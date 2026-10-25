    // ---- R662 OA fourth level spells audit ----
    // OA round forty-nine (capture pp. 132-140): the fourth level spell stat
    // blocks - the school, component, casting time and saving throw codes
    // with the reversible and sohei-usable markers, cross-checked spell by
    // spell between the passes
    {
        using namespace rules;
        int bad = 0;
    if (dhwL4SpellCount() != 20
            || dhwL4SoheiCount() != 3
            || dhwL4ReversibleCount() != 7
            || dhwL4AlterationCount() != 7
            || dhwL4AbjurationCount() != 5
            || dhwL4DivinationCount() != 4
            || dhwL4NecromanticCount() != 2
            || dhwL4ConjurationCount() != 1
            || dhwL4EvocationCount() != 1
            || dhwL4VSMCount() != 12
            || dhwL4VSCount() != 5
            || dhwL4VerbalOnlyCount() != 1
            || dhwL4SMCount() != 1
            || dhwL4VMCount() != 1
            || dhwL4TurnCasts() != 3
            || dhwL4SixTurnCasts() != 1
            || dhwL4VariableCasts() != 1
            || dhwL4RoundCasts() != 6
            || dhwL4NegSaves() != 3
            || dhwL4HalfSaves() != 1
        )
            ++bad;
        // the fourth level stat grid: the school, component, casting time and
        // saving throw codes with the reversible and sohei markers by spell
        // ordinal
        int CL4Data[20][6] = {
            {7,7,10,1,1,0},
            {5,3,7,0,1,0},
            {2,7,7,0,1,0},
            {2,7,10,0,0,0},
            {6,6,60,0,1,1},
            {7,7,-1,0,0,0},
            {2,7,360,0,0,0},
            {6,3,7,0,1,0},
            {6,3,4,0,0,0},
            {2,3,20,1,0,1},
            {6,1,3,0,0,0},
            {7,7,7,0,1,0},
            {5,7,10,2,0,0},
            {7,7,10,1,0,0},
            {4,5,60,0,0,0},
            {3,7,4,3,0,0},
            {6,7,60,0,0,0},
            {7,7,10,0,0,1},
            {6,7,10,0,0,0},
            {6,3,7,0,1,0},
            };
        for (int b = 0;
             b < dhwL4SpellCount();
             ++b) {
            int vals[6];
            vals[0] = dhwL4School(b);
            vals[1] = dhwL4Components(b);
            vals[2] = dhwL4CastTime(b);
            vals[3] = dhwL4Save(b);
            vals[4] = dhwL4Reversible(b);
            vals[5] = dhwL4Sohei(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CL4Data[b][c])
                    ++bad;
            }
        }
        // the count pins - twenty fourth level spells, three sohei-usable,
        // seven reversible, seven alteration
    if (dhwL4SpellCount() != 20
            || dhwL4SoheiCount() != 3
            || dhwL4ReversibleCount() != 7
            || dhwL4AlterationCount() != 7
            || dhwL4AbjurationCount() != 5
            || dhwL4DivinationCount() != 4
            || dhwL4NecromanticCount() != 2
            || dhwL4ConjurationCount() != 1
            || dhwL4EvocationCount() != 1
        )
            ++bad;
        // the school pins - abjure the dual school primary abjuration 7; cure
        // serious wounds and reanimation necromantic; fate and penetrate
        // disguise divination; reward conjuration; snake barrier evocation;
        // polymorph self and sustain alteration
    if (dhwL4School(0) != 7
            || dhwL4School(1) != 5
            || dhwL4School(12) != 5
            || dhwL4School(6) != 2
            || dhwL4School(9) != 2
            || dhwL4School(14) != 4
            || dhwL4School(15) != 3
            || dhwL4School(10) != 6
            || dhwL4School(18) != 6
        )
            ++bad;
        // the component pins - the component singles: polymorph self the
        // verbal only (1), endurance the somatic and material (6), reward the
        // verbal and material (5); the twelve all-component spells with
        // abjure, exorcise and spell immunity pinned; cure serious wounds and
        // tongues verbal and somatic
    if (dhwL4Components(10) != 1
            || dhwL4Components(4) != 6
            || dhwL4Components(14) != 5
            || dhwL4Components(0) != 7
            || dhwL4Components(5) != 7
            || dhwL4Components(17) != 7
            || dhwL4Components(1) != 3
            || dhwL4Components(19) != 3
        )
            ++bad;
        // the casting time pins - exorcise the variable 1-100+ turns cast
        // pinned as -1 (the only unfixed cast in the chapter); fate the
        // six-turn cast; penetrate disguise two rounds; the three one-turn
        // casts (endurance, reward, speak w/ plants); the seven-segment casts
        // (cure serious wounds, detect lie, neutralize poison, protection
        // from evil 10', tongues); pacify and snake barrier four, polymorph
        // self three
    if (dhwL4CastTime(5) != -1
            || dhwL4CastTime(6) != 360
            || dhwL4CastTime(9) != 20
            || dhwL4CastTime(4) != 60
            || dhwL4CastTime(14) != 60
            || dhwL4CastTime(16) != 60
            || dhwL4CastTime(1) != 7
            || dhwL4CastTime(11) != 7
            || dhwL4CastTime(19) != 7
            || dhwL4CastTime(8) != 4
            || dhwL4CastTime(15) != 4
            || dhwL4CastTime(10) != 3
        )
            ++bad;
        // the saving throw pins - abjure, penetrate disguise and remorse
        // neg.; reanimation special; snake barrier the debuting half code 3
        // (the print 112 garble settling per the compressed 1/2); the fifteen
        // others none
    if (dhwL4Save(0) != 1
            || dhwL4Save(9) != 1
            || dhwL4Save(13) != 1
            || dhwL4Save(12) != 2
            || dhwL4Save(15) != 3
            || dhwL4Save(1) != 0
            || dhwL4Save(6) != 0
            || dhwL4Save(19) != 0
        )
            ++bad;
        // the reversible pins - the seven marks (abjure, cure serious wounds,
        // detect lie, endurance, neutralize poison, protection from evil 10',
        // tongues); exorcise, fate and snake barrier not - the seven matching
        // the R658 T62 reversible column
    if (dhwL4Reversible(0) != 1
            || dhwL4Reversible(1) != 1
            || dhwL4Reversible(2) != 1
            || dhwL4Reversible(4) != 1
            || dhwL4Reversible(7) != 1
            || dhwL4Reversible(11) != 1
            || dhwL4Reversible(19) != 1
            || dhwL4Reversible(5) != 0
            || dhwL4Reversible(6) != 0
            || dhwL4Reversible(15) != 0
        )
            ++bad;
        // the sohei pins - endurance, penetrate disguise and spell immunity
        // marked; abjure, fate and tongues not - the three matching the R658
        // T62 sohei column
    if (dhwL4Sohei(4) != 1
            || dhwL4Sohei(9) != 1
            || dhwL4Sohei(17) != 1
            || dhwL4Sohei(0) != 0
            || dhwL4Sohei(6) != 0
            || dhwL4Sohei(19) != 0
        )
            ++bad;
        // the grid-sum pins - twelve VSM, five VS and the three component
        // singles; three one-turn, one six-turn and one variable casts; three
        // neg. and one half saves
    if (dhwL4VSMCount() != 12
            || dhwL4VSCount() != 5
            || dhwL4VerbalOnlyCount() != 1
            || dhwL4SMCount() != 1
            || dhwL4VMCount() != 1
            || dhwL4TurnCasts() != 3
            || dhwL4SixTurnCasts() != 1
            || dhwL4VariableCasts() != 1
            || dhwL4RoundCasts() != 6
            || dhwL4NegSaves() != 3
            || dhwL4HalfSaves() != 1
        )
            ++bad;
        printf("R662 OA fourth level spells audit: bad %d\n", bad);
        if (bad) return 1;
    }
