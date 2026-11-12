// R-refactor: split from npcpersonae.h - definitions
#include "rules/dmg/npcpersonae.h"

int Npcpersonae::npcD10Face(int d) {
    if (d <= 0) return 10;
    if (d > 10) return 10;
    return d;
}

int Npcpersonae::npcClassCount() { return 10; }

int Npcpersonae::npcClassAdjAbility(int cls, int slot) {
    // cleric wisdom +2; fighter and the
    // as-fighter rows (ranger, paladin)
    // strength +2, constitution +1;
    // magic-user intelligence +2,
    // dexterity +1; thief and the
    // as-thief assassin row dexterity +2,
    // intelligence +1, the assassin adding
    // strength +1; druid, illusionist and
    // monk carry minimums only
    if (cls < 0) cls = 0;
    if (cls > 9) cls = 9;
    if (slot < 0) slot = 0;
    if (slot > 2) slot = 2;
    static const int a[30] = {
        2, 6, 6,
        6, 6, 6,
        0, 4, 6,
        0, 4, 6,
        0, 4, 6,
        1, 3, 6,
        6, 6, 6,
        6, 6, 6,
        3, 1, 6,
        3, 1, 0,
    };
    return a[cls * 3 + slot];
}

int Npcpersonae::npcClassAdjAmount(int cls, int slot) {
    if (cls < 0) cls = 0;
    if (cls > 9) cls = 9;
    if (slot < 0) slot = 0;
    if (slot > 2) slot = 2;
    static const int m[30] = {
        2, 0, 0,
        0, 0, 0,
        2, 1, 0,
        2, 1, 0,
        2, 1, 0,
        2, 1, 0,
        0, 0, 0,
        0, 0, 0,
        2, 1, 0,
        2, 1, 1,
    };
    return m[cls * 3 + slot];
}

int Npcpersonae::npcClassMinAbility(int cls, int slot) {
    // druid wisdom/charisma 12/14, ranger
    // wisdom 12, paladin charisma 17,
    // illusionist intelligence/dexterity
    // 15/15, monk strength/wisdom/dexterity
    // 12/15/15; the rest carry none
    if (cls < 0) cls = 0;
    if (cls > 9) cls = 9;
    if (slot < 0) slot = 0;
    if (slot > 2) slot = 2;
    static const int a[30] = {
        6, 6, 6,
        2, 5, 6,
        6, 6, 6,
        2, 6, 6,
        5, 6, 6,
        6, 6, 6,
        1, 3, 6,
        0, 2, 3,
        6, 6, 6,
        6, 6, 6,
    };
    return a[cls * 3 + slot];
}

int Npcpersonae::npcClassMinValue(int cls, int slot) {
    if (cls < 0) cls = 0;
    if (cls > 9) cls = 9;
    if (slot < 0) slot = 0;
    if (slot > 2) slot = 2;
    static const int v[30] = {
        0, 0, 0,
        12, 14, 0,
        0, 0, 0,
        12, 0, 0,
        17, 0, 0,
        0, 0, 0,
        15, 15, 0,
        12, 15, 15,
        0, 0, 0,
        0, 0, 0,
    };
    return v[cls * 3 + slot];
}

int Npcpersonae::npcAdjustedAbility(int score, int adj) {
    // the table footnote: in spite of all
    // additions, normal ability limits
    // cannot be exceeded (JUDGMENT: a
    // clamp to the 3..18 ability range)
    int v = score + adj;
    if (v > 18) v = 18;
    if (v < 3) v = 3;
    return v;
}

int Npcpersonae::npcOccupationCount() { return 3; }

int Npcpersonae::npcOccupationAdjAbility(int occ, int slot) {
    if (occ < 0) occ = 0;
    if (occ > 2) occ = 2;
    if (slot < 0) slot = 0;
    if (slot > 2) slot = 2;
    static const int a[9] = {
        0, 6, 6,
        0, 4, 6,
        6, 6, 6,
    };
    return a[occ * 3 + slot];
}

int Npcpersonae::npcOccupationAdjMin(int occ, int slot) {
    if (occ < 0) occ = 0;
    if (occ > 2) occ = 2;
    if (slot < 0) slot = 0;
    if (slot > 2) slot = 2;
    static const int m[9] = {
        1, 0, 0,
        1, 3, 0,
        0, 0, 0,
    };
    return m[occ * 3 + slot];
}

int Npcpersonae::npcOccupationAdjMax(int occ, int slot) {
    // only the laborer range lifts the max
    // above the min
    if (occ < 0) occ = 0;
    if (occ > 2) occ = 2;
    if (slot < 0) slot = 0;
    if (slot > 2) slot = 2;
    static const int x[9] = {
        3, 0, 0,
        1, 3, 0,
        0, 0, 0,
    };
    return x[occ * 3 + slot];
}

int Npcpersonae::npcMercenaryMinHitPoints() { return 4; }

int Npcpersonae::npcOccupationMinAbility(int occ, int slot) {
    if (occ < 0) occ = 0;
    if (occ > 2) occ = 2;
    if (slot < 0) slot = 0;
    if (slot > 2) slot = 2;
    static const int a[9] = {
        6, 6, 6,
        6, 6, 6,
        1, 5, 6,
    };
    return a[occ * 3 + slot];
}

int Npcpersonae::npcOccupationMinValue(int occ, int slot) {
    if (occ < 0) occ = 0;
    if (occ > 2) occ = 2;
    if (slot < 0) slot = 0;
    if (slot > 2) slot = 2;
    static const int v[9] = {
        0, 0, 0,
        0, 0, 0,
        12, 12, 0,
    };
    return v[occ * 3 + slot];
}

int Npcpersonae::npcDemiRaceCount() { return 4; }

int Npcpersonae::npcRaceAdjAbility(int race, int slot) {
    if (race < 0) race = 0;
    if (race > 3) race = 3;
    if (slot < 0) slot = 0;
    if (slot > 2) slot = 2;
    static const int a[12] = {
        0, 4, 5,
        1, 3, 6,
        2, 4, 5,
        3, 4, 6,
    };
    return a[race * 3 + slot];
}

int Npcpersonae::npcRaceAdjAmount(int race, int slot) {
    if (race < 0) race = 0;
    if (race > 3) race = 3;
    if (slot < 0) slot = 0;
    if (slot > 2) slot = 2;
    static const int m[12] = {
        1, 1, -1,
        1, 1, 0,
        1, 1, -1,
        1, 1, 0,
    };
    return m[race * 3 + slot];
}

int Npcpersonae::npcFactAlign(int d10) {
    // 1 lawful good, 2 lawful neutral,
    // 3 lawful evil, 4 neutral evil,
    // 5 chaotic evil, 6 chaotic neutral,
    // 7 chaotic good, 8 neutral good,
    // 9 neutral, 0 (10) neutral
    static const int t[10] = {
        0, 1, 2, 3, 4,
        5, 6, 7, 8, 8,
    };
    return t[npcD10Face(d10) - 1];
}

int Npcpersonae::npcFactWealth(int d10) {
    // 1 none, 2-3 scant, 4-7 average,
    // 8 above average, 9 exceptional,
    // 0 (10) superabundant
    static const int t[10] = {
        0, 1, 1,
        2, 2, 2,
        2, 3,
        4, 5,
    };
    return t[npcD10Face(d10) - 1];
}

int Npcpersonae::npcFactAgeBand(int d10) {
    // 1 young, 2-3 youthful, 4-7 mature,
    // 8 middle-aged, 9 old, 0 (10) ancient
    static const int t[10] = {
        0, 1, 1,
        2, 2, 2,
        2, 3,
        4, 5,
    };
    return t[npcD10Face(d10) - 1];
}

int Npcpersonae::npcFactGeneralLook(int d10) {
    // the ten general appearance words,
    // each on its own face: dirty, clean,
    // unkempt, immaculate, rough, ragged,
    // dandyish, foppish, non-descript,
    // imposing
    static const int t[10] = {
        0, 1, 2,
        3, 4, 5,
        6, 7,
        8, 9,
    };
    return t[npcD10Face(d10) - 1];
}

int Npcpersonae::npcFactSanity(int d10) {
    // 1 very stable, 2-6 normal,
    // 7 neurotic, 8 unstable, 9 insane,
    // 0 (10) maniacal - the insane and
    // maniacal faces carry the asterisk
    static const int t[10] = {
        0, 1, 1,
        1, 1, 1,
        2, 3,
        4, 5,
    };
    return t[npcD10Face(d10) - 1];
}

bool Npcpersonae::npcSanityIsMarked(int level) {
    // the asterisk rows: insane and
    // maniacal are rolled again
    return level == NPCS_INSANE || level == NPCS_MANIACAL;
}

int Npcpersonae::npcSanityResolved(int firstRoll, int secondRoll) {
    // the asterisk rule: roll again, and
    // if either insane or maniacal is
    // indicated a second time, the
    // character then conforms to that
    // sanity level; in all other cases the
    // second roll stands in place of the
    // first
    if (npcSanityIsMarked(npcFactSanity(firstRoll)))
        return npcFactSanity(secondRoll);
    return npcFactSanity(firstRoll);
}

int Npcpersonae::npcGeneralCharacterDie(int die) {
    // general characters (typical
    // inhabitants and hirelings) roll 3d6
    // but read any 1 as a 3 and any 6 as
    // a 4
    if (die == 1) return 3;
    if (die == 6) return 4;
    return die;
}

int Npcpersonae::npcSpecialCharacterDieBonus(int die) {
    // special characters (including
    // henchmen), in the abilities germane
    // to the profession: +1 to each die of
    // the 3 rolled which scores under 6
    if (die < 6) return 1;
    return 0;
}

int Npcpersonae::npcMinGeneralTendencies() {
    // no fewer than three General
    // Tendencies are determined, more if
    // the DM desires
    return 3;
}
