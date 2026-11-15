#!/usr/bin/env python3
# r1054_splice.py - the R1054 splice tool: the DMG
# sage subsection de-wire of rules/dmg/sage.h.
#
# WHAT IT DOES (run from the repo root, idempotent):
#   - parses the 32 retiring static arrays (24 dim-N
#     int arrays, the five [4][3] grids, and the
#     three string-name arrays) plus a semantic
#     MODEL of the kept logic fns (sageKnowNone,
#     sageTimeNone, the 27 zero-arg scalars, every
#     clamp line)
#   - writes content/tables/dm_sage/ as 6 defs, 29
#     named tables: dm_sage_fields (7 field-name
#     rows + 5 dim-7 tables + 4 dim-6 band tables),
#     dm_sage_categories (68 category-name rows +
#     category_field), dm_sage_characteristics (9
#     align-name rows + 2 dim-9 + 3 dim-6 tables),
#     dm_sage_knowing (4 scope rows COMPUTED from
#     the parsed clamp bounds + know_lo/know_hi,
#     the grids FLATTENED scope-major to 12 cells),
#     dm_sage_discovery (the same 4 scope rows +
#     time_lo/time_hi/time_unit 12-cell +
#     cost_per_day/free_spread_percent dim 4) and
#     dm_sage_terms (3 offer rows COMPUTED from
#     the parsed offer bounds + offer/efficiency/
#     improvement tables)
#   - rewrites the 32 array accessors onto a
#     namespace-rules seam: szReg() / szTable(key,
#     tag) / szRows(key); the three name accessors
#     become rows readers (the R1051 dzRows idiom,
#     0-based); every signature, clamp and branch
#     stays; the grid accessors keep BOTH clamps
#     then read the flattened cell [scope*3+nature]
#   - writes rules/audits/r1054_sage_registry.h at
#     the R1041+ in-function seat (SEVEN printf
#     sections, six guards, census 1082 -> 1089) and
#     seats its include at regtest.cpp:1303
#
# HARD LESSONS APPLIED (the R1049-R1053 ledgers):
# every want is computed from the SAME parse that
# writes the lua; probe POLARITIES derive from the
# parsed models, never recalled constants;
# NEGATIVE cells handled end to end (the four print
# dashes and the improve_max -1); wrap-agnostic
# regex self-scan checks; the hand-shaped literal
# probe lines keep rules:: and the fn token on ONE
# line; the tool SELF-SCANS its own emitted
# fragment, seam and lua before writing anything.

import os
import re
import sys

ROOT = os.getcwd()
HEAD = "rules/dmg/sage.h"
LUA_DIR = "content/tables/dm_sage"
FRAG = "rules/audits/r1054_sage_registry.h"
REGTEST = "regtest.cpp"
APPLIED_MARK = "// R1054 applied"
INC_LINE = ('    #include "rules/audits/'
            'r1054_sage_registry.h"  // R1054')
CENSUS_BEFORE = 1082
CENSUS_AFTER = 1089
INC_ANCHOR = ('    #include "rules/audits/'
              'r1053_insanity_registry.h"  // R1053')

# the 24 dim-N int accessors:
# (def key, tag, fn, arg var, clamp hi)
FLAT_TAGS = [
    ("dm_sage_fields", "field_lo",
     "sageFieldLo", "f", 6),
    ("dm_sage_fields", "field_hi",
     "sageFieldHi", "f", 6),
    ("dm_sage_fields", "field_category_count",
     "sageFieldCategoryCount", "f", 6),
    ("dm_sage_fields", "field_category_first",
     "sageFieldCategoryFirst", "f", 6),
    ("dm_sage_fields", "spell_kind",
     "sageSpellKind", "f", 6),
    ("dm_sage_fields", "band_lo",
     "sageFieldsBandLo", "b", 5),
    ("dm_sage_fields", "band_hi",
     "sageFieldsBandHi", "b", 5),
    ("dm_sage_fields", "band_minor",
     "sageFieldsBandMinor", "b", 5),
    ("dm_sage_fields", "band_special",
     "sageFieldsBandSpecial", "b", 5),
    ("dm_sage_categories", "category_field",
     "sageCategoryField", "i", 67),
    ("dm_sage_characteristics", "align_lo",
     "sageAlignLo", "b", 8),
    ("dm_sage_characteristics", "align_hi",
     "sageAlignHi", "b", 8),
    ("dm_sage_characteristics", "ability_dice",
     "sageAbilityDice", "a", 5),
    ("dm_sage_characteristics",
     "ability_dice_count",
     "sageAbilityDiceCount", "a", 5),
    ("dm_sage_characteristics", "ability_plus",
     "sageAbilityPlus", "a", 5),
    ("dm_sage_discovery", "cost_per_day",
     "sageCostPerDay", "scope", 3),
    ("dm_sage_discovery",
     "free_spread_percent",
     "sageFreeSpreadPercent", "scope", 3),
    ("dm_sage_terms", "offer_lo",
     "sageOfferLo", "i", 2),
    ("dm_sage_terms", "offer_hi",
     "sageOfferHi", "i", 2),
    ("dm_sage_terms", "eff_milestone_cost",
     "sageEffMilestoneCost", "i", 2),
    ("dm_sage_terms", "eff_milestone_percent",
     "sageEffMilestonePercent", "i", 2),
    ("dm_sage_terms", "improve_cost",
     "sageImproveCost", "i", 3),
    ("dm_sage_terms", "improve_months",
     "sageImproveMonths", "i", 3),
    ("dm_sage_terms", "improve_max",
     "sageImproveMax", "i", 3),
]

# the five [4][3] grid accessors:
# (def key, tag, fn)
GRID_TAGS = [
    ("dm_sage_knowing", "know_lo",
     "sageKnowLo"),
    ("dm_sage_knowing", "know_hi",
     "sageKnowHi"),
    ("dm_sage_discovery", "time_lo",
     "sageTimeLo"),
    ("dm_sage_discovery", "time_hi",
     "sageTimeHi"),
    ("dm_sage_discovery", "time_unit",
     "sageTimeUnit"),
]

# the three string-name arrays (rows readers):
# (def key, fn, arg var, clamp hi)
NAME_TAGS = [
    ("dm_sage_fields", "sageFieldName",
     "f", 6),
    ("dm_sage_categories", "sageCategoryName",
     "i", 67),
    ("dm_sage_characteristics", "sageAlignName",
     "b", 8),
]

GRID_HI_SCOPE = 3
GRID_HI_NATURE = 2

DEF_KEYS = ["dm_sage_fields",
            "dm_sage_categories",
            "dm_sage_characteristics",
            "dm_sage_knowing",
            "dm_sage_discovery",
            "dm_sage_terms"]

LABELS = [
    "R1054 sage registry load",
    "R1054 sage registry counts",
    "R1054 sage fields and categories",
    "R1054 sage characteristics",
    "R1054 sage grids and terms",
    "R1054 sage registry seam",
    "R1054 sage registry edges",
]


def die(msg):
    sys.stderr.write(
        "r1054_splice: FATAL: %s\n" % msg)
    sys.exit(1)


# ---- census --------------------------------

def census_count():
    n = open(os.path.join(
        ROOT, REGTEST)).read().count(
        "audit: bad %d")
    for d, _, fs in os.walk(
            os.path.join(
                ROOT, "rules/audits")):
        for f in fs:
            if f.endswith(".h"):
                n += open(os.path.join(
                    d, f)).read().count(
                    "audit: bad %d")
    return n


# ---- the parse -----------------------------
# An independent read of every retiring array
# plus a semantic MODEL of every kept logic fn
# (the frag probes derive from the models, never
# from recalled constants).

def fn_body(src, fn):
    m = re.search(
        r"inline [\w\* ]+?" + fn +
        r"\([\s\S]*?\n\}", src)
    if not m:
        die("body of " + fn + " not found")
    return m.group(0)


def flat(body):
    return re.sub(r"\s+", " ", body)


def parse_clamps(body, var, hi):
    fb = flat(body)
    want = ("if (%s < 0) %s = 0; "
            "if (%s > %d) %s = %d;"
            % (var, var, var, hi, var, hi))
    if want not in fb:
        die("clamps for " + var
            + " not found (want "
            + repr(want[:40]) + ")")
    return hi


def parse_flat_fn(src, key, tag, fn, var, hi):
    body = fn_body(src, fn)
    got = re.findall(
        r"static const int "
        r"(\w+)\[(\d+)\] = "
        r"\{([^}]*)\};", body)
    if len(got) != 1:
        die(fn + ": want one array")
    nm, dm, lit = got[0]
    if int(dm) != hi + 1:
        die(fn + ": dim " + dm
            + ", want " + str(hi + 1))
    vals = [int(v) for v in
            re.findall(r"-?\d+", lit)]
    if len(vals) != hi + 1:
        die(fn + ": " + str(len(vals))
            + " cells parsed")
    parse_clamps(body, var, hi)
    return vals


def parse_grid_fn(src, key, tag, fn):
    body = fn_body(src, fn)
    m = re.search(
        r"static const int (\w+)"
        r"\[4\]\[3\] = "
        r"\{([\s\S]*?)\};", body)
    if not m:
        die(fn + ": the [4][3] grid "
            "init not found")
    vals = [int(v) for v in
            re.findall(r"-?\d+", m.group(2))]
    if len(vals) != 12:
        die(fn + ": " + str(len(vals))
            + " cells parsed, want 12")
    fb = flat(body)
    if ("if (scope < 0) scope = 0; "
            "if (scope > 3) scope = 3;"
            not in fb) or (
            "if (nature < 0) nature = 0; "
            "if (nature > 2) nature = 2;"
            not in fb):
        die(fn + ": the scope/nature "
            "clamps not found")
    # flatten scope-major (the C row order)
    return [vals[s * 3 + n]
            for s in range(4) for n in range(3)]


def parse_name_fn(src, key, fn, var, hi):
    body = fn_body(src, fn)
    m = re.search(
        r"(\w+)\[(\d+)\] = "
        r"\{([\s\S]*?)\};", body)
    if not m:
        die(fn + ": the name array init "
            "not found")
    if int(m.group(2)) != hi + 1:
        die(fn + ": name dim "
            + m.group(2))
    names = re.findall(
        r'"([^"]*)"', m.group(3))
    if len(names) != hi + 1:
        die(fn + ": " + str(len(names))
            + " names parsed")
    if any(not n for n in names):
        die(fn + ": an empty name")
    parse_clamps(body, var, hi)
    return names


def parse_pristine(src):
    p = {}
    p["n_static"] = len(
        re.findall(r"static const ", src))
    if p["n_static"] != 32:
        die("pristine has %d static "
            "consts, want 32 (24 dim-N "
            "int arrays + 5 grids + 3 "
            "name arrays)"
            % p["n_static"])
    p["arrs"] = {}
    for (key, tag, fn, var, hi) \
            in FLAT_TAGS:
        p["arrs"][tag] = parse_flat_fn(
            src, key, tag, fn, var, hi)
    p["grids"] = {}
    for (key, tag, fn) in GRID_TAGS:
        p["grids"][tag] = parse_grid_fn(
            src, key, tag, fn)
    p["names"] = {}
    for (key, fn, var, hi) in NAME_TAGS:
        p["names"][fn] = parse_name_fn(
            src, key, fn, var, hi)
    # the derived none flags (kept
    # fns; the edge probes derive a
    # dash cell and a plain cell)
    for fn in ("sageKnowNone",
               "sageTimeNone"):
        body = flat(fn_body(src, fn))
        lo = {"sageKnowNone":
              "sageKnowLo",
              "sageTimeNone":
              "sageTimeLo"}[fn]
        if ("return %s(scope, nature)"
            " < 0;" % lo) not in body:
            die(fn + " is not the "
                "derived dash flag")
    # the zero-arg scalar fns
    p["scalars"] = re.findall(
        r"inline int (\w+)\(\)"
        r"\s*\{\s*return (-?\d+);"
        r"\s*\}", src)
    if len(p["scalars"]) < 25:
        die("only %d scalar fns "
            "parsed" % len(p["scalars"]))
    # the computed row names: the
    # scope rows derive from the
    # parsed grid clamp bounds; the
    # offer rows from the parsed
    # offer bounds
    p["scope_rows"] = [
        "scope_%d" % s
        for s in range(
            GRID_HI_SCOPE + 1)]
    p["offer_rows"] = [
        "offer_%d_%d"
        % (p["arrs"]["offer_lo"][i],
           p["arrs"]["offer_hi"][i])
        for i in range(3)]
    return p


def row_names(p, key):
    if key == "dm_sage_fields":
        return p["names"]["sageFieldName"]
    if key == "dm_sage_categories":
        return p["names"]["sageCategoryName"]
    if key == "dm_sage_characteristics":
        return p["names"]["sageAlignName"]
    if key in ("dm_sage_knowing",
               "dm_sage_discovery"):
        return p["scope_rows"]
    if key == "dm_sage_terms":
        return p["offer_rows"]
    die("row names for " + key)


def def_tags(key):
    out = [t for (k, t, _, _, _)
           in FLAT_TAGS if k == key]
    out += [t for (k, t, _)
            in GRID_TAGS if k == key]
    return out


def table_vals(p, tag):
    if tag in p["arrs"]:
        return p["arrs"][tag]
    if tag in p["grids"]:
        return p["grids"][tag]
    die("no table " + tag)


# ---- the emitter ---------------------------

def wrap(text, ind=""):
    body = text.lstrip(" ")
    lead = ind + (" " * (len(text) - len(body)))
    if len(lead + body) <= 78:
        return [lead + body]
    if '"' in body:
        die("emit: line with a "
            + "string literal does "
            + "not fit 78: "
            + body[:40])
    words = body.split(" ")
    out = [lead + words[0]]
    for w in words[1:]:
        if len(out[-1]) + 1 + len(w) <= 78:
            out[-1] += " " + w
        else:
            out.append(lead + "    " + w)
    return out


class Emit:
    def __init__(self):
        self.lines = []

    def __call__(self, text, ind=""):
        self.lines.extend(wrap(text, ind))

    def raw(self, lines):
        for ln in lines:
            if len(ln.rstrip()) > 78:
                die("emit: raw line "
                    "over 78: " + ln[:50])
        self.lines.extend(lines)


def camel(tag):
    return "".join(
        part.capitalize()
        for part in tag.split("_"))


# ---- lua emit -------------------------------

LUA_TITLE = {
    "dm_sage_fields":
        "DMG sage fields of study "
        "(the seven fields)",
    "dm_sage_categories":
        "DMG sage special knowledge "
        "categories (the 68)",
    "dm_sage_characteristics":
        "DMG sage characteristics "
        "(abilities and alignment)",
    "dm_sage_knowing":
        "DMG sage chance of knowing "
        "an answer (scope x nature)",
    "dm_sage_discovery":
        "DMG sage information "
        "discovery time and cost",
    "dm_sage_terms":
        "DMG sage support, salary, "
        "efficiency and improvement",
}

LUA_ROWS_CMT = {
    "dm_sage_fields":
        "the printed fields of "
        "study in order",
    "dm_sage_categories":
        "the printed special "
        "knowledge categories in "
        "print order, field by "
        "field",
    "dm_sage_characteristics":
        "the printed alignment "
        "bands in ascending dice "
        "order",
    "dm_sage_knowing":
        "the four question scopes "
        "(0 out of fields, 1 minor "
        "field, 2 major field, 3 "
        "special category), names "
        "COMPUTED from the parsed "
        "clamp bounds",
    "dm_sage_discovery":
        "the four question scopes "
        "as in dm_sage_knowing "
        "(names COMPUTED from the "
        "parsed clamp bounds)",
    "dm_sage_terms":
        "the employment offer rows "
        "(names COMPUTED from the "
        "parsed offer bounds)",
}

LUA_TABLES_CMT = {
    "dm_sage_knowing":
        "the [4][3] grids FLATTENED "
        "scope-major; the accessor "
        "reads values[scope * 3 + "
        "nature], and cell (0,2) "
        "pins the print dash -1",
    "dm_sage_discovery":
        "the time grids FLATTENED "
        "scope-major (cell (0,2) "
        "pins the print dash -1 in "
        "time_lo/time_hi)",
    "dm_sage_terms":
        "improve_max row 3 pins -1 "
        "(no stated maximum)",
}

LUA_CMT = {
    "field_lo": "the field percent "
    "band low",
    "field_hi": "the field percent "
    "band high",
    "field_category_count":
        "the special knowledge "
        "categories in the field",
    "field_category_first":
        "the flat index of the "
        "first category in the "
        "field",
    "spell_kind": "the field spell "
    "kind (0 clerical, 1 druidical, "
    "2 magic-user or illusionist)",
    "band_lo": "the fields-count "
    "dice band low",
    "band_hi": "the fields-count "
    "dice band high",
    "band_minor": "the minor fields "
    "in the band",
    "band_special": "the special "
    "categories in the major field",
    "category_field": "the owning "
    "field of the category",
    "align_lo": "the alignment band "
    "low",
    "align_hi": "the alignment band "
    "high",
    "ability_dice": "the ability "
    "die (0 STR..5 CHA)",
    "ability_dice_count": "the "
    "ability dice count (0 STR..5 "
    "CHA)",
    "ability_plus": "the ability "
    "plus (0 STR..5 CHA)",
    "know_lo": "the knowing percent "
    "band low (scope-major flat)",
    "know_hi": "the knowing percent "
    "band high (scope-major flat)",
    "time_lo": "the discovery time "
    "band low (scope-major flat)",
    "time_hi": "the discovery time "
    "band high (scope-major flat)",
    "time_unit": "the discovery "
    "time unit (scope-major flat)",
    "cost_per_day": "the g.p. cost "
    "per day for the scope",
    "free_spread_percent": "the "
    "free-cost spread threshold "
    "for the scope",
    "offer_lo": "the offer row low "
    "(g.p. per month)",
    "offer_hi": "the offer row high "
    "(g.p. per month)",
    "eff_milestone_cost": "the "
    "efficiency milestone cost "
    "(g.p.)",
    "eff_milestone_percent": "the "
    "efficiency milestone percent",
    "improve_cost": "the "
    "improvement cost (g.p.)",
    "improve_months": "the "
    "improvement time (months)",
    "improve_max": "the improvement "
    "maximum (-1 no stated "
    "maximum)",
}


def lua_def(p, key):
    out = []
    w = out.append
    names = row_names(p, key)
    tags = def_tags(key)
    n = len(names)
    w("-- " + key)
    w("-- The R1054 sage de-wire "
      "(the DMG sage subsection).")
    w("-- " + LUA_TITLE[key] + ".")
    w("-- rows[]: " + LUA_ROWS_CMT[key]
      + " - the R1042 equipment rows "
      "idiom.")
    if key in LUA_TABLES_CMT:
        w("-- tables[]: "
          + LUA_TABLES_CMT[key] + ".")
    else:
        w("-- tables[]: the printed "
          "columns; the accessors "
          "live in rules/dmg/sage.h "
          "and keep their clamps.")
    w("-- DO NOT hand-edit: "
      "tools/r1054_splice.py is the "
      "only writer.")
    w("")
    w("return {")
    w("  key = \"%s\"," % key)
    w("  name = \"%s\"," % LUA_TITLE[key])
    w("  sources = {")
    w("    { part = 0, round = 1054 },")
    w("  },")
    w("  pins = {")
    w("    { name = \"%sRowCount\","
      % key)
    w("      value = %d," % n)
    w("      comment = \"the table "
      "rows\" },")
    w("  },")
    w("  rows = {")
    for i, nm in enumerate(names):
        w("    { name = \"%s\"," % nm)
        w("      set = \"%s\"," % key)
        w("      band = { %d, %d },"
          % (i, i))
        w("      xp = 0, xp_hi = 0, "
          "gp = 0, gp_hi = 0,")
        w("      qty = { 0, 0 } },")
    w("  },")
    w("  tables = {")
    for tag in tags:
        vals = table_vals(p, tag)
        w("    { name = \"%s\"," % tag)
        w("      values = {")
        for r in range(0, len(vals), 10):
            w("        "
              + ", ".join(str(v)
                          for v in
                          vals[r:r + 10])
              + ", ")
        w("      },")
        w("      comment = \"%s\" },"
          % LUA_CMT[tag])
    w("  },")
    w("}")
    w("")
    return "\n".join(out)


def build_lua(p):
    return {key: lua_def(p, key)
            for key in DEF_KEYS}


# ---- seam emit ------------------------------

SEAM_TXT = """\
// ---- the R1054 registry seam ---------------
// content/tables/dm_sage/ via
// items::MiscItemRegistry: the
// R1042 rows idiom plus named
// tables per def (the R1051 dzTable
// idiom) and the rows readers (the
// R1051 dzRows idiom - the three
// name accessors are rows readers
// now). Header-only singleton (the
// R1040 appendixp.h idiom). Every
// accessor below keeps its
// signature, clamp and branch; only
// the array read moves behind the
// registry. The five [4][3] grids
// retire FLATTENED scope-major;
// the grid accessors keep BOTH
// clamps then read the cell
// [scope * 3 + nature].

inline items::MiscItemRegistry&
szReg() {
    static items::MiscItemRegistry
        reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory(
            "content/tables/"
            "dm_sage");
    }
    return reg;
}

// the name rows of one def (the
// band is the index; the name
// accessors index them 0-based)
inline const std::vector<
    items::MiscItemRow>& szRows(
        const char* key) {
    static std::map<std::string,
        std::vector<
            items::MiscItemRow>>
        cache;
    auto it = cache.find(key);
    if (it == cache.end()) {
        const items::MiscItemDef*
            d = szReg().find(key);
        it = cache.emplace(
            key, d ? d->rows
                   : std::vector<
                        items::
                        MiscItemRow>()
                   ).first;
    }
    return it->second;
}

// one named int table of one def
// (null when absent or empty)
inline const std::vector<long
    long>* szTable(const char* key,
                  const char* tag) {
    static std::map<std::string,
        std::vector<long long>>
        cache;
    const std::string kk =
        std::string(key) + "/"
        + tag;
    auto it = cache.find(kk);
    if (it == cache.end()) {
        const items::MiscItemDef*
            d = szReg().find(key);
        const std::vector<long
            long>* v = nullptr;
        if (d) {
            for (const auto& t :
                 d->tables) {
                if (t.name == tag) {
                    v = &t.values;
                    break;
                }
            }
        }
        it = cache.emplace(
            kk, v ? *v
                  : std::vector<
                        long long>()
                   ).first;
    }
    return it->second.empty()
        ? nullptr
        : &it->second;
}
"""


def new_flat_body(p, key, tag, fn, var, hi):
    e = Emit()
    e("inline int %s(int %s) {"
      % (fn, var))
    e.raw([
        "    const auto* g = szTable(",
        "        \"%s\", \"%s\");"
        % (key, tag)])
    e("    if (%s < 0) %s = 0;"
      % (var, var))
    e("    if (%s > %d) %s = %d;"
      % (var, hi, var, hi))
    e("    if (!g) return %d;"
      % p["arrs"][tag][0])
    e("    return (int)(*g)[%s];" % var)
    e("}")
    return "\n".join(e.lines)


def new_grid_body(p, key, tag, fn):
    e = Emit()
    e("inline int %s(int scope, "
      "int nature) {" % fn)
    e.raw([
        "    const auto* g = szTable(",
        "        \"%s\", \"%s\");"
        % (key, tag)])
    e("    if (scope < 0) scope = 0;")
    e("    if (scope > 3) scope = 3;")
    e("    if (nature < 0) nature = 0;")
    e("    if (nature > 2) nature = 2;")
    e("    if (!g) return %d;"
      % p["grids"][tag][0])
    e("    return (int)(*g)"
      "[scope * 3 + nature];")
    e("}")
    return "\n".join(e.lines)


def new_name_body(p, key, fn, var, hi):
    e = Emit()
    e("inline const char* %s(int %s) {"
      % (fn, var))
    e("    const auto& rows = ")
    e.raw(["        szRows(\"%s\");"
           % key])
    e("    if (rows.empty())")
    e("        return \"\";")
    e("    if (%s < 0) %s = 0;"
      % (var, var))
    e("    if (%s > %d) %s = %d;"
      % (var, hi, var, hi))
    e("    if ((int)rows.size() <= %s)"
      % var)
    e("        return \"\";")
    e("    return rows[%s]"
      ".name.c_str();" % var)
    e("}")
    return "\n".join(e.lines)


def build_seam(src, p):
    s = src
    if APPLIED_MARK in s:
        die("applied mark already present")
    anchor = "namespace rules {\n"
    if anchor not in s:
        die("namespace rules anchor not found")
    inc = (APPLIED_MARK + "\n"
           + "#include \"items/"
           "MiscItemRegistry.h\"\n"
           + "\n")
    s = s.replace(
        anchor, inc + anchor + "\n" + SEAM_TXT, 1)
    rewrites = [(fn, new_flat_body(
                    p, key, tag, fn, var, hi))
                for (key, tag, fn, var, hi)
                in FLAT_TAGS]
    rewrites += [(fn, new_grid_body(
                     p, key, tag, fn))
                 for (key, tag, fn)
                 in GRID_TAGS]
    rewrites += [(fn, new_name_body(
                     p, key, fn, var, hi))
                 for (key, fn, var, hi)
                 in NAME_TAGS]
    for fn, body in rewrites:
        m = re.search(
            r"inline [\w\* ]*?" + fn +
            r"\([^)]*\)[\s\S]*?\n\}", s)
        if not m:
            die("body of " + fn
                + " not found for the rewrite")
        s = s.replace(m.group(0), body, 1)
    if re.search(r"static const ", s):
        die("a static array survived the rewrite")
    # the kept logic fns must still be present
    kept = ["sageKnowNone", "sageTimeNone"]
    kept += [fn for fn, _ in p["scalars"]]
    kept += ["sageFieldCount", "sageHpDiceCount"]
    for fn in kept:
        if fn not in s or "inline" not in s:
            die("kept fn " + fn + " lost")
    return s


# ---- fragment emit --------------------------

def want_arr(P, name, vals, ind=""):
    P("%sconst int %s[] = {" % (ind, name))
    for r in range(0, len(vals), 10):
        P("%s    %s,"
          % (ind, ", ".join(str(v) for v in
                            vals[r:r + 10])))
    P("%s};" % ind)


def row_probe(E, i, nm, ind=""):
    # a string-literal probe hand-shaped
    # so the literal never wraps (wrap()
    # refuses quotes; the R1052 lesson)
    E.raw([
        "%sif (std::string(" % ind,
        "%s    d->rows[%d].name)" % (ind, i),
        "%s    != \"%s\")" % (ind, nm),
        "%s    ++bad;" % ind])


def name_probe(E, fn, arg, nm):
    # the rows-reader output probe; the
    # rules:: token and the fn stay on
    # ONE line so the qualification
    # scan holds (the R1053 lesson)
    E.raw([
        "            if (std::string(",
        "                rules::%s(%d))"
        % (fn, arg),
        "                != \"%s\")" % nm,
        "                ++bad;"])


def build_frag(p):
    E = Emit()
    P = E
    P("    // ==== R1054: sage registry ===========")
    P("    // The R1054 de-wire: the 32 static")
    P("    // arrays of rules/dmg/sage.h ride")
    P("    // items::MiscItemRegistry from")
    P("    // content/tables/dm_sage/ (6 defs,")
    P("    // 29 named tables; the five [4][3]")
    P("    // grids retire FLATTENED scope-")
    P("    // major, the three name accessors")
    P("    // are rows readers). Seven sections:")
    P("    // load, counts, fields+categories,")
    P("    // characteristics, grids+terms,")
    P("    // seam, edges. Census 1082 -> 1089.")
    P("    // DO NOT hand-edit:")
    P("    // tools/r1054_splice.py is the only")
    P("    // writer.")
    P("    {")
    P("        int bad = 0;")
    keys = DEF_KEYS
    # -- 1. load
    P("        // -- 1. load ---------------------------------")
    P("        {")
    P("            items::MiscItemRegistry reg;")
    P("            int n = reg.loadDirectory(")
    P("                \"content/tables/dm_sage\");")
    P("            if (n != 6) ++bad;")
    P("            if (!reg.errors().empty()) ++bad;")
    P("            for (const auto& kv : reg.all())")
    P("                if ((int)kv.second.sources.size() != 1")
    P("                    || kv.second.sources[0].second != 1054)")
    P("                    ++bad;")
    for key in keys:
        P("            if (!reg.find(\"%s\")) ++bad;" % key)
    P("        }")
    P("        printf(\"%s audit: bad %%d\\n\", bad);"
      % LABELS[0])
    P("        if (bad) return 1;")
    P("        bad = 0;")
    # -- 2. counts
    P("        // -- 2. counts --------------------------------")
    P("        {")
    P("            items::MiscItemRegistry reg;")
    P("            reg.loadDirectory(")
    P("                \"content/tables/dm_sage\");")
    for key in keys:
        names = row_names(p, key)
        tags = def_tags(key)
        n = len(names)
        P("            {")
        P("                const items::MiscItemDef* d =")
        P("                    reg.find(\"%s\");" % key)
        P("                if (!d) { ++bad; } else {")
        P("                    if ((int)d->rows.size() != %d" % n)
        P("                        || (int)d->pins.size() != 1")
        E.raw([
            "                        || d->pins[0].name",
            "                            != \"%sRowCount\"" % key,
            "                        || d->pins[0].value != %d" % n,
            "                        || (int)d->tables.size() != %d)"
            % len(tags)])
        P("                        ++bad;")
        for i, tg in enumerate(tags):
            width = len(table_vals(p, tg))
            P("                    if (d->tables[%d].name" % i)
            P("                        != \"%s\"" % tg)
            P("                        || (int)d->tables[%d]" % i)
            P("                            .values.size() != %d)" % width)
            P("                        ++bad;")
        for i in range(n):
            P("                    if (d->rows[%d].set" % i)
            P("                        != \"%s\"" % key)
            P("                        || d->rows[%d].bandLo != %d" % (i, i))
            P("                        || d->rows[%d].bandHi != %d)" % (i, i))
            P("                        ++bad;")
        # the row names: one hand-shaped
        # probe each (the literals never
        # wrap - wrap() refuses quotes)
        for i, nm in enumerate(names):
            row_probe(E, i, nm,
                      ind="    " * 4)
        P("                }")
        P("            }")
    P("        }")
    P("        printf(\"%s audit: bad %%d\\n\", bad);"
      % LABELS[1])
    P("        if (bad) return 1;")
    P("        bad = 0;")
    # -- 3. fields + categories
    P("        // -- 3. fields + categories -------------------")
    P("        {")
    for (key, tag, fn, var, hi) in FLAT_TAGS:
        if key not in ("dm_sage_fields",
                       "dm_sage_categories"):
            continue
        vals = p["arrs"][tag]
        wn = "wantSg%s" % camel(tag)
        want_arr(P, wn, vals, ind="            ")
        P("            for (int %s = 0; %s < %d;"
          % (var, var, hi + 1))
        P("                 ++%s)" % var)
        P("                if (rules::%s(%s)" % (fn, var))
        P("                    != %s[%s])" % (wn, var))
        P("                    ++bad;")
    # the name rows read through the
    # rows-reader accessors (the
    # names DERIVE from the parse)
    for (key, fn, var, hi) in NAME_TAGS:
        if fn == "sageAlignName":
            continue
        for i, nm in enumerate(
                p["names"][fn]):
            name_probe(E, fn, i, nm)
    P("        }")
    P("        printf(\"%s audit: bad %%d\\n\", bad);"
      % LABELS[2])
    P("        if (bad) return 1;")
    P("        bad = 0;")
    # -- 4. characteristics
    P("        // -- 4. characteristics ----------------------")
    P("        {")
    for (key, tag, fn, var, hi) in FLAT_TAGS:
        if key != "dm_sage_characteristics":
            continue
        vals = p["arrs"][tag]
        wn = "wantSg%s" % camel(tag)
        want_arr(P, wn, vals, ind="            ")
        P("            for (int %s = 0; %s < %d;"
          % (var, var, hi + 1))
        P("                 ++%s)" % var)
        P("                if (rules::%s(%s)" % (fn, var))
        P("                    != %s[%s])" % (wn, var))
        P("                    ++bad;")
    for i, nm in enumerate(
            p["names"]["sageAlignName"]):
        name_probe(E, "sageAlignName",
                   i, nm)
    P("        }")
    P("        printf(\"%s audit: bad %%d\\n\", bad);"
      % LABELS[3])
    P("        if (bad) return 1;")
    P("        bad = 0;")
    # -- 5. grids + terms
    P("        // -- 5. grids + terms ------------------------")
    P("        {")
    for (key, tag, fn) in GRID_TAGS:
        vals = p["grids"][tag]
        wn = "wantSg%s" % camel(tag)
        want_arr(P, wn, vals, ind="            ")
        P("            for (int s = 0; s < 4; ++s)")
        P("                for (int n = 0; n < 3; ++n)")
        P("                    if (rules::%s(s, n)" % fn)
        P("                        != %s[" % wn)
        P("                            s * 3 + n])")
        P("                        ++bad;")
    for (key, tag, fn, var, hi) in FLAT_TAGS:
        if key != "dm_sage_terms" \
                and not (key == "dm_sage_discovery"):
            continue
        vals = p["arrs"][tag]
        wn = "wantSg%s" % camel(tag)
        want_arr(P, wn, vals, ind="            ")
        P("            for (int %s = 0; %s < %d;"
          % (var, var, hi + 1))
        P("                 ++%s)" % var)
        P("                if (rules::%s(%s)" % (fn, var))
        P("                    != %s[%s])" % (wn, var))
        P("                    ++bad;")
    P("        }")
    P("        printf(\"%s audit: bad %%d\\n\", bad);"
      % LABELS[4])
    P("        if (bad) return 1;")
    P("        bad = 0;")
    # -- 6. seam: the raw registry
    # cross-read against the accessors
    # (dual-path diff)
    P("        // -- 6. seam ---------------------------------")
    P("        {")
    P("            items::MiscItemRegistry reg;")
    P("            reg.loadDirectory(")
    P("                \"content/tables/dm_sage\");")
    for key in keys:
        P("            {")
        P("                const items::MiscItemDef* d =")
        P("                    reg.find(\"%s\");" % key)
        P("                if (!d) ++bad;")
        for tag in def_tags(key):
            P("                {")
            P("                    int got = 0;")
            P("                    for (const auto& t : d->tables) {")
            P("                        if (t.name != \"%s\")" % tag)
            P("                            continue;")
            P("                        got = 1;")
            if tag in p["grids"]:
                fn = dict(
                    (t, f)
                    for (k, t, f)
                    in GRID_TAGS)[tag]
                P("                        for (int s = 0; s < 4;")
                P("                             ++s)")
                P("                            for (int n = 0;")
                P("                                 n < 3;")
                P("                                 ++n)")
                P("                                if ((int)t")
                P("                                    .values[")
                P("                                    s * 3 + n]")
                P("                                    !=")
                P("                                    rules::%s(" % fn)
                P("                                        s, n))")
                P("                                    ++bad;")
            else:
                entry = [e for e in FLAT_TAGS
                         if e[1] == tag][0]
                _, _, fn, var, hi = entry
                width = hi + 1
                P("                        for (int %s = 0;" % var)
                P("                             %s < %d;" % (var, width))
                P("                             ++%s)" % var)
                P("                            if ((int)t.values[%s]" % var)
                P("                                != rules::%s(%s))" % (fn, var))
                P("                                ++bad;")
            P("                    }")
            P("                    if (!got) ++bad;")
            P("                }")
        # the name rows cross-read
        # against the rows readers -
        # SCOPED to the reader's OWN
        # def block (an unscoped loop
        # reads d->rows out of bounds
        # against a shorter def - the
        # R1054 seam bad 420 kill)
        for (rkey, fn, var, hi) \
                in NAME_TAGS:
            if rkey != key:
                continue
            P("                for (int %s = 0; %s < %d;"
              % (var, var, hi + 1))
            P("                     ++%s)" % var)
            P("                    if (d->rows[%s].name !=" % var)
            P("                        rules::%s(%s))" % (fn, var))
            P("                        ++bad;")
        P("            }")
    P("        }")
    P("        printf(\"%s audit: bad %%d\\n\", bad);"
      % LABELS[5])
    P("        if (bad) return 1;")
    P("        bad = 0;")
    # -- 7. edges: the kept logic fns,
    # every probe DERIVED from the parse
    # (the last section carries NO guard)
    P("        // -- 7. edges --------------------------------")
    P("        {")
    # every flat accessor at its clamp
    # bounds: -1 reads cell 0, hi+1 the
    # last cell (DERIVED)
    for (key, tag, fn, var, hi) in FLAT_TAGS:
        v = p["arrs"][tag]
        for arg, val in ((-1, v[0]),
                         (hi + 1, v[hi])):
            P("            if (rules::%s(%d)"
              % (fn, arg))
            P("                != %d)" % val)
            P("                ++bad;")
    # the grid accessors at their clamp
    # bounds (DERIVED)
    for (key, tag, fn) in GRID_TAGS:
        g = p["grids"][tag]
        for s, n in ((-1, -1), (9, 9)):
            val = g[0] if s < 0 else g[3 * 3 + 2]
            P("            if (rules::%s(%d, %d)" % (fn, s, n))
            P("                != %d)" % val)
            P("                ++bad;")
    # the rows-reader clamps (DERIVED:
    # below 0 reads the first row, above
    # hi the last)
    for (key, fn, var, hi) in NAME_TAGS:
        names = p["names"][fn]
        name_probe(E, fn, -1, names[0])
        name_probe(E, fn, hi + 1, names[hi])
    # the derived dash flags: DERIVED -
    # the (0,2) cell is the parsed -1
    # cell, the (0,0) cell a plain one
    for lo, fl in (("know_lo", "sageKnowNone"),
                   ("time_lo", "sageTimeNone")):
        g = p["grids"][lo]
        P("            if (rules::%s(0, 2)" % fl)
        P("                != %d)" % (1 if g[2] < 0 else 0))
        P("                ++bad;")
        P("            if (rules::%s(0, 0)" % fl)
        P("                != %d)" % (1 if g[0] < 0 else 0))
        P("                ++bad;")
    # the zero-arg scalar fns (ALL of
    # them, DERIVED from the parse)
    for fn, v in p["scalars"]:
        P("            if (rules::%s() != %d)" % (fn, int(v)))
        P("                ++bad;")
    P("        }")
    P("        printf(\"%s audit: bad %%d\\n\", bad);"
      % LABELS[6])
    P("    }")
    return "\n".join(E.lines)


# ---- the self-scan --------------------------
# Nothing is written until the emitted
# fragment, seam and lua pass every
# structural and parity check.

def self_scan(frag, seam, luas, p):
    # fragment shape
    if frag.count("printf(") != 7:
        die("self-scan: printf count")
    if frag.count("audit: bad %d") != 7:
        die("self-scan: census pattern count")
    if frag.count("if (bad) return 1;") != 6:
        die("self-scan: guard count")
    if frag.count("\n        bad = 0;") != 6:
        die("self-scan: bad resets")
    for lbl in LABELS:
        if frag.count(lbl) != 1:
            die("self-scan: label " + lbl)
    if frag.count("(") != frag.count(")"):
        die("self-scan: paren balance")
    if frag.count("{") != frag.count("}"):
        die("self-scan: brace balance")
    # seat shape
    for tok in ("#include", "#pragma",
                "namespace", "inline",
                "std::map", "std::set",
                "std::sort"):
        if tok in frag:
            die("self-scan: %s at the seat" % tok)
    # cols (banner lines exempt)
    for line in frag.splitlines():
        if line.startswith("    // ===="):
            continue
        if len(line.rstrip()) > 78:
            die("self-scan: cols " + repr(line[:50]))
    # fused tokens
    if re.search(r"[A-Za-z0-9_](?:rules|items)::", frag):
        die("self-scan: fused token")
    if re.search(r"\bconst(?=[A-Za-z_])", frag):
        die("self-scan: fused const")
    # rules:: qualification of every
    # fn token
    toks = set(fn for (_, _, fn, _, _)
               in FLAT_TAGS)
    toks.update(fn for (_, _, fn)
                in GRID_TAGS)
    toks.update(fn for (_, fn, _, _)
                in NAME_TAGS)
    toks.update(("sageKnowNone",
                 "sageTimeNone"))
    toks.update(fn for fn, _ in p["scalars"])
    fcode = re.sub(r"//[^\n]*", "", frag)
    for tk in toks:
        for m in re.finditer(
                r"(?<![\w:])" + tk + r"(?![\w:])",
                fcode):
            if not fcode[:m.start()].endswith("rules::"):
                die("self-scan: " + tk + " unqualified")
            break
    for tk in ("MiscItemRegistry",
               "MiscItemDef"):
        for m in re.finditer(
                r"(?<![\w:])" + tk + r"(?![\w:])",
                fcode):
            if not fcode[:m.start()].endswith("items::"):
                die("self-scan: " + tk + " not items::")
    # find targets AS SETS
    if sorted(set(re.findall(
            r'reg\.find\("(\w+)"\)', frag))) \
            != sorted(DEF_KEYS):
        die("self-scan: find targets")
    # want arrays: values parity vs the
    # parse (NEGATIVE cells included)
    for tag in list(p["arrs"]) + list(p["grids"]):
        wn = "wantSg%s" % camel(tag)
        m = re.search(
            r"const int " + wn +
            r"\[\] = \{([-\d\s,]+)\};", frag)
        if not m:
            die("self-scan: want " + wn + " missing")
        got = [int(v) for v in
               re.findall(r"-?\d+", m.group(1))]
        want = table_vals(p, tag)
        if got != want:
            die("self-scan: want " + wn + " parity")
    # row-name probes: every row of every
    # def appears in exactly one literal
    # probe IN THAT DEF'S BLOCK (the
    # knowing and discovery defs share
    # the computed scope row names - the
    # count must be per-def, not global)
    parts = re.split(
        r'(?=reg\.find\("\w+"\))', frag)
    blocks = {}
    for part in parts:
        m = re.search(
            r'reg\.find\("(\w+)"\)', part)
        if m:
            blocks.setdefault(m.group(1), "")
            blocks[m.group(1)] += part
    for key in DEF_KEYS:
        names = row_names(p, key)
        probes = re.findall(
            r'd->rows\[(\d+)\]\.name\)'
            r'\s*!= "([^"]*)"\)',
            blocks.get(key, ""))
        for i, nm in enumerate(names):
            c = sum(1 for a, n in probes
                    if int(a) == i and n == nm)
            if c != 1:
                die("self-scan: row probe "
                    + key + " " + nm)
    # rows-reader output probes: every
    # name read once in range, plus the
    # two clamp probes per reader
    for (key, fn, var, hi) in NAME_TAGS:
        names = p["names"][fn]
        nprobes = re.findall(
            re.escape("rules::" + fn)
            + r"\((-?\d+)\)\)"
            r'\s*!= "([^"]*)"\)', frag)
        for i, nm in enumerate(names):
            c = sum(1 for a, n in nprobes
                    if int(a) == i and n == nm)
            if c != 1:
                die("self-scan: name probe " + nm)
        if sum(1 for a, n in nprobes
               if int(a) == -1
               and n == names[0]) != 1:
            die("self-scan: name clamp lo " + fn)
        if sum(1 for a, n in nprobes
               if int(a) == hi + 1
               and n == names[hi]) != 1:
            die("self-scan: name clamp hi " + fn)
    # scalar probes: every parsed
    # zero-arg fn probed with its value
    for fn, v in p["scalars"]:
        want = "rules::%s() != %d)" % (fn, int(v))
        if frag.count(want) != 1:
            die("self-scan: scalar probe " + fn)
    # polarity re-derivation: wrap-
    # agnostic regexes (the emitted
    # lines may break anywhere - the
    # check must not depend on where
    # wrap() split)
    def probe_rx(rx):
        if re.search(rx, frag) is None:
            die("self-scan: probe missing " + rx[:60])
    # the flat accessor clamp bounds
    for (key, tag, fn, var, hi) in FLAT_TAGS:
        v = p["arrs"][tag]
        probe_rx(r"rules::%s\(\s*-1\)\s*"
                 r"!=\s*%d\)" % (fn, v[0]))
        probe_rx(r"rules::%s\(\s*%d\)\s*"
                 r"!=\s*%d\)"
                 % (fn, hi + 1, v[hi]))
    # the grid clamp bounds
    for (key, tag, fn) in GRID_TAGS:
        g = p["grids"][tag]
        probe_rx(r"rules::%s\(\s*-1,\s*-1\)\s*"
                 r"!=\s*%d\)" % (fn, g[0]))
        probe_rx(r"rules::%s\(\s*9,\s*9\)\s*"
                 r"!=\s*%d\)"
                 % (fn, g[3 * 3 + 2]))
    # the dash-flag polarity (the
    # parsed -1 cell and a plain cell)
    for lo, fl in (("know_lo", "sageKnowNone"),
                   ("time_lo", "sageTimeNone")):
        g = p["grids"][lo]
        probe_rx(r"rules::%s\(0,\s*2\)\s*"
                 r"!=\s*%d\)"
                 % (fl, 1 if g[2] < 0 else 0))
        probe_rx(r"rules::%s\(0,\s*0\)\s*"
                 r"!=\s*%d\)"
                 % (fl, 1 if g[0] < 0 else 0))
    # cross-read scoping: each rows-reader cross-read loop
    # appears EXACTLY ONCE in the whole fragment (unscoped
    # emission puts a copy in every def's block, reading
    # d->rows out of bounds against a shorter def - the
    # R1054 seam bad 420 kill)
    for (rkey, fn, var, hi) in NAME_TAGS:
        n_x = len(re.findall(
            re.escape("rules::%s(%s))"
                      % (fn, var)),
            frag))
        if n_x != 1:
            die("self-scan: cross-read "
                "scoping " + fn
                + " (" + str(n_x) + "x)")
    # seam checks
    if seam.count(APPLIED_MARK) != 1:
        die("self-scan: mark count")
    if ('#include "items/MiscItemRegistry.h"'
            not in seam):
        die("self-scan: registry include")
    if re.search(r"static const ", seam):
        die("self-scan: a static array survived")
    for tok in ("szReg()", "szTable(", "szRows("):
        if tok not in seam:
            die("self-scan: seam fn missing " + tok)
    # the single-owner call sites pin
    # their def key and tag (all 29; no
    # tag ternary this round)
    for (key, tag, fn, var, hi) in FLAT_TAGS:
        if ('"%s", "%s");' % (key, tag)) \
                not in seam:
            die("self-scan: single-owner site " + tag)
    for (key, tag, fn) in GRID_TAGS:
        if ('"%s", "%s");' % (key, tag)) \
                not in seam:
            die("self-scan: grid site " + tag)
    for (key, fn, var, hi) in NAME_TAGS:
        if ('szRows("%s");' % key) not in seam:
            die("self-scan: rows site " + fn)
    # the clamps survived the rewrite
    for (key, tag, fn, var, hi) in FLAT_TAGS:
        for b in (0, hi):
            if ("if (%s > %d) %s = %d;"
                    % (var, hi, var, hi)) \
                    not in seam:
                die("self-scan: clamp lost " + fn)
    for (key, tag, fn) in GRID_TAGS:
        for ln in ("if (scope > 3) scope = 3;",
                   "if (nature > 2) nature = 2;"):
            if ln not in seam:
                die("self-scan: grid clamp lost " + fn)
    if seam.count("if (!g) return") != 29:
        die("self-scan: fallback count %d"
            % seam.count("if (!g) return"))
    if seam.count("[scope * 3 + nature];") != 5:
        die("self-scan: grid index count")
    # lua checks
    for key in DEF_KEYS:
        x = luas[key]
        names = row_names(p, key)
        tags = def_tags(key)
        n = len(names)
        if ('key = "%s"' % key) not in x:
            die("self-scan: lua key " + key)
        if "round = 1054" not in x:
            die("self-scan: lua round " + key)
        if x.count("band = { ") != n:
            die("self-scan: lua row count " + key)
        if ('name = "%sRowCount"' % key) not in x:
            die("self-scan: lua pin " + key)
        for nm in names:
            if ('name = "%s",' % nm) not in x:
                die("self-scan: lua row " + nm)
        for tag in tags:
            if ('name = "%s",' % tag) not in x:
                die("self-scan: lua table " + tag)
            m = re.search(
                r'name = "' + tag +
                r'",\s*values = \{([-\d\s,]+)\}', x)
            if not m:
                die("self-scan: lua values " + tag)
            got = [int(v) for v in
                   re.findall(r"-?\d+", m.group(1))]
            want = table_vals(p, tag)
            if got != want:
                die("self-scan: lua value parity " + tag)


# ---- main -----------------------------------

def main():
    if not os.path.isfile(
            os.path.join(ROOT, REGTEST)) \
            or not os.path.isfile(
            os.path.join(ROOT, HEAD)):
        die("run me from the repo root")
    src = open(os.path.join(ROOT, HEAD)).read()
    if APPLIED_MARK in src:
        print("applied 0, already 1")
        print("SPLICE OK")
        return
    c0 = census_count()
    if c0 != CENSUS_BEFORE:
        die("census %d, want %d"
            % (c0, CENSUS_BEFORE))
    p = parse_pristine(src)
    luas = build_lua(p)
    seam = build_seam(src, p)
    frag = build_frag(p)
    self_scan(frag, seam, luas, p)
    # the regtest seat
    rt = open(os.path.join(ROOT, REGTEST)).read()
    if INC_ANCHOR not in rt:
        die("R1053 include anchor not found in regtest.cpp")
    before = rt.splitlines()
    at = before.index(
        [l for l in before if INC_ANCHOR in l][0])
    if at != 1301:
        die("R1053 include at line %d, want 1302"
            % (at + 1))
    rt = rt.replace(INC_ANCHOR + "\n",
                    INC_ANCHOR + "\n" + INC_LINE + "\n", 1)
    # write everything
    os.makedirs(os.path.join(ROOT, LUA_DIR),
                exist_ok=True)
    for key, txt in luas.items():
        open(os.path.join(ROOT, LUA_DIR, key + ".lua"),
            "w").write(txt)
    open(os.path.join(ROOT, FRAG), "w").write(frag + "\n")
    open(os.path.join(ROOT, HEAD), "w").write(seam)
    open(os.path.join(ROOT, REGTEST), "w").write(rt)
    c1 = census_count()
    if c1 != CENSUS_AFTER:
        die("post census %d, want %d"
            % (c1, CENSUS_AFTER))
    print("census %d -> %d audit printf patterns"
          % (c0, c1))
    print("applied 1, rewrote 2 tracked files, "
          "wrote 7 new files")
    print("SPLICE OK")


if __name__ == "__main__":
    main()
