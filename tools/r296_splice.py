#!/usr/bin/env python3
# tools/r296_splice.py - R296: the PHB gap report
# scope round - the unrecorded-sections pass.
#
# The R280-R295 arc pinned the last DMG artifact
# prose and the PHB ledger reads fully green - zero
# open items, zero divergences. But diffing the PHB
# upload section list against that ledger found
# five sections the report never explicitly pinned
# or marked OUT (unlike alignment, languages,
# psionics and stronghold economics, which are all
# written down). This round records them:
#
#   (a) tools/phb_gap_report.md - a new R296 scope
#       section: two items OPENED (the weapon
#       proficiency table - initial slots, the -2 to
#       -5 non-proficiency penalty, the added-slot
#       cadence, ten class rows, UNWIRED in the
#       engine, an R297 pin candidate; and the thief
#       function take table plus DEX Table II -
#       levels 1-17, eight functions, six racial
#       adjustment rows, a data-only R298 candidate,
#       the R186 poetics precedent) and three
#       recorded OUT (money changing, banks, loans
#       and jewelers - the economy is gold-only;
#       Appendix V - the division agreements are
#       player-side; Appendix IV - no planar layer).
#   (b) tools/dmg_gap_report.md - the round-note
#       chain gains the R296 note pointing at the
#       scope pass.
#
# A report round adds NO audit; the battery census
# stays 213. The patched PHB report md5 is the real
# gate.
#
# Idempotent: safe to run twice; a silent run means
# the paste was truncated - this tail ALWAYS prints.
# An assert follows EVERY patch (the R142 lesson).
# ZERO backslash characters (the markdown is plain
# ASCII lines), and no content string embeds a
# literal apostrophe.
# Commit: "R296: the PHB gap report scope round -
# the unrecorded sections recorded OUT and the
# proficiency and thief tables opened (census 213)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)   # one newline
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding="ascii") as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), "w", encoding="ascii") as f:
        f.write(s)

# ---- the R296 PHB scope section ----
SECTION = NL.join([
    "## R296 the unrecorded-sections pass (the second",
    "scope round)",
    "",
    "R296 SCOPE PASS. Diffing the PHB upload section",
    "list against this ledger found five sections",
    "the report never explicitly pinned or marked",
    "OUT. They are recorded here, per the R177",
    "convention that a scope decision gets written",
    "down. A report round adds no audit; the battery",
    "census stays 213.",
    "",
    "## Open items (the R296 additions)",
    "",
    "- [ ] **Weapon Proficiency Table (the WEAPONS",
    "      section)** - ten class rows. Initial",
    "      slots: cleric 2, druid 2, fighter 4,",
    "      paladin 3, ranger 3, magic-user 1,",
    "      illusionist 1, thief 2, assassin 3,",
    "      monk 1. The non-proficiency to-hit",
    "      penalty: fighter, paladin, ranger and",
    "      assassin -2; cleric, thief and monk -3;",
    "      druid -4; magic-user and illusionist",
    "      -5. The added-slot cadence: monk 1 per 2",
    "      levels, fighter-types 1 per 3, cleric,",
    "      thief and assassin 1 per 4, druid 1 per",
    "      5, magic-user and illusionist 1 per 6.",
    "      The printed notes: proficiency with a",
    "      normal weapon is subsumed in the magical",
    "      weapon of the same type; the added slots",
    "      arrive at the indicated level count above",
    "      the 1st (the cleric example: two weapons",
    "      at 1st, three at 5th, four at 9th, five",
    "      at 13th). UNWIRED - no proficiency layer",
    "      exists in the engine; the pin candidate",
    "      wires the penalty into the to-hit path",
    "      and the slot counts as data. The R297",
    "      candidate.",
    "- [ ] **Thief Function Take table and DEXTERITY",
    "      TABLE II (the THIEF and DEXTERITY",
    "      sections)** - the take table runs thief",
    "      levels 1 through 17 across the eight",
    "      functions (pick pockets, open locks,",
    "      find/remove traps, move silently, hide",
    "      in shadows, hear noise, climb walls,",
    "      read languages), with the six racial",
    "      adjustment rows beneath (dwarf, elf,",
    "      gnome, half-elf, halfling, half-orc);",
    "      DEX Table II prints the five thief",
    "      adjustment columns for scores 9",
    "      through 18. The engine carries the six",
    "      shared ability names and the",
    "      monk/assassin level-sharing rules",
    "      (rules/subclassspecials.h) but performs",
    "      no thief rolls. A DATA-ONLY pin",
    "      candidate (the R186 poetics precedent),",
    "      not gameplay wiring. The R298 candidate.",
    "",
    "## Out of engine scope (the R296 additions)",
    "",
    "- Money changing, banks, loans and jewelers",
    "  (the MONETARY SYSTEM section) - the engine",
    "  economy is gold-only (starting money R190,",
    "  the town ledger R93, taxation R207); no",
    "  exchange or credit layer exists or is",
    "  wanted.",
    "- Appendix V (the suggested agreements for",
    "  division of treasure) - the party division",
    "  agreements are player-side; the mechanical",
    "  share machinery is R93/R103.",
    "- Appendix IV (the known planes of",
    "  existence) - the engine has no planar",
    "  layer; the planar references that matter",
    "  (the artifact prose) are DMG-side and",
    "  pinned there.",
    "",
    "The R178 subclass-arc precedent: OPEN the",
    "scope items first, pin them in following",
    "rounds, flip the boxes in the same commits.",
    "The two R296 open items follow that shape -",
    "the proficiency table first (it is live",
    "to-hit wiring), the thief tables after",
    "(data-only).",
])

# ---- the R296 DMG round note ----
NOTE = NL.join([
    "R296 the PHB report scope round:",
    "diffing the PHB upload section",
    "list against the sibling ledger",
    "found five sections never",
    "explicitly pinned or marked",
    "OUT. Three recorded OUT: money",
    "changing, banks, loans and",
    "jewelers (the gold-only economy);",
    "Appendix V (the treasure division",
    "agreements - player-side);",
    "Appendix IV (the known planes -",
    "no planar layer). Two opened:",
    "the weapon proficiency table",
    "(initial slots, the -2 to -5",
    "non-proficiency penalty, the",
    "added-slot cadence - an R297",
    "pin candidate), and the thief",
    "function take plus DEX Table II",
    "(levels 1-17, the racial",
    "adjustments - a data-only R298",
    "candidate). No audit added; the",
    "battery census stays 213.",
])

# ---- the content self-asserts ----
assert chr(39) not in SECTION + NOTE, "apostrophe in content"
assert chr(92) not in SECTION + NOTE, "backslash in content"
for el in SECTION.split(NL):
    assert len(el) <= 57, "section line too long: " + el
    assert all(ord(c) < 128 for c in el), "non-ascii in section"
for el in NOTE.split(NL):
    assert len(el) <= 34, "note line too long: " + el
    assert all(ord(c) < 128 for c in el), "non-ascii in note"
SJOIN = " ".join(SECTION.split(NL))
for frag in ("R296 SCOPE PASS", "Weapon Proficiency Table",
             "Thief Function Take", "DEXTERITY",
             "MONETARY SYSTEM", "Appendix V", "Appendix IV",
             "R297", "R298", "census stays 213"):
    assert frag in SJOIN, "section frag missing: " + frag
NJOIN = " ".join(NOTE.split(NL))
for frag in ("R296", "R297", "R298", "213"):
    assert frag in NJOIN, "note frag missing: " + frag
assert SECTION.count("- [ ]") == 2, "open item count is not 2"

# ---- (1) the PHB gap report scope section ----
p = "tools/phb_gap_report.md"
s = rd(p)
if "R296 SCOPE PASS" in s:
    already.append("phb_gap_report.md: R296 scope section")
else:
    tail = "Census 155." + NL + NL
    assert s.count(tail) >= 1, "phb report tail not found"
    assert s.count("R296 SCOPE PASS") == 0, "mark pre-exists"
    assert s.rstrip().endswith("Census 155."), "phb tail wrong"
    wr(p, s + SECTION + NL)
    applied.append("phb_gap_report.md: R296 scope section")
s = rd(p)
assert s.count("R296 SCOPE PASS") == 1, "patch 1 failed"
assert s.count("R236 the bard specials") == 1, "patch 1 ate R236"
assert s.rstrip().endswith("(data-only)."), "patch 1 tail wrong"
assert s.count("# PHB Gap Report") == 1, "patch 1 ate the header"
assert len(applied) + len(already) == 1, "patch 1 count wrong"

# ---- (2) the DMG report round note ----
p = "tools/dmg_gap_report.md"
s = rd(p)
if "R296 the PHB report scope round" in s:
    already.append("dmg_gap_report.md: R296 round note")
else:
    anchor = "Special prose COMPLETE)." + NL + NL + "Categories:"
    assert s.count(anchor) == 1, "dmg anchor not unique"
    wr(p, s.replace(anchor,
        "Special prose COMPLETE)." + NL + NL + NOTE + NL + NL +
        "Categories:", 1))
    applied.append("dmg_gap_report.md: R296 round note")
s = rd(p)
assert s.count("R296 the PHB report scope round") == 1, "patch 2 failed"
assert s.count("Categories:") == 1, "patch 2 ate Categories"
assert s.count("R295 landed the III.E Special") == 1, "patch 2 ate R295"
assert len(applied) + len(already) == 2, "patch 2 count wrong"

# ---- R296 fails/tail ----
if fails:
    print("R296 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 2:
    print("R296 splice: FAIL - expected 2 patches, counted "
          + str(len(applied) + len(already))
          + " (a truncated paste?)")
    sys.exit(1)
print("R296 splice: ALL OK (applied "
      + str(len(applied)) + ", already " + str(len(already)) + ")")
print("R296 note: 2 patches; no audit added, census 213;")
print("real gate: md5sum tools/phb_gap_report.md")
print("commit: R296: the PHB gap report scope round - the unrecorded sections recorded OUT and the proficiency and thief tables opened (census 213)")

