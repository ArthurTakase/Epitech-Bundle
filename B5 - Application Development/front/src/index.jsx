import React from "react"
import ReactDOM from "react-dom/client"
import App from "./App"
import { AuthProvider } from "./Authentification/AuthProvider";
import "./css/colors.css"
import "./css/index.css"

const startApp = () => {
    const root = ReactDOM.createRoot(document.getElementById("root"))
    root.render(
        <React.StrictMode>
            <AuthProvider>
                <App />
            </AuthProvider>
        </React.StrictMode>
    )
}

if (window.cordova) {
    localStorage.setItem("platform", "mobile")
    document.addEventListener("deviceready", startApp, false)
} else {
    var url = window.location.href
    if (window.location.href.includes("http://")) url = url.replace("http://", "")
    if (window.location.href.includes("https://")) url = url.replace("https://", "")
    if (window.location.href.includes("8081")) {
        var index = url.indexOf("8081")
        url = url.substring(0, index - 1)
    }
    if (window.location.href.includes("8082")) {
        var index2 = url.indexOf("8082")
        url = url.substring(0, index2 - 1)
    }
    localStorage.setItem("url", `http://${url}:8080`)
    localStorage.setItem("platform", "web")
    startApp()
}