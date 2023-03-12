class Users::OmniauthCallbacksController < Devise::OmniauthCallbacksController
  def twitter
    @user = User.from_omniauth(request.env["omniauth.auth"])

    if @user
      render json: { message: "Connected" }, status: :ok
    else
      # session["devise.twitter_data"] = request.env["omniauth.auth"] # .except('extra')
      render json: { message: "Not Connected" }, status: :unauthorized
    end
  end

  def google_oauth2
    @user = User.from_omniauth(request.env["omniauth.auth"])
    #get refresh_token

    if @user
      # render json: { message: "Connected" }, status: :ok
      sign_in @user
      redirect_to controller: :sessions, action: :create
    else
      # session["devise.google_data"] = request.env["omniauth.auth"].except("extra") # Removing extra as it can overflow some session stores
      render json: { message: "Not Connected" }, status: :unauthorized
    end
  end

  def failure
    render json: { message: "Connection failed", error: params[:message] }, status: :unauthorized
  end
end
