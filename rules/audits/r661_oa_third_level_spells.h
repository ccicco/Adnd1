    // ---- R661 OA third level spells audit ----
    // OA round forty-eight (capture pp. 126-132): the third level spell stat
    // blocks - the school, component, casting time and saving throw codes
    // with the reversible and sohei-usable markers, cross-checked spell by
    // spell between the passes
    {
        using namespace rules;
        int bad = 0;
    if (dhvL3SpellCount() != 20
            || dhvL3SoheiCount() != 4
            || dhvL3ReversibleCount() != 7
            || dhvL3AbjurationCount() != 7
            || dhvL3DivinationCount() != 3
            || dhvL3AlterationCount() != 3
            || dhvL3ConjurationCount() != 2
            || dhvL3NecromanticCount() != 2
            || dhvL3InvocationCount() != 1
            || dhvL3IllusionCount() != 1
            || dhvL3EnchCharmCount() != 1
            || dhvL3VSMCount() != 14
            || dhvL3VSCount() != 6
            || dhvL3TurnCasts() != 5
            || dhvL3ThreeTurnCasts() != 1
            || dhvL3RoundCasts() != 6
            || dhvL3SixSegmentCasts() != 4
            || dhvL3NegSaves() != 3
            || dhvL3SpecialSaves() != 2
        )
            ++bad;
        // the third level stat grid: the school, component, casting time and
        // saving throw codes with the reversible and sohei markers by spell
        // ordinal
        int CL3Data[20][6] = {
            {7,7,3,2,0,1},
            {7,3,10,0,1,0},
            {7,3,60,0,1,0},
            {5,7,5,0,0,0},
            {2,7,10,0,0,0},
            {7,3,6,0,0,1},
            {2,7,60,0,0,0},
            {8,7,60,0,1,0},
            {6,7,5,0,0,1},
            {9,7,60,0,0,0},
            {2,3,10,0,1,0},
            {6,7,2,1,0,0},
            {4,7,10,0,0,0},
            {7,7,10,1,1,0},
            {1,7,10,1,0,0},
            {4,7,6,0,0,1},
            {7,3,6,2,1,0},
            {7,3,6,0,1,0},
            {5,7,60,0,0,0},
            {6,7,180,0,0,0},
            };
        for (int b = 0;
             b < dhvL3SpellCount();
             ++b) {
            int vals[6];
            vals[0] = dhvL3School(b);
            vals[1] = dhvL3Components(b);
            vals[2] = dhvL3CastTime(b);
            vals[3] = dhvL3Save(b);
            vals[4] = dhvL3Reversible(b);
            vals[5] = dhvL3Sohei(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CL3Data[b][c])
                    ++bad;
            }
        }
        // the count pins - twenty third level spells, four sohei-usable,
        // seven reversible, seven abjuration
    if (dhvL3SpellCount() != 20
            || dhvL3SoheiCount() != 4
            || dhvL3ReversibleCount() != 7
            || dhvL3AbjurationCount() != 7
            || dhvL3InvocationCount() != 1
            || dhvL3IllusionCount() != 1
            || dhvL3ConjurationCount() != 2
            || dhvL3NecromanticCount() != 2
        )
            ++bad;
        // the school pins - castigate abjuration; death's door and speak w/
        // dead necromantic; dispel magic abjuration; dream vision the
        // debuting invocation 8; flame walk, levitate and substitution
        // alteration; invisibility to spirits the debuting illusion/phantasm
        // 9; magical vestment the dual school primary conjuration 4; possess
        // animal enchantment/charm
    if (dhvL3School(0) != 7
            || dhvL3School(3) != 5
            || dhvL3School(5) != 7
            || dhvL3School(7) != 8
            || dhvL3School(9) != 9
            || dhvL3School(12) != 4
            || dhvL3School(14) != 1
            || dhvL3School(19) != 6
            || dhvL3School(18) != 5
        )
            ++bad;
        // the component pins - the fourteen all-component spells with
        // castigate, dream vision and substitution pinned; the six verbal and
        // somatic with cure blindness, dispel magic and remove paralysis
        // pinned
    if (dhvL3Components(0) != 7
            || dhvL3Components(7) != 7
            || dhvL3Components(19) != 7
            || dhvL3Components(1) != 3
            || dhvL3Components(5) != 3
            || dhvL3Components(17) != 3
            || dhvL3Components(4) != 7
            || dhvL3Components(11) != 7
        )
            ++bad;
        // the casting time pins - substitution the three-turn cast (the
        // longest in the level); the five one-turn casts (cure disease,
        // divination, dream vision, invisibility to spirits, speak w/ dead);
        // the six-segment casts (dispel magic, prayer, remove curse, remove
        // paralysis); levitate the two-segment, castigate the three-segment,
        // death's door and flame walk the five-segment casts
    if (dhvL3CastTime(19) != 180
            || dhvL3CastTime(2) != 60
            || dhvL3CastTime(6) != 60
            || dhvL3CastTime(9) != 60
            || dhvL3CastTime(18) != 60
            || dhvL3CastTime(5) != 6
            || dhvL3CastTime(15) != 6
            || dhvL3CastTime(16) != 6
            || dhvL3CastTime(11) != 2
            || dhvL3CastTime(0) != 3
            || dhvL3CastTime(3) != 5
            || dhvL3CastTime(8) != 5
        )
            ++bad;
        // the saving throw pins - levitate, oath and possess animal neg.;
        // castigate and remove curse special; the fifteen others none
    if (dhvL3Save(11) != 1
            || dhvL3Save(13) != 1
            || dhvL3Save(14) != 1
            || dhvL3Save(0) != 2
            || dhvL3Save(16) != 2
            || dhvL3Save(1) != 0
            || dhvL3Save(19) != 0
            || dhvL3Save(9) != 0
        )
            ++bad;
        // the reversible pins - the seven marks (cure blindness, cure
        // disease, dream vision, know alignment, oath, remove curse, remove
        // paralysis); castigate, levitate and substitution not - the seven
        // matching the R658 T62 reversible column
    if (dhvL3Reversible(1) != 1
            || dhvL3Reversible(2) != 1
            || dhvL3Reversible(7) != 1
            || dhvL3Reversible(10) != 1
            || dhvL3Reversible(13) != 1
            || dhvL3Reversible(16) != 1
            || dhvL3Reversible(17) != 1
            || dhvL3Reversible(0) != 0
            || dhvL3Reversible(11) != 0
            || dhvL3Reversible(19) != 0
        )
            ++bad;
        // the sohei pins - castigate, dispel magic, flame walk and prayer
        // marked; death's door, divination and levitate not - the four
        // matching the R658 T62 sohei column
    if (dhvL3Sohei(0) != 1
            || dhvL3Sohei(5) != 1
            || dhvL3Sohei(8) != 1
            || dhvL3Sohei(15) != 1
            || dhvL3Sohei(3) != 0
            || dhvL3Sohei(6) != 0
            || dhvL3Sohei(11) != 0
        )
            ++bad;
        // the grid-sum pins - fourteen VSM and six VS components; five
        // one-turn and one three-turn casts; four six-segment casts; three
        // neg. and two special saves
    if (dhvL3VSMCount() != 14
            || dhvL3VSCount() != 6
            || dhvL3TurnCasts() != 5
            || dhvL3ThreeTurnCasts() != 1
            || dhvL3RoundCasts() != 6
            || dhvL3SixSegmentCasts() != 4
            || dhvL3NegSaves() != 3
            || dhvL3SpecialSaves() != 2
            || dhvL3DivinationCount() != 3
            || dhvL3AlterationCount() != 3
            || dhvL3EnchCharmCount() != 1
        )
            ++bad;
        printf("R661 OA third level spells audit: bad %d\n", bad);
        if (bad) return 1;
    }
