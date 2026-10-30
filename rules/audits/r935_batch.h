    // ---- R935 issue-18 opener part two audit ----
    // THE DRAGON ISSUE-18 OPENER PART TWO - the three variant chains. CHAIN
    // ONE, New Spells in D&D by Paul Sullin (print 13, PDF 15): nineteen
    // researched spells across levels one to six, the per-level counts
    // 1/2/4/4/2/6 - Nature Call (the 1-10 summons, the minus-two hit die, the
    // eagle messenger, the 1-4 turn arrival, no underground), Magic Missile
    // II (one +2 or two +1 arrows per five levels beyond third), Moon Runes
    // (the one-year shine and fade), Flamebolt (3-24 living, 3-30 undead, the
    // 5-foot ignition, the level plus 1-3 fires), Mystic Rope (100 feet, one
    // point per four feet, the one-foot regeneration), Pit of Flame (the
    // 20x20x5 pit, half level rounded up, the 3-dice fifth-level example, the
    // interrogation float), Word of Warding (usable while meled, one melee
    // turn, the third-level ceiling after immediate use), Force Field (the
    // ten-foot sphere that will not block magic), the Extend family (levels
    // 3/4/5 at 50 percent, Extend III doubling the range), Shatterray (5-30,
    // 20 structure points, the 12-dice and 60-point caps), Wall of Water
    // (50x20, the five-hit-dice floor), Beam of Blasting (one per Gold Piece
    // to 50, doubling at twelfth level, no living matter), Conjure
    // Djinn/Efreet (the 24-hour service, the efreet banish-or-attack),
    // Density Control (gas to steel, armor class one, hands as swords),
    // Combine I (seven spell levels or three spells), Call Spirit (two
    // questions, 25 percent floor, night only, 20 feet), Rust Monster Touch -
    // plus the editor doctrine (the careful approval, the
    // every-spell-needs-a-loophole rule). The list ends level 6 with cont pg
    // 21 - levels 7-9 NEVER printed in TD18, the watch riding to TD 19. CHAIN
    // TWO, Monkish Weapons and Monk vs Monk Combat by Garry Eckert (print
    // 23-24, PDF 25-26): the kedo combat matrix - nine attacker moves down,
    // nine defender moves across, the outcome codes blocked 0, cut 1, dla 2,
    // dra 3, ara 4, ala 5 and the odd dar 6 - with the print catches pinned
    // as scanned: the numbered attack list prints 2-8 while claiming eight
    // attacks (attack 1 never prints, presumably the migi-do that appears
    // only in the matrix), the dar at the migi-men vs hidari-men crossing is
    // a transposition of dra absent from the printed notes key, and the
    // migi-men, migi-do, gyaku-do, kote, hidari-kote and tsuki rows cut
    // against their own defense (the six diagonal breaks) while the migi-do
    // and gyaku-do blocked cells print crossed; the weapon doctrine - the
    // live blade, shimia and bokutois swords, the seven-foot kyudo bow at
    // 40-50 pounds with the 90-pound expert draw and 39-inch arrows fired
    // standing, crouching or on horseback, the naginata and its three cuts,
    // the seven-to-nine-foot yari, the six-foot rokushakubo, the kama sickle,
    // the ton-fa or tui-fa in pairs, the silk-or-chain nunchaku, the sai -
    // and the seven-rank progression from the four-weapon Novice to the
    // 90-pound North Wind bow. CHAIN THREE, Effective Use of Poison by Bill
    // Coburn (print 24, PDF 26): the A/B/C grid - the A potion (arsenic,
    // hemlock, 80 percent death in 2-8 turns, stricken one week), the B gas
    // and darts (neurotoxic, 50 percent in 4-16 turns, stricken 1-3 days,
    // unconscious in 30 minutes for 1-4 days), the C creatures (hemotoxic, 10
    // percent in 1-4 days, stricken 1-10 days, unconscious in one hour for
    // 2-8 days), the stricken halves (Strength, Dexterity, Constitution,
    // Movement), the armor saving-throw ladder +2/+1/0/-2 with the
    // no-internal-effect rule, and the Neutralize Poison cancellation. The
    // pin IS the conversion noted never silent; the as-scanned quirks ride
    // the comments and the transcripts.
    {
        using namespace rules;
        int bad = 0;
    if (mknSullinSpells() != 19
            || mknSpellsLvl1() != 1
            || mknSpellsLvl2() != 2
            || mknSpellsLvl3() != 4
            || mknSpellsLvl4() != 4
            || mknSpellsLvl5() != 2
            || mknSpellsLvl6() != 6
            || mknNcrSummonMin() != 1
            || mknNcrSummonMax() != 10
            || mknNcrHitDiePenalty() != 2
            || mknNcrMessengerDays() != 3
            || mknNcrArrivalTurnsMin() != 1
            || mknNcrArrivalTurnsMax() != 4
            || mknMmiPlusTwoArrows() != 1
            || mknMmiPlusOneArrows() != 2
            || mknMmiBonusEveryLevels() != 5
            || mknMmiBeyondLevel() != 3
            || mknMreMaxDurationYears() != 1
            || mknFlbLivingDice() != 3
            || mknFlbLivingDieSides() != 8
            || mknFlbUndeadDice() != 3
            || mknFlbUndeadDieSides() != 10
            || mknFlbIgniteRadiusFeet() != 5
            || mknFlbRangeFeet() != 240
            || mknFlbFiresBonusMin() != 1
            || mknFlbFiresBonusMax() != 3
            || mknMroLengthFeet() != 100
            || mknMroHpPerFeet() != 4
            || mknMroRegenFeetPerTurn() != 1
            || mknPofWidthFeet() != 20
            || mknPofLengthFeet() != 20
            || mknPofDepthFeet() != 5
            || mknPofDurationTurns() != 3
            || mknPofFifthLevelDice() != 3
            || mknWowDurationMeleeTurns() != 1
            || mknWowImmediateMaxSpellLevel() != 3
            || mknFfdDiameterFeet() != 10
            || mknFfdRangeFeet() != 60
            || mknExtOneMaxSpellLevel() != 3
            || mknExtOneRangePct() != 50
            || mknShdDamageDice() != 5
            || mknShdDamageDieSides() != 6
            || mknShdStructurePoints() != 20
            || mknShdBonusBeyondLevel() != 7
            || mknShdMaxDamageDice() != 12
            || mknShdStructBonusPerLevel() != 5
            || mknShdMaxStructPoints() != 60
            || mknShdRangeFeet() != 120
            || mknWwdLengthFeet() != 50
            || mknWwdHeightFeet() != 20
            || mknWwdBreakDice() != 5
            || mknWwdBreakDieSides() != 6
            || mknWwdBlocksBelowHd() != 5
            || mknWwdRangeFeet() != 30
            || mknWwdDurationHours() != 1
            || mknExtTwoMaxSpellLevel() != 4
            || mknBbbBlastDiameterFeet() != 30
            || mknBbbDmgPerGp() != 1
            || mknBbbMaxDamage() != 50
            || mknBbbBonusEveryLevels() != 3
            || mknBbbBeyondLevel() != 9
            || mknBbbTwelfthDmgPerGp() != 2
            || mknBbbRangeFeet() != 200
            || mknCdeServiceHours() != 24
            || mknDcoDurationTurns() != 3
            || mknDcoMaxDensityAc() != 1
            || mknExtThreeMaxSpellLevel() != 5
            || mknCmbMaxSpellLevels() != 7
            || mknCmbMaxSpells() != 3
            || mknCspQuestions() != 2
            || mknCspMinChancePct() != 25
            || mknCspRemainsWithinFeet() != 20
            || mknMonkRanks() != 7
            || mknMonkWeapons() != 11
            || mknKedoMoves() != 9
            || mknKedoDefenses() != 9
            || mknKedoAttacksClaimed() != 8
            || mknKedoAttacksPrinted() != 7
            || mknKedoCodeBlocked() != 0
            || mknKedoCodeCut() != 1
            || mknKedoCodeDla() != 2
            || mknKedoCodeDra() != 3
            || mknKedoCodeAra() != 4
            || mknKedoCodeAla() != 5
            || mknKedoCodeDar() != 6
            || mknKyudoBowFeet() != 7
            || mknKyudoThickMinInches() != 1
            || mknKyudoThickMaxInches() != 2
            || mknKyudoDrawLbMin() != 40
            || mknKyudoDrawLbMax() != 50
            || mknKyudoExpertDrawLb() != 90
            || mknKyudoArrowInches() != 39
            || mknNaginataBasicCuts() != 3
            || mknYariMinFeet() != 7
            || mknYariMaxFeet() != 9
            || mknRokFeet() != 6
            || mknRokDiameterMinInches() != 1
            || mknRokDiameterMaxInches() != 2
            || mknTonfaMinInches() != 15
            || mknTonfaMaxInches() != 20
            || mknTonfaHandleInches() != 6
            || mknSaiMinInches() != 15
            || mknSaiMaxInches() != 20
            || mknRankNoviceWeapons() != 4
            || mknRankInitiateWeapons() != 2
            || mknRankDiscipleWeapons() != 1
            || mknRankImmaculateWeapons() != 2
            || mknRankMasterWeapons() != 1
            || mknRankGrandMasterWeapons() != 1
            || mknRankNorthWindWeapons() != 1
            || mknPoisCodes() != 3
            || mknStrickenStats() != 4
            || mknStrickenDivisor() != 2
            || mknArmorPlate() != 2
            || mknArmorChain() != 1
            || mknArmorLeather() != 0
            || mknArmorNone() != -2
            || !mknNcrConfusesStupidMonsters()
            || !mknNcrRefusesFearedFoes()
            || !mknNcrEagleMessenger()
            || !mknNcrNoUnderground()
            || !mknMreSetToShineOrFade()
            || !mknMroImmuneNonMagical()
            || !mknMroUntyingOnlyByConjurer()
            || !mknPofInterrogationFloats()
            || !mknPofDamageHalfLevelRoundedUp()
            || !mknWowUsableWhileMeled()
            || !mknWowDeflectsOneWeapon()
            || mknFfdBlocksMagic()
            || !mknFfdMovesOnlyWithCasterInside()
            || !mknFfdDurationPerLevelTurns()
            || !mknWwdBlocksNormalFire()
            || !mknWwdBlocksMissileFire()
            || !mknBbbNoLivingMatter()
            || !mknBbbHeldOrWornNoSave()
            || !mknCdeDjinnVanishAtEnd()
            || !mknCdeEfreetBanishOrAttack()
            || !mknDcoGasToSteel()
            || !mknDcoHandsStrikeAsSwords()
            || !mknDcoItemsInContactChange()
            || !mknDcoNoSolidWeaponAtMinDensity()
            || !mknExtThreeDoublesRange()
            || !mknCmbDurationAsShortest()
            || !mknCspNightOnly()
            || !mknCspNameMustBeKnown()
            || !mknRmtAsRustMonster()
            || !mknSullinEditorApprovalRequired()
            || !mknSullinEverySpellNeedsLoophole()
            || !mknSullinResearchAnyLevel()
            || !mknKedoAttackOneMissing()
            || !mknKedoMigiDoMatrixOnly()
            || !mknKedoGyakuDoRarelyUsed()
            || !mknKedoHidariKoteShoulderHeight()
            || !mknKedoTsukiThroat()
            || !mknKyudoFiredHorseback()
            || !mknNaginataMaimsHorseFirst()
            || !mknYariHorsebackUse()
            || !mknLiveBladeMetal()
            || !mknShimiaBamboo()
            || !mknBokutoisWooden()
            || !mknTonfaUsedInPairs()
            || !mknNunchakuSpecialSkill()
            || !mknNunchakuSilkOrChain()
            || !mknKamaRiceSickle()
            || !mknPoisAFoundPotion()
            || !mknPoisAArsenicEtc()
            || !mknPoisBFoundGasDarts()
            || !mknPoisBNeurotoxic()
            || !mknPoisCFoundCreatures()
            || !mknPoisCHemotoxic()
            || !mknPoisSaveFailIsPoisoned()
            || !mknPoisSurvivorStricken()
            || !mknPoisStrickenOnConsciousness()
            || !mknPoisNeutralizeCancelsAll()
            || !mknPoisArmorNoEffectInternal()
            || !mknPoisEachPortionOwnSave()
        )
            ++bad;
        // the kedo combat matrix - nine attacker moves down, nine defender
        // moves across, the outcome codes: blocked 0, cut 1, dla 2, dra 3,
        // ara 4, ala 5 and the odd dar 6; the six diagonal breaks (migi-men,
        // migi-do, gyaku-do, kote, hidari-kote and tsuki cut against their
        // own defense) and the crossed migi-do/gyaku-do blocked cells pin as
        // printed, noted never silent (print 24, PDF 26)
        int CKd[9][9] = {
            {0,5,4,1,1,4,1,1,0},
            {2,0,4,3,1,4,1,1,1},
            {3,6,1,3,4,1,1,1,1},
            {1,3,4,1,0,4,4,1,1},
            {1,1,3,0,1,4,4,1,1},
            {3,3,1,3,3,1,1,1,1},
            {1,1,1,3,3,1,1,0,0},
            {1,1,1,1,1,1,0,1,0},
            {0,1,1,1,1,0,0,0,0},
            };
        for (int b = 0;
             b < mknKedoMoves();
             ++b) {
            int vals[9];
            vals[0] = mknKedoVsShomen(b);
            vals[1] = mknKedoVsHidariMen(b);
            vals[2] = mknKedoVsMigiMen(b);
            vals[3] = mknKedoVsMigiDo(b);
            vals[4] = mknKedoVsGyakuDo(b);
            vals[5] = mknKedoVsKote(b);
            vals[6] = mknKedoVsHidariKote(b);
            vals[7] = mknKedoVsTsuki(b);
            vals[8] = mknKedoVsBlock(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CKd[b][c])
                    ++bad;
            }
        }
        // the effective-use-of-poison grid - the A potion, B gas/darts and C
        // creature rows with the death percent, the death timing (A and B in
        // turns, C in days, pinned as printed), the stricken span (the A week
        // pinned as 7 days) and the unconscious delay and duration (the A row
        // rides the sentinel, the C one-hour delay pinned as 60 minutes)
        // (print 24, PDF 26)
        int CPz[3][8] = {
            {80,2,8,7,7,-99,-99,-99},
            {50,4,16,1,3,30,1,4},
            {10,1,4,1,10,60,2,8},
            };
        int nPz[8] = {0,0,0,0,0,0,0,0};
        int ePz[8] = {0,0,0,0,0,1,1,1};
        for (int b = 0;
             b < mknPoisCodes();
             ++b) {
            int vals[8];
            vals[0] = mknPoisDeathPct(b);
            vals[1] = mknPoisDeathMin(b);
            vals[2] = mknPoisDeathMax(b);
            vals[3] = mknPoisStrickenMin(b);
            vals[4] = mknPoisStrickenMax(b);
            vals[5] = mknPoisUnconcDelay(b);
            vals[6] = mknPoisUnconcDurMin(b);
            vals[7] = mknPoisUnconcDurMax(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != CPz[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nPz[c];
            }
        }
        for (int c = 0; c < 8; ++c)
            if (nPz[c] != ePz[c])
                ++bad;
        // the spell census - nineteen spells, the per-level counts
        // 1/2/4/4/2/6, and the Nature Call summon range, hit-die penalty,
        // messenger days and arrival span (print 13, PDF 15)
    if (mknSullinSpells() != 19
            || mknSpellsLvl1() != 1
            || mknSpellsLvl3() != 4
            || mknSpellsLvl4() != 4
            || mknSpellsLvl6() != 6
            || mknNcrSummonMin() != 1
            || mknNcrSummonMax() != 10
            || mknNcrHitDiePenalty() != 2
            || mknNcrMessengerDays() != 3
            || mknNcrArrivalTurnsMax() != 4
        )
            ++bad;
        // Magic Missile II - one +2 arrow or two +1 arrows per five levels
        // beyond third - and the Extend family - levels 3/4/5 at 50 percent,
        // Extend III doubling the range (print 13, PDF 15)
    if (mknMmiPlusTwoArrows() != 1
            || mknMmiPlusOneArrows() != 2
            || mknMmiBonusEveryLevels() != 5
            || mknMmiBeyondLevel() != 3
            || mknExtOneMaxSpellLevel() != 3
            || mknExtOneRangePct() != 50
            || mknExtTwoMaxSpellLevel() != 4
            || mknExtThreeMaxSpellLevel() != 5
        )
            ++bad;
        // Flamebolt - 3-24 to the living, 3-30 to the undead, 5-foot
        // ignition, 240-foot range, level plus 1-3 fires - and Mystic Rope -
        // 100 feet, one point per four feet, one foot regenerated per melee
        // turn (print 13, PDF 15)
    if (mknFlbLivingDice() != 3
            || mknFlbLivingDieSides() != 8
            || mknFlbUndeadDieSides() != 10
            || mknFlbIgniteRadiusFeet() != 5
            || mknFlbRangeFeet() != 240
            || mknFlbFiresBonusMax() != 3
            || mknMroLengthFeet() != 100
            || mknMroHpPerFeet() != 4
            || mknMroRegenFeetPerTurn() != 1
        )
            ++bad;
        // the 20x20x5 Pit of Flame with its 3-turn duration and the 3-dice
        // fifth-level example, Word of Warding one melee turn with the
        // third-level ceiling after immediate use, the ten-foot Force Field
        // at 60 feet (print 13, PDF 15)
    if (mknPofWidthFeet() != 20
            || mknPofDepthFeet() != 5
            || mknPofDurationTurns() != 3
            || mknPofFifthLevelDice() != 3
            || mknWowDurationMeleeTurns() != 1
            || mknWowImmediateMaxSpellLevel() != 3
            || mknFfdDiameterFeet() != 10
            || mknFfdRangeFeet() != 60
        )
            ++bad;
        // Shatterray - 5-30 damage, 20 structure points, one die per level
        // beyond seventh to the 12-dice cap, five structural points per level
        // to the 60 cap, 120-foot range (print 13, PDF 15)
    if (mknShdDamageDice() != 5
            || mknShdDamageDieSides() != 6
            || mknShdStructurePoints() != 20
            || mknShdBonusBeyondLevel() != 7
            || mknShdMaxDamageDice() != 12
            || mknShdStructBonusPerLevel() != 5
            || mknShdMaxStructPoints() != 60
            || mknShdRangeFeet() != 120
        )
            ++bad;
        // the 50x20 Wall of Water - 5-30 to flame breaking through, the
        // five-hit-dice floor, one hour - and the Beam of Blasting 30-foot
        // blast, 50-point cap, 200-foot range (print 13, PDF 15)
    if (mknWwdLengthFeet() != 50
            || mknWwdHeightFeet() != 20
            || mknWwdBreakDice() != 5
            || mknWwdBreakDieSides() != 6
            || mknWwdBlocksBelowHd() != 5
            || mknWwdDurationHours() != 1
            || mknBbbBlastDiameterFeet() != 30
            || mknBbbMaxDamage() != 50
            || mknBbbRangeFeet() != 200
        )
            ++bad;
        // Beam of Blasting 1 per Gold Piece doubling at twelfth level, the
        // 24-hour djinn/efreet service, Density Control 3 turns at armor
        // class one, Combine I at 7 levels or 3 spells, Call Spirit two
        // questions at 25 percent within 20 feet (print 13, PDF 15)
    if (mknBbbDmgPerGp() != 1
            || mknBbbBonusEveryLevels() != 3
            || mknBbbBeyondLevel() != 9
            || mknBbbTwelfthDmgPerGp() != 2
            || mknCdeServiceHours() != 24
            || mknDcoDurationTurns() != 3
            || mknDcoMaxDensityAc() != 1
            || mknCmbMaxSpellLevels() != 7
            || mknCmbMaxSpells() != 3
            || mknCspQuestions() != 2
            || mknCspMinChancePct() != 25
            || mknCspRemainsWithinFeet() != 20
        )
            ++bad;
        // the monkish census - the 9x9 kedo matrix shape, eight attacks
        // claimed but seven printed, the seven-foot bow at 40-50 with the
        // 90-pound expert draw and 39-inch arrows, seven ranks with the
        // Novice four weapons (print 23-24, PDF 25-26)
    if (mknKedoMoves() != 9
            || mknKedoDefenses() != 9
            || mknKedoAttacksClaimed() != 8
            || mknKedoAttacksPrinted() != 7
            || mknKyudoBowFeet() != 7
            || mknKyudoDrawLbMin() != 40
            || mknKyudoExpertDrawLb() != 90
            || mknKyudoArrowInches() != 39
            || mknMonkRanks() != 7
            || mknRankNoviceWeapons() != 4
        )
            ++bad;
        // the poison frame - the three codes, the four stricken stats halved,
        // the armor saving-throw ladder +2/+1/0/-2 (print 24, PDF 26)
    if (mknPoisCodes() != 3
            || mknStrickenStats() != 4
            || mknStrickenDivisor() != 2
            || mknArmorPlate() != 2
            || mknArmorChain() != 1
            || mknArmorLeather() != 0
            || mknArmorNone() != -2
        )
            ++bad;
        // the kedo matrix blocked cells - the shomen and hidari-men
        // diagonals, the crossed migi-do and gyaku-do blocks, the front-block
        // row blocked at shomen and both hidari-kote and tsuki blocked only
        // by the front block (print 24, PDF 26)
    if (mknKedoVsShomen(0) != 0
            || mknKedoVsBlock(0) != 0
            || mknKedoVsShomen(8) != 0
            || mknKedoVsBlock(8) != 0
            || mknKedoVsHidariMen(1) != 0
            || mknKedoVsGyakuDo(3) != 0
            || mknKedoVsMigiDo(4) != 0
            || mknKedoVsHidariKote(8) != 0
            || mknKedoVsTsuki(8) != 0
        )
            ++bad;
        // the kedo odd cells - the dar 6 at migi-men vs hidari-men, the ala 5
        // and dla 2 and ara 4 arm codes, the six diagonal breaks migi-men,
        // migi-do, gyaku-do, kote, hidari-kote and tsuki, the front-block row
        // blocked 0 (print 24, PDF 26)
    if (mknKedoVsHidariMen(2) != 6
            || mknKedoVsHidariMen(0) != 5
            || mknKedoVsShomen(1) != 2
            || mknKedoVsKote(0) != 4
            || mknKedoVsMigiMen(2) != 1
            || mknKedoVsMigiDo(3) != 1
            || mknKedoVsGyakuDo(4) != 1
            || mknKedoVsKote(5) != 1
            || mknKedoVsHidariKote(6) != 1
            || mknKedoVsTsuki(7) != 1
            || mknKedoVsShomen(8) != 0
        )
            ++bad;
        // the poison grid - 80/50/10 death percentages, the 16-turn B death
        // maximum, the A week pinned as 7 days, the 30-minute and 60-minute
        // unconscious delays, the 8-day C duration, the A unconscious cells
        // riding the sentinel (print 24, PDF 26)
    if (mknPoisDeathPct(0) != 80
            || mknPoisDeathPct(1) != 50
            || mknPoisDeathPct(2) != 10
            || mknPoisDeathMax(1) != 16
            || mknPoisStrickenMax(0) != 7
            || mknPoisStrickenMax(2) != 10
            || mknPoisUnconcDelay(1) != 30
            || mknPoisUnconcDelay(2) != 60
            || mknPoisUnconcDurMax(2) != 8
            || mknPoisUnconcDelay(0) != -99
        )
            ++bad;
        printf("R935 issue-18 opener part two audit: bad %d\n", bad);
        if (bad) return 1;
    }
