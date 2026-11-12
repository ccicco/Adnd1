// ====================================================================
// Adnd1 - rules/dmg/wonder.h
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

// R-refactor: namespace rules -> class Wonder (instance methods)
class Wonder {
public:
    int rowCount();
    int rowLo(int i);
    int rowHi(int i);
    int chargesPerFunction();
    int rechargeable();
    int slowTurns();
    int deludeRounds();
    int gustForceMultiplier();
    int stinkingRangeInches();
    int rainRounds();
    int rainRadiusInches();
    int summonRhinoLo();
    int summonRhinoHi();
    int summonElephantLo();
    int summonElephantHi();
    int summonMouseLo();
    int summonMouseHi();
    int boltLengthInches();
    int boltWidthHalfInches();
    int butterflyCount();
    int butterflyRounds();
    int enlargeRangeInches();
    int darknessDiameterInches();
    int darknessCenterDistanceInches();
    int grassAreaInches();
    int grassGrowthFactor();
    int vanishMassPounds();
    int vanishVolumeCubicFeet();
    int diminishHeightInches();
    int leavesRangeInches();
    int gemCountLo();
    int gemCountHi();
    int gemBaseValueGp();
    int gemStreamLengthInches();
    int gemDamageHp();
    int gemHitDice();
    int gemHitFaces();
    int colorAreaWidthInches();
    int colorAreaHeightInches();
    int colorBlindLo();
    int colorBlindHi();
    int fleshRangeInches();
};
