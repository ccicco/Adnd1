    // ---- R630 OA family structures audit ----
    // OA round seventeen (capture pp. 62-64): the family structure and the
    // additional structures - the marriages, adoptions, polygamy,
    // interrelated characters and the deaths ladder
    {
        using namespace rules;
        int bad = 0;
    if (dgqChildrenDiceSides() != 8
            || dgqChildrenDiceMod() != -2
            || dgqMarriageDiceSides() != 6
            || dgqMarriageRollMax() != 5
            || dgqMarriageBonusPct() != 10
            || dgqAdoptChancePct() != 5
            || dgqAdoptDiceSides() != 6
            || dgqAdoptOrphanMax() != 2
            || dgqAdoptBonusPct() != 10
            || dgqDeathCheckPerYear() != 1
            || dgqDeathHeadPct() != 10
            || dgqDeathFatherPct() != 7
            || dgqDeathSiblingPct() != 5
            || dgqDeathFirstbornPct() != 75
            || !dgqChartDirectBranchOnly()
            || !dgqLineageDieClosestNotLess()
            || !dgqLineageRerollOverflow()
            || !dgqComplicationsOptional()
            || !dgqPcFemalesNeverRequired()
            || !dgqMarriageUsuallyOutsideClan()
            || !dgqMarriageEqualRank()
            || !dgqAdoptOrphansRelatedOnlyClan()
            || !dgqAdoptTwoClansWhenAlive()
            || !dgqAdoptOftenPolitical()
            || !dgqPolygamyLegal()
            || !dgqPolygamyMostMonogamous()
            || !dgqPolygamyGrandfatherFatherOnly()
            || !dgqFirstWifeChildrenInherit()
            || !dgqInheritanceFirstSonFirstWife()
            || !dgqFurtherGenerationsNoModifier()
            || !dgqInterrelatedDmApproval()
            || !dgqInterrelatedSameRace()
            || !dgqInterrelatedSameBirthRank()
            || !dgqInterrelatedTwinsOnly()
            || !dgqInterrelatedSharedAncestry()
            || !dgqPcReentryFirstLevel()
            || !dgqHeadTitleSuccession()
        )
            ++bad;
        // the dgqChildrenDiceSides pin
    if (dgqChildrenDiceSides() != 8
        )
            ++bad;
        // the dgqChildrenDiceMod pin
    if (dgqChildrenDiceMod() != -2
        )
            ++bad;
        // the dgqMarriageDiceSides pin
    if (dgqMarriageDiceSides() != 6
        )
            ++bad;
        // the dgqMarriageRollMax pin
    if (dgqMarriageRollMax() != 5
        )
            ++bad;
        // the dgqMarriageBonusPct pin
    if (dgqMarriageBonusPct() != 10
        )
            ++bad;
        // the dgqAdoptChancePct pin
    if (dgqAdoptChancePct() != 5
        )
            ++bad;
        // the dgqAdoptDiceSides pin
    if (dgqAdoptDiceSides() != 6
        )
            ++bad;
        // the dgqAdoptOrphanMax pin
    if (dgqAdoptOrphanMax() != 2
        )
            ++bad;
        // the dgqAdoptBonusPct pin
    if (dgqAdoptBonusPct() != 10
        )
            ++bad;
        // the dgqDeathCheckPerYear pin
    if (dgqDeathCheckPerYear() != 1
        )
            ++bad;
        // the dgqDeathHeadPct pin
    if (dgqDeathHeadPct() != 10
        )
            ++bad;
        // the dgqDeathFatherPct pin
    if (dgqDeathFatherPct() != 7
        )
            ++bad;
        // the dgqDeathSiblingPct pin
    if (dgqDeathSiblingPct() != 5
        )
            ++bad;
        // the dgqDeathFirstbornPct pin
    if (dgqDeathFirstbornPct() != 75
        )
            ++bad;
        // the dgqChartDirectBranchOnly pin
    if (dgqChartDirectBranchOnly() != 1
        )
            ++bad;
        // the dgqLineageDieClosestNotLess pin
    if (dgqLineageDieClosestNotLess() != 1
        )
            ++bad;
        // the dgqLineageRerollOverflow pin
    if (dgqLineageRerollOverflow() != 1
        )
            ++bad;
        // the dgqComplicationsOptional pin
    if (dgqComplicationsOptional() != 1
        )
            ++bad;
        // the dgqPcFemalesNeverRequired pin
    if (dgqPcFemalesNeverRequired() != 1
        )
            ++bad;
        // the dgqMarriageUsuallyOutsideClan pin
    if (dgqMarriageUsuallyOutsideClan() != 1
        )
            ++bad;
        // the dgqMarriageEqualRank pin
    if (dgqMarriageEqualRank() != 1
        )
            ++bad;
        // the dgqAdoptOrphansRelatedOnlyClan pin
    if (dgqAdoptOrphansRelatedOnlyClan() != 1
        )
            ++bad;
        // the dgqAdoptTwoClansWhenAlive pin
    if (dgqAdoptTwoClansWhenAlive() != 1
        )
            ++bad;
        // the dgqAdoptOftenPolitical pin
    if (dgqAdoptOftenPolitical() != 1
        )
            ++bad;
        // the dgqPolygamyLegal pin
    if (dgqPolygamyLegal() != 1
        )
            ++bad;
        // the dgqPolygamyMostMonogamous pin
    if (dgqPolygamyMostMonogamous() != 1
        )
            ++bad;
        // the dgqPolygamyGrandfatherFatherOnly pin
    if (dgqPolygamyGrandfatherFatherOnly() != 1
        )
            ++bad;
        // the dgqFirstWifeChildrenInherit pin
    if (dgqFirstWifeChildrenInherit() != 1
        )
            ++bad;
        // the dgqInheritanceFirstSonFirstWife pin
    if (dgqInheritanceFirstSonFirstWife() != 1
        )
            ++bad;
        // the dgqFurtherGenerationsNoModifier pin
    if (dgqFurtherGenerationsNoModifier() != 1
        )
            ++bad;
        // the dgqInterrelatedDmApproval pin
    if (dgqInterrelatedDmApproval() != 1
        )
            ++bad;
        // the dgqInterrelatedSameRace pin
    if (dgqInterrelatedSameRace() != 1
        )
            ++bad;
        // the dgqInterrelatedSameBirthRank pin
    if (dgqInterrelatedSameBirthRank() != 1
        )
            ++bad;
        // the dgqInterrelatedTwinsOnly pin
    if (dgqInterrelatedTwinsOnly() != 1
        )
            ++bad;
        // the dgqInterrelatedSharedAncestry pin
    if (dgqInterrelatedSharedAncestry() != 1
        )
            ++bad;
        // the dgqPcReentryFirstLevel pin
    if (dgqPcReentryFirstLevel() != 1
        )
            ++bad;
        // the dgqHeadTitleSuccession pin
    if (dgqHeadTitleSuccession() != 1
        )
            ++bad;
        // the children doctrine - 1d8 minus 2, the negatives and zero mean no
        // offspring (capture pp. 62-64)
    if (dgqChildrenDiceSides() != 8
            || dgqChildrenDiceMod() != -2
            || dgqChildrenDiceSides() + dgqChildrenDiceMod() != 6
        )
            ++bad;
        // the deaths ladder - 10, 7 and 5 percent by row (capture pp. 62-64)
    if (dgqDeathHeadPct() != 10
            || dgqDeathFatherPct() != 7
            || dgqDeathSiblingPct() != 5
        )
            ++bad;
        // the death read - once per game year, the 75 percent firstborn pass
        // (capture pp. 62-64)
    if (dgqDeathCheckPerYear() != 1
            || dgqDeathFirstbornPct() != 75
        )
            ++bad;
        // the marriage read - 1-5 on 1d6 with the +10 bonus (capture pp.
        // 62-64)
    if (dgqMarriageDiceSides() != 6
            || dgqMarriageRollMax() != 5
            || dgqMarriageBonusPct() != 10
        )
            ++bad;
        // the adoption read - the 5 percent entry, the 1-2 orphan check, the
        // +10 bonus (capture pp. 62-64)
    if (dgqAdoptChancePct() != 5
            || dgqAdoptDiceSides() != 6
            || dgqAdoptOrphanMax() != 2
            || dgqAdoptBonusPct() != 10
        )
            ++bad;
        printf("R630 OA family structures audit: bad %d\n", bad);
        if (bad) return 1;
    }
