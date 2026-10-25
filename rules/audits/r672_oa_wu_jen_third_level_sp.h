    // ---- R672 OA wu jen third level spells audit ----
    // OA round fifty-nine (capture pp. 173-181): the wu jen third level spell
    // stat blocks - the school, component, casting time and saving throw
    // codes with the reversible and element markers, cross-checked spell by
    // spell between the passes
    {
        using namespace rules;
        int bad = 0;
    if (dihWJL3SpellCount() != 24
            || dihWJL3AlterationCount() != 7
            || dihWJL3EnchantmentCount() != 4
            || dihWJL3IllusionCount() != 4
            || dihWJL3DivinationCount() != 3
            || dihWJL3ReversibleCount() != 4
            || dihWJL3VSMCount() != 19
            || dihWJL3VSCount() != 2
            || dihWJL3VMCount() != 2
            || dihWJL3VerbalOnlyCount() != 1
            || dihWJL3SpecialCasts() != 3
            || dihWJL3TurnCasts() != 4
            || dihWJL3RoundCasts() != 5
            || dihWJL3ThreeSegmentCasts() != 7
            || dihWJL3FiveSegmentCasts() != 2
            || dihWJL3SevenSegmentCasts() != 1
            || dihWJL3NegSaves() != 4
            || dihWJL3SpecialSaves() != 4
            || dihWJL3HalfSaves() != 2
            || dihWJL3ElementCount() != 7
        )
            ++bad;
        // the wu jen third level stat grid: the school, component, casting
        // time and saving throw codes with the reversible and element markers
        // by spell ordinal
        int CWJL3Data[24][6] = {
            {4,7,10,0,0,3},
            {6,7,5,0,0,8},
            {2,7,60,0,0,0},
            {2,7,10,0,0,0},
            {9,7,60,2,0,0},
            {7,3,3,0,0,0},
            {1,7,-1,0,0,0},
            {9,7,60,2,1,0},
            {5,3,1,0,0,0},
            {3,7,5,3,0,0},
            {6,7,10,0,0,0},
            {6,7,3,0,0,0},
            {1,1,3,1,0,0},
            {9,7,-1,0,0,0},
            {9,7,2,2,0,0},
            {6,7,3,1,1,2},
            {1,7,-1,1,1,0},
            {7,7,3,0,0,0},
            {3,7,10,3,0,1},
            {2,7,60,0,0,7},
            {6,7,7,2,0,2},
            {1,5,3,1,0,0},
            {6,5,3,0,1,0},
            {6,7,10,0,0,5},
            };
        for (int b = 0;
             b < dihWJL3SpellCount();
             ++b) {
            int vals[6];
            vals[0] = dihWJL3School(b);
            vals[1] = dihWJL3Components(b);
            vals[2] = dihWJL3CastTime(b);
            vals[3] = dihWJL3Save(b);
            vals[4] = dihWJL3Reversible(b);
            vals[5] = dihWJL3Element(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CWJL3Data[b][c])
                    ++bad;
            }
        }
        // the count pins - 24 spells, seven alteration, four
        // enchantment/charm, four illusion, three divination, four reversible
    if (dihWJL3SpellCount() != 24
            || dihWJL3AlterationCount() != 7
            || dihWJL3EnchantmentCount() != 4
            || dihWJL3IllusionCount() != 4
            || dihWJL3DivinationCount() != 3
            || dihWJL3ReversibleCount() != 4
        )
            ++bad;
        // the component pins - 19 VSM, two VS, suggestion and tongues the V,M
        // pairs, hold person the verbal only
    if (dihWJL3VSMCount() != 19
            || dihWJL3VSCount() != 2
            || dihWJL3VMCount() != 2
            || dihWJL3VerbalOnlyCount() != 1
        )
            ++bad;
        // the casting time pins - three Special casts (-1), four turn casts,
        // five round casts, seven three-segment, two five-segment, statue the
        // seven
    if (dihWJL3SpecialCasts() != 3
            || dihWJL3TurnCasts() != 4
            || dihWJL3RoundCasts() != 5
            || dihWJL3ThreeSegmentCasts() != 7
            || dihWJL3FiveSegmentCasts() != 2
            || dihWJL3SevenSegmentCasts() != 1
        )
            ++bad;
        // the saving throw pins - four neg., four special, fire rain and
        // steam breath the two half
    if (dihWJL3NegSaves() != 4
            || dihWJL3SpecialSaves() != 4
            || dihWJL3HalfSaves() != 2
            || dihWJL3ElementCount() != 7
        )
            ++bad;
        // the school pins - feign death the lone necromantic; animate fire
        // the lone conjuration; dispel magic and protection from normal
        // missiles abjuration; fire rain and steam breath evocation; commune,
        // detect shapechanger and scry divination; the four
        // enchantment/charm; the four illusion; cloudburst, fire wings, haste
        // and tongues among the seven alteration
    if (dihWJL3School(8) != 5
            || dihWJL3School(0) != 4
            || dihWJL3School(5) != 7
            || dihWJL3School(17) != 7
            || dihWJL3School(9) != 3
            || dihWJL3School(18) != 3
            || dihWJL3School(2) != 2
            || dihWJL3School(3) != 2
            || dihWJL3School(19) != 2
            || dihWJL3School(6) != 1
            || dihWJL3School(12) != 1
            || dihWJL3School(16) != 1
            || dihWJL3School(21) != 1
            || dihWJL3School(4) != 9
            || dihWJL3School(7) != 9
            || dihWJL3School(13) != 9
            || dihWJL3School(14) != 9
            || dihWJL3School(1) != 6
            || dihWJL3School(10) != 6
            || dihWJL3School(11) != 6
            || dihWJL3School(22) != 6
        )
            ++bad;
        // the component cell pins - the verbal-only hold person, the V,M
        // suggestion and tongues, the VS dispel magic and feign death, and
        // the VSM spots
    if (dihWJL3Components(12) != 1
            || dihWJL3Components(21) != 5
            || dihWJL3Components(22) != 5
            || dihWJL3Components(5) != 3
            || dihWJL3Components(8) != 3
            || dihWJL3Components(0) != 7
            || dihWJL3Components(1) != 7
            || dihWJL3Components(19) != 7
            || dihWJL3Components(20) != 7
            || dihWJL3Components(23) != 7
        )
            ++bad;
        // the casting time cell pins - the three Special casts at -1, the
        // turn casts, statue the seven, cloudburst and fire rain the five,
        // feign death the lone segment
    if (dihWJL3CastTime(6) != -1
            || dihWJL3CastTime(13) != -1
            || dihWJL3CastTime(16) != -1
            || dihWJL3CastTime(2) != 60
            || dihWJL3CastTime(4) != 60
            || dihWJL3CastTime(7) != 60
            || dihWJL3CastTime(19) != 60
            || dihWJL3CastTime(20) != 7
            || dihWJL3CastTime(1) != 5
            || dihWJL3CastTime(9) != 5
            || dihWJL3CastTime(8) != 1
            || dihWJL3CastTime(14) != 2
        )
            ++bad;
        // the saving throw cell pins - the four negation saves, the four
        // special saves, the two half, animate fire none
    if (dihWJL3Save(12) != 1
            || dihWJL3Save(15) != 1
            || dihWJL3Save(16) != 1
            || dihWJL3Save(21) != 1
            || dihWJL3Save(4) != 2
            || dihWJL3Save(7) != 2
            || dihWJL3Save(14) != 2
            || dihWJL3Save(20) != 2
            || dihWJL3Save(9) != 3
            || dihWJL3Save(18) != 3
            || dihWJL3Save(0) != 0
        )
            ++bad;
        // the reversible pins - face, magnetism, memory and tongues marked;
        // haste, dispel magic and feign death not
    if (dihWJL3Reversible(7) != 1
            || dihWJL3Reversible(15) != 1
            || dihWJL3Reversible(16) != 1
            || dihWJL3Reversible(22) != 1
            || dihWJL3Reversible(11) != 0
            || dihWJL3Reversible(5) != 0
            || dihWJL3Reversible(8) != 0
            || dihWJL3Reversible(0) != 0
        )
            ++bad;
        // the element cross-check pins - the seven tagged cells matching the
        // R669 dieWJT66L3Element grid: animate fire Fire, cloudburst the
        // Water/Air dual 8, magnetism and statue Earth, steam breath Air,
        // scry All, wood shape Nature; haste untagged
    if (dihWJL3Element(0) != 3
            || dihWJL3Element(1) != 8
            || dihWJL3Element(15) != 2
            || dihWJL3Element(20) != 2
            || dihWJL3Element(18) != 1
            || dihWJL3Element(19) != 7
            || dihWJL3Element(23) != 5
            || dihWJL3Element(11) != 0
            || dihWJL3Element(6) != 0
        )
            ++bad;
        printf("R672 OA wu jen third level spells audit: bad %d\n", bad);
        if (bad) return 1;
    }
