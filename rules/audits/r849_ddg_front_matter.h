    // ---- R849 DDG front matter audit ----
    // THE DDG FRONT MATTER - the D&DG arc opener, print pp. 1-11: the title
    // page, foreword, contents, preface, credits, the explanatory notes with
    // the seven over-18 ability grids and the psionic class table, the
    // standard divine abilities, the DMing doctrine with the intervention
    // modifiers, the clerics and spell-granting ladder, the omens, the
    // soul/spirit mortality doctrine, and the divine ascension requirements.
    // Zero registry defs touched; the floor holds at 995. The physical-copy
    // eyeball adjudications: the strength 23 damage +11 and the psionic class
    // V lettered modes.
    {
        using namespace rules;
        int bad = 0;
    if (dgaRound() != 849
            || dgaPrintYear() != 1980
            || dgaMythoiCount() != 17
            || dgaFrontMatterStart() != 1
            || dgaFrontMatterEnd() != 11
            || dgaTableCount() != 9
            || dgaChainCount() != 1
            || dgaRegistryFloor() != 995
            || dgaStrRows() != 7
            || dgaWisRows() != 7
            || dgaIntRows() != 7
            || dgaDexRows() != 7
            || dgaConRows() != 7
            || dgaChaRows() != 7
            || dgaHorrorRows() != 7
            || dgaPsiRows() != 6
            || dgaIntModsRows() != 6
            || dgaPantheonLeadersHp() != 400
            || dgaFreqVeryRare() != 4
            || dgaFreqRare() != 11
            || dgaFreqUncommon() != 20
            || dgaFreqCommon() != 65
            || dgaMrCasterBase() != 11
            || dgaMrPerLevel() != 5
            || dgaLevelFloorDemi() != 15
            || dgaLevelFloorLesser() != 20
            || dgaLevelFloorGreater() != 25
            || dgaStdAbilities() != 8
            || dgaCommandLesser() != 2
            || dgaCommandGreater() != 3
            || dgaGeasRange() != 9
            || dgaQuestRange() != 9
            || dgaInterventionBase() != 10
            || dgaGodSave() != 2
            || dgaHeroSave() != 3
            || dgaDivineRanks() != 3
            || dgaDemigodMaxSpell() != 5
            || dgaSoulRaces() != 5
            || dgaDeathLagMin() != 3
            || dgaDeathLagMax() != 30
            || dgaSpiritRestMin() != 10
            || dgaSpiritRestMax() != 1000
            || dgaRestDemonsCentury() != 100
            || dgaRestPrincesMin() != 2
            || dgaRestPrincesMax() != 8
            || dgaRestGreaterMin() != 1
            || dgaRestGreaterMax() != 4
            || dgaAscensionReqts() != 4
            || dgaAscAvg5Min() != 9
            || dgaAscAvg5Max() != 10
            || dgaAscAvg15Min() != 25
            || dgaAscAvg15Max() != 30
            || dgaWishAgingYears() != 3
            || dgaOmenWispDays() != 7
            || dgaPsiClasses() != 6
            || !dgaNotSupplement()
            || !dgaForewordPantheonSelection()
            || !dgaDemigodsIncluded()
            || !dgaMatchForDeitiesAscended()
            || !dgaThreeFourthsSourced()
            || !dgaScaledDown()
            || !dgaBeginningFramework()
            || !dgaChaosiumCredit()
            || !dgaSecondPrinting()
            || !dgaFreqUnique()
            || !dgaNumAppearingGuideline()
            || !dgaAcMagicalNature()
            || !dgaMoveTwoMediums()
            || !dgaInfiniteMoveTeleport()
            || !dgaDeityHpBanish()
            || !dgaMrStandardDoctrine()
            || !dgaMrPossessionsOnly()
            || !dgaMrAreaEffectNote()
            || !dgaMrSavesStillApply()
            || !dgaClassGridDoctrine()
            || !dgaHitPointsNotDice()
            || !dgaWisdomSpellBonusesApply()
            || !dgaDruidNeedNotNeutral()
            || !dgaMultiClassInconsistent()
            || !dgaMagicLevelFloor()
            || !dgaStrengthParen()
            || !dgaDeityAlignmentLoose()
            || !dgaClericAlignIdentical()
            || !dgaSizeThreeFold()
            || !dgaIntIllusionCumulative()
            || !dgaIntNeverFooled()
            || !dgaWisdomImmunitiesCumulative()
            || !dgaWisdomAutoThrowOff()
            || !dgaDexThiefColsNote()
            || !dgaConRerollDoctrine()
            || !dgaConNonFighterCap2()
            || !dgaAweDivineOnly()
            || !dgaAweStunNoSave()
            || !dgaAweStunnedDefendOnly()
            || !dgaHorrorDivineOnly()
            || !dgaHorrorDefendOnly()
            || !dgaNegativeChaNoHenchmen()
            || !dgaPsionicLevelFloor()
            || !dgaCommandNoSave()
            || !dgaComprehendSpeakWrite()
            || !dgaDetectAlignNoError()
            || !dgaGateSameMythos()
            || !dgaQuestNoSave()
            || !dgaTeleportNoError()
            || !dgaAbilitiesAtWillNotContinuous()
            || !dgaBonusPowersDmJudgment()
            || !dgaPowerFromWorshipers()
            || !dgaRaisedAbilitiesNoDivine()
            || !dgaGodsNotMonsterLists()
            || !dgaFlatterySeenThrough()
            || !dgaInt20PredictsAction()
            || !dgaAvoidDefeatTeleport()
            || !dgaSummonAidDepart()
            || !dgaDeitiesAvoidEachOther()
            || !dgaGateBringsServants()
            || !dgaSpecificAidRare()
            || !dgaEvilGodsAppearForConverts()
            || !dgaInterventionNoWhim()
            || !dgaFirstRequestRule()
            || !dgaDeityComesOn00()
            || !dgaCharactersBecomeIntervention()
            || !dgaInterventionPrimeOnly()
            || !dgaInterventionNoOuterPlanes()
            || !dgaInterventionNotPosNeg()
            || !dgaInterventionElementalDmOption()
            || !dgaInterventionOccasionalAstral()
            || !dgaSpells12KnowledgeFaith()
            || !dgaSpells345ServantsMinions()
            || !dgaDemigodDirect345()
            || !dgaDemigodNo67()
            || !dgaSixthSeventhFromDeity()
            || !dgaSeventhGreaterOnly()
            || !dgaRankAlterable()
            || !dgaSavesIrreducible()
            || !dgaClericExemplary()
            || !dgaClericRitualsRequired()
            || !dgaClericTempleBuilding()
            || !dgaMinorTransgressionWarningOmen()
            || !dgaSpellsDeniedDuringAtonement()
            || !dgaGraveSinAllPossessions()
            || !dgaExcommunicationTotal()
            || !dgaOmensCorrectionDevices()
            || !dgaOmenPartialPowerLoss()
            || !dgaOmenEscalation()
            || !dgaOmenResultsOptional()
            || !dgaOmenGoodPortents()
            || !dgaOmenGoodSymbols()
            || !dgaOmenMistletoe()
            || !dgaOmenLeatherRepels()
            || !dgaOmenDung()
            || !dgaOmenMirrorSalt()
            || !dgaOmenCelestials()
            || !dgaOmenOldWoman()
            || !dgaOmenBatWindow()
            || !dgaOmenTripping()
            || !dgaOmenBirdOnSymbol()
            || !dgaOmenCrossedKnives()
            || !dgaOmenThirteen()
            || !dgaOmenWispFire()
            || !dgaOmenBanshee()
            || !dgaOmenRainbow()
            || !dgaOmenBifrost()
            || !dgaSoulSpiritDoctrine()
            || !dgaSpiritMinIntLow()
            || !dgaSoulPlaneDmChoice()
            || !dgaSoulEternalResident()
            || !dgaSpiritRewardsLess()
            || !dgaSpiritReincarnation()
            || !dgaRaisedLimitRationale()
            || !dgaAstralPerilDoctrine()
            || !dgaResurrectionCooperation()
            || !dgaServantsAreSpirits()
            || !dgaImmortalityEternalYouth()
            || !dgaLongevityPotionReversal()
            || !dgaSilverCordUnbreakable()
            || !dgaCordPullNearInstant()
            || !dgaDeityDeathFades()
            || !dgaDormancyBlocksSpells()
            || !dgaDormancyReadAsOmen()
            || !dagaDeityNeverAdmitsDefeat()
            || !dgaHomePlaneDeathAbsolute()
            || !dgaHomePlaneDeityNearImpossible()
            || !dgaAscLevelAboveAverage()
            || !dgaAscAbilitiesRaised()
            || !dgaAscSincereWorshipers()
            || !dgaAscFaithfulFollower()
            || !dgaAscDivineQuests()
            || !dgaServantCenturiesToDemigod()
            || !dgaAscensionRemovesFromCampaign()
        )
            ++bad;
        // the strength table for scores above 18 (print p. 6) - the 23 row
        // damage +11 is the physical-copy adjudicated cell
        int CStr[7][9] = {
            {19,3,7,4500,7,8,3,0,50},
            {20,3,8,5000,7,8,3,0,60},
            {21,4,9,6000,9,10,4,0,70},
            {22,4,10,7500,11,12,4,0,80},
            {23,5,11,9000,11,12,5,0,90},
            {24,6,12,12000,19,20,7,8,100},
            {25,7,14,15000,23,24,9,10,100},
            };
        int nStr[9] = {0,0,0,0,0,0,0,0,0};
        int eStr[9] = {0,0,0,0,0,0,0,5,0};
        for (int b = 0;
             b < dgaStrRows();
             ++b) {
            int vals[9];
            vals[0] = dgaStrScore(b);
            vals[1] = dgaStrToHit(b);
            vals[2] = dgaStrDmg(b);
            vals[3] = dgaStrWt(b);
            vals[4] = dgaStrOdN(b);
            vals[5] = dgaStrOdD(b);
            vals[6] = dgaStrOdPn(b);
            vals[7] = dgaStrOdPd(b);
            vals[8] = dgaStrBendPct(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CStr[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nStr[c];
            }
        }
        for (int c = 0; c < 9; ++c)
            if (nStr[c] != eStr[c])
                ++bad;
        // the wisdom spell bonus table for scores above 18 (print p. 7)
        int CWis[7][5] = {
            {19,4,1,1,1},
            {20,4,1,2,1},
            {21,5,1,3,1},
            {22,5,1,4,1},
            {23,5,2,0,0},
            {24,6,2,0,0},
            {25,7,1,6,1},
            };
        int nWis[5] = {0,0,0,0,0};
        int eWis[5] = {0,0,0,2,2};
        for (int b = 0;
             b < dgaWisRows();
             ++b) {
            int vals[5];
            vals[0] = dgaWisScore(b);
            vals[1] = dgaWisHiLvl(b);
            vals[2] = dgaWisHiCnt(b);
            vals[3] = dgaWisLoLvl(b);
            vals[4] = dgaWisLoCnt(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CWis[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nWis[c];
            }
        }
        for (int c = 0; c < 5; ++c)
            if (nWis[c] != eWis[c])
                ++bad;
        // the intelligence table for scores above 18 (print p. 7)
        int CInt[7][4] = {
            {19,95,11,1},
            {20,96,12,2},
            {21,97,13,3},
            {22,98,14,4},
            {23,99,15,5},
            {24,100,16,6},
            {25,100,17,7},
            };
        for (int b = 0;
             b < dgaIntRows();
             ++b) {
            int vals[4];
            vals[0] = dgaIntScore(b);
            vals[1] = dgaIntKnowPct(b);
            vals[2] = dgaIntMinSpells(b);
            vals[3] = dgaIntIllusLvl(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CInt[b][c])
                    ++bad;
            }
        }
        // the dexterity table for scores above 18 (print p. 7) - the five
        // thief columns per the note bool
        int CDex[7][8] = {
            {19,3,-4,15,20,10,12,12},
            {20,3,-4,20,25,15,15,15},
            {21,4,-5,25,30,20,18,18},
            {22,4,-5,30,35,25,20,20},
            {23,4,-5,35,40,30,23,23},
            {24,5,-6,40,45,35,25,25},
            {25,5,-6,45,50,40,30,30},
            };
        for (int b = 0;
             b < dgaDexRows();
             ++b) {
            int vals[8];
            vals[0] = dgaDexScore(b);
            vals[1] = dgaDexReact(b);
            vals[2] = dgaDexDef(b);
            vals[3] = dgaDexPockets(b);
            vals[4] = dgaDexLocks(b);
            vals[5] = dgaDexTraps(b);
            vals[6] = dgaDexSilent(b);
            vals[7] = dgaDexHide(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != CDex[b][c])
                    ++bad;
            }
        }
        // the constitution table for scores above 18 (print p. 7)
        int CCon[7][4] = {
            {19,5,1,0},
            {20,5,1,6},
            {21,6,2,5},
            {22,6,2,4},
            {23,6,3,3},
            {24,7,3,2},
            {25,7,4,1},
            };
        int nCon[4] = {0,0,0,0};
        int eCon[4] = {0,0,0,1};
        for (int b = 0;
             b < dgaConRows();
             ++b) {
            int vals[4];
            vals[0] = dgaConScore(b);
            vals[1] = dgaConHpAdj(b);
            vals[2] = dgaConPoisonSave(b);
            vals[3] = dgaConRegenTurns(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CCon[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nCon[c];
            }
        }
        for (int c = 0; c < 4; ++c)
            if (nCon[c] != eCon[c])
                ++bad;
        // the charisma table for scores above 18 (print p. 7) - the awe
        // doctrine per the bools
        int CCha[7][5] = {
            {19,20,50,40,1},
            {20,25,60,45,2},
            {21,30,70,50,4},
            {22,35,80,55,6},
            {23,40,90,60,8},
            {24,45,100,65,10},
            {25,50,100,70,12},
            };
        for (int b = 0;
             b < dgaChaRows();
             ++b) {
            int vals[5];
            vals[0] = dgaChaScore(b);
            vals[1] = dgaChaHench(b);
            vals[2] = dgaChaLoyalty(b);
            vals[3] = dgaChaReact(b);
            vals[4] = dgaChaAweHd(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CCha[b][c])
                    ++bad;
            }
        }
        // the negative charisma horror table (print p. 7) - the
        // ghastly-divine-being doctrine
        int CHor[7][3] = {
            {-1,-40,1},
            {-2,-45,2},
            {-3,-50,4},
            {-4,-55,6},
            {-5,-60,8},
            {-6,-65,10},
            {-7,-70,12},
            };
        for (int b = 0;
             b < dgaHorrorRows();
             ++b) {
            int vals[3];
            vals[0] = dgaHorScore(b);
            vals[1] = dgaHorReact(b);
            vals[2] = dgaHorHd(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CHor[b][c])
                    ++bad;
            }
        }
        // the six standardized psionic classes (print p. 6) - classes I-IV
        // All/All, class V the lettered modes, class VI the asterisked Nil
        // row
        int CPsi[6][7] = {
            {1,326,365,5,2,5,5},
            {2,276,315,4,2,5,5},
            {3,236,265,3,2,5,5},
            {4,181,210,3,1,5,5},
            {5,91,110,2,1,4,3},
            {6,0,0,0,0,0,0},
            };
        int nPsi[7] = {0,0,0,0,0,0,0};
        int ePsi[7] = {0,1,1,1,1,1,1};
        for (int b = 0;
             b < dgaPsiRows();
             ++b) {
            int vals[7];
            vals[0] = dgaPsiCls(b);
            vals[1] = dgaPsiStrLo(b);
            vals[2] = dgaPsiStrHi(b);
            vals[3] = dgaPsiMinDis(b);
            vals[4] = dgaPsiMajDis(b);
            vals[5] = dgaPsiAtkCnt(b);
            vals[6] = dgaPsiDefCnt(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CPsi[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nPsi[c];
            }
        }
        for (int c = 0; c < 7; ++c)
            if (nPsi[c] != ePsi[c])
                ++bad;
        // the divine intervention modifiers (print p. 9) - the 00-roll
        // deity-comes chance table
        int CIntMods[6][2] = {
            {1,5},
            {2,5},
            {3,10},
            {4,10},
            {5,1},
            {6,25},
            };
        for (int b = 0;
             b < dgaIntModsRows();
             ++b) {
            int vals[2];
            vals[0] = dgaIntModsOrd(b);
            vals[1] = dgaIntModsPct(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CIntMods[b][c])
                    ++bad;
            }
        }
        // the dgaIntRating band-for boundaries
    if (dgaIntRating(-1) != 0
            || dgaIntRating(0) != 0
            || dgaIntRating(1) != 1
            || dgaIntRating(1) != 1
            || dgaIntRating(4) != 2
            || dgaIntRating(2) != 2
            || dgaIntRating(7) != 3
            || dgaIntRating(5) != 3
            || dgaIntRating(10) != 4
            || dgaIntRating(8) != 4
            || dgaIntRating(12) != 5
            || dgaIntRating(11) != 5
            || dgaIntRating(14) != 6
            || dgaIntRating(13) != 6
            || dgaIntRating(16) != 7
            || dgaIntRating(15) != 7
            || dgaIntRating(18) != 8
            || dgaIntRating(17) != 8
            || dgaIntRating(20) != 9
            || dgaIntRating(19) != 9
            || dgaIntRating(21) != 10
        )
            ++bad;
        // the census walk (the nine grids and the chain)
    if (dgaTableCount() != 9
            || dgaChainCount() != 1
            || dgaStrRows() + dgaWisRows() + dgaIntRows() + dgaDexRows() +
            dgaConRows() + dgaChaRows() + dgaHorrorRows() + dgaPsiRows() +
            dgaIntModsRows() != 61
        )
            ++bad;
        // the front matter bounds (print pp. 1-11)
    if (dgaFrontMatterStart() != 1
            || dgaFrontMatterEnd() != 11
        )
            ++bad;
        // the registry floor census pin (zero defs touched)
    if (dgaRegistryFloor() != 995
        )
            ++bad;
        // the MR worked example (a 95% resistance: the 10th-level caster has
        // no chance, the 12th-level has 10%)
    if (dgaMrCasterBase() != 11
            || dgaMrPerLevel() != 5
            || 95 + dgaMrPerLevel() != 100
            || 95 - dgaMrPerLevel() != 90
        )
            ++bad;
        // the strength 23 adjudicated cell (the physical-copy eyeball: damage
        // +11, not the OCR +1)
    if (dgaStrToHit(4) != 5
            || dgaStrDmg(4) != 11
            || dgaStrWt(4) != 9000
            || dgaStrBendPct(4) != 90
        )
            ++bad;
        // the storm giant and titan rows (the parenthesized open-doors pairs)
    if (dgaStrOdN(5) != 19
            || dgaStrOdD(5) != 20
            || dgaStrOdPn(5) != 7
            || dgaStrOdPd(5) != 8
            || dgaStrOdN(6) != 23
            || dgaStrOdD(6) != 24
            || dgaStrOdPn(6) != 9
            || dgaStrOdPd(6) != 10
        )
            ++bad;
        // the wisdom 25 row (One 6th and one 7th)
    if (dgaWisHiLvl(6) != 7
            || dgaWisHiCnt(6) != 1
            || dgaWisLoLvl(6) != 6
            || dgaWisLoCnt(6) != 1
        )
            ++bad;
        // the wisdom two-spell rows (23 and 24: two 5th, two 6th, no
        // low-level spell)
    if (dgaWisHiCnt(4) != 2
            || dgaWisLoLvl(4) != 0
            || dgaWisHiCnt(5) != 2
            || dgaWisLoLvl(5) != 0
        )
            ++bad;
        // the psionic class V lettered modes (4 attack A,B,C,E; 3 defense
        // F,G,H - the physical-copy adjudication)
    if (dgaPsiAtkCnt(4) != 4
            || dgaPsiDefCnt(4) != 3
            || dgaPsiMinDis(4) != 2
            || dgaPsiMajDis(4) != 1
        )
            ++bad;
        // the intervention modifier extremes (the +1% row and the +25%
        // proximate-service row)
    if (dgaIntModsPct(4) != 1
            || dgaIntModsPct(5) != 25
            || dgaIntModsPct(3) != 10
        )
            ++bad;
        // the saves doctrine (gods 2, heroes 3, irreducible)
    if (dgaGodSave() != 2
            || dgaHeroSave() != 3
        )
            ++bad;
        // the command rounds (lesser 2, greater 3)
    if (dgaCommandLesser() != 2
            || dgaCommandGreater() != 3
        )
            ++bad;
        // the frequency doctrine (4/11/20/65 percent)
    if (dgaFreqVeryRare() != 4
            || dgaFreqRare() != 11
            || dgaFreqUncommon() != 20
            || dgaFreqCommon() != 65
        )
            ++bad;
        // the death lag and rest doctrine (3-30 days; century, 2-8 weeks, 1-4
        // weeks)
    if (dgaDeathLagMin() != 3
            || dgaDeathLagMax() != 30
            || dgaRestDemonsCentury() != 100
            || dgaRestPrincesMin() != 2
            || dgaRestPrincesMax() != 8
            || dgaRestGreaterMin() != 1
            || dgaRestGreaterMax() != 4
        )
            ++bad;
        // the ascension level examples (average 5 gives 9th-10th, average 15
        // gives 25th-30th)
    if (dgaAscAvg5Min() != 9
            || dgaAscAvg5Max() != 10
            || dgaAscAvg15Min() != 25
            || dgaAscAvg15Max() != 30
        )
            ++bad;
        // the intelligence ladder boundary walk (the chain bands)
    if (dgaIntRating(0) != 0
            || dgaIntRating(1) != 1
            || dgaIntRating(2) != 2
            || dgaIntRating(5) != 3
            || dgaIntRating(8) != 4
            || dgaIntRating(11) != 5
            || dgaIntRating(13) != 6
            || dgaIntRating(15) != 7
            || dgaIntRating(17) != 8
            || dgaIntRating(19) != 9
            || dgaIntRating(21) != 10
            || dgaIntRating(25) != 10
        )
            ++bad;
        // the spell-granting ladder (a demigod caps at 5th)
    if (dgaDemigodMaxSpell() != 5
            || dgaDivineRanks() != 3
        )
            ++bad;
        // the will-o-wisp omen (seven days)
    if (dgaOmenWispDays() != 7
        )
            ++bad;
        // the level floors (15/20/25 for both the magic ability and the
        // psionic disciplines)
    if (dgaLevelFloorDemi() != 15
            || dgaLevelFloorLesser() != 20
            || dgaLevelFloorGreater() != 25
        )
            ++bad;
        printf("R849 DDG front matter audit: bad %d\n", bad);
        if (bad) return 1;
    }
