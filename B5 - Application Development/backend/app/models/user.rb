# frozen_string_literal: true

# == Schema Information
#
# Table name: users
#
#  id                     :bigint           not null, primary key
#  admin                  :boolean          default(FALSE), not null
#  background             :string
#  cat                    :jsonb
#  email                  :string           not null
#  encrypted_password     :string           default(""), not null
#  first_name             :string           not null
#  google_token           :string
#  last_name              :string           not null
#  p_uid                  :string
#  picture                :string
#  provider               :string
#  remember_created_at    :datetime
#  reset_password_sent_at :datetime
#  reset_password_token   :string
#  songs                  :jsonb            not null
#  spotify_token          :string
#  twitter_token          :string
#  created_at             :datetime         not null
#  updated_at             :datetime         not null
#
# Indexes
#
#  index_users_on_email                 (email) UNIQUE
#  index_users_on_reset_password_token  (reset_password_token) UNIQUE
#

#  twitter_refresh_token  :string

#  songs                  :jsonb
#  spotify_token          :string

#  created_at             :datetime         not null
#  updated_at             :datetime         not null
#
# Indexes
#
#  index_users_on_email                 (email) UNIQUE
#  index_users_on_reset_password_token  (reset_password_token) UNIQUE
#

require "httparty"

class User < ApplicationRecord
  # Callbacks
  before_destroy :destroy_widgets
  before_create :init_songs

  # Validattions
  validates :email,
    format: { with: /(.+)@(.+)/, message: "Email invalid"  },
              uniqueness: { case_sensitive: false },
              length: { minimum: 4, maximum: 254 }

  # Associations
  has_many :widgets

  # Scope
  scope :administrators, -> { where(admin: true) }

  # Devise gem authentication
  devise :database_authenticatable,
         :jwt_authenticatable,
         :registerable,
         :recoverable, :rememberable, :validatable,
         :omniauthable, omniauth_providers: %i[twitter google_oauth2],
         jwt_revocation_strategy: JwtDenylist

  def request_token_from_spotify(params)
    info_spotify = HTTParty.post("https://accounts.spotify.com/api/token",
                                 body: spotify_body(params[:code], params[:redirect_uri]))
    puts info_spotify
    if info_spotify["error"]
      return { error: info_spotify["error_description"] }
    end
    self.spotify_token = info_spotify["refresh_token"]
    self.save
    { message: "Spotify token added to user" }
  end

  def request_token_from_twitter(params)
    result = HTTParty.post("https://accounts.google.com/o/oauth2/token", body: twitter_body(params[:code]))
    puts twitter_body(params[:code])
    if result["error"]
      return { error: result["error_description"] }
    end
    self.twitter_refresh_token = result["refresh_token"]
    self.save
    { message: "Twitter token added to user" }
  end

  def request_token_from_google(params)
    result = HTTParty.post("https://accounts.google.com/o/oauth2/token",
body: google_body(params[:code], params[:redirect_uri]))
    if result["error"]
      return { error: result["error_description"] }
    end
    self.google_token = result["refresh_token"]
    self.save
    { message: "Google token added to user" }
  end

  def reset_token(hashed)
    self.reset_password_token = Devise.token_generator.digest(User, :reset_password_token, hashed)
    self.reset_password_sent_at = Time.now
    self.save
  end

  def self.sign_in_with_google(params)
    result = HTTParty.post("https://accounts.google.com/o/oauth2/token",
                           body: google_body(params[:code], params[:redirect_uri]),
                           headers: { "content-type": "application/x-www-form-urlencoded" })

    return [nil, result] if result["error"]

    refresh_token = result["refresh_token"]
    result = HTTParty.post("https://accounts.google.com/o/oauth2/token", body: google_refresh_token_body(refresh_token),
                           headers: { "content-type": "application/x-www-form-urlencoded" })


    return [nil, result] if result["error"]

    access_token = result["access_token"]
    result = HTTParty.get("https://www.googleapis.com/oauth2/v2/userinfo?access_token=#{access_token}",
                           headers: { "content-type": "application/x-www-form-urlencoded", "Authorization": "Bearer" })

    return [nil, result] if result["error"]

    connection_from_oauth(result, "google", refresh_token)
  end

  def self.connection_from_oauth(auth, provider, token)
    user = User.find_or_create_by(p_uid: auth["id"]) do |user|
      user.email = auth["email"]
      user.password = "123456"
      user.first_name = auth["given_name"]
      user.last_name = auth["family_name"]
      user.picture = auth["picture"]
      user.provider = provider
    end
    user.send("#{provider}_token=", token)
    user.save
    user
  end

  def delete_token(name)
    self.send("#{name}_token=", nil)
    if self.save
      { message: "#{name.capitalize} token deleted" }
    else
      { error: "Error with #{name} token" }
    end
  end

  private
    def self.google_refresh_token_body(refresh_token)
      { grant_type: "refresh_token",
        client_id: ENV["GOOGLE_CLIENT_ID"],
        client_secret: ENV["GOOGLE_CLIENT_SECRET"],
        refresh_token: refresh_token }
    end

    def self.google_access_token_body(access_token)
      { client_id: ENV["GOOGLE_CLIENT_ID"],
        client_secret: ENV["GOOGLE_CLIENT_SECRET"],
        access_token: access_token }
    end

    def self.google_body(code, redirect_uri)
      { code: code,
        client_id: ENV["GOOGLE_CLIENT_ID"],
        client_secret: ENV["GOOGLE_CLIENT_SECRET"],
        grant_type: "authorization_code",
        redirect_uri: redirect_uri }
    end

    def google_body(code, redirect_uri)
      { code: code,
        client_id: ENV["GOOGLE_CLIENT_ID"],
        client_secret: ENV["GOOGLE_CLIENT_SECRET"],
        grant_type: "authorization_code",
        redirect_uri: redirect_uri }
    end

    def spotify_body(code, redirect_uri)
      { client_id: ENV["SPOTIFY_CLIENT_ID"],
        client_secret: ENV["SPOTIFY_CLIENT_SECRET"], code: code,
        grant_type: "authorization_code",
        redirect_uri: redirect_uri }
    end


    def self.twitter_body(code)
      { "code" => code,
        "client_id"     => ENV["TWITTER_API_PUBLIC"],
        "client_secret" => ENV["TWITTER_API_SECRET"],
        "grant_type"    => "authorization_code" }
    end

    def destroy_widgets
      self.widgets.map(&:destroy)
    end

    def init_songs
      self.songs = {}
    end
end
