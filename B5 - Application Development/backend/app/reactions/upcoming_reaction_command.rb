# frozen_string_literal: true

class UpcomingReactionCommand
  def initialize(options)
    @reaction_id = options["reaction_id"]
    user = Reaction.find(@reaction_id).action.widget.user

    @user_id = user.id
    @token = user.google_token
    @email = user.email
  end

  def to_h
    { reaction_id: @reaction_id, user_id: @user_id, token: @token, email: @email }
  end
end
