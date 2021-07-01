# Day 9

**Attention au -42.** Servez vous de ce repo pour vous orienter si vous avez des difficultés, *tricher ne vous apportera rien.*

Je rappel également que les codes présents ici n'ont pas été corrigés suite à la piscine, **les erreurs que j'ai pu faire sont toujours dedans**, à vous de faire attention !

## Quelques Astuces

Voyez une structure comme un nouveau type qui peut contenir ce que vous voulez. Par exemple :

```
    struct student_t
    {
	    int age;
	    char *name;
    };
```

Cette structure est donc un élève à qui je peux donner un age et un nom. Pour modifier ses composants, deux manière existent :

> Si c'est un pointeur

Si la structure est utlisée avec un pointeur (donc qu'elle est allouée en mémoire), il faudra utiliser le symbole **->**.

```
    struct student_t *eleve = malloc(sizeof(struct student_t));
    
    eleve->age = 12;
    eleve->name = "Arthur";
```

Notre variable **eleve** contient maintenant les informations d'age et de nom (n'hésitez pas à faire un *my_putstr(eleve->name)* pour vérifier que tout se passe bien).

> Si ce n'est pas un pointeur

Si la structure n'est pas allouée en mémoire, il faudra utiliser le symbole **.** .

```
    struct student_t eleve;
        
    eleve.age = 12;
    eleve.name = "Arthur";
```