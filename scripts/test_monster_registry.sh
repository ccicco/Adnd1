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

LUA_MODULE=""
for candidate in lua5.4 lua lua-5.4 lua54; do
  if pkg-config --exists "$candidate"; then
    VERSION="$(pkg-config --modversion "$candidate")"
    case "$VERSION" in
      5.4.*)
        LUA_MODULE="$candidate"
        break
        ;;
    esac
  fi
done
if [ -z "$LUA_MODULE" ]; then
  echo "Could not find a Lua 5.4 pkg-config module" >&2
  exit 1
fi

LUA_FLAGS="$(pkg-config --cflags --libs "$LUA_MODULE")"

g++ -std=c++17 -I"$ROOT" \
  "$ROOT/tests/monster_registry_test.cpp" \
  "$ROOT/monsters/MonsterRegistry.cpp" \
  "$ROOT/rules/dice.cpp" \
  -o "$BIN" \
  $LUA_FLAGS

"$BIN"
