import com.fasterxml.jackson.module.kotlin.jacksonObjectMapper
import io.javalin.http.Context

class AccountPurchaseWebHandler(val accountRepository: AccountRepository) : WebHandler() {
    override fun call(ctx: Context) {
        val number: String = ctx.pathParam("number")
        val objectMapper = jacksonObjectMapper()
        val amount: Double = objectMapper.readTree(ctx.body()).get("amount").toString().toDouble()
        val account = accountRepository.getByNumber(number)

        if (account == null) {
            ctx.status(404).json("Account not found")
        } else {
            if (amount < account.sold) {
                accountRepository.purchaseByNumber(number, amount)
                ctx.status(200).json("ok")
            } else {
                ctx.status(406)
            }
        }
    }
}
