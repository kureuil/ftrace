#!/bin/sh

if [ -z $CC ]
then
    export CC=gcc
fi

for sourcefile in "$@"
do
    $CC -I ./inc/ -MM "$sourcefile" -MT $(echo $sourcefile | sed -e 's/.c$/.o/')
done
