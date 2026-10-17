// =========================================================================================
// Adnd1 - rules/limbopandemonium.h
// LIMBO AND PANDEMONIUM - printed pp. 97-101, the first two Chaos planes in
// one round: the quicksilver chaos of the slaadi, the githzerai and the
// floating god-realms, and the howling dark tunnels of the four layers with
// Loki's crystal Hidden Realm and the desire-draining Manala.
// census 505 -> 506.
//
// verified against printed pp. 97-101 of the uploaded motp.pdf OCR; the two
// planes ride together as the pure-chaos and evil-chaos pair (the R578
// pattern), each carrying its tables, structure, portals and Powers exactly
// as printed; the Abyssal-layers terrain table (printed p. 101-102) is left
// for the Abyss round that owns it.
//
// the gap census after this round: 71 closed, 19 open - THREE boxes fall
// (Limbo, Pandemonium, the Limbo random-entry table); the Abyss opens the
// deep evil next.
//
namespace rules {

// ---- the limbo and pandemonium pins ----

// the Limbo layers: five reported, all the same swirling disarray - the
// barriers weaker than any other plane's, the realms of the Powers floating
// between layers at will; the ancient names: Gith and Slaad (first), Susanowo
// (second), Agni (third), Indra (fourth), the fifth the layer of the Lost
// Gods - though the named Powers are found on other layers, the distinctions
// breaking down in chaos supreme.
inline int ddkLimboLayerCount()
    { return 5; }

// the Limbo random-entry table (the report's box): 1-20 a safe breathable
// pocket, 21-40 liquid (drowning, 10% magma or acid), 41-60 a collapsing
// pocket (an earthquake spell), 61-80 solid matter (suffocation as elemental
// Earth), 81-89 heat source (1d10 d6s per round, save halves), 90-98 cold
// source (1d6 d8s per round plus suffocation as para-elemental Ice), 99-00
// beside a sentient's safe area (a githzerai, slaad or Creator Power to deal
// with).
inline int ddkEntrySafePct()
    { return 20; }

// the safe-zone radius by Intelligence: 0 none; 1-4 ten FEET per point; 5-10
// ten YARDS per point; 11-18 100 YARDS per point; 19+ one MILE per point -
// companions of at least one category lower Intelligence add one increment
// each (an 18-Int individual: 1,800 feet plus 100 per Intelligence-5-plus
// companion); no new matter, no reshaping - only coalescing chaos into usable
// form.
inline int ddkSafeZoneYardsPerInt()
    { return 100; }

// the Limbo created-matter rule: matter conjured outside a safe area is
// semi-permanent regardless of the spell's duration - 1d10 (10) hours before
// the chaos wears it away (a fireball burns 1d10 hours at full damage per
// round, a wall of stone crumbles); inside safe areas normal durations hold,
// but the clock starts when the area moves on.
inline int ddkChaosMatterHours()
    { return 10; }

// the Pandemonium noise: every word caught by the wind and flung through all
// four layers - conversation only by shouting, ineffective beyond 10 feet;
// holy word, the power words and shout fail beyond 10 feet; unprotected ears:
// deaf one round's exposure temporary, one turn's exposure PERMANENT; ear
// plugs negate, but the noise still mind-shatters.
inline int ddkPandemoniumShoutFeet()
    { return 10; }

// the Pandemonium wind: from a strong breeze to (10% chance per 10 turns) a
// gale lifting up to 100 lbs and carrying it 1d6 miles (4d6 landing damage,
// terrain-modified); natives immune; Cocytus's shriller layer forces a save
// vs. spell after one turn or 10d10 turns of insanity; Phlegethon halves all
// light radii and kills infravision; Agathion's bubble storms fling 400-lb
// creatures for 1d6 per round.
inline int ddkWindLiftPounds()
    { return 100; }

// the Limbo doctrine: chaos supreme at Nirvana's antipode - a quicksilver
// mish-mash of the primal forces (boulders, trees, whole landscapes in
// torrents of murky liquid, winds, fire-balls and glacier-remnants); gravity
// only on contact with solids (walk up walls; thrown objects fly until they
// strike; momentumless items hang in space); sentience settles the chaos -
// all beings except Powers must CONCENTRATE to hold safe zones (no
// spellcasting while holding), and emotion attacks (charm person, fear)
// collapse the borders onto the Random Entry table; those who control chaos
// well are the anarchs.
inline bool ddkLimboDoctrine()
    { return true; }

// the Limbo portals: pools, wells, doors, bottomless openings and archways on
// the first layer, calm centers in the circling storms - each sends travelers
// to Gladsheim, Concordant Opposition or Pandemonium at 33% apiece.
inline bool ddkLimboPortals()
    { return true; }

// the slaadi: natives evolved from the primal soup, messengers, warriors and
// servants of the Powers (their chaos often derailing missions); immune to
// the plane's chaos but NOT to spells (a slaad lounges in a hanging pocket of
// flame unharmed, but a fireball hurts it); bullied by the slaad lords
// Ssendam and Ygort (Lesser Powers) - Ssendam's golden castle at chaos's
// edge, Ygort's whirling interlaced spheres through all five layers, Ygort in
// the innermost.
inline bool ddkSlaadRule()
    { return true; }

// the githzerai: later arrivals, relative-peace with the slaadi, genocidal
// foes of the githyanki; citadels in the void, silver swords used to SEVER
// the cords of astral arrivals and maroon them; not above slaving; cities of
// 100-600, the greatest the Floating City (Citadel of Gith) sighted in all
// five layers with 10,000-plus souls under Zaarith Menyar-Ag-Gith, an
// immortal wizard-king (16th-level fighter, 23rd-level magic-user, a demi-god
// in Limbo); they mind bar against githyanki silver swords when astrally
// raiding.
inline bool ddkGithzeraiRule()
    { return true; }

// the Limbo spirit rule: arriving spirits are swept into the plane's matter
// (no manes, lanterns or einheriar), occasionally coalescing into CHAOS
// ELEMENTALS - 6d6 hit dice, abominable man-like piles with tentacles, horns
// or trunks, 1 damage per hit die once per round; not true elementals
// (outer-planar natives, beyond the control spells); invisible in native
// chaos, identifiable in controlled pockets.
inline bool ddkChaosElementalRule()
    { return true; }

// the Limbo Powers: Indra's Swarga (a spherical vault half-filled with
// enchanted milk, the island-or-tortoise abode, served by a hundred
// hundredfold chaotic faithful, moving between layers at will); Agni's sphere
// of purest flame fed by the infinite matter (intruders immolated unless the
// fire god protects them, ever-moving to avoid choking on its own smoke);
// Susanowo's salt-water vault (a thousand miles wide, storming at the god's
// will); Huan-Ti's smoke-realm with the unconsuming bamboo palace flames
// (water poured on them: 3d6 damage per GALLON of steam).
inline bool ddkLimboPowers()
    { return true; }

// the Pandemonium structure: the underground opposite of Gladsheim - a great
// mass pierced by innumerable wind-carved tunnels; gravity away from the
// cavern center (walls, floors and ceilings all walkable); rivers along the
// floors or straight down the middle through the air; no constant light
// (fires quickly extinguished, a lasting light seen for miles and attracting
// the dark-seers; infravision works but the underworld spirits radiate no
// heat); four layers - Pandeemos the habitable top (the Styx's tunnels, the
// cities and citadels), Cocytus the lamentation layer (shriller, tool-carved
// by unknown hands), Phlegethon the light-swallowing wet blackness, and
// Agathion the solid-rock deep dotted with spherical bubbles (the windstorms,
// the stale air or vacuum at 50/50, the prisons of what the Powers will not
// wake); barriers found by dead-end passages with strong wind, which carries
// loose items between layers.
inline bool ddkPandemoniumStructure()
    { return true; }

// the Pandemonium portals: flat squares in the cavern walls - yellow to
// Limbo, red to the Abyss, black to Concordant Opposition, but 20% misroute
// the traveler to one of the other two (50/50); no native life - immigrants,
// exiles and the marooned, the nameless demons, exiled demon lords, quasits
// and shadow demons in abundance.
inline bool ddkPandemoniumPortals()
    { return true; }

// the Pandemonium Powers: Loki's Hidden Realm (a glittering white-crystal
// palace lighting a thousand miles, his evil unrestrained far from the
// pantheon, served by evil einheriar, a portal at its heart skipping Limbo
// entirely to Jotenheim); Tuonela of Tuonetar and Tuoni (ringed by the
// crimson river Manala flowing to the Styx - drink or touch it and desire
// drains away, wasting to death without a save or a remove curse; the
// daughters include Kipu-tytto of Tarterus and Loviatar of Gehenna); Anshar
// the retired Babylonian supreme (a walled city with a citadel reaching the
// cavern center, served by spirits in archaic dress speaking dead tongues);
// and Hruggek of the bugbears (a fortress at the junction of wind tunnels,
// grisly trophies, merciless bugbear spirit-servants immune to enchantment
// and charm).
inline bool ddkPandemoniumPowers()
    { return true; }

}   // namespace rules
