function SwitchTheme() {
    localStorage.setItem("theme", localStorage.getItem("theme") === "theme-dark" ? "theme-light" : "theme-dark")

    document.documentElement.className = localStorage.getItem("theme")
}

export default SwitchTheme