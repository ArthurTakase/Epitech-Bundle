defmodule ApiWeb.SaveController do
  use ApiWeb, :controller
  use PhoenixSwagger
  alias ApiWeb.Swagger.SaveSwagger
  alias ApiWeb.HereController

  alias Api.Saves
  alias Api.Saves.Save

  action_fallback(ApiWeb.FallbackController)

  @unauthorized_message "Unauthorized"

  def index(conn, _params) do
    saves = Saves.list_saves()
    render(conn, :index, saves: saves)
  end

  def create(conn, %{"save" => save_params}) do
    user_id = ApiWeb.TokenController.get_token(conn)
    save_params = Map.put(save_params, "user", user_id)

    # Check if save_params["data"] is nil or not
    case save_params["data"] do
      nil ->
        conn
        |> put_status(:unprocessable_entity)
        |> render("error.json", %{error: "Data not provided"})

      data ->
        # check if data is a valid base64 string
        case Base.decode64(data) do
          {:ok, _} ->
            with {:ok, %Save{} = save} <- Saves.create_save(save_params) do
              conn
              |> put_status(:created)
              |> put_resp_header("location", ~p"/api/saves/#{save}")
              |> render(:show, save: save)
            end

          {:error, _} ->
            conn
            |> put_status(:unprocessable_entity)
            |> render("error.json", %{error: "Invalid base64 string"})
        end
    end
  end

  def show(conn, %{"id" => id}) do
    save = Saves.get_save!(id)
    render(conn, :show, save: save)
  end

  def get_by_code(conn, %{"code" => code}) do
    save = Saves.get_save_by_code!(code)

    save_data = Base.decode64!(save.data)
    save_data = Jason.decode!(save_data)
    extracted_data = Enum.map(save_data, fn x -> HereController.lookup(x) end)

    conn
    |> put_status(:ok)
    |> render(:extracted, save: save, edata: extracted_data)
  end

  def get_by_user(conn, %{"user" => user_id}) do
    saves = Saves.get_saves_by_user!(user_id)
    render(conn, :index, saves: saves)
  end

  def update(conn, %{"id" => id, "save" => save_params}) do
    save = Saves.get_save!(id)

    with {:ok, %Save{} = save} <- Saves.update_save(save, save_params) do
      render(conn, :show, save: save)
    end
  end

  def deleteSave(conn, %{"id" => id}) do
    user_id = ApiWeb.TokenController.get_token(conn)
    save = Saves.get_save!(id)

    if user_id != save.user do
      conn
      |> put_status(:unauthorized)
      |> render("error.json", %{error: @unauthorized_message})
    else
      with {:ok, %Save{}} <- Saves.delete_save(save) do
        send_resp(conn, :no_content, "")
      end
    end
  end

  # -----------------------------------
  # Swagger
  # -----------------------------------

  def swagger_definitions do
    SaveSwagger.swagger_definition()
  end

  swagger_path :create do
    post("/api/saves")
    produces("application/json")
    tag("Save")
    operation_id("create")
    description("Create a new save")

    parameter(:save, :body, Schema.ref(:SaveRequest), "Save", required: true)

    response(
      201,
      "Created",
      Schema.ref(:HereResponse),
      %{examples: SaveSwagger.swagger_path_create_response_201()}
    )

    response(400, "Bad Request")

    response(422, "Unprocessable Entity", Schema.ref(:ErrorResponse))

    response(500, "Internal Server Error")
  end

  swagger_path :index do
    get("/api/saves")
    produces("application/json")
    tag("Save")
    operation_id("index")
    description("Retrieve the list of saves")

    response(
      200,
      "OK",
      Schema.ref(:SavesResponse),
      %{examples: SaveSwagger.swagger_path_index_response_200()}
    )

    response(500, "Internal Server Error")
  end

  swagger_path :show do
    get("/api/saves/{id}")
    produces("application/json")
    tag("Save")
    operation_id("show")
    description("Retrieve a single save")

    parameter(:id, :path, :integer, "Save ID", required: true)

    response(200, "OK", Schema.ref(:SaveResponse))

    response(404, "Not Found")

    response(500, "Internal Server Error")
  end

  swagger_path :get_by_code do
    get("/api/saves/code/{code}")
    produces("application/json")
    tag("Save")
    operation_id("get_by_code")
    description("Retrieve a single save by code and decode its data")

    parameter(:code, :path, :string, "Save Code", required: true)

    response(200, "OK", Schema.ref(:SaveDataResponse))

    response(404, "Not Found")

    response(500, "Internal Server Error")
  end

  swagger_path :get_by_user do
    get("/api/saves/user/{user}")
    produces("application/json")
    tag("Save")
    operation_id("get_by_user")
    description("Retrieve a list of saves by user")

    parameter(:user, :path, :integer, "User ID", required: true)

    response(200, "OK", Schema.ref(:SavesResponse))

    response(404, "Not Found")

    response(500, "Internal Server Error")
  end

  swagger_path :update do
    put("/api/saves/{id}")
    produces("application/json")
    tag("Save")
    operation_id("update")
    description("Update a single save")

    parameter(:id, :path, :integer, "Save ID", required: true)
    parameter(:save, :body, Schema.ref(:SaveRequest), "Save", required: true)

    response(200, "OK", Schema.ref(:SaveResponse))

    response(400, "Bad Request")

    response(404, "Not Found")

    response(422, "Unprocessable Entity", Schema.ref(:ErrorResponse))

    response(500, "Internal Server Error")
  end

  swagger_path :deleteSave do
    delete("/api/saves/{id}")
    produces("application/json")
    tag("Save")
    operation_id("deleteSave")
    description("Delete a single save")

    parameter(:id, :path, :integer, "Save ID", required: true)

    response(204, "No Content")

    response(404, "Not Found")

    response(500, "Internal Server Error")
  end
end
