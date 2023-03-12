# frozen_string_literal: true

class LikePlaylistReactionCommandHandler
  def initialize
  end

  def call(attributes, spotify = nil)
    puts "Like Playlist Command Handler" unless Rails.env.test?

    user = User.find(attributes[:user_id])

    spotify ||= SpotifyClient.new(user.spotify_token)

    begin
      spotify.create_playlist_liked_songs
    rescue Exception => e
      puts e.message unless Rails.env.test?
      return
    end
    puts "LETS GOOOOOOOOOOOOOOOOOOOOO" unless Rails.env.test?
  end
end
