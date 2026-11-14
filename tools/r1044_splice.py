#!/usr/bin/env python3
# r1044_splice.py - the R1044 splice tool: retire the PHB
# class xp-title ladders from rules/phb/subclasses.h (the six
# subclass arrays kXp*/kTitle*) and rules/phb/bard.h (kXp[23],
# kTitles[23]) into NEW dir content/tables/class_ladders/
# (7 lua, the items::MiscItemRow schema), and rewire the xp
# and title accessors onto registry views. The subclass
# scalars (base, group, caps, dice, adder, prime, the counts)
# and the bard non-ladder data (slots, colleges, gates) stay
# in-file - constants and code, not tables.
#
# Lua encoding (one def per class):
#   rows[i]: name = the printed title of level i+1,
#            band = { i+1, i+1 } the printed level,
#            gp = the XP to attain the level (0 at level 1),
#            set = the def key; every other field zero.
#   pins[0]: <key>RowCount = the printed row count.
#
# Idempotent: a second run reports "already 1".
import os
import re
import sys

ROOT = os.getcwd()
CENSUS_BEFORE = 1022
CENSUS_AFTER = 1028
SC = "rules/phb/subclasses.h"
BD = "rules/phb/bard.h"
DIR = "content/tables/class_ladders"
BARD_KEY = "bard_ladder"

# the def keys == the SubclassDef name fields (SUB_PALADIN..)
ORDER = ["paladin", "ranger", "druid",
         "illusionist", "assassin", "monk"]
WANT_ROWS = {"paladin": 11, "ranger": 12, "druid": 14,
             "illusionist": 12, "assassin": 15, "monk": 17}


def die(msg):
    sys.stderr.write("r1044_splice: FATAL: %s\n" % msg)
    sys.exit(1)


def replace_once(src, old, new, what):
    n = src.count(old)
    if n != 1:
        die("%s anchor appears %d times (expected 1)"
            % (what, n))
    return src.replace(old, new)


# ---------------------------------------------------------------------------
# parsing
def parse_ints(block, decl):
    if block.count(decl) != 1:
        die("%s appears %d times in block"
            % (decl, block.count(decl)))
    d = block.index(decl) + len(decl)
    e = block.index("};", d)
    return [int(x) for x in re.findall(r"-?\d+", block[d:e])]


def parse_strings(block, decl):
    if block.count(decl) != 1:
        die("%s appears %d times in block"
            % (decl, block.count(decl)))
    d = block.index(decl) + len(decl)
    e = block.index("};", d)
    return re.findall(r'"([^"]*)"', block[d:e])


def region_of(src, sig):
    if src.count(sig) != 1:
        die("signature %r appears %d times"
            % (sig, src.count(sig)))
    start = src.index(sig)
    end = src.index("\n}\n", start)
    return start, end + 3


def parse_subclasses(src):
    xp = {}
    titles = {}
    for name in ORDER:
        tag = name[0].upper() + name[1:]
        xp[name] = parse_ints(
            src, "static const int kXp%s[%d] = {"
            % (tag, WANT_ROWS[name]))
        titles[name] = parse_strings(
            src, "static const char* const kTitle%s[%d] = {"
            % (tag, WANT_ROWS[name]))
        if len(xp[name]) != WANT_ROWS[name]:
            die("%s xp has %d rows, want %d"
                % (name, len(xp[name]), WANT_ROWS[name]))
        if len(titles[name]) != WANT_ROWS[name]:
            die("%s titles has %d rows, want %d"
                % (name, len(titles[name]), WANT_ROWS[name]))
        for i, t in enumerate(titles[name]):
            if not t:
                die("%s title %d is empty" % (name, i))
        for i in range(1, len(xp[name])):
            if xp[name][i] <= xp[name][i - 1]:
                die("%s xp row %d not increasing" % (name, i + 1))
        if xp[name][0] != 0:
            die("%s xp level 1 is %d, want 0"
                % (name, xp[name][0]))

    # the SUB_DEFS scalars (name .. prime, 11 fields)
    row_re = re.compile(
        r'\{ "(\w+)", (-?\d+), (-?\d+), (-?\d+), (-?\d+), '
        r"(-?\d+), (-?\d+),\s*"
        r"kXp\w+, (\d+), (-?\d+),\s*"
        r"kTitle\w+, (\d+), (-?\d+) \}")
    defs = []
    for m in row_re.finditer(src):
        f = list(m.groups())
        defs.append({
            "name": f[0], "base": int(f[1]),
            "group": int(f[2]), "levelCap": int(f[3]),
            "hpBeyondCap": int(f[4]), "hitDie": int(f[5]),
            "two": int(f[6]), "xpRowCount": int(f[7]),
            "xpAdder": int(f[8]), "titleCount": int(f[9]),
            "prime": int(f[10]),
        })
    if len(defs) != 6:
        die("SUB_DEFS parsed %d rows, want 6" % len(defs))
    if [d["name"] for d in defs] != ORDER:
        die("SUB_DEFS order %s != %s"
            % ([d["name"] for d in defs], ORDER))
    for d in defs:
        n = WANT_ROWS[d["name"]]
        if d["xpRowCount"] != n or d["titleCount"] != n:
            die("%s counts %d/%d, want %d"
                % (d["name"], d["xpRowCount"],
                   d["titleCount"], n))
        if d["xpAdder"] < 0:
            die("%s adder %d" % (d["name"], d["xpAdder"]))
    print("parsed: subclasses 6 ladders "
          + "/".join(str(WANT_ROWS[n]) for n in ORDER))
    return xp, titles, defs


def parse_bard(src):
    s, e = region_of(src, "inline int bardXpForLevel(int level) {")
    xp = parse_ints(src[s:e], "static const int kXp[23] = {")
    s, e = region_of(src,
                      "inline const char* bardTitle(int level) {")
    titles = parse_strings(src[s:e],
                          "static const char* const kTitles[23] = {")
    if len(xp) != 23 or len(titles) != 23:
        die("bard arrays disagree: %d xp, %d titles"
            % (len(xp), len(titles)))
    if xp[0] != 0:
        die("bard xp level 1 is %d, want 0" % xp[0])
    for i in range(1, 23):
        if xp[i] <= xp[i - 1]:
            die("bard xp row %d not increasing" % (i + 1))
    for i, t in enumerate(titles):
        if not t:
            die("bard title %d is empty" % i)
    print("parsed: bard ladder 23 xp/title rows")
    return xp, titles


# ---------------------------------------------------------------------------
# lua emission
HDR = (
    "-- class ladder def: %s\n"
    "-- The PHB class xp-title ladder, the R1044 de-wire. %s\n"
    "-- Row encoding: band = { level, level } the printed\n"
    "-- level, gp the XP to attain it (0 at level 1),\n"
    "-- name the printed title. The accessor and clamp\n"
    "-- semantics live in rules/phb/%s and are unchanged.\n"
    "-- DO NOT hand-edit: tools/r1044_splice.py is the only writer.\n"
    "\n")

LUA_ROW = (
    '    { name = "%s", set = "%s", band = { %d, %d }, '
    'xp = 0, xp_hi = 0, gp = %d, gp_hi = 0, '
    'qty = { 0, 0 } },\n')


def lua_def(key, title, note, module, xp, titles):
    body = "".join(
        LUA_ROW % (titles[i], key, i + 1, i + 1, xp[i])
        for i in range(len(xp)))
    return (
        HDR % (key, note, module) +
        "return {\n"
        '  key = "%s",\n'
        '  name = "%s",\n'
        "  rows = {\n"
        "%s"
        "  },\n"
        "  sources = {\n"
        "    { part = 0, round = 1044 },\n"
        "  },\n"
        "  pins = {\n"
        '    { name = "%sRowCount", value = %d, '
        'comment = "the printed row count" },\n'
        "  },\n"
        "  tables = {},\n"
        "}\n"
        % (key, title, body, key, len(xp)))


RT_ROW = re.compile(
    r'\{ name = "([^"]+)", set = "([^"]+)", '
    r"band = \{ (\d+), (\d+) \}, "
    r"xp = (-?\d+), xp_hi = (-?\d+), gp = (-?\d+), "
    r"gp_hi = (-?\d+), qty = \{ (-?\d+), (-?\d+) \} \},")


def roundtrip(key, xp, titles, text):
    got = RT_ROW.findall(text)
    if len(got) != len(xp):
        die("%s round-trip: %d rows, want %d"
            % (key, len(got), len(xp)))
    for i, g in enumerate(got):
        want = (titles[i], key, str(i + 1), str(i + 1),
                "0", "0", str(xp[i]), "0", "0", "0")
        if g != want:
            die("%s round-trip row %d: %s != %s"
                % (key, i, g, want))


# ---------------------------------------------------------------------------
# seam
SEAM = (
    "// ---- the R1044 registry seam ----------------------------------------\n"
    "// The seven PHB class xp-title ladders (the six\n"
    "// subclass arrays and the bard ladder) ride\n"
    "// items::MiscItemRegistry from\n"
    "// content/tables/class_ladders/ (def keys = the\n"
    "// SubclassDef name fields, plus \"bard_ladder\").\n"
    "// Row encoding: band = { level, level } the printed\n"
    "// level, gp the XP to attain it, name the printed\n"
    "// title; the rest zero. This seam is header-only\n"
    "// (the R1040-R1043 idiom); every accessor signature\n"
    "// is unchanged (the r179/r186/r327 audits and the\n"
    "// engine pin them); the clamp semantics stay\n"
    "// verbatim. The subclass scalars (base, group,\n"
    "// caps, dice, adder, prime) are constants, not\n"
    "// tables, and stay in the struct below.\n"
    "\n"
    "inline items::MiscItemRegistry& ladderReg() {\n"
    "    static items::MiscItemRegistry reg;\n"
    "    static bool loaded = false;\n"
    "    if (!loaded) {\n"
    "        loaded = true;\n"
    "        reg.loadDirectory(\"content/tables/class_ladders\");\n"
    "    }\n"
    "    return reg;\n"
    "}\n"
    "\n"
    "// the registry-backed per-view cache (the\n"
    "// R1032-R1043 idiom; function-local statics in\n"
    "// inline functions are shared across TUs)\n"
    "inline const std::vector<items::MiscItemRow>& scLadder(\n"
    "        const char* name) {\n"
    "    static std::map<std::string,\n"
    "        std::vector<items::MiscItemRow>> cache;\n"
    "    auto it = cache.find(name);\n"
    "    if (it == cache.end()) {\n"
    "        const items::MiscItemDef* d = ladderReg().find(name);\n"
    "        it = cache.emplace(\n"
    "            name, d ? d->rows\n"
    "                   : std::vector<items::MiscItemRow>()).first;\n"
    "    }\n"
    "    return it->second;\n"
    "}\n"
    "\n")


def new_body(sig, body):
    return sig + "\n" + body + "}\n"


XP_BODY = (
    "    const SubclassDef& d = subclassDef(i);\n"
    "    if (level <= 1) return 0;\n"
    "    const auto& rows = scLadder(d.name);\n"
    "    if (rows.empty()) return 0;   // defensive: unloaded view\n"
    "    const int n = (int)rows.size();\n"
    "    if (level <= n) return rows[level - 1].gp;\n"
    "    return rows[n - 1].gp + (level - n) * d.xpAdder;\n")

TITLE_BODY = (
    "    const SubclassDef& d = subclassDef(i);\n"
    "    const auto& rows = scLadder(d.name);\n"
    "    if (rows.empty()) return \"\";   // defensive: unloaded\n"
    "    if (level < 1) level = 1;\n"
    "    if (level > (int)rows.size()) level = (int)rows.size();\n"
    "    return rows[level - 1].name.c_str();\n")

BARD_XP_BODY = (
    "    const auto& rows = scLadder(\"%s\");\n"
    "    if (rows.empty()) return 0;   // defensive: unloaded view\n"
    "    if (level < 1) level = 1;\n"
    "    if (level > (int)rows.size()) level = (int)rows.size();\n"
    "    return rows[level - 1].gp;\n") % BARD_KEY

BARD_TITLE_BODY = (
    "    const auto& rows = scLadder(\"%s\");\n"
    "    if (rows.empty()) return \"\";   // defensive: unloaded\n"
    "    if (level < 1) level = 1;\n"
    "    if (level > (int)rows.size()) level = (int)rows.size();\n"
    "    return rows[level - 1].name.c_str();\n") % BARD_KEY


def rewrite_subclasses(src, defs):
    # banner note
    src = replace_once(
        src,
        "// block, a bump of SUB_COUNT, and its battery rows.\n",
        "// block, a bump of SUB_COUNT, and its battery rows.\n"
        "//\n"
        "// R1044: the xp-title ladders are registry-native\n"
        "// (content/tables/class_ladders/, the seam below);\n"
        "// the printed arrays are gone from this header and\n"
        "// the accessors read registry views. The subclass\n"
        "// scalars (base, group, caps, dice, adder, prime)\n"
        "// are constants, not tables, and stay in-file.\n",
        "banner note")

    # include + seam
    src = replace_once(
        src,
        "#include <cstdint>\n\nnamespace rules {\n",
        "#include <cstdint>\n\n"
        "#include \"items/MiscItemRegistry.h\"   "
        "// R1044: the class ladders ride the registry\n"
        "\nnamespace rules {\n\n" + SEAM,
        "include + seam")

    # the struct: retire the two pointer fields
    src = replace_once(
        src,
        "    const int* xpRows;      // the printed attain rows\n"
        "    int xpRowCount;\n"
        "    int xpAdder;       // per level past the printed rows\n"
        "    const char* const* titles;   // the printed ladder\n"
        "    int titleCount;    // == xpRowCount\n",
        "    int xpRowCount;    // == the registry ladder rows\n"
        "    int xpAdder;       // per level past the printed rows\n"
        "    int titleCount;    // == xpRowCount (the ladder)\n",
        "struct fields")

    # the SUB_DEFS rows: drop the array members
    for d in defs:
        tag = d["name"][0].upper() + d["name"][1:]
        old = ("      kXp%s, %d, %d,\n"
               "      kTitle%s, %d, %d },\n"
               % (tag, d["xpRowCount"], d["xpAdder"],
                  tag, d["titleCount"], d["prime"]))
        new = ("      %d, %d,\n"
               "      %d, %d },\n"
               % (d["xpRowCount"], d["xpAdder"],
                  d["titleCount"], d["prime"]))
        src = replace_once(src, old, new,
                           "SUB_DEFS row " + d["name"])

    # the accessors
    src = replace_once(
        src,
        "// The XP to ATTAIN the given level (the R176\n"
        "// convention). Past the printed rows, the adder\n"
        "// applies (adder 0: the printed top is the\n"
        "// ceiling, the top row repeats).\n"
        "inline int subclassXpFor(int i, int level) {\n"
        "    const SubclassDef& d = subclassDef(i);\n"
        "    if (level <= 1) return 0;\n"
        "    if (level <= d.xpRowCount)\n"
        "        return d.xpRows[level - 1];\n"
        "    return d.xpRows[d.xpRowCount - 1]\n"
        "         + (level - d.xpRowCount) * d.xpAdder;\n"
        "}\n",
        "// The XP to ATTAIN the given level (the R176\n"
        "// convention). Past the printed rows, the adder\n"
        "// applies (adder 0: the printed top is the\n"
        "// ceiling, the top row repeats). The ladder\n"
        "// rows ride the R1044 registry seam.\n"
        "inline int subclassXpFor(int i, int level) {\n"
        + XP_BODY + "}\n",
        "subclassXpFor body")

    src = replace_once(
        src,
        "// The printed title for the level (clamped)\n"
        "inline const char* subclassTitle(int i, int level) {\n"
        "    const SubclassDef& d = subclassDef(i);\n"
        "    if (level < 1) level = 1;\n"
        "    if (level > d.titleCount) level = d.titleCount;\n"
        "    return d.titles[level - 1];\n"
        "}\n",
        "// The printed title for the level (clamped).\n"
        "// The ladder rows ride the R1044 registry seam.\n"
        "inline const char* subclassTitle(int i, int level) {\n"
        + TITLE_BODY + "}\n",
        "subclassTitle body")

    # retire the printed arrays (decl through };)
    for name in ORDER:
        tag = name[0].upper() + name[1:]
        for decl in ("static const int kXp%s[%d] = {",
                     "static const char* const kTitle%s[%d] = {"):
            decl = decl % (tag, WANT_ROWS[name])
            if src.count(decl) != 1:
                die("%s appears %d times at file scope"
                    % (decl, src.count(decl)))
            d = src.index(decl)
            ls = src.rfind("\n", 0, d) + 1
            e = src.index("};\n", d) + 3
            src = src[:ls] + src[e:]
    while "\n\n\n\n" in src:
        src = src.replace("\n\n\n\n", "\n\n\n")

    for tok in ["kXpPaladin", "kTitlePaladin", "kXpRanger",
                "kTitleRanger", "kXpDruid", "kTitleDruid",
                "kXpIllusionist", "kTitleIllusionist",
                "kXpAssassin", "kTitleAssassin",
                "kXpMonk", "kTitleMonk",
                "static const int kXp", "static const char* const kTitle"]:
        if tok in src:
            die("retired token %r still present" % tok)
    return src


def rewrite_bard(src):
    src = replace_once(
        src,
        "// DATA-DRIVEN (the standing scope).\n",
        "// DATA-DRIVEN (the standing scope).\n"
        "//\n"
        "// R1044: the xp-title ladder is registry-native\n"
        "// (content/tables/class_ladders/bard_ladder.lua,\n"
        "// the R1044 seam in subclasses.h); the printed\n"
        "// arrays are gone from this header and the\n"
        "// accessors read the registry view. The colleges,\n"
        "// the druid slots and the gates stay in-file\n"
        "// (constants and code, not tables).\n",
        "banner note")

    src = replace_once(
        src,
        "#include <cstdint>\n#include <string>\n",
        "#include <cstdint>\n#include <string>\n\n"
        '#include "subclasses.h"   '
        "// R1044: the ladder registry seam\n",
        "include seam")

    s, e = region_of(src, "inline int bardXpForLevel(int level) {")
    src = src[:s] + new_body(
        "inline int bardXpForLevel(int level) {",
        BARD_XP_BODY) + src[e:]

    s, e = region_of(src,
                      "inline const char* bardTitle(int level) {")
    src = src[:s] + new_body(
        "inline const char* bardTitle(int level) {",
        BARD_TITLE_BODY) + src[e:]

    for tok in ["kXp[23]", "kTitles[23]",
                "static const int kXp", "static const char* const kTitles"]:
        if tok in src:
            die("retired token %r still present" % tok)
    return src


# ---------------------------------------------------------------------------
# fragment (every pin computed from the parsed source)
def cq(s):
    # C string literal quoting: no embedded quotes exist in the
    # printed titles (verified by the parser); keep it simple
    # and loud if that ever changes.
    if '"' in s or "\\" in s:
        die("title needs escape support: %r" % s)
    return '"%s"' % s


def build_fragment(xp, titles, defs, bxp, btitles):
    L = []
    a = L.append
    a("    // ==== R1044: class ladder registry ======================================\n")
    a("    // The R1044 de-wire: the six subclass\n")
    a("    // xp-title ladders (11/12/14/12/15/17\n")
    a("    // rows) and the bard ladder (23) ride\n")
    a("    // items::MiscItemRegistry from\n")
    a("    // content/tables/class_ladders/ (def\n")
    a("    // keys = the SubclassDef name fields,\n")
    a('    // plus "bard_ladder"); this audit loads\n')
    a("    // its own registry instance and cross-reads\n")
    a("    // every row through the inline accessor\n")
    a("    // surface (subclassXpFor/subclassTitle/\n")
    a("    // bardXpForLevel/bardTitle), so the r179,\n")
    a("    // r186 and r327 audits and this registry\n")
    a("    // audit read the same data.\n")
    a("    {\n")
    a("        int bad = 0;\n")
    # -- 1. load
    a("        // -- 1. load --------------------------------------\n")
    a("        {\n")
    a("            items::MiscItemRegistry t;\n")
    a('            if (t.loadDirectory("content/tables/class_ladders") != 7)\n')
    a("                ++bad;\n")
    a("            if (!t.errors().empty()) ++bad;\n")
    a("            if (t.all().size() != 7) ++bad;\n")
    for k in ORDER + [BARD_KEY]:
        a('            if (t.all().count("%s") != 1) ++bad;\n' % k)
    a('            if (t.all().count("subclass_paladin")) ++bad;\n')
    a('            if (t.all().count("weapon_chart")) ++bad;\n')
    a('            if (t.all().count("equipment_armor")) ++bad;\n')
    a('            if (t.all().count("treasure_potions")) ++bad;\n')
    a('            if (t.all().count("")) ++bad;\n')
    a("        }\n")
    a('        printf("R1044 class ladder registry load audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # -- 2. counts
    a("        // -- 2. counts ------------------------------------\n")
    a("        {\n")
    a("            items::MiscItemRegistry t;\n")
    a('            t.loadDirectory("content/tables/class_ladders");\n')
    a("            if (rules::subclassCount() != 6) ++bad;\n")
    for i, k in enumerate(ORDER):
        a('            const auto* d_%d = t.find("%s");\n' % (i, k))
        a("            if (!d_%d || (int)d_%d->rows.size() != %d) ++bad;\n"
          % (i, i, WANT_ROWS[k]))
        a("            if (d_%d && ((int)d_%d->pins.size() != 1\n"
          % (i, i))
        a("                       || d_%d->pins[0].name\n" % i)
        a('                              != std::string("%sRowCount")\n' % k)
        a("                       || d_%d->pins[0].value != %d)) ++bad;\n"
          % (i, WANT_ROWS[k]))
        a("            if (d_%d && (int)d_%d->sources.size() != 1) ++bad;\n"
          % (i, i))
    a('            const auto* d_b = t.find("%s");\n' % BARD_KEY)
    a("            if (!d_b || (int)d_b->rows.size() != 23) ++bad;\n")
    a("            if (d_b && ((int)d_b->pins.size() != 1\n")
    a("                       || d_b->pins[0].name\n")
    a('                              != std::string("%sRowCount")\n' % BARD_KEY)
    a("                       || d_b->pins[0].value != 23)) ++bad;\n")
    # the in-file struct counts cross-check the rows
    for i, d in enumerate(defs):
        a("            if (rules::subclassDef(%d).xpRowCount != %d) ++bad;\n"
          % (i, d["xpRowCount"]))
        a("            if (rules::subclassDef(%d).titleCount != %d) ++bad;\n"
          % (i, d["titleCount"]))
    a("        }\n")
    a('        printf("R1044 class ladder registry counts audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # -- 3. bands
    a("        // -- 3. bands (the level axis) --------------------\n")
    a("        {\n")
    a("            items::MiscItemRegistry t;\n")
    a('            t.loadDirectory("content/tables/class_ladders");\n')
    a("            for (const auto& kv : t.all()) {\n")
    a("                const auto& d = kv.second;\n")
    a("                const int n = (int)d.rows.size();\n")
    a("                for (int i = 0; i < n; ++i)\n")
    a("                    if (d.rows[i].bandLo != i + 1\n")
    a("                        || d.rows[i].bandHi != i + 1\n")
    a("                        || d.rows[i].set != d.key\n")
    a("                        || d.rows[i].gpHi != 0\n")
    a("                        || d.rows[i].xp != 0\n")
    a("                        || d.rows[i].xpHi != 0\n")
    a("                        || d.rows[i].qtyLo != 0\n")
    a("                        || d.rows[i].qtyHi != 0) ++bad;\n")
    a("                for (int i = 0; i < n; ++i) {\n")
    a("                    if (d.rows[i].gp < 0) ++bad;\n")
    a("                    if (d.rows[i].name.empty()) ++bad;\n")
    a("                    if (i > 0\n")
    a("                        && d.rows[i].gp <= d.rows[i - 1].gp)\n")
    a("                        ++bad;   // strictly increasing\n")
    a("                }\n")
    a("            }\n")
    a("        }\n")
    a('        printf("R1044 class ladder registry bands audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # -- 4. data (famous pins + struct scalars)
    a("        // -- 4. data (famous pins, all computed) ----------\n")
    a("        {\n")
    # subclass xp and title spot rows
    a("            if (rules::subclassXpFor(0, 1) != %d) ++bad;\n"
      % xp["paladin"][0])
    a("            if (rules::subclassXpFor(0, 11) != %d) ++bad;\n"
      % xp["paladin"][10])
    a("            if (rules::subclassXpFor(1, 12) != %d) ++bad;\n"
      % xp["ranger"][11])
    a("            if (rules::subclassXpFor(2, 9) != %d) ++bad;\n"
      % xp["druid"][8])
    a("            if (rules::subclassXpFor(3, 10) != %d) ++bad;\n"
      % xp["illusionist"][9])
    a("            if (rules::subclassXpFor(4, 15) != %d) ++bad;\n"
      % xp["assassin"][14])
    a("            if (rules::subclassXpFor(5, 17) != %d) ++bad;\n"
      % xp["monk"][16])
    a("            if (std::string(rules::subclassTitle(0, 1))\n")
    a("                    != std::string(%s)) ++bad;\n"
      % cq(titles["paladin"][0]))
    a("            if (std::string(rules::subclassTitle(2, 14))\n")
    a("                    != std::string(%s)) ++bad;\n"
      % cq(titles["druid"][13]))
    a("            if (std::string(rules::subclassTitle(4, 15))\n")
    a("                    != std::string(%s)) ++bad;\n"
      % cq(titles["assassin"][14]))
    a("            if (std::string(rules::subclassTitle(5, 17))\n")
    a("                    != std::string(%s)) ++bad;\n"
      % cq(titles["monk"][16]))
    # bard spot rows
    a("            if (rules::bardXpForLevel(2) != %d) ++bad;\n"
      % bxp[1])
    a("            if (rules::bardXpForLevel(23) != %d) ++bad;\n"
      % bxp[22])
    a("            if (std::string(rules::bardTitle(1))\n")
    a("                    != std::string(%s)) ++bad;\n" % cq(btitles[0]))
    a("            if (std::string(rules::bardTitle(12))\n")
    a("                    != std::string(%s)) ++bad;\n" % cq(btitles[11]))
    a("            if (std::string(rules::bardTitle(23))\n")
    a("                    != std::string(%s)) ++bad;\n" % cq(btitles[22]))
    # the struct scalars (constants, not tables - stayed in-file)
    for i, d in enumerate(defs):
        a("            if (std::string(rules::subclassDef(%d).name)\n" % i)
        a("                    != std::string(%s)) ++bad;\n"
          % cq(d["name"]))
        a("            if (rules::subclassDef(%d).base != %d\n"
          % (i, d["base"]))
        a("                || rules::subclassDef(%d).group != %d\n"
          % (i, d["group"]))
        a("                || rules::subclassDef(%d).levelCap != %d\n"
          % (i, d["levelCap"]))
        a("                || rules::subclassDef(%d).hpBeyondCap != %d\n"
          % (i, d["hpBeyondCap"]))
        a("                || rules::subclassDef(%d).hitDie != %d\n"
          % (i, d["hitDie"]))
        a("                || rules::subclassDef(%d).twoDiceFirstLevel\n"
          % i)
        a("                       != %d\n" % d["two"])
        a("                || rules::subclassDef(%d).xpAdder != %d\n"
          % (i, d["xpAdder"]))
        a("                || rules::subclassDef(%d).prime != %d) ++bad;\n"
          % (i, d["prime"]))
    # the in-file bard constants (not tables - stayed)
    a("            if (rules::bardHitDice(23) != 22) ++bad;\n")
    a("            if (rules::bardDruidCastLevel(23) != 13) ++bad;\n")
    a("            if (rules::bardDruidCastLevel(13) != 12) ++bad;\n")
    a("        }\n")
    a('        printf("R1044 class ladder registry data audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # -- 5. rows (the full cross-read)
    a("        // -- 5. rows (the full cross-read) ----------------\n")
    a("        {\n")
    a("            items::MiscItemRegistry t;\n")
    a('            t.loadDirectory("content/tables/class_ladders");\n')
    for i, k in enumerate(ORDER):
        n = WANT_ROWS[k]
        a('            const auto* v_%d = t.find("%s");\n' % (i, k))
        a("            if (!v_%d) { ++bad; } else {\n" % i)
        a("                for (int l = 1; l <= %d; ++l) {\n" % n)
        a("                    if (rules::subclassXpFor(%d, l)\n" % i)
        a("                            != v_%d->rows[l - 1].gp\n" % i)
        a("                        || std::string(rules::subclassTitle(%d, l))\n"
          % i)
        a("                            != v_%d->rows[l - 1].name) ++bad;\n" % i)
        a("                }\n")
        a("            }\n")
    a('            const auto* v_b = t.find("%s");\n' % BARD_KEY)
    a("            if (!v_b) { ++bad; } else {\n")
    a("                for (int lv = 1; lv <= 23; ++lv) {\n")
    a("                    if (rules::bardXpForLevel(lv)\n")
    a("                            != v_b->rows[lv - 1].gp\n")
    a("                        || std::string(rules::bardTitle(lv))\n")
    a("                            != v_b->rows[lv - 1].name) ++bad;\n")
    a("                }\n")
    a("            }\n")
    a("        }\n")
    a('        printf("R1044 class ladder registry rows audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # -- 6. edges (adders, clamps, negatives)
    a("        // -- 6. edges (adders, clamps, negatives) --------\n")
    a("        {\n")
    for i, d in enumerate(defs):
        k = d["name"]
        n = d["xpRowCount"]
        top = xp[k][n - 1]
        if d["xpAdder"] > 0:
            a("            if (rules::subclassXpFor(%d, %d) != %d\n"
              % (i, n + 1, top + d["xpAdder"]))
            a("                || rules::subclassXpFor(%d, %d) != %d) ++bad;\n"
              % (i, n + 2, top + 2 * d["xpAdder"]))
        else:
            a("            if (rules::subclassXpFor(%d, %d) != %d\n"
              % (i, n + 1, top))
            a("                || rules::subclassXpFor(%d, %d) != %d) ++bad;\n"
              % (i, n + 3, top))
    a("            if (rules::subclassXpFor(0, 0) != 0) ++bad;\n")
    a("            if (rules::subclassXpFor(5, -3) != 0) ++bad;\n")
    a("            if (rules::subclassXpFor(-1, 9)\n")
    a("                    != rules::subclassXpFor(0, 9)) ++bad;\n")
    a("            if (rules::subclassXpFor(99, 9)\n")
    a("                    != rules::subclassXpFor(5, 9)) ++bad;\n")
    a("            if (std::string(rules::subclassTitle(0, -1))\n")
    a("                    != std::string(%s)) ++bad;\n"
      % cq(titles["paladin"][0]))
    a("            if (std::string(rules::subclassTitle(2, 999))\n")
    a("                    != std::string(%s)) ++bad;\n"
      % cq(titles["druid"][13]))
    a("            if (std::string(rules::subclassDef(-1).name)\n")
    a("                    != std::string(%s)\n" % cq(defs[0]["name"]))
    a("                || std::string(rules::subclassDef(99).name)\n")
    a("                       != std::string(%s)) ++bad;\n"
      % cq(defs[5]["name"]))
    a("            if (rules::bardXpForLevel(0) != %d) ++bad;\n"
      % bxp[0])
    a("            if (rules::bardXpForLevel(99) != %d) ++bad;\n"
      % bxp[22])
    a("            if (rules::bardXpForLevel(-4) != %d) ++bad;\n"
      % bxp[0])
    a("            if (std::string(rules::bardTitle(24))\n")
    a("                    != std::string(%s)) ++bad;\n"
      % cq(btitles[22]))
    a("            if (std::string(rules::bardTitle(0))\n")
    a("                    != std::string(%s)) ++bad;\n"
      % cq(btitles[0]))
    # negative views (the R1034 dispatch lesson)
    a("            if (!rules::scLadder(\"no_such_ladder\").empty())\n")
    a("                ++bad;\n")
    a("            if (rules::ladderReg().find(\"paladi\") != nullptr) ++bad;\n")
    a("            if (rules::ladderReg().find(\"\") != nullptr) ++bad;\n")
    a("            if (rules::subclassXpFor(0, 1) != 0) ++bad;\n")
    a("        }\n")
    a('        printf("R1044 class ladder registry edges audit: bad %d\\n", bad);\n')
    a("    }\n")
    return "".join(L)


# ---------------------------------------------------------------------------
# static header checks (the R392 lesson, generalized)
def static_checks(name, text):
    lines = text.split("\n")
    depth = 0
    for ln in lines:
        # strip string literals and comments crudely but
        # conservatively: flag any line with odd unescaped
        # quote count outside our known escape forms
        stripped = re.sub(r"\\.", "", ln)
        if stripped.count('"') % 2 != 0:
            # allowed: line ends inside a split string is NOT
            # allowed in this codebase's emitted text
            die("%s: unbalanced quotes: %r" % (name, ln))
    for ch in text:
        if ch == "{":
            depth += 1
        elif ch == "}":
            depth -= 1
    if depth != 0:
        die("%s: brace balance %d" % (name, depth))
    # hyphen scan on code only: strip string literals and
    # comments first (the R639 lesson targets identifiers)
    code = re.sub(r'"[^"\n]*"', '""', text)
    code = re.sub(r"//[^\n]*", "", code)
    for m in re.finditer(r"\b[A-Za-z0-9_]+(-[A-Za-z0-9_]+)+\b",
                         code):
        die("%s: hyphen token in code: %r"
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
    if not os.path.exists(SC) or not os.path.exists(BD):
        die("run from the repo root (%s missing)" % SC)

    marker = os.path.join(DIR, "paladin.lua")
    already = (os.path.exists(marker)
               and "R1044 registry seam" in open(SC).read())
    if already:
        print("applied 0, already 1")
        print("SPLICE OK")
        return

    c = census()
    if c != CENSUS_BEFORE:
        die("census %d, expected %d" % (c, CENSUS_BEFORE))

    sc = open(SC).read()
    bd = open(BD).read()
    xp, titles, defs = parse_subclasses(sc)
    bxp, btitles = parse_bard(bd)

    os.makedirs(DIR, exist_ok=True)
    files = {}
    for name in ORDER:
        files[name + ".lua"] = lua_def(
            name, "The %s xp and title ladder (%d rows)"
            % (name, WANT_ROWS[name]),
            "The six subclass ladders of rules/phb/"
            "subclasses.h.",
            "subclasses.h", xp[name], titles[name])
    files[BARD_KEY + ".lua"] = lua_def(
        BARD_KEY, "The bard xp and title ladder (23 rows)",
        "Bards Table I, rules/phb/bard.h.",
        "bard.h", bxp, btitles)
    for name, text in files.items():
        open(os.path.join(DIR, name), "w").write(text)

    for name in ORDER:
        roundtrip(name, xp[name], titles[name],
                  files[name + ".lua"])
    roundtrip(BARD_KEY, bxp, btitles, files[BARD_KEY + ".lua"])
    print("round-trip: 7 lua files parse back byte-exact")

    new_sc = rewrite_subclasses(sc, defs)
    new_bd = rewrite_bard(bd)
    static_checks(SC, new_sc)
    static_checks(BD, new_bd)
    open(SC, "w").write(new_sc)
    open(BD, "w").write(new_bd)

    frag = build_fragment(xp, titles, defs, bxp, btitles)
    static_checks("the fragment", frag)
    open("rules/audits/r1044_class_ladder_registry.h",
         "w").write(frag)

    reg = open("regtest.cpp").read()
    anchor = ('    #include "rules/audits/r1043_weapon_chart_registry.h"'
              '  // R1043\n')
    reg = replace_once(
        reg, anchor,
        anchor +
        '    #include "rules/audits/r1044_class_ladder_registry.h"'
        '  // R1044\n',
        "regtest include")
    open("regtest.cpp", "w").write(reg)

    c = census()
    print("census: %d -> %d audit printf patterns"
          % (CENSUS_BEFORE, CENSUS_AFTER))
    if c != CENSUS_AFTER:
        die("census %d, expected %d" % (c, CENSUS_AFTER))

    print("applied 1, rewrote 3 tracked files, wrote 8 new files")
    print("SPLICE OK")


main()
