    // ---- R209: the NPC personae facts audit ----
    // DMG pp.114-115: the classed, occupied
    // and demi-human ability adjustments,
    // the facts tables, the sanity asterisk
    // rule, and the p.11 die rules.
    {
        int bad = 0;
        // the class table: abilities and amounts
        // (ability codes: 0 STR, 1 INT, 2 WIS, 3 DEX,
        // 4 CON, 5 CHA, 6 none - the Ability enum)
        static const int kAdjAb[30] = {
            2, 6, 6,
            6, 6, 6,
            0, 4, 6,
            0, 4, 6,
            0, 4, 6,
            1, 3, 6,
            6, 6, 6,
            6, 6, 6,
            3, 1, 6,
            3, 1, 0,
        };
        static const int kAdjAmt[30] = {
            2, 0, 0,   0, 0, 0,   2, 1, 0,
            2, 1, 0,   2, 1, 0,   2, 1, 0,
            0, 0, 0,   0, 0, 0,   2, 1, 0,
            2, 1, 1,
        };
        if (rules::npcClassCount() != 10) ++bad;
        for (int c = 0; c < 10; ++c)
            for (int s = 0; s < 3; ++s)
                if (rules::npcClassAdjAbility(c, s)
                        != kAdjAb[c * 3 + s] ||
                    rules::npcClassAdjAmount(c, s)
                        != kAdjAmt[c * 3 + s]) ++bad;
        // the class minimums: druid 12/14,
        // ranger 12, paladin 17, illusionist
        // 15/15, monk 12/15/15
        if (rules::npcClassMinAbility(
                rules::NPCP_DRUID, 0) != 2 ||
            rules::npcClassMinValue(
                rules::NPCP_DRUID, 0) != 12 ||
            rules::npcClassMinAbility(
                rules::NPCP_DRUID, 1) != 5 ||
            rules::npcClassMinValue(
                rules::NPCP_DRUID, 1) != 14) ++bad;
        if (rules::npcClassMinAbility(
                rules::NPCP_RANGER, 0) != 2 ||
            rules::npcClassMinValue(
                rules::NPCP_RANGER, 0) != 12) ++bad;
        if (rules::npcClassMinAbility(
                rules::NPCP_PALADIN, 0) != 5 ||
            rules::npcClassMinValue(
                rules::NPCP_PALADIN, 0) != 17) ++bad;
        if (rules::npcClassMinAbility(
                rules::NPCP_ILLUSIONIST, 0) != 1 ||
            rules::npcClassMinValue(
                rules::NPCP_ILLUSIONIST, 0) != 15 ||
            rules::npcClassMinAbility(
                rules::NPCP_ILLUSIONIST, 1) != 3 ||
            rules::npcClassMinValue(
                rules::NPCP_ILLUSIONIST, 1) != 15) ++bad;
        if (rules::npcClassMinAbility(
                rules::NPCP_MONK, 0) != 0 ||
            rules::npcClassMinValue(
                rules::NPCP_MONK, 0) != 12 ||
            rules::npcClassMinAbility(
                rules::NPCP_MONK, 1) != 2 ||
            rules::npcClassMinValue(
                rules::NPCP_MONK, 1) != 15 ||
            rules::npcClassMinAbility(
                rules::NPCP_MONK, 2) != 3 ||
            rules::npcClassMinValue(
                rules::NPCP_MONK, 2) != 15) ++bad;
        // the no-minimum classes read none
        for (int s = 0; s < 3; ++s)
            if (rules::npcClassMinAbility(
                    rules::NPCP_CLERIC, s)
                    != 6 ||
                rules::npcClassMinValue(
                    rules::NPCP_CLERIC, s) != 0 ||
                rules::npcClassMinAbility(
                    rules::NPCP_THIEF, s)
                    != 6 ||
                rules::npcClassMinValue(
                    rules::NPCP_THIEF, s) != 0) ++bad;
        // the ability limit clamp
        if (rules::npcAdjustedAbility(18, 2) != 18 ||
            rules::npcAdjustedAbility(3, -1) != 3 ||
            rules::npcAdjustedAbility(10, 2) != 12) ++bad;
        // the occupations: laborer strength
        // +1 to +3, mercenary strength +1 and
        // constitution +3 with 4 minimum hit
        // points, merchant 12/12 minimums
        if (rules::npcOccupationCount() != 3) ++bad;
        if (rules::npcOccupationAdjAbility(
                rules::NPCO_LABORER, 0) != 0 ||
            rules::npcOccupationAdjMin(
                rules::NPCO_LABORER, 0) != 1 ||
            rules::npcOccupationAdjMax(
                rules::NPCO_LABORER, 0) != 3) ++bad;
        if (rules::npcOccupationAdjAbility(
                rules::NPCO_MERCENARY, 0) != 0 ||
            rules::npcOccupationAdjMin(
                rules::NPCO_MERCENARY, 0) != 1 ||
            rules::npcOccupationAdjAbility(
                rules::NPCO_MERCENARY, 1) != 4 ||
            rules::npcOccupationAdjMin(
                rules::NPCO_MERCENARY, 1) != 3 ||
            rules::npcMercenaryMinHitPoints() != 4) ++bad;
        if (rules::npcOccupationMinAbility(
                rules::NPCO_MERCHANT, 0) != 1 ||
            rules::npcOccupationMinValue(
                rules::NPCO_MERCHANT, 0) != 12 ||
            rules::npcOccupationMinAbility(
                rules::NPCO_MERCHANT, 1) != 5 ||
            rules::npcOccupationMinValue(
                rules::NPCO_MERCHANT, 1) != 12) ++bad;
        // the demi-human table (the DMG one,
        // not the PHB one)
        if (rules::npcDemiRaceCount() != 4) ++bad;
        static const int kRaceAb[12] = {
            0, 4, 5,
            1, 3, 6,
            2, 4, 5,
            3, 4, 6,
        };
        static const int kRaceAmt[12] = {
            1, 1, -1,   1, 1, 0,
            1, 1, -1,   1, 1, 0,
        };
        for (int r = 0; r < 4; ++r)
            for (int s = 0; s < 3; ++s)
                if (rules::npcRaceAdjAbility(r, s)
                        != kRaceAb[r * 3 + s] ||
                    rules::npcRaceAdjAmount(r, s)
                        != kRaceAmt[r * 3 + s]) ++bad;
        // the alignment table, every face
        static const int kAlign[10] = {
            0, 1, 2,
            3, 4, 5,
            6, 7, 8,
            8,
        };
        for (int d = 1; d <= 10; ++d)
            if (rules::npcFactAlign(d) != kAlign[d - 1]) ++bad;
        if (rules::npcFactAlign(0) != rules::NPCA_TRUE) ++bad;
        // the possessions table, every face
        static const int kWealth[10] = {
            0, 1, 1,
            2, 2,
            2, 2,
            3, 4,
            5,
        };
        for (int d = 1; d <= 10; ++d)
            if (rules::npcFactWealth(d) != kWealth[d - 1]) ++bad;
        // the appearance age bands, every face
        static const int kAge[10] = {
            0, 1,
            1, 2,
            2, 2,
            2, 3,
            4, 5,
        };
        for (int d = 1; d <= 10; ++d)
            if (rules::npcFactAgeBand(d) != kAge[d - 1]) ++bad;
        // the general appearance words,
        // every face, all ten distinct
        static const int kLook[10] = {
            0, 1,
            2, 3,
            4, 5,
            6, 7,
            8, 9,
        };
        for (int d = 1; d <= 10; ++d)
            if (rules::npcFactGeneralLook(d) != kLook[d - 1]) ++bad;
        // the sanity table, every face
        static const int kSanity[10] = {
            0, 1,
            1, 1,
            1, 1,
            2, 3,
            4, 5,
        };
        for (int d = 1; d <= 10; ++d)
            if (rules::npcFactSanity(d) != kSanity[d - 1]) ++bad;
        // the asterisk rows: insane and
        // maniacal only
        if (!rules::npcSanityIsMarked(
                rules::NPCS_INSANE) ||
            !rules::npcSanityIsMarked(
                rules::NPCS_MANIACAL) ||
            rules::npcSanityIsMarked(                rules::NPCS_NEUROTIC) ||
            rules::npcSanityIsMarked(                rules::NPCS_NORMAL)) ++bad;
        // the asterisk resolution: a marked
        // first roll takes the second roll,
        // an unmarked first roll stands
        if (rules::npcSanityResolved(9, 10)
                != rules::NPCS_MANIACAL ||
            rules::npcSanityResolved(10, 9)
                != rules::NPCS_INSANE ||
            rules::npcSanityResolved(9, 3)
                != rules::NPCS_NORMAL ||
            rules::npcSanityResolved(4, 10)
                != rules::NPCS_NORMAL ||
            rules::npcSanityResolved(2, 8)
                != rules::NPCS_NORMAL) ++bad;
        // the p.11 die rules
        if (rules::npcGeneralCharacterDie(1) != 3 ||
            rules::npcGeneralCharacterDie(6) != 4 ||
            rules::npcGeneralCharacterDie(3) != 3 ||
            rules::npcGeneralCharacterDie(5) != 5) ++bad;
        if (rules::npcSpecialCharacterDieBonus(1) != 1 ||
            rules::npcSpecialCharacterDieBonus(5) != 1 ||
            rules::npcSpecialCharacterDieBonus(6) != 0) ++bad;
        // no fewer than three General Tendencies
        if (rules::npcMinGeneralTendencies() != 3) ++bad;
        printf("R209 NPC personae facts audit: bad %d\n", bad);
        if (bad) return 1;
    }
