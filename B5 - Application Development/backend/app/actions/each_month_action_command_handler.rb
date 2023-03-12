# frozen_string_literal: true

class EachMonthActionCommandHandler
  def initialize
  end

  def call(attributes, mocked_response = nil)
    puts "Each Month Command Handler" unless Rails.env.test?

    time_info = mocked_response || HTTParty.get("https://api.timezonedb.com/v2.1/get-time-zone?key=MLW9WKV7JEUS&format=json&by=position&lat=44.8404&lng=-0.5805")
    current_month = time_info["formatted"].to_date.end_of_month
    last_month = attributes[:last_month].to_date.end_of_month
    result = current_month > last_month

    if result
      action = Action.find(attributes[:action_id])
      action.options["last_month"] = current_month.to_s
      action.save
    end
    result
  end
end
