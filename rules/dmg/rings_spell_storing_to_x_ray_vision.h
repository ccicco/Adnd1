// ====================================================================
// Adnd1 - rules/dmg/rings_spell_storing_to_x_ray_vision.h
// R256: the III.C rings explanation prose part 3
// pins (DMG pp.139-140) - Spell Storing
// through X-Ray Vision, the final ten
// rings of the EXPLANATIONS AND
// DESCRIPTIONS section (upload lines
// ~10458-10561):
//   - Spell Storing: 2-5 (d4+1) spells;
//     cleric d6, 6 rolls d4 instead;
//     magic-user d8, 8 rolls d6 instead;
//     druid and illusionist as cleric;
//     properties fixed once determined;
//     a 12th level magic-user restores
//     a 6th level spell; 5 segments each.
//   - Spell Turning: 3 exceptions (area
//     spells, touch, devices; a scroll
//     spell is not a device); percentile
//     rounding 1-5 down, 6-9 up, 05 = 0%
//     and 96 = 100%; saves +1 per 10%
//     below 100% (80% = +2 ... 10% = +9);
//     the 09-or-less / 91-or-more band
//     excludes the special save; 5% per
//     10% turned (11-19: roll 20 saves);
//     the maze example: 34% turned, the
//     fighter saves 15%, the illusionist
//     30% on 15-20; remove to receive;
//     psionics are not spell casting;
//     the 4-row resonating field table.
//   - Swimming: 21 inch base; 50 foot
//     dive; 1.5 feet of depth per 10
//     feet; 4 rounds breath; 4 hours
//     then 1 hour rest; afloat in all
//     but typhoon-like conditions.
//   - Telekinesis: the 5-row weight
//     table 250/500/1000/2000/4000 gp;
//     1 segment to begin; double-
//     dagger flagged.
//   - Three Wishes: 3 wishes; 25%
//     (01-25) are 3 limited wishes;
//     double-dagger flagged.
//   - Warmth: restores 1 hp per turn;
//     cold saves +2; cold damage -1
//     per die.
//   - Water Walking: any liquid; 1200
//     pounds; 1.5 foot by 1 inch
//     depressions per 100 pounds.
//   - Weakness: cursed; 1 point per
//     turn to 3; invisible at will
//     doubles the loss; remove curse
//     then dispel magic; 5% reversed
//     berserk (to 18s, 1 per turn,
//     then always melee); rest 1 day
//     per point.
//   - Wizardry: MU only (other classes
//     can neither use nor understand);
//     the 8-row doubling table; (M) and
//     double-dagger flagged.
//   - X-Ray Vision: 20 feet; the
//     5-substance penetration table;
//     100 sq ft per round; 90% secret
//     doors; 1 constitution per use
//     more than once every 6 turns
//     (2 points at 3 turns per hour,
//     3 at 4); 2 points per day rest;
//     exhausted at 2, resume at 3.
// The ten rings are the engine III.C
// table rows 64-100 (dm/treasure.cpp
// kRings, the R223 rings.h band pins)
// - cross-checked in the audit, with
// the Telekinesis / Three Wishes /
// Wizardry double-daggers cross-pinned
// against the R255-fixed charge array.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

// R-refactor: namespace rules -> class Rings_spell_storing_to_x_ray_vision (instance methods)
class Rings_spell_storing_to_x_ray_vision {
public:
    int rgpSpellStoringSpellLo();
    int rgpSpellStoringSpellHi();
    int rgpSpellStoringSpellDice();
    int rgpSpellStoringSpellPlus();
    int rgpSpellStoringClericFaces();
    int rgpSpellStoringClericSwapOn();
    int rgpSpellStoringClericSwapFaces();
    int rgpSpellStoringMuFaces();
    int rgpSpellStoringMuSwapOn();
    int rgpSpellStoringMuSwapFaces();
    int rgpSpellStoringRestoreMULevel();
    int rgpSpellStoringRestoreSpellLevel();
    int rgpSpellStoringCastSegments();
    int rgpSpellTurningExceptionCount();
    int rgpSpellTurningScrollIsDevice();
    int rgpSpellTurningRoundDownMax();
    int rgpSpellTurningRoundUpMin();
    int rgpSpellTurningRoundUpAdd();
    int rgpSpellTurningFloorExample();
    int rgpSpellTurningCeilExample();
    int rgpSpellTurningSaveAdjPer10Pct();
    int rgpSpellTurningSaveAdjAt80();
    int rgpSpellTurningSaveAdjAt10();
    int rgpSpellTurningSpecialSaveLowMax();
    int rgpSpellTurningSpecialSaveHighMin();
    int rgpSpellTurningSaveChancePer10Pct();
    int rgpSpellTurningLowBandSaveRoll();
    int rgpSpellTurningExampleTurnedPct();
    int rgpSpellTurningExampleWearerSave();
    int rgpSpellTurningExampleCasterSave();
    int rgpSpellTurningExampleCasterRollLo();
    int rgpSpellTurningMustRemoveToReceive();
    int rgpSpellTurningPsionicIsSpellcasting();
    int rgpSpellTurningResonantRowCount();
    int rgpSpellTurningResonantLo(int i);
    int rgpSpellTurningResonantHi(int i);
    int rgpSwimmingBaseSpeedInches();
    int rgpSwimmingDiveFeet();
    int rgpSwimmingDiveDepthInchesPer10Feet();
    int rgpSwimmingBreathRounds();
    int rgpSwimmingSurfaceHours();
    int rgpSwimmingRestHours();
    int rgpSwimmingAfloatExceptTyphoon();
    int rgpTelekinesisRowCount();
    int rgpTelekinesisRowLo(int i);
    int rgpTelekinesisRowHi(int i);
    int rgpTelekinesisRowGp(int i);
    int rgpTelekinesisStartSegments();
    int rgpTelekinesisDaggerFlag();
    int rgpThreeWishesWishCount();
    int rgpThreeWishesLimitedPct();
    int rgpThreeWishesLimitedBandLo();
    int rgpThreeWishesLimitedBandHi();
    int rgpThreeWishesDaggerFlag();
    int rgpWarmthRestoreHpPerTurn();
    int rgpWarmthColdSaveBonus();
    int rgpWarmthColdDamagePerDieMod();
    int rgpWaterWalkingMaxLoadPounds();
    int rgpWaterWalkingDepressionLengthInches();
    int rgpWaterWalkingDepressionDepthInches();
    int rgpWaterWalkingDepressionPerPounds();
    int rgpWeaknessLossPerTurn();
    int rgpWeaknessFloorScore();
    int rgpWeaknessInvisibleFlag();
    int rgpWeaknessInvisibleLossMultiplier();
    int rgpWeaknessBerserkChancePct();
    int rgpWeaknessBerserkTargetScore();
    int rgpWeaknessBerserkGainPerTurn();
    int rgpWeaknessRestDaysPerPoint();
    int rgpWizardryRowCount();
    int rgpWizardryRowLo(int i);
    int rgpWizardryRowHi(int i);
    int rgpWizardryRowSpellLo(int i);
    int rgpWizardryRowSpellHi(int i);
    int rgpWizardryMuOnlyFlag();
    int rgpWizardryDaggerFlag();
    int rgpXRayVisionRangeFeet();
    int rgpXRayScanSqFtPerRound();
    int rgpXRaySecretFindPct();
    int rgpXRayDrainIntervalTurns();
    int rgpXRayDrainAmount();
    int rgpXRayDrainAt3TurnsPerHour();
    int rgpXRayDrainAt4TurnsPerHour();
    int rgpXRayConRecoveryPerDay();
    int rgpXRayExhaustedScore();
    int rgpXRayResumeScore();
    int rgpXRaySubstanceCount();
    int rgpXRaySubstanceRateInches(int i);
    int rgpXRaySubstanceMaxInches(int i);
};
