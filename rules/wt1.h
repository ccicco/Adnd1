// =========================================================================================
// Adnd1 - rules/wt1.h
// The WSG+MOP normalization tail batch - the 23 defs (15 WSG, 8 MOP)
// rewritten to the full-field 57-key emission
// census 946 -> 947.
//
// The normalization tail - the per-book schema pass enters its tail (the R879
// normalizer doctrine, the R1009-R1014 MM1 arc, R1016 the OA book close,
// R1017-R1020 the MM2 arc closed, R1021-R1023 the FF arc closed): the 15 WSG
// service animals and the 8 MOP outsider defs rewritten to the canonical
// FIELD_ORDER emission, byte-exact against the landed normalize_registry.py;
// the 15 real WSG service role masks ride untouched - only absent keys read
// the sentinels; all 199 patches are anchored sentinel inserts under the
// single-line anchor doctrine (the R1021 aarakocra lesson); no reorders, no
// comma sites, no pin repairs - neither book carries fragment grids; the
// loader reads the sentinels under the R879 uniform coercer doctrine already
// live on the 972 normalized MM1, MM2, OA and FF defs
//
namespace rules {

// ---- the batch frame ----

// the WSG+MOP normalization tail batch - the 23 defs, the per-book pass
// enters its tail
inline int wt1Round()
    { return 1024; }

// the defs rewritten to full-field canonical form this batch - 15 WSG, 8 MOP
inline int wt1DefsNormalized()
    { return 23; }

// the file patches this round - 199 monster windows, all anchored sentinel
// inserts
inline int wt1PatchEntries()
    { return 199; }

// ---- the tail census ----

// the WSG defs in the batch (the service animals - bears, camels, dogs,
// donkeys, elephants, horses, rams, sheep, yak)
inline int wt1WsgDefs()
    { return 15; }

// the MOP defs in the batch (the five archons, the einheriar, the marut, the
// mortai)
inline int wt1MopDefs()
    { return 8; }

// the WSG and MOP defs carrying the full-field emission after this batch -
// the tail complete
inline int wt1TailNormalizedAfter()
    { return 23; }

// the WSG and MOP defs still sparse after this batch - NONE, the tail closed
inline int wt1TailRemaining()
    { return 0; }

// the WSG defs carrying REAL service role masks (1/3/5/7) - the values ride
// untouched, only the absent keys read the sentinels
inline int wt1WsgRolesMasks()
    { return 15; }

// the canonical FIELD_ORDER length - every def emitted with all 57 keys
inline int wt1SchemaKeys()
    { return 57; }

// ---- the patch anatomy ----

// the anchored insert sites - 568 inserted lines, all sentinel fields
inline int wt1InsSites()
    { return 199; }

// the trailing-comma whole-line rewrites - NONE this batch, every text field
// already carried the Lua-optional comma
inline int wt1CommaSites()
    { return 0; }

// the defs needing whole-line rewrites - NONE this batch, the fields already
// in canonical FIELD_ORDER
inline int wt1ReorderDefs()
    { return 0; }

// ---- the guarantees ----

// the landed normalize_registry.py reads its full 1338-def census - the
// registry floor live
inline bool wt1NormalizerCensusLive()
    { return true; }

// every rewritten def carries all 57 keys - string sentinel n/a, integer
// sentinel -1, saveAsBonus the loader zero default
inline bool wt1FullFieldEmission()
    { return true; }

// zero whole-line rewrites, zero deletes - every patch an anchored insert,
// the single-line anchor doctrine (the R1021 aarakocra lesson held, the
// second engine pass simulated in full pre-handoff)
inline bool wt1InsertOnly()
    { return true; }

// the 15 real WSG service role masks byte-identical through the batch - the
// sweep pins the value invariance per def
inline bool wt1WsgRolesPreserved()
    { return true; }

// no classed defs in the batch - zero saveAs keys, the R155 contract
// untouched
inline bool wt1NoClassedDefs()
    { return true; }

}   // namespace rules
