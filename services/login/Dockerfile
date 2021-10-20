FROM ubuntu:20.04

ARG commit_hash
ARG oidc_client_id
ARG oidc_client_secret

ENV COMMIT_HASH $commit_hash
ENV OIDC_CLIENT_ID $oidc_client_id
ENV OIDC_CLIENT_SECRET $oidc_client_secret

COPY cmake-build-release /build
COPY config.json /config.json

RUN apt-get update -y
RUN apt-get install libjsoncpp1 \
                    libc-ares2 \
                    libpq5 \
                    ca-certificates -y

ENTRYPOINT ./build/login_service