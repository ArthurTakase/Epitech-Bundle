defmodule Api.Repo.Migrations.CreateUsers do
  use Ecto.Migration

  def change do
    create table(:users) do
      add(:username, :string, null: false, unique: true)
      add(:email, :string, null: false, unique: true)

      timestamps(type: :utc_datetime)
    end
  end
end
