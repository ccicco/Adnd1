    // ---- R605 DMO item-creation audit ----
    // CHAPTER 4 of the DMO (printed pp. 86-95), the item-creation economy
    // closing in one round: the holy water ceremony (the five-spell chain,
    // the eight-hour meditations and rest, the -4 combat window, the
    // one-font-one-week rule with the cost ladder and the Delsenora recycle
    // read), the requirements doctrine (the class level thresholds, the
    // common-rare-exotic materials and processes, the laboratory and altar
    // economics), the Table 23 creation grid (28 rows of material, process,
    // footnote, cost and time codes), the per-type details (the 70/80/60
    // bases, the potion and ring research windows, the ink ladder, the
    // drained-item death rule), the recharge window with its -1 save-or-dust
    // risk, the 96-00 automatic failure with the cursed-item twists, the
    // Table 24 XP grid, and the Rozmare worked examples at 94 and 65 percent.
    {
        using namespace rules;
        int bad = 0;
    if (derHolySpellCount() != 5
            || derHolyUnholySpellCount() != 2
            || derHolyMeditateHours() != 8
            || derHolyChantTurns() != 1
            || derHolyRestHours() != 8
            || derHolyCombatPenalty() != -4
            || derFontUsePerWeek() != 1
            || derFontsPerBuilding() != 1
            || derFontRowCount() != 9
            || derFontBuildWeeksDieCount() != 2
            || derFontBuildWeeksDieSize() != 4
            || derFontBuildWeeksBonus() != 2
            || derVialCostGp() != 5
            || derVialPotencyTurns() != 1
            || derEmptyVialSellDieCount() != 1
            || derEmptyVialSellDieSize() != 4
            || derEmptyVialSellBonus() != 1
            || derRecyclePctDieCount() != 1
            || derRecyclePctDieSize() != 4
            || derRecyclePctBonus() != 1
            || derRecyclePctMult() != 10
            || derDelsenoraFontVials() != 32
            || derDelsenoraBasinCost() != 21000
            || derDelsenoraPedestalCost() != 1500
            || derDelsenoraRecycleRoll() != 2
            || derDelsenoraRecyclePct() != 30
            || derDelsenoraRecycleCost() != 6300
            || derWizPotionScrollLevel() != 9
            || derWizOtherItemLevel() != 11
            || derPriestScrollLevel() != 7
            || derPriestPotionLevel() != 9
            || derPriestOtherLevel() != 11
            || derSpecialistSchoolBonusPct() != 5
            || derLabMinSqFt() != 500
            || derLabSetupCostGp() != 5000
            || derLabMonthlyGp() != 500
            || derAltarMinCostGp() != 2000
            || derAltarVigilWeeks() != 1
            || derMatCommon() != 1
            || derMatRare() != 2
            || derMatExotic() != 3
            || derMatRareAndCommon() != 4
            || derMatExoticPerFunction() != 5
            || derMatExoticPerUse() != 6
            || derProcCommon() != 1
            || derProcRare() != 2
            || derProcExotic() != 3
            || derProcRareAndCommon() != 4
            || derProcExoticPerFunction() != 5
            || derProcExoticPerUse() != 6
            || derProcRarePerFunction() != 7
            || derProcVariable() != 0
            || derExtraNone() != 0
            || derExtraCommon() != 1
            || derExtraExotic() != 3
            || derExtraRareCommon() != 4
            || derCostHalfXp() != 1
            || derCostXp() != 2
            || derCostDoubleXp() != 4
            || derCostTripleXp() != 6
            || derCostQuadXp() != 8
            || derTimeDayPerHundredGp() != 1
            || derTimeDayPerSpellLevel() != 2
            || derTimeFixedDays() != 3
            || derTimeWeekPerHundredGp() != 4
            || derTimeWeekPerThousandGp() != 5
            || derPermanencyConLoss() != 1
            || derPotionBasePct() != 70
            || derPotionLevelPctStep() != 1
            || derPotionCostStepGp() != 100
            || derPotionResearchDieCount() != 1
            || derPotionResearchDieSize() != 3
            || derPotionResearchBonus() != 1
            || derPotionResearchWeeklyGp() != 100
            || derPotionAnalyzeWeeks() != 1
            || derScrollBasePct() != 80
            || derScrollLevelPctPerLevel() != 1
            || derScrollSpellPctPerSpellLevel() != 1
            || derScrollInkBlendDays() != 1
            || derScrollInkUseWeeks() != 2
            || derScrollLowInkLevelMax() != 3
            || derScrollHighInkLevelMin() != 4
            || derScrollTopInkLevelMin() != 7
            || derScrollSpellsDieSize() != 6
            || derRingBasePct() != 60
            || derRingLevelPctPerLevel() != 1
            || derRingSpellPctPerSpell() != 1
            || derRingResearchDieCount() != 1
            || derRingResearchDieSize() != 6
            || derRingResearchBonus() != 1
            || derRingResearchWeeklyGp() != 200
            || derRingResearchAidedWeeks() != 2
            || derRodStaffWandBasePct() != 60
            || derInitialCharges() != 1
            || derRechargeWindowHours() != 24
            || derRechargeSavePenalty() != -1
            || derAutoFailRollMin() != 96
            || derAutoFailRollMax() != 100
            || derXpFlat() != 0
            || derXpPerPlus() != 1
            || derXpSumOfValues() != 2
            || derXpLowerPlusShare() != 3
            || derXpPerSpellLevel() != 4
            || derRozmareLevel() != 13
            || derPotionSpeedXpValue() != 200
            || derPotionSpeedBrewWeeks() != 2
            || derPotionSpeedSuccessPct() != 94
            || derRozmareSwordXpValue() != 800
            || derRozmareSwordMaterialGp() != 1600
            || derSwordResearchWeeks() != 3
            || derSwordResearchGp() != 600
            || derPrepWeeksPerThousandGp() != 4
            || derRozmareSwordPrepWeeks() != 8
            || derRozmareSwordSuccessPct() != 65
            || derRozmareSwordExoticMaterials() != 2
            || derT23RowCount() != 28
            || derT24RowCount() != 27
            || !derUnholyReversedSpells()
            || !derCeremonyRuinOnDelay()
            || !derCreateWaterOverflowDissipated()
            || !derFontDefileByCurse()
            || !derFontDefileNonmagical()
            || !derDefiledFontRemade()
            || !derWarriorsRoguesCannot()
            || !derNoMagicalBooks()
            || !derNoAbilityWritings()
            || !derRacialItemsRacePriestOnly()
            || !derPriestsCastStoredSpellsOk()
            || !derOnlyUsableItems()
            || !derVigilRestartOnInterrupt()
            || !derOnlyConsecratorUsesAltar()
            || !derDefiledAltarReconsecrated()
            || !derDmApprovalRequired()
            || !derItemFinestQuality()
            || !derRequirementsNotAutoKnown()
            || !derEnchantAndPermanencyRequired()
            || !derPriestsPetitionDeities()
            || !derPriestNoConLossDefault()
            || !derPotionDoseNotConsumed()
            || !derPotionFormulaReusable()
            || !derScrollNoSpellsCast()
            || !derScrollComponentsConsumed()
            || !derScrollPenaltyCarried()
            || !derScrollFailurePreservesSpells()
            || !derScrollNewQuillPerSpell()
            || !derRingCommonProcessExtra()
            || !derRingPriestsSufferPenalty()
            || !derRodStaffWandPermanency()
            || !derDrainedItemDeadForever()
            || !derEachPlusSeparateSpell()
            || !derSingleUseNoPermanency()
            || !derMiscSameAsRing()
            || !derTimeNotReducible()
            || !derMagesRechargeNoncasterItems()
            || !derRechargeSpellDuplicatesPower()
            || !derRechargeNormalCastingTime()
            || !derDmRollsSecretly()
            || !derSuccessNeverImproves()
            || !derFailureUsuallyRuins()
            || !derAutoFailMakesCurse()
            || !derCursedCompareToSimilar()
            || !derCursedFailureDestroys()
            || !derCreatorCursedOnAutoFail()
            || !derNonstandardCompareToSimilar()
        )
            ++bad;
        // the derT23Grid grid
        int CT34[28][6] = {
            {2,1,0,2,1,1},
            {3,2,0,2,1,1},
            {4,0,0,1,2,1},
            {3,2,0,1,3,6},
            {3,1,0,2,4,1},
            {5,5,1,4,4,1},
            {3,3,1,4,4,1},
            {3,2,0,1,5,1},
            {3,2,0,1,4,1},
            {5,5,1,1,4,2},
            {3,6,0,1,4,4},
            {2,2,0,1,4,1},
            {5,5,1,1,4,2},
            {3,6,0,1,4,4},
            {2,2,0,1,4,1},
            {5,5,1,1,4,2},
            {3,6,0,1,4,4},
            {3,3,0,4,4,1},
            {3,3,0,6,4,1},
            {5,7,3,8,4,1},
            {6,6,3,4,4,3},
            {3,4,0,4,5,3},
            {5,5,4,4,5,4},
            {6,6,4,4,5,2},
            {2,1,0,2,4,1},
            {3,4,0,4,5,3},
            {5,5,4,4,5,4},
            {6,6,4,4,5,2},
            };
        for (int b = 0;
             b < derT23RowCount();
             ++b) {
            int vals[6];
            vals[0] = derT23MatCode(b);
            vals[1] = derT23ProcCode(b);
            vals[2] = derT23ProcExtraCode(b);
            vals[3] = derT23CostHalfXp(b);
            vals[4] = derT23TimeKind(b);
            vals[5] = derT23TimeRate(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CT34[b][c])
                    ++bad;
            }
        }
        // the derT24Grid grid
        int CT35[28][3] = {
            {200,1000,0},
            {250,1000,0},
            {100,0,4},
            {1000,2500,0},
            {1000,4000,0},
            {3000,5000,0},
            {1000,5000,0},
            {4000,10000,0},
            {5000,10000,0},
            {6000,10000,0},
            {4000,10000,0},
            {5000,8000,0},
            {7000,15000,0},
            {2500,5000,0},
            {2000,4000,0},
            {4000,7000,0},
            {4000,6000,0},
            {200,2000,0},
            {2000,10000,0},
            {2500,10000,0},
            {500,2500,0},
            {250,800,1},
            {0,0,2},
            {3000,5000,0},
            {20,50,1},
            {400,600,1},
            {0,0,3},
            {1000,5000,0},
            };
        for (int b = 0;
             b < derT24RowCount();
             ++b) {
            int vals[3];
            vals[0] = derT24XpMin(b);
            vals[1] = derT24XpMax(b);
            vals[2] = derT24PerPlus(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT35[b][c])
                    ++bad;
            }
        }
        // the derFontGrid grid
        int CT36[9][6] = {
            {6,1,6,10,120,200},
            {8,1,6,50,1000,350},
            {10,1,6,100,1800,500},
            {14,1,4,500,5200,750},
            {18,1,4,1000,8000,1000},
            {24,1,4,1000,15000,1250},
            {32,1,4,1000,18000,1500},
            {40,1,6,10000,50000,1750},
            {50,1,10,10000,100000,2000},
            };
        for (int b = 0;
             b < derFontRowCount();
             ++b) {
            int vals[6];
            vals[0] = derFontCapVials(b);
            vals[1] = derFontBasinDieCount(b);
            vals[2] = derFontBasinDieSize(b);
            vals[3] = derFontBasinDieMult(b);
            vals[4] = derFontBasinBonusGp(b);
            vals[5] = derFontPedestalGp(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CT36[b][c])
                    ++bad;
            }
        }
        // the derHolySpellCount pin
    if (derHolySpellCount() != 5
        )
            ++bad;
        // the derHolyUnholySpellCount pin
    if (derHolyUnholySpellCount() != 2
        )
            ++bad;
        // the derHolyMeditateHours pin
    if (derHolyMeditateHours() != 8
        )
            ++bad;
        // the derHolyChantTurns pin
    if (derHolyChantTurns() != 1
        )
            ++bad;
        // the derHolyRestHours pin
    if (derHolyRestHours() != 8
        )
            ++bad;
        // the derHolyCombatPenalty pin
    if (derHolyCombatPenalty() != -4
        )
            ++bad;
        // the derFontUsePerWeek pin
    if (derFontUsePerWeek() != 1
        )
            ++bad;
        // the derFontsPerBuilding pin
    if (derFontsPerBuilding() != 1
        )
            ++bad;
        // the derFontRowCount pin
    if (derFontRowCount() != 9
        )
            ++bad;
        // the derFontBuildWeeksDieCount pin
    if (derFontBuildWeeksDieCount() != 2
        )
            ++bad;
        // the derFontBuildWeeksDieSize pin
    if (derFontBuildWeeksDieSize() != 4
        )
            ++bad;
        // the derFontBuildWeeksBonus pin
    if (derFontBuildWeeksBonus() != 2
        )
            ++bad;
        // the derVialCostGp pin
    if (derVialCostGp() != 5
        )
            ++bad;
        // the derVialPotencyTurns pin
    if (derVialPotencyTurns() != 1
        )
            ++bad;
        // the derEmptyVialSellDieCount pin
    if (derEmptyVialSellDieCount() != 1
        )
            ++bad;
        // the derEmptyVialSellDieSize pin
    if (derEmptyVialSellDieSize() != 4
        )
            ++bad;
        // the derEmptyVialSellBonus pin
    if (derEmptyVialSellBonus() != 1
        )
            ++bad;
        // the derRecyclePctDieCount pin
    if (derRecyclePctDieCount() != 1
        )
            ++bad;
        // the derRecyclePctDieSize pin
    if (derRecyclePctDieSize() != 4
        )
            ++bad;
        // the derRecyclePctBonus pin
    if (derRecyclePctBonus() != 1
        )
            ++bad;
        // the derRecyclePctMult pin
    if (derRecyclePctMult() != 10
        )
            ++bad;
        // the derDelsenoraFontVials pin
    if (derDelsenoraFontVials() != 32
        )
            ++bad;
        // the derDelsenoraBasinCost pin
    if (derDelsenoraBasinCost() != 21000
        )
            ++bad;
        // the derDelsenoraPedestalCost pin
    if (derDelsenoraPedestalCost() != 1500
        )
            ++bad;
        // the derDelsenoraRecycleRoll pin
    if (derDelsenoraRecycleRoll() != 2
        )
            ++bad;
        // the derDelsenoraRecyclePct pin
    if (derDelsenoraRecyclePct() != 30
        )
            ++bad;
        // the derDelsenoraRecycleCost pin
    if (derDelsenoraRecycleCost() != 6300
        )
            ++bad;
        // the derWizPotionScrollLevel pin
    if (derWizPotionScrollLevel() != 9
        )
            ++bad;
        // the derWizOtherItemLevel pin
    if (derWizOtherItemLevel() != 11
        )
            ++bad;
        // the derPriestScrollLevel pin
    if (derPriestScrollLevel() != 7
        )
            ++bad;
        // the derPriestPotionLevel pin
    if (derPriestPotionLevel() != 9
        )
            ++bad;
        // the derPriestOtherLevel pin
    if (derPriestOtherLevel() != 11
        )
            ++bad;
        // the derSpecialistSchoolBonusPct pin
    if (derSpecialistSchoolBonusPct() != 5
        )
            ++bad;
        // the derLabMinSqFt pin
    if (derLabMinSqFt() != 500
        )
            ++bad;
        // the derLabSetupCostGp pin
    if (derLabSetupCostGp() != 5000
        )
            ++bad;
        // the derLabMonthlyGp pin
    if (derLabMonthlyGp() != 500
        )
            ++bad;
        // the derAltarMinCostGp pin
    if (derAltarMinCostGp() != 2000
        )
            ++bad;
        // the derAltarVigilWeeks pin
    if (derAltarVigilWeeks() != 1
        )
            ++bad;
        // the derMatCommon pin
    if (derMatCommon() != 1
        )
            ++bad;
        // the derMatRare pin
    if (derMatRare() != 2
        )
            ++bad;
        // the derMatExotic pin
    if (derMatExotic() != 3
        )
            ++bad;
        // the derMatRareAndCommon pin
    if (derMatRareAndCommon() != 4
        )
            ++bad;
        // the derMatExoticPerFunction pin
    if (derMatExoticPerFunction() != 5
        )
            ++bad;
        // the derMatExoticPerUse pin
    if (derMatExoticPerUse() != 6
        )
            ++bad;
        // the derProcCommon pin
    if (derProcCommon() != 1
        )
            ++bad;
        // the derProcRare pin
    if (derProcRare() != 2
        )
            ++bad;
        // the derProcExotic pin
    if (derProcExotic() != 3
        )
            ++bad;
        // the derProcRareAndCommon pin
    if (derProcRareAndCommon() != 4
        )
            ++bad;
        // the derProcExoticPerFunction pin
    if (derProcExoticPerFunction() != 5
        )
            ++bad;
        // the derProcExoticPerUse pin
    if (derProcExoticPerUse() != 6
        )
            ++bad;
        // the derProcRarePerFunction pin
    if (derProcRarePerFunction() != 7
        )
            ++bad;
        // the derProcVariable pin
    if (derProcVariable() != 0
        )
            ++bad;
        // the derExtraNone pin
    if (derExtraNone() != 0
        )
            ++bad;
        // the derExtraCommon pin
    if (derExtraCommon() != 1
        )
            ++bad;
        // the derExtraExotic pin
    if (derExtraExotic() != 3
        )
            ++bad;
        // the derExtraRareCommon pin
    if (derExtraRareCommon() != 4
        )
            ++bad;
        // the derCostHalfXp pin
    if (derCostHalfXp() != 1
        )
            ++bad;
        // the derCostXp pin
    if (derCostXp() != 2
        )
            ++bad;
        // the derCostDoubleXp pin
    if (derCostDoubleXp() != 4
        )
            ++bad;
        // the derCostTripleXp pin
    if (derCostTripleXp() != 6
        )
            ++bad;
        // the derCostQuadXp pin
    if (derCostQuadXp() != 8
        )
            ++bad;
        // the derTimeDayPerHundredGp pin
    if (derTimeDayPerHundredGp() != 1
        )
            ++bad;
        // the derTimeDayPerSpellLevel pin
    if (derTimeDayPerSpellLevel() != 2
        )
            ++bad;
        // the derTimeFixedDays pin
    if (derTimeFixedDays() != 3
        )
            ++bad;
        // the derTimeWeekPerHundredGp pin
    if (derTimeWeekPerHundredGp() != 4
        )
            ++bad;
        // the derTimeWeekPerThousandGp pin
    if (derTimeWeekPerThousandGp() != 5
        )
            ++bad;
        // the derPermanencyConLoss pin
    if (derPermanencyConLoss() != 1
        )
            ++bad;
        // the derPotionBasePct pin
    if (derPotionBasePct() != 70
        )
            ++bad;
        // the derPotionLevelPctStep pin
    if (derPotionLevelPctStep() != 1
        )
            ++bad;
        // the derPotionCostStepGp pin
    if (derPotionCostStepGp() != 100
        )
            ++bad;
        // the derPotionResearchDieCount pin
    if (derPotionResearchDieCount() != 1
        )
            ++bad;
        // the derPotionResearchDieSize pin
    if (derPotionResearchDieSize() != 3
        )
            ++bad;
        // the derPotionResearchBonus pin
    if (derPotionResearchBonus() != 1
        )
            ++bad;
        // the derPotionResearchWeeklyGp pin
    if (derPotionResearchWeeklyGp() != 100
        )
            ++bad;
        // the derPotionAnalyzeWeeks pin
    if (derPotionAnalyzeWeeks() != 1
        )
            ++bad;
        // the derScrollBasePct pin
    if (derScrollBasePct() != 80
        )
            ++bad;
        // the derScrollLevelPctPerLevel pin
    if (derScrollLevelPctPerLevel() != 1
        )
            ++bad;
        // the derScrollSpellPctPerSpellLevel pin
    if (derScrollSpellPctPerSpellLevel() != 1
        )
            ++bad;
        // the derScrollInkBlendDays pin
    if (derScrollInkBlendDays() != 1
        )
            ++bad;
        // the derScrollInkUseWeeks pin
    if (derScrollInkUseWeeks() != 2
        )
            ++bad;
        // the derScrollLowInkLevelMax pin
    if (derScrollLowInkLevelMax() != 3
        )
            ++bad;
        // the derScrollHighInkLevelMin pin
    if (derScrollHighInkLevelMin() != 4
        )
            ++bad;
        // the derScrollTopInkLevelMin pin
    if (derScrollTopInkLevelMin() != 7
        )
            ++bad;
        // the derScrollSpellsDieSize pin
    if (derScrollSpellsDieSize() != 6
        )
            ++bad;
        // the derRingBasePct pin
    if (derRingBasePct() != 60
        )
            ++bad;
        // the derRingLevelPctPerLevel pin
    if (derRingLevelPctPerLevel() != 1
        )
            ++bad;
        // the derRingSpellPctPerSpell pin
    if (derRingSpellPctPerSpell() != 1
        )
            ++bad;
        // the derRingResearchDieCount pin
    if (derRingResearchDieCount() != 1
        )
            ++bad;
        // the derRingResearchDieSize pin
    if (derRingResearchDieSize() != 6
        )
            ++bad;
        // the derRingResearchBonus pin
    if (derRingResearchBonus() != 1
        )
            ++bad;
        // the derRingResearchWeeklyGp pin
    if (derRingResearchWeeklyGp() != 200
        )
            ++bad;
        // the derRingResearchAidedWeeks pin
    if (derRingResearchAidedWeeks() != 2
        )
            ++bad;
        // the derRodStaffWandBasePct pin
    if (derRodStaffWandBasePct() != 60
        )
            ++bad;
        // the derInitialCharges pin
    if (derInitialCharges() != 1
        )
            ++bad;
        // the derRechargeWindowHours pin
    if (derRechargeWindowHours() != 24
        )
            ++bad;
        // the derRechargeSavePenalty pin
    if (derRechargeSavePenalty() != -1
        )
            ++bad;
        // the derAutoFailRollMin pin
    if (derAutoFailRollMin() != 96
        )
            ++bad;
        // the derAutoFailRollMax pin
    if (derAutoFailRollMax() != 100
        )
            ++bad;
        // the derXpFlat pin
    if (derXpFlat() != 0
        )
            ++bad;
        // the derXpPerPlus pin
    if (derXpPerPlus() != 1
        )
            ++bad;
        // the derXpSumOfValues pin
    if (derXpSumOfValues() != 2
        )
            ++bad;
        // the derXpLowerPlusShare pin
    if (derXpLowerPlusShare() != 3
        )
            ++bad;
        // the derXpPerSpellLevel pin
    if (derXpPerSpellLevel() != 4
        )
            ++bad;
        // the derRozmareLevel pin
    if (derRozmareLevel() != 13
        )
            ++bad;
        // the derPotionSpeedXpValue pin
    if (derPotionSpeedXpValue() != 200
        )
            ++bad;
        // the derPotionSpeedBrewWeeks pin
    if (derPotionSpeedBrewWeeks() != 2
        )
            ++bad;
        // the derPotionSpeedSuccessPct pin
    if (derPotionSpeedSuccessPct() != 94
        )
            ++bad;
        // the derRozmareSwordXpValue pin
    if (derRozmareSwordXpValue() != 800
        )
            ++bad;
        // the derRozmareSwordMaterialGp pin
    if (derRozmareSwordMaterialGp() != 1600
        )
            ++bad;
        // the derSwordResearchWeeks pin
    if (derSwordResearchWeeks() != 3
        )
            ++bad;
        // the derSwordResearchGp pin
    if (derSwordResearchGp() != 600
        )
            ++bad;
        // the derPrepWeeksPerThousandGp pin
    if (derPrepWeeksPerThousandGp() != 4
        )
            ++bad;
        // the derRozmareSwordPrepWeeks pin
    if (derRozmareSwordPrepWeeks() != 8
        )
            ++bad;
        // the derRozmareSwordSuccessPct pin
    if (derRozmareSwordSuccessPct() != 65
        )
            ++bad;
        // the derRozmareSwordExoticMaterials pin
    if (derRozmareSwordExoticMaterials() != 2
        )
            ++bad;
        // the derT23RowCount pin
    if (derT23RowCount() != 28
        )
            ++bad;
        // the derT24RowCount pin
    if (derT24RowCount() != 27
        )
            ++bad;
        // the derUnholyReversedSpells pin
    if (derUnholyReversedSpells() != 1
        )
            ++bad;
        // the derCeremonyRuinOnDelay pin
    if (derCeremonyRuinOnDelay() != 1
        )
            ++bad;
        // the derCreateWaterOverflowDissipated pin
    if (derCreateWaterOverflowDissipated() != 1
        )
            ++bad;
        // the derFontDefileByCurse pin
    if (derFontDefileByCurse() != 1
        )
            ++bad;
        // the derFontDefileNonmagical pin
    if (derFontDefileNonmagical() != 1
        )
            ++bad;
        // the derDefiledFontRemade pin
    if (derDefiledFontRemade() != 1
        )
            ++bad;
        // the derWarriorsRoguesCannot pin
    if (derWarriorsRoguesCannot() != 1
        )
            ++bad;
        // the derNoMagicalBooks pin
    if (derNoMagicalBooks() != 1
        )
            ++bad;
        // the derNoAbilityWritings pin
    if (derNoAbilityWritings() != 1
        )
            ++bad;
        // the derRacialItemsRacePriestOnly pin
    if (derRacialItemsRacePriestOnly() != 1
        )
            ++bad;
        // the derPriestsCastStoredSpellsOk pin
    if (derPriestsCastStoredSpellsOk() != 1
        )
            ++bad;
        // the derOnlyUsableItems pin
    if (derOnlyUsableItems() != 1
        )
            ++bad;
        // the derVigilRestartOnInterrupt pin
    if (derVigilRestartOnInterrupt() != 1
        )
            ++bad;
        // the derOnlyConsecratorUsesAltar pin
    if (derOnlyConsecratorUsesAltar() != 1
        )
            ++bad;
        // the derDefiledAltarReconsecrated pin
    if (derDefiledAltarReconsecrated() != 1
        )
            ++bad;
        // the derDmApprovalRequired pin
    if (derDmApprovalRequired() != 1
        )
            ++bad;
        // the derItemFinestQuality pin
    if (derItemFinestQuality() != 1
        )
            ++bad;
        // the derRequirementsNotAutoKnown pin
    if (derRequirementsNotAutoKnown() != 1
        )
            ++bad;
        // the derEnchantAndPermanencyRequired pin
    if (derEnchantAndPermanencyRequired() != 1
        )
            ++bad;
        // the derPriestsPetitionDeities pin
    if (derPriestsPetitionDeities() != 1
        )
            ++bad;
        // the derPriestNoConLossDefault pin
    if (derPriestNoConLossDefault() != 1
        )
            ++bad;
        // the derPotionDoseNotConsumed pin
    if (derPotionDoseNotConsumed() != 1
        )
            ++bad;
        // the derPotionFormulaReusable pin
    if (derPotionFormulaReusable() != 1
        )
            ++bad;
        // the derScrollNoSpellsCast pin
    if (derScrollNoSpellsCast() != 1
        )
            ++bad;
        // the derScrollComponentsConsumed pin
    if (derScrollComponentsConsumed() != 1
        )
            ++bad;
        // the derScrollPenaltyCarried pin
    if (derScrollPenaltyCarried() != 1
        )
            ++bad;
        // the derScrollFailurePreservesSpells pin
    if (derScrollFailurePreservesSpells() != 1
        )
            ++bad;
        // the derScrollNewQuillPerSpell pin
    if (derScrollNewQuillPerSpell() != 1
        )
            ++bad;
        // the derRingCommonProcessExtra pin
    if (derRingCommonProcessExtra() != 1
        )
            ++bad;
        // the derRingPriestsSufferPenalty pin
    if (derRingPriestsSufferPenalty() != 1
        )
            ++bad;
        // the derRodStaffWandPermanency pin
    if (derRodStaffWandPermanency() != 1
        )
            ++bad;
        // the derDrainedItemDeadForever pin
    if (derDrainedItemDeadForever() != 1
        )
            ++bad;
        // the derEachPlusSeparateSpell pin
    if (derEachPlusSeparateSpell() != 1
        )
            ++bad;
        // the derSingleUseNoPermanency pin
    if (derSingleUseNoPermanency() != 1
        )
            ++bad;
        // the derMiscSameAsRing pin
    if (derMiscSameAsRing() != 1
        )
            ++bad;
        // the derTimeNotReducible pin
    if (derTimeNotReducible() != 1
        )
            ++bad;
        // the derMagesRechargeNoncasterItems pin
    if (derMagesRechargeNoncasterItems() != 1
        )
            ++bad;
        // the derRechargeSpellDuplicatesPower pin
    if (derRechargeSpellDuplicatesPower() != 1
        )
            ++bad;
        // the derRechargeNormalCastingTime pin
    if (derRechargeNormalCastingTime() != 1
        )
            ++bad;
        // the derDmRollsSecretly pin
    if (derDmRollsSecretly() != 1
        )
            ++bad;
        // the derSuccessNeverImproves pin
    if (derSuccessNeverImproves() != 1
        )
            ++bad;
        // the derFailureUsuallyRuins pin
    if (derFailureUsuallyRuins() != 1
        )
            ++bad;
        // the derAutoFailMakesCurse pin
    if (derAutoFailMakesCurse() != 1
        )
            ++bad;
        // the derCursedCompareToSimilar pin
    if (derCursedCompareToSimilar() != 1
        )
            ++bad;
        // the derCursedFailureDestroys pin
    if (derCursedFailureDestroys() != 1
        )
            ++bad;
        // the derCreatorCursedOnAutoFail pin
    if (derCreatorCursedOnAutoFail() != 1
        )
            ++bad;
        // the derNonstandardCompareToSimilar pin
    if (derNonstandardCompareToSimilar() != 1
        )
            ++bad;
        // the Rozmare potion read: 70 + 26 - 2 is 94 percent (printed p. 95)
    if (derPotionBasePct() + 26 - 2 != 94
        )
            ++bad;
        // the Rozmare sword read: 60 + 13 - 8 is 65 percent (printed p. 95)
    if (derRingBasePct() + 13 - 8 != 65
        )
            ++bad;
        // the potion single-use row: rare material, common process, XP cost,
        // a day per 100 gp (printed p. 89)
    if (derT23MatCode(0) != 2
            || derT23ProcCode(0) != 1
            || derT23CostHalfXp(0) != 2
            || derT23TimeKind(0) != 1
            || derT23TimeRate(0) != 1
        )
            ++bad;
        // the scroll-spell row: rare-and-common material, half-XP cost, a day
        // per spell level (printed p. 89)
    if (derT23MatCode(2) != 4
            || derT23CostHalfXp(2) != 1
            || derT23TimeKind(2) != 2
        )
            ++bad;
        // the scroll-protection row: exotic material, six fixed days (printed
        // p. 89)
    if (derT23TimeKind(3) != 3
            || derT23TimeRate(3) != 6
        )
            ++bad;
        // the staff-multiple row: exotic per function with the common
        // footnote, two weeks per 100 gp (printed p. 89)
    if (derT23MatCode(12) != 5
            || derT23ProcCode(12) != 5
            || derT23ProcExtraCode(12) != 1
            || derT23TimeKind(12) != 4
            || derT23TimeRate(12) != 2
        )
            ++bad;
        // the armor single-function row: rare-and-common process, double
        // cost, three weeks per 1,000 gp (printed p. 89)
    if (derT23ProcCode(21) != 4
            || derT23CostHalfXp(21) != 4
            || derT23TimeKind(21) != 5
            || derT23TimeRate(21) != 3
        )
            ++bad;
        // the weapon-limited row: exotic per use with the rare-and-common
        // footnote, two weeks per 1,000 gp (printed p. 89)
    if (derT23ProcExtraCode(27) != 4
            || derT23TimeKind(27) != 5
            || derT23TimeRate(27) != 2
        )
            ++bad;
        // the rod-multiple row: two weeks per 100 gp, the footnote-one common
        // process (printed p. 89)
    if (derT23TimeRate(9) != 2
            || derT23ProcExtraCode(9) != 1
        )
            ++bad;
        // the misc-limited row: three weeks per 100 gp, the footnote-two
        // exotic process (printed p. 89)
    if (derT23TimeRate(20) != 3
            || derT23ProcExtraCode(20) != 3
        )
            ++bad;
        // the wand single-function XP band: 2,000 through 4,000 (printed p.
        // 93)
    if (derT24XpMin(14) != 2000
            || derT24XpMax(14) != 4000
        )
            ++bad;
        // the armor single-function XP: 250-800 per plus (printed p. 93)
    if (derT24XpMin(21) != 250
            || derT24XpMax(21) != 800
            || derT24PerPlus(21) != 1
        )
            ++bad;
        // the weapon-multiple XP: the lower value plus 20-40 percent of the
        // higher (printed p. 93)
    if (derT24PerPlus(26) != 3
        )
            ++bad;
        // the scroll-spell XP: 100 per spell level (printed p. 93)
    if (derT24PerPlus(2) != 4
            || derT24XpMin(2) != 100
        )
            ++bad;
        // the Delsenora font row: 32 vials, the 18,000 gp basin bonus, the
        // 1,500 gp pedestal (printed p. 87)
    if (derFontCapVials(6) != 32
            || derFontBasinBonusGp(6) != 18000
            || derFontPedestalGp(6) != 1500
        )
            ++bad;
        // the Delsenora recycle read: 30 percent of 21,000 gp is 6,300
        // (printed p. 87)
    if (derDelsenoraRecyclePct() * derDelsenoraBasinCost() / 100 != 6300
        )
            ++bad;
        // the ceremony window: eight hours meditating plus eight hours rest
        // (printed p. 86)
    if (derHolyMeditateHours() + derHolyRestHours() != 16
        )
            ++bad;
        // the Rozmare sword materials: double the 800 XP value is 1,600 gp
        // (printed p. 95)
    if (derRozmareSwordMaterialGp() / derRozmareSwordXpValue() != 2
        )
            ++bad;
        // the Rozmare sword preparation: 1,600 gp rounds to 2,000, four weeks
        // a thousand is eight (printed p. 95)
    if (derPrepWeeksPerThousandGp() * (derRozmareSwordMaterialGp() + 400) /
        1000 != 8
        )
            ++bad;
        // the font construction window: 2d4+2 weeks, the minimum four
        // (printed p. 87)
    if (derFontBuildWeeksDieCount() + derFontBuildWeeksBonus() != 4
        )
            ++bad;
        // the level thresholds: wizards at 9 and 11, priests at 7, 9 and 11
        // (printed p. 87)
    if (derWizPotionScrollLevel() != 9
            || derWizOtherItemLevel() != 11
            || derPriestScrollLevel() != 7
            || derPriestPotionLevel() != 9
            || derPriestOtherLevel() != 11
        )
            ++bad;
        printf("R605 DMO item-creation audit: bad %d\n", bad);
        if (bad) return 1;
    }
