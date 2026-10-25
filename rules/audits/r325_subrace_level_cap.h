    // ---- R325: the Race Table II fold audit ----
    // The caller seam (rules/subracecap.h):
    // the vital-ability read, the column
    // key build, the +2 eligibility, the
    // derived cap - and the live level-up
    // fold (the gainXp queue and the
    // trainer reading the Race Table II
    // cap through the uaSubrace field).
    // Pinned against the p.8 print.
    {
        using namespace rules;
        int bad = 0;
        // U1: the vital-ability read (the
        // p.8 left-hand column rule)
        {
            if (uaColumnAbility(
                UACLASS_FIGHTER)
                != ABILITY_STR) ++bad;
            if (uaColumnAbility(
                UACLASS_RANGER)
                != ABILITY_STR) ++bad;
            if (uaColumnAbility(
                UACLASS_ASSASSIN)
                != ABILITY_STR) ++bad;
            if (uaColumnAbility(
                UACLASS_CLERIC)
                != ABILITY_WIS) ++bad;
            if (uaColumnAbility(
                UACLASS_DRUID)
                != ABILITY_WIS) ++bad;
            if (uaColumnAbility(
                UACLASS_MAGIC_USER)
                != ABILITY_INT) ++bad;
            if (uaColumnAbility(
                UACLASS_ILLUSIONIST)
                != ABILITY_INT) ++bad;
            if (uaColumnAbility(
                UACLASS_THIEF)
                != ABILITY_DEX) ++bad;
        }
        // U2: the column key build (the
        // strength encoder rides the
        // exceptional roll)
        {
            AbilityScores a;
            ExceptionalStrength ex;
            a.str = 17;
            if (uaColumnKey(
                UACLASS_FIGHTER, a, ex)
                != 17000) ++bad;
            a.str = 18;
            if (uaColumnKey(
                UACLASS_FIGHTER, a, ex)
                != 18000) ++bad;
            ex.has = true; ex.pct = 51;
            if (uaColumnKey(
                UACLASS_FIGHTER, a, ex)
                != 18510) ++bad;
            ex.pct = 100;
            if (uaColumnKey(
                UACLASS_FIGHTER, a, ex)
                != 18999) ++bad;
            ex.has = false;
            a.wis = 15;
            if (uaColumnKey(
                UACLASS_CLERIC, a, ex)
                != 15000) ++bad;
            a.int_ = 21;
            if (uaColumnKey(
                UACLASS_MAGIC_USER, a, ex)
                != 21000) ++bad;
            a.dex = 9;
            if (uaColumnKey(
                UACLASS_THIEF, a, ex)
                != 9000) ++bad;
        }
        // U3: the +2 eligibility (the
        // Important paragraph): the
        // dwarven assassin reads the
        // plain limits - no assassin
        // combo exists for the race
        {
            if (!uaBonusEligible(
                SUB_DWARF_HILL,
                UACLASS_FIGHTER)) ++bad;
            if (uaBonusEligible(
                SUB_DWARF_HILL,
                UACLASS_ASSASSIN)) ++bad;
            if (!uaBonusEligible(
                SUB_HALFELF,
                UACLASS_RANGER)) ++bad;
            if (uaBonusEligible(
                SUB_HALFLING_HAIRFOOT,
                UACLASS_DRUID)) ++bad;
            if (!uaBonusEligible(
                SUB_GNOME_DEEP,
                UACLASS_ILLUSIONIST)) ++bad;
            if (uaBonusEligible(
                SUB_HUMAN,
                UACLASS_FIGHTER)) ++bad;
            if (uaBonusEligible(
                SUB_ELF_DARK,
                UACLASS_CLERIC)) ++bad;
        }
        // U4: the derived cap - the p.8
        // examples and the edge reads
        {
            AbilityScores a;
            ExceptionalStrength ex;
            // the hill dwarf 18-strength
            // fighter: 8 multi, 10 single,
            // the engine name-level cap (9)
            // still binds above
            a.str = 18;
            if (uaLevelCap(9, SUB_DWARF_HILL,
                UACLASS_FIGHTER, a, ex, 0)
                != 9) ++bad;
            // the 14-strength hill dwarf
            // fighter: 6 multi, 8 single
            a.str = 14;
            if (uaLevelCap(9, SUB_DWARF_HILL,
                UACLASS_FIGHTER, a, ex, 0)
                != 8) ++bad;
            if (uaLevelCap(9, SUB_DWARF_HILL,
                UACLASS_FIGHTER, a, ex, 9)
                != 6) ++bad;
            // the dwarven assassin: the
            // plain 9, no +2 (the print)
            a.str = 18;
            if (uaLevelCap(10, SUB_DWARF_HILL,
                UACLASS_ASSASSIN, a, ex, 0)
                != 9) ++bad;
            // humans and unset members
            // read the engine cap
            a.str = 14;
            if (uaLevelCap(9, SUB_HUMAN,
                UACLASS_FIGHTER, a, ex, 0)
                != 9) ++bad;
            if (uaLevelCap(9, SUB_NONE,
                UACLASS_FIGHTER, a, ex, 0)
                != 9) ++bad;
            // the hairfoot cleric: WIS 15
            // pins 4, no halfling cleric
            // combo - no +2
            a.wis = 15;
            if (uaLevelCap(9,
                SUB_HALFLING_HAIRFOOT,
                UACLASS_CLERIC, a, ex, 0)
                != 4) ++bad;
            // the half-elf ranger: 8 at
            // STR 18 (+2 = 10), 11 at 18/00
            // (+2 = 13)
            a.wis = 10; a.str = 18;
            if (uaLevelCap(15, SUB_HALFELF,
                UACLASS_RANGER, a, ex, 0)
                != 10) ++bad;
            ex.has = true; ex.pct = 100;
            if (uaLevelCap(15, SUB_HALFELF,
                UACLASS_RANGER, a, ex, 0)
                != 13) ++bad;
            ex.has = false;
            // the drow magic-user (male
            // columns): INT 17 pins 12, +2
            // = 14 - the engine cap (11)
            // binds above; the female
            // cleric split reads U at the
            // R324 layer
            a.str = 10; a.int_ = 17;
            if (uaLevelCap(11, SUB_ELF_DARK,
                UACLASS_MAGIC_USER, a, ex, 0)
                != 11) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_DARK, UACLASS_CLERIC,
                17000, 1) != 0) ++bad;
            // the wood-elf thief reads U -
            // the engine cap stands
            a.int_ = 10; a.dex = 18;
            if (uaLevelCap(10, SUB_ELF_WOOD,
                UACLASS_THIEF, a, ex, 0)
                != 10) ++bad;
            // the surface gnome
            // illusionist: INT 18 pins 7,
            // +2 = 9
            a.dex = 10; a.int_ = 18;
            if (uaLevelCap(11,
                SUB_GNOME_SURFACE,
                UACLASS_ILLUSIONIST, a, ex, 0)
                != 9) ++bad;
            // a class with no column
            // (the elven cavalier) reads
            // the engine cap
            if (uaLevelCap(9, SUB_ELF_WOOD,
                UACLASS_CAVALIER, a, ex, 0)
                != 9) ++bad;
        }
        // U5: the member class mapping
        // (the R230 runtime-base read)
        {
            if (uaClassOfMember(0, 1)
                != UACLASS_RANGER) ++bad;
            if (uaClassOfMember(2, 2)
                != UACLASS_DRUID) ++bad;
            if (uaClassOfMember(3, -1)
                != UACLASS_THIEF) ++bad;
            if (uaClassOfMember(0, -1)
                != UACLASS_FIGHTER) ++bad;
        }
        // U6: the live level-up fold -
        // the gainXp queue and the
        // trainer both stop at the
        // Race Table II cap (a million
        // xp per award, thirty walks -
        // the cap is the only stop)
        {
            // A: the 14-strength hill dwarf
            // fighter, single-classed: 6 +
            // 2 = 8
            {
                AppState st;
                st.party.formed = true;
                Character c;
                c.name = "Bram";
                c.race = 1;
                c.uaSubrace = SUB_DWARF_HILL;
                c.classIndex = 0;
                c.abilities.str = 14;
                c.level = 1;
                c.hp = 30; c.maxHp = 30;
                st.party.members.push_back(c);
                st.rng.seed(7);
                for (int i = 0; i < 30; ++i) {
                    st.party.gainXp(1000000,
                        st.dice, st.log);
                    st.party.trainNext(
                        st.dice, st.log);
                }
                if (st.party.members[0].level
                    != 8) ++bad;
            }
            // B: the same member multi-
            // classed (fighter/thief): the
            // plain 6, no +2
            {
                AppState st;
                st.party.formed = true;
                Character c;
                c.name = "Bram";
                c.race = 1;
                c.uaSubrace = SUB_DWARF_HILL;
                c.classIndex = 0;
                c.multiMask = 9;
                c.abilities.str = 14;
                c.level = 1;
                c.hp = 30; c.maxHp = 30;
                st.party.members.push_back(c);
                st.rng.seed(7);
                for (int i = 0; i < 30; ++i) {
                    st.party.gainXp(1000000,
                        st.dice, st.log);
                    st.party.trainNext(
                        st.dice, st.log);
                }
                if (st.party.members[0].level
                    != 6) ++bad;
            }
            // C: the human fighter - no
            // sub-race, the engine
            // name-level cap stands
            {
                AppState st;
                st.party.formed = true;
                Character c;
                c.name = "Aldo";
                c.race = 0;
                c.classIndex = 0;
                c.abilities.str = 14;
                c.level = 1;
                c.hp = 30; c.maxHp = 30;
                st.party.members.push_back(c);
                st.rng.seed(7);
                for (int i = 0; i < 30; ++i) {
                    st.party.gainXp(1000000,
                        st.dice, st.log);
                    st.party.trainNext(
                        st.dice, st.log);
                }
                if (st.party.members[0].level
                    != 9) ++bad;
            }
            // D: the hairfoot halfling
            // cleric - WIS 15 pins 4
            {
                AppState st;
                st.party.formed = true;
                Character c;
                c.name = "Pip";
                c.race = 5;
                c.uaSubrace =
                    SUB_HALFLING_HAIRFOOT;
                c.classIndex = 2;
                c.abilities.wis = 15;
                c.level = 1;
                c.hp = 30; c.maxHp = 30;
                st.party.members.push_back(c);
                st.rng.seed(7);
                for (int i = 0; i < 30; ++i) {
                    st.party.gainXp(1000000,
                        st.dice, st.log);
                    st.party.trainNext(
                        st.dice, st.log);
                }
                if (st.party.members[0].level
                    != 4) ++bad;
            }
        }
        printf("R325 subrace level cap audit: bad %d\n", bad);
        if (bad) return 1;
    }
