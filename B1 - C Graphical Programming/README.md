# Graphique 1 {Epitech}

**Attention au -42.** Servez vous de ce repo pour vous orienter si vous avez des difficultés, *tricher ne vous apportera rien.*

Je rappel également que les codes présents ici n'ont pas été corrigés suite à leur création, **les erreurs que j'ai pu faire sont toujours dedans**, à vous de faire attention !

## Informations

Chaque dossier possède son propre README.md avec des informations sur les projets concernés. Si vous bloquez, lisez le avant d'aller regarder le code. C'est toujours mieux de comprendre que de copier.

## Quelques Astuces

Pour ces deux projets, les astuces que j'ai pour vous seront au niveau  de la forme du code.
Pour une gestion plus simple de tous les éléments, n'hésitez pas à mettre en place une grosse structure principale qui contiendrait tous les éléments de votre jeu (sprites, musiques, scores, textes, etc...). Voici par exemple la structure principale du runner. N'hesitez pas également à mettre des structures dans des structures, histoire d'organiser tout ça proprement (ce qui n'a pas beaucoup été fait dans ces deux projets).

```
typedef  struct  s_run
{
	bg_t  *bg;
	char  *map;
	int is_over;
	int len_trap;
	int trap_max;
	trap_t trap;
	menu_t  *menu;
	score_t  *best;
	jauge_t  *jauge;
	score_t  *score;
	sprite_t  *life;
	sprite_t  *player;
	sprite_t  *cursor;
	sprite_t  *filtre;
	option_t  *option;
	all_sound_t  *sound;
	all_clock_t  *clock;
	sfRenderWindow *window;
} run_t;
```

Ensuite, pour la gestion des canards ou bien des ennemis, forcez-vous à utiliser les listes chaînées (avec comme élément un sprite par exemple :wink:). Pour ça, toujours [la même vidéo](https://www.youtube.com/watch?v=FmaNOdbngLc&t=922s) pour vous aider à la mise en place des listes.

Pour ce qui est des sprites, des sites comme Itch.io ou encore OpenGameArt.org devront vous aider.