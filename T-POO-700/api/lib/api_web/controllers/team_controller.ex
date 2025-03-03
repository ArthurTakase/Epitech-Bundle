defmodule ApiWeb.TeamController do
  use ApiWeb, :controller

  alias Api.Teams
  alias Api.Teams.Team
  alias Api.Users
  alias Api.Users.User

  action_fallback(ApiWeb.FallbackController)

  def index(conn, _params) do
    teams = Teams.list_teams()

    managers_id =
      for team <- teams do
        team.manager
      end

    managers = Users.get_users_from_id_list(managers_id)
    render(conn, :index, teams: teams, managers: managers)
  end

  def create(conn, %{"team" => team_params}) do
    manager_email = team_params["manager_email"]
    user = Users.get_user_by_email(manager_email)

    if user == nil do
      conn
      |> put_status(:not_found)
      |> render("error.json", %{error: "user not found"})
    else
      team_params = Map.put(team_params, "manager", user.id)

      with {:ok, %Team{} = team} <- Teams.create_team(team_params) do
        Users.update_user(%User{} = user, %{teams: user.teams ++ [team.id]})

        conn
        |> put_status(:created)
        |> render("success.json", %{success: "team created"})
      end
    end
  end

  def add_user(conn, %{"id" => id, "email" => email}) do
    user = Users.get_user_by_email(email)
    already = Users.check_if_already_in_team(user, id)

    if user != nil and already == false do
      with {:ok, %User{} = _user} <-
             Users.update_user(%User{} = user, %{teams: user.teams ++ [id]}) do
        conn
        |> put_status(:created)
        |> render("success.json", %{success: "user added to team"})
      end
    else
      conn
      |> put_status(:not_found)
      |> render("error.json", %{error: "user not found"})
    end
  end

  def show(conn, %{"id" => id}) do
    team = Teams.get_team!(id)
    render(conn, :show, team: team)
  end

  def update(conn, %{"id" => id, "team" => team_params}) do
    team = Teams.get_team!(id)

    with {:ok, %Team{} = team} <- Teams.update_team(team, team_params) do
      render(conn, :show, team: team)
    end
  end

  def delete(conn, %{"id" => id}) do
    team = Teams.get_team!(id)

    with {:ok, %Team{}} <- Teams.delete_team(team) do
      send_resp(conn, :no_content, "")
    end
  end
end
