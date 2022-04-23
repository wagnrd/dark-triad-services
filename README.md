## Dark Triad Services

### Services

- [Database](services/database/README.md)
- [Login](services/login/README.md)

### General setup

#### Compilation

- C++20 capable compiler (eg. GCC 11 or higher)
- CMake 3.1.0 (or higher)

#### Dependencies

Install the following dependency packages:

- Ubuntu

```shell
sudo apt install libjsoncpp-dev postgresql-server-dev-12 uuid-dev zlib1g-dev libfmt-dev libssl-dev
```

- Fedora

```shell
sudo dnf install hiredis-devel uuid-devel jsoncpp-devel fmt-devel libpq-devel
```

#### Deployment

If you want to run and deploy docker containers you also need to install Docker
and the Heroku CLI:

- Docker: [Installation instructions](https://docs.docker.com/engine/install/fedora)
- Heroku: [Installation instructions](https://devcenter.heroku.com/articles/heroku-cli#install-the-heroku-cli)

#### Troubleshooting

Install all dependencies from [Drogon](https://github.com/an-tao/drogon).