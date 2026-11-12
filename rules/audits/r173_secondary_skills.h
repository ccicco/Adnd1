    // ---- R173: secondary skills audit ------------------
    // DMG p.12: the player character non-professional
    // skills - the 23-band table cell by cell and the
    // when-to-use guidance (the judgments recorded in
    // the gap report).
    {
        Secondary secondary;
        int bad = 0;
        static const int kLo[23] = {
            1, 3, 5, 11, 15, 21, 24, 28, 33, 35, 38, 40,
            43, 45, 47, 50, 52, 55, 58, 61, 65, 68, 86
        };
        static const int kHi[23] = {
            2, 4, 10, 14, 20, 23, 27, 32, 34, 37, 39, 42,
            44, 46, 49, 51, 54, 57, 60, 64, 67, 85, 100
        };
        static const char* kName[23] = {
            "Armorer",
            "Bowyer/fletcher",
            "Farmer/gardener",
            "Fisher (netting)",
            "Forester",
            "Gambler",
            "Hunter/fisher (hook and line)",
            "Husbandman (animal husbandry)",
            "Jeweler/lapidary",
            "Leather worker/tanner",
            "Limner/painter",
            "Mason/carpenter",
            "Miner",
            "Navigator (fresh or salt water)",
            "Sailor (fresh or salt)",
            "Shipwright (boats or ships)",
            "Tailor/weaver",
            "Teamster/freighter",
            "Trader/barterer",
            "Trapper/furrier",
            "Woodworker/cabinetmaker",
            "NO SKILL OF MEASURABLE WORTH",
            "ROLL TWICE IGNORING THIS RESULT HEREAFTER"
        };
        if (secondary.rowCount() != 23) ++bad;
        for (int i = 0; i < 23; ++i) {
            Secondary secondary;
            const SecondarySkillRow& row =
                secondary.row(i);
            if (row.lo != kLo[i] || row.hi != kHi[i] ||
                std::string(row.name) != kName[i])
                ++bad;
        }
        // the band arithmetic: 1 through 100 clean
        if (kLo[0] != 1) ++bad;
        for (int i = 0; i < 22; ++i)
            if (kHi[i] + 1 != kLo[i + 1]) ++bad;
        if (kHi[22] != 100) ++bad;
        // the special rows
        if (!secondary.isNoSkill(21)) ++bad;
        if (secondary.isNoSkill(20)) ++bad;
        if (secondary.isNoSkill(22)) ++bad;
        if (!secondary.isRollTwice(22)) ++bad;
        if (secondary.isRollTwice(21)) ++bad;
        // the intro and adjudication prose
        if (!secondary.classAssumedPriorProfession() ||
            !secondary.minorMundaneKnowledgePossible() ||
            !secondary.campaignAimedAtSkillsUsesTable() ||
            !secondary.assignRandomOrPerBackground() ||
            !secondary.secondSkillIfTwoSkills() ||
            !secondary.DMAdjudicatesSituations() ||
            !secondary.skillGivesWorthSoundnessRepairs() ||
            !secondary.assumeRoleToScaleAbility())
            ++bad;
        printf("R173 secondary skills audit: bad %d\n", bad);
        if (bad) return 1;
    }
