FROM elixir

COPY . /app
WORKDIR /app

RUN apt-get update && apt-get install -y inotify-tools postgresql-client

RUN mix local.hex
RUN mix local.rebar
RUN mix archive.install hex phx_new
RUN mix deps.get
RUN mix deps.update --all

EXPOSE 4000

RUN chmod +x /app/start_server.sh
ENTRYPOINT ["/app/start_server.sh"]
