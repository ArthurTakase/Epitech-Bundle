defmodule ApiWeb.ApiControllerTest do
  use ApiWeb.ConnCase

  # Browse
  @default_attrs %{
    lat: "44.87433546903434",
    lon: "-0.5782521103907302",
    limit: "5"
  }
  @noLimit_attrs %{
    lat: "44.87433546903434",
    lon: "-0.5782521103907302"
  }

  setup %{conn: conn} do
    {:ok, conn: put_req_header(conn, "accept", "application/json")}
  end

  describe "enjoy" do
    test "get activities from API", %{conn: conn} do
      conn = post(conn, ~p"/api/enjoy", @default_attrs)
      items = json_response(conn, 200)["data"]["items"]
      assert length(items) <= 5
      Process.sleep(1000)
    end

    test "get activities from API (No Limit)", %{conn: conn} do
      conn = post(conn, ~p"/api/enjoy", @noLimit_attrs)
      items = json_response(conn, 200)["data"]["items"]
      assert length(items) <= 20
      Process.sleep(1000)
    end
  end

  describe "sleep" do
    test "get activities from API", %{conn: conn} do
      conn = post(conn, ~p"/api/sleep", @default_attrs)
      items = json_response(conn, 200)["data"]["items"]
      assert length(items) <= 5
      Process.sleep(1000)
    end

    test "get activities from API (No Limit)", %{conn: conn} do
      conn = post(conn, ~p"/api/sleep", @noLimit_attrs)
      items = json_response(conn, 200)["data"]["items"]
      assert length(items) <= 20
      Process.sleep(1000)
    end
  end

  describe "travel" do
    test "get activities from API", %{conn: conn} do
      conn = post(conn, ~p"/api/travel", @default_attrs)
      items = json_response(conn, 200)["data"]["items"]
      assert length(items) <= 5
      Process.sleep(1000)
    end

    test "get activities from API (No Limit)", %{conn: conn} do
      conn = post(conn, ~p"/api/travel", @noLimit_attrs)
      items = json_response(conn, 200)["data"]["items"]
      assert length(items) <= 20
      Process.sleep(1000)
    end
  end

  describe "eat" do
    test "get activities from API", %{conn: conn} do
      conn = post(conn, ~p"/api/eat", @default_attrs)
      items = json_response(conn, 200)["data"]["items"]
      assert length(items) <= 5
      Process.sleep(1000)
    end

    test "get activities from API (No Limit)", %{conn: conn} do
      conn = post(conn, ~p"/api/eat", @noLimit_attrs)
      items = json_response(conn, 200)["data"]["items"]
      assert length(items) <= 20
      Process.sleep(1000)
    end
  end

  describe "drink" do
    test "get activities from API", %{conn: conn} do
      conn = post(conn, ~p"/api/drink", @default_attrs)
      items = json_response(conn, 200)["data"]["items"]
      assert length(items) <= 5
      Process.sleep(1000)
    end

    test "get activities from API (No Limit)", %{conn: conn} do
      conn = post(conn, ~p"/api/drink", @noLimit_attrs)
      items = json_response(conn, 200)["data"]["items"]
      assert length(items) <= 20
      Process.sleep(1000)
    end
  end
end
