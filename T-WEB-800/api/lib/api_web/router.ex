defmodule ApiWeb.Router do
  use ApiWeb, :router

  pipeline :apipipe do
    plug(:accepts, ["json"])
  end

  pipeline :authenticated do
    plug(ApiWeb.Plugs.Auth)
  end

  # Open API routes
  scope "/api", ApiWeb do
    pipe_through(:apipipe)

    resources("/users", UserController, only: [:index, :show, :create])
    get("/saves/code/:code", SaveController, :get_by_code)
    post("/here/browse", HereController, :browse)
    post("/here/browseIn", HereController, :browse_in)
    post("/here/browseRoute", HereController, :browse_route)

    post("/enjoy", ApiController, :enjoy)
    post("/sleep", ApiController, :sleep)
    post("/travel", ApiController, :travel)
    post("/eat", ApiController, :eat)
    post("/drink", ApiController, :drink)

    get("/location", LocationController, :getLocation)
    # add your routes here
  end

  scope "/api/swagger" do
    forward("/", PhoenixSwagger.Plug.SwaggerUI,
      otp_app: :api,
      swagger_file: "swagger.json"
    )
  end

  # Open Auth routes
  scope "/auth", ApiWeb do
    pipe_through(:apipipe)

    post("/login", AuthController, :login)
    post("/register", UserController, :create)
  end

  # Authenticated routes
  scope "/api", ApiWeb do
    pipe_through([:apipipe, :authenticated])

    get("/saves/user/:user", SaveController, :get_by_user)
    resources("/saves", SaveController, only: [:index, :show, :create, :update])
    delete("/saves/:id", SaveController, :deleteSave)
    delete("/users/:id", UserController, :deleteUser)
    resources("/users", UserController, only: [:update])
    # add your routes here
  end

  # Swagger
  def swagger_info do
    %{
      schemes: ["http", "https", "ws", "wss"],
      info: %{
        version: "1.0",
        title: "Epic Road Trip API",
        description: "API Documentation for the Epic Road Trip API",
        termsOfService: "Open for public",
        contact: %{
          name: "Arthur Decaen",
          email: "arthur.decaen@epitech.eu"
        }
      },
      securityDefinitions: %{
        Bearer: %{
          type: "apiKey",
          name: "Authorization",
          description: "API Token must be provided via `Authorization: Bearer ` header",
          in: "header"
        }
      },
      consumes: ["application/json"],
      produces: ["application/json"],
      tags: [
        %{name: "Users", description: "Manipulation des données relatives aux utilisateurs"},
        %{
          name: "Save",
          description: "Manipulation des données relatives aux sauvegardes des trajets"
        },
        %{
          name: "MyApi",
          description: "Routes demandées dans le sujet. Elles se servent des routes de Browse"
        },
        %{name: "Auth", description: "Route de Lgin"},
        %{name: "Browse", description: "Routes liées à l'API Here"},
        %{name: "Location", description: "Routes liées à l'API Nominatim OpenStreetMap"}
      ]
    }
  end
end
