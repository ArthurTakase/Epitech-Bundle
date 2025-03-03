import com.github.jasync.sql.db.RowData
import java.time.OffsetDateTime

class AccountParser(row: RowData) {
    val row = row

    fun parse(): Account {
        return Account(
            id = row.get("id") as Int,
            number = row.get("number") as String,
            sold = row.get("sold") as Double,
            created_at = row.get("created_at") as OffsetDateTime,
            updated_at = row.get("updated_at") as OffsetDateTime,
        )
    }
}
