#!/usr/bin/env python3
# R99 the gate: the per-file syntax gate moves INTO
# tools/preflight.sh, written correctly. History: the gate
# that caught the R97 enum defect lived only in chat
# instructions, and its ad-hoc form used "|| break" - which
# exits the loop SUCCESS on error (SYNTAX-OK printed over 4
# compile errors). Here the loop remembers failures: clang
# prints its diagnosis, fail sticks, the preflight ends RED.
# adnd1.cpp is excluded - it is the Win32/GDI shell Termux
# cannot check (MSVC verify pending, backlog).
#
# Patches (4, all in tools/preflight.sh):
#   - header comment notes the gate
#   - new step [1/4] syntax gate inserted
#   - steps renumbered to [2/4]/[3/4]/[4/4]
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
# 1) the header comment notes the gate
# ---------------------------------------------------------------------------
OK &= patch('tools/preflight.sh',
"""# preflight.sh -- the gate that must pass before any git add/commit/push.
# Runs the full regtest battery on a FRESH binary (chained &&, so a
# failed build can never run a stale regtest) plus hygiene checks.
""",
"""# preflight.sh -- the gate that must pass before any git add/commit/push.
# Runs the full regtest battery on a FRESH binary (chained &&, so a
# failed build can never run a stale regtest) plus hygiene checks.
# R99: a per-file syntax gate runs FIRST - the check that
# caught the R97 enum defect lived only in chat notes, and
# its ad-hoc "|| break" form exited SUCCESS on error. Here
# the loop remembers failures; the gate ends RED.
""",
'preflight header')

# ---------------------------------------------------------------------------
# 2) the syntax gate step, inserted; regtest becomes [2/4]
# ---------------------------------------------------------------------------
OK &= patch('tools/preflight.sh',
"""echo "== [1/3] regtest build + battery (fresh binary) =="
""",
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

echo "== [2/4] regtest build + battery (fresh binary) =="
""",
'preflight syntax gate')

# ---------------------------------------------------------------------------
# 3) hygiene becomes [3/4]
# ---------------------------------------------------------------------------
OK &= patch('tools/preflight.sh',
"""echo "== [2/3] working tree hygiene =="
""",
"""echo "== [3/4] working tree hygiene =="
""",
'preflight hygiene step')

# ---------------------------------------------------------------------------
# 4) branch becomes [4/4]
# ---------------------------------------------------------------------------
OK &= patch('tools/preflight.sh',
"""echo "== [3/3] branch check =="
""",
"""echo "== [4/4] branch check =="
""",
'preflight branch step')

# ---------------------------------------------------------------------------
print()
if OK:
    print('R99 splice: ALL OK')
    sys.exit(0)
else:
    print('R99 splice: FAILED')
    sys.exit(1)
