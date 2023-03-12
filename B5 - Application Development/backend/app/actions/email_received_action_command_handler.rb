# frozen_string_literal: true

class EmailReceivedActionCommandHandler
  def initialize
  end

  def call(attributs, gmail = nil)
    puts "Email Received Command Handler" unless Rails.env.test?
    gmail ||= GmailClient.new(attributs[:token], attributs[:email])
    info = gmail.user_info

    begin
      current_number_of_mail_received = info["messagesTotal"]
      last_number_of_mail_received = attributs[:last_number_of_email_received]
      rescue NoMethodError
        puts "Gmail return null" unless Rails.env.test?
        return false
    end

    result = current_number_of_mail_received > last_number_of_mail_received
    some_mail_have_been_deleted = current_number_of_mail_received < last_number_of_mail_received

    action = Action.find(attributs[:action_id])
    action.options["last_number_of_email_received"] = current_number_of_mail_received
    action.save

    result
  end
end
