package com.example.test

import android.annotation.SuppressLint
import android.app.PendingIntent
import android.content.Intent
import android.content.IntentFilter
import android.nfc.NfcAdapter
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.TextView
import android.widget.Toast

class NFC : AppCompatActivity() {

    private var jsonTextFront: TextView? = null
    private var nfcAdapter: NfcAdapter? = null
    private var pendingIntent: PendingIntent? = null
    private var writingTagFilters: Array<IntentFilter>? = null
    private var writeMode: Boolean = false
    private var nfcTools: NFCTools = NFCTools()
    private var json: JSONTools = JSONTools()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_nfc)

        jsonTextFront = findViewById(R.id.nfc_content)

        nfcAdapter = NfcAdapter.getDefaultAdapter(this)
        if (nfcAdapter == null) {
            Toast.makeText(this, "This device does not support NFC", Toast.LENGTH_LONG).show()
            finish()
            return
        }
        //readFromIntent(intent)
        pendingIntent = PendingIntent.getActivity(
            this,
            0,
            Intent(this, javaClass).addFlags(Intent.FLAG_ACTIVITY_SINGLE_TOP),
            PendingIntent.FLAG_MUTABLE)
        val tagDetected = IntentFilter(NfcAdapter.ACTION_TAG_DISCOVERED)
        tagDetected.addCategory(Intent.CATEGORY_DEFAULT)
        writingTagFilters = arrayOf(tagDetected)
    }

    @SuppressLint("SetTextI18n")
    private fun readFromIntent(intent: Intent) {
        val action: String? = intent.action
        Log.d("NFC", "readFromIntent: $action")
        if (NfcAdapter.ACTION_TAG_DISCOVERED == action
            || NfcAdapter.ACTION_TECH_DISCOVERED == action
            || NfcAdapter.ACTION_NDEF_DISCOVERED == action) {

            // get memory information from the intent
            intent.getByteArrayExtra(NfcAdapter.EXTRA_ID).toString()

            val byteArrayExtra = intent.getByteArrayExtra(NfcAdapter.EXTRA_ID)
            jsonTextFront!!.text = "NFC Tag: " + nfcTools.byteArrayToHexString(byteArrayExtra)

            try {
                val data: Cash = nfcTools.extractDataMemory(intent)
                val cart = json.readCartJson(this)
                val total = cart.sumOf { product -> product.getTotalPrice() }
                data.amount = (total / 100.0f).toDouble()
                json.addCashJson(this, data)
                startActivity(Intent(this, Pay::class.java))
                finish()
            } catch (e: Exception) {
                Toast.makeText(this, "Cannot read NFC tag", Toast.LENGTH_LONG).show()
            }
        }
    }

    override fun onNewIntent(intent: Intent) {
        super.onNewIntent(intent)
        setIntent(intent)
        readFromIntent(intent)
    }

    override fun onPause() {
        super.onPause()
        writeModeOff()
    }

    override fun onResume() {
        super.onResume()
        writeModeOn()
    }

    private fun writeModeOn() {
        writeMode = true
        nfcAdapter?.enableForegroundDispatch(this, pendingIntent, writingTagFilters, null)
    }

    private fun writeModeOff() {
        writeMode = false
        nfcAdapter?.disableForegroundDispatch(this)
    }

    @SuppressLint("MissingSuperCall")
    @Deprecated("Deprecated in Java")
    override fun onBackPressed() {
        startActivity(Intent(this, MainActivity::class.java))
        finish()
    }
}