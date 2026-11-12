    // ---- R937 issue-19 opener part one audit ----
    // THE DRAGON ISSUE-19 OPENER PART ONE - the three doctrine chains of the
    // issue. CHAIN ONE, The Lowdown on Wishes by Kevin Thompson (print 12-13,
    // PDF 14-15): the wish-spell Class I-IV ladder - Class I the purely
    // physical objects and occurrences including the time-stop, Class II the
    // living non-magical beings and weak equipment with the level-5
    // magic-user ceiling, Class III the magic-oriented beings and moderate
    // equipment with any MU spell and the level-4 cleric ceiling, Class IV
    // the artifact-rare top with the no-more-wishes and no-artifact-creation
    // walls; the alignment grant matrices - lawful into lawful or neutral,
    // chaotic into neutral or chaotic, neutral into neutral only, the neutral
    // versatility and rarely-twisted doctrine; the object-strength logic -
    // never stronger than the creator, power lost in transfer, weak spells in
    // flimsy objects, the strongest in the immobile, the artifact exceptions
    // with the shrink-an-inch side effect; the wording doctrine and the
    // fishbowl, Abyss and drop-still-used-up adjudications. CHAIN TWO, The
    // Mythos of Australia by Jerome Arkenberg (print 14-15 + 26, PDF 16-17 +
    // 28): the GDH-format pantheon - twenty entities, eighteen statlines in
    // the dwsMythos grid with the armor class, move, hit points, magic level,
    // fighter level and psionic class columns, the eight See Below spell-list
    // gods at the -99 sentinel; Daramulun the All-Father at AC -3 and 300 hit
    // points through the stick-thin Mimi at AC 8; the Wondjina band, the
    // boomerang damage and the lightning-wand axe. CHAIN THREE, Systematic
    // Magic by Robin W. Rhodes (print 18-19, PDF 20-21): the thirteen-field
    // spell redivision - the dwsFields grid with the printed spell counts and
    // the five prime requisite codes, the cross-reference doctrine, the
    // first-level Defence counterpart gap and the five-spell second-level
    // tail.
    {
        using namespace rules;
        int bad = 0;
    if (dwsWishClasses() != 4
            || dwsClassTwoMuLevel() != 5
            || dwsClassThreeClericLevel() != 4
            || dwsLawfulVirtues() != 6
            || dwsChaoticVices() != 6
            || dwsArtifactShrinkPerUse() != 1
            || dwsLenientBalrogs() != 10
            || dwsRingWishes() != 3
            || dwsMythosEntities() != 20
            || dwsMythosStatlines() != 18
            || dwsMythosProseOnly() != 2
            || dwsMythosFlyingEntities() != 5
            || dwsWondjinaMinFeet() != 10
            || dwsWondjinaMaxFeet() != 16
            || dwsTcabFeet() != 9
            || dwsWagtjadbullaFeet() != 12
            || dwsTcabBoomMin() != 5
            || dwsTcabBoomMax() != 30
            || dwsTcabBoomPlus() != 2
            || dwsDjunggunBoomMin() != 10
            || dwsDjunggunBoomMax() != 60
            || dwsDjunggunBoomPlus() != 3
            || dwsMamaranganAxeMin() != 10
            || dwsMamaranganAxeMax() != 60
            || dwsMamaranganAxePlus() != 3
            || dwsGidjaSpells() != 8
            || dwsKallinSpells() != 6
            || dwsWaramurungundjuSpells() != 7
            || dwsMamaranganSpells() != 5
            || dwsMorkulSpells() != 5
            || dwsMamandabariSpells() != 5
            || dwsWawalagSpells() != 3
            || dwsNgunungSpells() != 4
            || dwsYalungurSpells() != 2
            || dwsSeeBelowSentinel() != -99
            || dwsMagicFields() != 13
            || dwsControlSpells() != 26
            || dwsMentalSpells() != 27
            || dwsTimeSpaceSpells() != 27
            || dwsAttackSpells() != 20
            || dwsAnimateSpells() != 25
            || dwsKnowledgeSpells() != 23
            || dwsTransmutationSpells() != 18
            || dwsDefenceSpells() != 18
            || dwsNatureSpells() != 31
            || dwsUnprintedFieldCounts() != 4
            || dwsUnprintedRequisites() != 8
            || dwsReqCharisma() != 1
            || dwsReqWisdom() != 2
            || dwsReqStrength() != 3
            || dwsReqDexterity() != 4
            || dwsReqIntelligence() != 5
            || dwsFirstLevelDefenceSpells() != 2
            || dwsSecondLevelTailNewFields() != 5
            || !dwsClassOnePhysicalObjects()
            || !dwsClassOneOccurrences()
            || !dwsClassTwoLivingBeings()
            || !dwsClassTwoWeakEquipment()
            || !dwsClassTwoNoWishEquipment()
            || !dwsClassThreeMagicBeings()
            || !dwsClassThreeWeakestOnlySlaves()
            || !dwsClassThreeModerateEquipment()
            || !dwsClassThreeAnyMuSpell()
            || !dwsClassFourRareOutsideArtifact()
            || !dwsClassFourNoMoreWishes()
            || !dwsClassFourNoArtifactCreation()
            || !dwsClassOneCanLeadToArtifact()
            || !dwsNeverTellPlayersClass()
            || !dwsLawfulGrantsLawfulOrNeutral()
            || !dwsChaoticGrantsNeutralOrChaotic()
            || !dwsNeutralGrantsNeutralOnly()
            || !dwsNeutralFavoredVersatile()
            || !dwsNeutralRarelyTwisted()
            || !dwsTwistedOnlyTypePossible()
            || !dwsFruitCocktailTypePossible()
            || !dwsNeverStrongerThanCreator()
            || !dwsPowerLostInTransfer()
            || !dwsWeakWsInFlimsyObjects()
            || !dwsStrongWsInDurableObjects()
            || !dwsStrongestWsImmobile()
            || !dwsArtifactsMorePowerful()
            || !dwsArtifactSideEffects()
            || !dwsLongWishEasierToTwist()
            || !dwsShortWishTooLittleInfo()
            || !dwsSimpleWordingFewProblems()
            || !dwsWsSomeUnderstandingPower()
            || !dwsFishbowlMirrorAdjudication()
            || !dwsAbyssAdjudication()
            || !dwsDropWishStillUsedUp()
            || !dwsDmDecidesMotiveSilently()
            || !dwsSubclassesEncouraged()
            || !dwsNgunungGateTwice()
            || !dwsWodoiMasterThief()
            || !dwsMamaranganAxeLightningWand()
            || !dwsMimiAfraidOfWind()
            || !dwsMimiEatMen()
            || !dwsMimiFoodYams()
            || !dwsWawalagSwallowedByYurlunggur()
            || !dwsYurlunggurGreatHealer()
            || !dwsYurlunggurWrathFloodDisease()
            || !dwsGidjaBanishedToNightSky()
            || !dwsKallinTookYalungurWife()
            || !dwsMuramuraDarandRainmaker()
            || !dwsMorkulLongGrassSpirit()
            || !dwsWalangdaMilkyWay()
            || !dwsDjanggawulSistersWithChild()
            || !dwsWondjinaHaloNoMouth()
            || !dwsMentalRequisiteUnprinted()
            || !dwsCrossReferencedSpells()
            || !dwsReverseGravityNatureTimeSpace()
            || !dwsLightSensesSummoning()
            || !dwsRopeTrickFlyProgression()
            || !dwsFirstLevelDefenceNoCounterpart()
            || !dwsSecondLevelTailFieldsUnavailable()
            || !dwsSpecializationDoctrine()
        )
            ++bad;
        // the mythos statline grid - eighteen entities down, the six statline
        // fields across, armor class, move, hit points, the magic level with
        // the See Below -99 sentinel, the fighter level and the psionic
        // class; the print catches pinned as scanned: the Wawalag fighter
        // line reads Champion 7th not Lord, the Wawalag psionic reads Nil
        // pinned 0, the Mimi armor class 8 is the lone positive AC, and
        // Wagtjadbulla and Tcabuinji share one statline (print 14-15 + 26,
        // PDF 16-17 + 28)
        int CMy[18][6] = {
            {-3,22,300,35,30,6},
            {-1,20,225,20,18,3},
            {0,18,170,-99,13,5},
            {0,18,180,-99,14,5},
            {0,18,130,-99,10,5},
            {0,18,190,-99,15,4},
            {0,17,160,15,13,5},
            {0,18,175,-99,17,4},
            {-1,18,240,25,20,6},
            {-2,19,230,-99,19,4},
            {-1,20,200,20,15,4},
            {-1,20,200,20,15,3},
            {-1,20,220,24,20,1},
            {-1,20,210,19,18,3},
            {0,18,210,-99,14,6},
            {1,15,175,18,15,5},
            {2,13,125,-99,7,0},
            {8,14,90,10,10,4},
            };
        int nMy[6] = {0,0,0,0,0,0};
        int eMy[6] = {0,0,0,8,0,0};
        for (int b = 0;
             b < dwsMythosStatlines();
             ++b) {
            int vals[6];
            vals[0] = dwsMythAc(b);
            vals[1] = dwsMythMove(b);
            vals[2] = dwsMythHp(b);
            vals[3] = dwsMythMagicLevel(b);
            vals[4] = dwsMythFighterLevel(b);
            vals[5] = dwsMythPsionicClass(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CMy[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nMy[c];
            }
        }
        for (int c = 0; c < 6; ++c)
            if (nMy[c] != eMy[c])
                ++bad;
        // the magic field grid - thirteen fields down, the printed spell
        // count and the prime requisite code across; the -99 sentinel pins
        // the four unprinted counts - Summoning, Senses, Illusion, Holy - and
        // the eight unprinted requisites, the Animation row carrying the
        // Animate header count pinned together (print 18-19, PDF 20-21)
        int CMf[13][2] = {
            {26,1},
            {-99,-99},
            {27,-99},
            {27,2},
            {20,3},
            {-99,-99},
            {25,4},
            {-99,-99},
            {23,-99},
            {18,5},
            {18,-99},
            {31,-99},
            {-99,-99},
            };
        int nMf[2] = {0,0};
        int eMf[2] = {4,8};
        for (int b = 0;
             b < dwsMagicFields();
             ++b) {
            int vals[2];
            vals[0] = dwsFieldSpells(b);
            vals[1] = dwsFieldRequisite(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CMf[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nMf[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nMf[c] != eMf[c])
                ++bad;
        // the wish census - four classes, the Class II level-5 MU ceiling,
        // the Class III level-4 cleric ceiling, the six lawful virtues and
        // six chaotic vices, the artifact shrink, the ten angry balrogs and
        // the three-wish ring (print 12-13, PDF 14-15)
    if (dwsWishClasses() != 4
            || dwsClassTwoMuLevel() != 5
            || dwsClassThreeClericLevel() != 4
            || dwsLawfulVirtues() != 6
            || dwsChaoticVices() != 6
            || dwsArtifactShrinkPerUse() != 1
            || dwsLenientBalrogs() != 10
            || dwsRingWishes() != 3
        )
            ++bad;
        // the wish alignment doctrine - the lawful, chaotic and neutral grant
        // matrices, the neutral versatility, the rarely-twisted neutral and
        // the twisted-only and fruit-cocktail oddball types (print 13, PDF
        // 15)
    if (dwsLawfulGrantsLawfulOrNeutral() != 1
            || dwsChaoticGrantsNeutralOrChaotic() != 1
            || dwsNeutralGrantsNeutralOnly() != 1
            || dwsNeutralFavoredVersatile() != 1
            || dwsNeutralRarelyTwisted() != 1
            || dwsTwistedOnlyTypePossible() != 1
            || dwsFruitCocktailTypePossible() != 1
        )
            ++bad;
        // the object-strength doctrine - never stronger than the creator,
        // power lost in transfer, weak WS in flimsy objects, strong in
        // durable, strongest in the immobile, the artifact exceptions (print
        // 12, PDF 14)
    if (dwsNeverStrongerThanCreator() != 1
            || dwsPowerLostInTransfer() != 1
            || dwsWeakWsInFlimsyObjects() != 1
            || dwsStrongWsInDurableObjects() != 1
            || dwsStrongestWsImmobile() != 1
            || dwsArtifactsMorePowerful() != 1
            || dwsArtifactSideEffects() != 1
        )
            ++bad;
        // the mythos census - twenty entities, eighteen statlines, two
        // prose-only, five fliers, the See Below sentinel, the Wondjina
        // ten-to-sixteen-foot band (print 14-15 + 26, PDF 16-17 + 28)
    if (dwsMythosEntities() != 20
            || dwsMythosStatlines() != 18
            || dwsMythosProseOnly() != 2
            || dwsMythosFlyingEntities() != 5
            || dwsSeeBelowSentinel() != -99
            || dwsWondjinaMinFeet() != 10
            || dwsWondjinaMaxFeet() != 16
        )
            ++bad;
        // the mythos weapons and statures - Tcabuinji nine feet and
        // Wagtjadbulla twelve, the 5-30 plus 2 and 10-60 plus 3 boomerangs,
        // the Mamarangan 10-60 plus 3 lightning-wand axe (print 15 + 26, PDF
        // 17 + 28)
    if (dwsTcabFeet() != 9
            || dwsWagtjadbullaFeet() != 12
            || dwsTcabBoomMin() != 5
            || dwsTcabBoomMax() != 30
            || dwsTcabBoomPlus() != 2
            || dwsDjunggunBoomMin() != 10
            || dwsDjunggunBoomMax() != 60
            || dwsDjunggunBoomPlus() != 3
            || dwsMamaranganAxeMin() != 10
            || dwsMamaranganAxeMax() != 60
            || dwsMamaranganAxePlus() != 3
            || dwsMamaranganAxeLightningWand() != 1
        )
            ++bad;
        // the mythos spell-list census - Gidja 8, Kallin-Kallin 6,
        // Waramurungundju 7, Mamarangan 5, Morkul 5, Mamandabari 5, Wawalag
        // 3, Ngunung 4 with the doubled Gate, Yalungur 2 (print 14-15 + 26,
        // PDF 16-17 + 28)
    if (dwsGidjaSpells() != 8
            || dwsKallinSpells() != 6
            || dwsWaramurungundjuSpells() != 7
            || dwsMamaranganSpells() != 5
            || dwsMorkulSpells() != 5
            || dwsMamandabariSpells() != 5
            || dwsWawalagSpells() != 3
            || dwsNgunungSpells() != 4
            || dwsYalungurSpells() != 2
            || dwsNgunungGateTwice() != 1
        )
            ++bad;
        // the field census - thirteen fields, the printed counts 26, 27, 27,
        // 20, 25, 23, 18, 18 and 31, the four unprinted counts and eight
        // unprinted requisites (print 18-19, PDF 20-21)
    if (dwsMagicFields() != 13
            || dwsControlSpells() != 26
            || dwsMentalSpells() != 27
            || dwsTimeSpaceSpells() != 27
            || dwsAttackSpells() != 20
            || dwsAnimateSpells() != 25
            || dwsKnowledgeSpells() != 23
            || dwsTransmutationSpells() != 18
            || dwsDefenceSpells() != 18
            || dwsNatureSpells() != 31
            || dwsUnprintedFieldCounts() != 4
            || dwsUnprintedRequisites() != 8
        )
            ++bad;
        // the requisite codes and doctrine - Charisma, Wisdom, Strength,
        // Dexterity and Intelligence for Control, Time/Space, Attack, Animate
        // and Transmutation, the Mental requisite unprinted, the
        // cross-references and the Rope Trick progression (print 18-19, PDF
        // 20-21)
    if (dwsReqCharisma() != 1
            || dwsReqWisdom() != 2
            || dwsReqStrength() != 3
            || dwsReqDexterity() != 4
            || dwsReqIntelligence() != 5
            || dwsMentalRequisiteUnprinted() != 1
            || dwsReverseGravityNatureTimeSpace() != 1
            || dwsLightSensesSummoning() != 1
            || dwsRopeTrickFlyProgression() != 1
        )
            ++bad;
        // the level-shape doctrine - the two counterpartless first-level
        // Defence spells, the five-spell second-level tail in
        // first-level-absent fields, the specialization argument (print 18,
        // PDF 20)
    if (dwsFirstLevelDefenceSpells() != 2
            || dwsSecondLevelTailNewFields() != 5
            || dwsFirstLevelDefenceNoCounterpart() != 1
            || dwsSecondLevelTailFieldsUnavailable() != 1
            || dwsSpecializationDoctrine() != 1
            || dwsCrossReferencedSpells() != 1
        )
            ++bad;
        // the mythos grid corners - the Daramulun -3/300/35 row, the Mimi
        // 8/90 positive-AC row, Yurlunggur 25, the Walangda psionic 1, the
        // Wawalag Champion 7 with the Nil psionic pinned 0 (print 14-15 + 26,
        // PDF 16-17 + 28)
    if (dwsMythAc(0) != -3
            || dwsMythAc(17) != 8
            || dwsMythHp(0) != 300
            || dwsMythHp(17) != 90
            || dwsMythMagicLevel(0) != 35
            || dwsMythMagicLevel(8) != 25
            || dwsMythPsionicClass(12) != 1
            || dwsMythFighterLevel(16) != 7
            || dwsMythPsionicClass(16) != 0
        )
            ++bad;
        // the See Below set - the eight spell-list gods Ngunung, Gidja,
        // Yalungur, Kallin-Kallin, Mamandabari, Mamarangan, Waramurungundju
        // and the Wawalag sisters carry the -99 sentinel, the Wizard-block
        // rows never do (print 14-15 + 26, PDF 16-17 + 28)
    if (dwsMythMagicLevel(2) != -99
            || dwsMythMagicLevel(3) != -99
            || dwsMythMagicLevel(4) != -99
            || dwsMythMagicLevel(5) != -99
            || dwsMythMagicLevel(7) != -99
            || dwsMythMagicLevel(9) != -99
            || dwsMythMagicLevel(14) != -99
            || dwsMythMagicLevel(16) != -99
            || dwsMythMagicLevel(6) == -99
            || dwsMythMagicLevel(17) == -99
        )
            ++bad;
        // the field count column - the nine printed counts and the four -99
        // sentinels at Summoning, Senses, Illusion and Holy (print 18-19, PDF
        // 20-21)
    if (dwsFieldSpells(0) != 26
            || dwsFieldSpells(2) != 27
            || dwsFieldSpells(3) != 27
            || dwsFieldSpells(4) != 20
            || dwsFieldSpells(6) != 25
            || dwsFieldSpells(8) != 23
            || dwsFieldSpells(9) != 18
            || dwsFieldSpells(10) != 18
            || dwsFieldSpells(11) != 31
            || dwsFieldSpells(1) != -99
            || dwsFieldSpells(5) != -99
            || dwsFieldSpells(7) != -99
            || dwsFieldSpells(12) != -99
        )
            ++bad;
        // the field requisite column - the five printed codes and the -99
        // sentinels at Mental, Knowledge, Defence and Nature (print 18-19,
        // PDF 20-21)
    if (dwsFieldRequisite(0) != 1
            || dwsFieldRequisite(3) != 2
            || dwsFieldRequisite(4) != 3
            || dwsFieldRequisite(6) != 4
            || dwsFieldRequisite(9) != 5
            || dwsFieldRequisite(2) != -99
            || dwsFieldRequisite(8) != -99
            || dwsFieldRequisite(10) != -99
            || dwsFieldRequisite(11) != -99
        )
            ++bad;
        printf("R937 issue-19 opener part one audit: bad %d\n", bad);
        if (bad) return 1;
    }
