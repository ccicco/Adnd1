// ===========================================================================
// Adnd1 - rules/uascharts.h
// The UA APPENDIX S clerical
// quick-reference charts, R407:
// the five charts (pp. 121-122)
// - the second data round riding
// the R405 deity layer seam. The
// R406 stat-block precedent: the
// scan-clean cells pin; the
// pantheon prose stays open.
//
// Each chart prints one row per
// deity, 8 columns: DEITY, the
// SPHERE OF CONTROL, the RAIMENT
// head and body, the color(s),
// the HOLY DAYS, and the
// SACRIFICE/PROPITIATION
// frequency and form.
//
// The pantheon order rides the
// R406 stat table (dwarves 0-4,
// elves 5-9, halflings 10-13,
// gnomes 14-17, orcs 18-22).
//
// The sacred-animal table: 13
// named (Aerdrie any bird,
// Solonor stag; the halfling
// four; Baervan raccoon, Urdlen
// white mole, Segojan badger;
// Bahgtru ox, Shargaas bat,
// Yurtrus skeleton, Luthic cave
// bear); null = none (the five
// dwarves - the print says NO
// dwarven god has a sacred
// animal - plus Flandal and
// Ilneval).
//
// The cleric gender reads: the
// dwarven split (males of the
// male deities, females of the
// female ones), the elf and
// halfling either-gender, the
// all-male never-druid gnomish
// clerics.

#pragma once

namespace rules {

struct UscChartRow {
    const char* name;
    const char* sphere;
    const char* head;
    const char* body;
    const char* color;
    const char* days;
    const char* freq;
    const char* form;
};

// A tiny string equality (no library
// includes in the header).
inline bool uscStrEq(const char* a,
                     const char* b) {
    int i = 0;
    while (a[i] != 0 && b[i] != 0) {
        if (a[i] != b[i]) return false;
        ++i;
    }
    return a[i] == b[i];
}

// The five charts, 23 rows in the
// pantheon order of the R406 stat
// table.
inline const UscChartRow& uscChartRow(
        int i) {
    static const UscChartRow T[23] = {
        // ---- the dwarves ----
        { "Clanggedin", "war, battle",
          "war helm", "chain mail",
          "silver", "before battle",
          "before battle", "weapons" },
        { "Vergadain", "suspicion, trickery",
          "helmet", "chain mail",
          "gold", "full moon",
          "monthly", "gold" },
        { "Dumathoin", "secrets, earth",
          "bare", "leather",
          "brown", "new moon",
          "monthly", "gems & jewels" },
        { "Abbathor", "evil, greed",
          "leather cap", "leather",
          "red", "solar eclipses",
          "annually", "blood & gems" },
        { "Berronar", "safety, truth",
          "silvered helm", "chain mail",
          "silver", "new year's day",
          "annually", "silver" },
        // ---- the elves ----
        { "Aerdrie", "air, weather, birds",
          "one feather", "sky-blue robes",
          "sky blue",
          "spring & fall equinoxes",
          "semi-annual",
          "beautiful feathers" },
        { "Erevan",
          "mischief, change, thieves",
          "leather cap", "leather armor",
          "black", "eclipses",
          "varies", "stolen treasures" },
        { "Solonor", "archery, hunting",
          "green hood",
          "elfin chain & silver",
          "leaf green", "full moon",
          "monthly", "hunting trophies" },
        { "Hanali", "romance, beauty",
          "bare", "gold robes",
          "gold", "full moon",
          "monthly", "beautiful objects" },
        { "Labelas", "longevity, time",
          "bare", "gray robes",
          "light gray", "sunset",
          "daily", "prayers & knowledge" },
        // ---- the halflings ----
        { "Sheela",
          "agriculture, weather",
          "bare", "green robes",
          "green", "full moon",
          "monthly", "seeds" },
        { "Arvoreen", "defense, warriors",
          "helmet", "chainmail",
          "silver", "before battle",
          "varies", "silvered weapons" },
        { "Cyrrollalee",
          "trust, protection",
          "bare", "brown robes",
          "brown", "first day of month",
          "monthly", "prayers" },
        { "Brandobaris", "thieves",
          "feathered cap",
          "leather armor",
          "gray", "new moon",
          "monthly", "stolen items" },
        // ---- the gnomes ----
        { "Baervan",
          "adventure, thieves",
          "green cap", "brown clothes",
          "wood brown", "full moon",
          "monthly", "treasure items" },
        { "Urdlen", "evil",
          "bare", "white cloak",
          "white", "winter solstice",
          "annually", "blood & jewels" },
        { "Segojan", "earth, nature",
          "fur cap", "leather armor",
          "gray & dark brown",
          "first day of each season",
          "quarterly", "gemstones" },
        { "Flandal", "metalworking",
          "steel helm", "leather armor",
          "red", "midsummer's day",
          "annually", "forged weapons" },
        // ---- the orcs ----
        { "Bahgtru", "strength",
          "bare", "loincloth",
          "n/a", "battle days",
          "before battle",
          "bones of enemies" },
        { "Shargaas", "night, thieves",
          "leather cap", "leather armor",
          "red & black", "new moon",
          "monthly", "stolen items" },
        { "Ilneval", "warriors",
          "red metal helmet",
          "red metal armor",
          "red", "battle days",
          "before & after battle",
          "blood & weapons" },
        { "Yurtrus", "death, plague",
          "bare", "skins",
          "white", "full moon",
          "monthly", "sacrifices" },
        { "Luthic",
          "caves, healing, females",
          "fur cap", "leather armor",
          "brown & black",
          "midwinter's day",
          "yearly", "treasures" },
    };
    if (i < 0) i = 0;
    if (i > 22) i = 22;
    return T[i];
}

// The sacred animals, by the same
// deity index; null = none.
inline const char* uscSacredAnimal(
        int i) {
    static const char* const A[23] = {
        0, 0, 0, 0, 0,
        "any bird", 0, "stag", 0, 0,
        "butterfly", "war dog",
        "squirrel", "mouse",
        "raccoon", "white mole",
        "badger", 0,
        "ox", "bat", 0,
        "skeleton", "cave bear"
    };
    if (i < 0) i = 0;
    if (i > 22) i = 22;
    return A[i];
}

inline int uscChartRowCount()
    { return 23; }

inline int uscChartCount()
    { return 5; }

// The named sacred animals (the
// non-null cells): 13.
inline int uscNamedSacredAnimalCount()
    {
    int n = 0;
    for (int i = 0; i < 23; ++i)
        if (uscSacredAnimal(i) != 0) ++n;
    return n;
}

// The frequency drift catches:
// 10 rows print monthly, 4 print
// annually, 2 print before battle.
inline int uscFrequencyCount(
        const char* freq) {
    int n = 0;
    for (int i = 0; i < 23; ++i)
        if (uscStrEq(uscChartRow(i).freq,
                     freq)) ++n;
    return n;
}

// The cleric gender reads.
// The dwarven split: only male
// dwarves may become clerics of
// the male deities, females of
// the female ones.
inline bool uscDwarfClericGenderSplit()
    { return true; }

inline bool uscElfClericsEitherGender()
    { return true; }

inline bool
        uscHalflingClericsEitherGender()
    { return true; }

// Gnomish clerics are never druids
// and are all males.
inline bool uscGnomeClericsNeverDruids()
    { return true; }

inline bool uscGnomishClericsAllMale()
    { return true; }

// R784: the worship-site strings - the print's
// place-of-worship reads, the prose under the
// five clerical charts (pp. 121-122). The kind
// codes and the cleric-gender grid pin in
// rules/worshipsites.h; the strings ride here,
// one row per deity in the registry order. The
// compilation's Hanali row carries Solonor's
// cells wholesale; the print's fountain-or-spring
// stands. Erevan's read rides the print's own
// "can by worshiped" typo in the prose.
inline const char* uscWorshipSite(int i) {
    static const char* const W[23] = {
        "battlefield",   // Clangeddin
        "underground temple",   // Vergadain
        "underground temple",   // Dumathoin
        "underground temple",   // Abbathor
        "underground temple",   // Berronar
        "open hilltops",   // Aerdrie
        "never the same place twice",   // Erevan
        "deep forest",   // Solonor
        "by a fountain or spring",   // Hanali
        "small grove",   // Labelas
        "open field",   // Sheela
        "anywhere",   // Arvoreen
        "the home",   // Cyrrollalee
        "anywhere",   // Brandobaris
        "forest clearing",   // Baervan
        "underground cavern",   // Urdlen
        "subterranean temple",   // Segojan
        "underground forge",   // Flandal
        "battlefield",   // Bahgtru
        "anywhere",   // Shargaas
        "anywhere",   // Ilneval
        "underground crypt",   // Yurtrus
        "in a temple within a cave",   // Luthic
    };
    if (i < 0) i = 0;
    if (i > 22) i = 22;
    return W[i];
}
}   // namespace rules

