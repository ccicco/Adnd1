    // ---- R677 OA wu jen eighth level spells audit ----
    // OA round sixty-four (capture pp. 207-213): the wu jen eighth level
    // spell stat blocks - the school, component, casting time and saving
    // throw codes with the reversible and element markers, cross-checked
    // spell by spell between the passes
    {
        using namespace rules;
        int bad = 0;
    if (dimWJL8SpellCount() != 14
            || dimWJL8AlterationCount() != 7
            || dimWJL8ConjurationCount() != 4
            || dimWJL8DualSchoolCount() != 2
            || dimWJL8VSMCount() != 10
            || dimWJL8SomaticOnlyCount() != 1
            || dimWJL8VerbalOnlyCount() != 1
            || dimWJL8ReversibleCount() != 1
            || dimWJL8SixTurnCast() != 360
            || dimWJL8TurnCasts() != 4
            || dimWJL8SpecialSaves() != 3
            || dimWJL8HalfSaves() != 2
            || dimWJL8ElementCount() != 4
        )
            ++bad;
        // the stat grid - one cell per spell and column, every grid cell
        // pinned from the stat blocks cross-checked between the passes
        int CWJL8Data[14][6] = {
            {1,7,360,2,0,0},
            {4,7,60,1,0,0},
            {6,7,5,0,0,1},
            {6,2,1,0,0,0},
            {6,7,60,0,1,0},
            {6,7,2,3,0,3},
            {7,3,1,0,0,0},
            {6,7,20,0,0,0},
            {6,7,10,2,0,0},
            {4,1,1,0,0,0},
            {0,3,60,0,0,1},
            {6,7,10,0,0,0},
            {4,7,8,2,0,0},
            {4,7,60,3,0,1},
            };
        for (int b = 0;
             b < dimWJL8SpellCount();
             ++b) {
            int vals[6];
            vals[0] = dimWJL8School(b);
            vals[1] = dimWJL8Components(b);
            vals[2] = dimWJL8CastTime(b);
            vals[3] = dimWJL8Save(b);
            vals[4] = dimWJL8Reversible(b);
            vals[5] = dimWJL8Element(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CWJL8Data[b][c])
                    ++bad;
            }
        }
        // the count pins - 14 spells, seven alteration, four conjuration, two
        // dual-school prints, one reversible, four element-tagged
    if (dimWJL8SpellCount() != 14
            || dimWJL8AlterationCount() != 7
            || dimWJL8ConjurationCount() != 4
            || dimWJL8DualSchoolCount() != 2
            || dimWJL8ReversibleCount() != 1
            || dimWJL8ElementCount() != 4
        )
            ++bad;
        // the component pins - 10 VSM, finding the center the lone
        // somatic-only, power word blind the lone verbal-only
    if (dimWJL8VSMCount() != 10
            || dimWJL8SomaticOnlyCount() != 1
            || dimWJL8VerbalOnlyCount() != 1
        )
            ++bad;
        // the casting time pins - the antipathy/sympathy six-turn cast pinned
        // 360 (the longest of the wu jen levels yet), four one-turn, no
        // Special cast this level
    if (dimWJL8SixTurnCast() != 360
            || dimWJL8TurnCasts() != 4
        )
            ++bad;
        // the saving throw pins - call the lone neg., three special, the two
        // half saves (the whirlwind 112 print garble settled by the
        // compressed 1/2)
    if (dimWJL8SpecialSaves() != 3
            || dimWJL8HalfSaves() != 2
        )
            ++bad;
        // the school column - the two duals pinned primary 6 (finding the
        // center, incendiary cloud), summoning wind the FIRST school-less
        // print pinned 0, mind blank the lone abjuration
    if (dimWJL8School(0) != 1
            || dimWJL8School(1) != 4
            || dimWJL8School(2) != 6
            || dimWJL8School(3) != 6
            || dimWJL8School(4) != 6
            || dimWJL8School(5) != 6
            || dimWJL8School(6) != 7
            || dimWJL8School(7) != 6
            || dimWJL8School(8) != 6
            || dimWJL8School(9) != 4
            || dimWJL8School(10) != 0
            || dimWJL8School(11) != 6
            || dimWJL8School(12) != 4
            || dimWJL8School(13) != 4
        )
            ++bad;
        // the component column - the 10 VSM spells, mind blank and summoning
        // wind the V,S pair, power word blind verbal-only, finding the center
        // somatic-only
    if (dimWJL8Components(0) != 7
            || dimWJL8Components(1) != 7
            || dimWJL8Components(2) != 7
            || dimWJL8Components(3) != 2
            || dimWJL8Components(4) != 7
            || dimWJL8Components(5) != 7
            || dimWJL8Components(6) != 3
            || dimWJL8Components(7) != 7
            || dimWJL8Components(8) != 7
            || dimWJL8Components(9) != 1
            || dimWJL8Components(10) != 3
            || dimWJL8Components(11) != 7
            || dimWJL8Components(12) != 7
            || dimWJL8Components(13) != 7
        )
            ++bad;
        // the casting time column - antipathy/sympathy 360, the four one-turn
        // casts, permanency 20, the one-round pair, symbol eight, cloud
        // trapeze five, incendiary cloud two, the three single segments
    if (dimWJL8CastTime(0) != 360
            || dimWJL8CastTime(1) != 60
            || dimWJL8CastTime(2) != 5
            || dimWJL8CastTime(3) != 1
            || dimWJL8CastTime(4) != 60
            || dimWJL8CastTime(5) != 2
            || dimWJL8CastTime(6) != 1
            || dimWJL8CastTime(7) != 20
            || dimWJL8CastTime(8) != 10
            || dimWJL8CastTime(9) != 1
            || dimWJL8CastTime(10) != 60
            || dimWJL8CastTime(11) != 10
            || dimWJL8CastTime(12) != 8
            || dimWJL8CastTime(13) != 60
        )
            ++bad;
        // the saving throw column - call the lone neg., the three special
        // saves, the two half saves, the other eight none
    if (dimWJL8Save(0) != 2
            || dimWJL8Save(1) != 1
            || dimWJL8Save(2) != 0
            || dimWJL8Save(3) != 0
            || dimWJL8Save(4) != 0
            || dimWJL8Save(5) != 3
            || dimWJL8Save(6) != 0
            || dimWJL8Save(7) != 0
            || dimWJL8Save(8) != 2
            || dimWJL8Save(9) != 0
            || dimWJL8Save(10) != 0
            || dimWJL8Save(11) != 0
            || dimWJL8Save(12) != 2
            || dimWJL8Save(13) != 3
        )
            ++bad;
        // the reversible column - giant size the one reversible spell of the
        // level
    if (dimWJL8Reversible(4) != 1
            || dimWJL8Reversible(0) != 0
            || dimWJL8Reversible(3) != 0
            || dimWJL8Reversible(6) != 0
            || dimWJL8Reversible(13) != 0
        )
            ++bad;
        // the element column - the four tagged cells matching the R669
        // dieWJT66L8Element grid exactly: three Air (cloud trapeze, summoning
        // wind, whirlwind), one Fire (incendiary cloud)
    if (dimWJL8Element(2) != 1
            || dimWJL8Element(5) != 3
            || dimWJL8Element(10) != 1
            || dimWJL8Element(13) != 1
            || dimWJL8Element(0) != 0
            || dimWJL8Element(1) != 0
            || dimWJL8Element(7) != 0
            || dimWJL8Element(12) != 0
        )
            ++bad;
        // the summoning wind line - the school-less print pinned 0 with the
        // V,S components, the one-turn cast, no save, the Air tag
    if (dimWJL8School(10) != 0
            || dimWJL8Components(10) != 3
            || dimWJL8CastTime(10) != 60
            || dimWJL8Save(10) != 0
            || dimWJL8Element(10) != 1
        )
            ++bad;
        printf("R677 OA wu jen eighth level spells audit: bad %d\n", bad);
        if (bad) return 1;
    }
