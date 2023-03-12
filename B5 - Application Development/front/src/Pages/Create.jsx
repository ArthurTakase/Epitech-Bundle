import "../css/colors.css"
import "../css/style.css"

import Navbar from "../Tools/Navbar"
import Load from "../Tools/Load"
import CreateForm from "./CreateForm"
import { Error } from "../Tools/Notif"
import SwitchTheme from "../Tools/SwitchTheme"

import { useState, useEffect } from "react"
import AXIOS from "../Tools/Client.jsx"

function Create() {
    SwitchTheme();
    const [element, setElement] = useState(<Load/>)

    useEffect(() => {
        AXIOS.get(localStorage.getItem("url") + "/about.json")
            .then(function (res) { setElement(<CreateForm json={res.data}/>) })
            .catch(function (err) { Error({"res": err}) });
    }, []);

    return (
        <>
            <Navbar currentPage="Create" />
            <div className="content">
                {element}
            </div>
        </>
    );
}

export default Create