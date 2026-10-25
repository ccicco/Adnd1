    // ---- R252: the III.B scrolls explanation prose pins audit ----
    // DMG pp.137-139: the scroll mechanics
    // and the eight protection scrolls.
    {
        int bad = 0;
        // the eight scrolls are the engine III.B
        // table rows 61-97 (the R222
        // scrollpins.h pins)
        if (rules::scrollProtRowCount() != 8 ||
            rules::scrollProtRowLo(0) != 61 ||
            rules::scrollProtRowHi(7) != 97) ++bad;
        static const int kPLo[8] = {
            61, 63, 65, 71, 77, 83, 88, 93,
        };
        static const int kPHi[8] = {
            62, 64, 70, 76, 82, 87, 92, 97,
        };
        for (int i = 0; i < 8; ++i)
            if (rules::scrollProtRowLo(i) != kPLo[i] ||
                rules::scrollProtRowHi(i) != kPHi[i]) ++bad;
        // the class table - the first and
        // second rolls
        if (rules::scpClassMuLo() != 1 ||
            rules::scpClassMuHi() != 70 ||
            rules::scpClassIlluLo() != 1 ||
            rules::scpClassIlluHi() != 10 ||
            rules::scpClassClericLo() != 71 ||
            rules::scpClassClericHi() != 100 ||
            rules::scpClassDruidLo() != 1 ||
            rules::scpClassDruidHi() != 25) ++bad;
        // the fading chance
        if (rules::scpFadePercentLo() != 5 ||
            rules::scpFadePercentHi() != 30 ||
            rules::scpFadeDieFaces() != 6) ++bad;
        // the spell level of scroll spells
        if (rules::scpWriteLevelAdd() != 1 ||
            rules::scpWriteLevelFloor() != 6 ||
            rules::scpSixthLevelSpellWrittenAt() != 13 ||
            rules::scpSeventhLevelSpellWrittenAt() != 15 ||
            rules::scpScrollFireballDice() != 6 ||
            rules::scpScrollFireballFaces() != 6) ++bad;
        // magic spell failure - the percent,
        // the wish example, and the table
        if (rules::scpFailPercentPerLevel() != 5 ||
            rules::scpWishExampleDiffLevels() != 17 ||
            rules::scpWishExampleFailPercent() != 85 ||
            rules::scpFailRowCount() != 6 ||
            rules::scpFailDiffStep() != 3) ++bad;
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
            if (rules::scpFailDiffLo(i) != kFDiffLo[i] ||
                rules::scpFailTotal(i) != kFTotal[i] ||
                rules::scpFailHarmful(i) != kFHarm[i]) ++bad;
        for (int i = 1; i < 6; ++i)
            if (rules::scpFailDiffLo(i) !=
                rules::scpFailDiffLo(i - 1) + 3) ++bad;
        // the use of scroll spells
        if (rules::scpSevenSpellScrollReducesTo() != 6) ++bad;
        // protection from demons
        if (rules::scpDemonsReadAllRounds() != 1 ||
            rules::scpDemonsReadTypeVISegments() != 7 ||
            rules::scpDemonsReadTypeIIISegments() != 3 ||
            rules::scpDemonsRadiusFeet() != 10 ||
            rules::scpDemonsRoundLo() != 5 ||
            rules::scpDemonsRoundHi() != 20 ||
            rules::scpDemonsDice() != 5 ||
            rules::scpDemonsFaces() != 4) ++bad;
        // protection from devils
        if (rules::scpDevilsReadAllRounds() != 1 ||
            rules::scpDevilsReadGreaterSegments() != 7 ||
            rules::scpDevilsReadLesserSegments() != 3) ++bad;
        // protection from elementals - and the
        // variety table
        if (rules::scpElemReadSegments() != 6 ||
            rules::scpElemVarietyRowCount() != 5 ||
            rules::scpElemRadiusFeet() != 10 ||
            rules::scpElemHitDiceSpecific() != 24 ||
            rules::scpElemHitDiceAll() != 16 ||
            rules::scpElemRoundLo() != 5 ||
            rules::scpElemRoundHi() != 40 ||
            rules::scpElemDice() != 5 ||
            rules::scpElemFaces() != 8) ++bad;
        static const int kELo[5] = {
            1, 16, 31, 46, 61,
        };
        static const int kEHi[5] = {
            15, 30, 45, 60, 100,
        };
        for (int i = 0; i < 5; ++i)
            if (rules::scpElemVarLo(i) != kELo[i] ||
                rules::scpElemVarHi(i) != kEHi[i]) ++bad;
        for (int i = 1; i < 5; ++i)
            if (rules::scpElemVarLo(i) !=
                rules::scpElemVarHi(i - 1) + 1) ++bad;
        if (rules::scpElemVarLo(-5) != 1 ||
            rules::scpElemVarHi(99) != 100) ++bad;
        // protection from lycanthropes - and the
        // type table
        if (rules::scpLycaReadSegments() != 4 ||
            rules::scpLycaTypeRowCount() != 7 ||
            rules::scpLycaRadiusFeet() != 10 ||
            rules::scpLycaHitDice() != 49 ||
            rules::scpLycaPlusTolerance() != 2 ||
            rules::scpLycaRoundLo() != 5 ||
            rules::scpLycaRoundHi() != 30) ++bad;
        static const int kLLo[7] = {
            1, 6, 11, 21, 26, 41, 99,
        };
        static const int kLHi[7] = {
            5, 10, 20, 25, 40, 98, 100,
        };
        for (int i = 0; i < 7; ++i)
            if (rules::scpLycaTypeLo(i) != kLLo[i] ||
                rules::scpLycaTypeHi(i) != kLHi[i]) ++bad;
        for (int i = 1; i < 7; ++i)
            if (rules::scpLycaTypeLo(i) !=
                rules::scpLycaTypeHi(i - 1) + 1) ++bad;
        if (rules::scpLycaTypeLo(-5) != 1 ||
            rules::scpLycaTypeHi(99) != 100) ++bad;
        // protection from magic
        if (rules::scpMagicReadSegments() != 8 ||
            rules::scpMagicRadiusFeet() != 5 ||
            rules::scpMagicDrainPercent() != 50 ||
            rules::scpMagicDrainSaveRoll() != 11 ||
            rules::scpMagicDrainSaveFaces() != 20 ||
            rules::scpMagicRoundLo() != 5 ||
            rules::scpMagicRoundHi() != 30 ||
            rules::scpMagicDice() != 5 ||
            rules::scpMagicFaces() != 6) ++bad;
        // protection from petrification
        if (rules::scpPetrifyReadSegments() != 5 ||
            rules::scpPetrifyRadiusFeet() != 10 ||
            rules::scpPetrifyRoundLo() != 5 ||
            rules::scpPetrifyRoundHi() != 20 ||
            rules::scpPetrifyDice() != 5 ||
            rules::scpPetrifyFaces() != 4) ++bad;
        // protection from possession
        if (rules::scpPossessReadRounds() != 1 ||
            rules::scpPossessRadiusFeet() != 10 ||
            rules::scpPossessRoundLo() != 10 ||
            rules::scpPossessRoundHi() != 60 ||
            rules::scpPossessRoundsPercent() != 90 ||
            rules::scpPossessTurnsPercent() != 10 ||
            rules::scpPossessTurnLo() != 10 ||
            rules::scpPossessTurnHi() != 60) ++bad;
        // protection from undead - the type
        // count cross-pins the R251 undead
        // control potion (the prose Cf.)
        if (rules::scpUndeadReadSegments() != 4 ||
            rules::scpUndeadRadiusFeet() != 5 ||
            rules::scpUndeadTypeCount() != 10 ||
            rules::potUndeadTypeRowCount() != 10 ||
            rules::scpUndeadHitDice() != 35 ||
            rules::scpUndeadRoundLo() != 10 ||
            rules::scpUndeadRoundHi() != 80 ||
            rules::scpUndeadDice() != 10 ||
            rules::scpUndeadFaces() != 8) ++bad;
        printf("R252 scrolls prose pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
