require "rails_helper"

RSpec.describe EachDayActionCommandHandler do
  describe "#each_day" do
    let(:action) { create(:action) }
    let(:current_day) { "2022-11-05" }
    let(:mocked_response)  { { "status"=>"OK", "message"=>"", "countryCode"=>"FR", "countryName"=>"France",
                        "regionName"=>"Nouvelle-Aquitaine", "cityName"=>"Bordeaux", "zoneName"=>"Europe/Paris",
                        "abbreviation"=>"CET", "gmtOffset"=>3600, "dst"=>"0",
                        "zoneStart"=>1667091600, "zoneEnd"=>1679792400, "nextAbbreviation"=>"CEST",
                        "timestamp"=>1667769118, "formatted"=>"#{current_day} 16:11:58" } }

    context "when the last day is yesterday" do
      let(:options)  { { "action_id" => action.id, "last_day" => (Date.parse(current_day)-1).to_s } }
      it "returns true" do
        command = EachDayActionCommand.new(options)
        handler = EachDayActionCommandHandler.new
        expect(handler.call(command.to_h, mocked_response)).to eq(true)
      end
    end

    context "when the last day is today" do
      let(:options)  { { "action_id" => action.id, "last_day" => (Date.parse(current_day)).to_s } }
      it "returns false" do
        command = EachDayActionCommand.new(options)
        handler = EachDayActionCommandHandler.new
        expect(handler.call(command.to_h, mocked_response)).to eq(false)
      end
    end

    context "when the last day is tomorrow" do
      let(:options)  { { "action_id" => action.id, "last_day" => (Date.parse(current_day)+1).to_s } }
      it "returns false" do
        command = EachDayActionCommand.new(options)
        handler = EachDayActionCommandHandler.new
        expect(handler.call(command.to_h, mocked_response)).to eq(false)
      end
    end

    context "when the last day is undefined" do
      let!(:current_day) { Date.today.to_s }
      let(:options)  { { "action_id" => action.id } }
      it "returns true" do
        command = EachDayActionCommand.new(options)
        handler = EachDayActionCommandHandler.new
        expect(handler.call(command.to_h, mocked_response)).to eq(true)
      end
    end
  end
end
