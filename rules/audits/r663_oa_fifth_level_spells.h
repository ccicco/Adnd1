    // ---- R663 OA fifth level spells audit ----
    // OA round fifty (capture pp. 140-143): the fifth level spell stat blocks
    // - the school, component, casting time and saving throw codes with the
    // reversible and sohei-usable markers, cross-checked spell by spell
    // between the passes
    {
        using namespace rules;
        int bad = 0;
    if (dhxL5SpellCount() != 12
            || dhxL5SoheiCount() != 4
            || dhxL5ReversibleCount() != 6
            || dhxL5AlterationCount() != 3
            || dhxL5DivinationCount() != 3
            || dhxL5EnchCharmCount() != 2
            || dhxL5AbjurationCount() != 2
            || dhxL5NecromanticCount() != 2
            || dhxL5VSMCount() != 9
            || dhxL5VSCount() != 2
            || dhxL5VerbalOnlyCount() != 1
            || dhxL5TurnCasts() != 5
            || dhxL5RoundCasts() != 1
            || dhxL5EightSegmentCasts() != 3
            || dhxL5FiveSegmentCasts() != 2
            || dhxL5OneSegmentCasts() != 1
            || dhxL5NegSaves() != 3
            || dhxL5SpecialSaves() != 2
        )
            ++bad;
        // the fifth level stat grid: the school, component, casting time and
        // saving throw codes with the reversible and sohei markers by spell
        // ordinal
        int CL5Data[12][6] = {
            {1,1,5,1,0,0},
            {6,7,1,0,0,0},
            {7,7,60,0,0,0},
            {2,7,60,0,0,0},
            {5,3,8,0,1,0},
            {7,7,8,1,1,1},
            {6,7,5,0,1,1},
            {1,7,60,1,0,0},
            {5,3,10,2,1,0},
            {2,7,60,2,1,0},
            {6,7,60,0,0,1},
            {2,7,8,0,1,1},
            };
        for (int b = 0;
             b < dhxL5SpellCount();
             ++b) {
            int vals[6];
            vals[0] = dhxL5School(b);
            vals[1] = dhxL5Components(b);
            vals[2] = dhxL5CastTime(b);
            vals[3] = dhxL5Save(b);
            vals[4] = dhxL5Reversible(b);
            vals[5] = dhxL5Sohei(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CL5Data[b][c])
                    ++bad;
            }
        }
        // the count pins - twelve fifth level spells, four sohei-usable, six
        // reversible, the alteration and divination tie at three
    if (dhxL5SpellCount() != 12
            || dhxL5SoheiCount() != 4
            || dhxL5ReversibleCount() != 6
            || dhxL5AlterationCount() != 3
            || dhxL5DivinationCount() != 3
            || dhxL5EnchCharmCount() != 2
            || dhxL5AbjurationCount() != 2
            || dhxL5NecromanticCount() != 2
        )
            ++bad;
        // the school pins - advice and possess enchantment/charm; air walk,
        // mental strength and strength alteration; atonement and dispel evil
        // abjuration; commune w/ greater spirit, remember and true seeing
        // divination; cure critical wounds and raise dead necromantic
    if (dhxL5School(0) != 1
            || dhxL5School(7) != 1
            || dhxL5School(1) != 6
            || dhxL5School(6) != 6
            || dhxL5School(10) != 6
            || dhxL5School(2) != 7
            || dhxL5School(5) != 7
            || dhxL5School(3) != 2
            || dhxL5School(9) != 2
            || dhxL5School(11) != 2
            || dhxL5School(4) != 5
            || dhxL5School(8) != 5
        )
            ++bad;
        // the component pins - advice the verbal only (1); cure critical
        // wounds and raise dead the verbal and somatic (3); air walk,
        // atonement and true seeing the all-component (7)
    if (dhxL5Components(0) != 1
            || dhxL5Components(4) != 3
            || dhxL5Components(8) != 3
            || dhxL5Components(1) != 7
            || dhxL5Components(2) != 7
            || dhxL5Components(11) != 7
            || dhxL5Components(6) != 7
            || dhxL5Components(10) != 7
        )
            ++bad;
        // the casting time pins - the five one-turn casts (atonement, commune
        // w/ greater spirit, possess, remember, strength); raise dead the
        // round; the eight-segment casts (cure critical wounds, dispel evil,
        // true seeing); advice and mental strength five; air walk the single
        // segment
    if (dhxL5CastTime(2) != 60
            || dhxL5CastTime(3) != 60
            || dhxL5CastTime(7) != 60
            || dhxL5CastTime(9) != 60
            || dhxL5CastTime(10) != 60
            || dhxL5CastTime(8) != 10
            || dhxL5CastTime(4) != 8
            || dhxL5CastTime(5) != 8
            || dhxL5CastTime(11) != 8
            || dhxL5CastTime(0) != 5
            || dhxL5CastTime(6) != 5
            || dhxL5CastTime(1) != 1
        )
            ++bad;
        // the saving throw pins - advice, dispel evil and possess neg.; raise
        // dead and remember special; the seven others none
    if (dhxL5Save(0) != 1
            || dhxL5Save(5) != 1
            || dhxL5Save(7) != 1
            || dhxL5Save(8) != 2
            || dhxL5Save(9) != 2
            || dhxL5Save(1) != 0
            || dhxL5Save(2) != 0
            || dhxL5Save(11) != 0
        )
            ++bad;
        // the reversible pins - cure critical wounds, dispel evil, mental
        // strength, raise dead, remember and true seeing marked; advice, air
        // walk and strength not - the six matching the R658 T62 reversible
        // column
    if (dhxL5Reversible(4) != 1
            || dhxL5Reversible(5) != 1
            || dhxL5Reversible(6) != 1
            || dhxL5Reversible(8) != 1
            || dhxL5Reversible(9) != 1
            || dhxL5Reversible(11) != 1
            || dhxL5Reversible(0) != 0
            || dhxL5Reversible(1) != 0
            || dhxL5Reversible(10) != 0
        )
            ++bad;
        // the sohei pins - dispel evil, mental strength, strength and true
        // seeing marked; advice, atonement and raise dead not - the four
        // matching the R658 T62 sohei column
    if (dhxL5Sohei(5) != 1
            || dhxL5Sohei(6) != 1
            || dhxL5Sohei(10) != 1
            || dhxL5Sohei(11) != 1
            || dhxL5Sohei(0) != 0
            || dhxL5Sohei(2) != 0
            || dhxL5Sohei(8) != 0
        )
            ++bad;
        // the grid-sum pins - nine VSM, two VS and the advice verbal only;
        // five one-turn and three eight-segment casts; three neg. and two
        // special saves
    if (dhxL5VSMCount() != 9
            || dhxL5VSCount() != 2
            || dhxL5VerbalOnlyCount() != 1
            || dhxL5TurnCasts() != 5
            || dhxL5RoundCasts() != 1
            || dhxL5EightSegmentCasts() != 3
            || dhxL5FiveSegmentCasts() != 2
            || dhxL5OneSegmentCasts() != 1
            || dhxL5NegSaves() != 3
            || dhxL5SpecialSaves() != 2
        )
            ++bad;
        printf("R663 OA fifth level spells audit: bad %d\n", bad);
        if (bad) return 1;
    }
