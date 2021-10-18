sudo docker build --tag registry.heroku.com/dark-triad-login-service/web --build-arg commit_hash=$GITHUB_SHA --build-arg oidc_client_id=$OIDC_CLIENT_ID --build-arg oidc_client_secret=$OIDC_CLIENT_SECRET .
echo $HEROKU_API_KEY | sudo docker login --username=$HEROKU_USERNAME --password-stdin registry.heroku.com
sudo docker push registry.heroku.com/dark-triad-login-service/web
heroku container:release web --app=dark-triad-login-service
