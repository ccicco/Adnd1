    // ---- R372: the UA cavalier
    // followers pin audit ----
    // The UA CAVALIER FOLLOWERS AND
    // HENCHMEN (pp. 74-75): the
    // men-at-arms dice ladder (all
    // d4, 1d4 at 4th through 48d4 at
    // 10th, non-cumulative, no gain
    // if the roll is not higher than
    // the current count), the four
    // equipment percentile rows (the
    // two outfits each, the medium
    // warhorses at 91-00), the
    // leader rules (the 5th-level
    // fighter per 20 troops, the 6th
    // per 60 with the 3rd-level
    // lieutenant, no replacement if
    // slain), the neutral-cause and
    // evil-bandit reads with the 1
    // and 5 percent per level monster
    // chances, the +3/+1 henchman
    // bonus and the alignment type
    // table, the retainer ladder (the
    // prose Knight at 6th flagged
    // against the R368 grid's Knight
    // at 5th), the paladin rules; the
    // R368 seam cross-checks the
    // title and rank cells, the R371
    // seam the armor costs; two
    // items flip CLOSED; the census
    // 298 -> 299.
    {
        using namespace rules;
        int bad = 0;
        // ---- the pinned cells ----
            if (uafolFollowersStartLevel() != 4)
                ++bad;
            if (uafolFollowersTopLevel() != 10)
                ++bad;
            if (uafolDiceSides(4) != 4) ++bad;
            if (uafolDiceSides(10) != 4) ++bad;
            if (uafolDiceSides(3) != 0) ++bad;
            if (uafolDiceSides(11) != 0) ++bad;
            if (uafolDiceCumulative()) ++bad;
            if (!uafolNoGainIfRollNotHigher())
                ++bad;
            if (uafolRowOneJavelinCount() != 3)
                ++bad;
            if (!uafolRowOneLightCavRingMailShield())
                ++bad;
            if (!uafolRowOneHeavyInfScalePoleArmClub())
                ++bad;
            if (!uafolRowTwoSplintMorningStarHandAxe())
                ++bad;
            if (!uafolRowTwoLeatherPikeShortSword())
                ++bad;
            if (!uafolRowThreeHeavyCrossbowShortSword())
                ++bad;
            if (!uafolRowThreeLightCrossbowMilitaryFork())
                ++bad;
            if (!uafolRowFourBandedShieldLanceMace())
                ++bad;
            if (!uafolRowFourStuddedLeatherLongSwordFlail())
                ++bad;
            if (uafolLeaderFighterLevel() != 5)
                ++bad;
            if (uafolLeaderTroopDenominator() != 20)
                ++bad;
            if (uafolSeniorLeaderLevel() != 6)
                ++bad;
            if (uafolSeniorLeaderTroops() != 60)
                ++bad;
            if (uafolLieutenantLevel() != 3)
                ++bad;
            if (!uafolLeadersNotReplacedIfSlain())
                ++bad;
            if (!uafolNeutralSpecificCause())
                ++bad;
            if (!uafolNeutralLeaveIfElsewhere())
                ++bad;
            if (!uafolEvilBanditsBrigands())
                ++bad;
            if (uafolEvilMonsterFollowerPctPerLevel()
                    != 1) ++bad;
            if (uafolEvilMonsterCooperatePctPerLevel()
                    != 5) ++bad;
            if (uafolHenchmanBonusGood() != 3)
                ++bad;
            if (uafolHenchmanBonusOther() != 1)
                ++bad;
            if (!uafolHenchmanGoodPaladins())
                ++bad;
            if (!uafolHenchmanNeutralThieves())
                ++bad;
            if (!uafolHenchmanEvilAssassins())
                ++bad;
            if (uafolRetainerStartLevel() != 4)
                ++bad;
            if (uafolRetainerArmigerLevel() != 1)
                ++bad;
            if (uafolRetainerScutiferLevel() != 2)
                ++bad;
            if (uafolEsquireLevel() != 3) ++bad;
            if (!uafolRetainerKnightProseConflict())
                ++bad;
            if (uafolHeraldGuardLevel() != 7)
                ++bad;
            if (uafolExtraManAtArmsLevel() != 8)
                ++bad;
            if (uafolChevalierTravelFreedomLevel()
                    != 9) ++bad;
            if (!uafolRetainersServeForCareAndUpkeep())
                ++bad;
            if (!uafolPaladinNoFollowers()) ++bad;
            if (!uafolPaladinRetainersMustBeCavaliers())
                ++bad;
        // ---- the dice ladder loops ----
            static const int kCnt[11] = {
                0, 0, 0, 0, 1, 2, 3,
                6, 12, 24, 48};
            for (int l = 4; l <= 10; ++l) {
                if (uafolDiceCount(l) != kCnt[l])
                    ++bad;
                if (uafolFollowersMin(l)
                        != kCnt[l]) ++bad;
                if (uafolFollowersMax(l)
                        != 4 * kCnt[l]) ++bad;
            }
            if (uafolDiceCount(3) != 0) ++bad;
            if (uafolDiceCount(11) != 0) ++bad;
        // ---- the equipment rows ----
            if (uafolEquipRowCount() != 4)
                ++bad;
            static const int kLo[4] = {
                1, 51, 76, 91};
            static const int kHi[4] = {
                50, 75, 90, 100};
            for (int r = 0; r < 4; ++r) {
                if (uafolEquipRowLo(r) != kLo[r])
                    ++bad;
                if (uafolEquipRowHi(r) != kHi[r])
                    ++bad;
                if (r < 3 && kHi[r] + 1
                        != kLo[r + 1]) ++bad;
                if (uafolEquipRowIsCavalry(r)
                        != (r == 0 || r == 3))
                    ++bad;
                if (uafolEquipRowMediumWarhorse(r)
                        != (r == 3)) ++bad;
            }
            if (uafolEquipRowLo(0) != 1) ++bad;
            if (uafolEquipRowHi(3) != 100) ++bad;
        // ---- the retainer ladder order ----
            if (uafolRetainerStartLevel()
                    >= uafolHeraldGuardLevel())
                ++bad;
            if (uafolHeraldGuardLevel()
                    >= uafolExtraManAtArmsLevel())
                ++bad;
            if (uafolExtraManAtArmsLevel()
                    >= uafolChevalierTravelFreedomLevel())
                ++bad;
        // ---- the R368 seam ----
            // the retainer start rides the
            // Knight Errant cell; the 7th
            // the Grand Knight, the 8th the
            // Banneret, the 9th the
            // Chevalier
            if (strcmp(uacavtTitle(
                        uafolRetainerStartLevel()),
                    "Knight Errant") != 0) ++bad;
            if (strcmp(uacavtTitle(
                        uafolHeraldGuardLevel()),
                    "Grand Knight") != 0) ++bad;
            if (strcmp(uacavtTitle(
                        uafolExtraManAtArmsLevel()),
                    "Banneret") != 0) ++bad;
            if (strcmp(uacavtTitle(
                        uafolChevalierTravelFreedomLevel()),
                    "Chevalier") != 0) ++bad;
            // the retainer ranks ride the
            // title ladder cells: the
            // Armiger, the Scutifer, the
            // Esquire, the Horseman, the
            // Lancer
            if (strcmp(uacavtTitle(
                        uafolRetainerArmigerLevel()),
                    "Armiger") != 0) ++bad;
            if (strcmp(uacavtTitle(
                        uafolRetainerScutiferLevel()),
                    "Scutifer") != 0) ++bad;
            if (strcmp(uacavtTitle(
                        uafolEsquireLevel()),
                    "Esquire") != 0) ++bad;
            if (strcmp(uacavtTitle(0),
                    "Horseman") != 0) ++bad;
            if (strcmp(uacavtTitle(-1),
                    "Lancer") != 0) ++bad;
        // ---- the R371 seam ----
            // the equipment rows name the
            // armors the expanded table
            // priced
            if (uaarmRingMailCost() != 30) ++bad;
            if (uaarmScaleMailCost() != 45) ++bad;
            if (uaarmSplintMailCost() != 80) ++bad;
            if (uaarmBandedCost() != 90) ++bad;
            if (uaarmStuddedLeatherCost() != 15)
                ++bad;
        printf("R372 UA cavalier followers pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
