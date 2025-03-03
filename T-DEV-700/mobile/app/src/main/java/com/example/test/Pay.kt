package com.example.test

import android.annotation.SuppressLint
import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.Handler
import android.util.Log
import android.widget.ImageView
import android.widget.TextView
import android.widget.Toast

class Pay : AppCompatActivity() {
    private var json: JSONTools = JSONTools()
    private var cash: Cash = Cash("", "", null)
    private var payText: TextView? = null
    private var requests: Requests? = null
    private var payImage: ImageView? = null
    private var requestSend: Boolean = false

    @SuppressLint("SetTextI18n")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_pay)
        payText = findViewById(R.id.pay_text)
        payImage = findViewById(R.id.pay_image)

        cash = json.readCashJson(this)
        Log.d("Requests", cash.accountName + " " + cash.accountNumber + " " + cash.amount)
        requests = Requests(this)
        val postData = """{"amount": ${cash.amount}}""".trimIndent()

        if (requestSend)
            return

        requestSend = true
        val token = json.getUserToken(this)
        val headers: MutableMap<String, String> = mutableMapOf()
        headers["Authorization"] = "Bearer $token"

        API().post("${requests?.url}/purchase/${cash.accountNumber}",
            headers = headers,
            postData = postData,
            onSuccess = { response ->
                Log.d("Requests", response)

                json.emptyCartJson(this)
                json.emptyCashJson(this)

                payText?.text = "Paiement accepté"
                payImage?.setImageResource(R.drawable.check)

                Handler().postDelayed({
                    startActivity(Intent(this, MainActivity::class.java))
                    finish()
                }, 3000)
            },
            onError = { error ->
                Log.d("Requests", error.toString())

                payText?.text = "Paiement refusé"
                payImage?.setImageResource(R.drawable.error)

                Handler().postDelayed({
                    startActivity(Intent(this, MainActivity::class.java))
                    finish()
                }, 3000)
            }
        )
    }

    @Deprecated("Deprecated in Java")
    @SuppressLint("MissingSuperCall")
    override fun onBackPressed() {
        Toast.makeText(this, "Please wait", Toast.LENGTH_SHORT).show()
    }
}