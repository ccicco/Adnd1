#!/usr/bin/env python3
# r1041_splice.py - the R1041 splice tool: retire the seven DMG
# pp.121-125 percentile item tables (III.A potions, III.C rings,
# III.D rods/staves/wands, III.E Special artifacts, III.F armor
# and shield, III.G swords, III.H misc weapons) from
# dm/treasure.cpp into NEW dir content/tables/treasure/ (7 lua,
# the items::MiscItemRow schema), and rewire the roller and the
# R122 pin surface onto registry views. The scrolls family
# (III.B) keeps its in-file shape (a different row shape, next
# family). Registry files (items/MiscItemRegistry.{h,cpp}) are
# NOT touched: the loader schema already covers these rows
# (free-form set strings, key = file stem, sources[] and pins[]
# mandatory).
#
# Idempotent: a second run reports "already 1" and rewrites
# nothing.
import os
import re
import sys

ROOT = os.getcwd()
CENSUS_BEFORE = 1004
CENSUS_AFTER = 1010


def die(msg):
    sys.stderr.write("r1041_splice: FATAL: %s\n" % msg)
    sys.exit(1)


def replace_once(src, old, new, what):
    n = src.count(old)
    if n != 1:
        die("%s anchor appears %d times (expected 1)" % (what, n))
    return src.replace(old, new)


# ---------------------------------------------------------------------------
# table inventory: (file-stem/def key, array name, section header line,
# row count, category number for the pin surface)
TABLES = [
    ("treasure_potions",  "kPotions",  "// ---- III.A Potions ----------------------------------------------------------", 35, 0),
    ("treasure_rings",    "kRings",    "// ---- III.C Rings ------------------------------------------------------------", 24, 2),
    ("treasure_rods",     "kRods",     "// ---- III.D Rods, Staves & Wands ---------------------------------------------", 30, 3),
    ("treasure_artifacts", "kArtifacts", "// ---- III.E. Special: Artifacts (no x.p.; printed g.p. sale values) -----------", 29, 12),
    ("treasure_armor",    "kArmor",    "// ---- III.F Armor and Shield ---------------------------------------------------", 26, 9),
    ("treasure_swords",   "kSwords",   "// ---- III.G Swords ---------------------------------------------------------------", 26, 10),
    ("treasure_weapons",  "kWeapons",  "// ---- III.H Miscellaneous Weapons ------------------------------------------------", 36, 11),
]

ROW_RE = re.compile(
    r'\{\s*(\d+),\s*(\d+),\s*"([^"]+)",\s*'
    r'(-?\d+)\s*,\s*(-?\d+),\s*(-?\d+)\s*,\s*(-?\d+),\s*'
    r'(-?\d+)\s*,\s*(-?\d+)\s*\}')

LUA_ROW = (
    '    { name = "%s", set = "%s", band = { %d, %d }, '
    'xp = %d, xp_hi = %d, gp = %d, gp_hi = %d, '
    'qty = { %d, %d } },\n')


def lua_file(key, rows):
    body = "".join(
        LUA_ROW % (r[2], key, r[0], r[1], r[3], r[4], r[5], r[6],
                   r[7], r[8]) for r in rows)
    fam = {
        "treasure_potions": "III.A potions (p.121)",
        "treasure_rings": "III.C rings (p.122)",
        "treasure_rods": "III.D rods, staves and wands (p.122)",
        "treasure_artifacts": "III.E Special artifacts (p.122)",
        "treasure_armor": "III.F armor and shield (p.123)",
        "treasure_swords": "III.G swords (p.123)",
        "treasure_weapons": "III.H miscellaneous weapons (p.123)",
    }[key]
    return (
        "-- treasure table def: %s\n"
        "-- The DMG Table %s, the R1041 de-wire: the printed\n"
        "-- percentile bands with the printed xp/gp values. xp_hi/\n"
        "-- gp_hi above the base mark a printed uniform range; qty\n"
        "-- above zero marks a printed bundle. The roller semantics\n"
        "-- (band scan on 1+d100, fallback the last row) live in\n"
        "-- dm/treasure.cpp and are unchanged.\n"
        "-- DO NOT hand-edit: tools/r1041_splice.py is the only writer.\n"
        "\n"
        "return {\n"
        '  key = "%s",\n'
        '  name = "Table %s",\n'
        "  rows = {\n"
        "%s"
        "  },\n"
        "  sources = {\n"
        "    { part = 0, round = 1041 },\n"
        "  },\n"
        "  pins = {\n"
        '    { name = "%sRowCount", value = %d, '
        'comment = "the printed row count" },\n'
        "  },\n"
        "  tables = {},\n"
        "}\n"
        % (key, fam, key, fam.split(" (")[0], body, key, len(rows)))


# ---------------------------------------------------------------------------
def parse_tables(src):
    out = {}
    for key, arr, header, want, _cat in TABLES:
        i = src.count(header)
        if i != 1:
            die("header for %s appears %d times" % (key, i))
        start = src.index(header)
        decl = "static const ItemRow %s[] = {" % arr
        if src.count(decl) != 1:
            die("declaration for %s appears %d times"
                % (arr, src.count(decl)))
        dstart = src.index(decl)
        if dstart < start:
            die("declaration precedes header for %s" % key)
        end = src.index("};", dstart)
        block = src[dstart:end]
        rows = [(int(a), int(b), name, int(c), int(d), int(e),
                 int(f), int(g), int(h))
                for a, b, name, c, d, e, f, g, h
                in ROW_RE.findall(block)]
        if len(rows) != want:
            die("%s: parsed %d rows (expected %d)"
                % (key, len(rows), want))
        # band chain: 1..100 contiguous, in order
        for i, r in enumerate(rows):
            if r[1] < r[0] or r[0] < 1 or r[1] > 100:
                die("%s row %d: bad band" % (key, i))
            if i == 0 and r[0] != 1:
                die("%s: first band does not start at 1" % key)
            if i > 0 and r[0] != rows[i - 1][1] + 1:
                die("%s row %d: band gap" % (key, i))
            if i == len(rows) - 1 and r[1] != 100:
                die("%s: last band does not reach 100" % key)
        out[key] = rows
    return out


def find_row(tables, key, name):
    for i, r in enumerate(tables[key]):
        if r[2] == name:
            return i, r
    die("row %r not found in %s" % (name, key))


# ---------------------------------------------------------------------------
def rewrite_treasure(src, tables):
    # -- 1. the struct + makeItem block -> the registry plumbing --
    OLD_STRUCT = (
        "struct ItemRow {\n"
        "    int lo, hi;\n"
        "    const char* name;\n"
        '    int xp, xpHi;      // xpHi > xp => uniform [xp, xpHi]\n'
        '    int gp, gpHi;      // gpHi > gp => uniform [gp, gpHi]\n'
        '    int qlo, qhi;      // qty range (0 = single)\n'
        "};\n"
        "\n"
        "static MagicItem makeItem(rules::Dice& dice, const ItemRow& r) {\n"
        "    MagicItem m;\n"
        "    m.name = r.name;\n"
        "    m.xp = valIn(dice, r.xp, r.xpHi);\n"
        "    m.gp = valIn(dice, r.gp, r.gpHi);\n"
        "    if (r.qhi > 0) m.qty = inRange(dice, r.qlo, r.qhi);\n"
        "    return m;\n"
        "}")
    NEW_STRUCT = (
        "// R1041 (the registry-native de-wire, the R1028/R1032-R1040\n"
        "// shape): the seven printed percentile tables (DMG pp.121-125)\n"
        "// retired into content/tables/treasure/ - one lua per family,\n"
        "// rows the items::MiscItemRow schema, set names = the def keys.\n"
        "// The roller and the pin surface read the registry views below;\n"
        "// the roll semantics (band scan on 1+d100, fallback the last\n"
        "// row) are the pickMiscRow semantics, unchanged. The scrolls\n"
        "// family (III.B) keeps its in-file shape. The R122 pin audits\n"
        "// read through the public accessors, so they pin the same\n"
        "// rows untouched.\n"
        "static items::MiscItemRegistry& tReg() {\n"
        "    // One-time lazy load (the miscReg shape: the engine loads\n"
        "    // its own registries).\n"
        "    static items::MiscItemRegistry reg;\n"
        "    static bool loaded = false;\n"
        "    if (!loaded) {\n"
        "        loaded = true;\n"
        '        reg.loadDirectory("content/tables/treasure");\n'
        "    }\n"
        "    return reg;\n"
        "}\n"
        "\n"
        "// Per-table views, band-sorted (the miscView idiom; the defs\n"
        "// arrive in band order, the sort is the stability belt).\n"
        "static const std::vector<items::MiscItemRow>& itemView(\n"
        "        const char* set) {\n"
        "    static std::map<std::string,\n"
        "        std::vector<items::MiscItemRow>> cache;\n"
        "    auto it = cache.find(set);\n"
        "    if (it == cache.end()) {\n"
        "        std::vector<items::MiscItemRow> v;\n"
        "        for (const auto& kv : tReg().all())\n"
        "            for (const auto& r : kv.second.rows)\n"
        "                if (r.set == set) v.push_back(r);\n"
        "        std::stable_sort(v.begin(), v.end(),\n"
        "                        [](const items::MiscItemRow& a,\n"
        "                           const items::MiscItemRow& b) {\n"
        "                            return a.bandLo < b.bandLo;\n"
        "                        });\n"
        "        it = cache.emplace(set, std::move(v)).first;\n"
        "    }\n"
        "    return it->second;\n"
        "}")
    src = replace_once(src, OLD_STRUCT, NEW_STRUCT, "struct block")

    # -- 2. retire the seven array blocks --
    for key, arr, header, want, _cat in TABLES:
        start = src.index(header)
        decl = "static const ItemRow %s[] = {" % arr
        dstart = src.index(decl)
        end = src.index("};", dstart) + 2
        block = src[dstart:end]
        if len(ROW_RE.findall(block)) != want:
            die("%s block row count drifted" % key)
        seam = ("// %s retired into content/tables/treasure/%s.lua "
                "(R1041)" % (header[8:].rstrip(), key))
        src = src[:start] + seam + src[end:]

    # -- 3. retire pickRow --
    OLD_PICK = (
        "// ---- table row picker ------------------------------------------------------------\n"
        "static MagicItem pickRow(rules::Dice& dice, const ItemRow* rows, int n) {\n"
        "    int r = 1 + d100(dice);\n"
        "    for (int i = 0; i < n; ++i)\n"
        "        if (r >= rows[i].lo && r <= rows[i].hi)\n"
        "            return makeItem(dice, rows[i]);\n"
        "    return makeItem(dice, rows[n - 1]);\n"
        "}\n"
        "\n")
    src = replace_once(src, OLD_PICK, "", "pickRow block")

    # -- 3b. the pickMiscRow comment quotes the retired name --
    src = replace_once(
        src,
        "// The pickRow semantics on registry rows: linear band scan on "
        "1+d100,\n// fallback the last row.",
        "// The band-scan row-picker semantics on registry rows:\n"
        "// linear scan on 1+d100, fallback the last row.",
        "pickMiscRow comment")

    # -- 4. rollFromCategoryUnset cases (exact per-case anchors) --
    cases = [
        (0, "treasure_potions", "kPotions", "case"),
        (2, "treasure_rings", "kRings", "case"),
        (3, "treasure_rods", "kRods", "case"),
        (9, "treasure_armor", "kArmor", "case"),
        (10, "treasure_swords", "kSwords", "case"),
        (11, "treasure_weapons", "kWeapons", "default"),
    ]
    for case, key, arr, kind in cases:
        if kind == "case":
            sp = "case %d:  return" % case if case < 10 \
                else "case %d: return" % case
            old = ("        %s pickRow(dice, %s, "
                   "COUNT_OF(%s));" % (sp, arr, arr))
            new = ('        %s pickMiscRow(dice, '
                   'itemView("%s"));' % (sp, key))
        else:
            old = ("        default: return pickRow(dice, %s, "
                   "COUNT_OF(%s));" % (arr, arr))
            new = ('        default: return pickMiscRow(dice, '
                   'itemView("%s"));' % key)
        src = replace_once(src, old, new, "case %d" % case)

    # -- 5. adjustSpecial's artifact dispatch --
    src = replace_once(
        src,
        "        return pickRow(dice, kArtifacts, COUNT_OF(kArtifacts));",
        '        return pickMiscRow(dice, itemView("treasure_artifacts"));',
        "artifact dispatch")

    # -- 6. the pin surface (comment + pinTableFor + both accessors) --
    start = src.index("// ---- R122: line-diff pins")
    tail = ("    out->qtyLo = r.qlo;  out->qtyHi = r.qhi;\n"
            "    return true;\n}")
    tstart = src.index(tail)
    if tstart < start:
        die("pin region tail precedes head")
    end = tstart + len(tail)
    region = src[start:end]
    for marker in ("pinTableFor", "magicTablePinCount", "magicTablePin",
                   "COUNT_OF(kSpellScrolls) + 9", "miscView"):
        if marker not in region:
            die("pin region missing %r" % marker)
    if "kPotions" not in region or "kArtifacts" not in region:
        die("pin region does not look pristine")
    NEW_PINS = (
        "// ---- R122: line-diff pins ---------------------------------------------------\n"
        "// The battery reads any printed row of the pp.121-125 tables so they\n"
        "// are pinned, not just rolled (the R122 line-diff found all 383 rows\n"
        "// faithful). Category 1 (scrolls) keeps its in-file shape - its pin\n"
        "// count is the structure: 16 spell bands + 8 protection scrolls + 1\n"
        "// curse row. The seven percentile families and the Special artifact\n"
        "// table read the R1041 registry views (set names = def keys).\n"
        "static const char* const kSetFor[13] = {\n"
        '    "treasure_potions",          // 0  III.A\n'
        "    nullptr,                     // 1  III.B scrolls (in-file)\n"
        '    "treasure_rings",            // 2  III.C\n'
        '    "treasure_rods",             // 3  III.D\n'
        "    nullptr,                     // 4-8 III.E.1-5 (miscView)\n"
        "    nullptr,\n"
        "    nullptr,\n"
        "    nullptr,\n"
        "    nullptr,\n"
        '    "treasure_armor",            // 9  III.F\n'
        '    "treasure_swords",           // 10 III.G\n'
        '    "treasure_weapons",          // 11 III.H\n'
        '    "treasure_artifacts"         // 12 Special\n'
        "};\n"
        "\n"
        "int magicTablePinCount(int category) {\n"
        "    if (category == 1)\n"
        "        return COUNT_OF(kSpellScrolls) + 9;  // + protection & curse\n"
        "    if (category >= 4 && category <= 8)     // registry-native misc tables\n"
        "        return (int)miscView(category - 3).size();\n"
        "    if (category < 0 || category > 12 || !kSetFor[category])\n"
        "        return 0;\n"
        "    return (int)itemView(kSetFor[category]).size();\n"
        "}\n"
        "\n"
        "bool magicTablePin(int category, int row, TablePin* out) {\n"
        "    if (!out || category == 1) return false;\n"
        "    if (category >= 4 && category <= 8) {    // registry-native misc tables\n"
        "        const auto& rows = miscView(category - 3);\n"
        "        if (row < 0 || row >= (int)rows.size()) return false;\n"
        "        const auto& r = rows[row];           // views are static: name lives\n"
        "        out->lo = r.bandLo;  out->hi = r.bandHi;\n"
        "        out->name = r.name.c_str();\n"
        "        out->xp = r.xp;      out->xpHi = r.xpHi;\n"
        "        out->gp = r.gp;      out->gpHi = r.gpHi;\n"
        "        out->qtyLo = r.qtyLo; out->qtyHi = r.qtyHi;\n"
        "    return true;\n"
        "    }\n"
        "    if (category < 0 || category > 12 || !kSetFor[category])\n"
        "        return false;\n"
        "    const auto& rows = itemView(kSetFor[category]);\n"
        "    if (row < 0 || row >= (int)rows.size()) return false;\n"
        "    const auto& r = rows[row];               // views are static: name lives\n"
        "    out->lo = r.bandLo;  out->hi = r.bandHi;\n"
        "    out->name = r.name.c_str();\n"
        "    out->xp = r.xp;      out->xpHi = r.xpHi;\n"
        "    out->gp = r.gp;      out->gpHi = r.gpHi;\n"
        "    out->qtyLo = r.qtyLo; out->qtyHi = r.qtyHi;\n"
        "    return true;\n"
        "}")
    src = src[:start] + NEW_PINS + src[end:]
    return src


# ---------------------------------------------------------------------------
def build_fragment(tables):
    def view(key):
        return "t.all().at(\"%s\").rows" % key

    out = []
    out.append(
        "    // ==== R1041: treasure item registry "
        "======================================\n"
        "    // The R1041 de-wire: the seven pp.121-125 percentile\n"
        "    // families ride items::MiscItemRegistry from\n"
        "    // content/tables/treasure/ (set names = def keys);\n"
        "    // this audit loads its own registry instance and\n"
        "    // cross-reads every row through the engine pin\n"
        "    // surface (magicTablePin), so the r122 structural\n"
        "    // audit and this registry audit read the same data.\n"
        "    {\n"
        "        int bad = 0;\n")

    # -- 1. load ---------------------------------------------------------
    neg_keys = ["treasure_scroll", "treasure_potion",
                "treasure_scroll_spells", "alchemy_jug",
                "castle_master", "appendixp_kit",
                "treasure_potions_rows"]
    out.append("        // -- 1. load --------------------------------------\n")
    out.append(
        "        items::MiscItemRegistry t;\n"
        "        if (t.loadDirectory(\"content/tables/treasure\") != 7)\n"
        "            ++bad;\n"
        "        if (!t.errors().empty()) ++bad;\n"
        "        if (t.all().size() != 7) ++bad;\n")
    for key, *_ in TABLES:
        out.append("        if (t.all().count(\"%s\") != 1) ++bad;\n" % key)
    for k in neg_keys:
        out.append("        if (t.all().count(\"%s\")) ++bad;\n" % k)
    out.append(
        "        printf(\"R1041 treasure item registry load audit: "
        "bad %d\\n\", bad);\n"
        "        if (bad) return 1;\n"
        "        bad = 0;\n")

    # -- 2. counts -------------------------------------------------------
    out.append("        // -- 2. counts -------------------------------------\n")
    out.append(
        "        {\n"
        "            static const int kRows[13] = { 35, 25, 24, 30, 33,\n"
        "                30, 33, 36, 35, 26, 26, 36, 29 };\n"
        "            for (int c = 0; c <= 12; ++c)\n"
        "                if (dm::treasure::magicTablePinCount(c)\n"
        "                    != kRows[c]) ++bad;\n"
        "        }\n")
    for key, _arr, _hdr, want, _cat in TABLES:
        out.append("        if ((int)%s.size() != %d) ++bad;\n"
                   % (view(key), want))
    out.append(
        "        printf(\"R1041 treasure item registry counts audit: "
        "bad %d\\n\", bad);\n"
        "        if (bad) return 1;\n"
        "        bad = 0;\n")

    # -- 3. bands ---------------------------------------------------------
    out.append("        // -- 3. bands --------------------------------------\n")
    for key, _arr, _hdr, _want, cat in TABLES:
        out.append(
            "        {\n"
            "            const auto& rows = %s;\n"
            "            int prevHi = 0;\n"
            "            for (const auto& r : rows) {\n"
            "                if (r.bandLo != prevHi + 1\n"
            "                    || r.bandHi < r.bandLo\n"
            "                    || r.bandHi > 100) { ++bad; break; }\n"
            "                prevHi = r.bandHi;\n"
            "            }\n"
            "            if (prevHi != 100) ++bad;\n"
            "        }\n" % view(key))
    out.append(
        "        printf(\"R1041 treasure item registry bands audit: "
        "bad %d\\n\", bad);\n"
        "        if (bad) return 1;\n"
        "        bad = 0;\n")

    # -- 4. data: the famous rows, through the engine pin surface ---------
    out.append("        // -- 4. data (famous rows) -----------------------\n")
    out.append("        {\n"
               "            dm::treasure::TablePin p;\n")
    famous = []
    i, r = find_row(tables, "treasure_potions",
                    "Potion of Animal Control")
    famous.append((0, i, r))
    i, r = find_row(tables, "treasure_potions", "Potion of Delusion")
    famous.append((0, i, r))
    i, r = find_row(tables, "treasure_potions", "Potion of Poison")
    famous.append((0, i, r))
    i, r = find_row(tables, "treasure_potions",
                    "Potion of Water Breathing")
    famous.append((0, i, r))
    i, r = find_row(tables, "treasure_rings", "Ring of Protection")
    famous.append((2, i, r))
    i, r = find_row(tables, "treasure_armor",
                    "Shield -1, missile attractor")
    famous.append((9, i, r))
    hammers = [(k, i, r) for k in ("treasure_swords",
                                   "treasure_weapons")
               for i, r in enumerate(tables[k])
               if r[2] == "Hammer +2"]
    if len(hammers) != 2:
        die("expected the twin Hammer +2 rows, found %d" % len(hammers))
    famous.extend(({"treasure_swords": 10, "treasure_weapons": 11}[k], i, r)
                  for k, i, r in hammers)
    i, r = find_row(tables, "treasure_weapons", "Arrow +2")
    famous.append((11, i, r))
    i, r = find_row(tables, "treasure_artifacts", "Throne of the Gods")
    famous.append((12, i, r))
    i, r = find_row(tables, "treasure_artifacts",
                    "Orb of the Dragonkind")
    famous.append((12, i, r))
    for cat, i, r in famous:
        out.append(
            "            if (!dm::treasure::magicTablePin(%d, %d, &p)\n"
            "                || p.lo != %d || p.hi != %d\n"
            "                || p.xp != %d || p.xpHi != %d\n"
            "                || p.gp != %d || p.gpHi != %d\n"
            "                || p.qtyLo != %d || p.qtyHi != %d)\n"
            "                ++bad;\n"
            % (cat, i, r[0], r[1], r[3], r[4], r[5], r[6], r[7],
               r[8]))
    # the Shield -1 curse: zero xp, printed gp only (hand record)
    shield = [r for r in tables["treasure_armor"]
              if r[2] == "Shield -1, missile attractor"][0]
    if shield[3] != 0 or shield[4] != 0 or shield[5] != 750:
        die("Shield -1 drifted from the record")
    orb = [r for r in tables["treasure_artifacts"]
           if r[2] == "Orb of the Dragonkind"][0]
    if (orb[5], orb[6]) != (10000, 80000):
        die("Orb of the Dragonkind gp range drifted")
    throne = [r for r in tables["treasure_artifacts"]
              if r[2] == "Throne of the Gods"][0]
    if (throne[3], throne[4], throne[5], throne[6]) != (0, 0, 0, 0):
        die("Throne of the Gods drifted")
    arrow = [r for r in tables["treasure_weapons"]
             if r[2] == "Arrow +2"][0]
    if arrow[7] != 2 or arrow[8] != 16:
        die("Arrow +2 bundle drifted")
    out.append(
        "            if (p.name != std::string(\"Orb of the Dragonkind\"))\n"
        "                ++bad;\n")
    out.append("        }\n")
    out.append(
        "        printf(\"R1041 treasure item registry data audit: "
        "bad %d\\n\", bad);\n"
        "        if (bad) return 1;\n"
        "        bad = 0;\n")

    # -- 5. rows: the full engine-registry cross-read -----------------------
    out.append("        // -- 5. rows (full cross-read) -------------------\n")
    for key, _arr, _hdr, _want, cat in TABLES:
        out.append(
            "        {\n"
            "            const auto& rows = %s;\n"
            "            dm::treasure::TablePin p;\n"
            "            for (int i = 0; i < (int)rows.size(); ++i) {\n"
            "                if (!dm::treasure::magicTablePin(%d, i, &p)\n"
            "                    || p.lo != rows[i].bandLo\n"
            "                    || p.hi != rows[i].bandHi\n"
            "                    || p.name != rows[i].name\n"
            "                    || p.xp != rows[i].xp\n"
            "                    || p.xpHi != rows[i].xpHi\n"
            "                    || p.gp != rows[i].gp\n"
            "                    || p.gpHi != rows[i].gpHi\n"
            "                    || p.qtyLo != rows[i].qtyLo\n"
            "                    || p.qtyHi != rows[i].qtyHi) { ++bad; "
            "break; }\n"
            "            }\n"
            "        }\n" % (view(key), cat))
    out.append(
        "        printf(\"R1041 treasure item registry rows audit: "
        "bad %d\\n\", bad);\n"
        "        if (bad) return 1;\n"
        "        bad = 0;\n")

    # -- 6. edges: refusal semantics + the scroll structure -----------------
    out.append("        // -- 6. edges (refusals + scrolls) ---------------\n")
    out.append(
        "        {\n"
        "            dm::treasure::TablePin p;\n"
        "            if (dm::treasure::magicTablePinCount(1) != 25) ++bad;\n"
        "            if (dm::treasure::magicTablePin(1, 0, &p)) ++bad;\n"
        "            if (dm::treasure::magicTablePin(0, 35, &p)) ++bad;\n"
        "            if (dm::treasure::magicTablePin(0, -1, &p)) ++bad;\n"
        "            if (dm::treasure::magicTablePin(13, 0, &p)) ++bad;\n"
        "            if (dm::treasure::magicTablePin(-1, 0, &p)) ++bad;\n"
        "            if (dm::treasure::magicTablePin(12, 29, &p)) ++bad;\n"
        "            if (!dm::treasure::magicTablePin(12, 28, &p)) ++bad;\n"
        "            if (dm::treasure::magicTablePinCount(13) != 0) ++bad;\n"
        "            if (dm::treasure::magicTablePinCount(-1) != 0) ++bad;\n"
        "            if (dm::treasure::magicTablePin(0, 0, nullptr)) ++bad;\n"
        "        }\n")
    out.append(
        "        printf(\"R1041 treasure item registry edges audit: "
        "bad %d\\n\", bad);\n"
        "        if (bad) return 1;\n"
        "    }\n")
    text = "".join(out)
    n = text.count("audit: bad %d")
    if n != 6:
        die("fragment carries %d audit printfs (expected 6)" % n)
    return text


# ---------------------------------------------------------------------------
def census():
    total = 0
    for dirpath, _dirs, files in os.walk(
            os.path.join(ROOT, "rules", "audits")):
        for fn in files:
            if fn.endswith(".h"):
                with open(os.path.join(dirpath, fn)) as f:
                    total += f.read().count("audit: bad %d")
    with open(os.path.join(ROOT, "regtest.cpp")) as f:
        total += f.read().count("audit: bad %d")
    return total


# ---------------------------------------------------------------------------
def main():
    tpath = os.path.join(ROOT, "dm", "treasure.cpp")
    with open(tpath) as f:
        src = f.read()

    if "R1041 (the registry-native de-wire" in src:
        print("applied 0, already 1")
        print("SPLICE OK")
        return

    tables = parse_tables(src)
    print("parsed: " + ", ".join(
        "%s %d" % (k[len("treasure_"):], len(v))
        for k, v in tables.items()))

    # famous-row record checks (the r122 hand record)
    check = lambda key, name, want: (
        die("%s drifted from the record" % name)
        if [r[3:9] for r in tables[key] if r[2] == name][0] != want
        else None)
    check("treasure_potions", "Potion of Animal Control",
          (250, 0, 400, 0, 0, 0))
    check("treasure_potions", "Potion of Delusion", (0, 0, 150, 0, 0, 0))
    check("treasure_potions", "Potion of Poison", (0, 0, 0, 0, 0, 0))
    check("treasure_potions", "Potion of Water Breathing",
          (400, 0, 900, 0, 0, 0))

    # emit the lua files
    os.makedirs(os.path.join(ROOT, "content", "tables", "treasure"),
                exist_ok=True)
    for key, rows in tables.items():
        text = lua_file(key, rows)
        path = os.path.join(ROOT, "content", "tables", "treasure",
                            key + ".lua")
        with open(path, "w") as f:
            f.write(text)
        # round-trip: the file must parse back to the same rows
        with open(path) as f:
            back = f.read()
        got = re.findall(
            r'\{ name = "([^"]+)", set = "([^"]+)", '
            r'band = \{ (\d+), (\d+) \}, '
            r'xp = (-?\d+), xp_hi = (-?\d+), '
            r'gp = (-?\d+), gp_hi = (-?\d+), '
            r'qty = \{ (-?\d+), (-?\d+) \} \},',
            back)
        want = [(r[2], key, r[0], r[1], r[3], r[4], r[5], r[6], r[7],
                 r[8]) for r in rows]
        norm = [(a, b, int(c), int(d), int(e), int(f), int(g), int(h),
                 int(i), int(j))
                for a, b, c, d, e, f, g, h, i, j in got]
        if norm != want:
            die("%s round-trip mismatch" % key)
    print("round-trip: 7 lua files parse back byte-exact")

    # rewrite dm/treasure.cpp
    src = rewrite_treasure(src, tables)

    # retirement scan
    for tok in ("struct ItemRow", "makeItem", "pickRow",
                "pinTableFor", "kPotions", "kRings", "kRods",
                "kArtifacts", "kArmor", "kSwords", "kWeapons"):
        if tok in src:
            die("retired token survived: %r" % tok)
    # kept surface
    for keep in ("kSpellScrolls", "COUNT_OF(kSpellScrolls) + 9",
                 "rollScroll", "adjustSpecial", "miscView",
                 "pickMiscRow", "rollFromCategory", "gemName",
                 "rollGemValue", "kLetters"):
        if keep not in src:
            die("kept surface missing: %r" % keep)
    # brace balance
    if src.count("{") != src.count("}"):
        die("brace balance: %d vs %d"
            % (src.count("{"), src.count("}")))
    with open(tpath, "w") as f:
        f.write(src)

    # the fragment
    frag = build_fragment(tables)
    fpath = os.path.join(ROOT, "rules", "audits",
                         "r1041_treasure_item_registry.h")
    with open(fpath, "w") as f:
        f.write(frag)

    # regtest include
    rpath = os.path.join(ROOT, "regtest.cpp")
    with open(rpath) as f:
        reg = f.read()
    reg = replace_once(
        reg,
        '    #include "rules/audits/r1040_appendixp_registry.h"  // R1040\n',
        '    #include "rules/audits/r1040_appendixp_registry.h"  // R1040\n'
        '    #include "rules/audits/r1041_treasure_item_registry.h"'
        '  // R1041\n',
        "regtest include")
    with open(rpath, "w") as f:
        f.write(reg)

    n = census()
    if n != CENSUS_AFTER:
        die("census %d (expected %d)" % (n, CENSUS_AFTER))
    print("census: %d -> %d audit printf patterns"
          % (CENSUS_BEFORE, n))
    print("applied 1, rewrote 2 tracked files, wrote 8 new files")
    print("SPLICE OK")


main()
