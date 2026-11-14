// ============================================================================
// Adnd1 - rules/audits/r1035_city_encounter_registry.h  (R1035)
// The city/town encounter family battery audit, the
// R1032-R1034 shape: the registry load, exact table counts,
// band coverage, row/dice/chance spot pins against the retired
// print-fidelity record, the flavor engine parity, the key
// companion vs the matrix, and the rollCityEncounter() path.
// Expected values: 9 city files - the 46-row city matrix
// (day/night percentile bands), 28 count-dice entries, the
// 4x3 magic chances and the six band tables (drunk 20,
// harlot 12, noble 2, sedan 2, ruffian 6, protection 11) -
// all from the R64/R146/R174 city record (Premium reprint
// p.190-192) the splice parsed. The city keys are fiction-
// heavy: party-type and civilian keys carry no bestiary
// record by design, so the companion is checked against the
// matrix expansion, not reg.find().
// ============================================================================
{

    static const char* const kBands[6] = {
        "city_band_drunk", "city_band_harlot",
        "city_band_noble", "city_band_sedan",
        "city_band_ruffian", "city_band_protection" };
    static const int kBandRows[6] = { 20, 12, 2, 2, 6, 11 };

    int bad = 0;
    dm::EncounterTableRegistry ereg;

    // -- 1. load: 9 city files, zero errors, all dirs one reg --
    bad = 0;
    {
        const int cf = ereg.loadDirectory(
            "content/tables/encounters_city");
        if (cf != 9) ++bad;
        if (!ereg.errors().empty()) ++bad;
        const int of = ereg.loadDirectory(
            "content/tables/encounters_outdoor");
        if (of != 21) ++bad;
        const int df = ereg.loadDirectory(
            "content/tables/encounters");
        if (df != 20) ++bad;
        const int wf = ereg.loadDirectory(
            "content/tables/encounters_water");
        if (wf != 9) ++bad;
        if (!ereg.hasCityMatrix()) ++bad;
        if (!ereg.hasCityBands("city_band_drunk")) ++bad;
        if (!ereg.hasCityBands("city_band_harlot")) ++bad;
        if (!ereg.hasCityBands("city_band_noble")) ++bad;
        if (!ereg.hasCityBands("city_band_sedan")) ++bad;
        if (!ereg.hasCityBands("city_band_ruffian")) ++bad;
        if (!ereg.hasCityBands("city_band_protection")) ++bad;
        // negative pins (the R1034 dispatch-order lesson:
        // the exact keys and the prefix must stay exclusive)
        if (ereg.hasCityBands("city_matrix")) ++bad;
        if (ereg.hasCityBands("outdoor_sets")) ++bad;
        if (ereg.hasOutdoor("city_matrix")) ++bad;
        if (ereg.hasWater("city_band_drunk")) ++bad;
        if (ereg.hasCityBands("")) ++bad;
    }
    printf("R1035 city encounter registry load audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 2. counts: the matrix, bands, dice and chances -----
    bad = 0;
    {
        if ((int)ereg.cityRows().size() != 46) ++bad;
        int bandTotal = 0;
        for (int i = 0; i < 6; ++i) {
            const int n = (int)ereg.cityBands(kBands[i]).size();
            if (n != kBandRows[i]) ++bad;
            bandTotal += n;
        }
        if (bandTotal != 53) ++bad;
        static const char* const kCountKeys[28] = {
            "bandit", "beggar", "doppelganger", "giant_rat",
            "ghoul", "ghast", "drunk", "gentleman", "laborer",
            "peddler", "mercenary", "merchant", "bard",
            "night_hag", "noble", "pilgrim", "press_gang",
            "rakshasa", "ruffian", "shadow", "spectre",
            "tradesman", "wererat", "weretiger", "werewolf",
            "wight", "will_o_wisp", "wraith" };
        int countTotal = 0;
        for (int i = 0; i < 28; ++i)
            if (ereg.cityCount(kCountKeys[i])) ++countTotal;
            else ++bad;
        if (countTotal != 28) ++bad;
        // fallthrough keys roll one specimen
        if (ereg.cityCount("ghost")) ++bad;
        if (ereg.cityCount("vampire")) ++bad;
        if (ereg.cityCount("harlot")) ++bad;
        if (ereg.cityCount("assassin")) ++bad;   // party path
        if ((int)ereg.cityMagic().size() != 4) ++bad;
    }
    printf("R1035 city encounter registry counts audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 3. bands: day/night chains + every flavor table ---
    bad = 0;
    {
        for (int pass = 0; pass < 2; ++pass) {
            int prev = 0;
            for (const auto& r : ereg.cityRows()) {
                const int lo = pass == 0 ? r.loDay : r.loNight;
                const int hi = pass == 0 ? r.hiDay : r.hiNight;
                if (lo < 0) continue;
                if (lo != prev + 1 || hi < lo || hi > 100) ++bad;
                prev = hi;
            }
            if (prev != 100) ++bad;
        }
        for (int i = 0; i < 6; ++i) {
            int prev = 0;
            for (const auto& b : ereg.cityBands(kBands[i])) {
                if (b.lo != prev + 1 || b.hi < b.lo || b.hi > 100)
                    ++bad;
                prev = b.hi;
            }
            if (prev != 100) ++bad;
        }
    }
    printf("R1035 city encounter registry bands audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 4. pins: matrix rows, dice, chances (the record) ---
    bad = 0;
    {
        const auto& m = ereg.cityRows();
        if (m[0].key != "assassin") ++bad;
        if (m[0].loDay != 1 || m[0].hiDay != 1) ++bad;
        if (m[0].loNight != 1 || m[0].hiNight != 3) ++bad;
        if (m[8].key != "demon_or_nycadaemon") ++bad;
        if (m[8].loDay != -1 || m[8].hiDay != -1) ++bad;
        if (m[8].loNight != 23 || m[8].hiNight != 23) ++bad;
        if (m[40].key != "weretiger") ++bad;
        if (m[40].loDay != 99 || m[40].hiDay != 99) ++bad;
        if (m[40].loNight != 94 || m[40].hiNight != 94) ++bad;
        if (m[45].key != "vampire_or_lich") ++bad;
        if (m[45].loDay != -1 || m[45].hiDay != -1) ++bad;
        if (m[45].loNight != 100 || m[45].hiNight != 100) ++bad;
        // dice pins (the printed numbers, code behavior)
        const auto* c = ereg.cityCount("bandit");
        if (!c || c->n != 1 || c->d != 10 || c->plus != 2) ++bad;
        c = ereg.cityCount("giant_rat");
        if (!c || !c->hasNight) ++bad;
        else {
            if (c->n != 2 || c->d != 4 || c->plus != 0) ++bad;
            if (c->nN != 1 || c->dN != 24 || c->plusN != 1) ++bad;
        }
        c = ereg.cityCount("press_gang");
        if (!c || c->n != 1 || c->d != 16 || c->plus != 1) ++bad;
        c = ereg.cityCount("peddler");
        if (!c || c->fixed != 1) ++bad;
        // the dead bard entry, preserved
        c = ereg.cityCount("bard");
        if (!c || c->fixed != 1) ++bad;
        // magic chance pins
        int sawSword = 0, sawProt = 0;
        for (const auto& r : ereg.cityMagic()) {
            if (r.category == "sword") {
                sawSword = 1;
                if (r.groups[0] != 10 || r.groups[1] != 0
                    || r.groups[2] != 0) ++bad;
            }
            if (r.category == "protection") {
                sawProt = 1;
                if (r.groups[0] != 2 || r.groups[1] != 2
                    || r.groups[2] != 10) ++bad;
            }
        }
        if (!sawSword || !sawProt) ++bad;
        // protection band pins
        std::string kind;
        if (!ereg.cityBandLookup("city_band_protection", 1, &kind))
            ++bad;
        else if (kind != "prot_ring1") ++bad;
        if (!ereg.cityBandLookup("city_band_protection", 100, &kind))
            ++bad;
        else if (kind != "prot_cloak3") ++bad;
    }
    printf("R1035 city encounter registry pins audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 5. flavor: the R146/R174 engine parity --------------
    bad = 0;
    {
        static const char* const kFunc[6][2] = {
            { "city_band_drunk", "drunk" },
            { "city_band_harlot", "harlot" },
            { "city_band_noble", "noble" },
            { "city_band_sedan", "sedan" },
            { "city_band_ruffian", "ruffian" },
            { "city_band_protection", "prot" } };
        for (int f = 0; f < 5; ++f)
            for (int pct = 1; pct <= 100; ++pct) {
                std::string want;
                ereg.cityBandLookup(kFunc[f][0], pct, &want);
                const char* got =
                    f == 0 ? dm::cityDrunkKind(pct)
                    : f == 1 ? dm::cityHarlotKind(pct)
                    : f == 2 ? dm::cityNobleKind(pct)
                    : f == 3 ? dm::cityNoblewomanSedan(pct)
                    : dm::cityRuffianKind(pct);
                if (got == nullptr || want != got) ++bad;
            }
        // the clamp contract (the retired flavorKindFor)
        if (dm::cityDrunkKind(0)[0] == 0) ++bad;   // clamp, not empty
        const char* at0 = dm::cityDrunkKind(0);
        const char* at1 = dm::cityDrunkKind(1);
        if (std::string(at0) != std::string(at1)) ++bad;
        const char* at101 = dm::cityDrunkKind(101);
        const char* at100 = dm::cityDrunkKind(100);
        if (std::string(at101) != std::string(at100)) ++bad;
    }
    printf("R1035 city encounter registry flavor audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 6. keys: the companion vs the matrix expansion ----
    bad = 0;
    {
        const auto got = dm::cityEncounterKeys(reg);
        std::vector<std::string> want;
        auto pushU = [&](const std::string& k) {
            for (const auto& w : want)
                if (w == k) return;
            want.push_back(k);
        };
        for (const auto& r : ereg.cityRows()) {
            const std::string k = r.key;
            if (k == "laborer_or_peddler")
                { pushU("laborer"); pushU("peddler"); continue; }
            if (k == "monk_or_bard")
                { pushU("monk"); pushU("bard"); continue; }
            if (k == "ghoul_or_ghast")
                { pushU("ghoul"); pushU("ghast"); continue; }
            if (k == "vampire_or_lich")
                { pushU("vampire"); pushU("lich"); continue; }
            if (k == "brigand")
                { pushU("bandit"); continue; }
            if (k == "demon_or_nycadaemon" ||
                k == "devil_or_mezzadaemon")
                continue;
            pushU(k);
        }
        if (got.size() != want.size() || want.size() != 47) ++bad;
        for (const auto& k : got) {
            bool hit = false;
            for (const auto& w : want)
                if (k == w) { hit = true; break; }
            if (!hit) { ++bad; break; }
        }
        for (const auto& k : want) {
            bool hit = false;
            for (const auto& g : got)
                if (k == g) { hit = true; break; }
            if (!hit) { ++bad; break; }
        }
    }
    printf("R1035 city encounter registry keys audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 7. roll: the city path, sweep + smoke -------------
    bad = 0;
    {
        rules::Rng rng(1035);
        rules::Dice dice(rng);
        int produced = 0;
        const auto companion = dm::cityEncounterKeys(reg);
        auto inCompanion = [&](const std::string& k) {
            for (const auto& c : companion)
                if (c == k) return true;
            return false;
        };
        auto isParty = [&](const std::string& k) {
            return k == "assassin" || k == "cleric" || k == "druid"
                || k == "fighter" || k == "illusionist"
                || k == "magic_user" || k == "monk"
                || k == "paladin" || k == "ranger" || k == "thief"
                || k == "rake" || k == "city_guard"
                || k == "city_official" || k == "city_watchman";
        };
        // count-path bounds (the printed numbers, code behavior)
        auto countInRange = [&](const std::string& k, int v,
                                bool night) -> bool {
            const auto* c = ereg.cityCount(k);
            if (!c) return v == 1;
            if (c->fixed >= 0) return v == c->fixed;
            int n = c->n, d = c->d, plus = c->plus;
            if (c->hasNight && night)
                { n = c->nN; d = c->dN; plus = c->plusN; }
            return v >= plus + n && v <= plus + n * d;
        };
        for (int nightI = 0; nightI < 2; ++nightI)
            for (int pct = 1; pct <= 100; ++pct) {
                const dm::CityTime t =
                    nightI ? dm::CITY_NIGHT : dm::CITY_DAY;
                const int p2 = 1 + (pct * 37) % 100;
                dm::DungeonEncounter e = dm::rollCityEncounter(
                    reg, dice, pct, p2, t);
                if (e.key.empty()) { ++bad; continue; }
                ++produced;
                if (!inCompanion(e.key)) ++bad;
                if (e.count < 1) ++bad;
                if (isParty(e.key)) {
                    if (!e.isParty) ++bad;
                    if ((int)e.party.members.size() != e.count)
                        ++bad;
                } else {
                    if (e.isParty) ++bad;
                    if (!countInRange(e.key, e.count,
                                     nightI == 1)) ++bad;
                }
            }
        // rng smoke: 4000 rolls, outcomes must be legal
        for (int i = 0; i < 4000; ++i) {
            const dm::CityTime t =
                (i % 2) ? dm::CITY_NIGHT : dm::CITY_DAY;
            dm::DungeonEncounter e = dm::rollCityEncounter(
                reg, dice, 1 + i % 100, 1 + (i * 53) % 100, t);
            if (e.key.empty()) { ++bad; continue; }
            if (!inCompanion(e.key)) ++bad;
            if (e.count < 1) ++bad;
            if (isParty(e.key) != e.isParty) ++bad;
        }
        if (produced < 180) ++bad;   // both sweeps resolve broadly
    }
    printf("R1035 city encounter registry roll audit: bad %d\n", bad);
    if (bad) return 1;

}
