    // ---- R890 Remorhaz lore audit ----
    // THE REMORHAZ LORE PIN - the issue-2 opener (Round A of issue 2), lore
    // on the variant layer per the Bulette pattern. THE INK (folio 21,
    // Creature Features): three sizes on d8 hit dice - 6/10/14 at 40/35/25
    // percent on the d100; the frame - 30 feet, movement 12, 20 percent in
    // lair, 75 percent magic resistance, low intelligence, neutral; armor
    // class underside 4, back 0 plus special, head 2; the bite at 3-36; the
    // fire breath at 3, 5, or 7 dice; and the doctrines - wings and head
    // backed with red (the MM1 polar worm beats small wings but breathes no
    // fire), the heated back protrusions that melt non-magical weapons, and
    // the cold-dwelling fire creature that stalks alongside the Silver Dragon
    // on the Eldritch Wizardry matrix. HONEST BOUNDARIES: the MM1 def
    // monsters/monsters/r/remorhaz.lua is UNTOUCHED and holds the stem -
    // these pins are lore/provenance only, never a competing def; every
    // divergence from the def (his bite 3-36 vs 6-36, his 6/10/14 bands vs
    // 7-14, his fire breath, his low intelligence vs animal, his 30 feet vs
    // 21-42) rides noted, never silent. THE VOICE: all 32 issue-2 pages at
    // extract/dragon/002/pNNN_full.txt plus the pre-flip
    // tools/dragon_gap_report_002.md (4 boxes, 0 closed - the Remorhaz box
    // flips at the next Dragon round) shipped as spec data files. The Aronson
    // box on the issue-1 report flips this round - the issue-1 report closes
    // out at 3 closed / 0 open.
    {
        using namespace rules;
        int bad = 0;
    if (rmzHdSmall() != 6
            || rmzHdMid() != 10
            || rmzHdLarge() != 14
            || rmzHdDie() != 8
            || rmzSmallPct() != 40
            || rmzMidPct() != 35
            || rmzLargePct() != 25
            || rmzLenFeet() != 30
            || rmzMoveInches() != 12
            || rmzPctInLair() != 20
            || rmzMagResPct() != 75
            || rmzAcUnderside() != 4
            || rmzAcBack() != 0
            || rmzAcHead() != 2
            || rmzBiteMin() != 3
            || rmzBiteMax() != 36
            || rmzBreathMinDice() != 3
            || rmzBreathMaxDice() != 7
            || !rmzWingsAndBreath()
            || !rmzBackMeltsWeapons()
            || !rmzColdDwelling()
        )
            ++bad;
        // the small band - 6 hit dice on the d8 (folio 21)
    if (rmzHdSmall() != 6
            || rmzHdDie() != 8
        )
            ++bad;
        // the middle and large bands - 10 and 14 hit dice (folio 21)
    if (rmzHdMid() != 10
            || rmzHdLarge() != 14
        )
            ++bad;
        // the three size chances tile the d100 exactly - 40/35/25 (folio 21)
    if (rmzSmallPct() + rmzMidPct() + rmzLargePct() != 100
        )
            ++bad;
        // the middle and large encounter chances (folio 21)
    if (rmzMidPct() != 35
            || rmzLargePct() != 25
        )
            ++bad;
        // the bite spread, 3-36 - the Dragon read, not the def's 6-36
    if (rmzBiteMax() - rmzBiteMin() != 33
        )
            ++bad;
        // the fire breath - 3, 5, or 7 dice (folio 21)
    if (rmzBreathMinDice() != 3
            || rmzBreathMaxDice() != 7
        )
            ++bad;
        // the 75 percent magic resistance (folio 21)
    if (rmzMagResPct() != 75
        )
            ++bad;
        // the three armor classes - underside 4, back 0 plus special, head 2
        // (folio 21)
    if (rmzAcUnderside() != 4
            || rmzAcBack() != 0
            || rmzAcHead() != 2
        )
            ++bad;
        // the frame - 30 feet, movement 12, 20 percent in lair (folio 21)
    if (rmzLenFeet() != 30
            || rmzMoveInches() != 12
            || rmzPctInLair() != 20
        )
            ++bad;
        // the wings-and-breath doctrine - the Dragon divergence from the MM1
        // polar worm (folio 21)
    if (rmzWingsAndBreath() != 1
        )
            ++bad;
        // the heated back - non-magical weapons melt on it (folio 21)
    if (rmzBackMeltsWeapons() != 1
        )
            ++bad;
        // the cold-dwelling fire creature, the Silver Dragon matrix seat
        // (folio 21)
    if (rmzColdDwelling() != 1
        )
            ++bad;
        printf("R890 Remorhaz lore audit: bad %d\n", bad);
        if (bad) return 1;
    }
