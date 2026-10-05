#!/usr/bin/env python3
# tools/r177_splice.py - R177: the PHB gap report
# created - the sibling whole-book inventory.
#
# The DMG gap report drove the R108b-R176 arc to a
# full close. This round creates the same inventory
# for the Players Handbook:
#
#   (a) tools/phb_gap_report.md CREATED - the whole
#       book read against the engine: verified boxes
#       (with their rounds), the ranked DIVERGENT
#       fix-round candidates, the open items and the
#       out-of-scope notes. The founding read verified
#       SIX ability-table divergences (the
#       rules/character.cpp ladders transcribed from
#       project notes - the same finding class as the
#       R162 XP rows, repinned R176): DEX reaction
#       cells 3/4/18, the CON system-shock and
#       resurrection-survival columns (every score),
#       the WIS magical-attack ladder, the INT
#       language ladder, the CHA scale plus two
#       henchmen cells, and the prime-requisite rungs
#       (open verify).
#   (b) tools/dmg_gap_report.md - the round-note chain
#       gains the R177 note pointing at the sibling
#       report.
#
# A report round adds NO audit; the battery census
# stays 94. The created-file md5 is the real gate.
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An
# assert follows EVERY patch (the R142 lesson). ZERO
# backslash characters (the markdown is plain ASCII
# lines), and no content string embeds a literal
# apostrophe.
# Commit: "R177: the PHB gap report created - the
# sibling whole-book inventory (census 94)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)   # one newline
applied, already, fails = [], [], []

def wr(p, s):
    with open(os.path.join(ROOT, p), "w", encoding="ascii") as f:
        f.write(s)

# ---- (1) the PHB gap report created ----
REPORT = NL.join([
    "# PHB Gap Report - the book vs the repo",
    "",
    "R177 CREATION. THE SECOND BOOK, WHOLE. The DMG gap",
    "report (tools/dmg_gap_report.md) covers the Dungeon",
    "Masters Guide; this sibling report inventories the",
    "Players Handbook (the Premium 1e OCR upload)",
    "against the same engine, end to end. Engine scope:",
    "four classes (fighter, magic-user, cleric, thief),",
    "the six ability tables, the weapon, armor and",
    "encumbrance layers, and the 54-spell registry.",
    "Everything else the book carries is out of engine",
    "scope, noted at the foot.",
    "",
    "Conventions as the DMG report: [x] verified",
    "against the book text (with the round); [~]",
    "verified DIVERGENT - fix-round candidates, ranked;",
    "[ ] open item (worth having); a round closes an",
    "item by flipping the box in the SAME commit. Page",
    "cites are the book own page numbers where earlier",
    "rounds set them; otherwise sections are cited by",
    "their printed table names.",
    "",
    "FOUNDING READ FINDING: the five ability tables",
    "other than STR are transcribed from project notes",
    "and DIVERGE from the print - the same finding",
    "class as the R162 XP rows (repinned R176). Five",
    "divergences are verified below, and the prime",
    "requisite ladder is an open verify item. A report",
    "round adds no audit; the battery census stays 94",
    "until the first PHB fix round lands.",
    "",
    "## Verified against the book",
    "",
    "- [x] **STR Table II (p.9, ability adjustments)** -",
    "      pinned R153: hit probability, damage, the",
    "      weight allowance, open doors and bend bars or",
    "      lift gates for the whole 3-18/00 run.",
    "- [x] **Race Tables I-III (pp.15-18)** - pinned",
    "      R154: class limitations, the footnoted level",
    "      caps, ability minimums and maximums (male and",
    "      female columns), infravision, the",
    "      sleep-and-charm resistances, the CON",
    "      magic-save bonus (the R147 shape).",
    "- [x] **Racial preferences table (the CHARACTER",
    "      RACES section)** - the acceptability matrix",
    "      pinned R169.",
    "- [x] **Class tables (pp.20-31)** - the level",
    "      title ladders pinned R162 (the cleric level 5",
    "      blank cell carries Curate down); the XP",
    "      boundary columns pinned R176 (band lower",
    "      bound - 1; the printed adders); hit dice and",
    "      the HP_BEYOND_CAP convention print-verified in",
    "      passing (R162).",
    "- [x] **Followers by class (the class description",
    "      sections)** - pinned R170.",
    "- [x] **Weapon data (speed factors, the per-weapon",
    "      charts)** - R158 (speed) and R144 (the to-hit",
    "      adjustment rows, from the repo-trusted",
    "      compilation); the book-verify pass is the",
    "      open item below, now payable.",
    "- [x] **Spells (the SPELL TABLES and the spell",
    "      explanations, engine classes)** - the",
    "      54-spell registry, the by-level slot tables",
    "      and the L4-6 casting gates pinned",
    "      R80/R130/R131; caster aging R129.",
    "- [x] **Death and revival (the CON resurrection",
    "      survival column in use)** - R82; the audit",
    "      range check covers the printed 40-100 column,",
    "      so the coming repin passes it unchanged.",
    "",
    "## Verified DIVERGENT (fix-round candidates, ranked)",
    "",
    "- [~] 1. **DEX Table I, reaction and attacking",
    "      adjustment (the DEXTERITY TABLE I page)** -",
    "      engine cells diverge at dex 3 (engine -2,",
    "      print -3), dex 4 (engine -1, print -2) and",
    "      dex 18 (engine +2, print +3); 5 through 17",
    "      match. LIVE: the accessor feeds missile",
    "      attacks (ai/actor) and the surprise roll",
    "      (rules/turn). The defensive adjustment ladder",
    "      matches the print (the items.cpp armor class",
    "      wiring).",
    "- [~] 2. **CON table, the system shock and",
    "      resurrection survival columns (the",
    "      CONSTITUTION TABLE page)** - the engine system",
    "      shock reads 25 through 96 against the printed",
    "      35 through 99; the resurrection survival reads",
    "      30 through 98 against the printed 40 through",
    "      100 - every score diverges in both columns.",
    "      The resurrection column is LIVE (the",
    "      raise-dead roll and the R82 audit). The",
    "      character.cpp conHPAdj CON 6 cell reads 0",
    "      against the printed -1 (classes.cpp",
    "      conHPAdjustment already matches the print).",
    "      The poison-save column the engine carries",
    "      (conPoisonSaveAdj) is not in the 1e print at",
    "      all - unsourced, and unused.",
    "- [~] 3. **WIS Table I, magical attack adjustment",
    "      (the WISDOM TABLE I page)** - the engine reads",
    "      -2 through +2; the print reads 3 -3, 4 -2,",
    "      5-7 -1, 8-14 none, 15 +1, 16 +2, 17 +3,",
    "      18 +4. Currently unwired (the saves.h note",
    "      points at it; the save rolls do not call it).",
    "- [~] 4. **INT Table I, additional languages (the",
    "      INTELLIGENCE TABLE I page)** - the engine",
    "      ladder diverges at every score above 3; the",
    "      print reads 3-7 none, 8-9 one, 10-11 two,",
    "      12-13 three, 14-15 four, 16 five, 17 six,",
    "      18 seven. Currently display-only.",
    "- [~] 5. **CHA table (reaction adjustment, loyalty",
    "      base, henchmen - the CHARISMA TABLE page)** -",
    "      the engine reaction adjustment is a flat -4",
    "      through +4 ladder against the printed percent",
    "      ladder (-25 at 3 through +35 at 18); the",
    "      loyalty base reads 1 through 15 against the",
    "      printed -30 through +40 percent; the henchmen",
    "      count diverges at cha 4 (engine 2, print 1)",
    "      and cha 12 (engine 4, print 5). The reaction",
    "      accessor is LIVE and feeds the d100 reaction",
    "      bands (dm.cpp rollReaction) - the fix round",
    "      must re-scale to the printed percents.",
    "",
    "## Open items (worth having)",
    "",
    "- [ ] **Prime requisite XP adjustment (the class",
    "      sections)** - the engine ladder reads +10, +5,",
    "      0, -10, -20 percent by prime requisite score;",
    "      the print carries the +10 percent",
    "      high-prime-requisite notes in the class",
    "      sections. The remaining rungs are unsourced",
    "      against the 1e print - verify, then repin or",
    "      record as convention.",
    "- [ ] **The PHB book-verify pass for the weapon",
    "      tables** - R144/R158 pinned from the",
    "      1eonline.info compilation; the PHB upload now",
    "      supplies the print charts (WEIGHT AND DAMAGE",
    "      BY WEAPON TYPE; WEAPON TYPES, GENERAL DATA AND",
    "      TO HIT ADJUSTMENTS) - a verify round can close",
    "      the standing compile-vs-print note.",
    "- [ ] **Starting money by class (the EQUIPPING THE",
    "      CHARACTER section)** - the print: cleric 3d6",
    "      (30-180 gp), fighter 5d4 (50-200), magic-user",
    "      2d4 (20-80), thief 2d6 (20-120). The engine",
    "      party-creation convention is unverified",
    "      against the print.",
    "- [ ] **Armor Class table (the ARMOR section)** -",
    "      the printed AC ratings (none 10 through plate",
    "      and shield 2, magic pluses lowering AC)",
    "      deserve a cell-by-cell verify against the",
    "      items armor rows (R101 pinned the plate kit).",
    "- [ ] **Fighter attacks per melee round (the class",
    "      tables section)** - 1 per round at levels 1-6,",
    "      3 per 2 rounds at 7-12, 2 per round at 13 and",
    "      up (one per level against creatures under one",
    "      hit die); the engine convention is unverified.",
    "- [ ] **Wisdom Table II, cleric bonus spells and",
    "      spell failure** - unwired; a wiring candidate",
    "      if engine scope wants it.",
    "",
    "## Out of engine scope (recorded, not defects)",
    "",
    "- The subclasses (paladin, ranger, druid,",
    "  illusionist, assassin, monk) and the multi-class",
    "  and two-class rules - the engine carries four",
    "  classes.",
    "- Alignment machinery (the ALIGNMENT section) -",
    "  player-side.",
    "- Language lists (the CHARACTER LANGUAGES section) -",
    "  display only.",
    "- The druid and illusionist spell lists and the",
    "  psionic sections.",
    "- Stronghold and tower construction economics (the",
    "  class description sections) - the engine",
    "  stronghold machinery is DMG-side (R106 and kin).",
    "",
])

def patch_report():
    p = os.path.join(ROOT, "tools/phb_gap_report.md")
    if os.path.exists(p):
        with open(p, encoding="ascii") as f:
            s = f.read()
        if "R177 CREATION" in s:
            already.append("phb_gap_report.md created")
        else:
            fails.append("phb_gap_report.md exists without "
                         "the R177 marker")
        return
    wr("tools/phb_gap_report.md", REPORT)
    applied.append("phb_gap_report.md created")

patch_report()
assert len(applied) + len(already) == 1

# ---- (2) the DMG report round note ----
p2_old = NL.join([
    "R176 battery audit carries the row walk, the",
    "beyond-table probes and the clamps.",
    "Census 94.",
])
p2_new = NL.join([
    "R176 battery audit carries the row walk, the",
    "beyond-table probes and the clamps.",
    "Census 94.",
    "R177 CREATED the PHB gap report",
    "(tools/phb_gap_report.md) - the sibling",
    "whole-book inventory for the Players Handbook,",
    "same conventions: verified boxes, ranked",
    "divergences, open items, out-of-scope notes.",
    "The founding read verified FIVE ability-table",
    "divergences (the character.cpp ladders",
    "transcribed from project notes - the R162 XP",
    "finding class) plus the prime-requisite ladder",
    "as an open verify. A report round adds no",
    "audit; census stays 94.",
])

p = os.path.join(ROOT, "tools/dmg_gap_report.md")
with open(p, encoding="ascii") as f:
    s = f.read()
if "R177 CREATED the PHB gap report" in s:
    already.append("dmg_gap_report.md: R177 round note")
else:
    n = s.count(p2_old)
    if n != 1:
        fails.append("dmg_gap_report.md round note: anchor "
                     "count " + str(n) + " (expected 1)")
    else:
        wr("tools/dmg_gap_report.md", s.replace(p2_old, p2_new))
        applied.append("dmg_gap_report.md: R177 round note")
assert len(applied) + len(already) == 2

# ---- R177 fails/tail ----
if fails:
    print("R177 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 2:
    print("R177 splice: FAIL - expected 2 patches, counted "
          + str(len(applied) + len(already))
          + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R177 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R177 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
print("R177 note: 2 patches; no audit added, census 94;")
print("real gate: md5sum tools/phb_gap_report.md")
print("commit: R177: the PHB gap report created - the")
print("sibling whole-book inventory (census 94)")

