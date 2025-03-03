import java.time.OffsetDateTime

data class Account(
    val id: Int,
    val number: String,
    val sold: Double,
    val created_at: OffsetDateTime,
    val updated_at: OffsetDateTime,
) {
    override fun toString(): String {
        return "Account(id=$id, number=$number, sold=$sold, created_at=$created_at, updated_at=$updated_at)"
    }
}
