// R-refactor: re-split from miscmagic_alchemy_jug_to_wings_of_flying.cpp - definitions
#include "rules/dmg/misc_magic/crystal_balls.h"

int Miscmagic_crystal_balls::mmpCrystalBallDiameterInches() {
    // a crystal sphere, half a foot across
    return 6;
}

int Miscmagic_crystal_balls::mmpCrystalBallLocatingRowCount() {
    // the subject-is table rows
    return 8;
}

int Miscmagic_crystal_balls::mmpCrystalBallLocatingWellKnownPct() {
    // personally well known
    return 100;
}

int Miscmagic_crystal_balls::mmpCrystalBallLocatingKnownSlightlyPct() {
    // personally known slightly
    return 85;
}

int Miscmagic_crystal_balls::mmpCrystalBallLocatingPicturedPct() {
    // pictured
    return 50;
}

int Miscmagic_crystal_balls::mmpCrystalBallLocatingPartPct() {
    // part of in possession
    return 50;
}

int Miscmagic_crystal_balls::mmpCrystalBallLocatingGarmentPct() {
    // garment in possession
    return 25;
}

int Miscmagic_crystal_balls::mmpCrystalBallLocatingWellInformedPct() {
    // well informed of
    return 25;
}

int Miscmagic_crystal_balls::mmpCrystalBallLocatingSlightlyInformedPct() {
    // slightly informed of
    return 20;
}

int Miscmagic_crystal_balls::mmpCrystalBallLocatingOtherPlanePct() {
    // on another plane: a minus
    return -25;
}

int Miscmagic_crystal_balls::mmpCrystalBallViewingRowCount() {
    // the viewing period table rows
    return 6;
}

int Miscmagic_crystal_balls::mmpCrystalBallOverrunIntLoss() {
    // past the limits, failed save: int down
    return 1;
}

int Miscmagic_crystal_balls::mmpCrystalBallOverrunInsaneUntilHealed() {
    // driven insane until healed
    return 1;
}

int Miscmagic_crystal_balls::mmpCrystalBallImprovingSpellCount() {
    // comprehend languages, read magic,
    // infravision, tongues
    return 4;
}

int Miscmagic_crystal_balls::mmpCrystalBallCastThroughSpellCount() {
    // detect magic, detect evil per good
    return 2;
}

int Miscmagic_crystal_balls::mmpCrystalBallCastThroughChancePerLevelPct() {
    // cast through the ball, per level
    return 5;
}

int Miscmagic_crystal_balls::mmpCrystalBallFeatureRowCount() {
    // the additional powers table rows
    return 4;
}

int Miscmagic_crystal_balls::mmpCrystalBallSpellFunctionLevel() {
    // the spell function operates at
    return 10;
}

int Miscmagic_crystal_balls::mmpCrystalBallNoticeMinInt() {
    // creatures of int 12 or better notice
    return 12;
}

int Miscmagic_crystal_balls::mmpCrystalBallDetectClassCount() {
    // the notice-by-class table entries
    return 7;
}

int Miscmagic_crystal_balls::mmpCrystalBallIntFactorCount() {
    // int 13 through 18, one rung each
    return 6;
}

int Miscmagic_crystal_balls::mmpCrystalBallDetectPerLevelPct() {
    // cumulative chance per level of experience
    return 1;
}

int Miscmagic_crystal_balls::mmpCrystalBallDetectionTablePage() {
    // spell-users: the detection table page
    return 60;
}

int Miscmagic_crystal_balls::mmpCrystalBallDispelDownDays() {
    // dispel magic: ceases functioning for
    return 1;
}

int Miscmagic_crystal_balls::mmpCrystalBallCheckPerRound() {
    // scrying detection checks each round
    return 1;
}

int Miscmagic_crystal_balls::mmpCrystalBallSpellUserClassCount() {
    // cleric, druid, magic-user, illusionist
    return 4;
}

int Miscmagic_crystal_balls::mmpCrystalBallClericDevicesAllowed() {
    // the note: clerics and druids may scry
    return 1;
}

int Miscmagic_crystal_balls::mmpCrystalBallKnowledgeNotDistance() {
    // knowledge is the key, not distance
    return 1;
}

int Miscmagic_crystal_balls::mmpCrystalBallTelepathyCommunicationOnly() {
    // the telepathy ball footnote
    return 1;
}

int Miscmagic_crystal_balls::mmpHypnosisBallCursed() {
    // the cursed item type
    return 1;
}

int Miscmagic_crystal_balls::mmpHypnosisBallRadiatesEvil() {
    // radiates magic, but NOT evil
    return 0;
}

int Miscmagic_crystal_balls::mmpHypnosisBallSuggestionImplanted() {
    // hypnotized, telepathic suggestion implanted
    return 1;
}

int Miscmagic_crystal_balls::mmpHypnosisBallIndistinguishable() {
    // indistinguishable from a normal ball
    return 1;
}

int Miscmagic_crystal_balls::mmpHypnosisBallInfluencerKindCount() {
    // magic-user, lich, other-planar power
    return 3;
}

int Miscmagic_crystal_balls::mmpHypnosisBallFateCount() {
    // servant, tool, or possession object
    return 3;
}

int Miscmagic_crystal_balls::mmpHypnosisBallRefereePace() {
    // gradual or sudden, referee decides
    return 1;
}

int Miscmagic_crystal_balls::mmpCrystalBallLocatingPct(int i) {
    // the locating chance; i clamps
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    static const int t[8] = {
        100, 85, 50, 50, 25, 25, 20, -25,
    };
    return t[i];
}

int Miscmagic_crystal_balls::mmpCrystalBallViewingMinutes(int i) {
    // the viewing period, in minutes; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        60, 30, 30, 30, 15, 10,
    };
    return t[i];
}

int Miscmagic_crystal_balls::mmpCrystalBallViewingTimesPerDay(int i) {
    // the daily frequency; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 3, 2, 1, 1, 1,
    };
    return t[i];
}

int Miscmagic_crystal_balls::mmpCrystalBallViewingBandHiPct(int i) {
    // the band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        100, 99, 89, 74, 49, 24,
    };
    return t[i];
}

int Miscmagic_crystal_balls::mmpCrystalBallFeatureBandLo(int i) {
    // the additional powers band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 51, 76, 91,
    };
    return t[i];
}

int Miscmagic_crystal_balls::mmpCrystalBallFeatureBandHi(int i) {
    // the band upper edges, 91-00 is 100; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        50, 75, 90, 100,
    };
    return t[i];
}

int Miscmagic_crystal_balls::mmpCrystalBallFeatureCountAt(int i) {
    // the additional feature count per band; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        0, 1, 2, 3,
    };
    return t[i];
}

int Miscmagic_crystal_balls::mmpCrystalBallDetectBasePct(int i) {
    // Fighter, Thief, Paladin, Assassin, Ranger,
    // Monk, Bard - the printed table order; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        2, 6, 6, 5, 4, 1, 3,
    };
    return t[i];
}

int Miscmagic_crystal_balls::mmpCrystalBallIntFactorPct(int i) {
    // the cumulative int ladder at int 13-18; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 3, 6, 10, 15, 21,
    };
    return t[i];
}
