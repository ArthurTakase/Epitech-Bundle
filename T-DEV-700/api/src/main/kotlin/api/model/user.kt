import java.time.OffsetDateTime

data class User(
    val id: Int,
    val name: String,
    val email: String,
    val last_key: String?,
    val created_at: OffsetDateTime,
    val updated_at: OffsetDateTime,
) {
    override fun toString(): String {
        return "User(id=$id, name=$name, email=$email, last_key=$last_key, created_at=$created_at, updated_at=$updated_at)"
    }
}
