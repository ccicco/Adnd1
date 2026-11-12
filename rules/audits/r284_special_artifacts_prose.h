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
        Specart specart;
        Specart_axe_of_the_dwarvish_lords_to_codex specart_axe_of_the_dwarvish_lords_to_codex;
        int bad = 0;
        // the Eye scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapEyeVecnaPhantomRoams() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapEyeDoomSurvivors() != 2 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapEyeFeralGlow() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapEyeAppearsAgate() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapEyeGraftIrrevocable() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapEyeHostNeutralEvil() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapEyeGrantsInfravision() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapEyeGrantsUltravision() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapEyePowerTotal() != 6 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapEyePrimaryPowerMalevolent() != 1) ++bad;
        // the Hand scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapHandVecnaLeftHand() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandMummifiedExtremity() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandGripStrength() != 18 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandGripStrengthRating() != 0 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandGripHitOrDamageBonus() != 0 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandHostTurnsNeutralEvil() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandMajorPowerWakesSpirit() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandPrimaryPowerInstantEvil() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandSeverBaseChancePct() != 100 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandSeverMajorPenaltyPct() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandSeverPrimaryPenaltyPct() != 10 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandNoRemovalAtLimit() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandFingerCombinations() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandPowerTotal() != 22 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandGodsOnlyAlteration() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandRecordCombinations() != 1) ++bad;
        // the eye powers per tables I-V
        static const int kEye[5] = {
            2, 2, 0, 1, 1,
        };
        for (int i = 0; i < 5; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapEyePowerCount(i) != kEye[i]) ++bad;
        // table III is skipped
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapEyePowerCount(2) != 0) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapEyePowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapEyePowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapEyePowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapEyePowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapEyePowerCount(4) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapEyePowerTotal()) ++bad;
        // the hand powers per table I-VI
        static const int kHap[6] = {
            10, 5, 2, 2, 2, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapHandPowerCount(i) != kHap[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapHandPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandPowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandPowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandPowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandPowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandPowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandPowerTotal()) ++bad;
        // the grip: strength 18, rating 00, no bonuses
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapHandGripStrength() * 100 +
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandGripStrengthRating() != 1800) ++bad;
        // the severance math: a primary power costs
        // ten times a major power
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapHandSeverPrimaryPenaltyPct() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandSeverMajorPenaltyPct() * 10) ++bad;
        // at the limit the subtractions reach the base
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapHandSeverBaseChancePct() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandSeverPrimaryPenaltyPct() * 10) ++bad;
        // both relics turn the host neutral evil
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapEyeHostNeutralEvil() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapHandHostTurnsNeutralEvil()) ++bad;
        // both relics survived the one doom
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapEyeDoomSurvivors() != 2) ++bad;
        // the cross-pins: the R240 sale table rows
        if (specart.saRowLo(6) != 23 ||
            specart.saRowHi(6) != 24 ||
            specart.saSaleGp(6) != 35000 ||
            specart.saRowLo(7) != 25 ||
            specart.saRowHi(7) != 25 ||
            specart.saSaleGp(7) != 60000) ++bad;
        printf("R284 special artifacts prose part 5 pins audit: bad %d\n", bad);
    }
