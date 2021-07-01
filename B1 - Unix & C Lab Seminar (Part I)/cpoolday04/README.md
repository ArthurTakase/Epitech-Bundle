# Day 4

**Attention au -42.** Servez vous de ce repo pour vous orienter si vous avez des difficultés, *tricher ne vous apportera rien.*

Je rappel également que les codes présents ici n'ont pas été corrigés suite à la piscine, **les erreurs que j'ai pu faire sont toujours dedans**, à vous de faire attention !

## Quelques Astuces

> **Task 01**

Pour cet exercice, il est primordial de comprendre le fonctionnement des pointeurs. Pour ça, vous pouvez aller voir les tutoriels disponibles sur l'intra de l'école.

Si vous avez encore des difficultés à comprendre, essayez de changer les valeurs entre deux variables dans une même fonction, puis dans deux fonctions différentes, le soucis sautera alors aux yeux.

Explication des pointeurs [ici](https://www.rocq.inria.fr/secret/Anne.Canteaut/COURS_C/chapitre3.html).

> **Task 02**

Les pointeurs peuvent aussi servir de "tableaux" comme dans le cas de cet exercice.
Voyez un char * comme une suite de char dans un tableau

char \*variable = "hello";

équivaut à

|case  | 0 |1|2|3|4|5|
|--|--|--|--|--|--|--|
|élément  | 'h' | 'e' | 'l' | 'l' | 'o' | '\0'

Déplacez vous dans ce tableau pour en faire ce que vous voulez.

> **Task 06**

Pour cet exercice, vous pouvez choisir la méthode de tri de votre choix. Une assez simple à mettre en place est [le bubble sort](https://www.geeksforgeeks.org/bubble-sort/).
N'hésitez pas à vous servir de votre **my_swap**.