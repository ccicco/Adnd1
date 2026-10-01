#!/usr/bin/env python3
# R107 the lean gate (MAINTENANCE): the user spotted that
# every preflight compiled every Termux-visible TU TWICE -
# once in the R99 syntax gate, once in the battery build
# (the -Wswitch warning printed twice per run). The gate
# now compiles ONLY the build's complement:
#   gate (10 TUs): game/*.cpp ai/*.cpp spelleffects/*.cpp
#                  monsters/MonsterXp.cpp treasuresim.cpp
#   build (14 TUs): rules/* dm/* items spells regtest
#                  monsters/MonsterRegistry.cpp
# Every TU compiles exactly once per preflight (36 compile
# passes -> 24), coverage is IDENTICAL plus one gain:
# monsters/MonsterXp.cpp had NEVER been compiled by any
# path (the R99 loop never listed monsters/; the build
# only links MonsterRegistry.cpp) - yet its xpForKill/
# xpForNpc are called from game/state_dungeon.cpp. It
# joins the gate. A build failure in the build's own files
# still names its file and ends RED - attribution kept.
#
# Patches (3):
#   tools/preflight.sh - header note + the lean gate
#   tools/maintenance_survey_r104.md - R107 appendix
import sys, os

os.chdir(os.path.dirname(os.path.abspath(__file__)) + '/..')

def rd(p):
    with open(p, 'r', encoding='ascii') as f:
        return f.read()

def wr(p, s):
    with open(p, 'w', encoding='ascii') as f:
        f.write(s)

OK = True

def patch(path, anchor, repl, label):
    global OK
    s = rd(path)
    if repl in s:
        print(label + ': already patched')
        return True
    i = s.find(anchor)
    if i < 0:
        print(label + ': ANCHOR MISS')
        OK = False
        return False
    s = s.replace(anchor, repl, 1)
    wr(path, s)
    print(label + ': patched')
    return True

# ---------------------------------------------------------------------------
# 1) preflight.sh - the header note
# ---------------------------------------------------------------------------
OK &= patch('tools/preflight.sh',
"""# R99: a per-file syntax gate runs FIRST - the check that
# caught the R97 enum defect lived only in chat notes, and
# its ad-hoc "|| break" form exited SUCCESS on error. Here
# the loop remembers failures; the gate ends RED.
""",
"""# R99: a per-file syntax gate runs FIRST - the check that
# caught the R97 enum defect lived only in chat notes, and
# its ad-hoc "|| break" form exited SUCCESS on error. Here
# the loop remembers failures; the gate ends RED.
# R107 (the lean gate): the gate now compiles only the
# TUs the battery build does NOT - every TU compiles
# exactly once per preflight (the old gate doubled the
# build's own files; the -Wswitch warning printed twice).
# It also gained monsters/MonsterXp.cpp, which no compile
# path had ever touched.
""",
'preflight header note')

# ---------------------------------------------------------------------------
# 2) preflight.sh - the lean gate
# ---------------------------------------------------------------------------
OK &= patch('tools/preflight.sh',
"""echo "== [1/4] per-file syntax gate (R99) =="
# Every Termux-visible translation unit, one at a time, so
# a failure names its file. NOT "|| break" - a break exits
# the loop with the loop's last (successful) status and the
# old ad-hoc gate printed SYNTAX-OK over real errors.
# adnd1.cpp is skipped: the Win32/GDI shell needs windows.h
# (MSVC verify pending, backlog).
for f in game/*.cpp rules/*.cpp dm/*.cpp items/*.cpp \\
         spells/*.cpp spelleffects/*.cpp ai/*.cpp \\
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
""",
"""echo "== [1/4] syntax gate: the build's complement (R99/R107) =="
# R107 (the lean gate): the battery build below compiles
# rules/, dm/, items/, spells/, monsters/MonsterRegistry
# .cpp and regtest.cpp - a syntax pass over the same files
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
for f in game/*.cpp ai/*.cpp spelleffects/*.cpp \\
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
""",
'preflight lean gate')

# ---------------------------------------------------------------------------
# 3) the survey doc - the R107 appendix
# ---------------------------------------------------------------------------
OK &= patch('tools/maintenance_survey_r104.md',
"""## Standing rules from this survey
""",
"""## R107 appendix - the lean gate

The user spotted the doubled -Wswitch warning: every
preflight compiled every Termux-visible TU twice (the R99
syntax gate + the battery build). The gate now compiles
only the build's complement (game/, ai/, spelleffects/,
treasuresim.cpp) - every TU compiles exactly once per
preflight, 36 compile passes down to 24. Coverage gain
found by the survey: monsters/MonsterXp.cpp had never
been compiled by ANY path (old gate never listed
monsters/, build links only MonsterRegistry.cpp) while
its xpForKill/xpForNpc are called from
game/state_dungeon.cpp - it joined the gate.

## Standing rules from this survey
""",
'survey appendix')

# ---------------------------------------------------------------------------
print()
if OK:
    print('R107 splice: ALL OK')
    sys.exit(0)
else:
    print('R107 splice: FAILED')
    sys.exit(1)
