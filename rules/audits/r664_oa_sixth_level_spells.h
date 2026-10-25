    // ---- R664 OA sixth level spells audit ----
    // OA round fifty-one (capture pp. 143-147): the sixth level spell stat
    // blocks - the school, component, casting time and saving throw codes
    // with the reversible and sohei-usable markers, cross-checked spell by
    // spell between the passes
    {
        using namespace rules;
        int bad = 0;
    if (dhyL6SpellCount() != 12
            || dhyL6SoheiCount() != 4
            || dhyL6ReversibleCount() != 4
            || dhyL6AlterationCount() != 5
            || dhyL6VSMCount() != 8
            || dhyL6VSCount() != 3
            || dhyL6VerbalOnlyCount() != 1
            || dhyL6DayCasts() != 1
            || dhyL6ThreeTurnCasts() != 1
            || dhyL6ThreeRoundCasts() != 1
            || dhyL6RoundCasts() != 4
            || dhyL6OneSegmentCasts() != 3
            || dhyL6NegSaves() != 2
            || dhyL6SpecialSaves() != 1
            || dhyL6HalfSaves() != 2
        )
            ++bad;
        // the sixth level stat grid: the school, component, casting time and
        // saving throw codes with the reversible and sohei markers by spell
        // ordinal
        int CL6Data[12][6] = {
            {2,7,30,0,1,1},
            {7,7,1,3,0,0},
            {5,3,10,0,1,0},
            {6,3,1,0,1,1},
            {4,7,10,0,0,0},
            {1,1,180,1,0,0},
            {9,7,10,0,0,0},
            {6,7,8640,2,0,0},
            {6,7,8,1,0,0},
            {6,7,10,0,1,0},
            {3,7,1,3,0,1},
            {6,3,9,0,0,1},
            };
        for (int b = 0;
             b < dhyL6SpellCount();
             ++b) {
            int vals[6];
            vals[0] = dhyL6School(b);
            vals[1] = dhyL6Components(b);
            vals[2] = dhyL6CastTime(b);
            vals[3] = dhyL6Save(b);
            vals[4] = dhyL6Reversible(b);
            vals[5] = dhyL6Sohei(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CL6Data[b][c])
                    ++bad;
            }
        }
        // the count pins - twelve sixth level spells, four sohei-usable, four
        // reversible, five alteration
    if (dhyL6SpellCount() != 12
            || dhyL6SoheiCount() != 4
            || dhyL6ReversibleCount() != 4
            || dhyL6AlterationCount() != 5
            || dhyL6VSMCount() != 8
            || dhyL6VSCount() != 3
            || dhyL6VerbalOnlyCount() != 1
        )
            ++bad;
        // the school pins - find the path divination; force shapechange
        // abjuration; heal necromantic; inanimate servant conjuration;
        // instruct enchantment/charm; invisibility to enemies
        // illusion/phantasm; smite evocation; immunity to weapons, longevity,
        // plane shift, quickgrowth and speak w/ monsters alteration
    if (dhyL6School(0) != 2
            || dhyL6School(1) != 7
            || dhyL6School(2) != 5
            || dhyL6School(4) != 4
            || dhyL6School(5) != 1
            || dhyL6School(6) != 9
            || dhyL6School(10) != 3
            || dhyL6School(3) != 6
            || dhyL6School(7) != 6
            || dhyL6School(8) != 6
            || dhyL6School(9) != 6
            || dhyL6School(11) != 6
        )
            ++bad;
        // the component pins - the three verbal and somatic (heal, immunity
        // to weapons, speak w/ monsters); instruct the verbal only; the eight
        // all-component with find the path, force shapechange, longevity and
        // smite pinned
    if (dhyL6Components(2) != 3
            || dhyL6Components(3) != 3
            || dhyL6Components(11) != 3
            || dhyL6Components(5) != 1
            || dhyL6Components(0) != 7
            || dhyL6Components(1) != 7
            || dhyL6Components(7) != 7
            || dhyL6Components(10) != 7
            || dhyL6Components(4) != 7
            || dhyL6Components(9) != 7
        )
            ++bad;
        // the casting time pins - longevity the one-day cast 8640 (the
        // longest in the chapter); instruct three turns; find the path three
        // rounds; the four one-round casts; plane shift eight segments; speak
        // w/ monsters nine; the three single-segment casts (force
        // shapechange, immunity to weapons, smite)
    if (dhyL6CastTime(7) != 8640
            || dhyL6CastTime(5) != 180
            || dhyL6CastTime(0) != 30
            || dhyL6CastTime(2) != 10
            || dhyL6CastTime(4) != 10
            || dhyL6CastTime(6) != 10
            || dhyL6CastTime(9) != 10
            || dhyL6CastTime(8) != 8
            || dhyL6CastTime(11) != 9
            || dhyL6CastTime(1) != 1
            || dhyL6CastTime(3) != 1
            || dhyL6CastTime(10) != 1
        )
            ++bad;
        // the saving throw pins - instruct and plane shift neg.; longevity
        // special; force shapechange and smite the half code; the seven
        // others none
    if (dhyL6Save(5) != 1
            || dhyL6Save(8) != 1
            || dhyL6Save(7) != 2
            || dhyL6Save(1) != 3
            || dhyL6Save(10) != 3
            || dhyL6Save(0) != 0
            || dhyL6Save(2) != 0
            || dhyL6Save(11) != 0
        )
            ++bad;
        // the reversible pins - find the path, heal, immunity to weapons and
        // quickgrowth marked; force shapechange, longevity and smite not -
        // the four matching the R658 T62 reversible column
    if (dhyL6Reversible(0) != 1
            || dhyL6Reversible(2) != 1
            || dhyL6Reversible(3) != 1
            || dhyL6Reversible(9) != 1
            || dhyL6Reversible(1) != 0
            || dhyL6Reversible(7) != 0
            || dhyL6Reversible(10) != 0
        )
            ++bad;
        // the sohei pins - find the path, immunity to weapons, smite and
        // speak w/ monsters marked; heal, instruct and longevity not - the
        // four matching the R658 T62 sohei column
    if (dhyL6Sohei(0) != 1
            || dhyL6Sohei(3) != 1
            || dhyL6Sohei(10) != 1
            || dhyL6Sohei(11) != 1
            || dhyL6Sohei(2) != 0
            || dhyL6Sohei(5) != 0
            || dhyL6Sohei(7) != 0
        )
            ++bad;
        // the grid-sum pins - eight VSM, three VS and the instruct verbal
        // only; the one-day, three-turn and three-round casts; four one-round
        // and three one-segment casts; two neg., one special and two half
        // saves
    if (dhyL6DayCasts() != 1
            || dhyL6ThreeTurnCasts() != 1
            || dhyL6ThreeRoundCasts() != 1
            || dhyL6RoundCasts() != 4
            || dhyL6OneSegmentCasts() != 3
            || dhyL6NegSaves() != 2
            || dhyL6SpecialSaves() != 1
            || dhyL6HalfSaves() != 2
        )
            ++bad;
        printf("R664 OA sixth level spells audit: bad %d\n", bad);
        if (bad) return 1;
    }
