class AddTokensToUser < ActiveRecord::Migration[7.0]
  def change
    add_column :users, :spotify_token, :string
    add_column :users, :google_token, :string
    add_column :users, :twitter_token, :string
  end
end
