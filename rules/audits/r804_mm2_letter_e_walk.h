    // ---- R804 MM2 letter E walk audit ----
    // THE MM2 LETTER E WALK - the eagle, the eblis, the electric marine eel,
    // the ELF family head, the grugach, the valley elf, the elfin cat and the
    // executioner hood pp. 62-64 (the user Go call on the landed dracolisk
    // walk). The pin-time walk from the print finds EIGHT entries: the eagle,
    // the eblis and the electric marine eel on p. 62, the ELF family head on
    // p. 63 (a doctrine-only grouping heading - the grugach and the valley
    // elf stat blocks ride beneath it), the grugach and the valley elf on p.
    // 63, the elfin cat on pp. 63-64 and the executioner hood on p. 64. SEVEN
    // defs ride the R791 data_files extension in the MM1 registry schema,
    // registry 615 -> 622. THE PRIOR-OWNED letter-E index entries: the
    // euparkeria (p. 52, landed with the R802 dinosaur walk) and the cooshee,
    // the elven dog (landed with the R798 letters BC walk); the MM1 electric
    // def owns the MM1 electric eel print, so the MM2 print takes the
    // electric_eel key. THE GRIDS: the 7-row EgStats stat grid (armor class,
    // hit dice, bonus, avgHp, attacks, xp, xp/hp, lair, move, magic
    // resistance). THE E-FLIP: the Letter E gap box flips to closed - 10
    // closed 27 open. THE SETTLED READS (capture primary, the 1eonline
    // transcription and the archive.org djvu the cross-check voices): the
    // grugach treasure "Individuals N, Q" (the capture "N, O" the OCR
    // misread); the grugach "fighter/druids" (the capture "fluids" the
    // misread); the electric eel move "//9"" the print line pinned verbatim
    // (the moveRate reads 9); the electric eel 6-8 hit dice read the low end
    // (the kuei precedent); the executioner hood hit-dice ladder 2+2, 4+4,
    // 6+6 reads the or-form best 6+6; the grugach and valley elf "90% to
    // charm and sleep only" magic resistance reads 90 in the grid; the
    // grugach print carries no xp level prefix; the valley elf xp is average
    // individuals only; the valley elf Greyhawk raids keep the print em-dash
    // as the ASCII hyphen. LOADER SEMANTICS: every Nil lair reads 0. ONE
    // REGTEST PATCH: the R804 live def walk at the R227 anchor (the R782
    // site-block pattern, no census marker), its registry census a FLOOR 615
    // -> at least 622.
    {
        using namespace rules;
        int bad = 0;
    if (mm2deRound() != 804
            || mm2deRegistryBefore() != 615
            || mm2deRegistryAfter() != 622
            || mm2deDefCount() != 7
            || mm2deEntryCount() != 8
            || mm2deEgStatRows() != 7
            || mm2deGapClosed() != 10
            || mm2deGapOpen() != 27
            || mm2dePriorOwnedEntries() != 2
            || mm2deEuparkeriaOwningRound() != 802
            || mm2deCoosheeOwningRound() != 798
            || mm2deElfHeadSubEntryCount() != 2
            || mm2deEagleXpValue() != 47
            || mm2deEagleXpLevel() != 2
            || mm2deEagleRookeryPct() != 5
            || mm2deEagleRookeryMin() != 5
            || mm2deEagleRookeryMax() != 12
            || mm2deEagleEggsMin() != 1
            || mm2deEagleEggsMax() != 4
            || mm2deEagleNestShinyPct() != 10
            || mm2deEagleDiveHeightFeet() != 100
            || mm2deEagleDiveClawAttacks() != 2
            || mm2deEagleDiveToHitBonus() != 2
            || mm2deEagleDiveDamageMultiplier() != 2
            || mm2deEagleTrainablePct() != 25
            || mm2deEagleEggValueMin() != 60
            || mm2deEagleEggValueMax() != 100
            || mm2deEblisXpValue() != 255
            || mm2deEblisXpLevel() != 4
            || mm2deEblisHutsMin() != 2
            || mm2deEblisHutsMax() != 8
            || mm2deEblisHutHiddenPct() != 90
            || mm2deEblisEggPct() != 30
            || mm2deEblisTreasurePct() != 25
            || mm2deEblisIllusionistsPerCommunity() != 1
            || mm2deEblisSpellMin() != 2
            || mm2deEblisSpellMax() != 8
            || mm2deEblisSpellCastingLevel() != 3
            || mm2deEblisIllusionistSpellCount() != 8
            || mm2deEblisFireSaveBonus() != 1
            || mm2deEblisFireDamageBonus() != 1
            || mm2deElectricEelXpValue() != 568
            || mm2deElectricEelXpLevel() != 5
            || mm2deElectricEelDepthMinFeet() != 30
            || mm2deElectricEelDepthMaxFeet() != 150
            || mm2deElectricEelInitiativeBonus() != 1
            || mm2deElectricEelChargePeriodTurns() != 1
            || mm2deElectricEelInnerRadiusFeet() != 5
            || mm2deElectricEelMiddleRadiusFeet() != 10
            || mm2deElectricEelOuterRadiusFeet() != 15
            || mm2deElectricEelInnerDamageMin() != 6
            || mm2deElectricEelInnerDamageMax() != 36
            || mm2deElectricEelMiddleDamageMin() != 4
            || mm2deElectricEelMiddleDamageMax() != 24
            || mm2deElectricEelOuterDamageMin() != 2
            || mm2deElectricEelOuterDamageMax() != 12
            || mm2deElectricEelMiddleSaveBonus() != 1
            || mm2deElectricEelOuterSaveBonus() != 2
            || mm2deGrugachXpValue() != 73
            || mm2deGrugachStrengthDiceBonus() != 2
            || mm2deGrugachStrengthCap() != 18
            || mm2deGrugachStagMountPct() != 70
            || mm2deGrugachMistakenForWoodElfPct() != 20
            || mm2deGrugachTrapCatchPct() != 90
            || mm2deGrugachTrapCarefulCatchPct() != 30
            || mm2deGrugachPitDepthFeet() != 10
            || mm2deGrugachPitFallMin() != 1
            || mm2deGrugachPitFallMax() != 4
            || mm2deGrugachPitSpikeMin() != 1
            || mm2deGrugachPitSpikeMax() != 6
            || mm2deGrugachPitPoisonPct() != 50
            || mm2deGrugachSnareSuspensionFeet() != 5
            || mm2deGrugachDeadfallMinDice() != 5
            || mm2deGrugachDeadfallMaxDice() != 8
            || mm2deGrugachDeadfallDieSides() != 6
            || mm2deValleyElfXpValue() != 75
            || mm2deValleyElfXpLevel() != 3
            || mm2deValleyElfCoosheePct() != 75
            || mm2deValleyElfCoosheeMin() != 1
            || mm2deValleyElfCoosheeMax() != 4
            || mm2deValleyElfCoosheeLairPct() != 90
            || mm2deValleyElfCoosheeLairMin() != 2
            || mm2deValleyElfCoosheeLairMax() != 8
            || mm2deValleyElfRaidTargetCount() != 4
            || mm2deElfinCatXpValue() != 199
            || mm2deElfinCatXpLevel() != 4
            || mm2deElfinCatLeapFeet() != 20
            || mm2deElfinCatEnlargePerDay() != 1
            || mm2deElfinCatReducePerDay() != 2
            || mm2deElfinCatTreePerDay() != 2
            || mm2deElfinCatTripPerDay() != 1
            || mm2deElfinCatSpellLevel() != 9
            || mm2deElfinCatConcealPct() != 90
            || mm2deElfinCatSurprisedIn() != 20
            || mm2deElfinCatSurprisesIn() != 6
            || mm2deHoodXpValue() != 536
            || mm2deHoodXpLevel() != 5
            || mm2deHoodFormCount() != 3
            || mm2deHoodHdNumMin() != 2
            || mm2deHoodHdNumMax() != 6
            || mm2deHoodHdBonusMin() != 2
            || mm2deHoodHdBonusMax() != 6
            || mm2deHoodBiteMin() != 1
            || mm2deHoodBiteMax() != 4
            || mm2deHoodSurpriseMin() != 1
            || mm2deHoodSurpriseMax() != 3
            || mm2deHoodBrandyRounds() != 4
            || mm2deHoodBrandyLossPerRound() != 1
            || mm2deHoodBrandyQuarts() != 1
            || mm2deHoodThicknessInches() != 1
            || mm2deHoodEyeHoles() != 2
            || !mm2deElfHeadIsDoctrineOnlyHeading()
            || !mm2deElfinCatOwnStatBlock()
            || !mm2deEagleDiveDoublesSpeed()
            || !mm2deEagleAlmostNeverSurprised()
            || !mm2deEagleAvoidsDemihumansUnlessHungry()
            || !mm2deEblisCastsByDancingVocalization()
            || !mm2deEblisAttacksByBeakStab()
            || !mm2deElectricEelChargeStunsForDamageRounds()
            || !mm2deElectricEelSaveNegatesOnlyStunning()
            || !mm2deElectricEelWarmShallowSaltWaterOnly()
            || !mm2deGrugachXenophobic()
            || !mm2deGrugachNotMagicUsers()
            || !mm2deGrugachDualClassAreFighterDruids()
            || !mm2deGrugachAllAdultsSetTraps()
            || !mm2deGrugachDeadfallPinsVictim()
            || !mm2deValleyElfUsesCoosheeGuards()
            || !mm2deValleyElfShunnedByOtherElves()
            || !mm2deValleyElfToleratesGnomes()
            || !mm2deValleyElfFollowsMm1ElfStats()
            || !mm2deElfinCatEnlargesToDoubleAttack()
            || !mm2deElfinCatMovesSilently()
            || !mm2deElfinCatLimitedEsp()
            || !mm2deElfinCatSentinelRole()
            || !mm2deElfinCatSpeaksAFewWordsOfElf()
            || !mm2deHoodImmuneToSleepSpells()
            || !mm2deHoodVictimSharesSpellEffects()
            || !mm2deHoodHuntsLikeLurkerAbove()
            || !mm2deHoodStranglesPrey()
        )
            ++bad;
        // THE E-GRID: the 7-row EgStats stat grid (every armor class,
        // hit-dice, bonus, avgHp, attack, xp, xp/hp, lair, move and
        // magic-resistance cell of the 7 letter-E stat blocks, in print
        // order)
        int CEgStats[7][10] = {
            {6,1,3,6,3,35,2,20,1,0},
            {3,4,4,18,4,165,5,50,12,0},
            {6,6,0,21,1,400,8,0,9,0},
            {6,1,1,4,1,65,2,50,15,90},
            {4,1,2,5,1,65,2,10,12,90},
            {4,3,6,16,3,135,4,5,18,20},
            {6,6,6,27,1,320,8,0,6,0},
            };
        for (int b = 0;
             b < mm2deEgStatRows();
             ++b) {
            int vals[10];
            vals[0] = mm2deEgStatAC(b);
            vals[1] = mm2deEgStatHd(b);
            vals[2] = mm2deEgStatHdBonus(b);
            vals[3] = mm2deEgStatAvgHp(b);
            vals[4] = mm2deEgStatAttacks(b);
            vals[5] = mm2deEgStatXp(b);
            vals[6] = mm2deEgStatXpHp(b);
            vals[7] = mm2deEgStatLairPct(b);
            vals[8] = mm2deEgStatMove(b);
            vals[9] = mm2deEgStatMr(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CEgStats[b][c])
                    ++bad;
            }
        }
        // the registry grows by exactly the def count and the gap box flips
        // (the census walk)
    if (mm2deRegistryAfter() - mm2deRegistryBefore() != mm2deDefCount()
            || mm2deDefCount() != 7
            || mm2deEntryCount() != 8
            || mm2deEgStatRows() != 7
            || mm2deGapClosed() != 10
            || mm2deGapOpen() != 27
            || mm2dePriorOwnedEntries() != 2
            || mm2deEuparkeriaOwningRound() != 802
            || mm2deCoosheeOwningRound() != 798
            || mm2deElfHeadSubEntryCount() != 2
        )
            ++bad;
        // each grid xp tile equals its pinned full kill xp (the xpValue
        // formula, pin-vs-pin)
    if (mm2deEgStatXp(0) + mm2deEgStatXpHp(0) * mm2deEgStatAvgHp(0) !=
        mm2deEagleXpValue()
            || mm2deEgStatXp(1) + mm2deEgStatXpHp(1) * mm2deEgStatAvgHp(1) !=
            mm2deEblisXpValue()
            || mm2deEgStatXp(2) + mm2deEgStatXpHp(2) * mm2deEgStatAvgHp(2) !=
            mm2deElectricEelXpValue()
            || mm2deEgStatXp(3) + mm2deEgStatXpHp(3) * mm2deEgStatAvgHp(3) !=
            mm2deGrugachXpValue()
            || mm2deEgStatXp(4) + mm2deEgStatXpHp(4) * mm2deEgStatAvgHp(4) !=
            mm2deValleyElfXpValue()
            || mm2deEgStatXp(5) + mm2deEgStatXpHp(5) * mm2deEgStatAvgHp(5) !=
            mm2deElfinCatXpValue()
            || mm2deEgStatXp(6) + mm2deEgStatXpHp(6) * mm2deEgStatAvgHp(6) !=
            mm2deHoodXpValue()
        )
            ++bad;
        // the electric discharge ladder runs 5, 10 and 15 feet with the 6-36,
        // 4-24 and 2-12 damage bands
    if (mm2deElectricEelInnerRadiusFeet() != 5
            || mm2deElectricEelMiddleRadiusFeet() != 10
            || mm2deElectricEelOuterRadiusFeet() != 15
            || mm2deElectricEelMiddleRadiusFeet() -
            mm2deElectricEelInnerRadiusFeet() != 5
            || mm2deElectricEelOuterRadiusFeet() -
            mm2deElectricEelMiddleRadiusFeet() != 5
            || mm2deElectricEelInnerDamageMin() +
            mm2deElectricEelMiddleDamageMin() +
            mm2deElectricEelOuterDamageMin() != 12
            || mm2deElectricEelInnerDamageMax() +
            mm2deElectricEelMiddleDamageMax() +
            mm2deElectricEelOuterDamageMax() != 72
            || mm2deElectricEelMiddleSaveBonus() != 1
            || mm2deElectricEelOuterSaveBonus() != 2
            || mm2deElectricEelDepthMinFeet() != 30
            || mm2deElectricEelDepthMaxFeet() != 150
            || mm2deElectricEelDepthMaxFeet() - mm2deElectricEelDepthMinFeet()
            != 120
        )
            ++bad;
        // the grugach trap ladder runs 90 to 30 with the spiked pit depth 10
    if (mm2deGrugachTrapCatchPct() != 90
            || mm2deGrugachTrapCarefulCatchPct() != 30
            || mm2deGrugachTrapCatchPct() - mm2deGrugachTrapCarefulCatchPct()
            != 60
            || mm2deGrugachPitDepthFeet() != 10
            || mm2deGrugachPitPoisonPct() != 50
            || mm2deGrugachDeadfallMinDice() + mm2deGrugachDeadfallMaxDice()
            != 13
            || mm2deGrugachDeadfallDieSides() != 6
            || mm2deGrugachStagMountPct() != 70
            || mm2deGrugachMistakenForWoodElfPct() != 20
        )
            ++bad;
        // the eagle rookery band runs 5-12 and the egg market runs 60-100
        // gold pieces
    if (mm2deEagleRookeryPct() != 5
            || mm2deEagleRookeryMin() + mm2deEagleRookeryMax() != 17
            || mm2deEagleEggValueMin() + mm2deEagleEggValueMax() != 160
            || mm2deEagleDiveClawAttacks() != 2
            || mm2deEagleDiveToHitBonus() != 2
            || mm2deEagleDiveDamageMultiplier() != 2
            || mm2deEagleDiveHeightFeet() != 100
            || mm2deEagleTrainablePct() != 25
            || mm2deEagleNestShinyPct() != 10
            || mm2deEagleEggsMin() + mm2deEagleEggsMax() != 5
        )
            ++bad;
        // the eblis hut and spell ladders both run 2-8 at 3rd level ability
    if (mm2deEblisHutsMin() + mm2deEblisHutsMax() != 10
            || mm2deEblisSpellMin() + mm2deEblisSpellMax() != 10
            || mm2deEblisSpellCastingLevel() != 3
            || mm2deEblisIllusionistSpellCount() != 8
            || mm2deEblisIllusionistsPerCommunity() != 1
            || mm2deEblisHutHiddenPct() != 90
            || mm2deEblisEggPct() != 30
            || mm2deEblisTreasurePct() != 25
            || mm2deEblisFireSaveBonus() != 1
            || mm2deEblisFireDamageBonus() != 1
        )
            ++bad;
        // the valley elf cooshee bands run 1-4 wandering and 2-8 in the lair
    if (mm2deValleyElfCoosheePct() != 75
            || mm2deValleyElfCoosheeMin() + mm2deValleyElfCoosheeMax() != 5
            || mm2deValleyElfCoosheeLairPct() != 90
            || mm2deValleyElfCoosheeLairMin() + mm2deValleyElfCoosheeLairMax()
            != 10
            || mm2deValleyElfRaidTargetCount() != 4
        )
            ++bad;
        // the elfin cat spell ladder sums 6 uses per day and the leap runs 20
        // feet
    if (mm2deElfinCatEnlargePerDay() + mm2deElfinCatReducePerDay() +
        mm2deElfinCatTreePerDay() + mm2deElfinCatTripPerDay() != 6
            || mm2deElfinCatSpellLevel() != 9
            || mm2deElfinCatLeapFeet() != 20
            || mm2deElfinCatConcealPct() != 90
            || mm2deElfinCatSurprisedIn() != 20
            || mm2deElfinCatSurprisesIn() != 6
        )
            ++bad;
        // the executioner's hood surprise runs 1-3, the brandy takes 4 rounds
        // and the hit-dice ladder runs 2+2 through 6+6
    if (mm2deHoodSurpriseMin() + mm2deHoodSurpriseMax() != 4
            || mm2deHoodBrandyRounds() != 4
            || mm2deHoodBrandyLossPerRound() != 1
            || mm2deHoodBrandyQuarts() != 1
            || mm2deHoodFormCount() != 3
            || mm2deHoodHdNumMin() + mm2deHoodHdNumMax() != 8
            || mm2deHoodHdBonusMin() + mm2deHoodHdBonusMax() != 8
            || mm2deHoodHdNumMin() != 2
            || mm2deHoodHdNumMax() != 6
            || mm2deHoodBiteMin() + mm2deHoodBiteMax() != 5
            || mm2deHoodThicknessInches() != 1
            || mm2deHoodEyeHoles() != 2
        )
            ++bad;
        printf("R804 MM2 letter E walk audit: bad %d\n", bad);
        if (bad) return 1;
    }
