    // ---- R629 OA families audit ----
    // OA round sixteen (capture pp. 60-62): the Chapter 3 opener - the family
    // doctrine, the birth rank prose and the Tables 37 and 38 grids
    {
        using namespace rules;
        int bad = 0;
    if (dgpT37RowCount() != 9
            || dgpBirthRollDice() != 2
            || dgpBirthRollSides() != 10
            || dgpT38RowCount() != 17
            || dgpNpcExampleDiffPct() != 25
            || dgpNpcExamplePc() != 30
            || dgpNpcExampleNpc() != 55
            || dgpFamilyChartRows() != 3
            || dgpHeadPosition() != 1
            || dgpRowSpacesDice() != 8
            || dgpMaleChancePct() != 70
            || !dgpFamilyIncludesAllRelations()
            || !dgpAncestorsAddHonor()
            || !dgpClassesMayAdoptProfession()
            || !dgpShukenjaSeversConnections()
            || !dgpOptionalFamilyFollowsRules()
            || !dgpKorobokuruSamuraiNoRoll()
            || !dgpKorobokuruSamuraiLowestRank()
            || !dgpNinjaAutomaticClan()
            || !dgpNinjaBirthRankOptional()
            || !dgpBirthRankNpcReaction()
            || !dgpBirthRankAncestryBirthright()
            || !dgpHonorIsFamilyNotCharacter()
            || !dgpHeadAutoMale()
            || !dgpFamilyNameFirst()
        )
            ++bad;
        // the Table 37 grid: the class birth modifiers and the requirement
        // codes (capture pp. 60-61)
        int CT37[9][3] = {
            {10,1,1},
            {0,0,0},
            {0,0,0},
            {0,1,1},
            {0,1,1},
            {0,1,1},
            {0,0,0},
            {0,0,1},
            {-10,0,1},
            };
        int nT37[3] = {0,0,0};
        int eT37[3] = {0,0,0};
        for (int b = 0;
             b < dgpT37RowCount();
             ++b) {
            int vals[3];
            vals[0] = dgpT37Mod(b);
            vals[1] = dgpT37BirthReq(b);
            vals[2] = dgpT37FamilyReq(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT37[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT37[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nT37[c] != eT37[c])
                ++bad;
        // the Table 38 grid: the rank codes, reaction scores, ancestry and
        // birthright dice with the family honor (capture p. 61)
        int CT38[17][7] = {
            {0,5,6,1,4,1,0},
            {1,10,4,2,4,2,1},
            {2,15,6,2,6,1,5},
            {3,20,10,1,8,2,8},
            {4,25,20,2,20,2,10},
            {5,30,100,2,20,4,15},
            {6,35,100,4,100,3,17},
            {7,40,100,5,100,4,20},
            {8,45,100,6,100,5,22},
            {9,50,100,7,100,6,24},
            {10,55,100,7,100,7,25},
            {11,60,100,7,100,8,26},
            {12,65,100,8,100,9,27},
            {13,70,100,8,100,10,28},
            {14,75,100,9,100,10,29},
            {15,80,100,9,100,10,30},
            {16,90,100,10,100,10,35},
            };
        int nT38[7] = {0,0,0,0,0,0,0};
        int eT38[7] = {0,0,0,0,0,0,0};
        for (int b = 0;
             b < dgpT38RowCount();
             ++b) {
            int vals[7];
            vals[0] = dgpT38RankCode(b);
            vals[1] = dgpT38NpcPct(b);
            vals[2] = dgpT38AncDie(b);
            vals[3] = dgpT38AncRolls(b);
            vals[4] = dgpT38BirthDie(b);
            vals[5] = dgpT38BirthRolls(b);
            vals[6] = dgpT38Honor(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CT38[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT38[c];
            }
        }
        for (int c = 0; c < 7; ++c)
            if (nT38[c] != eT38[c])
                ++bad;
        // the dgpT37RowCount pin
    if (dgpT37RowCount() != 9
        )
            ++bad;
        // the dgpBirthRollDice pin
    if (dgpBirthRollDice() != 2
        )
            ++bad;
        // the dgpBirthRollSides pin
    if (dgpBirthRollSides() != 10
        )
            ++bad;
        // the dgpT38RowCount pin
    if (dgpT38RowCount() != 17
        )
            ++bad;
        // the dgpNpcExampleDiffPct pin
    if (dgpNpcExampleDiffPct() != 25
        )
            ++bad;
        // the dgpNpcExamplePc pin
    if (dgpNpcExamplePc() != 30
        )
            ++bad;
        // the dgpNpcExampleNpc pin
    if (dgpNpcExampleNpc() != 55
        )
            ++bad;
        // the dgpFamilyChartRows pin
    if (dgpFamilyChartRows() != 3
        )
            ++bad;
        // the dgpHeadPosition pin
    if (dgpHeadPosition() != 1
        )
            ++bad;
        // the dgpRowSpacesDice pin
    if (dgpRowSpacesDice() != 8
        )
            ++bad;
        // the dgpMaleChancePct pin
    if (dgpMaleChancePct() != 70
        )
            ++bad;
        // the dgpFamilyIncludesAllRelations pin
    if (dgpFamilyIncludesAllRelations() != 1
        )
            ++bad;
        // the dgpAncestorsAddHonor pin
    if (dgpAncestorsAddHonor() != 1
        )
            ++bad;
        // the dgpClassesMayAdoptProfession pin
    if (dgpClassesMayAdoptProfession() != 1
        )
            ++bad;
        // the dgpShukenjaSeversConnections pin
    if (dgpShukenjaSeversConnections() != 1
        )
            ++bad;
        // the dgpOptionalFamilyFollowsRules pin
    if (dgpOptionalFamilyFollowsRules() != 1
        )
            ++bad;
        // the dgpKorobokuruSamuraiNoRoll pin
    if (dgpKorobokuruSamuraiNoRoll() != 1
        )
            ++bad;
        // the dgpKorobokuruSamuraiLowestRank pin
    if (dgpKorobokuruSamuraiLowestRank() != 1
        )
            ++bad;
        // the dgpNinjaAutomaticClan pin
    if (dgpNinjaAutomaticClan() != 1
        )
            ++bad;
        // the dgpNinjaBirthRankOptional pin
    if (dgpNinjaBirthRankOptional() != 1
        )
            ++bad;
        // the dgpBirthRankNpcReaction pin
    if (dgpBirthRankNpcReaction() != 1
        )
            ++bad;
        // the dgpBirthRankAncestryBirthright pin
    if (dgpBirthRankAncestryBirthright() != 1
        )
            ++bad;
        // the dgpHonorIsFamilyNotCharacter pin
    if (dgpHonorIsFamilyNotCharacter() != 1
        )
            ++bad;
        // the dgpHeadAutoMale pin
    if (dgpHeadAutoMale() != 1
        )
            ++bad;
        // the dgpFamilyNameFirst pin
    if (dgpFamilyNameFirst() != 1
        )
            ++bad;
        // the T37 samurai row - the +10 modifier, both requirements (capture
        // pp. 60-61)
    if (dgpT37Mod(0) != 10
            || dgpT37BirthReq(0) != 1
            || dgpT37FamilyReq(0) != 1
        )
            ++bad;
        // the T37 yakuza row - the -10 modifier, no birth roll, family
        // required (capture p. 61)
    if (dgpT37Mod(8) != -10
            || dgpT37BirthReq(8) != 0
            || dgpT37FamilyReq(8) != 1
        )
            ++bad;
        // the T37 ninja row - no modifier, no birth roll, family required
        // (capture p. 61)
    if (dgpT37Mod(7) != 0
            || dgpT37BirthReq(7) != 0
            || dgpT37FamilyReq(7) != 1
        )
            ++bad;
        // the T37 middle block - shukenja, sohei and wu jen require neither
        // (capture pp. 60-61)
    if (dgpT37BirthReq(1) != 0
            || dgpT37BirthReq(2) != 0
            || dgpT37BirthReq(6) != 0
            || dgpT37FamilyReq(6) != 0
        )
            ++bad;
        // the T38 outcast row - 5 percent, d6/1 ancestry, d4/1 birthright, 0
        // honor (capture p. 61)
    if (dgpT38RankCode(0) != 0
            || dgpT38NpcPct(0) != 5
            || dgpT38AncDie(0) != 6
            || dgpT38AncRolls(0) != 1
            || dgpT38BirthDie(0) != 4
            || dgpT38BirthRolls(0) != 1
            || dgpT38Honor(0) != 0
        )
            ++bad;
        // the T38 row-3 settled cell - the ancestry d100/8 read against the
        // 2018 print (capture p. 61)
    if (dgpT38AncDie(13) != 100
            || dgpT38AncRolls(13) != 8
        )
            ++bad;
        // the T38 1st Rank capstone - 90 percent, d100/10 both, honor 35,
        // seventeen rows only (capture p. 61)
    if (dgpT38RankCode(16) != 16
            || dgpT38NpcPct(16) != 90
            || dgpT38AncRolls(16) != 10
            || dgpT38BirthRolls(16) != 10
            || dgpT38Honor(16) != 35
            || dgpT38RowCount() != 17
        )
            ++bad;
        // the T38 honor ladder - 0 at outcast, 35 at 1st Rank (capture p. 61)
    if (dgpT38Honor(0) != 0
            || dgpT38Honor(6) != 17
            || dgpT38Honor(16) != 35
        )
            ++bad;
        // the T38 reaction example - the 55-minus-30 read for the -25
        // modifier (capture p. 62)
    if (dgpNpcExampleNpc() - dgpNpcExamplePc() != 25
            || dgpNpcExampleDiffPct() != 25
        )
            ++bad;
        // the birth roll doctrine - 2d10 with the modifier applied (capture
        // p. 61)
    if (dgpBirthRollDice() != 2
            || dgpBirthRollSides() != 10
        )
            ++bad;
        // the family chart doctrine - 1d8 spaces per row, three rows, head at
        // position 1 (capture p. 62)
    if (dgpRowSpacesDice() != 8
            || dgpFamilyChartRows() != 3
            || dgpHeadPosition() != 1
        )
            ++bad;
        printf("R629 OA families audit: bad %d\n", bad);
        if (bad) return 1;
    }
