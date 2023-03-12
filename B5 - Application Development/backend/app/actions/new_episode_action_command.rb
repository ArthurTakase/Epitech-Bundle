# frozen_string_literal: true

class NewEpisodeActionCommand
  def initialize(options)
    @action_id = options["action_id"]
    @widget_id = Action.find(@action_id).widget.id
    @show_id = options["show_id"]
  end

  def to_h
    { action_id: @action_id, widget_id: @widget_id, show_id: @show_id }
  end
end
