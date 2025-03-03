defmodule ApiWeb.LocationControllerTest do
  use ApiWeb.ConnCase

  # Browse
  @default_attrs %{
    city: "Bordeaux"
  }

  setup %{conn: conn} do
    {:ok, conn: put_req_header(conn, "accept", "application/json")}
  end

  describe "location" do
    test "get Bordeaux location", %{conn: conn} do
      conn = get(conn, ~p"/api/location", @default_attrs)
      req = Enum.at(json_response(conn, 200)["data"], 0)
      assert conn.status == 200

      assert req["lat"] == "44.841225"
      assert req["lon"] == "-0.5800364"
    end
  end
end
