    // ---- R271: the III.E misc magic explanation
    // prose part 15 ----
    // Mac-Fuirmidh Cittern through the type table,
    // part2 lines 686-764 - the slice closing the
    // kMisc3 row 26 instrument item.
    {
        int bad = 0;
        if (rules::mmpCitternMisusePct() != 50 ||
            rules::mmpCitternDamageMin() != 3 ||
            rules::mmpCitternDamageMax() != 12 ||
            rules::mmpCitternLevelGate() != 5 ||
            rules::mmpCitternCharmBonusPct() != 15 ||
            rules::mmpCitternSongCount() != 3) ++bad;
        if (rules::mmpDossMisusePct() != 60 ||
            rules::mmpDossDamageMin() != 4 ||
            rules::mmpDossDamageMax() != 16 ||
            rules::mmpDossLevelGate() != 8 ||
            rules::mmpDossCharmBonusPct() != 20 ||
            rules::mmpDossSongCount() != 3 ||
            rules::mmpDossProtFireRadiusFeet() != 10) ++bad;
        if (rules::mmpCanaithMisusePct() != 70 ||
            rules::mmpCanaithDamageMin() != 5 ||
            rules::mmpCanaithDamageMax() != 20 ||
            rules::mmpCanaithLevelGate() != 11 ||
            rules::mmpCanaithCharmBonusPct() != 25 ||
            rules::mmpCanaithSongCount() != 3 ||
            rules::mmpCanaithProtLightningRadiusFeet() !=
            10) ++bad;
        if (rules::mmpCliMisusePct() != 80 ||
            rules::mmpCliDamageMin() != 6 ||
            rules::mmpCliDamageMax() != 24 ||
            rules::mmpCliLevelGate() != 14 ||
            rules::mmpCliCharmBonusPct() != 30 ||
            rules::mmpCliSongCount() != 3) ++bad;
        if (rules::mmpAnstruthMisusePct() != 90 ||
            rules::mmpAnstruthDamageMin() != 8 ||
            rules::mmpAnstruthDamageMax() != 32 ||
            rules::mmpAnstruthLevelGate() != 17 ||
            rules::mmpAnstruthCharmBonusPct() != 35 ||
            rules::mmpAnstruthSongCount() != 3) ++bad;
        if (rules::mmpOllamhDamageMin() != 10 ||
            rules::mmpOllamhDamageMax() != 40 ||
            rules::mmpOllamhLevelGate() != 20 ||
            rules::mmpOllamhCharmBonusPct() != 40 ||
            rules::mmpOllamhSongCount() != 3) ++bad;
        // the printed ladders, verified against the
        // printed values: the misuse percent climbs
        // by 10, the level gates by 3, the charm
        // bonus by 5
        if (rules::mmpDossMisusePct() !=
            rules::mmpCitternMisusePct() + 10 ||
            rules::mmpCanaithMisusePct() !=
            rules::mmpDossMisusePct() + 10 ||
            rules::mmpCliMisusePct() !=
            rules::mmpCanaithMisusePct() + 10 ||
            rules::mmpAnstruthMisusePct() !=
            rules::mmpCliMisusePct() + 10) ++bad;
        if (rules::mmpDossLevelGate() !=
            rules::mmpCitternLevelGate() + 3 ||
            rules::mmpCanaithLevelGate() !=
            rules::mmpDossLevelGate() + 3 ||
            rules::mmpCliLevelGate() !=
            rules::mmpCanaithLevelGate() + 3 ||
            rules::mmpAnstruthLevelGate() !=
            rules::mmpCliLevelGate() + 3 ||
            rules::mmpOllamhLevelGate() !=
            rules::mmpAnstruthLevelGate() + 3) ++bad;
        if (rules::mmpDossCharmBonusPct() !=
            rules::mmpCitternCharmBonusPct() + 5 ||
            rules::mmpCanaithCharmBonusPct() !=
            rules::mmpDossCharmBonusPct() + 5 ||
            rules::mmpCliCharmBonusPct() !=
            rules::mmpCanaithCharmBonusPct() + 5 ||
            rules::mmpAnstruthCharmBonusPct() !=
            rules::mmpCliCharmBonusPct() + 5 ||
            rules::mmpOllamhCharmBonusPct() !=
            rules::mmpAnstruthCharmBonusPct() + 5) ++bad;
        // the general properties of all bard
        // instruments
        if (rules::mmpInstrumentAbilityCount() != 4 ||
            rules::mmpInstrumentAbilityRadiusFeet() !=
            10 ||
            rules::mmpInstrumentAbilityPerDay() != 1 ||
            rules::mmpInstrumentActivateSegments() != 5 ||
            rules::mmpInstrumentCompleteRounds() !=
            1) ++bad;
        // the college order runs 1-7, the magnus
        // alumni sings one turn longer
        if (rules::mmpInstrumentCollegeTurnsMin() != 1 ||
            rules::mmpInstrumentCollegeTurnsMax() != 7 ||
            rules::mmpInstrumentMagnusTurns() !=
            rules::mmpInstrumentCollegeTurnsMax() +
            1) ++bad;
        // the charm excess: -1 per 5 percent above
        // 100
        if (rules::mmpInstrumentCharmExcessThresholdPct() !=
            100 ||
            rules::mmpInstrumentCharmExcessStepPct() != 5 ||
            rules::mmpInstrumentCharmExcessPenaltyPerStep() !=
            1) ++bad;
        // the type die table against static twins
        static const int kTlo[7] = {
            1, 6, 10, 13, 16, 18, 20,
        };
        static const int kThi[7] = {
            5, 9, 12, 15, 17, 19, 20,
        };
        if (rules::mmpInstrumentKindRowCount() != 7) ++bad;
        for (int i = 0; i < 7; ++i)
            if (rules::mmpInstrumentDieLo(i) != kTlo[i] ||
                rules::mmpInstrumentDieHi(i) != kThi[i]) ++bad;
        // the type dice tile 1-20 without gaps
        for (int i = 0; i < 6; ++i)
            if (rules::mmpInstrumentDieLo(i + 1) !=
                rules::mmpInstrumentDieHi(i) +
                1) ++bad;
        if (rules::mmpInstrumentDieLo(0) != 1 ||
            rules::mmpInstrumentDieHi(6) != 20) ++bad;
        // the kMisc3 row 26 quadruple asterisk base
        if (rules::m3RowLo(26) != 73 ||
            rules::m3RowHi(26) != 78 ||
            rules::m3StarCount(26) != 4 ||
            rules::m3InstrumentBaseXp() != 1000 ||
            rules::m3InstrumentBaseGp() != 5000) ++bad;
        printf("R271 misc magic prose part 15 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
