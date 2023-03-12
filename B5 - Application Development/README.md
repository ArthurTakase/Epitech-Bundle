# AREA

## Description

- Area project is an API dashboard with actions and reaction.

### Requirements

- docker
- docker compose

## Usage

Clone it!

```bash
git clone git@github.com:Le-feu-de-camp/Area-Front.git
```

Go into the project directory and run the command:

```bash
docker-compose up --build
```

Open `http://localhost:8081` and enjoy!

## Android

- on peut aussi passer par Android Studio si l'emulateur ne fonctionne pas, ou simplement installer l'apk sur son tel

```bash
cordova emulate android
```

### Check data base

```bash
docker-compose run server bash
bundle install
rails db:drop db:setup
exit
docker-compose up --build
```

### Frontend

- Frontend is made with Reactjs version 18

### Backend

- Backend is made with Ruby On Rails with postgresSQL as data base
