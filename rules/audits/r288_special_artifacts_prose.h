    // ---- R288: the III.E Special artifacts
    // explanation prose part 9 ----
    // The Mighty Servant of Leuk-O,
    // part2 lines 1498-1517 (DMG p.163)
    // - the 18th of the 29 descriptions.
    // No seam restored this time - no page
    // break falls within these 20 lines.
    {
        int bad = 0;
        // the Servant make and frame scalars
        if (rules::sapServantLumSameMake() != 1 ||
            rules::sapServantAutomatonHeightFt() != 9 ||
            rules::sapServantDepthFt() != 6 ||
            rules::sapServantWidthFt() != 4 ||
            rules::sapServantInsideRiders() != 2 ||
            rules::sapServantOutsideSittersMin() != 4 ||
            rules::sapServantCommandPhrases() != 1) ++bad;
        // the Servant command and combat scalars
        if (rules::sapServantUseCount() != 3 ||
            rules::sapServantArmorClass() != 1 ||
            rules::sapServantHitPoints() != 60 ||
            rules::sapServantWeaponDamagePct() != 50 ||
            rules::sapServantRegenPerRound() != 2 ||
            rules::sapServantMagicResistPct() != 100 ||
            rules::sapServantElementImmuneCount() != 6 ||
            rules::sapServantElectricalDamagePct() != 20) ++bad;
        // the Servant movement and panic scalars
        if (rules::sapServantSpeedInches() != 3 ||
            rules::sapServantOperationHours() != 12 ||
            rules::sapServantRestHours() != 1 ||
            rules::sapServantPanicRangeInches() != 12 ||
            rules::sapServantPanicSaveBonus() != 2 ||
            rules::sapServantAttacksPerRound() != 1 ||
            rules::sapServantBaseHitPct() != 15) ++bad;
        // the Servant to-hit and damage scalars
        if (rules::sapServantDexReduceFloor() != 14 ||
            rules::sapServantDexReducePct() != 2 ||
            rules::sapServantDamageLowHp() != 10 ||
            rules::sapServantDamageHighHp() != 100 ||
            rules::sapServantObeysSecretLearners() != 1 ||
            rules::sapServantPowerTotal() != 17) ++bad;
        // the Servant powers per table I-VI
        static const int kSrv[6] = {
            6, 6, 1, 2, 0, 2,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapServantPowerCount(i) != kSrv[i]) ++bad;
        if (rules::sapServantPowerCount(0) +
            rules::sapServantPowerCount(1) +
            rules::sapServantPowerCount(2) +
            rules::sapServantPowerCount(3) +
            rules::sapServantPowerCount(4) +
            rules::sapServantPowerCount(5) !=
            rules::sapServantPowerTotal()) ++bad;
        // the frame sums: the width plus the
        // inside riders equals the depth
        if (rules::sapServantWidthFt() +
            rules::sapServantInsideRiders() !=
            rules::sapServantDepthFt()) ++bad;
        // the damage high agrees with the MR percent
        if (rules::sapServantDamageHighHp() !=
            rules::sapServantMagicResistPct()) ++bad;
        // the panic range agrees with the work span
        if (rules::sapServantPanicRangeInches() !=
            rules::sapServantOperationHours()) ++bad;
        // the 6 immunities agree with table I
        if (rules::sapServantElementImmuneCount() !=
            rules::sapServantPowerCount(0)) ++bad;
        // the cross-pin: the R240 sale table row
        if (rules::saRowLo(17) != 39 ||
            rules::saRowHi(17) != 40 ||
            rules::saSaleGp(17) != 185000) ++bad;
        printf("R288 special artifacts prose part 9 pins audit: bad %d\n", bad);
    }
