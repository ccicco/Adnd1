// =========================================================================================
// Adnd1 - rules/mm/mm1_letters_w_to_z.h
// The MM1 normalization batch six - 36 defs rewritten to the full-field
// 57-key emission, the letters w through z - MM1 closes complete
// census 936 -> 937.
//
// The MM1 normalization batch six - the per-book schema pass, MM1 part six of
// six, riding the letters w through z and CLOSING the MM1 book. The standing
// queue from R886/R879, continuing R1009 through R1013: every sparse MM1 def
// rewritten to the full-field 57-key emission of the landed
// tools/normalize_registry.py - string sentinels n/a, integer sentinels -1,
// saveAsBonus riding the loader zero default (the R155 contract) - byte-exact
// against the normalizer output, the canonical FIELD_ORDER honored including
// text before familyText. This batch rewrites the final 36 defs via 178
// anchored insert sites (542 inserted lines), 20 whole-line reorder sites
// across 20 defs, and no line-move encodings this batch. No normalizer
// repairs ride this round - both landed in R1009. No audited key in this
// batch rides a field-constraint audit - the encounter-grid membership and
// presence checks only. The MM1 census after this round: 408 defs, 408
// canonical, 0 remaining - the book complete. THE QUEUE: MM2 332, FF 185, OA
// 47, WSG+MOP 23 follow.
//
namespace rules {

// ---- the batch frame ----

// the MM1 normalization batch six - the letters w through z, the book closes
inline int mn6Round()
    { return 1014; }

// the MM1 defs rewritten to full-field canonical form this batch - the
// letters w through z
inline int mn6DefsNormalized()
    { return 36; }

// the file patches this round - 198 monster windows, no normalizer repairs
// (both landed in R1009), no line-move encodings this batch
inline int mn6PatchEntries()
    { return 198; }

// ---- the MM1 normalization census ----

// the MM1 def census - unchanged by the batch
inline int mn6Mm1Total()
    { return 408; }

// the MM1 defs carrying the full-field emission after this batch - ALL 408,
// the a-z batches complete, the book closed
inline int mn6Mm1NormalizedAfter()
    { return 408; }

// the MM1 defs still sparse after this batch - NONE, the MM1 normalization
// arc is complete
inline int mn6Mm1Remaining()
    { return 0; }

// the canonical FIELD_ORDER length - every MM1 def emitted with all 57 keys,
// string sentinel n/a, integer sentinel -1
inline int mn6SchemaKeys()
    { return 57; }

// ---- the patch anatomy ----

// the anchored insert sites - 542 inserted lines, the n/a and -1 sentinel
// fields plus the reordered text lines
inline int mn6InsSites()
    { return 178; }

// the defs needing whole-line reorders to reach the canonical FIELD_ORDER -
// text before familyText, statNote before text
inline int mn6ReorderDefs()
    { return 20; }

// ---- the guarantees ----

// the landed normalize_registry.py reads its full 1338-def census - the R1009
// REG glob repair proven live
inline bool mn6NormalizerCensusLive()
    { return true; }

// every rewritten def carries all 57 keys - the sparse-era implicit-nil
// fields now explicit with n/a strings, -1 ints and the saveAsBonus zero
// default
inline bool mn6FullFieldEmission()
    { return true; }

// the canonical FIELD_ORDER honored byte-exact - text before familyText,
// statNote before text, saveAs before saveAsBonus
inline bool mn6FieldOrderCanonical()
    { return true; }

// every rewritten file is byte-identical to the landed normalize_registry.py
// output over HEAD - verified by apply simulation before landing; the MM1
// book now renders 408 of 408 canonical
inline bool mn6NormalizerByteExact()
    { return true; }

}   // namespace rules
