require "rails_helper"

RSpec.describe AtHourActionCommandHandler do
  describe "#at_hour" do
    let(:action) { create(:action) }
    let(:current_hour) { "16:10:58" }
    let(:mocked_response)  { { "status"=>"OK", "message"=>"", "countryCode"=>"FR", "countryName"=>"France",
                        "regionName"=>"Nouvelle-Aquitaine", "cityName"=>"Bordeaux", "zoneName"=>"Europe/Paris",
                        "abbreviation"=>"CET", "gmtOffset"=>3600, "dst"=>"0",
                        "zoneStart"=>1667091600, "zoneEnd"=>1679792400, "nextAbbreviation"=>"CEST",
                        "timestamp"=>1667769118, "formatted"=>"#{Date.today} #{current_hour}" } }
    context "when the hour has passed" do
      let(:options)  { { "action_id" => action.id, "hour" => "16:00" } }
      it "returns true" do
        # byebug
        command = AtHourActionCommand.new(options)
        handler = AtHourActionCommandHandler.new
        expect(handler.call(command.to_h, mocked_response)).to eq(true)
      end
    end

    context "when the hour is now" do
      let(:options)  { { "action_id" => action.id, "hour" => current_hour } }
      it "returns false" do
        command = AtHourActionCommand.new(options)
        handler = AtHourActionCommandHandler.new
        expect(handler.call(command.to_h, mocked_response)).to eq(true)
      end
    end

    context "when the hour later" do
      let(:options)  { { "action_id" => action.id, "hour" => "16:15" } }
      it "returns false" do
        command = AtHourActionCommand.new(options)
        handler = AtHourActionCommandHandler.new
        expect(handler.call(command.to_h, mocked_response)).to eq(false)
      end
    end
  end
end
