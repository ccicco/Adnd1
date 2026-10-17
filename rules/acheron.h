// =========================================================================================
// Adnd1 - rules/acheron.h
// ACHERON - printed pp. 113-114, the iron-shod battle plains of lawful evil:
// the four block layers from Avalas to the razor squares of Ocanthus, the
// spherical portals that speak by sound, the spirit legions reborn within 24
// hours, Lei Kung on his cloud, and Maglubiyet and Gruumsh warring forever
// over one dull block.
// census 511 -> 512.
//
// verified against printed pp. 113-114 of the uploaded motp.pdf OCR; the four
// layers, the portal-sound convention, the scrap-heap and razor rules, the
// spirit legions and the goblin-orc war are pinned exactly as printed (Luthic
// and Ilneval restored against the OCR slips); Concordant Opposition (pp.
// 114-116) is left for the round that owns it.
//
// the gap census after this round: 78 closed, 12 open - ONE box falls
// (Acheron); the odd plane of Concordant Opposition opens next, and the outer
// planes are nearly closed.
//
namespace rules {

// ---- the acheron pins ----

// the four layers of Acheron, each stressing order over evil, the group over
// the individual: Avalas the topmost battle plain, Thuldanin the scrap heap,
// Tintibulus the geometric blocks, and Ocanthus the razor squares - each
// layer consisting of huge blocks that drift together, join for a time, then
// part again, the blocks the size of nations yet colliding without tremors;
// while blocks are joined, beings can change blocks and travel with the
// drifting river block; gravity pulls toward the center of each block, and
// the medium between them counts as air for breathing and flying.
inline int ddrAcheronLayerCount()
    { return 4; }

// the Thuldanin scrap heap: the second layer's hollow blocks, surfaces
// pockmarked with pits leading a few miles down into interiors filled with
// the broken scraps of thousands of devices - great ships burst asunder,
// toppled buildings, flying devices of every description, all inoperative,
// turned to stone by long exposure to the plane's magics; a day spent
// searching the litter yields anything useful only 0.1% of the time (1 in
// 1,000), and if useful the DM must determine whether it functions upon
// return to the Prime; there are no natives, only Avalas visitors seeking
// victory - and for each month a nonmagical item lies here it must save vs.
// crushing blow or turn to rock.
inline int ddrThuldaninSearchChance()
    { return 1000; }

// the Ocanthus razor squares: the final layer has no blocks, only razor-thin
// squares of hard black matter moving through the snow-white sky like a
// flurry of geese, from a few inches to several miles across, walkable on
// both faces (each side pulling gravitationally into the surface) - but a
// square striking edge-on inflicts 1d10 ten-sided dice of damage, hitting as
// a 1d10-hit-die monster with the target gaining no AC benefit from magical
// armor.
inline int ddrOcanthusEdgeDice()
    { return 10; }

// the Acheron portal arrival: those emerging from a spherical portal float in
// space and are slowly drawn to the nearest large block - and unless the
// traveler can fly, or the portal hangs very close to a block, he strikes the
// block with high velocity for 20d6 points of damage; flight spells operate
// normally in most of this layer.
inline int ddrPortalFallDice()
    { return 20; }

// the Acheron doctrine: the iron-shod battle plains, the most lawful of the
// evil planes, bridging the organized evil of the Nine Hells and the ultimate
// organization of Nirvana's clockwork disks - home of those who inflict evil
// secondarily, their chief aim organization and order; many armies but
// surprisingly few leaders, for those capable of initiative drift toward
// planes with more definite alignments.
inline bool ddrAcheronDoctrine()
    { return true; }

// Avalas, the topmost layer: the greatest number of block-like worlds and the
// most inhabitants, where the armies of the afterworlds come to battle -
// native legions and visitors settling differences in neutral territory; the
// ground black and hard as metal (the iron shod), reverberating to the
// passing of thousands of troops, the terrain cone-shaped mountains and pits,
// the iron citadels of armies, and the river Styx rising from one pit,
// crossing two or three sides of a block, then vanishing into another (Charon
// and his servants reach the blocks it touches).
inline bool ddrAvalasRule()
    { return true; }

// Tintibulus, the third layer: blocks of many regular shapes - six-sided,
// eight-sided, and so on - solid throughout and made of grey volcanic stone;
// when collisions occur the stone fractures along natural fault lines,
// creating huge hexagons of various dimensions on the surfaces; no native
// life either, but the emptiness often attracts magical researchers.
inline bool ddrTintibulusRule()
    { return true; }

// the Acheron portals and barriers: the upper layer (also called the
// Battleplains) is reached from Nirvana, Gehenna, and Concordant Opposition,
// each permanent portal hanging at a fixed point in space while the blocks
// slowly orbit it - a spherical portal activated by touch, its activation
// sound revealing the destination (a harmonious chord to Nirvana, a
// discordant one to Avernus of the Nine Hells, a silent sphere to Concordant
// Opposition); the spheres have no effect on the blocks, passing through them
// freely, though a portal will not function while inside a block, resuming as
// soon as the block passes; the interlayer barriers likewise hang in space
// unmoored to any block, making the lower reaches hard to reach or return
// from - but there is a careful order to the spinning of blocks, solids and
// black slabs, and those of at least 18 Intelligence who succeed an
// Intelligence check can discover an area's pattern and guide travelers
// barrier to barrier or portal to portal (one check per character per visit).
inline bool ddrAcheronPortals()
    { return true; }

// the spirit legions: compared to most other planes Acheron is a wasteland
// (though undiscovered life may hide as it would from an Antarctic landing),
// the imps, achaiarai and rust monsters immigrants from nearby planes along
// with occasional modrons and devils - the significant inhabitants are the
// spirit legions of the uppermost layer, gathering into nations of similar
// beliefs or alignments, all lawful with tendencies toward evil: the spirits
// of those who died in wars after losing sight of their objectives, war
// become an end in itself, humans among dwarves, halflings, kender, ogres and
// all manner of mindless soldiers; generally lacking leaders, they follow the
// tactics of the majority's milieu, fighting to conquer a block then joining
// against the legions of another block that comes within striking distance -
// and members slain in battle return to full strength within 24 hours, the
// eternal soldier fighting on without respite.
inline bool ddrSpiritLegionRule()
    { return true; }

// the Powers of Acheron: the sole human Power is Lei Kung, the Chinese Duke
// of Thunder, who strikes the guilty as directed by Shang-Ti his lord in
// Nirvana - living not on any block but on a large cloud-island of his own
// devising, a small temple and quarters resting on the cloud between his
// callings, with no servants and no abode but the cloud. And Acheron is home
// to Maglubiyet of the goblins and hobgoblins, and Gruumsh of the orcs with
// most of the orcish pantheon: Maglubiyet and Gruumsh share the same large
// spinning block, the orcish spirit legions clashing daily with the goblin
// and hobgoblin legions, both Powers maintaining several large citadels, one
// spirit legion usually besieging another within them; Gruumsh's
// preoccupation with unwinnable wars may explain his pantheon's poor state -
// the orcish gods reported native to the Nine Hells, Gehenna, and most
// recently Acheron, moving plane to plane seeking a layer to call their own
// (an orcish Asgard); several smaller blocks orbit the great contested one,
// the holdings of Luthic, Bahgtru and Ilneval - Gruumsh's wife, son, and
// first lieutenant in battle - the son and lieutenant often aiding against
// the goblin legions, their aid matched by the goblin pantheon; both sides
// wait for the other's final defeat to control the layer as the elves control
// Arvandor, neither willing to move or share the dull block they fight over -
// and most other deities cite this everlasting war as the example of the
// folly of continued violence for its own end.
inline bool ddrAcheronPowers()
    { return true; }

}   // namespace rules
