    // ---- R891 Alchemist class audit ----
    // THE ALCHEMIST, COMPLETE - Round B of issue 2 (folios 28-30, Jon
    // Pickens), the full variant class on the variant layer. THE CLASS FRAME
    // (folio 28): human, neutral, both Wisdom and Intelligence over 12
    // (converted to the 13 floor, noted), best armor class 5, d6 hit dice to
    // level 9 then one point a level, attacks as Clerics with one-handed
    // weapons, saves as Fighters plus 2 vs poison and non-magical
    // paralyzation, psionics as Fighters with Molecular Agitation for Body
    // Weaponry, any potion, the Manual of Golems, the Jug of Plentiful
    // Potions control. THE LADDER (folio 28): twenty stages Student 0 XP
    // through Master Alchemist the 11th at 1,800,000. THE GRIDS (folio 28):
    // the four ability percentages (Detect Poison, Neutralize Poison,
    // Neutralize Paralyzation, Identify Potion) - 20/10/15/5 at Student to
    // the printed 95s and the 100-percent ceiling where the ink's cells go
    // blank, so noted, never silent; the six-level potions grid - none
    // through Cleric, the columns opening 2 from Scribe, 1 from Savant, 1
    // from Philosopher, 1 from Alchemist, 1 from Mstr 2nd, 1 from Mstr 4th,
    // to 10/8/8/6/6/4 at the top. THE LEVEL GATES (folio 28): Read Languages
    // 80 percent and poisons and Delusion at 1st, potions and acids at 3rd,
    // Blade Venom at 5th, Read Magic as Thieves at 7th, potions from samples
    // at 9th. THE POISONS DOCTRINE (folios 28, 30): brew at 50 gold a
    // strength level a day; poison at or above the victim's dice kills in 3
    // rounds on a failed save, at half or more it slows until an hourly
    // constitution check, below that it accumulates; large doses minus 20
    // percent ingestion per dose, Belladonna half strength, the cleric
    // neutralization option; Blade Venom at 200 gold a week a vial, three
    // coats, dead 24 hours after opening. THE LABORATORY (folios 29-30):
    // acids at 100 gold and a d6 a level with the 15-plus-5-a-level
    // neutralization from 3rd; drugs double cost, saves minus 2, 4 hours
    // down; potions at 200 gold a level with samples plus 40 percent and the
    // 250-gold no-MU option; the forty-two-potion list across six levels with
    // the new-potion explanations; the item interactions - the Grimoire (plus
    // a level, 10,000 MU XP, Clerics 7,000 XP and 5-30 lost, others 2-20),
    // the Book of Infinite Spells 5-20, the Philosopher's Stone (2-8 charges,
    // 20 percent research, 10,000 weight transmuted at 50-50 gold-silver,
    // Cure Disease free, disease and heat immunity, disintegration at the
    // last charge). HONEST BOUNDARIES: a variant class, never core 1e canon -
    // the engine's canon classes are untouched; the blank ceiling cells and
    // the option clauses ride noted, never silent. The Remorhaz box flips
    // this round - the issue-2 report's first flip, 1 closed / 3 open.
    {
        using namespace rules;
        int bad = 0;
    if (alcWisIntFloor() != 13
            || alcMaxAc() != 5
            || alcHitDieSides() != 6
            || alcHitDiceTop() != 9
            || alcSaveBonusPoison() != 2
            || alcNeutralizeMult() != 2
            || alcParalyzeMult() != 2
            || alcPctRows() != 20
            || alcPotionRows() != 20
            || alcReadLangPct() != 80
            || alcReadLangLevel() != 1
            || alcPoisonDrugLevel() != 1
            || alcDelusionLevel() != 1
            || alcPotionAcidLevel() != 3
            || alcBladeVenomLevel() != 5
            || alcReadMagicLevel() != 7
            || alcSampleLevel() != 9
            || alcPoisonCostGp() != 50
            || alcPoisonCostDays() != 1
            || alcPoisonDieRounds() != 3
            || alcSlowDivisor() != 2
            || alcDoseIngestPenaltyPct() != 20
            || alcBelladonnaDiv() != 2
            || alcBladeVenomCostGp() != 200
            || alcBladeVenomWeeks() != 1
            || alcBladeVenomDoses() != 3
            || alcBladeVenomHours() != 24
            || alcAcidCostGp() != 100
            || alcAcidDieSides() != 6
            || alcAcidNeutralizeLevel() != 3
            || alcAcidNeutralizeBasePct() != 15
            || alcAcidNeutralizeStepPct() != 5
            || alcDrugCostMult() != 2
            || alcDrugSavePenalty() != 2
            || alcDrugUnconsciousHours() != 4
            || alcPotionCostGp() != 200
            || alcPotionWeeksPerLevel() != 1
            || alcSampleBonusPct() != 40
            || alcPotionOptionCostGp() != 250
            || alcPotionsL1() != 10
            || alcPotionsL2() != 8
            || alcPotionsL3() != 8
            || alcPotionsL4() != 6
            || alcPotionsL5() != 6
            || alcPotionsL6() != 4
            || alcSerumRiskPct() != 1
            || alcLycImmunityMonths() != 1
            || alcSneezeCoughMin() != 2
            || alcSneezeCoughMax() != 8
            || alcFlashBlindPct() != 90
            || alcFlashPellets() != 5
            || alcPurifyServings() != 10
            || alcTangleSideFeet() != 10
            || alcTangleMenTurns() != 3
            || alcTangleHours() != 1
            || alcDustParalyzPackets() != 10
            || alcParalyzHours() != 1
            || alcMindDampWeeks() != 1
            || alcRegenRingDays() != 1
            || alcRegenFreshDays() != 3
            || alcRegenWeeks() != 2
            || alcGrimoireAlcBonus() != 1
            || alcGrimoireMuXp() != 10000
            || alcGrimoireClericXp() != 7000
            || alcGrimoireClericLossMin() != 5
            || alcGrimoireClericLossMax() != 30
            || alcGrimoireOtherLossMin() != 2
            || alcGrimoireOtherLossMax() != 20
            || alcBookInfMin() != 5
            || alcBookInfMax() != 20
            || alcPstoneChargesMin() != 2
            || alcPstoneChargesMax() != 8
            || alcPstoneResearchPct() != 20
            || alcPstoneTransmuteWt() != 10000
            || alcPstoneGoldPct() != 50
            || !alcHumanOnly()
            || !alcNeutralRequired()
            || !alcAttackAsCleric()
            || !alcSavesAsFighter()
            || !alcPsionicSwap()
            || !alcUseAnyPotion()
            || !alcUseManualOfGolems()
            || !alcNoElementalWands()
            || !alcJugControl()
            || !alcDelusionRecheck()
            || !alcPoisonAccumulates()
            || !alcClericNeutralizeOption()
            || !alcPotionOptionNoMu()
            || !alcPstoneCureDisease()
            || !alcPstoneDiseaseImmune()
            || !alcPstoneHeatImmune()
        )
            ++bad;
        // the four ability percentages across the twenty stages - the ink's
        // blank cells past the printed 95s read as the 100-percent ceiling,
        // so noted, never silent (folio 28)
        int CAlcPct[20][4] = {
            {20,10,15,5},
            {25,15,20,10},
            {30,20,25,20},
            {35,25,35,25},
            {45,35,40,35},
            {55,45,45,45},
            {60,50,55,50},
            {65,55,65,60},
            {75,65,75,70},
            {85,75,85,80},
            {95,85,95,85},
            {100,90,100,95},
            {100,95,100,100},
            {100,100,100,100},
            {100,100,100,100},
            {100,100,100,100},
            {100,100,100,100},
            {100,100,100,100},
            {100,100,100,100},
            {100,100,100,100},
            };
        for (int b = 0;
             b < alcPctRows();
             ++b) {
            int vals[4];
            vals[0] = alcDetPct(b);
            vals[1] = alcNeutPoisPct(b);
            vals[2] = alcNeutParaPct(b);
            vals[3] = alcIdenPct(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CAlcPct[b][c])
                    ++bad;
            }
        }
        // the six-level potions grid across the twenty stages - Student and
        // Cleric brew none, the columns open one by one as printed (folio 28)
        int CAlcPot[20][6] = {
            {0,0,0,0,0,0},
            {0,0,0,0,0,0},
            {2,0,0,0,0,0},
            {2,0,0,0,0,0},
            {2,1,0,0,0,0},
            {2,2,0,0,0,0},
            {3,2,1,0,0,0},
            {4,2,2,0,0,0},
            {4,3,2,1,0,0},
            {5,3,3,2,0,0},
            {5,4,3,2,1,0},
            {6,4,4,2,2,0},
            {6,5,4,3,2,1},
            {7,5,5,3,3,1},
            {7,6,5,4,3,2},
            {8,6,6,4,4,2},
            {8,7,6,5,4,3},
            {9,7,7,5,5,3},
            {9,8,7,6,5,4},
            {10,8,8,6,6,4},
            };
        for (int b = 0;
             b < alcPotionRows();
             ++b) {
            int vals[6];
            vals[0] = alcPots1(b);
            vals[1] = alcPots2(b);
            vals[2] = alcPots3(b);
            vals[3] = alcPots4(b);
            vals[4] = alcPots5(b);
            vals[5] = alcPots6(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CAlcPot[b][c])
                    ++bad;
            }
        }
        // the frame - both scores over 12, the best AC 5 (folio 28)
    if (alcWisIntFloor() != 13
            || alcMaxAc() != 5
        )
            ++bad;
        // the d6 hit dice to level 9, one point per level after (folio 28)
    if (alcHitDieSides() != 6
            || alcHitDiceTop() != 9
        )
            ++bad;
        // the +2 saves and the twice-his-level neutralization caps (folio 28)
    if (alcSaveBonusPoison() != 2
            || alcNeutralizeMult() != 2
            || alcParalyzeMult() != 2
        )
            ++bad;
        // the ladder opens - Student at 0, Cleric at 1,500 (folio 28)
    if (alcXpStage(0) != 0
            || alcXpStage(1) != 1500
        )
            ++bad;
        // Master Alchemist the 1st at 300,000 (folio 28)
    if (alcXpStage(9) != 300000
        )
            ++bad;
        // the ladder tops - Master Alchemist the 11th at 1,800,000 (folio 28)
    if (alcXpStage(19) != 1800000
        )
            ++bad;
        // the Master ladder steps 150,000 per stage - Mstr 3rd over Mstr 2nd
    if (alcXpStage(11) - alcXpStage(10) != 150000
        )
            ++bad;
        // the Student row - Detect 20, Identify 5 (folio 28)
    if (alcDetPct(0) != 20
            || alcIdenPct(0) != 5
        )
            ++bad;
        // the Savant row - Detect 45, Paralyzation 40 (folio 28)
    if (alcDetPct(4) != 45
            || alcNeutParaPct(4) != 40
        )
            ++bad;
        // Mstr 2nd - Detect 95, Neutralize 85 (folio 28)
    if (alcDetPct(10) != 95
            || alcNeutPoisPct(10) != 85
        )
            ++bad;
        // Neutralize Poison's printed tail - 90, 95, then the 100 ceiling at
        // Mstr 5th (folio 28)
    if (alcNeutPoisPct(11) != 90
            || alcNeutPoisPct(12) != 95
            || alcNeutPoisPct(13) != 100
        )
            ++bad;
        // past the printed rows the ceiling holds - the ink's blank cells
        // read as 100, so noted (folio 28)
    if (alcDetPct(19) != 100
            || alcIdenPct(19) != 100
        )
            ++bad;
        // first-level potions - 2 from Scribe, 10 at the top stage (folio 28)
    if (alcPots1(2) != 2
            || alcPots1(19) != 10
        )
            ++bad;
        // second-level potions - 1 from Savant, 8 at the top (folio 28)
    if (alcPots2(4) != 1
            || alcPots2(19) != 8
        )
            ++bad;
        // each column opens exactly where printed - Philosopher, Alchemist,
        // Mstr 2nd, Mstr 4th (folio 28)
    if (alcPots3(6) != 1
            || alcPots4(8) != 1
            || alcPots5(10) != 1
            || alcPots6(12) != 1
        )
            ++bad;
        // the Magnus row - 4, 2, 2 and nothing higher (folio 28)
    if (alcPots1(7) != 4
            || alcPots2(7) != 2
            || alcPots3(7) != 2
        )
            ++bad;
        // sixth-level potions open at Mstr 4th, not before (folio 28)
    if (alcPots6(11) != 0
            || alcPots6(12) != 1
        )
            ++bad;
        // the level gates - Read Languages 1st, potions and acids 3rd, Blade
        // Venom 5th, Read Magic 7th, samples 9th (folio 28)
    if (alcReadLangLevel() != 1
            || alcPotionAcidLevel() != 3
            || alcBladeVenomLevel() != 5
            || alcReadMagicLevel() != 7
            || alcSampleLevel() != 9
        )
            ++bad;
        // poison brewing - 50 gold pieces and a day per strength level (folio
        // 28)
    if (alcPoisonCostGp() != 50
            || alcPoisonCostDays() != 1
        )
            ++bad;
        // the poison doctrine - death in 3 rounds at or above the dice count,
        // the slow at half (folio 30)
    if (alcPoisonDieRounds() != 3
            || alcSlowDivisor() != 2
        )
            ++bad;
        // large doses minus 20 percent ingestion per dose, Belladonna at half
        // strength (folio 30)
    if (alcDoseIngestPenaltyPct() != 20
            || alcBelladonnaDiv() != 2
        )
            ++bad;
        // Blade Venom - 200 gold, three coats per vial, dead 24 hours after
        // opening (folio 30)
    if (alcBladeVenomCostGp() != 200
            || alcBladeVenomDoses() != 3
            || alcBladeVenomHours() != 24
        )
            ++bad;
        // acids - 100 gold a gallon-strength, a d6 a level, neutralization 15
        // percent from 3rd rising 5 (folio 29)
    if (alcAcidCostGp() != 100
            || alcAcidDieSides() != 6
            || alcAcidNeutralizeBasePct() != 15
            || alcAcidNeutralizeStepPct() != 5
        )
            ++bad;
        // drugs - double cost, saves at minus 2, 4 hours of unconsciousness
        // (folio 29)
    if (alcDrugCostMult() != 2
            || alcDrugSavePenalty() != 2
            || alcDrugUnconsciousHours() != 4
        )
            ++bad;
        // potion production - 200 gold a level, samples plus 40 percent, the
        // option at 250 (folio 29)
    if (alcPotionCostGp() != 200
            || alcSampleBonusPct() != 40
            || alcPotionOptionCostGp() != 250
        )
            ++bad;
        // the potion lists tile 10 + 8 + 8 + 6 + 6 + 4 - forty-two potions
        // across six levels (folio 29)
    if (alcPotionsL1() + alcPotionsL2() + alcPotionsL3() + alcPotionsL4() +
        alcPotionsL5() + alcPotionsL6() != 42
        )
            ++bad;
        // the lycanthropy serum - one month of immunity at a 1 percent risk
        // (folio 29)
    if (alcSerumRiskPct() != 1
            || alcLycImmunityMonths() != 1
        )
            ++bad;
        // the new-potion flavor - the sneezing cough 2-8 rounds, the flash 90
        // percent blind (folio 29)
    if (alcSneezeCoughMin() != 2
            || alcSneezeCoughMax() != 8
            || alcFlashBlindPct() != 90
        )
            ++bad;
        // Tanglefoot - the 10 x 10 area, 3 turns to force, gone in an hour
        // (folio 29)
    if (alcTangleSideFeet() != 10
            || alcTangleMenTurns() != 3
            || alcTangleHours() != 1
        )
            ++bad;
        // the Grimoire - plus a level for Alchemists, 10,000 XP for MUs,
        // 7,000 for Clerics (folio 30)
    if (alcGrimoireAlcBonus() != 1
            || alcGrimoireMuXp() != 10000
            || alcGrimoireClericXp() != 7000
        )
            ++bad;
        // the Grimoire's price - Clerics lose 5-30, others 2-20 (folio 30)
    if (alcGrimoireClericLossMin() != 5
            || alcGrimoireClericLossMax() != 30
            || alcGrimoireOtherLossMin() != 2
            || alcGrimoireOtherLossMax() != 20
        )
            ++bad;
        // the Philosopher's Stone - 2-8 charges, plus 20 percent research,
        // 10,000 weight transmuted (folio 30)
    if (alcPstoneChargesMin() != 2
            || alcPstoneChargesMax() != 8
            || alcPstoneResearchPct() != 20
            || alcPstoneTransmuteWt() != 10000
        )
            ++bad;
        // the class frame - human, neutral, attacks as Cleric, saves as
        // Fighter (folio 28)
    if (alcHumanOnly() != 1
            || alcNeutralRequired() != 1
            || alcAttackAsCleric() != 1
            || alcSavesAsFighter() != 1
        )
            ++bad;
        // the psionic swap, any potion, the Manual of Golems, the Jug control
        // (folios 28, 30)
    if (alcPsionicSwap() != 1
            || alcUseAnyPotion() != 1
            || alcUseManualOfGolems() != 1
            || alcJugControl() != 1
        )
            ++bad;
        // the Delusion recheck, the accumulation doctrine, the cleric option
        // (folios 28, 30)
    if (alcDelusionRecheck() != 1
            || alcPoisonAccumulates() != 1
            || alcClericNeutralizeOption() != 1
        )
            ++bad;
        // the stone's three graces - Cure Disease free, disease immunity,
        // heat immunity (folio 30)
    if (alcPstoneCureDisease() != 1
            || alcPstoneDiseaseImmune() != 1
            || alcPstoneHeatImmune() != 1
        )
            ++bad;
        printf("R891 Alchemist class audit: bad %d\n", bad);
        if (bad) return 1;
    }
