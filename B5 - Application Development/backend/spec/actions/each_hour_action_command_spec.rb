require "rails_helper"

RSpec.describe EachHourActionCommand do
  describe "#to_h" do
    context "without last_hour" do
      let(:options) { { "action_id"=> 1 } }
      it "returns a hash with the correct keys" do
        command = EachHourActionCommand.new(options)
        expect(command.to_h).to eq({ action_id: 1, last_hour: (Time.now-1.hour).end_of_hour.to_s })
      end
    end

    context "with last_hour" do
      let(:options) { { "action_id"=> 1, "last_hour" => (Time.now+1.hour).to_s } }
      it "returns a hash with the correct keys" do
        command = EachHourActionCommand.new(options)
        expect(command.to_h).to eq({ action_id: 1, last_hour: (Time.now+1.hour).to_s })
      end
    end
  end
end
