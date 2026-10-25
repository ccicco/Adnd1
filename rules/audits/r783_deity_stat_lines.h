    // ---- R783 deity stat lines audit ----
    // THE DEITY STAT LINES - the R406 messy reads pin at last (Curtiss's
    // Appendix S pick). The 23 blocks ride the 1eonline.info compilation
    // pages (the repo-trusted source the R189 duty reads), row-verified
    // against the R406 pins (armor class, hit points, magic resistance,
    // attack halves, damage spans - every row cross-matched; where the
    // compilation fills a hole the print pins stand: Hanali's 99,
    // Brandobaris's unrecorded damage, Shargaas's attack hole). THE GRID: 23
    // x 12 plus 23 x 13 - the five class/level lines (every Nil reads zero,
    // the halfling titles read as levels, the "in each" fills both columns,
    // all five orc FIGHTER lines read as monsters, the print's own Dumathoin
    // typo rides verbatim), the MOVE rates (base + the parenthetical second
    // rate; Aerdrie's flight-only phrase carries no number), the seven
    // ability lines (signed - Yurtrus -4/-25; the 18/00 and 18/01 slash
    // prints split to the pct column; the CH/Com parentheticals with Hanali's
    // special sentinel), and the DAMAGE/ATTACK bonus (the see-below sentinel
    // for Labelas and Yurtrus). THE CROSS-CHECK: the damage bonus equals the
    // S parenthetical damage bonus on all 15 rows that print both - and the
    // three prints that refuse the pattern pin as they stand (Arvoreen +8
    // with no S parenthetical, Bahgtru +15 against the S +14, Solonor's S +9
    // with no damage bonus). Honest boundaries: the parenthetical reads and
    // the special/see-text levels ride contract-side (the prose is the
    // prose), the Yurtrus destructive-spells-only qualifier and Cyrrollalee's
    // by-weapon-type damage ride contract-side, and the stat-block prose
    // alone stays open
    {
        using namespace rules;
        int bad = 0;
    if (dvpDeityRowCount() != 23
            || dvpStatLineRound() != 783
            || dvpStatBlockFeederRound() != 406
            || dvpDeitySeamFeederRound() != 405
            || dvpClassLineCount() != 5
            || dvpAbilityLineCount() != 7
            || dvpMonsterFighterKind() != 13
            || dvpSeeTextLevel() != -1
            || !dvpClassLinesPinVerbatim()
            || !dvpHalflingTitlesReadAsLevels()
            || !dvpInEachFillsBoth()
            || !dvpOrcFighterLinesReadAsMonsters()
            || !dvpStrPctCellsPinTheSlash()
            || !dvpDamageBonusQuirksArePrint()
            || !dvpParenReadsRideContractSide()
            || dvpProseStaysOpen()
        )
            ++bad;
        // the 23 x 12 class-line grid - the five class/level lines and the
        // MOVE rates, in the R405/R406 registry order (the -1 sentinel census
        // rides the three see-text magic-user reads)
        int CDvpClassLines[23][12] = {
            {12,0,0,12,17,4,10,0,0,0,0,6},
            {18,0,0,12,12,4,0,0,18,0,0,15},
            {9,48,15,14,16,3,-1,14,12,0,0,0},
            {12,0,0,0,14,3,0,11,20,15,0,0},
            {12,0,15,12,14,5,16,0,0,0,0,0},
            {48,0,0,14,10,3,-1,0,0,0,0,10},
            {18,0,0,8,7,4,0,18,20,0,0,10},
            {15,0,0,12,17,4,10,0,12,0,0,8},
            {12,0,14,10,0,0,16,15,0,0,0,12},
            {12,0,14,12,0,0,18,16,0,0,0,12},
            {9,24,0,14,7,4,14,0,0,0,0,10},
            {12,0,8,0,12,4,0,0,10,0,8,0},
            {12,0,10,0,10,5,8,8,0,0,0,0},
            {12,0,0,6,7,4,6,6,19,0,6,0},
            {15,0,0,12,8,4,0,13,20,0,0,0},
            {12,36,8,0,10,3,0,13,0,12,0,0},
            {9,36,0,14,6,3,16,16,0,0,0,4},
            {6,0,8,8,10,3,15,0,0,0,0,0},
            {9,0,0,0,16,13,0,0,0,6,0,0},
            {18,0,0,0,10,13,0,7,16,15,10,0},
            {12,0,8,0,15,13,0,0,0,14,0,0},
            {6,0,15,0,13,13,-1,0,0,15,0,0},
            {15,12,15,0,12,13,12,12,6,6,0,0},
            };
        int nDvpClassLines[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
        int eDvpClassLines[12] = {0,0,0,0,0,0,3,0,0,0,0,0};
        for (int b = 0;
             b < dvpDeityRowCount();
             ++b) {
            int vals[12];
            vals[0] = dvpMoveBase(b);
            vals[1] = dvpMoveSpecial(b);
            vals[2] = dvpClericLvl(b);
            vals[3] = dvpDruidLvl(b);
            vals[4] = dvpFightLvl(b);
            vals[5] = dvpFightKind(b);
            vals[6] = dvpMuLvl(b);
            vals[7] = dvpIllusLvl(b);
            vals[8] = dvpThiefLvl(b);
            vals[9] = dvpAssassinLvl(b);
            vals[10] = dvpMonkLvl(b);
            vals[11] = dvpBardLvl(b);
            for (int c = 0; c < 12;
                 ++c) {
                if (vals[c] != CDvpClassLines[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nDvpClassLines[c];
            }
        }
        for (int c = 0; c < 12; ++c)
            if (nDvpClassLines[c] != eDvpClassLines[c])
                ++bad;
        // the 23 x 13 ability-line grid - the seven ability lines and the
        // DAMAGE/ATTACK bonus, in the R405/R406 registry order (the -1
        // sentinel census rides the twenty no-percentile strengths, Hanali's
        // special CH parenthetical, and the two see-below damage reads)
        int CDvpStatLines[23][13] = {
            {25,-1,7,14,20,19,20,25,16,22,13,20,14},
            {22,-1,4,10,23,20,23,25,18,24,18,24,10},
            {25,-1,7,14,23,25,20,25,18,24,13,16,14},
            {24,-1,6,12,22,16,24,24,8,14,7,13,12},
            {21,-1,4,9,25,25,20,25,19,25,20,25,9},
            {8,-1,0,0,24,22,24,19,23,0,25,0,0},
            {19,-1,3,7,23,16,25,20,24,0,25,0,7},
            {21,-1,4,9,22,21,25,21,23,0,22,0,0},
            {15,-1,0,0,23,23,25,20,25,-1,30,0,0},
            {12,-1,0,0,25,25,19,18,24,0,25,0,-1},
            {18,0,3,6,22,25,22,24,22,0,24,0,6},
            {20,-1,0,0,21,23,24,23,21,0,21,0,8},
            {17,-1,1,1,23,24,24,23,22,0,21,0,0},
            {19,-1,3,7,24,17,25,23,20,0,19,0,7},
            {18,0,3,6,21,19,25,22,22,0,16,0,6},
            {19,-1,3,7,20,14,20,24,3,0,-14,0,7},
            {18,1,1,3,22,23,18,24,20,0,15,0,3},
            {22,-1,4,10,18,20,17,23,18,0,16,0,10},
            {25,-1,7,14,6,6,18,25,5,22,-2,16,15},
            {20,-1,3,8,19,15,24,19,7,24,8,20,8},
            {23,-1,5,11,17,14,20,23,8,25,5,24,11},
            {18,-1,1,2,18,11,10,17,-4,0,-25,0,-1},
            {19,-1,3,7,18,19,14,20,12,25,3,24,7},
            };
        int nDvpStatLines[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
        int eDvpStatLines[13] = {0,20,0,0,0,0,0,0,0,1,0,0,2};
        for (int b = 0;
             b < dvpDeityRowCount();
             ++b) {
            int vals[13];
            vals[0] = dvpStrBase(b);
            vals[1] = dvpStrPct(b);
            vals[2] = dvpStrHit(b);
            vals[3] = dvpStrDmg(b);
            vals[4] = dvpIntBase(b);
            vals[5] = dvpWisBase(b);
            vals[6] = dvpDexBase(b);
            vals[7] = dvpConBase(b);
            vals[8] = dvpChaBase(b);
            vals[9] = dvpChaParen(b);
            vals[10] = dvpComBase(b);
            vals[11] = dvpComParen(b);
            vals[12] = dvpDmgBonus(b);
            for (int c = 0; c < 13;
                 ++c) {
                if (vals[c] != CDvpStatLines[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nDvpStatLines[c];
            }
        }
        for (int c = 0; c < 13; ++c)
            if (nDvpStatLines[c] != eDvpStatLines[c])
                ++bad;
        // the damage bonus equals the S parenthetical damage bonus on the 15
        // rows that print both
    if (dvpDmgBonus(0) != dvpStrDmg(0)
            || dvpDmgBonus(1) != dvpStrDmg(1)
            || dvpDmgBonus(2) != dvpStrDmg(2)
            || dvpDmgBonus(3) != dvpStrDmg(3)
            || dvpDmgBonus(4) != dvpStrDmg(4)
            || dvpDmgBonus(6) != dvpStrDmg(6)
            || dvpDmgBonus(10) != dvpStrDmg(10)
            || dvpDmgBonus(13) != dvpStrDmg(13)
            || dvpDmgBonus(14) != dvpStrDmg(14)
            || dvpDmgBonus(15) != dvpStrDmg(15)
            || dvpDmgBonus(16) != dvpStrDmg(16)
            || dvpDmgBonus(17) != dvpStrDmg(17)
            || dvpDmgBonus(19) != dvpStrDmg(19)
            || dvpDmgBonus(20) != dvpStrDmg(20)
            || dvpDmgBonus(22) != dvpStrDmg(22)
        )
            ++bad;
        // the three refusing prints pin as they stand (Arvoreen +8/no paren,
        // Bahgtru +15 vs +14, Solonor S +9/no bonus)
    if (dvpDmgBonus(11) != 8
            || dvpStrDmg(11) != 0
            || dvpDmgBonus(18) != 15
            || dvpStrDmg(18) != 14
            || dvpDmgBonus(7) != 0
            || dvpStrDmg(7) != 9
        )
            ++bad;
        // the orc monster-read census (kind 13 on all five FIGHTER lines) and
        // the row/feeder keys
    if (dvpFightKind(18) != 13
            || dvpFightKind(19) != 13
            || dvpFightKind(20) != 13
            || dvpFightKind(21) != 13
            || dvpFightKind(22) != 13
            || dvpDeityRowCount() != 23
            || dvpStatBlockFeederRound() != 406
            || dvpClassLineCount() != 5
            || dvpAbilityLineCount() != 7
        )
            ++bad;
        // the see-text sentinel rows and the special CH (Dumathoin, Aerdrie,
        // Yurtrus magic-user; Hanali)
    if (dvpMuLvl(2) != -1
            || dvpMuLvl(5) != -1
            || dvpMuLvl(21) != -1
            || dvpChaParen(8) != -1
            || dvpDmgBonus(9) != -1
            || dvpDmgBonus(21) != -1
        )
            ++bad;
        printf("R783 deity stat lines audit: bad %d\n", bad);
        if (bad) return 1;
    }
