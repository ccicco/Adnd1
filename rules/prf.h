// =========================================================================================
// Adnd1 - rules/prf.h
// THE REGISTRY PROMOTION DEF NAME FIX - the bare monster keys, the wsgRoles
// service mask, and the three MM1 field rides
// census 715 -> 716.
//
// The name-fix round of the promotion seam (the user call, 2026-10-23:
// monster .lua files cannot carry book prefixes). The 18 R792 wsg_ keys go
// bare: 15 new bare-key .lua defs land through data_files (the bear, the two
// camels, the sled dog, the donkey, the two elephants, the five horses, the
// giant ram, the sheep, the yak), and the three MM1 collisions (ape, mule,
// pony) keep their single existing defs with the WSG Table 13 rows riding as
// field patches (the single-def-per-creature rule). MonsterDef gains the
// wsgRoles service mask - 1 normal, 2 mount, 4 pack - the roles derived from
// the wsgmount.h catalog pins: 13 mount rows, 15 pack rows, all 18 carrying
// the normal bit (the wild horse normal only, the elephants trained only, the
// sled dog a pack team). The stale untracked wsg_ keys leave the tree by the
// pre-cut git clean (they never reached the f077c24 commit), so the registry
// reads 481 -> 478 live, superseding the prg 481 pin (the reconciliation
// carried in this banner; the prg record stays landed).
//
namespace rules {

// ---- the name fix consts (the R793 def name fix) ----

// The name-fix round: monster .lua keys go bare (the user call)
inline int prfNameFixRound()
    { return 793; }

// The WSG Table 13 row count: the ape through the yak, all 18 carried
inline int prfWSGRowCount()
    { return 18; }

// The new bare-key defs: the 15 non-colliding WSG animals (the bear through
// the yak)
inline int prfBareKeyDefCount()
    { return 15; }

// The MM1 collisions keeping their single defs with field rides: ape, mule,
// pony
inline int prfFieldRideDefCount()
    { return 3; }

// The data_files entries: the 55 R792 survivors (the OA 47 and MOP 8) plus
// the 15 new bare-key defs
inline int prfDataFileCount()
    { return 70; }

// The live registry after the fix: 481 minus the 18 stale wsg_ keys plus the
// 15 bare-key defs - supersedes the prg 481 pin
inline int prfRegistryDefTotal()
    { return 478; }

// The wsgRoles normal bit: the creature serves as a normal encountered animal
inline int prfRoleMaskNormal()
    { return 1; }

// The wsgRoles mount bit: the creature serves as a mount
inline int prfRoleMaskMount()
    { return 2; }

// The wsgRoles pack bit: the creature serves as a pack/burden animal
inline int prfRoleMaskPack()
    { return 4; }

// The Table 13 rows carrying the mount bit (wsgmount.h catalog)
inline int prfMountRoleRowCount()
    { return 13; }

// The Table 13 rows carrying the pack bit (wsgmount.h catalog)
inline int prfPackRoleRowCount()
    { return 15; }

// The promotion schema fields after this round: the five R792 fields plus
// wsgRoles
inline int prfSchemaFieldCount()
    { return 6; }

// ---- the name fix bools (the R793 def name fix) ----

// Monster .lua keys are bare creature names - no book prefixes (the user
// call)
inline bool prfBareMonsterKeysOnly()
    { return true; }

// One def per creature: the ape, mule and pony keep their single MM1 defs,
// the Table 13 rows riding as field patches
inline bool prfSingleDefPerCreature()
    { return true; }

// The normal/mount/pack roles ride the wsgRoles bitmask field, not the
// filename
inline bool prfRolesRideWsgRolesMask()
    { return true; }

// The role bits are derived from the wsgmount.h catalog prose pins (13
// mounts, 15 pack, all 18 normal)
inline bool prfRolesDerivedFromCatalog()
    { return true; }

// The prg 481 pin is superseded by 478 - the reconciliation carried in the
// prf banner, the prg record stays landed
inline bool prfPrgRegistryPinSuperseded()
    { return true; }

// The 18 stale wsg_ keys never reached the f077c24 commit (rn predates
// data_files) - they leave the tree by the pre-cut git clean
inline bool prfStaleUntrackedKeysRemoved()
    { return true; }

// The defs are generated data tables in the MM1 format - DO NOT hand-edit,
// regenerate
inline bool prfDefsAreGeneratedTables()
    { return true; }

// The defs load at runtime through the existing Lua 5.4 C API loader - the
// defensive coercers carry them
inline bool prfDefsRideRegistryLoader()
    { return true; }

// The pin headers stay the print-fidelity record; the .lua defs are the
// engine-feeding data layer
inline bool prfPinHeadersStayPrintRecord()
    { return true; }

// The battery census reads live this round: loaded 478, errors 0
inline bool prfBatteryCensusGrowsLive()
    { return true; }

// The wild horse carries the normal bit only - unbroken, not a mount or pack
// animal until trained
inline bool prfWildHorseNormalOnly()
    { return true; }

// The elephants carry mount and pack bits for the trained catalog service -
// the print's trained-only caveat
inline bool prfElephantsRideTrainedOnly()
    { return true; }

}   // namespace rules
