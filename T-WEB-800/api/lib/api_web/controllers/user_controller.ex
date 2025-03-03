defmodule ApiWeb.UserController do
  use ApiWeb, :controller
  use PhoenixSwagger
  alias ApiWeb.Swagger.UserSwagger

  alias Api.Users
  alias Api.Users.User

  action_fallback(ApiWeb.FallbackController)

  def index(conn, _params) do
    users = Users.list_users()
    render(conn, :index, users: users)
  end

  def create(conn, %{"user" => user_params}) do
    user = Users.get_user_by_username_or_email(user_params["username"], user_params["email"])

    if user do
      conn
      |> put_status(:not_found)
      |> render("error.json", %{error: "user already exists"})
    else
      with {:ok, %User{} = user} <- Users.create_user(user_params) do
        conn
        |> put_status(:created)
        |> put_resp_header("location", ~p"/api/users/#{user}")
        |> render(:show, user: user)
      end
    end
  end

  def show(conn, %{"id" => id}) do
    user = Users.get_user!(id)
    render(conn, :show, user: user)
  end

  def update(conn, %{"id" => id, "user" => user_params}) do
    user = Users.get_user!(id)

    with {:ok, %User{} = user} <- Users.update_user(user, user_params) do
      render(conn, :show, user: user)
    end
  end

  def deleteUser(conn, %{"id" => id}) do
    user = Users.get_user!(id)

    with {:ok, %User{}} <- Users.delete_user(user) do
      send_resp(conn, :no_content, "")
    end
  end

  # -----------------------------------
  # Swagger
  # -----------------------------------

  def swagger_definitions do
    UserSwagger.swagger_definition()
  end

  swagger_path :index do
    get("/api/users")
    produces("application/json")
    tag("Users")
    operation_id("list_users")
    description("Retrieve the list of users")
    deprecated(false)

    response(200, "OK", Schema.ref(:UsersResponse), %{
      examples: UserSwagger.swagger_path_index_response_200()
    })

    response(500, "Internal Server Error")
  end

  swagger_path :create do
    post("/api/users")
    consumes("application/json")
    produces("application/json")
    tag("Users")
    operation_id("create_user")
    description("Create a new user")
    deprecated(false)

    parameter(:user, :body, Schema.ref(:UserRequest), "The user details",
      example: UserSwagger.swagger_example_user()
    )

    response(201, "Created", Schema.ref(:UserResponse), %{
      examples: UserSwagger.swagger_path_create_response_201()
    })

    response(422, "Unprocessable Entity", Schema.ref(:ErrorResponse))

    response(400, "Bad Request")
    response(500, "Internal Server Error")
  end

  swagger_path :show do
    get("/api/users/:id")
    produces("application/json")
    tag("Users")
    operation_id("get_user")
    description("Retrieve a user")
    deprecated(false)

    parameter(:id, :path, :integer, "The user ID", required: true)

    response(200, "OK", Schema.ref(:UserResponse), %{
      examples: UserSwagger.swagger_path_create_response_201()
    })

    response(404, "Not Found")
    response(500, "Internal Server Error")
  end

  swagger_path :update do
    put("/api/users/:id")
    consumes("application/json")
    produces("application/json")
    tag("Users")
    operation_id("update_user")
    description("Update a user")
    deprecated(false)

    parameter(:id, :path, :integer, "The user ID", required: true)

    parameter(:user, :body, Schema.ref(:UserRequest), "The user details",
      example: UserSwagger.swagger_example_user()
    )

    response(200, "OK", Schema.ref(:UserResponse), %{
      examples: UserSwagger.swagger_path_create_response_201()
    })

    response(422, "Unprocessable Entity", Schema.ref(:ErrorResponse))

    response(400, "Bad Request")
    response(500, "Internal Server Error")
  end

  swagger_path :deleteUser do
    delete("/api/users/:id")
    tag("Users")
    operation_id("delete_user")
    description("Delete a user")
    deprecated(false)

    parameter(:id, :path, :integer, "The user ID", required: true)

    response(204, "No Content (Delete successful)")
    response(404, "Not Found")
    response(500, "Internal Server Error")
  end
end
