import { RefObject } from 'react'
import { modalActions } from './Modal'
import { RegisterBtn } from './Register'
import { IoLogInSharp } from "react-icons/io5"
import React from 'react'
import axios from 'axios'
import { toast } from 'react-toastify'
import { navbarActions } from './Navbar'
import { journeyActions } from './CurrentJourney'
import { leftPanelActions } from './LeftPanel'

export function LoginBtn() {
    modalActions.setOpen(false)
    modalActions.setTitle(<><IoLogInSharp /><span>Se connecter</span></>)
    modalActions.setModalContent(<Login />)
    modalActions.setOpen(true)
}

export function LoginValidation(response: any) {
    if (response.status === 200) {
        toast.success('Vous êtes connecté')
        modalActions.setOpen(false)

        const token = response.data.data.token
        localStorage.setItem('token', token)
        localStorage.setItem('id', response.data.data.user_id)

        navbarActions.setLeftZone(true)
        journeyActions.setActionBar(true)
        leftPanelActions.ToggleMyJourneys(true)
    }
}

export default function Login() {
    const errorRef: RefObject<HTMLDivElement> = React.createRef()
    const emailRef: RefObject<HTMLInputElement> = React.createRef()
    const passwordRef: RefObject<HTMLInputElement> = React.createRef()

    const Connect = () => {
        const email = emailRef.current?.value
        const password = passwordRef.current?.value

        if (!email || !password) return

        const body = {
            "email": email,
            "password": password
        }

        axios.post('http://localhost:4000/auth/login', body)
        .then(res => { LoginValidation(res) })
        .catch(err => {
            console.error(err)
            errorRef.current!.style.display = 'block'
            errorRef.current!.textContent = 'Erreur: ' + err.response.data.error
            toast.error('Erreur lors de la connexion : ' + err.response.data.error)
            passwordRef.current!.value = ''
        })
    }
    
    return (
        <>
            <input type='text' placeholder='Email' ref={emailRef} />
            <input type='password' placeholder='Mot de passe' ref={passwordRef} />
            <div className='error' id="errormsg" ref={errorRef}>Lorem ipsum dolor sit amet consectetur adipisicing elit.</div>
            <span className='space'></span>
            <button onClick={Connect}>Valider</button>
            <button onClick={RegisterBtn} className='underlineBtn'>Je n'ai pas encore de compte</button>
        </>
    )
}