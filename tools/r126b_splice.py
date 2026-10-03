#!/usr/bin/python3
# tools/r126b_splice.py - R126 REPAIR: fixes the two
# paste-delivery faults that broke the r126_splice.py run
# (run AFTER r126_splice.py; it touches only what the
# first splice left broken). Idempotent: safe to run
# twice; a silent run means the paste was truncated -
# this tail ALWAYS prints.
#  P0 tools/r126_splice.py: repairs the splice itself.
#     The audit patch's printf \n arrived as a single
#     backslash inside a NON-raw python string (python
#     read it as a newline, so the regtest anchor could
#     never match), and the paste dropped a character
#     inside the stable_sort lambda line (clang's
#     "expected expression"). After repair the file
#     should md5 to the authored master - printed.
#  P1 dm/encounters.cpp: replaces the sort span with a
#     call to a named comparator function - a find()-
#     based span replace, immune to whatever the dropped
#     character left in the lambda line.
#  P2 regtest.cpp: bandHas's dm::encounters::OutdoorBand
#     -> dm::OutdoorBand (the outdoor API - OutdoorBand,
#     outdoorBands, rollOutdoorEncounter - lives in
#     namespace dm, not dm::encounters).
#  P3 regtest.cpp: inserts the R126 wilderness line-diff
#     audit after the R125 block, with the printf \n
#     carried in a RAW python string this time.
import hashlib, os, sys

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
    # idempotency keys on a distinctive NEW-side marker
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

# ---- P0: repair tools/r126_splice.py itself ----
s = rd("tools/r126_splice.py")
fixed = 0
nfix = s.count(r'bad %d\n", bad);')
if nfix:
    s = s.replace(r'bad %d\n", bad);', r'bad %d\\n", bad);')
    fixed += nfix
master = r"""    std::stable_sort(out.begin(), out.end(),
                     
                     { return a.lo < b.lo; });"""
i = s.find("    std::stable_sort(out.begin(), out.end(),")
j = s.find("});", i) if i >= 0 else -1
if i >= 0 and j >= 0:
    if s[i:j + 3] != master:
        s = s[:i] + master + s[j + 3:]
        fixed += 1
else:
    fails.append("r126 splice repair: sort span not found "
                 "(i=" + str(i) + ", j=" + str(j) + ")")
wr("tools/r126_splice.py", s)
print("P0 r126 splice repaired: " + str(fixed)
      + " fault(s); md5 now "
      + hashlib.md5(s.encode("ascii")).hexdigest()
      + " (authored master: "
      + "4e45a175b868a4bd28e95ad6a9bea34a)")
if fixed:
    applied.append("r126 splice file repaired")
else:
    already.append("r126 splice file repaired")

# ---- P1: encounters.cpp - named comparator, no lambda ----
s = rd("dm/encounters.cpp")
if "outBandLess" in s:
    already.append("encounters.cpp: named comparator sort")
else:
    i = s.find("    std::stable_sort(out.begin(), out.end(),")
    j = s.find("});", i) if i >= 0 else -1
    k = s.find("// R126: collect a column's bands")
    if k < 0:
        k = s.find("static void pushBands(")
    if i < 0 or j < 0 or k < 0:
        fails.append("encounters.cpp: sort span not found (i="
                     + str(i) + ", j=" + str(j) + ", k=" + str(k) + ")")
    else:
        s = (s[:i]
             + "    std::stable_sort(out.begin(), out.end(), outBandLess);"
             + s[j + 3:])
        s = (s[:k]
             + "// R126: band order comparator (lo ascending)\n"
               "static bool outBandLess(const OutdoorBand& x,\n"
               "                        const OutdoorBand& y) {\n"
               "    return x.lo < y.lo;\n"
               "}\n\n"
             + s[k:])
        wr("dm/encounters.cpp", s)
        applied.append("encounters.cpp: named comparator sort")

# ---- P2: bandHas type is dm::OutdoorBand ----
patch("regtest.cpp",
r"""static bool bandHas(const std::vector<dm::encounters::OutdoorBand>& b,""",
r"""static bool bandHas(const std::vector<dm::OutdoorBand>& b,""",
      "regtest.cpp: bandHas type is dm::OutdoorBand",
      marker="std::vector<dm::OutdoorBand>& b")

# ---- P3: the R126 wilderness line-diff audit ----
patch("regtest.cpp",
r"""        printf("R125 traps and tricks audit: bad %d\n", bad);
        if (bad) return 1;
    }
""",
r"""        printf("R125 traps and tricks audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R126: wilderness line-diff audit ----
    {
        int bad = 0;
        namespace OE = dm;
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
        printf("R126 wilderness line-diff audit: bad %d\n", bad);
        if (bad) return 1;
    }
""",
      "regtest.cpp: R126 wilderness line-diff audit",
      marker="R126: wilderness line-diff audit")

# ---- the end ----
if fails:
    for f in fails:
        print("FAIL: " + f)
    sys.exit(1)
if not applied and not already:
    print("FAIL: nothing to do - anchors not found?")
    sys.exit(1)
print("R126b repair: ALL OK (applied %d, already %d)"
      % (len(applied), len(already)))
