defmodule ApiWeb.UserController do
  use ApiWeb, :controller

  alias Api.Users
  alias Api.Users.User
  alias Api.Workingtimes
  alias Api.Clocks
  alias Api.Teams

  @salt "monsupermdp"

  action_fallback(ApiWeb.FallbackController)

  def index(conn, %{"username" => username, "email" => email}) do
    user = Users.get_user_by_username_and_email(username, email)

    if user do
      render(conn, :show, user: user)
    else
      conn
      |> put_status(:not_found)
      |> render("error.json", %{error: "user not found"})
    end
  end

  def all_users(conn, _params) do
    users = Users.list_users()
    clocks = Clocks.list_clocks()

    if users do
      render(conn, :index, users: users, clocks: clocks)
    else
      conn
      |> put_status(:not_found)
      |> render("error.json", %{error: "users not found"})
    end
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

    if user do
      render(conn, :show, user: user)
    else
      conn
      |> put_status(:not_found)
      |> render("error.json", %{error: "user not found"})
    end
  end

  def update(conn, %{"id" => id, "user" => user_params}) do
    user = Users.get_user!(id)

    if user do
      with {:ok, %User{} = user} <- Users.update_user(user, user_params) do
        render(conn, :show, user: user)
      end
    else
      conn
      |> put_status(:not_found)
      |> render("error.json", %{error: "user not found"})
    end
  end

  def delete(conn, %{"id" => id}) do
    user = Users.get_user!(id)

    if user do
      Workingtimes.delete_workingtime_by_user_id(id)
      Clocks.delete_clock_by_user_id(id)
      Teams.remove_where_manager(id)

      with {:ok, %User{}} <- Users.delete_user(user) do
        send_resp(conn, :no_content, "")
      end
    else
      conn
      |> put_status(:not_found)
      |> render("error.json", %{error: "user not found"})
    end
  end

  def my_teams(conn, %{"userID" => id}) do
    users = Users.get_teams(id)
    clocks = Clocks.list_clocks()

    if users do
      render(conn, :index, users: users, clocks: clocks)
    else
      conn
      |> put_status(:not_found)
      |> render("error.json", %{error: "teams not found"})
    end
  end

  def get_from_token(conn, _params) do
    token =
      get_req_header(conn, "authorization")
      |> List.first()
      |> extract_token()

    case Phoenix.Token.verify(conn, @salt, token) do
      {:ok, user_id} ->
        user = Users.get_user!(user_id)
        render(conn, :show, user: user)

      {:error, _reason} ->
        conn
        |> put_status(:not_found)
        |> render("error.json", %{error: "user not found"})
    end
  end

  defp extract_token("Bearer " <> token), do: token
  defp extract_token(_), do: nil

  def ping(conn, _params) do
    conn
    |> put_status(:ok)
    |> render("ping.json", %{pong: true})
  end
end
