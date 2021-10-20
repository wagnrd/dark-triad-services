service_name="dark-triad-login-service"

echo ""
echo "=== $service_name ==="
echo ""

response=$(curl https://$service_name.herokuapp.com/status/details)
echo Response: $response
echo Commit hash: $GITHUB_SHA
if [[ ! "$response" == *"$GITHUB_SHA"* ]]; then echo "Commit hash of deployed version doesn't match for service '$service_name'!" && exit 1; fi
