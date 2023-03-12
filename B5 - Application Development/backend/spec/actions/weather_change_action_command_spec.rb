require "rails_helper"

RSpec.describe WeatherChangeActionCommand do
    describe "#to_h" do
        let(:action) { create(:action) }
        context "when last weather is given" do
          let(:options) { { "action_id"=>action.id, "longitude"=>"84", "latitude"=>"2", "last_weather"=>2 } }
          it "return valid hash" do
            command = WeatherChangeActionCommand.new(options)
            expect(command.to_h).to eq({ action_id: action.id, longitude: "84", latitude: "2", last_weather: 2 })
          end
        end

        context "when last weather isn't given" do
          let(:options) { { "action_id"=>action.id, "longitude"=>"84", "latitude"=>"2" } }
          let(:mocked_response)  { {
              "latitude"=>44.84,
              "longitude"=>-0.58000016,
              "generationtime_ms"=>0.18203258514404297,
              "utc_offset_seconds"=>0,
              "timezone"=>"GMT",
              "timezone_abbreviation"=>"GMT",
              "elevation"=>19.0,
              "current_weather"=>{ "temperature"=>"12", "windspeed"=>4.7, "winddirection"=>86.0, "weathercode"=>2,
                                   "time"=>"2022-11-11T21:00" } } }
          it "return valid hash" do
            command = WeatherChangeActionCommand.new(options, mocked_response)
            expect(command.to_h).to eq({ action_id: action.id, longitude: "84", latitude: "2", last_weather: 2 })
          end
        end
      end
end