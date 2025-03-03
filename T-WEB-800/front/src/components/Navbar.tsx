import { useEffect, useState } from 'react'
import '../scss/navbar.scss'
import { IoLogInSharp } from "react-icons/io5"
import { IoLogOutSharp } from "react-icons/io5"
import { IoPrintSharp } from "react-icons/io5";
import { IoPersonAdd } from "react-icons/io5"
import { LoginBtn } from './Login'
import { RegisterBtn } from './Register'
import { journeyActions } from './CurrentJourney'
import { leftPanelActions } from './LeftPanel'

interface NavbarActions {
    setLeftZone: (content: boolean) => void;
}

export const navbarActions: NavbarActions = {
    setLeftZone: (_: boolean) => {},
}

function Print() {
    const printMap = () => {
        window.print();
    };

    return (
        <button title="Print" onClick={printMap}>
        <span className="btnIcon">
            <IoPrintSharp />
        </span>
        <span className="btnTitle">Imprimer</span>
        </button>
    );
}

export function NavbarLeftLogged() {
    const Disconnect = () => {
        const confirmLogout = window.confirm("Êtes-vous sûr de vouloir vous déconnecter ?");

        if (confirmLogout) {localStorage.removeItem('token')
            localStorage.removeItem('id')
            navbarActions.setLeftZone(false)
            journeyActions.setActionBar(false)
            leftPanelActions.ToggleMyJourneys(false)
        }
    }

    return (
        <div className="leftZone">
            <Print />
            <button title='Logout' onClick={Disconnect}>
                <span className='btnIcon'><IoLogOutSharp /></span>
                <span className='btnTitle'>Se deconnecter</span>
            </button>
        </div>
    )
}

export function NavbarLeftNotLogged() {
    return (
        <div className="leftZone">
            <Print />
            <button title='Login' onClick={LoginBtn}>
                <span className='btnIcon'><IoLogInSharp /></span>
                <span className='btnTitle'>Se connecter</span>
            </button>
            <button title='Sign Up' onClick={RegisterBtn}>
                <span className='btnIcon'><IoPersonAdd /></span>
                <span className='btnTitle'>Créer un compte</span>
            </button>
        </div>
    )
}

export default function Navbar() {
    const [leftZone, setLeftZone] = useState(false)
    navbarActions.setLeftZone = setLeftZone

    useEffect(() => {
        if (localStorage.getItem('token')) setLeftZone(true)
    }, [])

    return (
        <nav>
            <div className="title">
                <h1 className='bigTitle'>Epic Road Trip</h1>
                <h1 className='smallTitle'>ERT</h1>
            </div>
            {leftZone
                ? <NavbarLeftLogged />
                : <NavbarLeftNotLogged />
            }
        </nav>
    )
}