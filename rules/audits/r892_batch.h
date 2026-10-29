    // ---- R892 Fischer items audit ----
    // THE FISCHER HINTS MAGIC ITEMS - Round C of issue 2 (folios 12-13, 26),
    // the judge's toybox on the variant layer. THE CHEST TRAPS (folio 12):
    // the d100 split - 0-50 a normal chest, 51-00 the trap sub-table: 1-4
    // spring-loaded daggers at 0-30, the poisoned daggers at 31-50, the gas
    // at 51-65, the Mirror of Life Trapping chest at 66-75, the 2-7-dice
    // explosion at 76-85, the enraged spectre at 86-90, the level loss within
    // 5 feet at 91-95, the magic item loss at 96-98, and the intelligent
    // 2nd-9th level magic-user chest at 99-00 - plus the screaming
    // intelligent gold. THE GEMS AND POOLS (folios 13, 26): Monster Gems -
    // 500 gold pieces, a wandering-dungeon monster on command, kobold to red
    // dragon, a week of service, monster and gem dying together; the Room of
    // Gems - three turns after removal half the hoard turns orc; the Pool of
    // Endless Ogres - one ogre a turn. THE PIPE (folio 13): the Hobbits' Pipe
    // - four ordered smoke rings a turn at 4 inches, living 1-6 turns, three
    // uses a day, carrying the wizards'-garden pipeweeds: Tranquillity
    // (6-inch radius, 3 turns, morale plus one, 1-4 longer in the pipe),
    // Stoning (6 inches, saves allowed, 25 percent backfire cut to 10 in the
    // pipe), Illusion (a Phantasmal Force, failing in high wind, 1-4 turns
    // longer in the pipe), Acapulco (everyone a friend, 2-12 turns, defend at
    // minus 3, saves in the pipe). THE ITEMS (folio 13): the Ring of Magic
    // Missiles - 10 charges, two a volley, two spells per missile restored;
    // the Bag of Infinite Wealth - 100 gold pieces a day; the Helm of
    // Forgetfulness - disguised as a Helm of Teleportation, saves at minus 1
    // for Int 13-15 and minus 2 for 16-18, a made save leaving partial loss;
    // the Ring of Infravision - the spell while worn. HONEST BOUNDARIES: the
    // wandering-monster sub-tables, the transport-to-fiction areas and the
    // maze guidance on folio 26 are judge-craft prose, noted here and never
    // pinned; all ink is OD&D-era variant, converted, noted, never silent.
    // The Alchemist box flips this round - the issue-2 report's second flip,
    // 2 closed / 2 open.
    {
        using namespace rules;
        int bad = 0;
    if (fchChestNormalHi() != 50
            || fchDaggerTrapHi() != 30
            || fchPoisonDaggerHi() != 50
            || fchGasTrapHi() != 65
            || fchMirrorTrapHi() != 75
            || fchExplodeTrapHi() != 85
            || fchSpectreTrapHi() != 90
            || fchLevelTrapHi() != 95
            || fchItemTrapHi() != 98
            || fchDaggerMin() != 1
            || fchDaggerMax() != 4
            || fchExplodeDiceMin() != 2
            || fchExplodeDiceMax() != 7
            || fchTrapRadiusFeet() != 5
            || fchChestMuMin() != 2
            || fchChestMuMax() != 9
            || fchGemValueGp() != 500
            || fchGemRoomTurns() != 3
            || fchGemRoomOrcPct() != 50
            || fchOgrePoolPerTurn() != 1
            || fchPipeRingsPerTurn() != 4
            || fchPipeRingMove() != 4
            || fchPipeRingMin() != 1
            || fchPipeRingMax() != 6
            || fchPipeUsesPerDay() != 3
            || fchTranqRange() != 6
            || fchTranqTurns() != 3
            || fchTranqPipeBonusMin() != 1
            || fchTranqPipeBonusMax() != 4
            || fchTranqMoraleBonus() != 1
            || fchStoneRange() != 6
            || fchStoneWindRiskPct() != 25
            || fchStonePipeRiskPct() != 10
            || fchIllusionPipeExtraMin() != 1
            || fchIllusionPipeExtraMax() != 4
            || fchAcapMinTurns() != 2
            || fchAcapMaxTurns() != 12
            || fchAcapDefendPenalty() != 3
            || fchMissileRingCharges() != 10
            || fchMissileRingPerVolley() != 2
            || fchMissileRingRechargeMult() != 2
            || fchBagGoldPerDay() != 100
            || fchHelmSavePenalty13() != 1
            || fchHelmSavePenalty16() != 2
            || !fchPoisonedDaggers()
            || !fchScreamingGold()
            || !fchGemMonsterWeek()
            || !fchGemDiesWithMonster()
            || !fchPipeMagicWeed()
            || !fchTranqNoAttack()
            || !fchStoneSaveAllowed()
            || !fchIllusionWindFails()
            || !fchAcapPipeSaves()
            || !fchHelmDisguise()
            || !fchHelmPartialSave()
            || !fchInfraWhileWorn()
        )
            ++bad;
        // the chest split - half the chests are innocent (folio 12)
    if (fchChestNormalHi() != 50
        )
            ++bad;
        // the sub-table's first bands - daggers, poisoned daggers, gas (folio
        // 12)
    if (fchDaggerTrapHi() != 30
            || fchPoisonDaggerHi() != 50
            || fchGasTrapHi() != 65
        )
            ++bad;
        // the middle bands - the Mirror chest, the explosion, the spectre
        // (folio 12)
    if (fchMirrorTrapHi() != 75
            || fchExplodeTrapHi() != 85
            || fchSpectreTrapHi() != 90
        )
            ++bad;
        // the loss bands - the level at 91-95, the item at 96-98 (folio 12)
    if (fchLevelTrapHi() != 95
            || fchItemTrapHi() != 98
        )
            ++bad;
        // the spring-loaded daggers, 1-4 (folio 12)
    if (fchDaggerMin() != 1
            || fchDaggerMax() != 4
        )
            ++bad;
        // the exploding chest, 2-7 dice (folio 12)
    if (fchExplodeDiceMin() != 2
            || fchExplodeDiceMax() != 7
        )
            ++bad;
        // the loss traps reach 5 feet (folio 12)
    if (fchTrapRadiusFeet() != 5
        )
            ++bad;
        // the intelligent chest - a 2nd-9th level magic-user (folio 12)
    if (fchChestMuMin() != 2
            || fchChestMuMax() != 9
        )
            ++bad;
        // the Monster Gem price - 500 gold pieces (folio 13)
    if (fchGemValueGp() != 500
        )
            ++bad;
        // the Room of Gems - three turns, half turn orc (folio 26)
    if (fchGemRoomTurns() != 3
            || fchGemRoomOrcPct() != 50
        )
            ++bad;
        // the Pool of Endless Ogres - one ogre a turn (folio 26)
    if (fchOgrePoolPerTurn() != 1
        )
            ++bad;
        // the pipe - four rings a turn, moving 4 inches (folio 13)
    if (fchPipeRingsPerTurn() != 4
            || fchPipeRingMove() != 4
        )
            ++bad;
        // the rings live 1-6 turns, the pipe works three times a day (folio
        // 13)
    if (fchPipeRingMin() != 1
            || fchPipeRingMax() != 6
            || fchPipeUsesPerDay() != 3
        )
            ++bad;
        // the tranquillity - 6-inch radius, 3 turns (folio 13)
    if (fchTranqRange() != 6
            || fchTranqTurns() != 3
        )
            ++bad;
        // the pipe adds 1-4 turns and the morale plus one (folio 13)
    if (fchTranqPipeBonusMin() != 1
            || fchTranqPipeBonusMax() != 4
            || fchTranqMoraleBonus() != 1
        )
            ++bad;
        // the stoning weed - 6 inches, 25 percent backfire, 10 in the pipe
        // (folio 13)
    if (fchStoneRange() != 6
            || fchStoneWindRiskPct() != 25
            || fchStonePipeRiskPct() != 10
        )
            ++bad;
        // the illusion weed's pipe bonus, 1-4 turns longer (folio 13)
    if (fchIllusionPipeExtraMin() != 1
            || fchIllusionPipeExtraMax() != 4
        )
            ++bad;
        // the Acapulco stupor - 2-12 turns, defend at minus 3 (folio 13)
    if (fchAcapMinTurns() != 2
            || fchAcapMaxTurns() != 12
            || fchAcapDefendPenalty() != 3
        )
            ++bad;
        // the Ring of Magic Missiles - 10 charges, 2 a volley, 2 spells per
        // recharge (folio 13)
    if (fchMissileRingCharges() != 10
            || fchMissileRingPerVolley() != 2
            || fchMissileRingRechargeMult() != 2
        )
            ++bad;
        // the Bag of Infinite Wealth - 100 gold pieces a day (folio 13)
    if (fchBagGoldPerDay() != 100
        )
            ++bad;
        // the Helm of Forgetfulness save ladder - minus 1 at Int 13-15, minus
        // 2 at 16-18 (folio 13)
    if (fchHelmSavePenalty13() != 1
            || fchHelmSavePenalty16() != 2
        )
            ++bad;
        // the poisoned daggers and the screaming gold (folio 12)
    if (fchPoisonedDaggers() != 1
            || fchScreamingGold() != 1
        )
            ++bad;
        // the gem-monster covenant - a week of service, death is mutual
        // (folio 13)
    if (fchGemMonsterWeek() != 1
            || fchGemDiesWithMonster() != 1
        )
            ++bad;
        // the pipe doctrine and the weed pair (folio 13)
    if (fchPipeMagicWeed() != 1
            || fchTranqNoAttack() != 1
            || fchStoneSaveAllowed() != 1
        )
            ++bad;
        // the wind and the save clauses (folio 13)
    if (fchIllusionWindFails() != 1
            || fchAcapPipeSaves() != 1
        )
            ++bad;
        // the helm's disguise and mercy, the infravision ring's tenure (folio
        // 13)
    if (fchHelmDisguise() != 1
            || fchHelmPartialSave() != 1
            || fchInfraWhileWorn() != 1
        )
            ++bad;
        printf("R892 Fischer items audit: bad %d\n", bad);
        if (bad) return 1;
    }
