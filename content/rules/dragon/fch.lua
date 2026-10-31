-- fch: promoted from tools/spec_r892.json (the The Fischer Hints magic items - Joe Fischer's judge toybox (folios 12-13, 26): the chest-trap table, Monster Gems and the Room of Gems, the Hobbits' Pipe with five pipeweeds, and the rings, the bag, the helm);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 892,
  "prefix" = "fch",
  "banner" = {
      "title" = "The Fischer Hints magic items - Joe Fischer's judge toybox (folios 12-13, 26): the chest-trap table, Monster Gems and the Room of Gems, the Hobbits' Pipe with five pipeweeds, and the rings, the bag, the helm",
      "provenance" = "Pinned from The Dragon Vol. 1 No. 2 (August 1976): folios 12-13, Joe Fischer's Hints for D&D Judges Part 3 - The Dungeons (the Marc Kurowski magic-item set, the chest-trap table, Monster Gems); folio 26, the Hints continuation - the Room of Gems and the Pool of Endless Ogres. The items are the unit of this round per the adjudication. OD&D-era ink converted per the walk doctrine: the pin IS the conversion, noted, never silent.",
      "sentinel" = "The variant-layer doctrine holds: Dragon ink is never core 1e canon. These are judge-toybox variant items on the variant layer - the engine's canon items are untouched; the ranges ride as printed with the 1e terms noted. The wandering-monster sub-tables, the transport-to-fiction areas and the maze guidance on folio 26 are judge-craft prose, noted here and never pinned - the honest boundary of the items round.",
    },
  "consts" = { {
      "name" = "fchChestNormalHi",
      "value" = 50,
      "comment" = "the chest table - 0-50 a normal chest, 51-00 trapped, roll the sub-table (folio 12)",
    }, {
      "name" = "fchDaggerTrapHi",
      "value" = 30,
      "comment" = "0-30: 1-4 spring-loaded daggers fire when the chest opens (folio 12)",
    }, {
      "name" = "fchPoisonDaggerHi",
      "value" = 50,
      "comment" = "31-50: the same daggers, poisoned (folio 12)",
    }, {
      "name" = "fchGasTrapHi",
      "value" = 65,
      "comment" = "51-65: poisoned gas released when the chest opens (folio 12)",
    }, {
      "name" = "fchMirrorTrapHi",
      "value" = 75,
      "comment" = "66-75: the opened chest acts as a Mirror of Life Trapping (folio 12)",
    }, {
      "name" = "fchExplodeTrapHi",
      "value" = 85,
      "comment" = "76-85: the chest explodes for 2-7 dice (folio 12)",
    }, {
      "name" = "fchSpectreTrapHi",
      "value" = 90,
      "comment" = "86-90: an enraged spectre comes out (folio 12)",
    }, {
      "name" = "fchLevelTrapHi",
      "value" = 95,
      "comment" = "91-95: all members within 5 feet lose one experience level (folio 12)",
    }, {
      "name" = "fchItemTrapHi",
      "value" = 98,
      "comment" = "96-98: all members within 5 feet lose one magic item (folio 12)",
    }, {
      "name" = "fchDaggerMin",
      "value" = 1,
      "comment" = "the spring-loaded daggers, 1-4 of them (folio 12)",
    }, {
      "name" = "fchDaggerMax",
      "value" = 4,
      "comment" = "the dagger count's top end (folio 12)",
    }, {
      "name" = "fchExplodeDiceMin",
      "value" = 2,
      "comment" = "the exploding chest, 2-7 dice (folio 12)",
    }, {
      "name" = "fchExplodeDiceMax",
      "value" = 7,
      "comment" = "the explosion's top end - 7 dice (folio 12)",
    }, {
      "name" = "fchTrapRadiusFeet",
      "value" = 5,
      "comment" = "the level- and item-loss traps reach 5 feet (folio 12)",
    }, {
      "name" = "fchChestMuMin",
      "value" = 2,
      "comment" = "99-00: the intelligent chest acts as a 2nd-9th level magic-user, spells and all (folio 12)",
    }, {
      "name" = "fchChestMuMax",
      "value" = 9,
      "comment" = "the intelligent chest's level ceiling - 9th (folio 12)",
    }, {
      "name" = "fchGemValueGp",
      "value" = 500,
      "comment" = "Monster Gems - magical gems worth 500 gold pieces each (folio 13)",
    }, {
      "name" = "fchGemRoomTurns",
      "value" = 3,
      "comment" = "the Room of Gems - three turns after the gems leave the room, half of them turn into orcs and attack (folio 26)",
    }, {
      "name" = "fchGemRoomOrcPct",
      "value" = 50,
      "comment" = "50 percent of the Room of Gems hoard turns orc (folio 26)",
    }, {
      "name" = "fchOgrePoolPerTurn",
      "value" = 1,
      "comment" = "the Pool of Endless Ogres - one ogre emerges per turn while adventurers remain in the cavern (folio 26)",
    }, {
      "name" = "fchPipeRingsPerTurn",
      "value" = 4,
      "comment" = "the Hobbits' Pipe blows four multi-colored smoke rings per turn, going wherever ordered (folio 13)",
    }, {
      "name" = "fchPipeRingMove",
      "value" = 4,
      "comment" = "the smoke rings move at 4 inches per turn, lasting 1-6 turns; high winds disperse them (folio 13)",
    }, {
      "name" = "fchPipeRingMin",
      "value" = 1,
      "comment" = "a ring's life, 1-6 turns (folio 13)",
    }, {
      "name" = "fchPipeRingMax",
      "value" = 6,
      "comment" = "a ring's life top end - 6 turns (folio 13)",
    }, {
      "name" = "fchPipeUsesPerDay",
      "value" = 3,
      "comment" = "the pipe is usable three times a day; magic pipeweed grows only in the gardens of wizards (folio 13)",
    }, {
      "name" = "fchTranqRange",
      "value" = 6,
      "comment" = "Pipeweed of Tranquillity - 6-inch radius, hostile creatures refrain from attacking (folio 13)",
    }, {
      "name" = "fchTranqTurns",
      "value" = 3,
      "comment" = "the tranquillity lasts 3 turns (folio 13)",
    }, {
      "name" = "fchTranqPipeBonusMin",
      "value" = 1,
      "comment" = "in the pipe it lasts 1-4 turns longer (folio 13)",
    }, {
      "name" = "fchTranqPipeBonusMax",
      "value" = 4,
      "comment" = "the pipe bonus top end - 4 extra turns (folio 13)",
    }, {
      "name" = "fchTranqMoraleBonus",
      "value" = 1,
      "comment" = "NPCs of the smoker's party take plus one to morale (folio 13)",
    }, {
      "name" = "fchStoneRange",
      "value" = 6,
      "comment" = "Pipeweed of Stoning - 6-inch range, creatures within turned to stone, saves allowed (folio 13)",
    }, {
      "name" = "fchStoneWindRiskPct",
      "value" = 25,
      "comment" = "each turn a 25 percent chance the wind carries the stoning smoke back on the smoker (folio 13)",
    }, {
      "name" = "fchStonePipeRiskPct",
      "value" = 10,
      "comment" = "the Hobbits' Pipe cuts the self-stoning risk to 10 percent (folio 13)",
    }, {
      "name" = "fchIllusionPipeExtraMin",
      "value" = 1,
      "comment" = "Pipeweed of Illusion - smoke as a Phantasmal Force; in the pipe it lasts 1-4 turns longer (folio 13)",
    }, {
      "name" = "fchIllusionPipeExtraMax",
      "value" = 4,
      "comment" = "the illusion pipe bonus top end - 4 turns (folio 13)",
    }, {
      "name" = "fchAcapMinTurns",
      "value" = 2,
      "comment" = "Pipeweed of Acapulco - the smoker treats everyone as a friend, 2-12 turns (folio 13)",
    }, {
      "name" = "fchAcapMaxTurns",
      "value" = 12,
      "comment" = "the Acapulco stupor top end - 12 turns (folio 13)",
    }, {
      "name" = "fchAcapDefendPenalty",
      "value" = 3,
      "comment" = "the Acapulco smoker will not attack and defends at minus 3; in the pipe, saves are allowed (folio 13)",
    }, {
      "name" = "fchMissileRingCharges",
      "value" = 10,
      "comment" = "Ring of Magic Missiles - holds 10 Magic Missiles, fired two at a time (folio 13)",
    }, {
      "name" = "fchMissileRingPerVolley",
      "value" = 2,
      "comment" = "two missiles per volley (folio 13)",
    }, {
      "name" = "fchMissileRingRechargeMult",
      "value" = 2,
      "comment" = "it recharges at two Magic Missile spells per missile restored (folio 13)",
    }, {
      "name" = "fchBagGoldPerDay",
      "value" = 100,
      "comment" = "Bag of Infinite Wealth - turns base metals into gold at 100 gold pieces per day (folio 13)",
    }, {
      "name" = "fchHelmSavePenalty13",
      "value" = 1,
      "comment" = "Helm of Forgetfulness - Intelligences 13-15 save at minus 1 (folio 13)",
    }, {
      "name" = "fchHelmSavePenalty16",
      "value" = 2,
      "comment" = "Intelligences 16-18 save at minus 2 (folio 13)",
    } },
  "bools" = { {
      "name" = "fchPoisonedDaggers",
      "value" = true,
      "comment" = "the 31-50 chest read - the daggers are poisoned (folio 12)",
    }, {
      "name" = "fchScreamingGold",
      "value" = true,
      "comment" = "intelligent gold pieces scream when taken from their room, drawing monsters, or throw themselves en masse (folio 12)",
    }, {
      "name" = "fchGemMonsterWeek",
      "value" = true,
      "comment" = "a Monster Gem commanded turns into a wandering-dungeon monster - anything from a kobold to a red dragon - staying a week (folio 13)",
    }, {
      "name" = "fchGemDiesWithMonster",
      "value" = true,
      "comment" = "when the gem-monster is killed, both monster and gem are destroyed (folio 13)",
    }, {
      "name" = "fchPipeMagicWeed",
      "value" = true,
      "comment" = "magic pipeweed is highly rare, grown only in the gardens of wizards, and the pipe carries its effects (folio 13)",
    }, {
      "name" = "fchTranqNoAttack",
      "value" = true,
      "comment" = "the tranquillity doctrine - hostile creatures refrain from attacking (folio 13)",
    }, {
      "name" = "fchStoneSaveAllowed",
      "value" = true,
      "comment" = "the stoning smoke allows saving throws (folio 13)",
    }, {
      "name" = "fchIllusionWindFails",
      "value" = true,
      "comment" = "the illusion smoke fails in high wind or drafty corridors (folio 13)",
    }, {
      "name" = "fchAcapPipeSaves",
      "value" = true,
      "comment" = "smoked in the pipe, the Acapulco weed allows saving throws (folio 13)",
    }, {
      "name" = "fchHelmDisguise",
      "value" = true,
      "comment" = "the Helm of Forgetfulness appears to be a Helm of Teleportation (folio 13)",
    }, {
      "name" = "fchHelmPartialSave",
      "value" = true,
      "comment" = "a made save leaves only a partial memory loss; on a miss all is forgotten (folio 13)",
    }, {
      "name" = "fchInfraWhileWorn",
      "value" = true,
      "comment" = "Ring of Infravision - as the Infravision spell, working as long as the ring is worn (folio 13)",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['fchChestNormalHi']() != 50",
      "note" = "the chest split - half the chests are innocent (folio 12)",
    }, {
      "expr" = "m['fchDaggerTrapHi']() != 30 or m['fchPoisonDaggerHi']() != 50 or m['fchGasTrapHi']() != 65",
      "note" = "the sub-table's first bands - daggers, poisoned daggers, gas (folio 12)",
    }, {
      "expr" = "m['fchMirrorTrapHi']() != 75 or m['fchExplodeTrapHi']() != 85 or m['fchSpectreTrapHi']() != 90",
      "note" = "the middle bands - the Mirror chest, the explosion, the spectre (folio 12)",
    }, {
      "expr" = "m['fchLevelTrapHi']() != 95 or m['fchItemTrapHi']() != 98",
      "note" = "the loss bands - the level at 91-95, the item at 96-98 (folio 12)",
    }, {
      "expr" = "m['fchDaggerMin']() != 1 or m['fchDaggerMax']() != 4",
      "note" = "the spring-loaded daggers, 1-4 (folio 12)",
    }, {
      "expr" = "m['fchExplodeDiceMin']() != 2 or m['fchExplodeDiceMax']() != 7",
      "note" = "the exploding chest, 2-7 dice (folio 12)",
    }, {
      "expr" = "m['fchTrapRadiusFeet']() != 5",
      "note" = "the loss traps reach 5 feet (folio 12)",
    }, {
      "expr" = "m['fchChestMuMin']() != 2 or m['fchChestMuMax']() != 9",
      "note" = "the intelligent chest - a 2nd-9th level magic-user (folio 12)",
    }, {
      "expr" = "m['fchGemValueGp']() != 500",
      "note" = "the Monster Gem price - 500 gold pieces (folio 13)",
    }, {
      "expr" = "m['fchGemRoomTurns']() != 3 or m['fchGemRoomOrcPct']() != 50",
      "note" = "the Room of Gems - three turns, half turn orc (folio 26)",
    }, {
      "expr" = "m['fchOgrePoolPerTurn']() != 1",
      "note" = "the Pool of Endless Ogres - one ogre a turn (folio 26)",
    }, {
      "expr" = "m['fchPipeRingsPerTurn']() != 4 or m['fchPipeRingMove']() != 4",
      "note" = "the pipe - four rings a turn, moving 4 inches (folio 13)",
    }, {
      "expr" = "m['fchPipeRingMin']() != 1 or m['fchPipeRingMax']() != 6 or m['fchPipeUsesPerDay']() != 3",
      "note" = "the rings live 1-6 turns, the pipe works three times a day (folio 13)",
    }, {
      "expr" = "m['fchTranqRange']() != 6 or m['fchTranqTurns']() != 3",
      "note" = "the tranquillity - 6-inch radius, 3 turns (folio 13)",
    }, {
      "expr" = "m['fchTranqPipeBonusMin']() != 1 or m['fchTranqPipeBonusMax']() != 4 or m['fchTranqMoraleBonus']() != 1",
      "note" = "the pipe adds 1-4 turns and the morale plus one (folio 13)",
    }, {
      "expr" = "m['fchStoneRange']() != 6 or m['fchStoneWindRiskPct']() != 25 or m['fchStonePipeRiskPct']() != 10",
      "note" = "the stoning weed - 6 inches, 25 percent backfire, 10 in the pipe (folio 13)",
    }, {
      "expr" = "m['fchIllusionPipeExtraMin']() != 1 or m['fchIllusionPipeExtraMax']() != 4",
      "note" = "the illusion weed's pipe bonus, 1-4 turns longer (folio 13)",
    }, {
      "expr" = "m['fchAcapMinTurns']() != 2 or m['fchAcapMaxTurns']() != 12 or m['fchAcapDefendPenalty']() != 3",
      "note" = "the Acapulco stupor - 2-12 turns, defend at minus 3 (folio 13)",
    }, {
      "expr" = "m['fchMissileRingCharges']() != 10 or m['fchMissileRingPerVolley']() != 2 or m['fchMissileRingRechargeMult']() != 2",
      "note" = "the Ring of Magic Missiles - 10 charges, 2 a volley, 2 spells per recharge (folio 13)",
    }, {
      "expr" = "m['fchBagGoldPerDay']() != 100",
      "note" = "the Bag of Infinite Wealth - 100 gold pieces a day (folio 13)",
    }, {
      "expr" = "m['fchHelmSavePenalty13']() != 1 or m['fchHelmSavePenalty16']() != 2",
      "note" = "the Helm of Forgetfulness save ladder - minus 1 at Int 13-15, minus 2 at 16-18 (folio 13)",
    }, {
      "expr" = "m['fchPoisonedDaggers']() != 1 or m['fchScreamingGold']() != 1",
      "note" = "the poisoned daggers and the screaming gold (folio 12)",
    }, {
      "expr" = "m['fchGemMonsterWeek']() != 1 or m['fchGemDiesWithMonster']() != 1",
      "note" = "the gem-monster covenant - a week of service, death is mutual (folio 13)",
    }, {
      "expr" = "m['fchPipeMagicWeed']() != 1 or m['fchTranqNoAttack']() != 1 or m['fchStoneSaveAllowed']() != 1",
      "note" = "the pipe doctrine and the weed pair (folio 13)",
    }, {
      "expr" = "m['fchIllusionWindFails']() != 1 or m['fchAcapPipeSaves']() != 1",
      "note" = "the wind and the save clauses (folio 13)",
    }, {
      "expr" = "m['fchHelmDisguise']() != 1 or m['fchHelmPartialSave']() != 1 or m['fchInfraWhileWorn']() != 1",
      "note" = "the helm's disguise and mercy, the infravision ring's tenure (folio 13)",
    } },
  "audit" = {
      "label" = "R892 Fischer items audit",
      "comment" = "THE FISCHER HINTS MAGIC ITEMS - Round C of issue 2 (folios 12-13, 26), the judge's toybox on the variant layer. THE CHEST TRAPS (folio 12): the d100 split - 0-50 a normal chest, 51-00 the trap sub-table: 1-4 spring-loaded daggers at 0-30, the poisoned daggers at 31-50, the gas at 51-65, the Mirror of Life Trapping chest at 66-75, the 2-7-dice explosion at 76-85, the enraged spectre at 86-90, the level loss within 5 feet at 91-95, the magic item loss at 96-98, and the intelligent 2nd-9th level magic-user chest at 99-00 - plus the screaming intelligent gold. THE GEMS AND POOLS (folios 13, 26): Monster Gems - 500 gold pieces, a wandering-dungeon monster on command, kobold to red dragon, a week of service, monster and gem dying together; the Room of Gems - three turns after removal half the hoard turns orc; the Pool of Endless Ogres - one ogre a turn. THE PIPE (folio 13): the Hobbits' Pipe - four ordered smoke rings a turn at 4 inches, living 1-6 turns, three uses a day, carrying the wizards'-garden pipeweeds: Tranquillity (6-inch radius, 3 turns, morale plus one, 1-4 longer in the pipe), Stoning (6 inches, saves allowed, 25 percent backfire cut to 10 in the pipe), Illusion (a Phantasmal Force, failing in high wind, 1-4 turns longer in the pipe), Acapulco (everyone a friend, 2-12 turns, defend at minus 3, saves in the pipe). THE ITEMS (folio 13): the Ring of Magic Missiles - 10 charges, two a volley, two spells per missile restored; the Bag of Infinite Wealth - 100 gold pieces a day; the Helm of Forgetfulness - disguised as a Helm of Teleportation, saves at minus 1 for Int 13-15 and minus 2 for 16-18, a made save leaving partial loss; the Ring of Infravision - the spell while worn. HONEST BOUNDARIES: the wandering-monster sub-tables, the transport-to-fiction areas and the maze guidance on folio 26 are judge-craft prose, noted here and never pinned; all ink is OD&D-era variant, converted, noted, never silent. The Alchemist box flips this round - the issue-2 report's second flip, 2 closed / 2 open.",
    },
}
