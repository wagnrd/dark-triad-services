#!/usr/bin/env bash

# defaults
to="prod"
from="main"

if [ "$1" == "--help" ]; then
    echo "./release.sh <dest> <src>"
    echo
    echo "<dest> - destination branch where the changes should be rebased to"
    echo "         default: prod"
    echo "<src>  - source branch where the changes should be rebased from"
    echo "         default: main"
    exit
fi

if [ "$1" != "" ]; then
    to=$1
fi

if [ "$2" != "" ]; then
    from=$2
fi

git checkout "$to" && git rebase "$from" && git push && git checkout -
