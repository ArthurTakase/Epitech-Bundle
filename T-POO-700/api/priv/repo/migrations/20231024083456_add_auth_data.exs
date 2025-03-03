defmodule Api.Repo.Migrations.AddAuthData do
  use Ecto.Migration

  def change do
    alter table(:users) do
      add(:user_role, :integer, default: 1, null: false)
      add(:password, :string, null: false, default: "")
    end

    # Ajout d'une contrainte de vérification pour s'assurer que user_role est entre 1 et 3
    execute("ALTER TABLE users ADD CONSTRAINT check_user_role CHECK (user_role >= 1 AND user_role <= 3)")
  end
end
