#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
OUT_DIR="${TMPDIR:-/tmp}/adnd1-monster-registry-test"
BIN="$OUT_DIR/monster_registry_test"

mkdir -p "$OUT_DIR"

if ! command -v pkg-config >/dev/null 2>&1; then
  echo "pkg-config is required to build monster_registry_test" >&2
  exit 1
fi

LUA_FLAGS="$(pkg-config --cflags --libs lua5.4)"

g++ -std=c++17 -I"$ROOT" \
  "$ROOT/tests/monster_registry_test.cpp" \
  "$ROOT/monsters/MonsterRegistry.cpp" \
  "$ROOT/rules/dice.cpp" \
  -o "$BIN" \
  $LUA_FLAGS

"$BIN"
