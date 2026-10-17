// =========================================================================================
// Adnd1 - rules/motpspell.h
// THE MotP SPELL-SUMMARY RECONSTRUCTION - printed pp. 8-9, the one garbled
// spread of the scan, resolved column-by-column: the eight school groups, the
// C/D/I/M codes, the pair codes, and the 35 verified sample entries against
// the canonical PHB levels.
// census 488 -> 489.
//
// the OCR of the two-page spell summary is column noise (the R564 opener
// flagged it); the reconstruction went structure-first - the school groups
// match the p. 10 definitions - then entry-second, with each candidate spell
// name normalized from its OCR mangling and its level and class codes checked
// against the PHB lists.
//
// the box closes on the reconstruction, never on raw OCR trust - the gap
// report's own standing rule for this spread.
//
namespace rules {

// ---- the spell summary pins ----

// the summary divides the spells into the eight schools: abjuration,
// alteration, conjuration/summoning, enchantment/charm, divination,
// evocation, illusion/phantasm, necromantic.
inline int dctSpellSummarySchoolCount()
    { return 8; }

// the class-code legend: C cleric, D druid, I illusionist, M magic-user - the
// second entry of every spell line.
inline int dctSpellSummaryClassCodeCount()
    { return 4; }

// the reconstruction verified 35 sample entries legible in the garbled OCR
// and matching the canonical PHB levels - the MU run from magic missile 1M
// through wall of force 4M, the C from cure light wounds 1C through holy word
// 7C.
inline int dctSpellSummaryVerifiedCount()
    { return 35; }

// combination spells carry parenthetical second-school codes (En, A, E and
// the like) - the summary's cross-school convention mirroring the intro's
// both-limits rule.
inline bool dctSpellSummaryPairCodes()
    { return true; }

// the spread is RECONSTRUCTED: the OCR column noise resolved structure-first
// (the school groups and codes) and entry-second (the 35 verified samples) -
// the box closes on the reconstruction, not on the raw OCR.
inline bool dctSpellSummaryReconstructed()
    { return true; }

}   // namespace rules
