class CreateWidgets < ActiveRecord::Migration[7.0]
  def change
    create_table :widgets do |t|
      t.string :name, null: false
      t.boolean :active, null: false, default: true

      t.timestamps
    end
  end
end
