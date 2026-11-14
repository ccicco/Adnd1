#!/usr/bin/env python3
# r1043_splice.py - the R1043 splice tool: retire the PHB
# weapon weight and damage tables from rules/phb/weapontables.h
# into NEW dir content/tables/weapons/ (7 lua, the
# items::MiscItemRow schema), and rewire the chart, speed and
# class-allowlist accessors onto registry views. The combat
# note constants, the oil/poison columns and the class
# dispatch mechanics stay in-file (constants and code, not
# tables).
#
# Row encoding (named in the lua headers and the seam):
#   weapon_chart (50):  band = { i, i } the print row index;
#                      gp  = the printed weight in gold
#                            pieces (the spear minimum 40);
#                      qty = { S-M damage min, S-M max };
#                      xp/xp_hi = the L damage min/max;
#                      gp_hi = 0.
#   weapon_speed (18):  band = { i, i }; gp = the printed
#                      speed factor; the rest zero.
#   weapon_cleric (7), weapon_druid (9),
#   weapon_mu_illusionist (3), weapon_thief (8),
#   weapon_monk (24):  name-only rows, band = { i, i }.
#
# Idempotent: a second run reports "already 1".
import os
import re
import sys

ROOT = os.getcwd()
CENSUS_BEFORE = 1016
CENSUS_AFTER = 1022
WT = "rules/phb/weapontables.h"
DIR = "content/tables/weapons"

CHART = "weapon_chart"
SPEED = "weapon_speed"
CLERIC = "weapon_cleric"
DRUID = "weapon_druid"
MUILL = "weapon_mu_illusionist"
THIEF = "weapon_thief"
MONK = "weapon_monk"


def die(msg):
    sys.stderr.write("r1043_splice: FATAL: %s\n" % msg)
    sys.exit(1)


def replace_once(src, old, new, what):
    n = src.count(old)
    if n != 1:
        die("%s anchor appears %d times (expected 1)" % (what, n))
    return src.replace(old, new)


# ---------------------------------------------------------------------------
# region helpers: accessor signature -> the column-0 closing brace
def body_region(src, sig):
    if src.count(sig) != 1:
        die("signature %r appears %d times"
            % (sig, src.count(sig)))
    start = src.index(sig)
    end = src.index("\n}\n", start)
    return start, end + 3


def region_of(src, sig):
    start, end = body_region(src, sig)
    return src[start:end]


def parse_strings(block, decl):
    if block.count(decl) != 1:
        die("%s appears %d times inside accessor"
            % (decl, block.count(decl)))
    d = block.index(decl) + len(decl)
    e = block.index("};", d)
    return re.findall(r'"([^"]*)"', block[d:e])


def parse_ints(block, decl):
    if block.count(decl) != 1:
        die("%s appears %d times inside accessor"
            % (decl, block.count(decl)))
    d = block.index(decl) + len(decl)
    e = block.index("};", d)
    return [int(x) for x in re.findall(r"-?\d+", block[d:e])]


def parse_all(src):
    blk = region_of(src, "inline const char* weaponChartName(int i) {")
    names = parse_strings(blk, "static const char* const kNames[50] = {")

    blk = region_of(src, "inline int weaponChartWeight(int i) {")
    weight = parse_ints(blk, "static const int kWeight[50] = {")

    blk = region_of(src, "inline int weaponChartDamageSMMin(int i) {")
    sm_lo = parse_ints(blk, "static const int kMin[50] = {")
    blk = region_of(src, "inline int weaponChartDamageSMMax(int i) {")
    sm_hi = parse_ints(blk, "static const int kMax[50] = {")
    blk = region_of(src, "inline int weaponChartDamageLMin(int i) {")
    l_lo = parse_ints(blk, "static const int kMin[50] = {")
    blk = region_of(src, "inline int weaponChartDamageLMax(int i) {")
    l_hi = parse_ints(blk, "static const int kMax[50] = {")

    n = 50
    if not all(len(x) == n for x in
               [names, weight, sm_lo, sm_hi, l_lo, l_hi]):
        die("chart arrays disagree: %d %d %d %d %d %d"
            % tuple(len(x) for x in
                    [names, weight, sm_lo, sm_hi, l_lo, l_hi]))
    chart = []
    for i in range(n):
        if not (sm_lo[i] <= sm_hi[i]):
            die("chart row %d: S-M pair %d-%d" % (i, sm_lo[i], sm_hi[i]))
        if not (l_lo[i] <= l_hi[i]):
            die("chart row %d: L pair %d-%d" % (i, l_lo[i], l_hi[i]))
        if weight[i] <= 0:
            die("chart row %d: weight %d" % (i, weight[i]))
        chart.append((names[i], weight[i], sm_lo[i], sm_hi[i],
                      l_lo[i], l_hi[i]))

    blk = region_of(src,
                    "inline const char* weaponSpeedVerifiedName(int i) {")
    snames = parse_strings(blk, "static const char* const kNames[18] = {")
    blk = region_of(src, "inline int weaponSpeedVerifiedFactor(int i) {")
    sfact = parse_ints(blk, "static const int kFactor[18] = {")
    if not (len(snames) == len(sfact) == 18):
        die("speed arrays disagree: %d %d"
            % (len(snames), len(sfact)))
    speed = [(snames[i], sfact[i]) for i in range(18)]

    lists = {
        CLERIC: parse_strings(src, "static const char* const kCleric[7] = {"),
        DRUID: parse_strings(src, "static const char* const kDruid[9] = {"),
        MUILL: parse_strings(src, "static const char* const kMuIll[3] = {"),
        THIEF: parse_strings(src, "static const char* const kThief[8] = {"),
        MONK: parse_strings(src, "static const char* const kMonk[24] = {"),
    }
    want = {CLERIC: 7, DRUID: 9, MUILL: 3, THIEF: 8, MONK: 24}
    for k, v in lists.items():
        if len(v) != want[k]:
            die("list %s has %d rows, want %d" % (k, len(v), want[k]))

    # the class-count accessor reads view sizes after the splice;
    # the fragment pins its outputs

    print("parsed: chart 50, speed 18, lists 7/9/3/8/24")
    return chart, speed, lists


# ---------------------------------------------------------------------------
# lua emission
HDR = (
    "-- weapon table def: %s\n"
    "-- The PHB weapon tables, the R1043 de-wire. %s\n"
    "-- Row encoding: band = { i, i } the printed row index.\n"
    "-- The accessor and clamp semantics live in\n"
    "-- rules/phb/weapontables.h and are unchanged.\n"
    "-- DO NOT hand-edit: tools/r1043_splice.py is the only writer.\n"
    "\n")

LUA_ROW = (
    '    { name = "%s", set = "%s", band = { %d, %d }, '
    'xp = %d, xp_hi = %d, gp = %d, gp_hi = %d, '
    'qty = { %d, %d } },\n')


def lua_def(key, title, note, rows):
    for i, r in enumerate(rows):
        if len(r) != 6:
            die("lua_def %s row %d: %d-tuple, want 6" % (key, i, len(r)))
    body = "".join(
        LUA_ROW % (r[0], key, i, i, r[1], r[2], r[3], 0, r[4], r[5])
        for i, r in enumerate(rows))
    return (
        HDR % (key, note) +
        "return {\n"
        '  key = "%s",\n'
        '  name = "%s",\n'
        "  rows = {\n"
        "%s"
        "  },\n"
        "  sources = {\n"
        "    { part = 0, round = 1043 },\n"
        "  },\n"
        "  pins = {\n"
        '    { name = "%sRowCount", value = %d, '
        'comment = "the printed row count" },\n'
        "  },\n"
        "  tables = {},\n"
        "}\n"
        % (key, title, body, key, len(rows)))


# ---------------------------------------------------------------------------
# round-trip
RT_ROW = re.compile(
    r'\{ name = "([^"]+)", set = "([^"]+)", band = \{ (\d+), (\d+) \}, '
    r'xp = (-?\d+), xp_hi = (-?\d+), gp = (-?\d+), gp_hi = (-?\d+), '
    r'qty = \{ (-?\d+), (-?\d+) \} \},')


def roundtrip(key, rows, text):
    got = RT_ROW.findall(text)
    if len(got) != len(rows):
        die("%s round-trip: %d rows, want %d"
            % (key, len(got), len(rows)))
    for i, g in enumerate(got):
        r = rows[i]
        want = (r[0], key, str(i), str(i), str(r[1]), str(r[2]),
                str(r[3]), "0", str(r[4]), str(r[5]))
        if g != want:
            die("%s round-trip row %d: %s != %s" % (key, i, g, want))


# ---------------------------------------------------------------------------
# seam
SEAM = (
    "// ---- the R1043 registry seam ----------------------------------------\n"
    "// The weapon chart, the speed verify list and the five\n"
    "// class allowlists ride items::MiscItemRegistry from\n"
    "// content/tables/weapons/ (set names = def keys). Chart\n"
    "// row encoding: band = { i, i } the print row index,\n"
    "// gp the printed weight in gold pieces (the spear\n"
    "// minimum 40), qty the S-M damage pair, xp/xp_hi the L\n"
    "// damage pair. Speed rows pin the factor in gp; list\n"
    "// rows are name-only. This seam is header-only like the\n"
    "// module (the R1040/R1042 idiom); every signature below\n"
    "// is unchanged (the r158/r189/r198/r337 audits and the\n"
    "// combat engine pin them); the clamp semantics stay\n"
    "// verbatim.\n"
    "\n"
    "inline items::MiscItemRegistry& wtReg() {\n"
    "    static items::MiscItemRegistry reg;\n"
    "    static bool loaded = false;\n"
    "    if (!loaded) {\n"
    "        loaded = true;\n"
    "        reg.loadDirectory(\"content/tables/weapons\");\n"
    "    }\n"
    "    return reg;\n"
    "}\n"
    "\n"
    "// the registry-backed per-view cache (the R1032-R1042\n"
    "// idiom; function-local statics in inline functions are\n"
    "// shared across TUs)\n"
    "inline const std::vector<items::MiscItemRow>& wtView(\n"
    "        const char* name) {\n"
    "    static std::map<std::string,\n"
    "        std::vector<items::MiscItemRow>> cache;\n"
    "    auto it = cache.find(name);\n"
    "    if (it == cache.end()) {\n"
    "        const items::MiscItemDef* d = wtReg().find(name);\n"
    "        it = cache.emplace(\n"
    "            name, d ? d->rows\n"
    "                   : std::vector<items::MiscItemRow>()).first;\n"
    "    }\n"
    "    return it->second;\n"
    "}\n"
    "\n")

V_NAME = (
    "    const auto& rows = wtView(\"%s\");\n"
    "    if (rows.empty()) return \"\";   // defensive: unloaded view\n"
    "    if (i < 0) i = 0;\n"
    "    if (i >= (int)rows.size()) i = (int)rows.size() - 1;\n"
    "    return rows[i].name.c_str();\n")

V_INT = (
    "    const auto& rows = wtView(\"%s\");\n"
    "    if (rows.empty()) return 0;   // defensive: unloaded view\n"
    "    if (i < 0) i = 0;\n"
    "    if (i >= (int)rows.size()) i = (int)rows.size() - 1;\n"
    "    return rows[i].%s;\n")


def new_body(sig, body):
    return sig + "\n" + body + "}\n"


ACCESSORS = [
    ("inline int weaponChartRowCount() { return WEAPON_CHART_ROWS; }",
     "REPL_ONE"),
    ("inline const char* weaponChartName(int i) {",
     new_body("inline const char* weaponChartName(int i) {",
              V_NAME % CHART)),
    ("inline int weaponChartWeight(int i) {",
     new_body("inline int weaponChartWeight(int i) {",
              V_INT % (CHART, "gp"))),
    ("inline int weaponChartDamageSMMin(int i) {",
     new_body("inline int weaponChartDamageSMMin(int i) {",
              V_INT % (CHART, "qtyLo"))),
    ("inline int weaponChartDamageSMMax(int i) {",
     new_body("inline int weaponChartDamageSMMax(int i) {",
              V_INT % (CHART, "qtyHi"))),
    ("inline int weaponChartDamageLMin(int i) {",
     new_body("inline int weaponChartDamageLMin(int i) {",
              V_INT % (CHART, "xp"))),
    ("inline int weaponChartDamageLMax(int i) {",
     new_body("inline int weaponChartDamageLMax(int i) {",
              V_INT % (CHART, "xpHi"))),
    ("inline int weaponSpeedVerifiedCount() { return 18; }",
     "REPL_ONE_SPEED"),
    ("inline const char* weaponSpeedVerifiedName(int i) {",
     new_body("inline const char* weaponSpeedVerifiedName(int i) {",
              V_NAME % SPEED)),
    ("inline int weaponSpeedVerifiedFactor(int i) {",
     new_body("inline int weaponSpeedVerifiedFactor(int i) {",
              V_INT % (SPEED, "gp"))),
]


def rewrite_header(src):
    # banner note
    src = replace_once(
        src,
        "// DATA-DRIVEN (the standing scope).\n",
        "// DATA-DRIVEN (the standing scope).\n"
        "//\n"
        "// R1043: the chart, speed and allowlist rows are\n"
        "// registry-native (content/tables/weapons/, the seam\n"
        "// below); the printed arrays are gone from this\n"
        "// header and the accessors read registry views. The\n"
        "// combat note constants and the oil/poison columns\n"
        "// stay in-file (constants, not tables).\n",
        "banner note")

    # include + seam
    src = replace_once(
        src,
        "#include <cstdint>\n\nnamespace rules {",
        "#include <cstdint>\n\n"
        "#include \"items/MiscItemRegistry.h\"   "
        "// R1043: the weapon tables ride the registry\n"
        "\nnamespace rules {\n\n" + SEAM,
        "include + seam")

    # one-liner count accessors
    src = replace_once(
        src,
        "inline int weaponChartRowCount() { return WEAPON_CHART_ROWS; }",
        "inline int weaponChartRowCount() {\n"
        "    return (int)wtView(\"%s\").size();\n}\n" % CHART,
        "chart count")
    src = replace_once(
        src,
        "inline int weaponSpeedVerifiedCount() { return 18; }",
        "inline int weaponSpeedVerifiedCount() {\n"
        "    return (int)wtView(\"%s\").size();\n}\n" % SPEED,
        "speed count")

    # retire the file-scope constant
    src = replace_once(
        src,
        "static const int WEAPON_CHART_ROWS = 50;\n\n",
        "",
        "WEAPON_CHART_ROWS")

    # multi-line accessor bodies
    for sig, new in ACCESSORS:
        if new in ("REPL_ONE", "REPL_ONE_SPEED"):
            continue   # already replaced above
        start, end = body_region(src, sig)
        src = src[:start] + new + src[end:]

    # class count + name
    src = rewrite_class_accessors(src)

    # retire the file-scope allowlist arrays (decl through };)
    for decl in ["static const char* const kCleric[7] = {",
                 "static const char* const kDruid[9] = {",
                 "static const char* const kMuIll[3] = {",
                 "static const char* const kThief[8] = {",
                 "static const char* const kMonk[24] = {"]:
        if src.count(decl) != 1:
            die("%s appears %d times at file scope"
                % (decl, src.count(decl)))
        d = src.index(decl)
        ls = src.rfind("\n", 0, d) + 1   # the line start
        e = src.index("};\n", d) + 3
        src = src[:ls] + src[e:]
    # tidy any doubled blank lines the deletions left behind
    while "\n\n\n\n" in src:
        src = src.replace("\n\n\n\n", "\n\n\n")

    retired = ["WEAPON_CHART_ROWS", "kNames[50]", "kWeight[50]",
               "kMin[50]", "kMax[50]", "kNames[18]", "kFactor[18]",
               "kCleric[7]", "kDruid[9]", "kMuIll[3]", "kThief[8]",
               "kMonk[24]", "static const int k",
               "static const char* const k"]
    for tok in retired:
        if tok in src:
            die("retired token %r still present" % tok)
    return src


CLS_LIST_FOR = {0: CLERIC, 1: DRUID, 5: MUILL, 6: MUILL,
                7: THIEF, 9: MONK}
CLS_MAX = {0: 6, 1: 8, 5: 2, 6: 2, 7: 7, 9: 23}


def rewrite_class_accessors(src):
    cnt_body = (
        "inline int classAllowedWeaponCount(int cls) {\n"
        "    if (classUsesAnyWeapon(cls)) return -1;\n"
        "    switch (cls) {\n"
        "    case 0: return (int)wtView(\"%s\").size();   // cleric\n"
        "    case 1: return (int)wtView(\"%s\").size();   // druid\n"
        "    case 5: case 6:\n"
        "        return (int)wtView(\"%s\").size();  // MU, illusionist\n"
        "    case 7: return (int)wtView(\"%s\").size();   // thief\n"
        "    case 9: return (int)wtView(\"%s\").size();   // monk\n"
        "    default: return 0;\n"
        "    }\n"
        "}\n"
        % (CLERIC, DRUID, MUILL, THIEF, MONK))
    src = replace_region(src, "inline int classAllowedWeaponCount(int cls) {",
                         cnt_body)

    nm = (
        "inline const char* classAllowedWeaponName(int cls, int i) {\n"
        "    if (i < 0) i = 0;\n"
        "    const char* key = 0;\n"
        "    int n = 0;\n"
        "    switch (cls) {\n"
        "    case 0: key = \"%s\"; n = 7; break;   // cleric\n"
        "    case 1: key = \"%s\"; n = 9; break;   // druid\n"
        "    case 5: key = \"%s\"; n = 3; break;   // MU\n"
        "    case 6: key = \"%s\"; n = 3; break;   // illusionist\n"
        "    case 7: key = \"%s\"; n = 8; break;   // thief\n"
        "    case 9: key = \"%s\"; n = 24; break;   // monk\n"
        "    default: return \"club\";   // out-of-range clamps\n"
        "    }\n"
        "    const auto& rows = wtView(key);\n"
        "    if (rows.empty()) return \"club\";   // defensive\n"
        "    if (i >= n) i = n - 1;\n"
        "    if (i >= (int)rows.size()) i = (int)rows.size() - 1;\n"
        "    return rows[i].name.c_str();\n"
        "}\n"
        % (CLERIC, DRUID, MUILL, MUILL, THIEF, MONK))
    src = replace_region(src,
                         "inline const char* classAllowedWeaponName(int cls, int i) {",
                         nm)
    return src


def replace_region(src, sig, new_text):
    start, end = body_region(src, sig)
    return src[:start] + new_text + src[end:]


# ---------------------------------------------------------------------------
# fragment
def build_fragment(chart, speed, lists):
    def cidx(name):
        for i, r in enumerate(chart):
            if r[0] == name:
                return i
        die("fragment: chart row %r not found" % name)
        return -1

    L = []
    a = L.append
    a("    // ==== R1043: weapon chart registry ======================================\n")
    a("    // The R1043 de-wire: the PHB weapon weight/damage\n")
    a("    // chart (50 rows), the speed verify list (18) and\n")
    a("    // the five class allowlists ride\n")
    a("    // items::MiscItemRegistry from content/tables/\n")
    a("    // weapons/ (set names = def keys); this audit\n")
    a("    // loads its own registry instance and cross-reads\n")
    a("    // every row through the inline accessor surface\n")
    a("    // (weaponChart*/weaponSpeedVerified*/classAllowed*\n")
    a("    // in rules/phb/weapontables.h), so the r158/r189/\n")
    a("    // r198/r337 audits and this registry audit read\n")
    a("    // the same data.\n")
    a("    {\n")
    a("        int bad = 0;\n")
    a("        // -- 1. load --------------------------------------\n")
    a("        {\n")
    a("            items::MiscItemRegistry t;\n")
    a('            if (t.loadDirectory("content/tables/weapons") != 7)\n')
    a("                ++bad;\n")
    a("            if (!t.errors().empty()) ++bad;\n")
    a("            if (t.all().size() != 7) ++bad;\n")
    for k in [CHART, SPEED, CLERIC, DRUID, MUILL, THIEF, MONK]:
        a('            if (t.all().count("%s") != 1) ++bad;\n' % k)
    a('            if (t.all().count("weapon_chart_rows")) ++bad;\n')
    a('            if (t.all().count("treasure_potions")) ++bad;\n')
    a('            if (t.all().count("equipment_arms")) ++bad;\n')
    a('            if (t.all().count("weapon_fighter")) ++bad;\n')
    a("        }\n")
    a('        printf("R1043 weapon chart registry load audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    a("        // -- 2. counts -------------------------------------\n")
    a("        {\n")
    a("            if (rules::weaponChartRowCount() != 50) ++bad;\n")
    a("            if (rules::weaponSpeedVerifiedCount() != 18) ++bad;\n")
    a("            if (rules::classAllowedWeaponCount(0) != 7) ++bad;\n")
    a("            if (rules::classAllowedWeaponCount(1) != 9) ++bad;\n")
    a("            if (rules::classAllowedWeaponCount(5) != 3) ++bad;\n")
    a("            if (rules::classAllowedWeaponCount(6) != 3) ++bad;\n")
    a("            if (rules::classAllowedWeaponCount(7) != 8) ++bad;\n")
    a("            if (rules::classAllowedWeaponCount(9) != 24) ++bad;\n")
    a("            if (rules::classAllowedWeaponCount(2) != -1) ++bad;\n")
    a("            if (rules::classAllowedWeaponCount(8) != -1) ++bad;\n")
    a("            if (rules::classAllowedWeaponCount(10) != 0) ++bad;\n")
    a("            items::MiscItemRegistry t;\n")
    a('            t.loadDirectory("content/tables/weapons");\n')
    for k, n in [(CHART, 50), (SPEED, 18), (CLERIC, 7), (DRUID, 9),
                 (MUILL, 3), (THIEF, 8), (MONK, 24)]:
        a('            const auto* d_%s = t.find("%s");\n'
          % (k.split("_")[1], k))
        a('            if (!d_%s || (int)d_%s->rows.size() != %d) ++bad;\n'
          % (k.split("_")[1], k.split("_")[1], n))
        a('            if (d_%s && ((int)d_%s->pins.size() != 1\n'
          % (k.split("_")[1], k.split("_")[1]))
        a('                       || d_%s->pins[0].name\n'
          % k.split("_")[1])
        a('                              != std::string("%sRowCount")\n' % k)
        a("                       || d_%s->pins[0].value != %d)) ++bad;\n"
          % (k.split("_")[1], n))
    a("        }\n")
    a('        printf("R1043 weapon chart registry counts audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    a("        // -- 3. bands (the row-index axis) ----------------\n")
    a("        {\n")
    a("            items::MiscItemRegistry t;\n")
    a('            t.loadDirectory("content/tables/weapons");\n')
    a("            for (const auto& kv : t.all()) {\n")
    a("                const auto& d = kv.second;\n")
    a("                const int n = (int)d.rows.size();\n")
    a("                for (int i = 0; i < n; ++i)\n")
    a("                    if (d.rows[i].bandLo != i\n")
    a("                        || d.rows[i].bandHi != i\n")
    a("                        || d.rows[i].set != d.key\n")
    a("                        || d.rows[i].gpHi != 0) ++bad;\n")
    a("            }\n")
    a("            const auto* dc = t.find(\"%s\");\n" % CHART)
    a("            if (dc) {\n")
    a("                for (const auto& r : dc->rows) {\n")
    a("                    if (r.gp <= 0) ++bad;   // weight in gp\n")
    a("                    if (r.qtyLo > r.qtyHi) ++bad;   // S-M pair\n")
    a("                    if (r.xp > r.xpHi) ++bad;   // L pair\n")
    a("                }\n")
    a("            } else ++bad;\n")
    a("            const auto* ds = t.find(\"%s\");\n" % SPEED)
    a("            if (ds) {\n")
    a("                for (const auto& r : ds->rows) {\n")
    a("                    if (r.gp < 1) ++bad;   // speed factor\n")
    a("                    if (r.xp != 0 || r.xpHi != 0\n")
    a("                        || r.qtyLo != 0 || r.qtyHi != 0) ++bad;\n")
    a("                }\n")
    a("            } else ++bad;\n")
    a("            for (const char* lk : {\"%s\", \"%s\", \"%s\", \"%s\", \"%s\"}) {\n"
      % (CLERIC, DRUID, MUILL, THIEF, MONK))
    a("                const auto* dl = t.find(lk);\n")
    a("                if (!dl) { ++bad; continue; }\n")
    a("                for (const auto& r : dl->rows)\n")
    a("                    if (r.xp != 0 || r.xpHi != 0 || r.gp != 0\n")
    a("                        || r.qtyLo != 0 || r.qtyHi != 0) ++bad;\n")
    a("            }\n")
    a("        }\n")
    a('        printf("R1043 weapon chart registry bands audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    a("        // -- 4. data (famous rows via the accessors) ------\n")
    a("        {\n")
    # famous chart rows, computed from the parsed arrays
    fam = ["arrow", "two-handed sword", "spear", "long sword",
           "dagger", "quarterstaff"]
    for nm in fam:
        i = cidx(nm)
        _, w, smlo, smhi, llo, lhi = chart[i]
        a('            if (rules::weaponChartName(%d) != std::string("%s")) ++bad;\n'
          % (i, nm))
        a("            if (rules::weaponChartWeight(%d) != %d) ++bad;\n"
          % (i, w))
        a("            if (rules::weaponChartDamageSMMin(%d) != %d\n"
          "                || rules::weaponChartDamageSMMax(%d) != %d) ++bad;\n"
          % (i, smlo, i, smhi))
        a("            if (rules::weaponChartDamageLMin(%d) != %d\n"
          "                || rules::weaponChartDamageLMax(%d) != %d) ++bad;\n"
          % (i, llo, i, lhi))
    # speed famous rows
    for nm, want in [("fist", speed[0][1]),
                     ("dagger", speed[1][1]),
                     ("spear", None), ("two-handed sword", None),
                     ("pike", None)]:
        j = next((k for k, r in enumerate(speed) if r[0] == nm), None)
        if j is None:
            die("fragment: speed row %r not found" % nm)
        if want is None:
            want = speed[j][1]
        a('            if (rules::weaponSpeedVerifiedName(%d) != std::string("%s")) ++bad;\n'
          % (j, nm))
        a("            if (rules::weaponSpeedVerifiedFactor(%d) != %d) ++bad;\n"
          % (j, want))
    # allowlist famous rows
    for key, idx, nm in [(CLERIC, 0, lists[CLERIC][0]),
                         (CLERIC, 6, lists[CLERIC][6]),
                         (DRUID, 0, lists[DRUID][0]),
                         (THIEF, 7, lists[THIEF][7]),
                         (MONK, 0, lists[MONK][0]),
                         (MONK, 23, lists[MONK][23])]:
        cls = {CLERIC: 0, DRUID: 1, MUILL: 5, THIEF: 7, MONK: 9}[key]
        a('            if (rules::classAllowedWeaponName(%d, %d) != std::string("%s"))\n'
          "                ++bad;\n" % (cls, idx, nm))
    # in-file pins stay
    a("            {\n")
    a("                int lo = 0, hi = 0;\n")
    a("                rules::spearWeightRange(lo, hi);\n")
    a("                if (lo != 40 || hi != 60) ++bad;\n")
    a("                if (!rules::lanceChargingDouble(24)\n")
    a("                    || !rules::lanceChargingDouble(26)\n")
    a("                    || rules::lanceChargingDouble(23)\n")
    a("                    || rules::lanceChargingDouble(27)) ++bad;\n")
    a("                if (!rules::spearSetChargingDouble()) ++bad;\n")
    a("                if (rules::weaponBackOrUnseenBonus() != 2) ++bad;\n")
    a("                if (rules::weaponStunnedProneMotionlessBonus()\n")
    a("                        != 4) ++bad;\n")
    a("            }\n")
    a("        }\n")
    a('        printf("R1043 weapon chart registry data audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    a("        // -- 5. rows (full cross-read) --------------------\n")
    a("        {\n")
    a("            items::MiscItemRegistry t;\n")
    a('            t.loadDirectory("content/tables/weapons");\n')
    a('            const auto* dc = t.find("%s");\n' % CHART)
    a("            if (dc) {\n")
    a("                for (int i = 0; i < 50; ++i) {\n")
    a("                    const auto& r = dc->rows[i];\n")
    a("                    if (rules::weaponChartName(i) != r.name\n")
    a("                        || rules::weaponChartWeight(i) != r.gp\n")
    a("                        || rules::weaponChartDamageSMMin(i)\n")
    a("                               != r.qtyLo\n")
    a("                        || rules::weaponChartDamageSMMax(i)\n")
    a("                               != r.qtyHi\n")
    a("                        || rules::weaponChartDamageLMin(i)\n")
    a("                               != r.xp\n")
    a("                        || rules::weaponChartDamageLMax(i)\n")
    a("                               != r.xpHi) ++bad;\n")
    a("                }\n")
    a("            } else ++bad;\n")
    a('            const auto* ds = t.find("%s");\n' % SPEED)
    a("            if (ds) {\n")
    a("                for (int i = 0; i < 18; ++i) {\n")
    a("                    const auto& r = ds->rows[i];\n")
    a("                    if (rules::weaponSpeedVerifiedName(i) != r.name\n")
    a("                        || rules::weaponSpeedVerifiedFactor(i)\n")
    a("                               != r.gp) ++bad;\n")
    a("                }\n")
    a("            } else ++bad;\n")
    a("            for (int cls = 0; cls < 10; ++cls) {\n")
    a("                const char* key = 0;\n")
    a("                if (cls == 0) key = \"%s\";\n" % CLERIC)
    a("                else if (cls == 1) key = \"%s\";\n" % DRUID)
    a("                else if (cls == 5 || cls == 6) key = \"%s\";\n" % MUILL)
    a("                else if (cls == 7) key = \"%s\";\n" % THIEF)
    a("                else if (cls == 9) key = \"%s\";\n" % MONK)
    a("                if (!key) continue;\n")
    a("                const auto* dl = t.find(key);\n")
    a("                if (!dl) { ++bad; continue; }\n")
    a("                const int n = (int)dl->rows.size();\n")
    a("                for (int i = 0; i < n; ++i)\n")
    a("                    if (rules::classAllowedWeaponName(cls, i)\n")
    a("                            != dl->rows[i].name) ++bad;\n")
    a("            }\n")
    a("        }\n")
    a('        printf("R1043 weapon chart registry rows audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    a("        // -- 6. edges (clamps + dispatch) -----------------\n")
    a("        {\n")
    a("            if (rules::weaponChartName(-1)\n")
    a("                    != rules::weaponChartName(0)) ++bad;\n")
    a("            if (rules::weaponChartName(999)\n")
    a("                    != rules::weaponChartName(49)) ++bad;\n")
    a("            if (rules::weaponChartWeight(-5)\n")
    a("                    != rules::weaponChartWeight(0)) ++bad;\n")
    a("            if (rules::weaponChartDamageLMax(999)\n")
    a("                    != rules::weaponChartDamageLMax(49)) ++bad;\n")
    a("            if (rules::weaponSpeedVerifiedName(-1)\n")
    a("                    != rules::weaponSpeedVerifiedName(0)) ++bad;\n")
    a("            if (rules::weaponSpeedVerifiedFactor(99)\n")
    a("                    != rules::weaponSpeedVerifiedFactor(17)) ++bad;\n")
    a("            if (rules::classAllowedWeaponName(0, 99)\n")
    a("                    != rules::classAllowedWeaponName(0, 6)) ++bad;\n")
    a("            if (rules::classAllowedWeaponName(9, -1)\n")
    a("                    != rules::classAllowedWeaponName(9, 0)) ++bad;\n")
    a("            if (rules::classAllowedWeaponName(10, 0)\n")
    a('                != std::string("club")) ++bad;\n')
    a("            if (!rules::classUsesAnyWeapon(2)\n")
    a("                || !rules::classUsesAnyWeapon(3)\n")
    a("                || !rules::classUsesAnyWeapon(4)\n")
    a("                || !rules::classUsesAnyWeapon(8)) ++bad;\n")
    a("            if (rules::classUsesAnyWeapon(0)\n")
    a("                || rules::classUsesAnyWeapon(9)) ++bad;\n")
    a('            if (rules::weaponAllowedForClass(0, "quarterstaff")\n')
    a("                != true) ++bad;\n")
    a('            if (rules::weaponAllowedForClass(0, "two-handed sword")\n')
    a("                != false) ++bad;\n")
    a('            if (rules::weaponAllowedForClass(2, "two-handed sword")\n')
    a("                != true) ++bad;\n")
    a("            if (rules::weaponAllowedForClass(0, 0) != false) ++bad;\n")
    a("            if (rules::classOilUse(9) != 0) ++bad;\n")
    a("            if (rules::classOilUse(0) != 1) ++bad;\n")
    a("            if (rules::classPoisonUse(0) != 0) ++bad;\n")
    a("            if (rules::classPoisonUse(8) != 1) ++bad;\n")
    a("            if (rules::classPoisonUseForAlignment(0, true) != -1)\n")
    a("                ++bad;\n")
    a("            if (rules::classPoisonUseForAlignment(0, false) != 0)\n")
    a("                ++bad;\n")
    a("        }\n")
    a('        printf("R1043 weapon chart registry edges audit: bad %d\\n", bad);\n')
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
    if not os.path.exists(WT):
        die("run from the repo root (%s missing)" % WT)

    marker = os.path.join(DIR, CHART + ".lua")
    already = (os.path.exists(marker)
               and "R1043 registry seam" in open(WT).read())
    if already:
        print("applied 0, already 1")
        print("SPLICE OK")
        return

    src = open(WT).read()
    chart, speed, lists = parse_all(src)

    os.makedirs(DIR, exist_ok=True)
    chart_rows = [(c[0], c[4], c[5], c[1], c[2], c[3])
                  for c in chart]
    files = {
        CHART + ".lua": lua_def(
            CHART, "Weapon weight and damage chart (50 rows)",
            "gp = the printed weight in gold pieces "
            "(the spear minimum), qty the S-M damage pair, "
            "xp/xp_hi the L damage pair.",
            chart_rows),
        SPEED + ".lua": lua_def(
            SPEED, "Weapon speed verify list (18 rows)",
            "gp = the printed speed factor; the rest zero.",
            [(s[0], 0, 0, s[1], 0, 0) for s in speed]),
        CLERIC + ".lua": lua_def(
            CLERIC, "Cleric weapon allowlist (7 rows)",
            "Name-only rows.",
            [(x, 0, 0, 0, 0, 0) for x in lists[CLERIC]]),
        DRUID + ".lua": lua_def(
            DRUID, "Druid weapon allowlist (9 rows)",
            "Name-only rows.",
            [(x, 0, 0, 0, 0, 0) for x in lists[DRUID]]),
        MUILL + ".lua": lua_def(
            MUILL, "Magic-user and illusionist allowlist (3 rows)",
            "Name-only rows.",
            [(x, 0, 0, 0, 0, 0) for x in lists[MUILL]]),
        THIEF + ".lua": lua_def(
            THIEF, "Thief weapon allowlist (8 rows)",
            "Name-only rows.",
            [(x, 0, 0, 0, 0, 0) for x in lists[THIEF]]),
        MONK + ".lua": lua_def(
            MONK, "Monk weapon allowlist (24 rows)",
            "Name-only rows.",
            [(x, 0, 0, 0, 0, 0) for x in lists[MONK]]),
    }
    for name, text in files.items():
        open(os.path.join(DIR, name), "w").write(text)

    roundtrip(CHART, chart_rows, files[CHART + ".lua"])
    roundtrip(SPEED, [(s[0], 0, 0, s[1], 0, 0) for s in speed],
              files[SPEED + ".lua"])
    for k in [CLERIC, DRUID, MUILL, THIEF, MONK]:
        roundtrip(k, [(x, 0, 0, 0, 0, 0) for x in lists[k]],
                  files[k + ".lua"])
    print("round-trip: 7 lua files parse back byte-exact")

    new_src = rewrite_header(src)
    open(WT, "w").write(new_src)

    frag = build_fragment(chart, speed, lists)
    open("rules/audits/r1043_weapon_chart_registry.h", "w").write(frag)

    reg = open("regtest.cpp").read()
    anchor = ('    #include "rules/audits/r1042_equipment_cost_registry.h"'
              '  // R1042\n')
    reg = replace_once(
        reg, anchor,
        anchor +
        '    #include "rules/audits/r1043_weapon_chart_registry.h"'
        '  // R1043\n',
        "regtest include")
    open("regtest.cpp", "w").write(reg)

    c = census()
    print("census: %d -> %d audit printf patterns"
          % (CENSUS_BEFORE, CENSUS_AFTER))
    if c != CENSUS_AFTER:
        die("census %d, expected %d" % (c, CENSUS_AFTER))

    print("applied 1, rewrote 2 tracked files, wrote 9 new files")
    print("SPLICE OK")


main()
