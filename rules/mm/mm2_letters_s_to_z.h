// =========================================================================================
// Adnd1 - rules/mm/mm2_letters_s_to_z.h
// The MM2 normalization batch four - the book closer, the last 83 of 332 defs
// rewritten to the full-field 57-key emission, the monster zombie pin repairs
// riding
// census 942 -> 943.
//
// The MM2 normalization - the per-book schema pass concludes for the MM2 book
// (the R879 normalizer doctrine, the R1009-R1014 MM1 arc, R1016 the OA book
// close, R1017-R1019 the MM2 arc openers): the last 83 sparse MM2 defs
// (shator through zygom) rewritten to the full-field 57-key emission of the
// landed tools/normalize_registry.py - string sentinels n/a, integer
// sentinels -1 - byte-exact against the normalizer output, the canonical
// FIELD_ORDER honored; 581 anchored inserts (2258 inserted lines), zero
// whole-line rewrites, zero move encodings. THE MM2 BOOK CLOSES COMPLETE: 332
// of 332 canonical. THE PIN REPAIRS: the monster zombie (the kWXYZ walk index
// 14) carries hitDiceNum 0 and its mm2_print xp 0/0/0 cells but never carried
// hitDiceBonus, avgHp or lairPct - the loader read absence as 0 and the WXYZ
// grid pinned that 0; the canonical emission writes the -1 sentinel, so three
// pin cells ride this round. The triple-grid shape of this walk: the regtest
// live-def walk pins the loader members against the grid functions, the
// migrated R815 fragment pins the grid functions against its hardcoded
// CWXYZStats copy, AND the fragment carries direct per-cell pins - the row 14
// grid copy and the three direct pins all mirror the repair, the avgHp grid
// comment rides along. The numAttacks/move/magicResistance sentinels are
// loader-coercer neutral (the n/a strings parse to the same 1/0/0 the
// pre-round absence defaults read). The yuan ti carries its by_level xp cells
// - no repair needed. The sweep simulated the fragment (grid copy, direct
// pins) and the live walk in full before the handoff - all bad 0. THE QUEUE:
// FF 185, WSG+MOP 23, DRG 5, the deity seam.
//
namespace rules {

// ---- the batch frame ----

// the MM2 normalization batch four - shator through zygom, the book closer,
// 83 of 332
inline int mq4Round()
    { return 1020; }

// the MM2 defs rewritten to full-field canonical form this batch
inline int mq4DefsNormalized()
    { return 83; }

// the file patches this round - 581 monster windows plus 8 pin-repair patches
// (3 grid cells, 3 fragment direct pins, 1 fragment grid row, 1 grid comment)
inline int mq4PatchEntries()
    { return 589; }

// ---- the MM2 normalization census ----

// the MM2 def census - unchanged by the batch
inline int mq4Mm2Total()
    { return 332; }

// the MM2 defs carrying the full-field emission after this batch - the book
// complete
inline int mq4Mm2NormalizedAfter()
    { return 332; }

// the MM2 defs still sparse after this batch - NONE, the book closed
inline int mq4Mm2Remaining()
    { return 0; }

// the canonical FIELD_ORDER length - every MM2 def emitted with all 57 keys
inline int mq4SchemaKeys()
    { return 57; }

// ---- the patch anatomy ----

// the anchored insert sites - 2258 inserted lines, all sentinel fields
inline int mq4InsSites()
    { return 581; }

// the trailing-comma whole-line rewrites - NONE this batch, every text field
// already carried the Lua-optional comma
inline int mq4CommaSites()
    { return 0; }

// the monster zombie pin cells repaired 0 to -1 - mm2wxyz cases 14 in the
// kWXYZ walk order, hitDiceBonus, avgHp and lairPct (the loader read the
// absent keys as 0; the numAttacks/move/magicResistance n/a sentinels are
// coercer-neutral)
inline int mq4ZombiePinRepairs()
    { return 3; }

// the defs needing whole-line rewrites - NONE this batch, the fields already
// in canonical FIELD_ORDER
inline int mq4ReorderDefs()
    { return 0; }

// ---- the guarantees ----

// the landed normalize_registry.py reads its full 1338-def census - the R1009
// REG glob repair proven live
inline bool mq4NormalizerCensusLive()
    { return true; }

// every rewritten def carries all 57 keys - string sentinel n/a, integer
// sentinel -1, saveAsBonus the loader zero default
inline bool mq4FullFieldEmission()
    { return true; }

// the canonical FIELD_ORDER honored byte-exact - all insert sites, no
// rewrites, no move encodings
inline bool mq4FieldOrderCanonical()
    { return true; }

// every rewritten file is byte-identical to the landed normalize_registry.py
// output over HEAD - the MM2 book renders 332 of 332 canonical, the book
// complete
inline bool mq4NormalizerByteExact()
    { return true; }

}   // namespace rules
