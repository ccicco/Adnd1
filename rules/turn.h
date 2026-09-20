// ============================================================================
// Adnd1 — rules/turn.h
// Time and the segment scheduler.
//
// Source: Dungeon Masters Guide (2012 Premium reprint):
//   - Time: DMG p.39 (round = 10 segments, 6 seconds each;
//     turn = 10 rounds)
//   - Surprise: DMG p.62 (2d6 table), PHB p.9-11 DEX reaction adj
//   - Initiative: DMG p.62-63 (d6 per side, high wins, tie = simul)
//   - Movement: 12"/turn base (= 120 feet outdoor, 120' dungeon scale
//     per turn; 1" = 10' dungeon, 10 yards outdoor per original
//     tranche 38 convention)
//   - Casting times, missile rate of fire: PHB spell + items tables
//     (hooks — values arrive with items/spells layers)
//
// The scheduler is a time-ordered event queue: an actor declares an
// action, the action resolves at its segment. The DMG p.71 Example of
// Melee golden test replays through this file.
// ============================================================================

#pragma once

#include "dice.h"

#include <cstdint>
#include <vector>

namespace rules {

// ----------------------------------------------------------------------------
// Time model
// ----------------------------------------------------------------------------
static const int SEGMENTS_PER_ROUND = 10;
static const int ROUNDS_PER_TURN    = 10;

// ----------------------------------------------------------------------------
// Surprise (DMG p.62): 2d6 vs the table.
//   2    : surprised 3 segments (ambush-ish)
//   3-5  : surprised 2 segments
//   6-7  : surprised 1 segment
//   8-12 : not surprised
// Each side rolls separately. DEX reaction adjustment (R3) applies to
// the die roll of the surprised side (better DEX = less surprise).
// ----------------------------------------------------------------------------
int surpriseSegments(Dice& dice, int dexReactionAdj);

// Surprise roll for both sides at once: returns segments each side
// loses. A side that is surprised while the other is not acts last.
void rollSurprise(Dice& dice, int dexAdjA, int dexAdjB,
                  int& segsA, int& segsB);

// ----------------------------------------------------------------------------
// Initiative (DMG p.62-63): each side rolls d6, high wins, tie means
// simultaneous resolution. Returns 0 on tie, 1 if A wins, -1 if B wins.
// DEX reaction adj does NOT modify initiative in 1e.
// ----------------------------------------------------------------------------
int rollInitiative(Dice& dice);   // one side's d6
int initiativeWinner(int rollA, int rollB);   // 1 / -1 / 0(tie)

// ----------------------------------------------------------------------------
// Movement (tranche 38 convention): base unencumbered 120' per turn =
// 12' per round = 1.2' per segment (indoor scale). Encoded as tenths
// of feet per segment to stay integer.
// ----------------------------------------------------------------------------
static const int BASE_MOVE_PER_TURN_FT   = 120;
static const int BASE_MOVE_PER_ROUND_FT   = 12;
static const int BASE_MOVE_PER_SEGMENT_TENTHS = 12;   // 1.2'

// feet moved in the given segments at the base rate (integer tenths
// -> feet truncation is fine for tile purposes)
int moveFeetInSegments(int segments);

// ----------------------------------------------------------------------------
// Action types and their segment costs (hooks for items/spells layers
// to refine with per-weapon/per-spell values)
// ----------------------------------------------------------------------------
enum ActionType : int {
    ACTION_MELEE = 0,     // resolves on initiative segment
    ACTION_MISSILE,       // per rate of fire; default 2/round at
                          // segments initiative, initiative+5
    ACTION_SPELL,         // initiative segment + casting time
    ACTION_DRINK,         // potion: takes effect end of round
    ACTION_TURN_UNDEAD,   // resolves at initiative segment
    ACTION_RETREAT,       // withdraw: full move, no attack
    ACTION_CHARGE,        // move + attack, arrives segment 5 (base)
    ACTION_SET_VS_CHARGE, // set weapon: ready at segment 1
    ACTION_COUNT
};

struct Action {
    ActionType type = ACTION_MELEE;
    int segment     = 0;      // computed resolve segment
    int castingTime = 0;      // spells (segments)
    int rateOfFire  = 2;      // missiles per round (default bow 2)
    int actorId     = 0;      // caller-assigned
};

// Compute the resolve segment(s) for an action.
//   initiativeSegment: the side's initiative-derived base segment
//     (winner acts first; convention: initiative roll result maps to
//     a segment via initiativeToSegment)
// Returns the primary resolve segment in Action.segment; missiles
// with rateOfFire place follow-up shots at +5 segments (caller loops).
Action& scheduleAction(Action& a, int initiativeSegment);

// Map a side's initiative d6 result to a base segment (1e convention:
// higher initiative = earlier; segment = 7 - d6, so a 6 acts at
// segment 1 and a 1 acts at segment 6; both sides on the same segment
// when tied).
int initiativeToSegment(int d6);

// ----------------------------------------------------------------------------
// Event queue: a round's actions resolved in segment order.
// ----------------------------------------------------------------------------
struct TurnEvent {
    int      segment;
    int      actorId;
    Action   action;
};

class RoundScheduler {
public:
    // queue an action (segment computed by scheduleAction)
    void submit(const Action& a, int initiativeSegment);

    // sort queued events by segment; stable for equal segments
    // (submission order preserved — declaration order tiebreak)
    void beginRound();

    // pop events in segment order; false when the round is empty
    bool next(TurnEvent& out);

    // events remaining (for tests)
    size_t pending() const { return m_queue.size(); }

private:
    std::vector<TurnEvent> m_queue;
    size_t                 m_pos = 0;
    bool                   m_sorted = false;
};

// ----------------------------------------------------------------------------
// Multiple attacks (DMG p.39, PHB fighter notes): fighters (and
// monsters with multiple attack routines) act on both initiative and
// initiative+5 segments by convention. High-level fighters (level 8+
// per original notes) gain a second melee routine.
// ----------------------------------------------------------------------------
int meleeAttacksPerRound(int classIndex, int level);

// Missile rate of fire default by weapon class (refined by items
// layer): bow 2/round, crossbow 1/round, other 1/round.
int defaultRateOfFire(int isBow);

} // namespace rules