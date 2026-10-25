    // ---- R733 OA treasure class usage audit ----
    // OA round one hundred twenty (capture p. 285): the Chapter 13 treasure
    // opener - the Magical Items Usable by Character Class table, the eight
    // Oriental classes pinned to their DMG usability codes, the sohei staves
    // exception carried in the split code, the opener prose riding along,
    // single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dkuClassCount() != 8
            || dkuCodeFighter() != 1
            || dkuCodeCleric() != 2
            || dkuCodeMagicUser() != 3
            || dkuCodeThief() != 4
            || dkuCodeSoheiSplit() != 5
            || !dkuChapterOpener()
            || !dkuMoneyMagicPower()
            || !dkuPowerToInfluenceDestiny()
            || !dkuPowerToInfluenceOthers()
            || !dkuTreasureGivesAccess()
            || !dkuSupplementsDMG()
            || !dkuMostDMGItemsFound()
            || !dkuPeculiarItemsGiven()
            || !dkuIntegrationTables()
            || !dkuDMGRestrictionsApply()
            || !dkuSamuraiFighter()
            || !dkuSoheiFighterClericExceptStaves()
            || !dkuShukenjaCleric()
            || !dkuBushiFighter()
            || !dkuKensaiFighter()
            || !dkuWuJenMagicUser()
            || !dkuNinjaThief()
            || !dkuYakuzaThief()
        )
            ++bad;
        // the dkuClassUse grid
        int CClassUse[8][1] = {
            {1},
            {5},
            {2},
            {1},
            {1},
            {3},
            {4},
            {4},
            };
        int nClassUse[1] = {0};
        int eClassUse[1] = {0};
        for (int b = 0;
             b < dkuClassCount();
             ++b) {
            int vals[1];
            vals[0] = dkuUsableCode(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CClassUse[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nClassUse[c];
            }
        }
        for (int c = 0; c < 1; ++c)
            if (nClassUse[c] != eClassUse[c])
                ++bad;
        // the opener prose - the Chapter 13 intro paragraph, healthy values,
        // each condition false
    if (dkuChapterOpener() != 1
            || dkuMoneyMagicPower() != 1
            || dkuPowerToInfluenceDestiny() != 1
            || dkuPowerToInfluenceOthers() != 1
            || dkuTreasureGivesAccess() != 1
            || dkuSupplementsDMG() != 1
            || dkuMostDMGItemsFound() != 1
            || dkuPeculiarItemsGiven() != 1
            || dkuIntegrationTables() != 1
        )
            ++bad;
        // the codes - the five usability codes and the row count, healthy
        // values, each condition false
    if (dkuCodeFighter() != 1
            || dkuCodeCleric() != 2
            || dkuCodeMagicUser() != 3
            || dkuCodeThief() != 4
            || dkuCodeSoheiSplit() != 5
            || dkuClassCount() != 8
        )
            ++bad;
        // the mappings and the restrictions clause, healthy values, each
        // condition false
    if (dkuDMGRestrictionsApply() != 1
            || dkuSamuraiFighter() != 1
            || dkuSoheiFighterClericExceptStaves() != 1
            || dkuShukenjaCleric() != 1
            || dkuBushiFighter() != 1
            || dkuKensaiFighter() != 1
            || dkuWuJenMagicUser() != 1
            || dkuNinjaThief() != 1
            || dkuYakuzaThief() != 1
        )
            ++bad;
        // the grid - the eight-row class table, audited cell by cell by the
        // table audit
    if (dkuClassCount() != 8
        )
            ++bad;
        printf("R733 OA treasure class usage audit: bad %d\n", bad);
        if (bad) return 1;
    }
