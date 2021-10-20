#!/usr/bin/env bash

service_name="dark-triad-database-service"

echo ""
echo "=== $service_name ==="
echo ""


heroku rollback --app=$service_name
