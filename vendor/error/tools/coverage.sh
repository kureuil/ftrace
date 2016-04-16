#!/bin/bash

sum=0
count=1
(
  cd coverage;
  for sourcefile in $@
  do
    current=$(
      gcov 2>/dev/null ../${sourcefile} \
      | grep -m 1 "Lines executed:" \
      | sed -n 's/Lines executed:\([\.0-9]\+\)% of \([0-9]\+\)/\1/p'
    )
    sum=$(echo "scale=2; ${sum}+${current}" | bc)
    count=$((count + 1))
  done
  covered=$(echo "scale=2; ${sum}/${count}" | bc)
  echo "${covered}% covered"
)
