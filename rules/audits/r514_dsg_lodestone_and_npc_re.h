    // ---- R514 DSG lodestone and NPC reactions audit ----
    // The DSG lodestone pins the magnetic effects (magnetism on iron armor
    // and iron weapons, the innocuous iron-ore form that cannot impede
    // movement or combat, the deep concentrated ores of massively powerful
    // magnetic rock, the Wisdom Check detection at 120 feet manifested as a
    // slight tug on all iron possessions, the obvious stage within 90 feet
    // where the force is noticeable but cannot pull a character against his
    // will, the threatened stage within 30 feet where hanging iron is pulled
    // with a strap-snapping force, the Strength Check for hand-held iron and
    // the additional check for iron armor with the 10-foot pull on a failure,
    // the successful check holding item or ground without repeats unless
    // closer, the repetition each 10 feet of approach, the -2 Strength at 20
    // feet and -4 at 10 feet, the -6 removal check with the forever-unable
    // failure, and the loss of all powers when removed from the natural
    // setting) and the NPC reactions (the special incentives for a prolonged
    // expedition, the Loyalty Check on being informed per DMG pages 36-37,
    // the week-or-more trigger with the dwarf, gnome and drow exemption, the
    // -5% per planned week, the -10% deception or too-late modifier, the
    // -20%-month desert example, the separate roll per NPC, the avoidance
    // short of risking life on a failure, the compelled NPC becoming
    // unsteady, the unsettled mind slipping over long periods away from
    // sunlight and fresh air, the first-week ill effects with the 10% morale
    // penalty and the nervous jumpiness, the weekly Loyalty rechecks, the
    // completely irrational break rolling d100 on Table 20, the four reaction
    // bands, the effect lasting until slain or returned to the surface, and
    // the 1d6 above-ground weeks with the recovery Wisdom Check and the
    // permanent affliction on a failure).
    {
        using namespace rules;
        int bad = 0;
    if (dnzWisCheckDetectionFt() != 120
            || dnzObviousWithinFt() != 90
            || dnzThreatenedWithinFt() != 30
            || dnzArmorPullFt() != 10
            || dnzRepeatEveryFt() != 10
            || dnzStrPenalty20Ft() != 2
            || dnzStrPenalty10Ft() != 4
            || dnzRemovalStrPenalty() != 6
            || dnzWeeklyLoyaltyPenaltyPct() != 5
            || dnzDeceptionPenaltyPct() != 10
            || dnzExampleMonthPenaltyPct() != 20
            || dnzMoralePenaltyPct() != 10
            || dnzRecoveryWeeksDice() != 1
            || dnzRecoveryWeeksSides() != 6
            || dnzT20RowCount() != 4
            || !dnzMagnetismAffectsIronArmor()
            || !dnzInnocuousFormInIronOre()
            || !dnzInnocuousCannotImpede()
            || !dnzDeepOresPowerful()
            || !dnzWisCheckSlightTug()
            || !dnzObviousNotPullingWill()
            || !dnzHangingIronSnapsStraps()
            || !dnzStrCheckHandheldIron()
            || !dnzIronArmorExtraStrCheck()
            || !dnzSuccessHoldsNoRepeat()
            || !dnzRemovalFailForever()
            || !dnzLosePowersOffSite()
            || !dnzNpcsNeedSpecialIncentives()
            || !dnzLoyaltyCheckOnInformed()
            || !dnzCheckWeekOrMore()
            || !dnzNoCheckDwarfGnomeDrow()
            || !dnzSeparateRollPerNpc()
            || !dnzFailureAvoidsMission()
            || !dnzCompelledBecomesUnsteady()
            || !dnzUnsteadyMindSlips()
            || !dnzIllEffectsAfterFirstWeek()
            || !dnzNervousAndJumpy()
            || !dnzLoyaltyCheckEachAddedWeek()
            || !dnzIrrationalOnFail()
            || !dnzEffectUntilSlainOrSurface()
            || !dnzRecoveryWisCheck()
            || !dnzPermanentOnFail()
        )
            ++bad;
        // the Table 20 unsteady NPC reactions grid
        int C20[4][3] = {
            {0,1,20},
            {1,21,55},
            {2,56,85},
            {3,86,100},
            };
        for (int b = 0;
             b < dnzT20RowCount();
             ++b) {
            int vals[3];
            vals[0] = dnzT20Key(b);
            vals[1] = dnzT20Lo(b);
            vals[2] = dnzT20Hi(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != C20[b][c])
                    ++bad;
            }
        }
        // the lodestone distance ladder: the Wis Check at 120 ft, obvious
        // within 90 ft, threatened within 30 ft, the armor pull of 10 ft, and
        // the checks repeated each 10 ft of approach.
    if (dnzWisCheckDetectionFt() != 120
            || dnzObviousWithinFt() != 90
            || dnzThreatenedWithinFt() != 30
            || dnzArmorPullFt() != 10
            || dnzRepeatEveryFt() != 10
        )
            ++bad;
        // the Strength penalties (as magnitudes): -2 at 20 ft, -4 at 10 ft,
        // and the -6 removal modifier for iron stuck to the stone.
    if (dnzStrPenalty20Ft() != 2
            || dnzStrPenalty10Ft() != 4
            || dnzRemovalStrPenalty() != 6
        )
            ++bad;
        // the lodestone opener: magnetism on iron armor and weapons, the
        // innocuous iron-ore form that cannot impede, and the deep
        // concentrated ores forming powerful magnetic rock.
    if (dnzMagnetismAffectsIronArmor() != 1
            || dnzInnocuousFormInIronOre() != 1
            || dnzInnocuousCannotImpede() != 1
            || dnzDeepOresPowerful() != 1
        )
            ++bad;
        // the stage readings: the slight tug at detection, the
        // noticeable-but-not-pulling force at 90 ft, the strap-snapping
        // threat at 30 ft, the hand-held and armor Strength Checks, and the
        // no-repeat hold.
    if (dnzWisCheckSlightTug() != 1
            || dnzObviousNotPullingWill() != 1
            || dnzHangingIronSnapsStraps() != 1
            || dnzStrCheckHandheldIron() != 1
            || dnzIronArmorExtraStrCheck() != 1
            || dnzSuccessHoldsNoRepeat() != 1
        )
            ++bad;
        // the removal tail: a failed -6 removal means the object is forever
        // stuck, and a lodestone removed from its natural setting loses all
        // powers.
    if (dnzRemovalFailForever() != 1
            || dnzLosePowersOffSite() != 1
        )
            ++bad;
        // the NPC opener: special incentives for a long expedition, the
        // Loyalty Check on being informed (the DMG 36-37 seam), the
        // week-or-more trigger, and the dwarf/gnome/drow exemption.
    if (dnzNpcsNeedSpecialIncentives() != 1
            || dnzLoyaltyCheckOnInformed() != 1
            || dnzCheckWeekOrMore() != 1
            || dnzNoCheckDwarfGnomeDrow() != 1
        )
            ++bad;
        // the Loyalty modifiers (as magnitudes): -5% per planned week, the
        // -10% deception modifier, and the -20%-for-the-month worked example
        // (the djvu garble -209/ settled by the Capture -20% read).
    if (dnzWeeklyLoyaltyPenaltyPct() != 5
            || dnzDeceptionPenaltyPct() != 10
            || dnzExampleMonthPenaltyPct() != 20
        )
            ++bad;
        // the check outcomes: a separate roll per NPC, the failure meaning
        // avoidance short of risking life, and the compelled NPC becoming
        // unsteady.
    if (dnzSeparateRollPerNpc() != 1
            || dnzFailureAvoidsMission() != 1
            || dnzCompelledBecomesUnsteady() != 1
        )
            ++bad;
        // the unsteady descent: the slipping mind after the first week, the
        // 10% morale penalty, the nervous jumpiness, the weekly rechecks, and
        // the irrational break on a failure.
    if (dnzUnsteadyMindSlips() != 1
            || dnzIllEffectsAfterFirstWeek() != 1
            || dnzMoralePenaltyPct() != 10
            || dnzNervousAndJumpy() != 1
            || dnzLoyaltyCheckEachAddedWeek() != 1
            || dnzIrrationalOnFail() != 1
        )
            ++bad;
        // the Table 20 first bands: 01-20 runs screaming to the limits of his
        // Endurance, 21-55 attacks a nearby PC.
    if (dnzT20Key(0) != 0
            || dnzT20Lo(0) != 1
            || dnzT20Hi(0) != 20
            || dnzT20Key(1) != 1
            || dnzT20Lo(1) != 21
            || dnzT20Hi(1) != 55
        )
            ++bad;
        // the Table 20 tail bands: 56-85 sneaks away quietly as soon as
        // possible, 86-00 (pinned 86-100) freezes in place (the djvu garble
        // ih place = in place).
    if (dnzT20Lo(2) != 56
            || dnzT20Hi(2) != 85
            || dnzT20Key(3) != 3
            || dnzT20Lo(3) != 86
            || dnzT20Hi(3) != 100
        )
            ++bad;
        // the recovery tail: the effect lasts until slain or returned to the
        // surface, the 1d6 above-ground weeks, the Wisdom Check, and the
        // permanent affliction on a failure.
    if (dnzEffectUntilSlainOrSurface() != 1
            || dnzRecoveryWeeksDice() != 1
            || dnzRecoveryWeeksSides() != 6
            || dnzRecoveryWisCheck() != 1
            || dnzPermanentOnFail() != 1
        )
            ++bad;
        // the Table 20 carries four reaction bands.
    if (dnzT20RowCount() != 4
        )
            ++bad;
        // the Table 20 grid cell-for-cell, rows 0-2: the screaming run, the
        // attack, and the sneak-away bands.
    if (dnzT20Key(0) != 0
            || dnzT20Lo(0) != 1
            || dnzT20Hi(0) != 20
            || dnzT20Key(1) != 1
            || dnzT20Lo(1) != 21
            || dnzT20Hi(1) != 55
            || dnzT20Key(2) != 2
            || dnzT20Lo(2) != 56
            || dnzT20Hi(2) != 85
        )
            ++bad;
        // the Table 20 grid cell-for-cell, row 3: the freeze-in-place band
        // 86-00 (pinned 86-100).
    if (dnzT20Key(3) != 3
            || dnzT20Lo(3) != 86
            || dnzT20Hi(3) != 100
        )
            ++bad;
        printf("R514 DSG lodestone and NPC reactions audit: bad %d\n", bad);
        if (bad) return 1;
    }
