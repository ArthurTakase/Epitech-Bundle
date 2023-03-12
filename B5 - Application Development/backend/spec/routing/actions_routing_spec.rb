require "rails_helper"

RSpec.describe ActionsController, type: :routing do
  describe "routing" do
    it "routes to #index" do
      expect(get: "/actions").to route_to("actions#index")
    end

    it "routes to #show" do
      expect(get: "/actions/1").to route_to("actions#show", id: "1")
    end
  end
end
