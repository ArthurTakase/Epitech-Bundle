class ActionsController < ApplicationController
  before_action :set_action, only: [ :show ]

  # GET /actions
  def index
    @actions = Action.all

    render json: @actions
  end

  # GET /actions/1
  def show
    render json: @action
  end

  private
    # Use callbacks to share common setup or constraints between actions.
    def set_action
      @action = Action.find(params[:id])
    end
end
