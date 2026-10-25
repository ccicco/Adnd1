    // ---- R806 MM2 letters HI walk audit ----
    // THE MM2 LETTERS HI WALK - the hangman tree, the haunt pp. 74-75, the
    // hollyphant, the hordling pp. 75-76 and the hybsil pp. 76-77 promoted to
    // the live registry; the letter-I span walks empty - the ildriss is the
    // only letter-I entry and it rode the R805 FG walk, so the Letter I box
    // closes on the already-pinned def; the contested cells settled: the
    // hangman tree hit-dice cell "61 hp/year" pins capture verbatim (the
    // 1eonline compilation notes the intended 6-plus-1-per-year typo reading;
    // the avgHp reads the flat printed 61 hp - the demilich precedent - and
    // the hitDiceNum reads the flat-hp 0 dice; the magic resistance reads the
    // 1% per year); the haunt attacks cell "1/1, as 5 HD monster" loads the
    // max 5 (the R798 duergar convention - the R805 grim lesson); the haunt
    // block prints no size or magic resistance line (the size reads empty,
    // the magic resistance reads Nil 0); the hordling or-form cells read
    // their best variant (the 9 hit dice, the 3 armor class, the 6 ground
    // move, the 0 magic resistance, the VII/1400 + 12/hp xp); the hybsil xp
    // level reads II (the capture "ll" and the djvu "11" both the OCR
    // misreads); the hybsil "pixie" (the capture "poie" the misread); the
    // hollyphant "2\"+ long" and hangman tree "20\"+ tall" feet/inches print
    // typos pinned verbatim
    {
        using namespace rules;
        int bad = 0;
    if (mm2hiRound() != 806
            || mm2hiRegistryBefore() != 650
            || mm2hiRegistryAfter() != 655
            || mm2hiDefCount() != 5
            || mm2hiEntryCount() != 5
            || mm2hiStatBlockHeadings() != 5
            || mm2hiDoctrineHeads() != 0
            || mm2hiLetterHHeadings() != 5
            || mm2hiLetterIHeadings() != 0
            || mm2hiHhStatRows() != 5
            || mm2hiGapClosed() != 14
            || mm2hiGapOpen() != 23
            || mm2hiPriorOwnedEntries() != 1
            || mm2hiIldrissOwningRound() != 805
            || mm2hiHangmanTreeXpValue() != 2088
            || mm2hiHangmanTreeXpLevel() != 7
            || mm2hiHangmanTreeAppendagesMin() != 6
            || mm2hiHangmanTreeAppendagesMax() != 9
            || mm2hiHangmanTreeControlledAppendages() != 3
            || mm2hiHangmanTreeVineSeverMin() != 13
            || mm2hiHangmanTreeVineSeverMax() != 20
            || mm2hiHangmanTreeVineDamageMax() != 3
            || mm2hiHangmanTreeLiftPounds() != 1000
            || mm2hiHangmanTreeLiftRounds() != 4
            || mm2hiHangmanTreeDropRound() != 5
            || mm2hiHangmanTreeAcidDamageMax() != 12
            || mm2hiHangmanTreeDigestVictims() != 3
            || mm2hiHangmanTreePerfumeRangeMinFeet() != 30
            || mm2hiHangmanTreePerfumeRangeMaxFeet() != 80
            || mm2hiHangmanTreeMrPerYear() != 1
            || mm2hiHangmanTreeSproutAgeMax() != 10
            || mm2hiHangmanTreeSaplingAgeMin() != 11
            || mm2hiHangmanTreeSaplingAgeMax() != 25
            || mm2hiHangmanTreeSaplingMoveFeetPerHour() != 6
            || mm2hiHangmanTreeMatureAgeMin() != 26
            || mm2hiHangmanTreeMatureAgeMax() != 75
            || mm2hiHangmanTreeOldAgeMin() != 76
            || mm2hiHangmanTreeOldAgeMax() != 150
            || mm2hiHangmanTreeAncientAgeMin() != 151
            || mm2hiHangmanTreeDarknessEfficiencyPct() != 50
            || mm2hiHauntXpValue() != 250
            || mm2hiHauntXpLevel() != 4
            || mm2hiHauntAreaRadiusInches() != 6
            || mm2hiHauntDexDrain() != 2
            || mm2hiHauntPossessDexFloor() != 0
            || mm2hiHauntReleaseVictimDex() != 3
            || mm2hiHauntDexRegainPerTurn() != 1
            || mm2hiHauntStrangleStart() != 1
            || mm2hiHauntStrangleSecond() != 2
            || mm2hiHauntStrangleThird() != 4
            || mm2hiHauntWeaponDamage() != 1
            || mm2hiHauntFireDamagePerRound() != 1
            || mm2hiHauntReformWeeks() != 1
            || mm2hiHauntAttackAsHd() != 5
            || mm2hiHauntFormCount() != 2
            || mm2hiHollyphantXpValue() != 4254
            || mm2hiHollyphantXpLevel() != 8
            || mm2hiHollyphantTrumpsPerDay() != 3
            || mm2hiHollyphantDeafenConeLengthInches() != 7
            || mm2hiHollyphantSunSparkleDamageDice() != 8
            || mm2hiHollyphantSunSparkleBonus() != 8
            || mm2hiHollyphantSpellLevel() != 16
            || mm2hiHollyphantBanishRangeInches() != 2
            || mm2hiHollyphantBanishHdCap() != 32
            || mm2hiHollyphantBacklashDamageMin() != 2
            || mm2hiHollyphantBacklashDamageMax() != 12
            || mm2hiHollyphantBacklashStunSegmentsMax() != 12
            || mm2hiHollyphantCureSeriousWoundsPerDay() != 2
            || mm2hiHollyphantProtectionFromEvilPerDay() != 2
            || mm2hiHollyphantProtectionRadiusFeet() != 10
            || mm2hiHollyphantGatePct() != 50
            || mm2hiHollyphantGateHollyphantPct() != 70
            || mm2hiHollyphantGateDevaPct() != 30
            || mm2hiHollyphantDetectEvilRadiusInches() != 2
            || mm2hiHollyphantPsionicMinor() != 4
            || mm2hiHollyphantPsionicMajor() != 2
            || mm2hiHollyphantFootTravelPct() != 5
            || mm2hiHollyphantWeaponPlusMin() != 1
            || mm2hiHollyphantFlyRate() != 42
            || mm2hiHollyphantPsionicMin() != 201
            || mm2hiHollyphantPsionicMax() != 300
            || mm2hiHordlingXpValue() != 1772
            || mm2hiHordlingXpLevelTop() != 7
            || mm2hiHordlingAcTier1() != 3
            || mm2hiHordlingAcTier2() != 2
            || mm2hiHordlingAcTier3() != 1
            || mm2hiHordlingAcTier4() != 0
            || mm2hiHordlingMoveTier1() != 6
            || mm2hiHordlingMoveTier4() != 15
            || mm2hiHordlingHdTier1() != 6
            || mm2hiHordlingHdBonusTier1() != 3
            || mm2hiHordlingHdTier4() != 9
            || mm2hiHordlingHdBonusTier4() != 0
            || mm2hiHordlingMrTier1() != 0
            || mm2hiHordlingMrTier4() != 30
            || mm2hiHordlingXpTier1() != 525
            || mm2hiHordlingXpHpTier1() != 8
            || mm2hiHordlingXpTier4() != 1400
            || mm2hiHordlingXpHpTier4() != 12
            || mm2hiHordlingTierDie() != 4
            || mm2hiHordlingTraitTableCount() != 18
            || mm2hiHordlingTraitDie() != 6
            || mm2hiHordlingAttackTableEntries() != 15
            || mm2hiHordlingSpecialAttackCount() != 6
            || mm2hiHordlingSpecialDefenseCount() != 6
            || mm2hiHordlingDoubleSpecialPct() != 10
            || mm2hiHordlingNearInvisiblePct() != 75
            || mm2hiHordlingNearInvisibleTurns() != 1
            || mm2hiHordlingLairPctHades() != 15
            || mm2hiHordlingStrengthToHitMin() != 1
            || mm2hiHordlingStrengthToHitMax() != 2
            || mm2hiHordlingStrengthDamageMin() != 1
            || mm2hiHordlingStrengthDamageMax() != 5
            || mm2hiHordlingAcidSpittleRangeFeet() != 10
            || mm2hiHordlingAcidSpittleDamageMax() != 8
            || mm2hiHordlingRegenerateMin() != 2
            || mm2hiHordlingRegenerateMax() != 5
            || mm2hiHybsilXpValue() != 24
            || mm2hiHybsilXpLevel() != 2
            || mm2hiHybsilNoAppearingDie() != 6
            || mm2hiHybsilNoAppearingMult() != 10
            || mm2hiHybsilArrowDamageMax() != 4
            || mm2hiHybsilSleepHoursMin() != 1
            || mm2hiHybsilSleepHoursMax() != 4
            || mm2hiHybsilSleepSavePenalty() != 4
            || mm2hiHybsilSaveBonus() != 4
            || mm2hiHybsilWitchDoctorDruidPct() != 60
            || mm2hiHybsilWitchDoctorMuPct() != 40
            || mm2hiHybsilWitchDoctorLevelMax() != 7
            || !mm2hiHauntCannotBeTurned()
            || !mm2hiHauntStruckOnlyBySilverMagicOrFire()
            || !mm2hiHauntExorcismDestroysForever()
            || !mm2hiHauntBlockPrintsNoSizeOrMrLine()
            || !mm2hiHollyphantGlobeOfInvulnerability()
            || !mm2hiHollyphantTusksImmunity()
            || !mm2hiHangmanTreeLightningDoubleDamage()
            || !mm2hiHangmanTreeHallucinatoryPerfume()
            || !mm2hiHordlingTurnedAsMinorDemons()
            || !mm2hiHordlingUltravisual()
            || !mm2hiHordlingBringerOfDoomSummoning()
            || !mm2hiHybsilPlusFourSaves()
            || !mm2hiHybsilWitchDoctorLeadership()
            || !mm2hiLetterIBoxClosesOnIldriss()
        )
            ++bad;
        // THE HH-GRID: the 5-row HhStats stat grid (every armor class,
        // hit-dice, bonus, avgHp, attack, xp, xp/hp, lair, move and
        // magic-resistance cell of the five letter-H stat blocks, in print
        // order - the hangman tree, the haunt, the hollyphant, the hordling
        // and the hybsil)
        int CHhStats[5][10] = {
            {3,0,0,61,3,1600,8,0,0,1},
            {0,5,0,17,5,165,5,0,6,0},
            {-4,8,8,36,2,3750,14,0,9,60},
            {3,9,0,31,1,1400,12,0,6,0},
            {7,1,-1,2,1,22,1,30,15,0},
            };
        for (int b = 0;
             b < mm2hiHhStatRows();
             ++b) {
            int vals[10];
            vals[0] = mm2hiHhStatAC(b);
            vals[1] = mm2hiHhStatHd(b);
            vals[2] = mm2hiHhStatHdBonus(b);
            vals[3] = mm2hiHhStatAvgHp(b);
            vals[4] = mm2hiHhStatAttacks(b);
            vals[5] = mm2hiHhStatXp(b);
            vals[6] = mm2hiHhStatXpHp(b);
            vals[7] = mm2hiHhStatLairPct(b);
            vals[8] = mm2hiHhStatMove(b);
            vals[9] = mm2hiHhStatMr(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CHhStats[b][c])
                    ++bad;
            }
        }
        // the registry grows by exactly the def count and the two gap boxes
        // flip (the census walk)
    if (mm2hiRegistryAfter() - mm2hiRegistryBefore() != mm2hiDefCount()
            || mm2hiDefCount() != 5
            || mm2hiEntryCount() != 5
            || mm2hiHhStatRows() != 5
            || mm2hiGapClosed() != 14
            || mm2hiGapOpen() != 23
            || mm2hiPriorOwnedEntries() != 1
        )
            ++bad;
        // the pin-time entry census composition (5 stat-block headings, no
        // doctrine-only family heads, the letter-I span walks empty)
    if (mm2hiStatBlockHeadings() != 5
            || mm2hiDoctrineHeads() != 0
            || mm2hiLetterHHeadings() != 5
            || mm2hiLetterIHeadings() != 0
            || mm2hiIldrissOwningRound() != 805
        )
            ++bad;
        // the hangman tree composite stat reads (the flat printed 61 hp, the
        // trunk armor class 3, the per-year magic resistance 1, the effective
        // 0 move)
    if (mm2hiHhStatAC(0) != 3
            || mm2hiHhStatHd(0) != 0
            || mm2hiHhStatAvgHp(0) != 61
            || mm2hiHhStatMr(0) != 1
            || mm2hiHhStatMove(0) != 0
            || mm2hiHhStatAttacks(0) != 3
        )
            ++bad;
        // the haunt composite stat reads (the natural-state armor class 0,
        // the 5-dice read, the "as 5 HD monster" attack load, the absent
        // magic resistance line reading 0)
    if (mm2hiHhStatAC(1) != 0
            || mm2hiHhStatHd(1) != 5
            || mm2hiHhStatAvgHp(1) != 17
            || mm2hiHhStatAttacks(1) != 5
            || mm2hiHhStatXp(1) != 165
            || mm2hiHhStatXpHp(1) != 5
            || mm2hiHhStatMove(1) != 6
            || mm2hiHhStatMr(1) != 0
        )
            ++bad;
        // the hollyphant stat reads (the -4 armor class, the 8+8 dice, the
        // 60% magic resistance, the ground 9 move)
    if (mm2hiHhStatAC(2) != -4
            || mm2hiHhStatHd(2) != 8
            || mm2hiHhStatHdBonus(2) != 8
            || mm2hiHhStatAvgHp(2) != 36
            || mm2hiHhStatXp(2) != 3750
            || mm2hiHhStatXpHp(2) != 14
            || mm2hiHhStatMr(2) != 60
            || mm2hiHhStatMove(2) != 9
        )
            ++bad;
        // the hordling or-form reads (the best 9 hit dice, the first armor
        // class 3, the first 6 move, the first 0 magic resistance, the top
        // VII/1400 + 12/hp xp variant, the "By type" attack floor 1)
    if (mm2hiHhStatAC(3) != 3
            || mm2hiHhStatHd(3) != 9
            || mm2hiHhStatAvgHp(3) != 31
            || mm2hiHhStatAttacks(3) != 1
            || mm2hiHhStatXp(3) != 1400
            || mm2hiHhStatXpHp(3) != 12
            || mm2hiHhStatMr(3) != 0
            || mm2hiHhStatMove(3) != 6
        )
            ++bad;
        // the hybsil stat reads (the "1-1" dice with the minus 1 bonus, the
        // 30% lair, the 15 move)
    if (mm2hiHhStatAC(4) != 7
            || mm2hiHhStatHd(4) != 1
            || mm2hiHhStatHdBonus(4) != -1
            || mm2hiHhStatAvgHp(4) != 2
            || mm2hiHhStatXp(4) != 22
            || mm2hiHhStatXpHp(4) != 1
            || mm2hiHhStatLairPct(4) != 30
            || mm2hiHhStatMove(4) != 15
            || mm2hiHhStatMr(4) != 0
        )
            ++bad;
        // the full kill xp values (the base + xp-per-hp x avgHp formula,
        // every letter-H def)
    if (mm2hiHangmanTreeXpValue() != 2088
            || mm2hiHauntXpValue() != 250
            || mm2hiHollyphantXpValue() != 4254
            || mm2hiHordlingXpValue() != 1772
            || mm2hiHybsilXpValue() != 24
        )
            ++bad;
        // the hordling tier ladders stay whole (the 1d4 armor class, move,
        // hit dice and magic resistance tiers)
    if (mm2hiHordlingAcTier1() != 3
            || mm2hiHordlingAcTier2() != 2
            || mm2hiHordlingAcTier3() != 1
            || mm2hiHordlingAcTier4() != 0
            || mm2hiHordlingMoveTier1() != 6
            || mm2hiHordlingMoveTier4() != 15
            || mm2hiHordlingHdTier1() != 6
            || mm2hiHordlingHdBonusTier1() != 3
            || mm2hiHordlingHdTier4() != 9
            || mm2hiHordlingHdBonusTier4() != 0
            || mm2hiHordlingMrTier1() != 0
            || mm2hiHordlingMrTier4() != 30
            || mm2hiHordlingXpTier1() != 525
            || mm2hiHordlingXpHpTier1() != 8
            || mm2hiHordlingXpTier4() != 1400
            || mm2hiHordlingXpHpTier4() != 12
        )
            ++bad;
        // the haunt doctrine arithmetic (the doubling strangling ladder and
        // the dexterity cycle)
    if (mm2hiHauntStrangleSecond() != mm2hiHauntStrangleStart() * 2
            || mm2hiHauntStrangleThird() != mm2hiHauntStrangleSecond() * 2
            || mm2hiHauntDexRegainPerTurn() != 1
            || mm2hiHauntReformWeeks() != 1
            || mm2hiHauntAttackAsHd() != 5
            || mm2hiHauntFormCount() != 2
        )
            ++bad;
        // the hollyphant gate arithmetic (the gate percents sum and the
        // psionic discipline pair)
    if (mm2hiHollyphantGateHollyphantPct() != 70
            || mm2hiHollyphantGateDevaPct() != 30
            || mm2hiHollyphantGatePct() != 50
            || mm2hiHollyphantPsionicMinor() != 4
            || mm2hiHollyphantPsionicMajor() != 2
            || mm2hiHollyphantSpellLevel() != 16
            || mm2hiHollyphantFlyRate() != 42
        )
            ++bad;
        // the hangman tree ages ladder (the five print bands, the perfume
        // range, the per-year magic resistance)
    if (mm2hiHangmanTreeSproutAgeMax() != 10
            || mm2hiHangmanTreeSaplingAgeMin() != 11
            || mm2hiHangmanTreeSaplingAgeMax() != 25
            || mm2hiHangmanTreeMatureAgeMin() != 26
            || mm2hiHangmanTreeMatureAgeMax() != 75
            || mm2hiHangmanTreeOldAgeMin() != 76
            || mm2hiHangmanTreeOldAgeMax() != 150
            || mm2hiHangmanTreeAncientAgeMin() != 151
            || mm2hiHangmanTreePerfumeRangeMinFeet() != 30
            || mm2hiHangmanTreePerfumeRangeMaxFeet() != 80
            || mm2hiHangmanTreeMrPerYear() != 1
        )
            ++bad;
        // the hybsil arithmetic (the witch doctor percents sum to 100, the
        // sleep arrow ladder, the +4 saves)
    if (mm2hiHybsilWitchDoctorDruidPct() + mm2hiHybsilWitchDoctorMuPct() !=
        100
            || mm2hiHybsilSleepHoursMin() != 1
            || mm2hiHybsilSleepHoursMax() != 4
            || mm2hiHybsilSleepSavePenalty() != 4
            || mm2hiHybsilSaveBonus() != 4
            || mm2hiHybsilWitchDoctorLevelMax() != 7
            || mm2hiHybsilNoAppearingMult() != 10
            || mm2hiHybsilNoAppearingDie() != 6
        )
            ++bad;
        printf("R806 MM2 letters HI walk audit: bad %d\n", bad);
        if (bad) return 1;
    }
