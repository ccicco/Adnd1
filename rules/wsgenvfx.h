// =========================================================================================
// Adnd1 - rules/wsgenvfx.h
// The WSG ENVIRONMENT
// EFFECTS, R427: the data
// slice of the
// effects-of-the-
// environment chapter -
// Table 4 (the 13
// temperature bands: the
// Str/Dex/Con reductions
// nonstrenuous and
// strenuous, the Land Move
// fraction, the Attack
// Rolls penalty) and
// Table 5 (the 6 wind
// bands: the missile
// adjustments at point
// blank/short/medium/long,
// the melee penalty, the
// move-against-wind
// fraction) with the
// how-to-use prose and the
// precipitation rules;
// census 352 -> 353.
//
// Provenance: the WSG
// scan (archive.org item
// pdfy-B3Fz83tZ3TV7zOc8),
// printed pp. 21-22; the
// grids read from the IIIF
// page image (the text
// layer mangles the
// fractions and drops the
// 120-or-higher row); the
// prose verified whole
// against the text layer.
//
// Sentinel: 99 = no effect
// (a dash cell) and xx =
// impossible (the missile
// columns); the Land Move
// fraction pins as
// num/den, 99 = none.
namespace rules {

// ---- Table 4: the 13 ----
// ---- temperature bands ----

// The census: 13 bands,
// -40 or lower up to 120
// or higher.
inline int wseTempBandCount()
    { return 13; }
// The Strength reduction,
// nonstrenuous (the left
// of the slash).
inline int wseTempStrNonstren(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 99;
        case 5:
            return 99;
        case 6:
            return 99;
        case 7:
            return 99;
        case 8:
            return 99;
        case 9:
            return 0;
        case 10:
            return -1;
        case 11:
            return -1;
        case 12:
            return -2;
        default:
            return 0;
        }
    }

// The Strength reduction,
// strenuous (the right
// of the slash).
inline int wseTempStrStren(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return -2;
        case 2:
            return -1;
        case 3:
            return -1;
        case 4:
            return 99;
        case 5:
            return 99;
        case 6:
            return 99;
        case 7:
            return 99;
        case 8:
            return 99;
        case 9:
            return -1;
        case 10:
            return -2;
        case 11:
            return -3;
        case 12:
            return -4;
        default:
            return 0;
        }
    }

// The Dexterity reduction,
// nonstrenuous.
inline int wseTempDexNonstren(int b)
    {
        switch (b) {
        case 0:
            return -4;
        case 1:
            return -3;
        case 2:
            return -2;
        case 3:
            return -1;
        case 4:
            return -1;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 99;
        case 8:
            return 99;
        case 9:
            return 99;
        case 10:
            return 0;
        case 11:
            return -1;
        case 12:
            return -1;
        default:
            return 0;
        }
    }

// The Dexterity reduction,
// strenuous.
inline int wseTempDexStren(int b)
    {
        switch (b) {
        case 0:
            return -5;
        case 1:
            return -4;
        case 2:
            return -3;
        case 3:
            return -2;
        case 4:
            return -2;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return 99;
        case 8:
            return 99;
        case 9:
            return 99;
        case 10:
            return -1;
        case 11:
            return -2;
        case 12:
            return -3;
        default:
            return 0;
        }
    }

// The Constitution
// reduction,
// nonstrenuous.
inline int wseTempConNonstren(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 99;
        case 5:
            return 99;
        case 6:
            return 99;
        case 7:
            return 99;
        case 8:
            return 0;
        case 9:
            return -1;
        case 10:
            return -2;
        case 11:
            return -3;
        case 12:
            return -4;
        default:
            return 0;
        }
    }

// The Constitution
// reduction,
// strenuous.
inline int wseTempConStren(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return -2;
        case 2:
            return -1;
        case 3:
            return -1;
        case 4:
            return 99;
        case 5:
            return 99;
        case 6:
            return 99;
        case 7:
            return 99;
        case 8:
            return -1;
        case 9:
            return -2;
        case 10:
            return -3;
        case 11:
            return -4;
        case 12:
            return -5;
        default:
            return 0;
        }
    }

// The Land Move fraction,
// numerator; 99 = no
// reduction.
inline int wseTempLandMoveNum(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 99;
        case 7:
            return 99;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 2;
        case 11:
            return 1;
        case 12:
            return 1;
        default:
            return 0;
        }
    }

// The Land Move fraction,
// denominator; 99 = no
// reduction.
inline int wseTempLandMoveDen(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 99;
        case 7:
            return 99;
        case 8:
            return 4;
        case 9:
            return 4;
        case 10:
            return 3;
        case 11:
            return 2;
        case 12:
            return 2;
        default:
            return 0;
        }
    }

// The Attack Rolls penalty
// on to-hit and damage;
// 99 = no effect.
inline int wseTempAttack(int b)
    {
        switch (b) {
        case 0:
            return -4;
        case 1:
            return -3;
        case 2:
            return -2;
        case 3:
            return -1;
        case 4:
            return -1;
        case 5:
            return 99;
        case 6:
            return 99;
        case 7:
            return 99;
        case 8:
            return 99;
        case 9:
            return -1;
        case 10:
            return -2;
        case 11:
            return -3;
        case 12:
            return -4;
        default:
            return 0;
        }
    }

// The band for a personal
// temperature: 0 = -40 or
// lower ... 12 = 120 or
// higher; 7 = the
// tolerable 21-79 range.
inline int wseTempBandFor(int t)
    {
        if (t <= -40) return 0;
        if (t <= -30) return 1;
        if (t <= -20) return 2;
        if (t <= -10) return 3;
        if (t <= 0) return 4;
        if (t <= 10) return 5;
        if (t <= 20) return 6;
        if (t <= 79) return 7;
        if (t <= 89) return 8;
        if (t <= 99) return 9;
        if (t <= 109) return 10;
        if (t <= 119) return 11;
        return 12;
    }

// ---- the Table 4 rules ----

// The strenuous side of a
// slash applies also when
// strenuous activity was
// performed within this
// many turns.
inline int wseStrenuousWindowTurns()
    { return 2; }
// An exceptional Strength
// score reduces to 18 for
// a nonstrenuous check.
inline int wseExStrCapNonstren()
    { return 18; }
// ... and to 17 for a
// strenuous one.
inline int wseExStrCapStren()
    { return 17; }
// The cavalier and paladin
// percentile Dex/Con scores
// are disregarded - only
// the whole number counts.
inline bool wsePercentileDisregarded()
    { return true; }
// Fractional movement
// results round up: half
// of 9 is 5.
inline bool wseFractionRoundUp()
    { return true; }
// The Attack Rolls penalty
// is cumulative with any
// penalties from the
// Strength reduction.
inline bool wseAttackCumulative()
    { return true; }
// A damage roll can never
// be reduced below this
// by these penalties.
inline int wseDamageFloor()
    { return 1; }
// The table entries assume
// the character is
// appropriately attired.
inline bool wseAssumesAttire()
    { return true; }

// ---- Table 5: the 6 ----
// ---- wind bands ----

// The census: 6 bands, 0-10
// up to 80+.
inline int wseWindBandCount()
    { return 6; }
// The missile adjustment,
// point blank; 99 = xx =
// impossible.
inline int wseWindMissilePb(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return -1;
        case 3:
            return -2;
        case 4:
            return -4;
        case 5:
            return 99;
        default:
            return 0;
        }
    }

// The missile adjustment,
// short range.
inline int wseWindMissileShort(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return -1;
        case 2:
            return -2;
        case 3:
            return -4;
        case 4:
            return -6;
        case 5:
            return 99;
        default:
            return 0;
        }
    }

// The missile adjustment,
// medium range.
inline int wseWindMissileMed(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return -2;
        case 2:
            return -3;
        case 3:
            return 99;
        case 4:
            return 99;
        case 5:
            return 99;
        default:
            return 0;
        }
    }

// The missile adjustment,
// long range.
inline int wseWindMissileLong(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return -3;
        case 2:
            return 99;
        case 3:
            return 99;
        case 4:
            return 99;
        case 5:
            return 99;
        default:
            return 0;
        }
    }

// The melee combat penalty
// on to-hit and
// damage.
inline int wseWindMelee(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return -1;
        case 3:
            return -2;
        case 4:
            return -4;
        case 5:
            return -8;
        default:
            return 0;
        }
    }

// The move-against-wind
// fraction, numerator;
// 99 = no reduction.
inline int wseWindMoveNum(int b)
    {
        switch (b) {
        case 0:
            return 99;
        case 1:
            return 99;
        case 2:
            return 3;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 1;
        default:
            return 0;
        }
    }

// The move-against-wind
// fraction,
// denominator.
inline int wseWindMoveDen(int b)
    {
        switch (b) {
        case 0:
            return 99;
        case 1:
            return 99;
        case 2:
            return 4;
        case 3:
            return 3;
        case 4:
            return 2;
        case 5:
            return 4;
        default:
            return 0;
        }
    }

// The band for a wind
// velocity in miles per
// hour: 0 = 0-10 ... 5 =
// 80+.
inline int wseWindBandFor(int m)
    {
        if (m <= 10) return 0;
        if (m <= 20) return 1;
        if (m <= 30) return 2;
        if (m <= 45) return 3;
        if (m <= 79) return 4;
        return 5;
    }

// ---- the Table 5 rules ----

// The wind velocity is the
// maximum the wind can
// reach, not a constant.
inline bool wseWindIsMaximum()
    { return true; }
// The direction a missile
// is fired in makes no
// difference.
inline bool wseMissileDirNoDiff()
    { return true; }
// xx = impossible: under
// normal circumstances the
// target cannot be hit.
inline bool wseXxIsImpossible()
    { return true; }
// The melee penalty is
// cumulative with the
// Table 4 attack penalty.
inline bool wseMeleeCumulative()
    { return true; }
// Moving perpendicular to
// the wind uses the next
// lower velocity line.
inline bool wsePerpNextLower()
    { return true; }
// When both tables reduce
// movement, use the
// greater reduction.
inline bool wseGreaterOfReductions()
    { return true; }

// ---- the precipitation ----
// ---- rules ----

// Moderate precipitation:
// use the next higher wind
// line (0-10 behaves as
// 11-20).
inline int wsePrecipModerateShift()
    { return 1; }
// Heavy precipitation: two
// lines down (11-20 behaves
// as 31-45).
inline int wsePrecipHeavyShift()
    { return 2; }
// Conditions can never
// become worse than the
// bottom (80+) line.
inline bool wsePrecipCapAtBottom()
    { return true; }

// ---- the ledger ----

// The census of the xx
// cells in the Table 5
// missile columns.
inline int wseXxCensus()
    { return 9; }

}   // namespace rules
