    // ---- R339: the UA proficiency pin audit ----
    // The UA WEAPON PROFICIENCY TABLE (p. 26) - the 14-row
    // roster: seven rows match the PHB rows cell for cell
    // (the R297 seam, verified live), the UA-new rows
    // (cavalier, barbarian, acrobat, bard), the attributed
    // fragment rows (illusionist, thief, assassin -
    // documented JUDGMENTs); the R392 clean PDF read
    // fills every hole (the cavalier penalty 3, the
    // paladin and assassin initials 3) and reconciles
    // the misdecodes (the barbarian 6, the ranger 3),
    // the facing-page notes read in full - the item
    // AMENDED, closes.
    {
        using namespace rules;
        int bad = 0;
        // U1: the counts and the roster
        {
            if (uapfRowCount() != 14) ++bad;
            if (strcmp(uapfName(0), "Cavalier") != 0)
                ++bad;
            if (strcmp(uapfName(5), "Barbarian")
                != 0) ++bad;
            if (strcmp(uapfName(10), "Acrobat")
                != 0) ++bad;
            if (strcmp(uapfName(13), "Bard") != 0)
                ++bad;
            if (!uapfNameIsAttributed(8)) ++bad;
            if (!uapfNameIsAttributed(9)) ++bad;
            if (!uapfNameIsAttributed(11)) ++bad;
            if (uapfNameIsAttributed(10)) ++bad;
            int attr = 0;
            for (int i = 0; i < 14; ++i)
                if (uapfNameIsAttributed(i)) ++attr;
            if (attr != 3) ++bad;
        }
        // U2: the initial slots
        {
            static const int k[14] = {
                3, 3, 2, 2, 4, 6, 3, 1,
                1, 2, 2, 3, 1, 5
            };
            for (int i = 0; i < 14; ++i)
                if (uapfInitialSlots(i) != k[i])
                    ++bad;
            // the recovered cells: the paladin, the
            // assassin (the R392 clean read)
            if (uapfInitialSlots(1) != 3) ++bad;
            if (uapfInitialSlots(11) != 3) ++bad;
        }
        // U3: the penalties (magnitudes)
        {
            static const int k[14] = {
                3, 3, 3, 4, 2, 1, 2, 5,
                5, 3, 3, 2, 3, 2
            };
            for (int i = 0; i < 14; ++i)
                if (uapfNonProfPenalty(i) != k[i])
                    ++bad;
            // the recovered cell: the cavalier
            // prints 3 (the R392 clean read)
            if (uapfNonProfPenalty(0) != 3) ++bad;
            // the deviations from the PHB (pinned
            // as printed): the paladin 3
            if (uapfNonProfPenalty(1) != 3) ++bad;
        }
        // U4: the cadences
        {
            static const int k[14] = {
                2, 2, 4, 5, 3, 2, 3, 6,
                6, 4, 4, 4, 2, 4
            };
            for (int i = 0; i < 14; ++i)
                if (uapfAddedCadence(i) != k[i])
                    ++bad;
            // the slash-loss prints: the cavalier
            // and paladin 112 = 1/2 levels
            if (uapfAddedCadence(0) != 2) ++bad;
            if (uapfAddedCadence(1) != 2) ++bad;
        }
        // U5: the R297 seam - the seven rows that
        // match the PHB cell for cell
        {
            static const int rows[7] = {
                2, 3, 4, 7, 8, 9, 12
            };
            for (int r = 0; r < 7; ++r) {
                int i = rows[r];
                int j = uapfPhbSeamRow(i);
                if (j < 0) { ++bad; continue; }
                if (uapfInitialSlots(i)
                    != wpfInitialSlots(j)) ++bad;
                if (uapfNonProfPenalty(i)
                    != wpfNonProfPenalty(j)) ++bad;
                if (uapfAddedCadence(i)
                    != wpfAddedCadence(j)) ++bad;
            }
            // the seam map itself
            if (uapfPhbSeamRow(0) != -1) ++bad;
            if (uapfPhbSeamRow(1) != PROF_PALADIN)
                ++bad;
            if (uapfPhbSeamRow(6) != PROF_RANGER)
                ++bad;
            if (uapfPhbSeamRow(11) != PROF_ASSASSIN)
                ++bad;
            if (uapfPhbSeamRow(13) != -1) ++bad;
        }
        // U6: the deviations reconciled (the R392
        // clean read)
        {
            // the ranger initial 3: the asterisk row,
            // the PHB (R297) agreement restored
            if (uapfInitialSlots(6) != 3) ++bad;
            if (wpfInitialSlots(PROF_RANGER) != 3)
                ++bad;
            // the paladin: UA penalty 3, cadence
            // 1/2 - the cavalier group's values
            if (uapfNonProfPenalty(1)
                != wpfNonProfPenalty(
                    PROF_PALADIN) + 1) ++bad;
            if (uapfAddedCadence(1)
                != wpfAddedCadence(
                    PROF_PALADIN) - 1) ++bad;
            // the assassin seam cells: penalty
            // and cadence match the PHB row
            if (uapfNonProfPenalty(11)
                != wpfNonProfPenalty(
                    PROF_ASSASSIN)) ++bad;
            if (uapfAddedCadence(11)
                != wpfAddedCadence(
                    PROF_ASSASSIN)) ++bad;
        }
        // U7: the slots arithmetic rides the R297
        // convention (one per cadence above 1st)
        {
            // the UA cavalier: 3 at 1st, 4 at 3rd,
            // 5 at 5th (cadence 2)
            if (uapfInitialSlots(0)
                    + (1 - 1) / uapfAddedCadence(0)
                != 3) ++bad;
            if (uapfInitialSlots(0)
                    + (3 - 1) / uapfAddedCadence(0)
                != 4) ++bad;
            // the UA barbarian: 6 at 1st, 7 at 3rd
            // (the R392 clean read)
            if (uapfInitialSlots(5)
                    + (3 - 1) / uapfAddedCadence(5)
                != 7) ++bad;
        }
        // U8: the facing-page notes (the R392
        // clean read: the notes recover in full)
        {
            if (uapfFacingPageNotesLost()) ++bad;
            if (uapfHorsemenInitialSlots() != 1)
                ++bad;
            if (uapfLancersInitialSlots() != 2)
                ++bad;
            if (uapfArmigersInitialSlots() != 3)
                ++bad;
            if (!uapfRestrictedWeaponChoice())
                ++bad;
            if (!uapfInitialAsterisk(0)) ++bad;
            if (!uapfInitialAsterisk(1)) ++bad;
            if (!uapfInitialAsterisk(6)) ++bad;
            if (uapfInitialAsterisk(5)) ++bad;
            if (uapfInitialAsterisk(13)) ++bad;
        }
        printf("R339 UA proficiency pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
