require "rails_helper"

RSpec.describe EachMonthActionCommand do
  describe "#to_h" do
    context "without last_month" do
      let(:options) { { "action_id"=> 1 } }
      it "returns a hash with the correct keys" do
        command = EachMonthActionCommand.new(options)
        expect(command.to_h).to eq({ action_id: 1, last_month: Date.today.prev_month.to_s })
      end
    end

    context "with last_month" do
      let(:options) { { "action_id"=> 1, "last_month" => Date.today.to_s } }
      it "returns a hash with the correct keys" do
        command = EachMonthActionCommand.new(options)
        expect(command.to_h).to eq({ action_id: 1, last_month: Date.today.to_s })
      end
    end
  end
end
