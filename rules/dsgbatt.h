// =========================================================================================
// Adnd1 - rules/dsgbatt.h
// The DSG BATTLESYSTEM OPTIONS UNDERGROUND, R508: the printed pp. 34-35 (pdf
// 35-36) - the opener (battles every bit as common underground, the new
// tactics, the any-scenario rule), the extremely narrow frontages (the 1/2-
// and 3/4-inch bottleneck figures), the combat modifiers (the 10% wounded
// marker vs the standard 25%, with the orc-figure example), the formation
// modifiers (the column formation, the 1-inch-10-yards scale, the
// shape-changing figure at twice lengthwise space, the narrower-corridor
// spacing), the morale effects (the no-room auto-rout and the chain reaction
// through the blocking friendly unit), the ventilation effects (the doubled
// gas durations, the wind-carried spell gas at 1/2 the area diameter), the
// flying effects (the 240/60/30 ceiling bands with the altitude thirds), the
// line-of-sight effects (the +6 Attack Rating composite of the -4 attacks and
// damage, the -4 saves, +4 AC vs melee, 1/3 movement, the first-rank obstacle
// rule, the one-light-per-figure negation, the +2 missile benefit against
// illuminated units) and the cave-ins (the 6d8 ceiling collapse halved on a
// save with the 60-dice orc example, the 4d8 mud fall, the 1% base with the
// +4% cumulative sub-25 increase and the heavy-unit 13-to-26 doubling) - PLUS
// the R507 chapter tail from the top of printed p. 34: the footman pull-down
// at -2/-4/-6 by mount speed and the stake defenses (two characters one hour
// per 10-foot square, the 1d4-1 stakes per 10-foot depth, the chain/plate
// barding reductions, the 2d6 per stake).
// census 432 -> 433.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR with the pdf
// Acrobat-Capture layer as the second read - every numeric cell
// dual-confirmed; the three garble classes settled: djvu 648 = 6d8 (proven by
// the 60-dice orc example at 10 orcs and the 4d8 mud read), djvu 496 = +4%
// (Acrobat "raised 4%"), djvu 1396 = 13% (Acrobat "13%", doubled to 26%); the
// dismount tail pins with this round per the content-density rule (it prints
// on the top of p. 34, past the R507 gap box's pp. 30-33) and CORRECTS the
// R507 record's "WSG-only -4 pull-down" note - the DSG pull-down is real but
// speed-band framed (-2/-4/-6) where the WSG pins the flat -4
// (wfcGrappleUnmountedPenalty); the +6 Attack Rating is the composite of the
// R507 dnqDark -4 attacks and damage, verified against rules/dsgfight.h and
// rules/wsgfight.h const-for-const - NOTHING auto-credited.
//
// Pure prose round - no printed grid, no tables, no sentinels. The
// Battlesystem figure-scale cells pin as inches-to-yards consts (1 inch = 10
// yards); the wounded-marker and collapse-chance cells pin as percent consts;
// the R507 tail pins under the same dnr prefix with the provenance note that
// it is the R507 chapter's own continuation text.
//
namespace rules {

// ---- the R507 tail: footmen pulling riders ----

// characters and creatures on foot can attempt to pull a rider from his horse
// - but only creatures that are man-sized or larger.
inline bool dnrFootmanPullManSizedOnly()
    { return true; }

// creatures larger than man-size count as two men for the pull attempt.
inline bool dnrFootmanPullLargerCountTwoMen()
    { return true; }

// the character on foot must first grab the rider as he passes by, with an
// attack roll modified by the speed of the mount.
inline bool dnrFootmanGrabAsPasses()
    { return true; }

// the pull-down slow band: the steed moving at 6 inches per round or less.
inline int dnrPullSlowMaxInches()
    { return 6; }

// the pull-down attack modifier in the slow band: -2.
inline int dnrPullSlowPenalty()
    { return 2; }

// the pull-down mid band opens at 7 inches per round.
inline int dnrPullMidMinInches()
    { return 7; }

// the pull-down mid band ceiling: 12 inches per round.
inline int dnrPullMidMaxInches()
    { return 12; }

// the pull-down attack modifier in the mid band: -4 (the WSG pins a flat -4
// for the unmounted pull-down - different framing, pinned as printed).
inline int dnrPullMidPenalty()
    { return 4; }

// the pull-down fast band opens above 12 inches per round.
inline int dnrPullFastMinInches()
    { return 12; }

// the pull-down attack modifier in the fast band: -6.
inline int dnrPullFastPenalty()
    { return 6; }

// a successful pull-down hit follows the same procedure as if the rider had
// been grappled by a mounted opponent.
inline bool dnrPullHitFollowsGrappleProcedure()
    { return true; }

// on a missed pull-down attempt with the steed moving faster than 12 inches
// per round, the steed gets a free set of attacks against the character on
// foot.
inline bool dnrPullMissFastFreeAttacks()
    { return true; }

// each additional footman grappling - up to 4 - applies a penalty to the
// rider's Proficiency Check.
inline int dnrPullExtraFootmanMax()
    { return 4; }

// the per-additional-footman penalty to the rider's Proficiency Check: -1.
inline int dnrPullExtraFootmanPenalty()
    { return 1; }

// a rider pulled from his mount by more than one person suffers no damage -
// his opponents actually cushion his fall.
inline bool dnrPullMultiPersonNoDamage()
    { return true; }

// a mount surrounded by eight man-sized creatures can be pulled down with its
// rider.
inline int dnrPullSurroundManSizedCount()
    { return 8; }

// a mount surrounded by four large creatures can be pulled down with its
// rider.
inline int dnrPullSurroundLargeCount()
    { return 4; }

// the surrounded case pulls down both the mount and the rider.
inline bool dnrPullBothMountAndRider()
    { return true; }

// during this combat both the mount and the rider are allowed their normal
// attacks.
inline bool dnrPullBothKeepNormalAttacks()
    { return true; }

// ---- the R507 tail: set defenses and stakes ----

// given time and material, set defenses can be prepared to dismount riders
// and stop horses.
inline bool dnrSetDefensesPreparable()
    { return true; }

// most of the set defenses are simple tricks and traps - a rope hung between
// two columns at the rider's height, a trip wire, etc.
inline bool dnrSetDefensesSimpleTricks()
    { return true; }

// the DM determines the chance of success for these types of traps.
inline bool dnrSetDefensesDmChance()
    { return true; }

// for defense against mounted attackers, sharpened stakes can be set in the
// ground.
inline bool dnrStakesSharpened()
    { return true; }

// it takes two characters to prepare a staked defensive area.
inline int dnrStakesPrepCharacters()
    { return 2; }

// the staked-area preparation time: one hour.
inline int dnrStakesPrepHours()
    { return 1; }

// the prepared stakes cover a 10-foot-square area.
inline int dnrStakesAreaFeetSq()
    { return 10; }

// the stakes run about four feet in length.
inline int dnrStakesLengthLoFt()
    { return 4; }

// the stakes run up to about five feet in length.
inline int dnrStakesLengthHiFt()
    { return 5; }

// the stakes require a supply of saplings, light wood, or spears.
inline bool dnrStakesNeedSaplings()
    { return true; }

// the defensive areas are easily spotted and can be avoided if there is an
// alternate route.
inline bool dnrStakesEasilySpotted()
    { return true; }

// a rider who wishes his mount to enter a staked area must make a
// horsemanship Proficiency Check, just as if trying a jump or leap.
inline bool dnrStakesEnterHorsemanshipCheck()
    { return true; }

// a failed check means the mount refuses to enter the area, although it
// continues moving in another direction if possible.
inline bool dnrStakesCheckFailRefuses()
    { return true; }

// a successful check means the mount enters the defended area.
inline bool dnrStakesCheckSuccessEnters()
    { return true; }

// the mount hits 0-3 stakes per 10-foot depth of the defenses: 1d4-1 (one
// die, minus 1).
inline int dnrStakesHitDiceMinus()
    { return 1; }

// the stakes-hit die: d4.
inline int dnrStakesHitDiceSides()
    { return 4; }

// the stakes hit per 10-foot-depth of the defenses.
inline int dnrStakesPerDepthFt()
    { return 10; }

// chain mail barding reduces the number of stakes that hit by -1.
inline int dnrStakesBardingChainReduction()
    { return 1; }

// plate barding reduces the number of stakes that hit by -2.
inline int dnrStakesBardingPlateReduction()
    { return 2; }

// each stake causes 2d6 points of damage to the mount: two dice.
inline int dnrStakeDamageDice()
    { return 2; }

// the stake damage die: d6.
inline int dnrStakeDamageSides()
    { return 6; }

// the stake damage applies whether or not the steed was charging at the time.
inline bool dnrStakeDamageChargingOrNot()
    { return true; }

// ---- the Battlesystem opener ----

// battles are every bit as common underground as on the surface - armed
// expeditions to the underearth, or subterranean races vying for control of
// key tunnel sections.
inline bool dnrBsBattlesCommonUnderground()
    { return true; }

// mass combat can be an instrument of every underground campaign.
inline bool dnrBsMassCombatInstrument()
    { return true; }

// the constricted nature of the underground environment demands a whole new
// set of tactics for warfare in the underearth.
inline bool dnrBsConstrictedNewTactics()
    { return true; }

// darkness and restrictions on flying create situations not commonly
// encountered above ground.
inline bool dnrBsDarknessFlyingNovel()
    { return true; }

// the optional Battlesystem rules are designed for the unusual battlefields
// of the underearth.
inline bool dnrBsForUnderearthBattlefields()
    { return true; }

// the rules also serve to clarify other types of combat, such as indoor or
// house-to-house warfare.
inline bool dnrBsClarifiesIndoorWarfare()
    { return true; }

// if all players are agreeable, the rules can be employed during any
// Battlesystem scenario.
inline bool dnrBsAnyScenarioIfAllAgree()
    { return true; }

// ---- extremely narrow frontages ----

// underground battlefields often possess terrain bottlenecks that allow a
// single figure to hold a gap against a long column of attackers.
inline bool dnrFrontBottleneckHoldsGap()
    { return true; }

// the narrow bottleneck figures: the 1/2-inch-wide figure denominator (one
// half inch).
inline int dnrFrontNarrowFigureHalfInch()
    { return 2; }

// the narrow bottleneck figures: the 3/4-inch-wide figure numerator-half
// (three quarters inch).
inline int dnrFrontNarrowFigureThreeQuarter()
    { return 3; }

// the Battlesystem rules are designed for combat between several figures at a
// time.
inline bool dnrFrontDesignedSeveralFigures()
    { return true; }

// the rules should be modified if only one or two figures face each other in
// combat.
inline bool dnrFrontModifyOneOrTwo()
    { return true; }

// ---- combat modifiers ----

// the wounded marker threshold underground: 10% or more of the figure's Hit
// Dice removed.
inline int dnrWoundedThresholdPct()
    { return 10; }

// the standard-rules wounded marker threshold: 25% or more - the underground
// rule is stricter.
inline int dnrWoundedStandardPct()
    { return 25; }

// the underground wounded threshold is stricter than the standard 25%.
inline bool dnrWoundedStricterThanStandard()
    { return true; }

// the worked example orc figure represents 10 orcs.
inline int dnrWoundedOrcFigureOrcs()
    { return 10; }

// the worked example orc figure carries a total of 10 Hit Dice.
inline int dnrWoundedOrcFigureHitDice()
    { return 10; }

// the orc figure is marked wounded if an attack inflicts 1-9 dice of damage:
// the floor 1.
inline int dnrWoundedOrcWoundedLoDice()
    { return 1; }

// the wounded-band ceiling in the orc example: 9 dice of damage still only
// wounds.
inline int dnrWoundedOrcWoundedHiDice()
    { return 9; }

// an attack inflicting less than one die of damage does not affect the
// figure.
inline bool dnrWoundedBelowOneDieNoEffect()
    { return true; }

// an attack inflicting 10 or more dice removes the figure.
inline int dnrWoundedRemovedDice()
    { return 10; }

// ---- formation modifiers ----

// movement through winding tunnels and narrow passages is difficult for
// military units in formation - such units generally move as long, thin
// columns.
inline bool dnrColTunnelsForceColumns()
    { return true; }

// a column formation displays as a line of figures, one figure wide and as
// long as the number of figures in the unit.
inline bool dnrColOneFigureWide()
    { return true; }

// a column is in its leader's command radius when the figure at its head is
// in the leader's command radius.
inline bool dnrColCommandRadiusAtHead()
    { return true; }

// a column pays no movement penalty for changing facing - as the tunnel
// winds, the column winds with it and still moves a distance equal to its
// movement rating.
inline bool dnrColNoFacingPenalty()
    { return true; }

// a unit in column formation is considered in open formation for purposes of
// morale checks.
inline bool dnrColOpenForMorale()
    { return true; }

// the Battlesystem game scale: 1 inch equals 10 yards.
inline int dnrScaleInchYards()
    { return 10; }

// at the game scale not even a 1/2-inch halfling or kobold figure could
// normally occupy a 10-foot-wide corridor.
inline bool dnrScaleHalflingCannotOccupy()
    { return true; }

// the individual creatures can still fit into the area, so the figure is
// assumed to change its shape to fit the tight confines.
inline bool dnrFigureChangesShape()
    { return true; }

// the figure actually occupies more space front to back than it does from
// side to side.
inline bool dnrFigureOccupiesMoreFrontToBack()
    { return true; }

// the tight-confines figure occupies twice as much space lengthwise as it
// normally would.
inline int dnrFigureLengthwiseMult()
    { return 2; }

// the extra space is always considered to lie to the back of the figure.
inline bool dnrFigureExtraSpaceToBack()
    { return true; }

// a 3/4-inch figure in a 1/3-inch corridor can be placed adjacent to an enemy
// figure in front of it.
inline bool dnrFigureAdjacentInFront()
    { return true; }

// if another figure, friendly or enemy, approaches from the rear, it can only
// move to within 3/4 inch of the original figure.
inline bool dnrFigureRearApproachLimit()
    { return true; }

// if a column or portion thereof occupies a corridor narrower than its
// figures, the figures must be placed twice as far apart as normal.
inline bool dnrColNarrowerFiguresSpread()
    { return true; }

// the twice-as-far-apart placement doubles the length of the column.
inline bool dnrColNarrowerDoublesLength()
    { return true; }

// ---- morale effects ----

// units in closed formation can suffer harmful morale effects if forced to
// break into open formation where they lack sufficient room.
inline bool dnrMoraleClosedBreaksHarmful()
    { return true; }

// a closed formation unit forced to break open can expand to the sides, or to
// the front or rear.
inline bool dnrMoraleExpandSidesFrontRear()
    { return true; }

// a closed formation unit without enough space to expand fully in at least
// one direction automatically routs.
inline bool dnrMoraleNoRoomAutoRouts()
    { return true; }

// if a routing formation is prohibited from performing its routing movement
// by the presence of a friendly unit - no possible retreat path around it -
// the unit blocking the path of retreat is automatically routed.
inline bool dnrMoraleRoutingBlockedRoutesBlocker()
    { return true; }

// the automatic routing can turn into a chain reaction of whatever length is
// required to clear a path for the routing units.
inline bool dnrMoraleChainReaction()
    { return true; }

// ---- ventilation effects ----

// if an underground battlefield has unusually good air circulation by natural
// or manufactured means, the ventilation rule should not be used.
inline bool dnrVentGoodCirculationSkip()
    { return true; }

// in most cases air circulates much more slowly underground than in the
// outside world - gases and smoke take much longer to disperse.
inline bool dnrVentAirSlowerUnderground()
    { return true; }

// the duration of all poisonous gases is DOUBLED when released underground.
inline int dnrVentGasDurationMult()
    { return 2; }

// the smoke caused by fires can create a major problem underground (see the
// Underground Environment section, printed p. 36).
inline bool dnrVentSmokeMajorProblem()
    { return true; }

// the smoke-effects cross-reference: the Underground Environment section on
// printed p. 36.
inline int dnrVentSmokeRefPage()
    { return 36; }

// a gaseous spell effect in a windy but relatively small area can be moved by
// the wind and still retain its potency.
inline bool dnrVentSpellGasWindCarried()
    { return true; }

// the wind-carry case requires a tunnel or passageway no more than 1/2 the
// diameter of the spell's area of effect (denominator 2).
inline int dnrVentSpellGasMaxDiameterFrac()
    { return 2; }

// wind blowing through the cave does not disperse the gas until twice the
// normal duration of the gas.
inline bool dnrVentWindCarryDurationDoubled()
    { return true; }

// the carried gas affects all susceptible creatures in its path.
inline bool dnrVentWindCarryAffectsPath()
    { return true; }

// ---- flying effects ----

// while the dimensions of many underground battlefields prohibit flying
// creatures, certain extraordinary caverns and realms are large enough to
// allow flight.
inline bool dnrFlyLargeCavernsAllowFlight()
    { return true; }

// a ceiling of 240 feet or higher uses the normal Battlesystem flight rules.
inline int dnrFlyNormalMinCeilingFt()
    { return 240; }

// even with a normal-rules ceiling, a flying creature might not be able to
// escape the battlefield by flying up and away.
inline bool dnrFlyMayNotEscapeUpward()
    { return true; }

// the thirds mapping opens at a ceiling of 60 feet.
inline int dnrFlyThirdsMinCeilingFt()
    { return 60; }

// between 60 and 240 feet use the normal low, medium and high designations,
// altered so low covers the bottom third, medium the middle third, and high
// the upper third of the available flying space.
inline bool dnrFlyThirdsMapping()
    { return true; }

// the two-altitude band opens above a 30-foot ceiling.
inline int dnrFlyTwoBandMinCeilingFt()
    { return 30; }

// a ceiling greater than 30 but less than 60 feet uses only medium and low
// altitudes, evenly divided between the two elevations.
inline bool dnrFlyTwoBandOnly()
    { return true; }

// ceilings lower than 30 feet allow only low-level flying creatures to take
// flight.
inline bool dnrFlyLowOnlyUnderThirty()
    { return true; }

// flying underground is very tricky and maneuverability is critical.
inline bool dnrFlyManeuverabilityCritical()
    { return true; }

// ---- line-of-sight effects ----

// a battle fought in the inky blackness of the underearth suffers vision
// effects even more extreme than those listed for Night Battles -
// Battlesystem game case 12.5.
inline bool dnrLosBlackerThanNightBattles()
    { return true; }

// unless fire, magical light, or a patch of phosphorescence somehow
// illuminates the field, creatures without infravision are at a great
// disadvantage.
inline bool dnrLosNeedFireMagicPhosphorescence()
    { return true; }

// creatures without infravision fighting in darkness suffer a +6 penalty to
// the unit's Attack Rating.
inline int dnrLosArPenalty()
    { return 6; }

// the +6 Attack Rating penalty reflects the combined effects of the -4 to
// attacks and -4 damage applied to blinded creatures (the R507 dnqDark
// numbers).
inline bool dnrLosArCompositesAttacksDamage()
    { return true; }

// the saving throws of individuals unable to see suffer a -4 penalty.
inline int dnrLosSavePenalty()
    { return 4; }

// the Armor Class of the creatures is raised by four against all melee
// attacks.
inline int dnrLosAcMeleePenalty()
    { return 4; }

// the movement rating of a unit that cannot see is reduced to 1/3 of its
// original (denominator 3).
inline int dnrLosMoveMultDen()
    { return 3; }

// if a unit unable to see encounters an unexpected obstacle such as a pit,
// pool of mud, or anything else that could trap the leading rank, the entire
// first rank of the unit is automatically affected.
inline bool dnrLosObstacleFirstRankAuto()
    { return true; }

// the first-rank rule accounts for the fact that even at the slowed rate, the
// front individuals cannot communicate the obstacle before the ranks behind
// push them into it.
inline bool dnrLosObstaclePushExplanation()
    { return true; }

// at least one light source must be employed for each figure in the unit to
// negate the darkness penalties.
inline bool dnrLosOneLightPerFigure()
    { return true; }

// the worked example: in a unit of 24 figures, at least 24 individuals must
// be equipped with torches or magical lights.
inline int dnrLosLightExampleFigures()
    { return 24; }

// a unit carrying its light source moves at its normal rate.
inline bool dnrLosLitMovesNormal()
    { return true; }

// the illuminated unit performs melee attacks normally.
inline bool dnrLosLitMeleesNormal()
    { return true; }

// the illuminated unit makes saving throws with the usual percentage chance
// of success.
inline bool dnrLosLitSavesNormal()
    { return true; }

// the illuminated unit cannot fire missiles at targets it cannot see.
inline bool dnrLosLitNoMissilesAtUnseen()
    { return true; }

// the illuminated unit cannot initiate a charge against a unit out of its
// range of vision.
inline bool dnrLosLitNoChargeBeyondVision()
    { return true; }

// a unit thus illuminated is easily seen by all forces on the field.
inline bool dnrLosLitEasilySeen()
    { return true; }

// if missiles are fired against the illuminated unit, the Attack Rating of
// the missile-using troops receives a +2 benefit in addition to any other
// modifiers that apply.
inline int dnrLosLitMissileArBonus()
    { return 2; }

// skirmishers can advance before a formation with torches, illuminating an
// enemy unit or target, or marking the terrain for a unit soon to come that
// way.
inline bool dnrSkirmishersIlluminateTargets()
    { return true; }

// because they are spread so, skirmishers with torches do not suffer the +2
// penalty against them when fired at with missile weapons.
inline bool dnrSkirmishersNoLitPenalty()
    { return true; }

// ---- cave-ins on a battlefield ----

// spells and effects that bring the massive weight of stone crashing down on
// foes are in high demand underground - the damage wrought by a collapse is
// devastating.
inline bool dnrCaveinSpellsHighDemand()
    { return true; }

// earthquake and transmute rock to mud are commonly used to bring down
// ceilings.
inline bool dnrCaveinEarthquakeCommon()
    { return true; }

// if a ceiling collapses, the area affected on the ground is the same as the
// area of the ceiling collapsed, plus 1 inch in all directions.
inline bool dnrCaveinAreaPlusInch()
    { return true; }

// the ground area expansion of a ceiling collapse: plus 1 inch in all
// directions.
inline int dnrCaveinPlusInches()
    { return 1; }

// a ceiling collapse deals 6d8 hit points of damage to all creatures in the
// area of effect: six dice (the djvu 648 garble, settled by the 60-dice orc
// example and the 4d8 mud read).
inline int dnrCaveinDamageDice()
    { return 6; }

// the ceiling-collapse damage die: d8.
inline int dnrCaveinDamageSides()
    { return 8; }

// a saving throw vs. spell reduces the collapse damage to half.
inline bool dnrCaveinSaveHalves()
    { return true; }

// the worked example: the 10-orc figure suffers 60 dice of damage and is
// automatically destroyed whether it saves or not.
inline bool dnrCaveinOrcFigureDestroyed()
    { return true; }

// the worked-example collapse damage on the 10-orc figure: 60 dice.
inline int dnrCaveinOrcFigureDice()
    { return 60; }

// a similar weight of falling mud deals only 4d8 points of damage.
inline int dnrCaveinMudDamageDice()
    { return 4; }

// the falling-mud damage die: d8.
inline int dnrCaveinMudDamageSides()
    { return 8; }

// the mud-fall damage is again halved if the saving throw is successful.
inline bool dnrCaveinMudSaveHalves()
    { return true; }

// unstable bridges, ledges, or other rock formations subject to unusual
// stress when heavy creatures move across or next to them are left to the
// DM's discretion.
inline bool dnrCaveinUnstableDmDiscretion()
    { return true; }

// along with bridges and ledges, the collapse of narrow columns or arches -
// even worn and cracked sections of cavern ceilings - can be catastrophic.
inline bool dnrCaveinColumnsArchesCracked()
    { return true; }

// the base chance of a frail feature collapsing is 1% whenever marching or
// melee combat occurs nearby.
inline int dnrCaveinBasePct()
    { return 1; }

// spells such as lightning bolt or earthquake can also trigger the collapse.
inline bool dnrCaveinSpellsTrigger()
    { return true; }

// the DM or neutral referee should make a secret d100 check whenever stress
// is applied to a fragile formation.
inline bool dnrCaveinSecretCheck()
    { return true; }

// if a formation is checked once and does not collapse, but the resulting
// d100 roll was less than 25, the collapse chance rises.
inline int dnrCaveinCumulativeRollBelow()
    { return 25; }

// the cumulative collapse-chance increase per sub-25 survived check: +4% (the
// djvu 496 garble, Acrobat "raised 4%").
inline int dnrCaveinCumulativePlusPct()
    { return 4; }

// the cumulative increase means the feature could grow increasingly fragile
// as the battle continues.
inline bool dnrCaveinCumulativeEffect()
    { return true; }

// the presence of heavy units - heavy cavalry, chariots, or large creatures -
// doubles the chance of a collapse.
inline bool dnrCaveinHeavyUnitsDouble()
    { return true; }

// the worked example: a bridge with a 13% chance of collapse (the djvu 1396
// garble, Acrobat 13%).
inline int dnrCaveinHeavyExamplePct()
    { return 13; }

// the worked example doubled: the 13% bridge has a 26% chance if a heavy
// cavalry unit gallops over it.
inline int dnrCaveinHeavyExampleDoubledPct()
    { return 26; }

// the formation's chance of collapsing doubles if an explosive spell such as
// a lightning bolt strikes it directly.
inline bool dnrCaveinDirectSpellHitDoubles()
    { return true; }

// the chance also doubles if an earthquake or similar effect causes the rock
// immediately adjacent to the threatened area to collapse.
inline bool dnrCaveinAdjacentCollapseDoubles()
    { return true; }

}   // namespace rules
