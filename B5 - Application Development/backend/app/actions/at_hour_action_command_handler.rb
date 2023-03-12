# frozen_string_literal: true

class AtHourActionCommandHandler
  def initialize
  end

  def call(attributes, mocked_response = nil)
    puts "At Hour Command Handler" unless Rails.env.test?

    begin
      time_info = mocked_response || HTTParty.get("https://api.timezonedb.com/v2.1/get-time-zone?key=MLW9WKV7JEUS&format=json&by=position&lat=44.8404&lng=-0.5805")
      current_time = time_info["formatted"].to_time
    rescue NoMethodError
      puts "Error: TimeZoneDB return nil"
      return false
    end

    # byebug

    target_time = attributes[:hour].to_time

    resultat = target_time <= current_time

    Widget_to_disable.append(attributes[:widget_id]) if resultat

    resultat
  end
end
