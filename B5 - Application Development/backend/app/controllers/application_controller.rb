require "httparty"

class ApplicationController < ActionController::API
  before_action :configure_permitted_parameters, if: :devise_controller?
  respond_to :json

  def about
    about = JSON.parse(File.read("private/about.json"))
    current_timestamp = Time.now.getutc.to_i
    services = about["server"]["services"]
    about["server"] = { "current_time"=>current_timestamp, "services"=>services }
    render json: JSON.pretty_generate(about)
  end


  protected
    def configure_permitted_parameters
      devise_parameter_sanitizer.permit(:account_update, keys: %i[password password_confirmation current_password])
      devise_parameter_sanitizer.permit(:sign_up, keys: %i[first_name last_name admin])
    end

    def user_logged?
      unless user_signed_in?
        render json: { "error": "You need to be logged" }, status: :unauthorized
      end
    end
end
