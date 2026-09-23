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

LUA_FLAGS=()
while IFS= read -r -d '' flag; do
  LUA_FLAGS+=("$flag")
done < <(
  LUA_MODULE="$LUA_MODULE" python3 - <<'PY'
import os
import shlex
import subprocess
import sys

out = subprocess.check_output(
    ["pkg-config", "--cflags", "--libs", os.environ["LUA_MODULE"]],
    text=True,
)
for token in shlex.split(out):
    sys.stdout.buffer.write(token.encode())
    sys.stdout.buffer.write(b"\0")
PY
)

SOURCES=(
  # Single source-of-truth for the portable engine units needed by
  # the monster registry/runtime boundary test.
  "$ROOT/tests/monster_registry_test.cpp"
  "$ROOT/ai/actor.cpp"
  "$ROOT/dm/dm.cpp"
  "$ROOT/items/items.cpp"
  "$ROOT/monsters/MonsterRegistry.cpp"
  "$ROOT/rules/character.cpp"
  "$ROOT/rules/combat.cpp"
  "$ROOT/rules/dice.cpp"
  "$ROOT/rules/saves.cpp"
  "$ROOT/rules/turn.cpp"
  "$ROOT/spelleffects/spelleffects.cpp"
  "$ROOT/spells/spells.cpp"
)

g++ -std=c++17 -I"$ROOT" \
  "${SOURCES[@]}" \
  -o "$BIN" \
  "${LUA_FLAGS[@]}"

"$BIN"
