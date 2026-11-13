// ============================================================================
// Adnd1 - rules/audits/r1032_encounter_engine_registry.h  (R1032)
// The dm::EncounterTableRegistry battery audit, the R1028 shape: the
// registry load, exact table counts, the Determination Matrix vs
// monsterLevelFor, the six pools, row spot pins against the retired
// print-fidelity record, and the full rollDungeonEncounter() path.
// Expected values: 20 files, 213 level rows, 72 dragon rows,
// 12x10 matrix, 6 pools - all from the R52 record the splice parsed.
// ============================================================================
{

    int bad = 0;
    dm::EncounterTableRegistry ereg;

    // -- 1. load: 20 files, zero errors ----------------------------------
    bad = 0;
    {
        const int files = ereg.loadDirectory("content/tables/encounters");
        if (files != 20) ++bad;
        if (!ereg.errors().empty()) ++bad;
    }
    printf("R1032 encounter engine registry load audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 2. counts: every table, exact row census ------------------------
    bad = 0;
    {
        static const int kLvl[11] = { 0, 20, 13, 18, 19, 21, 26, 42, 26, 18, 10 };
        static const int kDrg[11] = { 0, 0, 0, 3, 10, 10, 10, 10, 10, 10, 9 };
        for (int n = 1; n <= 10; ++n) {
            if (!ereg.hasLevel(n)) ++bad;
            if ((int)ereg.levelRows(n).size() != kLvl[n]) ++bad;
        }
        for (int n = 3; n <= 10; ++n) {
            if (!ereg.hasDragon(n)) ++bad;
            if ((int)ereg.dragonRows(n).size() != kDrg[n]) ++bad;
        }
    }
    printf("R1032 encounter engine registry counts audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 3. bands: the Determination Matrix, band 7 (dl 7) pinned ---------
    bad = 0;
    {
        const auto& b7 = ereg.matrixBand(6);
        if ((int)b7.size() != 10) ++bad;
        static const int want[10][3] = { { 1, 1, 1 }, { 2, 2, 2 }, { 3, 4, 3 }, { 5, 7, 4 }, { 8, 10, 5 }, { 11, 14, 6 }, { 15, 16, 7 }, { 17, 18, 8 }, { 19, 19, 9 }, { 20, 20, 10 } };
        for (int i = 0; i < 10; ++i)
            if (b7[i].lo != want[i][0] || b7[i].hi != want[i][1]
                || b7[i].mlv != want[i][2]) ++bad;
    }
    printf("R1032 encounter engine registry bands audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 4. matrix: monsterLevelFor vs the registry, every band ----------
    bad = 0;
    {
        for (int band = 0; band < 12; ++band) {
            // the engine maps band = dl-1, clamped: dl < 1 -> band 0,
            // dl >= 16 -> band 11 (and dl 12 also reaches band 11;
            // dl 13-15 read past the matrix - the preserved upstream
            // quirk, not swept here)
            const int dl = band == 0 ? 0 : (band == 11 ? 16 : band + 1);
            const auto& ents = ereg.matrixBand(band);
            if ((int)ents.size() != 10) { ++bad; continue; }
            for (int d20 = 1; d20 <= 20; ++d20) {
                int want = 1;
                for (int i = 0; i < 10; ++i)
                    if (ents[i].lo > 0 && d20 >= ents[i].lo
                        && d20 <= ents[i].hi) { want = i + 1; break; }
                if (dm::monsterLevelFor(dl, d20) != want) ++bad;
            }
        }
    }
    printf("R1032 encounter engine registry matrix audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 5. lists: the six dispatch pools, verbatim ----------------------
    bad = 0;
    {
        struct Want { const char* name;
                      std::vector<std::string> keys; };
        const Want want[] = {
        { "princes", { "demogorgon", "juiblex", "orcus", "yeenoghu" } },
        { "arch_devils", { "asmodeus", "baalzebul", "dispater", "geryon" } },
        { "elementals", { "air_elemental", "earth_elemental", "fire_elemental", "water_elemental" } },
        { "hill_stone", { "hill_giant", "stone_giant" } },
        { "fire_frost", { "fire_giant", "frost_giant" } },
        { "piercers", { "piercer_smallest", "piercer_small", "piercer_medium", "piercer_largest" } }
        };
        for (const auto& w : want) {
            const auto& got = ereg.list(w.name);
            if (got != w.keys) ++bad;
        }
    }
    printf("R1032 encounter engine registry lists audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 6. rows: spot pins against the retired print-fidelity record ----
    bad = 0;
    {
        const auto& l1 = ereg.levelRows(1);
        if ((int)l1.size() < 2
            || l1[0].kind != "monster" || l1[0].key != "giant_ant"
            || l1[0].lo != 1 || l1[0].hi != 2
            || l1[0].a != 1 || l1[0].b != 4
            || l1.back().kind != "monster" || l1.back().key != "zombie"
            || l1.back().lo != 99 || l1.back().hi != 100
            || l1.back().a != 1 || l1.back().b != 3) ++bad;
        const auto& l10 = ereg.levelRows(10);
        if ((int)l10.size() < 2
            || l10.back().kind != "none"
            || l10.back().lo != 81 || l10.back().hi != 100)
            ++bad;
        const auto& hy = ereg.levelRows(4);
        bool hyd = false;
        for (const auto& r : hy)
            if (r.kind == "hydra" && r.key == "hydra"
                && r.a == 5 && r.b == 6) hyd = true;
        if (!hyd) ++bad;
        int total = 0;
        for (int n = 1; n <= 10; ++n) total += (int)ereg.levelRows(n).size();
        if (total != 213) ++bad;
    }
    printf("R1032 encounter engine registry rows audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 7. roll: the rollDungeonEncounter smoke, R1028 style ------------
    bad = 0;
    {
        rules::Rng rng(1032);
        rules::Dice dice(rng);
        // band 7 test d20s: one per matrix entry, mlv 1..10 in order
        static const int kD20[11] = { 0, 1, 2, 3, 5, 8, 11, 15, 17, 19, 20 };
        int seen[11] = { 0 };
        int rolled = 0;
        for (int n = 1; n <= 10; ++n) {
            const auto& rows = ereg.levelRows(n);
            for (const auto& r : rows) {
                if (r.kind == "character" || r.kind == "none") continue;
                const int mid = (r.lo + r.hi) / 2;
                for (int p2 = 1; p2 <= 100; ++p2) {
                    dm::DungeonEncounter e = dm::rollDungeonEncounter(
                        reg, dice, kD20[n], mid, p2, 7);
                    ++rolled;
                    // legal outcomes: party (human/character), empty
                    // (reroll chains, absent keys), or a registry key
                    if (e.isParty || e.key.empty()) continue;
                    if (!reg.find(e.key)) { ++bad; continue; }
                    if (r.kind == "dragon") {
                        bool hit = false;
                        for (const auto& d : ereg.dragonRows(n))
                            if (d.key == e.key && e.ageLo == d.ageLo
                                && e.ageHi == d.ageHi) { hit = true; break; }
                        if (!hit) ++bad;
                    }
                    ++seen[n];
                }
            }
        }
        if (rolled < 200) ++bad;
        for (int n = 1; n <= 10; ++n)
            if (seen[n] == 0) ++bad;
    }
    printf("R1032 encounter engine registry roll audit: bad %d\n", bad);
    if (bad) return 1;
}
