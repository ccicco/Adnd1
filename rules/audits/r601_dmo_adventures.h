    // ---- R601 DMO adventures audit ----
    // THE ADVENTURE DOCTRINES of DMO Chapter 2 (pp. 30-45), the doctrine half
    // of the chapter: the adventure-construction rules (show don't tell,
    // prepare don't over-plan, don't force the action, enhance don't inflate,
    // gifts vs. rewards, multiple threats, don't kill - scare, proactive and
    // responsive foes, failures not catastrophic, the plot rules), the
    // encounter taxonomy (the twelve types with their doctrines, the five
    // linking methods, the five combat-plan elements), and the world-hopping
    // doctrine (the three world types, the 18 inner and 17 outer planes, the
    // one-Prime correction, the four aspects on the 2-20 scale).
    {
        using namespace rules;
        int bad = 0;
    if (dekEncounterTypeCount() != 12
            || dekLinkingMethodCount() != 5
            || dekCombatPlanElementCount() != 5
            || dekSecretDoorSearchTurns() != 10
            || dekPolymorphSelfTurnsPerLevel() != 2
            || dekPolymorphLichTurns() != 60
            || dekWorldTypeCount() != 3
            || dekInnerPlaneCount() != 18
            || dekOuterPlaneCount() != 17
            || dekWorldAspectCount() != 4
            || dekWorldAspectMin() != 2
            || dekWorldAspectMax() != 20
            || dekWorldAspectTypicalLow() != 10
            || dekWorldAspectTypicalHigh() != 12
            || !dekGoodAdventureDoctrine()
            || !dekShowDontTell()
            || !dekPrepareDontOverplan()
            || !dekDontForceAction()
            || !dekEncounterVariety()
            || !dekCombatVsCreativity()
            || !dekEnhanceDontInflate()
            || !dekGiftsVsRewards()
            || !dekMultipleThreats()
            || !dekDontKillScare()
            || !dekCharacterKnowledgeDoctrine()
            || !dekRulesConsistency()
            || !dekProactiveFoes()
            || !dekResponsiveFoes()
            || !dekFailuresNotCatastrophic()
            || !dekPlotDoctrine()
            || !dekEncounterTaxonomyDoctrine()
            || !dekLinkingDoctrine()
            || !dekCombatPlanDoctrine()
            || !dekWorldHoppingDoctrine()
        )
            ++bad;
        // the dekEncounterTypeCount pin
    if (dekEncounterTypeCount() != 12
        )
            ++bad;
        // the dekLinkingMethodCount pin
    if (dekLinkingMethodCount() != 5
        )
            ++bad;
        // the dekCombatPlanElementCount pin
    if (dekCombatPlanElementCount() != 5
        )
            ++bad;
        // the dekSecretDoorSearchTurns pin
    if (dekSecretDoorSearchTurns() != 10
        )
            ++bad;
        // the dekPolymorphSelfTurnsPerLevel pin
    if (dekPolymorphSelfTurnsPerLevel() != 2
        )
            ++bad;
        // the dekPolymorphLichTurns pin
    if (dekPolymorphLichTurns() != 60
        )
            ++bad;
        // the dekWorldTypeCount pin
    if (dekWorldTypeCount() != 3
        )
            ++bad;
        // the dekInnerPlaneCount pin
    if (dekInnerPlaneCount() != 18
        )
            ++bad;
        // the dekOuterPlaneCount pin
    if (dekOuterPlaneCount() != 17
        )
            ++bad;
        // the dekWorldAspectCount pin
    if (dekWorldAspectCount() != 4
        )
            ++bad;
        // the dekWorldAspectMin pin
    if (dekWorldAspectMin() != 2
        )
            ++bad;
        // the dekWorldAspectMax pin
    if (dekWorldAspectMax() != 20
        )
            ++bad;
        // the dekWorldAspectTypicalLow pin
    if (dekWorldAspectTypicalLow() != 10
        )
            ++bad;
        // the dekWorldAspectTypicalHigh pin
    if (dekWorldAspectTypicalHigh() != 12
        )
            ++bad;
        // the dekGoodAdventureDoctrine pin
    if (dekGoodAdventureDoctrine() != 1
        )
            ++bad;
        // the dekShowDontTell pin
    if (dekShowDontTell() != 1
        )
            ++bad;
        // the dekPrepareDontOverplan pin
    if (dekPrepareDontOverplan() != 1
        )
            ++bad;
        // the dekDontForceAction pin
    if (dekDontForceAction() != 1
        )
            ++bad;
        // the dekEncounterVariety pin
    if (dekEncounterVariety() != 1
        )
            ++bad;
        // the dekCombatVsCreativity pin
    if (dekCombatVsCreativity() != 1
        )
            ++bad;
        // the dekEnhanceDontInflate pin
    if (dekEnhanceDontInflate() != 1
        )
            ++bad;
        // the dekGiftsVsRewards pin
    if (dekGiftsVsRewards() != 1
        )
            ++bad;
        // the dekMultipleThreats pin
    if (dekMultipleThreats() != 1
        )
            ++bad;
        // the dekDontKillScare pin
    if (dekDontKillScare() != 1
        )
            ++bad;
        // the dekCharacterKnowledgeDoctrine pin
    if (dekCharacterKnowledgeDoctrine() != 1
        )
            ++bad;
        // the dekRulesConsistency pin
    if (dekRulesConsistency() != 1
        )
            ++bad;
        // the dekProactiveFoes pin
    if (dekProactiveFoes() != 1
        )
            ++bad;
        // the dekResponsiveFoes pin
    if (dekResponsiveFoes() != 1
        )
            ++bad;
        // the dekFailuresNotCatastrophic pin
    if (dekFailuresNotCatastrophic() != 1
        )
            ++bad;
        // the dekPlotDoctrine pin
    if (dekPlotDoctrine() != 1
        )
            ++bad;
        // the dekEncounterTaxonomyDoctrine pin
    if (dekEncounterTaxonomyDoctrine() != 1
        )
            ++bad;
        // the dekLinkingDoctrine pin
    if (dekLinkingDoctrine() != 1
        )
            ++bad;
        // the dekCombatPlanDoctrine pin
    if (dekCombatPlanDoctrine() != 1
        )
            ++bad;
        // the dekWorldHoppingDoctrine pin
    if (dekWorldHoppingDoctrine() != 1
        )
            ++bad;
        printf("R601 DMO adventures audit: bad %d\n", bad);
        if (bad) return 1;
    }
