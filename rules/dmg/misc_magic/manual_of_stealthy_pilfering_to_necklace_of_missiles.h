// ====================================================================
// Adnd1 - rules/dmg/misc_magic/manual_of_stealthy_pilfering_to_necklace_of_missiles.h
// R274: the III.E misc magic explanation prose part 18
// (DMG p.150-151) - the Manual of Stealthy Pilfering, the
// Mattock and Maul of the Titans, the Medallions of ESP
// and Thought Projection, the Mirrors of Life Trapping,
// Mental Prowess and Opposition and the Necklaces of
// Adaptation and Missiles, part2 lines 843-900 (global
// = 11065 + part2 line), pinning the kMisc4 rows 9-18 of
// the 36-row III.E.4 table. ONE mid-sentence break inside
// the slice: the mirror of life trapping paragraph splits
// between not a (863) and factor (865), the upload
// prints no running head at the break - ONE
// seam restored this round; the slice rides the
// pp.150-151 attribution on the R273-established p.150
// base. The upload quirks this round: the necklace of
// missiles table is badly mangled (pipes misplaced,
// fragments pushed into the wrong cells) - the
// dash-separated count ladders reconstruct it exactly
// and cross-check against the printed example:
// one 7-dice, two 5-dice, four 3-dice (the 9-12 row);
// the stray apostrophe artifact after the word manual
// recurs in the pilfering paragraph (a like manual)
// beside a printed magic- users with a space (both
// pinned as the upload prints them,
// apostrophe-free here); the medallion table prints
// clean. 67
// accessors: 59 scalars + 8 walkers (the medallion die
// bands, ranges and empathy marks; the necklace die
// bands, hit dice columns and the flattened 70-cell
// count table), no name collisions with miscprose1.h
// through miscprose17.h. Pure data + helpers,
// header-only (the grenade.h pattern).
// ---- re-split from miscmagic_alchemy_jug_to_wings_of_flying.h (the R257-R279 merge) ----
// ====================================================================
#pragma once

class Miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles {
public:
    int mmpStealthyPracticeMonths();
    int mmpStealthyKnowledgeMonths();
    int mmpStealthyAssassinXp();
    int mmpStealthyAssassinWeeks();
    int mmpStealthyWrongDamageMin();
    int mmpStealthyWrongDamageMax();
    int mmpStealthyStunRoundsMin();
    int mmpStealthyStunRoundsMax();
    int mmpStealthyXpLossMin();
    int mmpStealthyXpLossMax();
    int mmpStealthyAtoneDays();
    int mmpStealthyWisdomLoss();
    int mmpMattockLengthFeet();
    int mmpMattockWeightLb();
    int mmpMattockMinStrength();
    int mmpMattockEarthCubicFeet();
    int mmpMattockRockCubicFeet();
    int mmpMattockAreaTurns();
    int mmpMattockHitBonus();
    int mmpMattockDamageMin();
    int mmpMattockDamageMax();
    int mmpMaulLengthFeet();
    int mmpMaulWeightLb();
    int mmpMaulMinStrength();
    int mmpMaulPileDiameterFeet();
    int mmpMaulPileDepthFeet();
    int mmpMaulBlowsPerRound();
    int mmpMaulDoorHeightFeet();
    int mmpMaulDoorWidthFeet();
    int mmpMaulDoorThicknessInches();
    int mmpMaulDoorBlows();
    int mmpMaulDoorIronBlows();
    int mmpMaulHitBonus();
    int mmpMaulDamageMin();
    int mmpMaulDamageMax();
    int mmpEspPathWidthFeet();
    int mmpEspBroadenFeet();
    int mmpEspBroadenPerFeet();
    int mmpEspMaxWidthFeet();
    int mmpEspMaxWidthAtFeet();
    int mmpEspUseRounds();
    int mmpEspStoneBlockFeet();
    int mmpEspMetalBlockSixthsFeet();
    int mmpEspMalfunctionRoll();
    int mmpEspMalfunctionDieSides();
    int mmpEspRowLo(int i);
    int mmpEspRowHi(int i);
    int mmpEspRangeFeet(int i);
    int mmpEspEmpathy(int i);
    int mmpProjectionWorksRoll();
    int mmpTrapAreaSquareFeet();
    int mmpTrapCellMin();
    int mmpTrapCellMax();
    int mmpTrapTriggerFeet();
    int mmpTrapSeePctUnaware();
    int mmpTrapSeePctAvoiding();
    int mmpTrapSeePctAware();
    int mmpTrapOverflowFreed();
    int mmpProwessQuestionsPerWeek();
    int mmpProwessWidthFeet();
    int mmpProwessHeightFeet();
    int mmpAdaptationAirlessDays();
    int mmpMissileRangeInches();
    int mmpNeckRowLo(int i);
    int mmpNeckRowHi(int i);
    int mmpNeckDieOf(int i);
    int mmpNeckCell(int i);
};
