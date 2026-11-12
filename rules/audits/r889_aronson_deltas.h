    // ---- R889 Aronson deltas audit ----
    // THE ARONSON ILLUSIONIST DELTAS - Round C of the Dragon walk, deltas
    // only on the variant layer. THE XP PROGRESSION (folio 23): his 11th-14th
    // illusionist ladder - 525,000 / 700,000 / 875,000 / 1,050,000, a flat
    // 175,000-point step, diverging from the 1e PHB ladder the engine already
    // canonizes (r183/r229). THE MANUFACTURE AND SAVE NOTES (folio 25): minor
    // items (talking puppets, toys) from the 9th level, illusionist scrolls
    // and illusion wands from the 10th, and illusionists +4 on saves vs
    // things involving illusions or light. THE SPELL DELTAS (folios 23, 25):
    // Dispel Exhaustion - the non-canon 3rd-level spell, the illusion of
    // being rested with twice the rest owed after, the raised-and-wounded
    // clause at 1-6 extra damage; the borrowed-MU doctrine (eight MU spells
    // ride his list, Ventriloquism altered to range 9 and duration 5 turns);
    // and his Prismatic Spray - a d8 where 8 means two colors, roll again
    // twice ignoring 8s, seated at the 6th level where the PHB canon seats it
    // 7th. HONEST BOUNDARIES: deltas only per the issue-1 adjudication - the
    // spells Aronson listed that 1e later canonized ride the existing canon
    // layers untouched, never re-pinned here; all ink is OD&D-era variant,
    // converted, noted, never silent. The Round B gap box flips this round -
    // the dragon report's second flip.
    {
        using namespace rules;
        int bad = 0;
    if (arnXp11() != 525000
            || arnXp12() != 700000
            || arnXp13() != 875000
            || arnXp14() != 1050000
            || arnMinorItemLevel() != 9
            || arnScrollWandLevel() != 10
            || arnIllusionSaveBonus() != 4
            || arnSprayDie() != 8
            || arnRaisedExtraDamage() != 6
            || !arnDispelExhaustion()
            || !arnRestDebtDoubled()
            || !arnBorrowedMuSpells()
            || !arnSprayTwoColorOnEight()
            || !arnSpraySeatedSixth()
        )
            ++bad;
        // the 11th-level entry - his table opener (folio 23)
    if (arnXp11() != 525000
        )
            ++bad;
        // the 12th-level entry (folio 23)
    if (arnXp12() != 700000
        )
            ++bad;
        // the 13th- and 14th-level entries - the top of his printed table
        // (folio 23)
    if (arnXp13() != 875000
            || arnXp14() != 1050000
        )
            ++bad;
        // the ladder arithmetic - a flat 175,000-point step from 11th to 12th
    if (arnXp12() - arnXp11() != 175000
        )
            ++bad;
        // the step holds all the way up - 12th to 13th and 13th to 14th
    if (arnXp13() - arnXp12() != 175000
            || arnXp14() - arnXp13() != 175000
        )
            ++bad;
        // the manufacture thresholds - minor items at 9th, scrolls and wands
        // at 10th (folio 25 note)
    if (arnMinorItemLevel() != 9
            || arnScrollWandLevel() != 10
        )
            ++bad;
        // the +4 save vs things involving illusions or light (folio 25 note)
    if (arnIllusionSaveBonus() != 4
        )
            ++bad;
        // the spray mechanic - the d8 and the 8-means-two-colors read (folio
        // 25)
    if (arnSprayDie() != 8
            || arnSprayTwoColorOnEight() != 1
        )
            ++bad;
        // his 6th-level seating of Prismatic Spray - the divergence from the
        // PHB 7th, noted, never silent (folio 23)
    if (arnSpraySeatedSixth() != 1
        )
            ++bad;
        // the non-canon spell and its price - the illusion of rest, twice the
        // rest owed after (folio 23)
    if (arnDispelExhaustion() != 1
            || arnRestDebtDoubled() != 1
        )
            ++bad;
        // the borrowed-MU doctrine - eight MU spells ride the illusionist
        // list (folios 23, 25)
    if (arnBorrowedMuSpells() != 1
        )
            ++bad;
        // the raised-and-wounded clause - move normally, 1-6 extra points of
        // damage (folio 23)
    if (arnRaisedExtraDamage() != 6
        )
            ++bad;
        printf("R889 Aronson deltas audit: bad %d\n", bad);
        if (bad) return 1;
    }
