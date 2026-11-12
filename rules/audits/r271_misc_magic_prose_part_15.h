    // ---- R271: the III.E misc magic explanation
    // prose part 15 ----
    // Mac-Fuirmidh Cittern through the type table,
    // part2 lines 686-764 - the slice closing the
    // kMisc3 row 26 instrument item.
    {
        Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table miscmagic_mac_fuirmidh_cittern_to_instrument_type_table;
        Miscmagic_table3_footnotes miscmagic_table3_footnotes;
        int bad = 0;
        if (miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCitternMisusePct() != 50 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCitternDamageMin() != 3 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCitternDamageMax() != 12 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCitternLevelGate() != 5 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCitternCharmBonusPct() != 15 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCitternSongCount() != 3) ++bad;
        if (miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpDossMisusePct() != 60 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpDossDamageMin() != 4 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpDossDamageMax() != 16 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpDossLevelGate() != 8 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpDossCharmBonusPct() != 20 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpDossSongCount() != 3 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpDossProtFireRadiusFeet() != 10) ++bad;
        if (miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCanaithMisusePct() != 70 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCanaithDamageMin() != 5 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCanaithDamageMax() != 20 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCanaithLevelGate() != 11 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCanaithCharmBonusPct() != 25 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCanaithSongCount() != 3 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCanaithProtLightningRadiusFeet() !=
            10) ++bad;
        if (miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCliMisusePct() != 80 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCliDamageMin() != 6 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCliDamageMax() != 24 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCliLevelGate() != 14 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCliCharmBonusPct() != 30 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCliSongCount() != 3) ++bad;
        if (miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpAnstruthMisusePct() != 90 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpAnstruthDamageMin() != 8 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpAnstruthDamageMax() != 32 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpAnstruthLevelGate() != 17 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpAnstruthCharmBonusPct() != 35 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpAnstruthSongCount() != 3) ++bad;
        if (miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpOllamhDamageMin() != 10 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpOllamhDamageMax() != 40 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpOllamhLevelGate() != 20 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpOllamhCharmBonusPct() != 40 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpOllamhSongCount() != 3) ++bad;
        // the printed ladders, verified against the
        // printed values: the misuse percent climbs
        // by 10, the level gates by 3, the charm
        // bonus by 5
        if (miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpDossMisusePct() !=
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCitternMisusePct() + 10 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCanaithMisusePct() !=
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpDossMisusePct() + 10 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCliMisusePct() !=
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCanaithMisusePct() + 10 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpAnstruthMisusePct() !=
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCliMisusePct() + 10) ++bad;
        if (miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpDossLevelGate() !=
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCitternLevelGate() + 3 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCanaithLevelGate() !=
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpDossLevelGate() + 3 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCliLevelGate() !=
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCanaithLevelGate() + 3 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpAnstruthLevelGate() !=
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCliLevelGate() + 3 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpOllamhLevelGate() !=
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpAnstruthLevelGate() + 3) ++bad;
        if (miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpDossCharmBonusPct() !=
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCitternCharmBonusPct() + 5 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCanaithCharmBonusPct() !=
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpDossCharmBonusPct() + 5 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCliCharmBonusPct() !=
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCanaithCharmBonusPct() + 5 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpAnstruthCharmBonusPct() !=
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpCliCharmBonusPct() + 5 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpOllamhCharmBonusPct() !=
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpAnstruthCharmBonusPct() + 5) ++bad;
        // the general properties of all bard
        // instruments
        if (miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpInstrumentAbilityCount() != 4 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpInstrumentAbilityRadiusFeet() !=
            10 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpInstrumentAbilityPerDay() != 1 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpInstrumentActivateSegments() != 5 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpInstrumentCompleteRounds() !=
            1) ++bad;
        // the college order runs 1-7, the magnus
        // alumni sings one turn longer
        if (miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpInstrumentCollegeTurnsMin() != 1 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpInstrumentCollegeTurnsMax() != 7 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpInstrumentMagnusTurns() !=
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpInstrumentCollegeTurnsMax() +
            1) ++bad;
        // the charm excess: -1 per 5 percent above
        // 100
        if (miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpInstrumentCharmExcessThresholdPct() !=
            100 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpInstrumentCharmExcessStepPct() != 5 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpInstrumentCharmExcessPenaltyPerStep() !=
            1) ++bad;
        // the type die table against static twins
        static const int kTlo[7] = {
            1, 6, 10, 13, 16, 18, 20,
        };
        static const int kThi[7] = {
            5, 9, 12, 15, 17, 19, 20,
        };
        if (miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpInstrumentKindRowCount() != 7) ++bad;
        for (int i = 0; i < 7; ++i)
            if (miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpInstrumentDieLo(i) != kTlo[i] ||
                miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpInstrumentDieHi(i) != kThi[i]) ++bad;
        // the type dice tile 1-20 without gaps
        for (int i = 0; i < 6; ++i)
            if (miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpInstrumentDieLo(i + 1) !=
                miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpInstrumentDieHi(i) +
                1) ++bad;
        if (miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpInstrumentDieLo(0) != 1 ||
            miscmagic_mac_fuirmidh_cittern_to_instrument_type_table.mmpInstrumentDieHi(6) != 20) ++bad;
        // the kMisc3 row 26 quadruple asterisk base
        if (miscmagic_table3_footnotes.m3RowLo(26) != 73 ||
            miscmagic_table3_footnotes.m3RowHi(26) != 78 ||
            miscmagic_table3_footnotes.m3StarCount(26) != 4 ||
            miscmagic_table3_footnotes.m3InstrumentBaseXp() != 1000 ||
            miscmagic_table3_footnotes.m3InstrumentBaseGp() != 5000) ++bad;
        printf("R271 misc magic prose part 15 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
