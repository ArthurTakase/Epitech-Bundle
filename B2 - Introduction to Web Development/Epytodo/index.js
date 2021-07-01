const express = require("express");
const mysql = require('mysql');
var bodyParser = require("body-parser");
require("dotenv").config();
const port = 3000;
const auth = require("./src/routes/auth/auth");
const user = require("./src/routes/user/user");
const todo = require('./src/routes/todos/todo');
const app = express();

var jsonParser = bodyParser.json();
var urlencodedParser = bodyParser.urlencoded({ extended: false });

// ****************************************************************************
// *                      Récupération d'un parametre                         *
// ****************************************************************************

app.param('id', (req, res, next, id) => {
    req.id = id;
    next();
});

app.param('value', (req, res, next, value) => {
    req.value = value;
    next();
});

// ****************************************************************************
// *                                  Routes                                  *
// ****************************************************************************

app.post('/register', jsonParser, (req, res) => {
    return auth.register(req, res);
});

app.post('/login', jsonParser, (req, res) => {
    return auth.login(req, res);
});


app.get('/user', jsonParser, (req, res) => {
    return user.user_info(req, res);
});

app.get('/user/todos', jsonParser, (req, res) => {
    return user.user_todo(req, res);
});

app.get('/user/:value', jsonParser, (req, res) => {
    return user.info_user_id(req, res);
});

app.put('/user/:id', jsonParser, (req, res) => {
    return user.put_user_from_id(req, res, req.id);
});

app.delete('/user/:id', jsonParser, (req, res) => {
    return user.delete_user_from_id(req, res, req.id);
});

app.get('/todo', jsonParser, (req, res) => {
    return todo.get_todo(req, res);
});

app.get('/todo/:id', jsonParser, (req, res) => {
    return todo.get_todo_from_id(req, res, req.id);
});

app.post('/todo/', jsonParser, (req, res) => {
    return todo.post_todo(req, res);
});

app.put('/todo/:id', jsonParser, (req, res) => {
    return todo.put_todo_from_id(req, res, req.id);
});

app.delete('/todo/:id', jsonParser, (req, res) => {
    return todo.delete_todo_from_id(req, res, req.id);
});

// ****************************************************************************

app.listen(port, () => {
    console.log("Example app listening at http://localhost:"+ port);
});