# frozen_string_literal: true

class DiscoverMovieReactionCommand
  def initialize(options)
    @reaction_id = options["reaction_id"]
    @user_id = Reaction.find(@reaction_id).action.widget.user.id
    @language = options["language"] || "fr-FR"
    @region = options["region"] || "FR"
    @adult = options["adult"] || "false"
    @min_date = options["min_date"] || "1975"
    @min_score = options["min_score"] || "7"
  end

  def to_h
    {
      reaction_id: @reaction_id,
      user_id: @user_id,
      language: @language,
      region: @region,
      adult: @adult,
      min_date: @min_date,
      min_score: @min_score
    }
  end
end

