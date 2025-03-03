defmodule ApiWeb.Router do
  use ApiWeb, :router

  pipeline :browser do
    plug(:accepts, ["html", "json"])
    plug(:fetch_session)
    plug(:fetch_live_flash)
    plug(:put_root_layout, html: {ApiWeb.Layouts, :root})
    plug(:protect_from_forgery)
    plug(:put_secure_browser_headers)
  end

  pipeline :api do
    plug(:accepts, ["json"])
  end

  pipeline :authenticated do
    plug(ApiWeb.Plugs.Auth)
  end

  scope "/", ApiWeb do
    pipe_through(:browser)

    get("/", PageController, :home)
  end

  # Other scopes may use custom stacks.
  scope "/api", ApiWeb do
    pipe_through([:api, :authenticated])

    # USERS
    resources("/users", UserController, except: [:create, :new, :edit])
    get("/all_users", UserController, :all_users)
    get("/user", UserController, :get_from_token)
    get("/teams/:userID", UserController, :my_teams)
    # CLOCKS
    post("/clocks/:username", ClockController, :createOrUpdate)
    get("/clocks/:username", ClockController, :index)
    resources("/clocks", ClockController, only: [:update, :delete])
    # WORKINGTIMES
    resources("/workingtimes", WorkingtimeController, only: [:delete, :update])
    get("/workingtimes/:userID", WorkingtimeController, :index)
    get("/workingtimes/:userID/:id", WorkingtimeController, :show)
    post("/workingtimes/:userID", WorkingtimeController, :create)
    # TEAMS
    resources("/teams", TeamController, except: [:new, :edit])
    put("/user_teams/:id", TeamController, :add_user)
  end

  scope "/api", ApiWeb do
    pipe_through(:api)

    post("/users", UserController, :create)
    get("/ping", UserController, :ping)
  end

  # Other scopes may use custom stacks.
  scope "/auth", ApiWeb do
    post("/login", AuthController, :login)
  end
end
