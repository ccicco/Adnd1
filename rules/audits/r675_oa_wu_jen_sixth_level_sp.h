    // ---- R675 OA wu jen sixth level spells audit ----
    // OA round sixty-two (capture pp. 196-203): the wu jen sixth level spell
    // stat blocks - the school, component, casting time and saving throw
    // codes with the reversible and element markers, cross-checked spell by
    // spell between the passes
    {
        using namespace rules;
        int bad = 0;
    if (dikWJL6SpellCount() != 24
            || dikWJL6AlterationCount() != 9
            || dikWJL6IllusionCount() != 3
            || dikWJL6InvocationCount() != 2
            || dikWJL6DualSchoolCount() != 3
            || dikWJL6ReversibleCount() != 4
            || dikWJL6VSMCount() != 17
            || dikWJL6VSCount() != 3
            || dikWJL6VMCount() != 3
            || dikWJL6VerbalOnlyCount() != 1
            || dikWJL6SpecialCasts() != 3
            || dikWJL6SixSegmentCasts() != 6
            || dikWJL6TurnCasts() != 5
            || dikWJL6RoundCasts() != 5
            || dikWJL6OneSegmentCasts() != 2
            || dikWJL6NegSaves() != 3
            || dikWJL6SpecialSaves() != 5
            || dikWJL6ElementCount() != 7
        )
            ++bad;
        // the wu jen sixth level stat grid: the school, component, casting
        // time and saving throw codes with the reversible and element markers
        // by spell ordinal
        int CWJL6Data[24][6] = {
            {2,3,10,0,1,0},
            {6,7,60,0,0,0},
            {6,7,6,1,0,0},
            {4,7,-1,1,0,0},
            {8,7,1,0,0,0},
            {1,1,4,0,0,0},
            {6,7,10,0,0,2},
            {6,7,60,0,1,4},
            {1,5,6,1,0,0},
            {6,7,10,2,1,2},
            {6,7,-1,0,0,2},
            {8,7,1,0,0,0},
            {6,7,60,0,0,4},
            {9,7,6,2,0,0},
            {9,7,6,2,0,0},
            {7,5,6,0,0,0},
            {5,7,60,0,0,0},
            {3,5,-1,2,0,0},
            {6,7,6,2,1,2},
            {3,7,5,0,0,0},
            {2,3,10,0,0,0},
            {9,3,3,0,0,0},
            {4,7,60,0,0,0},
            {6,7,10,0,0,2},
            };
        for (int b = 0;
             b < dikWJL6SpellCount();
             ++b) {
            int vals[6];
            vals[0] = dikWJL6School(b);
            vals[1] = dikWJL6Components(b);
            vals[2] = dikWJL6CastTime(b);
            vals[3] = dikWJL6Save(b);
            vals[4] = dikWJL6Reversible(b);
            vals[5] = dikWJL6Element(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CWJL6Data[b][c])
                    ++bad;
            }
        }
        // the count pins - 24 spells, nine alteration, three illusion, two
        // invocation, four reversible, seven element-tagged
    if (dikWJL6SpellCount() != 24
            || dikWJL6AlterationCount() != 9
            || dikWJL6IllusionCount() != 3
            || dikWJL6InvocationCount() != 2
            || dikWJL6ReversibleCount() != 4
            || dikWJL6ElementCount() != 7
        )
            ++bad;
        // the component pins - 17 VSM, three VS, three V,M, geas the lone
        // verbal only
    if (dikWJL6VSMCount() != 17
            || dikWJL6VSCount() != 3
            || dikWJL6VMCount() != 3
            || dikWJL6VerbalOnlyCount() != 1
        )
            ++bad;
        // the casting time pins - three Special casts (-1), six six-segment,
        // five turn casts, five round casts, two single segments
    if (dikWJL6SpecialCasts() != 3
            || dikWJL6SixSegmentCasts() != 6
            || dikWJL6TurnCasts() != 5
            || dikWJL6RoundCasts() != 5
            || dikWJL6OneSegmentCasts() != 2
        )
            ++bad;
        // the saving throw pins - three neg., five special, no half save this
        // level
    if (dikWJL6NegSaves() != 3
            || dikWJL6SpecialSaves() != 5
        )
            ++bad;
        // the school pins - the three duals pinned primary: gambler's luck 8,
        // spiritwrack and sword of darkness 3; speak with dead the lone
        // necromantic, repulsion the lone abjuration; aura and true sight
        // divination; enchant an item and vessel conjuration; geas and mass
        // suggestion enchantment/charm; pain invocation; the three illusion;
        // disintegrate and glassee among the nine alteration
    if (dikWJL6School(4) != 8
            || dikWJL6School(17) != 3
            || dikWJL6School(19) != 3
            || dikWJL6School(16) != 5
            || dikWJL6School(15) != 7
            || dikWJL6School(0) != 2
            || dikWJL6School(20) != 2
            || dikWJL6School(3) != 4
            || dikWJL6School(22) != 4
            || dikWJL6School(5) != 1
            || dikWJL6School(8) != 1
            || dikWJL6School(11) != 8
            || dikWJL6School(13) != 9
            || dikWJL6School(14) != 9
            || dikWJL6School(21) != 9
            || dikWJL6School(2) != 6
            || dikWJL6School(6) != 6
            || dikWJL6School(9) != 6
            || dikWJL6School(10) != 6
            || dikWJL6School(12) != 6
            || dikWJL6School(18) != 6
            || dikWJL6School(23) != 6
            || dikWJL6School(1) != 6
        )
            ++bad;
        // the dual-school count pin - three duals this level, the most of any
        // wu jen level yet
    if (dikWJL6DualSchoolCount() != 3
        )
            ++bad;
        // the component cell pins - the verbal-only geas, the V,M set, the VS
        // set, and the VSM spots
    if (dikWJL6Components(5) != 1
            || dikWJL6Components(8) != 5
            || dikWJL6Components(15) != 5
            || dikWJL6Components(17) != 5
            || dikWJL6Components(0) != 3
            || dikWJL6Components(20) != 3
            || dikWJL6Components(21) != 3
            || dikWJL6Components(2) != 7
            || dikWJL6Components(6) != 7
            || dikWJL6Components(16) != 7
            || dikWJL6Components(22) != 7
            || dikWJL6Components(23) != 7
        )
            ++bad;
        // the casting time cell pins - the three Special casts at -1, the
        // six-segment spots, the turn casts, the single segments, geas the
        // four, sword of darkness the five, veil the three
    if (dikWJL6CastTime(3) != -1
            || dikWJL6CastTime(10) != -1
            || dikWJL6CastTime(17) != -1
            || dikWJL6CastTime(2) != 6
            || dikWJL6CastTime(8) != 6
            || dikWJL6CastTime(13) != 6
            || dikWJL6CastTime(14) != 6
            || dikWJL6CastTime(15) != 6
            || dikWJL6CastTime(18) != 6
            || dikWJL6CastTime(1) != 60
            || dikWJL6CastTime(7) != 60
            || dikWJL6CastTime(12) != 60
            || dikWJL6CastTime(16) != 60
            || dikWJL6CastTime(22) != 60
            || dikWJL6CastTime(4) != 1
            || dikWJL6CastTime(11) != 1
            || dikWJL6CastTime(5) != 4
            || dikWJL6CastTime(19) != 5
            || dikWJL6CastTime(21) != 3
        )
            ++bad;
        // the saving throw cell pins - the three negation saves, the five
        // special saves, aura none
    if (dikWJL6Save(2) != 1
            || dikWJL6Save(3) != 1
            || dikWJL6Save(8) != 1
            || dikWJL6Save(9) != 2
            || dikWJL6Save(13) != 2
            || dikWJL6Save(14) != 2
            || dikWJL6Save(17) != 2
            || dikWJL6Save(18) != 2
            || dikWJL6Save(0) != 0
        )
            ++bad;
        // the reversible pins - aura, lower water, metal to rust and stone to
        // flesh marked; disintegrate, geas and veil not
    if (dikWJL6Reversible(0) != 1
            || dikWJL6Reversible(7) != 1
            || dikWJL6Reversible(9) != 1
            || dikWJL6Reversible(18) != 1
            || dikWJL6Reversible(2) != 0
            || dikWJL6Reversible(5) != 0
            || dikWJL6Reversible(21) != 0
        )
            ++bad;
        // the element cross-check pins - the seven tagged cells matching the
        // R669 dieWJT66L6Element grid: glassee, metal to rust, move earth,
        // stone to flesh and warp stone the five Earth marks; lower water and
        // part water the two Water; control weather untagged
    if (dikWJL6Element(6) != 2
            || dikWJL6Element(9) != 2
            || dikWJL6Element(10) != 2
            || dikWJL6Element(18) != 2
            || dikWJL6Element(23) != 2
            || dikWJL6Element(7) != 4
            || dikWJL6Element(12) != 4
            || dikWJL6Element(1) != 0
            || dikWJL6Element(19) != 0
        )
            ++bad;
        printf("R675 OA wu jen sixth level spells audit: bad %d\n", bad);
        if (bad) return 1;
    }
