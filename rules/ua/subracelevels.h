// ===========================================================================
// Adnd1 - rules/ua/subracelevels.h
// The UA Character Race Table II
// (R324) - the class level limits
// per sub-race, keyed by the vital
// ability score. Header-only pins,
// the subraces.h pattern: pure data
// plus accessors, no engine
// callers yet (the leveling site
// reads these; the wiring rounds
// follow).
//
// UNEARTHED ARCANA pp. 8-9: the six
// sub-tables - II.A dwarves, II.B
// gnomes, II.C elves (the two
// printed blocks), II.D half-elves,
// II.E halflings, II.F half-orcs -
// 47 columns in all, the U entries,
// the footnoted ability gates and
// their escalation riders, and the
// single-class +2 rule. Humans have
// no sub-table (the print lists no
// limits); a null column means the
// caller reads no limit - the
// unlimited-by-omission classes
// (elven cavaliers, half-elf bards)
// ride the same null.
//
// THE KEY: the vital ability score
// as score*1000 (15000 = STR 15);
// exceptional strength 18/01-18/99
// as 18010-18990 and 18/00 (the
// top of the range) as 18999, so
// the ladder sorts exactly as the
// print rows it: 18 < 18/01 < ...
// < 18/99 < 18/00 < 19.
//
// THE READS: level 0 = U (the
// print unlimited: effectively
// unlimited for thieves and
// clerics, up to the class ceiling
// for druids and assassins - the
// caller concern). A score below
// the first row reads the first row
// (the print floor rule: a dwarven
// assassin with STR 14 or less
// attains 9th). A score between
// rows reads the lower row. The
// vital ability is class-dependent
// (STR: fighter/ranger/assassin,
// INT: magic-user/illusionist,
// WIS: cleric/druid, DEX: thief) -
// the caller passes the key.
// ===========================================================================

// R1049 applied
#pragma once

#include "subraces.h"
#include "items/MiscItemRegistry.h"

namespace rules {

// One print column: the ladder rows
// (ascending keys) with the level
// (0 = U) and the footnote id (0 =
// none) per row.
struct RaceLevelColumn {
    int n;
    const int* keys;
    const int* levels;
    const int* fns;   // may be null:
                       // no footnotes
};

// The strength-key encoder: score
// != 18 -> score*1000; pct < 0 ->
// 18000 (no exceptional roll);
// pct 1-99 -> 18000+pct*10;
// pct 100 (printed 18/00) ->
// 18999.
inline int subraceStrengthLevelKey(
        int score, int pct) {
    if (score != 18) return score*1000;
    if (pct < 0) return 18000;
    if (pct >= 100) return 18999;
    return 18000 + pct*10;
}

// The print columns, per sub-table.
// Every array is a literal of the
// printed rows; the audit re-reads
// them against the OCR.

// ---- the retired Table II ladders ----------
// The 101 ladder arrays, the 47 column
// descriptors and the 19 gate lists
// are registry rows now (R1049):
// content/tables/ua_levels/ - the six
// sub-table defs and the gates def.
// The tags map kIiaCleric ->
// iia_cleric and so on. DO NOT
// hand-edit: tools/r1049_splice.py is
// the only writer.

struct LevelGate {
    int stat;   // ABILITY_*
    int min;
};
// -------------------------------------------------
// the R1049 UA levels registry seam
//
// One registry behind the Table II
// reads: content/tables/ua_levels/ (the
// six sub-tables plus the gates). The
// per-tag views below build the column
// and gate structures on first use -
// every accessor signature and every
// clamp stays as the print reads it.
// DO NOT hand-edit: tools/r1049_splice.py
// is the only writer.
inline items::MiscItemRegistry&
uaLevelsReg() {
    static items::MiscItemRegistry reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory(
            "content/tables/ua_levels");
    }
    return reg;
}

inline const rules::RaceLevelColumn*
uaLevelColumn(const char* tag) {
    struct ColCache {
        std::map<std::string,
            RaceLevelColumn> cols;
        std::map<std::string,
            std::vector<int>> keys,
            levels, fns;
    };
    static ColCache cache;
    static bool built = false;
    if (!built) {
        built = true;
        std::map<std::string,
            std::vector<const items::
            MiscItemRow*>> byTag;
        for (const auto& kv :
                 uaLevelsReg().all()) {
            if (kv.first ==
                "ua_level_gates") continue;
            for (const auto& r :
                     kv.second.rows)
                byTag[r.name]
                    .push_back(&r);
        }
        for (auto& kv : byTag) {
            std::sort(kv.second.begin(),
                kv.second.end(),
                [](const items::
                MiscItemRow* a,
                const items::
                MiscItemRow* b) {
                    return a->bandLo
                           < b->bandLo; });
            cache.keys[kv.first]
                = std::vector<int>();
            cache.levels[kv.first]
                = std::vector<int>();
            cache.fns[kv.first]
                = std::vector<int>();
            for (const auto* r :
                     kv.second) {
                cache.keys[kv.first]
                    .push_back(r->bandLo);
                cache.levels[kv.first]
                    .push_back(r->gp);
                cache.fns[kv.first]
                    .push_back(r->xp);
            }
            RaceLevelColumn c;
            c.n = (int)cache
                .keys[kv.first].size();
            c.keys = cache
                .keys[kv.first].data();
            c.levels = cache
                .levels[kv.first].data();
            c.fns = cache
                .fns[kv.first].data();
            cache.cols[kv.first] = c;
        }
    }
    auto it = cache.cols.find(tag);
    return it == cache.cols.end()
               ? 0 : &it->second;
}

inline void uaLevelGateList(
        const char* tag,
        const rules::LevelGate*& g, int& n) {
    struct GateCache {
        std::map<std::string,
            std::vector<LevelGate>> lists;
    };
    static GateCache cache;
    static bool built = false;
    if (!built) {
        built = true;
        const items::MiscItemDef* d =
            uaLevelsReg().find(
                "ua_level_gates");
        if (d) {
            std::map<std::string,
                std::vector<const items::
                MiscItemRow*>> byTag;
            for (const auto& r : d->rows)
                byTag[r.name]
                    .push_back(&r);
            for (auto& kv : byTag) {
                std::sort(kv.second.begin(),
                    kv.second.end(),
                    [](const items::
                    MiscItemRow* a,
                    const items::
                    MiscItemRow* b) {
                        return a->bandLo
                               < b->bandLo; });
                std::vector<LevelGate> lg;
                for (const auto* r :
                         kv.second)
                    lg.push_back(LevelGate{
                        r->bandLo,
                        r->bandHi });
                cache.lists[kv.first] = lg;
            }
        }
    }
    auto it = cache.lists.find(tag);
    if (it == cache.lists.end()) {
        g = 0; n = 0; return;
    }
    g = it->second.data();
    n = (int)it->second.size();
}


// ---- the retired gate lists -------------
// The footnoted ability gates are
// registry rows now (R1049): the
// ua_level_gates def, one row per
// ability pair, name = the gate tag.
// The orMode rider (the fn6 elf
// assassin either-pair read) stays
// explicit in subraceLevelGates.

// The escalation riders (the prose
// reads that lift a limit when a
// second score climbs higher than
// the gate demands).

// II.C ranger fn1: if both INT and
// WIS are greater than 15, 8th
// level.
inline int elfRangerAbove15Level()
    { return 8; }

// II.D ranger fn2 (the 18/00 row):
// if WIS and CON are both greater
// than 18, 12th level; if both are
// greater than 19, 14th.
inline int halfElfRanger19Level()
    { return 12; }
inline int halfElfRanger20Level()
    { return 14; }

// II.E druid fn2-fn4: charisma 16+
// reads 8th, 17+ reads 10th, 18+
// reads 12th.
inline int halflingDruid16Level()
    { return 8; }
inline int halflingDruid17Level()
    { return 10; }
inline int halflingDruid18Level()
    { return 12; }

// ---------------------------------------------------------------------------
// The accessors
// ---------------------------------------------------------------------------

// The column for a sub-race/class
// pair (female splits the dark-elf
// columns). Null = no print column:
// humans, the unlimited-by-omission
// classes, and pairs Table I bars.
inline const RaceLevelColumn*
subraceLevelColumn(CharSubRace s,
                    UaClass c,
                    int female) {
    switch (s) {
        case SUB_DWARF_GRAY:
        case SUB_DWARF_MOUNTAIN:
            switch (c) {
                case UACLASS_CLERIC:
                    return uaLevelColumn("iia_cleric");
                case UACLASS_FIGHTER:
                    return
                        uaLevelColumn("iia_fighter_m_g");
                case UACLASS_THIEF:
                    return uaLevelColumn("iia_thief");
                case UACLASS_ASSASSIN:
                    return uaLevelColumn("iia_assassin");
                default: return 0;
            }
        case SUB_DWARF_HILL:
            switch (c) {
                case UACLASS_CLERIC:
                    return uaLevelColumn("iia_cleric");
                case UACLASS_FIGHTER:
                    return
                        uaLevelColumn("iia_fighter_hill");
                case UACLASS_THIEF:
                    return uaLevelColumn("iia_thief");
                case UACLASS_ASSASSIN:
                    return uaLevelColumn("iia_assassin");
                default: return 0;
            }
        case SUB_GNOME_DEEP:
        case SUB_GNOME_SURFACE:
            switch (c) {
                case UACLASS_CLERIC:
                    return uaLevelColumn("iib_cleric");
                case UACLASS_FIGHTER:
                    return uaLevelColumn("iib_fighter");
                case UACLASS_ILLUSIONIST:
                    return
                        uaLevelColumn("iib_illusionist");
                case UACLASS_THIEF:
                    return uaLevelColumn("iib_thief");
                case UACLASS_ASSASSIN:
                    return uaLevelColumn("iib_assassin");
                default: return 0;
            }
        case SUB_ELF_DARK:
            switch (c) {
                case UACLASS_CLERIC:
                    return female
                        ? uaLevelColumn("iic_cleric_d_f")
                        : uaLevelColumn("iic_cleric_d_m");
                case UACLASS_DRUID:
                    return uaLevelColumn("iic_druid_a_o");
                case UACLASS_FIGHTER:
                    return female
                        ? uaLevelColumn("iic_fighter_d_f")
                        : uaLevelColumn("iic_fighter_d_m");
                case UACLASS_MAGIC_USER:
                    return female
                        ? uaLevelColumn("iic_mu_d_f")
                        : uaLevelColumn("iic_mu_d_m");
                case UACLASS_THIEF:
                    return uaLevelColumn("iic_thief");
                case UACLASS_ASSASSIN:
                    return uaLevelColumn("iic_assassin");
                case UACLASS_RANGER:
                    return uaLevelColumn("iic_ranger");
                default: return 0;
            }
        case SUB_ELF_GRAY:
        case SUB_ELF_HIGH:
            switch (c) {
                case UACLASS_CLERIC:
                    return uaLevelColumn("iic_cleric_a_o");
                case UACLASS_DRUID:
                    return uaLevelColumn("iic_druid_a_o");
                case UACLASS_FIGHTER:
                    return uaLevelColumn("iic_fighter_g_h");
                case UACLASS_MAGIC_USER:
                    return (s == SUB_ELF_GRAY)
                        ? uaLevelColumn("iic_mu_gray")
                        : uaLevelColumn("iic_mu_high");
                case UACLASS_THIEF:
                    return uaLevelColumn("iic_thief");
                case UACLASS_ASSASSIN:
                    return uaLevelColumn("iic_assassin");
                case UACLASS_RANGER:
                    return uaLevelColumn("iic_ranger");
                default: return 0;
            }
        case SUB_ELF_VALLEY:
            switch (c) {
                case UACLASS_CLERIC:
                    return uaLevelColumn("iic_cleric_a_o");
                case UACLASS_DRUID:
                    return uaLevelColumn("iic_druid_a_o");
                case UACLASS_FIGHTER:
                    return uaLevelColumn("iic_fighter_va");
                case UACLASS_MAGIC_USER:
                    return uaLevelColumn("iic_mu_val");
                case UACLASS_THIEF:
                    return uaLevelColumn("iic_thief");
                case UACLASS_ASSASSIN:
                    return uaLevelColumn("iic_assassin");
                default: return 0;
            }
        case SUB_ELF_WILD:
            switch (c) {
                case UACLASS_CLERIC:
                    return uaLevelColumn("iic_cleric_a_o");
                case UACLASS_DRUID:
                    return uaLevelColumn("iic_druid_wild");
                case UACLASS_FIGHTER:
                    return uaLevelColumn("iic_fighter_wi");
                case UACLASS_THIEF:
                    return uaLevelColumn("iic_thief");
                case UACLASS_ASSASSIN:
                    return uaLevelColumn("iic_assassin");
                default: return 0;
            }
        case SUB_ELF_WOOD:
            switch (c) {
                case UACLASS_CLERIC:
                    return uaLevelColumn("iic_cleric_a_o");
                case UACLASS_DRUID:
                    return uaLevelColumn("iic_druid_a_o");
                case UACLASS_FIGHTER:
                    return uaLevelColumn("iic_fighter_wo");
                case UACLASS_MAGIC_USER:
                    return uaLevelColumn("iic_mu_wood");
                case UACLASS_THIEF:
                    return uaLevelColumn("iic_thief");
                case UACLASS_ASSASSIN:
                    return uaLevelColumn("iic_assassin");
                case UACLASS_RANGER:
                    return uaLevelColumn("iic_ranger");
                default: return 0;
            }
        case SUB_HALFELF:
            switch (c) {
                case UACLASS_CLERIC:
                    return uaLevelColumn("iid_cleric");
                case UACLASS_DRUID:
                    return uaLevelColumn("iid_druid");
                case UACLASS_FIGHTER:
                    return uaLevelColumn("iid_fighter");
                case UACLASS_RANGER:
                    return uaLevelColumn("iid_ranger");
                case UACLASS_MAGIC_USER:
                    return uaLevelColumn("iid_m_u");
                case UACLASS_THIEF:
                    return uaLevelColumn("iid_thief");
                case UACLASS_ASSASSIN:
                    return uaLevelColumn("iid_assassin");
                default: return 0;
            }
        case SUB_HALFLING_HAIRFOOT:
        case SUB_HALFLING_STOUT:
        case SUB_HALFLING_TALLFELLOW:
            switch (c) {
                case UACLASS_CLERIC:
                    return uaLevelColumn("iie_cleric");
                case UACLASS_DRUID:
                    return uaLevelColumn("iie_druid");
                case UACLASS_FIGHTER:
                    return
                        (s ==
                         SUB_HALFLING_HAIRFOOT)
                        ? uaLevelColumn("iie_fighter_h_f")
                        : (s ==
                          SUB_HALFLING_STOUT)
                        ? uaLevelColumn("iie_fighter_st")
                        : uaLevelColumn("iie_fighter_t_f");
                case UACLASS_THIEF:
                    return uaLevelColumn("iie_thief");
                default: return 0;
            }
        case SUB_HALF_ORC:
            switch (c) {
                case UACLASS_CLERIC:
                    return uaLevelColumn("iif_cleric");
                case UACLASS_FIGHTER:
                    return uaLevelColumn("iif_fighter");
                case UACLASS_THIEF:
                    return uaLevelColumn("iif_thief");
                case UACLASS_ASSASSIN:
                    return uaLevelColumn("iif_assassin");
                default: return 0;
            }
        case SUB_HUMAN:
        case SUB_NONE:
        default:
            return 0;
    }
}

// The level limit: -1 = no print
// column (no limit pinned); 0 = U.
// The floor rule and the between-
// rows rule both read the lower
// row.
inline int subraceLevelLimit(
        CharSubRace s, UaClass c,
        int key, int female) {
    const RaceLevelColumn* col =
        subraceLevelColumn(s, c, female);
    if (!col) return -1;
    int best = 0;
    for (int i = 0; i < col->n; ++i)
        if (col->keys[i] <= key)
            best = i;
    return col->levels[best];
}

// The footnote id of the row the
// lookup landed on (0 = none).
inline int subraceLevelFootnote(
        CharSubRace s, UaClass c,
        int key, int female) {
    const RaceLevelColumn* col =
        subraceLevelColumn(s, c, female);
    if (!col || !col->fns) return 0;
    int best = 0;
    for (int i = 0; i < col->n; ++i)
        if (col->keys[i] <= key)
            best = i;
    return col->fns[best];
}

// The gate list for a footnote id.
// fn ids are sub-table-local; the
// caller resolves them against the
// same (s, c) pair.
inline void subraceLevelGates(
        CharSubRace s, UaClass c,
        int fn,
        const LevelGate*& g,
        int& n, int& orMode) {
    g = 0; n = 0; orMode = 0;
    switch (s) {
        case SUB_DWARF_GRAY:
        case SUB_DWARF_HILL:
        case SUB_DWARF_MOUNTAIN:
            if (c != UACLASS_ASSASSIN)
                return;
            if (fn == 1) {
                uaLevelGateList("iia_g1", g, n);
            } else if (fn == 2) {
                uaLevelGateList("iia_g2", g, n); }
            return;
        case SUB_GNOME_DEEP:
        case SUB_GNOME_SURFACE:
            if (c != UACLASS_ASSASSIN)
                return;
            if (fn == 1) {
                uaLevelGateList("iib_g1", g, n);
            } else if (fn == 2) {
                uaLevelGateList("iib_g2", g, n); }
            return;
        case SUB_ELF_DARK:
        case SUB_ELF_GRAY:
        case SUB_ELF_HIGH:
        case SUB_ELF_VALLEY:
        case SUB_ELF_WILD:
        case SUB_ELF_WOOD:
            if (c == UACLASS_DRUID) {
                if (s != SUB_ELF_WILD)
                    return;
                if (fn == 1) {
                    uaLevelGateList("iic_d_g1", g, n);
                } else if (fn == 2) {
                    uaLevelGateList("iic_d_g2", g, n);
                }
                return;
            }
            if (c != UACLASS_ASSASSIN
                && c != UACLASS_RANGER)
                return;
            switch (fn) {
                case 1: uaLevelGateList("iic_a_g1", g, n);
                    return;
                case 2: uaLevelGateList("iic_a_g2", g, n);
                    return;
                case 3: uaLevelGateList("iic_a_g3", g, n);
                    return;
                case 4: uaLevelGateList("iic_a_g4", g, n);
                    return;
                case 5: uaLevelGateList("iic_a_g5", g, n);
                    return;
                case 6: uaLevelGateList("iic_a_g6", g, n);
                    orMode = 1; return;
            }
            return;
        case SUB_HALFELF:
            if (c != UACLASS_RANGER)
                return;
            if (fn == 1 || fn == 2) {
                uaLevelGateList("iid_g1", g, n);
            } else if (fn == 3) {
                uaLevelGateList("iid_g3", g, n); }
            return;
        case SUB_HALFLING_HAIRFOOT:
        case SUB_HALFLING_STOUT:
        case SUB_HALFLING_TALLFELLOW:
            if (c != UACLASS_DRUID)
                return;
            switch (fn) {
                case 1: uaLevelGateList("iie_g1", g, n);
                    return;
                case 2: uaLevelGateList("iie_g2", g, n);
                    return;
                case 3: uaLevelGateList("iie_g3", g, n);
                    return;
                case 4: uaLevelGateList("iie_g4", g, n);
                    return;
                case 5: uaLevelGateList("iie_g5", g, n);
                    return;
            }
            return;
        default:
            return;
    }
}

// The single-class +2 rule (the
// Important paragraph): a
// single-classed character whose
// class could have been a
// multi-class choice for the race
// may exceed the table limit by 2.
// The print examples: the hill
// dwarf fighter 18 STR (8 multi,
// 10 single); the 14-STR hill dwarf
// fighter (6 multi, 8 single); the
// half-elf ranger 18s (9 multi, 11
// single); the dwarven assassin
// (no bonus - a dwarf cannot
// multi-class as an assassin). The
// multi-class availability read
// lives with the engine multi-class
// layer (R185/R233) - the caller
// concern.
inline int singleClassLevelBonus()
    { return 2; }

} // namespace rules