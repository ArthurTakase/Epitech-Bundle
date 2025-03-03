defmodule Api.Teams.Team do
  use Ecto.Schema
  import Ecto.Changeset

  schema "teams" do
    field(:name, :string)
    field(:manager, :id)

    timestamps(type: :utc_datetime)
  end

  @doc false
  def changeset(team, attrs) do
    team
    |> cast(attrs, [:name, :manager])
    |> validate_required([:name, :manager])
  end
end
