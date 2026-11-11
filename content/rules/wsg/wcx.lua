-- wcx: promoted from tools/spec_r445.json (the The WSG CROSSING A CHASM ON A ROPE, R445: the chasm prose and Table 21 - characters can negotiate a chasm or deep canyon by anchoring a rope on the far side and moving hand-over-hand across it. Success depends on two factors: whether the terrain offers a protrusion to anchor a line, and whether the rope can be anchored to hold their weight; a grappling hook answers both questions through Table 20. A thrown loop of rope can also catch a protrusion if the target is directly across or only slightly above or below the thrower (never on a vertical climb), but only a thief or a rope-use proficient character can succeed. Table 21 gives the maximum ranges by level band: 40 feet at 1-4, 50 at 5-8, 60 at 9-12, 75 at 13-16 and 90 at 17+. The ranges assume a clear 10-foot radius to whirl the loop; without it, half the given figure. The base chance of hitting the target is 20%, plus 1% for every foot of distance below the maximum range; moderate to heavy precipitation, wind over 20 miles per hour or hampered visibility (fog, night) halve the chance - the fog example: a 17th-level character at 50 feet has (20 + 40) / 2 = 30%. Before crossing, BOTH ends must be anchored, and a suitable protrusion must exist on the near side too (wise to check before anchoring the far side). Once anchored, characters move hand-over-hand at a maximum 30 feet per round; it is prudent for only one to use the rope at a time - if more than one hangs from it, each makes a Dexterity Check at +2 on the die, failure meaning a lost grip and a fall. Census 369 -> 370.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 445,
  "prefix" = "wcx",
  "banner" = {
      "title" = "The WSG CROSSING A CHASM ON A ROPE, R445: the chasm prose and Table 21 - characters can negotiate a chasm or deep canyon by anchoring a rope on the far side and moving hand-over-hand across it. Success depends on two factors: whether the terrain offers a protrusion to anchor a line, and whether the rope can be anchored to hold their weight; a grappling hook answers both questions through Table 20. A thrown loop of rope can also catch a protrusion if the target is directly across or only slightly above or below the thrower (never on a vertical climb), but only a thief or a rope-use proficient character can succeed. Table 21 gives the maximum ranges by level band: 40 feet at 1-4, 50 at 5-8, 60 at 9-12, 75 at 13-16 and 90 at 17+. The ranges assume a clear 10-foot radius to whirl the loop; without it, half the given figure. The base chance of hitting the target is 20%, plus 1% for every foot of distance below the maximum range; moderate to heavy precipitation, wind over 20 miles per hour or hampered visibility (fog, night) halve the chance - the fog example: a 17th-level character at 50 feet has (20 + 40) / 2 = 30%. Before crossing, BOTH ends must be anchored, and a suitable protrusion must exist on the near side too (wise to check before anchoring the far side). Once anchored, characters move hand-over-hand at a maximum 30 feet per round; it is prudent for only one to use the rope at a time - if more than one hangs from it, each makes a Dexterity Check at +2 on the die, failure meaning a lost grip and a fall. Census 369 -> 370.",
      "provenance" = "the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed pp. 38-39; the user own copy OCR cross-checked against the archive djvu word layer (Guide_0038.djvu for the chasm prose and Table 21, the Guide_0039.djvu head for the crossing rate) - the section reads CLEAN, every number (the 40/50/60/75/90 ranges, the 10-foot radius, the 20% base with the +1% per foot, the 20 mph wind, the 17th-level 30% fog example, the 30-feet-per-round rate and the +2 Dexterity modifier) matched exactly; no eye-reads were needed.",
      "sentinel" = "The thrown loop: 40 to 90 feet by level band, base hit chance 20% plus 1% per foot below maximum range, halved in bad conditions - and the crossing itself runs hand-over-hand at 30 feet per round, one character at a time, with a +2 Dexterity Check for each extra hanger on the rope.",
    },
  "consts" = { {
      "name" = "wcxBaseHitPct",
      "value" = 20,
      "comment" = "The base chance of hitting the target with a thrown loop is 20%.",
    }, {
      "name" = "wcxClosenessBonusPerFt",
      "value" = 1,
      "comment" = "The hit chance gains a +1% bonus for every foot of distance between thrower and target that is LESS than the maximum range - the closer the target, the better the chance.",
    }, {
      "name" = "wcxWhirlRadiusFt",
      "value" = 10,
      "comment" = "The Table 21 ranges assume a clear 10-foot radius of space around the character so the loop can be whirled around before it is released.",
    }, {
      "name" = "wcxWindMphLimit",
      "value" = 20,
      "comment" = "Wind blowing more than 20 miles per hour halves the chance of hitting the target; moderate to heavy precipitation or hampered visibility (fog, night) do the same.",
    }, {
      "name" = "wcxCrossRateFtPerRound",
      "value" = 30,
      "comment" = "Once a rope is securely anchored at both ends, characters move along it hand-over-hand at a maximum rate of 30 feet per round.",
    }, {
      "name" = "wcxMultipleHangerDexMod",
      "value" = 2,
      "comment" = "If more than one character hangs from the rope at the same time, each of them must make a Dexterity Check with a +2 modifier to the die roll; failure means a lost grip and a fall.",
    }, {
      "name" = "wcxLoopBandCount",
      "value" = 5,
      "comment" = "Table 21 has five level bands: 1-4, 5-8, 9-12, 13-16 and 17+.",
    } },
  "bools" = { {
      "name" = "wcxTwoFactorsProtrusionAndHold",
      "value" = true,
      "comment" = "The chasm tactic depends on two factors: whether the terrain offers a protrusion to anchor a line, and whether the rope can be anchored so it will hold the characters weight.",
    }, {
      "name" = "wcxGrapplingHookViaTable20",
      "value" = true,
      "comment" = "A rope attached to a grappling hook answers both factors by using Table 20, choosing the terrain line that most closely corresponds to the target area.",
    }, {
      "name" = "wcxLoopTargetAcrossOrSlightly",
      "value" = true,
      "comment" = "A thrown loop can catch a protrusion only if the target is located directly across from or only slightly above or below the thrower.",
    }, {
      "name" = "wcxLoopNeverOnVerticalClimb",
      "value" = true,
      "comment" = "The thrown-loop tactic does not work on a vertical climb, which is why it was not discussed with the grappling hooks.",
    }, {
      "name" = "wcxThiefOrRopeUseOnly",
      "value" = true,
      "comment" = "Only a thief or a character with proficiency in rope use can succeed with a thrown loop; no one else can.",
    }, {
      "name" = "wcxNoWhirlRadiusHalvesRange",
      "value" = true,
      "comment" = "Without the clear 10-foot whirling radius, the maximum range is half of the given Table 21 figure.",
    }, {
      "name" = "wcxBadConditionsHalveHit",
      "value" = true,
      "comment" = "Moderate to heavy precipitation, wind over 20 miles per hour, or any condition hampering visibility (fog, night) modifies the hit chance downward by half.",
    }, {
      "name" = "wcxBothEndsMustBeAnchored",
      "value" = true,
      "comment" = "Before characters can move across a horizontally anchored rope, both ends must be anchored - which means a suitable protrusion must also exist at the location the characters are moving FROM (wise to check before anchoring the far side).",
    }, {
      "name" = "wcxOneAtATimePrudent",
      "value" = true,
      "comment" = "It is prudent for only one character to use the rope at a time.",
    }, {
      "name" = "wcxMultiHangerDexCheck",
      "value" = true,
      "comment" = "If more than one character hangs from the rope at the same time, each must make the +2 Dexterity Check; failure means the character loses his grip on the rope and falls.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "Table 21: THROWN LOOP RANGES",
      "tag" = "21",
      "count" = "wcxLoopBandCount",
      "col_default" = 90,
      "audit_comment" = "the Table 21 grid: the five level bands (1-4, 5-8, 9-12, 13-16, 17+) x the maximum thrown-loop range in feet - 40/50/60/75/90, with the 17+ band continuing beyond the table",
      "cols" = { "wcxMaxRangeFt" },
      "col_comments" = { "The maximum distance in feet at which the character can hit a target with a thrown loop, by level band: 40 feet at levels 1-4, 50 at 5-8, 60 at 9-12, 75 at 13-16 and 90 at 17 and above." },
      "data" = { { 40 }, { 50 }, { 60 }, { 75 }, { 90 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['wcxMaxRangeFt'](0) != 40 or m['wcxMaxRangeFt'](1) != 50 or m['wcxMaxRangeFt'](2) != 60 or m['wcxMaxRangeFt'](3) != 75 or m['wcxMaxRangeFt'](4) != 90",
      "note" = "the Table 21 ladder: 40/50/60/75/90 feet of maximum range across the five level bands",
    }, {
      "expr" = "m['wcxBaseHitPct']() != 20 or m['wcxClosenessBonusPerFt']() != 1",
      "note" = "the hit formula: a 20% base chance with a +1% bonus per foot below the maximum range",
    }, {
      "expr" = "m['wcxBaseHitPct']() + (m['wcxMaxRangeFt'](4) - 50) * m['wcxClosenessBonusPerFt']() != 2 * 30",
      "note" = "the fog example, cross-multiplied: a 17th-level character (range 90) at 50 feet has 20 + 40 = 60, halved by the fog to 30%",
    }, {
      "expr" = "m['wcxMaxRangeFt'](0) != 2 * 20",
      "note" = "the whirl-radius halving: without the 10-foot radius the range is half the given figure - the 1-4 band drops from 40 to 20 feet",
    }, {
      "expr" = "m['wcxCrossRateFtPerRound']() != 30 or m['wcxMultipleHangerDexMod']() != 2 or m['wcxWindMphLimit']() != 20 or m['wcxWhirlRadiusFt']() != 10",
      "note" = "the crossing numbers: 30 feet per round hand-over-hand, the +2 Dexterity modifier for multiple hangers, the 20 mph wind limit and the 10-foot whirling radius",
    } },
  "audit" = {
      "label" = "R445 WSG chasm crossing pin audit",
      "comment" = "The chasm-crossing slice pins the two anchor factors (a protrusion to anchor on, an anchor that holds - the grappling hook answers both via Table 20), the thrown-loop tactic (thief or rope-use proficient only, target directly across or slightly above/below, never on a vertical climb), Table 21 THROWN LOOP RANGES (40/50/60/75/90 feet by level band), the 10-foot whirl-radius assumption with the halved range otherwise, the 20% base hit chance with the +1% closeness bonus per foot below maximum range, the halving conditions (moderate to heavy precipitation, wind over 20 mph, hampered visibility), the both-ends-anchored rule with the near-side protrusion requirement, and the 30-feet-per-round hand-over-hand crossing rate with the +2 Dexterity check for multiple simultaneous hangers (rules/wsg/wsgchasm.h, prefix wcx); census 369 -> 370.",
    },
}
