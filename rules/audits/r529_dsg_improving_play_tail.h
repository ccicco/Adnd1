    // ---- R529 DSG improving-play tail audit ----
    // The DSG improving-play tail pins the fighting rules (the low-AC
    // placement, the mini-teams, the surprise paramountcy with the ranger
    // infravision note), the diversion tiers (the 1d4-round low-Int
    // distraction, the mid/high-Int save vs spell, the genius standard, the
    // PC no-save), the speeding-play procedures (the door drills, the
    // marching orders, the rotating caller), the creative spell tactics (the
    // silence coin, the darkness with blindfighting, the telekinesis slime
    // pots, the toppling walls), the tapping language (the 10x slowness, the
    // drum amplification), and the mapping techniques (the 10-ft graphing and
    // its 10-20-ft errors, the 100-ft-sketch line-drawing alternative).
    {
        using namespace rules;
        int bad = 0;
    if (dnpmDivertDice() != 1
            || dnpmDivertSides() != 4
            || dnpmTapLangMult() != 10
            || dnpmMapBlockFt() != 10
            || dnpmMapErrLowFt() != 10
            || dnpmMapErrHighFt() != 20
            || dnpmSketchFt() != 100
            || !dnpmFightTogetherLonger()
            || !dnpmLowAcInFront()
            || !dnpmRetreatPlans()
            || !dnpmMiniTeams()
            || !dnpmSurpriseParamount()
            || !dnpmRangerInfravisionNote()
            || !dnpmDiversionNoConceal()
            || !dnpmIntelligentMonstersWary()
            || !dnpmMidHighIntSave()
            || !dnpmGeniusNeedsClever()
            || !dnpmPcNoSaveVsDiversion()
            || !dnpmPaceGroupTaste()
            || !dnpmWastedTimeBane()
            || !dnpmDoorDrills()
            || !dnpmMarchingOrders()
            || !dnpmCallerRotation()
            || !dnpmBossyPeerPressure()
            || !dnpmBalancedSpellSelection()
            || !dnpmSleepProtections()
            || !dnpmDeadlyUndergroundSpells()
            || !dnpmWaterSpells()
            || !dnpmEnlargeReduceWarp()
            || !dnpmSilenceCoin()
            || !dnpmDarknessVsInfravision()
            || !dnpmTelekinesisPots()
            || !dnpmCharmQuestioning()
            || !dnpmTopplingWallsRicochet()
            || !dnpmTappingLanguage()
            || !dnpmDrumAmplification()
            || !dnpmGraphingWeaknesses()
            || !dnpmOverlapAgonizing()
            || !dnpmMapPurposeExit()
            || !dnpmLineDrawingMap()
            || !dnpmLineMapLimits()
        )
            ++bad;
        // the tail dice and multipliers: the 1d4-round diversion distraction
        // and the 10x-slower tapping language.
    if (dnpmDivertDice() != 1
            || dnpmDivertSides() != 4
            || dnpmTapLangMult() != 10
        )
            ++bad;
        // the mapping numbers: the 10-ft graphing blocks, the 10-to-20-ft
        // error explanation, and the 100-ft sketch window.
    if (dnpmMapBlockFt() != 10
            || dnpmMapErrLowFt() != 10
            || dnpmMapErrHighFt() != 20
            || dnpmSketchFt() != 100
        )
            ++bad;
        // the fighting and diversion prose: the low-AC placement, the
        // surprise paramountcy, the ranger infravision note, and the no-save
        // and genius diversion rules.
    if (dnpmLowAcInFront() != 1
            || dnpmSurpriseParamount() != 1
            || dnpmRangerInfravisionNote() != 1
            || dnpmPcNoSaveVsDiversion() != 1
            || dnpmGeniusNeedsClever() != 1
        )
            ++bad;
        // the speeding-play and creative-spell prose: the drills, marching
        // orders and caller, the silence coin, the darkness tactic, the slime
        // pots, and the line-drawing alternative.
    if (dnpmDoorDrills() != 1
            || dnpmMarchingOrders() != 1
            || dnpmCallerRotation() != 1
            || dnpmSilenceCoin() != 1
            || dnpmDarknessVsInfravision() != 1
            || dnpmTelekinesisPots() != 1
            || dnpmLineDrawingMap() != 1
        )
            ++bad;
        printf("R529 DSG improving-play tail audit: bad %d\n", bad);
        if (bad) return 1;
    }
