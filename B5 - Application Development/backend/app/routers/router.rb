# frozen_string_literal: true

class Router
  def initialize
    @router = {}
  end

  def resolve(command:, handler:)
    @router[command] = handler
  end

  def route(cmd)
    @router[cmd.class]
  end
end
