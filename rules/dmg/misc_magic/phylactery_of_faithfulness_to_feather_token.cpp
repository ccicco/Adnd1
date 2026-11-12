// R-refactor: re-split from miscmagic_alchemy_jug_to_wings_of_flying.cpp - definitions
#include "rules/dmg/misc_magic/phylactery_of_faithfulness_to_feather_token.h"

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpLongYearsSlowPct() {
    // slows the aging process by one-quarter
    return 25;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpLongYearsDonAge() {
    // the example cleric dons the device at age 20
    return 20;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpLongYearsMonthsPerYear() {
    // he or she will age 9 months every 12
    return 9;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpLongYearsPhysicalAge() {
    // in 12 chronological years, physically 29
    return 29;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpLongYearsChronAge() {
    // rather than the naive 32
    return 32;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpLongYearsReverseOneIn() {
    // 1 in 20 cursed to operate in reverse
    return 20;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpAttentionMinLevel() {
    // at 10th or higher level the deity most
    // powerful enemy interferes directly
    return 10;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpPipeGiantRatMin() {
    // attracts from 10-60 giant rats
    return 10;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpPipeGiantRatMax() {
    // the giant rat ceiling
    return 60;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpPipeGiantRatPct() {
    // giant rats at 80 percent
    return 80;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpPipeNormalRatMin() {
    // or from 30-180 normal rats
    return 30;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpPipeNormalRatMax() {
    // the normal rat ceiling
    return 180;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpPipeNormalRatPct() {
    // normal rats at 20 percent
    return 20;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpPipeCallRangeInches() {
    // if either or both are within 40 inches
    return 40;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpPipeDelayPerInches() {
    // a 1 round delay per each 5 inches traveled
    return 5;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpPipeObeyPct() {
    // 95 percent likely to obey while the piper plays
    return 95;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpPipeReplayObeyPct() {
    // called again: 70 percent come and obey
    return 70;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpPipeReplayTurnPct() {
    // but 30 percent turn upon the piper
    return 30;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpPipeTakeoverPctPerRound() {
    // 30 percent per round to take over control
    // from a controlling creature
    return 30;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpPipeKeepPct() {
    // 70 percent chance of maintaining control
    return 70;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpHoleDiameterFeet() {
    // opened fully, 6 feet in diameter
    return 6;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpHoleDepthFeet() {
    // an extra-dimensional hole 10 feet deep
    return 10;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpHoleBreathTurns() {
    // breath runs out after about a turn
    return 1;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpHoleGateRadiusFeet() {
    // creatures within a 10 foot radius are drawn
    // to the plane, both items destroyed
    return 10;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpTokenUses() {
    // each token is usable but once
    return 1;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpTokenRowLo(int i) {
    // the printed token band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 5, 8, 11, 14, 19,
    };
    return t[i];
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpTokenRowHi(int i) {
    // the printed token band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        4, 7, 10, 13, 18, 20,
    };
    return t[i];
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpTokenAnchorDays() {
    // the anchor moors a craft immobile for 1 full day
    return 1;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpTokenBirdDays() {
    // the bird equals a roc of the largest size
    // (1 day duration)
    return 1;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpTokenFanHours() {
    // the fan works up to eight hours a day
    return 8;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpTokenSwanSpeedInches() {
    // the swan boat swims at 24 inch speed
    return 24;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpTokenSwanHorses() {
    // it carries 8 horses and gear
    return 8;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpTokenSwanMen() {
    // or 32 men
    return 32;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpTokenSwanDays() {
    // duration 1 day
    return 1;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpTokenTreeTrunkFeet() {
    // a great oak with a 6 foot diameter trunk
    return 6;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpTokenTreeHeightFeet() {
    // 60 foot height
    return 60;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpTokenTreeTopFeet() {
    // 40 foot top diameter
    return 40;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpTokenWhipPlus() {
    // a +1 weapon
    return 1;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpTokenWhipLevel() {
    // 9th level fighter to hit probability
    return 9;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpTokenWhipDmgMin() {
    // 2-7 hit points damage
    return 2;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpTokenWhipDmgMax() {
    return 7;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpTokenWhipBindMin() {
    // save versus magic or be bound fast
    // for 2-7 rounds
    return 2;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpTokenWhipBindMax() {
    return 7;
}

int Miscmagic_phylactery_of_faithfulness_to_feather_token::mmpTokenWhipTurns() {
    // wielded for up to 6 turns
    return 6;
}
