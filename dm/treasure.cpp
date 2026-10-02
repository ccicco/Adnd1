// ============================================================================
// Adnd1 - dm/treasure.cpp
// R71: MM Treasure Types (p.105) + DMG treasure determination (pp.25-27,
// 120-125). Data transcribed from the Curtiss-verified table files; see
// treasure.h for provenance. All rolls through rules::Dice - deterministic.
// ============================================================================

#include "treasure.h"

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

struct ItemRow {
    int lo, hi;
    const char* name;
    int xp, xpHi;      // xpHi > xp => uniform [xp, xpHi]
    int gp, gpHi;      // gpHi > gp => uniform [gp, gpHi]
    int qlo, qhi;      // qty range (0 = single)
};

static MagicItem makeItem(rules::Dice& dice, const ItemRow& r) {
    MagicItem m;
    m.name = r.name;
    m.xp = valIn(dice, r.xp, r.xpHi);
    m.gp = valIn(dice, r.gp, r.gpHi);
    if (r.qhi > 0) m.qty = inRange(dice, r.qlo, r.qhi);
    return m;
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

// ---- III.A Potions ----------------------------------------------------------
static const ItemRow kPotions[] = {
    { 1, 3,   "Potion of Animal Control", 250,0, 400,0, 0,0 },
    { 4, 6,   "Potion of Clairaudience", 250,0, 400,0, 0,0 },
    { 7, 9,   "Potion of Clairvoyance", 300,0, 500,0, 0,0 },
    { 10,12,  "Potion of Climbing", 300,0, 500,0, 0,0 },
    { 13,15,  "Potion of Delusion", 0,0, 150,0, 0,0 },
    { 16,18,  "Potion of Diminution", 300,0, 500,0, 0,0 },
    { 19,20,  "Potion of Dragon Control", 500,1000, 5000,9000, 0,0 },
    { 21,23,  "Potion of ESP", 500,0, 850,0, 0,0 },
    { 24,26,  "Potion of Extra-Healing", 400,0, 800,0, 0,0 },
    { 27,29,  "Potion of Fire Resistance", 250,0, 400,0, 0,0 },
    { 30,32,  "Potion of Flying", 500,0, 750,0, 0,0 },
    { 33,34,  "Potion of Gaseous Form", 300,0, 400,0, 0,0 },
    { 35,36,  "Potion of Giant Control", 400,900, 1000,6000, 0,0 },
    { 37,39,  "Potion of Giant Strength", 500,750, 900,1400, 0,0 },
    { 40,41,  "Potion of Growth", 250,0, 300,0, 0,0 },
    { 42,47,  "Potion of Healing", 200,0, 400,0, 0,0 },
    { 48,49,  "Potion of Heroism", 300,0, 500,0, 0,0 },
    { 50,51,  "Potion of Human Control", 500,0, 900,0, 0,0 },
    { 52,54,  "Potion of Invisibility", 250,0, 500,0, 0,0 },
    { 55,57,  "Potion of Invulnerability", 350,0, 500,0, 0,0 },
    { 58,60,  "Potion of Levitation", 250,0, 400,0, 0,0 },
    { 61,63,  "Potion of Longevity", 500,0, 1000,0, 0,0 },
    { 64,66,  "Oil of Etherealness", 600,0, 1500,0, 0,0 },
    { 67,69,  "Oil of Slipperiness", 400,0, 750,0, 0,0 },
    { 70,72,  "Philter of Love", 200,0, 300,0, 0,0 },
    { 73,75,  "Philter of Persuasiveness", 400,0, 850,0, 0,0 },
    { 76,78,  "Potion of Plant Control", 250,0, 300,0, 0,0 },
    { 79,81,  "Potion of Polymorph (self)", 200,0, 350,0, 0,0 },
    { 82,84,  "Potion of Poison", 0,0, 0,0, 0,0 },
    { 85,87,  "Potion of Speed", 200,0, 450,0, 0,0 },
    { 88,90,  "Potion of Super-Heroism", 450,0, 750,0, 0,0 },
    { 91,93,  "Potion of Sweet Water", 200,0, 250,0, 0,0 },
    { 94,96,  "Potion of Treasure Finding", 600,0, 2000,0, 0,0 },
    { 97,97,  "Potion of Undead Control", 700,0, 2500,0, 0,0 },
    { 98,100, "Potion of Water Breathing", 400,0, 900,0, 0,0 },
};

// ---- III.C Rings ------------------------------------------------------------
static const ItemRow kRings[] = {
    { 1,6,    "Ring of Contrariness", 0,0, 1000,0, 0,0 },
    { 7,12,   "Ring of Delusion", 0,0, 2000,0, 0,0 },
    { 13,14,  "Ring of Djinni Summoning", 3000,0, 20000,0, 0,0 },
    { 15,15,  "Ring of Elemental Command", 5000,0, 25000,0, 0,0 },
    { 16,21,  "Ring of Feather Falling", 1000,0, 5000,0, 0,0 },
    { 22,27,  "Ring of Fire Resistance", 1000,0, 5000,0, 0,0 },
    { 28,30,  "Ring of Free Action", 1000,0, 5000,0, 0,0 },
    { 31,33,  "Ring of Human Influence", 2000,0, 10000,0, 0,0 },
    { 34,40,  "Ring of Invisibility", 1500,0, 7500,0, 0,0 },
    { 41,43,  "Ring of Mammal Control", 1000,0, 5000,0, 0,0 },
    { 44,44,  "Ring of Multiple Wishes", 5000,0, 25000,0, 0,0 },
    { 45,60,  "Ring of Protection", 2000,4000, 10000,20000, 0,0 },
    { 61,61,  "Ring of Regeneration", 5000,0, 40000,0, 0,0 },
    { 62,63,  "Ring of Shooting Stars", 3000,0, 15000,0, 0,0 },
    { 64,65,  "Ring of Spell Storing", 2500,0, 22500,0, 0,0 },
    { 66,69,  "Ring of Spell Turning", 2000,0, 17500,0, 0,0 },
    { 70,75,  "Ring of Swimming", 1000,0, 5000,0, 0,0 },
    { 76,77,  "Ring of Telekinesis", 2000,0, 10000,0, 0,0 },
    { 78,79,  "Ring of Three Wishes", 3000,0, 15000,0, 0,0 },
    { 80,85,  "Ring of Warmth", 1000,0, 5000,0, 0,0 },
    { 86,90,  "Ring of Water Walking", 1000,0, 5000,0, 0,0 },
    { 91,98,  "Ring of Weakness", 0,0, 1000,0, 0,0 },
    { 99,99,  "Ring of Wizardry", 4000,0, 50000,0, 0,0 },
    { 100,100,"Ring of X-Ray Vision", 4000,0, 35000,0, 0,0 },
};

// ---- III.D Rods, Staves & Wands ---------------------------------------------
static const ItemRow kRods[] = {
    { 1,3,    "Rod of Absorption", 7500,0, 40000,0, 0,0 },
    { 4,4,    "Rod of Beguiling", 5000,0, 30000,0, 0,0 },
    { 5,14,   "Rod of Cancellation", 10000,0, 15000,0, 0,0 },
    { 15,16,  "Rod of Lordly Might", 6000,0, 20000,0, 0,0 },
    { 17,17,  "Rod of Resurrection", 10000,0, 35000,0, 0,0 },
    { 18,18,  "Rod of Rulership", 8000,0, 35000,0, 0,0 },
    { 19,19,  "Rod of Smiting", 4000,0, 15000,0, 0,0 },
    { 20,20,  "Staff of Command", 5000,0, 25000,0, 0,0 },
    { 21,22,  "Staff of Curing", 6000,0, 25000,0, 0,0 },
    { 23,23,  "Staff of the Magi", 15000,0, 75000,0, 0,0 },
    { 24,24,  "Staff of Power", 12000,0, 60000,0, 0,0 },
    { 25,27,  "Staff of the Serpent", 7000,0, 35000,0, 0,0 },
    { 28,31,  "Staff of Striking", 6000,0, 15000,0, 0,0 },
    { 32,33,  "Staff of Withering", 8000,0, 35000,0, 0,0 },
    { 34,34,  "Wand of Conjuration", 7000,0, 35000,0, 0,0 },
    { 35,38,  "Wand of Enemy Detection", 2000,0, 10000,0, 0,0 },
    { 39,41,  "Wand of Fear", 3000,0, 15000,0, 0,0 },
    { 42,44,  "Wand of Fire", 4500,0, 25000,0, 0,0 },
    { 45,47,  "Wand of Frost", 6000,0, 50000,0, 0,0 },
    { 48,52,  "Wand of Illumination", 2000,0, 10000,0, 0,0 },
    { 53,56,  "Wand of Illusion", 3000,0, 20000,0, 0,0 },
    { 57,59,  "Wand of Lightning", 4000,0, 30000,0, 0,0 },
    { 60,68,  "Wand of Magic Detection", 2500,0, 25000,0, 0,0 },
    { 69,73,  "Wand of Metal & Mineral Detection", 1500,0, 7500,0, 0,0 },
    { 74,78,  "Wand of Magic Missiles", 4000,0, 35000,0, 0,0 },
    { 79,86,  "Wand of Negation", 3500,0, 15000,0, 0,0 },
    { 87,89,  "Wand of Paralyzation", 3500,0, 25000,0, 0,0 },
    { 90,92,  "Wand of Polymorphing", 3500,0, 25000,0, 0,0 },
    { 93,94,  "Wand of Secret Door & Trap Location", 5000,0, 40000,0, 0,0 },
    { 95,100, "Wand of Wonder", 6000,0, 10000,0, 0,0 },
};

// ---- III.E.1 Miscellaneous Magic ----------------------------------------------
static const ItemRow kMisc1[] = {
    { 1,2,    "Alchemy Jug", 3000,0, 12000,0, 0,0 },
    { 3,4,    "Amulet of Inescapable Location", 0,0, 1000,0, 0,0 },
    { 5,5,    "Amulet of Life Protection", 5000,0, 20000,0, 0,0 },
    { 6,7,    "Amulet of the Planes", 6000,0, 30000,0, 0,0 },
    { 8,11,   "Amulet of Proof Against Detection and Location", 4000,0, 15000,0, 0,0 },
    { 12,13,  "Apparatus of Kwalish", 8000,0, 35000,0, 0,0 },
    { 14,16,  "Arrow of Direction", 2500,0, 17500,0, 0,0 },
    { 17,17,  "Artifact or Relic", 0,0, 0,0, 0,0 },   // Special table below
    { 18,20,  "Bag of Beans", 1000,0, 5000,0, 0,0 },
    { 21,21,  "Bag of Devouring", 0,0, 1500,0, 0,0 },
    { 22,26,  "Bag of Holding", 5000,0, 25000,0, 0,0 },
    { 27,27,  "Bag of Transmuting", 0,0, 500,0, 0,0 },
    { 28,29,  "Bag of Tricks", 2500,0, 15000,0, 0,0 },
    { 30,31,  "Beaker of Plentiful Potions", 1500,0, 12500,0, 0,0 },
    { 32,32,  "Boat, Folding", 10000,0, 25000,0, 0,0 },
    { 33,33,  "Book of Exalted Deeds", 8000,0, 40000,0, 0,0 },
    { 34,34,  "Book of Infinite Spells", 9000,0, 50000,0, 0,0 },
    { 35,35,  "Book of Vile Darkness", 8000,0, 40000,0, 0,0 },
    { 36,36,  "Boots of Dancing", 0,0, 5000,0, 0,0 },
    { 37,42,  "Boots of Elvenkind", 1000,0, 5000,0, 0,0 },
    { 43,47,  "Boots of Levitation", 2000,0, 15000,0, 0,0 },
    { 48,51,  "Boots of Speed", 2500,0, 20000,0, 0,0 },
    { 52,55,  "Boots of Striding and Springing", 2500,0, 20000,0, 0,0 },
    { 56,58,  "Bowl Commanding Water Elementals", 4000,0, 25000,0, 0,0 },
    { 59,59,  "Bowl of Watery Death", 0,0, 1000,0, 0,0 },
    { 60,79,  "Bracers of Defense", 500,0, 3000,0, 0,0 },  // per AC pt, below
    { 80,81,  "Bracers of Defenselessness", 0,0, 2000,0, 0,0 },
    { 82,84,  "Brazier Commanding Fire Elementals", 4000,0, 25000,0, 0,0 },
    { 85,85,  "Brazier of Sleep Smoke", 0,0, 1000,0, 0,0 },
    { 86,92,  "Brooch of Shielding", 1000,0, 10000,0, 0,0 },
    { 93,93,  "Broom of Animated Attack", 0,0, 3000,0, 0,0 },
    { 94,98,  "Broom of Flying", 2000,0, 10000,0, 0,0 },
    { 99,100, "Bucknard's Everfull Purse", 1500,4000, 15000,40000, 0,0 },
};

// ---- III.E.2 ------------------------------------------------------------------
static const ItemRow kMisc2[] = {
    { 1,6,    "Candle of Invocation", 1000,0, 5000,0, 0,0 },
    { 7,8,    "Carpet of Flying", 7500,0, 25000,0, 0,0 },
    { 9,10,   "Censer Controlling Air Elementals", 4000,0, 25000,0, 0,0 },
    { 11,11,  "Censer of Summoning Hostile Air Elementals", 0,0, 1000,0, 0,0 },
    { 12,13,  "Chime of Opening", 3500,0, 20000,0, 0,0 },
    { 14,14,  "Chime of Hunger", 0,0, 0,0, 0,0 },
    { 15,18,  "Cloak of Displacement", 3000,0, 17500,0, 0,0 },
    { 19,27,  "Cloak of Elvenkind", 1000,0, 6000,0, 0,0 },
    { 28,30,  "Cloak of Manta Ray", 2000,0, 12500,0, 0,0 },
    { 31,32,  "Cloak of Poisonousness", 0,0, 2500,0, 0,0 },
    { 33,55,  "Cloak of Protection", 1000,0, 10000,0, 0,0 }, // per plus, below
    { 56,60,  "Crystal Ball", 1000,0, 5000,0, 0,0 },
    { 61,61,  "Crystal Hypnosis Ball", 0,0, 3000,0, 0,0 },
    { 62,63,  "Cube of Force", 3000,0, 20000,0, 0,0 },
    { 64,65,  "Cube of Frost Resistance", 2000,0, 14000,0, 0,0 },
    { 66,67,  "Cubic Gate", 5000,0, 17500,0, 0,0 },
    { 68,69,  "Daern's Instant Fortress", 7000,0, 27500,0, 0,0 },
    { 70,72,  "Decanter of Endless Water", 1000,0, 3000,0, 0,0 },
    { 73,76,  "Deck of Many Things", 0,0, 10000,0, 0,0 },
    { 77,77,  "Drums of Deafening", 0,0, 500,0, 0,0 },
    { 78,79,  "Drums of Panic", 6500,0, 35000,0, 0,0 },
    { 80,85,  "Dust of Appearance", 1000,0, 4000,0, 0,0 },
    { 86,91,  "Dust of Disappearance", 2000,0, 8000,0, 0,0 },
    { 92,92,  "Dust of Sneezing and Choking", 0,0, 1000,0, 0,0 },
    { 93,93,  "Efreeti Bottle", 9000,0, 45000,0, 0,0 },
    { 94,94,  "Eversmoking Bottle", 500,0, 2500,0, 0,0 },
    { 95,95,  "Eyes of Charming", 4000,0, 24000,0, 0,0 },
    { 96,97,  "Eyes of the Eagle", 3500,0, 18000,0, 0,0 },
    { 98,99,  "Eyes of Minute Seeing", 2000,0, 12500,0, 0,0 },
    { 100,100,"Eyes of Petrification", 0,0, 0,0, 0,0 },
};

// ---- III.E.3 ------------------------------------------------------------------
static const ItemRow kMisc3[] = {
    { 1,15,   "Figurine of Wondrous Power", 100,0, 1000,0, 0,0 }, // per hit die
    { 16,16,  "Flask of Curses", 0,0, 1000,0, 0,0 },
    { 17,18,  "Gauntlets of Dexterity", 1000,0, 10000,0, 0,0 },
    { 19,20,  "Gauntlets of Fumbling", 0,0, 1000,0, 0,0 },
    { 21,22,  "Gauntlets of Ogre Power", 1000,0, 15000,0, 0,0 },
    { 23,25,  "Gauntlets of Swimming and Climbing", 1000,0, 10000,0, 0,0 },
    { 26,26,  "Gem of Brightness", 2000,0, 17500,0, 0,0 },
    { 27,27,  "Gem of Seeing", 2000,0, 25000,0, 0,0 },
    { 28,28,  "Girdle of Femininity/Masculinity", 0,0, 1000,0, 0,0 },
    { 29,29,  "Girdle of Giant Strength", 200,0, 2500,0, 0,0 },
    { 30,30,  "Helm of Brilliance", 2500,0, 60000,0, 0,0 },
    { 31,35,  "Helm of Comprehending Languages & Reading Magic", 1000,0, 12500,0, 0,0 },
    { 36,37,  "Helm of Opposite Alignment", 0,0, 1000,0, 0,0 },
    { 38,39,  "Helm of Telepathy", 3000,0, 35000,0, 0,0 },
    { 40,40,  "Helm of Teleportation", 2500,0, 30000,0, 0,0 },
    { 41,45,  "Helm of Underwater Action", 1000,0, 10000,0, 0,0 },
    { 46,46,  "Horn of Blasting", 5000,0, 55000,0, 0,0 },
    { 47,48,  "Horn of Bubbles", 0,0, 0,0, 0,0 },
    { 49,49,  "Horn of Collapsing", 1500,0, 25000,0, 0,0 },
    { 50,53,  "Horn of the Tritons", 2000,0, 17500,0, 0,0 },
    { 54,60,  "Horn of Valhalla", 1000,0, 15000,0, 0,0 },
    { 61,63,  "Horseshoes of Speed", 2000,0, 10000,0, 0,0 },
    { 64,65,  "Horseshoes of a Zephyr", 1500,0, 7500,0, 0,0 },
    { 66,70,  "Incense of Meditation", 500,0, 7500,0, 0,0 },
    { 71,71,  "Incense of Obsession", 0,0, 500,0, 0,0 },
    { 72,72,  "Ioun Stone", 300,0, 5000,0, 0,0 },
    { 73,78,  "Instrument of the Bards", 1000,0, 5000,0, 0,0 },
    { 79,80,  "Iron Flask", 0,0, 0,0, 0,0 },
    { 81,85,  "Javelin of Lightning", 250,0, 3000,0, 0,0 },
    { 86,90,  "Javelin of Piercing", 250,0, 3000,0, 0,0 },
    { 91,91,  "Jewel of Attacks", 0,0, 1000,0, 0,0 },
    { 92,92,  "Jewel of Flawlessness", 0,0, 1000,0, 0,0 },
    { 93,100, "Keoghtom's Ointment", 500,0, 10000,0, 0,0 },
};

// ---- III.E.4 ------------------------------------------------------------------
static const ItemRow kMisc4[] = {
    { 1,1,    "Libram of Gainful Conjuration", 8000,0, 40000,0, 0,0 },
    { 2,2,    "Libram of Ineffable Damnation", 8000,0, 40000,0, 0,0 },
    { 3,3,    "Libram of Silver Magic", 8000,0, 40000,0, 0,0 },
    { 4,4,    "Lyre of Building", 5000,0, 30000,0, 0,0 },
    { 5,5,    "Manual of Bodily Health", 5000,0, 50000,0, 0,0 },
    { 6,6,    "Manual of Gainful Exercise", 5000,0, 50000,0, 0,0 },
    { 7,7,    "Manual of Golems", 3000,0, 30000,0, 0,0 },
    { 8,8,    "Manual of Puissant Skill at Arms", 8000,0, 40000,0, 0,0 },
    { 9,9,    "Manual of Quickness of Action", 5000,0, 50000,0, 0,0 },
    { 10,10,  "Manual of Stealthy Pilfering", 8000,0, 40000,0, 0,0 },
    { 11,11,  "Mattock of the Titans", 3500,0, 7000,0, 0,0 },
    { 12,12,  "Maul of the Titans", 4000,0, 12000,0, 0,0 },
    { 13,15,  "Medallion of ESP", 1000,3000, 10000,30000, 0,0 },
    { 16,17,  "Medallion of Thought Projection", 0,0, 1000,0, 0,0 },
    { 18,18,  "Mirror of Life Trapping", 2500,0, 25000,0, 0,0 },
    { 19,19,  "Mirror of Mental Prowess", 5000,0, 50000,0, 0,0 },
    { 20,20,  "Mirror of Opposition", 0,0, 2000,0, 0,0 },
    { 21,23,  "Necklace of Adaptation", 1000,0, 10000,0, 0,0 },
    { 24,27,  "Necklace of Missiles", 50,0, 200,0, 0,0 },
    { 28,33,  "Necklace of Prayer Beads", 500,0, 3000,0, 0,0 },
    { 34,35,  "Necklace of Strangulation", 0,0, 1000,0, 0,0 },
    { 36,38,  "Net of Entrapment", 1000,0, 7500,0, 0,0 },
    { 39,42,  "Net of Snaring", 1000,0, 6000,0, 0,0 },
    { 43,44,  "Nolzur's Marvelous Pigments", 500,0, 3000,0, 0,0 },
    { 45,46,  "Pearl of Power", 200,0, 2000,0, 0,0 },
    { 47,48,  "Pearl of Wisdom", 500,0, 5000,0, 0,0 },
    { 49,50,  "Periapt of Foul Rotting", 0,0, 1000,0, 0,0 },
    { 51,53,  "Periapt of Health", 1000,0, 10000,0, 0,0 },
    { 54,60,  "Periapt of Proof Against Poison", 1500,0, 12500,0, 0,0 },
    { 61,64,  "Periapt of Wound Closure", 1000,0, 10000,0, 0,0 },
    { 65,70,  "Phylactery of Faithfulness", 1000,0, 7500,0, 0,0 },
    { 71,74,  "Phylactery of Long Years", 3000,0, 25000,0, 0,0 },
    { 75,76,  "Phylactery of Monstrous Attention", 0,0, 2000,0, 0,0 },
    { 77,84,  "Pipes of the Sewers", 1750,0, 8500,0, 0,0 },
    { 85,85,  "Portable Hole", 5000,0, 50000,0, 0,0 },
    { 86,100, "Quaal's Feather Token", 500,1000, 2000,7000, 0,0 },
};

// ---- III.E.5 (Robe/Rope split verified against the printed book) --------------
static const ItemRow kMisc5[] = {
    { 1,1,    "Robe of the Archmagi", 6000,0, 65000,0, 0,0 },
    { 2,8,    "Robe of Blending", 3500,0, 35000,0, 0,0 },
    { 9,9,    "Robe of Eyes", 4500,0, 50000,0, 0,0 },
    { 10,10,  "Robe of Powerlessness", 0,0, 1000,0, 0,0 },
    { 11,11,  "Robe of Scintillating Colors", 2750,0, 25000,0, 0,0 },
    { 12,19,  "Robe of Useful Items", 1500,0, 15000,0, 0,0 },
    { 20,25,  "Rope of Climbing", 1000,0, 10000,0, 0,0 },
    { 26,27,  "Rope of Constriction", 0,0, 1000,0, 0,0 },
    { 28,31,  "Rope of Entanglement", 1250,0, 12000,0, 0,0 },
    { 32,32,  "Rug of Smothering", 0,0, 1500,0, 0,0 },
    { 33,33,  "Rug of Welcome", 6500,0, 45000,0, 0,0 },
    { 34,34,  "Saw of Mighty Cutting", 1750,0, 12500,0, 0,0 },
    { 35,35,  "Scarab of Death", 0,0, 2500,0, 0,0 },
    { 36,38,  "Scarab of Enraging Enemies", 1000,0, 8000,0, 0,0 },
    { 39,40,  "Scarab of Insanity", 1500,0, 11000,0, 0,0 },
    { 41,46,  "Scarab of Protection", 2500,0, 25000,0, 0,0 },
    { 47,47,  "Spade of Colossal Excavation", 1000,0, 6500,0, 0,0 },
    { 48,48,  "Sphere of Annihilation", 3750,0, 30000,0, 0,0 },
    { 49,50,  "Stone of Controlling Earth Elementals", 1500,0, 12500,0, 0,0 },
    { 51,52,  "Stone of Good Luck (Luckstone)", 3000,0, 25000,0, 0,0 },
    { 53,54,  "Stone of Weight (Loadstone)", 0,0, 1000,0, 0,0 },
    { 55,57,  "Talisman of Pure Good", 3500,0, 27500,0, 0,0 },
    { 58,58,  "Talisman of the Sphere", 100,0, 10000,0, 0,0 },
    { 59,60,  "Talisman of Ultimate Evil", 3500,0, 32500,0, 0,0 },
    { 61,66,  "Talisman of Zagy", 1000,0, 10000,0, 0,0 },
    { 67,67,  "Tome of Clear Thought", 8000,0, 48000,0, 0,0 },
    { 68,68,  "Tome of Leadership and Influence", 7500,0, 40000,0, 0,0 },
    { 69,69,  "Tome of Understanding", 8000,0, 43500,0, 0,0 },
    { 70,76,  "Trident of Fish Command", 500,0, 4000,0, 0,0 },
    { 77,78,  "Trident of Submission", 1250,0, 12500,0, 0,0 },
    { 79,83,  "Trident of Warning", 1000,0, 10000,0, 0,0 },
    { 84,85,  "Trident of Yearning", 0,0, 1000,0, 0,0 },
    { 86,87,  "Vacuous Grimoire", 0,0, 1000,0, 0,0 },
    { 88,90,  "Well of Many Worlds", 6000,0, 12000,0, 0,0 },
    { 91,100, "Wings of Flying", 750,0, 7500,0, 0,0 },
};

// ---- III.E. Special: Artifacts (no x.p.; printed g.p. sale values) -----------
static const ItemRow kArtifacts[] = {
    { 1,1,    "Axe of the Dwarvish Lords", 0,0, 55000,0, 0,0 },
    { 2,2,    "Baba Yaga's Hut", 0,0, 90000,0, 0,0 },
    { 3,4,    "Codex of the Infinite Planes", 0,0, 62500,0, 0,0 },
    { 5,20,   "Crown of Might", 0,0, 50000,0, 0,0 },
    { 21,21,  "Crystal of the Ebon Flame", 0,0, 75000,0, 0,0 },
    { 22,22,  "Cup and Talisman of Al'Akbar", 0,0, 85000,0, 0,0 },
    { 23,24,  "Eye of Vecna", 0,0, 35000,0, 0,0 },
    { 25,25,  "Hand of Vecna", 0,0, 60000,0, 0,0 },
    { 26,26,  "Heward's Mystical Organ", 0,0, 25000,0, 0,0 },
    { 27,27,  "Horn of Change", 0,0, 20000,0, 0,0 },
    { 28,29,  "Invulnerable Coat of Arnd", 0,0, 47500,0, 0,0 },
    { 30,31,  "Iron Flask of Tuerny the Merciless", 0,0, 50000,0, 0,0 },
    { 32,32,  "Jacinth of Inestimable Beauty", 0,0, 100000,0, 0,0 },
    { 33,33,  "Johydee's Mask", 0,0, 40000,0, 0,0 },
    { 34,35,  "Kuroth's Quill", 0,0, 27500,0, 0,0 },
    { 36,37,  "Mace of Cuthbert", 0,0, 35000,0, 0,0 },
    { 38,38,  "Machine of Lum the Mad", 0,0, 72500,0, 0,0 },
    { 39,40,  "Mighty Servant of Leuk-O", 0,0, 185000,0, 0,0 },
    { 41,47,  "Orb of the Dragonkind", 0,0, 10000,80000, 0,0 },
    { 48,63,  "Orb of Might", 0,0, 100000,0, 0,0 },
    { 64,64,  "Queen Ehlissa's Marvelous Nightingale", 0,0, 112500,0, 0,0 },
    { 65,66,  "Recorder of Ye'Cind", 0,0, 80000,0, 0,0 },
    { 67,68,  "Ring of Gaxx", 0,0, 17500,0, 0,0 },
    { 69,74,  "Rod of Seven Parts", 0,0, 25000,0, 0,0 },
    { 75,91,  "Sceptre of Might", 0,0, 150000,0, 0,0 },
    { 92,92,  "Sword of Kas", 0,0, 97000,0, 0,0 },
    { 93,98,  "Teeth of Dahlver-Nar", 0,0, 5000,0, 0,0 },  // per tooth
    { 99,99,  "Throne of the Gods", 0,0, 0,0, 0,0 },
    { 100,100,"Wand of Orcus", 0,0, 10000,0, 0,0 },
};

// ---- III.F Armor and Shield ---------------------------------------------------
static const ItemRow kArmor[] = {
    { 1,5,    "Chain Mail +1", 600,0, 3500,0, 0,0 },
    { 6,9,    "Chain Mail +2", 1200,0, 7500,0, 0,0 },
    { 10,11,  "Chain Mail +3", 2000,0, 12500,0, 0,0 },
    { 12,19,  "Leather Armor +1", 300,0, 2000,0, 0,0 },
    { 20,26,  "Plate Mail +1", 800,0, 5000,0, 0,0 },
    { 27,32,  "Plate Mail +2", 1750,0, 10500,0, 0,0 },
    { 33,35,  "Plate Mail +3", 2750,0, 15500,0, 0,0 },
    { 36,37,  "Plate Mail +4", 3500,0, 20500,0, 0,0 },
    { 38,38,  "Plate Mail +5", 4500,0, 27500,0, 0,0 },
    { 39,39,  "Plate Mail of Etherealness", 5000,0, 30000,0, 0,0 },
    { 40,44,  "Plate Mail of Vulnerability", 0,0, 1500,0, 0,0 },
    { 45,50,  "Ring Mail +1", 400,0, 2500,0, 0,0 },
    { 51,55,  "Scale Mail +1", 500,0, 3000,0, 0,0 },
    { 56,59,  "Scale Mail +2", 1100,0, 6750,0, 0,0 },
    { 60,63,  "Splint Mail +1", 700,0, 4000,0, 0,0 },
    { 64,66,  "Splint Mail +2", 1500,0, 8500,0, 0,0 },
    { 67,68,  "Splint Mail +3", 2250,0, 14500,0, 0,0 },
    { 69,69,  "Splint Mail +4", 3000,0, 19000,0, 0,0 },
    { 70,75,  "Studded Leather +1", 400,0, 2500,0, 0,0 },
    { 76,84,  "Shield +1", 250,0, 2500,0, 0,0 },
    { 85,89,  "Shield +2", 500,0, 5000,0, 0,0 },
    { 90,93,  "Shield +3", 800,0, 8000,0, 0,0 },
    { 94,95,  "Shield +4", 1200,0, 12000,0, 0,0 },
    { 96,96,  "Shield +5", 1750,0, 17500,0, 0,0 },
    { 97,97,  "Shield, large, +1, +4 vs. missiles", 400,0, 4000,0, 0,0 },
    { 98,100, "Shield -1, missile attractor", 0,0, 750,0, 0,0 },
};

// ---- III.G Swords ---------------------------------------------------------------
static const ItemRow kSwords[] = {
    { 1,25,   "Sword +1", 400,0, 2000,0, 0,0 },
    { 26,30,  "Sword +1, +2 vs. magic-using & enchanted creatures", 600,0, 3000,0, 0,0 },
    { 31,35,  "Sword +1, +3 vs. lycanthropes & shape changers", 700,0, 3500,0, 0,0 },
    { 36,40,  "Sword +1, +3 vs. regenerating creatures", 800,0, 4000,0, 0,0 },
    { 41,45,  "Sword +1, +4 vs. reptiles", 800,0, 4000,0, 0,0 },
    { 46,49,  "Sword +1, Flame Tongue", 900,0, 4500,0, 0,0 },
    { 50,50,  "Sword +1, Luck Blade", 1000,0, 5000,0, 0,0 },
    { 51,58,  "Sword +2", 800,0, 4000,0, 0,0 },
    { 59,62,  "Sword +2, Giant Slayer", 900,0, 4500,0, 0,0 },
    { 63,66,  "Sword +2, Dragon Slayer", 900,0, 4500,0, 0,0 },
    { 67,67,  "Sword +2, Nine Lives Stealer", 1600,0, 8000,0, 0,0 },
    { 68,71,  "Sword +3", 1400,0, 7000,0, 0,0 },
    { 72,74,  "Sword +3, Frost Brand", 1600,0, 8000,0, 0,0 },
    { 75,76,  "Sword +4", 2000,0, 10000,0, 0,0 },
    { 77,77,  "Sword +4, Defender", 3000,0, 15000,0, 0,0 },
    { 78,78,  "Sword +5", 3000,0, 15000,0, 0,0 },
    { 79,79,  "Sword +5, Defender", 3600,0, 18000,0, 0,0 },
    { 80,80,  "Sword +5, Holy Avenger", 4000,0, 20000,0, 0,0 },
    { 81,81,  "Sword of Dancing", 4400,0, 22000,0, 0,0 },
    { 82,82,  "Sword of Wounding", 4400,0, 22000,0, 0,0 },
    { 83,83,  "Sword of Life Stealing", 5000,0, 25000,0, 0,0 },
    { 84,84,  "Sword of Sharpness", 7000,0, 35000,0, 0,0 },
    { 85,85,  "Sword, Vorpal Weapon", 10000,0, 50000,0, 0,0 },
    { 86,90,  "Sword +1, Cursed", 400,0, 0,0, 0,0 },
    { 91,95,  "Sword -2, Cursed", 600,0, 0,0, 0,0 },
    { 96,100, "Sword, Cursed Berserking", 900,0, 0,0, 0,0 },
};

// ---- III.H Miscellaneous Weapons ------------------------------------------------
// NOTE: rows 57-60 and 61-62 are BOTH printed "Hammer +2" with different
// values (Curtiss-verified against p.125) - transcribed verbatim.
static const ItemRow kWeapons[] = {
    { 1,8,    "Arrow +1", 20,0, 120,0, 2,24 },
    { 9,12,   "Arrow +2", 50,0, 300,0, 2,16 },
    { 13,14,  "Arrow +3", 75,0, 450,0, 2,12 },
    { 15,15,  "Arrow of Slaying", 250,0, 2500,0, 0,0 },
    { 16,20,  "Axe +1", 300,0, 1750,0, 0,0 },
    { 21,22,  "Axe +2", 600,0, 3750,0, 0,0 },
    { 23,23,  "Axe +2, Throwing", 750,0, 4500,0, 0,0 },
    { 24,24,  "Axe +3", 1000,0, 7000,0, 0,0 },
    { 25,27,  "Battle Axe +1", 400,0, 2500,0, 0,0 },
    { 28,32,  "Bolt +2", 50,0, 300,0, 2,20 },
    { 33,35,  "Bow +1", 500,0, 3500,0, 0,0 },
    { 36,36,  "Crossbow of Accuracy, +3", 2000,0, 12000,0, 0,0 },
    { 37,37,  "Crossbow of Distance", 1500,0, 7500,0, 0,0 },
    { 38,38,  "Crossbow of Speed", 1500,0, 7500,0, 0,0 },
    { 39,46,  "Dagger +1, +2 vs. creatures smaller than man-sized", 100,0, 750,0, 0,0 },
    { 47,50,  "Dagger +2, +3 vs. creatures larger than man-sized", 250,0, 2000,0, 0,0 },
    { 51,51,  "Dagger of Venom", 350,0, 3000,0, 0,0 },
    { 52,56,  "Flail +1", 450,0, 4000,0, 0,0 },
    { 57,60,  "Hammer +2", 300,0, 2500,0, 0,0 },
    { 61,62,  "Hammer +2", 650,0, 6000,0, 0,0 },
    { 63,63,  "Hammer +3, Dwarven Thrower", 1500,0, 15000,0, 0,0 },
    { 64,64,  "Hammer of Thunderbolts", 2500,0, 25000,0, 0,0 },
    { 65,67,  "Javelin +2", 750,0, 5000,0, 0,0 },
    { 68,72,  "Mace +1", 350,0, 3000,0, 0,0 },
    { 73,75,  "Mace +2", 700,0, 4500,0, 0,0 },
    { 76,76,  "Mace of Disruption", 1750,0, 17500,0, 0,0 },
    { 77,77,  "Mace +4", 1500,0, 15000,0, 0,0 },
    { 78,80,  "Military Pick +1", 350,0, 2500,0, 0,0 },
    { 81,83,  "Morning Star +1", 400,0, 3000,0, 0,0 },
    { 84,88,  "Scimitar +2", 750,0, 6000,0, 0,0 },
    { 89,89,  "Sling of Seeking +2", 700,0, 7000,0, 0,0 },
    { 90,94,  "Spear +1", 500,0, 3000,0, 0,0 },
    { 95,96,  "Spear +2", 1000,0, 6500,0, 0,0 },
    { 97,97,  "Spear +3", 1750,0, 15000,0, 0,0 },
    { 98,99,  "Spear, Cursed Backbiter", 0,0, 1000,0, 0,0 },
    { 100,100,"Trident (Military Fork) +3", 1500,0, 12500,0, 0,0 },
};

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

// ---- table row picker ------------------------------------------------------------
static MagicItem pickRow(rules::Dice& dice, const ItemRow* rows, int n) {
    int r = 1 + d100(dice);
    for (int i = 0; i < n; ++i)
        if (r >= rows[i].lo && r <= rows[i].hi)
            return makeItem(dice, rows[i]);
    return makeItem(dice, rows[n - 1]);
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
        return pickRow(dice, kArtifacts, COUNT_OF(kArtifacts));
    }
    return r;
}

// Categories: 0 potions, 1 scrolls, 2 rings, 3 rods/staves/wands,
// 4-8 misc magic E.1-E.5, 9 armor & shields, 10 swords, 11 misc weapons.
// R76: the item carries its category (MagicItem::category) so the
// app can act on what it is without re-parsing names.
static MagicItem rollFromCategoryUnset(rules::Dice& dice, int cat) {
    switch (cat) {
        case 0:  return pickRow(dice, kPotions, COUNT_OF(kPotions));
        case 1:  return rollScroll(dice);
        case 2:  return pickRow(dice, kRings, COUNT_OF(kRings));
        case 3:  return pickRow(dice, kRods, COUNT_OF(kRods));
        case 4:  return adjustSpecial(dice,
                     pickRow(dice, kMisc1, COUNT_OF(kMisc1)));
        case 5:  return adjustSpecial(dice,
                     pickRow(dice, kMisc2, COUNT_OF(kMisc2)));
        case 6:  return adjustSpecial(dice,
                     pickRow(dice, kMisc3, COUNT_OF(kMisc3)));
        case 7:  return adjustSpecial(dice,
                     pickRow(dice, kMisc4, COUNT_OF(kMisc4)));
        case 8:  return adjustSpecial(dice,
                     pickRow(dice, kMisc5, COUNT_OF(kMisc5)));
        case 9:  return pickRow(dice, kArmor, COUNT_OF(kArmor));
        case 10: return pickRow(dice, kSwords, COUNT_OF(kSwords));
        default: return pickRow(dice, kWeapons, COUNT_OF(kWeapons));
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

MagicItem rollMagicItem(rules::Dice& dice) {
    return rollFromCategory(dice, rollCategory(dice));
}

// ---- R122: line-diff pins ---------------------------------------------------
// The battery reads any printed row of the pp.121-125 tables so they
// are pinned, not just rolled (the R122 line-diff found all 383 rows
// faithful). Category 1 (scrolls) has no ItemRow rows - its pin count
// is the structure: 16 spell bands + 8 protection scrolls + 1 curse
// row. Category 12 is the Special artifact table.
static const ItemRow* pinTableFor(int category, int* n) {
    switch (category) {
        case 0:  *n = COUNT_OF(kPotions);   return kPotions;
        case 2:  *n = COUNT_OF(kRings);     return kRings;
        case 3:  *n = COUNT_OF(kRods);      return kRods;
        case 4:  *n = COUNT_OF(kMisc1);     return kMisc1;
        case 5:  *n = COUNT_OF(kMisc2);     return kMisc2;
        case 6:  *n = COUNT_OF(kMisc3);     return kMisc3;
        case 7:  *n = COUNT_OF(kMisc4);     return kMisc4;
        case 8:  *n = COUNT_OF(kMisc5);     return kMisc5;
        case 9:  *n = COUNT_OF(kArmor);     return kArmor;
        case 10: *n = COUNT_OF(kSwords);    return kSwords;
        case 11: *n = COUNT_OF(kWeapons);   return kWeapons;
        case 12: *n = COUNT_OF(kArtifacts); return kArtifacts;
        default: *n = 0; return nullptr;
    }
}

int magicTablePinCount(int category) {
    if (category == 1)
        return COUNT_OF(kSpellScrolls) + 9;  // + protection & curse
    int n = 0;
    pinTableFor(category, &n);
    return n;
}

bool magicTablePin(int category, int row, TablePin* out) {
    if (!out || category == 1) return false;
    int n = 0;
    const ItemRow* t = pinTableFor(category, &n);
    if (!t || row < 0 || row >= n) return false;
    const ItemRow& r = t[row];
    out->lo = r.lo;      out->hi = r.hi;
    out->name = r.name;
    out->xp = r.xp;      out->xpHi = r.xpHi;
    out->gp = r.gp;      out->gpHi = r.gpHi;
    out->qtyLo = r.qlo;  out->qtyHi = r.qhi;
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
