defmodule ApiWeb.Swagger.HereSwagger do
  use PhoenixSwagger

  @example %{
    access: [
      %{
        lat: 50.09873,
        lng: 8.68743
      }
    ],
    address: %{
      city: "Frankfurt am Main",
      countryCode: "DEU",
      countryName: "Deutschland",
      county: "Frankfurt am Main",
      countyCode: "F",
      district: "Sachsenhausen",
      houseNumber: "50",
      label:
        "Hno-Praxis Dr. med. Jens Miklitza, Mörfelder Landstraße 50, 60598 Frankfurt am Main, Deutschland",
      postalCode: "60598",
      state: "Hessen",
      stateCode: "HE",
      street: "Mörfelder Landstraße"
    },
    categories: [
      %{
        id: "800-8000-0000",
        name: "Hospital or Health Care Facility",
        primary: true
      }
    ],
    distance: 16
  }

  def swagger_definition() do
    %{
      Here:
        swagger_schema do
          title("Here")
          description("Here API")

          example(@example)
        end,
      HereResponse:
        swagger_schema do
          title("HereResponse")
          description("Response schema for Here API")
          property(:data, Schema.array(:Here), "The Here details")
        end
    }
  end

  # -----------------------------------
  # Index
  # -----------------------------------

  def swagger_path_index_response_200() do
    %{
      "application/json": %{
        data: %{
          items: [
            @example
          ]
        }
      }
    }
  end
end
