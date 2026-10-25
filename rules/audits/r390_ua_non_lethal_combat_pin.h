    // ---- R390: the UA
    // non-lethal combat appendix
    // R pin audit ----
    // The pp. 109-110 stretch:
    // seven items pin - two
    // fully clean (the subdual
    // eligibility, the subdual
    // damage accounting) plus
    // five mechanics-clean with
    // flagged holes (the subdual
    // supercedes sentence, the
    // vanquishing loser sentence,
    // the chaotic constraints
    // line, the monks-druids
    // garble head, the disarming
    // scimitar seam) - RESOLVED
    // (R422): the clean p. 109
    // read resolves all five;
    // the R159
    // seam the DMG knockout, the
    // R389 seam the System II
    // layer.
    {
        using namespace rules;
        int bad = 0;
            if (!uanlSubdualEffectiveNonLethal()) ++bad;
            if (!uanlSubdualIntMinLow()) ++bad;
            if (!uanlSubdualIntMaxGenius()) ++bad;
            if (!uanlSubdualSimilarTypesDragons()) ++bad;
            if (uanlSubdualExampleCreatureCount() != 6) ++bad;
            if (!uanlSubdualHumanoidNonMagicalSizeL()) ++bad;
            if (!uanlSubdualOtherCreaturesDMDecision()) ++bad;
            if (!uanlSubdualPlanarNativePlaneOnly()) ++bad;
            if (!uanlSubdualPCsNeverSubduable()) ++bad;
            if (!uanlSubdualFlatButtHaftPommel()) ++bad;
            if (!uanlSubdualFullDamageNegates()) ++bad;
            if (!uanlSubdualNotedSeparately()) ++bad;
            if (uanlSubdualTemporaryPct() != 75) ++bad;
            if (uanlSubdualRealPct() != 25) ++bad;
            if (uanlSubdualExamplePoints() != 40) ++bad;
            if (uanlSubdualExampleReal() != 10) ++bad;
            if (!uanlSubdualSubduedWhenExceedsTotal()) ++bad;
            if (!uanlSubduedNoAttackExceptSelfDefense()) ++bad;
            if (!uanlSubduedMonsterWillNotAttackGroup()) ++bad;
            if (!uanlSubduedSubmitsSeeksEscape()) ++bad;
            if (!uanlSubduedTurnsIfPartyWeaker()) ++bad;
            if (!uanlSubdualLastsWhileUpperHand()) ++bad;
            if (!uanlSubdualSupercedesPublished()) ++bad;
            if (!uanlSubdualSupercedesReadsClean()) ++bad;
            if (!uanlSubdualSupercedesDragonSubdual()) ++bad;
            if (!uanlVanqUsedByLawfulToSettle()) ++bad;
            if (!uanlVanqDuelOfHonor()) ++bad;
            if (!uanlVanqChallengeMustTakeUp()) ++bad;
            if (!uanlVanqIntelligentLanguageCapable()) ++bad;
            if (!uanlVanqMustCommunicateAndAgree()) ++bad;
            if (!uanlVanqCombatNormalHoldingBack()) ++bad;
            if (uanlVanqRealDamageQuarterPct() != 25) ++bad;
            if (!uanlVanqResortToRealAtRoundStart()) ++bad;
            if (!uanlVanqFullRealDamageNegates()) ++bad;
            if (!uanlVanqTemporaryLostIgnored()) ++bad;
            if (!uanlVanqPoisonedVorpalPerformReal()) ++bad;
            if (!uanlVanqDamageNotedSeparately()) ++bad;
            if (!uanlVanqLoserAtZeroHp()) ++bad;
            if (!uanlVanqLoserMustHonorablySurrender()) ++bad;
            if (!uanlVanqDrawIfBothZeroSameRound()) ++bad;
            if (!uanlVanqWinnerDemandSingle()) ++bad;
            if (uanlVanqServiceExampleCount() != 4) ++bad;
            if (!uanlVanqItemWeaponArmorShield()) ++bad;
            if (uanlVanqTreasureGpPerHitDieOrLevel() != 1000) ++bad;
            if (!uanlVanqEnslaveOrSlayFreesDuty()) ++bad;
            if (!uanlVanqImprisonIfStated()) ++bad;
            if (!uanlVanqLawfulHonorBound()) ++bad;
            if (!uanlVanqGoodCannotPerformEvil()) ++bad;
            if (!uanlVanqNeutralHasChoice()) ++bad;
            if (!uanlVanqChaoticEvilNoConstraints()) ++bad;
            if (!uanlVanqChaoticLineReadsClean()) ++bad;
            if (!uanlVanqGenerallyTwoCombatants()) ++bad;
            if (!uanlVanqMultipleAllSideToZero()) ++bad;
            if (!uanlVanqZeroDamageMayContinue()) ++bad;
            if (!uanlVanqPastZeroFullDamage()) ++bad;
            if (!uanlVanqMultipleZeroRetiresHonor()) ++bad;
            if (!uanlVanqUsedByMonksAndDruids()) ++bad;
            if (!uanlVanqUsedToAdvanceLevelByCombat()) ++bad;
            if (!uanlVanqLawfulCommunitiesApprehend()) ++bad;
            if (!uanlDisarmFighterCavalierOnly()) ++bad;
            if (uanlDisarmWeaponCount() != 6) ++bad;
            if (uanlDisarmOrderKnife() != 1) ++bad;
            if (uanlDisarmOrderDagger() != 2) ++bad;
            if (uanlDisarmOrderHorsemanMace() != 3) ++bad;
            if (uanlDisarmOrderShortSword() != 4) ++bad;
            if (uanlDisarmOrderFootmanMace() != 5) ++bad;
            if (uanlDisarmOrderSword() != 6) ++bad;
            if (!uanlDisarmKhopeshDisarmsNormally()) ++bad;
            if (!uanlDisarmKhopeshIntentionalTheseRules()) ++bad;
            if (!uanlDisarmRequiresProficiency()) ++bad;
            if (!uanlDisarmOpponentListedWeapon()) ++bad;
            if (!uanlDisarmTwoHandedNeverAffected()) ++bad;
            if (!uanlDisarmInflictsNoDamage()) ++bad;
            if (!uanlDisarmHitThenSaveVsPetrification()) ++bad;
            if (!uanlDisarmSameLengthOrShorterOnly()) ++bad;
            if (!uanlDisarmExampleDaggerDisarmsKnife()) ++bad;
            if (!uanlDisarmExampleScimitarDisarmsMace()) ++bad;
            if (!uanlDisarmExampleDaggerNotShortSword()) ++bad;
            if (!uanlDisarmScimitarSeam()) ++bad;
            if (!uanlDisarmScimitarSeamIsPrint()) ++bad;
            if (!uanlDisarmFallsAtFeetIfSameSize()) ++bad;
            if (uanlDisarmFallsMinFeet() != 1) ++bad;
            if (uanlDisarmFallsMaxFeet() != 10) ++bad;
            if (uanlDisarmRecoverOptionsCount() != 3) ++bad;
            if (!uanlDisarmRecommendedWithSystemTwo()) ++bad;
            if (uanlPartItemTotal() != 7) ++bad;
            if (uanlPartCleanCount() != 7) ++bad;
            if (uanlPartFlaggedCount() != 0) ++bad;
            if (uanlPartGarbledCount() != 0) ++bad;
            if (uanlSubdualTemporaryPct()
                + uanlSubdualRealPct() != 100)
                ++bad;
            if (uanlVanqRealDamageQuarterPct()
                != uanlSubdualRealPct()) ++bad;
            if (uanlVanqTreasureGpPerHitDieOrLevel()
                * 4 != 4000) ++bad;
            if (uanlDisarmOrderDagger()
                <= uanlDisarmOrderKnife()) ++bad;
            if (uanlDisarmOrderShortSword()
                <= uanlDisarmOrderDagger()) ++bad;
            if (uanlDisarmFallsMinFeet()
                >= uanlDisarmFallsMaxFeet()) ++bad;
            if (uanlDisarmWeaponCount()
                != uanlDisarmOrderSword()) ++bad;
            if (subdualTemporaryPct()
                != uanlSubdualTemporaryPct()
                || subdualRealPct()
                != uanlSubdualRealPct()) ++bad;
            if (subdualRealDamage(
                uanlSubdualExamplePoints())
                != uanlSubdualExampleReal()) ++bad;
            if (!uaqSysTwoOutgrowthMorePowerful())
                ++bad;
        printf("R390 UA non-lethal combat pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
