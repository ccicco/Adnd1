-- oa621: promoted from rules/oa/oamonk.h (the THE MONK, printed capture pp. 31-35 - the OA monk round);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 621,
  "prefix" = "oa621",
  "banner" = {
      "title" = "THE MONK, printed capture pp. 31-35 - the OA monk round",
      "provenance" = "census 543 -> 544.  verified against capture pp. 31-35 of the oa.pdf OCR session (single Mistral-OCR capture; cites are capture pages). The Table 20 hit-points column header is settled against the 2018 print (4-sided dice for accum. hit points) - the 2-through-18 cells pin as accumulated d4 dice, the level plus one. The Table 21 additional-attack and additional-damage cells pin as codes (the slash pairs and the plus-dice notation). OCR normalization: may riot own horses reads as may not own horses; immune to gees reads as immune to geas (prose only)  the gap census after this round: 39 closed, 196 open - the monk boxes with Tables 20 and 21 flip (census 543 -> 544); NEXT - R622: the Ninja, capture pp. 35-39, Tables 22 and 23, prefix dgi (verify free), audit \"R622 OA ninja audit\", include after rules/oa/oamonk.h",
    },
  "consts" = { {
      "name" = "dghMonkMinStr",
      "value" = 15,
      "comment" = "Monk prose (capture p. 32): the Strength minimum",
    }, {
      "name" = "dghMonkMinWis",
      "value" = 15,
      "comment" = "Monk prose (capture p. 32): the Wisdom minimum",
    }, {
      "name" = "dghMonkMinDex",
      "value" = 15,
      "comment" = "Monk prose (capture p. 32): the Dexterity minimum",
    }, {
      "name" = "dghMonkMinCon",
      "value" = 11,
      "comment" = "Monk prose (capture p. 32): the Constitution minimum",
    }, {
      "name" = "dghMonkMaxLevel",
      "value" = 17,
      "comment" = "Monk prose (capture pp. 31-32): monks do not advance beyond 17th level",
    }, {
      "name" = "dghMonkStartDice",
      "value" = 2,
      "comment" = "Monk prose (capture p. 32): begins with 2-8 (2d4) hit points",
    }, {
      "name" = "dghMonkHitDie",
      "value" = 4,
      "comment" = "Monk prose (capture p. 32): gains 1d4 hit points per level thereafter",
    }, {
      "name" = "dghMonkWeaponDmgStep",
      "value" = 2,
      "comment" = "Monk prose (capture p. 32): one extra point of weapon damage per two experience levels",
    }, {
      "name" = "dghMonkBaseMove",
      "value" = 15,
      "comment" = "Monk prose (capture p. 32): base movement of 15 feet, improving per Table 21",
    }, {
      "name" = "dghMonkSlots",
      "value" = 5,
      "comment" = "Monk prose (capture p. 32): five other proficiency slots beyond the style",
    }, {
      "name" = "dghMonkStyleManeuvers",
      "value" = 2,
      "comment" = "Monk prose (capture p. 32): two of the style special maneuvers at start",
    }, {
      "name" = "dghMonkKiPerDayMult",
      "value" = 1,
      "comment" = "Monk prose (capture p. 33): the ki power usable a number of times per day equal to level",
    }, {
      "name" = "dghMonkSpeakAnimalsLevel",
      "value" = 3,
      "comment" = "Monk prose (capture p. 33): speak with animals at 3rd level, nonmagical",
    }, {
      "name" = "dghMonkFall20Level",
      "value" = 4,
      "comment" = "Monk prose (capture p. 33): the 20-foot fall at 4th level",
    }, {
      "name" = "dghMonkFall20Feet",
      "value" = 20,
      "comment" = "Monk prose (capture p. 33): fall up to 20 feet without damage",
    }, {
      "name" = "dghMonkFall20WallFeet",
      "value" = 1,
      "comment" = "Monk prose (capture p. 33): provided he is within one foot of a wall",
    }, {
      "name" = "dghMonkEspBasePct",
      "value" = 30,
      "comment" = "Monk prose (capture p. 33): ESP has only a 30 percent chance at 4th level",
    }, {
      "name" = "dghMonkEspStepPct",
      "value" = 2,
      "comment" = "Monk prose (capture p. 33): the ESP protection improves by 2 percent per level beyond 4th",
    }, {
      "name" = "dghMonkDiseaseLevel",
      "value" = 5,
      "comment" = "Monk prose (capture p. 33): immune to all disease at 5th level",
    }, {
      "name" = "dghMonkFall30Level",
      "value" = 6,
      "comment" = "Monk prose (capture p. 33): the 30-foot fall at 6th level",
    }, {
      "name" = "dghMonkFall30Feet",
      "value" = 30,
      "comment" = "Monk prose (capture p. 33): fall 30 feet without damage",
    }, {
      "name" = "dghMonkFall30WallFeet",
      "value" = 4,
      "comment" = "Monk prose (capture p. 33): provided he is within four feet of a wall",
    }, {
      "name" = "dghMonkCatalepticMult",
      "value" = 2,
      "comment" = "Monk prose (capture pp. 33-34): the cataleptic state lasts turns equal to twice his level",
    }, {
      "name" = "dghMonkHealLevel",
      "value" = 7,
      "comment" = "Monk prose (capture p. 34): the self-heal at 7th level",
    }, {
      "name" = "dghMonkHealMin",
      "value" = 2,
      "comment" = "Monk prose (capture p. 34): heals 2-5 points of damage per day",
    }, {
      "name" = "dghMonkHealMax",
      "value" = 5,
      "comment" = "Monk prose (capture p. 34): the heal upper bound",
    }, {
      "name" = "dghMonkHealStep",
      "value" = 1,
      "comment" = "Monk prose (capture p. 34): the heal increases one point per level beyond 7th",
    }, {
      "name" = "dghMonkSpeakPlantsLevel",
      "value" = 8,
      "comment" = "Monk prose (capture p. 34): speak with plants at 8th level",
    }, {
      "name" = "dghMonkFollowerMin",
      "value" = 2,
      "comment" = "Monk prose (capture p. 34): attracts 2-5 followers at 8th level",
    }, {
      "name" = "dghMonkFollowerMax",
      "value" = 5,
      "comment" = "Monk prose (capture p. 34): the follower upper bound",
    }, {
      "name" = "dghMonkFollowerExtraMin",
      "value" = 1,
      "comment" = "Monk prose (capture p. 34): 1-2 more 1st-level monks per level beyond 8th",
    }, {
      "name" = "dghMonkFollowerExtraMax",
      "value" = 2,
      "comment" = "Monk prose (capture p. 34): the extra-follower upper bound",
    }, {
      "name" = "dghMonkFollowerLeaveLevel",
      "value" = 7,
      "comment" = "Monk prose (capture p. 34): followers leave when they reach 7th level",
    }, {
      "name" = "dghMonkKiHalfFailLevel",
      "value" = 9,
      "comment" = "Monk prose (capture p. 34): from 9th level the ki gives half damage even on a failed save",
    }, {
      "name" = "dghMonkCharmBasePct",
      "value" = 50,
      "comment" = "Monk prose (capture p. 34): charm, hypnosis and suggestion have only a 50 percent chance at 9th",
    }, {
      "name" = "dghMonkCharmStepPct",
      "value" = 5,
      "comment" = "Monk prose (capture p. 34): the charm resistance improves by 5 percent per level beyond 9th",
    }, {
      "name" = "dghMonkMindShieldLevel",
      "value" = 10,
      "comment" = "Monk prose (capture p. 34): telepathic and mind blast defense as if Intelligence 18 at 10th",
    }, {
      "name" = "dghMonkPoisonImmuneLevel",
      "value" = 11,
      "comment" = "Monk prose (capture p. 34): immune to all poison at 11th level",
    }, {
      "name" = "dghMonkGeasImmuneLevel",
      "value" = 12,
      "comment" = "Monk prose (capture p. 34): immune to geas and quest spells at 12th level",
    }, {
      "name" = "dghMonkFreeManeuverLevel",
      "value" = 13,
      "comment" = "Monk prose (capture p. 34): one free martial arts special maneuver at 13th level",
    }, {
      "name" = "dghMonkHenchLevel",
      "value" = 6,
      "comment" = "Monk prose (capture p. 34): no henchmen or hirelings until 6th level",
    }, {
      "name" = "dghMonkHenchBase",
      "value" = 2,
      "comment" = "Monk prose (capture p. 34): up to two henchmen at 6th level",
    }, {
      "name" = "dghMonkHenchStep",
      "value" = 1,
      "comment" = "Monk prose (capture p. 34): one additional henchman per level beyond 6th",
    }, {
      "name" = "dghMonkMagicWeaponCap",
      "value" = 2,
      "comment" = "Monk prose (capture p. 34): may retain only two magical weapons",
    }, {
      "name" = "dghMonkMagicItemCap",
      "value" = 3,
      "comment" = "Monk prose (capture p. 34): and three other magical items",
    }, {
      "name" = "dghMonkMonasteryEights",
      "value" = 3,
      "comment" = "Monk prose (capture p. 35): three monks of 8th level attached to a monastery",
    }, {
      "name" = "dghMonkMonasteryBeyond",
      "value" = 1,
      "comment" = "Monk prose (capture p. 35): one of each level beyond 8th attached to a monastery",
    }, {
      "name" = "dghMonkResetXpExample",
      "value" = 98001,
      "comment" = "Monk prose (capture p. 35): the printed duel example - a defeated 8th-level monk drops to 98,001 xp, the 7th minimum",
    }, {
      "name" = "dghT20RowCount",
      "value" = 17,
      "comment" = "Table 20 (capture pp. 31-32): seventeen rows, levels 1-17",
    }, {
      "name" = "dghT20TitleNovice",
      "value" = 1,
      "comment" = "Table 20 (capture p. 31): the level-title codes - 1st is Novice",
    }, {
      "name" = "dghT20TitleGrandMaster",
      "value" = 17,
      "comment" = "Table 20 (capture p. 32): 17th is Grand Master of Flowers",
    }, {
      "name" = "dghT21RowCount",
      "value" = 17,
      "comment" = "Table 21 (capture p. 33): seventeen rows, levels 1-17",
    }, {
      "name" = "dghT21AtNone",
      "value" = 0,
      "comment" = "Table 21 (capture p. 33): the additional-attack code 0 - no additional attacks",
    }, {
      "name" = "dghT21AtFirst",
      "value" = 14,
      "comment" = "Table 21 (capture p. 33): the first attack code 1/4 - extra attacks times ten plus the round",
    }, {
      "name" = "dghT21AtLast",
      "value" = 31,
      "comment" = "Table 21 (capture p. 33): the top attack code 3/1 - three extra attacks every round",
    }, {
      "name" = "dghT21DmgNone",
      "value" = 0,
      "comment" = "Table 21 (capture p. 33): the damage code 0 - no additional damage",
    }, {
      "name" = "dghT21DmgFirstDice",
      "value" = 100,
      "comment" = "Table 21 (capture p. 33): the first dice damage code plus 1D - dice times 100 plus points",
    }, {
      "name" = "dghT21DmgCap",
      "value" = 400,
      "comment" = "Table 21 (capture p. 33): the top damage code plus 4D",
    }, {
      "name" = "dghT21SurpriseNormal",
      "value" = 0,
      "comment" = "Table 21 (capture p. 33): the surprise code 0 - the normal 1st-level surprise",
    } },
  "bools" = { {
      "name" = "dghMonkLawfulOnly",
      "value" = true,
      "comment" = "Monk prose (capture p. 32): must always be lawful - good, evil or neutral combined with law",
    }, {
      "name" = "dghMonkNoPrimeBonus",
      "value" = true,
      "comment" = "Monk prose (capture p. 32): no prime requisite - never the experience point bonus for high scores",
    }, {
      "name" = "dghMonkNoStrAdjust",
      "value" = true,
      "comment" = "Monk prose (capture p. 32): never bonuses on to hit or damage rolls for high Strength",
    }, {
      "name" = "dghMonkNoDexAc",
      "value" = true,
      "comment" = "Monk prose (capture p. 32): never armor class adjustments for high Dexterity",
    }, {
      "name" = "dghMonkThiefTables",
      "value" = true,
      "comment" = "Monk prose (capture p. 32): the combat table and saving throw tables of thieves",
    }, {
      "name" = "dghMonkNoArmor",
      "value" = true,
      "comment" = "Monk prose (capture p. 32): cannot wear armor or use shields",
    }, {
      "name" = "dghMonkNoFlamingOil",
      "value" = true,
      "comment" = "Monk prose (capture p. 32): the use of flaming oil in combat is forbidden",
    }, {
      "name" = "dghMonkMissileDeflection",
      "value" = true,
      "comment" = "Monk prose (capture p. 32): all monks have the Missile Deflection maneuver free - outside the style slots",
    }, {
      "name" = "dghMonkKiSaveNegates",
      "value" = true,
      "comment" = "Monk prose (capture p. 33): the 1st-level ki - a successful save vs magic means no damage or effect",
    }, {
      "name" = "dghMonkKiDeclaredLate",
      "value" = true,
      "comment" = "Monk prose (capture p. 33): the ki use can be declared at any time, even after the die is rolled",
    }, {
      "name" = "dghMonkDiseaseImmune",
      "value" = true,
      "comment" = "Monk prose (capture p. 33): at 5th level immune to all types of disease",
    }, {
      "name" = "dghMonkHasteSlowImmune",
      "value" = true,
      "comment" = "Monk prose (capture p. 33): at 5th level unaffected by all haste or slow spells",
    }, {
      "name" = "dghMonkCatalepticStated",
      "value" = true,
      "comment" = "Monk prose (capture pp. 33-34): the cataleptic duration must be stated at the beginning",
    }, {
      "name" = "dghMonkNoFamilyHonor",
      "value" = true,
      "comment" = "Monk prose (capture p. 34): no family, clan, birth rank, ancestry, birthrights or honor points",
    }, {
      "name" = "dghMonkMonasteryName",
      "value" = true,
      "comment" = "Monk prose (capture p. 34): adopts a name appropriate to the monastery, never the family name",
    }, {
      "name" = "dghMonkNoProperty",
      "value" = true,
      "comment" = "Monk prose (capture p. 34): can never hold land or property of any type",
    }, {
      "name" = "dghMonkDmgItemGate",
      "value" = true,
      "comment" = "Monk prose (capture p. 34): DMG magical items only if rings or usable by thieves",
    }, {
      "name" = "dghMonkNoItemTrading",
      "value" = true,
      "comment" = "Monk prose (capture p. 34): never trades magical items for better pieces",
    }, {
      "name" = "dghMonkMonasteryDuel",
      "value" = true,
      "comment" = "Monk prose (capture p. 35): beyond 7th the monk must find and defeat the monk of that level to keep it",
    }, {
      "name" = "dghMonkDuelNoIntervention",
      "value" = true,
      "comment" = "Monk prose (capture p. 35): the duel is strictly between the two monks - no one can intervene",
    } },
  "switches" = { {
      "name" = "dghT20XpMax",
      "values" = { 2250, 4750, 10000, 22500, 47500, 98000, 200000, 350000, 500000, 700000, 950000, 1250000, 1750000, 2250000, 2750000, 3250000, 3250001 },
      "default" = -99,
      "comment" = "the experience column: the upper xp bound of each level, 2,250 at 1st to 3,250,000 at 16th, then the 3,250,001 floor of the unbounded 17th (capture pp. 31-32).",
    }, {
      "name" = "dghT20Dice",
      "values" = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 },
      "default" = -99,
      "comment" = "the accumulated d4 dice column: the 2d4 start plus 1d4 per level - the level plus one, 2 through 18 (the 2018 print settles the header: 4-sided dice for accum. hit points) (capture pp. 31-32).",
    }, {
      "name" = "dghT20Title",
      "values" = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 },
      "default" = -99,
      "comment" = "the level-title code column: 1 Novice, 2 Initiate, 3 Brother, 4 Disciple, 5 Immaculate, 6 Master, 7 Superior Master, 8 Master of Dragons, 9 Master of the North Wind, 10 Master of the West Wind, 11 Master of the South Wind, 12 Master of the East Wind, 13 Master of Winter, 14 Master of Autumn, 15 Master of Summer, 16 Master of Spring, 17 Grand Master of Flowers (capture pp. 31-32).",
    }, {
      "name" = "dghT21Ac",
      "values" = { 10, 9, 8, 7, 7, 6, 5, 4, 3, 3, 2, 1, 0, -1, -1, -2, -3 },
      "default" = -99,
      "comment" = "the armor class column: 10 at 1st improving to -3 at 17th, the style AC used only if better (capture p. 33).",
    }, {
      "name" = "dghT21Move",
      "values" = { 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 32 },
      "default" = -99,
      "comment" = "the movement column: 15 feet at 1st improving to 32 at 17th (capture p. 33).",
    }, {
      "name" = "dghT21At",
      "values" = { 0, 0, 0, 14, 14, 12, 12, 12, 11, 11, 32, 32, 32, 21, 21, 31, 31 },
      "default" = -99,
      "comment" = "the additional martial-arts attack column as a code - 0 none, then extra attacks times ten plus the round: 1/4 = 14, 1/2 = 12, 1/1 = 11, 3/2 = 32, 2/1 = 21, 3/1 = 31 (capture p. 33).",
    }, {
      "name" = "dghT21Dmg",
      "values" = { 0, 0, 0, 0, 1, 2, 2, 100, 101, 102, 102, 200, 200, 201, 300, 301, 400 },
      "default" = -99,
      "comment" = "the additional martial-arts damage column as a code - dice times 100 plus points: 0 none, 1, 2, then 100 (+1D), 101 (+1D+1), 102 (+1D+2), 200 (+2D), 201 (+2D+1), 300 (+3D), 301 (+3D+1), 400 (+4D) (capture p. 33).",
    }, {
      "name" = "dghT21OpenLocks",
      "values" = { 25, 29, 33, 37, 42, 47, 52, 57, 62, 67, 72, 77, 82, 87, 92, 97, 99 },
      "default" = -99,
      "comment" = "the open locks column: 25 percent at 1st to 99 at 17th (capture p. 33).",
    }, {
      "name" = "dghT21Traps",
      "values" = { 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 99 },
      "default" = -99,
      "comment" = "the find and remove traps column: 20 percent at 1st to 99 at 17th (capture p. 33).",
    }, {
      "name" = "dghT21Silent",
      "values" = { 15, 21, 27, 33, 40, 47, 55, 62, 70, 78, 86, 94, 99, 99, 99, 99, 99 },
      "default" = -99,
      "comment" = "the move silently column: 15 percent at 1st to 99 at 13th and beyond (capture p. 33).",
    }, {
      "name" = "dghT21Hide",
      "values" = { 10, 15, 20, 25, 31, 37, 43, 49, 56, 63, 70, 77, 85, 93, 99, 99, 99 },
      "default" = -99,
      "comment" = "the hide in shadows column: 10 percent at 1st to 99 at 15th and beyond (capture p. 33).",
    }, {
      "name" = "dghT21Hear",
      "values" = { 10, 10, 15, 15, 20, 20, 25, 25, 30, 30, 35, 35, 40, 40, 50, 50, 55 },
      "default" = -99,
      "comment" = "the hear noise column: 10 percent at 1st to 55 at 17th (capture p. 33).",
    }, {
      "name" = "dghT21Climb",
      "values" = { 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 99, 99 },
      "default" = -99,
      "comment" = "the climb walls column: 85 percent at 1st to 99 at 15th and beyond (capture p. 33).",
    }, {
      "name" = "dghT21Surprise",
      "values" = { 0, 32, 30, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2 },
      "default" = -99,
      "comment" = "the surprise column as a code: 0 the normal 1st-level chance, then the surprised percentages 32 at 2nd down to 2 at 17th (capture p. 33).",
    } },
  "tables" = { {
      "name" = "dghT20Grid",
      "tag" = "T20",
      "count" = "dghT20RowCount",
      "sentinel" = -99,
      "cols" = { "dghT20XpMax", "dghT20Dice", "dghT20Title" },
      "data" = { { 2250, 2, 1 }, { 4750, 3, 2 }, { 10000, 4, 3 }, { 22500, 5, 4 }, { 47500, 6, 5 }, { 98000, 7, 6 }, { 200000, 8, 7 }, { 350000, 9, 8 }, { 500000, 10, 9 }, { 700000, 11, 10 }, { 950000, 12, 11 }, { 1250000, 13, 12 }, { 1750000, 14, 13 }, { 2250000, 15, 14 }, { 2750000, 16, 15 }, { 3250000, 17, 16 }, { 3250001, 18, 17 } },
      "comment" = "the Table 20 monk advancement grid (capture pp. 31-32)",
      "col_comments" = { "the experience column: the upper xp bound of each level, 2,250 at 1st to 3,250,000 at 16th, then the 3,250,001 floor of the unbounded 17th (capture pp. 31-32).", "the accumulated d4 dice column: the 2d4 start plus 1d4 per level - the level plus one, 2 through 18 (the 2018 print settles the header: 4-sided dice for accum. hit points) (capture pp. 31-32).", "the level-title code column: 1 Novice, 2 Initiate, 3 Brother, 4 Disciple, 5 Immaculate, 6 Master, 7 Superior Master, 8 Master of Dragons, 9 Master of the North Wind, 10 Master of the West Wind, 11 Master of the South Wind, 12 Master of the East Wind, 13 Master of Winter, 14 Master of Autumn, 15 Master of Summer, 16 Master of Spring, 17 Grand Master of Flowers (capture pp. 31-32)." },
      "audit_comment" = "the Table 20 grid: the xp bounds, the accumulated d4 dice and the title codes (capture pp. 31-32)",
      "sentinel_census" = { 0, 0, 0 },
    }, {
      "name" = "dghT21Grid",
      "tag" = "T21",
      "count" = "dghT21RowCount",
      "sentinel" = -99,
      "cols" = { "dghT21Ac", "dghT21Move", "dghT21At", "dghT21Dmg", "dghT21OpenLocks", "dghT21Traps", "dghT21Silent", "dghT21Hide", "dghT21Hear", "dghT21Climb", "dghT21Surprise" },
      "data" = { { 10, 15, 0, 0, 25, 20, 15, 10, 10, 85, 0 }, { 9, 16, 0, 0, 29, 25, 21, 15, 10, 86, 32 }, { 8, 17, 0, 0, 33, 30, 27, 20, 15, 87, 30 }, { 7, 18, 14, 0, 37, 35, 33, 25, 15, 88, 28 }, { 7, 19, 14, 1, 42, 40, 40, 31, 20, 89, 26 }, { 6, 20, 12, 2, 47, 45, 47, 37, 20, 90, 24 }, { 5, 21, 12, 2, 52, 50, 55, 43, 25, 91, 22 }, { 4, 22, 12, 100, 57, 55, 62, 49, 25, 92, 20 }, { 3, 23, 11, 101, 62, 60, 70, 56, 30, 93, 18 }, { 3, 24, 11, 102, 67, 65, 78, 63, 30, 94, 16 }, { 2, 25, 32, 102, 72, 70, 86, 70, 35, 95, 14 }, { 1, 26, 32, 200, 77, 75, 94, 77, 35, 96, 12 }, { 0, 27, 32, 200, 82, 80, 99, 85, 40, 97, 10 }, { -1, 28, 21, 201, 87, 85, 99, 93, 40, 98, 8 }, { -1, 29, 21, 300, 92, 90, 99, 99, 50, 99, 6 }, { -2, 30, 31, 301, 97, 95, 99, 99, 50, 99, 4 }, { -3, 32, 31, 400, 99, 99, 99, 99, 55, 99, 2 } },
      "comment" = "the Table 21 monk capabilities grid (capture p. 33)",
      "col_comments" = { "the armor class column: 10 at 1st improving to -3 at 17th, the style AC used only if better (capture p. 33).", "the movement column: 15 feet at 1st improving to 32 at 17th (capture p. 33).", "the additional martial-arts attack column as a code - 0 none, then extra attacks times ten plus the round: 1/4 = 14, 1/2 = 12, 1/1 = 11, 3/2 = 32, 2/1 = 21, 3/1 = 31 (capture p. 33).", "the additional martial-arts damage column as a code - dice times 100 plus points: 0 none, 1, 2, then 100 (+1D), 101 (+1D+1), 102 (+1D+2), 200 (+2D), 201 (+2D+1), 300 (+3D), 301 (+3D+1), 400 (+4D) (capture p. 33).", "the open locks column: 25 percent at 1st to 99 at 17th (capture p. 33).", "the find and remove traps column: 20 percent at 1st to 99 at 17th (capture p. 33).", "the move silently column: 15 percent at 1st to 99 at 13th and beyond (capture p. 33).", "the hide in shadows column: 10 percent at 1st to 99 at 15th and beyond (capture p. 33).", "the hear noise column: 10 percent at 1st to 55 at 17th (capture p. 33).", "the climb walls column: 85 percent at 1st to 99 at 15th and beyond (capture p. 33).", "the surprise column as a code: 0 the normal 1st-level chance, then the surprised percentages 32 at 2nd down to 2 at 17th (capture p. 33)." },
      "audit_comment" = "the Table 21 grid: the AC, movement, attack and damage codes, the six thief skills and the surprise ladder (capture p. 33)",
      "sentinel_census" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dghMonkMinStr']() != 15  or m['dghMonkMinWis']() != 15  or m['dghMonkMinDex']() != 15  or m['dghMonkMinCon']() != 11  or m['dghMonkMaxLevel']() != 17  or m['dghMonkStartDice']() != 2  or m['dghMonkHitDie']() != 4  or m['dghMonkWeaponDmgStep']() != 2  or m['dghMonkBaseMove']() != 15  or m['dghMonkSlots']() != 5  or m['dghMonkStyleManeuvers']() != 2  or m['dghMonkKiPerDayMult']() != 1  or m['dghMonkSpeakAnimalsLevel']() != 3  or m['dghMonkFall20Level']() != 4  or m['dghMonkFall20Feet']() != 20  or m['dghMonkFall20WallFeet']() != 1  or m['dghMonkEspBasePct']() != 30  or m['dghMonkEspStepPct']() != 2  or m['dghMonkDiseaseLevel']() != 5  or m['dghMonkFall30Level']() != 6  or m['dghMonkFall30Feet']() != 30  or m['dghMonkFall30WallFeet']() != 4  or m['dghMonkCatalepticMult']() != 2  or m['dghMonkHealLevel']() != 7  or m['dghMonkHealMin']() != 2  or m['dghMonkHealMax']() != 5  or m['dghMonkHealStep']() != 1  or m['dghMonkSpeakPlantsLevel']() != 8  or m['dghMonkFollowerMin']() != 2  or m['dghMonkFollowerMax']() != 5  or m['dghMonkFollowerExtraMin']() != 1  or m['dghMonkFollowerExtraMax']() != 2  or m['dghMonkFollowerLeaveLevel']() != 7  or m['dghMonkKiHalfFailLevel']() != 9  or m['dghMonkCharmBasePct']() != 50  or m['dghMonkCharmStepPct']() != 5  or m['dghMonkMindShieldLevel']() != 10  or m['dghMonkPoisonImmuneLevel']() != 11  or m['dghMonkGeasImmuneLevel']() != 12  or m['dghMonkFreeManeuverLevel']() != 13  or m['dghMonkHenchLevel']() != 6  or m['dghMonkHenchBase']() != 2  or m['dghMonkHenchStep']() != 1  or m['dghMonkMagicWeaponCap']() != 2  or m['dghMonkMagicItemCap']() != 3  or m['dghMonkMonasteryEights']() != 3  or m['dghMonkMonasteryBeyond']() != 1  or m['dghMonkResetXpExample']() != 98001  or m['dghT20RowCount']() != 17  or m['dghT20TitleNovice']() != 1  or m['dghT20TitleGrandMaster']() != 17  or m['dghT21RowCount']() != 17  or m['dghT21AtNone']() != 0  or m['dghT21AtFirst']() != 14  or m['dghT21AtLast']() != 31  or m['dghT21DmgNone']() != 0  or m['dghT21DmgFirstDice']() != 100  or m['dghT21DmgCap']() != 400  or m['dghT21SurpriseNormal']() != 0  or  m['dghMonkLawfulOnly']() != 1  or  m['dghMonkNoPrimeBonus']() != 1  or  m['dghMonkNoStrAdjust']() != 1  or  m['dghMonkNoDexAc']() != 1  or  m['dghMonkThiefTables']() != 1  or  m['dghMonkNoArmor']() != 1  or  m['dghMonkNoFlamingOil']() != 1  or  m['dghMonkMissileDeflection']() != 1  or  m['dghMonkKiSaveNegates']() != 1  or  m['dghMonkKiDeclaredLate']() != 1  or  m['dghMonkHasteSlowImmune']() != 1  or  m['dghMonkDiseaseImmune']() != 1  or  m['dghMonkCatalepticStated']() != 1  or  m['dghMonkMonasteryDuel']() != 1  or  m['dghMonkDuelNoIntervention']() != 1  or  m['dghMonkNoFamilyHonor']() != 1  or  m['dghMonkMonasteryName']() != 1  or  m['dghMonkNoProperty']() != 1  or  m['dghMonkDmgItemGate']() != 1  or  m['dghMonkNoItemTrading']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dghMonkMinStr']() != 15",
      "note" = "the dghMonkMinStr pin",
    }, {
      "expr" = "m['dghMonkMinWis']() != 15",
      "note" = "the dghMonkMinWis pin",
    }, {
      "expr" = "m['dghMonkMinDex']() != 15",
      "note" = "the dghMonkMinDex pin",
    }, {
      "expr" = "m['dghMonkMinCon']() != 11",
      "note" = "the dghMonkMinCon pin",
    }, {
      "expr" = "m['dghMonkMaxLevel']() != 17",
      "note" = "the dghMonkMaxLevel pin",
    }, {
      "expr" = "m['dghMonkStartDice']() != 2",
      "note" = "the dghMonkStartDice pin",
    }, {
      "expr" = "m['dghMonkHitDie']() != 4",
      "note" = "the dghMonkHitDie pin",
    }, {
      "expr" = "m['dghMonkWeaponDmgStep']() != 2",
      "note" = "the dghMonkWeaponDmgStep pin",
    }, {
      "expr" = "m['dghMonkBaseMove']() != 15",
      "note" = "the dghMonkBaseMove pin",
    }, {
      "expr" = "m['dghMonkSlots']() != 5",
      "note" = "the dghMonkSlots pin",
    }, {
      "expr" = "m['dghMonkStyleManeuvers']() != 2",
      "note" = "the dghMonkStyleManeuvers pin",
    }, {
      "expr" = "m['dghMonkKiPerDayMult']() != 1",
      "note" = "the dghMonkKiPerDayMult pin",
    }, {
      "expr" = "m['dghMonkSpeakAnimalsLevel']() != 3",
      "note" = "the dghMonkSpeakAnimalsLevel pin",
    }, {
      "expr" = "m['dghMonkFall20Level']() != 4",
      "note" = "the dghMonkFall20Level pin",
    }, {
      "expr" = "m['dghMonkFall20Feet']() != 20",
      "note" = "the dghMonkFall20Feet pin",
    }, {
      "expr" = "m['dghMonkFall20WallFeet']() != 1",
      "note" = "the dghMonkFall20WallFeet pin",
    }, {
      "expr" = "m['dghMonkEspBasePct']() != 30",
      "note" = "the dghMonkEspBasePct pin",
    }, {
      "expr" = "m['dghMonkEspStepPct']() != 2",
      "note" = "the dghMonkEspStepPct pin",
    }, {
      "expr" = "m['dghMonkDiseaseLevel']() != 5",
      "note" = "the dghMonkDiseaseLevel pin",
    }, {
      "expr" = "m['dghMonkFall30Level']() != 6",
      "note" = "the dghMonkFall30Level pin",
    }, {
      "expr" = "m['dghMonkFall30Feet']() != 30",
      "note" = "the dghMonkFall30Feet pin",
    }, {
      "expr" = "m['dghMonkFall30WallFeet']() != 4",
      "note" = "the dghMonkFall30WallFeet pin",
    }, {
      "expr" = "m['dghMonkCatalepticMult']() != 2",
      "note" = "the dghMonkCatalepticMult pin",
    }, {
      "expr" = "m['dghMonkHealLevel']() != 7",
      "note" = "the dghMonkHealLevel pin",
    }, {
      "expr" = "m['dghMonkHealMin']() != 2",
      "note" = "the dghMonkHealMin pin",
    }, {
      "expr" = "m['dghMonkHealMax']() != 5",
      "note" = "the dghMonkHealMax pin",
    }, {
      "expr" = "m['dghMonkHealStep']() != 1",
      "note" = "the dghMonkHealStep pin",
    }, {
      "expr" = "m['dghMonkSpeakPlantsLevel']() != 8",
      "note" = "the dghMonkSpeakPlantsLevel pin",
    }, {
      "expr" = "m['dghMonkFollowerMin']() != 2",
      "note" = "the dghMonkFollowerMin pin",
    }, {
      "expr" = "m['dghMonkFollowerMax']() != 5",
      "note" = "the dghMonkFollowerMax pin",
    }, {
      "expr" = "m['dghMonkFollowerExtraMin']() != 1",
      "note" = "the dghMonkFollowerExtraMin pin",
    }, {
      "expr" = "m['dghMonkFollowerExtraMax']() != 2",
      "note" = "the dghMonkFollowerExtraMax pin",
    }, {
      "expr" = "m['dghMonkFollowerLeaveLevel']() != 7",
      "note" = "the dghMonkFollowerLeaveLevel pin",
    }, {
      "expr" = "m['dghMonkKiHalfFailLevel']() != 9",
      "note" = "the dghMonkKiHalfFailLevel pin",
    }, {
      "expr" = "m['dghMonkCharmBasePct']() != 50",
      "note" = "the dghMonkCharmBasePct pin",
    }, {
      "expr" = "m['dghMonkCharmStepPct']() != 5",
      "note" = "the dghMonkCharmStepPct pin",
    }, {
      "expr" = "m['dghMonkMindShieldLevel']() != 10",
      "note" = "the dghMonkMindShieldLevel pin",
    }, {
      "expr" = "m['dghMonkPoisonImmuneLevel']() != 11",
      "note" = "the dghMonkPoisonImmuneLevel pin",
    }, {
      "expr" = "m['dghMonkGeasImmuneLevel']() != 12",
      "note" = "the dghMonkGeasImmuneLevel pin",
    }, {
      "expr" = "m['dghMonkFreeManeuverLevel']() != 13",
      "note" = "the dghMonkFreeManeuverLevel pin",
    }, {
      "expr" = "m['dghMonkHenchLevel']() != 6",
      "note" = "the dghMonkHenchLevel pin",
    }, {
      "expr" = "m['dghMonkHenchBase']() != 2",
      "note" = "the dghMonkHenchBase pin",
    }, {
      "expr" = "m['dghMonkHenchStep']() != 1",
      "note" = "the dghMonkHenchStep pin",
    }, {
      "expr" = "m['dghMonkMagicWeaponCap']() != 2",
      "note" = "the dghMonkMagicWeaponCap pin",
    }, {
      "expr" = "m['dghMonkMagicItemCap']() != 3",
      "note" = "the dghMonkMagicItemCap pin",
    }, {
      "expr" = "m['dghMonkMonasteryEights']() != 3",
      "note" = "the dghMonkMonasteryEights pin",
    }, {
      "expr" = "m['dghMonkMonasteryBeyond']() != 1",
      "note" = "the dghMonkMonasteryBeyond pin",
    }, {
      "expr" = "m['dghMonkResetXpExample']() != 98001",
      "note" = "the dghMonkResetXpExample pin",
    }, {
      "expr" = "m['dghT20RowCount']() != 17",
      "note" = "the dghT20RowCount pin",
    }, {
      "expr" = "m['dghT20TitleNovice']() != 1",
      "note" = "the dghT20TitleNovice pin",
    }, {
      "expr" = "m['dghT20TitleGrandMaster']() != 17",
      "note" = "the dghT20TitleGrandMaster pin",
    }, {
      "expr" = "m['dghT21RowCount']() != 17",
      "note" = "the dghT21RowCount pin",
    }, {
      "expr" = "m['dghT21AtNone']() != 0",
      "note" = "the dghT21AtNone pin",
    }, {
      "expr" = "m['dghT21AtFirst']() != 14",
      "note" = "the dghT21AtFirst pin",
    }, {
      "expr" = "m['dghT21AtLast']() != 31",
      "note" = "the dghT21AtLast pin",
    }, {
      "expr" = "m['dghT21DmgNone']() != 0",
      "note" = "the dghT21DmgNone pin",
    }, {
      "expr" = "m['dghT21DmgFirstDice']() != 100",
      "note" = "the dghT21DmgFirstDice pin",
    }, {
      "expr" = "m['dghT21DmgCap']() != 400",
      "note" = "the dghT21DmgCap pin",
    }, {
      "expr" = "m['dghT21SurpriseNormal']() != 0",
      "note" = "the dghT21SurpriseNormal pin",
    }, {
      "expr" = "m['dghMonkLawfulOnly']() != 1",
      "note" = "the dghMonkLawfulOnly pin",
    }, {
      "expr" = "m['dghMonkNoPrimeBonus']() != 1",
      "note" = "the dghMonkNoPrimeBonus pin",
    }, {
      "expr" = "m['dghMonkNoStrAdjust']() != 1",
      "note" = "the dghMonkNoStrAdjust pin",
    }, {
      "expr" = "m['dghMonkNoDexAc']() != 1",
      "note" = "the dghMonkNoDexAc pin",
    }, {
      "expr" = "m['dghMonkThiefTables']() != 1",
      "note" = "the dghMonkThiefTables pin",
    }, {
      "expr" = "m['dghMonkNoArmor']() != 1",
      "note" = "the dghMonkNoArmor pin",
    }, {
      "expr" = "m['dghMonkNoFlamingOil']() != 1",
      "note" = "the dghMonkNoFlamingOil pin",
    }, {
      "expr" = "m['dghMonkMissileDeflection']() != 1",
      "note" = "the dghMonkMissileDeflection pin",
    }, {
      "expr" = "m['dghMonkKiSaveNegates']() != 1",
      "note" = "the dghMonkKiSaveNegates pin",
    }, {
      "expr" = "m['dghMonkKiDeclaredLate']() != 1",
      "note" = "the dghMonkKiDeclaredLate pin",
    }, {
      "expr" = "m['dghMonkHasteSlowImmune']() != 1",
      "note" = "the dghMonkHasteSlowImmune pin",
    }, {
      "expr" = "m['dghMonkDiseaseImmune']() != 1",
      "note" = "the dghMonkDiseaseImmune pin",
    }, {
      "expr" = "m['dghMonkCatalepticStated']() != 1",
      "note" = "the dghMonkCatalepticStated pin",
    }, {
      "expr" = "m['dghMonkMonasteryDuel']() != 1",
      "note" = "the dghMonkMonasteryDuel pin",
    }, {
      "expr" = "m['dghMonkDuelNoIntervention']() != 1",
      "note" = "the dghMonkDuelNoIntervention pin",
    }, {
      "expr" = "m['dghMonkNoFamilyHonor']() != 1",
      "note" = "the dghMonkNoFamilyHonor pin",
    }, {
      "expr" = "m['dghMonkMonasteryName']() != 1",
      "note" = "the dghMonkMonasteryName pin",
    }, {
      "expr" = "m['dghMonkNoProperty']() != 1",
      "note" = "the dghMonkNoProperty pin",
    }, {
      "expr" = "m['dghMonkDmgItemGate']() != 1",
      "note" = "the dghMonkDmgItemGate pin",
    }, {
      "expr" = "m['dghMonkNoItemTrading']() != 1",
      "note" = "the dghMonkNoItemTrading pin",
    }, {
      "expr" = "m['dghT20XpMax'](0) != 2250  or m['dghT20Dice'](0) != 2  or m['dghT20Title'](0) != 1",
      "note" = "the T20 first row - 2,250 xp, two dice, Novice (capture p. 31)",
    }, {
      "expr" = "m['dghT20XpMax'](16) != 3250001  or m['dghT20Dice'](16) != 18  or m['dghT20Title'](16) != 17",
      "note" = "the T20 capstone - 3,250,001 xp, eighteen dice, Grand Master of Flowers (capture p. 32)",
    }, {
      "expr" = "m['dghT21Ac'](0) != 10  or m['dghT21Move'](0) != 15  or m['dghT21Surprise'](0) != 0",
      "note" = "the T21 first row - AC 10, move 15, normal surprise (capture p. 33)",
    }, {
      "expr" = "m['dghT21Ac'](16) != -3  or m['dghT21Move'](16) != 32  or m['dghT21At'](16) != 31  or m['dghT21Dmg'](16) != 400  or m['dghT21Surprise'](16) != 2",
      "note" = "the T21 capstone - AC -3, move 32, the 3/1 and +4D codes, 2 percent surprise (capture p. 33)",
    }, {
      "expr" = "m['dghT21At'](3) != 14",
      "note" = "the T21 attack codes open at 1/4 on the 4th-level row (capture p. 33)",
    }, {
      "expr" = "m['dghT21Dmg'](7) != 100",
      "note" = "the T21 damage codes open at +1D on the 8th-level row (capture p. 33)",
    }, {
      "expr" = "m['dghT21OpenLocks'](0) != 25  or m['dghT21OpenLocks'](16) != 99  or m['dghT21Climb'](0) != 85",
      "note" = "the T21 thief-skill ladder - open locks 25 to 99, climb walls 85 to 99 (capture p. 33)",
    }, {
      "expr" = "m['dghMonkEspBasePct']() -m['dghMonkEspStepPct']() != 28",
      "note" = "the ESP ladder - 30 at 4th minus 2 per level beyond, so 28 at 5th (capture p. 33)",
    }, {
      "expr" = "m['dghMonkWeaponDmgStep']() != 2",
      "note" = "the weapon damage step - one extra point per two levels (capture p. 32)",
    }, {
      "expr" = "m['dghMonkHealMin']() != 2  or m['dghMonkHealMax']() != 5  or m['dghMonkHealStep']() != 1",
      "note" = "the heal ladder - 2-5 at 7th, one more per level beyond (capture p. 34)",
    }, {
      "expr" = "m['dghMonkMonasteryEights']() != 3  or m['dghMonkMonasteryBeyond']() != 1",
      "note" = "the monastery supports three 8th-level monks and one of each level beyond (capture p. 35)",
    }, {
      "expr" = "m['dghT21Traps'](0) != 20 or m['dghT21Traps'](1) != 25 or m['dghT21Traps'](2) != 30 or m['dghT21Traps'](3) != 35 or m['dghT21Traps'](4) != 40 or m['dghT21Traps'](5) != 45 or m['dghT21Traps'](6) != 50 or m['dghT21Traps'](7) != 55",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dghT21Traps'](8) != 60 or m['dghT21Traps'](9) != 65 or m['dghT21Traps'](10) != 70 or m['dghT21Traps'](11) != 75 or m['dghT21Traps'](12) != 80 or m['dghT21Traps'](13) != 85 or m['dghT21Traps'](14) != 90 or m['dghT21Traps'](15) != 95",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dghT21Traps'](16) != 99 or m['dghT21Traps'](17) != -99 or m['dghT21Silent'](0) != 15 or m['dghT21Silent'](1) != 21 or m['dghT21Silent'](2) != 27 or m['dghT21Silent'](3) != 33 or m['dghT21Silent'](4) != 40 or m['dghT21Silent'](5) != 47",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dghT21Silent'](6) != 55 or m['dghT21Silent'](7) != 62 or m['dghT21Silent'](8) != 70 or m['dghT21Silent'](9) != 78 or m['dghT21Silent'](10) != 86 or m['dghT21Silent'](11) != 94 or m['dghT21Silent'](12) != 99 or m['dghT21Silent'](13) != 99",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dghT21Silent'](14) != 99 or m['dghT21Silent'](15) != 99 or m['dghT21Silent'](16) != 99 or m['dghT21Silent'](17) != -99 or m['dghT21Hide'](0) != 10 or m['dghT21Hide'](1) != 15 or m['dghT21Hide'](2) != 20 or m['dghT21Hide'](3) != 25",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dghT21Hide'](4) != 31 or m['dghT21Hide'](5) != 37 or m['dghT21Hide'](6) != 43 or m['dghT21Hide'](7) != 49 or m['dghT21Hide'](8) != 56 or m['dghT21Hide'](9) != 63 or m['dghT21Hide'](10) != 70 or m['dghT21Hide'](11) != 77",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dghT21Hide'](12) != 85 or m['dghT21Hide'](13) != 93 or m['dghT21Hide'](14) != 99 or m['dghT21Hide'](15) != 99 or m['dghT21Hide'](16) != 99 or m['dghT21Hide'](17) != -99 or m['dghT21Hear'](0) != 10 or m['dghT21Hear'](1) != 10",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dghT21Hear'](2) != 15 or m['dghT21Hear'](3) != 15 or m['dghT21Hear'](4) != 20 or m['dghT21Hear'](5) != 20 or m['dghT21Hear'](6) != 25 or m['dghT21Hear'](7) != 25 or m['dghT21Hear'](8) != 30 or m['dghT21Hear'](9) != 30",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dghT21Hear'](10) != 35 or m['dghT21Hear'](11) != 35 or m['dghT21Hear'](12) != 40 or m['dghT21Hear'](13) != 40 or m['dghT21Hear'](14) != 50 or m['dghT21Hear'](15) != 50 or m['dghT21Hear'](16) != 55 or m['dghT21Hear'](17) != -99",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    } },
  "audit" = {
      "label" = "R621 OA monk audit",
      "comment" = "OA round eight (capture pp. 31-35): the monk - the ability minima, the discipline ladders of Tables 20 and 21, the ki power, the level powers, the monastery duel and the material restrictions",
    },
}
