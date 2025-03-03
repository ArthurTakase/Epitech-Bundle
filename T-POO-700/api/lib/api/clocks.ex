defmodule Api.Clocks do
  @moduledoc """
  The Clocks context.
  """

  import Ecto.Query, warn: false
  alias Api.Repo

  alias Api.Clocks.Clock

  def list_clocks do
    Repo.all(Clock)
  end

  def get_clock!(id), do: Repo.get!(Clock, id)

  def create_clock(attrs \\ %{}) do
    %Clock{}
    |> Clock.changeset(attrs)
    |> Repo.insert()
  end

  def update_clock(%Clock{} = clock, attrs) do
    clock
    |> Clock.changeset(attrs)
    |> Repo.update()
  end

  def delete_clock(%Clock{} = clock) do
    Repo.delete(clock)
  end

  def delete_clock_by_user_id(user_id) do
    Repo.delete_all(from(c in Clock, where: c.user == ^user_id))
  end

  def change_clock(%Clock{} = clock, attrs \\ %{}) do
    Clock.changeset(clock, attrs)
  end

  def get_clock_by_user_id(user_id) do
    Repo.one(from(c in Clock, where: c.user == ^user_id))
  end
end
