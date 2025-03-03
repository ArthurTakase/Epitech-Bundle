defmodule Api.Repo.Migrations.AddTeamsArray do
  use Ecto.Migration

  def change do
    # alter table users and add an array of int
    alter table(:users) do
      add(:teams, {:array, :integer})
    end
  end
end
