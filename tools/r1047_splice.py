#!/usr/bin/env python3
# r1047_splice.py - the R1047 splice: the PHB class
# grid de-wire (the bard college column + the bard
# druid slots grid + the druid slots grid).
#
# WHAT: the two printed grids left in-file by R1044
# (rules/phb/bard.h: kCollege[23], kSlots[23][5])
# and the druid class slots grid (rules/phb/
# druidspells.h: kSlots[14][7]) ride items::
# MiscItemRegistry under NEW SIBLING DIRECTORY
# content/tables/class_grids/ (def keys
# bard_colleges, bard_druid_slots, druid_slots).
# Every accessor signature is unchanged (the
# r186/r228/r235a audits and the engine pin them);
# the clamp semantics stay verbatim, including the
# quirk that druidSpellSlots clamps a low level UP
# to 1 while bardDruidSlots returns 0 below 1.
#
# Row encodings (the MiscItemRow/MiscItemTable
# schema; the loader contract is hard - every def
# carries sources/pins/tables, rows carry every
# field, the R1046 fix-2 lesson):
#   bard_colleges    rows[23]: name the college,
#                   band { level, level }, rest zero
#   bard_druid_slots tables[1] "grid": 23 x 5 slot
#                   counts flat, row-major; pins
#                   RowCount 23, ColCount 5
#   druid_slots     tables[1] "grid": 14 x 7 slot
#                   counts flat, row-major; pins
#                   RowCount 14, ColCount 7
#
# The seam is header-only (the R1040-R1044 idiom):
# gridReg()/gridRows()/gridValues() in subclasses.h
# (the PHB registry home; bard.h already includes
# it, druidspells.h gains the include). The gates,
# the poetics constants, the henchmen ladder and
# the 77-spell roster stay in-file (constants and
# rosters, not tables).
#
# DO NOT hand-edit anything this tool writes.
import os
import re
import sys

ROOT = os.getcwd()
BARD = "rules/phb/bard.h"
DRUID = "rules/phb/druidspells.h"
SUBCL = "rules/phb/subclasses.h"
FRAG = "rules/audits/r1047_class_grid_registry.h"
LUA_DIR = "content/tables/class_grids"
CENSUS_BEFORE = 1040
CENSUS_AFTER = 1046
SEAM_MARK = "R1047 grid registry seam"


def die(msg):
    sys.stderr.write("r1047_splice: FATAL: %s\n" % msg)
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
def parse_colleges(src):
    sig = "kCollege[23] = {"
    d = src.index(sig) + len(sig)
    e = src.index("\n    };", d)
    names = re.findall(r'"([^"]+)"', src[d:e])
    if len(names) != 23:
        die("kCollege has %d names, want 23" % len(names))
    for n in names:
        if not n or not n.strip():
            die("empty college name at %r" % names)
    return names


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


def parse_all(bard, druid):
    colleges = parse_colleges(bard)
    bard_slots = parse_grid(
        bard, "kSlots[23][5] = {", 23, 5)
    druid_slots = parse_grid(
        druid, "kSlots[14][7] = {", 14, 7)
    return colleges, bard_slots, druid_slots


# ---------------------------------------------------------------------------
# lua emission
def colleges_lua(names):
    L = []
    L.append("-- class grid def: bard_colleges\n")
    L.append("-- The PHB bard college column, the R1047\n")
    L.append("-- de-wire. Bards Table II, rules/phb/bard.h.\n")
    L.append("-- Row encoding: name = the printed\n")
    L.append("-- college, band = { level, level } the\n")
    L.append("-- bard level, rest zero. The accessor and\n")
    L.append("-- the clamp semantics live in\n")
    L.append("-- rules/phb/bard.h and are unchanged.\n")
    L.append("-- DO NOT hand-edit: tools/r1047_splice.py\n")
    L.append("-- is the only writer.\n")
    L.append("\nreturn {\n")
    L.append('  key = "bard_colleges",\n')
    L.append('  name = "The bard college ladder '
            '(23 rows)",\n')
    L.append("  rows = {\n")
    row = ('    { name = "%s", set = "bard_colleges", '
           "band = { %d, %d }, "
           "xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, "
           "qty = { 0, 0 } },\n")
    for i, n in enumerate(names):
        L.append(row % (n, i + 1, i + 1))
    L.append("  },\n")
    L.append("  sources = {\n")
    L.append("    { part = 0, round = 1047 },\n")
    L.append("  },\n")
    L.append("  pins = {\n")
    L.append('    { name = "bard_collegesRowCount", '
            "value = 23, "
            'comment = "the bard levels" },\n')
    L.append("  },\n")
    L.append("  tables = {},\n")
    L.append("}\n")
    return "".join(L)


def grid_lua(key, title, row_n, col_n, flat):
    L = []
    L.append("-- class grid def: %s\n" % key)
    L.append("-- %s, the R1047 de-wire.\n" % title)
    L.append("-- Table encoding: tables[1] name \"grid\",\n")
    L.append("-- values = the printed slot counts flat\n")
    L.append("-- (row-major, %d rows x %d cols).\n"
             % (row_n, col_n))
    L.append("-- The accessor and the clamp semantics\n")
    L.append("-- live in the phb header and are unchanged.\n")
    L.append("-- DO NOT hand-edit: tools/r1047_splice.py\n")
    L.append("-- is the only writer.\n")
    L.append("\nreturn {\n")
    L.append('  key = "%s",\n' % key)
    L.append('  name = "%s (%d x %d)",\n'
             % (title, row_n, col_n))
    L.append("  sources = {\n")
    L.append("    { part = 0, round = 1047 },\n")
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


# round-trip: the emitted lua parses back to the
# parsed data (the R1042 discipline)
RT_ROW = re.compile(
    r'\{ name = "([^"]+)", set = "([^"]+)", '
    r"band = \{ (\d+), (\d+) \}, "
    r"xp = (\d+), xp_hi = (\d+), gp = (\d+), "
    r"gp_hi = (\d+), qty = \{ (\d+), (\d+) \} \},")
RT_VAL = re.compile(r"(\d+),?")


def roundtrip(names, key, flat, text):
    if key == "bard_colleges":
        got = RT_ROW.findall(text)
        if len(got) != 23:
            die("%s round-trip: %d rows, want 23"
                % (key, len(got)))
        for i, g in enumerate(got):
            want = (names[i], key, str(i + 1),
                    str(i + 1), "0", "0", "0", "0",
                    "0", "0")
            if g != want:
                die("%s round-trip row %d: %s != %s"
                    % (key, i, g, want))
    else:
        m = re.search(r'values = \{\n(.*?)\n    \} \}',
                      text, re.S)
        if not m:
            die("%s round-trip: no values block" % key)
        got = [int(x) for x in RT_VAL.findall(m.group(1))]
        if got != flat:
            die("%s round-trip: values differ"
                % key)
        # the loader contract: pins and tables present
        for needle in ("sources = {", "pins = {",
                       "tables = {"):
            if needle not in text:
                die("%s round-trip: missing %s"
                    % (key, needle))


# ---------------------------------------------------------------------------
# the seam (subclasses.h)
SEAM = (
    "// ---- the R1047 grid registry seam "
    "----------------------------------\n"
    "// The PHB class grids (the bard college\n"
    "// column, the bard druid slots grid, the\n"
    "// druid slots grid) ride\n"
    "// items::MiscItemRegistry from\n"
    "// content/tables/class_grids/ (def keys\n"
    "// bard_colleges, bard_druid_slots,\n"
    "// druid_slots). The slots defs encode the\n"
    "// grid as tables[1] name \"grid\", values\n"
    "// flat row-major (RowCount x ColCount pins);\n"
    "// the colleges def encodes rows (name the\n"
    "// college, band { level, level }). This seam\n"
    "// is header-only (the R1040-R1044 idiom);\n"
    "// every accessor signature is unchanged (the\n"
    "// r186/r228/r235a audits and the engine pin\n"
    "// them); the clamp semantics stay verbatim.\n"
    "\n"
    "inline items::MiscItemRegistry& gridReg() {\n"
    "    static items::MiscItemRegistry reg;\n"
    "    static bool loaded = false;\n"
    "    if (!loaded) {\n"
    "        loaded = true;\n"
    "        reg.loadDirectory("
    "\"content/tables/class_grids\");\n"
    "    }\n"
    "    return reg;\n"
    "}\n"
    "\n"
    "// the registry-backed per-view caches (the\n"
    "// R1032-R1044 idiom; function-local statics in\n"
    "// inline functions are shared across TUs)\n"
    "inline const std::vector<items::MiscItemRow>&\n"
    "gridRows(const char* name) {\n"
    "    static std::map<std::string,\n"
    "        std::vector<items::MiscItemRow>> cache;\n"
    "    auto it = cache.find(name);\n"
    "    if (it == cache.end()) {\n"
    "        const items::MiscItemDef* d =\n"
    "            gridReg().find(name);\n"
    "        it = cache.emplace(\n"
    "            name, d ? d->rows\n"
    "                   : std::vector<"
    "items::MiscItemRow>()).first;\n"
    "    }\n"
    "    return it->second;\n"
    "}\n"
    "\n"
    "inline const std::vector<long long>&\n"
    "gridValues(const char* name) {\n"
    "    static std::map<std::string,\n"
    "        std::vector<long long>> cache;\n"
    "    auto it = cache.find(name);\n"
    "    if (it == cache.end()) {\n"
    "        std::vector<long long> v;\n"
    "        const items::MiscItemDef* d =\n"
    "            gridReg().find(name);\n"
    "        if (d && d->tables.size() == 1\n"
    "            && d->tables[0].name == \"grid\")\n"
    "            v = d->tables[0].values;\n"
    "        it = cache.emplace(name, v).first;\n"
    "    }\n"
    "    return it->second;\n"
    "}\n"
    "\n")


def rewrite_subclasses(src):
    anchor = ("}\n\n\n"
              "// The subclass indices (stable; append only)\n")
    return replace_once(
        src, anchor, "}\n\n" + SEAM + "\n"
        "// The subclass indices (stable; append only)\n",
        "subclasses seam insert")


def rewrite_bard(src, colleges):
    # banner note
    src = replace_once(
        src,
        "// accessors read the registry view. The "
        "colleges,\n"
        "// the druid slots and the gates stay in-file\n"
        "// (constants and code, not tables).\n",
        "// accessors read the registry view. R1047: the\n"
        "// college column and the druid slots grid ride\n"
        "// content/tables/class_grids/ (the R1047 grid\n"
        "// seam in subclasses.h); the gates and the\n"
        "// career constants stay in-file (constants and\n"
        "// code, not tables).\n",
        "bard banner note")

    # the druid slots grid accessor
    sig = "inline int bardDruidSlots(int level, "
    s, e = region_of(src, sig + "int spellLevel) {")
    body = (
        "    if (level < 1) return 0;\n"
        "    if (level > 23) level = 23;\n"
        "    if (spellLevel < 1) spellLevel = 1;\n"
        "    if (spellLevel > 5) spellLevel = 5;\n"
        "    const auto& v = gridValues("
        "\"bard_druid_slots\");\n"
        "    if (v.empty()) return 0;   "
        "// defensive: unloaded view\n"
        "    return (int)v[(level - 1) * 5\n"
        "                 + (spellLevel - 1)];\n")
    src = src[:s] + sig + "int spellLevel) {\n" \
        + body + "}\n" + src[e:]

    # the college column accessor
    sig2 = ("inline const char* bardCollege("
            "int level) {")
    s, e = region_of(src, sig2)
    body2 = (
        "    const auto& rows = gridRows("
        "\"bard_colleges\");\n"
        "    if (rows.empty()) return \"\";   "
        "// defensive: unloaded view\n"
        "    if (level < 1) level = 1;\n"
        "    if (level > 23) level = 23;\n"
        "    return rows[level - 1].name.c_str();\n")
    src = src[:s] + sig2 + "\n" + body2 + "}\n" + src[e:]

    # retired-token checks
    for tok in ("kSlots[23][5]", "kCollege[23]",
                "static const char* const kCollege"):
        if tok in src:
            die("retired token survived in bard.h: %s"
                % tok)
    return src


def rewrite_druid(src):
    # banner note
    src = replace_once(
        src,
        "// lands as its own roster file with the "
        "same shape.\n",
        "// lands as its own roster file with the "
        "same shape.\n"
        "//\n"
        "// R1047: the 14 x 7 slots grid is\n"
        "// registry-native (content/tables/\n"
        "// class_grids/druid_slots.lua, the R1047\n"
        "// grid seam in subclasses.h); the roster\n"
        "// stays in-file as the printed record.\n",
        "druid banner note")

    # include
    src = replace_once(
        src,
        "#include <cstdint>\n\nnamespace rules {\n",
        "#include <cstdint>\n\n"
        "#include \"subclasses.h\"   // R1047: the "
        "grid registry seam\n"
        "\nnamespace rules {\n",
        "druid include")

    # the slots accessor
    sig = ("inline int druidSpellSlots(int druidLevel, "
           "int spellLevel) {")
    s, e = region_of(src, sig)
    body = (
        "    if (druidLevel < 1) druidLevel = 1;\n"
        "    if (druidLevel > 14) druidLevel = 14;\n"
        "    if (spellLevel < 1) spellLevel = 1;\n"
        "    if (spellLevel > 7) spellLevel = 7;\n"
        "    const auto& v = gridValues("
        "\"druid_slots\");\n"
        "    if (v.empty()) return 0;   "
        "// defensive: unloaded view\n"
        "    return (int)v[(druidLevel - 1) * 7\n"
        "                 + (spellLevel - 1)];\n")
    src = src[:s] + sig + "\n" + body + "}\n" + src[e:]

    if "kSlots[14][7]" in src:
        die("retired token survived in druidspells.h")
    return src


# ---------------------------------------------------------------------------
# the fragment (every pin computed from the parsed
# source; all engine calls qualified - the R1044
# fragment-scope lesson)
def build_fragment(colleges, bard_slots, druid_slots):
    L = []
    a = L.append
    a("    // ==== R1047: class grid registry "
      "================================\n")
    a("    // The R1047 de-wire: the PHB class grids\n")
    a("    // (the bard college column 23, the bard\n")
    a("    // druid slots 23 x 5, the druid slots\n")
    a("    // 14 x 7) ride items::MiscItemRegistry\n")
    a("    // from content/tables/class_grids/ (def\n")
    a("    // keys bard_colleges, bard_druid_slots,\n")
    a("    // druid_slots). This audit loads its own\n")
    a("    // registry instance and cross-reads every\n")
    a("    // cell through the inline accessor surface\n")
    a("    // (bardCollege/bardDruidSlots/\n")
    a("    // druidSpellSlots) and the gridRows/\n")
    a("    // gridValues seam, so the r186/r228/r235a\n")
    a("    // audits and this registry audit read the\n")
    a("    // same data through the same signatures.\n")
    a("    {\n")
    a("        int bad = 0;\n")
    # 1. load
    a("        // -- 1. load "
      "---------------------------------------\n")
    a("        {\n")
    a("            items::MiscItemRegistry t;\n")
    a('            if (t.loadDirectory('
      '"content/tables/class_grids") != 3)\n')
    a("                ++bad;\n")
    a("            if (!t.errors().empty()) ++bad;\n")
    a("            if (t.all().size() != 3) ++bad;\n")
    for k in ("bard_colleges", "bard_druid_slots",
              "druid_slots"):
        a('            if (t.all().count("%s") != 1) '
          "++bad;\n" % k)
    for k in ("bard_ladder", "bard_college",
              "druid_slot", "appendixa_door_location",
              ""):
        a('            if (t.all().count("%s")) '
          "++bad;\n" % k)
    a("        }\n")
    a('        printf("R1047 class grid registry load '
      'audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # 2. counts
    a("        // -- 2. counts "
      "-------------------------------------\n")
    a("        {\n")
    a("            items::MiscItemRegistry t;\n")
    a('            t.loadDirectory('
      '"content/tables/class_grids");\n')
    # colleges def
    a('            const auto* vc = t.find('
      '"bard_colleges");\n')
    a("            if (!vc) { ++bad; } else {\n")
    a("                if ((int)vc->rows.size() != 23)\n")
    a("                    ++bad;\n")
    a("                if ((int)vc->pins.size() != 1\n")
    a('                    || vc->pins[0].name != '
      'std::string("bard_collegesRowCount")\n')
    a("                    || vc->pins[0].value != 23)\n")
    a("                    ++bad;\n")
    a("                if ((int)vc->sources.size() != 1\n")
    a("                    || (int)vc->tables.size() != 0)\n")
    a("                    ++bad;\n")
    a("            }\n")
    # the two grid defs
    for key, rn, cn, vsz in (
            ("bard_druid_slots", 23, 5, 115),
            ("druid_slots", 14, 7, 98)):
        a('            const auto* v%s = t.find("%s");\n'
          % (key[0], key))
        a("            if (!v%s) { ++bad; } else {\n"
          % key[0])
        a("                if ((int)v%s->rows.size() "
          "!= 0)\n" % key[0])
        a("                    ++bad;\n")
        a("                if ((int)v%s->pins.size() "
          "!= 2\n" % key[0])
        a('                    || v%s->pins[0].name != '
          "std::string(\n" % key[0])
        a('                        "%sRowCount")\n' % key)
        a("                    || v%s->pins[0].value "
          "!= %d\n" % (key[0], rn))
        a('                    || v%s->pins[1].name != '
          "std::string(\n" % key[0])
        a('                        "%sColCount")\n' % key)
        a("                    || v%s->pins[1].value "
          "!= %d)\n" % (key[0], cn))
        a("                    ++bad;\n")
        a("                if ((int)v%s->sources.size() "
          "!= 1\n" % key[0])
        a("                    || (int)v%s->tables.size() "
          "!= 1)\n" % key[0])
        a("                    ++bad;\n")
        a("            }\n")
    a("        }\n")
    a('        printf("R1047 class grid registry counts '
      'audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # 3. bands (the axis shape)
    a("        // -- 3. bands (the level axis) "
      "------------\n")
    a("        {\n")
    a("            items::MiscItemRegistry t;\n")
    a('            t.loadDirectory('
      '"content/tables/class_grids");\n')
    a('            const auto* vc = t.find('
      '"bard_colleges");\n')
    a("            if (!vc) { ++bad; } else {\n")
    a("                for (int i = 0;\n")
    a("                     i < (int)vc->rows.size(); "
      "++i) {\n")
    a("                    const auto& r = vc->rows[i];\n")
    a("                    if (r.bandLo != i + 1\n")
    a("                        || r.bandHi != i + 1\n")
    a("                        || r.set != vc->key\n")
    a("                        || r.name.empty()\n")
    a("                        || r.gp != 0\n")
    a("                        || r.gpHi != 0\n")
    a("                        || r.xp != 0\n")
    a("                        || r.xpHi != 0\n")
    a("                        || r.qtyLo != 0\n")
    a("                        || r.qtyHi != 0) ++bad;\n")
    a("                }\n")
    a("            }\n")
    for key, vsz in (("b", 115), ("d", 98)):
        a('            const auto* v%s = t.find("%s");\n'
          % (key, "bard_druid_slots"
             if key == "b" else "druid_slots"))
        a("            if (!v%s) { ++bad; } else {\n"
          % key)
        a("                if (v%s->tables[0].name !=\n"
          % key)
        a('                    std::string("grid")\n')
        a("                    || (int)v%s->tables[0]."
          "values.size()\n" % key)
        a("                       != %d) ++bad;\n" % vsz)
        a("                for (long long x : "
          "v%s->tables[0].values)\n" % key)
        a("                    if (x < 0 || x > 9) "
          "++bad;\n")
        a("            }\n")
    a("        }\n")
    a('        printf("R1047 class grid registry bands '
      'audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # 4. data (famous pins, all computed)
    a("        // -- 4. data (famous pins, all "
      "computed) --\n")
    a("        {\n")
    # colleges: first, middle, last, and the seam row
    mid = 11   # level 12 (Canaith)
    a('            if (std::string(rules::bardCollege(1))\n')
    a("                    != std::string(%s)) ++bad;\n"
      % cq(colleges[0]))
    a("            if (std::string(rules::bardCollege(%d))\n"
      % (mid + 1))
    a("                    != std::string(%s)) ++bad;\n"
      % cq(colleges[mid]))
    a("            if (std::string(rules::bardCollege(23))\n")
    a("                    != std::string(%s)) ++bad;\n"
      % cq(colleges[22]))
    a('            if (rules::gridRows("bard_colleges")'
      "[%d].name\n" % mid)
    a("                    != std::string(%s)) ++bad;\n"
      % cq(colleges[mid]))
    # bard slots: first, last, a middle, the 16/1 pin
    pins = ((1, 1, 0), (23, 5, 114), (16, 1, 75),
            (10, 4, 48), (14, 5, 69))
    for lv, sl, idx in pins:
        a("            if (rules::bardDruidSlots(%d, %d) "
          "!= %d)\n" % (lv, sl, bard_slots[idx]))
        a("                ++bad;\n")
    # druid slots: first, last, the r228 pins
    pins = ((1, 1, 0), (14, 7, 97), (12, 4, 80),
            (9, 5, 60), (13, 4, 87))
    for dl, sl, idx in pins:
        a("            if (rules::druidSpellSlots(%d, %d) "
          "!= %d)\n" % (dl, sl, druid_slots[idx]))
        a("                ++bad;\n")
    a("        }\n")
    a('        printf("R1047 class grid registry data '
      'audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # 5. rows (the full cross-read)
    a("        // -- 5. rows (the full cross-read) "
      "--------\n")
    a("        {\n")
    a("            items::MiscItemRegistry t;\n")
    a('            t.loadDirectory('
      '"content/tables/class_grids");\n')
    a('            const auto* vc = t.find('
      '"bard_colleges");\n')
    a("            if (!vc) { ++bad; } else {\n")
    a("                for (int lv = 1; lv <= 23; ++lv)\n")
    a("                    if (std::string("
      "rules::bardCollege(lv))\n")
    a("                            != vc->rows[lv - 1]"
      ".name)\n")
    a("                        ++bad;\n")
    a("            }\n")
    for key, rn, cn, acc in (
            ("b", 23, 5, "bardDruidSlots"),
            ("d", 14, 7, "druidSpellSlots")):
        a('            const auto* v%s = t.find("%s");\n'
          % (key, "bard_druid_slots"
             if key == "b" else "druid_slots"))
        a("            if (!v%s) { ++bad; } else {\n"
          % key)
        a("                const auto& g =\n")
        a("                    v%s->tables[0].values;\n"
          % key)
        a("                for (int lv = 1; lv <= %d; "
          "++lv)\n" % rn)
        a("                    for (int sl = 1; "
          "sl <= %d; ++sl)\n" % cn)
        a("                        if (rules::%s(lv, sl)\n"
                          % acc)
        a("                                != (int)g["
          "(lv - 1) * %d\n" % cn)
        a("                                    + "
          "(sl - 1)])\n")
        a("                            ++bad;\n")
        a("            }\n")
    a("        }\n")
    a('        printf("R1047 class grid registry rows '
      'audit: bad %d\\n", bad);\n')
    a("        if (bad) return 1;\n")
    a("        bad = 0;\n")
    # 6. edges
    a("        // -- 6. edges (clamps, negatives) "
      "----------\n")
    a("        {\n")
    # bardDruidSlots: below 1 -> 0 (verbatim quirk);
    # level and column clamps
    a("            if (rules::bardDruidSlots(0, 1) != 0)\n")
    a("                ++bad;\n")
    a("            if (rules::bardDruidSlots(24, 3)\n")
    a("                    != rules::"
      "bardDruidSlots(23, 3))\n")
    a("                ++bad;\n")
    a("            if (rules::bardDruidSlots(24, 6)\n")
    a("                    != rules::"
      "bardDruidSlots(23, 5))\n")
    a("                ++bad;\n")
    a("            if (rules::bardDruidSlots(5, 0)\n")
    a("                    != rules::"
      "bardDruidSlots(5, 1))\n")
    a("                ++bad;\n")
    # druidSpellSlots: low level clamps UP to 1 (the
    # verbatim quirk), high clamps to 14, cols to 7
    a("            if (rules::druidSpellSlots(0, 1)\n")
    a("                    != rules::"
      "druidSpellSlots(1, 1))\n")
    a("                ++bad;\n")
    a("            if (rules::druidSpellSlots(99, 7)\n")
    a("                    != rules::"
      "druidSpellSlots(14, 7))\n")
    a("                ++bad;\n")
    a("            if (rules::druidSpellSlots(14, 8)\n")
    a("                    != rules::"
      "druidSpellSlots(14, 7))\n")
    a("                ++bad;\n")
    a("            if (rules::druidSpellSlots(14, 0)\n")
    a("                    != rules::"
      "druidSpellSlots(14, 1))\n")
    a("                ++bad;\n")
    # bardCollege clamps
    a("            if (std::string(rules::bardCollege(0))\n")
    a("                    != std::string(%s)) ++bad;\n"
      % cq(colleges[0]))
    a("            if (std::string("
      "rules::bardCollege(99))\n")
    a("                    != std::string(%s)) ++bad;\n"
      % cq(colleges[22]))
    # negatives: the seam must fail terminally
    a('            if (!rules::gridValues('
      '"no_such_table").empty())\n')
    a("                ++bad;\n")
    a('            if (!rules::gridRows('
      '"no_such_table").empty())\n')
    a("                ++bad;\n")
    a('            if (rules::gridReg().find('
      '"bard_ladder")\n')
    a("                    != nullptr) ++bad;\n")
    a('            if (rules::gridReg().find("") != '
      'nullptr)\n')
    a("                ++bad;\n")
    a("        }\n")
    a('        printf("R1047 class grid registry edges '
      'audit: bad %d\\n", bad);\n')
    a("    }\n")
    return "".join(L)


# static header checks (the R392/R1045 lessons)
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
    # the R1045 delivery miss, guarded: a qualified
    # call with an empty name (rules::(1)) is a bug
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
    if not os.path.exists(BARD):
        die("run from the repo root (%s missing)" % BARD)

    marker = os.path.join(LUA_DIR, "bard_colleges.lua")
    already = (os.path.exists(marker)
               and SEAM_MARK in open(SUBCL).read())
    if already:
        print("applied 0, already 1")
        print("SPLICE OK")
        return

    c = census()
    if c != CENSUS_BEFORE:
        die("census %d, expected %d" % (c, CENSUS_BEFORE))

    bard = open(BARD).read()
    druid = open(DRUID).read()
    colleges, bard_slots, druid_slots = parse_all(
        bard, druid)
    print("parsed: 23 colleges, 23x5 bard slots, "
          "14x7 druid slots")

    os.makedirs(LUA_DIR, exist_ok=True)
    files = {
        "bard_colleges.lua":
            colleges_lua(colleges),
        "bard_druid_slots.lua":
            grid_lua("bard_druid_slots",
                     "The bard druid spell slots grid",
                     23, 5, bard_slots),
        "druid_slots.lua":
            grid_lua("druid_slots",
                     "The druid spell slots grid",
                     14, 7, druid_slots),
    }
    for name, text in files.items():
        open(os.path.join(LUA_DIR, name), "w").write(text)
    roundtrip(colleges, "bard_colleges", None,
              files["bard_colleges.lua"])
    roundtrip(None, "bard_druid_slots", bard_slots,
              files["bard_druid_slots.lua"])
    roundtrip(None, "druid_slots", druid_slots,
              files["druid_slots.lua"])
    print("round-trip: 3 lua files parse back exact")

    subcl = rewrite_subclasses(open(SUBCL).read())
    static_checks(SUBCL, subcl)
    open(SUBCL, "w").write(subcl)

    new_bard = rewrite_bard(bard, colleges)
    static_checks(BARD, new_bard)
    open(BARD, "w").write(new_bard)

    new_druid = rewrite_druid(druid)
    static_checks(DRUID, new_druid)
    open(DRUID, "w").write(new_druid)

    frag = build_fragment(colleges, bard_slots,
                          druid_slots)
    static_checks("the fragment", frag)
    open(FRAG, "w").write(frag)

    reg = open("regtest.cpp").read()
    anchor = ('    #include "rules/audits/'
              'r1046_appendixa_dressing_registry.h"'
              '  // R1046\n')
    reg = replace_once(
        reg, anchor,
        anchor +
        '    #include "rules/audits/'
        'r1047_class_grid_registry.h"  // R1047\n',
        "regtest include")
    open("regtest.cpp", "w").write(reg)

    c = census()
    print("census: %d -> %d audit printf patterns"
          % (CENSUS_BEFORE, CENSUS_AFTER))
    if c != CENSUS_AFTER:
        die("census %d, expected %d" % (c, CENSUS_AFTER))

    print("applied 1, rewrote 4 tracked files, "
          "wrote 4 new files")
    print("SPLICE OK")


main()
