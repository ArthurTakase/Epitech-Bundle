class WidgetsController < ApplicationController
  before_action :user_logged?, only: %i[ create update destroy ]
  before_action :set_widget, only: %i[ show update destroy ]

  # GET /widgets
  def index
    @widgets = Widget.all

    render json: @widgets
  end

  # GET /widgets/1
  def show
    render json: @widget
  end

  # POST /widgets
  def create
    # Create Widget
    @widget = Widget.new(name: widget_params[:name], user_id: current_user.id)
    action_params = widget_params[:action]
    reaction_params = widget_params[:reaction]

    unless action_params && reaction_params
      render json: { message: "Params missing" }, status: :unprocessable_entity and return
    end
    unless @widget.save
      render json: @widget.errors, status: :unprocessable_entity and return
    end

    # Create Action
    @action = Action.new(klass: action_params[:name], options: action_params[:options], widget_id: @widget.id)

    unless @action.save
      @widget.destroy
      render json: @action.errors, status: :unprocessable_entity and return
    end

    # Create Reaction
    @reaction = Reaction.new(klass: reaction_params[:name], options: reaction_params[:options], action_id: @action.id)
    unless @reaction.save
      @widget.destroy
      render json: @reaction.errors, status: :unprocessable_entity and return
    end

    render json: @widget, status: :created, location: @widget
  end

  # PATCH/PUT /widgets/1
  def update
    action_params = widget_params[:action]
    reaction_params = widget_params[:reaction]

    # Check params
    unless @widget
      render json: { message: "Widget with id #{params[:id]} not found" }, status: :not_found and return
    end

    # Update Widget
    unless @widget.update(name: widget_params[:name], active: (widget_params[:active]))
      render json: @widget.errors, status: :unprocessable_entity and return
    end

    # Update Action
    action = @widget.action
    if action_params && !action.update(klass: action_params[:name], options: action_params[:options])
      render json: action.errors, status: :unprocessable_entity and return
    end

    # Update Reaction
    reaction = action.reaction
    if reaction_params && !reaction.update(klass: reaction_params[:name], options: reaction_params[:options])
      render json: reaction.errors, status: :unprocessable_entity and return
    end

    render json: @widget, status: :ok, location: @widget
  end

  # DELETE /widgets/1
  def destroy
    @widget.destroy
  end

  private
    # Use callbacks to share common setup or constraints between actions.
    def set_widget
      @widget = Widget.find(params[:id])
    rescue ActiveRecord::RecordNotFound
      render json: { error: "Widget not found" }, status: :not_found
    end

    # Only allow a list of trusted parameters through.
    def widget_params
      params.require(:widget).permit(:name, :active, :user_id, action: {}, reaction: {})
    end
end
