import { useState } from "react";
import { AiFillEyeInvisible, AiFillEye } from "react-icons/ai";
import SwitchTheme from "./SwitchTheme";

import "../css/password.css"

function PasswordInput({ className, id, placeholder, buttonClass }) {
    SwitchTheme();
    const [visible, setVisibility] = useState(false);
    const [icon, setIcon] = useState(<AiFillEyeInvisible />);

    const togglePassword = () => {
        setVisibility(!visible);
        setIcon(visible ? <AiFillEyeInvisible /> : <AiFillEye />);
    };

    return (
        <div className="custom-input">
            <input className={className} type={visible ? "text" : "password"} id={id} placeholder={placeholder} />
            <button className={buttonClass + "custom-input-button custom-button custom-icon"} onClick={togglePassword}>{icon}</button>
        </div>
    );
}

export default PasswordInput