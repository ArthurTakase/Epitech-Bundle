# == Schema Information
#
# Table name: reactions
#
#  id         :bigint           not null, primary key
#  klass      :string           not null
#  options    :jsonb            not null
#  created_at :datetime         not null
#  updated_at :datetime         not null
#  action_id  :bigint
#
# Indexes
#
#  index_reactions_on_action_id  (action_id)
#
# Foreign Keys
#
#  fk_rails_...  (action_id => actions.id)
#
FactoryBot.define do
  factory :reaction do
    klass { "daily_photo_bg" }
    options { {} }
    action_id { create(:action).id }
  end
end
