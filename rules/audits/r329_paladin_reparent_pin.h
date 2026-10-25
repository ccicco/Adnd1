    // ---- R329: the paladin reparent pin
    // audit ----
    // The UA paladin re-parented under the
    // cavalier (p. 16) - the pin-era
    // pattern: the re-parenting, the
    // minima (the cavalier requisites plus
    // WIS 13 and CHA 17), the lawful-good
    // gate with the stray read, the social
    // station with the 0-level track, the
    // no-prime-requisite and
    // no-specialization reads, the cavalier
    // charge (the five abilities), the CHA
    // percentile growth, the retainer
    // cross-reference. The R327/R328 seams
    // cross-checked.
    {
        using namespace rules;
        int bad = 0;
        // U1: the re-parenting
        {
            if (!paladinIsCavalierSubclass())
                ++bad;
        }
        // U2: the minima - the WIS and CHA
        // legs, and the delegation to the
        // R328 cavalier requisites
        {
            if (paladinWisdomMin() != 13)
                ++bad;
            if (paladinCharismaMin() != 17)
                ++bad;
            if (paladinMinAbility(
                ABILITY_WIS) != 13) ++bad;
            if (paladinMinAbility(
                ABILITY_CHA) != 17) ++bad;
            if (paladinMinAbility(
                ABILITY_STR) != 15) ++bad;
            if (paladinMinAbility(
                ABILITY_DEX) != 15) ++bad;
            if (paladinMinAbility(
                ABILITY_CON) != 15) ++bad;
            if (paladinMinAbility(
                ABILITY_INT) != 10) ++bad;
            // the delegation: the non-WIS,
            // non-CHA legs read the parent
            if (paladinMinAbility(ABILITY_STR)
                != cavalierMinAbility(
                    ABILITY_STR)) ++bad;
            if (paladinMinAbility(ABILITY_INT)
                != cavalierMinAbility(
                    ABILITY_INT)) ++bad;
        }
        // U3: the alignment gate
        {
            if (!paladinLawfulGoodOnly())
                ++bad;
            if (!paladinStrayBecomesCavalier())
                ++bad;
            if (!paladinStrayStripsPowers())
                ++bad;
        }
        // U4: the social station and the
        // 0-level track (the R328 seam)
        {
            if (!paladinSocialStationRequired())
                ++bad;
            if (!paladinSponsoredByNobility())
                ++bad;
            if (!paladinRidesZeroLevelTrack())
                ++bad;
            if (paladinZeroLevelHorsemanXp()
                != cavalierHorsemanXp()) ++bad;
            if (paladinZeroLevelLancerXp()
                != cavalierLancerXp()) ++bad;
            if (paladinZeroLevelHorsemanXp()
                != -1500) ++bad;
            if (paladinZeroLevelLancerXp()
                != -500) ++bad;
        }
        // U5: no prime requisite, no
        // specialization (the R327 station
        // ban cross-checked)
        {
            if (!paladinNoPrimeRequisite())
                ++bad;
            if (!paladinSpecializationBanned())
                ++bad;
            if (!uaStationArmorBan(
                UACLASS_PALADIN)) ++bad;
            if (paladinClericalFromLevel()
                != 9) ++bad;
        }
        // U6: the cavalier charge - the
        // five abilities, the PHB read,
        // the CHA growth
        {
            if (paladinCavalierAbilityCount()
                != 5) ++bad;
            if (strcmp(
                paladinCavalierAbilityName(0),
                "weapons of choice") != 0)
                ++bad;
            if (strcmp(
                paladinCavalierAbilityName(4),
                "immunity to fear") != 0)
                ++bad;
            if (!paladinPhbPowersUnchanged())
                ++bad;
            if (!paladinCharismaPercentileGrowth())
                ++bad;
        }
        // U7: the retainer cross-reference
        {
            if (!paladinRetainerRulesDiffer())
                ++bad;
        }
        printf("R329 paladin reparent pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
