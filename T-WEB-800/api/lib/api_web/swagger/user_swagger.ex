defmodule ApiWeb.Swagger.UserSwagger do
  use PhoenixSwagger

  def swagger_definition() do
    %{
      User:
        swagger_schema do
          title("User")
          description("A user of the app")

          properties do
            id(:integer, "User ID")
            name(:string, "User name", required: true)
            email(:string, "Email address", format: :email, required: true)
            password(:string, "Password", required: true)
          end

          example(%{
            id: 123,
            name: "Arthur",
            email: "arthur@mail.com",
            password: "123456"
          })
        end,
      UserRequest:
        swagger_schema do
          title("UserRequest")
          description("POST body for creating a user")
          property(:user, Schema.ref(:User), "The user details")
        end,
      UserResponse:
        swagger_schema do
          title("UserResponse")
          description("Response schema for single user")
          property(:data, Schema.ref(:User), "The user details")
        end,
      UsersResponse:
        swagger_schema do
          title("UsersReponse")
          description("Response schema for multiple users")
          property(:data, Schema.array(:User), "The users details")
        end,
      ErrorResponse:
        swagger_schema do
          title("ErrorResponse")
          description("Response schema for errors")
          property(:error, :string, "Error message")
        end
    }
  end

  # -----------------------------------
  # Data Example
  # -----------------------------------

  def swagger_example_user() do
    %{
      user: %{username: "Arthur", email: "arthur@mail.com", password: "123456"}
    }
  end

  # -----------------------------------
  # Index
  # -----------------------------------

  def swagger_path_index_response_200() do
    %{
      "application/json": %{
        data: [
          %{
            id: 1,
            username: "user1",
            email: "user1@gmail.com",
            password: "Mot de passe Hashé"
          },
          %{
            id: 2,
            username: "user2",
            email: "user2@gmail.com",
            password: "Mot de passe Hashé"
          }
        ]
      }
    }
  end

  # -----------------------------------
  # Create
  # -----------------------------------

  def swagger_path_create_response_201() do
    %{
      "application/json": %{
        data: %{
          id: 1,
          username: "Arthur",
          email: "arthur@mail.com",
          password: "Mot de passe Hashé"
        }
      }
    }
  end
end
