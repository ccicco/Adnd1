#!/usr/bin/env python3
# tools/r178_splice.py - R178: the subclass arc
# OPENED - the scope round.
#
# SCOPE DECISION (the user, 2026-10-05): the engine
# grows FULL subclass support - all six subclasses
# (paladin, ranger, druid, illusionist, assassin,
# monk), multi-class and dual-class (two-class)
# characters, and the full spell lists (the druid and
# illusionist lists join the registry; paladin and
# ranger progress through the existing lists).
#
# A scope round before any engine splice: the PHB gap
# report out-of-scope notes flip to the arc, and the
# arc plan with its round queue is recorded:
#
#   (a) tools/phb_gap_report.md - the subclasses
#       bullet and the druid/illusionist spell-list
#       bullet flip from out-of-scope to the arc, and
#       the ARC SECTION is appended: the scope
#       decisions and the round queue (foundations,
#       qualification and race gates, attacks per
#       round, the spell layers, multi-class and
#       dual-class, then the per-subclass specials).
#   (b) tools/dmg_gap_report.md - the round-note chain
#       gains the R178 note pointing at the arc.
#
# A scope round adds NO audit; the battery census
# stays 94. No engine file is touched.
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An
# assert follows EVERY patch (the R142 lesson). ZERO
# backslash characters, and no content string embeds a
# literal apostrophe.
# Commit: "R178: the subclass arc opened - the scope
# round (census 94)"
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

# ---- (1) the subclasses bullet flips to the arc ----
p1_old = NL.join([
    "- The subclasses (paladin, ranger, druid,",
    "  illusionist, assassin, monk) and the multi-class",
    "  and two-class rules - the engine carries four",
    "  classes.",
])
p1_new = NL.join([
    "- The subclasses (paladin, ranger, druid,",
    "  illusionist, assassin, monk) and the multi-class",
    "  and two-class rules - OPENED R178: the subclass",
    "  arc (the scope decisions and round queue below).",
])

# ---- (2) the spell-list bullet splits ----
p2_old = NL.join([
    "- The druid and illusionist spell lists and the",
    "  psionic sections.",
])
p2_new = NL.join([
    "- The psionic sections.",
    "- The druid and illusionist spell lists - OPENED",
    "  R178: the subclass arc (they join the spell",
    "  registry in the arc spell layers).",
])

# ---- (3) the arc section appends ----
p3_old = NL.join([
    "- Stronghold and tower construction economics (the",
    "  class description sections) - the engine",
    "  stronghold machinery is DMG-side (R106 and kin).",
])
p3_new = NL.join([
    "- Stronghold and tower construction economics (the",
    "  class description sections) - the engine",
    "  stronghold machinery is DMG-side (R106 and kin).",
    "",
    "## The subclass arc (OPENED R178 - the scope round)",
    "",
    "SCOPE DECISIONS (the user, 2026-10-05): the engine",
    "grows full subclass support - all six subclasses",
    "(paladin, ranger, druid, illusionist, assassin,",
    "monk), multi-class and dual-class (two-class)",
    "characters, and the full spell lists. The druid",
    "and illusionist lists bring spells beyond the",
    "current 54-spell registry; paladin and ranger",
    "progress through the existing cleric and",
    "magic-user lists.",
    "",
    "The arc plan (each round flips its box HERE in the",
    "same commit, and adds its battery audit - the",
    "census grows with the arc):",
    "",
    "- R179 the six subclass foundations - the class",
    "      registry grows (new indices past the four",
    "      base classes), per-class level caps, hit",
    "      dice, the HP-beyond-cap convention, the XP",
    "      rows and the title ladders from the printed",
    "      subclass tables (PALADINS, RANGERS, DRUIDS,",
    "      ILLUSIONISTS, ASSASSINS, MONKS tables).",
    "- R180 qualification and race gates - the ability",
    "      minimums and the alignment requirements;",
    "      Race Table I class limitations and the Race",
    "      Table II level caps for the new classes.",
    "- R181 attacks per melee round - the",
    "      fighter-group table (also closes the open",
    "      item above); the monk unarmed ladder and the",
    "      under-one-hit-die note.",
    "- R182 the druid spell layer - the druid list",
    "      joins the registry with its own",
    "      spells-usable-by-level table.",
    "- R183 the illusionist spell layer - the",
    "      illusionist list likewise.",
    "- R184 the paladin and ranger spell layers - the",
    "      spell progressions and the shared-list",
    "      wiring (lay on hands, curing, the ranger",
    "      giant-kind bonuses follow here).",
    "- R185 multi-class and dual-class - the split",
    "      experience machinery, the hit-dice and",
    "      hit-point conventions, and the two-class",
    "      rules.",
    "- R186+ the per-subclass specials that remain -",
    "      the assassin fees and disguise layer, the",
    "      monk special abilities, backstab for the",
    "      assassin, thief-skill sharing.",
    "",
    "Until a round lands, each subclass stays out of",
    "engine scope; the boxes flip per round. The",
    "ability-table divergences (the ranked list above)",
    "stay queued BEFORE the arc rounds - the live DEX",
    "and CON bugs first.",
])

# ---- (4) the DMG report round note ----
p4_old = NL.join([
    "as an open verify. A report round adds no",
    "audit; census stays 94.",
])
p4_new = NL.join([
    "as an open verify. A report round adds no",
    "audit; census stays 94.",
    "R178 OPENED the subclass arc (the scope round,",
    "no audit - census stays 94): full subclass",
    "support is now engine scope - the six",
    "subclasses, multi-class and dual-class, and",
    "the full spell lists. The arc plan and round",
    "queue live in the PHB gap report (the",
    "subclass arc section). The live ability-table",
    "divergences (DEX, CON) stay queued before the",
    "arc rounds.",
])

# ---- run ----
patch("tools/phb_gap_report.md", p1_old, p1_new,
      "phb report: subclasses bullet opened",
      marker="OPENED R178: the subclass")
assert len(applied) + len(already) == 1

patch("tools/phb_gap_report.md", p2_old, p2_new,
      "phb report: spell-list bullet split",
      marker="OPENED" + NL + "  R178: the subclass arc (they join the spell")
assert len(applied) + len(already) == 2

patch("tools/phb_gap_report.md", p3_old, p3_new,
      "phb report: the subclass arc section",
      marker="## The subclass arc (OPENED R178")
assert len(applied) + len(already) == 3

patch("tools/dmg_gap_report.md", p4_old, p4_new,
      "dmg report: R178 round note",
      marker="R178 OPENED the subclass arc")
assert len(applied) + len(already) == 4

# ---- R178 fails/tail ----
if fails:
    print("R178 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 4:
    print("R178 splice: FAIL - expected 4 patches, counted "
          + str(len(applied) + len(already))
          + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R178 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R178 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
print("R178 note: 4 patches; a scope round - no audit,")
print("census 94; no engine file touched.")
print("commit: R178: the subclass arc opened - the scope")
print("round (census 94)")

