defmodule Api.Repo.Migrations.CreateClocks do
  use Ecto.Migration

  def change do
    create table(:clocks) do
      add(:time, :utc_datetime, null: false)
      add(:status, :boolean, default: false, null: false)
      add(:user, references(:users, on_delete: :nothing), null: false)

      timestamps(type: :utc_datetime)
    end

    create(index(:clocks, [:user]))
  end
end
