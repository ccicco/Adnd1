    // ---- R747 OA armor explanation audit ----
    // OA round one hundred thirty-four (capture pp. 290-291): the Explanation
    // of Armor Properties - the armor of quality, the etherealness,
    // vulnerability, and missile attraction per the DMG, the presence, the
    // blending, the fear with the 2d4/2d10 charges discrepancy pinned as
    // printed, the possession mechanics, the healing armor, single-pass pins
    // per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dliQualityValueDie() != 4
            || dliPresenceCharisma() != 18
            || dliPresenceMoralePct() != 10
            || dliPresenceRadiusFt() != 12
            || dliFearRadiusFt() != 30
            || dliFearChargesDieFirst() != 4
            || dliFearChargesDieSecond() != 10
            || dliPossessionDaysDie() != 4
            || dliHealingPointsDie() != 6
            || dliHealingChargesDie() != 10
            || !dliQualityNotMagical()
            || !dliQualityFineConstruction()
            || !dliQualityNoACBonus()
            || !dliQualityLightFlexible()
            || !dliQualityOneEncumbranceLess()
            || !dliQualityDecorated()
            || !dliEtherealPerDMG()
            || !dliVulnerabilityPerDMG()
            || !dliVulnerabilityPlusesPenalty()
            || !dliMissileAttractionCursed()
            || !dliMissileAttractionNegative()
            || !dliPresenceCommandingAura()
            || !dliPresenceOnlyWhenVisible()
            || !dliBlendingDetectNotReveal()
            || !dliBlendingCommandWordClothing()
            || !dliBlendingRetainsProperties()
            || !dliBlendingTrueSeeingOnly()
            || !dliFearDetectOnlyMagical()
            || !dliFearCommandWordAura()
            || !dliFearSaveOrFleeOneTurn()
            || !dliFearWearerImmune()
            || !dliFearOneChargePerUse()
            || !dliFearChargesDiscrepancy()
            || !dliFearSpentBecomesPlusOne()
            || !dliPossessionAppearsNormal()
            || !dliPossessionStolenLifeforce()
            || !dliPossessionFirstDonnedDailySave()
            || !dliPossessionSaveSuccessNothing()
            || !dliPossessionSaveFailPossesses()
            || !dliPossessionGradualInsinuation()
            || !dliPossessionRefusesRemoval()
            || !dliPossessionBecomesNPC()
            || !dliPossessionExorcismBreaks()
            || !dliPossessionDispelTemporary()
            || !dliPossessionDestroyedLosesMagic()
            || !dliHealingAppearsNormal()
            || !dliHealingOncePerDayAutomatic()
            || !dliHealingOneChargeEach()
            || !dliHealingSpentBecomesPlusOne()
        )
            ++bad;
        // the quality and the presence and blending and fear mechanics,
        // healthy values, each condition false
    if (dliQualityNotMagical() != 1
            || dliQualityOneEncumbranceLess() != 1
            || dliQualityValueDie() != 4
            || dliPresenceCharisma() != 18
            || dliPresenceMoralePct() != 10
            || dliPresenceRadiusFt() != 12
            || dliBlendingTrueSeeingOnly() != 1
            || dliFearRadiusFt() != 30
            || dliFearChargesDieFirst() != 4
            || dliFearChargesDieSecond() != 10
        )
            ++bad;
        // the possession mechanics and the healing armor, healthy values,
        // each condition false
    if (dliPossessionDaysDie() != 4
            || dliPossessionFirstDonnedDailySave() != 1
            || dliPossessionExorcismBreaks() != 1
            || dliHealingPointsDie() != 6
            || dliHealingChargesDie() != 10
            || dliHealingOncePerDayAutomatic() != 1
            || dliHealingSpentBecomesPlusOne() != 1
        )
            ++bad;
        printf("R747 OA armor explanation audit: bad %d\n", bad);
        if (bad) return 1;
    }
