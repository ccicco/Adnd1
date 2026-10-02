// ============================================================================
// Adnd1 - dm/dm.cpp
// DMG morale, reactions, wandering, and Appendix A tables.
// ============================================================================

#include "dm.h"
#include "appendixa.h"   // R124: pp.169-172 pinned tables

namespace dm {

// ----------------------------------------------------------------------------
// Morale (DMG p.67-68)
//
// 2d10 roll vs base score, modified by situation:
//   + ally fled            (only when checking because ally fled: the
//                            fleeing is the trigger, not also a bonus)
// Situational modifiers applied to the TARGET (the base score):
//   outnumbered            +2 to base (harder to break when you have
//                            numbers? No - DMG: roll is against the
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
// R117: encounter reactions (DMG p.64) - the book's
// percentile table, seven bands, replacing R8's 2d6
// stand-in (its verification debt is paid here)
// ----------------------------------------------------------------------------

Reaction reactionForScore(int adjustedScore) {
    if (adjustedScore <= 5)  return REACTION_VIOLENT;       // 01-05
    if (adjustedScore <= 25) return REACTION_HOSTILE;        // 06-25
    if (adjustedScore <= 45) return REACTION_UNCERTAIN_NEG;  // 26-45
    if (adjustedScore <= 55) return REACTION_NEUTRAL;        // 46-55
    if (adjustedScore <= 75) return REACTION_UNCERTAIN_POS;  // 56-75
    if (adjustedScore <= 95) return REACTION_FRIENDLY;       // 76-95
    return REACTION_ENTHUSIASTIC;                            // 96+
}

Reaction rollReaction(Dice& dice, int chaReactionAdj) {
    return reactionForScore((int)dice.d100() + chaReactionAdj);
}

bool reactionAttacks(Reaction r) {
    // 01-05 violently hostile ("immediate attack") and
    // 06-25 hostile ("immediate action") - the starred
    // bands; the rest is parley (DMG p.64)
    return r == REACTION_VIOLENT || r == REACTION_HOSTILE;
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
    // R124: the book's TABLE III.A (p.170), pinned in
    // appendixa.h: 1-12 10', 13-16 20', 17 30', 18 5',
    // 19-20 SPECIAL (III.B). Feet to 10' tiles, clamped
    // 1-3 for the walk: 5' is half a tile; the 40'-60'
    // special passages with columns, streams, rivers and
    // chasms are pinned data for a future terrain
    // layer - the walk keeps corridor carving.
    int ft = appendixa::passageWidthFeetFor((int)dice.d20());
    if (ft < 0) ft = 40;   // special -> III.B's floor
    int tiles = (ft + 9) / 10;
    if (tiles > 3) tiles = 3;
    return tiles;
}

PassageFeature rollPassageFeature(Dice& dice) {
    // R124: the book's TABLE I (p.170), pinned in
    // appendixa.h, mapped to the walk's carveable
    // outcomes: a door (3-5) opens onto parallel space
    // the walk does not render - straight; stairs (17)
    // end the passage; a trick/trap (19) is pinned data
    // (TABLE VII.), not a carve; a wandering monster
    // (20) is an encounter cadence, not a feature.
    switch (appendixa::passageCheckFor((int)dice.d20())) {
        case appendixa::PC_SIDE:     return PASSAGE_T_JUNCTION;
        case appendixa::PC_TURN:     return PASSAGE_TURN;
        case appendixa::PC_CHAMBER:  return PASSAGE_CHAMBER;
        case appendixa::PC_STAIRS:
        case appendixa::PC_DEAD_END: return PASSAGE_DEAD_END;
        default: break;
    }
    return PASSAGE_STRAIGHT;
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
    // R124: the book's TABLE V (p.171), the room column,
    // pinned in appendixa.h: 10'x10' .. 30'x40' in feet
    // -> 10' tiles. The book prints the room column blank
    // at 18-20 (the unusual shape/size sub-tables are
    // chamber-only) - re-roll. The chamber column is
    // pinned data for the future layer.
    appendixa::SpaceShape s;
    while (!appendixa::roomShapeFor((int)dice.d20(), s)) {}
    w = s.wFt / 10;
    h = s.hFt / 10;
    if (w < 1) w = 1;
    if (h < 1) h = 1;
}

RoomContents rollRoomContents(Dice& dice) {
    // R124: the book's TABLE V.F (p.171), pinned in
    // appendixa.h: 1-12 empty, 13-14 monster, 15-17
    // monster and treasure, 18 special, 19 trick/trap,
    // 20 treasure.
    return appendixa::roomContentsFor((int)dice.d20());
}

} // namespace dm