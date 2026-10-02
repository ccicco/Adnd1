#!/usr/bin/env python3
# R112c splice: harden tools/preflight.sh so the two R112 failure
# classes can never reach a commit again:
#   - the 7a86ee7 class (truncated splice ran no patch; preflight
#     was GREEN on a pristine tree and a splice-only commit pushed):
#     hygiene now FAILS when untracked file(s) exist but NO tracked
#     file is modified - a splice that has not run looks exactly
#     like that.
#   - the double-insert class (a second splice run re-inserted the
#     combat/regtest blocks; the battery would print the audit line
#     twice): a new battery census gate reads every
#     "... audit: bad %d" printf pattern FROM regtest.cpp (self-
#     maintaining - each round's new audit is covered the moment it
#     is written) and requires each to appear EXACTLY ONCE in the
#     battery output and end in "bad 0".
# Steps renumber to 5. The battery build line gains a tee into a
# mktemp file (battery stdout stays byte-identical); the census
# reads it, then deletes it.
# Idempotent (single marker check, the R112b lesson). ASCII-only.
# Refuses non-unique anchors. Run twice - second run: nothing to do.
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MARKER = "battery audit census (R112c)"


def read(rel):
    with open(os.path.join(ROOT, rel), "r", encoding="ascii") as f:
        return f.read()


def write(rel, text):
    with open(os.path.join(ROOT, rel), "w", encoding="ascii") as f:
        f.write(text)


def replace_exact(text, old, new, label):
    n = text.count(old)
    if n != 1:
        print("REFUSED " + label + ": anchor not unique or missing (count %d)" % n)
        return text, False
    return text.replace(old, new, 1), True


def main():
    s = read("tools/preflight.sh")
    if MARKER in s:
        print("already applied: preflight R112c hardening")
        print("R112c splice: nothing to do (already applied)")
        return
    changed = 0

    # 1. header note
    old = "# Usage:  ./tools/preflight.sh && git add -A && git commit -m \"...\" && git push\n# Exit 0 only when every check is green.\n"
    new = ("# Usage:  ./tools/preflight.sh && git add -A && git commit -m \"...\" && git push\n"
           "# Exit 0 only when every check is green.\n"
           "# R112c: two new checks born of the R112 mishap - (a) the\n"
           "# battery census: every audit printf in regtest.cpp must\n"
           "# appear EXACTLY ONCE in the battery output as \"bad 0\" (a\n"
           "# double-inserted audit block or a missing audit both end\n"
           "# RED); (b) hygiene FAILS when untracked file(s) exist but\n"
           "# no tracked file is modified - the shape of a splice that\n"
           "# never ran (the 7a86ee7 lesson). Steps renumbered to 5.\n")
    s, did = replace_exact(s, old, new, "preflight header note")
    changed += did

    # 2. renumber step banners
    s, did = replace_exact(s, 'echo "== [1/4] syntax gate',
                           'echo "== [1/5] syntax gate', "banner 1")
    changed += did
    s, did = replace_exact(s, 'echo "== [2/4] regtest build',
                           'echo "== [2/5] regtest build', "banner 2")
    changed += did

    # 3. build line: tee the battery into a temp file (byte-identical
    #    stdout; regtest's own exit code preserved via PIPESTATUS)
    old = ("g++ -std=c++17 -I. -I\"$PREFIX/include/lua5.4\" \\\n"
           "  rules/dice.cpp rules/character.cpp rules/classes.cpp rules/combat.cpp \\\n"
           "  rules/saves.cpp rules/turn.cpp dm/dm.cpp dm/dungeon.cpp dm/encounters.cpp \\\n"
           "  dm/treasure.cpp monsters/MonsterRegistry.cpp spells/spells.cpp \\\n"
           "  items/items.cpp regtest.cpp \\\n"
           "  -o regtest -L\"$PREFIX/lib\" -llua5.4 && ./regtest || fail=1\n")
    new = ("# R112c: tee keeps stdout byte-identical while the census gate\n"
           "# below reads the copy; PIPESTATUS keeps regtest's own exit\n"
           "# code authoritative (a failed battery still ends RED).\n"
           "batfile=$(mktemp)\n"
           "if g++ -std=c++17 -I. -I\"$PREFIX/include/lua5.4\" \\\n"
           "  rules/dice.cpp rules/character.cpp rules/classes.cpp rules/combat.cpp \\\n"
           "  rules/saves.cpp rules/turn.cpp dm/dm.cpp dm/dungeon.cpp dm/encounters.cpp \\\n"
           "  dm/treasure.cpp monsters/MonsterRegistry.cpp spells/spells.cpp \\\n"
           "  items/items.cpp regtest.cpp \\\n"
           "  -o regtest -L\"$PREFIX/lib\" -llua5.4 && ./regtest | tee \"$batfile\"; then\n"
           "  [ \"${PIPESTATUS[0]}\" = 0 ] || fail=1\n"
           "else\n"
           "  fail=1\n"
           "fi\n")
    s, did = replace_exact(s, old, new, "build tee")
    changed += did

    # 4. the census gate + hygiene renumber, in one edit
    old = 'echo "== [3/4] working tree hygiene ==\"\n'
    new = ('echo "== [3/5] battery audit census (R112c) ==\"\n'
           "# Every audit printf pattern is read FROM regtest.cpp itself,\n"
           "# so the gate is self-maintaining: a round's new audit is\n"
           "# covered the moment its printf lands in regtest.cpp. The\n"
           "# pattern is the printf text up to (not including) the %d,\n"
           "# so it prefixes the printed line whatever the count is.\n"
           "# Each pattern must appear EXACTLY ONCE in the battery output\n"
           "# (a double-inserted audit block ends RED here - the R112b\n"
           "# lesson) and no audit may report a nonzero bad count.\n"
           "census_fail=0\n"
           "if [ ! -f \"$batfile\" ]; then\n"
           "  echo \"CENSUS FAIL: no battery output (build failed?)\"\n"
           "  census_fail=1\n"
           "fi\n"
           "while IFS= read -r pat; do\n"
           "  [ -n \"$pat\" ] || continue\n"
           "  n=$(grep -cF \"$pat\" \"$batfile\")\n"
           "  [ -n \"$n\" ] || n=0\n"
           "  if [ \"$n\" -ne 1 ]; then\n"
           "    echo \"CENSUS FAIL: '$pat' appears $n times (expected exactly once)\"\n"
           "    census_fail=1\n"
           "  fi\n"
           "done <<R112C_PATS\n"
           "$(grep 'printf(\"' regtest.cpp | grep -oE '[^\"]*audit: bad %d' | sed 's/%d$//' | sort -u)\n"
           "R112C_PATS\n"
           "if grep -qE 'audit: bad [1-9]' \"$batfile\" 2>/dev/null; then\n"
           "  echo \"CENSUS FAIL: an audit reported a nonzero bad count:\"\n"
           "  grep -E 'audit: bad [1-9]' \"$batfile\"\n"
           "  census_fail=1\n"
           "fi\n"
           "naudits=$(grep -cE 'audit: bad ' \"$batfile\" 2>/dev/null)\n"
           "[ -n \"$naudits\" ] || naudits=0\n"
           "if [ \"$census_fail\" = 0 ]; then\n"
           "  echo \"AUDIT CENSUS: $naudits audit lines, each exactly once, all bad 0\"\n"
           "else\n"
           "  fail=1\n"
           "fi\n"
           "rm -f \"$batfile\"\n"
           "\n"
           'echo "== [4/5] working tree hygiene ==\"\n')
    s, did = replace_exact(s, old, new, "census gate + hygiene banner")
    changed += did

    # 5. hygiene: untracked-but-unmodified FAIL (the 7a86ee7 shape)
    old = ("if git status --porcelain | grep -q '^??'; then\n"
           "  echo \"NOTE: untracked files exist:\"; git status --porcelain | grep '^??'\n"
           "  echo \"     (not a failure - confirm they belong in this commit)\"\n"
           "fi\n")
    new = ("if git status --porcelain | grep -q '^??'; then\n"
           "  echo \"NOTE: untracked files exist:\"; git status --porcelain | grep '^??'\n"
           "  echo \"     (not a failure - confirm they belong in this commit)\"\n"
           "  # R112c: untracked file(s) plus NO tracked modification is the\n"
           "  # shape of a splice that never ran (commit 7a86ee7 pushed a\n"
           "  # truncated splice with nothing else). Run the splice twice,\n"
           "  # or delete the script if abandoning the round.\n"
           "  if git diff --quiet && git diff --cached --quiet; then\n"
           "    echo \"HYGIENE FAIL: untracked file(s) present but NO tracked file modified\"\n"
           "    echo \"  - did the splice run? (the 7a86ee7 lesson)\"\n"
           "    fail=1\n"
           "  fi\n"
           "fi\n")
    s, did = replace_exact(s, old, new, "hygiene untracked check")
    changed += did

    # 6. renumber the branch banner
    s, did = replace_exact(s, 'echo "== [4/4] branch check =="',
                           'echo "== [5/5] branch check =="', "banner 5")
    changed += did

    if changed == 7:
        write("tools/preflight.sh", s)
        print("R112c splice: ALL OK")
    else:
        print("REFUSED R112c: only %d of 7 patches applied - nothing written" % changed)


main()
