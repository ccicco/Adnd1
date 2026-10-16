// =========================================================================================
// Adnd1 - rules/wsgfatig.h
// R489: the WSG FATIGUE chapter slice, printed pp. 87-89 - the round CLOSING
// the wilderness combat chapter with the close-to-the-ground dismount tail
// and landing the FULL fatigue and exhaustion chapter: the character
// strenuous rhythm with the shrinking check intervals and the fatigue and
// exhaustion penalties with their recovery chains and the carried-rest rules,
// the land-based mount nourishment and overwork rules with the fatigued
// movement and armor class effects and the cumulative exhaustion chance with
// the collapse ladder and the trauma drain, and the flying-mount stamina
// rules with the 1d10 fatigue check and the steep-dive buffet and
// thrown-rider damage - the mounts and beasts of burden catalog rides to
// R490.
// census 413 -> 414.
//
// THE SETTLE: two-way clean on the first pass - the tesseract full-text
// reads, the pdftotext layout read and the tsv coordinate reads agree on
// every number (the 4-turn risk, the 2-turn rest, the 6-turn check, the 5
// more turns, the 1-turn step and minimum, the score drop of 2 with the
// 2-hour clear, the example scores 18 18 and 14 with the temporary 16 and
// effective 12, the per-turn check, the 1-hour exhausted recovery, the 2 and
// 3 day animal nutrition bars with the 8-hour rest, the 12-plus-2 overwork
// formula with the 18-hour horse example, the half rate with the 1-round
// bursts, the 3-inch terrain bar, the 7-to-9 armor class example, the 20
// percent cumulative chance with the 1-hour reset, the 25 50 75 collapse
// ladder, the flat 50 percent death chance within 1d4 hours, the 1d6-minus-3
// trauma drain through 8 hours with the 2-per-hour regain, the 24/6 black
// dragon with the 1-4 on 1d10, the 30-turn non-block window, the two-thirds
// rate with 10 yards per round, the 100-yard same-turn landing bar, the 1d2
// buffet per 10 yards, the 11-40 thrown damage as 3d10 plus 10, and the
// three-times 18-turn post-fatigue rest). The garbles settled without
// contest: the layout l d 4 l d 6 l d l O l d 2 and 1dlO classes are 1d4 1d6
// 1d10 and 1d2, Constutition and conscutive are the book typos for
// constitution and consecutive, 3 inches renders the 3-inch terrain bar, and
// hump(s) survives the hump-at glyph. The p. 87 cut turned out to be a column
// wrap WITHIN the page, not a page cut: the right column carries the Dungeon
// Master may allow a character with proficiency in riding the mount to leap
// from its back and land safely on the ground - the dismount section is
// complete and only the connective pin rides to this round.
//
// Bounds held: the fatigue score drop equals the exhausted extra drop equals
// the attack and save penalty, the shrinking check interval floors at the
// step size, the animal nutrition bars run 2 and 3 days with the 8-hour
// recovery, the overwork formula makes the 3-hour horse rest 18, the fatigued
// animal moves at half rate with the 3-inch bar and the two-place armor class
// example, the collapse ladder climbs 25 50 75 in equal steps, the trauma
// roll floors at zero with the 8-hour critical period, the black dragon
// stamina runs 24 turns in 4 hours and 6 turns in 1 hour, the 1d10 fatigue
// chance is 10 minus the rest number, the fatigued flying rate is two-thirds
// with the 100-yard same-turn landing bar, the thrown damage is exactly 3d10
// plus 10 spanning 11 to 40, and the post-fatigue rest is three times the
// normal period at 18 turns.
//
namespace rules {

// ---- The chapter opener ----

// even the strongest and hardiest characters and creatures cannot exert
// themselves indefinitely without becoming tired and needing rest; a long
// journey pressed too hard may exhaust the party long before the destination,
// and taking measures to avoid fatigue and exhaustion is not difficult and
// usually not inconvenient
inline bool wftOpenerThreat()
    { return true; }

// ---- The p. 87 dismount tail ----

// the R488 cut tail: if the flying mount dies close to the ground, the
// Dungeon Master may allow a character with proficiency in riding the mount
// to leap from its back and land safely on the ground
inline bool wftGroundDeathProficientLeap()
    { return true; }

// ---- Characters ----

// a character runs the risk of becoming fatigued whenever he engages in
// strenuous activity for more than four turns in succession
inline int wftStrenuousRiskTurns()
    { return 4; }

// to avoid the risk of fatigue a character must rest for two consecutive
// turns after four turns of strenuous activity
inline int wftAvoidRiskRestTurns()
    { return 2; }

// if the character chooses not to rest, he must make a Constitution Check
// after exerting himself for six consecutive turns
inline int wftFirstConCheckTurns()
    { return 6; }

// a successful check indicates he can remain active for at least five more
// turns
inline int wftSuccessExtraTurns()
    { return 5; }

// every time a check is successful, the time until the next required check is
// reduced by one turn
inline int wftCheckStepReductionTurns()
    { return 1; }

// the shrinking check interval bottoms out at a minimum of one turn
inline int wftCheckIntervalMinTurns()
    { return 1; }

// all of the ability scores of a fatigued character except comeliness are
// lowered by 2 until he rests for two consecutive hours
inline int wftFatigueScoreDrop()
    { return 2; }

// the fatigue penalties remain in effect until the character rests for two
// consecutive hours
inline int wftFatigueClearRestHours()
    { return 2; }

// the strength example: a character with 18 strength who becomes fatigued
// loses his +1 bonus on to-hit rolls and has his damage bonus reduced from +2
// to +1
inline int wftExampleStrScore()
    { return 18; }

// the constitution example: a fighter with 18 constitution who becomes
// fatigued immediately loses 2 hit points for each hit die he has, reflecting
// his temporary constitution of 16
inline int wftExampleConScore()
    { return 18; }

// the wisdom example: a cleric with 14 wisdom who becomes fatigued loses both
// of his bonus 1st-level spells, his effective wisdom now 12
inline int wftExampleWisScore()
    { return 14; }

// in addition to the ability-score penalties, a fatigued character suffers a
// -2 penalty on all attack rolls (to hit and damage) and saving throws
inline int wftFatigueAtkSavePenalty()
    { return 2; }

// a fatigued character continuing strenuous activity must make a Constitution
// Check once per turn, using his fatigue-reduced constitution score
inline int wftFatigueCheckEveryTurns()
    { return 1; }

// an exhausted character takes an additional -2 penalty on all of his ability
// scores, attack rolls and saving throws
inline int wftExhaustExtraScoreDrop()
    { return 2; }

// if an exhausted character rests for one hour without interruption, he can
// recover from exhaustion by making a successful Constitution Check with his
// temporarily reduced score
inline int wftExhaustRecoverRestHours()
    { return 1; }

// a character who recovers from exhaustion is only fatigued, and then
// recovers from fatigue by resting for another two hours
inline int wftFatigueAfterExhaustRestHours()
    { return 2; }

// a character moving at greater than his full normal movement rate is engaged
// in strenuous activity
inline bool wftStrenuousOverfullMove()
    { return true; }

// a character involved in melee combat is engaged in strenuous activity
inline bool wftStrenuousMelee()
    { return true; }

// continuous climbing, swimming against a strong current, and moving while
// severely encumbered are other examples of strenuous activity
inline bool wftStrenuousOtherExamples()
    { return true; }

// failure on the Constitution Check indicates the character is fatigued
inline bool wftCheckFailFatigued()
    { return true; }

// each successful check grants activity but shortens the interval to the next
// required check, to a minimum of one turn
inline bool wftIntervalShrinksPerSuccess()
    { return true; }

// a character with an extremely high constitution may keep performing a
// strenuous activity for several hours, but the odds will eventually catch up
// with him
inline bool wftHighConEventuallyCaught()
    { return true; }

// all of the ability scores of a fatigued character except comeliness are
// lowered by 2, and most incidental benefits bestowed by the higher scores
// are also lost as long as he remains fatigued
inline bool wftFatigueScoresExceptComeliness()
    { return true; }

// the 18-strength fatigued example: the +1 to-hit bonus is lost and the
// damage bonus drops from +2 to +1, among other penalties
inline bool wftStr18ExampleDetail()
    { return true; }

// the 18-constitution fatigued example: the fighter loses 2 hit points for
// each hit die, his actual temporary constitution score being only 16
inline bool wftCon18ExampleDetail()
    { return true; }

// the 14-wisdom fatigued example: the cleric loses both bonus 1st-level
// spells; if spells are in memory two 1st-level spells are lost at random,
// higher-level spells lost instead if fewer than two are held, the bonus
// spells cannot be regained, and every spell cast carries a chance of failure
// until he is no longer fatigued
inline bool wftWis14ExampleDetail()
    { return true; }

// any Proficiency Check or Ability Check required of a fatigued character has
// a smaller chance of success, the die roll compared to the current ability
// score instead of the normal score
inline bool wftChecksUseReducedScores()
    { return true; }

// a fatigued character can continue to perform strenuous activity, but must
// make a Constitution Check once per turn while doing so
inline bool wftFatiguedCanContinue()
    { return true; }

// if a fatigued character fails a Constitution Check, he becomes exhausted
inline bool wftFatiguedFailExhausted()
    { return true; }

// an exhausted character can attempt to defend himself or perform some other
// physical action only when failure to move would mean risking death
inline bool wftExhaustedOnlyDefense()
    { return true; }

// otherwise an exhausted character is not capable of any voluntary physical
// activity: he cannot move under his own power, put on or take off armor,
// build a fire, or do anything else requiring minimal strength and muscle
// control
inline bool wftExhaustedCannotAct()
    { return true; }

// one hour of uninterrupted rest plus a successful Constitution Check (at the
// reduced score) leaves the character only fatigued instead of exhausted
inline bool wftExhaustRecoverByCheck()
    { return true; }

// if the recovery check fails, the character remains exhausted and must rest
// for another hour before trying again
inline bool wftExhaustRecoverFailLoop()
    { return true; }

// a fatigued or exhausted character can rest while being carried, as long as
// no strength or balance is needed to remain in position and he is not
// bounced or jostled; a fighter draping a frail magic-user across his
// shoulders works, but a choppy or zig-zagging path across rugged or very
// rugged terrain spoils the rest
inline bool wftRestWhileCarried()
    { return true; }

// an exhausted character can rest while securely tied to the back of a horse
// or other mount, but only if the mount moves easily (no faster than normal
// movement rate) over terrain that is not difficult for the animal to
// negotiate
inline bool wftRestTiedToMount()
    { return true; }

// ---- Land-based mounts and pack animals ----

// an animal becomes fatigued if forced to go for two consecutive days without
// any food and water
inline int wftAnimalNoFoodDays()
    { return 2; }

// an animal becomes fatigued if forced to subsist on less than its full
// normal daily ration for more than three consecutive days
inline int wftAnimalShortRationDays()
    { return 3; }

// to recover from fatigue due to lack of nourishment, an animal must be given
// a full normal ration of food and water and allowed to rest for eight hours
// afterward
inline int wftRationRecoveryRestHours()
    { return 8; }

// to recover from fatigue due to overexertion, an animal must rest for 12
// hours plus two hours for every hour it was overworked
inline int wftOverworkBaseRestHours()
    { return 12; }

// the overwork recovery adds two hours of rest per hour of overwork
inline int wftOverworkRestPerHour()
    { return 2; }

// the horse example: pushed three hours beyond the normal limit of its
// stamina
inline int wftHorseExampleOverworkHours()
    { return 3; }

// the horse example: it remains fatigued until allowed to rest for at least
// 18 hours without interruption (12 + 2 per overworked hour)
inline int wftHorseExampleRestHours()
    { return 18; }

// a fatigued animal moves at one-half of its normal movement rate - the
// numerator
inline int wftAnimalFatigueMoveNum()
    { return 1; }

// the fatigued animal movement fraction - the denominator
inline int wftAnimalFatigueMoveDen()
    { return 2; }

// a fatigued animal is capable of occasional bursts of speed enabling it to
// move at its full normal rate for one round per turn
inline int wftBurstFullRateRoundsPerTurn()
    { return 1; }

// a fatigued animal is not able to negotiate any terrain in which its full
// normal movement rate is 3 inches
inline int wftFatiguedTerrainBarInches()
    { return 3; }

// the armor class of a fatigued animal is two places worse than normal,
// accounting for its slower reflexes
inline int wftAnimalFatigueAcPlaces()
    { return 2; }

// the fatigued armor class example - the normal class
inline int wftAnimalFatigueAcFrom()
    { return 7; }

// the fatigued armor class example - the worsened class
inline int wftAnimalFatigueAcTo()
    { return 9; }

// if a fatigued animal is forced to keep working or moving, there is a 20
// percent chance per hour, cumulative, that it will become exhausted
inline int wftExhaustionHourChancePct()
    { return 20; }

// after any rest period of at least one hour the cumulative chance of
// exhaustion begins again at 20 percent
inline int wftExhaustionResetRestHours()
    { return 1; }

// an exhausted animal may collapse: 25 percent chance if unburdened
inline int wftCollapseUnburdenedPct()
    { return 25; }

// the collapse chance if carrying a rider or a normal load: 50 percent
inline int wftCollapseBurdenedPct()
    { return 50; }

// the collapse chance if carrying more than a normal load: 75 percent
inline int wftCollapseOverloadedPct()
    { return 75; }

// there is a flat 50 percent chance that an animal driven to exhaustion will
// die within 1d4 hours, checked as soon as it collapses
inline int wftExhaustDeathChancePct()
    { return 50; }

// the death window: the animal may die within 1d4 hours of collapse
inline int wftExhaustDeathWindowDie()
    { return 4; }

// once per hour for eight consecutive hours the Dungeon Master rolls 1d6 for
// the collapsed animal
inline int wftTraumaDie()
    { return 6; }

// the trauma roll subtracts 3 from the 1d6 result
inline int wftTraumaSubtract()
    { return 3; }

// the trauma roll yields a number in the range 0-3, the hit points lost
// during that hour
inline int wftTraumaMaxLoss()
    { return 3; }

// the trauma rolls run once per hour for eight consecutive hours - the
// critical period
inline int wftTraumaHours()
    { return 8; }

// an animal that survives the critical period regains its lost hit points at
// the rate of 2 per hour
inline int wftTraumaRegainPerHour()
    { return 2; }

// the stamina process is in the Encumbrance and Movement section, the
// animal-care specifics are in Mounts and Beasts of Burden, and these general
// fatigue rules apply in all cases not specifically accounted for elsewhere
inline bool wftAnimalCrossRefs()
    { return true; }

// two consecutive days without any food and water fatigues the animal
inline bool wftAnimalFatiguedNoFood()
    { return true; }

// less than the full normal daily ration for more than three consecutive days
// fatigues the animal
inline bool wftAnimalFatiguedShortRation()
    { return true; }

// nourishment recovery requires BOTH the full ration and the full eight hours
// of rest; missing either leaves the animal fatigued
inline bool wftRationRecoveryNeedsBoth()
    { return true; }

// overwork recovery is 12 hours of rest plus two hours per hour overworked;
// the pushed horse example rests 18 hours
inline bool wftOverworkRecoveryFormula()
    { return true; }

// a fatigued animal moves at half its normal rate with occasional
// one-round-per-turn bursts of full speed
inline bool wftFatiguedHalfMoveWithBursts()
    { return true; }

// the fatigued terrain bar: no terrain whose full normal rate is 3 inches; a
// fatigued horse cannot move in very rugged terrain carrying more than a
// normal load, and a fatigued camel cannot move in very rugged terrain under
// any circumstances
inline bool wftFatiguedTerrainBarDetail()
    { return true; }

// a fatigued animal is two armor class places worse (7 to 9, for instance) -
// slower reflexes
inline bool wftFatiguedAcWorse()
    { return true; }

// if a fatigued animal becomes excited, only a character with proficiency in
// animal handling can get it to calm down, and that chance is only as great
// as the normal chance for a nonproficient character
inline bool wftExcitedOnlyHandlerCalms()
    { return true; }

// a fatigued animal forced to keep working faces a cumulative 20 percent
// chance per hour of becoming exhausted
inline bool wftWorkedFatiguedExhaustionChance()
    { return true; }

// worked briefly without exhaustion and then rested at least an hour, the
// animal recovers somewhat and the cumulative chance starts again at 20
// percent
inline bool wftBriefWorkRestResets()
    { return true; }

// an exhausted animal stops in its tracks, incapable of moving or working;
// near death, its survival without magical aid depends entirely on chance
inline bool wftExhaustedStopsInTracks()
    { return true; }

// the exhausted animal may collapse (25/50/75 percent by burden) and while
// incapacitated is oblivious to anything going on around it
inline bool wftExhaustedCollapseOblivious()
    { return true; }

// an exhausted animal will not become excited or panicked even if threatened
// by fire, but will make no attempt to protect itself from attack or injury
inline bool wftExhaustedNoPanicNoDefense()
    { return true; }

// a flat 50 percent chance that the exhausted animal dies within 1d4 hours,
// checked by the Dungeon Master as soon as it collapses
inline bool wftExhaustedDeathCheck()
    { return true; }

// once per hour for eight consecutive hours the trauma roll is 1d6 minus 3,
// losing 0-3 hit points per hour; at a hit-point total of 0 the animal is
// dead
inline bool wftExhaustedTraumaDrain()
    { return true; }

// surviving the eight-hour critical period, the animal regains lost hit
// points at 2 per hour and is recovered from exhaustion (but still fatigued)
// when the total reaches its pre-exhaustion level
inline bool wftExhaustedTraumaRecovery()
    { return true; }

// ---- Flying mounts ----

// the black dragon example: stamina values 24/6, safe flying time 24
// consecutive turns
inline int wftDragonSafeTurns()
    { return 24; }

// the black dragon rest value: 6 turns of landed rest to regain stamina
inline int wftDragonRestTurns()
    { return 6; }

// the black dragon safe flying time in hours: 24 turns is four hours
inline int wftDragonSafeHours()
    { return 4; }

// the black dragon rest period in hours: 6 turns is one hour
inline int wftDragonRestHours()
    { return 1; }

// past the safe flying time the Dungeon Master rolls 1d10 on a turn-by-turn
// basis to see if the flying mount becomes fatigued
inline int wftFatigueCheckDie()
    { return 10; }

// the chance of fatigue is equal to 10 minus the second number of the stamina
// value
inline int wftFatigueChanceBase()
    { return 10; }

// the black dragon fatigues on any turn past its safe time when the 1d10 roll
// is 1-4 - the low end
inline int wftDragonFatigueRollLow()
    { return 1; }

// the black dragon fatigue roll high end: 1-4 on 1d10 (10 minus its rest
// value of 6)
inline int wftDragonFatigueRollHigh()
    { return 4; }

// the non-block example: over a period of 30 turns the dragon is aloft 24 and
// rests 6, within the safe limit
inline int wftExampleWindowTurns()
    { return 30; }

// the example variant: a 7-turn last flight period puts the dragon aloft 25
// turns without 6 turns of rest, risking fatigue on the 7th turn
inline int wftExampleLastFlightTurns()
    { return 7; }

// on the turn fatigue sets in the flying mount movement rate drops to
// two-thirds of full normal - the numerator
inline int wftFatigueMoveNum()
    { return 2; }

// the fatigued flying mount movement fraction - the denominator
inline int wftFatigueMoveDen()
    { return 3; }

// a fatigued flying mount gradually loses altitude at 10 yards per round
inline int wftFatigueLossPerRoundYards()
    { return 10; }

// a flying mount not more than 100 yards above the ground and not forced to
// remain aloft can descend and make a safe landing in the same turn fatigue
// sets in
inline int wftSameTurnLandingAltitudeYards()
    { return 100; }

// for every 10 yards dived a rider suffers 1d2 hit points of damage at the
// end of the flight
inline int wftBuffetDieSides()
    { return 2; }

// the buffet damage accrues per 10 yards of dive distance
inline int wftBuffetPerYards()
    { return 10; }

// an unstrapped rider thrown on landing suffers 11-40 hit points of damage -
// the minimum
inline int wftThrownDmgMin()
    { return 11; }

// the thrown-rider damage maximum: 40
inline int wftThrownDmgMax()
    { return 40; }

// the thrown-rider damage is 3d10 plus 10
inline int wftThrownDiceCount()
    { return 3; }

// the thrown-rider damage die: 3d10
inline int wftThrownDieSides()
    { return 10; }

// the thrown-rider damage base: +10 on 3d10
inline int wftThrownBase()
    { return 10; }

// a fatigued flying mount that lands refuses to take off again for at least
// three times its normal rest period
inline int wftPostFatigueRestMult()
    { return 3; }

// the black dragon post-fatigue rest: 18 turns (three times its 6-turn rest
// period)
inline int wftDragonPostFatigueRestTurns()
    { return 18; }

// a flying mount can never become exhausted; but if it becomes fatigued, the
// rider stands to suffer at least as much as the animal, and perhaps a whole
// lot more
inline bool wftFlyingNeverExhausted()
    { return true; }

// the Characteristics of Flying Mounts table in the Movement and Encumbrance
// section gives the stamina values; the first number is the safe flying time
inline bool wftStaminaTableCrossRef()
    { return true; }

// the safe flying time may be reduced if the creature is heavily loaded down
inline bool wftHeavyLoadReducesSafe()
    { return true; }

// once aloft for consecutive turns equal to its safe flying time, the Dungeon
// Master begins rolling 1d10 each turn thereafter
inline bool wftFatigueRollPastSafe()
    { return true; }

// the chance of fatigue is equal to 10 minus the second number of the stamina
// value
inline bool wftFatigueChanceFormula()
    { return true; }

// the black dragon 24/6: ridden through the air 24 consecutive turns (four
// hours) without risk, then it must land and rest (not fly) 6 turns (one
// hour) to regain stamina; past the 24th turn it fatigues on a 1d10 roll of
// 1-4
inline bool wftDragonExample()
    { return true; }

// flying time and rest time need not be taken in full blocks: flown 12,
// rested 3, flown 6, rested 2, flown 6, rested 1 - 24 aloft and 6 rest in a
// 30-turn window is safe; but the 7-turn last flight means 25 turns aloft
// without the 6 turns of rest, risking fatigue
inline bool wftFlyingRestNotFullBlocks()
    { return true; }

// a creature that exceeds its safe flying time and is brought to a safe
// landing must have a FULL rest period or it is subject to fatigue as soon as
// it takes to the air again
inline bool wftExceedNeedsFullRest()
    { return true; }

// keep careful track of how much the mount has flown and rested; exceeding
// the safe flying time by even a small amount can cause an extended delay on
// a long-distance journey
inline bool wftTrackAloftAndRest()
    { return true; }

// on the turn fatigue sets in the movement rate drops to two-thirds of normal
// and the mount begins losing altitude at 10 yards per round
inline bool wftFatigueTwoThirdsMove()
    { return true; }

// not more than 100 yards up and not forced to remain aloft, the fatigued
// mount can descend and land safely in the same turn
inline bool wftFatigueSafeLandingSameTurn()
    { return true; }

// more than 100 yards up when fatigue sets in, the mount is still aloft when
// its second turn of fatigue begins: it stops descending gradually and goes
// into a steep dive toward a resting place; riders face an increased chance
// of falling and the sudden stop at the end
inline bool wftSecondTurnSteepDive()
    { return true; }

// for every 10 yards dived before reaching the ground a rider suffers 1d2 hit
// points at the end of the flight from the buffeting of the crash, bounce or
// skid to a stop
inline bool wftDiveBuffetDamage()
    { return true; }

// the buffet damage is halved for a character with proficiency in airborne
// riding or one securely strapped (upper and lower body) to the back of the
// mount
inline bool wftBuffetHalvedFor()
    { return true; }

// a rider without at least his lower body strapped suffers no buffeting
// damage but is thrown from the mount when it lands, suffering 11-40 hit
// points (3d10 + 10) from the abrasion and impact of the tumble
inline bool wftUnstrappedThrown()
    { return true; }

// a fatigued flying mount that lands refuses to take off again for at least
// three times its normal rest period (18 turns for a black dragon), unless
// self-preservation dictates that it become airborne
inline bool wftPostFatigueGroundRefusal()
    { return true; }

// taking off again for any reason before the full post-fatigue rest period
// expires, the mount has a chance of becoming fatigued on every turn it
// remains aloft
inline bool wftEarlyTakeoffFatigueRisk()
    { return true; }

}   // namespace rules
