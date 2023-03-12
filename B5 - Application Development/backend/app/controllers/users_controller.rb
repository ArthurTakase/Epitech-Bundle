# frozen_string_literal: true

require "devise/jwt/test_helpers"

class UsersController < ApplicationController
  before_action :user_logged?, except: %i[ google_sign_in ]
  before_action :set_user, only: %i[ show update destroy ]
  before_action :is_admin?, only: %i[ index show update destroy ]

  # GET /users
  def index
    @users = User.all

    render json: @users
  end

  # GET /users/1
  def show
    render json: @user, include: "*.*.*"
  end

  # GET /current_user
  def show_current_user
    @user = current_user
    render json: @user, include: "*.*.*"
  end

  # PATCH /users/1
  def update
    if @user.update(user_params)
      render json: @user
    else
      render json: @user.errors, status: :unprocessable_entity
    end
  end

  # DELETE /users/1
  def destroy
    @user.destroy
  end

  # GET /users/reset_token
  def reset_token
    _raw, hashed = Devise.token_generator.generate(User, :reset_password_token)
    current_user.reset_token(hashed)

    render json: { token: hashed.to_s }
  end

  # DELETE /signout
  def signout
    sign_out current_user
    render json: { message: "Logged out." }, status: :ok
  end

  # POST /users/refresh_token
  def refresh_token
    res = current_user.send("request_token_from_#{code_params[:name]}", code_params)

    if res[:error]
      render json: { error: res[:error] }, status: :unauthorized and return
    end
    render json: { message: res[:message] }, status: :ok
  end

  # POST /users/google_sign_in
  def google_sign_in
    @user, error = User.sign_in_with_google(google_params)
    unless @user
      render json: error, status: :unauthorized and return
    end

    sign_in(@user)
    headers = Devise::JWT::TestHelpers.auth_headers({}, @user)
    response.set_header("Authorization", headers["Authorization"])
    render json: { message: "Logged" }
  end

  # POST /users/delete_token
  def delete_token
    res = current_user.delete_token(delete_token_params[:service_name])

    if res[:error]
      render json: { error: res[:error] }, status: :unauthorized and return
    end
    render json: { message: res[:message] }, status: :ok
  end

  private
    def google_params
      params.require(:user).permit(:code, :redirect_uri)
    end

    def code_params
      params.require(:refresh_token).permit(:name, :code, :redirect_uri)
    end

    # Use callbacks to share common setup or constraints between actions.
    def set_user
      @user = User.find(params[:id])
    rescue ActiveRecord::RecordNotFound
      render json: { error: "User not found" }, status: :not_found
    end

    # Only allow a list of trusted parameters through.
    def user_params
      params.require(:user).permit(:first_name, :last_name, :email, :admin, :password)
    end

    def delete_token_params
      params.require(:token).permit(:service_name)
    end

    def spotify_token_params
      params.require(:user).permit(:code, :redirect_uri)
    end

    def is_admin?
      unless current_user.admin
        render json: { message: "You are not admin." }, status: :unauthorized
      end
    end
end
