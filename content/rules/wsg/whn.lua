-- whn: promoted from tools/spec_r464.json (the R464: the WSG HUNTING AND STALKING slice - hunting (the four-turn check, the -5% per party member beyond the first, the -10% midday shift, the missile-weapon requirement, the 1d10 hit procedure), stalking a wounded animal (the enraged size L charge and the panicked size M flight) and Table 31 (the 33-row terrain-by-season hunting success grid), printed pp. 55-56.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 464,
  "prefix" = "whn",
  "banner" = {
      "title" = "R464: the WSG HUNTING AND STALKING slice - hunting (the four-turn check, the -5% per party member beyond the first, the -10% midday shift, the missile-weapon requirement, the 1d10 hit procedure), stalking a wounded animal (the enraged size L charge and the panicked size M flight) and Table 31 (the 33-row terrain-by-season hunting success grid), printed pp. 55-56.",
      "provenance" = "Ground truth three-way: the archive djvu word layer vs the pixel reads of the leaf 0055 spread (the full native 2444x3176 decode) vs vision reads of upscaled cell sheets. The two text layers garble four Table 31 cells; the pixels settled them (temperate mountains winter 25, not 15; arctic desert spring 5, not 30; tropical mountains summer and autumn 40, not 10). The game-encounter list row 6 is pixel-confirmed as size L, 1d3 creatures at 60-80 yards - the djvu 50-60 is a garble. NOTED BOOK DISCREPANCY: the p. 56 example prints a 35% chance for three hunters in a tropical forest, but Table 31 prints 50 and the party rule takes it to 40; the rule is pinned as printed and only the internally consistent examples are pinned.",
      "sentinel" = "All 132 grid cells and all 30 encounter list cells pinned; the hunting mechanics (the four-turn check, the party and midday modifiers, the 1d10 hit procedure, the charge and flight rules) are audit examples.",
    },
  "consts" = { {
      "name" = "whnRowCount",
      "value" = 33,
      "comment" = "the Table 31 terrain row count: 5 arctic rows, 7 rows in each of the other four climate regions",
    }, {
      "name" = "whnEncRowCount",
      "value" = 6,
      "comment" = "the game-encounter list row count: the 1d6 dispatch",
    }, {
      "name" = "whnCheckTurns",
      "value" = 4,
      "comment" = "a hunting check covers four turns of hunting",
    }, {
      "name" = "whnPartyPenaltyPct",
      "value" = 5,
      "comment" = "each party member beyond the first lowers the encounter chance by 5%, cumulative",
    }, {
      "name" = "whnMiddayPenaltyPct",
      "value" = 10,
      "comment" = "from mid-morning to mid-evening the encounter chance drops by 10% (the table assumes early morning or late evening)",
    }, {
      "name" = "whnMissileMinAvgDamage",
      "value" = 3,
      "comment" = "a hunting missile weapon must average at least 3 hp of damage against size L (a bow qualifies; a thrown dagger or club does not)",
    }, {
      "name" = "whnHitDieSize",
      "value" = 10,
      "comment" = "the DM rolls 1d10 repeatedly; a result greater than the creature-count roll is a hit",
    }, {
      "name" = "whnRetryTurns",
      "value" = 4,
      "comment" = "when the encounter is negated because no missile weapon reaches the range, the group may hunt again after 4 more turns",
    }, {
      "name" = "whnStalkRangeFeet",
      "value" = 20,
      "comment" = "a wounded animal is finished off by a missile fired from 20 feet or less, or hand-to-hand",
    }, {
      "name" = "whnWoundedLChargePct",
      "value" = 50,
      "comment" = "a wounded size L animal charges: 50% chance it inflicts damage before any retaliation",
    }, {
      "name" = "whnWoundedLChargeDie",
      "value" = 8,
      "comment" = "the enraged size L charge inflicts 1d8 damage",
    }, {
      "name" = "whnWoundedAC",
      "value" = 5,
      "comment" = "to hit a wounded animal in the stalk, strike against AC 5",
    }, {
      "name" = "whnWoundedMFleeRate",
      "value" = 18,
      "comment" = "a panicked wounded size M animal flees at 18 inches per round",
    }, {
      "name" = "whnWoundedMKillRangeFeet",
      "value" = 20,
      "comment" = "a fleeing wounded size M animal is killed if a character gets within 20 feet and hits against AC 5",
    } },
  "bools" = { {
      "name" = "whnNightNeedsVision",
      "value" = true,
      "comment" = "hunting at night is impossible without infravision or ultravision (with them, use the table as given)",
    }, {
      "name" = "whnMeleeFinishOnly",
      "value" = true,
      "comment" = "a melee weapon may be used only to finish off a wounded kill, never for the hunting shot",
    }, {
      "name" = "whnHitsOneAnimalAtATime",
      "value" = true,
      "comment" = "hits are applied one animal at a time until it is dead or wounded",
    }, {
      "name" = "whnWoundedLChargesClosest",
      "value" = true,
      "comment" = "the enraged wounded size L animal charges one character - the closest, or a random one if two are equidistant",
    }, {
      "name" = "whnWoundedMEscapesOnFirstMiss",
      "value" = true,
      "comment" = "a fleeing wounded size M animal escapes if no character hits on the first available opportunity round",
    } },
  "switches" = { {
      "name" = "whnHitsToKill",
      "values" = { 1, 2, 4 },
      "comment" = "hits to kill by size band: one for size S, two for size M, four for size L",
    } },
  "tables" = { {
      "name" = "whnHuntSuccess",
      "tag" = "31A",
      "count" = "whnRowCount",
      "cols" = { "whnWin", "whnSpr", "whnSum", "whnAut" },
      "col_default" = 0,
      "col_comments" = { "the Table 31 winter column", "the Table 31 spring column", "the Table 31 summer column", "the Table 31 autumn column" },
      "row_comments" = { "the arctic desert row", "the arctic hills row", "the arctic mountains row", "the arctic plains row", "the arctic scrublands row", "the subarctic desert row", "the subarctic forest row", "the subarctic hills row", "the subarctic mountains row", "the subarctic plains row", "the subarctic scrublands row", "the subarctic swamp row", "the temperate desert row", "the temperate forest row", "the temperate hills row", "the temperate mountains row", "the temperate plains row", "the temperate scrublands row", "the temperate swamp row", "the subtropical desert row", "the subtropical forest row", "the subtropical hills row", "the subtropical mountains row", "the subtropical plains row", "the subtropical scrublands row", "the subtropical swamp row", "the tropical desert row", "the tropical forest row", "the tropical hills row", "the tropical mountains row", "the tropical plains row", "the tropical scrublands row", "the tropical swamp row" },
      "data" = { { 5, 5, 10, 5 }, { 5, 5, 10, 10 }, { 5, 5, 5, 5 }, { 5, 10, 10, 5 }, { 5, 10, 10, 5 }, { 5, 10, 10, 5 }, { 5, 10, 10, 5 }, { 5, 10, 15, 15 }, { 5, 5, 10, 5 }, { 5, 10, 15, 15 }, { 5, 15, 20, 20 }, { 5, 10, 15, 10 }, { 10, 5, 5, 10 }, { 30, 50, 50, 50 }, { 25, 40, 40, 40 }, { 25, 30, 30, 30 }, { 25, 40, 50, 50 }, { 20, 40, 50, 50 }, { 20, 35, 50, 50 }, { 10, 5, 5, 5 }, { 50, 50, 50, 50 }, { 50, 50, 50, 50 }, { 35, 35, 35, 35 }, { 50, 50, 50, 50 }, { 50, 50, 50, 50 }, { 40, 50, 50, 50 }, { 5, 5, 5, 5 }, { 50, 50, 50, 50 }, { 50, 50, 50, 50 }, { 40, 40, 40, 40 }, { 50, 50, 50, 50 }, { 50, 50, 50, 50 }, { 50, 50, 50, 50 } },
      "audit_comment" = "the Table 31 hunting success grid (the percent chance per terrain per season)",
    }, {
      "name" = "whnEncounter",
      "tag" = "31B",
      "count" = "whnEncRowCount",
      "cols" = { "whnEncSize", "whnEncDice", "whnEncDie", "whnEncRangeMin", "whnEncRangeMax" },
      "col_default" = 0,
      "col_comments" = { "the encounter size band: 0 = S, 1 = M, 2 = L", "the creature-count dice", "the creature-count die size", "the minimum encounter range in yards", "the maximum encounter range in yards" },
      "row_comments" = { "roll 1: size S, 2d6 creatures", "roll 2: size S, 1d6 creatures", "roll 3: size M, 1d10 creatures", "roll 4: size M, 1d6 creatures", "roll 5: size M, 1d3 creatures", "roll 6: size L, 1d3 creatures" },
      "data" = { { 0, 2, 6, 20, 40 }, { 0, 1, 6, 20, 40 }, { 1, 1, 10, 20, 40 }, { 1, 1, 6, 40, 60 }, { 1, 1, 3, 40, 60 }, { 2, 1, 3, 60, 80 } },
      "audit_comment" = "the 1d6 game-encounter list (the size band, the creature dice and the yardage range)",
    } },
  "chains" = { {
      "name" = "whnWoundedMFleeBand",
      "arg" = "r",
      "limits" = { 1, 3 },
      "tail" = 2,
      "comment" = "the panicked size M flight direction on 1d4: 1 toward the hunters band 0, 2-3 perpendicular band 1, 4 directly away band 2",
    } },
  "examples" = { {
      "note" = "the solitary temperate forest hunter: 30% winter, 50% in the other seasons",
      "expr" = "m['whnWin'](13) != 30 or m['whnSpr'](13) != 50 or m['whnSum'](13) != 50 or m['whnAut'](13) != 50",
    }, {
      "note" = "two hunters in a tropical forest: 50% less the one-member penalty = 45%",
      "expr" = "m['whnSpr'](28) - m['whnPartyPenaltyPct']() != 45",
    }, {
      "note" = "the three-hunter party: 50% less two cumulative member penalties = 40%",
      "expr" = "m['whnSpr'](28) - 2 * m['whnPartyPenaltyPct']() != 40",
    }, {
      "note" = "hunting from mid-morning to mid-evening: 50% less the 10% midday shift = 40%",
      "expr" = "m['whnSpr'](28) - m['whnMiddayPenaltyPct']() != 40",
    }, {
      "note" = "the arctic desert winter: a 5% chance",
      "expr" = "m['whnWin'](0) != 5",
    }, {
      "note" = "the subarctic swamp autumn: a 10% chance",
      "expr" = "m['whnAut'](11) != 10",
    }, {
      "note" = "the 1d10 procedure: a roll of 4 beats a creature count of 3, a roll of 2 does not",
      "expr" = "m['whnHitDieSize']() != 10 or 4 <= 3 or 2 > 3",
    }, {
      "note" = "a roll of 6 on the encounter list: size L, 1d3 creatures at 60-80 yards (the pixel-confirmed cell)",
      "expr" = "m['whnEncSize'](5) != 2 or m['whnEncDice'](5) != 1 or m['whnEncDie'](5) != 3 or m['whnEncRangeMin'](5) != 60 or m['whnEncRangeMax'](5) != 80",
    }, {
      "note" = "the book own roll-5 example: size M, 1d3 creatures at 40-60 yards",
      "expr" = "m['whnEncSize'](4) != 1 or m['whnEncDice'](4) != 1 or m['whnEncDie'](4) != 3 or m['whnEncRangeMin'](4) != 40 or m['whnEncRangeMax'](4) != 60",
    }, {
      "note" = "hits to kill: one for size S, two for size M, four for size L",
      "expr" = "m['whnHitsToKill'](0) != 1 or m['whnHitsToKill'](1) != 2 or m['whnHitsToKill'](2) != 4",
    }, {
      "note" = "the panicked flight directions: 1 toward, 2 and 3 perpendicular, 4 away",
      "expr" = "m['whnWoundedMFleeBand'](1) != 0 or m['whnWoundedMFleeBand'](2) != 1 or m['whnWoundedMFleeBand'](3) != 1 or m['whnWoundedMFleeBand'](4) != 2",
    }, {
      "note" = "the enraged charge: a 50% chance of 1d8 damage before retaliation, the stalk to hit against AC 5",
      "expr" = "m['whnWoundedLChargePct']() != 50 or m['whnWoundedLChargeDie']() != 8 or m['whnWoundedAC']() != 5",
    } },
  "audit" = {
      "label" = "R464 WSG hunting pin audit",
      "comment" = "The Table 31 grid cell by cell (33 terrain rows across the five climate regions, the percent per season), the 1d6 game-encounter list (the size band, the creature dice and the yardage range), the four-turn hunting check with the party and midday modifiers, the 1d10 hit procedure and the wounded-animal stalking rules - every cell, const, bool, switch and chain limit verified against the model.",
    },
}
