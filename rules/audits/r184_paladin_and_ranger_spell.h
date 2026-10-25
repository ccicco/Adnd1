    // ---- R184: the paladin and ranger spell layers audit ----
    // Every printed slot cell of both progressions,
    // the specials ladders and the giant-class roster.
    {
        int bad = 0;
        // the paladin table, cell by cell (levels 9-20)
        static const int kPal[12][4] = {
            { 1, 0, 0, 0 },
            { 2, 0, 0, 0 },
            { 2, 1, 0, 0 },
            { 2, 2, 0, 0 },
            { 2, 2, 1, 0 },
            { 3, 2, 1, 0 },
            { 3, 2, 1, 1 },
            { 3, 3, 1, 1 },
            { 3, 3, 2, 1 },
            { 3, 3, 3, 1 },
            { 3, 3, 3, 2 },
            { 3, 3, 3, 3 },
        };
        for (int pl = 9; pl <= 20; ++pl)
            for (int sl = 1; sl <= 4; ++sl)
                if (rules::paladinSpellSlots(pl, sl)
                    != kPal[pl-9][sl-1]) ++bad;
        // the ranger table, cell by cell (levels 8-17,
        // druidic 1-3 and MU 1-2)
        static const int kRng[10][5] = {
            { 1, 0, 0, 0, 0 },
            { 1, 0, 0, 1, 0 },
            { 2, 0, 0, 1, 0 },
            { 2, 0, 0, 2, 0 },
            { 2, 1, 0, 2, 1 },
            { 2, 1, 0, 2, 1 },
            { 2, 2, 0, 2, 2 },
            { 2, 2, 0, 2, 2 },
            { 2, 2, 1, 2, 2 },
            { 2, 2, 2, 2, 2 },
        };
        for (int rl = 8; rl <= 17; ++rl) {
            for (int sl = 1; sl <= 3; ++sl)
                if (rules::rangerSpellSlots(rl, 0, sl)
                    != kRng[rl-8][sl-1]) ++bad;
            for (int sl = 1; sl <= 2; ++sl)
                if (rules::rangerSpellSlots(rl, 1, sl)
                    != kRng[rl-8][sl+2]) ++bad;
        }
        // below the spell bands: 0 slots
        if (rules::paladinSpellSlots(8, 1) != 0) ++bad;
        if (rules::paladinSpellSlots(1, 1) != 0) ++bad;
        if (rules::rangerSpellSlots(7, 0, 1) != 0) ++bad;
        if (rules::rangerSpellSlots(9, 1, 1) != 1) ++bad;
        // the clamps: past the max-ability rows
        if (rules::paladinSpellSlots(21, 1) != 3) ++bad;
        if (rules::paladinSpellSlots(99, 4) != 3) ++bad;
        if (rules::rangerSpellSlots(18, 0, 3) != 2) ++bad;
        if (rules::rangerSpellSlots(99, 1, 2) != 2) ++bad;
        // the clamps: spell level out of range reads
        // the band edges (druidic 4 pins as level 3, MU 3
        // as level 2)
        if (rules::rangerSpellSlots(17, 0, 4) != 2) ++bad;
        if (rules::rangerSpellSlots(17, 1, 3) != 2) ++bad;
        // the shared-list wiring
        if (rules::paladinSpellListClass()
            != rules::CLASS_CLERIC) ++bad;
        if (rules::rangerDruidicSpellListClass()
            != rules::CLASS_CLERIC) ++bad;
        if (rules::rangerMagicSpellListClass()
            != rules::CLASS_MAGIC_USER) ++bad;
        // lay on hands: 2 hp per level, once per day
        if (rules::paladinLayOnHandsHp(1) != 2) ++bad;
        if (rules::paladinLayOnHandsHp(9) != 18) ++bad;
        if (rules::paladinLayOnHandsHp(20) != 40) ++bad;
        if (rules::paladinLayOnHandsHp(0) != 0) ++bad;
        // cure disease: one per week per five levels
        if (rules::paladinCureDiseasePerWeek(1) != 1) ++bad;
        if (rules::paladinCureDiseasePerWeek(5) != 1) ++bad;
        if (rules::paladinCureDiseasePerWeek(6) != 2) ++bad;
        if (rules::paladinCureDiseasePerWeek(10) != 2) ++bad;
        if (rules::paladinCureDiseasePerWeek(11) != 3) ++bad;
        if (rules::paladinCureDiseasePerWeek(15) != 3) ++bad;
        if (rules::paladinCureDiseasePerWeek(16) != 4) ++bad;
        // the giant-class roster: 11 creatures
        if (rules::rangerGiantClassCount() != 11) ++bad;
        if (std::string(rules::rangerGiantClassName(0))
            != "bugbear") ++bad;
        if (std::string(rules::rangerGiantClassName(10))
            != "troll") ++bad;
        if (!rules::rangerIsGiantClass("ogre mage")) ++bad;
        if (!rules::rangerIsGiantClass("kobold")) ++bad;
        if (rules::rangerIsGiantClass("lizard man")) ++bad;  // R184b: the ogre probe fix
        if (rules::rangerIsGiantClass("giant frog")) ++bad;
        if (rules::rangerIsGiantClass("")) ++bad;
        // the bonus: +1 per ranger level
        if (rules::rangerGiantClassBonus(5) != 5) ++bad;
        if (rules::rangerGiantClassBonus(17) != 17) ++bad;
        if (rules::rangerGiantClassBonus(0) != 0) ++bad;
        printf("R184 paladin and ranger spell layers audit: bad %d\n", bad);
        if (bad) return 1;
    }
