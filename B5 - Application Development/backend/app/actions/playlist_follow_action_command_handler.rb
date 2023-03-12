# frozen_string_literal: true

class PlaylistFollowActionCommandHandler
  def initialize
  end

  def call(attributes, spotify = nil)
    puts "Playlist Follow Command Handler" unless Rails.env.test?

    spotify ||= SpotifyClient.new(nil)
    playlist = spotify.playlist_info(attributes[:playlist])

    unless playlist["followers"]
      puts "Error: Spotify return null" unless Rails.env.test?
      return false
    end

    current_follow = playlist["followers"]["total"].to_i
    last_follow = attributes[:nb_follower].to_i
    result = current_follow != last_follow

    puts "Follow Changed: #{result}" if result and !Rails.env.test?

    action = Action.find(attributes[:action_id])
    action.options["nb_follower"] = current_follow.to_s
    action.save

    result
  end
end
