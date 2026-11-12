    // ---- R244: the III.D rods explanation prose pins audit ----
    // DMG pp.141-142: the section conventions
    // and the seven rods of the RODS, et al.
    // explanation prose.
    {
        Rods_absorption_to_smiting rods_absorption_to_smiting;
        Rodswands rodswands;
        int bad = 0;
        // the charges conventions: rods 50 minus
        // 0-9, staves 25 minus 0-5, wands 100
        // minus 0-19
        if (rods_absorption_to_smiting.rpRodChargesMax() != 50 ||
            rods_absorption_to_smiting.rpRodChargesDieLo() != 0 ||
            rods_absorption_to_smiting.rpRodChargesDieHi() != 9) ++bad;
        if (rods_absorption_to_smiting.rpStaffChargesMax() != 25 ||
            rods_absorption_to_smiting.rpStaffChargesDieLo() != 0 ||
            rods_absorption_to_smiting.rpStaffChargesDieHi() != 5) ++bad;
        if (rods_absorption_to_smiting.rpWandChargesMax() != 100 ||
            rods_absorption_to_smiting.rpWandChargesDieLo() != 0 ||
            rods_absorption_to_smiting.rpWandChargesDieHi() != 19) ++bad;
        // the drained-crumble, command-word and
        // silence conventions
        if (rods_absorption_to_smiting.rpDrainedCrumble() != 1 ||
            rods_absorption_to_smiting.rpCommandWordRule() != 1 ||
            rods_absorption_to_smiting.rpSilenceBlocks() != 1) ++bad;
        // the seven rods are the first seven rows
        // of the engine III.D table - bands 01-19,
        // the staff rows from 20 (the R224 pins)
        if (rods_absorption_to_smiting.rpRodCount() != 7 ||
            rodswands.rswRowLo(0) != 1 ||
            rodswands.rswRowHi(6) != 19 ||
            rodswands.rswRowLo(7) != 20) ++bad;
        // Rod of Absorption
        if (rods_absorption_to_smiting.rpAbsorbMaxSpellLevels() != 50 ||
            rods_absorption_to_smiting.rpAbsorbCastSegments() != 1 ||
            rods_absorption_to_smiting.rpAbsorbRechargeable() != 0) ++bad;
        // Rod of Beguiling
        if (rods_absorption_to_smiting.rpBeguileRadiusInches() != 2 ||
            rods_absorption_to_smiting.rpBeguileMinIntelligence() != 1 ||
            rods_absorption_to_smiting.rpBeguileHasSave() != 0 ||
            rods_absorption_to_smiting.rpBeguileTurnsPerCharge() != 1 ||
            rods_absorption_to_smiting.rpBeguileRechargeable() != 1) ++bad;
        // Rod of Cancellation - the 11-row item
        // saving throw table
        static const int kCanc[11] = {
            20, 19, 17, 14, 13, 15, 12, 3, 11, 9, 10,
        };
        if (rods_absorption_to_smiting.rpCancSaveCount() != 11) ++bad;
        for (int i = 0; i < 11; ++i)
            if (rods_absorption_to_smiting.rpCancSaveValue(i) != kCanc[i]) ++bad;
        // the +5 armor/shield and holy sword variants
        if (rods_absorption_to_smiting.rpCancArmorShieldPlus5() != 8 ||
            rods_absorption_to_smiting.rpCancHolySword() != 7) ++bad;
        // drained items are not restorable, and the
        // rod turns brittle
        if (rods_absorption_to_smiting.rpCancDrainedRestorable() != 0 ||
            rods_absorption_to_smiting.rpCancRodBecomesBrittle() != 1) ++bad;
        // clamped reads land on the potion row below
        // and the misc weapon row above
        if (rods_absorption_to_smiting.rpCancSaveValue(-9) != 20 ||
            rods_absorption_to_smiting.rpCancSaveValue(99) != 10) ++bad;
        // Rod of Lordly Might
        if (rods_absorption_to_smiting.rpLmWeightPounds() != 10 ||
            rods_absorption_to_smiting.rpLmMinStrength() != 16 ||
            rods_absorption_to_smiting.rpLmStrBelowPenalty() != 1 ||
            rods_absorption_to_smiting.rpLmSpellLikeCount() != 3 ||
            rods_absorption_to_smiting.rpLmSpellCostCharges() != 1 ||
            rods_absorption_to_smiting.rpLmFearRangeInches() != 6 ||
            rods_absorption_to_smiting.rpLmDrainHpLo() != 2 ||
            rods_absorption_to_smiting.rpLmDrainHpHi() != 8) ++bad;
        // the four weapon forms: +2 mace, +1 flame
        // sword, +4 battle axe, +3 spear
        static const int kLmBonus[4] = {
            2, 1, 4, 3,
        };
        if (rods_absorption_to_smiting.rpLmWeaponFormCount() != 4) ++bad;
        for (int i = 0; i < 4; ++i)
            if (rods_absorption_to_smiting.rpLmWeaponBonus(i) != kLmBonus[i]) ++bad;
        // the spear lengths and the mundane uses
        if (rods_absorption_to_smiting.rpLmSpearLenMinFeet() != 6 ||
            rods_absorption_to_smiting.rpLmSpearLenMaxFeet() != 15 ||
            rods_absorption_to_smiting.rpLmSpearHandleMaxFeet() != 12 ||
            rods_absorption_to_smiting.rpLmMundaneUseCount() != 3 ||
            rods_absorption_to_smiting.rpLmPoleGrowthPerSegment() != 5 ||
            rods_absorption_to_smiting.rpLmPoleMaxFeet() != 50 ||
            rods_absorption_to_smiting.rpLmPoleBearPounds() != 4000 ||
            rods_absorption_to_smiting.rpLmDoorForceMaxFeet() != 30) ++bad;
        // weapon functions 2 and 3 die with the
        // charges, and the rod never recharges
        if (rods_absorption_to_smiting.rpLmExhaustedWeaponCeaseLo() != 2 ||
            rods_absorption_to_smiting.rpLmExhaustedWeaponCeaseHi() != 3 ||
            rods_absorption_to_smiting.rpLmRechargeable() != 0) ++bad;
        // clamped bonus reads land on the mace below
        // and the spear above
        if (rods_absorption_to_smiting.rpLmWeaponBonus(-9) != 2 ||
            rods_absorption_to_smiting.rpLmWeaponBonus(99) != 3) ++bad;
        // Rod of Resurrection - the charge table by
        // class (11) and race (7)
        static const int kResClass[11] = {
            1, 2, 2, 1, 2, 3, 3, 3, 4, 3, 2,
        };
        static const int kResRace[7] = {
            3, 4, 3, 2, 2, 4, 1,
        };
        if (rods_absorption_to_smiting.rpResUsesPerDay() != 1 ||
            rods_absorption_to_smiting.rpResClassCount() != 11 ||
            rods_absorption_to_smiting.rpResRaceCount() != 7) ++bad;
        for (int i = 0; i < 11; ++i)
            if (rods_absorption_to_smiting.rpResClassCharges(i) != kResClass[i]) ++bad;
        for (int i = 0; i < 7; ++i)
            if (rods_absorption_to_smiting.rpResRaceCharges(i) != kResRace[i]) ++bad;
        // multi-classed takes the least favorable
        if (rods_absorption_to_smiting.rpResMultiLeastFavorable() != 1 ||
            rods_absorption_to_smiting.rpResRechargeable() != 0) ++bad;
        // clamped reads land on the cleric below and
        // the bard above, the dwarf below and the
        // human above
        if (rods_absorption_to_smiting.rpResClassCharges(-9) != 1 ||
            rods_absorption_to_smiting.rpResClassCharges(99) != 2 ||
            rods_absorption_to_smiting.rpResRaceCharges(-9) != 3 ||
            rods_absorption_to_smiting.rpResRaceCharges(99) != 1) ++bad;
        // Rod of Rulership
        if (rods_absorption_to_smiting.rpRuleRadiusInches() != 12 ||
            rods_absorption_to_smiting.rpRuleHdLo() != 200 ||
            rods_absorption_to_smiting.rpRuleHdHi() != 500 ||
            rods_absorption_to_smiting.rpRuleSaveIntMin() != 15 ||
            rods_absorption_to_smiting.rpRuleSaveHdMin() != 12 ||
            rods_absorption_to_smiting.rpRuleActivateSegments() != 5 ||
            rods_absorption_to_smiting.rpRuleTurnsPerCharge() != 1 ||
            rods_absorption_to_smiting.rpRuleRechargeable() != 0) ++bad;
        // Rod of Smiting
        if (rods_absorption_to_smiting.rpSmiteBonus() != 3 ||
            rods_absorption_to_smiting.rpSmiteDamageLo() != 4 ||
            rods_absorption_to_smiting.rpSmiteDamageHi() != 11 ||
            rods_absorption_to_smiting.rpSmiteGolemDamageLo() != 8 ||
            rods_absorption_to_smiting.rpSmiteGolemDamageHi() != 22 ||
            rods_absorption_to_smiting.rpSmiteGolemDestroyRoll() != 20 ||
            rods_absorption_to_smiting.rpSmiteGolemHitChargeDrain() != 1 ||
            rods_absorption_to_smiting.rpSmiteOuterTripleRoll() != 20 ||
            rods_absorption_to_smiting.rpSmiteOuterChargeDrain() != 1 ||
            rods_absorption_to_smiting.rpSmiteOuterDamageMultiple() != 3 ||
            rods_absorption_to_smiting.rpSmiteRechargeable() != 0) ++bad;
        printf("R244 rods prose pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
