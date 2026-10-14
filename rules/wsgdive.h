// =========================================================================================
// Adnd1 - rules/wsgdive.h
// The WSG DIVING AND SURFACING, R452: the basic movement rate for a character
// attempting to swim downward through the water is 2 inches, or 20 feet per
// round - and this figure is DOUBLED for moderately encumbered characters and
// TRIPLED for heavily or severely encumbered characters (the same 1/1/2/3/3
// dive column the swimming round pinned in Table 24). In addition, the depth
// attainable on the FIRST round of a dive can be increased if the character
// leaps into the water from a point above the surface: a leap of at least 5
// feet adds 1 inch of depth, at least 15 feet adds 2, at least 25 feet adds
// 3, at least 35 feet adds 4, and at least 40 feet adds 5. Footnote: leaping
// from MORE than 40 feet above the surface does not increase the extra depth
// beyond 5 inches regardless of the height involved; and a dive from 40 feet
// or any greater height may suffer falling damage as described in the text
// about being carried over a waterfall. Census 376 -> 377.
// census 376 -> 377.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 42; the
// user own copy OCR (page 43) cross-checked against the archive djvu word
// layer (Guide_0042) and TWO independent IIIF eye-reads of the leaf - the
// prose matched three-way, and the djvu garbles the printed table (the
// 35-feet row reads "36 feet", the 40-feet row is mangled), so the ladder was
// settled by the two eye-reads, which agree with the OCR exactly:
// 5/15/25/35/40 feet -> 1/2/3/4/5 inches.
//
// Swim down at 2 inches a round - 20 feet - doubled for the moderately loaded
// and tripled for the heavily or severely loaded. Leap high to dive deep: 5
// feet adds an inch, 15 adds two, 25 adds three, 35 adds four, 40 adds five -
// and no leap past 40 feet buys a sixth inch, while a dive from 40 feet or
// more may yet cost falling damage.
//
namespace rules {

// ---- the downward swim rate ----

// The basic movement rate for a character attempting to swim downward through
// the water is 2 inches, or 20 feet per round.
inline int wdvBaseDownRateIn()
    { return 2; }

// The downward swim rate in feet: 2 inches is 20 feet per round.
inline int wdvBaseDownRateFt()
    { return 20; }

// The basic downward figure is doubled for moderately encumbered characters.
inline bool wdvModEncDoubled()
    { return true; }

// The downward rate is doubled for moderately encumbered characters.
inline int wdvModEncMult()
    { return 2; }

// The basic downward figure is tripled for heavily or severely encumbered
// characters.
inline bool wdvHeavyEncTripled()
    { return true; }

// The downward rate is tripled for heavily or severely encumbered characters.
inline int wdvHeavyEncMult()
    { return 3; }

// ---- the leap-height extra-depth ladder ----

// The depth attainable on the first round of a dive can be increased if the
// character leaps into the water from a point above the surface of the water.
inline bool wdvLeapBoostsFirstRound()
    { return true; }

// The leap-height extra-depth ladder has five rows: 5, 15, 25, 35 and 40 feet
// of leap height.
inline int wdvLeapRowCount()
    { return 5; }

// The leap height in feet, the "at least" threshold: 5, 15, 25, 35, 40.
inline int wdvLeapFt(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 15;
        case 2:
            return 25;
        case 3:
            return 35;
        case 4:
            return 40;
        default:
            return 0;
        }
    }

// The extra depth in inches attainable on the first round of the dive: 1, 2,
// 3, 4, 5.
inline int wdvExtraIn(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        default:
            return 0;
        }
    }

// If a character leaps into the water from more than 40 feet above the
// surface, the extra depth attainable on the first round of the dive does not
// increase beyond 5 inches regardless of the height involved.
inline int wdvLeapCapIn()
    { return 5; }

// The footnote: leaping from more than 40 feet above the surface never
// increases the first-round extra depth beyond 5 inches, regardless of the
// height involved.
inline bool wdvLeapCappedBeyondForty()
    { return true; }

// A character making a dive from 40 feet or any greater height may suffer
// falling damage as described in the text about being carried over a
// waterfall.
inline int wdvHighDiveMinFt()
    { return 40; }

// A dive from 40 feet or any greater height may suffer falling damage as
// described in the waterfall text.
inline bool wdvHighDiveFallingDamage()
    { return true; }

}   // namespace rules
