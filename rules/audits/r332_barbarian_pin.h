    // ---- R332: the barbarian pin audit ----
    // The UA barbarian (pp. 18-21) - the pin-era pattern: the
    // requirements, the AC/CON reads, Barbarians Table I, the
    // magic detestation, the natural attack progression, the
    // saves, the primary/secondary/tertiary ability ladders
    // (the running-leap formula and the award tail are OCR
    // holes - documented in the header). The R327 hit-die seam
    // and the R331 spec-gate seam cross-checked.
    {
        using namespace rules;
        int bad = 0;
        // U1: the requirements
        {
            if (barbarianMinAbility(
                ABILITY_STR) != 15) ++bad;
            if (barbarianMinAbility(
                ABILITY_CON) != 15) ++bad;
            if (barbarianMinAbility(
                ABILITY_DEX) != 14) ++bad;
            if (barbarianMinAbility(
                ABILITY_INT) != 0) ++bad;
            if (barbarianMaxWisdom() != 16)
                ++bad;
            if (!barbarianNoPrimeRequisite())
                ++bad;
            if (!barbarianDualClassBanned())
                ++bad;
            if (!barbarianHumanOnly()) ++bad;
        }
        // U2: the AC and CON reads
        {
            if (barbarianAcBonusPerDexPoint()
                != 2) ++bad;
            if (barbarianAcStepSize() != 1)
                ++bad;
            if (barbarianAcBulkyBonusPerPoint()
                != 1) ++bad;
            if (barbarianConHpBonusPerPoint()
                != 2) ++bad;
        }
        // U3: the combat reads
        {
            if (barbarianHitDice() != 12)
                ++bad;
            if (barbarianMoveRate() != 15)
                ++bad;
            if (barbarianRequiredWeaponCount()
                != 3) ++bad;
            if (strcmp(
                barbarianRequiredWeaponName(0),
                "Hand Axe") != 0) ++bad;
            if (strcmp(
                barbarianRequiredWeaponName(1),
                "Knife") != 0) ++bad;
            if (strcmp(
                barbarianRequiredWeaponName(2),
                "Spear") != 0) ++bad;
        }
        // U4: Barbarians Table I
        {
            static const int xp[11] = {
                0, 6000, 12000, 24000, 48000,
                80000, 150000, 275000, 500000,
                1000000, 1500000
            };
            for (int L = 1; L <= 11; ++L)
                if (barbarianXpToAttain(L)
                    != xp[L - 1]) ++bad;
            if (barbarianXpPerLevelPast11()
                != 500000) ++bad;
            if (barbarianHpPerLevelPast8()
                != 4) ++bad;
            // the R176 convention: the row
            // reads attained at its floor
            if (barbarianXpToAttain(0) != 0)
                ++bad;
            if (barbarianXpToAttain(12)
                != 1500000) ++bad;
        }
        // U5: the magic detestation
        {
            if (!barbarianDetestsMagic()) ++bad;
            if (!barbarianRefusesMagicItems())
                ++bad;
            if (!barbarianXpAwardForDestroying())
                ++bad;
            if (!barbarianShamanException())
                ++bad;
        }
        // U6: the natural attack progression
        {
            static const int lvl[5] = {
                4, 6, 8, 10, 12
            };
            for (int p = 1; p <= 5; ++p) {
                if (barbarianStrikeLevel(p)
                    != lvl[p - 1]) ++bad;
                if (barbarianStrikePlus(
                    lvl[p - 1]) != p) ++bad;
            }
            if (barbarianStrikePlus(3) != 0)
                ++bad;
            if (!barbarianStrikeGivesNoBonus())
                ++bad;
        }
        // U7: the saves
        {
            if (barbarianSaveBonusPoison()
                != 4) ++bad;
            if (barbarianSaveBonusParalysis()
                != 3) ++bad;
            if (barbarianSaveBonusRodWandBreath()
                != 2) ++bad;
            if (barbarianSpellSavePerLevels()
                != 4) ++bad;
            if (barbarianSpellSaveBonusPerStep()
                != 1) ++bad;
        }
        // U8: the primary abilities
        {
            if (barbarianClimbAsThiefLevel(5)
                != 5) ++bad;
            if (barbarianHideBonusLevels()
                != 3) ++bad;
            if (barbarianSurpriseFamiliar()
                != 4) ++bad;
            if (barbarianSurpriseUnfamiliar()
                != 3) ++bad;
            if (barbarianSurprisedFamiliar()
                != 5) ++bad;
            if (barbarianSurprisedUnfamiliar()
                != 10) ++bad;
            if (barbarianBackProtectPercent(1)
                != 5) ++bad;
            if (barbarianBackProtectPercent(2)
                != 10) ++bad;
            if (barbarianLeapStandingForward()
                != 10) ++bad;
            if (barbarianLeapStandingBackward()
                != 3) ++bad;
            if (barbarianLeapStandingUpward()
                != 3) ++bad;
            if (barbarianLeapRunningLow()
                != 16) ++bad;
            if (barbarianLeapRunningHigh()
                != 21) ++bad;
            if (barbarianSpringUpwardLow()
                != 4) ++bad;
            if (barbarianSpringUpwardHigh()
                != 7) ++bad;
            if (barbarianDetectIllusionPercent(
                3) != 15) ++bad;
            if (barbarianDetectIllusionPercent(
                20) != 75) ++bad;
            if (barbarianDetectIllusionCap()
                != 75) ++bad;
            if (barbarianDetectMagicBase()
                != 25) ++bad;
            if (barbarianDetectMagicPerLevel()
                != 5) ++bad;
            if (barbarianDetectMagicCap()
                != 90) ++bad;
            if (barbarianDetectRounds() != 1)
                ++bad;
            if (!barbarianLeadershipOnBarbarians())
                ++bad;
        }
        // U9: the secondary abilities
        {
            if (barbarianLocaleAdaptWeeks()
                != 4) ++bad;
            if (barbarianFirstAidHp() != 1)
                ++bad;
            if (barbarianFirstAidRestPerDay()
                != 2) ++bad;
            if (barbarianFirstAidActivePerDay()
                != 1) ++bad;
            if (barbarianFirstAidOtherHp()
                != 1) ++bad;
            if (barbarianFirstAidCurePercent()
                != 10) ++bad;
            if (barbarianFirstAidCureKnownBase()
                != 50) ++bad;
            if (barbarianFirstAidCureKnownCon()
                != 1) ++bad;
            if (barbarianOutdoorCraftDruidLevel()
                != 3) ++bad;
            if (!barbarianTracksAsRanger())
                ++bad;
        }
        // U10: the tertiary skills
        {
            if (barbarianTertiaryCount() != 7)
                ++bad;
            if (strcmp(
                barbarianTertiaryName(0),
                "Animal Handling") != 0) ++bad;
            if (strcmp(
                barbarianTertiaryName(2),
                "Long-Distance Signaling") != 0)
                ++bad;
            if (strcmp(
                barbarianTertiaryName(4),
                "Small Craft (Paddled and"
                " Rowed)") != 0) ++bad;
            if (strcmp(
                barbarianTertiaryName(6),
                "Snare Building") != 0) ++bad;
        }
        // U11: the R327 and R331 seams
        {
            if (uaClassHitDie(
                UACLASS_BARBARIAN) != 12) ++bad;
            if (weaponSpecClassAllowed(
                UACLASS_BARBARIAN)) ++bad;
        }
        printf("R332 barbarian pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
