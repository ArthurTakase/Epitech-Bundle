require "rails_helper"

RSpec.describe DailyPhotoBgReactionCommandHandler do
  describe "daily_photo_bg" do
    let(:user) { create(:user) }
    let(:widget) { create(:widget, user_id: user.id) }
    let(:action) { create(:action, widget_id: widget.id) }
    let(:reaction) { create(:reaction, action_id: action.id) }
    let(:options) { { "reaction_id" => reaction.id } }
    let(:mocked_response) {
      { "copyright"=>"Stan Honda",
       "date"=>"2022-11-12",
       "explanation"=>
       "A darker Moon sets over Manhattan in this night skyscape. The 16 frame composite was assembled from consecutive exposures recorded during the November 8 total lunar eclipse. In the timelapse sequence stars leave short trails above the urban skyline, while the Moon remains immersed in Earth's shadow. But the International Space Station was just emerging from the shadow into the sunlit portion of its low Earth orbit. As seen from New York City, the visible streak of this ISS flyover starts near a star in Taurus and tracks right to left, through the belt of Orion and over Sirius, alpha star of Canis Major. Gaps along the bright trail of the fast moving orbital outpost (and an aircraft flying closer to the horizon) mark the time between individual exposures in the sequence. The trail of bright planet Mars is at the top of the frame. Pleiades star cluster trails are high over the eclipsed Moon and Empire State Building.   Lunar Eclipse of November 2022: Notable Submissions to APOD  Love Eclipses? (US): Apply to become a NASA Partner Eclipse Ambassador",
       "hdurl"=>"https://apod.nasa.gov/apod/image/2211/StanHondaTLE-ISS1108.jpg",
       "media_type"=>"image",
       "service_version"=>"v1",
       "title"=>"Eclipse in the City",
       "url"=>"https://apod.nasa.gov/apod/image/2211/StanHondaTLE-ISS1108annotated1024.jpg" }
    }

    it "changes the user's background" do
      command = DailyPhotoBgReactionCommand.new(options)
      handler = DailyPhotoBgReactionCommandHandler.new

      handler.call(command.to_h, mocked_response)
      expect(User.find(user.id).background).to eq(mocked_response["url"])
    end
  end
end
