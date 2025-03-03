defmodule ApiWeb.UserJSON do
  alias Api.Users.User
  alias Api.Clocks.Clock

  def index(%{users: users, clocks: clocks}) do
    %{
      data:
        for(
          user <- users,
          do:
            data(
              user,
              Enum.find(clocks, fn clock -> clock.user == user.id end)
            )
        )
    }
  end

  def index(%{users: users}) do
    %{data: for(user <- users, do: data(user))}
  end

  def show(%{user: user}) do
    %{data: data(user)}
  end

  defp data(%User{} = user, %Clock{} = clock) do
    %{
      id: user.id,
      username: user.username,
      email: user.email,
      password: user.password,
      user_role: user.user_role,
      teams: user.teams,
      clock: clock.status
    }
  end

  defp data(%User{} = user, nil) do
    %{
      id: user.id,
      username: user.username,
      email: user.email,
      password: user.password,
      user_role: user.user_role,
      teams: user.teams,
      clock: nil
    }
  end

  defp data(%User{} = user) do
    %{
      id: user.id,
      username: user.username,
      email: user.email,
      password: user.password,
      user_role: user.user_role,
      teams: user.teams,
      clock: nil
    }
  end

  def error(%{error: error}) do
    %{
      error: error
    }
  end

  def ping(%{pong: pong}) do
    %{
      pong: pong
    }
  end
end
