# frozen_string_literal: true

class TemperatureChangeActionCommandHandler
  def initialize
  end

  def call(attributes, mocked_response = nil)
    puts "Temperature Change Command Handler" unless Rails.env.test?

    begin
      url = "https://api.open-meteo.com/v1/forecast?latitude=#{attributes[:latitude]}&longitude=#{attributes[:longitude]}&current_weather=true"
      weather_info = mocked_response || HTTParty.get(url)
      current_temp = weather_info["current_weather"]["temperature"].to_f
    rescue NoMethodError
      puts "Error: OpenMeteo return null" unless Rails.env.test?
      return false
    end

    last_temp = attributes[:last_temp].to_f
    result = current_temp != last_temp

    puts "Temperature Change: #{current_temp}" if result and !Rails.env.test?

    action = Action.find(attributes[:action_id])
    action.options["last_temp"] = current_temp.to_s
    action.save

    result
  end
end
