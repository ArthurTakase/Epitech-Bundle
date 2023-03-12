# == Schema Information
#
# Table name: reactions
#
#  id         :bigint           not null, primary key
#  klass      :string           not null
#  options    :jsonb            not null
#  created_at :datetime         not null
#  updated_at :datetime         not null
#  action_id  :bigint
#
# Indexes
#
#  index_reactions_on_action_id  (action_id)
#
# Foreign Keys
#
#  fk_rails_...  (action_id => actions.id)
#
class Reaction < ApplicationRecord
  # Callbacks
  after_create :add_id_information

  # Validations
  validate :klass_exist?

  # Associations
  belongs_to :action


  def klass_command
    klass.camelize+"ReactionCommand"
  end

  private
    def klass_exist?
      (klass.camelize+"ReactionCommand").constantize
    rescue NameError
      errors.add(:errors, "Reaction '#{klass}' doesn't exist")
      false
    else
      true
    end

    def add_id_information
      self.options["reaction_id"] = self.id
      self.save
    end
end
