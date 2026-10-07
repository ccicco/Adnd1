// ====================================================================
// Adnd1 - rules/wonder.h
// R248: the III.D wand of wonder effect
// table pins (DMG p.145) - the 19 die
// bands 01-10 through 98-00 and the
// effect numeric facts (upload lines
// ~10867-10947):
//   - the table bands: slow creature
//     pointed at for 1 turn (01-10);
//     delude the wielder 1 round, a
//     second die roll (11-18); gust of
//     wind at double force (19-25);
//     stinking cloud at 3" range
//     (26-30); heavy rain 1 round in a
//     6" radius (31-33); summon rhino
//     1-25, elephant 26-50, mouse
//     51-00 (34-36); lightning bolt
//     7" x 0.5" as wand - the width
//     pinned as 1 half-inch, continuing
//     the R247 half-inch workaround
//     (37-46); 600 large butterflies 2
//     rounds blinding everyone
//     including the wielder (47-49);
//     enlarge within 6" (50-53);
//     darkness in a 3" diameter
//     hemisphere at 3" center distance
//     (54-58); grass in a 16" square
//     or grows to 10 times normal size
//     (59-62); vanish non-living up to
//     1,000 pounds mass and 30 cubic
//     feet (63-65); diminish the
//     wielder to 1" height (66-69);
//     fireball as wand (70-79);
//     invisibility covers the wielder
//     (80-84); leaves grow within 6"
//     (85-87); 10-40 gems of 1 g.p.
//     base value in a 3" stream, each
//     causing 1 h.p., roll 5d4 for the
//     number of hits (88-90);
//     shimmering colors over 4" x 3",
//     blinded 1-6 rounds (91-97);
//     flesh to stone or reverse within
//     6" (98-00).
//   - the wand uses 1 charge per
//     function and may not be
//     recharged.
// The bands tile 01-100 with no gaps
// or overlaps. The wonder is the
// engine III.D table row 30
// (dm/treasure.cpp kRods, bands
// 95-100) - cross-checked against
// the R224 rodswands.h pins in the
// audit.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int wonderRowCount() {
    // the 19 die bands of the effect table
    return 19;
}

inline int wonderRowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 18) i = 18;
    static const int t[19] = {
        1, 11, 19, 26, 31, 34, 37, 47, 50, 54,
        59, 63, 66, 70, 80, 85, 88, 91, 98,
    };
    return t[i];
}

inline int wonderRowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 18) i = 18;
    static const int t[19] = {
        10, 18, 25, 30, 33, 36, 46, 49, 53, 58,
        62, 65, 69, 79, 84, 87, 90, 97, 100,
    };
    return t[i];
}

inline int wonderChargesPerFunction() {
    // the wand uses 1 charge per function
    return 1;
}

inline int wonderRechargeable() {
    // it may not be recharged
    return 0;
}

inline int wonderSlowTurns() {
    // band 01-10: slow creature pointed at
    // for 1 turn
    return 1;
}

inline int wonderDeludeRounds() {
    // band 11-18: deludes the wielder for
    // 1 round into believing the wand
    // functions as indicated by a second
    // die roll
    return 1;
}

inline int wonderGustForceMultiplier() {
    // band 19-25: gust of wind, double
    // force of the spell
    return 2;
}

inline int wonderStinkingRangeInches() {
    // band 26-30: stinking cloud at 3"
    // range
    return 3;
}

inline int wonderRainRounds() {
    // band 31-33: heavy rain falls for
    // 1 round
    return 1;
}

inline int wonderRainRadiusInches() {
    // in a 6" radius of the wand wielder
    return 6;
}

inline int wonderSummonRhinoLo() {
    // band 34-36: summon rhino on 1-25
    return 1;
}

inline int wonderSummonRhinoHi() {
    return 25;
}

inline int wonderSummonElephantLo() {
    // elephant on 26-50
    return 26;
}

inline int wonderSummonElephantHi() {
    return 50;
}

inline int wonderSummonMouseLo() {
    // mouse on 51-00
    return 51;
}

inline int wonderSummonMouseHi() {
    return 100;
}

inline int wonderBoltLengthInches() {
    // band 37-46: lightning bolt 7" long
    return 7;
}

inline int wonderBoltWidthHalfInches() {
    // the bolt is 0.5" wide - pinned as
    // 1 half-inch, continuing the R247
    // half-inch workaround
    return 1;
}

inline int wonderButterflyCount() {
    // band 47-49: a stream of 600 large
    // butterflies pour forth
    return 600;
}

inline int wonderButterflyRounds() {
    // they flutter around for 2 rounds,
    // blinding everyone including the
    // wielder
    return 2;
}

inline int wonderEnlargeRangeInches() {
    // band 50-53: enlarge the target if
    // in 6" of the wand
    return 6;
}

inline int wonderDarknessDiameterInches() {
    // band 54-58: darkness in a 3"
    // diameter hemisphere
    return 3;
}

inline int wonderDarknessCenterDistanceInches() {
    // at 3" center distance from the wand
    return 3;
}

inline int wonderGrassAreaInches() {
    // band 59-62: grass grows in an area
    // of 16" square before the wand
    return 16;
}

inline int wonderGrassGrowthFactor() {
    // or grass there grows to 10 times
    // normal size
    return 10;
}

inline int wonderVanishMassPounds() {
    // band 63-65: vanish any non-living
    // object of up to 1,000 pounds mass
    return 1000;
}

inline int wonderVanishVolumeCubicFeet() {
    // and up to 30 cubic feet in size
    return 30;
}

inline int wonderDiminishHeightInches() {
    // band 66-69: diminish the wielder
    // to 1" height
    return 1;
}

inline int wonderLeavesRangeInches() {
    // band 85-87: leaves grow from the
    // target if in 6" of the wand
    return 6;
}

inline int wonderGemCountLo() {
    // band 88-90: 10-40 gems shoot forth
    return 10;
}

inline int wonderGemCountHi() {
    return 40;
}

inline int wonderGemBaseValueGp() {
    // each gem has a 1 g.p. base value
    return 1;
}

inline int wonderGemStreamLengthInches() {
    // they shoot forth in a 3" long
    // stream
    return 3;
}

inline int wonderGemDamageHp() {
    // each causing 1 h.p. of damage to
    // any creature in path
    return 1;
}

inline int wonderGemHitDice() {
    // roll 5d4 for the number of hits
    return 5;
}

inline int wonderGemHitFaces() {
    return 4;
}

inline int wonderColorAreaWidthInches() {
    // band 91-97: shimmering colors
    // dance over a 4" x 3" area
    return 4;
}

inline int wonderColorAreaHeightInches() {
    return 3;
}

inline int wonderColorBlindLo() {
    // creatures therein are blinded
    // for 1-6 rounds
    return 1;
}

inline int wonderColorBlindHi() {
    return 6;
}

inline int wonderFleshRangeInches() {
    // band 98-00: flesh to stone or the
    // reverse if the target is within 6"
    return 6;
}

}  // namespace rules

