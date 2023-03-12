# frozen_string_literal: true

Rails.application.reloader.to_prepare do
  RouterAction ||= Router.new
  RouterAction.resolve(command: AtHourActionCommand, handler: AtHourActionCommandHandler.new)
  RouterAction.resolve(command: EachDayActionCommand, handler: EachDayActionCommandHandler.new)
  RouterAction.resolve(command: EachHourActionCommand, handler: EachHourActionCommandHandler.new)
  RouterAction.resolve(command: EachMonthActionCommand, handler: EachMonthActionCommandHandler.new)
  RouterAction.resolve(command: TemperatureChangeActionCommand, handler: TemperatureChangeActionCommandHandler.new)
  RouterAction.resolve(command: WeatherChangeActionCommand, handler: WeatherChangeActionCommandHandler.new)
  RouterAction.resolve(command: PlaylistFollowActionCommand, handler: PlaylistFollowActionCommandHandler.new)
  RouterAction.resolve(command: EmailReceivedActionCommand, handler: EmailReceivedActionCommandHandler.new)
  RouterAction.resolve(command: NewEpisodeActionCommand, handler: NewEpisodeActionCommandHandler.new)
end
