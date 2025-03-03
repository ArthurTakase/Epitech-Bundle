import io.javalin.http.Context

abstract class WebHandler() {
    fun handle(ctx: Context) {
        try {
            call(ctx)
        } catch (e: Exception) {
            println(e)
            ctx.status(501)
        }
    }

    abstract fun call(ctx: Context)
}
