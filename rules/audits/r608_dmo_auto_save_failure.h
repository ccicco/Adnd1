    // ---- R608 DMO auto-save-failure audit ----
    // DMO Chapter 7 round one of five (printed pp. 142-144): the saving-throw
    // doctrine - the group improvement limits (19, 21, 17, 21), the automatic
    // failure on 3 or less with the deity ladders (2, 1, never), the
    // adjusted-roll reading, the Wulf worked example (5 - 3 = 2); the Table
    // 36 saves-by-caster-level grid with its four defender-minus-caster
    // row-band chains; the Table 37 device casting levels; the Table 38
    // caster-level penalty ladder with its either-or rule; the Table 39 THACO
    // limits with the automatic miss on 1.
    {
        using namespace rules;
        int bad = 0;
    if (dewPriestSaveLimitLevel() != 19
            || dewRogueSaveLimitLevel() != 21
            || dewWarriorSaveLimitLevel() != 17
            || dewWizardSaveLimitLevel() != 21
            || dewPhbSaveTable() != 60
            || dewAutoFailMortal() != 3
            || dewAutoFailLesserDeity() != 2
            || dewAutoFailIntermediateDeity() != 1
            || dewAutoFailGreaterDeity() != 0
            || dewT36RowCount() != 28
            || dewRogueRowBase() != 7
            || dewWarriorRowBase() != 13
            || dewWizardRowBase() != 23
            || dewT38BandCount() != 7
            || dewWulfParSaveNumber() != 2
            || dewWulfPoisonPenalty() != -3
            || dewWulfSuccessRoll() != 5
            || dewRodLevel() != 12
            || dewStaffLevel() != 8
            || dewWandLevel() != 6
            || dewOtherItemLevel() != 12
            || dewArtifactLevel() != 20
            || dewThacoLimitPriest() != 8
            || dewThacoLimitRogue() != 11
            || dewThacoLimitWarrior() != 1
            || dewThacoLimitWizard() != 14
            || dewAutoMissRoll() != 1
            || !dewAutoFailAlwaysPossible()
            || !dewAutoFailIgnoresBonuses()
            || !dewSaveNumberIsAdjustedRoll()
            || !dewGreaterDeityNeverFails()
            || !dewT36ForDuelsOnly()
            || !dewT36NotForNonSpells()
            || !dewDeviceClosestColumn()
            || !dewWielderLevelIrrelevant()
            || !dewDmConcealsCasterLevel()
            || !dewT38ExcludesT36()
            || !dewFireballUsesSpellColumn()
            || !dewWandParalyzationUsesParColumn()
            || !dewThacoAdvancementLimited()
            || !dewWarriorsImproveThacoMost()
            || !dewMonstersNoThacoLimit()
        )
            ++bad;
        // the dewT36Grid grid
        int CT36[28][3] = {
            {10,13,15},
            {9,12,14},
            {7,10,12},
            {6,9,11},
            {5,8,10},
            {4,7,9},
            {2,5,7},
            {13,12,15},
            {12,11,13},
            {11,10,11},
            {10,9,9},
            {9,8,7},
            {8,7,5},
            {16,17,19},
            {14,15,17},
            {13,14,16},
            {11,12,14},
            {10,11,13},
            {8,9,11},
            {7,8,10},
            {5,6,8},
            {4,5,7},
            {3,4,6},
            {14,13,12},
            {13,11,10},
            {11,9,8},
            {10,7,6},
            {8,5,4},
            };
        for (int b = 0;
             b < dewT36RowCount();
             ++b) {
            int vals[3];
            vals[0] = dewT36Par(b);
            vals[1] = dewT36Petr(b);
            vals[2] = dewT36Spell(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT36[b][c])
                    ++bad;
            }
        }
        // the dewT38Grid grid
        int CT38[7][1] = {
            {0},
            {-1},
            {-2},
            {-3},
            {-4},
            {-5},
            {-6},
            };
        for (int b = 0;
             b < dewT38BandCount();
             ++b) {
            int vals[1];
            vals[0] = dewT38Penalty(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CT38[b][c])
                    ++bad;
            }
        }
        // the dewPriestRow band-for boundaries
    if (dewPriestRow(-8) != 0
            || dewPriestRow(-7) != 0
            || dewPriestRow(-4) != 1
            || dewPriestRow(-6) != 1
            || dewPriestRow(-1) != 2
            || dewPriestRow(-3) != 2
            || dewPriestRow(0) != 3
            || dewPriestRow(0) != 3
            || dewPriestRow(3) != 4
            || dewPriestRow(1) != 4
            || dewPriestRow(6) != 5
            || dewPriestRow(4) != 5
            || dewPriestRow(7) != 6
        )
            ++bad;
        // the dewRogueRow band-for boundaries
    if (dewRogueRow(-10) != 0
            || dewRogueRow(-9) != 0
            || dewRogueRow(-5) != 1
            || dewRogueRow(-8) != 1
            || dewRogueRow(-1) != 2
            || dewRogueRow(-4) != 2
            || dewRogueRow(0) != 3
            || dewRogueRow(0) != 3
            || dewRogueRow(4) != 4
            || dewRogueRow(1) != 4
            || dewRogueRow(5) != 5
        )
            ++bad;
        // the dewWarriorRow band-for boundaries
    if (dewWarriorRow(-8) != 0
            || dewWarriorRow(-7) != 0
            || dewWarriorRow(-5) != 1
            || dewWarriorRow(-6) != 1
            || dewWarriorRow(-3) != 2
            || dewWarriorRow(-4) != 2
            || dewWarriorRow(-1) != 3
            || dewWarriorRow(-2) != 3
            || dewWarriorRow(0) != 4
            || dewWarriorRow(0) != 4
            || dewWarriorRow(2) != 5
            || dewWarriorRow(1) != 5
            || dewWarriorRow(4) != 6
            || dewWarriorRow(3) != 6
            || dewWarriorRow(6) != 7
            || dewWarriorRow(5) != 7
            || dewWarriorRow(8) != 8
            || dewWarriorRow(7) != 8
            || dewWarriorRow(9) != 9
        )
            ++bad;
        // the dewWizardRow band-for boundaries
    if (dewWizardRow(-7) != 0
            || dewWizardRow(-6) != 0
            || dewWizardRow(-1) != 1
            || dewWizardRow(-5) != 1
            || dewWizardRow(0) != 2
            || dewWizardRow(0) != 2
            || dewWizardRow(5) != 3
            || dewWizardRow(1) != 3
            || dewWizardRow(6) != 4
        )
            ++bad;
        // the dewT38Band band-for boundaries
    if (dewT38Band(11) != 0
            || dewT38Band(12) != 0
            || dewT38Band(15) != 1
            || dewT38Band(13) != 1
            || dewT38Band(18) != 2
            || dewT38Band(16) != 2
            || dewT38Band(21) != 3
            || dewT38Band(19) != 3
            || dewT38Band(24) != 4
            || dewT38Band(22) != 4
            || dewT38Band(27) != 5
            || dewT38Band(25) != 5
            || dewT38Band(28) != 6
        )
            ++bad;
        // the dewPriestSaveLimitLevel pin
    if (dewPriestSaveLimitLevel() != 19
        )
            ++bad;
        // the dewRogueSaveLimitLevel pin
    if (dewRogueSaveLimitLevel() != 21
        )
            ++bad;
        // the dewWarriorSaveLimitLevel pin
    if (dewWarriorSaveLimitLevel() != 17
        )
            ++bad;
        // the dewWizardSaveLimitLevel pin
    if (dewWizardSaveLimitLevel() != 21
        )
            ++bad;
        // the dewPhbSaveTable pin
    if (dewPhbSaveTable() != 60
        )
            ++bad;
        // the dewAutoFailMortal pin
    if (dewAutoFailMortal() != 3
        )
            ++bad;
        // the dewAutoFailLesserDeity pin
    if (dewAutoFailLesserDeity() != 2
        )
            ++bad;
        // the dewAutoFailIntermediateDeity pin
    if (dewAutoFailIntermediateDeity() != 1
        )
            ++bad;
        // the dewAutoFailGreaterDeity pin
    if (dewAutoFailGreaterDeity() != 0
        )
            ++bad;
        // the dewT36RowCount pin
    if (dewT36RowCount() != 28
        )
            ++bad;
        // the dewRogueRowBase pin
    if (dewRogueRowBase() != 7
        )
            ++bad;
        // the dewWarriorRowBase pin
    if (dewWarriorRowBase() != 13
        )
            ++bad;
        // the dewWizardRowBase pin
    if (dewWizardRowBase() != 23
        )
            ++bad;
        // the dewT38BandCount pin
    if (dewT38BandCount() != 7
        )
            ++bad;
        // the dewWulfParSaveNumber pin
    if (dewWulfParSaveNumber() != 2
        )
            ++bad;
        // the dewWulfPoisonPenalty pin
    if (dewWulfPoisonPenalty() != -3
        )
            ++bad;
        // the dewWulfSuccessRoll pin
    if (dewWulfSuccessRoll() != 5
        )
            ++bad;
        // the dewRodLevel pin
    if (dewRodLevel() != 12
        )
            ++bad;
        // the dewStaffLevel pin
    if (dewStaffLevel() != 8
        )
            ++bad;
        // the dewWandLevel pin
    if (dewWandLevel() != 6
        )
            ++bad;
        // the dewOtherItemLevel pin
    if (dewOtherItemLevel() != 12
        )
            ++bad;
        // the dewArtifactLevel pin
    if (dewArtifactLevel() != 20
        )
            ++bad;
        // the dewThacoLimitPriest pin
    if (dewThacoLimitPriest() != 8
        )
            ++bad;
        // the dewThacoLimitRogue pin
    if (dewThacoLimitRogue() != 11
        )
            ++bad;
        // the dewThacoLimitWarrior pin
    if (dewThacoLimitWarrior() != 1
        )
            ++bad;
        // the dewThacoLimitWizard pin
    if (dewThacoLimitWizard() != 14
        )
            ++bad;
        // the dewAutoMissRoll pin
    if (dewAutoMissRoll() != 1
        )
            ++bad;
        // the dewAutoFailAlwaysPossible pin
    if (dewAutoFailAlwaysPossible() != 1
        )
            ++bad;
        // the dewAutoFailIgnoresBonuses pin
    if (dewAutoFailIgnoresBonuses() != 1
        )
            ++bad;
        // the dewSaveNumberIsAdjustedRoll pin
    if (dewSaveNumberIsAdjustedRoll() != 1
        )
            ++bad;
        // the dewGreaterDeityNeverFails pin
    if (dewGreaterDeityNeverFails() != 1
        )
            ++bad;
        // the dewT36ForDuelsOnly pin
    if (dewT36ForDuelsOnly() != 1
        )
            ++bad;
        // the dewT36NotForNonSpells pin
    if (dewT36NotForNonSpells() != 1
        )
            ++bad;
        // the dewDeviceClosestColumn pin
    if (dewDeviceClosestColumn() != 1
        )
            ++bad;
        // the dewWielderLevelIrrelevant pin
    if (dewWielderLevelIrrelevant() != 1
        )
            ++bad;
        // the dewDmConcealsCasterLevel pin
    if (dewDmConcealsCasterLevel() != 1
        )
            ++bad;
        // the dewT38ExcludesT36 pin
    if (dewT38ExcludesT36() != 1
        )
            ++bad;
        // the dewFireballUsesSpellColumn pin
    if (dewFireballUsesSpellColumn() != 1
        )
            ++bad;
        // the dewWandParalyzationUsesParColumn pin
    if (dewWandParalyzationUsesParColumn() != 1
        )
            ++bad;
        // the dewThacoAdvancementLimited pin
    if (dewThacoAdvancementLimited() != 1
        )
            ++bad;
        // the dewWarriorsImproveThacoMost pin
    if (dewWarriorsImproveThacoMost() != 1
        )
            ++bad;
        // the dewMonstersNoThacoLimit pin
    if (dewMonstersNoThacoLimit() != 1
        )
            ++bad;
        // the Wulf arithmetic: 5 - 3 = 2 (printed p. 143)
    if (dewWulfSuccessRoll() + dewWulfPoisonPenalty() !=
        dewWulfParSaveNumber()
        )
            ++bad;
        // the Wulf success roll beats the mortal auto-fail 3 (printed p. 143)
    if (dewWulfSuccessRoll() <= dewAutoFailMortal()
        )
            ++bad;
        // the mortal auto-fail is 3 or less on 1d20 (printed p. 142)
    if (dewAutoFailMortal() < 3
        )
            ++bad;
        // the Wulf save number of 2 falls in the 3-or-less adjusted-roll
        // class (printed p. 143)
    if (dewWulfParSaveNumber() > 3
        )
            ++bad;
        // the footnote-1 worked example: a -1 difference lands the priest on
        // row 2, spell column 12 (printed p. 143)
    if (dewT36Spell(dewPriestRow(-1)) != 12
        )
            ++bad;
        // the priest band head: a -9 difference reads the -7-or-more row,
        // paralyzation 10 (printed p. 143)
    if (dewT36Par(dewPriestRow(-9)) != 10
        )
            ++bad;
        // the rogue band head: a -12 difference reads the -9-or-more row,
        // paralyzation 13 (printed p. 143)
    if (dewT36Par(dewRogueRow(-12) + dewRogueRowBase()) != 13
        )
            ++bad;
        // the warrior band head: a -8 difference reads the -7-or-more row,
        // paralyzation 16 (printed p. 143)
    if (dewT36Par(dewWarriorRow(-8) + dewWarriorRowBase()) != 16
        )
            ++bad;
        // the wizard band head: a -10 difference reads the -6-or-more row,
        // paralyzation 14 (printed p. 143)
    if (dewT36Par(dewWizardRow(-10) + dewWizardRowBase()) != 14
        )
            ++bad;
        // the priest band tail: a +9 difference reads the +7-or-more row,
        // spell 7 (printed p. 143)
    if (dewT36Spell(dewPriestRow(9)) != 7
        )
            ++bad;
        // the rogue band tail: a +6 difference reads the +5-or-more row,
        // spell 5 (printed p. 143)
    if (dewT36Spell(dewRogueRow(6) + dewRogueRowBase()) != 5
        )
            ++bad;
        // the warrior band tail: a +11 difference reads the +9-or-more row,
        // spell 6 (printed p. 143)
    if (dewT36Spell(dewWarriorRow(11) + dewWarriorRowBase()) != 6
        )
            ++bad;
        // the wizard band tail: a +8 difference reads the +6-or-more row,
        // spell 4 (printed p. 143)
    if (dewT36Spell(dewWizardRow(8) + dewWizardRowBase()) != 4
        )
            ++bad;
        // the deity ladder descends: lesser 2 fails below the mortal 3
        // (printed p. 142)
    if (dewAutoFailLesserDeity() > dewAutoFailMortal()
        )
            ++bad;
        // the deity ladder descends: intermediate 1 below lesser 2 (printed
        // p. 142)
    if (dewAutoFailIntermediateDeity() > dewAutoFailLesserDeity()
        )
            ++bad;
        // the deity ladder ends: greater 0 below intermediate 1 (printed p.
        // 142)
    if (dewAutoFailGreaterDeity() > dewAutoFailIntermediateDeity()
        )
            ++bad;
        // the Table 38 band edges: 12 reads 0, 16 reads -2, 30 reads -6
        // (printed p. 144)
    if (dewT38Penalty(dewT38Band(12)) != 0
            || dewT38Penalty(dewT38Band(16)) != -2
            || dewT38Penalty(dewT38Band(30)) != -6
        )
            ++bad;
        // the Table 38 in-band read: 13 and 15 both read -1 (printed p. 144)
    if (dewT38Penalty(dewT38Band(13)) != -1
            || dewT38Penalty(dewT38Band(15)) != -1
        )
            ++bad;
        // the Table 38 tail: beyond 30 holds -6 (printed p. 144)
    if (dewT38Penalty(dewT38Band(31)) != -6
        )
            ++bad;
        // the Table 37 ladder: the artifact 20 outruns the rod 12 (printed p.
        // 144)
    if (dewArtifactLevel() <= dewRodLevel()
        )
            ++bad;
        // the Table 37 ladder: the wand 6 is the lowest device level (printed
        // p. 144)
    if (dewWandLevel() >= dewStaffLevel()
        )
            ++bad;
        // the Table 39 order: the warrior limit 1 beats the priest 8 (printed
        // p. 144)
    if (dewThacoLimitWarrior() >= dewThacoLimitPriest()
        )
            ++bad;
        // the Table 39 order: the priest limit 8 is better than the rogue 11
        // (printed p. 144)
    if (dewThacoLimitPriest() >= dewThacoLimitRogue()
        )
            ++bad;
        // the Table 39 order: the rogue limit 11 is better than the wizard 14
        // (printed p. 144)
    if (dewThacoLimitRogue() >= dewThacoLimitWizard()
        )
            ++bad;
        printf("R608 DMO auto-save-failure audit: bad %d\n", bad);
        if (bad) return 1;
    }
