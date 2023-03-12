class CreateUsers < ActiveRecord::Migration[7.0]
  def change
    create_table :users do |t|
      t.string :first_name, null: false
      t.string :last_name, null: false
      t.string :email, null: false
      t.string :background
      t.boolean :admin, null: false, default: false
      t.string :provider
      t.string :p_uid

      t.timestamps
    end
  end
end
