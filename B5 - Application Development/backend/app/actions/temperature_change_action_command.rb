# frozen_string_literal: true

class TemperatureChangeActionCommand
  def initialize(options, mocked_response = nil)
    @action_id = options["action_id"]
    @latitude = options["latitude"]
    @longitude = options["longitude"]
    @last_temp = options["last_temp"] || current_temp(mocked_response)
  end

  def to_h
    { action_id: @action_id, latitude: @latitude, longitude: @longitude, last_temp: @last_temp }
  end

  private
    def current_temp(mocked_response = nil)
      url = "https://api.open-meteo.com/v1/forecast?latitude=#{@latitude}&longitude=#{@longitude}&current_weather=true"
      weather_info = mocked_response || HTTParty.get(url)
      weather_info["current_weather"]["temperature"]
    rescue NoMethodError
      puts "Error: OpenMeteo return null" unless Rails.env.test?
      nil
    end
end
