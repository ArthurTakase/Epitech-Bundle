defmodule ApiWeb.SaveControllerTest do
  use ApiWeb.ConnCase

  import Api.SavesFixtures
  import Api.UsersFixtures

  alias Api.Saves.Save

  @create_attrs %{
    data: "W10="
  }
  @update_attrs %{
    data: "W3t9XQ=="
  }
  @login_attrs %{
    email: "mail@mail.com",
    password: "P@ssw0rd"
  }
  @invalid_attrs %{data: nil}

  setup %{conn: conn} do
    {:ok, conn: put_req_header(conn, "accept", "application/json")}
  end

  describe "index" do
    test "lists all saves (Not Login)", %{conn: conn} do
      conn = get(conn, ~p"/api/saves")
      assert conn.status == 401
      assert String.contains?(conn.resp_body, "Unauthorized")
    end

    test "lists all saves (Login)", %{conn: conn} do
      conn = loginAndGetToken(conn)
      conn = get(conn, ~p"/api/saves")
      assert json_response(conn, 200)["data"] == []
    end
  end

  describe "create save" do
    test "renders save when data is valid (Not Login)", %{conn: conn} do
      conn = post(conn, ~p"/api/saves", save: @create_attrs)
      assert conn.status == 401
      assert String.contains?(conn.resp_body, "Unauthorized")
    end

    test "renders save when data is valid (Login)", %{conn: conn} do
      conn = loginAndGetToken(conn)
      conn = post(conn, ~p"/api/saves", save: @create_attrs)
      assert %{"id" => id} = json_response(conn, 201)["data"]

      conn = get(conn, ~p"/api/saves/#{id}")

      assert %{
               "id" => ^id,
               "data" => "W10="
             } = json_response(conn, 200)["data"]
    end

    test "renders errors when data is invalid", %{conn: conn} do
      conn = loginAndGetToken(conn)
      conn = post(conn, ~p"/api/saves", save: @invalid_attrs)
      assert json_response(conn, 422)["errors"] != %{}
    end
  end

  describe "get save" do
    setup [:create_save]

    test "from code (Not Login)", %{
      conn: conn,
      save: %Save{id: id, code: code} = _
    } do
      conn = get(conn, ~p"/api/saves/code/#{code}")

      assert json_response(conn, 200)["data"] == []

      assert %{
               "id" => ^id,
               "code" => ^code
             } = json_response(conn, 200)["save"]
    end
  end

  describe "update save" do
    setup [:create_save]

    test "renders save when data is valid (Not Login)", %{conn: conn, save: %Save{id: _} = save} do
      conn = put(conn, ~p"/api/saves/#{save}", save: @update_attrs)
      assert conn.status == 401
      assert String.contains?(conn.resp_body, "Unauthorized")
    end

    test "renders save when data is valid (Login)", %{
      conn: conn,
      save: %Save{id: id, code: code} = save
    } do
      conn = loginAndGetToken(conn)
      conn = put(conn, ~p"/api/saves/#{save}", save: @update_attrs)
      assert %{"id" => ^id} = json_response(conn, 200)["data"]

      conn = get(conn, ~p"/api/saves/#{id}")

      assert %{
               "id" => ^id,
               "code" => ^code,
               "data" => "W3t9XQ=="
             } = json_response(conn, 200)["data"]
    end

    test "renders errors when data is invalid", %{conn: conn, save: save} do
      conn = loginAndGetToken(conn)
      conn = put(conn, ~p"/api/saves/#{save}", save: @invalid_attrs)
      assert json_response(conn, 422)["errors"] != %{}
    end
  end

  describe "delete save" do
    setup [:create_save]

    test "deletes chosen save (Not Login)", %{conn: conn, save: save} do
      conn = delete(conn, ~p"/api/saves/#{save}")
      assert conn.status == 401
      assert String.contains?(conn.resp_body, "Unauthorized")
    end

    test "deletes chosen save (Login)", %{conn: conn, save: save} do
      conn = loginAndGetToken(conn)
      conn = delete(conn, ~p"/api/saves/#{save}")
      assert response(conn, 204)

      assert_error_sent(404, fn ->
        get(conn, ~p"/api/saves/#{save}")
      end)
    end
  end

  defp create_save(_) do
    save = save_fixture()
    %{save: save}
  end

  defp loginAndGetToken(conn) do
    user_fixture()
    connLogin = post(conn, ~p"/auth/login", @login_attrs)
    token = json_response(connLogin, 200)["data"]["token"]
    conn = put_req_header(conn, "authorization", "Bearer #{token}")
    conn
  end
end
