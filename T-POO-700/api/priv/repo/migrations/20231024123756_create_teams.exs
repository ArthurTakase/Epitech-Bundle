defmodule Api.Repo.Migrations.CreateTeams do
  use Ecto.Migration

  def change do
    create table(:teams) do
      add :name, :string
      add :manager, references(:users, on_delete: :nothing)

      timestamps(type: :utc_datetime)
    end

    create index(:teams, [:manager])
  end
end
