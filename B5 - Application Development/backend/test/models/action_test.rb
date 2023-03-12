# == Schema Information
#
# Table name: actions
#
#  id         :bigint           not null, primary key
#  klass      :string           not null
#  options    :jsonb            not null
#  created_at :datetime         not null
#  updated_at :datetime         not null
#  widget_id  :bigint
#
# Indexes
#
#  index_actions_on_widget_id  (widget_id)
#
# Foreign Keys
#
#  fk_rails_...  (widget_id => widgets.id)
#
require "test_helper"

class ActionTest < ActiveSupport::TestCase
  # test "the truth" do
  #   assert true
  # end
end
