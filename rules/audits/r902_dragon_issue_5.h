    // ---- R902 Dragon issue-5 audit ----
    // THE DRAGON ISSUE-5 OPENER ROUND - three adjudicated chains. The
    // Witchcraft Supplement (folios 4-9, the anonymous ms.): the encounter
    // doctrine (rolls 5 or 7, witches present 50 percent of the time, the
    // 35/65 alignment split), the 12-sided Order ladder (Low 1-8, High 9-11,
    // Secret 12 - one Secret means all Secret), the Secret witch doctrines
    // (75 percent in lair, any terrain, the loner law, no brooms or balls or
    // familiar, the 50 percent sneak, the 13th-level item bar, the
    // cleric-touch instant death, the no-dispel Group B), the spell quotas
    // (good 7, the 4 percent ancient Priestess with ten daily and one weekly
    // at 11th-level saves, Low 4 Minor, High 4 Minor and 2 Major, Secret 6
    // Group A and 3 Group B), the immunities (witchcraft never affecting
    // Djinn, Efreet or Clerics; the concentration circle; the cleric
    // poison-touch immunity), the trade economy (the willingness die
    // 1-3/4/5-6, Table A 6-15k and Table B 10-50k plus magic items, the 10 gp
    // instructress fee, the 20 percent map cut, the 1-4 alliance die), the
    // witch items (the Skull of Death 5 points per turn and 3 dice undead
    // command, the Luck Charm d20, the Guardian Egg at 250 gp weight and
    // 48-hour reuse with its armor-class-2 Hill Giant 8, Roc 8 and Dragon
    // Turtle 10 dice forms, the Hornet Cape at 36 inches with three 7-inch
    // 3-dice stings, the Seed Satchel 7-12, the Witch Wand 7 spells, the
    // Serpent Belt 10-foot 2-dice, the Love Locket 20 percent and 2 items,
    // the Dart Ring twice per 30 feet, the 40-foot 4-dice Thorn Twine, the
    // 1-3 Hill Seeds), the spell matrix as a 21-row range/duration table with
    // 0 the no-printed-duration sentinel, and the lair treasure as a 4-row
    // cache table by lair type with the Good lair's 1-10 thousand SP and the
    // Secret lair's ring and Secret-item extras riding this note. The Anhkheg
    // (folios 12, 28): the Featured Creature's first magazine appearance,
    // pinned lore-against-def - the merged MM1 ankheg def exists at
    // monsters/monsters/a/ankheg.lua, so this is a provenance pin, never a
    // competing def; the stat block (1-6 appearing, 10-20 feet, armor class 2
    // over and 4 under, 12/6 move, 3-8 hit dice on the 8-sided die, 25
    // percent in lair, treasure B2, bite 3-18, the 1-6-dice acid squirt at 30
    // feet once per six hours, the 1-10 enzyme, the 5-10 foot ambush depth)
    // with every print divergence from the def noted (lair 25 vs 15, enzyme
    // 1-10 vs 1-4, B2 vs C, the acid squirt vs the def 8-32). The Wizard
    // Research Rules (folios 24-26, 28, Goforth): the research ladder as a
    // 10-row table - weeks equal the spell level, the standard investment
    // doubling per level from 2,000 and the certain line from 10,000 at the
    // flat 20 percent success chance - the once-per-stat permanent stat
    // spell, the +1 enchanting at 2 months and 2,000 gp, serious enchanting
    // at 10 months and 10,000 gp, the duplication at 10,000 gp and 10 months
    // times the table number, the ringmaking ladders (serious 10,000 and 10
    // months; the True Ring at 300,000 xp drained; the Wizard Blade at
    // 200,000 xp with the d8 property roll over the 11-property list and the
    // +6 to -6 named level, the larger 12/16/20-sided dice at
    // 300k/400k/500k), the unlimited ring charges against the 100-charge
    // wands and staffs, the no-reenchanting law, and the Memorial Enchanting
    // In Distress d8 hits. The garbled wilderness encounter grid at folio 4
    // is scoped out on OCR garble per the standing caution.
    {
        using namespace rules;
        int bad = 0;
    if (wchAnhkhegNaMin() != 1
            || wchAnhkhegNaMax() != 6
            || wchAnhkhegLengthMin() != 10
            || wchAnhkhegLengthMax() != 20
            || wchAnhkhegAcOverall() != 2
            || wchAnhkhegAcUnder() != 4
            || wchAnhkhegMoveSurface() != 12
            || wchAnhkhegMoveBurrow() != 6
            || wchAnhkhegHdMin() != 3
            || wchAnhkhegHdMax() != 8
            || wchAnhkhegHdDieSides() != 8
            || wchAnhkhegLairPct() != 25
            || wchAnhkhegBiteMin() != 3
            || wchAnhkhegBiteMax() != 18
            || wchAnhkhegAcidDiceMax() != 6
            || wchAnhkhegAcidRangeFeet() != 30
            || wchAnhkhegAcidRechargeHours() != 6
            || wchAnhkhegEnzymeMin() != 1
            || wchAnhkhegEnzymeMax() != 10
            || wchAnhkhegAmbushMin() != 5
            || wchAnhkhegAmbushMax() != 10
            || wchWitchWildRollA() != 5
            || wchWitchWildRollB() != 7
            || wchWitchLawfulPct() != 35
            || wchWitchChaoticPct() != 65
            || wchWitchOrderDieSides() != 12
            || wchWitchOrderLowMin() != 1
            || wchWitchOrderLowMax() != 8
            || wchWitchOrderHighMin() != 9
            || wchWitchOrderHighMax() != 11
            || wchWitchOrderSecretRoll() != 12
            || wchSecretWitchLairPct() != 75
            || wchGoodWitchSpellsDaily() != 7
            || wchPriestessAncientPct() != 4
            || wchPriestessSpellsDaily() != 10
            || wchPriestessWeeklySpells() != 1
            || wchPriestessSaveLevel() != 11
            || wchLowWitchMinorDaily() != 4
            || wchHighWitchMinorDaily() != 4
            || wchHighWitchMajorDaily() != 2
            || wchSecretGroupADaily() != 6
            || wchSecretGroupBDaily() != 3
            || wchSecretWitchSneakPct() != 50
            || wchSecretItemMinLevel() != 13
            || wchPriestessLocatePriceGp() != 10000
            || wchWitchTrainFeeGp() != 10
            || wchSellDieWillingMax() != 3
            || wchSellDieDoubleRoll() != 4
            || wchSellDieRefuseMin() != 5
            || wchSellDieRefuseMax() != 6
            || wchTableACostMin() != 6000
            || wchTableACostMax() != 15000
            || wchTableBCostMin() != 10000
            || wchTableBCostMax() != 50000
            || wchTreasureMapCutPct() != 20
            || wchMapAllianceRollMax() != 4
            || wchSkullRegenPerTurn() != 5
            || wchSkullUndeadDiceMax() != 3
            || wchLuckCharmDieSides() != 20
            || wchGuardianEggWeightGp() != 250
            || wchGuardianEggReuseHours() != 48
            || wchGuardianEggServantAc() != 2
            || wchGuardianEggGiantDice() != 8
            || wchGuardianEggRocDice() != 8
            || wchGuardianEggTurtleDice() != 10
            || wchHornetCapeSpeed() != 36
            || wchHornetCapeCommandRange() != 50
            || wchHornetCapeStingsPerTurn() != 3
            || wchHornetCapeStingRange() != 7
            || wchHornetCapeStingDice() != 3
            || wchSeedSatchelMin() != 7
            || wchSeedSatchelMax() != 12
            || wchSeedFeatureHours() != 1
            || wchWandSpellsDaily() != 7
            || wchSerpentBeltStretchFeet() != 10
            || wchSerpentBeltDamageDice() != 2
            || wchPotionCauldronLairMin() != 3
            || wchPotionPriceMin() != 500
            || wchPotionPriceMax() != 3000
            || wchBroomFlyingPct() != 35
            || wchLoveLocketCutPct() != 20
            || wchLoveLocketItemMax() != 2
            || wchDartRingShotsPerTurn() != 2
            || wchDartRingRangeFeet() != 30
            || wchThornTwineLengthFeet() != 40
            || wchThornTwineDicePerTurn() != 4
            || wchHillSeedNumberMin() != 1
            || wchHillSeedNumberMax() != 3
            || wchSpellMatrixCount() != 21
            || wchLairTreasureCount() != 4
            || wchResearchSuccessPct() != 20
            || wchEnchantPlusOneMonths() != 2
            || wchEnchantPlusOneGp() != 2000
            || wchSeriousEnchantMonths() != 10
            || wchSeriousEnchantGp() != 10000
            || wchDuplicateGp() != 10000
            || wchDuplicateMonths() != 10
            || wchRingMakeGp() != 10000
            || wchRingMakeMonths() != 10
            || wchTrueRingGp() != 10000
            || wchTrueRingMonths() != 10
            || wchTrueRingXp() != 300000
            || wchWizardBladeGp() != 10000
            || wchWizardBladeMonths() != 10
            || wchWizardBladeXp() != 200000
            || wchWizardBladeDieSides() != 8
            || wchWizardBladePropertyCount() != 11
            || wchWizardBladeLevelMax() != 6
            || wchWizardBladeLevelMin() != -6
            || wchWandStaffCharges() != 100
            || wchMemorialEnchantDie() != 8
            || wchBladeLargerDie300k() != 12
            || wchBladeLargerDie400k() != 16
            || wchBladeLargerDie500k() != 20
            || wchResearchCostCount() != 10
            || !wchAnhkhegLoreAgainstDef()
            || !wchAnhkhegPrintDivergent()
            || !wchAnhkhegTreasureB2()
            || !wchAnhkhegNeutral()
            || !wchAnhkhegNoMagicResistance()
            || !wchAnhkhegBurrowHunter()
            || !wchWitchImmunities()
            || !wchWitchSavesAsWarlock()
            || !wchWitchMagicTreatedAsSpell()
            || !wchSecretWitchLoner()
            || !wchSecretWitchAnyTerrain()
            || !wchSecretWitchNoGear()
            || !wchSecretItemClericDeath()
            || !wchSecretItemsGroupBNoDispel()
            || !wchLairNoHighOnly()
            || !wchLawfulLairNoCurseGuard()
            || !wchGoodWitchPolymorphFamiliar()
            || !wchConcentrationImmune()
            || !wchClericPoisonTouchImmune()
            || !wchStatSpellOncePerStat()
            || !wchEmbeddedRingsUnlimited()
            || !wchNoReenchant()
            || !wchOnlyEnchantersCreate()
        )
            ++bad;
        // the Witchcraft Supplement spell matrix - range and duration as
        // printed: Pit 5, FireBox 7/6, Diminish 10/6, Plant Entrapment 5/2,
        // Paralyzing Pit 7/3, Undead Control 10/4, Aging 2, Circle of
        // Blindness 7/3, Curse 1, Curtain Wall 2/3, Intensify 15/1, Wither 7,
        // Weight Concentration 10/6, Quake 50/2, Vaporize 3, Solidify 3,
        // Volcanic Circle 8/2, Calm 7/6, Rejuvenation 1, Dissipation 5,
        // Comfort 2/36 (folios 4-7)
        int CSpMx[21][2] = {
            {5,0},
            {7,6},
            {10,6},
            {5,2},
            {7,3},
            {10,4},
            {2,0},
            {7,3},
            {1,0},
            {2,3},
            {15,1},
            {7,0},
            {10,6},
            {50,2},
            {3,0},
            {3,0},
            {8,2},
            {7,6},
            {1,0},
            {5,0},
            {2,36},
            };
        for (int b = 0;
             b < wchSpellMatrixCount();
             ++b) {
            int vals[2];
            vals[0] = wchSpellRange(b);
            vals[1] = wchSpellDuration(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CSpMx[b][c])
                    ++bad;
            }
        }
        // the lair treasure caches by lair type - Good 1-4k GP with 1-10k SP
        // riding the audit note, Low 1-6k, High 11-20k, Secret 1-4k with the
        // gems of superior value and no printed jewelry line; the Secret lair
        // extras (1 ring, 1-2 Secret witch items) ride the audit note (folio
        // 8)
        int CLrTr[4][8] = {
            {1,4,1,10,1,8,1,3},
            {1,6,6,11,1,10,1,3},
            {11,20,6,11,1,8,1,2},
            {1,4,1,3,0,0,1,6},
            };
        for (int b = 0;
             b < wchLairTreasureCount();
             ++b) {
            int vals[8];
            vals[0] = wchLairGpMin(b);
            vals[1] = wchLairGpMax(b);
            vals[2] = wchLairGemMin(b);
            vals[3] = wchLairGemMax(b);
            vals[4] = wchLairJewMin(b);
            vals[5] = wchLairJewMax(b);
            vals[6] = wchLairWiMin(b);
            vals[7] = wchLairWiMax(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != CLrTr[b][c])
                    ++bad;
            }
        }
        // the spell research cost ladder by spell level 1-10 - weeks equal
        // the level, the standard investment doubling per level from 2,000
        // and the certain line from 10,000 (folio 24)
        int CRsC[10][3] = {
            {1,2000,10000},
            {2,4000,20000},
            {3,8000,40000},
            {4,16000,80000},
            {5,32000,160000},
            {6,64000,320000},
            {7,128000,640000},
            {8,256000,1280000},
            {9,512000,2560000},
            {10,1024000,5120000},
            };
        for (int b = 0;
             b < wchResearchCostCount();
             ++b) {
            int vals[3];
            vals[0] = wchResearchWeeks(b);
            vals[1] = wchResearchGold(b);
            vals[2] = wchResearchGoldCertain(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CRsC[b][c])
                    ++bad;
            }
        }
        // the Anhkheg stat block - number appearing 1-6, length 10-20 feet
        // (folio 12)
    if (wchAnhkhegNaMin() != 1
            || wchAnhkhegNaMax() != 6
            || wchAnhkhegLengthMin() != 10
            || wchAnhkhegLengthMax() != 20
        )
            ++bad;
        // the Anhkheg armor classes 2 over and 4 under, the 12/6 movement
        // (folio 12)
    if (wchAnhkhegAcOverall() != 2
            || wchAnhkhegAcUnder() != 4
            || wchAnhkhegMoveSurface() != 12
            || wchAnhkhegMoveBurrow() != 6
        )
            ++bad;
        // the Anhkheg hit dice 3-8 on the 8-sided die, 25 percent in lair
        // (folio 12)
    if (wchAnhkhegHdMin() != 3
            || wchAnhkhegHdMax() != 8
            || wchAnhkhegHdDieSides() != 8
            || wchAnhkhegLairPct() != 25
        )
            ++bad;
        // the Anhkheg bite 3-18, the acid squirt up to 1-6 dice at 30 feet
        // once per six hours (folios 12, 28)
    if (wchAnhkhegBiteMin() != 3
            || wchAnhkhegBiteMax() != 18
            || wchAnhkhegAcidDiceMax() != 6
            || wchAnhkhegAcidRangeFeet() != 30
            || wchAnhkhegAcidRechargeHours() != 6
        )
            ++bad;
        // the Anhkheg enzyme 1-10 per turn, the 5-10 foot ambush depth (folio
        // 28)
    if (wchAnhkhegEnzymeMin() != 1
            || wchAnhkhegEnzymeMax() != 10
            || wchAnhkhegAmbushMin() != 5
            || wchAnhkhegAmbushMax() != 10
        )
            ++bad;
        // the Anhkheg doctrines - lore-against-def against the merged MM1
        // ankheg, the divergences noted, treasure B2, neutral, no magic
        // resistance, the burrow ambush (folios 12, 28)
    if (wchAnhkhegLoreAgainstDef() != 1
            || wchAnhkhegPrintDivergent() != 1
            || wchAnhkhegTreasureB2() != 1
            || wchAnhkhegNeutral() != 1
            || wchAnhkhegNoMagicResistance() != 1
            || wchAnhkhegBurrowHunter() != 1
        )
            ++bad;
        // the witch encounter doctrine - rolls 5 or 7, the 35/65
        // Lawful/Chaotic split (folio 4)
    if (wchWitchWildRollA() != 5
            || wchWitchWildRollB() != 7
            || wchWitchLawfulPct() != 35
            || wchWitchChaoticPct() != 65
        )
            ++bad;
        // the 12-sided Order check - Low 1-8, High 9-11, Secret 12; the
        // Secret lair percent (folio 4)
    if (wchWitchOrderDieSides() != 12
            || wchWitchOrderLowMin() != 1
            || wchWitchOrderLowMax() != 8
            || wchWitchOrderHighMin() != 9
            || wchWitchOrderHighMax() != 11
            || wchWitchOrderSecretRoll() != 12
            || wchSecretWitchLairPct() != 75
        )
            ++bad;
        // the good witch 7 spells daily, the 4 percent ancient Priestess -
        // ten daily, one weekly, 11th level saves, the 10,000 gp locate
        // (folio 4)
    if (wchGoodWitchSpellsDaily() != 7
            || wchPriestessAncientPct() != 4
            || wchPriestessSpellsDaily() != 10
            || wchPriestessWeeklySpells() != 1
            || wchPriestessSaveLevel() != 11
            || wchPriestessLocatePriceGp() != 10000
        )
            ++bad;
        // the spell quotas - Low 4 Minor, High 4 Minor + 2 Major, Secret 6
        // Group A + 3 Group B, the 50 percent sneak (folios 4, 7)
    if (wchLowWitchMinorDaily() != 4
            || wchHighWitchMinorDaily() != 4
            || wchHighWitchMajorDaily() != 2
            || wchSecretGroupADaily() != 6
            || wchSecretGroupBDaily() != 3
            || wchSecretWitchSneakPct() != 50
        )
            ++bad;
        // the trade economy - the 13th level Secret item bar, the 10 gp
        // instructress fee, the Table A and B price bands (folios 7, 8, 9)
    if (wchSecretItemMinLevel() != 13
            || wchWitchTrainFeeGp() != 10
            || wchTableACostMin() != 6000
            || wchTableACostMax() != 15000
            || wchTableBCostMin() != 10000
            || wchTableBCostMax() != 50000
        )
            ++bad;
        // the willingness die 1-3/4/5-6, the 20 percent map cut, the 1-4
        // alliance die (folio 9)
    if (wchSellDieWillingMax() != 3
            || wchSellDieDoubleRoll() != 4
            || wchSellDieRefuseMin() != 5
            || wchSellDieRefuseMax() != 6
            || wchTreasureMapCutPct() != 20
            || wchMapAllianceRollMax() != 4
        )
            ++bad;
        // the Secret weapons - the Skull of Death 5 points per turn regen and
        // 3 dice undead command, the Luck Charm d20 (folios 7, 9, 28)
    if (wchSkullRegenPerTurn() != 5
            || wchSkullUndeadDiceMax() != 3
            || wchLuckCharmDieSides() != 20
        )
            ++bad;
        // the Guardian Egg - 250 gp weight, 48 hour reuse, armor class 2, the
        // Hill Giant 8, Roc 8 and Dragon Turtle 10 dice forms (folio 9)
    if (wchGuardianEggWeightGp() != 250
            || wchGuardianEggReuseHours() != 48
            || wchGuardianEggServantAc() != 2
            || wchGuardianEggGiantDice() != 8
            || wchGuardianEggRocDice() != 8
            || wchGuardianEggTurtleDice() != 10
        )
            ++bad;
        // the Hornet Cape - 36 inches per turn, the 50 inch command, three
        // 7-inch 3-dice stings per turn (folio 8)
    if (wchHornetCapeSpeed() != 36
            || wchHornetCapeCommandRange() != 50
            || wchHornetCapeStingsPerTurn() != 3
            || wchHornetCapeStingRange() != 7
            || wchHornetCapeStingDice() != 3
        )
            ++bad;
        // the Seed Satchel 7-12 seeds, one-hour features; the Hill Seeds 1-3
        // (folios 8, 9)
    if (wchSeedSatchelMin() != 7
            || wchSeedSatchelMax() != 12
            || wchSeedFeatureHours() != 1
            || wchHillSeedNumberMin() != 1
            || wchHillSeedNumberMax() != 3
        )
            ++bad;
        // the Witch Wand 7 spells, the Serpent Belt 10-foot 2-dice, the
        // cauldron at 3+ witches, the 500-3000 potions, the 35 percent broom
        // (folios 7, 8)
    if (wchWandSpellsDaily() != 7
            || wchSerpentBeltStretchFeet() != 10
            || wchSerpentBeltDamageDice() != 2
            || wchPotionCauldronLairMin() != 3
            || wchPotionPriceMin() != 500
            || wchPotionPriceMax() != 3000
            || wchBroomFlyingPct() != 35
        )
            ++bad;
        // the good witch Love Locket 20 percent and 2 items, the Dart Ring
        // twice per 30 feet, the 40-foot 4-dice Thorn Twine (folio 9)
    if (wchLoveLocketCutPct() != 20
            || wchLoveLocketItemMax() != 2
            || wchDartRingShotsPerTurn() != 2
            || wchDartRingRangeFeet() != 30
            || wchThornTwineLengthFeet() != 40
            || wchThornTwineDicePerTurn() != 4
        )
            ++bad;
        // the witch doctrines - the Djinn/Efreet/Cleric immunity, warlock
        // saves, the spell save treatment, the cleric poison-touch immunity
        // (folios 4, 5)
    if (wchWitchImmunities() != 1
            || wchWitchSavesAsWarlock() != 1
            || wchWitchMagicTreatedAsSpell() != 1
            || wchClericPoisonTouchImmune() != 1
        )
            ++bad;
        // the Secret Order doctrines - loner, any terrain, no gear, the
        // cleric-touch death, the no-dispel Group B (folios 4, 7)
    if (wchSecretWitchLoner() != 1
            || wchSecretWitchAnyTerrain() != 1
            || wchSecretWitchNoGear() != 1
            || wchSecretItemClericDeath() != 1
            || wchSecretItemsGroupBNoDispel() != 1
        )
            ++bad;
        // the lair doctrines - no High-only lairs, no Lawful curse guard, the
        // good witch polymorph familiar, the concentration immunity (folio 8)
    if (wchLairNoHighOnly() != 1
            || wchLawfulLairNoCurseGuard() != 1
            || wchGoodWitchPolymorphFamiliar() != 1
            || wchConcentrationImmune() != 1
        )
            ++bad;
        // the wchSpellMatrix, row 0 of 21 - the Witchcraft Supplement spell
        // matrix - range and duration as printed: Pit 5, FireBox 7/6,
        // Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead
        // Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain
        // Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6,
        // Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6,
        // Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)
    if (wchSpellRange(0) != 5
            || wchSpellDuration(0) != 0
            || wchSpellMatrixCount() != 21
        )
            ++bad;
        // the wchSpellMatrix, row 1 of 21 - the Witchcraft Supplement spell
        // matrix - range and duration as printed: Pit 5, FireBox 7/6,
        // Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead
        // Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain
        // Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6,
        // Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6,
        // Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)
    if (wchSpellRange(1) != 7
            || wchSpellDuration(1) != 6
        )
            ++bad;
        // the wchSpellMatrix, row 2 of 21 - the Witchcraft Supplement spell
        // matrix - range and duration as printed: Pit 5, FireBox 7/6,
        // Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead
        // Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain
        // Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6,
        // Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6,
        // Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)
    if (wchSpellRange(2) != 10
            || wchSpellDuration(2) != 6
        )
            ++bad;
        // the wchSpellMatrix, row 3 of 21 - the Witchcraft Supplement spell
        // matrix - range and duration as printed: Pit 5, FireBox 7/6,
        // Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead
        // Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain
        // Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6,
        // Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6,
        // Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)
    if (wchSpellRange(3) != 5
            || wchSpellDuration(3) != 2
        )
            ++bad;
        // the wchSpellMatrix, row 4 of 21 - the Witchcraft Supplement spell
        // matrix - range and duration as printed: Pit 5, FireBox 7/6,
        // Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead
        // Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain
        // Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6,
        // Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6,
        // Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)
    if (wchSpellRange(4) != 7
            || wchSpellDuration(4) != 3
        )
            ++bad;
        // the wchSpellMatrix, row 5 of 21 - the Witchcraft Supplement spell
        // matrix - range and duration as printed: Pit 5, FireBox 7/6,
        // Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead
        // Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain
        // Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6,
        // Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6,
        // Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)
    if (wchSpellRange(5) != 10
            || wchSpellDuration(5) != 4
        )
            ++bad;
        // the wchSpellMatrix, row 6 of 21 - the Witchcraft Supplement spell
        // matrix - range and duration as printed: Pit 5, FireBox 7/6,
        // Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead
        // Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain
        // Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6,
        // Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6,
        // Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)
    if (wchSpellRange(6) != 2
            || wchSpellDuration(6) != 0
        )
            ++bad;
        // the wchSpellMatrix, row 7 of 21 - the Witchcraft Supplement spell
        // matrix - range and duration as printed: Pit 5, FireBox 7/6,
        // Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead
        // Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain
        // Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6,
        // Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6,
        // Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)
    if (wchSpellRange(7) != 7
            || wchSpellDuration(7) != 3
        )
            ++bad;
        // the wchSpellMatrix, row 8 of 21 - the Witchcraft Supplement spell
        // matrix - range and duration as printed: Pit 5, FireBox 7/6,
        // Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead
        // Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain
        // Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6,
        // Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6,
        // Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)
    if (wchSpellRange(8) != 1
            || wchSpellDuration(8) != 0
        )
            ++bad;
        // the wchSpellMatrix, row 9 of 21 - the Witchcraft Supplement spell
        // matrix - range and duration as printed: Pit 5, FireBox 7/6,
        // Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead
        // Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain
        // Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6,
        // Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6,
        // Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)
    if (wchSpellRange(9) != 2
            || wchSpellDuration(9) != 3
        )
            ++bad;
        // the wchSpellMatrix, row 10 of 21 - the Witchcraft Supplement spell
        // matrix - range and duration as printed: Pit 5, FireBox 7/6,
        // Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead
        // Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain
        // Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6,
        // Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6,
        // Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)
    if (wchSpellRange(10) != 15
            || wchSpellDuration(10) != 1
        )
            ++bad;
        // the wchSpellMatrix, row 11 of 21 - the Witchcraft Supplement spell
        // matrix - range and duration as printed: Pit 5, FireBox 7/6,
        // Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead
        // Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain
        // Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6,
        // Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6,
        // Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)
    if (wchSpellRange(11) != 7
            || wchSpellDuration(11) != 0
        )
            ++bad;
        // the wchSpellMatrix, row 12 of 21 - the Witchcraft Supplement spell
        // matrix - range and duration as printed: Pit 5, FireBox 7/6,
        // Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead
        // Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain
        // Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6,
        // Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6,
        // Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)
    if (wchSpellRange(12) != 10
            || wchSpellDuration(12) != 6
        )
            ++bad;
        // the wchSpellMatrix, row 13 of 21 - the Witchcraft Supplement spell
        // matrix - range and duration as printed: Pit 5, FireBox 7/6,
        // Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead
        // Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain
        // Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6,
        // Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6,
        // Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)
    if (wchSpellRange(13) != 50
            || wchSpellDuration(13) != 2
        )
            ++bad;
        // the wchSpellMatrix, row 14 of 21 - the Witchcraft Supplement spell
        // matrix - range and duration as printed: Pit 5, FireBox 7/6,
        // Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead
        // Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain
        // Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6,
        // Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6,
        // Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)
    if (wchSpellRange(14) != 3
            || wchSpellDuration(14) != 0
        )
            ++bad;
        // the wchSpellMatrix, row 15 of 21 - the Witchcraft Supplement spell
        // matrix - range and duration as printed: Pit 5, FireBox 7/6,
        // Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead
        // Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain
        // Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6,
        // Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6,
        // Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)
    if (wchSpellRange(15) != 3
            || wchSpellDuration(15) != 0
        )
            ++bad;
        // the wchSpellMatrix, row 16 of 21 - the Witchcraft Supplement spell
        // matrix - range and duration as printed: Pit 5, FireBox 7/6,
        // Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead
        // Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain
        // Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6,
        // Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6,
        // Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)
    if (wchSpellRange(16) != 8
            || wchSpellDuration(16) != 2
        )
            ++bad;
        // the wchSpellMatrix, row 17 of 21 - the Witchcraft Supplement spell
        // matrix - range and duration as printed: Pit 5, FireBox 7/6,
        // Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead
        // Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain
        // Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6,
        // Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6,
        // Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)
    if (wchSpellRange(17) != 7
            || wchSpellDuration(17) != 6
        )
            ++bad;
        // the wchSpellMatrix, row 18 of 21 - the Witchcraft Supplement spell
        // matrix - range and duration as printed: Pit 5, FireBox 7/6,
        // Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead
        // Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain
        // Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6,
        // Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6,
        // Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)
    if (wchSpellRange(18) != 1
            || wchSpellDuration(18) != 0
        )
            ++bad;
        // the wchSpellMatrix, row 19 of 21 - the Witchcraft Supplement spell
        // matrix - range and duration as printed: Pit 5, FireBox 7/6,
        // Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead
        // Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain
        // Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6,
        // Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6,
        // Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)
    if (wchSpellRange(19) != 5
            || wchSpellDuration(19) != 0
        )
            ++bad;
        // the wchSpellMatrix, row 20 of 21 - the Witchcraft Supplement spell
        // matrix - range and duration as printed: Pit 5, FireBox 7/6,
        // Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead
        // Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain
        // Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6,
        // Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6,
        // Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)
    if (wchSpellRange(20) != 2
            || wchSpellDuration(20) != 36
        )
            ++bad;
        // the wchLairTreasure, row 0 of 4 - the lair treasure caches by lair
        // type - Good 1-4k GP with 1-10k SP riding the audit note, Low 1-6k,
        // High 11-20k, Secret 1-4k with the gems of superior value and no
        // printed jewelry line; the Secret lair extras (1 ring, 1-2 Secret
        // witch items) ride the audit note (folio 8)
    if (wchLairGpMin(0) != 1
            || wchLairGpMax(0) != 4
            || wchLairGemMin(0) != 1
            || wchLairGemMax(0) != 10
            || wchLairJewMin(0) != 1
            || wchLairJewMax(0) != 8
            || wchLairWiMin(0) != 1
            || wchLairWiMax(0) != 3
            || wchLairTreasureCount() != 4
        )
            ++bad;
        // the wchLairTreasure, row 1 of 4 - the lair treasure caches by lair
        // type - Good 1-4k GP with 1-10k SP riding the audit note, Low 1-6k,
        // High 11-20k, Secret 1-4k with the gems of superior value and no
        // printed jewelry line; the Secret lair extras (1 ring, 1-2 Secret
        // witch items) ride the audit note (folio 8)
    if (wchLairGpMin(1) != 1
            || wchLairGpMax(1) != 6
            || wchLairGemMin(1) != 6
            || wchLairGemMax(1) != 11
            || wchLairJewMin(1) != 1
            || wchLairJewMax(1) != 10
            || wchLairWiMin(1) != 1
            || wchLairWiMax(1) != 3
        )
            ++bad;
        // the wchLairTreasure, row 2 of 4 - the lair treasure caches by lair
        // type - Good 1-4k GP with 1-10k SP riding the audit note, Low 1-6k,
        // High 11-20k, Secret 1-4k with the gems of superior value and no
        // printed jewelry line; the Secret lair extras (1 ring, 1-2 Secret
        // witch items) ride the audit note (folio 8)
    if (wchLairGpMin(2) != 11
            || wchLairGpMax(2) != 20
            || wchLairGemMin(2) != 6
            || wchLairGemMax(2) != 11
            || wchLairJewMin(2) != 1
            || wchLairJewMax(2) != 8
            || wchLairWiMin(2) != 1
            || wchLairWiMax(2) != 2
        )
            ++bad;
        // the wchLairTreasure, row 3 of 4 - the lair treasure caches by lair
        // type - Good 1-4k GP with 1-10k SP riding the audit note, Low 1-6k,
        // High 11-20k, Secret 1-4k with the gems of superior value and no
        // printed jewelry line; the Secret lair extras (1 ring, 1-2 Secret
        // witch items) ride the audit note (folio 8)
    if (wchLairGpMin(3) != 1
            || wchLairGpMax(3) != 4
            || wchLairGemMin(3) != 1
            || wchLairGemMax(3) != 3
            || wchLairJewMin(3) != 0
            || wchLairJewMax(3) != 0
            || wchLairWiMin(3) != 1
            || wchLairWiMax(3) != 6
        )
            ++bad;
        // the research base - 20 percent success, the +1 at 2 months and
        // 2,000 gp, serious enchanting 10 months and 10,000 gp (folio 24)
    if (wchResearchSuccessPct() != 20
            || wchEnchantPlusOneMonths() != 2
            || wchEnchantPlusOneGp() != 2000
            || wchSeriousEnchantMonths() != 10
            || wchSeriousEnchantGp() != 10000
        )
            ++bad;
        // the duplication and serious ringmaking costs (folio 26)
    if (wchDuplicateGp() != 10000
            || wchDuplicateMonths() != 10
            || wchRingMakeGp() != 10000
            || wchRingMakeMonths() != 10
        )
            ++bad;
        // the True Ring - 10,000 gp, 10 months, 300,000 experience points
        // (folio 26)
    if (wchTrueRingGp() != 10000
            || wchTrueRingMonths() != 10
            || wchTrueRingXp() != 300000
        )
            ++bad;
        // the Wizard Blade - 10,000 gp, 10 months, 200,000 xp, the d8
        // property roll over 11 properties, the named level +6 to -6 (folio
        // 26)
    if (wchWizardBladeGp() != 10000
            || wchWizardBladeMonths() != 10
            || wchWizardBladeXp() != 200000
            || wchWizardBladeDieSides() != 8
            || wchWizardBladePropertyCount() != 11
            || wchWizardBladeLevelMax() != 6
            || wchWizardBladeLevelMin() != -6
        )
            ++bad;
        // the 100-charge wands and staffs, the Memorial d8 distress hits, the
        // larger blade dice at 300k/400k/500k xp (folios 26, 28)
    if (wchWandStaffCharges() != 100
            || wchMemorialEnchantDie() != 8
            || wchBladeLargerDie300k() != 12
            || wchBladeLargerDie400k() != 16
            || wchBladeLargerDie500k() != 20
        )
            ++bad;
        // the research doctrines - once per stat, unlimited ring charges, no
        // re-enchanting, only the four creator classes (folios 24, 26)
    if (wchStatSpellOncePerStat() != 1
            || wchEmbeddedRingsUnlimited() != 1
            || wchNoReenchant() != 1
            || wchOnlyEnchantersCreate() != 1
        )
            ++bad;
        // the wchResearchCost, row 0 of 10 - the spell research cost ladder
        // by spell level 1-10 - weeks equal the level, the standard
        // investment doubling per level from 2,000 and the certain line from
        // 10,000 (folio 24)
    if (wchResearchWeeks(0) != 1
            || wchResearchGold(0) != 2000
            || wchResearchGoldCertain(0) != 10000
            || wchResearchCostCount() != 10
        )
            ++bad;
        // the wchResearchCost, row 1 of 10 - the spell research cost ladder
        // by spell level 1-10 - weeks equal the level, the standard
        // investment doubling per level from 2,000 and the certain line from
        // 10,000 (folio 24)
    if (wchResearchWeeks(1) != 2
            || wchResearchGold(1) != 4000
            || wchResearchGoldCertain(1) != 20000
        )
            ++bad;
        // the wchResearchCost, row 2 of 10 - the spell research cost ladder
        // by spell level 1-10 - weeks equal the level, the standard
        // investment doubling per level from 2,000 and the certain line from
        // 10,000 (folio 24)
    if (wchResearchWeeks(2) != 3
            || wchResearchGold(2) != 8000
            || wchResearchGoldCertain(2) != 40000
        )
            ++bad;
        // the wchResearchCost, row 3 of 10 - the spell research cost ladder
        // by spell level 1-10 - weeks equal the level, the standard
        // investment doubling per level from 2,000 and the certain line from
        // 10,000 (folio 24)
    if (wchResearchWeeks(3) != 4
            || wchResearchGold(3) != 16000
            || wchResearchGoldCertain(3) != 80000
        )
            ++bad;
        // the wchResearchCost, row 4 of 10 - the spell research cost ladder
        // by spell level 1-10 - weeks equal the level, the standard
        // investment doubling per level from 2,000 and the certain line from
        // 10,000 (folio 24)
    if (wchResearchWeeks(4) != 5
            || wchResearchGold(4) != 32000
            || wchResearchGoldCertain(4) != 160000
        )
            ++bad;
        // the wchResearchCost, row 5 of 10 - the spell research cost ladder
        // by spell level 1-10 - weeks equal the level, the standard
        // investment doubling per level from 2,000 and the certain line from
        // 10,000 (folio 24)
    if (wchResearchWeeks(5) != 6
            || wchResearchGold(5) != 64000
            || wchResearchGoldCertain(5) != 320000
        )
            ++bad;
        // the wchResearchCost, row 6 of 10 - the spell research cost ladder
        // by spell level 1-10 - weeks equal the level, the standard
        // investment doubling per level from 2,000 and the certain line from
        // 10,000 (folio 24)
    if (wchResearchWeeks(6) != 7
            || wchResearchGold(6) != 128000
            || wchResearchGoldCertain(6) != 640000
        )
            ++bad;
        // the wchResearchCost, row 7 of 10 - the spell research cost ladder
        // by spell level 1-10 - weeks equal the level, the standard
        // investment doubling per level from 2,000 and the certain line from
        // 10,000 (folio 24)
    if (wchResearchWeeks(7) != 8
            || wchResearchGold(7) != 256000
            || wchResearchGoldCertain(7) != 1280000
        )
            ++bad;
        // the wchResearchCost, row 8 of 10 - the spell research cost ladder
        // by spell level 1-10 - weeks equal the level, the standard
        // investment doubling per level from 2,000 and the certain line from
        // 10,000 (folio 24)
    if (wchResearchWeeks(8) != 9
            || wchResearchGold(8) != 512000
            || wchResearchGoldCertain(8) != 2560000
        )
            ++bad;
        // the wchResearchCost, row 9 of 10 - the spell research cost ladder
        // by spell level 1-10 - weeks equal the level, the standard
        // investment doubling per level from 2,000 and the certain line from
        // 10,000 (folio 24)
    if (wchResearchWeeks(9) != 10
            || wchResearchGold(9) != 1024000
            || wchResearchGoldCertain(9) != 5120000
        )
            ++bad;
        printf("R902 Dragon issue-5 audit: bad %d\n", bad);
        if (bad) return 1;
    }
