#!/bin/sh

npm install
npm run build

if [ "$MODE" = "dev" ]; then
    npm run dev
    exec nginx restart
fi
