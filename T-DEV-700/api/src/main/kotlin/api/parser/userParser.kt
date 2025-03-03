import com.github.jasync.sql.db.RowData
import java.time.OffsetDateTime

class UserParser(row: RowData) {
    val row = row

    fun parse(): User {
        return User(
            id = row.get("id") as Int,
            name = row.get("name") as String,
            email = row.get("email") as String,
            last_key = row.get("last_key") as String?,
            created_at = row.get("created_at") as OffsetDateTime,
            updated_at = row.get("updated_at") as OffsetDateTime,
        )
    }
}
