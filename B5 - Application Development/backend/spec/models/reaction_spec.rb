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
require "rails_helper"

RSpec.describe Reaction, type: :model do
  context "create a reaction valid" do
    let(:id) { 509081 }
    subject { create(:reaction, id: id) }

    it "should persist an reaction" do
      expect { subject }.to change(Reaction, :count).by(1)
    end

    it "has an id in options on creation" do
      expect(subject.options["reaction_id"]).to eq(id)
    end

    it "has a klass valid" do
      reaction = subject.klass_command
      options = subject.options

      expect(reaction.constantize.send(:new, options)).to_not be_nil
    end
  end
end
