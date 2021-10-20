#!/usr/bin/env bash

service_name="dark-triad-login-service"

echo ""
echo "=== $service_name ==="
echo ""


heroku rollback --app=$service_name
