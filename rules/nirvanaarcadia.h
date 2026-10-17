// =========================================================================================
// Adnd1 - rules/nirvanaarcadia.h
// NIRVANA AND ARCADIA - printed pp. 84-87, the first two named planes in one
// round: the clockwork plane of ultimate Law with Primus and the modrons, and
// the orchard plane of law for the common good with its potion fruit, watch
// beasts and warrior Powers.
// census 501 -> 502.
//
// verified against printed pp. 84-87 of the uploaded motp.pdf OCR; the two
// planes ride together as the Law pair at the top of the wheel (the R572
// multi-plane pattern), each carrying its structure, portals, magic rules and
// Powers exactly as printed.
//
// the gap census after this round: 61 closed, 29 open - TWO boxes fall
// (Nirvana, Arcadia); the Seven Heavens and the Twin Paradises continue the
// Upper Planes next.
//
namespace rules {

// ---- the nirvana and arcadia pins ----

// the Nirvana clockwork: a single infinite plane filled with huge
// interlocking wheels like the cogs of an ornately carved clock - great
// platters of matter each 500 miles or more in radius, interlocking at their
// edges so the entire plane spins in unison; the void between disks is air,
// so flying is possible.
inline int ddgDiskRadiusMiles()
    { return 500; }

// the Nirvana float rule: each disk has its own gravity (toward the disk
// center, so one walks over the edge onto the far side); beyond any disk's
// pull a traveler floats as in the Astral, but a subtle tug from nearby
// realms pulls him within 1/100 turns (as printed) - usually only one side of
// a disk is inhabited.
inline int ddgRealmPullTurns()
    { return 100; }

// the Nirvana portals: circles light-green to Arcadia, deep red to Acheron,
// appearing regularly once per revolution of each disk (on Primus's plane
// every 20 days) and remaining open for a day; Primus is strict, and few
// Acheron warbands or Arcadian huntsmen get through - the Concordant
// Opposition portal is open at all times, on the underside of Primus's disk.
inline int ddgPortalCycleDays()
    { return 20; }

// the Arcadian trees: metallic bark (copper, gold, silver or iron), leaves
// that never fall, and fruit always available with magical powers - picked
// fruit lasts 1-10 days regardless of preservation and duplicates a
// DOUBLE-STRENGTH magical potion, the type rolled randomly (DMG or UA
// tables); each species grows only one type.
inline int ddgFruitSpoilDays()
    { return 10; }

// the Arcadian portals: few and permanent, marked by arched trellises of
// white ivory or black steel; passable normally, but 1 time in 10 the archway
// mists over into a color pool - white to the Seven Heavens, black to
// Concordant Opposition, silvery to Nirvana.
inline int ddgArchMistDenom()
    { return 10; }

// the archway sides rule: 90% of the time both sides of an Arcadian archway
// lead to the same portal on the other plane, but 10% of the time the two
// sides lead to different locations - and Prime portals sit at the center of
// a realm's topmost side, leading to planes where the realm's Powers are
// worshiped.
inline int ddgArchBothSidesPct()
    { return 90; }

// the Nirvana magic rule: all spells function normally EXCEPT illusions and
// phantasms - spells with illusionary or phantasmal components do not work in
// the plane of ultimate Law; at best they appear as thin wavy bits of smoke
// in the general shape of what was intended, fooling no one, least of all the
// natives.
inline bool ddgNirvanaNoIllusion()
    { return true; }

// Primus the One and Prime: the greatest of the modrons, dwelling (it is
// said) in a pool of energy at the center of the plane; most Astral silver
// pools and conduits open into his realm; base modrons serve throughout
// Nirvana's realms; he can send a beseeching traveler to Arcadia or Acheron,
// to the plane most akin to his alignment; when Anu travels, the temporary
// conduit Anu's Way bridges Nirvana and the Prime, and Marduk is summoned
// from Arcadia to mind his realm.
inline bool ddgPrimusDoctrine()
    { return true; }

// the Nirvana Powers: Anu the Babylonian judge (a 1,000-mile disk city,
// soldiers gilt in copper with pupilless yellow eyes, Anutu at his side);
// Shang-Ti the Jade Emperor (the Celestial Bureaucracy, Wang the
// transcendental doorkeeper, foo dogs and lions, ever-ripe peach trees -
// longevity as the potion, immortality for Powers - and the library of all
// lost Prime knowledge, collected by faceless grey-cloaked giants from doomed
// places); Shan-Hai Ching's watery wheel irrigating the peaches; the Indian
// trio Varuna, Rudra and Yama; Horus the Avenger with his hawk servants; and
// Utu the chaotic-good Sumerian sun god with Enki as his watcher, linked by a
// bridge of woven gold and crystal.
inline bool ddgNirvanaPantheon()
    { return true; }

// the Arcadian day: a great sphere set into the highest peak, half radiant
// and half black - Positive and Negative Material brought together without
// destruction or melding into shadow; its revolution matches a Prime day, but
// the Arcadian day is dawnless and duskless (light appears suddenly), split
// evenly between night and day.
inline bool ddgArcadiaDaySphere()
    { return true; }

// the Arcadian structure: three layers, the lower reaches unexplored; the
// uppermost layer is many well-organized realms sharing a common gravity -
// gentle showers, rainbow flowers in well-ordered untended patches, cities in
// geometrically perfect shapes, mountains unblemished by erosion.
inline bool ddgArcadiaLayers()
    { return true; }

// the Arcadian animals: golden foxes, coppery hares, silver-wooled sheep, and
// organized insects - peaceful, unaffected by Prime spells that touch their
// kind (as outer-planar natives), mute but with pupilless white eyes that
// pierce any illusion or phantasm - excellent watch beasts.
inline bool ddgArcadiaWatchBeasts()
    { return true; }

// the Arcadian militias: spirit-folk patrols (einheriar, Appendix III)
// hunting creatures that do not belong - good and lawful creatures are
// greeted and offered to ride along, neutrals are stiffly asked their
// business, evil and chaotic creatures are attacked; as natives the militias
// can use divination over the background static of the plane.
inline bool ddgArcadiaMilitia()
    { return true; }

// the Arcadian Powers: Marduk the Valiant (the Babylonian champion, city at
// the crossing of the rivers Kath and Laur, home of the kirdari warriors sent
// to aid his mythos, good regardless of Law-Chaos disposition, sole
// restriction against dragonkind); and Clanggedin Silverbeard (UA 110), the
// dwarven Father of Battle - a conical fortress mountain near the
// light-and-darkness sphere, his warriors forever practicing siegecraft
// against their own citadel, raids against the evil-dwarf and duergar hosts
// of Acheron, maximum damage at minimum risk, and good terms with Marduk; a
// barrier to Arcadia's second layer lies beneath his audience hall.
inline bool ddgArcadiaPowers()
    { return true; }

}   // namespace rules
