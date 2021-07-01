const express = require("express");
const jwt = require("jsonwebtoken");
require('dotenv').config();
var database = require("../../config/db");
var check = require("../../middleware/auth");
var bcrypt = require("bcrypt");

function my_query(sql) {
    return new Promise(resolve => {
        database.query(sql, (err, result) => {
            if (err) throw err;
            resolve(result[0].id);
        });
    });
}

module.exports = {
    user_info: function(req, res) {
        var value = check.verify_token(req, res);
        if (value == null) return;
        if (req.header('jwt') == '') {
            return res.send({mgs:"No Token, athorization denied"});
        }
        jwt.verify(req.header('jwt'), process.env.SECRET, (err, decoded) => {
            if (err) {
                return res.send({msg:"Token is not valid"});
            }
            var users = `SELECT * FROM user`;
            database.query(users, (err, result) => {
                if (err) throw err;
                return res.send(result);
            });
        });
    },
    user_todo: async function(req, res) {
        var value = check.verify_token(req, res);
        if (value == null) return;
        // if (value != null) {
        //     var get_id = `SELECT id FROM user WHERE email = "${value.email}"`
        //     var id = await my_query(get_id);
        // }
        var sql = `SELECT * FROM todo`;
        database.query(sql, (err, result) => {
            if (err) throw err;
            return res.send(result);
        });
    },
    info_user_id: function(req, res) {
        var value = check.verify_token(req, res);
        console.log(req.value);
        if (value == null || req.value) return res.send({msg:"no"});
        let sql = null;
        if (req.value.includes('@')) {
            sql = `SELECT * FROM user WHERE email="${req.value}"`;
        } else {
            sql = `SELECT * FROM user WHERE id="${req.value}"`; 
        }
        database.query(sql, (err, result) => {
            if (err) throw err;
            if (result.length === 0) return res.send({"msg": "Not found"});
            return res.send(result[0]);
        });
    },
    delete_user_from_id: async function(req, res, id) {
        var value = check.verify_token(req, res);
        if (value == null) return;
        var sql_check = `SELECT * FROM user WHERE id = ${id}`;
        var long = 0;
        let get_true_id = `SELECT id FROM user WHERE email="${value.email}"`
        database.query(sql_check, (err_check, result_check) => {
            if (err_check) return res.send({"msg": "internal server error"});
            long = result_check.length;
        });
        var sql_delete = `DELETE FROM user WHERE id = ${id}`;
        database.query(sql_delete, (err, result) => {
            if (long === 0) return res.send({"msg": "Not found"});
            if (err) return res.send({"msg": "internal server error"});
            return res.send({"msg": `succesfully deleted record number : ${id}`});
        });
    },
    put_user_from_id: function(req, res, id) {
        var sql_check = `SELECT * FROM user WHERE id = ${id}`;
        var long = 0;
        database.query(sql_check, (err_check, result_check) => {
            if (err_check) return res.send({"msg": "internal server error"});
            long = result_check.length;
        });
        var salt = bcrypt.genSaltSync(10);
        var hash = bcrypt.hashSync(req.body.password, salt);
        req.body.password = hash;
        var sql_update = `UPDATE user
            SET email = "${req.body.email}",
            password = "${req.body.password}",
            firstname = "${req.body.firstname}",
            name = "${req.body.name}"
            WHERE id = ${id}`;
        database.query(sql_update, (err, result) => {
            if (long === 0) return res.send({"msg": "Not found"});
            if (err) return res.send({"msg": "internal server error"});
            var sql_result = `SELECT * FROM user WHERE id = ${id}`;
            database.query(sql_result, (err_end, result_end) => {
                if (err_end) return res.send({"msg": "internal server error"});
                return res.send(result_end[0]);
            });
        });
    }
};