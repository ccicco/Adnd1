#!/usr/bin/env python3
# R117 splice: encounter reactions (DMG p.64) - the
# book's own table replaces R8's admitted-unverified
# 2d6 shape. The book: percentile dice, adjusted for
# charisma and applicable loyalty adjustment as if
# the creature were a henchman of the speaker; seven
# bands (01-05 violently hostile ... 96-00
# enthusiastically friendly; the two starred bands
# read "or morale check if appropriate" - noted).
# rollReaction becomes d100 + chaReactionAdj (the
# hireling reaction adjustment, PHB/R3 - the book's
# "as if a henchman" charisma machinery; the loyalty
# adjustment applies only when a loyalty score exists,
# which an encountered creature has none of -
# documented). A pure reactionForScore carries the
# bands so the battery can pin every edge. No callers
# exist (rollReaction was dead code), so the enum
# reshape is free. Battery audit pins the seven-band
# edges, the clamp on both ends, the enum order, and
# a seeded 200-roll smoke. Gap report box flips.
# Idempotent (marker checks per patch): run twice -
# the second run must print every patch already
# applied. ASCII-only. Refuses non-unique anchors,
# all-or-nothing.
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


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


# ---- patch bodies ----------------------------------------------------------

DH_OLD = """// ----------------------------------------------------------------------------
// REACTIONS (DMG p.71-72): 2d6 on the encounter reaction table, with
// CHA reaction adjustment (R3) applied to the roll.
// ----------------------------------------------------------------------------
enum Reaction : int {
    REACTION_HOSTILE   = 0,   // attacks immediately
    REACTION_THREATEN  = 1,   // hostile, may attack if pressed
    REACTION_INDIFFERENT= 2,  // neutral, goes about business
    REACTION_NEUTRAL   = 3,   // neutral, may parley
    REACTION_FRIENDLY  = 4,   // receptive, may aid
    REACTION_HELPFUL   = 5    // actively assists
};

Reaction rollReaction(Dice& dice, int chaReactionAdj);"""

DH_NEW = """// ----------------------------------------------------------------------------
// R117: ENCOUNTER REACTIONS (DMG p.64) - the book's own
// table (replacing R8's 2d6 stand-in shape, which
// carried a verification-debt NOTE). The book: roll
// percentile dice, adjust for charisma and applicable
// loyalty adjustment AS IF the creature were a
// henchman of the character speaking, and compare to
// the seven bands below. The charisma adjustment is
// chaReactionAdj (PHB hireling reaction adjustment,
// R3); the loyalty adjustment applies only where a
// loyalty score exists, and an encountered creature
// has none (documented interpretation - a caller
// with a real loyalty score pre-adjusts the roll).
// The book's stars on the two hostile bands: "or
// morale check if appropriate" - the caller's call.
// ----------------------------------------------------------------------------
enum Reaction : int {
    REACTION_VIOLENT      = 0,  // 01-05: violently hostile, immediate attack*
    REACTION_HOSTILE      = 1,  // 06-25: hostile, immediate action*
    REACTION_UNCERTAIN_NEG= 2,  // 26-45: uncertain, 55% prone toward negative
    REACTION_NEUTRAL      = 3,  // 46-55: neutral - uninterested - uncertain
    REACTION_UNCERTAIN_POS= 4,  // 56-75: uncertain, 55% prone toward positive
    REACTION_FRIENDLY     = 5,  // 76-95: friendly, immediate action
    REACTION_ENTHUSIASTIC = 6   // 96-00: enthusiastically friendly
};

// the book's band for an ADJUSTED percentile score
// (clamped at both ends: 05 or less is violent, 96
// or greater - the book's "96-00 (or greater)" - is
// enthusiastic)
Reaction reactionForScore(int adjustedScore);

// d100 + chaReactionAdj, banded (DMG p.64)
Reaction rollReaction(Dice& dice, int chaReactionAdj);"""

DC_OLD = """// ----------------------------------------------------------------------------
// Reactions (DMG p.71-72): 2d6 + CHA adj
//   2      : hostile, attacks
//   3-4    : threatening
//   5-6    : indifferent
//   7-8    : neutral
//   9-11   : friendly
//   12+    : helpful
// NOTE: the printed DMG table's exact bands get verified in the book
// pass (verification debt); this is the standard 1e shape.
// ----------------------------------------------------------------------------

Reaction rollReaction(Dice& dice, int chaReactionAdj) {
    int roll = (int)dice.roll(2, 6, 0) + chaReactionAdj;
    if (roll <= 2)  return REACTION_HOSTILE;
    if (roll <= 4)  return REACTION_THREATEN;
    if (roll <= 6)  return REACTION_INDIFFERENT;
    if (roll <= 8)  return REACTION_NEUTRAL;
    if (roll <= 11) return REACTION_FRIENDLY;
    return REACTION_HELPFUL;
}"""

DC_NEW = """// ----------------------------------------------------------------------------
// R117: encounter reactions (DMG p.64) - the book's
// percentile table, seven bands, replacing R8's 2d6
// stand-in (its verification debt is paid here)
// ----------------------------------------------------------------------------

Reaction reactionForScore(int adjustedScore) {
    if (adjustedScore <= 5)  return REACTION_VIOLENT;       // 01-05
    if (adjustedScore <= 25) return REACTION_HOSTILE;        // 06-25
    if (adjustedScore <= 45) return REACTION_UNCERTAIN_NEG;  // 26-45
    if (adjustedScore <= 55) return REACTION_NEUTRAL;        // 46-55
    if (adjustedScore <= 75) return REACTION_UNCERTAIN_POS;  // 56-75
    if (adjustedScore <= 95) return REACTION_FRIENDLY;       // 76-95
    return REACTION_ENTHUSIASTIC;                            // 96+
}

Reaction rollReaction(Dice& dice, int chaReactionAdj) {
    return reactionForScore((int)dice.d100() + chaReactionAdj);
}"""
RT_OLD = """        printf("R116 missile range audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----"""

RT_NEW = """        printf("R116 missile range audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R117: encounter reactions audit ----
    {
        int bad = 0;
        // the book's seven bands (DMG p.64), every
        // edge pinned on the pure banding helper
        if (dm::reactionForScore(5) != dm::REACTION_VIOLENT)
            ++bad;
        if (dm::reactionForScore(6) != dm::REACTION_HOSTILE)
            ++bad;
        if (dm::reactionForScore(25) != dm::REACTION_HOSTILE)
            ++bad;
        if (dm::reactionForScore(26) != dm::REACTION_UNCERTAIN_NEG)
            ++bad;
        if (dm::reactionForScore(45) != dm::REACTION_UNCERTAIN_NEG)
            ++bad;
        if (dm::reactionForScore(46) != dm::REACTION_NEUTRAL)
            ++bad;
        if (dm::reactionForScore(55) != dm::REACTION_NEUTRAL)
            ++bad;
        if (dm::reactionForScore(56) != dm::REACTION_UNCERTAIN_POS)
            ++bad;
        if (dm::reactionForScore(75) != dm::REACTION_UNCERTAIN_POS)
            ++bad;
        if (dm::reactionForScore(76) != dm::REACTION_FRIENDLY)
            ++bad;
        if (dm::reactionForScore(95) != dm::REACTION_FRIENDLY)
            ++bad;
        if (dm::reactionForScore(96) != dm::REACTION_ENTHUSIASTIC)
            ++bad;
        if (dm::reactionForScore(100) != dm::REACTION_ENTHUSIASTIC)
            ++bad;
        // clamped at both ends (the book's "01 (or
        // less)" and "96-00 (or greater)")
        if (dm::reactionForScore(0) != dm::REACTION_VIOLENT)
            ++bad;
        if (dm::reactionForScore(-4) != dm::REACTION_VIOLENT)
            ++bad;   // a -4 CHA adj can drive it below
        if (dm::reactionForScore(104) != dm::REACTION_ENTHUSIASTIC)
            ++bad;   // a +4 CHA adj can drive it above
        // the enum keeps the book's order (a caller
        // may compare magnitudes: violent < ... <
        // enthusiastic)
        if (dm::REACTION_VIOLENT != 0 ||
            dm::REACTION_HOSTILE != 1 ||
            dm::REACTION_UNCERTAIN_NEG != 2 ||
            dm::REACTION_NEUTRAL != 3 ||
            dm::REACTION_UNCERTAIN_POS != 4 ||
            dm::REACTION_FRIENDLY != 5 ||
            dm::REACTION_ENTHUSIASTIC != 6) ++bad;
        // smoke: 200 seeded rolls land in range and
        // both ends of the table are reachable
        {
            rules::Rng rng7(4242);
            rules::Dice dice7(rng7);
            bool sawLow = false, sawHigh = false;
            for (int i = 0; i < 200; ++i) {
                dm::Reaction r = dm::rollReaction(dice7, 0);
                if (r < dm::REACTION_VIOLENT ||
                    r > dm::REACTION_ENTHUSIASTIC) ++bad;
                if (r <= dm::REACTION_HOSTILE) sawLow = true;
                if (r >= dm::REACTION_FRIENDLY) sawHigh = true;
            }
            if (!sawLow || !sawHigh) ++bad;
        }
        printf("R117 encounter reactions audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----"""

GH_OLD = """R116 CLOSED the missile range modifiers
(p.75) - -2 medium, -5 long, on the
engagement distance."""

GH_NEW = """R116 CLOSED the missile range modifiers
(p.75) - -2 medium, -5 long, on the
engagement distance.
R117 CLOSED encounter reactions (p.64) -
the book's percentile seven-band table
replaces R8's 2d6 stand-in."""

GB_OLD = """- [ ] **Encounter reactions (p.63-64)** - the
      two-die reaction table and its
      attitude-by-roll results."""

GB_NEW = """- [x] **Encounter reactions (p.64)** -
      CLOSED R117: the book's percentile
      table (seven bands, 01-05 violently
      hostile through 96-00
      enthusiastically friendly) replaces
      R8's 2d6 stand-in, which carried a
      verification-debt NOTE. d100 +
      chaReactionAdj (the hireling reaction
      adjustment - the book's "as if the
      creature were a henchman" charisma
      machinery); the loyalty adjustment
      applies only where a loyalty score
      exists, which an encountered
      creature has none (documented -
      a caller with a real score
      pre-adjusts). The starred bands read
      "or morale check if appropriate" -
      the caller's call, noted in the
      enum. Pinned by the R117 battery
      audit (all 13 band edges, both
      clamps, enum order, 200-roll smoke).
      No callers yet - the parley hook is
      a future round (dead code until
      then, but the book's own shape)."""

# ---- patch table: (file, marker, old, new, label) --------------------------

PATCHES = [
    ("dm/dm.h", "Reaction reactionForScore(int adjustedScore);",
     DH_OLD, DH_NEW, "dm.h book's reaction table"),
    ("dm/dm.cpp", "Reaction reactionForScore(int adjustedScore) {",
     DC_OLD, DC_NEW, "dm.cpp book's reaction table"),
    ("regtest.cpp", "R117 encounter reactions audit",
     RT_OLD, RT_NEW, "regtest R117 audit"),
    ("tools/dmg_gap_report.md", "R117 CLOSED encounter reactions",
     GH_OLD, GH_NEW, "gap report header note"),
    ("tools/dmg_gap_report.md", "CLOSED R117: the book's percentile",
     GB_OLD, GB_NEW, "gap report reactions box"),
]


def main():
    # all-or-nothing: compute every patch, write only if
    # every patch applied or was already applied
    texts = {}
    applied = 0
    already = 0
    failed = []
    for rel, marker, old, new, label in PATCHES:
        if rel not in texts:
            texts[rel] = read(rel)
        t = texts[rel]
        if marker in t:
            print("already applied: " + label)
            already += 1
        else:
            t2, did = replace_exact(t, old, new, label)
            if not did:
                failed.append(label)
            else:
                texts[rel] = t2
                applied += 1
    if failed:
        print("R117 splice: REFUSED - %d of %d patches applied, "
              "nothing written" % (applied, len(PATCHES)))
        return
    for rel in texts:
        write(rel, texts[rel])
    if applied == len(PATCHES):
        print("R117 splice: ALL OK (%d patches)" % applied)
    elif applied == 0:
        print("R117 splice: nothing to do (already applied)")
    else:
        print("R117 splice: PARTIAL (%d applied, %d already) - "
              "inspect before committing" % (applied, already))


if __name__ == "__main__":
    main()
