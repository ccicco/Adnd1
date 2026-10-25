    // ---- R676 OA wu jen seventh level spells audit ----
    // OA round sixty-three (capture pp. 203-207): the wu jen seventh level
    // spell stat blocks - the school, component, casting time and saving
    // throw codes with the reversible and element markers, cross-checked
    // spell by spell between the passes
    {
        using namespace rules;
        int bad = 0;
    if (dilWJL7SpellCount() != 12
            || dilWJL7ConjurationCount() != 5
            || dilWJL7DualSchoolCount() != 3
            || dilWJL7ReversibleCount() != 1
            || dilWJL7VSMCount() != 7
            || dilWJL7VerbalOnlyCount() != 4
            || dilWJL7SpecialCasts() != 1
            || dilWJL7TurnCasts() != 3
            || dilWJL7OneSegmentCasts() != 3
            || dilWJL7NegSaves() != 2
            || dilWJL7SpecialSaves() != 2
            || dilWJL7ElementCount() != 1
        )
            ++bad;
        // the stat grid - one cell per spell and column, every grid cell
        // pinned from the stat blocks cross-checked between the passes
        int CWJL7Data[12][6] = {
            {4,7,1,0,0,0},
            {2,7,60,0,0,0},
            {6,7,7,0,0,0},
            {4,7,60,1,0,0},
            {3,7,60,0,1,4},
            {4,1,-1,2,0,0},
            {1,7,10,1,0,0},
            {4,1,1,0,0,0},
            {5,7,10,2,0,0},
            {4,1,1,0,0,0},
            {6,1,2,0,0,0},
            {3,3,4,3,0,0},
            };
        for (int b = 0;
             b < dilWJL7SpellCount();
             ++b) {
            int vals[6];
            vals[0] = dilWJL7School(b);
            vals[1] = dilWJL7Components(b);
            vals[2] = dilWJL7CastTime(b);
            vals[3] = dilWJL7Save(b);
            vals[4] = dilWJL7Reversible(b);
            vals[5] = dilWJL7Element(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CWJL7Data[b][c])
                    ++bad;
            }
        }
        // the count pins - 12 spells, five conjuration, three dual-school
        // prints, one reversible, one element-tagged
    if (dilWJL7SpellCount() != 12
            || dilWJL7ConjurationCount() != 5
            || dilWJL7DualSchoolCount() != 3
            || dilWJL7ReversibleCount() != 1
            || dilWJL7ElementCount() != 1
        )
            ++bad;
        // the component pins - seven VSM, FOUR verbal-only spells (the most
        // of any wu jen level yet)
    if (dilWJL7VSMCount() != 7
            || dilWJL7VerbalOnlyCount() != 4
        )
            ++bad;
        // the casting time pins - limited wish the lone Special cast (-1),
        // three one-turn, three single segments
    if (dilWJL7SpecialCasts() != 1
            || dilWJL7TurnCasts() != 3
            || dilWJL7OneSegmentCasts() != 3
        )
            ++bad;
        // the saving throw pins - two neg., two special, withering palm the
        // lone half save
    if (dilWJL7NegSaves() != 2
            || dilWJL7SpecialSaves() != 2
        )
            ++bad;
        // the school column - the three duals pinned primary: elemental
        // servant 4, ice blight 3, obedience 1; conjuration five; commune
        // with greater spirit the lone divination, reanimation the lone
        // necromantic
    if (dilWJL7School(0) != 4
            || dilWJL7School(1) != 2
            || dilWJL7School(2) != 6
            || dilWJL7School(3) != 4
            || dilWJL7School(4) != 3
            || dilWJL7School(5) != 4
            || dilWJL7School(6) != 1
            || dilWJL7School(7) != 4
            || dilWJL7School(8) != 5
            || dilWJL7School(9) != 4
            || dilWJL7School(10) != 6
            || dilWJL7School(11) != 3
        )
            ++bad;
        // the component column - the four verbal-only spells (limited wish,
        // power word stun, tool, vanish), withering palm the lone V,S, the
        // other seven VSM
    if (dilWJL7Components(0) != 7
            || dilWJL7Components(1) != 7
            || dilWJL7Components(2) != 7
            || dilWJL7Components(3) != 7
            || dilWJL7Components(4) != 7
            || dilWJL7Components(5) != 1
            || dilWJL7Components(6) != 7
            || dilWJL7Components(7) != 1
            || dilWJL7Components(8) != 7
            || dilWJL7Components(9) != 1
            || dilWJL7Components(10) != 1
            || dilWJL7Components(11) != 3
        )
            ++bad;
        // the casting time column - limited wish the lone Special (-1), the
        // three one-turn casts, the three single segments, obedience and
        // reanimation the one-round casts, duo-dimension seven, vanish two,
        // withering palm four segments
    if (dilWJL7CastTime(0) != 1
            || dilWJL7CastTime(1) != 60
            || dilWJL7CastTime(2) != 7
            || dilWJL7CastTime(3) != 60
            || dilWJL7CastTime(4) != 60
            || dilWJL7CastTime(5) != -1
            || dilWJL7CastTime(6) != 10
            || dilWJL7CastTime(7) != 1
            || dilWJL7CastTime(8) != 10
            || dilWJL7CastTime(9) != 1
            || dilWJL7CastTime(10) != 2
            || dilWJL7CastTime(11) != 4
        )
            ++bad;
        // the saving throw column - elemental servant and obedience neg.,
        // limited wish and reanimation special, withering palm the lone half
        // save, the other seven none
    if (dilWJL7Save(0) != 0
            || dilWJL7Save(1) != 0
            || dilWJL7Save(2) != 0
            || dilWJL7Save(3) != 1
            || dilWJL7Save(4) != 0
            || dilWJL7Save(5) != 2
            || dilWJL7Save(6) != 1
            || dilWJL7Save(7) != 0
            || dilWJL7Save(8) != 2
            || dilWJL7Save(9) != 0
            || dilWJL7Save(10) != 0
            || dilWJL7Save(11) != 3
        )
            ++bad;
        // the reversible column - ice blight (drought) the one reversible
        // spell of the level
    if (dilWJL7Reversible(4) != 1
            || dilWJL7Reversible(0) != 0
            || dilWJL7Reversible(3) != 0
            || dilWJL7Reversible(5) != 0
            || dilWJL7Reversible(11) != 0
        )
            ++bad;
        // the element column - ice blight Water the one tagged cell, matching
        // the R669 dieWJT66L7Element pin exactly
    if (dilWJL7Element(4) != 4
            || dilWJL7Element(0) != 0
            || dilWJL7Element(3) != 0
            || dilWJL7Element(5) != 0
            || dilWJL7Element(11) != 0
        )
            ++bad;
        // the limited wish line - the lone Special cast pinned -1 AND the
        // special save, verbal-only, conjuration school
    if (dilWJL7CastTime(5) != -1
            || dilWJL7Save(5) != 2
            || dilWJL7Components(5) != 1
            || dilWJL7School(5) != 4
        )
            ++bad;
        printf("R676 OA wu jen seventh level spells audit: bad %d\n", bad);
        if (bad) return 1;
    }
