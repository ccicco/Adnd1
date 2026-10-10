// ===========================================================================
// Adnd1 - rules/sage.h
// The sage subsection (R310).
//
// The DMG SAGE subsection (upload line 2110):
// the fields-count table, the SAGE FIELDS OF
// STUDY AND SPECIAL KNOWLEDGE CATEGORIES, the
// CHANCE OF KNOWING ANSWER TO A QUESTION table,
// the sage characteristics (the six ability dice
// rows, the nine alignment bands, the 8d4 hit
// points, the spell limits), the SUPPORT and
// SALARY offer table, the efficiency economics
// with the improvement ladder, and the INFORMATION
// DISCOVERY TIME AND COST TABLE.
//
// The fields-count table: 6 dice bands (the minor
// fields and the special categories in the major
// field). The fields: 7 percent bands carrying 68
// special knowledge categories (humankind 12,
// demi-humankind 11, humanoids and giantkind 8,
// the physical universes 10, fauna 10, flora 8,
// supernatural and unusual 9).
//
// SOURCE NOTE: the 1eonline.info compilation
// cross-read agrees on every cell. The upload OCR
// flattened the seven-column print: HISTORY
// HISTORY reads History; HISTORY CHEMISTRY splits
// History (humanoids) and restores CHEMISTRY to
// the physical universes; INSECTS TREES splits
// Insects (fauna) and restores TREES to flora - a
// third transcription confirms both recoveries.
// The chance-of-knowing print row for the major
// field interleaves three bands (61-80, 57-60,
// 26-35); the compilation resolves the order.
//
// The none cells pin -1 (the print dash): the
// out-of-fields exacting chance and the
// out-of-fields exacting time - an exacting
// question outside the fields cannot be answered
// at all. The special-category specific time band
// is the only HOURS cell (1-10 h.); every general
// band is rounds.
//
// The recorded notes ride the pin: the hiring
// restriction (only fighters, paladins, rangers,
// thieves and assassins hire permanently; any
// class may consult short-term - 100 g.p. per day
// plus the question difficulty, one week maximum,
// a one-game-month cooldown after; permanent
// offers are lifetime service only, the sage
// bringing nothing save thinking ability and
// knowledge), the location prose (large towns and
// cities only, near colleges, schools and
// libraries), the spell casting level (the minimum
// class level for the spell; a sage with
// third-level magic-user use casts at 5th), the
// excluded spells (bless, chant, prayer, commune,
// raise dead, commune with nature, contact other
// plane and their reverses), the remote doubler
// (no nearby town doubles times and costs), the
// rest rule (1 day per 3 research days, 1-2 extra
// if bothered) and the unknown-information terms
// (51-100 percent of the maximum time at half
// cost). No engine site charges any of this yet
// (no sage consultation layer exists; the town
// stores price canonically).
//
// DATA-DRIVEN (the standing scope).
// ===========================================================================

#pragma once

namespace rules {

// ---- the fields of study ----

// The field count (the print: 7 fields).
inline int sageFieldCount() {
    return 7;
}

// The field name at index f (clamped).
inline const char* sageFieldName(int f) {
    static const char* const kNames[7] = {
        "Humankind",
        "Demi-Humankind",
        "Humanoids & Giantkind",
        "Physical Universe(s)",
        "Fauna",
        "Flora",
        "Supernatural & Unusual",
    };
    if (f < 0) f = 0;
    if (f > 6) f = 6;
    return kNames[f];
}

// The field percent band low (clamped; the
// seven bands tile 1-100).
inline int sageFieldLo(int f) {
    static const int kLo[7] = {
           1,   31,   51,   61,   71,   81,   91,
    };
    if (f < 0) f = 0;
    if (f > 6) f = 6;
    return kLo[f];
}

// The field percent band high (clamped).
inline int sageFieldHi(int f) {
    static const int kHi[7] = {
          30,   50,   60,   70,   80,   90,  100,
    };
    if (f < 0) f = 0;
    if (f > 6) f = 6;
    return kHi[f];
}

// The special knowledge categories in the
// field (clamped).
inline int sageFieldCategoryCount(int f) {
    static const int kCount[7] = {
          12,   11,    8,   10,   10,    8,    9,
    };
    if (f < 0) f = 0;
    if (f > 6) f = 6;
    return kCount[f];
}

// The flat index of the first category in the
// field (clamped); the categories run field by
// field in the print order.
inline int sageFieldCategoryFirst(int f) {
    static const int kFirst[7] = {
           0,   12,   23,   31,   41,   51,   59,
    };
    if (f < 0) f = 0;
    if (f > 6) f = 6;
    return kFirst[f];
}

// ---- the special knowledge categories ----

// The category count (the print: 68 categories
// across the seven fields).
inline int sageCategoryCount() {
    return 68;
}

// The category name at flat index i (clamped).
inline const char* sageCategoryName(int i) {
    static const char* const kNames[68] = {
        "Art & Music",
        "Biology",
        "Demography",
        "History",
        "Languages",
        "Legends & Folklore",
        "Law & Customs",
        "Philosophy & Ethics",
        "Politics & Genealogy",
        "Psychology",
        "Sociology",
        "Theology & Myth",
        "Art & Music",
        "Biology",
        "Demography",
        "Languages",
        "Legends & Folklore",
        "Law & Customs",
        "Philosophy & Ethics",
        "Politics & Genealogy",
        "Psychology",
        "Sociology",
        "Theology & Myth",
        "Biology",
        "Demography",
        "History",
        "Languages",
        "Legends & Folklore",
        "Law & Customs",
        "Sociology",
        "Theology & Myth",
        "Architecture & Engineering",
        "Astronomy",
        "Chemistry",
        "Geography",
        "Geology & Mineralogy",
        "Mathematics",
        "Meteorology & Climatology",
        "Oceanography",
        "Physics",
        "Topography & Cartography",
        "Amphibians",
        "Arachnids",
        "Avians",
        "Cephalopods & Echinoderms",
        "Crustaceans & Mollusks",
        "Ichthyoids",
        "Insects",
        "Mammals",
        "Marsupials",
        "Reptiles",
        "Bushes & Shrubs",
        "Flowers",
        "Fungi",
        "Grasses & Grains",
        "Herbs",
        "Mosses & Ferns",
        "Trees",
        "Weeds",
        "Astrology & Numerology",
        "Cryptography",
        "Divination",
        "Dweomercraeft",
        "Heraldry, Signs & Sigils",
        "Medicine",
        "Metaphysics",
        "Planes (Astral, Elemental & Ethereal)",
        "Planes (Outer)",
    };
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    return kNames[i];
}

// The owning field of the category at flat
// index i (clamped).
inline int sageCategoryField(int i) {
    static const int kField[68] = {
           0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
           0,    0,    1,    1,    1,    1,    1,    1,    1,    1,
           1,    1,    1,    2,    2,    2,    2,    2,    2,    2,
           2,    3,    3,    3,    3,    3,    3,    3,    3,    3,
           3,    4,    4,    4,    4,    4,    4,    4,    4,    4,
           4,    5,    5,    5,    5,    5,    5,    5,    5,    6,
           6,    6,    6,    6,    6,    6,    6,    6,
    };
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    return kField[i];
}

// ---- the fields-count table ----

// The dice band count.
inline int sageFieldsBandCount() {
    return 6;
}

// The dice band low (clamped; the six bands
// tile 1-100).
inline int sageFieldsBandLo(int b) {
    static const int kLo[6] = {
           1,   11,   31,   51,   71,   91,
    };
    if (b < 0) b = 0;
    if (b > 5) b = 5;
    return kLo[b];
}

// The dice band high (clamped).
inline int sageFieldsBandHi(int b) {
    static const int kHi[6] = {
          10,   30,   50,   70,   90,  100,
    };
    if (b < 0) b = 0;
    if (b > 5) b = 5;
    return kHi[b];
}

// The minor fields in the band (clamped).
inline int sageFieldsBandMinor(int b) {
    static const int kMinor[6] = {
           1,    1,    1,    2,    2,    2,
    };
    if (b < 0) b = 0;
    if (b > 5) b = 5;
    return kMinor[b];
}

// The special categories in the major field
// (clamped).
inline int sageFieldsBandSpecial(int b) {
    static const int kSpecial[6] = {
           2,    3,    4,    2,    3,    4,
    };
    if (b < 0) b = 0;
    if (b > 5) b = 5;
    return kSpecial[b];
}

// ---- the chance of knowing an answer ----

// The knowing percent band low (both clamped).
// Scope: 0 out of fields, 1 minor field, 2 major
// field, 3 special category. Nature: 0 general,
// 1 specific, 2 exacting. -1 pins the none cell
// (the print dash - an exacting question out of
// the fields cannot be answered at all).
inline int sageKnowLo(int scope, int nature) {
    static const int kLo[4][3] = {
        {  31,   11,   -1},
        {  46,   31,   11},
        {  61,   57,   26},
        {  81,   76,   61},
    };
    if (scope < 0) scope = 0;
    if (scope > 3) scope = 3;
    if (nature < 0) nature = 0;
    if (nature > 2) nature = 2;
    return kLo[scope][nature];
}

// The knowing percent band high (both clamped).
inline int sageKnowHi(int scope, int nature) {
    static const int kHi[4][3] = {
        {  50,   20,   -1},
        {  65,   40,   20},
        {  80,   60,   35},
        { 100,   96,   80},
    };
    if (scope < 0) scope = 0;
    if (scope > 3) scope = 3;
    if (nature < 0) nature = 0;
    if (nature > 2) nature = 2;
    return kHi[scope][nature];
}

// The none flag: 1 when the cell prints a dash.
inline int sageKnowNone(int scope, int nature) {
    return sageKnowLo(scope, nature) < 0;
}

// ---- the sage characteristics ----

// The ability row count (0 STR, 1 INT, 2 WIS,
// 3 DEX, 4 CON, 5 CHA).
inline int sageAbilityCount() {
    return 6;
}

// The ability die (clamped).
inline int sageAbilityDice(int a) {
    static const int kDice[6] = {
           8,    4,    6,    6,    6,    6,
    };
    if (a < 0) a = 0;
    if (a > 5) a = 5;
    return kDice[a];
}

// The ability dice count (clamped).
inline int sageAbilityDiceCount(int a) {
    static const int kCount[6] = {
           1,    1,    1,    3,    2,    2,
    };
    if (a < 0) a = 0;
    if (a > 5) a = 5;
    return kCount[a];
}

// The ability plus (clamped); the score bands
// run plus + count to plus + count * dice.
inline int sageAbilityPlus(int a) {
    static const int kPlus[6] = {
           7,   14,   12,    0,    3,    2,
    };
    if (a < 0) a = 0;
    if (a > 5) a = 5;
    return kPlus[a];
}

// The alignment band count (ascending dice
// order; the nine bands tile 1-100).
inline int sageAlignBandCount() {
    return 9;
}

// The alignment band low (clamped).
inline int sageAlignLo(int b) {
    static const int kLo[9] = {
           1,    6,   11,   21,   31,   41,   61,   81,   91,
    };
    if (b < 0) b = 0;
    if (b > 8) b = 8;
    return kLo[b];
}

// The alignment band high (clamped).
inline int sageAlignHi(int b) {
    static const int kHi[9] = {
           5,   10,   20,   30,   40,   60,   80,   90,  100,
    };
    if (b < 0) b = 0;
    if (b > 8) b = 8;
    return kHi[b];
}

// The alignment band name (clamped).
inline const char* sageAlignName(int b) {
    static const char* const kNames[9] = {
        "chaotic evil",
        "chaotic good",
        "chaotic neutral",
        "lawful evil",
        "lawful good",
        "lawful neutral",
        "neutral",
        "neutral evil",
        "neutral good",
    };
    if (b < 0) b = 0;
    if (b > 8) b = 8;
    return kNames[b];
}

// The hit points: 8d4 plus the constitution
// bonus as applicable.
inline int sageHpDiceCount() {
    return 8;
}

inline int sageHpDie() {
    return 4;
}

// ---- the spell skills ----

// The spell kind count.
inline int sageSpellKindCount() {
    return 3;
}

// The field spell kind (clamped): 0 clerical,
// 1 druidical, 2 magic-user or illusionist (the
// art and music and legends and folklore
// categories read clerical or magic-user).
inline int sageSpellKind(int f) {
    static const int kKind[7] = {
           0,    0,    0,    0,    1,    1,    2,
    };
    if (f < 0) f = 0;
    if (f > 6) f = 6;
    return kKind[f];
}

// The maximum spell level: d4 + 2, the 3-6
// band inclusive.
inline int sageSpellMaxDie() {
    return 4;
}

inline int sageSpellMaxPlus() {
    return 2;
}

inline int sageSpellMaxLo() {
    return 3;
}

inline int sageSpellMaxHi() {
    return 6;
}

// The spells held per level and the ready cap
// (1-4 per level, no more than 1 of each level
// available for use at a time).
inline int sageSpellPerLevelLo() {
    return 1;
}

inline int sageSpellPerLevelHi() {
    return 4;
}

inline int sageSpellReadyPerLevel() {
    return 1;
}

// ---- the employment offer ----

// The offer row count: row 0 the support and
// salary per month (2d6 hundred g.p.), row 1 the
// research grants per month (2d6 hundred g.p.),
// row 2 the initial material expenditure (the
// 20,000 g.p. minimum; lo equals hi).
inline int sageOfferCount() {
    return 3;
}

// The offer row low (clamped; g.p. per month).
inline int sageOfferLo(int i) {
    static const int kLo[3] = {
         200,  200, 20000,
    };
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    return kLo[i];
}

// The offer row high (clamped; g.p. per month).
inline int sageOfferHi(int i) {
    static const int kHi[3] = {
        1200, 1200, 20000,
    };
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    return kHi[i];
}

// ---- the efficiency economics ----

// The efficiency milestone count.
inline int sageEffMilestoneCount() {
    return 3;
}

// The milestone cost (clamped): 20,000 g.p.
// buys 50 percent, 60,000 reaches 90 and
// 100,000 the full 100 (the specific and
// exacting areas).
inline int sageEffMilestoneCost(int i) {
    static const int kCost[3] = {
        20000, 60000, 100000,
    };
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    return kCost[i];
}

// The milestone efficiency percent (clamped).
inline int sageEffMilestonePercent(int i) {
    static const int kPct[3] = {
          50,   90,  100,
    };
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    return kPct[i];
}

// The +1 percent step cost to 90 percent.
inline int sageEffStepCost() {
    return 1000;
}

// The +1 percent step cost after 90.
inline int sageEffHighCostPerPercent() {
    return 4000;
}

// ---- the improvement ladder ----

// The improvement row count: row 0 the
// out-of-fields knowledge +1 percent (5,000
// g.p. and a month, max +5), row 1 the
// minor-field ability +1 percent (10,000 g.p.
// and a month, max +5), row 2 an extra minor
// field (100,000 g.p. and two years, three
// maximum), row 3 an extra major field
// (200,000 g.p. and two years; -1 pins no
// stated maximum).
inline int sageImproveCount() {
    return 4;
}

// The improvement cost in g.p. (clamped).
inline int sageImproveCost(int i) {
    static const int kCost[4] = {
        5000, 10000, 100000, 200000,
    };
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    return kCost[i];
}

// The improvement time in months (clamped).
inline int sageImproveMonths(int i) {
    static const int kMonths[4] = {
           1,    1,   24,   24,
    };
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    return kMonths[i];
}

// The improvement maximum (clamped; -1 pins
// no stated maximum).
inline int sageImproveMax(int i) {
    static const int kMax[4] = {
           5,    5,    3,   -1,
    };
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    return kMax[i];
}

// ---- the information discovery table ----

// The discovery time band low (both clamped).
// Scope and nature read as the knowing table;
// -1 pins the none cell (the print dash).
inline int sageTimeLo(int scope, int nature) {
    static const int kLo[4][3] = {
        {   1,    2,   -1},
        {   1,    2,    5},
        {   1,    1,    3},
        {   1,    1,    2},
    };
    if (scope < 0) scope = 0;
    if (scope > 3) scope = 3;
    if (nature < 0) nature = 0;
    if (nature > 2) nature = 2;
    return kLo[scope][nature];
}

// The discovery time band high (both clamped).
inline int sageTimeHi(int scope, int nature) {
    static const int kHi[4][3] = {
        {   6,   24,   -1},
        {   4,   20,   40},
        {   3,   12,   30},
        {   2,   10,   12},
    };
    if (scope < 0) scope = 0;
    if (scope > 3) scope = 3;
    if (nature < 0) nature = 0;
    if (nature > 2) nature = 2;
    return kHi[scope][nature];
}

// The discovery time unit (both clamped):
// 0 rounds, 1 hours, 2 days (the lone HOURS
// cell the special-category specific band).
inline int sageTimeUnit(int scope, int nature) {
    static const int kUnit[4][3] = {
        {   0,    2,    0},
        {   0,    2,    2},
        {   0,    2,    2},
        {   0,    1,    2},
    };
    if (scope < 0) scope = 0;
    if (scope > 3) scope = 3;
    if (nature < 0) nature = 0;
    if (nature > 2) nature = 2;
    return kUnit[scope][nature];
}

// The none flag: 1 when the cell prints a dash.
inline int sageTimeNone(int scope, int nature) {
    return sageTimeLo(scope, nature) < 0;
}

// The g.p. cost per day for the scope (clamped).
inline int sageCostPerDay(int scope) {
    static const int kCost[4] = {
         100, 1000,  500,  200,
    };
    if (scope < 0) scope = 0;
    if (scope > 3) scope = 3;
    return kCost[scope];
}

// The free-cost spread threshold (clamped):
// a knowing roll in the lower 20 percent of
// the spread means the materials are on hand;
// the special category widens to the lower 80
// percent.
inline int sageFreeSpreadPercent(int scope) {
    static const int kFree[4] = {
          20,   20,   20,   80,
    };
    if (scope < 0) scope = 0;
    if (scope > 3) scope = 3;
    return kFree[scope];
}

// The unknown-information band: 51-100
// percent of the maximum time.
inline int sageUnknownPercentLo() {
    return 51;
}

inline int sageUnknownPercentHi() {
    return 100;
}

// The unknown-information cost divisor (the
// costs accrue at half the stated amount).
inline int sageUnknownCostDivisor() {
    return 2;
}

// The short-term terms: 100 g.p. per day plus
// the question difficulty, one week maximum,
// a one-game-month cooldown after.
inline int sageShortTermCostPerDay() {
    return 100;
}

inline int sageShortTermMaxDays() {
    return 7;
}

inline int sageShortTermCooldownMonths() {
    return 1;
}

// The permanent offer is lifetime service only.
inline int sagePermanentHireOnly() {
    return 1;
}

}  // namespace rules
