require "rails_helper"

RSpec.describe NewAlbumReactionCommandHandler do
  describe "new_album" do
    let(:widget) { create(:widget, user_id: user.id) }
    let(:action) { create :action, widget_id: widget.id }
    let(:reaction) { create(:reaction, action_id: action.id) }
    let(:options) { { "reaction_id" => reaction.id } }

    context "user have a token" do
      let(:token) { FFaker::Internet.password }
      let(:user) { create(:user, spotify_token: token) }
      let(:spotify_service) { SpotifyClientTest.new(token) }

      it "change user's attribut songs" do
        command = NewAlbumReactionCommand.new(options)
        handler = NewAlbumReactionCommandHandler.new
        expected_songs = { "albums"=>[
                             { "url"=>"https://open.spotify.com/album/5xpWrRABn5rpscaaVETrzY",
                               "image"=>"https://i.scdn.co/image/ab67616d0000b2738a5b393a9cbc2a38e80c51a4",
                               "title"=>"L'école de la vie", "artist"=>"Kendji Girac" },
                           ]
                         }

        handler.call(command.to_h, spotify_service)
        expect(user.reload.songs).to eq(expected_songs)
      end
    end

    context "user doesn't have a token" do
      let(:user) { create(:user) }
      let(:spotify_service) { SpotifyClientTest.new(nil) }

      it "change user's attribut songs" do
        command = NewAlbumReactionCommand.new(options)
        handler = NewAlbumReactionCommandHandler.new
        expected_songs = { "albums"=>[
                             { "url"=>"https://open.spotify.com/album/5xpWrRABn5rpscaaVETrzY",
                               "image"=>"https://i.scdn.co/image/ab67616d0000b2738a5b393a9cbc2a38e80c51a4",
                               "title"=>"L'école de la vie", "artist"=>"Kendji Girac" },
                           ]
                         }

        handler.call(command.to_h, spotify_service)
        expect(user.reload.songs).to eq(expected_songs)
      end
    end
  end
end
