// =========================================================================================
// Adnd1 - rules/oa80carp.h
// OA MONSTERS - THE CARP, GIANT, printed capture pp. 257-258 - the overgrown
// fish round
// census 631 -> 632.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 162 closed, 73 open - the giant carp box
// flips (census 631 -> 632); NEXT - R710: the Con-Tinh, Lesser Spirit
// (capture pp. 258-259), prefix djx (verify free at the landing), audit "R710
// OA monsters Con-Tinh audit", include after rules/oa80carp.h
//
namespace rules {

// ---- the stat block ----

// the giant carp appearance minimum - the 1 of the 1-4 of the stat block
// (print capture p. 257)
inline int djwCarpNoAppearingMin()
    { return 1; }

// the giant carp appearance maximum - the 4 of the 1-4 of the stat block
// (print capture p. 257)
inline int djwCarpNoAppearingMax()
    { return 4; }

// the giant carp armor class - the AC 6 of the stat block (print capture p.
// 257)
inline int djwCarpAC()
    { return 6; }

// the giant carp movement rate - the move 18 of the stat block (print capture
// p. 257)
inline int djwCarpMove()
    { return 18; }

// the giant carp hit-dice minimum - the 8 of the 8-12 of the stat block
// (print capture p. 257)
inline int djwCarpHDMin()
    { return 8; }

// the giant carp hit-dice maximum - the 12 of the 8-12 of the stat block
// (print capture p. 257)
inline int djwCarpHDMax()
    { return 12; }

// the giant carp attacks per round - the 1 of the stat block (print capture
// p. 257)
inline int djwCarpAttacks()
    { return 1; }

// the giant carp damage minimum - the 2 of the 2-20 of the stat block (print
// capture p. 257)
inline int djwCarpDmgMin()
    { return 2; }

// the giant carp damage maximum - the 20 of the 2-20 of the stat block (print
// capture p. 257)
inline int djwCarpDmgMax()
    { return 20; }

// the giant carp swallow rule - the attack causing 12 or more points of
// damage may swallow whole (print capture p. 257)
inline int djwCarpSwallowDmgThreshold()
    { return 12; }

// the giant carp length minimum - the 20 of the 20-30 feet size L entry
// (print capture p. 257)
inline int djwCarpSizeMinFt()
    { return 20; }

// the giant carp length maximum - the 30 of the 20-30 feet size L entry
// (print capture p. 257)
inline int djwCarpSizeMaxFt()
    { return 30; }

// the giant carp experience table - the four HD-tiered rows: the 8 HD VI/650
// + 10, the 9 HD VI/1,000 + 12, the 10 HD VII/1,500 + 14, the 11 and 12 HD
// VII/2,150 + 16 (print capture p. 257)
inline int djwCarpXPTableRows()
    { return 4; }

// the giant carp 8 HD experience - the VI/650 + 10 per hp tier (print capture
// p. 257)
inline int djwCarpXP8HDBase()
    { return 650; }

// the giant carp 8 HD experience per hit point - the + 10 of the VI/650 tier
// (print capture p. 257)
inline int djwCarpXP8HDPerHP()
    { return 10; }

// the giant carp 9 HD experience - the VI/1,000 + 12 per hp tier (print
// capture p. 257)
inline int djwCarpXP9HDBase()
    { return 1000; }

// the giant carp 9 HD experience per hit point - the + 12 of the VI/1,000
// tier (print capture p. 257)
inline int djwCarpXP9HDPerHP()
    { return 12; }

// the giant carp 10 HD experience - the VII/1,500 + 14 per hp tier (print
// capture p. 257)
inline int djwCarpXP10HDBase()
    { return 1500; }

// the giant carp 10 HD experience per hit point - the + 14 of the VII/1,500
// tier (print capture p. 257)
inline int djwCarpXP10HDPerHP()
    { return 14; }

// the giant carp 11 and 12 HD experience level - the VII of the VII/2,150
// tier (print capture p. 257)
inline int djwCarpXP11HDLevel()
    { return 7; }

// the giant carp 11 and 12 HD experience - the VII/2,150 + 16 per hp tier
// (print capture p. 257)
inline int djwCarpXP11HDBase()
    { return 2150; }

// the giant carp 11 and 12 HD experience per hit point - the + 16 of the
// VII/2,150 tier (print capture p. 257)
inline int djwCarpXP11HDPerHP()
    { return 16; }

// the giant carp frequency - the uncommon of the stat block (print capture p.
// 257)
inline int djwCarpUncommon()
    { return 1; }

// the giant carp in-lair percentage - the Nil of the stat block (print
// capture p. 257)
inline int djwCarpLairNil()
    { return 1; }

// the giant carp treasure - the Nil of the stat block (print capture p. 257)
inline int djwCarpTreasureNil()
    { return 1; }

// the giant carp special attack - the swallow whole of the stat block (print
// capture p. 257)
inline int djwCarpSwallowWhole()
    { return 1; }

// the giant carp magic resistance - the standard of the stat block (print
// capture p. 257)
inline int djwCarpMRStandard()
    { return 1; }

// the giant carp intelligence - the animal of the stat block (print capture
// p. 257)
inline int djwCarpIntAnimal()
    { return 1; }

// the giant carp alignment - the neutral of the stat block (print capture p.
// 257)
inline int djwCarpNeutral()
    { return 1; }

// the giant carp size - the L of the stat block (print capture p. 257)
inline int djwCarpSizeL()
    { return 1; }

// the giant carp psionics - the Nil ability and the Nil attack/defense modes
// of the stat block (print capture p. 257)
inline int djwCarpPsionicNil()
    { return 1; }

// ---- the nature ----

// the giant carp nature - an overgrown cousin of the common carp, a food-fish
// favored by many people (print capture p. 257)
inline int djwCarpOvergrownCousin()
    { return 1; }

// the giant carp habitat - all types of fresh water lakes and rivers, if they
// are of substantial depth (print capture p. 257)
inline int djwCarpFreshwaterDepth()
    { return 1; }

// the giant carp range - from colder temperate waters to tropical climes
// (print capture p. 257)
inline int djwCarpTemperateToTropical()
    { return 1; }

// the giant carp feeding - a scavenger, primarily digging through the ooze on
// the bottom (print capture p. 257)
inline int djwCarpScavenger()
    { return 1; }

// the giant carp aggression - known to surface to attack small boats or
// swimmers (print capture p. 257)
inline int djwCarpSurfacesToAttack()
    { return 1; }

// the giant carp vulnerability - some have even taken the bait of a simple
// fishhook (print capture p. 257)
inline int djwCarpTakesBait()
    { return 1; }

// ---- the swallow rules ----

// the giant carp swallow-capacity tiers - the 8 HD dog, the 9 HD large dog or
// colt, the 10 HD small man, the 11 HD normal-sized man, the 12 HD small oni
// or ogre (print capture p. 258)
inline int djwCarpSwallowTiers()
    { return 5; }

// the swallowed victim damage - the 1 hp per round thereafter from the carp
// digestive juices (print capture p. 258)
inline int djwCarpDigestDmgPerRound()
    { return 1; }

// the swallowed victim suffocation - the 5% cumulative chance per round of
// suffocating (print capture p. 258)
inline int djwCarpSuffocateChancePct()
    { return 5; }

// the swallow rescue rule - when the carp has suffered a loss of 50% of its
// hit points, the victim can be freed (print capture p. 258)
inline int djwCarpFreeAtHPPct()
    { return 50; }

// the outside rescuers penalty - the -2 on their chance to hit, aiming a
// series of blows to the same area (print capture p. 258)
inline int djwCarpOutsideToHitPenalty()
    { return 2; }

// the thrusting and stabbing weapons - the 20% chance of striking the
// swallowed victim (print capture p. 258)
inline int djwCarpThrustHitSwallowedPct()
    { return 20; }

// the swallow rescue - characters swallowed can be rescued from the outside
// or cut free with some type of sharp-edged weapon (print capture p. 258)
inline int djwCarpRescueOutsideOrCutFree()
    { return 1; }

// the swallowed victim attacks - those on the inside suffer no penalty when
// making these attacks (print capture p. 258)
inline int djwCarpInsideNoPenalty()
    { return 1; }

// the giant carp value - a single giant carp can supply the needs of a
// village for quite some time (print capture p. 258)
inline int djwCarpVillageSupply()
    { return 1; }

// the giant carp hunting - fishermen sometimes organize expeditions, highly
// dangerous and often resulting in loss of life (print capture p. 258)
inline int djwCarpFishingExpeditions()
    { return 1; }

}   // namespace rules
