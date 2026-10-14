// =========================================================================================
// Adnd1 - rules/wsgdress.h
// The WSG DRESSING FOR
// THE WEATHER, R426: the
// first WSG pin round
// after the arc opener.
// The personal
// temperature system pins
// whole: the four
// clothing categories
// (the temperature
// ranges, the
// encumbrance
// equivalents, the outfit
// costs), Table 3 (the
// 15 attire rows x the 4
// temperature columns,
// cumulative), the
// protected/unprotected
// rules, the exertion
// regimes and the
// clothing-as-armor
// option; census
// 351 -> 352.
//
// Provenance: the WSG
// scan (archive.org item
// pdfy-B3Fz83tZ3TV7zOc8),
// printed pp. 18-20; the
// Table 3 grid, the row
// set and the clothing
// costs read from the
// IIIF page images (the
// text layer drops grid
// rows and mangles the
// figures); the rule
// prose verified whole
// against the text layer.
namespace rules {

// ---- the clothing
// ---- categories ----

// The census: 4
// categories, the book
// order (very cold, cold,
// moderate, hot).
inline int wsdClothingCount()
    { return 4; }
// The category range,
// low end; -99 = the
// range is open at the
// low end (very cold
// clothing suits
// anything below 0).
inline int wsdCategoryLo(int c)
    {
        switch (c) {
        case 0:
            return -99;
        case 1:
            return 0;
        case 2:
            return 31;
        case 3:
            return 76;
        default:
            return 0;
        }
    }
// The category range,
// high end; 99 = open
// (hot clothing suits
// anything above 75).
inline int wsdCategoryHi(int c)
    {
        switch (c) {
        case 0:
            return -1;
        case 1:
            return 30;
        case 2:
            return 75;
        case 3:
            return 99;
        default:
            return 0;
        }
    }
// The outfit cost, gold
// pieces (the hot
// category prices in
// silver - below).
inline int wsdCategoryCostGp(int c)
    {
        switch (c) {
        case 0:
            return 15;
        case 1:
            return 7;
        case 2:
            return 3;
        case 3:
            return 0;
        default:
            return 0;
        }
    }
// The hot-clothing
// outfit cost ceiling: a
// robe at 6 sp.
inline int wsdHotClothingCostSp()
    { return 6; }

// ---- the category
// ---- encumbrance ----

// Very cold clothing
// encumbers as plate mail
// (bulky).
inline bool wsdVcEncEqPlateMail()
    { return true; }
// The plate mail
// encumbrance weight, in
// gp.
inline int wsdVcEncWeightGp()
    { return 450; }
// Cold clothing encumbers
// as ring mail (fairly
// bulky).
inline bool wsdColdEncEqRingMail()
    { return true; }
inline int wsdColdEncWeightGp()
    { return 250; }
// Moderate clothing has
// no encumbrance value,
// or counts as leather
// armor (non-bulky) if
// heavy.
inline bool wsdModEncEqLeather()
    { return true; }
inline int wsdModEncWeightGp()
    { return 150; }
// Hot clothing has no
// encumbrance value.
inline bool wsdHotEncumbranceNone()
    { return true; }
// Very cold clothing
// equals two layers of
// cold clothing or four
// layers of moderate.
inline int wsdVcEqColdLayers()
    { return 2; }
inline int wsdVcEqModLayers()
    { return 4; }

// ---- the personal ----
// ---- temperature ----

// The temperatures are
// degrees Fahrenheit.
inline bool wsdDegreesAreFahrenheit()
    { return true; }

// ---- Table 3: the 15 ----
// ---- attire rows ----

// The census: 15 attire
// rows (the 4 clothing
// categories + the 11
// armor types).
inline int wsdAttireCount()
    { return 15; }
// The census: 4
// effective-temperature
// columns.
inline int wsdColCount()
    { return 4; }
// Column 0: the -1 or
// lower band (the
// value read per
// attire row).
inline int wsdTempAdjBelow0(int a)
    {
        switch (a) {
        case 0:
            return 30;
        case 1:
            return 20;
        case 2:
            return 10;
        case 3:
            return 0;
        case 4:
            return 10;
        case 5:
            return 10;
        case 6:
            return 10;
        case 7:
            return 5;
        case 8:
            return 5;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 5;
        case 13:
            return 20;
        case 14:
            return 10;
        default:
            return 0;
        }
    }

// Column 1: the 0 to 30
// band.
inline int wsdTempAdjCold(int a)
    {
        switch (a) {
        case 0:
            return 40;
        case 1:
            return 30;
        case 2:
            return 20;
        case 3:
            return 0;
        case 4:
            return 20;
        case 5:
            return 20;
        case 6:
            return 20;
        case 7:
            return 10;
        case 8:
            return 10;
        case 9:
            return 5;
        case 10:
            return 5;
        case 11:
            return 5;
        case 12:
            return 0;
        case 13:
            return 30;
        case 14:
            return 5;
        default:
            return 0;
        }
    }

// Column 2: the 31 to 75
// band.
inline int wsdTempAdjModerate(int a)
    {
        switch (a) {
        case 0:
            return 50;
        case 1:
            return 40;
        case 2:
            return 20;
        case 3:
            return 0;
        case 4:
            return 30;
        case 5:
            return 30;
        case 6:
            return 30;
        case 7:
            return 15;
        case 8:
            return 15;
        case 9:
            return 10;
        case 10:
            return 10;
        case 11:
            return 10;
        case 12:
            return 15;
        case 13:
            return 40;
        case 14:
            return 10;
        default:
            return 0;
        }
    }

// Column 3: the 76 or
// higher band.
inline int wsdTempAdjHot(int a)
    {
        switch (a) {
        case 0:
            return 60;
        case 1:
            return 50;
        case 2:
            return 30;
        case 3:
            return 0;
        case 4:
            return 40;
        case 5:
            return 40;
        case 6:
            return 30;
        case 7:
            return 20;
        case 8:
            return 20;
        case 9:
            return 20;
        case 10:
            return 20;
        case 11:
            return 15;
        case 12:
            return 30;
        case 13:
            return 50;
        case 14:
            return 20;
        default:
            return 0;
        }
    }

// The column for an
// effective temperature:
// -1 or lower, 0 to 30,
// 31 to 75, 76 or higher.
inline int wsdColForTemp(int t)
    { return t < 0 ? 0 : t < 31 ? 1 : t < 76 ? 2 : 3; }
// The Table 3 entry by
// attire and column -
// the dispatch over the
// four column accessors.
inline int wsdTempAdj(int a, int col)
    {
        switch (col) {
        case 0:
            return wsdTempAdjBelow0(a);
        case 1:
            return wsdTempAdjCold(a);
        case 2:
            return wsdTempAdjModerate(a);
        default:
            return wsdTempAdjHot(a);
        }
    }
// Table 3 entries are
// cumulative, no matter
// whether armor is worn
// over clothing or vice
// versa.
inline bool wsdTempAdjCumulative()
    { return true; }

// ---- protected and ----
// ---- unprotected ----

// Very cold clothing
// leaves a character
// unprotected above 30
// degrees effective.
inline int wsdVcUnprotectedAbove()
    { return 30; }
// Cold clothing: below 0
// or above 50.
inline int wsdColdUnprotBelow()
    { return 0; }
inline int wsdColdUnprotAbove()
    { return 50; }
// Moderate clothing:
// below 30 or above 80.
inline int wsdModUnprotBelow()
    { return 30; }
inline int wsdModUnprotAbove()
    { return 80; }
// Hot clothing: below 50.
inline int wsdHotUnprotBelow()
    { return 50; }
// Any metal armor (not
// studded leather) works
// above this effective
// temperature, regardless
// of clothing.
inline int wsdMetalHighTemp()
    { return 80; }
// Studded leather is not
// metal armor for this
// rule.
inline bool wsdStuddedLeatherNotMetal()
    { return true; }
// The clothing rule by
// category.
inline bool wsdClothingUnprotected(
    int c, int t)
    {
        switch (c) {
        case 0:
            return t > wsdVcUnprotectedAbove();
        case 1:
            return t < wsdColdUnprotBelow()
                || t > wsdColdUnprotAbove();
        case 2:
            return t < wsdModUnprotBelow()
                || t > wsdModUnprotAbove();
        case 3:
            return t < wsdHotUnprotBelow();
        default:
            return false;
        }
    }
// The metal armor rule.
inline bool wsdMetalUnprotected(
    bool metal, int t)
    { return metal
        && t > wsdMetalHighTemp(); }
// The combined rule:
// either clause true
// leaves the character
// unprotected.
inline bool wsdUnprotected(
    int c, bool metal, int t)
    { return wsdClothingUnprotected(c, t)
        || wsdMetalUnprotected(metal, t); }

// ---- the exertion ----
// ---- regimes ----

// Effective temperature
// below 0: a protected
// character gains 5
// degrees per 4
// consecutive turns of
// exertion.
inline int wsdExertGainBelow0()
    { return 5; }
inline int wsdExertTurnsBelow0()
    { return 4; }
// One turn of rest holds
// the gain; resting
// longer loses it.
inline int wsdExertRestHoldBelow0()
    { return 1; }
// The 4-on/1-off cycle
// caps the gain at 20.
inline int wsdExertMaxBelow0()
    { return 20; }
// Effective temperature
// 0 to 30: a protected
// character gains 5
// degrees after 6
// consecutive turns, 10
// (the maximum) after 12.
inline int wsdExertGainWarm()
    { return 5; }
inline int wsdExertTurnsWarm()
    { return 6; }
inline int wsdExertMaxWarm()
    { return 10; }
inline int wsdExertTurnsWarmMax()
    { return 12; }
// The gain is retained
// until the character
// rests more than 2 turns
// in a row.
inline int wsdExertRestLoseWarm()
    { return 2; }
// Effective temperature
// 80 or higher: an
// UNPROTECTED character
// gains 5 degrees per 3
// consecutive turns, up
// to a 25-degree maximum.
inline int wsdExertGainHot()
    { return 5; }
inline int wsdExertTurnsHot()
    { return 3; }
inline int wsdExertMaxHot()
    { return 25; }
// Resting drops the gain
// 5 degrees per 3 turns;
// resting AND taking off
// the armor drops 10 per
// 3 turns.
inline int wsdExertRestDropHot()
    { return 5; }
inline int wsdExertRestDropHotRelieved()
    { return 10; }
// The drop is floored at
// the non-exerting
// personal temperature.
inline bool wsdExertDropFloored()
    { return true; }

// ---- clothing that ----
// ---- functions as armor ----

// At the DM discretion,
// very cold clothing may
// impart armor class 8;
// cold clothing, armor
// class 9.
inline int wsdVcArmorClass()
    { return 8; }
inline int wsdColdArmorClass()
    { return 9; }
// The optional somatic
// miscast risk for
// casting in bulky
// clothing: 10 percent.
inline int wsdClothingMiscastChance()
    { return 10; }
inline bool wsdMiscastIsOptional()
    { return true; }

}   // namespace rules
