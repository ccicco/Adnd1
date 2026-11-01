-- ua376: promoted from rules/uapotprose.h (the The UA TREASURE (POTIONS) prose);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 376,
  "prefix" = "ua376",
  "banner" = {
      "title" = "The UA TREASURE (POTIONS) prose",
      "provenance" = "pins, part 1, R376: the twelve clean new-potion descriptions (pp. 90-92) - the four elixirs, the potion of fire breath, the oils of fiery burning, fumbling, sharpness, timelessness, and the potions of rainbow hues, ventriloquism, vitality. The seven PDF-gated fills landed R396 (acid resistance, disenchantment, elemental, impact, the philters of beauty, glibness, stammering) - the gap item closed. The skeleton seam rides in the regtest audit, not here.",
    },
  "consts" = { {
      "name" = "uappHealthCuresCount",
      "value" = 9,
      "comment" = "---- the elixir of health ---- Half a flask cures any one or two of the nine listed problems; the whole flask cures them all. It will not heal wounds or restore hit points lost through the listed causes.",
    }, {
      "name" = "uappHealthHalfFlaskCuresMax",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uappLifeNegativeHpPct",
      "value" = 20,
      "comment" = "---- the elixir of life ---- Restores life at a negative hit point level up to 20% of the total; administered within 5 rounds of death; one turn later the recipient sits unconscious at 1 hit point.",
    }, {
      "name" = "uappLifeMinus10NeedsFullHp",
      "value" = 50,
      "comment" = "A creature at -10 benefits only with a full-strength total of 50 or more.",
    }, {
      "name" = "uappLifeWindowRounds",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uappLifeAfterOneTurnHp",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uappLifeRestDaysPerNegHp",
      "value" = 1,
      "comment" = "Each neutralized negative hit point costs a day of rest or a cure light wounds; the stronger spells buy more days.",
    }, {
      "name" = "uappLifeCureSeriousDays",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uappLifeCureCriticalDays",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uappLifeHealSpellDays",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uappMadnessEquivalentSpell",
      "value" = "symbol of insanity",
      "comment" = "---- the elixir of madness ----",
    }, {
      "name" = "uappMadnessSipsToAffect",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uappYouthFullDoseYearsLo",
      "value" = 2,
      "comment" = "---- the elixir of youth ----",
    }, {
      "name" = "uappYouthFullDoseYearsHi",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uappYouthLowPotencyYearsLo",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uappYouthLowPotencyYearsHi",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uappFireBreathRetainTurns",
      "value" = 6,
      "comment" = "---- the potion of fire breath ---- The dweomer holds up to six turns before belching; after expiry a 10% backfire erupts in the imbiber, double damage, NO save.",
    }, {
      "name" = "uappFireBreathBackfirePct",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uappFireBreathBackfireDmgMult",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uappFireBreathDraughtsPerFlask",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uappFireBreathSmallWidthIn",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uappFireBreathSmallLenIn",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uappFireBreathSmallDmgLo",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uappFireBreathSmallDmgHi",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uappFireBreathFullWidthIn",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uappFireBreathFullLenIn",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uappFireBreathFullDmgLo",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uappFireBreathFullDmgHi",
      "value" = 50,
      "comment" = "",
    }, {
      "name" = "uappFieryDmgDice",
      "value" = 5,
      "comment" = "---- the oil of fiery burning ---- 5d6 to the coated creature, save vs. spell for half; a hurled flask always breaks.",
    }, {
      "name" = "uappFieryDmgSides",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uappFieryBlastRadiusIn",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uappFieryMaxCreatures",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uappFieryOpenDmgLo",
      "value" = 1,
      "comment" = "Opening the flask: the holder takes 1-4 at once, and re-stoppering needs a roll of dexterity or less on 2d10.",
    }, {
      "name" = "uappFieryOpenDmgHi",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uappFieryRestopperDice",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uappFieryRestopperSides",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uappFumblingPctPerRound",
      "value" = 50,
      "comment" = "---- the oil of fumbling ---- Under melee stress: a 50% chance each round of fumbling; only a thorough solvent bath removes it early.",
    }, {
      "name" = "uappSharpnessDurationLo",
      "value" = 8,
      "comment" = "---- the oil of sharpness ----",
    }, {
      "name" = "uappSharpnessDurationHi",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uappSharpnessAppsLo",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uappSharpnessAppsHi",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uappSharpnessMaxBonus",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uappTimelessYearActsAsDays",
      "value" = 1,
      "comment" = "---- the oil of timelessness ---- Each real year acts as a day on formerly-alive matter; the coating never wears off but can be magically removed.",
    }, {
      "name" = "uappTimelessSaveBonus",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uappTimelessHorsesPerFlask",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uappTimelessHumansPerFlask",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uappRainbowHoursPerFlask",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uappRainbowSegmentMax",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uappRainbowSparingDraughts",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uappRainbowDraughtHours",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uappVentriloquismUses",
      "value" = 6,
      "comment" = "---- the potion of ventriloquism ----",
    }, {
      "name" = "uappVentriloquismAsClass",
      "value" = "magic-user",
      "comment" = "",
    }, {
      "name" = "uappVitalityMaxDays",
      "value" = 7,
      "comment" = "---- the potion of vitality ---- Seven days of exertion-proof vigor; proof against poisons and diseases the while; lost hit points return at 1 per 4 hours.",
    }, {
      "name" = "uappVitalityHpPerRecovery",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uappVitalityRecoveryHours",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uappAcidResDurationHours",
      "value" = 24,
      "comment" = "",
    }, {
      "name" = "uappAcidResBigBlackMinutes",
      "value" = 64,
      "comment" = "The largest black dragon example: 64 minutes lost, 32 with a save versus breath weapon.",
    }, {
      "name" = "uappAcidResBigBlackSavedMinutes",
      "value" = 32,
      "comment" = "",
    }, {
      "name" = "uappAcidResOneManSizeHours",
      "value" = 24,
      "comment" = "One flask: one man-sized creature for 24 hours, or 24 creatures for one hour - any combination between.",
    }, {
      "name" = "uappAcidResOneHourCreatures",
      "value" = 24,
      "comment" = "",
    }, {
      "name" = "uappAcidResHorseEqualsMen",
      "value" = 8,
      "comment" = "A horse is equivalent to eight man-sized creatures.",
    }, {
      "name" = "uappDisenLostTurnsLo",
      "value" = 21,
      "comment" = "",
    }, {
      "name" = "uappDisenLostTurnsHi",
      "value" = 30,
      "comment" = "",
    }, {
      "name" = "uappElemInvSortCount",
      "value" = 4,
      "comment" = "---- the oil of elemental invulnerability (the R396 clean read) ---- Equal chances of the four basic sorts (air, earth, fire, water - roll d4); total invulnerability to normal elemental forces on the Prime Material Plane; elemental creatures still damage at -1 per die.",
    }, {
      "name" = "uappElemInvSortDieSides",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uappElemInvPlaneUsablePct",
      "value" = 10,
      "comment" = "A 10% chance any container is usable on any Elemental or Paraelemental Plane.",
    }, {
      "name" = "uappElemInvMonsterDamagePerDie",
      "value" = -1,
      "comment" = "",
    }, {
      "name" = "uappElemInvCoverageIndividuals",
      "value" = 8,
      "comment" = "One individual for eight days, or eight individuals for one day.",
    }, {
      "name" = "uappElemInvCoverageDays",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uappImpactMissileKindCount",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uappImpactApplicationsLo",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uappImpactApplicationsHi",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uappImpactHandRoundsLo",
      "value" = 9,
      "comment" = "",
    }, {
      "name" = "uappImpactHandRoundsHi",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uappImpactSlingPerAppLo",
      "value" = 4,
      "comment" = "One application treats 4-5 sling missiles or 2 larger weapons.",
    }, {
      "name" = "uappImpactSlingPerAppHi",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uappImpactLargerWeaponsPerApp",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uappImpactHandHitBonus",
      "value" = 3,
      "comment" = "The hand weapon gains +3 to hit and +6 damage; missiles are +3 both.",
    }, {
      "name" = "uappImpactHandDamageBonus",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uappImpactMissileHitBonus",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uappImpactMissileDamageBonus",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uappBeautyChaBonus",
      "value" = 1,
      "comment" = "---- the philter of beauty (the R396 clean read) ---- +1 charisma (18 maximum) and +1 to +4 comeliness for the duration; if the effects wear off within sight of a creature influenced by the enhanced scores, that creature turns hostile and attacks.",
    }, {
      "name" = "uappBeautyChaMax",
      "value" = 18,
      "comment" = "",
    }, {
      "name" = "uappBeautyComelinessLo",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uappBeautyComelinessHi",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uappStamReactionPenaltyPct",
      "value" = 25,
      "comment" = "",
    }, {
      "name" = "uappPartCleanCount",
      "value" = 19,
      "comment" = "---- the part ledger ---- All nineteen descriptions pin - the R396 clean read filled the seven the extract garbled.",
    }, {
      "name" = "uappPartGarbledCount",
      "value" = 0,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uappHealthHealsWounds",
      "value" = false,
      "comment" = "",
    }, {
      "name" = "uappHealthWholeFlaskCuresAll",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uappLifeDemihumansAffected",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uappMadnessFlaskDweomerVanishes",
      "value" = true,
      "comment" = "Once any creature is affected, the dweomer of the ENTIRE flask vanishes.",
    }, {
      "name" = "uappYouthSippingReducesPotency",
      "value" = true,
      "comment" = "Sipping first reduces the potency of the whole flask.",
    }, {
      "name" = "uappFireBreathBackfireNoSave",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uappFireBreathSaveForHalf",
      "value" = true,
      "comment" = "Save vs. breath weapon for half, in all cases.",
    }, {
      "name" = "uappFierySaveForHalf",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uappFieryHurlAlwaysBreaks",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uappFumblingSolventBathRemoves",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uappTimelessNeverWearsOff",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uappRainbowMetallicContainer",
      "value" = true,
      "comment" = "---- the potion of rainbow hues ---- Must be stored in a metallic container; a full flask holds seven hours of effect; the hue lands in under a segment.",
    }, {
      "name" = "uappVentriloquismFadesOnTime",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uappVitalityPoisonDiseaseProof",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uappVitalityRidesRemaining",
      "value" = true,
      "comment" = "Taken after deprivation, it nullifies the adverse effects and rides the remaining days.",
    }, {
      "name" = "uappAcidResCoversAnyMaterial",
      "value" = true,
      "comment" = "---- the oil of acid resistance (the R396 clean read) ---- Confers virtual invulnerability to acid on skin, cloth, or any other material; one application lasts a full day, but each acid exposure eats the remaining potency by as many minutes as the acid would have caused hit points of damage to exposed flesh.",
    }, {
      "name" = "uappDisenRemovesFromLiving",
      "value" = true,
      "comment" = "---- the oil of disenchantment (the R396 clean read) ---- Removes all enchantment/ charm dweomers placed upon living things; rubbed on an object, the object's dweomer is lost for 21-30 turns (d10 + 20), then returns once the oil has lost its potency. The oil radiates no magic and masks the dweomer of whatever it coats while effective.",
    }, {
      "name" = "uappDisenItemRegainsDweomer",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uappDisenRadiatesMagic",
      "value" = false,
      "comment" = "",
    }, {
      "name" = "uappDisenMasksDweomer",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uappElemInvNormalElementalProof",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uappImpactBluntAndMissiles",
      "value" = true,
      "comment" = "---- the oil of impact (the R396 clean read) ---- Charges blunt weapons and missiles - hurled hammers, hurled clubs, sling stones, sling bullets - with a powerful dweomer; a flask holds 3-5 applications; a hand-held weapon keeps the dweomer 9-12 rounds, a missile carries a single charge.",
    }, {
      "name" = "uappImpactMissileSingleCharge",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uappBeautyWearOffSightedHostile",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uappGlibSpeechUndetectable",
      "value" = true,
      "comment" = "---- the philter of glibness (the R396 clean read) ---- The imbiber speaks fluently - even lies - smoothly and undetectably; magical investigation gives altered results, revealing only a minor stretching of the truth.",
    }, {
      "name" = "uappGlibDetectLieShowsStretching",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uappStamSeemsBeneficial",
      "value" = true,
      "comment" = "---- the philter of stammering and stuttering (the R396 clean read) ---- Seems a beneficial draught (glibness or persuasiveness), but nothing meaningful can be said properly - spell verbal components, scroll text, conversation all fail - and hearers react at -25%.",
    }, {
      "name" = "uappStamMeaningfulSpeechFails",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uappStamHitsSpellComponents",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "uappSharpnessBonusForRoll",
      "comment" = "The dweomer by die roll: 1-2 +1, 3-5 +2, 6-11 +3, 12-16 +4, 17-19 +5, 20 +6.",
      "kind" = "header pin",
      "body" = "static const int k[20] = { 1, 1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 6 }; if (r < 1) return 0; if (r > 20) return 0; return k[r - 1];",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['uappHealthCuresCount']() != 9  or m['uappHealthHealsWounds']()  or m['uappHealthHalfFlaskCuresMax']() != 2  or  m['uappHealthWholeFlaskCuresAll']() != 1",
      "note" = "---- the elixir of health ----",
    }, {
      "expr" = "m['uappLifeNegativeHpPct']() != 20  or m['uappLifeMinus10NeedsFullHp']() != 50  or m['uappLifeWindowRounds']() != 5  or m['uappLifeAfterOneTurnHp']() != 1  or m['uappLifeRestDaysPerNegHp']() != 1  or m['uappLifeCureSeriousDays']() != 2  or m['uappLifeCureCriticalDays']() != 3  or m['uappLifeHealSpellDays']() != 7  or  m['uappLifeDemihumansAffected']() != 1",
      "note" = "---- the elixir of life ----",
    }, {
      "expr" = "strcmp(m['uappMadnessEquivalentSpell'](), \"symbol of insanity\") != 0  or m['uappMadnessSipsToAffect']() != 1  or  m['uappMadnessFlaskDweomerVanishes']() != 1",
      "note" = "---- the elixir of madness ----",
    }, {
      "expr" = "m['uappYouthFullDoseYearsLo']() != 2  or m['uappYouthFullDoseYearsHi']() != 5  or m['uappYouthLowPotencyYearsLo']() != 1  or m['uappYouthLowPotencyYearsHi']() != 3  or  m['uappYouthSippingReducesPotency']() != 1",
      "note" = "---- the elixir of youth ----",
    }, {
      "expr" = "m['uappFireBreathRetainTurns']() != 6  or m['uappFireBreathBackfirePct']() != 10  or m['uappFireBreathBackfireDmgMult']() != 2  or  m['uappFireBreathBackfireNoSave']() != 1  or m['uappFireBreathDraughtsPerFlask']() != 4  or m['uappFireBreathSmallWidthIn']() != 1  or m['uappFireBreathSmallLenIn']() != 2  or m['uappFireBreathSmallDmgLo']() != 3  or m['uappFireBreathSmallDmgHi']() != 12  or m['uappFireBreathFullWidthIn']() != 2  or m['uappFireBreathFullLenIn']() != 8  or m['uappFireBreathFullDmgLo']() != 5  or m['uappFireBreathFullDmgHi']() != 50  or  m['uappFireBreathSaveForHalf']() != 1",
      "note" = "---- the potion of fire breath ----",
    }, {
      "expr" = "m['uappFieryDmgDice']() != 5  or m['uappFieryDmgSides']() != 6  or  m['uappFierySaveForHalf']() != 1  or  m['uappFieryHurlAlwaysBreaks']() != 1  or m['uappFieryBlastRadiusIn']() != 1  or m['uappFieryMaxCreatures']() != 6  or m['uappFieryOpenDmgLo']() != 1  or m['uappFieryOpenDmgHi']() != 4  or m['uappFieryRestopperDice']() != 2  or m['uappFieryRestopperSides']() != 10",
      "note" = "---- the oil of fiery burning ----",
    }, {
      "expr" = "m['uappFumblingPctPerRound']() != 50  or  m['uappFumblingSolventBathRemoves']() != 1",
      "note" = "---- the oil of fumbling ----",
    }, {
      "expr" = "m['uappSharpnessDurationLo']() != 8  or m['uappSharpnessDurationHi']() != 12  or m['uappSharpnessAppsLo']() != 3  or m['uappSharpnessAppsHi']() != 5  or m['uappSharpnessMaxBonus']() != 6  or m['uappSharpnessBonusForRoll'](i + 1) != kBonus[i]  or m['uappSharpnessBonusForRoll'](0) != 0  or m['uappSharpnessBonusForRoll'](21) != 0",
      "note" = "---- the oil of sharpness ----",
    }, {
      "expr" = "m['uappTimelessYearActsAsDays']() != 1  or  m['uappTimelessNeverWearsOff']() != 1  or m['uappTimelessSaveBonus']() != 1  or m['uappTimelessHorsesPerFlask']() != 1  or m['uappTimelessHumansPerFlask']() != 8",
      "note" = "---- the oil of timelessness ----",
    }, {
      "expr" = "m['uappRainbowMetallicContainer']() != 1  or m['uappRainbowHoursPerFlask']() != 7  or m['uappRainbowSegmentMax']() != 1  or m['uappRainbowSparingDraughts']() != 7  or m['uappRainbowDraughtHours']() != 1",
      "note" = "---- rainbow hues ----",
    }, {
      "expr" = "m['uappVentriloquismUses']() != 6  or strcmp(m['uappVentriloquismAsClass'](), \"magic-user\") != 0  or  m['uappVentriloquismFadesOnTime']() != 1",
      "note" = "---- ventriloquism ----",
    }, {
      "expr" = "m['uappVitalityMaxDays']() != 7  or  m['uappVitalityPoisonDiseaseProof']() != 1  or m['uappVitalityHpPerRecovery']() != 1  or m['uappVitalityRecoveryHours']() != 4  or  m['uappVitalityRidesRemaining']() != 1",
      "note" = "---- vitality ----",
    }, {
      "expr" = "m['uappPartCleanCount']() != 19  or m['uappPartGarbledCount']() != 0",
      "note" = "---- the part ledger ----",
    }, {
      "expr" = "m['uadsCategoryCount']() != 8  or m['uadsPotionSplitLo']() != 65  or  m['uadsPotionLowBandIsNewPotions']() != 1  or m['uadsRowBodiesGarble']()",
      "note" = "---- the R375 skeleton seam ----",
    } },
  "audit" = {
      "label" = "R376: the UA new potions prose part 1 pin audit",
      "comment" = "The twelve clean descriptions (pp. 90-92): the four elixirs, fire breath, the oils of fiery burning, fumbling, sharpness, timelessness, rainbow hues, ventriloquism, vitality. The seven garbled descriptions filled by the R396 clean read. The R375 seam cross-checks the skeleton; the census 302 -> 303.",
    },
}
