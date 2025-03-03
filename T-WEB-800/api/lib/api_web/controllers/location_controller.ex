defmodule ApiWeb.LocationController do
  use PhoenixSwagger
  use ApiWeb, :controller
  alias ApiWeb.Swagger.LocationSwagger

  action_fallback(ApiWeb.FallbackController)

  def getLocation(conn, %{"city" => city}) do
    req = get_location_query(city)

    conn
    |> put_status(:ok)
    |> render("show.json", data: req)
  end

  defp get_location_query(city) do
    key = "location_#{city}"
    cached = Cachex.get!(Api.Cache, key)

    case cached do
      nil ->
        city = URI.encode_www_form(city)

        url =
          "https://nominatim.openstreetmap.org/search?q=#{city}&format=json&limit=1"

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
    LocationSwagger.swagger_definition()
  end

  swagger_path :getLocation do
    get("/api/location")
    summary("Get location details")
    description("Get location details for a city")
    tag("Location")
    deprecated(false)

    parameter(:query, "city", :string, "City name/Address", required: true)

    response(200, "Successful response", Schema.array(:Location))
  end
end
