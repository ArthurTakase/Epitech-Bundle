import "../css/navbar.css"
import "../css/colors.css"

import { NavItem } from "./NavItem"
import SwitchTheme from "./SwitchTheme"
import AXIOS from "../Tools/Client.jsx"

import { AiFillHome, AiOutlinePlus, AiFillSetting, AiOutlineLogout, AiOutlineCrown } from "react-icons/ai"
import { useState, useEffect } from "react"

function Navbar({ currentPage }) {
    SwitchTheme()

    const [element, setElement] = useState(<></>)
    const token = "Bearer " + localStorage.getItem("token");

    useEffect(() => {
        AXIOS.get(localStorage.getItem("url") + "/current_user", { headers: { Authorization: token } })
            .then(function (res) { if (res.data.admin) setElement(<NavItem icon={<AiOutlineCrown />} name="Admin" classes={`${currentPage === "Admin" ? "active" : ""}`} link="/admin" />) })
            .catch(function (err) { Error({"res": err}) });
    // eslint-disable-next-line react-hooks/exhaustive-deps
    }, []);

    return (
        <div className="navbar">
            <div className="navbarTop">
                <h1 className="navbarTitle">AREA</h1>
            </div>

            <div className="navbarMiddle">
                <NavItem icon={<AiFillHome />} name="Home" classes={`${currentPage === "Home" ? "active" : ""}`} link="/home" />
                <NavItem icon={<AiOutlinePlus />} name="Create" classes={`cornerBtn ${currentPage === "Create" ? "active" : ""}`} link="/create" />

                <div className="line"></div>

                {element}
                <NavItem icon={<AiFillSetting />} name="Settings" classes={`right ${currentPage === "Profil" ? "active" : ""}`} link="/profil" />
                <NavItem icon={<AiOutlineLogout />} classes={`right`} link="/logout" />
            </div>

            <div className="navbarBottom">
                <NavItem icon={<AiFillSetting />} classes={`${currentPage === "Profil" ? "active" : ""}`} link="/profil" />
                <NavItem icon={<AiOutlineLogout />} classes={`fixedRight`} link="/logout" />
            </div>
        </div>
    )
}

export default Navbar