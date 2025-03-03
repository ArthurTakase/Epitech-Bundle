defmodule Api.Repo.Migrations.CreateSaves do
  use Ecto.Migration

  def change do
    create table(:saves) do
      add(:data, :text, null: false)
      add(:code, :string)
      add(:last_update, :utc_datetime)
      add(:user, references(:users, on_delete: :delete_all))

      timestamps(type: :utc_datetime)
    end

    create(index(:saves, [:user]))
  end
end
