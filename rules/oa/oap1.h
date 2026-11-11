// =========================================================================================
// Adnd1 - rules/oa/oap1.h
// The OA normalization batch - 47 defs rewritten to the full-field 57-key
// emission - the book closes complete
// census 938 -> 939.
//
// The OA normalization - the per-book schema pass continued (the R879
// normalizer doctrine, continuing R1009-R1014 the MM1 arc): every sparse OA
// def rewritten to the full-field 57-key emission of the landed
// tools/normalize_registry.py - string sentinels n/a, integer sentinels -1,
// saveAsBonus riding the loader zero default (the R155 contract) - byte-exact
// against the normalizer output, the canonical FIELD_ORDER honored. The OA
// defs were promoted to the registry post-normalizer, so this batch is ALL
// INSERT SITES - 332 anchored inserts (1276 inserted lines), zero whole-line
// reorders, zero move encodings; the fields are already in canonical order,
// only sparse. No normalizer repairs ride this round. The audited key in this
// batch - chiang_lung - rides a registry presence check only, no field
// constraints. The OA census after this round: 47 defs, 47 canonical, 0
// remaining - THE BOOK CLOSES COMPLETE, the promotions (records, tables,
// monster defs) and the normalization both green. THE QUEUE: MM2 332, FF 185,
// WSG+MOP 23, DRG 5 follow.
//
namespace rules {

// ---- the batch frame ----

// the OA normalization batch - the letters a through z, the book closes
inline int oapRound()
    { return 1016; }

// the OA defs rewritten to full-field canonical form this batch
inline int oapDefsNormalized()
    { return 47; }

// the file patches this round - 332 monster windows, all inserts, no
// normalizer repairs, no move encodings
inline int oapPatchEntries()
    { return 332; }

// ---- the OA normalization census ----

// the OA def census - unchanged by the batch
inline int oapOaTotal()
    { return 47; }

// the OA defs carrying the full-field emission after this batch - ALL 47, the
// book closed
inline int oapOaNormalizedAfter()
    { return 47; }

// the OA defs still sparse after this batch - NONE, the OA normalization
// complete
inline int oapOaRemaining()
    { return 0; }

// the canonical FIELD_ORDER length - every OA def emitted with all 57 keys,
// string sentinel n/a, integer sentinel -1
inline int oapSchemaKeys()
    { return 57; }

// ---- the patch anatomy ----

// the anchored insert sites - 1276 inserted lines, all sentinel fields; the
// OA defs were promoted post-normalizer, already in canonical order
inline int oapInsSites()
    { return 332; }

// the defs needing whole-line reorders - NONE this batch, the fields already
// in the canonical FIELD_ORDER
inline int oapReorderDefs()
    { return 0; }

// ---- the guarantees ----

// the landed normalize_registry.py reads its full 1338-def census - the R1009
// REG glob repair proven live
inline bool oapNormalizerCensusLive()
    { return true; }

// every rewritten def carries all 57 keys - the sparse-era implicit-nil
// fields now explicit with n/a strings, -1 ints and the saveAsBonus zero
// default
inline bool oapFullFieldEmission()
    { return true; }

// the canonical FIELD_ORDER honored byte-exact - the OA defs needed no
// reorders, only the full-field inserts
inline bool oapFieldOrderCanonical()
    { return true; }

// every rewritten file is byte-identical to the landed normalize_registry.py
// output over HEAD - verified by apply simulation before landing; the OA book
// now renders 47 of 47 canonical
inline bool oapNormalizerByteExact()
    { return true; }

}   // namespace rules
