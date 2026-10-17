// =========================================================================================
// Adnd1 - rules/dsggeo.h
// THE DSG UNDERGROUND GEOGRAPHY AND THEORIES, R531: printed pp. 69-71 (pdf
// 70-72) - the second DM-section round, two children: the underground
// geography - domains in three dimensions (the total accessible area equaling
// the ground area of a large nation, the campaign-by-campaign world building,
// the 1,000-mile sample region; the surface terrain - the water-filled sea
// tunnels with their permanent-magic rationale, the stale dead-end air
// pockets, the water table, the higher-altitude mountain domains with
// explorers resurfacing at the mountain base, and the
// granite-versus-limestone seabeds; the temperature - the geothermal plant
// growth, the drow and duergar warm lairs making intelligent encounters
// likelier near heat, and the slow convection exploited by ventilation
// tunnels; the humidity - the brittle dried formations, the steamy
// scavenger-prized slippery rock, the dusty low-humidity areas, and the
// ever-changing erosion with its cave-ins and rock slides; the size - the
// creature-size limits of the three-foot halfling tunnels, the avoided
// unsupported caverns stretching a mile wide, the drow-duergar-derro support
// columns and permanenced spells, and the jermalaine-pech small-tunnel
// defense; the origin - the irregular natural caverns, the
// duergar-svirfneblin domed cities with their straight miles-long tunnels and
// ornate stonework, the drow-kuo-toa preference for conquering duergar lairs,
// and the mind flayer-myconid natural caverns; and the access and egress -
// the fresh air near surface connections, the no-access air shafts of the
// arctic example, and the easy-access raiders orcs, goblins and kobolds
// versus the deep cultures shunning the outside world), and the theories on
// the nature of the underground (the DM-decides frame and the sage-knowledge
// role playing; the hollow earth theory with its variants - the inner world
// of flyers and levitators cloaked in darkness with volcanic light, the
// lava-rain fire world, the far-fetched inner shell, and the Plane of Air
// connection; the Swiss cheese theory with the goblin-hobgoblin-orc ubiquity
// argument, the failed expeditions, and the unexploited connections; the
// isolated pockets theory with its forced-migration goblin-slave explanation;
// and the partial connection theory with its fire and water blocks and the
// later-sealed traversable pasts)
// census 454 -> 455.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~8902-9268) with the pdf Acrobat-Capture layer as the second read (idx
// 163-168 = the printed pp. 69-71 windows; the odd image-heavy interleaves
// hold no text in Capture); the compiled-tables appendix has no reprint of
// this prose. A CLEAN-READ ROUND: both machine reads agree on every
// load-bearing number - the 1,000-mile diameter, the three-foot tunnels, the
// hundreds-of-feet ceilings, and the mile-side-to-side caverns; the only
// garbles are the standing glyph classes (the Cyrillic-lead djvu noise in the
// page headers). SEAMS: the R530 underground environment (the oxygen
// circulation the air-shaft geography elaborates), the R521-R524 mining
// rounds (the duergar and svirfneblin excavators), the Monster Manual
// cultures, the DMG inner planes (the Plane of Air connection), and the R503
// re-grain. Nothing auto-credits.
//
// A prose round: no tables pin. The numbers pin as consts per the R508
// convention: the 1,000-mile sample-region diameter, the 3-foot halfling
// tunnels, and the 1-mile-wide largest caverns. The rest pins as prose bools:
// the geography factors (the frame, the surface terrain, the temperature, the
// humidity, the size, the origin, the access and egress) and the four
// theories with the DM-decides frame. The R530/R521-R524/MM/DMG/R503 seams
// are noted; nothing auto-credits.
//
namespace rules {

// ---- the underground geography section ----

// the total area of all the caverns, dungeons and tunnels equals the ground
// area of a large nation - this accessible total is the underground world
// that awaits the players, its layout to be well conceived and thoroughly
// understood by the DM.
inline bool dngrLargeNationArea()
    { return true; }

// habitable underground terrain extends beneath much of the campaign world,
// but mapping an entire world of caverns is impractical - the DM handles the
// creation on a campaign-by-campaign basis, the sample-area patterns adapted
// to his needs.
inline bool dngrCampaignByCampaign()
    { return true; }

// the typical underground geography area detailed for the DM is about 1,000
// miles in diameter and several dozen miles in depth, adaptable to his
// campaign.
inline int dngrRegionDiaMiles()
    { return 1000; }

// a network of tunnels or caverns beneath a body of water is nearly always
// water-filled; air requires a rationale - permanent magic holding the water
// at bay.
inline bool dngrSeaWaterFilled()
    { return true; }

// air pockets trapped in dead-end corridors cannot circulate, and hence are
// stale and of limited use for air-breathing creatures.
inline bool dngrTrappedAirStale()
    { return true; }

// even areas below dry land may be water-filled: all areas contain a water
// table, a level below which all openings are filled with water, and without
// steady drainage it can make entire stretches of caverns uninhabitable.
inline bool dngrWaterTable()
    { return true; }

// a domain beneath mountains may hold dungeons or caverns actually higher in
// altitude than many surrounding lands - explorers move deeper and deeper and
// abruptly return to the surface at the base of the mountain range.
inline bool dngrMountainDomainsHigher()
    { return true; }

// mountains and other solid-granite areas are much less likely to be
// penetrated by caves than the vast limestone bedrock expanses beneath the
// plains and forests - former seabeds, the most susceptible to natural cave
// formation - though excavated areas can be discovered anywhere.
inline bool dngrGraniteLimestone()
    { return true; }

// when geothermal energy is present, caverns tend to be more crowded with
// subterranean plants than cooler regions are.
inline bool dngrGeothermalPlants()
    { return true; }

// intelligent races, particularly the drow and the duergar, seek out the
// warmer caverns for their lairs and cities - so the chance of encountering
// intelligent denizens is significantly higher around sources of underground
// heat.
inline bool dngrWarmLairHeatRaces()
    { return true; }

// warm temperatures circulate air, heated air rising and cool fresh air drawn
// in; the natural convection is slow and inefficient, so intelligent races
// often excavate ventilation tunnels to exploit it, giving modified areas a
// good supply of fresh air.
inline bool dngrConvectionVentilation()
    { return true; }

// if a cave dries up, its stalactites, stalagmites and all exposed surfaces
// grow extremely brittle and eventually turn to dust.
inline bool dngrDryCaveBrittle()
    { return true; }

// high humidity with warm temperatures creates a steamy environment highly
// prized by certain scavengers - the rock very slippery, often coated with
// lichen, mold or other slimy matter.
inline bool dngrSteamyScavengerRock()
    { return true; }

// underground areas of extremely low humidity, regardless of temperature,
// tend to be very dusty.
inline bool dngrLowHumidityDusty()
    { return true; }

// water flowing through an area constantly erodes its bed so the area itself
// is always changing - often leading to cave-ins and rock slides, hazards not
// common in drier regions.
inline bool dngrErosionHazards()
    { return true; }

// the expanse of an area determines a great many characteristics, most
// obviously the physical limitations on the sizes of creatures encountered
// there.
inline bool dngrSizeLimitsCreatures()
    { return true; }

// a group of halfling explorers does not worry about encountering ogres in a
// network of three-foot-wide tunnels - the expanse of an area limits the
// sizes of creatures encountered there.
inline int dngrHalflingTunnelFt()
    { return 3; }

// some of the largest underground caverns have ceilings soaring hundreds of
// feet and stretch as much as a mile from side to side.
inline int dngrBigCavernMileWide()
    { return 1; }

// unless a huge cavern is magically or physically supported, intelligent
// creatures avoid it when seeking living quarters - even a minor earthquake,
// tremor or landslide could cave in a section of the ceiling
// catastrophically.
inline bool dngrHugeCavernsAvoided()
    { return true; }

// the drow, duergar and derro do prefer large underground areas for their
// communities, but are careful to prevent disasters - support columns the
// most common precaution, with permanenced magical spells also serving
// against cave-ins.
inline bool dngrSupportColumnsSpells()
    { return true; }

// creatures such as the jermalaine and pech choose small, constricted tunnel
// networks as living quarters - their small size is their greatest defense in
// such locations; other underground creatures adapt to both small and large
// lairs.
inline bool dngrSmallTunnelDefense()
    { return true; }

// naturally eroded or developed places - caverns, lava caves - vary widely in
// size and shape, earmarked by irregular walls, ceilings and floors,
// sometimes so rough, steep or constricted that travel on foot is virtually
// impossible.
inline bool dngrNaturalIrregular()
    { return true; }

// the lairs of the duergar and svirfneblin are the most smoothly carved
// regions of the underworld - often a large central cavern developed into a
// virtual domed city with individual residences excavated into the cavern
// walls.
inline bool dngrDuergarSmoothCities()
    { return true; }

// the skilled miners are capable of digging a perfectly straight tunnel many
// miles long, or of creating ornate stonework decorations.
inline bool dngrStraightMileTunnels()
    { return true; }

// races such as the drow and kuo-toa have limited excavation ability and much
// prefer to discover a fine duergar lair, overcome the gray dwarves defenses
// and claim it for their own; the mind flayers and myconids show no interest
// or ability in excavation, living in natural caverns or abandoned dungeons.
inline bool dngrDrowConquerLairs()
    { return true; }

// fresh air is much more plentiful in areas with some direct connection to
// the surface - though air can flow through shafts and tunnels that do not
// allow creatures easy access, the miles-deep arctic ventilation shafts a
// good example.
inline bool dngrAirShaftsNoAccess()
    { return true; }

// areas allowing easy access to the surface are populated by creatures that
// occasionally leave to raid or trade - orcs, goblins and kobolds the good
// examples - while most Underdark cultures dwell so deep they need not worry
// about the outside world, shunning the surface and its intrusion alike.
inline bool dngrEasyAccessRaiders()
    { return true; }

// ---- the theories on the nature of the underground section ----

// each theory was proposed by adventurers or sages and has its own merits -
// which if any are correct is the DMs decision, consistent with his overall
// campaign plans.
inline bool dngrDmDecidesTheory()
    { return true; }

// the theories are not common knowledge but are regarded much as an advanced
// scientific hypothesis is today - not secret to the sages, but not of broad
// popular interest; player characters must seek out knowledgeable NPCs and
// role play for the information.
inline bool dngrSageKnowledge()
    { return true; }

// the hollow earth theory holds that the surface is a mere crust over a vast
// open space where life forms exist almost completely isolated from the
// surface - no adventurer is known to have visited the inner earth, all
// reports originating from the deepest cultures.
inline bool dngrHollowEarthTheory()
    { return true; }

// some stories maintain a vast atmosphere beneath the crust with a small
// version of our own world at its middle - only creatures that can fly or
// levitate for long periods could travel between the worlds, and the inner
// earth is presumably cloaked in utter darkness though savage volcanic bouts
// light up great tracts of it.
inline bool dngrHollowInnerWorld()
    { return true; }

// other versions hold that columns of fiery lava fall from the outer earth as
// a rain of fire onto the inner earths surface - the temperature very high,
// hosting only creatures with a considerable liking for or resistance to
// fire.
inline bool dngrHollowLavaRain()
    { return true; }

// another theory holds the entire center hollow with the outer earth a thin
// shell - creatures living on the inside looking up to the center -
// considered one of the more far-fetched explanations.
inline bool dngrHollowShellVariant()
    { return true; }

// a variation keeps the air-filled center but denies creatures walking upside
// down on the inner shell: the center is home only to flying and levitating
// creatures, and is in fact a prime point of connection between the Plane of
// Air and our plane.
inline bool dngrHollowAirCenter()
    { return true; }

// the Swiss cheese theory holds the world fundamentally solid with no massive
// hollow core, but with enough caves, caverns and artificial passageways for
// an individual to travel anywhere under the world.
inline bool dngrSwissCheeseTheory()
    { return true; }

// the supporting argument is the widespread occurrence of goblins, hobgoblins
// and orcs - none liking to travel overland, so their wanderings must have
// occurred through a vast tunnel network; the mirrored characteristics of
// distant goblins prove nothing, since they might have migrated overland or
// received common traits from the same source - an evil deity, for example.
inline bool dngrGoblinUbiquity()
    { return true; }

// many adventurers have embarked to prove the theory - most failed to return,
// and the survivors report only failure: routes that dead-ended, circled back
// upon themselves, or led to the surface near the starting point.
inline bool dngrFailedExpeditions()
    { return true; }

// if connections between most Underdark realms exist, the fact is unexploited
// by its denizens - perhaps the passages are too small for great numbers, the
// habitable regions too far apart, or strife has prevented large-scale
// movements.
inline bool dngrUnexploitedConnections()
    { return true; }

// the isolated pockets theory is the least imaginative but fits most closely
// with present observations: each discovered underground region is an area
// unto itself, with no subterranean connections to any other.
inline bool dngrIsolatedPocketsTheory()
    { return true; }

// the contrary evidence - cultural similarities between widely separated
// populations - is explained as migration over the surface or the influence
// of a deity unbounded by geography; sunlight-hating creatures could have
// been forced to migrate overland, as goblins enslaved by humans who escaped
// into the dungeons, keeping their ancestors traditions.
inline bool dngrForcedMigration()
    { return true; }

// the partial connection theory, common among the most knowledgeable
// students, maintains connections between all or most underground regions but
// stops short of easy accessibility: the routes are treacherous and often
// impassable.
inline bool dngrPartialConnectionTheory()
    { return true; }

// fire - volcanic activity, lava, steam - is commonly suggested as a block to
// these passages, traversable only by creatures with powerful fire
// resistance; water is the other common obstacle, regions beneath the deepest
// seas unlikely to hold breathable air - a region traversable in the distant
// past could later have been filled with water or split by volcanic fire.
inline bool dngrFireWaterBlocks()
    { return true; }

}   // namespace rules
