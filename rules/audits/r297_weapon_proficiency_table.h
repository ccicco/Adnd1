    // ---- R297: the weapon proficiency table pins audit ----
    // The PHB WEAPONS section Weapon Proficiency
    // Table: the ten printed class rows (the
    // initial slots, the non-proficiency penalty,
    // the added-slot cadence), the base-class and
    // subclass mappings, the slot-at-level walker
    // (the printed cleric example), the clamps and
    // the penalty seam wpfNonProfHitAdj (the
    // Actor::hitAdjustment fold - ai/actor.cpp;
    // the empty-list convention and the monk open
    // hand stay engine pins, recorded in the
    // header).
    {
        int bad = 0;
        // the row count and the three printed columns
        if (rules::wpfRowCount() != 10) ++bad;
        static const int kSlots[10] = {
            2, 2, 4, 3, 3, 1, 1, 2, 3, 1,
        };
        static const int kPen[10] = {
            3, 4, 2, 2, 2, 5, 5, 3, 2, 3,
        };
        static const int kCad[10] = {
            4, 5, 3, 3, 3, 6, 6, 4, 4, 2,
        };
        for (int i = 0; i < 10; ++i)
            if (rules::wpfInitialSlots(i) != kSlots[i] ||
                rules::wpfNonProfPenalty(i) != kPen[i] ||
                rules::wpfAddedCadence(i) != kCad[i]) ++bad;
        // the clamps (the rows clamp 0..9, the
        // level at 1)
        if (rules::wpfInitialSlots(-5) != 2 ||
            rules::wpfInitialSlots(99) != 1 ||
            rules::wpfNonProfPenalty(-1) != 3 ||
            rules::wpfNonProfPenalty(12) != 3 ||
            rules::wpfAddedCadence(-3) != 4 ||
            rules::wpfAddedCadence(77) != 2 ||
            rules::wpfSlotsAt(0, 0) != 2 ||
            rules::wpfSlotsAt(0, -7) != 2) ++bad;
        // the printed cleric example: two weapons
        // at 1st, three at 5th, four at 9th, five
        // at 13th (the added-slot notes)
        if (rules::wpfSlotsAt(0, 1) != 2 ||
            rules::wpfSlotsAt(0, 5) != 3 ||
            rules::wpfSlotsAt(0, 9) != 4 ||
            rules::wpfSlotsAt(0, 13) != 5) ++bad;
        // the per-class cadence spot checks
        // (fighter 1 per 3, druid 1 per 5,
        // magic-user 1 per 6, assassin 1 per 4,
        // monk 1 per 2)
        if (rules::wpfSlotsAt(2, 1) != 4 ||
            rules::wpfSlotsAt(2, 4) != 5 ||
            rules::wpfSlotsAt(2, 7) != 6 ||
            rules::wpfSlotsAt(1, 1) != 2 ||
            rules::wpfSlotsAt(1, 6) != 3 ||
            rules::wpfSlotsAt(1, 11) != 4 ||
            rules::wpfSlotsAt(5, 1) != 1 ||
            rules::wpfSlotsAt(5, 7) != 2 ||
            rules::wpfSlotsAt(5, 13) != 3 ||
            rules::wpfSlotsAt(8, 1) != 3 ||
            rules::wpfSlotsAt(8, 5) != 4 ||
            rules::wpfSlotsAt(9, 1) != 1 ||
            rules::wpfSlotsAt(9, 3) != 2 ||
            rules::wpfSlotsAt(9, 5) != 3) ++bad;
        // the walker identities: level 1 = the
        // initial slots; the added slot lands at
        // 1 + cadence (every row)
        for (int r = 0; r < 10; ++r)
            if (rules::wpfSlotsAt(r, 1) !=
                    rules::wpfInitialSlots(r) ||
                rules::wpfSlotsAt(r, 1 +
                    rules::wpfAddedCadence(r)) !=
                    rules::wpfInitialSlots(r) + 1) ++bad;
        // the base-class mapping (fighter 2,
        // magic-user 5, cleric 0, thief 7; the
        // out-of-range default reads the fighter
        // row - the attackNumber convention)
        if (rules::wpfRowForBase(0) != 2 ||
            rules::wpfRowForBase(1) != 5 ||
            rules::wpfRowForBase(2) != 0 ||
            rules::wpfRowForBase(3) != 7 ||
            rules::wpfRowForBase(99) != 2) ++bad;
        // the subclass mapping (paladin 3, ranger
        // 4, druid 1, illusionist 6, assassin 8,
        // monk 9; -1 and the unknowns read -1)
        if (rules::wpfRowForSubclass(0) != 3 ||
            rules::wpfRowForSubclass(1) != 4 ||
            rules::wpfRowForSubclass(2) != 1 ||
            rules::wpfRowForSubclass(3) != 6 ||
            rules::wpfRowForSubclass(4) != 8 ||
            rules::wpfRowForSubclass(5) != 9 ||
            rules::wpfRowForSubclass(-1) != -1 ||
            rules::wpfRowForSubclass(6) != -1) ++bad;
        // the pair mapping: the subclass row wins
        // when set, the base row otherwise (an
        // unknown subclass falls back to the base)
        if (rules::wpfRowFor(0, -1) != 2 ||
            rules::wpfRowFor(2, -1) != 0 ||
            rules::wpfRowFor(0, 0) != 3 ||
            rules::wpfRowFor(2, 2) != 1 ||
            rules::wpfRowFor(1, 3) != 6 ||
            rules::wpfRowFor(3, 4) != 8 ||
            rules::wpfRowFor(3, 5) != 9 ||
            rules::wpfRowFor(3, 9) != 7) ++bad;
        // the penalty seam: -2..-5 by the class
        // pair (the subclass overrides the base)
        if (rules::wpfNonProfHitAdj(0, -1) != -2 ||
            rules::wpfNonProfHitAdj(1, -1) != -5 ||
            rules::wpfNonProfHitAdj(2, -1) != -3 ||
            rules::wpfNonProfHitAdj(3, -1) != -3 ||
            rules::wpfNonProfHitAdj(0, 0) != -2 ||
            rules::wpfNonProfHitAdj(2, 2) != -4 ||
            rules::wpfNonProfHitAdj(3, 4) != -2 ||
            rules::wpfNonProfHitAdj(3, 5) != -3 ||
            rules::wpfNonProfHitAdj(1, 3) != -5) ++bad;
        // the seam identity: the adjustment is
        // the negated penalty of the mapped row,
        // every base pair and every subclass
        for (int c = 0; c < 4; ++c)
            if (rules::wpfNonProfHitAdj(c, -1) !=
                    -rules::wpfNonProfPenalty(
                        rules::wpfRowForBase(c))) ++bad;
        for (int s = 0; s < 6; ++s)
            if (rules::wpfNonProfHitAdj(0, s) !=
                    -rules::wpfNonProfPenalty(
                        rules::wpfRowForSubclass(s))) ++bad;
        // the printed notes: the same-type magical
        // subsumption, the missile-or-melee reach,
        // the levels-above-the-1st cadence
        if (rules::wpfNoteSubsumption() != 1 ||
            rules::wpfNoteMeleeMissile() != 1 ||
            rules::wpfNoteAddedAboveFirst() != 1) ++bad;
        printf("R297 weapon proficiency table pins audit: bad %d\n", bad);
    }
