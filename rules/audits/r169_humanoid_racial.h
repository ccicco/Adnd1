    // ---- R169: humanoid racial preferences audit ----
    // DMG p.106: the nine-race matrix cell by
    // cell, the star marks, the letter key and
    // the usage and compatibility prose.
    {
        int bad = 0;
        // the nine race names, in print order
        if (rules::humRPrefRaceCount() != 9) ++bad;
        static const char* kRace[9] = {
            "bugbear", "gnoll", "goblin", "hill giant",
            "hobgoblin", "kobold", "ogre", "orc", "troll"
        };
        for (int i = 0; i < 9; ++i)
            if (std::string(rules::humRPrefRaceName(i))
                    != kRace[i])
                ++bad;
        // the race index probe, both ways
        if (rules::humRPrefRaceIndex("hobgoblin") != 4 ||
            rules::humRPrefRaceIndex("troll") != 8 ||
            rules::humRPrefRaceIndex("bugbear") != 0 ||
            rules::humRPrefRaceIndex("purple worm") != -1)
            ++bad;
        // the full 81-cell matrix and the star
        // marks, cell by cell
        static const rules::HumRPrefCode kWant[9][9] = {
            { rules::HPREF_P, rules::HPREF_T, rules::HPREF_G, rules::HPREF_T, rules::HPREF_A, rules::HPREF_A, rules::HPREF_T, rules::HPREF_A, rules::HPREF_N },
            { rules::HPREF_T, rules::HPREF_P, rules::HPREF_A, rules::HPREF_T, rules::HPREF_N, rules::HPREF_A, rules::HPREF_G, rules::HPREF_T, rules::HPREF_N },
            { rules::HPREF_G, rules::HPREF_A, rules::HPREF_P, rules::HPREF_N, rules::HPREF_T, rules::HPREF_G, rules::HPREF_H, rules::HPREF_N, rules::HPREF_A },
            { rules::HPREF_G, rules::HPREF_G, rules::HPREF_A, rules::HPREF_P, rules::HPREF_A, rules::HPREF_A, rules::HPREF_G, rules::HPREF_N, rules::HPREF_T },
            { rules::HPREF_T, rules::HPREF_N, rules::HPREF_N, rules::HPREF_N, rules::HPREF_H, rules::HPREF_A, rules::HPREF_A, rules::HPREF_T, rules::HPREF_H },
            { rules::HPREF_A, rules::HPREF_H, rules::HPREF_G, rules::HPREF_A, rules::HPREF_A, rules::HPREF_P, rules::HPREF_H, rules::HPREF_A, rules::HPREF_T },
            { rules::HPREF_T, rules::HPREF_T, rules::HPREF_A, rules::HPREF_G, rules::HPREF_A, rules::HPREF_A, rules::HPREF_P, rules::HPREF_T, rules::HPREF_T },
            { rules::HPREF_A, rules::HPREF_N, rules::HPREF_T, rules::HPREF_A, rules::HPREF_N, rules::HPREF_A, rules::HPREF_G, rules::HPREF_H, rules::HPREF_H },
            { rules::HPREF_A, rules::HPREF_N, rules::HPREF_A, rules::HPREF_T, rules::HPREF_H, rules::HPREF_T, rules::HPREF_N, rules::HPREF_A, rules::HPREF_N }
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
                if (rules::humRPrefCode(r, c) != kWant[r][c])
                    ++bad;
                if (rules::humRPrefStars(r, c)
                        != kStar[r][c])
                    ++bad;
                if (rules::humRPrefBullyMark(r, c)
                        != (kStar[r][c] == 1))
                    ++bad;
                if (rules::humRPrefRivalTribe(r, c)
                        != (kStar[r][c] == 2))
                    ++bad;
                switch (rules::humRPrefCode(r, c)) {
                case rules::HPREF_P: ++nP; break;
                case rules::HPREF_G: ++nG; break;
                case rules::HPREF_T: ++nT; break;
                case rules::HPREF_N: ++nN; break;
                case rules::HPREF_A: ++nA; break;
                case rules::HPREF_H: ++nH; break;
                }
                if (rules::humRPrefStars(r, c) == 1) ++nSingle;
                if (rules::humRPrefStars(r, c) == 2) ++nDouble;
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
            bool selfP =
                rules::humRPrefCode(i, i) == rules::HPREF_P;
            bool rival = rules::humRPrefRivalTribe(i, i);
            if (i == 4 || i == 7 || i == 8) {
                if (selfP || !rival) ++bad;
            } else {
                if (!selfP || rival) ++bad;
            }
        }
        // the letter key names and letters
        if (std::string(rules::humRPrefCodeName(
                rules::HPREF_P)) != "preference" ||
            std::string(rules::humRPrefCodeName(
                rules::HPREF_G)) != "goodwill" ||
            std::string(rules::humRPrefCodeName(
                rules::HPREF_T)) != "tolerate" ||
            std::string(rules::humRPrefCodeName(
                rules::HPREF_N)) != "neutral negative" ||
            std::string(rules::humRPrefCodeName(
                rules::HPREF_A)) != "antipathy" ||
            std::string(rules::humRPrefCodeName(
                rules::HPREF_H)) != "hatred" ||
            rules::humRPrefCodeLetter(rules::HPREF_P) != 'P' ||
            rules::humRPrefCodeLetter(rules::HPREF_G) != 'G' ||
            rules::humRPrefCodeLetter(rules::HPREF_T) != 'T' ||
            rules::humRPrefCodeLetter(rules::HPREF_N) != 'N' ||
            rules::humRPrefCodeLetter(rules::HPREF_A) != 'A' ||
            rules::humRPrefCodeLetter(rules::HPREF_H) != 'H')
            ++bad;
        // the letter semantics
        if (!rules::humCodeAllowsCoOperation(
                rules::HPREF_P) ||
            !rules::humCodeAllowsCoOperation(
                rules::HPREF_G) ||
            rules::humCodeAllowsCoOperation(rules::HPREF_T) ||
            !rules::humCodeNoHostilityLikely(rules::HPREF_T) ||
            rules::humCodeNoHostilityLikely(rules::HPREF_N) ||
            !rules::humCodeNoAidIfIllBefalls(rules::HPREF_N) ||
            rules::humCodeNoAidIfIllBefalls(rules::HPREF_G))
            ++bad;
        // the antipathy and hatred behavior
        if (!rules::humAntipathyDesertIfLeadersWeak() ||
            !rules::humHatredBreaksOutAtFirstOpportunity() ||
            !rules::humHatredDesertsNearStrongHatedBody())
            ++bad;
        // the usage prose: side by side within 12
        // inches, no intervening troops or screen
        if (rules::humSideBySideVisibilityRangeInches() != 12 ||
            !rules::humInterveningTroopsOrScreenBlocks())
            ++bad;
        // the compatibility prose
        if (!rules::humDemihumanCompatibilityFromPHBTable() ||
            !rules::humLizardMenHatedByAllHumanoidsSaveKobolds() ||
            !rules::humKoboldsSuspiciousOfLizardMen() ||
            !rules::humHumanTroopsSuspiciousOfLizardMen())
            ++bad;
        // spot probes of the matrix in print
        // coordinates
        if (rules::humRPrefCode(0, 2) != rules::HPREF_G ||
            rules::humRPrefCode(2, 0) != rules::HPREF_G ||
            rules::humRPrefCode(4, 8) != rules::HPREF_H ||
            rules::humRPrefCode(8, 4) != rules::HPREF_H ||
            rules::humRPrefCode(1, 6) != rules::HPREF_G ||
            rules::humRPrefCode(6, 1) != rules::HPREF_T ||
            rules::humRPrefCode(5, 1) != rules::HPREF_H ||
            rules::humRPrefCode(5, 6) != rules::HPREF_H)
            ++bad;
        if (!rules::humRPrefBullyMark(0, 1) ||
            !rules::humRPrefBullyMark(0, 4) ||
            !rules::humRPrefBullyMark(6, 5) ||
            !rules::humRPrefBullyMark(7, 5) ||
            !rules::humRPrefBullyMark(3, 7) ||
            !rules::humRPrefBullyMark(4, 2) ||
            rules::humRPrefBullyMark(4, 4) ||
            rules::humRPrefBullyMark(2, 5) ||
            rules::humRPrefRivalTribe(0, 4))
            ++bad;
        printf("R169 humanoid racial preferences audit: bad %d\n", bad);
        if (bad) return 1;
    }
