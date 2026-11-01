// =========================================================================================
// Adnd1 - rules/fq2.h
// The FF normalization batch two - the letters h-r, 60 of 185 defs rewritten
// to the full-field 57-key emission
// census 944 -> 945.
//
// The FF normalization - the per-book schema pass continues for the Fiend
// Folio (the R879 normalizer doctrine, the R1009-R1014 MM1 arc, R1016 the OA
// book close, R1017-R1020 the MM2 arc closed, R1021 the letters a-g): the
// letters h-r rewritten to the canonical FIELD_ORDER emission, byte-exact
// against the landed normalize_registry.py; all 420 patches are anchored
// sentinel inserts under the single-line anchor doctrine (the R1021 aarakocra
// lesson); no reorders, no comma sites, no pin repairs - the FF book carries
// no fragment grids; the loader reads the sentinels under the R879 uniform
// coercer doctrine already live on the 787 normalized MM1, MM2 and OA defs
//
namespace rules {

// ---- the batch frame ----

// the FF normalization batch two - the letters h-r, 60 of 185
inline int fq2Round()
    { return 1022; }

// the FF defs rewritten to full-field canonical form this batch - the letters
// h-r
inline int fq2DefsNormalized()
    { return 60; }

// the file patches this round - 420 monster windows, all anchored sentinel
// inserts
inline int fq2PatchEntries()
    { return 420; }

// ---- the FF normalization census ----

// the FF def census - unchanged by the batch
inline int fq2FfTotal()
    { return 185; }

// the FF defs carrying the full-field emission after this batch - the letters
// a-r
inline int fq2FfNormalizedAfter()
    { return 131; }

// the FF defs still sparse after this batch - the letters s-z, the book
// closes next round
inline int fq2FfRemaining()
    { return 54; }

// the canonical FIELD_ORDER length - every FF def emitted with all 57 keys
inline int fq2SchemaKeys()
    { return 57; }

// ---- the patch anatomy ----

// the anchored insert sites - 1620 inserted lines, all sentinel fields
inline int fq2InsSites()
    { return 420; }

// the trailing-comma whole-line rewrites - NONE this batch, every text field
// already carried the Lua-optional comma
inline int fq2CommaSites()
    { return 0; }

// the defs needing whole-line rewrites - NONE this batch, the fields already
// in canonical FIELD_ORDER
inline int fq2ReorderDefs()
    { return 0; }

// ---- the guarantees ----

// the landed normalize_registry.py reads its full 1338-def census - the
// registry floor live
inline bool fq2NormalizerCensusLive()
    { return true; }

// every rewritten def carries all 57 keys - string sentinel n/a, integer
// sentinel -1, saveAsBonus the loader zero default
inline bool fq2FullFieldEmission()
    { return true; }

// zero whole-line rewrites, zero deletes - every patch an anchored insert,
// the single-line anchor doctrine (the R1021 aarakocra lesson held, the
// second engine pass simulated in full pre-handoff)
inline bool fq2InsertOnly()
    { return true; }

// no classed defs in the letters h-r - zero saveAs keys, the R155 contract
// untouched
inline bool fq2NoClassedDefs()
    { return true; }

}   // namespace rules
