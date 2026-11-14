#!/usr/bin/env python3
# r1049_splice.py - the R1049 splice: the UA
# Character Race Table II de-wire (rules/ua/
# subracelevels.h).
#
# WHAT retires:
#   rules/ua/subracelevels.h  the 101 ladder
#     int arrays (kIi*K/-L/-F), the 47
#     RaceLevelColumn descriptors, and the 19
#     LevelGate gate lists -> NEW DIRECTORY
#     content/tables/ua_levels/ (six sub-table
#     defs ua_table2_a .. ua_table2_f plus
#     ua_level_gates). Ladder rows: name = the
#     column tag (kIiaCleric -> "iia_cleric"),
#     band = { rung key, next rung key - 1 }
#     ascending with the last band open to
#     999999 (the above-top terminal), gp = the
#     level (0 = U), xp = the footnote id. Gate
#     rows: name = the gate tag (kIiaG1 ->
#     "iia_g1"), band = { the parsed ABILITY_*
#     enum value, the min score }, gp = the
#     orMode flag (only iic_ag6 is 1).
#
# Seams are header-only (the R1040-R1044 idiom)
# INSIDE namespace rules (this header is all-
# namespace, unlike the R1048 file-scope four -
# the Termux compile lesson): uaLevelsReg() /
# uaLevelColumn(tag) / uaLevelGateList(tag, g,
# n). Every accessor signature is unchanged (the
# r324/r325 audits pin them); the
# subraceLevelLimit / subraceLevelFootnote bodies
# stay verbatim; the subraceLevelColumn and
# subraceLevelGates switches keep their enum
# mapping, returning registry views. The floor
# rule (below the first rung reads the first
# rung), the between-rows rule (reads the lower
# rung) and the above-top terminal ride the band
# encoding; the U (level 0) entries ride gp.
# Humans and unmapped pairs read -1 (no column).
#
# DO NOT hand-edit anything this tool writes.
import os
import re
import sys

ROOT = os.getcwd()
SUB = "rules/ua/subracelevels.h"
ABILITY_H = "rules/engine/character.h"
FRAG = "rules/audits/r1049_subrace_level_registry.h"
REGTEST = "regtest.cpp"
LUA_DIR = "content/tables/ua_levels"
CENSUS_BEFORE = 1052
CENSUS_AFTER = 1058
SEAM_MARK = "the R1049 UA levels registry seam"
APPLIED_MARK = "// R1049 applied"
TOP_BAND = 999999


def die(msg):
    sys.stderr.write("r1049_splice: FATAL: %s\n"
                     % msg)
    sys.exit(1)


def replace_once(src, old, new, what):
    n = src.count(old)
    if n != 1:
        die("%s anchor appears %d times (want 1)"
            % (what, n))
    return src.replace(old, new)


def parse_header(src):
    if SEAM_MARK in src:
        die("seam already present")
    arrs = {}
    for m in re.finditer(
            r"static const int (k[A-Za-z0-9]+)\[\]"
            r" = \{(.*?)\};", src, re.S):
        arrs[m.group(1)] = [
            int(x) for x in re.findall(
                r"-?\d+", m.group(2))]
    cols = {}
    for m in re.finditer(
            r"static const RaceLevelColumn "
            r"(k[A-Za-z0-9]+) = \{\s*(\d+),"
            r"\s*(k\w+),\s*(k\w+),"
            r"\s*(k\w+|0)\s*\};", src):
        cols[m.group(1)] = (
            int(m.group(2)), m.group(3),
            m.group(4), m.group(5))
    gates = {}
    for m in re.finditer(
            r"static const LevelGate "
            r"(k[A-Za-z0-9]+)\[\] = \{(.*?)};",
            src, re.S):
        gates[m.group(1)] = re.findall(
            r"\{ (ABILITY_\w+), (\d+) \}",
            m.group(2))
    if len(arrs) != 101:
        die("parsed %d int arrays (want 101)"
            % len(arrs))
    if len(cols) != 47:
        die("parsed %d columns (want 47)"
            % len(cols))
    if len(gates) != 19:
        die("parsed %d gate lists (want 19)"
            % len(gates))
    for name, (n, k, l, f) in cols.items():
        if len(arrs[k]) != n or \
                len(arrs[l]) != n:
            die("column %s n mismatch" % name)
        if f != "0" and len(arrs[f]) != n:
            die("column %s footnote n mismatch"
                % name)
    return arrs, cols, gates


def parse_abilities():
    src = open(os.path.join(
        ROOT, ABILITY_H)).read()
    m = re.search(r"ABILITY_STR"
                  r"\s*=\s*0,",
                  src)
    if not m:
        die("ability enum not found")
    vals = {"ABILITY_STR": 0}
    v = 1
    for name in re.findall(
            r"ABILITY_[A-Z]+"
            r"(?=\s*[,}])",
            src[m.end():]):
        if name in vals or \
                name == "ABILITY_COUNT":
            continue
        vals[name] = v
        v += 1
    if len(vals) != 6 or \
            "ABILITY_INT" not in vals or \
            "ABILITY_WIS" not in vals or \
            "ABILITY_DEX" not in vals or \
            "ABILITY_CHA" not in vals:
        die("ability enum parse incomplete")
    return vals


def tag_of(name):
    body = name[1:]
    parts = re.findall(
        r"[A-Z][a-z0-9]*|[A-Z](?=[A-Z]|$)"
        r"|[a-z0-9]+", body)
    return "_".join(p.lower()
                    for p in parts)


def sub_of(name):
    m = re.match(r"kIi([a-f])", name)
    if not m:
        die("array %s has no sub-table letter"
            % name)
    return m.group(1)


def column_data(arrs, cols, cname):
    n, k, l, f = cols[cname]
    keys = arrs[k]
    levels = arrs[l]
    fns = arrs[f] if f != "0" else [0] * n
    return keys, levels, fns


def lua_def(key, title, rows, col_count,
            extra_pins):
    out = []
    w = out.append
    w("-- %s" % key)
    w("-- The R1049 UA Table II de-wire.")
    words = title.split()
    line = "--"
    for word in words:
        if len(line) + 1 + len(word) > 70:
            w(line)
            line = "--"
        line += " " + word
    if line.strip() != "--":
        w(line)
    w("-- Row encoding: name = the column tag,")
    w("-- band = { rung key, next rung key - 1 }")
    w("-- with the last band open to %d" % TOP_BAND)
    w("-- (the above-top terminal), gp = the")
    w("-- level (0 = U), xp = the footnote id.")
    w("-- xp_hi/gp_hi/qty are loader-required")
    w("-- padding (MiscItemRow shape), all zero.")
    w("-- The accessors and the clamp semantics")
    w("-- live in rules/ua/subracelevels.h and")
    w("-- are unchanged.")
    w("-- DO NOT hand-edit: tools/r1049_splice.py")
    w("-- is the only writer.")
    w("")
    w("return {")
    w("  key = \"%s\"," % key)
    w("  name = \"%s\"," % title)
    w("  sources = {")
    w("    { part = 0, round = 1049 },")
    w("  },")
    w("  pins = {")
    w("    { name = \"%sRowCount\", value = %d,"
      % (key, len(rows)))
    w("      comment = \"the ladder rows\" },")
    w("    { name = \"%sColCount\", value = %d,"
      % (key, col_count))
    w("      comment = \"the print columns\" },")
    for nm, val, com in extra_pins:
        w("    { name = \"%s\", value = %d,"
          % (nm, val))
        w("      comment = \"%s\" }," % com)
    w("  },")
    w("  tables = {},")
    w("  rows = {")
    for (name, lo, hi, gp, xp) in rows:
        w("    { name = \"%s\"," % name)
        w("      set = \"%s\"," % key)
        w("      band = { %d, %d },"
          % (lo, hi))
        w("      gp = %d, xp = %d,"
          % (gp, xp))
        w("      xp_hi = 0, gp_hi = 0,"
          " qty = { 0, 0 } },")
    w("  },")
    w("}")
    w("")
    return "\n".join(out)


def build_lua(arrs, cols, gates, abilities):
    defs = {}
    titles = {}
    for c in "abcdef":
        key = "ua_table2_" + c
        defs[key] = {}
        titles[key] = (
            "The UA Character Race Table"
            " II.%s" % c.upper())
    for cname in cols:
        sub = sub_of(cname)
        tag = tag_of(cname)
        keys, levels, fns = column_data(
            arrs, cols, cname)
        rows = []
        for i in range(len(keys)):
            lo = keys[i]
            hi = keys[i + 1] - 1 \
                if i + 1 < len(keys) \
                else TOP_BAND
            rows.append((tag, lo, hi,
                         levels[i], fns[i]))
        defs["ua_table2_" + sub][tag] = rows
    files = {}
    for key in sorted(defs):
        rows = []
        colnames = sorted(defs[key])
        for tag in colnames:
            rows.extend(defs[key][tag])
        files[key + ".lua"] = lua_def(
            key, titles[key], rows,
            len(colnames), [])
    grows = []
    for gname, pairs in gates.items():
        tag = tag_of(gname)
        ormode = 1 if gname == "kIicAG6" \
            else 0
        for (ability, mn) in pairs:
            grows.append(
                (tag, abilities[ability],
                 int(mn), ormode, 0))
    files["ua_level_gates.lua"] = lua_def(
        "ua_level_gates",
        "The UA Table II level gates "
        "(the footnoted ability pairs)",
        grows, len(gates),
        [("ua_level_gatesOrModeRows",
          sum(1 for r in grows if r[3] == 1),
          "the orMode rows (iic_ag6)")])
    return files


SEAM = (
    "// -------------------------------------------------\n"
    "// " + SEAM_MARK + "\n"
    "//\n"
    "// One registry behind the Table II\n"
    "// reads: content/tables/ua_levels/ (the\n"
    "// six sub-tables plus the gates). The\n"
    "// per-tag views below build the column\n"
    "// and gate structures on first use -\n"
    "// every accessor signature and every\n"
    "// clamp stays as the print reads it.\n"
    "// DO NOT hand-edit: tools/r1049_splice.py\n"
    "// is the only writer.\n"
    "inline items::MiscItemRegistry&\n"
    "uaLevelsReg() {\n"
    "    static items::MiscItemRegistry reg;\n"
    "    static bool loaded = false;\n"
    "    if (!loaded) {\n"
    "        loaded = true;\n"
    "        reg.loadDirectory(\n"
    "            \"content/tables/ua_levels\");\n"
    "    }\n"
    "    return reg;\n"
    "}\n"
    "\n"
    "inline const rules::RaceLevelColumn*\n"
    "uaLevelColumn(const char* tag) {\n"
    "    struct ColCache {\n"
    "        std::map<std::string,\n"
    "            RaceLevelColumn> cols;\n"
    "        std::map<std::string,\n"
    "            std::vector<int>> keys,\n"
    "            levels, fns;\n"
    "    };\n"
    "    static ColCache cache;\n"
    "    static bool built = false;\n"
    "    if (!built) {\n"
    "        built = true;\n"
    "        std::map<std::string,\n"
    "            std::vector<const items::\n"
    "            MiscItemRow*>> byTag;\n"
    "        for (const auto& kv :\n"
    "                 uaLevelsReg().all()) {\n"
    "            if (kv.first ==\n"
    "                \"ua_level_gates\") continue;\n"
    "            for (const auto& r :\n"
    "                     kv.second.rows)\n"
    "                byTag[r.name]\n"
    "                    .push_back(&r);\n"
    "        }\n"
    "        for (auto& kv : byTag) {\n"
    "            std::sort(kv.second.begin(),\n"
    "                kv.second.end(),\n"
    "                [](const items::\n"
    "                MiscItemRow* a,\n"
    "                const items::\n"
    "                MiscItemRow* b) {\n"
    "                    return a->bandLo\n"
    "                           < b->bandLo; });\n"
    "            cache.keys[kv.first]\n"
    "                = std::vector<int>();\n"
    "            cache.levels[kv.first]\n"
    "                = std::vector<int>();\n"
    "            cache.fns[kv.first]\n"
    "                = std::vector<int>();\n"
    "            for (const auto* r :\n"
    "                     kv.second) {\n"
    "                cache.keys[kv.first]\n"
    "                    .push_back(r->bandLo);\n"
    "                cache.levels[kv.first]\n"
    "                    .push_back(r->gp);\n"
    "                cache.fns[kv.first]\n"
    "                    .push_back(r->xp);\n"
    "            }\n"
    "            RaceLevelColumn c;\n"
    "            c.n = (int)cache\n"
    "                .keys[kv.first].size();\n"
    "            c.keys = cache\n"
    "                .keys[kv.first].data();\n"
    "            c.levels = cache\n"
    "                .levels[kv.first].data();\n"
    "            c.fns = cache\n"
    "                .fns[kv.first].data();\n"
    "            cache.cols[kv.first] = c;\n"
    "        }\n"
    "    }\n"
    "    auto it = cache.cols.find(tag);\n"
    "    return it == cache.cols.end()\n"
    "               ? 0 : &it->second;\n"
    "}\n"
    "\n"
    "inline void uaLevelGateList(\n"
    "        const char* tag,\n"
    "        const rules::LevelGate*& g, int& n) {\n"
    "    struct GateCache {\n"
    "        std::map<std::string,\n"
    "            std::vector<LevelGate>> lists;\n"
    "    };\n"
    "    static GateCache cache;\n"
    "    static bool built = false;\n"
    "    if (!built) {\n"
    "        built = true;\n"
    "        const items::MiscItemDef* d =\n"
    "            uaLevelsReg().find(\n"
    "                \"ua_level_gates\");\n"
    "        if (d) {\n"
    "            std::map<std::string,\n"
    "                std::vector<const items::\n"
    "                MiscItemRow*>> byTag;\n"
    "            for (const auto& r : d->rows)\n"
    "                byTag[r.name]\n"
    "                    .push_back(&r);\n"
    "            for (auto& kv : byTag) {\n"
    "                std::sort(kv.second.begin(),\n"
    "                    kv.second.end(),\n"
    "                    [](const items::\n"
    "                    MiscItemRow* a,\n"
    "                    const items::\n"
    "                    MiscItemRow* b) {\n"
    "                        return a->bandLo\n"
    "                               < b->bandLo; });\n"
    "                std::vector<LevelGate> lg;\n"
    "                for (const auto* r :\n"
    "                         kv.second)\n"
    "                    lg.push_back(LevelGate{\n"
    "                        r->bandLo,\n"
    "                        r->bandHi });\n"
    "                cache.lists[kv.first] = lg;\n"
    "            }\n"
    "        }\n"
    "    }\n"
    "    auto it = cache.lists.find(tag);\n"
    "    if (it == cache.lists.end()) {\n"
    "        g = 0; n = 0; return;\n"
    "    }\n"
    "    g = it->second.data();\n"
    "    n = (int)it->second.size();\n"
    "}\n"
    "\n")


def rewrite_sub(src, arrs, cols, gates):
    src = replace_once(
        src, "#include \"subraces.h\"",
        "#include \"subraces.h\"\n"
        "#include \"items/MiscItemRegistry.h\"",
        "the subraces include")
    start = src.index(
        "// ---- II.A: dwarves (UA p.8) ----")
    end = src.index("struct LevelGate {")
    src = src[:start] + (
        "// ---- the retired Table II ladders "
        "----------\n"
        "// The 101 ladder arrays, the 47 column\n"
        "// descriptors and the 19 gate lists\n"
        "// are registry rows now (R1049):\n"
        "// content/tables/ua_levels/ - the six\n"
        "// sub-table defs and the gates def.\n"
        "// The tags map kIiaCleric ->\n"
        "// iia_cleric and so on. DO NOT\n"
        "// hand-edit: tools/r1049_splice.py is\n"
        "// the only writer.\n\n"
    ) + src[end:]
    anchor = (
        "struct LevelGate {\n"
        "    int stat;   // ABILITY_*\n"
        "    int min;\n"
        "};\n")
    src = replace_once(
        src, anchor, anchor + SEAM,
        "the LevelGate struct")
    gstart = src.index(
        "// II.A assassin: fn1 INT 18 DEX 19;")
    gend = src.index("// The escalation riders")
    src = src[:gstart] + (
        "// ---- the retired gate lists "
        "-------------\n"
        "// The footnoted ability gates are\n"
        "// registry rows now (R1049): the\n"
        "// ua_level_gates def, one row per\n"
        "// ability pair, name = the gate tag.\n"
        "// The orMode rider (the fn6 elf\n"
        "// assassin either-pair read) stays\n"
        "// explicit in subraceLevelGates.\n\n"
    ) + src[gend:]
    for cname in cols:
        old = "&" + cname
        if src.count(old) < 1:
            die("column %s referenced %d times"
                % (cname, src.count(old)))
        src = src.replace(
            old,
            "uaLevelColumn(\"%s\")"
            % tag_of(cname))
    for gname, pairs in gates.items():
        for m in list(re.finditer(
                r"g = %s; n = \d+;" % gname,
                src)):
            pass
        nfound = len(re.findall(
            r"g = %s; n = \d+;" % gname, src))
        if nfound != 1:
            die("gate %s assignments %d (want 1)"
                % (gname, nfound))
        src = re.sub(
            r"g = %s; n = \d+;" % gname,
            "uaLevelGateList(\"%s\", g, n);"
            % tag_of(gname),
            src, count=1)
    return src


def emit_int_arr(F, a, indent, decl,
                   vals, tail):
    a("%s%s {" % (indent, decl))
    line = " " * (len(indent) + 4)
    cur = ""
    for v in vals:
        piece = str(v) + ", "
        if len(line) + len(cur) + \
                len(piece.strip()) > 74:
            a(line + cur.rstrip())
            cur = ""
        cur += piece
    if cur.strip():
        a(line + cur.rstrip(", ")
          + "};")
    else:
        a("%s};" % (line.rstrip()))


def intlist(vals):
    return ", ".join(str(v) for v in vals)


def build_fragment(arrs, cols, gates,
                   abilities):
    # The R1047/R1048 seat idiom: a
    # brace-scoped block included INSIDE
    # the battery-runner function. No
    # pragma, no includes, no namespace,
    # no function wrapper, no std::map/
    # set/sort (regtest.cpp provides only
    # cstdio/cstring/string at global
    # scope). Early exits are
    # "if (bad) return 1;".
    F = []
    a = F.append
    tags = sorted(tag_of(c) for c in cols)
    gtags = sorted(tag_of(g) for g in gates)
    NAB = len(abilities)
    orm_want = sum(len(p) for g, p in
                   gates.items()
                   if g == "kIicAG6")
    colinfo = []
    for cname in sorted(cols):
        keys, levels, fns = column_data(
            arrs, cols, cname)
        his = [keys[i + 1] - 1
               for i in range(len(keys) - 1)]
        his.append(TOP_BAND)
        colinfo.append(
            ("ua_table2_" + sub_of(cname),
             tag_of(cname),
             keys, his, levels, fns))
    a("    // ==== R1049: UA subrace level"
      " registry " + "=" * 33)
    a("    // The R1049 de-wire: the 101"
      " ladder arrays, the 47")
    a("    // RaceLevelColumn descriptors and"
      " the 19 gate")
    a("    // lists of rules/ua/subracelevels.h"
      " ride")
    a("    // items::MiscItemRegistry from"
      " content/tables/")
    a("    // ua_levels/ (the six sub-tables"
      " ua_table2_a..f plus")
    a("    // ua_level_gates). Six sections:"
      " load, counts, bands,")
    a("    // data, rows, edges. Census %d"
      " -> %d. DO NOT"
      % (CENSUS_BEFORE, CENSUS_AFTER))
    a("    // hand-edit: tools/r1049_splice.py"
      " is the only writer.")
    a("    {")
    a("        int bad = 0;")
    # -- 1. load
    a("        // -- 1. load"
      " ---------------------------------")
    a("        {")
    a("            items::MiscItemRegistry"
      " reg;")
    a("            int n ="
      " reg.loadDirectory(")
    a("                "
      "\"content/tables/ua_levels\");")
    a("            if (n != 7) ++bad;")
    a("            if (!reg.errors()"
      ".empty()) ++bad;")
    a("            for (const auto& kv :"
      " reg.all())")
    a("                if ((int)kv"
      ".second.sources")
    a("                    .size() != 1)")
    a("                    ++bad;")
    a("        }")
    a("        printf(\"R1049 subrace level"
      " registry load audit:"
      " bad %d\\n\", bad);")
    a("        if (bad) return 1;")
    a("        bad = 0;")
    # -- 2. counts
    a("        // -- 2. counts"
      " ---------------------------------")
    a("        {")
    a("            items::MiscItemRegistry"
      " reg;")
    a("            reg.loadDirectory(")
    a("                "
      "\"content/tables/ua_levels\");")
    counts = []
    for c in "abcdef":
        key = "ua_table2_" + c
        ncol = sum(1 for x in cols
                   if sub_of(x) == c)
        nrow = sum(len(column_data(
            arrs, cols, x)[0])
            for x in cols
            if sub_of(x) == c)
        counts.append((key, nrow,
                       ncol, 2, 0))
    ngrow = sum(len(p) for p in
                gates.values())
    orm = sum(len(v) for k, v in
              gates.items()
              if k == "kIicAG6")
    counts.append(("ua_level_gates",
                   ngrow, 19, 3, orm))
    for key, nrow, ncol, npin, \
            pin2 in counts:
        a("            {")
        a("                const items::"
          "MiscItemDef* d =")
        a("                    reg.find("
          "\"%s\");" % key)
        a("                if (!d) { ++bad; }"
          " else {")
        a("                    for (const"
          " auto& r :")
        a("                             "
          "d->rows)")
        a("                        if (r.set !="
          " d->key)")
        a("                            ++bad;")
        a("                    if ((int)d"
          "->rows.size() != %d" % nrow)
        a("                        || (int)d"
          "->pins.size() != %d" % npin)
        a("                        || d"
          "->pins[0].value != %d"
          % nrow)
        a("                        || d"
          "->pins[1].value != %d"
          % ncol)
        if pin2:
            a("                        || d"
              "->pins[%d].value != %d"
              % (npin - 1, pin2))
        a("                        || (int)d"
          "->tables.size() != 0)")
        a("                        ++bad;")
        a("                }")
        a("            }")
    a("        }")
    a("        printf(\"R1049 subrace level"
      " registry counts audit:"
      " bad %d\\n\", bad);")
    a("        if (bad) return 1;")
    a("        bad = 0;")
    # -- 3. bands
    a("        // -- 3. bands"
      " ---------------------------------")
    a("        {")
    a("            items::MiscItemRegistry"
      " reg;")
    a("            reg.loadDirectory(")
    a("                "
      "\"content/tables/ua_levels\");")
    for dkey, tag, keys, his, levels, \
            fns in colinfo:
        a("            {")
        a("                const items::"
          "MiscItemDef* d =")
        a("                    reg.find("
          "\"%s\");" % dkey)
        a("                if (!d) { ++bad; }"
          " else {")
        a("                    int prevLo ="
          " %d;" % keys[0])
        a("                    int lastHi ="
          " 0;")
        a("                    int count ="
          " 0;")
        a("                    for (const"
          " auto& r :")
        a("                             "
          "d->rows)")
        a("                        if (r.name =="
          " \"%s\") {" % tag)
        a("                            ++count;")
        a("                            if (r"
          ".bandLo != prevLo")
        a("                                || r"
          ".gpHi != 0")
        a("                                || r"
          ".gp < 0")
        a("                                || r"
          ".gp > 29")
        a("                                || r"
          ".xp < 0")
        a("                                || r"
          ".xp > 6)")
        a("                                ++bad;")
        a("                            prevLo ="
          " r.bandHi + 1;")
        a("                            lastHi ="
          " r.bandHi;")
        a("                        }")
        a("                    if (count != %d"
          % len(keys))
        a("                        || lastHi !="
          " %d)" % TOP_BAND)
        a("                        ++bad;")
        a("                }")
        a("            }")
    a("            {")
    a("                const items::"
      "MiscItemDef* d =")
    a("                    reg.find("
      "\"ua_level_gates\");")
    a("                if (!d) { ++bad; }"
      " else {")
    a("                    for (const auto& r :"
      " d->rows)")
    a("                        if (r.bandLo < 0")
    a("                            || r"
      ".bandLo >= %d" % NAB)
    a("                            || r"
      ".bandHi < 15")
    a("                            || r"
      ".bandHi > 19")
    a("                            || (r.gp != 0")
    a("                                && r.gp"
      " != 1)")
    a("                            || r.xp != 0)")
    a("                            ++bad;")
    a("                    int orm = 0;")
    a("                    for (const auto& r :"
      " d->rows)")
    a("                        if (r.gp == 1)"
      " ++orm;")
    a("                    if (orm != %d)"
      " ++bad;" % orm_want)
    a("                }")
    a("            }")
    a("        }")
    a("        printf(\"R1049 subrace level"
      " registry bands audit:"
      " bad %d\\n\", bad);")
    a("        if (bad) return 1;")
    a("        bad = 0;")
    # -- 4. data
    a("        // -- 4. data"
      " ---------------------------------")
    a("        {")
    a("            items::MiscItemRegistry"
      " reg;")
    a("            reg.loadDirectory(")
    a("                "
      "\"content/tables/ua_levels\");")
    for dkey, tag, keys, his, levels, \
            fns in colinfo:
        a("            {")
        a("                const items::"
          "MiscItemDef* d =")
        a("                    reg.find("
          "\"%s\");" % dkey)
        a("                if (!d) { ++bad; }"
          " else {")
        a("                    int matches ="
          " 0;")
        emit_int_arr(F, a,
                     "                    ",
                     "const int wantLo[] =",
                     keys, "")
        emit_int_arr(F, a,
                     "                    ",
                     "const int wantHi[] =",
                     his, "")
        emit_int_arr(F, a,
                     "                    ",
                     "const int wantLvl[] =",
                     levels, "")
        emit_int_arr(F, a,
                     "                    ",
                     "const int wantFn[] =",
                     fns, "")
        a("                    for (int i ="
          " 0; i < %d; ++i) {"
          % len(keys))
        a("                        const items::"
          "MiscItemRow* rr = 0;")
        a("                        for (const"
          " auto& r :")
        a("                                 "
          "d->rows)")
        a("                            if (r.name =="
          " \"%s\"" % tag)
        a("                                && r"
          ".bandLo ==")
        a("                                   "
          "wantLo[i])")
        a("                                rr = &r;")
        a("                        if (!rr")
        a("                            || rr"
          "->bandHi !=")
        a("                               "
          "wantHi[i]")
        a("                            || rr"
          "->gp !=")
        a("                               "
          "wantLvl[i]")
        a("                            || rr"
          "->xp !=")
        a("                               "
          "wantFn[i])")
        a("                            ++bad;")
        a("                    }")
        a("                    for (const auto&"
          " r : d->rows)")
        a("                        if (r.name =="
          " \"%s\")" % tag)
        a("                            ++matches;")
        a("                    if (matches !="
          " %d) ++bad;" % len(keys))
        a("                }")
        a("            }")
    a("            const items::"
      "MiscItemDef* dg =")
    a("                reg.find("
      "\"ua_level_gates\");")
    a("            if (!dg) { ++bad; } else {")
    for gname in sorted(gates):
        pairs = gates[gname]
        tag = tag_of(gname)
        orm = 1 if gname == "kIicAG6" else 0
        a("                {")
        a("                    int matches ="
          " 0;")
        emit_int_arr(F, a,
                     "                    ",
                     "const int wantStat[] =",
                     [abilities[ab]
                      for ab, _ in pairs], "")
        emit_int_arr(F, a,
                     "                    ",
                     "const int wantMin[] =",
                     [int(mn)
                      for _, mn in pairs], "")
        a("                    for (int i ="
          " 0; i < %d; ++i) {"
          % len(pairs))
        a("                        const items::"
          "MiscItemRow* rr = 0;")
        a("                        for (const"
          " auto& r :")
        a("                                 "
          "dg->rows)")
        a("                            if (r.name =="
          " \"%s\"" % tag)
        a("                                && r"
          ".bandLo ==")
        a("                                   "
          "wantStat[i]")
        a("                                && r"
          ".bandHi ==")
        a("                                   "
          "wantMin[i])")
        a("                                rr = &r;")
        a("                        if (!rr")
        a("                            || rr"
          "->gp != %d)" % orm)
        a("                            ++bad;")
        a("                    }")
        a("                    for (const auto&"
          " r : dg->rows)")
        a("                        if (r.name =="
          " \"%s\")" % tag)
        a("                            ++matches;")
        a("                    if (matches !="
          " %d) ++bad;" % len(pairs))
        a("                }")
    a("            }")
    a("        }")
    a("        printf(\"R1049 subrace level"
      " registry data audit:"
      " bad %d\\n\", bad);")
    a("        if (bad) return 1;")
    a("        bad = 0;")
    # -- 5. rows
    a("        // -- 5. rows (the full"
      " cross-read) ---------")
    a("        {")
    a("            const char* colTags[] = {")
    for i in range(0, len(tags), 3):
        grp = tags[i:i + 3]
        a("                "
          + ", ".join('"%s"' % t
                      for t in grp)
          + ("," if i + 3 < len(tags)
             else ""))
    a("            };")
    a("            const int NCOLS = %d;"
      % len(tags))
    a("            const rules::RaceLevelColumn*"
      " colSet[NCOLS];")
    a("            for (int i = 0;"
      " i < NCOLS; ++i)")
    a("                colSet[i] ="
      " rules::uaLevelColumn(")
    a("                    colTags[i]);")
    a("            const char* gateTags[] = {")
    for i in range(0, len(gtags), 3):
        grp = gtags[i:i + 3]
        a("                "
          + ", ".join('"%s"' % t
                      for t in grp)
          + ("," if i + 3 < len(gtags)
             else ""))
    a("            };")
    a("            const int NGATES = %d;"
      % len(gtags))
    a("            const rules::LevelGate*"
      " gateSet[NGATES];")
    a("            int gateN[NGATES];")
    a("            for (int i = 0;"
      " i < NGATES; ++i) {")
    a("                gateSet[i] = 0;")
    a("                gateN[i] = 0;")
    a("                rules::"
      "uaLevelGateList(")
    a("                    gateTags[i],")
    a("                    gateSet[i],"
      " gateN[i]);")
    a("                if (!gateSet[i]")
    a("                    || gateN[i] == 0)")
    a("                    ++bad;")
    a("            }")
    a("            int seenCols[NCOLS];")
    a("            int seenGates[NGATES];")
    a("            for (int i = 0;"
      " i < NCOLS; ++i)")
    a("                seenCols[i] = 0;")
    a("            for (int i = 0;"
      " i < NGATES; ++i)")
    a("                seenGates[i] = 0;")
    a("            for (int s = 0;")
    a("                 s < rules::SUBRACE_COUNT;"
      " ++s)")
    a("                for (int c = 0;")
    a("                     c <"
      " rules::UACLASS_COUNT;"
      " ++c)")
    a("                    for (int f = 0;"
      " f <= 1; ++f) {")
    a("                        const"
      " rules::RaceLevelColumn*"
          " col =")
    a("                            rules::"
      "subraceLevelColumn(")
    a("                                "
      "(rules::CharSubRace)s,")
    a("                                "
      "(rules::UaClass)c, f);")
    a("                        if (!col) {")
    a("                            if (rules::"
      "subraceLevelLimit(")
    a("                                    "
      "(rules::CharSubRace)s,")
    a("                                    "
      "(rules::UaClass)c,")
    a("                                    "
      "1, f) != -1)")
    a("                                ++bad;")
    a("                            continue;")
    a("                        }")
    a("                        int idx = -1;")
    a("                        for (int i = 0;"
      " i < NCOLS; ++i)")
    a("                            if (colSet[i]"
      " == col)")
    a("                                idx = i;")
    a("                        if (idx < 0)"
      " ++bad;")
    a("                        else"
      " ++seenCols[idx];")
    a("                        for (int i = 0;"
      " i < col->n; ++i) {")
    a("                            int k ="
      " col->keys[i];")
    a("                            int want ="
      " col->levels[i];")
    a("                            if (rules::"
      "subraceLevelLimit(")
    a("                                    "
      "(rules::CharSubRace)s,")
    a("                                    "
      "(rules::UaClass)c,")
    a("                                    "
      "k, f) != want)")
    a("                                ++bad;")
    a("                            if (col->fns"
      " && rules::")
    a("                                "
      "subraceLevelFootnote(")
    a("                                    "
      "(rules::CharSubRace)s,")
    a("                                    "
      "(rules::UaClass)c,")
    a("                                    "
      "k, f) !=")
    a("                                "
      "col->fns[i])")
    a("                                ++bad;")
    a("                        }")
    a("                        int top ="
      " col->keys[col->n - 1];")
    a("                        if (rules::"
      "subraceLevelLimit(")
    a("                                "
      "(rules::CharSubRace)s,")
    a("                                "
      "(rules::UaClass)c,")
    a("                                top + 1,"
      " f) !=")
    a("                            col"
      "->levels[col->n - 1])")
    a("                            ++bad;")
    a("                        if (rules::"
      "subraceLevelLimit(")
    a("                                "
      "(rules::CharSubRace)s,")
    a("                                "
      "(rules::UaClass)c,")
    a("                                col"
      "->keys[0] - 1, f) !=")
    a("                            col"
      "->levels[0])")
    a("                            ++bad;")
    a("                        for (int fn = 0;")
    a("                             fn <= 6;"
      " ++fn) {")
    a("                            const "
      "rules::LevelGate* g = 0;")
    a("                            int n = 0;")
    a("                            int orMode ="
      " 0;")
    a("                            rules::"
      "subraceLevelGates(")
    a("                                "
      "(rules::CharSubRace)s,")
    a("                                "
      "(rules::UaClass)c, fn,")
    a("                                g, n,"
      " orMode);")
    a("                            if (fn == 0) {")
    a("                                if (g || n)")
    a("                                    ++bad;")
    a("                                continue;")
    a("                            }")
    a("                            if (!g)"
      " continue;")
    a("                            int gi = -1;")
    a("                            for (int i ="
      " 0; i < NGATES; ++i)")
    a("                                if (gateSet[i]"
      " == g)")
    a("                                    gi = i;")
    a("                            if (gi < 0)"
      " ++bad;")
    a("                            else"
      " ++seenGates[gi];")
    a("                            if (orMode != 0")
    a("                                && orMode"
      " != 1)")
    a("                                ++bad;")
    a("                        }")
    a("                    }")
    a("            for (int i = 0;"
      " i < NCOLS; ++i)")
    a("                if (seenCols[i] == 0)")
    a("                    ++bad;")
    a("            for (int i = 0;"
      " i < NGATES; ++i)")
    a("                if (seenGates[i] == 0)")
    a("                    ++bad;")
    a("        }")
    a("        printf(\"R1049 subrace level"
      " registry rows audit:"
      " bad %d\\n\", bad);")
    a("        if (bad) return 1;")
    a("        bad = 0;")
    # -- 6. edges
    a("        // -- 6. edges"
      " ---------------------------------")
    a("        {")
    a("            if (rules::"
      "subraceStrengthLevelKey(")
    a("                    17, -1) != 17000)")
    a("                ++bad;")
    a("            if (rules::"
      "subraceStrengthLevelKey(")
    a("                    18, -1) != 18000"
      " ||")
    a("                rules::"
      "subraceStrengthLevelKey(")
    a("                    18, 1) != 18010"
      " ||")
    a("                rules::"
      "subraceStrengthLevelKey(")
    a("                    18, 99) != 18990"
      " ||")
    a("                rules::"
      "subraceStrengthLevelKey(")
    a("                    18, 100) != 18999"
      " ||")
    a("                rules::"
      "subraceStrengthLevelKey(")
    a("                    19, 50) != 19000)")
    a("                ++bad;")
    a("            if (rules::"
      "subraceLevelLimit(")
    a("                    rules::SUB_HUMAN,"
      " rules::UACLASS_FIGHTER, 18000, 0)")
    a("                != -1)")
    a("                ++bad;")
    a("            if (rules::"
      "subraceLevelLimit(")
    a("                    rules::SUB_NONE,"
      " rules::UACLASS_CLERIC, 18000, 0)")
    a("                != -1)")
    a("                ++bad;")
    a("            if (rules::"
      "singleClassLevelBonus() != 2)")
    a("                ++bad;")
    a("            if (rules::"
      "elfRangerAbove15Level() != 8 ||")
    a("                rules::"
      "halfElfRanger19Level() != 12 ||")
    a("                rules::"
      "halfElfRanger20Level() != 14 ||")
    a("                rules::"
      "halflingDruid16Level() != 8 ||")
    a("                rules::"
      "halflingDruid17Level() != 10 ||")
    a("                rules::"
      "halflingDruid18Level() != 12)")
    a("                ++bad;")
    a("            {")
    a("                const rules::LevelGate* g = 0;")
    a("                int n = 0;")
    a("                int orMode = 0;")
    a("                rules::"
      "subraceLevelGates(")
    a("                    rules::SUB_ELF_WILD,"
      " rules::UACLASS_ASSASSIN, 6,")
    a("                    g, n, orMode);")
    a("                if (!g || n != 2"
      "                    || orMode != 1)")
    a("                    ++bad;")
    a("            }")
    a("            {")
    a("                const rules::LevelGate* g = 0;")
    a("                int n = 0;")
    a("                int orMode = 0;")
    a("                rules::"
      "subraceLevelGates(")
    a("                    rules::SUB_DWARF_HILL,"
      " rules::UACLASS_DRUID, 1,")
    a("                    g, n, orMode);")
    a("                if (g || n) ++bad;")
    a("            }")
    a("        }")
    a("        printf(\"R1049 subrace level"
      " registry edges audit:"
      " bad %d\\n\", bad);")
    a("        if (bad) return 1;")
    a("    }")
    return "\n".join(F) + "\n"


def census_count():
    out = os.popen(
        "cat rules/audits/*.h regtest.cpp"
        " | grep -c 'audit: bad %d'").read()
    return int(out.strip())


def main():
    if not os.path.exists(
            os.path.join(ROOT, SUB)):
        die("run from the repo root (%s missing)"
            % SUB)
    src = open(os.path.join(
        ROOT, SUB)).read()
    if APPLIED_MARK in src:
        print("applied 0, already 1")
        print("SPLICE OK")
        return
    if census_count() != CENSUS_BEFORE:
        die("census %d (want %d)"
            % (census_count(), CENSUS_BEFORE))
    arrs, cols, gates = parse_header(src)
    abilities = parse_abilities()
    files = build_lua(arrs, cols, gates,
                      abilities)
    dpath = os.path.join(ROOT, LUA_DIR)
    os.makedirs(dpath, exist_ok=True)
    for fname in sorted(files):
        open(os.path.join(dpath, fname),
             "w").write(files[fname])
    new_sub = rewrite_sub(src, arrs, cols,
                          gates)
    new_sub = new_sub.replace(
        "#pragma once",
        APPLIED_MARK + "\n#pragma once", 1)
    open(os.path.join(ROOT, SUB),
         "w").write(new_sub)
    frag = build_fragment(arrs, cols, gates,
                          abilities)
    open(os.path.join(ROOT, FRAG),
         "w").write(frag)
    rt = open(os.path.join(
        ROOT, REGTEST)).read()
    rt = replace_once(
        rt,
        "    #include \"rules/audits/"
        "r1048_straggler_registry.h\"  // R1048",
        "    #include \"rules/audits/"
        "r1048_straggler_registry.h\"  // R1048"
        "\n    #include \"rules/audits/"
        "r1049_subrace_level_registry.h\""
        "  // R1049",
        "the R1048 regtest include")
    open(os.path.join(ROOT, REGTEST),
         "w").write(rt)
    if census_count() != CENSUS_AFTER:
        die("census after %d (want %d)"
            % (census_count(), CENSUS_AFTER))
    print("census %d -> %d audit printf patterns"
          % (CENSUS_BEFORE, CENSUS_AFTER))
    print("applied 1, rewrote 2 tracked files, "
          "wrote %d new files"
          % (len(files) + 1))
    print("SPLICE OK")


main()
