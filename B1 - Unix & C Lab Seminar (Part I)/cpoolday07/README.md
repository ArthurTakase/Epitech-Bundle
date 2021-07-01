# Day 7

**Attention au -42.** Servez vous de ce repo pour vous orienter si vous avez des difficultés, *tricher ne vous apportera rien.*

Je rappel également que les codes présents ici n'ont pas été corrigés suite à la piscine, **les erreurs que j'ai pu faire sont toujours dedans**, à vous de faire attention !

## Quelques Astuces

> **Task 04**

Cette fois ci, c'est un programme que l'on vous demande et pas une fonction. Faites donc un main avec l'appel à argc et argv.

```
    int main(int argc, char **argv)
```

argc est le nombre d'argument au lancement et argv contient tous les arguments dans un tableau.

```
    ./mon_super_prog salut les amis
```

|argc|argv  |
|--|--|
| 4 | ["./mon_super_prog", "salut", "les", "amis"] |

salut se trouve alors en argv[1].

> **Task 06**

Faites un **bubble sort** avec un **strcmp**. Les deux programmes sont normalement déjà programmés lors des précédentes journées.