    // ---- R396: the UA potions
    // prose completion pin
    // audit ----
    // The clean read fills the
    // seven PDF-gated
    // descriptions (pp. 90-91):
    // the oils of acid
    // resistance,
    // disenchantment, elemental
    // invulnerability, impact,
    // and the philters of
    // beauty, glibness,
    // stammering - the R376
    // item closes, all nineteen
    // descriptions pin.
    {
        using namespace rules;
        int bad = 0;
        // ---- the acid resistance ----
            if (!uappAcidResCoversAnyMaterial())
                ++bad;
            if (uappAcidResDurationHours() != 24)
                ++bad;
            if (uappAcidResBigBlackMinutes()
                    != 64) ++bad;
            if (uappAcidResBigBlackSavedMinutes()
                    != 32) ++bad;
            if (uappAcidResOneManSizeHours()
                    != 24) ++bad;
            if (uappAcidResOneHourCreatures()
                    != 24) ++bad;
            if (uappAcidResHorseEqualsMen()
                    != 8) ++bad;
            // the day and the
            // creatures-per-hour
            // trade against the
            // flask
            if (uappAcidResOneManSizeHours()
                    != uappAcidResOneHourCreatures())
                ++bad;
        // ---- the disenchantment ----
            if (!uappDisenRemovesFromLiving())
                ++bad;
            if (uappDisenLostTurnsLo() != 21)
                ++bad;
            if (uappDisenLostTurnsHi() != 30)
                ++bad;
            // the lost-turns band
            // is d10 + 20
            if (uappDisenLostTurnsHi()
                    - uappDisenLostTurnsLo()
                    != 9) ++bad;
            if (!uappDisenItemRegainsDweomer())
                ++bad;
            if (uappDisenRadiatesMagic()) ++bad;
            if (!uappDisenMasksDweomer()) ++bad;
        // ---- the elemental
        // invulnerability ----
            if (uappElemInvSortCount() != 4)
                ++bad;
            if (uappElemInvSortDieSides()
                    != uappElemInvSortCount())
                ++bad;
            if (!uappElemInvNormalElementalProof())
                ++bad;
            if (uappElemInvPlaneUsablePct()
                    != 10) ++bad;
            if (uappElemInvMonsterDamagePerDie()
                    != -1) ++bad;
            // one for eight days or
            // eight for one day
            if (uappElemInvCoverageIndividuals()
                    != 8) ++bad;
            if (uappElemInvCoverageDays()
                    != uappElemInvCoverageIndividuals())
                ++bad;
        // ---- the impact ----
            if (!uappImpactBluntAndMissiles())
                ++bad;
            if (uappImpactMissileKindCount()
                    != 4) ++bad;
            if (uappImpactApplicationsLo() != 3)
                ++bad;
            if (uappImpactApplicationsHi() != 5)
                ++bad;
            if (uappImpactHandRoundsLo() != 9)
                ++bad;
            if (uappImpactHandRoundsHi() != 12)
                ++bad;
            if (!uappImpactMissileSingleCharge())
                ++bad;
            if (uappImpactSlingPerAppLo() != 4)
                ++bad;
            if (uappImpactSlingPerAppHi() != 5)
                ++bad;
            if (uappImpactLargerWeaponsPerApp()
                    != 2) ++bad;
            if (uappImpactHandHitBonus() != 3)
                ++bad;
            // the hand weapon's
            // damage doubles its
            // hit bonus
            if (uappImpactHandDamageBonus()
                    != uappImpactHandHitBonus()
                    * 2) ++bad;
            if (uappImpactMissileHitBonus()
                    != 3) ++bad;
            if (uappImpactMissileDamageBonus()
                    != uappImpactMissileHitBonus())
                ++bad;
        // ---- the beauty ----
            if (uappBeautyChaBonus() != 1)
                ++bad;
            if (uappBeautyChaMax() != 18)
                ++bad;
            if (uappBeautyComelinessLo() != 1)
                ++bad;
            if (uappBeautyComelinessHi() != 4)
                ++bad;
            if (!uappBeautyWearOffSightedHostile())
                ++bad;
        // ---- the glibness ----
            if (!uappGlibSpeechUndetectable())
                ++bad;
            if (!uappGlibDetectLieShowsStretching())
                ++bad;
        // ---- the stammering ----
            if (!uappStamSeemsBeneficial())
                ++bad;
            if (!uappStamMeaningfulSpeechFails())
                ++bad;
            if (!uappStamHitsSpellComponents())
                ++bad;
            if (uappStamReactionPenaltyPct()
                    != 25) ++bad;
        // ---- the ledger seam ----
            // the R376/R377 ledger
            // asserts carry the
            // flipped counts; the
            // fills ride here
            if (uappPartCleanCount()
                    + uappPartGarbledCount()
                    != 19) ++bad;
        printf("R396 UA potions prose completion pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
