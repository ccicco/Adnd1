    // ---- R665 OA seventh level spells audit ----
    // OA round fifty-two (capture pp. 147-152): the seventh level spell stat
    // blocks - the school, component, casting time and saving throw codes
    // with the reversible and sohei-usable markers, cross-checked spell by
    // spell between the passes
    {
        using namespace rules;
        int bad = 0;
    if (dhzL7SpellCount() != 12
            || dhzL7SoheiCount() != 1
            || dhzL7ReversibleCount() != 1
            || dhzL7ConjurationCount() != 3
            || dhzL7NecromanticCount() != 3
            || dhzL7VSMCount() != 8
            || dhzL7VSCount() != 2
            || dhzL7VerbalOnlyCount() != 2
            || dhzL7RoundCasts() != 5
            || dhzL7TurnCasts() != 3
            || dhzL7ThreeTurnCasts() != 1
            || dhzL7OneSegmentCasts() != 1
            || dhzL7FiveSegmentCasts() != 1
            || dhzL7EightSegmentCasts() != 1
            || dhzL7NegSaves() != 2
            || dhzL7SpecialSaves() != 2
        )
            ++bad;
        // the seventh level stat grid: the school, component, casting time
        // and saving throw codes with the reversible and sohei markers by
        // spell ordinal
        int CL7Data[12][6] = {
            {7,1,10,0,0,1},
            {6,3,180,0,0,0},
            {7,7,10,1,0,0},
            {4,7,60,0,0,0},
            {3,7,10,2,0,0},
            {4,3,5,0,0,0},
            {4,1,1,0,0,0},
            {1,7,8,1,0,0},
            {5,7,60,0,0,0},
            {5,7,10,2,0,0},
            {5,7,60,0,1,0},
            {6,7,10,0,0,0},
            };
        for (int b = 0;
             b < dhzL7SpellCount();
             ++b) {
            int vals[6];
            vals[0] = dhzL7School(b);
            vals[1] = dhzL7Components(b);
            vals[2] = dhzL7CastTime(b);
            vals[3] = dhzL7Save(b);
            vals[4] = dhzL7Reversible(b);
            vals[5] = dhzL7Sohei(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CL7Data[b][c])
                    ++bad;
            }
        }
        // the count pins - twelve seventh level spells, one sohei-usable, one
        // reversible, three conjuration and three necromantic
    if (dhzL7SpellCount() != 12
            || dhzL7SoheiCount() != 1
            || dhzL7ReversibleCount() != 1
            || dhzL7ConjurationCount() != 3
            || dhzL7NecromanticCount() != 3
            || dhzL7VSMCount() != 8
            || dhzL7VSCount() != 2
            || dhzL7VerbalOnlyCount() != 2
        )
            ++bad;
        // the school pins - ancient curse and compel abjuration; astral spell
        // and wind walk alteration; divine wind, gate and holy (unholy) word
        // conjuration; quest enchantment/charm; exaction evocation (the dual
        // Evocation/Alteration pinned primary); reincarnate, restore spirit
        // and resurrection necromantic
    if (dhzL7School(0) != 7
            || dhzL7School(2) != 7
            || dhzL7School(1) != 6
            || dhzL7School(11) != 6
            || dhzL7School(3) != 4
            || dhzL7School(5) != 4
            || dhzL7School(6) != 4
            || dhzL7School(7) != 1
            || dhzL7School(4) != 3
            || dhzL7School(8) != 5
            || dhzL7School(9) != 5
            || dhzL7School(10) != 5
        )
            ++bad;
        // the component pins - ancient curse and holy (unholy) word the
        // verbal-only pair; astral spell and gate the verbal and somatic; the
        // eight all-component with compel, divine wind, exaction, quest,
        // reincarnate, restore spirit, resurrection and wind walk pinned
    if (dhzL7Components(0) != 1
            || dhzL7Components(6) != 1
            || dhzL7Components(1) != 3
            || dhzL7Components(5) != 3
            || dhzL7Components(2) != 7
            || dhzL7Components(3) != 7
            || dhzL7Components(4) != 7
            || dhzL7Components(7) != 7
            || dhzL7Components(8) != 7
            || dhzL7Components(9) != 7
            || dhzL7Components(10) != 7
            || dhzL7Components(11) != 7
        )
            ++bad;
        // the casting time pins - astral spell the three-turn cast 180 (the
        // longest of the level); the three one-turn casts; the five one-round
        // casts; quest eight segments; gate five; holy (unholy) word the
        // single segment
    if (dhzL7CastTime(1) != 180
            || dhzL7CastTime(3) != 60
            || dhzL7CastTime(8) != 60
            || dhzL7CastTime(10) != 60
            || dhzL7CastTime(0) != 10
            || dhzL7CastTime(2) != 10
            || dhzL7CastTime(4) != 10
            || dhzL7CastTime(9) != 10
            || dhzL7CastTime(11) != 10
            || dhzL7CastTime(7) != 8
            || dhzL7CastTime(5) != 5
            || dhzL7CastTime(6) != 1
        )
            ++bad;
        // the saving throw pins - compel and quest neg.; exaction and restore
        // spirit special; the other eight none; no half saves this level
    if (dhzL7Save(2) != 1
            || dhzL7Save(7) != 1
            || dhzL7Save(4) != 2
            || dhzL7Save(9) != 2
            || dhzL7Save(0) != 0
            || dhzL7Save(1) != 0
            || dhzL7Save(3) != 0
            || dhzL7Save(5) != 0
            || dhzL7Save(6) != 0
            || dhzL7Save(8) != 0
            || dhzL7Save(10) != 0
            || dhzL7Save(11) != 0
        )
            ++bad;
        // the reversible pins - resurrection marked (the destruction
        // reverse); ancient curse, astral spell, holy (unholy) word and wind
        // walk not - the one matching the R658 T62 reversible column
    if (dhzL7Reversible(10) != 1
            || dhzL7Reversible(0) != 0
            || dhzL7Reversible(1) != 0
            || dhzL7Reversible(6) != 0
            || dhzL7Reversible(11) != 0
        )
            ++bad;
        // the sohei pins - ancient curse marked; holy (unholy) word, compel
        // and resurrection not - the one matching the R658 T62 sohei column
    if (dhzL7Sohei(0) != 1
            || dhzL7Sohei(6) != 0
            || dhzL7Sohei(10) != 0
            || dhzL7Sohei(3) != 0
        )
            ++bad;
        // the grid-sum pins - five one-round, three one-turn and one
        // three-turn casts; the one-segment, five-segment and eight-segment
        // singles; two neg. and two special saves
    if (dhzL7RoundCasts() != 5
            || dhzL7TurnCasts() != 3
            || dhzL7ThreeTurnCasts() != 1
            || dhzL7OneSegmentCasts() != 1
            || dhzL7FiveSegmentCasts() != 1
            || dhzL7EightSegmentCasts() != 1
            || dhzL7NegSaves() != 2
            || dhzL7SpecialSaves() != 2
        )
            ++bad;
        printf("R665 OA seventh level spells audit: bad %d\n", bad);
        if (bad) return 1;
    }
