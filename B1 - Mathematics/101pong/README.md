# 101pong {Epitech}

Le but du projet **101pong** est de calculer, à partir de vecteurs, la position d'une balle dans un espace en trois dimensions, ainsi que l'angle de rebond sur un mur placé en (0;0).

## Note

| MyEpitech |
|--|
| 96.8% |

## Détails supplementaires

Le programme doit afficher :

- La vélocité de la balle
- Les coordonnées de la balle au temps *t*
- L'angle avec lequel la balle touchera le mur (si elle le touche)

## How to

### USAGE

```bash
./101pong x0 y0 z0 x1 y1 z1 n
```

### DESCRIPTION

```txt
x0 ball abscissa at time t - 1
y0 ball ordinate at time t - 1
z0 ball altitude at time t - 1
x1 ball abscissa at time t
y1 ball ordinate at time t
z1 ball altitude at time t
n time shift (greater than or equal to zero, integer)
```

### Lancer le programme

Pour lancer le jeu, faites la commande suivante :

```bash
./101pong x0 y0 z0 x1 y1 z1 n
```

### Exemple d'un résultat

> ./101pong 1.1 3 5 -7 9 2 4

```txt
The velocity vector of the ball is:
(-8.10, 6.00, -3.00)
At time t + 4, ball coordinates will be:
(-39.40, 33.00, -10.00)
The incidence angle is:
16.57 degrees
```
