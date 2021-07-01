const express = require("express");
const jwt = require("jsonwebtoken");
require('dotenv').config();
var database = require("../../config/db");
var check = require("../../middleware/auth");

function get_user_id(sql) {
    return new Promise(resolve => {
        database.query(sql, (err, result) => {
            if (err) throw err;
            resolve(result[0].id);
        });
    });
}

module.exports = {
    // GET /todo
    get_todo: function(req, res) {
        var value = check.verify_token(req, res);
        if (value == null) return;
        var users = "SELECT * FROM todo";
        database.query(users, (err, result) => {
            if (err) throw err;
            return res.send(result);
        });
    },
    // POST /todo
    post_todo: async function(req, res) {
        var value = check.verify_token(req, res);
        if (value != null) {
            var get_id = `SELECT id FROM user WHERE email = "${value.email}"`
            var id = await get_user_id(get_id);
        }
        var sql = `INSERT INTO todo
            (
                title,
                description,
                due_time,
                user_id,
                status
            )
            VALUES
            (
                "${req.body.title}",
                "${req.body.description}",
                "${req.body.due_time}",
                "${id}",
                "${req.body.status}"
            )`;
        if (value != null) {
            database.query(sql, (err, result) => {
                if (err) return res.send({"msg": "internal server error"});
                else {
                    var last_todo = `SELECT * FROM todo ORDER BY id DESC LIMIT 1`;
                    database.query(last_todo, (err1, result1) => {
                        if (err1) return res.send({"msg": "internal server error"});
                        res.send(result1[0]);
                    })
                }
            });
        }
    },
    // GET /todo/:id
    get_todo_from_id: function(req, res, id) {
        var value = check.verify_token(req, res);
        if (value == null) return;
        var sql = `SELECT * FROM todo WHERE id = ${id}`;
        database.query(sql, (err, result) => {
            if (err) return res.send({"msg": "internal server error"});
            if (result.length === 0) return res.send({"msg": "Not found"});
            return res.send(result[0]);
        });
    },
    // PUT /todo/:id
    put_todo_from_id: function(req, res, id) {
        var value = check.verify_token(req, res);
        if (value == null) return;
        var sql_check = `SELECT * FROM todo WHERE id = ${id}`;
        var long = 0;
        database.query(sql_check, (err_check, result_check) => {
            if (err_check) return res.send({"msg": "internal server error"});
            long = result_check.length;
        });
        var sql_update = `UPDATE todo
            SET title = "${req.body.title}",
            description = "${req.body.description}",
            due_time = "${req.body.due_time}",
            user_id = "${req.body.user_id}",
            status = "${req.body.status}"
            WHERE id = ${id}`;
        database.query(sql_update, (err, result) => {
            if (long === 0) return res.send({"msg": "Not found"});
            if (err) return res.send({"msg": "internal server error"});
            var sql_result = `SELECT * FROM todo WHERE id = ${id}`;
            database.query(sql_result, (err_end, result_end) => {
                if (err_end) return res.send({"msg": "internal server error"});
                return res.send(result_end[0]);
            });
        });
    },
    // DELET /todo/:id
    delete_todo_from_id: function(req, res, id) {
        var value = check.verify_token(req, res);
        if (value == null) return;
        var sql_check = `SELECT * FROM todo WHERE id = ${id}`;
        var long = 0;
        database.query(sql_check, (err_check, result_check) => {
            if (err_check) return res.send({"msg": "internal server error"});
            long = result_check.length;
        });
        var sql_delete = `DELETE FROM todo WHERE id = ${id}`;
        database.query(sql_delete, (err, result) => {
            if (long === 0) return res.send({"msg": "Not found"});
            if (err) return res.send({"msg": "internal server error"});
            return res.send({"msg": `succesfully deleted record number : ${id}`});
        });
    }
};