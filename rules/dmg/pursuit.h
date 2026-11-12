// ====================================================================
// Adnd1 - rules/dmg/pursuit.h
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



// -----------------------------------------------------------------------
// The relative-speed cases
// -----------------------------------------------------------------------
enum PursuitSpeed {
    PURS_PURSUED_FASTER = 0,
    PURS_EQUAL_SPEED,
    PURS_PURSUER_FASTER,
};



// Terrain: plain, desert, open water -50;
// scrub, rough, hills, marsh +10; forest,
// mountains +30.
enum EvadeTerrain { EVT_PLAIN_DESERT_WATER = 0,
                    EVT_SCRUB_ROUGH_HILLS_MARSH,
                    EVT_FOREST_MOUNTAINS };



// Light: full daylight -30; twilight -10;
// bright moonlight 0; starlight +20; dark
// night +50.
enum EvadeLight { EVL_FULL_DAYLIGHT = 0, EVL_TWILIGHT,
                  EVL_BRIGHT_MOONLIGHT, EVL_STARLIGHT,
                  EVL_DARK_NIGHT };

// R-refactor: namespace rules -> class Pursuit (instance methods)
class Pursuit {
public:


// -----------------------------------------------------------------------
// Underground: will pursuit occur?
// -----------------------------------------------------------------------

// Case 2: semi-intelligent or under, and
// hungry, angry, aggressive or trained -
// 80 percent likely.
    int pursueLikelihoodMotivatedSemi();


// Case 3: low intelligence (otherwise
// qualifying) - by party vs pursuer
// numbers: outnumbers 20, about equal 40,
// outnumbered 80, and 100 when the
// outnumbering pursuers feel greatly
// superior.
    int pursueLikelihoodLowInt( bool partyOutnumbers, bool partiesAboutEqual, bool pursuersFeelSuperior);


// Pursuit ends when the pursued are in
// sight but beyond the sight distance, or
// out of sight and were beyond the
// out-of-sight distance when lost, or the
// pursuit has run past the round cap
// without a perceptible gain (the pursuer-
// faster case has no round cap: only the
// distances and endurance).
    int pursuitEndSightFeet(PursuitSpeed s);
    int pursuitEndOutOfSightFeet(PursuitSpeed s);


// The round cap: 5 rounds when the pursued
// are faster, 1 turn (10 rounds) at equal
// speed, no cap when the pursuer is faster
// (-1).
    int pursuitEndRoundCap(PursuitSpeed s);


// Does pursuit end this moment? (in sight,
// beyond the sight distance; out of sight
// and lost beyond the out-of-sight
// distance; past the round cap without a
// perceptible gain)
    bool pursuitEnds(PursuitSpeed s, bool inSight, int feetApart, bool outOfSight, int feetWhenLost, int roundsRun, bool gainedPerceptibly);


// -----------------------------------------------------------------------
// The movement procedure (underground):
// the pursued move in tens of feet by
// their slowest member, the pursuers by
// their fastest; 3 movement phases = 1
// round; contact at 10 feet or less forces
// confrontation.
// -----------------------------------------------------------------------
    int pursuitPhasesPerRound();
    int pursuitConfrontFeet();


// -----------------------------------------------------------------------
// The FOOD distraction: d10 base, +10
// percent per intelligence point below 5,
// 100 percent for non-intelligent; under
// 100 a second d10 at or under the
// probability breaks pursuit for 1 round.
// -----------------------------------------------------------------------
    int foodDistractionPercent(int d10, int intelligence);
    bool foodDistractionSucceeds(int percent, int secondD10);
    int foodDistractionBreakRounds();


// -----------------------------------------------------------------------
// The TREASURE distraction: +10 percent per
// 10 items dropped for low intelligence;
// +10 percent per 100 gp of value (known,
// presumed or potential) for average or
// greater; distracted 1 round or the
// gather time, whichever greater - the
// gather time is caller-side.
// -----------------------------------------------------------------------
    int treasureDistractionLowInt( int basePercent, int itemsDropped);
    int treasureDistractionValueBonus( int gpValue);


// -----------------------------------------------------------------------
// The multiple-choice rule: at a 3-way
// branch 2 in 3 wrong; a door and a
// passage 1 in 2. The detection clues:
// straight-line sight is near infinite, a
// corner cuts it to 60 feet; metal armor
// hears at 90 feet, hard boots 60, quiet
// movement 30; scent persists for hours.
// -----------------------------------------------------------------------
    int pursuitWrongChoiceWays(int ways);
    int pursuitCornerSightFeet();
    int pursuitHearingMetalFeet();
    int pursuitHearingBootsFeet();
    int pursuitHearingQuietFeet();


// -----------------------------------------------------------------------
// Outdoor: the BASE CHANCE OF EVADING
// PURSUIT OUTDOORS - base 80 percent with
// the four adjustment groups.
// -----------------------------------------------------------------------
    int evadeOutdoorBase();


// Speed: pursued faster +10, equal 0,
// pursuer faster -20.
    int evadeOutdoorSpeedAdj(PursuitSpeed s);
    int evadeOutdoorTerrainAdj(EvadeTerrain t);


// Size: the pursued party fewer than 6
// +10; 6-11 0; 12-50 -20; over 50 -50.
// The pursuing party: fewer than 12 -20;
// 12-24 0; over 24 +10.
    int evadeOutdoorPursuedSizeAdj(int pursuedCount);
    int evadeOutdoorPursuerSizeAdj(int pursuerCount);
    int evadeOutdoorLightAdj(EvadeLight l);


// The assembled outdoor evasion chance:
// base + speed + terrain + pursued size +
// pursuer size + light. The pursued roll
// d100 at or under to evade, hourly; a
// chance of 0 or less is immediate
// confrontation with no further evasion.
    int evadeOutdoorChance(PursuitSpeed s, EvadeTerrain t, int pursuedCount, int pursuerCount, EvadeLight l);


// -----------------------------------------------------------------------
// The outdoor surprise rule: a party that
// surprised the encountered evades
// automatically; a surprised party cannot
// evade at all.
// -----------------------------------------------------------------------
    bool evadeAutoOnSurprise(bool partySurprisedThem);
    bool evadePossibleWhenSurprised(bool partyIsSurprised);


// The hourly recheck: 0 or less means
// immediate confrontation.
    bool evadeOutdoorConfronts(int chance);
};
