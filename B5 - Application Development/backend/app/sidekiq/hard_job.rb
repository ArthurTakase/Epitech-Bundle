# frozen_string_literal: true

require "sidekiq-scheduler"

class HardJob
  include Sidekiq::Job

  def perform(*args)
    user_job

    Widget_to_kill.call
    Widget_to_disable.call
  end

  private
    def user_job
      User.all.each do |user|
        puts user.inspect
        user.widgets.activated.each do |widget|
          action = widget.action
          action_cmd = action.klass_command.constantize.send(:new, action.options)

          next unless Bus_actions << action_cmd

          reaction = action.reaction
          reaction_cmd = reaction.klass_command.constantize.send(:new, reaction.options)
          Bus_reactions << reaction_cmd
        end
      end
    end
end
