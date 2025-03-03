#!/bin/sh

rm -rf /app/mobile/www/*

cp /app/dist/* /app/mobile/www/

cordova build android --debug --buildConfig

cp /app/mobile/platforms/android/app/build/outputs/apk/debug/app-debug.apk /app/client.apk