# frozen_string_literal: true

Rails.application.reloader.to_prepare do
  RouterReaction ||= Router.new
  RouterReaction.resolve(command: SendMailReactionCommand, handler: SendMailReactionCommandHandler.new)
  RouterReaction.resolve(command: DailyPhotoBgReactionCommand, handler: DailyPhotoBgReactionCommandHandler.new)
  RouterReaction.resolve(command: NewAlbumReactionCommand, handler: NewAlbumReactionCommandHandler.new)
  RouterReaction.resolve(command: LikePlaylistReactionCommand, handler: LikePlaylistReactionCommandHandler.new)
  RouterReaction.resolve(command: UpcomingReactionCommand, handler: UpcomingReactionCommandHandler.new)
  RouterReaction.resolve(command: DiscoverMovieReactionCommand, handler: DiscoverMovieReactionCommandHandler.new)
  RouterReaction.resolve(command: DailyPhotoMailReactionCommand, handler: DailyPhotoMailReactionCommandHandler.new)
  RouterReaction.resolve(command: CatReactionCommand, handler: CatReactionCommandHandler.new)
end
