# frozen_string_literal: true

require "swagger_helper"
require "rails_helper"

RSpec.describe "api/users", type: :request do
  path "/users" do
    get "Get all user" do
      tags "Users as admin"
      produces "application/json"
      security [bearer: {}]

      response "200", "ok" do
        before { login_as create(:user_admin) }
        before { create(:user) }
        example "application/json", :example_two_user, [
                    {
                      id: 3,
                      first_name: "Alain",
                      last_name: "Provist",
                      email: "al.pro@email.com",
                      admin: false,
                      background: nil,
                      widgets: []
                    },
                    {
                      id: 4,
                      first_name: "Jean",
                      last_name: "Michelle",
                      email: "jean.michelle@email.com",
                      admin: false,
                      background: nil,
                      widgets: [
                        {
                          id: 1,
                          name: "Widget background",
                          active: true
                        },
                        {
                          id: 2,
                          name: "Widget twitter",
                          active: true
                        }
                      ]
                    }
                  ]
        run_test!
      end

      response "401", "unauthorized" do
        example "application/json", :your_not_logged, {
                  error: "You need to be logged"
                }

        example "application/json", :your_not_admin, {
                  error: "You are not admin."
                }

        run_test!
      end
    end
  end

  path "/current_user" do
    get "Get current user" do
      tags "Users"
      produces "application/json"
      security [bearer: {}]

      response "200", "ok" do
        before { login_as create(:user_admin) }

        example "application/json", :example, {
                  id: 1,
                  first_name: "Adam",
                  last_name: "Smasher",
                  email: "adam.smasher@email.com",
                  admin: false,
                  background: "https://apod.nasa.gov/apod/image/2210/LDN43_SelbyHanson_960.jpg",
                  widgets: [
                    {
                      id: 41,
                      name: "New background at 16h",
                      active: false,
                      action: {
                        id: 4,
                        name: "at_hour",
                        options: {
                          hour: "16:00:00",
                          action_id: 4
                        }
                      },
                      reaction: {
                        id: 3,
                        name: "daily_photo_bg",
                        options: {
                          reaction_id: 3
                        }
                      }
                    }
                  ]
                }

        run_test!
      end
      response "401", "unauthorized" do
        example "application/json", :your_not_logged, {
                  error: "You need to be logged"
                }

        run_test!
      end
    end
  end

  path "/users/{id}" do
    get "Get information user" do
      tags "Users as admin"
      produces "application/json"
      security [bearer: {}]
      parameter name: :id, in: :path, type: :string

      response "200", "ok" do
        before { sign_in(create(:user_admin)) }
        before { create(:user, id: 1) }
        let(:id) { 1 }


        example "application/json", :example, {
                  id: 1,
                  first_name: "Adam",
                  last_name: "Smasher",
                  email: "adam.smasher@email.com",
                  admin: false,
                  background: "https://apod.nasa.gov/apod/image/2210/LDN43_SelbyHanson_960.jpg",
                  widgets: [
                    {
                      id: 41,
                      name: "New background at 16h",
                      active: false,
                      action: {
                        id: 4,
                        name: "at_hour",
                        options: {
                          hour: "16:00:00",
                          action_id: 4
                        }
                      },
                      reaction: {
                        id: 3,
                        name: "daily_photo_bg",
                        options: {
                          reaction_id: 3
                        }
                      }
                    }
                  ]
                }

        run_test!
      end

      response "401", "unauthorized" do
        let(:id) { 1 }

        example "application/json", :your_not_logged, {
                  error: "You need to be logged"
                }

        example "application/json", :your_not_admin, {
                  error: "You are not admin."
                }

        run_test!
      end

      response "404", "user not found" do
        before { sign_in(create(:user_admin)) }
        let(:id) { 34 }

        run_test!
      end
    end

    patch "Update user information" do
      tags "Users as admin"
      consumes "application/json"
      produces "application/json"
      security [bearer: {}]
      parameter name: :id, in: :path, type: :string
      parameter name: :user, in: :body, schema: {
            type: :object,
            properties: {
              user: {
                type: :object,
                properties: {
                  first_name: { type: :string, example: "Jean-Jean" },
                  last_name: { type: :string, example: "Sernine" },
                  email: { type: :string, example: "jean.michelle@email.com" },
                  password: { type: :string, example: "azerty" },
                  admin: { type: :boolean, example: true }
                }
              }
            },
            required: %w[user]
        }

      response "200", "ok" do
        before { sign_in(create(:user_admin)) }
        before { create(:user, id: 1) }
        let!(:user) { { user: { email: "jean.michelle@email.com" } } }
        let(:id) { 1 }

        example "application/json", :example, {
                  id: 1,
                  first_name: "Adam",
                  last_name: "Smasher",
                  email: "jean.michelle@email.com",
                  admin: false,
                  background: "https://apod.nasa.gov/apod/image/2210/LDN43_SelbyHanson_960.jpg",
                  widgets: [
                    {
                      id: 41,
                      name: "New background at 16h",
                      active: false,
                      action: {
                        id: 4,
                        name: "at_hour",
                        options: {
                          hour: "16:00:00",
                          action_id: 4
                        }
                      },
                      reaction: {
                        id: 3,
                        name: "daily_photo_bg",
                        options: {
                          reaction_id: 3
                        }
                      }
                    }
                  ]
                }
        run_test!
      end

      response "401", "unauthorized" do
        let(:id) { 1 }
        let!(:user) { }

        example "application/json", :your_not_logged, {
                  error: "You need to be logged"
                }

        example "application/json", :your_not_admin, {
                  error: "You are not admin."
                }

        run_test!
      end

      response "404", "user not found" do
        before { sign_in(create(:user_admin)) }
        let(:id) { 34 }
        let!(:user) { }

        run_test!
      end
    end

    delete "Delete user" do
      tags "Users as admin"
      produces "application/json"
      security [bearer: {}]
      parameter name: :id, in: :path, type: :string

      response "204", "delete user" do
        before { sign_in(create(:user_admin)) }
        before { create(:user, id: 1) }
        let(:id) { 1 }

        run_test!
      end

      response "401", "unauthorized" do
        let(:id) { 1 }

        example "application/json", :your_not_logged, {
                    error: "You need to be logged"
                }

        example "application/json", :your_not_admin, {
                    error: "You are not admin."
                }

        run_test!
      end

      response "404", "user not found" do
        before { sign_in(create(:user_admin)) }
        let(:id) { 34 }

        run_test!
      end
    end
  end

  path "/users/reset_token" do
    get "Reset and send new token hashed" do
      tags "Users"
      security [bearer: {}]
      produces "application/json"

      response "200", "ok" do
        before { sign_in(create(:user_admin)) }
        let(:id) { 1 }
        example "application/json", :example, {
                  token: "897987ee7f0ed983570d19c17aab94a8cde3c4e53c57e3fb7f6366948997155b"
                }

        run_test!
      end

      response "401", "unauthorized" do
        let(:id) { 1 }
        example "application/json", :your_not_logged, {
                  error: "You need to be logged"
                }

        run_test!
      end
    end
  end

  path "/users/password.json" do
    let(:hashed) { Devise.token_generator.generate(User, :reset_password_token)[1] }

    put "Update user password" do
      tags "Users"
      security [bearer: {}]
      produces "application/json"
      consumes "application/json"
      parameter name: :user, in: :body, schema: {
                  type: :object,
                  properties: {
                    user: {
                      type: :object,
                      properties: {
                        current_password: { type: :string, example: "123456" },
                        password: { type: :string, example: "azerty" },
                        password_confirmation: { type: :string, example: "azerty" },
                        reset_password_token: { type: :string, example: "rifdlghqgiufogoaeze43hyu8" }
                      },
                      required: %w[current_password password password_confirmation reset_password_token]
                    }
                  },
                required: %w[user]
                }

      response "204", "password changed" do
        before { sign_in(create(:user)) }
        before { User.last.reset_token(hashed) }
        let!(:user) {
          {
            user: {
              current_password: "123456", password: "azerty", current_password: "azertyj",
              reset_password_token: hashed }
          }
        }

        run_test!
      end

      response "422", "unprocessable entity" do
        before { sign_in(create(:user, password: "123456")) }
        before { User.last.reset_token(hashed) }
        let!(:user) {
          {
            user: {
              current_password: "123456", password: "azerty", current_password: "azertyj",
              reset_password_token: "dfgsdhsg42fsdg8" }
          }
        }

        example "application/json", :your_not_logged, {
                  error: "You need to be logged"
                }

        run_test!
      end
    end
  end

  path "/users" do
    patch "Update user information" do
      tags "Users"
      consumes "application/json"
      produces "application/json"
      security [bearer: {}]
      parameter name: :user, in: :body, schema: {
                  type: :object,
                  properties: {
                    user: {
                      type: :object,
                      properties: {
                        email: { type: :string, example: "new_email@email.com" },
                        current_password: { type: :string, example: "123456" }
                      },
                      required: %w[current_password]
                    }
                  },
                  required: %w[user]
                }

      response "204", "user updated" do
        before { sign_in(create(:user, password: "123456")) }
        let!(:user) { { user: { email: "new_email@email.com", current_password: "123456" } } }

        run_test!
      end

      response "401", "unauthorize" do
        let!(:user) { { user: { email: "new_email@email.com", current_password: "123456" } } }
        example "application/json", :your_not_logged, {
                  error: "You need to be logged"
                }

        run_test!
      end

      response "422", "unprocessable entity" do
        before { sign_in(create(:user, password: "123456")) }
        let!(:user) { { user: { email: "new_email@email.com", current_password: "126" } } }
        example "application/json", :bad_password, {
                  errors: { current_password: ["is invalid"] }
                }

        run_test!
      end

      response "422", "unprocessable entity" do
        before { sign_in(create(:user, password: "123456")) }
        let!(:user) { { user: { email: "new_email@email.com" } } }
        example "application/json", :bad_password, {
                  errors: { current_password: ["can't be blank"] }
                }

        run_test!
      end
    end
  end

  path "/signout" do
    delete "Sign out current user" do
      tags "Connection"
      security [bearer: {}]
      produces "application/json"

      response "200", "ok" do
        before { sign_in(create(:user)) }

        example "application/json", :example, {
                  message: "Logged out"
                }

        run_test!
      end

      response "401", "unauthorized" do
        example "application/json", :your_not_logged, {
                error: "You need to be logged"
                }

        run_test!
      end
    end
  end

  path "/users/google_sign_in" do
    post "Register or sign in a user" do
      tags "Connection"
      security [bearer: {}]
      consumes "application/json"
      produces "application/json"
      parameter name: :user, in: :body, schema: {
                  type: :object,
                  properties: {
                    user: {
                      type: :object,
                      properties: {
                        code: { type: :string,
                                example: "4/0AfgeXvtvzNummXDNRNVHSwtkNRmZ20Ha0DsVENfB1HF41HHUtBdtz-w02l7ci7mJQ86Kdg" },
                        redirect_uri: { type: :string, example: "http://localhost:8081" }
                      },
                      required: %w[code redirect_uri]
                    }
                  },
                  required: ["user"]
                }

      response "200", "ok" do
        let!(:user) {
          { user: { code: "4/0AfgeXvtvzNummXDNRNVHSwtkNRmZ20Ha0DsVENfB1HF41HHUtBdtz-w02l7ci7mJQ86Kdg", redirect_uri: "http://localhost:8081" } } }
        example "application/json", :valid_code, {
                  message: "Logged."
                }

        # run_test!
      end
      response "401", "unauthorized" do
        let!(:user) {
          { user: { code: "4/0AfgeXvtvzNummXDNRNVHSwtkNRmZ20Ha0DsVENfB1HF41HHUtBdtz-w02l7ci7mJQ86Kdg", redirect_uri: "http://localhost:8081" } } }
        example "application/json", :invalid_code, {
                  error: "invalid_grant",
                  error_description: "Bad Request"
                }

        run_test!
      end
    end
  end

  path "/users/refresh_token" do
    post "Use code to get refresh token and add it to user" do
      tags "Users"
      security [bearer: {}]
      consumes "application/json"
      produces "application/json"
      parameter name: :refresh_token, in: :body, schema: {
                  type: :object,
                  properties: {
                    refresh_token: {
                      type: :object,
                      properties: {
                        name: { type: :string, enum: %w[google spotify], example: "google" },
                        code: { type: :string,
                                example: "4/0AfgeXvtvzNummXDNRNVHSwtkNRmZ20Ha0DsVENfB1HF41HHUtBdtz-w02l7ci7mJQ86Kdg" },
                        redirect_uri: { type: :string, example: "http://localhost:8081" }
                      },
                      required: %w[name code redirect_uri]
                    }
                  },
                  required: ["refresh_token"]
                }
      response "200", "ok" do
        let!(:refresh_token) {
          { refresh_token: { name: "google",
                             code: "4/0AfgeXvtvzNummXDNRNVHSwtkNRmZ20Ha0DsVENfB1HF41HHUtBdtz-w02l7ci7mJQ86Kdg",
                             redirect_uri: "http://localhost:8081" } }
        }
        example "application/json", :valid_code, {
                  message: "Google token added to user"
                }
        # run_test!
      end

      response "401", "unauthorized" do
        let!(:refresh_token) {
          { refresh_token: { name: "google",
                             code: "4/0AfgeXvtvzNummXDNRNVHSwtkNRmZ20Ha0DsVENfB1HF41HHUtBdtz-w02l7ci7mJQ86Kdg",
                             redirect_uri: "http://localhost:8081" } }
        }
        example "application/json", :invalid_code, {
                  error: "invalid_grant",
                  error_description: "Bad Request"
                }

        run_test!
      end
    end
  end
end
