#!/usr/bin/env python3
# tools/r178b_splice.py - R178b: the bard joins the
# subclass arc - the scope amendment.
#
# The user caught the gap: the 1e PHB carries a
# seventh path, the bard (APPENDIX II: BARDS) - not
# a starting class but a mid-career progression:
# fighter to at least 5th (before 8th), then thief
# to at least 5th (before 9th... the print reads
# between 5th and 9th), then druidical study as a
# bard - human or half-elf only, always neutral,
# hit dice ADDED to those already earned. The PHB
# upload carries the whole appendix: Bards Tables
# I (XP, 23 levels, druid spell slots), II
# (colleges, languages, charm percent, legend lore
# percent) and III (armor and weapons), plus the
# poetics morale/ferocity layers, the song
# negation and charming rules, and the item
# knowledge lists.
#
# The bard DEPENDS on the fighter and thief layers,
# the druid spell layer, and the dual-class
# machinery, so it slots after R185:
#
#   (a) tools/phb_gap_report.md - the arc scope
#       paragraph gains the bard, and the round
#       queue gains the bard round (the
#       per-subclass specials entry renumbers
#       R186+ to R187+).
#   (b) tools/dmg_gap_report.md - the round-note
#       chain gains the R178b note.
#
# A scope amendment adds NO audit; the battery
# census stays 94. No engine file is touched.
#
# Idempotent: safe to run twice; a silent run means
# the paste was truncated - this tail ALWAYS prints.
# An assert follows EVERY patch (the R142 lesson).
# ZERO backslash characters, and no content string
# embeds a literal apostrophe.
# Commit: "R178b: the bard joins the subclass arc -
# the scope amendment (census 94)"
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

# ---- (1) the arc scope paragraph gains the bard ----
p1_old = NL.join([
    "grows full subclass support - all six subclasses",
    "(paladin, ranger, druid, illusionist, assassin,",
    "monk), multi-class and dual-class (two-class)",
    "characters, and the full spell lists. The druid",
])
p1_new = NL.join([
    "grows full subclass support - all six subclasses",
    "(paladin, ranger, druid, illusionist, assassin,",
    "monk) plus the bard (Appendix II - the seventh",
    "path, a fighter-then-thief-then-druid",
    "progression), multi-class and dual-class",
    "(two-class) characters, and the full spell",
    "lists. The druid",
])

# ---- (2) the queue gains the bard round ----
p2_old = NL.join([
    "- R185 multi-class and dual-class - the split",
    "      experience machinery, the hit-dice and",
    "      hit-point conventions, and the two-class",
    "      rules.",
    "- R186+ the per-subclass specials that remain -",
])
p2_new = NL.join([
    "- R185 multi-class and dual-class - the split",
    "      experience machinery, the hit-dice and",
    "      hit-point conventions, and the two-class",
    "      rules.",
    "- R186 the bard (Appendix II) - the progression",
    "      gates (fighter to 5th-7th, thief to",
    "      5th-9th, then the bard), the ability",
    "      minimums (STR WIS DEX CHA 15+, INT 12,",
    "      CON 10), human or half-elf, always",
    "      neutral; Bards Table I (23 levels, bard XP",
    "      only, hit dice added to those already",
    "      earned, the druid spell slots capped at",
    "      12th-level druid ability until the 23rd),",
    "      Table II (colleges, the language gains,",
    "      the charm and legend lore percents) and",
    "      Table III (armor and weapons); the poetics",
    "      morale and ferocity layers, the song",
    "      negation, the musical charming rules, the",
    "      item knowledge lists, and the",
    "      most-favorite-table saves. Lands after",
    "      R185 - the bard builds on the fighter and",
    "      thief layers, the druid spell layer and",
    "      the dual-class machinery.",
    "- R187+ the per-subclass specials that remain -",
])

# ---- (3) the DMG report round note ----
p3_old = NL.join([
    "divergences (DEX, CON) stay queued before the",
    "arc rounds.",
])
p3_new = NL.join([
    "divergences (DEX, CON) stay queued before the",
    "arc rounds.",
    "R178b AMENDED the arc scope: the bard (PHB",
    "Appendix II - the fighter-then-thief-then-druid",
    "progression, human or half-elf, always neutral)",
    "joins the arc as R186, after the multi-class",
    "round; the per-subclass specials renumber to",
    "R187+. No audit; census stays 94.",
])

# ---- run ----
patch("tools/phb_gap_report.md", p1_old, p1_new,
      "phb report: scope paragraph gains the bard",
      marker="plus the bard (Appendix II - the seventh")
assert len(applied) + len(already) == 1

patch("tools/phb_gap_report.md", p2_old, p2_new,
      "phb report: the bard round queued",
      marker="- R186 the bard (Appendix II)")
assert len(applied) + len(already) == 2

patch("tools/dmg_gap_report.md", p3_old, p3_new,
      "dmg report: R178b round note",
      marker="R178b AMENDED the arc scope")
assert len(applied) + len(already) == 3

# ---- R178b fails/tail ----
if fails:
    print("R178b splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 3:
    print("R178b splice: FAIL - expected 3 patches, counted "
          + str(len(applied) + len(already))
          + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R178b splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R178b splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
print("R178b note: 3 patches; a scope amendment - no audit,")
print("census 94; no engine file touched.")
print("commit: R178b: the bard joins the subclass arc - the")
print("scope amendment (census 94)")

