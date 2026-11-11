-- wsm: promoted from tools/spec_r450.json (the The WSG SWIMMING, R450: the swimming intro, TABLE 24 EFFECTS OF ENCUMBRANCE ON SWIMMING, and the Endurance and Speed subsections - only characters with proficiency in swimming can propel themselves through the water without magic or a flotation device, but nonproficient characters do not simply sink like a stone (the section covers swimming and treading water). The three sub-skills are endurance, speed and diving; the most important factor for ANY swimmer is his degree of encumbrance. Table 24: the five encumbrance rows (none, light, moderate, heavy, severe) x the four functions (endurance, speed, diving, surfacing) - none doubles everything but diving; light is the unmodified baseline; moderate halves endurance, speed and surfacing while doubling diving; heavy quarters them while tripling diving; severe is the dash - impossible - except diving, which stays tripled: a severely encumbered character cannot swim, sinks in water deeper than his height and cannot surface without dropping encumbrance. Endurance: the base, in turns, is the total of experience levels plus the constitution score; at the limit he must rest out of the water or standing in calm water, regaining three turns per turn of rest; high speed doubles the movement rate but cuts endurance to 1/10 (rounded up), and high-speed losses are regained only one-for-one. Speed: humans swim 4 inches (40 feet per round), other PC races and land-based humanoids 3 inches; beneath the surface the rate is 2/3 (rounded up); strength and current modifiers run +1/+2/+3 for strength 16-17/18/18-01+ and plus-or-minus 1-3 light, 4-6 strong; a modified rate of 0 means holding position at endurance cost, less than 0 means the mercy of the current (drifting backward 1-3 inches); high speed is surface-only and is halved where the normal rate would be 0 or less. Census 374 -> 375.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 450,
  "prefix" = "wsm",
  "banner" = {
      "title" = "The WSG SWIMMING, R450: the swimming intro, TABLE 24 EFFECTS OF ENCUMBRANCE ON SWIMMING, and the Endurance and Speed subsections - only characters with proficiency in swimming can propel themselves through the water without magic or a flotation device, but nonproficient characters do not simply sink like a stone (the section covers swimming and treading water). The three sub-skills are endurance, speed and diving; the most important factor for ANY swimmer is his degree of encumbrance. Table 24: the five encumbrance rows (none, light, moderate, heavy, severe) x the four functions (endurance, speed, diving, surfacing) - none doubles everything but diving; light is the unmodified baseline; moderate halves endurance, speed and surfacing while doubling diving; heavy quarters them while tripling diving; severe is the dash - impossible - except diving, which stays tripled: a severely encumbered character cannot swim, sinks in water deeper than his height and cannot surface without dropping encumbrance. Endurance: the base, in turns, is the total of experience levels plus the constitution score; at the limit he must rest out of the water or standing in calm water, regaining three turns per turn of rest; high speed doubles the movement rate but cuts endurance to 1/10 (rounded up), and high-speed losses are regained only one-for-one. Speed: humans swim 4 inches (40 feet per round), other PC races and land-based humanoids 3 inches; beneath the surface the rate is 2/3 (rounded up); strength and current modifiers run +1/+2/+3 for strength 16-17/18/18-01+ and plus-or-minus 1-3 light, 4-6 strong; a modified rate of 0 means holding position at endurance cost, less than 0 means the mercy of the current (drifting backward 1-3 inches); high speed is surface-only and is halved where the normal rate would be 0 or less. Census 374 -> 375.",
      "provenance" = "the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 41; the user own copy OCR (page 42) cross-checked against the archive djvu word layer (Guide_0041.djvu) - the intro, Endurance and Speed prose reads CLEAN two-way, every number (the 3-turn rest rate, the 1/10 high-speed cut, the 18-turn example, the 40/30 base rates, the 2/3 subsurface rate, the modifier table and the 0-inch rules) matched exactly; the Table 24 grid and the strength/current modifier table are GARBLED in the djvu word layer, so every cell was confirmed by TWO independent IIIF eye-reads of leaf 41 - the OCR and both eye-reads agree on all 20 Table 24 cells and all seven modifier rows.",
      "sentinel" = "Encumbrance rules the water: none doubles, light is the baseline, moderate halves (but doubles the dive), heavy quarters (but triples the dive), and severe cannot swim at all - only the dive keeps working, straight down.",
    },
  "consts" = { {
      "name" = "wsmSubSkillCount",
      "value" = 3,
      "comment" = "The skill of swimming is composed of three sub-skills: endurance (how long a character can keep swimming), speed (how fast he can move through the water), and diving (how rapidly he can move downward through the water).",
    }, {
      "name" = "wsmEncRowCount",
      "value" = 5,
      "comment" = "Table 24 has five encumbrance rows: none, light, moderate, heavy and severe.",
    }, {
      "name" = "wsmRestRegainPerTurn",
      "value" = 3,
      "comment" = "A resting swimmer regains three turns of endurance for every turn spent resting - out of the water or standing in calm water that is not over his head; the same rate applies if he stops before using up all his endurance.",
    }, {
      "name" = "wsmHighSpeedMult",
      "value" = 2,
      "comment" = "A character can swim at high speed, doubling his normal movement rate.",
    }, {
      "name" = "wsmHighSpeedEndDiv",
      "value" = 10,
      "comment" = "Swimming at high speed reduces his endurance to 1/10 of its normal amount, rounded up.",
    }, {
      "name" = "wsmHumanSwimRateFt",
      "value" = 40,
      "comment" = "The base swimming movement rate for humans is 4 inches (40 feet per round).",
    }, {
      "name" = "wsmOtherSwimRateFt",
      "value" = 30,
      "comment" = "For other player-character races and land-based humanoids, the base swimming movement rate is 3 inches (30 feet per round).",
    }, {
      "name" = "wsmSubsurfaceNum",
      "value" = 2,
      "comment" = "For a swimmer moving beneath the surface of the water, the rate is reduced to 2/3 of the given amount, rounded up.",
    }, {
      "name" = "wsmSubsurfaceDen",
      "value" = 3,
      "comment" = "The denominator of the subsurface reduction: 2/3 of the surface rate, rounded up.",
    }, {
      "name" = "wsmStr1617BonusIn",
      "value" = 1,
      "comment" = "Swimming movement rate modifier: Strength 16 or 17, +1 inch.",
    }, {
      "name" = "wsmStr18BonusIn",
      "value" = 2,
      "comment" = "Swimming movement rate modifier: Strength 18, +2 inches.",
    }, {
      "name" = "wsmStr1801BonusIn",
      "value" = 3,
      "comment" = "Swimming movement rate modifier: Strength 18/01 or higher, +3 inches.",
    }, {
      "name" = "wsmLightCurMaxIn",
      "value" = 3,
      "comment" = "Swimming with or against a light current modifies the rate by 1 to 3 inches, with or against the flow.",
    }, {
      "name" = "wsmStrongCurMinIn",
      "value" = 4,
      "comment" = "Swimming with or against a strong current modifies the rate by 4 to 6 inches, with or against the flow.",
    }, {
      "name" = "wsmStrongCurMaxIn",
      "value" = 6,
      "comment" = "The top of the strong-current modifier range: 4 to 6 inches.",
    }, {
      "name" = "wsmMercyDriftMaxIn",
      "value" = 3,
      "comment" = "A modified rate of less than 0 means the character is at the mercy of the current - even swimming against it he is propelled in the opposite direction at 1 to 3 inches, depending on the strength of the current.",
    } },
  "bools" = { {
      "name" = "wsmOnlyProficientSwim",
      "value" = true,
      "comment" = "Only characters with proficiency in swimming have the ability to propel themselves through the water without the aid of magic or some sort of flotation device.",
    }, {
      "name" = "wsmNonproficientNotSink",
      "value" = true,
      "comment" = "Nonproficient characters do not simply sink like a stone if they find themselves immersed in a deep body of water - the section covers swimming for those who can swim and treading water for swimmers and non-swimmers alike.",
    }, {
      "name" = "wsmEncumbranceKeyFactor",
      "value" = true,
      "comment" = "The physical attributes of a swimmer may affect how well he performs the three functions, but the most important factor - and one that applies to any swimmer - is his degree of encumbrance.",
    }, {
      "name" = "wsmDashMeansImpossible",
      "value" = true,
      "comment" = "A dash entry on Table 24 means it is impossible for the character to perform the function under that degree of encumbrance.",
    }, {
      "name" = "wsmSevereSinksCannotSurface",
      "value" = true,
      "comment" = "A severely encumbered character cannot swim - he will sink in any body of water deeper than his height, and will not be able to surface under his own power unless he gets rid of at least some of his encumbrance before he drowns.",
    }, {
      "name" = "wsmEnduranceLevelsPlusCon",
      "value" = true,
      "comment" = "A character base swimming endurance, in turns, equals his total of experience levels (counting all classes for a multiclassed or two-class character) plus his constitution score.",
    }, {
      "name" = "wsmHighSpeedEndTenthRoundUp",
      "value" = true,
      "comment" = "High-speed swimming reduces the endurance to 1/10 of its normal amount, rounded up - the example: a 6th-level thief with constitution 12 has 18 turns lightly encumbered; after 8 normal turns, his remaining 10 turns buy exactly 1 more high-speed turn.",
    }, {
      "name" = "wsmHighSpeedRestOneForOne",
      "value" = true,
      "comment" = "After a high-speed swim the character must get out of the water to rest, and the endurance lost to high speed is regained only on a one-for-one basis - one turn of endurance for one turn of rest.",
    }, {
      "name" = "wsmMonsterRateSupersedes",
      "value" = true,
      "comment" = "A specific swimming rate listed in the statistics for any monster or humanoid supersedes the base rate given here.",
    }, {
      "name" = "wsmZeroRateHoldPosition",
      "value" = true,
      "comment" = "A modified movement rate of 0 means the character cannot move forward and must exert himself, using up endurance, simply to maintain his present location.",
    }, {
      "name" = "wsmNegativeRateMercy",
      "value" = true,
      "comment" = "A modified rate of less than 0 means the character is at the mercy of the current - the example: a 4-inch base against a 4-inch current is 0, and even at high speed he manages only 2 inches (half the normal bonus).",
    }, {
      "name" = "wsmCurrentDmDetermined",
      "value" = true,
      "comment" = "The strength of the current is determinable only by the Dungeon Master - a gently flowing river is probably no more than 1 or 2 inches, a rushing mountain stream certainly in the 5 to 6 inch range.",
    }, {
      "name" = "wsmNoHighSpeedSubsurface",
      "value" = true,
      "comment" = "It is not possible to swim at high speed beneath the surface; the doubling option applies only to characters swimming on the surface.",
    }, {
      "name" = "wsmHighSpeedHalvedAtZero",
      "value" = true,
      "comment" = "The high-speed increase is halved in any water conditions where the character would have a movement rate of 0 or less at normal speed.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "Table 24: EFFECTS OF ENCUMBRANCE ON SWIMMING",
      "tag" = "24",
      "count" = "wsmEncRowCount",
      "col_default" = 1,
      "cols" = { "wsmEndNum", "wsmEndDen", "wsmSpdNum", "wsmSpdDen", "wsmDiveNum", "wsmDiveDen", "wsmSurfNum", "wsmSurfDen" },
      "col_comments" = { "The numerator of the endurance multiplier by encumbrance row (0 = the dash, impossible).", "The denominator of the endurance multiplier: x2 none, x1 light, x1/2 moderate, x1/4 heavy, dash severe.", "The numerator of the speed multiplier (0 = the dash).", "The denominator of the speed multiplier: x2, x1, x1/2, x1/4, dash.", "The numerator of the diving multiplier - the one function that never dashes: x1, x1, x2, x3, x3.", "The denominator of the diving multiplier (always 1).", "The numerator of the surfacing multiplier (0 = the dash).", "The denominator of the surfacing multiplier: x2, x1, x1/2, x1/4, dash." },
      "audit_comment" = "the Table 24 grid: the five encumbrance rows (none, light, moderate, heavy, severe) x the four functions (endurance, speed, diving, surfacing), each cell split into the numerator and denominator of the multiplier - a 0 numerator is the printed dash (impossible)",
      "data" = { { 2, 1, 2, 1, 1, 1, 2, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 2, 1, 2, 2, 1, 1, 2 }, { 1, 4, 1, 4, 3, 1, 1, 4 }, { 0, 1, 0, 1, 3, 1, 0, 1 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['wsmEndNum'](0) != 2 or m['wsmEndDen'](0) != 1 or m['wsmDiveNum'](4) != 3 or m['wsmEndNum'](4) != 0",
      "note" = "the two poles: the unencumbered endurance doubles, and the severely encumbered dive stays tripled while everything else dashes",
    }, {
      "expr" = "m['wsmRestRegainPerTurn']() != 3 or m['wsmHighSpeedMult']() != 2 or m['wsmHighSpeedEndDiv']() != 10",
      "note" = "the printed endurance numbers: the three-turn rest rate, the doubled high-speed rate, the one-tenth endurance cut",
    }, {
      "expr" = "m['wsmHumanSwimRateFt']() != 40 or m['wsmOtherSwimRateFt']() != 30 or m['wsmHumanSwimRateFt']() != 4 * m['wsmOtherSwimRateFt']() / 3",
      "note" = "the base rates: 40 feet for humans, 30 for the other races - the human rate is four thirds of the other rate",
    }, {
      "expr" = "m['wsmStr1617BonusIn']() != 1 or m['wsmStr18BonusIn']() != 2 or m['wsmStr1801BonusIn']() != 3 or m['wsmStr18BonusIn']() - m['wsmStr1617BonusIn']() != 1 or m['wsmStr1801BonusIn']() - m['wsmStr18BonusIn']() != 1",
      "note" = "the strength ladder climbs one inch at a time: +1, +2, +3 for strength 16-17, 18, 18/01+",
    }, {
      "expr" = "m['wsmStrongCurMinIn']() != m['wsmLightCurMaxIn']() + 1 or m['wsmStrongCurMaxIn']() != 6 or m['wsmMercyDriftMaxIn']() != 3",
      "note" = "the current ranges: light tops at 3, strong starts at 4 and tops at 6, and the mercy drift tops at 3",
    } },
  "audit" = {
      "label" = "R450 WSG swimming pin audit",
      "comment" = "The swimming slice pins the proficiency gate (only proficient swimmers propel themselves; the nonproficient do not simply sink), the three sub-skills (endurance, speed, diving) with encumbrance as the key factor, Table 24 (the five encumbrance rows x the four functions, the multipliers from x2 down to the dash - only diving survives severe encumbrance, tripled), the endurance rules (the levels+con base in turns, the 3-turns-per-rest-turn rate, the doubled high-speed rate with the 1/10 endurance cut rounded up and the one-for-one high-speed recovery), and the speed rules (the 40/30 feet base rates, the 2/3 subsurface cut rounded up, the strength ladder +1/+2/+3, the light 1-3 and strong 4-6 current modifiers, the 0-inch hold position, the mercy-of-the-current drift at 1-3 inches, and the surface-only high speed halved at a 0 rate) (rules/wsg/wsgswim.h, prefix wsm); census 374 -> 375.",
    },
}
