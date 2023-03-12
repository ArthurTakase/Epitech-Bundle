class AddCatsToUser < ActiveRecord::Migration[7.0]
  def change
    add_column :users, :cat, :jsonb
  end
end
