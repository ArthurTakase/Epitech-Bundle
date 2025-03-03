package com.example.test

import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext
import java.net.HttpURLConnection
import java.net.URL

class API {

    private val coroutineScope = CoroutineScope(Dispatchers.IO)

    fun get(
        urlString: String,
        method: String = "GET",
        headers: Map<String, String> = emptyMap(),
        onSuccess: (String) -> Unit,
        onError: (Exception) -> Unit = {}
    ) {
        coroutineScope.launch {
            try {
                val url = URL(urlString)
                (withContext(Dispatchers.IO) {
                    url.openConnection()
                } as? HttpURLConnection)?.run {
                    requestMethod = method
                    headers.forEach { (key, value) -> setRequestProperty(key, value) }

                    inputStream.bufferedReader().use {
                        val response = it.readText()
                        withContext(Dispatchers.Main) {
                            onSuccess(response)
                        }
                    }
                }
            } catch (e: Exception) {
                withContext(Dispatchers.Main) {
                    onError(e)
                }
            }
        }
    }

    fun post(
        urlString: String,
        postData: String,
        headers: Map<String, String> = emptyMap(),
        onSuccess: (String) -> Unit,
        onError: (Exception) -> Unit = {}
    ) {
        coroutineScope.launch {
            try {
                val url = URL(urlString)
                (withContext(Dispatchers.IO) {
                    url.openConnection()
                } as? HttpURLConnection)?.run {
                    requestMethod = "POST"
                    doOutput = true
                    headers.forEach { (key, value) -> setRequestProperty(key, value) }

                    outputStream.bufferedWriter().use { writer ->
                        writer.write(postData)
                        writer.flush()
                    }

                    inputStream.bufferedReader().use {
                        val response = it.readText()
                        withContext(Dispatchers.Main) {
                            onSuccess(response)
                        }
                    }
                }
            } catch (e: Exception) {
                withContext(Dispatchers.Main) {
                    onError(e)
                }
            }
        }
    }
}