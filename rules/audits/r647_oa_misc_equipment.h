    // ---- R647 OA misc equipment audit ----
    // OA round thirty-four (capture p. 98): the miscellaneous equipment
    // descriptions - the grenades prose (pepper, dust, flash powder and
    // poison smoke)
    {
        using namespace rules;
        int bad = 0;
    if (dhhGrenadeKindCount() != 4
            || dhhPepperIncapLo() != 1
            || dhhPepperIncapHi() != 6
            || dhhDustBlindLo() != 1
            || dhhDustBlindHi() != 6
            || dhhFlashBlindLo() != 1
            || dhhFlashBlindHi() != 3
            || dhhSmokeFillFeet() != 5
            || dhhSmokeDmgLo() != 1
            || dhhSmokeDmgHi() != 2
            || dhhSmokeAreaFeet() != 10
            || dhhSmokeTurns() != 1
            || dhhEggshellFallFeet() != 10
            || !dhhGrenadeNoAcMod()
            || !dhhPepperSingleTarget()
            || !dhhFlashNeedsFire()
            || !dhhFlashPetrifySave()
            || !dhhSmokeNeedsFire()
            || !dhhSmokePoisonSave()
            || !dhhEggshellCrushSave()
        )
            ++bad;
        // the grenade kind count pin
    if (dhhGrenadeKindCount() != 4
        )
            ++bad;
        // the pepper incapacitation bounds pin - 1-6 rounds
    if (dhhPepperIncapLo() != 1
            || dhhPepperIncapHi() != 6
        )
            ++bad;
        // the dust blinding bounds pin - 1-6 rounds
    if (dhhDustBlindLo() != 1
            || dhhDustBlindHi() != 6
        )
            ++bad;
        // the flash blinding bounds pin - 1-3 rounds
    if (dhhFlashBlindLo() != 1
            || dhhFlashBlindHi() != 3
        )
            ++bad;
        // the poison smoke numbers pin - the 5-foot fill, the 1-2 damage, the
        // 10-foot area, the one turn
    if (dhhSmokeFillFeet() != 5
            || dhhSmokeDmgLo() != 1
            || dhhSmokeDmgHi() != 2
            || dhhSmokeAreaFeet() != 10
            || dhhSmokeTurns() != 1
        )
            ++bad;
        // the eggshell fall threshold pin - 10 feet
    if (dhhEggshellFallFeet() != 10
        )
            ++bad;
        // the no-armor-modifier doctrine pin
    if (dhhGrenadeNoAcMod() != 1
        )
            ++bad;
        // the pepper single-target pin
    if (dhhPepperSingleTarget() != 1
        )
            ++bad;
        // the flash fire-source and petrification-save pins
    if (dhhFlashNeedsFire() != 1
            || dhhFlashPetrifySave() != 1
        )
            ++bad;
        // the smoke fire-source and poison-save pins
    if (dhhSmokeNeedsFire() != 1
            || dhhSmokePoisonSave() != 1
        )
            ++bad;
        // the eggshell crushing-blow save pin
    if (dhhEggshellCrushSave() != 1
        )
            ++bad;
        printf("R647 OA misc equipment audit: bad %d\n", bad);
        if (bad) return 1;
    }
