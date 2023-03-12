class AddUserToAction < ActiveRecord::Migration[7.0]
  def change
    add_belongs_to :widgets, :user, foreign_key: true
  end
end
