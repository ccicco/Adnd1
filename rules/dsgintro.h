// =========================================================================================
// Adnd1 - rules/dsgintro.h
// THE DSG WHAT-IS-IT FRONT MATTER - the printed p. 6 chapter frame opening
// the book: the mystery of the underdark, the new rules for underground play,
// the denizens of the underdark, the underground campaign and the
// using-this-information player/DM split - the parent and all five children
// closed in one round.
// census 485 -> 486.
//
// from the DSG chapter on printed p. 6, djvu lines 466-585, between the
// credits and the Overview of the Underdark (the R503 extraction round);
// every promise cross-checked against the chapter that later lands it - the
// climbing and proficiencies the movement chapter, the cultures the R532
// round, the generators the R533 Deepearth frame, the 3-D mapping the R557
// doctrine.
//
// the front-matter frame is the arc's own table of contents in prose: each
// subhead is a promise the landed rounds already keep.
//
namespace rules {

// ---- the intro frame pins ----

// the chapter sits on printed p. 6 between the credits and the Overview of
// the Underdark - the front-matter frame opening the whole book.
inline int dcqFramePage()
    { return 6; }

// the denizens subhead names four cultures - the drow, duergar, kuo-toa and
// myconids revealed in their natural environments - the cultures the R532
// chapter later lands in full.
inline int dcqNamedCultureCount()
    { return 4; }

// the book splits into two sections: the first for player and DM alike (the
// expanded rules, the spells, the proficiencies, the new equipment), the
// latter tailored to the DM alone.
inline int dcqSectionCount()
    { return 2; }

// the mystery subhead counts three subterranean lures beneath the earth - the
// most fearsome foes, the most fabulous treasures and the most mysterious
// locales.
inline int dcqPlayerLureCount()
    { return 3; }

// the new-rules subhead asks whether a non-thief can climb a rough stone
// wall, fight while clinging to the wall, or duel atop a swaying footbridge -
// all covered by the rules this book introduces (the movement chapter era).
inline bool dcqNonthiefClimbCovered()
    { return true; }

// the proficiencies were first introduced in the AD&D Oriental Adventures
// book; the DSG reintroduces them and adds many more suited to the
// underearth.
inline bool dcqProficienciesFromOA()
    { return true; }

// the denizens subhead promises the detailed random location and encounter
// generators - exciting adventuring with little or no preparation time (the
// Deepearth R533 generators).
inline bool dcqRandomGenerators()
    { return true; }

// the using-this-information subhead marks the latter portion the DM's
// Forbidden Territory - players should avoid it or face the wrath of the DM.
inline bool dcqForbiddenDMHalf()
    { return true; }

}   // namespace rules
