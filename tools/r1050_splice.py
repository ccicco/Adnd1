#!/usr/bin/env python3
# tools/r1050_splice.py - the R1050
# dm/outdoormove.h de-wire.
#
# WHAT RETIRES: the five movement grids
# (footMilesPerDay k[3][3],
# mountedMilesPerDay k[6][3],
# oaredMilesPerDay k[8][5],
# sailedMilesLo k[8][5],
# sailedMilesHi k[8][5]) into
# content/tables/dm_movement/ (5 defs:
# dm_move_foot, dm_move_mounted,
# dm_move_oared, dm_move_sail_lo,
# dm_move_sail_hi).
#
# THE SEAM (namespace dm):
#   dmMoveReg()     the registry
#                   (loadDirectory once)
#   dmMoveGrid(tag) first-use flat
#                   int* grid cache
# The five accessor signatures, the
# enums and the pure functions
# (terrainClass, footBurdenFor,
# directionLimitFor, lostChanceIn10,
# lostAngleDeg) stay.
#
# THE FRAGMENT sits at the R1041+
# in-function seat (regtest.cpp:1299,
# after R1049's 1298): brace-scoped
# BLOCK, six printf sections, census
# 1058 -> 1064. R1048 idiom: no
# pragma/includes/namespace/function,
# no std::map/set/sort at the seat
# (only cstdio/cstring/string), dm::
# qualification on every dm-scope
# token, items:: on the registry.
#
# HARD LESSONS APPLIED (the R1049
# ledger, classes 3-10): every want
# is computed from the SAME parse that
# writes the lua; every dim, stride,
# param name and probe index comes off
# the parse (never hardcoded); the tool
# SELF-SCANS its own emitted fragment
# against the parsed mirrors before
# writing anything; the wrapper refuses
# to split a line carrying a string
# literal (fused tokens and broken
# strings are impossible by
# construction).
#
# Pins computed from parsed source,
# never recalled (R1035). Loader
# schema is a hard contract: sources/
# pins/tables in every def; rows are
# OPTIONAL at top level and these
# defs are rowless (the R1047
# class_grids grid shape).

import os
import re
import sys

ROOT = os.getcwd()
HEAD = "dm/outdoormove.h"
LUA_DIR = "content/tables/dm_movement"
FRAG = ("rules/audits/"
        "r1050_dm_movement_registry.h")
REGTEST = "regtest.cpp"
APPLIED_MARK = "// R1050 applied"
INC_LINE = ('    #include "rules/audits/'
            'r1050_dm_movement_registry.h"'
            '  // R1050')
CENSUS_BEFORE = 1058
CENSUS_AFTER = 1064
MARKER = ("R1050 dm movement "
          "registry")

# key, function, [row enum, col enum]
GRIDS = [
    ("dm_move_foot",
     "footMilesPerDay",
     ["FootBurden", "TerrainClass"]),
    ("dm_move_mounted",
     "mountedMilesPerDay",
     ["MountKind", "TerrainClass"]),
    ("dm_move_oared",
     "oaredMilesPerDay",
     ["VesselKind", "WaterKind"]),
    ("dm_move_sail_lo",
     "sailedMilesLo",
     ["VesselKind", "WaterKind"]),
    ("dm_move_sail_hi",
     "sailedMilesHi",
     ["VesselKind", "WaterKind"]),
]

ENUMS = ["TerrainClass", "FootBurden",
         "MountKind", "VesselKind",
         "WaterKind"]


def die(msg):
    sys.stderr.write(
        "r1050_splice: FATAL: %s\n"
        % msg)
    sys.exit(1)


# ---- census --------------------------------

def census_count():
    n = 0
    for d, _, fs in os.walk(
            os.path.join(
                ROOT, "rules/audits")):
        for f in fs:
            if f.endswith(".h"):
                p = os.path.join(d, f)
                n += open(p).read().count(
                    "audit: bad %d")
    n += open(os.path.join(
        ROOT, REGTEST)).read().count(
        "audit: bad %d")
    return n


# ---- the parse -----------------------------

def enum_members(src, name):
    # returns (members, count_token)
    m = re.search(
        r"enum " + name +
        r" \{([\s\S]*?)\}", src)
    if not m:
        die("enum " + name
            + " not found")
    body = re.sub(r"//[^\n]*", "",
                  m.group(1))
    names = []
    for p in body.split(","):
        p = p.strip()
        mm = re.match(
            r"([A-Z_][A-Z_0-9]*)"
            r"\s*(?:=\s*\d+)?$",
            p)
        if mm:
            names.append(mm.group(1))
    if not names:
        die("enum " + name
            + " has no members")
    if not names[-1].endswith(
            "_COUNT"):
        die("enum " + name
            + " has no _COUNT tail")
    return names[:-1], names[-1]


def parse_grids(src):
    out = {}
    for key, fn, enums in GRIDS:
        m = re.search(
            r"inline int " + fn +
            r"\(([^)]*)\)[^{]*\{",
            src)
        if not m:
            die("function " + fn
                + " not found")
        params = [p.strip().split()
                  for p in
                  m.group(1).split(",")]
        if len(params) != 2:
            die("function " + fn
                + ": want 2 params")
        for pr in params:
            if len(pr) != 2:
                die("function " + fn
                    + ": want type + "
                    + "name params")
        if [params[0][0],
                params[1][0]] \
                != enums:
            die("function " + fn
                + ": param types "
                + "mismatch the "
                + "enum pair")
        if not (params[0][1].islower()
                and params[1][1]
                .islower()):
            die("function " + fn
                + ": param names "
                + "not the parsed "
                + "lowercase names")
        body = re.search(
            r"inline int " + fn +
            r"\([^)]*\)[^{]*\{"
            r"([\s\S]*?)\n\}",
            src)
        g = re.search(
            r"static const int k"
            r"\[(\w+)\]\[(\w+)\]"
            r"\s*=\s*\{([\s\S]*?)\};",
            body.group(1))
        if not g:
            die("grid in " + fn
                + " not found")
        lit = re.sub(r"//[^\n]*", "",
                     g.group(3))
        vals = [int(v) for v in
                re.findall(r"-?\d+",
                           lit)]
        rmem, rcount = \
            enum_members(src, enums[0])
        cmem, ccount = \
            enum_members(src, enums[1])
        rows = len(rmem)
        cols = len(cmem)
        if [g.group(1), g.group(2)] \
                != [rcount, ccount]:
            die("grid dims in " + fn
                + " mismatch the "
                + "enum pair")
        if len(vals) != rows * cols:
            die("grid " + key + ": "
                + str(len(vals))
                + " cells (want "
                + str(rows * cols) + ")")
        out[key] = {
            "fn": fn, "vals": vals,
            "rows": rows, "cols": cols,
            "penum": [params[0][1],
                      params[1][1]],
            "enums": enums}
    return out


def parse_pure(src):
    # terrainClass: the case and the
    # return may share a line
    m = re.search(
        r"inline TerrainClass "
        r"terrainClass\("
        r"OutdoorTerrain t\) \{"
        r"([\s\S]*?)\n\}", src)
    if not m:
        die("terrainClass not found")
    tc = {}
    pend = []
    for line in \
            m.group(1).splitlines():
        for c in re.findall(
                r"case (T_\w+):",
                line):
            pend.append(c)
        r = re.search(
            r"return (TC_\w+);",
            line)
        if r:
            for p in pend:
                tc[p] = r.group(1)
            pend = []
    if pend:
        die("terrainClass: "
            + "unrouted case "
            + pend[0])
    if len(tc) != 8:
        die("terrainClass: "
            + str(len(tc))
            + " routes (want 8)")
    # footBurdenFor: the thresholds
    # plus the fallthrough return
    fm = re.search(
        r"inline FootBurden "
        r"footBurdenFor\(int lbs\) \{"
        r"([\s\S]*?)\n\}", src)
    if not fm:
        die("footBurdenFor "
            + "not found")
    body = fm.group(1)
    fbth = re.findall(
        r"if \(lbs <= (\d+)\) "
        r"return (FB_\w+);", body)
    rets = re.findall(
        r"return (FB_\w+);", body)
    if len(fbth) < 1:
        die("footBurdenFor "
            + "thresholds not found")
    if len(rets) != len(fbth) + 1:
        die("footBurdenFor: want "
            + "one fallthrough return")
    fb_fall = rets[-1]
    prev = -1
    for n, _ in fbth:
        if int(n) <= prev:
            die("footBurdenFor: "
                + "thresholds not "
                + "increasing")
        prev = int(n)
    return tc, fbth, fb_fall


# ---- the emitter ---------------------------
# The wrapper breaks ONLY at
# spaces, never inside a token,
# and refuses (dies) on any line
# carrying a string literal that
# does not fit - so a broken C
# string literal cannot occur.

def wrap(text, ind=""):
    m = re.match(r"( *)(.*)", text,
                 re.S)
    lead = ind + m.group(1)
    body = m.group(2)
    if len(lead + body) <= 78:
        return [lead + body]
    if '"' in body:
        die("emit: line with a "
            + "string literal "
            + "does not fit 78: "
            + body[:40])
    words = body.split(" ")
    out = [lead + words[0]]
    for w in words[1:]:
        if len(out[-1]) + 1 \
                + len(w) <= 78:
            out[-1] += " " + w
        else:
            out.append(lead + "    "
                       + w)
    return out


class Emit:
    def __init__(self):
        self.lines = []

    def __call__(self, text,
                 ind=""):
        self.lines.extend(
            wrap(text, ind))


# ---- lua emit -------------------------------

def lua_grid(key, title, rows,
             cols, vals):
    out = []
    w = out.append
    w("-- " + key)
    w("-- The R1050 outdoor movement")
    w("-- de-wire (DMG pp.58-59).")
    w("-- " + title + ".")
    w("-- Grid encoding: tables[1]")
    w("-- name \"grid\", values = the")
    w("-- printed rates flat (row-")
    w("-- major). RowCount/ColCount")
    w("-- pins. Rowless def (the")
    w("-- R1047 class_grids shape).")
    w("-- The accessors live in")
    w("-- dm/outdoormove.h and are")
    w("-- unchanged.")
    w("-- DO NOT hand-edit: "
      "tools/r1050_splice.py")
    w("-- is the only writer.")
    w("")
    w("return {")
    w("  key = \"%s\"," % key)
    w("  name = \"%s\"," % title)
    w("  sources = {")
    w("    { part = 0, "
      "round = 1050 },")
    w("  },")
    w("  pins = {")
    w("    { name = \"%sRowCount\","
      % key)
    w("      value = %d,"
      % rows)
    w("      comment = "
      "\"the grid rows\" },")
    w("    { name = \"%sColCount\","
      % key)
    w("      value = %d,"
      % cols)
    w("      comment = "
      "\"the grid cols\" },")
    w("  },")
    w("  tables = {")
    w("    { name = \"grid\", "
      "values = {")
    for r in range(rows):
        row = vals[
            r * cols:(r + 1) * cols]
        w("      " + ", ".join(
            str(v) for v in row)
          + ", ")
    w("    } },")
    w("  },")
    w("}")
    w("")
    return "\n".join(out)


def build_lua(grids):
    titles = {
        "dm_move_foot":
            "The DMG pp.58-59 afoot "
            "miles per day",
        "dm_move_mounted":
            "The DMG pp.58-59 mounted "
            "miles per day",
        "dm_move_oared":
            "The DMG pp.58-59 afloat "
            "oared miles per day",
        "dm_move_sail_lo":
            "The DMG pp.58-59 afloat "
            "sailed miles per day, "
            "band lo",
        "dm_move_sail_hi":
            "The DMG pp.58-59 afloat "
            "sailed miles per day, "
            "band hi"}
    files = {}
    for key, _, _ in GRIDS:
        g = grids[key]
        files[key + ".lua"] = \
            lua_grid(key, titles[key],
                     g["rows"],
                     g["cols"],
                     g["vals"])
    return files


# ---- seam emit ------------------------------

SEAM_TXT = """// -------------------------------------------------
// the R1050 dm movement registry seam
//
// One registry behind the movement
// reads: content/tables/dm_movement/
// (the five grids). The per-tag grid
// views build on first use - every
// accessor signature and every enum
// stays as the print reads it.
// DO NOT hand-edit:
// tools/r1050_splice.py is the
// only writer.
inline items::MiscItemRegistry&
dmMoveReg() {
    static items::MiscItemRegistry reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory(
            "content/tables/dm_movement");
    }
    return reg;
}

inline const int* dmMoveGrid(
        const char* tag) {
    struct GridCache {
        std::map<std::string,
            std::vector<int>> grids;
    };
    static GridCache cache;
    static bool built = false;
    if (!built) {
        built = true;
        for (const auto& kv :
                 dmMoveReg().all()) {
            const items::
                MiscItemDef* d =
                dmMoveReg().find(
                    kv.first);
            if (!d
                || d->tables.empty()
                || d->tables[0].name
                    != "grid")
                continue;
            cache.grids[kv.first]
                .assign(
                    d->tables[0]
                        .values.begin(),
                    d->tables[0]
                        .values.end());
        }
    }
    auto it = cache.grids.find(tag);
    return it == cache.grids.end()
        ? 0 : it->second.data();
}
"""


def build_seam(src, grids):
    s = src
    if ("#include \"items/"
            "MiscItemRegistry.h\""
            not in s):
        inc = re.findall(
            r"#include[^\n]*\n",
            s.split("namespace dm")[0])
        if not inc:
            die("no include line to "
                + "anchor the registry "
                + "include on")
        last = inc[-1]
        s = s.replace(
            last, last
            + "#include \"items/"
            "MiscItemRegistry.h\"\n",
            1)
    s = s.replace(
        "#pragma once",
        APPLIED_MARK + "\n#pragma once",
        1)
    anchor = "namespace dm {\n"
    if anchor not in s:
        die("namespace dm anchor "
            + "not found")
    s = s.replace(
        anchor, anchor + "\n"
        + SEAM_TXT, 1)
    # the five grids - each rewrite
    # scoped to its own function body
    for key, fn, _ in GRIDS:
        g = grids[key]
        r, c = g["penum"]
        m = re.search(
            r"inline int " + fn +
            r"\([^)]*\)[^{]*\{"
            r"([\s\S]*?)\n\}", s)
        if not m:
            die("body of " + fn
                + " not found for the "
                + "rewrite")
        body = m.group(0)
        old = re.search(
            r"    static const int k"
            r"\[\w+\]\[\w+\]\s*=\s*"
            r"\{[\s\S]*?\};\n"
            r"    return k\[\w+\]"
            r"\[\w+\];\n", body)
        if not old:
            die("grid body for "
                + fn + " not found")
        idx = ("(int)%s * %d + (int)%s"
               % (r, g["cols"], c))
        new = (
            "    const int* g = "
            "dmMoveGrid(\"%s\");\n"
            "    return g ? g[%s]\n"
            "               : 0;\n"
            % (key, idx))
        s = s.replace(
            m.group(0),
            m.group(0).replace(
                old.group(0), new, 1),
            1)
    if re.search(
            r"static const int k",
            s):
        die("a static grid survived "
            + "the rewrite")
    return s


# ---- fragment emit --------------------------
# R1048 block idiom at the
# in-function seat: 4-indent banner,
# brace-scoped block, six printf
# sections, "if (bad) return 1;"
# between them, no std:: containers.
# Every printf label fits 78 on one
# line so the census pattern "audit:
# bad %d" can never be split.

def want_arr(E, name, vals):
    txt = ("const int %s[] = { "
           % name
           + ", ".join(str(v)
                       for v in vals)
           + " };")
    E(txt, "                ")


def fb_probes(fbth, fb_fall):
    # probes derived off the parse:
    # each threshold and the step
    # past it, plus the zero floor
    out = [(0, fbth[0][1])]
    for i, (n, w) in \
            enumerate(fbth):
        nxt = (fbth[i + 1][1]
               if i + 1 < len(fbth)
               else fb_fall)
        out.append((int(n), w))
        out.append((int(n) + 1, nxt))
    return out


def build_frag(grids, tc, fbth,
               fb_fall, enums):
    E = Emit()
    E("    // ==== R1050: dm movement "
      "registry " + "=" * 24)
    E("    // The R1050 de-wire: the "
      "five movement grids of")
    E("    // dm/outdoormove.h ride "
      "items::MiscItemRegistry")
    E("    // from "
      "content/tables/dm_movement/ "
      "(5 defs). Six sections:")
    E("    // load, counts, land "
      "grids, afloat, seam, edges.")
    E("    // Census %d -> %d. DO NOT"
      % (CENSUS_BEFORE,
         CENSUS_AFTER))
    E("    // hand-edit: "
      "tools/r1050_splice.py is the")
    E("    // only writer.")
    E("    {")
    E("        int bad = 0;")

    # -- 1. load
    E("        // -- 1. load "
      "---------------------------------")
    E("        {")
    E("            items::"
      "MiscItemRegistry reg;")
    E("            int n = "
      "reg.loadDirectory(")
    E("                "
      "\"content/tables/"
      "dm_movement\");")
    E("            if (n != 5) ++bad;")
    E("            if (!reg.errors()"
      ".empty()) ++bad;")
    E("            for (const auto& "
      "kv : reg.all())")
    E("                if ((int)kv"
      ".second.sources")
    E("                    .size() "
      "!= 1)")
    E("                    ++bad;")
    E("        }")
    E("        printf(\"" + MARKER
      + " load "
      "audit: bad %d\\n\", bad);")
    E("        if (bad) return 1;")
    E("        bad = 0;")

    # -- 2. counts
    E("        // -- 2. counts "
      "---------------------------------")
    E("        {")
    E("            items::"
      "MiscItemRegistry reg;")
    E("            reg.loadDirectory(")
    E("                "
      "\"content/tables/"
      "dm_movement\");")
    for key, _, _ in GRIDS:
        g = grids[key]
        E("            {")
        E("                const "
          "items::MiscItemDef* d =")
        E("                    "
          "reg.find(\"%s\");" % key)
        E("                if (!d) "
          "{ ++bad; } else {")
        E("                    if "
          "((int)d->rows.size() != 0")
        E("                        || "
          "(int)d->pins.size() != 2")
        E("                        || "
          "d->pins[0].value != %d"
          % g["rows"])
        E("                        || "
          "d->pins[1].value != %d"
          % g["cols"])
        E("                        || "
          "(int)d->tables.size()"
          " != 1")
        E("                        || "
          "d->tables[0].name != "
          "\"grid\"")
        E("                        || "
          "(int)d->tables[0].values")
        E("                            "
          ".size() != %d)"
          % (g["rows"] * g["cols"]))
        E("                        "
          "++bad;")
        E("                }")
        E("            }")
    E("        }")
    E("        printf(\"" + MARKER
      + " counts "
      "audit: bad %d\\n\", bad);")
    E("        if (bad) return 1;")
    E("        bad = 0;")

    # -- 3. land grids
    E("        // -- 3. land grids "
      "-----------------------------")
    E("        {")
    E("            items::"
      "MiscItemRegistry reg;")
    E("            reg.loadDirectory(")
    E("                "
      "\"content/tables/"
      "dm_movement\");")
    E("            const items::"
      "MiscItemDef* df = reg.find(")
    E("                "
      "\"dm_move_foot\");")
    E("            const items::"
      "MiscItemDef* dk = reg.find(")
    E("                "
      "\"dm_move_mounted\");")
    E("            if (!df || !dk) "
      "{ ++bad; } else {")
    want_arr(E, "wantFoot",
             grids["dm_move_foot"]
             ["vals"])
    want_arr(E, "wantMounted",
             grids["dm_move_mounted"]
             ["vals"])
    E("                for (int i = 0;"
      " i < %d; ++i)"
      % len(grids["dm_move_foot"]
             ["vals"]))
    E("                    if ((int)df"
      "->tables[0].values[i] !="
      " wantFoot[i]) ++bad;")
    E("                for (int i = 0;"
      " i < %d; ++i)"
      % len(grids["dm_move_mounted"]
             ["vals"]))
    E("                    if ((int)dk"
      "->tables[0].values[i] !="
      " wantMounted[i]) ++bad;")
    E("            }")
    E("        }")
    E("        printf(\"" + MARKER
      + " land grids "
      "audit: bad %d\\n\", bad);")
    E("        if (bad) return 1;")
    E("        bad = 0;")

    # -- 4. afloat grids
    naf = len(
        grids["dm_move_oared"]
        ["vals"])
    E("        // -- 4. afloat "
      "---------------------------------")
    E("        {")
    E("            items::"
      "MiscItemRegistry reg;")
    E("            reg.loadDirectory(")
    E("                "
      "\"content/tables/"
      "dm_movement\");")
    E("            const items::"
      "MiscItemDef* d1 = reg.find(")
    E("                "
      "\"dm_move_oared\");")
    E("            const items::"
      "MiscItemDef* d2 = reg.find(")
    E("                "
      "\"dm_move_sail_lo\");")
    E("            const items::"
      "MiscItemDef* d3 = reg.find(")
    E("                "
      "\"dm_move_sail_hi\");")
    E("            if (!d1 || !d2 "
      "|| !d3) { ++bad; } else {")
    want_arr(E, "wantOared",
             grids["dm_move_oared"]
             ["vals"])
    want_arr(E, "wantLo",
             grids["dm_move_sail_lo"]
             ["vals"])
    want_arr(E, "wantHi",
             grids["dm_move_sail_hi"]
             ["vals"])
    E("                for (int i = 0;"
      " i < %d; ++i) {" % naf)
    E("                    if ((int)d1"
      "->tables[0].values[i] !="
      " wantOared[i]) ++bad;")
    E("                    if "
      "(wantLo[i] > wantHi[i])"
      " ++bad;")
    E("                    if ((int)d2"
      "->tables[0].values[i] !="
      " wantLo[i]) ++bad;")
    E("                    if ((int)d3"
      "->tables[0].values[i] !="
      " wantHi[i]) ++bad;")
    E("                }")
    E("            }")
    E("        }")
    E("        printf(\"" + MARKER
      + " afloat "
      "audit: bad %d\\n\", bad);")
    E("        if (bad) return 1;")
    E("        bad = 0;")

    # -- 5. seam cross-read
    E("        // -- 5. seam "
      "cross-read -------------------------")
    E("        {")
    E("            items::"
      "MiscItemRegistry reg;")
    E("            reg.loadDirectory(")
    E("                "
      "\"content/tables/"
      "dm_movement\");")
    cross = [
        ("dm_move_foot", "dfr"),
        ("dm_move_mounted", "dmo"),
        ("dm_move_oared", "doe"),
        ("dm_move_sail_lo", "dlo"),
        ("dm_move_sail_hi",
         "dhi")]
    for key, var in cross:
        E("            const items::"
          "MiscItemDef* %s = "
          "reg.find(" % var)
        E("                "
          "\"%s\");" % key)
    E("            if (!dfr || !dmo "
      "|| !doe || !dlo || !dhi)")
    E("                ++bad;")
    fcols = grids["dm_move_foot"]
    mcols = grids[
        "dm_move_mounted"]
    E("            for (int b = 0; "
      "b < %d; ++b)"
      % fcols["rows"])
    E("                for (int t = 0;"
      " t < %d; ++t)"
      % fcols["cols"])
    E("                    if (dm::"
      "footMilesPerDay(")
    E("                            "
      "(dm::FootBurden)b,")
    E("                            "
      "(dm::TerrainClass)t)")
    E("                        != "
      "(int)dfr->tables[0]")
    E("                            "
      ".values[b * %d + t])"
      % fcols["cols"])
    E("                        ++bad;")
    E("            for (int m = 0; "
      "m < %d; ++m)"
      % mcols["rows"])
    E("                for (int t = 0;"
      " t < %d; ++t)"
      % mcols["cols"])
    E("                    if (dm::"
      "mountedMilesPerDay(")
    E("                            "
      "(dm::MountKind)m,")
    E("                            "
      "(dm::TerrainClass)t)")
    E("                        != "
      "(int)dmo->tables[0]")
    E("                            "
      ".values[m * %d + t])"
      % mcols["cols"])
    E("                        ++bad;")
    E("            for (int v = 0; "
      "v < %d; ++v)"
      % grids["dm_move_oared"]
      ["rows"])
    E("                for (int w = 0;"
      " w < %d; ++w) {"
      % grids["dm_move_oared"]
      ["cols"])
    E("                    int i = "
      "v * %d + w;"
      % grids["dm_move_oared"]
      ["cols"])
    for fn, var in [
            ("oaredMilesPerDay",
             "doe"),
            ("sailedMilesLo",
             "dlo"),
            ("sailedMilesHi",
             "dhi")]:
        E("                    if "
          "(dm::%s(" % fn)
        E("                            "
          "(dm::VesselKind)v,")
        E("                            "
          "(dm::WaterKind)w)")
        E("                        != "
          "(int)%s->tables[0]"
          % var)
        E("                            "
          ".values[i]) ++bad;")
    E("                }")
    E("        }")
    E("        printf(\"" + MARKER
      + " seam "
      "audit: bad %d\\n\", bad);")
    E("        if (bad) return 1;")
    E("        bad = 0;")

    # -- 6. edges
    E("        // -- 6. edges "
      "---------------------------------")
    E("        {")
    for lbs, want in \
            fb_probes(fbth, fb_fall):
        E("            if (dm::"
          "footBurdenFor(%d) != "
          "dm::%s) ++bad;"
          % (lbs, want))
    for terrain in sorted(tc):
        E("            if (dm::"
          "terrainClass("
          "dm::%s)" % terrain)
        E("                != dm::%s)"
          " ++bad;" % tc[terrain])
    ms = grids["dm_move_sail_lo"]
    mh = grids["dm_move_sail_hi"]
    vi = {}
    for e in ["VesselKind",
              "WaterKind",
              "FootBurden",
              "TerrainClass",
              "MountKind"]:
        vi[e] = {
            n: i for i, n in
            enumerate(
                enums[e])}

    def idx(enum, tok):
        if tok not in vi[enum]:
            die("enum member "
                + tok + " not found")
        return vi[enum][tok]
    vms = idx("VesselKind",
              "VESSEL_MERCHANT_"
              "SMALL")
    wsea = idx("WaterKind",
               "WATER_SEA")
    lo50 = ms["vals"][
        vms * ms["cols"] + wsea]
    hi50 = mh["vals"][
        vms * mh["cols"] + wsea]
    E("            if (dm::"
      "sailedMilesLo(")
    E("                    dm::"
      "VESSEL_MERCHANT_SMALL,")
    E("                    dm::"
      "WATER_SEA) != %d) ++bad;"
      % lo50)
    E("            if (dm::"
      "sailedMilesHi(")
    E("                    dm::"
      "VESSEL_MERCHANT_SMALL,")
    E("                    dm::"
      "WATER_SEA) != %d) ++bad;"
      % hi50)
    fbh = idx("FootBurden",
              "FB_HEAVY")
    tcvr = idx("TerrainClass",
               "TC_VERY_RUGGED")
    foot = grids["dm_move_foot"]
    hv = foot["vals"][
        fbh * foot["cols"] + tcvr]
    E("            if (dm::"
      "footMilesPerDay(")
    E("                    dm::"
      "FB_HEAVY, dm::"
      "TC_VERY_RUGGED) != %d)"
      " ++bad;" % hv)
    mounted = grids[
        "dm_move_mounted"]
    mcart = idx("MountKind",
                "MOUNT_CART")
    mwag = idx("MountKind",
               "MOUNT_WAGON")
    cart0 = mounted["vals"][
        mcart * mounted["cols"]
        + tcvr]
    wag0 = mounted["vals"][
        mwag * mounted["cols"]
        + tcvr]
    E("            if (dm::"
      "mountedMilesPerDay(")
    E("                    dm::"
      "MOUNT_CART, dm::"
      "TC_VERY_RUGGED) != %d)"
      " ++bad;" % cart0)
    E("            if (dm::"
      "mountedMilesPerDay(")
    E("                    dm::"
      "MOUNT_WAGON, dm::"
      "TC_VERY_RUGGED) != %d)"
      " ++bad;" % wag0)
    E("        }")
    E("        printf(\"" + MARKER
      + " edges "
      "audit: bad %d\\n\", bad);")
    E("    }")
    return "\n".join(E.lines) + "\n"


# ---- the self-scan -------------------------
# Pre-write: every ledgered kill
# shape, re-derived from the parse.

def self_scan(frag, seam,
              lua_files, grids,
              tc, fbth, fb_fall,
              enums):
    keys = [k for k, _, _ in GRIDS]

    # class 6: fused tokens
    if re.search(
            r"[A-Za-z0-9_]"
            r"(?:rules|items|dm)::",
            frag):
        die("self-scan: fused "
            + "namespace token "
            + "in fragment")
    if re.search(
            r"\bconst(?=[A-Za-z_])",
            frag):
        die("self-scan: fused "
            + "const in fragment")

    # class 3: statement terminator
    for line in frag.splitlines():
        s = line.rstrip()
        if s.endswith("})") \
                and not s.endswith(
                    "});"):
            die("self-scan: }) "
                + "without ; (class 3): "
                + s)

    # class 4: seat shape
    for tok in ["#include",
                "#pragma",
                "namespace",
                "inline",
                "std::map",
                "std::set",
                "std::sort"]:
        if tok in frag:
            die("self-scan: %s "
                "in fragment (class 4)"
                % tok)
    if frag.count(
            "if (bad) return 1;"
            ) != 5:
        die("self-scan: want 5 "
            + "bad-guards in "
            + "fragment")
    if frag.count("printf(") != 6:
        die("self-scan: want 6 "
            + "printfs in fragment")
    if frag.count(
            "audit: bad %d") != 6:
        die("self-scan: census "
            + "pattern count != 6")
    if frag.count("(") \
            != frag.count(")"):
        die("self-scan: paren "
            + "imbalance in "
            + "fragment")
    if frag.count("{") \
            != frag.count("}"):
        die("self-scan: brace "
            + "imbalance in "
            + "fragment")

    # class 5: dm-scope
    # qualification
    toks = ["TerrainClass",
            "FootBurden",
            "MountKind",
            "VesselKind",
            "WaterKind",
            "footMilesPerDay",
            "mountedMilesPerDay",
            "oaredMilesPerDay",
            "sailedMilesLo",
            "sailedMilesHi",
            "terrainClass",
            "footBurdenFor"]
    for e in ENUMS:
        toks += enums[e]
    toks += list(tc)
    toks += [w for _, w in fbth]
    toks.append(fb_fall)
    for t in toks:
        for m in re.finditer(
                r"(?<![\w:])" + t
                + r"(?![\w:])", frag):
            pre = frag[:m.start()]
            if not pre.endswith(
                    "dm::"):
                die("self-scan: "
                    + t + " not dm:: "
                    + "qualified "
                    + "(class 5) at: "
                    + frag[max(
                        0, m.start()
                        - 30):
                        m.end() + 10]
                    .splitlines()[-1])
    for t in ["MiscItemRegistry",
              "MiscItemDef"]:
        for m in re.finditer(
                r"(?<![\w:])" + t
                + r"(?![\w:])", frag):
            pre = frag[:m.start()]
            if not pre.endswith(
                    "items::"):
                die("self-scan: "
                    + t + " not items:: "
                    + "qualified")

    # class 9: dangling find
    # targets
    finds = re.findall(
        r"reg\.find\(\"(\w+)\"\)",
        frag)
    if sorted(finds) \
            != sorted(keys):
        die("self-scan: reg.find "
            + "targets != the 5 "
            + "def keys")

    # class 10: wants must
    # equal the parsed data
    for name, key in [
            ("wantFoot",
             "dm_move_foot"),
            ("wantMounted",
             "dm_move_mounted"),
            ("wantOared",
             "dm_move_oared"),
            ("wantLo",
             "dm_move_sail_lo"),
            ("wantHi",
             "dm_move_sail_hi")]:
        m = re.search(
            r"const int " + name
            + r"\[\] = \{([\d\s,]+)"
            r"\};", frag)
        if not m:
            die("self-scan: want "
                + name + " missing")
        got = [int(v) for v in
               re.findall(r"\d+",
                          m.group(1))]
        if got != grids[key][
                "vals"]:
            die("self-scan: "
                + name + " != the "
                + "parsed grid")

    # edges: probe parity with
    # the parse
    for lbs, want in \
            fb_probes(fbth, fb_fall):
        if not re.search(
                r"footBurdenFor\("
                + str(lbs)
                + r"\) != dm::"
                + want + r"\)", frag):
            die("self-scan: "
                + "footBurdenFor probe "
                + str(lbs) + " missing")
    got_tc = re.findall(
        r"terrainClass\("
        r"dm::(T_\w+)\)\s*!= "
        r"dm::(TC_\w+)\)", frag)
    if {a: b for a, b in got_tc} \
            != tc:
        die("self-scan: "
            + "terrainClass probes "
            + "!= the parsed map")
    for fn in ["sailedMilesLo",
               "sailedMilesHi"]:
        mm = re.search(
            fn + r"\(\s*dm::"
            r"VESSEL_MERCHANT_"
            r"SMALL,\s*dm::"
            r"WATER_SEA\) != "
            r"(\d+)\)", frag)
        if not mm:
            die("self-scan: "
                + fn + " coaster "
                + "probe missing")
        g = grids[
            "dm_move_sail_lo"
            if fn.endswith("Lo")
            else "dm_move_sail_hi"]
        vms = enums[
            "VesselKind"].index(
            "VESSEL_MERCHANT_"
            "SMALL")
        wsea = enums[
            "WaterKind"].index(
            "WATER_SEA")
        want = g["vals"][
            vms * g["cols"] + wsea]
        if int(mm.group(1)) \
                != want:
            die("self-scan: "
                + fn + " coaster "
                + "want wrong")

    # cols <= 78 except the
    # banner line
    for line in frag.splitlines():
        if line.startswith(
                "    // ===="):
            continue
        if len(line.rstrip()) \
                > 78:
            die("self-scan: "
                + "fragment line "
                + "over 78 cols: "
                + line.rstrip())

    # the seam
    tags = re.findall(
        r"dmMoveGrid\(\"(\w+)\"\)",
        seam)
    if sorted(tags) \
            != sorted(keys):
        die("self-scan: seam "
            + "tags != the 5 "
            + "def keys")
    if seam.count(APPLIED_MARK) \
            != 1:
        die("self-scan: seam "
            + "mark count != 1")
    if seam.count(
            "namespace dm {") != 1:
        die("self-scan: seam "
            + "namespace opener "
            + "count != 1")
    if "static const int k" \
            in seam:
        die("self-scan: grid "
            + "survived in seam")
    for key, fn, _ in GRIDS:
        g = grids[key]
        want = ("g[(int)%s * %d "
                "+ (int)%s]"
                % (g["penum"][0],
                   g["cols"],
                   g["penum"][1]))
        if want not in seam:
            die("self-scan: seam "
                + "index for " + fn
                + " != the parsed "
                + "param shape")
    if seam.count("(") \
            != seam.count(")"):
        die("self-scan: paren "
            + "imbalance in seam")

    # the lua: loader schema and
    # value parity
    for key, body in \
            lua_files.items():
        if ('key = "%s"'
                % key[:-4]) \
                not in body:
            die("self-scan: lua "
                + key + " key/stem "
                + "mismatch")
        for need in [
                "sources = {",
                "pins = {",
                "tables = {",
                "{ part = 0, "
                "round = 1050 },"]:
            if need not in body:
                die("self-scan: lua "
                    + key + " lacks "
                    + need)
        for line in \
                body.splitlines():
            if len(
                    line.rstrip()) \
                    > 78:
                die("self-scan: lua "
                    + key + " line "
                    + "over 78 cols")
        g = grids[key[:-4]]
        got = [int(v) for v in
               re.findall(
                   r"\d+",
                   body.split(
                       "values = {")[1]
                   .split("} }")[0])]
        if got != g["vals"]:
            die("self-scan: lua "
                + key + " values "
                + "!= the parse")


# ---- main -----------------------------------

def main():
    if not os.path.isfile(
            os.path.join(
                ROOT, REGTEST)) \
            or not os.path.isfile(
                os.path.join(
                    ROOT, HEAD)):
        die("run me from the "
            + "repo root")
    src = open(
        os.path.join(
            ROOT, HEAD)).read()
    if APPLIED_MARK in src:
        print("applied 0, "
              "already 1")
        print("SPLICE OK")
        return
    c0 = census_count()
    if c0 != CENSUS_BEFORE:
        die("census %d, want %d"
            % (c0, CENSUS_BEFORE))
    grids = parse_grids(src)
    enums = {n: enum_members(
        src, n)[0] for n in ENUMS}
    tc, fbth, fb_fall = \
        parse_pure(src)
    lua_files = build_lua(grids)
    seam = build_seam(src, grids)
    frag = build_frag(
        grids, tc, fbth, fb_fall,
        enums)
    self_scan(frag, seam,
              lua_files, grids, tc,
              fbth, fb_fall, enums)

    # write: data first, the
    # marked header LAST so the
    # mark never lands on a
    # half-applied tree
    os.makedirs(
        os.path.join(
            ROOT, LUA_DIR),
        exist_ok=True)
    for name, body in \
            lua_files.items():
        open(os.path.join(
            ROOT, LUA_DIR, name),
            "w").write(body)
    open(os.path.join(
        ROOT, FRAG),
        "w").write(frag)

    rt = open(os.path.join(
        ROOT, REGTEST)).read()
    anchor = ('    #include '
              '"rules/audits/'
              'r1049_subrace_'
              'level_registry.h"'
              '  // R1049')
    if anchor not in rt:
        die("R1049 include "
            + "anchor missing")
    rt = rt.replace(
        anchor,
        anchor + "\n" + INC_LINE,
        1)
    open(os.path.join(
        ROOT, REGTEST),
        "w").write(rt)

    open(os.path.join(
        ROOT, HEAD),
        "w").write(seam)

    c1 = census_count()
    if c1 != CENSUS_AFTER:
        die("census after %d, "
            "want %d"
            % (c1, CENSUS_AFTER))
    print("census %d -> %d "
          "audit printf patterns"
          % (c0, c1))
    print("applied 1, rewrote 2 "
          "tracked files, wrote "
          "6 new files")
    print("SPLICE OK")


if __name__ == "__main__":
    main()
