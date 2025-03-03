defmodule Api.Clocks.Clock do
  use Ecto.Schema
  import Ecto.Changeset

  schema "clocks" do
    field(:status, :boolean, default: false)
    field(:time, :utc_datetime)
    field(:user, :id)

    timestamps(type: :utc_datetime)
  end

  @doc false
  def changeset(clock, attrs) do
    clock
    |> cast(attrs, [:time, :status, :user])
    |> validate_required([:time, :status, :user])
  end
end
