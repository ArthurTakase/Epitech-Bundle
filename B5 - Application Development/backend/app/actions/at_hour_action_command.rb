# frozen_string_literal: true

class AtHourActionCommand
  def initialize(options)
    @action_id = options["action_id"]
    @widget_id = Action.find(@action_id).widget.id
    @hour = options["hour"]
  end

  def to_h
    { action_id: @action_id, widget_id: @widget_id, hour: @hour }
  end
end
