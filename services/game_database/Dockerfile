FROM ubuntu:20.04

ARG commit_hash
ARG app_api_key
ARG postgres_username
ARG postgres_password

ENV COMMIT_HASH $commit_hash
ENV API_KEY $app_api_key
ENV POSTGRES_USERNAME $postgres_username
ENV POSTGRES_PASSWORD $postgres_password

COPY cmake-build-release /build
COPY config.json /config.json

RUN apt-get update -y
RUN apt-get install libjsoncpp1 \
                    libpq5 -y

ENTRYPOINT ./build/database_service