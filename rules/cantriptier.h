// ===========================================================================
// Adnd1 - rules/cantriptier.h
// The UA cantrip TIER SEAM (p. 45), R401: the
// sub-1st registry tier - a category of its own
// by standing decision (the R322 deferred-seams
// graph; the gateway charge for the cantrip
// prose rounds).
//
// The clean p. 45 print (the archive.org djvu
// scan): cantrips are the spells learned and
// used by apprentice magic-users and
// illusionists; the 0-level per-day ladder runs
// by xp band; at 1st level the knowledge is
// discarded unless up to four cantrips are
// retained in place of one 1st-level spell;
// cantrips are memorized like spells, read as
// spells and recorded in books and scrolls by
// the spell procedure (the R369/R366 seams).
//
// The cross-checked pins: the R369 acquisition
// bands (rules/uacantacq.h), the R365/R393
// illusionist counts (rules/uailacquisition.h,
// rules/uaspelltables.h), the R341 roster
// (rules/uaspelltables.h, amended R401 - the
// clean p. 30 table prints Tangle in the
// reversed column and Tweak in the personal
// column, both row 9; the roster reads 66
// names, not 64) and the R363 minor-illusion
// descriptions (rules/uailcantrips.h).
// ===========================================================================

#pragma once

namespace rules {

// ---- the tier traits ----
// All cantrips are 0 level, carry a 1-inch
// range, a generally small area of effect,
// soft simple verbal and somatic components,
// and cast in 1/10 to 1/2 segment (pinned as
// tenths: 1 to 5).
inline int cantSpellLevel()
    { return 0; }

inline int cantRangeInches()
    { return 1; }

inline int cantCastTimeMinTenths()
    { return 1; }

inline int cantCastTimeMaxTenths()
    { return 5; }

inline bool cantSmallAoe()
    { return true; }

inline bool cantSoftSimpleComponents()
    { return true; }

// Only the cantrips which involve living
// creatures afford any saving throw.
inline bool cantLivingCreatureCantripsAllowSave()
    { return true; }

// Individuals in a state of extreme
// concentration (such as when casting a
// spell) do not have that concentration
// broken by person-affecting cantrips.
inline bool cantConcentrationBlocksPersonAffecting()
    { return true; }

// The effects of cantrips, and the people
// and items affected by them, radiate a very
// faint magical aura.
inline bool cantFaintMagicAura()
    { return true; }

// Cantrips must be memorized just as
// higher-level spells are.
inline bool cantMemorizedLikeSpells()
    { return true; }

// ---- the 0-level per-day ladder ----
// A 0-level neophyte (-2000 to -1001 xp)
// casts 1 per day; a 0-level initiate
// (-1000 to -501) casts 2; a 0-level
// apprentice (-500 to -1) casts 3. A leveled
// character reads 0 here - the retention
// rule carries the tier at 1st level.
inline int cantNeophyteXpLo()
    { return -2000; }

inline int cantNeophyteXpHi()
    { return -1001; }

inline int cantNeophytePerDay()
    { return 1; }

inline int cantInitiateXpLo()
    { return -1000; }

inline int cantInitiateXpHi()
    { return -501; }

inline int cantInitiatePerDay()
    { return 2; }

inline int cantApprenticeXpLo()
    { return -500; }

inline int cantApprenticeXpHi()
    { return -1; }

inline int cantApprenticePerDay()
    { return 3; }

inline int cantPerDayByXp(int xp) {
    if (xp <= -1001) return 1;
    if (xp <= -501) return 2;
    if (xp <= -1) return 3;
    return 0;
}

// ---- the first-level discard and retention ----
// At 1st level the cantrip knowledge is
// discarded in favor of the more powerful
// spells - unless the character retains up
// to four cantrips in place of one
// 1st-level spell (book in hand).
inline bool cantKnowledgeDiscardedAtFirst()
    { return true; }

inline int cantRetainedMaxInPlaceOfFirst()
    { return 4; }

// ---- the round rules ----
// Only two cantrips can be cast during any
// round; after the first, a d4 tells how many
// segments later the second may be cast; a
// spell and a cantrip never share a round.
inline int cantPerRoundMax()
    { return 2; }

inline int cantSecondCastGapDieSides()
    { return 4; }

inline bool cantNoSpellAndCantripSameRound()
    { return true; }

// ---- the categories ----
// Six MU categories (useful, reversed,
// legerdemain, person-affecting, personal,
// haunting-sound) plus the seventh, minor
// illusion, available only to illusionists;
// any magic-user or illusionist has the
// potential to know cantrips in all of them.
inline int cantCategoryCount()
    { return 7; }

inline int cantMuCategoryCount()
    { return 6; }

inline bool cantAnyCasterMayKnowAllCategories()
    { return true; }

// ---- the roster totals ----
// The R401-amended R341 decode: 66 MU names
// (the clean p. 30 table prints Tangle,
// reversed row 9, and Tweak, personal row 9),
// the eight minor-illusion cantrips (the
// R363 amended list), 74 in all.
inline int cantMuRosterTotal()
    { return 66; }

inline int cantIlRosterTotal()
    { return 8; }

inline int cantRosterTotal()
    { return 74; }

}   // namespace rules

