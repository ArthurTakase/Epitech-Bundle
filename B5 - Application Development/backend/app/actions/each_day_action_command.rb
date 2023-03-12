# frozen_string_literal: true

class EachDayActionCommand
  def initialize(options)
    @action_id = options["action_id"]
    @last_day = options["last_day"] || Date.yesterday.to_s
  end

  def to_h
    { action_id: @action_id, last_day: @last_day }
  end
end
