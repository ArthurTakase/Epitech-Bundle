# frozen_string_literal: true

class DailyPhotoMailReactionCommandHandler
  def initialize
  end

  def call(attributes, gmail = nil, mocked_response = nil)
    puts "Daily Photo Mail Command Handler" unless Rails.env.test?

    img_info = mocked_response || HTTParty.get("https://api.nasa.gov/planetary/apod?api_key=0kohlBRL0b1ymWbGae4GKifyolr5cZ66qLBrHb6j")
    img = img_info["url"]

    user = User.find(attributes[:user_id])
    gmail ||= GmailClient.new(user.google_token, user.email)
    gmail.send_mail(attributes[:email], "AREA Daily Nasa Picture", "<img src='#{img}' alt='Nasa Daily Picture'/>")
  end
end
