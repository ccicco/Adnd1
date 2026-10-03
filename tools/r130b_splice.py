#!/usr/bin/python3
# tools/r130b_splice.py - R130b repair (the r130 splice's
# two failed patches + the audit's bare names, both caught
# by the user's build; the slot tables and gates stand).
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints.
#  - regtest.cpp: the R130 audit block is rebuilt with
#    namespaced spells:: calls and the real cleric enum
#    (SPELL_CLERIC, not SPELL_CL) - the first R130 paste
#    ran bare names, which no other audit does; the R129
#    audit's own "tables encode 1-6" comment (the comment
#    P6 meant to hit - its anchor text only exists in
#    spells.cpp) updates to the printed-tables wording
#    with the 12th-level pins standing
#  - tools/dmg_gap_report.md: the R130 box inserts with the
#    CORRECT indented anchor (the r130 splice missed the
#    six leading spaces on "Pinned by the R128...")
#  - sanity gates: the six r130-applied markers and the
#    held-row counts are verified (guards the paste
#    truncation - your file landed 389/420 lines)
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding="ascii") as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), "w", encoding="ascii") as f:
        f.write(s)

def patch(p, old, new, tag, expect=1, marker=None):
    s = rd(p)
    if marker is None:
        marker = new
    if marker in s:
        already.append(tag)
        return
    n = s.count(old)
    if n != expect:
        fails.append(tag + ": anchor count " + str(n)
                     + " (expected " + str(expect) + ")")
        return
    wr(p, s.replace(old, new))
    applied.append(tag)

def check(p, needle, expect, tag):
    n = rd(p).count(needle)
    if n != expect:
        fails.append(tag + ": count " + str(n)
                     + " (expected " + str(expect) + ")")

# ---- sanity gates on the r130 state (paste was 389/420) ----
check("spells/spells.h",
      "R130 line-diffed the tables against the", 1,
      "gate: spells.h doc")
check("spells/spells.cpp",
      "R130 line-diff against the", 1,
      "gate: slot tables block")
check("spells/spells.cpp",
      "R130 delivered", 1,
      "gate: R129 comment update")
check("spells/spells.cpp",
      "if (classLevel < 17) return 6;", 1,
      "gate: cleric 7th gate")
check("spells/spells.cpp",
      "if (int_ < 17) return 6;", 1,
      "gate: INT gate")
check("spells/spells.cpp",
      "{5,5,5,5,5,4,3,3,2},", 10,
      "gate: MU L20 + 9 held rows")
check("spells/spells.cpp",
      "{9,9,9,9,9,9,7,0,0},", 1,
      "gate: CL L29 row")
if fails:
    print("R130b splice: FAIL - sanity gates tripped; do NOT")
    print("  commit. Paste me this output plus the tail of")
    print("  your r130_splice.py (last 40 lines).")
    sys.exit(1)

# ---- B1: the R129 audit's stale comment (regtest's own) ----
patch("regtest.cpp",
"""        // cast-pending: the slot tables encode 1-6, so
        // levels 7-9 yield no slots at any class level
""",
"""        // R130: the printed tables now encode 1-9; these
        // 12th-level pins still hold (no 7th-9th at 12)
""",
      "regtest.cpp: R129 comment update",
      marker="12th-level pins still hold")

# ---- B2: the R130 audit block, rebuilt namespaced ----
# span surgery: whatever the truncated paste left between
# the R130 marker and its closing brace is replaced whole
NEW_BLOCK = """    // ---- R130: high-level slots audit ----
    // PHB class-table pins: corrected low rows, printed
    // high rows, the holds past the print, and the gates.
    // Line-diff source: the 1eonline.info PHB compilation.
    // R130b: namespaced spells:: calls (the first R130
    // paste ran bare names - caught by the user's build).
    {
        int bad = 0;
        // the corrected R80 rows (levels 7-12)
        if (spells::spellSlots(spells::SPELL_MU, 7, 1) != 4) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 8, 2) != 3) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 9, 5) != 1) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 10, 4) != 3) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 11, 5) != 3) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 12, 6) != 4) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 6, 3) != 2) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 7, 4) != 1) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 8, 4) != 2) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 9, 5) != 1) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 10, 5) != 2) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 11, 1) != 5) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 12, 1) != 6) ++bad;
        // the printed high rows (13-20)
        if (spells::spellSlots(spells::SPELL_MU, 13, 6) != 2) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 17, 7) != 2) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 18, 9) != 1) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 20, 9) != 2) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 13, 5) != 2) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 16, 7) != 1) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 17, 7) != 1) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 20, 7) != 2) ++bad;
        // the holds past the print (L29 = the final row)
        if (spells::spellSlots(spells::SPELL_MU, 29, 9) != 2) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 29, 7) != 7) ++bad;
        // the gates: cleric 7th at 17; INT 17 -> 7, 18 -> 9
        if (spells::maxSpellLevelForClericLevel(16) != 6) ++bad;
        if (spells::maxSpellLevelForClericLevel(17) != 7) ++bad;
        if (spells::maxSpellLevelForClericLevel(29) != 7) ++bad;
        if (spells::maxSpellLevelForInt(15) != 5) ++bad;
        if (spells::maxSpellLevelForInt(16) != 6) ++bad;
        if (spells::maxSpellLevelForInt(17) != 7) ++bad;
        if (spells::maxSpellLevelForInt(18) != 9) ++bad;
        printf("R130 high-level slots audit: bad %d\\n", bad);
        if (bad) return 1;
    }
"""

s = rd("regtest.cpp")
if "R130b: namespaced" in s:
    already.append("regtest.cpp: R130 audit rebuild")
else:
    a = s.find("    // ---- R130: high-level slots audit ----")
    if a < 0:
        fails.append("regtest.cpp: R130 audit rebuild: start marker not found")
    else:
        pr = s.find('printf("R130 high-level slots audit: bad', a)
        if pr < 0:
            fails.append("regtest.cpp: R130 audit rebuild: printf not found")
        else:
            b = s.find("    }\n", pr)
            if b < 0:
                fails.append("regtest.cpp: R130 audit rebuild: close brace not found")
            else:
                b += len("    }\n")
                wr("regtest.cpp", s[:a] + NEW_BLOCK + s[b:])
                applied.append("regtest.cpp: R130 audit rebuild")

# ---- B3: the gap report box (indented anchor) ----
patch("tools/dmg_gap_report.md",
"""      Pinned by the R128 battery audit; census 46.

## Out of scope by design
""",
"""      Pinned by the R128 battery audit; census 46.
- [x] **High-level spell slot tables (PHB
      class tables)** - CLOSED R130: the slot tables
      themselves were the last print-omission in the
      spell pipeline - line-diffed against the
      1eonline.info PHB compilation (class Table I +
      the SPELLS USABLE appendix): 9 spell levels
      encoded, MU printed rows to L20, cleric to L29,
      final row holds beyond the print; the R80
      project-notes rows 7-12 corrected to print; the
      cleric 7th gate lands at 17 (the printed Wis-18
      footnote at 16 not modeled - engine limit); the
      INT gate extends 17 -> 7th, 18 -> 8th/9th (the
      "highest intelligence" note - a convention
      extension riding the standing verification
      debt). The tables and gates now encode levels
      7-9 (the R129 caster-aging spells resolve at
      name level); the per-day slotsByLevel plumbing
      still tracks 6 - named debt, rides future
      rounds. Pinned by the R130 battery audit;
      census 48.

## Out of scope by design
""",
      "gap report: R130 box",
      marker="CLOSED R130: the slot tables")

# ---- R130b fails/tail ----
if fails:
    print("R130b splice: FAIL - " + str(len(fails)) + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if already and not applied:
    print("R130b splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R130b splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
