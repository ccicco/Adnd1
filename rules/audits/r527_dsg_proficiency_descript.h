    // ---- R527 DSG proficiency descriptions audit ----
    // The DSG proficiency descriptions pin the fourteen brief introductions -
    // the animal trainer's outdoor-room requirement, the armorer's forge with
    // ventilation and exhaust, the blacksmith's greater-but-cruder toolkit,
    // the boatwright's launchable location with the boat-size-plus-10-feet
    // space rule, the bowyer's knives and vises, the carpenter's woodworking
    // tools, the gem cutter's tooled chisels and strongboxes, the
    // leatherworker's punch-and-needle kit, the miner's pan-vs-tunnel
    // equipment ladder, the potter's kiln limit, the smelter's
    // furnace/bellows/feeding system, the stonemason's wagon and oxen, the
    // weaponsmith's finishing tools, and the weaver's spinning wheel and
    // loom.
    {
        using namespace rules;
        int bad = 0;
    if (dnepBoatwrightMarginFt() != 10
            || !dnepIntroFrame()
            || !dnepAnimalTrainerLittle()
            || !dnepArmorerForge()
            || !dnepBlacksmithSameButMore()
            || !dnepBoatwrightLocationCare()
            || !dnepBowyerLittle()
            || !dnepCarpenterTools()
            || !dnepGemCutterTools()
            || !dnepLeatherworkerTools()
            || !dnepMinerVaries()
            || !dnepPotterKiln()
            || !dnepSmelterFurnace()
            || !dnepStonemasonGoesToWork()
            || !dnepWeaponsmithShop()
            || !dnepWeaverSmall()
        )
            ++bad;
        // the load-bearing catch-up cells: the boatwright 10-ft margin, the
        // armorer forge-and-ventilation setup, the smelter
        // furnace/bellows/feeding system, and the miner pan-vs-tunnel
        // equipment.
    if (dnepBoatwrightMarginFt() != 10
            || dnepArmorerForge() != 1
            || dnepSmelterFurnace() != 1
            || dnepMinerVaries() != 1
        )
            ++bad;
        // the rest of the fourteen paragraphs: the intro frame, the
        // blacksmith, the boatwright location care, the weaver, the potter
        // and the stonemason.
    if (dnepIntroFrame() != 1
            || dnepBlacksmithSameButMore() != 1
            || dnepBoatwrightLocationCare() != 1
            || dnepWeaverSmall() != 1
            || dnepPotterKiln() != 1
            || dnepStonemasonGoesToWork() != 1
        )
            ++bad;
        printf("R527 DSG proficiency descriptions audit: bad %d\n", bad);
        if (bad) return 1;
    }
