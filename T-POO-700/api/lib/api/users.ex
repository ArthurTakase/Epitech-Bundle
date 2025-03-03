defmodule Api.Users do
  @moduledoc """
  The Users context.
  """

  import Ecto.Query, warn: false
  alias Api.Repo
  alias Api.Users.User
  alias Api.Teams

  def list_users do
    Repo.all(User)
  end

  def get_user!(id) do
    Repo.get!(User, id)
  end

  def create_user(attrs \\ %{}) do
    password = attrs["password"]
    password = Base.encode16(:crypto.hash(:sha256, "#{password}HelloWorld"))

    %User{}
    |> User.changeset(attrs)
    |> User.changeset(%{password: password})
    |> Repo.insert()
  end

  def update_user(%User{} = user, attrs) do
    user
    |> User.changeset(attrs)
    |> Repo.update()
  end

  def delete_user(%User{} = user) do
    Repo.delete(user)
  end

  def change_user(%User{} = user, attrs \\ %{}) do
    User.changeset(user, attrs)
  end

  def get_user_by_username_and_email(username, email) do
    query =
      from(u in User,
        where: u.username == ^username and u.email == ^email,
        select: u
      )

    Repo.one(query)
  end

  def get_user_by_username_or_email(username, email) do
    query =
      from(u in User,
        where: u.username == ^username or u.email == ^email,
        select: u
      )

    Repo.one(query)
  end

  def get_user_by_mail_and_password(email, password) do
    password = Base.encode16(:crypto.hash(:sha256, "#{password}HelloWorld"))

    query =
      from(u in User,
        where: u.email == ^email and u.password == ^password,
        select: u
      )

    Repo.one(query)
  end

  def get_user_by_email(email) do
    query =
      from(u in User,
        where: u.email == ^email,
        select: u
      )

    Repo.one(query)
  end

  def get_user_by_username(username) do
    query =
      from(u in User,
        where: u.username == ^username,
        select: u
      )

    Repo.one(query)
  end

  def with_teams_in(team_ids) do
    from(u in User,
      where: fragment("? && ?::integer[]", u.teams, ^team_ids)
    )
  end

  def get_teams(id) do
    teams = Teams.get_teams_by_user_id(id)
    user = get_user!(id)

    team_ids = Enum.map(teams, fn team -> team.id end)
    team_ids = team_ids ++ user.teams

    with_teams_in(team_ids)
    |> Repo.all()
  end

  def check_if_already_in_team(user, team_id) do
    team_id = String.to_integer(team_id)

    Enum.member?(user.teams, team_id)
  end

  def get_users_from_id_list(ids) do
    query = from(u in User, where: u.id in ^ids, select: u)
    Repo.all(query)
  end
end
