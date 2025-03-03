defmodule ApiWeb.HereControllerTest do
  use ApiWeb.ConnCase
  alias ApiWeb.HereController

  # Browse
  @default_attrs %{
    lat: "44.87433546903434",
    lon: "-0.5782521103907302",
    cat: "200-2000-0014",
    limit: "5"
  }
  @noLimit_attrs %{
    lat: "44.87433546903434",
    lon: "-0.5782521103907302",
    cat: "200-2000-0014"
  }
  @noCat_attrs %{
    lat: "44.87433546903434",
    lon: "-0.5782521103907302",
    limit: "5"
  }
  @noCatNoLimit_attrs %{
    lat: "44.87433546903434",
    lon: "-0.5782521103907302"
  }
  # BrowseIn
  @default_in_attrs %{
    lat: "44.87433546903434",
    lon: "-0.5782521103907302",
    west_lon: "-0.6820715736918265",
    south_lat: "44.8474332093429",
    east_lon: "-0.44681282094789493",
    north_lat: "44.94824868747471",
    cat: "200-2000-0014",
    limit: "5"
  }
  @noLimit_in_attrs %{
    lat: "44.87433546903434",
    lon: "-0.5782521103907302",
    west_lon: "-0.6820715736918265",
    south_lat: "44.8474332093429",
    east_lon: "-0.44681282094789493",
    north_lat: "44.94824868747471",
    cat: "200-2000-0014"
  }
  @noCat_in_attrs %{
    lat: "44.87433546903434",
    lon: "-0.5782521103907302",
    west_lon: "-0.6820715736918265",
    south_lat: "44.8474332093429",
    east_lon: "-0.44681282094789493",
    north_lat: "44.94824868747471",
    limit: "5"
  }
  @noCatNoLimit_in_attrs %{
    lat: "44.87433546903434",
    lon: "-0.5782521103907302",
    west_lon: "-0.6820715736918265",
    south_lat: "44.8474332093429",
    east_lon: "-0.44681282094789493",
    north_lat: "44.94824868747471"
  }
  # Browse Route
  @default_route_attrs %{
    lat: "44.87433546903434",
    lon: "-0.5782521103907302",
    cat: "200-2000-0014",
    limit: "5",
    route: "BFoz5xJ67i1B1B7PzIhaxL7Y;w=5000"
  }
  @noLimit_route_attrs %{
    lat: "44.87433546903434",
    lon: "-0.5782521103907302",
    cat: "200-2000-0014",
    route: "BFoz5xJ67i1B1B7PzIhaxL7Y;w=5000"
  }
  @noCat_route_attrs %{
    lat: "44.87433546903434",
    lon: "-0.5782521103907302",
    limit: "5",
    route: "BFoz5xJ67i1B1B7PzIhaxL7Y;w=5000"
  }
  @noCatNoLimit_route_attrs %{
    lat: "44.87433546903434",
    lon: "-0.5782521103907302",
    route: "BFoz5xJ67i1B1B7PzIhaxL7Y;w=5000"
  }

  setup %{conn: conn} do
    {:ok, conn: put_req_header(conn, "accept", "application/json")}
  end

  describe "browse" do
    test "get activities from API", %{conn: conn} do
      conn = post(conn, ~p"/api/here/browse", @default_attrs)
      items = json_response(conn, 200)["data"]["items"]
      assert length(items) <= 5
      Process.sleep(1000)
    end

    test "get activities from API (No Cat)", %{conn: conn} do
      conn = post(conn, ~p"/api/here/browse", @noCat_attrs)
      items = json_response(conn, 200)["data"]["items"]
      assert length(items) <= 5
      Process.sleep(1000)
    end

    test "get activities from API (No Limit)", %{conn: conn} do
      conn = post(conn, ~p"/api/here/browse", @noLimit_attrs)
      items = json_response(conn, 200)["data"]["items"]
      assert length(items) <= 20
      Process.sleep(1000)
    end

    test "get activities from API (No Limit, No Cat)", %{conn: conn} do
      conn = post(conn, ~p"/api/here/browse", @noCatNoLimit_attrs)
      items = json_response(conn, 200)["data"]["items"]
      assert length(items) <= 20
      Process.sleep(1000)
    end
  end

  describe "browseIn" do
    test "get activities from API", %{conn: conn} do
      conn = post(conn, ~p"/api/here/browseIn", @default_in_attrs)
      items = json_response(conn, 200)["data"]["items"]
      assert length(items) <= 5
      Process.sleep(1000)
    end

    test "get activities from API (No Cat)", %{conn: conn} do
      conn = post(conn, ~p"/api/here/browseIn", @noCat_in_attrs)
      items = json_response(conn, 200)["data"]["items"]
      assert length(items) <= 5
      Process.sleep(1000)
    end

    test "get activities from API (No Limit)", %{conn: conn} do
      conn = post(conn, ~p"/api/here/browseIn", @noLimit_in_attrs)
      items = json_response(conn, 200)["data"]["items"]
      assert length(items) <= 20
      Process.sleep(1000)
    end

    test "get activities from API (No Limit, No Cat)", %{conn: conn} do
      conn = post(conn, ~p"/api/here/browseIn", @noCatNoLimit_in_attrs)
      items = json_response(conn, 200)["data"]["items"]
      assert length(items) <= 20
      Process.sleep(1000)
    end
  end

  describe "browseRoute" do
    test "get activities from API", %{conn: conn} do
      conn = post(conn, ~p"/api/here/browseRoute", @default_route_attrs)
      items = json_response(conn, 200)["data"]["items"]
      assert length(items) <= 5
      Process.sleep(1000)
    end

    test "get activities from API (No Cat)", %{conn: conn} do
      conn = post(conn, ~p"/api/here/browseRoute", @noCat_route_attrs)
      items = json_response(conn, 200)["data"]["items"]
      assert length(items) <= 5
      Process.sleep(1000)
    end

    test "get activities from API (No Limit)", %{conn: conn} do
      conn = post(conn, ~p"/api/here/browseRoute", @noLimit_route_attrs)
      items = json_response(conn, 200)["data"]["items"]
      assert length(items) <= 20
      Process.sleep(1000)
    end

    test "get activities from API (No Limit, No Cat)", %{conn: conn} do
      conn = post(conn, ~p"/api/here/browseRoute", @noCatNoLimit_route_attrs)
      items = json_response(conn, 200)["data"]["items"]
      assert length(items) <= 20
      Process.sleep(1000)
    end
  end

  @hereLookup %{
    id: "here:pds:place:250ezzx4-73bfc7341111d7b6e15308da8ccde4a7",
    name: "Bordeaux, Gironde, Nouvelle-Aquitaine, France métropolitaine, France"
  }

  describe "lookup" do
    test "get activity from API", %{conn: _} do
      map = %{
        "id" => @hereLookup.id,
        "name" => @hereLookup.name
      }

      look = HereController.lookup(map)
      assert look["id"] == @hereLookup.id
      Process.sleep(1000)
    end
  end
end
