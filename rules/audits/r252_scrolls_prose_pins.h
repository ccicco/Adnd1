    // ---- R252: the III.B scrolls explanation prose pins audit ----
    // DMG pp.137-139: the scroll mechanics
    // and the eight protection scrolls.
    {
        Potions_invulnerability_to_water_breathing potions_invulnerability_to_water_breathing;
        Scrollpins scrollpins;
        Scrolls_mechanics_protection_demons_to_undead scrolls_mechanics_protection_demons_to_undead;
        int bad = 0;
        // the eight scrolls are the engine III.B
        // table rows 61-97 (the R222
        // scrollpins.h pins)
        if (scrollpins.scrollProtRowCount() != 8 ||
            scrollpins.scrollProtRowLo(0) != 61 ||
            scrollpins.scrollProtRowHi(7) != 97) ++bad;
        static const int kPLo[8] = {
            61, 63, 65, 71, 77, 83, 88, 93,
        };
        static const int kPHi[8] = {
            62, 64, 70, 76, 82, 87, 92, 97,
        };
        for (int i = 0; i < 8; ++i)
            if (scrollpins.scrollProtRowLo(i) != kPLo[i] ||
                scrollpins.scrollProtRowHi(i) != kPHi[i]) ++bad;
        // the class table - the first and
        // second rolls
        if (scrolls_mechanics_protection_demons_to_undead.scpClassMuLo() != 1 ||
            scrolls_mechanics_protection_demons_to_undead.scpClassMuHi() != 70 ||
            scrolls_mechanics_protection_demons_to_undead.scpClassIlluLo() != 1 ||
            scrolls_mechanics_protection_demons_to_undead.scpClassIlluHi() != 10 ||
            scrolls_mechanics_protection_demons_to_undead.scpClassClericLo() != 71 ||
            scrolls_mechanics_protection_demons_to_undead.scpClassClericHi() != 100 ||
            scrolls_mechanics_protection_demons_to_undead.scpClassDruidLo() != 1 ||
            scrolls_mechanics_protection_demons_to_undead.scpClassDruidHi() != 25) ++bad;
        // the fading chance
        if (scrolls_mechanics_protection_demons_to_undead.scpFadePercentLo() != 5 ||
            scrolls_mechanics_protection_demons_to_undead.scpFadePercentHi() != 30 ||
            scrolls_mechanics_protection_demons_to_undead.scpFadeDieFaces() != 6) ++bad;
        // the spell level of scroll spells
        if (scrolls_mechanics_protection_demons_to_undead.scpWriteLevelAdd() != 1 ||
            scrolls_mechanics_protection_demons_to_undead.scpWriteLevelFloor() != 6 ||
            scrolls_mechanics_protection_demons_to_undead.scpSixthLevelSpellWrittenAt() != 13 ||
            scrolls_mechanics_protection_demons_to_undead.scpSeventhLevelSpellWrittenAt() != 15 ||
            scrolls_mechanics_protection_demons_to_undead.scpScrollFireballDice() != 6 ||
            scrolls_mechanics_protection_demons_to_undead.scpScrollFireballFaces() != 6) ++bad;
        // magic spell failure - the percent,
        // the wish example, and the table
        if (scrolls_mechanics_protection_demons_to_undead.scpFailPercentPerLevel() != 5 ||
            scrolls_mechanics_protection_demons_to_undead.scpWishExampleDiffLevels() != 17 ||
            scrolls_mechanics_protection_demons_to_undead.scpWishExampleFailPercent() != 85 ||
            scrolls_mechanics_protection_demons_to_undead.scpFailRowCount() != 6 ||
            scrolls_mechanics_protection_demons_to_undead.scpFailDiffStep() != 3) ++bad;
        static const int kFDiffLo[6] = {
            1, 4, 7, 10, 13, 16,
        };
        static const int kFTotal[6] = {
            95, 85, 75, 65, 50, 30,
        };
        static const int kFHarm[6] = {
            5, 15, 25, 35, 50, 70,
        };
        for (int i = 0; i < 6; ++i)
            if (scrolls_mechanics_protection_demons_to_undead.scpFailDiffLo(i) != kFDiffLo[i] ||
                scrolls_mechanics_protection_demons_to_undead.scpFailTotal(i) != kFTotal[i] ||
                scrolls_mechanics_protection_demons_to_undead.scpFailHarmful(i) != kFHarm[i]) ++bad;
        for (int i = 1; i < 6; ++i)
            if (scrolls_mechanics_protection_demons_to_undead.scpFailDiffLo(i) !=
                scrolls_mechanics_protection_demons_to_undead.scpFailDiffLo(i - 1) + 3) ++bad;
        // the use of scroll spells
        if (scrolls_mechanics_protection_demons_to_undead.scpSevenSpellScrollReducesTo() != 6) ++bad;
        // protection from demons
        if (scrolls_mechanics_protection_demons_to_undead.scpDemonsReadAllRounds() != 1 ||
            scrolls_mechanics_protection_demons_to_undead.scpDemonsReadTypeVISegments() != 7 ||
            scrolls_mechanics_protection_demons_to_undead.scpDemonsReadTypeIIISegments() != 3 ||
            scrolls_mechanics_protection_demons_to_undead.scpDemonsRadiusFeet() != 10 ||
            scrolls_mechanics_protection_demons_to_undead.scpDemonsRoundLo() != 5 ||
            scrolls_mechanics_protection_demons_to_undead.scpDemonsRoundHi() != 20 ||
            scrolls_mechanics_protection_demons_to_undead.scpDemonsDice() != 5 ||
            scrolls_mechanics_protection_demons_to_undead.scpDemonsFaces() != 4) ++bad;
        // protection from devils
        if (scrolls_mechanics_protection_demons_to_undead.scpDevilsReadAllRounds() != 1 ||
            scrolls_mechanics_protection_demons_to_undead.scpDevilsReadGreaterSegments() != 7 ||
            scrolls_mechanics_protection_demons_to_undead.scpDevilsReadLesserSegments() != 3) ++bad;
        // protection from elementals - and the
        // variety table
        if (scrolls_mechanics_protection_demons_to_undead.scpElemReadSegments() != 6 ||
            scrolls_mechanics_protection_demons_to_undead.scpElemVarietyRowCount() != 5 ||
            scrolls_mechanics_protection_demons_to_undead.scpElemRadiusFeet() != 10 ||
            scrolls_mechanics_protection_demons_to_undead.scpElemHitDiceSpecific() != 24 ||
            scrolls_mechanics_protection_demons_to_undead.scpElemHitDiceAll() != 16 ||
            scrolls_mechanics_protection_demons_to_undead.scpElemRoundLo() != 5 ||
            scrolls_mechanics_protection_demons_to_undead.scpElemRoundHi() != 40 ||
            scrolls_mechanics_protection_demons_to_undead.scpElemDice() != 5 ||
            scrolls_mechanics_protection_demons_to_undead.scpElemFaces() != 8) ++bad;
        static const int kELo[5] = {
            1, 16, 31, 46, 61,
        };
        static const int kEHi[5] = {
            15, 30, 45, 60, 100,
        };
        for (int i = 0; i < 5; ++i)
            if (scrolls_mechanics_protection_demons_to_undead.scpElemVarLo(i) != kELo[i] ||
                scrolls_mechanics_protection_demons_to_undead.scpElemVarHi(i) != kEHi[i]) ++bad;
        for (int i = 1; i < 5; ++i)
            if (scrolls_mechanics_protection_demons_to_undead.scpElemVarLo(i) !=
                scrolls_mechanics_protection_demons_to_undead.scpElemVarHi(i - 1) + 1) ++bad;
        if (scrolls_mechanics_protection_demons_to_undead.scpElemVarLo(-5) != 1 ||
            scrolls_mechanics_protection_demons_to_undead.scpElemVarHi(99) != 100) ++bad;
        // protection from lycanthropes - and the
        // type table
        if (scrolls_mechanics_protection_demons_to_undead.scpLycaReadSegments() != 4 ||
            scrolls_mechanics_protection_demons_to_undead.scpLycaTypeRowCount() != 7 ||
            scrolls_mechanics_protection_demons_to_undead.scpLycaRadiusFeet() != 10 ||
            scrolls_mechanics_protection_demons_to_undead.scpLycaHitDice() != 49 ||
            scrolls_mechanics_protection_demons_to_undead.scpLycaPlusTolerance() != 2 ||
            scrolls_mechanics_protection_demons_to_undead.scpLycaRoundLo() != 5 ||
            scrolls_mechanics_protection_demons_to_undead.scpLycaRoundHi() != 30) ++bad;
        static const int kLLo[7] = {
            1, 6, 11, 21, 26, 41, 99,
        };
        static const int kLHi[7] = {
            5, 10, 20, 25, 40, 98, 100,
        };
        for (int i = 0; i < 7; ++i)
            if (scrolls_mechanics_protection_demons_to_undead.scpLycaTypeLo(i) != kLLo[i] ||
                scrolls_mechanics_protection_demons_to_undead.scpLycaTypeHi(i) != kLHi[i]) ++bad;
        for (int i = 1; i < 7; ++i)
            if (scrolls_mechanics_protection_demons_to_undead.scpLycaTypeLo(i) !=
                scrolls_mechanics_protection_demons_to_undead.scpLycaTypeHi(i - 1) + 1) ++bad;
        if (scrolls_mechanics_protection_demons_to_undead.scpLycaTypeLo(-5) != 1 ||
            scrolls_mechanics_protection_demons_to_undead.scpLycaTypeHi(99) != 100) ++bad;
        // protection from magic
        if (scrolls_mechanics_protection_demons_to_undead.scpMagicReadSegments() != 8 ||
            scrolls_mechanics_protection_demons_to_undead.scpMagicRadiusFeet() != 5 ||
            scrolls_mechanics_protection_demons_to_undead.scpMagicDrainPercent() != 50 ||
            scrolls_mechanics_protection_demons_to_undead.scpMagicDrainSaveRoll() != 11 ||
            scrolls_mechanics_protection_demons_to_undead.scpMagicDrainSaveFaces() != 20 ||
            scrolls_mechanics_protection_demons_to_undead.scpMagicRoundLo() != 5 ||
            scrolls_mechanics_protection_demons_to_undead.scpMagicRoundHi() != 30 ||
            scrolls_mechanics_protection_demons_to_undead.scpMagicDice() != 5 ||
            scrolls_mechanics_protection_demons_to_undead.scpMagicFaces() != 6) ++bad;
        // protection from petrification
        if (scrolls_mechanics_protection_demons_to_undead.scpPetrifyReadSegments() != 5 ||
            scrolls_mechanics_protection_demons_to_undead.scpPetrifyRadiusFeet() != 10 ||
            scrolls_mechanics_protection_demons_to_undead.scpPetrifyRoundLo() != 5 ||
            scrolls_mechanics_protection_demons_to_undead.scpPetrifyRoundHi() != 20 ||
            scrolls_mechanics_protection_demons_to_undead.scpPetrifyDice() != 5 ||
            scrolls_mechanics_protection_demons_to_undead.scpPetrifyFaces() != 4) ++bad;
        // protection from possession
        if (scrolls_mechanics_protection_demons_to_undead.scpPossessReadRounds() != 1 ||
            scrolls_mechanics_protection_demons_to_undead.scpPossessRadiusFeet() != 10 ||
            scrolls_mechanics_protection_demons_to_undead.scpPossessRoundLo() != 10 ||
            scrolls_mechanics_protection_demons_to_undead.scpPossessRoundHi() != 60 ||
            scrolls_mechanics_protection_demons_to_undead.scpPossessRoundsPercent() != 90 ||
            scrolls_mechanics_protection_demons_to_undead.scpPossessTurnsPercent() != 10 ||
            scrolls_mechanics_protection_demons_to_undead.scpPossessTurnLo() != 10 ||
            scrolls_mechanics_protection_demons_to_undead.scpPossessTurnHi() != 60) ++bad;
        // protection from undead - the type
        // count cross-pins the R251 undead
        // control potion (the prose Cf.)
        if (scrolls_mechanics_protection_demons_to_undead.scpUndeadReadSegments() != 4 ||
            scrolls_mechanics_protection_demons_to_undead.scpUndeadRadiusFeet() != 5 ||
            scrolls_mechanics_protection_demons_to_undead.scpUndeadTypeCount() != 10 ||
            potions_invulnerability_to_water_breathing.potUndeadTypeRowCount() != 10 ||
            scrolls_mechanics_protection_demons_to_undead.scpUndeadHitDice() != 35 ||
            scrolls_mechanics_protection_demons_to_undead.scpUndeadRoundLo() != 10 ||
            scrolls_mechanics_protection_demons_to_undead.scpUndeadRoundHi() != 80 ||
            scrolls_mechanics_protection_demons_to_undead.scpUndeadDice() != 10 ||
            scrolls_mechanics_protection_demons_to_undead.scpUndeadFaces() != 8) ++bad;
        printf("R252 scrolls prose pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
