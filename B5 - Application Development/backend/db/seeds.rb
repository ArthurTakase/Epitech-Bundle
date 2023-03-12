# This file should contain all the record creation needed to seed the database with its default values.
# The data can then be loaded with the bin/rails db:seed command (or created alongside the database with db:setup).
#
# Examples:
#
#   movies = Movie.create([{ name: "Star Wars" }, { name: "Lord of the Rings" }])
#   Character.create(name: "Luke", movie: movies.first)

# Users
users = [
  { first_name: "Jean-Jean", last_name: "La fouriere", email: "jean.four@email.com", password: "123456", admin: true,
    songs: :nil, spotify_token: "fdqsglfgjfdsd" },
  { first_name: "Kevin", last_name: "Gros", email: "grosKevin@gmail.com", password: "123456", admin: false,
    songs: :nil }
  ]
if User.count == 0
  users.each do |user|
    User.create!(first_name: user[:first_name], last_name: user[:last_name], email: user[:email],
                admin: user[:admin], password: user[:password], songs: user[:songs], spotify_token: user[:spotify_token])
  end
end

# Widget
widgets= [{ name: "Name", user_id: User.first.id }]
if Widget.count == 0
  widgets.each do |widget|
    Widget.create!(name: widget[:name], user_id: widget[:user_id])
  end
end

# Actions
actions = [{ klass: "at_hour", options: { "hour": "16:00" }, widget_id: Widget.first.id }]
if Action.count == 0
  actions.each do |action|
    Action.create!(klass: action[:klass], options: action[:options], widget_id: action[:widget_id])
  end
end

# Reactions
reactions = [{ klass: "daily_photo_bg", options: {}, action_id: Action.first.id }]
if Reaction.count == 0
  reactions.each do |reaction|
    Reaction.create!(klass: reaction[:klass], options: reaction[:options], action_id: reaction[:action_id])
  end
end
