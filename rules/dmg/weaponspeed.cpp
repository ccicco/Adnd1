// R-refactor: split from weaponspeed.h - definitions
#include "rules/dmg/weaponspeed.h"

int Weaponspeed::weaponSpeedFactor(const char* name) {
    static const struct { const char* n; int sf; } t[] = {
        { "fist",             1 },   // DMG p.66 example
        { "dagger",           2 },
        { "short sword",      3 },
        { "hammer",           4 },   // DMG p.66 example
        { "club",             4 },
        { "hand axe",         4 },
        { "quarterstaff",     4 },
        { "scimitar",         4 },
        { "long sword",       5 },   // DMG: broad or long
        { "broad sword",      5 },
        { "horseman mace",    6 },
        { "horseman flail",   6 },
        { "spear",            7 },   // print 6-8, default 7
        { "footman mace",     7 },
        { "footman flail",    7 },
        { "morning star",     7 },
        { "battle axe",       7 },
        { "two-handed sword", 10 },  // DMG p.64/p.66
        { "pike",             13 },  // the DMG p.66 example
        // R780: the three lances ride the ladder -
        // the PHB p.38 speed column cells (the medium
        // horse 6 outruns the light horse 7 - the print
        // is the print)
        { "lance, medium horse", 6 },
        { "lance, light horse",  7 },
        { "lance, heavy horse",  8 },
    };
    for (int i = 0; i < (int)(sizeof(t) / sizeof(t[0])); ++i)
        if (std::strcmp(name, t[i].n) == 0) return t[i].sf;
    return 0;   // unknown: caller decides
}

void Weaponspeed::spearSpeedFactorRange(int& lo, int& hi) {
    lo = 6; hi = 8;   // the printed 5-13+ foot length spread
}

int Weaponspeed::spearSpeedFactorByLengthFt(int lengthFt) {
    if (lengthFt <= 5) return 6;
    if (lengthFt >= 13) return 8;
    return 7;
}

int Weaponspeed::speedFactorFirst(int sfA, int sfB) {
    if (sfA < sfB) return -1;
    if (sfB < sfA) return 1;
    return 0;
}

int Weaponspeed::speedFactorAttacksBefore(int sfLow, int sfHigh) {
    int diff = sfHigh - sfLow;
    if (diff <= 0) return 1;
    if (diff >= 10) return 3;
    if (diff >= 2 * sfLow || diff >= 5) return 2;
    return 1;
}

bool Weaponspeed::speedFactorApplies(bool closingOrCharging) {
    return !closingOrCharging;   // the print exempts both
}

int Weaponspeed::weaponVsActivitySegment(int speedFactor, int losingInitiativeRoll) {
    int v = speedFactor - losingInitiativeRoll;
    if (v < 0) v = -v;
    return v;
}

int Weaponspeed::weaponVsActivityOrder(int strikeSegment, int activitySegments) {
    if (strikeSegment < activitySegments) return -1;
    if (strikeSegment > activitySegments) return 1;
    return 0;
}

bool Weaponspeed::speedFactorModifiedWhenSimultaneous() {
    return false;
}
