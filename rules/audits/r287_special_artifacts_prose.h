    // ---- R287: the III.E Special artifacts
    // explanation prose part 8 ----
    // Kuroths Quill, the Mace of Cuthbert and
    // the Machine of Lum the Mad, part2 lines
    // 1452-1497 (DMG p.163) - the 15th through
    // the 17th of the 29 descriptions.
    // No seam restored this time - the p.162-163
    // break fell in R286 and no page break falls
    // within these 46 lines.
    {
        int bad = 0;
        // the Quill scalars
        if (rules::sapQuillMasterThiefBest() != 1 ||
            rules::sapQuillUnknownAntiquity() != 1 ||
            rules::sapQuillBearsKurothName() != 1 ||
            rules::sapQuillInfallibleScribe() != 1 ||
            rules::sapQuillDepictsSeenSpoken() != 1 ||
            rules::sapQuillPotionTreasureFinding() != 1 ||
            rules::sapQuillTreasureFindPerMonth() != 1 ||
            rules::sapQuillPowerTotal() != 5) ++bad;
        // the Quill powers per table I-VI
        static const int kQrl[6] = {
            2, 0, 1, 1, 0, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapQuillPowerCount(i) != kQrl[i]) ++bad;
        if (rules::sapQuillPowerCount(0) +
            rules::sapQuillPowerCount(1) +
            rules::sapQuillPowerCount(2) +
            rules::sapQuillPowerCount(3) +
            rules::sapQuillPowerCount(4) +
            rules::sapQuillPowerCount(5) !=
            rules::sapQuillPowerTotal()) ++bad;
        // the Mace scalars
        if (rules::sapMaceSaintCuthbertWeapon() != 1 ||
            rules::sapMaceFollyOfError() != 1 ||
            rules::sapMaceRelicsEncased() != 1 ||
            rules::sapMaceHitDamageBonus() != 5 ||
            rules::sapMaceDisruptionEffects() != 1 ||
            rules::sapMaceClericStrReq() != 18 ||
            rules::sapMaceLawfulGoodOnly() != 1 ||
            rules::sapMacePowerTotal() != 6) ++bad;
        // the Mace powers per table I-VI
        static const int kMac[6] = {
            3, 2, 0, 0, 0, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapMacePowerCount(i) != kMac[i]) ++bad;
        if (rules::sapMacePowerCount(0) +
            rules::sapMacePowerCount(1) +
            rules::sapMacePowerCount(2) +
            rules::sapMacePowerCount(3) +
            rules::sapMacePowerCount(4) +
            rules::sapMacePowerCount(5) !=
            rules::sapMacePowerTotal()) ++bad;
        // the Mace bonus agrees with the Quill total
        if (rules::sapMaceHitDamageBonus() !=
            rules::sapQuillPowerTotal()) ++bad;
        // the Machine scalars
        if (rules::sapMachineGodsForgotten() != 1 ||
            rules::sapMachineWorkmanshipUnknown() != 1 ||
            rules::sapMachineBaronLumEmpire() != 1 ||
            rules::sapMachineLeverCount() != 60 ||
            rules::sapMachineDialCount() != 40 ||
            rules::sapMachineSwitchCount() != 20 ||
            rules::sapMachineControlsTotal() != 120 ||
            rules::sapMachineHalfFunction() != 60 ||
            rules::sapMachineWeightLb() != 5500 ||
            rules::sapMachineJoltDestroyMax() != 4 ||
            rules::sapMachineBoothCreatures() != 4 ||
            rules::sapMachinePowerTotal() != 70) ++bad;
        // the Machine controls add up
        if (rules::sapMachineLeverCount() +
            rules::sapMachineDialCount() +
            rules::sapMachineSwitchCount() !=
            rules::sapMachineControlsTotal()) ++bad;
        // one-half of the controls still function
        if (rules::sapMachineHalfFunction() * 2 !=
            rules::sapMachineControlsTotal()) ++bad;
        // the Machine powers per table I-VI
        static const int kMch[6] = {
            15, 15, 10, 10, 15, 5,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapMachinePowerCount(i) != kMch[i]) ++bad;
        if (rules::sapMachinePowerCount(0) +
            rules::sapMachinePowerCount(1) +
            rules::sapMachinePowerCount(2) +
            rules::sapMachinePowerCount(3) +
            rules::sapMachinePowerCount(4) +
            rules::sapMachinePowerCount(5) !=
            rules::sapMachinePowerTotal()) ++bad;
        // the jolt cap agrees with the booth capacity
        if (rules::sapMachineJoltDestroyMax() !=
            rules::sapMachineBoothCreatures()) ++bad;
        // the cross-pins: the R240 sale table rows
        if (rules::saRowLo(14) != 34 ||
            rules::saRowHi(14) != 35 ||
            rules::saSaleGp(14) != 27500 ||
            rules::saRowLo(15) != 36 ||
            rules::saRowHi(15) != 37 ||
            rules::saSaleGp(15) != 35000 ||
            rules::saRowLo(16) != 38 ||
            rules::saRowHi(16) != 38 ||
            rules::saSaleGp(16) != 72500) ++bad;
        printf("R287 special artifacts prose part 8 pins audit: bad %d\n", bad);
    }
