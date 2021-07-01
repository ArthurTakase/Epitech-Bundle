# My_runner {Epitech}

Le but du projet **My_runner** est de programmer un jeu basé sur le principe d'un [Endless Running Game](https://en.wikipedia.org/wiki/Platform_game#Endless_running_game), un jeu où l'on doit courir le plus longtemps possible en évitant les obstacles.

## Note

| MyEpitech | Norme | Intra
|--|--|--|
| 100% | 0 fautes | 59

## Détails supplementaires

-  le joueur est un personnage qui court dans une carte que vous avez prise comme paramètre.
- les ennemis et les obstacles doivent apparaître du côté opposé à la position du joueur.
- le joueur peut utiliser la barre d'espace pour sauter et éviter les obstacles et les ennemis.
- au fur et à mesure que le joueur court, un score, qui sera affiché, augmentera.
- lorsque le joueur meurt ou finit la carte, le score est affiché à l'intérieur de la fenêtre.

# How to
### Compilation

Pour lancer le programme, il faudra d'abords le compiler. Pour cela, [téléchargez le repo](https://github.com/EpitechIT2020/B-MUL-100-BDX-1-1-myrunner-arthur.decaen/archive/master.zip) ou clonez-le, puis faites la commande suivant :
> **$** make re

### Lancer le programme

Pour lancer le jeu, faites la commande suivante :
> **$** ./my_runner [map]

Une carte de démonstration se trouve sur le fichier asset/map/1.
> **$** ./my_runner asset/map/1

### Créer une carte

La création d'une carte se fait en modifiant un fichier (.txt par exemple) avec les informations suivantes :

|Valeur             |Résultat                     |
|-------------------|-----------------------------|
|0            		|Piège à loup                 |
|1           		|Slime                        |
|2					|Oiseau                       |
|3					|Drapeau de fin               |
|.					|Rien                         |
|!					|Signale la fin du fichier    |