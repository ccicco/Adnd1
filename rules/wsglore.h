// =========================================================================================
// Adnd1 - rules/wsglore.h
// R479: the WSG PLANT LORE PROFICIENCY slice, printed p. 70 - the ninth
// camping-arc round, a pure prose round with NO table, the short bridge
// section between the Table 40 availability pin (R478) and the injuries and
// treatment chapter: the party survival benefit, the no-vegetation bar, the
// greater-chance-in-greenery rule and the pointer to the Wilderness
// Proficiencies section.
// census 403 -> 404.
//
// The settle: two-way clean on the first pass - the tesseract full-text read
// and the pdfy layout read agree on every word of the section, and the tsv
// confirms the heading geometry; no contested cells, no vision reads needed.
// The section carries no numbers at all - only qualifications, pinned as
// bools.
//
// This is a qualification-only round: five bools, no consts, no grids - the
// audit proves each qualification pinned exactly once.
//
namespace rules {

// ---- The party survival benefit ----

// a party without ready access to healing and curing magic has increased
// chances of survival if it contains someone with proficiency in plant lore
inline bool plrAidsPartySurvival()
    { return true; }

// the proficiency is also sought to safeguard against losing healing and
// curing aid along the way
inline bool plrSafeguardsLostAid()
    { return true; }

// ---- The location rules ----

// such a character cannot locate vegetation where it does not exist
inline bool plrNoVegetationNoFind()
    { return true; }

// if there is greenery to search through, a proficient character has a
// greater chance of finding the type of plant desired
inline bool plrGreaterChanceInGreenery()
    { return true; }

// the benefits such a character brings to the party are detailed in the
// section on Wilderness Proficiencies
inline bool plrBenefitsInWildernessProficiencies()
    { return true; }

}   // namespace rules
