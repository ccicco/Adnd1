    // ---- R431 WSG equipment pin audit ----
    // The equipment effects slice pins the water, rust, leather, sand and
    // dust rules (rules/wsgequip.h, prefix weq): the moisture and rust
    // mechanics, the leather and rope rules, the wet-arrow penalty and the
    // chafe penalties; census 355 -> 356.
    {
        using namespace rules;
        int bad = 0;
    if (weqWetClothesDeltaTemp() != 10
            || weqRustDryDays() != 2
            || weqRustOilWeeks() != 2
            || weqArmorCrackRoll() != 20
            || weqArmorCrackDmgMin() != 4
            || weqArmorCrackDen() != 3
            || weqShieldSplitPct() != 50
            || weqWeaponBreakRoll() != 1
            || weqWeaponBreakDen() != 3
            || weqBootsDryDays() != 2
            || weqWetArrowPenalty() != -1
            || weqChafeSurpriseDen() != 6
            || weqChafeMoveNum() != 3
            || weqChafeMoveDen() != 4
            || weqChafeDexPenalty() != -1
            || !weqRustedArmorNoAcPenalty()
            || !weqArmorCrackOneStepWorse()
            || !weqArmorSecondHitBreaks()
            || !weqShieldNearMissSplits()
            || !weqLeatherCrackedAsRusted()
            || !weqLeatherHeatCracks()
            || !weqMudCanCrackLeather()
            || !weqWetKnotHardToUntie()
            || !weqDryKnotLoosens()
            || !weqArrowSpecialistExempt()
            || !weqMagicalInkWaterproof()
            || !weqSandAbrasionNegligible()
            || !weqSandPotionDmCall()
            || !weqDustNotAbrasive()
            || !weqDustNoChafe()
        )
            ++bad;
        // the wet-clothing example: wet gear at 30 degrees acts as 20 (10
        // colder)
    if (weqWetClothesDeltaTemp() != 10
            || 30 - weqWetClothesDeltaTemp() != 20
        )
            ++bad;
        // the armor crack gates: an unmodified 20 AND over 4 damage, then 1
        // in 3
    if (weqArmorCrackRoll() != 20
            || weqArmorCrackDmgMin() != 4
            || weqArmorCrackDen() != 3
        )
            ++bad;
        // the shield and weapon breaks: 50 percent on the near-miss, 1 in 3
        // on the unmodified 1
    if (weqShieldSplitPct() != 50
            || weqWeaponBreakRoll() != 1
            || weqWeaponBreakDen() != 3
        )
            ++bad;
        // the chafe penalties: +1 in 6 surprise, 3/4 speed, -1 dex
    if (weqChafeSurpriseDen() != 6
            || 3 * weqChafeMoveDen() != 4 * weqChafeMoveNum()
            || weqChafeDexPenalty() != -1
        )
            ++bad;
        printf("R431 WSG equipment pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
