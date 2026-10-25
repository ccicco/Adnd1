    // ---- R525 DSG equipment costs audit ----
    // The DSG equipment costs pins the Table 35 grid (the twenty general rows
    // from the air bladder 15 gp and 20 gp through the whistle 1 sp and 1 pc,
    // plus the transportation rows - boat 500/600, canoes 100/800 and
    // 300/1,600, kayak 250/500 gp), the fourteen proficiency costs and
    // minimum spaces (the gem cutter 2,225 gp and 15 x 15, the smelter 2,000
    // gp and 50 x 50, the weaponsmith 1,500 gp and 40 x 30), the
    // space-required rule making an undersized proficiency only partially
    // effective, and the raw-materials exclusion at 11-20% (1d10 + 10) of the
    // finished work value.
    {
        using namespace rules;
        int bad = 0;
    if (dntaT35RowCount() != 24
            || dntaProfRowCount() != 14
            || dntaRawMatDice() != 1
            || dntaRawMatSides() != 10
            || dntaRawMatAddPct() != 10
            || !dntaUsableAnyCampaign()
            || !dntaListedWithCostAndEncumbrance()
            || !dntaUsesTiedToRules()
            || !dntaProfSpaceRequired()
            || !dntaProfCostsExcludeRawMaterials()
            || !dntaReedWhistleWeightPrintedPc()
            || !dntaAnimalTrainerSpaceVaries()
            || !dntaCarpenterMinerStonemasonVary()
        )
            ++bad;
        // the Table 35 equipment cost and weight grid, the twenty general
        // rows plus the four transportation rows
        int C35[24][2] = {
            {1500,20},
            {50,80},
            {20,40},
            {4000,200},
            {50,50},
            {10000,20},
            {2000,20},
            {4000,50},
            {300,75},
            {500,50},
            {7500,75},
            {5000,50},
            {5,20},
            {100,20},
            {2000,200},
            {20,20},
            {2500,60},
            {10,1},
            {1000,180},
            {10,1},
            {50000,600},
            {10000,800},
            {30000,1600},
            {25000,500},
            };
        for (int b = 0;
             b < dntaT35RowCount();
             ++b) {
            int vals[2];
            vals[0] = dntaT35CostCp(b);
            vals[1] = dntaT35WtGp(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != C35[b][c])
                    ++bad;
            }
        }
        // the proficiency equipment grid, the fourteen initial costs and
        // minimum spaces
        int C35P[14][2] = {
            {100,-99},
            {1250,400},
            {1000,900},
            {1000,6000},
            {250,400},
            {400,-99},
            {2225,225},
            {300,225},
            {750,-99},
            {600,600},
            {2000,2500},
            {250,-99},
            {1500,1200},
            {500,900},
            };
        for (int b = 0;
             b < dntaProfRowCount();
             ++b) {
            int vals[2];
            vals[0] = dntaProfCostGp(b);
            vals[1] = dntaProfAreaSqft(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != C35P[b][c])
                    ++bad;
            }
        }
        // the row counts and the raw-material roll: twenty-four equipment
        // rows, fourteen proficiencies, and the 1d10 + 10 raw-material
        // percent.
    if (dntaT35RowCount() != 24
            || dntaProfRowCount() != 14
            || dntaRawMatDice() != 1
            || dntaRawMatSides() != 10
            || dntaRawMatAddPct() != 10
        )
            ++bad;
        // the proficiency cost anchors: the gem cutter 2,225 gp, the armorer
        // 1,250 gp, the smelter 2,000 gp.
    if (dntaProfCostGp(6) != 2225
            || dntaProfCostGp(1) != 1250
            || dntaProfCostGp(10) != 2000
        )
            ++bad;
        // the frame prose: the any-campaign rule, the space-required rule,
        // the raw-materials exclusion with the 11-20% cost, the 1-pc pin, and
        // the Varies rows.
    if (dntaUsableAnyCampaign() != 1
            || dntaProfSpaceRequired() != 1
            || dntaProfCostsExcludeRawMaterials() != 1
            || dntaReedWhistleWeightPrintedPc() != 1
            || dntaCarpenterMinerStonemasonVary() != 1
        )
            ++bad;
        // Table 35 anchor rows: the air bladder 15 gp and 20 gp, the basket
        // small 2 sp and 40 gp, the crowbar 3 gp and 75 gp, the pulley 25 gp
        // and 60 gp (all settled by the physical read).
    if (dntaT35CostCp(0) != 1500
            || dntaT35WtGp(0) != 20
            || dntaT35CostCp(2) != 20
            || dntaT35WtGp(2) != 40
            || dntaT35CostCp(8) != 300
            || dntaT35WtGp(8) != 75
            || dntaT35CostCp(16) != 2500
            || dntaT35WtGp(16) != 60
        )
            ++bad;
        // Table 35 small-value rows: the reed and whistle at 1 sp and the
        // printed 1 pc weight, and the lard pint at 5 cp.
    if (dntaT35CostCp(17) != 10
            || dntaT35WtGp(17) != 1
            || dntaT35CostCp(19) != 10
            || dntaT35WtGp(19) != 1
            || dntaT35CostCp(12) != 5
        )
            ++bad;
        // Table 35 transportation rows: the collapsible boat 500 gp and 600
        // gp, the large canoe 300 gp and 1,600 gp, the kayak 250 gp and 500
        // gp.
    if (dntaT35CostCp(20) != 50000
            || dntaT35WtGp(20) != 600
            || dntaT35CostCp(22) != 30000
            || dntaT35WtGp(22) != 1600
            || dntaT35CostCp(23) != 25000
            || dntaT35WtGp(23) != 500
        )
            ++bad;
        // the proficiency space anchors: the boatwright 50 x 120 (6,000 sq
        // ft), the smelter 50 x 50 (2,500), the weaponsmith 40 x 30 (1,200),
        // and the animal-trainer and miner Varies rows at the sentinel.
    if (dntaProfAreaSqft(3) != 6000
            || dntaProfAreaSqft(10) != 2500
            || dntaProfAreaSqft(12) != 1200
            || dntaProfAreaSqft(0) != -99
            || dntaProfAreaSqft(8) != -99
        )
            ++bad;
        printf("R525 DSG equipment costs audit: bad %d\n", bad);
        if (bad) return 1;
    }
