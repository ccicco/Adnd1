// =========================================================================================
// Adnd1 - rules/dsgarea10.h
// THE DSG DEEPEARTH AREAS 20-21, R543: printed pp. 91-92 (pdf 92-93) - the
// individual area key crosses the fire: Area 20 the Lava Caves (the balcony
// cavern overlooking the vast amphitheatre of molten rock, its weekly
// eruptions, the cataclysm-split cave half fallen away and baked brittle; the
// 400-foot climbable cliff, the crags and columns, the 1,000-foot ceiling
// losing chunks daily, the ocean-like swells and splashing; the fire giant
// outpost of about 20 with its dozen hell hounds and always-mounted tunnel
// guard; the rock-island lairs of fire giants and lava children at 50% per
// island; the porpoise-like magmen, the dwelling fire bats, the savage magma
// para-elementals; the once-a-decade elemental invasions repelled by the
// joined giants and lava children; the granite lava boats 80-240 feet long at
// 20% width, twin-masted over 160 feet, an oar pair per 40 feet; and the fire
// giant king's island castle with its 120-foot flank-towered harbor), and
// Area 21 the Elemental Vortex of Fire (the waterless, wind-sucked region
// where a torch dies 50% of the time; the 1,000-by-300-foot cavern with its
// rotted formations; the perfectly circular 100-foot hole ringed in flame,
// hypnotic and bottomless, a Wisdom Check after one round of staring
// compelling the failed jump; the vortex gate to the Plane of Fire; the 1d6
// fire elementals guarding it and the 50% chance of 1d6 efreeti, salamanders,
// azer, fire bats or elemental grue reinforcing on the first and every other
// round; the hot dry sulphurous air; the 8d8-per-round passage falling as if
// feather-fallen, escapable by levitation or fly within five rounds,
// committed after, ten rounds to the volcanic landscape; and the two Prime
// connections - 50% Area 21, 50% the lava sea whirlpool that draws boats
// within 500 feet).
// census 466 -> 467.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~11688-11932) with the pdf Acrobat-Capture layer as the second read
// (capture idx 210 = the printed pp. 91-92 window, with the p. 92 tail and
// the Area 22 head carried in idx 212); the compiled-tables appendix has no
// reprint of this prose. A CLEAN-READ ROUND: both machine reads agree on
// every load-bearing number - the weekly eruptions, the 400-ft cliff, the
// 1,000-ft ceiling, the 20-giant outpost with its dozen hounds, the 50%
// island races, the decade invasions, the 80/240-ft boats at 20% width with
// the 160-ft mast threshold and 40-ft oar spacing, the 120-ft harbor mouth
// with its dozen-per-tower, the 50% torch, the 1,000x300-ft cavern, the
// 100-ft hole, the one-round stare, the 1d6 elementals, the 50% 1d6
// reinforcements, the 8d8 passage, the five- and ten-round windows, the 50/50
// connections and the 500-ft whirlpool draw; the only garbles settled
// cross-read (the djvu 848 and 5096 for the capture 8d8 and 50%, the capture
// ld6 and ajarge for the djvu 1d6 and a large). SEAMS: the R518 water-travel
// analog (the lava boats), the Monster Manual denizens (the fire giants, hell
// hounds, efreeti, salamanders, azer, elemental grue, lava children), the PHB
// feather fall/levitation/fly and the Wisdom Check, and the Plane of Fire
// lore. A ZERO-FLIP ROUND: the pp. 75-98 Deepearth child remains open until
// the setting lands in full (the R527/R533-R542 precedent - the gap report is
// NOT in the git add). Nothing auto-credits.
//
// A procedural-plus-prose round: no tables pin. The numbers pin as consts per
// the R508 convention - the eruption week, the cliff and ceiling feet, the
// outpost giants and hounds and guard minimum, the island race percentage,
// the invasion decades, the boat length bounds and width percentage and mast
// threshold and oar spacing, the harbor mouth and tower garrison, the torch
// percentage, the cavern diameter and height, the hole diameter, the stare
// rounds, the reinforcement percentage, the escape and passage rounds, the
// emergence percentage and the whirlpool draw feet, with the 1d6, 8d8 and 1d6
// dice pinned as count-sides const pairs. The geography, denizens, resources
// and unique-features prose pins as bools for both areas. The
// water-travel/MM/PHB seams are noted; the Deepearth child stays open;
// nothing auto-credits.
//
namespace rules {

// ---- the Area 20 Lava Caves section ----

// the lava caves shown on the map are a small portion of a huge underground
// expanse running many miles north and east; the displayed cavern is situated
// like a balcony overlooking a vast amphitheatre of fire and molten rock.
inline bool dnalBalconyCave()
    { return true; }

// the tunnel leading to this area is very hot with the same damage potential
// as the tunnel to Area 19, and characters in Area 20 stand about the same
// chance of sustaining damage as in Area 19.
inline bool dnalTunnelSameRisk()
    { return true; }

// the eruptions of smoke, fire and poison gas here are much less common than
// in Area 19 - perhaps one eruption per week.
inline int dnalEruptWeekDays()
    { return 7; }

// the cavern is a portion of a natural cave split by cataclysmic geological
// forces: fully half of the original cave has fallen away to the encroaching
// lava, and the remainder is baked brittle with a layer of smoky residue on
// all surfaces.
inline bool dnalHalfFallen()
    { return true; }

// the cave floor drops off to the northeast in a 400-foot cliff, with enough
// cracks and ledges to make climbing possible.
inline int dnalCliffFt()
    { return 400; }

// the cliff drops away to a sea of lava lit by a dull red hellish glow; crags
// jut like forlorn islands, far tunnels branch off, and stone columns rise to
// the ceiling supporting the massive weight above.
inline bool dnalSeaPanorama()
    { return true; }

// in most cases the stony ceiling is at least 1,000 feet above the surface of
// the lava sea.
inline int dnalCeilMinFt()
    { return 1000; }

// every day a few chunks of stone and earth break free and tumble into the
// inferno below, and ceiling fissures vent heat and smoke toward the surface
// mountain range.
inline bool dnalDailyChunks()
    { return true; }

// the lava surface is tossed by a series of swells like an ocean surface,
// caused by internal convulsions far beneath; the lava splashes against the
// containing cliffs like an angry sea at its shore.
inline bool dnalSeaSwells()
    { return true; }

// the balcony cavern is guarded by a large outpost of fire giants, one of the
// few avenues to the fiery lands; the denizens carefully control who travels
// here, and the entire force repels any intruders discovered.
inline bool dnalOutpostControl()
    { return true; }

// the fire giant outpost usually holds about 20 individuals.
inline int dnalOutpostGiants()
    { return 20; }

// the outpost giants are accompanied by a dozen hell hounds.
inline int dnalOutpostHounds()
    { return 12; }

// at least one giant and one hell hound guard the access tunnel at all times.
inline int dnalGuardMin()
    { return 1; }

// rock islands scattered among the liquid rock serve as lairs for additional
// bands of fire giants and groups of lava children - each island holds only
// one type, the two races preferring separate lairs though they do not
// usually fight.
inline bool dnalIslandLairs()
    { return true; }

// a given island lair has a 50% chance of either race, fire giants or lava
// children.
inline int dnalIslandRacePct()
    { return 50; }

// great numbers of magmen live in the lava sea, splashing through the molten
// rock like porpoises; a few occasionally climb to the balcony cave to dive
// back down, an activity the fire giants view with amused tolerance.
inline bool dnalMagmenSea()
    { return true; }

// many fire bats dwell in the vast cavern, clinging to the lofty ceiling or
// soaring through the scorching air as they travel across Deepearth.
inline bool dnalFireBatsDwell()
    { return true; }

// para-elementals of magma dwell within the molten rock - less common than
// the magmen but far more dangerous, forming in the hottest areas and
// reaching upward to attack anyone within reach; even the fire giants in
// their lava boats are not immune.
inline bool dnalMagmaPara()
    { return true; }

// the Area 21 elemental vortex is the source of would-be conquerors: fire
// elementals, efreeti, salamanders and lower-plane allies foray into the sea
// to wage war, and the lava children and fire giants join forces against the
// common enemy - spectacular battles of lava boat fleets, flying boulders and
// thousands of creatures; the denizens have always driven off the invaders,
// each foray made with more force than the one before.
inline bool dnalConquerorForays()
    { return true; }

// the elemental invasions occur about once every decade.
inline int dnalInvasionDecades()
    { return 10; }

// the only real resource of the area is heat, which is difficult to transport
// to where it might be needed.
inline bool dnalHeatOnly()
    { return true; }

// the fire giants have sculpted massive granite boats they row or sail across
// the fiery liquid - wide stone paddles like galley oars, sails of a
// mysterious heat-resistant perhaps magically treated cloth hoisted when
// gusts sweep the sea, and a stone tiller in the stern; a forceful gust
// pushes the clumsy Viking-longship-like boats along at surface-sailing clip.
inline bool dnalBoats()
    { return true; }

// the lava boats range in length from 80 feet (the low bound).
inline int dnalBoatLenLoFt()
    { return 80; }

// the lava boats range in length up to 240 feet (the high bound).
inline int dnalBoatLenHiFt()
    { return 240; }

// a lava boat has a width of about 20% of its length.
inline int dnalBoatWidthPct()
    { return 20; }

// boats longer than 160 feet are equipped with a pair of masts, while the
// shorter boats have only single masts.
inline int dnalMastThresholdFt()
    { return 160; }

// each boat has one pair of oars for every 40 feet of length.
inline int dnalOarsPerFt()
    { return 40; }

// on a large island several miles from the balcony cave resides the fire
// giant king: the entire island tunneled and carved into a massive castle
// with tall towers and a high wall meeting the lava on all sides but one,
// where a breach opens into a lava-filled harbor with stone docks.
inline bool dnalKingIsland()
    { return true; }

// the harbor entrance is only 120 feet wide.
inline int dnalHarborMouthFt()
    { return 120; }

// the harbor entrance is protected on each flank by a high tower manned by a
// dozen fire giants with a large supply of boulders to hurl at unwelcome
// intruders.
inline int dnalTowerGiants()
    { return 12; }

// ---- the Area 21 Elemental Vortex section ----

// water is nonexistent in this region; when it leaks into the area it turns
// instantly to steam.
inline bool dnalNoWater()
    { return true; }

// the air is usually breathable, and fresh air is sucked in through the
// entrance tunnel with a force capable of blowing out candles and unsheltered
// lanterns.
inline bool dnalWindForce()
    { return true; }

// the entrance-tunnel wind is 50% likely to extinguish a torch.
inline int dnalTorchOutPct()
    { return 50; }

// the region is reached by crossing the lava sea or through the tunnel from
// Area 18; it is uncomfortably hot, and characters approaching through the
// tunnel run the same damage risks as in the other linking passages of the
// area.
inline bool dnalVortexRegion()
    { return true; }

// the tunnel ends in a huge cavern 1,000 feet in diameter.
inline int dnalCavernDiaFt()
    { return 1000; }

// the vortex cavern is 300 feet high.
inline int dnalCavernHtFt()
    { return 300; }

// the cavern formed naturally, but tremendous heat has long since dried and
// rotted its once-fabulous cave formations; the heat here has the same effect
// on characters as in Areas 19 and 20.
inline bool dnalRottedFormations()
    { return true; }

// the cavern floor is smooth and flat except at the very center.
inline bool dnalFlatFloor()
    { return true; }

// at the center a perfectly circular hole 100 feet across drops to the
// unknown depths below, red and orange fingers of flame flickering around its
// circumference and occasionally flaring as high as the ceiling.
inline int dnalHoleDiaFt()
    { return 100; }

// any character staring down the hypnotically swirling hole for more than a
// single round must make a Wisdom Check.
inline int dnalStareRounds()
    { return 1; }

// if the Wisdom Check fails, the character is compelled to jump into the hole
// and journey to the Plane of Fire.
inline bool dnalHypnoticJump()
    { return true; }

// the cavern has no entrances or exits other than the tunnel from Area 18 and
// the hole in the floor.
inline bool dnalNoOtherExits()
    { return true; }

// the hole is not a pit to the lava sea that flows beneath: through
// tremendous heat, pressure and arcane force it has become a vortex to the
// Plane of Fire, through which creatures of that fiery region journey to the
// Prime Material Plane without being summoned, and properly protected Prime
// Plane creatures journey to the Plane of Fire.
inline bool dnalVortexGate()
    { return true; }

// the only denizens are those journeyed from the Plane of Fire, fortunately
// not ranging far; the flickering fingers of fire contain fire elementals of
// randomly determined size, which remain in or very near the vortex and
// combine forces to prevent Prime Plane creatures from entering it.
inline bool dnalElementalGuard()
    { return true; }

// the fingers of fire around the vortex contain 1d6 fire elementals (the die
// count).
inline int dnalElementalDice()
    { return 1; }

// the vortex holds 1d6 fire elementals (the die sides).
inline int dnalElementalSides()
    { return 6; }

// there is an additional 50% chance that reinforcements immediately emerge
// from the vortex to battle invaders.
inline int dnalReinforcePct()
    { return 50; }

// the vortex reinforcements number 1d6 (the die count).
inline int dnalReinforceDice()
    { return 1; }

// the vortex reinforcements number 1d6 (the die sides).
inline int dnalReinforceSides()
    { return 6; }

// the reinforcements are efreeti, salamanders, azer, fire bats and elemental
// grue.
inline bool dnalReinforceRoster()
    { return true; }

// reinforcements are checked on the first round contact is made and every
// other round thereafter - the third, fifth, seventh, etc.
inline bool dnalReinforceCadence()
    { return true; }

// there is a minimum amount of breathable air in the chamber, and that is
// hot, dry and sulphurous; little else of value can be found here.
inline bool dnalSulphurAir()
    { return true; }

// any creatures entering the vortex who are not completely immune to fire
// suffer 8d8 of damage per round (the die count).
inline int dnalVortexDmgDice()
    { return 8; }

// the vortex passage deals 8d8 damage per round to non-immune creatures (the
// die sides).
inline int dnalVortexDmgSides()
    { return 8; }

// the vortex is an extraplanar location not subject to normal gravity:
// anything entering it descends as if under a feather fall spell.
inline bool dnalFeatherFall()
    { return true; }

// magic such as levitation or fly spells allows a character to reverse course
// and emerge from the vortex if cast within five rounds of entering.
inline bool dnalFlyReverse()
    { return true; }

// the levitation or fly escape window is five rounds after entering the
// vortex.
inline int dnalReverseRounds()
    { return 5; }

// after the escape window the character is committed to a journey to the
// Plane of Fire.
inline bool dnalCommitted()
    { return true; }

// the entire vortex passage requires 10 rounds.
inline int dnalPassageRounds()
    { return 10; }

// after the passage the character stands on a bleak volcanic landscape of
// eruptions, geysers and flowing lava, the vortex evident directly behind as
// a chute into the depths of a large volcano.
inline bool dnalPlaneArrival()
    { return true; }

// the vortex has two connections to the Prime Plane in roughly the same area
// - re-entering grants a 50% chance of emerging in Area 21 and a 50% chance
// in the lava sea; the lower vortex appears as a giant whirlpool of molten
// rock directly below the Area 21 one, and is the source of the elemental
// armies that attack the fire giants and lava children.
inline bool dnalTwoConnections()
    { return true; }

// anyone re-entering the vortex has a 50% chance of emerging in Area 21.
inline int dnalEmergePct()
    { return 50; }

// any lava boats venturing within 500 feet of the molten whirlpool are drawn
// in as if in water.
inline int dnalWhirlpoolDrawFt()
    { return 500; }

}   // namespace rules
