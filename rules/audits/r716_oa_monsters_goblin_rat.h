    // ---- R716 OA monsters Goblin Rat audit ----
    // OA round one hundred three (capture p. 266): the Chapter 12 monster
    // roster - the goblin rat, the stat block and the description riding
    // together, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dkdAppearMin() != 1
            || dkdAppearMax() != 20
            || dkdAC() != 7
            || dkdMove() != 9
            || dkdHD() != 3
            || dkdLairPct() != 20
            || dkdAttackCount() != 1
            || dkdBiteDmgMin() != 1
            || dkdBiteDmgMax() != 8
            || dkdMagicResistPct() != 10
            || dkdXPBase() != 1000
            || dkdXPPerHP() != 10
            || dkdDiseasePct() != 5
            || dkdKingGroupThreshold() != 10
            || dkdKingCountPerGroup() != 1
            || dkdKingHD() != 5
            || dkdKingAC() != 4
            || dkdKingBiteDmgBonus() != 2
            || dkdCatLikeToHitBonus() != 1
            || dkdFormsCount() != 2
            || dkdCommonDiseaseCount() != 3
            || dkdPreferredWeaponCount() != 3
            || dkdSizeMinFeet() != 3
            || dkdSizeMaxFeet() != 4
            || !dkdFrequencyRare()
            || !dkdTreasureTypeB()
            || !dkdDamageByWeaponType()
            || !dkdSpecialAttacksNil()
            || !dkdSpecialDefenseShapechange()
            || !dkdIntelligenceLowToStandard()
            || !dkdAlignmentLawfulEvil()
            || !dkdSizeSmall()
            || !dkdPsionicNil()
            || !dkdPsionicModesNil()
            || !dkdLevelVI()
            || !dkdHengeyokaiKin()
            || !dkdGiantRatForm()
            || !dkdRatmanForm()
            || !dkdFullHpEitherForm()
            || !dkdAnimalFormBite()
            || !dkdBiteTransmitsDisease()
            || !dkdDiseasesCholeraPlagueFever()
            || !dkdRatmanFightsWithWeapons()
            || !dkdRatmanWearsArmor()
            || !dkdPrefersSpears()
            || !dkdPrefersNaginatas()
            || !dkdPrefersTwoHandedSwords()
            || !dkdKingOfTheGroup()
            || !dkdFearsAllFelines()
            || !dkdFelineSaveVsParalyzation()
            || !dkdFailedSaveFleesInPanic()
            || !dkdSuccessfulSaveUnaffected()
            || !dkdAntipathyAndSuperstition()
            || !dkdCatPaintingsWardHousehold()
            || !dkdWardPaintingOfQuality()
            || !dkdFringeOfSettlements()
            || !dkdStealsFoodAndLivestock()
            || !dkdPreysOnLoneTravelers()
            || !dkdLairDesertedTempleOrHut()
            || !dkdNoLanguageOfOwn()
            || !dkdSpeaksTradeAndHuman()
        )
            ++bad;
        // the stat block - the stat block pins, healthy values, each
        // condition false
    if (dkdAppearMin() != 1
            || dkdAppearMax() != 20
            || dkdAC() != 7
            || dkdMove() != 9
            || dkdHD() != 3
            || dkdLairPct() != 20
            || dkdFrequencyRare() != 1
            || dkdTreasureTypeB() != 1
            || dkdAttackCount() != 1
            || dkdBiteDmgMin() != 1
            || dkdBiteDmgMax() != 8
            || dkdDamageByWeaponType() != 1
            || dkdSpecialAttacksNil() != 1
            || dkdSpecialDefenseShapechange() != 1
            || dkdMagicResistPct() != 10
            || dkdIntelligenceLowToStandard() != 1
            || dkdAlignmentLawfulEvil() != 1
            || dkdSizeSmall() != 1
            || dkdSizeMinFeet() != 3
            || dkdSizeMaxFeet() != 4
            || dkdPsionicNil() != 1
            || dkdPsionicModesNil() != 1
            || dkdLevelVI() != 1
            || dkdXPBase() != 1000
            || dkdXPPerHP() != 10
        )
            ++bad;
        // the shapechanger - the two-form shapechange, healthy values, each
        // condition false
    if (dkdHengeyokaiKin() != 1
            || dkdFormsCount() != 2
            || dkdGiantRatForm() != 1
            || dkdRatmanForm() != 1
            || dkdFullHpEitherForm() != 1
        )
            ++bad;
        // the bite and the ratman arms - the disease bite and the ratman
        // weapons, healthy values, each condition false
    if (dkdAnimalFormBite() != 1
            || dkdDiseasePct() != 5
            || dkdBiteTransmitsDisease() != 1
            || dkdCommonDiseaseCount() != 3
            || dkdDiseasesCholeraPlagueFever() != 1
            || dkdRatmanFightsWithWeapons() != 1
            || dkdRatmanWearsArmor() != 1
            || dkdPreferredWeaponCount() != 3
            || dkdPrefersSpears() != 1
            || dkdPrefersNaginatas() != 1
            || dkdPrefersTwoHandedSwords() != 1
        )
            ++bad;
        // the king of the group - the 10-plus group king, healthy values,
        // each condition false
    if (dkdKingGroupThreshold() != 10
            || dkdKingCountPerGroup() != 1
            || dkdKingHD() != 5
            || dkdKingAC() != 4
            || dkdKingBiteDmgBonus() != 2
            || dkdKingOfTheGroup() != 1
        )
            ++bad;
        // the feline antipathy - the feline fear and the cat ward, healthy
        // values, each condition false
    if (dkdFearsAllFelines() != 1
            || dkdFelineSaveVsParalyzation() != 1
            || dkdFailedSaveFleesInPanic() != 1
            || dkdSuccessfulSaveUnaffected() != 1
            || dkdCatLikeToHitBonus() != 1
            || dkdAntipathyAndSuperstition() != 1
            || dkdCatPaintingsWardHousehold() != 1
            || dkdWardPaintingOfQuality() != 1
        )
            ++bad;
        // the lair and the tongue - the fringe habitat and the borrowed
        // tongue, healthy values, each condition false
    if (dkdFringeOfSettlements() != 1
            || dkdStealsFoodAndLivestock() != 1
            || dkdPreysOnLoneTravelers() != 1
            || dkdLairDesertedTempleOrHut() != 1
            || dkdNoLanguageOfOwn() != 1
            || dkdSpeaksTradeAndHuman() != 1
        )
            ++bad;
        printf("R716 OA monsters Goblin Rat audit: bad %d\n", bad);
        if (bad) return 1;
    }
