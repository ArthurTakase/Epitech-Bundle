# frozen_string_literal: true

class EachDayActionCommandHandler
  def initialize
  end

  def call(attributes, mocked_response = nil)
    puts "Each Day Command Handler" unless Rails.env.test?
    begin
      time_info = mocked_response || HTTParty.get("https://api.timezonedb.com/v2.1/get-time-zone?key=MLW9WKV7JEUS&format=json&by=position&lat=44.8404&lng=-0.5805")
      today = time_info["formatted"].to_time.end_of_day
      last_day = attributes[:last_day].to_time.end_of_day
    rescue Exception => e
      puts "EachDayCommandHander error to_time on nil object"
      return false
    end

    result = today > last_day
    if result
      action = Action.find(attributes[:action_id])
      action.options["last_day"] = today.to_date.to_s
      action.save
    end
    result
  end
end
