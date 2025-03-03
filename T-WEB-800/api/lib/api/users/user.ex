defmodule Api.Users.User do
  use Ecto.Schema
  import Ecto.Changeset

  schema "users" do
    field(:username, :string)
    field(:password, :string)
    field(:email, :string)

    timestamps(type: :utc_datetime)
  end

  @doc false
  def changeset(user, attrs) do
    user
    |> cast(attrs, [:username, :email, :password])
    |> validate_required([:username, :email, :password])
    |> validate_format(
      :email,
      ~r/^[A-Za-z0-9._-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,4}$/,
      message: "invalid email format"
    )
    |> validate_format(
      :password,
      ~r/^(?=.*[A-Z])(?=.*\d)(?=.*\W).{6,}$/,
      message:
        "password must contain at least 6 characters, 1 uppercase letter, 1 number and 1 special character"
    )
    |> unique_constraint(:email, message: "email already exists")
    |> unique_constraint(:username, message: "username already exists")
    |> put_pass_hash()
  end

  defp put_pass_hash(changeset) do
    case changeset do
      %Ecto.Changeset{valid?: true, changes: %{password: password}} ->
        put_change(
          changeset,
          :password,
          Base.encode16(:crypto.hash(:sha256, "#{password}HelloWorld"))
        )

      _ ->
        changeset
    end
  end
end
