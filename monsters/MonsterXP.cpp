// ============================================================================
// Adnd1 — monsters/MonsterXp.cpp
// R49+: implementation of the xpSource dispatch (see MonsterXp.h).
//
// Design notes
//   * The 355 merged_mm1 entries are exact book values — we never
//     recompute those. xpForKill uses xp + xpPerHp * actualHp so an
//     under- or over-average specimen awards correctly (DMG awards
//     per hit point of the actual creature).
//   * The 8 perm_x10 uniques (Orcus, Demogorgon, Asmodeus, ...) carry
//     their printed lump XP in the xp field; the registry's legacy
//     fallback already mirrors it into xpValue, so we return that.
//   * The 43 dispatch monsters (10 dragons, 19 variable-HD animals,
//     13 classed-NPC groups, 1 hydra) resolve via DMG p.85.
//
// DMG p.85 ladders
//   baseForHd rows 1-10 are the minima observed in the verified merged
//   data (10, 20, 35, 60, 90, 150, 225, 375, 600, 900) — identical to
//   the DMG table. 11-20 interpolate the observed merged minima (12 HD
//   -> 1300, 13 HD -> 1800); 21+ continues x1.15/hd as a documented
//   Adnd1 extension: MM1 prints no XP for the variable-HD animals
//   that live there (whales, sharks).
//   perHpForHd is the verified ladder straight from the merged data:
//   16 HD -> 20/hp (aerial servant), 22 HD -> 35/hp (elder titan).
// ============================================================================

#include "MonsterXp.h"

#include <algorithm>
#include <cmath>

namespace monsters {
namespace xp {

// ----------------------------------------------------------------------------
// DMG p.85 base XP by hit dice (tier 1)
// ----------------------------------------------------------------------------
int baseForHd(int hd) {
    if (hd < 1)  hd = 1;
    // rows 1-10: verified merged-data minima == DMG p.85
    static const int kBase[] = {
        10, 20, 35, 60, 90, 150, 225, 375, 600, 900
    };
    if (hd <= 10) return kBase[hd - 1];

    // rows 11-20: smoothed through the observed minima at 12 HD (1300)
    // and 13 HD (1800) in the merged data — the DMG progression grows
    // ~x1.15/hd up here, not the x1.5 of the low rows.
    static const int kHigh[] = {
        1100, 1300, 1800, 2300, 2900,
        3600, 4400, 5300, 6300, 7400
    };
    if (hd <= 20) return kHigh[hd - 11];

    // 21+: continue x1.15/hd, rounded to 100 (whale country: MM1
    // prints no XP for these; documented Adnd1 extension)
    double v = 7400.0 * std::pow(1.15, hd - 20);
    return (int)std::min<long>((long)std::lround(v / 100.0) * 100, 500000L);
}

// ----------------------------------------------------------------------------
// DMG p.85 XP per hit point by hit dice
//   bands: 1:1  2:2  3-4:3/4  5-6:6  7-8:8  9-10:12/14  11-12:16
//          13-14:18  15-16:20  17-18:25  19-20:30  21+:35
//   (verified: 16HD->20, 22HD->35 in the merged data)
// ----------------------------------------------------------------------------
int perHpForHd(int hd) {
    if (hd < 1)   return 1;
    if (hd <= 2)  return 2;
    if (hd <= 3)  return 3;
    if (hd <= 4)  return 4;
    if (hd <= 6)  return 6;
    if (hd <= 8)  return 8;
    if (hd == 9)  return 12;
    if (hd == 10) return 14;
    if (hd <= 12) return 16;
    if (hd <= 14) return 18;
    if (hd <= 16) return 20;
    if (hd <= 18) return 25;
    if (hd <= 20) return 30;
    return 35;
}

// ----------------------------------------------------------------------------
// Special-ability tier (DMG p.85: x1 / x2 / x3 / x4)
// Heuristic from the loaded def. Counting:
//   +1 per typed special attack (poison, paralysis, energy drain, breath)
//   +1 magic resistance > 0
//   +1 weapon-plus requirement (requiredPlus > 0)
//   +1 strong text markers in specialAttacks/specialDefenses
//       ("surprise", "swallow", "constrict", "regenerat", "spell",
//        "energy drain", "psionic")
// Map: 0 -> x1, 1 -> x2, 2-3 -> x3, 4+ -> x4.
// The encounter generator may compute its own tier for known cases
// (e.g. dragons: breath + spells + fear aura -> x3 or x4) and pass
// a SpawnContext carrying it via def override... simplest is to call
// tierOf() and adjust at the call site.
// ----------------------------------------------------------------------------
namespace {

bool textHas(const std::string& s, const char* needle) {
    if (s.empty()) return false;
    std::string h;
    h.reserve(s.size());
    for (char c : s) h += (char)tolower((unsigned char)c);
    return h.find(needle) != std::string::npos;
}

} // namespace

int tierOf(const MonsterDef& def) {
    int count = (int)def.specials.size();

    if (def.magicResist > 0)   ++count;
    if (def.requiredPlus > 0) ++count;

    const std::string& atk = def.specialAttacksText;
    const std::string& dfs = def.specialDefensesText;
    static const char* kMarkers[] = {
        "surprise", "swallow", "constrict", "regenerat",
        "spell", "energy drain", "psionic", "breath", nullptr
    };
    for (int i = 0; kMarkers[i]; ++i) {
        if (textHas(atk, kMarkers[i]) || textHas(dfs, kMarkers[i])) {
            ++count;
            break;   // markers count once, not each
        }
    }

    if (count <= 0) return 1;
    if (count == 1) return 2;
    if (count <= 3) return 3;
    return 4;
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
        int hd = ctx.hd > 0 ? ctx.hd : def.hitDiceNum;
        if (hd < 1) hd = 1;
        int hp = ctx.actualHp > 0 ? ctx.actualHp
                                 : (int)(hd * 4.5f + def.hitDiceBonus);
        int v = baseForHd(hd) * tierOf(def) + perHpForHd(hd) * hp;
        return v;
    }

    // dragons: age bracket 1-8 sets hp/die; HD is the species range
    // (black 6-8, red 9-11, etc.) — ctx.hd is the rolled dice.
    if (src == "age_bracket") {
        int hd  = ctx.hd > 0 ? ctx.hd : def.hitDiceNum;
        int age = ctx.ageBracket;
        if (age < 1 || age > 8) age = 5;   // default: adult
        int hp  = ctx.actualHp > 0 ? ctx.actualHp : hd * age;
        // dragons: breath + spells + fear aura -> x3, +x4 if the
        // generator knows the specimen casts; tierOf reads the text
        int t = tierOf(def);
        if (t < 3) t = 3;
        return baseForHd(hd) * t + perHpForHd(hd) * hp;
    }

    // hydra: heads == hit dice
    if (src == "by_head_count") {
        int hd = ctx.heads > 0 ? ctx.heads : def.hitDiceNum;
        if (hd < 1) hd = 5;   // MM1 default roll band 5-12
        int hp = ctx.actualHp > 0 ? ctx.actualHp : hd * 8;
        return baseForHd(hd) * std::max(tierOf(def), 2) + perHpForHd(hd) * hp;
    }

    // classed NPCs (men-types). 0-level: DMG man = HD<1 row.
    // Leveled: TODO wire to rules/classes XP tables; until then the
    // DMG-shaped approximation base(level) covers the common 1-10
    // range sanely (a 5th-level fighter ~ 60+4/hp book value).
    if (src == "by_level") {
        if (ctx.level <= 0) {
            int hp = ctx.actualHp > 0 ? ctx.actualHp : 4;
            return 5 + 1 * hp;               // 0-level man: 5 + 1/hp
        }
        int lvl = std::min(ctx.level, 10);
        int hp  = ctx.actualHp;
        if (hp <= 0) hp = lvl * 5;           // Con-avg fighter-ish
        return baseForHd(lvl) * std::max(tierOf(def), 2) + perHpForHd(lvl) * hp;
    }

    // unknown source: fall back to whatever the file carried
    return def.xpValue > 0 ? def.xpValue : def.xpBase;
}

} // namespace xp
} // namespace monsters
