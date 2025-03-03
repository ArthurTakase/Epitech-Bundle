package com.example.test

import android.content.Intent
import android.nfc.NfcAdapter
import android.nfc.Tag
import android.nfc.tech.MifareClassic
import android.os.Parcelable
import android.util.Log

class NFCTools {
    fun byteArrayToHexString(inArray: ByteArray?): String {
        if (inArray == null) return ""
        return inArray.joinToString("") { "%02X".format(it) }
    }

    fun extractDataMemory(intent: Intent): Cash {
        val tag = intent.getParcelableExtra<Parcelable>(NfcAdapter.EXTRA_TAG) as Tag
        val mifareTag = MifareClassic.get(tag)
        if (mifareTag == null) {
            Log.d("NFCDump", "Tag is not MIFARE Classic")
            return Cash("", "", null)
        }
        mifareTag.connect()
        val sb = StringBuilder()

        for (i in 0 until mifareTag.sectorCount) {
            if (mifareTag.authenticateSectorWithKeyA(i, MifareClassic.KEY_DEFAULT)) {
                val bCount = mifareTag.getBlockCountInSector(i)
                val bIndex = mifareTag.sectorToBlock(i)
                var sectorHasData = false

                for (j in 0 until bCount) {
                    val block = mifareTag.readBlock(bIndex + j)
                    if (block.any { it != 0.toByte() }) {
                        if (!sectorHasData) sectorHasData = true
                        val utf8Data = String(block, Charsets.UTF_8)
                        sb.append(utf8Data)
                    }
                }
                if (sectorHasData) sb.append('\n')
            } else sb.append("Authentication failed for Sector $i\n")
        }

        mifareTag.close()

        // Clean up invalid characters and trim the result
        val cleanedResult = sb.toString().replace("[^\\x20-\\x7E]+".toRegex(), "").trim()

        // Extract valid JSON data
        val startIndex = cleanedResult.indexOf('{')
        val endIndex = cleanedResult.lastIndexOf('}')
        val json = cleanedResult.substring(startIndex, endIndex + 1)
        var accountNumber = json.substringAfter("account_number\":\"").substringBefore("\"")
        accountNumber = accountNumber.replace("[^\\d]".toRegex(), "")
        val accountName = json.substringAfter("account_name\":\"").substringBefore("\"")

        Log.d("NFCDump", "account_number: $accountNumber, account_name: $accountName")
        return Cash(accountNumber, accountName, null)
    }
}