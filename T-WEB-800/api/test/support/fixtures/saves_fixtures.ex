defmodule Api.SavesFixtures do
  @moduledoc """
  This module defines test helpers for creating
  entities via the `Api.Saves` context.
  """

  import Api.UsersFixtures

  @doc """
  Generate a save.
  """
  def save_fixture(attrs \\ %{}) do
    user = user_fixture()

    {:ok, save} =
      attrs
      |> Enum.into(%{
        data: "W10=",
        user: user.id
      })
      |> Api.Saves.create_save()

    save
  end

  def save_user_fixture(user_id, attrs \\ %{}) do
    {:ok, save} =
      attrs
      |> Enum.into(%{
        data: "W10=",
        user: user_id
      })
      |> Api.Saves.create_save()

    save
  end
end
