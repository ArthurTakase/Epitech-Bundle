require "rails_helper"

RSpec.describe EachHourActionCommandHandler do
  describe "#each_hour" do
    let(:action) { create(:action) }
    let(:current_hour) { "16:10:58" }
    let(:mocked_response)  { { "status"=>"OK", "message"=>"", "countryCode"=>"FR", "countryName"=>"France",
                        "regionName"=>"Nouvelle-Aquitaine", "cityName"=>"Bordeaux", "zoneName"=>"Europe/Paris",
                        "abbreviation"=>"CET", "gmtOffset"=>3600, "dst"=>"0",
                        "zoneStart"=>1667091600, "zoneEnd"=>1679792400, "nextAbbreviation"=>"CEST",
                        "timestamp"=>1667769118, "formatted"=>"#{Date.today} #{current_hour}" } }

    context "when the last hour is one hour ago" do
      let(:options)  { { "action_id" => action.id, "last_hour" => (current_hour.to_time-1.hour).to_s } }
      it "returns true" do
        command = EachHourActionCommand.new(options)
        handler = EachHourActionCommandHandler.new
        expect(handler.call(command.to_h, mocked_response)).to eq(true)
      end
    end

    context "when the last hour is now" do
      let(:options)  { { "action_id" => action.id, "last_hour" => current_hour.to_time.to_s } }
      it "returns false" do
        command = EachHourActionCommand.new(options)
        handler = EachHourActionCommandHandler.new
        expect(handler.call(command.to_h, mocked_response)).to eq(false)
      end
    end

    context "when the last hour is in one hour" do
      let(:options)  { { "action_id" => action.id, "last_hour" => (current_hour.to_time+1.hour).to_s } }
      it "returns false" do
        command = EachHourActionCommand.new(options)
        handler = EachHourActionCommandHandler.new
        expect(handler.call(command.to_h, mocked_response)).to eq(false)
      end
    end

    context "when the last hour is undefined" do
      let!(:current_hour) { Time.now.end_of_hour.to_s }
      let(:options)  { { "action_id" => action.id } }
      it "returns true" do
        command = EachHourActionCommand.new(options)
        handler = EachHourActionCommandHandler.new
        expect(handler.call(command.to_h, mocked_response)).to eq(true)
      end
    end
  end
end
