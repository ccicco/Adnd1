// ============================================================================
// Adnd1 - rules/audits/r1040_appendixp_registry.h  (R1040)
// The DMG Appendix P convention-party battery audit, the
// R1032-R1039 shape: the registry load, exact table counts
// and the band/column/class/die chains, the full 3x3 level
// options (registry rows and the bandLevelLo/Hi functions),
// the full transposed PROTECTIVE ITEMS and WEAPONS chance
// columns (rows and the protectivePct/weaponPct functions),
// the POTION chance/max columns, the ten printed potion
// types and the kit builder chances, the printed itemChance
// chain (incl. the Gonzo worked example) and the member
// builders. Expected: 6 appendixp files - the level options
// (9 rows), the two gear tables (7 rows each), the potions
// (4 rows), the types (10 rows) and the kit (4 rows) - all
// derived from the DMG record (pp.225-226, the 1eonline.info
// compilation) the splice parsed. The seam is header-only:
// an inline apReg() singleton self-loads the directory
// (encReg() is file-static to encounters.cpp and stays
// untouched).
// ============================================================================
{
    int bad = 0;
    dm::EncounterTableRegistry ereg;

    // -- 1. load: 6 appendixp files, zero errors, one reg --
    bad = 0;
    {
        const int af = ereg.loadDirectory(
            "content/tables/appendixp");
        if (af != 6) ++bad;
        if (!ereg.errors().empty()) ++bad;
        const int nf = ereg.loadDirectory(
            "content/tables/encounters_party");
        if (nf != 6) ++bad;
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
        if (!ereg.hasAppendixP("appendixp_band_level")) ++bad;
        if (!ereg.hasAppendixP("appendixp_protective")) ++bad;
        if (!ereg.hasAppendixP("appendixp_weapons")) ++bad;
        if (!ereg.hasAppendixP("appendixp_potions")) ++bad;
        if (!ereg.hasAppendixP("appendixp_potion_types")) ++bad;
        if (!ereg.hasAppendixP("appendixp_kit")) ++bad;
        // negative pins (the R1034 lesson; the R1038
        // phantom-pin lesson: every negative names a key
        // ABSENT from that map)
        if (ereg.hasAppendixP("")) ++bad;
        if (ereg.hasAppendixP("castle_type")) ++bad;
        if (ereg.hasAppendixP("appendixp_band")) ++bad;
        if (ereg.hasCastle("appendixp_kit")) ++bad;
        if (ereg.hasParty("appendixp_kit")) ++bad;
        if (ereg.hasPlanar("appendixp_kit")) ++bad;
        if (ereg.hasPlanarBands("appendixp_kit")) ++bad;
        if (ereg.hasWater("appendixp_kit")) ++bad;
        if (ereg.hasOutdoor("appendixp_kit")) ++bad;
        if (ereg.hasCityBands("appendixp_kit")) ++bad;
        // the earlier families still load clean
        if (!ereg.hasParty("character_subtable")) ++bad;
        if (!ereg.hasCastle("castle_master")) ++bad;
        if (!ereg.hasPlanar("psionic_table")) ++bad;
        if ((int)ereg.list("psionic_spell_exact").size()
            != 20) ++bad;
    }
    printf("R1040 appendixp registry load audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 2. counts: rows and the printed chains ------------
    bad = 0;
    {
        if ((int)ereg.appendixPRows("appendixp_band_level")
            .size() != 9) ++bad;
        if ((int)ereg.appendixPRows("appendixp_protective")
            .size() != 7) ++bad;
        if ((int)ereg.appendixPRows("appendixp_weapons")
            .size() != 7) ++bad;
        if ((int)ereg.appendixPRows("appendixp_potions")
            .size() != 4) ++bad;
        if ((int)ereg.appendixPRows("appendixp_potion_types")
            .size() != 10) ++bad;
        if ((int)ereg.appendixPRows("appendixp_kit")
            .size() != 4) ++bad;
        // the gear columns chain 1-7
        const char* const gear[2] = {
            "appendixp_protective", "appendixp_weapons" };
        for (int g = 0; g < 2; ++g) {
            const auto& rs = ereg.appendixPRows(gear[g]);
            int c = 1;
            for (const auto& r : rs) {
                if (r.lo != c || r.hi != c) ++bad;
                ++c;
            }
            if (c != 8) ++bad;
        }
        // the class-keyed rows chain 1-4
        const char* const cls[2] = {
            "appendixp_potions", "appendixp_kit" };
        for (int g = 0; g < 2; ++g) {
            const auto& rs = ereg.appendixPRows(cls[g]);
            int c = 1;
            for (const auto& r : rs) {
                if (r.lo != c || r.hi != c) ++bad;
                ++c;
            }
            if (c != 5) ++bad;
        }
        // the die faces chain 1-10
        {
            const auto& rs =
                ereg.appendixPRows("appendixp_potion_types");
            int d = 1;
            for (const auto& r : rs) {
                if (r.lo != d || r.hi != d) ++bad;
                ++d;
            }
            if (d != 11) ++bad;
        }
        // the level ranges stay printed
        for (const auto& r :
             ereg.appendixPRows("appendixp_band_level"))
            if (r.lo < 1 || r.hi < r.lo || r.hi > 12) ++bad;
    }
    printf("R1040 appendixp registry counts audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 3. band: the full 3x3 level options ---------------
    bad = 0;
    {
        const auto& rb =
            ereg.appendixPRows("appendixp_band_level");
        { const auto& r = rb[0];
          if (r.band != 1 || r.option != 1) ++bad;
          if (r.lo != 1 || r.hi != 2) ++bad; }
        { const auto& r = rb[1];
          if (r.band != 1 || r.option != 2) ++bad;
          if (r.lo != 1 || r.hi != 3) ++bad; }
        { const auto& r = rb[2];
          if (r.band != 1 || r.option != 3) ++bad;
          if (r.lo != 2 || r.hi != 4) ++bad; }
        { const auto& r = rb[3];
          if (r.band != 2 || r.option != 1) ++bad;
          if (r.lo != 5 || r.hi != 7) ++bad; }
        { const auto& r = rb[4];
          if (r.band != 2 || r.option != 2) ++bad;
          if (r.lo != 5 || r.hi != 8) ++bad; }
        { const auto& r = rb[5];
          if (r.band != 2 || r.option != 3) ++bad;
          if (r.lo != 7 || r.hi != 9) ++bad; }
        { const auto& r = rb[6];
          if (r.band != 3 || r.option != 1) ++bad;
          if (r.lo != 8 || r.hi != 10) ++bad; }
        { const auto& r = rb[7];
          if (r.band != 3 || r.option != 2) ++bad;
          if (r.lo != 8 || r.hi != 11) ++bad; }
        { const auto& r = rb[8];
          if (r.band != 3 || r.option != 3) ++bad;
          if (r.lo != 9 || r.hi != 12) ++bad; }
        if (dm::appendixp::bandLevelLo(0, 0) != 1)
            ++bad;
        if (dm::appendixp::bandLevelHi(0, 0) != 2)
            ++bad;
        if (dm::appendixp::bandLevelLo(0, 1) != 1)
            ++bad;
        if (dm::appendixp::bandLevelHi(0, 1) != 3)
            ++bad;
        if (dm::appendixp::bandLevelLo(0, 2) != 2)
            ++bad;
        if (dm::appendixp::bandLevelHi(0, 2) != 4)
            ++bad;
        if (dm::appendixp::bandLevelLo(1, 0) != 5)
            ++bad;
        if (dm::appendixp::bandLevelHi(1, 0) != 7)
            ++bad;
        if (dm::appendixp::bandLevelLo(1, 1) != 5)
            ++bad;
        if (dm::appendixp::bandLevelHi(1, 1) != 8)
            ++bad;
        if (dm::appendixp::bandLevelLo(1, 2) != 7)
            ++bad;
        if (dm::appendixp::bandLevelHi(1, 2) != 9)
            ++bad;
        if (dm::appendixp::bandLevelLo(2, 0) != 8)
            ++bad;
        if (dm::appendixp::bandLevelHi(2, 0) != 10)
            ++bad;
        if (dm::appendixp::bandLevelLo(2, 1) != 8)
            ++bad;
        if (dm::appendixp::bandLevelHi(2, 1) != 11)
            ++bad;
        if (dm::appendixp::bandLevelLo(2, 2) != 9)
            ++bad;
        if (dm::appendixp::bandLevelHi(2, 2) != 12)
            ++bad;
        // the defensive clamps mirror the retired arrays
        if (dm::appendixp::bandLevelLo(-1, -1) != 1) ++bad;
        if (dm::appendixp::bandLevelLo(9, 9) != 9) ++bad;
        if (dm::appendixp::bandLevelHi(-1, -1) != 2) ++bad;
        if (dm::appendixp::bandLevelHi(9, 9) != 12) ++bad;
    }
    printf("R1040 appendixp registry band audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 4. gear: the full chance columns -------------------
    bad = 0;
    {
        { const auto& r = ereg.appendixPRows("appendixp_protective")[0];
          if (r.lo != 1 || r.hi != 1) ++bad;
          if (r.fighter != 10) ++bad;
          if (r.magic_user != 0) ++bad;
          if (r.cleric != 10) ++bad;
          if (r.thief != 0) ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_protective")[1];
          if (r.lo != 2 || r.hi != 2) ++bad;
          if (r.fighter != 6) ++bad;
          if (r.magic_user != 0) ++bad;
          if (r.cleric != 5) ++bad;
          if (r.thief != 0) ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_protective")[2];
          if (r.lo != 3 || r.hi != 3) ++bad;
          if (r.fighter != 8) ++bad;
          if (r.magic_user != 0) ++bad;
          if (r.cleric != 6) ++bad;
          if (r.thief != 0) ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_protective")[3];
          if (r.lo != 4 || r.hi != 4) ++bad;
          if (r.fighter != 10) ++bad;
          if (r.magic_user != 0) ++bad;
          if (r.cleric != 8) ++bad;
          if (r.thief != 0) ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_protective")[4];
          if (r.lo != 5 || r.hi != 5) ++bad;
          if (r.fighter != 0) ++bad;
          if (r.magic_user != 0) ++bad;
          if (r.cleric != 0) ++bad;
          if (r.thief != 10) ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_protective")[5];
          if (r.lo != 6 || r.hi != 6) ++bad;
          if (r.fighter != 0) ++bad;
          if (r.magic_user != 15) ++bad;
          if (r.cleric != 2) ++bad;
          if (r.thief != 4) ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_protective")[6];
          if (r.lo != 7 || r.hi != 7) ++bad;
          if (r.fighter != 0) ++bad;
          if (r.magic_user != 4) ++bad;
          if (r.cleric != 0) ++bad;
          if (r.thief != 0) ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_weapons")[0];
          if (r.lo != 1 || r.hi != 1) ++bad;
          if (r.fighter != 10) ++bad;
          if (r.magic_user != 15) ++bad;
          if (r.cleric != 0) ++bad;
          if (r.thief != 12) ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_weapons")[1];
          if (r.lo != 2 || r.hi != 2) ++bad;
          if (r.fighter != 10) ++bad;
          if (r.magic_user != 0) ++bad;
          if (r.cleric != 0) ++bad;
          if (r.thief != 11) ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_weapons")[2];
          if (r.lo != 3 || r.hi != 3) ++bad;
          if (r.fighter != 0) ++bad;
          if (r.magic_user != 0) ++bad;
          if (r.cleric != 12) ++bad;
          if (r.thief != 0) ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_weapons")[3];
          if (r.lo != 4 || r.hi != 4) ++bad;
          if (r.fighter != 7) ++bad;
          if (r.magic_user != 0) ++bad;
          if (r.cleric != 0) ++bad;
          if (r.thief != 0) ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_weapons")[4];
          if (r.lo != 5 || r.hi != 5) ++bad;
          if (r.fighter != 8) ++bad;
          if (r.magic_user != 0) ++bad;
          if (r.cleric != 0) ++bad;
          if (r.thief != 0) ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_weapons")[5];
          if (r.lo != 6 || r.hi != 6) ++bad;
          if (r.fighter != 1) ++bad;
          if (r.magic_user != 0) ++bad;
          if (r.cleric != 0) ++bad;
          if (r.thief != 0) ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_weapons")[6];
          if (r.lo != 7 || r.hi != 7) ++bad;
          if (r.fighter != 10) ++bad;
          if (r.magic_user != 0) ++bad;
          if (r.cleric != 0) ++bad;
          if (r.thief != 0) ++bad; }
        if (dm::appendixp::protectivePct(0, 0) != 10)
            ++bad;
        if (dm::appendixp::protectivePct(1, 0) != 0)
            ++bad;
        if (dm::appendixp::protectivePct(2, 0) != 10)
            ++bad;
        if (dm::appendixp::protectivePct(3, 0) != 0)
            ++bad;
        if (dm::appendixp::protectivePct(0, 1) != 6)
            ++bad;
        if (dm::appendixp::protectivePct(1, 1) != 0)
            ++bad;
        if (dm::appendixp::protectivePct(2, 1) != 5)
            ++bad;
        if (dm::appendixp::protectivePct(3, 1) != 0)
            ++bad;
        if (dm::appendixp::protectivePct(0, 2) != 8)
            ++bad;
        if (dm::appendixp::protectivePct(1, 2) != 0)
            ++bad;
        if (dm::appendixp::protectivePct(2, 2) != 6)
            ++bad;
        if (dm::appendixp::protectivePct(3, 2) != 0)
            ++bad;
        if (dm::appendixp::protectivePct(0, 3) != 10)
            ++bad;
        if (dm::appendixp::protectivePct(1, 3) != 0)
            ++bad;
        if (dm::appendixp::protectivePct(2, 3) != 8)
            ++bad;
        if (dm::appendixp::protectivePct(3, 3) != 0)
            ++bad;
        if (dm::appendixp::protectivePct(0, 4) != 0)
            ++bad;
        if (dm::appendixp::protectivePct(1, 4) != 0)
            ++bad;
        if (dm::appendixp::protectivePct(2, 4) != 0)
            ++bad;
        if (dm::appendixp::protectivePct(3, 4) != 10)
            ++bad;
        if (dm::appendixp::protectivePct(0, 5) != 0)
            ++bad;
        if (dm::appendixp::protectivePct(1, 5) != 15)
            ++bad;
        if (dm::appendixp::protectivePct(2, 5) != 2)
            ++bad;
        if (dm::appendixp::protectivePct(3, 5) != 4)
            ++bad;
        if (dm::appendixp::protectivePct(0, 6) != 0)
            ++bad;
        if (dm::appendixp::protectivePct(1, 6) != 4)
            ++bad;
        if (dm::appendixp::protectivePct(2, 6) != 0)
            ++bad;
        if (dm::appendixp::protectivePct(3, 6) != 0)
            ++bad;
        if (dm::appendixp::weaponPct(0, 0) != 10)
            ++bad;
        if (dm::appendixp::weaponPct(1, 0) != 15)
            ++bad;
        if (dm::appendixp::weaponPct(2, 0) != 0)
            ++bad;
        if (dm::appendixp::weaponPct(3, 0) != 12)
            ++bad;
        if (dm::appendixp::weaponPct(0, 1) != 10)
            ++bad;
        if (dm::appendixp::weaponPct(1, 1) != 0)
            ++bad;
        if (dm::appendixp::weaponPct(2, 1) != 0)
            ++bad;
        if (dm::appendixp::weaponPct(3, 1) != 11)
            ++bad;
        if (dm::appendixp::weaponPct(0, 2) != 0)
            ++bad;
        if (dm::appendixp::weaponPct(1, 2) != 0)
            ++bad;
        if (dm::appendixp::weaponPct(2, 2) != 12)
            ++bad;
        if (dm::appendixp::weaponPct(3, 2) != 0)
            ++bad;
        if (dm::appendixp::weaponPct(0, 3) != 7)
            ++bad;
        if (dm::appendixp::weaponPct(1, 3) != 0)
            ++bad;
        if (dm::appendixp::weaponPct(2, 3) != 0)
            ++bad;
        if (dm::appendixp::weaponPct(3, 3) != 0)
            ++bad;
        if (dm::appendixp::weaponPct(0, 4) != 8)
            ++bad;
        if (dm::appendixp::weaponPct(1, 4) != 0)
            ++bad;
        if (dm::appendixp::weaponPct(2, 4) != 0)
            ++bad;
        if (dm::appendixp::weaponPct(3, 4) != 0)
            ++bad;
        if (dm::appendixp::weaponPct(0, 5) != 1)
            ++bad;
        if (dm::appendixp::weaponPct(1, 5) != 0)
            ++bad;
        if (dm::appendixp::weaponPct(2, 5) != 0)
            ++bad;
        if (dm::appendixp::weaponPct(3, 5) != 0)
            ++bad;
        if (dm::appendixp::weaponPct(0, 6) != 10)
            ++bad;
        if (dm::appendixp::weaponPct(1, 6) != 0)
            ++bad;
        if (dm::appendixp::weaponPct(2, 6) != 0)
            ++bad;
        if (dm::appendixp::weaponPct(3, 6) != 0)
            ++bad;
        // the defensive clamps: out-of-range reads the
        // edge rows (the retired clamp behavior)
        if (dm::appendixp::protectivePct(0, -1) != 10) ++bad;
        if (dm::appendixp::protectivePct(0, 9) != 0) ++bad;
        if (dm::appendixp::weaponPct(1, -1) != 15) ++bad;
        if (dm::appendixp::weaponPct(1, 9) != 0) ++bad;
    }
    printf("R1040 appendixp registry gear audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 5. potions, types and kit ---------------------------
    bad = 0;
    {
        { const auto& r = ereg.appendixPRows("appendixp_potions")[0];
          if (r.lo != 1 || r.hi != 1) ++bad;
          if (r.pct != 8 || r.max != 1) ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_potions")[1];
          if (r.lo != 2 || r.hi != 2) ++bad;
          if (r.pct != 10 || r.max != 3) ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_potions")[2];
          if (r.lo != 3 || r.hi != 3) ++bad;
          if (r.pct != 6 || r.max != 1) ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_potions")[3];
          if (r.lo != 4 || r.hi != 4) ++bad;
          if (r.pct != 9 || r.max != 2) ++bad; }
        if (dm::appendixp::potionPct(0) != 8) ++bad;
        if (dm::appendixp::potionMax(0) != 1) ++bad;
        if (dm::appendixp::potionPct(1) != 10) ++bad;
        if (dm::appendixp::potionMax(1) != 3) ++bad;
        if (dm::appendixp::potionPct(2) != 6) ++bad;
        if (dm::appendixp::potionMax(2) != 1) ++bad;
        if (dm::appendixp::potionPct(3) != 9) ++bad;
        if (dm::appendixp::potionMax(3) != 2) ++bad;
        { const auto& r = ereg.appendixPRows("appendixp_potion_types")[0];
          if (r.lo != 1 || r.hi != 1) ++bad;
          if (r.key != "Climbing") ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_potion_types")[1];
          if (r.lo != 2 || r.hi != 2) ++bad;
          if (r.key != "Diminution") ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_potion_types")[2];
          if (r.lo != 3 || r.hi != 3) ++bad;
          if (r.key != "Extra-Healing") ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_potion_types")[3];
          if (r.lo != 4 || r.hi != 4) ++bad;
          if (r.key != "Fire Resistance") ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_potion_types")[4];
          if (r.lo != 5 || r.hi != 5) ++bad;
          if (r.key != "Flying") ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_potion_types")[5];
          if (r.lo != 6 || r.hi != 6) ++bad;
          if (r.key != "Gaseous Form") ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_potion_types")[6];
          if (r.lo != 7 || r.hi != 7) ++bad;
          if (r.key != "Growth") ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_potion_types")[7];
          if (r.lo != 8 || r.hi != 8) ++bad;
          if (r.key != "Healing") ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_potion_types")[8];
          if (r.lo != 9 || r.hi != 9) ++bad;
          if (r.key != "Invisibility") ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_potion_types")[9];
          if (r.lo != 10 || r.hi != 10) ++bad;
          if (r.key != "Polymorph Self") ++bad; }
        if (std::string(dm::appendixp::potionType(1))
            != "Climbing") ++bad;
        if (std::string(dm::appendixp::potionType(2))
            != "Diminution") ++bad;
        if (std::string(dm::appendixp::potionType(3))
            != "Extra-Healing") ++bad;
        if (std::string(dm::appendixp::potionType(4))
            != "Fire Resistance") ++bad;
        if (std::string(dm::appendixp::potionType(5))
            != "Flying") ++bad;
        if (std::string(dm::appendixp::potionType(6))
            != "Gaseous Form") ++bad;
        if (std::string(dm::appendixp::potionType(7))
            != "Growth") ++bad;
        if (std::string(dm::appendixp::potionType(8))
            != "Healing") ++bad;
        if (std::string(dm::appendixp::potionType(9))
            != "Invisibility") ++bad;
        if (std::string(dm::appendixp::potionType(10))
            != "Polymorph Self") ++bad;
        { const auto& r = ereg.appendixPRows("appendixp_kit")[0];
          if (r.lo != 1 || r.hi != 1) ++bad;
          if (r.armorPct != 10) ++bad;
          if (r.weaponPct != 10) ++bad;
          if (r.shieldPct != 10) ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_kit")[1];
          if (r.lo != 2 || r.hi != 2) ++bad;
          if (r.armorPct != 15) ++bad;
          if (r.weaponPct != 15) ++bad;
          if (r.shieldPct != 0) ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_kit")[2];
          if (r.lo != 3 || r.hi != 3) ++bad;
          if (r.armorPct != 8) ++bad;
          if (r.weaponPct != 12) ++bad;
          if (r.shieldPct != 10) ++bad; }
        { const auto& r = ereg.appendixPRows("appendixp_kit")[3];
          if (r.lo != 4 || r.hi != 4) ++bad;
          if (r.armorPct != 10) ++bad;
          if (r.weaponPct != 11) ++bad;
          if (r.shieldPct != 0) ++bad; }
        // the defensive clamps
        if (dm::appendixp::potionPct(-1) != 8) ++bad;
        if (dm::appendixp::potionPct(9) != 9) ++bad;
        if (dm::appendixp::potionMax(-1) != 1) ++bad;
        if (dm::appendixp::potionMax(9) != 2) ++bad;
        if (*dm::appendixp::potionType(0) == 0) ++bad;
        if (*dm::appendixp::potionType(11) == 0) ++bad;
        if (std::string(dm::appendixp::potionType(0))
            != "Climbing") ++bad;
        if (std::string(dm::appendixp::potionType(11))
            != "Polymorph Self") ++bad;
    }
    printf("R1040 appendixp registry potions audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 6. chain: the printed itemChance chain -------------
    bad = 0;
    rules::Rng rng(1040);
    rules::Dice dice(rng);
    {
        // the Gonzo worked example (p.225): 15%/level chain
        // at 9th = 135%; +2 chance 9 + 45 = 54; +3 check 9
        if (dm::appendixp::itemChancePct(15, 9) != 135) ++bad;
        if (dm::appendixp::plusTwoChancePct(15, 9) != 54) ++bad;
        if (dm::appendixp::plusThreeChancePct(9) != 9) ++bad;
        if (dm::appendixp::itemChancePct(0, 9) != 0) ++bad;
        if (dm::appendixp::itemChancePct(15, 0) != 15) ++bad;
        // a zero chance never rolls a plus
        for (int i = 0; i < 100; ++i)
            if (dm::appendixp::rollItemPlus(dice, 0, 9) != 0)
                ++bad;
        // a huge chance always lands at least +1
        for (int i = 0; i < 100; ++i)
            if (dm::appendixp::rollItemPlus(dice, 100, 20) < 1)
                ++bad;
        // the ability roll stays 4d6-best-of-3
        for (int i = 0; i < 1000; ++i) {
            const int a = dm::appendixp::abilityRoll(dice);
            if (a < 3 || a > 18) ++bad;
        }
    }
    printf("R1040 appendixp registry chain audit: bad %d\n", bad);
    if (bad) return 1;

    // -- 7. member: the spur-of-the-moment builders ----------
    bad = 0;
    {
        // rollMemberMagic: kit pluses stay 0-3
        for (int i = 0; i < 4000; ++i) {
            const int c = i % 4;
            dm::appendixp::MemberMagic m =
                dm::appendixp::rollMemberMagic(
                    dice, c, 1 + i % 12);
            if (m.armorPlus < 0 || m.armorPlus > 3) ++bad;
            if (m.weaponPlus < 0 || m.weaponPlus > 3) ++bad;
            if (m.shieldPlus < 0 || m.shieldPlus > 3) ++bad;
            if (c != 0 && c != 2 && m.shieldPlus != 0) ++bad;
        }
        // rollSpurMember: the level lands in its band x
        // option, the abilities stay 3-18, classIndex clamps
        for (int i = 0; i < 2000; ++i) {
            const int b = i % 3, o = (i / 3) % 3;
            dm::appendixp::SpurMember m =
                dm::appendixp::rollSpurMember(
                    dice, b, o, i % 4);
            if (m.level < dm::appendixp::bandLevelLo(b, o)
                || m.level > dm::appendixp::bandLevelHi(b, o))
                ++bad;
            for (int a = 0; a < 6; ++a)
                if (m.abilities[a] < 3 || m.abilities[a] > 18)
                    ++bad;
        }
        // the classIndex clamp (the R156 m9 pin shape)
        {
            dm::appendixp::SpurMember m =
                dm::appendixp::rollSpurMember(dice, 0, 0, 9);
            if (m.classIndex != 3) ++bad;
        }
    }
    printf("R1040 appendixp registry member audit: bad %d\n", bad);
    if (bad) return 1;

}
