    // ---- R660 OA second level spells audit ----
    // OA round forty-seven (capture pp. 119-126): the second level spell stat
    // blocks - the school, component, casting time and saving throw codes
    // with the reversible and sohei-usable markers, cross-checked spell by
    // spell between the passes
    {
        using namespace rules;
        int bad = 0;
    if (dhuL2SpellCount() != 20
            || dhuL2SoheiCount() != 4
            || dhuL2ReversibleCount() != 3
            || dhuL2DivinationCount() != 5
            || dhuL2EnchCharmCount() != 4
            || dhuL2AlterationCount() != 5
            || dhuL2AbjurationCount() != 2
            || dhuL2VSMCount() != 13
            || dhuL2VSCount() != 6
            || dhuL2SMCount() != 1
            || dhuL2TurnCasts() != 3
            || dhuL2ThreeTurnCasts() != 1
            || dhuL2RoundCasts() != 9
            || dhuL2NegSaves() != 4
            || dhuL2SpecialSaves() != 2
        )
            ++bad;
        // the second level stat grid: the school, component, casting time and
        // saving throw codes with the reversible and sohei markers by spell
        // ordinal
        int CL2Data[20][6] = {
            {5,7,4,0,0,0},
            {4,3,60,0,0,1},
            {2,7,60,0,0,0},
            {6,7,10,0,1,0},
            {2,3,10,0,1,0},
            {2,7,10,0,0,0},
            {6,6,10,0,0,0},
            {1,3,10,1,0,0},
            {1,7,5,1,0,0},
            {4,7,60,0,0,0},
            {2,7,10,0,1,0},
            {1,7,10,1,0,1},
            {6,3,4,0,0,0},
            {7,7,10,2,0,0},
            {7,7,180,1,0,0},
            {5,7,1,0,0,1},
            {1,7,10,2,0,0},
            {6,3,5,0,0,0},
            {2,3,2,0,0,1},
            {6,7,3,0,0,0},
            };
        for (int b = 0;
             b < dhuL2SpellCount();
             ++b) {
            int vals[6];
            vals[0] = dhuL2School(b);
            vals[1] = dhuL2Components(b);
            vals[2] = dhuL2CastTime(b);
            vals[3] = dhuL2Save(b);
            vals[4] = dhuL2Reversible(b);
            vals[5] = dhuL2Sohei(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CL2Data[b][c])
                    ++bad;
            }
        }
        // the count pins - twenty second level spells, four sohei-usable,
        // three reversible, five divination
    if (dhuL2SpellCount() != 20
            || dhuL2SoheiCount() != 4
            || dhuL2ReversibleCount() != 3
            || dhuL2DivinationCount() != 5
            || dhuL2EnchCharmCount() != 4
            || dhuL2AlterationCount() != 5
            || dhuL2AbjurationCount() != 2
        )
            ++bad;
        // the school pins - aid the dual school necromantic/conjuration
        // primary 5; chant and holy symbol conjuration/summoning; commune
        // with lesser spirit, detect charm, detect life, know motivation and
        // warning divination; create spring, dream sight, obscurement, speak
        // w/ animals and withdraw alteration; protection from spirits and
        // request the debuting abjuration 7
    if (dhuL2School(0) != 5
            || dhuL2School(1) != 4
            || dhuL2School(2) != 2
            || dhuL2School(5) != 2
            || dhuL2School(9) != 4
            || dhuL2School(13) != 7
            || dhuL2School(14) != 7
            || dhuL2School(18) != 2
            || dhuL2School(19) != 6
        )
            ++bad;
        // the component pins - the thirteen all-component spells with aid,
        // hold person and request pinned; the six verbal and somatic with
        // chant, detect charm, enthrall and warning pinned; dream sight the
        // somatic and material only - the unique no-verbal spell
    if (dhuL2Components(0) != 7
            || dhuL2Components(8) != 7
            || dhuL2Components(14) != 7
            || dhuL2Components(1) != 3
            || dhuL2Components(4) != 3
            || dhuL2Components(7) != 3
            || dhuL2Components(18) != 3
            || dhuL2Components(6) != 6
            || dhuL2Components(2) != 7
        )
            ++bad;
        // the casting time pins - request the three-turn cast (the longest in
        // the level); chant, commune with lesser spirit and holy symbol the
        // one-turn casts; slow poison the single segment; warning two,
        // withdraw three, aid and obscurement four, hold person and speak w/
        // animals five
    if (dhuL2CastTime(14) != 180
            || dhuL2CastTime(1) != 60
            || dhuL2CastTime(2) != 60
            || dhuL2CastTime(9) != 60
            || dhuL2CastTime(15) != 1
            || dhuL2CastTime(18) != 2
            || dhuL2CastTime(19) != 3
            || dhuL2CastTime(0) != 4
            || dhuL2CastTime(12) != 4
            || dhuL2CastTime(8) != 5
            || dhuL2CastTime(17) != 5
        )
            ++bad;
        // the saving throw pins - enthrall, hold person, messenger and
        // request neg.; protection from spirits and snake summoning special;
        // the fourteen others none
    if (dhuL2Save(7) != 1
            || dhuL2Save(8) != 1
            || dhuL2Save(11) != 1
            || dhuL2Save(14) != 1
            || dhuL2Save(13) != 2
            || dhuL2Save(16) != 2
            || dhuL2Save(0) != 0
            || dhuL2Save(19) != 0
        )
            ++bad;
        // the reversible pins - create spring, detect charm and know
        // motivation marked; aid, dream sight and withdraw not - the three
        // matching the R658 T62 reversible column
    if (dhuL2Reversible(3) != 1
            || dhuL2Reversible(4) != 1
            || dhuL2Reversible(10) != 1
            || dhuL2Reversible(0) != 0
            || dhuL2Reversible(6) != 0
            || dhuL2Reversible(19) != 0
        )
            ++bad;
        // the sohei pins - chant, messenger, slow poison and warning marked;
        // aid, enthrall and hold person not - the four matching the R658 T62
        // sohei column
    if (dhuL2Sohei(1) != 1
            || dhuL2Sohei(11) != 1
            || dhuL2Sohei(15) != 1
            || dhuL2Sohei(18) != 1
            || dhuL2Sohei(0) != 0
            || dhuL2Sohei(7) != 0
            || dhuL2Sohei(8) != 0
        )
            ++bad;
        // the grid-sum pins - thirteen VSM, six VS, one SM components; three
        // one-turn and one three-turn casts; four neg. and two special saves
    if (dhuL2VSMCount() != 13
            || dhuL2VSCount() != 6
            || dhuL2SMCount() != 1
            || dhuL2TurnCasts() != 3
            || dhuL2ThreeTurnCasts() != 1
            || dhuL2RoundCasts() != 9
            || dhuL2NegSaves() != 4
            || dhuL2SpecialSaves() != 2
        )
            ++bad;
        printf("R660 OA second level spells audit: bad %d\n", bad);
        if (bad) return 1;
    }
