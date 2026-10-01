// ============================================================================
// Adnd1 - monsters/MonsterXp.cpp
// R49+: implementation of the xpSource dispatch (see MonsterXp.h).
//
// Design notes
//   * The 355 merged_mm1 entries are exact book values - we never
//     recompute those. xpForKill uses xp + xpPerHp * actualHp so an
//     under- or over-average specimen awards correctly (DMG awards
//     per hit point of the actual creature).
//   * The 8 perm_x10 uniques (Orcus, Demogorgon, Asmodeus, ...) carry
//     their printed lump XP in the xp field; the registry's legacy
//     fallback already mirrors it into xpValue, so we return that.
//   * The 43 dispatch monsters (10 dragons, 19 variable-HD animals,
//     13 classed-NPC groups, 1 hydra) resolve via DMG p.85.
//
// R59: DMG p.85 printed ladders (Premium reprint, OCR page 86).
//   baseForHd/perHpForHd/saxpbForHd/eaxpaForHd follow the printed
//   table exactly (see MonsterXp.h). The pre-R59 minima-derived
//   ladders diverged from print above 10 HD (e.g. HD 19-20 gave
//   6300/7400 vs the printed 4000 bracket) and compounded past 20
//   (printed: flat 5000 at 21+); HD 1/5/8 per-hp also drifted.
//   The award for resolved sources is now the printed ADDITIVE
//   formula - BXPV + XP/HP x hp + SAXPB x nSpecial +
//   EAXPA x nExceptional (book example: owlbear 30 hp = 405) -
//   replacing the x2/x3/x4 tier-multiplier heuristic.
// ============================================================================

#include "MonsterXp.h"

#include <algorithm>

namespace monsters {
namespace xp {

// ----------------------------------------------------------------------------
// DMG p.85 base XP by hit dice (tier 1)
// ----------------------------------------------------------------------------
int baseForHd(int hd) {
    if (hd < 1)   return 5;    // "up to 1 - 1" bracket
    // rows 1-10: bracket ending at n ("n-1+1 to n")
    static const int kBase[] = {
        10, 20, 35, 60, 90, 150, 225, 375, 600, 900
    };
    if (hd <= 10) return kBase[hd - 1];

    // rows 11-20: printed brackets "11 to 12+", "13 to 14+", ...
    static const int kHigh[] = {
        1300, 1300, 1800, 1800, 2400,
        2400, 3000, 3000, 4000, 4000
    };
    if (hd <= 20) return kHigh[hd - 11];

    // 21 and up: flat per the printed table
    return 5000;
}

// R59: printed "+1" bracket rule - a def of n (+p) HD sits in the
// bracket ending at n+1 when it carries any hp-per-die bonus
// (e.g. 4 + 1 -> "4 + 1 to 5" -> BXPV 90, not 60). Sub-1 HD (half
// dice) reads the "up to 1 - 1" bracket (row 0).
int rowForHd(int num, int bonus) {
    if (num < 1) return 0;
    return bonus > 0 ? num + 1 : num;
}

// ----------------------------------------------------------------------------
// DMG p.85 XP per hit point by hit dice
//   bands: 1:1  2:2  3-4:3/4  5-6:6  7-8:8  9-10:12/14  11-12:16
//          13-14:18  15-16:20  17-18:25  19-20:30  21+:35
//   (verified: 16HD->20, 22HD->35 in the merged data)
// ----------------------------------------------------------------------------
int perHpForHd(int hd) {
    if (hd < 1)   return 1;    // up to 1 - 1
    if (hd == 1)  return 1;    // 1 - 1 to 1
    if (hd == 2)  return 2;    // 1 + 1 to 2
    if (hd == 3)  return 3;
    if (hd == 4)  return 4;
    if (hd == 5)  return 5;    // 4 + 1 to 5
    if (hd == 6)  return 6;
    if (hd == 7)  return 8;    // 6 + 1 to 7
    if (hd == 8)  return 10;    // 7 + 1 to 8
    if (hd == 9)  return 12;
    if (hd == 10) return 14;
    if (hd <= 12) return 16;
    if (hd <= 14) return 18;
    if (hd <= 16) return 20;
    if (hd <= 18) return 25;
    if (hd <= 20) return 30;
    return 35;                  // 21 and up
}

// R59: Special Ability X.P. Bonus (SAXPB) by bracket row
int saxpbForHd(int hd) {
    if (hd < 1)   return 2;
    static const int kSaxpb[] = {
        4, 8, 15, 25, 40, 75, 125, 175, 300, 450
    };
    if (hd <= 10) return kSaxpb[hd - 1];
    if (hd <= 12) return 700;
    if (hd <= 14) return 950;
    if (hd <= 16) return 1250;
    if (hd <= 18) return 1550;
    if (hd <= 20) return 2100;
    return 2600;
}

// R59: Exceptional Ability X.P. Addition (EAXPA) by bracket row
int eaxpaForHd(int hd) {
    if (hd < 1)   return 25;
    static const int kEaxpa[] = {
        35, 45, 55, 65, 75, 125, 175, 275, 400, 600
    };
    if (hd <= 10) return kEaxpa[hd - 1];
    if (hd <= 12) return 850;
    if (hd <= 14) return 1200;
    if (hd <= 16) return 1600;
    if (hd <= 18) return 2000;
    if (hd <= 20) return 2500;
    return 3000;
}

// ----------------------------------------------------------------------------
// R59: ability counts for the printed ADDITIVE p.85 award
//   xp = BXPV + XP/HP x hp + SAXPB x nSpecial + EAXPA x nExceptional
// Classification per the printed footnotes:
//   special (**): 4+ attacks per round, missile discharge, AC 0 or
//     lower, other special attacks/defenses, high intelligence
//     which affects combat, minor (defensive) spell use.
//   exceptional (***): energy drain, paralysis, poison, major
//     breath weapon, magic resistance, spell use, swallowing
//     whole, weakness, attacks causing max damage > 24.
// Heuristic from the loaded def - the book hand-tunes its own
// suggested values, so counts approximate the printed examples
// (owlbear: 1 special; dragon: 4 special / 3 exceptional).
// ----------------------------------------------------------------------------
namespace {

bool textHas(const std::string& s, const char* needle) {
    if (s.empty()) return false;
    std::string h;
    h.reserve(s.size());
    for (char c : s) h += (char)tolower((unsigned char)c);
    return h.find(needle) != std::string::npos;
}

// flags for typed specials already counted (text markers must not
// double-count the same ability)
struct CountedFlags {
    bool poison = false, paralysis = false, drain = false,
         breath = false, spell = false;
};

void countTyped(const MonsterDef& def, CountedFlags& f,
                int& nExc) {
    for (const auto& sp : def.specials) {
        switch (sp.type) {
        case SPECIAL_POISON:        ++nExc; f.poison = true;    break;
        case SPECIAL_PARALYSIS:     ++nExc; f.paralysis = true; break;
        case SPECIAL_ENERGY_DRAIN:  ++nExc; f.drain = true;    break;
        case SPECIAL_BREATH_WEAPON: ++nExc; f.breath = true;   break;
        default: break;
        }
    }
}

} // namespace

int specialCountOf(const MonsterDef& def) {
    int n = 0;
    if (def.attacks >= 4)     ++n;   // 4 or more attacks per round
    if (def.armorClass <= 0)  ++n;   // armor class 0 or lower
    if (def.requiredPlus > 0) ++n;  // hit only by magic weapons

    const std::string& atk = def.specialAttacksText;
    const std::string& dfs = def.specialDefensesText;
    static const char* kSpecialMarkers[] = {
        "surprise", "constrict", "regenerat", "rend", "hug",
        "missile", "magic weapon", nullptr
    };
    for (int i = 0; kSpecialMarkers[i]; ++i) {
        if (textHas(atk, kSpecialMarkers[i]) ||
            textHas(dfs, kSpecialMarkers[i])) {
            ++n;
        }
    }

    // high intelligence which actually affects combat
    static const char* kSmart[] = {
        "very", "high", "genius", "excel", "supra", nullptr
    };
    for (int i = 0; kSmart[i]; ++i) {
        if (textHas(def.intelligence, kSmart[i])) { ++n; break; }
    }

    // minor/defensive spell use is a special ability (the major
    // spell-use exceptional count lives in exceptionalCountOf)
    if (textHas(atk, "spell") || textHas(dfs, "spell")) ++n;
    return n;
}

int exceptionalCountOf(const MonsterDef& def) {
    CountedFlags f;
    int n = 0;
    countTyped(def, f, n);

    if (def.magicResist > 0) ++n;   // magic resistance

    const std::string& atk = def.specialAttacksText;
    const std::string& dfs = def.specialDefensesText;
    if (!f.poison    && (textHas(atk, "poison") ||
                         textHas(dfs, "poison")))       ++n;
    if (!f.paralysis && (textHas(atk, "paralys") ||
                         textHas(dfs, "paralys")))      ++n;
    if (!f.drain     && (textHas(atk, "energy drain") ||
                         textHas(dfs, "energy drain")))  ++n;
    if (!f.breath    && (textHas(atk, "breath") ||
                         textHas(dfs, "breath")))       ++n;
    if (!f.spell     && (textHas(atk, "spell") ||
                         textHas(dfs, "spell")))        ++n;
    if (textHas(atk, "swallow") || textHas(dfs, "swallow"))  ++n;
    if (textHas(atk, "weakness") || textHas(dfs, "weakness")) ++n;
    if (textHas(atk, "psionic") || textHas(dfs, "psionic"))  ++n;

    // attacks causing maximum damage greater than 24 singly
    for (const auto& d : def.damageRoutines) {
        if (d.max > 24) { ++n; break; }
    }
    return n;
}

// ----------------------------------------------------------------------------
// R53/R59: the def-free classed-NPC path (DMG p.85 by_level math).
// Used by xpForKill's by_level dispatch AND directly for
// Character Subtable party members, who have no lua record.
// Printed p.85 footnote: "Treat peasants/levies as up to 1 - 1,
// men-at-arms as 1 - 1 to 1, and all levels as the n + 1 hit dice
// category" - a level-n character reads bracket row n+1. Spell
// use is an exceptional ability (p.85 ***): casters add EAXPA.
// ----------------------------------------------------------------------------
int xpForNpc(const SpawnContext& ctx) {
    if (ctx.level <= 0) {
        // 0-level men-at-arms: "1 - 1 to 1" bracket (BXPV 10,
        // 1 xp/hp - printed men-at-arms row; peasants/levies at 5
        // are never spawned by the encounter generator)
        int hp = ctx.actualHp > 0 ? ctx.actualHp : 4;
        return 10 + 1 * hp;
    }

    if (ctx.classIndex >= 0 &&
        ctx.classIndex < rules::CLASS_COUNT) {
        // wired path: real class data
        int lvl = ctx.level;
        int row = std::min(lvl + 1, 21);  // row n+1; 21+ is flat
        bool caster = (ctx.classIndex == rules::CLASS_MAGIC_USER ||
                       ctx.classIndex == rules::CLASS_CLERIC);
        int hp = ctx.actualHp;
        if (hp <= 0) {
            // average hp of a lvl-level member of the class:
            // levels below cap roll the die; beyond the cap the
            // class adds a fixed HP_BEYOND_CAP per level
            int cap = rules::CLASS_LEVEL_CAP[ctx.classIndex];
            int die = rules::CLASS_HIT_DIE[ctx.classIndex];
            int avgDie = (1 + die) / 2;   // d10 -> 5, d8 -> 4, ...
            int rolled = std::min(lvl, cap) * (avgDie + ctx.conAdj);
            int fixed  = (lvl > cap)
                ? (lvl - cap) * rules::HP_BEYOND_CAP[ctx.classIndex]
                : 0;
            hp = std::max(1, rolled + fixed);
        }
        int v = baseForHd(row) + perHpForHd(row) * hp;
        if (caster) v += eaxpaForHd(row);  // spell use: exceptional
        return v;
    }

    // unknown class: generic man-type approximation (row n+1,
    // no ability bonuses known)
    int lvl = std::min(ctx.level, 10);
    int hp  = ctx.actualHp;
    if (hp <= 0) hp = lvl * 5;           // Con-avg fighter-ish
    return baseForHd(lvl + 1) + perHpForHd(lvl + 1) * hp;
}

// ----------------------------------------------------------------------------
// The dispatch
// ----------------------------------------------------------------------------
int xpForKill(const MonsterDef& def, const SpawnContext& ctx) {
    const std::string& src = def.xpSource;

    // ---- book-value sources -------------------------------------------
    if (src == "merged_mm1") {
        if (def.xpPerHp > 0) {
            int hp = ctx.actualHp;
            if (hp <= 0) {
                // average specimen: prefer the precomputed xpValue
                // when present, else xp + xpPerHp * avgHp
                if (def.xpValue > def.xpBase && def.xpValue < 1000000)
                    return def.xpValue;
                hp = def.avgHp;
            }
            return def.xpBase + def.xpPerHp * hp;
        }
        // flat book value (golems, etc.): xpValue already mirrors xp
        return def.xpValue > 0 ? def.xpValue : def.xpBase;
    }

    if (src == "perm_x10" || src == "role_variant") {
        return def.xpValue > 0 ? def.xpValue : def.xpBase;
    }

    // ---- resolved sources ----------------------------------------------

    // variable-HD animals: hd comes from the spawn roll
    if (src == "by_hit_dice") {
        int dice = ctx.hd > 0 ? ctx.hd : def.hitDiceNum;
        // printed "+1" bracket rule: n (+p) HD reads row n+1
        int row = ctx.hd > 0 ? rowForHd(dice, def.hitDiceBonus)
                             : rowForHd(def.hitDiceNum,
                                        def.hitDiceBonus);
        if (row < 1) row = 0;   // sub-1 HD bracket (row 0)
        int hp = ctx.actualHp > 0 ? ctx.actualHp
                                 : (int)(dice * 4.5f +
                                         def.hitDiceBonus);
        return baseForHd(row) + perHpForHd(row) * hp +
               saxpbForHd(row)  * specialCountOf(def) +
               eaxpaForHd(row)  * exceptionalCountOf(def);
    }

    // dragons: age bracket 1-8 sets hp/die; HD is the species range
    // (black 6-8, red 9-11, etc.) - ctx.hd is the rolled dice.
    // Printed dragon example (ancient red, 88 hp): BXPV 1300 +
    // 16/hp + SAXPB x4 (armor class, special defense, high
    // intelligence, saving throw bonus) + EAXPA x3 (major breath
    // weapon, spell use, 3-30 bite damage). The classifier reads
    // the def; the breath/spell floors keep young dragons honest.
    if (src == "age_bracket") {
        int hd  = ctx.hd > 0 ? ctx.hd : def.hitDiceNum;
        int age = ctx.ageBracket;
        if (age < 1 || age > 8) age = 5;   // default: adult
        int hp  = ctx.actualHp > 0 ? ctx.actualHp : hd * age;
        int row = std::min(hd, 21);
        int nSp = specialCountOf(def);
        int nEx = exceptionalCountOf(def);
        if (nSp < 2) nSp = 2;   // AC/scales + high intelligence
        if (nEx < 2) nEx = 2;   // breath weapon + spell use
        return baseForHd(row) + perHpForHd(row) * hp +
               saxpbForHd(row) * nSp +
               eaxpaForHd(row) * nEx;
    }

    // hydra: heads == hit dice. Printed example: a 10-headed
    // hydra (80 hp) = BXPV 900 + XP/HP 14 x 80 + SAXPB 450 x1
    // (multiple attacks) - the additive formula directly.
    if (src == "by_head_count") {
        int hd = ctx.heads > 0 ? ctx.heads : def.hitDiceNum;
        if (hd < 1) hd = 5;   // MM1 default roll band 5-12
        int hp = ctx.actualHp > 0 ? ctx.actualHp : hd * 8;
        int row = std::min(hd, 21);
        int nSp = specialCountOf(def);
        if (nSp < 1) nSp = 1;   // multiple attacks on one opponent
        return baseForHd(row) + perHpForHd(row) * hp +
               saxpbForHd(row) * nSp;
    }

    // classed NPCs (men-types). DMG p.85: level is the HD row on the
    // monster table; tier from class/level; hp from the real class
    // hit die + Con adjustment (rules/classes wiring, R49+).
    if (src == "by_level")
        return xpForNpc(ctx);

    // unknown source: fall back to whatever the file carried
    return def.xpValue > 0 ? def.xpValue : def.xpBase;
}

} // namespace xp
} // namespace monsters
