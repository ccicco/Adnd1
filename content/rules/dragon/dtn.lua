-- dtn: promoted from tools/spec_r914.json (the The Dragon issue-10 opener, part one - the Orgies Inc. article (folios 5-6), the Clifton wilderness article (folio 7) and the Random Monsters article (folios 9-10): three adjudicated chains in one round, the issue-10 part-two chains to follow);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 914,
  "prefix" = "dtn",
  "banner" = {
      "title" = "The Dragon issue-10 opener, part one - the Orgies Inc. article (folios 5-6), the Clifton wilderness article (folio 7) and the Random Monsters article (folios 9-10): three adjudicated chains in one round, the issue-10 part-two chains to follow",
      "provenance" = "Pinned from The Dragon Vol. 2 No. 4 (October 1977), the archive.org scan voice (single-voice: no chat-side upload cross-check exists for issue 10; the source lives in the archive.org item accessory-dragon-magazine-012). The folios: 5-6, the Pickens D&D Option: ORGIES, INC. article - experience only as treasure is spent, the GP expenditure divided by level capped at the class hit-dice allowance, the divisor riding treasure experience only, the sacrifice class with its weekly window, tithes and the 100-GP-per-level wish or favor option, the lawful-only philanthropy, the MU and alchemist research at 250 GP per level per day, the clan-hoard class with no withdrawals, the orgy class at 500 GP per level per night halved to 250 recuperating under 50% with the constitution-days cycle, the halved hireling experience, no experience for upkeep, salaries, equipment, luxuries or investments, the level-10 fief example at 3400 of 240,000, the specialist divisor of 10 for fiefholders, the 500-GP mill returning 100-600 annually per 100 people, the 60-40 house edge with the halved En Garde winnings, and the psionic appendix - 20 GP per psionic point, 100 GP per 10% cumulative ability-loss roll, an ability back per 100 psionic points regained; 7, the Clifton Designing For Unique Wilderness Encounters article - the four-foot-square battlefield, the river across the field at 10% with the ford at a further 10%, the swimmer forcing the river onto the field, the road bridge or ford, the initial run in four directions with the clockwise, straight and counterclockwise courses, the slope facing toward or away from the high ground, the 75% slope turn at a watercourse, the clear, rough, mountainous, wooded and marshy feature bands with their grades - gentle at one level, steep at three - and their roll-again tables, the doubled surprise and 20-120 foot sighting in dense woods, the 20-100 yard sighting in light woods, the halved surprise at maximum sighting in clear featureless corners, the opposite-corner placement and the proportionate thinning of slopes and streams at larger areas; 9-10, the Crabaugh Random Monsters article - the 20-level dungeon basis, the d8 type band across mammal, reptile and undead, the intelligence band, the hit-dice modifier bands from +2 to -1, the hit-dice AC table for mammal and reptile, the level-offset column from +3 at die 1 to -2 at die 12 with the dungeon-level meaning, the undead turning as undead of level HD/2 with the vampire threshold at 17 and the (1-8)+1 undead AC, and the weapon-or-bite damage doctrine by intelligence. The transcripts ride extract/dragon/010/ (all 34 issue pages); the issue-10 gap report ships pre-flip with its two part boxes. PRINT FOLIO = PDF PAGE, verified at the printed 10, 19 and 21 footers.",
      "sentinel" = "The variant-layer doctrine holds: Dragon ink is never core 1e canon, and the Orgies Inc. experience-as-spent option - though it echoes the later training-cost doctrine - pins as a variant layer with provenance, never core canon. The print quirks ride AS SCANNED, noted, never silent: the Random Monsters speed table garbled (the '47' band), the special-characteristics grid without its d% axis, the damage grid's '=' artifacts, the size table's missing small cells and the limbs and exterior tables all ride the transcript whole, never guessed; the hit-dice AC table's row-12 reptile cell garbled - the band pins, the cell rides sentinel; the Clifton '46-600' band reads 46-60 by the print's own band arithmetic and the displaced Clear tail rows sit by contiguity; the Snits game and the Stellar Conquest diplomacy article scoped out as other systems. The editor's standing caution rides: none of this is official.",
    },
  "consts" = { {
      "name" = "dtnOrgyMaxGpPerLevel",
      "value" = 500,
      "comment" = "the orgy expenditure maximum, 500 GP per level per night (folio 5)",
    }, {
      "name" = "dtnOrgyRecuperatingMaxGp",
      "value" = 250,
      "comment" = "the orgy maximum halved to 250 GP when recuperating and under 50% (folio 5)",
    }, {
      "name" = "dtnResearchGpPerLevelDay",
      "value" = 250,
      "comment" = "the research expenditure rate, up to 250 GP per level per day for the MU or alchemist in his chambers (folio 5)",
    }, {
      "name" = "dtnSacrificeFavorGpPerLevel",
      "value" = 100,
      "comment" = "the referee option - a sacrifice of at least 100 GP per level of the giver earns a wish or favor (folio 5)",
    }, {
      "name" = "dtnSpecialistFiefDivisor",
      "value" = 10,
      "comment" = "the fiefholder specialist cost reduced by a factor of 10, excepting assassins and spies (folio 6)",
    }, {
      "name" = "dtnFiefExampleXp",
      "value" = 3400,
      "comment" = "the fief income example - a level 10 lord with eight villages of 400 picks up 3400 experience points (folio 6)",
    }, {
      "name" = "dtnFiefExampleNeed",
      "value" = 240000,
      "comment" = "the fief income example total needed for the next level, 240,000 (folio 6)",
    }, {
      "name" = "dtnMillCostGp",
      "value" = 500,
      "comment" = "the fixed investment example - a water-powered mill costing 500 GP (folio 6)",
    }, {
      "name" = "dtnMillAnnualMinGp",
      "value" = 100,
      "comment" = "the mill returns 100-600 GP annually per 100 people within a day march (folio 6)",
    }, {
      "name" = "dtnMillAnnualMaxGp",
      "value" = 600,
      "comment" = "the mill annual return maximum (folio 6)",
    }, {
      "name" = "dtnMillPeoplePer",
      "value" = 100,
      "comment" = "the mill return denominator - per 100 people within a day march (folio 6)",
    }, {
      "name" = "dtnHouseMinEdgePct",
      "value" = 60,
      "comment" = "the gambling house rule - the odds at least 60-40 in favor of the House (folio 6)",
    }, {
      "name" = "dtnPsionicGpPerPoint",
      "value" = 20,
      "comment" = "the appendix II psionic rule - each 20 GP spent on an orgy reduces psionic point level by one (folio 6)",
    }, {
      "name" = "dtnPsionicGpPerAbilityRoll",
      "value" = 100,
      "comment" = "every 100 GP spent carries a 10% cumulative chance of eliminating one special ability (folio 6)",
    }, {
      "name" = "dtnPsionicAbilityLossPct",
      "value" = 10,
      "comment" = "the cumulative special-ability loss chance per 100 GP (folio 6)",
    }, {
      "name" = "dtnPsionicAbilityRegenPoints",
      "value" = 100,
      "comment" = "a special ability returns with each 100 psionic points regained, or all lost points regenerate, whichever is least (folio 6)",
    }, {
      "name" = "dtnRiverAcrossFieldPct",
      "value" = 10,
      "comment" = "a river flowing through the hex has a 10% chance to flow across the field (folio 7)",
    }, {
      "name" = "dtnRiverFordChancePct",
      "value" = 10,
      "comment" = "an additional 10% chance the river has a ford (folio 7)",
    }, {
      "name" = "dtnSlopeTurnsToWaterPct",
      "value" = 75,
      "comment" = "a slope crossing a river or stream has a 75% chance to turn, face the watercourse and run parallel off the field (folio 7)",
    }, {
      "name" = "dtnDenseWoodsSightingMinFt",
      "value" = 20,
      "comment" = "dense woods - normal sighting distance between 20 and 120 feet (folio 7)",
    }, {
      "name" = "dtnDenseWoodsSightingMaxFt",
      "value" = 120,
      "comment" = "the dense woods sighting maximum in feet (folio 7)",
    }, {
      "name" = "dtnLightWoodsSightingMinYds",
      "value" = 20,
      "comment" = "light woods - normal sighting distance between 20 and 100 yards (folio 7)",
    }, {
      "name" = "dtnLightWoodsSightingMaxYds",
      "value" = 100,
      "comment" = "the light woods sighting maximum in yards (folio 7)",
    }, {
      "name" = "dtnGentleGradeLevels",
      "value" = 1,
      "comment" = "the grade indicates height - a gentle slope is one level (folio 7)",
    }, {
      "name" = "dtnSteepGradeLevels",
      "value" = 3,
      "comment" = "a steep slope is three levels (folio 7)",
    }, {
      "name" = "dtnRiverRunDirections",
      "value" = 4,
      "comment" = "the initial run of rivers, streams and slopes - four courses, north-south, northeast-southwest, east-west, northwest-southeast (folio 7)",
    }, {
      "name" = "dtnRMDungeonLevels",
      "value" = 20,
      "comment" = "the tables geared to a 20-level dungeon, each level populated by monsters of the same level (folio 9)",
    }, {
      "name" = "dtnRMUndeadTurnDivisor",
      "value" = 2,
      "comment" = "undead are turned by clerics as if they were undead of level HD/2 - a 2HD undead saves as a zombie (folio 9)",
    }, {
      "name" = "dtnRMVampireAtLevel",
      "value" = 17,
      "comment" = "undead of level 17+ are treated as vampires (folio 9)",
    }, {
      "name" = "dtnRMUndeadACBonus",
      "value" = 1,
      "comment" = "the undead AC roll - (1-8) + 1 (folio 9)",
    }, {
      "name" = "dtnRMHDBands",
      "value" = 4,
      "comment" = "the hit-dice modifier bands - four d6 bands (folio 9)",
    }, {
      "name" = "dtnRMACBands",
      "value" = 6,
      "comment" = "the hit-dice AC bands - six d12 bands, the row-12 reptile cell garbled in the OCR and riding the transcript (folio 9)",
    }, {
      "name" = "dtnRMLevelBands",
      "value" = 6,
      "comment" = "the level-offset bands - six d12 bands from die 1 at +3 to die 12 at -2 (folio 9)",
    } },
  "bools" = { {
      "name" = "dtnLawfulGoodEquivalence",
      "value" = true,
      "comment" = "the author's frame - in this article Lawful equals Good and Chaotic equals Evil (folio 5)",
    }, {
      "name" = "dtnXpOnlyAsSpent",
      "value" = true,
      "comment" = "the core option - players receive experience only as the treasure is spent, not as it is gained (folio 5)",
    }, {
      "name" = "dtnXpDivisorIsLevelCappedAtHD",
      "value" = true,
      "comment" = "the expenditure in GP is divided by the level of the character, the divisor limited to the hit dice allowed for the class (folio 5)",
    }, {
      "name" = "dtnDivisorTreasureXpOnly",
      "value" = true,
      "comment" = "the divisor is used only for treasure experience - monster kills and miscellaneous awards are untouched (folio 5)",
    }, {
      "name" = "dtnSacrificeWeeklyWindow",
      "value" = true,
      "comment" = "the sacrifice offering may be made once per week and within one week of acquisition, tithes counting; payment or bribe never counts (folio 5)",
    }, {
      "name" = "dtnPhilanthropyLawfulOnly",
      "value" = true,
      "comment" = "the philanthropy class - lawfuls only, aid to the poor or any NPC not a hireling, a real need required, or the local lawful church (folio 5)",
    }, {
      "name" = "dtnResearchMuAlchemistOnly",
      "value" = true,
      "comment" = "the research class - magic users and alchemists only, spell research counting, production not, never simultaneous (folio 5)",
    }, {
      "name" = "dtnClanHoardsClannishOnly",
      "value" = true,
      "comment" = "the clan-hoard class - dwarves and clannish folk, members only, no withdrawals ever (folio 5)",
    }, {
      "name" = "dtnOrgyClassesOnly",
      "value" = true,
      "comment" = "the orgy class - fighting men excluding rangers and paladins, bards, thieves and all chaotics excluding monks (folio 5)",
    }, {
      "name" = "dtnOrgyConstitutionDays",
      "value" = true,
      "comment" = "a player may orgy as many days as he has constitution points, then must rest as many days as he orgied (folio 5)",
    }, {
      "name" = "dtnHirelingXpHalved",
      "value" = true,
      "comment" = "hirelings may buy experience with their pay, halved for non-player characters (folio 5)",
    }, {
      "name" = "dtnNoXpForUpkeep",
      "value" = true,
      "comment" = "general maintenance, upkeep, advertisement, salaries, equipment, luxuries and investments yield no experience, investment income may (folio 5)",
    }, {
      "name" = "dtnFourFootSquareEncounter",
      "value" = true,
      "comment" = "the encounter field - a four foot square area with terrain determined to each corner section of four square feet (folio 7)",
    }, {
      "name" = "dtnSwimmerForcesRiver",
      "value" = true,
      "comment" = "if an encounter with a swimmer is indicated the river is always on the field (folio 7)",
    }, {
      "name" = "dtnRoadBridgesRiver",
      "value" = true,
      "comment" = "a party travelling on a road finds an appropriate bridge or ford at the river (folio 7)",
    }, {
      "name" = "dtnDenseWoodsDoubleSurprise",
      "value" = true,
      "comment" = "if either side is located in dense woods, chances of surprise are doubled (folio 7)",
    }, {
      "name" = "dtnClearHalveSurprise",
      "value" = true,
      "comment" = "if both are in featureless areas with clear lines of sight, chances of surprise are halved and sighting distance is always maximum (folio 7)",
    }, {
      "name" = "dtnOppositeCorners",
      "value" = true,
      "comment" = "monsters and party are placed in opposite corner sections (folio 7)",
    }, {
      "name" = "dtnLargerAreaFewerFeatures",
      "value" = true,
      "comment" = "mapping larger areas decreases the possibility of slopes and streams in proportion to the increase in area (folio 7)",
    }, {
      "name" = "dtnRMIntelligentWeaponDamage",
      "value" = true,
      "comment" = "intelligent monsters do damage by weapon type, unintelligent by bite, semi-intelligent 50% chance of each (folio 10)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "dtnRMHDModifier",
      "tag" = "Rh",
      "count" = "dtnRMHDBands",
      "sentinel" = -1,
      "cols" = { "dtnRMHDMod" },
      "col_comments" = { "the hit-dice modifier per d6 band - 1 at +2, 2-3 at +1, 4-5 at 0, 6 at -1 (folio 9)" },
      "data" = { { 2 }, { 1 }, { 0 }, { -1 } },
      "audit_comment" = "the Ward hit-dice modifier bands, four d6 bands from +2 to -1 (folio 9)",
    }, {
      "name" = "dtnRMAC",
      "tag" = "Ra",
      "count" = "dtnRMACBands",
      "sentinel" = -1,
      "sentinel_census" = { 0, 1 },
      "cols" = { "dtnRMACMammal", "dtnRMACReptile" },
      "col_comments" = { "the mammal AC per hit-dice d12 band - die 1 at AC 3 through die 12 at AC 8 (folio 9)", "the reptile AC per band - die 1 at AC 2 through die 10-11 at AC 6, the die-12 cell garbled in the OCR and riding the transcript (folio 9)" },
      "data" = { { 3, 2 }, { 4, 3 }, { 5, 4 }, { 6, 5 }, { 7, 6 }, { 8, -1 } },
      "audit_comment" = "the Crabaugh hit-dice AC table - six d12 bands, mammal AC 3 to 8, reptile AC 2 to 6 with the row-12 reptile cell garbled, sentinel -1 (folio 9)",
    }, {
      "name" = "dtnRMLevelOffset",
      "tag" = "Rl",
      "count" = "dtnRMLevelBands",
      "sentinel" = -1,
      "cols" = { "dtnRMLevelOffset" },
      "col_comments" = { "the level offset per hit-dice d12 band - die 1 at level +3, 2-3 at +2, 4-5 at +1, 6-9 at level, 10-11 at -1, 12 at -2, level meaning the dungeon level on this table only, non-positive results treated per the print (folio 9)" },
      "data" = { { 3 }, { 2 }, { 1 }, { 0 }, { -1 }, { -2 } },
      "audit_comment" = "the level-offset column - six d12 bands from +3 at die 1 to -2 at die 12 (folio 9)",
    } },
  "chains" = { {
      "name" = "dtnClearFeature",
      "limits" = { 70, 77, 82, 84, 88, 93, 97 },
      "tail" = 7,
      "comment" = "the clear terrain feature bands - featureless, hill, rough ground, marsh, slope, light woods, stream, pond (folio 7)",
    }, {
      "name" = "dtnRoughFeature",
      "limits" = { 25, 45, 60, 70, 77, 85, 89, 91, 95 },
      "tail" = 9,
      "comment" = "the rough terrain feature bands - featureless, hill, rough ground, slope, dense brush, light woods, dense woods, marsh, stream, pond, the 46-600 OCR band reading 46-60 by the print arithmetic (folio 7)",
    }, {
      "name" = "dtnMountainFeature",
      "limits" = { 15, 55, 60, 70, 75, 87, 95 },
      "tail" = 7,
      "comment" = "the mountainous terrain feature bands - featureless, slope, hill, rough ground, dense brush, light woods, dense woods, stream (folio 7)",
    }, {
      "name" = "dtnWoodedFeature",
      "limits" = { 5, 40, 60, 65, 68, 75, 89, 91, 95 },
      "tail" = 9,
      "comment" = "the wooded terrain feature bands - featureless, dense woods, light woods, dense brush, rough ground, slope, hill, marsh, stream, pond (folio 7)",
    }, {
      "name" = "dtnMarshyFeature",
      "limits" = { 5, 25, 55, 65, 80, 85, 93, 98 },
      "tail" = 8,
      "comment" = "the marshy terrain feature bands - featureless, marsh, pond, stream, dense brush, rough ground, dense woods, light woods, gentle hill (folio 7)",
    }, {
      "name" = "dtnClearGrade",
      "limits" = { 60, 90, 98 },
      "tail" = 3,
      "comment" = "the clear grade bands - gentle 1-60, average 61-90, steep 91-98, sheer 99-00 (folio 7)",
    }, {
      "name" = "dtnRoughGrade",
      "limits" = { 35, 75, 95 },
      "tail" = 3,
      "comment" = "the rough grade bands - gentle 1-35, average 36-75, steep 76-95, sheer 96-00 (folio 7)",
    }, {
      "name" = "dtnMountainGrade",
      "limits" = { 5, 30, 85 },
      "tail" = 3,
      "comment" = "the mountainous grade bands - gentle 1-5, average 6-30, steep 31-85, sheer 86-00 (folio 7)",
    }, {
      "name" = "dtnWoodedGrade",
      "limits" = { 50, 85, 96 },
      "tail" = 3,
      "comment" = "the wooded grade bands - gentle 1-50, average 51-85, steep 86-96, sheer 97-00 (folio 7)",
    }, {
      "name" = "dtnClearExtra",
      "limits" = { 90, 95 },
      "tail" = 2,
      "comment" = "the clear roll-again bands - no additional features 1-90, additional light woods 91-95, additional rough ground 96-00 (folio 7)",
    }, {
      "name" = "dtnRoughExtra",
      "limits" = { 60, 75, 81, 94 },
      "tail" = 4,
      "comment" = "the rough roll-again bands - none, rough ground, dense brush, light woods, dense woods (folio 7)",
    }, {
      "name" = "dtnMountainExtra",
      "limits" = { 60, 70, 77, 91 },
      "tail" = 4,
      "comment" = "the mountainous roll-again bands - none, rough ground, dense brush, light woods, dense woods (folio 7)",
    }, {
      "name" = "dtnWoodedExtra",
      "limits" = { 15, 60, 90, 94 },
      "tail" = 4,
      "comment" = "the wooded roll-again bands - none, dense woods, light woods, rough ground, dense brush (folio 7)",
    }, {
      "name" = "dtnMarshyExtra",
      "limits" = { 5, 50, 70, 80, 93 },
      "tail" = 5,
      "comment" = "the marshy roll-again bands - none, marsh (none if hill), dense brush, rough ground, dense woods, light woods (folio 7)",
    }, {
      "name" = "dtnRiverCourse",
      "limits" = { 2, 4 },
      "tail" = 2,
      "comment" = "the course of runs - 1-2 turns clockwise, 3-4 goes straight, 5-6 turns counterclockwise (folio 7)",
    }, {
      "name" = "dtnSlopeFacing",
      "limits" = { 2 },
      "tail" = 1,
      "comment" = "the facing of slopes - 1-2 faces the high ground, 3-6 faces away (folio 7)",
    }, {
      "name" = "dtnRMTypeBand",
      "limits" = { 4, 7 },
      "tail" = 2,
      "comment" = "the type band - 1-4 mammal, 5-7 reptile, 8 undead (folio 9)",
    }, {
      "name" = "dtnRMIntelligenceBand",
      "limits" = { 3, 5 },
      "tail" = 2,
      "comment" = "the intelligence band - 1-3 highly intelligent, 4-5 semi-intelligent, 6 unintelligent (folio 9)",
    } },
  "examples" = { {
      "expr" = "m['dtnOrgyMaxGpPerLevel']() != 500 or m['dtnResearchGpPerLevelDay']() != 250 or m['dtnSacrificeFavorGpPerLevel']() != 100 or m['dtnOrgyRecuperatingMaxGp']() != 250",
      "note" = "the expenditure rates - the orgy at 500 GP per level per night, 250 recuperating, the research at 250 GP per level per day, the sacrifice favor at 100 GP per level (folios 5-6)",
    }, {
      "expr" = "m['dtnPsionicGpPerPoint']() != 20 or m['dtnPsionicGpPerAbilityRoll']() != 100 or m['dtnPsionicAbilityLossPct']() != 10 or m['dtnPsionicAbilityRegenPoints']() != 100",
      "note" = "the appendix II psionic rules - 20 GP per point, 100 GP per 10% ability-loss roll, an ability back per 100 points regained (folio 6)",
    }, {
      "expr" = "m['dtnMillCostGp']() != 500 or m['dtnMillAnnualMinGp']() != 100 or m['dtnMillAnnualMaxGp']() != 600 or m['dtnHouseMinEdgePct']() != 60 or m['dtnSpecialistFiefDivisor']() != 10",
      "note" = "the fief economics - the 500-GP mill at 100-600 per 100 people, the 60-40 house edge, the specialist divisor of 10 (folio 6)",
    }, {
      "expr" = "m['dtnRiverAcrossFieldPct']() != 10 or m['dtnRiverFordChancePct']() != 10 or m['dtnSlopeTurnsToWaterPct']() != 75 or m['dtnDenseWoodsSightingMaxFt']() != 120 or m['dtnLightWoodsSightingMaxYds']() != 100",
      "note" = "the river at 10% with the ford at 10% more, the 75% slope turn, the 20-120 foot dense-woods sighting and the 20-100 yard light-woods sighting (folio 7)",
    }, {
      "expr" = "m['dtnClearFeature'](70) != 0 or m['dtnClearFeature'](71) != 1 or m['dtnRoughFeature'](60) != 2 or m['dtnMarshyFeature'](98) != 7 or m['dtnWoodedFeature'](40) != 1",
      "note" = "the terrain feature band boundaries - the clear 71-77 hill band, the rough 46-60 rough-ground band, the marshy 94-98 light-woods band, the wooded 6-40 dense-woods band (folio 7)",
    }, {
      "expr" = "m['dtnClearGrade'](60) != 0 or m['dtnClearGrade'](61) != 1 or m['dtnMountainGrade'](5) != 0 or m['dtnMountainGrade'](86) != 3",
      "note" = "the grade bands - the clear gentle 1-60, the mountainous sheer 86-00 (folio 7)",
    }, {
      "expr" = "m['dtnRMDungeonLevels']() != 20 or m['dtnRMUndeadTurnDivisor']() != 2 or m['dtnRMVampireAtLevel']() != 17 or m['dtnRMUndeadACBonus']() != 1",
      "note" = "the Random Monsters basis - the 20-level dungeon, the undead turning at HD/2, the vampire threshold at 17, the undead AC at (1-8)+1 (folios 9-10)",
    }, {
      "expr" = "m['dtnRMTypeBand'](4) != 0 or m['dtnRMTypeBand'](5) != 1 or m['dtnRMTypeBand'](8) != 2 or m['dtnRMIntelligenceBand'](3) != 0 or m['dtnRMIntelligenceBand'](6) != 2",
      "note" = "the type band - mammal 1-4, reptile 5-7, undead 8 - and the intelligence band, highly 1-3 through unintelligent 6 (folio 9)",
    } },
  "audit" = {
      "label" = "R914 issue-10 opener audit",
      "comment" = "THE DRAGON ISSUE-10 OPENER ROUND, PART ONE - three adjudicated chains. The Pickens Orgies Inc. article (folios 5-6): the experience-only-as-spent doctrine with the level divisor capped at the class hit dice, the five expenditure classes - the weekly sacrifice with its 100-GP-per-level favor option, the lawful-only philanthropy, the 250-GP-per-level-day research, the no-withdrawal clan hoards and the 500-GP-per-level-night orgy with its constitution-days cycle - the hireling halving, the fief and mill economics, the 60-40 house edge with the halved winnings, and the psionic appendix at 20 GP per point and 100 GP per ability roll. The Clifton wilderness article (folio 7): the four-foot-square convention, the river and ford at 10% each, the swimmer and road doctrines, the 75% slope turn, the five terrain feature bands with their grades and roll-again tables, the run courses and slope facings, the dense-woods doubled surprise at 20-120 feet, the light-woods 20-100 yard sighting, the halved surprise at maximum sighting, the opposite-corner placement and the grade heights. The Crabaugh Random Monsters article (folios 9-10): the 20-level dungeon basis, the type and intelligence bands, the hit-dice modifier and AC tables, the level-offset column, the undead turning at HD/2 with the vampire threshold at 17, and the weapon-or-bite damage doctrine.",
    },
}
