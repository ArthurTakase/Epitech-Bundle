class CreateActions < ActiveRecord::Migration[7.0]
  def change
    create_table :actions do |t|
      t.string :klass, null: false
      t.jsonb :options, null: false
      t.references :widget, foreign_key: true

      t.timestamps
    end
  end
end
