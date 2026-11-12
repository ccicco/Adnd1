// R-refactor: split from npctraits.h - definitions
#include "rules/dmg/npctraits.h"


int Npctraits::npcTendencyCount() { return 24; }

int Npctraits::npcTraitTendency(int d6, int d12) {
    // the d6 half: 1-3 the first twelve,
    // 4-6 the second; the d12 picks the row
    if (d6 < 1) d6 = 1;
    if (d6 > 6) d6 = 6;
    if (d12 < 1) d12 = 1;
    if (d12 > 12) d12 = 12;
    int half = d6 <= 3 ? 0 : 1;
    return half * 12 + d12 - 1;
}

int Npctraits::npcTraitPersonalityType(int d8) {
    // 1-5 average, 6-7 extroverted, 8
    // introverted
    if (d8 < 1) d8 = 1;
    if (d8 > 8) d8 = 8;
    if (d8 <= 5) return NPPTY_AVERAGE;
    if (d8 <= 7) return NPPTY_EXTROVERTED;
    return NPPTY_INTROVERTED;
}

int Npctraits::npcTraitPersonality(int d8first, int d8second) {
    // the word code: the column base plus
    // the row (the friendly, aloof, hostile,
    // rude and diplomatic words appear in
    // more than one column, so the codes are
    // per-column - the R209 raw-int
    // convention, one code per cell)
    if (d8first < 1) d8first = 1;
    if (d8first > 8) d8first = 8;
    if (d8second < 1) d8second = 1;
    if (d8second > 8) d8second = 8;
    static const int t[24] = {
        0, 1, 2, 3, 4, 5, 6, 7,
        8, 9, 10, 11, 12, 13, 14, 15,
        16, 17, 18, 19, 20, 21, 22, 23,
    };
    int col = d8first <= 5 ? 0 :
        (d8first <= 7 ? 1 : 2);
    return t[col * 8 + d8second - 1];
}

int Npctraits::npcInterestCount() { return 24; }

int Npctraits::npcTraitInterest(int d6, int d12) {
    // the same d6-half shape as the
    // tendencies
    if (d6 < 1) d6 = 1;
    if (d6 > 6) d6 = 6;
    if (d12 < 1) d12 = 1;
    if (d12 > 12) d12 = 12;
    int half = d6 <= 3 ? 0 : 1;
    return half * 12 + d12 - 1;
}

bool Npctraits::npcInterestIsCollector(int i) {
    // rows 17-20: the four collector faces
    return i >= NPI_COLLECTOR_1 && i <= NPI_COLLECTOR_4;
}

int Npctraits::npcTraitDisposition(int d10) {
    Npcpersonae npcpersonae;
    return npcpersonae.npcD10Face(d10) - 1;
}

int Npctraits::npcTraitIntellect(int d10) {
    Npcpersonae npcpersonae;
    return npcpersonae.npcD10Face(d10) - 1;
}

bool Npctraits::npcIntellectModifiesRating(int iq) {
    // dreaming, ponderous, anti-intellectual,
    // scheming and brilliant - the four-out-
    // of-eight-cases note reads dreaming
    // through brilliant
    return iq >= NPIQ_DREAMING;
}

int Npctraits::npcTraitCollection(int d12) {
    if (d12 < 1) d12 = 1;
    if (d12 > 12) d12 = 12;
    return d12 - 1;
}

int Npctraits::npcTraitNature(int d6) {
    if (d6 < 1) d6 = 1;
    if (d6 > 6) d6 = 6;
    return d6 - 1;
}

int Npctraits::npcTraitMaterialism(int d6) {
    if (d6 < 1) d6 = 1;
    if (d6 > 6) d6 = 6;
    return d6 - 1;
}

int Npctraits::npcTraitHonesty(int d8) {
    if (d8 < 1) d8 = 1;
    if (d8 > 8) d8 = 8;
    return d8 - 1;
}

int Npctraits::npcTraitBravery(int d8) {
    if (d8 < 1) d8 = 1;
    if (d8 > 8) d8 = 8;
    return d8 - 1;
}

int Npctraits::npcTraitEnergy(int d8) {
    if (d8 < 1) d8 = 1;
    if (d8 > 8) d8 = 8;
    return d8 - 1;
}

int Npctraits::npcTraitThrift(int d8) {
    if (d8 < 1) d8 = 1;
    if (d8 > 8) d8 = 8;
    return d8 - 1;
}

int Npctraits::npcTraitMorals(int d12) {
    if (d12 < 1) d12 = 1;
    if (d12 > 12) d12 = 12;
    return d12 - 1;
}

bool Npctraits::npcMoralsIsMarked(int m) {
    // perverted, sadistic and depraved - the
    // asterisk rows
    return m >= NPMOR_PERVERTED;
}

int Npctraits::npcMoralsResolved(int firstRoll, int secondRoll) {
    // the asterisk rule: roll again; if
    // perverted, sadistic or depraved is
    // again indicated, the character is that;
    // otherwise the second roll tells the
    // true morals and the first is ignored -
    // the same shape as the R209 sanity rule
    if (npcMoralsIsMarked(npcTraitMorals(firstRoll)))
        return npcTraitMorals(secondRoll);
    return npcTraitMorals(firstRoll);
}

int Npctraits::npcTraitPiety(int d12) {
    if (d12 < 1) d12 = 1;
    if (d12 > 12) d12 = 12;
    return d12 - 1;
}

int Npctraits::npcReactGroupCount() { return 9; }

int Npctraits::npcReactionAdjMin(int group) {
    // the neurotic row is the print asymmetry:
    // minus 1 percent to plus 6 percent
    if (group < 0) group = 0;
    if (group > 8) group = 8;
    static const int m[9] = {
        -1, 1, 1, 1, 1, 1, 1, 1, 1,
    };
    return m[group];
}

int Npctraits::npcReactionAdjMax(int group) {
    if (group < 0) group = 0;
    if (group > 8) group = 8;
    static const int x[9] = {
        6, 10, 20, 6, 4, 8, 20, 8, 20,
    };
    return x[group];
}
