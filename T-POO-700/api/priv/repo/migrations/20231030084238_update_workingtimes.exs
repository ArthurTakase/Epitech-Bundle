defmodule Api.Repo.Migrations.UpdateWorkingtimes do
  use Ecto.Migration

  def change do
    alter table(:workingtimes) do
      add(:isFinished, :boolean, default: false)
    end
  end
end
