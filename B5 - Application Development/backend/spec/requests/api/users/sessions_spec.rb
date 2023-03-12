# frozen_string_literal: true

require "swagger_helper"
require "rails_helper"

RSpec.describe "api/users/sessions", type: :request do
  path "/users" do
    post "Register new user" do
      tags "Connection"
      consumes "application/json"
      produces "application/json"
      security [bearer: {}]
      parameter name: :user, in: :body, schema: {
                  type: :object,
                  properties: {
                    user: {
                      type: :object,
                      properties: {
                        first_name: { type: :string, example: "Adam" },
                        last_name: { type: :string, example: "Smasher" },
                        email: { type: :string, example: "adam.smash@email.com" },
                        password: { type: :string, example: "12345" },
                        password_confirmation: { type: :string, example: "12345" }
                      },
                      required: %w[first_name last_name email password]
                    }
                  },
                  required: %w[user]
                }

      response "201", "User created" do
        let!(:user) {
          {
            user: {
              first_name: "Adam",
              last_name: "Smasher",
              email: "adam.smash@email.com",
              password: "123456",
              password_confirmation: "123456",
            }
          }
        }

        example "application/json", :example, {
                  id: 4,
                  first_name: "Adam",
                  last_name: "Smasher",
                  email: "adam.smash@email.com",
                  admin: false,
                  background: nil,
                  widgets: []
                }
        run_test!
      end

      response "422", "Unprocessable entity" do
        let!(:user) { { user: { email: "random@email.com" } } }

        run_test!
      end
    end
  end

  path "/users/sign_in.json" do
    post "Sign in user" do
      tags "Connection"
      consumes "application/json"
      produces "application/json"
      security [bearer: {}]
      parameter name: :user, in: :body, schema: {
                  type: :object,
                  properties: {
                    user: {
                      type: :object,
                      properites: {
                        email: { type: :string, example: "adam.smash@email.com" },
                        password: { type: :string, example: "123456" }
                      },
                      required: %w[email password]
                    }
                  },
                  required: %w[user]
                }
      response "200", "ok" do
        before { sign_in(create(:user)) }
        let!(:user) { { user: { email: "adam.smash@email.com", password: "123456" } } }
        example "application/json", :example, {
                  message: "Logged."
                }

        run_test!
      end

      response "401", "Unauthorized" do
        let!(:user) { { user: { email: "adam.smash@email.com", password: "badMdp" } } }
        example "application/json", :example, {
                  error: "Invalid Email or password."
                }
        run_test!
      end
    end
  end
end
