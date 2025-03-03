defmodule ApiWeb.AuthController do
  use ApiWeb, :controller
  use PhoenixSwagger
  alias ApiWeb.Swagger.AuthSwagger

  alias Api.Users
  alias Phoenix.Token

  @salt "monsupermdp"

  action_fallback(ApiWeb.FallbackController)

  def login(conn, %{"email" => email, "password" => password}) do
    user = Users.get_user_by_mail_and_password(email, password)

    if user do
      token = Token.sign(conn, @salt, user.id, max_age: 30 * 24 * 60 * 60 * 1000)

      render(conn, "show.json", %{
        token: token,
        user_id: user.id,
        username: user.username
      })
    else
      conn
      |> put_status(:not_found)
      |> render("error.json", %{error: "user not found"})
    end
  end

  # -----------------------------------
  # Swagger
  # -----------------------------------

  def swagger_definitions do
    AuthSwagger.swagger_definition()
  end

  swagger_path :login do
    get("/auth/login")
    produces("application/json")
    tag("Auth")
    operation_id("login")
    description("Get a token for a user.")
    deprecated(false)

    parameter(:user, :body, Schema.ref(:AuthRequest), "The login details",
      example: AuthSwagger.swagger_example_login()
    )

    response(200, "OK", Schema.ref(:AuthResponse), %{
      examples: AuthSwagger.swagger_path_login_response_200()
    })

    response(404, "Not Found", Schema.ref(:ErrorResponse), %{
      examples: AuthSwagger.swagger_path_login_response_404()
    })

    response(500, "Internal Server Error")
  end
end
