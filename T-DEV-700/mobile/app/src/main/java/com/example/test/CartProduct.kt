package com.example.test

class CartProduct(var product: Product, var quantity: Int) {
    fun getTotalPrice(): Int {
        return product.price * quantity
    }
}

