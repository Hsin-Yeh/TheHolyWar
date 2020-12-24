#!/usr/bin/env bash
set -euo pipefail

g++ main.cc
./a.out
rm a.out
