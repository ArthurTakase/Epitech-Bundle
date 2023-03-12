# frozen_string_literal: true

class NewEpisodeActionCommandHandler
  def initialize
  end

  def call(attributes)
    puts "New Episode Command Handler" unless Rails.env.test?

    update = HTTParty.get("https://api.themoviedb.org/3/tv/#{attributes[:show_id]}/changes?api_key=#{ENV["MOVIE_DB_KEY"]}&page=1")
    unless update
      puts "Error: The Movie DB return null"
      return false
    end

    len = update["changes"].length

    if len > 0
      (len-1).times do |i|
        if update["changes"][i]["key"] == "season"
          puts "New episode"
          Widget_to_disable.append(attributes[:widget_id])
          return true
        end
      end
    end

    puts "No new episode"
    false
  end
end
