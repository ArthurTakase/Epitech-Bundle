# frozen_string_literal: true

class EachHourActionCommand
  def initialize(options)
    @action_id = options["action_id"]
    @last_hour = options["last_hour"] || (Time.now-1.hour).end_of_hour.to_s
  end

  def to_h
    { action_id: @action_id, last_hour: @last_hour }
  end
end
