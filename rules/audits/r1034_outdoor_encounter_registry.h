// ============================================================================
// Adnd1 - rules/audits/r1034_outdoor_encounter_registry.h  (R1034)
// The outdoor (wilderness) encounter family battery audit, the
// R1032/R1033 shape: the registry load, exact table counts, band
// coverage and engine parity, row spot pins against the retired
// print-fidelity record, the pick-sets, the key companions vs the
// monster registry, and the rollOutdoorEncounter() path.
// Expected values: 21 files, 348 outdoor rows (19 tables + the
// tropical Sphinx footnote) - all from the R63 outdoor record
// (Premium reprint p.182-191) and the R126 line-diff record the
// splice parsed.
// ============================================================================
{

    static const char* const kNames[20] =
        { "outdoor_arctic", "outdoor_sub_arctic", "outdoor_temperate_wild", "outdoor_temperate_inhabited", "outdoor_faerie", "outdoor_pleistocene", "outdoor_dinosaur_age", "outdoor_tropical", "outdoor_sub_demihuman", "outdoor_sub_dragon", "outdoor_sub_frog", "outdoor_sub_giant", "outdoor_sub_humanoid", "outdoor_sub_lycanthrope", "outdoor_sub_men", "outdoor_sub_snake", "outdoor_sub_sphinx", "outdoor_sub_spider", "outdoor_sub_undead", "outdoor_sphinx_t" };
    static const int kRows[20] = { 12, 24, 59, 40, 38, 23, 29, 52, 4, 11, 3, 8, 5, 5, 9, 4, 4, 4, 10, 4 };

    int bad = 0;
    dm::EncounterTableRegistry ereg;

    // -- 1. load: 21 outdoor files, zero errors, all dirs one reg --
    bad = 0;
    {
        const int files = ereg.loadDirectory(
            "content/tables/encounters_outdoor");
        if (files != 21) ++bad;
        if (!ereg.errors().empty()) ++bad;
        // all three families in one registry: the dungeon and
        // water files join with no key collision (their own
        // audits pin their own loads separately)
        const int df = ereg.loadDirectory(
            "content/tables/encounters");
        if (df != 20) ++bad;
        const int wf = ereg.loadDirectory(
            "content/tables/encounters_water");
        if (wf != 9) ++bad;
        if (!ereg.hasOutdoor("outdoor_arctic")) ++bad;
        if (!ereg.hasOutdoor("outdoor_sphinx_t")) ++bad;
        if (!ereg.hasWater("dinosaur_sub")) ++bad;
        if (!ereg.hasLevel(10)) ++bad;
    }
    printf("R1034 outdoor encounter registry load audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 2. counts: every table, exact row census -----------------------
    bad = 0;
    {
        int total = 0;
        for (int i = 0; i < 20; ++i) {
            if (!ereg.hasOutdoor(kNames[i])) ++bad;
            const int n = (int)ereg.outdoorRows(kNames[i]).size();
            if (n != kRows[i]) ++bad;
            total += n;
        }
        if (total != 348) ++bad;
        if (ereg.hasOutdoor("dungeon_level_1")) ++bad;   // STRICT shapes
        if (ereg.hasOutdoor("underwater_fresh_shallow")) ++bad;
        // the sets file is its own shape, never an outdoor
        // table (the R1034 preflight dispatch-order bug)
        if (ereg.hasOutdoor("outdoor_sets")) ++bad;
        // the pick-sets ride the registry lists
        static const char* const kSets[6] =
            { "ki_rin_set", "leprechaun_set", "porcupine_set",
              "iguanodon_set", "lammasu_set", "wolf_dog_set" };
        static const int kSetSizes[6] = { 3, 2, 2, 2, 2, 2 };
        for (int i = 0; i < 6; ++i)
            if ((int)ereg.list(kSets[i]).size() != kSetSizes[i]) ++bad;
    }
    printf("R1034 outdoor encounter registry counts audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 3. bands: column coverage + engine parity ---------------------
    bad = 0;
    {
        // per-table column discipline: the entries a column
        // carries chain 1 -> 100 (a column with no entries
        // at all is legal - rows print no entry there)
        for (int i = 0; i < 20; ++i) {
            const auto& rs = ereg.outdoorRows(kNames[i]);
            for (int c = 0; c < 8; ++c) {
                int prev = 0; bool any = false;
                for (const auto& r : rs) {
                    if (r.lo[c] < 0) continue;
                    any = true;
                    if (r.lo[c] != prev + 1 || r.hi[c] < r.lo[c])
                        { ++bad; break; }
                    prev = r.hi[c];
                }
                if (any && prev != 100) ++bad;
            }
        }
        // engine parity: dm::outdoorBands must carry the registry
        // rows verbatim, every climate x terrain column
        for (int c = 0; c < 8; ++c)
            for (int t = 0; t < 8; ++t) {
                const auto& got = dm::outdoorBands(
                    (dm::OutdoorClime)c, (dm::OutdoorTerrain)t);
                const auto& want = ereg.outdoorRows(kNames[c]);
                size_t n = 0;
                for (const auto& r : want)
                    if (r.lo[t] >= 0) ++n;
                if (got.size() != n) { ++bad; continue; }
                size_t j = 0;
                for (const auto& r : want) {
                    if (r.lo[t] < 0) continue;
                    if (got[j].key != r.key || got[j].lo != r.lo[t]
                        || got[j].hi != r.hi[t]) { ++bad; break; }
                    ++j;
                }
            }
        // engine parity: the eleven SUB_* subtables and the
        // tropical Sphinx footnote, every terrain column
        static const char* const kSubs[12] = {
            "SUB_DEMIHUMAN", "SUB_DRAGON", "SUB_FROG",
            "SUB_GIANT", "SUB_HUMANOID", "SUB_LYCANTHROPE",
            "SUB_MEN", "SUB_SNAKE", "SUB_SPHINX",
            "SUB_SPIDER", "SUB_UNDEAD", "SUB_SPHINX_T" };
        static const char* const kSubNames[12] = {
            "outdoor_sub_demihuman", "outdoor_sub_dragon",
            "outdoor_sub_frog", "outdoor_sub_giant",
            "outdoor_sub_humanoid", "outdoor_sub_lycanthrope",
            "outdoor_sub_men", "outdoor_sub_snake",
            "outdoor_sub_sphinx", "outdoor_sub_spider",
            "outdoor_sub_undead", "outdoor_sphinx_t" };
        for (int s = 0; s < 12; ++s)
            for (int t = 0; t < 8; ++t) {
                const auto& got = dm::outdoorSubBands(
                    kSubs[s], (dm::OutdoorTerrain)t);
                const auto& want = ereg.outdoorRows(kSubNames[s]);
                size_t n = 0;
                for (const auto& r : want)
                    if (r.lo[t] >= 0) ++n;
                if (got.size() != n) { ++bad; continue; }
                size_t j = 0;
                for (const auto& r : want) {
                    if (r.lo[t] < 0) continue;
                    if (got[j].key != r.key || got[j].lo != r.lo[t]
                        || got[j].hi != r.hi[t]) { ++bad; break; }
                    ++j;
                }
            }
    }
    printf("R1034 outdoor encounter registry bands audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 4. rows: spot pins, the R126 line-diff record ------------------
    bad = 0;
    {
        dm::EncounterOutdoorRow r;
        r = ereg.outdoorRows("outdoor_arctic")[0];
        if (r.key != "brown_bear") ++bad;
        if (r.lo[0] != 1 || r.hi[0] != 10) ++bad;
        if (r.lo[1] != -1 || r.hi[1] != -1) ++bad;
        if (r.lo[2] != -1 || r.hi[2] != -1) ++bad;
        if (r.lo[3] != 1 || r.hi[3] != 9) ++bad;
        if (r.lo[4] != -1 || r.hi[4] != -1) ++bad;
        if (r.lo[5] != -1 || r.hi[5] != -1) ++bad;
        if (r.lo[6] != 1 || r.hi[6] != 7) ++bad;
        if (r.lo[7] != -1 || r.hi[7] != -1) ++bad;
        r = ereg.outdoorRows("outdoor_arctic")[11];
        if (r.key != "yeti") ++bad;
        if (r.lo[0] != 96 || r.hi[0] != 100) ++bad;
        if (r.lo[1] != -1 || r.hi[1] != -1) ++bad;
        if (r.lo[2] != -1 || r.hi[2] != -1) ++bad;
        if (r.lo[3] != 96 || r.hi[3] != 100) ++bad;
        if (r.lo[4] != -1 || r.hi[4] != -1) ++bad;
        if (r.lo[5] != -1 || r.hi[5] != -1) ++bad;
        if (r.lo[6] != 91 || r.hi[6] != 100) ++bad;
        if (r.lo[7] != -1 || r.hi[7] != -1) ++bad;
        r = ereg.outdoorRows("outdoor_temperate_wild")[18];
        if (r.key != "giant_eagle") ++bad;
        if (r.lo[0] != 15 || r.hi[0] != 16) ++bad;
        if (r.lo[1] != -1 || r.hi[1] != -1) ++bad;
        if (r.lo[2] != 15 || r.hi[2] != 15) ++bad;
        if (r.lo[3] != 14 || r.hi[3] != 14) ++bad;
        if (r.lo[4] != 9 || r.hi[4] != 9) ++bad;
        if (r.lo[5] != 25 || r.hi[5] != 25) ++bad;
        if (r.lo[6] != 13 || r.hi[6] != 14) ++bad;
        if (r.lo[7] != 8 || r.hi[7] != 8) ++bad;
        r = ereg.outdoorRows("outdoor_tropical")[27];
        if (r.key != "bandit") ++bad;
        if (r.lo[0] != 56 || r.hi[0] != 59) ++bad;
        if (r.lo[1] != 56 || r.hi[1] != 59) ++bad;
        if (r.lo[2] != 53 || r.hi[2] != 56) ++bad;
        if (r.lo[3] != 46 || r.hi[3] != 48) ++bad;
        if (r.lo[4] != 41 || r.hi[4] != 45) ++bad;
        if (r.lo[5] != 41 || r.hi[5] != 45) ++bad;
        if (r.lo[6] != 23 || r.hi[6] != 30) ++bad;
        if (r.lo[7] != -1 || r.hi[7] != -1) ++bad;
        r = ereg.outdoorRows("outdoor_tropical")[28];
        if (r.key != "dervish") ++bad;
        if (r.lo[0] != 60 || r.hi[0] != 60) ++bad;
        if (r.lo[1] != -1 || r.hi[1] != -1) ++bad;
        if (r.lo[2] != -1 || r.hi[2] != -1) ++bad;
        if (r.lo[3] != 49 || r.hi[3] != 50) ++bad;
        if (r.lo[4] != 46 || r.hi[4] != 55) ++bad;
        if (r.lo[5] != 46 || r.hi[5] != 47) ++bad;
        if (r.lo[6] != -1 || r.hi[6] != -1) ++bad;
        if (r.lo[7] != -1 || r.hi[7] != -1) ++bad;
        r = ereg.outdoorRows("outdoor_sub_giant")[5];
        if (r.key != "stone_giant") ++bad;
        if (r.lo[0] != 96 || r.hi[0] != 98) ++bad;
        if (r.lo[1] != 95 || r.hi[1] != 98) ++bad;
        if (r.lo[2] != 94 || r.hi[2] != 98) ++bad;
        if (r.lo[3] != 86 || r.hi[3] != 98) ++bad;
        if (r.lo[4] != -1 || r.hi[4] != -1) ++bad;
        if (r.lo[5] != 82 || r.hi[5] != 98) ++bad;
        if (r.lo[6] != 51 || r.hi[6] != 90) ++bad;
        if (r.lo[7] != -1 || r.hi[7] != -1) ++bad;
        r = ereg.outdoorRows("outdoor_sub_dragon")[4];
        if (r.key != "chimera") ++bad;
        if (r.lo[0] != 9 || r.hi[0] != 10) ++bad;
        if (r.lo[1] != 9 || r.hi[1] != 10) ++bad;
        if (r.lo[2] != 23 || r.hi[2] != 30) ++bad;
        if (r.lo[3] != 46 || r.hi[3] != 50) ++bad;
        if (r.lo[4] != 68 || r.hi[4] != 70) ++bad;
        if (r.lo[5] != 26 || r.hi[5] != 35) ++bad;
        if (r.lo[6] != 26 || r.hi[6] != 30) ++bad;
        if (r.lo[7] != 57 || r.hi[7] != 58) ++bad;
        r = ereg.outdoorRows("outdoor_sub_men")[3];
        if (r.key != "SUB_CHARACTER") ++bad;
        if (r.lo[0] != 11 || r.hi[0] != 20) ++bad;
        if (r.lo[1] != 16 || r.hi[1] != 25) ++bad;
        if (r.lo[2] != 16 || r.hi[2] != 25) ++bad;
        if (r.lo[3] != 16 || r.hi[3] != 25) ++bad;
        if (r.lo[4] != 11 || r.hi[4] != 20) ++bad;
        if (r.lo[5] != 21 || r.hi[5] != 30) ++bad;
        if (r.lo[6] != 21 || r.hi[6] != 30) ++bad;
        if (r.lo[7] != 11 || r.hi[7] != 20) ++bad;
        r = ereg.outdoorRows("outdoor_sphinx_t")[2];
        if (r.key != "gynosphinx") ++bad;
        if (r.lo[0] != 41 || r.hi[0] != 70) ++bad;
        if (r.lo[1] != 41 || r.hi[1] != 70) ++bad;
        if (r.lo[2] != 41 || r.hi[2] != 70) ++bad;
        if (r.lo[3] != 41 || r.hi[3] != 70) ++bad;
        if (r.lo[4] != 41 || r.hi[4] != 70) ++bad;
        if (r.lo[5] != 41 || r.hi[5] != 70) ++bad;
        if (r.lo[6] != 41 || r.hi[6] != 70) ++bad;
        if (r.lo[7] != 41 || r.hi[7] != 70) ++bad;
    }
    printf("R1034 outdoor encounter registry pins audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 5. sets: the six pick-sets, exact membership -------------------
    bad = 0;
    {
        const auto& s_ki_rin_set = ereg.list("ki_rin_set");
        if ((int)s_ki_rin_set.size() != 3) ++bad;
        if (s_ki_rin_set[0] != "ki_rin") ++bad;
        if (s_ki_rin_set[1] != "lammasu") ++bad;
        if (s_ki_rin_set[2] != "shedu") ++bad;
        if (!reg.find("ki_rin")) ++bad;
        if (!reg.find("lammasu")) ++bad;
        if (!reg.find("shedu")) ++bad;
        const auto& s_leprechaun_set = ereg.list("leprechaun_set");
        if ((int)s_leprechaun_set.size() != 2) ++bad;
        if (s_leprechaun_set[0] != "leprechaun") ++bad;
        if (s_leprechaun_set[1] != "brownie") ++bad;
        if (!reg.find("leprechaun")) ++bad;
        if (!reg.find("brownie")) ++bad;
        const auto& s_porcupine_set = ereg.list("porcupine_set");
        if ((int)s_porcupine_set.size() != 2) ++bad;
        if (s_porcupine_set[0] != "giant_porcupine") ++bad;
        if (s_porcupine_set[1] != "giant_skunk") ++bad;
        if (!reg.find("giant_porcupine")) ++bad;
        if (!reg.find("giant_skunk")) ++bad;
        const auto& s_iguanodon_set = ereg.list("iguanodon_set");
        if ((int)s_iguanodon_set.size() != 2) ++bad;
        if (s_iguanodon_set[0] != "iguanodon") ++bad;
        if (s_iguanodon_set[1] != "lambeosaurus") ++bad;
        if (!reg.find("iguanodon")) ++bad;
        if (!reg.find("lambeosaurus")) ++bad;
        const auto& s_lammasu_set = ereg.list("lammasu_set");
        if ((int)s_lammasu_set.size() != 2) ++bad;
        if (s_lammasu_set[0] != "lammasu") ++bad;
        if (s_lammasu_set[1] != "shedu") ++bad;
        if (!reg.find("lammasu")) ++bad;
        if (!reg.find("shedu")) ++bad;
        const auto& s_wolf_dog_set = ereg.list("wolf_dog_set");
        if ((int)s_wolf_dog_set.size() != 2) ++bad;
        if (s_wolf_dog_set[0] != "wolf") ++bad;
        if (s_wolf_dog_set[1] != "wild_dog") ++bad;
        if (!reg.find("wolf")) ++bad;
        if (!reg.find("wild_dog")) ++bad;
        if (!ereg.list("no_such_set").empty()) ++bad;   // STRICT
    }
    printf("R1034 outdoor encounter registry sets audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 6. keys: the companions vs an independent registry walk -------
    bad = 0;
    {
        auto pushU = [](std::vector<std::string>& v,
                      const std::string& k) {
            for (const auto& x : v) if (x == k) return;
            v.push_back(k);
        };
        auto setNameOf = [](const std::string& k) -> const char* {
            if (k == "KI_RIN_SET") return "ki_rin_set";
            if (k == "LEPRECHAUN_SET") return "leprechaun_set";
            if (k == "PORCUPINE_SET") return "porcupine_set";
            if (k == "IGUANODON_SET") return "iguanodon_set";
            if (k == "LAMMASU_SET") return "lammasu_set";
            if (k == "WOLF_DOG_SET") return "wolf_dog_set";
            return nullptr;
        };
        auto subNameOf = [](const std::string& k) -> const char* {
            if (k == "SUB_DEMIHUMAN") return "outdoor_sub_demihuman";
            if (k == "SUB_DRAGON") return "outdoor_sub_dragon";
            if (k == "SUB_FROG") return "outdoor_sub_frog";
            if (k == "SUB_GIANT") return "outdoor_sub_giant";
            if (k == "SUB_HUMANOID") return "outdoor_sub_humanoid";
            if (k == "SUB_LYCANTHROPE") return
                "outdoor_sub_lycanthrope";
            if (k == "SUB_MEN") return "outdoor_sub_men";
            if (k == "SUB_SNAKE") return "outdoor_sub_snake";
            if (k == "SUB_SPHINX") return "outdoor_sub_sphinx";
            if (k == "SUB_SPIDER") return "outdoor_sub_spider";
            if (k == "SUB_UNDEAD") return "outdoor_sub_undead";
            return nullptr;
        };
        // an independent worklist expansion straight off the
        // registry - must equal the engine's key companion
        for (int c = 0; c < 8; ++c)
            for (int t = 0; t < 8; ++t) {
                std::vector<std::string> work;
                for (const auto& r : ereg.outdoorRows(kNames[c]))
                    if (r.lo[t] >= 0) work.push_back(r.key);
                std::vector<std::string> want;
                while (!work.empty()) {
                    const std::string k = work.back();
                    work.pop_back();
                    if (k == "SUB_CHARACTER")
                        { pushU(want, "character_party"); continue; }
                    if (k == "MISC_REPTILE")
                        { pushU(want, "giant_lizard"); continue; }
                    if (k == "SUB_SPHINX_T") {
                        for (const auto& r :
                             ereg.outdoorRows("outdoor_sphinx_t"))
                            pushU(want, r.key);
                        continue;
                    }
                    const char* sn = setNameOf(k);
                    if (sn) {
                        for (const auto& s : ereg.list(sn))
                            pushU(want, s);
                        continue;
                    }
                    const char* sub = subNameOf(k);
                    if (sub) {
                        for (const auto& r : ereg.outdoorRows(sub))
                            if (r.lo[t] >= 0) work.push_back(r.key);
                        continue;
                    }
                    if (k.compare(0, 4, "SUB_") == 0) { ++bad; continue; }
                    if (reg.find(k)) pushU(want, k);
                }
                const auto got = dm::outdoorEncounterKeys(
                    reg, (dm::OutdoorClime)c, (dm::OutdoorTerrain)t);
                if (got.size() != want.size()) { ++bad; continue; }
                // set equality, both unique
                for (const auto& k : got) {
                    bool hit = false;
                    for (const auto& w : want)
                        if (k == w) { hit = true; break; }
                    if (!hit) { ++bad; break; }
                    if (!reg.find(k) && k != "character_party") ++bad;
                }
                for (const auto& w : want) {
                    bool hit = false;
                    for (const auto& k : got)
                        if (k == w) { hit = true; break; }
                    if (!hit) { ++bad; break; }
                }
            }
    }
    printf("R1034 outdoor encounter registry keys audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 7. roll: the outdoor path, sweep + smoke ----------------------
    bad = 0;
    {
        // the SUB_CHARACTER roll block is dead code in the
        // retired engine (resolveOutdoorKey returns false for
        // it - the R63 dispatch quirk, preserved verbatim);
        // outdoorEncounterKeys still lists character_party
        rules::Rng rng(1034);
        rules::Dice dice(rng);
        int produced = 0;
        static int seen[64];
        for (int i = 0; i < 64; ++i) seen[i] = 0;
        for (int c = 0; c < 8; ++c)
            for (int t = 0; t < 8; ++t) {
                const auto allowed = dm::outdoorEncounterKeys(
                    reg, (dm::OutdoorClime)c, (dm::OutdoorTerrain)t);
                for (int pct = 1; pct <= 100; ++pct) {
                    const int p2 = 1 + (pct * 37) % 100;
                    dm::DungeonEncounter e = dm::rollOutdoorEncounter(
                        reg, dice, pct, p2,
                        (dm::OutdoorClime)c, (dm::OutdoorTerrain)t);
                    if (e.key.empty()) continue;
                    ++produced;
                    ++seen[c * 8 + t];
                    if (e.isParty)   // defensive: dead as retired
                        if (e.key != "character_party") ++bad;
                    if (!reg.find(e.key)) ++bad;
                    if (e.count < 1) ++bad;
                    bool hit = false;
                    for (const auto& k : allowed)
                        if (k == e.key) { hit = true; break; }
                    if (!hit) ++bad;
                }
            }
        // every populated combo (non-empty companion) must produce
        // (SUB_CHARACTER columns lose their quirk cells, so the
        // per-combo count is not pinned at 100)
        for (int c = 0; c < 8; ++c)
            for (int t = 0; t < 8; ++t) {
                const auto allowed = dm::outdoorEncounterKeys(
                    reg, (dm::OutdoorClime)c, (dm::OutdoorTerrain)t);
                if (!allowed.empty() && seen[c * 8 + t] == 0) ++bad;
            }
        // rng smoke: 4000 rolls, outcomes must be legal
        for (int i = 0; i < 4000; ++i) {
            const int c = i % 8, t = (i / 8) % 8;
            dm::DungeonEncounter e = dm::rollOutdoorEncounter(
                reg, dice, 1 + i % 100, 1 + (i * 53) % 100,
                (dm::OutdoorClime)c, (dm::OutdoorTerrain)t);
            if (e.key.empty()) continue;
            if (e.isParty)   // defensive: dead as retired
                if (e.key != "character_party") ++bad;
            if (e.isParty) continue;
            if (!reg.find(e.key)) ++bad;
            if (e.count < 1) ++bad;
            const auto allowed = dm::outdoorEncounterKeys(
                reg, (dm::OutdoorClime)c, (dm::OutdoorTerrain)t);
            bool hit = false;
            for (const auto& k : allowed)
                if (k == e.key) { hit = true; break; }
            if (!hit) ++bad;
        }
        if (produced < 4000) ++bad;  // the sweep resolves broadly
    }
    printf("R1034 outdoor encounter registry roll audit: bad %d\n", bad);
    if (bad) return 1;
}
