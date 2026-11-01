-- dnam: promoted from tools/spec_r544.json (the THE DSG DEEPEARTH AREAS 22-23, R544: printed pp. 92-93 (pdf 93-94) - the individual area key reaches the demihuman lands: Area 22 the Lands of the Deep Gnomes (the extensive region of long narrow north-south caverns stacked in three levels, averaging 20 by 10 feet, pinching to two or three feet once per mile; the streams never filling the passages and the gnome-built upper walks and spiral stairways; the excavated homes from tiny burrows to crawl-in residences; one clan per cave with its 60-by-8-foot council chamber; the central 200-by-10-foot meeting chamber ringed by the powerful clans; the ~5,000 svirfneblin with a third mobilizable; the protected rothe herds, 100 per clan and eight or 10 times that; the trickling fresh water and still pools; the Grand Canyon air circulation; the edible fungi; the iron-silver-copper-lead mines with five-mile shafts; the smelter and smithy with the coal fires venting to the lava sea; the traded and stockpiled surplus; and the vault - thousands of 500-sp silver bars behind the 550-Strength stone door opened weekly by winch teams and hidden by illusions), and Area 23 the Lower Grand Canyon (the lower portion of Area 7 descending another 1,200 feet; the duergar and deep gnome domains meeting at the canyon, their vast carved galleries of a thousand or more spectators facing each other across the 1,000-foot width; the 20-foot stone bridge; and the arena beneath - a three-dimensional web of stone arches, metal girders, rope ladders and nets where champion duels replace the wars of the past, nonmissile weapons only, the duergar-svirfneblin duels always fatal, the girder spacing hampering the small warriors while humans move easily).);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 544,
  "prefix" = "dnam",
  "banner" = {
      "title" = "THE DSG DEEPEARTH AREAS 22-23, R544: printed pp. 92-93 (pdf 93-94) - the individual area key reaches the demihuman lands: Area 22 the Lands of the Deep Gnomes (the extensive region of long narrow north-south caverns stacked in three levels, averaging 20 by 10 feet, pinching to two or three feet once per mile; the streams never filling the passages and the gnome-built upper walks and spiral stairways; the excavated homes from tiny burrows to crawl-in residences; one clan per cave with its 60-by-8-foot council chamber; the central 200-by-10-foot meeting chamber ringed by the powerful clans; the ~5,000 svirfneblin with a third mobilizable; the protected rothe herds, 100 per clan and eight or 10 times that; the trickling fresh water and still pools; the Grand Canyon air circulation; the edible fungi; the iron-silver-copper-lead mines with five-mile shafts; the smelter and smithy with the coal fires venting to the lava sea; the traded and stockpiled surplus; and the vault - thousands of 500-sp silver bars behind the 550-Strength stone door opened weekly by winch teams and hidden by illusions), and Area 23 the Lower Grand Canyon (the lower portion of Area 7 descending another 1,200 feet; the duergar and deep gnome domains meeting at the canyon, their vast carved galleries of a thousand or more spectators facing each other across the 1,000-foot width; the 20-foot stone bridge; and the arena beneath - a three-dimensional web of stone arches, metal girders, rope ladders and nets where champion duels replace the wars of the past, nonmissile weapons only, the duergar-svirfneblin duels always fatal, the girder spacing hampering the small warriors while humans move easily).",
      "provenance" = "the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf = printed + 1; the text read from the IA djvu OCR (djvu.txt lines ~11935-12079) with the pdf Acrobat-Capture layer as the second read (capture idx 212 = the printed p. 93 area-22 tail window and idx 214 head = the area 23 text); the compiled-tables appendix has no reprint of this prose. A CLEAN-READ ROUND: both machine reads agree on every load-bearing number - the three levels, the 20/10-ft averages, the once-per-mile 2-3-ft pinches, the 60/8-ft council chambers, the 200/10-ft meeting hall, the 5,000 population with a third mobilizable, the 100-rothe clans with 8-10x herds, the five-mile shafts, the 500-sp silver bars behind the 550-Strength door, the 1,200-ft descent, the thousand-spectator galleries across the 1,000-ft width, and the 20-ft bridge; no cross-read garbles this round - both reads are clean. SEAMS: the R518 water travel (the navigable-boat note lands in Area 24), the Monster Manual denizens (the svirfneblin, duergar, rothe and the Area 7 fauna by reference), the R521-R522 mining (the gnome and duergar mines), and the Area 7 Grand Canyon round itself. A ZERO-FLIP ROUND: the pp. 75-98 Deepearth child remains open until the setting lands in full (the R527/R533-R543 precedent - the gap report is NOT in the git add). Nothing auto-credits.",
      "sentinel" = "A procedural-plus-prose round: no tables pin. The numbers pin as consts per the R508 convention - the cavern level count, the width and height averages, the pinch frequency and diameter bounds, the council and meeting chamber dimensions, the population, the rothe minimum and herd multiplier bounds, the mine shaft miles, the vault Strength and the silver bar value, the canyon descent and width and gallery capacity, and the bridge width. The geography, denizens, resources and unique-features prose pins as bools for both areas; no dice appear in this round. The water-travel/MM/mining seams are noted; the Deepearth child stays open; nothing auto-credits.",
    },
  "consts" = { {
      "name" = "dnamCavernLevels",
      "value" = 3,
      "comment" = "the deep gnomes' caverns are stacked in three distinct levels.",
    }, {
      "name" = "dnamCaveWideFt",
      "value" = 20,
      "comment" = "the deep gnome caves average 20 feet wide.",
    }, {
      "name" = "dnamCaveHighFt",
      "value" = 10,
      "comment" = "the deep gnome caves average 10 feet high.",
    }, {
      "name" = "dnamPinchPerMile",
      "value" = 1,
      "comment" = "at least once each mile travelers encounter a short narrow passage.",
    }, {
      "name" = "dnamPinchDiaLoFt",
      "value" = 2,
      "comment" = "the once-per-mile passage is only two or three feet in diameter (the low bound).",
    }, {
      "name" = "dnamPinchDiaHiFt",
      "value" = 3,
      "comment" = "the once-per-mile passage is two or three feet in diameter (the high bound).",
    }, {
      "name" = "dnamCouncilDiaFt",
      "value" = 60,
      "comment" = "each clan maintains its own council chamber, an excavated chamber about 60 feet in diameter.",
    }, {
      "name" = "dnamCouncilHighFt",
      "value" = 8,
      "comment" = "the clan council chamber is eight feet high.",
    }, {
      "name" = "dnamMeetingDiaFt",
      "value" = 200,
      "comment" = "the clan meeting chamber is a huge chamber 200 feet in diameter.",
    }, {
      "name" = "dnamMeetingCeilFt",
      "value" = 10,
      "comment" = "the meeting chamber ceiling is only 10 feet from the floor, with numerous columns supporting it.",
    }, {
      "name" = "dnamSvirfPop",
      "value" = 5000,
      "comment" = "the total population of svirfneblin numbers close to 5,000.",
    }, {
      "name" = "dnamRothePerClan",
      "value" = 100,
      "comment" = "each clan of svirfneblin keeps at least 100 rothe.",
    }, {
      "name" = "dnamHerdMultLo",
      "value" = 8,
      "comment" = "larger rothe herds number eight or 10 times as many beasts as the clan minimum (the low bound).",
    }, {
      "name" = "dnamHerdMultHi",
      "value" = 10,
      "comment" = "larger rothe herds number eight or 10 times the clan minimum (the high bound).",
    }, {
      "name" = "dnamMineShaftMiles",
      "value" = 5,
      "comment" = "many of the deep gnome mine shafts are over five miles long.",
    }, {
      "name" = "dnamVaultStr",
      "value" = 550,
      "comment" = "the vault door requires a combined Strength of 550 to open.",
    }, {
      "name" = "dnamSilverBarSp",
      "value" = 500,
      "comment" = "the vault contains thousands of bars of silver worth 500 sp apiece, alongside the excess products of the smiths.",
    }, {
      "name" = "dnamWallsDescendFt",
      "value" = 1200,
      "comment" = "the canyon walls descend another 1,200 feet from this point.",
    }, {
      "name" = "dnamGalleryCap",
      "value" = 1000,
      "comment" = "each carved gallery holds a thousand or more spectators.",
    }, {
      "name" = "dnamCanyonWideFt",
      "value" = 1000,
      "comment" = "the canyon spans a 1,000-foot width at the bridge.",
    }, {
      "name" = "dnamBridgeWideFt",
      "value" = 20,
      "comment" = "a sturdy stone bridge about 20 feet wide stretches between the two galleries.",
    } },
  "bools" = { {
      "name" = "dnamNorthSouthCaverns",
      "value" = true,
      "comment" = "this extensive region of natural caverns comprises numerous long, narrow caverns all running north to south, side by side and also above and below each other.",
    }, {
      "name" = "dnamNarrowStretches",
      "value" = true,
      "comment" = "in many places the caves become much narrower than their average size.",
    }, {
      "name" = "dnamStreamsDryFeet",
      "value" = true,
      "comment" = "streams flow through most of the caves but never completely fill the passages; where they come close to choking off tunnels, the svirfneblin have built upper passages so a gnome-sized character can walk anywhere without wet feet.",
    }, {
      "name" = "dnamGnomeStairways",
      "value" = true,
      "comment" = "the vertical connections between caves are all deep-gnome-crafted small spiral stairways or ladders - tight squeezes for humans, but none too small for them to force through.",
    }, {
      "name" = "dnamExcavatedHomes",
      "value" = true,
      "comment" = "many small tunnels are excavated in the cave sides as svirfneblin homes, ranging from burrows too small for a human to large multi-family residences or council centers a human could crawl into and stand erect.",
    }, {
      "name" = "dnamClanPerCave",
      "value" = true,
      "comment" = "each cave in the area is the home of a single clan of the deep gnomes, the most prestigious clans holding the largest caves.",
    }, {
      "name" = "dnamMeetingChamber",
      "value" = true,
      "comment" = "the gnomes cooperate well and have established a clan meeting chamber in a central cave, surrounded by the residences of the most powerful clans.",
    }, {
      "name" = "dnamThirdMobilize",
      "value" = true,
      "comment" = "about 1/3 of the svirfneblin population is able to mobilize for military purposes, making them a force to be reckoned with in Deepearth.",
    }, {
      "name" = "dnamRotheHerds",
      "value" = true,
      "comment" = "many herds of rothe live in the same caverns as the svirfneblin; the gnomes protect them from the more savage predators and use their wooly hair and tasty meat, practicing selective breeding for a healthy livestock supply.",
    }, {
      "name" = "dnamTrickleWater",
      "value" = true,
      "comment" = "fresh water trickles steadily into the caverns through many small wall and ceiling cracks; no single watercourse is a stream, but the trickles combine to the equivalent of a small stream per cave, gathering in a few large still pools.",
    }, {
      "name" = "dnamCanyonAir",
      "value" = true,
      "comment" = "the caverns at the southern end of the domain gain air circulation through the Grand Canyon of Deepearth, enough to supply all the caverns amply.",
    }, {
      "name" = "dnamEdibleFungi",
      "value" = true,
      "comment" = "plant life is represented by the edible fungi that grow throughout the area.",
    }, {
      "name" = "dnamGnomeMines",
      "value" = true,
      "comment" = "the tunnels branching off the northeast end of the domain are ever-growing mines of iron, silver, copper and lead, extending deep into the earth and horizontally north and east, worked by the industrious gnomes for generations.",
    }, {
      "name" = "dnamSmelter",
      "value" = true,
      "comment" = "a vast cavern connects the dwellings with the mining tunnels and holds a huge smelter and smithy; massive amounts of coal feed the roaring fires, and exhaust smoke vents through bedrock cracks into the lava sea caverns where it harmlessly disperses.",
    }, {
      "name" = "dnamSmithSurplus",
      "value" = true,
      "comment" = "svirfneblin blacksmiths, weaponsmiths and armorers toil endlessly creating high-quality weapons, armor and tools - many more than they need; some surplus is traded with other cultures and the rest stockpiled.",
    }, {
      "name" = "dnamVaultDoor",
      "value" = true,
      "comment" = "a huge stone door blocks off a large vault, sliding along a grooved floor track; the gnomes pull it aside about once a week with a work team of hundreds and a complicated system of winches and pulleys, and a number of illusions conceal the entrance.",
    }, {
      "name" = "dnamLowerCanyon",
      "value" = true,
      "comment" = "this is the lower portion of the Grand Canyon of Deepearth (Area 7), and the domains of the deep gnomes and the duergar both reach to the canyon itself.",
    }, {
      "name" = "dnamBridgedDomains",
      "value" = true,
      "comment" = "the canyon is bridged between Areas 22 and 24.",
    }, {
      "name" = "dnamCarvedGalleries",
      "value" = true,
      "comment" = "on each side of the canyon the demi-humans have carved vast galleries capable of holding a thousand or more spectators, facing each other across the canyon.",
    }, {
      "name" = "dnamArenaWeb",
      "value" = true,
      "comment" = "below the bridge, in full view of both galleries, is a three-dimensional web of stone arches, metal girders, rope ladders and nets - an arena of subterranean competition.",
    }, {
      "name" = "dnamArea7Denizens",
      "value" = true,
      "comment" = "denizens and resources are as explained under Area 7, noting that svirfneblin and duergar war parties constantly watch each other across the canyon.",
    }, {
      "name" = "dnamChampionDuels",
      "value" = true,
      "comment" = "the arena is a treacherous structure upon which most conflicts among the duergar and deep gnomes (and interracial fights) are resolved: the tragic costly wars of the past convinced the demi-humans to appoint a champion per faction and have them fight to the death rather than risk the devastation of war.",
    }, {
      "name" = "dnamNonmissileArms",
      "value" = true,
      "comment" = "the champions carry an assortment of nonmissile weapons onto the girders and fight to the death; the conflict may sometimes resolve sooner, but a duergar-svirfneblin duel always results in a fatality.",
    }, {
      "name" = "dnamArenaManeuver",
      "value" = true,
      "comment" = "the three-dimensional arena allows a unique combat in which opponents maneuver for height, positions of security and openings for attack; the girders and beams are spaced far enough apart that the small warriors often have difficulty reaching each other, while humans and larger creatures move through more easily.",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dnamCavernLevels']() != 3 or m['dnamCaveWideFt']() != 20 or m['dnamCaveHighFt']() != 10",
      "note" = "the gnome caverns: three levels, 20 ft wide, 10 ft high.",
    }, {
      "expr" = "m['dnamPinchPerMile']() != 1 or m['dnamPinchDiaLoFt']() != 2 or m['dnamPinchDiaHiFt']() != 3",
      "note" = "the pinches: once per mile, two to three feet across.",
    }, {
      "expr" = "m['dnamCouncilDiaFt']() != 60 or m['dnamCouncilHighFt']() != 8 or m['dnamMeetingDiaFt']() != 200 or m['dnamMeetingCeilFt']() != 10",
      "note" = "the chambers: the 60-ft/8-ft council rooms, the 200-ft/10-ft meeting hall.",
    }, {
      "expr" = "m['dnamSvirfPop']() != 5000 or m['dnamRothePerClan']() != 100 or m['dnamHerdMultLo']() != 8 or m['dnamHerdMultHi']() != 10",
      "note" = "the population: ~5,000 svirfneblin, 100 rothe per clan, herds eight or 10 times larger.",
    }, {
      "expr" = "m['dnamMineShaftMiles']() != 5 or m['dnamVaultStr']() != 550 or m['dnamSilverBarSp']() != 500",
      "note" = "the works: five-mile shafts, the 550-Strength vault door, 500-sp silver bars.",
    }, {
      "expr" = "m['dnamWallsDescendFt']() != 1200 or m['dnamGalleryCap']() != 1000 or m['dnamCanyonWideFt']() != 1000 or m['dnamBridgeWideFt']() != 20",
      "note" = "the lower canyon: 1,200-ft walls, thousand-spectator galleries, the 1,000-ft span, the 20-ft bridge.",
    } },
  "audit" = {
      "label" = "R544 DSG Deepearth areas 22-23 audit",
      "comment" = "The DSG Deepearth areas 22-23 pin Area 22 (the Lands of the Deep Gnomes with their three-level caverns, the clan council chambers, the 5,000-svirfneblin population, the rothe herds, the mines, the smelter and the 550-Strength silver vault) and Area 23 (the Lower Grand Canyon with its spectator galleries, the 20-ft bridge and the three-dimensional champion arena).",
    },
}
