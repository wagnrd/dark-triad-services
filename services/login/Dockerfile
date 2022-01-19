FROM ubuntu:20.04

ARG commit_hash
ARG oidc_client_id
ARG oidc_client_secret
ARG redis_password

ENV COMMIT_HASH $commit_hash
ENV OIDC_CLIENT_ID $oidc_client_id
ENV OIDC_CLIENT_SECRET $oidc_client_secret
ENV REDIS_PASSWORD $redis_password

COPY cmake-build-release /build
COPY config.json /config.json

RUN apt-get update
RUN apt-get install software-properties-common -y
RUN add-apt-repository ppa:ubuntu-toolchain-r/test
RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get dist-upgrade -y
RUN apt-get install libstdc++6 \
                    libjsoncpp1 \
                    libc-ares2 \
                    libpq5 \
                    libhiredis0.14 \
                    ca-certificates -y

ENTRYPOINT ./build/login_service