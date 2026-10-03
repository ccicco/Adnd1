#!/usr/bin/python3
# tools/r130_splice.py - R130 high-level spell slots (PHB
# class tables, line-diffed - the levels 7-9 rows the R129
# caster-aging spells need).
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints.
#  - spells/spells.cpp + .h: the slot tables line-diffed
#    against the 1eonline.info PHB compilation (class Table
#    I + the SPELLS USABLE appendix): 9 spell levels
#    encoded, MU printed rows to L20, cleric to L29, beyond
#    the print the final row holds; the R80 project-notes
#    rows 7-12 corrected to the printed values (rows 1-6
#    matched); the MU L17 7th slot pinned on the appendix
#    reading with the Table I variant documented
#  - spells.cpp: maxSpellLevelForClericLevel gains 7th at
#    17 (the Wis 18 footnote at 16 not modeled); the INT
#    gate extends: 17 -> 7th circle, 18 -> 8th and 9th
#  - regtest.cpp: the R130 high-level slots audit pins the
#    corrected rows, the printed high rows, the holds, and
#    the gates (census 48); the R129 cast-pending comment
#    updates (its 12th-level pins stand)
#  - tools/dmg_gap_report.md: the R130 box closes
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
    # idempotency keys on a distinctive NEW-side marker
    # (the R125 lesson; an anchor that is a PREFIX of its
    # replacement still counts after the patch)
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

# R130-CHUNK-1-START (spells.h + spells.cpp)

patch("spells/spells.h",
r"""
// Spell slots (PHB class tables): usable spells per spell level at
// a given class level. Rows to name level; beyond, max row repeats
// (1e: gained spells stop advancing - followers/strongholds take
// over; rebuild convention: hold at final row).
// ----------------------------------------------------------------------------
int spellSlots(SpellClass sc, int classLevel, int spellLevel);""",
r"""
// Spell slots (PHB class tables): usable spells per spell level at
// a given class level. R130 line-diffed the tables against the
// 1eonline.info PHB compilation (the class Table I and the SPELLS
// USABLE BY CLASS AND LEVEL appendix): MU printed rows run to L20,
// cleric to L29, spell levels 1-9 / 1-7 encoded; the R80 project-
// notes rows 7-12 were corrected to the printed values (rows 1-6
// matched). Beyond the printed rows the final row holds. The
// printed wisdom footnotes (6th: Wis 17 at cleric 11; 7th: Wis 18
// at cleric 16) are not modeled - the level-only gates are
// documented engine limits.
// ----------------------------------------------------------------------------
int spellSlots(SpellClass sc, int classLevel, int spellLevel);""",
      "spells.h: slot doc comment",
      marker="R130 line-diffed the tables against the")

patch("spells/spells.cpp",
r"""
// Slot tables (PHB p.20+)
//   MU: L1: 1 slot;  L2: 2; L3: 2/1; L4: 3/2; L5: 4/2/1; L6: 4/2/2;
//       L7: 5/3/2/1 ... (rows to L12)
//   Cleric: L1: 1; L2: 2; L3: 2/1; L4: 3/2; L5: 3/3/1;
//       L6: 4/3/2; L7: 5/3/2/1 ... (rows to L12)
// Encoded: max spell level 6 (columns), levels 1-12 (rows).
// ----------------------------------------------------------------------------

static const int kSlots = 6;      // spell levels 1-6 encoded
static const int kLevels = 12;    // class levels 1-12

static const int kMuSlots[kLevels][kSlots] = {
    {1,0,0,0,0,0},{2,0,0,0,0,0},{2,1,0,0,0,0},{3,2,0,0,0,0},
    {4,2,1,0,0,0},{4,2,2,0,0,0},{5,3,2,1,0,0},{5,3,3,2,0,0},
    {5,3,3,2,1,0},{5,4,4,2,1,0},{5,4,4,2,2,0},{5,4,4,3,2,1},
};
static const int kClericSlots[kLevels][kSlots] = {
    {1,0,0,0,0,0},{2,0,0,0,0,0},{2,1,0,0,0,0},{3,2,0,0,0,0},
    {3,3,1,0,0,0},{4,3,2,0,0,0},{5,3,2,1,0,0},{5,4,3,2,0,0},
    {5,4,4,2,1,0},{5,5,4,3,2,0},{5,5,5,3,2,1},{5,5,5,4,3,2},
};

int spellSlots(SpellClass sc, int classLevel, int spellLevel) {
    if (spellLevel < 1 || spellLevel > kSlots) return 0;
    if (classLevel < 1) classLevel = 1;
    if (classLevel > kLevels) classLevel = kLevels;
    return (sc == SPELL_MU ? kMuSlots : kClericSlots)
               [classLevel - 1][spellLevel - 1];
}""",
r"""
// Slot tables (PHB class tables - R130 line-diff against the
// 1eonline.info PHB compilation: the class Table I and the
// SPELLS USABLE BY CLASS AND LEVEL appendix, which agree row
// for row except the MU L17 7th slot noted below. The R80
// project-notes rows 7-12 were corrected to the printed
// values; rows 1-6 matched. MU printed rows run to L20,
// cleric to L29; beyond the printed rows the final row holds
// (the compilation prints no further spell rows - the xp
// line keeps advancing, the spell rows do not). The printed
// wisdom footnotes (6th needs Wis 17 at cleric 11; 7th needs
// Wis 18 at cleric 16) are not modeled - the level-only
// gates put 7th at 17; documented engine limits. Values ride
// the file's standing verification debt - the printed tables
// win when the PDF is re-uploaded.)
// ----------------------------------------------------------------------------

static const int kSlots = 9;      // spell levels 1-9 encoded
static const int kLevels = 29;    // class levels 1-29 (rows)

static const int kMuSlots[kLevels][kSlots] = {
    {1,0,0,0,0,0,0,0,0},   // L1 (unchanged - matches the print)
    {2,0,0,0,0,0,0,0,0},   // L2
    {2,1,0,0,0,0,0,0,0},   // L3
    {3,2,0,0,0,0,0,0,0},   // L4
    {4,2,1,0,0,0,0,0,0},   // L5
    {4,2,2,0,0,0,0,0,0},   // L6
    {4,3,2,1,0,0,0,0,0},   // L7 - corrected R130 (notes said 5,3,2,1)
    {4,3,3,2,0,0,0,0,0},   // L8 - corrected R130 (notes said 5,3,3,2)
    {4,3,3,2,1,0,0,0,0},   // L9 - corrected R130 (notes said 5,3,3,2,1)
    {4,4,3,3,2,0,0,0,0},   // L10 - corrected R130 (notes said 5,4,4,2,1)
    {4,4,4,3,3,0,0,0,0},   // L11 - corrected R130 (notes said 5,4,4,2,2)
    {4,4,4,4,4,1,0,0,0},   // L12 - corrected R130 (notes said 5,4,4,3,2,1)
    {5,5,5,4,4,2,0,0,0},   // L13 (printed; 7th at 14, 8th at 16, 9th at 18)
    {5,5,5,4,4,2,1,0,0},   // L14
    {5,5,5,5,5,2,1,0,0},   // L15
    {5,5,5,5,5,3,2,1,0},   // L16
    {5,5,5,5,5,3,2,2,0},   // L17 - the compilation's appendix prints 7th=2; its Table I prints 3 (documented fold; printed table wins on re-verify)
    {5,5,5,5,5,3,3,2,1},   // L18 (the Wish circle)
    {5,5,5,5,5,3,3,3,1},   // L19
    {5,5,5,5,5,4,3,3,2},   // L20 (last printed row)
    {5,5,5,5,5,4,3,3,2},   // L21 held
    {5,5,5,5,5,4,3,3,2},   // L22 held
    {5,5,5,5,5,4,3,3,2},   // L23 held
    {5,5,5,5,5,4,3,3,2},   // L24 held
    {5,5,5,5,5,4,3,3,2},   // L25 held
    {5,5,5,5,5,4,3,3,2},   // L26 held
    {5,5,5,5,5,4,3,3,2},   // L27 held
    {5,5,5,5,5,4,3,3,2},   // L28 held
    {5,5,5,5,5,4,3,3,2},   // L29 held (beyond the print, final row repeats)
};
static const int kClericSlots[kLevels][kSlots] = {
    {1,0,0,0,0,0,0,0,0},   // L1 (unchanged - matches the print)
    {2,0,0,0,0,0,0,0,0},   // L2
    {2,1,0,0,0,0,0,0,0},   // L3
    {3,2,0,0,0,0,0,0,0},   // L4
    {3,3,1,0,0,0,0,0,0},   // L5
    {3,3,2,0,0,0,0,0,0},   // L6 - corrected R130 (notes said 4,3,2)
    {3,3,2,1,0,0,0,0,0},   // L7 - corrected R130 (notes said 5,3,2,1)
    {3,3,3,2,0,0,0,0,0},   // L8 - corrected R130 (notes said 5,4,3,2)
    {4,4,3,2,1,0,0,0,0},   // L9 - corrected R130 (notes said 5,4,4,2,1)
    {4,4,3,3,2,0,0,0,0},   // L10 - corrected R130 (notes said 5,5,4,3,2)
    {5,4,4,3,2,1,0,0,0},   // L11 - corrected R130 (notes said 5,5,5,3,2,1); the printed * (Wis 17) on the 6th is not modeled
    {6,5,5,3,3,2,0,0,0},   // L12 - corrected R130 (notes said 5,5,5,4,3,2)
    {6,6,6,4,2,2,0,0,0},   // L13 - the printed 5th-level dip (2)
    {6,6,6,5,3,2,0,0,0},   // L14
    {7,7,7,5,4,2,0,0,0},   // L15
    {7,7,7,6,5,3,1,0,0},   // L16 - the printed ** (Wis 18) on the 7th; the level gate puts 7th at 17
    {8,8,8,6,5,3,1,0,0},   // L17
    {8,8,8,7,6,4,1,0,0},   // L18
    {9,9,9,7,6,4,2,0,0},   // L19
    {9,9,9,8,7,5,2,0,0},   // L20
    {9,9,9,9,8,6,2,0,0},   // L21
    {9,9,9,9,9,6,3,0,0},   // L22
    {9,9,9,9,9,7,3,0,0},   // L23
    {9,9,9,9,9,8,3,0,0},   // L24
    {9,9,9,9,9,8,4,0,0},   // L25
    {9,9,9,9,9,9,4,0,0},   // L26
    {9,9,9,9,9,9,5,0,0},   // L27
    {9,9,9,9,9,9,6,0,0},   // L28
    {9,9,9,9,9,9,7,0,0},   // L29 (last printed row)
};

int spellSlots(SpellClass sc, int classLevel, int spellLevel) {
    if (spellLevel < 1 || spellLevel > kSlots) return 0;
    if (classLevel < 1) classLevel = 1;
    if (classLevel > kLevels) classLevel = kLevels;
    return (sc == SPELL_MU ? kMuSlots : kClericSlots)
               [classLevel - 1][spellLevel - 1];
}""",
      "spells.cpp: the slot tables",
      marker="R130 line-diff against the")

patch("spells/spells.cpp",
r"""
    // spellSlots() yields 0 for these until the high-level
    // (name level+) tables arrive in a future round -
    // documented; the p.14 aging pins ride""",
r"""
    // spellSlots() yielded 0 for these until R130 delivered
    // the printed tables (MU to L20, cleric to L29); a
    // 12th-level caster still has no 7th-9th slot, so the
    // R129 pins stand - documented; the p.14 aging pins ride""",
      "spells.cpp: R129 rows comment update",
      marker="R130 delivered")

patch("spells/spells.cpp",
r"""
int maxSpellLevelForClericLevel(int classLevel) {
    if (classLevel < 1)  return 0;
    if (classLevel < 3)  return 1;
    if (classLevel < 5)  return 2;
    if (classLevel < 7)  return 3;
    if (classLevel < 9)  return 4;
    if (classLevel < 11) return 5;
    return 6;
}""",
r"""
int maxSpellLevelForClericLevel(int classLevel) {
    // R130: 7th at 17 (the printed ** footnote puts a Wis-18
    // cleric's first 7th at 16 - wisdom is not modeled; the
    // level-only gate is the documented engine limit)
    if (classLevel < 1)  return 0;
    if (classLevel < 3)  return 1;
    if (classLevel < 5)  return 2;
    if (classLevel < 7)  return 3;
    if (classLevel < 9)  return 4;
    if (classLevel < 11) return 5;
    if (classLevel < 17) return 6;
    return 7;
}""",
      "spells.cpp: cleric gate",
      marker="if (classLevel < 17) return 6;")

patch("spells/spells.cpp",
r"""
int maxSpellLevelForInt(uint8_t int_) {
    // PHB p.10 minimum INT by spell level: L1-2: 9, L3: 11, L4: 14,
    // L5: 15, L6: 16+ ... encoded as a lookup
    if (int_ < 9)  return 0;
    if (int_ < 11) return 2;
    if (int_ < 14) return 3;
    if (int_ < 15) return 4;
    if (int_ < 16) return 5;
    return 6;
}""",
r"""
int maxSpellLevelForInt(uint8_t int_) {
    // PHB p.10 minimum INT by spell level: L1-2: 9, L3: 11, L4: 14,
    // L5: 15, L6: 16+ ... encoded as a lookup. R130 extends past
    // 6th by the file's convention: 17 opens the 7th circle and
    // 18 the 8th and 9th (the PHB's own "only the highest
    // intelligence is able to comprehend the mighty magics
    // contained in 9th level spells" note; a convention
    // extension riding the standing verification debt)
    if (int_ < 9)  return 0;
    if (int_ < 11) return 2;
    if (int_ < 14) return 3;
    if (int_ < 15) return 4;
    if (int_ < 16) return 5;
    if (int_ < 17) return 6;
    if (int_ < 18) return 7;
    return 9;
}""",
      "spells.cpp: INT gate",
      marker="if (int_ < 17) return 6;")


# R130-CHUNK-1-END
# R130-CHUNK-2-START (regtest + gap report)

patch("regtest.cpp",
r"""
    // spellSlots() yields 0 for these until the high-level
    // (name level+) tables arrive in a future round -
    // documented; the p.14 aging pins ride""",
r"""
    // spellSlots() yielded 0 for these until R130 delivered
    // the printed tables (MU to L20, cleric to L29); a
    // 12th-level caster still has no 7th-9th slot, so the
    // R129 pins stand - documented; the p.14 aging pins ride""",
      "regtest.cpp: R129 comment update",
      marker="R130 delivered")

patch("regtest.cpp",
r"""
    // ---- R129: caster aging audit ----
""",
r"""
    // ---- R130: high-level slots audit ----
    // PHB class-table pins: corrected low rows, printed high
    // rows, holds past the print, and the gates. Line-diff
    // source: the 1eonline.info PHB compilation.
    {
        int bad = 0;
        // the corrected R80 rows (levels 7-12)
        if (spellSlots(SPELL_MU, 7, 1) != 4) bad++;
        if (spellSlots(SPELL_MU, 8, 2) != 3) bad++;
        if (spellSlots(SPELL_MU, 9, 5) != 1) bad++;
        if (spellSlots(SPELL_MU, 10, 4) != 3) bad++;
        if (spellSlots(SPELL_MU, 11, 5) != 3) bad++;
        if (spellSlots(SPELL_MU, 12, 6) != 4) bad++;
        if (spellSlots(SPELL_CL, 6, 3) != 2) bad++;
        if (spellSlots(SPELL_CL, 7, 4) != 1) bad++;
        if (spellSlots(SPELL_CL, 8, 4) != 2) bad++;
        if (spellSlots(SPELL_CL, 9, 5) != 1) bad++;
        if (spellSlots(SPELL_CL, 10, 5) != 2) bad++;
        if (spellSlots(SPELL_CL, 11, 1) != 5) bad++;
        if (spellSlots(SPELL_CL, 12, 1) != 6) bad++;
        // the printed high rows (13-20)
        if (spellSlots(SPELL_MU, 13, 6) != 2) bad++;
        if (spellSlots(SPELL_MU, 17, 7) != 2) bad++;
        if (spellSlots(SPELL_MU, 18, 9) != 1) bad++;
        if (spellSlots(SPELL_MU, 20, 9) != 2) bad++;
        if (spellSlots(SPELL_CL, 13, 5) != 2) bad++;
        if (spellSlots(SPELL_CL, 16, 7) != 1) bad++;
        if (spellSlots(SPELL_CL, 17, 7) != 1) bad++;
        if (spellSlots(SPELL_CL, 20, 7) != 2) bad++;
        // the holds past the print (L29 = final row)
        if (spellSlots(SPELL_MU, 29, 9) != 2) bad++;
        if (spellSlots(SPELL_CL, 29, 7) != 7) bad++;
        // the gates: cleric 7th at 17; INT 17 -> 7, 18 -> 9
        if (maxSpellLevelForClericLevel(16) != 6) bad++;
        if (maxSpellLevelForClericLevel(17) != 7) bad++;
        if (maxSpellLevelForClericLevel(29) != 7) bad++;
        if (maxSpellLevelForInt(15) != 5) bad++;
        if (maxSpellLevelForInt(16) != 6) bad++;
        if (maxSpellLevelForInt(17) != 7) bad++;
        if (maxSpellLevelForInt(18) != 9) bad++;
        // the standing low pins still hold
        if (spellSlots(SPELL_MU, 9, 5) != 1) bad++;
        if (spellSlots(SPELL_MU, 8, 5) != 0) bad++;
        if (maxSpellLevelForInt(15) != 5) bad++;
        printf("R130 high-level slots audit: bad %d\n", bad);
    }

    // ---- R129: caster aging audit ----
""",
      "regtest.cpp: R130 high-level slots audit",
      marker="R130 high-level slots audit")

patch("tools/dmg_gap_report.md",
r"""
Pinned by the R128 battery audit; census 46.

## Out of scope by design
""",
r"""
CLOSED R130: the slot tables themselves were the last
print-omission in the spell pipeline - line-diffed
against the 1eonline.info PHB compilation (class
Table I + SPELLS USABLE appendix): 9 spell levels
encoded, MU printed rows to L20, cleric to L29,
final row holds beyond the print; the R80 project-
notes rows 7-12 corrected to print; cleric 7th gate
at 17 (Wis footnotes not modeled - engine limit);
INT gate extends 17 -> 7th, 18 -> 8th/9th (the
"highest intelligence" note; convention riding
debt). Levels 7-9 are now castable - the R129
aging spells resolve. Pinned by the R130 battery
audit; census 48.

## Out of scope by design
""",
      "gap report: R130 box",
      marker="CLOSED R130: the slot tables themselves")

# ---- R130 fails/tail ----
if fails:
    print("R130 splice: FAIL - " + str(len(fails)) + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if already and not applied:
    print("R130 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R130 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
