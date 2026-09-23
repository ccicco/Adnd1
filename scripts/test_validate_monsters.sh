#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
VALIDATOR="$ROOT/scripts/validate_monsters.lua"
FIXTURES="$ROOT/tests/fixtures/monster_validation"

run_expect_success() {
  local output
  output="$($@ 2>&1)"
  echo "$output"
}

run_expect_failure() {
  local output
  set +e
  output="$($@ 2>&1)"
  local status=$?
  set -e
  echo "$output"
  if [ "$status" -eq 0 ]; then
    echo "Expected command to fail but it succeeded: $*" >&2
    exit 1
  fi
}

run_expect_success lua5.4 "$VALIDATOR" \
  "$FIXTURES/valid_imported.lua" \
  "$FIXTURES/valid_legacy.lua" >/dev/null

run_expect_failure lua5.4 "$VALIDATOR" \
  "$FIXTURES/duplicate_name_a.lua" \
  "$FIXTURES/duplicate_name_b.lua" | grep -F "duplicate monster name" >/dev/null

run_expect_failure lua5.4 "$VALIDATOR" \
  "$FIXTURES/invalid_no_appearing_range.lua" | grep -F "noAppearing.max must be >= noAppearing.min" >/dev/null

run_expect_failure lua5.4 "$VALIDATOR" \
  "$FIXTURES/invalid_damage_range.lua" | grep -F "damage[1].max must be >= damage[1].min" >/dev/null

run_expect_failure lua5.4 "$VALIDATOR" \
  "$FIXTURES/invalid_nonfinite.lua" | grep -F "field 'hitDiceNum' must be a finite number" >/dev/null

run_expect_failure lua5.4 "$VALIDATOR" \
  "$FIXTURES/malformed.lua" | grep -F "Lua syntax/load error" >/dev/null

run_expect_failure lua5.4 "$VALIDATOR" \
  "$FIXTURES/instruction_limit.lua" | grep -F "instruction limit exceeded while evaluating record" >/dev/null

echo "validator tests passed"
