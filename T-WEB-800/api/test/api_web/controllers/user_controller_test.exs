defmodule ApiWeb.UserControllerTest do
  use ApiWeb.ConnCase

  import Api.UsersFixtures
  import Api.SavesFixtures

  alias Api.Users.User
  alias Api.Users

  @create_attrs %{
    username: "some username",
    password: "P@ssw0rd",
    email: "mail@mail.com"
  }
  @update_attrs %{
    username: "some updated username",
    password: "P@ssw0rd2",
    email: "mail@mail.com"
  }
  @invalid_mail %{
    username: "some updated username",
    password: "P@ssw0rd2",
    email: "some updated email"
  }
  @login_attrs %{
    email: "mail@mail.com",
    password: "P@ssw0rd"
  }
  @invalid_attrs %{username: "", password: "", email: ""}

  setup %{conn: conn} do
    {:ok, conn: put_req_header(conn, "accept", "application/json")}
  end

  describe "index" do
    test "lists all users", %{conn: conn} do
      conn = get(conn, ~p"/api/users")
      assert json_response(conn, 200)["data"] == []
    end
  end

  describe "create user" do
    test "renders user when data is valid", %{conn: conn} do
      conn = post(conn, ~p"/api/users", user: @create_attrs)
      assert %{"id" => id} = json_response(conn, 201)["data"]

      conn = get(conn, ~p"/api/users/#{id}")
      password = encrypt_password("P@ssw0rd")
      user = getUserFromDB(id)

      assert %{
               "id" => ^id,
               "email" => "mail@mail.com",
               "username" => "some username"
             } = json_response(conn, 200)["data"]

      assert user.password == password
    end

    test "renders errors when data is invalid", %{conn: conn} do
      conn = post(conn, ~p"/api/users", user: @invalid_attrs)
      assert json_response(conn, 422)["errors"] != %{}
    end

    test "renders errors when email is invalid", %{conn: conn} do
      conn = post(conn, ~p"/api/users", user: @invalid_mail)
      assert json_response(conn, 422)["errors"] != %{}
    end
  end

  describe "update user" do
    setup [:create_user]

    test "renders user when data is valid (Not Login)", %{conn: conn, user: %User{id: _} = user} do
      conn = put(conn, ~p"/api/users/#{user}", user: @update_attrs)
      assert conn.status == 401
      assert String.contains?(conn.resp_body, "Unauthorized")
    end

    test "renders user when data is valid (Login)", %{conn: conn, user: %User{id: id} = user} do
      conn = loginAndGetToken(conn)
      conn = put(conn, ~p"/api/users/#{user}", user: @update_attrs)
      assert %{"id" => ^id} = json_response(conn, 200)["data"]

      conn = get(conn, ~p"/api/users/#{id}")
      password = encrypt_password("P@ssw0rd2")
      user = getUserFromDB(id)

      assert %{
               "id" => ^id,
               "email" => "mail@mail.com",
               "username" => "some updated username"
             } = json_response(conn, 200)["data"]

      assert user.password == password
    end

    test "renders errors when data is invalid", %{conn: conn, user: user} do
      conn = loginAndGetToken(conn)
      conn = put(conn, ~p"/api/users/#{user}", user: @invalid_attrs)
      assert json_response(conn, 422)["errors"] != %{}
    end
  end

  describe "delete user" do
    setup [:create_user]

    test "deletes chosen user (Not Login)", %{conn: conn, user: user} do
      conn = delete(conn, ~p"/api/users/#{user}")
      assert conn.status == 401
      assert String.contains?(conn.resp_body, "Unauthorized")
    end

    test "deletes chosen user (Login)", %{conn: conn, user: user} do
      conn = loginAndGetToken(conn)
      conn = delete(conn, ~p"/api/users/#{user}")
      assert response(conn, 204)

      assert_error_sent(404, fn ->
        get(conn, ~p"/api/users/#{user}")
      end)
    end
  end

  describe "user's save" do
    setup [:create_user]

    test "Get all user's saves (Login)", %{conn: conn, user: user} do
      conn = loginAndGetToken(conn)
      conn = get(conn, ~p"/api/saves/user/#{user.id}")
      saves = json_response(conn, 200)["data"]

      assert saves == []

      save_user_fixture(user.id)
      save_user_fixture(user.id)
      save_user_fixture(user.id)

      conn = get(conn, ~p"/api/saves/user/#{user.id}")
      saves = json_response(conn, 200)["data"]

      assert length(saves) == 3
    end

    test "Get all user's saves (Not Login)", %{conn: conn, user: user} do
      conn = get(conn, ~p"/api/saves/user/#{user.id}")
      assert conn.status == 401
      assert String.contains?(conn.resp_body, "Unauthorized")
    end

    test "Check saves after remove user", %{conn: conn, user: user} do
      conn = loginAndGetToken(conn)
      conn = get(conn, ~p"/api/saves/user/#{user.id}")
      saves = json_response(conn, 200)["data"]
      assert saves == []

      save_user_fixture(user.id)
      save_user_fixture(user.id)
      save_user_fixture(user.id)

      conn = get(conn, ~p"/api/saves")
      saves = json_response(conn, 200)["data"]
      assert length(saves) == 3

      conn = delete(conn, ~p"/api/users/#{user}")
      assert response(conn, 204)

      conn = get(conn, ~p"/api/saves")
      saves = json_response(conn, 200)["data"]
      assert length(saves) == 0
    end
  end

  defp create_user(_) do
    user = user_fixture()
    %{user: user}
  end

  defp loginAndGetToken(conn) do
    user_fixture()
    connLogin = post(conn, ~p"/auth/login", @login_attrs)
    token = json_response(connLogin, 200)["data"]["token"]
    conn = put_req_header(conn, "authorization", "Bearer #{token}")
    conn
  end

  defp encrypt_password(password) do
    Base.encode16(:crypto.hash(:sha256, "#{password}HelloWorld"))
  end

  defp getUserFromDB(id) do
    Users.get_user!(id)
  end
end
