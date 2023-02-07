#!/bin/sh

set -e

cat .ft/.cache/test_list.properties | while IFS="=" read -r name path
do
  (cd "$path" && FT_TEST_NAME="$name" ${MAKE-make} "$1")
done
