# frozen_string_literal: true

# == Schema Information
#
# Table name: widgets
#
#  id         :bigint           not null, primary key
#  active     :boolean          default(TRUE), not null
#  name       :string           not null
#  created_at :datetime         not null
#  updated_at :datetime         not null
#  user_id    :bigint
#
# Indexes
#
#  index_widgets_on_user_id  (user_id)
#
# Foreign Keys
#
#  fk_rails_...  (user_id => users.id)
#
class Widget < ApplicationRecord
  # Callbacks
  before_destroy :destroy_children
  after_create :capitalize_name

  # Validations
  validates :name, { length: { minimum: 1 } }
  validates :active, inclusion: { in: [true, false] }
  validate :name_available_for_this_user?

  # Associations
  belongs_to :user
  has_one :action
  has_one :reaction, through: :action

  # Scopes
  scope :activated, -> { where(active: true) }

  def disactivate
    update(active: false)
  end

  def activate
    update(active: true)
  end

  private
    def name_available_for_this_user?
      User.find(self.user_id).widgets.each do |widget|
        if widget.name.downcase == self.name.downcase && widget != self
          errors.add(:errors, "Widget name already used")
          return false
        end
      end
      true
    end

    def capitalize_name
      self.name.capitalize!
      self.save
    end

    def destroy_children
      self.reaction&.destroy
      self.action&.destroy
    end
end
