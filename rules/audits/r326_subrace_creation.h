    // ---- R326: the creation round audit ----
    // The sub-race picker rows (the
    // CR_SUBRACE stage), the makeMember
    // wiring (the uaSubrace and female
    // fields), and the dark-elf sex
    // split live at the fold (the
    // female columns of Race Table II
    // read through uaLevelCap). The
    // save line and the load tag are
    // splice-assert verified only (the
    // battery never writes adnd1.sav).
    {
        using namespace rules;
        int bad = 0;
        // U1: the picker rows (SUB_NONE
        // first; SUB_HUMAN stays a
        // matrix id)
        {
            CreationState cr;
            cr.racePick = 0;
            if (cr.subraceOptionCount() != 1)
                ++bad;
            if (cr.subraceOption(0) != SUB_NONE)
                ++bad;
            cr.racePick = 1;
            if (cr.subraceOptionCount() != 4)
                ++bad;
            if (cr.subraceOption(1)
                != SUB_DWARF_GRAY) ++bad;
            if (cr.subraceOption(2)
                != SUB_DWARF_HILL) ++bad;
            if (cr.subraceOption(3)
                != SUB_DWARF_MOUNTAIN) ++bad;
            cr.racePick = 2;
            if (cr.subraceOptionCount() != 7)
                ++bad;
            if (cr.subraceOption(1)
                != SUB_ELF_DARK) ++bad;
            if (cr.subraceOption(6)
                != SUB_ELF_WOOD) ++bad;
            cr.racePick = 3;
            if (cr.subraceOptionCount() != 3)
                ++bad;
            cr.racePick = 4;
            if (cr.subraceOptionCount() != 2)
                ++bad;
            cr.racePick = 5;
            if (cr.subraceOptionCount() != 4)
                ++bad;
            cr.racePick = 6;
            if (cr.subraceOptionCount() != 2)
                ++bad;
            // off-menu rows read none
            if (cr.subraceOption(-1)
                != SUB_NONE) ++bad;
            if (cr.subraceOption(9)
                != SUB_NONE) ++bad;
        }
        // U2: the makeMember wiring
        {
            CreationState cr;
            cr.rollFresh();
            cr.racePick = 2;
            cr.female = true;
            cr.subracePick = (int)SUB_ELF_DARK;
            Character c = cr.makeMember(1);
            if (c.race != 2) ++bad;
            if (c.uaSubrace != (int)SUB_ELF_DARK)
                ++bad;
            if (!c.female) ++bad;
            // the default path: a fresh
            // state carries none and male
            CreationState d;
            d.rollFresh();
            Character e = d.makeMember(0);
            if (e.uaSubrace != 0) ++bad;
            if (e.female) ++bad;
        }
        // U3: the dark-elf sex split at
        // the fold (engine caps F 9,
        // MU 11, C 9)
        {
            AbilityScores a;
            ExceptionalStrength ex;
            a.str = 14; a.int_ = 17;
            a.wis = 15; a.dex = 14;
            // drow MU INT 17: male 12+2
            // -> 11; female 5+2 -> 7
            if (uaLevelCap(11, SUB_ELF_DARK,
                UACLASS_MAGIC_USER, a, ex, 0, 0)
                != 11) ++bad;
            if (uaLevelCap(11, SUB_ELF_DARK,
                UACLASS_MAGIC_USER, a, ex, 0, 1)
                != 7) ++bad;
            // drow cleric WIS 17: male 7
            // (no +2 - no elven cleric
            // combo); female U -> 9
            if (uaLevelCap(9, SUB_ELF_DARK,
                UACLASS_CLERIC, a, ex, 0, 0)
                != 7) ++bad;
            if (uaLevelCap(9, SUB_ELF_DARK,
                UACLASS_CLERIC, a, ex, 0, 1)
                != 9) ++bad;
            // the female fighter columns
            // sit above the engine cap -
            // both 9
            if (uaLevelCap(9, SUB_ELF_DARK,
                UACLASS_FIGHTER, a, ex, 0, 0)
                != 9) ++bad;
            if (uaLevelCap(9, SUB_ELF_DARK,
                UACLASS_FIGHTER, a, ex, 0, 1)
                != 9) ++bad;
            // invariance: the female flag
            // moves no non-dark column
            if (uaLevelCap(9, SUB_DWARF_HILL,
                UACLASS_FIGHTER, a, ex, 0, 0)
                != uaLevelCap(9, SUB_DWARF_HILL,
                UACLASS_FIGHTER, a, ex, 0, 1))
                ++bad;
            // the split holds on the
            // multi path (no +2): female
            // 5, male 12+2 -> 11
            if (uaLevelCap(11, SUB_ELF_DARK,
                UACLASS_MAGIC_USER, a, ex, 9, 1)
                != 5) ++bad;
            if (uaLevelCap(11, SUB_ELF_DARK,
                UACLASS_MAGIC_USER, a, ex, 9, 0)
                != 11) ++bad;
        }
        // U4: the live fold - the female
        // drow MU stops at 7, the male at
        // 11; the female flag moves no
        // non-dark walk (hairfoot cleric
        // pins 4 both)
        {
            // A: the female drow MU
            {
                AppState st;
                st.party.formed = true;
                Character c;
                c.name = "Liriel";
                c.race = 2;
                c.uaSubrace = SUB_ELF_DARK;
                c.female = true;
                c.classIndex = 1;
                c.abilities.int_ = 17;
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
                    != 7) ++bad;
            }
            // B: the male drow MU (the
            // R325 male read through the
            // flag)
            {
                AppState st;
                st.party.formed = true;
                Character c;
                c.name = "Jarlaxle";
                c.race = 2;
                c.uaSubrace = SUB_ELF_DARK;
                c.female = false;
                c.classIndex = 1;
                c.abilities.int_ = 17;
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
                    != 11) ++bad;
            }
            // C: the female hairfoot
            // cleric - the flag must not
            // move the walk
            {
                AppState st;
                st.party.formed = true;
                Character c;
                c.name = "Pippa";
                c.race = 5;
                c.uaSubrace =
                    SUB_HALFLING_HAIRFOOT;
                c.female = true;
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
        printf("R326 subrace creation audit: bad %d\n", bad);
        if (bad) return 1;
    }
