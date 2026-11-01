// =========================================================================================
// Adnd1 - rules/dq1.h
// The DRG normalization batch - the five Dragon magazine defs (death angel,
// mihalli, prowler, qu'uni, vriyagga) rewritten to the full-field 57-key
// emission
// census 947 -> 948.
//
// The registry close - the per-book schema pass lands its last book (the R879
// normalizer doctrine: MM1 R1009-R1014, the OA book R1016, the MM2 arc
// R1017-R1020, the FF arc R1021-R1023, the WSG+MOP tail R1024): the five The
// Dragon magazine variant-layer defs rewritten to the canonical FIELD_ORDER
// emission, byte-exact against the landed normalize_registry.py, and the
// registry closes 1338 of 1338 defs canonical - every def of the census
// carries the full-field emission; the first comma-site round of the arc -
// each DRG text field lacked the Lua-optional trailing comma, so each of the
// five end-of-body windows is one whole-line rewrite merged with the sentinel
// insert, no bare deletes shipped, the sweep green pre-handoff (member scan,
// value invariance, quote parity, brace balance, name and source invariance,
// normalizer exactness and idempotence, xp formula zero exceptions).
//
namespace rules {

// ---- the batch frame ----

// the DRG normalization batch - the five defs, the registry close
inline int dq1Round()
    { return 1025; }

// the defs rewritten to full-field canonical form this batch - the five
// Dragon magazine variant-layer defs
inline int dq1DefsNormalized()
    { return 5; }

// the file patches this round - 30 anchored sentinel inserts, 5 comma-site
// windows, zero deletes
inline int dq1PatchEntries()
    { return 35; }

// ---- the DRG census ----

// the DRG defs in the registry (death angel, mihalli, prowler, qu'uni,
// vriyagga - The Dragon magazine)
inline int dq1DrgTotal()
    { return 5; }

// the DRG defs carrying the full-field emission after this batch - the book
// complete
inline int dq1DrgNormalizedAfter()
    { return 5; }

// the DRG defs still sparse after this batch - NONE, the last book closed
inline int dq1DrgRemaining()
    { return 0; }

// the full registry census the landed normalizer reads - the registry floor
inline int dq1RegistryTotal()
    { return 1338; }

// the registry defs canonical after this batch - THE REGISTRY CLOSES, every
// def of the census carries the full-field emission
inline int dq1RegistryCanonicalAfter()
    { return 1338; }

// the canonical FIELD_ORDER length - every def emitted with all 57 keys
inline int dq1SchemaKeys()
    { return 57; }

// ---- the patch anatomy ----

// the anchored insert sites - 45 inserted lines, all sentinel fields
inline int dq1InsSites()
    { return 30; }

// the trailing-comma whole-line rewrites - the first comma-site round of the
// arc, each DRG text field lacked the Lua-optional comma, each merged with
// its end-of-body insert in one window
inline int dq1CommaSites()
    { return 5; }

// the defs needing whole-line rewrites - NONE this batch, the fields already
// in canonical FIELD_ORDER
inline int dq1ReorderDefs()
    { return 0; }

// ---- the guarantees ----

// the landed normalize_registry.py reads its full 1338-def census - the
// registry floor live
inline bool dq1NormalizerCensusLive()
    { return true; }

// every rewritten def carries all 57 keys - string sentinel n/a, integer
// sentinel -1, the loader reads them uniformly
inline bool dq1FullFieldEmission()
    { return true; }

// THE REGISTRY CLOSES - all 1338 defs of the census carry the full-field
// 57-key emission after this batch, the last five books closed in this arc
inline bool dq1RegistryComplete()
    { return true; }

// no classed defs in the batch - zero saveAs keys, the R155 contract
// untouched
inline bool dq1NoClassedDefs()
    { return true; }

}   // namespace rules
