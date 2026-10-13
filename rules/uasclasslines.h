// ===========================================================================
// Adnd1 - rules/uasclasslines.h
// The UA APPENDIX S CLASS/LINES
// (pp. 110-120), R410: the six
// printed lines per deity block -
// CLERIC/DRUID, FIGHTER,
// MAGIC-USER/ILLUSIONIST,
// THIEF/ASSASSIN, MONK/BARD and
// PSIONIC ABILITY. The clean djvu
// scan carries all 23 blocks; the
// systematic OCR reads resolve
// (the dropped slash in the Berronar
// label, the "IOth"/"1 Oth"
// letter-O reads, the "tighter"
// fighter read, the label colon dot)
// with the level-ladder sanity -
// every printed level sits at 20 or
// below.
//
// The PSIONIC ABILITY line pins
// here as printed and cross-checks
// the R406 rating codes LIVE: the
// psn kind codes ARE the R406
// rating codes (0 VI, 1 III, 2 IV,
// 3 Nil) and the Brandobaris block
// prints NO line - kind -1, the
// recorded R406 unrecorded
// sentinel.
//
// The kind codes: 0 Nil, 1 single
// (a = the level), 2 dual (a, b),
// 3 each (a), 4 special (a = the
// second read level, 0 when the
// second reads Nil), 5 monster (a
// = the hit dice), 6 see below.

#pragma once

namespace rules {

// The class-line kind codes.
const int UASCL_NIL = 0;
const int UASCL_SINGLE = 1;
const int UASCL_DUAL = 2;
const int UASCL_EACH = 3;
const int UASCL_SPECIAL = 4;
const int UASCL_MONSTER = 5;
const int UASCL_SEEBELOW = 6;

// The psionic kind codes - the
// R406 rating codes by design.
const int UASCL_PSN_VI = 0;
const int UASCL_PSN_III = 1;
const int UASCL_PSN_IV = 2;
const int UASCL_PSN_NILRC = 3;
const int UASCL_PSN_MISSING = -1;

// One class/level line: the kind,
// the numeric reads and the printed
// read string (resolved OCR).
struct UasClassLine {
    int kind;
    int a;
    int b;
    const char* read;
};

// The six lines of one block.
struct UasClassLines {
    UasClassLine cd, f, mu, ta, mb;
    UasClassLine psn;
};

// The 23 blocks, in the R406
// roster order.
inline const UasClassLines& uasclLines(int i) {
    static const UasClassLines T[23] = {
        {  // 0
        { 1, 12, 0, "12th level druid" },
        { 1, 17, 0, "17th level ranger" },
        { 1, 10, 0, "10th level magic-user" },
        { 0, 0, 0, "Nil" },
        { 1, 6, 0, "6th level bard" },
        { 0, 0, 0, "VI" },
        },
        {  // 1
        { 1, 12, 0, "12th level druid" },
        { 1, 12, 0, "12th level ranger" },
        { 0, 0, 0, "Nil" },
        { 1, 18, 0, "18th level thief" },
        { 1, 15, 0, "15th level bard" },
        { 1, 0, 0, "III" },
        },
        {  // 2
        { 2, 15, 14, "15th level cleric/14th level druid" },
        { 1, 16, 0, "16th level fighter" },
        { 4, 14, 0, "Special/14th level illusionist" },
        { 1, 12, 0, "12th level thief" },
        { 0, 0, 0, "Nil" },
        { 0, 0, 0, "VI" },
        },
        {  // 3
        { 0, 0, 0, "Nil" },
        { 1, 14, 0, "14th level fighter" },
        { 1, 11, 0, "11th level illusionist" },
        { 2, 20, 15, "20th level thief/15th level assassin" },
        { 0, 0, 0, "Nil" },
        { 1, 0, 0, "III" },
        },
        {  // 4
        { 2, 15, 12, "15th level cleric/12th level druid" },
        { 1, 14, 0, "14th level paladin" },
        { 1, 16, 0, "16th level magic-user" },
        { 0, 0, 0, "Nil" },
        { 0, 0, 0, "Nil" },
        { 1, 0, 0, "III" },
        },
        {  // 5
        { 1, 14, 0, "14th level druid" },
        { 1, 10, 0, "10th level fighter" },
        { 4, 0, 0, "Special/Nil" },
        { 0, 0, 0, "Nil" },
        { 1, 10, 0, "10th level bard" },
        { 0, 0, 0, "VI" },
        },
        {  // 6
        { 1, 8, 0, "8th level druid" },
        { 1, 7, 0, "7th level ranger" },
        { 1, 18, 0, "18th level illusionist" },
        { 1, 20, 0, "20th level thief" },
        { 1, 10, 0, "10th level bard" },
        { 1, 0, 0, "III" },
        },
        {  // 7
        { 1, 12, 0, "12th level druid" },
        { 1, 17, 0, "17th level ranger" },
        { 1, 10, 0, "10th level magic-user" },
        { 1, 12, 0, "12th level thief" },
        { 1, 8, 0, "8th level bard" },
        { 0, 0, 0, "VI" },
        },
        {  // 8
        { 2, 14, 10, "14th level cleric/10th level druid" },
        { 0, 0, 0, "Nil" },
        { 2, 16, 15, "16th level m-u/15th level illusionist" },
        { 0, 0, 0, "Nil" },
        { 1, 12, 0, "12th level bard" },
        { 0, 0, 0, "VI" },
        },
        {  // 9
        { 2, 14, 12, "14th level cleric/12th level druid" },
        { 0, 0, 0, "Nil" },
        { 2, 18, 16, "18th level m-u/16th level illusionist" },
        { 0, 0, 0, "Nil" },
        { 1, 12, 0, "12th level bard" },
        { 0, 0, 0, "VI" },
        },
        {  // 10
        { 1, 14, 0, "14th level druid" },
        { 1, 7, 0, "7th level ranger" },
        { 1, 14, 0, "14th level magic-user" },
        { 0, 0, 0, "Nil" },
        { 1, 10, 0, "10th level bard" },
        { 3, 0, 0, "Nil" },
        },
        {  // 11
        { 1, 8, 0, "8th level cleric" },
        { 1, 12, 0, "12th level ranger" },
        { 0, 0, 0, "Nil" },
        { 1, 10, 0, "10th level thief" },
        { 1, 8, 0, "8th level monk" },
        { 3, 0, 0, "Nil" },
        },
        {  // 12
        { 1, 10, 0, "10th level cleric" },
        { 1, 10, 0, "10th level paladin" },
        { 3, 8, 0, "8th level in each" },
        { 0, 0, 0, "Nil" },
        { 0, 0, 0, "Nil" },
        { 3, 0, 0, "Nil" },
        },
        {  // 13
        { 1, 6, 0, "6th level druid" },
        { 1, 7, 0, "7th level ranger" },
        { 3, 6, 0, "6th level in each" },
        { 1, 19, 0, "19th level thief" },
        { 1, 6, 0, "6th level monk" },
        { -1, 0, 0, "none" },
        },
        {  // 14
        { 1, 12, 0, "12th level druid" },
        { 1, 8, 0, "8th level ranger" },
        { 1, 13, 0, "13th level illusionist" },
        { 1, 20, 0, "20th level thief" },
        { 0, 0, 0, "Nil" },
        { 1, 0, 0, "III" },
        },
        {  // 15
        { 1, 8, 0, "8th level cleric" },
        { 1, 10, 0, "10th level fighter" },
        { 1, 13, 0, "13th level illusionist" },
        { 1, 12, 0, "12th level assassin" },
        { 0, 0, 0, "Nil" },
        { 0, 0, 0, "VI" },
        },
        {  // 16
        { 1, 14, 0, "14th level druid" },
        { 1, 6, 0, "6th level fighter" },
        { 3, 16, 0, "16th level in each" },
        { 0, 0, 0, "Nil" },
        { 1, 4, 0, "4th level bard" },
        { 0, 0, 0, "VI" },
        },
        {  // 17
        { 3, 8, 0, "8th level in each" },
        { 1, 10, 0, "10th level fighter" },
        { 1, 15, 0, "15th level magic-user" },
        { 0, 0, 0, "Nil" },
        { 0, 0, 0, "Nil" },
        { 0, 0, 0, "VI" },
        },
        {  // 18
        { 0, 0, 0, "Nil" },
        { 5, 16, 0, "As 16-HD monster" },
        { 0, 0, 0, "Nil" },
        { 1, 6, 0, "6th level assassin" },
        { 0, 0, 0, "Nil" },
        { 3, 0, 0, "Nil" },
        },
        {  // 19
        { 0, 0, 0, "Nil" },
        { 5, 10, 0, "As 10 HD monster" },
        { 1, 7, 0, "7th level illusionist" },
        { 2, 16, 15, "16th level thief/15th level assassin" },
        { 1, 10, 0, "10th level monk" },
        { 2, 0, 0, "IV" },
        },
        {  // 20
        { 1, 8, 0, "8th level cleric" },
        { 5, 15, 0, "As 15 HD monster" },
        { 0, 0, 0, "Nil" },
        { 1, 14, 0, "14th level assassin" },
        { 0, 0, 0, "Nil" },
        { 3, 0, 0, "Nil" },
        },
        {  // 21
        { 1, 15, 0, "15th level cleric (destructive spells only)" },
        { 5, 13, 0, "As 13 HD monster" },
        { 6, 0, 0, "See below/Nil" },
        { 1, 15, 0, "15th level assassin" },
        { 0, 0, 0, "Nil" },
        { 0, 0, 0, "VI" },
        },
        {  // 22
        { 1, 15, 0, "15th level cleric" },
        { 5, 12, 0, "As 12 HD monster" },
        { 3, 12, 0, "12th level in each" },
        { 3, 6, 0, "6th level in each" },
        { 0, 0, 0, "Nil" },
        { 3, 0, 0, "Nil" },
        },
    };
    if (i < 0) i = 0;
    if (i > 22) i = 22;
    return T[i];
}

inline int uasclBlockCount()
    { return 23; }

// The Nil census across the five
// class lines (the psionic line
// excluded): 29.
inline int uasclNilCount() {
    int n = 0;
    for (int i = 0; i < 23; ++i) {
        const UasClassLines& b =
            uasclLines(i);
        if (b.cd.kind == UASCL_NIL) ++n;
        if (b.f.kind == UASCL_NIL) ++n;
        if (b.mu.kind == UASCL_NIL) ++n;
        if (b.ta.kind == UASCL_NIL) ++n;
        if (b.mb.kind == UASCL_NIL) ++n;
    }
    return n;
}

// The psionic census (the R406
// rating census re-derived from
// the printed lines): VI 10,
// III 5, IV 1, Nil 6, missing 1.
inline int uasclPsnCount(int code) {
    int n = 0;
    for (int i = 0; i < 23; ++i)
        if (uasclLines(i).psn.kind == code) ++n;
    return n;
}

}   // namespace rules

