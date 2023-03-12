# == Schema Information
#
# Table name: users
#
#  id                     :bigint           not null, primary key
#  admin                  :boolean          default(FALSE), not null
#  background             :string
#  cat                    :jsonb
#  email                  :string           not null
#  encrypted_password     :string           default(""), not null
#  first_name             :string           not null
#  google_token           :string
#  last_name              :string           not null
#  p_uid                  :string
#  picture                :string
#  provider               :string
#  remember_created_at    :datetime
#  reset_password_sent_at :datetime
#  reset_password_token   :string
#  songs                  :jsonb            not null
#  spotify_token          :string
#  twitter_token          :string
#  created_at             :datetime         not null
#  updated_at             :datetime         not null
#
# Indexes
#
#  index_users_on_email                 (email) UNIQUE
#  index_users_on_reset_password_token  (reset_password_token) UNIQUE
#
require "rails_helper"

RSpec.describe User, type: :model do
  context "create a user valid" do
    subject { create(:user) }

    it "should persist a new user" do
      expect { subject }.to change(User, :count).by(1)
    end

    it "should not be admin" do
      expect(subject.admin).to be_falsey
    end

    it "has a relation to widgets" do
      expect(subject).to respond_to(:widgets)
    end
  end
end
