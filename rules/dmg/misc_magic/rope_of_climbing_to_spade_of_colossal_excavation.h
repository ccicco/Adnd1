// ====================================================================
// Adnd1 - rules/dmg/misc_magic/rope_of_climbing_to_spade_of_colossal_excavation.h
// R278: the III.E misc magic explanation prose part 22
// (DMG p.154-156) - the Rope of Climbing, the Rope of
// Constriction, the Rope of Entanglement, the rope note,
// the Rug of Smothering, the Rug of Welcome, the Saw of
// Mighty Cutting, the Scarab of Death, the Scarab of
// Enraging Enemies, the Scarab of Insanity, the Scarab of
// Protection and the Spade of Colossal Excavation, part2
// lines 1054-1081 (global = 11065 + part2 line), pinning
// the kMisc5 rows 6-16 of the 35-row III.E.5 table - the
// eleven consecutive rows opening with the Rope of
// Climbing. This round has two seams restored: seam A
// splits the Constriction paragraph between the 1056 tail
// (delivers 2-12 hit) and the 1058 head (points of damage)
// across the single 1057 blank - the p.154-155 page break,
// no running head captured; seam B is the p.155-156 page
// break between the Insanity tail (1074) and the Protection
// head (1079) with the blank pair at 1075-1076, the
// TREASURE (MISCELLANEOUS MAGIC) running head at 1077 and
// the 1078 post-head blank. The upload quirks this round:
// the OCR splits spade- like with a space; the curly
// apostrophe prints in the victim possessive of the Scarab
// of Death; curly quotes wrap to hit in the enraging mods;
// the minus signs print true (minus 2, minus 3, minus 10
// percent, minus 2 saves); the foot and inch primes print
// as curly marks; the welcome rug carries a multiplication
// sign on its 6 x 9 flying size and the 1/12 shrink
// fraction; the rope note prints as a heading line - all
// pinned as plain digits and words, apostrophe-free here.
// The part1 quirks: the eleven slice rows print
// side-by-side with armor-table columns (part1 9881-9891);
// the Constriction, Smothering and Death rows print --- in
// the x.p. column; the Welcome, Saw and Spade rows carry
// the (M)/(F) marks. The Entanglement man-sized
// equivalence chain is pinned as the lone walker.
// 85 accessors: 84 scalars + 1 walker, no name collisions
// with miscprose1.h through miscprose21.h. Pure data +
// helpers, header-only (the grenade.h pattern).
// ---- re-split from miscmagic_alchemy_jug_to_wings_of_flying.h (the R257-R279 merge) ----
// ====================================================================
#pragma once

class Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation {
public:
    int mmpClimbLengthFeet();
    int mmpClimbWeightPounds();
    int mmpClimbSupportPounds();
    int mmpClimbSpeedFeetPerRound();
    int mmpClimbKnotIntervalFeet();
    int mmpClimbKnottedLengthFeet();
    int mmpConstrictExtraVictimsMin();
    int mmpConstrictExtraVictimsMax();
    int mmpConstrictVictimRangeFeet();
    int mmpConstrictDmgMin();
    int mmpConstrictDmgMax();
    int mmpConstrictAcClass();
    int mmpConstrictCutHitPoints();
    int mmpEntangleLashFeet();
    int mmpEntangleUpwardFeet();
    int mmpEntangleManSizedMax();
    int mmpEntangleStrikeSegments();
    int mmpEntangleEntwineSegments();
    int mmpEntangleCommandSegments();
    int mmpEntangleWholeSegments();
    int mmpEntangleAcClass();
    int mmpEntangleCutHitPoints();
    int mmpEntangleRepairTurns();
    int mmpSmotherRoundsMin();
    int mmpSmotherRoundsMax();
    int mmpSmotherBlockingSpells();
    int mmpWelcomeFlyWidthFeet();
    int mmpWelcomeFlyLengthFeet();
    int mmpWelcomeBridgeFeet();
    int mmpWelcomeBridgeWidthFeet();
    int mmpWelcomeAcClass();
    int mmpWelcomeDestroyHitPoints();
    int mmpWelcomeShrinkDivisor();
    int mmpSawLengthFeet();
    int mmpSawWidthFeet();
    int mmpSawSoloStrength();
    int mmpSawTandemStrength();
    int mmpSawTandemPersons();
    int mmpSawHardwoodFeet();
    int mmpSawHardwoodTurns();
    int mmpSawTrunkFeet();
    int mmpSawTrunkTurns();
    int mmpSawSmallDiameterFeet();
    int mmpSawSmallRounds();
    int mmpSawWorkTurns();
    int mmpSawRestTurns();
    int mmpDeathHoldRounds();
    int mmpDeathContainerFeet();
    int mmpDeathContainerTurns();
    int mmpDeathHeartRounds();
    int mmpEnrageRadiusInches();
    int mmpEnrageToHitBonus();
    int mmpEnrageDamageBonus();
    int mmpEnrageAcPenalty();
    int mmpEnrageRageMin();
    int mmpEnrageRageMax();
    int mmpEnrageChargesMin();
    int mmpEnrageChargesMax();
    int mmpInsanityRadiusInches();
    int mmpInsanitySavePenalty();
    int mmpInsanityMagicResistPenaltyPct();
    int mmpInsanityRoundsMin();
    int mmpInsanityRoundsMax();
    int mmpInsanityChargesMin();
    int mmpInsanityChargesMax();
    int mmpProtectSaveBonus();
    int mmpProtectNoSaveBase();
    int mmpProtectAbsorbCount();
    int mmpProtectReversedOneIn();
    int mmpProtectReversedPenalty();
    int mmpProtectFixedOneIn();
    int mmpProtectFixedBonus();
    int mmpProtectRemoveClericLevel();
    int mmpProtectRemovedAbsorbCount();
    int mmpSpadeLengthFeet();
    int mmpSpadeBladeWidthFeet();
    int mmpSpadeBladeLengthFeet();
    int mmpSpadeUserStrength();
    int mmpSpadeDigYardsPerRound();
    int mmpSpadeWorkRounds();
    int mmpSpadeRestRounds();
    int mmpSpadeHardPanFactor();
    int mmpSpadeGravelFactor();
    int mmpSpadeLooseSoilDivisor();
    int mmpEntangleManUnits(int i);
};
