// ====================================================================
// Adnd1 - rules/dmg/misc_magic/candle_of_invocation_to_cloak_of_protection.h
// R261: the III.E misc magic explanation prose part 5
// (DMG p.132) - Candle of Invocation through Cloak
// of Protection, part2 lines 155-220 (global =
// 11065 + part2 line). THREE page headers strip
// (155 TABLE (III.E.) 2., 159 and 183 both the
// TREASURE page); TWO seams pin exactly: the Candle
// (line 157 ends one of the, line 161 continues
// nine alignments) and the Cloak of Displacement
// (line 180 ends with such as spells,, line 185
// continues gaze weapon attacks). 60 accessors:
// 50 scalars + 10 array walkers, no name
// collisions with miscprose1.h through
// miscprose4.h. The slice completes kMisc2 rows
// 0-10; the per-plus asterisk sits on row 10
// (Cloak of Protection 33-55) - the R226 pin is
// correct, no R260-style off-by-one.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ---- re-split from miscmagic_alchemy_jug_to_wings_of_flying.h (the R257-R279 merge) ----
// ====================================================================
#pragma once

class Miscmagic_candle_of_invocation_to_cloak_of_protection {
public:
    int mmpCandleAlignments();
    int mmpCandleClericLevelBoost();
    int mmpCandleBurnHours();
    int mmpCandleGateSpell();
    int mmpCarpetRowCount();
    int mmpCenserAirHd();
    int mmpCenserAirMedBonusPerDie();
    int mmpCenserAirWidthInches();
    int mmpCenserAirHeightInches();
    int mmpCenserAirTurnsIfExtinguished();
    int mmpCenserHostileMin();
    int mmpCenserHostileMax();
    int mmpCenserHostilePerRound();
    int mmpChimeOpenLengthInches();
    int mmpChimeOpenWizardLockLevel();
    int mmpChimeOpenRoundPerFunction();
    int mmpChimeOpenSoundingsMin();
    int mmpChimeOpenSoundingsMax();
    int mmpChimeOpenChargesMin();
    int mmpChimeOpenChargesMax();
    int mmpChimeOpenChargesDieSides();
    int mmpChimeOpenChargesDieMult();
    int mmpChimeHungerRadiusInches();
    int mmpChimeHungerMinEatRounds();
    int mmpDisplacementMinFeet();
    int mmpDisplacementMaxFeet();
    int mmpDisplacementAcBonus();
    int mmpDisplacementSaveBonus();
    int mmpDisplacementHumanoidPct();
    int mmpDisplacementSmallPct();
    int mmpElvenkindRowCount();
    int mmpElvenkindOutdoorNaturalRows();
    int mmpElvenkindOutdoorOtherRows();
    int mmpElvenkindUndergroundRows();
    int mmpElvenkindHumanoidPct();
    int mmpElvenkindSmallPct();
    int mmpMantaRayLikenessPct();
    int mmpMantaRayMoveInches();
    int mmpMantaRayAc();
    int mmpMantaRayTailDmgMin();
    int mmpMantaRayTailDmgMax();
    int mmpMantaRayTailStun();
    int mmpMantaRaySaltWaterTrigger();
    int mmpPoisonCloakRevivalPctPenalty();
    int mmpPoisonCloakRemoveCurseDestroys();
    int mmpPoisonCloakNeutralizeNoEffect();
    int mmpCloakProtRowCount();
    int mmpCloakProtAcPerPlus();
    int mmpCloakProtSavePerPlus();
    int mmpCloakProtExampleBaseAc();
    int mmpCarpetBandLo(int i);
    int mmpCarpetBandHi(int i);
    int mmpCarpetWidthFeet(int i);
    int mmpCarpetLengthFeet(int i);
    int mmpCarpetPersons(int i);
    int mmpCarpetSpeedInches(int i);
    int mmpElvenkindInvisibilityPct(int i);
    int mmpCloakProtBandLo(int i);
    int mmpCloakProtBandHi(int i);
    int mmpCloakProtPlus(int i);
};
