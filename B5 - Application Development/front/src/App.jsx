import { HashRouter, Routes, Route, Link } from "react-router-dom"

import Register from "./Authentification/Register"
import Login from "./Authentification/Login"
import LogoutUser from "./Authentification/LogOut"
import Home from "./Pages/Home"
import Create from "./Pages/Create"
import UserProfil from "./Settings/UserProfil"
import Appearance from "./Settings/Appearance"
import Identification from "./Settings/Identification"
import APIPage from "./Settings/KeyManagement"
import Admin from "./Pages/Admin"
import { GoogleOAuthProvider } from '@react-oauth/google';
import AXIOS from "./Tools/Client"
import { Error, SetNotif } from './Tools/Notif.jsx'

function App() {

    if (window.location.href.includes("code")) {
        var code = window.location.href.split("code=")[1].split("&")[0];
        var url_target = localStorage.getItem("url") + `/users/refresh_token`;
        const token = "Bearer " + localStorage.getItem("token");

        AXIOS.get(localStorage.getItem("url") + "/current_user", { headers: { Authorization: token } })
            .then(function (res) {
                if (res.data.spotify_token === null || res.data.spotify_token === false) {
                    var access_token = {
                        "refresh_token": {
                            "name": "spotify",
                            "code": code,
                            "redirect_uri": localStorage.getItem("platform") === "mobile" ? "file:///android_asset/www/index.html" : "http://" + window.location.href.split("/")[2]
                        }
                    }

                    AXIOS.post(url_target, access_token, { headers: { Authorization: token } })
                        .then(function (res) { SetNotif({ "title": "Infos", "body": "Connection with Spotify completed" }) })
                }
            })
    }

    return (
        <GoogleOAuthProvider clientId={process.env.REACT_APP_GOOGLE_API_PUBLIC}>
            <HashRouter>
                <Link id="toHome" to="/Home" tabIndex="1">Return to Home</Link>
                <Routes>
                    <Route path="/" element={<Login />} />
                    <Route path="/login" element={<Login />} />
                    <Route path="/register" element={<Register />} />
                    <Route path="/home" element={<Home />} />
                    <Route path="/logout" element={<LogoutUser />} />
                    <Route path='/create' element={<Create />} />
                    <Route path='/profil' element={<UserProfil />} />
                    <Route path='/identification' element={<Identification />} />
                    <Route path='/appearance' element={<Appearance />} />
                    <Route path='/keys' element={<APIPage />} />
                    <Route path='/admin' element={<Admin />} />
                </Routes>
            </HashRouter>
        </GoogleOAuthProvider>
    );
}

export default App;
