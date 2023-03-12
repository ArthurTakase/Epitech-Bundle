require "rails_helper"

RSpec.describe WeatherChangeActionCommandHandler do
  describe "#Weather_change" do
    let(:action) { create(:action) }
    let(:current_weather) { 2 }
    let(:mocked_response)  { {
        "latitude"=>44.84,
        "longitude"=>-0.58000016,
        "generationtime_ms"=>0.18203258514404297,
        "utc_offset_seconds"=>0,
        "timezone"=>"GMT",
        "timezone_abbreviation"=>"GMT",
        "elevation"=>19.0,
        "current_weather"=>{ "temperature"=>"12", "windspeed"=>4.7, "winddirection"=>86.0,
                             "weathercode"=>2, "time"=>"2022-11-11T21:00" } } }

    context "when the last weather is lower than the current weather" do
      let(:options)  { { "action_id" => action.id, "last_weather" => (current_weather-1) } }
      it "returns true" do
        command = WeatherChangeActionCommand.new(options)
        handler = WeatherChangeActionCommandHandler.new
        expect(handler.call(command.to_h, mocked_response)).to eq(true)
      end
    end

    context "when the last weather is equal to the current weather" do
      let(:options)  { { "action_id" => action.id, "last_weather" => (current_weather) } }
      it "returns false" do
        command = WeatherChangeActionCommand.new(options)
        handler = WeatherChangeActionCommandHandler.new
        expect(handler.call(command.to_h, mocked_response)).to eq(false)
      end
    end

    context "when the last weather is higher than the current weather" do
      let(:options)  { { "action_id" => action.id, "last_weather" => (current_weather+1) } }
      it "returns true" do
        command = WeatherChangeActionCommand.new(options)
        handler = WeatherChangeActionCommandHandler.new
        expect(handler.call(command.to_h, mocked_response)).to eq(true)
      end
    end

    context "when the last weather is undefined" do
      let(:options)  { { "action_id" => action.id } }
      it "returns true" do
        command = WeatherChangeActionCommand.new(options)
        handler = WeatherChangeActionCommandHandler.new
        expect(handler.call(command.to_h, mocked_response)).to eq(true)
      end
    end
  end
end
