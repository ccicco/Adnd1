// ===========================================================================
// Adnd1 - rules/comeliness.h
// The UA comeliness pins (R322 - the arc
// opener).
//
// UNEARTHED ARCANA CHARACTER ABILITIES: the
// seventh attribute, rolled 3d6 after the
// first six, modified by the charisma
// ladder and the viewed-race adjustment.
// Pinned data only - no engine site exists
// (no comeliness field; the reaction layer
// itself has no callers) - the R311 pin-era
// pattern: pin now, wire when a site exists.
// R400: the site exists now - the
// Character field, the creation roll
// and the parley-gate reaction
// callers read these pins. The
// fascinate power, the order roll and
// the illusion cap stay pinned data
// (they gate on a fascinate site).
//
// The charisma ladder: charisma moves
// comeliness point-for-point as it changes
// (disease, disfigurement, aging, artifacts).
// The racial adjustments apply only to
// viewers of ANOTHER race; the pairs treat
// as same race (halflings and humans;
// half-elves and sylvan elves; gray and
// high elves). The engine carries one elf
// race - the +1 sylvan read pins, the +2
// gray/high subrace grain stays recorded
// (no subrace layer).

#pragma once

#include "races.h"

namespace rules {

// The base roll: 3d6, after the six
// attributes
inline int uaComelinessBaseDieCount()
    { return 3; }
inline int uaComelinessBaseDieSides()
    { return 6; }

// The charisma adjustment ladder
inline int uaComelinessChaAdj(int cha) {
    // below 3: -8; 3: -5; 4-5: -3; 6-8:
    // -1; 9-12: 0; 13-15: +1; 16-17:
    // +2; 18: +3; above 18: +5
    if (cha < 3) return -8;
    if (cha == 3) return -5;
    if (cha <= 5) return -3;
    if (cha <= 8) return -1;
    if (cha <= 12) return 0;
    if (cha <= 15) return 1;
    if (cha <= 17) return 2;
    if (cha == 18) return 3;
    return 5;
}

// The viewed-race adjustment (the viewer
// of another race; the same-race pairs
// read 0)
inline int uaComelinessRacialAdj(
    CharRace viewed) {
    // half-orcs -3; dwarves and gnomes
    // -1; humans and halflings 0 (the
    // pair); half-elves +1; elves +1
    // (the sylvan read - the +2 gray/
    // high grain stays recorded)
    switch (viewed) {
    case RACE_HALF_ORC: return -3;
    case RACE_DWARF: return -1;
    case RACE_GNOME: return -1;
    case RACE_HUMAN: return 0;
    case RACE_HALFLING: return 0;
    case RACE_HALF_ELF: return 1;
    case RACE_ELF: return 1;
    default: return 0;
    }
}

// The reaction bands: 0 repulsed (16 or
// lower negative), 1 disgust (-15 to
// -9), 2 aversion (-8 to 0), 3 ugly
// (+1 to +6), 4 homely (+7 to +9),
// 5 plain (+10 to +13, no effect),
// 6 interest (+14 to +17), 7 beauty
// (+18 to +21), 8 stunning (+22 to
// +25), 9 unearthly (+26 to +30)
inline int uaComelinessBand(int c) {
    if (c <= -16) return 0;
    if (c <= -9) return 1;
    if (c <= 0) return 2;
    if (c <= 6) return 3;
    if (c <= 9) return 4;
    if (c <= 13) return 5;
    if (c <= 17) return 6;
    if (c <= 21) return 7;
    if (c <= 25) return 8;
    return 9;
}

// The initial-reaction multiplier (the
// percent of the comeliness score): 100
// at +14 to +17, 150 at +18 to +21,
// 200 at +22 and up; 0 = no multiplier
// printed (the band carries the effect)
inline int uaComelinessReactionPct(int c) {
    int b = uaComelinessBand(c);
    if (b == 6) return 100;
    if (b == 7) return 150;
    if (b >= 8) return 200;
    return 0;
}

// The fascinate wisdom floor: the wisdom
// at or above which the viewer resists.
// -1 = no fascinate power in the band.
// Opposite sex: 50 percent at 14-17,
// two-thirds at 18-21 and 22-25, 75
// percent at 26-30. Same sex: none at
// 14-17, 50 percent at 18-21,
// two-thirds at 22-25, 75 percent at
// 26-30.
inline int uaComelinessFascinateWisMin(
    int c, bool oppositeSex) {
    int b = uaComelinessBand(c);
    if (b < 6) return -1;
    if (b == 6)
        return oppositeSex ? c / 2 : -1;
    if (b == 7)
        return oppositeSex ? (c * 2) / 3
                            : c / 2;
    if (b == 8)
        return (c * 2) / 3;
    return (c * 3) / 4;
}

// The consciously-sought floor: an
// opposite-sex viewer the beauty actively
// seeks resists only at wisdom 18
// (stunning) or 20 (unearthly); 0 = the
// band carries no sought power
inline int uaComelinessSoughtWisMin(int c) {
    int b = uaComelinessBand(c);
    if (b == 8) return 18;
    if (b == 9) return 20;
    return 0;
}

// The unearthly save: wisdom 19 or
// higher always allows a saving throw
// versus the power; 0 = the band is
// below unearthly
inline int uaComelinessUnearthlySaveWis(
    int c) {
    return uaComelinessBand(c) == 9 ? 19 : 0;
}

// The illusion cap: change self and alter
// self move comeliness at most 1 point
inline int uaComelinessIllusionAdjustMax() {
    return 1;
}

// The order roll: a fascinated creature
// obeys while 3d6 does not exceed the
// comeliness of the character; requests
// not in the creatures best interest
// take +1, hazardous ones up to +6
inline int uaComelinessOrderDieCount()
    { return 3; }
inline int uaComelinessOrderDieSides()
    { return 6; }

// ---- R400: the site layer ----
//
// The score: the raw 3d6 base roll
// (0 = unknown, the v1-save read)
// plus the charisma ladder. The
// point-for-point coupling rides the
// CURRENT charisma - a cha change
// moves the score the same distance.
inline int uaComelinessScore(
    int baseRoll, int cha) {
    if (baseRoll <= 0) return 0;
    return baseRoll
        + uaComelinessChaAdj(cha);
}

// The viewed score for a viewer race:
// the same-race pairs read 0 (the
// print's halfling/human and
// sylvan-elf/half-elf pairs), every
// other viewer reads the viewed race's
// cell. (The print's dwarf example -
// base 9, cha 16 - reads 11; its own
// "at 8" cell is loose arithmetic.)
inline int uaComelinessEffective(
    int score, CharRace viewed,
    CharRace viewer) {
    if (score <= 0) return 0;
    if (viewed == viewer) return score;
    if ((viewed == RACE_HUMAN
         && viewer == RACE_HALFLING)
        || (viewed == RACE_HALFLING
            && viewer == RACE_HUMAN)
        || (viewed == RACE_HALF_ELF
            && viewer == RACE_ELF)
        || (viewed == RACE_ELF
            && viewer == RACE_HALF_ELF))
        return score;
    return score
        + uaComelinessRacialAdj(viewed);
}

// The monster-viewer read: the parley
// gate has no CharRace for the viewer,
// so the viewed-race adjustment always
// rides (a monster is of another race
// by the site convention).
inline int uaComelinessScoreOtherRace(
    int baseRoll, int cha,
    CharRace viewed) {
    int s = uaComelinessScore(baseRoll, cha);
    if (s <= 0) return 0;
    return s
        + uaComelinessRacialAdj(viewed);
}

// The initial-contact reaction
// adjustment: the percent of the
// VIEWED comeliness score - 100 at
// +14 to +17, 150 at +18 to +21, 200
// at +22 and up (the print: "22
// comeliness equals +44%"). The bands
// below interest carry no percentile -
// the band text carries the effect.
inline int uaComelinessReactionAdj(
    int viewedScore) {
    if (viewedScore <= 13) return 0;
    return viewedScore
        * uaComelinessReactionPct(
              viewedScore) / 100;
}

}
