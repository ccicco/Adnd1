// ============================================================================
// Adnd1 - rules/audits/r1038_castle_encounter_registry.h  (R1038)
// The R67 castle family battery audit, the R1032-R1037
// shape: the registry load, exact table counts and the
// percentile chains, derived row spot pins (incl. the
// corrected Assassin/Monk/Bard overlap), the per-size
// inhabitants mapping, the master's class and level, the
// artillery and awareness mapping, and the roll/patrol
// path. Expected: 7 castle files - CASTLE TABLE I (9
// rows), the three per-size TABLE II sub-tables (4 rows
// each), SUB-TABLE II.A (4 rows), SUB-TABLE II.B (11
// rows) and the ARTILLERY table (8 rows) - all derived
// from the DMG record (Premium reprint p.182-183) the
// splice parsed. The enums ride as printed tokens; the
// master/henchmen/patrol construction (R53/R55/R62) and
// the noAppearing fallback (R60) stay engine-side.
// ============================================================================
{
    int bad = 0;
    dm::EncounterTableRegistry ereg;

    // -- 1. load: 7 castle files, zero errors, one reg --
    bad = 0;
    {
        const int kf = ereg.loadDirectory(
            "content/tables/encounters_castle");
        if (kf != 7) ++bad;
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
        const int pf = ereg.loadDirectory(
            "content/tables/encounters_psionic");
        if (pf != 2) ++bad;
        if (!ereg.hasCastle("castle_type")) ++bad;
        if (!ereg.hasCastle("castle_inh_small")) ++bad;
        if (!ereg.hasCastle("castle_inh_medium")) ++bad;
        if (!ereg.hasCastle("castle_inh_large")) ++bad;
        if (!ereg.hasCastle("castle_humans")) ++bad;
        if (!ereg.hasCastle("castle_master")) ++bad;
        if (!ereg.hasCastle("castle_artillery")) ++bad;
        // negative pins (the R1034 dispatch-order lesson:
        // the exact keys stay exclusive on every side)
        if (ereg.hasCastle("")) ++bad;
        if (ereg.hasCastle("castle_picks")) ++bad;
        if (ereg.hasPlanar("castle_type")) ++bad;
        if (ereg.hasPlanarBands("castle_type")) ++bad;
        if (ereg.hasWater("castle_type")) ++bad;
        if (ereg.hasOutdoor("castle_type")) ++bad;
        if (ereg.hasCityBands("castle_type")) ++bad;
        // the earlier families still load clean
        if (!ereg.hasPlanar("psionic_table")) ++bad;
        if ((int)ereg.list("psionic_spell_exact").size()
            != 20) ++bad;
    }
    printf("R1038 castle encounter registry load audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 2. counts: rows and the printed columns --------
    bad = 0;
    {
        if ((int)ereg.castleRows("castle_type").size() != 9)
            ++bad;
        if ((int)ereg.castleRows("castle_inh_small").size()
            != 4) ++bad;
        if ((int)ereg.castleRows("castle_inh_medium").size()
            != 4) ++bad;
        if ((int)ereg.castleRows("castle_inh_large").size()
            != 4) ++bad;
        if ((int)ereg.castleRows("castle_humans").size()
            != 4) ++bad;
        if ((int)ereg.castleRows("castle_master").size()
            != 11) ++bad;
        if ((int)ereg.castleRows("castle_artillery").size()
            != 8) ++bad;
        // one row per percentile, per percentile table
        const char* const banded[6] = {
            "castle_type", "castle_inh_small",
            "castle_inh_medium", "castle_inh_large",
            "castle_humans", "castle_master" };
        for (int b = 0; b < 6; ++b) {
            const auto& rs = ereg.castleRows(banded[b]);
            int lo = 1;
            for (const auto& r : rs) {
                if (r.lo != lo) ++bad;          // contiguous
                if (r.hi < r.lo || r.hi > 100) ++bad;
                lo = r.hi + 1;
            }
            if (lo != 101) ++bad;                // 01-00
        }
        // the master's level ranges stay printed
        for (const auto& r :
             ereg.castleRows("castle_master"))
            if (r.lvlLo < 1 || r.lvlHi < r.lvlLo
                || r.lvlHi > 23) ++bad;
        // the artillery counts stay non-negative
        for (const auto& r :
             ereg.castleRows("castle_artillery"))
            if (r.n1 < 0 || r.n2 < 0 || r.n3 < 0) ++bad;
    }
    printf("R1038 castle encounter registry counts audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 3. pins: spot pins derived from the parsed record
    bad = 0;
    {
        const auto& rt = ereg.castleRows("castle_type");
        const auto& rm = ereg.castleRows("castle_master");
        const auto& rh = ereg.castleRows("castle_humans");
        const auto& ra = ereg.castleRows("castle_artillery");
        { const int i = 0; const auto& r = rt[i];
          if (r.lo != 1 || r.hi != 10) ++bad;
          if (r.size != "small") ++bad;
          if (r.type != "small shell keep") ++bad;
        }
        { const int i = 2; const auto& r = rt[i];
          if (r.lo != 26 || r.hi != 35) ++bad;
          if (r.size != "small") ++bad;
          if (r.type != "moat house or friary") ++bad;
        }
        { const int i = 6; const auto& r = rt[i];
          if (r.lo != 81 || r.hi != 88) ++bad;
          if (r.size != "large") ++bad;
          if (r.type != "concentric castle") ++bad;
        }
        { const int i = 8; const auto& r = rt[i];
          if (r.lo != 96 || r.hi != 100) ++bad;
          if (r.size != "large") ++bad;
          if (r.type != "fortress complex") ++bad;
        }
        { const int i = 8; const auto& r = rm[i];
          if (r.lo != 94 || r.hi != 96) ++bad;
          if (r.prof != "assassin") ++bad;
          if (r.lvlLo != 14 || r.lvlHi != 14) ++bad;
        }
        { const int i = 9; const auto& r = rm[i];
          if (r.lo != 97 || r.hi != 99) ++bad;
          if (r.prof != "monk_bard") ++bad;
          if (r.lvlLo != 9 || r.lvlHi != 12) ++bad;
        }
        { const int i = 10; const auto& r = rm[i];
          if (r.lo != 100 || r.hi != 100) ++bad;
          if (r.prof != "monk_bard") ++bad;
          if (r.lvlLo != 23 || r.lvlHi != 23) ++bad;
        }
        { const int i = 0; const auto& r = rm[i];
          if (r.lo != 1 || r.hi != 18) ++bad;
          if (r.prof != "cleric") ++bad;
          if (r.lvlLo != 9 || r.lvlHi != 12) ++bad;
        }
        { const int i = 5; const auto& r = rm[i];
          if (r.lo != 69 || r.hi != 80) ++bad;
          if (r.prof != "magic_user") ++bad;
          if (r.lvlLo != 11 || r.lvlHi != 14) ++bad;
        }
        { const int i = 0; const auto& r = rh[i];
          if (r.lo != 1 || r.hi != 25) ++bad;
          if (r.key != "bandit") ++bad;
        }
        { const int i = 1; const auto& r = rh[i];
          if (r.lo != 26 || r.hi != 85) ++bad;
          if (r.key != "bandit") ++bad;
        }
        { const int i = 2; const auto& r = rh[i];
          if (r.lo != 86 || r.hi != 97) ++bad;
          if (r.key != "berserker") ++bad;
        }
        { const int i = 3; const auto& r = rh[i];
          if (r.lo != 98 || r.hi != 100) ++bad;
          if (r.key != "dervish") ++bad;
        }
        { const auto& r = ra[0];
          if (r.type != "moat house or friary") ++bad;
          if (r.n1 != 2 || r.n2 != 0 || r.n3 != 1) ++bad; }
        { const auto& r = ra[2];
          if (r.type != "shell keep") ++bad;
          if (r.n1 != 0 || r.n2 != 1 || r.n3 != 2) ++bad; }
        { const auto& r = ra[7];
          if (r.type != "fortress complex") ++bad;
          if (r.n1 != 4 || r.n2 != 4 || r.n3 != 8) ++bad; }
    }
    printf("R1038 castle encounter registry pins audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 4. inhabitants: the per-size mapping -----------
    bad = 0;
    {
        if (dm::castleInhabitants(1, dm::CASTLE_SMALL) != dm::CASTLE_TOTALLY_DESERTED) ++bad;
        if (dm::castleInhabitants(45, dm::CASTLE_SMALL) != dm::CASTLE_TOTALLY_DESERTED) ++bad;
        if (dm::castleInhabitants(46, dm::CASTLE_SMALL) != dm::CASTLE_DESERTED_MONSTER) ++bad;
        if (dm::castleInhabitants(60, dm::CASTLE_SMALL) != dm::CASTLE_DESERTED_MONSTER) ++bad;
        if (dm::castleInhabitants(61, dm::CASTLE_SMALL) != dm::CASTLE_HUMANS) ++bad;
        if (dm::castleInhabitants(70, dm::CASTLE_SMALL) != dm::CASTLE_HUMANS) ++bad;
        if (dm::castleInhabitants(71, dm::CASTLE_SMALL) != dm::CASTLE_CHARACTER_TYPES) ++bad;
        if (dm::castleInhabitants(100, dm::CASTLE_SMALL) != dm::CASTLE_CHARACTER_TYPES) ++bad;
        if (dm::castleInhabitants(1, dm::CASTLE_MEDIUM) != dm::CASTLE_TOTALLY_DESERTED) ++bad;
        if (dm::castleInhabitants(30, dm::CASTLE_MEDIUM) != dm::CASTLE_TOTALLY_DESERTED) ++bad;
        if (dm::castleInhabitants(31, dm::CASTLE_MEDIUM) != dm::CASTLE_DESERTED_MONSTER) ++bad;
        if (dm::castleInhabitants(50, dm::CASTLE_MEDIUM) != dm::CASTLE_DESERTED_MONSTER) ++bad;
        if (dm::castleInhabitants(51, dm::CASTLE_MEDIUM) != dm::CASTLE_HUMANS) ++bad;
        if (dm::castleInhabitants(65, dm::CASTLE_MEDIUM) != dm::CASTLE_HUMANS) ++bad;
        if (dm::castleInhabitants(66, dm::CASTLE_MEDIUM) != dm::CASTLE_CHARACTER_TYPES) ++bad;
        if (dm::castleInhabitants(100, dm::CASTLE_MEDIUM) != dm::CASTLE_CHARACTER_TYPES) ++bad;
        if (dm::castleInhabitants(1, dm::CASTLE_LARGE) != dm::CASTLE_TOTALLY_DESERTED) ++bad;
        if (dm::castleInhabitants(15, dm::CASTLE_LARGE) != dm::CASTLE_TOTALLY_DESERTED) ++bad;
        if (dm::castleInhabitants(16, dm::CASTLE_LARGE) != dm::CASTLE_DESERTED_MONSTER) ++bad;
        if (dm::castleInhabitants(40, dm::CASTLE_LARGE) != dm::CASTLE_DESERTED_MONSTER) ++bad;
        if (dm::castleInhabitants(41, dm::CASTLE_LARGE) != dm::CASTLE_HUMANS) ++bad;
        if (dm::castleInhabitants(60, dm::CASTLE_LARGE) != dm::CASTLE_HUMANS) ++bad;
        if (dm::castleInhabitants(61, dm::CASTLE_LARGE) != dm::CASTLE_CHARACTER_TYPES) ++bad;
        if (dm::castleInhabitants(100, dm::CASTLE_LARGE) != dm::CASTLE_CHARACTER_TYPES) ++bad;
        // the defensive fallbacks (the retired defaults)
        if (dm::castleInhabitants(101,
                dm::CASTLE_SMALL)
            != dm::CASTLE_TOTALLY_DESERTED) ++bad;
    }
    printf("R1038 castle encounter registry inhabitants audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 5. master: class and level per the record ------
    bad = 0;
    {
        rules::Rng rng(1038);
        rules::Dice dice(rng);
        { dm::PartyMember m = dm::rollCastleMaster(dice, 1);
          if (m.level < 9 || m.level > 12) ++bad;
          if (m.classIndex != rules::CLASS_CLERIC) ++bad; }
        { dm::PartyMember m = dm::rollCastleMaster(dice, 19);
          if (m.level < 12 || m.level > 13) ++bad;
          if (m.classIndex != rules::CLASS_CLERIC) ++bad; }
        { dm::PartyMember m = dm::rollCastleMaster(dice, 21);
          if (m.level < 9 || m.level > 12) ++bad;
          if (m.classIndex != rules::CLASS_FIGHTER) ++bad; }
        { dm::PartyMember m = dm::rollCastleMaster(dice, 66);
          if (m.level < 9 || m.level > 10) ++bad;
          if (m.classIndex != rules::CLASS_FIGHTER) ++bad; }
        { dm::PartyMember m = dm::rollCastleMaster(dice, 67);
          if (m.level < 10 || m.level > 13) ++bad;
          if (m.classIndex != rules::CLASS_FIGHTER) ++bad; }
        { dm::PartyMember m = dm::rollCastleMaster(dice, 69);
          if (m.level < 11 || m.level > 14) ++bad;
          if (m.classIndex != rules::CLASS_MAGIC_USER) ++bad; }
        { dm::PartyMember m = dm::rollCastleMaster(dice, 81);
          if (m.level < 10 || m.level > 13) ++bad;
          if (m.classIndex != rules::CLASS_MAGIC_USER) ++bad; }
        { dm::PartyMember m = dm::rollCastleMaster(dice, 86);
          if (m.level < 10 || m.level > 14) ++bad;
          if (m.classIndex != rules::CLASS_THIEF) ++bad; }
        { dm::PartyMember m = dm::rollCastleMaster(dice, 94);
          if (m.level < 14 || m.level > 14) ++bad;
          if (m.classIndex != rules::CLASS_THIEF) ++bad; }
        { dm::PartyMember m = dm::rollCastleMaster(dice, 97);
          if (m.level < 9 || m.level > 12) ++bad;
          if (m.classIndex != rules::CLASS_THIEF) ++bad; }
        { dm::PartyMember m = dm::rollCastleMaster(dice, 100);
          if (m.level < 23 || m.level > 23) ++bad;
          if (m.classIndex != rules::CLASS_THIEF) ++bad; }
        // the OCR-corrected rows are the pins: assassin
        // 94-96 (level 14), monk 97-99 (9-12), bard 00
        // (level 23 exactly)
        { dm::PartyMember a = dm::rollCastleMaster(dice, 95);
          if (a.level != 14) ++bad;
          if (a.classIndex != rules::CLASS_THIEF) ++bad; }
        { dm::PartyMember m = dm::rollCastleMaster(dice, 98);
          if (m.level < 9 || m.level > 12) ++bad; }
        { dm::PartyMember b = dm::rollCastleMaster(dice, 100);
          if (b.level != 23) ++bad;
          if (b.classIndex != rules::CLASS_THIEF) ++bad; }
        // henchmen: 2-5, all flagged, the master's class
        { dm::PartyMember m = dm::rollCastleMaster(dice, 21);
          dm::CharacterParty h =
              dm::rollCastleHenchmen(dice, m);
          if ((int)h.members.size() < 2
              || (int)h.members.size() > 5) ++bad;
          for (const auto& x : h.members) {
              if (!x.henchman) ++bad;
              if (x.classIndex != m.classIndex) ++bad;
          } }
    }
    printf("R1038 castle encounter registry master audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 6. artillery + awareness -----------------------
    bad = 0;
    {
        { dm::CastleType t = dm::rollCastleType(1);
          dm::CastleArtillery a = dm::castleArtillery(t);
          if (a.ballistae != 0 || a.lightCatapults != 1 || a.oilCauldrons != 2) ++bad; }
        { dm::CastleType t = dm::rollCastleType(11);
          dm::CastleArtillery a = dm::castleArtillery(t);
          if (a.ballistae != 1 || a.lightCatapults != 0 || a.oilCauldrons != 1) ++bad; }
        { dm::CastleType t = dm::rollCastleType(26);
          dm::CastleArtillery a = dm::castleArtillery(t);
          if (a.ballistae != 2 || a.lightCatapults != 0 || a.oilCauldrons != 1) ++bad; }
        { dm::CastleType t = dm::rollCastleType(36);
          dm::CastleArtillery a = dm::castleArtillery(t);
          if (a.ballistae != 0 || a.lightCatapults != 1 || a.oilCauldrons != 2) ++bad; }
        { dm::CastleType t = dm::rollCastleType(46);
          dm::CastleArtillery a = dm::castleArtillery(t);
          if (a.ballistae != 1 || a.lightCatapults != 1 || a.oilCauldrons != 2) ++bad; }
        { dm::CastleType t = dm::rollCastleType(66);
          dm::CastleArtillery a = dm::castleArtillery(t);
          if (a.ballistae != 2 || a.lightCatapults != 2 || a.oilCauldrons != 5) ++bad; }
        { dm::CastleType t = dm::rollCastleType(81);
          dm::CastleArtillery a = dm::castleArtillery(t);
          if (a.ballistae != 4 || a.lightCatapults != 2 || a.oilCauldrons != 6) ++bad; }
        { dm::CastleType t = dm::rollCastleType(89);
          dm::CastleArtillery a = dm::castleArtillery(t);
          if (a.ballistae != 4 || a.lightCatapults != 4 || a.oilCauldrons != 8) ++bad; }
        { dm::CastleType t = dm::rollCastleType(96);
          dm::CastleArtillery a = dm::castleArtillery(t);
          if (a.ballistae != 4 || a.lightCatapults != 4 || a.oilCauldrons != 8) ++bad; }
        // the shell-keep fallback: both shell rows share
        // the "shell keep" artillery row (documented)
        { dm::CastleType t;
          t.size = dm::CASTLE_SMALL;
          t.type = "small shell keep";
          dm::CastleArtillery a = dm::castleArtillery(t);
          if (a.ballistae != 0 || a.lightCatapults != 1
              || a.oilCauldrons != 2) ++bad; }
        // an unknown type carries no artillery
        { dm::CastleType t;
          t.size = dm::CASTLE_LARGE;
          t.type = "windmill";
          dm::CastleArtillery a = dm::castleArtillery(t);
          if (a.ballistae != 0 || a.lightCatapults != 0
              || a.oilCauldrons != 0) ++bad; }
        // awareness: 1 = aware, 2 = outside, 3+ = undetected
        if (dm::castleAwareness(1) !=
            dm::CASTLE_OCCUPANTS_AWARE) ++bad;
        if (dm::castleAwareness(0) !=
            dm::CASTLE_OCCUPANTS_AWARE) ++bad;
        if (dm::castleAwareness(2) !=
            dm::CASTLE_OCCUPANTS_OUTSIDE) ++bad;
        if (dm::castleAwareness(3) !=
            dm::CASTLE_UNDETECTED) ++bad;
        if (dm::castleAwareness(6) !=
            dm::CASTLE_UNDETECTED) ++bad;
    }
    printf("R1038 castle encounter registry artillery audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 7. roll: the sweep + the patrol smoke ----------
    bad = 0;
    {
        rules::Rng rng(1038);
        rules::Dice dice(rng);
        // rollCastleType sweep: every percentile produces
        // the row that carries it
        for (const auto& r :
             ereg.castleRows("castle_type"))
            for (int pct = r.lo; pct <= r.hi; ++pct) {
                dm::CastleType t =
                    dm::rollCastleType(pct);
                if (std::string(t.type) != r.type) ++bad;
                if (t.size !=
                    (r.size == "small"
                     ? dm::CASTLE_SMALL
                     : (r.size == "medium"
                        ? dm::CASTLE_MEDIUM
                        : dm::CASTLE_LARGE))) ++bad;
            }
        // castleHumansType sweep: the three bestiary keys,
        // all resolvable in the registry
        for (const auto& r :
             ereg.castleRows("castle_humans"))
            for (int pct = r.lo; pct <= r.hi; ++pct) {
                const char* key =
                    dm::castleHumansType(pct);
                if (std::string(key) != r.key) ++bad;
                if (!reg.find(key)) ++bad;
            }
        // castleHumansCount: the registry noAppearing
        // range (the R60 convention), dynamic
        for (const auto& r :
             ereg.castleRows("castle_humans")) {
            const monsters::MonsterDef* def =
                reg.find(r.key);
            if (!def) { ++bad; continue; }
            for (int i = 0; i < 40; ++i) {
                const int c = dm::castleHumansCount(
                    reg, dice, r.key.c_str());
                if (def->noAppearingMin > 0) {
                    const int lo = def->noAppearingMin;
                    const int hi =
                        def->noAppearingMax < lo
                        ? lo : def->noAppearingMax;
                    if (c < lo || c > hi) ++bad;
                } else if (c != 1) ++bad;
            }
        }
        // rollPatrol smoke: the printed shape
        for (int i = 0; i < 200; ++i) {
            dm::CharacterParty p =
                dm::rollPatrol(dice, i % 2 != 0);
            const int n = (int)p.members.size();
            if (n < 20 || n > 34) ++bad;
            if (p.members[0].level < 6
                || p.members[0].level > 8) ++bad;
            if (p.members[0].classIndex
                != rules::CLASS_FIGHTER) ++bad;
            if (p.members[1].level < 4
                || p.members[1].level > 5) ++bad;
            if (p.members[2].level < 2
                || p.members[2].level > 3) ++bad;
            int men = 0;
            for (const auto& m : p.members)
                if (m.manAtArms) ++men;
            if (men < 16 || men > 28) ++bad;
        }
        // rollCastleMaster smoke: levels stay printed
        for (int i = 0; i < 2000; ++i) {
            dm::PartyMember m = dm::rollCastleMaster(
                dice, 1 + i % 100);
            if (m.level < 9 || m.level > 23) ++bad;
        }
    }
    printf("R1038 castle encounter registry roll audit: bad %d\n", bad);
    if (bad) return 1;

}
