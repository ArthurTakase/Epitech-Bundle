require "rails_helper"

RSpec.describe PlaylistFollowActionCommandHandler do
  describe "playlist_follow" do
    let(:current_nb_followers) { 20 }
    let(:widget) { create(:widget) }
    let(:action) { create(:action, widget_id: widget.id) }
    let(:playlist_id) { "234htkjrz3" }
    let(:spotify_service) { SpotifyClientTest.new(nil, current_nb_followers.to_s) }

    context "when current_nb_follower is given" do
      context "when nb_follower has changed" do
        let(:options) {
          { "action_id"=>action.id, "playlist_id"=>playlist_id, "nb_follower"=>(current_nb_followers+5).to_s } }

        it "returns true" do
          command = PlaylistFollowActionCommand.new(options)
          handler = PlaylistFollowActionCommandHandler.new

          expect(handler.call(command.to_h, spotify_service)).to eq(true)
        end
      end

      context "when nb_follower is the same" do
        let(:options) {
          { "action_id"=>action.id, "playlist_id"=>playlist_id, "nb_follower"=>current_nb_followers.to_s } }

        it "returns false" do
          command = PlaylistFollowActionCommand.new(options)
          handler = PlaylistFollowActionCommandHandler.new

          expect(handler.call(command.to_h, spotify_service)).to eq(false)
        end
      end
    end

    context "when current_nb_follower isn't given" do
      let(:options) { { "action_id"=>action.id, "playlist_id"=>playlist_id } }

      it "returns false" do
        command = PlaylistFollowActionCommand.new(options, spotify_service)
        handler = PlaylistFollowActionCommandHandler.new

        expect(handler.call(command.to_h, spotify_service)).to eq(false)
      end
    end

    context "when playlist_id is nil" do
      let(:options) { { "action_id"=>action.id, "playlist_id"=>nil } }

      it "returns false" do
        command = PlaylistFollowActionCommand.new(options, spotify_service)
        handler = PlaylistFollowActionCommandHandler.new

        expect(handler.call(command.to_h, spotify_service)).to eq(false)
      end
    end
  end
end
