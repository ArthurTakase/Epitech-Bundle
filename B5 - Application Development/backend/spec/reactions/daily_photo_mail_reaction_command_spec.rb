require "rails_helper"

RSpec.describe DailyPhotoMailReactionCommand do
  describe "#to_h" do
    let(:user) { create(:user) }
    let(:widget) { create(:widget, user_id: user.id) }
    let(:action) { create(:action, widget_id: widget.id) }
    let(:reaction) { create(:reaction, action_id: action.id) }
    let(:email) { "test@email.com" }
    let(:options) { { "reaction_id" => reaction.id, "email"=>email } }

    it "returns a valid hash" do
      command = DailyPhotoMailReactionCommand.new(options)

      expect(command.to_h).to eq({ reaction_id: reaction.id, email: email, user_id: user.id })
    end
  end
end
