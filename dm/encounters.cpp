// ============================================================================
// Adnd1 — dm/encounters.cpp
// R74 implementation. All randomness flows through rules::Dice (R71
// determinism contract). No I/O — caller decides what an encounter means
// (spawn actors, narrate, or just log).
// ============================================================================

#include "encounters.h"

#include <cstdint>
#include <vector>

namespace dm {
namespace encounters {

// ---- frequency table (DMG Appendix C spirit; house weights) -------------
int frequencyWeight(const std::string& frequency) {
    if (frequency == "common")                        return 8;
    if (frequency == "uncommon")                      return 4;
    if (frequency == "rare")                          return 2;
    if (frequency == "very rare")                     return 1;
    if (frequency == "unique")                        return 1;
    return 4;  // unknown/blank → uncommon weight
}

// local dice helpers (same conventions as dm/treasure.cpp)
static int inRange(rules::Dice& d, int lo, int hi) {         // [lo, hi]
    if (hi <= lo) return lo;
    return lo + (int)d.d((uint32_t)(hi - lo + 1)) - 1;
}
static bool pctRoll(rules::Dice& d, int pct) {               // 0-99 < pct
    return (int)d.d100() - 1 < pct;
}

static bool isUnique(const monsters::MonsterDef& def) {
    return def.frequency == "unique" || def.xpSource == "perm_x10";
}

static bool alignmentOk(const monsters::MonsterDef& def,
                        const std::string& filter) {
    if (filter.empty()) return true;
    // prefix match on the normalized alignment string
    return def.alignment.compare(0, filter.size(), filter) == 0;
}

// Roll one treasure-letter set into the destination hoard.
static void rollLetters(rules::Dice& dice,
                        const std::vector<monsters::TreasureEntry>& list,
                        int nCreatures,
                        treasure::Hoard& out,
                        int& rolls) {
    for (const auto& e : list) {
        for (int t = 0; t < e.times; ++t) {
            out.absorb(treasure::rollTreasureType(dice, e.letter,
                                                  nCreatures,
                                                  e.magicOnly));
            ++rolls;
        }
    }
}

bool rollEncounter(const monsters::MonsterRegistry& reg,
                   rules::Dice& dice,
                   const EncounterOptions& opt,
                   Encounter& out) {
    out = Encounter{};
    const auto& all = reg.all();

    // ---- weighted pick over eligible monsters ------------------------
    // Two passes (total weight, then pick) over the std::map keeps this
    // allocation-light; encounter rolls are not hot-path.
    long long total = 0;
    for (const auto& kv : all) {
        const monsters::MonsterDef& d = kv.second;
        if (!opt.allowUnique && isUnique(d)) continue;
        if (!alignmentOk(d, opt.alignmentFilter)) continue;
        total += frequencyWeight(d.frequency);
    }
    if (total <= 0) return false;

    long long pick = inRange(dice, 1, (int)total);
    const monsters::MonsterDef* chosen = nullptr;
    for (const auto& kv : all) {
        const monsters::MonsterDef& d = kv.second;
        if (!opt.allowUnique && isUnique(d)) continue;
        if (!alignmentOk(d, opt.alignmentFilter)) continue;
        pick -= frequencyWeight(d.frequency);
        if (pick <= 0) { chosen = &d; break; }
    }
    if (!chosen) return false;              // cannot happen; belt & braces

    out.def = chosen;

    // ---- NO. APPEARING (clamped for spawn sanity) --------------------
    int lo = chosen->noAppearingMin;
    int hi = chosen->noAppearingMax;
    if (hi < lo) hi = lo;
    out.rawCount = inRange(dice, lo, hi);
    out.count = out.rawCount > opt.countCap ? opt.countCap
                                            : out.rawCount;
    if (out.count < 1) out.count = 1;       // a meeting, not a rumor
    out.clamped = out.rawCount > out.count;

    // ---- LAIR % -------------------------------------------------------
    // MM: % IN LAIR is the chance the encounter is at the lair (and
    // only then does the lair treasure apply).
    out.inLair = chosen->lairPct > 0 && pctRoll(dice, chosen->lairPct);

    // ---- treasure (R71 letters, R73-verified roller) ------------------
    if (opt.rollTreasure) {
        if (out.inLair && !chosen->treasure.lair.empty())
            rollLetters(dice, chosen->treasure.lair, out.count,
                        out.lairHoard, out.treasureRolls);
        if (!chosen->treasure.individual.empty())
            rollLetters(dice, chosen->treasure.individual, out.count,
                        out.carried, out.treasureRolls);
    }
    return true;
}

} // namespace encounters
} // namespace dm
