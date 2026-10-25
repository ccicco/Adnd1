    // ---- R393: the PDF-read completion sweep
    // pin audit ----
    // The clean PDF read fills the three
    // fragment-round holes; the amended
    // R331/R334/R365 blocks cross-check
    // here at the seams.
    {
        using namespace rules;
        int bad = 0;
        // U1: the spec-table corners
        {
            if (strcmp(
                weaponSpecTableCellKnown(0, 3),
                "1/2") != 0) ++bad;
            if (strcmp(
                weaponSpecTableCellKnown(1, 6),
                "5/1") != 0) ++bad;
            if (strcmp(
                weaponSpecTableCellKnown(2, 4),
                "2/1") != 0) ++bad;
            if (!weaponSpecTableSupersedes())
                ++bad;
        }
        // U2: the seam - the lasso/staff
        // sling 13+ cell equals the
        // attacks band-2 rate
        {
            if (strcmp(
                weaponSpecTableCellKnown(2, 4),
                "2/1") != 0) ++bad;
            if (uaAttacksBandAttacks(2) != 2)
                ++bad;
            if (uaAttacksBandRounds(2) != 1)
                ++bad;
        }
        // U3: the thief fills
        {
            if (thiefArmorCellIsHole(1, 0))
                ++bad;
            if (thiefArmorCellIsHole(1, 1))
                ++bad;
            if (thiefArmorCellIsHole(2, 0))
                ++bad;
            if (thiefArmorCellIsHole(5, 0))
                ++bad;
            if (thiefArmorModifierKnown(1, 0)
                != 0) ++bad;
            if (thiefArmorModifierKnown(1, 1)
                != -5) ++bad;
            if (thiefArmorModifierKnown(1, 2)
                != -10) ++bad;
            if (!thiefArmorFootnoteOnePrintsInFull())
                ++bad;
            if (!thiefArmorNoArmorLargeDevicesBarred())
                ++bad;
            if (!thiefArmorFootnoteFourOrphaned())
                ++bad;
        }
        // U4: the IL column-wise decode
        {
            if (uailaOffensiveRowCount() != 6)
                ++bad;
            if (uailaDefensiveRowCount() != 6)
                ++bad;
            if (uailaMiscRowCount() != 6) ++bad;
            if (!uailaOffRow6Spook()) ++bad;
            if (!uailaDefRow2Darkness()) ++bad;
            if (!uailaDefRow5PhantomArmor())
                ++bad;
            if (!uailaChromaticOrbPrintsPlain())
                ++bad;
            if (!uailaMiscRow6IsChooseAsterisk())
                ++bad;
            if (!uailaColumnsDecodeColumnWise())
                ++bad;
        }
        printf("R393 PDF-read completion pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
