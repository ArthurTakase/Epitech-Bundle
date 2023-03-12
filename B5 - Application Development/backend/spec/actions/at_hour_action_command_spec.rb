require "rails_helper"

RSpec.describe AtHourActionCommand do
  describe "#to_h" do
    context "without hour" do
      before { create(:action, id: 1, widget_id: (create(:widget, id: 3).id)) }
      let(:options) { { "action_id"=>1 } }
      it "returns a hash with invalid keys" do
        command = AtHourActionCommand.new(options)
        expect(command.to_h).to eq({ action_id: 1, widget_id: 3, hour: nil })
      end
    end

    context "with hour" do
      before { create(:action, id: 1, widget_id: (create(:widget, id: 3).id)) }
      let(:options) { { "action_id"=>1, "hour"=>"16:00" } }
      it "returns a hash with valid keys" do
        command=AtHourActionCommand.new(options)
        expect(command.to_h).to eq({ action_id: 1, widget_id: 3, hour: "16:00" })
      end
    end
  end
end
