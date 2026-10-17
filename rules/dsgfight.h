// =========================================================================================
// Adnd1 - rules/dsgfight.h
// The DSG COMBAT RULES FOR UNDERGROUND PLAY, R507: the printed pp. 30-33 (pdf
// 31-34; printed p. 31 = pdf 32 is the full-page combat illustration plate -
// the chapter text runs pp. 30 and 32-33 with the plummet-to/the-fate cut
// spanning the plate) - the fighting on walls and other sheer surfaces (the
// AC bonus loss, the flat -2, the elevation modifiers, the damage-forced
// Climbing Check, the dropped boulders), the fighting on bridges and ledges
// (the 5-foot rule, the hit-forced Dex Check, the push modifiers), the
// grabbing-an-enemy system (the 2-foot bar, the 1d20 vs AC 10, the -20%
// hanging checks, the rating assignments), the fighting in water (the depth
// ladder, the -4/-4, the exemptions) with the grappling-in-water
// modification, the fighting in narrow passages (the DMG frontage), the
// fighting in darkness (the -4/+4 set, the wild swing, the Dex/climbing
// cuts), the spellcasting in darkness (Table 9, the clue modifier), and the
// mounted combat (the species rules, the +1, the bow fire with Table 14 and
// the 45-degree limit) with the forcing-opponents-to-dismount tactics.
// census 431 -> 432.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR with the pdf
// Acrobat-Capture layer as the second read - every numeric cell
// dual-confirmed (Table 14 cell-for-cell: -1/-3/-5 both layers); the -10%
// climbing-check modifier is the % glyph OCR class (the 96 garble) and agrees
// const-for-const with the WSG half-hit-points pin; the clumsy-creature
// rating floor 0 carries the one residual caution (the % glyph unreadable,
// value 0 certain); the cross-book seam verified const-for-const against
// rules/wsgfight.h (R488) and the landed dmv/dmx/dnp DSG headers - NOTHING
// auto-credited; the seven flagged divergences (the bridge Dex-per-foot sign,
// the wall penalty frame, the elevation frame, the water depth ladder, the
// darkness penalty set, the mounted rate of fire, the bridge trigger) pinned
// as printed under the DSG prefix.
//
// The Table 14 speed bands encode as 0 (less than 1/2 normal), 1 (1/2 to less
// than 3/4), 2 (3/4 to maximum); the modifiers are the die-roll convention
// (-1/-3/-5). The grid sentinel is -99 with no NA cells (census 0/0). The
// DSG-internal cross-references (Table 9 course changes, the p. 12
// holding-breath rules, the p. 23 proficiency rules) pin as page-number
// consts.
//
namespace rules {

// ---- the chapter opener ----

// the rules cover melee and missile combat in unusual underground terrain.
inline bool dnqOpenerUnusualTerrain()
    { return true; }

// the suspended-midway-up-a-sheer-wall example.
inline bool dnqOpenerSheerWallExample()
    { return true; }

// the poised-atop-a-narrow-bridge example.
inline bool dnqOpenerNarrowBridgeExample()
    { return true; }

// the swimming-character-attacked example.
inline bool dnqOpenerSwimmingAttacked()
    { return true; }

// additional clarification of the effects of darkness follows.
inline bool dnqOpenerDarknessClarification()
    { return true; }

// the section closes with instructions and modified rules for the AD&D
// Battlesystem Fantasy Combat Supplement in the constricted conditions of the
// underearth.
inline bool dnqOpenerBattlesystemTail()
    { return true; }

// ---- fighting on walls and other sheer surfaces ----

// a climbing character loses all Armor Class bonuses from shield or
// Dexterity.
inline bool dnqWallNoShieldDexAcBonus()
    { return true; }

// a character whose face is toward the surface presents his back to any
// attacker.
inline bool dnqWallFaceToSurfaceBackExposed()
    { return true; }

// except an attacker next to him on the wall.
inline bool dnqWallBackExposedExceptAdjacent()
    { return true; }

// such a character can only face a foe to one side or the other.
inline bool dnqWallOneSideOrOther()
    { return true; }

// at least one hand is needed to hold on.
inline bool dnqWallOneHandHoldsOn()
    { return true; }

// the character cannot use multiple weapons.
inline bool dnqWallNoMultipleWeapons()
    { return true; }

// the flat -2 penalty assessed to all attack, damage, and save rolls on a
// sheer surface (the WSG splits cliff -2 attacks and saves / severe slope -1
// attacks - the DSG adds damage rolls and drops the slope distinction, pinned
// as printed).
inline int dnqWallAtkDmgSavePenalty()
    { return 2; }

// if combatants are above or below their opponents during a wall fight,
// specific modifiers apply.
inline bool dnqWallAboveBelowModifiers()
    { return true; }

// the higher character gains a +2 to-hit modifier in addition to all others
// that apply.
inline int dnqWallHigherAtkBonus()
    { return 2; }

// the lower character suffers a -2 modifier to his attack rolls.
inline int dnqWallLowerAtkPenalty()
    { return 2; }

// a place of some security reached before combat may cancel some or all of
// the penalties (the DM's judgment).
inline bool dnqWallSecurePlaceMayCancel()
    { return true; }

// the archer who carefully selects a ledge from which he can easily see his
// targets and draw his bow fires normally.
inline bool dnqWallArcherLedgeExample()
    { return true; }

// the swordsman firmly balanced on a large boulder has the advantage over
// opponents scrambling up to reach him.
inline bool dnqWallBoulderSwordsmanExample()
    { return true; }

// a character on a sheer surface struck for any amount of damage must make an
// immediate Climbing Check.
inline bool dnqWallDamageClimbingCheck()
    { return true; }

// the check succeeds: the character remains in place; it fails: the character
// falls.
inline bool dnqWallCheckFailFalls()
    { return true; }

// the damage-inflicted modifier applies when the damage is equal to or
// greater than 1/2 of the character's total hit points.
inline bool dnqWallHalfHpTrigger()
    { return true; }

// the half-total-hit-points figure is rounded up.
inline bool dnqWallHalfHpRoundedUp()
    { return true; }

// the -10% modifier to the Climbing Check on a half-or-more total-hit-points
// hit (the % glyph OCR class; agrees const-for-const with the WSG
// wfcBigDamageCheckPenalty).
inline int dnqWallHalfHpCheckPenalty()
    { return 10; }

// creatures defending a wall or cliff often roll or drop heavy objects onto
// attackers below.
inline bool dnqWallBoulderTactic()
    { return true; }

// the average-sized boulder is three feet in diameter.
inline int dnqBoulderDiameterFt()
    { return 3; }

// the boulder inflicts 2d8 points of damage: two dice.
inline int dnqBoulderDamageDice()
    { return 2; }

// the boulder damage die: d8.
inline int dnqBoulderDamageSides()
    { return 8; }

// all victims are treated as AC 10 for purposes of these attacks.
inline bool dnqBoulderVictimAcTen()
    { return true; }

// if the creatures dropping the missile cannot pick it up and hurl it (as a
// giant could), they suffer a -8 modifier to their attack roll.
inline int dnqBoulderCannotHurlPenalty()
    { return 8; }

// victims climbing a sheer cliff could be knocked off by this attack, as
// given by the fall rules.
inline bool dnqBoulderKnocksOffClimbers()
    { return true; }

// ---- fighting on bridges and ledges ----

// the bridges-and-ledges situations assume the character has room to stand
// somewhere without using his hands to hold on.
inline bool dnqBridgeStandWithoutHands()
    { return true; }

// the rule applies if some sort of drop-off is located within five feet of
// the character.
inline int dnqBridgeDropoffWithinFt()
    { return 5; }

// all the difficulties relate to hits against the character; there are no
// penalties for attacking in this situation.
inline bool dnqBridgeHitPenaltiesOnly()
    { return true; }

// a character hit by any attack that causes a loss of hit points or
// consciousness (such as a sleep spell) must make a successful Dexterity
// Check to avoid falling over the nearby drop-off.
inline bool dnqBridgeHitForcesDexCheck()
    { return true; }

// the Dexterity for the check is increased by two for every foot of distance
// between the character's feet and the drop-off (OPPOSITE SIGN to the WSG
// edge rule, which reads -2 per foot - the round's true cross-book
// divergence, pinned as printed).
inline int dnqBridgeDexPerFoot()
    { return 2; }

// the Dexterity is also modified if the force of the blow pushes the
// character toward or away from the drop-off.
inline bool dnqBridgePushTowardAway()
    { return true; }

// in melee a character with his back to a wall receives a +2 modifier to his
// Dexterity.
inline int dnqBridgeBackToWallDex()
    { return 2; }

// a character with his back to a drop-off receives a -2 penalty.
inline int dnqBridgeBackToDropoffDex()
    { return 2; }

// during missile combat the path of the missile serves as a good indicator of
// whether a character is pushed toward or away from a drop-off.
inline bool dnqBridgeMissilePathIndicator()
    { return true; }

// the character on a narrow bridge struck by an arrow from his left side is
// propelled toward the drop-off on his right.
inline bool dnqBridgeArrowExample()
    { return true; }

// the character on a ledge with his back to the wall and enemies before him
// is pushed back toward the wall by any blow.
inline bool dnqBridgeLedgeExample()
    { return true; }

// the push modifier is a + or -2 to Dexterity, applied in addition to all
// other modifiers.
inline int dnqBridgePushMod()
    { return 2; }

// ---- grabbing an enemy ----

// the grab rule is used when a character is fighting in extremely close
// quarters and falls from a sheer surface or a narrow ledge or bridge.
inline bool dnqGrabCloseQuartersOnly()
    { return true; }

// the rule is only used when at least one character fights with a weapon of
// less than two feet, or when the characters are grappling.
inline bool dnqGrabOrGrappling()
    { return true; }

// the grab-eligible weapon length bar: less than two feet.
inline int dnqGrabWeaponMaxFt()
    { return 2; }

// the falling character can make one attempt to grab his enemy as he falls.
inline bool dnqGrabOneAttempt()
    { return true; }

// the grab attempt is a normal attack roll on 1d20 that would hit the other
// character.
inline int dnqGrabAttackDie()
    { return 20; }

// the target is AC 10 minus Dexterity bonuses.
inline int dnqGrabAcBase()
    { return 10; }

// the target receives no benefit for armor or shield.
inline bool dnqGrabNoArmorShieldBenefit()
    { return true; }

// no magical bonuses for weapons apply to the grab attack roll.
inline bool dnqGrabNoWeaponMagicBonus()
    { return true; }

// any weapon held must be dropped for the attempt to be made.
inline bool dnqGrabWeaponMustDrop()
    { return true; }

// on a successful roll the character has grabbed some part of his opponent's
// body.
inline bool dnqGrabSuccessGrabsBody()
    { return true; }

// the grabbed character rolls a Climbing Check if on a wall.
inline bool dnqGrabbedWallClimbingCheck()
    { return true; }

// the grabbed character rolls a Dexterity Check on a ledge or bridge.
inline bool dnqGrabbedLedgeDexCheck()
    { return true; }

// if the check fails, both characters plummet to the fate that awaits them
// below.
inline bool dnqGrabbedCheckFailBothFall()
    { return true; }

// if the check succeeds, the grabbed character retains his position, with his
// opponent clinging tenuously to his leg (or whatever).
inline bool dnqGrabbedCheckSuccessRetains()
    { return true; }

// the character hanging onto his opponent cannot make any attacks.
inline bool dnqHangingCannotAttack()
    { return true; }

// the hanging character can make a Climbing Check with a -20% modifier to
// regain his hold on the wall or his footing on the ledge.
inline int dnqHangingRegainCheckPenalty()
    { return 20; }

// a successful regain check: the character has regained his place.
inline bool dnqHangingRegainSuccess()
    { return true; }

// an unsuccessful regain check: the character remains clinging desperately to
// his opponent.
inline bool dnqHangingFailStaysClinging()
    { return true; }

// the opponent can attack the clinging character normally.
inline bool dnqClingOpponentAttacksNormally()
    { return true; }

// any successful hit on the clinging character requires another Climbing
// Check with a -20% modifier.
inline int dnqClingHitCheckPenalty()
    { return 20; }

// failure on the hit check means the clinging character falls and his
// opponent remains on the wall.
inline bool dnqClingCheckFailFalls()
    { return true; }

// if anything else causes the character retaining his hold to fall, both
// characters fall.
inline bool dnqClingOtherCauseBothFall()
    { return true; }

// even if characters are grappled together when they fall, they separate
// immediately.
inline bool dnqFallingGrappledSeparate()
    { return true; }

// a magic-user might be able to cast a spell before hitting the bottom while
// his less fortunate opponent plummets to a hard landing.
inline bool dnqFallingSpellPossible()
    { return true; }

// when characters fight creatures without Climbing Ratings or Dexterity
// Scores, the DM assigns a Climbing Rating based on natural abilities or lack
// thereof.
inline bool dnqAssignRatingToCreatures()
    { return true; }

// the natural-climber band floor: monkeys, spiders and other natural climbers
// fall into the 80-95% range.
inline int dnqNaturalClimberRatingLo()
    { return 80; }

// the natural-climber band ceiling: 95%.
inline int dnqNaturalClimberRatingHi()
    { return 95; }

// mountain goats and llamas might rate 70%.
inline int dnqGoatLlamaRating()
    { return 70; }

// clumsier creatures could rate as low as 0 (the OCR caution cell: the %
// glyph unreadable, the value 0 certain).
inline int dnqClumsyRatingFloor()
    { return 0; }

// ---- fighting in water ----

// water interferes with the fighting effectiveness of characters and
// creatures not bred for that environment.
inline bool dnqWaterInterferesWithFighting()
    { return true; }

// standing in water less than waist deep: none of the combat penalties apply.
inline bool dnqWaterBelowWaistNoPenalty()
    { return true; }

// water waist deep to chest deep: the penalties are halved.
inline bool dnqWaterWaistToChestHalved()
    { return true; }

// swimming or standing in water above the chest: the penalties are fully in
// effect.
inline bool dnqWaterAboveChestOrSwimFull()
    { return true; }

// attacks by creatures not at home in water suffer a -4 penalty on the 1d20
// attack roll.
inline int dnqWaterAttackPenalty()
    { return 4; }

// a successful water attack suffers a -4 modifier to the damage it would
// normally inflict.
inline int dnqWaterDamagePenalty()
    { return 4; }

// water-modified damage can be reduced to no less than 1 point.
inline int dnqWaterDamageFloor()
    { return 1; }

// any creature that spends part of its life in the water is not penalized
// while fighting in it.
inline bool dnqWaterNativeExempt()
    { return true; }

// a character with swimming proficiency is not penalized while fighting in
// the water.
inline bool dnqWaterSwimProfExempt()
    { return true; }

// the grappling-in-water modification is for use with the Weaponless Combat
// System listed on page 106 of Unearthed Arcana.
inline int dnqWaterGrappleUaPage()
    { return 106; }

// using these rules, characters can attempt to pull their opponents
// underwater and hold them under until they drown.
inline bool dnqWaterGrapplePullUnder()
    { return true; }

// a grappling-in-water attack can only be successful in water at least 1/3 of
// the victim's height.
inline bool dnqWaterGrappleDepthRule()
    { return true; }

// the depth fraction numerator: 1/3 of the victim's height.
inline int dnqWaterGrappleDepthNum()
    { return 1; }

// the depth fraction denominator: 1/3.
inline int dnqWaterGrappleDepthDen()
    { return 3; }

// the grapple attempt can be made without the penalties that would apply to
// an attack with a weapon.
inline bool dnqWaterGrappleNoWeaponPenalties()
    { return true; }

// if the grapple is successful, both characters go under the surface of the
// water.
inline bool dnqWaterGrappleBothGoUnder()
    { return true; }

// the grappling character is assumed to have taken a deep breath of air (as
// per the swimming rules) before going under.
inline bool dnqWaterGrappleAttackerBreath()
    { return true; }

// the grappled character must make a saving throw vs. paralyzation to get
// such a breath of air.
inline bool dnqWaterGrappleVictimParalysisSave()
    { return true; }

// a failed save means the character is assumed to have been dragged under
// before he could take a breath.
inline bool dnqWaterGrappleNoBreathIfFailed()
    { return true; }

// the characters remain underwater until the hold is broken.
inline bool dnqWaterGrappleUnderUntilHoldBroken()
    { return true; }

// the hold-broken explanation sits on page 108 of Unearthed Arcana.
inline int dnqWaterGrappleHoldPage()
    { return 108; }

// the Holding Breath section on page 12 of the DSG gives the length of time a
// character can hold his breath.
inline int dnqWaterGrappleBreathRefPage()
    { return 12; }

// ---- fighting in narrow passages ----

// a common defensive barrier in caves is the bottleneck passage where only
// one or two characters can hold off a mob of attackers.
inline bool dnqNarrowBottleneckTactic()
    { return true; }

// only one or two characters hold off the mob at a bottleneck.
inline bool dnqNarrowOneOrTwoHolders()
    { return true; }

// page 69 of the DMG provides the combat-frontage description.
inline int dnqNarrowDmgFrontagePage()
    { return 69; }

// page 70 of the DMG completes the combat-frontage description.
inline int dnqNarrowDmgFrontagePage2()
    { return 70; }

// the bottleneck tactic limits the number of enemies that can attack at once.
inline bool dnqNarrowLimitsAttackers()
    { return true; }

// the bonus is usable by monsters and NPCs as well.
inline bool dnqNarrowMonstersNpcsToo()
    { return true; }

// the location can be used defensively as protection from the enemy's attacks
// or aggressively as a means of striking the enemy at an advantage.
inline bool dnqNarrowDefensiveOrAggressive()
    { return true; }

// the side claiming the bonus must have sufficient room for all fighting
// individuals to use their weapons without interfering with each other.
inline bool dnqNarrowRoomForAllRequired()
    { return true; }

// ---- fighting in darkness ----

// characters who cannot see in the dark run serious risks when participating
// in combat: greatly reduced success, the chance of wounding an ally or
// striking an obstacle, and treacherous terrain features such as cliffs, pits
// or pools.
inline bool dnqDarkCannotSeeRisks()
    { return true; }

// the -4 penalty to all attack rolls for characters who cannot see (the WSG
// splits -3 natural / -4 total on attacks only - the DSG flat -4 agrees with
// the total-dark value, pinned as printed).
inline int dnqDarkAttackPenalty()
    { return 4; }

// the -4 penalty to all saving throws in darkness.
inline int dnqDarkSavePenalty()
    { return 4; }

// the -4 penalty to all damage rolls in darkness.
inline int dnqDarkDamagePenalty()
    { return 4; }

// the +4 penalty to Armor Class in darkness.
inline int dnqDarkAcPenalty()
    { return 4; }

// even with the penalties, a successful attack cannot cause less than 1 point
// of damage.
inline int dnqDarkDamageFloor()
    { return 1; }

// all bonuses that require a character to see his victim are forfeited.
inline bool dnqDarkForfeitsSightBonuses()
    { return true; }

// the forfeited-bonus examples: a ranger's bonuses against giants, a thief's
// backstab attack, and a vorpal sword's beheading function.
inline bool dnqDarkForfeitExamples()
    { return true; }

// the penalties do not apply to characters with infravision.
inline bool dnqDarkInfravisionExempt()
    { return true; }

// the penalties do not apply to characters wielding magical weapons.
inline bool dnqDarkMagicWeaponExempt()
    { return true; }

// the penalties do not apply to characters within range of any source of
// light.
inline bool dnqDarkLightSourceExempt()
    { return true; }

// a cannot-see character within twice his weapon length of any ally, other
// opponents, walls, chairs or other obstacles stands a chance of striking one
// of these instead of his target.
inline bool dnqDarkWildSwingObjects()
    { return true; }

// if the attack roll misses with a modified result of 0 or less, the attack
// has unintentionally struck another object.
inline int dnqDarkWildSwingThreshold()
    { return 0; }

// any object closer to the character than twice his weapon's length may be
// hit.
inline int dnqDarkWildSwingRadiusMult()
    { return 2; }

// count up all the objects within the weapon's reach, then roll randomly to
// determine which is hit.
inline bool dnqDarkWildSwingCountRoll()
    { return true; }

// a cannot-see character fighting next to a drop-off or on a sheer surface
// has his Dexterity reduced for purposes of all Dexterity Checks to see if he
// falls over the drop-off.
inline bool dnqDarkDropoffDexCheck()
    { return true; }

// the Dexterity reduction near a drop-off or on a sheer surface in darkness:
// -2 (agrees with the WSG total-dark precarious modifier).
inline int dnqDarkDexCheckPenalty()
    { return 2; }

// the Climbing Rating is reduced for purposes of all Climbing Checks in
// darkness.
inline bool dnqDarkClimbingCheckCut()
    { return true; }

// the Climbing Rating reduction in darkness: -10% (agrees with the WSG
// total-dark climbing cut).
inline int dnqDarkClimbingCut()
    { return 10; }

// if a spellcaster cannot see the target of his spell, there is a chance the
// spell might affect something besides the intended target.
inline bool dnqDarkSpellOffTargetRisk()
    { return true; }

// the player must indicate exactly where the spell is targeted.
inline bool dnqDarkSpellPlayerIndicates()
    { return true; }

// the DM then makes a secret roll on Table 9: Course Changes in Darkness to
// determine where the spell really goes off.
inline bool dnqDarkSpellDmSecretRoll()
    { return true; }

// the DSG course-changes table consulted for spells cast in darkness: Table 9
// (landed R505 as the dmx darkness grid).
inline int dnqDarkSpellCourseTable()
    { return 9; }

// if the spellcaster has a clue to the location of the target (noise or
// smell, for example), the DM may assign a modifier to the Table 9 roll.
inline bool dnqDarkSpellClueMods()
    { return true; }

// the clue modifier floor: -1.
inline int dnqDarkSpellClueModLo()
    { return 1; }

// the clue modifier ceiling: -3.
inline int dnqDarkSpellClueModHi()
    { return 3; }

// ---- the mounted combat rules ----

// the sweeping charges of vast ranks of cavalry are not as common in the
// realms of the Underdark as upon the surface.
inline bool dnqMountCavalryRareUnderground()
    { return true; }

// many of the races living beneath the surface maintain a stable of
// appropriate mounts.
inline bool dnqMountUnderdarkStables()
    { return true; }

// a steed must have been trained for combat to function as a mount during it.
inline bool dnqMountTrainedRequired()
    { return true; }

// the steed must be of a species appropriate to such combat.
inline bool dnqMountSpeciesAppropriate()
    { return true; }

// mules are inappropriate combat mounts.
inline bool dnqMuleInappropriate()
    { return true; }

// the mule disqualifiers: lack of speed, maneuverability, and fearlessness.
inline bool dnqMuleLackSpeedManeuverFearless()
    { return true; }

// horses can be trained to fight in underground conditions.
inline bool dnqHorseTrainableUnderground()
    { return true; }

// horses rely heavily on the sense of sight.
inline bool dnqHorseReliesOnSight()
    { return true; }

// horses are unusable in situations of total darkness.
inline bool dnqHorseUnusableTotalDark()
    { return true; }

// steeds employed by the races of the Underdark include griffons, nightmares,
// dire wolves, giant striders, giant lizards, and rothe.
inline bool dnqUnderdarkSteedList()
    { return true; }

// horses are used if illumination permits.
inline bool dnqHorseIlluminationPermits()
    { return true; }

// horses are especially favored for raiding parties that venture onto the
// surface during the dark of night.
inline bool dnqHorseNightRaids()
    { return true; }

// the mounted character's height advantage serves to protect him from
// opponents' attacks and gives him an advantage when he attacks.
inline bool dnqMountedHeightAdvantage()
    { return true; }

// the +1 modifier on all attack rolls made by a mounted character against an
// opponent who is not mounted.
inline int dnqMountedVsFootBonus()
    { return 1; }

// when the character standing on the ground attacks, any roll that exactly
// equals the number needed to hit strikes the mount instead of the mounted
// character.
inline bool dnqExactHitStrikesMount()
    { return true; }

// the exact-hit procedure is only used if the rider is the intended victim.
inline bool dnqExactHitOnlyIfRiderTarget()
    { return true; }

// a character can always choose to attack the mount instead of the rider.
inline bool dnqChooseMountTarget()
    { return true; }

// mounted bowmen create a formidable force, combining speed with the ability
// to attack from a distance.
inline bool dnqMountedBowFormidable()
    { return true; }

// a mounted archer can often ride close to his enemy, shoot an arrow, and
// ride away again before the enemy can react.
inline bool dnqMountedBowRideShootRide()
    { return true; }

// any character can fire a bow from a mount that is not moving, without
// negative modifiers.
inline bool dnqMountedBowStationaryNoPenalty()
    { return true; }

// to shoot from a moving steed the character must have horsemanship
// proficiency.
inline bool dnqMountedBowMovingNeedsHorsemanship()
    { return true; }

// to shoot from a moving steed the character must also have a bow weapon
// proficiency.
inline bool dnqMountedBowMovingNeedsBowProf()
    { return true; }

// the character needs both hands to fire the bow and thus must guide his
// mount with his knees.
inline bool dnqMountedBowBothHandsKnees()
    { return true; }

// the DM can rule that terrain because of steepness, slipperiness or very
// rough ground requires the character to hold the reins, preventing mounted
// bow fire.
inline bool dnqMountedBowTerrainBar()
    { return true; }

// shortbows can be fired by mounted characters.
inline bool dnqShortbowAllowed()
    { return true; }

// composite shortbows can be fired by mounted characters.
inline bool dnqCompositeShortbowAllowed()
    { return true; }

// light crossbows can be fired by mounted characters.
inline bool dnqLightCrossbowAllowed()
    { return true; }

// the mounted rate of fire is less than when unmounted.
inline bool dnqMountedRofLessThanUnmounted()
    { return true; }

// the rate-of-fire example numerator: a character who normally attacks at
// 2/1.
inline int dnqMountedRofExampleFromNum()
    { return 2; }

// the rate-of-fire example denominator: 2/1.
inline int dnqMountedRofExampleFromDen()
    { return 1; }

// the mounted rate for the 2/1 archer: 1/1 (the DSG halves the rate - the WSG
// one-step-down-the-scale rule reads 2/1 to 3/2; the divergence is pinned as
// printed).
inline int dnqMountedRofExampleToNum()
    { return 1; }

// the mounted rate denominator for the 2/1 archer: 1/1.
inline int dnqMountedRofExampleToDen()
    { return 1; }

// the second rate example: a rate of 3/1.
inline int dnqMountedRofSecondFromNum()
    { return 3; }

// the mounted rate for the 3/1 archer: 3/2.
inline int dnqMountedRofSecondToNum()
    { return 3; }

// the mounted rate denominator for the 3/1 archer: 3/2, etc.
inline int dnqMountedRofSecondToDen()
    { return 2; }

// the character also suffers penalties to hit based on the speed of the mount
// at the time the attack is made, as shown on Table 14: Mounted Bow Fire.
inline bool dnqMountedSpeedPenaltyTable()
    { return true; }

// the Table 14 modifiers are cumulative with all others that apply.
inline bool dnqT14Cumulative()
    { return true; }

// during the round he fires, the rider cannot perform maneuvers with his
// mount, except for slight turning.
inline bool dnqFireRoundNoManeuvers()
    { return true; }

// the most the mount can turn during the firing round is 45 degrees to either
// side of its current direction.
inline int dnqFireRoundTurnLimitDeg()
    { return 45; }

// only slight turning is permitted while firing.
inline bool dnqSlightTurningOnly()
    { return true; }

// sharper turns and complicated maneuvers require the character to hold on
// and prevent the use of a bow.
inline bool dnqSharperTurnsRequireHold()
    { return true; }

// these rules apply to riders on all types of mounts.
inline bool dnqMountedRulesAllMounts()
    { return true; }

// if the steed is flying, additional penalties apply as listed in the DMG,
// page 53, under Aerial Missile Fire.
inline bool dnqFlyingAdditionalPenalties()
    { return true; }

// the DMG page for the flying-steed missile penalties: 53.
inline int dnqFlyingDmgRefPage()
    { return 53; }

// ---- forcing opponents to dismount ----

// special tactics evolved to allow opponents on the ground to even the odds
// with the mounted warrior.
inline bool dnqDismountEvensOdds()
    { return true; }

// knocking the rider off more than evens the odds: the rider is generally
// stunned, injured, or at the very least prone after falling from his mount.
inline bool dnqDismountRiderStunnedProne()
    { return true; }

// there are several methods for dismounting an opponent, some heroic and
// others merely grim and efficient.
inline bool dnqDismountMethodsHeroicOrGrim()
    { return true; }

// by far the most direct method is to slay the mount.
inline bool dnqSlayMountMostDirect()
    { return true; }

// the disadvantage to slaying the mount: it is no longer useful to anyone.
inline bool dnqSlayMountSteedLost()
    { return true; }

// in many cases it is more beneficial to try to remove the rider and capture
// the steed.
inline bool dnqCaptureSteedBetter()
    { return true; }

// if a steed is killed while a character is mounted upon it, the character
// automatically falls to the ground.
inline bool dnqMountDeathAutoFall()
    { return true; }

// a character with horsemanship proficiency (the proficiency rules, page 23)
// is entitled to a Proficiency Check to see if he lands on his feet.
inline bool dnqMountDeathProfCheckLandsFeet()
    { return true; }

// on a successful check the character remains upright and can continue to act
// normally, even attacking that same round if he has not attacked yet.
inline bool dnqMountDeathContinueActing()
    { return true; }

// the failed-or-unproficient dismount fall damage: 1d3 - one die.
inline int dnqMountDeathFallDmgDice()
    { return 1; }

// the dismount fall damage die: d3.
inline int dnqMountDeathFallDmgSides()
    { return 3; }

// the fallen character can perform no further functions that round.
inline bool dnqMountDeathNoFurtherFunctions()
    { return true; }

// the fallen character must spend the entire next round climbing to his feet.
inline bool dnqMountDeathNextRoundToFeet()
    { return true; }

// the unseat attempt requires a melee weapon of three feet or greater length
// wielded by another mounted character.
inline int dnqUnseatWeaponMinFt()
    { return 3; }

// the unseat attempt requires an attack roll of natural 20.
inline int dnqUnseatNaturalDie()
    { return 20; }

// when the natural-20 hit lands, there is a chance the victim is knocked from
// his mount.
inline bool dnqUnseatKnockChance()
    { return true; }

// a rider without horsemanship proficiency is automatically knocked to the
// ground.
inline bool dnqUnseatNoProfAutoFall()
    { return true; }

// the unproficient unseat victim suffers an additional 1d3 points of damage.
inline int dnqUnseatNoProfExtraDmgSides()
    { return 3; }

// a rider with horsemanship proficiency is allowed a Proficiency Check;
// success retains his seat with no ill effects beyond the damage caused by
// the attack.
inline bool dnqUnseatProfCheckRetains()
    { return true; }

// a failed unseat Proficiency Check drops the character with the effect
// previously noted.
inline bool dnqUnseatCheckFailFalls()
    { return true; }

// fighters on foot armed with weapons of five to nine feet have the same
// chance of unhorsing riders as mounted attackers.
inline int dnqFootUnseatShortMinFt()
    { return 5; }

// the foot-soldier short-weapon ceiling: nine feet.
inline int dnqFootUnseatShortMaxFt()
    { return 9; }

// riders have the same chance of remaining in the saddle in both instances.
inline bool dnqFootUnseatRidersSameBothWays()
    { return true; }

// foot soldiers using weapons of 10 feet or greater lengths have a 25% chance
// of dismounting riders.
inline int dnqFootUnseatLongMinFt()
    { return 10; }

// the long-weapon dismount chance: 25%.
inline int dnqFootUnseatLongPct()
    { return 25; }

// the long-weapon dismount roll: 16-20 on the attack roll.
inline int dnqFootUnseatLongDieLo()
    { return 16; }

// the long-weapon dismount roll ceiling: 20.
inline int dnqFootUnseatLongDieHi()
    { return 20; }

// riders with horsemanship proficiency are allowed a check to remain in the
// saddle against the long-weapon dismount.
inline bool dnqFootUnseatLongCheckAllowed()
    { return true; }

// a mounted attacker can attempt to dive on another rider by moving adjacent
// to him and leaping from the saddle.
inline bool dnqDiveByMounted()
    { return true; }

// a successful dive attack roll means the attacker has grappled the other
// rider.
inline bool dnqDiveSuccessGrapples()
    { return true; }

// a missed dive attack roll drops the attacker to the ground.
inline bool dnqDiveMissAttackerFalls()
    { return true; }

// the missed-dive fall damage: 1d6.
inline int dnqDiveMissFallDmgSides()
    { return 6; }

// the grappled rider may be allowed a check against his horsemanship
// proficiency.
inline bool dnqDiveVictimProfCheck()
    { return true; }

// a successful check means the grappled character remains in the saddle with
// the other character hanging from his side.
inline bool dnqDiveCheckSuccessStays()
    { return true; }

// if the check is not allowed or fails, both characters fall to the ground.
inline bool dnqDiveCheckFailBothFall()
    { return true; }

// the both-fall damage: 1d6 each.
inline int dnqDiveBothFallDmgSides()
    { return 6; }

// if the rider remains mounted with his attacker clinging to him, the
// procedure is repeated in subsequent rounds.
inline bool dnqDiveRepeatSubsequentRounds()
    { return true; }

// to keep his place, the attacker must successfully roll to hit each round.
inline bool dnqClingNeedsToHit()
    { return true; }

// on each cling hit the rider must make another Proficiency Check to remain
// in the saddle.
inline bool dnqClingRiderRechecks()
    { return true; }

// a rider can use a weapon to attack a grappling opponent.
inline bool dnqRiderMayAttackGrappler()
    { return true; }

// all rider attacks against a grappling opponent are made with a -2 modifier
// to hit (the WSG pins the permission but not the -2 - a DSG-only value).
inline int dnqRiderGrapplerAtkPenalty()
    { return 2; }

// ---- the Table 14 mounted bow fire grid ----

// the Table 14 Mounted Bow Fire grid: three speed bands.
inline int dnqT14RowCount()
    { return 3; }

// the mount-speed band: 0 = less than 1/2 normal, 1 = 1/2 to less than 3/4
// normal, 2 = 3/4 to maximum speed.
inline int dnqT14Band(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        default:
            return -99;
        }
    }

// the modifier to hit by band: -1, -3, -5 (agrees const-for-const with the
// WSG mount-speed penalties wfcMountSlow/Mid/FastPenalty).
inline int dnqT14Mod(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -3;
        case 2:
            return -5;
        default:
            return -99;
        }
    }

}   // namespace rules
