// =========================================================================================
// Adnd1 - rules/lreg.h
// THE REGISTRY PROMOTION WIRING - the engine data-files extension and the
// promotion doctrine pins: the tooling for the all-in-one R792
// census 713 -> 714.
//
// The tooling round of the promotion seam. Verified repo state at 3ff2f2a:
// the live registry holds 408 MM1 defs loaded by the Lua 5.4 C API loader;
// the five pin-only creature sets (OA Chapter 12, WSG animals, DMO ladder,
// MOP Appendices II and III) have zero runtime wiring. This round lands the
// engine extension (data_files) and the doctrine pins; R792 writes the 65
// defs in one pass, lands the schema adjustments (the WSG load fields, the
// DMO rank field, the MOP analogue transform field), and the battery census
// grows live: loaded 408 -> 473. The WSG mount and fish headers get one look
// before the R792 cut.
//
namespace rules {

// ---- the promotion consts (the R791 wiring) ----

// The promotion wiring round: the doctrine and the tooling
inline int lregPromoteRound()
    { return 791; }

// The engine data-files extension lands this same round (the R774/R775
// tooling precedent)
inline int lregEngineExtensionRound()
    { return 791; }

// The round that writes all 65 defs in one pass - the user-set all-in-one
// scope
inline int lregDefWriteRound()
    { return 792; }

// The OA Chapter 12 def count: the 28 oa076-oa103 headers expanded (gaki 4,
// gargantua 3, oni 3, generals 3, buso 2, nature spirits 2, tengu 2, oriental
// dragons 2, the rest singles)
inline int lregOARecordCount()
    { return 39; }

// The WSG Table 13 animal count (the ape through the yak)
inline int lregWSGAnimalCount()
    { return 18; }

// The MOP Appendix III count: einheriar, marut, the Beastlands mortal cloud,
// the five archons
inline int lregMOPCreatureCount()
    { return 8; }

// The new-def total: 39 + 18 + 8
inline int lregNewDefTotal()
    { return 65; }

// The live registry before the promotion: 408 defs, every one MM1
inline int lregRegistryCountBefore()
    { return 408; }

// The live registry after: 408 + 65
inline int lregRegistryCountAfter()
    { return 473; }

// The DMO legendary ladder rides as a rank field: the five scion ranks over
// existing defs, no new records
inline int lregScionRankCount()
    { return 5; }

// ---- the promotion bools (the R791 wiring) ----

// The new defs are generated data tables in the MM1 format - DO NOT
// hand-edit, regenerate (the monsters2lua.py doctrine)
inline bool lregDefsAreGeneratedTables()
    { return true; }

// The new defs load at runtime through the existing Lua 5.4 C API loader in
// monsters/MonsterRegistry.cpp - defensive coercers, MonsterDef
inline bool lregDefsRideRegistryLoader()
    { return true; }

// The pin headers stay the print-fidelity record; the .lua defs are the
// engine-feeding data layer
inline bool lregPinHeadersStayPrintRecord()
    { return true; }

// The battery census grows live when the defs land: loaded 408 -> 473, the xp
// audit checks 473 defs
inline bool lregBatteryCensusGrowsLive()
    { return true; }

// The DMO legendary ladder (the +/-1/2/3 altering rules) rides as a rank
// field on existing defs - a schema adjustment, not new files
inline bool lregDMOLadderRidesRankField()
    { return true; }

// The MOP Appendix II elemental-analogue system rides as a transform field -
// analogues transform existing defs, not new files
inline bool lregMOPAnalogueRidesTransformField()
    { return true; }

// The WSG animals need schema adjustments MM1 lacks: the load limits and the
// terrain-class movement rates
inline bool lregWSGAnimalsNeedLoadFields()
    { return true; }

// The engine gains spec-declared new-file emission this round: data_files
// entries, idempotent by existence, counted in the applied/already census
// like a file patch
inline bool lregEngineDataFilesLands()
    { return true; }

// One round carries all the defs - the MM1 precedent: monsters2lua.py
// generated all 408 from the merged @-record file in a single pass
inline bool lregOneRoundCarriesAllDefs()
    { return true; }

// The WSG mount and fish headers get one look before the R792 cut: any
// stat-bearing creatures beyond the Table 13 eighteen ride in
inline bool lregMountFishCheckBeforeCut()
    { return true; }

}   // namespace rules
