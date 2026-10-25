    // ---- R400: the UA comeliness
    // site audit ----
    // The deferred seam closes: the
    // Character field, the creation roll
    // and the parley-gate reaction
    // callers read the R322 pins. The
    // save line and the load tag are
    // splice-assert verified (the
    // battery never writes adnd1.sav).
    {
        using namespace rules;
        int bad = 0;
        // the score helper: the raw 3d6
        // plus the charisma ladder; 0 =
        // unknown reads 0 (the v1-save
        // read); cha below 3 reads -8
        if (uaComelinessScore(0, 12) != 0)
            ++bad;
        if (uaComelinessScore(3, 12) != 3)
            ++bad;
        if (uaComelinessScore(3, 3) != -2)
            ++bad;
        if (uaComelinessScore(3, 2) != -5)
            ++bad;
        if (uaComelinessScore(18, 18) != 21)
            ++bad;
        if (uaComelinessScore(18, 19) != 23)
            ++bad;
        // the print dwarf example (base
        // 9, cha 16): the score reads 11
        // (the print own at-8 cell is the
        // loose arithmetic)
        if (uaComelinessScore(9, 16) != 11)
            ++bad;
        // the viewed score: the same-race
        // pairs read 0 (the print
        // halfling/human and the
        // sylvan-elf/half-elf pairs)
        if (uaComelinessEffective(11, RACE_DWARF,
                                 RACE_DWARF) != 11)
            ++bad;
        if (uaComelinessEffective(11, RACE_DWARF,
                                 RACE_HUMAN) != 10)
            ++bad;
        if (uaComelinessEffective(11, RACE_HUMAN,
                                 RACE_HALFLING) != 11)
            ++bad;
        if (uaComelinessEffective(11, RACE_HALFLING,
                                 RACE_HUMAN) != 11)
            ++bad;
        if (uaComelinessEffective(11, RACE_HALF_ELF,
                                 RACE_ELF) != 11)
            ++bad;
        if (uaComelinessEffective(11, RACE_ELF,
                                 RACE_HALF_ELF) != 11)
            ++bad;
        if (uaComelinessEffective(11, RACE_HALF_ORC,
                                 RACE_HUMAN) != 8)
            ++bad;
        // the unknown member views 0 (the
        // v1-save read)
        if (uaComelinessEffective(0, RACE_DWARF,
                                 RACE_HUMAN) != 0)
            ++bad;
        // the monster-viewer read: the
        // viewed-race adjustment always
        // rides (the site convention)
        if (uaComelinessScoreOtherRace(9, 16,
                                      RACE_DWARF) != 10)
            ++bad;
        if (uaComelinessScoreOtherRace(9, 16,
                                      RACE_HUMAN) != 11)
            ++bad;
        if (uaComelinessScoreOtherRace(0, 12,
                                      RACE_ELF) != 0)
            ++bad;
        // the initial-contact percentile:
        // 100 at 14-17, 150 at 18-21, 200
        // at 22 and up (the print 22
        // comeliness equals +44%); the
        // bands below interest carry no
        // percentile
        if (uaComelinessReactionAdj(-5) != 0)
            ++bad;
        if (uaComelinessReactionAdj(10) != 0)
            ++bad;
        if (uaComelinessReactionAdj(13) != 0)
            ++bad;
        if (uaComelinessReactionAdj(14) != 14)
            ++bad;
        if (uaComelinessReactionAdj(16) != 16)
            ++bad;
        if (uaComelinessReactionAdj(17) != 17)
            ++bad;
        if (uaComelinessReactionAdj(18) != 27)
            ++bad;
        if (uaComelinessReactionAdj(21) != 31)
            ++bad;
        if (uaComelinessReactionAdj(22) != 44)
            ++bad;
        if (uaComelinessReactionAdj(25) != 50)
            ++bad;
        if (uaComelinessReactionAdj(26) != 52)
            ++bad;
        // ---- the cross-checks ----
        // the stunning and unearthly
        // ladders double the score
        if (2 * 22 != uaComelinessReactionAdj(22))
            ++bad;
        if (2 * 26 != uaComelinessReactionAdj(26))
            ++bad;
        // the unknown member never moves
        // a reaction
        if (uaComelinessReactionAdj(
                uaComelinessScore(0, 12)) != 0)
            ++bad;
        // ---- the wiring ----
        // the creation roll rides the
        // member; a fresh Character reads
        // unknown (the v1-save read)
        {
            CreationState cr;
            cr.rollFresh();
            if (cr.uaComRoll < 3
                || cr.uaComRoll > 18) ++bad;
            Character c = cr.makeMember(0);
            if (c.uaComBase != cr.uaComRoll)
                ++bad;
            Character d;
            if (d.uaComBase != 0) ++bad;
        }
        printf("R400 UA comeliness site audit: bad %d\n", bad);
        if (bad) return 1;
    }
