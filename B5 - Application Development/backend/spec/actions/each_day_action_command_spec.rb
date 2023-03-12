require "rails_helper"

RSpec.describe EachDayActionCommand do
  describe "#to_h" do
    context "without last_day" do
      let(:options) { { "action_id"=> 1 } }
      it "returns a hash with the correct keys" do
        command = EachDayActionCommand.new(options)
        expect(command.to_h).to eq({ action_id: 1, last_day: (Date.today-1).to_s })
      end
    end

    context "with last_day" do
      let(:options) { { "action_id"=> 1, "last_day" => (Date.today+1).to_s } }
      it "returns a hash with the correct keys" do
        command = EachDayActionCommand.new(options)
        expect(command.to_h).to eq({ action_id: 1, last_day: (Date.today+1).to_s })
      end
    end
  end
end
