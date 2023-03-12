# frozen_string_literal: true

class SpotifyClient
  def initialize(token)
    @token = token
  end

  def playlist_info(playlist_id)
    return if playlist_id.nil?

    response = HTTParty.get(
      "https://api.spotify.com/v1/playlists/#{playlist_id}",
        "headers": { "Authorization": "Bearer #{app_access_token}" }
      )

    response
  end

  def new_release
    HTTParty.get(
      "https://api.spotify.com/v1/browse/new-releases?limit=5",
      "headers": { "Authorization": "Bearer #{app_access_token}" }
    )
  end

  def user_id
    return if @token.nil?

    HTTParty.get("https://api.spotify.com/v1/me",
                 headers: { "Authorization": "Bearer #{user_access_token}" })
  end

  def create_playlist_liked_songs
    date = DateTime.now.strftime("%d/%m/%Y")

    playlist = HTTParty.post(
      "https://api.spotify.com/v1/users/#{user_id['id']}/playlists",
      body: {
        name: "Favourite titles #{date}",
        description: "All your favourite music (#{date}). Generated with AREA",
        public: false
      }.to_json,
      headers: {
        "Accept"=> "application/json",
        "Content-Type"=> "application/json",
        "Authorization"=> "Bearer #{user_access_token}"
      }
    )
    unless playlist["id"]
      raise StandardError.new("Error: Spotify return null")
    end

    # get liked songs
    offset = 0

    loop do
      tracks = ""
      songs = HTTParty.get(
        "https://api.spotify.com/v1/me/tracks?limit=50&offset=#{offset}",
        "headers": { "Authorization": "Bearer #{user_access_token}" }
      )

      unless songs["items"]
        raise StandardError.new("Error: Spotify return null")
      end

      songs["items"].each do |song|
        tracks += song["track"]["uri"] + ","
      end

      HTTParty.post(
        "https://api.spotify.com/v1/playlists/#{playlist["id"]}/tracks?uris=#{CGI.escape tracks[0..-2]}",
        "headers": { "Authorization": "Bearer #{user_access_token}" }
      )

      offset += 50
      break if songs["items"].length == 0
    end
  end

  private
    def app_access_token
      @app_access_token ||= HTTParty.post(
        "https://accounts.spotify.com/api/token",
          "body": "grant_type=client_credentials&client_id=#{ENV["SPOTIFY_CLIENT_ID"]}&client_secret=#{ENV["SPOTIFY_CLIENT_SECRET"]}"
        )["access_token"]
    end

    def user_access_token
      @user_access_token ||= HTTParty.post("https://accounts.spotify.com/api/token", body: body)["access_token"]
    end

    def body
      { client_id: ENV["SPOTIFY_CLIENT_ID"],
      client_secret: ENV["SPOTIFY_CLIENT_SECRET"],
      grant_type: "refresh_token",
      refresh_token: @token }
    end
end
