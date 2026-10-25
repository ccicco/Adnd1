    // ---- R328: the cavalier pin audit ----
    // The UA cavalier class (pp. 14-16) - the
    // pin-era pattern: the minima, the
    // 0-level track, the race gate, the
    // weapons-of-choice ladder, the parry and
    // armor reads, the mounted and horsemanship
    // ladders, the percentile growth, the saves
    // and immunities, the chivalric code facts,
    // the Table I clean cells. The title holes
    // (levels 5, 6, 11, 12) are documented
    // in-header and stay open with the Table I
    // gap item.
    {
        using namespace rules;
        int bad = 0;
        // U1: the class minima
        {
            if (cavalierMinAbility(
                ABILITY_STR) != 15) ++bad;
            if (cavalierMinAbility(
                ABILITY_DEX) != 15) ++bad;
            if (cavalierMinAbility(
                ABILITY_CON) != 15) ++bad;
            if (cavalierMinAbility(
                ABILITY_INT) != 10) ++bad;
            if (cavalierMinAbility(
                ABILITY_WIS) != 10) ++bad;
            if (cavalierMinAbility(
                ABILITY_CHA) != 0) ++bad;
            if (!cavalierNoPrimeRequisite())
                ++bad;
            if (!cavalierGoodAlignmentOnly())
                ++bad;
            if (!cavalierSpecializationBanned())
                ++bad;
        }
        // U2: the 0-level track and the race
        // gate
        {
            if (cavalierHorsemanXp() != -1500)
                ++bad;
            if (cavalierLancerXp() != -500)
                ++bad;
            if (!cavalierRaceAllowed(
                SUB_HUMAN, false)) ++bad;
            if (!cavalierRaceAllowed(
                SUB_NONE, false)) ++bad;
            if (cavalierRaceAllowed(
                SUB_ELF_HIGH, false)) ++bad;
            if (!cavalierRaceAllowed(
                SUB_ELF_HIGH, true)) ++bad;
            if (cavalierRaceAllowed(
                SUB_ELF_GRAY, false)) ++bad;
            if (!cavalierRaceAllowed(
                SUB_ELF_GRAY, true)) ++bad;
            if (cavalierRaceAllowed(
                SUB_ELF_DARK, false)) ++bad;
            if (!cavalierRaceAllowed(
                SUB_ELF_DARK, true)) ++bad;
            if (cavalierRaceAllowed(
                SUB_HALFELF, false)) ++bad;
            if (!cavalierRaceAllowed(
                SUB_HALFELF, true)) ++bad;
            if (cavalierRaceAllowed(
                SUB_DWARF_HILL, true)) ++bad;
            if (cavalierRaceAllowed(
                SUB_ELF_WOOD, true)) ++bad;
            if (cavalierRaceAllowed(
                SUB_HALFLING_HAIRFOOT,
                true)) ++bad;
        }
        // U3: the weapons-of-choice ladder
        {
            if (cavalierWeaponOfChoiceBonus(
                CAVALIER_WOC_LANCE, 1) != 1)
                ++bad;
            if (cavalierWeaponOfChoiceBonus(
                CAVALIER_WOC_LANCE, 6) != 1)
                ++bad;
            if (cavalierWeaponOfChoiceBonus(
                CAVALIER_WOC_LANCE, 7) != 2)
                ++bad;
            if (cavalierWeaponOfChoiceBonus(
                CAVALIER_WOC_LANCE, 12) != 2)
                ++bad;
            if (cavalierWeaponOfChoiceBonus(
                CAVALIER_WOC_LANCE, 13) != 3)
                ++bad;
            if (cavalierWeaponOfChoiceBonus(
                CAVALIER_WOC_LANCE, 0) != 0)
                ++bad;
            if (cavalierWeaponOfChoiceBonus(
                CAVALIER_WOC_SWORD, 2) != 0)
                ++bad;
            if (cavalierWeaponOfChoiceBonus(
                CAVALIER_WOC_SWORD, 3) != 1)
                ++bad;
            if (cavalierWeaponOfChoiceBonus(
                CAVALIER_WOC_SWORD, 9) != 2)
                ++bad;
            if (cavalierWeaponOfChoiceBonus(
                CAVALIER_WOC_MACE, 4) != 0)
                ++bad;
            if (cavalierWeaponOfChoiceBonus(
                CAVALIER_WOC_MACE, 5) != 1)
                ++bad;
            if (cavalierWeaponOfChoiceBonus(
                CAVALIER_WOC_MACE, 11) != 2)
                ++bad;
            if (cavalierChoiceAttackLevelBonus()
                != 5) ++bad;
            if (cavalierChoiceAttacksPerRoundLevel()
                != 16) ++bad;
            if (cavalierLanceMountedDamageBonus(
                9) != 9) ++bad;
            if (cavalierLanceDismountedDamageBonus()
                != 1) ++bad;
            if (cavalierPreferredWeaponCount()
                != 11) ++bad;
            if (strcmp(
                cavalierPreferredWeaponName(0),
                "lance") != 0) ++bad;
            if (strcmp(
                cavalierPreferredWeaponName(9),
                "scimitar") != 0) ++bad;
            if (strcmp(
                cavalierPreferredWeaponName(10),
                "javelin") != 0) ++bad;
            if (strcmp(cavalierElvenBowName(),
                "short composite bow") != 0)
                ++bad;
        }
        // U4: the parry and armor reads
        {
            if (cavalierShieldParryBase() != 1)
                ++bad;
            if (cavalierShieldParryMagicBonus(2)
                != 2) ++bad;
            if (cavalierArmorPreference("plate")
                != 0) ++bad;
            if (cavalierArmorPreference(
                "plate mail") != 1) ++bad;
            if (cavalierArmorPreference("banded")
                != 2) ++bad;
            if (cavalierArmorPreference("splint")
                != 2) ++bad;
            if (cavalierArmorPreference("chain")
                != 3) ++bad;
            if (cavalierArmorPreference("scale")
                != 4) ++bad;
            if (cavalierArmorPreference("ring")
                != 5) ++bad;
            if (cavalierArmorPreference("leather")
                != -1) ++bad;
            if (cavalierArmorPreference(
                "studded leather") != -1) ++bad;
            if (!uaStationArmorBan(
                UACLASS_CAVALIER)) ++bad;
        }
        // U5: the mounted and horsemanship
        // reads
        {
            if (cavalierHumanMountedLevelBonus()
                != 1) ++bad;
            if (cavalierSaddlePercent(1) != 85)
                ++bad;
            if (cavalierSaddlePercent(2) != 86)
                ++bad;
            if (cavalierSaddlePercent(10) != 94)
                ++bad;
            if (cavalierHorsemanshipLevel(0)
                != 3) ++bad;
            if (cavalierHorsemanshipLevel(1)
                != 4) ++bad;
            if (cavalierHorsemanshipLevel(2)
                != 5) ++bad;
            if (cavalierHorsemanshipLevel(3)
                != 7) ++bad;
            if (cavalierHorsemanshipLevel(4)
                != 9) ++bad;
            if (cavalierHorsemanshipLevel(5)
                != 11) ++bad;
            if (cavalierSteedHpBonusPerDie()
                != 2) ++bad;
            if (cavalierSteedLowWorthNum()
                != 1) ++bad;
            if (cavalierSteedWorthDen() != 3)
                ++bad;
            if (cavalierSteedHighWorthNum()
                != 2) ++bad;
        }
        // U6: the percentile growth and the
        // training rule
        {
            if (cavalierPercentileGainDice()
                != 2) ++bad;
            if (cavalierPercentileGainSides()
                != 10) ++bad;
            if (cavalierPercentileCap() != 100)
                ++bad;
            if (!cavalierPercentileAbility(
                ABILITY_STR)) ++bad;
            if (!cavalierPercentileAbility(
                ABILITY_DEX)) ++bad;
            if (!cavalierPercentileAbility(
                ABILITY_CON)) ++bad;
            if (cavalierPercentileAbility(
                ABILITY_INT)) ++bad;
            if (cavalierPercentileAbility(
                ABILITY_WIS)) ++bad;
            if (cavalierPercentileAbility(
                ABILITY_CHA)) ++bad;
            if (cavalierTrainerMinLevel() != 4)
                ++bad;
            if (cavalierTrainerLevelGap() != 2)
                ++bad;
            if (cavalierSelfTrainFromLevel()
                != 6) ++bad;
        }
        // U7: the saves and immunities
        {
            if (cavalierMindAffectResistPercent()
                != 90) ++bad;
            if (cavalierMindPowersCount() != 10)
                ++bad;
            if (strcmp(
                cavalierMindPowerName(0),
                "beguiling") != 0) ++bad;
            if (strcmp(
                cavalierMindPowerName(9),
                "psionic mind blast") != 0)
                ++bad;
            if (cavalierIllusionSaveBonus() != 2)
                ++bad;
            if (cavalierNegativeHpWindow(13)
                != 13) ++bad;
            if (cavalierNegativeHpWindow(4)
                != 4) ++bad;
            if (cavalierGoodHealPerWeekMin()
                != 1) ++bad;
            if (cavalierGoodHealPerWeekMax()
                != 4) ++bad;
        }
        // U8: the chivalric code facts
        {
            if (cavalierPennonLevel() != 4)
                ++bad;
            if (cavalierChargeOrderCount() != 8)
                ++bad;
            if (cavalierAlignmentChangeFreeLevel()
                != 4) ++bad;
            if (!cavalierEvilMayUsePoison())
                ++bad;
            if (!cavalierRevocationRetainsWoc())
                ++bad;
        }
        // U9: the Table I clean cells - the
        // XP ladder, the adder, the maxima,
        // the known title cells (the 5, 6,
        // 11 and 12 holes read empty)
        {
            static const int xp[12] = {
                0, 2500, 5000, 10000, 18500,
                37000, 85000, 140000, 220000,
                300000, 600000, 900000
            };
            for (int l = 1; l <= 12; ++l)
                if (cavalierXpToAttain(l)
                    != xp[l - 1]) ++bad;
            if (cavalierXpToAttain(0) != 0)
                ++bad;
            if (cavalierXpPerLevelPast12()
                != 300000) ++bad;
            if (cavalierCommanderLevel() != 13)
                ++bad;
            if (cavalierHpPerLevelPast10() != 3)
                ++bad;
            if (strcmp(cavalierTitleKnown(1),
                "Armiger") != 0) ++bad;
            if (strcmp(cavalierTitleKnown(2),
                "Scutifer") != 0) ++bad;
            if (strcmp(cavalierTitleKnown(3),
                "Esquire") != 0) ++bad;
            if (strcmp(cavalierTitleKnown(4),
                "Knight Errant") != 0) ++bad;
            if (strcmp(cavalierTitleKnown(7),
                "Grand Knight") != 0) ++bad;
            if (strcmp(cavalierTitleKnown(8),
                "Banneret") != 0) ++bad;
            if (strcmp(cavalierTitleKnown(9),
                "Chevalier") != 0) ++bad;
            if (strcmp(cavalierTitleKnown(10),
                "Cavalier") != 0) ++bad;
            if (strcmp(cavalierTitleKnown(13),
                "Cavalier Commander") != 0)
                ++bad;
            if (cavalierTitleKnown(5)[0]
                != 0) ++bad;
            if (cavalierTitleKnown(6)[0]
                != 0) ++bad;
            if (cavalierTitleKnown(11)[0]
                != 0) ++bad;
            if (cavalierTitleKnown(12)[0]
                != 0) ++bad;
        }
        printf("R328 cavalier pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
