    // ---- R674 OA wu jen fifth level spells audit ----
    // OA round sixty-one (capture pp. 189-196): the wu jen fifth level spell
    // stat blocks - the school, component, casting time and saving throw
    // codes with the reversible and element markers, cross-checked spell by
    // spell between the passes
    {
        using namespace rules;
        int bad = 0;
    if (dijWJL5SpellCount() != 24
            || dijWJL5AlterationCount() != 10
            || dijWJL5EvocationCount() != 8
            || dijWJL5ReversibleCount() != 4
            || dijWJL5VSMCount() != 20
            || dijWJL5SomaticOnlyCount() != 2
            || dijWJL5VSCount() != 2
            || dijWJL5FiveSegmentCasts() != 9
            || dijWJL5RoundCasts() != 6
            || dijWJL5ThreeSegmentCasts() != 3
            || dijWJL5TurnCasts() != 2
            || dijWJL5FiveRoundCast() != 1
            || dijWJL5OneSegmentCasts() != 1
            || dijWJL5TwoSegmentCasts() != 1
            || dijWJL5FourSegmentCasts() != 1
            || dijWJL5NegSaves() != 3
            || dijWJL5HalfSaves() != 2
            || dijWJL5ElementCount() != 13
        )
            ++bad;
        // the wu jen fifth level stat grid: the school, component, casting
        // time and saving throw codes with the reversible and element markers
        // by spell ordinal
        int CWJL5Data[24][6] = {
            {8,2,3,0,0,0},
            {6,3,5,0,1,0},
            {5,7,50,0,0,0},
            {3,7,5,3,0,4},
            {4,7,60,0,0,7},
            {3,7,5,0,0,1},
            {7,7,10,1,1,0},
            {3,7,10,3,0,3},
            {6,7,10,0,0,5},
            {6,7,60,0,0,0},
            {6,7,10,1,0,2},
            {6,7,5,0,0,2},
            {6,7,5,0,0,2},
            {4,7,1,0,0,0},
            {9,2,2,0,0,0},
            {6,7,3,0,0,0},
            {6,7,10,0,0,2},
            {3,7,4,0,0,0},
            {6,3,5,0,0,0},
            {3,7,5,0,0,0},
            {3,7,5,0,0,2},
            {3,7,5,0,0,2},
            {6,7,10,0,1,9},
            {3,7,3,1,1,5},
            };
        for (int b = 0;
             b < dijWJL5SpellCount();
             ++b) {
            int vals[6];
            vals[0] = dijWJL5School(b);
            vals[1] = dijWJL5Components(b);
            vals[2] = dijWJL5CastTime(b);
            vals[3] = dijWJL5Save(b);
            vals[4] = dijWJL5Reversible(b);
            vals[5] = dijWJL5Element(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CWJL5Data[b][c])
                    ++bad;
            }
        }
        // the count pins - 24 spells, 10 alteration, eight evocation, four
        // reversible, 13 element-tagged
    if (dijWJL5SpellCount() != 24
            || dijWJL5AlterationCount() != 10
            || dijWJL5EvocationCount() != 8
            || dijWJL5ReversibleCount() != 4
            || dijWJL5ElementCount() != 13
        )
            ++bad;
        // the component pins - 20 VSM, the two somatic-only spells, animal
        // growth and telekinesis the VS pair
    if (dijWJL5VSMCount() != 20
            || dijWJL5SomaticOnlyCount() != 2
            || dijWJL5VSCount() != 2
        )
            ++bad;
        // the casting time pins - nine five-segment, six round casts, animate
        // dead the five-round 50, two turn casts, three three-segment,
        // servant horde the lone segment
    if (dijWJL5FiveSegmentCasts() != 9
            || dijWJL5RoundCasts() != 6
            || dijWJL5FiveRoundCast() != 1
            || dijWJL5TurnCasts() != 2
            || dijWJL5ThreeSegmentCasts() != 3
            || dijWJL5OneSegmentCasts() != 1
            || dijWJL5TwoSegmentCasts() != 1
            || dijWJL5FourSegmentCasts() != 1
        )
            ++bad;
        // the saving throw pins - three neg., cone of cold and fire breath
        // the two half, no special save this level
    if (dijWJL5NegSaves() != 3
            || dijWJL5HalfSaves() != 2
        )
            ++bad;
        // the school pins - animate dead the lone necromantic; aiming at the
        // target the lone invocation; shadow door the lone illusion;
        // dismissal the lone abjuration with its triple-line print pinned
        // primary 7; conjure elemental and servant horde conjuration; sword
        // of deception, wall of force and creeping darkness among the eight
        // evocation; ironwood and telekinesis among the 10 alteration
    if (dijWJL5School(2) != 5
            || dijWJL5School(0) != 8
            || dijWJL5School(14) != 9
            || dijWJL5School(6) != 7
            || dijWJL5School(4) != 4
            || dijWJL5School(13) != 4
            || dijWJL5School(3) != 3
            || dijWJL5School(5) != 3
            || dijWJL5School(7) != 3
            || dijWJL5School(17) != 3
            || dijWJL5School(19) != 3
            || dijWJL5School(20) != 3
            || dijWJL5School(21) != 3
            || dijWJL5School(23) != 3
            || dijWJL5School(8) != 6
            || dijWJL5School(9) != 6
            || dijWJL5School(10) != 6
            || dijWJL5School(11) != 6
            || dijWJL5School(12) != 6
            || dijWJL5School(15) != 6
            || dijWJL5School(16) != 6
            || dijWJL5School(18) != 6
            || dijWJL5School(22) != 6
        )
            ++bad;
        // the component cell pins - the two somatic-only spells, the VS pair,
        // and the VSM spots
    if (dijWJL5Components(0) != 2
            || dijWJL5Components(14) != 2
            || dijWJL5Components(1) != 3
            || dijWJL5Components(18) != 3
            || dijWJL5Components(2) != 7
            || dijWJL5Components(3) != 7
            || dijWJL5Components(4) != 7
            || dijWJL5Components(13) != 7
            || dijWJL5Components(22) != 7
            || dijWJL5Components(23) != 7
        )
            ++bad;
        // the casting time cell pins - animate dead the 50, the turn casts,
        // servant horde the lone segment, shadow door the two, sword of
        // deception the four, the three-segment spots
    if (dijWJL5CastTime(2) != 50
            || dijWJL5CastTime(4) != 60
            || dijWJL5CastTime(9) != 60
            || dijWJL5CastTime(13) != 1
            || dijWJL5CastTime(14) != 2
            || dijWJL5CastTime(17) != 4
            || dijWJL5CastTime(0) != 3
            || dijWJL5CastTime(15) != 3
            || dijWJL5CastTime(23) != 3
            || dijWJL5CastTime(1) != 5
            || dijWJL5CastTime(11) != 5
            || dijWJL5CastTime(19) != 5
        )
            ++bad;
        // the saving throw cell pins - the three negation saves, the two half
        // saves, wall of force none
    if (dijWJL5Save(6) != 1
            || dijWJL5Save(10) != 1
            || dijWJL5Save(23) != 1
            || dijWJL5Save(3) != 3
            || dijWJL5Save(7) != 3
            || dijWJL5Save(19) != 0
            || dijWJL5Save(0) != 0
        )
            ++bad;
        // the reversible pins - animal growth, dismissal, water to poison and
        // wood rot marked; ironwood, major creation and telekinesis not
    if (dijWJL5Reversible(1) != 1
            || dijWJL5Reversible(6) != 1
            || dijWJL5Reversible(22) != 1
            || dijWJL5Reversible(23) != 1
            || dijWJL5Reversible(8) != 0
            || dijWJL5Reversible(9) != 0
            || dijWJL5Reversible(18) != 0
        )
            ++bad;
        // the element cross-check pins - the 13 tagged cells matching the
        // R669 dieWJT66L5Element grid: cone of cold Water, conjure elemental
        // All, creeping darkness Air, fire breath Fire, ironwood and wood rot
        // Nature, the six Earth marks, water to poison the Nature/Water dual
        // 9; wall of force untagged
    if (dijWJL5Element(3) != 4
            || dijWJL5Element(4) != 7
            || dijWJL5Element(5) != 1
            || dijWJL5Element(7) != 3
            || dijWJL5Element(8) != 5
            || dijWJL5Element(23) != 5
            || dijWJL5Element(10) != 2
            || dijWJL5Element(11) != 2
            || dijWJL5Element(12) != 2
            || dijWJL5Element(16) != 2
            || dijWJL5Element(20) != 2
            || dijWJL5Element(21) != 2
            || dijWJL5Element(22) != 9
            || dijWJL5Element(19) != 0
            || dijWJL5Element(0) != 0
        )
            ++bad;
        printf("R674 OA wu jen fifth level spells audit: bad %d\n", bad);
        if (bad) return 1;
    }
