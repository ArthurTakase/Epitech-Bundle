import AXIOS from "../Tools/Client.jsx"
import { Error } from '../Tools/Notif'

import { useNavigate } from 'react-router-dom';
import { useEffect } from 'react'

function LogoutUser() {
    const navigate = useNavigate()

    useEffect(() => {
        const token = "Bearer " + localStorage.getItem("token");
        const url = localStorage.getItem("url") + "/signout";
        const values = {
            headers: {
                Authorization: token,
            }
        }

        AXIOS.delete(url, values)
            .then(res => {
                localStorage.removeItem("token");
                navigate('/login')
            })
            .catch((error) => {
                Error({"res": error})
                localStorage.removeItem("token");
                navigate('/login')
            });
    // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [])
    return ( <></> )
}

export default LogoutUser;