class UserRepository(database: Database) {
    private val database = database

    fun all(): List<User> {
        val result = database.execQuery("SELECT * FROM USERS").get()
        val users = result.rows.map { row -> UserParser(row).parse() }
        println(users)
        return users
    }

    fun create(
        name: String,
        email: String,
        password: String,
    ): User? {
        println("Creating user")
        val passwordHashed = sha256(password)
        val query = "INSERT INTO users (name, email, password) VALUES (?, ?, ?) RETURNING *"
        val args = listOf(name, email, passwordHashed)
        println(password)
        println(passwordHashed)

        val result = database.execQuery(query, args).get()

        if (result.rowsAffected.equals(0)) {
            return null
        }

        val user = result.rows.map { row -> UserParser(row).parse() }.firstOrNull()
        return user
    }

    fun findByLastKey(last_key: String): User? {
        val query = "SELECT * FROM users WHERE last_key = ?"
        val args = listOf(last_key)

        val result = database.execQuery(query, args).get()

        if (result.rowsAffected.equals(0)) {
            return null
        }

        val user = result.rows.map { row -> UserParser(row).parse() }.firstOrNull()
        return user
    }

    fun findByEmailAndPassword(
        email: String,
        password: String,
    ): User? {
        val passwordHashed = sha256(password)
        val query = "SELECT * FROM users WHERE email = ? AND password = ?"
        val args = listOf(email, passwordHashed)

        println(email)
        print(password)
        println(passwordHashed)

        val result = database.execQuery(query, args).get()

        if (result.rowsAffected.equals(0)) {
            return null
        }

        val user = result.rows.map { row -> UserParser(row).parse() }.firstOrNull()
        return user
    }

    fun update(
        id: Int,
        last_key: String,
    ) {
        val query = "UPDATE users SET last_key = ? WHERE id = ?"
        val idString = id.toString()
        val args = listOf(last_key, idString)

        database.execQuery(query, args).get()
    }

    private fun sha256(input: String): String {
        val message = input.toByteArray()
        val digest = java.security.MessageDigest.getInstance("SHA-256").digest(message)

        val hexChars = CharArray(digest.size * 2)
        for (i in digest.indices) {
            val v = digest[i].toInt() and 0xFF
            hexChars[i * 2] = "0123456789ABCDEF"[v ushr 4]
            hexChars[i * 2 + 1] = "0123456789ABCDEF"[v and 0x0F]
        }

        return String(hexChars)
    }

}
