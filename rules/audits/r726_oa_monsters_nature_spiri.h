    // ---- R726 OA monsters Nature Spirits audit ----
    // OA round one hundred thirteen (capture pp. 278-279): the Chapter 12
    // monster roster - the nature spirits, the paired stat grid and the
    // six-rung xp ladders riding together with the lifeforce and aspect
    // doctrine, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dknNSCount() != 2
            || dknXPCount() != 6
            || dknGoodAspectChancePct() != 75
            || dknPolymorphCharisma() != 19
            || dknPolymorphComeliness() != 21
            || dknGreaterShapechangePerDay() != 5
            || !dknLesserCommon()
            || !dknGreaterRare()
            || !dknAppear()
            || !dknTreasureLesserI()
            || !dknTreasureGreaterH()
            || !dknSpecialAttacksSeeBelow()
            || !dknSpecialDefensesSeeBelow()
            || !dknIntLesserVeryToGenius()
            || !dknIntGreaterGenius()
            || !dknAlignmentVariable()
            || !dknSizeVariable()
            || !dknPsionicNil()
            || !dknModesNil()
            || !dknOutwardManifestations()
            || !dknLesserOfTreesFlowersRocksBamboo()
            || !dknGreaterOfMountainsBouldersPlainsIslands()
            || !dknLifeforceObjectOrPlace()
            || !dknDamageAffectsSpirit()
            || !dknTreeDeathKillsLesser()
            || !dknEarthquakeMayAngerOrInjure()
            || !dknTwoAspects()
            || !dknGoodAspectGentle()
            || !dknEvilAspectMalicious()
            || !dknShunsMortalWorld()
            || !dknAppearsInDanger()
            || !dknMeetsPeopleOfRenown()
            || !dknCommonInvisible()
            || !dknCommonPolymorphSelf()
            || !dknCommonDetectEvilGood()
            || !dknCommonDetectMagic()
            || !dknCommonDetectHarmony()
            || !dknCommonOncePerRoundAtWill()
            || !dknLesserFoundNearLifeforce()
            || !dknLesserPolymorphedForm()
            || !dknLesserCompleteAreaKnowledge()
            || !dknLesserFindsTreasuresAndLostItems()
            || !dknLesserNoAbilitiesBeyond()
            || !dknLesserMarriesMortals()
            || !dknGreaterConsiderablyMorePowerful()
            || !dknGreaterKnowHistoryAura()
            || !dknGreaterRewardOncePerWeek()
            || !dknGreaterAncientCurseOncePerWeek()
            || !dknGreaterCastsElementSpells()
            || !dknGreaterMountainEarthSpells()
            || !dknGreaterIslandWaterSpells()
            || !dknGreaterPlusFourWeaponsOnly()
            || !dknGreaterImmuneToOwnElement()
            || !dknGreaterCompleteEventKnowledge()
            || !dknGreaterAloofHaughtyIrritable()
            || !dknGreaterSlopeVillageDisdain()
            || !dknMortalsOfferAndConsultShukenja()
            || !dknGreaterSeldomIntermarry()
        )
            ++bad;
        // the dknNS grid
        int CNS[2][9] = {
            {7,12,2,7,80,1,1,8,20},
            {2,12,8,15,100,2,1,10,70},
            };
        int nNS[9] = {0,0,0,0,0,0,0,0,0};
        int eNS[9] = {0,0,0,0,0,0,0,0,0};
        for (int b = 0;
             b < dknNSCount();
             ++b) {
            int vals[9];
            vals[0] = dknNSAC(b);
            vals[1] = dknNSMove(b);
            vals[2] = dknNSHDMin(b);
            vals[3] = dknNSHDMax(b);
            vals[4] = dknNSLairPct(b);
            vals[5] = dknNSAttacks(b);
            vals[6] = dknNSDmgMin(b);
            vals[7] = dknNSDmgMax(b);
            vals[8] = dknNSMRPct(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CNS[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nNS[c];
            }
        }
        for (int c = 0; c < 9; ++c)
            if (nNS[c] != eNS[c])
                ++bad;
        // the dknXP grid
        int CXP[6][4] = {
            {118,2,1275,10},
            {160,3,2000,12},
            {215,4,3000,14},
            {280,5,4400,16},
            {475,6,6100,18},
            {700,8,8100,20},
            };
        int nXP[4] = {0,0,0,0};
        int eXP[4] = {0,0,0,0};
        for (int b = 0;
             b < dknXPCount();
             ++b) {
            int vals[4];
            vals[0] = dknXPLesserBase(b);
            vals[1] = dknXPLesserPerHP(b);
            vals[2] = dknXPGreaterBase(b);
            vals[3] = dknXPGreaterPerHP(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CXP[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nXP[c];
            }
        }
        for (int c = 0; c < 4; ++c)
            if (nXP[c] != eXP[c])
                ++bad;
        // the stat grid - the per-column lines, healthy values, each
        // condition false
    if (dknLesserCommon() != 1
            || dknGreaterRare() != 1
            || dknAppear() != 1
            || dknTreasureLesserI() != 1
            || dknTreasureGreaterH() != 1
            || dknSpecialAttacksSeeBelow() != 1
            || dknSpecialDefensesSeeBelow() != 1
            || dknIntLesserVeryToGenius() != 1
            || dknIntGreaterGenius() != 1
            || dknAlignmentVariable() != 1
            || dknSizeVariable() != 1
            || dknPsionicNil() != 1
            || dknModesNil() != 1
        )
            ++bad;
        // the stat and xp grids - the paired stat table and the six-rung
        // ladder table, audited cell by cell by the table audit
    if (dknNSCount() != 2
            || dknXPCount() != 6
        )
            ++bad;
        // the nature and the aspects - the lifeforce sympathy and the two
        // aspects, healthy values, each condition false
    if (dknOutwardManifestations() != 1
            || dknLesserOfTreesFlowersRocksBamboo() != 1
            || dknGreaterOfMountainsBouldersPlainsIslands() != 1
            || dknLifeforceObjectOrPlace() != 1
            || dknDamageAffectsSpirit() != 1
            || dknTreeDeathKillsLesser() != 1
            || dknEarthquakeMayAngerOrInjure() != 1
            || dknTwoAspects() != 1
            || dknGoodAspectGentle() != 1
            || dknEvilAspectMalicious() != 1
            || dknGoodAspectChancePct() != 75
            || dknShunsMortalWorld() != 1
            || dknAppearsInDanger() != 1
            || dknMeetsPeopleOfRenown() != 1
        )
            ++bad;
        // the common powers - the five powers and the use rate, healthy
        // values, each condition false
    if (dknCommonInvisible() != 1
            || dknCommonPolymorphSelf() != 1
            || dknCommonDetectEvilGood() != 1
            || dknCommonDetectMagic() != 1
            || dknCommonDetectHarmony() != 1
            || dknCommonOncePerRoundAtWill() != 1
        )
            ++bad;
        // the lesser - the haunt, the polymorphed form, and the romance,
        // healthy values, each condition false
    if (dknLesserFoundNearLifeforce() != 1
            || dknLesserPolymorphedForm() != 1
            || dknPolymorphCharisma() != 19
            || dknPolymorphComeliness() != 21
            || dknLesserCompleteAreaKnowledge() != 1
            || dknLesserFindsTreasuresAndLostItems() != 1
            || dknLesserNoAbilitiesBeyond() != 1
            || dknLesserMarriesMortals() != 1
        )
            ++bad;
        // the greater - the powers, the element spellcasting, and the temper,
        // healthy values, each condition false
    if (dknGreaterConsiderablyMorePowerful() != 1
            || dknGreaterShapechangePerDay() != 5
            || dknGreaterKnowHistoryAura() != 1
            || dknGreaterRewardOncePerWeek() != 1
            || dknGreaterAncientCurseOncePerWeek() != 1
            || dknGreaterCastsElementSpells() != 1
            || dknGreaterMountainEarthSpells() != 1
            || dknGreaterIslandWaterSpells() != 1
            || dknGreaterPlusFourWeaponsOnly() != 1
            || dknGreaterImmuneToOwnElement() != 1
            || dknGreaterCompleteEventKnowledge() != 1
            || dknGreaterAloofHaughtyIrritable() != 1
            || dknGreaterSlopeVillageDisdain() != 1
            || dknMortalsOfferAndConsultShukenja() != 1
            || dknGreaterSeldomIntermarry() != 1
        )
            ++bad;
        printf("R726 OA monsters Nature Spirits audit: bad %d\n", bad);
        if (bad) return 1;
    }
