// ===========================================================================
// Adnd1 - rules/hierophant.h
// The UA druid hierophant ladder
// (pp. 16-18) pins (R330).
//
// Pin-era pattern (R322): pinned data only - no engine site exists. The
// R327 druid-23 pin is the seam; the R228 registry parameters carry
// the pre-15 engine rows.
//
// The OCR holes, documented (revisit
// with the PDF):
// - the earth table 01-85 HD cell: the
//   extract prints "6 HD earth
//   elemental", contradicting the 16 HD
//   reads of the fire, water, air and
//   para tables - pinned as the
//   creature only, HD omitted;
// - the L21 title cell: the grid shows
//   a partial "Hierophant" - pinned
//   as a hole (empty);
// - the L20 row cells: the title reads
//   from the clean prose ("Numinous
//   Hierophant", 20th level); the hp
//   cell follows the pinned formula;
// - the air-table bounds: rows 1-2
//   survive in the scrambled tail as
//   fragments ("95-98 =", "1") - the
//   bounds follow the fire/earth/water
//   reads (86-94, 95-98).
// ===========================================================================

#pragma once

namespace rules {

// ---- the top of the hierarchy (p. 16) ----
// The Great Druid is 14th; the Grand
// Druid 15th with 3,000,001 or more xp,
// attended by 9 druids of a special
// sort; he knows 6 spells of each
// level plus up to 6 bonus spell
// levels (any combination adding up
// to six). Three Archdruids (13th
// level) roam as his messengers and
// agents, each with 4 additional
// spell levels.
inline int greatDruidLevel()
    { return 14; }

inline int greatDruidXpLow()
    { return 1500001; }

inline int grandDruidLevel()
    { return 15; }

inline int grandDruidXpLow()
    { return 3000001; }

inline int grandDruidAttendantCount()
    { return 9; }

inline int grandDruidSpellsPerLevel()
    { return 6; }

inline int grandDruidBonusSpellLevels()
    { return 6; }

inline int archDruidCount()
    { return 3; }

inline int archDruidLevel()
    { return 13; }

inline int archDruidBonusSpellLevels()
    { return 4; }

// ---- the abdication (p. 16) ----
// A Grand Druid may abdicate after
// 500,000 additional xp (3,500,001 or
// more total); he relinquishes the 6
// bonus spell levels, his xp total
// drops to 1 (the 16th-level band
// starts at 1), and he rises again per
// the ladder below.
inline int druidAbdicateXpTotal()
    { return 3500001; }

inline int druidAbdicateAdditionalXp()
    { return 500000; }

inline int druidAbdicateXpAfter()
    { return 1; }

inline int druidAbdicateBonusRelinquished()
    { return 6; }

// ---- Druids Table I: the ladder ----
// The 16th-level band starts at 1 xp;
// each later level at 500,001, 1,000,
// 001, 1,500,001, 2,000,001, 2,500,
// 001, 3,000,001 and 3,500,001 (the
// printed lower bounds; the 20th row's
// upper-bound cell is OCR-lost, the
// lower bound clean).
inline int hierophantFirstLevel()
    { return 16; }

inline int hierophantTopLevel()
    { return 23; }

inline int hierophantXpBandLow(int level) {
    static const int k[8] = {
        1, 500001, 1000001, 1500001,
        2000001, 2500001, 3000001, 3500001
    };
    if (level < 16) return 0;
    if (level > 23) return 3500001;
    return k[level - 16];
}

// The hit-dice column: 15 dice plus
// (level - 15) hit points, 15+1 at
// 16th through 15+8 at 23rd (the 20th
// hp cell is OCR-lost; the formula is
// pinned by the seven clean cells).
inline int hierophantHitDice()
    { return 15; }

inline int hierophantHpBonus(int level) {
    if (level < 16) return 0;
    if (level > 23) return 8;
    return level - 15;
}

// The level titles - the known cells
// only. The 21st cell is OCR-lost (a
// partial "Hierophant") and reads
// empty; the 20th reads from the clean
// prose.
inline const char* hierophantTitleKnown(
        int level) {
    switch (level) {
        case 14: return "Great Druid";
        case 15: return "Grand Druid";
        case 16: return "Hierophant Druid";
        case 17: return "Hierophant Initiate";
        case 18: return "Hierophant Adept";
        case 19: return "Hierophant Master";
        case 20: return "Numinous Hierophant";
        case 22: return "Arcane Hierophant";
        case 23: return "Hierophant of"
                      " the Cabal";
        default:
            return "";   // level 21: the
                         // OCR-lost cell
    }
}

// ---- the spell abilities (p. 17) ----
// At 16th and above all spell-casting
// stays at the 15th-level maximums (6
// spells of each level, 1st through
// 7th); no bonus spell levels; the
// casting level rises with experience
// level; spell-like powers instead.
inline int hierophantSpellMaxPerLevel()
    { return 6; }

inline int hierophantSpellMaxSpellLevel()
    { return 7; }

inline int hierophantCastingLevelCap()
    { return 15; }

// ---- the 16th-level powers (p. 17) ----
// Immunity to all natural poisons
// (animal or vegetable, including
// monster poisons; not mineral poisons
// or poison gas); extra longevity
// equal to the level in decades;
// vigorous health; appearance
// alteration at will (1 segment, height
// and weight change up to 50%,
// apparent age from child to very old,
// any human or humanoid features,
// non-magical - undetectable short of
// true seeing).
inline int hierophantPoisonImmunityLevel()
    { return 16; }

inline int hierophantLongevityDecades(
        int level)
    { return level; }

inline int hierophantAppearanceAlterLevel()
    { return 16; }

// ---- the 17th-level powers ----
// Hibernation / suspended animation
// (same length as the longevity, no
// aging).
inline int hierophantHibernateLevel()
    { return 17; }

// ---- the plane-entry ladder (p. 17) ----
// Earth at 17th, Fire 18th, Water 19th,
// Air 20th, the Para-Planes 21st, the
// Plane of Shadow 22nd, and at 23rd
// any of the Inner Planes, the Inner
// Plane Probability Lines (the 7th
// Dimension) and the Plane of
// Concordant Opposition. Entry confers
// survival (the environment reads as
// natural); no time limit; 1 round of
// transference.
enum HierophantPlane : int {
    HIEROPH_PLANE_EARTH = 0,
    HIEROPH_PLANE_FIRE,
    HIEROPH_PLANE_WATER,
    HIEROPH_PLANE_AIR,
    HIEROPH_PLANE_PARA,
    HIEROPH_PLANE_SHADOW,
    HIEROPH_PLANE_INNER
};

inline int hierophantPlaneEnterLevel(
        int plane) {
    switch (plane) {
        case HIEROPH_PLANE_EARTH:
            return 17;
        case HIEROPH_PLANE_FIRE:
            return 18;
        case HIEROPH_PLANE_WATER:
            return 19;
        case HIEROPH_PLANE_AIR:
            return 20;
        case HIEROPH_PLANE_PARA:
            return 21;
        case HIEROPH_PLANE_SHADOW:
            return 22;
        case HIEROPH_PLANE_INNER:
            return 23;
        default:
            return 0;
    }
}

inline int hierophantPlaneTransferenceRounds()
    { return 1; }

// ---- the conjure ladder (p. 17) ----
// Water elemental at 17th, air at 18th,
// magma/smoke para-elemental at 19th,
// ice/ooze para-elemental at 20th; each
// usable once per day (16th level or
// higher only).
enum HierophantConjure : int {
    HIEROPH_CONJ_WATER = 0,
    HIEROPH_CONJ_AIR,
    HIEROPH_CONJ_MAGMA_SMOKE,
    HIEROPH_CONJ_ICE_OOZE
};

inline int hierophantConjureLevel(
        int conj) {
    switch (conj) {
        case HIEROPH_CONJ_WATER:
            return 17;
        case HIEROPH_CONJ_AIR:
            return 18;
        case HIEROPH_CONJ_MAGMA_SMOKE:
            return 19;
        case HIEROPH_CONJ_ICE_OOZE:
            return 20;
        default:
            return 0;
    }
}

inline int hierophantConjureUsesPerDay()
    { return 1; }

// ---- the conjuring tables (pp. 17-18) ----
// The PHB conjure fire elemental results
// stand (pp. 61-62); the conjure earth
// elemental results (p. 63) do not -
// use these tables. The conjuring
// character's level is the percent
// chance of conjuring a desired type
// (a 20th-level druid: 20%); the
// override applies to druids of 16th
// level or higher only.
//
// Table t: 0 fire, 1 earth, 2 water,
// 3 air, 4 para-elemental. The earth
// 01-85 HD cell is OCR-lost (the
// extract prints "6 HD", contradicting
// the parallel 16 HD reads) - the name
// carries the creature only. The air
// rows 1-2 bounds follow the
// fire/earth/water reads (fragment-
// verified in the scrambled tail).
inline int hierophantConjureRowCount(int t) {
    return t == 4 ? 3 : 4;
}

inline int hierophantConjureLow(
        int t, int row) {
    static const int lo[5][4] = {
        {1, 86, 95, 99},
        {1, 86, 95, 99},
        {1, 86, 95, 99},
        {1, 86, 95, 99},
        {1, 86, 96, 0}
    };
    if (t < 0) t = 0;
    if (t > 4) t = 4;
    if (row < 0) row = 0;
    if (row > 3) row = 3;
    return lo[t][row];
}

inline int hierophantConjureHigh(
        int t, int row) {
    static const int hi[5][4] = {
        {85, 94, 98, 100},
        {85, 94, 98, 100},
        {85, 94, 98, 100},
        {85, 94, 98, 100},
        {85, 95, 100, 0}
    };
    if (t < 0) t = 0;
    if (t > 4) t = 4;
    if (row < 0) row = 0;
    if (row > 3) row = 3;
    return hi[t][row];
}

inline const char* hierophantConjureName(
        int t, int row) {
    static const char* const k[5][4] = {
        {"16 HD fire elemental",
         "2-4 salamanders",
         "1 efreeti",
         "21-24 HD fire elemental"},
        {"earth elemental",
         "2-4 xorn",
         "1 dao",
         "21-24 HD earth elemental"},
        {"16 HD water elemental",
         "7-12 tritons on hippocampi",
         "1 marid",
         "21-24 HD water elemental"},
        {"16 HD air elemental",
         "2-4 invisible stalkers",
         "1 djinni",
         "21-24 HD air elemental"},
        {"16 HD para-elemental",
         "special",
         "21-24 HD para-elemental",
         ""}
    };
    if (t < 0) t = 0;
    if (t > 4) t = 4;
    if (row < 0) row = 0;
    if (row > 3) row = 3;
    return k[t][row];
}

// The para-elemental "special" row: the
// listed creatures (or similar, as
// appropriate to the plane).
inline int hierophantConjureSpecialCount()
    { return 4; }

inline const char*
hierophantConjureSpecialName(int i) {
    static const char* const k[4] = {
        "5-8 lava children",
        "5-8 winter wolves",
        "21-24 mudmen",
        "21-24 vapor rats"
    };
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    return k[i];
}

// The desire override and the conjured
// creature reads: the level is the
// percent chance; a conjured creature
// gains extra hp equal to the conjurer's
// levels (capped at the ilk maximum)
// and serves obediently and selflessly
// regardless of alignment.
inline int hierophantConjureDesirePercent(
        int level)
    { return level; }

inline int hierophantConjureHpBonus(
        int level)
    { return level; }

}   // namespace rules