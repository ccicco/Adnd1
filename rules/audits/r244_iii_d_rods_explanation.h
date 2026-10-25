    // ---- R244: the III.D rods explanation prose pins audit ----
    // DMG pp.141-142: the section conventions
    // and the seven rods of the RODS, et al.
    // explanation prose.
    {
        int bad = 0;
        // the charges conventions: rods 50 minus
        // 0-9, staves 25 minus 0-5, wands 100
        // minus 0-19
        if (rules::rpRodChargesMax() != 50 ||
            rules::rpRodChargesDieLo() != 0 ||
            rules::rpRodChargesDieHi() != 9) ++bad;
        if (rules::rpStaffChargesMax() != 25 ||
            rules::rpStaffChargesDieLo() != 0 ||
            rules::rpStaffChargesDieHi() != 5) ++bad;
        if (rules::rpWandChargesMax() != 100 ||
            rules::rpWandChargesDieLo() != 0 ||
            rules::rpWandChargesDieHi() != 19) ++bad;
        // the drained-crumble, command-word and
        // silence conventions
        if (rules::rpDrainedCrumble() != 1 ||
            rules::rpCommandWordRule() != 1 ||
            rules::rpSilenceBlocks() != 1) ++bad;
        // the seven rods are the first seven rows
        // of the engine III.D table - bands 01-19,
        // the staff rows from 20 (the R224 pins)
        if (rules::rpRodCount() != 7 ||
            rules::rswRowLo(0) != 1 ||
            rules::rswRowHi(6) != 19 ||
            rules::rswRowLo(7) != 20) ++bad;
        // Rod of Absorption
        if (rules::rpAbsorbMaxSpellLevels() != 50 ||
            rules::rpAbsorbCastSegments() != 1 ||
            rules::rpAbsorbRechargeable() != 0) ++bad;
        // Rod of Beguiling
        if (rules::rpBeguileRadiusInches() != 2 ||
            rules::rpBeguileMinIntelligence() != 1 ||
            rules::rpBeguileHasSave() != 0 ||
            rules::rpBeguileTurnsPerCharge() != 1 ||
            rules::rpBeguileRechargeable() != 1) ++bad;
        // Rod of Cancellation - the 11-row item
        // saving throw table
        static const int kCanc[11] = {
            20, 19, 17, 14, 13, 15, 12, 3, 11, 9, 10,
        };
        if (rules::rpCancSaveCount() != 11) ++bad;
        for (int i = 0; i < 11; ++i)
            if (rules::rpCancSaveValue(i) != kCanc[i]) ++bad;
        // the +5 armor/shield and holy sword variants
        if (rules::rpCancArmorShieldPlus5() != 8 ||
            rules::rpCancHolySword() != 7) ++bad;
        // drained items are not restorable, and the
        // rod turns brittle
        if (rules::rpCancDrainedRestorable() != 0 ||
            rules::rpCancRodBecomesBrittle() != 1) ++bad;
        // clamped reads land on the potion row below
        // and the misc weapon row above
        if (rules::rpCancSaveValue(-9) != 20 ||
            rules::rpCancSaveValue(99) != 10) ++bad;
        // Rod of Lordly Might
        if (rules::rpLmWeightPounds() != 10 ||
            rules::rpLmMinStrength() != 16 ||
            rules::rpLmStrBelowPenalty() != 1 ||
            rules::rpLmSpellLikeCount() != 3 ||
            rules::rpLmSpellCostCharges() != 1 ||
            rules::rpLmFearRangeInches() != 6 ||
            rules::rpLmDrainHpLo() != 2 ||
            rules::rpLmDrainHpHi() != 8) ++bad;
        // the four weapon forms: +2 mace, +1 flame
        // sword, +4 battle axe, +3 spear
        static const int kLmBonus[4] = {
            2, 1, 4, 3,
        };
        if (rules::rpLmWeaponFormCount() != 4) ++bad;
        for (int i = 0; i < 4; ++i)
            if (rules::rpLmWeaponBonus(i) != kLmBonus[i]) ++bad;
        // the spear lengths and the mundane uses
        if (rules::rpLmSpearLenMinFeet() != 6 ||
            rules::rpLmSpearLenMaxFeet() != 15 ||
            rules::rpLmSpearHandleMaxFeet() != 12 ||
            rules::rpLmMundaneUseCount() != 3 ||
            rules::rpLmPoleGrowthPerSegment() != 5 ||
            rules::rpLmPoleMaxFeet() != 50 ||
            rules::rpLmPoleBearPounds() != 4000 ||
            rules::rpLmDoorForceMaxFeet() != 30) ++bad;
        // weapon functions 2 and 3 die with the
        // charges, and the rod never recharges
        if (rules::rpLmExhaustedWeaponCeaseLo() != 2 ||
            rules::rpLmExhaustedWeaponCeaseHi() != 3 ||
            rules::rpLmRechargeable() != 0) ++bad;
        // clamped bonus reads land on the mace below
        // and the spear above
        if (rules::rpLmWeaponBonus(-9) != 2 ||
            rules::rpLmWeaponBonus(99) != 3) ++bad;
        // Rod of Resurrection - the charge table by
        // class (11) and race (7)
        static const int kResClass[11] = {
            1, 2, 2, 1, 2, 3, 3, 3, 4, 3, 2,
        };
        static const int kResRace[7] = {
            3, 4, 3, 2, 2, 4, 1,
        };
        if (rules::rpResUsesPerDay() != 1 ||
            rules::rpResClassCount() != 11 ||
            rules::rpResRaceCount() != 7) ++bad;
        for (int i = 0; i < 11; ++i)
            if (rules::rpResClassCharges(i) != kResClass[i]) ++bad;
        for (int i = 0; i < 7; ++i)
            if (rules::rpResRaceCharges(i) != kResRace[i]) ++bad;
        // multi-classed takes the least favorable
        if (rules::rpResMultiLeastFavorable() != 1 ||
            rules::rpResRechargeable() != 0) ++bad;
        // clamped reads land on the cleric below and
        // the bard above, the dwarf below and the
        // human above
        if (rules::rpResClassCharges(-9) != 1 ||
            rules::rpResClassCharges(99) != 2 ||
            rules::rpResRaceCharges(-9) != 3 ||
            rules::rpResRaceCharges(99) != 1) ++bad;
        // Rod of Rulership
        if (rules::rpRuleRadiusInches() != 12 ||
            rules::rpRuleHdLo() != 200 ||
            rules::rpRuleHdHi() != 500 ||
            rules::rpRuleSaveIntMin() != 15 ||
            rules::rpRuleSaveHdMin() != 12 ||
            rules::rpRuleActivateSegments() != 5 ||
            rules::rpRuleTurnsPerCharge() != 1 ||
            rules::rpRuleRechargeable() != 0) ++bad;
        // Rod of Smiting
        if (rules::rpSmiteBonus() != 3 ||
            rules::rpSmiteDamageLo() != 4 ||
            rules::rpSmiteDamageHi() != 11 ||
            rules::rpSmiteGolemDamageLo() != 8 ||
            rules::rpSmiteGolemDamageHi() != 22 ||
            rules::rpSmiteGolemDestroyRoll() != 20 ||
            rules::rpSmiteGolemHitChargeDrain() != 1 ||
            rules::rpSmiteOuterTripleRoll() != 20 ||
            rules::rpSmiteOuterChargeDrain() != 1 ||
            rules::rpSmiteOuterDamageMultiple() != 3 ||
            rules::rpSmiteRechargeable() != 0) ++bad;
        printf("R244 rods prose pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
