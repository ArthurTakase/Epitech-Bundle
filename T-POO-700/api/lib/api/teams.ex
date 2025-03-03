defmodule Api.Teams do
  @moduledoc """
  The Teams context.
  """

  import Ecto.Query, warn: false
  alias Api.Repo

  alias Api.Teams.Team

  def list_teams do
    Repo.all(Team)
  end

  def get_team!(id), do: Repo.get!(Team, id)

  def create_team(attrs \\ %{}) do
    %Team{}
    |> Team.changeset(attrs)
    |> Repo.insert()
  end

  def update_team(%Team{} = team, attrs) do
    team
    |> Team.changeset(attrs)
    |> Repo.update()
  end

  def delete_team(%Team{} = team) do
    Repo.delete(team)
  end

  def change_team(%Team{} = team, attrs \\ %{}) do
    Team.changeset(team, attrs)
  end

  def get_teams_by_user_id(user_id) do
    query =
      from(t in Team,
        where: t.manager == ^user_id,
        select: t
      )

    Repo.all(query)
  end

  def get_team_by_name(name) do
    query =
      from(t in Team,
        where: t.name == ^name,
        select: t
      )

    Repo.all(query)
  end

  def remove_where_manager(userId) do
    query =
      from(t in Team,
        where: t.manager == ^userId,
        select: t
      )

    Repo.delete_all(query)
  end
end
