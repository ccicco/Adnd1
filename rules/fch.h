// =========================================================================================
// Adnd1 - rules/fch.h
// The Fischer Hints magic items - Joe Fischer's judge toybox (folios 12-13,
// 26): the chest-trap table, Monster Gems and the Room of Gems, the Hobbits'
// Pipe with five pipeweeds, and the rings, the bag, the helm
// census 814 -> 815.
//
// Pinned from The Dragon Vol. 1 No. 2 (August 1976): folios 12-13, Joe
// Fischer's Hints for D&D Judges Part 3 - The Dungeons (the Marc Kurowski
// magic-item set, the chest-trap table, Monster Gems); folio 26, the Hints
// continuation - the Room of Gems and the Pool of Endless Ogres. The items
// are the unit of this round per the adjudication. OD&D-era ink converted per
// the walk doctrine: the pin IS the conversion, noted, never silent.
//
// The variant-layer doctrine holds: Dragon ink is never core 1e canon. These
// are judge-toybox variant items on the variant layer - the engine's canon
// items are untouched; the ranges ride as printed with the 1e terms noted.
// The wandering-monster sub-tables, the transport-to-fiction areas and the
// maze guidance on folio 26 are judge-craft prose, noted here and never
// pinned - the honest boundary of the items round.
//
namespace rules {

// ---- the chest traps (folio 12) ----

// the chest table - 0-50 a normal chest, 51-00 trapped, roll the sub-table
// (folio 12)
inline int fchChestNormalHi()
    { return 50; }

// 0-30: 1-4 spring-loaded daggers fire when the chest opens (folio 12)
inline int fchDaggerTrapHi()
    { return 30; }

// 31-50: the same daggers, poisoned (folio 12)
inline int fchPoisonDaggerHi()
    { return 50; }

// 51-65: poisoned gas released when the chest opens (folio 12)
inline int fchGasTrapHi()
    { return 65; }

// 66-75: the opened chest acts as a Mirror of Life Trapping (folio 12)
inline int fchMirrorTrapHi()
    { return 75; }

// 76-85: the chest explodes for 2-7 dice (folio 12)
inline int fchExplodeTrapHi()
    { return 85; }

// 86-90: an enraged spectre comes out (folio 12)
inline int fchSpectreTrapHi()
    { return 90; }

// 91-95: all members within 5 feet lose one experience level (folio 12)
inline int fchLevelTrapHi()
    { return 95; }

// 96-98: all members within 5 feet lose one magic item (folio 12)
inline int fchItemTrapHi()
    { return 98; }

// the spring-loaded daggers, 1-4 of them (folio 12)
inline int fchDaggerMin()
    { return 1; }

// the dagger count's top end (folio 12)
inline int fchDaggerMax()
    { return 4; }

// the exploding chest, 2-7 dice (folio 12)
inline int fchExplodeDiceMin()
    { return 2; }

// the explosion's top end - 7 dice (folio 12)
inline int fchExplodeDiceMax()
    { return 7; }

// the level- and item-loss traps reach 5 feet (folio 12)
inline int fchTrapRadiusFeet()
    { return 5; }

// 99-00: the intelligent chest acts as a 2nd-9th level magic-user, spells and
// all (folio 12)
inline int fchChestMuMin()
    { return 2; }

// the intelligent chest's level ceiling - 9th (folio 12)
inline int fchChestMuMax()
    { return 9; }

// the 31-50 chest read - the daggers are poisoned (folio 12)
inline bool fchPoisonedDaggers()
    { return true; }

// intelligent gold pieces scream when taken from their room, drawing
// monsters, or throw themselves en masse (folio 12)
inline bool fchScreamingGold()
    { return true; }

// ---- the gems and pools (folios 13, 26) ----

// Monster Gems - magical gems worth 500 gold pieces each (folio 13)
inline int fchGemValueGp()
    { return 500; }

// the Room of Gems - three turns after the gems leave the room, half of them
// turn into orcs and attack (folio 26)
inline int fchGemRoomTurns()
    { return 3; }

// 50 percent of the Room of Gems hoard turns orc (folio 26)
inline int fchGemRoomOrcPct()
    { return 50; }

// the Pool of Endless Ogres - one ogre emerges per turn while adventurers
// remain in the cavern (folio 26)
inline int fchOgrePoolPerTurn()
    { return 1; }

// a Monster Gem commanded turns into a wandering-dungeon monster - anything
// from a kobold to a red dragon - staying a week (folio 13)
inline bool fchGemMonsterWeek()
    { return true; }

// when the gem-monster is killed, both monster and gem are destroyed (folio
// 13)
inline bool fchGemDiesWithMonster()
    { return true; }

// ---- the Hobbits' Pipe and the pipeweeds (folio 13) ----

// the Hobbits' Pipe blows four multi-colored smoke rings per turn, going
// wherever ordered (folio 13)
inline int fchPipeRingsPerTurn()
    { return 4; }

// the smoke rings move at 4 inches per turn, lasting 1-6 turns; high winds
// disperse them (folio 13)
inline int fchPipeRingMove()
    { return 4; }

// a ring's life, 1-6 turns (folio 13)
inline int fchPipeRingMin()
    { return 1; }

// a ring's life top end - 6 turns (folio 13)
inline int fchPipeRingMax()
    { return 6; }

// the pipe is usable three times a day; magic pipeweed grows only in the
// gardens of wizards (folio 13)
inline int fchPipeUsesPerDay()
    { return 3; }

// Pipeweed of Tranquillity - 6-inch radius, hostile creatures refrain from
// attacking (folio 13)
inline int fchTranqRange()
    { return 6; }

// the tranquillity lasts 3 turns (folio 13)
inline int fchTranqTurns()
    { return 3; }

// in the pipe it lasts 1-4 turns longer (folio 13)
inline int fchTranqPipeBonusMin()
    { return 1; }

// the pipe bonus top end - 4 extra turns (folio 13)
inline int fchTranqPipeBonusMax()
    { return 4; }

// NPCs of the smoker's party take plus one to morale (folio 13)
inline int fchTranqMoraleBonus()
    { return 1; }

// Pipeweed of Stoning - 6-inch range, creatures within turned to stone, saves
// allowed (folio 13)
inline int fchStoneRange()
    { return 6; }

// each turn a 25 percent chance the wind carries the stoning smoke back on
// the smoker (folio 13)
inline int fchStoneWindRiskPct()
    { return 25; }

// the Hobbits' Pipe cuts the self-stoning risk to 10 percent (folio 13)
inline int fchStonePipeRiskPct()
    { return 10; }

// Pipeweed of Illusion - smoke as a Phantasmal Force; in the pipe it lasts
// 1-4 turns longer (folio 13)
inline int fchIllusionPipeExtraMin()
    { return 1; }

// the illusion pipe bonus top end - 4 turns (folio 13)
inline int fchIllusionPipeExtraMax()
    { return 4; }

// Pipeweed of Acapulco - the smoker treats everyone as a friend, 2-12 turns
// (folio 13)
inline int fchAcapMinTurns()
    { return 2; }

// the Acapulco stupor top end - 12 turns (folio 13)
inline int fchAcapMaxTurns()
    { return 12; }

// the Acapulco smoker will not attack and defends at minus 3; in the pipe,
// saves are allowed (folio 13)
inline int fchAcapDefendPenalty()
    { return 3; }

// magic pipeweed is highly rare, grown only in the gardens of wizards, and
// the pipe carries its effects (folio 13)
inline bool fchPipeMagicWeed()
    { return true; }

// the tranquillity doctrine - hostile creatures refrain from attacking (folio
// 13)
inline bool fchTranqNoAttack()
    { return true; }

// the stoning smoke allows saving throws (folio 13)
inline bool fchStoneSaveAllowed()
    { return true; }

// the illusion smoke fails in high wind or drafty corridors (folio 13)
inline bool fchIllusionWindFails()
    { return true; }

// smoked in the pipe, the Acapulco weed allows saving throws (folio 13)
inline bool fchAcapPipeSaves()
    { return true; }

// ---- the rings, the bag, the helm (folio 13) ----

// Ring of Magic Missiles - holds 10 Magic Missiles, fired two at a time
// (folio 13)
inline int fchMissileRingCharges()
    { return 10; }

// two missiles per volley (folio 13)
inline int fchMissileRingPerVolley()
    { return 2; }

// it recharges at two Magic Missile spells per missile restored (folio 13)
inline int fchMissileRingRechargeMult()
    { return 2; }

// Bag of Infinite Wealth - turns base metals into gold at 100 gold pieces per
// day (folio 13)
inline int fchBagGoldPerDay()
    { return 100; }

// Helm of Forgetfulness - Intelligences 13-15 save at minus 1 (folio 13)
inline int fchHelmSavePenalty13()
    { return 1; }

// Intelligences 16-18 save at minus 2 (folio 13)
inline int fchHelmSavePenalty16()
    { return 2; }

// the Helm of Forgetfulness appears to be a Helm of Teleportation (folio 13)
inline bool fchHelmDisguise()
    { return true; }

// a made save leaves only a partial memory loss; on a miss all is forgotten
// (folio 13)
inline bool fchHelmPartialSave()
    { return true; }

// Ring of Infravision - as the Infravision spell, working as long as the ring
// is worn (folio 13)
inline bool fchInfraWhileWorn()
    { return true; }

}   // namespace rules
