// R-refactor: split from swords.h - definitions
#include "rules/dmg/swords.h"

int Swords::swRowCount() {
    // Sword +1 through the Cursed Berserking
    return 26;
}

int Swords::swRowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 25) i = 25;
    static const int t[26] = {
        1, 26, 31, 36, 41, 46, 50, 51, 59,
        63, 67, 68, 72, 75, 77, 78, 79, 80,
        81, 82, 83, 84, 85, 86, 91, 96,
    };
    return t[i];
}

int Swords::swRowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 25) i = 25;
    static const int t[26] = {
        25, 30, 35, 40, 45, 49, 50, 58, 62,
        66, 67, 71, 74, 76, 77, 78, 79, 80,
        81, 82, 83, 84, 85, 90, 95, 100,
    };
    return t[i];
}

int Swords::swXpValue(int i) {
    // the x.p. point values; i clamps
    if (i < 0) i = 0;
    if (i > 25) i = 25;
    static const int t[26] = {
        400, 600, 700, 800, 800, 900, 1000, 800, 900,
        900, 1600, 1400, 1600, 2000, 3000, 3000, 3600, 4000,
        4400, 4400, 5000, 7000, 10000, 400, 600, 900,
    };
    return t[i];
}

int Swords::swSaleGp(int i) {
    // the g.p. sale values; the cursed rows are 0; i clamps
    if (i < 0) i = 0;
    if (i > 25) i = 25;
    static const int t[26] = {
        2000, 3000, 3500, 4000, 4000, 4500, 5000, 4000, 4500,
        4500, 8000, 7000, 8000, 10000, 15000, 15000, 18000, 20000,
        22000, 22000, 25000, 35000, 50000, 0, 0, 0,
    };
    return t[i];
}

int Swords::swNoSaleCount() {
    // the three cursed swords print --- g.p.
    return 3;
}

int Swords::swLongswordPct() {
    // 70% of swords are longswords
    return 70;
}

int Swords::swBroadswordPct() {
    // 20% are broadswords
    return 20;
}

int Swords::swShortswordPct() {
    // 5% are short (small) swords
    return 5;
}

int Swords::swBastardPct() {
    // 4% are bastard swords
    return 4;
}

int Swords::swTwoHandedPct() {
    // 1% are two-handed swords
    return 1;
}

int Swords::swFlameVsRegenBonus() {
    // Flame Tongue: +2 vs. regenerating creatures
    return 2;
}

int Swords::swFlameVsColdAvianBonus() {
    // Flame Tongue: +3 vs. cold-using, inflammable or avian
    return 3;
}

int Swords::swFlameVsUndeadBonus() {
    // Flame Tongue: +4 vs. undead
    return 4;
}

int Swords::swFrostVsFireBonus() {
    // Frost Brand: +6 vs. fire using/dwelling creatures
    return 6;
}
