import { modalActions } from './Modal'
import { LoginBtn, LoginValidation } from './Login'
import { IoPersonAdd } from "react-icons/io5"
import { RefObject } from 'react'
import React from 'react'
import axios from 'axios'
import { toast } from 'react-toastify'

export function GetErrorMsg(responseData: any) {
    if (responseData === undefined) return 'Erreur: Aucune réponse du serveur'
    if (responseData.errors) {
        let errorMsg = []
        for (const key in responseData.errors) {
            errorMsg.push(responseData.errors[key].join(', '))
        }
        return 'Erreur: ' + errorMsg.join(' // ')
    }
    return 'Erreur: ' + responseData.error
}

export function RegisterBtn() {
    modalActions.setOpen(false)
    modalActions.setTitle(<><IoPersonAdd /><span>S'inscrire</span></>)
    modalActions.setModalContent(<Register />)
    modalActions.setOpen(true)
}

export default function Register() {
    const errorRef: RefObject<HTMLDivElement> = React.createRef()
    const usernameRef: RefObject<HTMLInputElement> = React.createRef()
    const emailRef: RefObject<HTMLInputElement> = React.createRef()
    const passwordRef: RefObject<HTMLInputElement> = React.createRef()
    const passwordConfirmRef: RefObject<HTMLInputElement> = React.createRef()

    const Connect = () => {
        const username = usernameRef.current?.value
        const email = emailRef.current?.value
        const password = passwordRef.current?.value
        const passwordConfirm = passwordConfirmRef.current?.value

        if (!username || !password || !passwordConfirm || !email) return
        if (password !== passwordConfirm) {
            errorRef.current!.style.display = 'block'
            errorRef.current!.textContent = 'Erreur: Les mots de passe ne correspondent pas'
            return
        }

        const body = {
            "user": {
                "email": email,
                "password": password,
                "username": username
            }
        }

        axios.post('http://localhost:4000/auth/register', body)
        .then((res) => {
            if (res.status === 201) {
                axios.post('http://localhost:4000/auth/login', { "email": email, "password": password })
                .then(res => { LoginValidation(res) })
                .catch(err => {
                    console.error(err)
                    errorRef.current!.style.display = 'block'
                    errorRef.current!.textContent = 'Erreur: ' + err.response.data.error
                    toast.error('Erreur lors de la connexion : ' + err.response.data.error)
                })
            }
        })
        .catch(err => {
            console.error(err)
            const errorMsg = GetErrorMsg(err.response.data)
            errorRef.current!.style.display = 'block'
            errorRef.current!.textContent = errorMsg
            toast.error(errorMsg)
        })
    }
    
    return (
        <>
            <input type='text' placeholder="Nom d'utilisateur" ref={usernameRef} />
            <input type='text' placeholder='Email' ref={emailRef} />
            <input type='password' placeholder='Mot de passe' ref={passwordRef} />
            <input type='password' placeholder='Confirmer le mot de passe' ref={passwordConfirmRef} />
            <div className='error' id="errormsg" ref={errorRef}>Lorem ipsum dolor sit amet consectetur adipisicing elit.</div>
            <span className='space'></span>
            <button onClick={Connect}>Valider</button>
            <button onClick={LoginBtn} className='underlineBtn'>J'ai déjà un compte</button>
        </>
    )
}