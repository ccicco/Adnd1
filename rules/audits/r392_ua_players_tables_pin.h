    // ---- R392: the UA players tables pin audit ----
    // The players tables manifest sweep (20 items): the
    // equipment and supplies costs table and the
    // hand-held weapons table pin NEW (rules/uaequip26.h,
    // rules/uahandheld.h); the weight/damage, missile and
    // proficiency tables AMEND (the clean PDF read: every
    // hole fills, three misdecodes reconcile - the garrot
    // L damage, the barbarian initial, the ranger initial);
    // the seventeen covered rides close the manifest.
    {
        using namespace rules;
        int bad = 0;
        // U1: the equipment and supplies costs
        {
            if (uaecArmorCount() != 4) ++bad;
            if (uaecArmsCount() != 19) ++bad;
            if (strcmp(uaecArmorName(0),
                "Bronze Plate") != 0) ++bad;
            if (uaecArmorCost(0) != 100) ++bad;
            if (strcmp(uaecArmorName(1),
                "Full Plate") != 0) ++bad;
            if (uaecArmorCost(1) != 4000) ++bad;
            if (strcmp(uaecArmorName(2),
                "Field Plate") != 0) ++bad;
            if (uaecArmorCost(2) != 2000) ++bad;
            if (uaecArmorCost(3) != 5) ++bad;
            if (strcmp(uaecArmsName(0), "Aklys")
                != 0) ++bad;
            if (uaecArmsCost(0) != 2) ++bad;
            if (strcmp(uaecArmsName(5),
                "Crossbow, hand") != 0) ++bad;
            if (uaecArmsCost(5) != 300) ++bad;
            if (strcmp(uaecArmsName(6),
                "Quarrels for same") != 0) ++bad;
            if (uaecArmsCost(6) != 100) ++bad;
            if (uaecArmsCost(18) != 3) ++bad;
            if (!uaecArmsPriceIsSilver(3)) ++bad;
            if (!uaecArmsPriceIsSilver(4)) ++bad;
            if (!uaecArmsPriceIsSilver(11)) ++bad;
            if (uaecArmsPriceIsSilver(0)) ++bad;
            if (!uaecArmsPriceIsElectrum(7)) ++bad;
            if (uaecArmsPriceIsElectrum(0)) ++bad;
            int gp = 0;
            for (int i = 0; i < 19; ++i) {
                if (uaecArmsPriceIsSilver(i)) continue;
                if (uaecArmsPriceIsElectrum(i))
                    continue;
                ++gp;
            }
            if (gp != 15) ++bad;
        }
        // U2: the hand-held weapons table
        {
            if (uahhRowCount() != 60) ++bad;
            if (strcmp(uahhName(0), "Aklys") != 0)
                ++bad;
            if (strcmp(uahhName(59), "Whip") != 0)
                ++bad;
            if (strcmp(uahhName(46), "Spetum")
                != 0) ++bad;
            if (strcmp(uahhLength(0), "c. 2'")
                != 0) ++bad;
            if (strcmp(uahhSpaceRequired(0), "2'")
                != 0) ++bad;
            if (uahhSpeedFactorMin(0) != 4) ++bad;
            if (uahhSpeedFactorMax(0) != 4) ++bad;
            if (uahhAklysSpeedBonus() != 1) ++bad;
            // the n/a rows: the atlatl, the blowgun,
            // the caltrop
            if (uahhSpeedFactorMin(1) != -1) ++bad;
            if (uahhSpeedFactorMin(7) != -1) ++bad;
            if (uahhSpeedFactorMin(9) != -1) ++bad;
            // the speed-factor ranges: the spear,
            // the trident, the whip
            if (uahhSpeedFactorMin(45) != 6) ++bad;
            if (uahhSpeedFactorMax(45) != 8) ++bad;
            if (uahhSpeedFactorMin(59) != 5) ++bad;
            if (uahhSpeedFactorMax(59) != 8) ++bad;
            // the aklys AC ladder (AC 0..6)
            for (int ac = 0; ac < 7; ++ac)
                if (uahhAcAdjustment(0, ac)
                    != ac - 7) ++bad;
            if (uahhAcAdjustment(5, 0) != 2) ++bad;
            if (uahhAcAdjustment(5, 4) != 2) ++bad;
            if (uahhAcAdjustment(5, 5) != 0) ++bad;
            if (uahhAcAdjustment(5, 10) != -1) ++bad;
            if (uahhAcAdjustment(59, 10) != 3) ++bad;
            // the general note and the footnotes
            if (uahhRearAttackBonus() != 2) ++bad;
            if (uahhStunnedProneBonus() != 4) ++bad;
            if (!uahhNoteSetDoubleVsCharge()) ++bad;
            if (!uahhNoteDismountOnHit()) ++bad;
            if (!uahhSetDoubleFlag(46)) ++bad;
            if (!uahhSetDoubleFlag(50)) ++bad;
            if (uahhSetDoubleFlag(0)) ++bad;
            if (!uahhDismountFlag(12)) ++bad;
            if (!uahhDismountFlag(42)) ++bad;
            if (uahhDismountFlag(0)) ++bad;
            int sd = 0, dm = 0;
            for (int i = 0; i < 60; ++i) {
                if (uahhSetDoubleFlag(i)) ++sd;
                if (uahhDismountFlag(i)) ++dm;
            }
            if (sd != 2) ++bad;
            if (dm != 8) ++bad;
        }
        // U3: the amended tables (the reconcile
        // cross-checks)
        {
            if (uawtRowCount() != 68) ++bad;
            if (uawtNewWeaponCount() != 18) ++bad;
            if (strcmp(uawtName(67),
                "Quarrel (or Bolt), hand") != 0)
                ++bad;
            if (!uawtIsNewWeapon(67)) ++bad;
            if (uawtPhbSeamIndex(67) != -1) ++bad;
            if (uawtWeightMin(67) != 1) ++bad;
            if (uawtDamageSMMin(67) != 1) ++bad;
            if (uawtDamageSMMax(67) != 3) ++bad;
            if (uawtDamageLMin(67) != 1) ++bad;
            if (uawtDamageLMax(67) != 2) ++bad;
            if (uawtDamageLMax(19) != 6) ++bad;
            if (!uawtDamagePrintsDash(35)) ++bad;
            if (uawtDamagePrintsDash(0)) ++bad;
            if (!uawtNote1ChargingMountDouble())
                ++bad;
            if (!uawtNote2SetDoubleVsCharge())
                ++bad;
            if (uawtNote3BladeClassLowInches()
                != 15) ++bad;
            if (uawtNote3BladeClassHighInches()
                != 24) ++bad;
            if (uawtNote4DisarmOnAcEightHit()
                != 8) ++bad;
            if (!uawtNote5BastardAsLongSword())
                ++bad;
            if (!uawtNote6VariantsSeePhb()) ++bad;
            if (uapfInitialSlots(5) != 6) ++bad;
            if (uapfInitialSlots(6) != 3) ++bad;
            if (uapfNonProfPenalty(0) != 3) ++bad;
            if (uapfFacingPageNotesLost()) ++bad;
            if (strcmp(uamtRateOfFire(18), "1/2")
                != 0) ++bad;
            if (strcmp(uamtRangeShort(0), "1*")
                != 0) ++bad;
            if (!uamtAklysTenFootOnly()) ++bad;
        }
        printf("R392 UA players tables pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
