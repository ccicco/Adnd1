    // ---- R288: the III.E Special artifacts
    // explanation prose part 9 ----
    // The Mighty Servant of Leuk-O,
    // part2 lines 1498-1517 (DMG p.163)
    // - the 18th of the 29 descriptions.
    // No seam restored this time - no page
    // break falls within these 20 lines.
    {
        Specart specart;
        Specart_axe_of_the_dwarvish_lords_to_codex specart_axe_of_the_dwarvish_lords_to_codex;
        int bad = 0;
        // the Servant make and frame scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapServantLumSameMake() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantAutomatonHeightFt() != 9 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantDepthFt() != 6 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantWidthFt() != 4 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantInsideRiders() != 2 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantOutsideSittersMin() != 4 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantCommandPhrases() != 1) ++bad;
        // the Servant command and combat scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapServantUseCount() != 3 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantArmorClass() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantHitPoints() != 60 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantWeaponDamagePct() != 50 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantRegenPerRound() != 2 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantMagicResistPct() != 100 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantElementImmuneCount() != 6 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantElectricalDamagePct() != 20) ++bad;
        // the Servant movement and panic scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapServantSpeedInches() != 3 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantOperationHours() != 12 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantRestHours() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantPanicRangeInches() != 12 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantPanicSaveBonus() != 2 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantAttacksPerRound() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantBaseHitPct() != 15) ++bad;
        // the Servant to-hit and damage scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapServantDexReduceFloor() != 14 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantDexReducePct() != 2 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantDamageLowHp() != 10 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantDamageHighHp() != 100 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantObeysSecretLearners() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantPowerTotal() != 17) ++bad;
        // the Servant powers per table I-VI
        static const int kSrv[6] = {
            6, 6, 1, 2, 0, 2,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapServantPowerCount(i) != kSrv[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapServantPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantPowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantPowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantPowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantPowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantPowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantPowerTotal()) ++bad;
        // the frame sums: the width plus the
        // inside riders equals the depth
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapServantWidthFt() +
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantInsideRiders() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantDepthFt()) ++bad;
        // the damage high agrees with the MR percent
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapServantDamageHighHp() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantMagicResistPct()) ++bad;
        // the panic range agrees with the work span
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapServantPanicRangeInches() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantOperationHours()) ++bad;
        // the 6 immunities agree with table I
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapServantElementImmuneCount() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapServantPowerCount(0)) ++bad;
        // the cross-pin: the R240 sale table row
        if (specart.saRowLo(17) != 39 ||
            specart.saRowHi(17) != 40 ||
            specart.saSaleGp(17) != 185000) ++bad;
        printf("R288 special artifacts prose part 9 pins audit: bad %d\n", bad);
    }
