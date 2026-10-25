    // ---- R313a: the underwater fight seam audit ----
    // The DMG UNDERWATER ADVENTURES movement and
    // combat pins folded for the crossing (rules/
    // uwfight.h, the grenade.h pattern): the
    // strength-fed equipment cap (the R311 20-lb
    // pin, +1 lb per full 100 g.p. of the R153
    // weight allowance), the thrusting-only
    // strike and the missile bar - verified by
    // audit_eval. The wclass reads the plain
    // rules::WeaponClass ints (0 bludgeoning, 1
    // piercing, 2 slashing).
    {
        int bad = 0;
        // the crossing cap: 20 lbs plus the strength
        // allowance (C truncation; the negatives
        // move the cap down)
        if (rules::uwCrossCapLbs(0) != 20 ||
            rules::uwCrossCapLbs(-350) != 17 ||
            rules::uwCrossCapLbs(250) != 22 ||
            rules::uwCrossCapLbs(5000) != 70) ++bad;
        // the cap cross-call identity: the seam fold
        // equals the R311 pin everywhere probed
        for (int i = 0; i <= 100; ++i)
            if (rules::uwCrossCapLbs(i * 50) !=
                rules::uwSwimEncumbranceCapLbs(
                    i * 50)) ++bad;
        // the load gate: the load beyond the armor
        // bars past the cap, the cap itself passes
        if (rules::uwCrossLoadBars(17, 17) != 0 ||
            rules::uwCrossLoadBars(18, 17) != 1 ||
            rules::uwCrossLoadBars(20, 17) != 1 ||
            rules::uwCrossLoadBars(23, 27) != 0) ++bad;
        // the thrusting-only strike: the bludgeon and
        // the slash fail, the thrust connects
        if (rules::uwStrikeAllowed(0) != 0 ||
            rules::uwStrikeAllowed(1) != 1 ||
            rules::uwStrikeAllowed(2) != 0) ++bad;
        // the missile bar (the special crossbow is
        // unpinned data - the bar is total)
        if (rules::uwMissileBarred() != 1) ++bad;
        printf("R313a underwater fight seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
