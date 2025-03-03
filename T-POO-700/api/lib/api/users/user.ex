defmodule Api.Users.User do
  use Ecto.Schema
  import Ecto.Changeset

  schema "users" do
    field(:username, :string)
    field(:email, :string)
    field(:user_role, :integer, default: 1)
    # field(:user_role, Ecto.Enum, values: [user: 1, manager: 2, superManager: 3], default: :user)
    field(:password, :string)
    field(:teams, {:array, :integer}, default: [])

    timestamps(type: :utc_datetime)
  end

  @doc false
  def changeset(user, attrs) do
    user
    |> cast(attrs, [:username, :email, :user_role, :password, :teams])
    |> validate_required([:username, :email, :user_role, :password, :teams])
    |> validate_format(
      :email,
      ~r/^[A-Za-z0-9._-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,4}$/,
      message: "invalid email format"
    )
    |> unique_constraint(:email)
    |> unique_constraint(:username)
  end
end
