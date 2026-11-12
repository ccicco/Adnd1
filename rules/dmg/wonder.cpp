// R-refactor: split from wonder.h - definitions
#include "rules/dmg/wonder.h"

int Wonder::wonderRowCount() {
    // the 19 die bands of the effect table
    return 19;
}

int Wonder::wonderRowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 18) i = 18;
    static const int t[19] = {
        1, 11, 19, 26, 31, 34, 37, 47, 50, 54,
        59, 63, 66, 70, 80, 85, 88, 91, 98,
    };
    return t[i];
}

int Wonder::wonderRowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 18) i = 18;
    static const int t[19] = {
        10, 18, 25, 30, 33, 36, 46, 49, 53, 58,
        62, 65, 69, 79, 84, 87, 90, 97, 100,
    };
    return t[i];
}

int Wonder::wonderChargesPerFunction() {
    // the wand uses 1 charge per function
    return 1;
}

int Wonder::wonderRechargeable() {
    // it may not be recharged
    return 0;
}

int Wonder::wonderSlowTurns() {
    // band 01-10: slow creature pointed at
    // for 1 turn
    return 1;
}

int Wonder::wonderDeludeRounds() {
    // band 11-18: deludes the wielder for
    // 1 round into believing the wand
    // functions as indicated by a second
    // die roll
    return 1;
}

int Wonder::wonderGustForceMultiplier() {
    // band 19-25: gust of wind, double
    // force of the spell
    return 2;
}

int Wonder::wonderStinkingRangeInches() {
    // band 26-30: stinking cloud at 3"
    // range
    return 3;
}

int Wonder::wonderRainRounds() {
    // band 31-33: heavy rain falls for
    // 1 round
    return 1;
}

int Wonder::wonderRainRadiusInches() {
    // in a 6" radius of the wand wielder
    return 6;
}

int Wonder::wonderSummonRhinoLo() {
    // band 34-36: summon rhino on 1-25
    return 1;
}

int Wonder::wonderSummonRhinoHi() {
    return 25;
}

int Wonder::wonderSummonElephantLo() {
    // elephant on 26-50
    return 26;
}

int Wonder::wonderSummonElephantHi() {
    return 50;
}

int Wonder::wonderSummonMouseLo() {
    // mouse on 51-00
    return 51;
}

int Wonder::wonderSummonMouseHi() {
    return 100;
}

int Wonder::wonderBoltLengthInches() {
    // band 37-46: lightning bolt 7" long
    return 7;
}

int Wonder::wonderBoltWidthHalfInches() {
    // the bolt is 0.5" wide - pinned as
    // 1 half-inch, continuing the R247
    // half-inch workaround
    return 1;
}

int Wonder::wonderButterflyCount() {
    // band 47-49: a stream of 600 large
    // butterflies pour forth
    return 600;
}

int Wonder::wonderButterflyRounds() {
    // they flutter around for 2 rounds,
    // blinding everyone including the
    // wielder
    return 2;
}

int Wonder::wonderEnlargeRangeInches() {
    // band 50-53: enlarge the target if
    // in 6" of the wand
    return 6;
}

int Wonder::wonderDarknessDiameterInches() {
    // band 54-58: darkness in a 3"
    // diameter hemisphere
    return 3;
}

int Wonder::wonderDarknessCenterDistanceInches() {
    // at 3" center distance from the wand
    return 3;
}

int Wonder::wonderGrassAreaInches() {
    // band 59-62: grass grows in an area
    // of 16" square before the wand
    return 16;
}

int Wonder::wonderGrassGrowthFactor() {
    // or grass there grows to 10 times
    // normal size
    return 10;
}

int Wonder::wonderVanishMassPounds() {
    // band 63-65: vanish any non-living
    // object of up to 1,000 pounds mass
    return 1000;
}

int Wonder::wonderVanishVolumeCubicFeet() {
    // and up to 30 cubic feet in size
    return 30;
}

int Wonder::wonderDiminishHeightInches() {
    // band 66-69: diminish the wielder
    // to 1" height
    return 1;
}

int Wonder::wonderLeavesRangeInches() {
    // band 85-87: leaves grow from the
    // target if in 6" of the wand
    return 6;
}

int Wonder::wonderGemCountLo() {
    // band 88-90: 10-40 gems shoot forth
    return 10;
}

int Wonder::wonderGemCountHi() {
    return 40;
}

int Wonder::wonderGemBaseValueGp() {
    // each gem has a 1 g.p. base value
    return 1;
}

int Wonder::wonderGemStreamLengthInches() {
    // they shoot forth in a 3" long
    // stream
    return 3;
}

int Wonder::wonderGemDamageHp() {
    // each causing 1 h.p. of damage to
    // any creature in path
    return 1;
}

int Wonder::wonderGemHitDice() {
    // roll 5d4 for the number of hits
    return 5;
}

int Wonder::wonderGemHitFaces() {
    return 4;
}

int Wonder::wonderColorAreaWidthInches() {
    // band 91-97: shimmering colors
    // dance over a 4" x 3" area
    return 4;
}

int Wonder::wonderColorAreaHeightInches() {
    return 3;
}

int Wonder::wonderColorBlindLo() {
    // creatures therein are blinded
    // for 1-6 rounds
    return 1;
}

int Wonder::wonderColorBlindHi() {
    return 6;
}

int Wonder::wonderFleshRangeInches() {
    // band 98-00: flesh to stone or the
    // reverse if the target is within 6"
    return 6;
}
