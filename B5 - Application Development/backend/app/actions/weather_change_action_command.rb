# frozen_string_literal: true

class WeatherChangeActionCommand
  def initialize(options, mocked_response = nil)
    @action_id = options["action_id"]
    @latitude = options["latitude"]
    @longitude = options["longitude"]
    @last_weather = options["last_weather"] || current_weather(mocked_response)
  end

  def to_h
    { action_id: @action_id, latitude: @latitude, longitude: @longitude, last_weather: @last_weather }
  end

  private
    def current_weather(mocked_response = nil)
      url = "https://api.open-meteo.com/v1/forecast?latitude=#{@latitude}&longitude=#{@longitude}&current_weather=true"
      weather_info = mocked_response || HTTParty.get(url)
      weather_info["current_weather"]["weathercode"].to_i
    rescue NoMethodError
      puts "Error: OpenMeteo return null" unless Rails.env.test?
      nil
    end
end