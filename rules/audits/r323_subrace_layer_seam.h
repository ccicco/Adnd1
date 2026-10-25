    // ---- R323: the subrace layer seam audit ----
    // The UA subrace seam (rules/subraces.h):
    // the 17 racial types, Race Table I
    // with the alignment column, the
    // Racial Preferences matrix, the
    // sub-race mechanics traits. Pinned
    // data only - the wiring rounds
    // follow. Draw-independent.
    {
        using namespace rules;
        int bad = 0;
        // U1: the enum shape
        {
            if (SUBRACE_COUNT != 18) ++bad;
            if (UACLASS_COUNT != 14) ++bad;
            if (HE_ANCESTRY_COUNT != 6) ++bad;
            if (subraceName(SUB_NONE)[0]
                != 'N') ++bad;
        }
        // U2: the parent mapping
        {
            if (subraceParentRace(
                    SUB_DWARF_GRAY)
                != RACE_DWARF) ++bad;
            if (subraceParentRace(
                    SUB_DWARF_MOUNTAIN)
                != RACE_DWARF) ++bad;
            if (subraceParentRace(
                    SUB_ELF_DARK)
                != RACE_ELF) ++bad;
            if (subraceParentRace(
                    SUB_ELF_WOOD)
                != RACE_ELF) ++bad;
            if (subraceParentRace(
                    SUB_GNOME_DEEP)
                != RACE_GNOME) ++bad;
            if (subraceParentRace(
                    SUB_HALFELF)
                != RACE_HALF_ELF) ++bad;
            if (subraceParentRace(
                    SUB_HALFLING_STOUT)
                != RACE_HALFLING) ++bad;
            if (subraceParentRace(
                    SUB_HALF_ORC)
                != RACE_HALF_ORC) ++bad;
            if (subraceParentRace(
                    SUB_HUMAN)
                != RACE_HUMAN) ++bad;
        }
        // U3: Race Table I - the spot cells
        // (the drow cavalier, the valley
        // gate, the grugach limits, the
        // gnome illusionist, the halfling
        // assassin ban, the half-elf bard,
        // the human full row)
        {
            if (!subraceClassAllowed(
                SUB_ELF_DARK,
                UACLASS_CAVALIER)) ++bad;
            if (subraceClassAllowed(
                SUB_ELF_VALLEY,
                UACLASS_CAVALIER)) ++bad;
            if (subraceClassAllowed(
                SUB_ELF_VALLEY,
                UACLASS_MAGIC_USER)) ++bad;
            if (subraceClassAllowed(
                SUB_ELF_WILD,
                UACLASS_RANGER)) ++bad;
            if (subraceClassAllowed(
                SUB_ELF_WILD,
                UACLASS_DRUID) != true)
                ++bad;
            if (subraceClassAllowed(
                SUB_GNOME_DEEP,
                UACLASS_ILLUSIONIST)
                != true) ++bad;
            if (subraceClassAllowed(
                SUB_HALFLING_STOUT,
                UACLASS_ASSASSIN)) ++bad;
            if (subraceClassAllowed(
                SUB_HALFELF,
                UACLASS_BARD) != true) ++bad;
            if (subraceClassAllowed(
                SUB_HALFELF,
                UACLASS_ILLUSIONIST))
                ++bad;
            if (subraceClassAllowed(
                SUB_HALF_ORC,
                UACLASS_DRUID)) ++bad;
            if (subraceClassAllowed(
                SUB_DWARF_GRAY,
                UACLASS_DRUID)) ++bad;
            if (subraceClassAllowed(
                SUB_ELF_WOOD,
                UACLASS_MAGIC_USER)
                != true) ++bad;
            if (subraceClassAllowed(
                SUB_ELF_DARK,
                UACLASS_PALADIN)) ++bad;
            int all = 0;
            for (int c = 0;
                 c < UACLASS_COUNT; ++c) {
                if (!subraceClassAllowed(
                    SUB_HUMAN,
                    (UaClass)c)) ++all;
            }
            if (all) ++bad;
        }
        // U4: the alignment column
        {
            if (uaClassAlignmentReq(
                UACLASS_PALADIN)
                != UA_ALIGN_LG_ONLY) ++bad;
            if (uaClassAlignmentReq(
                UACLASS_DRUID)
                != UA_ALIGN_TRUE_NEUTRAL)
                ++bad;
            if (uaClassAlignmentReq(
                UACLASS_ASSASSIN)
                != UA_ALIGN_ANY_EVIL) ++bad;
            if (uaClassAlignmentReq(
                UACLASS_MONK)
                != UA_ALIGN_ANY_LAWFUL) ++bad;
            if (uaClassAlignmentReq(
                UACLASS_BARD)
                != UA_ALIGN_ANY_NEUTRAL)
                ++bad;
            if (uaClassAlignmentReq(
                UACLASS_BARBARIAN)
                != UA_ALIGN_NON_LAWFUL) ++bad;
            if (uaClassAlignmentReq(
                UACLASS_THIEF)
                != UA_ALIGN_NON_GOOD) ++bad;
            if (uaClassAlignmentReq(
                UACLASS_CLERIC)
                != UA_ALIGN_ANY) ++bad;
        }
        // U5: the preferences matrix - all
        // 289 cells in range, the diagonal
        // all P, the print asymmetries
        {
            for (int v = SUB_DWARF_GRAY;
                 v <= SUB_HUMAN; ++v) {
                for (int w = SUB_DWARF_GRAY;
                     w <= SUB_HUMAN; ++w) {
                    RacePref p =
                        subracePrefers(
                        (CharSubRace)v,
                        (CharSubRace)w);
                    if (p < PREF_P
                        || p > PREF_H) ++bad;
                }
            }
            for (int v = SUB_DWARF_GRAY;
                 v <= SUB_HUMAN; ++v) {
                if (subracePrefers(
                    (CharSubRace)v,
                    (CharSubRace)v)
                    != PREF_P) ++bad;
            }
            // the print pins: dark elves
            // view all halflings with
            // antipathy, tallfellows read
            // dark elves neutral
            if (subracePrefers(
                SUB_ELF_DARK,
                SUB_HALFLING_HAIRFOOT)
                != PREF_A) ++bad;
            if (subracePrefers(
                SUB_HALFLING_TALLFELLOW,
                SUB_ELF_DARK)
                != PREF_N) ++bad;
            // half-orcs hate both dwarf
            // strains; humans tolerate
            // half-elves
            if (subracePrefers(
                SUB_HALF_ORC,
                SUB_DWARF_HILL)
                != PREF_H) ++bad;
            if (subracePrefers(
                SUB_HALF_ORC,
                SUB_DWARF_MOUNTAIN)
                != PREF_H) ++bad;
            if (subracePrefers(
                SUB_HUMAN, SUB_HALFELF)
                != PREF_T) ++bad;
            // the letter roundtrip
            if (racePrefLetter(PREF_P)[0]
                != 'P') ++bad;
            if (racePrefLetter(PREF_H)[0]
                != 'H') ++bad;
            // out-of-range reads neutral
            if (subracePrefers(SUB_NONE,
                SUB_HUMAN)
                != PREF_N) ++bad;
        }
        // U6: the traits - the ability
        // grain, the deep-strain reads
        {
            const SubRaceTraits& g =
                subraceTraits(SUB_ELF_GRAY);
            if (g.adj[ABILITY_INT] != 1
                || g.max[ABILITY_INT] != 19)
                ++bad;
            const SubRaceTraits& v =
                subraceTraits(SUB_ELF_VALLEY);
            if (v.adj[ABILITY_INT] != 1
                || v.max[ABILITY_INT] != 19)
                ++bad;
            const SubRaceTraits& w =
                subraceTraits(SUB_ELF_WOOD);
            if (w.adj[ABILITY_STR] != 1
                || w.adj[ABILITY_INT] != -1)
                ++bad;
            const SubRaceTraits& g2 =
                subraceTraits(SUB_ELF_WILD);
            if (g2.adj[ABILITY_STR] != 2)
                ++bad;
            const SubRaceTraits& d =
                subraceTraits(SUB_DWARF_GRAY);
            if (d.illusionImmune != 1
                || d.paralysisImmune != 1
                || d.magicPoisonImmune
                != 1) ++bad;
            if (d.surpriseOn != 3
                || d.surpriseDie != 6
                || d.surprisedOn != 1
                || d.surprisedDie != 10)
                ++bad;
            if (d.infravisionFeet != 120)
                ++bad;
            const SubRaceTraits& e =
                subraceTraits(SUB_ELF_DARK);
            if (e.saveVsMagicBonus != 2
                || e.surprisedOn != 1
                || e.surprisedDie != 8
                || e.moveFemale != 15
                || e.moveMale != 12
                || e.twoWeaponFree != 1
                || e.losesSwordBowBonus != 1
                || e.infravisionFeet != 120)
                ++bad;
            const SubRaceTraits& n =
                subraceTraits(SUB_GNOME_DEEP);
            if (n.saveVsPoisonBonus != 2
                || n.saveOtherBonus != 3
                || n.illusionImmune != 1
                || n.surpriseOn != 9
                || n.surpriseDie != 10
                || n.surprisedOn != 1
                || n.surprisedDie != 12
                || n.maleOnlyPC != 1
                || n.noPsionics != 1
                || n.infravisionFeet != 120)
                ++bad;
        }
        // U7: the prose pins - the
        // daylight ladders, the grugach
        // and svirfneblin reads, the
        // elemental table, the innate
        // spell lists
        {
            if (duergarDayDexPenalty() != 2
                || duergarDayToHitPenalty()
                != 2
                || duergarDayOpponentSaveBonus()
                != 2
                || duergarShadowToHitPenalty()
                != 1
                || duergarShadowSaveBonus()
                != 1) ++bad;
            if (wildElfTrapSuccessPct() != 90
                || wildElfMultiClassCount()
                != 1
                || wildElfAnimalFriendshipDeal()
                != 1) ++bad;
            if (svirfCamouflagePct() != 60
                || svirfBrightLightFeet() != 30
                || svirfBrightToHitPenalty()
                != 1
                || svirfDeepFoeToHitBonus() != 1
                || svirfDeepFoeDamageBonus()
                != 1) ++bad;
            int n = 0;
            const EarthElementalRow* R =
                svirfEarthElementalTable(n);
            if (n != 6) ++bad;
            if (R[0].lo != 1 || R[0].hi != 1)
                ++bad;
            if (R[1].lo != 2 || R[1].hi != 6)
                ++bad;
            if (R[2].lo != 7 || R[2].hi != 10)
                ++bad;
            if (R[3].lo != 11 || R[3].hi != 15)
                ++bad;
            if (R[4].lo != 16 || R[4].hi != 18)
                ++bad;
            if (R[5].lo != 19 || R[5].hi != 20)
                ++bad;
            if (R[5].result[0] != 's') ++bad;
            // the spans tile the d20
            for (int i = 0; i < n; ++i) {
                if (i && R[i].lo
                    != R[i-1].hi + 1) ++bad;
            }
            const char** L = 0;
            if (drowInnateBase(L) != 3) ++bad;
            if (L[0][0] != 'd'
                || L[1][0] != 'f'
                || L[2][0] != 'd') ++bad;
            if (drowInnateAt4(L) != 3) ++bad;
            if (L[0][0] != 'd') ++bad;
            if (drowInnateFemale4(L) != 4)
                ++bad;
            if (svirfInnate(L) != 3) ++bad;
            if (L[0][0] != 'b') ++bad;
            if (drowSilentTongueRangeFeet()
                != 30) ++bad;
            if (duergarMultiClassCount() != 4)
                ++bad;
        }
        // U8: the half-elf ancestries and
        // the comeliness subrace grain
        {
            if (halfElfAncestryExists(
                HE_ANCESTRY_GRUGACH))
                ++bad;
            if (!halfElfAncestryExists(
                HE_ANCESTRY_HIGH)) ++bad;
            if (!halfElfAncestryExists(
                HE_ANCESTRY_DROW)) ++bad;
            if (uaComelinessViewedSubraceAdj(
                SUB_ELF_GRAY) != 2) ++bad;
            if (uaComelinessViewedSubraceAdj(
                SUB_ELF_HIGH) != 2) ++bad;
            if (uaComelinessViewedSubraceAdj(
                SUB_ELF_WOOD) != 1) ++bad;
            if (uaComelinessViewedSubraceAdj(
                SUB_HUMAN) != 0) ++bad;
        }
        printf("R323 subrace layer seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
