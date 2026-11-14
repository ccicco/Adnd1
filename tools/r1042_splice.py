#!/usr/bin/env python3
# r1042_splice.py - the R1042 splice tool: retire the PHB
# equipment price tables from rules/phb/equipcosts.h (the 52
# arms rows, the 14 armor rows, the 99 general rows in 8
# printed lists) into NEW dir content/tables/equipment/
# (3 lua, the items::MiscItemRow schema), and rewire the
# inline price accessors onto registry views. The general
# list structure (list counts/firsts) rides the def's
# tables[] block natively. The monetary pins (20 sp = 1 gp,
# 10 cp = 1 sp, 200 cp = 1 gp) stay in-file (constants, not
# tables). Registry files are NOT touched.
#
# Row encoding (named in the lua headers and the seam):
#   band = { i, i }    the printed row index (print order)
#   gp   = amount     the printed price in its printed coin
#   qty  = { coin, 0 } the printed coin: 1 copper, 2 silver,
#                     3 gold (exactly one coin nonzero per
#                     row - the R300a identity)
#
# Idempotent: a second run reports "already 1" and rewrites
# nothing.
import os
import re
import sys

ROOT = os.getcwd()
CENSUS_BEFORE = 1010
CENSUS_AFTER = 1016
EQ = "rules/phb/equipcosts.h"
DIR = "content/tables/equipment"

ARMS = "equipment_arms"
ARMOR = "equipment_armor"
GENERAL = "equipment_general"

COIN_COPPER = 1
COIN_SILVER = 2
COIN_GOLD = 3


def die(msg):
    sys.stderr.write("r1042_splice: FATAL: %s\n" % msg)
    sys.exit(1)


def replace_once(src, old, new, what):
    n = src.count(old)
    if n != 1:
        die("%s anchor appears %d times (expected 1)" % (what, n))
    return src.replace(old, new)


# ---------------------------------------------------------------------------
# parse the source arrays
def parse_string_array(src, decl):
    if src.count(decl) != 1:
        die("%s appears %d times" % (decl, src.count(decl)))
    d = src.index(decl)
    end = src.index("};", d)
    block = src[d:end]
    return re.findall(r'"([^"]*)"', block)


def parse_int_array(src, decl):
    if src.count(decl) != 1:
        die("%s appears %d times" % (decl, src.count(decl)))
    d = src.index(decl) + len(decl)
    end = src.index("};", d)
    block = src[d:end]
    return [int(x) for x in re.findall(r"-?\d+", block)]


def parse_all(src):
    arms_n = parse_string_array(
        src, "static const char* const kNames[52] = {")
    arms_g = parse_int_array(src, "static const int kGold[52] = {")
    arms_s = parse_int_array(src, "static const int kSilver[52] = {")
    if not (len(arms_n) == len(arms_g) == len(arms_s) == 52):
        die("arms arrays disagree: %d %d %d"
            % (len(arms_n), len(arms_g), len(arms_s)))
    arms = []
    for i in range(52):
        if (arms_g[i] != 0) == (arms_s[i] != 0):
            die("arms row %d violates the one-coin identity" % i)
        coin = COIN_GOLD if arms_g[i] else COIN_SILVER
        arms.append((arms_n[i], coin, arms_g[i] + arms_s[i]))

    armor_n = parse_string_array(
        src, "static const char* const kNames[14] = {")
    armor_g = parse_int_array(src, "static const int kGold[14] = {")
    if not (len(armor_n) == len(armor_g) == 14):
        die("armor arrays disagree: %d %d"
            % (len(armor_n), len(armor_g)))
    armor = [(armor_n[i], COIN_GOLD, armor_g[i]) for i in range(14)]

    gen_n = parse_string_array(
        src, "static const char* const kNames[99] = {")
    gen_g = parse_int_array(src, "static const int kGold[99] = {")
    gen_s = parse_int_array(src, "static const int kSilver[99] = {")
    gen_c = parse_int_array(src, "static const int kCopper[99] = {")
    if not (len(gen_n) == len(gen_g) == len(gen_s)
            == len(gen_c) == 99):
        die("general arrays disagree: %d %d %d %d"
            % (len(gen_n), len(gen_g), len(gen_s), len(gen_c)))
    general = []
    for i in range(99):
        nz = (gen_g[i] != 0) + (gen_s[i] != 0) + (gen_c[i] != 0)
        if nz != 1:
            die("general row %d has %d nonzero coin columns"
                % (i, nz))
        if gen_g[i]:
            general.append((gen_n[i], COIN_GOLD, gen_g[i]))
        elif gen_s[i]:
            general.append((gen_n[i], COIN_SILVER, gen_s[i]))
        else:
            general.append((gen_n[i], COIN_COPPER, gen_c[i]))
    ngold = sum(1 for r in general if r[1] == COIN_GOLD)
    nsilver = sum(1 for r in general if r[1] == COIN_SILVER)
    ncopper = sum(1 for r in general if r[1] == COIN_COPPER)
    if (ngold, nsilver, ncopper) != (59, 29, 11):
        die("general coin split %d/%d/%d (the print: 59/29/11)"
            % (ngold, nsilver, ncopper))

    counts = parse_int_array(src, "static const int kCounts[8] = {")
    firsts = parse_int_array(src, "static const int kFirst[8] = {")
    if len(counts) != 8 or len(firsts) != 8:
        die("list structure arrays are not 8-wide")
    if sum(counts) != 99:
        die("list counts sum %d (the print: 99)" % sum(counts))
    for l in range(8):
        if firsts[l] + counts[l] != (
                firsts[l + 1] if l < 7 else 99):
            die("list %d first/counts chain breaks" % l)

    print("parsed: arms %d, armor %d, general %d "
          "(gold %d, silver %d, copper %d)"
          % (len(arms), len(armor), len(general),
             ngold, nsilver, ncopper))
    return arms, armor, general, counts, firsts


# ---------------------------------------------------------------------------
# lua emission
LUA_ROW = (
    '    { name = "%s", set = "%s", band = { %d, %d }, '
    'xp = 0, xp_hi = 0, gp = %d, gp_hi = 0, '
    'qty = { %d, 0 } },\n')

HDR = (
    "-- equipment table def: %s\n"
    "-- The PHB BASIC EQUIPMENT AND SUPPLIES COSTS tables, the\n"
    "-- R1042 de-wire: the printed price rows in print order.\n"
    "-- band = { i, i } the printed row index; gp = the printed\n"
    "-- price in its printed coin; qty = { coin, 0 } the coin\n"
    "-- code (1 copper, 2 silver, 3 gold - exactly one coin\n"
    "-- nonzero per row, the R300a identity). The clamp and\n"
    "-- accessor semantics live in rules/phb/equipcosts.h and\n"
    "-- are unchanged.\n"
    "-- DO NOT hand-edit: tools/r1042_splice.py is the only writer.\n"
    "\n")


def lua_file(key, title, rows):
    body = "".join(
        LUA_ROW % (r[0], key, i, i, r[2], r[1])
        for i, r in enumerate(rows))
    return (
        HDR % key +
        "return {\n"
        '  key = "%s",\n'
        '  name = "%s",\n'
        "  rows = {\n"
        "%s"
        "  },\n"
        "  sources = {\n"
        "    { part = 0, round = 1042 },\n"
        "  },\n"
        "  pins = {\n"
        '    { name = "%sRowCount", value = %d, '
        'comment = "the printed row count" },\n'
        "  },\n"
        "  tables = {},\n"
        "}\n"
        % (key, title, body, key, len(rows)))


def lua_general(key, title, rows, counts, firsts):
    body = "".join(
        LUA_ROW % (r[0], key, i, i, r[2], r[1])
        for i, r in enumerate(rows))
    cs = ", ".join(str(c) for c in counts)
    fs = ", ".join(str(f) for f in firsts)
    return (
        HDR % key +
        "return {\n"
        '  key = "%s",\n'
        '  name = "%s",\n'
        "  rows = {\n"
        "%s"
        "  },\n"
        "  sources = {\n"
        "    { part = 0, round = 1042 },\n"
        "  },\n"
        "  pins = {\n"
        '    { name = "%sRowCount", value = %d, '
        'comment = "the printed row count" },\n'
        '    { name = "%sCoinSplit", value = %d, '
        'comment = "packed coin split: cp*1000000 + sp*1000 + gp" },\n'
        "  },\n"
        "  tables = {\n"
        '    { name = "list_counts", values = { %s },\n'
        '      comment = "rows per list, lists 0-7" },\n'
        '    { name = "list_first", values = { %s },\n'
        '      comment = "first row of each list, lists 0-7" },\n'
        "  },\n"
        "}\n"
        % (key, title, body, key, len(rows), key,
           11 * 1000000 + 29 * 1000 + 59, cs, fs))


# ---------------------------------------------------------------------------
# round-trip check: parse the emitted lua back and compare
RT_ROW = re.compile(
    r'\{ name = "([^"]+)", set = "([^"]+)", band = \{ (\d+), (\d+) \}, '
    r'xp = 0, xp_hi = 0, gp = (\d+), gp_hi = 0, '
    r'qty = \{ (\d+), 0 \} \},')


def roundtrip(key, rows, text):
    got = RT_ROW.findall(text)
    if len(got) != len(rows):
        die("%s round-trip: %d rows, want %d"
            % (key, len(got), len(rows)))
    for i, g in enumerate(got):
        want = (rows[i][0], key, str(i), str(i),
                str(rows[i][2]), str(rows[i][1]))
        if g != want:
            die("%s round-trip row %d: %s != %s" % (key, i, g, want))


# ---------------------------------------------------------------------------
# seam rewrite: replace each accessor body between its signature
# line and the next column-0 closing brace
SIGS = [
    "inline int eqcArmsCount() {",
    "inline const char* eqcArmsName(int i) {",
    "inline int eqcArmsGold(int i) {",
    "inline int eqcArmsSilver(int i) {",
    "inline int eqcArmorCount() {",
    "inline const char* eqcArmorName(int i) {",
    "inline int eqcArmorGold(int i) {",
    "inline int eqcGeneralCount() {",
    "inline int eqcGeneralListCount(int l) {",
    "inline int eqcGeneralFirst(int l) {",
    "inline const char* eqcGeneralName(int i) {",
    "inline int eqcGeneralGold(int i) {",
    "inline int eqcGeneralSilver(int i) {",
    "inline int eqcGeneralCopper(int i) {",
]


def body_region(src, sig):
    if src.count(sig) != 1:
        die("signature %r appears %d times"
            % (sig, src.count(sig)))
    start = src.index(sig)
    end = src.index("\n}\n", start)
    return start, end + 3   # include the closing brace line


VIEW_NAME = (
    "    const auto& rows = eqView(\"%s\");\n"
    "    if (rows.empty()) return \"\";   // defensive: unloaded view\n"
    "    if (i < 0) i = 0;\n"
    "    if (i >= (int)rows.size()) i = (int)rows.size() - 1;\n"
    "    return rows[i].name.c_str();\n")

VIEW_COIN = (
    "    const auto& rows = eqView(\"%s\");\n"
    "    if (rows.empty()) return 0;   // defensive: unloaded view\n"
    "    if (i < 0) i = 0;\n"
    "    if (i >= (int)rows.size()) i = (int)rows.size() - 1;\n"
    "    return rows[i].qtyLo == %d ? rows[i].gp : 0;\n")


def new_bodies(counts, firsts):
    return {
        "inline int eqcArmsCount() {":
            "inline int eqcArmsCount() {\n"
            "    // the two printed columns together, alphabetical\n"
            "    return (int)eqView(\"%s\").size();\n}\n" % ARMS,
        "inline const char* eqcArmsName(int i) {":
            "inline const char* eqcArmsName(int i) {\n"
            + VIEW_NAME % ARMS + "}\n",
        "inline int eqcArmsGold(int i) {":
            "inline int eqcArmsGold(int i) {\n"
            + VIEW_COIN % (ARMS, COIN_GOLD) + "}\n",
        "inline int eqcArmsSilver(int i) {":
            "inline int eqcArmsSilver(int i) {\n"
            + VIEW_COIN % (ARMS, COIN_SILVER) + "}\n",
        "inline int eqcArmorCount() {":
            "inline int eqcArmorCount() {\n"
            "    // the two printed columns together, alphabetical\n"
            "    return (int)eqView(\"%s\").size();\n}\n" % ARMOR,
        "inline const char* eqcArmorName(int i) {":
            "inline const char* eqcArmorName(int i) {\n"
            + VIEW_NAME % ARMOR + "}\n",
        "inline int eqcArmorGold(int i) {":
            "inline int eqcArmorGold(int i) {\n"
            "    // every armor row prints in gold\n"
            + VIEW_COIN % (ARMOR, COIN_GOLD) + "}\n",
        "inline int eqcGeneralCount() {":
            "inline int eqcGeneralCount() {\n"
            "    return (int)eqView(\"%s\").size();\n}\n" % GENERAL,
        "inline int eqcGeneralListCount(int l) {":
            "inline int eqcGeneralListCount(int l) {\n"
            "    if (l < 0) l = 0;\n"
            "    if (l > 7) l = 7;\n"
            "    const auto* d = eqReg().find(\"%s\");\n"
            "    if (!d) return 0;   // defensive: unloaded view\n"
            "    for (const auto& t : d->tables)\n"
            "        if (t.name == \"list_counts\")\n"
            "            return (int)t.values[l];\n"
            "    return 0;\n}\n" % GENERAL,
        "inline int eqcGeneralFirst(int l) {":
            "inline int eqcGeneralFirst(int l) {\n"
            "    if (l < 0) l = 0;\n"
            "    if (l > 7) l = 7;\n"
            "    const auto* d = eqReg().find(\"%s\");\n"
            "    if (!d) return 0;   // defensive: unloaded view\n"
            "    for (const auto& t : d->tables)\n"
            "        if (t.name == \"list_first\")\n"
            "            return (int)t.values[l];\n"
            "    return 0;\n}\n" % GENERAL,
        "inline const char* eqcGeneralName(int i) {":
            "inline const char* eqcGeneralName(int i) {\n"
            + VIEW_NAME % GENERAL + "}\n",
        "inline int eqcGeneralGold(int i) {":
            "inline int eqcGeneralGold(int i) {\n"
            "    // the 59 gold rows\n"
            + VIEW_COIN % (GENERAL, COIN_GOLD) + "}\n",
        "inline int eqcGeneralSilver(int i) {":
            "inline int eqcGeneralSilver(int i) {\n"
            "    // the 29 silver rows\n"
            + VIEW_COIN % (GENERAL, COIN_SILVER) + "}\n",
        "inline int eqcGeneralCopper(int i) {":
            "inline int eqcGeneralCopper(int i) {\n"
            "    // the 11 copper rows\n"
            + VIEW_COIN % (GENERAL, COIN_COPPER) + "}\n",
    }


SEAM = (
    "// ---- the R1042 registry seam ----------------------------------------\n"
    "// The three price families (arms, armor, general) ride\n"
    "// items::MiscItemRegistry from content/tables/equipment/\n"
    "// (set names = def keys; one row per printed row: the band\n"
    "// carries the printed row index { i, i }, gp the printed\n"
    "// price in its printed coin, and qty the coin code\n"
    "// { 1 copper, 2 silver, 3 gold, 0 }). This seam is\n"
    "// header-only like the module: the registry rides its own\n"
    "// inline singleton (the R1040 appendixp.h idiom - a\n"
    "// file-static is out of reach from a header). Every\n"
    "// signature below is unchanged (the R300/R300a/R308\n"
    "// audits and the town stores pin them); the clamp\n"
    "// semantics stay verbatim.\n"
    "\n"
    "inline items::MiscItemRegistry& eqReg() {\n"
    "    static items::MiscItemRegistry reg;\n"
    "    static bool loaded = false;\n"
    "    if (!loaded) {\n"
    "        loaded = true;\n"
    "        reg.loadDirectory(\"content/tables/equipment\");\n"
    "    }\n"
    "    return reg;\n"
    "}\n"
    "\n"
    "// the registry-backed per-view cache (the R1032-R1041\n"
    "// idiom; function-local statics in inline functions are\n"
    "// shared across TUs)\n"
    "inline const std::vector<items::MiscItemRow>& eqView(\n"
    "        const char* name) {\n"
    "    static std::map<std::string,\n"
    "        std::vector<items::MiscItemRow>> cache;\n"
    "    auto it = cache.find(name);\n"
    "    if (it == cache.end()) {\n"
    "        const items::MiscItemDef* d = eqReg().find(name);\n"
    "        it = cache.emplace(\n"
    "            name, d ? d->rows\n"
    "                   : std::vector<items::MiscItemRow>()).first;\n"
    "    }\n"
    "    return it->second;\n"
    "}\n"
    "\n")


def rewrite_header(src, counts, firsts):
    # the R1042 module note in the header banner
    src = replace_once(
        src,
        "// DATA-DRIVEN (the standing scope).\n",
        "// DATA-DRIVEN (the standing scope).\n"
        "//\n"
        "// R1042: the price rows are registry-native\n"
        "// (content/tables/equipment/, the seam below); the\n"
        "// printed arrays are gone from this header and the\n"
        "// accessors read registry views. The monetary pins\n"
        "// stay in-file (constants, not tables).\n",
        "banner note")

    src = replace_once(
        src,
        "#pragma once\n\nnamespace rules {",
        "#pragma once\n\n"
        "#include \"items/MiscItemRegistry.h\"   "
        "// R1042: the price tables ride the registry\n"
        "\nnamespace rules {\n\n" + SEAM,
        "include + seam")

    bodies = new_bodies(counts, firsts)
    for sig in SIGS:
        start, end = body_region(src, sig)
        src = src[:start] + bodies[sig] + src[end:]

    retired = ["kNames[52]", "kGold[52]", "kSilver[52]",
               "kNames[14]", "kGold[14]", "kNames[99]",
               "kGold[99]", "kSilver[99]", "kCopper[99]",
               "kCounts[8]", "kFirst[8]",
               "static const char* const kNames",
               "static const int k"]
    for tok in retired:
        if tok in src:
            die("retired token %r still present" % tok)
    return src


# ---------------------------------------------------------------------------
# fragment
def find_idx(rows, name):
    for i, r in enumerate(rows):
        if r[0] == name:
            return i
    die("fragment: row %r not found" % name)
    return -1


def pin_accessors(what, calls):
    return "".join(
        "            if (%s) ++bad;\n" % c for c in calls)


def build_fragment(arms, armor, general, counts, firsts):
    def gidx(name):
        return find_idx(general, name)

    def aidx(name):
        return find_idx(arms, name)

    L = []
    a = L.append
    a("    // ==== R1042: equipment cost registry =====================================\n")
    a("    // The R1042 de-wire: the PHB equipment price tables\n")
    a("    // (52 arms, 14 armor, 99 general rows) ride\n")
    a("    // items::MiscItemRegistry from content/tables/\n")
    a("    // equipment/ (set names = def keys); this audit\n")
    a("    // loads its own registry instance and cross-reads\n")
    a("    // every row through the inline accessor surface\n")
    a("    // (eqc* in rules/phb/equipcosts.h), so the\n")
    a("    // R300/R300a/R308 audits and this registry audit\n")
    a("    // read the same data.\n")
    a("    {\n")
    a("        int bad = 0;\n")
    a("        // -- 1. load --------------------------------------\n")
    a("        {\n")
    a("            items::MiscItemRegistry t;\n")
    a('            if (t.loadDirectory("content/tables/equipment") != 3)\n')
    a("                ++bad;\n")
    a("            if (!t.errors().empty()) ++bad;\n")
    a("            if (t.all().size() != 3) ++bad;\n")
    a('            if (t.all().count("equipment_arms") != 1) ++bad;\n')
    a('            if (t.all().count("equipment_armor") != 1) ++bad;\n')
    a('            if (t.all().count("equipment_general") != 1) ++bad;\n')
    a('            if (t.all().count("equipment_clothing")) ++bad;\n')
    a('            if (t.all().count("treasure_potions")) ++bad;\n')
    a('            if (t.all().count("appendixp_kit")) ++bad;\n')
    a('            if (t.all().count("equipment_arms_rows")) ++bad;\n')
    a("        }\n")
    a('        printf("R1042 equipment cost registry load audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    a("        // -- 2. counts -------------------------------------\n")
    a("        {\n")
    a('            if (rules::eqcArmsCount() != 52) ++bad;\n')
    a('            if (rules::eqcArmorCount() != 14) ++bad;\n')
    a('            if (rules::eqcGeneralCount() != 99) ++bad;\n')
    a("            items::MiscItemRegistry t;\n")
    a('            t.loadDirectory("content/tables/equipment");\n')
    a('            const auto* d = t.find("equipment_general");\n')
    a("            if (!d) ++bad;\n")
    a("            else {\n")
    a("                int cg = 0, cs = 0, cc = 0;\n")
    a("                for (const auto& r : d->rows) {\n")
    a("                    if (r.qtyLo == 3) ++cg;\n")
    a("                    if (r.qtyLo == 2) ++cs;\n")
    a("                    if (r.qtyLo == 1) ++cc;\n")
    a("                }\n")
    a("                if (cg != 59 || cs != 29 || cc != 11) ++bad;\n")
    a("                const items::MiscItemTable* tc = nullptr;\n")
    a("                const items::MiscItemTable* tf = nullptr;\n")
    a('                for (const auto& tb : d->tables) {\n')
    a('                    if (tb.name == "list_counts") tc = &tb;\n')
    a('                    if (tb.name == "list_first") tf = &tb;\n')
    a("                }\n")
    a("                if (!tc || (int)tc->values.size() != 8) ++bad;\n")
    a("                if (!tf || (int)tf->values.size() != 8) ++bad;\n")
    a("                if ((int)d->pins.size() != 2) ++bad;\n")
    a("                else {\n")
    a('                    if (d->pins[0].name\n')
    a('                            != std::string("equipment_generalRowCount")\n')
    a("                        || d->pins[0].value != 99) ++bad;\n")
    a('                    if (d->pins[1].name\n')
    a('                            != std::string("equipment_generalCoinSplit")\n')
    a("                        || d->pins[1].value != 11029059LL) ++bad;\n")
    a("                }\n")
    a("                if (tc && tf) {\n")
    a("                    for (int l = 0; l < 8; ++l) {\n")
    a("                        if (rules::eqcGeneralListCount(l)\n")
    a("                                != (int)tc->values[l]) ++bad;\n")
    a("                        if (rules::eqcGeneralFirst(l)\n")
    a("                                != (int)tf->values[l]) ++bad;\n")
    a("                    }\n")
    a("                }\n")
    a("            }\n")
    a('            const auto* da = t.find("equipment_arms");\n')
    a('            if (!da || (int)da->rows.size() != 52) ++bad;\n')
    a('            if (da && ((int)da->pins.size() != 1\n')
    a('                       || da->pins[0].name\n')
    a('                              != std::string("equipment_armsRowCount")\n')
    a("                       || da->pins[0].value != 52)) ++bad;\n")
    a('            const auto* dr = t.find("equipment_armor");\n')
    a('            if (!dr || (int)dr->rows.size() != 14) ++bad;\n')
    a('            if (dr && ((int)dr->pins.size() != 1\n')
    a('                       || dr->pins[0].name\n')
    a('                              != std::string("equipment_armorRowCount")\n')
    a("                       || dr->pins[0].value != 14)) ++bad;\n")
    a("        }\n")
    a('        printf("R1042 equipment cost registry counts audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    a("        // -- 3. bands (the row-index axis) ----------------\n")
    a("        {\n")
    a("            items::MiscItemRegistry t;\n")
    a('            t.loadDirectory("content/tables/equipment");\n')
    a("            for (const char* key : {\"equipment_arms\",\n")
    a("                                   \"equipment_armor\",\n")
    a('                                   "equipment_general"}) {\n')
    a("                const auto* d = t.find(key);\n")
    a("                if (!d) { ++bad; continue; }\n")
    a("                const int n = (int)d->rows.size();\n")
    a("                for (int i = 0; i < n; ++i)\n")
    a("                    if (d->rows[i].bandLo != i\n")
    a("                        || d->rows[i].bandHi != i\n")
    a("                        || d->rows[i].set != std::string(key)\n")
    a("                        || d->rows[i].qtyLo < 1\n")
    a("                        || d->rows[i].qtyLo > 3\n")
    a("                        || d->rows[i].qtyHi != 0\n")
    a("                        || d->rows[i].xp != 0\n")
    a("                        || d->rows[i].xpHi != 0\n")
    a("                        || d->rows[i].gpHi != 0\n")
    a("                        || d->rows[i].gp <= 0) ++bad;\n")
    a("            }\n")
    a("        }\n")
    a('        printf("R1042 equipment cost registry bands audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    a("        // -- 4. data (famous rows via the accessors) ------\n")
    a("        {\n")

    def acc_int(calls):
        for c in calls:
            a("            if (%s) ++bad;\n" % c)

    # famous arms rows (values from the parsed arrays)
    fam_arms = [
        "arrow, normal, single", "arrow, normal, dozen",
        "bow, composite, long", "dagger and scabbard",
        "javelin", "bastard sword and scabbard",
        "long sword and scabbard", "two-handed sword",
    ]
    calls = []
    for nm in fam_arms:
        i = aidx(nm)
        coin, amt = arms[i][1], arms[i][2]
        acc = "Gold" if coin == COIN_GOLD else "Silver"
        calls.append('rules::eqcArmsName(%d) != std::string("%s")'
                     % (i, nm))
        calls.append("rules::eqcArms%s(%d) != %d" % (acc, i, amt))
        other = "Silver" if coin == COIN_GOLD else "Gold"
        calls.append("rules::eqcArms%s(%d) != 0" % (other, i))
    acc_int(calls)
    a("            if (rules::eqcArmorName(0) != std::string(\"banded\"))\n")
    a("                ++bad;\n")
    a("            if (rules::eqcArmorGold(0) != 90) ++bad;\n")
    a("            if (rules::eqcArmorGold(6) != 400) ++bad;\n")
    a("            if (rules::eqcArmorName(6) != std::string(\"plate\"))\n")
    a("                ++bad;\n")
    fam_gen = [
        ("belt", 2, 3),          # (name, coin, amount) checked below
        ("ale, pint", 2, 1),
        ("garlic, bud", 1, 5),
        ("wolvesbane, sprig", 2, 10),
        ("horse, heavy war", 3, 300),
        ("symbol, holy, silver", 3, 50),
        ("ship, war", 3, 20000),
        ("wagon", 3, 150),
    ]
    calls = []
    for nm, coin, amt in fam_gen:
        i = gidx(nm)
        if general[i][1] != coin or general[i][2] != amt:
            die("fragment famous row %r: source says coin %d amt %d"
                % (nm, general[i][1], general[i][2]))
        acc = {1: "Copper", 2: "Silver", 3: "Gold"}[coin]
        calls.append('rules::eqcGeneralName(%d) != std::string("%s")'
                     % (i, nm))
        calls.append("rules::eqcGeneral%s(%d) != %d" % (acc, i, amt))
    acc_int(calls)
    a("        }\n")
    a('        printf("R1042 equipment cost registry data audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    a("        // -- 5. rows (full cross-read) --------------------\n")
    a("        {\n")
    a("            items::MiscItemRegistry t;\n")
    a('            t.loadDirectory("content/tables/equipment");\n')
    a('            const auto* da = t.find("equipment_arms");\n')
    a("            if (da) {\n")
    a("                for (int i = 0; i < 52; ++i) {\n")
    a('                    if (rules::eqcArmsName(i) != da->rows[i].name)\n')
    a("                        ++bad;\n")
    a("                    const int g = rules::eqcArmsGold(i);\n")
    a("                    const int s = rules::eqcArmsSilver(i);\n")
    a("                    if (da->rows[i].qtyLo == 3\n")
    a("                        ? (g != da->rows[i].gp || s != 0)\n")
    a("                        : (g != 0 || s != da->rows[i].gp))\n")
    a("                        ++bad;\n")
    a("                }\n")
    a("            } else ++bad;\n")
    a('            const auto* dr = t.find("equipment_armor");\n')
    a("            if (dr) {\n")
    a("                for (int i = 0; i < 14; ++i) {\n")
    a('                    if (rules::eqcArmorName(i) != dr->rows[i].name)\n')
    a("                        ++bad;\n")
    a("                    if (rules::eqcArmorGold(i)\n")
    a("                            != (dr->rows[i].qtyLo == 3\n")
    a("                                ? dr->rows[i].gp : 0))\n")
    a("                        ++bad;\n")
    a("                }\n")
    a("            } else ++bad;\n")
    a('            const auto* dg = t.find("equipment_general");\n')
    a("            if (dg) {\n")
    a("                for (int i = 0; i < 99; ++i) {\n")
    a('                    if (rules::eqcGeneralName(i) != dg->rows[i].name)\n')
    a("                        ++bad;\n")
    a("                    const int q = dg->rows[i].qtyLo;\n")
    a("                    const int v = dg->rows[i].gp;\n")
    a("                    if (rules::eqcGeneralGold(i)   != (q == 3 ? v : 0)\n")
    a("                        || rules::eqcGeneralSilver(i)\n")
    a("                               != (q == 2 ? v : 0)\n")
    a("                        || rules::eqcGeneralCopper(i)\n")
    a("                               != (q == 1 ? v : 0))\n")
    a("                        ++bad;\n")
    a("                }\n")
    a("            } else ++bad;\n")
    a("        }\n")
    a('        printf("R1042 equipment cost registry rows audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    a("        // -- 6. edges (clamps) ----------------------------\n")
    a("        {\n")
    a("            if (rules::eqcArmsName(-1) != rules::eqcArmsName(0))\n")
    a("                ++bad;\n")
    a("            if (rules::eqcArmsName(999) != rules::eqcArmsName(51))\n")
    a("                ++bad;\n")
    a("            if (rules::eqcArmsGold(999) != rules::eqcArmsGold(51))\n")
    a("                ++bad;\n")
    a("            if (rules::eqcArmorGold(-3) != rules::eqcArmorGold(0))\n")
    a("                ++bad;\n")
    a("            if (rules::eqcGeneralName(-1)\n")
    a("                    != rules::eqcGeneralName(0))\n")
    a("                ++bad;\n")
    a("            if (rules::eqcGeneralCopper(9999)\n")
    a("                    != rules::eqcGeneralCopper(98))\n")
    a("                ++bad;\n")
    a("            if (rules::eqcGeneralListCount(-1) != 11) ++bad;\n")
    a("            if (rules::eqcGeneralListCount(8) != 10) ++bad;\n")
    a("            if (rules::eqcGeneralFirst(-1) != 0) ++bad;\n")
    a("            if (rules::eqcGeneralFirst(99) != 89) ++bad;\n")
    a("            if (rules::eqcSilverPerGold() != 20) ++bad;\n")
    a("            if (rules::eqcCopperPerSilver() != 10) ++bad;\n")
    a("            if (rules::eqcCopperPerGold() != 200) ++bad;\n")
    a("        }\n")
    a('        printf("R1042 equipment cost registry edges audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("    }\n")
    return "".join(L)


# ---------------------------------------------------------------------------
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
    if not os.path.exists(EQ):
        die("run from the repo root (%s missing)" % EQ)

    marker = os.path.join(DIR, ARMS + ".lua")
    seam_mark = "R1042 registry seam"
    already = os.path.exists(marker) and seam_mark in open(EQ).read()
    if already:
        print("applied 0, already 1")
        print("SPLICE OK")
        return

    src = open(EQ).read()
    arms, armor, general, counts, firsts = parse_all(src)

    os.makedirs(DIR, exist_ok=True)
    files = {
        ARMS + ".lua": lua_file(ARMS, "Equipment arms list (52 rows)",
                                arms),
        ARMOR + ".lua": lua_file(ARMOR, "Equipment armor list (14 rows)",
                                 armor),
        GENERAL + ".lua": lua_general(
            GENERAL, "Equipment general lists (99 rows)",
            general, counts, firsts),
    }
    for name, text in files.items():
        open(os.path.join(DIR, name), "w").write(text)

    roundtrip(ARMS, arms, files[ARMS + ".lua"])
    roundtrip(ARMOR, armor, files[ARMOR + ".lua"])
    roundtrip(GENERAL, general, files[GENERAL + ".lua"])
    print("round-trip: 3 lua files parse back byte-exact")

    new_src = rewrite_header(src, counts, firsts)
    open(EQ, "w").write(new_src)

    frag = build_fragment(arms, armor, general, counts, firsts)
    open("rules/audits/r1042_equipment_cost_registry.h", "w").write(frag)

    reg = open("regtest.cpp").read()
    anchor = ('    #include "rules/audits/r1041_treasure_item_registry.h"'
              '  // R1041\n')
    reg = replace_once(
        reg, anchor,
        anchor +
        '    #include "rules/audits/r1042_equipment_cost_registry.h"'
        '  // R1042\n',
        "regtest include")
    open("regtest.cpp", "w").write(reg)

    c = census()
    print("census: %d -> %d audit printf patterns"
          % (CENSUS_BEFORE, CENSUS_AFTER))
    if c != CENSUS_AFTER:
        die("census %d, expected %d" % (c, CENSUS_AFTER))

    print("applied 1, rewrote 2 tracked files, wrote 5 new files")
    print("SPLICE OK")


main()
