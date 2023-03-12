FROM ruby:3.0.2-alpine

RUN apk update && apk add bash build-base nodejs postgresql-dev tzdata libcurl

RUN mkdir /rails-app
WORKDIR /rails-app

COPY Gemfile Gemfile
COPY Gemfile.lock Gemfile.lock
RUN gem install bundler --no-document
RUN bundle install --no-binstubs --jobs $(nproc) --retry 3

COPY . /rails-app

CMD ["bundle", "exec", "rails", "server", "-b", "0.0.0.0"]
