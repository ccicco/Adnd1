-- wjp: promoted from tools/spec_r448.json (the The WSG JUMPING, R448: the jumping prose and TABLE 22 CHARACTERS' JUMPING ABILITY with the p. 40 modifiers - thief-acrobats and barbarians are particularly skilled in jumping, but ANY character can make a broad jump or a high jump. On the average a running broad jump covers FOUR more feet than a standing one, but it requires a 20-foot run in a straight line toward the obstacle immediately before leaping; without that space or the time to start the run, the standing jump is the best he can do. A high jump covers HALF as much distance horizontally as its height; a flat surface higher than the current elevation is landed on with a roll to absorb the impact; a thin barrier with level ground on the far side demands a successful high jump AND a Dexterity Check - failure lands him in a heap (1d3 damage for a jump of five feet or higher) and he needs the next round to stand up. The die is rolled for EACH jump attempt (a 4th-level character clears a 3-foot high jump only on a 1d3 roll of 3). Table 22: the seven level bands 1-6 through 23+ with the standing broad (1d4+1 to 1d6+6), the running broad (1d4+5 to 1d6+15) and the high jump (1d3 to 1d6+1). Modifiers, cumulative: moderately encumbered -1 foot; heavily encumbered -2 feet and cannot high jump; severely encumbered cannot jump at all; halfling -1 foot on broad jumps only; gnome or dwarf -2 feet broad and -1 foot high - with floors of 2 feet broad and 1 foot high. Census 372 -> 373.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 448,
  "prefix" = "wjp",
  "banner" = {
      "title" = "The WSG JUMPING, R448: the jumping prose and TABLE 22 CHARACTERS' JUMPING ABILITY with the p. 40 modifiers - thief-acrobats and barbarians are particularly skilled in jumping, but ANY character can make a broad jump or a high jump. On the average a running broad jump covers FOUR more feet than a standing one, but it requires a 20-foot run in a straight line toward the obstacle immediately before leaping; without that space or the time to start the run, the standing jump is the best he can do. A high jump covers HALF as much distance horizontally as its height; a flat surface higher than the current elevation is landed on with a roll to absorb the impact; a thin barrier with level ground on the far side demands a successful high jump AND a Dexterity Check - failure lands him in a heap (1d3 damage for a jump of five feet or higher) and he needs the next round to stand up. The die is rolled for EACH jump attempt (a 4th-level character clears a 3-foot high jump only on a 1d3 roll of 3). Table 22: the seven level bands 1-6 through 23+ with the standing broad (1d4+1 to 1d6+6), the running broad (1d4+5 to 1d6+15) and the high jump (1d3 to 1d6+1). Modifiers, cumulative: moderately encumbered -1 foot; heavily encumbered -2 feet and cannot high jump; severely encumbered cannot jump at all; halfling -1 foot on broad jumps only; gnome or dwarf -2 feet broad and -1 foot high - with floors of 2 feet broad and 1 foot high. Census 372 -> 373.",
      "provenance" = "the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed pp. 39-40; the user own copy OCR (pages 40-41) cross-checked against the archive djvu word layer (Guide_0039.djvu with the Guide_0040.djvu head) - the prose reads CLEAN two-way, every number (the four-foot advantage, the 20-foot run, the half-height high jump, the 1d3 five-foot heap damage, the modifier feet and the 2/1 floors) matched exactly; the Table 22 grid is GARBLED in the djvu word layer, so every cell was confirmed by TWO independent IIIF eye-reads of leaf 39 - the OCR and both eye-reads agree on all 21 cells.",
      "sentinel" = "A running broad jump buys four feet over a standing one but only after a 20-foot straight run; a high jump covers half its height sideways; Table 22 rolls the dice per attempt by level band, and the cumulative encumbrance and demihuman modifiers can never push a jump below two feet broad or one foot high.",
    },
  "consts" = { {
      "name" = "wjpRunningAdvantageFt",
      "value" = 4,
      "comment" = "On the average, a character can cover four more feet of distance with a running broad jump than he can with a standing broad jump.",
    }, {
      "name" = "wjpRunRequiredFt",
      "value" = 20,
      "comment" = "A running broad jump requires the character to make a 20-foot run in a straight line toward the obstacle immediately before leaping.",
    }, {
      "name" = "wjpHighHorizDiv",
      "value" = 2,
      "comment" = "A high jump will cover half as much distance horizontally as the height of the jump.",
    }, {
      "name" = "wjpHeapDmgDie",
      "value" = 3,
      "comment" = "Failure on the thin-barrier Dexterity Check indicates the jumper has landed in a heap, possibly causing damage (a 1d3 roll for a jump of five feet or higher).",
    }, {
      "name" = "wjpHeapMinFt",
      "value" = 5,
      "comment" = "The heap damage is possible for a jump of five feet or higher.",
    }, {
      "name" = "wjpStandFloorFt",
      "value" = 2,
      "comment" = "The modifiers are cumulative, but in no case can a broad jump be reduced to less than 2 feet for a character who is otherwise able to make the jump.",
    }, {
      "name" = "wjpHighFloorFt",
      "value" = 1,
      "comment" = "In no case can a high jump be reduced to less than 1 foot for a character who is otherwise able to make the jump.",
    }, {
      "name" = "wjpEncModerateFt",
      "value" = 1,
      "comment" = "Moderately encumbered: -1 foot on jumping ability.",
    }, {
      "name" = "wjpEncHeavyBroadFt",
      "value" = 2,
      "comment" = "Heavily encumbered: -2 feet, and the character cannot high jump at all.",
    }, {
      "name" = "wjpHalflingBroadFt",
      "value" = 1,
      "comment" = "Halfling: -1 foot on broad jumps only.",
    }, {
      "name" = "wjpDwarfBroadFt",
      "value" = 2,
      "comment" = "Gnome or dwarf: -2 feet on broad jumps.",
    }, {
      "name" = "wjpDwarfHighFt",
      "value" = 1,
      "comment" = "Gnome or dwarf: -1 foot on high jumps.",
    }, {
      "name" = "wjpBandCount",
      "value" = 7,
      "comment" = "Table 22 has seven level bands: 1-6, 7-9, 10-12, 13-15, 16-18, 19-22 and 23+.",
    } },
  "bools" = { {
      "name" = "wjpAnyCharacterCanJump",
      "value" = true,
      "comment" = "Although thief-acrobats and barbarians are particularly skilled in jumping, any character is capable of making a broad jump or a high jump to get across or over something in his path.",
    }, {
      "name" = "wjpRunNeedsStraightRun",
      "value" = true,
      "comment" = "A running broad jump requires the 20-foot straight-line run; if this space does not exist or there is no time to back up and start the run, then a standing broad jump is the best he can do.",
    }, {
      "name" = "wjpRollToHigherSurface",
      "value" = true,
      "comment" = "If the target is a flat surface higher than the character current elevation, he can (if he succeeds in the leap) jump up to the surface and roll to absorb the impact of the jump.",
    }, {
      "name" = "wjpThinBarrierDexCheck",
      "value" = true,
      "comment" = "If the obstacle is a thin barrier and the surface on the other side is at the same elevation, the jumper must make a successful high jump and then a Dexterity Check.",
    }, {
      "name" = "wjpHeapNeedsNextRound",
      "value" = true,
      "comment" = "Failure on the check indicates that he has landed in a heap and will need the next round to stand up.",
    }, {
      "name" = "wjpDieRolledPerJump",
      "value" = true,
      "comment" = "The die is rolled for each jump attempt - a 4th-level character can make a 3-foot high jump if a roll of 1d3 results in a 3, but fails to clear the height on a 1 or 2.",
    }, {
      "name" = "wjpModifiersCumulative",
      "value" = true,
      "comment" = "The modifiers to jumping ability are cumulative, subject to the 2-foot broad and 1-foot high floors.",
    }, {
      "name" = "wjpSevereCannotJump",
      "value" = true,
      "comment" = "A severely encumbered character cannot jump at all.",
    }, {
      "name" = "wjpHeavyCannotHighJump",
      "value" = true,
      "comment" = "A heavily encumbered character cannot high jump (the -2 feet applies to the broad jumps he can still make).",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "Table 22: CHARACTERS' JUMPING ABILITY",
      "tag" = "22",
      "count" = "wjpBandCount",
      "col_default" = 0,
      "cols" = { "wjpStandDie", "wjpStandPlus", "wjpRunDie", "wjpRunPlus", "wjpHighDie", "wjpHighPlus" },
      "col_comments" = { "The standing broad jump die by level band (4 = 1d4, 6 = 1d6): 1d4 for the 1-6 and 7-9 bands, 1d6 for the 10-12 through 23+ bands.", "The standing broad jump plus feet by level band: 1, 2, 2, 3, 4, 5 and 6 - the 1d4+1 through 1d6+6 ladder.", "The running broad jump die by level band (4 = 1d4, 6 = 1d6): 1d4 for the 1-6 and 7-9 bands, 1d6 for the 10-12 through 23+ bands.", "The running broad jump plus feet by level band: 5, 6, 5, 6, 9, 12 and 15 - the 1d4+5 through 1d6+15 ladder.", "The high jump die by level band (3 = 1d3, 4 = 1d4, 5 = 1d5, 6 = 1d6): 1d3, 1d4, 1d3, 1d4, 1d5, 1d5 and 1d6.", "The high jump plus feet by level band: 0, 0, 1, 1, 0, 1 and 1 - the 1d3 through 1d6+1 ladder." },
      "audit_comment" = "the Table 22 grid: the seven level bands (1-6, 7-9, 10-12, 13-15, 16-18, 19-22, 23+) x the three jumps (the standing broad 1d4+1 to 1d6+6, the running broad 1d4+5 to 1d6+15, the high jump 1d3 to 1d6+1), each cell split into the die and the plus feet",
      "data" = { { 4, 1, 4, 5, 3, 0 }, { 4, 2, 4, 6, 4, 0 }, { 6, 2, 6, 5, 3, 1 }, { 6, 3, 6, 6, 4, 1 }, { 6, 4, 6, 9, 5, 0 }, { 6, 5, 6, 12, 5, 1 }, { 6, 6, 6, 15, 6, 1 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['wjpStandDie'](0) != 4 or m['wjpStandPlus'](0) != 1 or m['wjpRunDie'](0) != 4 or m['wjpRunPlus'](0) != 5 or m['wjpHighDie'](0) != 3 or m['wjpHighPlus'](0) != 0",
      "note" = "the 1-6 band exactly as printed: 1d4+1 standing, 1d4+5 running, 1d3 high",
    }, {
      "expr" = "m['wjpStandPlus'](6) != 6 or m['wjpRunPlus'](6) != 15 or m['wjpHighDie'](6) != 6 or m['wjpHighPlus'](6) != 1",
      "note" = "the 23+ band: 1d6+6 standing, 1d6+15 running, 1d6+1 high",
    }, {
      "expr" = "m['wjpRunningAdvantageFt']() != 4 or m['wjpRunRequiredFt']() != 20 or m['wjpHeapDmgDie']() != 3 or m['wjpHeapMinFt']() != 5",
      "note" = "the printed prose numbers: the four-foot running advantage, the 20-foot straight run, the 1d3 heap damage at five feet or higher",
    }, {
      "expr" = "m['wjpRunPlus'](4) != 9 or m['wjpRunPlus'](5) != 12 or m['wjpRunPlus'](6) != 15",
      "note" = "the running ladder caps 9/12/15 - the three biggest running pluses, each in its own band",
    }, {
      "expr" = "m['wjpStandFloorFt']() != 2 or m['wjpHighFloorFt']() != 1 or m['wjpStandFloorFt']() != 2 * m['wjpHighFloorFt']()",
      "note" = "the modifier floors: 2 feet broad and 1 foot high - the broad floor is twice the high floor",
    } },
  "audit" = {
      "label" = "R448 WSG jumping pin audit",
      "comment" = "The jumping slice pins the any-character rule, the four-foot running advantage with its 20-foot straight run, the half-height high jump with the roll-to-absorb landing, the thin-barrier high jump plus Dexterity Check with the 1d3 heap damage at five feet or higher and the next-round stand-up, the per-jump die roll, Table 22 (the seven level bands with the standing broad, running broad and high jump dice), and the cumulative modifiers (moderate -1, heavy -2 and cannot high jump, severe cannot jump at all, halfling -1 broad only, gnome or dwarf -2 broad and -1 high) with the 2-foot broad and 1-foot high floors (rules/wsg/wsgjump.h, prefix wjp); census 372 -> 373.",
    },
}
