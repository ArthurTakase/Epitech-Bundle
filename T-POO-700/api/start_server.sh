#!/bin/sh

# until pg_isready -h $POSTGRES_HOST -p $POSTGRES_PORT -U $POSTGRES_USER
# do
#   echo "Waiting for postgres..."
#   sleep 1
# done

# if ! echo $POSTGRES_PASSWORD | psql -h $POSTGRES_HOST -p $POSTGRES_PORT -U $POSTGRES_USER -W -lqt $POSTGRES_DB | cut -d \| -f 1 | grep -qw $POSTGRES_DB; then
#   echo "Creating database..."
# fi

mix ecto.drop
mix ecto.create
mix ecto.migrate
mix deps.get
echo "Seed will start"
mix run priv/repo/seeds.exs
echo "Seed ended"
echo "Launching server"
exec mix phx.server
