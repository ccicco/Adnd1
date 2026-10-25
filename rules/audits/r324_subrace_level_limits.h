    // ---- R324: the Race Table II audit ----
    // The UA level-limit sub-tables
    // (rules/subracelevels.h): the six
    // sub-tables, 47 columns, the
    // footnoted ability gates, the
    // escalation riders, the +2
    // single-class rule. Pinned data
    // only - the leveling wiring is
    // a caller round. Draw-
    // independent.
    {
        using namespace rules;
        int bad = 0;
        // U1: the floor rule, the nulls
        // and the key encoder
        {
            if (subraceLevelLimit(
                SUB_DWARF_HILL,
                UACLASS_ASSASSIN, 14000, 0)
                != 9) ++bad;
            if (subraceLevelLimit(
                SUB_DWARF_HILL,
                UACLASS_ASSASSIN, 8000, 0)
                != 9) ++bad;
            if (subraceStrengthLevelKey(
                15, -1) != 15000) ++bad;
            if (subraceStrengthLevelKey(
                18, -1) != 18000) ++bad;
            if (subraceStrengthLevelKey(
                18, 37) != 18370) ++bad;
            if (subraceStrengthLevelKey(
                18, 99) != 18990) ++bad;
            if (subraceStrengthLevelKey(
                18, 100) != 18999) ++bad;
            if (subraceStrengthLevelKey(
                19, -1) != 19000) ++bad;
            // 18/37 between rows: the
            // lower row (18) reads 9
            if (subraceLevelLimit(
                SUB_DWARF_HILL,
                UACLASS_ASSASSIN, 18370, 0)
                != 9) ++bad;
            if (subraceLevelLimit(
                SUB_DWARF_HILL,
                UACLASS_MAGIC_USER,
                18000, 0) != -1) ++bad;
            if (subraceLevelLimit(
                SUB_HUMAN, UACLASS_FIGHTER,
                18000, 0) != -1) ++bad;
            if (subraceLevelLimit(
                SUB_NONE, UACLASS_CLERIC,
                18000, 0) != -1) ++bad;
            // the unlimited-by-omission
            // classes ride the null
            if (subraceLevelLimit(
                SUB_ELF_WOOD,
                UACLASS_CAVALIER,
                18000, 0) != -1) ++bad;
        }
        // U2: Table II.A (dwarves)
        {
            if (subraceLevelLimit(
                SUB_DWARF_HILL,
                UACLASS_FIGHTER, 15000, 0)
                != 6) ++bad;
            if (subraceLevelLimit(
                SUB_DWARF_HILL,
                UACLASS_FIGHTER, 18000, 0)
                != 8) ++bad;
            if (subraceLevelLimit(
                SUB_DWARF_HILL,
                UACLASS_FIGHTER, 18990, 0)
                != 8) ++bad;
            if (subraceLevelLimit(
                SUB_DWARF_HILL,
                UACLASS_FIGHTER, 18999, 0)
                != 9) ++bad;
            if (subraceLevelLimit(
                SUB_DWARF_HILL,
                UACLASS_FIGHTER, 21000, 0)
                != 15) ++bad;
            if (subraceLevelLimit(
                SUB_DWARF_GRAY,
                UACLASS_FIGHTER, 18000, 0)
                != 9) ++bad;
            if (subraceLevelLimit(
                SUB_DWARF_GRAY,
                UACLASS_FIGHTER, 21000, 0)
                != 16) ++bad;
            if (subraceLevelLimit(
                SUB_DWARF_HILL,
                UACLASS_CLERIC, 15000, 0)
                != 8) ++bad;
            if (subraceLevelLimit(
                SUB_DWARF_GRAY,
                UACLASS_CLERIC, 21000, 0)
                != 16) ++bad;
            if (subraceLevelLimit(
                SUB_DWARF_HILL,
                UACLASS_THIEF, 15000, 0)
                != 0) ++bad;
            if (subraceLevelLimit(
                SUB_DWARF_MOUNTAIN,
                UACLASS_THIEF, 21000, 0)
                != 0) ++bad;
            if (subraceLevelLimit(
                SUB_DWARF_HILL,
                UACLASS_ASSASSIN,
                18990, 0) != 11) ++bad;
            if (subraceLevelFootnote(
                SUB_DWARF_HILL,
                UACLASS_ASSASSIN,
                18990, 0) != 1) ++bad;
            if (subraceLevelLimit(
                SUB_DWARF_HILL,
                UACLASS_ASSASSIN,
                18999, 0) != 12) ++bad;
            if (subraceLevelFootnote(
                SUB_DWARF_MOUNTAIN,
                UACLASS_ASSASSIN,
                18999, 0) != 2) ++bad;
            if (subraceLevelFootnote(
                SUB_DWARF_GRAY,
                UACLASS_ASSASSIN,
                21000, 0) != 2) ++bad;
        }
        // U3: Table II.B (gnomes)
        {
            if (subraceLevelLimit(
                SUB_GNOME_DEEP,
                UACLASS_FIGHTER, 18000, 0)
                != 5) ++bad;
            if (subraceLevelLimit(
                SUB_GNOME_SURFACE,
                UACLASS_FIGHTER, 18500, 0)
                != 6) ++bad;
            if (subraceLevelLimit(
                SUB_GNOME_DEEP,
                UACLASS_FIGHTER, 18750, 0)
                != 7) ++bad;
            if (subraceLevelLimit(
                SUB_GNOME_SURFACE,
                UACLASS_FIGHTER, 18990, 0)
                != 8) ++bad;
            if (subraceLevelLimit(
                SUB_GNOME_DEEP,
                UACLASS_FIGHTER, 21000, 0)
                != 9) ++bad;
            if (subraceLevelLimit(
                SUB_GNOME_DEEP,
                UACLASS_ILLUSIONIST,
                18000, 0) != 7) ++bad;
            if (subraceLevelLimit(
                SUB_GNOME_SURFACE,
                UACLASS_ILLUSIONIST,
                21000, 0) != 13) ++bad;
            if (subraceLevelLimit(
                SUB_GNOME_DEEP,
                UACLASS_ASSASSIN,
                18500, 0) != 9) ++bad;
            if (subraceLevelFootnote(
                SUB_GNOME_DEEP,
                UACLASS_ASSASSIN,
                18500, 0) != 1) ++bad;
            if (subraceLevelLimit(
                SUB_GNOME_SURFACE,
                UACLASS_ASSASSIN,
                21000, 0) != 10) ++bad;
            if (subraceLevelLimit(
                SUB_GNOME_DEEP,
                UACLASS_CLERIC, 20000, 0)
                != 14) ++bad;
            if (subraceLevelLimit(
                SUB_GNOME_DEEP,
                UACLASS_THIEF, 17000, 0)
                != 0) ++bad;
        }
        // U4: Table II.C (elves), the
        // two printed blocks
        {
            if (subraceLevelLimit(
                SUB_ELF_DARK,
                UACLASS_CLERIC, 12000, 0)
                != 4) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_DARK,
                UACLASS_CLERIC, 18000, 0)
                != 7) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_DARK,
                UACLASS_CLERIC, 12000, 1)
                != 0) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_WOOD,
                UACLASS_CLERIC, 18000, 0)
                != 10) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_HIGH,
                UACLASS_CLERIC, 21000, 0)
                != 12) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_WILD,
                UACLASS_DRUID, 18000, 0)
                != 11) ++bad;
            if (subraceLevelFootnote(
                SUB_ELF_WILD,
                UACLASS_DRUID, 18000, 0)
                != 1) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_WILD,
                UACLASS_DRUID, 21000, 0)
                != 17) ++bad;
            if (subraceLevelFootnote(
                SUB_ELF_WILD,
                UACLASS_DRUID, 21000, 0)
                != 2) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_WOOD,
                UACLASS_DRUID, 15000, 0)
                != 0) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_DARK,
                UACLASS_FIGHTER, 12000, 0)
                != 7) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_DARK,
                UACLASS_FIGHTER, 18000, 0)
                != 10) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_DARK,
                UACLASS_FIGHTER, 14000, 1)
                != 11) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_GRAY,
                UACLASS_FIGHTER, 18000, 0)
                != 6) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_HIGH,
                UACLASS_FIGHTER, 18990, 0)
                != 9) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_GRAY,
                UACLASS_FIGHTER, 20000, 0)
                != 11) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_VALLEY,
                UACLASS_FIGHTER, 18999, 0)
                != 10) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_VALLEY,
                UACLASS_FIGHTER, 20000, 0)
                != 13) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_WILD,
                UACLASS_FIGHTER, 18900, 0)
                != 10) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_WILD,
                UACLASS_FIGHTER, 20000, 0)
                != 13) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_WOOD,
                UACLASS_FIGHTER, 18900, 0)
                != 9) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_WOOD,
                UACLASS_FIGHTER, 20000, 0)
                != 14) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_DARK,
                UACLASS_MAGIC_USER,
                17000, 0) != 12) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_DARK,
                UACLASS_MAGIC_USER,
                17000, 1) != 5) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_DARK,
                UACLASS_MAGIC_USER,
                22000, 0) != 18) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_GRAY,
                UACLASS_MAGIC_USER,
                22000, 0) != 18) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_HIGH,
                UACLASS_MAGIC_USER,
                22000, 0) != 17) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_VALLEY,
                UACLASS_MAGIC_USER,
                22000, 0) != 15) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_WOOD,
                UACLASS_MAGIC_USER,
                22000, 0) != 13) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_DARK,
                UACLASS_THIEF, 17000, 0)
                != 0) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_DARK,
                UACLASS_ASSASSIN,
                18000, 0) != 10) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_WOOD,
                UACLASS_ASSASSIN,
                18510, 0) != 10) ++bad;
            if (subraceLevelFootnote(
                SUB_ELF_GRAY,
                UACLASS_ASSASSIN,
                18510, 0) != 0) ++bad;
            if (subraceLevelFootnote(
                SUB_ELF_HIGH,
                UACLASS_ASSASSIN,
                18760, 0) != 0) ++bad;
            if (subraceLevelFootnote(
                SUB_ELF_HIGH,
                UACLASS_RANGER,
                18760, 0) != 3) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_VALLEY,
                UACLASS_ASSASSIN,
                18999, 0) != 12) ++bad;
            if (subraceLevelFootnote(
                SUB_ELF_WOOD,
                UACLASS_ASSASSIN,
                20000, 0) != 5) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_DARK,
                UACLASS_RANGER,
                18000, 0) != 6) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_WOOD,
                UACLASS_RANGER,
                18010, 0) != 7) ++bad;
            if (subraceLevelFootnote(
                SUB_ELF_GRAY,
                UACLASS_RANGER,
                18010, 0) != 1) ++bad;
            if (subraceLevelFootnote(
                SUB_ELF_HIGH,
                UACLASS_RANGER,
                18510, 0) != 2) ++bad;
            if (subraceLevelLimit(
                SUB_ELF_WOOD,
                UACLASS_RANGER,
                20000, 0) != 14) ++bad;
            if (subraceLevelFootnote(
                SUB_ELF_DARK,
                UACLASS_RANGER,
                20000, 0) != 4) ++bad;
        }
        // U5: Table II.D (half-elves)
        {
            if (subraceLevelLimit(
                SUB_HALFELF,
                UACLASS_CLERIC, 18000, 0)
                != 8) ++bad;
            if (subraceLevelLimit(
                SUB_HALFELF,
                UACLASS_CLERIC, 20000, 0)
                != 12) ++bad;
            if (subraceLevelLimit(
                SUB_HALFELF,
                UACLASS_DRUID, 15000, 0)
                != 0) ++bad;
            if (subraceLevelLimit(
                SUB_HALFELF,
                UACLASS_FIGHTER, 18000, 0)
                != 7) ++bad;
            if (subraceLevelLimit(
                SUB_HALFELF,
                UACLASS_FIGHTER, 18900, 0)
                != 8) ++bad;
            if (subraceLevelLimit(
                SUB_HALFELF,
                UACLASS_FIGHTER, 18999, 0)
                != 10) ++bad;
            if (subraceLevelLimit(
                SUB_HALFELF,
                UACLASS_FIGHTER, 20000, 0)
                != 13) ++bad;
            if (subraceLevelLimit(
                SUB_HALFELF,
                UACLASS_RANGER, 18900, 0)
                != 9) ++bad;
            if (subraceLevelFootnote(
                SUB_HALFELF,
                UACLASS_RANGER, 18900, 0)
                != 1) ++bad;
            if (subraceLevelLimit(
                SUB_HALFELF,
                UACLASS_RANGER, 18990, 0)
                != 10) ++bad;
            if (subraceLevelLimit(
                SUB_HALFELF,
                UACLASS_RANGER, 18999, 0)
                != 11) ++bad;
            if (subraceLevelFootnote(
                SUB_HALFELF,
                UACLASS_RANGER, 18999, 0)
                != 2) ++bad;
            if (subraceLevelLimit(
                SUB_HALFELF,
                UACLASS_RANGER, 20000, 0)
                != 15) ++bad;
            if (subraceLevelFootnote(
                SUB_HALFELF,
                UACLASS_RANGER, 20000, 0)
                != 3) ++bad;
            if (subraceLevelLimit(
                SUB_HALFELF,
                UACLASS_MAGIC_USER,
                19000, 0) != 8) ++bad;
            if (subraceLevelLimit(
                SUB_HALFELF,
                UACLASS_THIEF, 15000, 0)
                != 0) ++bad;
            if (subraceLevelLimit(
                SUB_HALFELF,
                UACLASS_ASSASSIN,
                15000, 0) != 11) ++bad;
            if (subraceLevelLimit(
                SUB_HALFELF,
                UACLASS_ASSASSIN,
                20000, 0) != 11) ++bad;
        }
        // U6: Table II.E (halflings)
        {
            if (subraceLevelLimit(
                SUB_HALFLING_HAIRFOOT,
                UACLASS_CLERIC, 18000, 0)
                != 6) ++bad;
            if (subraceLevelLimit(
                SUB_HALFLING_STOUT,
                UACLASS_CLERIC, 20000, 0)
                != 10) ++bad;
            if (subraceLevelLimit(
                SUB_HALFLING_HAIRFOOT,
                UACLASS_DRUID, 15000, 0)
                != 6) ++bad;
            if (subraceLevelFootnote(
                SUB_HALFLING_STOUT,
                UACLASS_DRUID, 15000, 0)
                != 1) ++bad;
            if (subraceLevelFootnote(
                SUB_HALFLING_TALLFELLOW,
                UACLASS_DRUID, 17000, 0)
                != 3) ++bad;
            if (subraceLevelLimit(
                SUB_HALFLING_HAIRFOOT,
                UACLASS_DRUID, 18000, 0)
                != 11) ++bad;
            if (subraceLevelFootnote(
                SUB_HALFLING_STOUT,
                UACLASS_DRUID, 18000, 0)
                != 4) ++bad;
            if (subraceLevelLimit(
                SUB_HALFLING_TALLFELLOW,
                UACLASS_DRUID, 20000, 0)
                != 13) ++bad;
            if (subraceLevelFootnote(
                SUB_HALFLING_HAIRFOOT,
                UACLASS_DRUID, 20000, 0)
                != 5) ++bad;
            if (subraceLevelLimit(
                SUB_HALFLING_HAIRFOOT,
                UACLASS_FIGHTER, 18500, 0)
                != 6) ++bad;
            if (subraceLevelLimit(
                SUB_HALFLING_HAIRFOOT,
                UACLASS_FIGHTER, 20000, 0)
                != 8) ++bad;
            if (subraceLevelLimit(
                SUB_HALFLING_STOUT,
                UACLASS_FIGHTER, 18900, 0)
                != 8) ++bad;
            if (subraceLevelLimit(
                SUB_HALFLING_STOUT,
                UACLASS_FIGHTER, 20000, 0)
                != 9) ++bad;
            if (subraceLevelLimit(
                SUB_HALFLING_TALLFELLOW,
                UACLASS_FIGHTER, 18900, 0)
                != 9) ++bad;
            if (subraceLevelLimit(
                SUB_HALFLING_TALLFELLOW,
                UACLASS_FIGHTER, 20000, 0)
                != 10) ++bad;
            if (subraceLevelLimit(
                SUB_HALFLING_HAIRFOOT,
                UACLASS_THIEF, 15000, 0)
                != 0) ++bad;
        }
        // U7: Table II.F (half-orcs)
        {
            if (subraceLevelLimit(
                SUB_HALF_ORC,
                UACLASS_CLERIC, 14000, 0)
                != 4) ++bad;
            if (subraceLevelLimit(
                SUB_HALF_ORC,
                UACLASS_CLERIC, 21000, 0)
                != 7) ++bad;
            if (subraceLevelLimit(
                SUB_HALF_ORC,
                UACLASS_FIGHTER, 14000, 0)
                != 10) ++bad;
            if (subraceLevelLimit(
                SUB_HALF_ORC,
                UACLASS_FIGHTER, 18990, 0)
                != 10) ++bad;
            if (subraceLevelLimit(
                SUB_HALF_ORC,
                UACLASS_FIGHTER, 18999, 0)
                != 11) ++bad;
            if (subraceLevelLimit(
                SUB_HALF_ORC,
                UACLASS_FIGHTER, 21000, 0)
                != 17) ++bad;
            if (subraceLevelLimit(
                SUB_HALF_ORC,
                UACLASS_THIEF, 17000, 0)
                != 11) ++bad;
            if (subraceLevelLimit(
                SUB_HALF_ORC,
                UACLASS_THIEF, 20000, 0)
                != 11) ++bad;
            if (subraceLevelLimit(
                SUB_HALF_ORC,
                UACLASS_ASSASSIN,
                14000, 0) != 0) ++bad;
            if (subraceLevelLimit(
                SUB_HALF_ORC,
                UACLASS_ASSASSIN,
                21000, 0) != 0) ++bad;
        }
        // U8: the gates, the riders
        // and the +2 rule
        {
            const LevelGate* g;
            int n, orMode;
            subraceLevelGates(
                SUB_DWARF_HILL,
                UACLASS_ASSASSIN, 1,
                g, n, orMode);
            if (n != 2 || orMode != 0
                || g[0].stat != ABILITY_INT
                || g[0].min != 18
                || g[1].stat != ABILITY_DEX
                || g[1].min != 19) ++bad;
            subraceLevelGates(
                SUB_DWARF_GRAY,
                UACLASS_ASSASSIN, 2,
                g, n, orMode);
            if (n != 2 || g[0].min != 19
                || g[1].min != 19) ++bad;
            subraceLevelGates(
                SUB_GNOME_DEEP,
                UACLASS_ASSASSIN, 1,
                g, n, orMode);
            if (n != 2 || g[0].min != 18
                || g[1].min != 18) ++bad;
            subraceLevelGates(
                SUB_ELF_WILD,
                UACLASS_DRUID, 1,
                g, n, orMode);
            if (n != 1
                || g[0].stat != ABILITY_CHA
                || g[0].min != 18) ++bad;
            subraceLevelGates(
                SUB_ELF_WOOD,
                UACLASS_RANGER, 5,
                g, n, orMode);
            if (n != 2
                || g[0].stat != ABILITY_INT
                || g[0].min != 18
                || g[1].stat != ABILITY_WIS
                || g[1].min != 19) ++bad;
            // fn6: the OR read
            subraceLevelGates(
                SUB_ELF_DARK,
                UACLASS_RANGER, 6,
                g, n, orMode);
            if (n != 2 || orMode != 1)
                ++bad;
            // the wild-elf assassin
            // reads the shared gates
            subraceLevelGates(
                SUB_ELF_WILD,
                UACLASS_ASSASSIN, 3,
                g, n, orMode);
            if (n != 2 || orMode != 0
                || g[0].min != 17
                || g[1].min != 17) ++bad;
            subraceLevelGates(
                SUB_HALFELF,
                UACLASS_RANGER, 1,
                g, n, orMode);
            if (n != 3
                || g[2].stat != ABILITY_CON
                || g[2].min != 18) ++bad;
            subraceLevelGates(
                SUB_HALFELF,
                UACLASS_RANGER, 3,
                g, n, orMode);
            if (n != 3 || g[0].min != 19
                || g[2].min != 19) ++bad;
            subraceLevelGates(
                SUB_HALFLING_STOUT,
                UACLASS_DRUID, 5,
                g, n, orMode);
            if (n != 1
                || g[0].stat != ABILITY_CHA
                || g[0].min != 19) ++bad;
            // a footnote the pair
            // does not carry reads null
            subraceLevelGates(
                SUB_DWARF_HILL,
                UACLASS_CLERIC, 1,
                g, n, orMode);
            if (n != 0 || g != 0) ++bad;
            if (elfRangerAbove15Level()
                != 8) ++bad;
            if (halfElfRanger19Level()
                != 12) ++bad;
            if (halfElfRanger20Level()
                != 14) ++bad;
            if (halflingDruid16Level()
                != 8) ++bad;
            if (halflingDruid17Level()
                != 10) ++bad;
            if (halflingDruid18Level()
                != 12) ++bad;
            if (singleClassLevelBonus()
                != 2) ++bad;
        }
        printf("R324 subrace level limits audit: bad %d\n", bad);
        if (bad) return 1;
    }
