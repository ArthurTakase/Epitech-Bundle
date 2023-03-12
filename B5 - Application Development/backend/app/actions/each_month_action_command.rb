# frozen_string_literal: true

class EachMonthActionCommand
  def initialize(options)
    @action_id = options["action_id"]
    @last_month = options["last_month"] || Date.today.prev_month.to_s
  end

  def to_h
    { action_id: @action_id, last_month: @last_month }
  end
end
