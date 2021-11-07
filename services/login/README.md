# Login Service

Login service for Dark Triad.

## Dependencies

- C++17 (GCC-9 or higher)
- Drogon (included in repo but has other dependencies)
- libfmt

## Setup

### App

Install the following dependency packages:

```shell
$ sudo apt install libjsoncpp-dev libfmt-dev libc-ares-dev libssl-dev
```

#### Troubleshooting

Install all dependencies from [Drogon](https://github.com/an-tao/drogon).

### Environment variables

Sensible data like passwords or secrets are stored as environment variables and are not present in the repository.

#### Postgres

- OIDC_CLIENT_ID (can be found in [auth0](https://auth0.com))
- OIDC_CLIENT_SECRET (can be found in [auth0](https://auth0.com))

#### Other

- DEPLOYMENT_STAGE ("local", "prod"; defaults to "prod")
- PORT (defaults to 8081)

### Docker

Install Docker with `sudo snap install docker`.

#### Build container

```shell
sudo docker build --tag local:login-service --build-arg oidc_client_id=<value> --build-arg oidc_client_secret=<value> .
```

#### Start container (for testing)

```shell
sudo docker run -p 80:8081/tcp --name login-service local:login-service
```

#### Remove container

```shell
sudo docker container stop login-service
sudo docker container rm login-service
sudo docker image rm local:login-service
```

### Deploy (Heroku)

Install heroku with `sudo snap install heroku --classic`

#### Push image to Heroku registry

```shell
sudo docker tag local:login-service registry.heroku.com/dark-triad-login-service/web
sudo docker push registry.heroku.com/dark-triad-login-service/web
sudo heroku login
sudo heroku container:login
heroku container:release web --app=dark-triad-login-service
```