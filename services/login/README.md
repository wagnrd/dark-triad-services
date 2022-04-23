# Login Service

Login service for Dark Triad.

## Environment variables

Sensible data like passwords or secrets are stored as environment variables and are not present in the repository.

### Auth0

Credentials can be found
in [auth0](https://manage.auth0.com/dashboard/eu/dark-triad/applications/JbzprOY29gdJbHOsRwXVpp7SYvFq0jKr/settings).

- OIDC_CLIENT_ID
- OIDC_CLIENT_SECRET

### Other

- DEPLOYMENT_STAGE ("local", "prod"; defaults to "prod")
- PORT (defaults to 8081)

## Build and deploy container

### Build container

```shell
sudo docker build --tag local:login-service --build-arg oidc_client_id=<value> --build-arg oidc_client_secret=<value>  --build-arg redis_password=<value>.
```

### Start container (for testing)

```shell
sudo docker run -p 80:8081/tcp --name login-service local:login-service
```

### Remove container

```shell
sudo docker container stop login-service
sudo docker container rm login-service
sudo docker image rm local:login-service
```

### Push image to Heroku registry

```shell
sudo docker tag local:login-service registry.heroku.com/dark-triad-login-service/web
sudo docker push registry.heroku.com/dark-triad-login-service/web
sudo heroku login
sudo heroku container:login
heroku container:release web --app=dark-triad-login-service
```