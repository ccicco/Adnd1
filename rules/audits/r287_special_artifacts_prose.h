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
        Specart specart;
        Specart_axe_of_the_dwarvish_lords_to_codex specart_axe_of_the_dwarvish_lords_to_codex;
        int bad = 0;
        // the Quill scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapQuillMasterThiefBest() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapQuillUnknownAntiquity() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapQuillBearsKurothName() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapQuillInfallibleScribe() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapQuillDepictsSeenSpoken() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapQuillPotionTreasureFinding() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapQuillTreasureFindPerMonth() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapQuillPowerTotal() != 5) ++bad;
        // the Quill powers per table I-VI
        static const int kQrl[6] = {
            2, 0, 1, 1, 0, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapQuillPowerCount(i) != kQrl[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapQuillPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapQuillPowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapQuillPowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapQuillPowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapQuillPowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapQuillPowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapQuillPowerTotal()) ++bad;
        // the Mace scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapMaceSaintCuthbertWeapon() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMaceFollyOfError() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMaceRelicsEncased() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMaceHitDamageBonus() != 5 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMaceDisruptionEffects() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMaceClericStrReq() != 18 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMaceLawfulGoodOnly() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMacePowerTotal() != 6) ++bad;
        // the Mace powers per table I-VI
        static const int kMac[6] = {
            3, 2, 0, 0, 0, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapMacePowerCount(i) != kMac[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapMacePowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapMacePowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapMacePowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapMacePowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapMacePowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapMacePowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapMacePowerTotal()) ++bad;
        // the Mace bonus agrees with the Quill total
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapMaceHitDamageBonus() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapQuillPowerTotal()) ++bad;
        // the Machine scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapMachineGodsForgotten() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMachineWorkmanshipUnknown() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMachineBaronLumEmpire() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMachineLeverCount() != 60 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMachineDialCount() != 40 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMachineSwitchCount() != 20 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMachineControlsTotal() != 120 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMachineHalfFunction() != 60 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMachineWeightLb() != 5500 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMachineJoltDestroyMax() != 4 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMachineBoothCreatures() != 4 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMachinePowerTotal() != 70) ++bad;
        // the Machine controls add up
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapMachineLeverCount() +
            specart_axe_of_the_dwarvish_lords_to_codex.sapMachineDialCount() +
            specart_axe_of_the_dwarvish_lords_to_codex.sapMachineSwitchCount() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapMachineControlsTotal()) ++bad;
        // one-half of the controls still function
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapMachineHalfFunction() * 2 !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapMachineControlsTotal()) ++bad;
        // the Machine powers per table I-VI
        static const int kMch[6] = {
            15, 15, 10, 10, 15, 5,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapMachinePowerCount(i) != kMch[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapMachinePowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapMachinePowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapMachinePowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapMachinePowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapMachinePowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapMachinePowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapMachinePowerTotal()) ++bad;
        // the jolt cap agrees with the booth capacity
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapMachineJoltDestroyMax() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapMachineBoothCreatures()) ++bad;
        // the cross-pins: the R240 sale table rows
        if (specart.saRowLo(14) != 34 ||
            specart.saRowHi(14) != 35 ||
            specart.saSaleGp(14) != 27500 ||
            specart.saRowLo(15) != 36 ||
            specart.saRowHi(15) != 37 ||
            specart.saSaleGp(15) != 35000 ||
            specart.saRowLo(16) != 38 ||
            specart.saRowHi(16) != 38 ||
            specart.saSaleGp(16) != 72500) ++bad;
        printf("R287 special artifacts prose part 8 pins audit: bad %d\n", bad);
    }
