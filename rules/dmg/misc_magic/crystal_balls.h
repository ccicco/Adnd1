// ====================================================================
// Adnd1 - rules/dmg/misc_magic/crystal_balls.h
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
// ---- re-split from miscmagic_alchemy_jug_to_wings_of_flying.h (the R257-R279 merge) ----
// ====================================================================
#pragma once

class Miscmagic_crystal_balls {
public:
    int mmpCrystalBallDiameterInches();
    int mmpCrystalBallLocatingRowCount();
    int mmpCrystalBallLocatingWellKnownPct();
    int mmpCrystalBallLocatingKnownSlightlyPct();
    int mmpCrystalBallLocatingPicturedPct();
    int mmpCrystalBallLocatingPartPct();
    int mmpCrystalBallLocatingGarmentPct();
    int mmpCrystalBallLocatingWellInformedPct();
    int mmpCrystalBallLocatingSlightlyInformedPct();
    int mmpCrystalBallLocatingOtherPlanePct();
    int mmpCrystalBallViewingRowCount();
    int mmpCrystalBallOverrunIntLoss();
    int mmpCrystalBallOverrunInsaneUntilHealed();
    int mmpCrystalBallImprovingSpellCount();
    int mmpCrystalBallCastThroughSpellCount();
    int mmpCrystalBallCastThroughChancePerLevelPct();
    int mmpCrystalBallFeatureRowCount();
    int mmpCrystalBallSpellFunctionLevel();
    int mmpCrystalBallNoticeMinInt();
    int mmpCrystalBallDetectClassCount();
    int mmpCrystalBallIntFactorCount();
    int mmpCrystalBallDetectPerLevelPct();
    int mmpCrystalBallDetectionTablePage();
    int mmpCrystalBallDispelDownDays();
    int mmpCrystalBallCheckPerRound();
    int mmpCrystalBallSpellUserClassCount();
    int mmpCrystalBallClericDevicesAllowed();
    int mmpCrystalBallKnowledgeNotDistance();
    int mmpCrystalBallTelepathyCommunicationOnly();
    int mmpHypnosisBallCursed();
    int mmpHypnosisBallRadiatesEvil();
    int mmpHypnosisBallSuggestionImplanted();
    int mmpHypnosisBallIndistinguishable();
    int mmpHypnosisBallInfluencerKindCount();
    int mmpHypnosisBallFateCount();
    int mmpHypnosisBallRefereePace();
    int mmpCrystalBallLocatingPct(int i);
    int mmpCrystalBallViewingMinutes(int i);
    int mmpCrystalBallViewingTimesPerDay(int i);
    int mmpCrystalBallViewingBandHiPct(int i);
    int mmpCrystalBallFeatureBandLo(int i);
    int mmpCrystalBallFeatureBandHi(int i);
    int mmpCrystalBallFeatureCountAt(int i);
    int mmpCrystalBallDetectBasePct(int i);
    int mmpCrystalBallIntFactorPct(int i);
};
