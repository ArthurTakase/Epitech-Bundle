defmodule ApiWeb.HereController do
  use ApiWeb, :controller
  use PhoenixSwagger
  alias ApiWeb.Swagger.HereSwagger

  action_fallback(ApiWeb.FallbackController)

  @api_root "https://browse.search.hereapi.com/v1/browse?apiKey=#{System.get_env("HERE_API_KEY")}&lang=fr-FR"
  @api_lookup_root "https://lookup.search.hereapi.com/v1/lookup?apiKey=#{System.get_env("HERE_API_KEY")}&lang=fr-FR"

  def browse(conn, %{"lat" => lat, "lon" => lon} = params) do
    cat = Map.get(params, "cat", "")
    limit = Map.get(params, "limit", 20)
    cat_query = if cat != "", do: "&categories=#{cat}", else: ""
    req = get_browse(lat, lon, cat, limit, cat_query)

    conn
    |> put_status(:ok)
    |> render("show.json", data: req)
  end

  defp get_browse(lat, lon, cat, limit, cat_query) do
    key = "browse_#{lat}_#{lon}_#{cat}_#{limit}"
    cached = Cachex.get!(Api.Cache, key)

    case cached do
      nil ->
        url = @api_root <> "&at=#{lat},#{lon}#{cat_query}&limit=#{limit}"
        response = HTTPoison.get!(url)
        req = Jason.decode!(response.body)

        if response.status_code == 200 do
          Cachex.put(Api.Cache, key, req)
          Cachex.expire(Api.Cache, key, :timer.hours(72))
        end

        req

      _ ->
        cached
    end
  end

  def browse_in(
        conn,
        %{
          "lat" => _lat,
          "lon" => _lon,
          "west_lon" => _west_lon,
          "south_lat" => _south_lat,
          "east_lon" => _east_lon,
          "north_lat" => _north_lat
        } = params
      ) do
    cat = Map.get(params, "cat", "")
    limit = Map.get(params, "limit", 20)
    cat_query = if cat != "", do: "&categories=#{cat}", else: ""
    req = get_browse_in(params, cat, limit, cat_query)

    conn
    |> put_status(:ok)
    |> render("show.json", data: req)
  end

  defp get_browse_in(params, cat, limit, cat_query) do
    lat = Map.get(params, "lat")
    lon = Map.get(params, "lon")
    west_lon = Map.get(params, "west_lon")
    south_lat = Map.get(params, "south_lat")
    east_lon = Map.get(params, "east_lon")
    north_lat = Map.get(params, "north_lat")

    key =
      "browse_in_#{lat}_#{lon}_#{west_lon}_#{south_lat}_#{east_lon}_#{north_lat}_#{cat}_#{limit}"

    cached = Cachex.get!(Api.Cache, key)

    case cached do
      nil ->
        url =
          @api_root <>
            "&at=#{lat},#{lon}#{cat_query}&in=bbox:#{west_lon},#{south_lat},#{east_lon},#{north_lat}&limit=#{limit}"

        response = HTTPoison.get!(url)
        req = Jason.decode!(response.body)

        if response.status_code == 200 do
          Cachex.put(Api.Cache, key, req)
          Cachex.expire(Api.Cache, key, :timer.hours(72))
        end

        req

      _ ->
        cached
    end
  end

  def browse_route(
        conn,
        %{
          "lat" => lat,
          "lon" => lon,
          "route" => route
        } = params
      ) do
    cat = Map.get(params, "cat", "")
    limit = Map.get(params, "limit", 20)
    cat_query = if cat != "", do: "&categories=#{cat}", else: ""
    req = get_browse_route(lat, lon, route, cat, limit, cat_query)

    conn
    |> put_status(:ok)
    |> render("show.json", data: req)
  end

  def lookup(params) do
    id = Map.get(params, "id")
    url = @api_lookup_root <> "&id=#{id}"

    cache_key = "lookup_#{id}"
    cached = Cachex.get!(Api.Cache, cache_key)

    case cached do
      nil ->
        response = HTTPoison.get!(url)
        req = Jason.decode!(response.body)

        if response.status_code == 200 do
          Cachex.put(Api.Cache, cache_key, req)
          Cachex.expire(Api.Cache, cache_key, :timer.hours(72))
        end

        req

      _ ->
        cached
    end
  end

  defp get_browse_route(lat, lon, route, cat, limit, cat_query) do
    key = "browse_route_#{lat}_#{lon}_#{route}_#{cat}_#{limit}"
    cached = Cachex.get!(Api.Cache, key)

    case cached do
      nil ->
        url = @api_root <> "&at=#{lat},#{lon}#{cat_query}&route=#{route}&limit=#{limit}"
        response = HTTPoison.get!(url)
        req = Jason.decode!(response.body)

        if response.status_code == 200 do
          Cachex.put(Api.Cache, key, req)
          Cachex.expire(Api.Cache, key, :timer.hours(72))
        end

        req

      _ ->
        cached
    end
  end

  # -----------------------------------
  # Swagger
  # -----------------------------------

  def swagger_definitions do
    HereSwagger.swagger_definition()
  end

  swagger_path :browse do
    get("/api/browse")
    produces("application/json")
    tag("Browse")
    operation_id("browse")
    description("Get events around a location")
    deprecated(false)

    parameter(:lat, :query, :float, "Latitude", required: true)
    parameter(:lon, :query, :float, "Longitude", required: true)

    parameter(
      :cat,
      :query,
      :string,
      "Category (see https://www.here.com/docs/bundle/geocoding-and-search-api-developer-guide/page/topics-places/places-category-system-full.html)"
    )

    parameter(:limit, :query, :int, "Limit (default 20)")

    response(200, "OK", Schema.ref(:HereResponse), %{
      examples: HereSwagger.swagger_path_index_response_200()
    })

    response(500, "Internal Server Error")
  end

  swagger_path :browse_in do
    get("/api/browse_in")
    produces("application/json")
    tag("Browse")
    operation_id("browse_in")
    description("Get events in a bounding box")
    deprecated(false)

    parameter(:lat, :query, :float, "Latitude", required: true)
    parameter(:lon, :query, :float, "Longitude", required: true)
    parameter(:west_lon, :query, :float, "West Longitude", required: true)
    parameter(:south_lat, :query, :float, "South Latitude", required: true)
    parameter(:east_lon, :query, :float, "East Longitude", required: true)
    parameter(:north_lat, :query, :float, "North Latitude", required: true)

    parameter(
      :cat,
      :query,
      :string,
      "Category (see https://www.here.com/docs/bundle/geocoding-and-search-api-developer-guide/page/topics-places/places-category-system-full.html)"
    )

    parameter(:limit, :query, :int, "Limit (default 20)")

    response(200, "OK", Schema.ref(:HereResponse), %{
      examples: HereSwagger.swagger_path_index_response_200()
    })

    response(500, "Internal Server Error")
  end

  swagger_path :browse_route do
    get("/api/browse_route")
    produces("application/json")
    tag("Browse")
    operation_id("browse_route")
    description("Get events along a route")
    deprecated(false)

    parameter(:lat, :query, :float, "Latitude", required: true)
    parameter(:lon, :query, :float, "Longitude", required: true)

    parameter(
      :route,
      :query,
      :string,
      "Route (see https://github.com/heremaps/flexible-polyline)",
      required: true
    )

    parameter(
      :cat,
      :query,
      :string,
      "Category (see https://www.here.com/docs/bundle/geocoding-and-search-api-developer-guide/page/topics-places/places-category-system-full.html)"
    )

    parameter(:limit, :query, :int, "Limit (default 20)")

    response(200, "OK", Schema.ref(:HereResponse), %{
      examples: HereSwagger.swagger_path_index_response_200()
    })

    response(500, "Internal Server Error")
  end
end
