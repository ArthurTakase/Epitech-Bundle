defmodule ApiWeb.ClockController do
  use ApiWeb, :controller

  alias Api.Clocks
  alias Api.Clocks.Clock
  alias Api.Workingtimes
  alias Api.Users

  action_fallback(ApiWeb.FallbackController)

  def index(conn, %{"username" => username}) do
    user = Users.get_user_by_username(username)
    id = user.id
    clock = Clocks.get_clock_by_user_id(id)

    if clock == nil do
      current_time = DateTime.utc_now()
      clock_params = %{"status" => false, "user" => id, "time" => current_time}

      with {:ok, %Clock{} = clock} <- Clocks.create_clock(clock_params) do
        conn
        |> put_status(:created)
        |> put_resp_header("location", ~p"/api/clocks/#{clock}")
        |> render(:show, clock: clock)
      end
    else
      render(conn, :show, clock: clock)
    end
  end

  def create(conn, %{"userID" => userID, "clock" => clock_params}) do
    clock_params = Map.put(clock_params, "user", userID)

    with {:ok, %Clock{} = clock} <- Clocks.create_clock(clock_params) do
      conn
      |> put_status(:created)
      |> put_resp_header("location", ~p"/api/clocks/#{clock}")
      |> render(:show, clock: clock)
    end
  end

  def createOrUpdate(conn, %{"username" => username}) do
    user = Users.get_user_by_username(username)
    userID = user.id
    current_time = DateTime.utc_now()
    clock = Clocks.get_clock_by_user_id(userID)

    if clock == nil do
      clock_params = %{"status" => true, "user" => userID, "time" => current_time}

      with {:ok, %Clock{} = clock} <- Clocks.create_clock(clock_params) do
        conn
        |> put_status(:created)
        |> put_resp_header("location", ~p"/api/clocks/#{clock}")
        |> render(:show, clock: clock)
      end
    else
      new_status = not clock.status
      clock = Clocks.get_clock!(clock.id)
      clock_params = %{"status" => new_status, "time" => current_time}
      start = clock.time

      with {:ok, %Clock{} = clock} <- Clocks.update_clock(clock, clock_params) do
        if new_status == false do
          Workingtimes.create_workingtime(%{
            "start" => start,
            "end" => DateTime.utc_now(),
            "user" => userID
          })
        end

        render(conn, :show, clock: clock)
      end
    end
  end

  def update(conn, %{"id" => id, "clock" => clock_params}) do
    clock = Clocks.get_clock!(id)

    with {:ok, %Clock{} = clock} <- Clocks.update_clock(clock, clock_params) do
      render(conn, :show, clock: clock)
    end
  end

  def delete(conn, %{"id" => id}) do
    clock = Clocks.get_clock!(id)

    with {:ok, %Clock{}} <- Clocks.delete_clock(clock) do
      send_resp(conn, :no_content, "")
    end
  end
end
