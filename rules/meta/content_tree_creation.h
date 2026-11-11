// =========================================================================================
// Adnd1 - rules/meta/content_tree_creation.h
// The content tree creation - the skeleton lands, the monsters move
// census 889 -> 890.
//
// The content-structure arc round two: the content/ skeleton lands via
// thirteen .keep data files (rules, npcs, items, items/artifacts, spells,
// tables, tiles, objects, world and its three world buckets plus the karatur
// expansion bucket), and the monster Lua registry moves from
// monsters/monsters to content/monsters by the user-side git mv - the loader
// path rewritten in six places (adnd1.cpp the loadDirectory call and its
// error string, regtest.cpp the loader walk and its R71fix comment,
// tools/normalize_registry.py its docstring, and the R314 engine audit
// fragment's letter-dir load). The registry and xp code stays in monsters/ -
// C++ never enters the content tree (the R966 charter).
//
namespace rules {

// ---- the tree frame ----

// the empty-domain .keep files landing with the skeleton (content/rules
// through the karatur bucket)
inline int cntTreeKeeps()
    { return 13; }

// the monster lua record count, unchanged by the move from monsters/monsters
// to content/monsters
inline int cntMonsterLua()
    { return 1338; }

// the rewritten path lines - adnd1.cpp twice, regtest.cpp twice,
// tools/normalize_registry.py once, the R314 engine audit fragment once
inline int cntLoaderTouchLines()
    { return 6; }

// the world-tree buckets - greyhawk, dragonlance, forgottenrealms plus the
// karatur expansion bucket
inline int cntWorldTreeDirs()
    { return 4; }

// the loaded floor expected at preflight, the census loading from
// content/monsters (the R924 measure)
inline int cntLoadedFloor()
    { return 1313; }

// ---- the tree facts ----

// the content/ skeleton lands via the .keep data files - no hand mkdir on the
// landing side
inline bool cntSkeletonCreated()
    { return true; }

// the monster registry moves to content/monsters by the user-side git mv,
// staged ahead of the ritual
inline bool cntMonstersMoved()
    { return true; }

// the six loader path lines read content/monsters after this round
inline bool cntLoaderPathUpdated()
    { return true; }

// the .keep rule honored - content/monsters carries no .keep, it is full
inline bool cntKeepEmptyDirsOnly()
    { return true; }

// MonsterRegistry and MonsterXp stay in monsters/ - the loader is engine
// code, outside the content tree
inline bool cntLoaderStaysEngine()
    { return true; }

}   // namespace rules
