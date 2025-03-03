package com.example.test

import android.annotation.SuppressLint
import android.content.Context
import android.content.Intent
import android.os.Bundle
import android.os.VibrationEffect
import android.os.Vibrator
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import android.widget.ImageView
import android.widget.LinearLayout
import android.widget.TextView
import androidx.fragment.app.Fragment


class Cart : Fragment() {
    private val json = JSONTools()

    @SuppressLint("DiscouragedApi", "SetTextI18n")
    private fun createProductCard(product: CartProduct) {
        val layout = view?.findViewById<LinearLayout>(R.id.cart_layout)
        val inflater = LayoutInflater.from(context)

        // if the product is already in the cart, we just increment the quantity
        if (layout?.findViewWithTag<View>(product.product.name) != null) {
            val view = layout.findViewWithTag<View>(product.product.name)
            val quantity = view.findViewById<TextView>(R.id.product_nb)
            val total = view.findViewById<TextView>(R.id.product_total)
            quantity.text = "x${product.quantity}"
            total.text = "$${product.getTotalPrice() / 100.0f}"
            return
        }

        val view = inflater.inflate(R.layout.product_card_cart, layout, false)
        view.tag = product.product.name

        view.findViewById<TextView>(R.id.product_name).text = product.product.name
        view.findViewById<TextView>(R.id.product_price).text = "$${product.product.price / 100.0f}"
        view.findViewById<TextView>(R.id.product_nb).text = "x${product.quantity}"
        view.findViewById<TextView>(R.id.product_description).text = product.product.description
        val imageResId = resources.getIdentifier(product.product.image, "drawable", requireActivity().packageName)
        view.findViewById<ImageView>(R.id.product_image).setImageResource(imageResId)

        view.findViewById<TextView>(R.id.product_total).text = "$${product.getTotalPrice() / 100.0f}"

        view.findViewById<Button>(R.id.delete_button).setOnClickListener {
            json.removeProductFromCart(requireContext(), product.product)
            layout?.removeView(view)
            vibrate()
            onResume()
        }

        layout?.addView(view)
    }

    private  fun totalCartPrice(): Int {
        val cart = json.readCartJson(requireContext())
        return cart.sumOf { product -> product.getTotalPrice() }
    }

    @SuppressLint("SetTextI18n")
    override fun onResume() {
        super.onResume()
        val cart = json.readCartJson(requireContext())

        cart.forEach { product -> createProductCard(product) }

        view?.findViewById<TextView>(R.id.checkout_button)?.text = "\uD83D\uDCB0 $${totalCartPrice() / 100.0f}"
    }

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val view = inflater.inflate(R.layout.fragment_cart, container, false)
        val context = requireContext()

        val nfc = view?.findViewById<TextView>(R.id.nfc_btn)
        nfc?.setOnClickListener {
            if (totalCartPrice() <= 0) return@setOnClickListener
            val intent = Intent(context, NFC::class.java)
            vibrate()
            startActivity(intent)
            activity?.finish()
        }

        val qr = view?.findViewById<TextView>(R.id.qr_btn)
        qr?.setOnClickListener {
            if (totalCartPrice() <= 0) return@setOnClickListener
            val intent = Intent(context, QRCodeScanner::class.java)
            vibrate()
            startActivity(intent)
            activity?.finish()
        }

        return view
    }

    private fun vibrate() {
        val vibrator = context?.getSystemService(Context.VIBRATOR_SERVICE) as Vibrator
        vibrator.vibrate(VibrationEffect.createOneShot(100, 30))
    }
}