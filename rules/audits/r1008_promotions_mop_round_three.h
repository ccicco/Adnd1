    // ---- R1008 promotions mop round three audit ----
    // THE PROMOTIONS MOP ROUND THREE - the MM1 collation half, the second
    // half of the naive-era data-quality pass. 222 glyph-bearing defs
    // repaired: 731 0x14 control codes restored to the print em-dash, 77
    // U+FFFD glyphs adjudicated against the 1977 print voice (10 degrees, 67
    // halves), three stat-field glyphs normalized to the landed convention
    // (the mold hitDice to Nil, the war dog noAppearing to n/a). The two lost
    // texts recovered from the print voice: the Copper Dragon (p. 32, three
    // paragraphs) and the Monoclonius (p. 24, one paragraph), every OCR
    // garble adjudicated. The MM1 text census reads 408 of 408 - the
    // data-quality pass complete; the battery line holds loaded 1338, errors
    // 0.
    {
        using namespace rules;
        int bad = 0;
    if (pm3Round() != 1008
            || pm3DefsRepaired() != 222
            || pm3EmdashFixes() != 731
            || pm3UfffdFixes() != 77
            || pm3StatFieldFixes() != 3
            || pm3TextsRecovered() != 2
            || pm3PatchEntries() != 444
            || pm3Mm1DefsTotal() != 408
            || pm3Mm1TextedAfter() != 408
            || !pm3SingleVoiceProvenance()
            || !pm3GlyphRoundTripGreen()
            || !pm3TextCensusComplete()
        )
            ++bad;
        // the repair census - 222 defs across the two glyph classes: 731
        // em-dash restorations, 77 adjudicated replacement glyphs
    if (pm3Round() != 1008
            || pm3DefsRepaired() != 222
            || pm3EmdashFixes() != 731
            || pm3UfffdFixes() != 77
        )
            ++bad;
        // the collation census - three stat-field normalizations, two texts
        // recovered from the print voice, the MM1 text census 408 of 408
    if (pm3StatFieldFixes() != 3
            || pm3TextsRecovered() != 2
            || pm3PatchEntries() != 444
            || pm3Mm1DefsTotal() != 408
            || pm3Mm1TextedAfter() != 408
        )
            ++bad;
        // the round doctrines - single-voice provenance, green round trip,
        // the completed text census
    if (pm3SingleVoiceProvenance() != 1
            || pm3GlyphRoundTripGreen() != 1
            || pm3TextCensusComplete() != 1
        )
            ++bad;
        printf("R1008 promotions mop round three audit: bad %d\n", bad);
        if (bad) return 1;
    }
