require "rails_helper"

RSpec.describe DiscoverMovieReactionCommand do
  describe "#to_h" do
    let(:widget) { create(:widget, user_id: user.id) }
    let(:action) { create(:action, widget_id: widget.id) }
    let(:user) { create(:user) }
    let(:reaction) { create(:reaction, action_id: action.id) }
    context "when all options are given" do
      let(:options) {
          { "reaction_id"=>reaction.id, "language"=>"en.US", "region"=>"FR", "adult"=>"false", "min_date"=>"2001",
            "min_score"=>"5" } }
      it "return valid hash" do
        command = DiscoverMovieReactionCommand.new(options)
        expect(command.to_h).to eq({ reaction_id: reaction.id, user_id: user.id, language: "en.US",
                                     region: "FR", adult: "false", min_date: "2001", min_score: "5" })
      end
    end

    context "when options aren't given" do
      let(:options) { { "reaction_id"=>reaction.id } }
      it "return valid hash" do
        command = DiscoverMovieReactionCommand.new(options)
        expect(command.to_h).to eq({ reaction_id: reaction.id, user_id: user.id, language: "fr-FR",
                                     region: "FR", adult: "false", min_date: "1975", min_score: "7" })
      end
    end
  end
end
