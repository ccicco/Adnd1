    // ---- R635 OA effects of honor audit ----
    // OA round twenty-two (capture pp. 70-72): the altering family honor
    // prose, the effects of honor doctrines and the Table 42 grid
    {
        using namespace rules;
        int bad = 0;
    if (dgvT42RowCount() != 68
            || dgvFamilyRaiseStep() != 10
            || dgvFamilyRaiseAmount() != 1
            || dgvFamilyLossThreshold() != 5
            || dgvFamilyLossAmount() != 1
            || dgvBelowBaseModPct() != -20
            || dgvAboveBaseBonusPct() != 5
            || dgvGiftHonorPoints() != 75
            || dgvSongsHonorPoints() != 80
            || dgvServeHonorPoints() != 90
            || dgvGreatHeroHonorPoints() != 95
            || dgvFoeBoastPct() != 10
            || dgvFoeRefuseHonorLoss() != 10
            || dgvServeRefusePct() != -10
            || dgvGreatHeroBonusPct() != 10
            || dgvSuccessorDivisor() != 10
            || dgvSuccessorMaxPerRoll() != 3
            || dgvMonsterXpPerPoint() != 2000
            || dgvStolenChienPerPoint() != 100
            || !dgvClanFortunesFollow()
            || !dgvRaiseOncePerGroup()
            || !dgvRaiseAtMaxHonor()
            || !dgvLossBlotsFamily()
            || !dgvFamilyShareChange()
            || !dgvEffectsAutomatic()
            || !dgvBelowZeroOut()
            || !dgvSamuraiKensaiStatus()
            || !dgvBelowBaseFamilyMod()
            || !dgvHarderToImpress()
            || !dgvGiftFromLord()
            || !dgvSongsAndBoasts()
            || !dgvLordInvitation()
            || !dgvGreatHeroRead()
            || !dgvSuccessorBonus()
            || !dgvSuccessorLimits()
            || !dgvSuccessorFreedom()
            || !dgvKensaiDuelOncePerLevel()
            || !dgvSamuraiDoubleAwards()
            || !dgvSingleCreatureRead()
        )
            ++bad;
        // the Table 42 grid: the deed awards and the footnote marks (capture
        // p. 72)
        int CT42[68][2] = {
            {-4,0},
            {1,0},
            {5,0},
            {-5,0},
            {-10,1},
            {-4,1},
            {5,0},
            {-10,0},
            {2,1},
            {-1,0},
            {-1,2},
            {-2,0},
            {7,0},
            {1,0},
            {1,0},
            {-10,0},
            {-5,1},
            {-1,0},
            {-2,0},
            {1,0},
            {1,0},
            {-3,0},
            {-2,0},
            {-2,0},
            {-2,0},
            {-2,0},
            {5,0},
            {-2,1},
            {-30,0},
            {-1,0},
            {-1,0},
            {-1,0},
            {-3,0},
            {-1,0},
            {1,0},
            {-3,0},
            {-2,0},
            {-5,0},
            {-5,0},
            {-1,0},
            {3,0},
            {1,0},
            {3,0},
            {-10,0},
            {-30,0},
            {-5,0},
            {-3,0},
            {-10,0},
            {1,0},
            {-1,0},
            {-4,0},
            {3,0},
            {-5,0},
            {-10,0},
            {-10,0},
            {-3,0},
            {-1,0},
            {1,0},
            {-3,0},
            {-1,0},
            {-1,0},
            {-10,0},
            {-5,0},
            {2,0},
            {-2,0},
            {5,0},
            {-3,0},
            {1,0},
            };
        int nT42[2] = {0,0};
        int eT42[2] = {0,0};
        for (int b = 0;
             b < dgvT42RowCount();
             ++b) {
            int vals[2];
            vals[0] = dgvT42Points(b);
            vals[1] = dgvT42Mark(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CT42[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT42[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nT42[c] != eT42[c])
                ++bad;
        // the dgvT42RowCount pin
    if (dgvT42RowCount() != 68
        )
            ++bad;
        // the dgvFamilyRaiseStep pin
    if (dgvFamilyRaiseStep() != 10
        )
            ++bad;
        // the dgvFamilyRaiseAmount pin
    if (dgvFamilyRaiseAmount() != 1
        )
            ++bad;
        // the dgvFamilyLossThreshold pin
    if (dgvFamilyLossThreshold() != 5
        )
            ++bad;
        // the dgvFamilyLossAmount pin
    if (dgvFamilyLossAmount() != 1
        )
            ++bad;
        // the dgvBelowBaseModPct pin
    if (dgvBelowBaseModPct() != -20
        )
            ++bad;
        // the dgvAboveBaseBonusPct pin
    if (dgvAboveBaseBonusPct() != 5
        )
            ++bad;
        // the dgvGiftHonorPoints pin
    if (dgvGiftHonorPoints() != 75
        )
            ++bad;
        // the dgvSongsHonorPoints pin
    if (dgvSongsHonorPoints() != 80
        )
            ++bad;
        // the dgvServeHonorPoints pin
    if (dgvServeHonorPoints() != 90
        )
            ++bad;
        // the dgvGreatHeroHonorPoints pin
    if (dgvGreatHeroHonorPoints() != 95
        )
            ++bad;
        // the dgvFoeBoastPct pin
    if (dgvFoeBoastPct() != 10
        )
            ++bad;
        // the dgvFoeRefuseHonorLoss pin
    if (dgvFoeRefuseHonorLoss() != 10
        )
            ++bad;
        // the dgvServeRefusePct pin
    if (dgvServeRefusePct() != -10
        )
            ++bad;
        // the dgvGreatHeroBonusPct pin
    if (dgvGreatHeroBonusPct() != 10
        )
            ++bad;
        // the dgvSuccessorDivisor pin
    if (dgvSuccessorDivisor() != 10
        )
            ++bad;
        // the dgvSuccessorMaxPerRoll pin
    if (dgvSuccessorMaxPerRoll() != 3
        )
            ++bad;
        // the dgvMonsterXpPerPoint pin
    if (dgvMonsterXpPerPoint() != 2000
        )
            ++bad;
        // the dgvStolenChienPerPoint pin
    if (dgvStolenChienPerPoint() != 100
        )
            ++bad;
        // the dgvClanFortunesFollow pin
    if (dgvClanFortunesFollow() != 1
        )
            ++bad;
        // the dgvRaiseOncePerGroup pin
    if (dgvRaiseOncePerGroup() != 1
        )
            ++bad;
        // the dgvRaiseAtMaxHonor pin
    if (dgvRaiseAtMaxHonor() != 1
        )
            ++bad;
        // the dgvLossBlotsFamily pin
    if (dgvLossBlotsFamily() != 1
        )
            ++bad;
        // the dgvFamilyShareChange pin
    if (dgvFamilyShareChange() != 1
        )
            ++bad;
        // the dgvEffectsAutomatic pin
    if (dgvEffectsAutomatic() != 1
        )
            ++bad;
        // the dgvBelowZeroOut pin
    if (dgvBelowZeroOut() != 1
        )
            ++bad;
        // the dgvSamuraiKensaiStatus pin
    if (dgvSamuraiKensaiStatus() != 1
        )
            ++bad;
        // the dgvBelowBaseFamilyMod pin
    if (dgvBelowBaseFamilyMod() != 1
        )
            ++bad;
        // the dgvHarderToImpress pin
    if (dgvHarderToImpress() != 1
        )
            ++bad;
        // the dgvGiftFromLord pin
    if (dgvGiftFromLord() != 1
        )
            ++bad;
        // the dgvSongsAndBoasts pin
    if (dgvSongsAndBoasts() != 1
        )
            ++bad;
        // the dgvLordInvitation pin
    if (dgvLordInvitation() != 1
        )
            ++bad;
        // the dgvGreatHeroRead pin
    if (dgvGreatHeroRead() != 1
        )
            ++bad;
        // the dgvSuccessorBonus pin
    if (dgvSuccessorBonus() != 1
        )
            ++bad;
        // the dgvSuccessorLimits pin
    if (dgvSuccessorLimits() != 1
        )
            ++bad;
        // the dgvSuccessorFreedom pin
    if (dgvSuccessorFreedom() != 1
        )
            ++bad;
        // the dgvKensaiDuelOncePerLevel pin
    if (dgvKensaiDuelOncePerLevel() != 1
        )
            ++bad;
        // the dgvSamuraiDoubleAwards pin
    if (dgvSamuraiDoubleAwards() != 1
        )
            ++bad;
        // the dgvSingleCreatureRead pin
    if (dgvSingleCreatureRead() != 1
        )
            ++bad;
        // the T42 treason and identity rows - the two -30 awards (capture p.
        // 72)
    if (dgvT42Points(28) != -30
            || dgvT42Points(44) != -30
        )
            ++bad;
        // the T42 family debt row - the +7 best all-character award (capture
        // p. 72)
    if (dgvT42Points(12) != 7
        )
            ++bad;
        // the T42 +5 trio - avenging murder, the great deed, the life saved
        // at great risk (capture p. 72)
    if (dgvT42Points(2) != 5
            || dgvT42Points(6) != 5
            || dgvT42Points(26) != 5
        )
            ++bad;
        // the T42 starred rows - the samurai-doubled marks at prisoner,
        // broken oath, ancestral enemy, lost birthright, served lord (capture
        // p. 72)
    if (dgvT42Mark(4) != 1
            || dgvT42Mark(5) != 1
            || dgvT42Mark(8) != 1
            || dgvT42Mark(16) != 1
            || dgvT42Mark(27) != 1
        )
            ++bad;
        // the T42 monsters row - the -1 per 2000 experience points, single
        // creatures only (capture p. 72)
    if (dgvT42Points(10) != -1
            || dgvT42Mark(10) != 2
            || dgvMonsterXpPerPoint() != 2000
        )
            ++bad;
        // the T42 yakuza rate row - the +1 per 100 ch'ien stolen-goods read
        // (capture p. 72)
    if (dgvT42Points(67) != 1
            || dgvStolenChienPerPoint() != 100
        )
            ++bad;
        // the T42 kensai duel trio - the +1 win, the -3 loss, the -5 refusal
        // (capture p. 72)
    if (dgvT42Points(41) != 1
            || dgvT42Points(35) != -3
            || dgvT42Points(38) != -5
        )
            ++bad;
        // the T42 -10 gravest rows - fleeing a fight, the lost magical item,
        // the ninja-weapon proficiency, the failing mission, the lost minyan
        // (capture p. 72)
    if (dgvT42Points(47) != -10
            || dgvT42Points(53) != -10
            || dgvT42Points(54) != -10
            || dgvT42Points(43) != -10
            || dgvT42Points(61) != -10
        )
            ++bad;
        // the T42 bounds - the -4 accused first row, the +1 stolen-goods last
        // row, sixty-eight rows only (capture p. 72)
    if (dgvT42Points(0) != -4
            || dgvT42Points(67) != 1
            || dgvT42RowCount() != 68
        )
            ++bad;
        // the family ledger doctrine - the 10-point raise step with the +1
        // raise and the once-per-group read, the 5-point blot with the -1
        // loss (capture p. 70)
    if (dgvFamilyRaiseStep() != 10
            || dgvFamilyRaiseAmount() != 1
            || dgvRaiseOncePerGroup() != 1
            || dgvFamilyLossThreshold() != 5
            || dgvFamilyLossAmount() != 1
        )
            ++bad;
        // the effects thresholds - the 75 gift, the 80 songs, the 90
        // invitation, the 95 great hero (capture pp. 71-72)
    if (dgvGiftHonorPoints() != 75
            || dgvSongsHonorPoints() != 80
            || dgvServeHonorPoints() != 90
            || dgvGreatHeroHonorPoints() != 95
        )
            ++bad;
        // the successor doctrine - the remainder divided by 10, the 3-point
        // cap, the freedom of race, class and family (capture p. 72)
    if (dgvSuccessorDivisor() != 10
            || dgvSuccessorMaxPerRoll() != 3
            || dgvSuccessorBonus() != 1
            || dgvSuccessorFreedom() != 1
        )
            ++bad;
        printf("R635 OA effects of honor audit: bad %d\n", bad);
        if (bad) return 1;
    }
