import '../css/navbar.css'
import '../css/colors.css'

import { Link } from "react-router-dom"

export function NavItem({icon, name, link, classes}) {
    return (
        <Link to={link} className={`navItem ${classes}`}>
            <div className="navIcon">{icon}</div>
            <div className="navText">{name}</div>
        </Link>
    )
}

export function NavButton({icon, name, fun, classes}) {
    return (
        <button onClick={fun} className={`navItem ${classes}`}>
            <div className="navIcon">{icon}</div>
            <div className="navText">{name}</div>
        </button>
    )
}