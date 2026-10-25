    // ---- R378: the UA new rings
    // prose pin audit ----
    // The six clean new-ring
    // descriptions (pp. 92-94):
    // animal friendship,
    // anything, blinking,
    // jumping, mind shielding,
    // truth. The seven garbled
    // descriptions filled by
    // the R397 clean read. The
    // R377 seam
    // cross-checks the scrolls
    // ledger, the R375 seam the
    // ring band; the census
    // 304 -> 305.
    {
        using namespace rules;
        int bad = 0;
        // ---- the animal friendship ring ----
            if (uarpAfRadiusIn() != 1) ++bad;
            if (!uarpAfSaveIsVsSpell()) ++bad;
            if (!uarpAfSaveSuccessFlees()) ++bad;
            if (!uarpAfSaveFailDocile()) ++bad;
            if (uarpAfDweomerLevel() != 6) ++bad;
            if (uarpAfMaxHd() != 12) ++bad;
            if (uarpAfGuardCostCharges() != 1) ++bad;
            if (uarpAfChargesTypical() != 27) ++bad;
            if (uarpAfRechargeable()) ++bad;
            if (uarpAfDruidMaxHd() != 24) ++bad;
            if (uarpAfRangerMaxHd() != 18) ++bad;
            // the druid doubles the
            // base dice; the ranger
            // rides the middle
            if (uarpAfDruidMaxHd()
                    != 2 * uarpAfMaxHd()) ++bad;
            if (uarpAfRangerMaxHd()
                    <= uarpAfMaxHd()) ++bad;
        // ---- the anything ring ----
            if (!uarpAnyAppearsWarmth()) ++bad;
            if (uarpAnyCommands() != 3) ++bad;
            if (!uarpAnyOpTypeIsOneOperation())
                ++bad;
            if (uarpAnyEffectHours() != 24) ++bad;
            if (!uarpAnyNeverReusable()) ++bad;
            if (!uarpAnyBecomesJewelry()) ++bad;
            if (uarpAnyJewelryLoGp() != 100) ++bad;
            if (uarpAnyJewelryHiGp() != 600) ++bad;
            if (uarpAnyJewelryLoGp()
                    >= uarpAnyJewelryHiGp()) ++bad;
        // ---- the blinking ring ----
            if (!uarpBlinkIsBlinkSpell()) ++bad;
            if (uarpBlinkActiveRounds() != 6) ++bad;
            if (uarpBlinkRechargeTurns() != 6) ++bad;
            if (uarpBlinkRechargeHours() != 1) ++bad;
            if (!uarpBlinkWordEngraved()) ++bad;
            if (!uarpBlinkAnyoneMaySpeak()) ++bad;
            if (uarpBlinkActivationFeet() != 10)
                ++bad;
        // ---- the jumping ring ----
            if (uarpJumpActivationSegs() != 1)
                ++bad;
            if (uarpJumpAheadFeet() != 30) ++bad;
            if (uarpJumpBackFeet() != 10) ++bad;
            if (uarpJumpArcFeetPerTen() != 2) ++bad;
            if (uarpJumpUsesPerDay() != 4) ++bad;
            if (uarpJumpAheadFeet()
                    != 3 * uarpJumpBackFeet()) ++bad;
        // ---- the mind shielding ring ----
            if (uarpMsImmuneCount() != 4) ++bad;
            if (!uarpMsBlocksEsp()) ++bad;
            if (!uarpMsBlocksDetectLie()) ++bad;
            if (!uarpMsBlocksKnowAlignment()) ++bad;
            if (!uarpMsBlocksTelepathy()) ++bad;
            if (!uarpMsThoughtShieldFree()) ++bad;
            if (uarpMsPsionicAttackDmgAdj() != -2)
                ++bad;
            if (uarpMsBlastSaveNonPsionic() != 1)
                ++bad;
            if (uarpMsBlastDmgPsionic() != -3) ++bad;
        // ---- the truth ring ----
            if (!uarpTruthLiesDetectable()) ++bad;
            if (!uarpTruthWearerCannotLie()) ++bad;
            if (!uarpTruthSpeaksLiteralTruth())
                ++bad;
            if (!uarpTruthDiscernsLastLie()) ++bad;
            if (!uarpTruthFalsettoVoice()) ++bad;
            if (!uarpTruthDweomerBlocksNotice())
                ++bad;
            if (!uarpTruthDweomerSilencesVoice())
                ++bad;
        // ---- the extract ledger ----
            if (uarpCleanCount() != 13) ++bad;
            if (uarpGarbledCount() != 0) ++bad;
            if (uarpTotalTypes() != 13) ++bad;
            if (uarpCleanCount() + uarpGarbledCount()
                    != uarpTotalTypes()) ++bad;
        // ---- the R377 scrolls seam ----
            if (uapsCleanCount() != 15) ++bad;
            if (uapsGarbledCount() != 0) ++bad;
        // ---- the R375 skeleton seam ----
            // the rings ride the
            // 36-40 band, split 01-67
            // new / 68-00 original
            if (uadsCategoryLo(2) != 36) ++bad;
            if (uadsCategoryHi(2) != 40) ++bad;
            if (uadsRingSplitLo() != 67) ++bad;
            if (uadsRowBodiesGarble()) ++bad;
        printf("R378 UA new rings prose pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
