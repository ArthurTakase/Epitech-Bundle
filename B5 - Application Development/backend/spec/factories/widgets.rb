# == Schema Information
#
# Table name: widgets
#
#  id         :bigint           not null, primary key
#  active     :boolean          default(TRUE), not null
#  name       :string           not null
#  created_at :datetime         not null
#  updated_at :datetime         not null
#  user_id    :bigint
#
# Indexes
#
#  index_widgets_on_user_id  (user_id)
#
# Foreign Keys
#
#  fk_rails_...  (user_id => users.id)
#
FactoryBot.define do
  factory :widget do
    name { FFaker::Name.unique.name }
    user_id { create(:user).id }
    active { true }

    factory :widget_complet do
      action { create(:action) }
    end
  end
end
