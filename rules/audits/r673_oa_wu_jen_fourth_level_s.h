    // ---- R673 OA wu jen fourth level spells audit ----
    // OA round sixty (capture pp. 181-188): the wu jen fourth level spell
    // stat blocks - the school, component, casting time and saving throw
    // codes with the reversible and element markers, cross-checked spell by
    // spell between the passes
    {
        using namespace rules;
        int bad = 0;
    if (diiWJL4SpellCount() != 24
            || diiWJL4AlterationCount() != 6
            || diiWJL4EnchantmentCount() != 6
            || diiWJL4EvocationCount() != 4
            || diiWJL4AbjurationCount() != 3
            || diiWJL4InvocationCount() != 2
            || diiWJL4IllusionCount() != 2
            || diiWJL4ReversibleCount() != 3
            || diiWJL4VSMCount() != 13
            || diiWJL4VSCount() != 7
            || diiWJL4VerbalOnlyCount() != 3
            || diiWJL4VMCount() != 1
            || diiWJL4FourSegmentCasts() != 7
            || diiWJL4RoundCasts() != 7
            || diiWJL4TurnCasts() != 3
            || diiWJL4ThreeSegmentCasts() != 4
            || diiWJL4OneSegmentCasts() != 2
            || diiWJL4FiveSegmentCasts() != 1
            || diiWJL4NegSaves() != 8
            || diiWJL4SpecialSaves() != 3
            || diiWJL4ElementCount() != 7
        )
            ++bad;
        // the wu jen fourth level stat grid: the school, component, casting
        // time and saving throw codes with the reversible and element markers
        // by spell ordinal
        int CWJL4Data[24][6] = {
            {1,7,10,1,0,0},
            {1,7,4,2,0,0},
            {3,7,10,0,0,0},
            {6,1,1,0,0,2},
            {7,3,3,0,0,0},
            {8,7,60,0,1,0},
            {7,7,5,1,0,7},
            {1,3,4,1,0,0},
            {1,7,10,1,0,3},
            {9,3,4,0,0,0},
            {3,7,10,0,0,3},
            {6,7,60,0,0,0},
            {6,3,4,0,0,5},
            {6,7,4,1,0,5},
            {6,1,3,0,0,0},
            {1,3,3,1,0,0},
            {7,3,4,2,1,0},
            {6,3,60,0,1,0},
            {3,5,1,1,0,0},
            {9,7,3,2,0,0},
            {1,7,10,1,0,0},
            {8,1,10,0,0,0},
            {4,7,10,0,0,0},
            {3,7,4,0,0,3},
            };
        for (int b = 0;
             b < diiWJL4SpellCount();
             ++b) {
            int vals[6];
            vals[0] = diiWJL4School(b);
            vals[1] = diiWJL4Components(b);
            vals[2] = diiWJL4CastTime(b);
            vals[3] = diiWJL4Save(b);
            vals[4] = diiWJL4Reversible(b);
            vals[5] = diiWJL4Element(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CWJL4Data[b][c])
                    ++bad;
            }
        }
        // the count pins - 24 spells, six alteration, six enchantment/charm,
        // four evocation, three abjuration, two invocation, two illusion,
        // three reversible
    if (diiWJL4SpellCount() != 24
            || diiWJL4AlterationCount() != 6
            || diiWJL4EnchantmentCount() != 6
            || diiWJL4EvocationCount() != 4
            || diiWJL4AbjurationCount() != 3
            || diiWJL4InvocationCount() != 2
            || diiWJL4IllusionCount() != 2
            || diiWJL4ReversibleCount() != 3
        )
            ++bad;
        // the component pins - 13 VSM, seven VS, the three verbal-only
        // spells, shout the lone V,M
    if (diiWJL4VSMCount() != 13
            || diiWJL4VSCount() != 7
            || diiWJL4VerbalOnlyCount() != 3
            || diiWJL4VMCount() != 1
        )
            ++bad;
        // the casting time pins - seven four-segment, seven round casts,
        // three turn casts, four three-segment, two single-segment, elemental
        // turning the lone five
    if (diiWJL4FourSegmentCasts() != 7
            || diiWJL4RoundCasts() != 7
            || diiWJL4TurnCasts() != 3
            || diiWJL4ThreeSegmentCasts() != 4
            || diiWJL4OneSegmentCasts() != 2
            || diiWJL4FiveSegmentCasts() != 1
        )
            ++bad;
        // the saving throw pins - eight neg., three special, the seven
        // element tags
    if (diiWJL4NegSaves() != 8
            || diiWJL4SpecialSaves() != 3
            || diiWJL4ElementCount() != 7
        )
            ++bad;
        // the school pins - wall of bones the dual Conjuration/Necromantic
        // pinned primary 4; dream vision and vengeance the debuting
        // invocation 8; dispel illusion, elemental turning and remove curse
        // abjuration; improved invisibility and spectral force illusion;
        // dancing blade, melt metal, shout and wall of fire evocation;
        // bargain and quell among the six enchantment/charm; dimension door
        // and plant growth among the six alteration
    if (diiWJL4School(22) != 4
            || diiWJL4School(5) != 8
            || diiWJL4School(21) != 8
            || diiWJL4School(4) != 7
            || diiWJL4School(6) != 7
            || diiWJL4School(16) != 7
            || diiWJL4School(9) != 9
            || diiWJL4School(19) != 9
            || diiWJL4School(2) != 3
            || diiWJL4School(10) != 3
            || diiWJL4School(18) != 3
            || diiWJL4School(23) != 3
            || diiWJL4School(0) != 1
            || diiWJL4School(1) != 1
            || diiWJL4School(7) != 1
            || diiWJL4School(8) != 1
            || diiWJL4School(15) != 1
            || diiWJL4School(20) != 1
            || diiWJL4School(3) != 6
            || diiWJL4School(11) != 6
            || diiWJL4School(12) != 6
            || diiWJL4School(13) != 6
            || diiWJL4School(14) != 6
            || diiWJL4School(17) != 6
        )
            ++bad;
        // the component cell pins - the three verbal-only spells, the V,M
        // shout, the VS set, and the VSM spots
    if (diiWJL4Components(3) != 1
            || diiWJL4Components(14) != 1
            || diiWJL4Components(21) != 1
            || diiWJL4Components(18) != 5
            || diiWJL4Components(4) != 3
            || diiWJL4Components(7) != 3
            || diiWJL4Components(9) != 3
            || diiWJL4Components(12) != 3
            || diiWJL4Components(15) != 3
            || diiWJL4Components(16) != 3
            || diiWJL4Components(17) != 3
            || diiWJL4Components(0) != 7
            || diiWJL4Components(2) != 7
            || diiWJL4Components(22) != 7
        )
            ++bad;
        // the casting time cell pins - the two single segments, elemental
        // turning the five, the turn casts, spectral force three, and the
        // four-segment spots
    if (diiWJL4CastTime(3) != 1
            || diiWJL4CastTime(18) != 1
            || diiWJL4CastTime(6) != 5
            || diiWJL4CastTime(5) != 60
            || diiWJL4CastTime(11) != 60
            || diiWJL4CastTime(17) != 60
            || diiWJL4CastTime(19) != 3
            || diiWJL4CastTime(14) != 3
            || diiWJL4CastTime(15) != 3
            || diiWJL4CastTime(4) != 3
            || diiWJL4CastTime(1) != 4
            || diiWJL4CastTime(7) != 4
            || diiWJL4CastTime(23) != 4
            || diiWJL4CastTime(13) != 4
            || diiWJL4CastTime(20) != 10
            || diiWJL4CastTime(22) != 10
        )
            ++bad;
        // the saving throw cell pins - the eight negation saves, the three
        // special saves, dancing blade none
    if (diiWJL4Save(0) != 1
            || diiWJL4Save(6) != 1
            || diiWJL4Save(7) != 1
            || diiWJL4Save(8) != 1
            || diiWJL4Save(13) != 1
            || diiWJL4Save(15) != 1
            || diiWJL4Save(18) != 1
            || diiWJL4Save(20) != 1
            || diiWJL4Save(1) != 2
            || diiWJL4Save(16) != 2
            || diiWJL4Save(19) != 2
            || diiWJL4Save(2) != 0
        )
            ++bad;
        // the reversible pins - dream vision, remove curse and reverse flow
        // marked; bargain, confusion and wall of fire not
    if (diiWJL4Reversible(5) != 1
            || diiWJL4Reversible(16) != 1
            || diiWJL4Reversible(17) != 1
            || diiWJL4Reversible(0) != 0
            || diiWJL4Reversible(1) != 0
            || diiWJL4Reversible(23) != 0
            || diiWJL4Reversible(13) != 0
        )
            ++bad;
        // the element cross-check pins - the seven tagged cells matching the
        // R669 dieWJT66L4Element grid: dimension door Earth, elemental
        // turning All, fire enchantment, melt metal and wall of fire Fire,
        // plant growth and polymorph other Nature; confusion untagged
    if (diiWJL4Element(3) != 2
            || diiWJL4Element(6) != 7
            || diiWJL4Element(8) != 3
            || diiWJL4Element(10) != 3
            || diiWJL4Element(23) != 3
            || diiWJL4Element(12) != 5
            || diiWJL4Element(13) != 5
            || diiWJL4Element(1) != 0
            || diiWJL4Element(0) != 0
        )
            ++bad;
        printf("R673 OA wu jen fourth level spells audit: bad %d\n", bad);
        if (bad) return 1;
    }
