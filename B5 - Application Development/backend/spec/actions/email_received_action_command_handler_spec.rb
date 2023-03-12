require "rails_helper"

RSpec.describe EmailReceivedActionCommandHandler do
  describe "#email_received" do
    let(:email) { "test@email.com" }
    let(:current_nb_mail) { 34 }
    let(:widget) { create(:widget, user_id: user.id) }
    let(:action) { create(:action, id: 1, widget_id: widget.id) }

    context "when user have token" do
      let(:token) { FFaker::Internet.password }
      let(:user) { create(:user, email: email, google_token: token) }

      context "when a new email is received" do
        let(:options) { { "action_id" => action.id, "last_number_of_email_received"=>(current_nb_mail).to_s } }
        let(:gmail_service) { GmailClientTest.new(token, email, (current_nb_mail+1).to_s) }

        it "returns true" do
          command = EmailReceivedActionCommand.new(options, gmail_service)
          handler = EmailReceivedActionCommandHandler.new

          expect(handler.call(command.to_h, gmail_service)).to eq(true)
        end
      end

      context "when there is no new email" do
        let(:options) { { "action_id" => action.id, "last_number_of_email_received"=>(current_nb_mail).to_s } }
        let(:gmail_service) { GmailClientTest.new(token, email, current_nb_mail.to_s) }

        it "returns false" do
          command = EmailReceivedActionCommand.new(options, gmail_service)
          handler = EmailReceivedActionCommandHandler.new

          expect(handler.call(command.to_h, gmail_service)).to eq(false)
        end
      end
    end

    context "when user does not have token" do
      let(:token) { nil }
      let(:user) { create(:user, email: email, google_token: nil) }

      context "when a new email is received" do
        let(:options) { { "action_id" => action.id, "last_number_of_email_received"=>(current_nb_mail).to_s } }
        let(:gmail_service) { GmailClientTest.new(token, email, (current_nb_mail+1).to_s) }

        it "returns false" do
          command = EmailReceivedActionCommand.new(options, gmail_service)
          handler = EmailReceivedActionCommandHandler.new

          expect(handler.call(command.to_h, gmail_service)).to eq(false)
        end
      end

      context "when there is no new email" do
        let(:options) { { "action_id" => action.id, "last_number_of_email_received"=>(current_nb_mail).to_s } }
        let(:gmail_service) { GmailClientTest.new(nil, email, current_nb_mail.to_s) }

        it "returns false" do
          command = EmailReceivedActionCommand.new(options, gmail_service)
          handler = EmailReceivedActionCommandHandler.new

          expect(handler.call(command.to_h, gmail_service)).to eq(false)
        end
      end
    end
  end
end
