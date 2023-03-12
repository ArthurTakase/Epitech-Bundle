# frozen_string_literal: true

class SendMailReactionCommand
  def initialize(options)
    @reaction_id = options["reaction_id"]

    user = Reaction.find(@reaction_id).action.widget.user
    @token = user.google_token
    @email = user.email
    @to = options["receiver"]
    @subject = options["object"]
    @body = options["message"]
  end

  def to_h
    { reaction_id: @reaction_id, token: @token, email: @email, to: @to, subject: @subject, body: @body }
  end
end
