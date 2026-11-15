#!/usr/bin/env python3
# r1061_splice.py - the R1061 siegefire family de-wire tool.
#
# Base: de2c64f4 (R1060). Target: 19 retiring static arrays of
# rules/dmg/siegefire.h ride items::MiscItemRegistry from
# content/tables/siegefire/ (4 rowless defs, 19 named tables,
# one pin per def). The 38 KEPT zero-arg scalars stay C++. The
# single caller (rules/audits/r214_war_machine_fire_and.h)
# stays BYTE-IDENTICAL - the new r1061 frag carries the parity.
# Census 1127 -> 1135.
#
# Hardening (R1059 lessons): mixed-splice-state loud die; the
# already-applied path dies if the frag/include is missing; the
# tree-root canvas.md (the R1060 accidental landing) is deleted
# FIRST so it rides out in the R1061 commit.
#
# Idempotent: rerun reports "already N" and changes nothing.
# Array values are PARSED from the pristine header and verified
# against embedded (width, sum) checksums; nothing is retyped.
#
# No backslashes appear in this source (the R1060 environment
# lesson); @N@ tokens become backslash-n at emit time.

import os
import re
import sys
import hashlib

PRISTINE_MD5 = "a2b8d1704b3dc2897bb04c89cb7d36af"

MARK = "// R1061 applied"
SEAM_REL = os.path.join("rules", "seams", "siegefirereg.h")
FRAG_REL = os.path.join("rules", "audits", "r1061_siegefire_registry.h")
LUA_DIR = os.path.join("content", "tables", "siegefire")
HEADER_REL = os.path.join("rules", "dmg", "siegefire.h")
REGTEST_REL = "regtest.cpp"

# (fn, index expr, dkey, tag, width, sum) - the 19 retiring arrays.
SPECS = [
    ("siegeFieldOfFireDegrees", "device", "siege_fire", "field_of_fire", 6, 100),
    ("siegeRangeMinQuarterInches", "device", "siege_fire", "range_min_qi", 6, 229),
    ("siegeRangeMaxQuarterInches", "device", "siege_fire", "range_max_qi", 6, 586),
    ("siegeDamageSMMin", "device", "siege_fire", "damage_sm_min", 6, 27),
    ("siegeDamageSMMax", "device", "siege_fire", "damage_sm_max", 6, 118),
    ("siegeDamageLMin", "device", "siege_fire", "damage_l_min", 6, 35),
    ("siegeDamageLMax", "device", "siege_fire", "damage_l_max", 6, 102),
    ("siegeRateOfFireMinHundredths", "device", "siege_fire", "rate_of_fire_min_h", 6, 200),
    ("siegeRateOfFireMaxHundredths", "device", "siege_fire", "rate_of_fire_max_h", 6, 225),
    ("siegeCrewMin", "device", "siege_fire", "crew_min", 6, 40),
    ("siegeCrewMax", "device", "siege_fire", "crew_max", 6, 72),
    ("siegeAttackQuarterPoints", "kind * 4 + material", "siege_attack", "quarter_points", 88, 736),
    ("siegeAttackPerRound", "kind", "siege_attack", "per_round", 22, 10),
    ("siegeAttackPerCasterLevel", "kind", "siege_attack", "per_caster_level", 22, 2),
    ("siegeAttackQuakeMin", "material", "siege_attack", "quake_min", 4, 20),
    ("siegeAttackQuakeMax", "material", "siege_attack", "quake_max", 4, 180),
    ("constructionDefensiveMin", "kind", "siege_defensive", "defensive_min", 26, 628),
    ("constructionDefensiveMax", "kind", "siege_defensive", "defensive_max", 26, 711),
    ("siegeDeviceMhp", "device", "siege_mhp", "mhp", 12, 79),
]

DEFS = [
    # (key, name, pin count value, [(tag, fn), ...] in table order)
    ("siege_fire", "DMG war machine fire table", 11,
     [("field_of_fire", "siegeFieldOfFireDegrees"),
      ("range_min_qi", "siegeRangeMinQuarterInches"),
      ("range_max_qi", "siegeRangeMaxQuarterInches"),
      ("damage_sm_min", "siegeDamageSMMin"),
      ("damage_sm_max", "siegeDamageSMMax"),
      ("damage_l_min", "siegeDamageLMin"),
      ("damage_l_max", "siegeDamageLMax"),
      ("rate_of_fire_min_h", "siegeRateOfFireMinHundredths"),
      ("rate_of_fire_max_h", "siegeRateOfFireMaxHundredths"),
      ("crew_min", "siegeCrewMin"),
      ("crew_max", "siegeCrewMax")]),
    ("siege_attack", "DMG siege attack values", 5,
     [("quarter_points", "siegeAttackQuarterPoints"),
      ("per_round", "siegeAttackPerRound"),
      ("per_caster_level", "siegeAttackPerCasterLevel"),
      ("quake_min", "siegeAttackQuakeMin"),
      ("quake_max", "siegeAttackQuakeMax")]),
    ("siege_defensive", "DMG construction defensive values", 2,
     [("defensive_min", "constructionDefensiveMin"),
      ("defensive_max", "constructionDefensiveMax")]),
    ("siege_mhp", "DMG siege device hit points", 1,
     [("mhp", "siegeDeviceMhp")]),
]

BS = chr(92)
def emit(text):
    # @N@ -> the two characters backslash + n
    return text.replace("@N@", BS + "n")

def die(msg):
    sys.stderr.write("r1061_splice: FATAL: " + msg + chr(10))
    sys.exit(1)

def parse_array(src, fn, expr):
    try:
        i = src.index("inline int " + fn + "(")
        j = src.index("return t[" + expr + "];", i)
        k = src.index("static const int t[", i, j)
    except ValueError:
        die("pristine shape mismatch at " + fn)
    seg = src[k:j]
    w = int(re.search(r"t" + re.escape("[") + r"(\d+)" + re.escape("]"), seg).group(1))
    vals = [int(x) for x in
            re.findall(r"-?\d+", seg.split("= " + chr(123), 1)[1].split("};" , 1)[0])]
    if len(vals) != w:
        die(fn + ": parsed " + str(len(vals)) + " values, header says " + str(w))
    return i, k, j + len("return t[" + expr + "];"), vals

def fmt_vals(vals, per, indent):
    p = " " * indent
    out = []
    for s in range(0, len(vals), per):
        out.append(p + ", ".join(str(v) for v in vals[s:s + per]) + ",")
    return out

def lua_file(key, name, tables):
    L = []
    L.append("-- misc magic item def: " + key)
    L.append("-- the R1061 siegefire family de-wire: the retired")
    L.append("-- static arrays of rules/dmg/siegefire.h ride this")
    L.append("-- def (rowless: flat int columns only, no rows).")
    L.append("-- The accessors keep their clamps and comments;")
    L.append("-- rules/audits/r214_war_machine_fire_and.h is the")
    L.append("-- print-fidelity record. DO NOT hand-edit this file;")
    L.append("-- tools/r1061_splice.py is the only writer.")
    L.append("return {")
    L.append("  key = " + chr(34) + key + chr(34) + ",")
    L.append("  name = " + chr(34) + name + chr(34) + ",")
    L.append("  sources = {")
    L.append("    { part = 0, round = 1061 },")
    L.append("  },")
    L.append("  pins = {")
    L.append("    { name = " + chr(34) + key + "TableCount" + chr(34) + ",")
    L.append("      value = " + str(len(tables)) + ",")
    L.append("      comment = " + chr(34) + "the family columns" + chr(34) + " },")
    L.append("  },")
    L.append("  tables = {")
    for tag, fn, vals in tables:
        L.append("    { name = " + chr(34) + tag + chr(34) + ",")
        L.append("      values = {")
        for line in fmt_vals(vals, 6, 8):
            L.append(line)
        L.append("      },")
        L.append("      comment = " + chr(34) + "from " + fn + chr(34) + " },")
    L.append("  },")
    L.append("}")
    return chr(10).join(L) + chr(10)

def seam_text():
    return chr(10).join([
        "// ===========================================================================",
        "// Adnd1 - rules/seams/siegefirereg.h",
        "// The R1061 siegefire-family registry seam.",
        "//",
        "// content/tables/siegefire/ (R1061)",
        "// via items::MiscItemRegistry: the R1058",
        "// weapons-family wTable idiom, rowless",
        "// (the siegefire family is flat int",
        "// columns only, no rows readers). Header-",
        "// only singleton (the R1040 appendixp.h",
        "// idiom). Every accessor in",
        "// rules/dmg/siegefire.h keeps its",
        "// signature, clamp and comment; only the",
        "// array read moves behind the registry.",
        "// The R1058 weaponsreg / R1059 miscreg",
        "// precedent, seated at rules/seams.",
        "// DO NOT hand-edit: tools/r1061_splice.py",
        "// is the only writer.",
        "// ===========================================================================",
        "",
        "#pragma once",
        "",
        '#include "items/MiscItemRegistry.h"',
        "",
        "namespace rules {",
        "",
        "// ---- the siegefire family registry seam ----",
        "",
        "inline items::MiscItemRegistry&",
        "sfReg() {",
        "    static items::MiscItemRegistry",
        "        reg;",
        "    static bool loaded = false;",
        "    if (!loaded) {",
        "        loaded = true;",
        "        reg.loadDirectory(",
        '            "content/tables/"',
        '            "siegefire");',
        "    }",
        "    return reg;",
        "}",
        "",
        "// one named int table of one def",
        "// (null when absent or empty -",
        "// the R1058 long long note rides",
        "// here unchanged)",
        "inline const std::vector<",
        "    long long>* sfTable(",
        "        const char* key,",
        "        const char* tag) {",
        "    static std::map<std::string,",
        "        std::vector<long long>>",
        "        cache;",
        "    std::string ck =",
        "        std::string(key)",
        "        + " + chr(34) + "/" + chr(34) + " + tag;",
        "    auto it = cache.find(ck);",
        "    if (it == cache.end()) {",
        "        const items::",
        "            MiscItemDef* d =",
        "            sfReg().find(key);",
        "        const std::vector<",
        "            long long>* v = nullptr;",
        "        if (d) {",
        "            for (const auto& t :",
        "                 d->tables)",
        '                if (t.name == tag) {',
        "                    v = &t.values;",
        "                    break;",
        "                }",
        "        }",
        "        it = cache.emplace(",
        "            ck, v ? *v",
        "                  : std::vector<",
        "                        long long>()",
        "            ).first;",
        "    }",
        "    return it->second.empty()",
        "        ? nullptr",
        "        : &it->second;",
        "}",
        "",
        "}   // namespace rules",
        ""]) + chr(10)

def arr_decl(name, vals, per, indent):
    lines = [" " * indent + "static const int " + name +
             "[" + str(len(vals)) + "] = {"]
    for line in fmt_vals(vals, per, indent + 4):
        lines.append(line)
    lines.append(" " * indent + "};")
    return lines

def frag_text(vals_by_fn):
    P = " " * 4
    L = []
    L.append(P + "// ==== R1061: siegefire registry ==========")
    L.append(P + "// The R1061 de-wire: the 19 retiring static")
    L.append(P + "// arrays of rules/dmg/siegefire.h ride")
    L.append(P + "// items::MiscItemRegistry from")
    L.append(P + "// content/tables/siegefire/ - 4 rowless defs,")
    L.append(P + "// 19 tables, one pin per def; the KEPT")
    L.append(P + "// zero-arg scalars stay C++, probed by the")
    L.append(P + "// R214 pin fragment and the edges here. Eight")
    L.append(P + "// sections: load, counts, defs-A/B/C/D, seam,")
    L.append(P + "// edges. Census 1127 -> 1135. DO NOT hand-edit:")
    L.append(P + "// tools/r1061_splice.py is the only writer.")
    L.append(P + "{")
    L.append(P + "    int bad = 0;")

    # -- 1. load --------------------------------------------------
    L.append(P + "    // -- 1. load ------------------------------")
    L.append(P + "    {")
    L.append(P + "        items::MiscItemRegistry reg;")
    L.append(P + "        int n = reg.loadDirectory(")
    L.append(P + '            "content/tables/siegefire");')
    L.append(P + "        if (n != 4) ++bad;")
    L.append(P + "        if (!reg.errors().empty()) ++bad;")
    L.append(P + "        for (const auto& kv : reg.all())")
    L.append(P + "            if ((int)kv.second.sources.size() != 1")
    L.append(P + "                || kv.second.sources[0].first != 0")
    L.append(P + "                || kv.second.sources[0].second != 1061)")
    L.append(P + "                ++bad;")
    for key, _, _, _ in DEFS:
        L.append(P + '        if (!reg.find("' + key + '")) ++bad;')
    L.append(P + "    }")
    L.append(P + '    printf("R1061 siegefire registry load audit: bad %d@N@", bad);')
    L.append(P + "    if (bad) return 1;")
    L.append(P + "    bad = 0;")

    # -- 2. counts ------------------------------------------------
    L.append(P + "    // -- 2. counts ----------------------------")
    L.append(P + "    {")
    L.append(P + "        items::MiscItemRegistry reg;")
    L.append(P + "        reg.loadDirectory(")
    L.append(P + '            "content/tables/siegefire");')
    for key, _, pinv, tags in DEFS:
        L.append(P + "        {")
        L.append(P + "            const items::MiscItemDef* d =")
        L.append(P + '                reg.find("' + key + '");')
        L.append(P + "            if (!d) { ++bad; } else {")
        L.append(P + "                if ((int)d->pins.size() != 1")
        L.append(P + '                    || d->pins[0].name')
        L.append(P + '                        != "' + key + 'TableCount"')
        L.append(P + "                    || d->pins[0].value != " + str(pinv) + ")")
        L.append(P + "                    ++bad;")
        L.append(P + "                if ((int)d->tables.size() != " + str(pinv) + ") ++bad;")
        for idx, (tag, fn) in enumerate(tags):
            w = vals_by_fn[fn][1]
            L.append(P + "                if (d->tables[" + str(idx) + "].name")
            L.append(P + '                    != "' + tag + '"')
            L.append(P + "                    || (int)d->tables[" + str(idx) + "]")
            L.append(P + "                        .values.size() != " + str(w) + ")")
            L.append(P + "                    ++bad;")
        L.append(P + "            }")
        L.append(P + "        }")
    L.append(P + "    }")
    L.append(P + '    printf("R1061 siegefire registry counts audit: bad %d@N@", bad);')
    L.append(P + "    if (bad) return 1;")
    L.append(P + "    bad = 0;")

    # -- 3. defs-A (fire) -----------------------------------------
    L.append(P + "    // -- 3. defs-A: the fire columns ----------")
    L.append(P + "    {")
    L.append(P + "        items::MiscItemRegistry reg;")
    L.append(P + "        reg.loadDirectory(")
    L.append(P + '            "content/tables/siegefire");')
    L.append(P + "        const items::MiscItemDef* d =")
    L.append(P + '            reg.find("siege_fire");')
    L.append(P + "        if (!d) { ++bad; } else {")
    for idx, (tag, fn) in enumerate(DEFS[0][3]):
        vals = vals_by_fn[fn][0]
        L.append(P + "            // " + fn + " (" + tag + ")")
        for line in arr_decl("k" + fn, vals, 6, 12):
            L.append(line)
        L.append(P + "            if (d->tables[" + str(idx) + "].name")
        L.append(P + '                != "' + tag + '") ++bad;')
        L.append(P + "            else for (int i = 0; i < " + str(len(vals)) + "; ++i)")
        L.append(P + "                if ((int)d->tables[" + str(idx) + "]")
        L.append(P + "                        .values[i] != k" + fn + "[i])")
        L.append(P + "                    ++bad;")
    L.append(P + "        }")
    L.append(P + "    }")
    L.append(P + '    printf("R1061 siegefire registry defs-A audit: bad %d@N@", bad);')
    L.append(P + "    if (bad) return 1;")
    L.append(P + "    bad = 0;")

    # -- 4. defs-B (attack) ---------------------------------------
    L.append(P + "    // -- 4. defs-B: the attack columns --------")
    L.append(P + "    {")
    L.append(P + "        items::MiscItemRegistry reg;")
    L.append(P + "        reg.loadDirectory(")
    L.append(P + '            "content/tables/siegefire");')
    L.append(P + "        const items::MiscItemDef* d =")
    L.append(P + '            reg.find("siege_attack");')
    L.append(P + "        if (!d) { ++bad; } else {")
    for idx, (tag, fn) in enumerate(DEFS[1][3]):
        vals = vals_by_fn[fn][0]
        L.append(P + "            // " + fn + " (" + tag + ")")
        per = 4 if len(vals) > 6 else 6
        for line in arr_decl("k" + fn, vals, per, 12):
            L.append(line)
        L.append(P + "            if (d->tables[" + str(idx) + "].name")
        L.append(P + '                != "' + tag + '") ++bad;')
        L.append(P + "            else for (int i = 0; i < " + str(len(vals)) + "; ++i)")
        L.append(P + "                if ((int)d->tables[" + str(idx) + "]")
        L.append(P + "                        .values[i] != k" + fn + "[i])")
        L.append(P + "                    ++bad;")
    L.append(P + "        }")
    L.append(P + "    }")
    L.append(P + '    printf("R1061 siegefire registry defs-B audit: bad %d@N@", bad);')
    L.append(P + "    if (bad) return 1;")
    L.append(P + "    bad = 0;")

    # -- 5. defs-C (quake/defensive/mhp) ---------------------------
    L.append(P + "    // -- 5. defs-C: quake, defensive, mhp -----")
    L.append(P + "    {")
    L.append(P + "        items::MiscItemRegistry reg;")
    L.append(P + "        reg.loadDirectory(")
    L.append(P + '            "content/tables/siegefire");')
    for key, _, _, tags in [DEFS[2], DEFS[3]]:
        L.append(P + "        {")
        L.append(P + "        const items::MiscItemDef* d =")
        L.append(P + '            reg.find("' + key + '");')
        L.append(P + "        if (!d) { ++bad; } else {")
        for idx, (tag, fn) in enumerate(tags):
            vals = vals_by_fn[fn][0]
            L.append(P + "            // " + fn + " (" + tag + ")")
            for line in arr_decl("k" + fn, vals, 8, 12):
                L.append(line)
            L.append(P + "            if (d->tables[" + str(idx) + "].name")
            L.append(P + '                != "' + tag + '") ++bad;')
            L.append(P + "            else for (int i = 0; i < " + str(len(vals)) + "; ++i)")
            L.append(P + "                if ((int)d->tables[" + str(idx) + "]")
            L.append(P + "                        .values[i] != k" + fn + "[i])")
            L.append(P + "                    ++bad;")
        L.append(P + "        }")
        L.append(P + "        }")
    L.append(P + "    }")
    L.append(P + '    printf("R1061 siegefire registry defs-C audit: bad %d@N@", bad);')
    L.append(P + "    if (bad) return 1;")
    L.append(P + "    bad = 0;")

    # -- 6. defs-D (accessor parity sweep) --------------------------
    L.append(P + "    // -- 6. defs-D: accessor parity sweep -----")
    L.append(P + "    // every accessor, every index, against")
    L.append(P + "    // the registry seam (the R214 caller")
    L.append(P + "    // stays byte-identical; this label")
    L.append(P + "    // carries the parity it used to carry)")
    L.append(P + "    {")
    for fn, expr, dkey, tag, w, _s in SPECS:
        L.append(P + "        {")
        L.append(P + "            const auto* g = rules::sfTable(")
        L.append(P + '                "' + dkey + '", "' + tag + '");')
        L.append(P + "            if (!g) { ++bad; }")
        if fn == "siegeAttackQuarterPoints":
            L.append(P + "            else for (int i = 0; i < " + str(w) + "; ++i)")
            L.append(P + "                if (rules::" + fn + "(")
            L.append(P + "                        i / 4, i % 4)")
            L.append(P + "                    != (int)(*g)[i]) ++bad;")
        else:
            L.append(P + "            else for (int i = 0; i < " + str(w) + "; ++i)")
            L.append(P + "                if (rules::" + fn + "(i)")
            L.append(P + "                    != (int)(*g)[i]) ++bad;")
        L.append(P + "        }")
    L.append(P + "    }")
    L.append(P + '    printf("R1061 siegefire registry defs-D audit: bad %d@N@", bad);')
    L.append(P + "    if (bad) return 1;")
    L.append(P + "    bad = 0;")

    # -- 7. seam ----------------------------------------------------
    L.append(P + "    // -- 7. seam -------------------------------")
    L.append(P + "    // all 19 (key, tag) pairs resolve; wrong")
    L.append(P + "    // tag and wrong key read null; two calls")
    L.append(P + "    // share the cached table (stability)")
    L.append(P + "    {")
    for fn, _e, dkey, tag, _w, _s in SPECS:
        L.append(P + '        if (!rules::sfTable("' + dkey + '", "' + tag + '")) ++bad;')
    L.append(P + '        if (rules::sfTable("siege_fire", "no_such_tag")) ++bad;')
    L.append(P + '        if (rules::sfTable("no_such_def", "field_of_fire")) ++bad;')
    L.append(P + "        {")
    L.append(P + '            const auto* p1 = rules::sfTable("siege_fire",')
    L.append(P + '                                 "field_of_fire");')
    L.append(P + '            const auto* p2 = rules::sfTable("siege_fire",')
    L.append(P + '                                 "field_of_fire");')
    L.append(P + "            if (p1 != p2) ++bad;")
    L.append(P + "        }")
    L.append(P + "    }")
    L.append(P + '    printf("R1061 siegefire registry seam audit: bad %d@N@", bad);')
    L.append(P + "    if (bad) return 1;")
    L.append(P + "    bad = 0;")

    # -- 8. edges ---------------------------------------------------
    L.append(P + "    // -- 8. edges -------------------------------")
    L.append(P + "    // accessor clamps and KEPT scalar spots")
    L.append(P + "    {")
    E = [
        ("siegeFieldOfFireDegrees(-9)", "siegeFieldOfFireDegrees(0)"),
        ("siegeFieldOfFireDegrees(99)", "siegeFieldOfFireDegrees(5)"),
        ("siegeRangeMinQuarterInches(99)", "siegeRangeMinQuarterInches(5)"),
        ("siegeAttackQuarterPoints(-9, 0)", "siegeAttackQuarterPoints(0, 0)"),
        ("siegeAttackQuarterPoints(99, 3)", "siegeAttackQuarterPoints(21, 3)"),
        ("siegeAttackQuarterPoints(0, 99)", "siegeAttackQuarterPoints(0, 3)"),
        ("siegeAttackPerRound(99)", "siegeAttackPerRound(21)"),
        ("siegeAttackQuakeMin(9)", "siegeAttackQuakeMin(3)"),
        ("siegeAttackQuakeMax(-3)", "siegeAttackQuakeMax(0)"),
        ("constructionDefensiveMin(99)", "constructionDefensiveMin(25)"),
        ("constructionDefensiveMax(-3)", "constructionDefensiveMax(0)"),
        ("siegeDeviceMhp(99)", "siegeDeviceMhp(11)"),
    ]
    for a, b in E:
        L.append(P + "        if (rules::" + a)
        L.append(P + "            != rules::" + b + ") ++bad;")
    for keep, val in [("fireDeviceCount", "6"),
                      ("siegeAttackKindCount", "22"),
                      ("defensiveKindCount", "26"),
                      ("wmDirectFireBonus", "4"),
                      ("siegeBelowMinCrewRatePct", "50")]:
        L.append(P + "        if (rules::" + keep + "() != " + val + ") ++bad;")
    L.append(P + "    }")
    L.append(P + '    printf("R1061 siegefire registry edges audit: bad %d@N@", bad);')
    L.append(P + "    if (bad) return 1;")
    L.append(P + "    bad = 0;")
    L.append(P + "}")
    return chr(10).join(L) + chr(10)

def rewrite_header(src, vals_by_fn):
    # mark + seam include after #pragma once
    po = src.index("#pragma once")
    eol = src.index(chr(10), po)
    src = (src[:eol + 1] + chr(10) + MARK + chr(10)
           + '#include "rules/seams/siegefirereg.h"' + chr(10) + src[eol + 1:])
    # 19 body rewrites, back-to-front not needed (indexes shift-safe:
    # we re-scan per fn)
    for fn, expr, dkey, tag, w, _s in SPECS:
        i, k, jend, vals = parse_array(src, fn, expr)
        if len(vals) != w or sum(vals) != dict(
                (x[0], x[5]) for x in SPECS)[fn]:
            die(fn + " checksum mismatch")
        tail = ("const auto* g = sfTable(" + chr(10)
                + '        "' + dkey + '", "' + tag + '");' + chr(10)
                + "    if (!g) return 0;" + chr(10)
                + "    return (int)(*g)[" + expr + "];")
        src = src[:k] + tail + src[jend:]
    return src

def load_lua_vals(root):
    # parse values back out of the spliced lua defs (for the
    # already-applied frag refresh path)
    vals_by_fn = {}
    for key, _name, _pinv, tags in DEFS:
        txt = open(os.path.join(root, LUA_DIR, key + ".lua")).read()
        for tag, fn in tags:
            m = re.search(r'name = "' + tag + r'",[@' + chr(10) + r' ]*'
                         + r'values = ' + chr(123) + r'(.*?)' + chr(125),
                         txt, re.S)
            if not m:
                die("lua table " + tag + " unreadable in " + key)
            vals = [int(x) for x in re.findall(r"-?\d+", m.group(1))]
            spec = dict((x[0], (x[4], x[5])) for x in SPECS)[fn]
            if len(vals) != spec[0] or sum(vals) != spec[1]:
                die("lua checksum drift at " + fn + " (frag refresh path)")
            vals_by_fn[fn] = (vals, spec[0])
    return vals_by_fn

def main():
    root = sys.argv[1] if len(sys.argv) > 1 else "."
    root = os.path.abspath(root)
    hdr = os.path.join(root, HEADER_REL)

    # canvas.md rides out first (the R1060 accidental landing)
    cm = os.path.join(root, "canvas.md")
    if os.path.isfile(cm):
        os.remove(cm)
        print("r1061_splice: tree-root canvas.md deleted (rides out in R1061)")

    if not os.path.isfile(hdr):
        die("no rules/dmg/siegefire.h under " + root)
    src = open(hdr).read()

    if MARK in src:
        # already-applied path: harden (R1059 lesson)
        ok = (os.path.isfile(os.path.join(root, FRAG_REL))
              and os.path.isfile(os.path.join(root, SEAM_REL))
              and os.path.isdir(os.path.join(root, LUA_DIR)))
        if not ok:
            die("R1061 mark present but frag/seam/lua dir missing - mixed splice state")
        n_lua = len([f for f in os.listdir(os.path.join(root, LUA_DIR))
                     if f.endswith(".lua")])
        if n_lua != 4:
            die("R1061 mark present but " + str(n_lua) + " lua defs (want 4)")
        rt = open(os.path.join(root, REGTEST_REL)).read()
        if "r1061_siegefire_registry.h" not in rt:
            die("R1061 mark present but regtest include missing - mixed splice state")
        vals_by_fn = load_lua_vals(root)
        frag_path = os.path.join(root, FRAG_REL)
        fresh_frag = emit(frag_text(vals_by_fn))
        cur = open(frag_path).read()
        if cur != fresh_frag:
            open(frag_path, "w").write(fresh_frag)
            print("r1061_splice: frag refreshed (tool-generated output updated)")
        else:
            print("r1061_splice: frag current")
        print("r1061_splice: already applied (4 defs, 19 tables, 8 labels)")
        print("r1061_splice: applied 0, already 19; census stays 1135")
        return

    md5 = hashlib.md5(src.encode()).hexdigest()
    if md5 != PRISTINE_MD5:
        die("rules/dmg/siegefire.md5 is " + md5 + ", want " + PRISTINE_MD5
            + " (pristine de2c64f4 required)")

    # parse + verify all 19
    vals_by_fn = {}
    for fn, expr, dkey, tag, w, s in SPECS:
        _i, _k, _j, vals = parse_array(src, fn, expr)
        if len(vals) != w or sum(vals) != s:
            die(fn + " checksum mismatch (want w=" + str(w) + " sum=" + str(s) + ")")
        vals_by_fn[fn] = (vals, w)
    print("r1061_splice: 19 arrays parsed, checksums verified")

    # lua defs
    os.makedirs(os.path.join(root, LUA_DIR), exist_ok=True)
    for key, name, _pinv, tags in DEFS:
        tables = [(tag, fn, vals_by_fn[fn][0]) for tag, fn in tags]
        path = os.path.join(root, LUA_DIR, key + ".lua")
        open(path, "w").write(lua_file(key, name, tables))
    print("r1061_splice: 4 lua defs written (19 tables, 4 pins)")

    # seam
    open(os.path.join(root, SEAM_REL), "w").write(seam_text())
    print("r1061_splice: seam rules/seams/siegefirereg.h written")

    # header rewrite
    open(hdr, "w").write(rewrite_header(src, vals_by_fn))
    print("r1061_splice: siegefire.h rewritten (mark + seam include + 19 bodies)")

    # frag
    open(os.path.join(root, FRAG_REL), "w").write(emit(frag_text(vals_by_fn)))
    print("r1061_splice: frag r1061_siegefire_registry.h written (8 labels)")

    # regtest include after the R1059 line
    rt = open(os.path.join(root, REGTEST_REL)).read()
    anchor = '#include "rules/audits/r1059_miscmagic_registry.h"  // R1059'
    if anchor not in rt:
        die("regtest.cpp R1059 anchor missing")
    line = '#include "rules/audits/r1061_siegefire_registry.h"  // R1061'
    rt = rt.replace(anchor, anchor + chr(10) + line, 1)
    open(os.path.join(root, REGTEST_REL), "w").write(rt)
    print("r1061_splice: regtest.cpp include added after the R1059 line")

    print("r1061_splice: applied 19, already 0; census 1127 -> 1135 (+8)")

if __name__ == "__main__":
    main()
