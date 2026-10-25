    // ---- R448 WSG jumping pin audit ----
    // The jumping slice pins the any-character rule, the four-foot running
    // advantage with its 20-foot straight run, the half-height high jump with
    // the roll-to-absorb landing, the thin-barrier high jump plus Dexterity
    // Check with the 1d3 heap damage at five feet or higher and the
    // next-round stand-up, the per-jump die roll, Table 22 (the seven level
    // bands with the standing broad, running broad and high jump dice), and
    // the cumulative modifiers (moderate -1, heavy -2 and cannot high jump,
    // severe cannot jump at all, halfling -1 broad only, gnome or dwarf -2
    // broad and -1 high) with the 2-foot broad and 1-foot high floors
    // (rules/wsgjump.h, prefix wjp); census 372 -> 373.
    {
        using namespace rules;
        int bad = 0;
    if (wjpRunningAdvantageFt() != 4
            || wjpRunRequiredFt() != 20
            || wjpHighHorizDiv() != 2
            || wjpHeapDmgDie() != 3
            || wjpHeapMinFt() != 5
            || wjpStandFloorFt() != 2
            || wjpHighFloorFt() != 1
            || wjpEncModerateFt() != 1
            || wjpEncHeavyBroadFt() != 2
            || wjpHalflingBroadFt() != 1
            || wjpDwarfBroadFt() != 2
            || wjpDwarfHighFt() != 1
            || wjpBandCount() != 7
            || !wjpAnyCharacterCanJump()
            || !wjpRunNeedsStraightRun()
            || !wjpRollToHigherSurface()
            || !wjpThinBarrierDexCheck()
            || !wjpHeapNeedsNextRound()
            || !wjpDieRolledPerJump()
            || !wjpModifiersCumulative()
            || !wjpSevereCannotJump()
            || !wjpHeavyCannotHighJump()
        )
            ++bad;
        // the Table 22 grid: the seven level bands (1-6, 7-9, 10-12, 13-15,
        // 16-18, 19-22, 23+) x the three jumps (the standing broad 1d4+1 to
        // 1d6+6, the running broad 1d4+5 to 1d6+15, the high jump 1d3 to
        // 1d6+1), each cell split into the die and the plus feet
        int C22[7][6] = {
            {4,1,4,5,3,0},
            {4,2,4,6,4,0},
            {6,2,6,5,3,1},
            {6,3,6,6,4,1},
            {6,4,6,9,5,0},
            {6,5,6,12,5,1},
            {6,6,6,15,6,1},
            };
        for (int b = 0;
             b < wjpBandCount();
             ++b) {
            int vals[6];
            vals[0] = wjpStandDie(b);
            vals[1] = wjpStandPlus(b);
            vals[2] = wjpRunDie(b);
            vals[3] = wjpRunPlus(b);
            vals[4] = wjpHighDie(b);
            vals[5] = wjpHighPlus(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != C22[b][c])
                    ++bad;
            }
        }
        // the 1-6 band exactly as printed: 1d4+1 standing, 1d4+5 running, 1d3
        // high
    if (wjpStandDie(0) != 4
            || wjpStandPlus(0) != 1
            || wjpRunDie(0) != 4
            || wjpRunPlus(0) != 5
            || wjpHighDie(0) != 3
            || wjpHighPlus(0) != 0
        )
            ++bad;
        // the 23+ band: 1d6+6 standing, 1d6+15 running, 1d6+1 high
    if (wjpStandPlus(6) != 6
            || wjpRunPlus(6) != 15
            || wjpHighDie(6) != 6
            || wjpHighPlus(6) != 1
        )
            ++bad;
        // the printed prose numbers: the four-foot running advantage, the
        // 20-foot straight run, the 1d3 heap damage at five feet or higher
    if (wjpRunningAdvantageFt() != 4
            || wjpRunRequiredFt() != 20
            || wjpHeapDmgDie() != 3
            || wjpHeapMinFt() != 5
        )
            ++bad;
        // the running ladder caps 9/12/15 - the three biggest running pluses,
        // each in its own band
    if (wjpRunPlus(4) != 9
            || wjpRunPlus(5) != 12
            || wjpRunPlus(6) != 15
        )
            ++bad;
        // the modifier floors: 2 feet broad and 1 foot high - the broad floor
        // is twice the high floor
    if (wjpStandFloorFt() != 2
            || wjpHighFloorFt() != 1
            || wjpStandFloorFt() != 2 * wjpHighFloorFt()
        )
            ++bad;
        // the running advantage inside the grid: the first band gains 4 over
        // standing (the printed average), the last band gains 9
    if (wjpRunPlus(0) - wjpStandPlus(0) != 4
            || wjpRunPlus(6) - wjpStandPlus(6) != 9
        )
            ++bad;
        // running strictly exceeds standing in every one of the seven bands
    if (wjpRunPlus(0) <= wjpStandPlus(0)
            || wjpRunPlus(1) <= wjpStandPlus(1)
            || wjpRunPlus(2) <= wjpStandPlus(2)
            || wjpRunPlus(3) <= wjpStandPlus(3)
            || wjpRunPlus(4) <= wjpStandPlus(4)
            || wjpRunPlus(5) <= wjpStandPlus(5)
            || wjpRunPlus(6) <= wjpStandPlus(6)
        )
            ++bad;
        // the die ladders: the standing die steps 1d4 to 1d6, the high die
        // climbs 1d3, 1d5, 1d6
    if (wjpStandDie(0) != 4
            || wjpStandDie(2) != 6
            || wjpHighDie(0) != 3
            || wjpHighDie(4) != 5
            || wjpHighDie(6) != 6
        )
            ++bad;
        // the printed modifier feet: -1 moderate, -2 heavy, -1 halfling
        // broad, -2/-1 gnome or dwarf
    if (wjpEncModerateFt() != 1
            || wjpEncHeavyBroadFt() != 2
            || wjpHalflingBroadFt() != 1
            || wjpDwarfBroadFt() != 2
            || wjpDwarfHighFt() != 1
        )
            ++bad;
        printf("R448 WSG jumping pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
