require "rails_helper"

RSpec.describe EachMonthActionCommandHandler do
  describe "#each_month" do
    let(:action) { create(:action) }
    let(:current_day) { "2022-11-06" }
    let(:mocked_response)  { { "status"=>"OK", "message"=>"", "countryCode"=>"FR", "countryName"=>"France",
                        "regionName"=>"Nouvelle-Aquitaine", "cityName"=>"Bordeaux", "zoneName"=>"Europe/Paris",
                        "abbreviation"=>"CET", "gmtOffset"=>3600, "dst"=>"0",
                        "zoneStart"=>1667091600, "zoneEnd"=>1679792400, "nextAbbreviation"=>"CEST",
                        "timestamp"=>1667769118, "formatted"=>"#{current_day} 16:11:58" } }

    context "when the last month is one month ago" do
      let(:options)  { { "action_id" => action.id, "last_month" => Date.parse(current_day).prev_month.to_s } }
      it "returns true" do
        command = EachMonthActionCommand.new(options)
        handler = EachMonthActionCommandHandler.new
        expect(handler.call(command.to_h, mocked_response)).to eq(true)
      end
    end

    context "when the last month is today" do
      let(:options)  { { "action_id" => action.id, "last_month" => Date.parse(current_day).to_s } }
      it "returns false" do
        command = EachMonthActionCommand.new(options)
        handler = EachMonthActionCommandHandler.new
        expect(handler.call(command.to_h, mocked_response)).to eq(false)
      end
    end

    context "when the last month is in 30 days" do
      let(:options)  { { "action_id" => action.id, "last_month" => Date.parse(current_day).next_month.to_s } }
      it "returns false" do
        command = EachMonthActionCommand.new(options)
        handler = EachMonthActionCommandHandler.new
        expect(handler.call(command.to_h, mocked_response)).to eq(false)
      end
    end

    context "when the last month is undefined" do
      let(:options)  { { "action_id" => action.id } }
      it "returns true" do
        command = EachMonthActionCommand.new(options)
        handler = EachMonthActionCommandHandler.new
        expect(handler.call(command.to_h, mocked_response)).to eq(true)
      end
    end
  end
end
