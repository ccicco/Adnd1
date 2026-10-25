    // ---- R154: PC races audit ---------------------------------
    // PHB pp.15-18, Race Tables I-III: the racial ability
    // adjustments, the Table III minimums and maximums
    // (male and female columns), infravision, the
    // sleep-and-charm resistance, the CON magic-save bonus
    // (dwarf, gnome, halfling - the R147 shape) with the
    // poison finding (the print gives the gnome MAGIC
    // ONLY; dwarf and halfling ride poison too - the gap
    // box claimed gnome poison, the print wins), Race
    // Table I class limitations, the footnoted Race Table
    // II level caps, the goblin-kind and giant-kind
    // to-hit lists and the detection lists. The creation
    // RACE stage itself lives in appstate/adnd1 (the game
    // layer is outside the battery build; its syntax gate
    // compiles appstate.h via game/*.cpp).
    {
        int bad = 0;
        namespace RS = rules;
        // the Penalties and Bonuses list, all races x abilities
        static const int kAdj[7][6] = {
            {  0,  0,  0,  0,  0,  0 },   // human
            {  0,  0,  0,  0,  1, -1 },   // dwarf
            {  0,  0,  0,  1, -1,  0 },   // elf
            {  0,  0,  0,  0,  0,  0 },   // gnome
            {  0,  0,  0,  0,  0,  0 },   // half-elf
            { -1,  0,  0,  1,  0,  0 },   // halfling
            {  1,  0,  0,  0,  1, -2 },   // half-orc
        };
        for (int r = 0; r < 7; ++r)
            for (int a = 0; a < 6; ++a)
                if (RS::raceAbilityAdj((RS::CharRace)r,
                        (RS::Ability)a) != kAdj[r][a])
                    ++bad;
        // Table III minimums (identical M/F in print)
        static const int kMin[7][6] = {
            {  3,  3,  3,  3,  3,  3 },   // human
            {  8,  3,  3,  3, 12,  3 },   // dwarf
            {  3,  8,  3,  7,  6,  8 },   // elf
            {  6,  7,  3,  3,  8,  3 },   // gnome
            {  3,  4,  3,  6,  6,  3 },   // half-elf
            {  6,  6,  3,  8, 10,  3 },   // halfling
            {  6,  3,  3,  3, 13,  3 },   // half-orc
        };
        // Table III maximums, male then female columns
        static const int kMaxM[7][6] = {
            { 18, 18, 18, 18, 18, 18 },   // human
            { 18, 18, 18, 17, 19, 16 },   // dwarf
            { 18, 18, 18, 19, 18, 18 },   // elf
            { 18, 18, 18, 18, 18, 18 },   // gnome
            { 18, 18, 18, 18, 18, 18 },   // half-elf
            { 17, 18, 17, 18, 19, 18 },   // halfling
            { 18, 17, 14, 17, 19, 12 },   // half-orc
        };
        static const int kMaxF[7][6] = {
            { 18, 18, 18, 18, 18, 18 },   // human
            { 17, 18, 18, 17, 19, 16 },   // dwarf
            { 16, 18, 18, 19, 18, 18 },   // elf
            { 15, 18, 18, 18, 18, 18 },   // gnome
            { 17, 18, 18, 18, 18, 18 },   // half-elf
            { 14, 18, 17, 18, 19, 18 },   // halfling
            { 18, 17, 14, 17, 19, 12 },   // half-orc
        };
        for (int r = 0; r < 7; ++r)
            for (int a = 0; a < 6; ++a) {
                if (RS::raceAbilityMin((RS::CharRace)r,
                        (RS::Ability)a, false) != kMin[r][a])
                    ++bad;
                if (RS::raceAbilityMin((RS::CharRace)r,
                        (RS::Ability)a, true) != kMin[r][a])
                    ++bad;
                if (RS::raceAbilityMax((RS::CharRace)r,
                        (RS::Ability)a, false) != kMaxM[r][a])
                    ++bad;
                if (RS::raceAbilityMax((RS::CharRace)r,
                        (RS::Ability)a, true) != kMaxF[r][a])
                    ++bad;
            }
        // infravision and sleep-and-charm resistance
        static const int kInfra[7] = { 0, 60, 60, 60, 60, 30, 60 };
        static const int kSleep[7] = { 0,  0, 90,  0, 30,  0,  0 };
        for (int r = 0; r < 7; ++r) {
            if (RS::raceInfravisionFeet((RS::CharRace)r)
                != kInfra[r]) ++bad;
            if (RS::raceSleepCharmResistPct((RS::CharRace)r)
                != kSleep[r]) ++bad;
        }
        // the CON magic-save bands, every score 3-18, per
        // race - plus the poison finding (gnome: magic only)
        for (int c = 3; c <= 18; ++c) {
            int shape = (c * 2) / 7;
            if (shape > 5) shape = 5;
            for (int r = 0; r < 7; ++r) {
                bool magicRace =
                    r == RS::RACE_DWARF || r == RS::RACE_GNOME
                    || r == RS::RACE_HALFLING;
                bool poisonRace =
                    r == RS::RACE_DWARF || r == RS::RACE_HALFLING;
                if (RS::raceMagicSaveBonus((RS::CharRace)r,
                        (uint8_t)c) != (magicRace ? shape : 0))
                    ++bad;
                if (RS::racePoisonSaveBonus((RS::CharRace)r,
                        (uint8_t)c) != (poisonRace ? shape : 0))
                    ++bad;
            }
        }
        // Race Table I: class limitations, the base four
        static const bool kAllow[4][7] = {
            { true, true, true, true, true, true, true },   // F
            { true, false, true, false, true, false, false },   // MU
            { true, false, false, false, true, false, true },   // C
            { true, true, true, true, true, true, true },   // T
        };
        for (int ci = 0; ci < 4; ++ci)
            for (int r = 0; r < 7; ++r)
                if (RS::classAllowedForRace(ci,
                        (RS::CharRace)r) != kAllow[ci][r])
                    ++bad;
        // Race Table II level caps, with the footnotes
        static const struct {
            int ci; int r; int s; int dex; int cap;
        } kCap[] = {
            // fighter, footnote STR ladders
            { 0, 1, 16, 0,  7 }, { 0, 1, 17, 0,  8 },
            { 0, 1, 18, 0,  9 },
            { 0, 2, 16, 0,  5 }, { 0, 2, 17, 0,  6 },
            { 0, 2, 18, 0,  7 },
            { 0, 3, 17, 0,  5 }, { 0, 3, 18, 0,  6 },
            { 0, 4, 16, 0,  6 }, { 0, 4, 17, 0,  7 },
            { 0, 4, 18, 0,  8 },
            { 0, 5, 16, 0,  4 }, { 0, 5, 17, 0,  5 },
            { 0, 5, 18, 0,  6 },
            { 0, 6,  0, 0, 10 },
            // magic-user, footnote INT ladders
            { 1, 2, 16, 0,  9 }, { 1, 2, 17, 0, 10 },
            { 1, 2, 18, 0, 11 },
            { 1, 4, 16, 0,  6 }, { 1, 4, 17, 0,  7 },
            { 1, 4, 18, 0,  8 },
            // cleric caps (half-elf, half-orc)
            { 2, 4,  0, 0,  5 },
            { 2, 6,  0, 0,  4 },
            // thief, the half-orc footnote DEX ladder
            { 3, 6,  0, 16, 6 }, { 3, 6,  0, 17, 7 },
            { 3, 6,  0, 18, 8 },
            // unlimited: human everywhere, dwarf thief
            { 0, 0,  0, 0, -1 }, { 1, 0,  0, 0, -1 },
            { 2, 0,  0, 0, -1 }, { 3, 0,  0, 0, -1 },
            { 3, 1,  0, 0, -1 },
            // not allowed: MU dwarf, cleric dwarf/elf/gnome
            { 1, 1, 18, 0,  0 }, { 2, 1,  0, 0,  0 },
            { 2, 2,  0, 0,  0 }, { 2, 3,  0, 0,  0 },
        };
        for (size_t i = 0; i < sizeof(kCap)/sizeof(kCap[0]); ++i)
            if (RS::raceLevelCap(kCap[i].ci,
                    (RS::CharRace)kCap[i].r,
                    (uint8_t)kCap[i].s,
                    (uint8_t)kCap[i].s,
                    (uint8_t)kCap[i].dex) != kCap[i].cap)
                ++bad;
        // the goblin-kind and giant-kind to-hit lists
        static const struct {
            int r; const char* foe; int bonus; int pen;
        } kFoe[] = {
            { 1, "half-orc",   1, 0 }, { 1, "goblin", 1, 0 },
            { 1, "hobgoblin",  1, 0 }, { 1, "orc",    1, 0 },
            { 1, "gnoll",      0, 0 }, { 1, "kobold", 0, 0 },
            { 1, "ogre",       0, 4 }, { 1, "troll",  0, 4 },
            { 1, "ogre mage",  0, 4 }, { 1, "giant",  0, 4 },
            { 1, "titan",      0, 4 },
            { 1, "gnoll",      0, 0 },   // dwarf: no gnoll pen
            { 1, "bugbear",    0, 0 },
            { 3, "kobold",     1, 0 }, { 3, "goblin", 1, 0 },
            { 3, "orc",        0, 0 },
            { 3, "gnoll",      0, 4 }, { 3, "bugbear", 0, 4 },
            { 3, "ogre",       0, 4 }, { 3, "troll",   0, 4 },
            { 3, "ogre mage",  0, 4 }, { 3, "giant",  0, 4 },
            { 3, "titan",      0, 4 },
            { 0, "goblin",     0, 0 }, { 2, "ogre",   0, 0 },
            { 4, "goblin",     0, 0 },
        };
        for (size_t i = 0; i < sizeof(kFoe)/sizeof(kFoe[0]); ++i)
            if (RS::raceBonusVsFoeName((RS::CharRace)kFoe[i].r,
                    kFoe[i].foe) != kFoe[i].bonus
                || RS::raceFoeAttackPenalty(
                    (RS::CharRace)kFoe[i].r,
                    kFoe[i].foe) != kFoe[i].pen)
                ++bad;
        // the detection lists, in-N pairs + spot percents
        static const struct {
            int r; RS::DetectKind k; int num; int den;
        } kDet[] = {
            { 1, RS::DET_GRADE,           3,  4 },
            { 1, RS::DET_NEW_CONSTRUCTION, 3,  4 },
            { 1, RS::DET_SLIDING_WALLS,   4,  6 },
            { 1, RS::DET_STONE_TRAPS,      2,  4 },
            { 1, RS::DET_DEPTH,            1,  2 },
            { 3, RS::DET_GRADE,            8, 10 },
            { 3, RS::DET_UNSAFE_SURFACES,  7, 10 },
            { 3, RS::DET_DEPTH,            6, 10 },
            { 3, RS::DET_DIRECTION,        1,  2 },
            { 5, RS::DET_GRADE,            3,  4 },
            { 5, RS::DET_DIRECTION,        1,  2 },
            { 2, RS::DET_SECRET_PASS,      1,  6 },
            { 2, RS::DET_SECRET_SEARCH,     2,  6 },
            { 2, RS::DET_CONCEALED_SEARCH,  3,  6 },
            { 4, RS::DET_SECRET_PASS,      1,  6 },
            { 4, RS::DET_SECRET_SEARCH,     2,  6 },
            { 4, RS::DET_CONCEALED_SEARCH,  3,  6 },
        };
        for (size_t i = 0; i < sizeof(kDet)/sizeof(kDet[0]); ++i) {
            RS::ChanceIn c = RS::raceDetectChance(
                (RS::CharRace)kDet[i].r, kDet[i].k);
            if (c.num != kDet[i].num || c.den != kDet[i].den)
                ++bad;
        }
        // a race with no entry reads 0-in-0 (and pct 0)
        for (int r = 0; r < 7; ++r) {
            RS::ChanceIn c = RS::raceDetectChance(
                (RS::CharRace)r, RS::DET_SLIDING_WALLS);
            bool dwarf = (r == RS::RACE_DWARF);
            if (dwarf != (c.num == 4 && c.den == 6)) ++bad;
            if (RS::raceDetectPct((RS::CharRace)r,
                    RS::DET_SLIDING_WALLS) != (dwarf ? 66 : 0))
                ++bad;
        }
        if (RS::raceDetectPct(RS::RACE_DWARF,
                RS::DET_GRADE) != 75
            || RS::raceDetectPct(RS::RACE_ELF,
                RS::DET_SECRET_PASS) != 16) ++bad;
        // applyRacialAdjustments + eligibility spot checks
        RS::AbilityScores s;
        s.str = 18; s.con = 18; s.cha = 18;
        RS::applyRacialAdjustments(s, RS::RACE_DWARF, false);
        if (s.str != 18 || s.con != 19 || s.cha != 16) ++bad;
        s.str = 18; s.dex = 18; s.con = 18;
        RS::applyRacialAdjustments(s, RS::RACE_ELF, false);
        if (s.str != 18 || s.dex != 19 || s.con != 17) ++bad;
        s.str = 18; s.dex = 18;
        RS::applyRacialAdjustments(s, RS::RACE_ELF, true);
        if (s.str != 16) ++bad;   // female STR max 16
        s.str = 18; s.dex = 18; s.con = 18;
        RS::applyRacialAdjustments(s, RS::RACE_HALFLING, false);
        if (s.str != 17 || s.dex != 18) ++bad;
        s.str = 18; s.con = 18; s.cha = 18;
        RS::applyRacialAdjustments(s, RS::RACE_HALF_ORC, false);
        // STR 18+1 clamps to the 18 max, CON reaches 19,
        // CHA 18-2 = 16 clamps to the 12 max (Table III)
        if (s.str != 18 || s.con != 19 || s.cha != 12) ++bad;
        RS::AbilityScores e;
        e.con = 11;
        if (!RS::raceMeetsMinimums(e, RS::RACE_DWARF, false)) ++bad;
        e.con = 10;
        if (RS::raceMeetsMinimums(e, RS::RACE_DWARF, false)) ++bad;
        e.con = 18; e.str = 7;
        if (!RS::raceMeetsMinimums(e, RS::RACE_HALFLING, false))
            ++bad;
        e.str = 6;
        if (RS::raceMeetsMinimums(e, RS::RACE_HALFLING, false)) ++bad;
        printf("R154 PC races audit: bad %d\n", bad);
        if (bad) return 1;
    }
