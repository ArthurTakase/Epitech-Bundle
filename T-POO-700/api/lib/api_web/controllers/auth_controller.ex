defmodule ApiWeb.AuthController do
  use ApiWeb, :controller

  alias Api.Users
  alias Phoenix.Token

  @salt "monsupermdp"

  action_fallback(ApiWeb.FallbackController)

  def login(conn, %{"email" => email, "password" => password}) do
    user = Users.get_user_by_mail_and_password(email, password)

    if user do
      token = Token.sign(conn, @salt, user.id)

      render(conn, "show.json", %{
        token: token,
        role: user.user_role,
        user_id: user.id,
        username: user.username
      })
    else
      conn
      |> put_status(:not_found)
      |> render("error.json", %{error: "user not found"})
    end
  end
end
