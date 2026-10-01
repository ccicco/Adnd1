#!/usr/bin/env python3
"""encounters_merge_r78.py -- R78b: re-add the R74 frequency-weight
generator after the git restore of the Appendix C encounter files.

Run from the repo root AFTER the git restore:
    git show 0fa785dbf1:dm/encounters.h   > dm/encounters.h
    git show 0fa785dbf1:dm/encounters.cpp  > dm/encounters.cpp
    python3 tools/encounters_merge_r78.py [--dry]
"""
import sys
import re

DRY = "--dry" in sys.argv[1:]

H_INC_ANCHOR = '#include "../rules/dice.h"'
H_INC_NEW = '#include "treasure.h"   // R74: Hoard (encounters::rollEncounter)'
NS_ANCHOR = "} // namespace dm"
CPP_INC_ANCHOR = "#include <algorithm>"
CPP_INC_NEW = "#include <cstdint>\n#include <vector>"

H_BLOCK = """
// ==== R74: MM-frequency random encounter generator (merged R78) ====
namespace encounters {

// MM FREQUENCY string -> selection weight. Higher = met more often.
// Unknown/blank strings weight as "uncommon" (defensive: new data
// must not crash the picker).
int frequencyWeight(const std::string& frequency);

struct Encounter {
    const monsters::MonsterDef* def = nullptr; // picked monster (owned by
                                               // the registry - do not free)
    int  count = 0;             // creatures actually appearing (after cap)
    int  rawCount = 0;          // NO. APPEARING roll before the cap
    bool clamped = false;       // rawCount exceeded the cap
    bool inLair = false;        // LAIR % roll succeeded

    treasure::Hoard lairHoard;   // lair letters (inLair only)
    treasure::Hoard carried;     // individual letters x appearing count
    int  treasureRolls = 0;      // letters rolled (audit aid)
};

struct EncounterOptions {
    int  countCap = 50;          // clamp on NO. APPEARING (spawn sanity;
                                 // goblins say "40-400" - a 400-orc spawn
                                 // on one screen is a designer problem)
    bool allowUnique = false;    // Tiamat, Bahamut & friends stay out of
                                 // random rotation unless asked for
    bool rollTreasure = true;    // fill lairHoard/carried
    std::string alignmentFilter; // "" = any; else alignment prefix,
                                 // e.g. "chaotic", "lawful_good"
};

bool rollEncounter(const monsters::MonsterRegistry& reg,
                   rules::Dice& dice,
                   const EncounterOptions& opt,
                   Encounter& out);

} // namespace encounters

"""

CPP_BLOCK = """
// ==== R74: MM-frequency encounter generator (merged R78) ====
namespace encounters {

// ---- frequency table (DMG Appendix C spirit; house weights) -------------
int frequencyWeight(const std::string& frequency) {
    if (frequency == "common")                        return 8;
    if (frequency == "uncommon")                      return 4;
    if (frequency == "rare")                          return 2;
    if (frequency == "very rare")                     return 1;
    if (frequency == "unique")                        return 1;
    return 4;  // unknown/blank -> uncommon weight
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

    int lo = chosen->noAppearingMin;
    int hi = chosen->noAppearingMax;
    if (hi < lo) hi = lo;
    out.rawCount = inRange(dice, lo, hi);
    out.count = out.rawCount > opt.countCap ? opt.countCap
                                            : out.rawCount;
    if (out.count < 1) out.count = 1;       // a meeting, not a rumor
    out.clamped = out.rawCount > out.count;

    out.inLair = chosen->lairPct > 0 && pctRoll(dice, chosen->lairPct);

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

"""


def balance(s):
    s = re.sub(r"//[^\n]*", "", s)
    s = re.sub(r"/\*.*?\*/", "", s, flags=re.S)
    s = re.sub(r'"(?:\\.|[^"\\])*"', '""', s)
    s = re.sub(r"'(?:\\.|[^'\\])*'", "''", s)
    return s.count("{") - s.count("}")


def merge(path, inc_anchor, inc_new, block, what):
    with open(path, encoding="utf-8") as f:
        s = f.read()
    if "namespace encounters {" in s:
        print("SKIP %s: already merged" % path)
        return True
    if inc_anchor not in s:
        print("ABORT %s: include anchor missing: %r" % (path, inc_anchor))
        return False
    if NS_ANCHOR not in s:
        print("ABORT %s: namespace anchor missing" % path)
        return False
    s2 = s.replace(inc_anchor, inc_anchor + "\n" + inc_new, 1)
    idx = s2.rfind(NS_ANCHOR)
    s2 = s2[:idx] + block + s2[idx:]
    if balance(s2) != 0:
        print("ABORT %s: brace balance %d after merge" % (path, balance(s2)))
        return False
    if not DRY:
        with open(path, "w", encoding="utf-8") as f:
            f.write(s2)
    print("%s: merged (%d -> %d lines)" % (what, s.count("\n") + 1, s2.count("\n") + 1))
    return True


ok = merge("dm/encounters.h", H_INC_ANCHOR, H_INC_NEW, H_BLOCK, "header")
ok = merge("dm/encounters.cpp", CPP_INC_ANCHOR, CPP_INC_NEW, CPP_BLOCK, "cpp") and ok
print("DRY RUN - nothing written" if DRY else ("OK - both files written" if ok else "FAILED - no files written"))
sys.exit(0 if ok else 1)
