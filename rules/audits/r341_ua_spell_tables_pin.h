    // ---- R341: the UA spell tables pin audit ----
    // The UA SPELL TABLES (pp. 28-31), part 1 - the
    // cleric 1st-3rd table (20 rows, seam-verified
    // against the R80 registry), the cleric 4th-7th
    // fragments, the druid tables (the four readable
    // rows seam-decoded as the 1st-level roster, the
    // "Insect P|" fragment seam-decoded as Insect
    // Plague) and the MU cantrip table (64 names,
    // the Gather/Polish merge decoded). The MU spells
    // tables and the illusionist spell table are
    // OCR-scrambled - the item stays open pending
    // the PDF.
    {
        using namespace rules;
        int bad = 0;
        // U1: the counts
        {
            if (uastClericTableRowCount() != 20) ++bad;
            if (uastClericReadableCount(1) != 18) ++bad;
            if (uastClericReadableCount(2) != 16) ++bad;
            if (uastClericReadableCount(3) != 20) ++bad;
            if (uastClericFragCount(4) != 2) ++bad;
            if (uastClericFragCount(5) != 7) ++bad;
            if (uastClericFragCount(6) != 4) ++bad;
            if (uastClericFragCount(7) != 0) ++bad;
            if (uastDruid1stCount() != 4) ++bad;
            if (uastDruid4thCount() != 6) ++bad;
            if (uastDruid5thCount() != 6) ++bad;
            if (uastDruid6thCount() != 5) ++bad;
            if (uastCantripCategoryCount() != 6) ++bad;
            int total = 0;
            for (int c = 0; c < 6; ++c)
                total += uastCantripCount(c);
            // R401 clean-read fix: Tangle and
            // Tweak print on p. 30 - the roster
            // reads 66, not 64
            if (total != 66) ++bad;
            if (!uastNoteAllCantripsDescribedHere()) ++bad;
        }
        // U2: the cleric 1st column (the two holes)
        {
            if (strcmp(uastClericName(1, 0), "Bless")
                != 0) ++bad;
            if (strcmp(uastClericName(1, 5),
                "Cure Light Wounds") != 0) ++bad;
            if (strcmp(uastClericName(1, 14),
                "Precipitation") != 0) ++bad;
            if (strcmp(uastClericName(1, 19),
                "Sanctuary") != 0) ++bad;
            // the "ct Evil" garble cell - a hole
            if (uastClericName(1, 6)[0] != 0) ++bad;
            // the empty cell - a hole
            if (uastClericName(1, 13)[0] != 0) ++bad;
            int n = 0;
            for (int r = 0; r < 20; ++r)
                if (uastClericName(1, r)[0]) ++n;
            if (n != 18) ++bad;
        }
        // U3: the cleric 2nd and 3rd columns
        {
            if (strcmp(uastClericName(2, 5),
                "Dust Devil") != 0) ++bad;
            if (strcmp(uastClericName(2, 13),
                "Silence 15 Radius") != 0) ++bad;
            if (strcmp(uastClericName(2, 19),
                "Wyvern Watch") != 0) ++bad;
            // the three leading empties, the "draw"
            // garble - holes
            if (uastClericName(2, 0)[0] != 0) ++bad;
            if (uastClericName(2, 18)[0] != 0) ++bad;
            int n = 0;
            for (int r = 0; r < 20; ++r)
                if (uastClericName(2, r)[0]) ++n;
            if (n != 16) ++bad;
            // the 3rd column: all 20 readable
            if (strcmp(uastClericName(3, 0),
                "Animate Dead") != 0) ++bad;
            if (strcmp(uastClericName(3, 14),
                "Negative Plane Protection") != 0)
                ++bad;
            if (strcmp(uastClericName(3, 19),
                "Water Walk") != 0) ++bad;
        }
        // U4: the cleric 4th-7th fragments
        {
            if (strcmp(uastClericFragName(4, 0),
                "Sticks to Snakes") != 0) ++bad;
            if (strcmp(uastClericFragName(4, 1),
                "Tongues") != 0) ++bad;
            if (strcmp(uastClericFragName(5, 0),
                "Commune") != 0) ++bad;
            // the Spike Growth print sits in the 5th
            // column (the PHB reads 3rd) - as printed
            if (strcmp(uastClericFragName(5, 5),
                "Spike Growth") != 0) ++bad;
            if (strcmp(uastClericFragName(5, 6),
                "True Seeing") != 0) ++bad;
            if (strcmp(uastClericFragName(6, 3),
                "Stone Tell") != 0) ++bad;
            // the 7th column: wholly lost
            if (uastClericFragCount(7) != 0) ++bad;
        }
        // U5: the druid tables
        {
            if (strcmp(uastDruid1stName(0),
                "Locate Animals") != 0) ++bad;
            if (strcmp(uastDruid1stName(1),
                "Invisibility to Animals") != 0) ++bad;
            if (strcmp(uastDruid1stName(2),
                "Shillelagh") != 0) ++bad;
            if (strcmp(uastDruid1stName(3),
                "Speak With Animals") != 0) ++bad;
            if (strcmp(uastDruid4thName(0),
                "Cure Serious Wounds") != 0) ++bad;
            if (strcmp(uastDruid4thName(5),
                "Speak With Plants") != 0) ++bad;
            if (strcmp(uastDruid5thName(2),
                "Insect Plague") != 0) ++bad;
            // the Sticks To Snakes deviation: printed
            // in the 5th column, the seam reads 6th
            if (strcmp(uastDruid5thName(3),
                "Sticks To Snakes") != 0) ++bad;
            if (strcmp(uastDruid6thName(0),
                "Cure Critical Wounds") != 0) ++bad;
            if (strcmp(uastDruid6thName(4),
                "Weather Summoning") != 0) ++bad;
        }
        // U6: the cantrip table
        {
            if (strcmp(uastCantripCategoryName(0),
                "Useful") != 0) ++bad;
            if (strcmp(uastCantripCategoryName(5),
                "Haunting") != 0) ++bad;
            if (strcmp(uastCantripName(0, 0),
                "Chill") != 0) ++bad;
            // the merged Gather/Polish cell: two names
            if (strcmp(uastCantripName(0, 9),
                "Gather") != 0) ++bad;
            if (strcmp(uastCantripName(0, 10),
                "Polish") != 0) ++bad;
            if (strcmp(uastCantripName(0, 19),
                "Wrap") != 0) ++bad;
            // R401: Tangle seats at reversed
            // row 9; Wilt moves to 11
            if (strcmp(uastCantripName(1, 8),
                "Tangle") != 0) ++bad;
            if (strcmp(uastCantripName(1, 11),
                "Wilt") != 0) ++bad;
            if (strcmp(uastCantripName(2, 5),
                "Present") != 0) ++bad;
            if (strcmp(uastCantripName(3, 9),
                "Yawn") != 0) ++bad;
            // R401: Tweak seats at personal
            // row 9; Unlock moves to 9
            if (strcmp(uastCantripName(4, 8),
                "Tweak") != 0) ++bad;
            if (strcmp(uastCantripName(4, 9),
                "Unlock") != 0) ++bad;
            if (strcmp(uastCantripName(5, 7),
                "Whistle") != 0) ++bad;
        }
        // U7: the acquisition prose
        {
            if (uastMuCantripMaxNewCount() != 3) ++bad;
            if (!uastMuUsefulOnePerIntPoint()) ++bad;
            if (uastMuReversedMin() != 2) ++bad;
            if (uastMuReversedMax() != 8) ++bad;
            if (uastMuLegerdemainMin() != 2) ++bad;
            if (uastMuLegerdemainMax() != 5) ++bad;
            if (uastMuPersonAffectingMin() != 2) ++bad;
            if (uastMuPersonAffectingMax() != 8) ++bad;
            if (uastMuPersonalMax() != 8) ++bad;
            if (uastMuHauntingMin() != 2) ++bad;
            if (uastMuHauntingMax() != 5) ++bad;
            if (uastIlMinorIllusionMin() != 5) ++bad;
            if (uastIlMinorIllusionMax() != 8) ++bad;
            if (uastIlUsefulIntMinus() != 3) ++bad;
            if (uastIlUsefulAtInt18() != 15) ++bad;
            if (uastIlLegerdemainMin() != 3) ++bad;
            if (uastIlLegerdemainMax() != 6) ++bad;
            if (uastIlPersonalMax() != 5) ++bad;
            if (uastIlHauntingMin() != 5) ++bad;
            if (uastIlHauntingMax() != 8) ++bad;
        }
        // U8: the R80/R228 registry seam (live)
        {
            auto reglvl = [](const char* n,
                spells::SpellClass c) -> int {
                for (int id = 0;
                     id < spells::SPELL_COUNT; ++id) {
                    const spells::SpellDef& d =
                        spells::spell(
                            (spells::SpellId)id);
                    if (d.sclass == c
                        && strcmp(d.name, n) == 0)
                        return d.level;
                }
                return -1;
            };
            using spells::SPELL_CLERIC;
            using spells::SPELL_DRUID;
            // the cleric 1st-3rd columns verify
            if (reglvl("Cure Light Wounds",
                SPELL_CLERIC) != 1) ++bad;
            if (reglvl("Hold Person",
                SPELL_CLERIC) != 2) ++bad;
            if (reglvl("Slow Poison",
                SPELL_CLERIC) != 2) ++bad;
            if (reglvl("Dispel Magic",
                SPELL_CLERIC) != 3) ++bad;
            if (reglvl("Prayer",
                SPELL_CLERIC) != 3) ++bad;
            // the registry quirk: CCW at cleric 4
            if (reglvl("Cure Critical Wounds",
                SPELL_CLERIC) != 4) ++bad;
            // the druid 1st-level decode seam
            if (reglvl("Locate Animals",
                SPELL_DRUID) != 1) ++bad;
            if (reglvl("Invisibility To Animals",
                SPELL_DRUID) != 1) ++bad;
            if (reglvl("Shillelagh",
                SPELL_DRUID) != 1) ++bad;
            if (reglvl("Speak With Animals",
                SPELL_DRUID) != 1) ++bad;
            // the 4th-6th columns verify
            if (reglvl("Cure Serious Wounds",
                SPELL_DRUID) != 4) ++bad;
            if (reglvl("Dispel Magic",
                SPELL_DRUID) != 4) ++bad;
            if (reglvl("Hallucinatory Forest",
                SPELL_DRUID) != 4) ++bad;
            if (reglvl("Repel Insects",
                SPELL_DRUID) != 4) ++bad;
            if (reglvl("Commune With Nature",
                SPELL_DRUID) != 5) ++bad;
            if (reglvl("Control Winds",
                SPELL_DRUID) != 5) ++bad;
            // the Insect P| fragment decode seam
            if (reglvl("Insect Plague",
                SPELL_DRUID) != 5) ++bad;
            // the Sticks To Snakes deviation: the
            // seam reads 6, the print sits in the 5th
            if (reglvl("Sticks to Snakes",
                SPELL_DRUID) != 6) ++bad;
            if (reglvl("Cure Critical Wounds",
                SPELL_DRUID) != 6) ++bad;
            if (reglvl("Turn Wood",
                SPELL_DRUID) != 6) ++bad;
            if (reglvl("Weather Summoning",
                SPELL_DRUID) != 6) ++bad;
        }
        printf("R341 UA spell tables pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
