// =========================================================================================
// Adnd1 - rules/ff/normalization_batch3.h
// The FF normalization batch three - the FF book closer, the last 54 of 185
// defs rewritten to the full-field 57-key emission
// census 945 -> 946.
//
// The FF normalization - the per-book schema pass concludes for the Fiend
// Folio (the R879 normalizer doctrine, the R1009-R1014 MM1 arc, R1016 the OA
// book close, R1017-R1020 the MM2 arc closed, R1021 the letters a-g, R1022
// the letters h-r): the last 54 sparse FF defs (the letters s-z) rewritten to
// the canonical FIELD_ORDER emission, byte-exact against the landed
// normalize_registry.py; the FF book closes COMPLETE on both axes - 185 of
// 185 canonical; all 378 patches are anchored sentinel inserts under the
// single-line anchor doctrine (the R1021 aarakocra lesson); no reorders, no
// comma sites, no pin repairs - the FF book carries no fragment grids; the
// loader reads the sentinels under the R879 uniform coercer doctrine already
// live on the 787 normalized MM1, MM2 and OA defs
//
namespace rules {

// ---- the batch frame ----

// the FF normalization batch three - the letters s-z, the FF book closer, 54
// of 185
inline int fq3Round()
    { return 1023; }

// the FF defs rewritten to full-field canonical form this batch - the letters
// s-z
inline int fq3DefsNormalized()
    { return 54; }

// the file patches this round - 378 monster windows, all anchored sentinel
// inserts
inline int fq3PatchEntries()
    { return 378; }

// ---- the FF normalization census ----

// the FF def census - unchanged by the batch
inline int fq3FfTotal()
    { return 185; }

// the FF defs carrying the full-field emission after this batch - the FF book
// complete
inline int fq3FfNormalizedAfter()
    { return 185; }

// the FF defs still sparse after this batch - NONE, the book closed
inline int fq3FfRemaining()
    { return 0; }

// the canonical FIELD_ORDER length - every FF def emitted with all 57 keys
inline int fq3SchemaKeys()
    { return 57; }

// ---- the patch anatomy ----

// the anchored insert sites - 1458 inserted lines, all sentinel fields
inline int fq3InsSites()
    { return 378; }

// the trailing-comma whole-line rewrites - NONE this batch, every text field
// already carried the Lua-optional comma
inline int fq3CommaSites()
    { return 0; }

// the defs needing whole-line rewrites - NONE this batch, the fields already
// in canonical FIELD_ORDER
inline int fq3ReorderDefs()
    { return 0; }

// ---- the guarantees ----

// the landed normalize_registry.py reads its full 1338-def census - the
// registry floor live
inline bool fq3NormalizerCensusLive()
    { return true; }

// every rewritten def carries all 57 keys - string sentinel n/a, integer
// sentinel -1, saveAsBonus the loader zero default
inline bool fq3FullFieldEmission()
    { return true; }

// zero whole-line rewrites, zero deletes - every patch an anchored insert,
// the single-line anchor doctrine (the R1021 aarakocra lesson held, the
// second engine pass simulated in full pre-handoff)
inline bool fq3InsertOnly()
    { return true; }

// no classed defs in the letters s-z - zero saveAs keys, the R155 contract
// untouched
inline bool fq3NoClassedDefs()
    { return true; }

}   // namespace rules
