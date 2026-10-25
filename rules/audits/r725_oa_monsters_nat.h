    // ---- R725 OA monsters Nat audit ----
    // OA round one hundred twelve (capture pp. 276-278): the Chapter 12
    // monster roster - the nat, the three lesser spirits of the tropics - the
    // stat table and the three descriptions riding together, the AC 0 of the
    // hkum yang colliding with the table sentinel (an R722-class find),
    // single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dkmNatCount() != 3
            || dkmAppear() != 1
            || dkmFearRadius() != 10
            || dkmFearFleeMin() != 2
            || dkmFearFleeMax() != 5
            || dkmDiseaseCloudDiameter() != 10
            || dkmDiseaseHPPerTurn() != 10
            || dkmAnimFireWoodPerDay() != 3
            || dkmLuCursePerDay() != 3
            || dkmElemDmgDivisor() != 2
            || !dkmEinsaungRare()
            || !dkmHkumVeryRare()
            || !dkmLuRare()
            || !dkmEinsaungChaoticGood()
            || !dkmHkumNeutral()
            || !dkmLuChaoticEvil()
            || !dkmEinsaungIntVery()
            || !dkmHkumIntStandard()
            || !dkmLuIntLow()
            || !dkmEinsaungSizeSmall()
            || !dkmHkumSizeMedium()
            || !dkmLuSizeMedium()
            || !dkmTreasureNil()
            || !dkmPsionicNil()
            || !dkmModesNil()
            || !dkmHkumFearAttack()
            || !dkmLuDiseaseAttack()
            || !dkmDefensesSeeBelow()
            || !dkmTropicalJungleSpirits()
            || !dkmHumanoidDemonicCast()
            || !dkmWildTangledHair()
            || !dkmLongClawedFingernails()
            || !dkmSharpFangedTeeth()
            || !dkmNotAllBiteEffectively()
            || !dkmAtWillInvisible()
            || !dkmAtWillLevitate()
            || !dkmAtWillESP()
            || !dkmAtWillComprehendLanguages()
            || !dkmAtWillDeflection()
            || !dkmAtWillDreamVision()
            || !dkmAtWillPossessAnimal()
            || !dkmAtWillDetectShapechanger()
            || !dkmAtWillQuickgrowth()
            || !dkmAtWillPasswall()
            || !dkmAtWillDancingBlade()
            || !dkmImmuneToPoisonAndDisease()
            || !dkmHalfElectricalFireDamage()
            || !dkmSpeakOwnAndWuJenLanguage()
            || !dkmEinsaungBeneficialIfPleased()
            || !dkmEinsaungTakesUpResidence()
            || !dkmEinsaungGoodLuckSign()
            || !dkmEinsaungDepartureIllOmen()
            || !dkmEinsaungSouthCornerpost()
            || !dkmEinsaungLairEthereal()
            || !dkmEinsaungOfferingsAtPost()
            || !dkmEinsaungExtraAtWillPowers()
            || !dkmEinsaungDailyPowers()
            || !dkmEinsaungWeeklyPowers()
            || !dkmEinsaungBlessAura()
            || !dkmEinsaungAuraCoversHouse()
            || !dkmEinsaungShy()
            || !dkmEinsaungActsThroughPossession()
            || !dkmEinsaungAvoidsCombat()
            || !dkmEinsaungAidsByAdvice()
            || !dkmEinsaungPlaysWithChildren()
            || !dkmHkumFearedProtector()
            || !dkmHkumVillageProtector()
            || !dkmHkumCentralResidence()
            || !dkmHkumSpoilsToEthereal()
            || !dkmHkumDispleasureDisaster()
            || !dkmHkumDefendsVillage()
            || !dkmHkumExtraAtWillPowers()
            || !dkmHkumAnimateFireWood()
            || !dkmHkumDailyPowers()
            || !dkmHkumWeeklyPowers()
            || !dkmHkumFearAura()
            || !dkmHkumFearSightOnly()
            || !dkmLuTotallyEvil()
            || !dkmLuGraveyardLair()
            || !dkmLuSimpleMinded()
            || !dkmLuHungryDescent()
            || !dkmLuExtraAtWillPowers()
            || !dkmLuCurseCreepingDarkness()
            || !dkmLuDailyPowers()
            || !dkmLuDiseaseCloud()
            || !dkmLuCloudSaveVsDeath()
            || !dkmLuNoHealingUntilCured()
        )
            ++bad;
        // the dkmNat grid
        int CNat[3][11] = {
            {2,12,2,100,1,10,1,113,2,1,6},
            {0,12,4,100,2,30,2,405,4,1,6},
            {-2,9,8,80,3,10,3,2250,10,1,8},
            };
        int nNat[11] = {0,0,0,0,0,0,0,0,0,0,0};
        int eNat[11] = {1,0,0,0,0,0,0,0,0,0,0};
        for (int b = 0;
             b < dkmNatCount();
             ++b) {
            int vals[11];
            vals[0] = dkmNatAC(b);
            vals[1] = dkmNatMove(b);
            vals[2] = dkmNatHD(b);
            vals[3] = dkmNatLairPct(b);
            vals[4] = dkmNatAttacks(b);
            vals[5] = dkmNatMRPct(b);
            vals[6] = dkmNatWeaponPlus(b);
            vals[7] = dkmNatXPBase(b);
            vals[8] = dkmNatXPPerHP(b);
            vals[9] = dkmNatDmgMin(b);
            vals[10] = dkmNatDmgMax(b);
            for (int c = 0; c < 11;
                 ++c) {
                if (vals[c] != CNat[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nNat[c];
            }
        }
        for (int c = 0; c < 11; ++c)
            if (nNat[c] != eNat[c])
                ++bad;
        // the stat table - the per-type lines, healthy values, each condition
        // false
    if (dkmAppear() != 1
            || dkmEinsaungRare() != 1
            || dkmHkumVeryRare() != 1
            || dkmLuRare() != 1
            || dkmEinsaungChaoticGood() != 1
            || dkmHkumNeutral() != 1
            || dkmLuChaoticEvil() != 1
            || dkmEinsaungIntVery() != 1
            || dkmHkumIntStandard() != 1
            || dkmLuIntLow() != 1
            || dkmEinsaungSizeSmall() != 1
            || dkmHkumSizeMedium() != 1
            || dkmLuSizeMedium() != 1
            || dkmTreasureNil() != 1
            || dkmPsionicNil() != 1
            || dkmModesNil() != 1
            || dkmHkumFearAttack() != 1
            || dkmLuDiseaseAttack() != 1
            || dkmDefensesSeeBelow() != 1
        )
            ++bad;
        // the nat grid - the three-column stat table, audited cell by cell by
        // the table audit
    if (dkmNatCount() != 3
        )
            ++bad;
        // the lesser spirit nature - the habitat, the look, and the at-will
        // roster, healthy values, each condition false
    if (dkmTropicalJungleSpirits() != 1
            || dkmHumanoidDemonicCast() != 1
            || dkmWildTangledHair() != 1
            || dkmLongClawedFingernails() != 1
            || dkmSharpFangedTeeth() != 1
            || dkmNotAllBiteEffectively() != 1
            || dkmAtWillInvisible() != 1
            || dkmAtWillLevitate() != 1
            || dkmAtWillESP() != 1
            || dkmAtWillComprehendLanguages() != 1
            || dkmAtWillDeflection() != 1
            || dkmAtWillDreamVision() != 1
            || dkmAtWillPossessAnimal() != 1
            || dkmAtWillDetectShapechanger() != 1
            || dkmAtWillQuickgrowth() != 1
            || dkmAtWillPasswall() != 1
            || dkmAtWillDancingBlade() != 1
            || dkmImmuneToPoisonAndDisease() != 1
            || dkmHalfElectricalFireDamage() != 1
            || dkmElemDmgDivisor() != 2
            || dkmSpeakOwnAndWuJenLanguage() != 1
        )
            ++bad;
        // the einsaung nat - the household benefactor and its powers, healthy
        // values, each condition false
    if (dkmEinsaungBeneficialIfPleased() != 1
            || dkmEinsaungTakesUpResidence() != 1
            || dkmEinsaungGoodLuckSign() != 1
            || dkmEinsaungDepartureIllOmen() != 1
            || dkmEinsaungSouthCornerpost() != 1
            || dkmEinsaungLairEthereal() != 1
            || dkmEinsaungOfferingsAtPost() != 1
            || dkmEinsaungExtraAtWillPowers() != 1
            || dkmEinsaungDailyPowers() != 1
            || dkmEinsaungWeeklyPowers() != 1
            || dkmEinsaungBlessAura() != 1
            || dkmEinsaungAuraCoversHouse() != 1
            || dkmEinsaungShy() != 1
            || dkmEinsaungActsThroughPossession() != 1
            || dkmEinsaungAvoidsCombat() != 1
            || dkmEinsaungAidsByAdvice() != 1
            || dkmEinsaungPlaysWithChildren() != 1
        )
            ++bad;
        // the hkum yang nat - the village protector and its powers, healthy
        // values, each condition false
    if (dkmHkumFearedProtector() != 1
            || dkmHkumVillageProtector() != 1
            || dkmHkumCentralResidence() != 1
            || dkmHkumSpoilsToEthereal() != 1
            || dkmHkumDispleasureDisaster() != 1
            || dkmHkumDefendsVillage() != 1
            || dkmHkumExtraAtWillPowers() != 1
            || dkmHkumAnimateFireWood() != 1
            || dkmAnimFireWoodPerDay() != 3
            || dkmHkumDailyPowers() != 1
            || dkmHkumWeeklyPowers() != 1
            || dkmHkumFearAura() != 1
            || dkmFearRadius() != 10
            || dkmFearFleeMin() != 2
            || dkmFearFleeMax() != 5
            || dkmHkumFearSightOnly() != 1
        )
            ++bad;
        // the lu nat - the graveyard evil and its disease cloud, healthy
        // values, each condition false
    if (dkmLuTotallyEvil() != 1
            || dkmLuGraveyardLair() != 1
            || dkmLuSimpleMinded() != 1
            || dkmLuHungryDescent() != 1
            || dkmLuExtraAtWillPowers() != 1
            || dkmLuCurseCreepingDarkness() != 1
            || dkmLuCursePerDay() != 3
            || dkmLuDailyPowers() != 1
            || dkmLuDiseaseCloud() != 1
            || dkmDiseaseCloudDiameter() != 10
            || dkmLuCloudSaveVsDeath() != 1
            || dkmDiseaseHPPerTurn() != 10
            || dkmLuNoHealingUntilCured() != 1
        )
            ++bad;
        printf("R725 OA monsters Nat audit: bad %d\n", bad);
        if (bad) return 1;
    }
