    // ---- R711 OA monsters Doc Cu'o'c audit ----
    // OA round ninety-eight (capture p. 259): the Chapter 12 monster roster -
    // the doc cu'o'c, the first greater spirit of the roster, the stat block
    // and the description riding together, single-pass pins per the Chapter 9
    // provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (djyDocCuocNoAppearing() != 1
            || djyDocCuocAC() != -3
            || djyDocCuocMove() != 24
            || djyDocCuocHD() != 10
            || djyDocCuocLairPct() != 10
            || djyDocCuocAttacks() != 2
            || djyDocCuocDmgMin() != 1
            || djyDocCuocDmgMax() != 8
            || djyDocCuocMRPct() != 70
            || djyDocCuocXPLevel() != 8
            || djyDocCuocXPBase() != 3600
            || djyDocCuocXPPerHP() != 14
            || djyDocCuocWeaponPlusRequired() != 3
            || djyDocCuocOncePerDaySpells() != 5
            || djyDocCuocThricePerDaySpells() != 2
            || djyDocCuocAxeDmgMax() != 8
            || !djyDocCuocVeryRare()
            || !djyDocCuocTreasureG()
            || !djyDocCuocIntGenius()
            || !djyDocCuocChaoticGood()
            || !djyDocCuocSizeM()
            || !djyDocCuocPsionicNil()
            || !djyDocCuocHalfManOneLeg()
            || !djyDocCuocAlwaysCarriesAxe()
            || !djyDocCuocBeneficialIfOffered()
            || !djyDocCuocCountrysideProtector()
            || !djyDocCuocSeesInvisible()
            || !djyDocCuocInvisibleAtWill()
            || !djyDocCuocEvilSpiritEnemies()
            || !djyDocCuocCropWeatherDoctrine()
            || !djyDocCuocSeldomDirectInvolvement()
            || !djyDocCuocProtectsLandNotPeople()
            || !djyDocCuocAxeElectricalShock()
            || !djyDocCuocShockSaveVsSpellHalves()
            || !djyDocCuocLairAstralPlane()
            || !djyDocCuocStoresOfferingsAndTrophies()
            || !djyDocCuocRobberyHavocRule()
            || !djyDocCuocLeavesForeverAfterHavoc()
        )
            ++bad;
        // the stat block - the very rare, the 1, the AC -3, the move 24, the
        // HD 10, the 10% lair, the treasure G, the 2 attacks of 1-8/1-8 +
        // special, the 70% MR, the genius, the chaotic good, the M, the Nil
        // psionics, the VIII/3,600 + 14/hp
    if (djyDocCuocNoAppearing() != 1
            || djyDocCuocAC() != -3
            || djyDocCuocMove() != 24
            || djyDocCuocHD() != 10
            || djyDocCuocLairPct() != 10
            || djyDocCuocAttacks() != 2
            || djyDocCuocDmgMin() != 1
            || djyDocCuocDmgMax() != 8
            || djyDocCuocMRPct() != 70
            || djyDocCuocXPLevel() != 8
            || djyDocCuocXPBase() != 3600
            || djyDocCuocXPPerHP() != 14
            || djyDocCuocVeryRare() != 1
            || djyDocCuocTreasureG() != 1
            || djyDocCuocIntGenius() != 1
            || djyDocCuocChaoticGood() != 1
            || djyDocCuocSizeM() != 1
            || djyDocCuocPsionicNil() != 1
        )
            ++bad;
        // the nature - the half-man one-leg form, the always-carried axe, the
        // offering-and-worship covenant, the countryside protectorship, the
        // see-invisible, the invisible at will, the evil-spirit enmity, the
        // crop-weather doctrine, the seldom-direct-involvement restraint, the
        // protects-the-land-not-the-people priority
    if (djyDocCuocHalfManOneLeg() != 1
            || djyDocCuocAlwaysCarriesAxe() != 1
            || djyDocCuocBeneficialIfOffered() != 1
            || djyDocCuocCountrysideProtector() != 1
            || djyDocCuocSeesInvisible() != 1
            || djyDocCuocInvisibleAtWill() != 1
            || djyDocCuocEvilSpiritEnemies() != 1
            || djyDocCuocCropWeatherDoctrine() != 1
            || djyDocCuocSeldomDirectInvolvement() != 1
            || djyDocCuocProtectsLandNotPeople() != 1
        )
            ++bad;
        // the axe and the lair - the 1d8 axe, the electrical shock at current
        // hit points, the save vs. spell for half, the +3 weapon requirement,
        // the five once-per-day cures, the two thrice-per-day powers, the
        // Astral-Plane lair, the offerings and trophies hoard, the
        // robbery-havoc rule, the leaves-forever departure
    if (djyDocCuocWeaponPlusRequired() != 3
            || djyDocCuocOncePerDaySpells() != 5
            || djyDocCuocThricePerDaySpells() != 2
            || djyDocCuocAxeDmgMax() != 8
            || djyDocCuocAxeElectricalShock() != 1
            || djyDocCuocShockSaveVsSpellHalves() != 1
            || djyDocCuocLairAstralPlane() != 1
            || djyDocCuocStoresOfferingsAndTrophies() != 1
            || djyDocCuocRobberyHavocRule() != 1
            || djyDocCuocLeavesForeverAfterHavoc() != 1
        )
            ++bad;
        printf("R711 OA monsters Doc Cu'o'c audit: bad %d\n", bad);
        if (bad) return 1;
    }
