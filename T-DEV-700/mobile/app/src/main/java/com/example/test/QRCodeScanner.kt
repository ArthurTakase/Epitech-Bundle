package com.example.test

import android.annotation.SuppressLint
import android.content.Intent
import android.content.pm.PackageManager
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.TextView
import android.widget.Toast
import androidx.core.app.ActivityCompat
import androidx.core.content.ContextCompat
import com.budiyev.android.codescanner.AutoFocusMode
import com.budiyev.android.codescanner.CodeScanner
import com.budiyev.android.codescanner.CodeScannerView
import com.budiyev.android.codescanner.DecodeCallback
import com.budiyev.android.codescanner.ErrorCallback
import com.budiyev.android.codescanner.ScanMode
import org.json.JSONObject

private const val CAMERA_REQUEST_CODE = 101

class QRCodeScanner : AppCompatActivity() {

    private lateinit var codeScanner: CodeScanner
    private var json: JSONTools = JSONTools()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_qrcode_scanner)

        setupPermissions()
        codeScanner()
    }

    override fun onResume() {
        super.onResume()
        codeScanner.startPreview()
    }

    override fun onPause() {
        codeScanner.releaseResources()
        super.onPause()
    }

    private fun extractCash(jsonString: String): Cash {
        return try {
            val json = JSONObject(jsonString)
            val accountNumber = json.getString("account_number")
            val accountName = json.getString("account_name")
            val amount = json.getString("amount").toDouble()

            Cash(accountNumber, accountName, amount)
        } catch (e: Exception) {
            e.printStackTrace()
            Cash("", "", null)
        }
    }

    @SuppressLint("SetTextI18n")
    private fun codeScanner() {
        val scannerView = findViewById<CodeScannerView>(R.id.scanner_view)
        codeScanner = CodeScanner(this, scannerView)
        codeScanner.camera = CodeScanner.CAMERA_BACK
        codeScanner.formats = CodeScanner.ALL_FORMATS
        codeScanner.autoFocusMode = AutoFocusMode.SAFE
        codeScanner.scanMode = ScanMode.CONTINUOUS
        codeScanner.isAutoFocusEnabled = true
        codeScanner.isFlashEnabled = false

        codeScanner.decodeCallback = DecodeCallback {
            runOnUiThread {
                val cash = extractCash(it.text)
                val totalCart = json.readCartJson(this)
                val total = totalCart.sumOf { product -> product.getTotalPrice() }

                if (cash.amount == null || cash.amount!! < total / 100.0f) {
                    Toast.makeText(this, "The check amount is insufficient", Toast.LENGTH_LONG).show()
                    startActivity(Intent(this, MainActivity::class.java))
                    finish()
                    return@runOnUiThread
                }

                if (cash.amount!! < total) cash.amount = (total / 100.0f).toDouble()

                json.addCashJson(this, cash)
                startActivity(Intent(this, Pay::class.java))
                finish()
            }
        }

        codeScanner.errorCallback = ErrorCallback {
            runOnUiThread {
                val text = findViewById<TextView>(R.id.scan_text)
                text.text = it.message
            }
        }
    }

    private fun setupPermissions() {
        val permission = ContextCompat.checkSelfPermission(this,
            android.Manifest.permission.CAMERA)

        if (permission != PackageManager.PERMISSION_GRANTED) {
            Log.i("Main", "Permission to record denied")
            makeRequest()
        }
    }

    private fun makeRequest() {
        ActivityCompat.requestPermissions(this,
            arrayOf(android.Manifest.permission.CAMERA),
            CAMERA_REQUEST_CODE)
    }

    override fun onRequestPermissionsResult(requestCode: Int, permissions: Array<String>, grantResults: IntArray) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults)
        when (requestCode) {
            CAMERA_REQUEST_CODE -> {
                if (grantResults.isEmpty() || grantResults[0] != PackageManager.PERMISSION_GRANTED) {
                    Log.i("Main", "Permission has been denied by user")
                } else {
                    Log.i("Main", "Permission has been granted by user")
                }
            }
        }
    }

    @SuppressLint("MissingSuperCall")
    @Deprecated("Deprecated in Java")
    override fun onBackPressed() {
        startActivity(Intent(this, MainActivity::class.java))
        finish()
    }
}