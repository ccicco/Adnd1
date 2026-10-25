    // ---- R729 OA monsters P oh audit ----
    // OA round one hundred sixteen (capture pp. 281-282): the Chapter 12
    // monster roster - the p oh, the stat block and the drought doctrine
    // riding together, the xp line as consts per the R723 pattern, the
    // apostrophe of the print kept to the comments, single-pass pins per the
    // Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dkqAppear() != 1
            || dkqAC() != 4
            || dkqMove() != 6
            || dkqHD() != 5
            || dkqLairPct() != 30
            || dkqAttackCount() != 1
            || dkqDmgMin() != 1
            || dkqDmgMax() != 6
            || dkqConFloor() != 2
            || dkqDroughtPerWeek() != 1
            || dkqDroughtDiameterMiles() != 5
            || dkqConLossPerHit() != 1
            || dkqXPBase() != 280
            || dkqXPPerHP() != 5
            || !dkqFrequencyVeryRare()
            || !dkqTreasureQ()
            || !dkqDamageOrByWeapon()
            || !dkqSpecialAttacksDrought()
            || !dkqPlusOneWeaponsToHit()
            || !dkqMRStandard()
            || !dkqIntHigh()
            || !dkqAlignmentChaoticEvil()
            || !dkqSizeSmall()
            || !dkqPsionicNil()
            || !dkqModesNil()
            || !dkqSmallHumanoid()
            || !dkqRuddyBronzeSkin()
            || !dkqRedHair()
            || !dkqWanderingSpirit()
            || !dkqFearedByCommonFolk()
            || !dkqGivenOfferings()
            || !dkqAgriculturalLands()
            || !dkqClubFromWitheredTree()
            || !dkqIronRod()
            || !dkqHitForcesSaveVsSpell()
            || !dkqSaveSuccessNoEffect()
            || !dkqDessicatedOnFailure()
            || !dkqConZeroIsDeath()
            || !dkqInvisibleAtWill()
            || !dkqCreatesDrought()
            || !dkqDroughtUntilCancelled()
            || !dkqFindsSecureLair()
            || !dkqAnnouncesToPeasants()
            || !dkqCollectsWhileInvisible()
            || !dkqSatisfiedByOfferings()
            || !dkqDroughtOnInsufficientOfferings()
            || !dkqCountryRoadShrines()
            || !dkqSentByCelestialEmperor()
            || !dkqSpeaksTwoLanguages()
        )
            ++bad;
        // the stat block - the stat block pins, healthy values, each
        // condition false
    if (dkqFrequencyVeryRare() != 1
            || dkqAppear() != 1
            || dkqAC() != 4
            || dkqMove() != 6
            || dkqHD() != 5
            || dkqLairPct() != 30
            || dkqTreasureQ() != 1
            || dkqAttackCount() != 1
            || dkqDmgMin() != 1
            || dkqDmgMax() != 6
            || dkqDamageOrByWeapon() != 1
            || dkqSpecialAttacksDrought() != 1
            || dkqPlusOneWeaponsToHit() != 1
            || dkqMRStandard() != 1
            || dkqIntHigh() != 1
            || dkqAlignmentChaoticEvil() != 1
            || dkqSizeSmall() != 1
            || dkqPsionicNil() != 1
            || dkqModesNil() != 1
        )
            ++bad;
        // the xp line - the V/280 + 5 per hp, healthy values, each condition
        // false
    if (dkqXPBase() != 280
            || dkqXPPerHP() != 5
        )
            ++bad;
        // the wandering spirit - the look and the fear, healthy values, each
        // condition false
    if (dkqSmallHumanoid() != 1
            || dkqRuddyBronzeSkin() != 1
            || dkqRedHair() != 1
            || dkqWanderingSpirit() != 1
            || dkqFearedByCommonFolk() != 1
            || dkqGivenOfferings() != 1
            || dkqAgriculturalLands() != 1
        )
            ++bad;
        // the drying touch - the weapons, the save, and the Constitution
        // ladder, healthy values, each condition false
    if (dkqClubFromWitheredTree() != 1
            || dkqIronRod() != 1
            || dkqHitForcesSaveVsSpell() != 1
            || dkqSaveSuccessNoEffect() != 1
            || dkqDessicatedOnFailure() != 1
            || dkqConLossPerHit() != 1
            || dkqConFloor() != 2
            || dkqConZeroIsDeath() != 1
            || dkqInvisibleAtWill() != 1
        )
            ++bad;
        // the drought - the power and the peasant squeeze, healthy values,
        // each condition false
    if (dkqCreatesDrought() != 1
            || dkqDroughtPerWeek() != 1
            || dkqDroughtUntilCancelled() != 1
            || dkqDroughtDiameterMiles() != 5
            || dkqFindsSecureLair() != 1
            || dkqAnnouncesToPeasants() != 1
            || dkqCollectsWhileInvisible() != 1
            || dkqSatisfiedByOfferings() != 1
            || dkqDroughtOnInsufficientOfferings() != 1
            || dkqCountryRoadShrines() != 1
            || dkqSentByCelestialEmperor() != 1
            || dkqSpeaksTwoLanguages() != 1
        )
            ++bad;
        printf("R729 OA monsters P oh audit: bad %d\n", bad);
        if (bad) return 1;
    }
