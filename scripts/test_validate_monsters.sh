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
  "$FIXTURES/invalid_nonfinite_positive_inf.lua" | grep -F "field 'hitDiceNum' must be a finite number" >/dev/null

run_expect_failure lua5.4 "$VALIDATOR" \
  "$FIXTURES/invalid_nonfinite_negative_inf.lua" | grep -F "field 'hitDiceNum' must be a finite number" >/dev/null

run_expect_failure lua5.4 "$VALIDATOR" \
  "$FIXTURES/malformed.lua" | grep -F "Lua syntax/load error" >/dev/null

run_expect_failure lua5.4 "$VALIDATOR" \
  "$FIXTURES/missing_required_alignment.lua" | grep -F "field 'alignment' is required" >/dev/null

run_expect_failure lua5.4 "$VALIDATOR" \
  "$FIXTURES/invalid_move_rate_fraction.lua" | grep -F "field 'move.rate' must be an integer" >/dev/null

run_expect_failure lua5.4 "$VALIDATOR" \
  "$FIXTURES/invalid_damage_not_array.lua" | grep -F "field 'damage' must be a dense 1-based array" >/dev/null

run_expect_failure lua5.4 "$VALIDATOR" \
  "$FIXTURES/invalid_move_modes_not_array.lua" | grep -F "field 'move.modes' must be a dense 1-based array" >/dev/null

run_expect_failure lua5.4 "$VALIDATOR" \
  "$FIXTURES/invalid_move_missing_rate_and_modes.lua" | grep -F "field 'move' must include rate or at least one move.modes entry" >/dev/null

run_expect_failure lua5.4 "$VALIDATOR" \
  "$FIXTURES/legacy_missing_xp.lua" | grep -F "field 'xp' or 'xpValue' is required" >/dev/null

run_expect_failure lua5.4 "$VALIDATOR" \
  "$FIXTURES/mixed_schema.lua" | grep -F "record mixes imported and legacy schema fields" >/dev/null

run_expect_failure lua5.4 "$VALIDATOR" \
  "$FIXTURES/instruction_limit.lua" | grep -F "instruction limit exceeded while evaluating record" >/dev/null

run_expect_failure lua5.4 "$VALIDATOR" \
  "$FIXTURES/sandbox_global_read.lua" | grep -F "global 'UNKNOWN_GLOBAL' is not available in validator sandbox" >/dev/null

run_expect_failure lua5.4 "$VALIDATOR" \
  "$FIXTURES/sandbox_global_assign.lua" | grep -F "global assignment 'BAD_GLOBAL' is not allowed in validator sandbox" >/dev/null

echo "validator tests passed"
