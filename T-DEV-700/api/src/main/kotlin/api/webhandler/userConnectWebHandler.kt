import com.fasterxml.jackson.module.kotlin.jacksonObjectMapper
import io.javalin.http.Context
import java.util.UUID

data class UserConnection(val email: String, val password: String)

class UserConnectWebHandler(val userRepository: UserRepository) : WebHandler() {

    override fun call(ctx: Context) {
        val lastKey = UUID.randomUUID().toString()
        val objectMapper = jacksonObjectMapper()
        val userData = objectMapper.readValue(ctx.body(), UserConnection::class.java)

        val user = userRepository.findByEmailAndPassword(userData.email, userData.password)

        if (user == null) {
            ctx.status(401).json("Unauthorized")
            return
        }

        userRepository.update(user.id, lastKey)
        ctx.json(lastKey)
    }
}
