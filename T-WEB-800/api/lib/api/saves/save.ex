defmodule Api.Saves.Save do
  use Ecto.Schema
  import Ecto.Changeset

  schema "saves" do
    field(:code, :string)
    field(:data, :string)
    field(:last_update, :utc_datetime)
    field(:user, :id)

    timestamps(type: :utc_datetime)
  end

  @doc false
  def changeset(save, attrs) do
    save
    |> cast(attrs, [:data, :user])
    |> validate_required([:data, :user])
    |> put_last_update()
    |> put_code()
  end

  defp put_last_update(changeset) do
    date = DateTime.truncate(DateTime.utc_now(), :second)
    put_change(changeset, :last_update, date)
  end

  defp put_code(changeset) do
    if get_field(changeset, :code) != nil do
      changeset
    else
      put_change(
        changeset,
        :code,
        generate_code()
      )
    end
  end

  defp generate_code() do
    clean64 = :crypto.strong_rand_bytes(50) |> Base.encode64()
    up = String.upcase(clean64)
    up = String.replace(up, ~r/[^A-Z0-9]/, "")
    String.slice(up, 0..15)
  end
end
