// ============================================================================
// Adnd1 - rules/audits/r1037_psionic_encounter_registry.h  (R1037)
// The R66 psionic family battery audit, the R1032-R1036
// shape: the registry load, exact table counts, the percentile
// chain, row spot pins against the parsed R66 record, the
// printed spells lists, the key companion vs the table
// expansion, and the rollPsionicEncounter() path. Expected:
// 2 psionic files - the 19-row psionic table (band, key, the
// printed Numbers column, the shared planar row shape) and
// the spells file (20 exact names + 6 family prefixes) -
// all derived from the DMG record (Premium reprint p.182)
// the splice parsed. The demon/devil rows resolve through
// the R1036 pick-sets; kPrinces/kArchDevils stay
// engine-side (the R52 record); PSI_MEN resolves as a
// Character Subtable party (the R63 convention); the
// yellow mold dash falls back to the registry's
// noAppearing (the R60 convention).
// ============================================================================
{
    static const char* const kFragPrinces[4] = {
        "demogorgon",
        "juiblex",
        "orcus",
        "yeenoghu",
    };
    static const char* const kFragArchDevils[4] = {
        "asmodeus",
        "baalzebul",
        "dispater",
        "geryon",
    };

    int bad = 0;
    dm::EncounterTableRegistry ereg;

    // -- 1. load: 2 psionic files, zero errors, one reg --
    bad = 0;
    {
        const int pf = ereg.loadDirectory(
            "content/tables/encounters_psionic");
        if (pf != 2) ++bad;
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
        const int xf = ereg.loadDirectory(
            "content/tables/encounters_planar");
        if (xf != 5) ++bad;
        if (!ereg.hasPlanar("psionic_table")) ++bad;
        // the spells file rides m_lists, not m_planar
        if (ereg.hasPlanar("psionic_spells")) ++bad;
        // negative pins (the R1034 dispatch-order lesson:
        // the exact keys stay exclusive on every side)
        if (ereg.hasPlanar("")) ++bad;
        if (ereg.hasPlanarBands("psionic_table")) ++bad;
        if (ereg.hasPlanarBands("")) ++bad;
        if (ereg.hasCityBands("psionic_table")) ++bad;
        if (ereg.hasWater("psionic_table")) ++bad;
        if (ereg.hasOutdoor("psionic_table")) ++bad;
        if (ereg.hasPlanar("planar_picks")) ++bad;
        // the spells lists and the R1036 pick-sets
        if ((int)ereg.list("psionic_spell_exact").size()
            != 20) ++bad;
        if ((int)ereg.list("psionic_spell_family").size()
            != 6) ++bad;
        if (!ereg.list("psionic_spell_exact").empty()
            && ereg.list("psionic_spell_exact")[0]
               != "astral spell") ++bad;
        if ((int)ereg.list("demon_minor_set").size() != 6)
            ++bad;
        if ((int)ereg.list("demon_major_set").size() != 10)
            ++bad;
        if ((int)ereg.list("devil_greater_set").size() != 3)
            ++bad;
    }
    printf("R1037 psionic encounter registry load audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 2. counts: the 19 rows, the printed columns ------
    bad = 0;
    {
        const auto& rs = ereg.planarRows("psionic_table");
        if ((int)rs.size() != 19) ++bad;
        int lo = 1;
        for (const auto& r : rs) {
            if (r.lo != lo) ++bad;             // contiguous
            if (r.hi < r.lo || r.hi > 100) ++bad;
            if (r.nMin < 0 || r.nMax < r.nMin
                || r.nMax > 100) ++bad;
            if (r.primeOnly) ++bad;   // no (*) footnote here
            lo = r.hi + 1;
        }
        if (lo != 101) ++bad;                   // covers 01-00
    }
    printf("R1037 psionic encounter registry counts audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 3. chains: one row per percentile ---------------
    bad = 0;
    {
        const auto& rs = ereg.planarRows("psionic_table");
        for (int pct = 1; pct <= 100; ++pct) {
            int hits = 0;
            for (const auto& r : rs)
                if (pct >= r.lo && pct <= r.hi) ++hits;
            if (hits != 1) ++bad;
        }
        // the printed Numbers column never exceeds the band
        for (const auto& r : rs) {
            if (r.nMin == 0 && r.nMax == 0) continue;
            if (r.nMin < 1) ++bad;
        }
    }
    printf("R1037 psionic encounter registry chains audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 4. pins: spot pins derived from the parsed record -
    bad = 0;
    {
        const auto& rs = ereg.planarRows("psionic_table");
        { const int i = 0; const auto& r = rs[i];
          if (r.lo != 1 || r.hi != 5)
              ++bad;
          if (r.key != "brain_mole") ++bad;
          if (r.nMin != 1 || r.nMax != 3)
              ++bad;
          if (r.primeOnly) ++bad; }
        { const int i = 5; const auto& r = rs[i];
          if (r.lo != 25 || r.hi != 26)
              ++bad;
          if (r.key != "PSI_DEMON_PRINCE") ++bad;
          if (r.nMin != 1 || r.nMax != 1)
              ++bad;
          if (r.primeOnly) ++bad; }
        { const int i = 12; const auto& r = rs[i];
          if (r.lo != 57 || r.hi != 62)
              ++bad;
          if (r.key != "PSI_MEN") ++bad;
          if (r.nMin != 0 || r.nMax != 0)
              ++bad;
          if (r.primeOnly) ++bad; }
        { const int i = 14; const auto& r = rs[i];
          if (r.lo != 70 || r.hi != 72)
              ++bad;
          if (r.key != "yellow_mold") ++bad;
          if (r.nMin != 0 || r.nMax != 0)
              ++bad;
          if (r.primeOnly) ++bad; }
        { const int i = 18; const auto& r = rs[i];
          if (r.lo != 99 || r.hi != 100)
              ++bad;
          if (r.key != "triton") ++bad;
          if (r.nMin != 10 || r.nMax != 60)
              ++bad;
          if (r.primeOnly) ++bad; }
    }
    printf("R1037 psionic encounter registry pins audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 5. spells: the printed lists, case-insensitive ---
    bad = 0;
    {
        // exact positives (the case-insensitivity pin:
        // the battery feeds mixed case at the engine)
        if (!dm::spellResemblesPsionicPower("feather fall"))
            ++bad;
        if (!dm::spellResemblesPsionicPower(
                "FEATHER FALL")) ++bad;
        if (!dm::spellResemblesPsionicPower(
                "Temporal Stasis")) ++bad;
        if (!dm::spellResemblesPsionicPower(
                "astral spell")) ++bad;
        if (!dm::spellResemblesPsionicPower("esp"))
            ++bad;
        // family positives (the printed "(any)" leading
        // words)
        if (!dm::spellResemblesPsionicPower(
                "charm person")) ++bad;
        if (!dm::spellResemblesPsionicPower(
                "cure light wounds")) ++bad;
        if (!dm::spellResemblesPsionicPower(
                "detect magic")) ++bad;
        if (!dm::spellResemblesPsionicPower(
                "invisibility 10' radius")) ++bad;
        if (!dm::spellResemblesPsionicPower(
                "polymorph self")) ++bad;
        if (!dm::spellResemblesPsionicPower(
                "teleport")) ++bad;
        // negatives (near-misses and unrelated classics)
        if (dm::spellResemblesPsionicPower(
                "fireball")) ++bad;
        if (dm::spellResemblesPsionicPower(
                "magic missile")) ++bad;
        if (dm::spellResemblesPsionicPower(
                "lightning bolt")) ++bad;
        if (dm::spellResemblesPsionicPower(
                "sleep")) ++bad;
        if (dm::spellResemblesPsionicPower(
                "web")) ++bad;
        if (dm::spellResemblesPsionicPower(
                "shield")) ++bad;
        if (dm::spellResemblesPsionicPower(
                "healing")) ++bad;      // heal, not healing
        if (dm::spellResemblesPsionicPower(
                "curing")) ++bad;      // cure family needs
                                        // the full prefix
        if (dm::spellResemblesPsionicPower("")) ++bad;
        if (dm::spellResemblesPsionicPower(
                "feather")) ++bad;     // not the exact name
    }
    printf("R1037 psionic encounter registry spells audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 6. keys: the companion vs the expansion ----------
    bad = 0;
    {
        const auto got = dm::psionicEncounterKeys(reg);
        std::vector<std::string> want;
        auto pushU = [&](const std::string& k) {
            for (const auto& w : want)
                if (w == k) return;
            want.push_back(k);
        };
        const auto& rs = ereg.planarRows("psionic_table");
        for (const auto& r : rs) {
            const std::string& k = r.key;
            if      (k == "PSI_DEMON_MAJOR")
                for (const auto& x :
                     ereg.list("demon_major_set"))
                    pushU(x);
            else if (k == "PSI_DEMON_MINOR")
                for (const auto& x :
                     ereg.list("demon_minor_set"))
                    pushU(x);
            else if (k == "PSI_DEMON_PRINCE")
                for (const char* x : kFragPrinces)
                    pushU(x);
            else if (k == "PSI_DEVIL_ARCH")
                for (const char* x : kFragArchDevils)
                    pushU(x);
            else if (k == "PSI_DEVIL_GREATER")
                for (const auto& x :
                     ereg.list("devil_greater_set"))
                    pushU(x);
            else if (k == "PSI_MEN")
                pushU("character_party");
            else
                pushU(k);
        }
        // both directions, then the size pin (the derived
        // companion: 13 plain + 27 picks/princes/arch + party)
        if (got.size() != want.size()) ++bad;
        if ((int)got.size() != 41) ++bad;
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
        // structural pins (grepped, never recalled)
        if (!has("character_party")) ++bad;
        if (!has("demogorgon")) ++bad;
        if (!has("asmodeus")) ++bad;
        if (!has("type_vi_demon_balor")) ++bad;
        if (!has("pit_fiend")) ++bad;
        if (!has("brain_mole")) ++bad;
        if (!has("triton")) ++bad;
        if (!has("yellow_mold")) ++bad;
        // no pseudo-key leaks into the companion
        for (const auto& g : got)
            if (g.compare(0, 4, "PSI_") == 0) ++bad;
    }
    printf("R1037 psionic encounter registry keys audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 7. roll: the psionic path, sweep + smoke ---------
    bad = 0;
    {
        rules::Rng rng(1037);
        rules::Dice dice(rng);
        // expanded key -> the printed numbers range (the
        // map is keyed by EXPANDED keys - the R1036 lesson)
        std::map<std::string, std::pair<int,int>> nums;
        {
            const auto& rs =
                ereg.planarRows("psionic_table");
            for (const auto& r : rs) {
                std::vector<std::string> kk;
                const std::string& k = r.key;
                if      (k == "PSI_DEMON_MAJOR")
                    kk = ereg.list("demon_major_set");
                else if (k == "PSI_DEMON_MINOR")
                    kk = ereg.list("demon_minor_set");
                else if (k == "PSI_DEMON_PRINCE")
                    for (const char* x : kFragPrinces)
                        kk.push_back(x);
                else if (k == "PSI_DEVIL_ARCH")
                    for (const char* x : kFragArchDevils)
                        kk.push_back(x);
                else if (k == "PSI_DEVIL_GREATER")
                    kk = ereg.list("devil_greater_set");
                else
                    kk.push_back(k);
                for (const auto& x : kk) {
                    if (x == "PSI_MEN"
                        || x == "yellow_mold") continue;
                    auto& p = nums[x];
                    if (r.nMax > p.second)
                        p = { r.nMin, r.nMax };
                }
            }
        }
        const auto companion = dm::psionicEncounterKeys(reg);
        auto inCompanion = [&](const std::string& k) {
            for (const auto& c : companion)
                if (c == k) return true;
            return false;
        };
        const monsters::MonsterDef* ym =
            reg.find("yellow_mold");
        for (int pct = 1; pct <= 100; ++pct) {
            const int p2 = 1 + (pct * 37) % 100;
            dm::DungeonEncounter e =
                dm::rollPsionicEncounter(reg, dice, pct, p2);
            if (e.key.empty()) { ++bad; continue; }
            if (!inCompanion(e.key)) ++bad;
            if (e.key == "character_party") {
                if (!e.isParty) ++bad;
                if ((int)e.party.members.size() != e.count)
                    ++bad;
            } else if (e.key == "yellow_mold") {
                if (e.isParty) ++bad;
                // the printed dash: the registry's
                // noAppearing (0/0 -> single patch)
                if (ym && ym->noAppearingMin > 0) {
                    const int lo = ym->noAppearingMin;
                    const int hi = ym->noAppearingMax < lo
                        ? lo : ym->noAppearingMax;
                    if (e.count < lo || e.count > hi)
                        ++bad;
                } else if (e.count != 1) ++bad;
            } else {
                if (e.isParty) ++bad;
                const auto it = nums.find(e.key);
                if (it == nums.end()) ++bad;
                else if (e.count < it->second.first
                      || e.count > it->second.second)
                    ++bad;
            }
        }
        // rng smoke: 4000 rolls, outcomes must be legal
        for (int i = 0; i < 4000; ++i) {
            dm::DungeonEncounter e = dm::rollPsionicEncounter(
                reg, dice, 1 + i % 100, 1 + (i * 53) % 100);
            if (e.key.empty()) { ++bad; continue; }
            if (e.key == "character_party") {
                if (!e.isParty) ++bad;
                if ((int)e.party.members.size() != e.count)
                    ++bad;
            } else if (e.key == "yellow_mold") {
                if (e.isParty) ++bad;
                if (e.count < 1) ++bad;
            } else {
                if (e.isParty) ++bad;
                if (e.count < 1) ++bad;
            }
        }
    }
    printf("R1037 psionic encounter registry roll audit: bad %d\n", bad);
    if (bad) return 1;

}
