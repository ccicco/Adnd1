    // ---- R461 WSG airborne fall chance pin audit ----
    // The Chapter 5 closer: the fall-chance system (printed p. 48) and the
    // airborne riding proficiency (printed p. 49) pin as rules/wsgfallair.h
    // (NEW, prefix wfa): the 0% base with the seven reduction modifiers (the
    // full-body strap -200, the lower-body strap -150, the proficiency -50,
    // the saddle -10, the stirrups -10, the -2 per ability point above 12
    // with the strength cap 18) and the seven increase modifiers (the
    // hands-free +50, the overload +20, the faster-than-normal +20, the
    // unwilling mount +20, the inclement weather +20, the not-level +10, the
    // +2 per ability point below 12 and the +1 per wind mph above the 30-mph
    // threshold), the every-three-turns check cadence restarting on each
    // landing with the bad-conditions once-per-round exception, and the
    // proficiency pins (the per-category slots with the dragon-and-griffon
    // two-slot example, the -50/+50 hands-free negation, no mount control,
    // the feats under ideal conditions only, the nonproficient automatic feat
    // failure).
    {
        using namespace rules;
        int bad = 0;
    if (wfaBaseFallChancePct() != 0
            || wfaStrapFullBodyPct() != -200
            || wfaStrapLowerBodyPct() != -150
            || wfaAirborneProfPct() != -50
            || wfaSaddlePct() != -10
            || wfaStirrupsPct() != -10
            || wfaPerAbilityAbove12Pct() != -2
            || wfaAbilityModThreshold() != 12
            || wfaStrengthCap() != 18
            || wfaPerAbilityBelow12Pct() != 2
            || wfaFreeHandsPct() != 50
            || wfaOverloadPct() != 20
            || wfaFasterThanNormalPct() != 20
            || wfaUnwillingMountPct() != 20
            || wfaInclementWeatherPct() != 20
            || wfaNotFlyingLevelPct() != 10
            || wfaWindThresholdMph() != 30
            || wfaPerWindMphAbove30Pct() != 1
            || wfaFallCheckEveryTurns() != 3
            || wfaBadConditionsPerRounds() != 1
            || !wfaChanceUnlessFastened()
            || !wfaSaddleNoAttachmentWorse()
            || !wfaNoSaddleWorseStill()
            || !wfaCheckRestartsOnLanding()
            || !wfaBadConditionsMayCheckPerRound()
            || !wfaNonproficientAutoFails()
            || !wfaProficiencyPerCategory()
            || !wfaTwoCategoriesTwoSlots()
            || !wfaProfNegatesFreeHands()
            || !wfaProfImpartsNoControl()
            || !wfaFeatsIdealConditionsOnly()
        )
            ++bad;
        // the book example: the proficiency -50% negates the +50% hands-free
        // under normal conditions
    if (wfaAirborneProfPct() + wfaFreeHandsPct() != 0
        )
            ++bad;
        // the full-body strap is strictly more protective than the
        // lower-body-only strap
    if (wfaStrapFullBodyPct() >= wfaStrapLowerBodyPct()
        )
            ++bad;
        // the saddle and stirrups reductions sum to -20
    if (wfaSaddlePct() + wfaStirrupsPct() != -20
        )
            ++bad;
        // the symmetric per-point ladder: four points above 12 (-8%) mirrors
        // four below (+8%)
    if (4 * wfaPerAbilityAbove12Pct() + 4 * wfaPerAbilityBelow12Pct() != 0
        )
            ++bad;
        // a 40-mph wind: 10 mph over the threshold at +1% per mph gives +10%
    if (40 - wfaWindThresholdMph() != 10 * wfaPerWindMphAbove30Pct()
        )
            ++bad;
        printf("R461 WSG airborne fall chance pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
