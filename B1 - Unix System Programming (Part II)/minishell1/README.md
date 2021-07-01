# Graphique 1 {Epitech}

**Attention au -42.** Servez vous de ce repo pour vous orienter si vous avez des difficultés, *tricher ne vous apportera rien.*

Je rappel également que les codes présents ici n'ont pas été corrigés suite à leur création, **les erreurs que j'ai pu faire sont toujours dedans**, à vous de faire attention !

## Note

| MyEpitech | Norme | Intra |
|--|--|--|
| 47.1% | 0 fautes | 4121

(Crash)

## Quelques Astuces  

Les astuces que je vais donné ne sont pas appliquées dans cette version du code, mais se trouvent dans celui du minishell2 et du 42sh (ses suites). Donc pour voir tout ça en action, je vous invite à aller voir les autres dossiers.

La première étape pour ce projet est la lecture du man de getline() qui vous sera plus qu'utile.

Le minishell est composé de 3 grosses parties :

 1. Le parsing
 2. Les built-ins
 3. Le fork

> **Parsing**

Le parsing du minishell 1 se limite uniquement à couper la commande aux niveaux des espaces. Vous pouvez donc faire appel à un char \*\* et le remplir comme il faut au début de votre boucle. La fonction **strtok** étant autorisée, vous pouvez en abuser pour votre shell (*man strtok*), cela vous permettra d'avoir une allocation dynamique simple et efficace.

> **Le fork**

Le fork est une notion importante du shell. Il va vous permettre d'exécuter des programmes avec execvr sans que ce dernier ne stoppe votre shell. Pour vous aider à mettre ça en place, vous pouvez aller voir [cette vidéo](https://www.youtube.com/watch?v=xVSPv-9x3gk). Petit tips, l'execution du programme demandé se fait dans le processus enfant. Si le programme demandé n'existe pas, alors execvr ne coupera pas le processus enfant, profitez-en pour y mettre votre gestion d'erreur.