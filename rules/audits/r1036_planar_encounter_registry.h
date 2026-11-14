// ============================================================================
// Adnd1 - rules/audits/r1036_planar_encounter_registry.h  (R1036)
// The R65 astral/ethereal planar family battery audit, the
// R1032-R1035 shape: the registry load, exact table counts,
// band coverage, row/pick/band spot pins against the
// print-fidelity record, the wind/cyclone engine parity,
// the key companion vs the table expansion, and the
// rollPlanarEncounter() path. Expected: 5 planar files -
// the 24-row astral and 27-row ethereal tables (band,
// key, the printed Numbers column, the (*) footnote flag),
// the 7 pick-sets (6/10/3/4/2/2/2),
// and the wind/cyclone d20 band tables - all from the
// R65 record (Premium reprint p.181) the splice parsed.
// The demon-prince/arch-devil pools are engine-side (the
// R52 record); the (*) footnote creatures are listed in
// the companion regardless (R60 precedent) and gated on
// primeAdjacent at roll time.
// ============================================================================
{

    static const char* const kPlanarTables[2] = {
        "planar_astral", "planar_ethereal" };
    static const char* const kPlanarSets[7] = {
        "demon_minor_set", "demon_major_set", "devil_greater_set",
        "devil_lesser_set", "titan_elder_set", "titan_lesser_set",
        "titan_major_set" };
    static const int kPlanarSetSizes[7] = { 6, 10, 3, 4, 2, 2, 2 };
    static const char* const kPlanarBands[2] = {
        "planar_wind", "planar_cyclone" };
    static const char* const kFragPrinces[4] = {
        "demogorgon", "juiblex", "orcus", "yeenoghu" };
    static const char* const kFragArchDevils[4] = {
        "asmodeus", "baalzebul", "dispater", "geryon" };

    int bad = 0;
    dm::EncounterTableRegistry ereg;

    // -- 1. load: 5 planar files, zero errors, one reg --
    bad = 0;
    {
        const int pf = ereg.loadDirectory(
            "content/tables/encounters_planar");
        if (pf != 5) ++bad;
        if (!ereg.errors().empty()) ++bad;
        const int df = ereg.loadDirectory(
            "content/tables/encounters");
        if (df != 20) ++bad;
        const int wf = ereg.loadDirectory(
            "content/tables/encounters_water");
        if (wf != 9) ++bad;
        const int of = ereg.loadDirectory(
            "content/tables/encounters_outdoor");
        if (of != 21) ++bad;
        const int cf = ereg.loadDirectory(
            "content/tables/encounters_city");
        if (cf != 9) ++bad;
        if (!ereg.hasPlanar("planar_astral")) ++bad;
        if (!ereg.hasPlanar("planar_ethereal")) ++bad;
        if (!ereg.hasPlanarBands("planar_wind")) ++bad;
        if (!ereg.hasPlanarBands("planar_cyclone")) ++bad;
        // negative pins (the R1034 dispatch-order lesson:
        // the exact keys stay exclusive on every side)
        if (ereg.hasPlanar("planar_picks")) ++bad;
        if (ereg.hasPlanar("planar_wind")) ++bad;   // band file
        if (ereg.hasPlanarBands("planar_astral")) ++bad;
        if (ereg.hasPlanar("city_matrix")) ++bad;
        if (ereg.hasPlanar("outdoor_sets")) ++bad;
        if (ereg.hasCityBands("planar_wind")) ++bad;
        if (ereg.hasOutdoor("planar_astral")) ++bad;
        if (ereg.hasWater("planar_ethereal")) ++bad;
        if (ereg.hasPlanar("")) ++bad;
        if (ereg.hasPlanarBands("")) ++bad;
        // the pick-set lists rode m_lists
        if ((int)ereg.list("demon_minor_set").size() != 6) ++bad;
        if ((int)ereg.list("demon_major_set").size() != 10) ++bad;
    }
    printf("R1036 planar encounter registry load audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 2. counts: rows, sets, bands ---------------------
    bad = 0;
    {
        if ((int)ereg.planarRows("planar_astral").size() != 24) ++bad;
        if ((int)ereg.planarRows("planar_ethereal").size() != 27) ++bad;
        for (int i = 0; i < 7; ++i) {
            const int n = (int)ereg.list(kPlanarSets[i]).size();
            if (n != kPlanarSetSizes[i]) ++bad;
        }
        if ((int)ereg.planarBands("planar_wind").size() != 4) ++bad;
        if ((int)ereg.planarBands("planar_cyclone").size() != 4) ++bad;
        // the absent-table contract: empty, never a crash
        if (!ereg.planarRows("planar_picks").empty()) ++bad;
        if (!ereg.planarBands("planar_astral").empty()) ++bad;
    }
    printf("R1036 planar encounter registry counts audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 3. bands: percentile and d20 chains -------------
    bad = 0;
    {
        for (int t = 0; t < 2; ++t) {
            int prev = 0;
            for (const auto& r : ereg.planarRows(kPlanarTables[t])) {
                if (r.lo != prev + 1 || r.hi < r.lo
                    || r.hi > 100) ++bad;
                prev = r.hi;
            }
            if (prev != 100) ++bad;
        }
        for (int b = 0; b < 2; ++b) {
            int prev = 0;
            for (const auto& r : ereg.planarBands(kPlanarBands[b])) {
                if (r.lo != prev + 1 || r.hi < r.lo
                    || r.hi > 20) ++bad;
                prev = r.hi;
            }
            if (prev != 20) ++bad;
        }
    }
    printf("R1036 planar encounter registry bands audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 4. pins: rows, picks, wind/cyclone bands ---------
    bad = 0;
    {
        const auto& ma = ereg.planarRows("planar_astral");
        const auto& me = ereg.planarRows("planar_ethereal");
        if (ma[0].key != "aerial_servant" || ma[0].lo != 1
            || ma[0].hi != 4 || ma[0].nMin != 1
            || ma[0].nMax != 1 || ma[0].primeOnly)
            ++bad;
        if (ma[1].key != "basilisk" || !ma[1].primeOnly) ++bad;
        if (ma[23].key != "PLANAR_TITAN_MAJOR") ++bad;
        if (ma[23].lo != 98 || ma[23].hi != 100
            || ma[23].nMin != 1 || ma[23].nMax != 1) ++bad;
        if (me[0].key != "aerial_servant" || me[0].lo != 1
            || me[0].hi != 5 || me[0].primeOnly)
            ++bad;
        if (me[3].key != "couatl" || me[3].lo != 14
            || me[3].hi != 18 || me[3].nMin != 1
            || me[3].nMax != 4 || me[3].primeOnly) ++bad;
        if (me[26].key != "xorn" || me[26].lo != 98
            || me[26].hi != 100 || me[26].nMin != 3
            || me[26].nMax != 6) ++bad;
        // the pick sets (verbatim members, first/last spot)
        const auto& dminor = ereg.list("demon_minor_set");
        if (dminor.empty() || dminor.front() != "type_i_vrock") ++bad;
        if (dminor.back() != "type_iv_demon_nalfeshnee") ++bad;
        const auto& dmaj = ereg.list("demon_major_set");
        if (dmaj.empty() || dmaj.front() != "type_v_demon_aishapra") ++bad;
        if (dmaj.back() != "type_vi_demon_wendonai") ++bad;
        const auto& telder = ereg.list("titan_elder_set");
        if (telder.size() != 2 || telder.front() != "elder_titan_ac_2") ++bad;
        if (telder.back() != "elder_titan_ac_3") ++bad;
        const auto& dgreater = ereg.list("devil_greater_set");
        if (dgreater.size() != 3 || dgreater.front() != "horned_devil") ++bad;
        // the wind/cyclone bands (d20, printed day ranges)
        const auto& wb = ereg.planarBands("planar_wind");
        if (wb[0].lo != 1 || wb[0].hi != 12) ++bad;
        if (wb[0].effect != "slowed" || wb[0].dMin != -1) ++bad;
        if (wb[3].lo != 20 || wb[3].hi != 20) ++bad;
        if (wb[3].effect != "storm" || wb[3].dMin != 4
            || wb[3].dMax != 40) ++bad;
        const auto& cb = ereg.planarBands("planar_cyclone");
        if (cb[0].lo != 1 || cb[0].hi != 10) ++bad;
        if (cb[0].effect != "blown_about" || cb[0].dMin != -1) ++bad;
        if (cb[2].lo != 16 || cb[2].hi != 18) ++bad;
        if (cb[2].effect != "lost_new_plane" || cb[2].dMin != 5
            || cb[2].dMax != 60) ++bad;
        if (cb[3].effect != "storm_astral" || cb[3].dMin != 10
            || cb[3].dMax != 120) ++bad;
    }
    printf("R1036 planar encounter registry pins audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 5. parity: the wind/cyclone engine vs the bands -
    bad = 0;
    {
        rules::Rng rng(1036);
        rules::Dice dice(rng);
        for (int d20 = 1; d20 <= 20; ++d20)
            for (int s = 0; s < 2; ++s) {
                const bool save = s != 0;
                dm::PsychicWindResult w =
                    dm::rollPsychicWind(dice, d20, save);
                const dm::EncounterPlanarBand* b = nullptr;
                for (const auto& cand : ereg.planarBands("planar_wind"))
                    if (d20 >= cand.lo && d20 <= cand.hi)
                        { b = &cand; break; }
                if (!b) { ++bad; continue; }
                if (b->effect == "slowed") {
                    if (w.effect != dm::PsychicWindEffect::Slowed
                        || w.days != 0 || w.cordBroken) ++bad;
                } else if (b->effect == "lost_return") {
                    if (w.effect != dm::PsychicWindEffect::LostReturn
                        || w.days < b->dMin || w.days > b->dMax
                        || w.cordBroken) ++bad;
                } else if (b->effect == "off_course") {
                    if (w.effect != dm::PsychicWindEffect::OffCourse
                        || w.days != 0 || w.cordBroken) ++bad;
                } else {
                    if (w.effect != dm::PsychicWindEffect::Storm)
                        ++bad;
                    if (save) {
                        if (w.days < b->dMin || w.days > b->dMax
                            || w.cordBroken) ++bad;
                    } else {
                        if (!w.cordBroken) ++bad;
                    }
                }
                dm::EtherCycloneResult c =
                    dm::rollEtherCyclone(dice, d20, save);
                const dm::EncounterPlanarBand* cb = nullptr;
                for (const auto& cand :
                     ereg.planarBands("planar_cyclone"))
                    if (d20 >= cand.lo && d20 <= cand.hi)
                        { cb = &cand; break; }
                if (!cb) { ++bad; continue; }
                if (cb->effect == "blown_about") {
                    if (c.effect != dm::EtherCycloneEffect::BlownAbout
                        || c.days != 0 || c.blownToAstral) ++bad;
                } else if (cb->effect == "different_plane") {
                    if (c.effect !=
                            dm::EtherCycloneEffect::DifferentPlane
                        || c.days != 0 || c.blownToAstral) ++bad;
                } else if (cb->effect == "lost_new_plane") {
                    if (c.effect != dm::EtherCycloneEffect::LostNewPlane
                        || c.days < cb->dMin
                        || c.days > cb->dMax
                        || c.blownToAstral) ++bad;
                } else {
                    if (c.effect !=
                            dm::EtherCycloneEffect::StormAstral)
                        ++bad;
                    if (c.days < cb->dMin || c.days > cb->dMax)
                        ++bad;
                    if (c.blownToAstral == save) ++bad;
                }
            }
    }
    printf("R1036 planar encounter registry parity audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 6. keys: the companion vs the table expansion ---
    bad = 0;
    {
        for (int t = 0; t < 2; ++t) {
            const auto got = dm::planarEncounterKeys(
                reg, t ? dm::PB_ETHEREAL : dm::PB_ASTRAL);
            std::vector<std::string> want;
            auto pushU = [&](const std::string& k) {
                for (const auto& w : want)
                    if (w == k) return;
                want.push_back(k);
            };
            for (const auto& r : ereg.planarRows(kPlanarTables[t])) {
                const std::string k = r.key;
                if (k == "PLANAR_DEMON_MINOR") {
                    for (const auto& s : ereg.list("demon_minor_set"))
                        pushU(s);
                    continue;
                }
                if (k == "PLANAR_DEMON_MAJOR") {
                    for (const auto& s : ereg.list("demon_major_set"))
                        pushU(s);
                    continue;
                }
                if (k == "PLANAR_DEMON_PRINCE") {
                    for (const char* s : kFragPrinces) pushU(s);
                    continue;
                }
                if (k == "PLANAR_DEVIL_ARCH") {
                    for (const char* s : kFragArchDevils)
                        pushU(s);
                    continue;
                }
                if (k == "PLANAR_DEVIL_GREATER") {
                    for (const auto& s :
                         ereg.list("devil_greater_set"))
                        pushU(s);
                    continue;
                }
                if (k == "PLANAR_DEVIL_LESSER") {
                    for (const auto& s :
                         ereg.list("devil_lesser_set"))
                        pushU(s);
                    continue;
                }
                if (k == "PLANAR_TITAN_ELDER"
                    || k == "PLANAR_TITAN_LESSER"
                    || k == "PLANAR_TITAN_MAJOR") {
                    const std::string set =
                        k == "PLANAR_TITAN_ELDER"
                        ? "titan_elder_set"
                        : k == "PLANAR_TITAN_LESSER"
                        ? "titan_lesser_set" : "titan_major_set";
                    for (const auto& s : ereg.list(set)) pushU(s);
                    continue;
                }
                if (k == "PLANAR_TRAVELLER") {
                    pushU("planar_traveller_party");
                    continue;
                }
                if (reg.find(k)) pushU(k);
            }
            // both directions, then the structural pins
            if (got.size() != want.size()) ++bad;
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
            auto has = [&](const char* k) {
                for (const auto& g : got)
                    if (g == k) return true;
                return false;
            };
            if (!has("planar_traveller_party")) ++bad;
            if (t == 0) {
                // the astral-only structural pins (the
                // ethereal table carries no demon/devil/
                // titan rows - table-scoped, not global)
                if (!has("type_vi_demon_balor")) ++bad;
                if (!has("pit_fiend")) ++bad;
                if (!has("demogorgon")) ++bad;
                if (!has("asmodeus")) ++bad;
                if (!has("elder_titan_ac_2")) ++bad;
                if (!has("major_titan_ac_1")) ++bad;
                // R60 precedent: the (*) footnote creatures
                // are listed regardless, gated at roll time
                if (!has("basilisk") || !has("cockatrice")
                    || !has("gorgon") || !has("medusa")) ++bad;
                if (!has("shedu")) ++bad;
                if ((int)got.size() < 40) ++bad;
            } else {
                if (!has("xorn") || !has("wind_walker")) ++bad;
                if (!has("couatl")) ++bad;
                if ((int)got.size() < 25) ++bad;
            }
        }
    }
    printf("R1036 planar encounter registry keys audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 7. roll: the planar path, sweep + smoke ---------
    bad = 0;
    {
        rules::Rng rng(1036);
        rules::Dice dice(rng);
        // expanded key -> the widest printed numbers range
        std::map<std::string, std::pair<int,int>> nums;
        for (int t = 0; t < 2; ++t)
            for (const auto& r :
                 ereg.planarRows(kPlanarTables[t])) {
                std::vector<std::string> kk;
                const std::string& k = r.key;
                if      (k == "PLANAR_DEMON_MINOR")
                    kk = ereg.list("demon_minor_set");
                else if (k == "PLANAR_DEMON_MAJOR")
                    kk = ereg.list("demon_major_set");
                else if (k == "PLANAR_DEMON_PRINCE")
                    for (const char* x : kFragPrinces)
                        kk.push_back(x);
                else if (k == "PLANAR_DEVIL_ARCH")
                    for (const char* x : kFragArchDevils)
                        kk.push_back(x);
                else if (k == "PLANAR_DEVIL_GREATER")
                    kk = ereg.list("devil_greater_set");
                else if (k == "PLANAR_DEVIL_LESSER")
                    kk = ereg.list("devil_lesser_set");
                else if (k == "PLANAR_TITAN_ELDER")
                    kk = ereg.list("titan_elder_set");
                else if (k == "PLANAR_TITAN_LESSER")
                    kk = ereg.list("titan_lesser_set");
                else if (k == "PLANAR_TITAN_MAJOR")
                    kk = ereg.list("titan_major_set");
                else if (k != "PLANAR_TRAVELLER")
                    kk.push_back(k);
                for (const auto& x : kk) {
                    auto& p = nums[x];
                    if (r.nMax > p.second)
                        p = { r.nMin, r.nMax };
                }
            }
        for (int t = 0; t < 2; ++t) {
            const auto companion = dm::planarEncounterKeys(
                reg, t ? dm::PB_ETHEREAL : dm::PB_ASTRAL);
            auto inCompanion = [&](const std::string& k) {
                for (const auto& c : companion)
                    if (c == k) return true;
                return false;
            };
            for (int primeI = 0; primeI < 2; ++primeI)
                for (int pct = 1; pct <= 100; ++pct) {
                    const int p2 = 1 + (pct * 37) % 100;
                    dm::DungeonEncounter e =
                        dm::rollPlanarEncounter(
                            reg, dice, pct, p2,
                            t ? dm::PB_ETHEREAL : dm::PB_ASTRAL,
                            primeI != 0);
                    if (e.key.empty()) { ++bad; continue; }
                    if (!inCompanion(e.key)) ++bad;
                    if (e.key == "planar_traveller_party") {
                        if (!e.isParty) ++bad;
                        if ((int)e.party.members.size()
                            != e.count) ++bad;
                        if (e.count < 1 || e.count > 6) ++bad;
                    } else {
                        if (e.isParty) ++bad;
                        const auto it = nums.find(e.key);
                        if (it == nums.end()) ++bad;
                        else if (e.count < it->second.first
                              || e.count > it->second.second)
                            ++bad;
                    }
                    if (!primeI) {
                        // the (*) footnote: never produced
                        // when no prime-material effect
                        if (e.key == "basilisk"
                            || e.key == "cockatrice"
                            || e.key == "gorgon"
                            || e.key == "medusa") ++bad;
                    }
                }
        }
        // rng smoke: 4000 rolls, outcomes must be legal
        for (int i = 0; i < 4000; ++i) {
            dm::DungeonEncounter e = dm::rollPlanarEncounter(
                reg, dice, 1 + i % 100, 1 + (i * 53) % 100,
                (i % 2) ? dm::PB_ETHEREAL : dm::PB_ASTRAL,
                (i % 3) != 0);
            if (e.key.empty()) { ++bad; continue; }
            if (e.key == "planar_traveller_party") {
                if (!e.isParty) ++bad;
                if ((int)e.party.members.size() != e.count)
                    ++bad;
                if (e.count < 1 || e.count > 6) ++bad;
            } else {
                if (e.isParty) ++bad;
                if (e.count < 1) ++bad;
            }
        }
    }
    printf("R1036 planar encounter registry roll audit: bad %d\n", bad);
    if (bad) return 1;

}
