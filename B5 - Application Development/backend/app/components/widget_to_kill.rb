# frozen_string_literal: true

class WidgetToKill
  def initialize
    @liste = []
  end

  def append(widget_id)
    @liste.append(widget_id)
  end

  def call
    @liste.each do |widget_id|
      Widget.find(widget_id)&.destroy
    end

    @liste.clear
  end
end
