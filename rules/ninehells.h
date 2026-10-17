// =========================================================================================
// Adnd1 - rules/ninehells.h
// THE NINE HELLS - printed pp. 109-113, evil organized: the nine layers from
// Avernus the front parlor to the rifts of Nessus, the reddish-hoop portals
// and the Prime conduits, the home-layer immunity, the three factions of the
// arch-devils under Asmodeus the overlord, and the Powers from Tiamat and Set
// to Sekolah, Kurtulmak and No Cha.
// census 510 -> 511.
//
// verified against printed pp. 109-113 of the uploaded motp.pdf OCR; the nine
// layers with their rulers and hazards, the portal conventions, the
// arch-devil census and faction map, and the non-devil Powers are pinned
// exactly as printed (Belial restored against the OCR slip, and the dice
// rendered as the printed d6s and dice); Acheron (pp. 113-114) is left for
// the round that owns it.
//
// the gap census after this round: 77 closed, 13 open - ONE box falls (the
// Nine Hells); the iron-shod battle plains of Acheron open next.
//
namespace rules {

// ---- the nine hells pins ----

// the nine layers of the Hells, each infinite, extending forever in all
// directions; the barriers between layers always sit at the lowest point of
// the upper layer and at a very high point above the surface of the next
// below (the convenient mountain descents very rare and always guarded -
// otherwise the barrier exit hangs about a half-mile above the next layer,
// and the flightless fall for the 20d6 cap and the spectacular attention of
// the creatures below); the physical laws and properties of matter are
// constant within each layer but change from layer to layer.
inline int ddpHellsLayerCount()
    { return 9; }

// the Avernus fireball vapor: the front parlor's dark red starless sky over a
// rocky wasteland of stunted twisted plants, its atmosphere filled with
// flammable vapor gathered into innumerable dimly glowing spheres - a 1 in 6
// chance per turn that a glowing region bursts into a fireball (as the spell)
// for 2-7 dice of damage, reduced to 1 in 12 if the traveler refrains from
// open flame; the great rocky crags shelter greater devils astrally
// projecting, and Tiamat watches the parlor.
inline int ddpAvernusFireballChance()
    { return 6; }

// the Minauros disease: the third layer of the avaricious under Mammon, marsh
// and wet ground under continual rains, hail and sleet, the only solid land
// the hard volcanic ridges undulating like frozen serpents - the black-stone
// sinking city continually settling into the swamps, a barrier to Dis only 30
// feet above Mammon's palace roofs and carefully guarded, the surrounding
// ground rotten with decaying bodies that halve movement rates - and the most
// disease-ridden of the lower planes, a 13% chance per visit that an
// extraplanar traveler contracts a disease.
inline int ddpMinaurosDiseasePct()
    { return 13; }

// the Stygia ice: the fifth layer, a great frozen sea through which the Styx
// cuts a clear channel (losing its memory-robbing power here by dilution),
// eons of decayed moss and small plants producing a cold swamp atop an ice
// pack up to three miles in thickness floating on an ocean of limitless
// depth; the solid ground is the floating islands, from whose peaks lightning
// dances out of the jet black sky and walls of cold fire radiating 2d6 points
// of damage guard the barriers to the upper Hells.
inline int ddpStygiaIceMiles()
    { return 3; }

// the Malagard of Maladomini: the seventh layer, Baalzebul's home, a solid
// surface twisted and deformed by continual building and rebuilding - great
// quarries scarring the countryside, stone-walled aqueducts and canals
// carrying lava across the lifeless plains, malebranche fortresses and city
// ruins dotting the land; the only inhabited city is Malagard, a palace
// stretching a thousand miles and containing a million rooms, over a dungeon
// complex so vast the devils themselves are unaware of its full dimensions.
inline int ddpMalagardMiles()
    { return 1000; }

// the Caina cold: the eighth layer outdoes Stygia in heartless cold - a
// region of huge glaciers moving past mountains of slower-moving ice, snow
// and sleet continual companions, and travelers suffer the effects of -60
// degree weather (per the WSG) as long as they remain; the ruler is
// Mephistopheles.
inline int ddpCainaCold()
    { return 60; }

// the Nine Hells doctrine: the plane of evil organized to further its own
// malefic ends, dominating the imagination of travelers, the greed of
// treasure-seekers, and the battle-fury of paladins - the devils set in a
// rigid caste system amid large numbers of other evil creatures; the Hells
// are the most typical of the lower planes, so much so that the unknowing
// ascribe their environments to the other lower planes as well.
inline bool ddpHellsDoctrine()
    { return true; }

// the nine layers: Avernus the front parlor (Tiamat's lair of abishai and
// evil dragon spirits); Dis the Iron City rising miles over low hills and
// black stagnant rivers, the stone-and-lead inner sanctum of Dispater beyond
// its barriers, the flat barren land under a dull green overcast lit by
// lightning; Minauros Mammon's sinking city; Phlegethos the nightmare realm
// of volcanos and rivers of liquefied fire (entering one means the plane of
// elemental Fire), ruled by Belial from Abriymoch, the Mount of Leaping
// Flames, a basalt palace in a dead volcano whose tunnels are far larger than
// the outside allows; Stygia the frozen sea of Geryon's Tantlin; Malbolge the
// huge rockfall of city-sized angular black stones over a possible infinite
// lava sea, the copper-shod fortresses of Moloch the viceroy of Baalzebul
// beneath blood-red steam clouds; Maladomini of Baalzebul and Malagard; Caina
// the glacier layer of Mephistopheles; and Nessus, the final level - a series
// of vast rifts each leading lower to the grand palace of Hell's Overlord
// Asmodeus, dwarfing even the Khin-Oin, resting on the banks of a great
// shifting lake of ice fed by the river Lethe, a land of extremes: the
// coldest regions, the hottest volcanos, the steepest and smoothest cliffs,
// and waves of fire as triple-strength walls sweeping the region and turning
// everything in their path to ash - a recommended stop only in the most dire
// of needs.
inline bool ddpNineLayersRule()
    { return true; }

// the paths in and out of the Hells: the Styx runs through Avernus and into
// Stygia with Charon and his charonadaemons ferrying the foolish; the Lethe
// runs through Nessus, said to link to certain Prime Material planes as the
// Yggdrasil and Olympus link theirs (unknown whether it does) - its black
// waters work as the Styx but Charon and his servants never appear on its
// shores; Avernus holds portals to the topmost layers of Acheron and Gehenna
// and to the outer rings of Concordant Opposition, identical free-standing
// hoops of reddish light that Tiamat guards with abishai encampments and
// traps; a large number of conduits lead to Prime Material planes so the
// dukes and archdukes can vie for control of evil across the alternates -
// squabbling that spells the doom of evil plans, for evil always turns upon
// itself; and in the heart of Asmodeus's palace a rumored conduit older than
// any overlord that destroys all evil that touches it, even the mightiest
// arch-devil or demon prince - destination unknown, the foundation of the
// stories that the best escape from the Hells is to journey to the lowest
// layer.
inline bool ddpHellsPortals()
    { return true; }

// the devil rule: devikind the most prominent inhabitants, sharing the plane
// with many other evil creatures (the Monster Manual II devil entry the
// summary of frequencies by layer); all creatures native to the Nine Hells
// are unaffected by the natural forces of their native layer - the ice devil
// of Caina immune to all magical and natural cold, but only while in Caina -
// a home advantage that tends to prevent attacks by devils from other layers;
// the arch-devils are a group of powerful devils, treated as lesser gods in
// their home plane, dedicated to the defeat of good and their own supremacy
// over all the known planes - a unified force that could pose a great
// problem, except that each is convinced that he (or she) alone is the most
// capable leader of the diabolic forces: the desire to rule in Hell always
// outweighs any advantage from defeating the forces of good (devils contest
// with Odin, but no devil sees himself taking Odin's position in Gladsheim),
// and all see themselves as contenders for the Overlord's throne - the
// battling more subtle than the roaring wars of the Oinodaemon's halls, but
// endless in the pits nonetheless.
inline bool ddpDevilRule()
    { return true; }

// the arch-devil census and politics: Asmodeus the overlord ruling from the
// great palace in Nessus's lowest rift, his household and staff not fully
// described, to his liking; Mephistopheles in the iron citadel of Mephistar
// overlooking the great glacier Nargus, Hutinin his chief duke; Baalzebul,
// the second-most powerful, in Malagard's maze of towers walls and dungeons
// jammed with treasure and never-thrown-out debris; Moloch, Baalzebul's
// vassal denied a permanent home, moving location to location across
// Malbolge; Geryon's castle Tantlin rising from the Stygian ice, Armon his
// chief assistant; Belial's basalt Abriymoch in a dead volcano's cone; Mammon
// in the stinking sinking Minauros, served by Bael his chief commander and
// Glasya his chief consort, one of the more powerful diabolic members of the
// Hells; Dispater's stone tower in the heart of Dis, gathering information
// from his erinyes in the highest towers and dictating to Titivilus his
// trusted messenger; Tiamat's cavernous Avernus lair of abishai and evil
// dragon spirits sent to lay low the challengers. Politically three opposing
// groups: Asmodeus commands the unswerving loyalty of Geryon and Tiamat
// (layers 1, 5 and 9); Baalzebul with Moloch his stated vassal recruiting
// Belial, whose rivalry with Geryon is unbounded (layers 4, 6 and 7);
// Mephistopheles the would-be force of reason and restraint with Dispater and
// the ever-greedy Mammon (layers 2, 3 and 8). Asmodeus seems weakest but
// holds the overlord's control: his rivals cannot depend on their factions
// (members defy Asmodeus only when victory is certain, arch-devils quickly
// turn on erstwhile allies for gain), the faction not revolting automatically
// sides with him hoping for spoils, and he plays one against the other, never
// letting his dukes know where they stand - plus his control of both ends of
// the Hells through Tiamat, underrated by her compatriots as a dumb beast.
inline bool ddpArchdevilPolitics()
    { return true; }

// the non-devil Powers of the Hells: the organized realms are vast but the
// layers infinite, home to other Powers - the true relationship between
// lawful evil Powers and devils unknown, each world ignorant of the other's
// rivals (Tiamat as Takhisis never lets her Krynn followers know there are
// other arch-devils or a Nine Hells at all, and Asmodeus keeps the Druagas
// and Sets of the multiverse unknown to his own); Druaga, the self-titled
// Ruler of the Devil World, a Babylonian lesser Power with a realm on the
// second layer far from Dis's hills, tolerating and tolerated by Dispater,
// who may provide the devils Druaga sends forth; Set of the Egyptians, whose
// single-minded vengeance against Osiris, Horus and the pantheon exceeds even
// Loki's hatred of Gladsheim, accepting no equals - too weak to be driven
// from the Hells but not strong enough to have come, he controls a large
// swath of Avernus lit by a blazing sun and bone-dry as the desert, his great
// white-stone palace overseeing captives erecting a massive pyramid he hopes
// will fill his layer and create his own set of planes between the Hells and
// Acheron - dangerously close to a mad god; Hecate of the Greeks and Inanna
// of the Sumerians with adjacent realms in Phlegethos and conduits to their
// worshiping worlds - Hecate more lawful than evil, sending her devil quota
// out in organized fashion to punish particular misdeeds, Inanna more evil
// than lawful, delighting in the fickle blessings of too many or not enough
// servants in battle, both indifferent to their organized neighbors, both
// courts called on by Belial, both feared by Asmodeus (who would rather cut
// off a limb than see the Greek and Sumerian pantheons descend on his
// delicate balance); Sekolah, the great white shark of the sahuagin, abiding
// in Stygia's deep oceans far beneath the ice pack, dining on giant
// sea-beasts and known to surface to converse with - and often devour -
// Geryon's ambassadors to the monarch of the deep; Kurtulmak of the kobolds
// in the first layer's caverns, careful to stay out of the way, courted by
// arch-dukes as one more ally, smiling graciously, taking all aid, and
// robbing the arch-devils blind while maintaining his front - rarely
// admitting to his followers that his Hells have any other major inhabitants;
// No Cha of the Chinese, a demi-god with no set address like Ratri in the
// glooms of Hades, invoked by thieves and robbers for nocturnal luck, always
// moving, stealing from one devil group and seeking sanctuary with another,
// smart enough not to steal anything someone would start a war to recover
// (Asmodeus's rod of office, for example); and the false-name doctrine -
// lesser devils given the names of Powers (the devil Dagon who is not the
// demon prince, the devil Nergal who is not the Babylonian god) to upset the
// other Power, to catch spell casters invoking without understanding, and to
// muddle who rules the lower planes - as Titivilus says: Nergal? Why, Nergal
// lives in the Hells - outcast, hides in Avernus, looks like a toad, poor
// thing.
inline bool ddpHellsPowers()
    { return true; }

}   // namespace rules
