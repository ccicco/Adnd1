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
  local expected_message="$1"
  local expected_summary="$2"
  shift 2
  local output
  set +e
  output="$($@ 2>&1)"
  local status=$?
  set -e
  if [ "$status" -ne 1 ]; then
    echo "Expected command to fail with status 1, got $status: $*" >&2
    echo "$output" >&2
    exit 1
  fi
  if [[ "$output" != *"$expected_message"* ]]; then
    echo "Missing expected message: $expected_message" >&2
    echo "$output" >&2
    exit 1
  fi
  if [[ "$output" != *"$expected_summary"* ]]; then
    echo "Missing expected summary: $expected_summary" >&2
    echo "$output" >&2
    exit 1
  fi
}

run_expect_success lua5.4 "$VALIDATOR" \
  "$FIXTURES/valid_imported.lua" \
  "$FIXTURES/valid_legacy.lua" >/dev/null

run_expect_success lua5.4 "$VALIDATOR" \
  "$FIXTURES/valid_lair_pct.lua" >/dev/null

run_expect_failure "duplicate monster name" "1 error(s) in 2 monster file(s)" lua5.4 "$VALIDATOR" \
  "$FIXTURES/duplicate_name_a.lua" \
  "$FIXTURES/duplicate_name_b.lua"

run_expect_failure "noAppearing.max must be >= noAppearing.min" "1 error(s) in 1 monster file(s)" lua5.4 "$VALIDATOR" \
  "$FIXTURES/invalid_no_appearing_range.lua"

run_expect_failure "damage[1].max must be >= damage[1].min" "1 error(s) in 1 monster file(s)" lua5.4 "$VALIDATOR" \
  "$FIXTURES/invalid_damage_range.lua"

run_expect_failure "field 'hitDiceNum' must be a finite number" "1 error(s) in 1 monster file(s)" lua5.4 "$VALIDATOR" \
  "$FIXTURES/invalid_nonfinite.lua"

run_expect_failure "field 'hitDiceNum' must be a finite number" "1 error(s) in 1 monster file(s)" lua5.4 "$VALIDATOR" \
  "$FIXTURES/invalid_nonfinite_positive_inf.lua"

run_expect_failure "field 'hitDiceNum' must be a finite number" "1 error(s) in 1 monster file(s)" lua5.4 "$VALIDATOR" \
  "$FIXTURES/invalid_nonfinite_negative_inf.lua"

run_expect_failure "Lua syntax/load error" "1 error(s) in 1 monster file(s)" lua5.4 "$VALIDATOR" \
  "$FIXTURES/malformed.lua"

run_expect_failure "field 'alignment' is required" "1 error(s) in 1 monster file(s)" lua5.4 "$VALIDATOR" \
  "$FIXTURES/missing_required_alignment.lua"

run_expect_failure "field 'lairPct' must be <= 100" "1 error(s) in 1 monster file(s)" lua5.4 "$VALIDATOR" \
  "$FIXTURES/invalid_lair_pct.lua"

run_expect_failure "field 'move.rate' must be an integer" "1 error(s) in 1 monster file(s)" lua5.4 "$VALIDATOR" \
  "$FIXTURES/invalid_move_rate_fraction.lua"

run_expect_failure "field 'damage' must be a dense 1-based array" "1 error(s) in 1 monster file(s)" lua5.4 "$VALIDATOR" \
  "$FIXTURES/invalid_damage_not_array.lua"

run_expect_failure "field 'damage' must be a dense 1-based array" "1 error(s) in 1 monster file(s)" lua5.4 "$VALIDATOR" \
  "$FIXTURES/invalid_damage_sparse.lua"

run_expect_failure "field 'move.modes' must be a dense 1-based array" "1 error(s) in 1 monster file(s)" lua5.4 "$VALIDATOR" \
  "$FIXTURES/invalid_move_modes_not_array.lua"

run_expect_failure "field 'move.modes' must be a dense 1-based array" "1 error(s) in 1 monster file(s)" lua5.4 "$VALIDATOR" \
  "$FIXTURES/invalid_move_modes_sparse.lua"

run_expect_failure "field 'move' must include rate or at least one move.modes entry" "1 error(s) in 1 monster file(s)" lua5.4 "$VALIDATOR" \
  "$FIXTURES/invalid_move_missing_rate_and_modes.lua"

run_expect_failure "field 'xpValue' is required (or legacy fallback 'xp')" "1 error(s) in 1 monster file(s)" lua5.4 "$VALIDATOR" \
  "$FIXTURES/legacy_missing_xp.lua"

run_expect_failure "record mixes imported and legacy schema fields" "1 error(s) in 1 monster file(s)" lua5.4 "$VALIDATOR" \
  "$FIXTURES/mixed_schema.lua"

run_expect_failure "instruction limit exceeded while evaluating record" "1 error(s) in 1 monster file(s)" lua5.4 "$VALIDATOR" \
  "$FIXTURES/instruction_limit.lua"

run_expect_failure "global 'UNKNOWN_GLOBAL' is not available in validator sandbox" "1 error(s) in 1 monster file(s)" lua5.4 "$VALIDATOR" \
  "$FIXTURES/sandbox_global_read.lua"

run_expect_failure "global assignment 'BAD_GLOBAL' is not allowed in validator sandbox" "1 error(s) in 1 monster file(s)" lua5.4 "$VALIDATOR" \
  "$FIXTURES/sandbox_global_assign.lua"

run_expect_failure "error while evaluating file: coroutine yielded; file must return directly" "1 error(s) in 1 monster file(s)" lua5.4 "$VALIDATOR" \
  "$FIXTURES/yield_record.lua"

echo "validator tests passed"
