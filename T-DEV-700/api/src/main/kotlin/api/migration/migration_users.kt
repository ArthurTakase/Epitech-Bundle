class MigrationUsers(database: Database) {
    private val database = database

    fun exec() {
        database.execQuery("CREATE TABLE IF NOT EXISTS users (id SERIAL PRIMARY KEY, name VARCHAR(255), email VARCHAR(255) UNIQUE, last_key VARCHAR(255), password VARCHAR(255), created_at TIMESTAMPTZ NOT NULL DEFAULT NOW(), updated_at TIMESTAMPTZ NOT NULL DEFAULT NOW());")
        println("Migration users")
    }
}
