# frozen_string_literal: true

class DiscoverMovieReactionCommandHandler
  def initialize
  end

  def call(attributes, gmail = nil, mocked_response = nil)
    puts "Discover Movie Command Handler" unless Rails.env.test?

    unless mocked_response
      begin
        infos = HTTParty.get("https://api.themoviedb.org/3/discover/movie?api_key=#{ENV["MOVIE_DB_KEY"]}&language=#{attributes[:language]}&region=#{attributes[:region]}&sort_by=vote_average.desc&include_adult=#{attributes[:adult]}&include_video=true&page=1&release_date.gte=#{attributes[:min_date]}&vote_count.gte=50&vote_average.gte=#{attributes[:min_score]}&without_genres=documentary&watch_region=FR")
        nbPage = infos["total_pages"].to_i
        nbPage = nbPage >= 500 ? 499 : nbPage
      rescue NoMethodError
        puts "Error: The Movie DB return null"
        return false
      end
    end

    begin
      movies = mocked_response || HTTParty.get("https://api.themoviedb.org/3/discover/movie?api_key=#{ENV["MOVIE_DB_KEY"]}&language=#{attributes[:language]}&region=#{attributes[:region]}&sort_by=vote_average.desc&include_adult=#{attributes[:adult]}&include_video=true&page=#{rand(1..nbPage)}&release_date.gte=#{attributes[:min_date]}&vote_count.gte=50&vote_average.gte=#{attributes[:min_score]}&without_genres=documentary&watch_region=FR")
      movie = movies["results"][rand(0..movies["results"].length-1)]
      date = DateTime.now.strftime("%d/%m/%Y")
    rescue Exception
      puts "Error: The Movie DB return null"
      return false
    end

    user = User.find(attributes[:user_id])
    gmail ||= GmailClient.new(user.google_token, user.email)
    gmail.send_mail(
      user.email,
      "AREA Movie Recommandation (#{date})",
      "<!doctype html>
<html>
  <head>
    <meta name='viewport' content='width=device-width, initial-scale=1.0'/>
    <meta http-equiv='Content-Type' content='text/html; charset=UTF-8' />
    <title>Simple Transactional Email</title>
  </head>
  <body>
    <div style='text-align: center;'>
      <h1><u>#{movie["title"]}</u></h1>
      <i>#{movie["release_date"]}</i>
      <p>#{movie["overview"]}</p>
      <img src='https://image.tmdb.org/t/p/w500#{movie["poster_path"]}' height='300px'/><br/>
      <a href='https://www.themoviedb.org/movie/#{movie["id"]}' target='_blank'>Plus d'infos</a>
    </div>
  </body>
</html>"
    )
  end
end
