-- wnf: promoted from tools/spec_r462.json (the R462: the WSG FOOD AND WATER chapter opener - going without food (Table 28), going without water, the effects on animals, the minimum daily requirement of food and the minimum daily requirement of water (Table 29), printed pp. 50-53.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 462,
  "prefix" = "wnf",
  "banner" = {
      "title" = "R462: the WSG FOOD AND WATER chapter opener - going without food (Table 28), going without water, the effects on animals, the minimum daily requirement of food and the minimum daily requirement of water (Table 29), printed pp. 50-53.",
      "provenance" = "Ground truth three-way: the user Drive PDF OCR (Wilderness Survival Guide.pdf pp. 50-53) vs the archive djvu word layer vs IIIF eye-reads of leaves 0050-0053 - Table 28 settled on the image (the djvu garbles the 4/5/6/7/8/10 ladder), the +2/+4 example modifiers, the 1.5-times animal multiple, the cumulative -4 recovery modifier and the water encumbrance sentence eye-read; Table 29 clean in both text layers.",
      "sentinel" = "All fractions pinned cross-multiplied (division-free); the book examples (Str 12 + Con 14 = 26, the +2/+4 checks, the ration packs, the 56-pint cubic foot) are audit examples.",
    },
  "consts" = { {
      "name" = "wnfCheckEveryHours",
      "value" = 12,
      "comment" = "past tolerance: a Str or Con check (higher score) every 12 hours to remain unaffected",
    }, {
      "name" = "wnfCheckIncumPerCheck",
      "value" = 1,
      "comment" = "every check after the first: a cumulative +1 on the die roll (+1 second, +2 third, and so on)",
    }, {
      "name" = "wnfWeakCheckIncum",
      "value" = 2,
      "comment" = "after the first failed check: subsequent checks at a cumulative +2 on the die roll",
    }, {
      "name" = "wnfWeakAtkPenaltyFirstDay",
      "value" = 1,
      "comment" = "weakened: -1 on attack rolls and dodging or reaction saving throws the first day",
    }, {
      "name" = "wnfWeakPenaltyWorsenPerDay",
      "value" = 1,
      "comment" = "while weakened the penalty worsens by -1 per day",
    }, {
      "name" = "wnfRecoveryStepsPerDay",
      "value" = 2,
      "comment" = "eating at least one full meal per day: the condition improves by two steps per day",
    }, {
      "name" = "wnfIncapPenaltyFloor",
      "value" = 4,
      "comment" = "incapacitated: accumulated penalties retained or worsened to -4 if they were not that low already",
    }, {
      "name" = "wnfIncapRecoveryMinMeals",
      "value" = 2,
      "comment" = "incapacitated recovers only via solid nourishment for at least two consecutive days (at least two full meals, spaced one day apart)",
    }, {
      "name" = "wnfIncapFailedCheckIncum",
      "value" = 4,
      "comment" = "if the incapacitated recovery check fails and he keeps eating one meal a day: subsequent daily checks at a cumulative -4 until one succeeds",
    }, {
      "name" = "wnfIncapHpLossPerHourDie",
      "value" = 6,
      "comment" = "incapacitated without eating within 12 hours: hit points lost at 1d6 per hour, death at zero",
    }, {
      "name" = "wnfIncapHpRegainPerHourDie",
      "value" = 4,
      "comment" = "nourishment while alive: hit points regained at 1d4 per hour",
    }, {
      "name" = "wnfIncapPenaltyPerHour",
      "value" = 1,
      "comment" = "an additional -1 on attack rolls and saving throws for each hour of hit-point loss",
    }, {
      "name" = "wnfDistressStrenuousTurnLimit",
      "value" = 2,
      "comment" = "distressed: no more than two turns of strenuous activity before a Con check, a fail means automatic exhaustion (not merely fatigued)",
    }, {
      "name" = "wnfWaterBaseTolerance",
      "value" = 3,
      "comment" = "general rule: no character goes without liquid nourishment more than three days before adverse effects",
    }, {
      "name" = "wnfWaterModHighWaterFood",
      "value" = 2,
      "comment" = "+2 days if food with a high water content is eaten (standard rations, green plants, raw meat, fruits, vegetables)",
    }, {
      "name" = "wnfWaterModHeavy",
      "value" = 1,
      "comment" = "+1 day if body weight over 200 pounds, above average weight for the race, or average weight and below average height",
    }, {
      "name" = "wnfWaterModFemale",
      "value" = 1,
      "comment" = "+1 day if female",
    }, {
      "name" = "wnfWaterModNoStrenuous",
      "value" = 1,
      "comment" = "+1 day without strenuous activity the entire period (a once-per-day very short burst allowable)",
    }, {
      "name" = "wnfWaterModHot90",
      "value" = -1,
      "comment" = "-1 day if the effective temperature reaches or exceeds 90 degrees even once, magical or natural",
    }, {
      "name" = "wnfWaterModLessMeal",
      "value" = -1,
      "comment" = "-1 day without at least one meal per day",
    }, {
      "name" = "wnfWaterModLowStrCon",
      "value" = -1,
      "comment" = "-1 day if strength or constitution under 8",
    }, {
      "name" = "wnfWaterToleranceFloor",
      "value" = 1,
      "comment" = "negative modifiers can never reduce the water tolerance level below one day",
    }, {
      "name" = "wnfWaterNoStrenuousLossTurns",
      "value" = 1,
      "comment" = "one turn of strenuous activity during a day loses the no-strenuous-activity benefit",
    }, {
      "name" = "wnfAnimalHalveFactor",
      "value" = 2,
      "comment" = "a weakened animal: movement and carrying capacity both reduced to one-half (divide by two)",
    }, {
      "name" = "wnfAnimalHardWorkTurns",
      "value" = 3,
      "comment" = "a weakened animal forced to work hard longer than three turns in a day: incapacitated at the end of the third turn",
    }, {
      "name" = "wnfAnimalIncapMultNum",
      "value" = 3,
      "comment" = "the incapacitation multiple numerator: 1.5 times the tolerance level (rounded down)",
    }, {
      "name" = "wnfAnimalIncapMultDen",
      "value" = 2,
      "comment" = "the incapacitation multiple denominator (3/2)",
    }, {
      "name" = "wnfAnimalRestMinHours",
      "value" = 13,
      "comment" = "a weakened animal fed or watered: back to full strength after 13-24 hours of rest",
    }, {
      "name" = "wnfAnimalRestMaxHours",
      "value" = 24,
      "comment" = "the rest window upper end (1d12 + 12)",
    }, {
      "name" = "wnfAnimalRestDieSides",
      "value" = 12,
      "comment" = "the recovery rest die (1d12 + 12)",
    }, {
      "name" = "wnfAnimalRestDieBonus",
      "value" = 12,
      "comment" = "the recovery rest die bonus",
    }, {
      "name" = "wnfAnimalEffortDeathTurns",
      "value" = 1,
      "comment" = "an incapacitated animal dies if forced to expend appreciable energy for as little as one turn",
    }, {
      "name" = "wnfAnimalIncapIdleDeathDays",
      "value" = 1,
      "comment" = "an incapacitated animal dies after one day in the condition even if unencumbered and stationary",
    }, {
      "name" = "wnfFoodHumanMinLb",
      "value" = 1,
      "comment" = "a human, dwarf, half-orc or half-elf needs 1-2 pounds of solid nourishment per day: the floor",
    }, {
      "name" = "wnfFoodHumanMaxLb",
      "value" = 2,
      "comment" = "the daily food requirement ceiling in pounds",
    }, {
      "name" = "wnfFoodElfNum",
      "value" = 3,
      "comment" = "an elf needs three-fourths of a human-sized ration: the numerator",
    }, {
      "name" = "wnfFoodElfDen",
      "value" = 4,
      "comment" = "the elf ration fraction denominator (3/4)",
    }, {
      "name" = "wnfFoodSmallNum",
      "value" = 1,
      "comment" = "a gnome or halfling gets along on half a human ration: the numerator",
    }, {
      "name" = "wnfFoodSmallDen",
      "value" = 2,
      "comment" = "the small race fraction (1/2)",
    }, {
      "name" = "wnfRationWeekDays",
      "value" = 7,
      "comment" = "a ration pack feeds one human for one week (seven days)",
    }, {
      "name" = "wnfStdRationEncGp",
      "value" = 200,
      "comment" = "the standard rations pack encumbrance value in gold pieces",
    }, {
      "name" = "wnfStdRationWeightLb",
      "value" = 14,
      "comment" = "the standard rations pack actual weight in pounds (140 gp)",
    }, {
      "name" = "wnfStdRationBulkGp",
      "value" = 60,
      "comment" = "the standard rations pack bulk accounts for the other 60 gp",
    }, {
      "name" = "wnfStdRationDailyLb",
      "value" = 2,
      "comment" = "the minimum daily requirement of standard rations: two pounds",
    }, {
      "name" = "wnfIronRationEncGp",
      "value" = 75,
      "comment" = "the iron rations pack encumbrance value",
    }, {
      "name" = "wnfIronRationBulkGp",
      "value" = 5,
      "comment" = "the iron rations bulk: perhaps as little as 5 gp",
    }, {
      "name" = "wnfIronRationWeightLb",
      "value" = 7,
      "comment" = "the iron rations actual weight: 70 gp = 7 pounds",
    }, {
      "name" = "wnfIronRationDailyLb",
      "value" = 1,
      "comment" = "the minimum daily requirement of iron rations: one pound",
    }, {
      "name" = "wnfMeatVegNourishRatio",
      "value" = 2,
      "comment" = "one pound of meat provides the nourishment of two pounds of vegetables",
    }, {
      "name" = "wnfMealsPerDayMin",
      "value" = 2,
      "comment" = "a character should eat at least twice a day (after a night rest, at the end of the day)",
    }, {
      "name" = "wnfMissedMealToHitMod",
      "value" = -1,
      "comment" = "a missed meal: the DM may assign -1 \"to hit\"",
    }, {
      "name" = "wnfMissedMealCheckMod",
      "value" = 1,
      "comment" = "a missed meal: +1 on Strength or Constitution checks, until the next nourishment",
    }, {
      "name" = "wnfHalfRationCheatNum",
      "value" = 1,
      "comment" = "cheating by half the recommended amount: the numerator (1/2)",
    }, {
      "name" = "wnfHalfRationCheatDen",
      "value" = 2,
      "comment" = "the cheat fraction denominator",
    }, {
      "name" = "wnfHalfRationDaysNum",
      "value" = 3,
      "comment" = "half rations sustain normal activity for 1.5 times the tolerance level rounded down: the numerator",
    }, {
      "name" = "wnfHalfRationDaysDen",
      "value" = 2,
      "comment" = "the half-ration days multiple denominator (3/2)",
    }, {
      "name" = "wnfBandCount",
      "value" = 6,
      "comment" = "the Table 28 band count (six combined Str+Con bands)",
    }, {
      "name" = "wnfTempBandCount",
      "value" = 4,
      "comment" = "the Table 29 temperature band count (below 50, 50-70, 71-90, above 90)",
    }, {
      "name" = "wnfElfWaterRedNum",
      "value" = 1,
      "comment" = "elves need one-fourth less water: the numerator",
    }, {
      "name" = "wnfElfWaterRedDen",
      "value" = 4,
      "comment" = "the elf water reduction fraction (1/4, rounded up to the nearest half-pint)",
    }, {
      "name" = "wnfDemiWaterRedNum",
      "value" = 1,
      "comment" = "dwarves, gnomes and halflings need one-third less water: the numerator",
    }, {
      "name" = "wnfDemiWaterRedDen",
      "value" = 3,
      "comment" = "the demihuman water reduction fraction (1/3, rounded up to the nearest pint or half-pint)",
    }, {
      "name" = "wnfHighWaterFoodMinNum",
      "value" = 1,
      "comment" = "high-water-content food covers one-fourth to one-third of the daily water requirement: the lower numerator",
    }, {
      "name" = "wnfHighWaterFoodMinDen",
      "value" = 4,
      "comment" = "the lower fraction denominator (1/4)",
    }, {
      "name" = "wnfHighWaterFoodMaxNum",
      "value" = 1,
      "comment" = "the upper fraction numerator",
    }, {
      "name" = "wnfHighWaterFoodMaxDen",
      "value" = 3,
      "comment" = "the upper fraction denominator (1/3)",
    }, {
      "name" = "wnfInactHourLimit",
      "value" = 1,
      "comment" = "inactive: one hour or less of significant physical activity in the day",
    }, {
      "name" = "wnfLightHourOver",
      "value" = 1,
      "comment" = "light activity: more than one hour on non-sedentary pursuits",
    }, {
      "name" = "wnfModerateHourOver",
      "value" = 2,
      "comment" = "moderate activity: more than two hours",
    }, {
      "name" = "wnfHeavyHourOver",
      "value" = 4,
      "comment" = "heavy activity: more than four hours",
    }, {
      "name" = "wnfCubicFootGallons",
      "value" = 7,
      "comment" = "one cubic foot of water contains seven gallons",
    }, {
      "name" = "wnfGallonPints",
      "value" = 8,
      "comment" = "there are eight pints in a gallon",
    }, {
      "name" = "wnfWaterEncPerGallon",
      "value" = 50,
      "comment" = "water has an encumbrance value of 50 gp per gallon",
    }, {
      "name" = "wnfContainerEncPerGallons",
      "value" = 3,
      "comment" = "plus an extra 50 gp for every three gallons transported in a single container",
    }, {
      "name" = "wnfContainerEncGp",
      "value" = 50,
      "comment" = "the per-container-bulk charge in gold pieces",
    }, {
      "name" = "wnfWaterskinGallons",
      "value" = 1,
      "comment" = "a typical waterskin holds one gallon",
    } },
  "bools" = { {
      "name" = "wnfFoodToleranceRequiresWater",
      "value" = true,
      "comment" = "no ill effects from going without food only with an adequate supply of drinking water",
    }, {
      "name" = "wnfWaterAnyDrinkableLiquid",
      "value" = true,
      "comment" = "\"water\" is any liquid swallowed without harmful effects - the same benefit as pure water",
    }, {
      "name" = "wnfStandardRationsHighWater",
      "value" = true,
      "comment" = "standard rations have a high water content",
    }, {
      "name" = "wnfIronRationsHighWater",
      "value" = false,
      "comment" = "iron rations do NOT have a high water content",
    }, {
      "name" = "wnfGreenPlantsRawMeatHighWater",
      "value" = true,
      "comment" = "green plants, raw meat, fruits and vegetables have a high water content",
    }, {
      "name" = "wnfTreeBarkHighWater",
      "value" = false,
      "comment" = "tree bark is edible but has no high water content, nor dried or cooked meat, nor bread",
    }, {
      "name" = "wnfWaterModsCumulative",
      "value" = true,
      "comment" = "the water tolerance modifiers are all cumulative",
    }, {
      "name" = "wnfWaterDeprivationUsesFoodConditions",
      "value" = true,
      "comment" = "weakened, distressed and incapacitated from lack of water follow the going-without-food conditions and transitions",
    }, {
      "name" = "wnfTotalDeprivationIncapOnFail",
      "value" = true,
      "comment" = "without food AND water: after the water tolerance onset, a failed check means immediate incapacitation",
    }, {
      "name" = "wnfDistressFailExhaustedNotFatigued",
      "value" = true,
      "comment" = "a distressed character failing the strenuous Con check becomes automatically exhausted, not merely fatigued",
    }, {
      "name" = "wnfIncapNoVoluntaryActivity",
      "value" = true,
      "comment" = "an incapacitated character is incapable of any voluntary physical activity",
    }, {
      "name" = "wnfAnimalMoveCarryHalved",
      "value" = true,
      "comment" = "a weakened animal has movement and carrying capacity halved",
    }, {
      "name" = "wnfOvereatingNoBenefit",
      "value" = true,
      "comment" = "overeating offers no significant benefit in game terms",
    }, {
      "name" = "wnfHalfRationFullMealRecovers",
      "value" = true,
      "comment" = "one full ration on any single day offsets the half-ration weakness",
    }, {
      "name" = "wnfHalfRationIndefiniteIfIdle",
      "value" = true,
      "comment" = "without significant physical activity a character subsists on half rations indefinitely",
    }, {
      "name" = "wnfMissedMealBelowAvgSusceptible",
      "value" = true,
      "comment" = "below-average strength or constitution is especially susceptible to a missed meal",
    }, {
      "name" = "wnfNotEnoughWaterAsBadAsNone",
      "value" = true,
      "comment" = "not enough water is just as bad as none: less than a full ration triggers the tolerance clock",
    }, {
      "name" = "wnfAnimalsRecoverQuickly",
      "value" = true,
      "comment" = "animals recover rather quickly from food or water deprivation",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "wnfFoodTolerance",
      "tag" = "28",
      "cols" = { "wnfToleranceDays" },
      "count" = "wnfBandCount",
      "data" = { { 4 }, { 5 }, { 6 }, { 7 }, { 8 }, { 10 } },
      "col_default" = 0,
      "col_comments" = { "the Table 28 tolerance days per combined Str+Con band" },
      "audit_comment" = "the Table 28 tolerance ladder (4/5/6/7/8/10 days)",
    }, {
      "name" = "wnfWaterReq",
      "tag" = "29",
      "cols" = { "wnfWaterPintInact", "wnfWaterPintLight", "wnfWaterPintMod", "wnfWaterPintHeavy" },
      "count" = "wnfTempBandCount",
      "data" = { { 5, 6, 8, 9 }, { 6, 7, 9, 10 }, { 7, 8, 10, 12 }, { 8, 10, 12, 16 } },
      "col_default" = 0,
      "col_comments" = { "the Table 29 inactive pints per temperature band", "the light activity pints", "the moderate activity pints", "the heavy activity pints" },
      "audit_comment" = "the Table 29 pint grid (rows: below 50, 50-70, 71-90, above 90)",
    } },
  "chains" = { {
      "name" = "wnfBandFor",
      "arg" = "sc",
      "limits" = { 15, 19, 24, 30, 35 },
      "tail" = 5,
      "comment" = "the combined Str+Con band: 15 or less 0, 16-19 1, 20-24 2, 25-30 3, 31-35 4, 36 or more 5",
    }, {
      "name" = "wnfTempBandFor",
      "arg" = "t",
      "limits" = { 49, 70, 90 },
      "tail" = 3,
      "comment" = "the effective temperature band: below 50 0, 50-70 1, 71-90 2, above 90 3",
    } },
  "examples" = { {
      "note" = "the book example: Str 12 + Con 14 = 26 lands in band 3 with a seven-day tolerance",
      "expr" = "m['wnfToleranceDays'](m['wnfBandFor'](26)) != 7",
    }, {
      "note" = "the example check at +2 fails a Con 14 on 13 or higher",
      "expr" = "15 - 2 * m['wnfCheckIncumPerCheck']() != 13",
    }, {
      "note" = "the weakened example check at +4 fails on 11 or higher (+2 ladder plus the +2 weakened shift)",
      "expr" = "15 - (2 * m['wnfCheckIncumPerCheck']() + m['wnfWeakCheckIncum']()) != 11",
    }, {
      "note" = "the elf three-fourths ration: 2 lb human -> 1.5 lb elf, cross-multiplied",
      "expr" = "m['wnfFoodElfNum']() * 8 != m['wnfFoodElfDen']() * 6",
    }, {
      "note" = "the gnome or halfling half ration, cross-multiplied",
      "expr" = "m['wnfFoodSmallNum']() * 4 != m['wnfFoodSmallDen']() * 2",
    }, {
      "note" = "the standard rations pack: 14 lb over a week is 2 lb per day",
      "expr" = "m['wnfStdRationWeightLb']() != m['wnfStdRationDailyLb']() * m['wnfRationWeekDays']()",
    }, {
      "note" = "the iron rations pack: 7 lb over a week is 1 lb per day",
      "expr" = "m['wnfIronRationWeightLb']() != m['wnfIronRationDailyLb']() * m['wnfRationWeekDays']()",
    }, {
      "note" = "the half-ration cheat: 1.5 times the tolerance, cross-multiplied (tolerance 5 -> 7 days)",
      "expr" = "m['wnfHalfRationDaysNum']() * 10 != m['wnfHalfRationDaysDen']() * 15",
    }, {
      "note" = "the animal incapacitation multiple: 1.5 times tolerance rounded down (tolerance 4 -> 6 days)",
      "expr" = "m['wnfAnimalIncapMultNum']() * 8 != m['wnfAnimalIncapMultDen']() * 12",
    }, {
      "note" = "the animal recovery rest: 1d12 + 12 spans 13-24 hours",
      "expr" = "m['wnfAnimalRestDieSides']() + m['wnfAnimalRestDieBonus']() != m['wnfAnimalRestMaxHours']()",
    }, {
      "note" = "the recovery rest floor: the die minimum plus one is 13 hours",
      "expr" = "m['wnfAnimalRestDieBonus']() + 1 != m['wnfAnimalRestMinHours']()",
    }, {
      "note" = "a cubic foot of create water: 7 gallons x 8 pints = 56 pints",
      "expr" = "m['wnfCubicFootGallons']() * m['wnfGallonPints']() != 56",
    }, {
      "note" = "the Table 29 corner: heavy activity above 90 costs 16 pints",
      "expr" = "m['wnfWaterPintHeavy'](m['wnfTempBandFor'](100)) != 16",
    } },
  "audit" = {
      "label" = "R462 WSG food and water pin audit",
      "comment" = "The Table 28 ladder and the Table 29 grid cell by cell, the 12-hour check cadence with the +1/+2 modifier ladders, the water tolerance modifier set with the floor, the animal incapacitation and recovery rules, the ration arithmetic and the daily water requirement arithmetic - every cell, const, bool and chain limit verified against the model.",
    },
}
