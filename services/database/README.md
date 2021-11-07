# Database API

## Dependencies

- C++17 (GCC-9 or higher)
- Drogon (included in repo but has other dependencies)

## Setup

### App

Install the following dependency packages:

```shell
$ sudo apt install libjsoncpp-dev postgresql-server-dev-12 uuid-dev zlib1g-dev libfmt-dev libssl-dev
```

#### Troubleshooting

Install all dependencies from [Drogon](https://github.com/an-tao/drogon).

### Environment variables

Sensible data like passwords or secrets are stored as environment variables and are not present in the repository.

#### Postgres

Can be found [here](https://data.heroku.com/datastores/08979ddc-6642-4d2f-a460-596086581d29#administration).

- POSTGRES_USERNAME
- POSTGRES_PASSWORD

#### Other

- DEPLOYMENT_STAGE ("local", "prod"; defaults to "prod")
- API_KEY (Can be found in Bitwarden; defaults to empty string)
- PORT (defaults to 8080)

### Docker

Install Docker with `sudo snap install docker`.

#### Build container

```shell
sudo docker build --tag local:database-api --build-arg postgres_username=<value> --build-arg postgres_password=<value> .
```

#### Start container (for testing)

```shell
sudo docker run -p 80:8080/tcp --name database-api local:database-api
```

#### Remove container

```shell
sudo docker container stop database-api
sudo docker container rm database-api
sudo docker image rm local:database-api
```

### Deploy (Heroku)

Install heroku with `sudo snap install heroku --classic`

#### Push image to Heroku registry

```shell
sudo docker tag local:database-api registry.heroku.com/dark-triad-db/web
sudo docker push registry.heroku.com/dark-triad-db/web
sudo heroku login
sudo heroku container:login
heroku container:release web --app=dark-triad-db
```

### Local Postgres

1. Install PostgreSQL  
   *(WIP)*
2. Connect to Postgres CLI:
   ```shell
   sudo -u postgres psql
   ```
3. Change password:
   ```
   \password postgres
   ```

