// =========================================================================================
// Adnd1 - rules/wsgmagic.h
// R491: the WSG MAGIC IN THE WILDERNESS chapter slice, printed pp. 95-101 -
// the round CLOSING the chapter: the alphabetical spell commentary from
// affect normal fires through wraithform, the climbing and falling interplay
// with the web thickness chain and slope multipliers, the temperature magics,
// the cold-weather reductions, and the potion, scroll, ring, rod and
// miscellaneous item rules - the DM section rides to R492.
// census 415 -> 416.
//
// THE SETTLE: the magic pages two-way clean - the pdftotext layout reads and
// the tesseract tsv reconstructions agree on every number (the bind 100 feet
// of half-inch rope; the armor 10 degrees; the bug +10 percent; the bluelight
// twice safe speed; the commune one fact per level; the cone of cold six
// points, one per turn, one hour; the control weather 30 to 40 and the
// druidic two steps; the earthquake 1 mile, 50 percent, 1d6 turns; the feign
// death half; the firewater one pint; the flame strike 10-foot diameter; the
// forcecage 5 percent per level and the 20-foot fall; the fumble minus 20
// percent and plus 4; the haste minus 10 percent and plus 2; the chill metal
// 7 rounds as one hour; the insect plague 40 degrees, one-tenth duration,
// three-quarters area, the 9-inch diameter 1.5-inch high cleric cloud and
// 8-inch 1-inch druid cloud, where tesseract low-confidence 3 and 12 (conf 51
// and 8) lose to the text layer against the three-quarters math; the jump 50
// percent on smooth; the knot 1d4 minimum 1; the rainbow once per round, half
// weight, 6 inches, 6th level; the sink 4 segments and 4 turns; the snare 100
// and 50 percent; the summon insects half; the water walk two man-sized; the
// web 5 feet per 10 feet, 10-20-40-60, 2x 4x 8x, with the printed examples
// being the 10-foot and 20-foot thick webs - both reads dropped the 0 into
// 1-inch and 2-inch, and the doubled 40 and quadrupled 160 settle it; the
// gaseous form 3-30; the invulnerability 40 and 80; the vitality seven days;
// the scroll cold 40 degrees and the gas 1 inch; the sustenance minus 5, six
// turns and the unmodified 20; the lordly might 20 feet; the swarming insects
// 30 plus 5 versus 60 plus 10; the Fharlanghn 100 and 80 percent; the stone
// of good luck plus 5 percent and minus 1) - md5
// 2f437a1aa0262a999f410c533be81815 on p096_103_full.txt - printed p. 102 is
// ornament-only and the chapter ends at printed 101.
//
// The chain lesson: the web thickness band and every const feed the audit
// mirror, and the mutant battery perturbs each one against it.
//
namespace rules {

// ---- The chapter opener ----

// many sections of this book describe facets of the outdoor environment
// without considering that characters in the wilderness may have access to
// spells or magic items; the magic commentary gathered here is a starting
// point, not exhaustive, and some of it may seem obvious
inline bool wmgMagicIntro()
    { return true; }

// magic that specifically affects animals or plants is obvious and excluded
// unless noteworthy; fire magic enters only when the observation is
// noteworthy; nourishment-creating magic is excluded; items with no general
// outdoor application are excluded; practically any magic may have a specific
// application in a particular circumstance
inline bool wmgGeneralPoints()
    { return true; }

// the spell section (including cantrips) is alphabetical without regard to
// class; the magic item section is alphabetical, and items that duplicate
// listed spell effects are not repeated
inline bool wmgArrangement()
    { return true; }

// ---- Spells A through B ----

// an easy way to blaze a campfire or cookfire quickly without fire-building
// proficiency: the magic expires soon but by then the larger fuel is ignited
// and the fire burns on its own
inline bool wmgAffectFiresCampfire()
    { return true; }

// useful for ascending or descending a steep incline or moving directly up or
// down near a cliff face; the air walker must reach a safe perch before the
// spell duration expires
inline bool wmgAirWalkAerialUse()
    { return true; }

// in the area of effect the movement rate equals the swimming rate, and other
// characters in the sphere or hemisphere cannot move faster than the
// spell-caster if they intend to remain within the affected area
inline bool wmgAiryWaterMoveRate()
    { return true; }

// the alarm guards an area that is not in the sentry line of sight, giving an
// added assist for a short time
inline bool wmgAlarmOutOfSight()
    { return true; }

// unless the caster is of very high level it is not prudent to cast it on the
// campsite itself since it cannot cover enough area; a better tactic is a
// spot a short distance away, perhaps on a path toward or parallel to the
// campsite
inline bool wmgAlarmNotCampsite()
    { return true; }

// if the caster party contains a character with animal lore proficiency the
// Dungeon Master may let the caster know in advance at least one animal type
// available within range; the caster will certainly receive animals of that
// sort if that is what he desires
inline bool wmgAnimalSummonLore()
    { return true; }

// animating the rock at the bottom of a pile near a plateau edge and sending
// it over makes the others follow - no more orc archers
inline bool wmgAnimateObjectRocks()
    { return true; }

// animate rock: see animate object above for the same idea
inline bool wmgAnimateRockIdea()
    { return true; }

// the armor spell alters the personal temperature of the recipient by 10
// degrees toward the tolerable range - warmer if the environment is cold, or
// vice versa
inline int wmgArmorTempDeg()
    { return 10; }

// handy for determining if gathered greenery is edible in the absence of
// plant lore proficiency or as a safeguard against an incorrect estimation;
// the augury itself does not always produce accurate results
inline bool wmgAuguryEdible()
    { return true; }

// the recipient suffers half damage from abrasion when tumbling down a slope;
// a druid acting quickly might cast it on a character as he tumbles past,
// minimizing abrasion for the remainder of the distance but not offsetting
// damage already suffered before the spell takes effect
inline bool wmgBarkskinHalfAbrasion()
    { return true; }

// a character victimized by the bee cantrip in a precarious position on a
// moderate or severe slope or a cliff face must make a Climbing Check to
// avoid falling; a creature stung in a similar situation must also check to
// keep from falling
inline bool wmgBeeClimbingCheck()
    { return true; }

// the bind spell affects at least 100 feet of half-inch-diameter climbing
// rope, or an even greater length of smaller rope such as might be used to
// pitch a tent
inline int wmgBindRopeMinFt()
    { return 100; }

// frivolous for setting up camp but handy for taking down a tent quickly if
// the party lacks rope use proficiency; it also has obvious utility in
// climbing situations
inline bool wmgBindTentTeardown()
    { return true; }

// if a protrusion is only a few inches out of reach the character extends the
// rope end as far as possible and has his magic-using companion bind the rope
// to the protrusion
inline bool wmgBindReachProtrusion()
    { return true; }

// bluelight sheds enough light to enable a character to move at twice his
// maximum safe speed in darkness or moonlight without Dexterity Checks,
// provided he pays attention to the terrain in front of him
inline int wmgBluelightSpeedMult()
    { return 2; }

// the bug cantrip bite is usually not as severe as a bee sting, so the victim
// gets a +10% bonus to his Climbing Rating for the Climbing Check
inline int wmgBugClimbBonusPct()
    { return 10; }

// ---- Spells C ----

// a bolt of magical lightning will always hit a target within range of the
// area where it strikes, whereas the chance of being hit by natural lightning
// is usually quite small
inline bool wmgCallLtnAlwaysHit()
    { return true; }

// the magical lightning is generally less lethal than natural lightning but
// will always do at least half damage
inline bool wmgCallLtnHalfDmgMin()
    { return true; }

// to an outside observer magical lightning is indistinguishable in appearance
// from natural lightning, so a witness or victim will not automatically know
// an external force was involved
inline bool wmgCallLtnIndistinguishable()
    { return true; }

// if more than one strike hits a target or targets within a relatively short
// time, witnesses may logically suspect that nature is not entirely to blame
inline bool wmgCallLtnMultipleSuspect()
    { return true; }

// natural lightning can also occur during the spell duration as long as
// conditions permit - the storm must be actually occurring, not simply about
// to happen under hot and cloudy conditions
inline bool wmgCallLtnNaturalCoexists()
    { return true; }

// the presence of a character with animal lore proficiency will NOT enhance
// the chances of call woodland beings, since that proficiency imparts no
// special knowledge about the sorts of fantastic creatures that can be called
inline bool wmgCallWoodNoLore()
    { return true; }

// commune with nature lasts until the caster has requested and found out one
// fact for each level of experience
inline int wmgCommuneFactsPerLevel()
    { return 1; }

// the caster need not maintain total concentration: he can move normally,
// eat, converse with companions and so forth
inline bool wmgCommuneNoConcentration()
    { return true; }

// the spell expires prematurely if the caster performs any strenuous physical
// or mental activity, is struck by a physical or magical attack, or loses
// consciousness
inline bool wmgCommuneExpiresOn()
    { return true; }

// at the Dungeon Master discretion cone of cold could be used in a
// non-damaging manifestation to let a character recover from heatstroke: kept
// cooled for an hour without suffering damage from the spell and thereby
// saved from further harm
inline bool wmgConeHeatstrokeUse()
    { return true; }

// the cone of cold heatstroke treatment will not restore lost hit points but
// will restore lost constitution points up to a maximum of six
inline int wmgConeConMax()
    { return 6; }

// one constitution point per turn is restored by the cone of cold cooling
// treatment
inline int wmgConeConPerTurn()
    { return 1; }

// the cone of cold cooling power remains in effect for one hour of treatment
inline int wmgConeHour()
    { return 1; }

// control temperature is useful for protecting and aiding the recovery of
// someone suffering hypothermia, frostbite, heatstroke or another
// temperature-related malady
inline bool wmgCtrlTempRecoveryUse()
    { return true; }

// extreme heat is not necessarily good for a cold victim - a frostbite victim
// might be harmed as much as helped by a sudden 100-degree rise, so gradual
// warming is more conducive to full recovery; a heatstroke victim benefits
// most from prompt exposure to freezing or near-freezing conditions to bring
// body temperature down rapidly
inline bool wmgCtrlTempGradual()
    { return true; }

// at the Dungeon Master discretion the caster may manipulate the temperature
// during the duration or may be forced to pick a target temperature and stick
// with it as long as the spell persists
inline bool wmgCtrlTempDM()
    { return true; }

// control weather will not radically change the temperature through 100
// degrees or more; a maximum range of 30 degrees in one direction or the
// other is recommended
inline int wmgCtrlWeatherLoDeg()
    { return 30; }

// the upper bound of the recommended control weather temperature change: a
// maximum range of 30 or 40 degrees in one direction or the other
inline int wmgCtrlWeatherHiDeg()
    { return 40; }

// sweltering heat cannot be made hotter and arctic cold cannot be made
// colder; at an extreme the temperature can only be moved in one direction,
// true even of the druidic version
inline bool wmgCtrlWeatherExtreme()
    { return true; }

// the druidic version of control weather can move weather conditions two
// steps instead of just one
inline int wmgDruidicSteps()
    { return 2; }

// when control weather expires the prior weather resumes as if the
// intervening time had not occurred; it will not prevent characters on the
// seacoast from being in the path of an oncoming hurricane, though moving
// inland during the spell may let them avoid the brunt of the storm
inline bool wmgCtrlWeatherResumes()
    { return true; }

// control winds cast to counter a control weather or control temperature
// spell completely negates the previous spell, reinstates the natural
// conditions that were in effect beforehand, and then creates a wind of the
// desired velocity
inline bool wmgCtrlWindsNegates()
    { return true; }

// the created wind can affect other naturally existing conditions if strong
// enough: it will dissipate moderate or heavy fog and neutralize a sandstorm
// within the area of effect
inline bool wmgCtrlWindsAffects()
    { return true; }

// unlike control weather, the natural weather will not necessarily resume
// when control winds expires: if a sandstorm would have abated by then, it
// will not resume
inline bool wmgCtrlWindsNoResume()
    { return true; }

// control winds cannot change large-scale weather conditions such as moving
// storm clouds rapidly, because the area of effect is not nearly large enough
// to affect the upper atmosphere where those clouds are located
inline bool wmgCtrlWindsNoLargeScale()
    { return true; }

// the interruption caused by the cough cantrip is not severe or long-lasting
// enough to cause a character to lose his concentration on a spell he is
// trying to maintain
inline bool wmgCoughNoBreak()
    { return true; }

// create food and water is better than create water in dire straits because
// it provides both solid and liquid nourishment if the caster specifies and
// requires no material component
inline bool wmgCreateFoodWater()
    { return true; }

// create water is a life-saver when the party runs out of water in the desert
// or any other waterless environment
inline bool wmgCreateWaterLifesaver()
    { return true; }

// you cannot take it with you unless you have something to carry the created
// water in
inline bool wmgCreateWaterContainer()
    { return true; }

// you cannot make water unless you have at least a drop of water to begin
// with; whether saliva or perspiration qualifies as the material component is
// a matter for the Dungeon Master
inline bool wmgCreateWaterDrop()
    { return true; }

// cure blindness negates the eye injuries and blindness caused by a sandstorm
// without requiring the victim to keep his eyes covered during a recovery
// period
inline bool wmgCureBlindSandstorm()
    { return true; }

// physical traumas such as dehydration, hypothermia and heatstroke are not
// considered diseases for determining what cure disease can affect
inline bool wmgCureDiseaseNotTrauma()
    { return true; }

// ---- Spells D through F ----

// the maximum safe movement rate in the magical darkness of darkness 15
// radius is one-half of the figure given for natural darkness
inline int wmgDarknessRateDen()
    { return 2; }

// the magical darkness is much blacker than the darkness that normally
// prevails in the wilderness at night, even under a moonless or overcast sky
inline bool wmgDarknessBlacker()
    { return true; }

// the detect snares and pits area of effect moves as the caster moves as long
// as he concentrates, does not have his concentration abruptly interrupted by
// combat or the preparation of a different spell, and does not attempt to
// move faster than his full normal movement rate
inline bool wmgDetectSnaresMoves()
    { return true; }

// the caster can converse normally with other party members and perform any
// non-strenuous physical activity without interrupting the detect spell
inline bool wmgDetectSnaresActivity()
    { return true; }

// dig is a quick way to search for water beneath the desert surface; it does
// not increase the chance of finding water at a certain location but the
// party will not spend a lot of time and effort in a fruitless endeavor
inline bool wmgDigDesertWater()
    { return true; }

// despite its name dispel exhaustion does only what the Players Handbook
// says: it cannot alleviate or offset the effects of fatigue or exhaustion as
// described in this text
inline bool wmgDispelExhaustionNoHelp()
    { return true; }

// distract: see cough above - the interruption is not severe enough to break
// spell concentration
inline bool wmgDistractSeeCough()
    { return true; }

// the dry cantrip makes wet kindling flammable so a small campfire can be
// started more quickly thereafter
inline bool wmgDryKindling()
    { return true; }

// larger pieces of wood not wet all the way through can keep the fire going
// if broken up so the dry interior is exposed, or a second application of the
// cantrip can dry the surface of a pile of larger pieces so the fuel ignites
// without needing to be broken up
inline bool wmgDrySecondApp()
    { return true; }

// the earthquake spell effect is magical, not natural, and thus does not
// cause the same results as a natural earthquake
inline bool wmgQuakeMagical()
    { return true; }

// if the earthquake spell is cast within one mile of a natural fault line
// there is a chance of triggering a natural earthquake at that location
inline int wmgQuakeFaultMiles()
    { return 1; }

// casting the earthquake spell within one mile of a natural fault line gives
// a 50 percent chance that a natural earthquake will occur there
inline int wmgQuakeChancePct()
    { return 50; }

// the natural earthquake triggered by the spell occurs 1d6 turns after the
// magical earthquake has subsided
inline int wmgQuakeDelayDie()
    { return 6; }

// creatures with higher than animal intelligence affected by fear will not
// run into the side of a cliff, over a cliff or into a fire while fleeing;
// they will alter their path and proceed along the edge or perimeter of the
// obstacle, still trying to put as much distance as possible between
// themselves and the caster
inline bool wmgFearSmartFleeing()
    { return true; }

// under feign death the effects of exposure such as frostbite and heatstroke
// accumulate only half as quickly as under normal circumstances
inline int wmgFeignExposureDen()
    { return 2; }

// a character who knows help is on the way may help save his life or the life
// of another by using feign death to partially protect the victim from
// exposure
inline bool wmgFeignProtect()
    { return true; }

// casting find familiar in a desolate area such as a scorching desert or
// arctic wastes may, at the Dungeon Master discretion, automatically fail to
// attract any of the listed creatures
inline bool wmgFamiliarDesolate()
    { return true; }

// the possibilities for normal familiars should be restricted to creatures
// that could conceivably exist within the spell range - a black cat will not
// be found in a desert or at a mountain summit and a toad will not be found
// in the middle of a grassy plain; contradictory die-roll results may be
// re-rolled or treated as no familiar available
inline bool wmgFamiliarPlausible()
    { return true; }

// find traps, like detect snares and pits, can remain in effect while the
// caster turns or moves at a normal speed
inline bool wmgFindTrapsMove()
    { return true; }

// find traps is only useful to discover traps of a magical or mechanical
// nature: it will not reveal a covered pit, nor a trip wire unless the wire
// is connected to a snare or a missile-firing device or some other accessory
// that constitutes a mechanical trap
inline bool wmgFindTrapsOnlyMagMech()
    { return true; }

// as little as one pint of firewater, sprinkled evenly over the fuel and
// ignited before it evaporates, will make branches and logs catch fire
// wherever the substance is present
inline int wmgFirewaterPints()
    { return 1; }

// the flame produced by firewater spreads to the rest of the fuel and
// produces a blaze usable for cooking or warmth or both, with no kindling or
// other preparation needed
inline bool wmgFirewaterSpread()
    { return true; }

// flame strike momentarily ignites everything in a 10-foot-diameter area,
// charring easily flammable materials there when the duration expires
inline int wmgFlameStrikeDiamFt()
    { return 10; }

// using flame strike to start a campfire is as sensible as lighting a pipe
// with a blowtorch: if the area also contains combustible materials the spell
// could start an uncontrollable fire - see the Camping and Campfires section
inline bool wmgFlameStrikeFireRisk()
    { return true; }

// there is a chance equal to 5% per level of the caster that forcecage could
// be used to halt a falling character or creature in mid-air, assuming the
// target is within range when the spell is discharged
inline int wmgForcecagePctPerLevel()
    { return 5; }

// the spell description does not require the cage to be anchored to a solid
// surface, so it can stop a fall in mid-air; failure on the chance means the
// cage forms around thin air and the target was missed
inline bool wmgForcecageNeedNotAnchor()
    { return true; }

// a target successfully halted by a mid-air forcecage is prevented from
// falling any farther and takes damage only as for a 20-foot fall - the
// length of one side of the cage
inline int wmgForcecageFallDmgFt()
    { return 20; }

// there must be a way to rescue the halted character before the forcecage
// duration expires or his fall resumes from that point: for instance a rope
// can be passed through the bars, tied around his waist, and he can be hauled
// to safety when the magic ends or is dispelled
inline bool wmgForcecageRescue()
    { return true; }

// a fumbled character or creature in a precarious position that fails its
// saving throw stumbles and falls unless it makes a successful Climbing Check
// at a -20% modifier to its Climbing Rating
inline int wmgFumbleClimbPct()
    { return 20; }

// the fumble fall-avoidance Dexterity Check is made with a +4 modifier to the
// die roll, whichever check applies
inline int wmgFumbleDexMod()
    { return 4; }

// the fumble effect can be averted if the target remains motionless until the
// spell duration expires
inline bool wmgFumbleMotionless()
    { return true; }

// in most cases a target that fails its fumble saving throw will not know it
// has been affected, so the decision to remain motionless must be made
// independent of any knowledge of the peril movement would cause
inline bool wmgFumbleUnaware()
    { return true; }

// a motionless fumble target who attempts to find a new handhold or foothold,
// grab for a rope, or perform any other deliberate motion must make the
// modified Climbing Check or Dexterity Check or slip and fall
inline bool wmgFumbleDeliberate()
    { return true; }

// ---- Spells G through L ----

// the gather cantrip cannot cull inedible or poisonous plants from freshly
// picked greenery unless the caster has prior knowledge, by plant lore
// proficiency for instance, of which plants are good to eat
inline bool wmgGatherNeedsLore()
    { return true; }

// giggle: see cough above - the interruption is not severe enough to break
// spell concentration
inline bool wmgGiggleSeeCough()
    { return true; }

// a hasted character on a slope or cliff face can move twice as fast as
// normal, but all Climbing Checks for hasted characters and creatures are
// made at a -10% penalty to their Climbing Ratings
inline int wmgHasteClimbPct()
    { return 10; }

// if a hasted character exceeds his maximum safe speed in conditions of
// reduced visibility he must make all Dexterity Checks called for at a +2
// modifier to the die roll
inline int wmgHasteDexMod()
    { return 2; }

// the Dungeon Master should interpret heal liberally against injuries or
// disabilities caused directly or indirectly by the environment: it will
// restore all constitution points lost from heatstroke, not just those
// regained by normal recovery
inline bool wmgHealConRestore()
    { return true; }

// the seven rounds of heat metal spell duration, when the reverse chill metal
// is used on the armor of a heatstroke victim, will benefit him the same as
// normal treatment
inline int wmgChillRounds()
    { return 7; }

// the chill metal heatstroke treatment benefits the victim the same as if he
// had received normal treatment for a full hour; he suffers no damage or
// disability from the spell
inline int wmgChillAsHour()
    { return 1; }

// hold person and similar magics will not suspend a character or creature in
// mid-air to save it from falling: it only freezes victims so as to prevent
// them from moving under their own power
inline bool wmgHoldNotMidair()
    { return true; }

// someone about to lose his grip on a mountainside can be held in place as
// long as he is still gripping handholds and footholds when the spell takes
// effect; if he has already lost his grip the spell will not necessarily hold
// him unless his feet are securely placed on a ledge
inline bool wmgHoldGrip()
    { return true; }

// for a willing or needy recipient of hold person the saving throw should be
// disregarded or considered to be automatically failed
inline bool wmgHoldWilling()
    { return true; }

// if insect plague is cast when the actual temperature is 40 degrees or lower
// the duration and area of effect are both reduced
inline int wmgPlagueColdDeg()
    { return 40; }

// under the 40-degree threshold the insect plague duration is reduced to
// one-tenth of normal: 1 round per level
inline int wmgPlagueDurationPct()
    { return 10; }

// the cold-weather insect plague lasts 1 round per level of the caster
inline int wmgPlagueRoundsPerLevel()
    { return 1; }

// under the 40-degree threshold the insect plague area of effect is cut to
// three-quarters of normal
inline int wmgPlagueAreaPct()
    { return 75; }

// the cold-weather cleric insect plague cloud is 9 inches in diameter
// (tesseract read a low-confidence 3 here, conf 51; the text layer wins)
inline int wmgPlagueClericDiamIn()
    { return 9; }

// the cold-weather cleric insect plague cloud is 1.5 inches high - 3
// half-inches (tesseract read a low-confidence 12-inch height, conf 8; the
// text layer wins)
inline int wmgPlagueClericHighHalfIn()
    { return 3; }

// the cold-weather druid insect plague cloud is 8 inches in diameter
inline int wmgPlagueDruidDiamIn()
    { return 8; }

// the cold-weather druid insect plague cloud is 1 inch high - 2 half-inches
inline int wmgPlagueDruidHighHalfIn()
    { return 2; }

// the itching application of irritation will cause a target in a precarious
// position to lose his grip and tumble or fall unless he is otherwise
// prevented from doing so
inline bool wmgIrritationGrip()
    { return true; }

// item is a handy way to make a campfire portable, but whoever carries the
// fire between stops had better be sure the spell-caster will not
// inadvertently speak the command word while it is in his backpack
inline bool wmgItemPortableFire()
    { return true; }

// jump is a possible but risky means of ascending - not descending - a slope
// or cliff face, since the spell does not insure any safety in landing or
// grasping at the end of the leap
inline bool wmgJumpAscentOnly()
    { return true; }

// if a place exists for the jumper to land upon or grab onto he must make a
// successful Dexterity Check at the end of the jump to land safely; if no
// such place exists or he fails the check, he will fall
inline bool wmgJumpDexCheck()
    { return true; }

// for the chance of a protrusion the Dungeon Master can use the Grappling
// Success Table, or rule that a safe landing or grabbing spot always exists
// except on a smooth slope or smooth cliff face - fingers and toes can find
// purchase where a grappling hook would not usually catch
inline bool wmgJumpGrappling()
    { return true; }

// on a smooth slope or smooth cliff face the chance of a safe landing or
// grasping spot for a jump spell is 50 percent
inline int wmgJumpSmoothPct()
    { return 50; }

// a character with rope use proficiency can loosen the bind knot in 1d4
// rounds
inline int wmgKnotDie()
    { return 4; }

// the knot-loosening time is reduced by the dexterity reaction bonus but is a
// minimum of 1 round in any case
inline int wmgKnotMin()
    { return 1; }

// the knot round count is reduced by the character dexterity bonus for
// reaction, with the 1-round minimum
inline bool wmgKnotDexBonus()
    { return true; }

// locate animals: see animal summoning above for the proficiency interaction
inline bool wmgLocateAnimalsRef()
    { return true; }

// locate plants: see animal summoning above, except that the text applies to
// plants in this case
inline bool wmgLocatePlantsRef()
    { return true; }

// the reverse of lower water will bring subsurface desert water toward the
// surface but not necessarily all the way to ground level, so characters
// might still have to excavate to find it
inline bool wmgLowerWaterToward()
    { return true; }

// the unreversed lower water can enable characters to ford a deep river or
// cross a narrow lake on foot, assuming the water is lowered enough and the
// travelers can cover the distance before the spell duration expires
inline bool wmgLowerWaterFord()
    { return true; }

// not all the river or lake water will be within the area of effect, but
// water that spills into the area as a result of the lowering is immediately
// lowered itself
inline bool wmgLowerWaterSpill()
    { return true; }

// ---- Spells M through S ----

// massmorph makes the party safe from any number of natural hazards -
// sandstorm, hailstorm, extreme temperature and the like - by turning them
// into trees until the hazard has ceased to exist
inline bool wmgMassmorphHazards()
    { return true; }

// only a blow from a weapon (not a bare fist) or the impact of a harmful
// magic effect such as magic missile or death spell will damage massmorphed
// characters; they are still subject to effects that can harm trees - fire,
// lightning, extremely strong wind, acid and so forth
inline bool wmgMassmorphWeaponOnly()
    { return true; }

// the illusionary trees cannot eat and cannot soak up water from the ground,
// so characters kept in this form for an extended period may be in dire need
// of food and water when the magic is dispelled and may even die from lack of
// nourishment; the rest of the party is in big trouble if the spell-caster is
// chopped down before dispelling
inline bool wmgMassmorphNoNourish()
    { return true; }

// mending will repair a rope that has broken or frayed but cannot be used to
// join two different ropes into one single longer rope
inline bool wmgMendOneRope()
    { return true; }

// misdirection cast on a character with a knowledge-based proficiency such as
// animal lore or direction sense, on a failed saving throw, reverses the
// interpretation or assumption made - a correct assessment becomes incorrect
// or vice versa, and the spell-caster will not usually know ahead of time
// which it was
inline bool wmgMisdirectReversal()
    { return true; }

// protection from normal missiles prevents harm from hailstones, sandstorms
// and any other missile-like natural phenomenon
inline bool wmgPfnmMissiles()
    { return true; }

// the protection from normal missiles recipient cannot be blinded by a
// sandstorm and no sand will actually touch him, but he is still limited in
// visibility as much as an unprotected character
inline bool wmgPfnmLimitedVis()
    { return true; }

// the spell does not negate very strong wind such as a tornado: the character
// can still be picked up and carried along by the funnel cloud, but he will
// not take damage from collision with debris that is also being carried along
inline bool wmgPfnmWindNotNegated()
    { return true; }

// the protection field prevents abrasion damage during a tumble but does not
// keep the character safe from impact damage at the end of a fall or tumble
inline bool wmgPfnmAbrasionNotImpact()
    { return true; }

// the protection from normal missiles field will not keep out natural
// lightning
inline bool wmgPfnmNoLightning()
    { return true; }

// the field will keep a character safe from being burned by lava during a
// volcanic eruption but will not protect him from radiant heat that can also
// cause damage at such a time
inline bool wmgPfnmLava()
    { return true; }

// if an illusionist casts a rainbow cantrip and a cleric who sees it fails
// his saving throw, the cleric can successfully cast a rainbow spell if the
// casting begins before the cantrip magic expires and the material components
// are readily available - it is not easy but it is possible; the resulting
// spell is reduced in efficacy
inline bool wmgRainbowClericChain()
    { return true; }

// the rainbow spell wrought through the cantrip chain fires the bow only once
// per round
inline int wmgRainbowBowPerRound()
    { return 1; }

// a normal rainbow spell fires the bow twice per round
inline int wmgRainbowBowNormal()
    { return 2; }

// the chain-wrought rainbow bridge weight limit is half normal - 50 percent
inline int wmgRainbowBridgePct()
    { return 50; }

// the chain-wrought rainbow elevator moves at 6 inches per round
inline int wmgRainbowElevatorIn()
    { return 6; }

// the normal rainbow elevator moves at 12 inches per round
inline int wmgRainbowElevatorNormal()
    { return 12; }

// the chain-wrought rainbow flagon draughts act as if cast by a cleric of 6th
// level
inline int wmgRainbowLevel()
    { return 6; }

// a normal rainbow flagon acts as if cast by a cleric of 12th level
inline int wmgRainbowLevelNormal()
    { return 12; }

// a resist cold recipient suffering hypothermia, frostbite or another
// cold-related malady is protected from further harm for the spell duration,
// but the magic will not negate adverse effects already suffered
inline bool wmgResistColdFurther()
    { return true; }

// resist fire is handled the same way as resist cold, except that it pertains
// to heat-related instead of cold-related effects
inline bool wmgResistFireSame()
    { return true; }

// if individuals affected by a run spell do not rest and refresh themselves
// immediately after the spell duration expires, they become exhausted after
// as little as 1 turn of activity other than eating, drinking and resting
inline int wmgRunExhaustTurns()
    { return 1; }

// the run spell stricture requires rest and refreshment immediately after the
// spell effect expires
inline bool wmgRunMustRest()
    { return true; }

// the run stricture does not prohibit mental activity such as studying a
// spell book or praying for spells
inline bool wmgRunMentalOk()
    { return true; }

// the lone exception is a character with endurance proficiency, who can
// continue nonstrenuous physical activity immediately after the run spell
// expires; for a period equal to the spell duration he cannot make use of his
// proficiency and is subject to fatigue and exhaustion as a normal character
// would be
inline bool wmgRunEnduranceException()
    { return true; }

// the run spell will not affect a character with long-distance running
// proficiency, just as it does not affect a barbarian with the special
// running ability of that class
inline bool wmgRunRunnersExempt()
    { return true; }

// a shielded magic-user takes two-thirds of the abrasion and impact damage he
// would otherwise suffer from a tumble or fall - the numerator 2
inline int wmgShieldAbrasionNum()
    { return 2; }

// the shield tumble-and-fall damage divisor: two-thirds, denominator 3
inline int wmgShieldAbrasionDen()
    { return 3; }

// if the sink caster stops chanting after 4 segments the subject becomes
// fastened to the surface he is touching
inline int wmgSinkSegments()
    { return 4; }

// after a sink spell fastens a falling character, the rest of the group has 4
// turns to devise a way to keep him from falling when he returns to normal
// form
inline int wmgSinkTurns()
    { return 4; }

// as with hold person, the sink saving throw can be waived or considered
// automatically failed if the spell is intentionally cast upon a willing or
// needy recipient
inline bool wmgSinkWilling()
    { return true; }

// a snare prepared without magical assistance, when enhanced by the snare
// spell, is 100 percent undetectable without magical means
inline int wmgSnareNonmagicPct()
    { return 100; }

// the snare-spell snare can be noticed only on a 50 percent chance even if
// some form of magical detection is employed on the area in which it is
// located
inline int wmgSnareMagicPct()
    { return 50; }

// stone tell will function if cast upon something such as a mountainside or a
// cliff face - after all, essentially a conglomeration of stones - as well as
// upon individual rocks or boulders
inline bool wmgStoneTellMountains()
    { return true; }

// a character who takes a tumble while stoneskinned suffers no abrasion
// damage from the episode
inline bool wmgStoneskinNoAbrasion()
    { return true; }

// the act of tumbling will dispel the stoneskin, whether or not the recipient
// would otherwise have suffered damage
inline bool wmgStoneskinTumbleDispels()
    { return true; }

// stoneskin keeps a character safe from injury in a hailstorm, the entire
// storm being considered as one attack sequence, but it will be dispelled
// when the hailstorm stops
inline bool wmgStoneskinHail()
    { return true; }

// if summon insects is cast when the actual temperature is 40 degrees or
// lower the spell duration is reduced
inline int wmgInsectsColdDeg()
    { return 40; }

// under the 40-degree threshold the summon insects duration is one-half of
// normal, rounded down - the denominator 2
inline int wmgInsectsDurDen()
    { return 2; }

// under the 40-degree threshold the summon insects duration is only one-half
// of normal, rounded down
inline bool wmgInsectsHalfDur()
    { return true; }

// the symbol-of-hopelessness viewer who fails his saving throw must make a
// successful Wisdom Check every turn as long as the magic remains in effect
inline int wmgSymbolEveryTurn()
    { return 1; }

// a symbol of hopelessness viewed from a precarious position on a severe
// slope or cliff face holds the gaze of a character who fails his saving
// throw; if any Wisdom Check fails he falls unless he makes a successful
// Climbing Check or Dexterity Check immediately after
inline bool wmgSymbolHopeless()
    { return true; }

// if a symbol of pain is viewed in the same circumstances, the Dungeon Master
// should substitute a Constitution Check for the Wisdom Check and handle the
// incident otherwise the same way
inline bool wmgSymbolPainCon()
    { return true; }

// ---- Spells T through W ----

// transmute rock to mud used in combination with the reverse of lower water
// can produce drinkable liquid from solid rock
inline bool wmgTransmuteDrinkable()
    { return true; }

// trip will have no effect upon characters who are not walking or running in
// a normal fashion, such as those crawling along level terrain or using both
// hands and feet to negotiate a slope or cliff face
inline bool wmgTripNormalGait()
    { return true; }

// for determining how many individuals water walk can affect, a heavily or
// severely encumbered character counts as two man-sized creatures instead of
// just one
inline int wmgWaterWalkEncumberedCount()
    { return 2; }

// a creature empowered to walk on water does so at his normal land-based
// movement rate, taking into account encumbrance, the condition of the water
// and any other pertinent factors
inline bool wmgWaterWalkLandRate()
    { return true; }

// calm water is equivalent to normal terrain, actively flowing water might be
// considered rugged terrain, and white-water rapids would be very rugged
// terrain
inline bool wmgWaterWalkTerrain()
    { return true; }

// in order to move against the current, the water walker must be able to
// maintain a movement rate faster than the current
inline bool wmgWaterWalkCurrent()
    { return true; }

// the duration and area of effect of the magically created weather under
// weather summoning are dictated by the nature of the conditions called for
// by the caster
inline bool wmgWeatherSummonNature()
    { return true; }

// the caster should not attempt to summon any weather condition that could
// not conceivably occur during the current time of year; if he does, the
// Dungeon Master is entitled to disallow the request and consider the spell
// ruined
inline bool wmgWeatherSummonSeason()
    { return true; }

// weather conditions that prevailed before weather summoning was cast will
// resume when the duration expires, and the trend of the weather to come will
// be apparent to any character who observes the changing conditions, not just
// one with weather sense proficiency
inline bool wmgWeatherSummonResumes()
    { return true; }

// web can form a net beneath a falling character or object as long as two
// diametrically opposed vertical surfaces - two cliff faces close together,
// for instance - are available to serve as anchors for the web
inline bool wmgWebNetAnchors()
    { return true; }

// for every five feet of thickness, a web can protect a character from a fall
// of 10 feet
inline int wmgWebPerThickFt()
    { return 5; }

// a web up to 5 feet thick stops a fall of up to 10 feet
inline int wmgWebBand0FallFt()
    { return 10; }

// a web up to 10 feet thick stops a fall of up to 20 feet
inline int wmgWebBand1FallFt()
    { return 20; }

// a web up to 20 feet thick stops a fall of up to 40 feet
inline int wmgWebBand2FallFt()
    { return 40; }

// a web of 30 feet of thickness or more stops a fall of up to 60 feet, the
// maximum
inline int wmgWebMaxFallFt()
    { return 60; }

// when a web halts a tumble down a severe slope the fall distance figures are
// doubled
inline int wmgWebSevereMult()
    { return 2; }

// when a web halts a tumble down a moderate slope the fall distance figures
// are quadrupled
inline int wmgWebModerateMult()
    { return 4; }

// when a web halts a tumble down a gentle slope the fall distance figures are
// multiplied by eight
inline int wmgWebGentleMult()
    { return 8; }

// the tumble example: a 10-foot-thick web (both reads dropped the 0, printing
// a 1-inch web that cannot reconcile with the 5-feet-per-10-feet rule) halts
// a character after a tumble of 40 feet or less down a severe slope
inline int wmgWebSevereExThickFt()
    { return 10; }

// the severe-slope web example halts a tumble of 40 feet or less
inline int wmgWebSevereExTumbleFt()
    { return 40; }

// a 20-foot-thick web (the 2-inch misread, same dropped-0 class) brings a
// character safely to a halt after a fall of 160 feet or less down a moderate
// slope
inline int wmgWebModerateExThickFt()
    { return 20; }

// the moderate-slope web example halts a tumble of 160 feet or less
inline int wmgWebModerateExTumbleFt()
    { return 160; }

// the web thickness band: 0 for up to 5 feet, 1 for up to 10 feet, 2 for up
// to 20 feet, tail 3 for 30 feet or more (the band index the audit mirrors
// against the 10-20-40-60 fall distances)
inline int wmgWebThickBand(int x)
    {
        if (x <= 5) return 0;
        if (x <= 10) return 1;
        if (x <= 20) return 2;
        return 3;
    }

// if a character falls more than 60 feet a web will be of no use: his body
// will have built up so much velocity that it will keep falling as though the
// web was not there
inline bool wmgWebOverMax()
    { return true; }

// the web does not negate abrasion damage from a tumble, but it does prevent
// the character from suffering impact damage
inline bool wmgWebAbrasionNotImpact()
    { return true; }

// an illusionist who casts wraithform upon himself just before leaping or
// falling takes no damage from the impact of the fall, assuming he hits
// ground before the duration expires
inline bool wmgWraithformNoFallDmg()
    { return true; }

// the magic does not alter the weight or mass of the illusionist, only his
// physical nature and appearance
inline bool wmgWraithformWeight()
    { return true; }

// wraithform cannot be cast while the illusionist is falling, unlike feather
// fall which can be effected in mid-air, because one material component is a
// wisp of smoke; casting might be possible if the fall carries him through a
// cloud of smoke with the other component ready in hand, provided he can
// finish the casting before hitting the ground
inline bool wmgWraithformNoMidairCast()
    { return true; }

// ---- Potions ----

// an individual in gaseous form takes 3-30 points of damage if exposed to
// gale-force winds - the low end
inline int wmgGaseousGaleLo()
    { return 3; }

// the gaseous-form gale-force damage high end: 3-30 points
inline int wmgGaseousGaleHi()
    { return 30; }

// an individual in gaseous form is killed outright if hit by hurricane-force
// winds or a tornado
inline bool wmgGaseousHurricaneDeath()
    { return true; }

// a fighter who has drunk potion of invulnerability takes no damage from a
// fall of 40 feet or less and no abrasion damage from a tumble
inline int wmgInvulnFallFt()
    { return 40; }

// the invulnerability potion prevents no impact damage from a tumble of 80
// feet or less; farther than the given distances, impact damage is halved
inline int wmgInvulnTumbleFt()
    { return 80; }

// beyond the 40-foot fall and 80-foot tumble impact limits, the
// invulnerability potion halves the impact damage
inline bool wmgInvulnHalved()
    { return true; }

// the vitality potion negates the need to rest and take nourishment after a
// run spell and makes the imbiber immune to fatigue and exhaustion for up to
// seven days
inline int wmgVitalityDays()
    { return 7; }

// among other things the vitality potion covers the run spell aftermath and
// the fatigue and exhaustion effects described in this text
inline bool wmgVitalityRunAndFatigue()
    { return true; }

// ---- Protection scrolls ----

// the protection from cold scroll effective temperature is at least high
// enough to prevent adverse cold effects, or 40 degrees warmer than the
// current effective temperature, whichever is higher
inline int wmgScrollColdDeg()
    { return 40; }

// the cold scroll rule is a whichever-is-higher test between the
// no-adverse-effects temperature and the current-plus-40-degrees figure
inline bool wmgScrollColdRule()
    { return true; }

// the protection from fire scroll works similarly to the cold scroll except
// that the effective temperature is lowered instead of raised
inline bool wmgScrollFireMirror()
    { return true; }

// characters within 1 inch of the gas scroll reader are in an area of no wind
inline int wmgScrollGasRadiusIn()
    { return 1; }

// the gas scroll area of no wind means characters cannot be swept up by a
// tornado or blown across the countryside by a hurricane
inline bool wmgScrollGasNoWind()
    { return true; }

// a sandstorm is neutralized in the gas scroll area: when airborne grains of
// sand come into contact with the calm air they simply fall to the ground
inline bool wmgScrollGasSandstorm()
    { return true; }

// the effective temperature within the gas scroll protected area is altered
// to account for the absence of wind
inline bool wmgScrollGasTemp()
    { return true; }

// ---- Rings ----

// the ring of fire resistance makes the wearer immune to the effects of
// normal heat just as a protection from fire scroll does
inline bool wmgRingFireResScroll()
    { return true; }

// the ring of free action wearer moves and operates as if not encumbered
// unless actually severely encumbered, in which case he operates as if
// moderately encumbered
inline bool wmgRingFreeActionEncumbrance()
    { return true; }

// the ring of free action does not enable carrying more encumbrance than
// normal: attempting it negates the ring power until the excess baggage is
// rid of; the ring does not change the actual encumbrance value, so a mounted
// wearer has his normal effect on the animal carrying capacity
inline bool wmgRingFreeActionLimits()
    { return true; }

// the ring of protection plus is subtracted from each die of fall or tumble
// damage, to a minimum of 1 point of damage per die, applying to both
// abrasion and impact damage; the power is related to the armor class
// improvement and will not function if the character is wearing magical armor
inline bool wmgRingProtPlusPerDie()
    { return true; }

// all Constitution Checks for fatigue and exhaustion are made with a -5
// modifier to the die roll for the ring of sustenance wearer
inline int wmgRingSustMod()
    { return 5; }

// with the ring of sustenance, Constitution Checks for fatigue need not be
// made more often than once every six turns regardless of how long the
// character engages in strenuous activity
inline int wmgRingSustEveryTurns()
    { return 6; }

// even with the ring of sustenance fatigue modifier, an unmodified
// Constitution Check roll of 20 is still failure in any case
inline int wmgRingSustAutoFail()
    { return 20; }

// a ring of sustenance wearer is much less likely to be affected by fatigue
// or exhaustion
inline bool wmgRingSustFatigue()
    { return true; }

// the ring of warmth provides the same benefits as a protection from cold
// scroll does
inline bool wmgRingWarmthScroll()
    { return true; }

// ---- Rods, staves, and wands ----

// even out of charges, the rod of lordly might can still be used as - among
// other things - a climbing pole, a direction-finder and an altimeter
inline bool wmgLordlyOutOfCharges()
    { return true; }

// a severely encumbered character must make a successful Dexterity Check to
// safely negotiate the rod of lordly might climbing pole whenever it is
// extended to 20 feet or more
inline int wmgLordlyPoleFt()
    { return 20; }

// all characters other than the severely encumbered can move along the rod of
// lordly might rungs with no chance of slipping and falling under normal
// circumstances
inline bool wmgLordlyEncumbered()
    { return true; }

// if the staff of swarming insects is employed when the effective temperature
// is 40 degrees or lower it produces only half as many insects as normal
inline int wmgSwarmColdDeg()
    { return 40; }

// under the 40-degree threshold the staff of swarming insects produces 30
// insects plus 5 per level of the user
inline int wmgSwarmBase()
    { return 30; }

// the cold-weather staff of swarming insects per-level insect increment
inline int wmgSwarmPerLevel()
    { return 5; }

// the staff of swarming insects normally produces 60 insects plus 10 per
// level of the user
inline int wmgSwarmNormalBase()
    { return 60; }

// the normal staff of swarming insects per-level insect increment
inline int wmgSwarmNormalPerLevel()
    { return 10; }

// the staff of swarming insects cold-weather insect count is half of normal
// on both the base and the per-level increments
inline bool wmgSwarmHalved()
    { return true; }

// ---- Miscellaneous magic ----

// the apparatus of Kwalish can negotiate any solid or semi-solid surface
// except for a cliff face
inline bool wmgKwalishSurfaces()
    { return true; }

// at the Dungeon Master discretion the arrow of direction may be usable as a
// direction-finder in outdoor settings as well as subterranean environments
inline bool wmgArrowOutdoor()
    { return true; }

// cloak of protection: see ring of protection above
inline bool wmgCloakSeeRing()
    { return true; }

// the cube of force face five - keeps out all things
inline int wmgCubeFaceFive()
    { return 5; }

// when cube of force face five is activated, anything inside the cube is
// immune to damage from a fall or a tumble
inline bool wmgCubeFaceFiveImmune()
    { return true; }

// the Daern instant fortress is impervious to a hurricane or a tornado or
// obviously any wind of less strength, but it is not climate-controlled: the
// effective temperature inside will be the same as the actual temperature
// outside, not considering the effect of any wind that might be blowing
inline bool wmgDaernWindproof()
    { return true; }

// gauntlets of dexterity give a +10% modifier to the Climbing Rating whenever
// both hands and feet are used to traverse a surface
inline int wmgGauntDexBonusPct()
    { return 10; }

// gauntlets of fumbling give a -10% modifier to the Climbing Rating whenever
// both hands and feet are used to traverse a surface
inline int wmgGauntFumblePct()
    { return 10; }

// the mantle of Celestian personal temperature for the wearer is always
// comfortable
inline bool wmgMantleComfort()
    { return true; }

// the mantle of Celestian wearer is entirely protected from practically any
// form of precipitation including a sandstorm and need never worry about
// dying from thirst or starvation
inline bool wmgMantlePrecipitation()
    { return true; }

// the mantle of Celestian will not protect its wearer from impact damage from
// a fall, tumble, hailstones and the like, and it will not keep him safe from
// the adverse effects of high winds - he can still be swept away by a tornado
inline bool wmgMantleLimits()
    { return true; }

// the periapt of wound closure possessor is immune to abrasion damage from a
// tumble but still takes impact damage from a tumble or a fall as normal
inline bool wmgPeriaptAbrasionOnly()
    { return true; }

// a protrusion must be available within range for the rope of climbing to
// fasten itself; use the Grappling Success Table to determine if a protrusion
// exists, or alternatively allow a 100 percent chance on any non-smooth
// surface and a 50 percent chance on a smooth surface
inline bool wmgRopeGrappling()
    { return true; }

// shoes of Fharlanghn let the wearer travel on foot over any terrain as
// though it were normal instead of rugged or very rugged, with his movement
// rate increased accordingly
inline bool wmgFharlanghnTerrain()
    { return true; }

// a neutral or neutral good shoes of Fharlanghn wearer has a base Climbing
// Rating of 100 percent when negotiating a gentle or moderate slope
inline int wmgFharlanghnGentlePct()
    { return 100; }

// the shoes of Fharlanghn severe-slope or cliff-face-with-ledges base
// Climbing Rating is 80 percent
inline int wmgFharlanghnSeverePct()
    { return 80; }

// the shoes of Fharlanghn Climbing Ratings apply if the wearer is of neutral
// or neutral good alignment
inline bool wmgFharlanghnAlignment()
    { return true; }

// the stone of good luck affords its possessor a +5% modifier to his Climbing
// Rating
inline int wmgLuckyStoneClimbPct()
    { return 5; }

// the stone of good luck gives a -1 modifier to the die roll on any Dexterity
// Check or any Proficiency Check when dexterity is the appropriate related
// ability
inline int wmgLuckyStoneDie()
    { return 1; }

// the stone of good luck modifiers apply to Dexterity Checks and
// dexterity-related Proficiency Checks
inline bool wmgLuckyStoneDexChecks()
    { return true; }

}   // namespace rules
