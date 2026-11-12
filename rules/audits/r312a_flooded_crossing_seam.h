    // ---- R312a: the flooded crossing seam audit ----
    // The DMG surface SWIMMING paragraph folds
    // (rules/dmg/swimcross.h, the grenade.h pattern)
    // against the R311 drown pin - verified by
    // audit_eval. The armor ids read the plain
    // items::ArmorId order (0 none through 9
    // plate); studded leather reads metal (the
    // studs - the JUDGMENT).
    {
        Swimcross swimcross;
        int bad = 0;
        static const int kSwimWalk[10] = {
             1,  1,  1,  0,  0,  0,  0,  0,  0,  0,
        };
        // the armor walk: none, padded and
        // leather swim, the metal armors bar
        for (int i = 0; i < 10; ++i)
            if (swimcross.swimArmorSwims(i) !=
                kSwimWalk[i]) ++bad;
        // the magic armor exception: the dog
        // paddle clears the gate
        if (swimcross.swimMagicArmorSwims() != 1 ||
            swimcross.swimCanSwim(3, 1) != 1 ||
            swimcross.swimCanSwim(9, 1) != 1) ++bad;
        // the plain armors read the ban
        if (swimcross.swimCanSwim(0, 0) != 1 ||
            swimcross.swimCanSwim(1, 0) != 1 ||
            swimcross.swimCanSwim(2, 0) != 1 ||
            swimcross.swimCanSwim(3, 0) != 0 ||
            swimcross.swimCanSwim(9, 0) != 0) ++bad;
        // the load beyond the armor: 1 pound =
        // 10 g.p., the worn armor not counted,
        // the negatives clamped
        if (swimcross.swimLoadBeyondArmorLbs(0, 0) != 0 ||
            swimcross.swimLoadBeyondArmorLbs(170, 150)
                != 2 ||
            swimcross.swimLoadBeyondArmorLbs(1550, 1500)
                != 5 ||
            swimcross.swimLoadBeyondArmorLbs(50, 100)
                != 0) ++bad;
        // the drown band rides the R311 pin: 5
        // percent bare, +2 per full 5 pounds
        if (rules::uwSurfaceDrownPct(0) != 5 ||
            rules::uwSurfaceDrownPct(2) != 5 ||
            rules::uwSurfaceDrownPct(5) != 7 ||
            rules::uwSurfaceDrownPct(25) != 15)
            ++bad;
        // the per-crossing roll judgment
        if (swimcross.swimDrownRollPerCrossing() != 1)
            ++bad;
        // the pool judgments: one per delve,
        // the sides 2-3
        if (swimcross.floodPerDelveCount() != 1 ||
            swimcross.floodSideMin() != 2 ||
            swimcross.floodSideMax() != 3 ||
            swimcross.floodSideMax() -
                swimcross.floodSideMin() + 1 != 2)
            ++bad;
        printf("R312a flooded crossing seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
