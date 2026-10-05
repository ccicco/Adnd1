// ============================================================================
// Adnd1 - rules/turn.cpp
// Segment scheduler implementation.
// ============================================================================

#include "turn.h"
#include "attacksround.h"  // R181: the fighter-group print consults rules/attacksround.h

#include <algorithm>

namespace rules {

// ----------------------------------------------------------------------------
// Surprise (DMG p.62)
// ----------------------------------------------------------------------------

int surpriseSegments(Dice& dice, int dexReactionAdj) {
    int roll = (int)dice.roll(2, 6, 0) + dexReactionAdj;
    if (roll <= 2)  return 3;
    if (roll <= 5)  return 2;
    if (roll <= 7)  return 1;
    return 0;   // 8+: not surprised
}

void rollSurprise(Dice& dice, int dexAdjA, int dexAdjB,
                  int& segsA, int& segsB) {
    segsA = surpriseSegments(dice, dexAdjA);
    segsB = surpriseSegments(dice, dexAdjB);
}

// ----------------------------------------------------------------------------
// Initiative
// ----------------------------------------------------------------------------

int rollInitiative(Dice& dice) {
    return (int)dice.d6();
}

int initiativeWinner(int rollA, int rollB) {
    if (rollA > rollB) return 1;
    if (rollB > rollA) return -1;
    return 0;
}

int initiativeToSegment(int d6) {
    if (d6 < 1) d6 = 1;
    if (d6 > 6) d6 = 6;
    return 7 - d6;   // 6 -> seg 1 ... 1 -> seg 6
}

// ----------------------------------------------------------------------------
// Movement
// ----------------------------------------------------------------------------

int moveFeetInSegments(int segments) {
    if (segments <= 0) return 0;
    int tenths = segments * BASE_MOVE_PER_SEGMENT_TENTHS;
    return tenths / 10;   // 1.2'/segment -> feet (truncated)
}

// ----------------------------------------------------------------------------
// Scheduling
// ----------------------------------------------------------------------------

Action& scheduleAction(Action& a, int initiativeSegment) {
    switch (a.type) {
        case ACTION_MELEE:
        case ACTION_TURN_UNDEAD:
            a.segment = initiativeSegment;
            break;
        case ACTION_MISSILE:
            // first shot at initiative; follow-ups +5 segments
            a.segment = initiativeSegment;
            break;
        case ACTION_SPELL:
            a.segment = initiativeSegment + a.castingTime;
            if (a.segment > SEGMENTS_PER_ROUND)
                a.segment = SEGMENTS_PER_ROUND;   // spills next round
            break;
        case ACTION_DRINK:
            a.segment = SEGMENTS_PER_ROUND;   // end of round
            break;
        case ACTION_CHARGE:
            a.segment = 5;   // base: arrives and attacks mid-round
            break;
        case ACTION_SET_VS_CHARGE:
            a.segment = 1;   // weapon set immediately
            break;
        case ACTION_RETREAT:
            a.segment = initiativeSegment;
            break;
        default:
            a.segment = initiativeSegment;
    }
    return a;
}

// ----------------------------------------------------------------------------
// RoundScheduler
// ----------------------------------------------------------------------------

void RoundScheduler::submit(const Action& a, int initiativeSegment) {
    TurnEvent ev;
    ev.action = a;
    scheduleAction(ev.action, initiativeSegment);
    ev.segment  = ev.action.segment;
    ev.actorId  = a.actorId;
    m_queue.push_back(ev);
}

void RoundScheduler::beginRound() {
    // stable sort by segment: submission order breaks ties
    std::stable_sort(m_queue.begin(), m_queue.end(),
                     [](const TurnEvent& a, const TurnEvent& b) {
                         return a.segment < b.segment;
                     });
    m_pos = 0;
    m_sorted = true;
}

bool RoundScheduler::next(TurnEvent& out) {
    if (m_pos >= m_queue.size()) return false;
    out = m_queue[m_pos++];
    return true;
}

// ----------------------------------------------------------------------------
// Attack routines
// ----------------------------------------------------------------------------

int meleeAttacksPerRound(int classIndex, int level) {
    // R181 repin: the printed 3/2 band opens at 7th level
    // (the fighters, paladins and rangers attacks-per-melee-
    // round table). The engine round model carries two swing
    // slots (initiative and initiative+5), so this returns the
    // routine count of the HEAVY round of the printed cycle:
    // 1 below the 3/2 band, 2 in the 3/2 and 2/1 bands. The
    // full printed rates (and the ranger band edges, which
    // need the subclass id this base-class function does not
    // carry) live in rules/attacksround.h.
    if (classIndex == 0) {
        rules::AtkRate r = rules::fighterGroupAttacks(0, level);
        return (r.attacks >= 2) ? 2 : 1;
    }
    return 1;
}

int defaultRateOfFire(int isBow) {
    return isBow ? 2 : 1;
}

} // namespace rules