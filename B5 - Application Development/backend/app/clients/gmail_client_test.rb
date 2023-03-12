# frozen_string_literal: true

class GmailClientTest
  def initialize(refresh_token, email, message_total = "85")
    @refresh_token = refresh_token
    @email = email
    @user_info_request = 0
    @send_mail_request = 0
    @last_mail = ""
    @message_total = message_total
  end

  def user_info
    return if @refresh_token.nil? || @email.nil?

    @user_info_request += 1
    { "emailAddress"=>@email, "messagesTotal"=>@message_total, "threadsTotal"=>51, "historyId"=>"1849490" }
  end

  def send_mail(to, subject, message)
    return if @refresh_token.nil? || @email.nil?

    @last_mail = Base64.encode64("From: <#{@email}>
  To: <#{to}>
  Subject: #{subject}
  Content-type: text/html;charset=utf-8

  #{message}").tr("+/", "-_").delete("\n")

    @send_mail_request += 1
  end

  attr_reader :user_info_request, :send_mail_request, :last_mail
end
