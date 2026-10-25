    // ---- R449 WSG reduced visibility pin audit ----
    // The reduced visibility slice pins the daylight assumption behind the
    // previously described rates, the other-factors-first multiplication by
    // the Table 23 entry (the 1/1 clear-daylight cell means no further
    // reduction), the on-foot daylight hazard avoidance (no trees, no roots)
    // with the night exception (a pit or cliff unless the surface is tested
    // or probed), the infravision heat-only detection (a warm-blooded ambush
    // yes, a cliff edge usually no), the Dexterity Check above the maximum
    // safe speed with the blunder/stop-short consequences (saddle, wagon
    // seat, chariot front) and the twice-the-figure cap, and Table 23 (the
    // three light rows x the five visibility conditions, the fractions from
    // 1/1 down to 1/8) (rules/wsgvis.h, prefix wsv); census 373 -> 374.
    {
        using namespace rules;
        int bad = 0;
    if (wsvLightCount() != 3
            || wsvCondCount() != 5
            || wsvSpeedCapMult() != 2
            || !wsvRatesAssumeDaylight()
            || !wsvOtherFactorsFirst()
            || !wsvDaylightClearNoCut()
            || !wsvDaylightFootHazardSafe()
            || !wsvNightHazardsRemain()
            || !wsvInfravisionHeatOnly()
            || !wsvFasterNeedsDexCheck()
            || !wsvBlunderConsequences()
        )
            ++bad;
        // the Table 23 grid: the three light rows (daylight, moonlight,
        // darkness) x the five visibility conditions (clear, moderate fog,
        // heavy fog or snow, heavy snow with wind, blowing sand or dust),
        // each cell split into the numerator and denominator of the maximum
        // safe speed fraction - from 1/1 down to 1/8
        int C23[3][10] = {
            {1,1,5,6,3,4,2,3,1,2},
            {2,3,1,2,1,3,1,4,1,6},
            {1,2,1,3,1,4,1,6,1,8},
            };
        for (int b = 0;
             b < wsvLightCount();
             ++b) {
            int vals[10];
            vals[0] = wsvNumClear(b);
            vals[1] = wsvDenClear(b);
            vals[2] = wsvNumModFog(b);
            vals[3] = wsvDenModFog(b);
            vals[4] = wsvNumHeavyFog(b);
            vals[5] = wsvDenHeavyFog(b);
            vals[6] = wsvNumHeavySnow(b);
            vals[7] = wsvDenHeavySnow(b);
            vals[8] = wsvNumBlowing(b);
            vals[9] = wsvDenBlowing(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != C23[b][c])
                    ++bad;
            }
        }
        // the two extremes: 1/1 in clear daylight (no further reduction) and
        // 1/8 in blowing sand or dust at night (the sandstorm-in-darkness
        // example)
    if (wsvNumClear(0) != 1
            || wsvDenClear(0) != 1
            || wsvNumBlowing(2) != 1
            || wsvDenBlowing(2) != 8
        )
            ++bad;
        // the mid-grid printed pair: 5/6 in daylight moderate fog, 1/4 in
        // moonlight heavy snow with wind
    if (wsvNumModFog(0) != 5
            || wsvDenModFog(0) != 6
            || wsvNumHeavySnow(1) != 1
            || wsvDenHeavySnow(1) != 4
        )
            ++bad;
        // the printed prose numbers: the twice-the-figure speed cap, over the
        // three light rows and the five conditions
    if (wsvSpeedCapMult() != 2
            || wsvLightCount() != 3
            || wsvCondCount() != 5
        )
            ++bad;
        // the daylight row degrades strictly left to right: 1/1 > 5/6 > 3/4 >
        // 2/3 > 1/2, each fraction smaller than the one before it
        // (cross-multiplied)
    if (wsvNumClear(0) * wsvDenModFog(0) <= wsvNumModFog(0) * wsvDenClear(0)
            || wsvNumModFog(0) * wsvDenHeavyFog(0) <= wsvNumHeavyFog(0) *
            wsvDenModFog(0)
            || wsvNumHeavyFog(0) * wsvDenHeavySnow(0) <= wsvNumHeavySnow(0) *
            wsvDenHeavyFog(0)
            || wsvNumHeavySnow(0) * wsvDenBlowing(0) <= wsvNumBlowing(0) *
            wsvDenHeavySnow(0)
        )
            ++bad;
        // the moonlight row degrades strictly left to right: 2/3 > 1/2 > 1/3
        // > 1/4 > 1/6
    if (wsvNumClear(1) * wsvDenModFog(1) <= wsvNumModFog(1) * wsvDenClear(1)
            || wsvNumModFog(1) * wsvDenHeavyFog(1) <= wsvNumHeavyFog(1) *
            wsvDenModFog(1)
            || wsvNumHeavyFog(1) * wsvDenHeavySnow(1) <= wsvNumHeavySnow(1) *
            wsvDenHeavyFog(1)
            || wsvNumHeavySnow(1) * wsvDenBlowing(1) <= wsvNumBlowing(1) *
            wsvDenHeavySnow(1)
        )
            ++bad;
        // the darkness row degrades strictly left to right: 1/2 > 1/3 > 1/4 >
        // 1/6 > 1/8
    if (wsvNumClear(2) * wsvDenModFog(2) <= wsvNumModFog(2) * wsvDenClear(2)
            || wsvNumModFog(2) * wsvDenHeavyFog(2) <= wsvNumHeavyFog(2) *
            wsvDenModFog(2)
            || wsvNumHeavyFog(2) * wsvDenHeavySnow(2) <= wsvNumHeavySnow(2) *
            wsvDenHeavyFog(2)
            || wsvNumHeavySnow(2) * wsvDenBlowing(2) <= wsvNumBlowing(2) *
            wsvDenHeavySnow(2)
        )
            ++bad;
        // darker is always slower: darkness cuts deeper than moonlight, and
        // moonlight deeper than daylight, in the clear column and in the
        // blowing column (cross-multiplied)
    if (wsvNumClear(2) * wsvDenClear(1) >= wsvNumClear(1) * wsvDenClear(2)
            || wsvNumClear(1) * wsvDenClear(0) >= wsvNumClear(0) *
            wsvDenClear(1)
            || wsvNumBlowing(2) * wsvDenBlowing(1) >= wsvNumBlowing(1) *
            wsvDenBlowing(2)
            || wsvNumBlowing(1) * wsvDenBlowing(0) >= wsvNumBlowing(0) *
            wsvDenBlowing(1)
        )
            ++bad;
        printf("R449 WSG reduced visibility pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
