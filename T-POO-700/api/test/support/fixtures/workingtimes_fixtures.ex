defmodule Api.WorkingtimesFixtures do
  @moduledoc """
  This module defines test helpers for creating
  entities via the `Api.Workingtimes` context.
  """

  @doc """
  Generate a workingtime.
  """
  def workingtime_fixture(attrs \\ %{}) do
    {:ok, workingtime} =
      attrs
      |> Enum.into(%{
        end: ~U[2023-10-22 19:18:00Z],
        start: ~U[2023-10-22 19:18:00Z]
      })
      |> Api.Workingtimes.create_workingtime()

    workingtime
  end
end
