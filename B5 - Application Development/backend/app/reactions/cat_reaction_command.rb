# frozen_string_literal: true

class CatReactionCommand
  def initialize(options)
    @reaction_id = options["reaction_id"]
    @user_id = Reaction.find(@reaction_id).action.widget.user.id
  end

  def to_h
    { reaction_id: @reaction_id, user_id: @user_id }
  end
end
