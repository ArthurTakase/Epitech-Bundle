require "rails_helper"

RSpec.describe TemperatureChangeActionCommandHandler do
  describe "#temperature_change" do
    let(:action) { create(:action) }
    let(:current_temperature) { 12.0 }
    let(:mocked_response)  { {
        "latitude"=>44.84,
        "longitude"=>-0.58000016,
        "generationtime_ms"=>0.18203258514404297,
        "utc_offset_seconds"=>0,
        "timezone"=>"GMT",
        "timezone_abbreviation"=>"GMT",
        "elevation"=>19.0,
        "current_weather"=>{ "temperature"=>current_temperature, "windspeed"=>4.7, "winddirection"=>86.0,
                             "weathercode"=>0, "time"=>"2022-11-11T21:00" } } }

    context "when the last temperature is lower than the current temperature" do
      let(:options)  { { "action_id" => action.id, "last_temp" => (current_temperature-1) } }
      it "returns true" do
        command = TemperatureChangeActionCommand.new(options)
        handler = TemperatureChangeActionCommandHandler.new
        expect(handler.call(command.to_h, mocked_response)).to eq(true)
      end
    end

    context "when the last temperature is equal to the current temperature" do
      let(:options)  { { "action_id" => action.id, "last_temp" => (current_temperature) } }
      it "returns false" do
        command = TemperatureChangeActionCommand.new(options)
        handler = TemperatureChangeActionCommandHandler.new
        expect(handler.call(command.to_h, mocked_response)).to eq(false)
      end
    end

    context "when the last temperature is higher than the current temperature" do
      let(:options)  { { "action_id" => action.id, "last_temp" => (current_temperature+1) } }
      it "returns true" do
        command = TemperatureChangeActionCommand.new(options)
        handler = TemperatureChangeActionCommandHandler.new
        expect(handler.call(command.to_h, mocked_response)).to eq(true)
      end
    end

    context "when the last temperature is undefined" do
      let(:options)  { { "action_id" => action.id } }
      it "returns true" do
        command = TemperatureChangeActionCommand.new(options)
        handler = TemperatureChangeActionCommandHandler.new
        expect(handler.call(command.to_h, mocked_response)).to eq(true)
      end
    end
  end
end

# HTTParty.get("https://api.open-meteo.com/v1/forecast?latitude=44.8404&longitude=-0.5805&current_weather=true")
