    // ---- R331: the weapon specialization
    // prose pin audit ----
    // The UA weapon specialization (pp.
    // 18-19) - the pin-era pattern: the
    // class gate, the slot costs, the
    // melee benefits, the bow and
    // crossbow point blanks, the other
    // missiles, the double
    // specialization, the final note, the
    // table structure with the cleanly
    // readable cells (the mangled cells
    // read empty - the item stays open
    // pending the PDF). The R328
    // exclusion seam cross-checked.
    {
        using namespace rules;
        int bad = 0;
        // U1: the class gate
        {
            if (!weaponSpecClassAllowed(
                UACLASS_FIGHTER)) ++bad;
            if (!weaponSpecClassAllowed(
                UACLASS_RANGER)) ++bad;
            if (weaponSpecClassAllowed(
                UACLASS_CAVALIER)) ++bad;
            if (weaponSpecClassAllowed(
                UACLASS_PALADIN)) ++bad;
            if (weaponSpecClassAllowed(
                UACLASS_BARBARIAN)) ++bad;
            if (weaponSpecClassAllowed(
                UACLASS_THIEF)) ++bad;
            if (!weaponSpecAtCreationOnly())
                ++bad;
        }
        // U2: the slot costs
        {
            if (weaponSpecSlots() != 2) ++bad;
            if (
                weaponSpecFighterOtherProficiencies()
                != 2) ++bad;
            if (weaponSpecRangerProficiencies()
                != 1) ++bad;
            if (weaponSpecBowExtraSlot() != 1)
                ++bad;
            if (weaponSpecFighterBowOthers()
                != 1) ++bad;
            if (weaponSpecRangerBowOthers()
                != 0) ++bad;
            // the fighter budget: 2 spec
            // slots + 2 others = the
            // printed four
            if (weaponSpecSlots()
                + weaponSpecFighterOtherProficiencies()
                != 4) ++bad;
        }
        // U3: the melee benefits
        {
            if (weaponSpecMeleeToHitBonus()
                != 1) ++bad;
            if (weaponSpecMeleeDamageBonus()
                != 2) ++bad;
            if (!weaponSpecSpecificTypeRequired())
                ++bad;
            if (!weaponSpecExtraAttacks())
                ++bad;
        }
        // U4: the bow point blank
        {
            if (weaponSpecBowPointBlankMin()
                != 6) ++bad;
            if (weaponSpecBowPointBlankMax()
                != 30) ++bad;
            if (weaponSpecBowPointBlankBonus()
                != 2) ++bad;
            if (!weaponSpecBowDoubleDamage())
                ++bad;
            if (weaponSpecArrowDamageLow() != 6)
                ++bad;
            if (weaponSpecArrowDamageHigh()
                != 16) ++bad;
            if (!weaponSpecNockedArrowPreInitiative())
                ++bad;
            if (weaponSpecBowShortRangeFrom()
                != 30) ++bad;
            if (weaponSpecBowShortRangeBonus()
                != 1) ++bad;
        }
        // U5: the crossbow point blank
        // (the medium read rides the
        // fragment-verified +1 hit, no
        // damage bonus)
        {
            if (weaponSpecCrossbowPointBlankMin()
                != 6) ++bad;
            if (weaponSpecCrossbowPointBlankMax()
                != 60) ++bad;
            if (
                weaponSpecCrossbowPointBlankBonus()
                != 2) ++bad;
            if (!weaponSpecCrossbowDoubleDamage())
                ++bad;
            if (weaponSpecLightBoltDamageLow()
                != 6) ++bad;
            if (weaponSpecLightBoltDamageHigh()
                != 12) ++bad;
            if (weaponSpecCrossbowShortBonus()
                != 1) ++bad;
            if (
                weaponSpecCrossbowMediumHitBonus()
                != 1) ++bad;
            if (
                weaponSpecCrossbowMediumDamageBonus()
                != 0) ++bad;
            if (!weaponSpecCrossbowFreeShot())
                ++bad;
        }
        // U6: the other missiles and the
        // double specialization
        {
            if (weaponSpecOtherMissileToHitBonus()
                != 1) ++bad;
            if (weaponSpecOtherMissileDamageBonus()
                != 2) ++bad;
            if (!weaponSpecDoubleAllowed())
                ++bad;
            if (!weaponSpecDoubleMeleeOnly())
                ++bad;
            if (weaponSpecDoubleToHitBonus()
                != 3) ++bad;
            if (weaponSpecDoubleDamageBonus()
                != 3) ++bad;
        }
        // U7: the final note
        {
            if (!weaponSpecBonusesNotMagical())
                ++bad;
            if (!weaponSpecMagicStacks()) ++bad;
        }
        // U8: the table structure - the
        // columns, the bands, all 24
        // cells read (the R393 clean
        // read; the superseding note
        // pins)
        {
            if (weaponSpecTableColumnCount()
                != 8) ++bad;
            if (strcmp(weaponSpecTableColumnName(0),
                "Melee Weapon") != 0) ++bad;
            if (strcmp(weaponSpecTableColumnName(4),
                "Lasso and Staff Sling") != 0)
                ++bad;
            if (strcmp(weaponSpecTableColumnName(7),
                "Other Missiles and Hurled"
                " Weapons") != 0) ++bad;
            static const int lo[3] = {1, 7, 13};
            static const int hi[3] = {6, 12, 0};
            for (int b = 0; b < 3; ++b) {
                if (weaponSpecTableBandLow(b)
                    != lo[b]) ++bad;
                if (weaponSpecTableBandHigh(b)
                    != hi[b]) ++bad;
            }
            if (strcmp(
                weaponSpecTableCellKnown(0, 0),
                "3/2") != 0) ++bad;
            if (strcmp(
                weaponSpecTableCellKnown(0, 7),
                "3/2") != 0) ++bad;
            if (strcmp(
                weaponSpecTableCellKnown(1, 2),
                "3/2") != 0) ++bad;
            if (strcmp(
                weaponSpecTableCellKnown(1, 4),
                "3/2") != 0) ++bad;
            if (strcmp(
                weaponSpecTableCellKnown(2, 0),
                "5/2") != 0) ++bad;
            if (strcmp(
                weaponSpecTableCellKnown(2, 7),
                "5/2") != 0) ++bad;
            // the R393 clean read fills
            // the lost cells
            if (strcmp(weaponSpecTableCellKnown(
                0, 1), "2/1") != 0) ++bad;
            if (strcmp(weaponSpecTableCellKnown(
                0, 2), "1/1") != 0) ++bad;
            if (strcmp(weaponSpecTableCellKnown(
                0, 3), "1/2") != 0) ++bad;
            if (strcmp(weaponSpecTableCellKnown(
                1, 5), "4/1") != 0) ++bad;
            if (strcmp(weaponSpecTableCellKnown(
                2, 3), "3/2") != 0) ++bad;
        }
        // U9: the R328 exclusion seam
        {
            if (!cavalierSpecializationBanned())
                ++bad;
            if (weaponSpecClassAllowed(
                UACLASS_CAVALIER)) ++bad;
        }
        printf("R331 weapon spec prose pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
