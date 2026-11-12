    // ---- R919 issue-12 opener audit ----
    // THE DRAGON ISSUE-12 OPENER ROUND, PART ONE - two adjudicated chains,
    // the mythos pair to follow in part two. The Ovalle illusionist article
    // (folios 6-7): the 7-percent-per-level recognition of disguised
    // creatures, the no-fireball-no-lightning restriction, the astral and
    // ethereal attack ability, the trading rules, and the spell ladder from
    // Wall of Fog and Displacement through Feeblemind, the Shadow Magic
    // variants, the Demi Shadow Magic variants, Create Spectres and the
    // seventh-level Alter Reality full wish. The Endersby and Carroll ship
    // cargo article (folio 12): the twelve-unit small and thirty-unit large
    // merchant capacities, the d6 per cargo kind with the one-roll's 1-6
    // units, the overflow-drops-least-valuable rule, the treasure type A
    // roll, the 15 percent passenger chance and the twelve-row value grid
    // with its three sentinel cells.
    {
        using namespace rules;
        int bad = 0;
    if (ilvRecognizePercentPerLevel() != 7
            || ilvWallOfFogMinTurns() != 3
            || ilvWallOfFogMaxTurns() != 12
            || ilvDisplacementMinFeet() != 0
            || ilvDisplacementMaxFeet() != 10
            || ilvDisplacementMinTurns() != 1
            || ilvDisplacementMaxTurns() != 6
            || ilvMultipleHypnosisMinTargets() != 1
            || ilvMultipleHypnosisMaxTargets() != 4
            || ilvHypnotizeMonsterCharmBonus() != 2
            || ilvFeeblemindMuSavePenalty() != 30
            || ilvFeeblemindClericSavePenalty() != 10
            || ilvFingerOfDeathLevelDrain() != 2
            || ilvBladeBarrierMinDamage() != 1
            || ilvBladeBarrierMaxDamage() != 8
            || ilvCauseSeriousWoundsDamage() != 1
            || ilvGazeRangeNearInches() != 6
            || ilvGazeRangeFarInches() != 12
            || ilvPowerWordKillMinHp() != 1
            || ilvPowerWordKillMaxHp() != 4
            || ilvHolyWordMinFirstLevelTypes() != 2
            || ilvHolyWordMaxFirstLevelTypes() != 16
            || ilvPrismaticWallDamageLow() != 2
            || ilvPrismaticWallDamageHigh() != 4
            || ilvIceStormMinDamage() != 1
            || ilvIceStormMaxDamage() != 6
            || ilvMUSpellResearchWaitWeeks() != 2
            || ilvShieldIllusionistSpellLevel() != 4
            || ilvImprovedInvisibilityMuSpellLevel() != 5
            || ilvSecondLevelWaitMultiplier() != 2
            || ilvSpellLadderLevels() != 7
            || ilvSmallMerchantUnits() != 12
            || ilvLargeMerchantUnits() != 30
            || ilvCargoKindDieSides() != 6
            || ilvCargoUnitsMin() != 1
            || ilvCargoUnitsMax() != 6
            || ilvPassengerChancePercent() != 15
            || ilvCargoRows() != 12
            || !ilvRecognizesColleagueWork()
            || !ilvNoFireballOrLightning()
            || !ilvOffensiveSpellsCostlyToTrade()
            || !ilvDefensiveSpellsTradeEasier()
            || !ilvInformationalSpellsFreelyTradeable()
            || !ilvVisionNeverResearchable()
            || !ilvAttacksAstralAndEthereal()
            || !ilvEyeFocusSpellsSilent()
            || !ilvGazeReflectionBouncesVisualOnly()
            || !ilvPosthypnoticSuggestionSaves()
            || !ilvDispelAutoVsMuCast()
            || !ilvPersonalSilenceClone()
            || !ilvImprovedDisplacementUnlimited()
            || !ilvSensoryDisplacementBlinds()
            || !ilvDiscordDelusionEffect()
            || !ilvGazeReflectedBack()
            || !ilvSpectresWeaponImmune()
            || !ilvMUSpellResearchPermanent()
            || !ilvBasiliskGazeTurnsToStone()
            || !ilvAlterRealityFullWish()
            || !ilvCargoAfterSurrenderOnly()
            || !ilvOverflowDropsLeastValuable()
            || !ilvCargoTreasureTypeA()
        )
            ++bad;
        // the cargo value grid - the Spice, Ivory and Foreign-slaves value
        // cells ride the -1 sentinel: Spice and Ivory print blank in the
        // scan, the Foreign slaves cell prints a count (20-60 people) not a
        // gold figure, the count riding the transcript (folio 12)
        int CCG[12][1] = {
            {-1},
            {1000},
            {1000},
            {-1},
            {300},
            {350},
            {250},
            {1000},
            {250},
            {250},
            {100},
            {-1},
            };
        int nCG[1] = {0};
        int eCG[1] = {3};
        for (int b = 0;
             b < ilvCargoRows();
             ++b) {
            int vals[1];
            vals[0] = ilvCargoGoldPerUnit(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CCG[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nCG[c];
            }
        }
        for (int c = 0; c < 1; ++c)
            if (nCG[c] != eCG[c])
                ++bad;
        // the illusionist recognition ladder - 7 percent per level across the
        // seven-level spell ladder (folios 6-7)
    if (ilvRecognizePercentPerLevel() != 7
            || ilvSpellLadderLevels() != 7
        )
            ++bad;
        // the Displacement bounds - the image 0-10 feet out for 1-6 turns
        // plus the caster's level (folio 7)
    if (ilvDisplacementMinFeet() != 0
            || ilvDisplacementMaxFeet() != 10
            || ilvDisplacementMinTurns() != 1
            || ilvDisplacementMaxTurns() != 6
        )
            ++bad;
        // the Feeblemind saves - magic users 30 percent off, clerics 10
        // percent off, illusionists normal (folio 7)
    if (ilvFeeblemindMuSavePenalty() != 30
            || ilvFeeblemindClericSavePenalty() != 10
        )
            ++bad;
        // the Demi Shadow Magic variants - Power Word Kill 1-4 hit points,
        // Holy Word 2-16 first-level types, Prismatic Wall 2 or 4, Ice Storm
        // 1-6, Symbol no effect (folio 7)
    if (ilvPowerWordKillMaxHp() != 4
            || ilvHolyWordMaxFirstLevelTypes() != 16
            || ilvPrismaticWallDamageHigh() != 4
            || ilvIceStormMaxDamage() != 6
        )
            ++bad;
        // the trading ladder - shield a fourth-level illusionist spell,
        // improved invisibility a fifth-level magic-user spell (folio 6)
    if (ilvShieldIllusionistSpellLevel() != 4
            || ilvImprovedInvisibilityMuSpellLevel() != 5
        )
            ++bad;
        // the research waits - two game weeks per failed save, doubled for
        // second-level spells (folio 7)
    if (ilvMUSpellResearchWaitWeeks() != 2
            || ilvSecondLevelWaitMultiplier() != 2
        )
            ++bad;
        // the cargo procedure - twelve units small, thirty large, the d6 per
        // kind with the one-roll's 1-6 units (folio 12)
    if (ilvSmallMerchantUnits() != 12
            || ilvLargeMerchantUnits() != 30
            || ilvCargoKindDieSides() != 6
            || ilvCargoUnitsMax() != 6
        )
            ++bad;
        // the passenger chance - 15 percent, merchants, adventurers or
        // noblemen (folio 12)
    if (ilvPassengerChancePercent() != 15
        )
            ++bad;
        // the thousand-gold cargoes - silk, precious stones and the primitive
        // low-grade jewelry (folio 12)
    if (ilvCargoGoldPerUnit(1) != 1000
            || ilvCargoGoldPerUnit(2) != 1000
            || ilvCargoGoldPerUnit(7) != 1000
        )
            ++bad;
        // the lesser cargoes - precious wood 300, tea 350,
        // cotton/cloth/exotic livestock 250, fruits and vegetables 100 (folio
        // 12)
    if (ilvCargoGoldPerUnit(4) != 300
            || ilvCargoGoldPerUnit(5) != 350
            || ilvCargoGoldPerUnit(6) != 250
            || ilvCargoGoldPerUnit(8) != 250
            || ilvCargoGoldPerUnit(9) != 250
            || ilvCargoGoldPerUnit(10) != 100
        )
            ++bad;
        // the three sentinel cells - spice and ivory print blank, the foreign
        // slaves cell prints a count, all riding the sentinel, noted never
        // silent (folio 12)
    if (ilvCargoGoldPerUnit(0) != -1
            || ilvCargoGoldPerUnit(3) != -1
            || ilvCargoGoldPerUnit(11) != -1
        )
            ++bad;
        printf("R919 issue-12 opener audit: bad %d\n", bad);
        if (bad) return 1;
    }
