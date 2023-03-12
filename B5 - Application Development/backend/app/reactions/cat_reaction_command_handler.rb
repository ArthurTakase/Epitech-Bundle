# frozen_string_literal: true

class CatReactionCommandHandler
  def initialize
  end

  def call(attributes)
    puts "Cat Command Handler" unless Rails.env.test?

    begin
      pictureCat = HTTParty.get("https://api.thecatapi.com/v1/images/search")
      img = pictureCat[0]["url"]
    rescue Exception
      img = "https://media.discordapp.net/attachments/823473929447538710/1039684054397759590/Screenshot_from_2022-11-08_23-41-25.png?width=1211&height=681"
    end
    factsCat = HTTParty.get("https://catfact.ninja/fact")
    fact = factsCat["fact"] || "Aujourd'hui mon chat est mort, ou hier peut-être, je ne sais pas, je suis un chat."

    user = User.find(attributes[:user_id])
    user.cat = {
      "picture"=> img,
      "fact"=> fact
    }
    user.save # return true if succeed
  end
end
