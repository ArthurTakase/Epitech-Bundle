defmodule ApiWeb.Swagger.AuthSwagger do
  use PhoenixSwagger

  def swagger_definition() do
    %{
      Auth:
        swagger_schema do
          title("Auth")
          description("Login infos of an user of the app")

          properties do
            token(:string, "Token")
            username(:string, "User name", required: true)
            user_id(:integer, "User ID", required: true)
          end

          example(%{
            token: "token",
            username: "username",
            user_id: 123
          })
        end,
      AuthRequest:
        swagger_schema do
          title("AuthRequest")
          description("POST body for login")
          property(:email, :string, "Email address", format: :email, required: true)
          property(:password, :string, "Password", required: true)
        end,
      AuthResponse:
        swagger_schema do
          title("AuthResponse")
          description("Response schema for single user")
          property(:data, Schema.ref(:Auth), "The user details")
        end
    }
  end

  # -----------------------------------
  # Data Example
  # -----------------------------------

  def swagger_example_login() do
    %{
      email: "arthur@mail.com",
      password: "123456"
    }
  end

  # -----------------------------------
  # Login
  # -----------------------------------

  def swagger_path_login_response_200() do
    %{
      "application/json": %{
        data: %{
          token: "token",
          username: "username",
          user_id: 123
        }
      }
    }
  end

  def swagger_path_login_response_404() do
    %{
      "application/json": %{
        error: "user not found"
      }
    }
  end
end
