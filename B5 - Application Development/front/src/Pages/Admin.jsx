import "../css/colors.css"
import "../css/style.css"

import Navbar from "../Tools/Navbar"
import AXIOS from "../Tools/Client.jsx"
import { Error } from '../Tools/Notif'
import Load from '../Tools/Load'
import User from "../Tools/User.jsx"
import GenerateKey from '../Tools/Key'

import { useNavigate } from "react-router-dom";
import { useState, useEffect } from "react"

export default function Admin() {
    const navigate = useNavigate()
    const [element, setElement] = useState(<Load />)
    const token = "Bearer " + localStorage.getItem("token");

    useEffect(() => {
        AXIOS.get(localStorage.getItem("url") + "/current_user", { headers: { Authorization: token } })
            .then(function (res) { if (!res.data.admin) navigate("/home") })
            .catch(function (err) { Error({"res": err}) })
        
        AXIOS.get(localStorage.getItem("url") + "/users", { headers: { Authorization: token } })
            .then(function (res) {
                var users = res.data.map((u) => { return ( <User key={GenerateKey()} u={u} /> ) })
                setElement( <>{users}</> )
            })
            .catch(function (err) { Error({"res": err}) });

    }, [navigate, token]);

    return (
        <>
            <Navbar currentPage="Admin" />
            <div className="content">{element}</div>
        </>
    )
}