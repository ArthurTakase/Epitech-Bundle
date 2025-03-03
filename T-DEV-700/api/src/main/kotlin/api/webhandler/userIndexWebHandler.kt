import io.javalin.http.Context

class UserIndexWebHandler(val userRepository: UserRepository) : WebHandler() {

    override fun call(ctx: Context) {
        println(userRepository)
        val users = userRepository.all()
        ctx.json(users)
    }
}
