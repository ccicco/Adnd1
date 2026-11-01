// =========================================================================================
// Adnd1 - rules/mn3.h
// The MM1 normalization batch three - 86 defs rewritten to the full-field
// 57-key emission, the letters l through p
// census 933 -> 934.
//
// The MM1 normalization batch three - the per-book schema pass, MM1 part
// three of six, riding the letters l through p. The standing queue from
// R886/R879, continuing R1009 and R1010: every sparse MM1 def rewritten to
// the full-field 57-key emission of the landed tools/normalize_registry.py -
// string sentinels n/a, integer sentinels -1, saveAsBonus riding the loader
// zero default (the R155 contract) - byte-exact against the normalizer
// output, the canonical FIELD_ORDER honored including text before familyText.
// This batch rewrites 86 defs via 435 anchored insert sites (1723 inserted
// lines), 26 whole-line reorder sites across 25 defs, and no line-move
// encodings this batch. No normalizer repairs ride this round - both landed
// in R1009. The audited keys in this batch - lammasu, leprechaun, purple_worm
// - ride encounter-grid membership and presence checks only, no field
// constraints. The MM1 census after this round: 408 defs, 275 canonical, 133
// remaining for batches four through six (the letters q through z).
//
namespace rules {

// ---- the batch frame ----

// the MM1 normalization batch three - the letters l through p
inline int mn3Round()
    { return 1011; }

// the MM1 defs rewritten to full-field canonical form this batch - the
// letters l through p
inline int mn3DefsNormalized()
    { return 86; }

// the file patches this round - 461 monster windows, no normalizer repairs
// (both landed in R1009), no line-move encodings this batch
inline int mn3PatchEntries()
    { return 461; }

// ---- the MM1 normalization census ----

// the MM1 def census - unchanged by the batch
inline int mn3Mm1Total()
    { return 408; }

// the MM1 defs carrying the full-field emission after this batch - the R1009
// a-f and R1010 g-k letters plus these l-p
inline int mn3Mm1NormalizedAfter()
    { return 275; }

// the MM1 defs still sparse after this batch - batches four through six, the
// letters q through z
inline int mn3Mm1Remaining()
    { return 133; }

// the canonical FIELD_ORDER length - every MM1 def emitted with all 57 keys,
// string sentinel n/a, integer sentinel -1
inline int mn3SchemaKeys()
    { return 57; }

// ---- the patch anatomy ----

// the anchored insert sites - 1723 inserted lines, the n/a and -1 sentinel
// fields plus the reordered text lines
inline int mn3InsSites()
    { return 435; }

// the defs needing whole-line reorders to reach the canonical FIELD_ORDER -
// text before familyText, statNote before text
inline int mn3ReorderDefs()
    { return 25; }

// ---- the guarantees ----

// the landed normalize_registry.py reads its full 1338-def census - the R1009
// REG glob repair proven live
inline bool mn3NormalizerCensusLive()
    { return true; }

// every rewritten def carries all 57 keys - the sparse-era implicit-nil
// fields now explicit with n/a strings, -1 ints and the saveAsBonus zero
// default
inline bool mn3FullFieldEmission()
    { return true; }

// the canonical FIELD_ORDER honored byte-exact - text before familyText,
// statNote before text, saveAs before saveAsBonus
inline bool mn3FieldOrderCanonical()
    { return true; }

// every rewritten file is byte-identical to the landed normalize_registry.py
// output over HEAD - verified by apply simulation before landing
inline bool mn3NormalizerByteExact()
    { return true; }

}   // namespace rules
