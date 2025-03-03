# Epic Road Trip

Un planificateur de voyage qui simplifie les vacances en générant des suggestions personnalisées en fonction de lieux, dates et budgets. Explorez des événements culturels, sports, hébergements, restaurants, bars, transports, itinéraires, et visualisez tout sur une carte. Enregistrez et partagez vos recherches pour une expérience de voyage sans stress.

## Windows

Si vous êtes sur Windows, merci de faire les étapes suivantes avant de cloner le projet.

- Désactivez le crlf

```bash
git config --global core.autocrlf false
```

OU

- Téléchargez le projet en zip et décompressez le dans un dossier.
- Clonez le projet dans un autre dossier.
- Copiez le `.git` dans le dossier du projet décompressé.
- Supprimez le dossier du projet cloné.

## Installation

1. Ajoutez un fichier `.env` à la racine du projet avec les variables suivantes :
    - POSTGRES_USER
    - POSTGRES_PASSWORD
    - POSTGRES_HOST
    - POSTGRES_PORT
    - POSTGRES_DB
    - MODE
    - HERE_API_KEY

2. Lancez les containers avec la commande suivante :

```bash
sudo docker-compose up --build
```

## Liens

- Front : [http://localhost:8080](http://localhost:8080)
- Back : [http://localhost:4000](http://localhost:4000)
- Documentation API : [http://localhost:4000/api/swagger](http://localhost:4000/api/swagger)

## Normes

- Les messages de commit doivent être en anglais.
- Chaque commit doit commencer par un des mots-clés suivants :
  - `FEAT` : nouvelle fonctionnalité
  - `FIX` : correction de bug
  - `UP` : refactoring
  - `DEL` : suppression de code
  - `TEST` : ajout ou modification de tests
  - `DOC` : ajout ou modification de documentation
- Les messages de commit doivent être de la forme suivante : `<mot clef>: <description>`
- les branches doivent être nommées de la manière suivante : `<feat ou fix>/<description>`

## CI/CD

Chaque push déclenche une suite de tests sur GitHub Actions. Une branche dont le dernier commit ne passe pas les tests ne sera pas mergé sur la branche principale.

Les étapes de la CI sont les suivantes :

1. Construction des containers (back, front et db).
2. Configuration du back (clean, compile, create db).
3. Lancement des tests (back).
4. Lancement des tests (front).

## Lancement manuel des tests

- Back
  
  ```bash
  sudo docker compose exec server mix test
  ```

- Front
  
  ```bash
  sudo docker compose exec client npm test
  ```

## Exectuer des commandes dans les containers

```bash
sudo docker compose exec <container_name> <command>
```

### Containers

- `server`
- `client`

### Commandes utiles

| Commande | Description |
| --- | --- |
| `mix phx.server` | Lance le serveur Phoenix |
| `mix ecto.migrate` | Exécute les migrations |
| `mix ecto.rollback` | Annule les migrations |
| `mix do ecto.drop, ecto.create, ecto.migrate` | Recrée la base de données |
| `mix deps.update --all` | Met à jour les dépendances |
| `mix phx.gen.json Users User users username:string email:string`, `mix phx.gen.json Workingtimes Workingtime workingtimes start:utc_datetime end:utc_datetime user:references:users` | Génère des fichiers pour les modèles (à modifier en fonction des besoins) |
| `mix ecto.gen.migration update_posts_table` | Génère une migration |
| `mix phx.swagger.generate` | Regénère la documentation swagger |
| `npm run test` | Lance les tests (front) |
| `mix test` | Lance les tests (back) |
