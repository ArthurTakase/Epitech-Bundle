# 102 architect {Epitech}

le projet 102 architect a pour but de calculer, a l'aide de matrices, une multitude de transformations sur un point dans un espace en deux dimensions.

## Note

| MyEpitech |
|--|
| 91.3% |

## Détails supplementaires

**les transformations applicables sont les suivantes:**

 - translation
 - mise a l'echelle
 - rotation centrée en O
 - reflection sur n'importe quel axe qui passe par O
 - toutes combinaison des précédentes transormations

Le programme doit afficher :

- la matrice finale de calcul, avec toutes les transformations appliquées
- Les coordonnées du point, avant et après toutes les transformation
 

# How to

> ### USAGE

	./102architect x y transfo1 arg11 [arg12] [transfo2 arg12 [arg22]] ...

> ### DESCRIPTION

	x absciss of the original point

	y ordinate of the original point

	transfo arg1 [arg2]

	-t i j translation along vector (i, j)

	-z m n scaling by factors m (x-axis) and n (y-axis)

	-r d rotation centered in O by a d degree angle

	-s d reflection over the axis passing through O with an inclination angle of d degrees

### Lancer le programme

Pour lancer le jeu, faites la commande suivante :
> **$** ./102 architect x y transfo1 arg11 [arg12] [transfo2 arg12 [arg22]] ...

### Exemple d'un résultat

> **$**  ./102architect 1 2 -t 2 3 -z 1 -2 -r 45 -s 30
```
Translation along vector (2, 3)
Scaling by factors 1 and -2
Rotation by a 45 degree angle
Reflection over an axis with an inclination angle of 30 degrees
0.97    -0.52   0.38
0.26    1.93    6.31
0.00    0.00    1.00
(1.00, 2.00) => (0.31, 10.44)
```
