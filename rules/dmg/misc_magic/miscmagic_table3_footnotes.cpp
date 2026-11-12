// R-refactor: split from miscmagic_table3_footnotes.h - definitions
#include "rules/dmg/misc_magic/miscmagic_table3_footnotes.h"

int Miscmagic_table3_footnotes::m3RowCount() {
    // Figurine through the 93-00 Ointment
    return 33;
}

int Miscmagic_table3_footnotes::m3RowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    static const int t[33] = {
        1, 16, 17, 19, 21, 23, 26, 27, 28, 29,
        30, 31, 36, 38, 40, 41, 46, 47, 49, 50,
        54, 61, 64, 66, 71, 72, 73, 79, 81, 86,
        91, 92, 93,
    };
    return t[i];
}

int Miscmagic_table3_footnotes::m3RowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    static const int t[33] = {
        15, 16, 18, 20, 22, 25, 26, 27, 28, 29,
        30, 35, 37, 39, 40, 45, 46, 48, 49, 53,
        60, 63, 65, 70, 71, 72, 78, 80, 85, 90,
        91, 92, 100,
    };
    return t[i];
}

int Miscmagic_table3_footnotes::m3UsableByCleric(int i) {
    // the (C) mark; i clamps
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    static const int t[33] = {
        0, 0, 0, 0, 1, 1, 0, 0, 1, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 1, 1, 0, 0, 0, 0, 0,
        0, 0, 0,
    };
    return t[i];
}

int Miscmagic_table3_footnotes::m3UsableByFighter(int i) {
    // the (F) mark; i clamps
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    static const int t[33] = {
        0, 0, 0, 0, 1, 1, 0, 0, 1, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
        0, 0, 0,
    };
    return t[i];
}

int Miscmagic_table3_footnotes::m3UsableByThief(int i) {
    // the (T) mark; i clamps
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    static const int t[33] = {
        0, 0, 0, 0, 1, 1, 0, 0, 1, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0,
    };
    return t[i];
}

int Miscmagic_table3_footnotes::m3StarCount(int i) {
    // the asterisk ladder: 1 the Figurine
    // (per hit die), 2 the Horn of Valhalla
    // (bronze/iron), 3 the Ioun Stones (per
    // stone), 4 the Instrument of the Bards
    // (per level of instrument); i clamps
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    static const int t[33] = {
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        2, 0, 0, 0, 0, 3, 4, 0, 0, 0,
        0, 0, 0,
    };
    return t[i];
}

int Miscmagic_table3_footnotes::m3IsPerFacetValued(int i) {
    // the Jewel of Flawlessness (92): 1,000
    // g.p. per facet; i clamps
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    static const int t[33] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0,
    };
    return t[i];
}

int Miscmagic_table3_footnotes::m3ClericCount() {
    return 7;
}

int Miscmagic_table3_footnotes::m3FighterCount() {
    return 7;
}

int Miscmagic_table3_footnotes::m3ThiefCount() {
    return 4;
}

int Miscmagic_table3_footnotes::m3FigurinePerHitDieXp() {
    // per hit die of the figurine
    return 100;
}

int Miscmagic_table3_footnotes::m3FigurinePerHitDieGp() {
    return 1000;
}

int Miscmagic_table3_footnotes::m3ValhallaBaseXp() {
    return 1000;
}

int Miscmagic_table3_footnotes::m3ValhallaBaseGp() {
    return 15000;
}

int Miscmagic_table3_footnotes::m3ValhallaBronzeMult() {
    // double for a bronze horn
    return 2;
}

int Miscmagic_table3_footnotes::m3ValhallaIronMult() {
    // triple for an iron horn
    return 3;
}

int Miscmagic_table3_footnotes::m3IounPerStoneXp() {
    // per stone
    return 300;
}

int Miscmagic_table3_footnotes::m3IounPerStoneGp() {
    return 5000;
}

int Miscmagic_table3_footnotes::m3InstrumentBaseXp() {
    // per level of instrument for bards
    return 1000;
}

int Miscmagic_table3_footnotes::m3InstrumentBaseGp() {
    return 5000;
}

int Miscmagic_table3_footnotes::m3JewelPerFacetGp() {
    // no x.p., 1,000 g.p. per facet
    return 1000;
}
