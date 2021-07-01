# 101pong {Epitech}

Le but du projet **104intersection** est de calculer les potentiels points d'intersection entre un vecteur et un objet en 3d.


## Note

| MyEpitech |
|--|
| 91.3% |

## Objets supportés


- Sphère centrée en (0;0;0)
- Cylindre de révolution autour de l'axe Z
- Cone de révolution autour de l'axe Z avec pour sommet le point (0;0;0)
 

# How to
> #### USAGE
	./104intersection opt xp yp zp xv yv zv p
> #### DESCRIPTION
	opt -> surface option: 1 for a sphere, 2 for a cylinder, 3 for a cone
    (xp, yp, zp) -> coordinates of a point by which the light ray passes through
    (xv, yv, zv) -> coordinates of a vector parallel to the light ray
    p -> parameter: radius of the sphere, radius of the cylinder, or angle formed by the cone and the Z-axis

### Lancer le programme

Pour lancer le jeu, faites la commande suivante :
> **$** ./104intersection opt xp yp zp xv yv zv p

### Exemple d'un résultat

> **$**  /104intersection 2 0 0 2 1 1 0 1
```
Cylinder of radius 1
Line passing through the point (0, 0, 2) and parallel to the vector (1, 1, 0)
2 intersection points:
(0.707, 0.707, 2.000)
(-0.707, -0.707, 2.000)```