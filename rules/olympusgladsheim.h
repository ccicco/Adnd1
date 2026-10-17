// =========================================================================================
// Adnd1 - rules/olympusgladsheim.h
// OLYMPUS AND GLADSHEIM - printed pp. 92-97, the last two Upper Planes in one
// round: the Greek and elvish pantheons of the mountain plane with the
// Evergold pool and the crimson-disk portals, and the Norse earthberg rivers
// with the Bifrost, the wells, and the Asgard realm census.
// census 504 -> 505.
//
// verified against printed pp. 92-97 of the uploaded motp.pdf OCR; the two
// chaotic-good pantheon planes ride together as the final Upper pair (the
// R578 pattern), each carrying its layers, portals, creature rules and full
// Power census exactly as printed.
//
// the gap census after this round: 68 closed, 22 open - TWO boxes fall
// (Olympus, Gladsheim) and the Upper Planes ARE CLOSED; Limbo opens the Chaos
// side of the wheel next.
//
namespace rules {

// ---- the olympus and gladsheim pins ----

// the Olympus creature modifications (Olympus natives only, lost in other
// planes): creatures one size larger (small-to-medium, medium-to-large), AC 2
// better, claw-strikers +2 to hit, hit dice doubled for hit points and combat
// effects, and 1 in 20 human-like creatures (medusae, harpies) cast as
// magic-users of 1d10 level.
inline int ddjOlympusCreatureAcBonus()
    { return 2; }

// the Gladsheim wells: portals from Olympus, Limbo and Concordant Opposition
// appear in Asgard as wells - arrivals rise out, departures pass down;
// runemarked wells deliver to the indicated plane only 80% of the time, the
// other 20% dumping the traveler at a random location in either of the other
// two planes.
inline int ddjWellAccuracyPct()
    { return 80; }

// the Bifrost: Odin or Heimdall directs the trembling rainbow bridge to any
// Prime Material plane (a rainbow rising to a cloud holding a conduit's
// earthy end); 10 yards wide (widenable at will), ALL magical abilities of
// beings and items are lost on the bridge except those of Powers and
// artifacts; the Gladsheim end is fixed between the plains of Ida and Vigrid
// under Himinbjorg and Heimdall.
inline int ddjBifrostWidthYards()
    { return 10; }

// the Yggdrasil span: Gladsheim is the World Ash's topmost point (roots in
// Hades' second layer Niflheim, branches touching every Norse-worshiping
// Prime); physically climbing Prime-to-Asgard should take at least 100 days
// and has never been successfully attempted; the tree hosts giant stags,
// giant eagle nests, and the squirrel Ratatosk carrying threats between
// dragons and eagle.
inline int ddjGladsheimTransitDays()
    { return 100; }

// the Gladsheim giants: smarter than their Prime brethren - 1 in 4 is an
// illusionist of up to 14th level, 1 in 10 a magic-user of up to 20th, 1 in
// 20 a cleric of up to 20th (Utgard-Loki both cleric and illusionist at
// 14th); giant-sized magical items equipped as an adventuring party of those
// levels; their illusions can affect the gods themselves, though never
// killing a Greater Power in his home plane.
inline int ddjGiantIllusionistDiv()
    { return 4; }

// the Olympus structure: three layers - Olympus/Arvandor the topmost (the
// Greek and elvish pantheons' realms separated by a few thousand miles of
// wilderlands, steep mountains, hillocks the size of Prime mountains, the
// layer slightly convex so neither citadel sees the other); Ossa/Aquallor the
// watery second (the Oceanus outflow from Thalasia, seas mostly three feet
// deep, chasms holding the other chaotic good sea gods); Pallon/Mithardir the
// dusty third (blowing white sand and snow over everything, buried realms and
// treasures of the departed powers); barriers rare, opening into the water
// domains; portals are spinning crimson disks, walled and gated by the
// Powers.
inline bool ddjOlympusStructure()
    { return true; }

// the Greek pantheon: short-tempered, lusty, partying, as chaotic as any save
// the Norse - yet twice a common front (defeating and casting the titans into
// Tartarus, and forging-or-inheriting Mount Olympus as the permanent
// conduit); Zeus's marble-and-gold citadel at the highest spot with Hera;
// Aphrodite's mirror-quartz palace, Apollo's sunlit domain, Ares's bone
// battlement and Athena's iron palace flanking the Mount Olympus portal,
// Dionysus's vine-heavy halls, Hermes's gambling den, Poseidon's bordering
// sea; the lesser powers (Artemis, Demeter, Nike, Tyche, Prometheus) hold
// realms larger than human nations.
inline bool ddjGreekPantheon()
    { return true; }

// the elvish pantheon (the Seldarine, less organized, more good and chaotic,
// competing for neither land nor followers with the Greeks): Corellon
// Larethian the sole Greater Power; Erevan illesere of mischief, Solonor
// Thelandira of forests and streams, Labelas Enoreth of longevity; Hanali
// Celanil's crystal palace holding the Evergold fountain (shared with
// Aphrodite, who pilgrimages yearly - the Greeks call the pool Canathas);
// Deep Bashelas's sea (through which the second-layer barrier is reached);
// Rillifane Rallathil the Leaflord, a tree whose roots reach the Primes
// through conduits; Aedrie Faenya wandering with 10d10 great birds; and
// Nephthys of the Egyptians in a lone dun-colored desert palace - all served
// by the Chosen, balanced male and female einheriar-like spirits.
inline bool ddjElvishPantheon()
    { return true; }

// the Gladsheim structure: reality breaks down at this end of the wheel -
// each layer is shifting rivers of earth, millions of miles wide, arching
// through empty space: earthbergs grinding and separating like ice blocks,
// chasms thousands of miles deep, undersides emitting radiant fire that
// bathes the realms in reddish glow (Powers modify light and weather into
// days and seasons - Asgard simulates gloomy northern Midgard); the three
// layers are Asgard (the great realm conglomeration around Yggdrasil, with
// Vanaheim, Alfheim and Jotenheim adjacent), Muspelheim (earthbergs reversed,
// flaming side up - Surtur's fire giants) and Nidavellir (densely packed
// rivers, luminous caverns opening and closing between trips).
inline bool ddjGladsheimStructure()
    { return true; }

// the Gladsheim magic rule: the standard outer-plane limits, plus the Norse
// bravery doctrine - beneficial necromantic spells are for cowards and DO NOT
// function in Asgard or Vanaheim (Jotenheim and Alfheim's Powers are more
// practical); lingering viewing portals near Loki or Odin risk being yanked
// into the plane by the irritated god.
inline bool ddjGladsheimNecroBan()
    { return true; }

// the Norse pantheon: might-makes-right tempered with beneficence, a wild lot
// despite the clerics' claims - the realm census: Gladsheim or Mount Joy (the
// levelled peak, the feast-hall of aesir and vanir where fealty is sworn),
// Valaskialf (Odinhome, the all-seeing throne Hildskialf), Thrudheim and the
// iron-shod Bilskirnir (Thor and Sif, the joyous thralls, sons Magni and
// Modi), Fensalir in Vingolf (Frigga), Breidablik (Balder's beauty),
// Himinbjorg (Heimdall's mirrored-steel redoubt manned by einheriar and
// valkyrie), Ydalir (Uller's yew groves), Landvidi (Vidar), Gilmir and
// Forseti's justice, Loki's bolt-holes in Jotenheim and Pandemonium, Idun's
// apple orchards (her husband Bragi dwelling in far Elysium), Tyr in
// Valhalla, and Aegir the giant-relative wanderer.
inline bool ddjNorsePantheon()
    { return true; }

// the Gladsheim creatures: the standard upper-plane host avoids the plane -
// only the hollyphant and planetar are frequent - but Scandinavian and
// Germanic beasts and monsters abound (bears, wild boars, giants, stags) with
// the same modifications as Olympus (AC 2 better, claws +2, doubled hit dice,
// the 1-in-20 human-like casters); the giants carry the
// illusionist/magic-user/cleric chances of their own.
inline bool ddjGladsheimCreatures()
    { return true; }

}   // namespace rules
