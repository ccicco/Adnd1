// ===========================================================================
// Adnd1 - rules/uaspellbooks.h
// The UA MAGIC-USER SPELL BOOKS (pp. 79-80 print) pins,
// R366: the book types and capacities, the costs, the
// physical aspects, the values and the direct-casting
// and learning rules.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists. The section general note applies equally
// to illusionists; the illusionist-side exceptions pin
// in the R365 acquisition header.
//
// JUDGMENTs (the decode method):
//   - the section opening garbles (the one-or-two
//     starting books read survives in the cost
//     paragraph); the readable facts pin, the rest is
//     a hole pending the PDF.
//   - the standard-book encumbrance cell and the
//     travelling-book thickness/weight/encumbrance
//     cells garble - holes, no numeric pin, pending
//     the PDF; the travelling 500 gp cost prints as a
//     fragment ("costs such a 500 gold") and pins
//     flagged.
//   - the direct-casting neighbor-destroy chance
//     prints 1 percent per level of the spell; the
//     whole-book chance prints a flat 1 percent.
// ===========================================================================

#pragma once

namespace rules {

// ---- the standard book capacities ----
inline int uabkStandardCantripsCapacity()
    { return 36; }

inline int uabkStandardLowLevelSpells()
    { return 24; }

inline int uabkStandardMidLevelSpells()
    { return 16; }

inline int uabkStandardHighLevelSpells()
    { return 8; }

// ---- the travelling book (one-fourth) ----
inline bool uabkTravellingIsOneFourth()
    { return true; }

inline int uabkTravellingCantripsCapacity()
    { return 9; }

inline int uabkTravellingLowLevelSpells()
    { return 6; }

inline int uabkTravellingMidLevelSpells()
    { return 4; }

inline int uabkTravellingHighLevelSpells()
    { return 2; }

// ---- the costs ----
// A standard spell book costs 1,000 gp for materials
// plus 100 gp per spell level for each spell contained
// therein; cantrips count as 1st-level spells.
inline int uabkStandardMaterialsCostGp()
    { return 1000; }

inline int uabkPerSpellLevelCostGp()
    { return 100; }

inline bool uabkCantripsCountAsFirstLevel()
    { return true; }

// The new caster's former master bears the cost of
// the initial book or books (one or two, at no cost).
inline bool uabkInitialBooksBorneByMaster()
    { return true; }

inline int uabkInitialBookCountMax()
    { return 2; }

// Later books are composed during the training to rise
// to a higher experience level: 4-7 weeks per new
// standard book.
inline bool uabkLaterBooksSelfComposed()
    { return true; }

inline int uabkCompositionWeeksMin()
    { return 4; }

inline int uabkCompositionWeeksMax()
    { return 7; }

inline bool uabkCompositionRidesLevelTraining()
    { return true; }

// The printed examples: entering a 1st-level spell
// costs 100 gp, a 2nd-level spell 200 gp.
inline int uabkEnterFirstLevelCostGp()
    { return 100; }

inline int uabkEnterSecondLevelCostGp()
    { return 200; }

// The travelling-book cost fragment (the cell garbles
// around a readable "such a 500 gold").
inline int uabkTravellingCostFragmentGp()
    { return 500; }

inline bool uabkTravellingCostIsFragmentRead()
    { return true; }

// ---- the standard book physical aspects ----
inline int uabkStandardHeightInches()
    { return 16; }

inline int uabkStandardWidthInches()
    { return 12; }

inline int uabkStandardThicknessInches()
    { return 6; }

// The DM has leeway to reduce or enlarge this general
// size (nothing smaller than 12x12x6 or larger than
// 18x12x9 is recommended).
inline bool uabkDmMayResizeTheBook()
    { return true; }

inline int uabkMinSizeHeightInches()
    { return 12; }

inline int uabkMinSizeWidthInches()
    { return 12; }

inline int uabkMinSizeThicknessInches()
    { return 6; }

inline int uabkMaxSizeHeightInches()
    { return 18; }

inline int uabkMaxSizeWidthInches()
    { return 12; }

inline int uabkMaxSizeThicknessInches()
    { return 9; }

// The weight of a standard book of median size is 150
// gold pieces (adjusted for varying sizes); the
// encumbrance cell garbles - a hole.
inline int uabkMedianWeightGp()
    { return 150; }

inline bool uabkWeightAdjustedForSize()
    { return true; }

inline bool uabkEncumbranceCellLost()
    { return true; }

inline bool uabkFitsBackpackOrLargeSack()
    { return true; }

// The cover is heavy leather (dragon hide or similar)
// inlaid with metal for durability and closing; vellum
// pages are sewn and secured to a leather spine backing
// with vellum stubs for added pages.
inline bool uabkCoverHeavyLeatherInlaidMetal()
    { return true; }

inline bool uabkVellumPagesSewnToSpine()
    { return true; }

inline bool uabkVellumStubsForAddedPages()
    { return true; }

inline bool uabkStubsDoNotChangeCapacity()
    { return true; }

// A standard spell book has a saving throw equal to
// that of leather or book, with +2 to dice rolls made
// to save against acid, fireball, disintegration and
// lightning attacks.
inline bool uabkSaveAsLeatherOrBook()
    { return true; }

inline int uabkSaveBonusVsAcidFireDisintLightning()
    { return 2; }

// ---- the travelling book physical aspects ----
inline int uabkTravellingTallInches()
    { return 12; }

inline int uabkTravellingWideInches()
    { return 6; }

inline bool uabkTravellingThickCellLost()
    { return true; }

inline bool uabkTravellingWeightCellLost()
    { return true; }

inline bool uabkTravellingEncumbranceCellLost()
    { return true; }

inline int uabkTravellingFitPerLargeSack()
    { return 5; }

// The cover is strong supple leather (giant cobra and
// similar); hand-sewn parchment leaves glued to the
// spine; pages very thin and fragile; a small lock or
// leather ties secure the whole.
inline bool uabkTravellingCoverGiantCobraLeather()
    { return true; }

inline bool uabkTravellingPagesThinFragile()
    { return true; }

inline bool uabkTravellingLockOrLeatherTies()
    { return true; }

// A travelling spell book saves as leather or book
// with no bonuses against certain forms of attack.
inline bool uabkTravellingSaveNoBonus()
    { return true; }

// ---- the values ----
// A standard spell book has an Experience Point Value
// of 500 points per spell level contained therein
// (cantrips as 1st-level spells) and a Gold Piece Sale
// Value of 1,000 gp per spell level (all spells,
// including cantrips).
inline int uabkXpValuePerSpellLevel()
    { return 500; }

inline int uabkSaleValuePerSpellLevelGp()
    { return 1000; }

// Spell books must be sold immediately or else the
// x.p. value taken - a book cannot be kept while
// spells are transcribed and then sold.
inline bool uabkSellImmediatelyOrTakeXp()
    { return true; }

inline bool uabkNoKeepTranscribeThenSell()
    { return true; }

// ---- casting directly from books ----
// In extremis the DM may allow a spell to be cast
// directly from a spell book just as if the book were
// a scroll; the book must match the profession of the
// caster and the caster must be able to know and use
// the spell (reading directly differs from scroll
// use in this regard).
inline bool uabkInExtremisDmMayAllowDirectCast()
    { return true; }

inline bool uabkBookMustMatchCasterProfession()
    { return true; }

inline bool uabkCasterMustKnowAndUseSpell()
    { return true; }

inline bool uabkDirectCastDiffersFromScrolls()
    { return true; }

// Direct casting automatically destroys that spell;
// a 1 percent per level chance destroys the
// immediately preceding and following spells; a flat
// 1 percent chance destroys the entire book.
inline bool uabkDirectCastDestroysTheSpell()
    { return true; }

inline int uabkNeighborDestroyPctPerLevel()
    { return 1; }

inline int uabkWholeBookDestroyPct()
    { return 1; }

// A permanency spell would not prevent the loss (the
// writing might remain on the page but is no longer
// magical); the strictures apply to any book, personal
// or another's.
inline bool uabkPermanencyDoesNotPreventLoss()
    { return true; }

inline bool uabkWritingRemainsButNotMagical()
    { return true; }

inline bool uabkStricturesApplyToAnyBook()
    { return true; }

// ---- learning from another's book ----
inline bool uabkReadMagicNeededForOthersBook()
    { return true; }

inline bool uabkLearnSpellFromAnotherBook()
    { return true; }

inline int uabkStudyHoursPerLevelMin()
    { return 2; }

inline int uabkStudyHoursPerLevelMax()
    { return 8; }

inline bool uabkLearnedSpellImmediatelyUsable()
    { return true; }

}   // namespace rules

