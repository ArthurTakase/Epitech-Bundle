require "rails_helper"

RSpec.describe SendMailReactionCommandHandler do
  describe "#send_mail" do
    let(:email) { "test@email.com" }
    let(:widget) { create(:widget, user_id: user.id) }
    let(:action) { create(:action, id: 1, widget_id: widget.id) }
    let(:reaction) { create(:reaction, id: 1, action_id: action.id) }

    context "when user have token" do
      let(:token) { FFaker::Internet.password }
      let(:user) { create(:user, email: email, google_token: token) }
      let(:options) {
        { "reaction_id"=>reaction.id, "token"=> token, "email"=> email, "receiver"=>email, "object"=>"Subject",
          "message"=>"Message" }
      }
      let(:gmail_service) { GmailClientTest.new(token, email) }

      it "has send a mail" do
        command = SendMailReactionCommand.new(options)
        handler = SendMailReactionCommandHandler.new
        expected_coded_mail = "RnJvbTogPHRlc3RAZW1haWwuY29tPgogIFRvOiA8dGVzdEBlbWFpbC5jb20-CiAgU3ViamVjdDogU3ViamVjdAogIENvbnRlbnQtdHlwZTogdGV4dC9odG1sO2NoYXJzZXQ9dXRmLTgKCiAgTWVzc2FnZQ=="

        expect { handler.call(command.to_h, gmail_service) }.to change(gmail_service, :send_mail_request).by(1)
        expect(gmail_service.last_mail).to eq(expected_coded_mail)
      end
    end

    context "when user does not have token" do
      let(:user) { create(:user, email: email, google_token: nil) }
      let(:options) {
        { "reaction_id"=>reaction.id, "token"=> nil, "email"=> email, "receiver"=>email, "object"=>"Subject",
          "message"=>"Message" }
      }
      let(:gmail_service) { GmailClientTest.new(nil, email) }

      it "raise an error" do
        command = SendMailReactionCommand.new(options)
        handler = SendMailReactionCommandHandler.new

        expect { handler.call(command.to_h, gmail_service) }.not_to change(gmail_service, :send_mail_request)
        expect(gmail_service.last_mail).to eq("")
      end
    end
  end
end
