import { useState, useEffect } from "react"

import Container from '../Tools/Container'
import AXIOS from "../Tools/Client"
import Load from "../Tools/Load"
import { Error } from "../Tools/Notif"
import SettingsNavBar from "./SettingsNavBar"

import '../css/settings.css'

function DisplayUserInfos({ data }) {
    return (
        <Container>
            {
                data.picture === null ?
                    <div className="pageTitle">
                        {data.first_name + "'s Account"}
                    </div>
                    : <img className="userProfil" src={data.picture} alt="" />
            }
            <div className="column row-2 border margin">
                <div>First name</div>
                <input type="text" readOnly="readonly" placeholder={data.first_name} />
            </div>
            <div className="column row-2 border margin">
                <div>Last name</div>
                <input type="text" readOnly="readonly" placeholder={data.last_name} />
            </div>
            <div className="column row-2 border margin">
                <div>Email address</div>
                <input type="text" readOnly="readonly" placeholder={data.email} />
            </div>
        </Container>
    );
}

function UserProfil() {
    const [element, setElement] = useState(<Load />)

    useEffect(() => {
        const token = "Bearer " + localStorage.getItem("token");

        AXIOS.get(localStorage.getItem("url") + "/current_user", { headers: { Authorization: token } })
            .then(res => { setElement(<DisplayUserInfos data={res.data} />) })
            .catch(error => { Error({ "res": error }) });
    }, [])

    return (
        <>
            <SettingsNavBar currentPage="UserProfil" />
            <div className="content">
                {element}
            </div>
        </>
    );
}

export default UserProfil