    // ---- R408: the UA p. 26 armor
    // class table pin audit ----
    // The composite ladder pins
    // directly: the 11 rows AC 10 to
    // 0, the printed armor sets, the
    // 28 composites; the type rows
    // cross-check the R191 ladder
    // live, the shield composites
    // read base minus the step, the
    // bronze read cross-checks the
    // R371 pin, and the R392
    // equipment costs re-verify
    // against the independent scan;
    // the two stale boxes close;
    // census 334 -> 335.
    {
        using namespace rules;
        int bad = 0;
        // ---- the ladder ----
        if (uacrRowCount() != 11) ++bad;
        if (uacrRowAc(0) != 10
                || uacrRowAc(5) != 5
                || uacrRowAc(10) != 0)
            ++bad;
        if (strcmp(uacrRowSet(0), "none") != 0)
            ++bad;
        if (strcmp(uacrRowSet(1),
                   "shield only") != 0)
            ++bad;
        if (strcmp(uacrRowSet(10),
                   "full plate armor + shield")
                != 0)
            ++bad;
        if (uacrRowMemberCount(0) != 1
                || uacrRowMemberCount(3) != 4
                || uacrRowMemberCount(6) != 5
                || uacrRowMemberCount(10) != 1)
            ++bad;
        // the composites add up
        if (uacrRowMemberCount(0)
                + uacrRowMemberCount(1)
                + uacrRowMemberCount(2)
                + uacrRowMemberCount(3)
                + uacrRowMemberCount(4)
                + uacrRowMemberCount(5)
                + uacrRowMemberCount(6)
                + uacrRowMemberCount(7)
                + uacrRowMemberCount(8)
                + uacrRowMemberCount(9)
                + uacrRowMemberCount(10)
                != uacrCompositeCount()) ++bad;
        if (uacrCompositeCount() != 28) ++bad;
        if (!uacrRowHasShieldMember(3)
                || !uacrRowHasShieldMember(10)
                || uacrRowHasShieldMember(0)
                || uacrRowHasShieldMember(2))
            ++bad;
        // ---- the R191 cross-checks ----
        // the type rows read the ladder
        if (uacrRowAc(2) != armorRatingAc(3))
            ++bad;
        if (uacrRowAc(4) != armorRatingAc(6))
            ++bad;
        if (uacrRowAc(5) != armorRatingAc(7))
            ++bad;
        if (uacrRowAc(7) != armorRatingAc(10))
            ++bad;
        // the shield composites read base
        // minus the step: leather 8 with
        // shield 7, scale 6 with shield 5,
        // full plate 1 with shield 0
        if (uacrRowAc(2)
                - armorRatingShieldStep()
                != uacrRowAc(3)) ++bad;
        if (uacrRowAc(4)
                - armorRatingShieldStep()
                != uacrRowAc(5)) ++bad;
        if (uacrRowAc(8)
                - armorRatingShieldStep()
                != uacrRowAc(9)) ++bad;
        if (uacrRowAc(9)
                - armorRatingShieldStep()
                != uacrRowAc(10)) ++bad;
        // ---- the R371 bronze read ----
        if (uaarmBronzeAc() != 4) ++bad;
        if (uaarmBronzeAc()
                != armorRatingAc(7) - 1)
            ++bad;
        // the bronze plate mail composite
        // reads row 4, its shield row 3
        if (uaarmBronzeAc() != uacrRowAc(6))
            ++bad;
        if (uaarmBronzeAc()
                - armorRatingShieldStep()
                != uacrRowAc(7)) ++bad;
        // ---- the R392 equipment costs ----
        // the scan re-verifies the pins:
        // bronze 100, full 4000, field
        // 2000, the buckler 5
        if (uaecArmorCount() != 4) ++bad;
        if (uaecArmorCost(0) != 100
                || uaecArmorCost(1) != 4000
                || uaecArmorCost(2) != 2000
                || uaecArmorCost(3) != 5)
            ++bad;
        if (uaecArmsCount() != 19) ++bad;
        if (uaecArmsCost(0) != 2
                || uaecArmsCost(5) != 300
                || uaecArmsCost(6) != 100)
            ++bad;
        if (uaecArmsPriceIsSilver(11)
                != true) ++bad;
        printf("R408 UA armor class table pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
