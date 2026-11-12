// R-refactor: split from hoard.h - definitions
#include "rules/dmg/hoard.h"

int Hoard::bandCount() {
    // 01-20 through 97-00: ten bands
    return 10;
}

int Hoard::bandOfRoll(int roll) {
    // 01-20 b0, 21-40 b1, 41-55 b2, 56-65 b3,
    // 66-75 b4, 76-80 b5, 81-85 b6, 86-90 b7,
    // 91-96 b8, 97-00 b9
    if (roll < 1) roll = 1;
    if (roll > 100) roll = 100;
    if (roll <= 20) return 0;
    if (roll <= 40) return 1;
    if (roll <= 55) return 2;
    if (roll <= 65) return 3;
    if (roll <= 75) return 4;
    if (roll <= 80) return 5;
    if (roll <= 85) return 6;
    if (roll <= 90) return 7;
    if (roll <= 96) return 8;
    return 9;
}

int Hoard::monetaryRowCount(int band) {
    // b0: 1-2; b1: 6-10; b2: 3-5 and 6-10;
    // b3: 1-2, 3-5 and 6-10; b4: 6-10 and
    // 11-12; b5: 3-5, 6-10, 11-12 and 16-17;
    // b6/b7: the 20 row; b8/b9: none on hand
    if (band < 0) band = 0;
    if (band > 9) band = 9;
    static const int t[10] = {
        1, 1, 2, 3, 2, 4, 1, 1, 0, 0,
    };
    return t[band];
}

int Hoard::monetaryRow(int band, int i) {
    // the R219 monetary band indices, in the
    // printed order; i clamps to the count
    if (band < 0) band = 0;
    if (band > 9) band = 9;
    static const int t[10][4] = {
        { 0, 0, 0, 0 },
        { 2, 2, 2, 2 },
        { 1, 2, 2, 2 },
        { 0, 1, 2, 2 },
        { 2, 3, 3, 3 },
        { 1, 2, 3, 5 },
        { 8, 8, 8, 8 },
        { 8, 8, 8, 8 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
    };
    int n = monetaryRowCount(band);
    if (i < 0) i = 0;
    if (i > n - 1) i = n - 1;
    if (i < 0) i = 0;
    return t[band][i];
}

int Hoard::magicRowCount(int band) {
    // b0: 1-5; b1: 1-5; b2: 1-5 and 15-18;
    // b3: 9-12 and 13-14; b4: 6-8 and 15-18;
    // b5: 1-5 and 9-12; b6/b7: none (the
    // magic is at the map); b8: 20; b9:
    // 15-18 and 20
    if (band < 0) band = 0;
    if (band > 9) band = 9;
    static const int t[10] = {
        1, 1, 2, 2, 2, 2, 0, 0, 1, 2,
    };
    return t[band];
}

int Hoard::magicRow(int band, int i) {
    // the R219 magic band indices, in the
    // printed order; i clamps to the count
    if (band < 0) band = 0;
    if (band > 9) band = 9;
    static const int t[10][2] = {
        { 0, 0 },
        { 0, 0 },
        { 0, 4 },
        { 2, 3 },
        { 1, 4 },
        { 0, 2 },
        { 0, 0 },
        { 0, 0 },
        { 6, 6 },
        { 4, 6 },
    };
    int n = magicRowCount(band);
    if (i < 0) i = 0;
    if (i > n - 1) i = n - 1;
    if (i < 0) i = 0;
    return t[band][i];
}

int Hoard::mapsToMonetary(int band) {
    // bands 91-96 and 97-00 map to the
    // monetary treasure
    if (band < 0) band = 0;
    if (band > 9) band = 9;
    if (band == 8) return 1;
    if (band == 9) return 1;
    return 0;
}

int Hoard::mapMonetaryRowCount(int band) {
    // b8 maps to 1-2 and 3-5; b9 maps to
    // 11-12 and 13-15
    if (band < 0) band = 0;
    if (band > 9) band = 9;
    if (band == 8) return 2;
    if (band == 9) return 2;
    return 0;
}

int Hoard::mapMonetaryRow(int band, int i) {
    // b8: rows 0 and 1; b9: rows 3 and 4
    if (band < 0) band = 0;
    if (band > 9) band = 9;
    static const int t[10][2] = {
        { 0, 0 },
        { 0, 0 },
        { 0, 0 },
        { 0, 0 },
        { 0, 0 },
        { 0, 0 },
        { 0, 0 },
        { 0, 0 },
        { 0, 1 },
        { 3, 4 },
    };
    int n = mapMonetaryRowCount(band);
    if (i < 0) i = 0;
    if (i > n - 1) i = n - 1;
    if (i < 0) i = 0;
    return t[band][i];
}

int Hoard::mapsToMagic(int band) {
    // bands 81-85 and 86-90 map to the magic
    // treasure
    if (band < 0) band = 0;
    if (band > 9) band = 9;
    if (band == 6) return 1;
    if (band == 7) return 1;
    return 0;
}

int Hoard::mapMagicRowCount(int band) {
    // b6 maps to 1-5 magic; b7 maps to 19
    if (band < 0) band = 0;
    if (band > 9) band = 9;
    if (band == 6) return 1;
    if (band == 7) return 1;
    return 0;
}

int Hoard::mapMagicRow(int band, int i) {
    // b6: row 0 (die 1-5); b7: row 7 (die 19)
    if (band < 0) band = 0;
    if (band > 9) band = 9;
    static const int t[10][2] = {
        { 0, 0 },
        { 0, 0 },
        { 0, 0 },
        { 0, 0 },
        { 0, 0 },
        { 0, 0 },
        { 0, 0 },
        { 7, 7 },
        { 0, 0 },
        { 0, 0 },
    };
    int n = mapMagicRowCount(band);
    if (i < 0) i = 0;
    if (i > n - 1) i = n - 1;
    if (i < 0) i = 0;
    return t[band][i];
}

int Hoard::mustBeHiddenTrappedGuarded() {
    // combined hoards should be hidden,
    // trapped and guarded
    return 1;
}

int Hoard::distantPlaces() {
    // they should be located in distant
    // places too
    return 1;
}
