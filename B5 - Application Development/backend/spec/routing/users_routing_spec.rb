require "rails_helper"

RSpec.describe UsersController, type: :routing do
  describe "routing" do
    it "routes to #index" do
      expect(get: "/users").to route_to("users#index")
    end

    it "routes to #show" do
      expect(get: "/users/1").to route_to("users#show", id: "1")
    end

    it "routes to #create" do
      expect(post: "/users").to route_to("devise/registrations#create", format: :json)
    end

    it "routes to #destroy" do
      expect(delete: "/users/1").to route_to("users#destroy", id: "1")
    end

    it "routes to #current_user" do
      expect(get: "/current_user").to route_to("users#show_current_user")
    end

    it "routes to #reset_token" do
      expect(get: "/users/reset_token").to route_to("users#reset_token")
    end

    it "routes to #refresh_token" do
      expect(post: "/users/refresh_token").to route_to("users#refresh_token")
    end

    it "routes to #google_sign_in" do
      expect(post: "/users/google_sign_in").to route_to("users#google_sign_in")
    end

    it "routes to #delete_token" do
      expect(post: "/users/delete_token").to route_to("users#delete_token")
    end
  end
end
