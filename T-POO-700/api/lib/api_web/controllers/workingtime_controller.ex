defmodule ApiWeb.WorkingtimeController do
  use ApiWeb, :controller

  alias Api.Workingtimes
  alias Api.Workingtimes.Workingtime

  action_fallback(ApiWeb.FallbackController)

  def index(conn, %{"userID" => user, "start" => startDate, "end" => endDate}) do
    workingtimes = Workingtimes.get_all_workingtimes_between(user, startDate, endDate)
    render(conn, :index, workingtimes: workingtimes)
  end

  def create(conn, %{"userID" => user, "workingtime" => workingtime_params}) do
    workingtime_params = Map.put(workingtime_params, "user", user)

    with {:ok, %Workingtime{} = workingtime} <-
           Workingtimes.create_workingtime(workingtime_params) do
      conn
      |> put_status(:created)
      |> put_resp_header("location", ~p"/api/workingtimes/#{workingtime}")
      |> render(:show, workingtime: workingtime)
    end
  end

  def show(conn, %{"userID" => user, "id" => id}) do
    workingtime = Workingtimes.get_user_workingtime!(user, id)
    render(conn, :show, workingtime: workingtime)
  end

  def update(conn, %{"id" => id, "workingtime" => workingtime_params}) do
    workingtime = Workingtimes.get_workingtime!(id)

    with {:ok, %Workingtime{} = workingtime} <-
           Workingtimes.update_workingtime(workingtime, workingtime_params) do
      render(conn, :show, workingtime: workingtime)
    end
  end

  def delete(conn, %{"id" => id}) do
    workingtime = Workingtimes.get_workingtime!(id)

    with {:ok, %Workingtime{}} <- Workingtimes.delete_workingtime(workingtime) do
      send_resp(conn, :no_content, "")
    end
  end
end
