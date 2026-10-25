    // ---- R272: the III.E misc magic explanation
    // prose part 16 ----
    // Iron Flask through Keoghtom ointment, part2
    // lines 766-802 - the slice completing the
    // kMisc3 rows 27-32 (the 33-row III.E.3 table).
    {
        int bad = 0;
        // the iron flask
        if (rules::mmpFlaskRangeInches() != 6 ||
            rules::mmpFlaskMaxCreatures() != 1 ||
            rules::mmpFlaskServiceTurns() != 1 ||
            rules::mmpFlaskServiceHours() != 1 ||
            rules::mmpFlaskRepeatSaveBonus() != 2) ++bad;
        // the flask contents die table against
        // static twins; the printed 00 row is the
        // d100 100 (the engine kMisc3 93-00
        // precedent)
        static const int kFlo[19] = {
            1, 51, 55, 57, 58, 60, 61, 66, 70, 73,
            77, 82, 84, 86, 87, 90, 94, 98, 100,
        };
        static const int kFhi[19] = {
            50, 54, 56, 57, 59, 60, 65, 69, 72, 76,
            81, 83, 85, 86, 89, 93, 97, 99, 100,
        };
        if (rules::mmpFlaskContentsRowCount() != 19) ++bad;
        for (int i = 0; i < 19; ++i)
            if (rules::mmpFlaskContentsLo(i) != kFlo[i] ||
                rules::mmpFlaskContentsHi(i) != kFhi[i]) ++bad;
        // the d100 bands tile without gaps
        for (int i = 0; i < 18; ++i)
            if (rules::mmpFlaskContentsLo(i + 1) !=
                rules::mmpFlaskContentsHi(i) +
                1) ++bad;
        if (rules::mmpFlaskContentsLo(0) != 1 ||
            rules::mmpFlaskContentsHi(18) != 100) ++bad;
        // the three rows whose pipe the upload drops
        if (rules::mmpFlaskContentsLo(11) != 82 ||
            rules::mmpFlaskContentsHi(11) != 83 ||
            rules::mmpFlaskContentsLo(17) != 98 ||
            rules::mmpFlaskContentsHi(17) != 99) ++bad;
        // the javelin of lightning
        if (rules::mmpJavelinLightningPlus() != 2 ||
            rules::mmpJavelinLightningRangeInches() != 9 ||
            rules::mmpJavelinLightningStrokeWidthHalfInches()
            != 1 ||
            rules::mmpJavelinLightningStrokeLengthInches()
            != 3 ||
            rules::mmpJavelinLightningDamageMin() != 1 ||
            rules::mmpJavelinLightningDamageMax() != 6 ||
            rules::mmpJavelinLightningElectricalDamage()
            != 20 ||
            rules::mmpJavelinLightningBackstrokeMin() != 10 ||
            rules::mmpJavelinLightningBackstrokeMax() != 20 ||
            rules::mmpJavelinLightningBackstrokeInches() !=
            3 ||
            rules::mmpJavelinLightningFoundMin() != 2 ||
            rules::mmpJavelinLightningFoundMax() != 5) ++bad;
        // the javelin of piercing
        if (rules::mmpJavelinPiercingRangeInches() != 6 ||
            rules::mmpJavelinPiercingToHitBonus() != 6 ||
            rules::mmpJavelinPiercingDamageMin() != 7 ||
            rules::mmpJavelinPiercingDamageMax() != 12 ||
            rules::mmpJavelinPiercingFoundMin() != 2 ||
            rules::mmpJavelinPiercingFoundMax() != 8 ||
            rules::mmpJavelinPiercingThrows() != 1) ++bad;
        // the jewel of attacks
        if (rules::mmpJewelAttacksWanderingPct() != 100 ||
            rules::mmpJewelAttacksPursuitPct() != 100) ++bad;
        // the jewel of flawlessness
        if (rules::mmpJewelFlawlessBoostPct() != 100 ||
            rules::mmpJewelFlawlessBaseTenths() != 1 ||
            rules::mmpJewelFlawlessBoostedTenths() != 2 ||
            rules::mmpJewelFlawlessFacetMin() != 10 ||
            rules::mmpJewelFlawlessFacetMax() != 100 ||
            rules::mmpJewelFlawlessTriggerD10() != 2 ||
            rules::mmpJewelFlawlessFacetsLostPerBoost() !=
            1) ++bad;
        // the Keoghtom ointment
        if (rules::mmpOintmentJarDiameterInches() != 3 ||
            rules::mmpOintmentJarDepthInches() != 1 ||
            rules::mmpOintmentApplications() != 5 ||
            rules::mmpOintmentHealMin() != 9 ||
            rules::mmpOintmentHealMax() != 12 ||
            rules::mmpOintmentFoundMin() != 1 ||
            rules::mmpOintmentFoundMax() != 3) ++bad;
        // the engine kMisc3 rows 27-32: band edges,
        // the javelin (F) marks, no asterisks, the
        // flawless per-facet row
        if (rules::m3RowLo(27) != 79 ||
            rules::m3RowHi(27) != 80 ||
            rules::m3RowLo(28) != 81 ||
            rules::m3RowHi(28) != 85 ||
            rules::m3RowLo(29) != 86 ||
            rules::m3RowHi(29) != 90 ||
            rules::m3RowLo(30) != 91 ||
            rules::m3RowHi(30) != 91 ||
            rules::m3RowLo(31) != 92 ||
            rules::m3RowHi(31) != 92 ||
            rules::m3RowLo(32) != 93 ||
            rules::m3RowHi(32) != 100) ++bad;
        if (rules::m3UsableByFighter(27) != 0 ||
            rules::m3UsableByFighter(28) != 1 ||
            rules::m3UsableByFighter(29) != 1 ||
            rules::m3UsableByFighter(30) != 0 ||
            rules::m3UsableByFighter(31) != 0 ||
            rules::m3UsableByFighter(32) != 0) ++bad;
        if (rules::m3StarCount(27) != 0 ||
            rules::m3StarCount(28) != 0 ||
            rules::m3StarCount(29) != 0 ||
            rules::m3StarCount(30) != 0 ||
            rules::m3StarCount(31) != 0 ||
            rules::m3StarCount(32) != 0) ++bad;
        if (rules::m3IsPerFacetValued(31) != 1 ||
            rules::m3JewelPerFacetGp() != 1000) ++bad;
        printf("R272 misc magic prose part 16 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
