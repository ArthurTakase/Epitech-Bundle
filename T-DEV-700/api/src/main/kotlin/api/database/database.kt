import com.github.jasync.sql.db.QueryResult
import com.github.jasync.sql.db.postgresql.PostgreSQLConnectionBuilder
import java.util.concurrent.CompletableFuture
import kotlin.collections.listOf

class Database(databasePath: String) {
    private var connection = PostgreSQLConnectionBuilder.createConnectionPool(databasePath)

    fun execQuery(query: String): CompletableFuture<QueryResult> {
        return connection.sendPreparedStatement(query)
    }

    fun execQuery(
        query: String,
        args: List<String> = listOf(),
    ): CompletableFuture<QueryResult> {
        return connection.sendPreparedStatement(query, args)
    }
}
