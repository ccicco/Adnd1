// ====================================================================
// Adnd1 - rules/dmg/rings.h
// R223: the III.C rings footnote pins
// (DMG p.127) - the two footnotes that
// frame the III.C RINGS table:
//   - the (M) ring: magic-user use
//     only (Ring of Wizardry).
//   - the double-dagger rings: these
//     contain the most powerful magical
//     abilities and may possess only a
//     limited number of magical charges
//     before being depleted, at the DM
//     option (Djinni Summoning, Human
//     Influence, Mammal Control,
//     Multiple Wishes, Telekinesis,
//     Three Wishes, and Wizardry -
//     seven rings).
// The row identity is the 24 die bands
// of the engine III.C table
// (dm/treasure.cpp kRings order,
// Contrariness 01-06 through X-Ray
// Vision 00). The row VALUES were
// pinned by the R122 line-diff audit;
// this header pins the footnote flags
// and the band edges. JUDGMENT, named
// in place: Ring of Wizardry prints
// BOTH the double-dagger and the (M);
// both flags are set.
// Pure data + helpers, header-only
// (the grenade.h pattern).
// ====================================================================

#pragma once

// R-refactor: namespace rules -> class Rings (instance methods)
class Rings {
public:
    int ringRowCount();
    int ringRowLo(int i);
    int ringRowHi(int i);
    int ringIsMuOnly(int i);
    int ringMuOnlyCount();
    int ringIsChargeLimited(int i);
    int ringChargeLimitedCount();
};
