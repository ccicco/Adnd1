// =========================================================================================
// Adnd1 - rules/dsgarea2.h
// THE DSG DEEPEARTH AREAS 4-5, R535: printed pp. 79-81 (pdf 80-82) - the
// individual area key continues with the middle pair of areas: Area 4
// Cathedral Caverns (the four great limestone caverns ranging 1d6 miles in
// length with ceilings up to 100 ft and a few 80- and 90-ft-wide spots, the
// stalactite-stalagmite-drapery abundance giving the ornately decorated
// cathedral appearance; the west tunnel rising to the surface and the ancient
// excavated connecting tunnel to the vast many-leveled dungeon below the
// surface city, its single Deepearth route concealed by a secret door; the
// 400-ft sinkhole from the forest above with the bandit escape route, the
// cave-in rubble and the secret-door notice; the clean cold water of the
// shallow narrow streams, five feet wide and one foot deep; the isolated
// pocket of hostile drow - about 25 fighters and an equal number of
// noncombatants, poor and far from their homeland's potent magic; the
// piercer-lined cathedral ceiling with the drow's faint rim trail; the
// jellies and oozes, the rats-giant rats-wererats of the city tunnel, and the
// otyugh and neo-otyugh scavengers; the 12-HD hydra fallen down the sinkhole,
// starving and nearly berserk; the diamond-vein cul-de-sac settled by jewelry
// proficiency; the scarce food with the drow stockpiling; the 500-ft drow
// approach tunnel under 10 ft wide - pit traps, 6d6 falling blocks,
// shriekers, an illusionary dead end, the steep last 100 ft with oil pots and
// archer niches; and the geothermal mud pool with its gold dust - 20 gp per
// coated character, more than 10,000 gp in all, 20 ft wide and 5 ft deep),
// and Area 5 Enclosed Caverns (the air-filled natural caves whose only
// entrance and exit are completely water-choked, fed by the subterranean
// river from the south-shore cave of the great lake; the 3-to-4 meander with
// the upstream sandy beach; the rapids a mile before the area and the cascade
// with no airspace that sweeps masts and tillers 80% of the time before the
// two-round tumble into the quiet pool of the vast entry cavern; the eight
// connected caves, each under a mile, joined by tunnels less than two feet in
// diameter; the far-end chute - the water-filled plunge of 50 ft, then less
// than a foot of clearance for about six miles to the long waterfall of Area
// 14; the pathetic mad castaways of a dozen expeditions, about 20 mostly men
// with their green-glowing fungi light; the kuo-toa outpost of 6d6 fish-men
// guarding the chute with their monthly sweeps, their downstream slave
// escorts and their insane wanderers; the fish, rats, beavers, weasels,
// rabbits and the occasional freshwater scrag; the nereid of the deep
// riverside-spring pool; the foam-assured air, the limited fungi, the
// plentiful netted fish; the 1%-per-hour river-bottom finds - plate mail +2,
// shield +2, shield +3, longsword +1, spear +3; the surface net stopping
// several feet short of the bottom; and the outpost's three vertical levels,
// secret doors and elaborate food-storage chamber)
// census 458 -> 459.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~10084-10295) with the pdf Acrobat-Capture layer as the second read (idx
// 368-372 = the printed pp. 79-81 windows); the compiled-tables appendix has
// no reprint of this prose. A CLEAN-READ ROUND: both machine reads agree on
// every load-bearing number - the four 1d6-mile caverns, the 100-ft ceilings,
// the 80/90-ft widths, the 400-ft sinkhole, the 5-ft-wide 1-ft-deep streams,
// the 25 drow fighters, the 12-HD hydra, the 500-ft tunnel under 10 ft wide
// with its 6d6 blocks and 100-ft climb, the mud pool's 20/5-ft size with the
// 20-gp and 10,000-gp gold, the 3-to-4 river rate, the one-mile rapids, the
// 80% sweep, the two cascade rounds, the eight sub-mile caves with the 2-ft
// tunnels, the 50-ft water-filled plunge and the six low-clearance miles, the
// 20 castaways, the 6d6 kuo-toa, the 1% finds and the outpost's three levels;
// the only garbles are non-load-bearing (the djvu 'GPPER' header noise, its
// Cyrillic glyph substitutions, and the Capture 'ievel' and 'kua-toa'
// spellings). SEAMS: the R518 water travel (the river flow rates and the
// cascade), the Monster Manual denizens (the drow, piercers, hydra, otyughs,
// kuo-toa, nereid, scrag and the rest), the R503 re-grain. A ZERO-FLIP ROUND:
// the pp. 75-98 Deepearth child remains open until the setting lands in full
// (the R527/R533/R534 precedent - the gap report is NOT in the git add).
// Nothing auto-credits.
//
// A procedural-plus-prose round: no tables pin. The numbers pin as consts per
// the R508 convention - the cavern dimensions and stream sizes, the sinkhole
// depth, the drow lair and tunnel numbers, the mud pool's gold, the river
// rates and cascade odds, the cave-chain and chute numbers, and the castaway,
// kuo-toa and outpost counts, with the 1d6/6d6/6d6 dice pinned as
// count-and-sides const pairs. The geography, denizens, resources and
// unique-features prose pins as bools for both areas. The R518/MM/R503 seams
// are noted; the Deepearth child stays open; nothing auto-credits.
//
namespace rules {

// ---- the Area 4 Cathedral Caverns section ----

// the region is made up of several very large limestone caves; four caverns
// run the length of the area, connected by narrower passages with a number of
// side passages.
inline int dnacCavernCount()
    { return 4; }

// each of the four great caverns ranges in length from 1d6 miles (the die
// count).
inline int dnacCavernLenDice()
    { return 1; }

// each of the four great caverns ranges in length from 1d6 miles (the die
// sides).
inline int dnacCavernLenSides()
    { return 6; }

// these are living caves; the presence of stalactites, stalagmites and
// draperies is so overwhelming in the huge central cavern that the overall
// appearance is similar to an ornately decorated cathedral.
inline bool dnacCavernFormations()
    { return true; }

// each large cavern has a ceiling that ranges up to 100 feet high in places.
inline int dnacCeilingMaxFt()
    { return 100; }

// each cavern has a few locations where it is 80 or 90 feet wide (the low
// bound).
inline int dnacWideLowFt()
    { return 80; }

// each cavern has a few locations where it is 80 or 90 feet wide (the high
// bound).
inline int dnacWideHighFt()
    { return 90; }

// to the west a narrow tunnel gradually rises to the level of the surface,
// and an ancient excavation drilled a connecting tunnel to the vast,
// many-leveled dungeon below the surface city - only one route, concealed by
// a secret door, provides access to Deepearth.
inline bool dnacSurfaceLinks()
    { return true; }

// a side passage off the central cavern is pierced by a sinkhole from the
// surface that plunges 400 feet to the cavern floor, used as an escape route
// by bandits living in the forest above.
inline int dnacSinkholeDepthFt()
    { return 400; }

// the sinkhole side cavern is partially closed off from the main cave by the
// rubble of a cave-in; characters only notice the passage if they
// successfully discover a secret door, and a few hours of excavation clears a
// path large enough for humans.
inline bool dnacSinkholeBandits()
    { return true; }

// the water flowing through these caverns is clean and cold; the streams tend
// to be about five feet wide.
inline int dnacStreamWidthFt()
    { return 5; }

// most of the water flows down shallow, narrow stream beds about one foot
// deep, with a few still, deep pools scattered about.
inline int dnacStreamDepthFt()
    { return 1; }

// the denizens depend less on surface access than do the residents of Area 3
// - only the proliferation of all types of bats indicates the connection
// exists.
inline bool dnacBatsOnly()
    { return true; }

// an isolated pocket of drow lairs in one side cavern; the band numbers about
// 25 fighters and an equal number of noncombatants.
inline int dnacDrowFighters()
    { return 25; }

// the isolated drow pocket is an evil and suspicious bunch even by drow
// standards, reacts hostilely to any intrusion, knows every passageway and
// hiding place in its area, and - so far from its homeland - has none of the
// potent magical items of its kind; it is very poor and holds little to
// interest a surface thief.
inline bool dnacDrowLair()
    { return true; }

// the ceiling of the central cathedral chamber is liberally lined with
// piercers that drop on unsuspecting explorers; the drow have developed a
// faint trail around the outer rim to avoid them, not apparent unless
// actively sought.
inline bool dnacPiercersTrail()
    { return true; }

// a number of jellies and oozes survive on the leavings of the other
// denizens; few rats are found here, but rats, giant rats and even wererats
// may be encountered in the tunnel leading to the city, and an assortment of
// otyugh and neo-otyugh perform scavenging duties.
inline bool dnacScavengerMix()
    { return true; }

// a 12 Hit Dice hydra fell down the sinkhole some years back, survived,
// forced its way into the central cavern, and has somehow managed to survive
// there - constantly hungry and nearly berserk with frustration.
inline int dnacHydraHD()
    { return 12; }

// one of the side caverns leads to a small cul-de-sac containing a vein of
// shiny stones; a character can gather a large number of the rough, uncut
// rocks, and one with jewelry proficiency can identify them as diamonds.
inline bool dnacDiamondVein()
    { return true; }

// air and water are plentiful, but there is not enough subterranean plant
// food for all the inhabitants to eat well; the drow manage by stockpiling
// while the other creatures subsist off each other - the hydra eats
// scavengers and anything else it can catch but is slowly starving to death.
inline bool dnacFoodScarce()
    { return true; }

// the only approach to the drow cavern is through a 500-foot-long tunnel.
inline int dnacTunnelLenFt()
    { return 500; }

// the drow approach tunnel is less than 10 feet wide along its entire length.
inline int dnacTunnelMaxWidthFt()
    { return 10; }

// precariously balanced blocks of stone fall on trespassers who trip
// camouflaged releases, dealing 6d6 damage (the die count).
inline int dnacTrapDice()
    { return 6; }

// precariously balanced blocks of stone fall on trespassers who trip
// camouflaged releases, dealing 6d6 damage (the die sides).
inline int dnacTrapSides()
    { return 6; }

// the last 100 feet of the drow approach tunnel climb steeply, where the drow
// have pots of oil ready to pour down upon intruders.
inline int dnacTunnelClimbFt()
    { return 100; }

// the drow cavern is protected by an elaborate series of traps and alarms:
// pit traps, falling stone blocks (6d6 damage), batches of shriekers, and an
// illusionary dead end to the tunnel, with archer niches prepared along the
// steep final climb.
inline bool dnacDrowTrapTunnel()
    { return true; }

// a corner of one of the small side caverns holds a bubbling pool of thick
// geothermally heated mud, about 20 feet wide.
inline int dnacMudPoolWidthFt()
    { return 20; }

// the geothermal mud pool is about five feet deep, very warm but not
// dangerously hot.
inline int dnacMudPoolDepthFt()
    { return 5; }

// the mud contains significant quantities of gold dust brought by ancient
// erosion; a character coated with the mud collects about 20 gp worth of gold
// when it dries and crumbles off.
inline int dnacMudGoldPerCharGp()
    { return 20; }

// the whole mud pool contains more than 10,000 gp worth of gold, but
// excavating and drying the entire pool would take a major commitment of time
// and effort.
inline int dnacMudGoldTotalGp()
    { return 10000; }

// the geothermal mud pool bubbles and gurgles in a corner of one small side
// cavern; the gold dust within becomes apparent only if the mud is dried and
// the dust blown away.
inline bool dnacMudPoolGold()
    { return true; }

// ---- the Area 5 Enclosed Caverns section ----

// this area of natural caverns is filled with air, but the only entrance and
// exit are completely water-choked; the subterranean river flows in from the
// cave on the south shore of the great lake on the surface.
inline bool dnacAirWaterChoked()
    { return true; }

// the subterranean river meanders along at a flow rate of 3 to 4 (the low
// bound, per the p. 78 area key's miles-per-turn scale).
inline int dnacRiverFlowLow()
    { return 3; }

// the subterranean river meanders along at a flow rate of 3 to 4 (the high
// bound).
inline int dnacRiverFlowHigh()
    { return 4; }

// at the point where the side tunnel joins the river, just upstream from Area
// 5, the river widens and slows and a wide sandy beach allows easy beaching
// of boats.
inline bool dnacBeachApproach()
    { return true; }

// one mile before reaching Area 5 the river picks up speed and tumbles along
// as a rapids.
inline int dnacRapidsMiles()
    { return 1; }

// at the cascade the water pours through a hole just wide enough for itself
// with no airspace, so boats capsize and masts and tillers are swept away 80%
// of the time.
inline int dnacSweepChancePct()
    { return 80; }

// after two rounds of cascade churn the river empties into a quiet pool in a
// vast cavern.
inline int dnacCascadeRounds()
    { return 2; }

// the entry cavern connects to eight other caves, each less than a mile long.
inline int dnacCaveCount()
    { return 8; }

// each of the eight connected caves is less than a mile long.
inline int dnacCaveMaxMiles()
    { return 1; }

// the connections between caves pass through tunnels less than two feet in
// diameter.
inline int dnacTunnelDiaFt()
    { return 2; }

// all of the eight connected caves of Area 5 are of natural origin, joined by
// the narrow inter-cave tunnels.
inline bool dnacEightCaves()
    { return true; }

// at the far end the river plunges through a water-filled opening and
// continues that way for 50 feet before the tunnel opens slightly.
inline int dnacWaterFilledFt()
    { return 50; }

// past the 50-foot water-filled stretch the river flows along less than one
// foot from the ceiling for about six miles before plunging over a long
// waterfall (see Area 14).
inline int dnacLowClearanceMiles()
    { return 6; }

// the pathetic band of human castaways - the survivors of a dozen previous
// expeditions whose boats were wrecked - numbers about 20, mostly men.
inline int dnacCastawaysCount()
    { return 20; }

// the mad castaways live off the few fungi plants and an occasional fish,
// keep a ragged collection of weapons, are relatively harmless unless
// threatened, and represent all varieties of character classes with
// experience levels tailored to balance the PCs; several who tried to float
// out the far end promised to return if safe passage was found - none
// returned.
inline bool dnacCastaways()
    { return true; }

// some of the fungi glow with a greenish phosphorescence and serve as feeble
// light sources for the castaways.
inline bool dnacGlowFungi()
    { return true; }

// the small kuo-toa outpost in the caves contains 6d6 of the fish-men (the
// die count).
inline int dnacKuoDice()
    { return 6; }

// the small kuo-toa outpost in the caves contains 6d6 of the fish-men (the
// die sides).
inline int dnacKuoSides()
    { return 6; }

// the dreaded nemesis of the humans is a small outpost of kuo-toa who can
// freely travel underwater; their purpose is to guard the chute where the
// river leaves the cavern, prevent unwelcome visitors from journeying
// downstream, and carry warning if a force is too large to stop.
inline bool dnacKuoToaOutpost()
    { return true; }

// about once a month the kuo-toa sweep through the caverns in search of food
// or slaves; captured humans are bound and sent downstream with a heavy
// escort, and many do not survive the trip; often one of the lonely outpost's
// kuo-toa goes insane and wanders off into the caves alone.
inline bool dnacMonthlySweeps()
    { return true; }

// unintelligent denizens include a variety of fish, rats, beavers, weasels
// and rabbits; occasionally a freshwater scrag follows the stream into the
// cavern.
inline bool dnacRiverFauna()
    { return true; }

// a deep pool located at a riverside spring about halfway through the cavern
// is the lair of a nereid.
inline bool dnacNereidPool()
    { return true; }

// the foaming water passing through the caverns assures a steady supply of
// fresh air; plant food is limited to a few varieties of fungi, but fish are
// plentiful for those with nets, and occasionally animals are swept down the
// river as well.
inline bool dnacFoamResources()
    { return true; }

// a character searching the river bottom has a 1% chance per hour of
// discovering one of the sunken magic items.
inline int dnacFindChancePct()
    { return 1; }

// many valuables line the river bottom, spilled from capsized boats - a large
// number of coins and all sorts of mundane armor and weaponry - including
// plate mail +2, shield +2, shield +3, longsword +1, and spear +3.
inline bool dnacRiverFinds()
    { return true; }

// the kuo-toa have attempted to block off the downstream end of the tunnel
// with a large net that stretches across the surface of the river but stops
// several feet short of the bottom.
inline bool dnacKuoNet()
    { return true; }

// the kuo-toa have excavated a rather involved series of rooms for their
// outpost, including three vertical levels, secret doors, and an elaborate
// food-storage chamber.
inline int dnacOutpostLevels()
    { return 3; }

}   // namespace rules
