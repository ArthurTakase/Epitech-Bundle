defmodule Api.UsersFixtures do
  @moduledoc """
  This module defines test helpers for creating
  entities via the `Api.Users` context.
  """

  @doc """
  Generate a user.
  """
  def user_fixture(attrs \\ %{}) do
    existing_user =
      Api.Users.get_user_by_username_or_email("some username", "mail@mail.com")

    if existing_user do
      existing_user
    else
      {:ok, user} =
        attrs
        |> Enum.into(%{
          email: "mail@mail.com",
          password: "P@ssw0rd",
          username: "some username"
        })
        |> Api.Users.create_user()

      user
    end
  end
end
