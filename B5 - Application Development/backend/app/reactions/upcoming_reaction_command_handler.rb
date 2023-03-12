# frozen_string_literal: true

class UpcomingReactionCommandHandler
  def initialize
  end

  def call(attributes)
    puts "Upcoming Movies Command Handler" unless Rails.env.test?

    movies = HTTParty.get("https://api.themoviedb.org/3/movie/upcoming?api_key=#{ENV["MOVIE_DB_KEY"]}&language=fr-FR&page=1&region=FR")
    unless movies["results"]
      puts "Error: The Movie DB return null"
      return false
    end

    result = "<!doctype html>
    <html>
      <head>
        <meta name='viewport' content='width=device-width, initial-scale=1.0'/>
        <meta http-equiv='Content-Type' content='text/html; charset=UTF-8' />
        <title>Simple Transactional Email</title>
      </head>
      <body>"
    movies["results"].each do |movie|
      result += "<div style='text-align: center;'>
      <h1><u>#{movie["title"]}</u></h1>
      <i>#{movie["release_date"]}</i>
      <p>#{movie["overview"]}</p>
      <img src='https://image.tmdb.org/t/p/w500#{movie["poster_path"]}' height='300px'/><br/>
      <a href='https://www.themoviedb.org/movie/#{movie["id"]}' target='_blank'>Plus d'infos</a>
    </div>"
    end
    result += "</body></html>"

    date = DateTime.now.strftime("%d/%m/%Y")

    gmail = GmailClient.new(attributes[:token], attributes[:email])
    gmail.send_mail(
      attributes[:email],
      "AREA Upcoming Movies (#{date})",
      result
    )
  end
end
