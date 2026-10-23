// =========================================================================================
// Adnd1 - rules/prg.h
// THE REGISTRY PROMOTION DEFS - the 73 all-in-one .lua defs (47 OA + 18 WSG +
// 8 MOP), the five schema fields, and the xp-audit print sources
// census 714 -> 715.
//
// The def-write round of the promotion seam, riding the R791 data_files
// extension. 73 new .lua defs land in one pass: 47 OA Chapter 12 defs (the
// corrected census - the kappa pair, the kala pair, the nat trio and the oa91
// hu hsien, ikiryo, jishin mushi trio all ride, the ikiryo with sentinel nil
// stats per the user call), 18 WSG Table 13 animals (the print carries loads
// and movement only, the combat fields riding the documented loader defaults
// per the user call), and 8 MOP Appendix III creatures (the printed stat
// blocks as pinned in appendixiiioutercreatures.h). The MonsterRegistry
// loader gains the five schema fields (loadNormal and loadMax for the WSG
// loads, rank for the DMO legendary ladder, plane and transform for the MOP
// Appendix III and II adjustments - both zero-record, riding existing defs),
// and the regtest xp audit gains the three print sources (oa_print,
// wsg_print, mop_print). The registry grows 408 -> 481 live: the battery
// census reads loaded 481, errors 0.
//
namespace rules {

// ---- the promotion defs consts (the R792 def write) ----

// The def-write round of the promotion seam: the 73 defs in one pass
inline int prgPromoteRound()
    { return 792; }

// The OA Chapter 12 def count: the 28 headers expanded (gaki 4, gargantua 3,
// oni 3, generals 3, buso 2, nature spirits 2, tengu 2, the oriental dragons
// 2, kappa 2, kala 2, nat 3, the oa91 trio, the rest singles) - the corrected
// census, not the R791 working 39
inline int prgOADefCount()
    { return 47; }

// The WSG Table 13 animal count (the ape through the yak)
inline int prgWSGAnimalCount()
    { return 18; }

// The MOP Appendix III count: einheriar, marut, the Beastlands mortai, the
// five archons
inline int prgMOPCreatureCount()
    { return 8; }

// The new-def total: 47 + 18 + 8
inline int prgNewDefTotal()
    { return 73; }

// The live registry before the promotion: 408 defs, every one MM1
inline int prgRegistryCountBefore()
    { return 408; }

// The live registry after: 408 + 73
inline int prgRegistryCountAfter()
    { return 481; }

// The schema fields the loader gains: loadNormal, loadMax, rank, plane,
// transform
inline int prgSchemaFieldCount()
    { return 5; }

// The new xp sources riding the audit: oa_print, wsg_print, mop_print
inline int prgPrintSourceCount()
    { return 3; }

// The data_files entries: one .lua def each
inline int prgDataFileCount()
    { return 73; }

// The loader field patches: MonsterRegistry.h and MonsterRegistry.cpp
inline int prgLoaderFieldPatchCount()
    { return 2; }

// The regtest xp-audit patch: the three print sources join the allowed list
inline int prgXpAuditPatchCount()
    { return 1; }

// The zero-HD sentinel defs: the ikiryo, the tagamaling, the level-based
// einheriar (hitDiceNum 0, the documented defaults ride)
inline int prgSentinelDefCount()
    { return 3; }

// ---- the promotion defs bools (the R792 def write) ----

// The new defs are generated data tables in the MM1 format - DO NOT
// hand-edit, regenerate (the monsters2lua.py doctrine)
inline bool prgDefsAreGeneratedTables()
    { return true; }

// The new defs load at runtime through the existing Lua 5.4 C API loader -
// the defensive coercers carry them
inline bool prgDefsRideRegistryLoader()
    { return true; }

// The pin headers stay the print-fidelity record; the .lua defs are the
// engine-feeding data layer
inline bool prgPinHeadersStayPrintRecord()
    { return true; }

// The battery census grows live this round: loaded 408 -> 481, the xp audit
// checks 481 defs
inline bool prgBatteryCensusGrowsLive()
    { return true; }

// The OA def census is the corrected 47 (the user call, 2026-10-23): the
// kappa pair, the kala pair, the nat trio and the oa91 trio all ride -
// superseding the R791 working 39
inline bool prgOACensusCorrected()
    { return true; }

// The ikiryo rides with sentinel nil stats (the user call): AC, HD, move and
// size nil, the psionic 200-260 projection
inline bool prgIkiryoIncludedWithSentinels()
    { return true; }

// The WSG print carries no combat statistics - loads and movement only, so
// the combat fields ride the documented loader defaults (the user call)
inline bool prgWSGCombatFieldsRideDefaults()
    { return true; }

// The MOP Appendix III stat blocks are taken from the printed pp. 122-123
// exactly as pinned in appendixiiioutercreatures.h
inline bool prgMOPStatBlocksFromPrint()
    { return true; }

// The DMO legendary ladder rides as the rank field on existing defs, default
// 0 - a schema adjustment, no new records
inline bool prgDMOLadderRidesRankField()
    { return true; }

// The MOP Appendix II elemental-analogue system rides as the transform field
// - analogues transform existing defs, no new records
inline bool prgMOPAnalogueRidesTransformField()
    { return true; }

// The WSG animals carry the load limits: loadNormal and loadMax from the
// Table 13 grid (rules/wsganimal.h)
inline bool prgWSGAnimalsNeedLoadFields()
    { return true; }

// The three print sources ride the regtest xp audit allowed list via the file
// patch, so the anomalies stay 0
inline bool prgNewPrintSourcesRideAudit()
    { return true; }

// One round carries all the defs - the MM1 precedent: monsters2lua.py
// generated all 408 from the merged @-record file in a single pass
inline bool prgOneRoundCarriesAllDefs()
    { return true; }

// The rank field defaults 0: every MM1 def stays unchanged, the ladder
// assigns ranks later
inline bool prgRankDefaultsZero()
    { return true; }

}   // namespace rules
