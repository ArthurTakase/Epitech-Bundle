#!/bin/bash

echo "Création de la librairie en cours..."

find -name "*.c" -exec gcc -c {} \;
ar rc libmy.a *.o

echo "Création terminée !"

find -name "*.o" -exec rm -rf {} \;

echo "Fichiers .o supprimés !"
