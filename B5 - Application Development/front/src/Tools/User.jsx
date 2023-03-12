import "../css/settings.css"

import Container from "./Container";
import AXIOS from "./Client.jsx"
import { Error } from './Notif'

import { useState } from 'react'
import { AiOutlineCheck } from 'react-icons/ai'

function User({ u }) {

    const [content, setContent] = useState(
        <>
            <div className="containerTitle"><span id={`admin_${u.id}`}>{u.admin ? "👑 " : ""}</span>{u.first_name} {u.last_name}</div>
            <div className="containerContent">{u.email}</div>
            <div className="containerContent">Widgets<span className="tag">{u.widgets.length}</span></div>
        </>
    )

    function removeThis(id) {
        const token = "Bearer " + localStorage.getItem("token");
        var url = localStorage.getItem("url") + `/users/${id}`

        AXIOS.delete(url, { headers: { Authorization: token } })
            .then((res) => {
                try { document.getElementById(`user_${id}`).remove() } catch (e) {}
            })
            .catch((err) => Error(err))
    }

    function editThis(u) {
        var temp = document.getElementById(`user_${u.id}`)

        try {
            if (temp.classList.contains("editContainer")) {
                temp.classList.remove("editContainer")
                setContent(
                    <>
                        <div className="containerTitle"><span id={`admin_${u.id}`}>{u.admin ? "👑 " : ""}</span>{u.first_name} {u.last_name}</div>
                        <div className="containerContent">{u.email}</div>
                        <div className="containerContent">Widgets<span className="tag">{u.widgets.length}</span></div>
                    </>
                )
                try { temp.getElementsByClassName("funZone")[0].firstChild.innerHTML = "🖊️" } catch (e) {}
                return
            }
            try { temp.getElementsByClassName("funZone")[0].firstChild.innerHTML = "❌" } catch (e) {}
        } catch (e) {}
        
        temp.classList.add("editContainer")
        
        setContent(
            <>
                <div className="row-2 border">
                    <div>Edit User n°{u.id}</div>
                    <input type="text" id="first_name" className="requiered" title="First Name" placeholder="First Name" defaultValue={u.first_name}/>
                    <input type="text" id="last_name" className="requiered" title="Last Name" placeholder="Last Name" defaultValue={u.last_name}/>
                </div>
                <div className="row-2 border">
                    <div>Email</div>
                    <input type="email" id="email" className="requiered" title="Email" placeholder="Email" defaultValue={u.email}/>
                </div>
                <div className="row-2 border">
                    <div>New Password</div>
                    <input type="text" id="password" title="Password" placeholder="Leave empty to keep the current password"/>
                </div>
                <button onClick={(e) => {
                    const token = "Bearer " + localStorage.getItem("token");
                    var url = localStorage.getItem("url") + `/users/${u.id}`

                    u.first_name = document.getElementById("first_name").value
                    u.last_name = document.getElementById("last_name").value
                    u.email = document.getElementById("email").value
                    if (document.getElementById("password").value !== "") { u.password = document.getElementById("password").value }
            
                    AXIOS.patch(url, {"user": u}, { headers: { Authorization: token } })
                        .then((res) => { window.location.reload() })
                        .catch((err) => Error(err))
                }} className="btnBig cornerBtn"><AiOutlineCheck /></button>
            </>
        )
    }

    function adminThis(u) {
        var token = "Bearer " + localStorage.getItem("token");
        var url = localStorage.getItem("url") + `/users/${u.id}`

        u.admin = !u.admin

        AXIOS.patch(url, {"user": u}, { headers: { Authorization: token } })
            .then((res) => {
                try {
                    var temp = document.getElementById(`admin_${u.id}`)
                    if (u.admin) temp.innerHTML = "👑 "
                    else temp.innerHTML = ""
                } catch (e) {}
            })
            .catch((err) => Error(err))
    }

    return (
        <Container key={u.id} id={`user_${u.id}`} type={`widget ${u.admin ? "admin" : ""}`}>
            {content}
            <div className="funZone">
                <button className="button" title="Edit" onClick={() => { editThis(u) }}>🖊️</button>
                <button className="button" title="Set Admin/not Admin" onClick={() => { adminThis(u) }}>👑</button>
                <button className="button" title="Remove" onClick={() => { removeThis(u.id) }}>🗑️</button>
            </div>
        </Container>
    )
}

export default User;