    // ---- R678 OA wu jen ninth level spells audit ----
    // OA round sixty-five (capture pp. 213-216): the wu jen ninth level spell
    // stat blocks - the school, component, casting time and saving throw
    // codes with the reversible and element markers, cross-checked spell by
    // spell between the passes - the round closing the wu jen spell book grid
    {
        using namespace rules;
        int bad = 0;
    if (dioWJL9SpellCount() != 13
            || dioWJL9ConjurationCount() != 5
            || dioWJL9DualSchoolCount() != 1
            || dioWJL9NineSegmentCasts() != 6
            || dioWJL9VSCount() != 4
            || dioWJL9VSMCount() != 6
            || dioWJL9VerbalOnlyCount() != 3
            || dioWJL9SpecialCasts() != 1
            || dioWJL9TurnCasts() != 3
            || dioWJL9NegSaves() != 1
            || dioWJL9SpecialSaves() != 3
            || dioWJL9HalfSaves() != 1
            || dioWJL9ReversibleCount() != 1
            || dioWJL9ElementCount() != 3
        )
            ++bad;
        // the stat grid - one cell per spell and column, every grid cell
        // pinned from the stat blocks cross-checked between the passes
        int CWJL9Data[13][6] = {
            {3,3,9,0,0,0},
            {6,3,9,2,0,2},
            {4,3,9,0,0,0},
            {7,3,9,0,1,0},
            {5,7,10,0,0,0},
            {3,7,10,0,0,3},
            {4,7,60,2,0,0},
            {4,1,1,0,0,0},
            {6,7,9,0,0,0},
            {4,7,60,1,0,0},
            {6,1,9,0,0,0},
            {3,7,60,3,0,4},
            {4,1,-1,2,0,0},
            };
        for (int b = 0;
             b < dioWJL9SpellCount();
             ++b) {
            int vals[6];
            vals[0] = dioWJL9School(b);
            vals[1] = dioWJL9Components(b);
            vals[2] = dioWJL9CastTime(b);
            vals[3] = dioWJL9Save(b);
            vals[4] = dioWJL9Reversible(b);
            vals[5] = dioWJL9Element(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CWJL9Data[b][c])
                    ++bad;
            }
        }
        // the count pins - 13 spells, five conjuration, one dual-school
        // print, one reversible, three element-tagged
    if (dioWJL9SpellCount() != 13
            || dioWJL9ConjurationCount() != 5
            || dioWJL9DualSchoolCount() != 1
            || dioWJL9ReversibleCount() != 1
            || dioWJL9ElementCount() != 3
        )
            ++bad;
        // the casting time pins - SIX nine-segment casts (the ninth level
        // signature), three one-turn, wish the lone Special cast
    if (dioWJL9NineSegmentCasts() != 6
            || dioWJL9TurnCasts() != 3
            || dioWJL9SpecialCasts() != 1
        )
            ++bad;
        // the component pins - the opening V,S quartet, six VSM, three
        // verbal-only, no somatic-only or V,M spell
    if (dioWJL9VSCount() != 4
            || dioWJL9VSMCount() != 6
            || dioWJL9VerbalOnlyCount() != 3
        )
            ++bad;
        // the saving throw pins - summon spirit the lone neg., three special,
        // tsunami the lone half save
    if (dioWJL9NegSaves() != 1
            || dioWJL9SpecialSaves() != 3
            || dioWJL9HalfSaves() != 1
        )
            ++bad;
        // the school column - the five conjurations, the three alterations,
        // the three evocations, imprisonment the lone abjuration, instant
        // regeneration the lone necromantic, summon spirit the dual pinned 4
    if (dioWJL9School(0) != 3
            || dioWJL9School(1) != 6
            || dioWJL9School(2) != 4
            || dioWJL9School(3) != 7
            || dioWJL9School(4) != 5
            || dioWJL9School(5) != 3
            || dioWJL9School(6) != 4
            || dioWJL9School(7) != 4
            || dioWJL9School(8) != 6
            || dioWJL9School(9) != 4
            || dioWJL9School(10) != 6
            || dioWJL9School(11) != 3
            || dioWJL9School(12) != 4
        )
            ++bad;
        // the component column - the opening V,S quartet, the six VSM spells,
        // the three verbal-only
    if (dioWJL9Components(0) != 3
            || dioWJL9Components(1) != 3
            || dioWJL9Components(2) != 3
            || dioWJL9Components(3) != 3
            || dioWJL9Components(4) != 7
            || dioWJL9Components(5) != 7
            || dioWJL9Components(6) != 7
            || dioWJL9Components(7) != 1
            || dioWJL9Components(8) != 7
            || dioWJL9Components(9) != 7
            || dioWJL9Components(10) != 1
            || dioWJL9Components(11) != 7
            || dioWJL9Components(12) != 1
        )
            ++bad;
        // the casting time column - the six nine-segment casts, the three
        // one-turn, the one-round pair, power word kill the single segment,
        // wish -1
    if (dioWJL9CastTime(0) != 9
            || dioWJL9CastTime(1) != 9
            || dioWJL9CastTime(2) != 9
            || dioWJL9CastTime(3) != 9
            || dioWJL9CastTime(4) != 10
            || dioWJL9CastTime(5) != 10
            || dioWJL9CastTime(6) != 60
            || dioWJL9CastTime(7) != 1
            || dioWJL9CastTime(8) != 9
            || dioWJL9CastTime(9) != 60
            || dioWJL9CastTime(10) != 9
            || dioWJL9CastTime(11) != 60
            || dioWJL9CastTime(12) != -1
        )
            ++bad;
        // the saving throw column - crystalbrittle, planar call and wish
        // special, summon spirit neg., tsunami the lone half, the other eight
        // none
    if (dioWJL9Save(0) != 0
            || dioWJL9Save(1) != 2
            || dioWJL9Save(2) != 0
            || dioWJL9Save(3) != 0
            || dioWJL9Save(4) != 0
            || dioWJL9Save(5) != 0
            || dioWJL9Save(6) != 2
            || dioWJL9Save(7) != 0
            || dioWJL9Save(8) != 0
            || dioWJL9Save(9) != 1
            || dioWJL9Save(10) != 0
            || dioWJL9Save(11) != 3
            || dioWJL9Save(12) != 2
        )
            ++bad;
        // the reversible column - imprisonment the one reversible spell of
        // the level
    if (dioWJL9Reversible(3) != 1
            || dioWJL9Reversible(0) != 0
            || dioWJL9Reversible(2) != 0
            || dioWJL9Reversible(8) != 0
            || dioWJL9Reversible(12) != 0
        )
            ++bad;
        // the element column - the three tagged cells matching the R669
        // dieWJT66L9Element grid exactly: crystalbrittle Earth, internal fire
        // Fire, tsunami Water
    if (dioWJL9Element(1) != 2
            || dioWJL9Element(5) != 3
            || dioWJL9Element(11) != 4
            || dioWJL9Element(0) != 0
            || dioWJL9Element(4) != 0
            || dioWJL9Element(9) != 0
            || dioWJL9Element(12) != 0
        )
            ++bad;
        // the wish line - the lone Special cast pinned -1 AND the special
        // save, verbal-only, conjuration school
    if (dioWJL9CastTime(12) != -1
            || dioWJL9Save(12) != 2
            || dioWJL9Components(12) != 1
            || dioWJL9School(12) != 4
        )
            ++bad;
        printf("R678 OA wu jen ninth level spells audit: bad %d\n", bad);
        if (bad) return 1;
    }
