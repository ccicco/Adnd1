// R-refactor: re-split from miscmagic_alchemy_jug_to_wings_of_flying.cpp - definitions
#include "rules/dmg/misc_magic/miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.h"

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpClimbLengthFeet() {
    // a 60 foot long rope of climbing
    return 60;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpClimbWeightPounds() {
    // weighs no more than 3 pounds
    return 3;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpClimbSupportPounds() {
    // strong enough to support 3,000 pounds
    return 3000;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpClimbSpeedFeetPerRound() {
    // moves at 10 feet per round upon command
    return 10;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpClimbKnotIntervalFeet() {
    // large knots appear at 1 foot intervals
    return 1;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpClimbKnottedLengthFeet() {
    // knotting shortens the rope to 50 feet
    return 50;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpConstrictExtraVictimsMin() {
    // lashes at 1-4 others near the holder
    return 1;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpConstrictExtraVictimsMax() {
    // the extra victim ceiling
    return 4;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpConstrictVictimRangeFeet() {
    // the others within 10 feet of the victim
    return 10;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpConstrictDmgMin() {
    // each round delivers 2-12 hit points
    return 2;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpConstrictDmgMax() {
    // the constriction damage ceiling
    return 12;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpConstrictAcClass() {
    // the rope itself is AC -2
    return -2;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpConstrictCutHitPoints() {
    // takes 22 hit points to cut through
    return 22;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpEntangleLashFeet() {
    // lashes forward 20 feet upon command
    return 20;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpEntangleUpwardFeet() {
    // or upwards 10 feet
    return 10;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpEntangleManSizedMax() {
    // ties fast up to 8 man-sized creatures
    return 8;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpEntangleStrikeSegments() {
    // a single segment to strike
    return 1;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpEntangleEntwineSegments() {
    // another segment to entwine
    return 1;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpEntangleCommandSegments() {
    // the command requires 1 segment
    return 1;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpEntangleWholeSegments() {
    // the whole takes 3 segments to perform
    return 3;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpEntangleAcClass() {
    // the rope is AC -2
    return -2;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpEntangleCutHitPoints() {
    // takes 22 hit points to cut through
    return 22;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpEntangleRepairTurns() {
    // damage under 22 repairs itself in 6 turns
    return 6;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSmotherRoundsMin() {
    // suffocates its victim in 3-6 rounds
    return 3;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSmotherRoundsMax() {
    // the suffocation ceiling
    return 6;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSmotherBlockingSpells() {
    // four spells prevent the smothering: alter
    // reality, animate object, hold plant, wish
    return 4;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpWelcomeFlyWidthFeet() {
    // functions as a carpet of flying (6 x 9
    return 6;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpWelcomeFlyLengthFeet() {
    // size)
    return 9;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpWelcomeBridgeFeet() {
    // stiffens as steel up to 27 feet long
    return 27;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpWelcomeBridgeWidthFeet() {
    // at a 2 foot width
    return 2;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpWelcomeAcClass() {
    // the bridge form is AC 0
    return 0;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpWelcomeDestroyHitPoints() {
    // takes 100 hit points to destroy
    return 100;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpWelcomeShrinkDivisor() {
    // shrinks to 1/12 size on command
    return 12;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSawLengthFeet() {
    // the notched adamantite blade is 12 feet
    return 12;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSawWidthFeet() {
    // long and over 1 foot wide
    return 1;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSawSoloStrength() {
    // requires 18/00 or greater strength alone
    return 18;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSawTandemStrength() {
    // or 2 persons of 17 or greater strength
    return 17;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSawTandemPersons() {
    // working in tandem
    return 2;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSawHardwoodFeet() {
    // a 2 foot thick hardwood tree
    return 2;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSawHardwoodTurns() {
    // sliced through in 1 turn
    return 1;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSawTrunkFeet() {
    // a 4 foot thick trunk
    return 4;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSawTrunkTurns() {
    // sliced through in 3 turns
    return 3;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSawSmallDiameterFeet() {
    // a 1 foot diameter tree
    return 1;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSawSmallRounds() {
    // sliced through in but 3 rounds
    return 3;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSawWorkTurns() {
    // after 6 turns of cutting
    return 6;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSawRestTurns() {
    // the users must rest for 6 turns
    return 6;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpDeathHoldRounds() {
    // changes if held for more than 1 round
    return 1;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpDeathContainerFeet() {
    // or placed within 1 foot of a warm
    return 1;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpDeathContainerTurns() {
    // living body for 1 turn
    return 1;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpDeathHeartRounds() {
    // reaches the victim heart in a single round
    return 1;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpEnrageRadiusInches() {
    // enrages hostiles within a 4 inch radius
    return 4;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpEnrageToHitBonus() {
    // the enraged gain +1 to hit
    return 1;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpEnrageDamageBonus() {
    // and +2 on damage
    return 2;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpEnrageAcPenalty() {
    // and -3 on their own armor class
    return 3;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpEnrageRageMin() {
    // the rage lasts for 7-12 rounds
    return 7;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpEnrageRageMax() {
    // the rage ceiling
    return 12;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpEnrageChargesMin() {
    // contains from 19-24 charges
    return 19;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpEnrageChargesMax() {
    // the charge ceiling
    return 24;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpInsanityRadiusInches() {
    // insanity within a 2 inch radius
    return 2;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpInsanitySavePenalty() {
    // the save versus magic at -2
    return 2;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpInsanityMagicResistPenaltyPct() {
    // and -10 percent from magic resistance
    return 10;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpInsanityRoundsMin() {
    // completely insane for 9-12 rounds
    return 9;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpInsanityRoundsMax() {
    // the insanity ceiling
    return 12;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpInsanityChargesMin() {
    // the scarab has 9-16 charges
    return 9;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpInsanityChargesMax() {
    // the charge ceiling
    return 16;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpProtectSaveBonus() {
    // +1 on all saving throws versus magic
    return 1;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpProtectNoSaveBase() {
    // a save of 20 when none is possible
    return 20;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpProtectAbsorbCount() {
    // absorbs up to 12 level drains or death
    return 12;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpProtectReversedOneIn() {
    // 1 in 20 are reversed cursed items
    return 20;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpProtectReversedPenalty() {
    // giving the possessor a -2 on the dice
    return 2;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpProtectFixedOneIn() {
    // 1 in 5 of the cursed items are fixed
    return 5;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpProtectFixedBonus() {
    // actually +2 once the curse is removed
    return 2;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpProtectRemoveClericLevel() {
    // removed by a cleric of 16 or higher level
    return 16;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpProtectRemovedAbsorbCount() {
    // the fixed scarab absorbs 24 rather than 12
    return 24;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSpadeLengthFeet() {
    // the digging tool is 8 feet long
    return 8;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSpadeBladeWidthFeet() {
    // with a blade 2 feet wide
    return 2;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSpadeBladeLengthFeet() {
    // and 3 feet long
    return 3;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSpadeUserStrength() {
    // any fighter with 18 strength can use it
    return 18;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSpadeDigYardsPerRound() {
    // 1 cubic yard excavated in 1 round
    return 1;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSpadeWorkRounds() {
    // every 10 rounds of digging
    return 10;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSpadeRestRounds() {
    // forces a rest of 5 rounds
    return 5;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSpadeHardPanFactor() {
    // hard pan clay takes twice as long
    return 2;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSpadeGravelFactor() {
    // as does gravel
    return 2;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpSpadeLooseSoilDivisor() {
    // loose soil takes half as long
    return 2;
}

int Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation::mmpEntangleManUnits(int i) {
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
