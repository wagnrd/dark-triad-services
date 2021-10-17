#!/usr/bin/env bash

karateVersion=1.1.0

if [ ! -f "karate-$karateVersion.jar" ]; then
    echo "=== Downloading Karate executable ==="
    echo
    wget https://github.com/intuit/karate/releases/download/v$karateVersion/karate-$karateVersion.jar
    echo
fi

echo "=== Running Karate tests ==="
echo

if [ -d "target" ]; then
    echo " - clearing old Karate target folder"
    rm -rf target
fi

echo
java -jar karate-$karateVersion.jar -g test test
