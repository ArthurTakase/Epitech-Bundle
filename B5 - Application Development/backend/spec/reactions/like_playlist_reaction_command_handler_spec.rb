require "rails_helper"

RSpec.describe LikePlaylistReactionCommandHandler do
  describe "like_playing" do
    let(:widget) { create(:widget, user_id: user.id) }
    let(:action) { create :action, widget_id: widget.id }
    let(:reaction) { create(:reaction, action_id: action.id) }
    let(:options) { { "reaction_id" => reaction.id } }
    context "user have a token" do
      let(:token) { FFaker::Internet.password }
      let(:user) { create(:user, spotify_token: token) }
      let(:spotify_service) { SpotifyClientTest.new(token) }

      it "create a playlist with liked songs" do
        command = LikePlaylistReactionCommand.new(options)
        handler = LikePlaylistReactionCommandHandler.new

        expect {
          handler.call(command.to_h,
                       spotify_service) }.to change(spotify_service, :create_playlist_liked_songs_requests).by(1)
      end
    end

    context "user doesn't have token" do
      let(:user) { create(:user) }
      let(:spotify_service) { SpotifyClientTest.new(nil) }

      it "create a playlist with liked songs" do
        command = LikePlaylistReactionCommand.new(options)
        handler = LikePlaylistReactionCommandHandler.new

        expect {
          handler.call(command.to_h,
                       spotify_service) }.not_to change(spotify_service, :create_playlist_liked_songs_requests)
      end
    end
  end
end
