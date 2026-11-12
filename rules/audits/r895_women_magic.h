    // ---- R895 women magic audit ----
    // THE ISSUE-3 OPENER - the Dragon #3 walk opens: the 32 voice pages ride
    // as data files, the issue-3 gap report ships pre-flip with five boxes
    // (the women opener, the specialists, the fighting sub-classes, the
    // character, the comedy and small-variants rounds), and the Ward box
    // flips closing the issue-1 report at 4 closed / 0 open. THE LAKOFKA
    // WOMEN: the Beauty attribute (2d20 as 1-10s, 2-20), the strength frame
    // (1d8+1d6, 2-14, the 13-14 constitution bump), the four ladders -
    // Fighting Woman to War Lady 10th, Novice to Matriarch 12th, Wench to
    // Sibyl, Medium to Witch 22nd - with the hit-dice X+Y forms CONVERTED to
    // base-plus-bonus columns; the seduction family - the five-race beauty
    // matrix with the thief +2 and fighter +4 adders, the nine duration
    // bands, the Charm Men grades with hit-dice caps and catatonia dice, the
    // humanoid charm gates with the 70 percent break and the 12-16 carry-off;
    // the witch additions - the five Horrid Beauty tiers with the scare and
    // seduce caps, Poison with the counter-spell percentages, Magic Mount,
    // Mind Meld with the insanity chances, Spirit, and the chaotic cleric
    // Worship. HONEST BOUNDARIES: the beauty matrix, the Witch-grid odd
    // hit-dice cells and the ugly-tier flee sign ride as scanned, no figure
    // to check; the OCR duplicate Succubus row pins eight thief titles; the
    // female ladders ride the variant layer against the engine's canon class
    // tables, never a rewrite.
    {
        using namespace rules;
        int bad = 0;
    if (wmnBeautyDiceCount() != 2
            || wmnBeautyDieMax() != 10
            || wmnStrengthDieEight() != 8
            || wmnStrengthDieSix() != 6
            || wmnStrengthMin() != 2
            || wmnStrengthMax() != 14
            || wmnStrConBonusMin() != 13
            || wmnStrConBonusMax() != 14
            || wmnStrConBonus() != 1
            || wmnThiefSpellIntMin() != 12
            || wmnThiefCharmIntMin() != 9
            || wmnThiefCharmBeautyMin() != 13
            || wmnEncumbranceBase() != 1000
            || wmnEncumbrancePerStr() != 50
            || wmnMaxLoadTenths() != 18
            || wmnGroupOnePenalty() != 1
            || wmnGroupTwoPenaltyTen() != 2
            || wmnGroupTwoPenaltyTwelve() != 1
            || wmnDaggerBonus() != 1
            || wmnPlateFatigueTen() != 20
            || wmnPlateFatigueTwelve() != 10
            || wmnChainFatigueEleven() != 10
            || wmnWitchEqualLevel() != 13
            || wmnSeduceRangeFeet() != 6
            || wmnSeduceEffectTurns() != 2
            || wmnSeduceAttackPenalty() != 3
            || wmnSeduceThiefBonus() != 2
            || wmnSeduceFighterBonus() != 4
            || wmnSeduceSaveFighter() != 13
            || wmnSeduceSaveThief() != 12
            || wmnSeduceSavePaladin() != 10
            || wmnSeduceSaveMage() != 9
            || wmnSeduceSaveCleric() != 8
            || wmnCharmRangeFeet() != 16
            || wmnCharmTakeoverTurns() != 2
            || wmnCharmBossDie() != 8
            || wmnCharmBossDispels() != 6
            || wmnCharmBeautyMage() != 11
            || wmnCharmBeautyThief() != 13
            || wmnCharmBeautyFighter() != 16
            || wmnChmBeautyMage() != 11
            || wmnChmBeautyThiefFighter() != 13
            || wmnChmCatatoniaDie() != 4
            || wmnChmBreakPercent() != 70
            || wmnChmKillRoll() != 8
            || wmnChmGrappleRoll() != 9
            || wmnChmHarmPercent() != 50
            || wmnChmLevelBonus() != 2
            || wmnChmCarryRollMin() != 12
            || wmnChmCarryRollMax() != 16
            || wmnHbRangeFeet() != 16
            || wmnHbDurationTurns() != 6
            || wmnPoisonRangeInches() != 18
            || wmnPoisonDamagePerTurn() != 3
            || wmnPoisonPurifyPct() != 40
            || wmnPoisonNeutralizePct() != 60
            || wmnPoisonCurePct() != 10
            || wmnPoisonDetectPct() != 30
            || wmnMeldCastRangeInches() != 6
            || wmnMeldRangeInches() != 12
            || wmnMeldLowGainDiv() != 2
            || wmnMeldStrongerGain() != 1
            || wmnMeldInsanityDamaged() != 85
            || wmnMeldInsanityOther() != 50
            || wmnMeldDurationBase() != 6
            || wmnMeldDurationDie() != 8
            || wmnMountHeavyCount() != 3
            || wmnMountRiders() != 2
            || wmnSpiritMoveInches() != 12
            || wmnSpiritDurationBase() != 4
            || wmnSpiritDurationDie() != 8
            || wmnSpiritMagicDamagePct() != 50
            || wmnSpiritSpellPct() != 30
            || wmnWorshipLevel() != 4
            || wmnWorshipBeautyMin() != 11
            || wmnWorshipRangeFeet() != 12
            || wmnWorshipDurationBase() != 4
            || wmnWorshipDurationDie() != 8
            || wmnWorshipSaveHd() != 5
            || wmnFtrLevels() != 10
            || wmnClrLevels() != 12
            || wmnThfLevels() != 8
            || wmnMageLevels() != 22
            || wmnSeduceRaces() != 5
            || wmnSeduceBands() != 9
            || wmnCharmMenLevels() != 3
            || wmnHbTiers() != 5
            || !wmnWomenSurpassMenThieves()
            || !wmnChaoticClericsUseBeauty()
            || !wmnClericsRateCharisma()
            || !wmnAlternateSystemLevelCut()
            || !wmnSeductionMalesOnly()
            || !wmnOrdinaryEffectCoinFlip()
            || !wmnMeldRequiresStillness()
            || !wmnMountBridleAtOnce()
            || !wmnTarotYesNoOnly()
            || !wmnTarotSibylReads()
        )
            ++bad;
        // the Fighting Woman ladder - Fighting Woman, Swordswoman, Gladiator,
        // Battle Maiden, Shield Maiden, Myrmidon, Heroine, Valkyrie, War
        // Lady, War Lady 10th (folio 7)
        int CWmnFtr[10][3] = {
            {0,1,1},
            {1600,2,0},
            {3200,3,0},
            {6400,4,0},
            {12800,5,0},
            {25000,5,2},
            {50000,6,2},
            {100000,7,2},
            {200000,8,2},
            {300000,9,2},
            };
        for (int b = 0;
             b < wmnFtrLevels();
             ++b) {
            int vals[3];
            vals[0] = wmnFtrXp(b);
            vals[1] = wmnFtrHitBase(b);
            vals[2] = wmnFtrHitBonus(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CWmnFtr[b][c])
                    ++bad;
            }
        }
        // the female Cleric ladder - Novice, Initiate, Postulant, Apostolate,
        // Sister, Deaconess, Canoness, Prioress, Superioress, Matriarch
        // 10th-12th (folios 7-8)
        int CWmnClr[12][3] = {
            {0,1,0},
            {1200,2,0},
            {2400,3,0},
            {4800,3,1},
            {9600,4,0},
            {20000,4,1},
            {40000,5,0},
            {80000,6,0},
            {160000,6,2},
            {240000,7,2},
            {320000,8,2},
            {400000,9,2},
            };
        for (int b = 0;
             b < wmnClrLevels();
             ++b) {
            int vals[3];
            vals[0] = wmnClrXp(b);
            vals[1] = wmnClrHitBase(b);
            vals[2] = wmnClrHitBonus(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CWmnClr[b][c])
                    ++bad;
            }
        }
        // the female Thief ladder - Wench, Hag, Jade, Succubus, Adventuress,
        // Soothsayer, Gypsy, Sibyl; the duplicate Succubus row in the
        // transcript is an OCR artifact, eight titles pin (folios 7-8)
        int CWmnThf[8][3] = {
            {0,1,0},
            {1000,2,0},
            {2000,3,0},
            {4000,4,0},
            {8000,4,1},
            {16000,4,2},
            {35000,5,0},
            {70000,5,2},
            };
        for (int b = 0;
             b < wmnThfLevels();
             ++b) {
            int vals[3];
            vals[0] = wmnThfXp(b);
            vals[1] = wmnThfHitBase(b);
            vals[2] = wmnThfHitBonus(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CWmnThf[b][c])
                    ++bad;
            }
        }
        // the female Magic-User ladder - Medium, Seer, Sage, Mystic, Oracle,
        // Enchantress, Illusionist, Sorceress, Witch 9th-22nd (folios 7-8)
        int CWmnMge[22][3] = {
            {0,1,0},
            {2400,1,1},
            {4800,2,0},
            {9600,2,1},
            {20000,3,0},
            {40000,3,1},
            {65000,4,0},
            {90000,5,0},
            {180000,6,0},
            {270000,7,0},
            {360000,8,0},
            {450000,8,1},
            {600000,8,2},
            {700000,9,2},
            {800000,9,3},
            {900000,10,2},
            {1000000,10,3},
            {1200000,10,4},
            {1400000,11,3},
            {1600000,11,4},
            {2000000,11,5},
            {2400000,11,7},
            };
        for (int b = 0;
             b < wmnMageLevels();
             ++b) {
            int vals[3];
            vals[0] = wmnMageXp(b);
            vals[1] = wmnMageHitBase(b);
            vals[2] = wmnMageHitBonus(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CWmnMge[b][c])
                    ++bad;
            }
        }
        // the beauty matrix AS SCANNED - rows Elf, Woman, Hobbit, Orc, Dwarf
        // against the defender races; no figure pixels ride the OCR artifact
        // to verify against, the honest boundary noted; women with a lower
        // beauty score cannot seduce the given man of the other race (folio
        // 9)
        int CWmnSed[5][5] = {
            {10,11,10,10,10},
            {11,12,11,12,12},
            {12,14,13,11,12},
            {15,20,11,14,17},
            {13,15,14,13,11},
            };
        for (int b = 0;
             b < wmnSeduceRaces();
             ++b) {
            int vals[5];
            vals[0] = wmnSeduceVsMen(b);
            vals[1] = wmnSeduceVsElves(b);
            vals[2] = wmnSeduceVsOrcs(b);
            vals[3] = wmnSeduceVsHobbits(b);
            vals[4] = wmnSeduceVsDwarves(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CWmnSed[b][c])
                    ++bad;
            }
        }
        // the seduction duration by level bands 1-2, 3-4, 5-6, 7-8, 9-10,
        // 11-12, 13-14, 15-16, 17-18 (folio 9)
        int CWmnSdd[9][2] = {
            {2,0},
            {1,2},
            {1,3},
            {2,3},
            {3,4},
            {3,6},
            {4,6},
            {4,8},
            {5,8},
            };
        for (int b = 0;
             b < wmnSeduceBands();
             ++b) {
            int vals[2];
            vals[0] = wmnSedBase(b);
            vals[1] = wmnSedDie(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CWmnSdd[b][c])
                    ++bad;
            }
        }
        // the Charm Men grades I, II, III - catatonia occurs if no figure
        // with more hit dice is within 12 feet; weakest figures are always
        // affected first (folio 9)
        int CWmnCm[3][5] = {
            {3,3,4,4,4},
            {4,4,6,6,6},
            {5,5,8,8,8},
            };
        for (int b = 0;
             b < wmnCharmMenLevels();
             ++b) {
            int vals[5];
            vals[0] = wmnCmHdCap(b);
            vals[1] = wmnCmCataBase(b);
            vals[2] = wmnCmCataDie(b);
            vals[3] = wmnCmAffBase(b);
            vals[4] = wmnCmAffDie(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CWmnCm[b][c])
                    ++bad;
            }
        }
        // the Horrid Beauty tiers - Grotesque, Ugly, Ordinary, Beautiful,
        // Gorgeous; the ordinary tier flips a coin between the scare and the
        // seduce effects (folio 10)
        int CWmnHb[5][7] = {
            {2,3,0,0,2,4,6},
            {6,2,0,0,1,2,4},
            {10,0,0,0,0,0,0},
            {13,0,4,6,0,0,0},
            {17,0,5,7,0,0,0},
            };
        for (int b = 0;
             b < wmnHbTiers();
             ++b) {
            int vals[7];
            vals[0] = wmnHbBeautyMin(b);
            vals[1] = wmnHbScareHd(b);
            vals[2] = wmnHbSeduceHd(b);
            vals[3] = wmnHbSeduceLevel(b);
            vals[4] = wmnHbMoraleDrop(b);
            vals[5] = wmnHbFleeBase(b);
            vals[6] = wmnHbFleeDie(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CWmnHb[b][c])
                    ++bad;
            }
        }
        // the Fighting Woman ladder bookends - 0, Shield Maiden 12800, War
        // Lady 10th 300000 (folio 7)
    if (wmnFtrXp(0) != 0
            || wmnFtrXp(4) != 12800
            || wmnFtrXp(9) != 300000
        )
            ++bad;
        // the Myrmidon rolls 5+2 hit dice, the Fighting Woman 1+1 (folio 7)
    if (wmnFtrHitBase(5) != 5
            || wmnFtrHitBonus(5) != 2
            || wmnFtrHitBonus(0) != 1
        )
            ++bad;
        // the Matriarch 12th caps at 400000 experience, 9+2 hit dice (folios
        // 7-8)
    if (wmnClrXp(11) != 400000
            || wmnClrHitBase(11) != 9
            || wmnClrHitBonus(11) != 2
        )
            ++bad;
        // the Apostolate 3+1, the Deaconess 4+1, the Superioress 6+2 (folio
        // 8)
    if (wmnClrHitBonus(3) != 1
            || wmnClrHitBonus(5) != 1
            || wmnClrHitBonus(8) != 2
        )
            ++bad;
        // the Gypsy at 35000, the Sibyl at 70000 (folio 7)
    if (wmnThfXp(6) != 35000
            || wmnThfXp(7) != 70000
        )
            ++bad;
        // the Soothsayer 4+2, the Sibyl 5+2 (folio 8)
    if (wmnThfHitBase(5) != 4
            || wmnThfHitBonus(5) != 2
            || wmnThfHitBonus(7) != 2
        )
            ++bad;
        // the Witch ladder - Witch at 180000 through Witch 22nd at 2400000
        // (folio 7)
    if (wmnMageXp(8) != 180000
            || wmnMageXp(20) != 2000000
            || wmnMageXp(21) != 2400000
        )
            ++bad;
        // the Witch-grid hit-dice column as scanned - Witch 16th 10+2 base,
        // Witch 18th +4, Witch 22nd +7 (folio 8)
    if (wmnMageHitBase(15) != 10
            || wmnMageHitBonus(17) != 4
            || wmnMageHitBonus(21) != 7
        )
            ++bad;
        // beauty on two twenty-sided dice numbered 1-10, range 2-20 not 2-40
        // (folio 7)
    if (wmnBeautyDiceCount() != 2
            || wmnBeautyDieMax() != 10
        )
            ++bad;
        // strength 2-14 on one 8-sider plus one 6-sider (folios 7-8)
    if (wmnStrengthMin() != 2
            || wmnStrengthMax() != 14
            || wmnStrengthDieEight() != 8
            || wmnStrengthDieSix() != 6
        )
            ++bad;
        // strength 13 or 14 adds 1 to constitution (folio 7)
    if (wmnStrConBonusMin() != 13
            || wmnStrConBonusMax() != 14
            || wmnStrConBonus() != 1
        )
            ++bad;
        // the thief spell gates - intelligence 12 for spells, 9 for the three
        // charm spells, beauty 13 (folio 8)
    if (wmnThiefSpellIntMin() != 12
            || wmnThiefCharmIntMin() != 9
            || wmnThiefCharmBeautyMin() != 13
        )
            ++bad;
        // the encumbrance frame - 1000 plus fifty times strength, max load
        // 1.8x as 18 tenths (folio 8)
    if (wmnEncumbranceBase() != 1000
            || wmnEncumbrancePerStr() != 50
            || wmnMaxLoadTenths() != 18
        )
            ++bad;
        // the weapon penalties by strength - the flail group at -1, the
        // pole-arm group -2 at ten or lower, -1 at twelve or lower (folio 8)
    if (wmnGroupOnePenalty() != 1
            || wmnGroupTwoPenaltyTen() != 2
            || wmnGroupTwoPenaltyTwelve() != 1
        )
            ++bad;
        // ALL WOMEN wield the dagger at an additional +1 (folio 8)
    if (wmnDaggerBonus() != 1
        )
            ++bad;
        // the armor fatigue percentages (folio 8)
    if (wmnPlateFatigueTen() != 20
            || wmnPlateFatigueTwelve() != 10
            || wmnChainFatigueEleven() != 10
        )
            ++bad;
        // Witch 13 equals Wizard 13; women surpass men as thieves; the
        // Alternate Combat System cuts one level (folios 7-8)
    if (wmnWitchEqualLevel() != 13
            || wmnWomenSurpassMenThieves() != 1
            || wmnAlternateSystemLevelCut() != 1
        )
            ++bad;
        // the beauty matrix as scanned - a woman needs 11 versus Men, an orc
        // 20 versus Elves, a dwarf 14 versus Orcs (folio 9)
    if (wmnSeduceVsMen(1) != 11
            || wmnSeduceVsElves(3) != 20
            || wmnSeduceVsOrcs(4) != 14
        )
            ++bad;
        // thieves add 2, fighters add 4 to each matrix score (folio 9)
    if (wmnSeduceThiefBonus() != 2
            || wmnSeduceFighterBonus() != 4
        )
            ++bad;
        // the fighter, thief and paladin save thresholds (folio 9)
    if (wmnSeduceSaveFighter() != 13
            || wmnSeduceSaveThief() != 12
            || wmnSeduceSavePaladin() != 10
        )
            ++bad;
        // the magic-user and cleric save thresholds (folio 9)
    if (wmnSeduceSaveMage() != 9
            || wmnSeduceSaveCleric() != 8
        )
            ++bad;
        // seduction at six feet, two full turns at three levels lower (folio
        // 9)
    if (wmnSeduceRangeFeet() != 6
            || wmnSeduceEffectTurns() != 2
            || wmnSeduceAttackPenalty() != 3
        )
            ++bad;
        // the first duration band is a flat two turns (folio 9)
    if (wmnSedBase(0) != 2
            || wmnSedDie(0) != 0
        )
            ++bad;
        // the 17-18 band runs 5+(1-8) turns, the 7-8 band 2+(1-3) (folio 9)
    if (wmnSedBase(8) != 5
            || wmnSedDie(8) != 8
            || wmnSedBase(3) != 2
            || wmnSedDie(3) != 3
        )
            ++bad;
        // the Charm Men hit-dice caps - 3, 4, 5 by grade (folio 9)
    if (wmnCmHdCap(0) != 3
            || wmnCmHdCap(1) != 4
            || wmnCmHdCap(2) != 5
        )
            ++bad;
        // Charm Men II - 4+(1-6) turns of catatonia, 6+(1-6) men affected
        // (folio 9)
    if (wmnCmCataBase(1) != 4
            || wmnCmCataDie(1) != 6
            || wmnCmAffBase(1) != 6
            || wmnCmAffDie(1) != 6
        )
            ++bad;
        // the charm frame - range 16 feet, takeover after 2 turns, the boss
        // rolls a d8 and dispels at 6+ (folio 9)
    if (wmnCharmRangeFeet() != 16
            || wmnCharmTakeoverTurns() != 2
            || wmnCharmBossDie() != 8
            || wmnCharmBossDispels() != 6
        )
            ++bad;
        // the charm beauty gates - magic user 11, thief 13, fighter 16 (folio
        // 9)
    if (wmnCharmBeautyMage() != 11
            || wmnCharmBeautyThief() != 13
            || wmnCharmBeautyFighter() != 16
        )
            ++bad;
        // the humanoid charm gates and the 70 percent break (folio 9)
    if (wmnChmBeautyMage() != 11
            || wmnChmBeautyThiefFighter() != 13
            || wmnChmBreakPercent() != 70
        )
            ++bad;
        // catatonia 1-4 turns, vampires, gargoyles and centaurs +2 level, the
        // 50 percent grapple harm (folios 9-10)
    if (wmnChmCatatoniaDie() != 4
            || wmnChmLevelBonus() != 2
            || wmnChmHarmPercent() != 50
        )
            ++bad;
        // the fight-break roll - 8+ kill, 9+ grapple, 12-16 carry-off, 17+
        // catatonia (folio 9)
    if (wmnChmKillRoll() != 8
            || wmnChmGrappleRoll() != 9
            || wmnChmCarryRollMin() != 12
            || wmnChmCarryRollMax() != 16
        )
            ++bad;
        // the tier floors - Grotesque 2, Ugly 6, Beautiful 13, Gorgeous 17
        // (folio 10)
    if (wmnHbBeautyMin(0) != 2
            || wmnHbBeautyMin(1) != 6
            || wmnHbBeautyMin(3) != 13
            || wmnHbBeautyMin(4) != 17
        )
            ++bad;
        // Grotesque scares 3 hit dice to death, Ugly 2 (folio 10)
    if (wmnHbScareHd(0) != 3
            || wmnHbScareHd(1) != 2
        )
            ++bad;
        // Beautiful seduces 4 hit dice as a 6th-level spell, Gorgeous 5 as a
        // 7th (folio 10)
    if (wmnHbSeduceHd(3) != 4
            || wmnHbSeduceLevel(3) != 6
            || wmnHbSeduceHd(4) != 5
            || wmnHbSeduceLevel(4) != 7
        )
            ++bad;
        // the flee morale hits - 2 and 1, the ugly flee as scanned 2+(1-4)
        // (folio 10)
    if (wmnHbMoraleDrop(0) != 2
            || wmnHbMoraleDrop(1) != 1
            || wmnHbFleeBase(1) != 2
            || wmnHbFleeDie(1) != 4
        )
            ++bad;
        // the ordinary 50/50, sight within 16 feet, 6-turn duration (folio
        // 10)
    if (wmnOrdinaryEffectCoinFlip() != 1
            || wmnHbRangeFeet() != 16
            || wmnHbDurationTurns() != 6
        )
            ++bad;
        // poison to 18 inches, 3 hits per turn (folio 10)
    if (wmnPoisonRangeInches() != 18
            || wmnPoisonDamagePerTurn() != 3
        )
            ++bad;
        // the counter-spell chances (folio 10)
    if (wmnPoisonPurifyPct() != 40
            || wmnPoisonNeutralizePct() != 60
            || wmnPoisonCurePct() != 10
            || wmnPoisonDetectPct() != 30
        )
            ++bad;
        // the Mind Meld frame (folio 10)
    if (wmnMeldCastRangeInches() != 6
            || wmnMeldRangeInches() != 12
            || wmnMeldDurationBase() != 6
            || wmnMeldDurationDie() != 8
        )
            ++bad;
        // the insanity chances and the level gains (folio 10)
    if (wmnMeldInsanityDamaged() != 85
            || wmnMeldInsanityOther() != 50
            || wmnMeldLowGainDiv() != 2
            || wmnMeldStrongerGain() != 1
        )
            ++bad;
        // the Wind Horse fights as 3 heavy horse, carries two, bridled at
        // once (folio 10)
    if (wmnMountHeavyCount() != 3
            || wmnMountRiders() != 2
            || wmnMountBridleAtOnce() != 1
        )
            ++bad;
        // the spirit form - lateral 12, 4+(1-8) turns (folio 10)
    if (wmnSpiritMoveInches() != 12
            || wmnSpiritDurationBase() != 4
            || wmnSpiritDurationDie() != 8
        )
            ++bad;
        // magic weapons half damage, spells 30 percent (folio 10)
    if (wmnSpiritMagicDamagePct() != 50
            || wmnSpiritSpellPct() != 30
        )
            ++bad;
        // Worship - the 4th-level chaotic cleric spell, beauty 11, within 12
        // feet (folio 10)
    if (wmnWorshipLevel() != 4
            || wmnWorshipBeautyMin() != 11
            || wmnWorshipRangeFeet() != 12
        )
            ++bad;
        // the trance 4+(1-8) turns, the save at 4+1 hit dice (folio 10)
    if (wmnWorshipDurationBase() != 4
            || wmnWorshipDurationDie() != 8
            || wmnWorshipSaveHd() != 5
        )
            ++bad;
        // the cleric beauty rules - chaotic beauty, lawful and neutral
        // charisma (folios 7, 10)
    if (wmnChaoticClericsUseBeauty() != 1
            || wmnClericsRateCharisma() != 1
        )
            ++bad;
        // males only for seduction, the tarot yes/no frame, the Sibyl read
        // (folio 8)
    if (wmnSeductionMalesOnly() != 1
            || wmnTarotYesNoOnly() != 1
            || wmnTarotSibylReads() != 1
        )
            ++bad;
        // the meld breaks only through two full turns of stillness (folio 10)
    if (wmnMeldRequiresStillness() != 1
        )
            ++bad;
        printf("R895 women magic audit: bad %d\n", bad);
        if (bad) return 1;
    }
