require "rails_helper"

RSpec.describe SendMailReactionCommand do
  describe "#to_h" do
    let(:token) { FFaker::Internet.password }
    let(:email) { "test@email.com" }
    let(:user) { create(:user, email: email, google_token: token) }
    let(:widget) { create(:widget, user_id: user.id) }
    let(:action) { create(:action, id: 1, widget_id: widget.id) }
    let(:reaction) { create(:reaction, id: 1, action_id: action.id) }

    let(:options) {
      { "reaction_id"=>reaction.id, "token"=> token, "email"=> email, "receiver"=>email, "object"=>"Subject",
        "message"=>"Message" }
    }

    it "return a valid hash" do
      command = SendMailReactionCommand.new(options)

      expect(command.to_h).to eq({ reaction_id: reaction.id, token: token, email: email, to: email, subject: "Subject",
                                   body: "Message" })
    end
  end
end
