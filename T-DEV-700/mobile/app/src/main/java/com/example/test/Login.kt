package com.example.test

import android.content.Intent
import android.os.Bundle
import android.util.Log
import android.widget.Button
import android.widget.EditText
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import android.os.Handler
import android.os.Looper
import android.os.VibrationEffect
import android.os.Vibrator

class Login : AppCompatActivity() {

    private lateinit var jsonTools: JSONTools
    private var backPressedCount = 0
    private var serverEditText: EditText? = null
    private var emailEditText: EditText? = null
    private var passwordEditText: EditText? = null
    private var connectButton: Button? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_login)

        jsonTools = JSONTools()

        serverEditText = findViewById(R.id.edit_server_address)
        emailEditText = findViewById(R.id.edit_email_address)
        passwordEditText = findViewById(R.id.edit_password_address)
        connectButton = findViewById(R.id.button_connect)

        val user = jsonTools.readUserJson(this)
        serverEditText?.setText(user.server)
        emailEditText?.setText(user.email)

        connectButton?.setOnClickListener {
            login()
        }
    }

    @Deprecated("Deprecated in Java")
    override fun onBackPressed() {
        if (backPressedCount == 1) {
            super.onBackPressed()
            return
        }

        backPressedCount++
        Toast.makeText(this, "Press back again to exit", Toast.LENGTH_SHORT).show()

        Handler(Looper.getMainLooper()).postDelayed({
            backPressedCount = 0
        }, 2000)
    }

    private fun vibrate() {
        val vibrator = this.getSystemService(VIBRATOR_SERVICE) as Vibrator
        vibrator.vibrate(VibrationEffect.createOneShot(100, 30))
    }

    private fun login()
    {
        var server = serverEditText?.text.toString()
        val email = emailEditText?.text.toString()
        val password = passwordEditText?.text.toString()

        if (!server.startsWith("http://"))
            server = "http://$server"
        else if (server.startsWith("https://"))
            server = server.replace("https://", "http://")

        val postData = """{"email": "$email", "password": "$password"}""".trimIndent()

        API().post("${server}/users/connect", postData,
            onSuccess = { response ->
                Log.d("Requests", response)
                jsonTools.addUser(this, User(email, server, password, response))
                vibrate()
                startActivity(Intent(this, MainActivity::class.java))
                finish()
            },
            onError = { error ->
                Log.d("Requests", error.toString())
                Toast.makeText(this, "Can't connect to database.", Toast.LENGTH_SHORT).show()
            }
        )
    }
}

