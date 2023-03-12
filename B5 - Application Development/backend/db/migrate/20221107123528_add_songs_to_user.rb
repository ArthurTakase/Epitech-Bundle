class AddSongsToUser < ActiveRecord::Migration[7.0]
  def change
    add_column :users, :songs, :jsonb, null: false
  end
end
