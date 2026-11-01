-- dna: promoted from tools/spec_r509.json (the The DSG UNDERGROUND ENVIRONMENT OPENER, R509: the printed pp. 36-37 (pdf 37-38) - the chapter opener (life underground shaped by the limits of sunlight and fresh air), the air supply duration (10 cubic feet per 24-hour rest, 12 moderate, 6 strenuous, the 2x/4x rates, the 3+4x5=23 example, the creature ratios, the post-exhaustion Con Check ladder with the -10 hp death floor and the 3-per-turn recovery), fire and oxygen (the small-fire 10-foot cube in 2 hours, torch 8 hours, the 4x scaling, the oil 3-rounds-as-turns rule), the smoke system (the 1-foot layer per turn per 10x10, ceiling stacking, the Con Check with 1d6 damage and 1d6 recovery, the cumulative rule and the 33-28-5 orc death example), the poisonous and noxious gases (save vs. poison vs. the -3/-3 Con Check economy, the natural-gas 20% explosion ladder with its Wisdom Check, the small-bird early warning) and the five-rung ventilation ladder);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 509,
  "prefix" = "dna",
  "banner" = {
      "title" = "The DSG UNDERGROUND ENVIRONMENT OPENER, R509: the printed pp. 36-37 (pdf 37-38) - the chapter opener (life underground shaped by the limits of sunlight and fresh air), the air supply duration (10 cubic feet per 24-hour rest, 12 moderate, 6 strenuous, the 2x/4x rates, the 3+4x5=23 example, the creature ratios, the post-exhaustion Con Check ladder with the -10 hp death floor and the 3-per-turn recovery), fire and oxygen (the small-fire 10-foot cube in 2 hours, torch 8 hours, the 4x scaling, the oil 3-rounds-as-turns rule), the smoke system (the 1-foot layer per turn per 10x10, ceiling stacking, the Con Check with 1d6 damage and 1d6 recovery, the cumulative rule and the 33-28-5 orc death example), the poisonous and noxious gases (save vs. poison vs. the -3/-3 Con Check economy, the natural-gas 20% explosion ladder with its Wisdom Check, the small-bird early warning) and the five-rung ventilation ladder",
      "provenance" = "the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf = printed + 1; the text read from the IA djvu OCR with the pdf Acrobat-Capture layer as the second read - every numeric cell dual-confirmed; the garble classes settled: djvu \"213 as much oxygen\" = 2/3 (Acrobat \"consumes 2/3 as much\"), the percent-glyph garbles (1096/496-class) = 10% and +4%-style, Acrobat \"112\" = 1/2 (the halved rates), Acrobat \"ld6/ld4\" = 1d6/1d4. Odor detection (pp. 37-38) and its Tables 15-16 begin the NEXT round - this slice ends at the sealed-rung ladder.",
      "sentinel" = "Pure prose round - no printed grid, no tables, no sentinels. The ventilation pins are the ENVIRONMENTAL-scale ladder; the R508 dnrVent pins are the Battlesystem-scale modifiers - related seams, nothing auto-credited either way. The breath-holding scope note pins as a bool with the WSG R454 cross-reference in its comment.",
    },
  "consts" = { {
      "name" = "dnaAirRestCubicFeet",
      "value" = 10,
      "comment" = "a human-sized creature at complete rest depletes the oxygen in 10 cubic feet of air.",
    }, {
      "name" = "dnaAirRestHours",
      "value" = 24,
      "comment" = "the same 10 cubic feet lasts 24 hours at complete rest.",
    }, {
      "name" = "dnaAirModerateHours",
      "value" = 12,
      "comment" = "even moderate physical activity halves the air supply to 12 hours.",
    }, {
      "name" = "dnaAirStrenuousHours",
      "value" = 6,
      "comment" = "strenuous exertion cuts the air supply to a mere 6 hours.",
    }, {
      "name" = "dnaAirModerateRateMult",
      "value" = 2,
      "comment" = "a moderately exercising character uses oxygen twice as fast as one at rest.",
    }, {
      "name" = "dnaAirStrenuousRateMult",
      "value" = 4,
      "comment" = "a character working strenuously uses oxygen four times faster than a resting one.",
    }, {
      "name" = "dnaAirExampleRestHours",
      "value" = 3,
      "comment" = "the worked example: the character rests for 3 hours.",
    }, {
      "name" = "dnaAirExampleWorkHours",
      "value" = 5,
      "comment" = "the worked example: then works hard for 5 hours.",
    }, {
      "name" = "dnaAirExampleTotalRestHours",
      "value" = 23,
      "comment" = "the worked example total: 3 hours of rest plus 4 times 5 hours of work equals 23 hours of resting-rate oxygen.",
    }, {
      "name" = "dnaAirDwarfElfNum",
      "value" = 2,
      "comment" = "a dwarf or elf consumes oxygen at two-thirds the human rate: the numerator.",
    }, {
      "name" = "dnaAirDwarfElfDen",
      "value" = 3,
      "comment" = "a dwarf or elf consumes oxygen at two-thirds the human rate: the denominator.",
    }, {
      "name" = "dnaAirHalflingDogDen",
      "value" = 2,
      "comment" = "a halfling or a dog uses only half as much oxygen as a human.",
    }, {
      "name" = "dnaAirMuleOgreMult",
      "value" = 2,
      "comment" = "a mule or an ogre consumes oxygen at twice the human rate.",
    }, {
      "name" = "dnaAirFailAbilityLoss",
      "value" = 1,
      "comment" = "every failed post-exhaustion check reduces each ability score by 1.",
    }, {
      "name" = "dnaAirFailHpLoss",
      "value" = 1,
      "comment" = "every failed post-exhaustion check also reduces the hit point total by 1.",
    }, {
      "name" = "dnaAirDeathHpFloor",
      "value" = -10,
      "comment" = "when the hit point total reaches -10, the character is dead.",
    }, {
      "name" = "dnaAirRecoverPerTurn",
      "value" = 3,
      "comment" = "on recovery, hit points and ability scores all climb at 3 points per turn until original levels.",
    }, {
      "name" = "dnaFireSmallMaxDiameterFeet",
      "value" = 1,
      "comment" = "a small fire is one foot or less in diameter.",
    }, {
      "name" = "dnaFireSmallCubeFeet",
      "value" = 10,
      "comment" = "a small fire consumes all of the oxygen in a ten-foot cubic space.",
    }, {
      "name" = "dnaFireSmallHours",
      "value" = 2,
      "comment" = "the small fire exhausts that ten-foot cube of oxygen in 2 hours.",
    }, {
      "name" = "dnaFireSmallTurns",
      "value" = 12,
      "comment" = "the same consumption expressed in turns: 12 turns.",
    }, {
      "name" = "dnaFireTorchHours",
      "value" = 8,
      "comment" = "a flaming torch consumes all of the oxygen in the same ten-foot cube in 8 hours.",
    }, {
      "name" = "dnaFireScaleExampleMult",
      "value" = 4,
      "comment" = "a fire four times larger than a small fire consumes oxygen four times as fast.",
    }, {
      "name" = "dnaOilBurnRounds",
      "value" = 3,
      "comment" = "oil in a flask or similar small container burns for 3 rounds.",
    }, {
      "name" = "dnaSmokeLayerFeet",
      "value" = 1,
      "comment" = "a small fire produces enough smoke in one turn to create a one-foot-thick smoke layer.",
    }, {
      "name" = "dnaSmokeAreaFeet",
      "value" = 10,
      "comment" = "that smoke layer covers a 10-foot by 10-foot square area.",
    }, {
      "name" = "dnaSmokeScaleExampleMult",
      "value" = 3,
      "comment" = "the smoke example multiplier: 3 times the fire, 3 times the smoke rate.",
    }, {
      "name" = "dnaSmokeDamageDie",
      "value" = 6,
      "comment" = "a failed smoke check means the character suffers 1d6 hit points of smoke damage.",
    }, {
      "name" = "dnaSmokeRecoverDie",
      "value" = 6,
      "comment" = "the smoke-damage recovery die: 1d6 points per successful fresh-air round.",
    }, {
      "name" = "dnaSmokeExampleCharHp",
      "value" = 33,
      "comment" = "the smoke example character has 33 hit points.",
    }, {
      "name" = "dnaSmokeExampleLoss",
      "value" = 28,
      "comment" = "he loses 28 of them to smoke inhalation.",
    }, {
      "name" = "dnaSmokeExampleOrcHit",
      "value" = 5,
      "comment" = "an orc strikes him for 5 points of damage before he regains any smoke losses - the 5 remaining points mean he is killed.",
    }, {
      "name" = "dnaNoxiousAbilityLoss",
      "value" = 3,
      "comment" = "a failed noxious-gas check results in a general lowering of ability scores by 3.",
    }, {
      "name" = "dnaNoxiousAttackPenalty",
      "value" = 3,
      "comment" = "the same 3-point penalty is applied to attack rolls (the modern example: tear gas).",
    }, {
      "name" = "dnaNoxiousRecoverPerTurn",
      "value" = 3,
      "comment" = "ability scores are raised at 3 per turn once the character can breathe fresh air again.",
    }, {
      "name" = "dnaNatGasExplodePct",
      "value" = 20,
      "comment" = "the base chance of a natural-gas explosion is 20 percent per round.",
    }, {
      "name" = "dnaNatGasDamageDie",
      "value" = 6,
      "comment" = "the explosion causes 1d6 points of damage to all characters and creatures in the area with the gas.",
    }, {
      "name" = "dnaNatGasPotencyStepPct",
      "value" = 10,
      "comment" = "the potency step: each 10 percent increase in the chance of explosion.",
    }, {
      "name" = "dnaNatGasPotencyDieStep",
      "value" = 1,
      "comment" = "each potency step adds another 1d6 to the damage inflicted.",
    }, {
      "name" = "dnaNatGasWisBonusPerStep",
      "value" = 1,
      "comment" = "higher concentrations add 1 to the characters' Wisdom scores per potency step, for purposes of this Wisdom Check only.",
    }, {
      "name" = "dnaBirdSaveLevel",
      "value" = 0,
      "comment" = "the bird saves as a 0th-level human.",
    }, {
      "name" = "dnaVentWellGasTurns",
      "value" = 2,
      "comment" = "poisonous or noxious gases remain in a well-ventilated area for 2 turns unless more gas is introduced.",
    }, {
      "name" = "dnaVentSubtleGasHours",
      "value" = 1,
      "comment" = "in a subtly ventilated area, poisonous or noxious gases remain effective for 1 hour.",
    }, {
      "name" = "dnaVentSubtleLargeSmokeDiv",
      "value" = 2,
      "comment" = "smoke from large fires or burning oil accumulates at half the rate listed for enclosed areas in a subtly ventilated area.",
    }, {
      "name" = "dnaVentConnectedSmallSmokeDiv",
      "value" = 2,
      "comment" = "an area with no visible ventilation but connected to ventilated areas or the surface collects small-fire smoke at half the rate.",
    }, {
      "name" = "dnaVentConnectedGasMinHours",
      "value" = 2,
      "comment" = "poisonous or noxious gases remain in a connected area for 2-5 hours (1d4+1): the minimum.",
    }, {
      "name" = "dnaVentConnectedGasMaxHours",
      "value" = 5,
      "comment" = "the 2-5 hour connected-area gas duration: the maximum.",
    }, {
      "name" = "dnaVentNoneGasHours",
      "value" = 24,
      "comment" = "poisonous or noxious gases remain in an unventilated area for a full 24 hours.",
    }, {
      "name" = "dnaSealedSmokeLingerDie",
      "value" = 6,
      "comment" = "smoke that collects in a sealed room lingers for 1d6 hours after the fire that created it goes out.",
    } },
  "bools" = { {
      "name" = "dnaAirDmAppliesToCreatures",
      "value" = true,
      "comment" = "the DM applies the oxygen ratio to all characters and to any creatures, such as mules or dogs, that accompany them.",
    }, {
      "name" = "dnaAirConCheckEachTurnAfterExhaust",
      "value" = true,
      "comment" = "each turn after the oxygen is exhausted, the character must make a Constitution Check.",
    }, {
      "name" = "dnaAirCheckAgainstReducedCon",
      "value" = true,
      "comment" = "each additional Constitution Check is made against the reduced Constitution score - the character grows more feeble as he gulps the last oxygen.",
    }, {
      "name" = "dnaAirUnconsciousAtZeroAbilities",
      "value" = true,
      "comment" = "when all ability scores have dropped to 0, the character is unconscious.",
    }, {
      "name" = "dnaAirAutoDeathAtConZero",
      "value" = true,
      "comment" = "death becomes automatic once the Constitution score reaches 0, since all further Constitution Checks automatically fail.",
    }, {
      "name" = "dnaAirRecoveryImmediateOnFreshAir",
      "value" = true,
      "comment" = "if fresh air is introduced before death, the character begins to recover immediately.",
    }, {
      "name" = "dnaAirOnlyInAirNotBreathHolding",
      "value" = true,
      "comment" = "this system is used only for characters in an area with air - it cannot be used for characters holding their breath (the WSG breath-holding pins are a separate system; nothing auto-credited).",
    }, {
      "name" = "dnaAirCaveInCutsVentilation",
      "value" = true,
      "comment" = "if a cave-in occurs, ventilation sources may be cut off - the potential for air supply problems should not be overlooked.",
    }, {
      "name" = "dnaAirCrowdingOutpacesVentilation",
      "value" = true,
      "comment" = "a chamber may be so crowded that a meager ventilation system cannot replace oxygen as fast as it is depleted.",
    }, {
      "name" = "dnaFireScalesBySmallFireEquivalents",
      "value" = true,
      "comment" = "the oxygen consumption of larger fires is based on the number of small fires they equal.",
    }, {
      "name" = "dnaFireGoesOutWithoutOxygen",
      "value" = true,
      "comment" = "when all of the oxygen is consumed, the fire goes out.",
    }, {
      "name" = "dnaOilRoundCountsAsTurn",
      "value" = true,
      "comment" = "for oxygen consumption, burning oil is treated as a small fire and each round of burning counts as a full turn - 3 rounds use the oxygen of 3 turns of wood fire.",
    }, {
      "name" = "dnaSmokeFromWetOrGreenFuel",
      "value" = true,
      "comment" = "if any of the fuel is wet, or if green or living branches, twigs or leaves are used, smoke is produced.",
    }, {
      "name" = "dnaSmokeFromFabricAndOil",
      "value" = true,
      "comment" = "any kind of burning fabric creates smoke, as does burning oil.",
    }, {
      "name" = "dnaSmokeLayersStackFromCeiling",
      "value" = true,
      "comment" = "the smoke rises and collects against the ceiling; each next turn of smoke collects below the previous layer until the breathable air is concentrated near the floor.",
    }, {
      "name" = "dnaSmokeFillsRoomAffectsFloor",
      "value" = true,
      "comment" = "finally the entire room fills with smoke and even characters lying on the floor are affected.",
    }, {
      "name" = "dnaOilSmokeRateByRound",
      "value" = true,
      "comment" = "an oil fire creates the same amount of smoke as an average fire, except that the rate is calculated by round instead of by turn.",
    }, {
      "name" = "dnaSmokeScalesWithFireSize",
      "value" = true,
      "comment" = "a fire three times as big as a one-foot-diameter fire creates smoke three times as fast.",
    }, {
      "name" = "dnaSmokeConCheckEachRound",
      "value" = true,
      "comment" = "a character forced to breathe smoke must make a Constitution Check each round that the smoke is inhaled.",
    }, {
      "name" = "dnaSmokeDamageTemporary",
      "value" = true,
      "comment" = "smoke damage is temporary - with a chance to breathe fresh air the character makes a Constitution Check every round, regaining 1d6 points on a success.",
    }, {
      "name" = "dnaSmokeDamageCumulative",
      "value" = true,
      "comment" = "smoke damage is real: any other damage taken while a character suffers from smoke damage must be considered cumulative with it.",
    }, {
      "name" = "dnaGasPoisonSaveVsPoison",
      "value" = true,
      "comment" = "poisonous gases generally require characters to make saving throws vs. poison.",
    }, {
      "name" = "dnaGasOxygenReplacementTreatedAsExhaustion",
      "value" = true,
      "comment" = "any gas - poisonous, noxious, or harmless - can replace the oxygen in an area; the effects are treated as the air-supply exhaustion explained earlier.",
    }, {
      "name" = "dnaNoxiousConCheckEachRound",
      "value" = true,
      "comment" = "noxious gases force characters to make Constitution Checks every round.",
    }, {
      "name" = "dnaNoxiousHelplessAtZeroAbilities",
      "value" = true,
      "comment" = "characters can be rendered quite helpless by noxious gases when all ability scores are reduced to 0.",
    }, {
      "name" = "dnaNoxiousNoHpLoss",
      "value" = true,
      "comment" = "but they are not killed - noxious gases cause no loss of hit points.",
    }, {
      "name" = "dnaGasDmAdjustmentsAllowed",
      "value" = true,
      "comment" = "modifiers to the saving throw or Constitution Check can be applied as the DM sees fit, for exceptionally lethal or mild poisons or degrees of noxiousness.",
    }, {
      "name" = "dnaOdorlessGasNoWisCheck",
      "value" = true,
      "comment" = "if a gas is completely odor-free, no Wisdom Check should be allowed - the check represents awareness of the odor.",
    }, {
      "name" = "dnaStrongOdorAllowsBreathHold",
      "value" = true,
      "comment" = "strong-odor gases such as sulphur give the characters a chance to hold their breath before the full force of the gas takes effect.",
    }, {
      "name" = "dnaNatGasExplodesWithOpenFlame",
      "value" = true,
      "comment" = "natural gas with a torch, candle, lantern or any other open flame has a chance per round of exploding.",
    }, {
      "name" = "dnaNatGasWisCheckOnlyIfCareful",
      "value" = true,
      "comment" = "characters entering natural gas might be allowed Wisdom Checks only if they are moving slowly and investigating their surroundings carefully.",
    }, {
      "name" = "dnaBirdWarnsOneTurnEarly",
      "value" = true,
      "comment" = "a small bird with the party gives early warning of gradually increasing poisonous gas: the bird's save comes one turn before the characters must save.",
    }, {
      "name" = "dnaBirdSaveSecret",
      "value" = true,
      "comment" = "the DM should make a secret saving throw vs. poison for the bird.",
    }, {
      "name" = "dnaBirdDiesOnFailedSave",
      "value" = true,
      "comment" = "if the bird's saving throw fails, the bird dies.",
    }, {
      "name" = "dnaBirdOnlyGradualGas",
      "value" = true,
      "comment" = "the bird warning is of little help if gas is suddenly introduced in high concentration - only a gradually increasing amount gives any early warning.",
    }, {
      "name" = "dnaVentWellNoSmokeAccumulation",
      "value" = true,
      "comment" = "in a well-ventilated area (a noticeable airflow), smoke does not accumulate.",
    }, {
      "name" = "dnaVentWellNoOxygenExhaustion",
      "value" = true,
      "comment" = "nor is the oxygen exhausted by characters breathing or by fire in a well-ventilated area.",
    }, {
      "name" = "dnaVentWellGasSpellsHalved",
      "value" = true,
      "comment" = "the duration of all gas-based spells is halved in a well-ventilated area.",
    }, {
      "name" = "dnaVentSubtleSpellsNormal",
      "value" = true,
      "comment" = "with subtle air movement (detected by the flickering of a torch or candle), gas-based spells linger for their normal durations and fresh air is not a problem.",
    }, {
      "name" = "dnaVentSubtleSmallSmokeNoAccumulation",
      "value" = true,
      "comment" = "smoke from small fires or torches does not accumulate in a subtly ventilated area.",
    }, {
      "name" = "dnaVentConnectedLargeSmokeNormal",
      "value" = true,
      "comment" = "large or oil fires fill such a connected area with smoke at the usual rate.",
    }, {
      "name" = "dnaVentConnectedBreathNeverExhausts",
      "value" = true,
      "comment" = "characters do not use up all the air through breathing in a connected area - even minimal ventilation allows enough air movement for respiration.",
    }, {
      "name" = "dnaVentConnectedSpellsNormal",
      "value" = true,
      "comment" = "the duration of all gas-based spells is normal in a connected area.",
    }, {
      "name" = "dnaVentNoneSmallSmokeNormal",
      "value" = true,
      "comment" = "an area with no noticeable ventilation and no outflow captures smoke at the normal rate, even from small fires.",
    }, {
      "name" = "dnaVentNoneHeavierThanAirException",
      "value" = true,
      "comment" = "the 24-hour figure holds unless the gas is specifically noted as heavier than air.",
    }, {
      "name" = "dnaSealedAirFinite",
      "value" = true,
      "comment" = "an area completely sealed off (by cave-ins, mortared stone walls, or walls of force) has a finite air supply that once used up can only be replaced by introduced fresh air.",
    }, {
      "name" = "dnaSealedEffectsNormalRates",
      "value" = true,
      "comment" = "in a sealed area all of the effects apply at their normal rates of accumulation and effect.",
    }, {
      "name" = "dnaSealedGasUntilVented",
      "value" = true,
      "comment" = "poisonous or noxious gases remain in a sealed area until vented out by the admission of fresh air.",
    }, {
      "name" = "dnaSealedSpellsNormal",
      "value" = true,
      "comment" = "the duration of all gas-based spells is normal in a sealed area.",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dnaAirRestCubicFeet']() != 10 or m['dnaAirRestHours']() != 24 or m['dnaAirModerateHours']() != 12 or m['dnaAirStrenuousHours']() != 6",
      "note" = "the air-supply durations: 10 cubic feet per human per 24 hours at rest, 12 hours moderate, 6 hours strenuous.",
    }, {
      "expr" = "m['dnaAirModerateRateMult']() != 2 or m['dnaAirStrenuousRateMult']() != 4 or m['dnaAirExampleRestHours']() != 3 or m['dnaAirExampleWorkHours']() != 5 or m['dnaAirExampleTotalRestHours']() != 23",
      "note" = "the consumption rates (2x moderate, 4x strenuous) and the worked example: 3 hours rest plus 4 times 5 hours work equals 23 hours of resting-rate oxygen.",
    }, {
      "expr" = "m['dnaAirDwarfElfNum']() != 2 or m['dnaAirDwarfElfDen']() != 3 or m['dnaAirHalflingDogDen']() != 2 or m['dnaAirMuleOgreMult']() != 2",
      "note" = "the creature-rate ratios: dwarf and elf at two-thirds human, halfling and dog at half, mule and ogre at twice.",
    }, {
      "expr" = "m['dnaAirConCheckEachTurnAfterExhaust']() != 1 or m['dnaAirCheckAgainstReducedCon']() != 1 or m['dnaAirFailAbilityLoss']() != 1 or m['dnaAirFailHpLoss']() != 1 or m['dnaAirUnconsciousAtZeroAbilities']() != 1 or m['dnaAirAutoDeathAtConZero']() != 1 or m['dnaAirDeathHpFloor']() != -10",
      "note" = "the post-exhaustion ladder: a Con Check each turn against the reduced Con, each failure draining 1 from every ability and 1 hit point, unconscious at all-zero abilities, dead at -10 hit points, automatic once Con reaches 0.",
    }, {
      "expr" = "m['dnaAirRecoveryImmediateOnFreshAir']() != 1 or m['dnaAirRecoverPerTurn']() != 3 or m['dnaAirOnlyInAirNotBreathHolding']() != 1",
      "note" = "the recovery (immediate, 3 points per turn for hit points and abilities) and the scope note: air areas only, never breath-holding.",
    }, {
      "expr" = "m['dnaFireSmallMaxDiameterFeet']() != 1 or m['dnaFireSmallCubeFeet']() != 10 or m['dnaFireSmallHours']() != 2 or m['dnaFireSmallTurns']() != 12 or m['dnaFireTorchHours']() != 8",
      "note" = "the fire oxygen rates: a small fire (1 foot or less) drains a 10-foot cube in 2 hours (12 turns), a torch in 8 hours.",
    }, {
      "expr" = "m['dnaFireScalesBySmallFireEquivalents']() != 1 or m['dnaFireScaleExampleMult']() != 4 or m['dnaFireGoesOutWithoutOxygen']() != 1 or m['dnaOilBurnRounds']() != 3 or m['dnaOilRoundCountsAsTurn']() != 1",
      "note" = "the fire scaling (a 4x fire drains 4x as fast, and fires go out when the oxygen is gone) and the oil rule: a flask burns 3 rounds, each counted as a full turn of small-fire oxygen.",
    }, {
      "expr" = "m['dnaSmokeLayerFeet']() != 1 or m['dnaSmokeAreaFeet']() != 10 or m['dnaSmokeLayersStackFromCeiling']() != 1 or m['dnaSmokeFillsRoomAffectsFloor']() != 1",
      "note" = "the smoke buildup: a 1-foot-thick layer per turn over each 10-by-10 area, stacking from the ceiling down until even floor-liers are affected.",
    }, {
      "expr" = "m['dnaSmokeConCheckEachRound']() != 1 or m['dnaSmokeDamageDie']() != 6 or m['dnaSmokeDamageTemporary']() != 1 or m['dnaSmokeRecoverDie']() != 6 or m['dnaSmokeDamageCumulative']() != 1",
      "note" = "the smoke damage loop: a Con Check each inhaled round, 1d6 on a failure, 1d6 recovered per successful fresh-air round, cumulative with other damage.",
    }, {
      "expr" = "m['dnaSmokeExampleCharHp']() - m['dnaSmokeExampleLoss']() != m['dnaSmokeExampleOrcHit']()",
      "note" = "the smoke death example: the 33-hit-point character has exactly his 28-point smoke loss equal to the orc's 5-point blow (33 - 28 == 5), so the strike kills him before any recovery.",
    }, {
      "expr" = "m['dnaGasPoisonSaveVsPoison']() != 1 or m['dnaNoxiousConCheckEachRound']() != 1 or m['dnaNoxiousAbilityLoss']() != 3 or m['dnaNoxiousAttackPenalty']() != 3 or m['dnaNoxiousNoHpLoss']() != 1 or m['dnaNoxiousRecoverPerTurn']() != 3",
      "note" = "the gas effects: poisonous gases save vs. poison; noxious gases Con Check each round with the -3 ability and -3 attack drain, no hit-point loss, and 3 points per turn of recovery.",
    }, {
      "expr" = "m['dnaNatGasExplodePct']() != 20 or m['dnaNatGasDamageDie']() != 6 or m['dnaNatGasPotencyStepPct']() != 10 or m['dnaNatGasPotencyDieStep']() != 1 or m['dnaNatGasWisBonusPerStep']() != 1 or m['dnaOdorlessGasNoWisCheck']() != 1 or m['dnaNatGasWisCheckOnlyIfCareful']() != 1",
      "note" = "the natural-gas hazard: the base 20 percent per-round explosion chance with open flame, 1d6 damage, each 10 percent potency step adding 1d6 damage and 1 point of Wisdom for the check only - and no Wisdom Check at all for an odor-free gas.",
    }, {
      "expr" = "m['dnaBirdWarnsOneTurnEarly']() != 1 or m['dnaBirdSaveSecret']() != 1 or m['dnaBirdSaveLevel']() != 0 or m['dnaBirdDiesOnFailedSave']() != 1 or m['dnaBirdOnlyGradualGas']() != 1",
      "note" = "the small-bird warning: a secret save vs. poison one turn before the characters, saving as a 0th-level human, dying on a failure, and only against gradually increasing gas.",
    }, {
      "expr" = "m['dnaVentWellGasTurns']() != 2 or m['dnaVentWellNoSmokeAccumulation']() != 1 or m['dnaVentWellNoOxygenExhaustion']() != 1 or m['dnaVentWellGasSpellsHalved']() != 1",
      "note" = "the well-ventilated rung: no smoke accumulation, no oxygen exhaustion, gas-based spell durations halved, gases gone in 2 turns.",
    }, {
      "expr" = "m['dnaVentSubtleGasHours']() != 1 or m['dnaVentSubtleLargeSmokeDiv']() != 2 or m['dnaVentSubtleSpellsNormal']() != 1 or m['dnaVentSubtleSmallSmokeNoAccumulation']() != 1",
      "note" = "the subtle rung (torch-flicker airflow): normal spell durations, gases 1 hour, small-fire smoke no accumulation, large or oil smoke at half rate.",
    }, {
      "expr" = "m['dnaVentConnectedSmallSmokeDiv']() != 2 or m['dnaVentConnectedLargeSmokeNormal']() != 1 or m['dnaVentConnectedGasMinHours']() != 2 or m['dnaVentConnectedGasMaxHours']() != 5 or m['dnaVentConnectedBreathNeverExhausts']() != 1 or m['dnaVentConnectedSpellsNormal']() != 1",
      "note" = "the connected rung: small-fire smoke at half rate, large or oil at the usual rate, breathing never exhausts the air, gases 2-5 hours (1d4+1), spells normal.",
    }, {
      "expr" = "m['dnaVentNoneSmallSmokeNormal']() != 1 or m['dnaVentNoneGasHours']() != 24 or m['dnaVentNoneHeavierThanAirException']() != 1",
      "note" = "the no-ventilation rung: smoke at full rate even from small fires, gases a full 24 hours unless heavier than air.",
    }, {
      "expr" = "m['dnaSealedAirFinite']() != 1 or m['dnaSealedSmokeLingerDie']() != 6 or m['dnaSealedGasUntilVented']() != 1 or m['dnaSealedSpellsNormal']() != 1 or m['dnaSealedEffectsNormalRates']() != 1",
      "note" = "the sealed rung: finite air at normal rates, smoke lingering 1d6 hours after the fire goes out, gases remaining until vented, spells normal.",
    } },
  "audit" = {
      "label" = "R509 DSG air and gases audit",
      "comment" = "The DSG underground environment opener pins the air supply duration (10 cubic feet per human per 24 hours at rest, 12 hours moderate, 6 hours strenuous, the 2x and 4x consumption rates, the 3-hours-rest-plus-4-times-5 example at 23 hours, the creature ratios at 2/3, 1/2 and 2x, the post-exhaustion Con Check ladder - each failure draining 1 from every ability and 1 hit point, further checks against the reduced Con, unconscious at all-zero abilities, dead at -10 hit points, automatic once Con hits 0, the immediate 3-per-turn recovery on fresh air, and the air-only scope that excludes breath-holding), the fire and oxygen rules (the 1-foot small fire draining a 10-foot cube in 2 hours/12 turns, the torch at 8 hours, the small-fire-equivalent scaling at 4x, the 3-round oil flask counted as 3 turns), the smoke system (the 1-foot layer per turn per 10-by-10 area stacking from the ceiling until floor-liers are affected, wet or green fuel and fabric and oil as the smoke sources, the per-round Con Check with 1d6 damage, the 1d6-per-round fresh-air recovery, the cumulative rule, the 33-hit-point character losing 28 and dying to the orc's 5-point blow), the gases (poisonous gases saving vs. poison, noxious gases Con Checking every round for -3 abilities and -3 attacks with no hit-point loss and 3 per turn recovery, the gas-replaces-oxygen fold into the air system, the natural-gas 20-percent-per-round explosion at 1d6 with a 1d6 damage and 1 Wisdom step per 10 percent potency, no Wisdom Check for odorless gas, and the secret small-bird save one turn early as a 0th-level human against gradually increasing gas) and the five-rung ventilation ladder (well-ventilated, subtle, connected, none and sealed with their smoke, gas, spell and oxygen clauses).",
    },
}
