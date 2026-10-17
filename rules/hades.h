// =========================================================================================
// Adnd1 - rules/hades.h
// HADES - printed pp. 105-107, the three grey Glooms of the evil-between:
// Oinos the diseased, Niflheim the mist-bound, Pluton the grove of Persephone
// - with the color fade and the larva trap, the coin portals, Anthraxus's
// Khin-Oin, the jailers turned prisoners, and the Powers from Hel and Nidhogg
// to Nergal, Abbathor and Yurtrus.
// census 508 -> 509.
//
// verified against printed pp. 105-107 of the uploaded motp.pdf OCR; the
// three layers, the fade-and-trap rules, the portal coins, the daemon
// politics and the realm census are pinned exactly as printed (the orc
// death-god rendered Yurtrus and the Norse as Niflheim against the OCR
// slips); Gehenna (pp. 107-109) is left for the round that owns it.
//
// the gap census after this round: 75 closed, 15 open - ONE box falls
// (Hades); the fourfold furnaces of Gehenna open next.
//
namespace rules {

// ---- the hades pins ----

// the three Glooms of Hades, named for their chief inhabitants: Oinos (the
// daemons' layer, taking its name from Anthraxus's title as lord of the
// middle planes, the Oinodaemon), Niflheim (the Norse layer reached by the
// Yggdrasil), and Pluton (also called Hades, the Greek underworld proper).
inline int ddnHadesLayerCount()
    { return 3; }

// the Oinos disease: the first layer is a sickly land of stunted withered
// plants, foliage and rocky terrain in muted greys stretching to the horizon
// - those who walk its surface, or sail the Styx as it passes through, have a
// 10% chance of contracting a major disease.
inline int ddnOinosDiseasePct()
    { return 10; }

// the Niflheim mists: the second layer is richer in vegetation and cooler
// than Oinos without the touch of sickness, its terrain rough and cloaked
// with pines - but vision beyond 100 feet is blocked by the mists and fogs
// that swirl through the plane.
inline int ddnNiflheimVisionFeet()
    { return 100; }

// the Hades trap: the evil of the plane infects the long-staying with
// defeatism and sadness - colors fade until the most vibrant blues and reds
// are muted after one week and reduced to shades of grey by the end of two;
// travelers who remain longer than two weeks must roll successful saving
// throws vs. spell or be permanently trapped, their existence fading over the
// next month until they become larvae (rescuable only by another traveler
// pulling them out, or by a wish or related spell).
inline int ddnLarvaSaveWeeks()
    { return 2; }

// the Khin-Oin, the Wasting Tower: Anthraxus's realm is a mighty fortress of
// grey stone battlements laced with crenellations and studded with towers and
// minor citadels, towering 20 miles in height with dungeons burrowing a
// similar distance below ground.
inline int ddnKhinOinMiles()
    { return 20; }

// the Nergaltos dome saves: at each of the seven nested gates of Nergal's
// circular city the traveler must save vs. spell or suffer the
// trapped-in-Hades effect, each dome applying a cumulative -2 penalty to the
// save - by the seventh dome the penalty is -14, so potent that Powers such
// as Ishtar have been trapped in his domain.
inline int ddnNergalDomePenalty()
    { return 2; }

// the Hades doctrine: the plane of evil balanced between Law and Chaos, one
// of the most accessible of the lower planes - the midpoint of the Styx
// linking the lower planes in a river of evil, the foundation of Mount
// Olympus reaching the Greek pantheon, and the base of the Yggdrasil reaching
// Gladsheim, both great trees touching the lower layers; the Glooms are
// realms without joy or emotion, without hope or peace, without good will - a
// grey land under a grey sky where only muted blacks and whites belong, with
// neither sun, moon, stars, nor passing seasons, merely a state of waiting
// with no end in sight; viewing pools from the Astral work normally on the
// upper layer (why Hades and Hel keep their realms below), leaving the top to
// a variety of Powers, one of them the Oinodaemon.
inline bool ddnHadesDoctrine()
    { return true; }

// the Hades portals and barriers: the standard portals reach the top layer,
// appearing as great spinning coins - copper to Gehenna, silver to Concordant
// Opposition, gold to Tarterus - their brightness visible for miles, often
// enclosed by the red iron fortresses arcanadaemons build to control traffic;
// the barriers between the layers are tightly controlled, the main
// Oinos-to-Niflheim barrier leading to the roots of the Yggdrasil in full
// view of Hel's feast hall, and the major passable Niflheim-to-Pluton barrier
// leading to the grove of Persephone and the gates of Hades with its guardian
// Cerberus - other barriers may exist, unrevealed, for Hades and Hel keep
// their infinite realms as quiet and controlled as possible.
inline bool ddnHadesPortals()
    { return true; }

// the daemons of Hades: ruled at least in theory by Anthraxus, though the
// bird-like diakk and the misshapen hordlings both outnumber the daemons, the
// deeper layers' Powers severely limiting these lesser creatures; the greater
// daemons' domains hold diakk and hordlings as servants, an occasional
// demodand likewise; the demodands and daemons wage a sniping war of small
// skirmishes and assassinations, avoiding the large-scale violence that might
// attract the Greater Powers - while at the Khin-Oin the diseased great
// daemons plot against Anthraxus in continual hall-battles, uniting into a
// restless common front only against an outside Power or invader, and
// unbeatable then: no other group has ever stormed or besieged the Wasting
// Tower successfully.
inline bool ddnDaemonRule()
    { return true; }

// the larvae and the night hags: nightmares and mephits also haunt the layers
// alongside the hags, who live exclusive lives and meddle in local politics
// only when necessary; the hags are chiefly interested in Hades' larvae - the
// human-headed worm-spirits found throughout the layers - for the larvae are
// a medium of exchange in the lower planes, and the night hags gather as many
// as they can.
inline bool ddnLarvaRule()
    { return true; }

// the jailer doctrine: many of the Powers of Hades were once beings of Law
// and justice assigned to guard against the evil dead in this land - the
// millennial exposure to the plane has turned them to the grey evil as well,
// so they are both the jailers and the prisoners of Hades; only those of
// greater godly status can wander the Astral or visit other planes.
inline bool ddnJailerRule()
    { return true; }

// the Powers of the Glooms: Hades of Pluton, the most powerful of the plane
// yet touched by its grey sorrow - his realm walled around the grove of
// Persephone where Mount Olympus has its base and passes into the Astral, the
// grove filled with black willows and a single white laurel, the gates
// massive structures of beaten bronze dented by heroes who over the ages
// assaulted the underworld's lord; at the gates the kennel of the
// three-headed Cerberus, who keeps the unwanted out and the inhabitants in -
// he may be slain but returns to life by the wish of Hades - and the evil
// Olympian beasts within carrying ability modifications like those of
// Olympus; Hel of Niflheim, likewise assigned to guard the dead and fallen to
// the grey despair - her domain like Valhalla save for the omnipresent grey
// and the lack of valkyries, served by her own evil, grey-armored einherjar,
// wild creatures like Gladsheim's roaming the borders; at the Yggdrasil's
// base Nidhogg, a huge very ancient red dragon with 10 points per hit die and
// her innumerable brood, tasked to gnaw the roots of the World Ash and cut
// the link from Niflheim to Asgard - the ash sets down new roots even as she
// consumes them, and though slain, within a year one of her brood grows to
// her size and power and resumes the mantle; Nergal the Babylonian keeper of
// the dead on Oinos, ruling a wide but finite swath from Nergaltos, the
// circular city of seven nested arched domes, each dome pierced by a single
// gate, viewing portals unable to pass the gates without his permission, the
// city peopled by soldiers like Anu's warriors but evil, the centermost domes
// holding the forgotten Powers whom Marduk and his pantheon defeated and
// brought to him; the Indian demigoddess of night, thieves and robbers with
// no permanent abode, layer to layer, living off what she steals from the
// Greater Powers - an unwelcome guest in the courts of Hades and Hel,
// dominating the daemons and demodands she encounters; Abbathor of the evil
// greedy dwarves in the Glitterhell, a deep cavern complex said to hold a
// barrier into Niflheim at its deepest point - lined with gold that sparkles
// even in the grey, kept moving and immune to the plane's malaise by his own
// lust and greed, its true location unknown behind several false ones; and
// silent Yurtrus of the orcs, the orc god of death, whose realm on Oinos is
// dreary even by Hades's standards - all plants die before its borders, only
// Yurtrus and his equally silent ones exist there, and even the daemons cross
// that terrain carefully.
inline bool ddnHadesPowers()
    { return true; }

}   // namespace rules
