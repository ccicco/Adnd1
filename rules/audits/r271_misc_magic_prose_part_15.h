    // ---- R271: the III.E misc magic explanation
    // prose part 15 ----
    // Mac-Fuirmidh Cittern through the type table,
    // part2 lines 686-764 - the slice closing the
    // kMisc3 row 26 instrument item.
    {
        Miscmagic_alchemy_jug_to_wings_of_flying miscmagic;
        Miscmagic_table3_footnotes miscmagic_table3_footnotes;
        int bad = 0;
        if (miscmagic.mmpCitternMisusePct() != 50 ||
            miscmagic.mmpCitternDamageMin() != 3 ||
            miscmagic.mmpCitternDamageMax() != 12 ||
            miscmagic.mmpCitternLevelGate() != 5 ||
            miscmagic.mmpCitternCharmBonusPct() != 15 ||
            miscmagic.mmpCitternSongCount() != 3) ++bad;
        if (miscmagic.mmpDossMisusePct() != 60 ||
            miscmagic.mmpDossDamageMin() != 4 ||
            miscmagic.mmpDossDamageMax() != 16 ||
            miscmagic.mmpDossLevelGate() != 8 ||
            miscmagic.mmpDossCharmBonusPct() != 20 ||
            miscmagic.mmpDossSongCount() != 3 ||
            miscmagic.mmpDossProtFireRadiusFeet() != 10) ++bad;
        if (miscmagic.mmpCanaithMisusePct() != 70 ||
            miscmagic.mmpCanaithDamageMin() != 5 ||
            miscmagic.mmpCanaithDamageMax() != 20 ||
            miscmagic.mmpCanaithLevelGate() != 11 ||
            miscmagic.mmpCanaithCharmBonusPct() != 25 ||
            miscmagic.mmpCanaithSongCount() != 3 ||
            miscmagic.mmpCanaithProtLightningRadiusFeet() !=
            10) ++bad;
        if (miscmagic.mmpCliMisusePct() != 80 ||
            miscmagic.mmpCliDamageMin() != 6 ||
            miscmagic.mmpCliDamageMax() != 24 ||
            miscmagic.mmpCliLevelGate() != 14 ||
            miscmagic.mmpCliCharmBonusPct() != 30 ||
            miscmagic.mmpCliSongCount() != 3) ++bad;
        if (miscmagic.mmpAnstruthMisusePct() != 90 ||
            miscmagic.mmpAnstruthDamageMin() != 8 ||
            miscmagic.mmpAnstruthDamageMax() != 32 ||
            miscmagic.mmpAnstruthLevelGate() != 17 ||
            miscmagic.mmpAnstruthCharmBonusPct() != 35 ||
            miscmagic.mmpAnstruthSongCount() != 3) ++bad;
        if (miscmagic.mmpOllamhDamageMin() != 10 ||
            miscmagic.mmpOllamhDamageMax() != 40 ||
            miscmagic.mmpOllamhLevelGate() != 20 ||
            miscmagic.mmpOllamhCharmBonusPct() != 40 ||
            miscmagic.mmpOllamhSongCount() != 3) ++bad;
        // the printed ladders, verified against the
        // printed values: the misuse percent climbs
        // by 10, the level gates by 3, the charm
        // bonus by 5
        if (miscmagic.mmpDossMisusePct() !=
            miscmagic.mmpCitternMisusePct() + 10 ||
            miscmagic.mmpCanaithMisusePct() !=
            miscmagic.mmpDossMisusePct() + 10 ||
            miscmagic.mmpCliMisusePct() !=
            miscmagic.mmpCanaithMisusePct() + 10 ||
            miscmagic.mmpAnstruthMisusePct() !=
            miscmagic.mmpCliMisusePct() + 10) ++bad;
        if (miscmagic.mmpDossLevelGate() !=
            miscmagic.mmpCitternLevelGate() + 3 ||
            miscmagic.mmpCanaithLevelGate() !=
            miscmagic.mmpDossLevelGate() + 3 ||
            miscmagic.mmpCliLevelGate() !=
            miscmagic.mmpCanaithLevelGate() + 3 ||
            miscmagic.mmpAnstruthLevelGate() !=
            miscmagic.mmpCliLevelGate() + 3 ||
            miscmagic.mmpOllamhLevelGate() !=
            miscmagic.mmpAnstruthLevelGate() + 3) ++bad;
        if (miscmagic.mmpDossCharmBonusPct() !=
            miscmagic.mmpCitternCharmBonusPct() + 5 ||
            miscmagic.mmpCanaithCharmBonusPct() !=
            miscmagic.mmpDossCharmBonusPct() + 5 ||
            miscmagic.mmpCliCharmBonusPct() !=
            miscmagic.mmpCanaithCharmBonusPct() + 5 ||
            miscmagic.mmpAnstruthCharmBonusPct() !=
            miscmagic.mmpCliCharmBonusPct() + 5 ||
            miscmagic.mmpOllamhCharmBonusPct() !=
            miscmagic.mmpAnstruthCharmBonusPct() + 5) ++bad;
        // the general properties of all bard
        // instruments
        if (miscmagic.mmpInstrumentAbilityCount() != 4 ||
            miscmagic.mmpInstrumentAbilityRadiusFeet() !=
            10 ||
            miscmagic.mmpInstrumentAbilityPerDay() != 1 ||
            miscmagic.mmpInstrumentActivateSegments() != 5 ||
            miscmagic.mmpInstrumentCompleteRounds() !=
            1) ++bad;
        // the college order runs 1-7, the magnus
        // alumni sings one turn longer
        if (miscmagic.mmpInstrumentCollegeTurnsMin() != 1 ||
            miscmagic.mmpInstrumentCollegeTurnsMax() != 7 ||
            miscmagic.mmpInstrumentMagnusTurns() !=
            miscmagic.mmpInstrumentCollegeTurnsMax() +
            1) ++bad;
        // the charm excess: -1 per 5 percent above
        // 100
        if (miscmagic.mmpInstrumentCharmExcessThresholdPct() !=
            100 ||
            miscmagic.mmpInstrumentCharmExcessStepPct() != 5 ||
            miscmagic.mmpInstrumentCharmExcessPenaltyPerStep() !=
            1) ++bad;
        // the type die table against static twins
        static const int kTlo[7] = {
            1, 6, 10, 13, 16, 18, 20,
        };
        static const int kThi[7] = {
            5, 9, 12, 15, 17, 19, 20,
        };
        if (miscmagic.mmpInstrumentKindRowCount() != 7) ++bad;
        for (int i = 0; i < 7; ++i)
            if (miscmagic.mmpInstrumentDieLo(i) != kTlo[i] ||
                miscmagic.mmpInstrumentDieHi(i) != kThi[i]) ++bad;
        // the type dice tile 1-20 without gaps
        for (int i = 0; i < 6; ++i)
            if (miscmagic.mmpInstrumentDieLo(i + 1) !=
                miscmagic.mmpInstrumentDieHi(i) +
                1) ++bad;
        if (miscmagic.mmpInstrumentDieLo(0) != 1 ||
            miscmagic.mmpInstrumentDieHi(6) != 20) ++bad;
        // the kMisc3 row 26 quadruple asterisk base
        if (miscmagic_table3_footnotes.m3RowLo(26) != 73 ||
            miscmagic_table3_footnotes.m3RowHi(26) != 78 ||
            miscmagic_table3_footnotes.m3StarCount(26) != 4 ||
            miscmagic_table3_footnotes.m3InstrumentBaseXp() != 1000 ||
            miscmagic_table3_footnotes.m3InstrumentBaseGp() != 5000) ++bad;
        printf("R271 misc magic prose part 15 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
