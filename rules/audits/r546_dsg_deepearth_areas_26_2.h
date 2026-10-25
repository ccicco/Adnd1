    // ---- R546 DSG Deepearth areas 26-27 audit ----
    // The DSG Deepearth areas 26-27 pin Area 26 (the Hallowed Grounds with
    // their mile-wide dead caverns, the skeleton battlefields, the undead
    // legions commanded per cavern by 18-27th-level liches and their treasure
    // houses of battle magic) and Area 27 (the Melting Pot with its
    // small-cavern maze, the 1d12-cave racial niches, the sacred waters and
    // the secret routes).
    {
        using namespace rules;
        int bad = 0;
    if (dnaoCeilMinFt() != 1000
            || dnaoLichLvlMin() != 18
            || dnaoLichLvlMax() != 27
            || dnaoLichLvlDice() != 1
            || dnaoLichLvlSides() != 10
            || dnaoLichLvlBase() != 17
            || dnaoLichDualPct() != 20
            || dnaoNicheDice() != 1
            || dnaoNicheSides() != 12
            || !dnaoVastCaverns()
            || !dnaoMileWideChambers()
            || !dnaoGorgeBridges()
            || !dnaoStreamsLakes()
            || !dnaoBarrenBeaten()
            || !dnaoBattleDebris()
            || !dnaoNothingLives()
            || !dnaoSpiritLegions()
            || !dnaoLichPerCavern()
            || !dnaoNoFood()
            || !dnaoScavengedFields()
            || !dnaoTreasureHouses()
            || !dnaoBattleMagic()
            || !dnaoSmallCavernMaze()
            || !dnaoEveryRace()
            || !dnaoVigorousDefense()
            || !dnaoRotheFungus()
            || !dnaoSacredWater()
            || !dnaoExhaustedVeins()
            || !dnaoSecretRoutes()
        )
            ++bad;
        // the hallowed grounds: ceilings 1,000 feet or more.
    if (dnaoCeilMinFt() != 1000
        )
            ++bad;
        // the liches: 18-27th level, rolled as 17 + 1d10.
    if (dnaoLichLvlMin() != 18
            || dnaoLichLvlMax() != 27
            || dnaoLichLvlDice() != 1
            || dnaoLichLvlSides() != 10
            || dnaoLichLvlBase() != 17
        )
            ++bad;
        // the lich castes: 20% magic user/clerics, 80% magic-users only.
    if (dnaoLichDualPct() != 20
        )
            ++bad;
        // the melting pot: 1d12 caves per racial niche.
    if (dnaoNicheDice() != 1
            || dnaoNicheSides() != 12
        )
            ++bad;
        printf("R546 DSG Deepearth areas 26-27 audit: bad %d\n", bad);
        if (bad) return 1;
    }
