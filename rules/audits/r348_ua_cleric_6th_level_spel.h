    // ---- R348: the UA new cleric 6th level spells pin audit ----
    // The UA NEW CLERIC SPELLS (p. 41), the
    // 6th level - only two spells print at
    // this level: forbiddance (the name
    // header never prints - identified by
    // the near-verbatim 2e descendant; the
    // ethics/morals entry ladder with the
    // password gate) and heroes feast (the
    // twelve-hour benefits and the
    // one-hour consume rule). The
    // digit-garble family decodes this
    // round's two 7s as 1 - both
    // corroborated (the later editions'
    // 1-turn casting time; the one-full-hour
    // prose); the forbiddance 6s stay
    // genuine. The R341 continued table
    // prints four 6th-level fragments -
    // neither name seam-checks. The item
    // stays open (the 7th level).
    {
        using namespace rules;
        int bad = 0;
        // U1: forbiddance
        {
            if (strcmp(uac6ForbidName(),
                "Forbiddance (Abjuration)") != 0) ++bad;
            // the name header never prints - an
            // external decode, a hole
            if (!uac6ForbidNameHeaderLost()) ++bad;
            if (!uac6ForbidComponentsVSM()) ++bad;
            if (uac6ForbidLevel() != 6) ++bad;
            if (uac6ForbidRangeInches() != 3) ++bad;
            // a genuine 6, not the family
            if (uac6ForbidCastingTimeRounds() != 6) ++bad;
            if (!uac6ForbidDurationPermanent()) ++bad;
            if (!uac6ForbidSaveSpecial()) ++bad;
            // the AoE prints "6 cubic "/level"
            if (uac6ForbidAoeCubicInchesPerLevel() != 6)
                ++bad;
            // the consecrated-area gate
            if (!uac6ForbidRequiresConsecratedArea()) ++bad;
            if (!uac6ForbidCfCeremonySpell()) ++bad;
            if (!uac6ForbidBasedOnEthicsAndMorals()) ++bad;
            // the entry ladder
            if (!uac6ForbidIdenticalNeedsPassword()) ++bad;
            if (!uac6ForbidIdenticalNoSave()) ++bad;
            if (!uac6ForbidDiffEthicsSaveVsSpell()) ++bad;
            if (uac6ForbidDiffEthicsDamageMin() != 2) ++bad;
            if (uac6ForbidDiffEthicsDamageMax() != 12)
                ++bad;
            if (!uac6ForbidDiffMoralsSaveVsSpell()) ++bad;
            if (uac6ForbidDiffMoralsDamageMin() != 4) ++bad;
            if (uac6ForbidDiffMoralsDamageMax() != 24)
                ++bad;
            if (!uac6ForbidFailedSaveBarsEntry()) ++bad;
            if (!uac6ForbidEffectsCumulative()) ++bad;
            if (!uac6ForbidMultipleSavesPossible()) ++bad;
            if (!uac6ForbidCasterImmune()) ++bad;
            if (!uac6ForbidIntrudersUneasyTense()) ++bad;
            if (!uac6ForbidUneasyVerbFragmentLost()) ++bad;
            // the shattered material sentence
            if (!uac6ForbidMaterialWaterSymbolIronSulfur())
                ++bad;
            if (!uac6ForbidMaterialFragmentLost()) ++bad;
            if (!uac6ForbidSeamFragmentsOnly()) ++bad;
        }
        // U2: heroes feast
        {
            if (strcmp(uac6FeastName(),
                "Heroes' Feast (Evocation)") != 0) ++bad;
            if (!uac6FeastComponentsVSM()) ++bad;
            if (uac6FeastLevel() != 6) ++bad;
            if (uac6FeastRangeInches() != 1) ++bad;
            // the casting prints "7 turn" - the
            // family decodes 1 turn (corroborated)
            if (uac6FeastCastingTimeTurns() != 1) ++bad;
            // the duration prints "7 hour" - the
            // family decodes 1 hour (corroborated)
            if (uac6FeastDurationHours() != 1) ++bad;
            if (!uac6FeastSaveNone()) ++bad;
            if (!uac6FeastAoeOnePerLevel()) ++bad;
            if (!uac6FeastServesOnePerLevel()) ++bad;
            if (!uac6FeastCreatesTableService()) ++bad;
            // the twelve-hour benefits
            if (!uac6FeastCuresAllDiseases()) ++bad;
            if (uac6FeastPoisonImmunityHours() != 12) ++bad;
            if (uac6FeastHealDamageMin() != 5) ++bad;
            if (uac6FeastHealDamageMax() != 8) ++bad;
            if (!uac6FeastAmbrosiaEqualsBless()) ++bad;
            if (uac6FeastBlessHours() != 12) ++bad;
            if (!uac6FeastImmuneFearHopePanic()) ++bad;
            // the one-hour consume rule
            if (uac6FeastConsumeHours() != 1) ++bad;
            if (!uac6FeastEffectsAfterTheHour()) ++bad;
            if (!uac6FeastInterruptRuinsAll()) ++bad;
            // the material
            if (!uac6FeastMaterialSymbolHoney()) ++bad;
            if (!uac6FeastHoneyRoyalLarvae()) ++bad;
        }
        // U3: the seam
        {
            // the R341 continued table prints four
            // 6th-level fragments
            if (uastClericFragCount(6) != 4) ++bad;
            static const char* const n[4] = {
                "Conjure Animals", "Find The Path",
                "Speak With Monsters", "Stone Tell" };
            for (int i = 0; i < 4; ++i) {
                if (strcmp(uastClericFragName(6, i), n[i])
                    != 0) ++bad;
            }
            // neither of this round's names
            // seam-checks - the pins are from the
            // prose alone
            if (!uac6ForbidSeamFragmentsOnly()) ++bad;
            if (!uac6SpellsPinFromProse()) ++bad;
        }
        printf("R348 UA cleric 6th level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
