# frozen_string_literal: true

class WidgetToDisable
  def initialize
    @liste = []
  end

  def append(widget_id)
    @liste.append(widget_id)
  end

  def call
    @liste.each do |widget_id|
      widget = Widget.find(widget_id)
      widget.disactivate
    end

    @liste.clear
  end
end
