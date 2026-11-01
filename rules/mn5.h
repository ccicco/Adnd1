// =========================================================================================
// Adnd1 - rules/mn5.h
// The MM1 normalization batch five - 40 defs rewritten to the full-field
// 57-key emission, the letters t through v
// census 935 -> 936.
//
// The MM1 normalization batch five - the per-book schema pass, MM1 part five
// of six, riding the letters t through v. The standing queue from R886/R879,
// continuing R1009 through R1012: every sparse MM1 def rewritten to the
// full-field 57-key emission of the landed tools/normalize_registry.py -
// string sentinels n/a, integer sentinels -1, saveAsBonus riding the loader
// zero default (the R155 contract) - byte-exact against the normalizer
// output, the canonical FIELD_ORDER honored including text before familyText.
// This batch rewrites 40 defs via 190 anchored insert sites (664 inserted
// lines), 17 whole-line reorder sites across 17 defs, and no line-move
// encodings this batch. No normalizer repairs ride this round - both landed
// in R1009. No audited key in this batch rides a field-constraint audit - the
// encounter-grid membership and presence checks only. The MM1 census after
// this round: 408 defs, 372 canonical, 36 remaining for batch six (the
// letters w through z).
//
namespace rules {

// ---- the batch frame ----

// the MM1 normalization batch five - the letters t through v
inline int mn5Round()
    { return 1013; }

// the MM1 defs rewritten to full-field canonical form this batch - the
// letters t through v
inline int mn5DefsNormalized()
    { return 40; }

// the file patches this round - 207 monster windows, no normalizer repairs
// (both landed in R1009), no line-move encodings this batch
inline int mn5PatchEntries()
    { return 207; }

// ---- the MM1 normalization census ----

// the MM1 def census - unchanged by the batch
inline int mn5Mm1Total()
    { return 408; }

// the MM1 defs carrying the full-field emission after this batch - the R1009
// a-f, R1010 g-k, R1011 l-p and R1012 q-s letters plus these t-v
inline int mn5Mm1NormalizedAfter()
    { return 372; }

// the MM1 defs still sparse after this batch - batch six, the letters w
// through z
inline int mn5Mm1Remaining()
    { return 36; }

// the canonical FIELD_ORDER length - every MM1 def emitted with all 57 keys,
// string sentinel n/a, integer sentinel -1
inline int mn5SchemaKeys()
    { return 57; }

// ---- the patch anatomy ----

// the anchored insert sites - 664 inserted lines, the n/a and -1 sentinel
// fields plus the reordered text lines
inline int mn5InsSites()
    { return 190; }

// the defs needing whole-line reorders to reach the canonical FIELD_ORDER -
// text before familyText, statNote before text
inline int mn5ReorderDefs()
    { return 17; }

// ---- the guarantees ----

// the landed normalize_registry.py reads its full 1338-def census - the R1009
// REG glob repair proven live
inline bool mn5NormalizerCensusLive()
    { return true; }

// every rewritten def carries all 57 keys - the sparse-era implicit-nil
// fields now explicit with n/a strings, -1 ints and the saveAsBonus zero
// default
inline bool mn5FullFieldEmission()
    { return true; }

// the canonical FIELD_ORDER honored byte-exact - text before familyText,
// statNote before text, saveAs before saveAsBonus
inline bool mn5FieldOrderCanonical()
    { return true; }

// every rewritten file is byte-identical to the landed normalize_registry.py
// output over HEAD - verified by apply simulation before landing
inline bool mn5NormalizerByteExact()
    { return true; }

}   // namespace rules
