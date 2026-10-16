// =========================================================================================
// Adnd1 - rules/dsgoverview.h
// The DSG OVERVIEW OF THE UNDERDARK, R503: the arc's first content round -
// the three natural cave types with the living/dead split, the geothermal
// ladder, the unnatural locale taxonomy and the hazards of the underearth;
// the DM-section boxes re-grained from the DM's own table of contents.
// census 427 -> 428.
//
// The DSG Overview of the Underdark, printed pp. 7-11 (pdf 8-12), read from
// the tesseract extraction on the r503-extraction branch (d8_full through
// d12_full with the tsv confidence tables and the 300-dpi page images; pdf 9
// is the cave-formations illustration plate). The pdf-page offset is printed
// + 1, the same as the WSG. Values pinned: the three-cave taxonomy, the
// living/dead cave split, the formations list, the 1,800 F lava, the 10-foot
// shoring interval, the realms depth rule and the five hazard families.
//
// THE SETTLE: census 427 -> 428; the gap report 0/151 -> 5 closed / 150 open
// (the overview parent, its natural/unnatural/hazards children and the DM TOC
// close; the DM section re-grained; the perspective-maps box opened).
//
namespace rules {

// ---- the chapter opener ----

// the overview chapter starts at printed p. 7.
inline int dovPrintedLo()
    { return 7; }

// the overview chapter ends at printed p. 11.
inline int dovPrintedHi()
    { return 11; }

// the overview chapter starts at pdf page 8 (the offset: pdf = printed + 1).
inline int dovPdfLo()
    { return 8; }

// the overview chapter ends at pdf page 12.
inline int dovPdfHi()
    { return 12; }

// three types of natural caves are commonly encountered: limestone, sea and
// lava.
inline int dovCaveTypeCount()
    { return 3; }

// ---- the geothermal side ----

// molten lava has a temperature of approximately 1,800 degrees Fahrenheit and
// quickly kills any non-fire-resistant creature forced into contact with it.
inline int dovLavaTempF()
    { return 1800; }

// geothermal heat can be encountered in deep caves of any kind but is
// particularly likely in a lava cave, since lava itself is a carrier of
// geothermal heat.
inline bool dovGeothermalInDeepCaves()
    { return true; }

// the glowing crimson flow of molten lava carries heat from the deepest
// reaches and quickly kills any non-fire-resistant creature forced into
// contact with it.
inline bool dovLavaKillsOnContact()
    { return true; }

// even where lava has cooled to a solid crust it is still blisteringly hot,
// and a character venturing onto it risks breaking through into the infernal
// heat below.
inline bool dovLavaCrustBreakRisk()
    { return true; }

// steam can scald or even kill a creature caught in its intense blast; sudden
// vaporization in high-geothermal areas creates high pressures, and blasts
// can erupt far from the actual heat source.
inline bool dovSteamScalds()
    { return true; }

// warm or hot water, a more tolerable form of geothermal heat, ranges from
// lukewarm to boiling depending on the proximity and intensity of the heat
// source.
inline bool dovHotWaterRange()
    { return true; }

// warm or hot air rising through subterranean passages is often an explorer's
// first warning of approaching geothermal heat.
inline bool dovWarmAirFirstWarning()
    { return true; }

// ---- the hazards of the underearth ----

// cave-ins, a constant problem under tons of earth and rock, are triggered by
// erosion or by sudden shocks such as earthquakes or explosions; those
// underneath suffer falling damage and are often pinned or trapped with
// little air.
inline bool dovCaveinTriggers()
    { return true; }

// dungeons are protected against cave-ins by shoring passages with timbers or
// stone arches, caverns lack such engineered protection, and realms are too
// vast for it - and so rarely subject to cave-ins, though a realm cave-in
// rivals the worst hurricane or tidal wave.
inline bool dovCaveinProtectionSplit()
    { return true; }

// underground flood water has little chance to spread out and disperse;
// corridors may fill with water, making drowning a virtual certainty for any
// air-breathing creature caught there.
inline bool dovFloodNoDispersion()
    { return true; }

// fires threaten underground dwellings in a double sense: they consume
// combustible objects in their path and also use up the precious oxygen,
// which exists in finite supply.
inline bool dovFireDoubleThreat()
    { return true; }

// wood is not a common building material underground - the difficulty of
// transporting it in and its tendency to rot in damp conditions discourage
// its use - though shoring up a corridor is much easier with wood than with
// stone.
inline bool dovWoodUncommonUnderground()
    { return true; }

// poisonous gases, whether natural (like the sulfur dioxide of volcanic
// areas), magical or manufactured, menace all oxygen-breathers, and their use
// as a weapon of war is greatly enhanced in the constricted underearth.
inline bool dovPoisonGasConfined()
    { return true; }

// volcanoes are a major cause of subterranean fires and poison-gas emissions;
// often occurring with earthquakes, a volcanic burst can fill inhabited
// corridors with lava or steam and close off escape passages or popular
// transportation routes.
inline bool dovVolcanoDamage()
    { return true; }

// ---- the lava caves and the quakes and faults ----

// a lava cave is created when the crust of a flowing lava surface hardens
// while the molten lava beneath continues to flow away, leaving an air-filled
// space that may reach considerable size.
inline bool dovLavaCrustOrigin()
    { return true; }

// lava caves are commonly found in areas of volcanic activity and do not
// contain the features typical of limestone caves.
inline bool dovLavaCaveVolcanic()
    { return true; }

// unless in a region of heavy rainfall or at a very low elevation, lava caves
// may well be completely dry.
inline bool dovLavaCaveDry()
    { return true; }

// a great many lava caves have no exits to the outside world; their existence
// can only be discovered by chance excavation or by breaking through a thin
// crust.
inline bool dovLavaCaveHiddenExits()
    { return true; }

// earthquake and rockslide chambers, tenuously supported by accumulated
// rubble, resemble caves but are not true caves; they make good overnight
// shelters and lairs for hostile animals or monsters.
inline bool dovQuakeChamberNotTrueCave()
    { return true; }

// geological faulting creates cavities when a large shelf of rock moves and
// the neighboring rock stays stationary; such caverns are often completely
// enclosed but may be very large.
inline bool dovFaultCavityEnclosed()
    { return true; }

// ---- the limestone cave ----

// limestone caves are by far the most common type, found mostly where the
// bedrock is a great shelf of limestone.
inline bool dovLimestoneMostCommon()
    { return true; }

// dolomite and marble terrain can also serve as an environment for the
// creation of a limestone cave.
inline bool dovLimestoneCarbonateBedrock()
    { return true; }

// a limestone cave is created by the erosive and corrosive action of water
// seeping through rock; rainwater, a dilute carbonic acid from absorbed
// carbon dioxide, quickly eats away limestone.
inline bool dovLimestoneAcidErosion()
    { return true; }

// a drop in the water table leaves formerly underwater passages dry and full
// of air; droughts, floods or terrain movement can shift the flow.
inline bool dovWaterTableDrainsCave()
    { return true; }

// the inlets or outlets of the water that once flowed through a cave, often
// tortuously narrow or steep, are the most common entrances to limestone
// caves.
inline bool dovLimestoneWaterInletEntrances()
    { return true; }

// a cave grown too large may collapse its ceiling into a sinkhole dropping
// precipitously from the surface to the cave floor, usable as an entrance for
// characters willing to do a little rope work.
inline bool dovSinkholeEntrance()
    { return true; }

// stalactites hang from the ceiling and stalagmites grow upward from the
// floor, created by slow dripping water that evaporates and leaves mineral
// deposits; the color ranges from muddy brown to red to a rare pure
// crystalline white.
inline bool dovDripFormations()
    { return true; }

// the other cave features are draperies (ruffled-curtain stone sheets),
// flowstone (falling in tiers like flowing sludge) and rare, delicate gypsum
// flowers.
inline bool dovOtherFormations()
    { return true; }

// a cave subject to continuing water seepage is a living cave: its features
// grow, glisten and shine in light, and are very sturdy; the cave is
// generally clean and almost dust-free before creatures enter.
inline bool dovLivingCaveSeepage()
    { return true; }

// in a living cave all low areas not regularly swept by flowing water contain
// pools of sticky mud, which can be quite deep depending on drainage and
// shape.
inline bool dovLivingCaveMud()
    { return true; }

// in a dead cave the water no longer flows: the features do not glisten, grow
// very weak without constant humidity, become brittle and eventually crumble
// into dust.
inline bool dovDeadCaveBrittle()
    { return true; }

// a dead cave is much more likely to be choked with rubble than its living
// counterpart, and a layer of dust often covers everything.
inline bool dovDeadCaveRubble()
    { return true; }

// water found in a dead cave has generally been standing for centuries but is
// very rarely stagnant - the cold temperatures and lack of sunlight see to
// that.
inline bool dovDeadCaveWaterNotStagnant()
    { return true; }

// completely water-filled limestone caves generally have smooth, rubble-free
// passages, though very narrow or tightly winding ones may be difficult or
// impossible to travel.
inline bool dovWaterFilledSmooth()
    { return true; }

// ---- the sea and river caves ----

// sea caves are formed along current or former coastlines where the erosive
// action of pounding surf gradually wears an entrance into the bedrock.
inline bool dovSeaCaveSurfCarved()
    { return true; }

// sea caves are generally much smaller than limestone caves, since the waves
// disperse their energy quickly as they work inward.
inline bool dovSeaCaveSmaller()
    { return true; }

// sea caves are often partially water-filled; a changing water level can
// leave one completely submerged with a hidden mouth, or stranded in a cliff
// far above the surf or many miles inland.
inline bool dovSeaCaveWaterLevels()
    { return true; }

// sea caves have smooth floors, walls and ceilings with none of the
// spectacular limestone features, but their relatively easy access makes
// relics of long-past inhabitants more likely.
inline bool dovSeaCaveSmoothNoFeatures()
    { return true; }

// a river-bend abrasion cavern, eroded where water pounds the outer bank,
// resembles a sea cave in most respects.
inline bool dovRiverbendLikeSeaCave()
    { return true; }

// ---- the unnatural locales ----

// a dungeon excavated from dirt requires constant shoring up, at least at
// 10-foot intervals, to prevent cave-ins.
inline int dovDirtShoringIntervalFt()
    { return 10; }

// realms are rarely found within a mile of the surface and often extend far
// deeper.
inline int dovRealmShallowMi()
    { return 1; }

// dungeons are built by intelligent creatures, each to serve a particular
// purpose; some are constructed entirely from caves, others use caves as
// entrances or emergency exits only.
inline bool dovDungeonPurposeBuilt()
    { return true; }

// dungeon passages generally run within a few hundred feet of the surface;
// the deeper the dungeon, the harder the task of moving the excavated
// material out of the way.
inline bool dovDungeonShallowish()
    { return true; }

// dungeons are generally excavated from a soft rock such as sandstone or
// limestone - not as hard to excavate as granite, yet still a solid and
// sturdy support.
inline bool dovDungeonSoftRock()
    { return true; }

// some dungeons begin as buildings whose ruins are later buried by new
// buildings until the original layer seems well underground; encountered
// dungeons may be collapsing, newly excavated, or still under construction.
inline bool dovRuinsBecomeDungeons()
    { return true; }

// the most common dungeon purposes are jails, hiding places for treasures,
// lairs for bands of underground creatures, and positions of defense.
inline bool dovDungeonPurposes()
    { return true; }

// in a world where flying creatures are ever-present, dungeons can prove to
// be stronger fortresses than castles.
inline bool dovDungeonStrongerThanCastles()
    { return true; }

// fantasy-world mines are almost always tunnels or shafts; mines developed
// over centuries by diligent excavators such as dwarves or gnomes can become
// complicated three-dimensional networks stretching for dozens of miles.
inline bool dovMineTunnelNetworks()
    { return true; }

// active mines are usually well-guarded; inactive mines - closed for a
// depleted vein, a disaster or a conflict - often become the lairs of
// subterranean monsters.
inline bool dovMineActiveGuarded()
    { return true; }

// burrows are long tunnels generally no bigger in diameter than the creature
// that created them, often with a widened chamber at the deepest end; usually
// dug from dirt, but certain creatures such as umber hulks can burrow in
// solid stone.
inline bool dovBurrowCreatorSized()
    { return true; }

// realms are vast underground reaches of caverns, dungeons and lofty passages
// deep beneath the earth, regions of mystery to surface dwellers; the drow,
// deep gnomes, duergar, kuo-toa and derro live in reaches that never see the
// light of day.
inline bool dovRealmsDeepMystery()
    { return true; }

// realms contain cavern networks that might rival an entire nation in size
// and underground bodies of water as big as any outerworld sea, with islands
// just as surface seas have.
inline bool dovRealmNationScale()
    { return true; }

// certain vast realms are best described as wilderness where no cultures
// flourish, while other areas boast cities and fortresses worthy of the most
// advanced civilizations; horrific beasts rumored never to venture up to
// dungeon level are said to live there.
inline bool dovRealmWildernessToCities()
    { return true; }

}   // namespace rules
