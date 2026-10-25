    // ---- R284: the III.E Special artifacts
    // explanation prose part 5 ----
    // The Eye of Vecna and The Hand of Vecna,
    // part2 lines 1318-1357 (DMG p.160-161) -
    // the seventh and eighth of the 29 artifact
    // descriptions. One seam restored: the
    // p.160-161 page break splits the severing
    // paragraph between the 1332 tail and
    // the 1337 head.
    {
        int bad = 0;
        // the Eye scalars
        if (rules::sapEyeVecnaPhantomRoams() != 1 ||
            rules::sapEyeDoomSurvivors() != 2 ||
            rules::sapEyeFeralGlow() != 1 ||
            rules::sapEyeAppearsAgate() != 1 ||
            rules::sapEyeGraftIrrevocable() != 1 ||
            rules::sapEyeHostNeutralEvil() != 1 ||
            rules::sapEyeGrantsInfravision() != 1 ||
            rules::sapEyeGrantsUltravision() != 1 ||
            rules::sapEyePowerTotal() != 6 ||
            rules::sapEyePrimaryPowerMalevolent() != 1) ++bad;
        // the Hand scalars
        if (rules::sapHandVecnaLeftHand() != 1 ||
            rules::sapHandMummifiedExtremity() != 1 ||
            rules::sapHandGripStrength() != 18 ||
            rules::sapHandGripStrengthRating() != 0 ||
            rules::sapHandGripHitOrDamageBonus() != 0 ||
            rules::sapHandHostTurnsNeutralEvil() != 1 ||
            rules::sapHandMajorPowerWakesSpirit() != 1 ||
            rules::sapHandPrimaryPowerInstantEvil() != 1 ||
            rules::sapHandSeverBaseChancePct() != 100 ||
            rules::sapHandSeverMajorPenaltyPct() != 1 ||
            rules::sapHandSeverPrimaryPenaltyPct() != 10 ||
            rules::sapHandNoRemovalAtLimit() != 1 ||
            rules::sapHandFingerCombinations() != 1 ||
            rules::sapHandPowerTotal() != 22 ||
            rules::sapHandGodsOnlyAlteration() != 1 ||
            rules::sapHandRecordCombinations() != 1) ++bad;
        // the eye powers per tables I-V
        static const int kEye[5] = {
            2, 2, 0, 1, 1,
        };
        for (int i = 0; i < 5; ++i)
            if (rules::sapEyePowerCount(i) != kEye[i]) ++bad;
        // table III is skipped
        if (rules::sapEyePowerCount(2) != 0) ++bad;
        if (rules::sapEyePowerCount(0) +
            rules::sapEyePowerCount(1) +
            rules::sapEyePowerCount(2) +
            rules::sapEyePowerCount(3) +
            rules::sapEyePowerCount(4) !=
            rules::sapEyePowerTotal()) ++bad;
        // the hand powers per table I-VI
        static const int kHap[6] = {
            10, 5, 2, 2, 2, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapHandPowerCount(i) != kHap[i]) ++bad;
        if (rules::sapHandPowerCount(0) +
            rules::sapHandPowerCount(1) +
            rules::sapHandPowerCount(2) +
            rules::sapHandPowerCount(3) +
            rules::sapHandPowerCount(4) +
            rules::sapHandPowerCount(5) !=
            rules::sapHandPowerTotal()) ++bad;
        // the grip: strength 18, rating 00, no bonuses
        if (rules::sapHandGripStrength() * 100 +
            rules::sapHandGripStrengthRating() != 1800) ++bad;
        // the severance math: a primary power costs
        // ten times a major power
        if (rules::sapHandSeverPrimaryPenaltyPct() !=
            rules::sapHandSeverMajorPenaltyPct() * 10) ++bad;
        // at the limit the subtractions reach the base
        if (rules::sapHandSeverBaseChancePct() !=
            rules::sapHandSeverPrimaryPenaltyPct() * 10) ++bad;
        // both relics turn the host neutral evil
        if (rules::sapEyeHostNeutralEvil() !=
            rules::sapHandHostTurnsNeutralEvil()) ++bad;
        // both relics survived the one doom
        if (rules::sapEyeDoomSurvivors() != 2) ++bad;
        // the cross-pins: the R240 sale table rows
        if (rules::saRowLo(6) != 23 ||
            rules::saRowHi(6) != 24 ||
            rules::saSaleGp(6) != 35000 ||
            rules::saRowLo(7) != 25 ||
            rules::saRowHi(7) != 25 ||
            rules::saSaleGp(7) != 60000) ++bad;
        printf("R284 special artifacts prose part 5 pins audit: bad %d\n", bad);
    }
