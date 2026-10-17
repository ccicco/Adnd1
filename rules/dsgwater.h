// =========================================================================================
// Adnd1 - rules/dsgwater.h
// The DSG UNDERGROUND WATERWAYS, R517: printed pp. 43-46 (pdf 44-47) - the
// standing water rules (the pools, reservoirs, lakes and seas, the low
// ceiling blocking normal boat travel, the absence of wind making sailing
// virtually unheard-of, the practically nonexistent waves with the cave-in
// tsunami and the confining-wall chop, the fresh lakes and pools safe to
// drink when fed by a stream or spring, and the reservoir dams that may sit
// at the bottom like a cork), the deep salt seas with their geothermal steam,
// the flowing-water characteristics (the impassable, narrow, average and wide
// diameter ladder, the 50/100% flow percentages, and the 0-40 rate of flow
// with the 20-feet-per-round multiplier), the six flow bands from stagnant
// through placid and medium to rapids, cascades and waterfalls with their
// speeds, slopes, audibility and drop-off dice, the damming rules (the 1,000
// cubic feet per flow point per turn, the double-wide/quarter-narrow
// adjustment, the 1d6 dam points per worker per turn, the flow-rate
// destruction, the 50/150/250 completed CPVs and the half-flow leak), the
// water temperature ladder (the almost universally cold water, the 1d4-mile
// warmth retention, the 6d6 near-boiling burn with no save and the -2 per
// die, the 1d6 very-hot damage, and the bath-warm immunity), and the access
// rules (the occasional direct surface embark, the usual dungeon route, the
// upstream-travel cost of an outlet, the cliff-not-sand lake shores with
// their creature docks, and the sandy stream banks)
// census 440 -> 441.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~5533-5962) with the pdf Acrobat-Capture layer as the second read (idx
// 61-62 = printed pp. 44-45, with the section opener on idx 60) - every
// numeric cell dual-confirmed: the 3/20/60 diameter ladder with the 3/4-8/8
// depths, the 50/100% flow, the 0-40 scale with the x20 ft/round, the
// 1-2/2-6/6-12/12-30/30-40 bands with the 40/120, 120/240, 240/600 and 600
// speeds and the 10-15/30/30-200/200-1000/>1000 slopes, the 1,000-ft rapids
// audibility and 1-mile cascade audibility, the 1d6/1d3, 1d6/1d4 and 3d6/1d8
// drop-off dice, the 1,000 cu ft, 1d6 and 50/150/250 dam numbers, and the
// 1d4/6d6/-2/1/1d6 temperature ladder. The djvu garbles: 10096 = 100% flow
// (the Capture reads 1000/0), "flow rate - 2-6" = 2-6 (the Capture reads "=
// 2-6"), and a stray STRUCTGRAL DECAY heading interrupting the waterways
// opener (the Capture reads clean). The Underground Water Travel section
// (Tables 21-26) starts the NEXT round per the content-density rule.
//
// No tables in this section - the pins are consts and bools only, the biggest
// header since R509. Every die pins as dice + sides consts per the R508
// convention (the medium 1d6/1d3, the rapids 1d6/1d4, the cascade 3d6/1d8,
// the dam 1d6, the warmth 1d4, the boiling 6d6, the very-hot 1d6). The flow
// bands overlap at their edges exactly as printed (medium 2-6 shares 2 with
// placid 1-2, rapids 6-12 share 6 with medium, and so on) - they pin as bound
// consts, NOT a chain, because a chain would force non-overlap the book does
// not have. The DMG pages 109-110 Construction Point Value seam and the DSG
// page 114 three-dimensional-maps note are noted; nothing auto-credits.
//
namespace rules {

// ---- the standing water rules ----

// water underground is found as flowing water (brooks, streams, and rivers)
// and standing water (pools, reservoirs, lakes, and seas).
inline bool dntStandingWaterForms()
    { return true; }

// if the ceiling over an underground lake, pool, or sea touches the surface
// of the water or leaves only a few inches of clearance, normal boat travel
// is impossible.
inline bool dntLowCeilingBlocksBoats()
    { return true; }

// the absence of wind means that sailing is virtually unheard-of underground,
// except in those rare instances where the ventilation is ample enough to
// create a wind capable of moving a boat.
inline bool dntNoWindSailingRare()
    { return true; }

// waves are practically nonexistent underground; lake and sea shores are not
// eroded by wave action.
inline bool dntWavesPracticallyNonexistent()
    { return true; }

// a cave-in somewhere above or next to a lake often forces a powerful wave
// outward, much like a tsunami; earthquakes often produce similarly
// destructive waves in the Underdark.
inline bool dntCaveInMakesTsunamiWave()
    { return true; }

// the action of waves is often amplified and confused by the confining walls:
// a large wave in a small body of water can last for many turns - the exact
// duration is left to the DM, depending on the force of the original wave and
// the size of the enclosing area.
inline bool dntChopAmplifiedByWalls()
    { return true; }

// other causes of waves include animal, monster, and humanoid activity, and
// streams flowing into a standing body; characters confronted with waves on
// otherwise still water are wise to determine the source of the disturbance.
inline bool dntWiseToFindWaveSource()
    { return true; }

// lakes and pools make up the majority of underground bodies of water; they
// differ in size (lakes are larger) but both contain fresh water, and can be
// found at nearly all depths of the Underdark.
inline bool dntLakesPoolsFreshWater()
    { return true; }

// if a lake or pool has a stream or spring flowing into it, the water is
// almost always safe to drink.
inline bool dntInflowWaterSafeToDrink()
    { return true; }

// reservoirs are commonly created by intelligent denizens; the dam is not
// always built along the side - it may be located at the bottom, serving much
// the same function as a cork in the bottom of a leaky bucket.
inline bool dntReservoirDamMayBeAtBottom()
    { return true; }

// ---- the seas of the Underdark ----

// seas lie in the deepest depths of the Underdark: salty water heavy with
// minerals dissolved from the surrounding rock, and almost always huge in
// comparison to other underground bodies of water because of their age.
inline bool dntSeasDeepSaltHuge()
    { return true; }

// whole races inhabit the seas of the Underdark; some seas are cold, vast,
// and deep, while others lie so close to geothermal heat sources that their
// waters are warm and the surrounding air is heavy with steam.
inline bool dntSeasGeothermalSteam()
    { return true; }

// ---- the passage diameter ladder ----

// flowing water is more commonly encountered underground than standing water
// - it is flowing water that has shaped much of the underground environment.
inline bool dntFlowingMoreCommonThanStanding()
    { return true; }

// the characteristics of a flowing body of water are determined by three
// significant measurements: the diameter of the waterway, the percentage of
// the passage that is filled with water, and the rate of flow.
inline bool dntThreeMeasurements()
    { return true; }

// at least part of an impassable waterway must be less than three feet in
// diameter.
inline int dntImpassableMaxDiaFt()
    { return 3; }

// a narrow waterway follows a path less than 20 feet wide.
inline int dntNarrowMaxWidthFt()
    { return 20; }

// a narrow waterway is generally less than three feet deep.
inline int dntNarrowTypicalMaxDepthFt()
    { return 3; }

// average waterways include streams and small rivers from 20 to 60 feet wide.
inline int dntAverageMinWidthFt()
    { return 20; }

// the wide end of the average waterway band: 20 to 60 feet wide.
inline int dntAverageMaxWidthFt()
    { return 60; }

// average waterways are usually four to eight feet deep, though occasionally
// shallow enough to wade in.
inline int dntAverageDepthLowFt()
    { return 4; }

// the deep end of the average waterway band: usually four to eight feet deep.
inline int dntAverageDepthHighFt()
    { return 8; }

// wide waterways include all areas of flowing water more than 60 feet wide.
inline int dntWideMinWidthFt()
    { return 60; }

// the depth of a wide waterway is generally greater than eight feet, at least
// in the center; the water near each bank is often considerably shallower.
inline int dntWideMinDepthFt()
    { return 8; }

// artificially constructed underground waterways include canals for water
// transportation and aqueducts moving water from one location to another; the
// underground races also use flowing water to turn water wheels powering
// fans, pumps, and other machinery, and water-powered pumps even operate
// locks on underground canals.
inline bool dntArtificialCanalsAqueducts()
    { return true; }

// ---- the percentage of flow ----

// a river passage with a 50% flow is half-full of water and half-full of air.
inline int dntHalfFlowPct()
    { return 50; }

// a passage with 100% flow is completely filled with water and impossible to
// boat through (the djvu garble 10096 = 100%, settled by the Capture 1000/0
// read).
inline int dntFullFlowPct()
    { return 100; }

// a passage with 100% flow is completely filled with water and impossible to
// boat through.
inline bool dntFullFlowUnboatable()
    { return true; }

// ---- the rate of flow scale ----

// rate of flow is quantified as a number ranging from 1-40: a current of 1 is
// barely moving, while those rated 40 tumble down as waterfalls.
inline int dntFlowRateMax()
    { return 40; }

// a completely stagnant body of water receives a 0 rating - the water
// collects in pools and low spots when there is no downhill flow.
inline int dntStagnantFlowRate()
    { return 0; }

// the actual movement rate of the current can be calculated by multiplying
// the flow rate by 20 feet per round.
inline int dntFtPerRoundPerFlowPoint()
    { return 20; }

// travel along stagnant water is not threatened by flow, but it may be
// difficult if the water is too shallow to support a boat.
inline bool dntStagnantShallowBoatRisk()
    { return true; }

// ---- the placid and medium bands ----

// placid water usually has a noticeable flow (flow rate = 1-2), often
// encountered near the mouths of streams or rivers or in lakes.
inline int dntPlacidMaxFlowRate()
    { return 2; }

// placid water sometimes requires dropping bits of wood, dust, or other
// floating objects into the water to determine the direction of its flow.
inline bool dntPlacidFloatersShowFlow()
    { return true; }

// a placid waterway has a barely perceptible drop in altitude, often no more
// than 10 or 15 feet per mile.
inline int dntPlacidDropLowFtPerMile()
    { return 10; }

// the high end of the placid drop band: no more than 10 or 15 feet per mile.
inline int dntPlacidDropHighFtPerMile()
    { return 15; }

// the rate of flow of a placid stream is 40 feet or less per round; any rocks
// or obstacles can be easily avoided.
inline int dntPlacidMaxFtPerRound()
    { return 40; }

// medium flowing water is the most pleasant for traveling downstream (flow
// rate = 2-6; the djvu garble "flow rate - 2-6" settled by the Capture "=
// 2-6" read).
inline int dntMediumMaxFlowRate()
    { return 6; }

// medium water flows along at between 40 and 120 feet per round, descending
// only slightly on its course.
inline int dntMediumFtPerRoundLow()
    { return 40; }

// the fast end of the medium band: between 40 and 120 feet per round.
inline int dntMediumFtPerRoundHigh()
    { return 120; }

// a river with a medium flow may drop as much as 30 feet over the course of a
// mile.
inline int dntMediumDropFtPerMile()
    { return 30; }

// travel along a medium waterway is relatively safe, but characters must keep
// a lookout for rocks protruding from the water; the inattentive may be drawn
// into an unfortunate collision by the force of the flow.
inline bool dntMediumWatchForRocks()
    { return true; }

// when PCs travel a medium river, the DM rolls 1d6 for each mile traveled.
inline int dntMediumDropoffMileDice()
    { return 1; }

// the sides of the medium-flow 1d6 per-mile drop-off roll, pinned as dice +
// sides consts per the R508 convention.
inline int dntMediumDropoffMileSides()
    { return 6; }

// on a 5 or 6 of the medium per-mile roll, a drop-off is encountered
// somewhere in that mile.
inline int dntMediumDropoffTriggerLow()
    { return 5; }

// the high end of the medium drop-off trigger: on a 5 or 6.
inline int dntMediumDropoffTriggerHigh()
    { return 6; }

// a medium-flow drop-off is 1d3 feet high.
inline int dntMediumDropoffFtDice()
    { return 1; }

// the sides of the medium drop-off 1d3-feet roll.
inline int dntMediumDropoffFtSides()
    { return 3; }

// ---- the rapids band ----

// rapid flowing water is more commonly called rapids (flow rate = 6-12).
inline int dntRapidMinFlowRate()
    { return 6; }

// the top of the rapids band on the 0-40 flow rate scale: 6-12.
inline int dntRapidMaxFlowRate()
    { return 12; }

// water flowing through rapids travels more than 120 feet per round.
inline int dntRapidFtPerRoundLow()
    { return 120; }

// rapids sometimes move as much as 240 feet per round.
inline int dntRapidFtPerRoundHigh()
    { return 240; }

// the descent of a rapid stream bed ranges from 30 feet to as much as 200
// feet over the course of a mile.
inline int dntRapidDescentLowFtPerMile()
    { return 30; }

// the steep end of the rapids descent band: 30 to 200 feet per mile.
inline int dntRapidDescentHighFtPerMile()
    { return 200; }

// the sound of rapids can be heard by characters and creatures within 1,000
// feet.
inline int dntRapidsAudibleFt()
    { return 1000; }

// traveling upstream along rapids is impossible unless powerful magic is
// employed; traveling downstream is dangerous, but possible.
inline bool dntRapidsUpstreamImpossible()
    { return true; }

// certain boats such as kayaks are more suited to rapids than most standard
// boats; characters who boat down a rapid stream without boating proficiency
// will find themselves in great danger.
inline bool dntRapidsNeedBoatingProficiency()
    { return true; }

// for each mile along a rapid stream the DM rolls 1d6.
inline int dntRapidDropoffMileDice()
    { return 1; }

// the sides of the rapids 1d6 per-mile roll.
inline int dntRapidDropoffMileSides()
    { return 6; }

// a result of 6 on the rapids per-mile roll means that no significant
// drop-offs occur during the mile; a result of 1-5 is the number of drop-offs
// encountered.
inline int dntRapidDropoffNoneRoll()
    { return 6; }

// each rapid drop-off falls 1d4 feet.
inline int dntRapidDropoffFtDice()
    { return 1; }

// the sides of the rapids drop-off 1d4-feet roll.
inline int dntRapidDropoffFtSides()
    { return 4; }

// ---- the cascade and waterfall bands ----

// cascades are steeply dropping portions of a river (flow rate = 12-30), much
// like a stairway with water running down it.
inline int dntCascadeMinFlowRate()
    { return 12; }

// the top of the cascade band on the flow rate scale: 12-30.
inline int dntCascadeMaxFlowRate()
    { return 30; }

// the thundering roar of a cascade is usually audible at least a mile away
// from the river.
inline int dntCascadeAudibleMiles()
    { return 1; }

// water spilling down a cascade travels at anywhere from 240 to 600 feet per
// round.
inline int dntCascadeFtPerRoundLow()
    { return 240; }

// the fast end of the cascade band: 240 to 600 feet per round.
inline int dntCascadeFtPerRoundHigh()
    { return 600; }

// a cascade waterway descends at a slope of at least 200 feet, and perhaps as
// much as 1,000 feet, in a mile.
inline int dntCascadeSlopeLowFtPerMile()
    { return 200; }

// the steep end of the cascade slope band: 200 to 1,000 feet per mile.
inline int dntCascadeSlopeHighFtPerMile()
    { return 1000; }

// traveling upstream against the force of a cascade is impossible; traveling
// downstream might be possible for a lucky character with boating proficiency
// in a kayak.
inline bool dntCascadeUpstreamImpossible()
    { return true; }

// if PCs travel down a cascade, the DM rolls 3d6 for each mile traveled; the
// result is the number of drop-offs in that mile.
inline int dntCascadeDropoffMileDice()
    { return 3; }

// the sides of the cascade 3d6 per-mile roll.
inline int dntCascadeDropoffMileSides()
    { return 6; }

// each cascade drop-off is 1d8 feet high.
inline int dntCascadeDropoffFtDice()
    { return 1; }

// the sides of the cascade drop-off 1d8-feet roll.
inline int dntCascadeDropoffFtSides()
    { return 8; }

// waterfalls represent flowing water at its fastest and most powerful (flow
// rate = 30-40).
inline int dntWaterfallMinFlowRate()
    { return 30; }

// the top of the waterfall band: those rated 40 tumble down as waterfalls.
inline int dntWaterfallMaxFlowRate()
    { return 40; }

// a long stretch of waterfalls, with rapids or cascades between them, is
// still considered a waterfall.
inline bool dntWaterfallStretchesWithRapids()
    { return true; }

// the speed of water plummeting over a fall is at least 600 feet per round;
// the exact speed depends on the number of steps in the fall.
inline int dntWaterfallMinFtPerRound()
    { return 600; }

// anywhere the water plunges at a slope of more than 1,000 feet per mile is
// considered a waterfall.
inline int dntWaterfallSlopeFtPerMile()
    { return 1000; }

// the nature of a waterfall makes it impossible to control a boat traveling
// over the fall; survival is more a matter of luck than skill.
inline bool dntWaterfallBoatUncontrollable()
    { return true; }

// ---- the damming rules ----

// a dammed underground waterway immediately begins to back up and flood
// behind the dam; the DM must rely on accurate three-dimensional maps (see
// DSG page 114), as the water may be diverted into other parts of the
// setting, filling rooms and making its way through corridors and down
// stairways.
inline bool dntDamBacksUpFloods()
    { return true; }

// in an average waterway, water held back by a dam fills a 10-foot cubic area
// (10 ft x 10 ft x 10 ft = 1,000 cubic feet) times the flow rate per turn.
inline int dntDamCuFtPerFlowPerTurn()
    { return 1000; }

// the backup figure is doubled for a wide waterway and quartered for a narrow
// one.
inline bool dntDamDoubleWideQuarterNarrow()
    { return true; }

// as soon as the water level reaches a height that allows it to flow through
// another channel, it changes course to follow the path of least resistance.
inline bool dntDamDivertsLeastResistance()
    { return true; }

// a single worker can construct 1d6 points of dam per turn.
inline int dntDamWorkerDice()
    { return 1; }

// the sides of the worker 1d6 dam-points-per-turn roll.
inline int dntDamWorkerSides()
    { return 6; }

// the current destroys a number of dam points equal to the water rate of flow
// each turn, so several characters must work together to dam rapid streams.
inline bool dntDamCurrentDestroysFlow()
    { return true; }

// the Construction Point Value of a completed dam on a narrow waterway is 50
// points (per the DMG pages 109-110 CPV seam).
inline int dntDamCpvNarrow()
    { return 50; }

// a completed dam on an average waterway equals 150 points.
inline int dntDamCpvAverage()
    { return 150; }

// a completed dam on a wide waterway equals 250 points.
inline int dntDamCpvWide()
    { return 250; }

// once a dam is completed, water will not destroy it unless something
// specifically weakens the dam or increases the water pressure.
inline bool dntDamCompletedStable()
    { return true; }

// once a dam begins to leak, water destroys a number of points equal to half
// the rate of flow per turn until the dam is washed away or repaired.
inline int dntDamLeakDivisor()
    { return 2; }

// ---- the water temperature rules ----

// unless some external source of heat contributes, underground water is
// almost universally cold; it rarely freezes underground, but its temperature
// is numbing to any characters who get soaked in it.
inline bool dntUndergroundWaterUniversallyCold()
    { return true; }

// water flowing directly from a warm above-ground source retains this warmth
// for 1d4 miles.
inline int dntWarmthMilesDice()
    { return 1; }

// the sides of the 1d4-miles warmth-retention roll.
inline int dntWarmthMilesSides()
    { return 4; }

// underground water can occasionally be warmed by geothermal heat sources -
// the same energy that gives rise to geysers and volcanoes; depending on
// proximity the water might be only slightly warmer, or hot enough to scald a
// character to death very quickly.
inline bool dntGeothermalWarming()
    { return true; }

// characters immersed in water at or near boiling temperature suffer 6d6 of
// burn damage per round spent in the water.
inline int dntBoilingBurnDice()
    { return 6; }

// the sides of the 6d6 near-boiling burn roll per round.
inline int dntBoilingBurnSides()
    { return 6; }

// no saving throw is allowed against the near-boiling 6d6 burn damage per
// round, though magical protection against heat or fire gains a -2 per die
// (minimum 1 point per die).
inline bool dntBoilingNoSave()
    { return true; }

// characters with magical protection against heat or fire gain a -2 per die
// of damage (pinned as a positive magnitude with the minus in the name and
// comment).
inline int dntHeatProtectPerDie()
    { return 2; }

// the -2 per die carries a minimum of 1 point per die.
inline int dntHeatProtectMinPerDie()
    { return 1; }

// characters only partially immersed in near-boiling water suffer partial
// damage: the DM establishes a proportional number of d6 based on what
// proportion of their bodies is exposed.
inline bool dntBoilingPartialProportional()
    { return true; }

// water that is very hot, but not near boiling temperature, inflicts 1d6
// points of damage to characters immersed in it.
inline int dntVeryHotBurnDice()
    { return 1; }

// the sides of the very-hot 1d6 burn roll.
inline int dntVeryHotBurnSides()
    { return 6; }

// against the very-hot (not near-boiling) 1d6 damage, characters only
// partially exposed or with any magical protection against fire and heat
// attacks are not affected.
inline bool dntVeryHotProtectedUnaffected()
    { return true; }

// if the water is no warmer than very hot bath water, characters suffer no
// ill effects from the heat.
inline bool dntBathWarmNoIllEffects()
    { return true; }

// ---- the access rules ----

// the streams and lakes of the Underdark can occasionally be embarked upon
// directly from the surface: a meandering stream may flow into a cave and
// disappear, or the far side of a mountain lake may include a cave high
// enough and deep enough for a boat to enter.
inline bool dntDirectSurfaceEmbarkOccasional()
    { return true; }

// more often, water drops from the surface in cascades and waterfalls, or
// trickles through a tunnel too narrow to follow; characters must enter the
// underearth through a dungeon or cavern and find a suitable place to join
// the river below.
inline bool dntUsuallyEnterViaDungeon()
    { return true; }

// in rare cases an underground river returns to the surface; if the water is
// suitably placid, such an outlet can provide access to an underground
// waterway, but entering at a water outlet necessarily entails the problems
// of traveling upstream along the water.
inline bool dntOutletRequiresUpstream()
    { return true; }

// underground lakes and seas are generally not surrounded by sandy beaches -
// without waves there is no force to grind the stone into sand; such bodies
// are more likely surrounded by sheer cliffs or jagged boulders, though
// inhabited portions may hold creature-built docks or wharves, possibly with
// a few boats lying around.
inline bool dntLakeShoresCliffsNotSand()
    { return true; }

// streams and rivers are much more likely to be bordered by smooth sand
// beaches that allow easy access to the water.
inline bool dntStreamShoresSandBeaches()
    { return true; }

}   // namespace rules
