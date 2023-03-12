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
class UserSerializer < ActiveModel::Serializer
  attributes :id, :first_name, :last_name, :email, :admin, :background, :songs, :picture, :google_token, :spotify_token, :cat

  def google_token
    !object.google_token.nil?
  end

  def spotify_token
    !object.spotify_token.nil?
  end

  has_many :widgets
end
