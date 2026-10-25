    // ---- R659 OA first level spells audit ----
    // OA round forty-six (capture pp. 112-119): the first level spell stat
    // blocks - the school, component, casting time and saving throw codes
    // with the reversible and sohei-usable markers, cross-checked spell by
    // spell between the passes
    {
        using namespace rules;
        int bad = 0;
    if (dhtL1SpellCount() != 20
            || dhtL1SoheiCount() != 5
            || dhtL1ReversibleCount() != 5
            || dhtL1DivinationCount() != 10
            || dhtL1VSMCount() != 12
            || dhtL1VerbalOnlyCount() != 2
            || dhtL1TurnCasts() != 4
            || dhtL1RoundCasts() != 12
            || dhtL1SegmentCasts() != 4
            || dhtL1NegSaves() != 2
            || dhtL1SpecialSaves() != 2
        )
            ++bad;
        // the first level stat grid: the school, component, casting time and
        // saving throw codes with the reversible and sohei markers by spell
        // ordinal
        int CL1Data[20][6] = {
            {1,7,60,1,0,1},
            {2,7,10,0,0,0},
            {3,1,5,0,0,0},
            {4,3,10,0,1,1},
            {1,7,5,1,0,0},
            {5,3,5,0,1,0},
            {3,3,10,2,1,1},
            {2,7,10,0,0,0},
            {2,7,10,0,1,0},
            {2,7,60,0,0,0},
            {2,7,10,0,0,0},
            {2,7,10,0,0,0},
            {2,7,10,0,0,0},
            {2,7,10,2,0,0},
            {2,1,60,0,0,0},
            {6,3,10,0,1,0},
            {6,7,10,0,0,1},
            {1,3,5,0,0,0},
            {2,3,10,0,0,0},
            {4,7,60,0,0,1},
            };
        for (int b = 0;
             b < dhtL1SpellCount();
             ++b) {
            int vals[6];
            vals[0] = dhtL1School(b);
            vals[1] = dhtL1Components(b);
            vals[2] = dhtL1CastTime(b);
            vals[3] = dhtL1Save(b);
            vals[4] = dhtL1Reversible(b);
            vals[5] = dhtL1Sohei(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CL1Data[b][c])
                    ++bad;
            }
        }
        // the count pins - twenty first level spells, five sohei-usable, five
        // reversible, ten divination
    if (dhtL1SpellCount() != 20
            || dhtL1SoheiCount() != 5
            || dhtL1ReversibleCount() != 5
            || dhtL1DivinationCount() != 10
        )
            ++bad;
        // the school pins - animal companion, calm and snake charm
        // enchantment/charm; augury through trance the divination run;
        // beneficence and deflection evocation; bless and weapon bless
        // conjuration/summoning; cure light wounds necromantic; purify food &
        // drink and resist alteration
    if (dhtL1School(0) != 1
            || dhtL1School(1) != 2
            || dhtL1School(2) != 3
            || dhtL1School(3) != 4
            || dhtL1School(4) != 1
            || dhtL1School(5) != 5
            || dhtL1School(6) != 3
            || dhtL1School(18) != 2
            || dhtL1School(19) != 4
        )
            ++bad;
        // the component pins - the twelve all-component spells (animal
        // companion, augury, calm, the five detects, divining rod, know
        // history, resist, weapon bless); beneficence and omen verbal only;
        // bless, cure light wounds, deflection, purify, snake charm and
        // trance verbal and somatic
    if (dhtL1Components(0) != 7
            || dhtL1Components(1) != 7
            || dhtL1Components(2) != 1
            || dhtL1Components(3) != 3
            || dhtL1Components(9) != 7
            || dhtL1Components(13) != 7
            || dhtL1Components(14) != 1
            || dhtL1Components(15) != 3
            || dhtL1Components(17) != 3
            || dhtL1Components(19) != 7
        )
            ++bad;
        // the casting time pins - the one-turn casts (animal companion,
        // detect harmony, omen, weapon bless); the five-segment casts
        // (beneficence, calm, cure light wounds, snake charm); the rest one
        // round
    if (dhtL1CastTime(0) != 60
            || dhtL1CastTime(2) != 5
            || dhtL1CastTime(4) != 5
            || dhtL1CastTime(9) != 60
            || dhtL1CastTime(14) != 60
            || dhtL1CastTime(17) != 5
            || dhtL1CastTime(19) != 60
            || dhtL1CastTime(1) != 10
            || dhtL1CastTime(18) != 10
        )
            ++bad;
        // the saving throw pins - animal companion and calm neg., deflection
        // and know history special, the sixteen others none
    if (dhtL1Save(0) != 1
            || dhtL1Save(4) != 1
            || dhtL1Save(6) != 2
            || dhtL1Save(13) != 2
            || dhtL1Save(1) != 0
            || dhtL1Save(15) != 0
            || dhtL1Save(19) != 0
        )
            ++bad;
        // the reversible pins - bless, cure light wounds, deflection, detect
        // evil and purify food & drink marked; augury, calm and weapon bless
        // not - the five matching the R658 T62 reversible column
    if (dhtL1Reversible(3) != 1
            || dhtL1Reversible(5) != 1
            || dhtL1Reversible(6) != 1
            || dhtL1Reversible(8) != 1
            || dhtL1Reversible(15) != 1
            || dhtL1Reversible(1) != 0
            || dhtL1Reversible(4) != 0
            || dhtL1Reversible(19) != 0
        )
            ++bad;
        // the sohei pins - animal companion, bless, deflection, resist and
        // weapon bless marked; augury and cure light wounds not - the five
        // matching the R658 T62 sohei column
    if (dhtL1Sohei(0) != 1
            || dhtL1Sohei(3) != 1
            || dhtL1Sohei(6) != 1
            || dhtL1Sohei(16) != 1
            || dhtL1Sohei(19) != 1
            || dhtL1Sohei(1) != 0
            || dhtL1Sohei(5) != 0
        )
            ++bad;
        // the grid-sum pins - twelve VSM components, twelve one-round casts,
        // sixteen none saves
    if (dhtL1VSMCount() != 12
            || dhtL1RoundCasts() != 12
            || dhtL1VerbalOnlyCount() != 2
            || dhtL1SegmentCasts() != 4
            || dhtL1TurnCasts() != 4
            || dhtL1NegSaves() != 2
            || dhtL1SpecialSaves() != 2
        )
            ++bad;
        printf("R659 OA first level spells audit: bad %d\n", bad);
        if (bad) return 1;
    }
