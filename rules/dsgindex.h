// =========================================================================================
// Adnd1 - rules/dsgindex.h
// THE DSG INDEX - the printed pp. 127-128 roster closing the book: the
// alphabetical topic list whose every page reference lands on a chapter this
// arc already pinned, from Ability Check (p. 12) through World design (p.
// 100), with the see-cross-references and the four underdark theories.
// census 483 -> 484.
//
// from the DSG index, printed pp. 127-128, djvu lines 15866-16247, every
// entry cross-checked against the landed rounds page ranges; the roster
// references no page outside the pp. 6-128 book.
//
// the roster is the arc own mirror: the DSG gap report and the index close
// together, the back-cover blurb the only prose past it.
//
namespace rules {

// ---- the index roster pins ----

// the index opens at Ability Check, printed p. 12 - the R504 movement chapter
// era; the roster runs A (Ability Check) through W (World design, p. 100)
// across the printed pp. 127-128 spread.
inline int dcmIndexFirstPage()
    { return 12; }

// the Mapping entry refs p. 114 with its geomorphic (117), orthographic and
// perspective subheads - the R557 mapping chapter and the R559 plates it
// served.
inline int dcmMappingPage()
    { return 114; }

// the story elements moral subhead refs p. 109 - the R553 tail closing the
// elements, with the story types and the storytelling techniques (pace,
// voice) subheads at pp. 109/112.
inline int dcmMoralPage()
    { return 109; }

// four underdark theories indexed at p. 71: Hollow Earth, Isolated Pockets,
// Partial Connections and Swiss Cheese - the R-era underground environment
// chapter.
inline int dcmTheoryCount()
    { return 4; }

// the index uses see-cross-references: Illithids see Mind flayers, Smell see
// Odor detection - the roster routes the reader instead of double-listing.
inline bool dcmSeeCrossRefs()
    { return true; }

// Types of players and the Role-Players / Problem-Solvers subheads are
// indexed at p. 99 - the R550 campaign opener.
inline bool dcmPlayerTypesIndexed()
    { return true; }

// the Equipment entry refs the pp. 56-58 range with its proficiency-equipment
// subhead at p. 58 - the landed new-equipment chapter.
inline bool dcmEquipmentRangeIndexed()
    { return true; }

// the back-cover blurb (the Niles quote and the TSR addresses) follows the
// index - the book ends at printed p. 128, the arc's final census boundary.
inline bool dcmBackCoverPastIndex()
    { return true; }

}   // namespace rules
