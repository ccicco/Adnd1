// ============================================================================
// Adnd1 - dm/treasure.cpp
// R71: MM Treasure Types (p.105) + DMG treasure determination (pp.25-27,
// 120-125). Data transcribed from the Curtiss-verified table files; see
// treasure.h for provenance. All rolls through rules::Dice - deterministic.
// ============================================================================

#include "treasure.h"

// R402: the treasure dial rides the
// determination dispatch; this TU
// pulls its own rules headers (the
// R400 lesson - the engine TUs do
// not pull rules/ transitively).
#include "../rules/ua/uatreasuredial.h"
#include "../rules/ua/uadetskel.h"
#include "../rules/ua/uadetrows.h"
#include "items/MiscItemRegistry.h"

#include <algorithm>

#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace dm {
namespace treasure {

// ----------------------------------------------------------------------------
// Dice helpers
// ----------------------------------------------------------------------------
static int d100(rules::Dice& d) { return (int)d.d100() - 1; }        // 0-99
static int pctRoll(rules::Dice& d, int pct) { return d100(d) < pct; }
static int inRange(rules::Dice& d, int lo, int hi) {                 // [lo,hi]
    if (hi <= lo) return lo;
    return lo + (int)d.d((uint32_t)(hi - lo + 1)) - 1;
}
static int valIn(rules::Dice& d, int lo, int hi) {                  // 0 = n/a
    if (hi <= 0 || hi <= lo) return lo;
    return inRange(d, lo, hi);
}

// ----------------------------------------------------------------------------
// Gems - DMG p.25-26. Base value by percentile, then the d10 variation
// roll with the book's reroll/step rules. Returns the gem's gp value.
// ----------------------------------------------------------------------------

static const int kGemBase[6]    = { 10, 50, 100, 500, 1000, 5000 };
// Progression above 5,000 gp (dice result 1, per the printed rule)
static const long long kGemUp[7] = { 10000, 25000, 50000, 100000,
                                     250000, 500000, 1000000 };
// Below 10 gp (dice result 0, per the printed rule): 5 gp, 1 gp, then
// 10 sp, 5 sp, 1 sp - encoded in gp (a sp is 1/10 gp, cp 1/100).
static const long long kGemDown[5] = { 5, 1, 1, 0, 0 };

static const char* kOrnamental[12] = {
    "azurite", "banded agate", "blue quartz", "eye agate", "hematite",
    "lapis lazuli", "malachite", "moss agate", "obsidian",
    "rhodochrosite", "tiger eye", "turquoise" };
static const char* kSemiPrecious[13] = {
    "bloodstone", "carnelian", "chalcedony", "chrysoprase", "citrine",
    "jasper", "moonstone", "onyx", "rock crystal", "sardonyx",
    "smoky quartz", "star rose quartz", "zircon" };
static const char* kFancy[14] = {
    "amber", "alexandrite", "amethyst", "aquamarine", "chrysoberyl",
    "coral", "garnet", "jade", "jet", "pearl", "peridot", "spinel",
    "topaz", "tourmaline" };
static const char* kGemStones[14] = {
    "black opal", "black sapphire", "diamond", "emerald", "fire opal",
    "jacinth", "opal", "oriental amethyst", "oriental emerald",
    "oriental topaz", "ruby", "sapphire", "star ruby", "star sapphire" };

long long rollGemValue(rules::Dice& dice) {
    int pct = d100(dice);
    int cls = (pct < 25) ? 0 : (pct < 50) ? 1 : (pct < 71) ? 2
           : (pct < 91) ? 3 : (pct < 100) ? 4 : 5;
    long long v = kGemBase[cls];
    int upSteps = 0, downSteps = 0;

    // The printed d10 variation roll; results 1 and 0 re-roll (bounded
    // by the book's +7 / -5 step caps).
    for (int guard = 0; guard < 8; ++guard) {
        int r = (int)dice.d10();
        if (r >= 2 && r <= 9) {
            if (r == 2) v *= 2;                          // double base
            else if (r == 3) v = v * (10 + (int)dice.d6()) / 10;    // +10..60%
            else if (r == 9) v = v * (10 - (int)dice.d4()) / 10; // -10..40%
            // 4-8 unchanged
            break;
        }
        if (r == 1) {                       // next higher base value
            if (upSteps >= 7) break;
            ++upSteps;
            if (cls == 5) {
                v = kGemUp[upSteps - 1];
            } else {
                ++cls;
                v = kGemBase[cls];
            }
        } else {                            // r == 0: next lower
            if (downSteps >= 5) break;
            ++downSteps;
            if (cls == 0) {
                v = kGemDown[downSteps - 1];
            } else {
                --cls;
                v = kGemBase[cls];
            }
        }
    }
    return v;
}

// Flavor name for a stone of the given base-value class band.
static const char* gemName(rules::Dice& dice, long long v) {
    if (v >= 1000) return kGemStones[dice.d(14) - 1];
    if (v >= 100)  return kFancy[dice.d(14) - 1];
    if (v >= 50)   return kSemiPrecious[dice.d(13) - 1];
    return kOrnamental[dice.d(12) - 1];
}

// ----------------------------------------------------------------------------
// Jewelry - DMG p.26. Percentile class, uniform value in the class range,
// d10 workmanship (each 1 promotes and re-checks), and for gem-set
// pieces the d8 (+5,000) then d6 doubling chain, max 640,000 gp.
// ----------------------------------------------------------------------------

struct JewelryClass {
    int lo, hi;
    const char* desc;
    bool gemSet;
};
static const JewelryClass kJewelry[7] = {
    {   100,  1000, "ivory or wrought silver",           false },
    {   200,  1200, "wrought silver and gold",           false },
    {   300,  1800, "wrought gold",                      false },
    {   500,  3000, "jade, coral or wrought platinum",   false },
    {  1000,  6000, "silver with gems",                  true  },
    {  2000,  8000, "gold with gems",                    true  },
    {  2000, 12000, "platinum with gems",                true  },
};

static long long rollJewelry(rules::Dice& dice, const char** desc);

long long rollJewelryValue(rules::Dice& dice) {
    const char* desc = nullptr;
    return rollJewelry(dice, &desc);
}

// R73: shared body - rolls a piece of jewelry and, if desc is non-null,
// reports its final workmanship class for the loot log flavor.
static long long rollJewelry(rules::Dice& dice, const char** desc) {
    int pct = d100(dice);
    int cls = (pct < 10) ? 0 : (pct < 20) ? 1 : (pct < 40) ? 2
           : (pct < 50) ? 3 : (pct < 70) ? 4 : (pct < 90) ? 5 : 6;
    long long v = inRange(dice, kJewelry[cls].lo, kJewelry[cls].hi);

    // Workmanship: each 1 promotes (highest value in class, or next
    // class up where the base is re-determined and re-checked).
    for (int guard = 0; guard < 8; ++guard) {
        if ((int)dice.d10() != 1) break;
        if (cls == 6) { v = kJewelry[6].hi; break; }
        ++cls;
        v = inRange(dice, kJewelry[cls].lo, kJewelry[cls].hi);
    }
    // Exceptional stones in the setting (gem-set classes only)
    if (kJewelry[cls].gemSet && (int)dice.d8() == 1) {
        long long bonus = 5000;
        while ((int)dice.d6() == 1 && bonus < 640000) bonus *= 2;
        if (bonus > 640000) bonus = 640000;
        v += bonus;
    }
    if (v > 640000) v = 640000;
    if (desc) *desc = kJewelry[cls].desc;
    return v;
}

// ----------------------------------------------------------------------------
// Magic item tables - DMG pp.121-125 (III.A-H). Rows are the printed
// percentile bands; xp/gp are the printed values (xpHi/gpHi > xp/gp
// mark printed ranges, rolled uniform). qlo/qhi > 0 mark bundled finds.
// ----------------------------------------------------------------------------

// R1041 (the registry-native de-wire, the R1028/R1032-R1040
// shape): the seven printed percentile tables (DMG pp.121-125)
// retired into content/tables/treasure/ - one lua per family,
// rows the items::MiscItemRow schema, set names = the def keys.
// The roller and the pin surface read the registry views below;
// the roll semantics (band scan on 1+d100, fallback the last
// row) are the pickMiscRow semantics, unchanged. The scrolls
// family (III.B) keeps its in-file shape. The R122 pin audits
// read through the public accessors, so they pin the same
// rows untouched.
static items::MiscItemRegistry& tReg() {
    // One-time lazy load (the miscReg shape: the engine loads
    // its own registries).
    static items::MiscItemRegistry reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory("content/tables/treasure");
    }
    return reg;
}

// Per-table views, band-sorted (the miscView idiom; the defs
// arrive in band order, the sort is the stability belt).
static const std::vector<items::MiscItemRow>& itemView(
        const char* set) {
    static std::map<std::string,
        std::vector<items::MiscItemRow>> cache;
    auto it = cache.find(set);
    if (it == cache.end()) {
        std::vector<items::MiscItemRow> v;
        for (const auto& kv : tReg().all())
            for (const auto& r : kv.second.rows)
                if (r.set == set) v.push_back(r);
        std::stable_sort(v.begin(), v.end(),
                        [](const items::MiscItemRow& a,
                           const items::MiscItemRow& b) {
                            return a.bandLo < b.bandLo;
                        });
        it = cache.emplace(set, std::move(v)).first;
    }
    return it->second;
}

// ---- R76 helpers ------------------------------------------------------------
bool MagicItem::isHealingPotion() const {
    if (category != MIC_POTION) return false;
    return name == "Potion of Healing" ||
           name == "Potion of Extra-Healing";
}

// ---- R77: kind & curse classification ---------------------------------------
static bool nameHas(const std::string& s, const char* kw) {
    return strstr(s.c_str(), kw) != nullptr;
}

MagicItemKind MagicItem::kind() const {
    switch (category) {
        case MIC_SWORD:
            return MIK_SWORD;
        case MIC_SCROLL:
            return MIK_SCROLL;
        case MIC_ARMOR:
            return nameHas(name, "Shield") ? MIK_SHIELD : MIK_ARMOR;
        case MIC_WEAPON:
            if (nameHas(name, "Arrow") || nameHas(name, "Bolt"))
                return MIK_AMMO;
            if (nameHas(name, "Bow") || nameHas(name, "Sling"))
                return MIK_MISSILE;
            return MIK_MELEE;
        default:
            return MIK_OTHER;
    }
}

bool MagicItem::cursed() const {
    // printed curse/trap rows (III.F/G/H): keep in sync with the tables
    return nameHas(name, "Cursed") ||
           nameHas(name, "Vulnerability") ||
           nameHas(name, "attractor") ||
           nameHas(name, "Backbiter");
}

int MagicItem::weaponPlus() const {
    // first "+N" in the printed name ("Sword +3, Frost Brand" -> 3;
    // "Arrow +2" (qty bundle) -> 2; no plus -> 0)
    size_t p = name.find('+');
    while (p != std::string::npos) {
        if (p + 1 < name.size() && name[p + 1] >= '0' &&
            name[p + 1] <= '9')
            return atoi(name.c_str() + p + 1);
        p = name.find('+', p + 1);
    }
    return 0;
}

// III.A Potions ---------------------------------------------------------- retired into content/tables/treasure/treasure_potions.lua (R1041)

// III.C Rings ------------------------------------------------------------ retired into content/tables/treasure/treasure_rings.lua (R1041)

// III.D Rods, Staves & Wands --------------------------------------------- retired into content/tables/treasure/treasure_rods.lua (R1041)

// ---- III.E.1-5 Miscellaneous Magic (R1028: registry-native) ---------------------
// The five hardcoded kMisc ItemRow arrays are retired: the tables are the
// 166 def rows at content/magic_items/<letter>/<stem>.lua, loaded through
// items::MiscItemRegistry. The one hardcoded survivor is the Artifact or
// Relic dispatch row (band 17-17 of table 1): it is the trigger for the
// Special artifact table, so the A1 ruling keeps it out of the defs and it
// is injected into the view below; adjustSpecial dispatches on its exact
// printed name.
static items::MiscItemRegistry& miscReg() {
    // One-time lazy load (adnd1.cpp is a Win32 shell TU that preflight
    // skips, so the engine loads its own registries; R71fix letter-dir
    // loop: a missing letter dir is normal, loadDirectory returns -1).
    static items::MiscItemRegistry reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        for (char c = 'a'; c <= 'z'; ++c) {
            std::string dir = "content/magic_items/";
            dir.push_back(c);
            reg.loadDirectory(dir);
        }
    }
    return reg;
}

// Per-table views of the registry rows, band-sorted (registry key order
// is alphabetical, NOT band order). Counts: 33/30/33/36/35 (the 166
// def rows + the injected artifact row), matching mNRowCount() and the
// retired arrays, so the R122 pin audits read the same table.
static const std::vector<items::MiscItemRow>& miscView(int n) {
    static std::vector<items::MiscItemRow> v[6];
    static bool built = false;
    if (!built) {
        built = true;
        for (const auto& kv : miscReg().all())
            for (const auto& r : kv.second.rows)
                if (r.set.size() == 6 && r.set.compare(0, 5, "kMisc") == 0
                    && r.set[5] >= '1' && r.set[5] <= '5')
                    v[r.set[5] - '0'].push_back(r);
        items::MiscItemRow art;   // the A1-ruling dispatch row
        art.name = "Artifact or Relic";
        art.set = "kMisc1";
        art.bandLo = art.bandHi = 17;
        v[1].push_back(art);
        for (int i = 1; i <= 5; ++i)
            std::sort(v[i].begin(), v[i].end(),
                      [](const items::MiscItemRow& a,
                         const items::MiscItemRow& b) {
                          return a.bandLo < b.bandLo;
                      });
    }
    return v[n];
}

static MagicItem makeMiscItem(rules::Dice& dice,
                              const items::MiscItemRow& r) {
    MagicItem m;
    m.name = r.name;
    m.xp = valIn(dice, r.xp, r.xpHi);
    m.gp = valIn(dice, r.gp, r.gpHi);
    if (r.qtyHi > 0) m.qty = inRange(dice, r.qtyLo, r.qtyHi);
    return m;
}

// The band-scan row-picker semantics on registry rows:
// linear scan on 1+d100, fallback the last row.
static MagicItem pickMiscRow(rules::Dice& dice,
                             const std::vector<items::MiscItemRow>& rows) {
    int r = 1 + d100(dice);
    for (const auto& row : rows)
        if (r >= row.bandLo && r <= row.bandHi)
            return makeMiscItem(dice, row);
    return makeMiscItem(dice, rows.back());
}

// III.E. Special: Artifacts (no x.p.; printed g.p. sale values) ----------- retired into content/tables/treasure/treasure_artifacts.lua (R1041)

// III.F Armor and Shield --------------------------------------------------- retired into content/tables/treasure/treasure_armor.lua (R1041)

// III.G Swords --------------------------------------------------------------- retired into content/tables/treasure/treasure_swords.lua (R1041)

// III.H Miscellaneous Weapons ------------------------------------------------ retired into content/tables/treasure/treasure_weapons.lua (R1041)

// ---- III.B Scrolls -----------------------------------------------------------
// 01-60: N spells of the given level range (30% clerical, of which 25%
// druidical; 10% of magic-user scrolls illusionist - noted in flavor).
struct ScrollRow { int lo, hi; int nSpells; int lvLo, lvHi; };
static const ScrollRow kSpellScrolls[] = {
    { 1,10, 1, 1,4 }, { 11,16, 1, 1,6 }, { 17,19, 1, 2,9 },
    { 20,24, 2, 1,4 }, { 25,27, 2, 1,8 },
    { 28,32, 3, 1,4 }, { 33,35, 3, 2,9 },
    { 36,39, 4, 1,6 }, { 40,42, 4, 1,8 },
    { 43,46, 5, 1,6 }, { 47,49, 5, 1,8 },
    { 50,52, 6, 1,6 }, { 53,54, 6, 3,8 },
    { 55,57, 7, 1,8 }, { 58,59, 7, 2,9 }, { 60,60, 7, 4,9 },
};

static MagicItem rollScroll(rules::Dice& dice) {
    int r = 1 + d100(dice);
    MagicItem m;
    if (r >= 61) {
        static const struct { int lo, hi; const char* name; int xp; } prot[] = {
            { 61,62, "Scroll of Protection from Demons", 2500 },
            { 63,64, "Scroll of Protection from Devils", 2500 },
            { 65,70, "Scroll of Protection from Elementals", 1500 },
            { 71,76, "Scroll of Protection from Lycanthropes", 1000 },
            { 77,82, "Scroll of Protection from Magic", 1500 },
            { 83,87, "Scroll of Protection from Petrification", 2000 },
            { 88,92, "Scroll of Protection from Possession", 2000 },
            { 93,97, "Scroll of Protection from Undead", 1500 },
        };
        if (r <= 97) {
            for (const auto& p : prot)
                if (r >= p.lo && r <= p.hi) {
                    m.name = p.name;
                    m.xp = p.xp;
                    m.gp = p.xp * 5;   // protection scrolls sell at 5x xp
                    return m;
                }
        }
        m.name = "Cursed Scroll";
        m.note = "it reads as a scroll, but...";
        return m;
    }
    // spell scroll: 100 xp per spell level; sale value 3x xp
    for (const auto& s : kSpellScrolls)
        if (r >= s.lo && r <= s.hi) {
            int totalXp = 0;
            for (int i = 0; i < s.nSpells; ++i)
                totalXp += inRange(dice, s.lvLo, s.lvHi) * 100;
            m.xp = totalXp;
            m.gp = totalXp * 3;
            bool clerical = d100(dice) < 30;
            char buf[96];
            std::snprintf(buf, sizeof buf, "%s scroll of %d spells "
                           "(levels %d-%d)",
                           clerical ? "clerical" : "magic-user",
                           s.nSpells, s.lvLo, s.lvHi);
            m.name = buf;
            if (clerical && d100(dice) < 25) m.note = "druidical";
            return m;
        }
    m.name = "Scroll";
    return m;
}

#define COUNT_OF(a) (int)(sizeof(a) / sizeof((a)[0]))

// Special-value rows with printed footnotes get their multipliers rolled
// here (simplifications noted in the knowledge file).
static MagicItem adjustSpecial(rules::Dice& dice, const MagicItem& m) {
    MagicItem r = m;
    if (r.name == std::string("Bracers of Defense")) {
        // 500 xp / 3,000 gp per AC point below 10; roll AC 8 down to 2
        int plus = inRange(dice, 2, 8);
        r.xp = 500 * plus;
        r.gp = 3000 * plus;
        char buf[64];
        std::snprintf(buf, sizeof buf, "Bracers of Defense (AC %d)",
                      10 - plus);
        r.name = buf;
    } else if (r.name == std::string("Cloak of Protection")) {
        // 1,000 xp / 10,000 gp per plus; roll the plus 1-5
        int plus = inRange(dice, 1, 5);
        r.xp = 1000 * plus;
        r.gp = 10000 * plus;
        char buf[64];
        std::snprintf(buf, sizeof buf, "Cloak of Protection +%d", plus);
        r.name = buf;
    } else if (r.name == std::string("Artifact or Relic")) {
        return pickMiscRow(dice, itemView("treasure_artifacts"));
    }
    return r;
}

// Categories: 0 potions, 1 scrolls, 2 rings, 3 rods/staves/wands,
// 4-8 misc magic E.1-E.5, 9 armor & shields, 10 swords, 11 misc weapons.
// R76: the item carries its category (MagicItem::category) so the
// app can act on what it is without re-parsing names.
static MagicItem rollFromCategoryUnset(rules::Dice& dice, int cat) {
    switch (cat) {
        case 0:  return pickMiscRow(dice, itemView("treasure_potions"));
        case 1:  return rollScroll(dice);
        case 2:  return pickMiscRow(dice, itemView("treasure_rings"));
        case 3:  return pickMiscRow(dice, itemView("treasure_rods"));
        case 4:  return adjustSpecial(dice, pickMiscRow(dice, miscView(1)));
        case 5:  return adjustSpecial(dice, pickMiscRow(dice, miscView(2)));
        case 6:  return adjustSpecial(dice, pickMiscRow(dice, miscView(3)));
        case 7:  return adjustSpecial(dice, pickMiscRow(dice, miscView(4)));
        case 8:  return adjustSpecial(dice, pickMiscRow(dice, miscView(5)));
        case 9:  return pickMiscRow(dice, itemView("treasure_armor"));
        case 10: return pickMiscRow(dice, itemView("treasure_swords"));
        default: return pickMiscRow(dice, itemView("treasure_weapons"));
    }
}

static MagicItem rollFromCategory(rules::Dice& dice, int cat) {
    MagicItem m = rollFromCategoryUnset(dice, cat);
    if (m.category == MIC_UNSET) m.category = cat;
    return m;
}

// III. Magic Items dispatch (DMG p.121): percentile into categories.
static int rollCategory(rules::Dice& dice) {
    int r = 1 + d100(dice);
    if (r <= 20) return 0;
    if (r <= 35) return 1;
    if (r <= 40) return 2;
    if (r <= 45) return 3;
    if (r <= 48) return 4;
    if (r <= 51) return 5;
    if (r <= 54) return 6;
    if (r <= 57) return 7;
    if (r <= 60) return 8;
    if (r <= 75) return 9;
    if (r <= 86) return 10;
    return 11;
}

// ---- R402: the treasure dial (the UA
// determination) ----
// The dial routes the random
// determination dispatch: DMG (the
// default - the landed audits), UA
// (the revised tables, the R375/R395
// data), MERGED (both sets live - a
// per-item coin flip picks the set).

// The UA top-level category bands
// (the printed order, eight
// categories - uadetskel).
static int rollCategoryUa(rules::Dice& dice) {
    int r = 1 + d100(dice);
    int cat = -1;
    for (int i = 0;
         i < rules::uadsCategoryCount();
         ++i)
        if (r >= rules::uadsCategoryLo(i)
                && r
                <= rules::uadsCategoryHi(i)) {
            cat = i;
            break;
        }
    if (cat < 0) cat = 7;
    return cat;
}

// The UA category -> the DMG carrier
// category (the misc band rides the
// misc carrier; the MIK kinds do not
// split the misc sub-tables).
static int uaCategoryToDmg(int c) {
    switch (c) {
        case 0: return 0;   // potions
        case 1: return 1;   // scrolls
        case 2: return 2;   // rings
        case 3: return 3;   // rods
        case 4: return 8;   // misc magic
        case 5: return 9;   // armor
        case 6: return 10;  // swords
        default: return 11; // weapons
    }
}

// The split low bands (the new UA
// table low, the DMG original high).
static int uaSplitLo(int c) {
    switch (c) {
        case 0:
            return rules::uadsPotionSplitLo();
        case 1:
            return rules::uadsScrollSplitLo();
        case 2:
            return rules::uadsRingSplitLo();
        case 3:
            return rules::uadsRodSplitLo();
        case 5:
            return rules::uadsArmorSplitLo();
        case 6:
            return rules::uadsSwordSplitLo();
        default:
            return rules::uadsWeaponSplitLo();
    }
}

// The category primary UA table (the
// uadetrows printed order).
static int uaPrimaryTable(int c) {
    switch (c) {
        case 0: return 0;    // III.A
        case 1: return 2;    // III.B
        case 2: return 4;    // III.C
        case 3: return 6;    // III.D
        case 5: return 15;   // III.F
        case 6: return 17;   // III.G
        default: return 19;  // III.H
    }
}

// A row of a UA table by percentile
// (the R395 bands cover 01-00
// contiguously).
static int uaRowOfRoll(int t, int r) {
    for (int i = 0;
         i < rules::uadrowRowCount(t);
         ++i)
        if (r >= rules::uadrowRowLo(t, i)
                && r
                <= rules::uadrowRowHi(t, i))
            return i;
    return 0;
}

// Roll an item from a UA table row
// (the -1 cells carry the print non-
// numerics - the uadetrows
// discipline).
static MagicItem rollFromUaTable(
        rules::Dice& dice, int t,
        int carrier) {
    int r = 1 + d100(dice);
    int i = uaRowOfRoll(t, r);
    MagicItem m;
    m.name = rules::uadrowRowName(t, i);
    m.xp = rules::uadrowRowXpLo(t, i);
    m.gp = rules::uadrowRowGpLo(t, i);
    m.category = carrier;
    return m;
}

// The UA-mode determination: the
// category band, then the split - the
// low band rolls the new UA table,
// the high band the DMG original.
// Misc magic carries no split - the
// seven sub-tables are all UA.
static MagicItem rollMagicItemUa(
        rules::Dice& dice) {
    int c = rollCategoryUa(dice);
    int carrier = uaCategoryToDmg(c);
    if (c == 4) {
        int r = 1 + d100(dice);
        int t =
            8 + rules::uadsMiscSubCount() - 1;
        for (int i = 0;
             i < rules::uadsMiscSubCount();
             ++i)
            if (r
                    >= rules::uadsMiscSubLo(i)
                    && r
                    <= rules::uadsMiscSubHi(i)) {
                t = 8 + i;
                break;
            }
        return rollFromUaTable(dice, t,
                               carrier);
    }
    int r2 = 1 + d100(dice);
    if (r2 <= uaSplitLo(c))
        return rollFromUaTable(
            dice, uaPrimaryTable(c),
            carrier);
    return rollFromCategory(dice,
                            carrier);
}

// MERGED: the union read - both
// table sets live; a per-item coin
// flip picks the set (playtesting
// sees both).
static MagicItem rollMagicItemMerged(
        rules::Dice& dice) {
    if (d100(dice) < 50)
        return rollMagicItemUa(dice);
    return rollFromCategory(dice,
                            rollCategory(dice));
}

MagicItem rollMagicItem(rules::Dice& dice) {
    // R402: the dial governs the
    // dispatch; the DMG default keeps
    // the landed audits authoritative
    int mode = rules::uatdMode();
    if (mode == rules::uatdModeUa())
        return rollMagicItemUa(dice);
    if (mode == rules::uatdModeMerged())
        return rollMagicItemMerged(dice);
    return rollFromCategory(dice,
                            rollCategory(dice));
}

// ---- R122: line-diff pins ---------------------------------------------------
// The battery reads any printed row of the pp.121-125 tables so they
// are pinned, not just rolled (the R122 line-diff found all 383 rows
// faithful). Category 1 (scrolls) keeps its in-file shape - its pin
// count is the structure: 16 spell bands + 8 protection scrolls + 1
// curse row. The seven percentile families and the Special artifact
// table read the R1041 registry views (set names = def keys).
static const char* const kSetFor[13] = {
    "treasure_potions",          // 0  III.A
    nullptr,                     // 1  III.B scrolls (in-file)
    "treasure_rings",            // 2  III.C
    "treasure_rods",             // 3  III.D
    nullptr,                     // 4-8 III.E.1-5 (miscView)
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    "treasure_armor",            // 9  III.F
    "treasure_swords",           // 10 III.G
    "treasure_weapons",          // 11 III.H
    "treasure_artifacts"         // 12 Special
};

int magicTablePinCount(int category) {
    if (category == 1)
        return COUNT_OF(kSpellScrolls) + 9;  // + protection & curse
    if (category >= 4 && category <= 8)     // registry-native misc tables
        return (int)miscView(category - 3).size();
    if (category < 0 || category > 12 || !kSetFor[category])
        return 0;
    return (int)itemView(kSetFor[category]).size();
}

bool magicTablePin(int category, int row, TablePin* out) {
    if (!out || category == 1) return false;
    if (category >= 4 && category <= 8) {    // registry-native misc tables
        const auto& rows = miscView(category - 3);
        if (row < 0 || row >= (int)rows.size()) return false;
        const auto& r = rows[row];           // views are static: name lives
        out->lo = r.bandLo;  out->hi = r.bandHi;
        out->name = r.name.c_str();
        out->xp = r.xp;      out->xpHi = r.xpHi;
        out->gp = r.gp;      out->gpHi = r.gpHi;
        out->qtyLo = r.qtyLo; out->qtyHi = r.qtyHi;
    return true;
    }
    if (category < 0 || category > 12 || !kSetFor[category])
        return false;
    const auto& rows = itemView(kSetFor[category]);
    if (row < 0 || row >= (int)rows.size()) return false;
    const auto& r = rows[row];               // views are static: name lives
    out->lo = r.bandLo;  out->hi = r.bandHi;
    out->name = r.name.c_str();
    out->xp = r.xp;      out->xpHi = r.xpHi;
    out->gp = r.gp;      out->gpHi = r.gpHi;
    out->qtyLo = r.qtyLo; out->qtyHi = r.qtyHi;
    return true;
}

// "Any N" - N rolls on table III (with the letter's printed exclusions).
static void addAnyItems(rules::Dice& dice, Hoard& h, int n,
                        bool noSwords, bool noWeapons) {
    for (int i = 0; i < n; ++i) {
        int cat = -1;
        for (int guard = 0; guard < 20 && cat < 0; ++guard) {
            int c = rollCategory(dice);
            if ((noSwords && c == 10) || (noWeapons && c == 11))
                continue;
            cat = c;
        }
        if (cat < 0) cat = 2;   // exclusions exhausted: a ring
        h.magic.push_back(rollFromCategory(dice, cat));
    }
}

// "1 (2) of each magic, excluding potions & scrolls" (letters U/V):
// one (two) roll(s) on every other category of table III.
static void addOneOfEach(rules::Dice& dice, Hoard& h, int nEach) {
    for (int cat = 2; cat <= 10; ++cat)     // rings..swords (skip
        for (int k = 0; k < nEach; ++k)     // potions & scrolls)
            h.magic.push_back(rollFromCategory(dice, cat));
}

// A map per the DMG Map Table - flavor note only (maps never list
// their treasure; where they lead is the DM's province).
static void addMap(rules::Dice& dice, Hoard& h) {
    int r = 1 + d100(dice);
    const char* what = (r <= 5) ? "a false map"
                      : (r <= 70) ? "a map to monetary treasure"
                      : (r <= 90) ? "a map to magic treasure"
                                  : "a map to a combined hoard";
    h.notes.push_back(std::string(what) + " (destination unknown)");
}

// ----------------------------------------------------------------------------
// MM Treasure Types - the verified p.105 table.
// ----------------------------------------------------------------------------

struct CoinCell { int lo, hi, pct; };       // nil = pct 0; J-N = pct -1
struct GemCell  { int lo, hi, pct; };
enum MagicKind {
    MK_NONE,        // letter has no magic column
    MK_ANY,         // "Any N [plus extras]" - table III rolls
    MK_SAW,         // "sword, armor, or misc. weapon"
    MK_POTIONS,     // 2-8 potions
    MK_SCROLLS,     // 1-4 scrolls
    MK_MAP,         // 1 map
    MK_MISC_POTION, // 1 misc. magic plus 1 potion
    MK_EACH         // 1/2 of each, excluding potions & scrolls
};

struct LetterDef {
    CoinCell cp, sp, ep, gp, pp;           // thousands (pp: hundreds)
    GemCell  gems, jewelry;
    MagicKind magic;
    int magicPct, magicN;                  // chance & count semantics
    bool noSwords, noWeapons;              // exclusions (F)
    int extraPotions, extraScrolls;
};

// clang-format off
static const LetterDef kLetters[26] = {
/* A */ { {1,6,25},{1,6,30},{1,6,35},{1,10,40},{1,4,25}, {4,40,60},{3,30,50}, MK_ANY, 30,3, false,false, 0,0 },
/* B */ { {1,8,50},{1,6,25},{1,4,25},{1,3,25}, {0,0,0},  {1,8,30},{1,4,20},  MK_SAW,  10,0, false,false, 0,0 },
/* C */ { {1,12,20},{1,6,30},{1,4,10},{0,0,0},{0,0,0},  {1,6,25},{1,3,20},  MK_ANY,  10,2, false,false, 0,0 },
/* D */ { {1,8,10},{1,12,15},{1,8,15},{1,6,50},{0,0,0},  {1,10,30},{1,6,25}, MK_ANY,  15,2, false,false, 1,0 },
/* E */ { {1,10,5},{1,12,25},{1,6,25},{1,8,25}, {0,0,0}, {1,12,15},{1,8,10}, MK_ANY,  25,3, false,false, 0,1 },
/* F */ { {0,0,0},{1,20,10},{1,12,15},{1,10,40},{1,8,35},{3,30,20},{1,10,10},MK_ANY,  30,3, true,true,   1,1 },
/* G */ { {0,0,0},{0,0,0},{0,0,0},{10,40,50},{1,20,50},{5,20,30},{1,10,25},  MK_ANY,  35,4, false,false, 0,1 },
/* H */ { {5,30,25},{1,100,40},{10,40,40},{10,60,55},{5,50,25},{1,100,50},{10,40,50}, MK_ANY, 15,4, false,false, 1,1 },
/* I */ { {0,0,0},{0,0,0},{0,0,0},{0,0,0},{3,18,30},{2,20,55},{1,12,50},    MK_ANY,  15,1, false,false, 0,0 },
/* J */ { {3,24,-1},{0,0,0},{0,0,0},{0,0,0},{0,0,0}, {0,0,0},{0,0,0}, MK_NONE, 0,0, false,false, 0,0 },
/* K */ { {0,0,0},{3,18,-1},{0,0,0},{0,0,0},{0,0,0}, {0,0,0},{0,0,0}, MK_NONE, 0,0, false,false, 0,0 },
/* L */ { {0,0,0},{0,0,0},{2,12,-1},{0,0,0},{0,0,0}, {0,0,0},{0,0,0}, MK_NONE, 0,0, false,false, 0,0 },
/* M */ { {0,0,0},{0,0,0},{0,0,0},{2,8,-1},{0,0,0},  {0,0,0},{0,0,0}, MK_NONE, 0,0, false,false, 0,0 },
/* N */ { {0,0,0},{0,0,0},{0,0,0},{0,0,0},{1,6,-1},  {0,0,0},{0,0,0}, MK_NONE, 0,0, false,false, 0,0 },
/* O */ { {1,4,25},{1,3,20},{0,0,0},{0,0,0},{0,0,0}, {0,0,0},{0,0,0}, MK_NONE, 0,0, false,false, 0,0 },
/* P */ { {0,0,0},{1,6,30},{1,2,25},{0,0,0},{0,0,0},  {0,0,0},{0,0,0}, MK_NONE, 0,0, false,false, 0,0 },
/* Q */ { {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},   {1,4,50},{0,0,0}, MK_NONE, 0,0, false,false, 0,0 },
/* R */ { {0,0,0},{0,0,0},{0,0,0},{2,8,40},{10,60,50},{4,32,55},{1,12,45}, MK_NONE, 0,0, false,false, 0,0 },
/* S */ { {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},   {0,0,0},{0,0,0}, MK_POTIONS, 40,0, false,false, 0,0 },
/* T */ { {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},   {0,0,0},{0,0,0}, MK_SCROLLS, 50,0, false,false, 0,0 },
/* U */ { {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},   {10,80,90},{5,30,80}, MK_EACH, 70,1, false,false, 0,0 },
/* V */ { {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},   {0,0,0},{0,0,0}, MK_EACH, 85,2, false,false, 0,0 },
/* W */ { {0,0,0},{0,0,0},{0,0,0},{5,30,60},{1,8,15},{10,80,60},{5,40,50}, MK_MAP, 55,0, false,false, 0,0 },
/* X */ { {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},   {0,0,0},{0,0,0}, MK_MISC_POTION, 60,0, false,false, 0,0 },
/* Y */ { {0,0,0},{0,0,0},{0,0,0},{2,12,70},{0,0,0}, {0,0,0},{0,0,0}, MK_NONE, 0,0, false,false, 0,0 },
/* Z */ { {1,3,20},{1,4,25},{1,4,25},{1,4,30},{1,6,30},{10,60,55},{5,30,50}, MK_ANY, 50,3, false,false, 0,0 },
};
// clang-format on

static long long rollCoins(rules::Dice& dice, const CoinCell& c,
                           int multiplier) {
    if (c.pct <= 0) return 0;
    if (c.pct < 100 && !pctRoll(dice, c.pct)) return 0;
    return (long long)inRange(dice, c.lo, c.hi) * multiplier;
}

static void addGems(rules::Dice& dice, Hoard& h, const GemCell& g) {
    if (g.pct <= 0) return;
    if (g.pct < 100 && !pctRoll(dice, g.pct)) return;
    int n = inRange(dice, g.lo, g.hi);
    for (int i = 0; i < n; ++i) {
        long long v = rollGemValue(dice);
        h.gemValue += v;
        ++h.gemCount;
        // R73: flavor - name the stone in the loot log
        char nb[96];
        snprintf(nb, sizeof nb, "a %s worth %lld gp",
                 gemName(dice, v), v);
        h.notes.push_back(nb);
    }
}

static void addJewelry(rules::Dice& dice, Hoard& h, const GemCell& j) {
    if (j.pct <= 0) return;
    if (j.pct < 100 && !pctRoll(dice, j.pct)) return;
    int n = inRange(dice, j.lo, j.hi);
    for (int i = 0; i < n; ++i) {
        const char* desc = "";
        long long v = rollJewelry(dice, &desc);
        h.jewelryValue += v;
        ++h.jewelryCount;
        // R73: flavor - name the piece in the loot log
        char nb[112];
        snprintf(nb, sizeof nb,
                 "jewelry of %s worth %lld gp", desc, v);
        h.notes.push_back(nb);
    }
}

Hoard rollTreasureType(rules::Dice& dice, char letter,
                       int nCreatures, bool magicOnly) {
    Hoard h;
    if (letter < 'A' || letter > 'Z') return h;
    const LetterDef& L = kLetters[letter - 'A'];

    // J-N: "pieces per individual" - the coin itself, per creature
    if (L.cp.pct == -1) {
        h.cp = (long long)inRange(dice, L.cp.lo, L.cp.hi) * nCreatures;
        return h;
    }
    if (L.sp.pct == -1) {
        h.sp = (long long)inRange(dice, L.sp.lo, L.sp.hi) * nCreatures;
        return h;
    }
    if (L.ep.pct == -1) {
        h.ep = (long long)inRange(dice, L.ep.lo, L.ep.hi) * nCreatures;
        return h;
    }
    if (L.gp.pct == -1) {
        h.gp = (long long)inRange(dice, L.gp.lo, L.gp.hi) * nCreatures;
        return h;
    }
    if (L.pp.pct == -1) {
        h.pp = (long long)inRange(dice, L.pp.lo, L.pp.hi) * nCreatures;
        return h;
    }

    if (!magicOnly) {
        h.cp = rollCoins(dice, L.cp, 1000);
        h.sp = rollCoins(dice, L.sp, 1000);
        h.ep = rollCoins(dice, L.ep, 1000);
        h.gp = rollCoins(dice, L.gp, 1000);
        h.pp = rollCoins(dice, L.pp, 100);   // platinum: 100's
        addGems(dice, h, L.gems);
        addJewelry(dice, h, L.jewelry);
    }

    // the maps-or-magic column
    if (L.magic != MK_NONE && pctRoll(dice, L.magicPct)) {
        switch (L.magic) {
            case MK_ANY:
                addAnyItems(dice, h, L.magicN, L.noSwords, L.noWeapons);
                for (int i = 0; i < L.extraPotions; ++i)
                    h.magic.push_back(rollFromCategory(dice, 0));
                for (int i = 0; i < L.extraScrolls; ++i)
                    h.magic.push_back(rollFromCategory(dice, 1));
                break;
            case MK_SAW: {
                // "sword, armor, or misc. weapon" - even thirds
                int pick = (int)dice.d(3) - 1;
                int cat = (pick == 0) ? 10 : (pick == 1) ? 9 : 11;
                h.magic.push_back(rollFromCategory(dice, cat));
                break;
            }
            case MK_POTIONS: {
                int n = inRange(dice, 2, 8);
                for (int i = 0; i < n; ++i)
                    h.magic.push_back(rollFromCategory(dice, 0));
                break;
            }
            case MK_SCROLLS: {
                int n = inRange(dice, 1, 4);
                for (int i = 0; i < n; ++i)
                    h.magic.push_back(rollFromCategory(dice, 1));
                break;
            }
            case MK_MAP:
                addMap(dice, h);
                break;
            case MK_MISC_POTION:
                // 1 misc. magic (E.1-E.5) plus 1 potion
                h.magic.push_back(rollFromCategory(dice,
                    4 + (int)dice.d(5) - 1));
                h.magic.push_back(rollFromCategory(dice, 0));
                break;
            case MK_EACH:
                addOneOfEach(dice, h, L.magicN);
                break;
            default:
                break;
        }
    }
    return h;
}

} // namespace treasure
} // namespace dm
