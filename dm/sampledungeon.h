// ============================================================================
// Adnd1 - dm/sampledungeon.h
// R142: DMG pp.94-96 - the SAMPLE DUNGEON (the MONASTERY
// CELLARS & SECRET CRYPTS), the book's own teaching delve:
// three keyed rooms and two d4 wandering tables, pinned
// as pure data (the appendixgh.h pattern: inline accessors,
// no dice - the caller rolls). The book keys rooms 1-3 in
// detail, then says only '4. (Etc.)' - so the crypts behind
// the seventh knob, the crypt wandering column, and the
// crypt-cleric row ride the future-crypts debt: data now,
// delve later.
// ============================================================================

#pragma once

#include "dungeon.h"
#include <cstdint>
#include <vector>

namespace dm {
namespace sampledungeon {

// The seed that summons the keyed delve. Any other seed
// (including the default new-dungeon seed 1) walks the
// generated dungeon exactly as before.
const uint64_t kSampleSeed = 0x53414D50ULL;   // 'SAMP'

// One wandering-table row: a monster key and its count
// range. Both of the book's tables are a single d4.
struct SampleWanderingRow {
    const char* key;
    int lo;
    int hi;
};

// The book's two d4 wandering columns (p.96). crypt=false:
// the monastery halls; crypt=true: the crypt column (data
// for the future crypts - nothing wires it yet). Crypt row
// two is '1 third-level evil cleric and 2 hobgoblins': the
// cleric needs a spell-caster encounter hook and rides
// the debt; the row carries the hobgoblins.
inline SampleWanderingRow sampleWandering(bool crypt,
                                          int roll) {
    static const SampleWanderingRow halls[4] = {
        { "goblin",      3, 12 },
        { "bandit",      2,  5 },
        { "giant_rat",   7, 12 },
        { "fire_beetle", 1,  2 },
    };
    static const SampleWanderingRow crypts[4] = {
        { "ghoul",       1,  2 },
        { "hobgoblin",   2,  2 },
        { "giant_rat",   7, 12 },
        { "skeleton",    2,  5 },
    };
    if (roll < 1) roll = 1;
    if (roll > 4) roll = 4;
    return crypt ? crypts[roll - 1] : halls[roll - 1];
}

// The keyed room texts (room 1-3 of the book = indices
// 0-2 here). Pure ASCII, pure data; the engine logs them
// as the first-sight flavor of the keyed rooms.
inline const char* sampleRoomText(int i) {
    static const char* texts[3] = {
        "Cobwebs curtain this 30 foot square entry chamber; a goblin skull sits against the wall and ten rotting sacks slump nearby. When the wind gusts through the old oak door, it groans - and any torch flame gutters low.",
        "A stream slips north to south through this chamber, feeding a limed-over pool. Beside the water rests a skeleton in abbot robes, one hand folded around a curious key - and an ivory tube lies half in the stream, its vellum map water-ruined save for the first few chambers.",
        "A dome some 25 feet across crowns this ceremonial chamber. A 9 foot platform rises at the far end, seven stone knobs set above empty socket holes - the seventh, the book says, opens the south crypt door."
    };
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    return texts[i];
}

// Build the keyed delve: three chambers joined by a
// straight passage. Room 0 is the book's exact 30 foot
// square entry chamber (3x3 tiles at 10 feet); rooms 1-2
// follow the text's shape at the engine's conventions
// (the book gives no tile measures for them). The entry
// stair lands at the chamber's center; the oak door of
// the text is the door tile at its east jamb.
inline DungeonResult buildSampleDungeon() {
    DungeonResult res;
    world::Map& m = res.map;
    for (int y = 0; y < world::MAP_TILES_Y; ++y)
        for (int x = 0; x < world::MAP_TILES_X; ++x)
            m.set(x, y, world::TILE_VOID);

    GeneratedRoom r0;   // the entry chamber, 30 square
    r0.x = 30; r0.y = 30; r0.w = 3; r0.h = 3;
    GeneratedRoom r1;   // the water room (convention)
    r1.x = 38; r1.y = 28; r1.w = 4; r1.h = 5;
    GeneratedRoom r2;   // the ceremonial dome
    r2.x = 46; r2.y = 30; r2.w = 4; r2.h = 4;

    const GeneratedRoom* rs[3] = { &r0, &r1, &r2 };
    for (int i = 0; i < 3; ++i) {
        const GeneratedRoom& r = *rs[i];
        for (int yy = 0; yy < r.h; ++yy)
            for (int xx = 0; xx < r.w; ++xx)
                m.set(r.x + xx, r.y + yy, world::TILE_FLOOR);
    }
    // the joining passage along the chambers mid-line,
    // with the book oak doors at the first two jambs
    for (int x = 33; x <= 45; ++x) {
        int t = (x == 33 || x == 42) ? world::TILE_DOOR
                                    : world::TILE_CORR;
        m.set(x, 31, t);
    }

    res.rooms.push_back(r0);
    res.rooms.push_back(r1);
    res.rooms.push_back(r2);
    res.entryX = 31;   // the chamber center
    res.entryY = 31;
    return res;
}

} // namespace sampledungeon
} // namespace dm
