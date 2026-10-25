    // ---- R227: the wis mental save wiring audit ----


    // PHB Wisdom Table I: the magical attack
    // saving throw adjustment now reaches the
    // spell save rolls - the R192 ladder had
    // zero callers. The gate seam
    // rules::wisMentalSaveAdj (wisdom.h); the
    // delegation spells::spellSaveModWis; the
    // spelleffects fold (saveBonus carries the
    // gated ladder; the descriptor carries the
    // defender WIS). Charm person and charm
    // monster are the registry mental forms.
    {
        int bad = 0;
        if (rules::wisMentalSaveAdj(3, true) != -3 ||
            rules::wisMentalSaveAdj(4, true) != -2 ||
            rules::wisMentalSaveAdj(5, true) != -1 ||
            rules::wisMentalSaveAdj(7, true) != -1 ||
            rules::wisMentalSaveAdj(8, true) != 0 ||
            rules::wisMentalSaveAdj(14, true) != 0 ||
            rules::wisMentalSaveAdj(15, true) != 1 ||
            rules::wisMentalSaveAdj(16, true) != 2 ||
            rules::wisMentalSaveAdj(17, true) != 3 ||
            rules::wisMentalSaveAdj(18, true) != 4) ++bad;
        // the ladder clamps (below 3, above 18)
        if (rules::wisMentalSaveAdj(0, true) != -3 ||
            rules::wisMentalSaveAdj(19, true) != 4 ||
            rules::wisMentalSaveAdj(25, true) != 4) ++bad;
        // non-mental forms read flat 0
        if (rules::wisMentalSaveAdj(18, false) != 0 ||
            rules::wisMentalSaveAdj(3, false) != 0 ||
            rules::wisMentalSaveAdj(10, false) != 0) ++bad;
        // ladder consistency: the gated form
        // equals the R192 ladder cell by cell
        for (int w = 3; w <= 18; ++w)
            if (rules::wisMentalSaveAdj(w, true) !=
                    rules::wisMagicalAttackAdj(w) ||
                rules::wisMentalSaveAdj(w, false) != 0) ++bad;
        // the fold: an existing caller-side
        // saveBonus rides WITH the gate, not
        // instead of it (+2 probe)
        static const int kW[5] = { 3, 8, 12, 15, 18, };
        for (int i = 0; i < 5; ++i)
            if (rules::wisMentalSaveAdj(kW[i], true) + 2 !=
                    rules::wisMagicalAttackAdj(kW[i]) + 2) ++bad;
        for (int i = 0; i < 5; ++i)
            if (rules::wisMentalSaveAdj(kW[i], false) + 2 != 2) ++bad;
        printf("R227 wis mental save wiring audit: bad %d\n", bad);
        if (bad) return 1;
    }
