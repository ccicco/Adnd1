// =========================================================================================
// Adnd1 - rules/meta/content_structure_charter.h
// The content-structure charter - the folder hierarchy formalized
// census 888 -> 889.
//
// The content-structure arc opener - the folder-hierarchy charter adjudicated
// with Curtiss 2026-10-31: content/ the data root (game data and script code
// files, C++ never in the tree), the nine domains, the nesting rule with its
// two precedents (kara-tur under forgottenrealms, artifacts under items), the
// tile resolutions as manifest fields (dungeon 64, overland 32). The charter
// document rides doc/content_structure.md.
//
namespace rules {

// ---- the charter frame ----

// the domain count - rules, monsters, npcs, items, spells, tables, world,
// tiles, objects (the charter)
inline int cshContentDomains()
    { return 9; }

// the three main worlds - greyhawk, dragonlance, forgottenrealms (the
// charter)
inline int cshWorldCount()
    { return 3; }

// the nesting rule precedents - karatur under forgottenrealms, artifacts
// under items (the charter)
inline int cshNestingPrecedents()
    { return 2; }

// the dungeon and indoor tile resolution - detail afforded because indoor
// grids stay small (the charter)
inline int cshDungeonTilePx()
    { return 64; }

// the overland and outdoor tile resolution - the memory conservation choice
// on the large grids (the charter)
inline int cshOverlandTilePx()
    { return 32; }

// the six-value dungeon tile vocabulary - void, floor, wall, door, corridor,
// water (world/map.h today)
inline int cshDungeonTileValues()
    { return 6; }

// the viewport pair retiring from world/map.h into the tileset manifests -
// 25x19 at 32px
inline int cshViewportTilesX()
    { return 25; }

// the viewport pair retiring from world/map.h into the tileset manifests -
// 25x19 at 32px
inline int cshViewportTilesY()
    { return 19; }

// ---- the charter doctrines ----

// the data root is content/ - game data and script code files live in the
// tree (the charter)
inline bool cshContentRootAdjudicated()
    { return true; }

// C++ never enters the content tree - engine and loader code stay in their
// domain dirs (the charter)
inline bool cshNoCppInContent()
    { return true; }

// the agreed direction - pins migrate to Lua records under content/rules,
// testing moves to the records (the charter)
inline bool cshRulesMigrateToLua()
    { return true; }

// NPCs are their own domain, separate from monsters - class, level,
// equipment, personality (the charter)
inline bool cshNpcsSeparateFromMonsters()
    { return true; }

// mundane and magic item records share one schema, magic adds the enchant
// fields (the charter)
inline bool cshItemsMundaneMagicTogether()
    { return true; }

// artifacts are their own sub-domain at items/artifacts - unique,
// prose-heavy, curse-carrying (the charter)
inline bool cshArtifactsOwnSubdomain()
    { return true; }

// a module written for a specific campaign world nests under that world (the
// charter)
inline bool cshModulesNestUnderWorld()
    { return true; }

// expansions nest under their parent world - kara-tur under forgottenrealms
// (the charter)
inline bool cshExpansionsNestUnderParent()
    { return true; }

// tile size is a per-tileset manifest field, not an engine constant (the
// charter)
inline bool cshTileSizeManifestField()
    { return true; }

// one tile vocabulary enum shared by the tileset manifests and the map
// records (the charter)
inline bool cshTileVocabShared()
    { return true; }

// an asset is one folder pairing the payload image with its Lua manifest (the
// charter)
inline bool cshAssetManifestPairing()
    { return true; }

}   // namespace rules
