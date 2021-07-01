# 105torus {Epitech}

Le but du projet **105Torus** est de résoudre des équations du 4ème degrès à une inconnue à partir de différentes méthodes.


## Note

| MyEpitech |
|--|
| 71.4% |

## Objets supportés


- The bisection method,
- Newton’s method,
- The secant method.
 

# How to
> #### USAGE
	./105torus opt a0 a1 a2 a3 a4 n
> #### DESCRIPTION
	opt -> method option:
        1 for the bisection method
        2 for Newton’s method
        3 for the secant method
    a[0-4] -> coefficients of the equation
    n -> precision (the application of the polynomial to the solution should be smaller than 10ˆ-n)

### Lancer le programme

Pour lancer le jeu, faites la commande suivante :
> **$** ./105torus opt a0 a1 a2 a3 a4 n

### Exemple d'un résultat

> **$**  ./105torus 1 -1 0 6 -5 1 6
```
x = 0.5
x = 0.75
x = 0.625
x = 0.5625
x = 0.53125
x = 0.515625
x = 0.523438
x = 0.519531
x = 0.521484
x = 0.522461
x = 0.522949
x = 0.522705
x = 0.522827
x = 0.522766
x = 0.522736
x = 0.522751
x = 0.522743
x = 0.522739
x = 0.522741
x = 0.522740
```