    // ---- R169: humanoid racial preferences audit ----
    // DMG p.106: the nine-race matrix cell by
    // cell, the star marks, the letter key and
    // the usage and compatibility prose.
    {
        Humanoid_preferences humanoid_preferences;
        int bad = 0;
        // the nine race names, in print order
        if (humanoid_preferences.humRPrefRaceCount() != 9) ++bad;
        static const char* kRace[9] = {
            "bugbear", "gnoll", "goblin", "hill giant",
            "hobgoblin", "kobold", "ogre", "orc", "troll"
        };
        for (int i = 0; i < 9; ++i)
            if (std::string(humanoid_preferences.humRPrefRaceName(i))
                    != kRace[i])
                ++bad;
        // the race index probe, both ways
        if (humanoid_preferences.humRPrefRaceIndex("hobgoblin") != 4 ||
            humanoid_preferences.humRPrefRaceIndex("troll") != 8 ||
            humanoid_preferences.humRPrefRaceIndex("bugbear") != 0 ||
            humanoid_preferences.humRPrefRaceIndex("purple worm") != -1)
            ++bad;
        // the full 81-cell matrix and the star
        // marks, cell by cell
        static const HumRPrefCode kWant[9][9] = {
            { HPREF_P, HPREF_T, HPREF_G, HPREF_T, HPREF_A, HPREF_A, HPREF_T, HPREF_A, HPREF_N },
            { HPREF_T, HPREF_P, HPREF_A, HPREF_T, HPREF_N, HPREF_A, HPREF_G, HPREF_T, HPREF_N },
            { HPREF_G, HPREF_A, HPREF_P, HPREF_N, HPREF_T, HPREF_G, HPREF_H, HPREF_N, HPREF_A },
            { HPREF_G, HPREF_G, HPREF_A, HPREF_P, HPREF_A, HPREF_A, HPREF_G, HPREF_N, HPREF_T },
            { HPREF_T, HPREF_N, HPREF_N, HPREF_N, HPREF_H, HPREF_A, HPREF_A, HPREF_T, HPREF_H },
            { HPREF_A, HPREF_H, HPREF_G, HPREF_A, HPREF_A, HPREF_P, HPREF_H, HPREF_A, HPREF_T },
            { HPREF_T, HPREF_T, HPREF_A, HPREF_G, HPREF_A, HPREF_A, HPREF_P, HPREF_T, HPREF_T },
            { HPREF_A, HPREF_N, HPREF_T, HPREF_A, HPREF_N, HPREF_A, HPREF_G, HPREF_H, HPREF_H },
            { HPREF_A, HPREF_N, HPREF_A, HPREF_T, HPREF_H, HPREF_T, HPREF_N, HPREF_A, HPREF_N }
        };
        static const int kStar[9][9] = {
            { 0, 1, 0, 0, 1, 1, 0, 1, 0 },
            { 0, 0, 1, 0, 0, 1, 0, 1, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 1, 0 },
            { 0, 0, 1, 0, 2, 1, 0, 1, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 1, 1, 0, 1, 1, 0, 1, 0 },
            { 0, 0, 1, 0, 0, 1, 0, 2, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 2 }
        };
        int nP = 0, nG = 0, nT = 0, nN = 0,
            nA = 0, nH = 0, nSingle = 0, nDouble = 0;
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                Humanoid_preferences humanoid_preferences;
                if (humanoid_preferences.humRPrefCode(r, c) != kWant[r][c])
                    ++bad;
                if (humanoid_preferences.humRPrefStars(r, c)
                        != kStar[r][c])
                    ++bad;
                if (humanoid_preferences.humRPrefBullyMark(r, c)
                        != (kStar[r][c] == 1))
                    ++bad;
                if (humanoid_preferences.humRPrefRivalTribe(r, c)
                        != (kStar[r][c] == 2))
                    ++bad;
                switch (humanoid_preferences.humRPrefCode(r, c)) {
                case HPREF_P: ++nP; break;
                case HPREF_G: ++nG; break;
                case HPREF_T: ++nT; break;
                case HPREF_N: ++nN; break;
                case HPREF_A: ++nA; break;
                case HPREF_H: ++nH; break;
                }
                if (humanoid_preferences.humRPrefStars(r, c) == 1) ++nSingle;
                if (humanoid_preferences.humRPrefStars(r, c) == 2) ++nDouble;
            }
        }
        // the letter census: P 6, G 10, T 18,
        // N 14, A 25, H 8 (81 cells)
        if (nP != 6 || nG != 10 || nT != 18 ||
            nN != 14 || nA != 25 || nH != 8)
            ++bad;
        // 18 single stars, 3 double stars
        if (nSingle != 18 || nDouble != 3) ++bad;
        // the self cells: six print P, the
        // hobgoblin, orc and troll cells print the
        // double star (rival tribe or family
        // group)
        for (int i = 0; i < 9; ++i) {
            Humanoid_preferences humanoid_preferences;
            bool selfP =
                humanoid_preferences.humRPrefCode(i, i) == HPREF_P;
            bool rival = humanoid_preferences.humRPrefRivalTribe(i, i);
            if (i == 4 || i == 7 || i == 8) {
                if (selfP || !rival) ++bad;
            } else {
                if (!selfP || rival) ++bad;
            }
        }
        // the letter key names and letters
        if (std::string(humanoid_preferences.humRPrefCodeName(
                HPREF_P)) != "preference" ||
            std::string(humanoid_preferences.humRPrefCodeName(
                HPREF_G)) != "goodwill" ||
            std::string(humanoid_preferences.humRPrefCodeName(
                HPREF_T)) != "tolerate" ||
            std::string(humanoid_preferences.humRPrefCodeName(
                HPREF_N)) != "neutral negative" ||
            std::string(humanoid_preferences.humRPrefCodeName(
                HPREF_A)) != "antipathy" ||
            std::string(humanoid_preferences.humRPrefCodeName(
                HPREF_H)) != "hatred" ||
            humanoid_preferences.humRPrefCodeLetter(HPREF_P) != 'P' ||
            humanoid_preferences.humRPrefCodeLetter(HPREF_G) != 'G' ||
            humanoid_preferences.humRPrefCodeLetter(HPREF_T) != 'T' ||
            humanoid_preferences.humRPrefCodeLetter(HPREF_N) != 'N' ||
            humanoid_preferences.humRPrefCodeLetter(HPREF_A) != 'A' ||
            humanoid_preferences.humRPrefCodeLetter(HPREF_H) != 'H')
            ++bad;
        // the letter semantics
        if (!humanoid_preferences.humCodeAllowsCoOperation(
                HPREF_P) ||
            !humanoid_preferences.humCodeAllowsCoOperation(
                HPREF_G) ||
            humanoid_preferences.humCodeAllowsCoOperation(HPREF_T) ||
            !humanoid_preferences.humCodeNoHostilityLikely(HPREF_T) ||
            humanoid_preferences.humCodeNoHostilityLikely(HPREF_N) ||
            !humanoid_preferences.humCodeNoAidIfIllBefalls(HPREF_N) ||
            humanoid_preferences.humCodeNoAidIfIllBefalls(HPREF_G))
            ++bad;
        // the antipathy and hatred behavior
        if (!humanoid_preferences.humAntipathyDesertIfLeadersWeak() ||
            !humanoid_preferences.humHatredBreaksOutAtFirstOpportunity() ||
            !humanoid_preferences.humHatredDesertsNearStrongHatedBody())
            ++bad;
        // the usage prose: side by side within 12
        // inches, no intervening troops or screen
        if (humanoid_preferences.humSideBySideVisibilityRangeInches() != 12 ||
            !humanoid_preferences.humInterveningTroopsOrScreenBlocks())
            ++bad;
        // the compatibility prose
        if (!humanoid_preferences.humDemihumanCompatibilityFromPHBTable() ||
            !humanoid_preferences.humLizardMenHatedByAllHumanoidsSaveKobolds() ||
            !humanoid_preferences.humKoboldsSuspiciousOfLizardMen() ||
            !humanoid_preferences.humHumanTroopsSuspiciousOfLizardMen())
            ++bad;
        // spot probes of the matrix in print
        // coordinates
        if (humanoid_preferences.humRPrefCode(0, 2) != HPREF_G ||
            humanoid_preferences.humRPrefCode(2, 0) != HPREF_G ||
            humanoid_preferences.humRPrefCode(4, 8) != HPREF_H ||
            humanoid_preferences.humRPrefCode(8, 4) != HPREF_H ||
            humanoid_preferences.humRPrefCode(1, 6) != HPREF_G ||
            humanoid_preferences.humRPrefCode(6, 1) != HPREF_T ||
            humanoid_preferences.humRPrefCode(5, 1) != HPREF_H ||
            humanoid_preferences.humRPrefCode(5, 6) != HPREF_H)
            ++bad;
        if (!humanoid_preferences.humRPrefBullyMark(0, 1) ||
            !humanoid_preferences.humRPrefBullyMark(0, 4) ||
            !humanoid_preferences.humRPrefBullyMark(6, 5) ||
            !humanoid_preferences.humRPrefBullyMark(7, 5) ||
            !humanoid_preferences.humRPrefBullyMark(3, 7) ||
            !humanoid_preferences.humRPrefBullyMark(4, 2) ||
            humanoid_preferences.humRPrefBullyMark(4, 4) ||
            humanoid_preferences.humRPrefBullyMark(2, 5) ||
            humanoid_preferences.humRPrefRivalTribe(0, 4))
            ++bad;
        printf("R169 humanoid racial preferences audit: bad %d\n", bad);
        if (bad) return 1;
    }
