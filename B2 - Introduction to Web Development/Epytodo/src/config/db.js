var mysql = require('mysql');
require('dotenv').config();

class Database {
    // Initialisation de l'objet avec une nouvelle Pool
    // Utilisation de Pool au lieu de Connection pour 2 raisons:
    //      1 - Ca utilise toutes les var du .env
    //      2 - Ca permet d'éviter de faire une nouvelle connection quand il y en a déjà une
    constructor(config) {
        this.connection = mysql.createPool({
            host: process.env.MYSQL_HOST,
            user: process.env.MYSQL_USER,
            password: process.env.MYSQL_ROOT_PASSWORD,
            database: process.env.MYSQL_DATABASE,
            connectionLimit: 10
        });
    }
    // Requete asynchrone
    // Promise fait les traitements de façon asynchrone, ce qui permet de faire plusieurs demandes en même temps (c'est mieux pour une base de données)
    // Elle représente une valeur qui peut être dispo maintenant, plus tard ou jamais.
    // resolve -> Promise avec une valeur
    // reject -> Promise sans valeur
    query(sql, args) {
        return new Promise((resolve, reject) => {
            this.connection.query(sql, args, (err, rows) => {
                if (err) return reject(err);
                resolve(rows);
            });
        });
    }
    // Ferme la connection
    // Toujours en Async, donc voir les commentaires au dessus pour plus d'infos
    close() {
        return new Promise((resolve, reject) => {
            this.connection.end(err => {
                if (err) return reject(err);
                resolve();
            })
        });
    }
}

module.exports = new Database();