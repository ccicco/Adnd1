// =========================================================================================
// Adnd1 - rules/motpintro.h
// THE MotP ARC OPENER - the introduction, printed pp. 5-10: the five
// groupings of the planes, the organization pattern, the true-vs-subjective
// time doctrine with its per-plane ratios, and the spell school definitions -
// the arc the DSG arc handed off to opens here, on the R503 extraction-round
// pattern.
// census 487 -> 488.
//
// from the Manual of the Plans (1987, Jeff Grubb), printed pp. 3-10, the
// uploaded motp.pdf OCR (60 clean pages of prose; the pp. 8-9 spell-summary
// tables are the one garbled spread, flagged in the gap report); the offset
// pinned at printed + 1.
//
// the opener mirrors the book's own skeleton: the gap report
// tools/motp_gap_report.md lands with this round and every box in it closes
// on the MotP's own text - nothing auto-credited across the seams.
//
namespace rules {

// ---- the intro opener pins ----

// the five groupings of the planes: the Prime Material, the Ethereal, the
// inner (elemental), the Astral, and the outer (the planes of power).
inline int dcsPlaneGroupCount()
    { return 5; }

// the Deep Ethereal: 10 true rounds pass for every one subjective round - a
// 10-round Prime potion lasts 100 rounds; 10 days without food fasts for one
// day.
inline int dcsEtherealTimeRatio()
    { return 10; }

// the inner planes: one true round passes for every two subjective rounds -
// subjective effects last half as long; poison takes effect twice as quickly.
inline int dcsInnerTimeDivisor()
    { return 2; }

// the Astral: 365,000 true rounds (about 170 true days) pass per subjective
// round - a thousand true years equal one subjective day.
inline int dcsAstralTrueRounds()
    { return 365000; }

// time is a constant in the known planes: it cannot be expanded, contracted,
// created, or destroyed - 20 rounds in the Ethereal are 20 rounds on the
// Prime.
inline bool dcsTrueTimeConstant()
    { return true; }

// natives of a plane are unaffected by its subjective effects: an
// Ethereal-native caster regains spells in a standard day, a visiting Prime
// mage in ten times that.
inline bool dcsNativesUnaffected()
    { return true; }

// spell casting on the Astral is exempt from the time differential: a sleep
// SPELL keeps its five-rounds-per-level duration, while a sleep POTION would
// last 170 true days.
inline bool dcsAstralSpellsExempt()
    { return true; }

// spells combining types (alteration-evocations and the like) are constrained
// by the limitations on BOTH types - the intro's combined-spell rule.
inline bool dcsCombinedSpellsBothLimited()
    { return true; }

}   // namespace rules
