-- oa622: promoted from rules/oaninja.h (the THE NINJA, printed capture pp. 35-39 - the OA ninja round);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 622,
  "prefix" = "oa622",
  "banner" = {
      "title" = "THE NINJA, printed capture pp. 35-39 - the OA ninja round",
      "provenance" = "census 544 -> 545.  verified against capture pp. 35-39 of the oa.pdf OCR session (single Mistral-OCR capture; cites are capture pages). Two cells settled against the 2018 print BEFORE pinning, per the settling doctrine: the T22 level-2 bound pins as 8,000 (the 2018 8,001 cell contradicts its own next-row floor of 8,001) and the T23 Dex-11 pockets cell pins as -5 (the 2018 05 reading lost its minus against the ladder). The T24 pole-vault column pins in half feet. OCR normalization: 15 points for the bushi class reads as 1-5 points; infraction reads as infravision; 1096 reads as 10 percent (prose only)  the gap census after this round: 43 closed, 192 open - the ninja boxes with Tables 22, 23 and 24 flip (census 544 -> 545); NEXT - R623: the Samurai, capture pp. 39-42, Table 25, prefix dgj (verify free), audit \"R623 OA samurai audit\", include after rules/oaninja.h",
    },
  "consts" = { {
      "name" = "dgiNinjaMinDex",
      "value" = 14,
      "comment" = "Ninja prose (capture p. 36): the Dexterity minimum",
    }, {
      "name" = "dgiNinjaMinCha",
      "value" = 14,
      "comment" = "Ninja prose (capture p. 36): the Charisma minimum",
    }, {
      "name" = "dgiNinjaMinInt",
      "value" = 15,
      "comment" = "Ninja prose (capture p. 36): the Intelligence minimum",
    }, {
      "name" = "dgiNinjaXpSplitDiv",
      "value" = 2,
      "comment" = "Ninja prose (capture p. 36): the experience points split between the two classes - normally exactly in half, the DM may skew",
    }, {
      "name" = "dgiNinjaHpMin",
      "value" = 1,
      "comment" = "Ninja prose (capture p. 36): 1-2 hit points for advancing a ninja level",
    }, {
      "name" = "dgiNinjaHpMax",
      "value" = 2,
      "comment" = "Ninja prose (capture p. 36): the hit-point upper bound per ninja level",
    }, {
      "name" = "dgiNinjaOtherHpDiv",
      "value" = 2,
      "comment" = "Ninja prose (capture p. 36): the other-class hit points - roll the normal die and divide the result by two",
    }, {
      "name" = "dgiNinjaExampleHpMin",
      "value" = 2,
      "comment" = "Ninja prose (capture p. 36): the printed 1st-level bushi/ninja example - from 2 hit points (1-5 for the bushi class plus 1-2 for the ninja class)",
    }, {
      "name" = "dgiNinjaExampleHpMax",
      "value" = 7,
      "comment" = "Ninja prose (capture p. 36): the bushi/ninja example upper bound (5 plus 2)",
    }, {
      "name" = "dgiNinjaSlots",
      "value" = 2,
      "comment" = "Ninja prose (capture p. 37): two proficiency slots at the beginning usable for the special ninja items",
    }, {
      "name" = "dgiNinjaNightingaleDiv",
      "value" = 2,
      "comment" = "Ninja prose (capture p. 37): nightingale floors reduce the move silently chance by one-half",
    }, {
      "name" = "dgiNinjaDisguiseSexDiv",
      "value" = 2,
      "comment" = "Ninja prose (capture p. 37): the opposite-sex disguise chance is reduced by half",
    }, {
      "name" = "dgiNinjaDisguisePersonDiv",
      "value" = 2,
      "comment" = "Ninja prose (capture p. 37): impersonating a specific person is one-half the normal disguise percentage",
    }, {
      "name" = "dgiNinjaDisguiseObserveDays",
      "value" = 30,
      "comment" = "Ninja prose (capture p. 37): one month of close observation restores the normal impersonation chance",
    }, {
      "name" = "dgiNinjaTightropeAngle",
      "value" = 45,
      "comment" = "Ninja prose (capture p. 37): tightrope walking works on surfaces angled at 45 degrees or less",
    }, {
      "name" = "dgiNinjaTightropeCheckFeet",
      "value" = 60,
      "comment" = "Ninja prose (capture p. 37): one tightrope check per 60 feet covered",
    }, {
      "name" = "dgiNinjaTightropeMove",
      "value" = 60,
      "comment" = "Ninja prose (capture p. 37): the tightrope movement rate, 60 feet per round",
    }, {
      "name" = "dgiNinjaTightropeBalanceBonus",
      "value" = 10,
      "comment" = "Ninja prose (capture p. 37): a balancing item increases the tightrope chance by 10 percent",
    }, {
      "name" = "dgiNinjaTightropeModerateWind",
      "value" = -10,
      "comment" = "Ninja prose (capture pp. 37-38): moderate winds lower the tightrope chance by 10 percent",
    }, {
      "name" = "dgiNinjaTightropeStrongWind",
      "value" = -20,
      "comment" = "Ninja prose (capture p. 38): strong winds lower the tightrope chance by 20 percent",
    }, {
      "name" = "dgiNinjaTightropeGustingWind",
      "value" = -30,
      "comment" = "Ninja prose (capture p. 38): gusting winds lower the tightrope chance by 30 percent",
    }, {
      "name" = "dgiNinjaTightropeFightPenalty",
      "value" = -5,
      "comment" = "Ninja prose (capture p. 38): fighting one-handed on a tightrope suffers -5 to hit plus an immediate fall check",
    }, {
      "name" = "dgiNinjaVaultRunFeet",
      "value" = 30,
      "comment" = "Ninja prose (capture p. 38): the pole vault needs a 30-foot running start",
    }, {
      "name" = "dgiNinjaVaultPoleExtraFeet",
      "value" = 4,
      "comment" = "Ninja prose (capture p. 38): the pole must be at least four feet longer than the character",
    }, {
      "name" = "dgiNinjaVaultObstacleReduction",
      "value" = 1,
      "comment" = "Ninja prose (capture p. 38): vaulting atop an obstacle reduces the maximum height by 1 foot",
    }, {
      "name" = "dgiNinjaVaultDistanceMult",
      "value" = 2,
      "comment" = "Ninja prose (capture p. 38): a distance vault covers twice the length of the pole",
    }, {
      "name" = "dgiNinjaEscapeRoundsDie",
      "value" = 10,
      "comment" = "Ninja prose (capture p. 38): the escape attempt takes 1d10 rounds",
    }, {
      "name" = "dgiNinjaOpenLocksPerLevel",
      "value" = 1,
      "comment" = "Ninja prose (capture p. 38): one try per lock per experience level",
    }, {
      "name" = "dgiNinjaKiBreathLevel",
      "value" = 1,
      "comment" = "Ninja prose (capture p. 39): the breath-holding ki at 1st level - rounds equal to the ninja level",
    }, {
      "name" = "dgiNinjaKiWaterLevel",
      "value" = 5,
      "comment" = "Ninja prose (capture p. 39): the water-walking ki at 5th level",
    }, {
      "name" = "dgiNinjaKiWaterFeetPerLevel",
      "value" = 5,
      "comment" = "Ninja prose (capture p. 39): the water walk crosses 5 feet of water per ninja level",
    }, {
      "name" = "dgiNinjaKiWaterMove",
      "value" = 30,
      "comment" = "Ninja prose (capture p. 39): the water-walking movement rate, 30 feet per round",
    }, {
      "name" = "dgiNinjaKiWaterPerDayMult",
      "value" = 1,
      "comment" = "Ninja prose (capture p. 39): the water-walking uses per day equal to the ninja level",
    }, {
      "name" = "dgiNinjaKiWallLevel",
      "value" = 12,
      "comment" = "Ninja prose (capture p. 39): the wall-passing ki at 12th level - the ultimate ninja power",
    }, {
      "name" = "dgiNinjaKiWallPrepRounds",
      "value" = 3,
      "comment" = "Ninja prose (capture p. 39): three rounds of concentration before entering the wall",
    }, {
      "name" = "dgiNinjaKiWallDurationRounds",
      "value" = 1,
      "comment" = "Ninja prose (capture p. 39): the wall pass lasts one round",
    }, {
      "name" = "dgiNinjaKiWallFeetPerLevel",
      "value" = 1,
      "comment" = "Ninja prose (capture p. 39): the wall pass moves 1 foot per experience level; not through by the end means death inside",
    }, {
      "name" = "dgiNinjaNukeXpMult",
      "value" = 2,
      "comment" = "Ninja prose (capture p. 39): a nukenin needs twice the normal experience points to advance as a ninja - the other class advances normally",
    }, {
      "name" = "dgiT22RowCount",
      "value" = 12,
      "comment" = "Table 22 (capture pp. 35-36): twelve rows, levels 1-12",
    }, {
      "name" = "dgiT22XpBeyond",
      "value" = 300000,
      "comment" = "Table 22 note (capture p. 36): 300,000 experience points are required for each level beyond 12th",
    }, {
      "name" = "dgiT22HpBeyond",
      "value" = 1,
      "comment" = "Table 22 (capture pp. 35-36): the hit-point column reads 1 for the 10th through 12th rows - 1 hp per level beyond 9th",
    }, {
      "name" = "dgiT23RowCount",
      "value" = 10,
      "comment" = "Table 23 (capture p. 36): ten rows, Dexterity scores 9 through 18",
    }, {
      "name" = "dgiT23FirstScore",
      "value" = 9,
      "comment" = "Table 23 (capture p. 36): the first ability score row is 9 - the row index is the score minus 9",
    }, {
      "name" = "dgiT24RowCount",
      "value" = 20,
      "comment" = "Table 24 (capture pp. 38-39): twenty rows, levels 1-20",
    }, {
      "name" = "dgiT24VaultHalfFoot",
      "value" = 2,
      "comment" = "Table 24 (capture pp. 38-39): the pole vault column is in half feet - the 8 through 18 prime cells are the printed heights times two",
    } },
  "bools" = { {
      "name" = "dgiNinjaHumanOnly",
      "value" = true,
      "comment" = "Ninja prose (capture p. 36): the ninja class is only open to human characters",
    }, {
      "name" = "dgiNinjaSplitClassOnly",
      "value" = true,
      "comment" = "Ninja prose (capture p. 36): not an independent class - the character must first qualify for the bushi, sohei, wu jen or yakuza class",
    }, {
      "name" = "dgiNinjaNoPrimeBonus",
      "value" = true,
      "comment" = "Ninja prose (capture p. 36): no prime requisite - the 10 percent bonus never applies to the ninja class even when earned in the other class",
    }, {
      "name" = "dgiNinjaNoConBonusHp",
      "value" = true,
      "comment" = "Ninja prose (capture p. 36): never the high-Constitution hit point bonus on the ninja rolls",
    }, {
      "name" = "dgiNinjaOtherHpRoundedUp",
      "value" = true,
      "comment" = "Ninja prose (capture p. 36): the halved other-class die is rounded up, then the Constitution bonus of that class applies",
    }, {
      "name" = "dgiNinjaThiefSaves",
      "value" = true,
      "comment" = "Ninja prose (capture p. 36): always the saving throw tables of thieves",
    }, {
      "name" = "dgiNinjaOtherCombatTable",
      "value" = true,
      "comment" = "Ninja prose (capture p. 36): the combat table of the other character class",
    }, {
      "name" = "dgiNinjaWeaponsNoHonorLoss",
      "value" = true,
      "comment" = "Ninja prose (capture p. 37): the special ninja weapons (Tables 49, 50 and 51) cost no honor, regardless of the other class",
    }, {
      "name" = "dgiNinjaCrossSlotHonorLoss",
      "value" = true,
      "comment" = "Ninja prose (capture p. 37): bushi/ninja who use other-class proficiencies to master ninja weapons lose honor",
    }, {
      "name" = "dgiNinjaOtherClassArmor",
      "value" = true,
      "comment" = "Ninja prose (capture p. 37): wears the armor of the other class, though certain ninja abilities may not work in armor",
    }, {
      "name" = "dgiNinjaMagicItemsUnion",
      "value" = true,
      "comment" = "Ninja prose (capture p. 37): any magical items of the other class plus the ninja-only items",
    }, {
      "name" = "dgiNinjaSilentNoMetal",
      "value" = true,
      "comment" = "Ninja prose (capture p. 37): move silently cannot be used while wearing metal armor",
    }, {
      "name" = "dgiNinjaHideWatched",
      "value" = true,
      "comment" = "Ninja prose (capture p. 37): hide in shadows cannot be used while someone is watching - the character always thinks he is hidden",
    }, {
      "name" = "dgiNinjaHideInfravision",
      "value" = true,
      "comment" = "Ninja prose (capture p. 37): near a heat source the skill works against infravision - the heat blinds it",
    }, {
      "name" = "dgiNinjaTrapsSmallOnly",
      "value" = true,
      "comment" = "Ninja prose (capture p. 37): find/remove traps works only for small traps, not large ones",
    }, {
      "name" = "dgiNinjaTrapsOneAttempt",
      "value" = true,
      "comment" = "Ninja prose (capture p. 37): only one attempt per character per trap - an equal chance to remove once found",
    }, {
      "name" = "dgiNinjaClimbChainMail",
      "value" = true,
      "comment" = "Ninja prose (capture p. 37): climb walls cannot be used in metal armor other than chain mail",
    }, {
      "name" = "dgiNinjaClimbMidpointCheck",
      "value" = true,
      "comment" = "Ninja prose (capture p. 37): one climb check at the midpoint - failure means the fall at the midpoint",
    }, {
      "name" = "dgiNinjaDisguiseClassOnly",
      "value" = true,
      "comment" = "Ninja prose (capture p. 37): disguise covers any general class of person of about the same height, weight and age",
    }, {
      "name" = "dgiNinjaDisguiseFailForever",
      "value" = true,
      "comment" = "Ninja prose (capture p. 37): once a specific-person impersonation fails, that person can never be impersonated",
    }, {
      "name" = "dgiNinjaAssassinatePlanned",
      "value" = true,
      "comment" = "Ninja prose (capture p. 37): the DMG assassination tables, carefully planned, DM-adjusted - not a combat skill, unusable in melee",
    }, {
      "name" = "dgiNinjaVaultNoMetal",
      "value" = true,
      "comment" = "Ninja prose (capture p. 38): no metal armor when pole vaulting",
    }, {
      "name" = "dgiNinjaFallChainMail",
      "value" = true,
      "comment" = "Ninja prose (capture p. 38): the safe fall allows no metal armor other than chain mail",
    }, {
      "name" = "dgiNinjaFallVerticalSurface",
      "value" = true,
      "comment" = "Ninja prose (capture p. 38): the safe fall needs a reachable vertical surface; beyond the stated distance the full damage applies",
    }, {
      "name" = "dgiNinjaEscapeOneAttempt",
      "value" = true,
      "comment" = "Ninja prose (capture p. 38): one escape attempt only - with guards present it is easily thwarted",
    }, {
      "name" = "dgiNinjaOpenLocksLockedForever",
      "value" = true,
      "comment" = "Ninja prose (capture p. 38): a failed lock never opens - the retry comes at the next experience level",
    }, {
      "name" = "dgiNinjaBackstabUnnoticed",
      "value" = true,
      "comment" = "Ninja prose (capture p. 38): the backstab strikes unnoticed from behind - the usual Strength, class and magic modifiers apply before the multiplier",
    }, {
      "name" = "dgiNinjaKiBreathOnceDaily",
      "value" = true,
      "comment" = "Ninja prose (capture p. 39): the breath-holding ki is usable only once per day",
    }, {
      "name" = "dgiNinjaKiWaterBrokenByInjury",
      "value" = true,
      "comment" = "Ninja prose (capture p. 39): any injury breaks the water-walking concentration",
    }, {
      "name" = "dgiNinjaKiWallCostsAllKi",
      "value" = true,
      "comment" = "Ninja prose (capture p. 39): the wall pass needs the entire day ki - disturbance loses this and all other ki powers for the day",
    }, {
      "name" = "dgiNinjaFamilyRule",
      "value" = true,
      "comment" = "Ninja prose (capture p. 39): ruled absolutely by the head of the family - disobedience brings assassination attempts until the character dies or slays the head",
    }, {
      "name" = "dgiNinjaMissionsFromHead",
      "value" = true,
      "comment" = "Ninja prose (capture p. 39): all missions come from the head of the family - the DM may forbid missions against player characters",
    }, {
      "name" = "dgiNinjaIdentityCost",
      "value" = true,
      "comment" = "Ninja prose (capture p. 39): discovery of the true identity costs honor - others may know he is a ninja but never who he is",
    }, {
      "name" = "dgiNinjaMissionRetryable",
      "value" = true,
      "comment" = "Ninja prose (capture p. 39): failing a mission costs honor but the mission can be attempted again",
    }, {
      "name" = "dgiNinjaMissionRefusalAllHonor",
      "value" = true,
      "comment" = "Ninja prose (capture p. 39): refusing a mission loses all honor - defiance of the head of the family",
    }, {
      "name" = "dgiNinjaHonorAboveFamily",
      "value" = true,
      "comment" = "Ninja prose (capture p. 39): the ninja must maintain his honor above the family honor - the ninja honor measures obedience and loyalty",
    }, {
      "name" = "dgiNinjaNukeDeathOrNukenin",
      "value" = true,
      "comment" = "Ninja prose (capture p. 39): failing that carries the same punishment as disobedience, death - a survivor is a nukenin",
    } },
  "switches" = { {
      "name" = "dgiT22XpMax",
      "values" = { 4000, 8000, 15000, 30000, 60000, 120000, 240000, 500000, 1000000, 1300000, 1600000, 1900000 },
      "default" = -99,
      "comment" = "the experience column: the upper xp bound of each level, 4,000 at 1st to 1,900,000 at 12th (capture pp. 35-36).",
    }, {
      "name" = "dgiT22HpMax",
      "values" = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 },
      "default" = -99,
      "comment" = "the hit points per level column: the printed 1-2 range through 9th, then 1 for the 10th through 12th rows (capture pp. 35-36).",
    }, {
      "name" = "dgiT23Pockets",
      "values" = { -15, -10, -5, 0, 0, 0, 0, 0, 5, 10 },
      "default" = -99,
      "comment" = "the picking pockets column: -15 percent at Dex 9 to +10 at 18 (capture p. 36).",
    }, {
      "name" = "dgiT23Traps",
      "values" = { -10, -10, -5, 0, 0, 0, 0, 0, 0, 5 },
      "default" = -99,
      "comment" = "the locating and removing traps column: -10 percent at Dex 9 to +5 at 18 (capture p. 36).",
    }, {
      "name" = "dgiT23Silent",
      "values" = { -20, -15, -10, -5, 0, 0, 0, 0, 5, 10 },
      "default" = -99,
      "comment" = "the moving silently column: -20 percent at Dex 9 to +10 at 18 (capture p. 36).",
    }, {
      "name" = "dgiT23Hide",
      "values" = { -10, -5, 0, 0, 0, 0, 0, 0, 5, 10 },
      "default" = -99,
      "comment" = "the hiding in shadows column: -10 percent at Dex 9 to +10 at 18 (capture p. 36).",
    }, {
      "name" = "dgiT23Locks",
      "values" = { -15, -10, -5, 0, 0, 0, 0, 0, 5, 10 },
      "default" = -99,
      "comment" = "the open locks column: -15 percent at Dex 9 to +10 at 18 (capture p. 36).",
    }, {
      "name" = "dgiT24Hide",
      "values" = { 10, 15, 20, 25, 31, 37, 43, 49, 56, 63, 70, 77, 85, 93, 94, 95, 96, 97, 98, 99 },
      "default" = -99,
      "comment" = "the hide in shadows column: 10 percent at 1st to 99 at 20th (capture pp. 38-39).",
    }, {
      "name" = "dgiT24Silent",
      "values" = { 15, 21, 27, 33, 40, 47, 55, 62, 70, 78, 86, 94, 95, 96, 97, 98, 99, 99, 99, 99 },
      "default" = -99,
      "comment" = "the move silently column: 15 percent at 1st to 99 from 17th (capture pp. 38-39).",
    }, {
      "name" = "dgiT24Traps",
      "values" = { 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 95, 95, 95, 95 },
      "default" = -99,
      "comment" = "the find and remove traps column: 20 percent at 1st to 95 from 13th (capture pp. 38-39).",
    }, {
      "name" = "dgiT24Climb",
      "values" = { 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 99, 99, 99, 99, 99 },
      "default" = -99,
      "comment" = "the climb walls column: 85 percent at 1st to 99 from 15th (capture pp. 38-39).",
    }, {
      "name" = "dgiT24Disguise",
      "values" = { 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96 },
      "default" = -99,
      "comment" = "the disguise column: 20 percent at 1st to 96 at 20th (capture pp. 38-39).",
    }, {
      "name" = "dgiT24Locks",
      "values" = { 25, 29, 33, 37, 42, 47, 52, 57, 62, 67, 72, 77, 82, 87, 92, 97, 99, 99, 99, 99 },
      "default" = -99,
      "comment" = "the open locks column: 25 percent at 1st to 99 from 17th (capture pp. 38-39).",
    }, {
      "name" = "dgiT24Tightrope",
      "values" = { 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 96, 97, 98, 99 },
      "default" = -99,
      "comment" = "the tightrope walk column: 20 percent at 1st to 99 at 20th (capture pp. 38-39).",
    }, {
      "name" = "dgiT24Vault",
      "values" = { 16, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36 },
      "default" = -99,
      "comment" = "the pole vault column in half feet: 16 (8 feet) at 1st to 36 (18 feet) at 20th (capture pp. 38-39).",
    }, {
      "name" = "dgiT24Fall",
      "values" = { 0, 0, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95 },
      "default" = -99,
      "comment" = "the fall column: 0 feet at 1st and 2nd, then 10 at 3rd climbing 5 per level to 95 at 20th (capture pp. 38-39).",
    }, {
      "name" = "dgiT24Escape",
      "values" = { 10, 14, 18, 22, 26, 30, 34, 38, 42, 46, 50, 54, 58, 62, 66, 70, 74, 78, 82, 86 },
      "default" = -99,
      "comment" = "the escape column: 10 percent at 1st to 86 at 20th (capture pp. 38-39).",
    }, {
      "name" = "dgiT24Backstab",
      "values" = { 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5 },
      "default" = -99,
      "comment" = "the backstab multiplier column: x2 at 1st, x3 at 5th, x4 at 10th, x5 at 20th (capture pp. 38-39).",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dgiNinjaMinDex']() != 14  or m['dgiNinjaMinCha']() != 14  or m['dgiNinjaMinInt']() != 15  or m['dgiNinjaXpSplitDiv']() != 2  or m['dgiNinjaHpMin']() != 1  or m['dgiNinjaHpMax']() != 2  or m['dgiNinjaOtherHpDiv']() != 2  or m['dgiNinjaExampleHpMin']() != 2  or m['dgiNinjaExampleHpMax']() != 7  or m['dgiNinjaSlots']() != 2  or m['dgiNinjaNightingaleDiv']() != 2  or m['dgiNinjaTightropeAngle']() != 45  or m['dgiNinjaTightropeCheckFeet']() != 60  or m['dgiNinjaTightropeMove']() != 60  or m['dgiNinjaTightropeBalanceBonus']() != 10  or m['dgiNinjaTightropeModerateWind']() != -10  or m['dgiNinjaTightropeStrongWind']() != -20  or m['dgiNinjaTightropeGustingWind']() != -30  or m['dgiNinjaTightropeFightPenalty']() != -5  or m['dgiNinjaVaultRunFeet']() != 30  or m['dgiNinjaVaultPoleExtraFeet']() != 4  or m['dgiNinjaVaultObstacleReduction']() != 1  or m['dgiNinjaVaultDistanceMult']() != 2  or m['dgiNinjaEscapeRoundsDie']() != 10  or m['dgiNinjaOpenLocksPerLevel']() != 1  or m['dgiNinjaDisguiseSexDiv']() != 2  or m['dgiNinjaDisguisePersonDiv']() != 2  or m['dgiNinjaDisguiseObserveDays']() != 30  or m['dgiNinjaKiBreathLevel']() != 1  or m['dgiNinjaKiWaterLevel']() != 5  or m['dgiNinjaKiWaterFeetPerLevel']() != 5  or m['dgiNinjaKiWaterMove']() != 30  or m['dgiNinjaKiWaterPerDayMult']() != 1  or m['dgiNinjaKiWallLevel']() != 12  or m['dgiNinjaKiWallPrepRounds']() != 3  or m['dgiNinjaKiWallDurationRounds']() != 1  or m['dgiNinjaKiWallFeetPerLevel']() != 1  or m['dgiNinjaNukeXpMult']() != 2  or m['dgiT22RowCount']() != 12  or m['dgiT22XpBeyond']() != 300000  or m['dgiT22HpBeyond']() != 1  or m['dgiT23RowCount']() != 10  or m['dgiT23FirstScore']() != 9  or m['dgiT24RowCount']() != 20  or m['dgiT24VaultHalfFoot']() != 2  or  m['dgiNinjaHumanOnly']() != 1  or  m['dgiNinjaSplitClassOnly']() != 1  or  m['dgiNinjaNoPrimeBonus']() != 1  or  m['dgiNinjaNoConBonusHp']() != 1  or  m['dgiNinjaOtherHpRoundedUp']() != 1  or  m['dgiNinjaThiefSaves']() != 1  or  m['dgiNinjaOtherCombatTable']() != 1  or  m['dgiNinjaWeaponsNoHonorLoss']() != 1  or  m['dgiNinjaCrossSlotHonorLoss']() != 1  or  m['dgiNinjaOtherClassArmor']() != 1  or  m['dgiNinjaMagicItemsUnion']() != 1  or  m['dgiNinjaSilentNoMetal']() != 1  or  m['dgiNinjaHideWatched']() != 1  or  m['dgiNinjaHideInfravision']() != 1  or  m['dgiNinjaTrapsSmallOnly']() != 1  or  m['dgiNinjaTrapsOneAttempt']() != 1  or  m['dgiNinjaClimbChainMail']() != 1  or  m['dgiNinjaClimbMidpointCheck']() != 1  or  m['dgiNinjaDisguiseClassOnly']() != 1  or  m['dgiNinjaDisguiseFailForever']() != 1  or  m['dgiNinjaAssassinatePlanned']() != 1  or  m['dgiNinjaVaultNoMetal']() != 1  or  m['dgiNinjaFallChainMail']() != 1  or  m['dgiNinjaFallVerticalSurface']() != 1  or  m['dgiNinjaEscapeOneAttempt']() != 1  or  m['dgiNinjaOpenLocksLockedForever']() != 1  or  m['dgiNinjaBackstabUnnoticed']() != 1  or  m['dgiNinjaKiBreathOnceDaily']() != 1  or  m['dgiNinjaKiWaterBrokenByInjury']() != 1  or  m['dgiNinjaKiWallCostsAllKi']() != 1  or  m['dgiNinjaFamilyRule']() != 1  or  m['dgiNinjaIdentityCost']() != 1  or  m['dgiNinjaMissionRetryable']() != 1  or  m['dgiNinjaMissionRefusalAllHonor']() != 1  or  m['dgiNinjaHonorAboveFamily']() != 1  or  m['dgiNinjaNukeDeathOrNukenin']() != 1  or  m['dgiNinjaMissionsFromHead']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dgiNinjaMinDex']() != 14",
      "note" = "the dgiNinjaMinDex pin",
    }, {
      "expr" = "m['dgiNinjaMinCha']() != 14",
      "note" = "the dgiNinjaMinCha pin",
    }, {
      "expr" = "m['dgiNinjaMinInt']() != 15",
      "note" = "the dgiNinjaMinInt pin",
    }, {
      "expr" = "m['dgiNinjaXpSplitDiv']() != 2",
      "note" = "the dgiNinjaXpSplitDiv pin",
    }, {
      "expr" = "m['dgiNinjaHpMin']() != 1",
      "note" = "the dgiNinjaHpMin pin",
    }, {
      "expr" = "m['dgiNinjaHpMax']() != 2",
      "note" = "the dgiNinjaHpMax pin",
    }, {
      "expr" = "m['dgiNinjaOtherHpDiv']() != 2",
      "note" = "the dgiNinjaOtherHpDiv pin",
    }, {
      "expr" = "m['dgiNinjaExampleHpMin']() != 2",
      "note" = "the dgiNinjaExampleHpMin pin",
    }, {
      "expr" = "m['dgiNinjaExampleHpMax']() != 7",
      "note" = "the dgiNinjaExampleHpMax pin",
    }, {
      "expr" = "m['dgiNinjaSlots']() != 2",
      "note" = "the dgiNinjaSlots pin",
    }, {
      "expr" = "m['dgiNinjaNightingaleDiv']() != 2",
      "note" = "the dgiNinjaNightingaleDiv pin",
    }, {
      "expr" = "m['dgiNinjaTightropeAngle']() != 45",
      "note" = "the dgiNinjaTightropeAngle pin",
    }, {
      "expr" = "m['dgiNinjaTightropeCheckFeet']() != 60",
      "note" = "the dgiNinjaTightropeCheckFeet pin",
    }, {
      "expr" = "m['dgiNinjaTightropeMove']() != 60",
      "note" = "the dgiNinjaTightropeMove pin",
    }, {
      "expr" = "m['dgiNinjaTightropeBalanceBonus']() != 10",
      "note" = "the dgiNinjaTightropeBalanceBonus pin",
    }, {
      "expr" = "m['dgiNinjaTightropeModerateWind']() != -10",
      "note" = "the dgiNinjaTightropeModerateWind pin",
    }, {
      "expr" = "m['dgiNinjaTightropeStrongWind']() != -20",
      "note" = "the dgiNinjaTightropeStrongWind pin",
    }, {
      "expr" = "m['dgiNinjaTightropeGustingWind']() != -30",
      "note" = "the dgiNinjaTightropeGustingWind pin",
    }, {
      "expr" = "m['dgiNinjaTightropeFightPenalty']() != -5",
      "note" = "the dgiNinjaTightropeFightPenalty pin",
    }, {
      "expr" = "m['dgiNinjaVaultRunFeet']() != 30",
      "note" = "the dgiNinjaVaultRunFeet pin",
    }, {
      "expr" = "m['dgiNinjaVaultPoleExtraFeet']() != 4",
      "note" = "the dgiNinjaVaultPoleExtraFeet pin",
    }, {
      "expr" = "m['dgiNinjaVaultObstacleReduction']() != 1",
      "note" = "the dgiNinjaVaultObstacleReduction pin",
    }, {
      "expr" = "m['dgiNinjaVaultDistanceMult']() != 2",
      "note" = "the dgiNinjaVaultDistanceMult pin",
    }, {
      "expr" = "m['dgiNinjaEscapeRoundsDie']() != 10",
      "note" = "the dgiNinjaEscapeRoundsDie pin",
    }, {
      "expr" = "m['dgiNinjaOpenLocksPerLevel']() != 1",
      "note" = "the dgiNinjaOpenLocksPerLevel pin",
    }, {
      "expr" = "m['dgiNinjaDisguiseSexDiv']() != 2",
      "note" = "the dgiNinjaDisguiseSexDiv pin",
    }, {
      "expr" = "m['dgiNinjaDisguisePersonDiv']() != 2",
      "note" = "the dgiNinjaDisguisePersonDiv pin",
    }, {
      "expr" = "m['dgiNinjaDisguiseObserveDays']() != 30",
      "note" = "the dgiNinjaDisguiseObserveDays pin",
    }, {
      "expr" = "m['dgiNinjaKiBreathLevel']() != 1",
      "note" = "the dgiNinjaKiBreathLevel pin",
    }, {
      "expr" = "m['dgiNinjaKiWaterLevel']() != 5",
      "note" = "the dgiNinjaKiWaterLevel pin",
    }, {
      "expr" = "m['dgiNinjaKiWaterFeetPerLevel']() != 5",
      "note" = "the dgiNinjaKiWaterFeetPerLevel pin",
    }, {
      "expr" = "m['dgiNinjaKiWaterMove']() != 30",
      "note" = "the dgiNinjaKiWaterMove pin",
    }, {
      "expr" = "m['dgiNinjaKiWaterPerDayMult']() != 1",
      "note" = "the dgiNinjaKiWaterPerDayMult pin",
    }, {
      "expr" = "m['dgiNinjaKiWallLevel']() != 12",
      "note" = "the dgiNinjaKiWallLevel pin",
    }, {
      "expr" = "m['dgiNinjaKiWallPrepRounds']() != 3",
      "note" = "the dgiNinjaKiWallPrepRounds pin",
    }, {
      "expr" = "m['dgiNinjaKiWallDurationRounds']() != 1",
      "note" = "the dgiNinjaKiWallDurationRounds pin",
    }, {
      "expr" = "m['dgiNinjaKiWallFeetPerLevel']() != 1",
      "note" = "the dgiNinjaKiWallFeetPerLevel pin",
    }, {
      "expr" = "m['dgiNinjaNukeXpMult']() != 2",
      "note" = "the dgiNinjaNukeXpMult pin",
    }, {
      "expr" = "m['dgiT22RowCount']() != 12",
      "note" = "the dgiT22RowCount pin",
    }, {
      "expr" = "m['dgiT22XpBeyond']() != 300000",
      "note" = "the dgiT22XpBeyond pin",
    }, {
      "expr" = "m['dgiT22HpBeyond']() != 1",
      "note" = "the dgiT22HpBeyond pin",
    }, {
      "expr" = "m['dgiT23RowCount']() != 10",
      "note" = "the dgiT23RowCount pin",
    }, {
      "expr" = "m['dgiT23FirstScore']() != 9",
      "note" = "the dgiT23FirstScore pin",
    }, {
      "expr" = "m['dgiT24RowCount']() != 20",
      "note" = "the dgiT24RowCount pin",
    }, {
      "expr" = "m['dgiT24VaultHalfFoot']() != 2",
      "note" = "the dgiT24VaultHalfFoot pin",
    }, {
      "expr" = "m['dgiNinjaHumanOnly']() != 1",
      "note" = "the dgiNinjaHumanOnly pin",
    }, {
      "expr" = "m['dgiNinjaSplitClassOnly']() != 1",
      "note" = "the dgiNinjaSplitClassOnly pin",
    }, {
      "expr" = "m['dgiNinjaNoPrimeBonus']() != 1",
      "note" = "the dgiNinjaNoPrimeBonus pin",
    }, {
      "expr" = "m['dgiNinjaNoConBonusHp']() != 1",
      "note" = "the dgiNinjaNoConBonusHp pin",
    }, {
      "expr" = "m['dgiNinjaOtherHpRoundedUp']() != 1",
      "note" = "the dgiNinjaOtherHpRoundedUp pin",
    }, {
      "expr" = "m['dgiNinjaThiefSaves']() != 1",
      "note" = "the dgiNinjaThiefSaves pin",
    }, {
      "expr" = "m['dgiNinjaOtherCombatTable']() != 1",
      "note" = "the dgiNinjaOtherCombatTable pin",
    }, {
      "expr" = "m['dgiNinjaWeaponsNoHonorLoss']() != 1",
      "note" = "the dgiNinjaWeaponsNoHonorLoss pin",
    }, {
      "expr" = "m['dgiNinjaCrossSlotHonorLoss']() != 1",
      "note" = "the dgiNinjaCrossSlotHonorLoss pin",
    }, {
      "expr" = "m['dgiNinjaOtherClassArmor']() != 1",
      "note" = "the dgiNinjaOtherClassArmor pin",
    }, {
      "expr" = "m['dgiNinjaMagicItemsUnion']() != 1",
      "note" = "the dgiNinjaMagicItemsUnion pin",
    }, {
      "expr" = "m['dgiNinjaSilentNoMetal']() != 1",
      "note" = "the dgiNinjaSilentNoMetal pin",
    }, {
      "expr" = "m['dgiNinjaHideWatched']() != 1",
      "note" = "the dgiNinjaHideWatched pin",
    }, {
      "expr" = "m['dgiNinjaHideInfravision']() != 1",
      "note" = "the dgiNinjaHideInfravision pin",
    }, {
      "expr" = "m['dgiNinjaTrapsSmallOnly']() != 1",
      "note" = "the dgiNinjaTrapsSmallOnly pin",
    }, {
      "expr" = "m['dgiNinjaTrapsOneAttempt']() != 1",
      "note" = "the dgiNinjaTrapsOneAttempt pin",
    }, {
      "expr" = "m['dgiNinjaClimbChainMail']() != 1",
      "note" = "the dgiNinjaClimbChainMail pin",
    }, {
      "expr" = "m['dgiNinjaClimbMidpointCheck']() != 1",
      "note" = "the dgiNinjaClimbMidpointCheck pin",
    }, {
      "expr" = "m['dgiNinjaDisguiseClassOnly']() != 1",
      "note" = "the dgiNinjaDisguiseClassOnly pin",
    }, {
      "expr" = "m['dgiNinjaDisguiseFailForever']() != 1",
      "note" = "the dgiNinjaDisguiseFailForever pin",
    }, {
      "expr" = "m['dgiNinjaAssassinatePlanned']() != 1",
      "note" = "the dgiNinjaAssassinatePlanned pin",
    }, {
      "expr" = "m['dgiNinjaVaultNoMetal']() != 1",
      "note" = "the dgiNinjaVaultNoMetal pin",
    }, {
      "expr" = "m['dgiNinjaFallChainMail']() != 1",
      "note" = "the dgiNinjaFallChainMail pin",
    }, {
      "expr" = "m['dgiNinjaFallVerticalSurface']() != 1",
      "note" = "the dgiNinjaFallVerticalSurface pin",
    }, {
      "expr" = "m['dgiNinjaEscapeOneAttempt']() != 1",
      "note" = "the dgiNinjaEscapeOneAttempt pin",
    }, {
      "expr" = "m['dgiNinjaOpenLocksLockedForever']() != 1",
      "note" = "the dgiNinjaOpenLocksLockedForever pin",
    }, {
      "expr" = "m['dgiNinjaBackstabUnnoticed']() != 1",
      "note" = "the dgiNinjaBackstabUnnoticed pin",
    }, {
      "expr" = "m['dgiNinjaKiBreathOnceDaily']() != 1",
      "note" = "the dgiNinjaKiBreathOnceDaily pin",
    }, {
      "expr" = "m['dgiNinjaKiWaterBrokenByInjury']() != 1",
      "note" = "the dgiNinjaKiWaterBrokenByInjury pin",
    }, {
      "expr" = "m['dgiNinjaKiWallCostsAllKi']() != 1",
      "note" = "the dgiNinjaKiWallCostsAllKi pin",
    }, {
      "expr" = "m['dgiNinjaFamilyRule']() != 1",
      "note" = "the dgiNinjaFamilyRule pin",
    }, {
      "expr" = "m['dgiNinjaIdentityCost']() != 1",
      "note" = "the dgiNinjaIdentityCost pin",
    }, {
      "expr" = "m['dgiNinjaMissionRetryable']() != 1",
      "note" = "the dgiNinjaMissionRetryable pin",
    }, {
      "expr" = "m['dgiNinjaMissionRefusalAllHonor']() != 1",
      "note" = "the dgiNinjaMissionRefusalAllHonor pin",
    }, {
      "expr" = "m['dgiNinjaHonorAboveFamily']() != 1",
      "note" = "the dgiNinjaHonorAboveFamily pin",
    }, {
      "expr" = "m['dgiNinjaNukeDeathOrNukenin']() != 1",
      "note" = "the dgiNinjaNukeDeathOrNukenin pin",
    }, {
      "expr" = "m['dgiNinjaMissionsFromHead']() != 1",
      "note" = "the dgiNinjaMissionsFromHead pin",
    }, {
      "expr" = "m['dgiT22XpMax'](0) != 4000  or m['dgiT22HpMax'](0) != 2",
      "note" = "the T22 first row - 4,000 xp, the 1-2 hp range (capture p. 35)",
    }, {
      "expr" = "m['dgiT22XpMax'](1) != 8000  or m['dgiT22XpMax'](2) != 15000",
      "note" = "the T22 level-2 bound settled at 8,000 - the 2018 print 8,001 cell contradicts the next-row floor (capture p. 35)",
    }, {
      "expr" = "m['dgiT22HpMax'](9) != 1  or m['dgiT22HpMax'](11) != 1  or m['dgiT22XpMax'](11) != 1900000  or m['dgiT22HpBeyond']() != 1",
      "note" = "the T22 beyond-9th rows - hp 1 and the 1,900,000 cap (capture p. 36)",
    }, {
      "expr" = "m['dgiT23Pockets'](0) != -15  or m['dgiT23Silent'](0) != -20  or m['dgiT23Locks'](0) != -15",
      "note" = "the T23 Dex-9 row - the five penalties (capture p. 36)",
    }, {
      "expr" = "m['dgiT23Pockets'](2) != -5  or m['dgiT23Pockets'](3) != 0",
      "note" = "the T23 Dex-11 pockets cell settled at -5 - the 2018 print 05 reading lost the minus (capture p. 36)",
    }, {
      "expr" = "m['dgiT23Pockets'](9) != 10  or m['dgiT23Traps'](9) != 5  or m['dgiT23Silent'](9) != 10  or m['dgiT23Hide'](9) != 10  or m['dgiT23Locks'](9) != 10",
      "note" = "the T23 Dex-18 row - the five bonuses (capture p. 36)",
    }, {
      "expr" = "m['dgiT24Hide'](0) != 10  or m['dgiT24Climb'](0) != 85  or m['dgiT24Vault'](0) != 16  or m['dgiT24Fall'](0) != 0  or m['dgiT24Backstab'](0) != 2",
      "note" = "the T24 1st-level row - the eleven capabilities (capture p. 38)",
    }, {
      "expr" = "m['dgiT24Hide'](19) != 99  or m['dgiT24Disguise'](19) != 96  or m['dgiT24Vault'](19) != 36  or m['dgiT24Fall'](19) != 95  or m['dgiT24Escape'](19) != 86  or m['dgiT24Backstab'](19) != 5",
      "note" = "the T24 capstone - the 20th-level row with the x5 backstab (capture p. 39)",
    }, {
      "expr" = "m['dgiT24Backstab'](4) != 3  or m['dgiT24Backstab'](9) != 4",
      "note" = "the T24 backstab ladder - x3 at 5th, x4 at 10th (capture pp. 38-39)",
    }, {
      "expr" = "m['dgiT24Vault'](2) != 19  or m['dgiT24VaultHalfFoot']() != 2",
      "note" = "the T24 pole-vault ladder - the 9.5 prime cell at 3rd is 19 half feet (capture p. 38)",
    }, {
      "expr" = "m['dgiT24Fall'](1) != 0  or m['dgiT24Fall'](2) != 10",
      "note" = "the T24 fall ladder opens at 10 feet on the 3rd-level row (capture p. 38)",
    }, {
      "expr" = "m['dgiNinjaExampleHpMin']() != 2  or m['dgiNinjaExampleHpMax']() != 7  or m['dgiNinjaOtherHpDiv']() != 2",
      "note" = "the bushi/ninja example - 2 to 7 hit points, the 1-5 halved die plus 1-2 (capture p. 36)",
    }, {
      "expr" = "m['dgiT24Silent'](0) != 15 or m['dgiT24Silent'](1) != 21 or m['dgiT24Silent'](2) != 27 or m['dgiT24Silent'](3) != 33 or m['dgiT24Silent'](4) != 40 or m['dgiT24Silent'](5) != 47 or m['dgiT24Silent'](6) != 55 or m['dgiT24Silent'](7) != 62",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgiT24Silent'](8) != 70 or m['dgiT24Silent'](9) != 78 or m['dgiT24Silent'](10) != 86 or m['dgiT24Silent'](11) != 94 or m['dgiT24Silent'](12) != 95 or m['dgiT24Silent'](13) != 96 or m['dgiT24Silent'](14) != 97 or m['dgiT24Silent'](15) != 98",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgiT24Silent'](16) != 99 or m['dgiT24Silent'](17) != 99 or m['dgiT24Silent'](18) != 99 or m['dgiT24Silent'](19) != 99 or m['dgiT24Silent'](20) != -99 or m['dgiT24Traps'](0) != 20 or m['dgiT24Traps'](1) != 25 or m['dgiT24Traps'](2) != 30",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgiT24Traps'](3) != 35 or m['dgiT24Traps'](4) != 40 or m['dgiT24Traps'](5) != 45 or m['dgiT24Traps'](6) != 50 or m['dgiT24Traps'](7) != 55 or m['dgiT24Traps'](8) != 60 or m['dgiT24Traps'](9) != 65 or m['dgiT24Traps'](10) != 70",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgiT24Traps'](11) != 75 or m['dgiT24Traps'](12) != 80 or m['dgiT24Traps'](13) != 85 or m['dgiT24Traps'](14) != 90 or m['dgiT24Traps'](15) != 95 or m['dgiT24Traps'](16) != 95 or m['dgiT24Traps'](17) != 95 or m['dgiT24Traps'](18) != 95",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgiT24Traps'](19) != 95 or m['dgiT24Traps'](20) != -99 or m['dgiT24Locks'](0) != 25 or m['dgiT24Locks'](1) != 29 or m['dgiT24Locks'](2) != 33 or m['dgiT24Locks'](3) != 37 or m['dgiT24Locks'](4) != 42 or m['dgiT24Locks'](5) != 47",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgiT24Locks'](6) != 52 or m['dgiT24Locks'](7) != 57 or m['dgiT24Locks'](8) != 62 or m['dgiT24Locks'](9) != 67 or m['dgiT24Locks'](10) != 72 or m['dgiT24Locks'](11) != 77 or m['dgiT24Locks'](12) != 82 or m['dgiT24Locks'](13) != 87",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgiT24Locks'](14) != 92 or m['dgiT24Locks'](15) != 97 or m['dgiT24Locks'](16) != 99 or m['dgiT24Locks'](17) != 99 or m['dgiT24Locks'](18) != 99 or m['dgiT24Locks'](19) != 99 or m['dgiT24Locks'](20) != -99 or m['dgiT24Tightrope'](0) != 20",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgiT24Tightrope'](1) != 25 or m['dgiT24Tightrope'](2) != 30 or m['dgiT24Tightrope'](3) != 35 or m['dgiT24Tightrope'](4) != 40 or m['dgiT24Tightrope'](5) != 45 or m['dgiT24Tightrope'](6) != 50 or m['dgiT24Tightrope'](7) != 55 or m['dgiT24Tightrope'](8) != 60",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgiT24Tightrope'](9) != 65 or m['dgiT24Tightrope'](10) != 70 or m['dgiT24Tightrope'](11) != 75 or m['dgiT24Tightrope'](12) != 80 or m['dgiT24Tightrope'](13) != 85 or m['dgiT24Tightrope'](14) != 90 or m['dgiT24Tightrope'](15) != 95 or m['dgiT24Tightrope'](16) != 96",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgiT24Tightrope'](17) != 97 or m['dgiT24Tightrope'](18) != 98 or m['dgiT24Tightrope'](19) != 99 or m['dgiT24Tightrope'](20) != -99",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    } },
  "audit" = {
      "label" = "R622 OA ninja audit",
      "comment" = "OA round nine (capture pp. 35-39): the ninja - the dual-class doctrine, the capability ladders of Tables 22, 23 and 24, the ki powers, the honor mechanics and the nukenin",
    },
}
