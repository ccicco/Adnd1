// =========================================================================================
// Adnd1 - rules/wsgtumble.h
// The WSG TUMBLING DAMAGE, R438: Table 18 (the damage from tumbling down a
// moderate or gentle slope - the six rows x the non-slippery, slightly
// slippery and slippery conditions, each entry the abrasion-free feet / the
// abrasion die / the impact distance, from the rough gentle 20/3/50 to the
// smooth moderate 50/3/20) with the prose rules: tumbling is what happens to
// a character who slips and leaves his feet, or releases his handholds and
// footholds, and tumbles down a moderate or gentle slope; the first number is
// the feet tumbled free of abrasion damage, the second is the die rolled (6 =
// 1d6, 3 = 1d3) per 10 feet past that, the third is the minimum distance for
// impact damage (1d6 per full or partial increment of that distance at the
// stop); the impact figures are the worst-case abrupt stop (a gradual stop
// decreases the damage, perhaps eliminating it; a long flat-terrain tumble
// can add abrasion); and an unimpeded tumble covers 100-300 feet per round
// down a gentle slope and 300-500 feet per round down a moderate slope,
// slowest when nonslippery - the round continues the
// movement-across-special-terrain section. Census 362 -> 363.
// census 362 -> 363.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 36; the
// user own copy OCR cross-checked against the archive djvu word layer (16 of
// 18 cells clean; the normal gentle and normal moderate slippery cells are
// garbled or absent from the djvu) and the IIIF full-resolution eye-reads
// (two independent reads of the two disputed rows; every value matched the
// user copy exactly: 50/3/30 and 40/6/20). The smooth moderate die is
// genuinely 3 - the djvu word layer confirms the 1d3 there.
//
// Each Table 18 entry is three numbers: the feet tumbled before abrasion
// damage begins, the abrasion die rolled per 10 feet beyond that, and the
// minimum distance for the 1d6-per-increment impact damage of the stop.
//
namespace rules {

// ---- the tumbling prose rules ----

// The Table 18 row count (the rough, normal and smooth surfaces at the gentle
// and moderate tilts).
inline int wdtRowCount()
    { return 6; }

// Abrasion damage is rolled for every 10 feet of distance greater than the
// first number of the entry.
inline int wdtAbrasionPerFt()
    { return 10; }

// Tumbling is what happens to a character who slips and leaves his feet, or
// releases handholds and footholds, and tumbles down a moderate or gentle
// slope.
inline bool wdtTumbleIsSlipOrRelease()
    { return true; }

// The first number of a Table 18 entry is the distance in feet a character
// can tumble down the slope before taking damage from abrasion.
inline bool wdtFirstNumberFreeFeet()
    { return true; }

// The second number of an entry is the die that is rolled (6 = 1d6, 3 = 1d3)
// to determine abrasion damage for every 10 feet of distance greater than the
// first number.
inline bool wdtSecondNumberDie()
    { return true; }

// The third number of an entry is the minimum distance the character must
// travel in order to take damage from the impact of the stop at the end of
// his tumble.
inline bool wdtThirdNumberImpactDist()
    { return true; }

// Impact damage is 1d6 for a tumble of the indicated distance, and an
// additional 1d6 for each full or partial increment of that distance.
inline bool wdtImpactPerIncrement()
    { return true; }

// The impact figures represent a worst-case situation - when the character
// comes to an abrupt stop at the bottom of the slope.
inline bool wdtImpactWorstCase()
    { return true; }

// If the topography lets the character come to a gradual stop (such as
// tumbling onto a large expanse of flat, featureless terrain), the DM should
// decrease impact damage accordingly - perhaps eliminating it altogether.
inline bool wdtGradualStopDecrease()
    { return true; }

// If the character tumbles across flat terrain for some length of time before
// gradually stopping, the DM could assess some additional abrasion damage to
// account for the extra distance of the fall.
inline bool wdtFlatTumbleExtraAbrasion()
    { return true; }

// ---- Table 18: the tumbling damage cells ----

// The gentle-slope rows begin at index 0 (the rough, normal and smooth gentle
// rows).
inline int wdtGentleRowBase()
    { return 0; }

// The moderate-slope rows begin at index 3 (the rough, normal and smooth
// moderate rows).
inline int wdtModerateRowBase()
    { return 3; }

// The abrasion-free distance in feet for the non-slippery condition, by
// surface row (the rough, normal and smooth surfaces at the gentle and
// moderate tilts).
inline int wdtAbrN(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 10;
        case 2:
            return 30;
        case 3:
            return 20;
        case 4:
            return 40;
        case 5:
            return 30;
        default:
            return 0;
        }
    }

// The abrasion-free distance in feet for the slightly slippery condition.
inline int wdtAbrS(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 20;
        case 2:
            return 40;
        case 3:
            return 30;
        case 4:
            return 50;
        case 5:
            return 40;
        default:
            return 0;
        }
    }

// The abrasion-free distance in feet for the slippery condition.
inline int wdtAbrV(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 30;
        case 2:
            return 50;
        case 3:
            return 40;
        case 4:
            return 60;
        case 5:
            return 50;
        default:
            return 0;
        }
    }

// The abrasion die for the non-slippery condition (6 = 1d6, 3 = 1d3, rolled
// per 10 feet past the free distance).
inline int wdtDieN(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 6;
        case 2:
            return 3;
        case 3:
            return 6;
        case 4:
            return 3;
        case 5:
            return 3;
        default:
            return 0;
        }
    }

// The abrasion die for the slightly slippery condition.
inline int wdtDieS(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 6;
        case 2:
            return 3;
        case 3:
            return 6;
        case 4:
            return 3;
        case 5:
            return 3;
        default:
            return 0;
        }
    }

// The abrasion die for the slippery condition.
inline int wdtDieV(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 6;
        case 2:
            return 3;
        case 3:
            return 6;
        case 4:
            return 3;
        case 5:
            return 3;
        default:
            return 0;
        }
    }

// The minimum impact distance in feet for the non-slippery condition (1d6
// impact damage per full or partial increment).
inline int wdtImpN(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 40;
        case 2:
            return 50;
        case 3:
            return 40;
        case 4:
            return 40;
        case 5:
            return 30;
        default:
            return 0;
        }
    }

// The minimum impact distance in feet for the slightly slippery condition.
inline int wdtImpS(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 30;
        case 2:
            return 40;
        case 3:
            return 30;
        case 4:
            return 30;
        case 5:
            return 20;
        default:
            return 0;
        }
    }

// The minimum impact distance in feet for the slippery condition.
inline int wdtImpV(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 20;
        case 2:
            return 30;
        case 3:
            return 20;
        case 4:
            return 30;
        case 5:
            return 20;
        default:
            return 0;
        }
    }

// ---- the tumble rates ----

// An unimpeded tumble down a gentle slope covers at least 100 feet in one
// round.
inline int wdtGentleRateMin()
    { return 100; }

// An unimpeded tumble down a gentle slope covers at most 300 feet in one
// round.
inline int wdtGentleRateMax()
    { return 300; }

// An unimpeded tumble down a moderate slope covers at least 300 feet per
// round.
inline int wdtModerateRateMin()
    { return 300; }

// An unimpeded tumble down a moderate slope covers at most 500 feet per
// round.
inline int wdtModerateRateMax()
    { return 500; }

// The tumble rates depend on the slipperiness of the surface - the slowest
// rate applies to a nonslippery surface.
inline bool wdtRatesSlowestNonslippery()
    { return true; }

}   // namespace rules
