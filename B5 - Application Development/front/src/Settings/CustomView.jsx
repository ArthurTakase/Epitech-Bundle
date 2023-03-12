export default function OpenBrowser(url) {
    var target = "_blank"
    var options = "fullscreen=no,location=yes,clearsessioncache=yes,clearcache=yes"
    var ref = window.open(url, target, options);

    ref.addEventListener("exit", exitCallback);

    function exitCallback() {
        ref.close();
        console.log("Browser is closed")
    }
}