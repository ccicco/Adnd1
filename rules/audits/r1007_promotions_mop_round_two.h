    // ---- R1007 promotions mop round two audit ----
    // THE PROMOTIONS MOP ROUND TWO - the MM1 text completion, the structural
    // half of the naive-era data-quality pass. 136 of the 138 text-deficient
    // MM1 defs gain their text field, every byte derived mechanically from
    // tools/monsters.md: 25 family carriers, 61 family members, 50 variants.
    // The two excluded defs - the Copper Dragon and the Monoclonius, the only
    // MM1 records with no prose anywhere in the source - await the
    // print-voice collation half. The MM1 text census moves 270 of 408 to 406
    // of 408; the battery line holds loaded 1338, errors 0.
    {
        using namespace rules;
        int bad = 0;
    if (pm2Round() != 1007
            || pm2DefsCompleted() != 136
            || pm2CarrierDefs() != 25
            || pm2FamilyMemberDefs() != 61
            || pm2VariantDefs() != 50
            || pm2DefsExcluded() != 2
            || pm2Mm1DefsTotal() != 408
            || pm2Mm1TextedAfter() != 406
            || !pm2CompletionMechanical()
            || !pm2RoundTripGreen()
            || !pm2CollationHalfRides()
        )
            ++bad;
        // the completion census - 136 defs across the three derivation
        // classes: 25 carriers, 61 family members, 50 variants
    if (pm2Round() != 1007
            || pm2DefsCompleted() != 136
            || pm2CarrierDefs() != 25
            || pm2FamilyMemberDefs() != 61
            || pm2VariantDefs() != 50
        )
            ++bad;
        // the MM1 text census - 406 of 408 after the repair, the Copper
        // Dragon and the Monoclonius the two riding to the collation rounds
    if (pm2DefsExcluded() != 2
            || pm2Mm1DefsTotal() != 408
            || pm2Mm1TextedAfter() != 406
        )
            ++bad;
        // the repair doctrines - mechanical derivation from the source, the
        // parse-back proof green, the collation half riding ahead
    if (pm2CompletionMechanical() != 1
            || pm2RoundTripGreen() != 1
            || pm2CollationHalfRides() != 1
        )
            ++bad;
        printf("R1007 promotions mop round two audit: bad %d\n", bad);
        if (bad) return 1;
    }
