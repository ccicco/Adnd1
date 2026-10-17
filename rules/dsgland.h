// =========================================================================================
// Adnd1 - rules/dsgland.h
// THE DSG LANDS OF DEEPEARTH OPENER, R533: printed p. 75 (pdf 76) - the
// Deepearth setting frame and the connecting-passage generation: the frame
// (the lands presented in detail as a campaign setting, the party gaining
// many levels without exploring the entirety; the alternative
// example-of-the-ecosystem view, use-and-discard, expandable, the realms
// occupying no more area than a moderately small nation; the numbered-area
// rough detail with the mapping-in-more-detail requirement; the page-114
// three-dimensional and geomorphic mapping referrals; and the
// hollow-earth-below note with the shafts from the lowest level), the
// connecting passages (all passable to human-sized characters, the vertical
// obstacles and water currents handled per area or generated randomly), the
// water passages (the rivers with their map-readable flow directions, the
// indicated waterfalls with map-scale drops, the rest navigable by boat with
// a skilled pilot and a little luck; the 1d6-x-10 width generation for the
// 10-60-foot spread, the width constant for one mile, the drift reroll - 2-5
// the same, 1 shrinking 10 feet or 5 at the 10-foot floor, 6 growing 10 feet
// even beyond 60; the 1d6 temperature - 1-5 very cold, the 6 heat check with
// the second d6 - 1 cool-slightly-warmer, 6 boiling hot, 2-5 proportional;
// only the boiling water unsafe for unprotected characters), the tunnels (the
// human-passable diameters, mostly natural caverns, the
// 10-percent-per-10-miles carved chance, the carved uniform 10-foot diameter
// and height with no sudden obstacles; the 33-percent-per-mile obstacle
// chance with the 10d10 cliffs, the 20d10-deep 4d10-wide chasms, the cave-in
// remnants and the water-quicksand-oil-tar pools, never closing the passage;
// the 3d20 cavern widths from 3 to 60 feet, constant for 1d20-x-100 feet of
// 100-2,000, the 1/3 change chance with the 3d20 reroll; and the
// unintelligent dwellers - scavengers, fungi, molds and lichens - the
// intelligent denizens only passing through, the banished renegade bands the
// exception), and the area details (the framework-not-full-detail rule, the
// 300-foot-square as 30-by-30 graph squares, and the DMG page-169 Random
// Dungeon Generation referral)
// census 456 -> 457.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~9584-9712) with the pdf Acrobat-Capture layer as the second read (idx 176
// = the printed p. 75 window); the compiled-tables appendix has no reprint of
// these procedures. A CLEAN-READ ROUND with one settled garble: the djvu
// cavern-width formula reads "(3420)" and the Capture layer reads "(3d20)" -
// settled as 3d20 by the Capture read, corroborated by the 3-60-foot range
// (the standing die-notation OCR class); every other load-bearing number
// agrees in both reads - the 1d6-x-10 widths, the drift bands, the
// temperature bands, the 10% carved chance, the 33% obstacle chance, the
// 10d10/20d10/4d10 obstacle dice, and the 1d20-x-100 constancy. The map pages
// (printed pp. 76-77) are graphics and pin nothing this round. SEAMS: the DMG
// Random Dungeon Generation (page 169), the R518 water travel (the
// navigable-by-boat rule), the R531 geography (the cavern-width generation),
// and the R503 re-grain. A ZERO-FLIP ROUND: the pp. 75-98 Deepearth child
// remains open until the setting lands in full (the R527 precedent - the gap
// report is NOT in the git add). Nothing auto-credits.
//
// A procedural round: the numbers pin as consts per the R508 convention - the
// waterway width generation (1d6 x 10, the 10-60 spread, the drift bands with
// the 5-foot floor), the temperature bands (1-5 cold, the 6 heat, the second
// d6 with the boiling 6), the tunnel carving (10%, the uniform 10 feet), the
// obstacles (33% per mile, the 10d10 cliffs, the 20d10-deep 4d10-wide
// chasms), the cavern widths (3d20, the 3-60 range, the 1d20-x-100 constancy,
// the 1/3 change chance), and the area-details example (the 300-foot square,
// the 30 squares, the DMG page 169). The frame and dwelling prose pin as
// bools. The DMG/R518/R531 seams are noted; the Deepearth child stays open;
// nothing auto-credits.
//
namespace rules {

// ---- the Deepearth frame section ----

// the lands of Deepearth are presented in detail as a setting for the
// underground campaign: the known varieties of intelligent life each claim a
// portion, and a party can gain many levels and overcome towering obstacles
// without exploring Deepearth in its entirety.
inline bool dndlSettingForCampaign()
    { return true; }

// alternatively regard the lands as an example of the underground ecosystem -
// utilize the aspects you like, disregard others, expand as you wish; as
// presented the realms occupy no more area than a moderately small nation,
// with potential for many such realms under the lands and seas.
inline bool dndlExampleToAdapt()
    { return true; }

// each numbered map area is presented in rough detail - the overall
// geography, the major inhabitants and resources, and any unique features -
// and each area must be mapped in more detail to run a campaign there.
inline bool dndlAreaKeyRoughDetail()
    { return true; }

// for three-dimensional mapping detail see page 114; geomorphic mapping is
// described there too and can be a great time-saver for PCs spending much
// time in the regions of Deepearth.
inline bool dndlThreeDimReferral()
    { return true; }

// if employing one of the hollow earth theories, the hollow-earth region lies
// below the areas depicted on the Deepearth map - create shafts or tunnels
// leading down from the lowest level.
inline bool dndlHollowBelowNote()
    { return true; }

// all connecting passages are large enough to be passable to human-sized
// characters; other factors such as vertical obstacles or water currents are
// handled in the area description or generated randomly by the DM.
inline bool dndlPassagesHumanSized()
    { return true; }

// ---- the water passages section ----

// the map waterways are rivers flowing through the dark reaches; the flow
// direction is easy to determine from the map, the rivers proceeding at a
// rapid pace or slower, sometimes almost stagnant.
inline bool dndlRiversFlowMap()
    { return true; }

// all vertical drops are indicated on the map - use the map scale to
// determine how far a waterfall drops; all other waterway sections are
// navigable by boat, assuming a skilled pilot and a little luck.
inline bool dndlWaterfallsIndicated()
    { return true; }

// the waterway width roll: 1d6 multiplied by 10.
inline int dndlWaterWidthDice()
    { return 1; }

// the waterway width die is a d6.
inline int dndlWaterWidthSides()
    { return 6; }

// the 1d6 result is multiplied by 10 feet.
inline int dndlWaterWidthMultFt()
    { return 10; }

// the narrowest waterway section is 10 feet wide.
inline int dndlWaterWidthMinFt()
    { return 10; }

// the widest standard waterway section is 60 feet.
inline int dndlWaterWidthMaxFt()
    { return 60; }

// a waterway width remains constant, with minor fluctuations, for one mile,
// after which the drift d6 is rolled again.
inline bool dndlWidthMileConst()
    { return true; }

// the width-drift roll: on a 2-5 the river remains at approximately the same
// width for the next mile.
inline int dndlWidthSameLow()
    { return 2; }

// the upper bound of the same-width drift band.
inline int dndlWidthSameHigh()
    { return 5; }

// a drift roll of 1 decreases the river width by 10 feet.
inline int dndlWidthShrinkFt()
    { return 10; }

// a river already only 10 feet wide decreases by 5 feet instead of 10 on a
// shrink roll.
inline int dndlWidthFloorFt()
    { return 5; }

// a drift roll of 6 expands the river width by 10 feet - even if this makes
// it wider than 60 feet.
inline int dndlWidthGrowFt()
    { return 10; }

// the temperature roll: on a 1-5 the river is very cold.
inline int dndlWaterColdHigh()
    { return 5; }

// on a 6 some heat is reaching the water, and a second d6 determines how
// warm.
inline int dndlWaterHeatRoll()
    { return 6; }

// the second roll: on a 1 the water is cool, but slightly warmer than normal.
inline int dndlWaterWarmLow()
    { return 1; }

// on a 6 the water is boiling hot - the only temperature unsafe for
// unprotected characters to swim or fall into.
inline int dndlWaterBoilRoll()
    { return 6; }

// the water in underground rivers is usually numbingly cold; only water that
// is boiling hot is unsafe for unprotected characters to swim or fall into,
// the 2-5 results meaning a degree of warmth proportional to the roll.
inline bool dndlWaterBoilOnlyDanger()
    { return true; }

// ---- the tunnels section ----

// the tunnels connecting the larger realms are all of sufficient diameter to
// allow a human to pass, and often much wider; in most cases they are natural
// caverns.
inline bool dndlTunnelsHumanPass()
    { return true; }

// about 1 out of every 10 miles of connecting tunnel has been carved by
// intelligent creatures.
inline int dndlCarvedChancePct()
    { return 10; }

// an excavated tunnel is a uniform 10-foot diameter and height, with no
// sudden obstacles such as cliffs or chasms.
inline int dndlCarvedDiaFt()
    { return 10; }

// a base 33% chance per mile that an obstacle lies in the path of the PCs
// exploring natural caverns.
inline int dndlObstaclePct()
    { return 33; }

// the obstacles: a cliff of 10d10 feet height, a chasm 20d10 feet deep and
// 4d10 feet wide, the remnants of a cave-in, or a large pool of water,
// quicksand, oil, or tar - the obstacle never completely closes off the
// passage.
inline bool dndlObstacleExamples()
    { return true; }

// the obstacle cliff height roll is 10d10 feet.
inline int dndlCliffDice()
    { return 10; }

// the cliff height die is a d10, ten of them.
inline int dndlCliffSides()
    { return 10; }

// the obstacle chasm depth roll is 20d10 feet.
inline int dndlChasmDepthDice()
    { return 20; }

// the chasm depth die is a d10, twenty of them.
inline int dndlChasmDepthSides()
    { return 10; }

// the chasm width roll is 4d10 feet.
inline int dndlChasmWidthDice()
    { return 4; }

// the chasm width die is a d10, four of them.
inline int dndlChasmWidthSides()
    { return 10; }

// the connecting-cavern width roll is 3d20 feet.
inline int dndlCavernDice()
    { return 3; }

// the cavern width die is a d20, three of them (the djvu 3420 garble settled
// by the Capture read).
inline int dndlCavernSides()
    { return 20; }

// the narrowest connecting cavern is 3 feet wide.
inline int dndlCavernMinFt()
    { return 3; }

// the widest connecting cavern is 60 feet.
inline int dndlCavernMaxFt()
    { return 60; }

// a cavern width remains constant for 1d20 x 100 feet.
inline int dndlConstDice()
    { return 1; }

// the constancy distance die is a d20.
inline int dndlConstSides()
    { return 20; }

// the constancy die is multiplied by 100 feet.
inline int dndlConstMultFt()
    { return 100; }

// the shortest constancy run is 100 feet.
inline int dndlConstMinFt()
    { return 100; }

// the longest constancy run is 2,000 feet.
inline int dndlConstMaxFt()
    { return 2000; }

// after the constancy run the cavern stands a 1/3 chance of changing width -
// reroll the 3d20 if indicated.
inline int dndlChangeChancePct()
    { return 33; }

// unintelligent monsters including scavengers occasionally live in the
// passages, as do fungi, molds and lichens - but intelligent creatures do not
// dwell here; encountered drow and other denizens are passing through, though
// renegade bands banished from their homelands might eke out an existence in
// the tunnels.
inline bool dndlUnintelligentDwellers()
    { return true; }

// ---- the area details section ----

// the map shows much too large an area to be fully detailed in the volume -
// an overall framework is given and the DM is free to fill in the necessary
// details.
inline bool dndlFrameworkNotFullDetail()
    { return true; }

// general information indicates the overall parameters: a 300-foot-square
// dungeon maps as a 30-square by 30-square graph section, not as one huge
// room 300 feet on a side.
inline bool dndlSquareMeansGraph()
    { return true; }

// the area-details example: a dungeon described as occupying a
// 300-foot-square area.
inline int dndlSquareFt()
    { return 300; }

// the 300-foot square means a 30-by-30 square section of graph paper, not one
// huge room.
inline int dndlSquaresPerSide()
    { return 30; }

// if there is no time to prepare a map, use the Random Dungeon Generation
// system in the DMG, page 169.
inline bool dndlDmgRandomDungeon()
    { return true; }

// the Random Dungeon Generation system referral: DMG page 169.
inline int dndlDmgPage()
    { return 169; }

}   // namespace rules
