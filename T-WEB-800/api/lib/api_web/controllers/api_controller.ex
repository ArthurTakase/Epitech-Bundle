defmodule ApiWeb.ApiController do
  use ApiWeb, :controller
  use PhoenixSwagger
  alias ApiWeb.Swagger.ApiSwagger
  alias ApiWeb.HereController

  action_fallback(ApiWeb.FallbackController)

  @routeDesc "Route (for route, see https://github.com/heremaps/flexible-polyline)"

  # 200 - Going out-Entertainment
  # 300 - Sights and Museums
  def enjoy(conn, %{"lat" => _lat, "lon" => _lon} = params) do
    params = Map.put(params, "cat", "200,300")
    api_end(conn, params)
  end

  # 500 - Accommodations
  def sleep(conn, %{"lat" => _lat, "lon" => _lon} = params) do
    params = Map.put(params, "cat", "500")
    api_end(conn, params)
  end

  # 400 - Transport
  def travel(conn, %{"lat" => _lat, "lon" => _lon} = params) do
    params = Map.put(params, "cat", "400")
    api_end(conn, params)
  end

  # 1000 - Restaurant
  def eat(conn, %{"lat" => _lat, "lon" => _lon} = params) do
    params = Map.put(params, "cat", "100-1000")
    api_end(conn, params)
  end

  # 200-2000-0011 - Bar or Pub
  def drink(conn, %{"lat" => _lat, "lon" => _lon} = params) do
    params = Map.put(params, "cat", "200-2000-0011")
    api_end(conn, params)
  end

  defp api_end(conn, params) do
    if Map.has_key?(params, "west_lon") do
      HereController.browse_in(conn, params)
    else
      if Map.has_key?(params, "route") do
        HereController.browse_route(conn, params)
      else
        HereController.browse(conn, params)
      end
    end
  end

  # -----------------------------------
  # Swagger
  # -----------------------------------

  def swagger_definitions do
    ApiSwagger.swagger_definition()
  end

  swagger_path :enjoy do
    get("/api/enjoy")
    produces("application/json")
    tag("MyApi")
    operation_id("enjoy")
    description("List of existing events|activities")
    deprecated(false)

    parameter(:lat, :query, :float, "Latitude", required: true)
    parameter(:lon, :query, :float, "Longitude", required: true)
    parameter(:west_lon, :query, :float, "West Longitude (for bounding box)")
    parameter(:south_lat, :query, :float, "South Latitude (for bounding box)")
    parameter(:east_lon, :query, :float, "East Longitude (for bounding box)")
    parameter(:north_lat, :query, :float, "North Latitude (for bounding box)")
    parameter(:route, :query, :string, @routeDesc)

    response(200, "OK", Schema.ref(:ApiResponse), %{
      examples: ApiSwagger.swagger_path_index_response_200()
    })

    response(500, "Internal Server Error")
  end

  swagger_path :sleep do
    get("/api/sleep")
    produces("application/json")
    tag("MyApi")
    operation_id("sleep")
    description("List of available accommodations")
    deprecated(false)

    parameter(:lat, :query, :float, "Latitude", required: true)
    parameter(:lon, :query, :float, "Longitude", required: true)
    parameter(:west_lon, :query, :float, "West Longitude (for bounding box)")
    parameter(:south_lat, :query, :float, "South Latitude (for bounding box)")
    parameter(:east_lon, :query, :float, "East Longitude (for bounding box)")
    parameter(:north_lat, :query, :float, "North Latitude (for bounding box)")
    parameter(:route, :query, :string, @routeDesc)

    response(200, "OK", Schema.ref(:ApiResponse), %{
      examples: ApiSwagger.swagger_path_index_response_200()
    })

    response(500, "Internal Server Error")
  end

  swagger_path :travel do
    get("/api/travel")
    produces("application/json")
    tag("MyApi")
    operation_id("trvael")
    description("List of available transports")
    deprecated(false)

    parameter(:lat, :query, :float, "Latitude", required: true)
    parameter(:lon, :query, :float, "Longitude", required: true)
    parameter(:west_lon, :query, :float, "West Longitude (for bounding box)")
    parameter(:south_lat, :query, :float, "South Latitude (for bounding box)")
    parameter(:east_lon, :query, :float, "East Longitude (for bounding box)")
    parameter(:north_lat, :query, :float, "North Latitude (for bounding box)")
    parameter(:route, :query, :string, @routeDesc)

    response(200, "OK", Schema.ref(:ApiResponse), %{
      examples: ApiSwagger.swagger_path_index_response_200()
    })

    response(500, "Internal Server Error")
  end

  swagger_path :eat do
    get("/api/eat")
    produces("application/json")
    tag("MyApi")
    operation_id("eat")
    description("List of available restaurants")
    deprecated(false)

    parameter(:lat, :query, :float, "Latitude", required: true)
    parameter(:lon, :query, :float, "Longitude", required: true)
    parameter(:west_lon, :query, :float, "West Longitude (for bounding box)")
    parameter(:south_lat, :query, :float, "South Latitude (for bounding box)")
    parameter(:east_lon, :query, :float, "East Longitude (for bounding box)")
    parameter(:north_lat, :query, :float, "North Latitude (for bounding box)")
    parameter(:route, :query, :string, @routeDesc)

    response(200, "OK", Schema.ref(:ApiResponse), %{
      examples: ApiSwagger.swagger_path_index_response_200()
    })

    response(500, "Internal Server Error")
  end

  swagger_path :drink do
    get("/api/drink")
    produces("application/json")
    tag("MyApi")
    operation_id("drink")
    description("List of available bars")
    deprecated(false)

    parameter(:lat, :query, :float, "Latitude", required: true)
    parameter(:lon, :query, :float, "Longitude", required: true)
    parameter(:west_lon, :query, :float, "West Longitude (for bounding box)")
    parameter(:south_lat, :query, :float, "South Latitude (for bounding box)")
    parameter(:east_lon, :query, :float, "East Longitude (for bounding box)")
    parameter(:north_lat, :query, :float, "North Latitude (for bounding box)")
    parameter(:route, :query, :string, @routeDesc)

    response(200, "OK", Schema.ref(:ApiResponse), %{
      examples: ApiSwagger.swagger_path_index_response_200()
    })

    response(500, "Internal Server Error")
  end
end
