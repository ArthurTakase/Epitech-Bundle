defmodule ApiWeb.WorkingtimeControllerTest do
  use ApiWeb.ConnCase

  import Api.WorkingtimesFixtures

  alias Api.Workingtimes.Workingtime

  @create_attrs %{
    start: ~U[2023-10-22 19:18:00Z],
    end: ~U[2023-10-22 19:18:00Z]
  }
  @update_attrs %{
    start: ~U[2023-10-23 19:18:00Z],
    end: ~U[2023-10-23 19:18:00Z]
  }
  @invalid_attrs %{start: nil, end: nil}

  setup %{conn: conn} do
    {:ok, conn: put_req_header(conn, "accept", "application/json")}
  end

  describe "index" do
    test "lists all workingtimes", %{conn: conn} do
      conn = get(conn, ~p"/api/workingtimes")
      assert json_response(conn, 200)["data"] == []
    end
  end

  describe "create workingtime" do
    test "renders workingtime when data is valid", %{conn: conn} do
      conn = post(conn, ~p"/api/workingtimes", workingtime: @create_attrs)
      assert %{"id" => id} = json_response(conn, 201)["data"]

      conn = get(conn, ~p"/api/workingtimes/#{id}")

      assert %{
               "id" => ^id,
               "end" => "2023-10-22T19:18:00Z",
               "start" => "2023-10-22T19:18:00Z"
             } = json_response(conn, 200)["data"]
    end

    test "renders errors when data is invalid", %{conn: conn} do
      conn = post(conn, ~p"/api/workingtimes", workingtime: @invalid_attrs)
      assert json_response(conn, 422)["errors"] != %{}
    end
  end

  describe "update workingtime" do
    setup [:create_workingtime]

    test "renders workingtime when data is valid", %{conn: conn, workingtime: %Workingtime{id: id} = workingtime} do
      conn = put(conn, ~p"/api/workingtimes/#{workingtime}", workingtime: @update_attrs)
      assert %{"id" => ^id} = json_response(conn, 200)["data"]

      conn = get(conn, ~p"/api/workingtimes/#{id}")

      assert %{
               "id" => ^id,
               "end" => "2023-10-23T19:18:00Z",
               "start" => "2023-10-23T19:18:00Z"
             } = json_response(conn, 200)["data"]
    end

    test "renders errors when data is invalid", %{conn: conn, workingtime: workingtime} do
      conn = put(conn, ~p"/api/workingtimes/#{workingtime}", workingtime: @invalid_attrs)
      assert json_response(conn, 422)["errors"] != %{}
    end
  end

  describe "delete workingtime" do
    setup [:create_workingtime]

    test "deletes chosen workingtime", %{conn: conn, workingtime: workingtime} do
      conn = delete(conn, ~p"/api/workingtimes/#{workingtime}")
      assert response(conn, 204)

      assert_error_sent 404, fn ->
        get(conn, ~p"/api/workingtimes/#{workingtime}")
      end
    end
  end

  defp create_workingtime(_) do
    workingtime = workingtime_fixture()
    %{workingtime: workingtime}
  end
end
