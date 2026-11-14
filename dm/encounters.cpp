// ============================================================================
// Adnd1 - dm/encounters.cpp - see encounters.h
//
// R52: the DMG Appendix C dungeon tables (Premium reprint p.174-179,
// OCR-verified against the uploaded DMG): Determination Matrix, Monster
// Level Tables I-X (verbatim dice ranges and numbers), per-level Dragon
// Subtables with age categories, Human Subtable. Character Subtable
// parties and the D3-module daemons re-roll (DMG's own advice).
//
// Footnoted substitutions per the printed tables: Badger (L I, below
// 2nd dungeon level) -> Hobgoblin; Halfling (L I, below 4th) -> Giant
// Rat; Giant Badger (L II, below 3rd) -> Gnoll. "Titan, minor" maps to
// the lesser-titan AC-2 record; "Lizard, subterranean" -> fire lizard.
// ============================================================================

#include "encounters.h"
#include "appendixp.h"   // R156: Appendix P kits, the convention party
#include "EncounterTableRegistry.h"   // R1032: the registry-native dungeon tables

#include <algorithm>
#include <array>
#include <cstdint>
#include <map>
#include <string>
#include <vector>

namespace dm {
namespace {

enum RowKind {
    ROW_MONSTER, ROW_HUMAN, ROW_CHARACTER, ROW_DRAGON, ROW_HYDRA,
    ROW_ELEMENTAL, ROW_PRINCE, ROW_NONE
};

struct Row {
    int lo, hi;             // percentile range
    int kind;
    std::string key;
    int a, b;               // count range (monster) or head range (hydra)
    int nmin, nmax;        // hydra number appearing
};

struct DragonRow {
    int lo, hi;
    std::string key;
    int ageLo, ageHi;      // age bracket 1-8 range
};

// ---- R1032: the DMG Appendix C dungeon tables ride the registry ----
// The retired per-level, dragon-subtable, matrix and pool static
// arrays are the R52 print-fidelity record (Premium reprint
// p.174-179, OCR-verified); tools/r1032_splice.py moved them
// verbatim into content/tables/encounters/*.lua and this seam
// reads them through dm::EncounterTableRegistry - the R1028
// misc-engine pattern. Views are built once, band-sorted,
// kind-mapped; rollDungeonEncounter() and encounterKeys() are
// byte-identical in behavior.

struct MatrixBand { int lo, hi, mlv; };

// Retained verbatim: kPrinces/kArchDevils are shared with the planar
// and psi special-key dispatch paths further down this file
// (PLANAR_DEMON_PRINCE / PSI_DEMON_PRINCE etc.), so the dungeon seam
// keeps using them. The registry still carries the "princes" and
// "arch_devils" lists, and the R1032 fragment cross-checks the two.
static const char* kPrinces[] = { "demogorgon", "juiblex", "orcus", "yeenoghu" };
static const char* kArchDevils[] = { "asmodeus", "baalzebul", "dispater", "geryon" };

static dm::EncounterTableRegistry& encReg() {
    // One-time lazy load (adnd1.cpp is a Win32 shell TU that preflight
    // skips, so the engine loads its own registries; the battery's
    // R1032 fragment catches a missing directory loudly).
    static dm::EncounterTableRegistry reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory("content/tables/encounters");
        // R1033: the water family joined the registry from its own
        // directory (the R1032 audit pins 20 files in encounters/).
        reg.loadDirectory("content/tables/encounters_water");
        // R1034: the outdoor family joined likewise (the R1033
        // audit pins 9 files in encounters_water/).
        reg.loadDirectory("content/tables/encounters_outdoor");
    }
    return reg;
}

static int kindFor(const std::string& k) {
    if (k == "monster")   return ROW_MONSTER;
    if (k == "human")     return ROW_HUMAN;
    if (k == "character") return ROW_CHARACTER;
    if (k == "dragon")    return ROW_DRAGON;
    if (k == "hydra")     return ROW_HYDRA;
    if (k == "elemental") return ROW_ELEMENTAL;
    if (k == "prince")    return ROW_PRINCE;
    return ROW_NONE;
}

static const std::vector<Row>& levelView(int n) {
    static std::vector<std::vector<Row>> cache(11);
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        for (int t = 1; t <= 10; ++t) {
            const auto& rs = encReg().levelRows(t);
            for (const auto& r : rs)
                cache[t].push_back(Row{ r.lo, r.hi, kindFor(r.kind),
                                        r.key, r.a, r.b, r.nmin, r.nmax });
        }
    }
    return cache[n];
}

static const std::vector<DragonRow>& dragonView(int n) {
    static std::vector<std::vector<DragonRow>> cache(11);
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        for (int t = 3; t <= 10; ++t) {
            const auto& rs = encReg().dragonRows(t);
            for (const auto& r : rs)
                cache[t].push_back(DragonRow{ r.lo, r.hi, r.key,
                                              r.ageLo, r.ageHi });
        }
    }
    return cache[n];
}

static const std::vector<std::array<MatrixBand, 10>>& matrixView() {
    static std::vector<std::array<MatrixBand, 10>> m;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        m.resize(12);
        for (int b = 0; b < 12; ++b) {
            const auto& es = encReg().matrixBand(b);
            int i = 0;
            for (const auto& e : es)
                m[b][i++] = MatrixBand{ e.lo, e.hi, e.mlv };
        }
    }
    return m;
}

static const std::vector<std::string>& listView(const char* set) {
    static std::map<std::string, std::vector<std::string>> m;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        for (const char* s : { "princes", "arch_devils", "elementals",
                              "hill_stone", "fire_frost", "piercers" })
            m[s] = encReg().list(s);
    }
    static const std::vector<std::string> none;
    auto it = m.find(set);
    return it == m.end() ? none : it->second;
}


const Row* levelTable(int mlv, size_t& count) {
    const std::vector<Row>& t = levelView(mlv);
    count = t.size();
    return t.empty() ? nullptr : t.data();
}

const DragonRow* dragonTable(int mlv, size_t& count) {
    const std::vector<DragonRow>& t = dragonView(mlv);
    count = t.size();
    return t.empty() ? nullptr : t.data();
}

} // namespace

int monsterLevelFor(int dungeonLevel, int d20) {
    int band = dungeonLevel < 1 ? 0
             : dungeonLevel >= 16 ? 11 : dungeonLevel - 1;
    const auto& row = matrixView()[band];
    for (int i = 0; i < 10; ++i)
        if (row[i].lo > 0 && d20 >= row[i].lo && d20 <= row[i].hi)
            return i + 1;
    return 1;
}

DungeonEncounter rollDungeonEncounter(
        const monsters::MonsterRegistry& reg, rules::Dice& dice,
        int d20, int pctile, int pctile2, int dungeonLevel) {
    DungeonEncounter e;

    for (int attempt = 0; attempt < 24; ++attempt) {
        int mlv = monsterLevelFor(dungeonLevel, d20);
        size_t count = 0;
        const Row* t = levelTable(mlv, count);
        const Row* row = nullptr;
        for (size_t i = 0; i < count; ++i)
            if (pctile >= t[i].lo && pctile <= t[i].hi) { row = &t[i]; break; }
        if (!row) return e;

        switch ((RowKind)row->kind) {
        case ROW_MONSTER: {
            std::string key = row->key;
            if (key == "REROLL") break;
            if (key == "HILL_STONE")  key = listView("hill_stone")[pctile2 % 2];
            if (key == "FIRE_FROST") key = listView("fire_frost")[pctile2 % 2];
            if (key == "PIERCER")
                key = listView("piercers")[pctile2 % 4];
            if (!reg.find(key)) break;
            e.key = key;
            e.count = (row->a == row->b)
                ? row->a
                : row->a + (int)dice.roll(1,
                        (uint32_t)(row->b - row->a + 1), 0) - 1;
            return e;
        }
        case ROW_HYDRA: {
            if (!reg.find(row->key)) break;
            e.key = row->key;
            e.headsLo = row->a;
            e.headsHi = row->b;
            e.count = row->nmin;
            return e;
        }
        case ROW_DRAGON: {
            size_t dc = 0;
            const DragonRow* dt = dragonTable(mlv, dc);
            const DragonRow* dr = nullptr;
            for (size_t i = 0; i < dc; ++i)
                if (pctile2 >= dt[i].lo && pctile2 <= dt[i].hi)
                    { dr = &dt[i]; break; }
            if (!dr) return e;
            if (!reg.find(dr->key)) break;
            e.key = dr->key;
            e.ageLo = dr->ageLo;
            e.ageHi = dr->ageHi;
            e.count = (mlv >= 9)
                ? (int)dice.roll(1, 2, 0)   // DMG: 1-2 at ML IX/X
                : 1;
            return e;
        }
        case ROW_ELEMENTAL: {
            const std::string& key = listView("elementals")[pctile2 % 4];
            if (!reg.find(key)) break;
            e.key = key;
            e.count = 1;
            return e;
        }
        case ROW_PRINCE: {
            const char* const* pool =
                (row->hi <= 28) ? kPrinces : kArchDevils;
            const char* key = pool[pctile2 % 4];
            if (!reg.find(key)) break;
            e.key = key;
            e.count = 1;
            return e;
        }
        case ROW_HUMAN: {
            // Human Subtable: 01-25 Bandit, 26-30 Berserker,
            // 31-45 Brigand (chaotic evil bandits), 46-00 Character
            if (pctile2 <= 25)      e.key = "bandit";
            else if (pctile2 <= 30) e.key = "berserker";
            else if (pctile2 <= 45) e.key = "bandit";
            else {
                // R53: Character Subtable party (DMG p.176)
                e.party = rollCharacterParty(dice, dungeonLevel, mlv);
                e.isParty = true;
                e.key = "character_party";
                e.count = e.party.size();
                return e;
            }
            if (!reg.find(e.key)) break;
            e.count = (e.key == "berserker")
                ? 2 + (int)dice.roll(1, 7, 0)      // 3-9
                : 4 + (int)dice.roll(1, 11, 0);    // 5-15
            return e;
        }
        case ROW_CHARACTER: {
            // R53: the Character Subtable resolves here -
            // a classed NPC party (DMG p.176)
            e.party = rollCharacterParty(dice, dungeonLevel, mlv);
            e.isParty = true;
            e.key = "character_party";
            e.count = e.party.size();
            return e;
        }
        case ROW_NONE:
        default:
            return e;    // NO ENCOUNTER (Monster Level X 81-00)
        }

        // DMG advice: ignore & re-roll
        d20     = 1 + (int)dice.roll(1, 20, 0);
        pctile  = 1 + (int)dice.roll(1, 100, 0) - 1;
        pctile2 = 1 + (int)dice.roll(1, 100, 0) - 1;
    }
    return e;
}

namespace {
void pushUnique(std::vector<std::string>& v, const char* key) {
    std::string k(key);
    for (const auto& s : v) if (s == k) return;
    v.push_back(k);
}
} // namespace

std::vector<std::string> encounterKeys(
        const monsters::MonsterRegistry& reg, int dungeonLevel) {
    std::vector<std::string> out;
    int band = dungeonLevel < 1 ? 0
             : dungeonLevel >= 16 ? 11 : dungeonLevel - 1;
    const auto& row = matrixView()[band];
    for (int i = 0; i < 10; ++i) {
        if (row[i].lo <= 0) continue;
        int mlv = i + 1;
        size_t count = 0;
        const Row* t = levelTable(mlv, count);
        for (size_t r = 0; r < count; ++r) {
            const Row* rw = &t[r];
            if (rw->kind == ROW_MONSTER) {
                std::string key = rw->key;
                if (key == "REROLL") continue;
                if (key == "HILL_STONE") {
                    pushUnique(out, listView("hill_stone")[0].c_str());
                    pushUnique(out, listView("hill_stone")[1].c_str());
                    continue;
                }
                if (key == "FIRE_FROST") {
                    pushUnique(out, listView("fire_frost")[0].c_str());
                    pushUnique(out, listView("fire_frost")[1].c_str());
                    continue;
                }
                if (key == "PIERCER") {
                    for (int p = 0; p < 4; ++p)
                        pushUnique(out, listView("piercers")[p].c_str());
                    continue;
                }
                if (reg.find(key)) pushUnique(out, key.c_str());
            } else if (rw->kind == ROW_HYDRA) {
                if (reg.find(rw->key)) pushUnique(out, rw->key.c_str());
            } else if (rw->kind == ROW_DRAGON) {
                size_t dc = 0;
                const DragonRow* dt = dragonTable(mlv, dc);
                for (size_t d = 0; d < dc; ++d)
                    if (reg.find(dt[d].key)) pushUnique(out, dt[d].key.c_str());
            } else if (rw->kind == ROW_ELEMENTAL) {
                for (int el = 0; el < 4; ++el)
                    if (reg.find(listView("elementals")[el]))
                        pushUnique(out, listView("elementals")[el].c_str());
            } else if (rw->kind == ROW_PRINCE) {
                for (int p = 0; p < 4; ++p)
                    if (reg.find(kPrinces[p])) pushUnique(out, kPrinces[p]);
                for (int p = 0; p < 4; ++p)
                    if (reg.find(kArchDevils[p])) pushUnique(out, kArchDevils[p]);
            } else if (rw->kind == ROW_HUMAN) {
                if (reg.find("bandit")) pushUnique(out, "bandit");
                if (reg.find("berserker")) pushUnique(out, "berserker");
            }
        }
    }
    return out;
}

// ----------------------------------------------------------------------------
// R53: the Character Subtable (DMG p.176), verbatim ranges and
// per-profession maxima. The engine's four classes absorb the
// rest per the book's closest-approximation advice.
// ----------------------------------------------------------------------------
namespace {

struct ProfRow { int lo, hi, max; };   // subtable percentile + max/party

enum ProfId {
    PROF_CLERIC, PROF_DRUID, PROF_FIGHTER, PROF_PALADIN, PROF_RANGER,
    PROF_MU, PROF_ILLUSIONIST, PROF_THIEF, PROF_ASSASSIN, PROF_MONK_BARD,
    PROF_COUNT
};

// 01-17 Cleric / 18-20 Druid / 21-60 Fighter / 61-62 Paladin /
// 63-65 Ranger / 66-86 Magic-user / 87-88 Illusionist /
// 89-98 Thief / 99 Assassin / 00 Monk or Bard
const ProfRow kProfTable[PROF_COUNT] = {
    {  1, 17, 3},   // cleric
    { 18, 20, 2},   // druid
    { 21, 60, 5},   // fighter
    { 61, 62, 2},   // paladin
    { 63, 65, 2},   // ranger
    { 66, 86, 3},   // magic-user
    { 87, 88, 1},   // illusionist
    { 89, 98, 4},   // thief
    { 99, 99, 2},   // assassin
    {100,100, 1},   // monk or bard
};

int profFor(int pctile) {
    for (int i = 0; i < PROF_COUNT; ++i)
        if (pctile >= kProfTable[i].lo && pctile <= kProfTable[i].hi)
            return i;
    return PROF_FIGHTER;
}

// engine class per profession (closest approximation, DMG advice)
int classForProf(int prof) {
    switch (prof) {
        case PROF_CLERIC:
        case PROF_DRUID:        return rules::CLASS_CLERIC;
        case PROF_MU:
        case PROF_ILLUSIONIST:  return rules::CLASS_MAGIC_USER;
        case PROF_THIEF:
        case PROF_ASSASSIN:     return rules::CLASS_THIEF;
        case PROF_MONK_BARD:    return rules::CLASS_THIEF;   // bard
        default:                return rules::CLASS_FIGHTER; // fighter/
    }                           // paladin/ranger/monk
}

// DMG p.176: character level = dungeon or monster level, whichever
// is greater, through the 4th; thereafter d6+6 adjusted toward the
// dungeon level (not to exceed 12 unless the dungeon is 16th+).
int characterLevelFor(rules::Dice& dice, int dungeonLevel,
                      int monsterLevel) {
    int base = dungeonLevel > monsterLevel ? dungeonLevel : monsterLevel;
    if (base < 1) base = 1;
    if (base <= 4) return base;
    int lvl = 6 + (int)dice.roll(1, 6, 0);       // 7-12
    if (lvl > dungeonLevel)      --lvl;
    else if (lvl < dungeonLevel) ++lvl;
    if (lvl > 12 && dungeonLevel < 16) lvl = 12;
    return lvl;
}

// DMG p.176: henchman level = master/3 (fractions below one-half
// round down, else up), plus one level per three master levels
// when the master is above 8th (bonus in whole levels).
int henchmanLevelFor(int masterLevel) {
    int base = (2 * masterLevel + 3) / 6;   // round-to-nearest thirds
    int bonus = masterLevel > 8 ? masterLevel / 3 : 0;
    int lvl = base + bonus;
    return lvl < 1 ? 1 : lvl;
}

// R62: 1e class/race allowances for the fiction layer
bool raceAllowsClass(int race, int classIndex) {
    switch (race) {
        case RACE_DWARF:
        case RACE_HALFLING:
            return classIndex == rules::CLASS_FIGHTER ||
                   classIndex == rules::CLASS_THIEF;
        case RACE_ELF:
        case RACE_GNOME:
            return classIndex != rules::CLASS_CLERIC;
        case RACE_HALF_ORC:
            return classIndex != rules::CLASS_MAGIC_USER;
        default:
            return true;   // human, half-elf: any class
    }
}

} // namespace

// ----------------------------------------------------------------------------
// R55: DMG p.176-177 party magic items - the level-chance
// ladder and Tables I-IV. Only implementable outcomes carry a
// mechanical effect (weapon/armor/shield/missile pluses); the
// rest of each table (potions, scrolls, rings, staves, wands,
// miscellany) is represented in the fiction but rolls as NONE.
// Table II/III are headed "(d8, d6)": implemented as d8 within a
// half, d6 1-3/4-6 picking the half (a uniform 1-16 reading of
// the two-dice notation).
// ----------------------------------------------------------------------------
namespace {

enum ItemKind { ITEM_NONE, ITEM_WPN, ITEM_RNG, ITEM_ARM, ITEM_SHD,
                ITEM_ARM_SET };   // armor+shield sold as one set

struct ItemRow {
    int kind;   // ItemKind
    int a, b;   // pluses (b = shield plus for ARM_SET rows)
};

// Table I (d20)
const ItemRow kTableI[20] = {
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 1-3
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 4-6
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 7-9
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 10-12
    {ITEM_ARM,1,0},    // 13: leather +1
    {ITEM_SHD,1,0},    // 14: shield +1
    {ITEM_WPN,1,0},    // 15: sword +1
    {ITEM_RNG,1,0},    // 16: 10 arrows +1
    {ITEM_RNG,2,0},    // 17: 4 bolts +2
    {ITEM_WPN,1,0},    // 18: dagger +1 or +2 (+1 taken)
    {ITEM_WPN,2,0},    // 19: javelin +2
    {ITEM_WPN,1,0},    // 20: mace +1
};

// Table II (d8 + d6-half, 16 rows)
const ItemRow kTableII[16] = {
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 1-3
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 4-6
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 7-9
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 10-12
    {ITEM_ARM_SET,1,2},  // 13: chainmail +1, shield +2
    {ITEM_ARM,4,0},      // 14: splint mail +4
    {ITEM_WPN,3,0},      // 15: sword +3
    {ITEM_WPN,2,0},      // 16: crossbow of speed / hammer +2
};

// Table III (d8 + d6-half, 16 rows)
const ItemRow kTableIII[16] = {
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 1-3
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 4-6
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 7-9
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0},                    // 10-11
    {ITEM_ARM_SET,3,2},  // 12: plate +3, shield +2
    {ITEM_SHD,5,0},      // 13: shield +5
    {ITEM_WPN,4,0},      // 14: sword +4, defender
    {ITEM_WPN,3,0},      // 15: mace +3
    {ITEM_WPN,3,0},      // 16: spear +3
};

// Table IV (d12)
const ItemRow kTableIV[12] = {
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 1-3
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 4-6
    {ITEM_NONE,0,0}, {ITEM_NONE,0,0}, {ITEM_NONE,0,0},   // 7-9
    {ITEM_ARM_SET,4,3},  // 10: plate +4, shield +3
    {ITEM_WPN,1,0},      // 11: sword of wounding (+1 to-hit)
    {ITEM_NONE,0,0},     // 12: arrow of slaying
};

const ItemRow& rollTable(rules::Dice& dice, const ItemRow* t, int n,
                        bool halfDice) {
    int row;
    if (halfDice)   // "(d8, d6)": d6 1-3 -> first half, 4-6 second
        row = (int)dice.roll(1, 8, 0) +
              ((int)dice.roll(1, 6, 0) > 3 ? n / 2 : 0) - 1;
    else
        row = (int)dice.roll(1, (uint32_t)n, 0) - 1;
    if (row < 0) row = 0;
    if (row >= n) row = n - 1;
    return t[row];
}

void applyItem(const ItemRow& r, PartyMember& m) {
    switch (r.kind) {
        case ITEM_WPN: if (r.a > m.wpnPlus) m.wpnPlus = r.a; break;
        case ITEM_RNG: if (r.a > m.rngPlus) m.rngPlus = r.a; break;
        case ITEM_ARM: if (r.a > m.armPlus) m.armPlus = r.a; break;
        case ITEM_SHD: if (r.a > m.shdPlus) m.shdPlus = r.a; break;
        case ITEM_ARM_SET:
            if (r.a > m.armPlus) m.armPlus = r.a;
            if (r.b > m.shdPlus) m.shdPlus = r.b;
            break;
        default: break;   // unmodeled device (fiction only)
    }
}

// DMG p.176 level-chance ladder: {level, pctI, nI, pctII, nII,
// pctIII, nIII, pctIV, nIV}. pct -1 = automatic (the printed
// "3 items" rows). Level 13+ uses the 13th row.
const int kLadder[13][9] = {
    { 1,  10, 1,   0, 0,   0, 0,   0, 0},
    { 2,  20, 2,   0, 0,   0, 0,   0, 0},
    { 3,  30, 2,  10, 1,   0, 0,   0, 0},
    { 4,  40, 2,  20, 1,   0, 0,   0, 0},
    { 5,  50, 2,  30, 1,   0, 0,   0, 0},
    { 6,  60, 3,  40, 2,   0, 0,   0, 0},
    { 7,  70, 3,  50, 2,  10, 1,   0, 0},
    { 8,  80, 3,  60, 2,  20, 1,   0, 0},
    { 9,  90, 3,  70, 2,  30, 1,   0, 0},
    {10,  -1, 3,  80, 2,  40, 1,   0, 0},
    {11,  -1, 3,  90, 2,  50, 1,  10, 1},
    {12,  -1, 3,  -1, 2,  60, 1,  20, 1},
    {13,  -1, 3,  -1, 2,  -1, 1,  60, 1},
};

void rollMagicItemsFor(rules::Dice& dice, PartyMember& m) {
    if (m.level < 1) return;   // men-at-arms: hp is all they need
    int li = m.level - 1;
    if (li > 12) li = 12;
    const int* row = kLadder[li];
    for (int t = 0; t < row[2]; ++t)                     // Table I
        if (row[1] < 0 || (int)dice.roll(1, 100, 0) <= row[1])
            applyItem(rollTable(dice, kTableI, 20, false), m);
    for (int t = 0; t < row[4]; ++t)                     // Table II
        if (row[3] < 0 || (int)dice.roll(1, 100, 0) <= row[3])
            applyItem(rollTable(dice, kTableII, 16, true), m);
    for (int t = 0; t < row[6]; ++t)                     // Table III
        if (row[5] < 0 || (int)dice.roll(1, 100, 0) <= row[5])
            applyItem(rollTable(dice, kTableIII, 16, true), m);
    for (int t = 0; t < row[8]; ++t)                     // Table IV
        if (row[7] < 0 || (int)dice.roll(1, 100, 0) <= row[7])
            applyItem(rollTable(dice, kTableIV, 12, false), m);
}

} // namespace

CharacterParty rollCharacterParty(rules::Dice& dice,
                                  int dungeonLevel, int monsterLevel) {
    CharacterParty p;

    // 2-5 characters (d4+1)
    int nChars = 1 + (int)dice.roll(1, 4, 0);

    int perProf[PROF_COUNT] = {0};
    bool hasPaladin = false, hasAssassin = false;

    for (int i = 0; i < nChars; ++i) {
        int prof = PROF_FIGHTER;
        // re-roll contradictions (paladin with assassin) and
        // per-profession maxima (DMG: ignore such rolls)
        for (int attempt = 0; attempt < 24; ++attempt) {
            int pct = (int)dice.roll(1, 100, 0);
            int cand = profFor(pct);
            if (perProf[cand] >= kProfTable[cand].max) continue;
            if ((cand == PROF_ASSASSIN && hasPaladin) ||
                (cand == PROF_PALADIN && hasAssassin)) continue;
            prof = cand;
            break;
        }
        ++perProf[prof];
        if (prof == PROF_PALADIN) hasPaladin = true;
        if (prof == PROF_ASSASSIN) hasAssassin = true;

        PartyMember m;
        m.classIndex = classForProf(prof);
        m.race = rollNpcRace(dice, m.classIndex);   // R62
        m.level = characterLevelFor(dice, dungeonLevel, monsterLevel);
        rollMagicItemsFor(dice, m);   // R55: DMG p.176-177
        p.members.push_back(m);
    }

    // followers round the party out to nine: men-at-arms on
    // dungeon levels 1-3, classed henchmen on 4+
    int followers = 9 - nChars;
    bool menAtArms = dungeonLevel <= 3;
    for (int i = 0; i < followers; ++i) {
        PartyMember m;
        if (menAtArms) {
            // 0-level men: hp is all they need (DMG p.176)
            m.manAtArms = true;
            m.classIndex = rules::CLASS_FIGHTER;   // kit + saves
            m.level = 0;
            m.race = RACE_HUMAN;   // R62: 0-level men
        } else {
            // henchmen: profession by subtable (paladins and
            // party-contradictory assassins re-rolled), level
            // one-third of the master's (rotating assignment)
            int prof = PROF_FIGHTER;
            for (int attempt = 0; attempt < 24; ++attempt) {
                int pct = (int)dice.roll(1, 100, 0);
                int cand = profFor(pct);
                if (cand == PROF_PALADIN) continue;
                if (cand == PROF_ASSASSIN &&
                    (hasAssassin || hasPaladin)) continue;
                if (perProf[cand] >= kProfTable[cand].max) continue;
                prof = cand;
                break;
            }
            m.henchman = true;
            m.classIndex = classForProf(prof);
            // R62: a henchman follows his master's folk when
            // his profession allows it (design fiction)
            {
                int masterRace =
                    p.members[(size_t)(i % nChars)].race;
                m.race = raceAllowsClass(masterRace, m.classIndex)
                       ? masterRace
                       : rollNpcRace(dice, m.classIndex);
            }
            m.level = henchmanLevelFor(
                p.members[(size_t)(i % nChars)].level);
            rollMagicItemsFor(dice, m);   // R55: henchmen too
        }
        p.members.push_back(m);
    }
    return p;
}

// ----------------------------------------------------------------------------
// R156: DMG Appendix P (pp.225-226) - the convention party on the
// spur of the moment. rollCharacterParty rolls the p.176 subtable
// with the R55 magic ladder; THIS generator uses the Appendix P
// tables: caller-chosen classes (the players select in the book),
// the band/option level roll, and the kit from rollMemberMagic -
// the R147 tables, first engine caller. The ability scores stay
// player-side (the encounter party carries combat fields only);
// multi-class level math and alignment curation are player-side.
// ----------------------------------------------------------------------------

CharacterParty rollConventionParty(rules::Dice& dice, int band,
                                   int option,
                                   const int* classIndices,
                                   int count) {
    CharacterParty p;
    if (count < 1) count = 1;
    if (count > 9) count = 9;   // the p.176 nine-member cap
    for (int i = 0; i < count; ++i) {
        appendixp::SpurMember s = appendixp::rollSpurMember(
            dice, band, option, classIndices ? classIndices[i] : 0);
        PartyMember m;
        m.classIndex = s.classIndex;
        m.level = s.level;
        m.armPlus = s.kit.armorPlus;
        m.wpnPlus = s.kit.weaponPlus;
        m.shdPlus = s.kit.shieldPlus;
        m.race = RACE_HUMAN;   // convention default (fiction-only)
        p.members.push_back(m);
    }
    return p;
}

// R62: the p.192 race-check adjective for fiction strings.
const char* npcRaceAdjective(int race) {
    switch (race) {
        case RACE_DWARF:     return "dwarven ";
        case RACE_ELF:       return "elven ";
        case RACE_GNOME:     return "gnomish ";
        case RACE_HALF_ELF:  return "half-elven ";
        case RACE_HALFLING:  return "halfling ";
        case RACE_HALF_ORC:  return "half-orc ";
        default:             return "";   // human
    }
}

// R62: DMG p.192 race check with class-contradiction re-rolls.
int rollNpcRace(rules::Dice& dice, int classIndex) {
    for (int attempt = 0; attempt < 24; ++attempt) {
        int pct = (int)dice.roll(1, 100, 0);
        int race = RACE_HUMAN;
        if      (pct <= 8)  race = RACE_DWARF;
        else if (pct <= 13) race = RACE_ELF;
        else if (pct <= 15) race = RACE_GNOME;
        else if (pct <= 23) race = RACE_HALF_ELF;
        else if (pct <= 25) race = RACE_HALFLING;
        else if (pct <= 30) race = RACE_HALF_ORC;
        if (raceAllowsClass(race, classIndex)) return race;
    }
    return RACE_HUMAN;
}

// R58: DMG p.63 Encounter Reactions - percentile adjusted for
// the spokesman's Charisma, compared to the printed bands. The
// p.63 "loyalty adjustment as if the creature were a henchman" is
// not modeled (documented simplification - the strangers owe
// the party no tracked loyalty). The p.176 Confrontation shift:
// a party that feels weak avoids, negotiates or bluffs (+10).
PartyReaction rollPartyReaction(rules::Dice& dice, int chaAdj,
                                bool npcWeaker) {
    int score = (int)dice.roll(1, 100, 0) + chaAdj;
    if (npcWeaker) score += 10;   // p.176 Confrontation
    if (score <= 5)  return PartyReaction::ViolentlyHostile;
    if (score <= 25) return PartyReaction::Hostile;
    if (score <= 45) return PartyReaction::UncertainNegative;
    if (score <= 55) return PartyReaction::Neutral;
    if (score <= 75) return PartyReaction::UncertainPositive;
    if (score <= 95) return PartyReaction::Friendly;
    return PartyReaction::Enthusiastic;
}

// ----------------------------------------------------------------------------
// R1033: the water encounter tables ride the registry. The retired
// kFreshShallow/kFreshDeep/kSaltShallow/kSaltDeep/kDinoSub (the R60
// underwater set, DMG Appendix C Premium reprint p.179-181,
// OCR-verified) and kWaterFreshSmall/kWaterFreshLarge/
// kWaterSaltShallow/kWaterSaltDeep (the R127 waterborne set,
// line-diffed against the 1eonline.info Appendix C compilation)
// were extracted verbatim into content/tables/encounters_water/*.lua
// and load through dm::EncounterTableRegistry (see encReg() above).
// The provenance notes moved with the data: footnote clime gates
// (* cool only / ** warm only) are the lua flags column, the
// fresh-water Dinosaur warm gate rides the parent row (the R60
// convention), and the substitutions (Koalinth -> hobgoblin,
// Kopoacinth -> gargoyle, Lacedon -> ghoul, Elf (aquatic) -> elf,
// Pirate -> buccaneer / caveman, Mermaid -> merman, the R61 whale
// size mapping) are transcribed in-row there, as are the two
// as-printed nixie clime discrepancies (book-verify debt).
// Counts still come from the registry's noAppearing fields (the
// book prints no number columns for either set). The roll paths,
// key companions and band edges below are behavior-identical to
// the retired arrays - the R127 line-diff audit and the R1033
// battery fragment pin the parity. tools/r1033_splice.py is the
// only writer of the lua; this seam is its reader.
// ----------------------------------------------------------------------------

namespace {

enum WaterFlagBits { WF_NONE = 0, WF_COOL_ONLY = 1, WF_WARM_ONLY = 2,
                     WF_DEEP_ONLY = 4 };

struct WaterRow { int lo, hi; std::string key; int flags; };

// registry-backed views, built once (the R1032 misc-engine shape)
static const std::vector<WaterRow>& waterView(const char* name) {
    static std::map<std::string, std::vector<WaterRow>> m;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        for (const char* n : { "underwater_fresh_shallow",
                               "underwater_fresh_deep",
                               "underwater_salt_shallow",
                               "underwater_salt_deep",
                               "dinosaur_sub",
                               "waterborne_fresh_small",
                               "waterborne_fresh_large",
                               "waterborne_salt_shallow",
                               "waterborne_salt_deep" }) {
            const auto& rs = encReg().waterRows(n);
            std::vector<WaterRow> rows;
            for (const auto& r : rs)
                rows.push_back(WaterRow{ r.lo, r.hi, r.key, r.flags });
            m[n] = rows;
        }
    }
    static const std::vector<WaterRow> none;
    auto it = m.find(name);
    return it == m.end() ? none : it->second;
}

// the R60 underwater selector: fresh/salt x shallow/deep
static const char* underwaterTableName(WaterBody body,
                                        WaterDepth depth) {
    if (body == WaterBody::FRESH)
        return depth == WaterDepth::SHALLOW
            ? "underwater_fresh_shallow" : "underwater_fresh_deep";
    return depth == WaterDepth::SHALLOW
        ? "underwater_salt_shallow" : "underwater_salt_deep";
}

// the R127 waterborne selector: the fresh body size rides the
// depth enum (SHALLOW = small body, DEEP = large body)
static const char* waterborneTableName(WaterBody body,
                                       WaterDepth depth) {
    if (body == WaterBody::FRESH)
        return depth == WaterDepth::SHALLOW
            ? "waterborne_fresh_small" : "waterborne_fresh_large";
    return depth == WaterDepth::SHALLOW
        ? "waterborne_salt_shallow" : "waterborne_salt_deep";
}

} // namespace

// R60: the underwater roll - see encounters.h.
DungeonEncounter rollWaterEncounter(
        const monsters::MonsterRegistry& reg, rules::Dice& dice,
        int pctile, int pctile2,
        WaterBody body, WaterDepth depth, WaterClime clime) {
    DungeonEncounter e;

    const std::vector<WaterRow>& t =
        waterView(underwaterTableName(body, depth));

    for (int attempt = 0; attempt < 24; ++attempt) {
        const WaterRow* row = nullptr;
        for (const auto& r : t)
            if (pctile >= r.lo && pctile <= r.hi) { row = &r; break; }
        if (!row) return e;

        // footnote clime gates (DMG: "otherwise roll again")
        bool ok = true;
        if ((row->flags & WF_COOL_ONLY) && clime == WaterClime::WARM)
            ok = false;
        if ((row->flags & WF_WARM_ONLY) && clime == WaterClime::COOL)
            ok = false;

        std::string key = row->key;
        if (ok && key == "DINOSAUR") {
            const WaterRow* dr = nullptr;
            const auto& ds = waterView("dinosaur_sub");
            for (const auto& d : ds)
                if (pctile2 >= d.lo && pctile2 <= d.hi)
                    { dr = &d; break; }
            if (!dr) return e;    // subtable covers 01-00; defensive
            // Dinosaur Subtable *: deep water only (dinichthys)
            if ((dr->flags & WF_DEEP_ONLY) && depth == WaterDepth::SHALLOW)
                ok = false;
            else
                key = dr->key;
        }

        if (ok) {
            const monsters::MonsterDef* def = reg.find(key);
            if (def) {
                e.key = key;
                // numbers per MONSTER MANUAL (registry noAppearing;
                // 0/0 falls back to a single specimen)
                if (def->noAppearingMin > 0) {
                    int lo = def->noAppearingMin;
                    int hi = def->noAppearingMax < lo
                           ? lo : def->noAppearingMax;
                    e.count = (lo == hi)
                        ? lo
                        : lo + (int)dice.roll(1,
                                (uint32_t)(hi - lo + 1), 0) - 1;
                } else {
                    e.count = 1;
                }
                return e;
            }
        }

        // DMG advice: ignore & re-roll
        pctile  = 1 + (int)dice.roll(1, 100, 0) - 1;
        pctile2 = 1 + (int)dice.roll(1, 100, 0) - 1;
    }
    return e;
}

std::vector<std::string> waterEncounterKeys(
        const monsters::MonsterRegistry& reg,
        WaterBody body, WaterDepth depth) {
    std::vector<std::string> out;
    const std::vector<WaterRow>& t =
        waterView(underwaterTableName(body, depth));
    for (const auto& r : t) {
        std::string key = r.key;
        if (key == "DINOSAUR") {
            for (const auto& d : waterView("dinosaur_sub"))
                if (reg.find(d.key))
                    pushUnique(out, d.key.c_str());
        } else if (reg.find(key)) {
            pushUnique(out, key.c_str());
        }
    }
    return out;
}

// R127: the waterborne roll - see encounters.h.
DungeonEncounter rollWaterborneEncounter(
        const monsters::MonsterRegistry& reg, rules::Dice& dice,
        int pctile, int pctile2,
        WaterBody body, WaterDepth depth, WaterClime clime) {
    DungeonEncounter e;

    const std::vector<WaterRow>& t =
        waterView(waterborneTableName(body, depth));

    for (int attempt = 0; attempt < 24; ++attempt) {
        const WaterRow* row = nullptr;
        for (const auto& r : t)
            if (pctile >= r.lo && pctile <= r.hi)
                { row = &r; break; }
        if (!row) return e;

        // footnote clime gates (DMG: "otherwise roll again")
        bool ok = true;
        if ((row->flags & WF_COOL_ONLY) && clime == WaterClime::WARM)
            ok = false;
        if ((row->flags & WF_WARM_ONLY) && clime == WaterClime::COOL)
            ok = false;

        std::string key = row->key;
        if (ok && key == "DINOSAUR") {
            const WaterRow* dr = nullptr;
            const auto& ds = waterView("dinosaur_sub");
            for (const auto& d : ds)
                if (pctile2 >= d.lo && pctile2 <= d.hi)
                    { dr = &d; break; }
            if (!dr) return e;    // subtable covers 01-00; defensive
            // Dinosaur Subtable *: deep water only (dinichthys)
            if ((dr->flags & WF_DEEP_ONLY)
                && depth == WaterDepth::SHALLOW)
                ok = false;
            else
                key = dr->key;
        }

        if (ok) {
            const monsters::MonsterDef* def = reg.find(key);
            if (def) {
                e.key = key;
                // numbers per MONSTER MANUAL (registry
                // noAppearing; 0/0 falls back to a single
                // specimen)
                if (def->noAppearingMin > 0) {
                    int lo = def->noAppearingMin;
                    int hi = def->noAppearingMax < lo
                           ? lo : def->noAppearingMax;
                    e.count = (lo == hi)
                        ? lo
                        : lo + (int)dice.roll(1,
                                (uint32_t)(hi - lo + 1), 0) - 1;
                } else {
                    e.count = 1;
                }
                return e;
            }
        }

        // DMG advice: ignore & re-roll
        pctile  = 1 + (int)dice.roll(1, 100, 0) - 1;
        pctile2 = 1 + (int)dice.roll(1, 100, 0) - 1;
    }
    return e;
}

// Every registry key the waterborne table can produce - the
// regtest-style companion of rollWaterborneEncounter.
std::vector<std::string> waterborneEncounterKeys(
        const monsters::MonsterRegistry& reg,
        WaterBody body, WaterDepth depth) {
    std::vector<std::string> out;
    const std::vector<WaterRow>& t =
        waterView(waterborneTableName(body, depth));
    for (const auto& r : t) {
        std::string key = r.key;
        if (key == "DINOSAUR") {
            for (const auto& d : waterView("dinosaur_sub"))
                if (reg.find(d.key))
                    pushUnique(out, d.key.c_str());
        } else if (reg.find(key)) {
            pushUnique(out, key.c_str());
        }
    }
    return out;
}

// R127: the printed band edges - see encounters.h.
std::vector<WaterborneBand> waterborneBands(
        WaterBody body, WaterDepth depth) {
    std::vector<WaterborneBand> out;
    for (const auto& r : waterView(waterborneTableName(body, depth))) {
        WaterborneBand b;
        b.key = r.key;
        b.lo  = r.lo;
        b.hi  = r.hi;
        b.flags = r.flags;
        out.push_back(b);
    }
    return out;
}

// The shared p.190 Dinosaur Subtable - see encounters.h.
std::vector<WaterborneBand> dinosaurSubBands() {
    std::vector<WaterborneBand> out;
    for (const auto& r : waterView("dinosaur_sub")) {
        WaterborneBand b;
        b.key = r.key;
        b.lo  = r.lo;
        b.hi  = r.hi;
        b.flags = r.flags;
        out.push_back(b);
    }
    return out;
}

// ----------------------------------------------------------------------------
// R1034: the outdoor (wilderness) encounter tables ride the registry.
// The retired kOutArctic..kOutTropical climate tables, the eleven
// SUB_* terrain subtables, the six pick-set arrays and the tropical
// Sphinx footnote (all R63, DMG Appendix C Premium reprint p.182-191,
// OCR-verified against the uploaded DMG; the five 1eonline.info-
// carried climates line-diffed band-for-band at R126) were extracted
// verbatim into content/tables/encounters_outdoor/*.lua and load
// through dm::EncounterTableRegistry (see encReg() above). The
// provenance record: eight climate tables, each creature-major across
// eight terrain columns (Plain, Scrub, Forest, Rough - ruins within
// five miles per the book footnote - Desert, Hills, Mountains,
// Marsh); the subtables resolve on the second percentile against the
// same terrain column; the tropical Sphinx footnote is the single-
// column p.189 subtable (replicated across the eight columns in the
// registry def - it is terrain-independent); the pick-sets resolve on
// the second percentile modulo set size, Porcupine/Skunk mapping to
// the giant varieties. The DMG prints no number columns ("the numbers
// of monsters encountered are those shown in MONSTER MANUAL"), so
// counts come from the registry's noAppearing fields, as in R60/R1033.
// Substitutions documented at R63 and transcribed in-row in the lua:
// Men tribesmen -> caveman and nomad -> dervish, brigand -> bandit,
// Camel -> wild_camel, Misc reptiles -> giant_lizard (book fn *),
// "Pterodactyl, small" -> pteranodon, Nothosaurus -> megalosaurus
// (book fn **), Treant -> treant_mature_middle_aged, Titan -> titan.
// The OCR folds are pinned in-row by the data (sub-arctic marsh
// caveman 56-65, inhabited ghast, tropical bandit mountains 23-30,
// the dropped tropical dervish mountain/marsh duplicates, Faerie
// giant boar forest 09-12, temperate wild giant eagle plain 15-16,
// tropical dervish hills 46-47, Dragon subtable chimera forest
// 23-30, Giant subtable stone giant hills 82-98, Lycanthrope
// wereboar, Undead ghast, Men subtable marsh pilgrim 36-50 and
// tribesman 51-00, temperate wild scrub Humanoid 26-32, tropical
// rough giant scorpion 84-85). The Men Subtable Character row
// resolves as a character party of levels 7-10 per the p.187
// wilderness note: rollCharacterParty(dice, 8, 8). The roll paths,
// key companions and band edges below are behavior-identical to the
// retired arrays - the R126 line-diff audit and the R1034 battery
// fragment pin the parity. tools/r1034_splice.py is the only writer
// of the lua; this seam is its reader.
// ----------------------------------------------------------------------------

namespace {

struct OutdoorRow {
    std::string key;   // registry key, SUB_* / *_SET pseudo-key
    short lo[8];       // per-terrain percentile low (-1 = no entry)
    short hi[8];       // per-terrain percentile high (-1 = no entry)
};

// registry-backed views, built once (the R1032 misc-engine shape)
static const std::vector<OutdoorRow>& outdoorView(const char* name) {
    static std::map<std::string, std::vector<OutdoorRow>> m;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        for (const char* n : { "outdoor_arctic",
                               "outdoor_sub_arctic",
                               "outdoor_temperate_wild",
                               "outdoor_temperate_inhabited",
                               "outdoor_faerie",
                               "outdoor_pleistocene",
                               "outdoor_dinosaur_age",
                               "outdoor_tropical",
                               "outdoor_sub_demihuman",
                               "outdoor_sub_dragon",
                               "outdoor_sub_frog",
                               "outdoor_sub_giant",
                               "outdoor_sub_humanoid",
                               "outdoor_sub_lycanthrope",
                               "outdoor_sub_men",
                               "outdoor_sub_snake",
                               "outdoor_sub_sphinx",
                               "outdoor_sub_spider",
                               "outdoor_sub_undead",
                               "outdoor_sphinx_t" }) {
            const auto& rs = encReg().outdoorRows(n);
            std::vector<OutdoorRow> rows;
            for (const auto& r : rs) {
                OutdoorRow row;
                row.key = r.key;
                for (int c = 0; c < 8; ++c) {
                    row.lo[c] = (short)r.lo[c];
                    row.hi[c] = (short)r.hi[c];
                }
                rows.push_back(row);
            }
            m[n] = rows;
        }
    }
    static const std::vector<OutdoorRow> none;
    auto it = m.find(name);
    return it == m.end() ? none : it->second;
}

// the six pick-sets (registry lists; the retired kOut*Set arrays)
static const std::vector<std::string>& outdoorSet(const char* set) {
    static std::map<std::string, std::vector<std::string>> m;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        for (const char* s : { "ki_rin_set", "leprechaun_set",
                               "porcupine_set", "iguanodon_set",
                               "lammasu_set", "wolf_dog_set" })
            m[s] = encReg().list(s);
    }
    static const std::vector<std::string> none;
    auto it = m.find(set);
    return it == m.end() ? none : it->second;
}

// R63: the climate selector (OutdoorClime -> registry table name)
static const char* outdoorTableName(OutdoorClime clime) {
    switch (clime) {
        case OC_ARCTIC:              return "outdoor_arctic";
        case OC_SUB_ARCTIC:          return "outdoor_sub_arctic";
        case OC_TEMPERATE_WILD:      return "outdoor_temperate_wild";
        case OC_TEMPERATE_INHABITED: return "outdoor_temperate_inhabited";
        case OC_FAERIE:              return "outdoor_faerie";
        case OC_PLEISTOCENE:         return "outdoor_pleistocene";
        case OC_DINOSAUR_AGE:        return "outdoor_dinosaur_age";
        case OC_TROPICAL:            return "outdoor_tropical";
    }
    return nullptr;
}

// R63: the terrain-column subtable selector (SUB_* -> table name)
static const char* outdoorSubName(const std::string& subKey) {
    if      (subKey == "SUB_DEMIHUMAN")   return "outdoor_sub_demihuman";
    else if (subKey == "SUB_DRAGON")      return "outdoor_sub_dragon";
    else if (subKey == "SUB_FROG")        return "outdoor_sub_frog";
    else if (subKey == "SUB_GIANT")       return "outdoor_sub_giant";
    else if (subKey == "SUB_HUMANOID")    return "outdoor_sub_humanoid";
    else if (subKey == "SUB_LYCANTHROPE") return "outdoor_sub_lycanthrope";
    else if (subKey == "SUB_MEN")         return "outdoor_sub_men";
    else if (subKey == "SUB_SNAKE")       return "outdoor_sub_snake";
    else if (subKey == "SUB_SPHINX")      return "outdoor_sub_sphinx";
    else if (subKey == "SUB_SPIDER")      return "outdoor_sub_spider";
    else if (subKey == "SUB_UNDEAD")      return "outdoor_sub_undead";
    return nullptr;
}

} // namespace

// Resolve a main-table row (or Men-subtable row) at the terrain
// column: returns the registry key, or handles SUB_* dispatch and
// pick-sets. isParty set for the Men Character row. False return
// means no encounter (defensive; every printed column covers 01-00).
static bool resolveOutdoorKey(const OutdoorRow* row, int terrain,
                              int pctile2, std::string& key) {
    (void)terrain;   // sets don't vary by terrain
    key = row->key;
    if      (key == "KI_RIN_SET") {
        const auto& s = outdoorSet("ki_rin_set");
        key = s[pctile2 % s.size()];
    }
    else if (key == "LEPRECHAUN_SET") {
        const auto& s = outdoorSet("leprechaun_set");
        key = s[pctile2 % s.size()];
    }
    else if (key == "PORCUPINE_SET") {
        const auto& s = outdoorSet("porcupine_set");
        key = s[pctile2 % s.size()];
    }
    else if (key == "IGUANODON_SET") {
        const auto& s = outdoorSet("iguanodon_set");
        key = s[pctile2 % s.size()];
    }
    else if (key == "LAMMASU_SET") {
        const auto& s = outdoorSet("lammasu_set");
        key = s[pctile2 % s.size()];
    }
    else if (key == "WOLF_DOG_SET") {
        const auto& s = outdoorSet("wolf_dog_set");
        key = s[pctile2 % s.size()];
    }
    else if (key == "MISC_REPTILE")    key = "giant_lizard";
    else if (key == "SUB_SPHINX_T") {
        // tropical footnote: single-column Sphinx Subtable (p.189),
        // replicated across the terrain columns in the registry def
        for (const auto& r : outdoorView("outdoor_sphinx_t"))
            if (r.lo[0] >= 0 && pctile2 >= r.lo[0]
                && pctile2 <= r.hi[0]) { key = r.key; break; }
    } else if (key.size() > 4 && key.compare(0, 4, "SUB_") == 0) {
        // terrain-column subtable, resolved on pctile2
        const char* subName = outdoorSubName(key);
        const std::vector<OutdoorRow>* sub = nullptr;
        if (subName) sub = &outdoorView(subName);
        if (!sub) return false;
        const OutdoorRow* sr = nullptr;
        for (const auto& r : *sub)
            if (r.lo[terrain] >= 0 &&
                pctile2 >= r.lo[terrain] && pctile2 <= r.hi[terrain])
                { sr = &r; break; }
        if (!sr) return false;
        return resolveOutdoorKey(sr, terrain, pctile2, key);
    }
    return true;
}

// The registry keys one climate/terrain column can produce - the
// regtest-style companion of rollOutdoorEncounter.
static void pushOutKeys(std::vector<std::string>& out,
                        const monsters::MonsterRegistry& reg,
                        const std::vector<OutdoorRow>& t, int terrain) {
    for (const auto& row : t) {
        if (row.lo[terrain] < 0) continue;
        const std::string& key = row.key;
        if (key == "SUB_CHARACTER") { pushUnique(out, "character_party"); continue; }
        if (key == "MISC_REPTILE")  { pushUnique(out, "giant_lizard"); continue; }
        if (key == "KI_RIN_SET") {
            for (const auto& k : outdoorSet("ki_rin_set")) pushUnique(out, k.c_str());
            continue;
        }
        if (key == "LEPRECHAUN_SET") {
            for (const auto& k : outdoorSet("leprechaun_set")) pushUnique(out, k.c_str());
            continue;
        }
        if (key == "PORCUPINE_SET") {
            for (const auto& k : outdoorSet("porcupine_set")) pushUnique(out, k.c_str());
            continue;
        }
        if (key == "IGUANODON_SET") {
            for (const auto& k : outdoorSet("iguanodon_set")) pushUnique(out, k.c_str());
            continue;
        }
        if (key == "LAMMASU_SET") {
            for (const auto& k : outdoorSet("lammasu_set")) pushUnique(out, k.c_str());
            continue;
        }
        if (key == "WOLF_DOG_SET") {
            for (const auto& k : outdoorSet("wolf_dog_set")) pushUnique(out, k.c_str());
            continue;
        }
        if (key == "SUB_SPHINX_T") {
            for (const auto& r : outdoorView("outdoor_sphinx_t"))
                pushUnique(out, r.key.c_str());
            continue;
        }
        if (key.size() > 4 && key.compare(0, 4, "SUB_") == 0) {
            const char* subName = outdoorSubName(key);
            if (subName) pushOutKeys(out, reg, outdoorView(subName), terrain);
            continue;
        }
        if (reg.find(key)) pushUnique(out, key.c_str());
    }
}

// R63: the outdoor roll - see encounters.h.
DungeonEncounter rollOutdoorEncounter(
        const monsters::MonsterRegistry& reg, rules::Dice& dice,
        int pctile, int pctile2,
        OutdoorClime clime, OutdoorTerrain terrain) {
    DungeonEncounter e;

    const char* tn = outdoorTableName(clime);
    if (!tn) return e;
    const std::vector<OutdoorRow>& t = outdoorView(tn);
    int ti = (int)terrain;

    for (int attempt = 0; attempt < 24; ++attempt) {
        const OutdoorRow* row = nullptr;
        for (const auto& r : t)
            if (r.lo[ti] >= 0 &&
                pctile >= r.lo[ti] && pctile <= r.hi[ti])
                { row = &r; break; }
        if (!row) return e;   // defensive: columns cover 01-00

        std::string key;
        if (!resolveOutdoorKey(row, ti, pctile2, key)) return e;

        if (key == "SUB_CHARACTER") {
            // Men Subtable Character row - wilderness character
            // party, levels 7-10 (p.187 note)
            e.party = rollCharacterParty(dice, 8, 8);
            e.isParty = true;
            e.key = "character_party";
            e.count = e.party.size();
            return e;
        }

        const monsters::MonsterDef* def = reg.find(key);
        if (def) {
            e.key = key;
            // numbers per MONSTER MANUAL (registry noAppearing;
            // 0/0 falls back to a single specimen)
            if (def->noAppearingMin > 0) {
                int lo = def->noAppearingMin;
                int hi = def->noAppearingMax < lo ? lo : def->noAppearingMax;
                e.count = (lo == hi)
                    ? lo
                    : lo + (int)dice.roll(1, (uint32_t)(hi - lo + 1), 0) - 1;
            } else {
                e.count = 1;
            }
            return e;
        }

        // DMG advice: ignore & re-roll
        pctile  = 1 + (int)dice.roll(1, 100, 0) - 1;
        pctile2 = 1 + (int)dice.roll(1, 100, 0) - 1;
    }
    return e;
}

std::vector<std::string> outdoorEncounterKeys(
        const monsters::MonsterRegistry& reg,
        OutdoorClime clime, OutdoorTerrain terrain) {
    std::vector<std::string> out;
    const char* tn = outdoorTableName(clime);
    if (tn) pushOutKeys(out, reg, outdoorView(tn), (int)terrain);
    return out;
}

namespace {

// R126: the subtable matrix behind a SUB_* pseudo-key (see
// encounters.h; the tropical Sphinx Subtable is single-column
// and never reaches here - outdoorSubBands handles it before
// the lookup).
const std::vector<OutdoorRow>& outSub(const std::string& subKey) {
    const char* n = nullptr;
    if      (subKey == "SUB_DEMIHUMAN")   n = "outdoor_sub_demihuman";
    else if (subKey == "SUB_DRAGON")      n = "outdoor_sub_dragon";
    else if (subKey == "SUB_FROG")        n = "outdoor_sub_frog";
    else if (subKey == "SUB_GIANT")       n = "outdoor_sub_giant";
    else if (subKey == "SUB_HUMANOID")    n = "outdoor_sub_humanoid";
    else if (subKey == "SUB_LYCANTHROPE") n = "outdoor_sub_lycanthrope";
    else if (subKey == "SUB_MEN")         n = "outdoor_sub_men";
    else if (subKey == "SUB_SNAKE")       n = "outdoor_sub_snake";
    else if (subKey == "SUB_SPHINX")      n = "outdoor_sub_sphinx";
    else if (subKey == "SUB_SPIDER")      n = "outdoor_sub_spider";
    else if (subKey == "SUB_UNDEAD")      n = "outdoor_sub_undead";
    static const std::vector<OutdoorRow> none;
    return n ? outdoorView(n) : none;
}

// R126: band order comparator (lo ascending)
static bool outBandLess(const OutdoorBand& x,
                        const OutdoorBand& y) {
    return x.lo < y.lo;
}

// R126: collect a column's bands, low-ascending
static void pushBands(std::vector<OutdoorBand>& out,
                      const std::vector<OutdoorRow>& t, int ti) {
    for (const auto& r : t) {
        if (r.lo[ti] < 0) continue;
        OutdoorBand b;
        b.key = r.key;
        b.lo  = r.lo[ti];
        b.hi  = r.hi[ti];
        out.push_back(b);
    }
    std::stable_sort(out.begin(), out.end(), outBandLess);
}

} // namespace

// R126: the printed band edges behind the tables - see
// encounters.h.
std::vector<OutdoorBand> outdoorBands(
        OutdoorClime clime, OutdoorTerrain terrain) {
    std::vector<OutdoorBand> out;
    const char* tn = outdoorTableName(clime);
    if (tn) pushBands(out, outdoorView(tn), (int)terrain);
    return out;
}

std::vector<OutdoorBand> outdoorSubBands(
        const std::string& subKey, OutdoorTerrain terrain) {
    std::vector<OutdoorBand> out;
    if (subKey == "SUB_SPHINX_T") {
        // tropical footnote: single-column Sphinx Subtable
        // (p.189) - 01-10/11-40/41-70/71-00, replicated across
        // the terrain columns in the registry def
        pushBands(out, outdoorView("outdoor_sphinx_t"), (int)terrain);
        return out;
    }
    pushBands(out, outSub(subKey), (int)terrain);
    return out;
}

// ----------------------------------------------------------------------------
// R64: the CITY/TOWN ENCOUNTER MATRIX - DMG Appendix C (Premium
// reprint p.190-192, OCR-verified against the uploaded DMG). One
// matrix, two percentile columns (daytime / nighttime; several
// rows are night-only, marked "-" in the book). Asterisked types
// (assassin, city guard, cleric, druid, fighter, illusionist,
// magic-user, ranger, thief) roll the p.191 race check -
// rollNpcRace (R62); unasterisked classed types are human (1e
// class restrictions: paladin, monk, rake, city watch, city
// official). Classed and service encounters resolve as
// character parties built to the p.191-192 explanations; the
// civilian fictions (beggar, drunk, goodwife, harlot, laborer,
// peddler, gentleman, noble, mercenary, merchant, pilgrim,
// press gang, ruffian, tradesman, bard) carry printed counts
// but no bestiary entry - their flavor subtables are
// fiction the engine models only in part: the harlot type
// (p.192) and drunk-of-what-type (p.191) tables are
// pinned R146 (cityHarlotKind / cityDrunkKind); the
// noble gender coin, the noblewoman sedan-chair detail
// and the ruffian 1-in-4 half-orc/humanoid note are
// pinned R174 (cityNobleKind / cityNoblewomanSedan /
// cityRuffianKind). Numbers are the printed
// encounter numbers, not the registry's wilderness-scale
// noAppearing (bandit registry 20-200 vs. printed night 3-12;
// giant rat registry 5-50 vs. printed 2-8 day / 4-24 night).
// "Demon or Nycadaemon (60%/40%)" and "Devil or Mezzadaemon
// (50%/50%)" re-roll per the R52 mezzodaemon/nycadaemon
// precedent and the book's own advice ("they may be ignored
// entirely if desirable", p.191). The lich half of "Vampire or
// Lich (75%/25%)" and the ghast half of "Ghoul or Ghast
// (30%/70%)" take the ghost treatment - one specimen - where
// the book prints no separate number (lich) or the ghoul's
// 4-16 (ghast, same-as-ghoul per the ghost text). Bard (of
// "Monk or Bard 60%/40%") is a single fiction NPC: the 1e
// bard's dual fighter/thief abilities are unmodeled here.
// Book "Doppleganger" -> doppelganger (MM spelling,
// the bestiary key). OCR defects corrected: night 36 printed "Ghost or Ghoul
// (30%/70%)" is "Ghoul or Ghast" (37 is Ghost; the
// explanations print both ghoul 4-16 and ghast);
// "Wereat" -> Wererat, "Wereiger" -> Weretiger (night 91-93 /
// 94). Day bandits print no number ("a nondescript group being
// seen") - 3-12, the nighttime number, is used, documented.
// City magic (p.192): 1st-or-higher classed city NPCs roll
// the CHANCE PER LEVEL FOR MAGIC ITEM table per category;
// potions, scrolls, rings, wands and misc magic have no
// mechanical effect here (R55 precedent), protection devices
// roll the printed subtable. WIRED SINCE R70 - the city
// streets excursion loop rolls this matrix (game/appstate.h).

namespace {

struct CityRow {
    short loDay, hiDay;      // daytime percentile (-0 = no row)
    short loNight, hiNight;  // nighttime percentile
    const char* key;
};

// CITY/TOWN ENCOUNTER MATRIX (DMG p.191)
static const CityRow kCityMatrix[] = {
{1,1,1,3,"assassin"},
{2,2,4,5,"bandit"},
{3,12,6,8,"beggar"},
{13,13,9,10,"brigand"},
{14,18,11,11,"city_guard"},
{19,21,12,12,"city_official"},
{22,23,13,21,"city_watchman"},
{24,25,22,22,"cleric"},
{0,0,23,23,"demon_or_nycadaemon"},
{0,0,24,24,"devil_or_mezzadaemon"},
{0,0,25,25,"doppelganger"},
{26,26,26,26,"druid"},
{27,27,27,31,"drunk"},
{28,29,32,33,"fighter"},
{30,33,34,35,"gentleman"},
{0,0,36,36,"ghoul_or_ghast"},
{0,0,37,37,"ghost"},
{34,34,38,42,"giant_rat"},
{35,39,43,43,"goodwife"},
{40,41,44,50,"harlot"},
{42,42,51,51,"illusionist"},
{43,50,52,52,"laborer_or_peddler"},
{51,51,53,53,"magic_user"},
{52,55,54,58,"mercenary"},
{56,62,59,60,"merchant"},
{63,63,61,61,"monk_or_bard"},
{0,0,62,62,"night_hag"},
{64,65,63,64,"noble"},
{66,66,65,65,"paladin"},
{67,69,66,66,"pilgrim"},
{70,70,67,67,"press_gang"},
{71,72,68,71,"rake"},
{0,0,72,72,"rakshasa"},
{73,73,73,73,"ranger"},
{74,78,74,80,"ruffian"},
{0,0,81,81,"shadow"},
{0,0,82,82,"spectre"},
{79,82,83,88,"thief"},
{83,97,89,90,"tradesman"},
{98,98,91,93,"wererat"},
{99,99,94,94,"weretiger"},
{100,100,95,96,"werewolf"},
{0,0,97,97,"wight"},
{0,0,98,98,"will_o_wisp"},
{0,0,99,99,"wraith"},
{0,0,100,100,"vampire_or_lich"}
};

// printed encounter numbers for the non-party results
int cityCountFor(rules::Dice& dice, const std::string& key, bool night) {
    (void)night;
    if (key == "bandit" || key == "brigand")
        return 2 + (int)dice.roll(1, 10, 0);          // 3-12 night; day documented
    if (key == "beggar")
        return (int)dice.roll(1, 2, 0);               // 1, possibly 2
    if (key == "doppelganger")
        return 2 + (int)dice.roll(1, 4, 0);           // d4+2 = 3-6
    if (key == "giant_rat")
        return night
            ? 1 + (int)dice.roll(1, 24, 0)            // 4-24 night
            : (int)dice.roll(2, 4, 0);                // 2-8 day
    if (key == "ghoul" || key == "ghast")
        return 4 + (int)dice.roll(1, 13, 0);          // 4-16
    if (key == "drunk")
        return (int)dice.roll(1, 4, 0);               // 1-4 revelers/bums
    if (key == "gentleman")
        return (int)dice.roll(1, 5, 0);               // 1 + 0-4 company
    if (key == "laborer")
        return 2 + (int)dice.roll(1, 11, 0);          // 3-12
    if (key == "peddler")
        return 1;
    if (key == "mercenary")
        return 2 + (int)dice.roll(1, 11, 0);          // 3-12
    if (key == "merchant")
        return (int)dice.roll(1, 3, 0);               // 1-3 (night guards fiction)
    if (key == "bard")
        return 1;
    if (key == "night_hag")
        return (int)dice.roll(1, 2, 0);               // 1-2
    if (key == "noble")
        return 1;
    if (key == "pilgrim")
        return 2 + (int)dice.roll(1, 11, 0);          // 3-12
    if (key == "press_gang")
        return 1 + (int)dice.roll(1, 16, 0);          // 2-16
    if (key == "rakshasa")
        return (int)dice.roll(1, 3, 0);               // 1-3
    if (key == "ruffian")
        return 6 + (int)dice.roll(1, 6, 0);           // d6+6 = 7-12
    if (key == "shadow")
        return 2 + (int)dice.roll(1, 7, 0);           // 2-8
    if (key == "spectre")
        return (int)dice.roll(1, 3, 0);               // 1-3
    if (key == "tradesman")
        return (int)dice.roll(2, 4, 0);               // 2-8
    if (key == "wererat")
        return 2 + (int)dice.roll(1, 4, 0);           // 2-5
    if (key == "weretiger")
        return (int)dice.roll(1, 2, 0);               // 1-2
    if (key == "werewolf")
        return 2 + (int)dice.roll(1, 4, 0);           // 2-5
    if (key == "wight")
        return 2 + (int)dice.roll(1, 4, 0);           // 2-5
    if (key == "will_o_wisp")
        return (int)dice.roll(1, 2, 0);               // 1-2
    if (key == "wraith")
        return (int)dice.roll(1, 4, 0);              // 1-4
    // ghost, ghoul's kin, vampire, lich, doppelganger's kin,
    // goodwife, harlot, paladin-less singles: one specimen
    return 1;
}

// p.192 protection device subtable (the mechanically usable
// outcomes; the amulet of life protection has no mechanical
// effect here - R55 precedent)
enum { PROT_RING1, PROT_RING2, PROT_RING3, PROT_AMULET,
       PROT_BRACERS6, PROT_BRACERS4, PROT_BRACERS2,
       PROT_DISPLACEMENT, PROT_CLOAK1, PROT_CLOAK2, PROT_CLOAK3 };

static int rollProtectionDevice(rules::Dice& dice) {
    int p = (int)dice.roll(1, 100, 0);
    if (p <= 25) return PROT_RING1;
    if (p <= 30) return PROT_RING2;
    if (p == 31) return PROT_RING3;
    if (p == 32) return PROT_AMULET;
    if (p <= 55) return PROT_BRACERS6;
    if (p <= 70) return PROT_BRACERS4;
    if (p <= 75) return PROT_BRACERS2;
    if (p <= 82) return PROT_DISPLACEMENT;
    if (p <= 95) return PROT_CLOAK1;
    if (p <= 99) return PROT_CLOAK2;
    return PROT_CLOAK3;
}

// "The power of the item must be commensurate with the level of
// the possessor" (p.192): +1 at 1st-5th, +2 at 6th-11th, +3 at
// 12th and above (documented approximation, R55's ladder spirit)
static int plusForLevel(int level) {
    if (level >= 12) return 3;
    if (level >= 6)  return 2;
    return 1;
}

} // namespace

// R64: p.192 CHANCE PER LEVEL FOR MAGIC ITEM - one percentile
// roll per category at (chance x level). Group 0: assassin,
// fighter, thief, etc.; group 1: cleric, druid; group 2:
// magic-user. The printed monk column has no engine class
// (monks resolve as fighters per R53) - documented. Potions,
// scrolls, rings, wands/staffs/rods and misc magic exist in
// the fiction but have no mechanical effect here (R55).
static void rollCityMagicItems(rules::Dice& dice, PartyMember& m) {
    if (m.level < 1) return;   // 0-level men: hp is all they need

    int group = (m.classIndex == rules::CLASS_CLERIC) ? 1
              : (m.classIndex == rules::CLASS_MAGIC_USER) ? 2 : 0;

    //                g0   g1   g2   (percent per level)
    const int sword   [3] = { 10,  0,  0 };
    const int miscWpn [3] = {  5, 10,  5 };
    const int armor   [3] = { 10, 10,  0 };
    const int protect [3] = {  2,  2, 10 };

    int lvl = m.level;
    if ((int)dice.roll(1, 100, 0) <= sword[group] * lvl)
        m.wpnPlus = plusForLevel(lvl);
    if ((int)dice.roll(1, 100, 0) <= miscWpn[group] * lvl)
        m.rngPlus = plusForLevel(lvl);
    if ((int)dice.roll(1, 100, 0) <= armor[group] * lvl) {
        m.armPlus = plusForLevel(lvl);
        // "Armor &/or Shield" - the shield is a coin-flip half
        // of the category (documented split)
        if ((int)dice.roll(1, 2, 0) == 2)
            m.shdPlus = plusForLevel(lvl);
    }
    if ((int)dice.roll(1, 100, 0) <= protect[group] * lvl) {
        switch (rollProtectionDevice(dice)) {
            case PROT_RING1: case PROT_CLOAK1: m.shdPlus += 1; break;
            case PROT_RING2: case PROT_CLOAK2: m.shdPlus += 2; break;
            case PROT_RING3: case PROT_CLOAK3: m.shdPlus += 3; break;
            // bracers replace armor: the AC-6/4/2 sets read as
            // +2/+4/+6 unarmored (documented approximation)
            case PROT_BRACERS6: m.armPlus = (m.armPlus > 2) ? m.armPlus : 2; break;
            case PROT_BRACERS4: m.armPlus = (m.armPlus > 4) ? m.armPlus : 4; break;
            case PROT_BRACERS2: m.armPlus = (m.armPlus > 6) ? m.armPlus : 6; break;
            // cloak of displacement: -2 AC in the MM
            case PROT_DISPLACEMENT: m.shdPlus += 2; break;
            case PROT_AMULET:
            default: break;   // fiction only
        }
    }
}

// R64: build a city party to the p.191-192 explanations.
// asterisk = rollNpcRace (R62); unasterisked classed types are
// human (1e class restrictions). Followers and leaders are
// henchmen; 0-level guardsmen are men-at-arms (R53 shapes).
static CharacterParty rollCityParty(rules::Dice& dice,
                                    const char* type, bool night) {
    CharacterParty p;
    const std::string t(type);

    auto add = [&](int classIndex, int level, bool asterisk) {
        PartyMember m;
        m.classIndex = classIndex;
        m.level = level;
        m.race = asterisk ? rollNpcRace(dice, classIndex)
                          : RACE_HUMAN;
        rollCityMagicItems(dice, m);
        p.members.push_back(m);
        return m;
    };
    auto addHench = [&](int classIndex, int level, bool asterisk) {
        PartyMember m;
        m.classIndex = classIndex;
        m.level = level;
        m.henchman = true;
        m.race = asterisk ? rollNpcRace(dice, classIndex)
                          : RACE_HUMAN;
        rollCityMagicItems(dice, m);
        p.members.push_back(m);
    };
    auto addMan = [&](int n) {
        for (int i = 0; i < n; ++i) {
            PartyMember m;
            m.manAtArms = true;               // 0-level men (R53)
            m.classIndex = rules::CLASS_FIGHTER;
            m.level = 0;
            m.race = RACE_HUMAN;
            p.members.push_back(m);
        }
    };

    if (t == "assassin") {
        // 1-3 assassins; the book prints no level here - the
        // 5th-8th ruffian bodyguard range, the only city
        // assassin range printed, is used (documented)
        int n = (int)dice.roll(1, 3, 0);
        for (int i = 0; i < n; ++i)
            add(rules::CLASS_THIEF, 4 + (int)dice.roll(1, 4, 0), true);
    } else if (t == "cleric") {
        // cleric 6th-11th (d6+5) + 0-5 lesser clerics (d4 level)
        add(rules::CLASS_CLERIC, 5 + (int)dice.roll(1, 6, 0), true);
        int n = (int)dice.roll(1, 6, 0) - 1;
        for (int i = 0; i < n; ++i)
            addHench(rules::CLASS_CLERIC, (int)dice.roll(1, 4, 0), true);
    } else if (t == "druid") {
        // druid 6th-11th; 50% 0-3 lesser druids (d4 level),
        // else 1-4 fighters (d6 level)
        add(rules::CLASS_CLERIC, 5 + (int)dice.roll(1, 6, 0), true);
        if ((int)dice.roll(1, 2, 0) == 1) {
            int n = (int)dice.roll(1, 4, 0) - 1;
            for (int i = 0; i < n; ++i)
                addHench(rules::CLASS_CLERIC, (int)dice.roll(1, 4, 0), true);
        } else {
            int n = (int)dice.roll(1, 4, 0);
            for (int i = 0; i < n; ++i)
                addHench(rules::CLASS_FIGHTER, (int)dice.roll(1, 6, 0), true);
        }
    } else if (t == "fighter") {
        // fighter 6th-12th (2d4+4) + 0-3 henchmen (d4 level)
        add(rules::CLASS_FIGHTER,
            4 + (int)dice.roll(2, 4, 0), true);
        int n = (int)dice.roll(1, 4, 0) - 1;
        for (int i = 0; i < n; ++i)
            addHench(rules::CLASS_FIGHTER, (int)dice.roll(1, 4, 0), true);
    } else if (t == "illusionist") {
        // illusionist 7th-10th (d4+6); 50% 0-3 apprentices
        // (d4 level), else 1-3 fighter guards (d6 level)
        add(rules::CLASS_MAGIC_USER,
            6 + (int)dice.roll(1, 4, 0), true);
        if ((int)dice.roll(1, 2, 0) == 1) {
            int n = (int)dice.roll(1, 4, 0) - 1;
            for (int i = 0; i < n; ++i)
                addHench(rules::CLASS_MAGIC_USER,
                         (int)dice.roll(1, 4, 0), true);
        } else {
            int n = (int)dice.roll(1, 3, 0);
            for (int i = 0; i < n; ++i)
                addHench(rules::CLASS_FIGHTER,
                         (int)dice.roll(1, 6, 0), true);
        }
    } else if (t == "magic_user") {
        // magic-user 7th-12th (d6+6) + 1-4 henchmen: 45%
        // apprentices (d6 level), 30% fighter guards (d4+3),
        // 25% a mixture "providing 2 or 4 henchmen" - the
        // count is forced to 2 or 4 and split evenly
        add(rules::CLASS_MAGIC_USER,
            6 + (int)dice.roll(1, 6, 0), true);
        int roll = (int)dice.roll(1, 100, 0);
        if (roll <= 45) {
            int n = (int)dice.roll(1, 4, 0);
            for (int i = 0; i < n; ++i)
                addHench(rules::CLASS_MAGIC_USER,
                         (int)dice.roll(1, 6, 0), true);
        } else if (roll <= 75) {
            int n = (int)dice.roll(1, 4, 0);
            for (int i = 0; i < n; ++i)
                addHench(rules::CLASS_FIGHTER,
                         3 + (int)dice.roll(1, 4, 0), true);
        } else {
            int n = ((int)dice.roll(1, 2, 0) == 1) ? 2 : 4;
            for (int i = 0; i < n; ++i)
                addHench((i % 2 == 0) ? rules::CLASS_MAGIC_USER
                                      : rules::CLASS_FIGHTER,
                         (i % 2 == 0) ? (int)dice.roll(1, 6, 0)
                                      : 3 + (int)dice.roll(1, 4, 0),
                         true);
        }
    } else if (t == "monk") {
        // one monk, 7th-10th (d4+6); monks resolve as fighters
        // (R53 closest-approximation), human (no asterisk)
        add(rules::CLASS_FIGHTER, 6 + (int)dice.roll(1, 4, 0), false);
    } else if (t == "paladin") {
        // one paladin, 6th-9th (d4+5); human (1e requirement)
        add(rules::CLASS_FIGHTER, 5 + (int)dice.roll(1, 4, 0), false);
    } else if (t == "ranger") {
        // one ranger, 7th-10th (d4+6), race-checked (*)
        add(rules::CLASS_FIGHTER, 6 + (int)dice.roll(1, 4, 0), true);
    } else if (t == "thief") {
        // thief 8th-11th (d4+7) + 0-2 apprentices (d4 level)
        add(rules::CLASS_THIEF, 7 + (int)dice.roll(1, 4, 0), true);
        int n = (int)dice.roll(1, 3, 0) - 1;
        for (int i = 0; i < n; ++i)
            addHench(rules::CLASS_THIEF, (int)dice.roll(1, 4, 0), true);
    } else if (t == "rake") {
        // 2-5 young gentlemen fighters, 5th-10th (d6+4)
        int n = 1 + (int)dice.roll(1, 4, 0);
        for (int i = 0; i < n; ++i)
            add(rules::CLASS_FIGHTER,
                4 + (int)dice.roll(1, 6, 0), false);
    } else if (t == "city_guard") {
        // 2-16 0-level guardsmen; 1 leader (2 if more than 8,
        // 3 if more than 12) of 2nd-5th (d4+1); plus an
        // indentured magic-user of 1st-4th - all race-checked
        // (the matrix asterisks the City guard)
        int n = 1 + (int)dice.roll(1, 16, 0);
        addMan(n);
        int leaders = (n > 12) ? 3 : (n > 8) ? 2 : 1;
        for (int i = 0; i < leaders; ++i)
            addHench(rules::CLASS_FIGHTER,
                     1 + (int)dice.roll(1, 4, 0), true);
        addHench(rules::CLASS_MAGIC_USER,
                 (int)dice.roll(1, 4, 0), true);
    } else if (t == "city_watchman") {
        // day: 5 men + 1st-3rd sergeant; night: double numbers
        // plus a 4th/5th-level lieutenant; always accompanied
        // by an indentured cleric of 2nd-5th (d4+1)
        addMan(night ? 10 : 5);
        addHench(rules::CLASS_FIGHTER,
                 (int)dice.roll(1, 3, 0), false);   // sergeant
        if (night)
            addHench(rules::CLASS_FIGHTER,
                     3 + (int)dice.roll(1, 2, 0), false);  // lieutenant
        addHench(rules::CLASS_CLERIC,
                 1 + (int)dice.roll(1, 4, 0), false);
    } else if (t == "city_official") {
        // a minor bureaucrat (10% a major official with 2-8
        // guards); always 1-4 personal fighters (d4 level).
        // The official is fiction - a man-at-arms shape -
        // the guards are classed. No asterisk: human.
        addMan(1);
        bool major = (int)dice.roll(1, 10, 0) == 10;
        if (major)
            addMan(1 + (int)dice.roll(1, 8, 0));
        int n = (int)dice.roll(1, 4, 0);
        for (int i = 0; i < n; ++i)
            addHench(rules::CLASS_FIGHTER,
                     (int)dice.roll(1, 4, 0), false);
    }
    (void)add;
    return p;
}

DungeonEncounter rollCityEncounter(
        const monsters::MonsterRegistry& reg, rules::Dice& dice,
        int pctile, int pctile2, CityTime time) {
    DungeonEncounter e;

    for (int attempt = 0; attempt < 24; ++attempt) {
        const CityRow* row = nullptr;
        for (size_t i = 0;
             i < sizeof kCityMatrix / sizeof kCityMatrix[0]; ++i) {
            short lo, hi;
            if (time == CITY_DAY) { lo = kCityMatrix[i].loDay;  hi = kCityMatrix[i].hiDay;  }
            else                  { lo = kCityMatrix[i].loNight; hi = kCityMatrix[i].hiNight; }
            if (lo > 0 && pctile >= lo && pctile <= hi)
                { row = &kCityMatrix[i]; break; }
        }
        if (!row) return e;   // defensive: columns cover 01-00

        std::string key = row->key;

        // the book's own advice: "they may be ignored entirely
        // if desirable ... treat these encounters as highly
        // special" (p.191); nycadaemon/mezzadaemon are
        // unimplemented (R52) - ignore & re-roll
        if (key == "demon_or_nycadaemon" ||
            key == "devil_or_mezzadaemon") {
            pctile  = 1 + (int)dice.roll(1, 100, 0) - 1;
            pctile2 = 1 + (int)dice.roll(1, 100, 0) - 1;
            continue;
        }

        // printed 50/50 - 75/25 splits (second percentile)
        if (key == "laborer_or_peddler")
            key = (pctile2 <= 50) ? "laborer" : "peddler";
        else if (key == "monk_or_bard")
            key = (pctile2 <= 60) ? "monk" : "bard";
        else if (key == "ghoul_or_ghast")
            key = (pctile2 <= 30) ? "ghoul" : "ghast";
        else if (key == "vampire_or_lich")
            key = (pctile2 <= 75) ? "vampire" : "lich";
        else if (key == "brigand")
            key = "bandit";   // "the same as bandit encounters"

        // classed / service encounters: character parties
        if (key == "assassin" || key == "cleric" || key == "druid" ||
            key == "fighter" || key == "illusionist" ||
            key == "magic_user" || key == "monk" || key == "paladin" ||
            key == "ranger" || key == "thief" || key == "rake" ||
            key == "city_guard" || key == "city_official" ||
            key == "city_watchman") {
            e.party = rollCityParty(dice, key.c_str(),
                                    time == CITY_NIGHT);
            e.isParty = true;
            e.key = key;
            e.count = e.party.size();
            return e;
        }

        e.key = key;
        e.count = cityCountFor(dice, key,
                               time == CITY_NIGHT);
        (void)reg;   // fiction keys may not be registry keys;
                     // the regtest companion lists both
        return e;
    }
    return e;
}

// Every result key the matrix can produce - registry keys for
// the monsters, fiction keys for the civilians, party-type
// keys for the classed and service encounters (resolved as
// character parties). The regtest companion of
// rollCityEncounter.
std::vector<std::string> cityEncounterKeys(
        const monsters::MonsterRegistry& reg) {
    std::vector<std::string> out;
    for (size_t i = 0;
         i < sizeof kCityMatrix / sizeof kCityMatrix[0]; ++i) {
        std::string key = kCityMatrix[i].key;
        if (key == "laborer_or_peddler") {
            pushUnique(out, "laborer");
            pushUnique(out, "peddler");
            continue;
        }
        if (key == "monk_or_bard") {
            pushUnique(out, "monk");
            pushUnique(out, "bard");
            continue;
        }
        if (key == "ghoul_or_ghast") {
            pushUnique(out, "ghoul");
            pushUnique(out, "ghast");
            continue;
        }
        if (key == "vampire_or_lich") {
            pushUnique(out, "vampire");
            pushUnique(out, "lich");
            continue;
        }
        if (key == "brigand") {
            pushUnique(out, "bandit");
            continue;
        }
        if (key == "demon_or_nycadaemon" ||
            key == "devil_or_mezzadaemon")
            continue;   // ignored & re-rolled (documented)
        pushUnique(out, key.c_str());
    }
    (void)reg;
    return out;
}

// ----------------------------------------------------------------------------
// R146: the city flavor subtables R64 named as unmodeled -
// the p.191 drunk identity table ("the character(s) found
// drunk should be diced for") and the p.192 harlot type
// table, both transcribed from the 1eonline.info
// compilation (the repo-trusted source; the DMG re-upload's
// OCR debt stands). Fiction-only descriptors: the app's
// cityFlavor strings dress the "drunk" and "harlot" rows
// with them; no combat effect. The book prints "MU" and
// "Merc" in full as the fiction strings (magic-user,
// mercenary); the printed book reads "haughty", the
// compilation "Haughy" an OCR defect (corrected,
// documented). R174 pins the two remaining R64 flavor
// notes below (the R149-corrected reading): noble
// gender is a clean nobleman-with-retainers 75% /
// noblewoman 25% coin; the noblewoman is 75% likely
// to have a sedan chair, carriers and linkboys (at
// night); the printed matrix footnote - 1 in 4
// ruffians can be half-orc or of humanoid race
// (goblin, hobgoblin, kobold, orc) - is banded as
// five equal fifths of the quarter, the weights the
// book leaves unstated (documented).
namespace {

struct FlavorBand {
    short lo, hi;
    const char* kind;
};

// p.191: the drunk's dice-for identity (20 bands)
static const FlavorBand kDrunkKinds[] = {
    {   1,  2, "assassin" },
    {   3,10, "bandit" },
    { 11,18, "brigand" },
    { 19,20, "city guard" },
    { 21,22, "city official" },
    { 23,25, "city watchman" },
    { 26,27, "cleric" },
    { 28,29, "druid" },
    { 30,38, "fighter" },
    { 39,45, "gentleman" },
    { 46,48, "illusionist" },
    { 49,63, "laborer" },
    { 64,65, "magic-user" },
    { 66,73, "mercenary" },
    { 74,80, "merchant" },
    { 81,82, "noble" },
    { 83,90, "rake" },
    { 91,95, "ruffian" },
    { 96,97, "thief" },
    { 98,100, "tradesman" },
};

// p.192: the harlot encounter type (12 bands)
static const FlavorBand kHarlotKinds[] = {
    {   1,10, "slovenly trull" },
    { 11,25, "brazen strumpet" },
    { 26,35, "cheap trollop" },
    { 36,50, "typical streetwalker" },
    { 51,65, "saucy tart" },
    { 66,75, "wanton wench" },
    { 76,85, "expensive doxy" },
    { 86,90, "haughty courtesan" },
    { 91,92, "aged madam" },
    { 93,94, "wealthy procuress" },
    { 95,98, "sly pimp" },
    { 99,100, "rich panderer" },
};

const char* flavorKindFor(const FlavorBand* t, size_t n,
                          int pctile) {
    if (pctile < 1)   pctile = 1;
    if (pctile > 100) pctile = 100;
    for (size_t i = 0; i < n; ++i)
        if (pctile >= t[i].lo && pctile <= t[i].hi)
            return t[i].kind;
    return "";
}

}   // namespace

const char* cityDrunkKind(int pctile) {
    return flavorKindFor(kDrunkKinds,
        sizeof kDrunkKinds / sizeof kDrunkKinds[0], pctile);
}

const char* cityHarlotKind(int pctile) {
    return flavorKindFor(kHarlotKinds,
        sizeof kHarlotKinds / sizeof kHarlotKinds[0], pctile);
}


// ----------------------------------------------------------------------------
// R174: the two remaining R64 city flavor notes, pinned
// from the fresh DMG upload (p.191-192, both confirmed
// by the R149 book-verify pass): the noble gender coin
// - nobleman-with-retainers 75% / noblewoman 25% (the
// corrected reading; the 70/25/no-last-5 guess is dead)
// - and the noblewoman 75% sedan-chair likelihood (with
// carriers and linkboys at night; the complement reads
// her on foot). The ruffian matrix footnote (if
// desired, 1 in 4 can be half-orc or of humanoid
// race - goblin, hobgoblin, kobold, orc) is banded
// as the printed 25% quarter split into five equal
// fifths, the weights the book leaves unstated
// (documented); the first band is the human
// three-quarters. Like the R146 tables these are
// fiction-only descriptors dressing the city flavor
// strings - no combat effect. The note says CAN be:
// the fiction never summons the bestiary half-orc /
// goblin / hobgoblin / kobold / orc records.

// p.191-192: the noble gender coin (2 bands)
static const FlavorBand kNobleKinds[] = {
    {  1, 75, "nobleman" },
    { 76,100, "noblewoman" },
};

// p.192: the noblewoman ride (2 bands)
static const FlavorBand kSedanKinds[] = {
    {  1, 75, "sedan chair" },
    { 76,100, "on foot" },
};

// p.191: the ruffian 1-in-4 matrix footnote (6 bands)
static const FlavorBand kRuffianKinds[] = {
    {   1, 75, "human" },
    {  76, 80, "half-orc" },
    {  81, 85, "goblin" },
    {  86, 90, "hobgoblin" },
    {  91, 95, "kobold" },
    {  96,100, "orc" },
};

const char* cityNobleKind(int pctile) {
    return flavorKindFor(kNobleKinds,
        sizeof kNobleKinds / sizeof kNobleKinds[0], pctile);
}

const char* cityNoblewomanSedan(int pctile) {
    return flavorKindFor(kSedanKinds,
        sizeof kSedanKinds / sizeof kSedanKinds[0], pctile);
}

const char* cityRuffianKind(int pctile) {
    return flavorKindFor(kRuffianKinds,
        sizeof kRuffianKinds / sizeof kRuffianKinds[0], pctile);
}



// ----------------------------------------------------------------------------
// R65: the ASTRAL & ETHEREAL encounter tables - DMG Appendix C
// (Premium reprint p.181, OCR-verified against the uploaded
// DMG). "Encounters occur 1 in 20; check at the beginning,
// midpoint, and end of the journey." Unlike the outdoor
// tables, these print a Numbers column - counts come from the
// table rows, not the registry. The astral/ethereal footnote
// (*): basilisk, cockatrice, gorgon and medusa "do not
// actually travel therein ... their possible appearance
// applies only to situations in which the encounter allows
// effect to extend from the Prime Material Plane; otherwise
// ignore the encounter result and roll again" - carried as
// PF_PRIME_ONLY, gated on the caller's primeAdjacent flag
// and re-rolled when false (the R60 footnote-clime
// precedent). "Dragon, chromatic" / "Dragon, platinum" are
// Tiamat and Bahamut - the bestiary's chromatic_dragon /
// platinum_dragon keys, documented. Demon/devil tiers are
// pick-sets on the second percentile (R52 style): minor ->
// the six type I-IV demons, major -> the ten type V/VI
// demons, prince -> the R52 kPrinces pool, arch- ->
// kArchDevils, greater -> horned/ice/pit_fiend, lesser ->
// succubus/erinyes/barbed/bone devil. The bestiary's titans
// are AC variants: elder (AC -2/-3), lesser (AC 1/2), major
// (AC 0/1), picked on the second percentile. "Human
// traveller" resolves as the ** modified Human Subtable
// party (see rollPlanarTravellerParty). The Psychic Wind
// and Ether Cyclone tables (chance 5% per plane crossed)
// are transcribed verbatim as results the caller interprets
// - the engine has no planar travel yet, so lost-days and
// cord effects are fiction-only (documented; R60/R63 no-
// wiring precedent).

namespace {

struct PlanarRow {
    short lo, hi;             // percentile
    const char* key;          // registry key or pseudo-key
    short nMin, nMax;         // printed Numbers column
    int flags;
};
enum { PF_NONE = 0, PF_PRIME_ONLY = 1 };

static const PlanarRow kAstralTable[] = {
{1, 4, "aerial_servant", 1, 1},
{5, 10, "basilisk", 1, 2 | PF_PRIME_ONLY}, // * prime-adjacent only,
{11, 13, "cockatrice", 1, 4 | PF_PRIME_ONLY}, // * prime-adjacent only,
{14, 16, "PLANAR_DEMON_MAJOR", 1, 1}, // Demon, major -> type V/VI pick-set,
{17, 22, "PLANAR_DEMON_MINOR", 1, 3}, // Demon, minor -> type I-IV pick-set,
{23, 23, "PLANAR_DEMON_PRINCE", 1, 1}, // Demon, prince -> R52 kPrinces pool,
{24, 24, "PLANAR_DEVIL_ARCH", 1, 1}, // Devil, arch- -> R52 kArchDevils pool,
{25, 28, "PLANAR_DEVIL_GREATER", 1, 1}, // Devil, greater- -> horned/ice/pit_fiend,
{29, 37, "PLANAR_DEVIL_LESSER", 1, 3}, // Devil, lesser- -> succubus/erinyes/barbed/bone,
{38, 38, "chromatic_dragon", 1, 1}, // Dragon, chromatic (Tiamat),
{39, 39, "platinum_dragon", 1, 1}, // Dragon, platinum (Bahamut),
{40, 41, "gorgon", 1, 2 | PF_PRIME_ONLY}, // * prime-adjacent only,
{42, 46, "PLANAR_TRAVELLER", 0, 0}, // Human traveller - modified Human Subtable (**),
{47, 49, "intellect_devourer", 1, 2},
{50, 55, "invisible_stalker", 1, 3},
{56, 61, "ki_rin", 1, 1},
{62, 63, "medusa", 1, 2 | PF_PRIME_ONLY}, // * prime-adjacent only,
{64, 71, "night_hag", 1, 4},
{72, 74, "nightmare", 1, 4},
{75, 79, "rakshasa", 1, 3},
{80, 91, "shedu", 2, 5},
{92, 92, "PLANAR_TITAN_ELDER", 1, 1}, // Titan, elder -> AC -2/-3 variants,
{93, 97, "PLANAR_TITAN_LESSER", 1, 1}, // Titan, lesser -> AC 1/2 variants,
{98, 100, "PLANAR_TITAN_MAJOR", 1, 1}   // Titan, major -> AC 0/1 variants
};

static const PlanarRow kEtherealTable[] = {
{1, 5, "aerial_servant", 1, 1},
{6, 10, "basilisk", 1, 2 | PF_PRIME_ONLY}, // * prime-adjacent only,
{11, 13, "cockatrice", 1, 4 | PF_PRIME_ONLY}, // * prime-adjacent only,
{14, 18, "couatl", 1, 4},
{19, 26, "djinni", 1, 6},
{27, 27, "chromatic_dragon", 1, 1}, // Dragon, chromatic (Tiamat),
{28, 28, "platinum_dragon", 1, 1}, // Dragon, platinum (Bahamut),
{29, 30, "efreeti", 1, 3},
{31, 37, "air_elemental", 1, 1}, // Elemental, air,
{38, 39, "earth_elemental", 1, 1}, // Elemental, earth,
{40, 41, "fire_elemental", 1, 1}, // Elemental, fire,
{42, 42, "water_elemental", 1, 1}, // Elemental, water,
{43, 48, "ghost", 1, 1},
{49, 50, "gorgon", 1, 2 | PF_PRIME_ONLY}, // * prime-adjacent only,
{51, 52, "groaning_spirit", 1, 2},
{53, 57, "PLANAR_TRAVELLER", 0, 0}, // Human traveller - same ** note,
{58, 59, "intellect_devourer", 1, 2},
{60, 62, "invisible_stalker", 1, 3},
{63, 68, "ki_rin", 1, 1},
{69, 76, "lammasu", 2, 8},
{77, 78, "medusa", 1, 2 | PF_PRIME_ONLY}, // * prime-adjacent only,
{79, 80, "nightmare", 1, 4},
{81, 82, "salamander", 2, 5},
{83, 87, "phase_spider", 1, 6}, // Spider, phase,
{88, 94, "thought_eater", 1, 3}, // Thought eaters,
{95, 97, "wind_walker", 2, 5}, // Wind walkers,
{98, 100, "xorn", 3, 6}
};

// pick-sets (second percentile modulo size)
static const char* const kDemonMinor[] = {
    "type_i_vrock", "type_ii_hezrou", "type_iii_glabrezu",
    "type_iv_demon_bilwhr", "type_iv_demon_johud",
    "type_iv_demon_nalfeshnee"
};
static const char* const kDemonMajor[] = {
    "type_v_demon_aishapra", "type_v_demon_kevokulli",
    "type_v_demon_marilith", "type_v_demon_rehnaremme",
    "type_vi_demon_alzoll", "type_vi_demon_balor",
    "type_vi_demon_errtu", "type_vi_demon_ndulu",
    "type_vi_demon_tersath", "type_vi_demon_wendonai"
};
static const char* const kDevilGreater[] = {
    "horned_devil", "ice_devil", "pit_fiend"
};
static const char* const kDevilLesser[] = {
    "succubus", "erinyes", "barbed_devil", "bone_devil"
};
static const char* const kTitanElder[]  = { "elder_titan_ac_2", "elder_titan_ac_3" };
static const char* const kTitanLesser[] = { "lesser_titan_ac_1", "lesser_titan_ac_2" };
static const char* const kTitanMajor[]  = { "major_titan_ac_0", "major_titan_ac_1" };

const PlanarRow* planarTable(PlanarBody body, size_t& n) {
    if (body == PB_ASTRAL) {
        n = sizeof kAstralTable / sizeof kAstralTable[0];
        return kAstralTable;
    }
    n = sizeof kEtherealTable / sizeof kEtherealTable[0];
    return kEtherealTable;
}

} // namespace

// R65: the ** modified Human Subtable for planar travellers
// (both tables reference it). "Party size will be only 1-6.
// No limits to the number of characters of one class apply.
// There will always be 1 cleric; if 2 or more in the party,
// there will also be a minimum of 1 magic-user." Levels per
// the printed class table: cleric 9-18, druid 7-14, fighter
// 8-15, paladin 7-16, ranger 7-16, magic-user 11-20,
// illusionist 10-17, thief 9-16, assassin 10-15, monk 8-17,
// bard 11-18 (the bard's fighter 7th-8th / thief 6th-9th
// dual abilities are unmodeled - the thief range, per the
// R53 bard convention). The remaining members roll
// professions on the standard subtable without per-class
// maxima; the monk/bard split is 60/40 (city-matrix
// precedent, documented). Race: rollNpcRace per class
// (R62) - nothing printed, the character-party convention.
// Magic items: the R55 ladder (rollMagicItemsFor), the
// character-party convention, documented.
static CharacterParty rollPlanarTravellerParty(rules::Dice& dice) {
    CharacterParty p;
    int n = (int)dice.roll(1, 6, 0);            // 1-6 members

    auto profLevel = [&](int prof) {
        switch (prof) {
            case PROF_CLERIC:      return 8 + (int)dice.roll(1, 10, 0);   // 9-18
            case PROF_DRUID:       return 6 + (int)dice.roll(1, 8, 0);     // 7-14
            case PROF_FIGHTER:     return 7 + (int)dice.roll(1, 8, 0);     // 8-15
            case PROF_PALADIN:     return 6 + (int)dice.roll(1, 10, 0);   // 7-16
            case PROF_RANGER:      return 6 + (int)dice.roll(1, 10, 0);   // 7-16
            case PROF_MU:          return 10 + (int)dice.roll(1, 10, 0);  // 11-20
            case PROF_ILLUSIONIST: return 9 + (int)dice.roll(1, 8, 0);    // 10-17
            case PROF_THIEF:       return 8 + (int)dice.roll(1, 8, 0);    // 9-16
            case PROF_ASSASSIN:    return 9 + (int)dice.roll(1, 6, 0);    // 10-15
            case PROF_MONK_BARD:   // monk 8-17 / bard thief 6-9
                return ((int)dice.roll(1, 100, 0) <= 60)
                     ? 7 + (int)dice.roll(1, 10, 0)
                     : 5 + (int)dice.roll(1, 4, 0);
            default:               return 8 + (int)dice.roll(1, 8, 0);
        }
    };
    auto addMember = [&](int prof) {
        PartyMember m;
        m.classIndex = classForProf(prof);
        m.level = profLevel(prof);
        m.race = rollNpcRace(dice, m.classIndex);   // R62
        rollMagicItemsFor(dice, m);                 // R55
        p.members.push_back(m);
    };

    // always 1 cleric; 2+ members -> minimum 1 magic-user
    addMember(PROF_CLERIC);
    if (n >= 2) addMember(PROF_MU);
    for (int i = (int)p.members.size(); i < n; ++i)
        addMember(profFor((int)dice.roll(1, 100, 0)));
    return p;
}

DungeonEncounter rollPlanarEncounter(
        const monsters::MonsterRegistry& reg, rules::Dice& dice,
        int pctile, int pctile2,
        PlanarBody body, bool primeAdjacent) {
    DungeonEncounter e;

    size_t n = 0;
    const PlanarRow* t = planarTable(body, n);

    for (int attempt = 0; attempt < 24; ++attempt) {
        const PlanarRow* row = nullptr;
        for (size_t i = 0; i < n; ++i)
            if (pctile >= t[i].lo && pctile <= t[i].hi)
                { row = &t[i]; break; }
        if (!row) return e;   // defensive: columns cover 01-00

        // * footnote: prime-material perception creatures
        // "otherwise, ignore the encounter result and roll
        // again"
        if ((row->flags & PF_PRIME_ONLY) && !primeAdjacent) {
            pctile  = 1 + (int)dice.roll(1, 100, 0) - 1;
            pctile2 = 1 + (int)dice.roll(1, 100, 0) - 1;
            continue;
        }

        std::string key = row->key;
        if      (key == "PLANAR_DEMON_MINOR")  key = kDemonMinor[pctile2 % 6];
        else if (key == "PLANAR_DEMON_MAJOR")  key = kDemonMajor[pctile2 % 10];
        else if (key == "PLANAR_DEMON_PRINCE") key = kPrinces[pctile2 % 4];
        else if (key == "PLANAR_DEVIL_ARCH")   key = kArchDevils[pctile2 % 4];
        else if (key == "PLANAR_DEVIL_GREATER") key = kDevilGreater[pctile2 % 3];
        else if (key == "PLANAR_DEVIL_LESSER")  key = kDevilLesser[pctile2 % 4];
        else if (key == "PLANAR_TITAN_ELDER")   key = kTitanElder[pctile2 % 2];
        else if (key == "PLANAR_TITAN_LESSER")  key = kTitanLesser[pctile2 % 2];
        else if (key == "PLANAR_TITAN_MAJOR")   key = kTitanMajor[pctile2 % 2];

        if (key == "PLANAR_TRAVELLER") {
            // ** modified Human Subtable party
            e.party = rollPlanarTravellerParty(dice);
            e.isParty = true;
            e.key = "planar_traveller_party";
            e.count = e.party.size();
            return e;
        }

        const monsters::MonsterDef* def = reg.find(key);
        if (def) {
            e.key = key;
            // printed Numbers column (uniform lo..hi; single
            // results skip the roll)
            e.count = (row->nMin == row->nMax)
                ? row->nMin
                : row->nMin + (int)dice.roll(
                      1, (uint32_t)(row->nMax - row->nMin + 1), 0) - 1;
            return e;
        }

        // DMG advice: ignore & re-roll
        pctile  = 1 + (int)dice.roll(1, 100, 0) - 1;
        pctile2 = 1 + (int)dice.roll(1, 100, 0) - 1;
    }
    return e;
}

// Every result key the table can produce - the regtest-style
// companion of rollPlanarEncounter. Footnote (*) creatures
// appear only when the encounter allows prime-material
// effect; they are listed regardless (R60 precedent) and the
// caller gates on primeAdjacent.
std::vector<std::string> planarEncounterKeys(
        const monsters::MonsterRegistry& reg, PlanarBody body) {
    std::vector<std::string> out;
    size_t n = 0;
    const PlanarRow* t = planarTable(body, n);
    for (size_t i = 0; i < n; ++i) {
        const std::string key = t[i].key;
        if      (key == "PLANAR_DEMON_MINOR")
            for (const char* k : kDemonMinor) pushUnique(out, k);
        else if (key == "PLANAR_DEMON_MAJOR")
            for (const char* k : kDemonMajor) pushUnique(out, k);
        else if (key == "PLANAR_DEMON_PRINCE")
            for (const char* k : kPrinces) pushUnique(out, k);
        else if (key == "PLANAR_DEVIL_ARCH")
            for (const char* k : kArchDevils) pushUnique(out, k);
        else if (key == "PLANAR_DEVIL_GREATER")
            for (const char* k : kDevilGreater) pushUnique(out, k);
        else if (key == "PLANAR_DEVIL_LESSER")
            for (const char* k : kDevilLesser) pushUnique(out, k);
        else if (key == "PLANAR_TITAN_ELDER")
            for (const char* k : kTitanElder) pushUnique(out, k);
        else if (key == "PLANAR_TITAN_LESSER")
            for (const char* k : kTitanLesser) pushUnique(out, k);
        else if (key == "PLANAR_TITAN_MAJOR")
            for (const char* k : kTitanMajor) pushUnique(out, k);
        else if (key == "PLANAR_TRAVELLER")
            pushUnique(out, "planar_traveller_party");
        else if (reg.find(key))
            pushUnique(out, key.c_str());
    }
    return out;
}

// ----------------------------------------------------------------------------
// R65: PSYCHIC WIND (astral) & ETHER CYCLONE (ethereal) - DMG
// p.181, transcribed verbatim. "The chance of a delayed or
// disrupted journey is 5% per plane crossed." The effects
// are journey fiction the engine does not yet simulate (no
// planar travel); the roll functions return the printed
// result and the caller interprets. Day counts are uniform
// over the printed range (the book prints only the range;
// the spread is a documented approximation). The saving
// throw versus magic (wind 20 / cyclone 19-20) is the
// caller's - passed in as saveMade.

PsychicWindResult rollPsychicWind(rules::Dice& dice, int d20,
                                  bool saveMade) {
    PsychicWindResult r;
    if (d20 <= 12) {
        r.effect = PsychicWindEffect::Slowed;
    } else if (d20 <= 16) {
        r.effect = PsychicWindEffect::LostReturn;
        r.days = 1 + (int)dice.roll(1, 19, 0);       // 2-20
    } else if (d20 <= 19) {
        r.effect = PsychicWindEffect::OffCourse;
    } else {
        r.effect = PsychicWindEffect::Storm;
        if (saveMade)
            r.days = 3 + (int)dice.roll(1, 37, 0);    // 4-40
        else
            r.cordBroken = true;
        // no-cord projection: lost AND different destination
        // (p.181 note) - the caller reads cordBroken plus
        // OffCourse semantics; fiction, documented
    }
    return r;
}


EtherCycloneResult rollEtherCyclone(rules::Dice& dice, int d20,
                                    bool saveMade) {
    EtherCycloneResult r;
    if (d20 <= 10) {
        r.effect = EtherCycloneEffect::BlownAbout;
    } else if (d20 <= 15) {
        r.effect = EtherCycloneEffect::DifferentPlane;
    } else if (d20 <= 18) {
        r.effect = EtherCycloneEffect::LostNewPlane;
        r.days = 4 + (int)dice.roll(1, 56, 0);        // 5-60
    } else {
        r.effect = EtherCycloneEffect::StormAstral;
        r.days = 9 + (int)dice.roll(1, 111, 0);      // 10-120
        r.blownToAstral = !saveMade;   // save: random ether-touched plane
    }
    return r;
}


// ----------------------------------------------------------------------------
// R66: the PSIONIC ENCOUNTER TABLE - DMG Appendix C (Premium
// reprint p.182, OCR-verified against the uploaded DMG).
// "If you opt to include psionic powers in your campaign,
// then certain random encounters will be with
// psionically-empowered creatures ... if the player party has
// used psionic powers during the last turn, or spells
// resembling psionic powers during the last round, then the
// chance for a psionic encounter will be 1 in 4 if an
// encounter is otherwise indicated." The 1-in-4 gate is the
// caller's (dice passed in, engine has no psionics yet);
// spellResemblesPsionicPower below implements the printed
// spells list. The table prints a Numbers column - counts
// come from the table, not the registry - except the yellow
// mold row's dash, which falls back to the registry's
// noAppearing (the R60 convention, documented in-row). The
// (*) demon/devil rows are "Dice for type or select" - the
// R65 pick-sets on the second percentile, reused. The (**)
// Men row refers to the DUNGEON RANDOM MONSTER TABLE's
// Character Subtable - a character party; the R63 wilderness
// convention rollCharacterParty(dice, 8, 8) is applied, as
// the psionic table is not dungeon-level-tied (documented).
// "Roll until an appropriate encounter occurs, ignoring
// inappropriate results" - the caller's judgement; the
// triton row's "1-3 of total are psionic" is fiction (the
// count is the printed 10-60). No appstate wiring (R60/R63
// no-wiring precedent).

namespace {

struct PsionicRow {
    short lo, hi;         // percentile
    const char* key;      // registry key or PSI_* pseudo-key
    short nMin, nMax;     // printed Numbers column
};

// PSIONIC ENCOUNTER TABLE (DMG p.182)
static const PsionicRow kPsionicTable[] = {
{1, 5, "brain_mole", 1, 3},
{6, 12, "cerebral_parasite", 3, 12},
{13, 15, "couatl", 1, 4},
{16, 18, "PSI_DEMON_MAJOR", 1, 2}, // Demon, major* -> R65 kDemonMajor,
{19, 24, "PSI_DEMON_MINOR", 1, 4}, // Demon, minor* -> R65 kDemonMinor,
{25, 26, "PSI_DEMON_PRINCE", 1, 1}, // Demon, prince* -> R52 kPrinces,
{27, 28, "PSI_DEVIL_ARCH", 1, 1}, // Devil, arch-* -> R52 kArchDevils,
{29, 34, "PSI_DEVIL_GREATER", 1, 2}, // Devil, greater-* -> R65 kDevilGreater,
{35, 38, "gray_ooze", 1, 3},
{39, 48, "intellect_devourer", 1, 2},
{49, 51, "ki_rin", 1, 1}, // Ki-rin,
{52, 56, "lich", 1, 1},
{57, 62, "PSI_MEN", 0, 0}, // Men (human psionic)** -> Character Subtable party,
{63, 69, "mind_flayer", 1, 4},
{70, 72, "yellow_mold", 0, 0}, // Mold, yellow (dash) -> registry noAppearing (R60),
{73, 82, "shedu", 2, 8},
{83, 92, "su_monster", 1, 12}, // Su-monster,
{93, 98, "titan", 1, 2}, // Titan -> bestiary's plain titan key,
{99, 100, "triton", 10, 60}   // 1-3 of total are psionic (fiction, documented)
};

} // namespace

// R66: the printed "Spells Resembling Psionic Powers" list
// (p.182). The families - astral spell, augury, blink,
// charm (any), clairadience, clairvoyance, cure (any),
// detect (any), dimension door, enlarge, ESP, feather fall,
// feign death, heat metal, heal, hypnotism, invisibility
// (any), know alignment, levitation, plane shift,
// polymorph (any), remove curse, shape change, stone tell,
// tele- (any), temporal stasis. Matching is
// case-insensitive on the full name; "(any)" families match
// by the leading word (charm, cure, detect, invisibility,
// polymorph, tele-). Magic items performing these powers
// count as well (the book's note) - the caller's call.
bool spellResemblesPsionicPower(const std::string& name) {
    static const char* const exact[] = {
        "astral spell", "augury", "blink", "clairadience",
        "clairvoyance", "dimension door", "enlarge", "esp",
        "feather fall", "feign death", "heat metal", "heal",
        "hypnotism", "know alignment", "levitation",
        "plane shift", "remove curse", "shape change",
        "stone tell", "temporal stasis"
    };
    std::string lower;
    for (char c : name) {
        unsigned char u = (unsigned char)c;
        lower.push_back((char)(u >= 'A' && u <= 'Z' ? u + 32 : u));
    }
    for (const char* e : exact)
        if (lower == e) return true;
    // "(any)" families - the printed leading word
    static const char* const family[] = {
        "charm", "cure", "detect", "invisibility",
        "polymorph", "tele"
    };
    for (const char* f : family)
        if (lower.rfind(f, 0) == 0) return true;
    return false;
}

DungeonEncounter rollPsionicEncounter(
        const monsters::MonsterRegistry& reg, rules::Dice& dice,
        int pctile, int pctile2) {
    DungeonEncounter e;

    size_t n = sizeof kPsionicTable / sizeof kPsionicTable[0];

    for (int attempt = 0; attempt < 24; ++attempt) {
        const PsionicRow* row = nullptr;
        for (size_t i = 0; i < n; ++i)
            if (pctile >= kPsionicTable[i].lo &&
                pctile <= kPsionicTable[i].hi)
                { row = &kPsionicTable[i]; break; }
        if (!row) return e;   // defensive: column covers 01-00

        std::string key = row->key;
        if      (key == "PSI_DEMON_MAJOR")   key = kDemonMajor[pctile2 % 10];
        else if (key == "PSI_DEMON_MINOR")   key = kDemonMinor[pctile2 % 6];
        else if (key == "PSI_DEMON_PRINCE")  key = kPrinces[pctile2 % 4];
        else if (key == "PSI_DEVIL_ARCH")    key = kArchDevils[pctile2 % 4];
        else if (key == "PSI_DEVIL_GREATER") key = kDevilGreater[pctile2 % 3];

        if (key == "PSI_MEN") {
            // (**) Character Subtable party - the R63
            // wilderness convention (not dungeon-level-tied)
            e.party = rollCharacterParty(dice, 8, 8);
            e.isParty = true;
            e.key = "character_party";
            e.count = e.party.size();
            return e;
        }

        const monsters::MonsterDef* def = reg.find(key);
        if (def) {
            e.key = key;
            if (key == "yellow_mold") {
                // printed dash: numbers per MONSTER MANUAL
                // (registry noAppearing; 0/0 -> single patch)
                if (def->noAppearingMin > 0) {
                    int lo = def->noAppearingMin;
                    int hi = def->noAppearingMax < lo
                           ? lo : def->noAppearingMax;
                    e.count = (lo == hi)
                        ? lo
                        : lo + (int)dice.roll(
                              1, (uint32_t)(hi - lo + 1), 0) - 1;
                } else {
                    e.count = 1;
                }
            } else if (row->nMin == row->nMax) {
                e.count = row->nMin;
            } else {
                // printed Numbers column
                e.count = row->nMin + (int)dice.roll(
                    1, (uint32_t)(row->nMax - row->nMin + 1), 0) - 1;
            }
            return e;
        }

        // DMG advice: ignore & re-roll
        pctile  = 1 + (int)dice.roll(1, 100, 0) - 1;
        pctile2 = 1 + (int)dice.roll(1, 100, 0) - 1;
    }
    return e;
}

// Every result key the table can produce - the regtest-style
// companion of rollPsionicEncounter.
std::vector<std::string> psionicEncounterKeys(
        const monsters::MonsterRegistry& reg) {
    std::vector<std::string> out;
    size_t n = sizeof kPsionicTable / sizeof kPsionicTable[0];
    for (size_t i = 0; i < n; ++i) {
        const std::string key = kPsionicTable[i].key;
        if      (key == "PSI_DEMON_MAJOR")
            for (const char* k : kDemonMajor) pushUnique(out, k);
        else if (key == "PSI_DEMON_MINOR")
            for (const char* k : kDemonMinor) pushUnique(out, k);
        else if (key == "PSI_DEMON_PRINCE")
            for (const char* k : kPrinces) pushUnique(out, k);
        else if (key == "PSI_DEVIL_ARCH")
            for (const char* k : kArchDevils) pushUnique(out, k);
        else if (key == "PSI_DEVIL_GREATER")
            for (const char* k : kDevilGreater) pushUnique(out, k);
        else if (key == "PSI_MEN")
            pushUnique(out, "character_party");
        else if (reg.find(key))
            pushUnique(out, key.c_str());
    }
    return out;
}


// ----------------------------------------------------------------------------
// R67: the PATROL and CASTLE/FORTRESS tables - DMG Appendix C
// (Premium reprint p.182-183, OCR-verified against the
// uploaded DMG). These complete the outdoor tables' context:
// inhabited areas are patrolled ("roll d20; 5 in 20 are
// encounters with a patrol"), uninhabited areas occasionally
// hold strongholds ("1 in 20 is an encounter which discovers
// such a stronghold" - the party is within visual range,
// 1/2 to 5 miles). Both gates are the caller's; the builders
// below construct what is found.
//
// PATROLS (p.182): "commanded by a fighter (or ranger, where
// applicable) of from 6th to 8th level, with a lieutenant of
// from 4th to 5th level, and a sergeant of 2nd or 3rd level.
// There will be from 3 to 4 1st level men and from 13 to 24
// soldiers (men-at-arms) forming the main body ... Each
// patrol will be accompanied by a cleric (40%) of 6th or 7th
// level or a magic-user (60%) of 5th to 8th level." Arms are
// fiction (no itemization in the engine, documented); the
// book's pointer to Character Subtable party magic items is
// honored via the R55 ladder (rollMagicItemsFor). Racial
// composition is "appropriate to the area" - the caller's;
// classed members roll R62 races, men-at-arms are human
// (R53 convention).
//
// CASTLE TABLE I (p.182): size class and type, 01-00. CASTLE
// TABLE II: inhabitants per size - totally deserted /
// deserted (monster therein: "roll on the appropriate OUTDOOR
// ENCOUNTER TABLE, ignoring any rolls which indicate men" -
// the R63 rollOutdoorEncounter is the caller's tool) /
// humans / character-types. SUB-TABLE II.A: humans are
// bandits / brigands / berserkers / dervishes (brigand ->
// bandit, the R63 substitution); "numbers and other details
// ... are given in the MONSTER MANUAL under the heading of
// MEN" - registry noAppearing (R60 convention), so
// castleHumansCount uses the registry. SUB-TABLE II.B: the
// master's class and level; henchmen 2-5 with level per the
// Character Subtable (henchmanLevelFor, one-third the
// master's, R53) and R55 magic items. OCR defect corrected
// and documented: the printed "94-96 Assassin / 94-99 MONK
// / 00 BARD" overlaps - the original prints Assassin 94-96,
// Monk 97-99, Bard 00 (23rd level). The illusionist
// covered-by-illusion and monk monastery notes are fiction,
// documented. The garrison men-at-arms (heavy horse 9-12 /
// light horse 9-16 / foot 13-24 / crossbow 7-12, each led
// by a 3rd-4th level fighter) lost their per-class
// assignment to an OCR image extraction - transcribed in
// the comment below, fiction only, the caller assigns.
//
// ARTILLERY per fortress type: transcribed verbatim. The
// printed eight rows do not map one-to-one onto the nine
// castle types (the book groups); the engine maps by nearest
// type, documented in castleArtillery. Detection: "roll a
// surprise die ... if they are surprised, then the fortress
// occupants know they are there - if surprise is 2 or
// greater, the occupants are actually outside the place" -
// castleAwareness maps the die directly (1d6: 1 = aware,
// 2 = aware and outside, 3+ = undetected; the standard 1e
// surprise die). Reaction fiction (welcome / joust / ransom)
// is the caller's, per the p.183 text.
//
// Garrison units as printed (p.183, OCR image), fiction:
//   9-12 heavy horse, splint mail & shield, lance, long
//   sword, mace; 9-16 light horse, studded leather, light
//   crossbow, long sword; 13-24 men-at-arms, scale mail,
//   shield, spear, hand axe; 7-12 men-at-arms, scale mail,
//   heavy crossbow, morning star. Cavalry stabled, fights
//   on the walls; each unit led by a 3rd-4th level fighter
//   with normal chances for magic items, in addition to the
//   figures shown.

namespace {

struct CastleTypeRow {
    short lo, hi;
    CastleSize size;
    const char* type;
};

// CASTLE TABLE I: SIZE CLASS AND TYPE (DMG p.182)
static const CastleTypeRow kCastleTypeTable[] = {
{1, 10, CASTLE_SMALL, "small shell keep"},
{11, 25, CASTLE_SMALL, "tower"},
{26, 35, CASTLE_SMALL, "moat house or friary"},
{36, 45, CASTLE_MEDIUM, "large shell keep"},
{46, 65, CASTLE_MEDIUM, "small walled castle with keep"},
{66, 80, CASTLE_MEDIUM, "medium walled castle with keep"},
{81, 88, CASTLE_LARGE, "concentric castle"},
{89, 95, CASTLE_LARGE, "large walled castle with keep"},
{96, 100, CASTLE_LARGE, "fortress complex"}
};

struct CastleInhRow {
    short lo, hi;
    CastleInhabitants cat;
};

// CASTLE TABLE II: INHABITANTS (per size class)
static const CastleInhRow kCastleInhSmall[] = {
{1, 45, CASTLE_TOTALLY_DESERTED},
{46, 60, CASTLE_DESERTED_MONSTER},
{61, 70, CASTLE_HUMANS},
{71, 100, CASTLE_CHARACTER_TYPES}
};
static const CastleInhRow kCastleInhMedium[] = {
{1, 30, CASTLE_TOTALLY_DESERTED},
{31, 50, CASTLE_DESERTED_MONSTER},
{51, 65, CASTLE_HUMANS},
{66, 100, CASTLE_CHARACTER_TYPES}
};
static const CastleInhRow kCastleInhLarge[] = {
{1, 15, CASTLE_TOTALLY_DESERTED},
{16, 40, CASTLE_DESERTED_MONSTER},
{41, 60, CASTLE_HUMANS},
{61, 100, CASTLE_CHARACTER_TYPES}
};

// CASTLE SUB-TABLE II.A: HUMANS ARE (brigand -> bandit, the
// R63 substitution, documented)
static const struct { short lo, hi; const char* key; } kCastleHumansAre[] = {
{1, 25, "bandit"},
{26, 85, "bandit"},
{86, 97, "berserker"},
{98, 100, "dervish"}
};

struct CastleMasterRow {
    short lo, hi;
    int prof;      // ProfId
    short lvlLo, lvlHi;
};

// CASTLE SUB-TABLE II.B: MASTER'S CLASS AND LEVEL. The OCR
// printed Assassin 94-96 overlapping Monk 94-99; the
// original prints Assassin 94-96 / Monk 97-99 / Bard 00
// (corrected, documented above).
static const CastleMasterRow kCastleMaster[] = {
{1, 18, PROF_CLERIC, 9, 12},
{19, 20, PROF_DRUID, 12, 13},
{21, 65, PROF_FIGHTER, 9, 12},
{66, 66, PROF_PALADIN, 9, 10},
{67, 68, PROF_RANGER, 10, 13},
{69, 80, PROF_MU, 11, 14},
{81, 85, PROF_ILLUSIONIST, 10, 13},
{86, 93, PROF_THIEF, 10, 14},
{94, 96, PROF_ASSASSIN, 14, 14},
{97, 99, PROF_MONK_BARD, 9, 12}, // monk,
{100, 100, PROF_MONK_BARD, 23, 23}   // bard, 23rd
};

struct ArtilleryRow {
    const char* type;
    int ballistae, lightCatapults, oilCauldrons;
};

// ARTILLERY per fortress type (DMG p.183)
static const ArtilleryRow kCastleArtillery[] = {
{"moat house or friary", 2, 0, 1},
{"tower", 1, 0, 1},
{"shell keep", 0, 1, 2},
{"small walled castle with keep", 1, 1, 2},
{"medium walled castle with keep", 2, 2, 5},
{"concentric castle", 4, 2, 6},
{"large walled castle with keep", 4, 4, 8},
{"fortress complex", 4, 4, 8}
};

} // namespace

CastleType rollCastleType(int pctile) {
    CastleType t;
    size_t n = sizeof kCastleTypeTable / sizeof kCastleTypeTable[0];
    for (size_t i = 0; i < n; ++i)
        if (pctile >= kCastleTypeTable[i].lo &&
            pctile <= kCastleTypeTable[i].hi) {
            t.size = kCastleTypeTable[i].size;
            t.type = kCastleTypeTable[i].type;
            return t;
        }
    return t;   // defensive: column covers 01-00
}

CastleInhabitants castleInhabitants(int pctile, CastleSize size) {
    const CastleInhRow* t = nullptr; size_t n = 0;
    switch (size) {
        case CASTLE_SMALL:  t = kCastleInhSmall;  n = sizeof kCastleInhSmall  / sizeof kCastleInhSmall[0];  break;
        case CASTLE_MEDIUM: t = kCastleInhMedium; n = sizeof kCastleInhMedium / sizeof kCastleInhMedium[0]; break;
        default:            t = kCastleInhLarge;  n = sizeof kCastleInhLarge  / sizeof kCastleInhLarge[0];  break;
    }
    for (size_t i = 0; i < n; ++i)
        if (pctile >= t[i].lo && pctile <= t[i].hi)
            return t[i].cat;
    return CASTLE_TOTALLY_DESERTED;   // defensive
}

const char* castleHumansType(int pctile) {
    size_t n = sizeof kCastleHumansAre / sizeof kCastleHumansAre[0];
    for (size_t i = 0; i < n; ++i)
        if (pctile >= kCastleHumansAre[i].lo &&
            pctile <= kCastleHumansAre[i].hi)
            return kCastleHumansAre[i].key;
    return "bandit";   // defensive
}

int castleHumansCount(const monsters::MonsterRegistry& reg,
                      rules::Dice& dice, const char* key) {
    // "Numbers and other details of these humans are given in
    // the MONSTER MANUAL under the heading of MEN" - registry
    // noAppearing (R60 convention; 0/0 -> single specimen)
    const monsters::MonsterDef* def = reg.find(key);
    if (!def) return 1;
    if (def->noAppearingMin > 0) {
        int lo = def->noAppearingMin;
        int hi = def->noAppearingMax < lo ? lo : def->noAppearingMax;
        return (lo == hi)
            ? lo
            : lo + (int)dice.roll(1, (uint32_t)(hi - lo + 1), 0) - 1;
    }
    return 1;
}

// R67: the stronghold's master per Sub-Table II.B - class by
// percentile, level uniform over the printed range, race per
// R62, magic items per the R55 ladder (the book's Character
// Subtable pointer).
PartyMember rollCastleMaster(rules::Dice& dice, int pctile) {
    PartyMember m;
    size_t n = sizeof kCastleMaster / sizeof kCastleMaster[0];
    const CastleMasterRow* row = nullptr;
    for (size_t i = 0; i < n; ++i)
        if (pctile >= kCastleMaster[i].lo &&
            pctile <= kCastleMaster[i].hi)
            { row = &kCastleMaster[i]; break; }
    if (!row) return m;   // defensive: column covers 01-00
    m.classIndex = classForProf(row->prof);
    m.level = (row->lvlLo == row->lvlHi)
        ? row->lvlLo
        : row->lvlLo + (int)dice.roll(
              1, (uint32_t)(row->lvlHi - row->lvlLo + 1), 0) - 1;
    m.race = rollNpcRace(dice, m.classIndex);   // R62
    rollMagicItemsFor(dice, m);                 // R55
    return m;
}

// R67: the master's henchmen - "from 2-5 henchmen found
// within a fortress," levels and magic items per the
// Character Subtable (henchmanLevelFor, one-third of the
// master's, R53; R62 race follows the master's folk where
// the class allows - the R63 convention).
CharacterParty rollCastleHenchmen(rules::Dice& dice,
                                  const PartyMember& master) {
    CharacterParty p;
    int n = 1 + (int)dice.roll(1, 4, 0);           // 2-5
    for (int i = 0; i < n; ++i) {
        PartyMember m;
        m.henchman = true;
        m.classIndex = master.classIndex;   // the master's own
        m.level = henchmanLevelFor(master.level);
        m.race = raceAllowsClass(master.race, m.classIndex)
               ? master.race
               : rollNpcRace(dice, m.classIndex);
        rollMagicItemsFor(dice, m);               // R55
        p.members.push_back(m);
    }
    return p;
}

// R67: the artillery of the fortress, per the printed table.
// The book's eight rows group the nine castle types; the
// engine maps by nearest type (concentric -> the medium
// concentric row; large walled / fortress complex -> the
// large castle row), documented.
CastleArtillery castleArtillery(const CastleType& castle) {
    size_t n = sizeof kCastleArtillery / sizeof kCastleArtillery[0];
    for (size_t i = 0; i < n; ++i)
        if (std::string(kCastleArtillery[i].type) == castle.type)
            return { kCastleArtillery[i].ballistae,
                     kCastleArtillery[i].lightCatapults,
                     kCastleArtillery[i].oilCauldrons };
    // shell keeps share a row keyed "shell keep" (documented)
    if (std::string(castle.type).find("shell keep") !=
        std::string::npos)
        for (size_t i = 0; i < n; ++i)
            if (std::string(kCastleArtillery[i].type) == "shell keep")
                return { kCastleArtillery[i].ballistae,
                         kCastleArtillery[i].lightCatapults,
                         kCastleArtillery[i].oilCauldrons };
    return { 0, 0, 0 };
}

// R67: fortress detection per the p.183 rule - "roll a
// surprise die ... if they are surprised, then the fortress
// occupants know they are there - if surprise is 2 or
// greater, the occupants are actually outside the place and
// within normal surprise distance." The standard 1e
// surprise die is 1d6; 1 = surprised (occupants aware),
// 2 = surprised and the occupants are outside, 3+ = not
// detected.
CastleAwareness castleAwareness(int surpriseDie) {
    if (surpriseDie <= 1) return CASTLE_OCCUPANTS_AWARE;
    if (surpriseDie == 2) return CASTLE_OCCUPANTS_OUTSIDE;
    return CASTLE_UNDETECTED;
}

// R67: build a patrol per the p.182 text - fighter (or
// ranger) leader 6th-8th, lieutenant 4th-5th, sergeant
// 2nd-3rd, 3-4 1st-level men, 13-24 men-at-arms, plus a
// cleric 6th-7th (40%) or magic-user 5th-8th (60%). Classed
// members roll R62 races and R55 magic items (the book's
// Character Subtable pointer); men-at-arms are 0-level
// humans (R53). Arms/armor fiction is not itemized
// (documented).
CharacterParty rollPatrol(rules::Dice& dice, bool rangerLeader) {
    CharacterParty p;
    auto add = [&](int classIndex, int level) {
        PartyMember m;
        m.classIndex = classIndex;
        m.level = level;
        m.race = rollNpcRace(dice, classIndex);   // R62
        rollMagicItemsFor(dice, m);               // R55
        p.members.push_back(m);
    };
    auto addMan = [&](int level, int count) {
        for (int i = 0; i < count; ++i) {
            PartyMember m;
            m.manAtArms = true;
            m.classIndex = rules::CLASS_FIGHTER;
            m.level = level;
            m.race = RACE_HUMAN;   // R53 convention
            p.members.push_back(m);
        }
    };

    // leader: fighter 6-8 (or ranger where applicable)
    int leadLvl = 5 + (int)dice.roll(1, 3, 0);
    add(rangerLeader ? rules::CLASS_FIGHTER : rules::CLASS_FIGHTER,
        leadLvl);   // ranger kit not carried by classIndex (R53)
    // lieutenant 4-5, sergeant 2-3
    add(rules::CLASS_FIGHTER, 3 + (int)dice.roll(1, 2, 0));
    add(rules::CLASS_FIGHTER, 1 + (int)dice.roll(1, 2, 0));
    // 3-4 1st-level men
    addMan(1, 2 + (int)dice.roll(1, 2, 0));
    // 13-24 men-at-arms (0-level, R53 shapes)
    addMan(0, 12 + (int)dice.roll(1, 12, 0));
    // cleric 6-7 (40%) or magic-user 5-8 (60%)
    if ((int)dice.roll(1, 100, 0) <= 40)
        add(rules::CLASS_CLERIC, 5 + (int)dice.roll(1, 2, 0));
    else
        add(rules::CLASS_MAGIC_USER, 4 + (int)dice.roll(1, 4, 0));
    return p;
}



// ==== R74: MM-frequency encounter generator (merged R78) ====
namespace encounters {

// ---- frequency table (DMG Appendix C spirit; house weights) -------------
int frequencyWeight(const std::string& frequency) {
    if (frequency == "common")                        return 8;
    if (frequency == "uncommon")                      return 4;
    if (frequency == "rare")                          return 2;
    if (frequency == "very rare")                     return 1;
    if (frequency == "unique")                        return 1;
    return 4;  // unknown/blank -> uncommon weight
}

// local dice helpers (same conventions as dm/treasure.cpp)
static int inRange(rules::Dice& d, int lo, int hi) {         // [lo, hi]
    if (hi <= lo) return lo;
    return lo + (int)d.d((uint32_t)(hi - lo + 1)) - 1;
}
static bool pctRoll(rules::Dice& d, int pct) {               // 0-99 < pct
    return (int)d.d100() - 1 < pct;
}

static bool isUnique(const monsters::MonsterDef& def) {
    return def.frequency == "unique" || def.xpSource == "perm_x10";
}

static bool alignmentOk(const monsters::MonsterDef& def,
                        const std::string& filter) {
    if (filter.empty()) return true;
    return def.alignment.compare(0, filter.size(), filter) == 0;
}

// Roll one treasure-letter set into the destination hoard.
static void rollLetters(rules::Dice& dice,
                        const std::vector<monsters::TreasureEntry>& list,
                        int nCreatures,
                        treasure::Hoard& out,
                        int& rolls) {
    for (const auto& e : list) {
        for (int t = 0; t < e.times; ++t) {
            out.absorb(treasure::rollTreasureType(dice, e.letter,
                                                  nCreatures,
                                                  e.magicOnly));
            ++rolls;
        }
    }
}

bool rollEncounter(const monsters::MonsterRegistry& reg,
                   rules::Dice& dice,
                   const EncounterOptions& opt,
                   Encounter& out) {
    out = Encounter{};
    const auto& all = reg.all();

    long long total = 0;
    for (const auto& kv : all) {
        const monsters::MonsterDef& d = kv.second;
        if (!opt.allowUnique && isUnique(d)) continue;
        if (!alignmentOk(d, opt.alignmentFilter)) continue;
        total += frequencyWeight(d.frequency);
    }
    if (total <= 0) return false;

    long long pick = inRange(dice, 1, (int)total);
    const monsters::MonsterDef* chosen = nullptr;
    for (const auto& kv : all) {
        const monsters::MonsterDef& d = kv.second;
        if (!opt.allowUnique && isUnique(d)) continue;
        if (!alignmentOk(d, opt.alignmentFilter)) continue;
        pick -= frequencyWeight(d.frequency);
        if (pick <= 0) { chosen = &d; break; }
    }
    if (!chosen) return false;              // cannot happen; belt & braces

    out.def = chosen;

    int lo = chosen->noAppearingMin;
    int hi = chosen->noAppearingMax;
    if (hi < lo) hi = lo;
    out.rawCount = inRange(dice, lo, hi);
    out.count = out.rawCount > opt.countCap ? opt.countCap
                                            : out.rawCount;
    if (out.count < 1) out.count = 1;       // a meeting, not a rumor
    out.clamped = out.rawCount > out.count;

    out.inLair = chosen->lairPct > 0 && pctRoll(dice, chosen->lairPct);

    if (opt.rollTreasure) {
        if (out.inLair && !chosen->treasure.lair.empty())
            rollLetters(dice, chosen->treasure.lair, out.count,
                        out.lairHoard, out.treasureRolls);
        if (!chosen->treasure.individual.empty())
            rollLetters(dice, chosen->treasure.individual, out.count,
                        out.carried, out.treasureRolls);
    }
    return true;
}

} // namespace encounters

} // namespace dm
