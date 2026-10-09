// ====================================================================
// Adnd1 - rules/miscprose22.h
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
// ====================================================================

#pragma once

namespace rules {

inline int mmpClimbLengthFeet() {
    // a 60 foot long rope of climbing
    return 60;
}

inline int mmpClimbWeightPounds() {
    // weighs no more than 3 pounds
    return 3;
}

inline int mmpClimbSupportPounds() {
    // strong enough to support 3,000 pounds
    return 3000;
}

inline int mmpClimbSpeedFeetPerRound() {
    // moves at 10 feet per round upon command
    return 10;
}

inline int mmpClimbKnotIntervalFeet() {
    // large knots appear at 1 foot intervals
    return 1;
}

inline int mmpClimbKnottedLengthFeet() {
    // knotting shortens the rope to 50 feet
    return 50;
}

inline int mmpConstrictExtraVictimsMin() {
    // lashes at 1-4 others near the holder
    return 1;
}

inline int mmpConstrictExtraVictimsMax() {
    // the extra victim ceiling
    return 4;
}

inline int mmpConstrictVictimRangeFeet() {
    // the others within 10 feet of the victim
    return 10;
}

inline int mmpConstrictDmgMin() {
    // each round delivers 2-12 hit points
    return 2;
}

inline int mmpConstrictDmgMax() {
    // the constriction damage ceiling
    return 12;
}

inline int mmpConstrictAcClass() {
    // the rope itself is AC -2
    return -2;
}

inline int mmpConstrictCutHitPoints() {
    // takes 22 hit points to cut through
    return 22;
}

inline int mmpEntangleLashFeet() {
    // lashes forward 20 feet upon command
    return 20;
}

inline int mmpEntangleUpwardFeet() {
    // or upwards 10 feet
    return 10;
}

inline int mmpEntangleManSizedMax() {
    // ties fast up to 8 man-sized creatures
    return 8;
}

inline int mmpEntangleStrikeSegments() {
    // a single segment to strike
    return 1;
}

inline int mmpEntangleEntwineSegments() {
    // another segment to entwine
    return 1;
}

inline int mmpEntangleCommandSegments() {
    // the command requires 1 segment
    return 1;
}

inline int mmpEntangleWholeSegments() {
    // the whole takes 3 segments to perform
    return 3;
}

inline int mmpEntangleAcClass() {
    // the rope is AC -2
    return -2;
}

inline int mmpEntangleCutHitPoints() {
    // takes 22 hit points to cut through
    return 22;
}

inline int mmpEntangleRepairTurns() {
    // damage under 22 repairs itself in 6 turns
    return 6;
}

inline int mmpSmotherRoundsMin() {
    // suffocates its victim in 3-6 rounds
    return 3;
}

inline int mmpSmotherRoundsMax() {
    // the suffocation ceiling
    return 6;
}

inline int mmpSmotherBlockingSpells() {
    // four spells prevent the smothering: alter
    // reality, animate object, hold plant, wish
    return 4;
}

inline int mmpWelcomeFlyWidthFeet() {
    // functions as a carpet of flying (6 x 9
    return 6;
}

inline int mmpWelcomeFlyLengthFeet() {
    // size)
    return 9;
}

inline int mmpWelcomeBridgeFeet() {
    // stiffens as steel up to 27 feet long
    return 27;
}

inline int mmpWelcomeBridgeWidthFeet() {
    // at a 2 foot width
    return 2;
}

inline int mmpWelcomeAcClass() {
    // the bridge form is AC 0
    return 0;
}

inline int mmpWelcomeDestroyHitPoints() {
    // takes 100 hit points to destroy
    return 100;
}

inline int mmpWelcomeShrinkDivisor() {
    // shrinks to 1/12 size on command
    return 12;
}

inline int mmpSawLengthFeet() {
    // the notched adamantite blade is 12 feet
    return 12;
}

inline int mmpSawWidthFeet() {
    // long and over 1 foot wide
    return 1;
}

inline int mmpSawSoloStrength() {
    // requires 18/00 or greater strength alone
    return 18;
}

inline int mmpSawTandemStrength() {
    // or 2 persons of 17 or greater strength
    return 17;
}

inline int mmpSawTandemPersons() {
    // working in tandem
    return 2;
}

inline int mmpSawHardwoodFeet() {
    // a 2 foot thick hardwood tree
    return 2;
}

inline int mmpSawHardwoodTurns() {
    // sliced through in 1 turn
    return 1;
}

inline int mmpSawTrunkFeet() {
    // a 4 foot thick trunk
    return 4;
}

inline int mmpSawTrunkTurns() {
    // sliced through in 3 turns
    return 3;
}

inline int mmpSawSmallDiameterFeet() {
    // a 1 foot diameter tree
    return 1;
}

inline int mmpSawSmallRounds() {
    // sliced through in but 3 rounds
    return 3;
}

inline int mmpSawWorkTurns() {
    // after 6 turns of cutting
    return 6;
}

inline int mmpSawRestTurns() {
    // the users must rest for 6 turns
    return 6;
}

inline int mmpDeathHoldRounds() {
    // changes if held for more than 1 round
    return 1;
}

inline int mmpDeathContainerFeet() {
    // or placed within 1 foot of a warm
    return 1;
}

inline int mmpDeathContainerTurns() {
    // living body for 1 turn
    return 1;
}

inline int mmpDeathHeartRounds() {
    // reaches the victim heart in a single round
    return 1;
}

inline int mmpEnrageRadiusInches() {
    // enrages hostiles within a 4 inch radius
    return 4;
}

inline int mmpEnrageToHitBonus() {
    // the enraged gain +1 to hit
    return 1;
}

inline int mmpEnrageDamageBonus() {
    // and +2 on damage
    return 2;
}

inline int mmpEnrageAcPenalty() {
    // and -3 on their own armor class
    return 3;
}

inline int mmpEnrageRageMin() {
    // the rage lasts for 7-12 rounds
    return 7;
}

inline int mmpEnrageRageMax() {
    // the rage ceiling
    return 12;
}

inline int mmpEnrageChargesMin() {
    // contains from 19-24 charges
    return 19;
}

inline int mmpEnrageChargesMax() {
    // the charge ceiling
    return 24;
}

inline int mmpInsanityRadiusInches() {
    // insanity within a 2 inch radius
    return 2;
}

inline int mmpInsanitySavePenalty() {
    // the save versus magic at -2
    return 2;
}

inline int mmpInsanityMagicResistPenaltyPct() {
    // and -10 percent from magic resistance
    return 10;
}

inline int mmpInsanityRoundsMin() {
    // completely insane for 9-12 rounds
    return 9;
}

inline int mmpInsanityRoundsMax() {
    // the insanity ceiling
    return 12;
}

inline int mmpInsanityChargesMin() {
    // the scarab has 9-16 charges
    return 9;
}

inline int mmpInsanityChargesMax() {
    // the charge ceiling
    return 16;
}

inline int mmpProtectSaveBonus() {
    // +1 on all saving throws versus magic
    return 1;
}

inline int mmpProtectNoSaveBase() {
    // a save of 20 when none is possible
    return 20;
}

inline int mmpProtectAbsorbCount() {
    // absorbs up to 12 level drains or death
    return 12;
}

inline int mmpProtectReversedOneIn() {
    // 1 in 20 are reversed cursed items
    return 20;
}

inline int mmpProtectReversedPenalty() {
    // giving the possessor a -2 on the dice
    return 2;
}

inline int mmpProtectFixedOneIn() {
    // 1 in 5 of the cursed items are fixed
    return 5;
}

inline int mmpProtectFixedBonus() {
    // actually +2 once the curse is removed
    return 2;
}

inline int mmpProtectRemoveClericLevel() {
    // removed by a cleric of 16 or higher level
    return 16;
}

inline int mmpProtectRemovedAbsorbCount() {
    // the fixed scarab absorbs 24 rather than 12
    return 24;
}

inline int mmpSpadeLengthFeet() {
    // the digging tool is 8 feet long
    return 8;
}

inline int mmpSpadeBladeWidthFeet() {
    // with a blade 2 feet wide
    return 2;
}

inline int mmpSpadeBladeLengthFeet() {
    // and 3 feet long
    return 3;
}

inline int mmpSpadeUserStrength() {
    // any fighter with 18 strength can use it
    return 18;
}

inline int mmpSpadeDigYardsPerRound() {
    // 1 cubic yard excavated in 1 round
    return 1;
}

inline int mmpSpadeWorkRounds() {
    // every 10 rounds of digging
    return 10;
}

inline int mmpSpadeRestRounds() {
    // forces a rest of 5 rounds
    return 5;
}

inline int mmpSpadeHardPanFactor() {
    // hard pan clay takes twice as long
    return 2;
}

inline int mmpSpadeGravelFactor() {
    // as does gravel
    return 2;
}

inline int mmpSpadeLooseSoilDivisor() {
    // loose soil takes half as long
    return 2;
}

inline int mmpEntangleManUnits(int i) {
    // the man-sized equivalence chain; i clamps
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    // 1 storm giant or fire giant = 2 frost or stone or
    // hill giants = 3 ogres = 4 bugbears = 6 gnolls = 8 men
    // = 10 elves = 12 dwarves = 16 gnomes or kobolds
    static const int t[9] = {
        1, 2, 3, 4, 6,
        8, 10, 12, 16,
    };
    return t[i];
}

}  // namespace rules