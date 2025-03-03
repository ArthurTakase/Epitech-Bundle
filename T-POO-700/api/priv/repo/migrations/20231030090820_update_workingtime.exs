defmodule Api.Repo.Migrations.UpdateWorkingtime do
  use Ecto.Migration

  def change do
    # in the table workingtimes, edit the column end to be nullable
    alter table(:workingtimes) do
      modify(:end, :utc_datetime, null: true)
    end
  end
end
