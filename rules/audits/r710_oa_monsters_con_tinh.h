    // ---- R710 OA monsters Con-Tinh audit ----
    // OA round ninety-seven (capture pp. 258-259): the Chapter 12 monster
    // roster - the con-tinh, the stat block and the description riding
    // together, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (djxConTinhNoAppearingMin() != 1
            || djxConTinhNoAppearingMax() != 2
            || djxConTinhAC() != 7
            || djxConTinhMove() != 12
            || djxConTinhHD() != 6
            || djxConTinhAttacks() != 1
            || djxConTinhDmgMin() != 1
            || djxConTinhDmgMax() != 6
            || djxConTinhMRPct() != 20
            || djxConTinhXPBase() != 600
            || djxConTinhXPPerHP() != 6
            || djxConTinhTreeRadiusFt() != 100
            || djxConTinhLaughRadiusFt() != 20
            || djxConTinhLaughsPerNight() != 3
            || djxConTinhInsanityFloor() != 2
            || djxConTinhWeaponPlusRequired() != 2
            || !djxConTinhRare()
            || !djxConTinhLair100()
            || !djxConTinhTreasureI()
            || !djxConTinhLaughAttack()
            || !djxConTinhIntStandard()
            || !djxConTinhChaoticEvil()
            || !djxConTinhSizeM()
            || !djxConTinhPsionicNil()
            || !djxConTinhEvilSpirit()
            || !djxConTinhMaidenSpirits()
            || !djxConTinhYoungGirlAppearance()
            || !djxConTinhNightOnly()
            || !djxConTinhTreeLifeforce()
            || !djxConTinhTreeDamageHurts()
            || !djxConTinhTreeDestroyedDestroys()
            || !djxConTinhFearedAndShunned()
            || !djxConTinhHidesInTreeByDay()
            || !djxConTinhNightAmbusher()
            || !djxConTinhNotFierceButSpecial()
            || !djxConTinhLaughSaveVsDeath()
            || !djxConTinhHealRestoresInsanity()
            || !djxConTinhPossessionOncePerNight()
            || !djxConTinhPossessionDaytimeToo()
            || !djxConTinhExorcismDestroys()
            || !djxConTinhTreeSlayerCursed()
            || !djxConTinhCurseDayOrNight()
        )
            ++bad;
        // the stat block - the rare, the 1-2, the AC 7, the move 12, the HD
        // 6, the 100% lair, the treasure I, the 1 attack of 1-6, the laugh,
        // the 20% MR, the standard, the chaotic evil, the M, the Nil
        // psionics, the VI/600 + 6/hp
    if (djxConTinhNoAppearingMin() != 1
            || djxConTinhNoAppearingMax() != 2
            || djxConTinhAC() != 7
            || djxConTinhMove() != 12
            || djxConTinhHD() != 6
            || djxConTinhAttacks() != 1
            || djxConTinhDmgMin() != 1
            || djxConTinhDmgMax() != 6
            || djxConTinhMRPct() != 20
            || djxConTinhXPBase() != 600
            || djxConTinhXPPerHP() != 6
            || djxConTinhRare() != 1
            || djxConTinhLair100() != 1
            || djxConTinhTreasureI() != 1
            || djxConTinhLaughAttack() != 1
            || djxConTinhIntStandard() != 1
            || djxConTinhChaoticEvil() != 1
            || djxConTinhSizeM() != 1
            || djxConTinhPsionicNil() != 1
        )
            ++bad;
        // the nature - the evil spirit, the maiden folklore, the young-girl
        // appearance, the night only, the 100-foot tree lifeforce with the
        // damage and destruction rules, the feared-and-shunned reputation,
        // the daytime hiding, the night ambushing
    if (djxConTinhTreeRadiusFt() != 100
            || djxConTinhEvilSpirit() != 1
            || djxConTinhMaidenSpirits() != 1
            || djxConTinhYoungGirlAppearance() != 1
            || djxConTinhNightOnly() != 1
            || djxConTinhTreeLifeforce() != 1
            || djxConTinhTreeDamageHurts() != 1
            || djxConTinhTreeDestroyedDestroys() != 1
            || djxConTinhFearedAndShunned() != 1
            || djxConTinhHidesInTreeByDay() != 1
            || djxConTinhNightAmbusher() != 1
        )
            ++bad;
        // the special attacks - the not-fierce-but-two- attacks doctrine, the
        // 20-foot laugh with the save vs. death or insanity, the Int and Wis
        // 2 floor until heal, the once-per-night possession maintained into
        // daytime, the +2-or-greater weapon requirement, the exorcism
        // destruction, the tree-slayer ancient curse, automatic day or night
    if (djxConTinhLaughRadiusFt() != 20
            || djxConTinhLaughsPerNight() != 3
            || djxConTinhInsanityFloor() != 2
            || djxConTinhWeaponPlusRequired() != 2
            || djxConTinhNotFierceButSpecial() != 1
            || djxConTinhLaughSaveVsDeath() != 1
            || djxConTinhHealRestoresInsanity() != 1
            || djxConTinhPossessionOncePerNight() != 1
            || djxConTinhPossessionDaytimeToo() != 1
            || djxConTinhExorcismDestroys() != 1
            || djxConTinhTreeSlayerCursed() != 1
            || djxConTinhCurseDayOrNight() != 1
        )
            ++bad;
        printf("R710 OA monsters Con-Tinh audit: bad %d\n", bad);
        if (bad) return 1;
    }
