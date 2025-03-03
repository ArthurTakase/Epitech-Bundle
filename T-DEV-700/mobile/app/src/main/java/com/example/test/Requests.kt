package com.example.test

import android.content.Context

class Requests(context: Context) {
    private val json = JSONTools()
    private var infos: User? = null
    var url: String = ""

    init {
        infos = json.readUserJson(context)
        url = infos!!.server

        if (!url.startsWith("http://"))
            url = "http://$url"
        else if (url.startsWith("https://"))
            url = url.replace("https://", "http://")
    }
}