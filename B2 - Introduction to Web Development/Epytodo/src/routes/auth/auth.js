const express = require("express");
require("mysql");
var bodyParser = require('body-parser')
var database = require("../../config/db");
var jwt = require("jsonwebtoken");
var bcrypt = require("bcrypt");

module.exports = {
    register: function(req, res) {
        var salt = bcrypt.genSaltSync(10);
        var hash = bcrypt.hashSync(req.body.password, salt);
        req.body.password = hash;
        var sql = `INSERT INTO user
            (
                email,
                password,
                name,
                firstname
            )
            VALUES
            (
                "${req.body.email}",
                "${req.body.password}",
                "${req.body.name}",
                "${req.body.firstname}"
            )`;
        database.query(sql, (err, result) => {
            if (err) {
                if (err.errno == 1062) {
                    res.send({msg:"account already exists"});
                }
                else res.send({"msg": "internal server error"});
            }
            else {
                var header = {
                    "algorithm": "HS256"
                };
                var payload = {
                    "email": req.body.email,
                    "password": req.body.password,
                };
                var token = jwt.sign(payload, process.env.SECRET, header);
                var log = {
                    "token": token //t bg <3
                };
                return res.send(log);
            }
        });
    },
    // ! CECI EST UNE FONCTION ATTENTION, VOILA, J'AI TOUT DIT, MERCI, DES BISOUS
    login: function(req, res) {
        var credential = `SELECT email, password FROM user WHERE email="${req.body.email}"`
            database.query(credential, (err, result) => {
                if (err) throw err;
                if (result[0] == null) return res.send({msg:"Invalid  Credentials"});
                bcrypt.compare(req.body.password, result[0].password, (err, result) => {
                    if (err) throw err;
                    if (result) {
                        var header = {
                            "algorithm": "HS256"
                        };
                        var payload = {
                            "email": req.body.email,
                            "password": req.body.password,
                        };
                        var token = jwt.sign(payload, process.env.SECRET, header);
                        var log = {
                            "token": token
                        };
                        return res.send(log);
                    } else {
                        return res.send({msg:"Invalid Credentials"});
                    }
                });
            });
    }
};