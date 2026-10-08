// ====================================================================
// Adnd1 - rules/miscprose6.h
// R262: the III.E misc magic explanation prose part 6
// (DMG p.132) - Crystal Ball and Crystal Hypnosis
// Ball, part2 lines 222-283 (global = 11065 + part2
// line). ONE page header strips (279, the TREASURE
// page). The slice is table-dense: the locating
// chance table, the viewing period table, the
// additional powers table and the notice-by-class
// table all pin. 45 accessors: 36 scalars + 9
// array walkers, no name collisions with
// miscprose1.h through miscprose5.h. The slice
// completes kMisc2 rows 11-12; the double
// asterisk sits on row 11 (Crystal Ball 56-60) -
// the R226 pin is correct. The Crystal Hypnosis
// Ball is prose-only: three influencer kinds,
// three fates, referee picks the pace.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int mmpCrystalBallDiameterInches() {
    // a crystal sphere, half a foot across
    return 6;
}

inline int mmpCrystalBallLocatingRowCount() {
    // the subject-is table rows
    return 8;
}

inline int mmpCrystalBallLocatingWellKnownPct() {
    // personally well known
    return 100;
}

inline int mmpCrystalBallLocatingKnownSlightlyPct() {
    // personally known slightly
    return 85;
}

inline int mmpCrystalBallLocatingPicturedPct() {
    // pictured
    return 50;
}

inline int mmpCrystalBallLocatingPartPct() {
    // part of in possession
    return 50;
}

inline int mmpCrystalBallLocatingGarmentPct() {
    // garment in possession
    return 25;
}

inline int mmpCrystalBallLocatingWellInformedPct() {
    // well informed of
    return 25;
}

inline int mmpCrystalBallLocatingSlightlyInformedPct() {
    // slightly informed of
    return 20;
}

inline int mmpCrystalBallLocatingOtherPlanePct() {
    // on another plane: a minus
    return -25;
}

inline int mmpCrystalBallViewingRowCount() {
    // the viewing period table rows
    return 6;
}

inline int mmpCrystalBallOverrunIntLoss() {
    // past the limits, failed save: int down
    return 1;
}

inline int mmpCrystalBallOverrunInsaneUntilHealed() {
    // driven insane until healed
    return 1;
}

inline int mmpCrystalBallImprovingSpellCount() {
    // comprehend languages, read magic,
    // infravision, tongues
    return 4;
}

inline int mmpCrystalBallCastThroughSpellCount() {
    // detect magic, detect evil per good
    return 2;
}

inline int mmpCrystalBallCastThroughChancePerLevelPct() {
    // cast through the ball, per level
    return 5;
}

inline int mmpCrystalBallFeatureRowCount() {
    // the additional powers table rows
    return 4;
}

inline int mmpCrystalBallSpellFunctionLevel() {
    // the spell function operates at
    return 10;
}

inline int mmpCrystalBallNoticeMinInt() {
    // creatures of int 12 or better notice
    return 12;
}

inline int mmpCrystalBallDetectClassCount() {
    // the notice-by-class table entries
    return 7;
}

inline int mmpCrystalBallIntFactorCount() {
    // int 13 through 18, one rung each
    return 6;
}

inline int mmpCrystalBallDetectPerLevelPct() {
    // cumulative chance per level of experience
    return 1;
}

inline int mmpCrystalBallDetectionTablePage() {
    // spell-users: the detection table page
    return 60;
}

inline int mmpCrystalBallDispelDownDays() {
    // dispel magic: ceases functioning for
    return 1;
}

inline int mmpCrystalBallCheckPerRound() {
    // scrying detection checks each round
    return 1;
}

inline int mmpCrystalBallSpellUserClassCount() {
    // cleric, druid, magic-user, illusionist
    return 4;
}

inline int mmpCrystalBallClericDevicesAllowed() {
    // the note: clerics and druids may scry
    return 1;
}

inline int mmpCrystalBallKnowledgeNotDistance() {
    // knowledge is the key, not distance
    return 1;
}

inline int mmpCrystalBallTelepathyCommunicationOnly() {
    // the telepathy ball footnote
    return 1;
}

inline int mmpHypnosisBallCursed() {
    // the cursed item type
    return 1;
}

inline int mmpHypnosisBallRadiatesEvil() {
    // radiates magic, but NOT evil
    return 0;
}

inline int mmpHypnosisBallSuggestionImplanted() {
    // hypnotized, telepathic suggestion implanted
    return 1;
}

inline int mmpHypnosisBallIndistinguishable() {
    // indistinguishable from a normal ball
    return 1;
}

inline int mmpHypnosisBallInfluencerKindCount() {
    // magic-user, lich, other-planar power
    return 3;
}

inline int mmpHypnosisBallFateCount() {
    // servant, tool, or possession object
    return 3;
}

inline int mmpHypnosisBallRefereePace() {
    // gradual or sudden, referee decides
    return 1;
}

inline int mmpCrystalBallLocatingPct(int i) {
    // the locating chance; i clamps
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    static const int t[8] = {
        100, 85, 50, 50, 25, 25, 20, -25,
    };
    return t[i];
}

inline int mmpCrystalBallViewingMinutes(int i) {
    // the viewing period, in minutes; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        60, 30, 30, 30, 15, 10,
    };
    return t[i];
}

inline int mmpCrystalBallViewingTimesPerDay(int i) {
    // the daily frequency; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 3, 2, 1, 1, 1,
    };
    return t[i];
}

inline int mmpCrystalBallViewingBandHiPct(int i) {
    // the band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        100, 99, 89, 74, 49, 24,
    };
    return t[i];
}

inline int mmpCrystalBallFeatureBandLo(int i) {
    // the additional powers band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 51, 76, 91,
    };
    return t[i];
}

inline int mmpCrystalBallFeatureBandHi(int i) {
    // the band upper edges, 91-00 is 100; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        50, 75, 90, 100,
    };
    return t[i];
}

inline int mmpCrystalBallFeatureCountAt(int i) {
    // the additional feature count per band; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        0, 1, 2, 3,
    };
    return t[i];
}

inline int mmpCrystalBallDetectBasePct(int i) {
    // Fighter, Thief, Paladin, Assassin, Ranger,
    // Monk, Bard - the printed table order; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        2, 6, 6, 5, 4, 1, 3,
    };
    return t[i];
}

inline int mmpCrystalBallIntFactorPct(int i) {
    // the cumulative int ladder at int 13-18; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 3, 6, 10, 15, 21,
    };
    return t[i];
}

} // namespace rules