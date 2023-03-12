# frozen_string_literal: true

class SpotifyClientTest
  def initialize(token, playlist_total_followers = "10")
    @token = token
    @user_id_requests = 0
    @new_release_requests = 0
    @playlist_info_requests = 0
    @create_playlist_liked_songs_requests = 0
    @playlist_total_followers = playlist_total_followers
  end

  def playlist_info(playlist_id)
    @playlist_info_requests += 1

    { "followers"=> { "total" => @playlist_total_followers } }
  end

  def new_release
    @new_release_requests += 1
    { "albums"=>
      { "href"=>"https://api.spotify.com/v1/browse/new-releases?country=FR&offset=0&limit=5",
       "items"=>
        [{ "album_type"=>"album",
          "artists"=>
           [{ "external_urls"=>{ "spotify"=>"https://open.spotify.com/artist/4IS4EyXNmiI2w5SRCjMtEF" },
             "href"=>"https://api.spotify.com/v1/artists/4IS4EyXNmiI2w5SRCjMtEF",
             "id"=>"4IS4EyXNmiI2w5SRCjMtEF",
             "name"=>"Kendji Girac",
             "type"=>"artist",
             "uri"=>"spotify:artist:4IS4EyXNmiI2w5SRCjMtEF" }],
          "available_markets"=>
           ["AD", "XK", "ZA", "ZM", "ZW"],
          "external_urls"=>{ "spotify"=>"https://open.spotify.com/album/5xpWrRABn5rpscaaVETrzY" },
          "href"=>"https://api.spotify.com/v1/albums/5xpWrRABn5rpscaaVETrzY",
          "id"=>"5xpWrRABn5rpscaaVETrzY",
          "images"=>
           [{ "height"=>640, "url"=>"https://i.scdn.co/image/ab67616d0000b2738a5b393a9cbc2a38e80c51a4", "width"=>640 },
            { "height"=>300, "url"=>"https://i.scdn.co/image/ab67616d00001e028a5b393a9cbc2a38e80c51a4", "width"=>300 },
            { "height"=>64, "url"=>"https://i.scdn.co/image/ab67616d000048518a5b393a9cbc2a38e80c51a4", "width"=>64 }],
          "name"=>"L'école de la vie",
          "release_date"=>"2022-11-10",
          "release_date_precision"=>"day",
          "total_tracks"=>11,
          "type"=>"album",
          "uri"=>"spotify:album:5xpWrRABn5rpscaaVETrzY" }]
      }
    }
  end

  def user_id
    @user_id_requests += 1

    { "country"=>"FR",
     "display_name"=>"User name",
     "email"=>"User email",
     "explicit_content"=>{ "filter_enabled"=>false, "filter_locked"=>false },
     "external_urls"=>{ "spotify"=>"https://open.spotify.com/user/user_pseudo" },
     "followers"=>{ "href"=>nil, "total"=>2 },
     "href"=>"https://api.spotify.com/v1/users/user_pseudo",
     "id"=>"user_speudo",
     "images"=>
      [{ "height"=>nil,
        "url"=>
         "https://scontent-frx5-1.xx.fbcdn.net/v/t1.6435-1/68834295_2951715018234899_2574324189435527168_n.jpg?stp=dst-jpg_p320x320&_nc_cat=111&ccb=1-7&_nc_sid=0c64ff&_nc_ohc=ZtmtNngfXgQAX-QEhb5&_nc_ht=scontent-frx5-1.xx&edm=AP4hL3IEAAAA&oh=00_AfDk96-CLnWjs0JDO6nnf5YH_k-Rhy2ykDN4MQm4dC82aA&oe=6397CBEB",
        "width"=>nil }],
     "product"=>"premium",
     "type"=>"user",
     "uri"=>"spotify:user:user_pseudo" }
  end

  def create_playlist_liked_songs
    raise StandardError.new("Error: Spotify return null") if @token.nil?

    @create_playlist_liked_songs_requests += 1
  end

  attr_reader :create_playlist_liked_songs_requests, :user_id_requests, :new_release_requests
end
