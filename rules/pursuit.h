// ====================================================================
// Adnd1 - rules/pursuit.h
// R206: pursuit and evasion of pursuit (DMG
// pp.67-69) - the underground and outdoor
// pursuit machinery. A seam with no prior
// coverage: no rules/ file and no gap-report
// mention.
//
// Pure data + helpers, header-only (the
// grenade.h pattern: the caller owns the
// map, the movement phases and the weekly
// clock; the rolls and bands read here).
// Conventions, named in place:
//   - PURSUED_FASTER / EQUAL_SPEED /
//     PURSUER_FASTER name the relative-speed
//     cases; the end-condition helpers read
//     the printed thresholds.
//   - The distractions run 10-100 percent
//     and are the caller adjudication
//     (the print says so); the FOOD and
//     TREASURE sub-cases carry their own
//     arithmetic here.
//   - Outdoor evasion: the base 80 percent
//     plus the four adjustment groups; the
//     caller sums the group picks and rolls
//     d100 against the total, hourly, and 0
//     or less is immediate confrontation.
//   - JUDGMENTs: the pursued-count and
//     pursuer-count adjustments are
//     independent rows (the print lists them
//     side by side); intelligence thresholds
//     follow the print (semi-intelligent or
//     under; low; average or greater).
// ====================================================================

#pragma once

namespace rules {

// -----------------------------------------------------------------------
// Underground: will pursuit occur?
// -----------------------------------------------------------------------

// Case 2: semi-intelligent or under, and
// hungry, angry, aggressive or trained -
// 80 percent likely.
inline int pursueLikelihoodMotivatedSemi() {
    return 80;
}

// Case 3: low intelligence (otherwise
// qualifying) - by party vs pursuer
// numbers: outnumbers 20, about equal 40,
// outnumbered 80, and 100 when the
// outnumbering pursuers feel greatly
// superior.
inline int pursueLikelihoodLowInt(
        bool partyOutnumbers,
        bool partiesAboutEqual,
        bool pursuersFeelSuperior) {
    if (partyOutnumbers) return 20;
    if (partiesAboutEqual) return 40;
    if (pursuersFeelSuperior) return 100;
    return 80;
}

// -----------------------------------------------------------------------
// The relative-speed cases
// -----------------------------------------------------------------------

enum PursuitSpeed {
    PURS_PURSUED_FASTER = 0,
    PURS_EQUAL_SPEED,
    PURS_PURSUER_FASTER,
};

// Pursuit ends when the pursued are in
// sight but beyond the sight distance, or
// out of sight and were beyond the
// out-of-sight distance when lost, or the
// pursuit has run past the round cap
// without a perceptible gain (the pursuer-
// faster case has no round cap: only the
// distances and endurance).
inline int pursuitEndSightFeet(PursuitSpeed s) {
    static const int k[3] = { 100, 150, 0 };
    if (s < PURS_PURSUED_FASTER) s = PURS_PURSUED_FASTER;
    if (s > PURS_PURSUER_FASTER) s = PURS_PURSUER_FASTER;
    return k[s];
}

inline int pursuitEndOutOfSightFeet(PursuitSpeed s) {
    static const int k[3] = { 50, 80, 200 };
    if (s < PURS_PURSUED_FASTER) s = PURS_PURSUED_FASTER;
    if (s > PURS_PURSUER_FASTER) s = PURS_PURSUER_FASTER;
    return k[s];
}

// The round cap: 5 rounds when the pursued
// are faster, 1 turn (10 rounds) at equal
// speed, no cap when the pursuer is faster
// (-1).
inline int pursuitEndRoundCap(PursuitSpeed s) {
    static const int k[3] = { 5, 10, -1 };
    if (s < PURS_PURSUED_FASTER) s = PURS_PURSUED_FASTER;
    if (s > PURS_PURSUER_FASTER) s = PURS_PURSUER_FASTER;
    return k[s];
}

// Does pursuit end this moment? (in sight,
// beyond the sight distance; out of sight
// and lost beyond the out-of-sight
// distance; past the round cap without a
// perceptible gain)
inline bool pursuitEnds(PursuitSpeed s,
                        bool inSight, int feetApart,
                        bool outOfSight,
                        int feetWhenLost,
                        int roundsRun,
                        bool gainedPerceptibly) {
    if (inSight && feetApart > pursuitEndSightFeet(s))
        return true;
    if (outOfSight
            && feetWhenLost > pursuitEndOutOfSightFeet(s))
        return true;
    int cap = pursuitEndRoundCap(s);
    if (cap > 0 && roundsRun > cap && !gainedPerceptibly)
        return true;
    return false;
}

// -----------------------------------------------------------------------
// The movement procedure (underground):
// the pursued move in tens of feet by
// their slowest member, the pursuers by
// their fastest; 3 movement phases = 1
// round; contact at 10 feet or less forces
// confrontation.
// -----------------------------------------------------------------------
inline int pursuitPhasesPerRound() { return 3; }
inline int pursuitConfrontFeet() { return 10; }

// -----------------------------------------------------------------------
// The FOOD distraction: d10 base, +10
// percent per intelligence point below 5,
// 100 percent for non-intelligent; under
// 100 a second d10 at or under the
// probability breaks pursuit for 1 round.
// -----------------------------------------------------------------------
inline int foodDistractionPercent(int d10, int intelligence) {
    if (intelligence <= 0) return 100;
    int pct = d10 * 10;
    if (intelligence < 5) pct += 10 * (5 - intelligence);
    if (pct > 100) pct = 100;
    return pct;
}

inline bool foodDistractionSucceeds(int percent,
                                    int secondD10) {
    if (percent >= 100) return true;
    return secondD10 * 10 <= percent;
}

inline int foodDistractionBreakRounds() { return 1; }

// -----------------------------------------------------------------------
// The TREASURE distraction: +10 percent per
// 10 items dropped for low intelligence;
// +10 percent per 100 gp of value (known,
// presumed or potential) for average or
// greater; distracted 1 round or the
// gather time, whichever greater - the
// gather time is caller-side.
// -----------------------------------------------------------------------
inline int treasureDistractionLowInt(
        int basePercent, int itemsDropped) {
    int pct = basePercent + 10 * (itemsDropped / 10);
    if (pct > 100) pct = 100;
    return pct;
}

inline int treasureDistractionValueBonus(
        int gpValue) {
    return 10 * (gpValue / 100);
}

// -----------------------------------------------------------------------
// The multiple-choice rule: at a 3-way
// branch 2 in 3 wrong; a door and a
// passage 1 in 2. The detection clues:
// straight-line sight is near infinite, a
// corner cuts it to 60 feet; metal armor
// hears at 90 feet, hard boots 60, quiet
// movement 30; scent persists for hours.
// -----------------------------------------------------------------------
inline int pursuitWrongChoiceWays(int ways) {
    return ways - 1;
}

inline int pursuitCornerSightFeet() { return 60; }
inline int pursuitHearingMetalFeet() { return 90; }
inline int pursuitHearingBootsFeet() { return 60; }
inline int pursuitHearingQuietFeet() { return 30; }

// -----------------------------------------------------------------------
// Outdoor: the BASE CHANCE OF EVADING
// PURSUIT OUTDOORS - base 80 percent with
// the four adjustment groups.
// -----------------------------------------------------------------------

inline int evadeOutdoorBase() { return 80; }

// Speed: pursued faster +10, equal 0,
// pursuer faster -20.
inline int evadeOutdoorSpeedAdj(PursuitSpeed s) {
    static const int k[3] = { 10, 0, -20 };
    if (s < PURS_PURSUED_FASTER) s = PURS_PURSUED_FASTER;
    if (s > PURS_PURSUER_FASTER) s = PURS_PURSUER_FASTER;
    return k[s];
}

// Terrain: plain, desert, open water -50;
// scrub, rough, hills, marsh +10; forest,
// mountains +30.
enum EvadeTerrain { EVT_PLAIN_DESERT_WATER = 0,
                    EVT_SCRUB_ROUGH_HILLS_MARSH,
                    EVT_FOREST_MOUNTAINS };

inline int evadeOutdoorTerrainAdj(EvadeTerrain t) {
    static const int k[3] = { -50, 10, 30 };
    if (t < EVT_PLAIN_DESERT_WATER) t = EVT_PLAIN_DESERT_WATER;
    if (t > EVT_FOREST_MOUNTAINS) t = EVT_FOREST_MOUNTAINS;
    return k[t];
}

// Size: the pursued party fewer than 6
// +10; 6-11 0; 12-50 -20; over 50 -50.
// The pursuing party: fewer than 12 -20;
// 12-24 0; over 24 +10.
inline int evadeOutdoorPursuedSizeAdj(int pursuedCount) {
    if (pursuedCount < 6) return 10;
    if (pursuedCount <= 11) return 0;
    if (pursuedCount <= 50) return -20;
    return -50;
}

inline int evadeOutdoorPursuerSizeAdj(int pursuerCount) {
    if (pursuerCount < 12) return -20;
    if (pursuerCount <= 24) return 0;
    return 10;
}

// Light: full daylight -30; twilight -10;
// bright moonlight 0; starlight +20; dark
// night +50.
enum EvadeLight { EVL_FULL_DAYLIGHT = 0, EVL_TWILIGHT,
                  EVL_BRIGHT_MOONLIGHT, EVL_STARLIGHT,
                  EVL_DARK_NIGHT };

inline int evadeOutdoorLightAdj(EvadeLight l) {
    static const int k[5] = { -30, -10, 0, 20, 50 };
    if (l < EVL_FULL_DAYLIGHT) l = EVL_FULL_DAYLIGHT;
    if (l > EVL_DARK_NIGHT) l = EVL_DARK_NIGHT;
    return k[l];
}

// The assembled outdoor evasion chance:
// base + speed + terrain + pursued size +
// pursuer size + light. The pursued roll
// d100 at or under to evade, hourly; a
// chance of 0 or less is immediate
// confrontation with no further evasion.
inline int evadeOutdoorChance(PursuitSpeed s,
                              EvadeTerrain t,
                              int pursuedCount,
                              int pursuerCount,
                              EvadeLight l) {
    int c = evadeOutdoorBase()
          + evadeOutdoorSpeedAdj(s)
          + evadeOutdoorTerrainAdj(t)
          + evadeOutdoorPursuedSizeAdj(pursuedCount)
          + evadeOutdoorPursuerSizeAdj(pursuerCount)
          + evadeOutdoorLightAdj(l);
    return c;
}

// -----------------------------------------------------------------------
// The outdoor surprise rule: a party that
// surprised the encountered evades
// automatically; a surprised party cannot
// evade at all.
// -----------------------------------------------------------------------
inline bool evadeAutoOnSurprise(bool partySurprisedThem) {
    return partySurprisedThem;
}

inline bool evadePossibleWhenSurprised(bool partyIsSurprised) {
    return !partyIsSurprised;
}

// The hourly recheck: 0 or less means
// immediate confrontation.
inline bool evadeOutdoorConfronts(int chance) {
    return chance <= 0;
}

} // namespace rules
