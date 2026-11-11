# Adnd1 content structure charter

The folder hierarchy for game content, adjudicated with Curtiss
2026-10-31 and pinned R966. This document is the charter: it
answers where any piece of game content lives without asking.

## The content root

content/ is the data root. It holds game data and script code
files. C++ source never enters the content tree - engine and
loader code live in their domain directories outside it
(monsters/ keeps the registry, world/ keeps the tile system).

The one hard constraint: rules/ and rules/audits/ do not move.
The pin ritual anchors there - 66 spec JSONs and 1046 regtest
includes - and stays put while the content domains grow beside
it.

## The domains

- content/rules/ - rule records in Lua. The agreed direction:
  pin content migrates to Lua records here, and testing moves
  with it - the record becomes the audited artifact, the
  mutant battery verifies the records Python-side, a loader
  census guards runtime, regtest shrinks to engine plus smoke
  test.
- content/monsters/{a..z}/ - the monster Lua records (the
  precedent domain: one record per file, the loader census).
- content/npcs/ - NPC records, separate from monsters
  (class/level, equipment, personality).
- content/items/ - item records, bucketed by the printed
  taxonomy (weapons, armor, gear, ...); mundane and magic side
  by side - magic is the same schema plus enchant fields
  (bonus, charges, command word, curse).
- content/items/artifacts/ - the artifact sub-domain: unique,
  prose-heavy objects with powers, side effects and curse
  mechanics (the DDG doctrine precedent; generated only from
  adjudicated pins).
- content/spells/ - spell records (the kSpells roster leaves
  C++). spelleffects stays engine - resolution behavior, not
  data.
- content/tables/ - rollable tables (treasure, encounter,
  appendix dice tables).
- content/world/{greyhawk,dragonlance,forgottenrealms}/ -
  map records, one per world, the grid as row-strings.
- content/tiles/ and content/objects/ - image assets, one
  folder per asset: the payload image plus its Lua manifest
  (cells, frames, collision flags, script hooks).

## The nesting rule

A sub-domain nests under the parent it belongs to. The two
precedents: world/forgottenrealms/karatur/ (Kara-Tur is an
expansion of the Forgotten Realms) and items/artifacts/. A
module written for a specific campaign world nests under that
world (world/<world>/modules/<code>/, its maps, keyed
encounters, NPCs and monsters riding with the module); the
home for world-agnostic modules is an open item.

## Naming rules

1. Top-level directories are lowercase, one word; plural
   means a collection of many files of one kind.
2. Every directory holds exactly one role: pinned, data,
   reference, engine, or ritual. The role decides where a
   file goes.
3. A new top-level directory requires a charter line here
   and a declared role.
4. Collections over about 100 files get single-letter buckets
   a..z keyed on the record name.
5. Issue directories are 3-digit zero-padded; the issue
   directory is the citation unit.
6. Page artifacts: pNNN_full.txt (full text), pNNN_tsv.tsv
   (cell table), pNNN.png (scan).
7. Pin headers take the round prefix (rules/dragon/issue026_opener2.h); audits ride
   rules/audits/r{NNN}_batch.h.
8. Engine code is PascalCase matching the type
   (MonsterRegistry.cpp); state machines state_{noun}.cpp.
9. Lua records are the record key, all lowercase, one record
   per file.
10. Scratch holds anything not durable; durable artifacts
    graduate to extract/ or doc/data.
11. .keep only in otherwise-empty directories.

## The tile decisions

Tile size is a manifest field per tileset, not an engine
constant: dungeon/indoor tiles render at 64x64, overland/
outdoor at 32x32 - the memory-conservation choice, since
overland grids are the large ones and surface cost scales
with tile pixels. TILE_W/H and the viewport pair (25x19)
retire from world/map.h into the manifests; the viewport
derives from window size / tile size. The tile vocabulary is
shared: one enum referenced by the tileset manifests and the
map records alike. The overland vocabulary is an open item -
the first world round establishes it.

## Open items

- the rules record shape (heterogeneous consts/bools/grids/
  chains versus one record per file)
- the overland tile vocabulary
- the home for world-agnostic modules
- committing tile/object binaries versus a gitignored asset
  directory
- the migration order for the domains that leave C++
