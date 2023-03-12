# frozen_string_literal: true

class Bus
  def initialize(router)
    @router = router
  end

  def send_command(cmd)
    router.route(cmd).call cmd.to_h
  end

  alias << send_command
  attr_accessor :router
end
