defmodule ApiWeb.TeamJSON do
  alias Api.Teams.Team
  alias Api.Users.User

  def index(%{teams: teams, managers: managers}) do
    %{
      data:
        for(
          team <- teams,
          do:
            data(
              team,
              Enum.find(managers, fn manager -> manager.id == team.manager end)
            )
        )
    }
  end

  def index(%{teams: teams}) do
    %{data: for(team <- teams, do: data(team))}
  end

  def show(%{team: team}) do
    %{data: data(team)}
  end

  defp data(%Team{} = team, %User{} = manager) do
    %{
      id: team.id,
      name: team.name,
      manager: manager.username,
      manager_id: manager.id
    }
  end

  defp data(%Team{} = team) do
    %{
      id: team.id,
      name: team.name
    }
  end

  def error(%{error: error}) do
    %{
      error: error
    }
  end

  def success(%{success: success}) do
    %{
      success: success
    }
  end
end
