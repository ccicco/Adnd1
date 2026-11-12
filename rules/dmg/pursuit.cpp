// R-refactor: split from pursuit.h - definitions
#include "rules/dmg/pursuit.h"

int Pursuit::pursueLikelihoodMotivatedSemi() {
    return 80;
}

int Pursuit::pursueLikelihoodLowInt( bool partyOutnumbers, bool partiesAboutEqual, bool pursuersFeelSuperior) {
    if (partyOutnumbers) return 20;
    if (partiesAboutEqual) return 40;
    if (pursuersFeelSuperior) return 100;
    return 80;
}

int Pursuit::pursuitEndSightFeet(PursuitSpeed s) {
    static const int k[3] = { 100, 150, 0 };
    if (s < PURS_PURSUED_FASTER) s = PURS_PURSUED_FASTER;
    if (s > PURS_PURSUER_FASTER) s = PURS_PURSUER_FASTER;
    return k[s];
}

int Pursuit::pursuitEndOutOfSightFeet(PursuitSpeed s) {
    static const int k[3] = { 50, 80, 200 };
    if (s < PURS_PURSUED_FASTER) s = PURS_PURSUED_FASTER;
    if (s > PURS_PURSUER_FASTER) s = PURS_PURSUER_FASTER;
    return k[s];
}

int Pursuit::pursuitEndRoundCap(PursuitSpeed s) {
    static const int k[3] = { 5, 10, -1 };
    if (s < PURS_PURSUED_FASTER) s = PURS_PURSUED_FASTER;
    if (s > PURS_PURSUER_FASTER) s = PURS_PURSUER_FASTER;
    return k[s];
}

bool Pursuit::pursuitEnds(PursuitSpeed s, bool inSight, int feetApart, bool outOfSight, int feetWhenLost, int roundsRun, bool gainedPerceptibly) {
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

int Pursuit::pursuitPhasesPerRound() { return 3; }

int Pursuit::pursuitConfrontFeet() { return 10; }

int Pursuit::foodDistractionPercent(int d10, int intelligence) {
    if (intelligence <= 0) return 100;
    int pct = d10 * 10;
    if (intelligence < 5) pct += 10 * (5 - intelligence);
    if (pct > 100) pct = 100;
    return pct;
}

bool Pursuit::foodDistractionSucceeds(int percent, int secondD10) {
    if (percent >= 100) return true;
    return secondD10 * 10 <= percent;
}

int Pursuit::foodDistractionBreakRounds() { return 1; }

int Pursuit::treasureDistractionLowInt( int basePercent, int itemsDropped) {
    int pct = basePercent + 10 * (itemsDropped / 10);
    if (pct > 100) pct = 100;
    return pct;
}

int Pursuit::treasureDistractionValueBonus( int gpValue) {
    return 10 * (gpValue / 100);
}

int Pursuit::pursuitWrongChoiceWays(int ways) {
    return ways - 1;
}

int Pursuit::pursuitCornerSightFeet() { return 60; }

int Pursuit::pursuitHearingMetalFeet() { return 90; }

int Pursuit::pursuitHearingBootsFeet() { return 60; }

int Pursuit::pursuitHearingQuietFeet() { return 30; }

int Pursuit::evadeOutdoorBase() { return 80; }

int Pursuit::evadeOutdoorSpeedAdj(PursuitSpeed s) {
    static const int k[3] = { 10, 0, -20 };
    if (s < PURS_PURSUED_FASTER) s = PURS_PURSUED_FASTER;
    if (s > PURS_PURSUER_FASTER) s = PURS_PURSUER_FASTER;
    return k[s];
}

int Pursuit::evadeOutdoorTerrainAdj(EvadeTerrain t) {
    static const int k[3] = { -50, 10, 30 };
    if (t < EVT_PLAIN_DESERT_WATER) t = EVT_PLAIN_DESERT_WATER;
    if (t > EVT_FOREST_MOUNTAINS) t = EVT_FOREST_MOUNTAINS;
    return k[t];
}

int Pursuit::evadeOutdoorPursuedSizeAdj(int pursuedCount) {
    if (pursuedCount < 6) return 10;
    if (pursuedCount <= 11) return 0;
    if (pursuedCount <= 50) return -20;
    return -50;
}

int Pursuit::evadeOutdoorPursuerSizeAdj(int pursuerCount) {
    if (pursuerCount < 12) return -20;
    if (pursuerCount <= 24) return 0;
    return 10;
}

int Pursuit::evadeOutdoorLightAdj(EvadeLight l) {
    static const int k[5] = { -30, -10, 0, 20, 50 };
    if (l < EVL_FULL_DAYLIGHT) l = EVL_FULL_DAYLIGHT;
    if (l > EVL_DARK_NIGHT) l = EVL_DARK_NIGHT;
    return k[l];
}

int Pursuit::evadeOutdoorChance(PursuitSpeed s, EvadeTerrain t, int pursuedCount, int pursuerCount, EvadeLight l) {
    int c = evadeOutdoorBase()
          + evadeOutdoorSpeedAdj(s)
          + evadeOutdoorTerrainAdj(t)
          + evadeOutdoorPursuedSizeAdj(pursuedCount)
          + evadeOutdoorPursuerSizeAdj(pursuerCount)
          + evadeOutdoorLightAdj(l);
    return c;
}

bool Pursuit::evadeAutoOnSurprise(bool partySurprisedThem) {
    return partySurprisedThem;
}

bool Pursuit::evadePossibleWhenSurprised(bool partyIsSurprised) {
    return !partyIsSurprised;
}

bool Pursuit::evadeOutdoorConfronts(int chance) {
    return chance <= 0;
}
