#!/usr/bin/env bash

service_name="dark-triad-login-service"

echo ""
echo "=== $service_name ==="
echo ""

sudo docker build --tag registry.heroku.com/$service_name/web --build-arg commit_hash=$GITHUB_SHA --build-arg oidc_client_id=$OIDC_CLIENT_ID --build-arg oidc_client_secret=$OIDC_CLIENT_SECRET  --build-arg redis_password=$REDIS_PASSWORD .
echo $HEROKU_API_KEY | sudo docker login --username=$HEROKU_USERNAME --password-stdin registry.heroku.com
sudo docker push registry.heroku.com/$service_name/web
heroku container:release web --app=$service_name
