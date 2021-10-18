sudo docker build --tag registry.heroku.com/dark-triad-database-service/web --build-arg postgres_username=$POSTGRES_USERNAME --build-arg postgres_password=$POSTGRES_PASSWORD --build-arg commit_hash=$GITHUB_SHA --build-arg app_api_key=$APP_API_KEY .
echo $HEROKU_API_KEY | sudo docker login --username=$HEROKU_USERNAME --password-stdin registry.heroku.com
sudo docker push registry.heroku.com/dark-triad-database-service/web
heroku container:release web --app=dark-triad-database-service
