    // ---- R669 OA wu jen spell list audit ----
    // OA round fifty-six (capture pp. 153-155): Table 66 - the wu jen spell
    // list by level, the per-level spell counts with the elemental marks,
    // cross-checked level by level between the passes
    {
        using namespace rules;
        int bad = 0;
    if (dieWJT66LevelCount() != 9
            || dieWJT66SpellTotal() != 195
            || dieWJT66OrdinalMax() != 30
            || dieWJT66L1Spells() != 30
            || dieWJT66L2Spells() != 30
            || dieWJT66L3Spells() != 24
            || dieWJT66L4Spells() != 24
            || dieWJT66L5Spells() != 24
            || dieWJT66L6Spells() != 24
            || dieWJT66L7Spells() != 12
            || dieWJT66L8Spells() != 14
            || dieWJT66L9Spells() != 13
            || dieWJT66AirCount() != 13
            || dieWJT66EarthCount() != 16
            || dieWJT66FireCount() != 11
            || dieWJT66WaterCount() != 10
            || dieWJT66NatureCount() != 7
            || dieWJT66WoodCount() != 1
            || dieWJT66AllCount() != 4
            || dieWJT66DualCount() != 2
            || dieWJT66UntaggedCount() != 131
            || dieWJT66MemorizeHours() != 6
            || dieWJT66StartRoll() != 3
        )
            ++bad;
        // the wu jen spell list grid: the elemental marks by spell ordinal
        // and level
        int CWJT66Data[30][9] = {
            {0,0,3,0,0,0,0,0,0},
            {5,0,8,0,0,0,0,0,2},
            {0,4,0,0,0,0,0,1,0},
            {1,0,0,2,4,0,0,0,0},
            {0,0,0,0,7,0,4,0,0},
            {0,0,0,0,1,0,0,3,3},
            {5,0,0,7,0,2,0,0,0},
            {7,0,0,0,3,4,0,0,0},
            {3,3,0,3,5,0,0,0,0},
            {0,1,0,0,0,2,0,0,0},
            {2,0,0,3,2,2,0,1,0},
            {0,4,0,0,2,0,0,0,4},
            {0,0,0,5,2,4,-99,0,0},
            {0,0,0,5,0,0,-99,1,-99},
            {0,0,0,0,0,0,-99,-99,-99},
            {3,0,2,0,0,0,-99,-99,-99},
            {0,0,0,0,2,0,-99,-99,-99},
            {0,0,0,0,0,0,-99,-99,-99},
            {0,0,1,0,0,2,-99,-99,-99},
            {0,3,7,0,0,0,-99,-99,-99},
            {0,0,2,0,2,0,-99,-99,-99},
            {0,1,0,0,2,0,-99,-99,-99},
            {4,1,0,0,9,0,-99,-99,-99},
            {4,1,5,3,5,2,-99,-99,-99},
            {0,0,-99,-99,-99,-99,-99,-99,-99},
            {0,0,-99,-99,-99,-99,-99,-99,-99},
            {1,1,-99,-99,-99,-99,-99,-99,-99},
            {6,0,-99,-99,-99,-99,-99,-99,-99},
            {4,1,-99,-99,-99,-99,-99,-99,-99},
            {0,0,-99,-99,-99,-99,-99,-99,-99},
            };
        int nWJT66Data[9] = {0,0,0,0,0,0,0,0,0};
        int eWJT66Data[9] = {0,0,6,6,6,6,18,16,17};
        for (int b = 0;
             b < dieWJT66OrdinalMax();
             ++b) {
            int vals[9];
            vals[0] = dieWJT66L1Element(b);
            vals[1] = dieWJT66L2Element(b);
            vals[2] = dieWJT66L3Element(b);
            vals[3] = dieWJT66L4Element(b);
            vals[4] = dieWJT66L5Element(b);
            vals[5] = dieWJT66L6Element(b);
            vals[6] = dieWJT66L7Element(b);
            vals[7] = dieWJT66L8Element(b);
            vals[8] = dieWJT66L9Element(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CWJT66Data[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nWJT66Data[c];
            }
        }
        for (int c = 0; c < 9; ++c)
            if (nWJT66Data[c] != eWJT66Data[c])
                ++bad;
        // the count pins - nine levels, 195 spells total, the ordinal max 30,
        // and the per-level counts
    if (dieWJT66LevelCount() != 9
            || dieWJT66SpellTotal() != 195
            || dieWJT66OrdinalMax() != 30
            || dieWJT66L1Spells() != 30
            || dieWJT66L2Spells() != 30
            || dieWJT66L3Spells() != 24
            || dieWJT66L4Spells() != 24
            || dieWJT66L5Spells() != 24
            || dieWJT66L6Spells() != 24
            || dieWJT66L7Spells() != 12
            || dieWJT66L8Spells() != 14
            || dieWJT66L9Spells() != 13
        )
            ++bad;
        // the level-sum identity pins - the per-level counts sum to the spell
        // total
    if (dieWJT66L1Spells() + dieWJT66L2Spells() + dieWJT66L3Spells() +
        dieWJT66L4Spells() != 108
            || dieWJT66L5Spells() + dieWJT66L6Spells() + dieWJT66L7Spells() +
            dieWJT66L8Spells() + dieWJT66L9Spells() != 87
            || dieWJT66SpellTotal() != 108 + 87
        )
            ++bad;
        // the element census pins - Earth the most common at 16, Air 13, Fire
        // 11, Water 10, Nature 7, the single Wood mark, the four All marks,
        // the two duals and the 131 untagged
    if (dieWJT66AirCount() != 13
            || dieWJT66EarthCount() != 16
            || dieWJT66FireCount() != 11
            || dieWJT66WaterCount() != 10
            || dieWJT66NatureCount() != 7
            || dieWJT66WoodCount() != 1
            || dieWJT66AllCount() != 4
            || dieWJT66DualCount() != 2
            || dieWJT66UntaggedCount() != 131
        )
            ++bad;
        // the element-sum identity pins - the tagged elements plus the
        // untagged sum to the spell total
    if (dieWJT66AirCount() + dieWJT66EarthCount() + dieWJT66FireCount() +
        dieWJT66WaterCount() + dieWJT66NatureCount() + dieWJT66WoodCount() +
        dieWJT66AllCount() + dieWJT66DualCount() + dieWJT66UntaggedCount() !=
        dieWJT66SpellTotal()
        )
            ++bad;
        // the first level element pins - animate wood and drowsy insects
        // Nature, cloud ladder and wall of fog Air, elemental burst All,
        // fiery eyes and melt Fire, hail of stone Earth, still water, swim
        // and water protection Water, warp wood the lone Wood mark, accuracy
        // and the other eleven untagged
    if (dieWJT66L1Element(1) != 5
            || dieWJT66L1Element(6) != 5
            || dieWJT66L1Element(3) != 1
            || dieWJT66L1Element(26) != 1
            || dieWJT66L1Element(7) != 7
            || dieWJT66L1Element(8) != 3
            || dieWJT66L1Element(15) != 3
            || dieWJT66L1Element(10) != 2
            || dieWJT66L1Element(22) != 4
            || dieWJT66L1Element(23) != 4
            || dieWJT66L1Element(28) != 4
            || dieWJT66L1Element(27) != 6
            || dieWJT66L1Element(0) != 0
            || dieWJT66L1Element(14) != 0
        )
            ++bad;
        // the second level element pins - the six Air marks (fog cloud, smoke
        // shape, smoky form, stinking cloud, wind breath, whispering wind),
        // animate water and ice knife Water, fire shuriken and pyrotechnics
        // Fire
    if (dieWJT66L2Element(9) != 1
            || dieWJT66L2Element(21) != 1
            || dieWJT66L2Element(22) != 1
            || dieWJT66L2Element(23) != 1
            || dieWJT66L2Element(26) != 1
            || dieWJT66L2Element(28) != 1
            || dieWJT66L2Element(2) != 4
            || dieWJT66L2Element(11) != 4
            || dieWJT66L2Element(8) != 3
            || dieWJT66L2Element(19) != 3
        )
            ++bad;
        // the middle level element pins - cloudburst the Water/Air dual 8,
        // water to poison the Nature/Water dual 9, glassee Earth (the print
        // OCR reading Glasses, the compressed Glassee settling the PHB name),
        // the All marks at scry, elemental turning and conjure elemental
    if (dieWJT66L3Element(1) != 8
            || dieWJT66L5Element(22) != 9
            || dieWJT66L6Element(6) != 2
            || dieWJT66L3Element(19) != 7
            || dieWJT66L4Element(6) != 7
            || dieWJT66L5Element(4) != 7
        )
            ++bad;
        // the high level element pins - ice blight the lone seventh level
        // mark, the three Air marks and incendiary cloud Fire at the eighth,
        // crystalbrittle Earth, internal fire Fire and tsunami Water at the
        // ninth
    if (dieWJT66L7Element(4) != 4
            || dieWJT66L8Element(2) != 1
            || dieWJT66L8Element(10) != 1
            || dieWJT66L8Element(13) != 1
            || dieWJT66L8Element(5) != 3
            || dieWJT66L9Element(1) != 2
            || dieWJT66L9Element(5) != 3
            || dieWJT66L9Element(11) != 4
        )
            ++bad;
        // the memorization pins - the six hours of restful meditation and the
        // 3d6 starting spell roll
    if (dieWJT66MemorizeHours() != 6
            || dieWJT66StartRoll() != 3
        )
            ++bad;
        printf("R669 OA wu jen spell list audit: bad %d\n", bad);
        if (bad) return 1;
    }
