require "rails_helper"

RSpec.describe PlaylistFollowActionCommand do
  describe "#to_h" do
    let(:widget) { create(:widget) }
    let(:action) { create(:action, widget_id: widget.id) }
    let(:playlist_id) { "234htkjrz3" }

    context "when nb_follower is given" do
      let(:options) { { "action_id"=>action.id, "playlist_id"=>playlist_id, "nb_follower"=>"10" } }

      it "returns a valid_hash" do
        command = PlaylistFollowActionCommand.new(options)

        expect(command.to_h).to eq({ action_id: action.id, widget_id: widget.id, playlist: playlist_id,
                                     nb_follower: "10" })
      end
    end
    context "when nb_follower is given" do
      let(:options) { { "action_id"=>action.id, "playlist_id"=>playlist_id } }
      let(:spotify_service) { SpotifyClientTest.new(nil, "24") }

      it "returns a valid_hash" do
        command = PlaylistFollowActionCommand.new(options, spotify_service)

        expect(command.to_h).to eq({ action_id: action.id, widget_id: widget.id, playlist: playlist_id,
                                     nb_follower: "24" })
      end
    end
  end
end
