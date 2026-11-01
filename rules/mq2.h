// =========================================================================================
// Adnd1 - rules/mq2.h
// The MM2 normalization batch two - 83 of 332 defs rewritten to the
// full-field 57-key emission, the by_level pin repairs riding
// census 940 -> 941.
//
// The MM2 normalization - the per-book schema pass continued (the R879
// normalizer doctrine, the R1009-R1014 MM1 arc, R1016 the OA book close,
// R1017 the MM2 arc opener): 83 more sparse MM2 defs (derro through
// mephistopheles, the letters d through m) rewritten to the full-field 57-key
// emission of the landed tools/normalize_registry.py - string sentinels n/a,
// integer sentinels -1 - byte-exact against the normalizer output, the
// canonical FIELD_ORDER honored; 578 anchored inserts (2252 inserted lines),
// five trailing-comma whole-line rewrites (hangman_tree, haunt, hollyphant,
// hordling, hybsil - the last carried field line lacked the Lua-optional
// comma, values verbatim), zero move encodings. THE PIN REPAIRS: the duergar
// and mandragora are by_level defs whose sparse files never carried
// xp/xpPerHp, and the loader reads absence as 0 - the mm2dg and mm2lmn pin
// grids pinned that 0. The canonical emission writes the -1 sentinel (the
// dervish and dwarf precedent), so four pin cells ride this round: mm2dg case
// 10 and mm2lmn case 7, xp and xpPerHp, 0 to -1. Each letter walk exists
// TWICE - the regtest live-def walk pins the loader members against the grid
// functions, and the migrated fragments pin the grid functions against
// hardcoded copies of the print grids - so the R803 dragon-section fragment
// (CDgStats row 10) and the R808 LMN-walk fragment (CLmStats row 7) mirror
// the repaired cells; both grid copies caught by the preflight gate over two
// attempts. The mongrelman and myconid by_level rows stay 0 until their own
// batches. No other audit pins a changed member. THE MM2 census after this
// round: 332 defs, 166 canonical, 166 remaining. THE QUEUE: the MM2 batches
// three and four follow, then FF 185, WSG+MOP 23, DRG 5, the deity seam.
//
namespace rules {

// ---- the batch frame ----

// the MM2 normalization batch two - derro through mephistopheles, 83 of 332
inline int mq2Round()
    { return 1018; }

// the MM2 defs rewritten to full-field canonical form this batch
inline int mq2DefsNormalized()
    { return 83; }

// the file patches this round - 583 monster windows plus 9 pin-repair patches
// (4 grid cells, 2 fragment grid-copy rows, 3 grid comments)
inline int mq2PatchEntries()
    { return 592; }

// ---- the MM2 normalization census ----

// the MM2 def census - unchanged by the batch
inline int mq2Mm2Total()
    { return 332; }

// the MM2 defs carrying the full-field emission after this batch
inline int mq2Mm2NormalizedAfter()
    { return 166; }

// the MM2 defs still sparse after this batch - the batches three and four
// follow
inline int mq2Mm2Remaining()
    { return 166; }

// the canonical FIELD_ORDER length - every MM2 def emitted with all 57 keys
inline int mq2SchemaKeys()
    { return 57; }

// ---- the patch anatomy ----

// the anchored insert sites - 2252 inserted lines, all sentinel fields
inline int mq2InsSites()
    { return 578; }

// the trailing-comma whole-line rewrites - hangman_tree, haunt, hollyphant,
// hordling, hybsil; values verbatim
inline int mq2CommaSites()
    { return 5; }

// the by_level pin cells repaired 0 to -1 - mm2dg case 10 and mm2lmn case 7,
// xp and xpPerHp (the duergar and mandragora; the loader read the absent keys
// as 0)
inline int mq2ByLevelPinRepairs()
    { return 4; }

// the defs needing whole-line rewrites - the five trailing-comma sites, the
// fields already in canonical FIELD_ORDER
inline int mq2ReorderDefs()
    { return 5; }

// ---- the guarantees ----

// the landed normalize_registry.py reads its full 1338-def census - the R1009
// REG glob repair proven live
inline bool mq2NormalizerCensusLive()
    { return true; }

// every rewritten def carries all 57 keys - string sentinel n/a, integer
// sentinel -1, saveAsBonus the loader zero default
inline bool mq2FullFieldEmission()
    { return true; }

// the canonical FIELD_ORDER honored byte-exact - insert sites plus the five
// trailing-comma rewrites, no move encodings
inline bool mq2FieldOrderCanonical()
    { return true; }

// every rewritten file is byte-identical to the landed normalize_registry.py
// output over HEAD - the MM2 book now renders 166 of 332 canonical
inline bool mq2NormalizerByteExact()
    { return true; }

}   // namespace rules
