class MigrationAccounts(database: Database) {
    private val database = database

    fun exec() {
        database.execQuery(
            "CREATE TABLE IF NOT EXISTS accounts (id SERIAL PRIMARY KEY, number VARCHAR(255) UNIQUE, sold FLOAT, created_at TIMESTAMPTZ NOT NULL DEFAULT NOW(), updated_at TIMESTAMPTZ NOT NULL DEFAULT NOW());",
        )
        println("Migration accounts")
    }
}
