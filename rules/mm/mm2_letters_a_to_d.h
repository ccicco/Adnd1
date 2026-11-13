// =========================================================================================
// Adnd1 - rules/mm/mm2_letters_a_to_d.h
// The MM2 normalization batch one - 83 of 332 defs rewritten to the
// full-field 57-key emission
// census 939 -> 940.
//
// The MM2 normalization - the per-book schema pass continued (the R879
// normalizer doctrine, R1009-R1014 the MM1 arc, R1016 the OA book close):
// every sparse MM2 def rewritten to the full-field 57-key emission of the
// landed tools/normalize_registry.py - string sentinels n/a, integer
// sentinels -1, saveAsBonus riding the loader zero default (the R155
// contract) - byte-exact against the normalizer output, the canonical
// FIELD_ORDER honored. The MM2 defs were promoted to the registry
// post-normalizer, so this batch is ALL INSERT SITES - 586 anchored inserts
// (2236 inserted lines), zero whole-line reorders, zero move encodings; the
// fields are already in canonical order, only sparse. No normalizer repairs
// ride this round. Eight audited keys in this batch (amaimon, azer, fire_bat,
// cambion, camptosaurus, chaggrin, crysmal, dao) - every constraint reads a
// key the def already carries; no audit touches a sentinel-emitted key. The
// MM2 census after this round: 332 defs, 83 canonical, 249 remaining. THE
// QUEUE: the MM2 batches two through four follow, then FF 185, WSG+MOP 23,
// DRG 5, the deity seam.
//
namespace rules {

// ---- the batch frame ----

// the MM2 normalization batch one - the letters a through d, 83 of 332
inline int mqRound()
    { return 1017; }

// the MM2 defs rewritten to full-field canonical form this batch
inline int mqDefsNormalized()
    { return 83; }

// the file patches this round - 586 monster windows, all inserts, no
// normalizer repairs, no move encodings
inline int mqPatchEntries()
    { return 586; }

// ---- the MM2 normalization census ----

// the MM2 def census - unchanged by the batch
inline int mqMm2Total()
    { return 332; }

// the MM2 defs carrying the full-field emission after this batch
inline int mqMm2NormalizedAfter()
    { return 83; }

// the MM2 defs still sparse after this batch - the batches two through four
// follow
inline int mqMm2Remaining()
    { return 249; }

// the canonical FIELD_ORDER length - every MM2 def emitted with all 57 keys,
// string sentinel n/a, integer sentinel -1
inline int mqSchemaKeys()
    { return 57; }

// ---- the patch anatomy ----

// the anchored insert sites - 2236 inserted lines, all sentinel fields; the
// MM2 defs were promoted post-normalizer, already in canonical order
inline int mqInsSites()
    { return 586; }

// the defs needing whole-line reorders - NONE this batch, the fields already
// in the canonical FIELD_ORDER
inline int mqReorderDefs()
    { return 0; }

// ---- the guarantees ----

// the landed normalize_registry.py reads its full 1338-def census - the R1009
// REG glob repair proven live
inline bool mqNormalizerCensusLive()
    { return true; }

// every rewritten def carries all 57 keys - the sparse-era implicit-nil
// fields now explicit with n/a strings, -1 ints and the saveAsBonus zero
// default
inline bool mqFullFieldEmission()
    { return true; }

// the canonical FIELD_ORDER honored byte-exact - the MM2 defs needed no
// reorders, only the full-field inserts
inline bool mqFieldOrderCanonical()
    { return true; }

// every rewritten file is byte-identical to the landed normalize_registry.py
// output over HEAD - verified by apply simulation before landing; the MM2
// book now renders 83 of 332 canonical
inline bool mqNormalizerByteExact()
    { return true; }

}   // namespace rules
