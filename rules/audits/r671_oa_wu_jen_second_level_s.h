    // ---- R671 OA wu jen second level spells audit ----
    // OA round fifty-eight (capture pp. 165-173): the wu jen second level
    // spell stat blocks - the school, component, casting time and saving
    // throw codes with the reversible and element markers, cross-checked
    // spell by spell between the passes
    {
        using namespace rules;
        int bad = 0;
    if (digWJL2SpellCount() != 30
            || digWJL2ReversibleCount() != 2
            || digWJL2AlterationCount() != 11
            || digWJL2DivinationCount() != 5
            || digWJL2EvocationCount() != 6
            || digWJL2IllusionCount() != 5
            || digWJL2VSMCount() != 19
            || digWJL2VSCount() != 7
            || digWJL2SMCount() != 2
            || digWJL2VMCount() != 1
            || digWJL2VerbalOnlyCount() != 1
            || digWJL2TwoSegmentCasts() != 16
            || digWJL2RoundCasts() != 7
            || digWJL2TurnCasts() != 4
            || digWJL2ThreeSegmentCasts() != 2
            || digWJL2OneSegmentCasts() != 1
            || digWJL2NegSaves() != 5
            || digWJL2SpecialSaves() != 3
            || digWJL2HalfSaves() != 1
            || digWJL2ElementCount() != 10
        )
            ++bad;
        // the wu jen second level stat grid: the school, component, casting
        // time and saving throw codes with the reversible and element markers
        // by spell ordinal
        int CWJL2Data[30][6] = {
            {1,7,60,1,0,0},
            {9,7,10,1,0,0},
            {4,7,10,0,0,4},
            {6,7,2,0,0,0},
            {2,3,2,0,1,0},
            {2,7,2,0,0,0},
            {2,7,2,0,0,0},
            {3,7,60,0,0,0},
            {3,7,3,0,0,3},
            {6,3,2,0,0,1},
            {9,6,2,1,0,0},
            {3,7,10,1,0,4},
            {9,7,2,0,0,0},
            {6,1,1,0,0,0},
            {2,7,2,0,1,0},
            {9,3,2,1,0,0},
            {2,5,60,0,0,0},
            {9,7,3,2,0,0},
            {7,7,2,0,0,0},
            {6,3,2,0,0,3},
            {6,7,2,0,0,0},
            {6,3,10,0,0,1},
            {6,7,10,0,0,1},
            {3,7,2,2,0,1},
            {6,7,60,0,0,0},
            {6,6,10,0,0,0},
            {3,7,10,3,0,1},
            {3,7,2,2,0,0},
            {6,3,2,0,0,1},
            {6,3,2,0,0,0},
            };
        for (int b = 0;
             b < digWJL2SpellCount();
             ++b) {
            int vals[6];
            vals[0] = digWJL2School(b);
            vals[1] = digWJL2Components(b);
            vals[2] = digWJL2CastTime(b);
            vals[3] = digWJL2Save(b);
            vals[4] = digWJL2Reversible(b);
            vals[5] = digWJL2Element(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CWJL2Data[b][c])
                    ++bad;
            }
        }
        // the count pins - 30 spells, two reversible, 11 alteration, five
        // divination, six evocation, five illusion
    if (digWJL2SpellCount() != 30
            || digWJL2ReversibleCount() != 2
            || digWJL2AlterationCount() != 11
            || digWJL2DivinationCount() != 5
            || digWJL2EvocationCount() != 6
            || digWJL2IllusionCount() != 5
        )
            ++bad;
        // the component pins - 19 VSM, seven VS, hypnotic pattern and
        // vocalize the S,M pairs, omen the V,M, knock the verbal only
    if (digWJL2VSMCount() != 19
            || digWJL2VSCount() != 7
            || digWJL2SMCount() != 2
            || digWJL2VMCount() != 1
            || digWJL2VerbalOnlyCount() != 1
        )
            ++bad;
        // the casting time pins - 16 two-segment, seven round casts, four
        // turn casts, two three-segment, knock the lone segment
    if (digWJL2TwoSegmentCasts() != 16
            || digWJL2RoundCasts() != 7
            || digWJL2TurnCasts() != 4
            || digWJL2ThreeSegmentCasts() != 2
            || digWJL2OneSegmentCasts() != 1
        )
            ++bad;
        // the saving throw pins - five neg., three special, wind breath the
        // lone half
    if (digWJL2NegSaves() != 5
            || digWJL2SpecialSaves() != 3
            || digWJL2HalfSaves() != 1
            || digWJL2ElementCount() != 10
        )
            ++bad;
        // the school pins - animal companion the lone enchantment/charm and
        // protection from charm the lone abjuration; the five divination; the
        // six evocation; the five illusion; the two duals (bind, whispering
        // wind) and knock among the 11 alteration
    if (digWJL2School(0) != 1
            || digWJL2School(18) != 7
            || digWJL2School(4) != 2
            || digWJL2School(5) != 2
            || digWJL2School(6) != 2
            || digWJL2School(14) != 2
            || digWJL2School(16) != 2
            || digWJL2School(7) != 3
            || digWJL2School(8) != 3
            || digWJL2School(11) != 3
            || digWJL2School(23) != 3
            || digWJL2School(26) != 3
            || digWJL2School(27) != 3
            || digWJL2School(2) != 4
            || digWJL2School(1) != 9
            || digWJL2School(10) != 9
            || digWJL2School(12) != 9
            || digWJL2School(15) != 9
            || digWJL2School(17) != 9
            || digWJL2School(3) != 6
            || digWJL2School(28) != 6
            || digWJL2School(13) != 6
            || digWJL2School(29) != 6
        )
            ++bad;
        // the component cell pins - the verbal-only knock, the V,M omen, the
        // S,M hypnotic pattern and vocalize, and the VS set
    if (digWJL2Components(13) != 1
            || digWJL2Components(16) != 5
            || digWJL2Components(10) != 6
            || digWJL2Components(25) != 6
            || digWJL2Components(4) != 3
            || digWJL2Components(9) != 3
            || digWJL2Components(15) != 3
            || digWJL2Components(19) != 3
            || digWJL2Components(21) != 3
            || digWJL2Components(28) != 3
            || digWJL2Components(29) != 3
            || digWJL2Components(0) != 7
            || digWJL2Components(1) != 7
            || digWJL2Components(2) != 7
        )
            ++bad;
        // the casting time cell pins - the four turn casts, the three-segment
        // pair, the one-round ice knife and vocalize, knock the lone segment
    if (digWJL2CastTime(0) != 60
            || digWJL2CastTime(7) != 60
            || digWJL2CastTime(16) != 60
            || digWJL2CastTime(24) != 60
            || digWJL2CastTime(8) != 3
            || digWJL2CastTime(17) != 3
            || digWJL2CastTime(11) != 10
            || digWJL2CastTime(25) != 10
            || digWJL2CastTime(13) != 1
            || digWJL2CastTime(3) != 2
            || digWJL2CastTime(5) != 2
        )
            ++bad;
        // the saving throw cell pins - the five negation saves, the three
        // special saves, wind breath the half, knock none
    if (digWJL2Save(0) != 1
            || digWJL2Save(1) != 1
            || digWJL2Save(10) != 1
            || digWJL2Save(11) != 1
            || digWJL2Save(15) != 1
            || digWJL2Save(17) != 2
            || digWJL2Save(23) != 2
            || digWJL2Save(27) != 2
            || digWJL2Save(26) != 3
            || digWJL2Save(13) != 0
        )
            ++bad;
        // the reversible pins - detect evil and locate object marked, detect
        // invisibility, invisibility and knock not
    if (digWJL2Reversible(4) != 1
            || digWJL2Reversible(14) != 1
            || digWJL2Reversible(5) != 0
            || digWJL2Reversible(12) != 0
            || digWJL2Reversible(13) != 0
            || digWJL2Reversible(0) != 0
        )
            ++bad;
        // the element cross-check pins - the 10 tagged cells matching the
        // R669 dieWJT66L2Element grid: animate water and ice knife Water,
        // fire shuriken and pyrotechnics Fire, the six Air marks (fog cloud,
        // smoke shape, smoky form, stinking cloud, wind breath, whispering
        // wind); knock untagged
    if (digWJL2Element(2) != 4
            || digWJL2Element(11) != 4
            || digWJL2Element(8) != 3
            || digWJL2Element(19) != 3
            || digWJL2Element(9) != 1
            || digWJL2Element(21) != 1
            || digWJL2Element(22) != 1
            || digWJL2Element(23) != 1
            || digWJL2Element(26) != 1
            || digWJL2Element(28) != 1
            || digWJL2Element(13) != 0
            || digWJL2Element(0) != 0
        )
            ++bad;
        printf("R671 OA wu jen second level spells audit: bad %d\n", bad);
        if (bad) return 1;
    }
