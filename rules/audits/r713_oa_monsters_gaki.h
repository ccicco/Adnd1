    // ---- R713 OA monsters Gaki audit ----
    // OA round one hundred (capture pp. 262-263): the Chapter 12 monster
    // roster - the gaki, the four-type spirit round, the stat block and the
    // description riding together, single-pass pins per the Chapter 9
    // provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dkaGakiTypeCount() != 4
            || dkaGakiPasswallPerDay() != 3
            || dkaJikiKetsuNoApp() != 1
            || dkaJikiKetsuAC() != 2
            || dkaJikiKetsuMoveFly() != 12
            || dkaJikiKetsuMoveGround() != 6
            || dkaJikiKetsuHD() != 8
            || dkaJikiKetsuAttacks() != 3
            || dkaJikiKetsuClawDmgMin() != 1
            || dkaJikiKetsuClawDmgMax() != 3
            || dkaJikiKetsuBiteDmgMax() != 8
            || dkaJikiKetsuBloodDrainMin() != 1
            || dkaJikiKetsuBloodDrainMax() != 10
            || dkaJikiKetsuRegenPerRound() != 1
            || dkaJikiKetsuXPBase() != 1075
            || dkaJikiKetsuXPPerHP() != 10
            || dkaJikiNikuNoAppMin() != 1
            || dkaJikiNikuNoAppMax() != 4
            || dkaJikiNikuAC() != 6
            || dkaJikiNikuHD() != 3
            || dkaJikiNikuAttacks() != 3
            || dkaJikiNikuClawDmgMin() != 1
            || dkaJikiNikuClawDmgMax() != 4
            || dkaJikiNikuBiteDmgMax() != 8
            || dkaJikiNikuRegenPerTurn() != 1
            || dkaJikiNikuXPBase() != 50
            || dkaJikiNikuXPPerHP() != 3
            || dkaShikkiNoApp() != 1
            || dkaShikkiAC() != 4
            || dkaShikkiMoveFly() != 12
            || dkaShikkiMoveGround() != 6
            || dkaShikkiHD() != 5
            || dkaShikkiAttacks() != 2
            || dkaShikkiClawDmgMin() != 1
            || dkaShikkiClawDmgMax() != 4
            || dkaShikkiDiseaseOnsetDice() != 2
            || dkaShikkiDiseaseOnsetSides() != 6
            || dkaShikkiHPPerHour() != 1
            || dkaShikkiDiseaseDaysMin() != 2
            || dkaShikkiDiseaseDaysMax() != 5
            || dkaShikkiRegenPerTurn() != 2
            || dkaShikkiXPBase() != 245
            || dkaShikkiXPPerHP() != 5
            || dkaShinenNoAppMin() != 1
            || dkaShinenNoAppMax() != 3
            || dkaShinenAC() != 0
            || dkaShinenHD() != 4
            || dkaShinenAttacks() != 1
            || dkaShinenDmgMin() != 1
            || dkaShinenDmgMax() != 8
            || dkaShinenFireDmgMax() != 10
            || dkaShinenWaterSavePenalty() != 2
            || dkaShinenWaterBonusPerDie() != 1
            || dkaShinenRegenPerTurn() != 3
            || dkaShinenXPBase() != 135
            || dkaShinenXPPerHP() != 4
            || !dkaGakiSpiritsOfWicked()
            || !dkaGakiCrimesDetermineType()
            || !dkaGakiCompelledEvil()
            || !dkaGakiNeverSated()
            || !dkaGakiInvisibleAtWill()
            || !dkaGakiInsectPolymorph()
            || !dkaGakiImmuneMentalSpells()
            || !dkaGakiSubjectToSpiritSpells()
            || !dkaJikiKetsuVeryRare()
            || !dkaJikiKetsuLairNil()
            || !dkaJikiKetsuTreasureNil()
            || !dkaJikiKetsuMostFearsome()
            || !dkaJikiKetsuVampiric()
            || !dkaJikiKetsuBiteGrips()
            || !dkaJikiKetsuNeverLetsGo()
            || !dkaJikiKetsuPlus3Weapons()
            || !dkaJikiKetsuImmuneColdFire()
            || !dkaJikiKetsuNightActive()
            || !dkaJikiNikuRare()
            || !dkaJikiNikuLairNil()
            || !dkaJikiNikuTreasureNil()
            || !dkaJikiNikuMostCommon()
            || !dkaJikiNikuFleshEater()
            || !dkaJikiNikuIdenticalAppearance()
            || !dkaJikiNikuCarriesOffVictims()
            || !dkaJikiNikuGraveyardHaunts()
            || !dkaShikkiUncommon()
            || !dkaShikkiLairNil()
            || !dkaShikkiTreasureNil()
            || !dkaShikkiCausesDisease()
            || !dkaShikkiSaveVsPoisonPerHit()
            || !dkaShikkiDelirium()
            || !dkaShikkiPlus1Weapons()
            || !dkaShikkiImmuneDiseasePoison()
            || !dkaShinenUncommon()
            || !dkaShinenLairNil()
            || !dkaShikenTreasureNil()
            || !dkaShinenMove0()
            || !dkaShinenLeastDangerous()
            || !dkaShinenLuresToFlammableGround()
            || !dkaShinenImmuneFire()
            || !dkaShinenPlus2Weapons()
        )
            ++bad;
        // the shared gaki doctrine
    if (dkaGakiTypeCount() != 4
            || dkaGakiPasswallPerDay() != 3
            || dkaGakiSpiritsOfWicked() != 1
            || dkaGakiCrimesDetermineType() != 1
            || dkaGakiCompelledEvil() != 1
            || dkaGakiNeverSated() != 1
            || dkaGakiInvisibleAtWill() != 1
            || dkaGakiInsectPolymorph() != 1
            || dkaGakiImmuneMentalSpells() != 1
            || dkaGakiSubjectToSpiritSpells() != 1
        )
            ++bad;
        // the jiki-ketsu-gaki
    if (dkaJikiKetsuNoApp() != 1
            || dkaJikiKetsuAC() != 2
            || dkaJikiKetsuMoveFly() != 12
            || dkaJikiKetsuMoveGround() != 6
            || dkaJikiKetsuHD() != 8
            || dkaJikiKetsuAttacks() != 3
            || dkaJikiKetsuClawDmgMin() != 1
            || dkaJikiKetsuClawDmgMax() != 3
            || dkaJikiKetsuBiteDmgMax() != 8
            || dkaJikiKetsuBloodDrainMin() != 1
            || dkaJikiKetsuBloodDrainMax() != 10
            || dkaJikiKetsuRegenPerRound() != 1
            || dkaJikiKetsuXPBase() != 1075
            || dkaJikiKetsuXPPerHP() != 10
            || dkaJikiKetsuVeryRare() != 1
            || dkaJikiKetsuLairNil() != 1
            || dkaJikiKetsuTreasureNil() != 1
            || dkaJikiKetsuMostFearsome() != 1
            || dkaJikiKetsuVampiric() != 1
            || dkaJikiKetsuBiteGrips() != 1
            || dkaJikiKetsuNeverLetsGo() != 1
            || dkaJikiKetsuPlus3Weapons() != 1
            || dkaJikiKetsuImmuneColdFire() != 1
            || dkaJikiKetsuNightActive() != 1
        )
            ++bad;
        // the jiki-niku-gaki
    if (dkaJikiNikuNoAppMin() != 1
            || dkaJikiNikuNoAppMax() != 4
            || dkaJikiNikuAC() != 6
            || dkaJikiNikuHD() != 3
            || dkaJikiNikuAttacks() != 3
            || dkaJikiNikuClawDmgMin() != 1
            || dkaJikiNikuClawDmgMax() != 4
            || dkaJikiNikuBiteDmgMax() != 8
            || dkaJikiNikuRegenPerTurn() != 1
            || dkaJikiNikuXPBase() != 50
            || dkaJikiNikuXPPerHP() != 3
            || dkaJikiNikuRare() != 1
            || dkaJikiNikuLairNil() != 1
            || dkaJikiNikuTreasureNil() != 1
            || dkaJikiNikuMostCommon() != 1
            || dkaJikiNikuFleshEater() != 1
            || dkaJikiNikuIdenticalAppearance() != 1
            || dkaJikiNikuCarriesOffVictims() != 1
            || dkaJikiNikuGraveyardHaunts() != 1
        )
            ++bad;
        // the shikki-gaki
    if (dkaShikkiNoApp() != 1
            || dkaShikkiAC() != 4
            || dkaShikkiMoveFly() != 12
            || dkaShikkiMoveGround() != 6
            || dkaShikkiHD() != 5
            || dkaShikkiAttacks() != 2
            || dkaShikkiClawDmgMin() != 1
            || dkaShikkiClawDmgMax() != 4
            || dkaShikkiDiseaseOnsetDice() != 2
            || dkaShikkiDiseaseOnsetSides() != 6
            || dkaShikkiHPPerHour() != 1
            || dkaShikkiDiseaseDaysMin() != 2
            || dkaShikkiDiseaseDaysMax() != 5
            || dkaShikkiRegenPerTurn() != 2
            || dkaShikkiXPBase() != 245
            || dkaShikkiXPPerHP() != 5
            || dkaShikkiUncommon() != 1
            || dkaShikkiLairNil() != 1
            || dkaShikkiTreasureNil() != 1
            || dkaShikkiCausesDisease() != 1
            || dkaShikkiSaveVsPoisonPerHit() != 1
            || dkaShikkiDelirium() != 1
            || dkaShikkiPlus1Weapons() != 1
            || dkaShikkiImmuneDiseasePoison() != 1
        )
            ++bad;
        // the shinen-gaki
    if (dkaShinenNoAppMin() != 1
            || dkaShinenNoAppMax() != 3
            || dkaShinenAC() != 0
            || dkaShinenHD() != 4
            || dkaShinenAttacks() != 1
            || dkaShinenDmgMin() != 1
            || dkaShinenDmgMax() != 8
            || dkaShinenFireDmgMax() != 10
            || dkaShinenWaterSavePenalty() != 2
            || dkaShinenWaterBonusPerDie() != 1
            || dkaShinenRegenPerTurn() != 3
            || dkaShinenXPBase() != 135
            || dkaShinenXPPerHP() != 4
            || dkaShinenUncommon() != 1
            || dkaShinenLairNil() != 1
            || dkaShikenTreasureNil() != 1
            || dkaShinenMove0() != 1
            || dkaShinenLeastDangerous() != 1
            || dkaShinenLuresToFlammableGround() != 1
            || dkaShinenImmuneFire() != 1
            || dkaShinenPlus2Weapons() != 1
        )
            ++bad;
        printf("R713 OA monsters Gaki audit: bad %d\n", bad);
        if (bad) return 1;
    }
