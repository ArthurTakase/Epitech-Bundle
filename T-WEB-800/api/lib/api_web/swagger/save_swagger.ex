defmodule ApiWeb.Swagger.SaveSwagger do
  alias ElixirSense.Plugins.Ecto.Schema
  use PhoenixSwagger

  @example %{
    code: "ABCDEF123456789",
    data: "data",
    user: 123,
    last_update: "2021-01-01T00:00:00Z",
    id: 123
  }

  @exampleHere %{
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
      Save:
        swagger_schema do
          title("Save")
          description("Save travel details")

          properties do
            code(:string, "Code")
            data(:string, "Data", required: true)
            user(:id, "User ID", required: true)
            last_update(:utc_datetime, "Last update")
            id(:integer, "Save ID")
          end

          example(@example)
        end,
      SaveRequest:
        swagger_schema do
          title("SaveRequest")
          description("POST body for save")

          property(:data, :string, "Data (Baes64 array of object with id and name)",
            required: true
          )

          example(%{
            data: "data (Baes64 array of object with id and name)"
          })
        end,
      SaveResponse:
        swagger_schema do
          title("SaveResponse")
          description("Response schema for single save")
          property(:data, Schema.ref(:Save), "The save details")
        end,
      Here:
        swagger_schema do
          title("Here")
          description("Here API")

          example(@exampleHere)
        end,
      SaveDataResponse:
        swagger_schema do
          title("SaveDataResponse")
          description("Response schema for single save data")

          property(:data, Schema.array(:Here), "The decoded data (HERE API format)")

          property(:save, Schema.ref(:Save), "The save details")
        end,
      SavesResponse:
        swagger_schema do
          title("SavesResponse")
          description("Response schema for multiple saves")
          property(:data, [Schema.ref(:Save)], "The save details")
        end,
      ErrorResponse:
        swagger_schema do
          title("ErrorResponse")
          description("Response schema for errors")
          property(:error, :string, "Error message")
        end
    }
  end

  # -----------------------------------
  # Paths
  # -----------------------------------

  def example_save() do
    @example
  end

  def swagger_path_create_response_201() do
    %{
      "application/json": %{
        data: @example
      }
    }
  end

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
