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

RUN apt-get update -y
RUN apt-get install libjsoncpp1 \
                    libc-ares2 \
                    libpq5 \
                    libhiredis0.14 \
                    ca-certificates -y
RUN sudo echo "/lib/x86_64-linux-gnu/libhiredis.so.0.14" > "/etc/ld.so.conf.d/local.conf"
RUN ldconfig -p
RUN ldconfig -p | grep libhiredis


ENTRYPOINT ./build/login_service