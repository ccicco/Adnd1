#!/data/data/com.termux/files/usr/bin/bash
# preflight.sh -- the gate that must pass before any git add/commit/push.
# Runs the full regtest battery on a FRESH binary (chained &&, so a
# failed build can never run a stale regtest) plus hygiene checks.
# R99: a per-file syntax gate runs FIRST - the check that
# caught the R97 enum defect lived only in chat notes, and
# its ad-hoc "|| break" form exited SUCCESS on error. Here
# the loop remembers failures; the gate ends RED.
# Usage:  ./tools/preflight.sh && git add -A && git commit -m "..." && git push
# Exit 0 only when every check is green.

set -u
cd "$(dirname "$0")/.."
fail=0

echo "== [1/4] per-file syntax gate (R99) =="
# Every Termux-visible translation unit, one at a time, so
# a failure names its file. NOT "|| break" - a break exits
# the loop with the loop's last (successful) status and the
# old ad-hoc gate printed SYNTAX-OK over real errors.
# adnd1.cpp is skipped: the Win32/GDI shell needs windows.h
# (MSVC verify pending, backlog).
for f in game/*.cpp rules/*.cpp dm/*.cpp items/*.cpp \
         spells/*.cpp spelleffects/*.cpp ai/*.cpp \
         regtest.cpp treasuresim.cpp; do
  if [ ! -f "$f" ]; then continue; fi
  if ! clang++ -fsyntax-only -std=c++17 -I. "$f"; then
    echo "SYNTAX FAIL: $f"
    fail=1
  fi
done
if [ "$fail" = 0 ]; then
  echo "SYNTAX-OK: all Termux-visible translation units clean"
fi

echo "== [2/4] regtest build + battery (fresh binary) =="
g++ -std=c++17 -I. -I"$PREFIX/include/lua5.4" \
  rules/dice.cpp rules/character.cpp rules/classes.cpp rules/combat.cpp \
  rules/saves.cpp rules/turn.cpp dm/dm.cpp dm/dungeon.cpp dm/encounters.cpp \
  dm/treasure.cpp monsters/MonsterRegistry.cpp spells/spells.cpp \
  items/items.cpp regtest.cpp \
  -o regtest -L"$PREFIX/lib" -llua5.4 && ./regtest || fail=1

echo "== [3/4] working tree hygiene =="
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
fi

echo "== [4/4] branch check =="
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
