// ============================================================================
// Adnd1 - rules/audits/r1039_party_encounter_registry.h  (R1039)
// The R53/R55 party family battery audit, the R1032-R1038
// shape: the registry load, exact table counts and the
// percentile/level/die chains, the full Character Subtable
// pins (bands, profession tokens, per-party maxima), the
// full 13-row level-chance ladder, the full four item
// tables (every die face), the rollCharacterParty semantics
// (men-at-arms vs henchmen, level caps, plus bounds), and
// the cross-region callers (the R1038 castle master and
// patrol still ride the retired tables through
// rollMagicItemsFor). Expected: 6 party files - the
// Character Subtable (10 rows), the level-chance ladder (13
// rows) and MAGIC ITEM TABLES I-IV (20/16/16/12 rows) - all
// derived from the DMG record (Premium reprint p.176-177)
// the splice parsed. The enums ride as printed tokens; the
// class/level/henchman mechanics and the half-dice reading
// stay engine-side.
// ============================================================================
{
    int bad = 0;
    dm::EncounterTableRegistry ereg;

    // -- 1. load: 6 party files, zero errors, one reg --
    bad = 0;
    {
        const int nf = ereg.loadDirectory(
            "content/tables/encounters_party");
        if (nf != 6) ++bad;
        if (!ereg.errors().empty()) ++bad;
        const int kf = ereg.loadDirectory(
            "content/tables/encounters_castle");
        if (kf != 7) ++bad;
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
        if (!ereg.hasParty("character_subtable")) ++bad;
        if (!ereg.hasParty("magic_ladder")) ++bad;
        if (!ereg.hasParty("magic_table_1")) ++bad;
        if (!ereg.hasParty("magic_table_2")) ++bad;
        if (!ereg.hasParty("magic_table_3")) ++bad;
        if (!ereg.hasParty("magic_table_4")) ++bad;
        // negative pins (the R1034 dispatch-order lesson:
        // every negative names a key ABSENT from that map -
        // the R1038 phantom-pin lesson)
        if (ereg.hasParty("")) ++bad;
        if (ereg.hasParty("castle_type")) ++bad;
        if (ereg.hasParty("magic_table_5")) ++bad;
        if (ereg.hasCastle("character_subtable")) ++bad;
        if (ereg.hasPlanar("character_subtable")) ++bad;
        if (ereg.hasPlanarBands("character_subtable")) ++bad;
        if (ereg.hasWater("character_subtable")) ++bad;
        if (ereg.hasOutdoor("character_subtable")) ++bad;
        if (ereg.hasCityBands("character_subtable")) ++bad;
        // the earlier families still load clean
        if (!ereg.hasCastle("castle_master")) ++bad;
        if (!ereg.hasPlanar("psionic_table")) ++bad;
        if ((int)ereg.list("psionic_spell_exact").size()
            != 20) ++bad;
    }
    printf("R1039 party encounter registry load audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 2. counts: rows and the printed chains ----------
    bad = 0;
    {
        if ((int)ereg.partyRows("character_subtable").size()
            != 10) ++bad;
        if ((int)ereg.partyRows("magic_ladder").size()
            != 13) ++bad;
        if ((int)ereg.partyRows("magic_table_1").size()
            != 20) ++bad;
        if ((int)ereg.partyRows("magic_table_2").size()
            != 16) ++bad;
        if ((int)ereg.partyRows("magic_table_3").size()
            != 16) ++bad;
        if ((int)ereg.partyRows("magic_table_4").size()
            != 12) ++bad;
        // the subtable bands chain 01-00
        {
            const auto& rs = ereg.partyRows(
                "character_subtable");
            int lo = 1;
            for (const auto& r : rs) {
                if (r.lo != lo) ++bad;          // contiguous
                if (r.hi < r.lo || r.hi > 100) ++bad;
                lo = r.hi + 1;
            }
            if (lo != 101) ++bad;                // 01-00
        }
        // the ladder levels chain 1-13
        {
            const auto& rs = ereg.partyRows("magic_ladder");
            int lvl = 1;
            for (const auto& r : rs) {
                if (r.lo != lvl || r.hi != lvl) ++bad;
                ++lvl;
            }
            if (lvl != 14) ++bad;
        }
        // the item die faces chain from 1
        const char* const tabs[4] = {
            "magic_table_1", "magic_table_2",
            "magic_table_3", "magic_table_4" };
        for (int t = 0; t < 4; ++t) {
            const auto& rs = ereg.partyRows(tabs[t]);
            int d = 1;
            for (const auto& r : rs) {
                if (r.lo != d || r.hi != d) ++bad;
                ++d;
            }
            if (d != (int)rs.size() + 1) ++bad;
        }
        // the pluses and maxima stay printed
        for (const auto& r :
             ereg.partyRows("character_subtable"))
            if (r.max < 1 || r.max > 5) ++bad;
        for (int t = 0; t < 4; ++t)
            for (const auto& r : ereg.partyRows(tabs[t]))
                if (r.a < 0 || r.a > 5
                    || r.b < 0 || r.b > 5) ++bad;
    }
    printf("R1039 party encounter registry counts audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 3. subtable: every row pinned -------------------
    bad = 0;
    {
        const auto& rs = ereg.partyRows("character_subtable");
        { const auto& r = rs[0];
          if (r.lo != 1 || r.hi != 17) ++bad;
          if (r.prof != "cleric") ++bad;
          if (r.max != 3) ++bad; }
        { const auto& r = rs[1];
          if (r.lo != 18 || r.hi != 20) ++bad;
          if (r.prof != "druid") ++bad;
          if (r.max != 2) ++bad; }
        { const auto& r = rs[2];
          if (r.lo != 21 || r.hi != 60) ++bad;
          if (r.prof != "fighter") ++bad;
          if (r.max != 5) ++bad; }
        { const auto& r = rs[3];
          if (r.lo != 61 || r.hi != 62) ++bad;
          if (r.prof != "paladin") ++bad;
          if (r.max != 2) ++bad; }
        { const auto& r = rs[4];
          if (r.lo != 63 || r.hi != 65) ++bad;
          if (r.prof != "ranger") ++bad;
          if (r.max != 2) ++bad; }
        { const auto& r = rs[5];
          if (r.lo != 66 || r.hi != 86) ++bad;
          if (r.prof != "magic_user") ++bad;
          if (r.max != 3) ++bad; }
        { const auto& r = rs[6];
          if (r.lo != 87 || r.hi != 88) ++bad;
          if (r.prof != "illusionist") ++bad;
          if (r.max != 1) ++bad; }
        { const auto& r = rs[7];
          if (r.lo != 89 || r.hi != 98) ++bad;
          if (r.prof != "thief") ++bad;
          if (r.max != 4) ++bad; }
        { const auto& r = rs[8];
          if (r.lo != 99 || r.hi != 99) ++bad;
          if (r.prof != "assassin") ++bad;
          if (r.max != 2) ++bad; }
        { const auto& r = rs[9];
          if (r.lo != 100 || r.hi != 100) ++bad;
          if (r.prof != "monk_bard") ++bad;
          if (r.max != 1) ++bad; }
    }
    printf("R1039 party encounter registry subtable audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 4. ladder: every row, every field ----------------
    bad = 0;
    {
        { const auto& r = ereg.partyRows("magic_ladder")[0];
          if (r.lo != 1 || r.hi != 1) ++bad;
          if (r.t1pct != 10 || r.t1n != 1) ++bad;
          if (r.t2pct != 0 || r.t2n != 0) ++bad;
          if (r.t3pct != 0 || r.t3n != 0) ++bad;
          if (r.t4pct != 0 || r.t4n != 0) ++bad; }
        { const auto& r = ereg.partyRows("magic_ladder")[1];
          if (r.lo != 2 || r.hi != 2) ++bad;
          if (r.t1pct != 20 || r.t1n != 2) ++bad;
          if (r.t2pct != 0 || r.t2n != 0) ++bad;
          if (r.t3pct != 0 || r.t3n != 0) ++bad;
          if (r.t4pct != 0 || r.t4n != 0) ++bad; }
        { const auto& r = ereg.partyRows("magic_ladder")[2];
          if (r.lo != 3 || r.hi != 3) ++bad;
          if (r.t1pct != 30 || r.t1n != 2) ++bad;
          if (r.t2pct != 10 || r.t2n != 1) ++bad;
          if (r.t3pct != 0 || r.t3n != 0) ++bad;
          if (r.t4pct != 0 || r.t4n != 0) ++bad; }
        { const auto& r = ereg.partyRows("magic_ladder")[3];
          if (r.lo != 4 || r.hi != 4) ++bad;
          if (r.t1pct != 40 || r.t1n != 2) ++bad;
          if (r.t2pct != 20 || r.t2n != 1) ++bad;
          if (r.t3pct != 0 || r.t3n != 0) ++bad;
          if (r.t4pct != 0 || r.t4n != 0) ++bad; }
        { const auto& r = ereg.partyRows("magic_ladder")[4];
          if (r.lo != 5 || r.hi != 5) ++bad;
          if (r.t1pct != 50 || r.t1n != 2) ++bad;
          if (r.t2pct != 30 || r.t2n != 1) ++bad;
          if (r.t3pct != 0 || r.t3n != 0) ++bad;
          if (r.t4pct != 0 || r.t4n != 0) ++bad; }
        { const auto& r = ereg.partyRows("magic_ladder")[5];
          if (r.lo != 6 || r.hi != 6) ++bad;
          if (r.t1pct != 60 || r.t1n != 3) ++bad;
          if (r.t2pct != 40 || r.t2n != 2) ++bad;
          if (r.t3pct != 0 || r.t3n != 0) ++bad;
          if (r.t4pct != 0 || r.t4n != 0) ++bad; }
        { const auto& r = ereg.partyRows("magic_ladder")[6];
          if (r.lo != 7 || r.hi != 7) ++bad;
          if (r.t1pct != 70 || r.t1n != 3) ++bad;
          if (r.t2pct != 50 || r.t2n != 2) ++bad;
          if (r.t3pct != 10 || r.t3n != 1) ++bad;
          if (r.t4pct != 0 || r.t4n != 0) ++bad; }
        { const auto& r = ereg.partyRows("magic_ladder")[7];
          if (r.lo != 8 || r.hi != 8) ++bad;
          if (r.t1pct != 80 || r.t1n != 3) ++bad;
          if (r.t2pct != 60 || r.t2n != 2) ++bad;
          if (r.t3pct != 20 || r.t3n != 1) ++bad;
          if (r.t4pct != 0 || r.t4n != 0) ++bad; }
        { const auto& r = ereg.partyRows("magic_ladder")[8];
          if (r.lo != 9 || r.hi != 9) ++bad;
          if (r.t1pct != 90 || r.t1n != 3) ++bad;
          if (r.t2pct != 70 || r.t2n != 2) ++bad;
          if (r.t3pct != 30 || r.t3n != 1) ++bad;
          if (r.t4pct != 0 || r.t4n != 0) ++bad; }
        { const auto& r = ereg.partyRows("magic_ladder")[9];
          if (r.lo != 10 || r.hi != 10) ++bad;
          if (r.t1pct != -1 || r.t1n != 3) ++bad;
          if (r.t2pct != 80 || r.t2n != 2) ++bad;
          if (r.t3pct != 40 || r.t3n != 1) ++bad;
          if (r.t4pct != 0 || r.t4n != 0) ++bad; }
        { const auto& r = ereg.partyRows("magic_ladder")[10];
          if (r.lo != 11 || r.hi != 11) ++bad;
          if (r.t1pct != -1 || r.t1n != 3) ++bad;
          if (r.t2pct != 90 || r.t2n != 2) ++bad;
          if (r.t3pct != 50 || r.t3n != 1) ++bad;
          if (r.t4pct != 10 || r.t4n != 1) ++bad; }
        { const auto& r = ereg.partyRows("magic_ladder")[11];
          if (r.lo != 12 || r.hi != 12) ++bad;
          if (r.t1pct != -1 || r.t1n != 3) ++bad;
          if (r.t2pct != -1 || r.t2n != 2) ++bad;
          if (r.t3pct != 60 || r.t3n != 1) ++bad;
          if (r.t4pct != 20 || r.t4n != 1) ++bad; }
        { const auto& r = ereg.partyRows("magic_ladder")[12];
          if (r.lo != 13 || r.hi != 13) ++bad;
          if (r.t1pct != -1 || r.t1n != 3) ++bad;
          if (r.t2pct != -1 || r.t2n != 2) ++bad;
          if (r.t3pct != -1 || r.t3n != 1) ++bad;
          if (r.t4pct != 60 || r.t4n != 1) ++bad; }
    }
    printf("R1039 party encounter registry ladder audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 5. items: every die face of all four tables ------
    bad = 0;
    {
        { const auto& tab = ereg.partyRows("magic_table_1");
          { const auto& r = tab[0];
            if (r.lo != 1 || r.hi != 1) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[1];
            if (r.lo != 2 || r.hi != 2) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[2];
            if (r.lo != 3 || r.hi != 3) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[3];
            if (r.lo != 4 || r.hi != 4) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[4];
            if (r.lo != 5 || r.hi != 5) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[5];
            if (r.lo != 6 || r.hi != 6) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[6];
            if (r.lo != 7 || r.hi != 7) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[7];
            if (r.lo != 8 || r.hi != 8) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[8];
            if (r.lo != 9 || r.hi != 9) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[9];
            if (r.lo != 10 || r.hi != 10) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[10];
            if (r.lo != 11 || r.hi != 11) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[11];
            if (r.lo != 12 || r.hi != 12) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[12];
            if (r.lo != 13 || r.hi != 13) ++bad;
            if (r.kind != "arm") ++bad;
            if (r.a != 1 || r.b != 0) ++bad; }
          { const auto& r = tab[13];
            if (r.lo != 14 || r.hi != 14) ++bad;
            if (r.kind != "shd") ++bad;
            if (r.a != 1 || r.b != 0) ++bad; }
          { const auto& r = tab[14];
            if (r.lo != 15 || r.hi != 15) ++bad;
            if (r.kind != "wpn") ++bad;
            if (r.a != 1 || r.b != 0) ++bad; }
          { const auto& r = tab[15];
            if (r.lo != 16 || r.hi != 16) ++bad;
            if (r.kind != "rng") ++bad;
            if (r.a != 1 || r.b != 0) ++bad; }
          { const auto& r = tab[16];
            if (r.lo != 17 || r.hi != 17) ++bad;
            if (r.kind != "rng") ++bad;
            if (r.a != 2 || r.b != 0) ++bad; }
          { const auto& r = tab[17];
            if (r.lo != 18 || r.hi != 18) ++bad;
            if (r.kind != "wpn") ++bad;
            if (r.a != 1 || r.b != 0) ++bad; }
          { const auto& r = tab[18];
            if (r.lo != 19 || r.hi != 19) ++bad;
            if (r.kind != "wpn") ++bad;
            if (r.a != 2 || r.b != 0) ++bad; }
          { const auto& r = tab[19];
            if (r.lo != 20 || r.hi != 20) ++bad;
            if (r.kind != "wpn") ++bad;
            if (r.a != 1 || r.b != 0) ++bad; }
        }
        { const auto& tab = ereg.partyRows("magic_table_2");
          { const auto& r = tab[0];
            if (r.lo != 1 || r.hi != 1) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[1];
            if (r.lo != 2 || r.hi != 2) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[2];
            if (r.lo != 3 || r.hi != 3) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[3];
            if (r.lo != 4 || r.hi != 4) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[4];
            if (r.lo != 5 || r.hi != 5) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[5];
            if (r.lo != 6 || r.hi != 6) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[6];
            if (r.lo != 7 || r.hi != 7) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[7];
            if (r.lo != 8 || r.hi != 8) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[8];
            if (r.lo != 9 || r.hi != 9) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[9];
            if (r.lo != 10 || r.hi != 10) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[10];
            if (r.lo != 11 || r.hi != 11) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[11];
            if (r.lo != 12 || r.hi != 12) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[12];
            if (r.lo != 13 || r.hi != 13) ++bad;
            if (r.kind != "arm_set") ++bad;
            if (r.a != 1 || r.b != 2) ++bad; }
          { const auto& r = tab[13];
            if (r.lo != 14 || r.hi != 14) ++bad;
            if (r.kind != "arm") ++bad;
            if (r.a != 4 || r.b != 0) ++bad; }
          { const auto& r = tab[14];
            if (r.lo != 15 || r.hi != 15) ++bad;
            if (r.kind != "wpn") ++bad;
            if (r.a != 3 || r.b != 0) ++bad; }
          { const auto& r = tab[15];
            if (r.lo != 16 || r.hi != 16) ++bad;
            if (r.kind != "wpn") ++bad;
            if (r.a != 2 || r.b != 0) ++bad; }
        }
        { const auto& tab = ereg.partyRows("magic_table_3");
          { const auto& r = tab[0];
            if (r.lo != 1 || r.hi != 1) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[1];
            if (r.lo != 2 || r.hi != 2) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[2];
            if (r.lo != 3 || r.hi != 3) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[3];
            if (r.lo != 4 || r.hi != 4) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[4];
            if (r.lo != 5 || r.hi != 5) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[5];
            if (r.lo != 6 || r.hi != 6) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[6];
            if (r.lo != 7 || r.hi != 7) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[7];
            if (r.lo != 8 || r.hi != 8) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[8];
            if (r.lo != 9 || r.hi != 9) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[9];
            if (r.lo != 10 || r.hi != 10) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[10];
            if (r.lo != 11 || r.hi != 11) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[11];
            if (r.lo != 12 || r.hi != 12) ++bad;
            if (r.kind != "arm_set") ++bad;
            if (r.a != 3 || r.b != 2) ++bad; }
          { const auto& r = tab[12];
            if (r.lo != 13 || r.hi != 13) ++bad;
            if (r.kind != "shd") ++bad;
            if (r.a != 5 || r.b != 0) ++bad; }
          { const auto& r = tab[13];
            if (r.lo != 14 || r.hi != 14) ++bad;
            if (r.kind != "wpn") ++bad;
            if (r.a != 4 || r.b != 0) ++bad; }
          { const auto& r = tab[14];
            if (r.lo != 15 || r.hi != 15) ++bad;
            if (r.kind != "wpn") ++bad;
            if (r.a != 3 || r.b != 0) ++bad; }
          { const auto& r = tab[15];
            if (r.lo != 16 || r.hi != 16) ++bad;
            if (r.kind != "wpn") ++bad;
            if (r.a != 3 || r.b != 0) ++bad; }
        }
        { const auto& tab = ereg.partyRows("magic_table_4");
          { const auto& r = tab[0];
            if (r.lo != 1 || r.hi != 1) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[1];
            if (r.lo != 2 || r.hi != 2) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[2];
            if (r.lo != 3 || r.hi != 3) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[3];
            if (r.lo != 4 || r.hi != 4) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[4];
            if (r.lo != 5 || r.hi != 5) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[5];
            if (r.lo != 6 || r.hi != 6) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[6];
            if (r.lo != 7 || r.hi != 7) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[7];
            if (r.lo != 8 || r.hi != 8) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[8];
            if (r.lo != 9 || r.hi != 9) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
          { const auto& r = tab[9];
            if (r.lo != 10 || r.hi != 10) ++bad;
            if (r.kind != "arm_set") ++bad;
            if (r.a != 4 || r.b != 3) ++bad; }
          { const auto& r = tab[10];
            if (r.lo != 11 || r.hi != 11) ++bad;
            if (r.kind != "wpn") ++bad;
            if (r.a != 1 || r.b != 0) ++bad; }
          { const auto& r = tab[11];
            if (r.lo != 12 || r.hi != 12) ++bad;
            if (r.kind != "none") ++bad;
            if (r.a != 0 || r.b != 0) ++bad; }
        }
    }
    printf("R1039 party encounter registry items audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 6. party: the rollCharacterParty semantics -------
    bad = 0;
    {
        rules::Rng rng(1039);
        rules::Dice dice(rng);
        // low dungeon: 2-5 characters + 0-level men-at-arms
        for (int i = 0; i < 500; ++i) {
            dm::CharacterParty p =
                dm::rollCharacterParty(dice, 1, 1);
            if ((int)p.members.size() != 9) ++bad;
            int men = 0, chars = 0;
            for (const auto& m : p.members) {
                if (m.classIndex != rules::CLASS_FIGHTER
                    && m.classIndex != rules::CLASS_CLERIC
                    && m.classIndex != rules::CLASS_MAGIC_USER
                    && m.classIndex != rules::CLASS_THIEF) ++bad;
                if (m.manAtArms) {
                    ++men;
                    if (m.level != 0) ++bad;
                    if (m.classIndex != rules::CLASS_FIGHTER)
                        ++bad;
                } else {
                    ++chars;
                    if (m.level < 1 || m.level > 4) ++bad;
                    if (m.wpnPlus < 0 || m.wpnPlus > 4) ++bad;
                    if (m.rngPlus < 0 || m.rngPlus > 2) ++bad;
                    if (m.armPlus < 0 || m.armPlus > 4) ++bad;
                    if (m.shdPlus < 0 || m.shdPlus > 5) ++bad;
                }
            }
            if (chars < 2 || chars > 5) ++bad;
            if (men != 9 - chars) ++bad;
        }
        // deep dungeon: the followers are henchmen instead
        for (int i = 0; i < 500; ++i) {
            dm::CharacterParty p =
                dm::rollCharacterParty(dice, 10, 10);
            if ((int)p.members.size() != 9) ++bad;
            int hench = 0;
            for (const auto& m : p.members) {
                if (m.henchman) {
                    ++hench;
                    if (m.level < 1) ++bad;
                    if (m.manAtArms) ++bad;
                }
                if (m.level > 12) ++bad;   // characterLevelFor cap
            }
            if (hench < 4 || hench > 7) ++bad;
        }
    }
    printf("R1039 party encounter registry party audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 7. roll: the cross-region callers still ride ----
    bad = 0;
    {
        rules::Rng rng(1039);
        rules::Dice dice(rng);
        // the R1038 castle master rolls the R55 ladder and
        // the R53 helpers (levels 9-23, pluses bounded)
        for (int i = 0; i < 2000; ++i) {
            dm::PartyMember m = dm::rollCastleMaster(
                dice, 1 + i % 100);
            if (m.level < 9 || m.level > 23) ++bad;
            if (m.wpnPlus < 0 || m.wpnPlus > 4) ++bad;
            if (m.armPlus < 0 || m.armPlus > 4) ++bad;
            if (m.shdPlus < 0 || m.shdPlus > 5) ++bad;
        }
        // patrols ride the same construction
        for (int i = 0; i < 100; ++i) {
            dm::CharacterParty p =
                dm::rollPatrol(dice, i % 2 != 0);
            const int n = (int)p.members.size();
            if (n < 20 || n > 34) ++bad;
            int men = 0;
            for (const auto& m : p.members)
                if (m.manAtArms) ++men;
            if (men < 16 || men > 28) ++bad;
        }
    }
    printf("R1039 party encounter registry roll audit: bad %d\n", bad);
    if (bad) return 1;

}
