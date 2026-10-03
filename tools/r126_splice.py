#!/usr/bin/python3
# tools/r126_splice.py - R126 wilderness encounter tables
# verification (DMG pp.182-189, the R63 Appendix C outdoor
# tables - the R122 line-diff pattern).
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints.
#  - dm/encounters.h + .cpp: OutdoorBand and the
#    outdoorBands/outdoorSubBands regtest accessors; the
#    R126 verification header note; two printed-gap
#    resolutions documented in-row (temperate wild scrub
#    Humanoid 36-32 -> 26-32, tropical rough giant
#    scorpion 84-84 -> 84-85)
#  - regtest.cpp: the R126 wilderness line-diff audit -
#    band continuity 1 -> 100 for all 8 climate matrices
#    and the 11 subtables plus the tropical Sphinx
#    footnote, and spot pins from the verified
#    transcription (census becomes 44)
#  - tools/dmg_gap_report.md: the pp.182-189 box flips
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding="ascii") as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), "w", encoding="ascii") as f:
        f.write(s)

def patch(p, old, new, tag, expect=1, marker=None):
    s = rd(p)
    # idempotency keys on a distinctive NEW-side marker:
    # an anchor that is a PREFIX of its replacement still
    # counts after the patch, so "old not in s" cannot be
    # the already-applied test.
    if marker is None:
        marker = new
    if marker in s:
        already.append(tag)
        return
    n = s.count(old)
    if n != expect:
        fails.append(tag + ": anchor count " + str(n)
                     + " (expected " + str(expect) + ")")
        return
    wr(p, s.replace(old, new))
    applied.append(tag)

# R126-CHUNK-1-START (encounters.h + encounters.cpp)

# the header: OutdoorBand + the two accessors after
# outdoorEncounterKeys
patch("dm/encounters.h",
"""// Every registry key the climate/terrain column can produce -
// the regtest-style companion of rollOutdoorEncounter.
std::vector<std::string> outdoorEncounterKeys(
    const monsters::MonsterRegistry& reg,
    OutdoorClime clime, OutdoorTerrain terrain);


// R64: DMG Appendix C CITY/TOWN ENCOUNTER MATRIX (Premium""",
"""// Every registry key the climate/terrain column can produce -
// the regtest-style companion of rollOutdoorEncounter.
std::vector<std::string> outdoorEncounterKeys(
    const monsters::MonsterRegistry& reg,
    OutdoorClime clime, OutdoorTerrain terrain);

// R126: the printed band edges behind outdoorEncounterKeys -
// the regtest line-diff audit walks them (the R122 shape
// applied to the R63 outdoor tables). One OutdoorBand per
// printed band, low-ascending; a climate/terrain column the
// climate does not serve comes back empty (the Arctic serves
// Plain/Rough/Mountains only, etc.). outdoorSubBands takes a
// SUB_* pseudo-key and its terrain column; the tropical
// Sphinx Subtable is the p.189 single-column footnote and
// reports under SUB_SPHINX_T for any terrain.
struct OutdoorBand {
    std::string key;
    int lo;
    int hi;
};
std::vector<OutdoorBand> outdoorBands(
    OutdoorClime clime, OutdoorTerrain terrain);
std::vector<OutdoorBand> outdoorSubBands(
    const std::string& subKey, OutdoorTerrain terrain);


// R64: DMG Appendix C CITY/TOWN ENCOUNTER MATRIX (Premium""",
      "encounters.h: OutdoorBand accessors",
      marker="struct OutdoorBand {")

# the R126 verification note in the R63 header
patch("dm/encounters.cpp",
"""// 31-00 -> 51-00.

namespace {""",
"""// 31-00 -> 51-00.
//
// R126: the five climates the 1eonline.info Appendix C
// compilation carries (Arctic, Sub-Arctic, both Temperate,
// Tropical) are line-diffed band-for-band against it - clean
// modulo the documented folds. Two more printed-gap
// resolutions are now documented in-row (the giant-eagle
// pattern): temperate wild scrub Humanoid 36-32 -> 26-32 and
// tropical rough giant scorpion 84-84 -> 84-85. The
// compilation omits the Faerie, Pleistocene and Age of
// Dinosaurs tables - they ride the book-verify debt. Its
// variant readings (tropical mountains dervish 29-30 apart
// from bandit 23-28; marsh Men nomad/tribesman where the
// reprint resolves pilgrim/tribesman) stay with the reprint:
// the documented folds are pinned. Pinned by the R126
// battery audit.

namespace {""",
      "encounters.cpp: R126 header note",
      marker="// R126: the five climates the 1eonline.info Appendix C")

# the two printed-gap resolutions, documented in-row
patch("dm/encounters.cpp",
"""{"SUB_HUMANOID",
  {31, 26, 26, 26, 20, 40, 33, 17},
  {33, 32, 30, 30, 28, 50, 40, 30}},""",
"""{"SUB_HUMANOID",
  {31, 26, 26, 26, 20, 40, 33, 17},
  {33, 32, 30, 30, 28, 50, 40, 30}},   // S 36-32 OCR -> 26-32 (Jackal 33-34 follows, covers the printed gap, documented),""",
      "encounters.cpp: scrub Humanoid 36-32 documented",
      marker="S 36-32 OCR -> 26-32")

patch("dm/encounters.cpp",
"""{"giant_scorpion",
  {86, 85, 61, 84, 84, -1, -1, -1},
  {90, 86, 64, 85, 89, -1, -1, -1}},""",
"""{"giant_scorpion",
  {86, 85, 61, 84, 84, -1, -1, -1},
  {90, 86, 64, 85, 89, -1, -1, -1}},   // R 84-84 OCR -> 84-85 to cover the printed gap at 85 (poisonous snake 86-88 follows, documented),""",
      "encounters.cpp: rough scorpion 84-84 documented",
      marker="R 84-84 OCR -> 84-85")
# R126-CHUNK-1-END
# R126-CHUNK-2-START (the accessors + regtest + gap report)

# the accessors, after outdoorEncounterKeys
patch("dm/encounters.cpp",
"""    size_t n = 0;
    const OutdoorRow* t = outTable(clime, n);
    if (t) pushOutKeys(out, reg, t, n, (int)terrain);
    return out;
}
""",
"""    size_t n = 0;
    const OutdoorRow* t = outTable(clime, n);
    if (t) pushOutKeys(out, reg, t, n, (int)terrain);
    return out;
}

namespace {

// R126: the subtable matrix behind a SUB_* pseudo-key (see
// encounters.h; the tropical Sphinx Subtable is single-
// column and never reaches here - outdoorSubBands handles
// it before the lookup).
const OutdoorRow* outSub(const std::string& subKey, size_t& n) {
    if      (subKey == "SUB_DEMIHUMAN")   { n = sizeof kOutDemiHuman   / sizeof kOutDemiHuman[0];   return kOutDemiHuman; }
    else if (subKey == "SUB_DRAGON")      { n = sizeof kOutDragon      / sizeof kOutDragon[0];      return kOutDragon; }
    else if (subKey == "SUB_FROG")        { n = sizeof kOutFrog        / sizeof kOutFrog[0];        return kOutFrog; }
    else if (subKey == "SUB_GIANT")       { n = sizeof kOutGiant       / sizeof kOutGiant[0];       return kOutGiant; }
    else if (subKey == "SUB_HUMANOID")    { n = sizeof kOutHumanoid    / sizeof kOutHumanoid[0];    return kOutHumanoid; }
    else if (subKey == "SUB_LYCANTHROPE") { n = sizeof kOutLycanthrope / sizeof kOutLycanthrope[0]; return kOutLycanthrope; }
    else if (subKey == "SUB_MEN")         { n = sizeof kOutMen         / sizeof kOutMen[0];         return kOutMen; }
    else if (subKey == "SUB_SNAKE")       { n = sizeof kOutSnake       / sizeof kOutSnake[0];       return kOutSnake; }
    else if (subKey == "SUB_SPHINX")      { n = sizeof kOutSphinx      / sizeof kOutSphinx[0];      return kOutSphinx; }
    else if (subKey == "SUB_SPIDER")      { n = sizeof kOutSpider       / sizeof kOutSpider[0];      return kOutSpider; }
    else if (subKey == "SUB_UNDEAD")      { n = sizeof kOutUndead      / sizeof kOutUndead[0];      return kOutUndead; }
    n = 0; return nullptr;
}

// R126: collect a column's bands, low-ascending
static void pushBands(std::vector<OutdoorBand>& out,
                      const OutdoorRow* t, size_t n, int ti) {
    for (size_t i = 0; i < n; ++i) {
        if (t[i].lo[ti] < 0) continue;
        OutdoorBand b;
        b.key = t[i].key;
        b.lo  = t[i].lo[ti];
        b.hi  = t[i].hi[ti];
        out.push_back(b);
    }
    std::stable_sort(out.begin(), out.end(),
                     
                     { return a.lo < b.lo; });
}

} // namespace

// R126: the printed band edges behind the tables - see
// encounters.h.
std::vector<OutdoorBand> outdoorBands(
        OutdoorClime clime, OutdoorTerrain terrain) {
    std::vector<OutdoorBand> out;
    size_t n = 0;
    const OutdoorRow* t = outTable(clime, n);
    if (t) pushBands(out, t, n, (int)terrain);
    return out;
}

std::vector<OutdoorBand> outdoorSubBands(
        const std::string& subKey, OutdoorTerrain terrain) {
    std::vector<OutdoorBand> out;
    if (subKey == "SUB_SPHINX_T") {
        // tropical footnote: single-column Sphinx Subtable
        // (p.189) - 01-10/11-40/41-70/71-00
        static const char* kSphinxT[4] = {
            "androsphinx", "criosphinx",
            "gynosphinx", "hieracosphinx"
        };
        static const int kLoT[4] = { 1, 11, 41, 71 };
        static const int kHiT[4] = { 10, 40, 70, 100 };
        for (int i = 0; i < 4; ++i) {
            OutdoorBand b;
            b.key = kSphinxT[i];
            b.lo  = kLoT[i];
            b.hi  = kHiT[i];
            out.push_back(b);
        }
        return out;
    }
    size_t n = 0;
    const OutdoorRow* sub = outSub(subKey, n);
    if (sub) pushBands(out, sub, n, (int)terrain);
    return out;
}
""",
      "encounters.cpp: outdoorBands/outdoorSubBands",
      marker="const OutdoorRow* outSub(")

# regtest.cpp: the spot-check helper before main
patch("regtest.cpp",
"""
int main() {
    monsters::MonsterRegistry reg;
""",
"""
// R126: does the band list carry this exact (key, lo, hi)
// pin? - the wilderness line-diff audit's spot-check helper
static bool bandHas(const std::vector<dm::encounters::OutdoorBand>& b,
                    const char* k, int lo, int hi) {
    for (const auto& x : b)
        if (x.key == k && x.lo == lo && x.hi == hi) return true;
    return false;
}

int main() {
    monsters::MonsterRegistry reg;
""",
      "regtest.cpp: bandHas helper",
      marker="static bool bandHas(")

# regtest.cpp: the R126 audit after the R125 block
patch("regtest.cpp",
"""        printf("R125 traps and tricks audit: bad %d\\n", bad);
        if (bad) return 1;
    }
""",
"""        printf("R125 traps and tricks audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R126: wilderness line-diff audit ----
    {
        int bad = 0;
        namespace OE = dm::encounters;
        // every served climate/terrain column chains 1 -> 100:
        // no gap, no overlap, no inverted band (the R122
        // line-diff shape on the R63 outdoor tables)
        for (int c = 0; c < 8; ++c) {
            for (int t = 0; t < 8; ++t) {
                std::vector<OE::OutdoorBand> b = OE::outdoorBands(
                    (OE::OutdoorClime)c, (OE::OutdoorTerrain)t);
                if (b.empty()) continue;
                int lo = 1;
                for (const OE::OutdoorBand& x : b) {
                    if (x.lo != lo || x.hi < x.lo) ++bad;
                    lo = x.hi + 1;
                }
                if (lo != 101) ++bad;
            }
        }
        // the eleven terrain-column subtables chain likewise;
        // SUB_SPHINX_T is the tropical single-column footnote
        static const char* kSubs[12] = {
            "SUB_DEMIHUMAN", "SUB_DRAGON", "SUB_FROG",
            "SUB_GIANT", "SUB_HUMANOID", "SUB_LYCANTHROPE",
            "SUB_MEN", "SUB_SNAKE", "SUB_SPHINX",
            "SUB_SPIDER", "SUB_UNDEAD", "SUB_SPHINX_T"
        };
        for (const char* s : kSubs) {
            for (int t = 0; t < 8; ++t) {
                std::vector<OE::OutdoorBand> b = OE::outdoorSubBands(
                    s, (OE::OutdoorTerrain)t);
                if (b.empty()) continue;
                int lo = 1;
                for (const OE::OutdoorBand& x : b) {
                    if (x.lo != lo || x.hi < x.lo) ++bad;
                    lo = x.hi + 1;
                }
                if (lo != 101) ++bad;
            }
        }
        // spot pins from the verified transcription - the
        // documented OCR/print folds (R63 header, R126
        // line-diff vs. the 1eonline Appendix C compilation)
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorBands(
                OE::OC_TEMPERATE_WILD, OE::T_SCRUB);
            if (!bandHas(b, "SUB_HUMANOID", 26, 32)) ++bad;
        }
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorBands(
                OE::OC_TEMPERATE_WILD, OE::T_PLAIN);
            if (!bandHas(b, "giant_eagle", 15, 16)) ++bad;
        }
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorBands(
                OE::OC_TROPICAL, OE::T_ROUGH);
            if (!bandHas(b, "giant_scorpion", 84, 85)) ++bad;
        }
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorBands(
                OE::OC_TROPICAL, OE::T_MOUNTAINS);
            if (!bandHas(b, "bandit", 23, 30)) ++bad;
        }
        {
            // the tropical mountains Sphinx row resolves off
            // the p.189 single-column footnote - all four
            std::vector<std::string> k = OE::outdoorEncounterKeys(
                reg, OE::OC_TROPICAL, OE::T_MOUNTAINS);
            int seen = 0;
            for (const std::string& x : k) {
                if (x == "androsphinx" || x == "criosphinx" ||
                    x == "gynosphinx" || x == "hieracosphinx") ++seen;
            }
            if (seen != 4) ++bad;
        }
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorBands(
                OE::OC_SUB_ARCTIC, OE::T_MARSH);
            if (!bandHas(b, "caveman", 56, 65)) ++bad;
        }
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorBands(
                OE::OC_ARCTIC, OE::T_MOUNTAINS);
            if (!bandHas(b, "yeti", 91, 100)) ++bad;
        }
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorSubBands(
                "SUB_DRAGON", OE::T_FOREST);
            if (!bandHas(b, "chimera", 23, 30)) ++bad;
        }
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorSubBands(
                "SUB_GIANT", OE::T_HILLS);
            if (!bandHas(b, "stone_giant", 82, 98)) ++bad;
        }
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorSubBands(
                "SUB_MEN", OE::T_MARSH);
            if (!bandHas(b, "pilgrim", 36, 50)) ++bad;
            if (!bandHas(b, "caveman", 51, 100)) ++bad;
        }
        printf("R126 wilderness line-diff audit: bad %d\\n", bad);
        if (bad) return 1;
    }
""",
      "regtest.cpp: R126 wilderness line-diff audit",
      marker="R126: wilderness line-diff audit")

# the gap report box flips
patch("tools/dmg_gap_report.md",
"""- [ ] **Wilderness encounter tables
      (pp.182-189)** - the appendix C-style
      tables for outdoor play.""",
"""- [x] **Wilderness encounter tables
      (pp.182-189)** - CLOSED R126: the R63 climate
      matrices (Arctic, Sub-Arctic, Temperate Wild,
      Temperate Inhabited, Faerie, Pleistocene, Age of
      Dinosaurs, Tropical) and the eleven terrain-column
      subtables (plus the tropical single-column Sphinx
      footnote) are line-diffed against the 1eonline.info
      Appendix C compilation: the five climates it carries
      match band-for-band modulo the documented OCR folds,
      and the two undocumented printed-gap resolutions
      (temperate wild scrub Humanoid 36-32 -> 26-32,
      tropical rough giant scorpion 84-84 -> 84-85) are now
      documented in-row. The compilation omits the Faerie,
      Pleistocene and Age of Dinosaurs tables - those three
      ride the book-verify debt with the printed table as
      the winner, as do the printing-variant readings
      (tropical mountains dervish 29-30; marsh Men
      nomad/tribesman). Pinned by the R126 battery audit;
      census 44.""",
      "gap report: wilderness box flips",
      marker="CLOSED R126:")
# R126-CHUNK-2-END

# ---- the end ----
if fails:
    for f in fails:
        print("FAIL: " + f)
    sys.exit(1)
if not applied and not already:
    print("FAIL: nothing to do - anchors not found?")
    sys.exit(1)
print("R126 splice: ALL OK (applied %d, already %d)"
      % (len(applied), len(already)))
