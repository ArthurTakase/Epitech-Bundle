# frozen_string_literal: true

class EmailReceivedActionCommand
  def initialize(options, gmail_service = nil)
    @action_id = options["action_id"]
    user = Action.find(@action_id).widget.user
    @token = user.google_token
    @email = user.email
    @last_number_of_email_received = options["last_number_of_email_received"] || current_number_of_mail(gmail_service)
  end

  def to_h
    { action_id: @action_id, last_number_of_email_received: @last_number_of_email_received, token: @token,
      email: @email }
  end

  private
    def current_number_of_mail(gmail_service)
      gmail_service ||= GmailClient.new(@token, @email)
      info =  gmail_service.user_info
      info["messagesTotal"]
    end
end
