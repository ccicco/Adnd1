// =========================================================================================
// Adnd1 - rules/gehenna.h
// GEHENNA - printed pp. 107-109, the fourfold furnaces of the lawful-evil
// slope: the baseless peakless mountains at 45 degrees, the Styx cascades of
// Khalas, Chamada's blinding cloud, the burning-snow avalanches of Mungoth,
// the dead furnaces of Krangath, the barghests of the exiles, and the sparse
// Powers - Chih-Chiang Fyu-Ya, Loviatar, and Shargaas the Night Lord.
// census 509 -> 510.
//
// verified against printed pp. 107-109 of the uploaded motp.pdf OCR; the four
// layers, the gravity and heat rules, the portal and barrier conventions and
// the Powers are pinned exactly as printed (the heat damage rendered 1d8 per
// turn against the OCR slip); the Nine Hells (pp. 109-113) are left for the
// round that owns them.
//
// the gap census after this round: 76 closed, 14 open - ONE box falls
// (Gehenna); the nine layers of the Hells open next.
//
namespace rules {

// ---- the gehenna pins ----

// the fourfold furnaces of Gehenna: Khalas the temperate top (nearest the
// Astral, where the Styx cascades), Chamada the violent volcanic second,
// Mungoth the cold third of ash and burning snow, and Krangath the dead
// furnaces, dark and heatless - four layers, each similar mountainous
// terrain.
inline int ddoGehennaLayerCount()
    { return 4; }

// the Gehenna gravity: the mountains have neither bases nor peaks, everything
// built onto or carved into their sides, and the gravity sits at 45 degrees
// to the level of the ground - a traveler who loses his footing tumbles for
// miles down the slope before stopping, and a tumbling traveler who strikes a
// solid object (a fortress wall) suffers damage as a normal fall from a
// height equal to the distance tumbled; the terrain varies from slippery to
// slightly slippery throughout the layers.
inline int ddoGravityDegrees()
    { return 45; }

// the Gehenna heat: it comes from the ground itself - vents, fumaroles and
// mud pots common, lava flows often running down the flanks, eruptions and
// earthquakes frequently ripping the land asunder - and the unprotected
// suffer 1d8 points of damage per turn, though devices and spells that negate
// the plane of elemental Fire work against it.
inline int ddoHeatDamage()
    { return 8; }

// the Chamada cloud: the second layer's lava flows in cascades thousands of
// miles wide, its erupting volcanoes wide enough to swallow whole cities, and
// the air within 10 miles of the surface is filled with an acrid cloud that
// inflicts blindness on unprotected eyes and acts as a permanent stinking
// cloud - those who cannot escape may spend the rest of their lives choking
// and coughing; beneath the surface the cloud is absent, but the smell of
// burning hair and flesh permeates even those depths.
inline int ddoChamadaCloudMiles()
    { return 10; }

// the barrier hazard: a 5% chance that any barrier leading to a deeper layer
// opens into a volcanic region (if into the second or third layer) or a
// sealed cavern without other escape (if in the fourth) - travelers should
// consider such occurrences when wandering Gehenna.
inline int ddoBarrierHazardPct()
    { return 5; }

// the Gehenna doctrine: smoky, burning realms where the ground provides light
// (like Tarterus's orbs) and heat, the ground often so hot that unprotected
// flammable items burst into flame; the mountains are without bases or peaks,
// everything built onto or carved into their sides, with the 45-degree
// gravity and the tumbling rule, and the terrain slippery throughout.
inline bool ddoGehennaDoctrine()
    { return true; }

// Khalas, the topmost layer: the most temperate, home to creatures and minor
// Powers including devils from the Nine Hells currently out of favor or in
// hiding; a region of waterfalls flowing down the slopes swathed in steam as
// the water evaporates from the ground's heat, the largest cascades those of
// the Styx, which follows a rough-hewn course down the mountainside, falling
// thousands of feet, twisting through rapids, then passing into the
// underground passages that lace Gehenna's interior; the sky reddish near the
// horizon, slowly fading to black toward the zenith.
inline bool ddoKhalasRule()
    { return true; }

// Mungoth and Krangath: the third layer is one of ash and burning snow, cold
// - its furnaces fewer and farther apart with ice and snow common on the
// volcanic edges, the greatest danger avalanches of wet snow mixed with
// burning rock, the sky darker for the lesser activity, the underground
// regions as comfortable as the layer gets; Krangath, the final layer, means
// the dead furnaces - whatever fires existed are long gone, sky and surface
// completely dark, no sources of heat or light even in the cavern complexes
// beneath the surface.
inline bool ddoMungothKrangathRule()
    { return true; }

// the Gehenna portals and barriers: the Styx flows through Khalas on its long
// journey among the lower planes, and Khalas is reachable from the Astral
// (color pools and viewing points) and from the Nine Hells, Hades, and
// Concordant Opposition; the interplanar portals always lie deep beneath the
// surface, appearing as black chasms in the floor with no formal
// identification, intelligent creatures usually marking the walls with the
// destination; the barriers between layers are likewise found beneath the
// furnaces, usually (though not always) in dead-end corridors - an
// arrangement that leads some sages to picture Gehenna as a four-sided
// pyramid, each layer one face, though this is only supposition.
inline bool ddoGehennaPortals()
    { return true; }

// the barghests and the exiles: Gehenna is overrun with creatures from
// adjacent lower planes - nightmares, imps, manes, daemons, mephits, lesser
// devils, and achalera - sneaking into the rocks, crannies and caverns to
// hide from more powerful beings elsewhere; the arch-devils and daemon
// masters found here are always the less-powerful types in disfavor with the
// ruler of an adjacent plane, and with resources and manpower low the
// extraplanar rulers let it stand as a plane of exile; the only true natives
// are the barghests, swarming through great rifts in the uppermost layer (in
// lesser numbers below), living solitary lives yet enslaving weaker beings to
// forge small empires and attack rivals - and because these battles are
// continual, and because barghests dread the next generation taking over
// their petty baronies, the young are raised on the Prime Material plane.
inline bool ddoBarghestRule()
    { return true; }

// the Powers of Gehenna: few reside here - the organizers are recruited into
// the hierarchies of the Nine Hells, the lawless drift to the grey evil of
// Hades; Chih-Chiang Fyu-Ya, a Chinese demi-power, holds a large region of
// the first layer from a teardrop-shaped citadel that parts the lava to
// either side, the demi-god enthroned at its highest point watching and
// waiting to be called to judgment, a great temple bell carved from a giant's
// skull hanging behind the throne so that when he is called its tolling
// sounds throughout the slopes of Gehenna; Loviatar, the Finnish mistress of
// pain, makes her home in the third layer - a fortress of ice protected by
// the mighty spells of her parents Tuonetar and Tuoni against the realm's hot
// spots, served by faithful creatures she rewards with cruelty and abuse, not
// a nice place to visit; and Shargaas of the orcs, who inhabits the depths
// beneath the layers of Gehenna - his followers call it the Night Land and
// him the Night Lord, all the deep caverns his, only Shargaas and his spirit
// servants (the most evil of his people) able to see within his domain; if
// there are planar barriers and deeper layers to Gehenna, only Shargaas knows
// of them.
inline bool ddoGehennaPowers()
    { return true; }

}   // namespace rules
