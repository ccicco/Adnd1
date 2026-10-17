// =========================================================================================
// Adnd1 - rules/dsgarea9.h
// THE DSG DEEPEARTH AREAS 18-19, R542: printed pp. 90-91 (pdf 91-92) - the
// individual area key crosses the volcanic belt: Area 18 the Steam-Heated
// Caverns (the water-eroded cavern region altered by volcanic upheavals, its
// sharp fissures tapped into the caves; the meandering river from the Lower
// Lake reaching a connecting cavern five miles south, the source of a rapid
// hot stream that joins the river as the riverbed descends; the wide
// fine-sand shoreline landing for boats; the artificially expanded,
// straightened chute tunnel racing hot water into the river; the six large
// caves joined by narrow passages, steamy air, coated rock, boiling-to-cool
// pools and the slippery mildew; the north tunnel to Area 21 with its
// once-an-hour superheated blasts, 2% per round cumulative, 4d6 halved on a
// breath save; the east-tunnel stream inflicting 4d6 per round; the Plane of
// Fire spillover - efreet, fire elementals, salamanders, fire bats; the hell
// hounds, rats, green slime, crawlers and megalo centipedes; the fire giants
// holding sway, their nomadic clan numbering over 50; the half-usual fatigue
// in the muggy air; and the geysers - a 20% pool susceptibility, 6d6 halved
// on a save), and Area 19 the Chambers of Fire (the caves baked by the
// geothermal sources; the swept-clean approach tunnel at 1d6 per turn,
// dousing to avoid; the roughly circular caverns split by thousands-of-feet
// floor fissures belching smoke, poison gas, steam and fire once per hour at
// 25% per type for 1d6 rounds; the dangerous cave heat at 1d6 per round,
// halved by dousing; the eruption volley - 6d6 per round from steam or fire
// halved on a breath save, poison gas save-or-die, 1d4 turns of smoke at the
// page 36 effects; the slender stone arches at 50% over the 3d6-foot
// fissures; the four mephit forms at 50% after the matching eruption; the
// common fire bats; the diving magmen; the breathable but smoky air and the
// mildew; and the remote cavern where the toiling mephits widen the 20-foot
// fissure with their fireproof pickaxes, 21-40 of them entering per eruption,
// throwing intruders in as offerings to bring through a monstrously evil
// creature of the dark lower planes).
// census 465 -> 466.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~11485-11685) with the pdf Acrobat-Capture layer as the second read (idx
// 206 and 208 = the printed pp. 90-91 windows); the compiled-tables appendix
// has no reprint of this prose. A CLEAN-READ ROUND: both machine reads agree
// on every load-bearing number - the five-mile junction, the six caves, the
// 2%-cumulative blast with its 4d6, the 4d6 stream, the 50-giant clan, the
// 20%/6d6 geysers, the 1d6-per-turn tunnel, the 25% eruption types lasting
// 1d6 rounds, the 1d6-per-round caves, the 6d6 steam-or-fire, the 1d4-turn
// smoke, the 50% arches over the 3d6-foot fissures, the four mephit forms at
// 50%, and the 21-40 (1d20+20) toiling mephits widening the 20-foot fissure;
// the only garbles settled cross-read (the djvu 296 and 346-foot garbles for
// the capture 2% and 3d6, the capture ld6/ld4/ld20+20 for the djvu 1d6 and
// 1d4 and 1d20+20). SEAMS: the R518 water travel (the river junction and the
// chute), the Monster Manual denizens (the efreet, salamanders, hell hounds,
// fire giants, mephits, magmen and lava children to come in Area 20), the PHB
// fire resistance and breath saves, and the page 36 smoke rules. A ZERO-FLIP
// ROUND: the pp. 75-98 Deepearth child remains open until the setting lands
// in full (the R527/R533-R541 precedent - the gap report is NOT in the git
// add). Nothing auto-credits.
//
// A procedural-plus-prose round: no tables pin. The numbers pin as consts per
// the R508 convention - the junction miles, the cave count, the blast base
// and step percentages, the dice of the blast, stream and geyser damage, the
// giant clan size, the fatigue divisor, the geyser pool percentage, the
// tunnel and cave damage dice, the eruption type percentage and rounds, the
// eruption damage dice, the smoke turns, the arch percentage, the fissure
// width dice, the mephit forms and follow percentage, and the toiling-mephit
// count with its sides and base and the 20-foot fissure width, with the 4d6,
// 6d6, 1d6, 1d4, 3d6 and 1d20+20 dice pinned as count-sides(-multiplier/base)
// const pairs or triples. The geography, denizens, resources and
// unique-features prose pins as bools for both areas. The water-travel/MM/PHB
// seams are noted; the Deepearth child stays open; nothing auto-credits.
//
namespace rules {

// ---- the Area 18 Steam-Heated section ----

// the meandering river from the Lower Lake reaches a connecting cavern about
// five miles south of the main chambers of this area.
inline int dnakRiverMeetMiles()
    { return 5; }

// the region formed by water erosion has been altered by major subterranean
// upheavals: fiery volcanic action in nearby sections of Deepearth created
// sharp fissures throughout the rock, and some of these cracks in the world
// tapped into the caverns.
inline bool dnakVolcanicFissures()
    { return true; }

// the connecting cavern is the source of a rapid stream of relatively hot
// water that joins the river.
inline bool dnakHotStreamJoin()
    { return true; }

// the river at this point picks up speed as the riverbed starts to descend
// more steeply.
inline bool dnakRiverDescends()
    { return true; }

// a wide shoreline coated with a beach of fine sand provides an easy landing
// for boat traffic.
inline bool dnakSandLanding()
    { return true; }

// the hot-stream tunnel, once a natural cavern, has been artificially
// expanded to handle an increased flow: its course straightened and its rate
// of descent increased, so that the hot water races down a veritable chute
// into the river.
inline bool dnakChuteTunnel()
    { return true; }

// the main area of caverns contains six large caves.
inline int dnakCaveCount()
    { return 6; }

// the six large caves are connected by several narrow passages.
inline bool dnakNarrowPassages()
    { return true; }

// the air is steamy and hot, and water coats all rock surfaces.
inline bool dnakSteamyAir()
    { return true; }

// large pools of water fill the low spots in many of the caverns, their
// temperatures ranging from boiling hot to relatively cool.
inline bool dnakPoolRange()
    { return true; }

// mildew on most of the rock surfaces makes everything extremely slippery.
inline bool dnakMildewSlip()
    { return true; }

// the north tunnel to Area 21 is subject to blasts of superheated air about
// once an hour: a 2% chance per round after a blast (the base chance).
inline int dnakBlastPctBase()
    { return 2; }

// the superheated-air chance is cumulative - 2% the first round after a
// blast, 4% the next round, 6% after that, etc. (the step).
inline int dnakBlastPctStep()
    { return 2; }

// characters in the north tunnel at the time of a blast sustain 4d6 points of
// damage (the die count).
inline int dnakBlastDmgDice()
    { return 4; }

// the superheated-air blast deals 4d6 damage to characters in the tunnel (the
// die sides).
inline int dnakBlastDmgSides()
    { return 6; }

// the blast damage can be saved vs. breath weapon for half, and normal fire
// resistance benefits might reduce it further.
inline bool dnakBlastSaveHalf()
    { return true; }

// the east-tunnel water inflicts 4d6 points of damage per round (the die
// count).
inline int dnakStreamDmgDice()
    { return 4; }

// the east-tunnel water inflicts 4d6 damage per round (the die sides).
inline int dnakStreamDmgSides()
    { return 6; }

// the east tunnel is the source of the outflowing stream, and the water there
// inflicts 4d6 points of damage per round with saves as above; characters
// only partly immersed take the damage reduced accordingly.
inline bool dnakStreamPartial()
    { return true; }

// a favorite haven for creatures who love fire and heat.
inline bool dnakFireHaven()
    { return true; }

// the Area 21 connection to the Elemental Plane of Fire has enabled creatures
// from that infernal place to proliferate.
inline bool dnakPlaneSpillover()
    { return true; }

// efreet, fire elementals, salamanders and fire bats from the Plane of Fire
// can be encountered here; hostile and aggressive, they are far enough from
// their escape routes that they will not hesitate to flee an encounter going
// badly.
inline bool dnakPlaneRefugees()
    { return true; }

// hell hounds, giant rats, green slime, carrion crawlers and even megalo
// centipedes have made these caverns their lairs and fight with normal
// tenacity.
inline bool dnakLesserLairs()
    { return true; }

// the fire giants hold sway over all the other denizens: occasionally
// accompanied by packs of hell hounds, they restlessly roam bullying the
// lesser creatures and slaying any who resist; nomadic though they claim the
// largest cavern as their lair.
inline bool dnakFireGiantSway()
    { return true; }

// when assembled, the clan of fire giants numbers over 50 individuals.
inline int dnakGiantClanOver()
    { return 50; }

// the muggy, oppressive air fatigues characters unused to the environment in
// half the usual time.
inline bool dnakSteamFatigue()
    { return true; }

// the fatigue time divisor: unused characters become fatigued in half the
// usual time.
inline int dnakFatigueDiv()
    { return 2; }

// water is plentiful and food in the form of fungi is abundant, but no
// mineral wealth has been located here.
inline bool dnakNoMinerals()
    { return true; }

// several caverns contain geysers capable of spouting scalding water and
// steam every bit as lethal as a red dragon's breath, and a number of narrow
// cracks and niches in the rock can issue such deadly blasts.
inline bool dnakGeysers()
    { return true; }

// a pool of water in this area is 20% likely to be susceptible to geyser
// activity.
inline int dnakGeyserPoolPct()
    { return 20; }

// characters caught in the force of one of these geothermal eruptions sustain
// 6d6 points of damage (the die count).
inline int dnakGeyserDmgDice()
    { return 6; }

// the geothermal eruption deals 6d6 damage (the die sides).
inline int dnakGeyserDmgSides()
    { return 6; }

// a saving throw vs. breath weapon reduces geyser damage to half, and fire
// resistant benefits can reduce it further.
inline bool dnakGeyserSaveHalf()
    { return true; }

// ---- the Area 19 Chambers of Fire section ----

// these caves are very close to the fiery geothermal heat sources that
// constantly bake this portion of Deepearth: formed by water erosion, they
// now quickly evaporate the small amount of water that flows into them.
inline bool dnakFireBaked()
    { return true; }

// the approach tunnel, once a natural cave with a sizable stream, has been
// swept clean by frequent blasts of tremendous heat and is devoid of cave
// formations.
inline bool dnakDryTunnel()
    { return true; }

// the approach tunnel is so hot that creatures not resistant to fire sustain
// 1d6 points of damage per turn (the die count).
inline int dnakTunnelDmgDice()
    { return 1; }

// the approach tunnel deals 1d6 damage per turn to non-resistant creatures
// (the die sides).
inline int dnakTunnelDmgSides()
    { return 6; }

// protective measures in the approach tunnel, such as frequently dousing with
// water, avoid the damage entirely.
inline bool dnakDouseAvoids()
    { return true; }

// the caves formed as a number of large, roughly circular caverns connected
// by an assortment of artificial and natural tunnels.
inline bool dnakCircularCaves()
    { return true; }

// each large cave is split by a few long, narrow fissures in the floor,
// thousands of feet deep.
inline bool dnakFloorFissures()
    { return true; }

// the fissures often belch out blistering clouds of smoke, poisonous gas,
// steam and fire, an average of once per hour in each cavern.
inline bool dnakFissureBelch()
    { return true; }

// an eruption of one of these substances occurs with a 25% chance for any
// given type.
inline int dnakEruptTypePct()
    { return 25; }

// the eruption lasts for 1d6 rounds (the die count).
inline int dnakEruptRoundsDice()
    { return 1; }

// the eruption lasts for 1d6 rounds (the die sides).
inline int dnakEruptRoundsSides()
    { return 6; }

// the average temperature in each cave is dangerously hot: creatures not
// resistant to fire suffer 1d6 points of damage per round (the die count).
inline int dnakCaveDmgDice()
    { return 1; }

// the cave heat deals 1d6 damage per round to non-resistant creatures (the
// die sides).
inline int dnakCaveDmgSides()
    { return 6; }

// protective measures such as water dousing reduce the per-round cave damage
// to half but do not eliminate it entirely.
inline bool dnakDouseHalves()
    { return true; }

// if an eruption occurs while characters are in the cave, mundane protective
// measures are of no avail.
inline bool dnakEruptNoAid()
    { return true; }

// the steam or fire eruption deals 6d6 damage per round (the die count).
inline int dnakEruptDmgDice()
    { return 6; }

// the steam or fire eruption deals 6d6 damage per round (the die sides).
inline int dnakEruptDmgSides()
    { return 6; }

// if steam or fire erupts, characters in the cavern sustain 6d6 points of
// damage per round, a save vs. breath weapon reducing this to half.
inline bool dnakEruptSaveHalf()
    { return true; }

// if poison gas erupts, a saving throw vs. poison is necessary to avoid
// death.
inline bool dnakPoisonDeath()
    { return true; }

// the smoke eruption fills the cave for 1d4 turns (the die count).
inline int dnakSmokeTurnsDice()
    { return 1; }

// the smoke eruption fills the cave for 1d4 turns (the die sides).
inline int dnakSmokeTurnsSides()
    { return 4; }

// smoke eruptions fill the cave for 1d4 turns, with the effects described on
// page 36 of the DSG.
inline bool dnakSmokeEffects()
    { return true; }

// there is a 50% chance that a given fissure is bridged in at least one spot
// by a slender stone arch.
inline int dnakArchPct()
    { return 50; }

// a given fissure is 3d6 feet wide (the die count).
inline int dnakFissureWideDice()
    { return 3; }

// a given fissure is 3d6 feet wide (the die sides).
inline int dnakFissureWideSides()
    { return 6; }

// most earthly creatures are unable to survive the fiery environment; three
// types of unearthly creatures reside in the area.
inline bool dnakUnearthlyOnly()
    { return true; }

// mephits, the most common denizens, are represented in all four of their
// forms: fire, lava, smoke and steam.
inline int dnakMephitForms()
    { return 4; }

// mephits are 50% likely to be encountered immediately following an eruption
// of the appropriate type.
inline int dnakMephitFollowPct()
    { return 50; }

// lava mephits are associated with poisonous gas eruptions for this purpose.
inline bool dnakLavaGasLink()
    { return true; }

// the mephits are generally sent to the Prime Plane to accomplish some
// fiendish or demonic purpose, but seem to frequent the area simply because
// they like it; they cheerfully attack earthly creatures, and only in the
// remote cavern do they pursue a goal.
inline bool dnakMephitPurpose()
    { return true; }

// fire bats are also common, flapping about and swooping adroitly into and
// out of the fissures; they extend their flights into the approaching caverns
// but do not remain away from their fiery heat sources for long.
inline bool dnakFireBatsCommon()
    { return true; }

// groups of magmen climb the sheer walls of the fissures from the furnaces
// below to joyously leap back down, plummeting thousands of feet into the
// molten rock; they spend several days per climb, eagerly ignite creatures
// and objects to gratify their sense of fun, and would enjoy persuading
// others into the diving game - so far they have found no takers.
inline bool dnakMagmenDive()
    { return true; }

// the air is smoky, smells bad and occasionally becomes poisonous, but a
// series of narrow ceiling fissures vents most of the foul air, so enough
// fresh air flows in to keep the atmosphere breathable.
inline bool dnakBadAir()
    { return true; }

// mildew has formed in some of the cooler out-of-the-way places - the only
// form of plant life in the area.
inline bool dnakMildewOnly()
    { return true; }

// in the most remote cavern the mephits delight in attacking intruders,
// dragging them to the largest fissure and throwing them in as offerings;
// they toil to widen it enough for a monstrously evil creature from one of
// the dark lower planes, and will continue for many years until they achieve
// their goal or a major catastrophe seals the fissure.
inline bool dnakMephitOfferings()
    { return true; }

// eruptions from the largest fissure bring 21-40 mephits (1d20 + 20) of the
// appropriate type with the first shock (the die count).
inline int dnakToilMephitDice()
    { return 1; }

// the toiling mephits number 1d20 + 20 (the die sides).
inline int dnakToilMephitSides()
    { return 20; }

// the toiling mephits number 1d20 + 20 (the base).
inline int dnakToilMephitBase()
    { return 20; }

// the mephits aggressively toil to widen the fissure from its current width
// of 20 feet.
inline int dnakFissureWideFt()
    { return 20; }

// the mephits chip away with an assortment of superhardened metal tools lying
// about the cavern - small pickaxes with stone handles and metal picks,
// completely impervious to fire.
inline bool dnakFireproofTools()
    { return true; }

}   // namespace rules
