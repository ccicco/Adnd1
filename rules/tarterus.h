// =========================================================================================
// Adnd1 - rules/tarterus.h
// TARTERUS - printed pp. 103-105, the six crimson-pearl layers between Hades
// and the Abyss: the flyable air-gulfs, the obelisk portals, the demodand
// shators, the trapped titans of Kronos, and the exile realms of Surma,
// Kiputyto and Grolantor.
// census 507 -> 508.
//
// verified against printed pp. 103-105 of the uploaded motp.pdf OCR; the six
// layers with their spacings and hazards, the obelisk-portal shapes, the
// demodand hierarchy and the titan exile history are pinned exactly as
// printed; Hades (pp. 105-107) is left for the round that owns it.
//
// the gap census after this round: 74 closed, 16 open - ONE box falls
// (Tarterus); the three grey Glooms of Hades open next.
//
namespace rules {

// ---- the tarterus pins ----

// the sixfold layers of Tarterus - a fell region inhabited by monsters and
// great evil beasts, home of many evil Powers in exile (such as the greater
// titans driven out of Olympus) and creatures planning their revenge; the
// layer names mostly titanish; the barriers sit at the lowest points of an
// orb (chasms, canyons, tunnels beneath the surface), each orb's barriers
// always leading to the same orb in the other layer - the layers nested
// spheres, one within the next; the fifth-to-sixth barriers are underwater,
// and any layers beyond the sixth are walled off beneath miles of ice.
inline int ddmTarterusLayerCount()
    { return 6; }

// the orb gaps by layer, the fourth the widest: Othrys about 100 miles
// between orbs (easily crossed), Cathrys 500 (smaller worlds), Minethys 5,000
// (hard winds in the airy gulfs), Colothys a half-million - about twice the
// Earth-Moon distance - and Porphatys millions; the gap between the worlds is
// filled with air, so travelers can fly from world to world in relative
// safety.
inline int ddmOrbGapColothysMiles()
    { return 500000; }

// the Cathrys acid: the second layer's overblown jungles and scarlet
// grasslands secrete a powerful acid that eats through metal in 1d10 rounds
// and delivers 1d6 points of damage to those in contact - natives, of course,
// immune.
inline int ddmCathrysAcidMetalRounds()
    { return 10; }

// the Minethys tornado: in the third layer's desert, windstorms born in the
// airy gulf sweep huge clouds of foul-smelling poisonous stinging dust across
// the land (effectively a permanent cloudkill) - and every 10 days a massive
// tornado sweeps the landscape, carrying any in its path to an adjacent orb
// or an orb on another string entirely.
inline int ddmMinethysTornadoDays()
    { return 10; }

// the Porphatys black snow: the fifth and wettest-but-one layer, great black
// clouds moving between the orbs laden with a demonic acidic snow - exposed
// skin caught in a snowstorm suffers 1d4 points of damage per round, the acid
// rots cloth in 10 rounds but has no effect on stone or metal; the snow
// sticks only on the topmost peaks, so the orb surfaces stand covered in 1d6
// feet of water, the fallen snow keeping its acidity (natives immune to all
// the layer's effects).
inline int ddmPorphatysSnowDamage()
    { return 4; }

// the peaks of Mount Othrys: on two particular close orbs of the first layer,
// a set of huge peaks 50 miles high each erupts from the marshy plains and
// links the worlds together - where the mountains meet, the titans hold their
// citadel, Mount Othrys, which names the orbs and the layer alike.
inline int ddmTitanPeakMiles()
    { return 50; }

// the Tarterus doctrine: the worlds laid out like strings of huge crimson
// pearls, each pearl the size of a Prime Material world; every surface gives
// off a dull reddish glow from its soil, like the phosphorescence of fire
// beetles, bathing all the layers in hellish light - yet no hotter than a
// summer's afternoon; unlike Prime globes the orbs do not spin, taking heat
// from the ground and light from the ground and the adjacent orbs; no day or
// night save at the wishes of particular realms' Powers; seasons and weather
// sweep the plane at random, heavy storms following clear sky, and the scarce
// plant life bursts into full flower after a storm only to wither within
// hours.
inline bool ddmTarterusDoctrine()
    { return true; }

// the Tarterus portals and travel: the portals of Othrys are obelisks, easily
// identified and usually guarded by demons or watch beasts, the destination
// read from the stone's shape - taller than wide leads to Hades, wider than
// tall to the Abyss, height equal to width to Concordant Opposition -
// transfer made by touching the obelisk; the river Styx also flows through
// the topmost layer, and on Othrys the Styx and innumerable other rivers
// cross every world, an easy passage from orb to orb without braving the
// gulf.
inline bool ddmTarterusPortals()
    { return true; }

// the demodands: Tarterus is the contested land between Hades and the Abyss,
// the demons (with numbers) and the daemons (with organization and planning)
// in a continual insurgency against whichever race tops a particular orb, the
// great princes not interfering - arcanadaemons and cambions often keeping
// both kinds in their households; rising above the struggle are the demodands
// (MMII), winged creatures mixing the worst features of demon and daemon, the
// most common of the Tarterian monsters - a shator (shaggy) demodand likely
// rules part of an orb with kelubar and farastu as servants, enslaving any
// living being they can; all are winged, spanning the gulfs between orbs
// without difficulty, with a sense of direction in the plane like the
// elementals in theirs; all but the most powerful demons and daemons make
// way.
inline bool ddmDemodandRule()
    { return true; }

// the Tarteran bestiary: achalera, nightmares, hordlings, shadow demons and
// mephits also make the layers home, and the vargouille are a common nuisance
// - rumored created by a powerful shator to plague his foes in other planes
// until they turned on their master and consumed him; all creatures native to
// the layers are immune to the plane's effects including the acid snow and
// the cold of the lower layers, while similar creatures from other planes
// remain subject (an Abyssal demon lord feels the cold unless otherwise
// protected).
inline bool ddmTarterusCreatures()
    { return true; }

// the titans of Othrys: the evil titans hold their citadel where the twin
// 50-mile peaks meet, ruled by Kronos - once master of Olympus, Hades and
// Tarterus before the coming of the Greek pantheon - with Coeus, Crius and
// Oceanus in his court (realms on orbs of the third, fourth and fifth layers,
// reachable only from Kronos's twin orbs); the upper layer was once linked by
// Mount Olympus to Hades' third layer, Olympus' first, and the Greek and
// titan Primes, and it was there the titans retreated upon defeat - the
// Olympians shattered the reaching mountain and trapped them; the outside
// titans have turned chaotic good, so only the spirits of the worst descend,
// and an attack would raise the ire of Hades, Hel, Anthraxus and the
// mobilized daemons and einherjar - so the titans wait and plan, seizing any
// travelers whose abilities, knowledge or items might aid the retaking of
// Olympus.
inline bool ddmKronosRule()
    { return true; }

// the Powers of Tarterus: far from the titan orbs, the adjacent realms of the
// Finnish Powers Surma and Kiputyto - gloomy marshes dark despite the red
// glow, cold from first orb to farthest; Surma's realm filled with open
// graves where undead walk freely, Kiputyto's carrying disease on the winds
// (gout, ulcers, the plague), neither receiving many visitors; and Grolantor,
// god of the hill giants, uncaring, dwelling among the fourth layer's
// infinite peaks and mighty chasms, rarely venturing forth - the shator
// demodands of the layers above cede him vassalage more from fear of the evil
// giant-spirit armies than any love.
inline bool ddmTarterusPowers()
    { return true; }

}   // namespace rules
