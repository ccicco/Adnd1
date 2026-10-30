    // ---- R934 issue-18 opener part one audit ----
    // THE DRAGON ISSUE-18 OPENER PART ONE - the four system and doctrine
    // chains of the issue. CHAIN ONE, Insanity or Why Is My Character Eating
    // Leaves by Kevin Thompson (print 9, PDF 11): the 9x6 insanity
    // saving-throw chart (nine wisdom bands crossed with six intelligence
    // bands, the unadjusted number, the level added, the d20 roll), the
    // twelve-type insanity chart (Nutty, Kleptomaniac, Perverse, Psychotic
    // Hatred, Childlike Trusting, Schizoid, Severe Paranoia, Acute Paranoia,
    // Gibbering, Suicidal, Violent, Catatonic) with the per-type doctrine
    // (the schizoid d10 each turn reverting on 1, the suicidal d6 attempt on
    // 1, the immediate gibbering, violent and catatonic states, the magic
    // staying functional except when gibbering or catatonic). CHAIN TWO,
    // Magic: Governed by Laws of Theory by Thomas A. McCloud (print 14 + 19,
    // PDF 16 + 21): the six laws (Similarity, Contagion, Mana, Artistry,
    // Obscurity, Harmony), the three parts of the act (the spell, the rite,
    // the condition), the fatigue-factor cast check (the d20 against the
    // fatigue-adjusted intelligence, the backfire on a high roll), and the
    // Kemble magic contest rules (three judges at 1-10 points, two
    // categories, the one-similarity minimum, the flesh golems, the
    // no-black-magic rule). CHAIN THREE, The Chamber of the Godgame by Mick
    // McAllister (print 19, PDF 21): the four-dice hazard (the cyanide die,
    // the 1 roll, the door opening on fulfillment, the escape-proof chamber),
    // the benign, evil and neutral Godgame Master variants, the recompense
    // doctrine (the 2x treasure share, the 2-or-3x experience share, the
    // worked 4,000 GP / 1,500 EP example with its 1,000/375 shares and the
    // 2,000/1,125 reward), the loaded-dice option and the four-dice solitary
    // variant with its crushed-die bitter almonds. CHAIN FOUR, the Non-Player
    // Character Statistics (print 31-32, PDF 33-34): the nine-band pride
    // table (the charisma, constitution, greed-percent and work-percent
    // modifiers from the 01 none band to the 00 egomaniac), the eleven-band
    // greed table (the loan chances and the selling prices from gives-away at
    // 1/10 to never-loans at triple price), the four-band work-quality table
    // (trash at 1-6 uses and 1/10 price, the cheap 1/5-to-1/2 at half
    // lifespan, normal, the sturdy twice-as-long at up to 2-1/2 price), the
    // base percentage method (subtract ten, add the d20, the 00+20 cap), the
    // interest correspondences (0, 5 and 100 percent) and the NPC restriction
    // floors (shop-owner greed 20, spy pride 08, hired thief greed above 21,
    // armorer pride above 13). The pin IS the conversion: OD&D-era ink
    // adjudicated to 1e terms, noted never silent; the as-scanned quirks ride
    // the comments and the transcripts.
    {
        using namespace rules;
        int bad = 0;
    if (psyInsWisBands() != 9
            || psyInsIntBands() != 6
            || psyInsSaveDieSides() != 20
            || psyInsChartDieSides() != 12
            || psyInsChartEntries() != 12
            || psyInsSchizoidDieSides() != 10
            || psyInsSchizoidRevertRoll() != 1
            || psyInsSuicideDieSides() != 6
            || psyInsSuicideAttemptRoll() != 1
            || psyInsSaveRows() != 9
            || psyPrideRows() != 9
            || psyGreedRows() != 11
            || psyLawCount() != 6
            || psyActParts() != 3
            || psyLawFatigueDieSides() != 20
            || psyContestJudges() != 3
            || psyContestPointsMin() != 1
            || psyContestPointsMax() != 10
            || psyContestCategories() != 2
            || psyContestSimilarityMin() != 1
            || psyGodDiceCount() != 4
            || psyGodLosingRoll() != 1
            || psyGodTreasureShareX() != 2
            || psyGodXpShareXLow() != 2
            || psyGodXpShareXHigh() != 3
            || psyGodExPartyGold() != 4000
            || psyGodExPartyXp() != 1500
            || psyGodExShareGold() != 1000
            || psyGodExShareXp() != 375
            || psyGodExRewardGold() != 2000
            || psyGodExRewardXp() != 1125
            || psyGodSoloDiceCount() != 4
            || psyNpcGreedBaseMethodSubtract() != 10
            || psyNpcGreedDieSides() != 20
            || psyNpcGreedCapPlus() != 20
            || psyNpcShopkeeperGreedFloor() != 20
            || psyNpcSpyPrideFloor() != 8
            || psyNpcThiefGreedFloor() != 21
            || psyNpcArmorerPrideFloor() != 13
            || psyNpcInterestNormalPercent() != 5
            || psyNpcInterestDoublePercent() != 100
            || psyNpcInterestZeroPercent() != 0
            || psyWorkTrashUsesDieMax() != 6
            || psyWorkTrashPricePercent() != 10
            || psyWorkCheapPriceMinPercent() != 20
            || psyWorkCheapPriceMaxPercent() != 50
            || psyWorkCheapLifespanPercent() != 50
            || psyWorkNormalPricePercent() != 100
            || psyWorkSturdyLifespanPercent() != 200
            || psyWorkSturdyPricePercent() != 250
            || !psyInsIntBelowWisVulnerable()
            || !psyInsIntAboveWisMoreSusceptible()
            || !psyInsLevelAddedToSave()
            || !psyInsSaveRollLowAvoids()
            || !psyInsPsychosesNotImmediate()
            || !psyInsGibberingImmediate()
            || !psyInsViolentImmediate()
            || !psyInsCatatonicImmediate()
            || !psyInsMagicFunctionalExcept()
            || !psyInsSchizoidNoPhysicalChange()
            || !psyInsCausesDmSet()
            || !psyInsNutty()
            || !psyInsKleptomaniac()
            || !psyInsPerverse()
            || !psyInsPsychoticHatred()
            || !psyInsChildlikeTrusting()
            || !psyInsSchizoid()
            || !psyInsSevereParanoia()
            || !psyInsAcuteParanoia()
            || !psyInsGibbering()
            || !psyInsSuicidal()
            || !psyInsViolent()
            || !psyInsCatatonic()
            || !psyLawSimilarity()
            || !psyLawContagion()
            || !psyLawMana()
            || !psyLawArtistry()
            || !psyLawObscurity()
            || !psyLawHarmony()
            || !psyActPartSpell()
            || !psyActPartRite()
            || !psyActPartCondition()
            || !psyLawSpellMustDescribeSimilarity()
            || !psyLawFatigueSubtractsAll()
            || !psyLawFatigueBackfire()
            || !psyLawSpellPoetic()
            || !psyContestWrittenSpellRequired()
            || !psyContestFleshGolems()
            || !psyContestNoBlackMagic()
            || !psyContestResurrected()
            || !psyContestSpectatorsOwnHazard()
            || !psyGodCyanideDie()
            || !psyGodDoorOpensOnFulfillment()
            || !psyGodEscapeProof()
            || !psyGodScrollMayLie()
            || !psyGodBenignSuspension()
            || !psyGodRewardXpAndTreasure()
            || !psyGodEvilRansom()
            || !psyGodEvilPartySelect()
            || !psyGodNeutralPunishesCoercers()
            || !psyGodNeutralCoercerDies()
            || !psyGodNeutralSlayOrFree()
            || !psyGodUnpoisonedVariant()
            || !psyGodSoloCrushedDie()
            || !psyGodLoadedDiceOption()
            || !psyPrideRolledOnce()
            || !psyGreedBaseMethodOption()
            || !psyWorkRolledPerItem()
            || !psyNpcBarteringHirelingWages()
            || !psyWorkCheapBandGap()
            || !psyNpcGreedShareDoctrine()
        )
            ++bad;
        // the insanity saving-throw chart - nine wisdom bands down, six
        // intelligence bands across, the unadjusted save number before the
        // level is added; roll that number or less on the d20 to avoid (print
        // 9, PDF 11)
        int CPs[9][6] = {
            {7,5,3,1,-2,-5},
            {8,9,7,5,2,-1},
            {9,10,8,6,3,0},
            {10,11,12,10,7,4},
            {11,12,13,14,11,8},
            {12,13,14,15,12,9},
            {13,14,15,16,17,14},
            {14,15,16,17,18,15},
            {15,16,17,18,19,20},
            };
        for (int b = 0;
             b < psyInsSaveRows();
             ++b) {
            int vals[6];
            vals[0] = psySaveIntLt3(b);
            vals[1] = psySaveInt3to8(b);
            vals[2] = psySaveInt9to12(b);
            vals[3] = psySaveInt13to15(b);
            vals[4] = psySaveInt16to18(b);
            vals[5] = psySaveIntOver18(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CPs[b][c])
                    ++bad;
            }
        }
        // the pride ego table - nine percentile bands with the charisma and
        // constitution modifiers and the greed and work-quality percent
        // adjustments; the 00 band is the egomaniac (print 31, PDF 33)
        int CPp[9][6] = {
            {1,1,0,-1,-15,-5},
            {2,7,0,0,-10,-1},
            {8,13,0,0,-5,0},
            {14,89,0,0,0,0},
            {90,91,1,1,0,0},
            {92,93,0,1,5,5},
            {94,98,-1,1,10,2},
            {99,99,-2,1,15,0},
            {100,100,-3,1,20,0},
            };
        for (int b = 0;
             b < psyPrideRows();
             ++b) {
            int vals[6];
            vals[0] = psyPrideLo(b);
            vals[1] = psyPrideHi(b);
            vals[2] = psyPrideChr(b);
            vals[3] = psyPrideCons(b);
            vals[4] = psyPrideGreedPct(b);
            vals[5] = psyPrideWorkPct(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CPp[b][c])
                    ++bad;
            }
        }
        // the greed table - eleven bands from any negative to 00 + 20: the
        // loan chance as a numerator over denominator (0/0 gives away, 1/1
        // loans freely, 2/3, 1/3, 1/6, 1/12 and 1/20 may-loan chances, 0/1
        // never loans) and the selling price as a percent of normal (10
        // through 300) (print 31, PDF 33)
        int CPg[11][3] = {
            {0,0,10},
            {0,0,20},
            {1,1,50},
            {1,1,100},
            {2,3,100},
            {1,3,110},
            {1,6,120},
            {1,12,150},
            {1,20,200},
            {0,1,250},
            {0,1,300},
            };
        for (int b = 0;
             b < psyGreedRows();
             ++b) {
            int vals[3];
            vals[0] = psyGreedLoanNum(b);
            vals[1] = psyGreedLoanDen(b);
            vals[2] = psyGreedPricePercent(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CPg[b][c])
                    ++bad;
            }
        }
        // the insanity save chart edges - 7 and 15 on the low intelligence
        // column, the odd 12 at wisdom 9-12 crossed with intelligence 9-12,
        // the 17 at wisdom 17 crossed with intelligence 16-18, 20 at the far
        // corner, the d20 and d12, the 9x6 bands (print 9)
    if (psySaveIntLt3(0) != 7
            || psySaveIntLt3(8) != 15
            || psySaveInt9to12(3) != 12
            || psySaveInt16to18(6) != 17
            || psySaveIntOver18(8) != 20
            || psyInsSaveDieSides() != 20
            || psyInsChartDieSides() != 12
            || psyInsWisBands() != 9
            || psyInsIntBands() != 6
        )
            ++bad;
        // the per-psychosis doctrine - the schizoid d10 reverting on 1 each
        // turn, the suicidal d6 attempt on 1, the twelve chart entries (print
        // 9)
    if (psyInsSchizoidDieSides() != 10
            || psyInsSchizoidRevertRoll() != 1
            || psyInsSuicideDieSides() != 6
            || psyInsSuicideAttemptRoll() != 1
            || psyInsChartEntries() != 12
        )
            ++bad;
        // the magic theory - six laws, three act parts, the d20 fatigue
        // check, the Kemble contest with its three judges awarding 1-10 in
        // two categories, the one-similarity minimum (print 14 + 19)
    if (psyLawCount() != 6
            || psyActParts() != 3
            || psyLawFatigueDieSides() != 20
            || psyContestJudges() != 3
            || psyContestPointsMin() != 1
            || psyContestPointsMax() != 10
            || psyContestCategories() != 2
            || psyContestSimilarityMin() != 1
        )
            ++bad;
        // the godgame - four dice, the 1 roll, the 2x treasure and 2-or-3x
        // experience recompense, the worked 4,000 GP / 1,500 EP example with
        // its 1,000/375 shares and the 2,000 GP / 1,125 EP reward, the
        // four-dice solo variant (print 19)
    if (psyGodDiceCount() != 4
            || psyGodLosingRoll() != 1
            || psyGodTreasureShareX() != 2
            || psyGodXpShareXLow() != 2
            || psyGodXpShareXHigh() != 3
            || psyGodExPartyGold() != 4000
            || psyGodExPartyXp() != 1500
            || psyGodExShareGold() != 1000
            || psyGodExShareXp() != 375
            || psyGodExRewardGold() != 2000
            || psyGodExRewardXp() != 1125
            || psyGodSoloDiceCount() != 4
        )
            ++bad;
        // the pride bands - the 01 none with its -1 cons, -15 greed and -5
        // work, the 00 egomaniac -3 chr and +20 greed, the 94-98 vain -1 chr,
        // the 92-93 well-being +1 cons and +5 work (print 31)
    if (psyPrideLo(0) != 1
            || psyPrideHi(0) != 1
            || psyPrideCons(0) != -1
            || psyPrideGreedPct(0) != -15
            || psyPrideWorkPct(0) != -5
            || psyPrideChr(8) != -3
            || psyPrideGreedPct(8) != 20
            || psyPrideChr(6) != -1
            || psyPrideCons(6) != 1
            || psyPrideWorkPct(5) != 5
            || psyPrideGreedPct(6) != 10
        )
            ++bad;
        // the greed bands - gives-away at negative and zero with 1/10 and 1/5
        // prices, the 2/3 may-loan at 85-95, the 1/12 chance at 00+10-14 with
        // +50 percent, the never-loan 00+20 triple price (print 31)
    if (psyGreedLoanNum(0) != 0
            || psyGreedLoanDen(0) != 0
            || psyGreedPricePercent(0) != 10
            || psyGreedLoanNum(4) != 2
            || psyGreedLoanDen(4) != 3
            || psyGreedPricePercent(4) != 100
            || psyGreedLoanNum(7) != 1
            || psyGreedLoanDen(7) != 12
            || psyGreedPricePercent(7) != 150
            || psyGreedLoanNum(10) != 0
            || psyGreedLoanDen(10) != 1
            || psyGreedPricePercent(10) != 300
        )
            ++bad;
        // the NPC doctrine - the base method subtract-10 with the d20 add and
        // the 00+20 cap, the shop-owner 20, spy 08, thief 21 and armorer 13
        // floors, the 5 and 100 percent interest correspondences (print 32)
    if (psyNpcGreedBaseMethodSubtract() != 10
            || psyNpcGreedDieSides() != 20
            || psyNpcGreedCapPlus() != 20
            || psyNpcShopkeeperGreedFloor() != 20
            || psyNpcSpyPrideFloor() != 8
            || psyNpcThiefGreedFloor() != 21
            || psyNpcArmorerPrideFloor() != 13
            || psyNpcInterestNormalPercent() != 5
            || psyNpcInterestDoublePercent() != 100
        )
            ++bad;
        // the work quality bands - trash at 1-6 uses and 1/10 price, the
        // cheap 1/5-to-1/2 at half lifespan, normal 100, the sturdy twice as
        // long at up to 2-1/2 price (print 32)
    if (psyWorkTrashUsesDieMax() != 6
            || psyWorkTrashPricePercent() != 10
            || psyWorkCheapPriceMinPercent() != 20
            || psyWorkCheapPriceMaxPercent() != 50
            || psyWorkCheapLifespanPercent() != 50
            || psyWorkNormalPricePercent() != 100
            || psyWorkSturdyLifespanPercent() != 200
            || psyWorkSturdyPricePercent() != 250
        )
            ++bad;
        // the save chart interior - the intelligence 3-8 column from 5 to 16,
        // the 3, 1, -2 and -5 wisdom-under-3 row, the 4 at wisdom 9-12 by
        // intelligence over 18 (print 9)
    if (psySaveInt3to8(0) != 5
            || psySaveInt3to8(8) != 16
            || psySaveInt9to12(0) != 3
            || psySaveInt13to15(0) != 1
            || psySaveInt13to15(8) != 18
            || psySaveInt16to18(0) != -2
            || psySaveInt16to18(8) != 19
            || psySaveIntOver18(0) != -5
            || psySaveIntOver18(3) != 4
        )
            ++bad;
        // the pride normal band 14-89, the 90-91 well-being +1 chr and cons,
        // the 99 egotist, the 100/00 egomaniac band (print 31)
    if (psyPrideLo(3) != 14
            || psyPrideHi(3) != 89
            || psyPrideChr(4) != 1
            || psyPrideCons(4) != 1
            || psyPrideLo(7) != 99
            || psyPrideHi(7) != 99
            || psyPrideChr(7) != -2
            || psyPrideCons(7) != 1
            || psyPrideGreedPct(7) != 15
            || psyPrideLo(8) != 100
            || psyPrideHi(8) != 100
        )
            ++bad;
        // the greed 01-20 loans at 1/2, the 00+4 band 1/3 at +10, the
        // 00+15-17 1/20 at double, the 00+18-19 2-1/2 price (print 31)
    if (psyGreedLoanNum(2) != 1
            || psyGreedLoanDen(2) != 1
            || psyGreedPricePercent(2) != 50
            || psyGreedLoanNum(5) != 1
            || psyGreedLoanDen(5) != 3
            || psyGreedPricePercent(5) != 110
            || psyGreedLoanNum(8) != 1
            || psyGreedLoanDen(8) != 20
            || psyGreedPricePercent(8) != 200
            || psyGreedPricePercent(9) != 250
        )
            ++bad;
        printf("R934 issue-18 opener part one audit: bad %d\n", bad);
        if (bad) return 1;
    }
