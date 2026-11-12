// R-refactor: split from scrollpins.h - definitions
#include "rules/dmg/scrollpins.h"

int Scrollpins::scrollSpellRowCount() {
    return 16;
}

int Scrollpins::scrollSpellRowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 15) i = 15;
    static const int t[16] = {
        1, 11, 17, 20, 25, 28, 33, 36, 40, 43,
        47, 50, 53, 55, 58, 60,
    };
    return t[i];
}

int Scrollpins::scrollSpellRowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 15) i = 15;
    static const int t[16] = {
        10, 16, 19, 24, 27, 32, 35, 39, 42, 46,
        49, 52, 54, 57, 59, 60,
    };
    return t[i];
}

int Scrollpins::scrollSpellRowN(int i) {
    // the spells on the scroll; i clamps
    if (i < 0) i = 0;
    if (i > 15) i = 15;
    static const int t[16] = {
        1, 1, 1, 2, 2, 3, 3, 4, 4, 5,
        5, 6, 6, 7, 7, 7,
    };
    return t[i];
}

int Scrollpins::scrollSpellRowLvLo(int i) {
    // the main level range lower edge; i clamps
    if (i < 0) i = 0;
    if (i > 15) i = 15;
    static const int t[16] = {
        1, 1, 2, 1, 1, 1, 2, 1, 1, 1,
        1, 1, 3, 1, 2, 4,
    };
    return t[i];
}

int Scrollpins::scrollSpellRowLvHi(int i) {
    // the main level range upper edge; i clamps
    if (i < 0) i = 0;
    if (i > 15) i = 15;
    static const int t[16] = {
        4, 6, 9, 4, 8, 4, 9, 6, 8, 6,
        8, 6, 8, 8, 9, 9,
    };
    return t[i];
}

int Scrollpins::scrollSpellRowHasAlt(int i) {
    // 1 when the print gives an
    // illusionist alternative range
    // (the or X-Y* halves); i clamps
    if (i < 0) i = 0;
    if (i > 15) i = 15;
    static const int t[16] = {
        0, 0, 1, 0, 1, 0, 1, 0, 1, 0,
        1, 0, 1, 0, 0, 1,
    };
    return t[i];
}

int Scrollpins::scrollSpellRowAltLvLo(int i) {
    // the alt range lower edge (equals
    // the main lo on every alt row);
    // i clamps
    if (i < 0) i = 0;
    if (i > 15) i = 15;
    static const int t[16] = {
        0, 0, 2, 0, 1, 0, 2, 0, 1, 0,
        1, 0, 3, 0, 0, 4,
    };
    return t[i];
}

int Scrollpins::scrollSpellRowAltLvHi(int i) {
    // the alt range upper edge (lower
    // than the main hi on every alt
    // row); i clamps
    if (i < 0) i = 0;
    if (i > 15) i = 15;
    static const int t[16] = {
        0, 0, 7, 0, 6, 0, 7, 0, 6, 0,
        6, 0, 6, 0, 0, 7,
    };
    return t[i];
}

int Scrollpins::scrollSpellAltRangeCount() {
    // the 17-19, 25-27, 33-35, 40-42,
    // 47-49, 53-54 and 60 bands
    return 7;
}

int Scrollpins::scrollProtRowCount() {
    // the protection scrolls (61-97)
    return 8;
}

int Scrollpins::scrollProtRowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    static const int t[8] = {
        61, 63, 65, 71, 77, 83, 88, 93,
    };
    return t[i];
}

int Scrollpins::scrollProtRowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    static const int t[8] = {
        62, 64, 70, 76, 82, 87, 92, 97,
    };
    return t[i];
}

int Scrollpins::scrollProtRowXp(int i) {
    // the table-printed x.p. values;
    // i clamps
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    static const int t[8] = {
        2500, 2500, 1500, 1000, 1500, 2000, 2000, 1500,
    };
    return t[i];
}

int Scrollpins::scrollCurseRowCount() {
    return 8;
}

int Scrollpins::scrollCurseRowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    static const int t[8] = {
        1, 26, 31, 41, 51, 76, 91, 100,
    };
    return t[i];
}

int Scrollpins::scrollCurseRowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    static const int t[8] = {
        25, 30, 40, 50, 75, 90, 99, 100,
    };
    return t[i];
}

int Scrollpins::scrollSpellXpPerLevel() {
    // awarded only to characters who can
    // use the spell(s)
    return 100;
}

int Scrollpins::scrollSpellSaleMultiplier() {
    // the open market pays three times
    // the x.p. value
    return 3;
}

int Scrollpins::scrollProtectionSaleMultiplier() {
    // protection scrolls sell at five
    // times the x.p. value
    return 5;
}

int Scrollpins::scrollDmMustConvinceRead() {
    // duplicity, coercion and threat:
    // the DM must do his utmost to
    // convince players a cursed scroll
    // should be read
    return 1;
}

int Scrollpins::scrollUnreadMayFade() {
    // a scroll not read has a chance of
    // fading in normal air; the archaic
    // wording notes it if read in the
    // still dungeon atmosphere
    return 1;
}

int Scrollpins::scrollCurseTakesEffectImmediately() {
    return 1;
}

int Scrollpins::scrollCurseDiseaseOnsetMin() {
    // fatal to the reader in 2-8 turns
    // unless cured
    return 2;
}

int Scrollpins::scrollCurseDiseaseOnsetMax() {
    return 8;
}

int Scrollpins::scrollCurseTransportMinMiles() {
    // rows 31-40: 200 to 1,200 miles in
    // a random direction
    return 200;
}

int Scrollpins::scrollCurseTransportMaxMiles() {
    return 1200;
}

int Scrollpins::scrollCurseTransportRadius() {
    // rows 31-50 move the reader AND all
    // within 20 feet
    return 20;
}

int Scrollpins::scrollCurseRandomSpellLevel() {
    // row 00: a randomly rolled spell
    // affects the reader at the 12th
    // level of magic-use
    return 12;
}
