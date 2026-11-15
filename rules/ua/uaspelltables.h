// ===========================================================================
// Adnd1 - rules/ua/uaspelltables.h
// The UA SPELL TABLES (pp. 28-31) pins, part 1 (R341): the cleric
// tables, the druid tables and the magic-user cantrip table.
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
// The R80 spell registry (spells/spells.h) is the class/level seam.
//
// JUDGMENTs:
//   - the scope: part 1 pins the READABLE tables. The magic-user
//     spells tables (1st-5th and 7th-9th) and the illusionist
//     spell table are OCR-scrambled beyond row-aligned decode -
//     their head rows read clean but the column alignment breaks
//     mid-table (the interleaved tail rows) - they stay open
//     pending the PDF, the item stays open.
//   - the druid "2nd Level" fragment: the four readable rows (the
//     merged "Locate Invisibility To Animals Animals" cell plus
//     Shillelagh and Speak With Animals) all seam-verify against
//     the R228 druid roster as FIRST-level spells (Locate Animals,
//     Invisibility To Animals, Shillelagh, Speak With Animals -
//     all druid 1). The merged cell decodes as two interleaved
//     names (Locate/Invisibility + Animals/Animals). The "2nd
//     Level" header reads as a stray fragment: the visible rows
//     are the 1st-level roster; the actual 2nd-level list is
//     OCR-lost.
//   - the druid 5th column "Insect P|" fragment decodes to Insect
//     Plague - the R228 seam (druid 5) confirms both the name and
//     the column. The druid Sticks To Snakes prints in the 5th
//     column where the R228 seam reads druid 6 - pinned as
//     printed, the doubt noted pending the PDF.
//   - the cleric Spike Growth prints in the 5th column
//     (the PHB reads cleric 3rd) - pinned as printed,
//     the doubt noted pending the PDF.
//   - the cleric Cure Critical Wounds prints in the 5th column
//     (the PHB-consistent read); the R80 registry carries it at
//     cleric 4 - a registry quirk, not a print doubt: pinned as
//     printed, no seam assert against the registry for that cell.
//   - the cantrip "Gather Polish" cell is two names merged by the
//     OCR (Gather, Polish); both pin. The "Unlock" cantrip prints
//     in the Personal column - pinned as printed, the likely
//     column-slip noted pending the PDF.
//   - the cleric 2nd column "Silence 15 Radius" prints without the
//     apostrophe (the PHB print "Silence 15' Radius"); pinned as
//     printed.
//   - the MU useful-cantrip count: the acquisition prose prints
//     scrambled, but the fragments ("has one", "of each point",
//     "For of intelligence") assemble to one useful cantrip per
//     point of intelligence - the illusionist text ("one per point
//     of intelligence, up to intelligence minus 3") parallels it.
//     Pinned as the fragment decode, flagged.
//   - the Number columns prove the loss: the cleric Continued table
//     prints row numbers 15 and 16 (a 16+ row table) but only 7
//     readable rows; the druid 4th-6th table prints 4, 6, 10, 11
//     (garbled "1""), 12 - a 12-row table with 6 readable rows.
//
// OCR holes (the item stays open pending the PDF): the ENTIRE
// magic-user spells tables (1st-9th), the illusionist spell table
// and the illusionist minor-illusion cantrip list; the cleric 1st
// "ct Evil" cell (a garble matching no unique name), the cleric
// 2nd "draw" cell, the empty table cells (hole sentinels: the
// empty string), the cleric 7th column (no readable cell), the
// druid 1st/2nd/3rd lists beyond the four readable rows, and the
// two tables' Number columns.
// ===========================================================================

#pragma once

// R1057 applied
#include "rules/ua/uaregistry.h"

namespace rules {

// ---- the cleric table (pp. 28-29) ----
// The 1st-3rd level table: 20 printed rows. The empty string is
// the hole sentinel (an OCR-lost cell).
inline int uastClericTableRowCount()
    { return 20; }

inline const char* uastClericName(int lvl, int row) {
    const auto& rows = uaRows("ua_ast_cleric");
    if (rows.empty())
        return "";
    if (lvl < 1) lvl = 1;
    if (lvl > 3) lvl = 3;
    if (row < 0) row = 0;
    if (row > 19) row = 19;
    if ((int)rows.size() <= (lvl - 1) * 20
        + (row))
        return "";
    return rows[(lvl - 1) * 20
        + (row)].name.c_str();
}

// The readable cells per level column (18, 16, 20).
inline int uastClericReadableCount(int lvl) {
    const auto* g = uaTable(
        "ua_ast_cleric", "readable_count");
    if (lvl < 1) lvl = 1;
    if (lvl > 3) lvl = 3;
    if (!g) return 0;
    return (int)(*g)[lvl - 1];
}

// The Continued table (4th-7th): only fragments readable (the
// row numbers 15 and 16 prove a 16-row print).
inline int uastClericFragCount(int lvl) {
    const auto* g = uaTable(
        "ua_ast_cleric", "frag_count");
    if (lvl < 4) lvl = 4;
    if (lvl > 7) lvl = 7;
    if (!g) return 0;
    return (int)(*g)[lvl - 4];
}

inline const char* uastClericFragName(int lvl, int i) {
    const auto& rows = uaRows("ua_ast_frag");
    if (rows.empty())
        return "";
    if (lvl < 4) lvl = 4;
    if (lvl > 7) lvl = 7;
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    if ((int)rows.size() <= (lvl - 4) * 8
        + (i))
        return "";
    return rows[(lvl - 4) * 8
        + (i)].name.c_str();
}

// ---- the druid tables (p. 29) ----
// The four readable rows - the 1st-level roster per the R228
// seam (the "2nd Level" header is a stray fragment).
inline int uastDruid1stCount()
    { return 4; }

inline const char* uastDruid1stName(int i) {
    const auto& rows = uaRows("ua_ast_druid1");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// The 4th-6th table: 6 readable rows of a 12-row print.
inline int uastDruid4thCount()
    { return 6; }

inline const char* uastDruid4thName(int i) {
    const auto& rows = uaRows("ua_ast_druid4");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

inline int uastDruid5thCount()
    { return 6; }

inline const char* uastDruid5thName(int i) {
    const auto& rows = uaRows("ua_ast_druid5");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

inline int uastDruid6thCount()
    { return 5; }

inline const char* uastDruid6thName(int i) {
    const auto& rows = uaRows("ua_ast_druid6");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// ---- the magic-user cantrip table (p. 30) ----
// Six categories, 66 names (the Gather/Polish
// merge decodes to two; the Number column is
// OCR-lost). R401 clean-read fix: the table
// prints Tangle (reversed row 9) and Tweak
// (personal row 9) - the R341 decode read 64,
// missing both.
inline int uastCantripCategoryCount()
    { return 6; }

inline const char* uastCantripCategoryName(int cat) {
    const auto& rows = uaRows("ua_ast_cantrip_cat");
    if (rows.empty())
        return "";
    if (cat < 0) cat = 0;
    if (cat > 5) cat = 5;
    if ((int)rows.size() <= (cat))
        return "";
    return rows[cat].name.c_str();
}

// The name count per category (20, 12, 6,
// 10, 10, 8 - the R401 clean-read fix adds
// Tangle and Tweak).
inline int uastCantripCount(int cat) {
    const auto* g = uaTable(
        "ua_ast_cantrip_cat", "cantrip_count");
    if (cat < 0) cat = 0;
    if (cat > 5) cat = 5;
    if (!g) return 0;
    return (int)(*g)[cat];
}

inline const char* uastCantripName(int cat, int i) {
    const auto& rows = uaRows("ua_ast_cantrip_names");
    if (rows.empty())
        return "";
    if (cat < 0) cat = 0;
    if (cat > 5) cat = 5;
    if (i < 0) i = 0;
    if (i > 19) i = 19;
    if ((int)rows.size() <= (cat) * 20
        + (i))
        return "";
    return rows[(cat) * 20
        + (i)].name.c_str();
}

// ---- the cantrip acquisition prose (pp. 28, 31) ----
// The magic-user ranges (the useful count is the fragment
// decode - one per point of intelligence).
inline int uastMuCantripMaxNewCount()
    { return 3; }

inline bool uastMuUsefulOnePerIntPoint()
    { return true; }

inline int uastMuReversedMin()
    { return 2; }

inline int uastMuReversedMax()
    { return 8; }

inline int uastMuLegerdemainMin()
    { return 2; }

inline int uastMuLegerdemainMax()
    { return 5; }

inline int uastMuPersonAffectingMin()
    { return 2; }

inline int uastMuPersonAffectingMax()
    { return 8; }

inline int uastMuPersonalMin()
    { return 2; }

inline int uastMuPersonalMax()
    { return 8; }

inline int uastMuHauntingMin()
    { return 2; }

inline int uastMuHauntingMax()
    { return 5; }

// The illusionist ranges (clean print): the useful count is one
// per point of intelligence up to intelligence minus 3 (an 18
// intelligence chooses 15); 5-8 minor illusion cantrips.
inline int uastIlMinorIllusionMin()
    { return 5; }

inline int uastIlMinorIllusionMax()
    { return 8; }

inline int uastIlUsefulIntMinus()
    { return 3; }

inline int uastIlUsefulAtInt18()
    { return 15; }

inline int uastIlReversedMin()
    { return 2; }

inline int uastIlReversedMax()
    { return 5; }

inline int uastIlLegerdemainMin()
    { return 3; }

inline int uastIlLegerdemainMax()
    { return 6; }

inline int uastIlPersonAffectingMin()
    { return 2; }

inline int uastIlPersonAffectingMax()
    { return 5; }

inline int uastIlPersonalMin()
    { return 2; }

inline int uastIlPersonalMax()
    { return 5; }

inline int uastIlHauntingMin()
    { return 5; }

inline int uastIlHauntingMax()
    { return 8; }

// The caption note: all cantrips (plus the italic spells) are
// described in this volume.
inline bool uastNoteAllCantripsDescribedHere()
    { return true; }

}   // namespace rules