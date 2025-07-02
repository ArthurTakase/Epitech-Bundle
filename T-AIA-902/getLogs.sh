#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <container_id>"
    exit 1
fi

CONTAINER_ID=$1
EXPORT_DIR="./exported"

mkdir -p "$EXPORT_DIR"

echo "==> Copie de taxi.pkl vers $EXPORT_DIR..."
docker cp $CONTAINER_ID:/app/taxi.pkl "$EXPORT_DIR/taxi.pkl"

echo "==> Copie de results filtré vers $EXPORT_DIR/results..."
docker cp $CONTAINER_ID:/app/results "$EXPORT_DIR/results"

echo "==> Suppression des fichiers inutiles..."
rm -rf "$EXPORT_DIR/results/exemples"
rm -rf "$EXPORT_DIR/results/.gitkeep"

echo "✅ Fichiers copiés dans $EXPORT_DIR."
