-- wfs: promoted from tools/spec_r465.json (the R465: the WSG HUNTING PROFICIENCY AND FISHING slice - the hunting proficiency (the one-hit size M kill, the two-hit size L kill, the 50% distance kill of a wounded size M with a single attempt, the single-hit wounded size L with multiple attempts, the successful Proficiency Check before the 1d6 roll, the missile-weapon requirement, no boost to the encounter chance or the prey size, the repeatable expeditions), fishing (the one-hour baited hook-and-line base, the net +50%, the zero-or-lower no-fish gate, the proficiency +2 in fair or good spots only, the cumulative -1 per extra group member, the cumulative -2 per hour beyond the first in the same spot, the fished-out rule, the spot-quality guidelines) and Table 32 (the spot-by-time dice grid), printed p. 57 with the spot-guideline tail on p. 58.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 465,
  "prefix" = "wfs",
  "banner" = {
      "title" = "R465: the WSG HUNTING PROFICIENCY AND FISHING slice - the hunting proficiency (the one-hit size M kill, the two-hit size L kill, the 50% distance kill of a wounded size M with a single attempt, the single-hit wounded size L with multiple attempts, the successful Proficiency Check before the 1d6 roll, the missile-weapon requirement, no boost to the encounter chance or the prey size, the repeatable expeditions), fishing (the one-hour baited hook-and-line base, the net +50%, the zero-or-lower no-fish gate, the proficiency +2 in fair or good spots only, the cumulative -1 per extra group member, the cumulative -2 per hour beyond the first in the same spot, the fished-out rule, the spot-quality guidelines) and Table 32 (the spot-by-time dice grid), printed p. 57 with the spot-guideline tail on p. 58.",
      "provenance" = "Ground truth three-way: the archive djvu word layer vs the pixel reads of the native decode of the printed p. 57 image (a pure-Python JPEG decoder, 1179x1516) vs vision reads of contrast-stretched cell crops. The text layer drops the Fair-Day cell and garbles four Good cells; the pixels settled them: Fair-Day 1d6-2 (glyph holes=1, the canonical 6 template at 0.947), Good-Day 1d8-2 (the digit shows the stacked-loop waist of an 8, template 0.775 vs 0.738 for the 6), Good-Night 1d6+2 (proven by the book own A/B/C example: 1d6+4 for the proficient A = 1d6+2 + 2), Good-Dawn 1d8+2 (the same 8 waist; the plus vertical stroke survives as faint 158-238 grayscale traces through the bar while the true minus on the same page shows pure background around its bar). The Fair and Good row labels are pixel-and-vision confirmed. The p. 58 tail completes the p. 57 sentence: fish congregate where they can be shaded by trees or overhanging terrain; such a spot is fair or good while an unshaded spot nearby on the same body of water is a poor one.",
      "sentinel" = "All 18 Table 32 cells pinned (the die and the modifier per row per time band); the hunting proficiency and fishing mechanics are audit examples, including the book own A/B/C three-fisherman hour-by-hour example.",
    },
  "consts" = { {
      "name" = "wfsRowCount",
      "value" = 3,
      "comment" = "the Table 32 row count: the poor, fair and good spot-quality rows",
    }, {
      "name" = "wfsNetBonusPct",
      "value" = 50,
      "comment" = "a net increases the take to 50% more than the modified die roll",
    }, {
      "name" = "wfsProfBonus",
      "value" = 2,
      "comment" = "a character with fishing proficiency gets a +2 modifier in any fair or good area",
    }, {
      "name" = "wfsGroupPenalty",
      "value" = 1,
      "comment" = "each extra member of the fishing group takes a cumulative -1: -1 for the second character, -2 for the third, and so on",
    }, {
      "name" = "wfsSpotHourPenalty",
      "value" = 2,
      "comment" = "each hour beyond the first spent in the same spot takes a further cumulative -2 per hour",
    }, {
      "name" = "wfsFishedOutDays",
      "value" = 1,
      "comment" = "a fished-out spot will not yield any more fish for at least one day",
    }, {
      "name" = "wfsProfWoundedMDistancePct",
      "value" = 50,
      "comment" = "a proficient hunter has a 50% chance of killing a wounded size M creature from a distance instead of closing with it",
    }, {
      "name" = "wfsProfWoundedLHits",
      "value" = 1,
      "comment" = "a proficient hunter kills a wounded size L creature with a single hit instead of the two or three a group might need",
    } },
  "bools" = { {
      "name" = "wfsProfCheckBeforeRoll",
      "value" = true,
      "comment" = "the hunting proficiency feats require a successful Proficiency Check when game is encountered, before the 1d6 size-and-number roll",
    }, {
      "name" = "wfsProfNeedsMissile",
      "value" = true,
      "comment" = "the proficiency feats require a missile weapon of the appropriate sort",
    }, {
      "name" = "wfsProfNoEncounterBoost",
      "value" = true,
      "comment" = "a proficient hunter does not increase the chance of encountering game, nor affect the size of the prey encountered",
    }, {
      "name" = "wfsProfRepeatable",
      "value" = true,
      "comment" = "hunting expeditions may be undertaken as often as desired - animals are not rooted, and the same area can be searched again",
    }, {
      "name" = "wfsProfWoundedMOneAttempt",
      "value" = true,
      "comment" = "only one distance-kill attempt on a wounded size M creature; if it fails, the creature has escaped",
    }, {
      "name" = "wfsProfWoundedLMultipleAttempts",
      "value" = true,
      "comment" = "multiple attempts are permitted on a wounded size L creature if it is not dispatched on the first attempt",
    }, {
      "name" = "wfsZeroNoFish",
      "value" = true,
      "comment" = "a die-roll result of zero or lower catches no fish regardless of the gear used",
    }, {
      "name" = "wfsProfBonusFairGoodOnly",
      "value" = true,
      "comment" = "the fishing proficiency bonus applies only in fair or good areas - prowess does not help in a poor spot",
    }, {
      "name" = "wfsFishedOutAllZero",
      "value" = true,
      "comment" = "a spot is fished out as soon as every fisherman gets a result of zero or lower in the same hour",
    }, {
      "name" = "wfsBoatBetterThanShore",
      "value" = true,
      "comment" = "fishing from a boat moored in the middle of a body of water is better than fishing from shore",
    }, {
      "name" = "wfsShadedSpotFairGood",
      "value" = true,
      "comment" = "in hot or sunny weather fish congregate where they can be shaded by trees or overhanging terrain, or in rain; such a spot is fair or good",
    }, {
      "name" = "wfsUnshadedSpotPoor",
      "value" = true,
      "comment" = "an unshaded spot nearby on the same body of water will be a poor one",
    }, {
      "name" = "wfsSwampBogPoor",
      "value" = true,
      "comment" = "a swamp or bog is generally a poor place for fishing",
    }, {
      "name" = "wfsStagnantCreekPoor",
      "value" = true,
      "comment" = "a stagnant, shallow creek is a poor place for fishing",
    } },
  "switches" = { {
      "name" = "wfsProfHitsToKill",
      "values" = { 1, 1, 2 },
      "comment" = "hits to kill with hunting proficiency by size band: one for size S, one for size M (instead of two), two for size L (instead of four)",
    } },
  "tables" = { {
      "name" = "wfsFishSuccess",
      "tag" = "32",
      "count" = "wfsRowCount",
      "cols" = { "wfsDayDie", "wfsDayMod", "wfsNightDie", "wfsNightMod", "wfsDawnDie", "wfsDawnMod" },
      "col_default" = 0,
      "col_comments" = { "the Table 32 daytime die", "the Table 32 daytime modifier", "the Table 32 night die", "the Table 32 night modifier", "the Table 32 dawn/dusk die", "the Table 32 dawn/dusk modifier" },
      "row_comments" = { "the poor spot row", "the fair spot row", "the good spot row" },
      "data" = { { 4, -2, 4, 0, 4, 2 }, { 6, -2, 6, -1, 6, 2 }, { 8, -2, 6, 2, 8, 2 } },
      "audit_comment" = "the Table 32 fishing success grid (the die and the modifier per spot quality per time of day)",
    } },
  "chains" = {},
  "examples" = { {
      "note" = "the poor spot: 1d4-2 by day, 1d4 at night, 1d4+2 at dawn or dusk",
      "expr" = "m['wfsDayDie'](0) != 4 or m['wfsDayMod'](0) != -2 or m['wfsNightDie'](0) != 4 or m['wfsNightMod'](0) != 0 or m['wfsDawnDie'](0) != 4 or m['wfsDawnMod'](0) != 2",
    }, {
      "note" = "the fair spot: 1d6-2 by day, 1d6-1 at night, 1d6+2 at dawn or dusk (the OCR-dropped day cell, pixel-confirmed)",
      "expr" = "m['wfsDayDie'](1) != 6 or m['wfsDayMod'](1) != -2 or m['wfsNightDie'](1) != 6 or m['wfsNightMod'](1) != -1 or m['wfsDawnDie'](1) != 6 or m['wfsDawnMod'](1) != 2",
    }, {
      "note" = "the good spot: 1d8-2 by day, 1d6+2 at night (the book example cell), 1d8+2 at dawn or dusk",
      "expr" = "m['wfsDayDie'](2) != 8 or m['wfsDayMod'](2) != -2 or m['wfsNightDie'](2) != 6 or m['wfsNightMod'](2) != 2 or m['wfsDawnDie'](2) != 8 or m['wfsDawnMod'](2) != 2",
    }, {
      "note" = "the book hour-1 example A: the proficient lone fisherman at a good spot at night rolls 1d6+4",
      "expr" = "m['wfsNightMod'](2) + m['wfsProfBonus']() != 4",
    }, {
      "note" = "the book hour-1 example B: the first extra group member rolls 1d6+1",
      "expr" = "m['wfsNightMod'](2) - m['wfsGroupPenalty']() != 1",
    }, {
      "note" = "the book hour-1 example C: the second extra group member rolls 1d6",
      "expr" = "m['wfsNightMod'](2) - 2 * m['wfsGroupPenalty']() != 0",
    }, {
      "note" = "the book hour-2 example A: 1d6+2 (the night modifier less the hour penalty plus the proficiency bonus)",
      "expr" = "m['wfsNightMod'](2) - m['wfsSpotHourPenalty']() + m['wfsProfBonus']() != 2",
    }, {
      "note" = "the book hour-2 example B: 1d6-1",
      "expr" = "m['wfsNightMod'](2) - m['wfsSpotHourPenalty']() - m['wfsGroupPenalty']() != -1",
    }, {
      "note" = "the book hour-3 example B: 1d6-3 (the cumulative hour penalty twice plus the group penalty)",
      "expr" = "m['wfsNightMod'](2) - 2 * m['wfsSpotHourPenalty']() - m['wfsGroupPenalty']() != -3",
    }, {
      "note" = "the book hour-3 example C: 1d6-4, and in hour 4 all three can reach zero or lower - the fished-out hour",
      "expr" = "m['wfsNightMod'](2) - 2 * m['wfsSpotHourPenalty']() - 2 * m['wfsGroupPenalty']() != -4",
    }, {
      "note" = "the net: a take of 4 fish rises to 6 (50% more, cross-multiplied)",
      "expr" = "2 * 100 != 4 * m['wfsNetBonusPct']()",
    }, {
      "note" = "the fished-out spot yields nothing for at least one day",
      "expr" = "m['wfsFishedOutDays']() != 1",
    }, {
      "note" = "the hunting proficiency kill ladder: one hit for size S and M, two for size L",
      "expr" = "m['wfsProfHitsToKill'](0) != 1 or m['wfsProfHitsToKill'](1) != 1 or m['wfsProfHitsToKill'](2) != 2",
    }, {
      "note" = "the distance kill of a wounded size M creature: a 50% chance, one attempt only",
      "expr" = "m['wfsProfWoundedMDistancePct']() != 50",
    }, {
      "note" = "the wounded size L creature drops to a single hit for a proficient hunter",
      "expr" = "m['wfsProfWoundedLHits']() != 1",
    } },
  "audit" = {
      "label" = "R465 WSG fishing pin audit",
      "comment" = "The Table 32 dice grid cell by cell (the die and the modifier per spot quality per time of day), the hunting proficiency kill rules (the one-hit size M kill, the two-hit size L kill, the distance kill of a wounded size M, the single-hit wounded size L, the Proficiency Check before the 1d6 roll) and the fishing mechanics (the net bonus, the zero gate, the proficiency bonus, the group and hour penalties, the fished-out rule) - every cell, const, bool and switch verified against the model.",
    },
}
