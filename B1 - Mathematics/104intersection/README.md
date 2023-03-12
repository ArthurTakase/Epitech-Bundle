# 104intersection {Epitech}

## Note

| MyEpitech |
|--|
| 91.3% |

## Objets supportés

- Sphère centrée en (0;0;0)
- Cylindre de révolution autour de l'axe Z
- Cone de révolution autour de l'axe Z avec pour sommet le point (0;0;0)

## How to

### USAGE

```bash
./104intersection opt xp yp zp xv yv zv p
```

### DESCRIPTION

```txt
opt -> surface option: 1 for a sphere, 2 for a cylinder, 3 for a cone
(xp, yp, zp) -> coordinates of a point by which the light ray passes through
(xv, yv, zv) -> coordinates of a vector parallel to the light ray
p -> parameter: radius of the sphere, radius of the cylinder, or angle formed by the cone and the Z-axis
```

### Lancer le programme

Pour lancer le jeu, faites la commande suivante :

```bash
./104intersection opt xp yp zp xv yv zv p
```

### Exemple d'un résultat

> ./104intersection 2 0 0 2 1 1 0 1

```txt
Cylinder of radius 1
Line passing through the point (0, 0, 2) and parallel to the vector (1, 1, 0)
2 intersection points:
(0.707, 0.707, 2.000)
(-0.707, -0.707, 2.000)
```
