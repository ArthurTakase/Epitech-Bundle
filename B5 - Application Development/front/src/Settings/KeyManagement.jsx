import { useState, useEffect } from "react"
import { useGoogleLogin } from "@react-oauth/google";

import SettingsNavBar from "./SettingsNavBar"
import Container from "../Tools/Container"
import AXIOS from "../Tools/Client"
import Load from "../Tools/Load"
import { Error, SetNotif } from "../Tools/Notif"

function APIPage() {
    var url = localStorage.getItem("platform") === "mobile" ? "file:///android_asset/www/index.html" : "http://" + window.location.href.split("/")[2]
    var token = "Bearer " + localStorage.getItem("token");
    var user_url = localStorage.getItem("url") + "/current_user";
    const [spotifyText, setSpotifyText] = useState("Login with Spotify");
    const [googleText, setGoogleText] = useState("Login with Google");

    useEffect(() => {
        AXIOS.get(user_url, { headers: { Authorization: token } })
            .then(function (res) {
                if (res.data.spotify_token) {
                    setSpotifyText("Logout from Spotify");
                }
                if (res.data.google_token) {
                    setGoogleText("Logout from Google");
                }
            })
    }, [spotifyText, token, user_url]);

    function logoutSpotify() {
        var logout_url = localStorage.getItem("url") + `/users/delete_token`;
        let service = {
            "token": {
                "service_name": "spotify"
            }
        }
        AXIOS.post(logout_url, service, { headers: { Authorization: token } })
            .then((res) => {
                setSpotifyText("Login with Spotify");
                SetNotif({ "title": "Infos", "body": "Logout from Spotify completed" })
            })
            .catch((err) => Error(err))
    }

    const googleLogin = useGoogleLogin({
        onSuccess: tokenResponse => {
            var url_target = localStorage.getItem("url") + `/users/refresh_token`;
            const token = "Bearer " + localStorage.getItem("token");
            var access_token = {
                "refresh_token": {
                    "name": "google",
                    "code": tokenResponse.code,
                    "redirect_uri": localStorage.getItem("platform") === "mobile" ? "file:///android_asset/www/index.html" : "http://" + window.location.href.split("/")[2]
                }
            }
            setGoogleText("Logout from Google");
            AXIOS.post(url_target, access_token, { headers: { Authorization: token } })
                .then(function (res) { SetNotif({ "title": "Infos", "body": "Connection with Google completed" }) })
                .catch((err) => Error(err))
        },
        flow: 'auth-code',
        scope: `https://www.googleapis.com/auth/gmail.modify`,
        onError: error => Error({ "res": error })
    })

    function googleLogout() {

        var logout_url = localStorage.getItem("url") + `/users/delete_token`;
        let service = {
            "token": {
                "service_name": "google"
            }
        }
        AXIOS.post(logout_url, service, { headers: { Authorization: token } })
            .then((res) => {
                setGoogleText("Login with Google")
                SetNotif({ "title": "Infos", "body": "Logout from Google completed" })
            })
            .catch((err) => Error(err))
    }

    async function checkUserGoogle() {
        await AXIOS.get(user_url, { headers: { Authorization: token } })
            .then(function (res) {
                res.data.google_token ? googleLogout() : googleLogin();
            })
            .catch((err) => { return (false); })
    }

    const Spotify = () => {
        const [element, setElement] = useState(<Load />);

        useEffect(() => {
            AXIOS.get(user_url, { headers: { Authorization: token } })
                .then(function (res) {
                    res.data.spotify_token ?
                        setElement(<button className="spotify spotify-button" onClick={logoutSpotify}>{spotifyText}</button>)
                        : setElement(<a className="spotify" href={`https://accounts.spotify.com/authorize?client_id=${process.env.REACT_APP_SPOTIFY_CLIENT_ID}&redirect_uri=${url}&response_type=code&scope=user-library-read,playlist-modify-public,playlist-modify-private,user-read-private,user-read-email`}>{spotifyText}</a>)
                })
                .catch((err) => { Error(err) })
            // eslint-disable-next-line
        }, [user_url, token, url, spotifyText]);

        return (
            <Container type="large" key="Spotify">
                {element}
            </Container>
        )

    }

    return (
        <>
            <SettingsNavBar currentPage="API" />
            <div className="content large">
                <Spotify />
                <Container type="large" key="Google">
                    <button className="google-button" onClick={() => { checkUserGoogle() }}>{googleText}</button>
                </Container>
            </div>
        </>
    );
}

export default APIPage;