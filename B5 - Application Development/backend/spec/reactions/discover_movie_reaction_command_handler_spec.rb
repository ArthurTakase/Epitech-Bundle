require "rails_helper"

RSpec.describe DiscoverMovieReactionCommandHandler do
  describe "#DiscoverMovieReaction" do
    let(:email) { "test@email.com" }
    let(:widget) { create(:widget, user_id: user.id) }
    let(:action) { create(:action, widget_id: widget.id) }
    let(:reaction) { create(:reaction, action_id: action.id) }
    let(:mocked_response) { { "page"=>1,
        "results"=>
         [{ "adult"=>false,
           "backdrop_path"=>"/ttsFffDoso5BIqNugMoQDBI9A34.jpg",
           "genre_ids"=>[10402, 99],
           "id"=>939984,
           "original_language"=>"ko",
           "original_title"=>"BTS Permission to Dance On Stage - Seoul: Live Viewing",
           "overview"=>
            "Rejoignez-nous pour une expérience incontournable où BTS et les ARMY ne formeront plus qu’un avec la musique et la danse lors du concert diffusé en direct de Séoul dans les cinémas du monde entier !",
           "popularity"=>7.956,
           "poster_path"=>"/fJW3YaGPg5TatAG5Gugz4QWO6d3.jpg",
           "release_date"=>"2022-03-12",
           "title"=>"BTS Permission to dance on stage - Seoul : Live viewing",
           "video"=>true,
           "vote_average"=>9.2,
           "vote_count"=>100 }] }}
    let(:options) {
        { "reaction_id"=>reaction.id, "language"=>"en.US", "region"=>"FR", "adult"=>"false", "min_date"=>"2001",
          "min_score"=>"5" } }
    context "when the user has token" do
      let(:gmail) { GmailClientTest.new(token, user.email) }
      let(:user) { create(:user, google_token: token, email: email) }
      let(:token) { FFaker::Internet.password }
      let(:expected_mail) {
          "RnJvbTogPHRlc3RAZW1haWwuY29tPgogIFRvOiA8dGVzdEBlbWFpbC5jb20-CiAgU3ViamVjdDogQVJFQSBNb3ZpZSBSZWNvbW1hbmRhdGlvbiAoMTMvMTEvMjAyMikKICBDb250ZW50LXR5cGU6IHRleHQvaHRtbDtjaGFyc2V0PXV0Zi04CgogIDwhZG9jdHlwZSBodG1sPgo8aHRtbD4KICA8aGVhZD4KICAgIDxtZXRhIG5hbWU9J3ZpZXdwb3J0JyBjb250ZW50PSd3aWR0aD1kZXZpY2Utd2lkdGgsIGluaXRpYWwtc2NhbGU9MS4wJy8-CiAgICA8bWV0YSBodHRwLWVxdWl2PSdDb250ZW50LVR5cGUnIGNvbnRlbnQ9J3RleHQvaHRtbDsgY2hhcnNldD1VVEYtOCcgLz4KICAgIDx0aXRsZT5TaW1wbGUgVHJhbnNhY3Rpb25hbCBFbWFpbDwvdGl0bGU-CiAgPC9oZWFkPgogIDxib2R5PgogICAgPGRpdiBzdHlsZT0ndGV4dC1hbGlnbjogY2VudGVyOyc-CiAgICAgIDxoMT48dT5CVFMgUGVybWlzc2lvbiB0byBkYW5jZSBvbiBzdGFnZSAtIFNlb3VsIDogTGl2ZSB2aWV3aW5nPC91PjwvaDE-CiAgICAgIDxpPjIwMjItMDMtMTI8L2k-CiAgICAgIDxwPlJlam9pZ25lei1ub3VzIHBvdXIgdW5lIGV4cMOpcmllbmNlIGluY29udG91cm5hYmxlIG_DuSBCVFMgZXQgbGVzIEFSTVkgbmUgZm9ybWVyb250IHBsdXMgcXXigJl1biBhdmVjIGxhIG11c2lxdWUgZXQgbGEgZGFuc2UgbG9ycyBkdSBjb25jZXJ0IGRpZmZ1c8OpIGVuIGRpcmVjdCBkZSBTw6lvdWwgZGFucyBsZXMgY2luw6ltYXMgZHUgbW9uZGUgZW50aWVyICE8L3A-CiAgICAgIDxpbWcgc3JjPSdodHRwczovL2ltYWdlLnRtZGIub3JnL3QvcC93NTAwL2ZKVzNZYUdQZzVUYXRBRzVHdWd6NFFXTzZkMy5qcGcnIGhlaWdodD0nMzAwcHgnLz48YnIvPgogICAgICA8YSBocmVmPSdodHRwczovL3d3dy50aGVtb3ZpZWRiLm9yZy9tb3ZpZS85Mzk5ODQnIHRhcmdldD0nX2JsYW5rJz5QbHVzIGQnaW5mb3M8L2E-CiAgICA8L2Rpdj4KICA8L2JvZHk-CjwvaHRtbD4=" }
      it "sends mail" do
        command = DiscoverMovieReactionCommand.new(options)
        handler = DiscoverMovieReactionCommandHandler.new
        expect { handler.call(command.to_h, gmail, mocked_response) }.to change(gmail, :send_mail_request).by(1)
        expect(gmail.last_mail).to eq(expected_mail)
      end
    end

    context "when the user hasn't token" do
      let(:gmail) { GmailClientTest.new(nil, user.email) }
      let(:user) { create(:user, google_token: nil, email: email) }
      it "sends mail" do
        command = DiscoverMovieReactionCommand.new(options)
        handler = DiscoverMovieReactionCommandHandler.new
        expect { handler.call(command.to_h, gmail, mocked_response) }.not_to change(gmail, :send_mail_request)
      end
    end
  end
end
