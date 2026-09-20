// ============================================================================
// Adnd1 — dm/dm.h
// The DM layer: morale, reactions, wandering monsters, dungeon
// generation. The game adjudicates; the player plays.
//
// Source: Dungeon Masters Guide (2012 Premium reprint):
//   - Morale: DMG p.67-68 (base scores, 2d10 adjustments table)
//   - Reactions: DMG p.71-72 (encounter reaction table, 2d6)
//   - Wandering monsters: DMG p.61 (check cadence) + Appendix C
//     (p.182-187 monster level tables)
//   - Dungeon generation: DMG Appendix A (p.170-172: passages, doors,
//     rooms, contents)
// ============================================================================

#pragma once

#include "../rules/dice.h"
#include "../rules/turn.h"

#include <cstdint>

namespace dm {

using rules::Dice;
using rules::Rng;

// ----------------------------------------------------------------------------
// MORALE (DMG p.67-68)
//
// Every monster has a base morale score. Checks happen at defined
// triggers; 2d10 is rolled against adjustments + base score.
//   score <= adjusted base : monster fights on
//   score >  adjusted base : monster fails — flees/surrenders
// ----------------------------------------------------------------------------
enum MoraleBase : int {
    MORALE_FANATIC  = 18,  // fights to the death: undead, mindless,
                           // fanatically loyal
    MORALE_ELITE    = 16,  // elite troops, high-HD monsters
    MORALE_AVERAGE  = 12,  // typical humanoids
    MORALE_IRREGULAR= 10,  // bandits, rabble
    MORALE_LOW      = 8,   // weak, cowardly
    MORALE_NONE     = 6    // non-fighters, animals of low cunning
};

enum MoraleTrigger : int {
    MORALE_ON_START = 0,        // encounter begins, odds even
    MORALE_ON_OUTNUMBERED,      // facing superior numbers
    MORALE_ON_50PCT_LOSS,       // half the group down
    MORALE_ON_LEADER_DOWN,      // leader/alpha killed
    MORALE_ON_FLEEING_ALLY,     // ally group routed
    MORALE_TRIGGER_COUNT
};

struct MoraleState {
    int base           = MORALE_AVERAGE;
    int lossesPct      = 0;    // 0-100
    bool leaderDown    = false;
    bool allyFled      = false;
    bool outnumbered   = false;
};

// Roll 2d10 + situational modifiers; compare to base.
bool moraleCheck(Dice& dice, const MoraleState& m, MoraleTrigger trig);

// ----------------------------------------------------------------------------
// REACTIONS (DMG p.71-72): 2d6 on the encounter reaction table, with
// CHA reaction adjustment (R3) applied to the roll.
// ----------------------------------------------------------------------------
enum Reaction : int {
    REACTION_HOSTILE   = 0,   // attacks immediately
    REACTION_THREATEN  = 1,   // hostile, may attack if pressed
    REACTION_INDIFFERENT= 2,  // neutral, goes about business
    REACTION_NEUTRAL   = 3,   // neutral, may parley
    REACTION_FRIENDLY  = 4,   // receptive, may aid
    REACTION_HELPFUL   = 5    // actively assists
};

Reaction rollReaction(Dice& dice, int chaReactionAdj);

// ----------------------------------------------------------------------------
// WANDERING MONSTERS (DMG p.61 + Appendix C)
//
// One check per turn of dungeon time (the hook in adnd1.cpp calls
// this). Chance is per-level configurable (DMG suggests 1 in 12 base
// at 1st-3rd dungeon levels; higher dungeon levels check at a worse
// chance — tuned by dungeon level table when Appendix C is wired).
// ----------------------------------------------------------------------------
struct WanderConfig {
    int chanceOutOf12 = 1;    // base 1-in-12 (DMG default guidance)
    int distanceRoll  = 0;    // arrival distance modifier hook
};

// True = a wandering encounter occurs this turn.
bool wanderCheck(Dice& dice, const WanderConfig& cfg);

// Distance (in tens of feet) the encounter is first spotted at:
// 2d6 x 10'.
int wanderDistance(Dice& dice);

// ----------------------------------------------------------------------------
// DUNGEON GENERATION (DMG Appendix A, p.170-172)
//
// Random dungeon: begin at a stair/entry, follow passage generation,
// roll doors where passages turn or end, generate rooms, stock
// contents. Encoded here: the tables the generator rolls on. The map
// assembly (tile writing) lives in dm/dungeon.cpp using the Map
// struct from adnd1.cpp — for now the generator produces a tile grid
// via callback so it stays decoupled from the Win32 layer.
// ----------------------------------------------------------------------------

// Passage width (in 10' tiles): 1 = 10' wide, 2 = 20' wide, 3 = 30'.
int rollPassageWidth(Dice& dice);          // d20: 1-12 -> 1, 13-19 -> 2, 20 -> 3

// At a passage T/junction: continues/crossing/turn table.
enum PassageFeature : int {
    PASSAGE_STRAIGHT = 0,   // continues same direction
    PASSAGE_TURN,           // turns left or right
    PASSAGE_T_JUNCTION,     // side passage joins
    PASSAGE_CROSS,          // four-way
    PASSAGE_CHAMBER,        // opens into a room
    PASSAGE_DEAD_END,       // passage ends (door/chance)
    PASSAGE_FEATURE_COUNT
};
PassageFeature rollPassageFeature(Dice& dice);   // d20 table, App A

// Turn direction at a turn/junction: -1 left, +1 right (axis-relative).
int rollTurnDirection(Dice& dice);               // d6: 1-3 left, 4-6 right

// Doors: chance a door is stuck, locked, trapped (App A "doors" notes:
// 1-in-6 stuck, 1-in-10 locked; trapped only on contents rolls).
struct DoorState {
    bool stuck  = false;
    bool locked = false;
    bool secret = false;
};
DoorState rollDoor(Dice& dice);

// Room size in tiles: d6 pairs -> small/medium/large + dimensions.
// Returns width x height in 10' tiles (e.g. 2x3, 4x6).
void rollRoomSize(Dice& dice, int& w, int& h);

// Room contents (Appendix A room contents table): empty, monster,
// monster+treasure, treasure, special, trap/empty-with-trap.
enum RoomContents : int {
    ROOM_EMPTY = 0,
    ROOM_MONSTER,
    ROOM_MONSTER_TREASURE,
    ROOM_TREASURE,
    ROOM_SPECIAL,
    ROOM_TRAP,
    ROOM_CONTENTS_COUNT
};
RoomContents rollRoomContents(Dice& dice);   // d20 weighted table

} // namespace dm