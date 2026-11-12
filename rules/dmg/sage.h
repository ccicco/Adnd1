// ===========================================================================
// Adnd1 - rules/dmg/sage.h
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

// R-refactor: namespace rules -> class Sage (instance methods)
class Sage {
public:


// ---- the fields of study ----

// The field count (the print: 7 fields).
    int sageFieldCount();


// The field name at index f (clamped).
    const char* sageFieldName(int f);


// The field percent band low (clamped; the
// seven bands tile 1-100).
    int sageFieldLo(int f);


// The field percent band high (clamped).
    int sageFieldHi(int f);


// The special knowledge categories in the
// field (clamped).
    int sageFieldCategoryCount(int f);


// The flat index of the first category in the
// field (clamped); the categories run field by
// field in the print order.
    int sageFieldCategoryFirst(int f);


// ---- the special knowledge categories ----

// The category count (the print: 68 categories
// across the seven fields).
    int sageCategoryCount();


// The category name at flat index i (clamped).
    const char* sageCategoryName(int i);


// The owning field of the category at flat
// index i (clamped).
    int sageCategoryField(int i);


// ---- the fields-count table ----

// The dice band count.
    int sageFieldsBandCount();


// The dice band low (clamped; the six bands
// tile 1-100).
    int sageFieldsBandLo(int b);


// The dice band high (clamped).
    int sageFieldsBandHi(int b);


// The minor fields in the band (clamped).
    int sageFieldsBandMinor(int b);


// The special categories in the major field
// (clamped).
    int sageFieldsBandSpecial(int b);


// ---- the chance of knowing an answer ----

// The knowing percent band low (both clamped).
// Scope: 0 out of fields, 1 minor field, 2 major
// field, 3 special category. Nature: 0 general,
// 1 specific, 2 exacting. -1 pins the none cell
// (the print dash - an exacting question out of
// the fields cannot be answered at all).
    int sageKnowLo(int scope, int nature);


// The knowing percent band high (both clamped).
    int sageKnowHi(int scope, int nature);


// The none flag: 1 when the cell prints a dash.
    int sageKnowNone(int scope, int nature);


// ---- the sage characteristics ----

// The ability row count (0 STR, 1 INT, 2 WIS,
// 3 DEX, 4 CON, 5 CHA).
    int sageAbilityCount();


// The ability die (clamped).
    int sageAbilityDice(int a);


// The ability dice count (clamped).
    int sageAbilityDiceCount(int a);


// The ability plus (clamped); the score bands
// run plus + count to plus + count * dice.
    int sageAbilityPlus(int a);


// The alignment band count (ascending dice
// order; the nine bands tile 1-100).
    int sageAlignBandCount();


// The alignment band low (clamped).
    int sageAlignLo(int b);


// The alignment band high (clamped).
    int sageAlignHi(int b);


// The alignment band name (clamped).
    const char* sageAlignName(int b);


// The hit points: 8d4 plus the constitution
// bonus as applicable.
    int sageHpDiceCount();
    int sageHpDie();


// ---- the spell skills ----

// The spell kind count.
    int sageSpellKindCount();


// The field spell kind (clamped): 0 clerical,
// 1 druidical, 2 magic-user or illusionist (the
// art and music and legends and folklore
// categories read clerical or magic-user).
    int sageSpellKind(int f);


// The maximum spell level: d4 + 2, the 3-6
// band inclusive.
    int sageSpellMaxDie();
    int sageSpellMaxPlus();
    int sageSpellMaxLo();
    int sageSpellMaxHi();


// The spells held per level and the ready cap
// (1-4 per level, no more than 1 of each level
// available for use at a time).
    int sageSpellPerLevelLo();
    int sageSpellPerLevelHi();
    int sageSpellReadyPerLevel();


// ---- the employment offer ----

// The offer row count: row 0 the support and
// salary per month (2d6 hundred g.p.), row 1 the
// research grants per month (2d6 hundred g.p.),
// row 2 the initial material expenditure (the
// 20,000 g.p. minimum; lo equals hi).
    int sageOfferCount();


// The offer row low (clamped; g.p. per month).
    int sageOfferLo(int i);


// The offer row high (clamped; g.p. per month).
    int sageOfferHi(int i);


// ---- the efficiency economics ----

// The efficiency milestone count.
    int sageEffMilestoneCount();


// The milestone cost (clamped): 20,000 g.p.
// buys 50 percent, 60,000 reaches 90 and
// 100,000 the full 100 (the specific and
// exacting areas).
    int sageEffMilestoneCost(int i);


// The milestone efficiency percent (clamped).
    int sageEffMilestonePercent(int i);


// The +1 percent step cost to 90 percent.
    int sageEffStepCost();


// The +1 percent step cost after 90.
    int sageEffHighCostPerPercent();


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
    int sageImproveCount();


// The improvement cost in g.p. (clamped).
    int sageImproveCost(int i);


// The improvement time in months (clamped).
    int sageImproveMonths(int i);


// The improvement maximum (clamped; -1 pins
// no stated maximum).
    int sageImproveMax(int i);


// ---- the information discovery table ----

// The discovery time band low (both clamped).
// Scope and nature read as the knowing table;
// -1 pins the none cell (the print dash).
    int sageTimeLo(int scope, int nature);


// The discovery time band high (both clamped).
    int sageTimeHi(int scope, int nature);


// The discovery time unit (both clamped):
// 0 rounds, 1 hours, 2 days (the lone HOURS
// cell the special-category specific band).
    int sageTimeUnit(int scope, int nature);


// The none flag: 1 when the cell prints a dash.
    int sageTimeNone(int scope, int nature);


// The g.p. cost per day for the scope (clamped).
    int sageCostPerDay(int scope);


// The free-cost spread threshold (clamped):
// a knowing roll in the lower 20 percent of
// the spread means the materials are on hand;
// the special category widens to the lower 80
// percent.
    int sageFreeSpreadPercent(int scope);


// The unknown-information band: 51-100
// percent of the maximum time.
    int sageUnknownPercentLo();
    int sageUnknownPercentHi();


// The unknown-information cost divisor (the
// costs accrue at half the stated amount).
    int sageUnknownCostDivisor();


// The short-term terms: 100 g.p. per day plus
// the question difficulty, one week maximum,
// a one-game-month cooldown after.
    int sageShortTermCostPerDay();
    int sageShortTermMaxDays();
    int sageShortTermCooldownMonths();


// The permanent offer is lifetime service only.
    int sagePermanentHireOnly();
};
