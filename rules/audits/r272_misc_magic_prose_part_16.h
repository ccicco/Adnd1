    // ---- R272: the III.E misc magic explanation
    // prose part 16 ----
    // Iron Flask through Keoghtom ointment, part2
    // lines 766-802 - the slice completing the
    // kMisc3 rows 27-32 (the 33-row III.E.3 table).
    {
        Miscmagic_iron_flask_to_keoghtoms_ointment miscmagic;
        Miscmagic_table3_footnotes miscmagic_table3_footnotes;
        int bad = 0;
        // the iron flask
        if (miscmagic.mmpFlaskRangeInches() != 6 ||
            miscmagic.mmpFlaskMaxCreatures() != 1 ||
            miscmagic.mmpFlaskServiceTurns() != 1 ||
            miscmagic.mmpFlaskServiceHours() != 1 ||
            miscmagic.mmpFlaskRepeatSaveBonus() != 2) ++bad;
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
        if (miscmagic.mmpFlaskContentsRowCount() != 19) ++bad;
        for (int i = 0; i < 19; ++i)
            if (miscmagic.mmpFlaskContentsLo(i) != kFlo[i] ||
                miscmagic.mmpFlaskContentsHi(i) != kFhi[i]) ++bad;
        // the d100 bands tile without gaps
        for (int i = 0; i < 18; ++i)
            if (miscmagic.mmpFlaskContentsLo(i + 1) !=
                miscmagic.mmpFlaskContentsHi(i) +
                1) ++bad;
        if (miscmagic.mmpFlaskContentsLo(0) != 1 ||
            miscmagic.mmpFlaskContentsHi(18) != 100) ++bad;
        // the three rows whose pipe the upload drops
        if (miscmagic.mmpFlaskContentsLo(11) != 82 ||
            miscmagic.mmpFlaskContentsHi(11) != 83 ||
            miscmagic.mmpFlaskContentsLo(17) != 98 ||
            miscmagic.mmpFlaskContentsHi(17) != 99) ++bad;
        // the javelin of lightning
        if (miscmagic.mmpJavelinLightningPlus() != 2 ||
            miscmagic.mmpJavelinLightningRangeInches() != 9 ||
            miscmagic.mmpJavelinLightningStrokeWidthHalfInches()
            != 1 ||
            miscmagic.mmpJavelinLightningStrokeLengthInches()
            != 3 ||
            miscmagic.mmpJavelinLightningDamageMin() != 1 ||
            miscmagic.mmpJavelinLightningDamageMax() != 6 ||
            miscmagic.mmpJavelinLightningElectricalDamage()
            != 20 ||
            miscmagic.mmpJavelinLightningBackstrokeMin() != 10 ||
            miscmagic.mmpJavelinLightningBackstrokeMax() != 20 ||
            miscmagic.mmpJavelinLightningBackstrokeInches() !=
            3 ||
            miscmagic.mmpJavelinLightningFoundMin() != 2 ||
            miscmagic.mmpJavelinLightningFoundMax() != 5) ++bad;
        // the javelin of piercing
        if (miscmagic.mmpJavelinPiercingRangeInches() != 6 ||
            miscmagic.mmpJavelinPiercingToHitBonus() != 6 ||
            miscmagic.mmpJavelinPiercingDamageMin() != 7 ||
            miscmagic.mmpJavelinPiercingDamageMax() != 12 ||
            miscmagic.mmpJavelinPiercingFoundMin() != 2 ||
            miscmagic.mmpJavelinPiercingFoundMax() != 8 ||
            miscmagic.mmpJavelinPiercingThrows() != 1) ++bad;
        // the jewel of attacks
        if (miscmagic.mmpJewelAttacksWanderingPct() != 100 ||
            miscmagic.mmpJewelAttacksPursuitPct() != 100) ++bad;
        // the jewel of flawlessness
        if (miscmagic.mmpJewelFlawlessBoostPct() != 100 ||
            miscmagic.mmpJewelFlawlessBaseTenths() != 1 ||
            miscmagic.mmpJewelFlawlessBoostedTenths() != 2 ||
            miscmagic.mmpJewelFlawlessFacetMin() != 10 ||
            miscmagic.mmpJewelFlawlessFacetMax() != 100 ||
            miscmagic.mmpJewelFlawlessTriggerD10() != 2 ||
            miscmagic.mmpJewelFlawlessFacetsLostPerBoost() !=
            1) ++bad;
        // the Keoghtom ointment
        if (miscmagic.mmpOintmentJarDiameterInches() != 3 ||
            miscmagic.mmpOintmentJarDepthInches() != 1 ||
            miscmagic.mmpOintmentApplications() != 5 ||
            miscmagic.mmpOintmentHealMin() != 9 ||
            miscmagic.mmpOintmentHealMax() != 12 ||
            miscmagic.mmpOintmentFoundMin() != 1 ||
            miscmagic.mmpOintmentFoundMax() != 3) ++bad;
        // the engine kMisc3 rows 27-32: band edges,
        // the javelin (F) marks, no asterisks, the
        // flawless per-facet row
        if (miscmagic_table3_footnotes.m3RowLo(27) != 79 ||
            miscmagic_table3_footnotes.m3RowHi(27) != 80 ||
            miscmagic_table3_footnotes.m3RowLo(28) != 81 ||
            miscmagic_table3_footnotes.m3RowHi(28) != 85 ||
            miscmagic_table3_footnotes.m3RowLo(29) != 86 ||
            miscmagic_table3_footnotes.m3RowHi(29) != 90 ||
            miscmagic_table3_footnotes.m3RowLo(30) != 91 ||
            miscmagic_table3_footnotes.m3RowHi(30) != 91 ||
            miscmagic_table3_footnotes.m3RowLo(31) != 92 ||
            miscmagic_table3_footnotes.m3RowHi(31) != 92 ||
            miscmagic_table3_footnotes.m3RowLo(32) != 93 ||
            miscmagic_table3_footnotes.m3RowHi(32) != 100) ++bad;
        if (miscmagic_table3_footnotes.m3UsableByFighter(27) != 0 ||
            miscmagic_table3_footnotes.m3UsableByFighter(28) != 1 ||
            miscmagic_table3_footnotes.m3UsableByFighter(29) != 1 ||
            miscmagic_table3_footnotes.m3UsableByFighter(30) != 0 ||
            miscmagic_table3_footnotes.m3UsableByFighter(31) != 0 ||
            miscmagic_table3_footnotes.m3UsableByFighter(32) != 0) ++bad;
        if (miscmagic_table3_footnotes.m3StarCount(27) != 0 ||
            miscmagic_table3_footnotes.m3StarCount(28) != 0 ||
            miscmagic_table3_footnotes.m3StarCount(29) != 0 ||
            miscmagic_table3_footnotes.m3StarCount(30) != 0 ||
            miscmagic_table3_footnotes.m3StarCount(31) != 0 ||
            miscmagic_table3_footnotes.m3StarCount(32) != 0) ++bad;
        if (miscmagic_table3_footnotes.m3IsPerFacetValued(31) != 1 ||
            miscmagic_table3_footnotes.m3JewelPerFacetGp() != 1000) ++bad;
        printf("R272 misc magic prose part 16 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
