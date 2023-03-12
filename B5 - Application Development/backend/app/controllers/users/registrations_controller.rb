class Users::RegistrationsController < Devise::RegistrationsController
  before_action :is_admin?, only: [:destroy]
  respond_to :json

    private
      def respond_with(resource, _opts = {})
        resource.persisted? ? register_success : register_failed
      end
      def register_success
        render json: { message: "Signed up." }
      end
      def register_failed
        render json: { message: "Signed up failure." }
      end
      def is_admin?
        unless current_user.admin
          render json: { message: "You are not admin." }, status: :unauthorized
        end
      end
end
