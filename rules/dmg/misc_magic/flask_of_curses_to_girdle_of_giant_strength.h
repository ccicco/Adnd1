// ====================================================================
// Adnd1 - rules/dmg/misc_magic/flask_of_curses_to_girdle_of_giant_strength.h
// R267: the III.E misc magic explanation prose part 11
// (DMG p.136-137) - Flask of Curses through the Girdle
// of Giant Strength, part2 lines 481-530 (global =
// 11065 + part2 line). ONE page header strips (493,
// the TREASURE page) cutting the Gem of Brightness
// paragraph mid-sentence (one seam, restored). 63
// accessors: 49 scalars + 14 array walkers (the giant
// strength and rock hurling tables), no name
// collisions with miscprose1.h through miscprose10.h.
// The slice pins kMisc3 rows 1-9, the (C, F, T) marks
// riding rows 4, 5, 8 and 9. Pure data + helpers,
// header-only (the grenade.h pattern).
// ---- re-split from miscmagic_alchemy_jug_to_wings_of_flying.h (the R257-R279 merge) ----
// ====================================================================
#pragma once

class Miscmagic_flask_of_curses_to_girdle_of_giant_strength {
public:
    int mmpFlaskCurseOnFirstOpen();
    int mmpFlaskHarmlessAfterUse();
    int mmpGauntDexBoostLow();
    int mmpGauntDexBoostMid();
    int mmpGauntDexBoostHigh();
    int mmpGauntDexThiefLevel();
    int mmpGauntDexThiefBonusPct();
    int mmpGauntFumbDropPct();
    int mmpGauntFumbDexPenalty();
    int mmpGauntFumbRemoveCurseOnly();
    int mmpGauntOgreStrength();
    int mmpGauntOgreStrengthPercentile();
    int mmpGauntOgreHitBonus();
    int mmpGauntOgreDmgBonus();
    int mmpGauntSwimUnderwaterInches();
    int mmpGauntSwimSurfaceInches();
    int mmpGauntSwimClimbSuccessPct();
    int mmpGauntSwimThiefSuccessTenthPct();
    int mmpGemBrightLightSorts();
    int mmpGemBrightConeLengthFeet();
    int mmpGemBrightConeRadiusHalfFeet();
    int mmpGemBrightRayDiameterFeet();
    int mmpGemBrightRayLengthFeet();
    int mmpGemBrightDazzleMinRounds();
    int mmpGemBrightDazzleMaxRounds();
    int mmpGemBrightRayCharges();
    int mmpGemBrightFlashLengthFeet();
    int mmpGemBrightFlashRadiusFeet();
    int mmpGemBrightBlindMinRounds();
    int mmpGemBrightBlindMaxRounds();
    int mmpGemBrightEyePenaltyMin();
    int mmpGemBrightEyePenaltyMax();
    int mmpGemBrightFlashCharges();
    int mmpGemBrightTotalCharges();
    int mmpGemBrightDarknessDrainCharges();
    int mmpGemBrightDarknessRoundUseless();
    int mmpGemBrightDarknessDayUseless();
    int mmpGemBrightDarknessExpelCharges();
    int mmpGemSeeCursoryRangeInches();
    int mmpGemSeeCarefulRangeInches();
    int mmpGemSeeCursoryAreaFeet();
    int mmpGemSeeCursoryRounds();
    int mmpGemSeeCarefulAreaFeet();
    int mmpGemSeeCarefulRounds();
    int mmpGemSeeHallucinationPct();
    int mmpGirdleSexWishRestorePct();
    int mmpGirdleSexSexlessPct();
    int mmpGirdleGiantTypeCount();
    int mmpGirdleGiantRockDmgMin();
    int mmpGirdleGiantDiceLo(int i);
    int mmpGirdleGiantDiceHi(int i);
    int mmpGirdleGiantStrength(int i);
    int mmpGirdleGiantHitBonus(int i);
    int mmpGirdleGiantDmgBonus(int i);
    int mmpGirdleGiantOpenDoorsTop(int i);
    int mmpGirdleGiantOpenDoorsBottom(int i);
    int mmpGirdleGiantOpenChances(int i);
    int mmpGirdleGiantOpenOutOf(int i);
    int mmpGirdleGiantWeightAllowance(int i);
    int mmpGirdleGiantRangeInches(int i);
    int mmpGirdleGiantRockDmgMax(int i);
    int mmpGirdleGiantRockWeight(int i);
    int mmpGirdleGiantBendBarsPct(int i);
};
