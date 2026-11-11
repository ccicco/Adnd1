-- dny: promoted from tools/spec_r513.json (the The DSG DPV AND HYPOTHERMIA, R513: the printed pp. 40-42 (pdf 41-43) - the defensive point values section (the DMG page-110 fortification seam, the natural and constructed formations assigned DPVs, the destroy-on-attack-or-spell use, the cubic-open-space reading where the value is the damage needed to collapse the ceiling, the chain-reaction follow-up check after a collapse, and the Table 19 thirteen-formation grid - room 10-ft tube 50, room 20-ft cube 90, column 3-ft 10, column 10-ft 100, wall 10-ft square 20, bridge small wooden 12, bridge small stone 40, bridge large stone 80, rock ledge per 1-ft 10, ceiling small cavern 100, ceiling large cavern 250, stalactite small 8, stalactite large 20) and the hypothermia optional rule (the damp-chill preamble, the one-turn swimming onset with the no-heat-source assumption, the shallow-water risk reduction - knee-to-waist deep one hour, shallower than knee no threat - the Constitution Check after onset with 1d6 lost on a failure repeated every turn, the losses accumulating until an external heat source and even after leaving the water, the 1d6-per-turn recovery by a fire or warm-blooded creatures until fully recovered, the cold-adapted and ring-of-warmth immunity, and the grease or oil coating doubling both the time before the first check and the interval between checks));
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 513,
  "prefix" = "dny",
  "banner" = {
      "title" = "The DSG DPV AND HYPOTHERMIA, R513: the printed pp. 40-42 (pdf 41-43) - the defensive point values section (the DMG page-110 fortification seam, the natural and constructed formations assigned DPVs, the destroy-on-attack-or-spell use, the cubic-open-space reading where the value is the damage needed to collapse the ceiling, the chain-reaction follow-up check after a collapse, and the Table 19 thirteen-formation grid - room 10-ft tube 50, room 20-ft cube 90, column 3-ft 10, column 10-ft 100, wall 10-ft square 20, bridge small wooden 12, bridge small stone 40, bridge large stone 80, rock ledge per 1-ft 10, ceiling small cavern 100, ceiling large cavern 250, stalactite small 8, stalactite large 20) and the hypothermia optional rule (the damp-chill preamble, the one-turn swimming onset with the no-heat-source assumption, the shallow-water risk reduction - knee-to-waist deep one hour, shallower than knee no threat - the Constitution Check after onset with 1d6 lost on a failure repeated every turn, the losses accumulating until an external heat source and even after leaving the water, the 1d6-per-turn recovery by a fire or warm-blooded creatures until fully recovered, the cold-adapted and ring-of-warmth immunity, and the grease or oil coating doubling both the time before the first check and the interval between checks)",
      "provenance" = "the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf = printed + 1; the text read from the IA djvu OCR with the pdf Acrobat-Capture layer as the second read (idx 54 = printed p. 41, idx 55-57 = printed p. 42) - the Table 19 grid confirmed THREE WAYS: the chapter djvu read and the compiled-tables appendix reprint (djvu.txt line 15570ff) agree on all thirteen rows, with the Capture layer partially corroborating (Room 10- 50, Column 3 10, Column 10^4 diameter 100, Wall 10-fl square 20, Bridge small wooden 12, Ceiling large cavern 250; the Capture garble 104 = 10-ft and the appendix drop of the word Stalactite on the small 8 row are both settled by the chapter read). The hypothermia numbers dual-confirmed by Capture idx 56-57: the Constitution Check, the 1d6 loss per failed check, the per-turn repetition, the 1d6-per-turn recovery, the fire/warm-blooded-creature source, the ring-of-warmth immunity and the grease doubling. The Magnetic Effects of Lodestone section starts the NEXT round per the content-density rule.",
      "sentinel" = "Table 19 pins as a 13x2 grid: the row key and the Defensive Point Value, each the damage needed to destroy the formation (or, for a cubic open space, to collapse its ceiling). The hypothermia dice pin as dice + sides consts (loss 1d6, recovery 1d6) per the R508 convention. The DMG page-110 seam and the wsgheat.h cross-book seam are noted but nothing auto-credits; the R512 chain reaction procedure is the collapse follow-up.",
    },
  "consts" = { {
      "name" = "dnyT19RowCount",
      "value" = 13,
      "comment" = "the Table 19 carries thirteen formations: two rooms, two columns, a wall, three bridges, a rock ledge, two cavern ceilings and two stalactites.",
    }, {
      "name" = "dnySwimTurnsToOnset",
      "value" = 1,
      "comment" = "a character becomes subject to hypothermia - a disastrous lowering of body temperature - after one turn of swimming in a typical underground body of water.",
    }, {
      "name" = "dnyWadingOnsetHours",
      "value" = 1,
      "comment" = "the knee-to-waist-deep wading onset delay: one hour.",
    }, {
      "name" = "dnyLossPerFailDice",
      "value" = 1,
      "comment" = "if the Constitution Check fails, the character loses hit points on 1d6 - the dice count.",
    }, {
      "name" = "dnyLossPerFailSides",
      "value" = 6,
      "comment" = "the hypothermia loss die: d6.",
    }, {
      "name" = "dnyCheckEveryTurns",
      "value" = 1,
      "comment" = "the Constitution Check must be repeated every turn, with all hit point losses accumulating.",
    }, {
      "name" = "dnyRecoveryPerTurnDice",
      "value" = 1,
      "comment" = "near a heat source the character regains hit points at 1d6 per turn - the dice count.",
    }, {
      "name" = "dnyRecoveryPerTurnSides",
      "value" = 6,
      "comment" = "the hypothermia recovery die: d6.",
    }, {
      "name" = "dnyGreaseTimeMult",
      "value" = 2,
      "comment" = "the grease or oil coating multiplier on the time before the first Constitution Check and on the interval between checks.",
    } },
  "bools" = { {
      "name" = "dnyFortificationsHaveDpv",
      "value" = true,
      "comment" = "constructed fortifications have Defensive Point Values, as explained in the DMG (page 110), and many natural and constructed underground formations are assigned DPVs too - the cross-book seam.",
    }, {
      "name" = "dnyDpvDestroysOnAttackOrSpell",
      "value" = true,
      "comment" = "use these Defensive Point Values to determine if an area is destroyed by the effects of an attack or spell.",
    }, {
      "name" = "dnyCubicOpenSpaceCeiling",
      "value" = true,
      "comment" = "when a Defensive Point Value is provided for a cubic open space, the value equals the amount of damage needed to cause the area's ceiling to collapse.",
    }, {
      "name" = "dnyCollapseChecksChainReaction",
      "value" = true,
      "comment" = "after a DPV collapse, check for additional ceiling or wall collapses with the normal chain reaction procedure - the R512 rules/dsg/dsgcavein2.h seam.",
    }, {
      "name" = "dnyDampChillUnhealthy",
      "value" = true,
      "comment" = "the damp chill of the underworld air is decidedly unhealthy for most creatures; the streams, rivers and lakes of the Underdark can numb a character who suffers prolonged exposure to their bone-chilling cold waters.",
    }, {
      "name" = "dnyNoHeatSourceAssumed",
      "value" = true,
      "comment" = "the one-turn swimming onset assumes no subterranean heat source is warming the water.",
    }, {
      "name" = "dnyShallowWaterReducesRisk",
      "value" = true,
      "comment" = "the risks of hypothermia are reduced in shallow water.",
    }, {
      "name" = "dnyKneeToWaistOneHour",
      "value" = true,
      "comment" = "if a character is moving through water between knee and waist deep, hypothermia effects do not begin for one hour.",
    }, {
      "name" = "dnyShallowerThanKneeNoThreat",
      "value" = true,
      "comment" = "if the water is shallower than knee deep, hypothermia is not a threat.",
    }, {
      "name" = "dnyConCheckOnOnset",
      "value" = true,
      "comment" = "after hypothermia sets in, the player must make a Constitution Check.",
    }, {
      "name" = "dnyLossesAccumulateUntilHeat",
      "value" = true,
      "comment" = "all hit point losses accumulate until the character reaches some external heat source that can warm his chilled body.",
    }, {
      "name" = "dnyLossContinuesOutOfWater",
      "value" = true,
      "comment" = "hit point loss continues even after the character has gotten out of the water, if no heat source is found.",
    }, {
      "name" = "dnyFireOrWarmCreaturesRecover",
      "value" = true,
      "comment" = "if a means of warming up - such as a fire or the close presence of other warm-blooded creatures - is located, the character recovers.",
    }, {
      "name" = "dnyRecoveryUntilFullyRecovered",
      "value" = true,
      "comment" = "the 1d6-per-turn recovery continues until the hypothermia losses have been fully recovered.",
    }, {
      "name" = "dnyColdAdaptedOrRingImmune",
      "value" = true,
      "comment" = "creatures especially adapted for cold environments, or carrying magical protections such as a ring of warmth, are not susceptible to the effects of this rule.",
    }, {
      "name" = "dnyGreaseDoublesInterval",
      "value" = true,
      "comment" = "a character who thoroughly coats himself with a layer of grease or oil before entering the water can double the amount of time before making a Constitution Check, and double the interval between checks as well.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "Table 19: UNDERGROUND STRUCTURE DEFENSIVE POINT VALUE",
      "tag" = "19",
      "count" = "dnyT19RowCount",
      "sentinel" = -99,
      "col_default" = -99,
      "cols" = { "dnyT19Key", "dnyT19Dpv" },
      "col_comments" = { "the row key: 0 room 10-ft tube, 1 room 20-ft cube, 2 column 3-ft diameter, 3 column 10-ft diameter, 4 wall 10-ft square, 5 bridge small wooden, 6 bridge small stone, 7 bridge large stone, 8 rock ledge per 1-ft wide, 9 ceiling small cavern, 10 ceiling large cavern, 11 stalactite small, 12 stalactite large.", "the Defensive Point Value of the formation: the damage needed to destroy it (or, for a cubic open space, to collapse its ceiling)." },
      "audit_comment" = "the Table 19 underground structure DPV grid",
      "data" = { { 0, 50 }, { 1, 90 }, { 2, 10 }, { 3, 100 }, { 4, 20 }, { 5, 12 }, { 6, 40 }, { 7, 80 }, { 8, 10 }, { 9, 100 }, { 10, 250 }, { 11, 8 }, { 12, 20 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dnyT19Key'](0) != 0 or m['dnyT19Dpv'](0) != 50 or m['dnyT19Key'](1) != 1 or m['dnyT19Dpv'](1) != 90 or m['dnyT19Key'](2) != 2 or m['dnyT19Dpv'](2) != 10 or m['dnyT19Key'](3) != 3 or m['dnyT19Dpv'](3) != 100",
      "note" = "the Table 19 rooms and columns: the 10-ft tube 50, the 20-ft cube 90, the 3-ft column 10 and the 10-ft column 100 (the Capture garble 104 = 10-ft, settled by the chapter and appendix reads).",
    }, {
      "expr" = "m['dnyT19Key'](4) != 4 or m['dnyT19Dpv'](4) != 20 or m['dnyT19Key'](5) != 5 or m['dnyT19Dpv'](5) != 12 or m['dnyT19Key'](6) != 6 or m['dnyT19Dpv'](6) != 40 or m['dnyT19Key'](7) != 7 or m['dnyT19Dpv'](7) != 80",
      "note" = "the Table 19 wall and bridges: the 10-ft square wall 20, the small wooden bridge 12, the small stone bridge 40 and the large stone bridge 80.",
    }, {
      "expr" = "m['dnyT19Key'](8) != 8 or m['dnyT19Dpv'](8) != 10 or m['dnyT19Key'](9) != 9 or m['dnyT19Dpv'](9) != 100 or m['dnyT19Key'](10) != 10 or m['dnyT19Dpv'](10) != 250 or m['dnyT19Key'](11) != 11 or m['dnyT19Dpv'](11) != 8 or m['dnyT19Key'](12) != 12 or m['dnyT19Dpv'](12) != 20",
      "note" = "the Table 19 ledges, ceilings and stalactites: the per-1-ft rock ledge 10, the small-cavern ceiling 100, the large-cavern ceiling 250, the small stalactite 8 and the large stalactite 20.",
    }, {
      "expr" = "m['dnyFortificationsHaveDpv']() != 1 or m['dnyDpvDestroysOnAttackOrSpell']() != 1 or m['dnyCubicOpenSpaceCeiling']() != 1 or m['dnyCollapseChecksChainReaction']() != 1",
      "note" = "the DPV section: the DMG page-110 fortification seam, the destroy-on-attack-or-spell use, the cubic-open-space ceiling-collapse reading, and the chain reaction follow-up check.",
    }, {
      "expr" = "m['dnySwimTurnsToOnset']() != 1 or m['dnyNoHeatSourceAssumed']() != 1 or m['dnyDampChillUnhealthy']() != 1",
      "note" = "the hypothermia onset: one turn of swimming in typical underground water, assuming no subterranean heat source warming it.",
    }, {
      "expr" = "m['dnyKneeToWaistOneHour']() != 1 or m['dnyWadingOnsetHours']() != 1 or m['dnyShallowerThanKneeNoThreat']() != 1 or m['dnyShallowWaterReducesRisk']() != 1",
      "note" = "the shallow-water risk reduction: knee-to-waist deep delays onset to one hour, and shallower than knee deep is no threat at all.",
    }, {
      "expr" = "m['dnyConCheckOnOnset']() != 1 or m['dnyLossPerFailDice']() != 1 or m['dnyLossPerFailSides']() != 6 or m['dnyCheckEveryTurns']() != 1 or m['dnyLossesAccumulateUntilHeat']() != 1 or m['dnyLossContinuesOutOfWater']() != 1",
      "note" = "the hypothermia check cycle: a Constitution Check after onset, 1d6 lost on a failure, repeated every turn with losses accumulating until an external heat source is reached - even out of the water.",
    }, {
      "expr" = "m['dnyFireOrWarmCreaturesRecover']() != 1 or m['dnyRecoveryPerTurnDice']() != 1 or m['dnyRecoveryPerTurnSides']() != 6 or m['dnyRecoveryUntilFullyRecovered']() != 1",
      "note" = "the recovery: a fire or the close presence of warm-blooded creatures restores 1d6 hit points per turn until the losses are fully recovered.",
    }, {
      "expr" = "m['dnyColdAdaptedOrRingImmune']() != 1",
      "note" = "the immunity: cold-adapted creatures and a ring of warmth are not susceptible.",
    }, {
      "expr" = "m['dnyGreaseTimeMult']() != 2 or m['dnyGreaseDoublesInterval']() != 1",
      "note" = "the grease or oil coating: doubles both the time before the first Constitution Check and the interval between checks.",
    } },
  "audit" = {
      "label" = "R513 DSG DPV and hypothermia audit",
      "comment" = "The DSG DPV pins the defensive point values section (the constructed fortifications with DPVs per the DMG page 110, the natural and constructed formations assigned values, the use to determine if an area is destroyed by an attack or spell, the cubic open space where the value is the damage needed to collapse the ceiling, and the follow-up chain reaction check per the R512 procedure after a collapse) and the Table 19 grid (the 10-ft tube room 50, the 20-ft cube room 90, the 3-ft column 10, the 10-ft column 100, the 10-ft square wall 20, the small wooden bridge 12, the small stone bridge 40, the large stone bridge 80, the per-1-ft rock ledge 10, the small-cavern ceiling 100, the large-cavern ceiling 250, the small stalactite 8 and the large stalactite 20). The hypothermia pins the damp-chill preamble with the one-turn swimming onset assuming no subterranean heat source, the shallow-water reduction (knee-to-waist deep one hour, shallower than knee no threat), the Constitution Check after onset with 1d6 lost on a failure and repeated every turn, the losses accumulating until an external heat source is reached and continuing even out of the water, the 1d6-per-turn recovery by a fire or the close presence of warm-blooded creatures until fully recovered, the cold-adapted and ring-of-warmth immunity, and the grease or oil coating doubling both the pre-check time and the check interval.",
    },
}
