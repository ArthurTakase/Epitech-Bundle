defmodule ApiWeb.Swagger.LocationSwagger do
  alias ElixirSense.Plugins.Ecto.Schema
  use PhoenixSwagger

  @example %{
    addresstype: "city",
    boundingbox: [
      "44.8107826",
      "44.9161806",
      "-0.6386987",
      "-0.5336838"
    ],
    class: "boundary",
    display_name: "Bordeaux, Gironde, Nouvelle-Aquitaine, France métropolitaine, France",
    importance: 0.6740050666982947,
    lat: "44.841225",
    licence: "Data © OpenStreetMap contributors, ODbL 1.0. http://osm.org/copyright",
    lon: "-0.5800364",
    name: "Bordeaux",
    osm_id: 105_270,
    osm_type: "relation",
    place_id: 252_059_258,
    place_rank: 16,
    type: "administrative"
  }

  def swagger_definition() do
    %{
      Location:
        swagger_schema do
          title("Location")
          description("Location details")

          properties do
            addresstype(:string, "Address type")
            boundingbox(:array, "Bounding box")
            class(:string, "Class")
            display_name(:string, "Display name")
            importance(:float, "Importance")
            lat(:string, "Latitude")
            licence(:string, "Licence")
            lon(:string, "Longitude")
            name(:string, "Name")
            osm_id(:integer, "OSM ID")
            osm_type(:string, "OSM Type")
            place_id(:integer, "Place ID")
            place_rank(:integer, "Place rank")
            type(:string, "Type")
          end

          example(@example)
        end
    }
  end

  # -----------------------------------
  # Paths
  # -----------------------------------

  def swagger_path_index_response_200() do
    %{
      "application/json": %{
        data: [
          @example,
          @example
        ]
      }
    }
  end
end
