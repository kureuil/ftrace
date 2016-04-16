#!/bin/bash

if [ -z $CC ]
then
    export CC=gcc
fi

CFLAGS=$1
shift

for sourcefile in "$@"
do
    $CC $CFLAGS -MM "$sourcefile" -MT $(echo $sourcefile | sed -e 's/.c$/.o/')
done
