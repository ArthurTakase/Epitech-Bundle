class AddPictureToUser < ActiveRecord::Migration[7.0]
  def change
    add_column :users, :picture, :string
  end
end
