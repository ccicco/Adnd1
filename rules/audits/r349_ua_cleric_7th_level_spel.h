    // ---- R349: the UA new cleric 7th level spells pin audit ----
    // The UA NEW CLERIC SPELLS (p. 42), the
    // 7th level - exaction (the duty or
    // quest upon a powerful extraplanar
    // creature, the alignment gates, the
    // past-favor or pledge causality, the
    // bargain consequences) and succor
    // (the prepared-object dweomer, the
    // command-word transport, the summons
    // reverse, the 2,000-5,000 gp
    // preparation cost). The digit-garble
    // family decodes this round's two 7s
    // as 1 (the exaction casting matches
    // the abjure precedent; the succor
    // day decode stays verbatim with
    // doubt); the exaction range
    // position-decodes from the
    // interleave. The R341 continued
    // table prints zero 7th-level
    // fragments - both names pin from the
    // prose. The item CLOSES this round -
    // all seven levels pinned.
    {
        using namespace rules;
        int bad = 0;
        // U1: exaction
        {
            if (strcmp(uac7ExactionName(),
                "Exaction (Evocation - Alteration)")
                != 0) ++bad;
            if (!uac7ExactionComponentsVSM()) ++bad;
            if (uac7ExactionLevel() != 7) ++bad;
            // the Range cell interleaves - the
            // bare "1" after the Casting Time
            if (uac7ExactionRangeInches() != 1) ++bad;
            // the casting prints "7 round"
            if (uac7ExactionCastingTimeRounds() != 1)
                ++bad;
            if (!uac7ExactionSaveSpecial()) ++bad;
            if (!uac7ExactionDurationSpecial()) ++bad;
            if (!uac7ExactionAoeOneCreature()) ++bad;
            // the opener word decodes as cast
            if (!uac7ExactionWhenCastOpenerDecoded())
                ++bad;
            if (!uac7ExactionOpenerFragmentLost()) ++bad;
            // the confrontation
            if (!uac7ExactionConfrontsExtraplanar())
                ++bad;
            if (!uac7ExactionRequiresDutyOrQuest()) ++bad;
            // the garbled examples decode
            if (!uac7ExactionExamplesIncludeDevasDemons())
                ++bad;
            if (!uac7ExactionNotOnDeities()) ++bad;
            if (!uac7ExactionExampleFragmentLost()) ++bad;
            // the alignment gates
            if (!uac7ExactionNoEthicalMoralOpposition())
                ++bad;
            if (!uac7ExactionTrueNeutralOpposed()) ++bad;
            // the causality
            if (!uac7ExactionMustKnowOrFairTrade()) ++bad;
            if (!uac7ExactionPastFavorAsCause()) ++bad;
            if (!uac7ExactionPledgeIfNoReason()) ++bad;
            if (!uac7ExactionServiceMustBeReasonable())
                ++bad;
            if (!uac7ExactionActsAsQuest()) ++bad;
            // the completion transport
            if (!uac7ExactionTransportedOnCompletion())
                ++bad;
            if (!uac7ExactionCompletionFragmentLost())
                ++bad;
            // the bargain consequences
            if (!uac7ExactionRewardReturnRequired()) ++bad;
            if (!uac7ExactionCreatureFreedOnReward()) ++bad;
            if (!uac7ExactionFailureInvitesCounterExaction())
                ++bad;
            if (!uac7ExactionFailureGrantsSpellImmunity())
                ++bad;
            if (!uac7ExactionMaterialSymbolPlaneMatterScroll())
                ++bad;
        }
        // U2: succor
        {
            if (strcmp(uac7SuccorName(),
                "Succor (Alteration - Enchantment)"
                " Reversible") != 0) ++bad;
            if (!uac7SuccorReversible()) ++bad;
            if (!uac7SuccorComponentsVSM()) ++bad;
            if (uac7SuccorLevel() != 7) ++bad;
            // the casting prints "7 day"
            if (uac7SuccorCastingTimeDays() != 1) ++bad;
            if (!uac7SuccorRangeTouch()) ++bad;
            if (!uac7SuccorSaveNone()) ++bad;
            if (!uac7SuccorDurationSpecial()) ++bad;
            if (!uac7SuccorAoeOneIndividual()) ++bad;
            // the prepared-object dweomer
            if (!uac7SuccorDweomerInPreparedObject()) ++bad;
            if (uac7SuccorObjectExampleCount() != 3) ++bad;
            for (int i = 0; i < 3; ++i) {
                if (uac7SuccorObjectExampleName(i) == 0)
                    ++bad;
            }
            if (!uac7SuccorRadiatesMagic()) ++bad;
            if (!uac7SuccorTransportsPossessorToSanctuary())
                ++bad;
            // the command-word mechanics
            if (!uac7SuccorGivenWillinglyWithCommandWord())
                ++bad;
            if (!uac7SuccorBreakItemWithCommandWord()) ++bad;
            if (!uac7SuccorWordOfRecallEquivalent()) ++bad;
            if (!uac7SuccorNoOtherCreatures()) ++bad;
            // the summons reverse
            if (!uac7SuccorReverseSummons()) ++bad;
            if (!uac7SuccorReverseVicinityFragmentLost())
                ++bad;
            if (!uac7SuccorClericMayDeclineSummons()) ++bad;
            if (!uac7SuccorDeclineWastesSpell()) ++bad;
            // the preparation cost
            if (uac7SuccorPreparationCostMinGP() != 2000)
                ++bad;
            if (uac7SuccorPreparationCostMaxGP() != 5000)
                ++bad;
            if (!uac7SuccorEitherVersionCosts()) ++bad;
        }
        // U3: the seam
        {
            // the R341 continued table prints
            // zero 7th-level fragments
            if (uastClericFragCount(7) != 0) ++bad;
            if (uastClericFragName(7, 0)[0] != 0) ++bad;
            // neither name seam-checks - the
            // pins are from the prose alone
            if (!uac7ExactionSeamFragmentsOnly()) ++bad;
            if (!uac7SpellsPinFromProse()) ++bad;
        }
        printf("R349 UA cleric 7th level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
