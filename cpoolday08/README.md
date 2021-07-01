# Day 8

**Attention au -42.** Servez vous de ce repo pour vous orienter si vous avez des difficultés, *tricher ne vous apportera rien.*

Je rappel également que les codes présents ici n'ont pas été corrigés suite à la piscine, **les erreurs que j'ai pu faire sont toujours dedans**, à vous de faire attention !

## Quelques Astuces

Pour les exercices suivants, malloc sera utilisé de la manière suivante :

> type *var = malloc(sizeof(type) * nbr_elem);

Par exemple, pour allouer en mémoire un char \* pour stocker un mot comme "hello", il faudra faire :

> char *var = malloc(sizeof(char) * 6);

Pourquoi 6 ? Il ne faut pas oublier le \0 en fin de phrase évidemment !
De manière générale, ajouter une case pour donner un symbole finale est une bonne chose à faire. Pour un tableau de mots par exemple, n'hésitez pas à rajouter un 0 dans la dernière case.