    // ---- R334: the thief armor and attacks pin audit ----
    // The UA Thieves Table II (p. 22) - the pin-era pattern:
    // the armor categories, the function rows, the
    // fragment-verified cells (the sign carries the no-armor
    // column), the footnotes; the paired Attacks Per Melee
    // Round Table - the five classes, the band edges, the
    // verified rates. The Open Locks cells, the missing
    // no-armor cells, the attacks high-band rate and the
    // footnote-1 tail are OCR holes - the item stays open
    // pending the PDF. The R181/R331 seams cross-checked.
    {
        using namespace rules;
        int bad = 0;
        // U1: the categories and the functions
        {
            if (thiefArmorCategoryCount() != 3)
                ++bad;
            if (strcmp(thiefArmorCategoryName(0),
                "No Armor") != 0) ++bad;
            if (strcmp(thiefArmorCategoryName(1),
                "Elfin Chain") != 0) ++bad;
            if (strcmp(thiefArmorCategoryName(2),
                "Studded or Padded") != 0)
                ++bad;
            if (thiefArmorFunctionCount() != 8)
                ++bad;
            if (strcmp(thiefArmorFunctionName(0),
                "Pick Pockets") != 0) ++bad;
            if (strcmp(thiefArmorFunctionName(3),
                "Move Silently") != 0) ++bad;
            if (strcmp(thiefArmorFunctionName(7),
                "Read Languages") != 0) ++bad;
        }
        // U2: the verified cells
        {
            // Pick Pockets: +5 / -20 / -30
            if (thiefArmorCellIsHole(0, 0)) ++bad;
            if (thiefArmorModifierKnown(0, 0)
                != 5) ++bad;
            if (thiefArmorModifierKnown(0, 1)
                != -20) ++bad;
            if (thiefArmorModifierKnown(0, 2)
                != -30) ++bad;
            // Find/Remove Traps: -5 / -10
            if (thiefArmorModifierKnown(2, 1)
                != -5) ++bad;
            if (thiefArmorModifierKnown(2, 2)
                != -10) ++bad;
            // Move Silently: +10 / -10 / -20
            if (thiefArmorModifierKnown(3, 0)
                != 10) ++bad;
            if (thiefArmorModifierKnown(3, 1)
                != -10) ++bad;
            if (thiefArmorModifierKnown(3, 2)
                != -20) ++bad;
            // Hide in Shadows: +5 / -10 / -20
            if (thiefArmorModifierKnown(4, 0)
                != 5) ++bad;
            if (thiefArmorModifierKnown(4, 1)
                != -10) ++bad;
            if (thiefArmorModifierKnown(4, 2)
                != -20) ++bad;
            // Hear Noise: -5 / -10
            if (thiefArmorModifierKnown(5, 1)
                != -5) ++bad;
            if (thiefArmorModifierKnown(5, 2)
                != -10) ++bad;
            // Climb Walls: +10 / -20 / -30
            if (thiefArmorModifierKnown(6, 0)
                != 10) ++bad;
            if (thiefArmorModifierKnown(6, 1)
                != -20) ++bad;
            if (thiefArmorModifierKnown(6, 2)
                != -30) ++bad;
            // Read Languages: the dashes
            // read as 0
            if (thiefArmorModifierKnown(7, 0)
                != 0) ++bad;
            if (thiefArmorModifierKnown(7, 2)
                != 0) ++bad;
        }
        // U3: the R393 clean read -
        // every hole fills
        {
            if (thiefArmorCellIsHole(1, 0))
                ++bad;
            if (thiefArmorCellIsHole(1, 1))
                ++bad;
            if (thiefArmorCellIsHole(1, 2))
                ++bad;
            if (thiefArmorCellIsHole(2, 0))
                ++bad;
            if (thiefArmorCellIsHole(5, 0))
                ++bad;
            if (thiefArmorCellIsHole(0, 0)) ++bad;
            if (thiefArmorCellIsHole(4, 1)) ++bad;
            // Open Locks reads 0/-5/-10;
            // the no-armor dashes read 0
            if (thiefArmorModifierKnown(1, 0)
                != 0) ++bad;
            if (thiefArmorModifierKnown(1, 1)
                != -5) ++bad;
            if (thiefArmorModifierKnown(1, 2)
                != -10) ++bad;
            if (thiefArmorModifierKnown(2, 0)
                != 0) ++bad;
            if (thiefArmorModifierKnown(5, 0)
                != 0) ++bad;
        }
        // U4: the footnotes
        {
            if (!thiefArmorNoDexBonusInArmor())
                ++bad;
            if (!thiefArmorCoveredByGarmentAssumed())
                ++bad;
            if (!thiefArmorElfinUnderNormalClothing())
                ++bad;
            if (!thiefArmorStuddedNeedsFullBodyCloak())
                ++bad;
            if (!thiefArmorNoArmorBracersOrCloak())
                ++bad;
            if (!thiefArmorFootnoteOnePrintsInFull())
                ++bad;
            if (!thiefArmorNoArmorLargeDevicesBarred())
                ++bad;
            if (!thiefArmorFootnoteFourOrphaned())
                ++bad;
        }
        // U5: the attacks classes and
        // band edges
        {
            if (uaAttacksClassCount() != 5)
                ++bad;
            if (strcmp(uaAttacksClassName(0),
                "Fighter") != 0) ++bad;
            if (strcmp(uaAttacksClassName(4),
                "Paladin") != 0) ++bad;
            if (uaAttacksBandCount() != 4)
                ++bad;
            static const int lo[5][4] = {
                {1, 7, 13, 0},
                {1, 6, 11, 0},
                {1, 8, 15, 0},
                {1, 6, 11, 16},
                {1, 7, 12, 19}
            };
            static const int hi[5][4] = {
                {6, 12, 0, 0},
                {5, 10, 0, 0},
                {7, 14, 0, 0},
                {5, 10, 15, 0},
                {6, 12, 18, 0}
            };
            for (int c = 0; c < 5; ++c)
                for (int b = 0; b < 4; ++b) {
                    if (uaAttacksBandLow(c, b)
                        != lo[c][b]) ++bad;
                    if (uaAttacksBandHigh(c, b)
                        != hi[c][b]) ++bad;
                }
        }
        // U6: the band routing and the
        // verified rates (the R393 clean
        // read: the high band is 2/1)
        {
            if (uaAttacksBandForLevel(0, 1)
                != 0) ++bad;
            if (uaAttacksBandForLevel(0, 7)
                != 1) ++bad;
            if (uaAttacksBandForLevel(0, 13)
                != 2) ++bad;
            if (uaAttacksBandForLevel(2, 15)
                != 2) ++bad;
            if (uaAttacksBandForLevel(3, 16)
                != 3) ++bad;
            if (uaAttacksBandForLevel(4, 19)
                != 3) ++bad;
            if (uaAttacksBandForLevel(4, 12)
                != 1) ++bad;
            if (uaAttacksBandForLevel(4, 13)
                != 2) ++bad;
            if (uaAttacksBandAttacks(0) != 1)
                ++bad;
            if (uaAttacksBandRounds(0) != 1)
                ++bad;
            if (uaAttacksBandAttacks(1) != 3)
                ++bad;
            if (uaAttacksBandRounds(1) != 2)
                ++bad;
            if (uaAttacksBandAttacks(2) != 2)
                ++bad;
            if (uaAttacksBandRounds(2) != 1)
                ++bad;
            if (uaAttacksBandAttacks(3) != 5)
                ++bad;
            if (uaAttacksBandRounds(3) != 2)
                ++bad;
        }
        // U7: the asterisk and the notes
        {
            if (!uaAttacksThrustingOrStrikingOnly())
                ++bad;
            if (!uaAttacksSubOneHdOncePerLevel())
                ++bad;
            if (!uaAttacksNotForSpecialized())
                ++bad;
        }
        // U8: the seams - the R181 PHB
        // table (band agreement on the
        // verified cells) and the R331
        // spec extra-attacks pin
        {
            if (fighterGroupAttacks(0, 3)
                .attacks != 1) ++bad;
            if (fighterGroupAttacks(0, 3)
                .rounds != 1) ++bad;
            if (fighterGroupAttacks(0, 8)
                .attacks != 3) ++bad;
            if (fighterGroupAttacks(0, 8)
                .rounds != 2) ++bad;
            if (!weaponSpecExtraAttacks())
                ++bad;
        }
        printf("R334 thief armor and attacks pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
