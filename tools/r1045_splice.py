#!/usr/bin/env python3
# r1045_splice.py - the R1045 splice tool: retire the five
# DMG Appendix I dressing band cascades from dm/appendixi.h
# (airCurrentFor, odorFor, airStateFor, generalItemFor,
# soundFor - 14/14/6/54/58 printed bands, 146 total) into NEW
# dir content/tables/appendixi/ (5 lua, the items::MiscItemRow
# schema), and rewire the five accessors onto registry view
# scans. The enums stay in-file (constants, the band identity
# API - the r150 audit and the callers pin them); every
# accessor signature is unchanged; the 00-fold and the clamp
# semantics stay verbatim.
#
# Lua encoding (one def per dressing table):
#   rows[i]: name = the enum tag at index i (the parsed
#            source, never hand-transcribed),
#            band = { lo, hi } the printed percentile band,
#            set = the def key; every other field zero.
#   pins[0]: <key>RowCount = the printed band count.
#
# Idempotent: a second run reports "already 1".
import os
import re
import sys

ROOT = os.getcwd()
CENSUS_BEFORE = 1028
CENSUS_AFTER = 1034
AI = "dm/appendixi.h"
DIR = "content/tables/appendixi"

TABLES = [
    {"enum": "AirCurrent", "prefix": "AC_",
     "acc": "inline AirCurrent airCurrentFor(int r) {",
     "count": "AC_COUNT", "n": 14,
     "key": "appendixi_air_currents",
     "title": "Appendix I air currents (14 bands)"},
    {"enum": "Odor", "prefix": "OD_",
     "acc": "inline Odor odorFor(int r) {",
     "count": "OD_COUNT", "n": 14,
     "key": "appendixi_odors",
     "title": "Appendix I odors (14 bands)"},
    {"enum": "AirState", "prefix": "AIR_",
     "acc": "inline AirState airStateFor(int r) {",
     "count": "AIR_COUNT", "n": 6,
     "key": "appendixi_air_states",
     "title": "Appendix I air (6 bands)"},
    {"enum": "GeneralItem", "prefix": "GI_",
     "acc": "inline GeneralItem generalItemFor(int r) {",
     "count": "GI_COUNT", "n": 54,
     "key": "appendixi_general_items",
     "title": "Appendix I general items (54 bands)"},
    {"enum": "SoundKind", "prefix": "SK_",
     "acc": "inline SoundKind soundFor(int r) {",
     "count": "SK_COUNT", "n": 58,
     "key": "appendixi_unexplained_sounds",
     "title": "Appendix I unexplained sounds (58 bands)"},
]


def die(msg):
    sys.stderr.write("r1045_splice: FATAL: %s\n" % msg)
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


# ---------------------------------------------------------------------------
# parsing
def parse_table(src, spec):
    # the enum: tags in order (the COUNT entry has no comma)
    esig = "enum %s {" % spec["enum"]
    if src.count(esig) != 1:
        die("enum %s appears %d times"
            % (spec["enum"], src.count(esig)))
    d = src.index(esig) + len(esig)
    e = src.index("};", d)
    tags = []
    comments = []
    for ln in src[d:e].split("\n"):
        m = re.match(r"\s+([A-Z][A-Z0-9_]*)( = \d+)?,?\s*"
                     r"(?://\s*(\d+)(?:-(\d+))?)?", ln)
        if not m:
            if ln.strip():
                die("unparsed enum line %r" % ln)
            continue
        tags.append(m.group(1))
        if m.group(3):
            lo = int(m.group(3))
            hi = int(m.group(4) or m.group(3))
            if m.group(4) == "00":
                hi = 100
            comments.append((lo, hi))
        else:
            comments.append(None)
    if tags and tags[-1] == spec["count"]:
        tags = tags[:-1]
        comments = comments[:-1]
    if len(tags) != spec["n"]:
        die("%s enum has %d tags, want %d"
            % (spec["enum"], len(tags), spec["n"]))
    for i, t in enumerate(tags):
        if not t.startswith(spec["prefix"]):
            die("%s tag %d %r lacks prefix %s"
                % (spec["enum"], i, t, spec["prefix"]))

    # the accessor cascade: thresholds + tags
    s, e = region_of(src, spec["acc"])
    blk = src[s:e]
    steps = re.findall(r"if \(r <= (\d+)\)\s+"
                       r"return ([A-Z][A-Z0-9_]*);", blk)
    if len(steps) != spec["n"] - 1:
        die("%s cascade has %d steps, want %d"
            % (spec["enum"], len(steps), spec["n"] - 1))
    tail = re.findall(r"\n    return ([A-Z][A-Z0-9_]*);\n",
                     blk)
    if len(tail) != 1:
        die("%s cascade tail appears %d times"
            % (spec["enum"], len(tail)))
    bands = []
    prev = 0
    for hi_s, tag in steps + [(None, tail[0])]:
        if hi_s is None:
            hi = 100
        else:
            hi = int(hi_s)
        bands.append((prev + 1, hi, tag))
        prev = hi
    for i, (lo, hi, tag) in enumerate(bands):
        if tag != tags[i]:
            die("%s band %d tag %r != enum %r"
                % (spec["enum"], i, tag, tags[i]))
        if lo > hi or hi > 100:
            die("%s band %d %d-%d" % (spec["enum"], i, lo, hi))
        c = comments[i]
        if c is not None and c != (lo, hi):
            die("%s band %d comment %s != cascade %d-%d"
                % (spec["enum"], i, c, lo, hi))
    if bands[-1][1] != 100:
        die("%s last band hi %d" % (spec["enum"], bands[-1][1]))
    return tags, bands


def parse_all(src):
    out = {}
    for spec in TABLES:
        tags, bands = parse_table(src, spec)
        out[spec["key"]] = {"spec": spec, "tags": tags,
                            "bands": bands}
        print("parsed: %s %d bands"
              % (spec["enum"], len(bands)))
    return out


# ---------------------------------------------------------------------------
# lua emission
HDR = (
    "-- dressing table def: %s\n"
    "-- The DMG Appendix I dressing bands, the R1045 de-wire. %s\n"
    "-- Row encoding: name = the enum tag at the row index\n"
    "-- (dm/appendixi.h), band = { lo, hi } the printed\n"
    "-- percentile band (the 00 band is 100). The accessor,\n"
    "-- the 00-fold and the clamp semantics live in\n"
    "-- dm/appendixi.h and are unchanged.\n"
    "-- DO NOT hand-edit: tools/r1045_splice.py is the only writer.\n"
    "\n")

LUA_ROW = (
    '    { name = "%s", set = "%s", band = { %d, %d }, '
    'xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, '
    'qty = { 0, 0 } },\n')


def lua_def(key, title, tags, bands):
    body = "".join(
        LUA_ROW % (tags[i], key, bands[i][0], bands[i][1])
        for i in range(len(tags)))
    return (
        HDR % (key, title) +
        "return {\n"
        '  key = "%s",\n'
        '  name = "%s",\n'
        "  rows = {\n"
        "%s"
        "  },\n"
        "  sources = {\n"
        "    { part = 0, round = 1045 },\n"
        "  },\n"
        "  pins = {\n"
        '    { name = "%sRowCount", value = %d, '
        'comment = "the printed band count" },\n'
        "  },\n"
        "  tables = {},\n"
        "}\n"
        % (key, title, body, key, len(tags)))


RT_ROW = re.compile(
    r'\{ name = "([^"]+)", set = "([^"]+)", '
    r"band = \{ (\d+), (\d+) \}, "
    r"xp = (-?\d+), xp_hi = (-?\d+), gp = (-?\d+), "
    r"gp_hi = (-?\d+), qty = \{ (-?\d+), (-?\d+) \} \},")


def roundtrip(key, tags, bands, text):
    got = RT_ROW.findall(text)
    if len(got) != len(tags):
        die("%s round-trip: %d rows, want %d"
            % (key, len(got), len(tags)))
    for i, g in enumerate(got):
        want = (tags[i], key, str(bands[i][0]),
                str(bands[i][1]),
                "0", "0", "0", "0", "0", "0")
        if g != want:
            die("%s round-trip row %d: %s != %s"
                % (key, i, g, want))


# ---------------------------------------------------------------------------
# seam + rewrite
SEAM = (
    "// ---- the R1045 registry seam ----------------------------------------\n"
    "// The five dressing band tables ride\n"
    "// items::MiscItemRegistry from\n"
    "// content/tables/appendixi/ (def keys\n"
    "// appendixi_*). Row encoding: name = the\n"
    "// enum tag at the row index, band = the\n"
    "// printed percentile band; the rest zero.\n"
    "// This seam is header-only (the\n"
    "// R1040-R1044 idiom); every accessor\n"
    "// signature below is unchanged (the r150\n"
    "// audit pins them); the enums stay in-file\n"
    "// as constants and the 00-fold and clamp\n"
    "// semantics stay verbatim. The band scan\n"
    "// relies on the battery-pinned band chain\n"
    "// (1..100, contiguous, last band 100).\n"
    "\n"
    "inline items::MiscItemRegistry& aiReg() {\n"
    "    static items::MiscItemRegistry reg;\n"
    "    static bool loaded = false;\n"
    "    if (!loaded) {\n"
    "        loaded = true;\n"
    "        reg.loadDirectory(\"content/tables/appendixi\");\n"
    "    }\n"
    "    return reg;\n"
    "}\n"
    "\n"
    "// the registry-backed per-view cache (the\n"
    "// R1032-R1044 idiom; function-local statics in\n"
    "// inline functions are shared across TUs)\n"
    "inline const std::vector<items::MiscItemRow>& aiView(\n"
    "        const char* name) {\n"
    "    static std::map<std::string,\n"
    "        std::vector<items::MiscItemRow>> cache;\n"
    "    auto it = cache.find(name);\n"
    "    if (it == cache.end()) {\n"
    "        const items::MiscItemDef* d = aiReg().find(name);\n"
    "        it = cache.emplace(\n"
    "            name, d ? d->rows\n"
    "                   : std::vector<items::MiscItemRow>()).first;\n"
    "    }\n"
    "    return it->second;\n"
    "}\n"
    "\n")



def rewrite_header(src, tables):
    # banner note
    src = replace_once(
        src,
        "// Conventions, all named in place:\n",
        "// R1045: the five band tables are registry-native\n"
        "// (content/tables/appendixi/, the seam below);\n"
        "// the printed cascades are gone from this header\n"
        "// and the accessors read registry views. The enums\n"
        "// stay in-file as constants (the band identity API);\n"
        "// the 00-fold and the clamp semantics stay verbatim.\n"
        "//\n"
        "// Conventions, all named in place:\n",
        "banner note")

    # include + seam
    src = replace_once(
        src,
        "#pragma once\n\nnamespace dm {\nnamespace appendixi {\n",
        "#pragma once\n\n"
        "#include \"items/MiscItemRegistry.h\"   "
        "// R1045: the dressing bands ride the registry\n"
        "\nnamespace dm {\nnamespace appendixi {\n\n" + SEAM,
        "include + seam")

    # the five accessor bodies
    for spec in TABLES:
        tags = tables[spec["key"]]["tags"]
        body = (
            "    if (r <= 0)   r = 100;              "
            "// 00 folds to 100\n"
            "    if (r > 100)  r = 100;\n"
            "    const auto& rows = aiView(\"%s\");\n"
            "    if (rows.empty()) return %s;   // defensive\n"
            "    for (int i = 0; i < (int)rows.size(); ++i)\n"
            "        if (r <= rows[i].bandHi)\n"
            "            return %s(i);\n"
            "    return %s((int)rows.size() - 1);\n"
            % (spec["key"], tags[0], spec["enum"],
               spec["enum"]))
        s, e = region_of(src, spec["acc"])
        src = (src[:s] + spec["acc"] + "\n" + body + "}\n"
               + src[e:])

    # retired-token checks: every cascade step is gone; only
    # the two folds/clamps per accessor remain
    n = src.count("if (r <=")
    if n != 2 * len(TABLES):
        die("if (r <= count %d, want %d (folds+clamps only)"
            % (n, 2 * len(TABLES)))
    for spec in TABLES:
        if src.count("return %s;" % spec["count"]):
            die("count return survived in %s" % spec["enum"])
    return src


# ---------------------------------------------------------------------------
# fragment (every pin computed from the parsed source)
def cq(s):
    if '"' in s or "\\" in s:
        die("tag needs escape support: %r" % s)
    return '"%s"' % s


def barename(spec):
    # "inline AirCurrent airCurrentFor(int r) {"
    #   -> "airCurrentFor" (the name sits before the paren;
    #   rindex over the WHOLE line would land inside the
    #   parameter list, the R1045 delivery miss)
    s = spec["acc"]
    head = s[:s.index("(")]
    name = head[head.rindex(" ") + 1:]
    if not name.isidentifier():
        die("cannot extract accessor name from %r" % s)
    return name


def accname(spec):
    # "airCurrentFor" -> "AI::airCurrentFor"
    return "AI::" + barename(spec)


def build_fragment(tables):
    L = []
    a = L.append
    a("    // ==== R1045: appendixi dressing registry ================================\n")
    a("    // The R1045 de-wire: the five DMG Appendix I\n")
    a("    // dressing band tables (air currents 14,\n")
    a("    // odors 14, air 6, general items 54,\n")
    a("    // unexplained sounds 58; 146 bands) ride\n")
    a("    // items::MiscItemRegistry from\n")
    a("    // content/tables/appendixi/ (def keys\n")
    a("    // appendixi_*). This audit loads its own\n")
    a("    // registry instance and cross-reads every\n")
    a("    // band through the inline accessor surface\n")
    a("    // (airCurrentFor/odorFor/airStateFor/\n")
    a("    // generalItemFor/soundFor) and the aiView\n")
    a("    // seam, so the r150 audit and this registry\n")
    a("    // audit read the same data through the same\n")
    a("    // signatures.\n")
    a("    {\n")
    a("        int bad = 0;\n")
    # 1. load
    a("        // -- 1. load --------------------------------------\n")
    a("        {\n")
    a("            items::MiscItemRegistry t;\n")
    a('            if (t.loadDirectory("content/tables/appendixi") != 5)\n')
    a("                ++bad;\n")
    a("            if (!t.errors().empty()) ++bad;\n")
    a("            if (t.all().size() != 5) ++bad;\n")
    for spec in TABLES:
        a('            if (t.all().count("%s") != 1) ++bad;\n'
          % spec["key"])
    a('            if (t.all().count("appendixi_air")) ++bad;\n')
    a('            if (t.all().count("treasure_swords")) ++bad;\n')
    a('            if (t.all().count("weapon_chart")) ++bad;\n')
    a('            if (t.all().count("")) ++bad;\n')
    a("        }\n")
    a('        printf("R1045 appendixi dressing registry load audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # 2. counts
    a("        // -- 2. counts ------------------------------------\n")
    a("        {\n")
    a("            items::MiscItemRegistry t;\n")
    a('            t.loadDirectory("content/tables/appendixi");\n')
    for spec in TABLES:
        v = "v_%s" % spec["count"]
        a('            const auto* %s = t.find("%s");\n'
          % (v, spec["key"]))
        a("            if (!%s || (int)%s->rows.size() != %d) ++bad;\n"
          % (v, v, spec["n"]))
        a("            if (%s && ((int)%s->pins.size() != 1\n"
          % (v, v))
        a("                       || %s->pins[0].name\n" % v)
        a('                              != std::string("%sRowCount")\n'
          % spec["key"])
        a("                       || %s->pins[0].value != %d)) ++bad;\n"
          % (v, spec["n"]))
        a("            if (%s && (int)%s->sources.size() != 1) ++bad;\n"
          % (v, v))
        # the in-file enum count cross-checks the rows
        a("            if (dm::appendixi::%s != (%s ? (int)%s->rows.size() : -1))\n"
          % (spec["count"], v, v))
        a("                ++bad;\n")
    a("        }\n")
    a('        printf("R1045 appendixi dressing registry counts audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # 3. bands
    a("        // -- 3. bands (the percentile axis) ---------------\n")
    a("        {\n")
    a("            items::MiscItemRegistry t;\n")
    a('            t.loadDirectory("content/tables/appendixi");\n')
    a("            for (const auto& kv : t.all()) {\n")
    a("                const auto& d = kv.second;\n")
    a("                int prevHi = 0;\n")
    a("                for (const auto& r : d.rows) {\n")
    a("                    if (r.bandLo != prevHi + 1\n")
    a("                        || r.bandHi < r.bandLo\n")
    a("                        || r.bandHi > 100\n")
    a("                        || r.set != d.key\n")
    a("                        || r.name.empty()\n")
    a("                        || r.gp != 0\n")
    a("                        || r.gpHi != 0\n")
    a("                        || r.xp != 0\n")
    a("                        || r.xpHi != 0\n")
    a("                        || r.qtyLo != 0\n")
    a("                        || r.qtyHi != 0) ++bad;\n")
    a("                    prevHi = r.bandHi;\n")
    a("                }\n")
    a("                if (prevHi != 100) ++bad;   // last band is 00\n")
    a("            }\n")
    a("        }\n")
    a('        printf("R1045 appendixi dressing registry bands audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # 4. data (famous pins, all computed from the parsed source)
    a("        // -- 4. data (famous pins, all computed) ----------\n")
    a("        {\n")
    a("            namespace AI = dm::appendixi;\n")
    for spec in TABLES:
        ent = tables[spec["key"]]
        tags = ent["tags"]
        bands = ent["bands"]
        acc = accname(spec)
        mid = spec["n"] // 2
        lo0, hi0 = bands[0][0], bands[0][1]
        loM, hiM = bands[mid][0], bands[mid][1]
        tagM = tags[mid]
        loL, hiL = bands[-1][0], bands[-1][1]
        tagL = tags[-1]
        # first band edges (both sides) + the step over it
        a("            if (%s(%d) != AI::%s) ++bad;\n"
          % (acc, lo0, tags[0]))
        a("            if (%s(%d) != AI::%s) ++bad;\n"
          % (acc, hi0, tags[0]))
        a("            if (%s(%d) != AI::%s) ++bad;\n"
          % (acc, hi0 + 1, tags[1]))
        # a middle band, both edges
        a("            if (%s(%d) != AI::%s\n" % (acc, loM, tagM))
        a("                || %s(%d) != AI::%s) ++bad;\n"
          % (acc, hiM, tagM))
        # the last printed band (the 00 band) both edges
        a("            if (%s(%d) != AI::%s\n" % (acc, loL, tagL))
        a("                || %s(100) != AI::%s) ++bad;\n"
          % (acc, tagL))
        # the middle row's name is the middle enum tag
        a('            if (AI::aiView("%s")[%d].name\n'
          % (spec["key"], mid))
        a('                    != std::string(%s)) ++bad;\n'
          % cq(tagM))
    a("        }\n")
    a('        printf("R1045 appendixi dressing registry data audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # 5. rows (the full cross-read: accessor vs bands, 1..100,
    #    and every row name == its parsed enum tag)
    a("        // -- 5. rows (the full band cross-read) -----------\n")
    a("        {\n")
    a("            items::MiscItemRegistry t;\n")
    a('            t.loadDirectory("content/tables/appendixi");\n')
    for spec in TABLES:
        v = "v_%s" % spec["count"]
        acc = barename(spec)
        a('            const auto* %s = t.find("%s");\n'
          % (v, spec["key"]))
        a("            if (!%s) { ++bad; } else {\n" % v)
        # every row name == the parsed enum tag, in order
        a("                static const char* const k1045_%s[] = {\n"
          % spec["count"])
        tags = tables[spec["key"]]["tags"]
        for i in range(0, len(tags), 3):
            chunk = tags[i:i + 3]
            a("                    " + " ".join(
                "%s," % cq(t) for t in chunk) + "\n")
        a("                };\n")
        a("                if ((int)(sizeof(k1045_%s) / sizeof(k1045_%s[0]))\n"
          % (spec["count"], spec["count"]))
        a("                        != (int)%s->rows.size()) ++bad;\n" % v)
        a("                for (int i = 0; i < (int)%s->rows.size(); ++i)\n"
          % v)
        a("                    if (%s->rows[i].name\n" % v)
        a("                            != std::string(k1045_%s[i])) ++bad;\n"
          % spec["count"])
        # the accessor cross-read: for every percentile roll,
        # the accessor returns the row whose band contains it
        a("                for (int r = 1; r <= 100; ++r) {\n")
        a("                    int want = 0;\n")
        a("                    for (int i = 0;\n")
        a("                         i < (int)%s->rows.size(); ++i) {\n" % v)
        a("                        if (r <= %s->rows[i].bandHi) {\n" % v)
        a("                            want = i;\n")
        a("                            break;\n")
        a("                        }\n")
        a("                    }\n")
        a("                    if (dm::appendixi::%s(r) != want) ++bad;\n"
          % acc)
        a("                }\n")
        a("            }\n")
    a("        }\n")
    a('        printf("R1045 appendixi dressing registry rows audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # 6. edges
    a("        // -- 6. edges (folds, clamps, negatives) -----------\n")
    a("        {\n")
    a("            namespace AI = dm::appendixi;\n")
    for spec in TABLES:
        acc = accname(spec)
        tagL = tables[spec["key"]]["tags"][-1]
        # 0 folds to 100 (the book 00); negatives and
        # out-of-range rolls clamp to the last band
        a("            if (%s(0) != AI::%s) ++bad;\n" % (acc, tagL))
        a("            if (%s(-5) != AI::%s) ++bad;\n" % (acc, tagL))
        a("            if (%s(101) != AI::%s) ++bad;\n" % (acc, tagL))
        a("            if (%s(999) != AI::%s) ++bad;\n" % (acc, tagL))
    a('            if (!dm::appendixi::aiView("appendixi_air").empty())\n')
    a("                ++bad;\n")
    a('            if (!dm::appendixi::aiView("no_such_table").empty())\n')
    a("                ++bad;\n")
    a('            if (dm::appendixi::aiReg().find("treasure_swords")\n')
    a("                    != nullptr) ++bad;\n")
    a('            if (dm::appendixi::aiReg().find("") != nullptr) ++bad;\n')
    a("        }\n")
    a('        printf("R1045 appendixi dressing registry edges audit: bad %d\\n", bad);\n')
    a("    }\n")
    return "".join(L)


# static header checks (the R392 lesson, generalized)
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
    for m in re.finditer(r"\b[A-Za-z0-9_]+(-[A-Za-z0-9_]+)+\b",
                         code):
        die("%s: hyphen token in code: %r"
            % (name, m.group(0)))
    # the R1045 delivery miss, guarded: a qualified call
    # with an empty name (AI::(1)) is always a bug
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
                total += open(os.path.join(root, f)).read().count(
                    "audit: bad %d")
    total += open("regtest.cpp").read().count("audit: bad %d")
    return total


def main():
    os.chdir(ROOT)
    if not os.path.exists(AI):
        die("run from the repo root (%s missing)" % AI)

    marker = os.path.join(DIR, TABLES[0]["key"] + ".lua")
    already = (os.path.exists(marker)
               and "R1045 registry seam" in open(AI).read())
    if already:
        print("applied 0, already 1")
        print("SPLICE OK")
        return

    c = census()
    if c != CENSUS_BEFORE:
        die("census %d, expected %d" % (c, CENSUS_BEFORE))

    src = open(AI).read()
    tables = parse_all(src)

    os.makedirs(DIR, exist_ok=True)
    files = {}
    for spec in TABLES:
        ent = tables[spec["key"]]
        files[spec["key"] + ".lua"] = lua_def(
            spec["key"], spec["title"], ent["tags"],
            ent["bands"])
    for name, text in files.items():
        open(os.path.join(DIR, name), "w").write(text)
    for spec in TABLES:
        ent = tables[spec["key"]]
        roundtrip(spec["key"], ent["tags"], ent["bands"],
                  files[spec["key"] + ".lua"])
    print("round-trip: 5 lua files parse back byte-exact")

    new_src = rewrite_header(src, tables)
    static_checks(AI, new_src)
    open(AI, "w").write(new_src)

    frag = build_fragment(tables)
    static_checks("the fragment", frag)
    open("rules/audits/r1045_appendixi_dressing_registry.h",
         "w").write(frag)

    reg = open("regtest.cpp").read()
    anchor = ('    #include "rules/audits/r1044_class_ladder_registry.h"'
              '  // R1044\n')
    reg = replace_once(
        reg, anchor,
        anchor +
        '    #include "rules/audits/r1045_appendixi_dressing_registry.h"'
        '  // R1045\n',
        "regtest include")
    open("regtest.cpp", "w").write(reg)

    c = census()
    print("census: %d -> %d audit printf patterns"
          % (CENSUS_BEFORE, CENSUS_AFTER))
    if c != CENSUS_AFTER:
        die("census %d, expected %d" % (c, CENSUS_AFTER))

    print("applied 1, rewrote 2 tracked files, wrote 6 new files")
    print("SPLICE OK")


main()
