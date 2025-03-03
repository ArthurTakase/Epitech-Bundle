defmodule ApiWeb.AuthControllerTest do
  use ApiWeb.ConnCase

  @valid_attrs %{
    email: "mail@mail.com",
    password: "P@ssw0rd"
  }

  @invalid_attrs %{
    email: "blop@mail.com",
    password: "P@ssw0rd"
  }

  @create_attrs %{
    username: "some username",
    password: "P@ssw0rd",
    email: "mail@mail.com"
  }

  describe "login" do
    test "renders user when data is valid", %{conn: conn} do
      conn = post(conn, ~p"/api/users", user: @create_attrs)
      conn = post(conn, ~p"/auth/login", @valid_attrs)
      assert %{"token" => _, "username" => _, "user_id" => _} = json_response(conn, 200)["data"]
    end

    test "renders errors when data is invalid", %{conn: conn} do
      conn = post(conn, ~p"/auth/login", @invalid_attrs)
      assert json_response(conn, 404)["error"] == "user not found"
    end
  end
end
