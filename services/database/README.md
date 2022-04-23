# Database Service

## Environment variables

Sensible data like passwords or secrets are stored as environment variables and are not present in the repository.

### Postgres

Credentials can be found
in [Heroku](https://data.heroku.com/datastores/08979ddc-6642-4d2f-a460-596086581d29#administration).

- POSTGRES_USERNAME
- POSTGRES_PASSWORD

### Other

- DEPLOYMENT_STAGE ("local", "prod"; defaults to "prod")
- API_KEY (Can be found in Bitwarden; defaults to empty string)
- PORT (defaults to 8080)

## Build and deploy container

### Build container

```shell
sudo docker build --tag local:database-service --build-arg postgres_username=<value> --build-arg postgres_password=<value> .
```

### Start container (for testing)

```shell
sudo docker run -p 80:8080/tcp --name database-service local:database-service
```

### Remove container

```shell
sudo docker container stop database-service
sudo docker container rm database-service
sudo docker image rm local:database-service
```

### Push image to Heroku registry

```shell
sudo docker tag local:database-service registry.heroku.com/dark-triad-database-service/web
sudo docker push registry.heroku.com/dark-triad-database-sevice/web
sudo heroku login
sudo heroku container:login
heroku container:release web --app=dark-triad-database-service
```