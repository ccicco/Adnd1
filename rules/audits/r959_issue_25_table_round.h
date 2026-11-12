    // ---- R959 issue-25 table round audit ----
    // the two-chain table round audit - the Xochiyaoyotl war game with the
    // scale, the prowess grid, the morale and victory brackets and the
    // Spanish option, and the vampire varieties with the fifteen type roster,
    // the charm adjustments and the call bands
    {
        using namespace rules;
        int bad = 0;
    if (s25MenPerUnit() != 20
            || s25TurnMinutes() != 2
            || s25YardsPerInch() != 25
            || s25FeetPerVerticalInch() != 5
            || s25ProwessRangeLo() != 1
            || s25ProwessRangeHi() != 5
            || s25ProwessDieCount() != 6
            || s25ProwessRatioPct1() != 100
            || s25ProwessRatioPct2() != 90
            || s25ProwessRatioPct3() != 75
            || s25ProwessRatioPct4() != 60
            || s25ProwessRatioPct5() != 50
            || s25LeaderEliteStrength() != 6
            || s25PriestEliteStrength() != 1
            || s25CottonArmorPct() != 25
            || s25DivisionUnits() != 10
            || s25DivisionChainInches() != 2
            || s25LeaderContactInches() != 24
            || s25HiddenRevealInches() != 2
            || s25WeatherPeriodTurns() != 15
            || s25SacrificeWeatherMen() != 60
            || s25SacrificeMoraleMen() != 20
            || s25CaptureMoraleBoost() != 3
            || s25CaptureMoraleTurns() != 15
            || s25MaxAttackersPerTurn() != 6
            || s25PrisonerPriestWaitTurns() != 1
            || s25PrisonerOffFieldWaitTurns() != 2
            || s25VictoryDrawHi() != 50
            || s25VictoryMinimalHi() != 100
            || s25VictoryMarginHi() != 150
            || s25FlowerLeaderCapturePts() != 10
            || s25FlowerEliteCapturePts() != 5
            || s25FlowerManCapturePts() != 3
            || s25FlowerManKilledPenalty() != 1
            || s25SpanishEliteStrength() != 6
            || s25SpanishRatioPct() != 25
            || s25CannonsPerUnit() != 5
            || s25CannonCrewMen() != 20
            || s25SpanishHorseCannonPctMax() != 10
            || s25SpanishLeaderCapturedPts() != 10
            || s25SpanishLeaderKilledPts() != 5
            || s25SpanishManCapturedPts() != 5
            || s25SpanishManKilledPts() != 3
            || s25SpanishSacrificePenaltyPts() != 2
            || s25VampireRosterCount() != 15
            || s25VampireRiseDays() != 7
            || s25AsanbosamManHd() != 9
            || s25AsanbosamWomanHd() != 8
            || s25AsanbosamChildHd() != 7
            || s25AsanbosamCharmAdj() != 3
            || s25AsanbosamLeopardsLo() != 3
            || s25AsanbosamLeopardsHi() != 18
            || s25AsanbosamTigersLo() != 2
            || s25AsanbosamTigersHi() != 12
            || s25BurcolakasRatsLo() != 10
            || s25BurcolakasRatsHi() != 100
            || s25LobishumenCharmAdj() != 4
            || s25LobishumenNymphoPct() != 60
            || s25EkimmuCharmAdj() != 1
            || s25EkimmuDispelBasePct() != 50
            || s25EkimmuDispelLevelPct() != 5
            || s25AnananngelCharmAdj() != 2
            || s25AnananngelFearAdj() != 3
            || s25AnananngelLivingWitchPct() != 50
            || s25AnananngelCureDaysLo() != 2
            || s25AnananngelCureDaysHi() != 7
            || s25AlpButterfliesLo() != 10
            || s25AlpButterfliesHi() != 100
            || s25ChingShihFoxesLo() != 3
            || s25ChingShihFoxesHi() != 18
            || !s25RefereeRecommended()
            || !s25SimultaneousMoves()
            || !s25LeaderLastCaught()
            || !s25PriestsSwordMelee()
            || !s25FiredNoMove()
            || !s25HalfFireHalfMove()
            || !s25SlingStuns()
            || !s25HiddenInRough()
            || !s25DefendDoubles()
            || !s25HindQuarterMultiplier()
            || !s25FlowerLeadersSafe()
            || !s25FlowerDisarmDefendOnly()
            || !s25FlowerSacrificeCountsCaptured()
            || !s25SpanishArmorNotVsGunpowder()
            || !s25NoGunfireInThunderstorm()
            || !s25CannonBannedInSwamp()
            || !s25SpanishColumnMove()
            || !s25MexicanAttackerDisarmOnly()
            || !s25SpanishNoSacrifice()
            || !s25SpanishNotInFlowerWars()
            || !s25SpanishPrisonersFirst()
            || !s25VampiresAvoidWards()
            || !s25NormalWeaponsNoHarm()
            || !s25GaseousFormAllButOne()
            || !s25AsanbosamClericOnly()
            || !s25BurcolakasMimicVoice()
            || !s25BurcolakasNoWolves()
            || !s25LobishumenSuccubi()
            || !s25EkimmuInvisibleAlways()
            || !s25BlautsaugerGraveEarth()
            || !s25MuloPolymorphs()
            || !s25AlpLemonDefeat()
            || !s25AnananngelNotTurnedWhenLiving()
            || !s25KrvopijacFoalSearch()
            || !s25ChingShihRiceDefeat()
            || !s25VlkodlakEclipses()
            || !s25VlkodlakNavelStake()
            || !s25BruxaSunActive()
            || !s25NosferatPolymorphs()
        )
            ++bad;
        // the Military Prowess grid - six die rolls against the five ratings,
        // the die six roll carrying the elite mark at every rating
        int CProwess[6][6] = {
            {1,2,2,3,3,-99},
            {2,2,3,3,4,-99},
            {2,3,3,4,4,-99},
            {3,3,4,4,5,-99},
            {3,4,4,5,5,-99},
            {4,4,5,5,6,1},
            };
        int nProwess[6] = {0,0,0,0,0,0};
        int eProwess[6] = {0,0,0,0,0,5};
        for (int b = 0;
             b < s25ProwessDieCount();
             ++b) {
            int vals[6];
            vals[0] = s25StrengthMp1(b);
            vals[1] = s25StrengthMp2(b);
            vals[2] = s25StrengthMp3(b);
            vals[3] = s25StrengthMp4(b);
            vals[4] = s25StrengthMp5(b);
            vals[5] = s25EliteOnDie(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CProwess[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nProwess[c];
            }
        }
        for (int c = 0; c < 6; ++c)
            if (nProwess[c] != eProwess[c])
                ++bad;
        // the vampire roster grid - the fifteen types in printed order from
        // the common to the nosferat, the printed movement pair and the charm
        // adjustment per row
        int CVamp[15][3] = {
            {12,18,-99},
            {12,0,3},
            {12,18,-99},
            {12,18,2},
            {15,0,4},
            {12,18,1},
            {12,18,3},
            {12,18,2},
            {0,24,-99},
            {0,24,2},
            {12,18,-99},
            {12,-99,-99},
            {12,18,-99},
            {12,18,-99},
            {12,18,2},
            };
        int nVamp[3] = {0,0,0};
        int eVamp[3] = {0,1,7};
        for (int b = 0;
             b < s25VampireRosterCount();
             ++b) {
            int vals[3];
            vals[0] = s25VampMove(b);
            vals[1] = s25VampMoveAlt(b);
            vals[2] = s25VampCharmAdj(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CVamp[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nVamp[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nVamp[c] != eVamp[c])
                ++bad;
        // the scales - twenty men a unit, two minutes a turn, twenty five
        // yards the horizontal inch, five feet the vertical, prowess one to
        // fivethe Xochiyaoyotl war game rules (print 37-40)
    if (s25MenPerUnit() != 20
            || s25TurnMinutes() != 2
            || s25YardsPerInch() != 25
            || s25FeetPerVerticalInch() != 5
            || s25ProwessRangeLo() != 1
            || s25ProwessRangeHi() != 5
        )
            ++bad;
        // the prowess ratios - the full count, nine tenths, three quarters,
        // three fifths and half the menthe Xochiyaoyotl war game rules (print
        // 37-40)
    if (s25ProwessRatioPct1() != 100
            || s25ProwessRatioPct2() != 90
            || s25ProwessRatioPct3() != 75
            || s25ProwessRatioPct4() != 60
            || s25ProwessRatioPct5() != 50
        )
            ++bad;
        // the elites - the Mexican leader and the whole Spanish host at six,
        // the priest at one, the Spanish ratio a quarterthe Xochiyaoyotl war
        // game rules (print 37-40)
    if (s25LeaderEliteStrength() != 6
            || s25PriestEliteStrength() != 1
            || s25SpanishEliteStrength() != 6
            || s25SpanishRatioPct() != 25
        )
            ++bad;
        // the victory scale - the draw, minimal and victory bands with the
        // War of Flowers pointsthe Xochiyaoyotl war game rules (print 37-40)
    if (s25VictoryDrawHi() != 50
            || s25VictoryMinimalHi() != 100
            || s25VictoryMarginHi() != 150
            || s25FlowerLeaderCapturePts() != 10
            || s25FlowerEliteCapturePts() != 5
            || s25FlowerManCapturePts() != 3
            || s25FlowerManKilledPenalty() != 1
        )
            ++bad;
        // the discipline set - fire or move, the half measure, the doubled
        // defense, the rear multiplier and the War of Flowers lawsthe
        // Xochiyaoyotl war game rules (print 37-40)
    if (s25FiredNoMove() != 1
            || s25HalfFireHalfMove() != 1
            || s25DefendDoubles() != 1
            || s25HindQuarterMultiplier() != 1
            || s25FlowerLeadersSafe() != 1
            || s25FlowerDisarmDefendOnly() != 1
            || s25FlowerSacrificeCountsCaptured() != 1
        )
            ++bad;
        // the Spanish option - the armor flaw, the thunderstorm ban, the
        // swamp ban, the column, the Mexican limits and the prisoner lawsthe
        // Xochiyaoyotl war game rules (print 37-40)
    if (s25SpanishArmorNotVsGunpowder() != 1
            || s25NoGunfireInThunderstorm() != 1
            || s25CannonBannedInSwamp() != 1
            || s25SpanishColumnMove() != 1
            || s25MexicanAttackerDisarmOnly() != 1
            || s25SpanishNoSacrifice() != 1
            || s25SpanishNotInFlowerWars() != 1
            || s25SpanishPrisonersFirst() != 1
        )
            ++bad;
        // the frame - fifteen types on the roster, the unguarded corpse
        // rising within seven daysthe R.P. Smith vampire varieties (print 42)
    if (s25VampireRosterCount() != 15
            || s25VampireRiseDays() != 7
        )
            ++bad;
        // the asanbosam - nine, eight and seven hit dice, the charm at minus
        // three, the leopards and the tigers calledthe R.P. Smith vampire
        // varieties (print 42)
    if (s25AsanbosamManHd() != 9
            || s25AsanbosamWomanHd() != 8
            || s25AsanbosamChildHd() != 7
            || s25AsanbosamCharmAdj() != 3
            || s25AsanbosamLeopardsLo() != 3
            || s25AsanbosamLeopardsHi() != 18
            || s25AsanbosamTigersLo() != 2
            || s25AsanbosamTigersHi() != 12
        )
            ++bad;
        // the mid roster - the rat swarm, the lobishumen charm and legacy,
        // the ekimmu charm and the exorcism oddsthe R.P. Smith vampire
        // varieties (print 42)
    if (s25BurcolakasRatsLo() != 10
            || s25BurcolakasRatsHi() != 100
            || s25LobishumenCharmAdj() != 4
            || s25LobishumenNymphoPct() != 60
            || s25EkimmuCharmAdj() != 1
            || s25EkimmuDispelBasePct() != 50
            || s25EkimmuDispelLevelPct() != 5
        )
            ++bad;
        // the far roster - the anananngel charm, fear, coin and cure, the alp
        // butterflies and the Chinese vampire foxesthe R.P. Smith vampire
        // varieties (print 42)
    if (s25AnananngelCharmAdj() != 2
            || s25AnananngelFearAdj() != 3
            || s25AnananngelLivingWitchPct() != 50
            || s25AnananngelCureDaysLo() != 2
            || s25AnananngelCureDaysHi() != 7
            || s25AlpButterfliesLo() != 10
            || s25AlpButterfliesHi() != 100
            || s25ChingShihFoxesLo() != 3
            || s25ChingShihFoxesHi() != 18
        )
            ++bad;
        // the common laws with the asanbosam end and the lobishumen doomthe
        // R.P. Smith vampire varieties (print 42)
    if (s25VampiresAvoidWards() != 1
            || s25NormalWeaponsNoHarm() != 1
            || s25GaseousFormAllButOne() != 1
            || s25AsanbosamClericOnly() != 1
            || s25LobishumenSuccubi() != 1
            || s25EkimmuInvisibleAlways() != 1
        )
            ++bad;
        // the prowess grid corners - die one through die six at both ratio
        // ends with the elite mark on the last rollthe Xochiyaoyotl war game
        // rules (print 37-40)
    if (s25StrengthMp1(0) != 1
            || s25StrengthMp1(5) != 4
            || s25StrengthMp5(0) != 3
            || s25StrengthMp5(5) != 6
            || s25EliteOnDie(4) != -99
            || s25EliteOnDie(5) != 1
        )
            ++bad;
        // the roster corners - the common pair, the alp flight, the
        // single-move Chinese vampire, the lobishumen charm and the nosferat
        // charmthe R.P. Smith vampire varieties (print 42)
    if (s25VampMove(0) != 12
            || s25VampMoveAlt(0) != 18
            || s25VampMove(8) != 0
            || s25VampMoveAlt(8) != 24
            || s25VampMoveAlt(11) != -99
            || s25VampCharmAdj(4) != 4
            || s25VampCharmAdj(14) != 2
        )
            ++bad;
        printf("R959 issue-25 table round audit: bad %d\n", bad);
        if (bad) return 1;
    }
