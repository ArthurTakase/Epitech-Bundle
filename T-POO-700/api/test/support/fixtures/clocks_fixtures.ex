defmodule Api.ClocksFixtures do
  @moduledoc """
  This module defines test helpers for creating
  entities via the `Api.Clocks` context.
  """

  @doc """
  Generate a clock.
  """
  def clock_fixture(attrs \\ %{}) do
    {:ok, clock} =
      attrs
      |> Enum.into(%{
        status: true,
        time: ~U[2023-10-22 19:19:00Z]
      })
      |> Api.Clocks.create_clock()

    clock
  end
end
