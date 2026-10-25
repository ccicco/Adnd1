    // ---- R625 OA sohei audit ----
    // OA round twelve (capture pp. 45-47): the sohei - the minima, the ki
    // powers, the command doctrine, and the advancement and spell grids
    {
        using namespace rules;
        int bad = 0;
    if (dglSoheiMinStr() != 13
            || dglSoheiMinWis() != 10
            || dglSoheiMinCon() != 10
            || dglSoheiBonusStat() != 15
            || dglSoheiBonusPct() != 10
            || dglSoheiHitDie() != 10
            || dglSoheiSlots() != 4
            || dglSoheiWeaponChoiceBonus() != 1
            || dglSoheiKiLevel() != 3
            || dglSoheiKiDurationTurns() != 1
            || dglSoheiKiPerDay() != 1
            || dglSoheiKiExtraAttacks() != 1
            || dglSoheiKiAcBonus() != 1
            || dglSoheiKiMoveBonus() != 3
            || dglSoheiKiRollBonus() != 1
            || dglSoheiFanaticLevel() != 5
            || dglSoheiFanaticDeathHp() != -10
            || dglSoheiFanaticRollBonus() != 2
            || dglSoheiCommandLevel() != 6
            || dglSoheiCommandMin() != 10
            || dglSoheiCommandMax() != 30
            || dglSoheiCommandStep() != 10
            || dglSoheiCommissionLevel() != 9
            || dglSoheiOffCauseXpDiv() != 2
            || dglT29RowCount() != 12
            || dglT29XpBeyond() != 200000
            || dglT29HpBeyond() != 1
            || dglT30RowCount() != 25
            || dglT30SpellLevels() != 4
            || dglT30FirstSpellLevel() != 6
            || dglT30MaxCastable() != 7
            || !dglSoheiLawfulOnly()
            || !dglSoheiDualPrime()
            || !dglSoheiClericTables()
            || !dglSoheiAnyArmor()
            || !dglSoheiCastShukenjaSpells()
            || !dglSoheiMilitant()
            || !dglSoheiWeaponChoiceProficiency()
            || !dglSoheiKiMissileDeflection()
            || !dglSoheiFanaticFinalAct()
            || !dglSoheiCommandReplaceable()
            || !dglSoheiCommandLostIfSlain()
            || !dglSoheiCommissionCommander()
            || !dglSoheiFishAllowed()
            || !dglSoheiAnyCaste()
            || !dglSoheiHonorImportant()
        )
            ++bad;
        // the Table 29 grid: the xp bounds and the accumulated dice plus
        // bonus (capture p. 45)
        int CT29[12][3] = {
            {2000,1,0},
            {4000,2,0},
            {7000,3,0},
            {13000,4,0},
            {24000,5,0},
            {48000,6,0},
            {85000,7,0},
            {150000,8,0},
            {350000,9,0},
            {550000,9,1},
            {750000,9,2},
            {950000,9,3},
            };
        int nT29[3] = {0,0,0};
        int eT29[3] = {0,0,0};
        for (int b = 0;
             b < dglT29RowCount();
             ++b) {
            int vals[3];
            vals[0] = dglT29XpMax(b);
            vals[1] = dglT29Dice(b);
            vals[2] = dglT29HpBonus(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT29[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT29[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nT29[c] != eT29[c])
                ++bad;
        // the Table 30 grid: the four spell-level columns, levels 1-29
        // (capture p. 46)
        int CT30[25][4] = {
            {0,0,0,0},
            {1,0,0,0},
            {1,1,0,0},
            {2,1,0,0},
            {2,2,0,0},
            {2,2,1,0},
            {3,2,1,0},
            {3,2,2,0},
            {3,3,2,0},
            {3,3,3,0},
            {3,3,3,1},
            {3,3,3,2},
            {4,3,3,2},
            {4,4,3,2},
            {4,4,4,3},
            {5,4,4,3},
            {5,5,4,3},
            {5,5,4,4},
            {5,5,5,4},
            {6,5,5,4},
            {6,6,5,4},
            {6,6,5,5},
            {6,6,6,5},
            {6,6,6,6},
            {7,7,6,6},
            };
        int nT30[4] = {0,0,0,0};
        int eT30[4] = {0,0,0,0};
        for (int b = 0;
             b < dglT30RowCount();
             ++b) {
            int vals[4];
            vals[0] = dglT30S1(b);
            vals[1] = dglT30S2(b);
            vals[2] = dglT30S3(b);
            vals[3] = dglT30S4(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CT30[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT30[c];
            }
        }
        for (int c = 0; c < 4; ++c)
            if (nT30[c] != eT30[c])
                ++bad;
        // the dglSoheiMinStr pin
    if (dglSoheiMinStr() != 13
        )
            ++bad;
        // the dglSoheiMinWis pin
    if (dglSoheiMinWis() != 10
        )
            ++bad;
        // the dglSoheiMinCon pin
    if (dglSoheiMinCon() != 10
        )
            ++bad;
        // the dglSoheiBonusStat pin
    if (dglSoheiBonusStat() != 15
        )
            ++bad;
        // the dglSoheiBonusPct pin
    if (dglSoheiBonusPct() != 10
        )
            ++bad;
        // the dglSoheiHitDie pin
    if (dglSoheiHitDie() != 10
        )
            ++bad;
        // the dglSoheiSlots pin
    if (dglSoheiSlots() != 4
        )
            ++bad;
        // the dglSoheiWeaponChoiceBonus pin
    if (dglSoheiWeaponChoiceBonus() != 1
        )
            ++bad;
        // the dglSoheiKiLevel pin
    if (dglSoheiKiLevel() != 3
        )
            ++bad;
        // the dglSoheiKiDurationTurns pin
    if (dglSoheiKiDurationTurns() != 1
        )
            ++bad;
        // the dglSoheiKiPerDay pin
    if (dglSoheiKiPerDay() != 1
        )
            ++bad;
        // the dglSoheiKiExtraAttacks pin
    if (dglSoheiKiExtraAttacks() != 1
        )
            ++bad;
        // the dglSoheiKiAcBonus pin
    if (dglSoheiKiAcBonus() != 1
        )
            ++bad;
        // the dglSoheiKiMoveBonus pin
    if (dglSoheiKiMoveBonus() != 3
        )
            ++bad;
        // the dglSoheiKiRollBonus pin
    if (dglSoheiKiRollBonus() != 1
        )
            ++bad;
        // the dglSoheiFanaticLevel pin
    if (dglSoheiFanaticLevel() != 5
        )
            ++bad;
        // the dglSoheiFanaticDeathHp pin
    if (dglSoheiFanaticDeathHp() != -10
        )
            ++bad;
        // the dglSoheiFanaticRollBonus pin
    if (dglSoheiFanaticRollBonus() != 2
        )
            ++bad;
        // the dglSoheiCommandLevel pin
    if (dglSoheiCommandLevel() != 6
        )
            ++bad;
        // the dglSoheiCommandMin pin
    if (dglSoheiCommandMin() != 10
        )
            ++bad;
        // the dglSoheiCommandMax pin
    if (dglSoheiCommandMax() != 30
        )
            ++bad;
        // the dglSoheiCommandStep pin
    if (dglSoheiCommandStep() != 10
        )
            ++bad;
        // the dglSoheiCommissionLevel pin
    if (dglSoheiCommissionLevel() != 9
        )
            ++bad;
        // the dglSoheiOffCauseXpDiv pin
    if (dglSoheiOffCauseXpDiv() != 2
        )
            ++bad;
        // the dglT29RowCount pin
    if (dglT29RowCount() != 12
        )
            ++bad;
        // the dglT29XpBeyond pin
    if (dglT29XpBeyond() != 200000
        )
            ++bad;
        // the dglT29HpBeyond pin
    if (dglT29HpBeyond() != 1
        )
            ++bad;
        // the dglT30RowCount pin
    if (dglT30RowCount() != 25
        )
            ++bad;
        // the dglT30SpellLevels pin
    if (dglT30SpellLevels() != 4
        )
            ++bad;
        // the dglT30FirstSpellLevel pin
    if (dglT30FirstSpellLevel() != 6
        )
            ++bad;
        // the dglT30MaxCastable pin
    if (dglT30MaxCastable() != 7
        )
            ++bad;
        // the dglSoheiLawfulOnly pin
    if (dglSoheiLawfulOnly() != 1
        )
            ++bad;
        // the dglSoheiDualPrime pin
    if (dglSoheiDualPrime() != 1
        )
            ++bad;
        // the dglSoheiClericTables pin
    if (dglSoheiClericTables() != 1
        )
            ++bad;
        // the dglSoheiAnyArmor pin
    if (dglSoheiAnyArmor() != 1
        )
            ++bad;
        // the dglSoheiCastShukenjaSpells pin
    if (dglSoheiCastShukenjaSpells() != 1
        )
            ++bad;
        // the dglSoheiMilitant pin
    if (dglSoheiMilitant() != 1
        )
            ++bad;
        // the dglSoheiWeaponChoiceProficiency pin
    if (dglSoheiWeaponChoiceProficiency() != 1
        )
            ++bad;
        // the dglSoheiKiMissileDeflection pin
    if (dglSoheiKiMissileDeflection() != 1
        )
            ++bad;
        // the dglSoheiFanaticFinalAct pin
    if (dglSoheiFanaticFinalAct() != 1
        )
            ++bad;
        // the dglSoheiCommandReplaceable pin
    if (dglSoheiCommandReplaceable() != 1
        )
            ++bad;
        // the dglSoheiCommandLostIfSlain pin
    if (dglSoheiCommandLostIfSlain() != 1
        )
            ++bad;
        // the dglSoheiCommissionCommander pin
    if (dglSoheiCommissionCommander() != 1
        )
            ++bad;
        // the dglSoheiFishAllowed pin
    if (dglSoheiFishAllowed() != 1
        )
            ++bad;
        // the dglSoheiAnyCaste pin
    if (dglSoheiAnyCaste() != 1
        )
            ++bad;
        // the dglSoheiHonorImportant pin
    if (dglSoheiHonorImportant() != 1
        )
            ++bad;
        // the T29 first row - 2,000 xp, one die (capture p. 45)
    if (dglT29XpMax(0) != 2000
            || dglT29Dice(0) != 1
            || dglT29HpBonus(0) != 0
        )
            ++bad;
        // the T29 row-4 cell settled - 13,000 xp is level 4 with four dice,
        // the capture printed 3 (capture p. 45)
    if (dglT29XpMax(3) != 13000
            || dglT29Dice(3) != 4
            || dglT29Dice(4) != 5
        )
            ++bad;
        // the T29 capstone - 950,000 xp, nine dice plus three (capture p. 45)
    if (dglT29XpMax(11) != 950000
            || dglT29Dice(11) != 9
            || dglT29HpBonus(11) != 3
        )
            ++bad;
        // the T29 9-plus-N cells open on the 10th-level row (capture p. 45)
    if (dglT29Dice(9) != 9
            || dglT29HpBonus(9) != 1
        )
            ++bad;
        // the T30 row 0 - the levels 1-5 blank (capture p. 46)
    if (dglT30S1(0) != 0
            || dglT30S4(0) != 0
        )
            ++bad;
        // the T30 openings - the 1st at 6th, the 2nd at 7th, the 3rd at 10th,
        // the 4th at 15th (capture p. 46)
    if (dglT30S1(1) != 1
            || dglT30S2(2) != 1
            || dglT30S3(5) != 1
            || dglT30S4(10) != 1
        )
            ++bad;
        // the T30 capstone - the 29th-level row (capture p. 46)
    if (dglT30S1(24) != 7
            || dglT30S2(24) != 7
            || dglT30S3(24) != 6
            || dglT30S4(24) != 6
        )
            ++bad;
        // the berserk ki riders - the extra attack, AC, movement and roll
        // bonuses (capture p. 47)
    if (dglSoheiKiExtraAttacks() != 1
            || dglSoheiKiAcBonus() != 1
            || dglSoheiKiMoveBonus() != 3
            || dglSoheiKiRollBonus() != 1
        )
            ++bad;
        // the fanaticism bounds - the -10 death floor with the +2 reserves
        // (capture p. 47)
    if (dglSoheiFanaticDeathHp() != -10
            || dglSoheiFanaticRollBonus() != 2
        )
            ++bad;
        // the command ladder - 10-30 sohei plus 10 per level above 6th
        // (capture p. 47)
    if (dglSoheiCommandMin() != 10
            || dglSoheiCommandMax() != 30
            || dglSoheiCommandStep() != 10
        )
            ++bad;
        printf("R625 OA sohei audit: bad %d\n", bad);
        if (bad) return 1;
    }
