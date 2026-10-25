    // ---- R670 OA wu jen first level spells audit ----
    // OA round fifty-seven (capture pp. 155-165): the wu jen first level
    // spell stat blocks - the school, component, casting time and saving
    // throw codes with the reversible and element markers, cross-checked
    // spell by spell between the passes
    {
        using namespace rules;
        int bad = 0;
    if (difWJL1SpellCount() != 30
            || difWJL1ReversibleCount() != 6
            || difWJL1AlterationCount() != 15
            || difWJL1DivinationCount() != 3
            || difWJL1ConjurationCount() != 6
            || difWJL1VSMCount() != 20
            || difWJL1VSCount() != 7
            || difWJL1VerbalOnlyCount() != 1
            || difWJL1VMCount() != 1
            || difWJL1SpecialCompCount() != 1
            || difWJL1RoundCasts() != 12
            || difWJL1OneSegmentCasts() != 13
            || difWJL1ThreeSegmentCasts() != 2
            || difWJL1FourSegmentCasts() != 1
            || difWJL1FiveSegmentCasts() != 2
            || difWJL1NegSaves() != 2
            || difWJL1SpecialSaves() != 4
            || difWJL1HalfSaves() != 1
        )
            ++bad;
        // the wu jen first level stat grid: the school, component, casting
        // time and saving throw codes with the reversible and element markers
        // by spell ordinal
        int CWJL1Data[30][6] = {
            {1,7,10,0,1,0},
            {6,7,10,0,0,5},
            {9,7,10,0,0,0},
            {6,7,10,0,0,1},
            {6,7,10,0,1,0},
            {2,3,1,0,0,0},
            {4,7,10,1,0,5},
            {4,3,3,3,0,7},
            {6,3,5,0,0,3},
            {4,7,5,0,0,0},
            {4,7,10,0,0,2},
            {6,1,1,0,0,0},
            {1,3,1,1,0,0},
            {2,3,10,2,0,0},
            {3,3,1,0,0,0},
            {6,7,1,2,0,3},
            {6,7,1,0,0,0},
            {4,7,3,2,1,0},
            {2,7,10,0,1,0},
            {6,0,1,0,0,0},
            {3,3,1,0,0,0},
            {6,7,1,0,0,0},
            {6,7,10,2,1,4},
            {6,7,10,0,1,4},
            {4,7,1,0,0,0},
            {9,5,1,0,0,0},
            {6,7,1,0,0,1},
            {6,7,4,0,0,6},
            {6,7,10,0,0,4},
            {6,7,1,0,0,0},
            };
        for (int b = 0;
             b < difWJL1SpellCount();
             ++b) {
            int vals[6];
            vals[0] = difWJL1School(b);
            vals[1] = difWJL1Components(b);
            vals[2] = difWJL1CastTime(b);
            vals[3] = difWJL1Save(b);
            vals[4] = difWJL1Reversible(b);
            vals[5] = difWJL1Element(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CWJL1Data[b][c])
                    ++bad;
            }
        }
        // the count pins - 30 spells, six reversible, 15 alteration, three
        // divination, six conjuration
    if (difWJL1SpellCount() != 30
            || difWJL1ReversibleCount() != 6
            || difWJL1AlterationCount() != 15
            || difWJL1DivinationCount() != 3
            || difWJL1ConjurationCount() != 6
        )
            ++bad;
        // the component pins - 20 VSM, seven VS, hold portal the verbal only,
        // ventriloquism the V,M pair, secret signs the special-components
        // cell
    if (difWJL1VSMCount() != 20
            || difWJL1VSCount() != 7
            || difWJL1VerbalOnlyCount() != 1
            || difWJL1VMCount() != 1
            || difWJL1SpecialCompCount() != 1
        )
            ++bad;
        // the casting time pins - 12 round casts, 13 one-segment, two
        // three-segment, warp wood the four, fiery eyes and ghost light the
        // five
    if (difWJL1RoundCasts() != 12
            || difWJL1OneSegmentCasts() != 13
            || difWJL1ThreeSegmentCasts() != 2
            || difWJL1FourSegmentCasts() != 1
            || difWJL1FiveSegmentCasts() != 2
        )
            ++bad;
        // the saving throw pins - two neg., four special, elemental burst the
        // lone half
    if (difWJL1NegSaves() != 2
            || difWJL1SpecialSaves() != 4
            || difWJL1HalfSaves() != 1
        )
            ++bad;
        // the school pins - accuracy and hypnotism enchantment/charm; detect
        // magic, know history and read magic divination; magic missile and
        // shield evocation; chameleon and ventriloquism illusion; the six
        // conjuration; fiery eyes and hold portal among the 15 alteration
    if (difWJL1School(0) != 1
            || difWJL1School(12) != 1
            || difWJL1School(5) != 2
            || difWJL1School(13) != 2
            || difWJL1School(18) != 2
            || difWJL1School(14) != 3
            || difWJL1School(20) != 3
            || difWJL1School(2) != 9
            || difWJL1School(25) != 9
            || difWJL1School(6) != 4
            || difWJL1School(7) != 4
            || difWJL1School(9) != 4
            || difWJL1School(10) != 4
            || difWJL1School(17) != 4
            || difWJL1School(24) != 4
            || difWJL1School(8) != 6
            || difWJL1School(11) != 6
        )
            ++bad;
        // the component cell pins - the verbal-only hold portal, the V,M
        // ventriloquism, the special secret signs, and the VS set
    if (difWJL1Components(11) != 1
            || difWJL1Components(25) != 5
            || difWJL1Components(19) != 0
            || difWJL1Components(5) != 3
            || difWJL1Components(7) != 3
            || difWJL1Components(8) != 3
            || difWJL1Components(12) != 3
            || difWJL1Components(13) != 3
            || difWJL1Components(14) != 3
            || difWJL1Components(20) != 3
        )
            ++bad;
        // the casting time cell pins - the three-segment pair, the
        // five-segment pair, warp wood the four, and the one-segment spots
    if (difWJL1CastTime(7) != 3
            || difWJL1CastTime(17) != 3
            || difWJL1CastTime(8) != 5
            || difWJL1CastTime(9) != 5
            || difWJL1CastTime(27) != 4
            || difWJL1CastTime(11) != 1
            || difWJL1CastTime(19) != 1
            || difWJL1CastTime(25) != 1
        )
            ++bad;
        // the saving throw cell pins - drowsy insects and hypnotism neg.;
        // know history, melt, prestidigitation and still water special;
        // elemental burst the half; accuracy none
    if (difWJL1Save(6) != 1
            || difWJL1Save(12) != 1
            || difWJL1Save(13) != 2
            || difWJL1Save(15) != 2
            || difWJL1Save(17) != 2
            || difWJL1Save(22) != 2
            || difWJL1Save(7) != 3
            || difWJL1Save(0) != 0
        )
            ++bad;
        // the reversible pins - accuracy, comprehend languages,
        // prestidigitation, read magic, still water and swim marked; detect
        // magic, ghost light and warp wood not
    if (difWJL1Reversible(0) != 1
            || difWJL1Reversible(4) != 1
            || difWJL1Reversible(17) != 1
            || difWJL1Reversible(18) != 1
            || difWJL1Reversible(22) != 1
            || difWJL1Reversible(23) != 1
            || difWJL1Reversible(5) != 0
            || difWJL1Reversible(9) != 0
            || difWJL1Reversible(27) != 0
        )
            ++bad;
        // the element cross-check pins - the 12 tagged cells matching the
        // R669 dieWJT66L1Element grid: animate wood and drowsy insects
        // Nature, cloud ladder and wall of fog Air, elemental burst All,
        // fiery eyes and melt Fire, hail of stone Earth, the three Water
        // marks and warp wood the lone Wood; accuracy untagged
    if (difWJL1Element(1) != 5
            || difWJL1Element(6) != 5
            || difWJL1Element(3) != 1
            || difWJL1Element(26) != 1
            || difWJL1Element(7) != 7
            || difWJL1Element(8) != 3
            || difWJL1Element(15) != 3
            || difWJL1Element(10) != 2
            || difWJL1Element(22) != 4
            || difWJL1Element(23) != 4
            || difWJL1Element(28) != 4
            || difWJL1Element(27) != 6
            || difWJL1Element(0) != 0
        )
            ++bad;
        printf("R670 OA wu jen first level spells audit: bad %d\n", bad);
        if (bad) return 1;
    }
