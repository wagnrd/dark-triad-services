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

RUN add-apt-repository -y ppa:ubuntu-toolchain-r/test
RUN apt-get update -y
RUN apt-get install libstdc++-11-dev \
                    libjsoncpp1 \
                    libc-ares2 \
                    libpq5 \
                    libhiredis0.14 -y

ENTRYPOINT ./build/database_service