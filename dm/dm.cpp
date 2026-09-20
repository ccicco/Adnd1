// ============================================================================
// Adnd1 — dm/dm.cpp
// DMG morale, reactions, wandering, and Appendix A tables.
// ============================================================================

#include "dm.h"

namespace dm {

// ----------------------------------------------------------------------------
// Morale (DMG p.67-68)
//
// 2d10 roll vs base score, modified by situation:
//   + ally fled            (only when checking because ally fled: the
//                            fleeing is the trigger, not also a bonus)
// Situational modifiers applied to the TARGET (the base score):
//   outnumbered            +2 to base (harder to break when you have
//                            numbers? No — DMG: roll is against the
//                            monster's base; outnumbering the
//                            MONSTERS lowers their effective morale)
// Rebuild convention (logged decision, from original morale tranche):
//   adjusted = base
//     - 4 if 50%+ losses (already suffered)
//     - 3 if leader down
//     - 3 if an ally group has fled
//     - 2 if outnumbered by the party
//   The 2d10 roll must be <= adjusted to hold. Higher roll = worse.
// ----------------------------------------------------------------------------

bool moraleCheck(Dice& dice, const MoraleState& m, MoraleTrigger trig) {
    int adjusted = m.base;

    // accumulated state effects
    if (m.lossesPct >= 50) adjusted -= 4;
    if (m.leaderDown)      adjusted -= 3;
    if (m.allyFled)        adjusted -= 3;
    if (m.outnumbered)     adjusted -= 2;

    // fresh-trigger effects (DMG 2d10 adjustments table shape)
    switch (trig) {
        case MORALE_ON_50PCT_LOSS: adjusted -= 2; break;   // fresh shock
        case MORALE_ON_LEADER_DOWN: adjusted -= 2; break;
        default: break;
    }

    if (adjusted < 2) adjusted = 2;
    if (adjusted > 20) adjusted = 20;

    int roll = (int)dice.roll(2, 10, 0);
    return roll <= adjusted;   // true = holds morale
}

// ----------------------------------------------------------------------------
// Reactions (DMG p.71-72): 2d6 + CHA adj
//   2      : hostile, attacks
//   3-4    : threatening
//   5-6    : indifferent
//   7-8    : neutral
//   9-11   : friendly
//   12+    : helpful
// NOTE: the printed DMG table's exact bands get verified in the book
// pass (verification debt); this is the standard 1e shape.
// ----------------------------------------------------------------------------

Reaction rollReaction(Dice& dice, int chaReactionAdj) {
    int roll = (int)dice.roll(2, 6, 0) + chaReactionAdj;
    if (roll <= 2)  return REACTION_HOSTILE;
    if (roll <= 4)  return REACTION_THREATEN;
    if (roll <= 6)  return REACTION_INDIFFERENT;
    if (roll <= 8)  return REACTION_NEUTRAL;
    if (roll <= 11) return REACTION_FRIENDLY;
    return REACTION_HELPFUL;
}

// ----------------------------------------------------------------------------
// Wandering monsters (DMG p.61)
// ----------------------------------------------------------------------------

bool wanderCheck(Dice& dice, const WanderConfig& cfg) {
    if (cfg.chanceOutOf12 <= 0) return false;
    if (cfg.chanceOutOf12 >= 12) return true;
    return (int)dice.d12() <= cfg.chanceOutOf12;
}

int wanderDistance(Dice& dice) {
    return (int)dice.roll(2, 6, 0) * 10;   // tens of feet
}

// ----------------------------------------------------------------------------
// Dungeon generation (Appendix A)
// ----------------------------------------------------------------------------

int rollPassageWidth(Dice& dice) {
    int r = (int)dice.d20();
    if (r <= 12) return 1;   // 10'
    if (r <= 19) return 2;   // 20'
    return 3;                // 30'
}

PassageFeature rollPassageFeature(Dice& dice) {
    int r = (int)dice.d20();
    // Appendix A "passage" table shape (verification debt: exact
    // weights vs printed table)
    if (r <= 8)  return PASSAGE_STRAIGHT;
    if (r <= 12) return PASSAGE_TURN;
    if (r <= 15) return PASSAGE_T_JUNCTION;
    if (r <= 17) return PASSAGE_CROSS;
    if (r <= 19) return PASSAGE_CHAMBER;
    return PASSAGE_DEAD_END;
}

int rollTurnDirection(Dice& dice) {
    return ((int)dice.d6() <= 3) ? -1 : +1;
}

DoorState rollDoor(Dice& dice) {
    DoorState d;
    d.stuck  = ((int)dice.d6()  == 1);   // 1-in-6 stuck
    d.locked = ((int)dice.d10() == 1);   // 1-in-10 locked
    return d;
}

void rollRoomSize(Dice& dice, int& w, int& h) {
    // Appendix A room size: d6+d6 pairs; standard shape
    int a = (int)dice.d6();
    int b = (int)dice.d6();
    // small 1-2, medium 3-4, large 5-6 scale factor
    int scale = (a <= 2) ? 1 : (a <= 4) ? 2 : 3;
    w = 1 + (b / 2) + scale;             // rough 2-6 tiles
    h = 1 + ((int)dice.d6() / 2) + (scale == 3 ? 1 : 0);
    if (w < 2) w = 2;
    if (h < 2) h = 2;
}

RoomContents rollRoomContents(Dice& dice) {
    int r = (int)dice.d20();
    // Appendix A room contents weighted shape (verification debt)
    if (r <= 8)  return ROOM_EMPTY;             // ~40%
    if (r <= 13) return ROOM_MONSTER;           // ~30%
    if (r <= 16) return ROOM_MONSTER_TREASURE;  // ~15%
    if (r <= 18) return ROOM_TREASURE;          // ~10%
    if (r == 19) return ROOM_SPECIAL;           // 5%
    return ROOM_TRAP;                           // 5%
}

} // namespace dm