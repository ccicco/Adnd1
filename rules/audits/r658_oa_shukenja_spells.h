    // ---- R658 OA shukenja spells audit ----
    // OA round forty-five (capture p. 112): Table 62 - the shukenja spell
    // list by level, the per-level spell counts with the sohei-usable and
    // reversible markers
    {
        using namespace rules;
        int bad = 0;
    if (dhsT62LevelCount() != 7
            || dhsT62SpellTotal() != 116
            || dhsT62OrdinalMax() != 20
            || dhsT62L1Spells() != 20
            || dhsT62L2Spells() != 20
            || dhsT62L3Spells() != 20
            || dhsT62L4Spells() != 20
            || dhsT62L5Spells() != 12
            || dhsT62L6Spells() != 12
            || dhsT62L7Spells() != 12
        )
            ++bad;
        // the Table 62 grid: the sohei-usable and reversible markers by spell
        // ordinal and level
        int CT62Data[20][14] = {
            {1,0,1,0,0,1,1,0,0,0,1,0,1,0},
            {0,1,0,0,0,0,0,0,0,1,1,0,0,0},
            {0,0,0,0,0,0,0,0,0,1,1,0,1,0},
            {1,0,0,0,0,1,0,1,1,0,0,0,1,0},
            {0,0,0,1,0,0,0,0,1,0,1,1,0,0},
            {0,0,1,0,1,0,0,1,0,0,0,1,0,0},
            {1,0,0,0,1,0,1,1,0,0,0,1,0,0},
            {0,0,0,0,0,0,0,0,0,1,1,0,0,0},
            {0,0,1,0,0,0,0,1,0,0,0,1,0,0},
            {0,0,0,1,0,0,0,0,0,0,0,1,1,0},
            {0,0,0,0,1,1,0,0,1,1,0,0,0,1},
            {0,1,0,0,1,1,0,0,0,0,1,1,0,0},
            {0,0,0,0,-99,-99,-99,0,0,0,0,-99,-99,-99},
            {0,0,0,0,-99,-99,-99,0,0,1,0,-99,-99,-99},
            {0,0,0,0,-99,-99,-99,0,0,0,0,-99,-99,-99},
            {0,1,1,0,-99,-99,-99,1,0,0,0,-99,-99,-99},
            {1,0,0,0,-99,-99,-99,0,0,1,0,-99,-99,-99},
            {0,0,0,1,-99,-99,-99,0,0,1,0,-99,-99,-99},
            {0,1,0,0,-99,-99,-99,0,0,0,0,-99,-99,-99},
            {1,0,0,0,-99,-99,-99,0,0,0,1,-99,-99,-99},
            };
        int nT62Data[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int eT62Data[14] = {0,0,0,0,8,8,8,0,0,0,0,8,8,8};
        for (int b = 0;
             b < dhsT62OrdinalMax();
             ++b) {
            int vals[14];
            vals[0] = dhsT62L1Sohei(b);
            vals[1] = dhsT62L2Sohei(b);
            vals[2] = dhsT62L3Sohei(b);
            vals[3] = dhsT62L4Sohei(b);
            vals[4] = dhsT62L5Sohei(b);
            vals[5] = dhsT62L6Sohei(b);
            vals[6] = dhsT62L7Sohei(b);
            vals[7] = dhsT62L1Rev(b);
            vals[8] = dhsT62L2Rev(b);
            vals[9] = dhsT62L3Rev(b);
            vals[10] = dhsT62L4Rev(b);
            vals[11] = dhsT62L5Rev(b);
            vals[12] = dhsT62L6Rev(b);
            vals[13] = dhsT62L7Rev(b);
            for (int c = 0; c < 14;
                 ++c) {
                if (vals[c] != CT62Data[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT62Data[c];
            }
        }
        for (int c = 0; c < 14; ++c)
            if (nT62Data[c] != eT62Data[c])
                ++bad;
        // the 1st level sohei pins - animal companion, bless, deflection,
        // resist and weapon bless marked, augury and cure light wounds
        // unmarked
    if (dhsT62L1Sohei(0) != 1
            || dhsT62L1Sohei(1) != 0
            || dhsT62L1Sohei(3) != 1
            || dhsT62L1Sohei(5) != 0
            || dhsT62L1Sohei(6) != 1
            || dhsT62L1Sohei(16) != 1
            || dhsT62L1Sohei(19) != 1
        )
            ++bad;
        // the 2nd through 4th level sohei pins - chant, messenger, slow
        // poison, warning; castigate, dispel magic, flame walk, prayer;
        // endurance, penetrate disguise, spell immunity
    if (dhsT62L2Sohei(1) != 1
            || dhsT62L2Sohei(11) != 1
            || dhsT62L2Sohei(15) != 1
            || dhsT62L2Sohei(18) != 1
            || dhsT62L3Sohei(0) != 1
            || dhsT62L3Sohei(5) != 1
            || dhsT62L3Sohei(8) != 1
            || dhsT62L3Sohei(15) != 1
            || dhsT62L4Sohei(4) != 1
            || dhsT62L4Sohei(9) != 1
            || dhsT62L4Sohei(17) != 1
        )
            ++bad;
        // the 5th through 7th level sohei pins with the level extents -
        // dispel evil, mental strength, strength, true seeing; find the path,
        // immunity to weapons, smite, speak w/ monsters; ancient curse, holy
        // word; the sentinel past the twelve-spell levels
    if (dhsT62L5Sohei(5) != 1
            || dhsT62L5Sohei(6) != 1
            || dhsT62L5Sohei(10) != 1
            || dhsT62L5Sohei(11) != 1
            || dhsT62L5Sohei(12) != -99
            || dhsT62L6Sohei(0) != 1
            || dhsT62L6Sohei(3) != 1
            || dhsT62L6Sohei(10) != 1
            || dhsT62L6Sohei(11) != 1
            || dhsT62L7Sohei(0) != 1
            || dhsT62L7Sohei(6) != 1
            || dhsT62L7Sohei(12) != -99
        )
            ++bad;
        // the 1st level reversible pins - bless, cure light wounds,
        // deflection, detect evil and purify food & drink marked, animal
        // companion and weapon bless not
    if (dhsT62L1Rev(3) != 1
            || dhsT62L1Rev(5) != 1
            || dhsT62L1Rev(6) != 1
            || dhsT62L1Rev(8) != 1
            || dhsT62L1Rev(15) != 1
            || dhsT62L1Rev(0) != 0
            || dhsT62L1Rev(19) != 0
        )
            ++bad;
        // the 2nd through 4th level reversible pins - create spring, detect
        // charm, know motivation; the seven 3rd level and seven 4th level
        // marks
    if (dhsT62L2Rev(3) != 1
            || dhsT62L2Rev(4) != 1
            || dhsT62L2Rev(10) != 1
            || dhsT62L3Rev(1) != 1
            || dhsT62L3Rev(2) != 1
            || dhsT62L3Rev(7) != 1
            || dhsT62L3Rev(10) != 1
            || dhsT62L3Rev(13) != 1
            || dhsT62L3Rev(16) != 1
            || dhsT62L3Rev(17) != 1
            || dhsT62L4Rev(0) != 1
            || dhsT62L4Rev(1) != 1
            || dhsT62L4Rev(2) != 1
            || dhsT62L4Rev(4) != 1
            || dhsT62L4Rev(7) != 1
            || dhsT62L4Rev(11) != 1
            || dhsT62L4Rev(19) != 1
        )
            ++bad;
        // the 5th through 7th level reversible pins with the extents - the
        // six 5th, four 6th and one 7th level marks
    if (dhsT62L5Rev(4) != 1
            || dhsT62L5Rev(5) != 1
            || dhsT62L5Rev(6) != 1
            || dhsT62L5Rev(8) != 1
            || dhsT62L5Rev(9) != 1
            || dhsT62L5Rev(11) != 1
            || dhsT62L5Rev(12) != -99
            || dhsT62L6Rev(0) != 1
            || dhsT62L6Rev(2) != 1
            || dhsT62L6Rev(3) != 1
            || dhsT62L6Rev(9) != 1
            || dhsT62L7Rev(10) != 1
            || dhsT62L7Rev(11) != 0
            || dhsT62L7Rev(12) != -99
        )
            ++bad;
        // the count pins - seven levels, 116 spells, the longest level
        // twenty, four levels of twenty and three of twelve
    if (dhsT62LevelCount() != 7
            || dhsT62SpellTotal() != 116
            || dhsT62OrdinalMax() != 20
            || dhsT62L1Spells() != 20
            || dhsT62L4Spells() != 20
            || dhsT62L5Spells() != 12
            || dhsT62L7Spells() != 12
        )
            ++bad;
        printf("R658 OA shukenja spells audit: bad %d\n", bad);
        if (bad) return 1;
    }
