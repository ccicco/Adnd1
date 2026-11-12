    // ---- R931 issue-17 opener part one audit ----
    // THE DRAGON ISSUE-17 OPENER PART ONE - the seven engine-relevant chains
    // of the potpourri issue, the Ward wizard article riding the part-two
    // round. CHAIN ONE, Jousting in D&D by Jon Pickens (print 4, PDF 6), the
    // Chainmail system rebuilt for D&D levels and magical equipment: the
    // eight-by-six joust matrix (HELM, DC, CP, SC, DF, FP, SF, BASE over
    // Lower Helm, Lean Right, Lean Left, Steady Seat, Shield High, Shield
    // Low), the attacker position grid (the 4-6, 3-6, Any, 2,4-6, 1,4-6
    // prints as allowed flags), the four-row results table across seven
    // knight level comparison bands (U at 25-15, U/B at 23-13, B at 21-11, G
    // at 17-7), the six-band injury percentile table from 10 percent to the
    // 00 kill, the level-comparison chain, the 10 percent unhorsed injury
    // with 20 added on the helm knock-off, the no-strength-dex-bonus
    // doctrine. CHAIN TWO, Vampires in the Dungeon by Clayton Miner (print 3,
    // PDF 5), the tactics doctrine: the charm-many-then-banquet, the rat spy
    // network, the 50 mph gaseous offensive, the stake doctrine at four
    // strokes maximum of hawthorn or blackthorn, the century crumble, the
    // coffin booby traps, the 8:69 strength garble at the sentinel. CHAIN
    // THREE, Sights and Sounds in D&D by Dushay and Weisberg (print 15, PDF
    // 17): the 25 percent noise chance every 30 minutes, the 21-row sounds
    // table as scanned with the joke row 21, the 20-row sights table, the
    // real-to-all-senses apparitions that vanish after the party leaves.
    // CHAIN FOUR, the joke monsters (print 16-17, PDF 18-19), pinned with
    // their printed stat ink - the Magic Munchkin (clans 3-12, the four-foot
    // mother, one magic munchkin in ten per 25 casting at eighteenth level,
    // the 5 percent weekly cumulative leave chance, the Munchkin Slaying
    // auto-kill), the Scholar (AC 9, HD 1-3, lair 30, 5 cp, the three ranks
    // with their spell counts, the 3-18 Academic Dust, the Tenure denied
    // cardiac arrest), the Crs'tchen (NA 1-12, AC 12, HD 1/2, move 15, the 33
    // percent alignment change, the 30-30-30-5-5 transfix table, the 100-600
    // K beg, burn within three turns, Eyes 1, 16 and 19). CHAIN FIVE, the
    // Tesseracts by Gary Jordan (print 20 + 22, PDF 22 + 24), the hypercube
    // dungeon: eight rooms, four central doors, the all-doors-closed
    // activation, the U/L upside-down anomaly, the dispel collapse. CHAIN
    // SIX, A Short History of Adamanite (print 31-32, PDF 33-34): the ten-row
    // base price grid from plate 20000 to arrow points 400@ with the nil
    // weight at the sentinel, the charm costs 8000 per level plate and 4000
    // sword or shield beyond the +2, the 20-40 and 25-60 market multipliers,
    // the Snog 8th level goblin tale with the 50-25-25 tribute split, the
    // diamond test. CHAIN SEVEN, Messengers of God: Angels in D&D by Stephen
    // Dorneman (print 32-33, PDF 34-35): the four-type stat grid (Wrath AC 0,
    // 10d8, MR 65, 12/24; Healing AC 9, 6 dice, MR 75; Mercy AC -1, 12 dice,
    // MR 85, 15/30; Seraphim AC -3, 16 dice, MR 95, 24/48), the weapon floors
    // 1, 0, 2, 3, the common abilities doctrine (teleport no error, turn
    // undead as Patriarch, immune to psionic and Finger of Death), the 1
    // percent per cleric level prayer response, the Wrath +5 Holy Sword and
    // three double-strength walls, the Seraphim triple-strength wall, Holy
    // Word and Symbol once a day, the Wrath of God double-strength Meteor
    // Swarm, the 2-16, 1-4, 1-6 summons.
    {
        using namespace rules;
        int bad = 0;
    if (jouMatrixDieSides() != 20
            || jouResolutionSteps() != 6
            || jouUnhorsedInjuryPercent() != 10
            || jouHelmKnockoffInjuryBonusPercent() != 20
            || jouMatrixRows() != 8
            || jouResultsRows() != 4
            || jouInjuryRows() != 6
            || jouVmpGaseousSpeedMph() != 50
            || jouVmpStakeStrokesMax() != 4
            || jouVmpCrumbleDustAgeYears() != 100
            || jouVmpMinStrength() != -1
            || jouSsgSoundChancePercent() != 25
            || jouSsgSoundIntervalMinutes() != 30
            || jouSsgSoundRows() != 21
            || jouSsgSightRows() != 20
            || jouMjkClanMin() != 3
            || jouMjkClanMax() != 12
            || jouMjkMotherHeightInches() != 48
            || jouMjkOffspringMinInches() != 36
            || jouMjkOffspringMaxInches() != 48
            || jouMjkMaleParentPercent() != 5
            || jouMjkOffspringMalePercent() != 75
            || jouMjkMagicChancePercent() != 10
            || jouMjkMagicPerGroup() != 25
            || jouMjkMagicSpellsPerDay() != 1
            || jouMjkMagicSpellLevelMax() != 9
            || jouMjkMagicCasterLevel() != 18
            || jouMjkMotherSpellsPerDay() != 3
            || jouMjkLeaveChancePercent() != 5
            || jouSchNumberMin() != 1
            || jouSchNumberMax() != 4
            || jouSchSymposiumMin() != 10
            || jouSchSymposiumMax() != 20
            || jouSchArmorClass() != 9
            || jouSchHdMin() != 1
            || jouSchHdMax() != 3
            || jouSchHdSides() != 6
            || jouSchLairPercent() != 30
            || jouSchTreasureCopper() != 5
            || jouSchInstructorSpells() != 2
            || jouSchAssociateSpells() != 3
            || jouSchFoolSpells() != 3
            || jouSchBookMissileMin() != 1
            || jouSchBookMissileMax() != 8
            || jouSchDustMin() != 3
            || jouSchDustMax() != 18
            || jouSchParalyzeMinTurns() != 2
            || jouSchParalyzeMaxTurns() != 4
            || jouCrsNumberMin() != 1
            || jouCrsNumberMax() != 12
            || jouCrsArmorClass() != 12
            || jouCrsMoveFeet() != 15
            || jouCrsLairPercent() != 80
            || jouCrsLairGoldPercent() != 30
            || jouCrsAlignmentChangePercent() != 33
            || jouCrsTransfix3Percent() != 30
            || jouCrsTransfix4Percent() != 30
            || jouCrsTransfix5Percent() != 30
            || jouCrsTransfixHalfDayPercent() != 5
            || jouCrsTransfixFullDayPercent() != 5
            || jouCrsBegMoneyPercent() != 20
            || jouCrsBegMoneyMinK() != 100
            || jouCrsBegMoneyMaxK() != 600
            || jouCrsBegServicePercent() != 10
            || jouCrsBegServiceMinDays() != 1
            || jouCrsBegServiceMaxDays() != 12
            || jouCrsBurnWithinTurns() != 3
            || jouCrsEyeOne() != 1
            || jouCrsEyeSixteen() != 16
            || jouCrsEyeNineteen() != 19
            || jouTsvRooms() != 8
            || jouTsvCentralDoors() != 4
            || jouTsvCommonSides() != 1
            || jouTsvCommonEdges() != 4
            || jouAdmRows() != 10
            || jouAdmCharmCostPlatePerLevel() != 8000
            || jouAdmCharmCostSwordShieldPerLevel() != 4000
            || jouAdmCharmBasePlus() != 2
            || jouAdmCharmMaxYears() != 1
            || jouAdmHardenedPriceMin() != 20
            || jouAdmHardenedPriceMax() != 40
            || jouAdmTemperablePriceMin() != 25
            || jouAdmTemperablePriceMax() != 60
            || jouAdmImitationHitProbPenalty() != 1
            || jouAdmImitationPlusFirst() != 2
            || jouAdmImitationPlusSecond() != 1
            || jouAdmMuProfitPercent() != 100
            || jouAdmDiscoveryToInvasionMonths() != 14
            || jouAdmResearchYears() != 5
            || jouAdmFormulaReturnYears() != 2
            || jouAdmSnogFighterLevel() != 8
            || jouAdmSnogGuardsLevel() != 2
            || jouAdmTributeKingPercent() != 50
            || jouAdmTributeChurchPercent() != 25
            || jouAdmTributeSoldiersPercent() != 25
            || jouAngRows() != 4
            || jouAngResponseBasePercent() != 1
            || jouAngHierarchyTypes() != 9
            || jouAngRecordedTypes() != 4
            || jouAngWrathSwordPlus() != 5
            || jouAngWrathWallPerDay() != 3
            || jouAngWrathWallMultiplier() != 2
            || jouAngWrathHolyWordPerDay() != 1
            || jouAngSeraphWallMultiplier() != 3
            || jouAngSeraphHolyWordPerDay() != 1
            || jouAngSeraphSymbolPerDay() != 1
            || jouAngSeraphWrathOfGodMultiplier() != 2
            || jouAngSummonOneMin() != 2
            || jouAngSummonOneMax() != 16
            || jouAngSummonTwoMin() != 1
            || jouAngSummonTwoMax() != 4
            || jouAngSummonThreeMin() != 1
            || jouAngSummonThreeMax() != 6
            || !jouNoStrengthDexBonuses()
            || !jouShieldBonusHelmOnlyShieldHigh()
            || !jouHelmSteadySeatZeroSpecial()
            || !jouGlancingBlowMissExceptHelm()
            || !jouMagicalLanceBreaksIfShieldHigher()
            || !jouInjuryConCheckVsResurrection()
            || !jouContinueRidesUntilUnhorsed()
            || !jouVmpCharmManyThenBanquet()
            || !jouVmpRatSpyNetwork()
            || !jouVmpGaseousOffensiveAssault()
            || !jouVmpGarlicProtection()
            || !jouVmpHostCircleProtection()
            || !jouVmpMirrorTwoViews()
            || !jouVmpStakeHawthornBlackthorn()
            || !jouVmpStakeTemporaryMeasure()
            || !jouVmpCoffinHolyWaterBoobyTrap()
            || !jouVmpCoffinHostDenial()
            || !jouVmpDirtStealing()
            || !jouVmpVictimInfectsNearDeathOrBlood()
            || !jouVmpSatedVampireLethargic()
            || !jouSsgSoundsCeaseOrLeadAway()
            || !jouSsgSoundsSeldomRevealCause()
            || !jouSsgNoiseRoomsDoctrine()
            || !jouSsgAcousticsDistort()
            || !jouSsgSightsRealToAllSenses()
            || !jouSsgSightsVanishAfterLeaving()
            || !jouSsgSightsMisleadLandmarks()
            || !jouSsgRustFlakesCrumbleOnTouch()
            || !jouSsgSlimeNotGreenSlime()
            || !jouMjkMatriarchalClans()
            || !jouMjkImmuneMostMagic()
            || !jouMjkRegenerative()
            || !jouMjkPermanentPests()
            || !jouMjkBoredTroublesome()
            || !jouMjkLeaveChanceCumulative()
            || !jouMjkEscapeFlyingTeleport()
            || !jouMjkMagicEscapePrevented()
            || !jouMjkSlayingWeaponAutoKill()
            || !jouMjkAncientItemsDetect()
            || !jouMjkNotForNormalExpeditions()
            || !jouSchPipeSmokeInvisibility()
            || !jouSchTenureDeniedNoSave()
            || !jouSchCauseBoredomSleep()
            || !jouSchThreeRanks()
            || !jouCrsHdHalf()
            || !jouCrsAlwaysSmilingWellDressed()
            || !jouCrsBookOfEternalExistence()
            || !jouCrsBookSelfTranslating()
            || !jouCrsBookAcHigherThanOwner()
            || !jouCrsSaveLevelThreePlus()
            || !jouCrsMagicUserControlOfSelf()
            || !jouCrsRegeneratesUnlessBurned()
            || !jouCrsRelentless()
            || !jouCrsLairCaptureLost()
            || !jouCrsDivineInterventionSaves()
            || !jouTsvAnyDoorOpenNotActivated()
            || !jouTsvAllClosedActivates()
            || !jouTsvEscapeItemDoctrine()
            || !jouTsvDispelVanishesAllButCentral()
            || !jouTsvUpDownUpsideDownAnomaly()
            || !jouTsvNoUpDownAccessRecommended()
            || !jouTsvUpperLowerAccessPlanned()
            || !jouAdmDiamondScratchesImitations()
            || !jouAdmCharmTwiceCostTwiceTime()
            || !jouAdmCharmZoomAfterThree()
            || !jouAdmUnstableImitations()
            || !jouAdmMuCostHalfListed()
            || !jouAdmReluctantMuMarket()
            || !jouAdmArrowPointsPerArrowAt()
            || !jouAngTeleportNoError()
            || !jouAngContinualLightCommon()
            || !jouAngBlessCommon()
            || !jouAngFearCommon()
            || !jouAngDetectEvilCommon()
            || !jouAngSpeakHumanTongues()
            || !jouAngSpeakWithDead()
            || !jouAngTurnUndeadAsPatriarch()
            || !jouAngImmunePsionic()
            || !jouAngImmuneFingerOfDeath()
            || !jouAngWrathArmorVanishes()
            || !jouAngHealingRegenerationTouch()
            || !jouAngHealingFlamingSword()
            || !jouAngMercySwordOfSharpness()
            || !jouAngMercyNoTimeStop()
            || !jouAngSeraphVorpalBlade()
            || !jouAngSeraphUnstunnable()
            || !jouAngNoLairUnlessRelic()
            || !jouAngNoRandomEncounters()
            || !jouAngMissionManifestationOnly()
        )
            ++bad;
        // the joust matrix - eight aiming points over six defensive
        // positions, the printed base numbers added to the d20 roll; the HELM
        // row Steady Seat cell prints 0* (the glancing-blow helm knock-off),
        // pinned 0 with the flag (folio 4, PDF 6)
        int CJm[8][6] = {
            {0,0,0,0,12,0},
            {12,4,0,4,4,0},
            {9,12,2,4,9,12},
            {2,0,4,2,2,12},
            {4,9,0,4,0,4},
            {9,2,4,9,9,4},
            {2,0,9,2,2,2},
            {4,2,12,4,9,4},
            };
        for (int b = 0;
             b < jouMatrixRows();
             ++b) {
            int vals[6];
            vals[0] = jouLowerHelm(b);
            vals[1] = jouLeanRight(b);
            vals[2] = jouLeanLeft(b);
            vals[3] = jouSteadySeat(b);
            vals[4] = jouShieldHigh(b);
            vals[5] = jouShieldLow(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CJm[b][c])
                    ++bad;
            }
        }
        // the attacker position grid - which defensive positions an attacker
        // may take, considering his own aiming point: the 4-6, 3-6, Any,
        // 2,4-6 and 1,4-6 prints encoded as one-allowed, zero-not-allowed per
        // column (folio 4, PDF 6)
        int CJa[8][6] = {
            {0,0,0,1,1,1},
            {0,0,1,1,1,1},
            {1,1,1,1,1,1},
            {0,1,0,1,1,1},
            {0,0,0,1,1,1},
            {1,1,1,1,1,1},
            {0,0,0,1,1,1},
            {1,0,0,1,1,1},
            };
        for (int b = 0;
             b < jouMatrixRows();
             ++b) {
            int vals[6];
            vals[0] = jouAttLowerHelm(b);
            vals[1] = jouAttLeanRight(b);
            vals[2] = jouAttLeanLeft(b);
            vals[3] = jouAttSteadySeat(b);
            vals[4] = jouAttShieldHigh(b);
            vals[5] = jouAttShieldLow(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CJa[b][c])
                    ++bad;
            }
        }
        // the joust results table - the minimum adjusted score per result row
        // across the seven knight level comparison bands, from -12 or more
        // through 12-up (folio 4, PDF 6)
        int CJr[4][7] = {
            {25,23,21,20,19,17,15},
            {23,21,19,18,17,15,13},
            {21,19,17,16,15,13,11},
            {17,15,13,12,11,9,7},
            };
        for (int b = 0;
             b < jouResultsRows();
             ++b) {
            int vals[7];
            vals[0] = jouResMinus12(b);
            vals[1] = jouResMinus8(b);
            vals[2] = jouResMinus4(b);
            vals[3] = jouResMinus3to3(b);
            vals[4] = jouResPlus4(b);
            vals[5] = jouResPlus8(b);
            vals[6] = jouResPlus12(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CJr[b][c])
                    ++bad;
            }
        }
        // the joust injury percentile table - six bands, hit points lost as a
        // percentage of total, from 01-60 at 10 percent to the 00 kill; the
        // 00 row pins the percent 100 with the hp column 0 - the knight is
        // KILLED, the 0 is the kill marker not a zero loss (folio 4, PDF 6)
        int CJi[6][2] = {
            {60,10},
            {75,25},
            {85,33},
            {95,50},
            {99,80},
            {100,0},
            };
        for (int b = 0;
             b < jouInjuryRows();
             ++b) {
            int vals[2];
            vals[0] = jouInjuryUpper(b);
            vals[1] = jouInjuryHpPct(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CJi[b][c])
                    ++bad;
            }
        }
        // the adamanite base price grid - ten rows of handcrafted uncharmed
        // +2 equipment, price in GP and weight in GP; the arrow points weight
        // prints nil and rides the sentinel, the price printing 400@ per
        // arrow (folios 31-32, PDF 33-34)
        int CJd[10][2] = {
            {20000,600},
            {14000,400},
            {4000,40},
            {4000,120},
            {4000,40},
            {5000,120},
            {3000,80},
            {2000,80},
            {1500,16},
            {400,-1},
            };
        int nJd[2] = {0,0};
        int eJd[2] = {0,1};
        for (int b = 0;
             b < jouAdmRows();
             ++b) {
            int vals[2];
            vals[0] = jouAdmPriceGold(b);
            vals[1] = jouAdmWeightGold(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CJd[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nJd[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nJd[c] != eJd[c])
                ++bad;
        // the four angel types in printed order - the Angel of Wrath, the
        // Angel of Healing, the Archangel of Mercy, the Seraphim; only the
        // Wrath prints its hit-dice sides (eight-sided), the other three ride
        // the sentinel; the Healing secondary move prints the garbled quarter
        // and rides the sentinel; the weapon floor is the magic-plus needed
        // to hit, 0 where none prints; the Mercy AC minus 1 is genuine ink
        // that shares the sentinel value - the AC census of 1 locks it, the
        // pin IS the value (folios 32-33, PDF 34-35)
        int CJg[4][7] = {
            {0,10,8,65,12,24,1},
            {9,6,-1,75,15,-1,0},
            {-1,12,-1,85,15,30,2},
            {-3,16,-1,95,24,48,3},
            };
        int nJg[7] = {0,0,0,0,0,0,0};
        int eJg[7] = {1,0,3,0,0,1,0};
        for (int b = 0;
             b < jouAngRows();
             ++b) {
            int vals[7];
            vals[0] = jouAngAc(b);
            vals[1] = jouAngHitDice(b);
            vals[2] = jouAngDiceSides(b);
            vals[3] = jouAngMagicResist(b);
            vals[4] = jouAngMovePrimary(b);
            vals[5] = jouAngMoveSecondary(b);
            vals[6] = jouAngWeaponFloor(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CJg[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nJg[c];
            }
        }
        for (int c = 0; c < 7; ++c)
            if (nJg[c] != eJg[c])
                ++bad;
        // the jouLevelBand band-for boundaries
    if (jouLevelBand(-13) != 0
            || jouLevelBand(-12) != 0
            || jouLevelBand(-8) != 1
            || jouLevelBand(-11) != 1
            || jouLevelBand(-4) != 2
            || jouLevelBand(-7) != 2
            || jouLevelBand(3) != 3
            || jouLevelBand(-3) != 3
            || jouLevelBand(7) != 4
            || jouLevelBand(4) != 4
            || jouLevelBand(11) != 5
            || jouLevelBand(8) != 5
            || jouLevelBand(12) != 6
        )
            ++bad;
        // the jousting doctrine - a 10 percent injury chance on unhorsing, 20
        // added on the helm knock-off, the d20 matrix, the six resolution
        // steps, the level-comparison bands at their edges (folio 4)
    if (jouUnhorsedInjuryPercent() != 10
            || jouHelmKnockoffInjuryBonusPercent() != 20
            || jouMatrixDieSides() != 20
            || jouResolutionSteps() != 6
            || jouLevelBand(-12) != 0
            || jouLevelBand(-11) != 1
            || jouLevelBand(3) != 3
            || jouLevelBand(12) != 6
        )
            ++bad;
        // the vampire and dressing doctrine - the 50 mph gaseous rush, the
        // four-stroke stake maximum, the century crumble, the garbled
        // strength cell at the sentinel, the 25 percent noise chance every 30
        // minutes, the 21-row sounds print and the 20 sights (folios 3, 15)
    if (jouVmpGaseousSpeedMph() != 50
            || jouVmpStakeStrokesMax() != 4
            || jouVmpCrumbleDustAgeYears() != 100
            || jouVmpMinStrength() != -1
            || jouSsgSoundChancePercent() != 25
            || jouSsgSoundIntervalMinutes() != 30
            || jouSsgSoundRows() != 21
            || jouSsgSightRows() != 20
        )
            ++bad;
        // the joke monsters - munchkin clans to 12, the four-foot mother, one
        // magic munchkin in ten per 25 casting at eighteenth level, the
        // mother at three spells a day, the Scholar AC 9, 30 percent lair, 5
        // cp and the 3-18 Academic Dust (folios 16-17)
    if (jouMjkClanMax() != 12
            || jouMjkMotherHeightInches() != 48
            || jouMjkMagicChancePercent() != 10
            || jouMjkMagicPerGroup() != 25
            || jouMjkMagicCasterLevel() != 18
            || jouMjkMotherSpellsPerDay() != 3
            || jouSchArmorClass() != 9
            || jouSchLairPercent() != 30
            || jouSchTreasureCopper() != 5
            || jouSchDustMax() != 18
        )
            ++bad;
        // the Crs'tchen and the tesseract - AC 12 in the EPT print, move 15,
        // the 33 percent alignment change, the 100-600 K beg, burn within
        // three turns, Eye 16, eight tesseract rooms with four central doors
        // and four common edges (folios 17, 20+22)
    if (jouCrsArmorClass() != 12
            || jouCrsMoveFeet() != 15
            || jouCrsAlignmentChangePercent() != 33
            || jouCrsBegMoneyMaxK() != 600
            || jouCrsBurnWithinTurns() != 3
            || jouCrsEyeSixteen() != 16
            || jouTsvRooms() != 8
            || jouTsvCentralDoors() != 4
            || jouTsvCommonEdges() != 4
        )
            ++bad;
        // the adamanite economics - 8000 GP per level to charm plate, 4000
        // for sword or shield, the 20-40 hardened and 25-60 temperable
        // multipliers, Snog the 8th level goblin, the 50-25-25 tribute split,
        // the unstable +2 imitation (folio 32)
    if (jouAdmCharmCostPlatePerLevel() != 8000
            || jouAdmCharmCostSwordShieldPerLevel() != 4000
            || jouAdmHardenedPriceMin() != 20
            || jouAdmTemperablePriceMax() != 60
            || jouAdmSnogFighterLevel() != 8
            || jouAdmTributeKingPercent() != 50
            || jouAdmTributeChurchPercent() != 25
            || jouAdmImitationPlusFirst() != 2
        )
            ++bad;
        // the angels - the 1 percent per level prayer response, nine
        // classical types with four recorded, the Wrath +5 Holy Sword and
        // three double-strength walls a day, the Seraphim triple-strength
        // wall, Holy Word and the 2-16 Type I summons (folios 32-33)
    if (jouAngResponseBasePercent() != 1
            || jouAngRecordedTypes() != 4
            || jouAngHierarchyTypes() != 9
            || jouAngWrathSwordPlus() != 5
            || jouAngWrathWallPerDay() != 3
            || jouAngSeraphWallMultiplier() != 3
            || jouAngSeraphHolyWordPerDay() != 1
            || jouAngSummonOneMin() != 2
            || jouAngSummonOneMax() != 16
        )
            ++bad;
        // the joust matrix spot cells - DC 12 on Lower Helm, the HELM Steady
        // Seat 0*, HELM 12 on Shield High, DC 4 on Lean Right, CP 12 on
        // Shield Low, BASE 4 on Steady Seat, SF 2 on Shield High (folio 4)
    if (jouLowerHelm(1) != 12
            || jouSteadySeat(0) != 0
            || jouShieldHigh(0) != 12
            || jouLeanRight(1) != 4
            || jouShieldLow(2) != 12
            || jouSteadySeat(7) != 4
            || jouShieldHigh(6) != 2
        )
            ++bad;
        // the attacker position grid - BASE may take Lower Helm, HELM may
        // not; DC may take Lean Left, HELM may not; CP may take anything
        // (folio 4)
    if (jouAttLowerHelm(7) != 1
            || jouAttLowerHelm(0) != 0
            || jouAttLeanLeft(1) != 1
            || jouAttLeanLeft(0) != 0
            || jouAttLeanRight(2) != 1
            || jouAttSteadySeat(3) != 1
            || jouAttShieldLow(2) != 1
        )
            ++bad;
        // the joust results spot cells - U at 25, 20 and 15 across the bands;
        // G at 17, 12 and 7; U/B at 21 on the minus-8 band (folio 4)
    if (jouResMinus12(0) != 25
            || jouResMinus3to3(0) != 20
            || jouResPlus12(0) != 15
            || jouResMinus12(3) != 17
            || jouResMinus3to3(3) != 12
            || jouResPlus12(3) != 7
            || jouResMinus8(1) != 21
        )
            ++bad;
        // the injury table - 01-60 at 10 percent, 96-99 at 80 percent, the 00
        // kill at 100, the 76-85 band at 33 percent (folio 4)
    if (jouInjuryUpper(0) != 60
            || jouInjuryHpPct(0) != 10
            || jouInjuryUpper(4) != 99
            || jouInjuryHpPct(4) != 80
            || jouInjuryUpper(5) != 100
            || jouInjuryHpPct(5) != 0
            || jouInjuryHpPct(2) != 33
        )
            ++bad;
        // the adamanite price grid - plate 20000 at 600, chain 14000, the
        // two-handed sword 5000, arrow points 400@ with the nil weight at the
        // sentinel, the shield at 120 (folios 31-32)
    if (jouAdmPriceGold(0) != 20000
            || jouAdmWeightGold(0) != 600
            || jouAdmPriceGold(1) != 14000
            || jouAdmPriceGold(5) != 5000
            || jouAdmPriceGold(9) != 400
            || jouAdmWeightGold(9) != -1
            || jouAdmWeightGold(3) != 120
        )
            ++bad;
        // the angel grid - Wrath AC 0, Seraphim AC minus 3 and 16 dice, the
        // Wrath eight-sided print, the Healing sides at the sentinel, 75 MR,
        // Mercy 15/30 with the plus-2 floor, the Seraphim 24 primary move
        // (folios 32-33)
    if (jouAngAc(0) != 0
            || jouAngAc(3) != -3
            || jouAngHitDice(3) != 16
            || jouAngDiceSides(0) != 8
            || jouAngDiceSides(1) != -1
            || jouAngMagicResist(1) != 75
            || jouAngMoveSecondary(2) != 30
            || jouAngWeaponFloor(2) != 2
            || jouAngMovePrimary(3) != 24
        )
            ++bad;
        printf("R931 issue-17 opener part one audit: bad %d\n", bad);
        if (bad) return 1;
    }
