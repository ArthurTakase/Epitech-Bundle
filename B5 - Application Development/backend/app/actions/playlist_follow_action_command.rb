# frozen_string_literal: true

class PlaylistFollowActionCommand
  def initialize(options, spotify = nil)
    @action_id = options["action_id"]
    @widget_id = Action.find(@action_id).widget.id
    @playlist = options["playlist_id"]
    @nb_follower = options["nb_follower"] || current_nb_follow(spotify)
  end

  def to_h
    { action_id: @action_id, widget_id: @widget_id, playlist: @playlist, nb_follower: @nb_follower }
  end

  private
    def current_nb_follow(spotify)
      spotify ||= SpotifyClient.new(nil)

      playlist = spotify.playlist_info(@playlist)
      playlist["followers"]["total"]
    end
end
