    // ---- R668 OA fate audit ----
    // OA round fifty-five (capture p. 135): Table 65 - the fate table of the
    // fourth level fate spell, the twelve 1d20 bands with their face widths,
    // cross-checked between the passes
    {
        using namespace rules;
        int bad = 0;
    if (didT65BandCount() != 12
            || didT65DieFaces() != 20
            || didT65SingleFaceBands() != 6
            || didT65TwoFaceBands() != 4
            || didT65WidestBands() != 3
            || didT65FateLimit() != 1
        )
            ++bad;
        // the fate grid: the band face widths by ordinal - the outcome prose
        // is narrative, not pinned cells
        int CT65Data[12][1] = {
            {1},
            {1},
            {1},
            {2},
            {2},
            {2},
            {3},
            {3},
            {2},
            {1},
            {1},
            {1},
            };
        for (int b = 0;
             b < didT65BandCount();
             ++b) {
            int vals[1];
            vals[0] = didT65Faces(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CT65Data[b][c])
                    ++bad;
            }
        }
        // the didT65FateBand band-for boundaries
    if (didT65FateBand(0) != 0
            || didT65FateBand(1) != 0
            || didT65FateBand(2) != 1
            || didT65FateBand(2) != 1
            || didT65FateBand(3) != 2
            || didT65FateBand(3) != 2
            || didT65FateBand(5) != 3
            || didT65FateBand(4) != 3
            || didT65FateBand(7) != 4
            || didT65FateBand(6) != 4
            || didT65FateBand(9) != 5
            || didT65FateBand(8) != 5
            || didT65FateBand(12) != 6
            || didT65FateBand(10) != 6
            || didT65FateBand(15) != 7
            || didT65FateBand(13) != 7
            || didT65FateBand(17) != 8
            || didT65FateBand(16) != 8
            || didT65FateBand(18) != 9
            || didT65FateBand(18) != 9
            || didT65FateBand(19) != 10
            || didT65FateBand(19) != 10
            || didT65FateBand(20) != 11
        )
            ++bad;
        // the count pins - twelve bands, the 1d20 faces, the six single-face
        // and four two-face bands, the three-face widest bands, the one-fate
        // limit
    if (didT65BandCount() != 12
            || didT65DieFaces() != 20
            || didT65SingleFaceBands() != 6
            || didT65TwoFaceBands() != 4
            || didT65WidestBands() != 3
            || didT65FateLimit() != 1
        )
            ++bad;
        // the chain pins - the 1d20 roll mapped to its band: rolls 1, 2 and 3
        // the bands 0-2, the paired bands through 17, the single-face tail
        // bands 18, 19 and 20
    if (didT65FateBand(1) != 0
            || didT65FateBand(2) != 1
            || didT65FateBand(3) != 2
            || didT65FateBand(4) != 3
            || didT65FateBand(5) != 3
            || didT65FateBand(7) != 4
            || didT65FateBand(9) != 5
            || didT65FateBand(12) != 6
            || didT65FateBand(15) != 7
            || didT65FateBand(17) != 8
            || didT65FateBand(18) != 9
            || didT65FateBand(19) != 10
            || didT65FateBand(20) != 11
        )
            ++bad;
        // the width grid pins - the six single-face ladder ends, the four
        // two-face pairs, the two three-face widest bands
    if (didT65Faces(0) != 1
            || didT65Faces(2) != 1
            || didT65Faces(9) != 1
            || didT65Faces(11) != 1
            || didT65Faces(3) != 2
            || didT65Faces(5) != 2
            || didT65Faces(8) != 2
            || didT65Faces(6) != 3
            || didT65Faces(7) != 3
        )
            ++bad;
        // the width sum pins - the widths sum to the twenty faces of the die,
        // checked as the ladder-end, pair and widest subtotals
    if (didT65Faces(0) + didT65Faces(1) + didT65Faces(2) != 3
            || didT65Faces(3) + didT65Faces(4) + didT65Faces(5) != 6
            || didT65Faces(6) + didT65Faces(7) != 6
            || didT65Faces(8) != 2
            || didT65Faces(9) + didT65Faces(10) + didT65Faces(11) != 3
            || didT65DieFaces() != 20
        )
            ++bad;
        // the band census pins - the count of one-face and two-face bands
        // matches the consts, checked band by band
    if (didT65SingleFaceBands() != 6
            || didT65TwoFaceBands() != 4
            || didT65WidestBands() != 3
        )
            ++bad;
        printf("R668 OA fate audit: bad %d\n", bad);
        if (bad) return 1;
    }
