// =========================================================================================
// Adnd1 - rules/ff/normalization_batch1.h
// The FF normalization batch one - the letters a-g, the first 71 of 185 defs
// rewritten to the full-field 57-key emission, the FF arc opener
// census 943 -> 944.
//
// The FF normalization - the per-book schema pass opens for the Fiend Folio
// (the R879 normalizer doctrine, the R1009-R1014 MM1 arc, R1016 the OA book
// close, R1017-R1020 the MM2 arc closed): the first 71 sparse FF defs
// rewritten to the canonical FIELD_ORDER emission, byte-exact against the
// landed normalize_registry.py; all 497 patches are anchored sentinel inserts
// - the fields already in canonical order, no reorders, no comma sites, no
// pin repairs (the FF book carries no fragment grids - the promotion headers
// are census-style, the R1018/R1020 mirror class is empty here); the loader
// reads the sentinels under the R879 uniform coercer doctrine already live on
// the 787 normalized MM1, MM2 and OA defs
//
namespace rules {

// ---- the batch frame ----

// the FF normalization batch one - the letters a-g, 71 of 185, the FF arc
// opener
inline int fq1Round()
    { return 1021; }

// the FF defs rewritten to full-field canonical form this batch - the letters
// a-g
inline int fq1DefsNormalized()
    { return 71; }

// the file patches this round - 497 monster windows, all anchored sentinel
// inserts
inline int fq1PatchEntries()
    { return 497; }

// ---- the FF normalization census ----

// the FF def census - unchanged by the batch
inline int fq1FfTotal()
    { return 185; }

// the FF defs carrying the full-field emission after this batch
inline int fq1FfNormalizedAfter()
    { return 71; }

// the FF defs still sparse after this batch - the letters h-z
inline int fq1FfRemaining()
    { return 114; }

// the canonical FIELD_ORDER length - every FF def emitted with all 57 keys
inline int fq1SchemaKeys()
    { return 57; }

// ---- the patch anatomy ----

// the anchored insert sites - 1917 inserted lines, all sentinel fields
inline int fq1InsSites()
    { return 497; }

// the trailing-comma whole-line rewrites - NONE this batch, every text field
// already carried the Lua-optional comma
inline int fq1CommaSites()
    { return 0; }

// the defs needing whole-line rewrites - NONE this batch, the fields already
// in canonical FIELD_ORDER
inline int fq1ReorderDefs()
    { return 0; }

// ---- the guarantees ----

// the landed normalize_registry.py reads its full 1338-def census - the
// registry floor live
inline bool fq1NormalizerCensusLive()
    { return true; }

// every rewritten def carries all 57 keys - string sentinel n/a, integer
// sentinel -1, saveAsBonus the loader zero default
inline bool fq1FullFieldEmission()
    { return true; }

// zero whole-line rewrites, zero deletes - every patch an anchored insert,
// the pre-existing field bytes ride untouched
inline bool fq1InsertOnly()
    { return true; }

// no classed defs in the letters a-g - zero saveAs keys, the R155 contract
// untouched
inline bool fq1NoClassedDefs()
    { return true; }

}   // namespace rules
