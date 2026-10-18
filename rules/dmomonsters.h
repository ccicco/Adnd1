// =========================================================================================
// Adnd1 - rules/dmomonsters.h
// THE LEGENDARY LADDER - DMO Chapter 2 closes: the altering-monsters doctrine
// (the +/-1/2/3 modifier used throughout - hit points floored at one a die,
// damage at one a die, saves capped at 20 and floored at 3, XP floored at
// 1-1, THACO and AC moved the printed way, movement and Intelligence and
// alignment and morale untouched, the three-point size shift optional), the
// ability-scores system (3d6 read by Size and Intelligence - Tables 6-11, the
// warrior bonuses, the total-not-per-die damage rule, the weight-allowance
// bumps 35/70/105, the bend-bars ladder, the three-point language gap), and
// the legendary ranks (Lesser Scion through Paragon - the AC -4 to -12 and
// hit-dice +5 to +25 ladder with the x1.5 through x3.5 area multiplier, the
// rank ability rolls 3d4+4 through 1d8+10, the power counts two-to-three
// through five-to-seven).
// census 525 -> 526.
//
// verified against printed pp. 57-66 of the uploaded DMO session capture
// (part 1, printed page N at OCR page N+1); the scrag colony example from p.
// 57, the rust monster reads from p. 58, the rank rosters and Table 12 from
// p. 61, the breath and disease and fear and crush tables from pp. 62-63, the
// wounding and melee and movement and gaze and resistance and regeneration
// tables from pp. 64-66.
//
// the gap census after this round: 37 closed, 59 open - ALL EIGHTEEN monster
// boxes of Chapter 2 close and the chapter is DONE; the DMO arc continues
// with Chapter 3 (Spells and Magical Items, pp. 68-85).
//
namespace rules {

// ---- the DMO monster-doctrine pins ----

// the ability-grid row count: 13 rows, the 3d6 rolls 3,4,5,6,7,8, the 9-12
// band as one row, 13,14,15,16,17,18 (Tables 6-11, printed pp. 58-61).
inline int denAbilityRowCount()
    { return 13; }

// the legendary-rank count: five ranks - Lesser Scion, Scion, Elder, Great
// Elder, Paragon (printed p. 61, Table 12).
inline int denRankCount()
    { return 5; }

// the altering-monsters cap: the modifier applied to a weaker or stronger
// specimen is -1, -2 or -3, or +1, +2 or +3 (printed p. 57).
inline int denAlterMax()
    { return 3; }

// the weaker-monster hit-point floor: the modifier is subtracted from each
// hit die, but the creature always receives at least one hit point from each
// hit die (printed p. 57).
inline int denHpFloor()
    { return 1; }

// the weaker-monster damage floor: the modifier is subtracted from each
// damage die, but the creature inflicts at least one point of damage with
// each die (printed p. 57).
inline int denDamageFloor()
    { return 1; }

// the weaker-monster save ceiling: the modifier is added to the base saving
// throws, but no saving throw can be increased above 20 (printed p. 57).
inline int denSaveCeiling()
    { return 20; }

// the stronger-monster save floor: the modifier is subtracted from the saving
// throw numbers, but no saving throw can be reduced below 3 (printed p. 57).
inline int denSaveFloor()
    { return 3; }

// the weaker-monster XP floor: the modifier is subtracted from the adjusted
// hit dice for the XP value, but no creature can have a value lower than 1-1
// (printed p. 57).
inline int denXpHdFloor()
    { return 1; }

// the optional size shift: a +3 modifier can bump the creature to the next
// higher size class and a -3 can reduce it one step (printed p. 57).
inline int denSizeShiftModifier()
    { return 3; }

// the ability-score generation die: roll 3d6 on the appropriate table and
// read the result from the applicable column (printed p. 58).
inline int denAbilityRollDie()
    { return 6; }

// the ability-score generation roll count: three dice of the d6 (printed p.
// 58).
inline int denAbilityRollCount()
    { return 3; }

// the monster weight allowance bump, large: add 35 pounds to a large
// creature's weight allowance - the higher of this and any listed capacity
// (printed p. 58).
inline int denWeightAllowLarge()
    { return 35; }

// the monster weight allowance bump, huge: add 70 pounds (printed p. 58).
inline int denWeightAllowHuge()
    { return 70; }

// the monster weight allowance bump, gargantuan: add 105 pounds (printed p.
// 58).
inline int denWeightAllowGargantuan()
    { return 105; }

// the monster bend bars/lift gates bonus, large: +5 percent - exceptionally
// sturdy objects negate the bonus (printed p. 59).
inline int denBendBarsLargePct()
    { return 5; }

// the monster bend bars/lift gates bonus, huge: +10 percent (printed p. 59).
inline int denBendBarsHugePct()
    { return 10; }

// the monster bend bars/lift gates bonus, gargantuan: +20 percent (printed p.
// 59).
inline int denBendBarsGargantuanPct()
    { return 20; }

// the monster language gap: a creature with an Intelligence score at least
// three points higher than the normal value for its race can understand one
// or more languages - the hoof-tap horse (printed p. 59).
inline int denLanguageGap()
    { return 3; }

// the lesser scion power range, minimum: two or three powers from Tables
// 13-22; several hundred to several thousand on a world (printed p. 61).
inline int denLesserScionPowersMin()
    { return 2; }

// the lesser scion power range, maximum: two or three powers (printed p. 61).
inline int denLesserScionPowersMax()
    { return 3; }

// the lesser scion ability roll die: 3d4+4 (printed p. 61).
inline int denLesserScionRollDie()
    { return 4; }

// the lesser scion ability roll count: three dice of the d4 (printed p. 61).
inline int denLesserScionRollCount()
    { return 3; }

// the lesser scion ability roll bonus: 3d4+4 (printed p. 61).
inline int denLesserScionRollBonus()
    { return 4; }

// the scion power range, minimum: three or four powers; a few hundred to
// perhaps a thousand on a world (printed p. 61).
inline int denScionPowersMin()
    { return 3; }

// the scion power range, maximum: three or four powers (printed p. 61).
inline int denScionPowersMax()
    { return 4; }

// the scion ability roll die: 2d6+6 (printed p. 61).
inline int denScionRollDie()
    { return 6; }

// the scion ability roll count: two dice of the d6 (printed p. 61).
inline int denScionRollCount()
    { return 2; }

// the scion ability roll bonus: 2d6+6 (printed p. 61).
inline int denScionRollBonus()
    { return 6; }

// the elder power range, minimum: three to five powers; not more than a few
// hundred of any race on a world (printed p. 61).
inline int denElderPowersMin()
    { return 3; }

// the elder power range, maximum: three to five powers (printed p. 61).
inline int denElderPowersMax()
    { return 5; }

// the elder ability roll die: 1d10+8 (printed p. 61).
inline int denElderRollDie()
    { return 10; }

// the elder ability roll count: one die of the d10 (printed p. 61).
inline int denElderRollCount()
    { return 1; }

// the elder ability roll bonus: 1d10+8 (printed p. 61).
inline int denElderRollBonus()
    { return 8; }

// the great elder power range, minimum: four to six powers; not more than
// several dozen of a given race on a world (printed p. 61).
inline int denGreatElderPowersMin()
    { return 4; }

// the great elder power range, maximum: four to six powers (printed p. 61).
inline int denGreatElderPowersMax()
    { return 6; }

// the great elder ability roll die: 1d10+8, the same roll as the elder
// (printed p. 61).
inline int denGreatElderRollDie()
    { return 10; }

// the great elder ability roll count: one die of the d10 (printed p. 61).
inline int denGreatElderRollCount()
    { return 1; }

// the great elder ability roll bonus: 1d10+8 (printed p. 61).
inline int denGreatElderRollBonus()
    { return 8; }

// the paragon power range, minimum: five to seven powers; a handful at most,
// often a unique creature (printed p. 61).
inline int denParagonPowersMin()
    { return 5; }

// the paragon power range, maximum: five to seven powers (printed p. 61).
inline int denParagonPowersMax()
    { return 7; }

// the paragon ability roll die: 1d8+10 (printed p. 61).
inline int denParagonRollDie()
    { return 8; }

// the paragon ability roll count: one die of the d8 (printed p. 61).
inline int denParagonRollCount()
    { return 1; }

// the paragon ability roll bonus: 1d8+10 (printed p. 61).
inline int denParagonRollBonus()
    { return 10; }

// the fixed-hit-point rule: a monster normally given a fixed hit point total
// gains five hit points per additional hit die instead of rolled dice
// (printed p. 61, Table 12).
inline int denFixedHpPerExtraDie()
    { return 5; }

// the breath-weapon daily minimum: three uses a day (printed p. 62).
inline int denBreathPerDayMin()
    { return 3; }

// the breath-weapon daily maximum: five uses a day (printed p. 62).
inline int denBreathPerDayMax()
    { return 5; }

// the breath-weapon wait minimum: one round between breaths (printed p. 62).
inline int denBreathWaitRoundsMin()
    { return 1; }

// the breath-weapon wait maximum: two rounds between breaths (printed p. 62).
inline int denBreathWaitRoundsMax()
    { return 2; }

// the paragon breath rule in half-points: an existing breath weapon averages
// 4.5 points of damage per hit die - the 39-hit-die paragon dragon turtle
// inflicts an average of 175 (printed p. 62).
inline int denParagonBreathHalfPerHd()
    { return 45; }

// the breath-average ladder in half-points: 1d4 averages 2.5 (printed p. 63).
inline int denAvgD4Half()
    { return 25; }

// the breath-average ladder in half-points: 1d6 averages 3.5 (printed p. 63).
inline int denAvgD6Half()
    { return 35; }

// the breath-average ladder in half-points: 1d8 averages 4.5 (printed p. 63).
inline int denAvgD8Half()
    { return 45; }

// the breath-average ladder in half-points: 1d10 averages 5.5 (printed p.
// 63).
inline int denAvgD10Half()
    { return 55; }

// the breath-average ladder in half-points: 1d12 averages 6.5 (printed p.
// 63).
inline int denAvgD12Half()
    { return 65; }

// the breath-average ladder in half-points: 1d20 averages 10.5 (printed p.
// 63).
inline int denAvgD20Half()
    { return 105; }

// the breath cloud geometry, width: 50 feet wide (printed p. 63).
inline int denCloudWidthFt()
    { return 50; }

// the breath cloud geometry, height: 40 feet tall (printed p. 63).
inline int denCloudHeightFt()
    { return 40; }

// the breath cone geometry, at the mouth: 5 feet in diameter (printed p. 63).
inline int denConeMouthFt()
    { return 5; }

// the breath cone geometry, at the apex: 30 feet in diameter (printed p. 63).
inline int denConeApexFt()
    { return 30; }

// the breath line geometry, width: 5 feet wide (printed p. 63).
inline int denLineWidthFt()
    { return 5; }

// the breath line geometry, height: 5 feet tall (printed p. 63).
inline int denLineHeightFt()
    { return 5; }

// the cause-disease check: after a successful physical attack roll 1d100 -
// equal to or less than the damage inflicted contracts the disease; two hits
// for 17 and 21 points means 38 or less, checked once a round (printed p.
// 62).
inline int denDiseaseCheckDie()
    { return 100; }

// the chills duration die: the victim shivers 2d4 rounds, unable to move,
// attack or cast spells (printed p. 63).
inline int denChillsRoundsDie()
    { return 4; }

// the chills duration count: two dice of the d4, recurring on a fresh onset
// roll (printed p. 63).
inline int denChillsRoundsCount()
    { return 2; }

// the chills penalty: all saving throws and ability checks suffer -4 while
// the chills last (printed p. 63).
inline int denChillsPenalty()
    { return 4; }

// the delirium snap-out roll: once each turn the victim snaps out on a 9 or
// less on 1d20, the Constitution hit-point adjustment applying as bonus or
// penalty (printed p. 63).
inline int denDeliriumSnapRoll()
    { return 9; }

// the fever consciousness roll: forced into action the victim rolls a 9 or
// less on 1d20 each hour to stay conscious, else delirium 2d4 rounds and a
// stupor 2d4 hours (printed p. 63).
inline int denFeverConsciousRoll()
    { return 9; }

// the cause-fear panic bar: creatures of less than 4+1 hit dice flee on sight
// when the monster attacks or charges (printed p. 63).
inline int denCauseFearHdMax()
    { return 4; }

// the cause-fear panic bar, characters: 4th level or less (printed p. 63).
inline int denCauseFearLevelMax()
    { return 4; }

// the cause-fear flee duration die: panicked creatures flee 2d4 turns as
// though under the 4th-level wizard fear spell (printed p. 63).
inline int denCauseFearFleeDie()
    { return 4; }

// the cause-fear flee duration count: two dice of the d4, in turns (printed
// p. 63).
inline int denCauseFearFleeCount()
    { return 2; }

// the flying crush height: a flying creature or one jumping down from 30 feet
// or more can crush at the end of its movement (printed p. 63).
inline int denCrushHeightMin()
    { return 30; }

// the crush save penalty, two sizes smaller: the save vs. death is at -4
// (printed p. 63).
inline int denCrushTwoSizePenalty()
    { return 4; }

// the crush save penalty, three sizes smaller: -8, and so on down the sizes
// (printed p. 63).
inline int denCrushThreeSizePenalty()
    { return 8; }

// the existing-gaze-weapon rule: use the next higher rank's values - a
// paragon's gaze penalty is -8 (printed p. 66).
inline int denExistingGazeParagonPenalty()
    { return 8; }

// the altering-monsters constancy doctrine: once you start altering a
// monster, use the same modifier throughout the process (printed p. 57).
inline bool denSameModifierThroughout()
    { return true; }

// the altering-monsters scope doctrine: the creature's movement rate,
// Intelligence, alignment, morale and other statistics remain unchanged under
// the modifier system (printed p. 57).
inline bool denUnchangedCharacteristics()
    { return true; }

// the monster ability doctrine, strength: except as noted, all modifiers
// apply to creatures as they do for characters, and creatures gain the
// warrior combat bonuses for high scores (printed p. 58).
inline bool denAbilityWarriorBonuses()
    { return true; }

// the monster ability doctrine, damage adjustment: the bonus or penalty
// applies to the creature's natural attacks - if the creature rolls multiple
// dice the adjustment applies to the total, not each die (printed p. 58).
inline bool denDamageTotalNotPerDie()
    { return true; }

// the monster ability doctrine, dexterity: all modifiers apply as for
// characters, except the Reaction Adjustment also increases the movement rate
// (printed p. 59).
inline bool denDexMovesBonus()
    { return true; }

// the ability-scores-for-monsters scope: the system is intended for
// nonhumanoid creatures (humanoids are best treated as characters) but works
// with any creature in a pinch; the Size and Intelligence ratings determine
// the range (printed pp. 57-58).
inline bool denNonhumanoidDoctrine()
    { return true; }

// the legendary potency doctrine: like a dragon's fear radius, a legendary
// monster's power potency is based on its overall rank - an elder's breath is
// noticeably deadlier than a lesser scion's (printed p. 62).
inline bool denRankPotencyDoctrine()
    { return true; }

// the existing-breath-weapon rule: a creature that already has a breath
// weapon uses the values for the next higher rank, and all damaging breath
// weapons deal half on a successful save (printed p. 62).
inline bool denExistingBreathNextRank()
    { return true; }

// the gaze-attack doctrine: a gaze attack requires no special effort and
// freely combines with other attacks and abilities - the effect is whatever
// the DM desires, with the save to avoid it (printed p. 66).
inline bool denGazeEffortless()
    { return true; }

// the crush-attack doctrine: the creature expends its full movement allowance
// for the round and takes no other actions; opponents larger than the
// attacker cannot be crushed (printed p. 63).
inline bool denCrushFullMovement()
    { return true; }

// the crush-and-overrun doctrine: under the PLAYER'S OPTION overrun rule a
// crush attack does not provoke an attack of opportunity, knocked-down
// creatures smaller than the attacker can be trampled, and overruns work only
// against smaller creatures (printed p. 63).
inline bool denCrushOverrunNoAoo()
    { return true; }

// the wounding doctrine: wounds from this power cannot be healed by
// regeneration, first aid, or any magical means short of a wish, a 10th-level
// healing spell, or a periapt of wound closure (printed p. 64).
inline bool denWoundNoRegen()
    { return true; }

// the lesser-regeneration bar: a scion or lesser scion eventually regenerates
// any damage unless attacked with fire, acid, or magical wounding, and cannot
// regenerate back to life after a disintegrate or death-magic kill, or if its
// remains are destroyed (printed p. 66).
inline bool denLesserRegenBar()
    { return true; }

// the enhanced-movement doctrine: the normal movement increases by the listed
// percentage with fractions rounded up, and the bonus also defines unusual
// movement powers - leaps, blinks, climbs (printed p. 66).
inline bool denEnhancedMovementRoundsUp()
    { return true; }

// the Table 6 denStrT column: the Strength score for the roll band (printed
// p. 58).
inline int denStrT(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 7;
        case 6:
            return 8;
        case 7:
            return 10;
        case 8:
            return 11;
        case 9:
            return 12;
        case 10:
            return 13;
        case 11:
            return 14;
        case 12:
            return 15;
        default:
            return -99;
        }
    }

// the Table 6 denStrS column: the Strength score for the roll band (printed
// p. 58).
inline int denStrS(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 5;
        case 2:
            return 6;
        case 3:
            return 7;
        case 4:
            return 8;
        case 5:
            return 9;
        case 6:
            return 10;
        case 7:
            return 11;
        case 8:
            return 12;
        case 9:
            return 13;
        case 10:
            return 14;
        case 11:
            return 15;
        case 12:
            return 16;
        default:
            return -99;
        }
    }

// the Table 6 denStrM column: the Strength score for the roll band (printed
// p. 58).
inline int denStrM(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 7;
        case 2:
            return 8;
        case 3:
            return 9;
        case 4:
            return 10;
        case 5:
            return 11;
        case 6:
            return 12;
        case 7:
            return 13;
        case 8:
            return 14;
        case 9:
            return 15;
        case 10:
            return 16;
        case 11:
            return 17;
        case 12:
            return 18;
        default:
            return -99;
        }
    }

// the Table 6 denStrL column: the Strength score for the roll band (printed
// p. 58).
inline int denStrL(int b)
    {
        switch (b) {
        case 0:
            return 13;
        case 1:
            return 14;
        case 2:
            return 15;
        case 3:
            return 16;
        case 4:
            return 17;
        case 5:
            return 18;
        case 6:
            return 1801;
        case 7:
            return 1851;
        case 8:
            return 1876;
        case 9:
            return 1891;
        case 10:
            return 1800;
        case 11:
            return 19;
        case 12:
            return 20;
        default:
            return -99;
        }
    }

// the Table 6 denStrH column: the Strength score for the roll band (printed
// p. 58).
inline int denStrH(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 17;
        case 2:
            return 18;
        case 3:
            return 1801;
        case 4:
            return 1851;
        case 5:
            return 1876;
        case 6:
            return 1891;
        case 7:
            return 1800;
        case 8:
            return 19;
        case 9:
            return 20;
        case 10:
            return 21;
        case 11:
            return 22;
        case 12:
            return 23;
        default:
            return -99;
        }
    }

// the Table 6 denStrG column: the Strength score for the roll band (printed
// p. 58).
inline int denStrG(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 1801;
        case 2:
            return 1851;
        case 3:
            return 1876;
        case 4:
            return 1891;
        case 5:
            return 1800;
        case 6:
            return 19;
        case 7:
            return 20;
        case 8:
            return 21;
        case 9:
            return 22;
        case 10:
            return 23;
        case 11:
            return 24;
        case 12:
            return 25;
        default:
            return -99;
        }
    }

// the Table 7 denDexT column: the Dexterity score for the roll band (printed
// p. 58).
inline int denDexT(int b)
    {
        switch (b) {
        case 0:
            return 13;
        case 1:
            return 14;
        case 2:
            return 15;
        case 3:
            return 16;
        case 4:
            return 17;
        case 5:
            return 18;
        case 6:
            return 19;
        case 7:
            return 20;
        case 8:
            return 21;
        case 9:
            return 22;
        case 10:
            return 23;
        case 11:
            return 24;
        case 12:
            return 25;
        default:
            return -99;
        }
    }

// the Table 7 denDexS column: the Dexterity score for the roll band (printed
// p. 58).
inline int denDexS(int b)
    {
        switch (b) {
        case 0:
            return 11;
        case 1:
            return 12;
        case 2:
            return 13;
        case 3:
            return 14;
        case 4:
            return 15;
        case 5:
            return 16;
        case 6:
            return 17;
        case 7:
            return 18;
        case 8:
            return 19;
        case 9:
            return 20;
        case 10:
            return 21;
        case 11:
            return 22;
        case 12:
            return 23;
        default:
            return -99;
        }
    }

// the Table 7 denDexM column: the Dexterity score for the roll band (printed
// p. 58).
inline int denDexM(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 10;
        case 2:
            return 11;
        case 3:
            return 12;
        case 4:
            return 13;
        case 5:
            return 14;
        case 6:
            return 15;
        case 7:
            return 16;
        case 8:
            return 17;
        case 9:
            return 18;
        case 10:
            return 19;
        case 11:
            return 20;
        case 12:
            return 21;
        default:
            return -99;
        }
    }

// the Table 7 denDexL column: the Dexterity score for the roll band (printed
// p. 58).
inline int denDexL(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 8;
        case 2:
            return 9;
        case 3:
            return 10;
        case 4:
            return 11;
        case 5:
            return 12;
        case 6:
            return 13;
        case 7:
            return 14;
        case 8:
            return 15;
        case 9:
            return 16;
        case 10:
            return 17;
        case 11:
            return 18;
        case 12:
            return 19;
        default:
            return -99;
        }
    }

// the Table 7 denDexH column: the Dexterity score for the roll band (printed
// p. 58).
inline int denDexH(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 6;
        case 2:
            return 7;
        case 3:
            return 8;
        case 4:
            return 9;
        case 5:
            return 10;
        case 6:
            return 11;
        case 7:
            return 12;
        case 8:
            return 13;
        case 9:
            return 14;
        case 10:
            return 15;
        case 11:
            return 16;
        case 12:
            return 17;
        default:
            return -99;
        }
    }

// the Table 7 denDexG column: the Dexterity score for the roll band (printed
// p. 58).
inline int denDexG(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 5;
        case 3:
            return 6;
        case 4:
            return 7;
        case 5:
            return 8;
        case 6:
            return 9;
        case 7:
            return 10;
        case 8:
            return 11;
        case 9:
            return 12;
        case 10:
            return 13;
        case 11:
            return 14;
        case 12:
            return 15;
        default:
            return -99;
        }
    }

// the Table 8 denConT column: the Constitution score for the roll band
// (printed p. 58).
inline int denConT(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 5;
        case 3:
            return 6;
        case 4:
            return 7;
        case 5:
            return 8;
        case 6:
            return 9;
        case 7:
            return 10;
        case 8:
            return 11;
        case 9:
            return 12;
        case 10:
            return 13;
        case 11:
            return 14;
        case 12:
            return 15;
        default:
            return -99;
        }
    }

// the Table 8 denConS column: the Constitution score for the roll band
// (printed p. 58).
inline int denConS(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 6;
        case 2:
            return 7;
        case 3:
            return 8;
        case 4:
            return 9;
        case 5:
            return 10;
        case 6:
            return 11;
        case 7:
            return 12;
        case 8:
            return 13;
        case 9:
            return 14;
        case 10:
            return 15;
        case 11:
            return 16;
        case 12:
            return 17;
        default:
            return -99;
        }
    }

// the Table 8 denConM column: the Constitution score for the roll band
// (printed p. 58).
inline int denConM(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 8;
        case 2:
            return 9;
        case 3:
            return 10;
        case 4:
            return 11;
        case 5:
            return 12;
        case 6:
            return 13;
        case 7:
            return 14;
        case 8:
            return 15;
        case 9:
            return 16;
        case 10:
            return 17;
        case 11:
            return 18;
        case 12:
            return 19;
        default:
            return -99;
        }
    }

// the Table 8 denConL column: the Constitution score for the roll band
// (printed p. 58).
inline int denConL(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 10;
        case 2:
            return 11;
        case 3:
            return 12;
        case 4:
            return 13;
        case 5:
            return 14;
        case 6:
            return 15;
        case 7:
            return 16;
        case 8:
            return 17;
        case 9:
            return 18;
        case 10:
            return 19;
        case 11:
            return 20;
        case 12:
            return 21;
        default:
            return -99;
        }
    }

// the Table 8 denConH column: the Constitution score for the roll band
// (printed p. 58).
inline int denConH(int b)
    {
        switch (b) {
        case 0:
            return 11;
        case 1:
            return 12;
        case 2:
            return 13;
        case 3:
            return 14;
        case 4:
            return 15;
        case 5:
            return 16;
        case 6:
            return 17;
        case 7:
            return 18;
        case 8:
            return 19;
        case 9:
            return 20;
        case 10:
            return 21;
        case 11:
            return 22;
        case 12:
            return 23;
        default:
            return -99;
        }
    }

// the Table 8 denConG column: the Constitution score for the roll band
// (printed p. 58).
inline int denConG(int b)
    {
        switch (b) {
        case 0:
            return 13;
        case 1:
            return 14;
        case 2:
            return 15;
        case 3:
            return 16;
        case 4:
            return 17;
        case 5:
            return 18;
        case 6:
            return 19;
        case 7:
            return 20;
        case 8:
            return 21;
        case 9:
            return 22;
        case 10:
            return 23;
        case 11:
            return 24;
        case 12:
            return 25;
        default:
            return -99;
        }
    }

// the Table 9 Animal-intelligence column: the Intelligence score for the roll
// band (printed p. 59).
inline int denIntA(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 4;
        default:
            return -99;
        }
    }

// the Table 9 Semiintelligent column: the Intelligence score for the roll
// band (printed p. 59).
inline int denIntS(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 4;
        case 9:
            return 4;
        case 10:
            return 5;
        case 11:
            return 5;
        case 12:
            return 6;
        default:
            return -99;
        }
    }

// the Table 9 Low-intelligence column: the Intelligence score for the roll
// band (printed p. 59).
inline int denIntL(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 6;
        case 8:
            return 7;
        case 9:
            return 7;
        case 10:
            return 8;
        case 11:
            return 8;
        case 12:
            return 9;
        default:
            return -99;
        }
    }

// the Table 9 Average-intelligence column: the Intelligence score for the
// roll band (printed p. 59).
inline int denIntAv(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 7;
        case 2:
            return 7;
        case 3:
            return 8;
        case 4:
            return 8;
        case 5:
            return 9;
        case 6:
            return 9;
        case 7:
            return 10;
        case 8:
            return 10;
        case 9:
            return 11;
        case 10:
            return 11;
        case 11:
            return 12;
        case 12:
            return 13;
        default:
            return -99;
        }
    }

// the Table 9 Very-intelligence column: the Intelligence score for the roll
// band (printed p. 59).
inline int denIntV(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 7;
        case 2:
            return 8;
        case 3:
            return 8;
        case 4:
            return 9;
        case 5:
            return 9;
        case 6:
            return 11;
        case 7:
            return 11;
        case 8:
            return 12;
        case 9:
            return 12;
        case 10:
            return 13;
        case 11:
            return 14;
        case 12:
            return 15;
        default:
            return -99;
        }
    }

// the Table 9 Highly-intelligence column: the Intelligence score for the roll
// band (printed p. 59).
inline int denIntH(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 10;
        case 2:
            return 11;
        case 3:
            return 11;
        case 4:
            return 12;
        case 5:
            return 12;
        case 6:
            return 13;
        case 7:
            return 13;
        case 8:
            return 14;
        case 9:
            return 15;
        case 10:
            return 16;
        case 11:
            return 17;
        case 12:
            return 19;
        default:
            return -99;
        }
    }

// the Table 9 Exceptionally-intelligence column: the Intelligence score for
// the roll band (printed p. 59).
inline int denIntE(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 11;
        case 2:
            return 13;
        case 3:
            return 13;
        case 4:
            return 14;
        case 5:
            return 14;
        case 6:
            return 15;
        case 7:
            return 15;
        case 8:
            return 16;
        case 9:
            return 17;
        case 10:
            return 18;
        case 11:
            return 19;
        case 12:
            return 20;
        default:
            return -99;
        }
    }

// the Table 9 Genius-intelligence column: the Intelligence score for the roll
// band (printed p. 59).
inline int denIntG(int b)
    {
        switch (b) {
        case 0:
            return 13;
        case 1:
            return 14;
        case 2:
            return 15;
        case 3:
            return 16;
        case 4:
            return 16;
        case 5:
            return 17;
        case 6:
            return 17;
        case 7:
            return 18;
        case 8:
            return 19;
        case 9:
            return 20;
        case 10:
            return 21;
        case 11:
            return 22;
        case 12:
            return 23;
        default:
            return -99;
        }
    }

// the Table 9 Supra-genius-intelligence column: the Intelligence score for
// the roll band (printed p. 59).
inline int denIntSg(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 16;
        case 2:
            return 17;
        case 3:
            return 17;
        case 4:
            return 18;
        case 5:
            return 18;
        case 6:
            return 19;
        case 7:
            return 19;
        case 8:
            return 20;
        case 9:
            return 21;
        case 10:
            return 22;
        case 11:
            return 23;
        case 12:
            return 24;
        default:
            return -99;
        }
    }

// the Table 9 Godlike-intelligence column: the Intelligence score for the
// roll band (printed p. 59).
inline int denIntGo(int b)
    {
        switch (b) {
        case 0:
            return 17;
        case 1:
            return 18;
        case 2:
            return 19;
        case 3:
            return 19;
        case 4:
            return 20;
        case 5:
            return 20;
        case 6:
            return 21;
        case 7:
            return 21;
        case 8:
            return 22;
        case 9:
            return 22;
        case 10:
            return 23;
        case 11:
            return 24;
        case 12:
            return 25;
        default:
            return -99;
        }
    }

// the Table 10 Animal-intelligence column: the Wisdom score for the roll band
// (printed p. 59).
inline int denWisA(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 3;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 5;
        default:
            return -99;
        }
    }

// the Table 10 Semiintelligent column: the Wisdom score for the roll band
// (printed p. 59).
inline int denWisS(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 4;
        case 9:
            return 5;
        case 10:
            return 5;
        case 11:
            return 5;
        case 12:
            return 6;
        default:
            return -99;
        }
    }

// the Table 10 Low-intelligence column: the Wisdom score for the roll band
// (printed p. 59).
inline int denWisL(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 6;
        case 8:
            return 7;
        case 9:
            return 7;
        case 10:
            return 8;
        case 11:
            return 8;
        case 12:
            return 9;
        default:
            return -99;
        }
    }

// the Table 10 Average-intelligence column: the Wisdom score for the roll
// band (printed p. 59).
inline int denWisAv(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
        case 2:
            return 7;
        case 3:
            return 7;
        case 4:
            return 8;
        case 5:
            return 8;
        case 6:
            return 9;
        case 7:
            return 9;
        case 8:
            return 10;
        case 9:
            return 10;
        case 10:
            return 11;
        case 11:
            return 11;
        case 12:
            return 12;
        default:
            return -99;
        }
    }

// the Table 10 Very-intelligence column: the Wisdom score for the roll band
// (printed p. 59).
inline int denWisV(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 8;
        case 2:
            return 9;
        case 3:
            return 9;
        case 4:
            return 10;
        case 5:
            return 10;
        case 6:
            return 11;
        case 7:
            return 11;
        case 8:
            return 12;
        case 9:
            return 12;
        case 10:
            return 13;
        case 11:
            return 13;
        case 12:
            return 14;
        default:
            return -99;
        }
    }

// the Table 10 Highly-intelligence column: the Wisdom score for the roll band
// (printed p. 59).
inline int denWisH(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 10;
        case 2:
            return 11;
        case 3:
            return 11;
        case 4:
            return 12;
        case 5:
            return 12;
        case 6:
            return 13;
        case 7:
            return 13;
        case 8:
            return 14;
        case 9:
            return 14;
        case 10:
            return 15;
        case 11:
            return 16;
        case 12:
            return 17;
        default:
            return -99;
        }
    }

// the Table 10 Exceptionally-intelligence column: the Wisdom score for the
// roll band (printed p. 59).
inline int denWisE(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 12;
        case 2:
            return 13;
        case 3:
            return 13;
        case 4:
            return 14;
        case 5:
            return 14;
        case 6:
            return 15;
        case 7:
            return 15;
        case 8:
            return 16;
        case 9:
            return 16;
        case 10:
            return 17;
        case 11:
            return 18;
        case 12:
            return 19;
        default:
            return -99;
        }
    }

// the Table 10 Genius-intelligence column: the Wisdom score for the roll band
// (printed p. 59).
inline int denWisG(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 14;
        case 2:
            return 15;
        case 3:
            return 15;
        case 4:
            return 16;
        case 5:
            return 16;
        case 6:
            return 17;
        case 7:
            return 17;
        case 8:
            return 18;
        case 9:
            return 18;
        case 10:
            return 19;
        case 11:
            return 20;
        case 12:
            return 21;
        default:
            return -99;
        }
    }

// the Table 10 Supra-genius-intelligence column: the Wisdom score for the
// roll band (printed p. 59).
inline int denWisSg(int b)
    {
        switch (b) {
        case 0:
            return 16;
        case 1:
            return 16;
        case 2:
            return 17;
        case 3:
            return 17;
        case 4:
            return 18;
        case 5:
            return 18;
        case 6:
            return 19;
        case 7:
            return 19;
        case 8:
            return 20;
        case 9:
            return 20;
        case 10:
            return 21;
        case 11:
            return 22;
        case 12:
            return 23;
        default:
            return -99;
        }
    }

// the Table 10 Godlike-intelligence column: the Wisdom score for the roll
// band (printed p. 59).
inline int denWisGo(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 18;
        case 2:
            return 19;
        case 3:
            return 19;
        case 4:
            return 20;
        case 5:
            return 20;
        case 6:
            return 21;
        case 7:
            return 21;
        case 8:
            return 22;
        case 9:
            return 22;
        case 10:
            return 23;
        case 11:
            return 24;
        case 12:
            return 25;
        default:
            return -99;
        }
    }

// the Table 11 Animal-intelligence column: the Charisma score for the roll
// band (printed p. 61).
inline int denChaA(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 3;
        case 12:
            return 3;
        default:
            return -99;
        }
    }

// the Table 11 Semiintelligent column: the Charisma score for the roll band
// (printed p. 61).
inline int denChaS(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 4;
        case 9:
            return 4;
        case 10:
            return 5;
        case 11:
            return 5;
        case 12:
            return 6;
        default:
            return -99;
        }
    }

// the Table 11 Low-intelligence column: the Charisma score for the roll band
// (printed p. 61).
inline int denChaL(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 6;
        case 8:
            return 7;
        case 9:
            return 7;
        case 10:
            return 8;
        case 11:
            return 8;
        case 12:
            return 9;
        default:
            return -99;
        }
    }

// the Table 11 Average-intelligence column: the Charisma score for the roll
// band (printed p. 61).
inline int denChaAv(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
        case 2:
            return 7;
        case 3:
            return 7;
        case 4:
            return 8;
        case 5:
            return 8;
        case 6:
            return 9;
        case 7:
            return 9;
        case 8:
            return 10;
        case 9:
            return 10;
        case 10:
            return 11;
        case 11:
            return 11;
        case 12:
            return 12;
        default:
            return -99;
        }
    }

// the Table 11 Very-intelligence column: the Charisma score for the roll band
// (printed p. 61).
inline int denChaV(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 8;
        case 2:
            return 9;
        case 3:
            return 9;
        case 4:
            return 10;
        case 5:
            return 10;
        case 6:
            return 11;
        case 7:
            return 11;
        case 8:
            return 12;
        case 9:
            return 12;
        case 10:
            return 13;
        case 11:
            return 13;
        case 12:
            return 14;
        default:
            return -99;
        }
    }

// the Table 11 Highly-intelligence column: the Charisma score for the roll
// band (printed p. 61).
inline int denChaH(int b)
    {
        switch (b) {
        case 0:
            return 11;
        case 1:
            return 11;
        case 2:
            return 12;
        case 3:
            return 12;
        case 4:
            return 13;
        case 5:
            return 13;
        case 6:
            return 14;
        case 7:
            return 14;
        case 8:
            return 15;
        case 9:
            return 15;
        case 10:
            return 16;
        case 11:
            return 16;
        case 12:
            return 17;
        default:
            return -99;
        }
    }

// the Table 11 Exceptionally-intelligence column: the Charisma score for the
// roll band (printed p. 61).
inline int denChaE(int b)
    {
        switch (b) {
        case 0:
            return 13;
        case 1:
            return 13;
        case 2:
            return 14;
        case 3:
            return 14;
        case 4:
            return 15;
        case 5:
            return 15;
        case 6:
            return 16;
        case 7:
            return 16;
        case 8:
            return 17;
        case 9:
            return 17;
        case 10:
            return 18;
        case 11:
            return 18;
        case 12:
            return 19;
        default:
            return -99;
        }
    }

// the Table 11 Genius-intelligence column: the Charisma score for the roll
// band (printed p. 61).
inline int denChaG(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 15;
        case 2:
            return 16;
        case 3:
            return 16;
        case 4:
            return 17;
        case 5:
            return 17;
        case 6:
            return 18;
        case 7:
            return 18;
        case 8:
            return 19;
        case 9:
            return 19;
        case 10:
            return 20;
        case 11:
            return 20;
        case 12:
            return 21;
        default:
            return -99;
        }
    }

// the Table 11 Supra-genius-intelligence column: the Charisma score for the
// roll band (printed p. 61).
inline int denChaSg(int b)
    {
        switch (b) {
        case 0:
            return 17;
        case 1:
            return 17;
        case 2:
            return 18;
        case 3:
            return 18;
        case 4:
            return 19;
        case 5:
            return 19;
        case 6:
            return 20;
        case 7:
            return 20;
        case 8:
            return 21;
        case 9:
            return 21;
        case 10:
            return 22;
        case 11:
            return 22;
        case 12:
            return 23;
        default:
            return -99;
        }
    }

// the Table 11 Godlike-intelligence column: the Charisma score for the roll
// band (printed p. 61).
inline int denChaGo(int b)
    {
        switch (b) {
        case 0:
            return 19;
        case 1:
            return 19;
        case 2:
            return 20;
        case 3:
            return 20;
        case 4:
            return 21;
        case 5:
            return 21;
        case 6:
            return 22;
        case 7:
            return 22;
        case 8:
            return 23;
        case 9:
            return 23;
        case 10:
            return 24;
        case 11:
            return 24;
        case 12:
            return 25;
        default:
            return -99;
        }
    }

// the Table 12 armor-class modifier for the rank, subtracted from the base AC
// (printed p. 61).
inline int denLegendAcMod(int b)
    {
        switch (b) {
        case 0:
            return -4;
        case 1:
            return -6;
        case 2:
            return -8;
        case 3:
            return -10;
        case 4:
            return -12;
        default:
            return -99;
        }
    }

// the Table 12 hit-dice bonus for the rank, added with all the benefits -
// reduced THACO, better saves, more hit points (printed p. 61).
inline int denLegendHdBonus(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 15;
        case 3:
            return 20;
        case 4:
            return 25;
        default:
            return -99;
        }
    }

// the Table 12 body-area hit-point multiplier x10 for the rank (15 = x1.5, 35
// = x3.5), the number after the slash for hydras and beholders (printed p.
// 61).
inline int denLegendMult(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 20;
        case 2:
            return 25;
        case 3:
            return 30;
        case 4:
            return 35;
        default:
            return -99;
        }
    }

// the Table 13 low end of the average-damage band for the rank (printed pp.
// 62-63).
inline int denBreathDmgLow(int b)
    {
        switch (b) {
        case 0:
            return 26;
        case 1:
            return 36;
        case 2:
            return 46;
        case 3:
            return 56;
        case 4:
            return 66;
        default:
            return -99;
        }
    }

// the Table 13 high end of the average-damage band for the rank (printed pp.
// 62-63).
inline int denBreathDmgHigh(int b)
    {
        switch (b) {
        case 0:
            return 35;
        case 1:
            return 45;
        case 2:
            return 55;
        case 3:
            return 65;
        case 4:
            return 75;
        default:
            return -99;
        }
    }

// the Table 13 saving-throw modifier for the rank, non-damaging breath
// weapons only (printed pp. 62-63).
inline int denBreathSave(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return -3;
        case 2:
            return -4;
        case 3:
            return -5;
        case 4:
            return -6;
        default:
            return -99;
        }
    }

// the Table 13 cloud length in feet for the rank (printed pp. 62-63).
inline int denBreathCloudFt(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 40;
        case 2:
            return 50;
        case 3:
            return 60;
        case 4:
            return 70;
        default:
            return -99;
        }
    }

// the Table 13 cone length in feet for the rank (printed pp. 62-63).
inline int denBreathConeFt(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 55;
        case 2:
            return 70;
        case 3:
            return 85;
        case 4:
            return 100;
        default:
            return -99;
        }
    }

// the Table 13 line length in feet for the rank (printed pp. 62-63).
inline int denBreathLineFt(int b)
    {
        switch (b) {
        case 0:
            return 60;
        case 1:
            return 80;
        case 2:
            return 100;
        case 3:
            return 120;
        case 4:
            return 140;
        default:
            return -99;
        }
    }

// the Table 14 onset die count for the rank - always 1d4 (printed p. 63).
inline int denDiseaseOnsetCount(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        default:
            return -99;
        }
    }

// the Table 14 onset die size for the rank - always a d4 (printed p. 63).
inline int denDiseaseOnsetDie(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 4;
        default:
            return -99;
        }
    }

// the Table 14 onset unit code for the rank: 5 week, 4 day, 3 hour, 2 turn, 1
// round (printed p. 63).
inline int denDiseaseOnsetUnit(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 4;
        case 2:
            return 3;
        case 3:
            return 2;
        case 4:
            return 1;
        default:
            return -99;
        }
    }

// the Table 14 fatality die count for the rank (printed p. 63).
inline int denDiseaseFatalCount(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 1;
        default:
            return -99;
        }
    }

// the Table 14 fatality die size for the rank (printed p. 63).
inline int denDiseaseFatalDie(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 4;
        case 4:
            return 4;
        default:
            return -99;
        }
    }

// the Table 14 fatality unit code for the rank: 6 month, 5 week, 4 day, 3
// hour, 2 turn (printed p. 63).
inline int denDiseaseFatalUnit(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 5;
        case 2:
            return 4;
        case 3:
            return 3;
        case 4:
            return 2;
        default:
            return -99;
        }
    }

// the Table 15 fear radius in feet for the rank (printed p. 63).
inline int denFearRadiusFt(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 35;
        case 2:
            return 40;
        case 3:
            return 45;
        case 4:
            return 50;
        default:
            return -99;
        }
    }

// the Table 15 saving-throw modifier vs. spell for the rank (printed p. 63).
inline int denFearSave(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return -1;
        case 2:
            return -2;
        case 3:
            return -3;
        case 4:
            return -4;
        default:
            return -99;
        }
    }

// the Table 16 crush radius in feet for the rank (printed p. 63).
inline int denCrushRadiusFt(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 15;
        case 2:
            return 20;
        case 3:
            return 25;
        case 4:
            return 30;
        default:
            return -99;
        }
    }

// the Table 16 crush damage die count for the rank (printed p. 63).
inline int denCrushDice(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 5;
        case 3:
            return 6;
        case 4:
            return 7;
        default:
            return -99;
        }
    }

// the Table 16 crush damage die size for the rank - always a d8 (printed p.
// 63).
inline int denCrushDieSize(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 8;
        case 2:
            return 8;
        case 3:
            return 8;
        case 4:
            return 8;
        default:
            return -99;
        }
    }

// the Table 17 bleeding damage die count per round for the rank (printed p.
// 65).
inline int denWoundCount(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 2;
        default:
            return -99;
        }
    }

// the Table 17 bleeding damage die size per round for the rank - 0 where the
// count stands alone (printed p. 65).
inline int denWoundDie(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 4;
        case 3:
            return 8;
        case 4:
            return 6;
        default:
            return -99;
        }
    }

// the Table 18 damage bonus per die for the rank (printed p. 65).
inline int denMeleeBonusPerDie(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 3;
        default:
            return -99;
        }
    }

// the Table 18 extra damage dice for the rank on top of the per-die bonus
// (printed p. 65).
inline int denMeleeExtraDice(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 2;
        default:
            return -99;
        }
    }

// the Table 18 size percentage for the rank (printed p. 65).
inline int denMeleeSizePct(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 20;
        case 2:
            return 30;
        case 3:
            return 40;
        case 4:
            return 50;
        default:
            return -99;
        }
    }

// the Table 19 movement-rate percentage for the rank (printed p. 66).
inline int denMovePct(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 30;
        case 2:
            return 40;
        case 3:
            return 50;
        case 4:
            return 60;
        default:
            return -99;
        }
    }

// the Table 20 saving-throw modifier for the rank (printed p. 66).
inline int denGazeSave(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return -3;
        case 2:
            return -4;
        case 3:
            return -5;
        case 4:
            return -6;
        default:
            return -99;
        }
    }

// the Table 21 magic-resistance percentage for the rank (printed p. 66).
inline int denResistPct(int b)
    {
        switch (b) {
        case 0:
            return 60;
        case 1:
            return 70;
        case 2:
            return 80;
        case 3:
            return 90;
        case 4:
            return 100;
        default:
            return -99;
        }
    }

// the Table 22 hit points regenerated per round for the rank (printed p. 66).
inline int denRegenPerRound(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        default:
            return -99;
        }
    }

// the Table 22 regeneration delay in rounds after the first wound - the
// lesser scion's printed three, 0 elsewhere (printed p. 66).
inline int denRegenDelayRounds(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        default:
            return -99;
        }
    }

}   // namespace rules
