    // ---- R327: the class tables pin
    // audit ----
    // UA Character Classes Table I
    // (p. 12) and Table II (p. 13) - the
    // pin-era pattern: the hit-die
    // column, the first-level dice, the
    // note-1 social-standing generators,
    // the dice maxima, the druid 23, the
    // spell-ability legs, the Table II
    // footnotes; the R230 registry rows
    // cross-checked (the ranger and
    // monk dice already carried).
    {
        using namespace rules;
        int bad = 0;
        // U1: the hit-die column
        {
            if (uaClassHitDie(
                UACLASS_CAVALIER) != 10) ++bad;
            if (uaClassHitDie(
                UACLASS_BARBARIAN) != 12) ++bad;
            if (uaClassHitDie(
                UACLASS_RANGER) != 8) ++bad;
            if (uaClassHitDie(
                UACLASS_MONK) != 4) ++bad;
        }
        // U2: the first-level dice
        {
            if (uaClassFirstLevelDice(
                UACLASS_RANGER) != 2) ++bad;
            if (uaClassFirstLevelDice(
                UACLASS_MONK) != 2) ++bad;
            if (uaClassFirstLevelDice(
                UACLASS_CAVALIER) != 1) ++bad;
            if (uaClassFirstLevelDice(
                UACLASS_BARBARIAN) != 1) ++bad;
        }
        // U3: the registry cross-check
        // (the R230 rows carry the dice)
        {
            const SubclassDef& rg =
                subclassDef(SUB_RANGER);
            if (rg.hitDie != 8) ++bad;
            if (rg.twoDiceFirstLevel != 1)
                ++bad;
            const SubclassDef& mk =
                subclassDef(SUB_MONK);
            if (mk.hitDie != 4) ++bad;
            if (mk.twoDiceFirstLevel != 1)
                ++bad;
            if (mk.levelCap != 17) ++bad;
        }
        // U4: the note-1 generators -
        // both tracks yield the printed
        // 4-13 range (3d4+1, d10+3)
        {
            if (cavalierTrackDice(
                CAVALIER_TRACK_ZERO) != 3)
                ++bad;
            if (cavalierTrackSides(
                CAVALIER_TRACK_ZERO) != 4)
                ++bad;
            if (cavalierTrackBonus(
                CAVALIER_TRACK_ZERO) != 1)
                ++bad;
            if (cavalierTrackDice(
                CAVALIER_TRACK_UPPER) != 1)
                ++bad;
            if (cavalierTrackSides(
                CAVALIER_TRACK_UPPER) != 10)
                ++bad;
            if (cavalierTrackBonus(
                CAVALIER_TRACK_UPPER) != 3)
                ++bad;
            if (3*1 + 1 < 4
                || 3*4 + 1 > 13) ++bad;
            if (1*1 + 3 < 4
                || 1*10 + 3 > 13) ++bad;
        }
        // U5: the maxima and the limit
        {
            if (rangerMaxHitDice() != 11)
                ++bad;
            if (rangerMaxHitDiceLevel() != 10)
                ++bad;
            if (monkMaxHitDice() != 18)
                ++bad;
            if (monkMaxHitDiceLevel() != 17)
                ++bad;
            if (druidClassLevelLimit() != 23)
                ++bad;
        }
        // U6: the spell-ability legs
        {
            if (paladinClericalFromLevel()
                != 9) ++bad;
            if (paladinClericalMaxSpellLevel()
                != 4) ++bad;
            if (rangerDruidicFromLevel()
                != 8) ++bad;
            if (rangerDruidicMaxSpellLevel()
                != 3) ++bad;
            if (rangerMuFromLevel()
                != 9) ++bad;
            if (rangerMuMaxSpellLevel()
                != 2) ++bad;
            if (thiefScrollFromLevel()
                != 10) ++bad;
            if (assassinScrollFromLevel()
                != 12) ++bad;
        }
        // U7: the Table II footnotes
        {
            if (!uaStationArmorBan(
                UACLASS_CAVALIER)) ++bad;
            if (!uaStationArmorBan(
                UACLASS_PALADIN)) ++bad;
            if (uaStationArmorBan(
                UACLASS_FIGHTER)) ++bad;
            if (!uaStationWeaponBan(
                UACLASS_CAVALIER)) ++bad;
            if (!uaStationWeaponBan(
                UACLASS_PALADIN)) ++bad;
            if (uaStationWeaponBan(
                UACLASS_RANGER)) ++bad;
            if (!uaOilSiegeException(
                UACLASS_CAVALIER)) ++bad;
            if (!uaOilSiegeException(
                UACLASS_PALADIN)) ++bad;
            if (uaOilSiegeException(
                UACLASS_THIEF)) ++bad;
        }
        // U8: the acrobat as-thief-plus
        // row
        {
            if (acrobatExtraWeaponCount()
                != 2) ++bad;
            if (strcmp(acrobatExtraWeaponName(0),
                "lasso") != 0) ++bad;
            if (strcmp(acrobatExtraWeaponName(1),
                "staff") != 0) ++bad;
        }
        printf("R327 class tables pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
