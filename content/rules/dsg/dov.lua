-- dov: promoted from tools/spec_r503.json (the The DSG OVERVIEW OF THE UNDERDARK, R503: the arc's first content round - the three natural cave types with the living/dead split, the geothermal ladder, the unnatural locale taxonomy and the hazards of the underearth; the DM-section boxes re-grained from the DM's own table of contents.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 503,
  "prefix" = "dov",
  "banner" = {
      "title" = "The DSG OVERVIEW OF THE UNDERDARK, R503: the arc's first content round - the three natural cave types with the living/dead split, the geothermal ladder, the unnatural locale taxonomy and the hazards of the underearth; the DM-section boxes re-grained from the DM's own table of contents.",
      "provenance" = "The DSG Overview of the Underdark, printed pp. 7-11 (pdf 8-12), read from the tesseract extraction on the r503-extraction branch (d8_full through d12_full with the tsv confidence tables and the 300-dpi page images; pdf 9 is the cave-formations illustration plate). The pdf-page offset is printed + 1, the same as the WSG. Values pinned: the three-cave taxonomy, the living/dead cave split, the formations list, the 1,800 F lava, the 10-foot shoring interval, the realms depth rule and the five hazard families.",
      "sentinel" = "THE SETTLE: census 427 -> 428; the gap report 0/151 -> 5 closed / 150 open (the overview parent, its natural/unnatural/hazards children and the DM TOC close; the DM section re-grained; the perspective-maps box opened).",
    },
  "consts" = { {
      "comment" = "the overview chapter starts at printed p. 7.",
      "name" = "dovPrintedLo",
      "value" = 7,
    }, {
      "comment" = "the overview chapter ends at printed p. 11.",
      "name" = "dovPrintedHi",
      "value" = 11,
    }, {
      "comment" = "the overview chapter starts at pdf page 8 (the offset: pdf = printed + 1).",
      "name" = "dovPdfLo",
      "value" = 8,
    }, {
      "comment" = "the overview chapter ends at pdf page 12.",
      "name" = "dovPdfHi",
      "value" = 12,
    }, {
      "comment" = "three types of natural caves are commonly encountered: limestone, sea and lava.",
      "name" = "dovCaveTypeCount",
      "value" = 3,
    }, {
      "comment" = "molten lava has a temperature of approximately 1,800 degrees Fahrenheit and quickly kills any non-fire-resistant creature forced into contact with it.",
      "name" = "dovLavaTempF",
      "value" = 1800,
    }, {
      "comment" = "a dungeon excavated from dirt requires constant shoring up, at least at 10-foot intervals, to prevent cave-ins.",
      "name" = "dovDirtShoringIntervalFt",
      "value" = 10,
    }, {
      "comment" = "realms are rarely found within a mile of the surface and often extend far deeper.",
      "name" = "dovRealmShallowMi",
      "value" = 1,
    } },
  "bools" = { {
      "comment" = "limestone caves are by far the most common type, found mostly where the bedrock is a great shelf of limestone.",
      "name" = "dovLimestoneMostCommon",
      "value" = true,
    }, {
      "comment" = "dolomite and marble terrain can also serve as an environment for the creation of a limestone cave.",
      "name" = "dovLimestoneCarbonateBedrock",
      "value" = true,
    }, {
      "comment" = "a limestone cave is created by the erosive and corrosive action of water seeping through rock; rainwater, a dilute carbonic acid from absorbed carbon dioxide, quickly eats away limestone.",
      "name" = "dovLimestoneAcidErosion",
      "value" = true,
    }, {
      "comment" = "a drop in the water table leaves formerly underwater passages dry and full of air; droughts, floods or terrain movement can shift the flow.",
      "name" = "dovWaterTableDrainsCave",
      "value" = true,
    }, {
      "comment" = "the inlets or outlets of the water that once flowed through a cave, often tortuously narrow or steep, are the most common entrances to limestone caves.",
      "name" = "dovLimestoneWaterInletEntrances",
      "value" = true,
    }, {
      "comment" = "a cave grown too large may collapse its ceiling into a sinkhole dropping precipitously from the surface to the cave floor, usable as an entrance for characters willing to do a little rope work.",
      "name" = "dovSinkholeEntrance",
      "value" = true,
    }, {
      "comment" = "stalactites hang from the ceiling and stalagmites grow upward from the floor, created by slow dripping water that evaporates and leaves mineral deposits; the color ranges from muddy brown to red to a rare pure crystalline white.",
      "name" = "dovDripFormations",
      "value" = true,
    }, {
      "comment" = "the other cave features are draperies (ruffled-curtain stone sheets), flowstone (falling in tiers like flowing sludge) and rare, delicate gypsum flowers.",
      "name" = "dovOtherFormations",
      "value" = true,
    }, {
      "comment" = "a cave subject to continuing water seepage is a living cave: its features grow, glisten and shine in light, and are very sturdy; the cave is generally clean and almost dust-free before creatures enter.",
      "name" = "dovLivingCaveSeepage",
      "value" = true,
    }, {
      "comment" = "in a living cave all low areas not regularly swept by flowing water contain pools of sticky mud, which can be quite deep depending on drainage and shape.",
      "name" = "dovLivingCaveMud",
      "value" = true,
    }, {
      "comment" = "in a dead cave the water no longer flows: the features do not glisten, grow very weak without constant humidity, become brittle and eventually crumble into dust.",
      "name" = "dovDeadCaveBrittle",
      "value" = true,
    }, {
      "comment" = "a dead cave is much more likely to be choked with rubble than its living counterpart, and a layer of dust often covers everything.",
      "name" = "dovDeadCaveRubble",
      "value" = true,
    }, {
      "comment" = "water found in a dead cave has generally been standing for centuries but is very rarely stagnant - the cold temperatures and lack of sunlight see to that.",
      "name" = "dovDeadCaveWaterNotStagnant",
      "value" = true,
    }, {
      "comment" = "completely water-filled limestone caves generally have smooth, rubble-free passages, though very narrow or tightly winding ones may be difficult or impossible to travel.",
      "name" = "dovWaterFilledSmooth",
      "value" = true,
    }, {
      "comment" = "sea caves are formed along current or former coastlines where the erosive action of pounding surf gradually wears an entrance into the bedrock.",
      "name" = "dovSeaCaveSurfCarved",
      "value" = true,
    }, {
      "comment" = "sea caves are generally much smaller than limestone caves, since the waves disperse their energy quickly as they work inward.",
      "name" = "dovSeaCaveSmaller",
      "value" = true,
    }, {
      "comment" = "sea caves are often partially water-filled; a changing water level can leave one completely submerged with a hidden mouth, or stranded in a cliff far above the surf or many miles inland.",
      "name" = "dovSeaCaveWaterLevels",
      "value" = true,
    }, {
      "comment" = "sea caves have smooth floors, walls and ceilings with none of the spectacular limestone features, but their relatively easy access makes relics of long-past inhabitants more likely.",
      "name" = "dovSeaCaveSmoothNoFeatures",
      "value" = true,
    }, {
      "comment" = "a river-bend abrasion cavern, eroded where water pounds the outer bank, resembles a sea cave in most respects.",
      "name" = "dovRiverbendLikeSeaCave",
      "value" = true,
    }, {
      "comment" = "a lava cave is created when the crust of a flowing lava surface hardens while the molten lava beneath continues to flow away, leaving an air-filled space that may reach considerable size.",
      "name" = "dovLavaCrustOrigin",
      "value" = true,
    }, {
      "comment" = "lava caves are commonly found in areas of volcanic activity and do not contain the features typical of limestone caves.",
      "name" = "dovLavaCaveVolcanic",
      "value" = true,
    }, {
      "comment" = "unless in a region of heavy rainfall or at a very low elevation, lava caves may well be completely dry.",
      "name" = "dovLavaCaveDry",
      "value" = true,
    }, {
      "comment" = "a great many lava caves have no exits to the outside world; their existence can only be discovered by chance excavation or by breaking through a thin crust.",
      "name" = "dovLavaCaveHiddenExits",
      "value" = true,
    }, {
      "comment" = "earthquake and rockslide chambers, tenuously supported by accumulated rubble, resemble caves but are not true caves; they make good overnight shelters and lairs for hostile animals or monsters.",
      "name" = "dovQuakeChamberNotTrueCave",
      "value" = true,
    }, {
      "comment" = "geological faulting creates cavities when a large shelf of rock moves and the neighboring rock stays stationary; such caverns are often completely enclosed but may be very large.",
      "name" = "dovFaultCavityEnclosed",
      "value" = true,
    }, {
      "comment" = "geothermal heat can be encountered in deep caves of any kind but is particularly likely in a lava cave, since lava itself is a carrier of geothermal heat.",
      "name" = "dovGeothermalInDeepCaves",
      "value" = true,
    }, {
      "comment" = "the glowing crimson flow of molten lava carries heat from the deepest reaches and quickly kills any non-fire-resistant creature forced into contact with it.",
      "name" = "dovLavaKillsOnContact",
      "value" = true,
    }, {
      "comment" = "even where lava has cooled to a solid crust it is still blisteringly hot, and a character venturing onto it risks breaking through into the infernal heat below.",
      "name" = "dovLavaCrustBreakRisk",
      "value" = true,
    }, {
      "comment" = "steam can scald or even kill a creature caught in its intense blast; sudden vaporization in high-geothermal areas creates high pressures, and blasts can erupt far from the actual heat source.",
      "name" = "dovSteamScalds",
      "value" = true,
    }, {
      "comment" = "warm or hot water, a more tolerable form of geothermal heat, ranges from lukewarm to boiling depending on the proximity and intensity of the heat source.",
      "name" = "dovHotWaterRange",
      "value" = true,
    }, {
      "comment" = "warm or hot air rising through subterranean passages is often an explorer's first warning of approaching geothermal heat.",
      "name" = "dovWarmAirFirstWarning",
      "value" = true,
    }, {
      "comment" = "dungeons are built by intelligent creatures, each to serve a particular purpose; some are constructed entirely from caves, others use caves as entrances or emergency exits only.",
      "name" = "dovDungeonPurposeBuilt",
      "value" = true,
    }, {
      "comment" = "dungeon passages generally run within a few hundred feet of the surface; the deeper the dungeon, the harder the task of moving the excavated material out of the way.",
      "name" = "dovDungeonShallowish",
      "value" = true,
    }, {
      "comment" = "dungeons are generally excavated from a soft rock such as sandstone or limestone - not as hard to excavate as granite, yet still a solid and sturdy support.",
      "name" = "dovDungeonSoftRock",
      "value" = true,
    }, {
      "comment" = "some dungeons begin as buildings whose ruins are later buried by new buildings until the original layer seems well underground; encountered dungeons may be collapsing, newly excavated, or still under construction.",
      "name" = "dovRuinsBecomeDungeons",
      "value" = true,
    }, {
      "comment" = "the most common dungeon purposes are jails, hiding places for treasures, lairs for bands of underground creatures, and positions of defense.",
      "name" = "dovDungeonPurposes",
      "value" = true,
    }, {
      "comment" = "in a world where flying creatures are ever-present, dungeons can prove to be stronger fortresses than castles.",
      "name" = "dovDungeonStrongerThanCastles",
      "value" = true,
    }, {
      "comment" = "fantasy-world mines are almost always tunnels or shafts; mines developed over centuries by diligent excavators such as dwarves or gnomes can become complicated three-dimensional networks stretching for dozens of miles.",
      "name" = "dovMineTunnelNetworks",
      "value" = true,
    }, {
      "comment" = "active mines are usually well-guarded; inactive mines - closed for a depleted vein, a disaster or a conflict - often become the lairs of subterranean monsters.",
      "name" = "dovMineActiveGuarded",
      "value" = true,
    }, {
      "comment" = "burrows are long tunnels generally no bigger in diameter than the creature that created them, often with a widened chamber at the deepest end; usually dug from dirt, but certain creatures such as umber hulks can burrow in solid stone.",
      "name" = "dovBurrowCreatorSized",
      "value" = true,
    }, {
      "comment" = "realms are vast underground reaches of caverns, dungeons and lofty passages deep beneath the earth, regions of mystery to surface dwellers; the drow, deep gnomes, duergar, kuo-toa and derro live in reaches that never see the light of day.",
      "name" = "dovRealmsDeepMystery",
      "value" = true,
    }, {
      "comment" = "realms contain cavern networks that might rival an entire nation in size and underground bodies of water as big as any outerworld sea, with islands just as surface seas have.",
      "name" = "dovRealmNationScale",
      "value" = true,
    }, {
      "comment" = "certain vast realms are best described as wilderness where no cultures flourish, while other areas boast cities and fortresses worthy of the most advanced civilizations; horrific beasts rumored never to venture up to dungeon level are said to live there.",
      "name" = "dovRealmWildernessToCities",
      "value" = true,
    }, {
      "comment" = "cave-ins, a constant problem under tons of earth and rock, are triggered by erosion or by sudden shocks such as earthquakes or explosions; those underneath suffer falling damage and are often pinned or trapped with little air.",
      "name" = "dovCaveinTriggers",
      "value" = true,
    }, {
      "comment" = "dungeons are protected against cave-ins by shoring passages with timbers or stone arches, caverns lack such engineered protection, and realms are too vast for it - and so rarely subject to cave-ins, though a realm cave-in rivals the worst hurricane or tidal wave.",
      "name" = "dovCaveinProtectionSplit",
      "value" = true,
    }, {
      "comment" = "underground flood water has little chance to spread out and disperse; corridors may fill with water, making drowning a virtual certainty for any air-breathing creature caught there.",
      "name" = "dovFloodNoDispersion",
      "value" = true,
    }, {
      "comment" = "fires threaten underground dwellings in a double sense: they consume combustible objects in their path and also use up the precious oxygen, which exists in finite supply.",
      "name" = "dovFireDoubleThreat",
      "value" = true,
    }, {
      "comment" = "wood is not a common building material underground - the difficulty of transporting it in and its tendency to rot in damp conditions discourage its use - though shoring up a corridor is much easier with wood than with stone.",
      "name" = "dovWoodUncommonUnderground",
      "value" = true,
    }, {
      "comment" = "poisonous gases, whether natural (like the sulfur dioxide of volcanic areas), magical or manufactured, menace all oxygen-breathers, and their use as a weapon of war is greatly enhanced in the constricted underearth.",
      "name" = "dovPoisonGasConfined",
      "value" = true,
    }, {
      "comment" = "volcanoes are a major cause of subterranean fires and poison-gas emissions; often occurring with earthquakes, a volcanic burst can fill inhabited corridors with lava or steam and close off escape passages or popular transportation routes.",
      "name" = "dovVolcanoDamage",
      "value" = true,
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dovPrintedLo']() != 7 or m['dovPrintedHi']() != 11 or m['dovPdfLo']() != 8 or m['dovPdfHi']() != 12",
      "note" = "the chapter spans printed 7-11 and pdf 8-12",
    }, {
      "expr" = "m['dovPdfLo']() - m['dovPrintedLo']() != 1 or m['dovPdfHi']() - m['dovPrintedHi']() != 1",
      "note" = "the pdf offset is printed + 1 on both ends of the chapter",
    }, {
      "expr" = "m['dovCaveTypeCount']() != 3",
      "note" = "three natural cave types",
    }, {
      "expr" = "m['dovLavaTempF']() != 1800 or m['dovLavaTempF']() < 1000",
      "note" = "molten lava runs at approximately 1,800 degrees Fahrenheit",
    }, {
      "expr" = "m['dovDirtShoringIntervalFt']() != 10 or m['dovDirtShoringIntervalFt']() <= 0",
      "note" = "dirt dungeons get shored at 10-foot intervals",
    }, {
      "expr" = "m['dovRealmShallowMi']() != 1",
      "note" = "realms live deeper than a mile",
    }, {
      "expr" = "m['dovLimestoneMostCommon']() != 1",
      "note" = "dovLimestoneMostCommon",
    }, {
      "expr" = "m['dovLimestoneCarbonateBedrock']() != 1",
      "note" = "dovLimestoneCarbonateBedrock",
    }, {
      "expr" = "m['dovLimestoneAcidErosion']() != 1",
      "note" = "dovLimestoneAcidErosion",
    }, {
      "expr" = "m['dovWaterTableDrainsCave']() != 1",
      "note" = "dovWaterTableDrainsCave",
    }, {
      "expr" = "m['dovLimestoneWaterInletEntrances']() != 1",
      "note" = "dovLimestoneWaterInletEntrances",
    }, {
      "expr" = "m['dovSinkholeEntrance']() != 1",
      "note" = "dovSinkholeEntrance",
    }, {
      "expr" = "m['dovDripFormations']() != 1",
      "note" = "dovDripFormations",
    }, {
      "expr" = "m['dovOtherFormations']() != 1",
      "note" = "dovOtherFormations",
    }, {
      "expr" = "m['dovLivingCaveSeepage']() != 1",
      "note" = "dovLivingCaveSeepage",
    }, {
      "expr" = "m['dovLivingCaveMud']() != 1",
      "note" = "dovLivingCaveMud",
    }, {
      "expr" = "m['dovDeadCaveBrittle']() != 1",
      "note" = "dovDeadCaveBrittle",
    }, {
      "expr" = "m['dovDeadCaveRubble']() != 1",
      "note" = "dovDeadCaveRubble",
    }, {
      "expr" = "m['dovDeadCaveWaterNotStagnant']() != 1",
      "note" = "dovDeadCaveWaterNotStagnant",
    }, {
      "expr" = "m['dovWaterFilledSmooth']() != 1",
      "note" = "dovWaterFilledSmooth",
    }, {
      "expr" = "m['dovSeaCaveSurfCarved']() != 1",
      "note" = "dovSeaCaveSurfCarved",
    }, {
      "expr" = "m['dovSeaCaveSmaller']() != 1",
      "note" = "dovSeaCaveSmaller",
    }, {
      "expr" = "m['dovSeaCaveWaterLevels']() != 1",
      "note" = "dovSeaCaveWaterLevels",
    }, {
      "expr" = "m['dovSeaCaveSmoothNoFeatures']() != 1",
      "note" = "dovSeaCaveSmoothNoFeatures",
    }, {
      "expr" = "m['dovRiverbendLikeSeaCave']() != 1",
      "note" = "dovRiverbendLikeSeaCave",
    }, {
      "expr" = "m['dovLavaCrustOrigin']() != 1",
      "note" = "dovLavaCrustOrigin",
    }, {
      "expr" = "m['dovLavaCaveVolcanic']() != 1",
      "note" = "dovLavaCaveVolcanic",
    }, {
      "expr" = "m['dovLavaCaveDry']() != 1",
      "note" = "dovLavaCaveDry",
    }, {
      "expr" = "m['dovLavaCaveHiddenExits']() != 1",
      "note" = "dovLavaCaveHiddenExits",
    }, {
      "expr" = "m['dovQuakeChamberNotTrueCave']() != 1",
      "note" = "dovQuakeChamberNotTrueCave",
    }, {
      "expr" = "m['dovFaultCavityEnclosed']() != 1",
      "note" = "dovFaultCavityEnclosed",
    }, {
      "expr" = "m['dovGeothermalInDeepCaves']() != 1",
      "note" = "dovGeothermalInDeepCaves",
    }, {
      "expr" = "m['dovLavaKillsOnContact']() != 1",
      "note" = "dovLavaKillsOnContact",
    }, {
      "expr" = "m['dovLavaCrustBreakRisk']() != 1",
      "note" = "dovLavaCrustBreakRisk",
    }, {
      "expr" = "m['dovSteamScalds']() != 1",
      "note" = "dovSteamScalds",
    }, {
      "expr" = "m['dovHotWaterRange']() != 1",
      "note" = "dovHotWaterRange",
    }, {
      "expr" = "m['dovWarmAirFirstWarning']() != 1",
      "note" = "dovWarmAirFirstWarning",
    }, {
      "expr" = "m['dovDungeonPurposeBuilt']() != 1",
      "note" = "dovDungeonPurposeBuilt",
    }, {
      "expr" = "m['dovDungeonShallowish']() != 1",
      "note" = "dovDungeonShallowish",
    }, {
      "expr" = "m['dovDungeonSoftRock']() != 1",
      "note" = "dovDungeonSoftRock",
    }, {
      "expr" = "m['dovRuinsBecomeDungeons']() != 1",
      "note" = "dovRuinsBecomeDungeons",
    }, {
      "expr" = "m['dovDungeonPurposes']() != 1",
      "note" = "dovDungeonPurposes",
    }, {
      "expr" = "m['dovDungeonStrongerThanCastles']() != 1",
      "note" = "dovDungeonStrongerThanCastles",
    }, {
      "expr" = "m['dovMineTunnelNetworks']() != 1",
      "note" = "dovMineTunnelNetworks",
    }, {
      "expr" = "m['dovMineActiveGuarded']() != 1",
      "note" = "dovMineActiveGuarded",
    }, {
      "expr" = "m['dovBurrowCreatorSized']() != 1",
      "note" = "dovBurrowCreatorSized",
    }, {
      "expr" = "m['dovRealmsDeepMystery']() != 1",
      "note" = "dovRealmsDeepMystery",
    }, {
      "expr" = "m['dovRealmNationScale']() != 1",
      "note" = "dovRealmNationScale",
    }, {
      "expr" = "m['dovRealmWildernessToCities']() != 1",
      "note" = "dovRealmWildernessToCities",
    }, {
      "expr" = "m['dovCaveinTriggers']() != 1",
      "note" = "dovCaveinTriggers",
    }, {
      "expr" = "m['dovCaveinProtectionSplit']() != 1",
      "note" = "dovCaveinProtectionSplit",
    }, {
      "expr" = "m['dovFloodNoDispersion']() != 1",
      "note" = "dovFloodNoDispersion",
    }, {
      "expr" = "m['dovFireDoubleThreat']() != 1",
      "note" = "dovFireDoubleThreat",
    }, {
      "expr" = "m['dovWoodUncommonUnderground']() != 1",
      "note" = "dovWoodUncommonUnderground",
    }, {
      "expr" = "m['dovPoisonGasConfined']() != 1",
      "note" = "dovPoisonGasConfined",
    }, {
      "expr" = "m['dovVolcanoDamage']() != 1",
      "note" = "dovVolcanoDamage",
    } },
  "audit" = {
      "label" = "R503 DSG overview audit",
      "comment" = "The DSG OVERVIEW OF THE UNDERDARK, printed pp. 7-11 (pdf 8-12) - the first DSG content round, the R497 pattern applied to the dungeoneering book: the three natural cave types (limestone, sea, lava), the living/dead cave split, the drip formations, the geothermal ladder with the 1,800-degree lava, the unnatural locale taxonomy (dungeons, mines, burrows, realms) and the five hazard families of the underearth. The load-bearing pins: the pdf = printed + 1 offset (proved by the chapter opener on pdf 7 for printed 6); the three-cave taxonomy; the molten lava temperature of approximately 1,800 F that kills non-fire-resistant creatures on contact; the 10-foot dirt-shoring interval; the realms-deeper-than-a-mile rule; and the living/dead cave mechanics (glisten, sturdy, mud pools vs brittle, dust, rubble, standing-but-not-stagnant water). The DM-section boxes of tools/dsg_gap_report.md are re-grained in the same splice from the DM table of contents pulled at pdf 65, and the perspective-maps section (pp. 124-127) the player TOC missed is opened. Provenance: the tesseract reads (d8-d12 full/tsv/png) on the r503-extraction branch; pdf 9 is the cave-formations illustration plate (labels only).",
    },
}
