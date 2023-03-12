import { useState, useEffect } from "react"
import { AiOutlineCheck } from "react-icons/ai";

import Container from '../Tools/Container'
import AXIOS from "../Tools/Client"
import Load from "../Tools/Load"
import { Error, SetNotif } from "../Tools/Notif"
import SettingsNavBar from "./SettingsNavBar"
import PasswordInput from "../Tools/Password";

function UserIdentification({ data, token }) {
    const [reset_token, setElement] = useState("")

    useEffect(() => {
        AXIOS.get(localStorage.getItem("url") + "/users/reset_token/", { headers: { Authorization: token } })
            .then(function (res) { setElement(res.data["token"]) })
            .catch(function (err) { Error({ "res": err }) })
    }, [token]);

    async function SetEmailValue(evt) {
        evt.preventDefault();
        let url = localStorage.getItem("url") + "/users/";

        const user = {
            "user": {
                "email": document.getElementById("new_email").value,
                "current_password": document.getElementById("current_password").value
            }
        };
        await AXIOS.patch(url, user, { headers: { Authorization: token } })
            .then(res => { SetNotif({ "title": "Success", "body": "Email address changed" }) })
            .catch(res => { Error({ "res": res }) })
    }

    async function SetPasswordValue(evt) {
        evt.preventDefault();

        const infos = {
            "user": {
                "current_password": document.getElementById("password").value,
                "password": document.getElementById("password_reset").value,
                "password_confirm": document.getElementById("confirm").value,
                "reset_password_token": reset_token
            }
        };

        await AXIOS.put(localStorage.getItem("url") + "/users/password.json", infos)
            .then(res => { SetNotif({ "title": "Success", "body": "Password changed" }) })
            .catch(error => { Error({ "res": error }) });
    }

    return (
        <Container>
            <div className="pageTitle">
                {data.first_name + "'s Login"}
            </div>

            <div className="column row-2 border padding-top">
                <div className="margin-top">Want to change Email ?</div>
                <input type="text" id="new_email" placeholder="Enter a new email address" />
                <PasswordInput id="current_password" placeholder="Your current password" />
            </div>
            <button onClick={SetEmailValue} className="btnBig margin"><AiOutlineCheck /></button>

            <div className="column row-2 border padding-top">
                <div className="margin-top"> Want to change Password ? </div>
                <PasswordInput id="password" placeholder="Your old Password"> </PasswordInput>
                <PasswordInput id="password_reset" placeholder="Enter new Password"></PasswordInput>
                <PasswordInput id="confirm" placeholder="Confirm new Password"></PasswordInput>
            </div>

            <button onClick={SetPasswordValue} className="btnBig"><AiOutlineCheck /></button>

        </Container>
    );
}

function Identification() {
    const [element, setElement] = useState(<Load />)

    useEffect(() => {
        const token = "Bearer " + localStorage.getItem("token");

        AXIOS.get(localStorage.getItem("url") + "/current_user", { headers: { Authorization: token } })
            .then(res => { setElement(<UserIdentification data={res.data} token={token} />) })
            .catch(error => { Error({ "res": error }) });
    }, []);

    return (
        <>
            <SettingsNavBar currentPage="Identification" />
            <div className="content">
                {element}
            </div>
        </>
    );
}

export default Identification;