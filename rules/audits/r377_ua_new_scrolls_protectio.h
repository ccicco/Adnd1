    // ---- R377: the UA new scrolls
    // protection prose pin audit ----
    // The eleven clean
    // protection-scroll types
    // (pp. 91-93): acid, breath
    // weapons (dragon and
    // non-dragon), fire, gas,
    // illusions,
    // paralyzation, plants,
    // poison, the traps trio
    // (50 mechanical, 30
    // magical, 20 any), water.
    // The four garbled types
    // (cold, electricity, the
    // two weapons scrolls)
    // filled by the R397 clean
    // read. The R376 seam
    // cross-checks the potions
    // ledger, the R375 seam the
    // scroll splits; the census
    // 303 -> 304.
    {
        using namespace rules;
        int bad = 0;
        // ---- the acid scroll ----
            if (uapsAcidReadingSegs() != 5)
                ++bad;
            if (uapsAcidDamageLimitHd() != 20)
                ++bad;
            if (uapsAcidDurationLoTurns() != 9)
                ++bad;
            if (uapsAcidDurationHiTurns() != 12)
                ++bad;
            if (uapsAcidExampleBreaths() != 3)
                ++bad;
            if (uapsAcidExampleHdPerBreath() != 6)
                ++bad;
            if (uapsAcidDurationLoTurns()
                    + uapsAcidDurationHiTurns()
                    != 21) ++bad;
        // ---- the breath weapon scrolls ----
            if (uapsBwDragonReadingRounds() != 1)
                ++bad;
            if (uapsBwDragonDurationLoRounds() != 6)
                ++bad;
            if (uapsBwDragonDurationHiRounds() != 12)
                ++bad;
            if (!uapsBwDragonIndividualOnly())
                ++bad;
            if (uapsBwNonDragonReadingSegs() != 1)
                ++bad;
            if (uapsBwNonDragonDurationLoRounds() != 5)
                ++bad;
            if (uapsBwNonDragonDurationHiRounds() != 8)
                ++bad;
            if (!uapsBwNonDragonIndividualOnly())
                ++bad;
        // ---- the fire scroll ----
            if (uapsFireReadingSegs() != 8)
                ++bad;
            if (uapsFireSphereDiamIn() != 3)
                ++bad;
            if (uapsFireDurationLoTurns() != 5)
                ++bad;
            if (uapsFireDurationHiTurns() != 8)
                ++bad;
        // ---- the gas scroll ----
            if (uapsGasReadingSegs() != 3) ++bad;
            if (uapsGasSphereDiamIn() != 1) ++bad;
            if (uapsGasDurationLoRounds() != 5)
                ++bad;
            if (uapsGasDurationHiRounds() != 8)
                ++bad;
        // ---- the illusions scroll ----
            if (uapsIllusionsReadingSegs() != 7)
                ++bad;
            if (uapsIllusionsDurationLoRounds() != 5)
                ++bad;
            if (uapsIllusionsDurationHiRounds() != 30)
                ++bad;
            if (!uapsIllusionsIndividualOnly())
                ++bad;
        // ---- the paralyzation scroll ----
            if (uapsParalReadingRounds() != 1)
                ++bad;
            if (uapsParalDurationLoTurns() != 2)
                ++bad;
            if (uapsParalDurationHiTurns() != 5)
                ++bad;
            if (!uapsParalBlocksHold()) ++bad;
            if (!uapsParalBlocksGas()) ++bad;
            if (!uapsParalReaderOnly()) ++bad;
        // ---- the plants scroll ----
            if (uapsPlantsReadingRounds() != 1)
                ++bad;
            if (uapsPlantsSphereDiamIn() != 1)
                ++bad;
            if (uapsPlantsDurationLoTurns() != 5)
                ++bad;
            if (uapsPlantsDurationHiTurns() != 8)
                ++bad;
        // ---- the poison scroll ----
            if (uapsPoisonReadingSegs() != 3)
                ++bad;
            if (uapsPoisonDurationLoRounds() != 3)
                ++bad;
            if (uapsPoisonDurationHiRounds() != 12)
                ++bad;
            if (!uapsPoisonReaderOnly()) ++bad;
            if (!uapsPoisonNeutralizesInSystem())
                ++bad;
        // ---- the traps scrolls ----
            static const int kTrap[3] = {
                50, 30, 20};
            if (uapsTrapMechanicalPct() != kTrap[0])
                ++bad;
            if (uapsTrapMagicalPct() != kTrap[1])
                ++bad;
            if (uapsTrapAnyPct() != kTrap[2]) ++bad;
            if (kTrap[0] + kTrap[1] + kTrap[2]
                    != 100) ++bad;
            if (uapsTrapMechReadingSegs() != 4)
                ++bad;
            if (uapsTrapMechDurationLoRounds() != 5)
                ++bad;
            if (uapsTrapMechDurationHiRounds() != 20)
                ++bad;
            if (!uapsTrapMechReaderOnly()) ++bad;
            if (!uapsTrapMechNotRevealed()) ++bad;
            if (uapsTrapMagReadingSegs() != 8)
                ++bad;
            if (uapsTrapMagSphereDiamIn() != 1)
                ++bad;
            if (uapsTrapMagDurationLoRounds() != 3)
                ++bad;
            if (uapsTrapMagDurationHiRounds() != 12)
                ++bad;
            if (!uapsTrapMagNotRevealed()) ++bad;
            if (uapsTrapAnyReadingRounds() != 1)
                ++bad;
            if (uapsTrapAnySphereDiamIn() != 1)
                ++bad;
            if (uapsTrapAnyDurationLoRounds() != 2)
                ++bad;
            if (uapsTrapAnyDurationHiRounds() != 8)
                ++bad;
            if (!uapsTrapAnyNotRevealed()) ++bad;
        // ---- the water scroll ----
            if (uapsWaterReadingSegs() != 6)
                ++bad;
            if (uapsWaterSphereDiamIn() != 1)
                ++bad;
            if (uapsWaterDurationLoTurns() != 5)
                ++bad;
            if (uapsWaterDurationHiTurns() != 8)
                ++bad;
        // ---- the extract ledger ----
            if (uapsCleanCount() != 15) ++bad;
            if (uapsGarbledCount() != 0) ++bad;
            if (uapsCleanCount() + uapsGarbledCount()
                    != 15) ++bad;
        // ---- the R376 potions seam ----
            if (uappPartCleanCount() != 19) ++bad;
            if (uappPartGarbledCount() != 0) ++bad;
        // ---- the R375 skeleton seam ----
            // the protection scrolls
            // ride the scrolls band and
            // its II.B.2 second table
            if (uadsScrollSplitLo() != 85) ++bad;
            if (!uadsScrollSecondTableIsIIB2())
                ++bad;
            if (uadsRowBodiesGarble()) ++bad;
        printf("R377 UA new scrolls protection pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
