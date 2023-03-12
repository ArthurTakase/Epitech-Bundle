require "rails_helper"

RSpec.describe EmailReceivedActionCommand do
  describe "#to_h" do
    let(:token) { FFaker::Internet.password }
    let(:email) { "test@email.com" }
    let(:user) { create(:user, email: email, google_token: token) }
    let(:widget) { create(:widget, user_id: user.id) }
    let(:action) { create(:action, id: 1, widget_id: widget.id) }

    context "when last_number_of_email_received is given" do
      let(:options) { { "action_id" => action.id, "last_number_of_email_received"=>"34" } }

      it "return a valid hash" do
        command = EmailReceivedActionCommand.new(options)
        expect(command.to_h).to eq({ action_id: action.id, last_number_of_email_received: "34", email: email,
                                     token: token })
      end
    end

    context "when last_number_of_email_received isn't given" do
      let(:options) { { "action_id" => action.id } }
      let(:gmail_service) { GmailClientTest.new(token, email, "55") }

      it "return a valid hash" do
        command = EmailReceivedActionCommand.new(options, gmail_service)
        expect(command.to_h).to eq({ action_id: action.id, last_number_of_email_received: "55", email: email,
                                     token: token })
      end
    end
  end
end
