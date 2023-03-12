class CreateReactions < ActiveRecord::Migration[7.0]
  def change
    create_table :reactions do |t|
      t.string :klass, null: false
      t.jsonb :options, null: false
      t.references :action, foreign_key: true

      t.timestamps
    end
  end
end
