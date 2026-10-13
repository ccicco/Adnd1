// ===========================================================================
// Adnd1 - rules/uasstatlines.h
// The UA APPENDIX S STAT LINES
// (pp. 110-120), R409: the
// S/I/W/D/C/CH/CM row for each of
// the 23 deity stat blocks the R406
// round pinned. The clean djvu scan
// carries all 23 lines; the
// systematic OCR reads resolve:
// the capital I renders "1:", the
// label dots ("S.", "C.", "CM.")
// read colons, the asterisk and the
// diamond read plus, the dot reads
// comma. Every resolved read carries
// an independent confirmation -
// the same-score agreement (the
// four S:19 rows, the three S:25
// rows, the pairs at 22/21/20, the
// 18/00 pair), the R153 percentile
// bands (18/00 reads +3/+6, 18/01
// reads +1/+3), or the block own
// DAMAGE/ATTACK print.
//
// The hole: the Cyrrollalee plus
// pair prints "( + 1. + 1)" - the
// dot sits inside the value pair
// and the block damage line prints
// "By weapon type" (no
// parenthetical), so no
// independent confirmation exists.
// The pair records as the hole
// sentinel, never a guess.
//
// The divergence: the Bahgtru
// DAMAGE/ATTACK line prints
// 10-60 (+15) against the stat
// line S:25 (+ 7, + 14). Both
// prints are scan-clean; the print
// diverges. The stat line pins and
// the mirror registry records the
// damage line 15 with the
// divergence flag.
//
// The paren codes: 0 = the print
// carries no parenthetical; -2 =
// the Hanali CH:25 "(special)". The
// plus codes: 0 = the plain scores
// carry no parenthetical plusses
// (S:8, S:12, S:15); -1 = the
// Cyrrollalee hole. The percent
// code: 0 = none; 1 and 100 print
// 18/01 and 18/00.

#pragma once

namespace rules {

// The plus codes.
const int UASL_PLUS_NONE = 0;
const int UASL_PLUS_HOLE = -1;

// The paren codes.
const int UASL_PAREN_NONE = 0;
const int UASL_PAREN_SPECIAL = -2;

// One stat line, as printed:
// the seven scores, the
// exceptional percentile, the S
// parenthetical plusses, and the
// CH/CM parenthetical forms.
struct UaslStatLine {
    const char* name;
    int str;
    int pct;   // 0 none, 1 = 18/01, 100 = 18/00
    int hit;   // 0 unprinted, -1 hole
    int dmg;   // 0 unprinted, -1 hole
    int intl;
    int wis;
    int dex;
    int con;
    int cha;
    int chaParen;   // 0 none, -2 special
    int cm;
    int cmParen;
};

// The 23 stat lines, in the R406
// roster order.
inline const UaslStatLine& uaslLine(int i) {
    static const UaslStatLine T[23] = {
        { "CLANGGEDIN SILVERBEARD",
          25, 0, 7, 14, 20, 19, 20, 25, 16, 22, 13, 20 },
        { "VERGADAIN",
          22, 0, 4, 10, 23, 20, 23, 25, 18, 24, 18, 24 },
        { "DUMATHOIN",
          25, 0, 7, 14, 23, 25, 20, 25, 18, 24, 13, 16 },
        { "ABBATHOR",
          24, 0, 6, 12, 22, 16, 24, 24, 8, 14, 7, 13 },
        { "BERRONAR",
          21, 0, 4, 9, 25, 25, 20, 25, 19, 25, 20, 25 },
        { "AERDRIE FAENYA",
          8, 0, 0, 0, 24, 22, 24, 19, 23, 0, 25, 0 },
        { "EREVAN ILESERE",
          19, 0, 3, 7, 23, 16, 25, 20, 24, 0, 25, 0 },
        { "SOLONOR THELANDIRA",
          21, 0, 4, 9, 22, 21, 25, 21, 23, 0, 22, 0 },
        { "HANALI CELANIL",
          15, 0, 0, 0, 23, 23, 25, 20, 25, -2, 30, 0 },
        { "LABELAS ENORETH",
          12, 0, 0, 0, 25, 25, 19, 18, 24, 0, 25, 0 },
        { "SHEELA PERYROYL",
          18, 100, 3, 6, 22, 25, 22, 24, 22, 0, 24, 0 },
        { "ARVOREEN",
          20, 0, 3, 8, 21, 23, 24, 23, 21, 0, 21, 0 },
        { "CYRROLLALEE",
          17, 0, -1, -1, 23, 24, 24, 23, 22, 0, 21, 0 },
        { "BRANDOBARIS",
          19, 0, 3, 7, 24, 17, 25, 23, 20, 0, 19, 0 },
        { "BAERVAN WILDWANDERER",
          18, 100, 3, 6, 21, 19, 25, 22, 22, 0, 16, 0 },
        { "URDLEN",
          19, 0, 3, 7, 20, 14, 20, 24, 3, 0, -14, 0 },
        { "SEGOJAN EARTHCALLER",
          18, 1, 1, 3, 22, 23, 18, 24, 20, 0, 15, 0 },
        { "FLANDAL STEELSKIN",
          22, 0, 4, 10, 18, 20, 17, 23, 18, 0, 16, 0 },
        { "BAHGTRU",
          25, 0, 7, 14, 6, 6, 18, 25, 5, 22, -2, 16 },
        { "SHARGAAS",
          20, 0, 3, 8, 19, 15, 24, 19, 7, 24, 8, 20 },
        { "ILNEVAL",
          23, 0, 5, 11, 17, 14, 20, 23, 8, 25, 5, 24 },
        { "YURTRUS",
          18, 0, 1, 2, 18, 11, 10, 17, -4, 0, -25, 0 },
        { "LUTHIC",
          19, 0, 3, 7, 18, 19, 14, 20, 12, 25, 3, 24 },
    };
    if (i < 0) i = 0;
    if (i > 22) i = 22;
    return T[i];
}

inline int uaslLineCount()
    { return 23; }

// The DAMAGE/ATTACK line
// parenthetical per block, as
// printed (0 = the line prints no
// parenthetical). The Bahgtru 15
// is the recorded divergence
// against the stat line 14.
inline int uaslDmgLineMirror(int i) {
    static const int k[23] = {
        14, 10, 14, 12, 9, 0, 7, 0, 0, 0, 6, 8,
        0, 7, 6, 7, 3, 10, 15, 8, 11, 0, 7,
    };
    if (i < 0) i = 0;
    if (i > 22) i = 22;
    return k[i];
}

// The Bahgtru print divergence:
// the damage line 15 against the
// stat line 14 - recorded, not
// reconciled.
inline bool uaslBahgtruDmgDiverges()
    { return true; }

}   // namespace rules

