# frozen_string_literal: true

class EachHourActionCommandHandler
  def initialize
  end

  def call(attributes, mocked_response = nil)
    puts "Each Hour Command Handler" unless Rails.env.test?

    time_info = mocked_response || HTTParty.get("https://api.timezonedb.com/v2.1/get-time-zone?key=MLW9WKV7JEUS&format=json&by=position&lat=44.8404&lng=-0.5805")
    
    unless time_info["formatted"]
      puts "Error: Timezonedb return null" unless Rails.env.test?
      return false
    end
    
    current_hour = time_info["formatted"].to_time.end_of_hour
    last_hour = attributes[:last_hour].to_time.end_of_hour
    result = current_hour > last_hour

    if result
      action = Action.find(attributes[:action_id])
      action.options["last_hour"] = current_hour
      action.save
    end
    result
  end
end
