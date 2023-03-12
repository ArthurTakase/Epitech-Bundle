require "rails_helper"

RSpec.describe ReactionsController, type: :routing do
  describe "routing" do
    it "routes to #index" do
      expect(get: "/reactions").to route_to("reactions#index")
    end

    it "routes to #show" do
      expect(get: "/reactions/1").to route_to("reactions#show", id: "1")
    end
  end
end
