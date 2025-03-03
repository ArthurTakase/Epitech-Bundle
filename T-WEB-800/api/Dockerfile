FROM elixir

COPY --chown=user:group . /app
WORKDIR /app

RUN apt-get clean && apt-get update && apt-get install -y inotify-tools postgresql-client

RUN mix local.hex
RUN mix local.rebar
RUN mix archive.install hex phx_new
RUN mix deps.get
RUN mix deps.update --all
RUN mix deps.get

EXPOSE 4000

ENTRYPOINT ["/app/start_server.sh"]