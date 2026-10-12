// ===========================================================================
// Adnd1 - rules/uacantacq.h
// The UA ACQUISITION OF CANTRIPS,
// MAGIC-USERS (p. 79) pins, R369: the
// known-count rules - the useful category
// one known per point of intelligence by
// free choice, the five random categories
// (reversed 2-8, legerdemain 2-5,
// person-affecting 2-8, personal 2-8,
// haunting-sound 2-5), the three developed
// cantrips cap with the DM review, and the
// read-as-spell / recorded-as-spell notes.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists. Cross-checks the landed R365 seam
// (rules/uailacquisition.h - the illusionist bands
// deliberately differ, the documented divergence)
// and the R366 spell-book seam (cantrips count as
// 1st-level spells).
//
// JUDGMENTs (the decode method):
//   - the useful-per-intelligence sentence garbles
//     in the extract; the read - one known per point
//     of intelligence, free choice - is decoded from
//     the surviving fragments and matches the gap
//     report standing reading; flagged pending the
//     PDF.
//   - the five random bands and the developed-cap
//     sentence print clean.
//   - the 0-level per-day tier (p. 45) rides its own
//     item (the cantrips category); no pin here.

namespace rules {

// ---- the useful category ----
// One known per point of intelligence, free
// choice - the decode flagged above.
inline int uacaqUsefulPerIntelligencePoint()
    { return 1; }

inline bool uacaqUsefulFreeChoice()
    { return true; }

inline bool uacaqUsefulReadDecoded()
    { return true; }

// ---- the category count ----
// Six MU categories; the illusionist seventh
// (minor illusion) is R365 territory.
inline int uacaqCategoryCount()
    { return 6; }

// ---- the five random categories ----
inline int uacaqReversedKnownMin()
    { return 2; }

inline int uacaqReversedKnownMax()
    { return 8; }

inline int uacaqLegerdemainKnownMin()
    { return 2; }

inline int uacaqLegerdemainKnownMax()
    { return 5; }

inline int uacaqPersonAffectingKnownMin()
    { return 2; }

inline int uacaqPersonAffectingKnownMax()
    { return 8; }

inline int uacaqPersonalKnownMin()
    { return 2; }

inline int uacaqPersonalKnownMax()
    { return 8; }

inline int uacaqHauntingSoundKnownMin()
    { return 2; }

inline int uacaqHauntingSoundKnownMax()
    { return 5; }

// ---- the developed-cantrips cap ----
inline int uacaqMaxDevelopedCantrips()
    { return 3; }

inline bool uacaqDevelopedRequiresDmReview()
    { return true; }

// ---- the spell-procedure notes ----
// Cantrips are read as spells and recorded
// in books or scrolls by the spell procedure.
inline bool uacaqReadAsSpell()
    { return true; }

inline bool uacaqRecordedAsSpell()
    { return true; }

}   // namespace rules

