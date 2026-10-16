// =========================================================================================
// Adnd1 - rules/wsgfight.h
// R488: the WSG WILDERNESS COMBAT opener slice, printed pp. 84-87 - the round
// OPENING the wilderness combat chapter, the last WSG chapter: the chapter
// introduction with the DSG summary cross-reference, the fighting while
// climbing penalties and Climbing Checks, the precariously balanced rules
// with the edge-distance and suffocation chains, the water depth penalties,
// the poor visibility penalties with the wild-swing rules, the inclement
// weather cumulative note, the melee and missile combat from a mount rules
// with the rate-of-fire scale, and the forcing- opponents-to-dismount rules
// through the p. 87 cut - the dismount tail rides to the next round.
// census 412 -> 413.
//
// THE SETTLE: two-way clean on the first pass - the tesseract full-text
// reads, the pdftotext layout read and the tsv coordinate reads agree on
// every number (the -2 cliff and -1 severe penalties, the +2/-2 and +1/-1
// elevation adjustments, the +10 and -10 Climbing Rating adjustments, the -4
// mud and -2 ledge balance modifiers with -2 per foot of edge distance and
// -18 at nine feet, the 19-20 auto-fails, the five-segment recovery, the +4
// slippery check, the -1 -2 -4 water penalties, the -1 -3 -4 visibility
// penalties with the quarter and half bonus cuts, the 50 percent wild swing,
// the 5 and 10 percent climbing cuts, the +1 and +2 precarious modifiers, the
// +1 and +2 mount bonuses, the +4 brace with the 3-foot weapon, the
// 6/1-to-1/1 rate scale with the 5/2-to-2/1 javelin step, the -1 -3 -5 speed
// penalties, the 45-degree limit, the natural 20 and 16-20 unseating rolls
// with the 5-9 and 10-foot weapon ranges, and the 1d3 and 1d6 fall dice). The
// garbles all settled without contest: the tesseract em-dash class (a leading
// -2) matches the layout minus, the layout rate-of-fire scale 611 511 411 311
// 512 211 312 111 is 6/1 5/1 4/1 3/1 5/2 2/1 3/2 1/1 with the slash rendered
// as a one (tesseract confirms with 6/1), the javelin example 5 every 2
// rounds reduced to 2 per round anchors the scale, + I is +1, l d 3 and l d 6
// are 1d3 and 1d6, and the DMG page 53 cross-reference stands. The p. 87 cut
// is mid-sentence in the flying-mount-death text - the close-to-the-ground
// tail rides to R489 exactly as the tidal tail rode to R487.
//
// Bounds held: the cliff penalty is twice the severe-slope penalty, the
// elevation adjustments halve from the cliff to the slope, the water
// penalties strictly ascend 1 2 and 4, the visibility penalties strictly
// ascend 1 3 and 4 with the bonus cut doubling from quarter to half, the
// darkness climbing and precarious adjustments double from natural to total,
// the mount-speed penalties strictly ascend 1 3 and 5, the rate-of-fire scale
// floors at 1/1 with the javelin 5/2 stepping down to 2/1, and the unseat
// rolls run natural 20 for the 3-foot weapon and 16-20 for the 10-foot
// pole-arm.
//
namespace rules {

// ---- The chapter opener ----

// characters prefer to engage in the best position for attack and defense,
// but the wilderness and its creatures are not usually accommodating -
// characters will often have to attack or defend in far-from-best positions,
// sometimes enjoying the advantage when the tables are turned
inline bool wfcWildernessPositions()
    { return true; }

// some combat rules for unusual situations are covered in the Dungeoneer's
// Survival Guide on pages 30-34, summarized here - the start page
inline int wfcDsgRefStartPage()
    { return 30; }

// the summarized DSG reference end page
inline int wfcDsgRefEndPage()
    { return 34; }

// some of the DSG rules are summarized here for those without the volume, and
// the section goes into detail about other nonstandard combat situations
// peculiar to the outdoors
inline bool wfcOutdoorNonstandardDetail()
    { return true; }

// ---- Fighting while climbing ----

// a character negotiating a severe slope or a cliff face who must attack or
// defend does not benefit from any armor class bonus due to dexterity,
// because his attention and effort are at least partially focused on climbing
inline bool wfcClimberNoDexBonus()
    { return true; }

// an armor class penalty for low dexterity is not negated while climbing
inline bool wfcClimberLowDexPenaltyStays()
    { return true; }

// assuming the climber needs one hand to hold onto a rope or the surface, he
// cannot use two weapons, or a weapon and a shield, at the same time
inline bool wfcOneHandToClimb()
    { return true; }

// since he is facing the surface he is climbing, the climber is vulnerable to
// attacks from behind - with all appropriate penalties - from any opponent
// except one that is adjacent to him on the surface
inline bool wfcRearAttackVulnerable()
    { return true; }

// a character climbing with his shield strapped to his back receives an armor
// class benefit of one step (from 6 to 5, for instance) for a buckler or a
// small shield
inline int wfcShieldBackSmallSteps()
    { return 1; }

// and a benefit of two steps for any larger shield
inline int wfcShieldBackLargeSteps()
    { return 2; }

// a character climbing a cliff face suffers a -2 penalty to all of his attack
// rolls - to hit and damage - in melee or missile combat
inline int wfcCliffAtkPenalty()
    { return 2; }

// the cliff-face climber also suffers a -2 penalty on all saving throws
// related to an attempt to dodge or evade
inline int wfcCliffSavePenalty()
    { return 2; }

// if the fighting is taking place on a severe slope, these attack penalties
// are -1 instead of -2
inline int wfcSevereSlopeAtkPenalty()
    { return 1; }

// if opponents engage from different elevations on a cliff face - one
// combatant above the other by at least half of the higher combatant's height
// - the elevation adjustments apply
inline bool wfcElevNeedsHalfHeight()
    { return true; }

// the character in the higher position on a cliff face receives a +2 bonus to
// hit
inline int wfcElevHighBonusCliff()
    { return 2; }

// and the character in the lower position suffers a -2 penalty to hit
inline int wfcElevLowPenaltyCliff()
    { return 2; }

// on a severe slope the elevation adjustments are +1 and -1
inline int wfcElevHighBonusSevere()
    { return 1; }

// the severe-slope lower-position penalty
inline int wfcElevLowPenaltySevere()
    { return 1; }

// the elevation adjustments are cumulative with any other modifiers that may
// apply
inline bool wfcElevAdjustmentsCumulative()
    { return true; }

// if a character climbing a cliff face suffers damage from an attack in
// missile or melee combat - including damage from a spell effect - he must
// make a Climbing Check immediately: success and he remains in place, failure
// and he falls
inline bool wfcDamageClimbingCheck()
    { return true; }

// on a severe slope the damage-triggered Climbing Check is made with a +10
// percent bonus to the character's Climbing Rating
inline int wfcDamageCheckSevereBonus()
    { return 10; }

// if a character takes damage from a single attack equal to or greater than
// one-half of his total hit points, rounded up, a Climbing Check to avoid
// falling must be made
inline bool wfcBigDamageHalfHpCheck()
    { return true; }

// the big-damage Climbing Check is made with a -10 percent penalty to the
// Climbing Rating, applying both on a cliff face and on a severe slope
inline int wfcBigDamageCheckPenalty()
    { return 10; }

// climbing a gentle or even a moderate slope does not usually put a character
// at a disadvantage in combat - such terrain is usually not so steep that the
// climber cannot stand up with the full use of both hands and reasonable
// mobility
inline bool wfcModerateSlopeNoDisadvantage()
    { return true; }

// at the Dungeon Master's discretion, the to-hit adjustments for relative
// elevation (+1 and -1) may apply on a moderate slope, especially one just
// short of qualifying for the severe category
inline bool wfcModerateElevOption()
    { return true; }

// the Dungeon Master may rule that a character on a moderate or gentle slope
// who takes a significant amount of damage in a single attack will be knocked
// off his feet and tumble down the slope
inline bool wfcModerateDamageTumbleOption()
    { return true; }

// if a character is extremely outmanned and prefers not to stand and fight,
// voluntarily tumbling down a slope to get away from his enemies might be a
// viable strategy
inline bool wfcVoluntaryTumbleEscape()
    { return true; }

// ---- Fighting precariously balanced ----

// a precariously balanced character is perched on a surface where he does not
// need to use at least one hand to hold on, and does not necessarily have to
// face the surface his body is next to
inline bool wfcBalancedDefinition()
    { return true; }

// a character is precariously balanced when standing on a ledge jutting from
// a cliff face or severe slope; on a narrow bridge of rock or a fallen tree
// spanning a canyon; standing up in a boat or on the edge of a barge;
// standing in knee-deep water or mud, or upon loose soil or snow in which the
// feet sink beneath the surface; and standing upon a level but slippery
// surface
inline bool wfcBalancedExamples()
    { return true; }

// whenever a character engaged in melee combat misses an attack, he must make
// a successful Dexterity Check to avoid losing his balance and falling down -
// perhaps falling a long distance
inline bool wfcMissDexCheck()
    { return true; }

// the Dungeon Master may allow a modifier of -1 to -4 on the balance
// Dexterity Check where overbalancing is less likely to result in a fall: -4
// for a character knee-deep in mud, which helps hold him upright
inline int wfcDexModMud()
    { return 4; }

// -2 for a character standing on a fairly wide ledge that offers room to take
// a step on his follow-through and keep himself from toppling
inline int wfcDexModWideLedge()
    { return 2; }

// no modifier for a character standing on a slippery surface, where his
// ability to keep his balance depends entirely on how dextrous he is and not
// on some advantage of his location
inline bool wfcSlipperyNoDexMod()
    { return true; }

// if a character in a precarious position at a high elevation is hit by an
// attack that causes loss of consciousness or inflicts damage equal to or
// greater than a threshold fraction of his total hit points, he must make a
// successful Dexterity Check to avoid falling from his position
inline bool wfcBigHitDexCheck()
    { return true; }

// the big-hit threshold at a high elevation: damage equal to or greater than
// 10 percent of the victim's total hit points
inline int wfcBigHitHpPct()
    { return 10; }

// if the victim is not standing right at the edge of a dropoff, he receives a
// -2 modifier to the Dexterity Check die roll for every foot of distance
// between him and the edge
inline int wfcEdgePerFootMod()
    { return 2; }

// a character 10 feet or more from the edge of a dropoff is not considered to
// be in a precarious position, and does not need to make the Dexterity Check
inline int wfcNotPrecariousFt()
    { return 10; }

// someone balanced on a ledge barely wide enough for his feet receives no
// modifier; someone nine feet away from the edge of a dropoff receives a -18
// modifier and is virtually assured of not falling
inline int wfcNineFtEdgeMod()
    { return 18; }

// as with any ability check, an unmodified roll of 19 or 20 indicates failure
// - the low auto-fail roll
inline int wfcAutoFailRollLow()
    { return 19; }

// the high auto-fail roll
inline int wfcAutoFailRollHigh()
    { return 20; }

// a character who falls despite being a fair distance from the edge of his
// perch is assumed to have staggered a short distance toward the edge before
// dropping over
inline bool wfcStaggerBeforeFall()
    { return true; }

// the rule also applies to a precariously balanced character not at a high
// elevation: he is in danger of being knocked off his feet by a large amount
// of damage, and will certainly fall down - as would anyone in a more stable
// position - if rendered unconscious
inline bool wfcLowPrecariousKnockdown()
    { return true; }

// a character who is knee-deep in water and gets hit by a sleep spell will
// keel over; beginning the following round he must make Constitution Checks
// as though holding his breath underwater and out of air, and dies if he does
// not regain consciousness or is not rescued before failing one
inline bool wfcWaterSleepSuffocation()
    { return true; }

// a character who falls unconscious in loose soil - including sand - or snow
// must make a Dexterity Check with a -2 modifier to the die roll; failure
// indicates he has landed face down and must then begin Constitution Checks,
// dying of suffocation if not revived or at least rolled over before failing
// one
inline bool wfcLooseSoilFaceDownCheck()
    { return true; }

// the loose-soil face-down Dexterity Check modifier
inline int wfcLooseSoilDexMod()
    { return 2; }

// whenever a character is knocked off his feet and does not lose
// consciousness, he must make a Dexterity Check
inline bool wfcKnockdownDexCheck()
    { return true; }

// a successful check means he is able to regain his feet in five segments
inline int wfcRegainFeetSegments()
    { return 5; }

// a failed check means he must take a full round to stand and resume a
// fighting posture
inline bool wfcKnockdownFullRoundFail()
    { return true; }

// a character who gets to his feet quickly may be able to make an attack or
// cast a spell during the last half of the round, if other conditions permit
inline bool wfcRegainHalfRoundAction()
    { return true; }

// on a slippery surface, the knockdown Dexterity Check is made with a +4
// modifier to the die roll
inline int wfcSlipperyDexMod()
    { return 4; }

// ---- Fighting in water ----

// a character in combat while standing in water at least up to his knees but
// not higher than his waist does not enjoy any armor class benefit due to
// dexterity
inline bool wfcWaterKneeNoDexBonus()
    { return true; }

// the knee-to-waist water fighter takes a -1 penalty on all attack rolls - to
// hit and damage - in addition to any other penalties
inline int wfcWaterKneePenalty()
    { return 1; }

// if the water is more than waist-high but not higher than the chest, the
// penalty is -2
inline int wfcWaterChestPenalty()
    { return 2; }

// if the water is even higher than the chest, the penalty is -4
inline int wfcWaterOverChestPenalty()
    { return 4; }

// in no case can the damage from a successful hit be reduced to less than 1
// point
inline int wfcWaterDmgMin()
    { return 1; }

// any opponent attempting to hit a character who is immersed or partially
// immersed in water does so at the same penalty to its attack rolls - even if
// the opponent is not immersed - reflecting that a smaller portion of the
// character's body is vulnerable to a weapon blow
inline bool wfcAttackerSamePenalty()
    { return true; }

// these penalties do not apply to a creature native to an aquatic
// environment, assuming it can strike freely above the water or below the
// surface
inline bool wfcAquaticNativeExempt()
    { return true; }

// for a character with proficiency in swimming, the chest and over-chest
// penalties are reduced by one-half - to -1 and -2 respectively - and the
// waist-deep penalty does not apply
inline bool wfcSwimProficiencyRelief()
    { return true; }

// ---- Fighting in poor visibility ----

// in moonlight, a character suffers a -1 penalty on all attack rolls and all
// saving throws related to dodging or evasion
inline int wfcMoonlightPenalty()
    { return 1; }

// in natural darkness with no moonlight the penalty is -3
inline int wfcNaturalDarkPenalty()
    { return 3; }

// in total darkness - such as that caused by magical means, or the darkness
// deep inside a cave - the penalty is -4
inline int wfcTotalDarkPenalty()
    { return 4; }

// any attack bonus related to the ability to see the target is reduced by
// one-quarter in moonlight (pinned as 1 out of 4)
inline int wfcMoonlightBonusCutNum()
    { return 4; }

// the vision-based attack bonus is reduced by one-half in natural darkness
// (pinned as 1 out of 2)
inline int wfcNaturalDarkBonusCutNum()
    { return 2; }

// the vision-based attack bonus is fully negated in total darkness
inline bool wfcTotalDarkBonusNegated()
    { return true; }

// the vision-based bonus category includes a thief's backstabbing skill, a
// ranger's special prowess against giant-class creatures, or the special
// severing property of a sword of sharpness commanded not to shed any light
inline bool wfcBonusCutExamples()
    { return true; }

// when meleeing in total darkness, if the attacker's modified to-hit roll is
// 0 or less he has accidentally struck another object or creature, if some
// other target exists within the wild-swing radius
inline bool wfcTotalDarkWildSwing()
    { return true; }

// the wild-swing radius is twice the attacker's weapon length
inline int wfcWildSwingRadiusMult()
    { return 2; }

// if more than one unintended target is in range, the Dungeon Master randomly
// determines which object, creature or character has been hit - including
// other members of the attacker's party
inline bool wfcWildSwingRandomTarget()
    { return true; }

// an object hit by a wild swing must save versus crushing blow to avoid being
// broken or destroyed; a creature or character takes the appropriate damage
// after the poor-visibility damage penalty is taken into account
inline bool wfcWildSwingObjectSave()
    { return true; }

// in natural darkness there is a 50 percent chance that a wild swing results
// in damage to an unintended target
inline int wfcNaturalDarkWildPct()
    { return 50; }

// if the natural-darkness wild-swing roll fails, the attack hits nothing
// within range
inline bool wfcNaturalDarkWildElseMiss()
    { return true; }

// a character fighting in natural darkness while climbing has his Climbing
// Rating reduced by 5 percent for any combat-triggered Climbing Check
inline int wfcDarkClimbCut()
    { return 5; }

// a character fighting in natural darkness while in a precarious position
// makes any required Dexterity Check with a +1 modifier to the die roll
inline int wfcDarkPrecariousDexMod()
    { return 1; }

// in total darkness the Climbing Rating reduction is 10 percent
inline int wfcTotalDarkClimbCut()
    { return 10; }

// in total darkness the precarious-position Dexterity Check modifier is +2
inline int wfcTotalDarkPrecariousDexMod()
    { return 2; }

// if the illumination is at least equivalent to moonlight, neither the
// climbing nor the precarious-position darkness penalty applies
inline bool wfcMoonlightIlluminationExempt()
    { return true; }

// a character using infravision or ultravision, and able to benefit from the
// ability, is not subject to any of the poor-visibility penalties
inline bool wfcSpecialVisionExempt()
    { return true; }

// any character within the range of natural or magical illumination is not
// penalized
inline bool wfcIlluminationRangeExempt()
    { return true; }

// ---- Fighting in inclement weather ----

// all adjustments for inclement weather - high wind and precipitation - are
// cumulative with any other modifiers that apply; even the most accomplished
// fighter will have a tough time hitting anything in the dark of night during
// a howling rainstorm
inline bool wfcWeatherCumulative()
    { return true; }

// ---- Melee combat from a mount ----

// a character on a land-based mount in melee with an opponent standing on the
// ground has an advantage of +1 to hit if the foe is the same size as the
// attacker
inline int wfcMountSameSizeBonus()
    { return 1; }

// the mounted character receives no bonus if the opponent is larger
inline bool wfcMountLargerNoBonus()
    { return true; }

// a mounted attacker must take a -1 penalty to hit against an unmounted
// opponent of smaller size - it is tougher for a man on horseback to hit a
// goblin assaulting him from below
inline int wfcMountSmallerPenalty()
    { return 1; }

// a character on foot and fighting a mounted opponent has a -1 penalty to hit
// regardless of the opponent's size
inline int wfcFootVsMountedPenalty()
    { return 1; }

// if the foot character's to-hit roll - including all other modifiers - is
// exactly the number he would have needed to hit his foe, the attack hits the
// mount instead of the rider
inline bool wfcExactHitStrikesMount()
    { return true; }

// a character on foot can choose to strike against the mount instead of the
// rider, which can often be a good tactic
inline bool wfcChooseStrikeMount()
    { return true; }

// a character on a flying mount can engage in melee with a nearby airborne
// opponent, or with a foe on the ground if the mount is flying low enough to
// make it possible
inline bool wfcFlyingMountLowEngagement()
    { return true; }

// if two antagonists are both airborne, the combat adjustments for relative
// elevation usually do not apply - the combatants are assumed to be
// constantly jockeying for position, neither voluntarily remaining in a
// vulnerable position
inline bool wfcAirborneNoElevationAdjustment()
    { return true; }

// a character who is airborne is +1 to hit against an opponent on the ground
inline int wfcAirborneVsGroundBonus()
    { return 1; }

// the airborne character is +2 to hit if the attack is made at the end of a
// swooping charge
inline int wfcSwoopChargeBonus()
    { return 2; }

// a character on the ground may defend against an attack from above by
// remaining in one spot and bracing himself for the onslaught
inline bool wfcBracedDefense()
    { return true; }

// the braced defense requires wielding a weapon of at least 3 feet in length
inline int wfcBraceWeaponMinFt()
    { return 3; }

// the braced defender receives a +4 bonus on his to-hit roll
inline int wfcBraceBonus()
    { return 4; }

// the braced defender forfeits any armor class bonus due to dexterity
inline bool wfcBraceForfeitsDexBonus()
    { return true; }

// an airborne opponent, noticing the braced tactic, can choose to pull up and
// break off the attack, in which case neither combatant will score a hit
inline bool wfcPullUpBreaksOff()
    { return true; }

// a character on a flying mount must be able to hover in close proximity to a
// land-based opponent to benefit from multiple attacks per round
inline bool wfcHoverNeededForMulti()
    { return true; }

// an attacker who closes to take one swing and then veers away to avoid being
// hit in return will not be able to change course in time to get a second or
// third attack
inline bool wfcVeerPreventsFollowups()
    { return true; }

// most flying creatures have very poor maneuverability when used as mounts,
// and are not capable of repeated abrupt changes of direction or other
// precise maneuvers
inline bool wfcFlyingMountPoorManeuver()
    { return true; }

// ---- Missile combat from a mount ----

// only a character with proficiency in riding his mount can successfully use
// a missile weapon from the back of a moving mount, whether airborne or
// land-based
inline bool wfcMissileNeedsRidingProf()
    { return true; }

// even if the weapon does not actually require two hands, the character must
// be able to ride with both hands free - one of the abilities included in the
// land-based and airborne riding proficiencies
inline bool wfcMissileNeedsBothHands()
    { return true; }

// any missile weapon except a longbow can be used from the back of a moving
// mount
inline bool wfcMissileLongbowExcluded()
    { return true; }

// a heavy crossbow also cannot be used from the back of a moving mount
inline bool wfcMissileHeavyCrossbowExcluded()
    { return true; }

// the mounted missile attacker must take a one-step reduction in his normal
// rate of fire on the standard scale
inline bool wfcRofOneStepReduction()
    { return true; }

// the head of the rate-of-fire scale: 6 attacks per round, descending through
// 5/1, 4/1, 3/1, 5/2, 2/1 and 3/2
inline int wfcRofBestPerRound()
    { return 6; }

// in no case can a character's rate of fire be reduced below 1 attack per
// round because of the mounted penalty - the numerator floor
inline int wfcRofFloorNum()
    { return 1; }

// the rate-of-fire floor denominator: 1/1
inline int wfcRofFloorDen()
    { return 1; }

// a 13th-level fighter specialized in hurling the javelin can ordinarily make
// 5 attacks every 2 rounds - the numerator
inline int wfcJavelinNormalNum()
    { return 5; }

// the ordinary javelin rate denominator
inline int wfcJavelinNormalDen()
    { return 2; }

// fighting from the back of a moving mount, his rate of fire is reduced to 2
// attacks per round - the numerator
inline int wfcJavelinMountedNum()
    { return 2; }

// the mounted javelin rate denominator: 2/1, one step down the scale
inline int wfcJavelinMountedDen()
    { return 1; }

// the mounted missile attacker suffers a -1 penalty to hit if the mount is
// moving at less than half of its full normal rate
inline int wfcMountSlowPenalty()
    { return 1; }

// the penalty is -3 for a speed of one-half or more but less than
// three-quarters of normal
inline int wfcMountMidPenalty()
    { return 3; }

// the penalty is -5 for a speed of three-quarters normal or greater
inline int wfcMountFastPenalty()
    { return 5; }

// the mount-speed penalties are in addition to all others - range,
// visibility, etc. - that may apply
inline bool wfcSpeedPenaltiesCumulative()
    { return true; }

// it is not possible to use a missile weapon with success if the mount is
// turned at an angle of more than 45 degrees during the round in which firing
// is attempted
inline int wfcTurnLimitDeg()
    { return 45; }

// missile fire is impossible while the mount is performing complex maneuvers
inline bool wfcComplexManeuversBlock()
    { return true; }

// at the Dungeon Master's discretion, missile combat from the back of a
// moving land-based mount may be impossible in terrain conditions where the
// rider is forced to use at least one hand to hold onto his mount
inline bool wfcTerrainMayBlock()
    { return true; }

// as noted in the Dungeon Master's Guide on page 53, on a flying mount short
// range is treated as medium range for to-hit modifiers unless the mount is
// hovering
inline bool wfcFlyingShortAsMedium()
    { return true; }

// medium range from a flying mount is considered long range for to-hit
// modifiers unless hovering
inline bool wfcFlyingMediumAsLong()
    { return true; }

// the Dungeon Master's Guide page carrying the flying-mount missile range
// penalties
inline int wfcDmgMountRefPage()
    { return 53; }

// a hovering rider suffers no additional to-hit penalties but still must
// abide by the reduction in rate of fire
inline bool wfcHoverNoExtraToHit()
    { return true; }

// ---- Forcing opponents to dismount ----

// a mounted character should always anticipate the possibility that his
// opponent may attack his mount or otherwise cause him to fall, and should be
// alert for the opportunity to separate a mounted opponent from its steed; an
// unseated opponent is at worst on equal terms with a character on the
// ground, at best disadvantaged if the character is still in the saddle
inline bool wfcDismountBothDirections()
    { return true; }

// if a land-based mount is killed while a character is riding it, the
// character instantly falls to the ground
inline bool wfcLandMountDeathFall()
    { return true; }

// a character with proficiency in riding the mount will land on his feet if
// he makes a successful Proficiency Check, and will be able to perform
// normally during the remainder of the round in which he falls
inline bool wfcRidingCheckLandsOnFeet()
    { return true; }

// a rider without proficiency, or whose check fails, takes a tumble suffering
// 1d3 points of damage
inline int wfcTumbleDmgDie()
    { return 3; }

// the tumbling rider must spend the remainder of the current round and all of
// the following round getting back to his feet and regaining his bearings
inline bool wfcTumbleRecoveryTwoRounds()
    { return true; }

// if a flying mount takes damage that brings it to less than half of its
// total hit points, the rider must immediately make a check to see if he
// falls, with further checks required in every round until the mount is
// brought to a landing or regains enough hit points to put it out of danger
inline bool wfcFlyingMountHalfHpChecks()
    { return true; }

// a cleric equipped with several cure wounds spells could keep his mount
// flying for quite a while, as long as the creature is among those that can
// be affected by such magic
inline bool wfcClericCanKeepMountFlying()
    { return true; }

// if a flying mount is killed while a character is aboard, the creature will
// plummet to the ground and most likely also carry the rider to his death,
// especially if the rider is securely strapped onto the mount (the
// close-to-the-ground tail rides to the next round)
inline bool wfcFlyingMountDeathPlummet()
    { return true; }

// the Dungeon Master may allow a character with proficiency in riding the
// mount to leap from its back and land safely on the ground - usually only
// when the mount is hovering, though the DM could grant the chance under
// other conditions with a die-roll modifier on the Proficiency Check
inline bool wfcLeapFromMount()
    { return true; }

// a mounted character using a melee weapon of at least 3 feet in length may
// be able to unseat a mounted opponent by getting a natural 20 on his to-hit
// roll
inline int wfcUnseatNaturalDie()
    { return 20; }

// the minimum weapon length for the natural-20 unseat attempt from the saddle
inline int wfcUnseatWeaponMinFt()
    { return 3; }

// if the unseat victim has riding proficiency and makes a successful
// Proficiency Check, he retains his seat; otherwise - if the check fails or
// the rider is not proficient - he falls to the ground and takes 1d3 points
// of damage
inline bool wfcUnseatProfCheckRetains()
    { return true; }

// a character standing on the ground can unseat a mounted opponent with a
// natural 20 on the die roll if using a weapon with a length of 5 to 9 feet -
// the short-range minimum
inline int wfcGroundUnseatShortMinFt()
    { return 5; }

// the short-range unseating weapon length maximum
inline int wfcGroundUnseatShortMaxFt()
    { return 9; }

// an attacker on the ground armed with a weapon of at least 10 feet in length
// can unseat a mounted opponent with a natural roll of 16-20 on the to-hit
// die
inline int wfcGroundUnseatLongMinFt()
    { return 10; }

// the long-weapon unseat roll minimum
inline int wfcGroundUnseatLongMinDie()
    { return 16; }

// the long-weapon unseat roll maximum
inline int wfcGroundUnseatLongMaxDie()
    { return 20; }

// a character - mounted or on foot - can attempt to unseat a mounted opponent
// by pulling him down: moving adjacent, diving toward his foe, and making a
// successful to-hit roll as if attacking with his bare hands to grapple
inline bool wfcPullDownGrapple()
    { return true; }

// if the pull-down attacker is not mounted, the to-hit roll is made at a -4
// penalty
inline int wfcGrappleUnmountedPenalty()
    { return 4; }

// the grappled mounted opponent is allowed a Proficiency Check, if
// applicable, to see if he remains on the mount; success means he has not
// been unseated and the attacker is clinging to him or the mount
inline bool wfcGrappleVictimProfCheck()
    { return true; }

// if the victim's check fails, both combatants fall to the ground and each
// suffers 1d6 points of damage
inline int wfcGrappleFallDmgDie()
    { return 6; }

// if the original grapple attempt fails, the attacker falls to the ground and
// suffers 1d6 points of damage
inline bool wfcGrappleFailAttackerFalls()
    { return true; }

// an attacker remaining clinging to a mounted opponent must make successful
// to-hit rolls in each subsequent round to remain in that position; failure
// on any roll means he has fallen with the usual effects
inline bool wfcClingToHitEachRound()
    { return true; }

// if the clinging attacker's to-hit roll in any round succeeds, the rider
// must make a Proficiency Check to prevent falling - and taking the attacker
// along with him
inline bool wfcRiderCheckOrBothFall()
    { return true; }

// at the Dungeon Master's discretion a rider may be able to use his weapon to
// attack a grappling opponent, but if such an attack is possible it is made
// with a -2 penalty to hit
inline bool wfcRiderMayAttackGrappler()
    { return true; }

}   // namespace rules
