// =========================================================================================
// Adnd1 - rules/wsghazd.h
// R486: the WSG NATURAL HAZARDS opener slice, printed pp. 76-79 - opening the
// natural hazards chapter in one content-density round: the volcano frame
// with the one-type rule, the lava general rules with the 250-yd/hr flow and
// the 2d3-week heat retention, the 1d4 lava bands (fluid 2d6 days with the
// 50-degree taper, thick 2d4 days with the 30-degree taper, pyroclastic with
// the 1-percent base and the 5-and-1d6-per-100-yards escalation), the ash
// cloud and fertilizer rules with the Mount St. Helens account, the 1d6 ash
// bands (light 1d4+2 weeks with the 1d3-burn and breath-weapon choke chain,
// heavy 1d6+5 hours with the 4000-yard danger zone, six with the 3-8-day
// pyroclastic spell), the explosive cloudkill bands with the 1d3-day warning,
// the light, moderate and severe quake classes with the doubling rule, and
// the tidal wave approach rules through the direct-path death - the section
// cut mid-sentence at the p. 79 bottom rides with R487.
// census 410 -> 411.
//
// THE SETTLE: two-way clean on the first pass - the tesseract full-text
// reads, the pdfy layout read and the tsv coordinate reads agree on every
// number of all four pages (the 250-yd/hr flow, the 2d3 weeks, the
// 50/30-degree rises with the 10-degree taper, the 500/2000/4000-yard danger
// radii, the 2000-3000 foot ash cloud, the 9,677 to 8,364 foot St. Helens
// peak, all the 1d4+2 and 1d10+15 style dice, the d6+9 and 1d6+3-tens quake
// durations, and the 150 mph, 75-foot, 500-foot, 30-second wave). The garbles
// all settled without contest: the tesseract 17/ and the pdfy 1V2 both read
// 1.5 miles, the /s and V4 mile reads are the one-quarter-mile reference
// distance, the tesseract underatreehasa1in 8 is under a tree has a 1 in 8,
// the book's own crevasse spelling stands, and the (1d6 +3) beside 40-90
// seconds is tens-of-seconds die notation. Printed p. 79 ends mid-sentence at
// and he will - the tidal wave death-rule continuation rides with R487, and
// the tidal waves gap box stays open until then.
//
// Bounds held: the 1d4 lava and 1d6 ash bands tile their dice exactly, the
// danger radii ascend 500 to 2000 to 4000 yards, both temperature rises are
// exact multiples of the quarter-mile taper closing at 1.5 and 1 mile, the
// severe quake exactly doubles the moderate penalties, the cloudkill hit-die
// bands abut at 8+1 and 10+1, the ash accumulations ascend 2 to 6 to 9
// inches, and the 150-mph wave sighted at half a mile fits inside the
// 30-second warning bound.
//
namespace rules {

// ---- The volcano frame ----

// three types of volcanic eruption for game purposes: lava, ash, explosive
inline int whzVolcanoEruptionTypes()
    { return 3; }

// any single volcano always erupts in only one of the three types - it will
// not spout a lava eruption one time and an ash eruption the next
inline bool whzOneTypePerVolcano()
    { return true; }

// a volcano can lie dormant so long it is forgotten even in local legends,
// then in the space of days or even hours come alive and unleash all its fury
inline bool whzDormantAwakensFast()
    { return true; }

// other volcanoes are almost perpetually active, spitting out a bit of ash
// and smoke every few weeks as a reminder
inline bool whzPerpetuallyActive()
    { return true; }

// ---- Lava eruptions ----

// the molten rock is properly called magma when inside the volcano and lava
// after it is expelled
inline bool whzMagmaInsideLavaOut()
    { return true; }

// the red-hot liquid can spray out of the center of the crater if forced out
// by fairly high pressure from beneath and if the molten rock is relatively
// thick
inline bool whzLavaSpraysWhenThick()
    { return true; }

// the more fluid the magma beneath the surface, the less violent the
// explosion when it is propelled up to the surface
inline bool whzFluidMagmaLessViolent()
    { return true; }

// some lava finds its way out through fissures in the sides, which dissipates
// the force of the eruption out of the crater mouth but does not eliminate
// the possibility of a crater flow
inline bool whzLavaSideFissures()
    { return true; }

// lava can come out of the top and the sides of a volcano at the same time
inline bool whzLavaTopAndSides()
    { return true; }

// lava incinerates any combustible object it comes into contact with, even
// after it has cooled so much that it is barely still flowing
inline bool whzLavaIncinerates()
    { return true; }

// even after it stops flowing and looks cooled, the lava retains serious-burn
// heat for 2d3 weeks: minimum 2
inline int whzLavaHeatWeeksMin()
    { return 2; }

// the 2d3-week heat retention maximum
inline int whzLavaHeatWeeksMax()
    { return 6; }

// a character capable of movement and in control of his faculties can almost
// certainly avoid flowing lava even a short distance from the source
inline bool whzLavaAvoidable()
    { return true; }

// a speed of 250 yards per hour is about average for a lava flow, and it does
// not usually gush forth in massive quantities at one time
inline int whzLavaFlowYardsPerHour()
    { return 250; }

// the greater danger near a lava eruption is the expulsion of pyroclastic
// material - bombs and blocks, blobs of semi-hardened magma and chunks of
// rock carried along in the upward flow, thrown high and far by the force of
// the eruption
inline bool whzPyroclasticBombsBlocks()
    { return true; }

// ---- The lava eruption 1d4 bands ----

// 1d4 result 1-2, fluid magma: the eruption spews for 2d6 days, minimum 2
inline int whzFluidLavaDaysMin()
    { return 2; }

// the 2d6-day fluid eruption maximum
inline int whzFluidLavaDaysMax()
    { return 12; }

// fluid magma: a character closer than 500 yards to a significant source
// takes at least 1d6 points of damage per turn from radiant heat, possibly
// much more when considerably closer
inline int whzFluidLavaHeatDmgDie()
    { return 6; }

// fluid magma: the effective air temperature one-quarter mile from the site
// increases by 50 degrees for as long as the eruption continues, much more in
// close proximity
inline int whzFluidTempRiseDeg()
    { return 50; }

// the radiant-heat damage range for both the fluid and the thick bands:
// closer than 500 yards to a significant source or sizable quantity
inline int whzLavaHeatRangeYards()
    { return 500; }

// the fluid and thick temperature increases taper off by 10 degrees per
// additional quarter mile of distance from the site
inline int whzLavaTempTaperDeg()
    { return 10; }

// fluid magma: no heat difference is detectable from 1.5 miles away - six
// quarter-miles from the site
inline int whzFluidNoHeatQmi()
    { return 6; }

// 1d4 result 3, thick magma: sprays into the air and flows out around the
// crater mouth for 2d4 days, minimum 2
inline int whzThickLavaDaysMin()
    { return 2; }

// the 2d4-day thick eruption maximum
inline int whzThickLavaDaysMax()
    { return 8; }

// thick magma: a character closer than 500 yards to a sizable quantity
// suffers at least 1d4 points of damage per turn
inline int whzThickLavaHeatDmgDie()
    { return 4; }

// thick magma: the effective air temperature one-quarter mile from the site
// increases by 30 degrees
inline int whzThickTempRiseDeg()
    { return 30; }

// thick magma: no heat difference is felt from 1 mile away - four
// quarter-miles
inline int whzThickNoHeatQmi()
    { return 4; }

// 1d4 result 4, thick magma plus pyroclastic material: a character within
// 1,000 yards of the site is subject to the falling bombs and blocks
inline int whzPyroclasticRangeYards()
    { return 1000; }

// a 1 percent chance per hour of being hit by one or more chunks of
// pyroclastic material
inline int whzPyroclasticHitChancePct()
    { return 1; }

// a pyroclastic hit costs 2d6 hit points from burn and impact damage, minimum
// 2
inline int whzPyroclasticDmgMin()
    { return 2; }

// the 2d6-point pyroclastic hit maximum
inline int whzPyroclasticDmgMax()
    { return 12; }

// for every 100 yards of distance less than 1,000 yards from the site
inline int whzPyroclasticStepYards()
    { return 100; }

// each 100 yards closer increases the hourly hit chance by 5 percent
inline int whzPyroclasticChanceStepPct()
    { return 5; }

// each 100 yards closer increases the damage from a hit by 1d6
inline int whzPyroclasticDmgStepDie()
    { return 6; }

// ---- Ash eruptions ----

// volcanoes with ash eruptions can and often do expel some lava at the same
// time, but the molten rock is overshadowed by huge clouds of thick hot ash
inline bool whzAshEruptionsExpelLava()
    { return true; }

// aside from the initial blast that begins the eruption, ash volcanoes are
// seldom violent - the danger comes from the enormous amount of ash, dust and
// minuscule lava particles, not explosive force or heat
inline bool whzAshSeldomViolent()
    { return true; }

// the original ash cloud can easily be 2,000 or 3,000 feet high directly
// above the mouth of the volcano
inline int whzAshCloudHeightMinFt()
    { return 2000; }

// the original cloud height upper figure
inline int whzAshCloudHeightMaxFt()
    { return 3000; }

// the original cloud is so thick that one cannot see into it, much less
// through it
inline bool whzAshCloudOpaque()
    { return true; }

// the lighter particles can be carried by the wind for dozens of miles before
// settling to the ground
inline bool whzAshLighterCarriedFar()
    { return true; }

// even dozens of miles out, the accumulation on solid surfaces can be as
// great as three or four inches over an average-length eruption of moderate
// intensity
inline int whzAshFarAccumInchesMin()
    { return 3; }

// the far accumulation upper figure
inline int whzAshFarAccumInchesMax()
    { return 4; }

// the ash chokes and kills any green plant life that receives even a moderate
// dusting
inline bool whzAshKillsPlants()
    { return true; }

// the chemical composition of volcanic ash makes it one of nature's best
// fertilizers - within a few months the slopes are again covered with plants
// thriving on the rich soil that killed their predecessors
inline bool whzAshFertilizer()
    { return true; }

// the eruption of Mount St. Helens in the northwestern United States was an
// ash eruption
inline bool whzStHelensWasAshEruption()
    { return true; }

// the Mount St. Helens eruption occurred during 1980 and 1981
inline int whzStHelensYear()
    { return 1980; }

// actually six separate incidents over a 10-month period
inline int whzStHelensIncidents()
    { return 6; }

// the six incidents spanned 10 months
inline int whzStHelensMonths()
    { return 10; }

// the superheated gas expelled from the summit melted the surrounding snow
// cover, leading to mudslides
inline bool whzStHelensSnowmeltMudslides()
    { return true; }

// the mudslides covered more than 100,000 acres of land in the vicinity
inline int whzStHelensMudslideAcres()
    { return 100000; }

// the initial blast on May 18, 1980 had a force equal to a 10-megaton
// hydrogen bomb
inline int whzStHelensBlastMegatons()
    { return 10; }

// the concussive force knocked over trees as far as 4 miles away
inline int whzStHelensTreesMiles()
    { return 4; }

// the entire time the volcano remained active the summit was pulverized
inline bool whzStHelensPeakPulverized()
    { return true; }

// the peak of Mount St. Helens was 9,677 feet above sea level before the
// eruption
inline int whzStHelensBeforeFt()
    { return 9677; }

// and only 8,364 feet when the last expulsion of ash subsided
inline int whzStHelensAfterFt()
    { return 8364; }

// ---- The ash eruption 1d6 bands ----

// 1d6 result 1-3, light to moderate but extended: ash is expelled for at
// least 12 hours each day
inline int whzAshLightDailyHours()
    { return 12; }

// for a period of 1d4+2 weeks, minimum 3
inline int whzAshLightWeeksMin()
    { return 3; }

// the 1d4+2-week duration maximum
inline int whzAshLightWeeksMax()
    { return 6; }

// a significant amount of ash, at least 2 inches of total accumulation, is
// carried downwind
inline int whzAshLightFarAccumInches()
    { return 2; }

// the significant ash settles 1d10+15 miles from the site in the direction of
// the prevailing winds, minimum 16
inline int whzAshLightFarMilesMin()
    { return 16; }

// the 1d10+15-mile downwind maximum
inline int whzAshLightFarMilesMax()
    { return 25; }

// heavier amounts of ash, 6 inches or more, settle everywhere within the near
// radius
inline int whzAshLightNearAccumInches()
    { return 6; }

// the heavy accumulation falls within a radius of 1d6+4 miles of the site,
// minimum 5
inline int whzAshLightNearMilesMin()
    { return 5; }

// the 1d6+4-mile near radius maximum
inline int whzAshLightNearMilesMax()
    { return 10; }

// a character within 2,000 yards of the eruption site suffers the burn damage
inline int whzAshLightDangerYards()
    { return 2000; }

// 1d3 points of burn damage per turn from the hot particles that settle on
// his body
inline int whzAshBurnDmgDie()
    { return 3; }

// unless the character is in a shelter or otherwise protected
inline bool whzAshShelterProtects()
    { return true; }

// such a character must make a saving throw versus breath weapon once per
// turn to avoid going into a choking fit
inline bool whzChokeSaveBreathWeapon()
    { return true; }

// in a choking fit: -4 on attack rolls
inline int whzChokeAtkPenalty()
    { return 4; }

// in a choking fit: +4 to be hit
inline int whzChokeBeHitBonus()
    { return 4; }

// a character who fails two saving throws in succession is in danger of being
// asphyxiated or suffocated
inline bool whzChokeTwoFailsAsphyxiate()
    { return true; }

// the asphyxiating character takes 1d4 points of damage per round
inline int whzAsphyxDmgDie()
    { return 4; }

// and will die unless he can receive aid within one turn
inline bool whzAsphyxAidWithinTurn()
    { return true; }

// 1d6 result 4-5, heavy but relatively short: ash is expelled 1d6+5 hours
// each day, minimum 6
inline int whzAshHeavyHoursMin()
    { return 6; }

// the 1d6+5 daily-hours maximum
inline int whzAshHeavyHoursMax()
    { return 11; }

// for a period of 1d3 weeks, minimum 1
inline int whzAshHeavyWeeksMin()
    { return 1; }

// the 1d3-week duration maximum
inline int whzAshHeavyWeeksMax()
    { return 3; }

// a significant amount of ash accumulates 1d6+9 miles away from the site in
// the direction of the wind, minimum 10
inline int whzAshHeavyFarMilesMin()
    { return 10; }

// the 1d6+9-mile downwind maximum
inline int whzAshHeavyFarMilesMax()
    { return 15; }

// a heavy accumulation of 9 inches or more comes down everywhere within the
// near radius
inline int whzAshHeavyNearAccumInches()
    { return 9; }

// the heavy accumulation falls within a radius of 1d6+2 miles of the site,
// minimum 3
inline int whzAshHeavyNearMilesMin()
    { return 3; }

// the 1d6+2-mile near radius maximum
inline int whzAshHeavyNearMilesMax()
    { return 8; }

// the heavy-band danger zone for characters is 4,000 yards
inline int whzAshHeavyDangerYards()
    { return 4000; }

// with the light-band effects upon those who are unprotected and within the
// heavy danger zone
inline bool whzAshHeavyUnprotectedEffects()
    { return true; }

// 1d6 result 6, the first 3-8 days of the heavy eruption are marked by the
// expulsion of pyroclastic material, minimum 3
inline int whzAshSixPyrDaysMin()
    { return 3; }

// the pyroclastic spell of band 6 lasts at most 8 days
inline int whzAshSixPyrDaysMax()
    { return 8; }

// ---- Explosive eruptions ----

// an explosive eruption cannot be characterized in general terms, but the
// opening salvo can be strong enough to literally blow the top off the
// volcano
inline bool whzExplosiveBlowsTop()
    { return true; }

// a volume of several million cubic feet of rock around the crater mouth
// cracks and crumbles, and the peak collapses into the chamber of magma or
// ash (or both) beneath the surface
inline bool whzExplosivePeakCollapses()
    { return true; }

// any characters or creatures within sight range of an explosive eruption are
// in mortal danger from a variety of sources: a huge cloud of ash and
// pyroclastic material raining down on the countryside
inline bool whzExplosiveSightRangeDanger()
    { return true; }

// a glowing avalanche of thick lava and heavy ash flows from the newly
// enlarged mouth, threatening to incinerate and then inundate anything within
// a radius of 3-5 miles, minimum 3
inline int whzGlowingAvalancheMilesMin()
    { return 3; }

// the glowing-avalanche radius maximum
inline int whzGlowingAvalancheMilesMax()
    { return 5; }

// the ash cloud or the avalanche, or both, exude superheated air and noxious
// gases with the effect of a double-strength cloudkill spell
inline int whzCloudkillStrength()
    { return 2; }

// breathing the air for as little as one-half round slays anything with fewer
// than 8+1 hit dice
inline bool whzExplosiveCloudkillBreath()
    { return true; }

// the cloudkill slays fewer than 8+1 hit dice - 9 hit dice and below
inline int whzCloudkillSlaysBelowHd()
    { return 9; }

// those with 8+1 to 10+1 hit dice must save versus poison at -4
inline int whzCloudkillMidSavePenalty()
    { return 4; }

// those with more than 10+1 hit dice - 11 and above - must save versus poison
// normally to avoid death
inline int whzCloudkillMidMaxHd()
    { return 11; }

// an explosive eruption gives sufficient warning first: the volcano puffs out
// small ash clouds, leaks small amounts of lava, and perhaps sends moderate
// tremors through the ground
inline bool whzExplosiveWarnsFirst()
    { return true; }

// the warning signs continue for 1d3 days before the eruption begins with
// full force - anyone who remains despite them gets what he deserves
inline int whzExplosiveWarningDaysMax()
    { return 3; }

// ---- Earthquakes ----

// when the earth moves nothing can stand its ground - the only way to avoid
// an earthquake is to take to the air at just the right time
inline bool whzQuakeOnlyAvoidedByAir()
    { return true; }

// earthquakes do not occur very often, those that do are generally confined
// to small areas, and the vast majority strong enough to be noticeable are
// not strong enough to do any harm
inline bool whzQuakeMostlyHarmless()
    { return true; }

// this discussion is limited to quakes in wilderness areas with no stable
// human or humanoid populations, since the book's scope does not include
// cities and villages
inline bool whzQuakeWildernessScope()
    { return true; }

// most earthquakes occur along fault lines, where two sections of bedrock
// come together and exert pressure against each other - the DM places the
// fault lines, the characters find them for themselves
inline bool whzQuakeFaultLines()
    { return true; }

// when the pressure exceeds the strength of the rocks, one or both rock
// masses shifts along the fault line, and the shock waves - extending over a
// much larger area - do much more actual damage than the fault-line shift
// that started the quake
inline bool whzQuakeShockWavesDoMoreDamage()
    { return true; }

// one earthquake can cause another if the tremors from the first set off
// activity along a second nearby fault line
inline bool whzQuakeTriggersQuake()
    { return true; }

// a quake hardly ever ends with just one tremor - aftershocks occur
// sporadically for several days as mountain-sized slabs continue to settle
inline bool whzQuakeAftershocksDays()
    { return true; }

// for game purposes earthquakes are classified as light, moderate, or severe
inline int whzQuakeClasses()
    { return 3; }

// a light quake is a shivering or vibrating force through the ground and
// everything in contact with it, lasting a few seconds or even less, with no
// directly hazardous effects
inline bool whzLightQuakeFewSeconds()
    { return true; }

// a light quake striking a magic-user preparing a spell disrupts his
// concentration and ruins the spell
inline bool whzLightQuakeRuinsSpell()
    { return true; }

// a thief defusing or avoiding a trap is jostled
inline bool whzLightQuakeThiefJostled()
    { return true; }

// the jostled thief has a 50 percent chance to fail even if an earlier dice
// roll indicated he would succeed
inline int whzLightQuakeThiefFailPct()
    { return 50; }

// a tightrope walker has his chance of success cut in half and falls unless
// he grabs the rope with a successful Dexterity Check; the DM judges when
// other concentration or balance tasks are likewise affected
inline bool whzLightQuakeTightropeHalved()
    { return true; }

// ---- The moderate and severe quake ----

// a moderate quake has all the effects of a light quake
inline bool whzModQuakeHasLightEffects()
    { return true; }

// a moderate quake normally lasts d6+9 seconds, minimum 10
inline int whzModQuakeSecMin()
    { return 10; }

// the d6+9-second moderate duration maximum
inline int whzModQuakeSecMax()
    { return 15; }

// occasionally (20 percent) a moderate quake lasts less than the normal
// duration
inline int whzModQuakeLessPct()
    { return 20; }

// sometimes (30 percent) more, up to 25 or 30 seconds
inline int whzModQuakeMorePct()
    { return 30; }

// the occasional long moderate quake tops out at 30 seconds
inline int whzModQuakeMoreSecMax()
    { return 30; }

// a moderate quake can dislodge a character from a precarious position even
// if the position is not particularly unstable
inline bool whzModQuakeDislodges()
    { return true; }

// a character straddling a limb or branch is toppled from his perch unless he
// makes both a Dexterity Check (reacting in time) and a Strength Check
// (grabbing the limb and holding on until the quake subsides)
inline bool whzModQuakeToppleNeedsDexStr()
    { return true; }

// someone climbing a severe or moderate slope must make a Climbing Check at a
// -50 percent penalty to his Climbing Rating to avoid losing his footing and
// tumbling down the slope
inline int whzModQuakeClimbPenaltyPct()
    { return 50; }

// a character specialized in a missile weapon takes a -2 penalty to hit if he
// gets a shot off during a moderate quake
inline int whzModQuakeSpecMissilePenalty()
    { return 2; }

// the specialist's -2 penalty does not apply at point blank range
inline bool whzModQuakeSpecPointBlankOk()
    { return true; }

// a non-specialist with a missile weapon takes -3 to hit at short range
inline int whzModQuakeNonSpecShort()
    { return 3; }

// a -5 penalty at medium range
inline int whzModQuakeNonSpecMed()
    { return 5; }

// and a -7 penalty at long range
inline int whzModQuakeNonSpecLong()
    { return 7; }

// the non-specialist penalties are in addition to the usual penalties for
// medium and long range
inline bool whzModQuakeNonSpecRangeStacks()
    { return true; }

// any character in melee combat takes a -3 penalty on all attack rolls
inline int whzModQuakeMeleePenalty()
    { return 3; }

// and if he misses he will slip and fall as if he was attacking while
// standing on a slippery horizontal surface
inline bool whzModQuakeMissSlipFall()
    { return true; }

// a character at the base of a cliff or severe slope may be set upon by a
// rockfall or a mudslide depending on the terrain makeup
inline bool whzModQuakeRockfallMudslide()
    { return true; }

// of course, anyone climbing either of those surfaces is also subject to
// these perils
inline bool whzModQuakeClimberAlsoAtRisk()
    { return true; }

// a character standing under a tree has a 1-in-8 chance of being hit if the
// tree is uprooted and falls
inline int whzModQuakeTreeFallChance()
    { return 8; }

// it is rare but possible for a moderate quake to open a fissure in the
// ground
inline bool whzModQuakeFissureOpens()
    { return true; }

// an unfortunate character standing in that exact spot takes falling damage,
// and possibly abrasion damage as well if he bounces off the sides of the
// crevasse
inline bool whzModQuakeFissureFallingDmg()
    { return true; }

// a very unfortunate character, if not killed by the fall, is suffocated or
// crushed if the two sides of the fissure move toward each other after
// separating
inline bool whzModQuakeFissureCrush()
    { return true; }

// a severe quake has all the effects of a moderate quake, with all penalties
// and all chances of unfortunate occurrences multiplied by two
inline bool whzSevQuakeDoublesAll()
    { return true; }

// the Climbing Rating penalty is -100 percent instead of -50
inline int whzSevQuakeClimbPenaltyPct()
    { return 100; }

// the melee attack-roll penalty is -6 instead of -3
inline int whzSevQuakeMeleePenalty()
    { return 6; }

// the chance of a rockfall occurring adjacent to a cliff face is twice as
// great, and so forth
inline bool whzSevQuakeRockfallDoubled()
    { return true; }

// a severe quake lasts 1d6+3 tens of seconds - 40 to 90 seconds, minimum 40
inline int whzSevQuakeSecMin()
    { return 40; }

// the severe duration maximum
inline int whzSevQuakeSecMax()
    { return 90; }

// during a severe quake the only sensible course of action is to hit the
// ground (but not from 50 feet in the air), cover your head, and pray to the
// deity of your choice
inline bool whzSevQuakeHitTheGround()
    { return true; }

// ---- Tidal waves ----

// a tidal wave is created by some cataclysmic occurrence on the ocean floor,
// such as an earthquake or the eruption of an undersea volcano
inline bool whzTidalCreatedOnOceanFloor()
    { return true; }

// unlike a shock wave in solid matter, the ocean water in the immediate
// vicinity absorbs the force and passes it on to the surrounding water with
// relatively little decrease in intensity
inline bool whzTidalShockAbsorbed()
    { return true; }

// unless and until something gets in its way, a tidal wave can travel for
// thousands of miles and still possess enormous force when it hits land
inline bool whzTidalTravelsFar()
    { return true; }

// a character within sight of the shore and looking out to sea will notice
// the oncoming wall of water when it is one-half mile away from the shore
inline int whzTidalSightHalfMiles()
    { return 1; }

// this much warning may provide time for some precaution - aerial movement,
// magical protection - but time is at a premium
inline bool whzTidalPrecautionWindow()
    { return true; }

// the velocity of the wave will be at least 150 miles per hour
inline int whzTidalMinMph()
    { return 150; }

// even in the best case less than 30 seconds pass from the time it is sighted
// until it hits the shore
inline int whzTidalMaxWarnSec()
    { return 30; }

// the wave will be at least 75 feet tall
inline int whzTidalMinHeightFt()
    { return 75; }

// and 500 feet long when it hits
inline int whzTidalLengthFt()
    { return 500; }

// which translates to a volume of almost 30 million gallons for the smallest
// tidal wave possible
inline int whzTidalVolumeMillionGal()
    { return 30; }

// a tidal wave may rush inland for several miles before its force is spent
inline bool whzTidalRushesInland()
    { return true; }

// its velocity diminishes rapidly after it hits land, but several million
// gallons of water at only 20 miles per hour can still wreak a lot of havoc
inline bool whzTidalInlandDiminishes()
    { return true; }

// the diminished inland velocity of the several million gallons still moving
inline int whzTidalInlandMph()
    { return 20; }

// how far inland the wave moves and how rapidly it dissipates depend upon the
// terrain along the coastline
inline bool whzTidalTerrainGoverns()
    { return true; }

// if an ocean ends at the base of a cliff rising 5,000 feet above the water
inline int whzTidalCliffFt()
    { return 5000; }

// people standing a few hundred yards from the edge of such a cliff might not
// even get wet
inline bool whzTidalCliffSpares()
    { return true; }

// but if the terrain 20 miles inland is still only a few feet above sea level
inline int whzTidalLowlandMiles()
    { return 20; }

// people standing there have almost as much to fear as those who live on the
// coast itself
inline bool whzTidalLowlandFears()
    { return true; }

// a character directly in the path of a tidal wave will die - if he survives
// the buffeting he will at least be knocked unconscious (the section
// continues onto p. 80 and rides with R487)
inline bool whzTidalPathKills()
    { return true; }

}   // namespace rules
