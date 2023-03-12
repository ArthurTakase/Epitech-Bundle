
import React from "react"
import { NavItem, NavButton } from "../Tools/NavItem"
import SwitchTheme from "../Tools/SwitchTheme"
import OpenBrowser from "./CustomView"

import { AiOutlineArrowLeft, AiOutlineUser, AiFillFormatPainter, AiOutlineKey, AiFillIdcard } from "react-icons/ai"

import "../css/navbar.css"

function SettingsNavBar({ currentPage }) {
    SwitchTheme();
    return (
        <div className="navbar">

            <div className="navbarTop">
                <h1 className="navbarTitle">Settings</h1>
            </div>

            <div className="navbarMiddle">
                <NavItem icon={<AiOutlineUser />} name="Profil" classes={`${currentPage === "UserProfil" ? "active" : ""}`} link="/profil" />
                <NavItem icon={<AiFillIdcard />} name="Identification" classes={`${currentPage === "Identification" ? "active" : ""}`} link="/identification" />
                {
                    localStorage.getItem("platform") === "web" ? <NavItem icon={<AiOutlineKey />} name="Services" classes={`${currentPage === "API" ? "active" : ""}`} link="/keys" />
                        : <NavButton icon={<AiOutlineKey />} name="Services" classes={`${currentPage === "API" ? "active" : ""}`} fun={() => { OpenBrowser(localStorage.getItem("url").slice(0, -1) + "1") }} />
                }
                <NavItem icon={<AiFillFormatPainter />} name="Appearance" classes={`${currentPage === "Appearance" ? "active" : ""}`} link="/appearance" />
                <NavItem icon={<AiOutlineArrowLeft />} classes={`right ${currentPage === "Home" ? "active" : ""}`} link="/home" />

                <div className="line"></div>

            </div>

            <div className="navbarBottom">
                <NavItem icon={<AiOutlineArrowLeft />} classes={`${currentPage === "Home" ? "active" : ""}`} link="/home" />
            </div>
        </div>

    );
}

export default SettingsNavBar;