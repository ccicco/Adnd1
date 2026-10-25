    // ---- R706 OA monsters Bakemono audit ----
    // OA round ninety-three (capture pp. 254-255): the Chapter 12 monster
    // roster - the Bakemono, the stat block and the description riding
    // together, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (djtBakemonoNoAppearingMin() != 1
            || djtBakemonoNoAppearingMax() != 100
            || djtBakemonoAC() != 6
            || djtBakemonoMove() != 6
            || djtBakemonoHDNum() != 1
            || djtBakemonoHDMod() != 1
            || djtBakemonoLairPct() != 40
            || djtBakemonoAttacks() != 1
            || djtBakemonoDmgMin() != 1
            || djtBakemonoDmgMax() != 6
            || djtBakemonoXPBase() != 10
            || djtBakemonoXPPerHP() != 1
            || djtBakemonoBandPerLieutenant() != 20
            || djtBakemonoLieutenantHD() != 2
            || djtBakemonoLieutenantAC() != 4
            || djtBakemonoLieutenantDmgMax() != 8
            || djtBakemonoStockadePct() != 40
            || djtBakemonoEquipCount() != 7
            || djtBakemonoEquipKatanaPct() != 5
            || djtBakemonoEquipNaginataPct() != 20
            || djtBakemonoEquipSpearPct() != 40
            || djtBakemonoEquipTetsuboPct() != 10
            || djtBakemonoEquipShortswordBowPct() != 10
            || djtBakemonoEquipChainShurikenPct() != 5
            || djtBakemonoEquipKusariGamaPct() != 10
            || djtBakemonoArmoredPct() != 20
            || djtBakemonoArmoredAC() != 5
            || djtBakemonoLangCount() != 4
            || !djtBakemonoGoblinCousins()
            || !djtBakemonoNoTwoAlike()
            || !djtBakemonoBandsForRaiding()
            || !djtBakemonoRuledByOniOrOgreMage()
            || !djtBakemonoLieutenantAbsoluteCommand()
            || !djtBakemonoLairAbandonedTemples()
            || !djtBakemonoScavengeNotMake()
            || !djtBakemonoArmorUnusableByPCs()
            || !djtBakemonoEasilyTricked()
            || !djtBakemonoSakeWeakness()
        )
            ++bad;
        // the stat block - the 1-100, the AC 6, the move 6, the HD 1-1, the
        // 40% lair, the treasure A, the 1 attack of 1-6, the 1/10 + 1 per hp
    if (djtBakemonoNoAppearingMin() != 1
            || djtBakemonoNoAppearingMax() != 100
            || djtBakemonoAC() != 6
            || djtBakemonoMove() != 6
            || djtBakemonoHDNum() != 1
            || djtBakemonoHDMod() != 1
            || djtBakemonoLairPct() != 40
            || djtBakemonoAttacks() != 1
            || djtBakemonoDmgMin() != 1
            || djtBakemonoDmgMax() != 6
            || djtBakemonoXPBase() != 10
            || djtBakemonoXPPerHP() != 1
        )
            ++bad;
        // the band organization - the 20 per lieutenant, the HD 2, the AC 4,
        // the 1-8, the absolute command, the oni or ogre mage rule
    if (djtBakemonoBandPerLieutenant() != 20
            || djtBakemonoLieutenantHD() != 2
            || djtBakemonoLieutenantAC() != 4
            || djtBakemonoLieutenantDmgMax() != 8
            || djtBakemonoLieutenantAbsoluteCommand() != 1
            || djtBakemonoRuledByOniOrOgreMage() != 1
        )
            ++bad;
        // the equipment table - the seven rows, the katana 5, the naginata
        // 20, the spear 40, the tetsubo 10, the short sword and bow 10, the
        // chain and shuriken 5, the kusari-gama 10, the scavenge-not-make
    if (djtBakemonoEquipCount() != 7
            || djtBakemonoEquipKatanaPct() != 5
            || djtBakemonoEquipNaginataPct() != 20
            || djtBakemonoEquipSpearPct() != 40
            || djtBakemonoEquipTetsuboPct() != 10
            || djtBakemonoEquipShortswordBowPct() != 10
            || djtBakemonoEquipChainShurikenPct() != 5
            || djtBakemonoEquipKusariGamaPct() != 10
            || djtBakemonoScavengeNotMake() != 1
        )
            ++bad;
        // the armor and the lair - the 20% at AC 5, the pieces unusable by
        // player characters, the abandoned temples, the 40% stockade
    if (djtBakemonoArmoredPct() != 20
            || djtBakemonoArmoredAC() != 5
            || djtBakemonoArmorUnusableByPCs() != 1
            || djtBakemonoLairAbandonedTemples() != 1
            || djtBakemonoStockadePct() != 40
        )
            ++bad;
        // the nature - the goblin cousins, the no-two-alike, the four
        // languages, the easily tricked, the sake weakness
    if (djtBakemonoGoblinCousins() != 1
            || djtBakemonoNoTwoAlike() != 1
            || djtBakemonoLangCount() != 4
            || djtBakemonoEasilyTricked() != 1
            || djtBakemonoSakeWeakness() != 1
        )
            ++bad;
        printf("R706 OA monsters Bakemono audit: bad %d\n", bad);
        if (bad) return 1;
    }
