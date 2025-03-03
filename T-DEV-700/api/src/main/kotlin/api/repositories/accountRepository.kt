class AccountRepository(database: Database) {
    private val database = database

    fun get(id: Int): Account? {
        val result = database.execQuery("SELECT * FROM ACCOUNTS WHERE id=$id").get()
        val account = result.rows.map { row -> AccountParser(row).parse() }.firstOrNull()
        return account
    }

    fun getByNumber(number: String): Account? {
        val result = database.execQuery("SELECT * FROM ACCOUNTS WHERE number='$number'").get()
        val account = result.rows.map { row -> AccountParser(row).parse() }.firstOrNull()
        return account
    }

    fun purchase(
        id: Int,
        amount: Double,
    ) {
        val sold = database.execQuery("SELECT sold FROM ACCOUNTS WHERE id=$id").get().rows[0].get("sold") as Double
        update(id, (sold - amount))
    }

    fun purchaseByNumber(
        number: String,
        amount: Double,
    ) {
        val sold = database.execQuery("SELECT sold FROM ACCOUNTS WHERE number='$number'").get().rows[0].get("sold") as Double
        updateByNumber(number, (sold - amount))
    }

    fun update(
        id: Int,
        newSold: Double,
    ): Account {
        val result =
            database.execQuery("UPDATE ACCOUNTS SET sold=$newSold WHERE id=$id RETURNING *")
                .get()
        val account = result.rows.map { row -> AccountParser(row).parse() }.first()
        return account
    }

    fun updateByNumber(
        number: String,
        newSold: Double,
    ): Account {
        val result =
            database.execQuery("UPDATE ACCOUNTS SET sold=$newSold WHERE number='$number' RETURNING *")
                .get()
        val account = result.rows.map { row -> AccountParser(row).parse() }.first()
        return account
    }
}
