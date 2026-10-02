#!/data/data/com.termux/files/usr/bin/bash
# preflight.sh -- the gate that must pass before any git add/commit/push.
# Runs the full regtest battery on a FRESH binary (chained &&, so a
# failed build can never run a stale regtest) plus hygiene checks.
# R99: a per-file syntax gate runs FIRST - the check that
# caught the R97 enum defect lived only in chat notes, and
# its ad-hoc "|| break" form exited SUCCESS on error. Here
# the loop remembers failures; the gate ends RED.
# R107 (the lean gate): the gate now compiles only the
# TUs the battery build does NOT - every TU compiles
# exactly once per preflight (the old gate doubled the
# build's own files; the -Wswitch warning printed twice).
# It also gained monsters/MonsterXp.cpp, which no compile
# path had ever touched.
# Usage:  ./tools/preflight.sh && git add -A && git commit -m "..." && git push
# Exit 0 only when every check is green.
# R112c: two new checks born of the R112 mishap - (a) the
# battery census: every audit printf in regtest.cpp must
# appear EXACTLY ONCE in the battery output as "bad 0" (a
# double-inserted audit block or a missing audit both end
# RED); (b) hygiene FAILS when untracked file(s) exist but
# no tracked file is modified - the shape of a splice that
# never ran (the 7a86ee7 lesson). Steps renumbered to 5.

set -u
cd "$(dirname "$0")/.."
fail=0

echo "== [1/5] syntax gate: the build's complement (R99/R107) =="
# R107 (the lean gate): the battery build below compiles
# rules/, dm/, abilities/ (R118 - it was compiled by
# nothing before), items/, spells/, monsters/
# MonsterRegistry.cpp and regtest.cpp - a syntax pass
# over the same files
# was pure redundancy. This gate now covers ONLY the
# complement, so every Termux-visible TU compiles exactly
# once per preflight. Same R99 discipline: one file at a
# time so a failure names its file, NOT "|| break" - the
# loop remembers failures and the gate ends RED. A build
# failure in the build's own files still names its file in
# step 2 and ends RED there - attribution is kept.
# NEW COVERAGE: monsters/MonsterXp.cpp was compiled by NO
# path (the old loop never listed monsters/; the build
# links only MonsterRegistry.cpp) while its xpForKill/
# xpForNpc are called from game/state_dungeon.cpp - it
# joins the gate here.
# adnd1.cpp stays skipped: the Win32/GDI shell needs
# windows.h (MSVC verify pending, backlog).
checked=0
for f in game/*.cpp ai/*.cpp spelleffects/*.cpp \
         monsters/MonsterXp.cpp treasuresim.cpp; do
  if [ ! -f "$f" ]; then continue; fi
  checked=$((checked + 1))
  if ! clang++ -fsyntax-only -std=c++17 -I. "$f"; then
    echo "SYNTAX FAIL: $f"
    fail=1
  fi
done
if [ "$fail" = 0 ]; then
  echo "SYNTAX-OK: $checked complement TUs clean (the battery build covers the rest)"
fi

echo "== [2/5] regtest build + battery (fresh binary) =="
# R112c: tee keeps stdout byte-identical while the census gate
# below reads the copy; PIPESTATUS keeps regtest's own exit
# code authoritative (a failed battery still ends RED).
batfile=$(mktemp)
if g++ -std=c++17 -I. -I"$PREFIX/include/lua5.4" \
  rules/dice.cpp rules/character.cpp rules/classes.cpp rules/combat.cpp \
  rules/saves.cpp rules/turn.cpp dm/dm.cpp dm/dungeon.cpp dm/encounters.cpp \
  dm/treasure.cpp monsters/MonsterRegistry.cpp spells/spells.cpp \
  abilities/abilities.cpp items/items.cpp regtest.cpp \
  -o regtest -L"$PREFIX/lib" -llua5.4 && ./regtest | tee "$batfile"; then
  [ "${PIPESTATUS[0]}" = 0 ] || fail=1
else
  fail=1
fi

echo "== [3/5] battery audit census (R112c) =="
# Every audit printf pattern is read FROM regtest.cpp itself,
# so the gate is self-maintaining: a round's new audit is
# covered the moment its printf lands in regtest.cpp. The
# pattern is the printf text up to (not including) the %d,
# so it prefixes the printed line whatever the count is.
# Each pattern must appear EXACTLY ONCE in the battery output
# (a double-inserted audit block ends RED here - the R112b
# lesson) and no audit may report a nonzero bad count.
census_fail=0
if [ ! -f "$batfile" ]; then
  echo "CENSUS FAIL: no battery output (build failed?)"
  census_fail=1
fi
while IFS= read -r pat; do
  [ -n "$pat" ] || continue
  n=$(grep -cF "$pat" "$batfile")
  [ -n "$n" ] || n=0
  if [ "$n" -ne 1 ]; then
    echo "CENSUS FAIL: '$pat' appears $n times (expected exactly once)"
    census_fail=1
  fi
done <<R112C_PATS
$(grep 'printf("' regtest.cpp | grep -oE '[^"]*audit: bad %d' | sed 's/%d$//' | sort -u)
R112C_PATS
if grep -qE 'audit: bad [1-9]' "$batfile" 2>/dev/null; then
  echo "CENSUS FAIL: an audit reported a nonzero bad count:"
  grep -E 'audit: bad [1-9]' "$batfile"
  census_fail=1
fi
naudits=$(grep -cE 'audit: bad ' "$batfile" 2>/dev/null)
[ -n "$naudits" ] || naudits=0
if [ "$census_fail" = 0 ]; then
  echo "AUDIT CENSUS: $naudits audit lines, each exactly once, all bad 0"
else
  fail=1
fi
rm -f "$batfile"

echo "== [4/5] working tree hygiene =="
# R84: auto-clean - bytecode is always regenerable, so the gate
# removes it instead of failing (it rode into a commit once, R80;
# the FAIL taxed every splice round since)
if [ -d tools/__pycache__ ]; then
  rm -rf tools/__pycache__
  echo "NOTE: removed tools/__pycache__ (auto-clean)"
else
  echo "OK: no __pycache__"
fi
if git status --porcelain | grep -q '^??'; then
  echo "NOTE: untracked files exist:"; git status --porcelain | grep '^??'
  echo "     (not a failure - confirm they belong in this commit)"
  # R112c: untracked file(s) plus NO tracked modification is the
  # shape of a splice that never ran (commit 7a86ee7 pushed a
  # truncated splice with nothing else). Run the splice twice,
  # or delete the script if abandoning the round.
  if git diff --quiet && git diff --cached --quiet; then
    echo "HYGIENE FAIL: untracked file(s) present but NO tracked file modified"
    echo "  - did the splice run? (the 7a86ee7 lesson)"
    fail=1
  fi
fi

echo "== [5/5] branch check =="
branch=$(git rev-parse --abbrev-ref HEAD)
echo "on branch: $branch"
if [ "$branch" = "main" ]; then
  echo "NOTE: committing straight to main (Termux-gated convention)"
fi

if [ "$fail" = 0 ]; then
  echo "PREFLIGHT: GREEN - safe to commit and push"
else
  echo "PREFLIGHT: RED - fix the failures above before any git add/commit/push"
fi
exit $fail
