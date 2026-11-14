#!/usr/bin/env python3
# r1048_splice.py - the R1048 splice: the straggler
# band/grid de-wire (four leftovers across three
# books).
#
# WHAT retires:
#   rules/phb/palrangerspells.h  kSlots[12][4] and
#     kSlots[10][5] (the paladin 9-20 x 4 and
#     ranger 8-17 x 5 slot grids) -> NEW DIRECTORY
#     content/tables/class_slots/ (def keys
#     paladin_slots, ranger_slots; tables[1]
#     "grid" flat row-major, RowCount/ColCount
#     pins). NOT class_grids/ - the R1047 fragment
#     pins that directory's load at 3 defs, so new
#     defs there would break the landed audit (the
#     cross-round collision caught at the survey).
#   dm/appendixgh.h  the LO/HI band arrays of the
#     Appendix G trap list (46 kinds, d% bands
#     tiling 1-100) -> NEW DIRECTORY
#     content/tables/appendixg/ (def key
#     trap_list; rows name = the enum tag, band =
#     the printed percentile band). trapName and
#     the enum stay in-file (the printed record,
#     the druid-roster ruling).
#   rules/wsg/wsgforage.h  wfgInedBandFor (the 1d8
#     inedible-plant dispatch, 3 bands) and
#     rules/wsg/wsgweathx.h  wwyCycloneDriftFor
#     (the 2d6 cyclone drift, 3 bands) -> NEW
#     DIRECTORY content/tables/wsg/ (def keys
#     wsg_inedible_bands, wsg_cyclone_drift_bands;
#     rows name = the band tag, band = the roll
#     band, gp = the band index).
#
# Seams are header-only (the R1040-R1044 idiom):
# slotsReg()/slotValues() in palrangerspells.h,
# ghReg()/ghView() in dm/appendixgh.h (the aiReg
# pattern), and NEW shared header rules/wsg/
# wsgbands.h (wsgBandReg()/wsgBandRows()) included
# by both wsg headers - one registry, one loader.
# Every accessor signature is unchanged (the
# r125/r184/r463/r494 audits and the engine pin
# them); the clamp semantics stay verbatim,
# including the paladin below-9 / ranger below-8
# zero floors and the ranger kind-column mapping.
# Defensive empty-registry paths fail TERMINAL
# (the R1046 fix-2b lesson: trapFor -> the last
# kind, the wsg bands -> the harmless last band).
#
# DO NOT hand-edit anything this tool writes.
import os
import re
import sys

ROOT = os.getcwd()
PAL = "rules/phb/palrangerspells.h"
GH = "dm/appendixgh.h"
WFG = "rules/wsg/wsgforage.h"
WWY = "rules/wsg/wsgweathx.h"
WSGB = "rules/wsg/wsgbands.h"
FRAG = "rules/audits/r1048_straggler_registry.h"
CENSUS_BEFORE = 1046
CENSUS_AFTER = 1052
SEAM_MARK = "R1048 slots registry seam"


def die(msg):
    sys.stderr.write("r1048_splice: FATAL: %s\n" % msg)
    sys.exit(1)


def replace_once(src, old, new, what):
    n = src.count(old)
    if n != 1:
        die("%s anchor appears %d times (expected 1)"
            % (what, n))
    return src.replace(old, new)


def region_of(src, sig):
    if src.count(sig) != 1:
        die("signature %r appears %d times"
            % (sig, src.count(sig)))
    start = src.index(sig)
    end = src.index("\n}\n", start)
    return start, end + 3


def cq(s):
    if '"' in s or "\\" in s:
        die("tag needs escape support: %r" % s)
    return '"%s"' % s


# ---------------------------------------------------------------------------
# parsing (the pristine headers are the ground truth)
def parse_grid(src, sig, rows, cols):
    d = src.index(sig) + len(sig)
    e = src.index("\n    };", d)
    blk = src[d:e]
    cells = re.findall(r"\{([^{}]*)\}", blk)
    if len(cells) != rows:
        die("%s has %d rows, want %d"
            % (sig, len(cells), rows))
    flat = []
    for i, c in enumerate(cells):
        ints = [int(x) for x in c.split(",")]
        if len(ints) != cols:
            die("%s row %d has %d cells, want %d"
                % (sig, i, len(ints), cols))
        for v in ints:
            if v < 0 or v > 9:
                die("%s value %d out of print range"
                    % (sig, v))
        flat.extend(ints)
    return flat


def parse_trap(src):
    # the enum tags, cross-checked against the lo-hi
    # comments (the R1045 parse discipline)
    s = src.index("enum TrapKind {")
    s = src.index("\n", s) + 1   # skip the opener line
    e = src.index("\n};", s)
    tags = []
    comments = []
    for ln in src[s:e].split("\n"):
        m = re.match(
            r"\s+(TRAP_[A-Z0-9_]+)(?:,\s*)?"
            r"(?://\s*(\d+)(?:-(\d+))?)?", ln)
        if not m:
            if ln.strip():
                die("unparsed TrapKind line %r" % ln)
            continue
        if m.group(1) == "TRAP_KIND_COUNT":
            continue
        tags.append(m.group(1))
        if m.group(2):
            hi = m.group(3) or m.group(2)
            if hi == "00":
                hi = "100"
            comments.append((int(m.group(2)),
                             int(hi)))
        else:
            comments.append(None)
    if len(tags) != 46:
        die("TrapKind has %d tags, want 46" % len(tags))

    # the LO/HI arrays
    lo = parse_int_array(src,
                         "static const int LO["
                         "TRAP_KIND_COUNT] = {", 46)
    hi = parse_int_array(src,
                         "static const int HI["
                         "TRAP_KIND_COUNT] = {", 46)
    if lo[0] != 1 or hi[-1] != 100:
        die("trap bands do not tile 1-100")
    for i in range(46):
        if lo[i] != (1 if i == 0 else hi[i - 1] + 1):
            die("trap band %d lo %d breaks the chain"
                % (i, lo[i]))
        if hi[i] < lo[i]:
            die("trap band %d hi < lo" % i)
        c = comments[i]
        if c is not None and c != (lo[i], hi[i]):
            die("trap band %d comment %s != %s"
                % (i, c, (lo[i], hi[i])))
    return tags, lo, hi


def parse_int_array(src, sig, n):
    d = src.index(sig) + len(sig)
    e = src.index("};", d)   # the arrays close inline
    ints = [int(x) for x in
            re.findall(r"\d+", src[d:e])]
    if len(ints) != n:
        die("%s has %d ints, want %d"
            % (sig, len(ints), n))
    return ints


# ---------------------------------------------------------------------------
# lua emission
LUA_HDR = (
    "-- %s\n"
    "-- The R1048 straggler de-wire. %s\n"
    "-- The accessor and the clamp semantics live in\n"
    "-- the source header and are unchanged.\n"
    "-- DO NOT hand-edit: tools/r1048_splice.py is\n"
    "-- the only writer.\n"
    "\nreturn {\n")


def grid_lua(key, title, row_n, col_n, flat):
    L = []
    L.append(LUA_HDR % (key, title))
    L.append('  key = "%s",\n' % key)
    L.append('  name = "%s (%d x %d)",\n'
             % (title, row_n, col_n))
    L.append("  sources = {\n")
    L.append("    { part = 0, round = 1048 },\n")
    L.append("  },\n")
    L.append("  pins = {\n")
    L.append('    { name = "%sRowCount", value = %d, '
             % (key, row_n))
    L.append('comment = "the class levels" },\n')
    L.append('    { name = "%sColCount", value = %d, '
             % (key, col_n))
    L.append('comment = "the spell levels" },\n')
    L.append("  },\n")
    L.append("  tables = {\n")
    L.append('    { name = "grid", values = {\n')
    line = "      "
    for i, v in enumerate(flat):
        line += "%d, " % v
        if (i + 1) % col_n == 0:
            L.append(line + "\n")
            line = "      "
    if line.strip():
        L.append(line + "\n")
    L.append("    } },\n")
    L.append("  },\n")
    L.append("}\n")
    return "".join(L)


def rows_lua(key, title, rows):
    # rows: (tag, lo, hi, gp)
    L = []
    L.append(LUA_HDR % (key, title))
    L.append('  key = "%s",\n' % key)
    L.append('  name = "%s",\n' % title)
    L.append("  rows = {\n")
    for tag, lo, hi, gp in rows:
        L.append('    { name = "%s", set = "%s", '
                 "band = { %d, %d }, "
                 "xp = 0, xp_hi = 0, gp = %d, "
                 "gp_hi = 0, qty = { 0, 0 } },\n"
                 % (tag, key, lo, hi, gp))
    L.append("  },\n")
    L.append("  sources = {\n")
    L.append("    { part = 0, round = 1048 },\n")
    L.append("  },\n")
    L.append("  pins = {\n")
    L.append('    { name = "%sRowCount", value = %d, '
             % (key, len(rows)))
    L.append('comment = "the printed band count" },\n')
    L.append("  },\n")
    L.append("  tables = {},\n")
    L.append("}\n")
    return "".join(L)


RT_ROW = re.compile(
    r'\{ name = "([^"]+)", set = "([^"]+)", '
    r"band = \{ (\d+), (\d+) \}, "
    r"xp = (\d+), xp_hi = (\d+), gp = (\d+), "
    r"gp_hi = (\d+), qty = \{ (\d+), (\d+) \} \},")


def roundtrip_rows(key, rows, text):
    got = RT_ROW.findall(text)
    if len(got) != len(rows):
        die("%s round-trip: %d rows, want %d"
            % (key, len(got), len(rows)))
    for i, g in enumerate(got):
        tag, lo, hi, gp = rows[i]
        want = (tag, key, str(lo), str(hi),
                "0", "0", str(gp), "0", "0", "0")
        if g != want:
            die("%s round-trip row %d: %s != %s"
                % (key, i, g, want))


def roundtrip_grid(key, flat, text):
    m = re.search(r'values = \{\n(.*?)\n    \} \}',
                  text, re.S)
    if not m:
        die("%s round-trip: no values block" % key)
    got = [int(x) for x in
           re.findall(r"(\d+),?", m.group(1))]
    if got != flat:
        die("%s round-trip: values differ" % key)
    for needle in ("sources = {", "pins = {",
                   "tables = {"):
        if needle not in text:
            die("%s round-trip: missing %s"
                % (key, needle))


# ---------------------------------------------------------------------------
# the seams
PAL_SEAM = (
    "// ---- the R1048 slots registry seam "
    "----------------------------\n"
    "// The paladin and ranger spell-slot grids ride\n"
    "// items::MiscItemRegistry from\n"
    "// content/tables/class_slots/ (def keys\n"
    "// paladin_slots, ranger_slots; tables[1]\n"
    "// \"grid\", values flat row-major - the R1047\n"
    "// grid encoding, but its OWN directory: the\n"
    "// R1047 fragment pins class_grids at 3 defs).\n"
    "// Header-only seam (the R1040-R1044 idiom);\n"
    "// the accessor signatures and clamp semantics\n"
    "// below are unchanged.\n"
    "\n"
    "inline items::MiscItemRegistry& slotsReg() {\n"
    "    static items::MiscItemRegistry reg;\n"
    "    static bool loaded = false;\n"
    "    if (!loaded) {\n"
    "        loaded = true;\n"
    "        reg.loadDirectory("
    "\"content/tables/class_slots\");\n"
    "    }\n"
    "    return reg;\n"
    "}\n"
    "\n"
    "// the per-view cache (the R1032-R1044 idiom)\n"
    "inline const std::vector<long long>&\n"
    "slotValues(const char* name) {\n"
    "    static std::map<std::string,\n"
    "        std::vector<long long>> cache;\n"
    "    auto it = cache.find(name);\n"
    "    if (it == cache.end()) {\n"
    "        std::vector<long long> v;\n"
    "        const items::MiscItemDef* d =\n"
    "            slotsReg().find(name);\n"
    "        if (d && d->tables.size() == 1\n"
    "            && d->tables[0].name == \"grid\")\n"
    "            v = d->tables[0].values;\n"
    "        it = cache.emplace(name, v).first;\n"
    "    }\n"
    "    return it->second;\n"
    "}\n"
    "\n")


GH_SEAM = (
    "// ---- the R1048 trap-list registry seam "
    "---------------------------\n"
    "// The Appendix G trap-list d% bands ride\n"
    "// items::MiscItemRegistry from\n"
    "// content/tables/appendixg/ (def key\n"
    "// trap_list; rows name = the enum tag,\n"
    "// band = the printed percentile band, the\n"
    "// 00 band stored as 100). Header-only seam\n"
    "// (the R1045 aiReg idiom); every accessor\n"
    "// signature below is unchanged (the r125\n"
    "// audit and state_dungeon pin them); the\n"
    "// band chain is battery-pinned (1..100,\n"
    "// contiguous, last band 100). The NAMES\n"
    "// array stays in-file as the printed record.\n"
    "\n"
    "inline items::MiscItemRegistry& ghReg() {\n"
    "    static items::MiscItemRegistry reg;\n"
    "    static bool loaded = false;\n"
    "    if (!loaded) {\n"
    "        loaded = true;\n"
    "        reg.loadDirectory("
    "\"content/tables/appendixg\");\n"
    "    }\n"
    "    return reg;\n"
    "}\n"
    "\n"
    "inline const std::vector<items::MiscItemRow>&\n"
    "ghView(const char* name) {\n"
    "    static std::map<std::string,\n"
    "        std::vector<items::MiscItemRow>> cache;\n"
    "    auto it = cache.find(name);\n"
    "    if (it == cache.end()) {\n"
    "        const items::MiscItemDef* d =\n"
    "            ghReg().find(name);\n"
    "        it = cache.emplace(\n"
    "            name, d ? d->rows\n"
    "                   : std::vector<"
    "items::MiscItemRow>()).first;\n"
    "    }\n"
    "    return it->second;\n"
    "}\n"
    "\n")


WSGB_SEAM = (
    "// ============================================================================\n"
    "// Adnd1 - rules/wsg/wsgbands.h\n"
    "// The R1048 WSG band-table seam: the small\n"
    "// printed roll-band dispatches (wsgforage.h\n"
    "// wfgInedBandFor, wsgweathx.h\n"
    "// wwyCycloneDriftFor) ride\n"
    "// items::MiscItemRegistry from\n"
    "// content/tables/wsg/ (def keys\n"
    "// wsg_inedible_bands, wsg_cyclone_drift_bands;\n"
    "// rows name = the band tag, band = the roll\n"
    "// band, gp = the band index). One registry,\n"
    "// one loader, shared by both headers (the\n"
    "// R1032-R1044 header-only idiom; every\n"
    "// accessor signature is unchanged - the\n"
    "// r463/r494 audits pin them).\n"
    "// ============================================================================\n"
    "\n"
    "#pragma once\n"
    "\n"
    '#include "items/MiscItemRegistry.h"\n'
    "\n"
    "namespace rules {\n"
    "\n"
    "inline items::MiscItemRegistry& wsgBandReg() {\n"
    "    static items::MiscItemRegistry reg;\n"
    "    static bool loaded = false;\n"
    "    if (!loaded) {\n"
    "        loaded = true;\n"
    "        reg.loadDirectory("
    "\"content/tables/wsg\");\n"
    "    }\n"
    "    return reg;\n"
    "}\n"
    "\n"
    "inline const std::vector<items::MiscItemRow>&\n"
    "wsgBandRows(const char* name) {\n"
    "    static std::map<std::string,\n"
    "        std::vector<items::MiscItemRow>> cache;\n"
    "    auto it = cache.find(name);\n"
    "    if (it == cache.end()) {\n"
    "        const items::MiscItemDef* d =\n"
    "            wsgBandReg().find(name);\n"
    "        it = cache.emplace(\n"
    "            name, d ? d->rows\n"
    "                   : std::vector<"
    "items::MiscItemRow>()).first;\n"
    "    }\n"
    "    return it->second;\n"
    "}\n"
    "\n"
    "}  // namespace rules\n")


def rewrite_pal(src, pal_grid, ran_grid):
    # include + seam (after the standing includes)
    src = replace_once(
        src,
        '#include "../engine/classes.h"\n'
        "\n#include <cstdint>\n#include <string>\n",
        '#include "../engine/classes.h"\n'
        "\n#include <cstdint>\n#include <string>\n"
        "\n"
        '#include "items/MiscItemRegistry.h"   '
        "// R1048: the slot grids ride the registry\n"
        "\n" + PAL_SEAM,
        "pal include + seam")

    # paladin accessor
    sig = ("inline int paladinSpellSlots("
           "int paladinLevel,\n"
           "                        int spellLevel) {")
    s, e = region_of(src, sig)
    body = (
        "    if (paladinLevel < 9) return 0;\n"
        "    if (paladinLevel > 20) paladinLevel = 20;\n"
        "    if (spellLevel < 1) spellLevel = 1;\n"
        "    if (spellLevel > 4) spellLevel = 4;\n"
        "    const auto& v = slotValues("
        "\"paladin_slots\");\n"
        "    if (v.empty()) return 0;   "
        "// defensive: unloaded view\n"
        "    return (int)v[(paladinLevel - 9) * 4\n"
        "                 + (spellLevel - 1)];\n")
    src = src[:s] + sig + "\n" + body + "}\n" + src[e:]

    # ranger accessor (the kind-column mapping stays
    # verbatim)
    sig2 = ("inline int rangerSpellSlots("
            "int rangerLevel, int kind,\n"
            "                       int spellLevel) {")
    s, e = region_of(src, sig2)
    body2 = (
        "    if (rangerLevel < 8) return 0;\n"
        "    if (rangerLevel > 17) rangerLevel = 17;\n"
        "    int col;\n"
        "    if (kind == 0) {\n"
        "        if (spellLevel < 1) spellLevel = 1;\n"
        "        if (spellLevel > 3) spellLevel = 3;\n"
        "        col = spellLevel;\n"
        "    } else {\n"
        "        if (spellLevel < 1) spellLevel = 1;\n"
        "        if (spellLevel > 2) spellLevel = 2;\n"
        "        col = spellLevel + 3;\n"
        "    }\n"
        "    const auto& v = slotValues("
        "\"ranger_slots\");\n"
        "    if (v.empty()) return 0;   "
        "// defensive: unloaded view\n"
        "    return (int)v[(rangerLevel - 8) * 5\n"
        "                 + (col - 1)];\n")
    src = src[:s] + sig2 + "\n" + body2 + "}\n" + src[e:]

    for tok in ("kSlots[12][4]", "kSlots[10][5]"):
        if tok in src:
            die("retired token survived in "
                "palrangerspells.h: %s" % tok)
    return src


def rewrite_gh(src, tags, lo, hi):
    src = replace_once(
        src,
        "#pragma once\n\n#include <string>\n",
        "#pragma once\n\n#include <string>\n\n"
        '#include "items/MiscItemRegistry.h"   '
        "// R1048: the trap bands ride the registry\n"
        "\n" + GH_SEAM,
        "gh include + seam")

    sig = "inline int trapBandLo(int kind) {"
    s, e = region_of(src, sig)
    body = (
        "    const auto& rows = ghView(\"trap_list\");\n"
        "    if (kind < 0 || kind >= (int)rows.size())\n"
        "        return 0;   // defensive: unloaded "
        "view\n"
        "    return rows[kind].bandLo;\n")
    src = src[:s] + sig + "\n" + body + "}\n" + src[e:]

    sig2 = "inline int trapBandHi(int kind) {"
    s, e = region_of(src, sig2)
    body2 = (
        "    const auto& rows = ghView(\"trap_list\");\n"
        "    if (kind < 0 || kind >= (int)rows.size())\n"
        "        return 0;   // defensive: unloaded "
        "view\n"
        "    return rows[kind].bandHi;\n")
    src = src[:s] + sig2 + "\n" + body2 + "}\n" \
        + src[e:]

    sig3 = ("inline int trapFor(int r) {")
    s, e = region_of(src, sig3)
    body3 = (
        "    if (r < 1) r = 1;\n"
        "    if (r > 100) r = 100;\n"
        "    const auto& rows = ghView(\"trap_list\");\n"
        "    if (rows.empty())   "
        "// defensive: unload - TERMINAL\n"
        "        return TRAP_KIND_COUNT - 1;\n"
        "    for (int k = 0; k < (int)rows.size(); "
        "++k)\n"
        "        if (r <= rows[k].bandHi) return k;\n"
        "    return (int)rows.size() - 1;\n")
    src = src[:s] + sig3 + "\n" + body3 + "}\n" \
        + src[e:]

    for tok in ("static const int LO[TRAP_KIND_COUNT]",
                "static const int HI[TRAP_KIND_COUNT]"):
        if tok in src:
            die("retired token survived in "
                "appendixgh.h: %s" % tok)
    return src


WFG_OLD = (
    "inline int wfgInedBandFor(int r)\n"
    "    {\n"
    "        if (r <= 1) return 0;\n"
    "        if (r <= 4) return 1;\n"
    "        return 2;\n"
    "    }")
WFG_NEW = (
    "inline int wfgInedBandFor(int r)\n"
    "    {\n"
    "        const auto& rows =\n"
    "            wsgBandRows(\"wsg_inedible_bands\");\n"
    "        if (rows.empty()) return 2;   "
    "// defensive: TERMINAL\n"
    "        for (int i = 0; i < (int)rows.size(); "
    "++i)\n"
    "            if (r <= rows[i].bandHi) return i;\n"
    "        return (int)rows.size() - 1;\n"
    "    }")

WWY_OLD = (
    "inline int wwyCycloneDriftFor(int roll)\n"
    "    {\n"
    "        if (roll <= 6) return 0;\n"
    "        if (roll <= 7) return 1;\n"
    "        return 2;\n"
    "    }")
WWY_NEW = (
    "inline int wwyCycloneDriftFor(int roll)\n"
    "    {\n"
    "        const auto& rows =\n"
    "            wsgBandRows("
    "\"wsg_cyclone_drift_bands\");\n"
    "        if (rows.empty()) return 2;   "
    "// defensive: TERMINAL\n"
    "        for (int i = 0; i < (int)rows.size(); "
    "++i)\n"
    "            if (roll <= rows[i].bandHi)\n"
    "                return i;\n"
    "        return (int)rows.size() - 1;\n"
    "    }")


def rewrite_wsg(wfg, wwy):
    wfg = replace_once(wfg, WFG_OLD, WFG_NEW,
                       "wfg cascade")
    wwy = replace_once(wwy, WWY_OLD, WWY_NEW,
                       "wwy cascade")
    return wfg, wwy


def add_wsgb_include(src, what):
    # the wsg headers carry no include guards; the
    # unique namespace opener is the anchor
    anchor = "namespace rules {\n"
    return replace_once(
        src, anchor,
        '#include "wsgbands.h"   // R1048: the WSG '
        "band tables ride the registry\n"
        "\n" + anchor,
        what + " wsgbands include")


# ---------------------------------------------------------------------------
# the fragment (every pin computed from the parsed
# source; all engine calls qualified - the R1044
# fragment-scope lesson)
def build_fragment(pal, ran, tags, lo, hi):
    L = []
    a = L.append
    a("    // ==== R1048: straggler registry "
      "=================================\n")
    a("    // The R1048 de-wire: the four stragglers\n")
    a("    // (paladin 12 x 4 and ranger 10 x 5 slot\n")
    a("    // grids, the Appendix G trap list 46 d%\n")
    a("    // bands, the WSG inedible 1d8 and cyclone\n")
    a("    // drift 2d6 dispatches) ride\n")
    a("    // items::MiscItemRegistry from\n")
    a("    // content/tables/{class_slots,appendixg,\n")
    a("    // wsg}/. This audit loads its own\n")
    a("    // registry instances and cross-reads every\n")
    a("    // cell and band through the inline accessor\n")
    a("    // surface, so the r125/r184/r463/r494\n")
    a("    // audits and this registry audit read the\n")
    a("    // same data through the same signatures.\n")
    a("    {\n")
    a("        int bad = 0;\n")
    # 1. load
    a("        // -- 1. load "
      "---------------------------------------\n")
    a("        {\n")
    for var, d, n in (
            ("ts", "class_slots", 2),
            ("tg", "appendixg", 1),
            ("tw", "wsg", 2)):
        a("            items::MiscItemRegistry %s;\n"
          % var)
        a('            if (%s.loadDirectory('
          '"content/tables/%s")\n' % (var, d))
        a("                    != %d) ++bad;\n" % n)
        a("            if (!%s.errors().empty()) "
          "++bad;\n" % var)
        a("            if ((int)%s.all().size() != %d)"
          " ++bad;\n" % (var, n))
    for k in ("paladin_slots", "ranger_slots"):
        a('            if (!ts.all().count("%s")) '
          "++bad;\n" % k)
    a('            if (!tg.all().count("trap_list"))'
      " ++bad;\n")
    for k in ("wsg_inedible_bands",
              "wsg_cyclone_drift_bands"):
        a('            if (!tw.all().count("%s")) '
          "++bad;\n" % k)
    # negatives: keys absent from each registry
    a('            if (ts.all().count("paladin_slot"))'
      "\n")
    a("                ++bad;   // singular\n")
    a('            if (ts.all().count('
      '"bard_druid_slots"))\n')
    a("                ++bad;   // cross-family\n")
    a('            if (tg.all().count("traplist")) '
      "++bad;\n")
    a('            if (tg.all().count("appendixa_'
      'turn")) ++bad;\n')
    a('            if (tw.all().count("wsg_cyclone"))'
      " ++bad;\n")
    a('            if (ts.all().count("")) ++bad;\n')
    a('            if (tg.all().count("")) ++bad;\n')
    a('            if (tw.all().count("")) ++bad;\n')
    a("        }\n")
    a('        printf("R1048 straggler registry load '
      'audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # 2. counts
    a("        // -- 2. counts "
      "-------------------------------------\n")
    a("        {\n")
    a("            items::MiscItemRegistry ts;\n")
    a('            ts.loadDirectory('
      '"content/tables/class_slots");\n')
    a("            items::MiscItemRegistry tg;\n")
    a('            tg.loadDirectory('
      '"content/tables/appendixg");\n')
    a("            items::MiscItemRegistry tw;\n")
    a('            tw.loadDirectory('
      '"content/tables/wsg");\n')
    for var, key, rn, cn in (
            ("ts", "paladin_slots", 12, 4),
            ("ts", "ranger_slots", 10, 5)):
        a("            {\n")
        a('            const auto* v = %s.find('
          '"%s");\n' % (var, key))
        a("            if (!v) { ++bad; } else {\n")
        a("                if ((int)v->rows.size() "
          "!= 0\n")
        a("                    || (int)v->sources.size()"
          " != 1\n")
        a("                    || (int)v->pins.size() "
          "!= 2\n")
        a("                    || v->pins[0].value != "
          "%d\n" % rn)
        a("                    || v->pins[1].value != "
          "%d\n" % cn)
        a("                    || (int)v->tables.size()"
          " != 1\n")
        a("                    || v->tables[0].name !=\n")
        a('                        std::string('
          '"grid")\n')
        a("                    || (int)v->tables[0]"
          ".values.size()\n")
        a("                       != %d) ++bad;\n"
          % (rn * cn))
        a("            }\n")
        a("            }\n")
    a('            const auto* vt = tg.find('
      '"trap_list");\n')
    a("            if (!vt) { ++bad; } else {\n")
    a("                if ((int)vt->rows.size() != 46\n")
    a("                    || (int)vt->sources.size() "
      "!= 1\n")
    a("                    || (int)vt->pins.size() != 1\n")
    a("                    || (int)vt->tables.size() "
      "!= 0\n")
    a('                    || vt->pins[0].name != '
      'std::string(\n')
    a('                        "trap_listRowCount")\n')
    a("                    || vt->pins[0].value != 46)\n")
    a("                    ++bad;\n")
    a("            }\n")
    for key in ("wsg_inedible_bands",
                "wsg_cyclone_drift_bands"):
        a("            {\n")
        a('            const auto* vw = tw.find("%s");'
          "\n" % key)
        a("            if (!vw) { ++bad; } else {\n")
        a("                if ((int)vw->rows.size() != 3\n")
        a("                    || (int)vw->sources.size()"
          " != 1\n")
        a("                    || (int)vw->pins.size() != "
          "1\n")
        a("                    || (int)vw->tables.size() "
          "!= 0\n")
        a("                    || vw->pins[0].value != 3)"
          "\n")
        a("                    ++bad;\n")
        a("            }\n")
        a("            }\n")
    a("        }\n")
    a('        printf("R1048 straggler registry counts '
      'audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # 3. bands (the axis shapes)
    a("        // -- 3. bands (the roll axes) "
      "--------------\n")
    a("        {\n")
    a("            items::MiscItemRegistry tg;\n")
    a('            tg.loadDirectory('
      '"content/tables/appendixg");\n')
    a("            items::MiscItemRegistry tw;\n")
    a('            tw.loadDirectory('
      '"content/tables/wsg");\n')
    a('            const auto* vt = tg.find('
      '"trap_list");\n')
    a("            if (!vt) { ++bad; } else {\n")
    a("                int prevHi = 0;\n")
    a("                for (const auto& r : "
      "vt->rows) {\n")
    a("                    if (r.bandLo != prevHi + 1\n")
    a("                        || r.bandHi < r.bandLo\n")
    a("                        || r.bandHi > 100\n")
    a("                        || r.set != vt->key\n")
    a("                        || r.name.empty()\n")
    a("                        || r.gp != 0\n")
    a("                        || r.gpHi != 0\n")
    a("                        || r.xp != 0\n")
    a("                        || r.xpHi != 0\n")
    a("                        || r.qtyLo != 0\n")
    a("                        || r.qtyHi != 0) ++bad;\n")
    a("                    prevHi = r.bandHi;\n")
    a("                }\n")
    a("                if (prevHi != 100) ++bad;\n")
    a("            }\n")
    for key in ("wsg_inedible_bands",
                "wsg_cyclone_drift_bands"):
        a("            {\n")
        a('            const auto* vw = tw.find("%s");'
          "\n" % key)
        a("            if (!vw) { ++bad; } else {\n")
        a("                int prevHi = 0;\n")
        a("                for (int i = 0;\n")
        a("                     i < (int)vw->rows.size();"
          " ++i) {\n")
        a("                    const auto& r = "
          "vw->rows[i];\n")
        a("                    if (r.bandLo != prevHi + 1\n")
        a("                        || r.set != vw->key\n")
        a("                        || r.name.empty()\n")
        a("                        || r.gp != i) ++bad;\n")
        a("                    prevHi = r.bandHi;\n")
        a("                }\n")
        a("            }\n")
        a("            }\n")
    a("        }\n")
    a('        printf("R1048 straggler registry bands '
      'audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # 4. data (famous pins, all computed)
    a("        // -- 4. data (famous pins, all "
      "computed) --\n")
    a("        {\n")
    # trap bands and rolls
    a("            if (dm::appendixg::trapBandLo(0) "
      "!= %d\n" % lo[0])
    a("                || dm::appendixg::"
      "trapBandHi(0) != %d) ++bad;\n" % hi[0])
    a("            if (dm::appendixg::trapBandLo(28) "
      "!= %d\n" % lo[28])
    a("                || dm::appendixg::"
      "trapBandHi(28) != %d) ++bad;\n" % hi[28])
    a("            if (dm::appendixg::trapBandLo(45) "
      "!= %d\n" % lo[45])
    a("                || dm::appendixg::"
      "trapBandHi(45) != 100) ++bad;\n")
    a("            if (dm::appendixg::trapFor(1) != 0\n")
    a("                || dm::appendixg::trapFor(%d) "
      "!= 0) ++bad;\n" % hi[0])
    a("            if (dm::appendixg::trapFor(100) != "
      "45\n")
    a("                || dm::appendixg::"
      "trapFor(%d) != 45) ++bad;\n" % lo[45])
    # the paladin/ranger slot pins
    for lv, sl, want in ((9, 1, pal[0]),
                         (20, 4, pal[47]),
                         (15, 2, pal[25])):
        a("            if (rules::paladinSpellSlots("
          "%d, %d) != %d)\n" % (lv, sl, want))
        a("                ++bad;\n")
    for lv, kind, sl, want in (
            (8, 0, 1, ran[0]), (17, 1, 2, ran[49]),
            (10, 1, 1, ran[13])):
        a("            if (rules::rangerSpellSlots("
          "%d, %d, %d) != %d)\n"
          % (lv, kind, sl, want))
        a("                ++bad;\n")
    # the wsg dispatch pins
    for r, want in ((1, 0), (2, 1), (4, 1), (5, 2),
                    (8, 2)):
        a("            if (rules::wfgInedBandFor(%d) "
          "!= %d) ++bad;\n" % (r, want))
    for r, want in ((2, 0), (6, 0), (7, 1),
                    (8, 2), (12, 2)):
        a("            if (rules::wwyCycloneDriftFor("
          "%d) != %d)\n" % (r, want))
        a("                ++bad;\n")
    a("        }\n")
    a('        printf("R1048 straggler registry data '
      'audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # 5. rows (the full cross-read)
    a("        // -- 5. rows (the full cross-read) "
      "--------\n")
    a("        {\n")
    a("            items::MiscItemRegistry ts;\n")
    a('            ts.loadDirectory('
      '"content/tables/class_slots");\n')
    a("            items::MiscItemRegistry tg;\n")
    a('            tg.loadDirectory('
      '"content/tables/appendixg");\n')
    a("            items::MiscItemRegistry tw;\n")
    a('            tw.loadDirectory('
      '"content/tables/wsg");\n')
    # paladin
    a('            const auto* vp = ts.find('
      '"paladin_slots");\n')
    a("            if (!vp) { ++bad; } else {\n")
    a("                const auto& g = "
      "vp->tables[0].values;\n")
    a("                for (int lv = 9; lv <= 20; "
      "++lv)\n")
    a("                    for (int sl = 1; sl <= 4; "
      "++sl)\n")
    a("                        if (rules::"
      "paladinSpellSlots(lv, sl)\n")
    a("                                != (int)g["
      "(lv - 9) * 4\n")
    a("                                    + "
      "(sl - 1)]) ++bad;\n")
    a("            }\n")
    # ranger (the flat index walked; the col mapping
    # derived per index - never recalled)
    a('            const auto* vr = ts.find('
      '"ranger_slots");\n')
    a("            if (!vr) { ++bad; } else {\n")
    a("                const auto& g = "
      "vr->tables[0].values;\n")
    a("                for (int lv = 8; lv <= 17; "
      "++lv)\n")
    a("                    for (int col = 1; col <= 5; "
      "++col) {\n")
    a("                        int kind = (col <= 3) ? "
      "0 : 1;\n")
    a("                        int sl = (col <= 3)\n")
    a("                            ? col : col - 3;\n")
    a("                        if (rules::"
      "rangerSpellSlots(lv, kind, sl)\n")
    a("                                != (int)g["
      "(lv - 8) * 5\n")
    a("                                    + "
      "(col - 1)]) ++bad;\n")
    a("                    }\n")
    a("            }\n")
    # trap: every roll 1..100 through trapFor vs the
    # band scan on the registry rows
    a('            const auto* vt = tg.find('
      '"trap_list");\n')
    a("            if (!vt) { ++bad; } else {\n")
    a("                for (int r = 1; r <= 100; "
      "++r) {\n")
    a("                    int want = 0;\n")
    a("                    for (int i = 0;\n")
    a("                         i < (int)vt->rows."
                      "size(); ++i) {\n")
    a("                        if (r <= vt->rows[i]."
                      "bandHi) {\n")
    a("                            want = i;\n")
    a("                            break;\n")
    a("                        }\n")
    a("                    }\n")
    a("                    if (dm::appendixg::"
      "trapFor(r) != want) ++bad;\n")
    a("                }\n")
    a("            }\n")
    # wsg: every roll through the accessors vs the
    # band scan
    for key, acc, rmax in (
            ("wsg_inedible_bands",
             "rules::wfgInedBandFor", 9),
            ("wsg_cyclone_drift_bands",
             "rules::wwyCycloneDriftFor", 13)):
        a("            {\n")
        a('            const auto* vw = tw.find("%s");'
          "\n" % key)
        a("            if (!vw) { ++bad; } else {\n")
        a("                for (int r = 0; r <= %d; "
          "++r) {\n" % rmax)
        a("                    int want =\n")
        a("                        (int)vw->rows."
          "size() - 1;\n")
        a("                    for (int i = 0;\n")
        a("                         i < (int)vw->rows."
                          "size(); ++i) {\n")
        a("                        if (r <= vw->rows[i]."
                          "bandHi) {\n")
        a("                            want = i;\n")
        a("                            break;\n")
        a("                        }\n")
        a("                    }\n")
        a("                    if (%s(r) != want) "
          "++bad;\n" % acc)
        a("                }\n")
        a("            }\n")
        a("            }\n")
    a("        }\n")
    a('        printf("R1048 straggler registry rows '
      'audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # 6. edges
    a("        // -- 6. edges (clamps, negatives) "
      "----------\n")
    a("        {\n")
    a("            if (rules::paladinSpellSlots(8, 1)"
      " != 0\n")
    a("                || rules::"
      "paladinSpellSlots(1, 1) != 0)\n")
    a("                ++bad;\n")
    a("            if (rules::paladinSpellSlots(21, 1)"
      "\n")
    a("                    != rules::"
      "paladinSpellSlots(20, 1))\n")
    a("                ++bad;\n")
    a("            if (rules::paladinSpellSlots(9, 0)\n")
    a("                    != rules::"
      "paladinSpellSlots(9, 1)\n")
    a("                || rules::"
      "paladinSpellSlots(9, 5)\n")
    a("                   != rules::"
      "paladinSpellSlots(9, 4))\n")
    a("                ++bad;\n")
    a("            if (rules::rangerSpellSlots(7, 0, 1)"
      " != 0)\n")
    a("                ++bad;\n")
    a("            if (rules::rangerSpellSlots(18, 0, 3)"
      "\n")
    a("                    != rules::"
      "rangerSpellSlots(17, 0, 3))\n")
    a("                ++bad;\n")
    a("            if (rules::rangerSpellSlots(10, 1, 3)"
      "\n")
    a("                    != rules::"
      "rangerSpellSlots(10, 1, 2))\n")
    a("                ++bad;\n")
    a("            if (dm::appendixg::trapFor(0) != 0\n")
    a("                || dm::appendixg::"
      "trapFor(101) != 45\n")
    a("                || dm::appendixg::"
      "trapFor(999) != 45)\n")
    a("                ++bad;\n")
    a("            if (dm::appendixg::trapBandLo(-1) "
      "!= 0\n")
    a("                || dm::appendixg::"
      "trapBandLo(99) != 0\n")
    a("                || dm::appendixg::"
      "trapBandHi(-1) != 0\n")
    a("                || dm::appendixg::"
      "trapBandHi(99) != 0)\n")
    a("                ++bad;\n")
    a("            if (std::string("
      "dm::appendixg::trapName(-1))\n")
    a('                    != std::string("unknown")) '
      "++bad;\n")
    a("            if (rules::wfgInedBandFor(0) != 0\n")
    a("                || rules::"
      "wfgInedBandFor(99) != 2) ++bad;\n")
    a("            if (rules::"
      "wwyCycloneDriftFor(1) != 0\n")
    a("                || rules::"
      "wwyCycloneDriftFor(13) != 2\n")
    a("                || rules::"
      "wwyCycloneDriftFor(99) != 2)\n")
    a("                ++bad;\n")
    a('            if (!slotValues('
      '"no_such").empty())\n')
    a("                ++bad;\n")
    a('            if (!ghView('
      '"no_such").empty())\n')
    a("                ++bad;\n")
    a('            if (!rules::wsgBandRows('
      '"no_such").empty())\n')
    a("                ++bad;\n")
    a('            if (slotsReg().find('
      '"bard_druid_slots")\n')
    a("                    != nullptr) ++bad;\n")
    a('            if (ghReg().find('
      '"traplist")\n')
    a("                    != nullptr) ++bad;\n")
    a('            if (rules::wsgBandReg().find('
      '"wsg_cyclone")\n')
    a("                    != nullptr) ++bad;\n")
    a('            if (slotsReg().find("") != '
      'nullptr)\n')
    a("                ++bad;\n")
    a("        }\n")
    a('        printf("R1048 straggler registry edges '
      'audit: bad %d\\n", bad);\n')
    a("    }\n")
    return "".join(L)


# static header checks (the R392/R1045/R1047 lessons:
# quotes, braces, PARENS, hyphens, empty names)
def static_checks(name, text):
    for ln in text.split("\n"):
        stripped = re.sub(r"\\.", "", ln)
        if stripped.count('"') % 2 != 0:
            die("%s: unbalanced quotes: %r" % (name, ln))
    depth = 0
    for ch in text:
        if ch == "{":
            depth += 1
        elif ch == "}":
            depth -= 1
    if depth != 0:
        die("%s: brace balance %d" % (name, depth))
    code = re.sub(r'"[^"\n]*"', '""', text)
    code = re.sub(r"//[^\n]*", "", code)
    if code.count("(") != code.count(")"):
        die("%s: paren balance %d vs %d"
            % (name, code.count("("), code.count(")")))
    for m in re.finditer(r"\b[A-Za-z0-9_]+"
                         r"(-[A-Za-z0-9_]+)+\b", code):
        die("%s: hyphen token in code: %r"
            % (name, m.group(0)))
    for m in re.finditer(r"::\s*\(", code):
        die("%s: qualified call with no name at %r"
            % (name, m.group(0)))


def census():
    total = 0
    for root, _dirs, files in os.walk("rules"):
        if "audits" not in root:
            continue
        for f in files:
            if f.endswith(".h"):
                total += open(os.path.join(root, f)).read(
                ).count("audit: bad %d")
    total += open("regtest.cpp").read().count(
        "audit: bad %d")
    return total


def main():
    if not os.path.exists(PAL):
        die("run from the repo root (%s missing)" % PAL)

    marker = os.path.join("content/tables/class_slots",
                          "paladin_slots.lua")
    already = (os.path.exists(marker)
               and SEAM_MARK in open(PAL).read())
    if already:
        print("applied 0, already 1")
        print("SPLICE OK")
        return

    c = census()
    if c != CENSUS_BEFORE:
        die("census %d, expected %d" % (c, CENSUS_BEFORE))

    pal_src = open(PAL).read()
    gh_src = open(GH).read()
    wfg_src = open(WFG).read()
    wwy_src = open(WWY).read()

    pal_grid = parse_grid(pal_src,
                          "kSlots[12][4] = {", 12, 4)
    ran_grid = parse_grid(pal_src,
                          "kSlots[10][5] = {", 10, 5)
    tags, lo, hi = parse_trap(gh_src)
    print("parsed: paladin 12x4, ranger 10x5, "
          "trap list 46 bands, 2 wsg dispatches")

    # the wsg dispatch bodies must match verbatim
    for what, body in (("wfgInedBandFor", WFG_OLD),
                       ("wwyCycloneDriftFor", WWY_OLD)):
        hay = (wfg_src if "wfg" in what
               else wwy_src)
        if hay.count(body) != 1:
            die("%s cascade body appears %d times"
                % (what, hay.count(body)))

    # 5 lua files, 3 new directories
    os.makedirs("content/tables/class_slots",
                exist_ok=True)
    os.makedirs("content/tables/appendixg",
                exist_ok=True)
    os.makedirs("content/tables/wsg", exist_ok=True)
    files = {
        "content/tables/class_slots/paladin_slots.lua":
            grid_lua("paladin_slots",
                     "The paladin clerical spell slots",
                     12, 4, pal_grid),
        "content/tables/class_slots/ranger_slots.lua":
            grid_lua("ranger_slots",
                     "The ranger spell slots",
                     10, 5, ran_grid),
        "content/tables/appendixg/trap_list.lua":
            rows_lua("trap_list",
                     "The Appendix G trap list d% bands "
                     "(46 rows)",
                     [(tags[i], lo[i], hi[i], 0)
                      for i in range(46)]),
        "content/tables/wsg/wsg_inedible_bands.lua":
            rows_lua("wsg_inedible_bands",
                     "The WSG inedible-plant dispatch "
                     "(1d8, 3 bands)",
                     [("INED_POISONOUS", 1, 1, 0),
                      ("INED_TAINTED", 2, 4, 1),
                      ("INED_NO_FOOD_VALUE", 5, 8, 2)]),
        "content/tables/wsg/"
        "wsg_cyclone_drift_bands.lua":
            rows_lua("wsg_cyclone_drift_bands",
                     "The WSG cyclone drift dispatch "
                     "(2d6, 3 bands)",
                     [("DRIFT_COOLER", 1, 6, 0),
                      ("DRIFT_HOLD", 7, 7, 1),
                      ("DRIFT_WARMER", 8, 12, 2)]),
    }
    for name, text in files.items():
        open(name, "w").write(text)
    roundtrip_grid("paladin_slots", pal_grid,
                   files["content/tables/class_slots/"
                         "paladin_slots.lua"])
    roundtrip_grid("ranger_slots", ran_grid,
                   files["content/tables/class_slots/"
                         "ranger_slots.lua"])
    roundtrip_rows("trap_list",
                   [(tags[i], lo[i], hi[i], 0)
                    for i in range(46)],
                   files["content/tables/appendixg/"
                         "trap_list.lua"])
    roundtrip_rows("wsg_inedible_bands",
                   [("INED_POISONOUS", 1, 1, 0),
                    ("INED_TAINTED", 2, 4, 1),
                    ("INED_NO_FOOD_VALUE", 5, 8, 2)],
                   files["content/tables/wsg/"
                         "wsg_inedible_bands.lua"])
    roundtrip_rows("wsg_cyclone_drift_bands",
                   [("DRIFT_COOLER", 1, 6, 0),
                    ("DRIFT_HOLD", 7, 7, 1),
                    ("DRIFT_WARMER", 8, 12, 2)],
                   files["content/tables/wsg/"
                         "wsg_cyclone_drift_bands.lua"])
    print("round-trip: 5 lua files parse back exact")

    new_pal = rewrite_pal(pal_src, pal_grid, ran_grid)
    static_checks(PAL, new_pal)
    open(PAL, "w").write(new_pal)

    new_gh = rewrite_gh(gh_src, tags, lo, hi)
    static_checks(GH, new_gh)
    open(GH, "w").write(new_gh)

    wfg_src, wwy_src = rewrite_wsg(wfg_src, wwy_src)
    wfg_src = add_wsgb_include(wfg_src, "wsgforage")
    wwy_src = add_wsgb_include(wwy_src, "wsgweathx")
    static_checks(WFG, wfg_src)
    static_checks(WWY, wwy_src)
    open(WFG, "w").write(wfg_src)
    open(WWY, "w").write(wwy_src)

    static_checks("the wsgbands seam",
                  WSGB_SEAM)
    open(WSGB, "w").write(WSGB_SEAM)

    frag = build_fragment(pal_grid, ran_grid,
                          tags, lo, hi)
    static_checks("the fragment", frag)
    open(FRAG, "w").write(frag)

    reg = open("regtest.cpp").read()
    anchor = ('    #include "rules/audits/'
              'r1047_class_grid_registry.h"  // R1047\n')
    reg = replace_once(
        reg, anchor,
        anchor +
        '    #include "rules/audits/'
        'r1048_straggler_registry.h"  // R1048\n',
        "regtest include")
    open("regtest.cpp", "w").write(reg)

    c = census()
    print("census: %d -> %d audit printf patterns"
          % (CENSUS_BEFORE, CENSUS_AFTER))
    if c != CENSUS_AFTER:
        die("census %d, expected %d" % (c, CENSUS_AFTER))

    print("applied 1, rewrote 5 tracked files, "
          "wrote 7 new files")
    print("SPLICE OK")


main()
