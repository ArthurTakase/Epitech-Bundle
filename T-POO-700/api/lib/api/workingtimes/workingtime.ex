defmodule Api.Workingtimes.Workingtime do
  use Ecto.Schema
  import Ecto.Changeset

  schema "workingtimes" do
    field(:start, :utc_datetime)
    field(:end, :utc_datetime)
    field(:user, :id)
    field(:isFinished, :boolean, default: false)

    timestamps(type: :utc_datetime)
  end

  @doc false
  def changeset(workingtime, attrs) do
    workingtime
    |> cast(attrs, [:start, :end, :user, :isFinished])
    |> validate_required([:start, :end, :user, :isFinished])
  end
end
