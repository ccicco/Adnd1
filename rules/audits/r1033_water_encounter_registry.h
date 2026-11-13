// ============================================================================
// Adnd1 - rules/audits/r1033_water_encounter_registry.h  (R1033)
// The water encounter family battery audit, the R1032 shape: the
// registry load, exact table counts, band coverage, the footnote
// flag gates, row spot pins against the retired print-fidelity
// record, the key companions vs the monster registry, and the
// rollWaterEncounter() / rollWaterborneEncounter() paths.
// Expected values: 9 files, 205 water rows - all from the R60
// underwater record (p.179-181) and the R127 waterborne record
// (p.190) the splice parsed.
// ============================================================================
{

    static const char* const kNames[9] =
        { "underwater_fresh_shallow", "underwater_fresh_deep", "underwater_salt_shallow", "underwater_salt_deep", "dinosaur_sub", "waterborne_fresh_small", "waterborne_fresh_large", "waterborne_salt_shallow", "waterborne_salt_deep" };
    static const int kRows[9] = { 27, 23, 42, 35, 5, 9, 20, 24, 20 };

    int bad = 0;
    dm::EncounterTableRegistry ereg;

    // -- 1. load: 9 water files, zero errors, both dirs one reg -
    bad = 0;
    {
        const int files = ereg.loadDirectory(
            "content/tables/encounters_water");
        if (files != 9) ++bad;
        if (!ereg.errors().empty()) ++bad;
        // both families in one registry: 20 dungeon files join
        // with no key collision (the R1032 audit pins its own
        // 20-file load separately)
        const int df = ereg.loadDirectory(
            "content/tables/encounters");
        if (df != 20) ++bad;
        if (!ereg.hasWater("dinosaur_sub")) ++bad;
        if (!ereg.hasLevel(10)) ++bad;
    }
    printf("R1033 water encounter registry load audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 2. counts: every table, exact row census ------------------------
    bad = 0;
    {
        int total = 0;
        for (int i = 0; i < 9; ++i) {
            if (!ereg.hasWater(kNames[i])) ++bad;
            const int n = (int)ereg.waterRows(kNames[i]).size();
            if (n != kRows[i]) ++bad;
            total += n;
        }
        if (total != 205) ++bad;
        if (ereg.hasWater("dungeon_level_1")) ++bad;   // STRICT shapes
    }
    printf("R1033 water encounter registry counts audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 3. bands: 01-00 coverage + engine parity ----------------------
    bad = 0;
    {
        for (int i = 0; i < 9; ++i) {
            const auto& rs = ereg.waterRows(kNames[i]);
            if (rs.empty() || rs[0].lo != 1 || rs.back().hi != 100)
                { ++bad; continue; }
            int prev = 0;
            for (const auto& r : rs) {
                if (r.lo != prev + 1 || r.hi < r.lo) { ++bad; break; }
                prev = r.hi;
            }
        }
        // engine parity: dm::waterborneBands / dinosaurSubBands must
        // carry the registry rows verbatim (the R127 line-diff pins)
        for (int body = 0; body < 2; ++body)
            for (int dep = 0; dep < 2; ++dep) {
                const auto& got = dm::waterborneBands(
                    (dm::WaterBody)body, (dm::WaterDepth)dep);
                const auto& want = ereg.waterRows(
                    body == 0 ? (dep == 0
                        ? "waterborne_fresh_small"
                        : "waterborne_fresh_large")
                    : (dep == 0
                        ? "waterborne_salt_shallow"
                        : "waterborne_salt_deep"));
                if (got.size() != want.size()) { ++bad; continue; }
                for (size_t i = 0; i < got.size(); ++i)
                    if (got[i].key != want[i].key
                        || got[i].lo != want[i].lo
                        || got[i].hi != want[i].hi
                        || got[i].flags != want[i].flags)
                        { ++bad; break; }
            }
        const auto& db = dm::dinosaurSubBands();
        const auto& dw = ereg.waterRows("dinosaur_sub");
        if (db.size() != dw.size() || db.size() != 5) ++bad;
        for (size_t i = 0; i < db.size() && i < dw.size(); ++i)
            if (db[i].key != dw[i].key || db[i].lo != dw[i].lo
                || db[i].hi != dw[i].hi || db[i].flags != dw[i].flags)
                ++bad;
    }
    printf("R1033 water encounter registry bands audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 4. flags: footnote gates, domain and pins ----------------------
    bad = 0;
    {
        for (int i = 0; i < 9; ++i)
            for (const auto& r : ereg.waterRows(kNames[i]))
                if (r.flags != 0 && r.flags != 1 && r.flags != 2
                    && r.flags != 4) ++bad;
        dm::EncounterWaterRow r;
        r = ereg.waterRows(kNames[0])[0];
        if (r.lo != 1 || r.hi != 6 || r.key != "giant_beaver"
            || r.flags != 1) ++bad;
        r = ereg.waterRows(kNames[0])[4];
        if (r.lo != 21 || r.hi != 23 || r.key != "DINOSAUR"
            || r.flags != 2) ++bad;
        r = ereg.waterRows(kNames[5])[4];
        if (r.lo != 61 || r.hi != 65 || r.key != "nixie"
            || r.flags != 1) ++bad;
        r = ereg.waterRows(kNames[6])[15];
        if (r.lo != 86 || r.hi != 90 || r.key != "nixie"
            || r.flags != 2) ++bad;
        r = ereg.waterRows(kNames[4])[1];
        if (r.lo != 16 || r.hi != 35 || r.key != "dinichthys"
            || r.flags != 4) ++bad;
        // gate census: cool/warm row counts per clime-split table
        {
            int c = 0, w = 0;
            for (const auto& r : ereg.waterRows("underwater_fresh_shallow"))
                { if (r.flags == 1) ++c; if (r.flags == 2) ++w; }
            if (c != 4 || w != 5) ++bad;
        }
        {
            int c = 0, w = 0;
            for (const auto& r : ereg.waterRows("waterborne_fresh_small"))
                { if (r.flags == 1) ++c; if (r.flags == 2) ++w; }
            if (c != 2 || w != 2) ++bad;
        }
        {
            int c = 0, w = 0;
            for (const auto& r : ereg.waterRows("waterborne_fresh_large"))
                { if (r.flags == 1) ++c; if (r.flags == 2) ++w; }
            if (c != 1 || w != 5) ++bad;
        }
    }
    printf("R1033 water encounter registry flags audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 5. rows: spot pins, substitutions documented in-row ----------
    bad = 0;
    {
        dm::EncounterWaterRow r;
        r = ereg.waterRows("underwater_salt_shallow")[36];
        if (r.lo != 92 || r.hi != 92 || r.key != "sperm_whale"
            || r.flags != 0) ++bad;
        r = ereg.waterRows("underwater_salt_shallow")[41];
        if (r.lo != 99 || r.hi != 100 || r.key != "white_whale_beluga"
            || r.flags != 0) ++bad;
        r = ereg.waterRows("underwater_fresh_deep")[15];
        if (r.lo != 61 || r.hi != 63 || r.key != "purple_worm"
            || r.flags != 0) ++bad;
        r = ereg.waterRows("underwater_salt_deep")[4];
        if (r.lo != 21 || r.hi != 21 || r.key != "dragon_turtle"
            || r.flags != 0) ++bad;
        r = ereg.waterRows("waterborne_salt_shallow")[13];
        if (r.lo != 68 || r.hi != 70 || r.key != "caveman"
            || r.flags != 0) ++bad;
        r = ereg.waterRows("waterborne_salt_shallow")[16];
        if (r.lo != 75 || r.hi != 75 || r.key != "giant_octopus"
            || r.flags != 0) ++bad;
        r = ereg.waterRows("waterborne_salt_shallow")[22];
        if (r.lo != 91 || r.hi != 96 || r.key != "black_whale"
            || r.flags != 0) ++bad;
        r = ereg.waterRows("waterborne_salt_deep")[19];
        if (r.lo != 96 || r.hi != 100 || r.key != "white_whale_beluga"
            || r.flags != 0) ++bad;
        r = ereg.waterRows("waterborne_fresh_large")[11];
        if (r.lo != 34 || r.hi != 48 || r.key != "buccaneer"
            || r.flags != 0) ++bad;
    }
    printf("R1033 water encounter registry rows audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 6. keys: the companions vs the monster registry -------------
    bad = 0;
    {
        for (int body = 0; body < 2; ++body)
            for (int dep = 0; dep < 2; ++dep) {
                const auto uk = dm::waterEncounterKeys(
                    reg, (dm::WaterBody)body, (dm::WaterDepth)dep);
                const auto bk = dm::waterborneEncounterKeys(
                    reg, (dm::WaterBody)body, (dm::WaterDepth)dep);
                for (const auto& k : uk)
                    if (!reg.find(k)) ++bad;
                for (const auto& k : bk)
                    if (!reg.find(k)) ++bad;
                for (size_t i = 0; i < uk.size(); ++i)
                    for (size_t j = i + 1; j < uk.size(); ++j)
                        if (uk[i] == uk[j]) ++bad;
                for (size_t i = 0; i < bk.size(); ++i)
                    for (size_t j = i + 1; j < bk.size(); ++j)
                        if (bk[i] == bk[j]) ++bad;
            }
        // every DINOSAUR-bearing table reaches all five subtable keys
        // (the registry carries all five MM dinosaurs; the union
        // covers the fresh-small table, which prints no Dinosaur
        // row - as printed)
        static const char* const kDinos[5] =
            { "archelon_ischyros", "dinichthys", "elasmosaurus",
              "mosasaurus", "plesiosaurus" };
        for (int i = 0; i < 5; ++i)
            if (!reg.find(kDinos[i])) ++bad;
        for (int i = 0; i < 5; ++i) {
            bool hit = false;
            for (int body = 0; body < 2 && !hit; ++body)
                for (int dep = 0; dep < 2 && !hit; ++dep) {
                    const auto bk = dm::waterborneEncounterKeys(
                        reg, (dm::WaterBody)body, (dm::WaterDepth)dep);
                    for (const auto& k : bk)
                        if (k == kDinos[i]) { hit = true; break; }
                }
            if (!hit) ++bad;
        }
        // the four underwater tables and the three dino-bearing
        // waterborne tables each expand all five keys directly
        for (int body = 0; body < 2; ++body)
            for (int dep = 0; dep < 2; ++dep) {
                const auto uk = dm::waterEncounterKeys(
                    reg, (dm::WaterBody)body, (dm::WaterDepth)dep);
                if (uk.empty()) ++bad;
                for (int i = 0; i < 5; ++i) {
                    bool hit = false;
                    for (const auto& k : uk)
                        if (k == kDinos[i]) { hit = true; break; }
                    if (!hit) ++bad;
                }
            }
        for (int dep = 1; dep < 2; ++dep) {
            const auto bk = dm::waterborneEncounterKeys(
                reg, dm::WaterBody::FRESH, (dm::WaterDepth)dep);
            if (bk.empty()) ++bad;
            for (int i = 0; i < 5; ++i) {
                bool hit = false;
                for (const auto& k : bk)
                    if (k == kDinos[i]) { hit = true; break; }
                if (!hit) ++bad;
            }
        }
    }
    printf("R1033 water encounter registry keys audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 7. roll: both water paths, sweep + smoke ---------------------
    bad = 0;
    {
        rules::Rng rng(1033);
        rules::Dice dice(rng);
        for (int body = 0; body < 2; ++body)
            for (int dep = 0; dep < 2; ++dep)
                for (int cl = 0; cl < 2; ++cl) {
                    const auto uk = dm::waterEncounterKeys(
                        reg, (dm::WaterBody)body, (dm::WaterDepth)dep);
                    const auto bk = dm::waterborneEncounterKeys(
                        reg, (dm::WaterBody)body, (dm::WaterDepth)dep);
                    int rolled = 0;
                    for (int pct = 1; pct <= 100; ++pct) {
                        const int p2 = 1 + (pct * 37) % 100;
                        dm::DungeonEncounter a = dm::rollWaterEncounter(
                            reg, dice, pct, p2, (dm::WaterBody)body,
                            (dm::WaterDepth)dep, (dm::WaterClime)cl);
                        dm::DungeonEncounter b =
                            dm::rollWaterborneEncounter(
                                reg, dice, pct, p2, (dm::WaterBody)body,
                                (dm::WaterDepth)dep,
                                (dm::WaterClime)cl);
                        ++rolled;
                        if (!a.key.empty() && !reg.find(a.key)) ++bad;
                        if (!b.key.empty() && !reg.find(b.key)) ++bad;
                        if (!a.key.empty()) {
                            bool hit = false;
                            for (const auto& k : uk)
                                if (k == a.key) { hit = true; break; }
                            if (!hit) ++bad;
                        }
                        if (!b.key.empty()) {
                            bool hit = false;
                            for (const auto& k : bk)
                                if (k == b.key) { hit = true; break; }
                            if (!hit) ++bad;
                        }
                    }
                    if (rolled != 100) ++bad;
                }
        // rng smoke: 2000 rolls per path, outcomes must be legal and
        // every table must have produced at least one encounter
        int seen[8] = { 0 };
        int produced = 0;
        for (int i = 0; i < 2000; ++i) {
            const int body = i % 2, dep = (i / 2) % 2;
            const int cl = (i / 4) % 2;
            dm::DungeonEncounter a = dm::rollWaterEncounter(
                reg, dice, 1 + i % 100, 1 + (i * 53) % 100,
                (dm::WaterBody)body, (dm::WaterDepth)dep,
                (dm::WaterClime)cl);
            dm::DungeonEncounter b = dm::rollWaterborneEncounter(
                reg, dice, 1 + i % 100, 1 + (i * 53) % 100,
                (dm::WaterBody)body, (dm::WaterDepth)dep,
                (dm::WaterClime)cl);
            if (!a.key.empty()) {
                if (!reg.find(a.key)) ++bad;
                if (a.count < 1) ++bad;
                ++seen[body * 2 + dep];
                ++produced;
            }
            if (!b.key.empty()) {
                if (!reg.find(b.key)) ++bad;
                if (b.count < 1) ++bad;
                ++seen[4 + body * 2 + dep];
                ++produced;
            }
        }
        if (produced < 2000) ++bad;
        for (int i = 0; i < 8; ++i)
            if (seen[i] == 0) ++bad;
    }
    printf("R1033 water encounter registry roll audit: bad %d\n", bad);
    if (bad) return 1;
}
