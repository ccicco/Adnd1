    // ---- R312a: the flooded crossing seam audit ----
    // The DMG surface SWIMMING paragraph folds
    // (rules/swimcross.h, the grenade.h pattern)
    // against the R311 drown pin - verified by
    // audit_eval. The armor ids read the plain
    // items::ArmorId order (0 none through 9
    // plate); studded leather reads metal (the
    // studs - the JUDGMENT).
    {
        int bad = 0;
        static const int kSwimWalk[10] = {
             1,  1,  1,  0,  0,  0,  0,  0,  0,  0,
        };
        // the armor walk: none, padded and
        // leather swim, the metal armors bar
        for (int i = 0; i < 10; ++i)
            if (rules::swimArmorSwims(i) !=
                kSwimWalk[i]) ++bad;
        // the magic armor exception: the dog
        // paddle clears the gate
        if (rules::swimMagicArmorSwims() != 1 ||
            rules::swimCanSwim(3, 1) != 1 ||
            rules::swimCanSwim(9, 1) != 1) ++bad;
        // the plain armors read the ban
        if (rules::swimCanSwim(0, 0) != 1 ||
            rules::swimCanSwim(1, 0) != 1 ||
            rules::swimCanSwim(2, 0) != 1 ||
            rules::swimCanSwim(3, 0) != 0 ||
            rules::swimCanSwim(9, 0) != 0) ++bad;
        // the load beyond the armor: 1 pound =
        // 10 g.p., the worn armor not counted,
        // the negatives clamped
        if (rules::swimLoadBeyondArmorLbs(0, 0) != 0 ||
            rules::swimLoadBeyondArmorLbs(170, 150)
                != 2 ||
            rules::swimLoadBeyondArmorLbs(1550, 1500)
                != 5 ||
            rules::swimLoadBeyondArmorLbs(50, 100)
                != 0) ++bad;
        // the drown band rides the R311 pin: 5
        // percent bare, +2 per full 5 pounds
        if (rules::uwSurfaceDrownPct(0) != 5 ||
            rules::uwSurfaceDrownPct(2) != 5 ||
            rules::uwSurfaceDrownPct(5) != 7 ||
            rules::uwSurfaceDrownPct(25) != 15)
            ++bad;
        // the per-crossing roll judgment
        if (rules::swimDrownRollPerCrossing() != 1)
            ++bad;
        // the pool judgments: one per delve,
        // the sides 2-3
        if (rules::floodPerDelveCount() != 1 ||
            rules::floodSideMin() != 2 ||
            rules::floodSideMax() != 3 ||
            rules::floodSideMax() -
                rules::floodSideMin() + 1 != 2)
            ++bad;
        printf("R312a flooded crossing seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
