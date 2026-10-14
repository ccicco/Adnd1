// =========================================================================================
// Adnd1 - rules/wsgfall.h
// The WSG DAMAGE FROM FALLING, R437: Table 17 (the damage from free fall or
// severe slope - the six fall-distance bands: 10 feet 1d6, 11-20 feet 3d6,
// 21-30 feet 6d6, 31-40 feet 10d6, 41-50 feet 15d6 and 51 feet or more 20d6,
// the maximum) with the prose rules: falling is distinguished from tumbling
// (the former much more liable to cause serious injury or death, the latter
// able in the least perilous circumstances to result in nothing more than a
// minor inconvenience; tumbling down a moderate or gentle slope is Table 18,
// the next round), falling describes a vertical drop (the character releases
// his hold on a cliff face or a severe slope and plummets until hitting a
// surface that stops the fall), the damage is 1d6 cumulative for each 10 feet
// fallen, the figures apply to free fall and to tumbling down a severe slope
// (the recurring impact with the slope plus the stop at the end), on a smooth
// and/or slippery slope the abrasion damage on the way down is not a great
// factor but the greater velocity makes the end result essentially the same
// as a rough slope at a slower speed, and an unimpeded fall covers 1000 feet
// per round in free fall or 600-800 feet per round down a severe slope
// depending on the texture and degree of slipperiness - the round continues
// the movement-across-special-terrain section. Census 361 -> 362.
// census 361 -> 362.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed pp. 35-36;
// the user own copy OCR cross-checked against the archive djvu word layer
// (five of six rows clean; the 11-20 feet dice cell is MISSING from the djvu
// text layer) and the IIIF full-resolution eye-reads (two independent reads
// of the full table; the disputed 3d6 cell matched the user copy exactly).
//
// The Table 17 figures are cumulative damage dice by the fall-distance band -
// 1d6 for each 10 feet fallen, capped at the 20d6 maximum in the
// 51-feet-or-more band. They apply to free fall and to tumbling down a severe
// slope.
//
namespace rules {

// ---- the falling prose rules ----

// The Table 17 damage-band count (10, 11-20, 21-30, 31-40, 41-50 and
// 51-or-more feet).
inline int wdfFallBandCount()
    { return 6; }

// A distinction is made between falling and tumbling - the former is much
// more liable to cause serious injury or death, while the latter can in the
// least perilous circumstances result in nothing more than a minor
// inconvenience.
inline bool wdfFallingVsTumbling()
    { return true; }

// Falling describes a vertical drop: the character releases his hold on a
// cliff face or a severe slope and plummets down until hitting a surface that
// stops the fall.
inline bool wdfFallingIsVerticalDrop()
    { return true; }

// A character takes damage from a fall at the rate of 1d6 cumulative for each
// 10 feet fallen.
inline bool wdfDiceCumulativePer10Ft()
    { return true; }

// The Table 17 damage figures apply whether the character is in free fall or
// tumbling down a severe slope.
inline bool wdfAppliesFreeFallOrSevere()
    { return true; }

// Tumbling down a severe slope, the character is assumed to take some damage
// from recurring impact with the slope itself, in addition to being hurt when
// he comes to a stop at the end of the fall.
inline bool wdfSevereTumbleRecurringImpact()
    { return true; }

// On a smooth and/or slippery severe slope, abrasion damage on the way down
// is not a great factor - but the body reaches a greater velocity, so the end
// result is essentially the same as tumbling down a rough slope at a slower
// speed.
inline bool wdfSmoothSlipperyAbrasionNote()
    { return true; }

// Tumbling - handled by Table 18 - is what happens to a character who slips
// and leaves his feet, or releases his handholds and footholds, and tumbles
// down a moderate or gentle slope; it is pinned by the next round.
inline bool wdfTumbleModerateGentleNext()
    { return true; }

// ---- the fall rates ----

// A character whose fall is not impeded or stopped falls 1000 feet per round
// in free fall.
inline int wdfFreeFallRate()
    { return 1000; }

// An unimpeded fall down a severe slope covers at least 600 feet per round.
inline int wdfSevereRateMin()
    { return 600; }

// An unimpeded fall down a severe slope covers at most 800 feet per round,
// depending on the texture and degree of slipperiness of the slope.
inline int wdfSevereRateMax()
    { return 800; }

// ---- Table 17: the free-fall and severe-slope damage ----

// The band-minimum distance of the fall in feet by band row (the 10, 11-20,
// 21-30, 31-40, 41-50 and 51-or-more-feet bands; the final band is
// open-ended).
inline int wdfFallMinFt(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 11;
        case 2:
            return 21;
        case 3:
            return 31;
        case 4:
            return 41;
        case 5:
            return 51;
        default:
            return 0;
        }
    }

// The cumulative damage dice for the band (1d6 for each 10 feet fallen; 20d6
// is the maximum).
inline int wdfFallDice(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 6;
        case 3:
            return 10;
        case 4:
            return 15;
        case 5:
            return 20;
        default:
            return 0;
        }
    }

// The 51-feet-or-more band damage is 20d6 - the maximum.
inline int wdfMaxFallDice()
    { return 20; }

}   // namespace rules
