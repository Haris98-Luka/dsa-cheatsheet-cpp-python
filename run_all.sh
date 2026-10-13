#!/usr/bin/env bash
# Runs every Python and C++ file and reports pass/fail.
set -u
fail=0
tmp=$(mktemp -d)

for f in */*.py; do
  python3 "$f" || { echo "FAILED: $f"; fail=1; }
done

for f in */*.cpp; do
  out="$tmp/$(basename "${f%.cpp}")"
  if g++ -std=c++17 -Wall -Wextra "$f" -o "$out"; then
    "$out" || { echo "FAILED: $f"; fail=1; }
  else
    echo "COMPILE ERROR: $f"; fail=1
  fi
done

rm -rf "$tmp"
[ $fail -eq 0 ] && echo "ALL TESTS PASSED" || { echo "SOME TESTS FAILED"; exit 1; }
