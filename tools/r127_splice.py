#!/usr/bin/python3
# tools/r127_splice.py - R127 waterborne/aerial encounter
# tables (DMG p.190, Appendix C WATERBORNE RANDOM MONSTER
# ENCOUNTERS - the surface-travel companion of the R60
# underwater set).
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints.
#  - dm/encounters.h + .cpp: the four p.190 waterborne
#    tables (fresh small/large body, salt shallow/deep),
#    line-diffed against the 1eonline.info Appendix C
#    compilation; rollWaterborneEncounter +
#    waterborneEncounterKeys + the WaterborneBand audit
#    accessors; the R70 sea loop rewires to them (the R60
#    underwater set stays pinned data for the future
#    diving layer)
#  - regtest.cpp: the R127 waterborne line-diff audit -
#    band continuity 1 -> 100 for the four tables and the
#    shared Dinosaur Subtable, flag and substitution spot
#    pins from the verified transcription (census 45)
#  - game/state_sea.cpp + game/appstate.h: the coaster
#    rolls waterborne encounters; the Men rows (buccaneer,
#    merchant, pirate-raider) get a sail log line
#  - tools/dmg_gap_report.md: the p.190 box flips
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding="ascii") as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), "w", encoding="ascii") as f:
        f.write(s)

def patch(p, old, new, tag, expect=1, marker=None):
    s = rd(p)
    # idempotency keys on a distinctive NEW-side marker
    # (the R125 lesson; an anchor that is a PREFIX of its
    # replacement still counts after the patch)
    if marker is None:
        marker = new
    if marker in s:
        already.append(tag)
        return
    n = s.count(old)
    if n != expect:
        fails.append(tag + ": anchor count " + str(n)
                     + " (expected " + str(expect) + ")")
        return
    wr(p, s.replace(old, new))
    applied.append(tag)

# R127-CHUNK-1-START (encounters.h + encounters.cpp)

patch("dm/encounters.h",
r"""
    WaterBody body, WaterDepth depth);

// R63: DMG Appendix C outdoor (wilderness) encounter tables""",
r"""
    WaterBody body, WaterDepth depth);

// R127: DMG Appendix C WATERBORNE encounter tables (Premium
// reprint p.190; line-diffed against the 1eonline.info
// Appendix C compilation - the surface-travel companion of
// the R60 underwater set, which the compilation omits and
// which stays on its R60 uploaded-DMG verification). Four
// tables: Fresh Water small body / large body, Salt Water
// shallow (coastal) / deep; the fresh-water body size rides
// the depth enum (SHALLOW = small body, DEEP = large body -
// the engine's documented selector). Dinosaur rows resolve
// on the shared p.190 Dinosaur Subtable against the second
// percentile. The same footnote clime gates as R60 (* cool
// only / ** warm only) re-roll per the book's own
// "otherwise roll again"; the fresh-water Dinosaur warm
// gate rides the parent row (the R60 convention). Counts
// come from the registry's noAppearing fields (the book
// prints no number columns for the waterborne tables
// either). Substitutions documented in-row: Koalinth ->
// hobgoblin, Kopoacinth -> gargoyle, Lacedon -> ghoul,
// Elf (aquatic) -> elf (R60 conventions), Pirate ->
// buccaneer and pirate (tribesman with small craft) ->
// caveman (no pirate record; the repo's tribesman
// convention), Mermaid -> merman (the MM Merman entry
// covers mermaids); whales follow the R61 size mapping.
// WIRED SINCE R127 - the sea travel loop rolls the
// salt-water waterborne tables (see game/appstate.h, R70;
// the R60 underwater set is pinned data for the future
// diving layer).
DungeonEncounter rollWaterborneEncounter(
    const monsters::MonsterRegistry& reg, rules::Dice& dice,
    int pctile, int pctile2,
    WaterBody body, WaterDepth depth, WaterClime clime);

// Every registry key the waterborne table (in both climes)
// can produce - the regtest-style companion.
std::vector<std::string> waterborneEncounterKeys(
    const monsters::MonsterRegistry& reg,
    WaterBody body, WaterDepth depth);

// R127: the printed band edges behind the waterborne tables
// and the p.190 Dinosaur Subtable (shared with the R60
// underwater set) - the regtest line-diff audit walks them.
// flags carries the footnote gates: 1 = cool waters only,
// 2 = warm waters only, 4 = deep water only.
struct WaterborneBand {
    std::string key;
    int lo;
    int hi;
    int flags;
};
std::vector<WaterborneBand> waterborneBands(
    WaterBody body, WaterDepth depth);
std::vector<WaterborneBand> dinosaurSubBands();

// R63: DMG Appendix C outdoor (wilderness) encounter tables""",
      "encounters.h: R127 waterborne API",
      marker="struct WaterborneBand {")

patch("dm/encounters.h",
r"""
// WIRED SINCE R70 - the sea travel loop rolls the salt-water
// tables (see game/appstate.h, R70).""",
r"""
// R70 wired the sea loop here; since R127 the sea travel
// loop rolls the p.190 WATERBORNE tables instead (see the
// R127 block above) - the underwater set stays pinned
// data for the future diving layer.""",
      "encounters.h: R60 wired note",
      marker="the underwater set stays pinned")

patch("dm/encounters.cpp",
r"""
    return out;
}

// ----------------------------------------------------------------------------
// R63: the outdoor (wilderness) encounter tables - DMG Appendix C""",
r"""
    return out;
}

// ----------------------------------------------------------------------------
// R127: the WATERBORNE encounter tables - DMG Appendix C
// (Premium reprint p.190; line-diffed against the 1eonline
// .info Appendix C compilation). The surface-travel
// companion of the R60 underwater set: Fresh Water small
// body / large body, Salt Water shallow (coastal) / deep.
// The compilation omits the underwater tables, so those
// stay on their R60 uploaded-DMG verification; the fresh
// body size rides the depth enum (SHALLOW = small body,
// DEEP = large body - the engine's documented selector).
// The Dinosaur rows resolve on the shared p.190 Dinosaur
// Subtable (second percentile). Footnote clime gates as
// R60 (* cool only / ** warm only) re-roll per the book's
// own "otherwise roll again"; the fresh-water Dinosaur
// warm gate rides the parent row (the R60 convention -
// the compilation prints the gate in the footnote text:
// Elasmosaurus / Mosasaurus / Plesiosaurus "must be in a
// relatively warm clime" in fresh water). Book readings
// pinned as printed: the compilation prints nixie
// cool-only in the small-body fresh table but warm-only
// in the large-body one - both transcribed as printed
// (the discrepancy rides the book-verify debt). Counts
// come from the registry's noAppearing fields (the book
// prints no number columns).
// Substitutions documented in-row: Koalinth -> hobgoblin,
// Kopoacinth -> gargoyle, Lacedon -> ghoul, Elf (aquatic)
// -> elf (R60), Pirate -> buccaneer (no pirate record; the
// MM Buccaneer entry covers sea-raiders), pirate
// (tribesman with small craft) -> caveman (the repo's
// tribesman convention), Mermaid -> merman (the MM Merman
// entry covers mermaids); whales follow the R61 size
// mapping (carnivorous L/M/S -> sperm / killer / black;
// plain L/M/S -> whale / right / beluga).

// ---- Fresh Water, Small Body of Water - DMG p.190 ----
static const WaterRow kWaterFreshSmall[] = {
    {  1, 15, "giant_beaver",     WF_COOL_ONLY},   // *
    { 16, 30, "crocodile",        WF_WARM_ONLY},   // **
    { 31, 40, "hippopotamus",     WF_WARM_ONLY},   // **
    { 41, 60, "lizard_man",       WF_NONE},
    { 61, 65, "nixie",            WF_COOL_ONLY},   // * (the large-body table prints ** - as printed, documented)
    { 66, 70, "nymph",            WF_NONE},
    { 71, 85, "giant_otter",      WF_NONE},
    { 86, 98, "snapping_turtle",  WF_NONE},
    { 99,100, "water_weird",      WF_NONE},
};

// ---- Fresh Water, Large Body of Water - DMG p.190 ----
static const WaterRow kWaterFreshLarge[] = {
    {  1,  2, "giant_beaver",     WF_COOL_ONLY},   // *
    {  3,  4, "giant_crayfish",   WF_NONE},
    {  5,  6, "crocodile",        WF_WARM_ONLY},   // **
    {  7, 10, "giant_crocodile",  WF_WARM_ONLY},   // **
    { 11, 15, "DINOSAUR",         WF_WARM_ONLY},   // the ** dino warm gate rides the parent row (R60 convention, documented)
    { 16, 21, "giant_gar",        WF_NONE},
    { 22, 23, "hippopotamus",     WF_WARM_ONLY},   // **
    { 24, 26, "hobgoblin",        WF_NONE},   // Koalinth
    { 27, 28, "gargoyle",         WF_NONE},   // Kopoacinth
    { 29, 29, "ghoul",            WF_NONE},   // Lacedon
    { 30, 33, "lizard_man",       WF_NONE},
    { 34, 48, "buccaneer",        WF_NONE},   // Man, buccaneer (or warship)
    { 49, 78, "merchant",         WF_NONE},   // Man, merchant
    { 79, 84, "buccaneer",        WF_NONE},   // Man, pirate -> buccaneer (no pirate record, documented)
    { 85, 85, "water_naga",       WF_NONE},
    { 86, 90, "nixie",            WF_WARM_ONLY},   // ** (the small-body table prints * - as printed, documented)
    { 91, 93, "giant_otter",      WF_NONE},
    { 94, 97, "giant_pike",       WF_NONE},
    { 98, 99, "snapping_turtle",  WF_NONE},
    {100,100, "water_weird",      WF_NONE},
};

// ---- Salt Water, Shallow Waters, Coastal Waters, Small
// ---- Inland Seas - DMG p.190
static const WaterRow kWaterSaltShallow[] = {
    {  1,  2, "giant_crocodile",  WF_WARM_ONLY},   // **
    {  3, 10, "DINOSAUR",         WF_NONE},
    { 11, 17, "dolphin",          WF_NONE},
    { 18, 18, "dragon_turtle",    WF_NONE},
    { 19, 20, "elf",              WF_NONE},   // Elf, aquatic
    { 21, 21, "ixitxachitl",      WF_NONE},
    { 22, 23, "hobgoblin",        WF_NONE},   // Koalinth
    { 24, 24, "gargoyle",         WF_NONE},   // Kopoacinth
    { 25, 25, "ghoul",            WF_NONE},   // Lacedon
    { 26, 26, "locathah",         WF_NONE},
    { 27, 35, "buccaneer",        WF_NONE},   // Man, buccaneer (warship)
    { 36, 63, "merchant",         WF_NONE},   // Man, merchant
    { 64, 67, "buccaneer",        WF_NONE},   // Man, pirate -> buccaneer (documented)
    { 68, 70, "caveman",          WF_NONE},   // Man, pirate (tribesman with small craft) -> caveman (the tribesman convention, documented)
    { 71, 73, "merman",           WF_NONE},   // Mermaid -> merman (the MM entry covers mermaids, documented)
    { 74, 74, "nymph",            WF_NONE},
    { 75, 75, "giant_octopus",    WF_NONE},   // Octopus, giant
    { 76, 80, "sahuagin",         WF_NONE},
    { 81, 83, "giant_shark",      WF_NONE},   // Shark, giant
    { 84, 86, "sea_snake",        WF_NONE},   // Snake, sea
    { 87, 89, "triton",           WF_NONE},
    { 90, 90, "sea_turtle",       WF_NONE},   // Turtle, giant, sea
    { 91, 96, "black_whale",      WF_NONE},   // Whale, carnivorous, small
    { 97,100, "white_whale_beluga", WF_NONE}, // Whale, small
};

// ---- Salt Water, Deep Waters - DMG p.190 ----
static const WaterRow kWaterSaltDeep[] = {
    {  1,  5, "DINOSAUR",         WF_NONE},
    {  6, 13, "dolphin",          WF_NONE},
    { 14, 14, "dragon_turtle",    WF_NONE},
    { 15, 16, "buccaneer",        WF_NONE},   // Man, buccaneer (warship)
    { 17, 25, "merchant",         WF_NONE},   // Man, merchant
    { 26, 27, "buccaneer",        WF_NONE},   // Man, pirate -> buccaneer (documented)
    { 28, 35, "merman",           WF_NONE},
    { 36, 40, "giant_octopus",    WF_NONE},   // Octopus, giant
    { 41, 45, "sahuagin",         WF_NONE},
    { 46, 50, "giant_shark",      WF_NONE},   // Shark, giant
    { 51, 53, "sea_snake",        WF_NONE},   // Snake, sea
    { 54, 55, "giant_squid",      WF_NONE},   // Squid, giant
    { 56, 65, "triton",           WF_NONE},
    { 66, 68, "sea_turtle",       WF_NONE},   // Turtle, giant, sea
    { 69, 72, "sperm_whale",      WF_NONE},   // Whale, carnivorous, large
    { 73, 78, "killer_whale",     WF_NONE},   // Whale, carnivorous, medium
    { 79, 85, "black_whale",      WF_NONE},   // Whale, carnivorous, small
    { 86, 90, "whale",            WF_NONE},   // Whale, large
    { 91, 95, "right_whale",      WF_NONE},   // Whale, medium
    { 96,100, "white_whale_beluga", WF_NONE}, // Whale, small
};

static const WaterRow* waterborneTable(WaterBody body,
                                       WaterDepth depth,
                                       size_t& count) {
    const WaterRow* t;
    if (body == WaterBody::FRESH) {
        if (depth == WaterDepth::SHALLOW) {
            t = kWaterFreshSmall; count = sizeof kWaterFreshSmall / sizeof kWaterFreshSmall[0];
        } else {
            t = kWaterFreshLarge; count = sizeof kWaterFreshLarge / sizeof kWaterFreshLarge[0];
        }
    } else {
        if (depth == WaterDepth::SHALLOW) {
            t = kWaterSaltShallow; count = sizeof kWaterSaltShallow / sizeof kWaterSaltShallow[0];
        } else {
            t = kWaterSaltDeep; count = sizeof kWaterSaltDeep / sizeof kWaterSaltDeep[0];
        }
    }
    return t;
}

// R127: the waterborne roll - see encounters.h.
DungeonEncounter rollWaterborneEncounter(
        const monsters::MonsterRegistry& reg, rules::Dice& dice,
        int pctile, int pctile2,
        WaterBody body, WaterDepth depth, WaterClime clime) {
    DungeonEncounter e;

    size_t n = 0;
    const WaterRow* t = waterborneTable(body, depth, n);

    for (int attempt = 0; attempt < 24; ++attempt) {
        const WaterRow* row = nullptr;
        for (size_t i = 0; i < n; ++i)
            if (pctile >= t[i].lo && pctile <= t[i].hi)
                { row = &t[i]; break; }
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
            for (size_t i = 0;
                 i < sizeof kDinoSub / sizeof kDinoSub[0]; ++i)
                if (pctile2 >= kDinoSub[i].lo
                    && pctile2 <= kDinoSub[i].hi)
                    { dr = &kDinoSub[i]; break; }
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
    size_t n = 0;
    const WaterRow* t = waterborneTable(body, depth, n);
    for (size_t i = 0; i < n; ++i) {
        std::string key = t[i].key;
        if (key == "DINOSAUR") {
            for (size_t d = 0;
                 d < sizeof kDinoSub / sizeof kDinoSub[0]; ++d)
                if (reg.find(kDinoSub[d].key))
                    pushUnique(out, kDinoSub[d].key);
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
    size_t n = 0;
    const WaterRow* t = waterborneTable(body, depth, n);
    for (size_t i = 0; i < n; ++i) {
        WaterborneBand b;
        b.key = t[i].key;
        b.lo  = t[i].lo;
        b.hi  = t[i].hi;
        b.flags = t[i].flags;
        out.push_back(b);
    }
    return out;
}

// The shared p.190 Dinosaur Subtable - see encounters.h.
std::vector<WaterborneBand> dinosaurSubBands() {
    std::vector<WaterborneBand> out;
    for (size_t i = 0;
         i < sizeof kDinoSub / sizeof kDinoSub[0]; ++i) {
        WaterborneBand b;
        b.key = kDinoSub[i].key;
        b.lo  = kDinoSub[i].lo;
        b.hi  = kDinoSub[i].hi;
        b.flags = kDinoSub[i].flags;
        out.push_back(b);
    }
    return out;
}

// ----------------------------------------------------------------------------
// R63: the outdoor (wilderness) encounter tables - DMG Appendix C""",
      "encounters.cpp: R127 waterborne tables + functions",
      marker="kWaterFreshSmall")

# R127-CHUNK-1-END
# R127-CHUNK-2-START (regtest + sea + gap report)

patch("regtest.cpp",
r"""
static bool bandHas(const std::vector<dm::OutdoorBand>& b,
                    const char* k, int lo, int hi) {
    for (const auto& x : b)
        if (x.key == k && x.lo == lo && x.hi == hi) return true;
    return false;
}
""",
r"""
static bool bandHas(const std::vector<dm::OutdoorBand>& b,
                    const char* k, int lo, int hi) {
    for (const auto& x : b)
        if (x.key == k && x.lo == lo && x.hi == hi) return true;
    return false;
}

// R127: the waterborne spot-check helper - exact key, band,
// and footnote-gate flags (1 = cool only, 2 = warm only,
// 4 = deep only)
static bool waterBandHas(const std::vector<dm::WaterborneBand>& b,
                         const char* k, int lo, int hi, int fl) {
    for (const auto& x : b)
        if (x.key == k && x.lo == lo && x.hi == hi
            && x.flags == fl) return true;
    return false;
}
""",
      "regtest.cpp: waterBandHas helper",
      marker="static bool waterBandHas(")

patch("regtest.cpp",
r"""
        printf("R126 wilderness line-diff audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----""",
r"""
        printf("R126 wilderness line-diff audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R127: waterborne line-diff audit ----
    {
        int bad = 0;
        namespace OE = dm;
        // the four p.190 waterborne tables chain 1 -> 100:
        // no gap, no overlap, no inverted band (the R122
        // line-diff shape on the p.190 waterborne set)
        for (int body = 0; body < 2; ++body) {
            for (int dep = 0; dep < 2; ++dep) {
                std::vector<OE::WaterborneBand> b =
                    OE::waterborneBands(
                        (OE::WaterBody)body,
                        (OE::WaterDepth)dep);
                if (b.empty()) { ++bad; continue; }
                int lo = 1;
                for (const OE::WaterborneBand& x : b) {
                    if (x.lo != lo || x.hi < x.lo) ++bad;
                    lo = x.hi + 1;
                }
                if (lo != 101) ++bad;
            }
        }
        // the shared p.190 Dinosaur Subtable chains likewise
        {
            std::vector<OE::WaterborneBand> b =
                OE::dinosaurSubBands();
            int lo = 1;
            for (const OE::WaterborneBand& x : b) {
                if (x.lo != lo || x.hi < x.lo) ++bad;
                lo = x.hi + 1;
            }
            if (lo != 101) ++bad;
        }
        // spot pins from the verified transcription - flags:
        // 1 = cool only, 2 = warm only, 4 = deep only
        {
            std::vector<OE::WaterborneBand> b = OE::waterborneBands(
                OE::WaterBody::FRESH, OE::WaterDepth::SHALLOW);
            if (!waterBandHas(b, "giant_beaver", 1, 15, 1)) ++bad;
            if (!waterBandHas(b, "nixie", 61, 65, 1)) ++bad;
        }
        {
            std::vector<OE::WaterborneBand> b = OE::waterborneBands(
                OE::WaterBody::FRESH, OE::WaterDepth::DEEP);
            if (!waterBandHas(b, "DINOSAUR", 11, 15, 2)) ++bad;
            if (!waterBandHas(b, "nixie", 86, 90, 2)) ++bad;
            if (!waterBandHas(b, "buccaneer", 34, 48, 0)) ++bad;
            if (!waterBandHas(b, "merchant", 49, 78, 0)) ++bad;
            if (!waterBandHas(b, "buccaneer", 79, 84, 0)) ++bad;
        }
        {
            std::vector<OE::WaterborneBand> b = OE::waterborneBands(
                OE::WaterBody::SALT, OE::WaterDepth::SHALLOW);
            if (!waterBandHas(b, "giant_crocodile", 1, 2, 2)) ++bad;
            if (!waterBandHas(b, "DINOSAUR", 3, 10, 0)) ++bad;
            if (!waterBandHas(b, "caveman", 68, 70, 0)) ++bad;
            if (!waterBandHas(b, "merman", 71, 73, 0)) ++bad;
            if (!waterBandHas(b, "black_whale", 91, 96, 0)) ++bad;
            if (!waterBandHas(b, "white_whale_beluga", 97, 100, 0)) ++bad;
        }
        {
            std::vector<OE::WaterborneBand> b = OE::waterborneBands(
                OE::WaterBody::SALT, OE::WaterDepth::DEEP);
            if (!waterBandHas(b, "DINOSAUR", 1, 5, 0)) ++bad;
            if (!waterBandHas(b, "giant_squid", 54, 55, 0)) ++bad;
            if (!waterBandHas(b, "sperm_whale", 69, 72, 0)) ++bad;
            if (!waterBandHas(b, "whale", 86, 90, 0)) ++bad;
            if (!waterBandHas(b, "right_whale", 91, 95, 0)) ++bad;
            if (!waterBandHas(b, "white_whale_beluga", 96, 100, 0)) ++bad;
        }
        {
            std::vector<OE::WaterborneBand> b =
                OE::dinosaurSubBands();
            if (!waterBandHas(b, "archelon_ischyros", 1, 15, 0)) ++bad;
            if (!waterBandHas(b, "dinichthys", 16, 35, 4)) ++bad;
            if (!waterBandHas(b, "plesiosaurus", 76, 100, 0)) ++bad;
        }
        {
            // the Men substitutions resolve, and no phantom
            // mermaid/pirate key survives
            std::vector<std::string> k = OE::waterborneEncounterKeys(
                reg, OE::WaterBody::SALT, OE::WaterDepth::DEEP);
            int seen = 0;
            for (const std::string& x : k) {
                if (x == "merman" || x == "buccaneer" ||
                    x == "merchant" || x == "giant_squid" ||
                    x == "sperm_whale") ++seen;
            }
            if (seen != 5) ++bad;
        }
        {
            std::vector<std::string> k = OE::waterborneEncounterKeys(
                reg, OE::WaterBody::SALT, OE::WaterDepth::SHALLOW);
            int seen = 0;
            for (const std::string& x : k) {
                if (x == "mermaid" || x == "pirate") ++bad;
                if (x == "caveman" || x == "merman") ++seen;
            }
            if (seen != 2) ++bad;
        }
        printf("R127 waterborne line-diff audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----""",
      "regtest.cpp: R127 waterborne line-diff audit",
      marker="R127: waterborne line-diff audit")

patch("game/state_sea.cpp",
r"""
        dm::DungeonEncounter e = dm::rollWaterEncounter(
            registry, dice,
            (int)dice.roll(1, 100, 0), (int)dice.roll(1, 100, 0),
            dm::WaterBody::SALT, seaDepth(),
            dm::WaterClime::COOL);""",
r"""
        // R127: the p.190 waterborne tables - a surface
        // voyage rolls waterborne encounters (R70 had wired
        // the R60 underwater set; the coaster sails the top)
        dm::DungeonEncounter e = dm::rollWaterborneEncounter(
            registry, dice,
            (int)dice.roll(1, 100, 0), (int)dice.roll(1, 100, 0),
            dm::WaterBody::SALT, seaDepth(),
            dm::WaterClime::COOL);""",
      "state_sea.cpp: seaStep rolls waterborne",
      marker="rollWaterborneEncounter")

patch("game/state_sea.cpp",
r"""
        char buf[96];
        if (e.count == 1)
            snprintf(buf, sizeof buf,
                     "It rises from the waves - a wild %s "
                     "attacks the ship!", e.key.c_str());
        else
            snprintf(buf, sizeof buf,
                     "%d wild %ss attack the ship!",
                     e.count, e.key.c_str());
        log.add(buf);""",
r"""
        char buf[96];
        if (e.key == "buccaneer" || e.key == "merchant"
            || e.key == "caveman") {
            // R127: the waterborne Men rows - sails on the
            // horizon, not fins below the keel
            snprintf(buf, sizeof buf,
                     "Sail ho! %d %ss close on the coaster - "
                     "steel follows!", e.count, e.key.c_str());
        } else if (e.count == 1) {
            snprintf(buf, sizeof buf,
                     "It rises from the waves - a wild %s "
                     "attacks the ship!", e.key.c_str());
        } else {
            snprintf(buf, sizeof buf,
                     "%d wild %ss attack the ship!",
                     e.count, e.key.c_str());
        }
        log.add(buf);""",
      "state_sea.cpp: the Men sail log line",
      marker="Sail ho!")

patch("game/appstate.h",
r"""
    MODE_SEA,          // R70: sea voyage (R60 salt-water tables)""",
r"""
    MODE_SEA,          // R70: sea voyage (R127 p.190 waterborne)""",
      "appstate.h: MODE_SEA comment",
      marker="R127 p.190 waterborne")

patch("tools/dmg_gap_report.md",
r"""
- [ ] **Waterborne/aerial encounter tables
      (p.190)** - alongside the crew economy.""",
r"""
- [x] **Waterborne/aerial encounter tables
      (p.190)** - CLOSED R127: the four p.190 waterborne
      tables (fresh water small/large body, salt water
      shallow/coastal and deep) are pinned row-by-row,
      line-diffed against the 1eonline.info Appendix C
      compilation, and wired into the sea travel loop
      (R70 had rolled the R60 underwater set; the coaster
      now rolls surface encounters - buccaneers,
      merchants, pirates, mermaids, whales - and the
      underwater set stays pinned data for the future
      diving layer). Dinosaur rows resolve on the shared
      p.190 Dinosaur Subtable; the fresh-water warm gate
      rides the parent row per the R60 convention.
      Aerial: the DMG prints no separate aerial table -
      airborne play resolves on the wilderness tables'
      airborne rows (the ^75^ markers, pinned R63/R126),
      documented. Substitutions pinned in-row (pirate ->
      buccaneer, tribesman small craft -> caveman,
      mermaid -> merman). Pinned by the R127 battery
      audit; census 45.""",
      "gap report: waterborne box flips",
      marker="CLOSED R127:")

# ---- the end ----
if fails:
    for f in fails:
        print("FAIL: " + f)
    sys.exit(1)
if not applied and not already:
    print("FAIL: nothing to do - anchors not found?")
    sys.exit(1)
print("R127 splice: ALL OK (applied %d, already %d)"
      % (len(applied), len(already)))
