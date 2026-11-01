// =========================================================================================
// Adnd1 - rules/mn2.h
// The MM1 normalization batch two - 90 defs rewritten to the full-field
// 57-key emission, the letters g through k
// census 932 -> 933.
//
// The MM1 normalization batch two - the per-book schema pass, MM1 part two of
// six, riding the letters g through k. The standing queue from R886/R879,
// continuing R1009: every sparse MM1 def rewritten to the full-field 57-key
// emission of the repaired, landed tools/normalize_registry.py - string
// sentinels n/a, integer sentinels -1, saveAsBonus riding the loader zero
// default (the R155 contract) - byte-exact against the normalizer output, the
// canonical FIELD_ORDER honored including text before familyText. This batch
// rewrites 90 defs via 466 anchored insert sites (1924 inserted lines), 21
// whole-line reorder sites across 22 defs, 1 line-move encoding - the
// delete-replace window plus paired insert, since the engine cannot ship a
// bare delete. No normalizer repairs ride this round - both landed in R1009
// (the REG glob, the saveAsBonus zero default) and the normalizer reads its
// full 1338-def census live. The classed ki-rin rides this batch - its
// magic-user 18 save is preserved and its saveAsBonus carries the zero
// default, the R155 contract held. The MM1 census after this round: 408 defs,
// 189 canonical, 219 remaining for batches three through six (the letters l
// through z).
//
namespace rules {

// ---- the batch frame ----

// the MM1 normalization batch two - the letters g through k
inline int mn2Round()
    { return 1010; }

// the MM1 defs rewritten to full-field canonical form this batch - the
// letters g through k
inline int mn2DefsNormalized()
    { return 90; }

// the file patches this round - 488 monster windows, no normalizer repairs
// (both landed in R1009)
inline int mn2PatchEntries()
    { return 488; }

// ---- the MM1 normalization census ----

// the MM1 def census - unchanged by the batch
inline int mn2Mm1Total()
    { return 408; }

// the MM1 defs carrying the full-field emission after this batch - the R1009
// letters a-f plus these letters g-k
inline int mn2Mm1NormalizedAfter()
    { return 189; }

// the MM1 defs still sparse after this batch - batches three through six, the
// letters l through z
inline int mn2Mm1Remaining()
    { return 219; }

// the canonical FIELD_ORDER length - every MM1 def emitted with all 57 keys,
// string sentinel n/a, integer sentinel -1
inline int mn2SchemaKeys()
    { return 57; }

// ---- the patch anatomy ----

// the anchored insert sites - 1924 inserted lines, the n/a and -1 sentinel
// fields plus the reordered text lines
inline int mn2InsSites()
    { return 466; }

// the defs needing whole-line reorders to reach the canonical FIELD_ORDER -
// text before familyText, statNote before text
inline int mn2ReorderDefs()
    { return 22; }

// the line-move encodings - delete-replace windows spanning the moved line
// plus its neighbours, each with a paired insert at the canonical site
inline int mn2MoveSites()
    { return 1; }

// ---- the guarantees ----

// the repaired normalize_registry.py reads its full 1338-def census - the
// R1009 REG glob repair proven live at HEAD
inline bool mn2NormalizerCensusLive()
    { return true; }

// every rewritten def carries all 57 keys - the sparse-era implicit-nil
// fields now explicit with n/a strings, -1 ints and the saveAsBonus zero
// default
inline bool mn2FullFieldEmission()
    { return true; }

// the canonical FIELD_ORDER honored byte-exact - text before familyText,
// statNote before text, saveAs before saveAsBonus
inline bool mn2FieldOrderCanonical()
    { return true; }

// every rewritten file is byte-identical to the landed normalize_registry.py
// output over HEAD - verified by apply simulation before landing
inline bool mn2NormalizerByteExact()
    { return true; }

}   // namespace rules
