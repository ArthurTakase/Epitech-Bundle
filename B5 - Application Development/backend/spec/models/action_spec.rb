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
require "rails_helper"

RSpec.describe Action, type: :model do
  context "create a action valid" do
    let(:id) { 509081 }
    subject { create(:action, id: id) }

    it "should persist an action" do
      expect { subject }.to change(Action, :count).by(1)
    end

    it "has an id in options on creation" do
      expect(subject.options["action_id"]).to eq(id)
    end

    it "has an association to an reaction" do
      expect(subject).to respond_to(:reaction)
    end

    it "has a klass valid" do
      action = subject.klass_command
      options = subject.options

      expect(action.constantize.send(:new, options)).to_not be_nil
    end
  end
end
