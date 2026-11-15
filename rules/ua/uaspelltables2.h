// ===========================================================================
// Adnd1 - rules/ua/uaspelltables2.h
// The UA SPELL TABLES (pp. 30-31) pins, part 2 (R342): the magic-user
// spells tables and the illusionist spell table.
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
// The R80 spell registry (spells/spells.h) is the class/level seam.
//
// JUDGMENTs (the decode method): each column of the printed table is
// alphabetical, so a fragment's position forces its identity; the
// straight apostrophe normalizes the extract's typographic one.
//   - split names: Spider/[Climb]; Tenser's/[Floating]/[Disc]; Secure/
//     Shelter = Leomund's Secure Shelter (the attribution restored by
//     the L-sort position between Ice Storm and Magic Mirror); Minor
//     Globe of/[Invulnerability]; Otiluke's Resilient/[ere = Sphere];
//     Mordenkainen's Faithful/[Hound]; Rary's Mnemonic/[Enhancer];
//     Protection From Normal/[Missiles]; [L]/[Bolt] = Lightning Bolt
//     (registry seam-proven: the engine row reads MU 3); Wizard/
//     [Lock]; Prismatic/[Sphere].
//   - garble decodes: "Reso Magic" = Read Magic (position-forced: it
//     sorts between Protection From Evil and Shocking Grasp);
//     "588985888 Grasp" = Shocking Grasp; "From Evil" = the tail of
//     Protection From Evil (head lost); "Dis oor" = Dimension Door
//     (sorts between Dig and Enchanted Weapon); "Fics 2 LA Terrain" =
//     Hallucinatory Terrain (sorts between Fire Shield and Ice Storm);
//     "Ice" = Ice Storm (registry seam-proven: the engine row reads
//     MU 4); "Tiny Hut" = Leomund's Tiny Hut; "Runes" = Explosive
//     Runes; "Extension Il" = Extension II (the pair convention with
//     the 4th column's Extension I); "Monster Summoning Ili" =
//     Monster Summoning III; "Wall Iron of" and "Stone Wall of" =
//     word-order scrambles of Wall of Iron and Wall of Stone.
//   - merged-cell decodes: "Comprehend Languages Detect Evil" = two
//     names (col1 + col2); "Conjure Elemental Tentacles" = Conjure
//     Elemental (col5) + the leaked tail of Evard's Black Tentacles
//     (col4); "Leomund's Lamentable rosie Belabourment Jar Secret
//     Chest" = Leomund's Lamentable Belabourment + Magic Jar +
//     Leomund's Secret Chest (three 5th-level names, position-
//     verified); "Tasha's Uncontrollable ~~ Water Breathing" = the
//     2nd-level name plus the 3rd column's Water Breathing drifted
//     into the cell ("Laughter Hideous" below is its inverted tail);
//     "Protection From Normal Rary's Mnemonic" = the 3rd-level name
//     plus the 4th column's Rary's Mnemonic Enhancer; "Spider Taunt
//     Tenser's" = three 1st-level names; "Whip Wizard" = the 2nd-level
//     "Whip" plus Wizard Lock's head; "Disc ~~ Zephyr" = the 1st-level
//     Disc tail plus the 2nd-level Zephyr.
//   - R785: the "Whip" doubt STRIKES - the
//     uam2WhipName pin ("Whip (Evocation)", p. 52)
//     proves the cell reads a real UA 2nd-level
//     spell, not a garble.
//   - verbatim-with-doubt pins: "Stone Shape" prints in the 5th
//     column (the PHB reads MU 4th) and "Secret Page" in the 3rd (the
//     PHB reads 2nd) - pinned as printed, doubts noted; the 3rd- and
//     7th-column "Monster Summoning" cells print without numerals -
//     pinned verbatim, the numeral loss noted.
//
// R785 RESOLUTIONS (the PDF ledger closes; the ledger
// census pins in rules/ua/spelltableledger.h): the
// archive.org full-text OCR reads the continued table;
// the 6th-level column REPAIRS (17 names, uas2Mu6thName)
// and the drifted cells re-seat - Tenser's
// Transformation and Transmute Water To Dust belong
// to the 6th column, and the four other drifted 6th
// cells read in their own column; Clone and Otiluke's
// Telekinetic Sphere newly read; the fragment holes
// resolve against the UA-new description rosters and
// the R80 registry (Flaming = Flaming Sphere,
// Protection From = the cantrips tail, Detect = Detect
// Illusion, Item and Material resolve, Dispel = Dispel
// Illusion, Dolor resolves, Truename resolves, Gravity =
// the Reverse Gravity tail, Project Im = Project
// Image); Glassteel and Power Word Kill stay OPEN
// holes (absent from the print, the descriptions, and
// the registry); the "th Level" print stands (the 9
// stays lost); the row numbers stay unreliable (the
// alphabetical order contradicts them); the registry
// rows absent from the print stay noted, not pinned;
// the illusionist 3rd-6th columns resolve on the
// UA-new side (the R364-R368 description rosters,
// rules/uailspells3-7.h, carry 4/4/4/4 new names plus
// the 7th-level pair Shadow Walk and Weird); the
// PHB-side rows of those columns stay lost; the
// "Phantom Wind" fragment resolves (the UA-new 3rd
// roster carries it); the "Mirror" tail seam-decode
// stands (Mirror Image).

// ===========================================================================

#pragma once

// R1057 applied
#include "rules/ua/uaregistry.h"

namespace rules {

// ---- the MU 1st-5th table (pp. 30-31) ----
// The readable roster of the 1st-level column (35 names).
inline int uas2Mu1stCount()
    { return 35; }

inline const char* uas2Mu1stName(int i) {
    const auto& rows = uaRows("ua_s2_mu1");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// The 2nd-level column (30 names; "Whip" pinned as printed; the
// extract prints Suggestion in the 3rd column only).
inline int uas2Mu2ndCount()
    { return 30; }

inline const char* uas2Mu2ndName(int i) {
    const auto& rows = uaRows("ua_s2_mu2");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// The 3rd-level column (28 names; Secret Page pinned as printed).
inline int uas2Mu3rdCount()
    { return 28; }

inline const char* uas2Mu3rdName(int i) {
    const auto& rows = uaRows("ua_s2_mu3");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 27) i = 27;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// The 4th-level column (28 names).
inline int uas2Mu4thCount()
    { return 28; }

inline const char* uas2Mu4thName(int i) {
    const auto& rows = uaRows("ua_s2_mu4");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 27) i = 27;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// The 5th-level column (28 names; Stone Shape pinned as printed).
inline int uas2Mu5thCount()
    { return 28; }

inline const char* uas2Mu5thName(int i) {
    const auto& rows = uaRows("ua_s2_mu5");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 27) i = 27;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// ---- the MU continued table (6th-9th; the R785
// ledger repair rides rules/ua/spelltableledger.h) ----
// The repaired 7th-level roster (16 names: the nine
// readable print cells - including the numeral
// restorations Monster Summoning V and Drawmij's
// Instant Summons and the Reverse Gravity tail - the
// six UA-new description-roster names, and the
// registry row Limited Wish).
inline int uas2Mu7thCount()
    { return 16; }

inline const char* uas2Mu7thName(int i) {
    const auto& rows = uaRows("ua_s2_mu7");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 15) i = 15;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// The repaired 8th-level roster (10 names: the nine
// readable print cells - including the newly-read
// Clone and Otiluke's Telekinetic Sphere - and the
// UA-new Binding; Glassteel and Power Word Kill stay
// OPEN holes; Tenser's Transformation and Transmute
// Water To Dust re-seat to the 6th column).
inline int uas2Mu8thCount()
    { return 10; }

inline const char* uas2Mu8thName(int i) {
    const auto& rows = uaRows("ua_s2_mu8");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// The repaired 9th-level roster (8 names: the five
// readable print cells - Energy Drain, Gate, Prismatic
// Sphere, Shape Change, Wish - and the UA-new
// Crystalbrittle, Mordenkainen's Disjunction, and
// Succor, its level seam-proven by the section
// heading; the "th Level" print stands).
inline int uas2Mu9thCount()
    { return 8; }

inline const char* uas2Mu9thName(int i) {
    const auto& rows = uaRows("ua_s2_mu9");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// R785: the 6th-level column - the archive.org
// full-text OCR reads the continued table, and the
// cells the R342 read had drifted into the 7th and
// 8th blocks re-seat here. The repaired roster (17
// names: the twelve readable cells, the three UA-new
// description-roster names - Chain Lightning,
// Ensnarement, Mordenkainen's Lucubration - and the
// two registry rows Death Spell and Disintegrate).
inline int uas2Mu6thCount()
    { return 17; }

inline const char* uas2Mu6thName(int i) {
    const auto& rows = uaRows("ua_s2_mu6");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 16) i = 16;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// R785: the sixth column reads (the loss flag flips).
inline bool uas2MuSixthLevelColumnLost()
    { return false; }
// The continued header's "th Level" prints the 9 lost.
inline bool uas2MuHighTableNineLost()
    { return true; }

// ---- the illusionist table (p. 31) ----
// The readable 1st-level column (5 names).
inline int uas2Il1stCount()
    { return 5; }

inline const char* uas2Il1stName(int i) {
    const auto& rows = uaRows("ua_s2_il1");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// The readable 2nd-level names (4; the "Hallucin: Terrain" and
// "Mirror" fragments seam-decode against the R229 registry).
inline int uas2Il2ndCount()
    { return 4; }

inline const char* uas2Il2ndName(int i) {
    const auto& rows = uaRows("ua_s2_il2");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// The readable 7th-level name (1; the 3rd-6th columns are lost).
inline int uas2Il7thCount()
    { return 1; }

inline const char* uas2Il7thName(int i) {
    const auto& rows = uaRows("ua_s2_il7");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// The illusionist minor-illusion cantrip
// column: the PDF read resolves the
// loss (R421) - the clean p. 31
// print gives the whole column, the
// eight names in roster order,
// matching the description roster
// (rules/ua/uailcantrips.h) row for row.
inline int uas2IlCantripCount()
    { return 8; }

inline const char* uas2IlCantripName(int i) {
    const auto& rows = uaRows("ua_s2_ilcantrip");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

}   // namespace rules
