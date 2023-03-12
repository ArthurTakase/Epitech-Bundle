import { useState } from "react"
import { AiOutlineCheck } from "react-icons/ai"

import AXIOS from "../Tools/Client.jsx"
import SettingsNavBar from "./SettingsNavBar"
import Container from "../Tools/Container"

function Appearance() {
    const token = "Bearer " + localStorage.getItem("token");
    const [picked, setPicked] = useState("Light");

    const handlePickChange = (picked) => {
        setPicked(picked);
    }

    const SelectTheme = () => {
        localStorage.setItem("theme", picked === "Light" ? "theme-light" : "theme-dark");
        document.documentElement.className = localStorage.getItem("theme");
    }

    AXIOS.get(localStorage.getItem("url") + "/current_user", { headers: { Authorization: token } })
        .then()
        .catch(err => { Error({ "res": err }) });

    return (
        <>
            <SettingsNavBar currentPage="Appearance" />
            <div className="content">
                <Container>
                    <div className="pageTitle">Change your Theme</div>
                    <div className="column row-2 border">
                        <div>Select</div>
                        <select name="selection" value={picked} onChange={event => handlePickChange(event.target.value)}>
                            <option>Light</option>
                            <option>Dark</option>
                        </select>
                    </div>
                    <button onClick={SelectTheme} className="btnBig cornerBtn"><AiOutlineCheck /></button>
                </Container>
            </div>
        </>
    );
}

export default Appearance