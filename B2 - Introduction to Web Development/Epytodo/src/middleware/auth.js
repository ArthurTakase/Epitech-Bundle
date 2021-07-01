const express = require("express");
const jwt = require("jsonwebtoken");
require('dotenv').config();
var database = require("../config/db");

module.exports = {
    verify_token: function(req, res) {
        if (req.headers.jwt == null || req.header('jwt') == '') {
            res.send({mgs:"No Token, athorization denied"});
            return null;
        }
        try {
            var decoded = jwt.verify(req.header('jwt'), process.env.SECRET);
            return decoded;
        } catch (error){
            res.send({msg:"Invalid Token"});
            return null;
        }

    }
};