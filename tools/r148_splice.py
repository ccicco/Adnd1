#!/usr/bin/env python3
# tools/r148_splice.py - R148, REPORT-ONLY: the gap-report
# fresh sweep. Two patches to tools/dmg_gap_report.md, no
# code and no battery change (AUDIT CENSUS stays 67).
#
# (a) THE FRESH-SWEEP OPEN BOXES (24): a table-and-prose
#     sweep of the fresh DMG/PHB uploads against the repo
#     found the unimplemented rules; each becomes an open
#     box (the living-checklist convention: a round closes
#     an item, it flips HERE in the same commit). The set:
#     the book-verify pass (the debt is now payable), the
#     PC races layer (the stale authored splice, to be
#     re-authored), the R144-R147 named leaders (matrix
#     II.C, the Appendix P caller, R146 fiction, R4 title
#     ladders, R7 two-weapon), and the DMG table gaps
#     (grenade-like missiles, weapon speed factors,
#     striking to subdue, weaponless combat, the poison
#     table, the assassination table, potion miscibility,
#     intoxication and insanity, PC disease and parasites,
#     underwater spell use, becoming lost, humanoid racial
#     preferences, Appendices K/L/M, Appendix O,
#     exceptional strength, followers by class, secondary
#     skills).
# (b) OUT PINS: the Boot Hill / Gamma World /
#     Metamorphosis Alpha conversion tables (pp.112-114)
#     and Appendix J herbs, spices, and medicinal
#     vegetation (p.220) join the out-of-scope list.
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson). This file contains
# ZERO backslash characters, and no content string embeds an
# apostrophe (the R133b + R147 chunk-delivery lessons).
# Commit: "R148: gap-report fresh sweep - open boxes + OUT
# pins (report-only)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
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

# ---- (1) the fresh-sweep open boxes ----
old_tail = NL.join([
    '      future lane). Pinned by the R147 Appendix P audit;',
    '      census 67.',
    '',
    '## Out of scope by design',
])
new_tail = NL.join([
    '      future lane). Pinned by the R147 Appendix P audit;',
    '      census 67.',
    '- [ ] **The book-verify pass (the standing debt)** - the',
    '      fresh DMG/PHB uploads (2026-10-04) make the whole',
    '      verification debt payable. The riders name their',
    '      winners: Appendix G/H spellings (R125), the Faerie',
    '      / Pleistocene / Age of Dinosaurs wilderness tables',
    '      and printing-variant readings (R126), the p.38',
    '      weapon rows (R145), the city flavor cells (R146),',
    '      and the p.71 example numbers (R144).',
    '- [ ] **PC races layer (PHB pp.15-18, Race Tables I-III)**',
    '      - the races half of the authored-but-unlanded R148',
    '      combined splice: gnome and halfling CON magic-save',
    '      and poison-save bonuses (con*2/7, the R147 dwarf',
    '      shape), elven 90% / half-elven 30% sleep-and-charm',
    '      resistance, infravision, the racial detection',
    '      lists, ability adjustments with min/max, footnoted',
    '      level caps, race to-hit adjustments vs. goblin-kind',
    '      and giant-kind, and the creation-stage',
    '      ROLL->RACE->CLASS->NAME flow. Must be re-authored',
    '      against current main - the combined splice is',
    '      stale (its 18 R147 patches already landed).',
    '- [ ] **Matrix II.C (classed monsters, most favorable',
    '      matrix)** - the R147 named gap: the per-monster',
    '      class pass, so a classed foe saves on its own',
    '      class matrix when that beats matrix II.',
    '- [ ] **Appendix P caller (the convention-party',
    '      generator)** - rollMemberMagic has no caller; wire',
    '      it into the p.176 party rows or a dm/encounters',
    '      generator.',
    '- [ ] **Grenade-like missiles + holy/unholy water',
    '      (pp.64-65)** - thrown flasks: the break and splash',
    '      rules, the cone tables, vial costs and effects.',
    '- [ ] **Weapon speed factors in initiative (p.66)** - the',
    '      segment scheduler exists; the speed-factor table',
    '      and its melee-initiative adjustments are unpinned',
    '      (verify against rules/turn first).',
    '- [ ] **Striking to subdue (p.67)** - the knockout',
    '      procedure and subdual damage accounting.',
    '- [ ] **Weaponless combat (pp.72-73)** - pummeling,',
    '      wrestling, overbearing: the three procedures and',
    '      their tables.',
    '- [ ] **Attacks with two weapons (p.70)** - the R7',
    '      double-attack named leader: the two-weapon',
    '      conventions for attack and armor class.',
    '- [ ] **Level title ladders (PHB class tables)** - the R4',
    '      named leader: the printed per-level titles for the',
    '      four engine classes.',
    '- [ ] **The poison table (p.20)** - the printed types:',
    '      ingest/injury, onset times, damage and effect',
    '      classes. The monster venom layer rolls per-monster',
    '      saves; the type table itself is unpinned.',
    '- [ ] **The assassination table (p.75)** - the odds table',
    '      proper; the p.19-20 spying rules are already wired',
    '      (the spy).',
    '- [ ] **Potion miscibility (p.119)** - the interactions',
    '      table for drinking incompatible potions.',
    '- [ ] **Intoxication and insanity (pp.82-83)** - the',
    '      alcohol and drugs effects with recovery tables;',
    '      the types of insanity.',
    '- [ ] **PC disease + parasitic infestation (pp.13-14)**',
    '      - contraction chance, occurrence and severity',
    '      tables. The monster-borne disease layer exists',
    '      (mummy rot); PC-side contraction does not.',
    '- [ ] **Underwater spell use (p.57)** - the modifier',
    '      table; the underwater encounter tables are pinned',
    '      (R60/R127) but the spell columns are not.',
    '- [ ] **Chances of becoming lost (p.49)** - the overland',
    '      navigation check for the outdoor march.',
    '- [ ] **Humanoid racial preferences (p.106)** - the',
    '      association matrix for lair and population',
    '      placement passes.',
    '- [ ] **Appendices K + L + M (pp.221-224)** - describing',
    '      magical substances; conjured animals; summoned',
    '      monsters - support tables for the conjure and',
    '      summon spell effects.',
    '- [ ] **Appendix O, encumbrance of standard items',
    '      (p.225)** - items::encumbrance exists; the printed',
    '      weight table itself is unpinned.',
    '- [ ] **Exceptional strength (PHB p.9)** - the fighter 18',
    '      percentile roll (18/01 through 18/00) and the STR',
    '      Table II bend-bars / open-doors columns; verify',
    '      the abilities layer first.',
    '- [ ] **Followers by class (pp.16-18)** - the name-level',
    '      follower tables (cleric, fighter, ranger, thief,',
    '      assassin) for stronghold recruitment.',
    '- [ ] **Secondary skills (p.12)** - the table and the',
    '      when-to-use guidance for PC backgrounds.',
    '- [ ] **R146 fiction (the named omissions)** - noble',
    '      gender (the book prints nobleman 70% / noblewoman',
    '      25% and no last 5%) and the ruffian 1-in-4',
    '      half-orc/humanoid note - city flavor follow-ups.',
    '',
    '## Out of scope by design',
])

# ---- (2) the OUT pins ----
old_out = NL.join([
    '  and the full non-standard-procedure magic',
    '  items list beyond what the battery pins.',
])
new_out = NL.join([
    '  and the full non-standard-procedure magic',
    '  items list beyond what the battery pins, the Boot',
    '  Hill / Gamma World / Metamorphosis Alpha',
    '  conversion tables (pp.112-114), and Appendix J',
    '  herbs, spices, and medicinal vegetation (p.220).',
])

# ---- run ----
patch("tools/dmg_gap_report.md", old_tail, new_tail,
      "gap report: fresh-sweep open boxes",
      marker="PC races layer (PHB pp.15-18")
assert len(applied) + len(already) == 1

patch("tools/dmg_gap_report.md", old_out, new_out,
      "gap report: OUT pins",
      marker="Metamorphosis Alpha")
assert len(applied) + len(already) == 2

# ---- R148 fails/tail ----
if fails:
    print("R148 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 2:
    print("R148 splice: FAIL - expected 2 patches, counted "
          + str(len(applied) + len(already))
          + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R148 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R148 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
print("R148 note: REPORT-ONLY - no code or battery change;")
print("AUDIT CENSUS stays 67; commit: R148: gap-report fresh")
print("sweep - open boxes + OUT pins (report-only)")
