package com.example.test

import android.annotation.SuppressLint
import android.os.Bundle
import android.os.Handler
import android.os.Looper
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import androidx.fragment.app.Fragment
import com.example.test.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding : ActivityMainBinding
    private val store: Store = Store()
    private val cart: Cart = Cart()
    private val settings: Settings = Settings()
    private var backPressedCount = 0

    @SuppressLint("SetTextI18n")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        replaceFragment(Store())

        binding.bottomNav.setOnItemSelectedListener {
            when (it.itemId) {
                R.id.store -> { replaceFragment(store); true }
                R.id.cart -> { replaceFragment(cart); true }
                R.id.settings -> { replaceFragment(settings); true }
                else -> false

            }
        }
    }

    private fun replaceFragment(fragment: Fragment) {
        val fragmentManager = supportFragmentManager
        val fragmentTransaction = fragmentManager.beginTransaction()
        fragmentTransaction.replace(R.id.frame_layout, fragment)
        fragmentTransaction.commit()
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
}