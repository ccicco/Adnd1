// =========================================================================================
// Adnd1 - rules/dsgmove.h
// The DSG MOVEMENT CHAPTER PART I, R504: the printed pp. 12-19 (pdf 13-20)
// first half of the movement chapter - the ability/proficiency check frames,
// the swimming block with TABLE 1 SWIMMING EFFECTS OF ENCUMBRANCE, the breath
// economy, the moving-water effects, the climbing block with TABLE 2 RATES OF
// CLIMBING and TABLE 3 GRAPPLING SUCCESS and the rappel, the non-acrobat
// jumping with TABLE 4 BROAD JUMPING, and the rope system (the chasm crossing
// with TABLE 5 CROSSING WITH A GRAPPLE and TABLE 6 THROWN LOOP RANGES, the
// swing, the belay, the roping-together cascade). The movement chapter parent
// stays open: bridges, the expanded falling rules, spelunking, excavation,
// fatigue, darkness and slippery surfaces ride the next round.
// census 428 -> 429.
//
// the DSG scan (the user own copy), printed pp. 12-19 = pdf 13-20, pulled
// per-page on the r504-extraction branch with the tsv confidence tables and
// the 300-dpi page images under extract/r504/ on main; the damaged grid cells
// (the Table 1 encumbered row, the Table 2 mid-column, the Table 4 top bands)
// confirmed by the table crops (t1-014 through t9-023). CAUTION carried from
// the extraction: the Table 2 slightly-slippery cells of the last four rows
// came from image reads where the tsv showed a misread 0; the 36/24, 60/40,
// 60/30, 40/30 pattern was confirmed twice by image. The printed dive example
// says heavy gear TRIPLES the dive rate where the Table 1 heavy row DOUBLES
// it: the table is the authority (the R501 precedent), the example pinned as
// printed with the tension noted.
//
// THE SETTLE: census 428 -> 429; the gap report 5/150 -> 27 closed / 128 open
// (the sixteen movement-chapter boxes from the check frames through roping
// together, plus the six manifest tables 1-6; the movement parent box stays
// open for the next round). CROSS-BOOK SEAM: Table 1 verified const-for-const
// against rules/wsgswim.h, the breath against rules/wsgbreath.h, the moving
// water against rules/wsgmwater.h, the rappel against rules/wsgrapp.h, the
// loop against rules/wsgchasm.h, the belay against rules/wsgbelay.h, the
// cascade against rules/wsgtog.h and the jump floors against rules/wsgjump.h
// - two divergences pin under dmv: the strength speed bonus keyed on the
// DAMAGE bonus (the WSG keys on strength bands; both cap +3) and the
// encumbered -4 jump allowed (the WSG forbids severe jumps).
//
namespace rules {

// ---- the chapter opener and the check frames ----

// the movement chapter part I spans printed pp. 12-19: the swimming, breath,
// moving water, climbing, jumping and rope halves, through roping together.
inline int dmvPart1Lo()
    { return 12; }

// the part I chapter matter ends at printed p. 19; bridges, the expanded
// falling rules, spelunking, excavation, fatigue, darkness and slippery
// surfaces ride the next round.
inline int dmvPart1Hi()
    { return 19; }

// the part I pdf pages start at 13 (the offset: pdf = printed + 1, pinned at
// R503).
inline int dmvPart1PdfLo()
    { return 13; }

// the part I pdf pages end at 20.
inline int dmvPart1PdfHi()
    { return 20; }

// an ability check is rolled on 1d20.
inline int dmvCheckDie()
    { return 20; }

// the ability check is successful if the roll is equal to or less than the
// ability in question.
inline bool dmvAbilityCheckEqualOrLess()
    { return true; }

// occasionally an ability check calls for a certain combination of dice, as
// in a 4d6 dexterity check; the listed dice are substituted for the d20, and
// the purpose is still to roll the attribute score or less.
inline bool dmvSubstituteDiceOk()
    { return true; }

// a proficiency check is rolled on 1d20 and compared to the character rating
// in the given proficiency: rolls LESS than the rating are successful - the
// strict inequality that distinguishes the proficiency check from the
// equal-or-less ability check.
inline bool dmvProfCheckStrictlyLess()
    { return true; }

// all of these rules assume the character uses no magical assistance; the
// effects of such devices, when used, always take precedence over a character
// innate swimming abilities.
inline bool dmvNoMagicAssumed()
    { return true; }

// ---- the swimming proficiency and the three functions ----

// for humanoid monsters, assume a 1/3 chance that the creatures are able to
// swim (the numerator).
inline int dmvMonsterSwimNum()
    { return 1; }

// the denominator of the humanoid-monster swimming chance: 1/3.
inline int dmvMonsterSwimDen()
    { return 3; }

// the swimming ability is divided into three functions: endurance (how long),
// speed (how fast) and diving (how deep in a single round).
inline int dmvSwimFuncCount()
    { return 3; }

// a character swimming completely underwater has his speed reduced to 2/3 of
// the maximum (the numerator).
inline int dmvUnderwaterRateNum()
    { return 2; }

// the denominator of the underwater speed cut: 2/3 of the maximum.
inline int dmvUnderwaterRateDen()
    { return 3; }

// characters without swimming proficiency are unable to remain afloat in
// water and drown in deep water unless they are aided.
inline bool dmvSwimProfRequiredAfloat()
    { return true; }

// a character does not need swimming proficiency to be able to hold his
// breath.
inline bool dmvBreathHeldWithoutProf()
    { return true; }

// almost all animals can swim, if forced to; wolves and other canines
// willingly follow prey into water, while most felines swim only in
// desperation.
inline bool dmvAnimalsSwimIfForced()
    { return true; }

// certain creatures - fire- and stone-based monsters in particular - never
// enter the water.
inline bool dmvFireStoneNeverEnter()
    { return true; }

// endurance reflects how long a character can continue swimming without
// resting, and assumes that he can breathe while swimming, i.e. is not
// swimming through a completely water-filled passage.
inline bool dmvEnduranceNeedsBreath()
    { return true; }

// the encumbrance categories match those described in the players handbook,
// page 101.
inline bool dmvEncCategoriesMatchPhb()
    { return true; }

// an encumbered character cannot move through the water under his own power;
// if he enters the water, he will sink (the Table 1 footnote).
inline bool dmvEncumberedSinks()
    { return true; }

// ---- the swimming endurance and speed ----

// the printed example: a fighter/magic-user of levels 6/5 with a CON score of
// 12 could swim 23 turns when carrying normal gear.
inline int dmvEndurExampleTurns()
    { return 23; }

// completely unencumbered the same character could swim for 46 turns - the
// Table 1 doubled endurance.
inline int dmvEndurExampleUnencTurns()
    { return 46; }

// the endurance of a character swimming at high speed is reduced to 1/10 of
// its original value.
inline int dmvHighSpeedEndDiv()
    { return 10; }

// the speed with which a character can swim begins at a base 4 inches per
// round for humans.
inline int dmvHumanSwimIn()
    { return 4; }

// the base swimming speed is 3 inches per round for demihumans and humanoids.
inline int dmvDemiSwimIn()
    { return 3; }

// the strength bonus added to swimming speed can never exceed +3 inches, even
// if the character damage bonus is greater.
inline int dmvStrSpeedBonusMaxIn()
    { return 3; }

// the printed example: a human character with a strength of 16 has a damage
// bonus of +1.
inline int dmvStrExBonusIn()
    { return 1; }

// the strength-16 human could thus swim at 5 inches per round.
inline int dmvStrExSpeedIn()
    { return 5; }

// a character swimming endurance is calculated by adding his total experience
// levels to his constitution score - the number of turns he can swim without
// rest.
inline bool dmvEnduranceLevelsPlusCon()
    { return true; }

// a character who is only attempting to stay afloat by treading water doubles
// the number of turns of his swimming endurance.
inline bool dmvTreadingDoublesEndurance()
    { return true; }

// when a character runs out of endurance he will drown unless he can get out
// of deep water or find some means of staying afloat.
inline bool dmvEndurOutMeansDrown()
    { return true; }

// a character can elect to swim at high speed, doubling his rate of movement
// with the endurance penalty.
inline bool dmvHighSpeedDoublesRate()
    { return true; }

// immediately upon exiting the water, the high-speed swimmer must spend as
// much time resting as he spent swimming at high speed.
inline bool dmvHighSpeedRestEqual()
    { return true; }

// the strength bonus added to swimming speed is the strength DAMAGE bonus
// (the strength-16 +1 example swims at 5 inches) - the DSG keys the speed
// bonus on the damage bonus where the WSG keyed it on strength bands; a
// pinned cross-book divergence, both cap at +3.
inline bool dmvStrBonusIsDamageBonus()
    { return true; }

// ---- the diving and surfacing rules ----

// a character can normally swim downward 20 feet in a game round.
inline int dmvDiveRateFt()
    { return 20; }

// a character jumping or diving into the water from a place within a few feet
// of the surface can add 10 feet to the depth achieved on the first round.
inline int dmvJumpDiveBonusFt()
    { return 10; }

// for each 10 feet of height above the water surface, an additional depth can
// be added.
inline int dmvPerHeightFt()
    { return 10; }

// the additional depth per 10 feet of height: 5 feet.
inline int dmvHeightDepthBonusFt()
    { return 5; }

// the height additions run to a maximum of a 40-foot-high jump.
inline int dmvMaxJumpHeightFt()
    { return 40; }

// the printed dive example: the normal-gear character achieves a depth of 30
// feet after the first round - the 20-foot rate plus the 10-foot jump-in
// bonus.
inline int dmvExampleDiveNormalFt()
    { return 30; }

// the heavy-gear character sinks 60 additional feet after the jump, depth 70
// after the first round - pinned as printed; NOTE the example text says his
// encumbrance TRIPLES the diving rate while the Table 1 heavy row DOUBLES it
// (the table is the authority, the R501 precedent; the very heavy row is the
// triple).
inline int dmvExampleDiveHeavyFt()
    { return 70; }

// the rate at which a character can surface from a dive is 20 feet per round
// with normal encumbrance.
inline int dmvSurfaceRateFt()
    { return 20; }

// a character who is simply floating upward (an unconscious character, for
// example) moves five feet per round slower.
inline int dmvPassiveFloatSlowerFt()
    { return 5; }

// it takes one round to remove a backpack under water.
inline int dmvBackpackRemoveRounds()
    { return 1; }

// subtract the armor class of the armor (not including magical bonuses or
// shield) from 10 to determine the rounds required to remove it under water.
inline int dmvArmorRemoveBase()
    { return 10; }

// the printed example: a sinking character in chain mail (AC 5) can remove
// the armor in five rounds.
inline int dmvArmorExampleRounds()
    { return 5; }

// the depth attainable on a diving round can be modified by encumbrance, as
// explained on Table 1.
inline bool dmvDiveModifiedByEnc()
    { return true; }

// the additions for diving into water are not modified by encumbrance: a
// character jumping into the water can dive an extra 10 feet regardless of
// whether he is completely unencumbered or carrying heavy gear.
inline bool dmvJumpBonusUnmodifiedByEnc()
    { return true; }

// the surfacing rate is modified by unusual encumbrance as shown on Table 1,
// and assumes the character is actively working to return to the surface.
inline bool dmvSurfaceModifiedByEnc()
    { return true; }

// a character encumbered with heavy gear or greater must actively swim for
// the surface, or he does not rise at all.
inline bool dmvHeavyMustActivelySwim()
    { return true; }

// a character can intentionally load himself down (with rocks, etc.) to aid a
// dive and release the added weight when he wants to surface; the DM must
// decide how heavily the character must load himself to reach a certain
// encumbrance category.
inline bool dmvIntentionalLoadingDmJudged()
    { return true; }

// ---- Table 1: the swimming encumbrance grid ----

// Table 1 has five encumbrance rows: unencumbered, normal gear, heavy gear,
// very heavy gear and encumbered.
inline int dmvT1RowCount()
    { return 5; }

// The numerator of the endurance multiplier by encumbrance row (0 = the
// printed none, impossible).
inline int dmvT1EndNum(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 0;
        default:
            return 1;
        }
    }

// The denominator of the endurance multiplier: doubled, normal, halved,
// quartered, none.
inline int dmvT1EndDen(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 4;
        case 4:
            return 1;
        default:
            return 1;
        }
    }

// The numerator of the speed multiplier by encumbrance row (0 = the printed
// none).
inline int dmvT1SpdNum(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 0;
        default:
            return 1;
        }
    }

// The denominator of the speed multiplier: doubled, normal, halved,
// quartered, none.
inline int dmvT1SpdDen(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 4;
        case 4:
            return 1;
        default:
            return 1;
        }
    }

// The numerator of the diving multiplier - the one function that survives
// every encumbrance: normal, normal, doubled, tripled, tripled.
inline int dmvT1DiveNum(int b)
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
            return 3;
        default:
            return 1;
        }
    }

// The denominator of the diving multiplier (always 1).
inline int dmvT1DiveDen(int b)
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
            return 1;
        }
    }

// The numerator of the surfacing multiplier by encumbrance row (0 = the
// printed none).
inline int dmvT1SurfNum(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 0;
        default:
            return 1;
        }
    }

// The denominator of the surfacing multiplier: doubled, normal, halved,
// quartered, none.
inline int dmvT1SurfDen(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 4;
        case 4:
            return 1;
        default:
            return 1;
        }
    }

// ---- the breath economy ----

// a character who has taken a large breath of air and is not performing
// strenuous exercise can hold his breath for a number of rounds equal to 1/3
// his constitution score, rounded up.
inline int dmvBreathConDiv()
    { return 3; }

// a character is always able to hold his breath for at least one round.
inline int dmvMinBreathRounds()
    { return 1; }

// each round after his breath runs out the character makes a constitution
// check to stay alive: the first check has no modifiers, with a -2 cumulative
// modifier each round thereafter, until he leaves the water or fails a check
// and dies.
inline int dmvBreathCheckStep()
    { return 2; }

// the printed example: a character with a 16 constitution can hold his breath
// underwater for six rounds; the 7th-round check is unmodified, the 8th at
// -2, the 9th at -4, the 10th at -6.
inline int dmvBreathExampleRounds()
    { return 6; }

// the breath durations and their halvings are all rounded up: the 1/3
// constitution base, the strenuous halving and the no-breath halving.
inline bool dmvBreathRoundedUp()
    { return true; }

// a character cannot be fully encumbered while performing the nonstrenuous
// breath-holding functions (normal movement, searching for secret doors,
// picking a lock).
inline bool dmvFullyEncumBreathBarred()
    { return true; }

// strenuous exercise (fighting, subduing, lifting or moving a heavy weight,
// moving at high speed) cuts the underwater time in half, rounded up -
// cumulative with the no-breath halving.
inline bool dmvStrenuousHalvesBreath()
    { return true; }

// fully encumbered characters underwater are always considered to be
// performing strenuous exercise.
inline bool dmvFullyEncumAlwaysStrenuous()
    { return true; }

// a character without a chance to take a deep breath before submerging has
// his underwater time halved (rounded up), cumulative with the strenuous
// halving.
inline bool dmvNoDeepBreathHalves()
    { return true; }

// a character does not immediately die when his breath runs out: each round
// after, he makes the constitution check to stay alive with the -2 cumulative
// step.
inline bool dmvConCheckAfterBreath()
    { return true; }

// holding breath in nonswimming situations (to avoid breathing the
// surrounding air) uses the swimming formula but adds one round.
inline bool dmvNonswimBreathPlusOne()
    { return true; }

// characters cannot use breath-holding to avoid the effects of a gas unless
// they suspect that a gas is about to be released.
inline bool dmvCantAvoidUnsuspectedGas()
    { return true; }

// ---- the moving water effects ----

// the printed example: a stream flowing 40 feet per round will carry swimming
// characters along at that speed, plus or minus their swimming speeds.
inline int dmvExampleStreamFt()
    { return 40; }

// by swimming upstream at the normal human swimming speed of 4 inches per
// round, a character could manage to stay in the same position relative to
// the banks.
inline int dmvUpstreamHoldIn()
    { return 4; }

// dwarves and halflings with normal swimming speeds of 3 inches per round
// will be washed downstream 10 feet in the sample stream, even spending the
// entire round swimming upstream.
inline int dmvExampleWashdownFt()
    { return 10; }

// a character carried over a waterfall receives half the normal amount of
// damage for the distance of the fall.
inline int dmvWaterfallDamageDiv()
    { return 2; }

// with a successful save vs. breath weapon: if the fall is 100 feet or less,
// the character receives no damage from the plunge.
inline int dmvShortPlungeMaxFt()
    { return 100; }

// if the drop is greater than 100 feet, the saved character only receives
// 1/10 the normal damage for such a fall.
inline int dmvLongPlungeDiv()
    { return 10; }

// the DM rates the danger of a rapid, rock-filled stream with a number from
// one to 10, one being the most dangerous.
inline int dmvDangerRatingLo()
    { return 1; }

// the top of the danger rating range: 10.
inline int dmvDangerRatingHi()
    { return 10; }

// whenever a character fails a swimming check in a dangerous stream, the
// pounding against the rocks causes 1d6 points of damage.
inline int dmvRockDmgDie()
    { return 6; }

// a character swimming speed is relative to the water he occupies: the stream
// carries him along at its speed plus or minus his swimming speed.
inline bool dmvSpeedRelativeToWater()
    { return true; }

// extremely rapid streams can move characters with enough momentum to do them
// considerable harm; until the character hits something, the water might
// prove a fast and direct form of transportation - submerged rocks and
// subterranean waterfalls change that impression quickly.
inline bool dmvRapidTransportUntilImpact()
    { return true; }

// a character carried over a waterfall receives half the normal damage for
// the distance of the fall, except that a saving throw vs. breath weapon is
// allowed, with the avoid-the-obstacles results.
inline bool dmvWaterfallSaveVsBreath()
    { return true; }

// the stream danger rating tells how often a character must make a swimming
// proficiency check: the time between checks in rounds equals the rating - a
// stream rated one requires a check every round, one rated four every four
// rounds.
inline bool dmvDangerRatingIsCadence()
    { return true; }

// in a stream rated five or less, characters must swim at high speed.
inline bool dmvLowRatingForcesHighSpeed()
    { return true; }

// ---- the climbing surfaces and conditions ----

// a pole diameter cannot be greater than 1/4 the height of the character
// attempting to climb it, unless the character uses a rope.
inline int dmvPoleDiaDiv()
    { return 4; }

// even if the save vs. petrification after a fall on a sloping wall is
// unsuccessful, the fall only inflicts half of the normal damage.
inline int dmvSlopeFallDiv()
    { return 2; }

// slightly slippery surfaces are wet or crumbly: the chance of a character
// falling from one is twice normal.
inline int dmvSlightFallMult()
    { return 2; }

// slippery surfaces (running water, slime or algae, frost, ice or grease): a
// thief character chance of falling on one is ten times his normal chance.
inline int dmvSlipFallMult()
    { return 10; }

// the printed example: a 3rd-level thief would make a normal climb walls roll
// at 87 percent.
inline int dmvExThiefRoll()
    { return 87; }

// the 3rd-level thief normal chance of failure: 13 percent.
inline int dmvExFailurePct()
    { return 13; }

// on a slightly slippery surface the thief has a 26 percent chance of
// failure, needing a roll of 74 or less for success.
inline int dmvExSlightFailPct()
    { return 26; }

// on a slippery surface a thief of 10th level only succeeds on a 90 or less.
inline int dmvExSlipRoll10()
    { return 90; }

// the 10th-level thief normal success roll: 99 or less.
inline int dmvExNormalRoll10()
    { return 99; }

// characters with heavy gear or very heavy gear move at half the movement
// rates listed for climbing characters.
inline int dmvHeavyClimbDiv()
    { return 2; }

// non-thief characters have a base climbing rating of 40 percent and use the
// same procedure as thieves, but with a lesser chance of success.
inline int dmvNonThiefRatingPct()
    { return 40; }

// members of all character classes have a limited ability to move up and down
// steep slopes, provided hand and footholds are available.
inline bool dmvAllClassesLimitedClimb()
    { return true; }

// only thieves have the capability to ascend sheer walls, cliffs and the
// like.
inline bool dmvOnlyThievesSheer()
    { return true; }

// other characters may try to climb very rough stone surfaces, as well as
// trees, poles, ropes and other simple routes.
inline bool dmvNonThiefRoughRoutes()
    { return true; }

// the mountaineering proficiency can increase climbing abilities for both
// thieves and non-thieves.
inline bool dmvMountaineerBoosts()
    { return true; }

// walls that are very smooth, smooth with cracks, or rough can only be
// climbed by thieves, unless characters are using ropes, spikes or other
// tools.
inline bool dmvThiefOnlySmoothTypes()
    { return true; }

// ice walls can only be climbed by characters (including thieves) using
// tools.
inline bool dmvIceNeedsTools()
    { return true; }

// in all instances the Table 2 rates are for thieves only; all other
// characters move at half the thief rates.
inline bool dmvThiefOnlyRates()
    { return true; }

// all characters can add their dexterity reaction/attacking adjustments to
// their rate of climbing.
inline bool dmvDexAdjAddsToRate()
    { return true; }

// any pole with tree bark still attached is considered a nonslippery surface.
inline bool dmvBarkNonslippery()
    { return true; }

// a rope only falls into the pole category if the character cannot brace his
// feet against a wall or some other surface to aid the climb.
inline bool dmvRopeOnlyUnbracedCat()
    { return true; }

// if a character falls while on a sloping wall surface, he can make a saving
// throw vs. petrification; if the save is successful, he takes no damage from
// the fall.
inline bool dmvSlopeSaveVsPetr()
    { return true; }

// nonslippery surfaces are dry and solid; they do not crumble when touched,
// and a character chance of falling is calculated at the normal rate.
inline bool dmvNonslipperyDrySolid()
    { return true; }

// encumbered characters cannot climb sheer surfaces without the aid of tools.
inline bool dmvEncumbNoSheerWithoutTools()
    { return true; }

// the heavy-gear and very-heavy-gear climbing halving is cumulative with all
// other effects.
inline bool dmvHeavyGearHalfRate()
    { return true; }

// characters with no gear or normal gear can utilize the full climbing
// movement rates.
inline bool dmvNormalGearFullRate()
    { return true; }

// the non-thief climbing check is rolled on 1d100 against the modified
// climbing rating: a result greater than the rating indicates failure, a
// result less than or equal to the rating means success.
inline bool dmvNonThiefCheckEqualOrLess()
    { return true; }

// if a climbing check fails, the character can never climb that wall.
inline bool dmvFailMeansNeverClimb()
    { return true; }

// even a failed climbing attempt requires one round of game time.
inline bool dmvFailCostsOneRound()
    { return true; }

// ---- Table 2: the rates of climbing grid ----

// Table 2 has nine surface rows: very smooth, smooth with cracks, rough,
// rough with ledges, ice wall, pole, tree with branches, sloping wall, and
// rope and wall.
inline int dmvClimbRowCount()
    { return 9; }

// The nonslippery climbing rate in feet per round by surface row: 6, 12, 18,
// 24, dash, 36, 60, 60, 40 (0 = the printed dash, thieves with tools only for
// ice).
inline int dmvT2NonslipFt(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 12;
        case 2:
            return 18;
        case 3:
            return 24;
        case 4:
            return 0;
        case 5:
            return 36;
        case 6:
            return 60;
        case 7:
            return 60;
        case 8:
            return 40;
        default:
            return 0;
        }
    }

// The slightly slippery rate in feet per round by surface row: 3, 6, 9, 12,
// dash, 24, 40, 30, 30 (0 = the printed dash).
inline int dmvT2SlightFt(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 6;
        case 2:
            return 9;
        case 3:
            return 12;
        case 4:
            return 0;
        case 5:
            return 24;
        case 6:
            return 40;
        case 7:
            return 30;
        case 8:
            return 30;
        default:
            return 0;
        }
    }

// The slippery rate in feet per round by surface row: 0, 3, 6, 9, 6, 12, 20,
// 15, 20 (0 = the printed dash).
inline int dmvT2SlipFt(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 3;
        case 2:
            return 6;
        case 3:
            return 9;
        case 4:
            return 6;
        case 5:
            return 12;
        case 6:
            return 20;
        case 7:
            return 15;
        case 8:
            return 20;
        default:
            return 0;
        }
    }

// ---- the climbing modifiers ----

// characters in chain, splint, scale or banded armor can climb, but suffer a
// -15 percent penalty to their chance for success.
inline int dmvArmorMidPct()
    { return 15; }

// characters in studded leather or padded armor suffer a -5 percent to their
// chances.
inline int dmvArmorLightPct()
    { return 5; }

// the race climbing modifier: dwarf -5 percent.
inline int dmvDwarfPct()
    { return 5; }

// the race climbing modifier: gnome -10 percent.
inline int dmvGnomePct()
    { return 10; }

// the race climbing modifier: halfling -5 percent.
inline int dmvHalflingPct()
    { return 5; }

// the race climbing modifier: half-orc +5 percent.
inline int dmvHalforcPct()
    { return 5; }

// the climbing surface bonus: tree with branches +40 percent.
inline int dmvTreeModPct()
    { return 40; }

// the climbing surface bonus: sloping wall +25 percent.
inline int dmvSlopeModPct()
    { return 25; }

// the climbing surface bonus: pole +20 percent.
inline int dmvPoleModPct()
    { return 20; }

// the climbing surface bonus: rope and wall +40 percent.
inline int dmvRopeWallModPct()
    { return 40; }

// characters cannot climb in any type of plate mail armor, nor can a shield
// be held by a climbing character.
inline bool dmvNoPlateNoShield()
    { return true; }

// leather armor does not penalize a climber.
inline bool dmvLeatherNoPenalty()
    { return true; }

// a character can sling a shield over his shoulder to carry it along while
// climbing, but cannot receive any defensive benefit for a shield thus
// carried.
inline bool dmvShieldSlungNoBenefit()
    { return true; }

// ---- the climbing tools ----

// a spike takes 1d4 rounds to hammer into a wall surface.
inline int dmvSpikeRoundsDie()
    { return 4; }

// the clanging of a hammered spike can be heard up to a mile away in windless
// conditions.
inline int dmvSpikeNoiseMi()
    { return 1; }

// whenever a spike is called upon to arrest a fall, there is a 10 percent
// chance per character supported that it will give way; if it comes free, the
// characters fall the full distance (or twice the distance to the next
// spike).
inline int dmvSpikeFailPct()
    { return 10; }

// the printed example: two characters roped together and relying upon one
// spike to arrest their fall give the spike a 20 percent chance of popping
// free.
inline int dmvSpikeExamplePct()
    { return 20; }

// any character whose fall is broken by a rope suffers only half the damage a
// fall of that distance would normally inflict.
inline int dmvRopeFallDiv()
    { return 2; }

// spikes placed in ice have a 15 percent chance of pulling free per character
// whose weight suddenly pulls against them.
inline int dmvIceSpikeFailPct()
    { return 15; }

// a character can throw a grappling hook upward a distance equal to 1/3 of
// his strength score, rounded up, times 10.
inline int dmvGrappleStrDiv()
    { return 3; }

// the strength-to-feet multiplier of the grappling hook throw: 1/3 strength
// times 10 feet.
inline int dmvGrappleMultFt()
    { return 10; }

// the printed example: a character with a strength of 15 could throw the hook
// up to a height of 50 feet.
inline int dmvGrappleExampleFt()
    { return 50; }

// with a radius of 10 feet from his body cleared of obstacles for swinging
// the hook in a circle before the cast.
inline int dmvSwingThrowRadiusFt()
    { return 10; }

// the character can throw the hook twice as far horizontally as he could
// otherwise.
inline int dmvSwingThrowMult()
    { return 2; }

// if a grappling hook cast is unsuccessful, it takes another 1d4 rounds to
// coil the rope and prepare the hook for another throw.
inline int dmvRecoilDie()
    { return 4; }

// if a character is directly underneath his target and the dice roll on the
// throw is 01-05.
inline int dmvSelfHitLoPct()
    { return 1; }

// the top of the self-hit throw range: 01-05.
inline int dmvSelfHitHiPct()
    { return 5; }

// the thrower is struck by the hook as it falls and suffers 1d6 of damage.
inline int dmvSelfHitDie()
    { return 6; }

// a successful grappling hook throw is audible for 100-400 yards in ideal
// conditions.
inline int dmvHookNoiseLoYd()
    { return 100; }

// the top of the successful-throw noise range: 400 yards.
inline int dmvHookNoiseHiYd()
    { return 400; }

// an unsuccessful throw will raise a clang audible 200-800 yards away.
inline int dmvHookFailNoiseLoYd()
    { return 200; }

// the top of the failed-throw noise range: 800 yards.
inline int dmvHookFailNoiseHiYd()
    { return 800; }

// a catch-and-slip grapple will slip free after 1d6 rounds of supporting a
// load; characters who pull on the rope for that many rounds are able to
// dislodge the hook, if they take the time to check.
inline int dmvSlipFreeDie()
    { return 6; }

// the usual function of a spike is to shorten the distance a character falls:
// a spike 200 feet up a cliff with 50 feet of slack in the rope turns a fall
// beginning 50 feet higher into a 100-foot fall (50 down to the spike, 50
// more of slack).
inline bool dmvSpikeShortensFall()
    { return true; }

// characters can help prevent spike-arrest accidents by using more than one
// spike.
inline bool dmvUseMultipleSpikes()
    { return true; }

// climbing an ice wall absolutely requires spikes: a spike must be driven
// into the ice wall before a character can climb, the process must be
// repeated each round, and since it takes a round to drive a spike, the
// process is doubly slow.
inline bool dmvIceSpikeEachRound()
    { return true; }

// a rope wrapped around a too-wide pole and pulled against as he climbs lets
// a character climb a pole whose diameter equals his own height; any pole
// wider than this should be treated as a wall.
inline bool dmvPoleWrapTechnique()
    { return true; }

// ---- Table 3: the grappling success grid ----

// Table 3 has two grapple target rows: rocky ledge and wooden wall.
inline int dmvGrappleTargetCount()
    { return 2; }

// The miss maximum of the d100 grapple throw by target row: 01-88 miss on a
// rocky ledge, 01-70 on a wooden wall.
inline int dmvT3Miss(int b)
    {
        switch (b) {
        case 0:
            return 88;
        case 1:
            return 70;
        default:
            return 0;
        }
    }

// The catch-and-slip maximum by target row: 89-93 on a rocky ledge, 71-74 on
// a wooden wall.
inline int dmvT3Slip(int b)
    {
        switch (b) {
        case 0:
            return 93;
        case 1:
            return 74;
        default:
            return 0;
        }
    }

// The catch maximum by target row: 94-00 on a rocky ledge, 75-00 on a wooden
// wall.
inline int dmvT3Catch(int b)
    {
        switch (b) {
        case 0:
            return 100;
        case 1:
            return 100;
        default:
            return 0;
        }
    }

// ---- the rappelling rules ----

// to rappel successfully, the character must make a successful climbing check
// with a +50 percent modifier.
inline int dmvRappelModPct()
    { return 50; }

// a rappel can be made down a free-hanging rope, where the character has no
// wall to brace against, but in this case the modifier is only +30 percent.
inline int dmvFreeHangModPct()
    { return 30; }

// a character can rappel up to 120 feet per round.
inline int dmvRappelRateFt()
    { return 120; }

// a failed rappel climbing check means a fall from the top to the bottom of
// whatever distance is involved.
inline bool dmvRappelFailFallsFull()
    { return true; }

// all normal climbing restrictions (encumbrance, armor, etc.) apply to
// rappelling.
inline bool dmvRappelNormalRestrictions()
    { return true; }

// ---- the jumping rules ----

// a running broad jump requires a 20-foot head start.
inline int dmvRunHeadStartFt()
    { return 20; }

// in no case can jumping modifiers shorten a jump to less than two feet.
inline int dmvJumpFloorFt()
    { return 2; }

// characters carrying heavy gear subtract one foot from the distance of their
// jumps.
inline int dmvHeavyJumpFt()
    { return 1; }

// characters with very heavy gear subtract two feet from their jumping
// distance.
inline int dmvVeryHvyJumpFt()
    { return 2; }

// encumbered characters subtract four feet - the DSG allows the encumbered
// jump at a penalty where the WSG forbids severe jumps outright (a pinned
// cross-book divergence).
inline int dmvEncumbJumpFt()
    { return 4; }

// halflings must subtract one foot from their total jumping distance.
inline int dmvHalflingJumpFt()
    { return 1; }

// dwarves and gnomes must subtract two feet.
inline int dmvDwarfJumpFt()
    { return 2; }

// characters of all classes have a limited ability to jump across obstacles,
// the same procedure as given for acrobats (unearthed arcana page 24).
inline bool dmvAllClassesJump()
    { return true; }

// all jumps require only one segment of time.
inline bool dmvJumpOneSegment()
    { return true; }

// unlike acrobats, other characters cannot attempt to jump backward or leap
// in an extended position.
inline bool dmvNoBackwardOrExtended()
    { return true; }

// unencumbered characters and characters carrying normal gear have no
// penalties to their jumping abilities - the encumbrance ladder starts at
// heavy gear.
inline bool dmvJumpNoNormalPenalty()
    { return true; }

// humans, elves and half-orcs suffer no racial penalty on a jump.
inline bool dmvJumpNoRacialHumans()
    { return true; }

// ---- Table 4: the broad jumping grid and band chain ----

// Table 4 has seven level bands: 1-6, 7-9, 10-12, 13-15, 16-18, 19-22 and
// 23+.
inline int dmvJumpBandCount()
    { return 7; }

// the broad-jumping level band chain: levels 1-6 band 0, 7-9 band 1, 10-12
// band 2, 13-15 band 3, 16-18 band 4, 19-22 band 5, and 23 or up band 6 (the
// tail) - the band indexes the Table 4 rows.
inline int dmvJumpBand(int lvl)
    {
        if (lvl <= 6) return 0;
        if (lvl <= 9) return 1;
        if (lvl <= 12) return 2;
        if (lvl <= 15) return 3;
        if (lvl <= 18) return 4;
        if (lvl <= 22) return 5;
        return 6;
    }

// The standing broad jump die by level band (4 = 1d4, 6 = 1d6): 1d4 for the
// 1-6 and 7-9 bands, 1d6 for the 10-12 through 23+ bands.
inline int dmvT4StandDie(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 6;
        case 5:
            return 6;
        case 6:
            return 6;
        default:
            return 0;
        }
    }

// The standing broad jump plus feet by level band: 1, 2, 2, 3, 4, 5, 6 - the
// 1d4+1 through 1d6+6 ladder.
inline int dmvT4StandAdd(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 6;
        default:
            return 0;
        }
    }

// The running broad jump die by level band (4 = 1d4, 6 = 1d6).
inline int dmvT4RunDie(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 6;
        case 5:
            return 6;
        case 6:
            return 6;
        default:
            return 0;
        }
    }

// The running broad jump plus feet by level band: 5, 6, 5, 6, 9, 12, 15 - the
// 1d4+5 through 1d6+15 ladder.
inline int dmvT4RunAdd(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 6;
        case 2:
            return 5;
        case 3:
            return 6;
        case 4:
            return 9;
        case 5:
            return 12;
        case 6:
            return 15;
        default:
            return 0;
        }
    }

// ---- the chasm crossing on a rope ----

// if a random determination is needed, there is a base chance of 50 percent
// that a given crossing has some sort of protrusion for a tossed grappling
// hook to catch on.
inline int dmvProtrusionBasePct()
    { return 50; }

// the other end of the crossing rope can be tied off to a handy protrusion (a
// 50 percent chance of finding one), tied to a spike hammered into the stone,
// or held by a character.
inline int dmvTieoffProtrusionPct()
    { return 50; }

// a character crossing on a rope line is allowed a +30 percent modifier to
// his climbing rating for the check each round he is suspended.
inline int dmvRopeCrossModPct()
    { return 30; }

// the perennial rope problem is how to attach the rope to the far side:
// grapple-catchable irregularities are uncommon in a dungeon setting, more
// common in natural caves, and a once-bridged crossing invariably has
// wreckage of the bridge foundation to catch with a grappling hook.
inline bool dmvFarSideAnchorProblem()
    { return true; }

// the rope-tied-to-the-arrow trick is dashing and romantic but impractical:
// an arrow trailing a rope and fired into wood is simply not strong enough to
// support even the lightest of characters.
inline bool dmvArrowRopeImpractical()
    { return true; }

// a character crossing on such a line is in a precarious position indeed, and
// must make a climbing check each round that he is suspended.
inline bool dmvRopeCrossCheckEachRound()
    { return true; }

// on a rope crossing the modifiers for armor and encumbrance still apply to
// the climbing check.
inline bool dmvRopeCrossModsApply()
    { return true; }

// a rope is always considered a nonslippery surface.
inline bool dmvRopeAlwaysNonslippery()
    { return true; }

// the rate of climb listed for rope and wall applies to characters making a
// crossing on a rope.
inline bool dmvRopeWallRateApplies()
    { return true; }

// ---- Table 5: the crossing with a grapple grid ----

// Table 5 has three crossing target rows: bare stone walls or floor, cave
// formations, and ruined foundation.
inline int dmvCrossTargetCount()
    { return 3; }

// The miss maximum of the d100 crossing throw by target row: 01-82 bare stone
// walls/floor, 01-75 cave formations, 01-66 ruined foundation.
inline int dmvT5Miss(int b)
    {
        switch (b) {
        case 0:
            return 82;
        case 1:
            return 75;
        case 2:
            return 66;
        default:
            return 0;
        }
    }

// The catch-and-slip maximum by target row: 83-89, 76-80, 67-71.
inline int dmvT5Slip(int b)
    {
        switch (b) {
        case 0:
            return 89;
        case 1:
            return 80;
        case 2:
            return 71;
        default:
            return 0;
        }
    }

// The catch maximum by target row: 90-00, 81-00, 72-00.
inline int dmvT5Catch(int b)
    {
        switch (b) {
        case 0:
            return 100;
        case 1:
            return 100;
        case 2:
            return 100;
        default:
            return 0;
        }
    }

// ---- the thrown loop ----

// a suitable thrown-loop target is uncommon in a dungeon, but in a cave there
// is a base 20 percent chance that an appropriate stalagmite is located in a
// convenient position.
inline int dmvCaveTargetPct()
    { return 20; }

// the maximum thrown-loop range assumes the character has a clear radius of
// 10 feet around him to prepare the throw.
inline int dmvLoopPrepRadiusFt()
    { return 10; }

// the basic chance to hit with a thrown loop is 20 percent at maximum range.
inline int dmvLoopBaseHitPct()
    { return 20; }

// the thrown-loop chance is modified by +1 percent for each foot under
// maximum range.
inline int dmvLoopBonusPerFt()
    { return 1; }

// the printed example: the 7th-level character maximum range is 50 feet.
inline int dmvLoopExampleMaxFt()
    { return 50; }

// throwing a loop over a stalagmite some 30 feet distant, the 7th-level
// character has a 40 percent chance of success (20 plus the 20 feet under
// maximum).
inline int dmvLoopExamplePct()
    { return 40; }

// if a thrown loop is unsuccessful, the coiling of the rope for a second
// attempt takes 1d6 rounds.
inline int dmvLoopCoilDie()
    { return 6; }

// a thrown loop is a tricky maneuver that can only be attempted by thieves or
// other characters with a long and intimate familiarity with ropes
// (characters raised on farms, or who served as sailors).
inline bool dmvLoopThiefOrFamiliar()
    { return true; }

// the thrown-loop range is halved if the character does not have the clear
// 10-foot radius around him to prepare the throw.
inline bool dmvLoopRangeHalved()
    { return true; }

// a loop attempt takes one round; characters may make as many attempts as
// they wish, and the method carries the additional advantage of being
// virtually soundless.
inline bool dmvLoopAttemptOneRound()
    { return true; }

// ---- Table 6: the thrown loop ranges and band chain ----

// Table 6 has five level bands: 1-4, 5-8, 9-12, 13-16 and 17+.
inline int dmvLoopBandCount()
    { return 5; }

// the thrown-loop level band chain: levels 1-4 band 0, 5-8 band 1, 9-12 band
// 2, 13-16 band 3, and 17 or up band 4 (the tail) - the band indexes the
// Table 6 range rows.
inline int dmvLoopBand(int lvl)
    {
        if (lvl <= 4) return 0;
        if (lvl <= 8) return 1;
        if (lvl <= 12) return 2;
        if (lvl <= 16) return 3;
        return 4;
    }

// The maximum thrown-loop range in feet by level band: 40, 50, 60, 75, 90
// (non-acrobats).
inline int dmvLoopRangeFt(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 50;
        case 2:
            return 60;
        case 3:
            return 75;
        case 4:
            return 90;
        default:
            return 0;
        }
    }

// ---- the swinging across rules ----

// the swing-into-obstacle climbing check is modified by a -5 percent per 10
// feet of rope between the character and the point at which the rope is
// fastened.
inline int dmvSwingCheckStepPct()
    { return 5; }

// the rope-length step of the swing check: each 10 feet of rope costs 5
// percent.
inline int dmvSwingCheckPerFt()
    { return 10; }

// a character smashed into an obstacle during a swing takes 1d6 points of
// damage per 20-foot section of rope between him and the attached rope end.
inline int dmvSwingSectionFt()
    { return 20; }

// the swing damage die: 1d6 per 20-foot section of rope.
inline int dmvSwingDmgDie()
    { return 6; }

// a rope supported at one end swings to a point where it is hanging straight
// down; a weight attached to the rope is carried past that point by momentum,
// creating the pendulum motion that gives characters problems when they ram
// into a solid object during their swing.
inline bool dmvSwingPendulum()
    { return true; }

// if a character is holding a rope that swings into an obstacle, he must make
// an immediate climbing check to see if he can hold on; an unsuccessful check
// means he has been knocked off the rope and has fallen.
inline bool dmvSwingCheckToHold()
    { return true; }

// the swing damage drops all fractions: a character on a 15-foot rope
// receives no damage, and a character 35 feet down a rope suffers only 1d6
// points of damage.
inline bool dmvSwingDropFractions()
    { return true; }

// ---- the belaying rules ----

// the second belay check is required of belayers on a sheer surface of any
// kind, and also of characters on a level spot but within three feet of the
// edge of the sheer surface, when the fall pulls them in the direction of the
// drop-off.
inline int dmvBelayEdgeFt()
    { return 3; }

// each additional falling character on the rope subtracts 10 from the
// climbing success chance of the character attempting to belay.
inline int dmvBelayPerFallerPct()
    { return 10; }

// any character can attempt to protect another character against a fall with
// a belay; the only tool required is a rope, although spikes can add to the
// security of a belay.
inline bool dmvAnyoneCanBelay()
    { return true; }

// the character to be protected must have a rope tied securely around him;
// the character performing the belay holds the other end of the rope, but
// does not tie it to himself.
inline bool dmvBelayRopeTied()
    { return true; }

// the belayer pays out the rope slowly as the protected character moves
// farther away from him; if the protected character should fall, the belayer
// grabs the rope tightly and braces himself to try to catch the shock of the
// weight.
inline bool dmvBelayPaysOutSlack()
    { return true; }

// the belayer must roll a climbing check to arrest the fall: if successful,
// the rope is held and the other character can fall no farther than the
// length of the rope; if unsuccessful, the rope runs through the hands of the
// belayer too quickly and the fall proceeds normally.
inline bool dmvBelayCheckArrests()
    { return true; }

// a belayer who successfully holds the rope but occupies a dangerous or
// narrow spot must make a second climbing check to maintain his hold on
// whatever surface he is clinging to; if the second check is unsuccessful,
// the belayer joins his companion in the fall.
inline bool dmvBelaySecondCheck()
    { return true; }

// a belayer performing from a dangerous spot can use a spike to anchor
// himself: he performs the belay normally, and if he arrests the fall but
// fails his second check so that he is pulled into the fall, the spike should
// then catch both falling characters - with the standing 10 percent per
// supported character chance of pulling loose.
inline bool dmvBelaySpikeAnchored()
    { return true; }

// a belay can hold one end of a rope used for support, as in a chasm
// crossing: with a grappling hook fastening the far side and a belay
// established on the near side, characters cross as if the rope were attached
// at both ends, and the character holding the rope makes no checks.
inline bool dmvBelayBothEndsNoChecks()
    { return true; }

// ---- the roping together rules ----

// roping together ties the characters to a rope with 20 or 30 feet of slack
// between them.
inline int dmvRopeSlackLoFt()
    { return 20; }

// the top of the roping slack range: 30 feet between characters.
inline int dmvRopeSlackHiFt()
    { return 30; }

// when one character arrests the fall of two, the successful character must
// check again with a -10 modifier, and the character next to the second
// character to fall must make a climbing check to catch the two.
inline int dmvCascadePct()
    { return 10; }

// a party roped together insures that no single member will suffer a damaging
// fall; however, the group takes the risk of all members falling together.
inline bool dmvRopedNoSingleFall()
    { return true; }

// characters who are roped together must move at the rate of the slowest
// member, with the order of characters on the rope noted.
inline bool dmvRopedSlowestRate()
    { return true; }

// if one roped character falls, the characters on each side of him must make
// climbing checks: if both checks are successful the fall is stopped
// immediately; if one character arrests the fall but the other fails, the -10
// two-faller re-check follows.
inline bool dmvRopedBothSidesCheck()
    { return true; }

// each time the weight of a new character is added to those who have fallen,
// the characters who have not fallen but are adjacent to those falling must
// make climbing checks; this continues until a successful climbing check is
// made on each side of the falling characters, or until the entire party
// falls.
inline bool dmvRopedCascadeRecheck()
    { return true; }

// if a character or characters on the end of the rope fall, only the single
// character next to the falling character must make a check - it is more
// advantageous to have either the first or the last character fall,
// especially if the character next to him is a skilled climber.
inline bool dmvRopedEndSingleCheck()
    { return true; }

}   // namespace rules
