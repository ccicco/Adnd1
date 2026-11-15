#!/usr/bin/env python3
# r1058_splice.py - the R1058 splice
# tool: the WEAPONS-family de-wire
# of 11 cross-book headers
# (49 retiring arrays, 6 kept
# struct/logic seams: the
# weaponless WeaponlessTier
# trio, kMonkLadder, and the
# kMid/kHigh band edges inside
# fighterGroupAttacks).
#
# WHAT IT DOES (run from the repo
# root, idempotent):
#   - parses the 49 retiring
#     static arrays across the
#     11 headers (1-D clamped
#     flats, the [24][7]/[24][4]/
#     [60][11] AC grids, the
#     [3][8] padded string grid,
#     the 13 string name arrays,
#     the name-keyed struct pair
#     list of weaponSpeedFactor)
#     plus every kept zero-arg
#     scalar and logic fn (a
#     semantic MODEL, the probe
#     source)
#   - writes content/tables/
#     weapondata/ as 17 defs, 36
#     tables, every def's rows =
#     its parsed name list (or
#     COMPUTED band/row names)
#   - seats the NEW cross-book
#     seam rules/seams/
#     weaponsreg.h (wReg/wRows/
#     wTable, the R1056 uaregistry
#     precedent at rules/seams)
#   - rewrites the 49 accessors
#     behind the seam, keeping
#     every signature, clamp and
#     branch
#   - emits the R1058 registry
#     fragment (8 labels, census
#     1111 -> 1119) and seats its
#     include at regtest.cpp:1306
#
# The emitted bodies keep the
# parsed clamps verbatim; string
# literals carry no backslash
# escapes (the R1057 NUL lesson);
# the already-applied path still
# runs apply_kept_fixups (the
# R1057 cascade lesson).

import os
import re
import sys

ROOT = os.getcwd()
REGTEST = "regtest.cpp"
LUA_DIR = "content/tables/weapondata"
FRAG = ("rules/audits/"
        "r1058_weapons_registry.h")
APPLIED_MARK = "// R1058 applied"
CENSUS_BEFORE = 1111
CENSUS_AFTER = 1119
INC_ANCHOR = ('    #include "rules/audits/'
              'r1057_uaspells_registry.h"'
              '  // R1057')
ROUND = 1058

FILES = [
    "rules/ua/uaweapontable.h",
    "rules/ua/uamissile.h",
    "rules/ua/uahandheld.h",
    "rules/ua/uanewweapons.h",
    "rules/ua/weaponspec.h",
    "rules/ua/uaprof.h",
    "rules/dmg/mweapons.h",
    "rules/dmg/weaponspeed.h",
    "rules/dmg/weaponless.h",
    "rules/phb/weaponprof.h",
    "rules/phb/attacksround.h",
]


# the def rows: (def key, rows
# source) - "reader:<fn>" = the
# parsed name array of that reader
# fn; "computed:<prefix>:<lo>:<n>"
# = computed names;
# "structnames:<fn>" = the parsed
# first-string field of the KEPT
# struct seam fn; "cstrs:<fn,fn,..>"
# = the parsed zero-arg string
# fns' literal returns
DEF_ROWS = [
    ("wt", "reader:uawtName"),
    ("uamt", "reader:uamtName"),
    ("uamt_rof",
     "reader:uamtRateOfFire"),
    ("uamt_range_s",
     "reader:uamtRangeShort"),
    ("uamt_range_m",
     "reader:uamtRangeMedium"),
    ("uamt_range_l",
     "reader:uamtRangeLong"),
    ("uahh", "reader:uahhName"),
    ("uahh_length",
     "reader:uahhLength"),
    ("uahh_space",
     "reader:uahhSpaceRequired"),
    ("uanw", "reader:uanwName"),
    ("wspec_cols",
     "reader:"
     "weaponSpecTableColumnName"),
    ("wspec",
     "computed:band_:0:3"),
    ("wspec_cells",
     "reader:"
     "weaponSpecTableCellKnown"),
    ("uapf", "reader:uapfName"),
    ("mw", "computed:row_:0:36"),
    ("wspeed",
     "pairs:weaponSpeedFactor"),
    ("wpf", "computed:row_:0:10"),
]


DEFS = [d for d, _ in DEF_ROWS]

# the retiring int accessors:
# (fn, file stem, def, tag, array
# name in the body, kind, params)
# kinds:
#  band (lo, hi): guards return
#    lo-val / top-cell; read
#    [arg - lo]
#  flat: clamped [i]; fallback
#    cell(0,0)
#  grid2 (w, aoff, boff, amin,
#    amax, bmin, bmax): read
#    [(a-aoff)*w + (b-boff)]
INT_FNS = [
    ("uawtIsNewWeapon",
     "rules/ua/uaweapontable",
     "wt", "is_new", "k",
     "flat", ()),
    ("uawtPhbSeamIndex",
     "rules/ua/uaweapontable",
     "wt", "phb_seam", "k",
     "flat", ()),
    ("uawtWeightMin",
     "rules/ua/uaweapontable",
     "wt", "weight_min", "k",
     "flat", ()),
    ("uawtWeightMax",
     "rules/ua/uaweapontable",
     "wt", "weight_max", "k",
     "flat", ()),
    ("uawtDamageSMMin",
     "rules/ua/uaweapontable",
     "wt", "sm_min", "k",
     "flat", ()),
    ("uawtDamageSMMax",
     "rules/ua/uaweapontable",
     "wt", "sm_max", "k",
     "flat", ()),
    ("uawtDamageLMin",
     "rules/ua/uaweapontable",
     "wt", "l_min", "k",
     "flat", ()),
    ("uawtDamageLMax",
     "rules/ua/uaweapontable",
     "wt", "l_max", "k",
     "flat", ()),
    ("uamtIsNewWeapon",
     "rules/ua/uamissile",
     "uamt", "is_new", "k",
     "flat", ()),
    ("uamtRangePrinted",
     "rules/ua/uamissile",
     "uamt", "range_printed",
     "k", "flat", ()),
    ("uamtAcAdjustment",
     "rules/ua/uamissile",
     "uamt", "ac_adjustment",
     "k", "grid2",
     (7, 0, 0, 0, 23, 0, 6)),
    ("uamtAcAdjustmentHigh",
     "rules/ua/uamissile",
     "uamt",
     "ac_adjustment_high",
     "k", "grid2",
     (4, 0, 0, 0, 23, 0, 3)),
    ("uahhSpeedFactorMin",
     "rules/ua/uahandheld",
     "uahh", "speed_min", "k",
     "flat", ()),
    ("uahhSpeedFactorMax",
     "rules/ua/uahandheld",
     "uahh", "speed_max", "k",
     "flat", ()),
    ("uahhSetDoubleFlag",
     "rules/ua/uahandheld",
     "uahh", "set_double",
     "k", "flat", ()),
    ("uahhDismountFlag",
     "rules/ua/uahandheld",
     "uahh", "dismount", "k",
     "flat", ()),
    ("uahhAcAdjustment",
     "rules/ua/uahandheld",
     "uahh", "ac_adjustment",
     "k", "grid2",
     (11, 0, 0, 0, 59, 0, 10)),
    ("uanwInGapItemList",
     "rules/ua/uanewweapons",
     "uanw", "in_gap", "k",
     "flat", ()),
    ("weaponSpecTableBandLow",
     "rules/ua/weaponspec",
     "wspec", "band_low", "k",
     "flat", ()),
    ("weaponSpecTableBandHigh",
     "rules/ua/weaponspec",
     "wspec", "band_high",
     "k", "flat", ()),
    ("uapfPhbSeamRow",
     "rules/ua/uaprof",
     "uapf", "phb_seam", "k",
     "flat", ()),
    ("uapfNameIsAttributed",
     "rules/ua/uaprof",
     "uapf", "attributed",
     "k", "flat", ()),
    ("uapfInitialSlots",
     "rules/ua/uaprof",
     "uapf", "initial_slots",
     "k", "flat", ()),
    ("uapfNonProfPenalty",
     "rules/ua/uaprof",
     "uapf", "nonprof_penalty",
     "k", "flat", ()),
    ("uapfAddedCadence",
     "rules/ua/uaprof",
     "uapf", "added_cadence",
     "k", "flat", ()),
    ("uapfInitialAsterisk",
     "rules/ua/uaprof",
     "uapf",
     "initial_asterisk",
     "k", "flat", ()),
    ("mwRowLo",
     "rules/dmg/mweapons",
     "mw", "row_lo", "t",
     "flat", ()),
    ("mwRowHi",
     "rules/dmg/mweapons",
     "mw", "row_hi", "t",
     "flat", ()),
    ("mwXpValue",
     "rules/dmg/mweapons",
     "mw", "xp_value", "t",
     "flat", ()),
    ("mwSaleGp",
     "rules/dmg/mweapons",
     "mw", "sale_gp", "t",
     "flat", ()),
    ("mwQtyLo",
     "rules/dmg/mweapons",
     "mw", "qty_lo", "t",
     "flat", ()),
    ("mwQtyHi",
     "rules/dmg/mweapons",
     "mw", "qty_hi", "t",
     "flat", ()),
    ("wpfInitialSlots",
     "rules/phb/weaponprof",
     "wpf", "initial_slots",
     "t", "flat", ()),
    ("wpfNonProfPenalty",
     "rules/phb/weaponprof",
     "wpf", "nonprof_penalty",
     "t", "flat", ()),
    ("wpfAddedCadence",
     "rules/phb/weaponprof",
     "wpf", "added_cadence",
     "t", "flat", ()),
]


# the retiring string readers:
# (fn, file stem, def, array name,
# kind, params)
# kinds: reader (1-arg clamp lo..hi),
#  reader_null (same, but the
#  initializer has 0 cells -> ""),
#  reader_tern (the guard rides a
#  return ternary),
#  gridstr (a0..a1 x b0..b1 padded
#  string grid, flattened row-major,
#  "" cells legal)
READERS = [
    ("uawtName",
     "rules/ua/uaweapontable",
     "wt", "k", "reader",
     ("i", 0, 67)),
    ("uamtName",
     "rules/ua/uamissile",
     "uamt", "k", "reader",
     ("i", 0, 23)),
    ("uamtRateOfFire",
     "rules/ua/uamissile",
     "uamt_rof", "k",
     "reader", ("i", 0, 23)),
    ("uamtRangeShort",
     "rules/ua/uamissile",
     "uamt_range_s", "k",
     "reader", ("i", 0, 23)),
    ("uamtRangeMedium",
     "rules/ua/uamissile",
     "uamt_range_m", "k",
     "reader", ("i", 0, 23)),
    ("uamtRangeLong",
     "rules/ua/uamissile",
     "uamt_range_l", "k",
     "reader", ("i", 0, 23)),
    ("uahhName",
     "rules/ua/uahandheld",
     "uahh", "k", "reader",
     ("i", 0, 59)),
    ("uahhLength",
     "rules/ua/uahandheld",
     "uahh_length", "k",
     "reader", ("i", 0, 59)),
    ("uahhSpaceRequired",
     "rules/ua/uahandheld",
     "uahh_space", "k",
     "reader", ("i", 0, 59)),
    ("uanwName",
     "rules/ua/uanewweapons",
     "uanw", "k", "reader",
     ("i", 0, 15)),
    ("weaponSpecTable"
     "ColumnName",
     "rules/ua/weaponspec",
     "wspec_cols", "k",
     "reader", ("i", 0, 7)),
    ("weaponSpecTable"
     "CellKnown",
     "rules/ua/weaponspec",
     "wspec_cells", "k",
     "gridstr",
     ("band", 0, 2,
      "col", 0, 7)),
    ("uapfName",
     "rules/ua/uaprof",
     "uapf", "k", "reader",
     ("i", 0, 13)),
    ("weaponSpeedFactor",
     "rules/dmg/weaponspeed",
     "wspeed", "t",
     "reader_name",
     ("name",)),
]


LIST_FNS = []

# the KEPT struct seams:
# (file stem, accessor fn, struct
# name, row count, [field names])
KEEP_STRUCTS = []

# the KEPT count fns the generic
# model cannot evaluate (loop
# bodies): (fn, kind, data)
#  ("structfield", fn, struct
#   accessor, field name, count)
#  -> counts of each distinct
#     int field value
#  ("reader", fn, retiring reader,
#   count) -> counts of each
#     distinct reader value
#  ("nonnull", fn, retiring
#   reader, count) -> non-empty
#     names
#  ("freq", fn, struct accessor)
#   -> string-arg counts of the
#     freq column
KEPT_COUNTS = []

# the kept-fn fixups applied to
# the rewritten headers (each
# idempotent: skipped when the
# old text is gone)
KEPT_FIXUPS = []

LUA_TITLE = {
    "wt":
        "UA weight-and-damage "
        "table rows",
    "uamt":
        "UA missile table rows",
    "uamt_rof":
        "UA missile rates of "
        "fire",
    "uamt_range_s":
        "UA missile short "
        "ranges",
    "uamt_range_m":
        "UA missile medium "
        "ranges",
    "uamt_range_l":
        "UA missile long "
        "ranges",
    "uahh":
        "UA handheld table "
        "rows",
    "uahh_length":
        "UA handheld weapon "
        "lengths",
    "uahh_space":
        "UA handheld space "
        "required",
    "uanw":
        "UA new-weapon "
        "roster",
    "wspec_cols":
        "weapon specialization "
        "table columns",
    "wspec":
        "weapon specialization "
        "level bands",
    "wspec_cells":
        "weapon specialization "
        "known cells",
    "uapf":
        "UA proficiency "
        "roster",
    "mw":
        "DMG magic weapon "
        "treasure rows",
    "wspeed":
        "DMG weapon speed "
        "factors",
    "wpf":
        "PHB weapon "
        "proficiency rows",
}

GROUPS = {
    "A": ["wt", "uamt",
          "uamt_rof",
          "uamt_range_s",
          "uamt_range_m",
          "uamt_range_l"],
    "B": ["uahh", "uahh_length",
          "uahh_space", "uanw"],
    "C": ["wspec_cols", "wspec",
          "wspec_cells", "uapf"],
    "D": ["mw", "wspeed",
          "wpf"],
}

LABELS = [
    "load", "counts", "defs-A",
    "defs-B", "defs-C", "defs-D",
    "seam", "edges",
]


def die(msg):
    print("SPLICE FAIL: " + msg)
    sys.exit(1)


# ---- the parse -----------------------

def _strip(s):
    return re.sub(r"//[^\n]*", "", s)


def _fn_args(src, fn):
    m = re.search(
        r"inline [\w\s:\*&]+?"
        r"\b" + fn
        + r"\(([\s\S]*?)\)", src)
    if not m:
        die(fn + " args missing")
    return m.group(1)


def fn_body(src, fn):
    # a brace-counting extractor:
    # single-line bodies ({ ... })
    # and multi-line bodies both
    # parse; the body is the
    # content between the fn's
    # opening brace and its match
    m = re.search(
        r"inline [\w\s:\*&]+?"
        r"\b" + fn + r"\(", src)
    if not m:
        die(fn + " body missing")
    i = src.index("{", m.end())
    depth = 1
    j = i + 1
    while j < len(src) and depth:
        if src[j] == "{":
            depth += 1
        elif src[j] == "}":
            depth -= 1
        j += 1
    if depth:
        die(fn + " braces unbalanced")
    return src[i + 1:j - 1]


def _fn_args(src, fn):
    m = re.search(
        r"inline [\w\s:\*&]+?"
        r"\b" + fn
        + r"\(([\s\S]*?)\)", src)
    if not m:
        die(fn + " args missing")
    return m.group(1)


def _int_vals(body, name, dims):
    pat = (r"static const "
           r"(?:int|uint8_t|bool) " + name
           + r"\[[^\]]*\]" * len(dims)
           + r"\s*=\s*\{([\s\S]*?)\};")
    m = re.search(pat, body)
    if not m:
        die("array " + name
            + " missing")
    vals = [int(v) for v in
            re.findall(r"-?\d+",
                       _strip(m.group(1)))]
    want = 1
    for d in dims:
        want *= d
    if len(vals) != want:
        die("array " + name + " cells "
            + str(len(vals))
            + " != " + str(want))
    return vals


def _pairs_vals(body, name):
    # the name-keyed struct
    # pair list (the
    # weaponSpeedFactor t[]
    # idiom): { "name", sf }
    # initializer entries
    pat = (r"static const struct"
           r"\s*\{[^}]*\} " + name
           + r"\[\] = \{"
           r"([\s\S]*?)\};")
    m = re.search(pat, body)
    if not m:
        die("pair array " + name
            + " missing")
    inner = m.group(1)
    out = []
    for pm in re.finditer(
            r'\{\s*"((?:[^"\\]'
            r'|\\.)*)"\s*,'
            r"\s*(-?\d+)\s*\}",
            inner):
        out.append((pm.group(1),
                    int(pm.group(
                        2))))
    if not out:
        die("pair array " + name
            + " empty")
    return out


def _str_vals(body, name, n):
    pat = (r"static const char\*"
           r"(?: const)? " + name
           + r"\[(?:\d+)\]\s*=\s*"
           r"\{([\s\S]*?)\};")
    m = re.search(pat, body)
    if not m:
        die("string array " + name
            + " missing")
    seg = _strip(m.group(1))
    out = []
    cur = None
    for mm in re.finditer(
            r'"((?:[^"\\]|\\.)*)"',
            seg):
        if cur is not None \
                and seg[cur[1]:mm.start()
                        ].strip():
            out.append(cur[0])
            cur = None
        if cur is None:
            cur = [mm.group(1),
                   mm.end()]
        else:
            cur[0] += mm.group(1)
            cur[1] = mm.end()
    if cur is not None:
        out.append(cur[0])
    if len(out) != n:
        die("string array " + name
            + " names "
            + str(len(out))
            + " != " + str(n))
    return [_cun(x)
            for x in out]


def _cun(s):
    # unescape the C string
    # escapes the family tables
    # carry (\", \\): the lua
    # writer re-escapes on emit
    # (the uahhLength "c. 15\\""
    # lesson - the R1057 tooling
    # never met a backslash cell)
    out = []
    i = 0
    while i < len(s):
        if s[i] == "\\" \
                and i + 1 < len(s):
            c = s[i + 1]
            if c == '"':
                out.append('"')
            elif c == "\\":
                out.append("\\")
            else:
                out.append(s[i:i + 2])
            i += 2
        else:
            out.append(s[i])
            i += 1
    return "".join(out)


def _ragged_vals(body, prefix,
                 counts):
    out = []
    for i, c in enumerate(counts):
        out += _str_vals(
            body, prefix + str(i), c)
    return out


def parse_pristine():
    srcs = {}
    for f in FILES:
        srcs[f] = _strip(
            open(os.path.join(
                ROOT, f)).read())
    p = {"srcs": srcs,
         "ints": {}, "strs": {},
         "pairs": {},
         "grids": {}, "scalars": {},
         "clamps": {}, "args": {}}
    for f in FILES:
        s = srcs[f]
        stem = f[:-2]
        # the zero-arg scalars
        for m in re.finditer(
                r"inline (int|bool)"
                r" (\w+)\(\)\s*\{\s*"
                r"return (-?\d+|true"
                r"|false);",
                s):
            v = m.group(3)
            val = (v == "true"
                   if v in ("true",
                            "false")
                   else int(v))
            p["scalars"][
                m.group(2)] = val
    # the int fns
    for (fn, stem, dkey, tag,
         arr, kind, pp) in INT_FNS:
        s = srcs[
            stem + ".h"]
        b = fn_body(s, fn)
        p["args"][fn] = _fn_args(s, fn)
        if kind == "search":
            vals = _int_vals(
                b, arr, (17, 3))
        elif kind == "pref":
            vals = _int_vals(
                b, arr, (17, 17))
        else:
            dims = _arr_dims(s, b,
                             arr)
            vals = _int_vals(
                b, arr, dims)
        p["ints"][(dkey, tag)] = vals
        p["clamps"][fn] = \
            _clamp_lines(b, kind, pp)
    # the readers
    for (fn, stem, dkey, arr,
         kind, pp) in READERS:
        s = srcs[
            stem + ".h"]
        b = fn_body(s, fn)
        p["args"][fn] = _fn_args(s, fn)
        if kind == "gridstr":
            dims = (pp[2] - pp[1] + 1,
                    pp[5] - pp[4] + 1)
            p["strs"][fn] = \
                _str_grid(
                    b, arr, dims)
        elif kind == \
                "reader_name":
            pairs = \
                _pairs_vals(b, arr)
            p["strs"][fn] = \
                [n for n, _ in
                 pairs]
            p["pairs"][fn] = \
                pairs
            p["ints"][(dkey,
                       "sf")] = \
                [v for _, v in
                 pairs]
        elif kind == "reader_null":
            n = pp[2] - pp[1] + 1
            p["strs"][fn] = \
                _str_vals_null(
                    b, arr, n)
        else:
            n = pp[2] - pp[1] + 1
            p["strs"][fn] = \
                _str_vals(
                    b, arr, n)
        p["clamps"][fn] = \
            _clamp_lines(
                b, kind, pp)
    # the pointer-out lists
    p["lists"] = {}
    for (fn, stem, arr,
         n) in LIST_FNS:
        s = srcs[
            stem + ".h"]
        b = fn_body(s, fn)
        p["lists"][fn] = \
            _str_vals(b, arr, n)
    # the KEPT struct seams:
    # each T initializer parsed
    # into per-record (strings,
    # ints) field tuples
    p["structs"] = {}
    for (stem, afn, sname,
         cnt, fields) in KEEP_STRUCTS:
        s = srcs[
            stem + ".h"]
        p["structs"][afn] = \
            _parse_struct_records(
                s, sname, cnt)
    # the zero-arg const char*
    # fns with literal returns
    p["cstrs"] = {}
    strpat = re.compile(
        r"inline const char\* "
        r"(\w+)\(\)\s*\{\s*"
        r"return\s+((?:\"(?:[^\"\\]"
        r"|\\.)*\"\s*)+);")
    for f in FILES:
        s = srcs[f]
        for m in strpat.finditer(s):
            lit = "".join(
                re.findall(
                    r"\"((?:[^\"\\]"
                    r"|\\.)*)\"",
                    m.group(2)))
            p["cstrs"][
                m.group(1)] = lit
    return p



def _arr_dims(src, body, name):
    m = re.search(
        r"static const "
        r"(?:int|uint8_t|bool) " + name
        + r"((?:\[[^\]]*\])+)"
        r"\s*=", body)
    if not m:
        die("dims of " + name)
    dims = []
    for d in re.findall(
            r"\[([^\]]*)\]", m.group(1)):
        if d.isdigit():
            dims.append(int(d))
        else:
            dm = re.search(
                r"enum \w+ : int "
                r"\{([\s\S]*?)\}",
                src)
            val = None
            for en in re.finditer(
                    r"enum (\w+) : int"
                    r"\{([\s\S]*?)\}",
                    src):
                v = 0
                for part in \
                        en.group(2
                                 ).split(","):
                    part = part.strip()
                    if part.startswith(
                            d + " ") \
                            or part == d \
                            or part.startswith(
                            d + "="):
                        val = v
                    if "=" in part:
                        v = int(part.split(
                            "=")[1])
                    v += 1
            if val is None:
                val = 18  # SUBRACE_COUNT
            dims.append(val)
    return dims


def _str_grid(body, name, dims):
    pat = (r"static const char\*"
           r" const " + name
           + r"\[" + str(dims[0])
           + r"\]\[" + str(dims[1])
           + r"\]\s*=\s*"
           r"\{([\s\S]*?)\};")
    m = re.search(pat, body)
    if not m:
        die("string grid " + name)
    seg = _strip(m.group(1))
    out = []
    cur = None
    for mm in re.finditer(
            r'"((?:[^"\\]|\\.)*)"',
            seg):
        if cur is not None \
                and seg[cur[1]:mm.start()
                        ].strip():
            out.append(cur[0])
            cur = None
        if cur is None:
            cur = [mm.group(1),
                   mm.end()]
        else:
            cur[0] += mm.group(1)
            cur[1] = mm.end()
    if cur is not None:
        out.append(cur[0])
    if len(out) != dims[0] * dims[1]:
        die("string grid " + name
            + " names")
    return [_cun(x)
            for x in out]


def _str_vals_null(body, name, n):
    # a string array whose
    # initializer may hold
    # bare 0 cells (the
    # sacred-animal nullptr
    # seams): each 0 cell
    # retires as ""
    pat = (r"static const char\*"
           r"(?: const)? " + name
           + r"\[(?:\d+)\]\s*=\s*"
           r"\{([\s\S]*?)\};")
    m = re.search(pat, body)
    if not m:
        die("string array " + name
            + " missing")
    seg = _strip(m.group(1))
    # split top-level commas
    cells = []
    depth = 0
    cur = ""
    inq = False
    esc = False
    for c in seg:
        if inq:
            cur += c
            if esc:
                esc = False
            elif c == "\\":
                esc = True
            elif c == '"':
                inq = False
            continue
        if c == '"':
            inq = True
            cur += c
            continue
        if c in "{[(":
            depth += 1
        elif c in "}])":
            depth -= 1
        if c == "," and depth == 0:
            cells.append(cur)
            cur = ""
            continue
        cur += c
    if cur.strip():
        cells.append(cur)
    out = []
    for cell in cells:
        cell = cell.strip()
        if not cell or re.match(
                r"^(0|NULL|"
                r"nullptr)$", cell):
            out.append("")
            continue
        lits = re.findall(
            r'"((?:[^"\\]|\\.)*)"',
            cell)
        if not lits:
            die("null cell parse: "
                + cell[:40])
        out.append("".join(lits))
    if len(out) != n:
        die("string array " + name
            + " cells "
            + str(len(out))
            + " != " + str(n))
    return out


def _parse_struct_records(src, sname,
                          cnt):
    # parse a KEPT struct
    # array's initializer
    # into per-record
    # (strings, ints) tuples
    m = re.search(
        r"static const " + sname
        + r"\s+T\[(?:\d+)\]"
        r"\s*=\s*\{",
        src)
    if not m:
        die("struct array " + sname)
    seg = src[m.end():]
    recs = []
    depth = 0
    rec = None
    for c in seg:
        if c == "{":
            depth += 1
            if depth == 1:
                rec = ""
                continue
        elif c == "}":
            depth -= 1
            if depth == 0 and rec \
                    is not None:
                recs.append(rec)
                rec = None
                continue
            if depth < 0:
                break
        elif rec is not None:
            rec += c
    if len(recs) != cnt:
        die("struct records "
            + sname + ": "
            + str(len(recs)))
    out = []
    for r in recs:
        strs = re.findall(
            r'"((?:[^"\\]|\\.)*)"',
            r)
        ints = [int(v) for v in
                re.findall(
                    r"-?\d+",
                    _strip(r))]
        out.append((strs, ints))
    return out


def _parse_struct_records(src, sname,
                          cnt):
    # parse a KEPT struct
    # array's initializer
    # into per-record
    # (strings, ints) tuples
    # (adjacent string
    # literals join; ints
    # come only from the
    # non-string spans)
    m = re.search(
        r"static const " + sname
        + r"\s+T\[(?:\d+)\]"
        r"\s*=\s*\{",
        src)
    if not m:
        die("struct array " + sname)
    seg = src[m.end():]
    recs = []
    depth = 0
    rec = None
    for c in seg:
        if c == "{":
            depth += 1
            if depth == 1:
                rec = ""
                continue
        elif c == "}":
            depth -= 1
            if depth == 0 and rec \
                    is not None:
                recs.append(rec)
                rec = None
                continue
            if depth < 0:
                break
        elif rec is not None:
            rec += c
    if len(recs) != cnt:
        die("struct records "
            + sname + ": "
            + str(len(recs)))
    # the named area-kind
    # constants (UCO_AREA_SPHERE
    # etc.) resolve to ints
    cmap = {
        m.group(1): int(m.group(2))
        for m in re.finditer(
            r"const int (\w+) ="
            r" (-?\d+);", src)}
    recs = [
        re.sub(
            r"\b(" + "|".join(
                sorted(cmap)) + r")\b",
            lambda mm: str(
                cmap[mm.group(1)]),
            r)
        for r in recs
    ] if cmap else recs
    out = []
    for r in recs:
        strs = []
        ints = []
        last = None
        for mm in re.finditer(
                r'"((?:[^"\\]'
                r'|\\.)*)"',
                r):
            gap = (r[last:mm.start()]
                   if last is not None
                   else r[:mm.start()])
            if strs and gap.strip() \
                    == "" and last \
                    is not None:
                strs[-1] += mm.group(1)
            else:
                if last is not None:
                    ints += [
                        int(v)
                        for v in
                        re.findall(
                            r"-?\d+",
                            gap)]
                else:
                    ints += [
                        int(v)
                        for v in
                        re.findall(
                            r"-?\d+",
                            gap)]
                strs.append(
                    mm.group(1))
            last = mm.end()
        tail = (r[last:]
                if last is not None
                else r)
        ints += [int(v) for v in
                 re.findall(
                     r"-?\d+",
                     _strip(tail))]
        out.append((strs, ints))
    return out


def _clamp_lines(body, kind, pp):
    # the EXACT original
    # clamp/guard statements,
    # comments stripped - the
    # new body reuses them
    # verbatim (R1053 class 5)
    lines = []
    for m in re.finditer(
            r"(?:^|(?<=;))[ \t]*"
            r"(if \([^;]*?\)"
            r"[^;]*?;|return [^;]*?;)",
            _strip(body),
            re.M):
        t = m.group(1).strip()
        if "static const" in t:
            continue
        # an if that INDEXES
        # an array is in-loop
        # logic (the search
        # kind's match if),
        # not a clamp: a real
        # clamp compares
        # scalars only
        if t.startswith("if ") \
                and "[" in t:
            continue
        lines.append(t)
    return lines


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


# ---- the enums + the kept-fn
# model (probe wants) --------

def parse_enums(srcs):
    out = {}
    for f, src in srcs.items():
        for m in re.finditer(
                r"enum (\w+) : int"
                r"[^\{]*\{([\s\S]*?)\}",
                src):
            name, body = m.group(1), m.group(2)
            if name in out:
                continue
            vals = {}
            v = 0
            for part in body.split(","):
                part = re.sub(
                    r"//[^\n]*", "",
                    part).strip()
                mm = re.match(
                    r"(\w+)\s*(?:=\s*"
                    r"(-?\d+))?", part)
                if not mm:
                    continue
                if mm.group(2) is not None:
                    v = int(mm.group(2))
                vals[mm.group(1)] = v
                v += 1
            out[name] = vals
    # the core enums the ua
    # headers lean on (Ability
    # rides engine/character.h)
    core = {}
    for cf in ("rules/engine/"
               "character.h",
               "rules/engine/"
               "races.h"):
        p = os.path.join(ROOT, cf)
        if os.path.exists(p):
            core = _strip(open(p).read())
            for m in re.finditer(
                    r"enum (\w+) : int"
                    r"[^\{]*\{([\s\S]*?)\}",
                    core):
                name = m.group(1)
                if name in out:
                    continue
                vals = {}
                v = 0
                for part in m.group(2).split(","):
                    part = re.sub(
                        r"//[^\n]*", "",
                        part).strip()
                    mm = re.match(
                        r"(\w+)\s*(?:=\s*"
                        r"(-?\d+))?", part)
                    if not mm:
                        continue
                    if mm.group(2) is not None:
                        v = int(mm.group(2))
                    vals[mm.group(1)] = v
                    v += 1
                out[name] = vals
    return out


# every inline fn in the 13
# headers: name -> (file stem,
# return type, args string)
def parse_fns(srcs):
    fns = {}
    for f, src in srcs.items():
        stem = f[:-2]
        for m in re.finditer(
                r"inline ((?:[\w:\*&]+"
                r"(?:\s+|\s*\*\s*)"
                r")+?)\b(\w+)\("
                r"([\s\S]*?)\)\s*\{",
                src):
            ret, name, args = m.groups()
            if name in ("wReg", "wRows",
                        "wTable"):
                continue
            fns[name] = (stem, ret.strip(),
                         " ".join(args.split()))
    return fns


RETIRED = set()
for _t in INT_FNS:
    RETIRED.add(_t[0])
for _t in READERS:
    RETIRED.add(_t[0])


class Model:
    # the generic C-subset
    # evaluator over the KEPT
    # fns. DIE on anything it
    # cannot model (fail loud).
    def __init__(self, p, enums, fns):
        self.p = p
        self.enums = enums
        self.fns = fns
        self.cache = {}

    def enumval(self, tok):
        for _, vals in self.enums.items():
            if tok in vals:
                return vals[tok]
        return None

    def ret_of(self, fn):
        return self.fns[fn][1]

    def args_of(self, fn):
        a = self.fns[fn][2]
        return [x.strip() for x in
                a.split(",") if x.strip()]

    def call(self, fn, args):
        key = (fn, tuple(args))
        if key in self.cache:
            return self.cache[key]
        stem = self.fns[fn][0]
        src = self.p["srcs"][
            stem + ".h"]
        body = fn_body(src, fn)
        body = _strip(body)
        names = [x.split()[-1].strip("&")
                 .strip("[]") for x in
                 self.args_of(fn)]
        env = dict(zip(names, args))
        val = self.eval_body(
            body, env)
        self.cache[key] = val
        return val

    def eval_body(self, body, env):
        # local decls ASSIGN into
        # the env (a formula's
        # named temporaries)
        while True:
            dm = re.search(
                r"\b(?:int|bool)\s+"
                r"(\w+)\s*=\s*"
                r"([^;]+);", body)
            if not dm:
                break
            env[dm.group(1)] = \
                self.eval_expr(
                    dm.group(2), env)
            body = body[:dm.start()] \
                + body[dm.end():]
        # a lone return expression
        m = re.match(
            r"^\s*(?:return\s+"
            r"([\s\S]*?);)\s*$",
            body.strip())
        if m:
            return self.eval_expr(
                m.group(1), env)
        # guard chain: a run of
        # if (...) ...; return ...;
        lines = body.strip()
        # switch statement?
        sm = re.match(
            r"^switch \((\w+)\)"
            r"\s*\{([\s\S]*)\}$",
            lines)
        if sm:
            return self.eval_switch(
                sm.group(1),
                sm.group(2), env)
        # if-chain
        if lines.startswith("if ("):
            return self.eval_ifchain(
                lines, env)
        raise ValueError(
            "unmodelable body: "
            + lines[:60])

    def eval_switch(self, var, body,
                    env):
        val = env[var]
        # split into labeled
        # arms; a DEFAULT arm
        # may hold an if-chain
        # (cavalierTitleKnown's
        # OCR-hole guard) -
        # evaluate it as a
        # body, not a lone
        # return expr
        labs = list(re.finditer(
                r"case ([\w]+):"
                r"|default:", body))
        arms = []
        for i, m in \
                enumerate(labs):
            if m.group(0) \
                    == "default:":
                lab = "DEFAULT"
            else:
                lab = \
                    m.group(1)
                lv = self.enumval(
                    lab)
                if lv is None:
                    lv = int(lab)
                lab = lv
            end = (labs[i + 1]
                   .start()
                   if i + 1
                   < len(labs)
                   else len(body))
            arms.append((lab,
                         body[
                          m.end():
                          end]))
        dflt = None
        for lab, text in arms:
            if lab == "DEFAULT":
                dflt = text
                continue
            if lab == val:
                return self.\
                    eval_arm(text,
                             env)
        if dflt is not None:
            return self.eval_arm(
                dflt, env)
        raise ValueError(
            "switch fallthrough")

    def eval_arm(self, text, env):
        # an arm is a lone
        # return (possibly
        # line-wrapped) or a
        # small if-chain body
        t = text.strip()
        m = re.match(
            r"return\s+"
            r"([\s\S]*?);\s*$",
            t)
        if m:
            return self.eval_expr(
                m.group(1), env)
        if t.startswith("if (") \
                or t.startswith(
                    "if("):
            return self.\
                eval_ifchain(t,
                             env)
        return self.eval_body(
            t, env)

    def eval_ifchain(self, text, env):
        # split into (cond, expr)
        # pairs + final return
        rest = text
        pairs = []
        while True:
            m = re.match(
                r"if \(([\s\S]*?)\)"
                r"\s*(\{[^\}]*\}"
                r"|return\s+[\s\S]*?;)"
                r"\s*",
                rest, re.S)
            if not m:
                break
            cond = m.group(1)
            act = m.group(2)
            if act.startswith("{"):
                act = act.strip("{}"
                                ).strip()
            expr = re.match(
                r"return\s+([\s\S]*?);",
                act)
            if not expr:
                # a block: handle a
                # single nested return
                # after a nested if
                raise ValueError(
                    "unmodelable if "
                    + act[:40])
            pairs.append((cond,
                          expr.group(1)))
            rest = rest[m.end():]
        tail = re.match(
            r"return\s+([\s\S]*?);"
            r"\s*$", rest.strip())
        if not tail:
            raise ValueError(
                "if-chain tail "
                + rest[:40])
        pairs.append(("1", tail.group(1)))
        for cond, expr in pairs:
            if self.eval_cond(cond,
                              env):
                return self.eval_expr(
                    expr, env)
        raise ValueError("no branch")

    def eval_cond(self, cond, env):
        return self.eval_expr(
            cond, env) != 0

    def eval_expr(self, expr, env):
        e = re.sub(r"\s+", " ",
                   expr).strip()
        # casts out
        e = re.sub(
            r"\((?:unsigned |long |"
            r"int|bool|char|size_t|"
            r"RacePref|CharSubRace|"
            r"CharRace|Ability|"
            r"HierophantConjure|"
            r"HierophantPlane|"
            r"CavalierTrack|"
            r"CavalierWeaponOfChoice|"
            r"UaAlignReq|UaClass|"
            r"HalfElfAncestry|"
            r"GenMethod|XPPct)\)",
            "", e)
        # true/false
        e = re.sub(r"\btrue\b", "1",
                   e)
        e = re.sub(r"\bfalse\b", "0",
                   e)
        # nested calls first
        # (innermost parens)
        while True:
            cm = re.search(
                r"\b(\w+)\("
                r"([^()]*?)\)", e)
            if not cm:
                break
            fn = cm.group(1)
            if fn in self.fns \
                    and fn not in \
                    RETIRED:
                raw = cm.group(2)
                argv = []
                for part in raw.split(","):
                    part = part.strip()
                    if not part:
                        continue
                    argv.append(
                        self.eval_expr(
                            part, env))
                # enum-typed args:
                # ints are fine
                v = self.call(fn, argv)
                e = e[:cm.start()] \
                    + repr(v) + e[cm.end():]
            else:
                # min/max idioms
                break
        # enum tokens
        def sub_tok(mm):
            v = self.enumval(mm.group(0))
            if v is None:
                raise ValueError(
                    "token " + mm.group(0))
            return str(v)
        e = re.sub(r"\b[A-Z][A-Z_0-9]{2,}\b",
                   sub_tok, e)
        # C ops
        e = e.replace("&&", " and ")
        e = e.replace("||", " or ")
        e = re.sub(r"!(?!=)", " not ", e)
        # ternaries: innermost
        while "?" in e:
            tm = re.search(
                r"\(([^()?]+)\)"
                r"\s*\?\s*([^()?:]*)"
                r"\s*:\s*([^()?:]*)",
                e)
            if tm:
                c = self.eval_expr(
                    tm.group(1), {})
                pick = tm.group(2) \
                    if self.eval_expr(
                        c, {}) \
                    else tm.group(3)
                e = e[:tm.start()] \
                    + "(" + pick + ")" \
                    + e[tm.end():]
                continue
            tm = re.search(
                r"([^()?]+)\s*\?\s*"
                r"([^()?:]*)\s*:\s*"
                r"([^()?:]*)", e)
            if not tm:
                raise ValueError(
                    "ternary " + e[:40])
            c = self.eval_expr(
                tm.group(1), env)
            pick = tm.group(2) \
                if c else tm.group(3)
            e = e[:tm.start()] \
                + "(" + pick + ")" \
                + e[tm.end():]
        # python-safe eval
        e = re.sub(r"\sint\b", "", e)
        try:
            return eval(
                e, {"__builtins__": {}},
                dict(env))
        except Exception as ex:
            raise ValueError(
                "expr " + expr[:50]
                + " -> " + str(ex))


def build_defs(p):
    rows = {}
    for dkey, src in DEF_ROWS:
        if src.startswith("reader:"):
            rows[dkey] = p["strs"][
                src[7:]]
        elif src.startswith("computed:"):
            _, prefix, lo, n = \
                src.split(":")
            rows[dkey] = [
                prefix + str(i)
                for i in range(
                    int(lo),
                    int(lo) + int(n))]
        elif src.startswith(
                "structnames:"):
            fn = src[12:]
            rows[dkey] = [
                rec[0][0]
                for rec in
                p["structs"][fn]]
        elif src.startswith("cstrs:"):
            fns = src[6:].split(",")
            rows[dkey] = [
                p["cstrs"][fn]
                for fn in fns]
        elif src.startswith("pairs:"):
            rows[dkey] = [n for n, _
                          in p["pairs"]
                          [src[6:]]]
        else:
            die("rows source " + src)
    return rows


def prefix_sums(counts):
    out = []
    acc = 0
    for c in counts:
        out.append(acc)
        acc += c
    return out


def build_tables(p):
    # (def, tag) -> values;
    # grid2 flatten, all
    # derived from the parse
    # (no computed offsets
    # this round)
    t = {}
    for (fn, stem, dkey, tag,
         arr, kind, pp) in INT_FNS:
        vals = p["ints"][(dkey, tag)]
        t[(dkey, tag)] = vals
    for spec in READERS:
        # reader_name pairs: the
        # sf column rides the
        # wTable side channel
        if spec[4] == "reader_name":
            t[(spec[2], "sf")] = \
                p["ints"][
                    (spec[2], "sf")]
    return t


# ---- the lua emit ----------------------------

def _q(t):
    return t.replace("\\", "\\\\").replace(
        "\"", "\\\"")


def def_tables(dkey, tables):
    out = []
    for (d, tag), vals in tables.items():
        if d == dkey:
            out.append((tag, vals))
    out.sort(key=lambda x: x[0])
    return out


def table_comment(fn, stem, dkey,
                  tag, arr, kind, pp):
    n = "the " \
        + LUA_TITLE.get(
            dkey, dkey) \
        + " " + tag + " column"
    if kind == "band":
        n += ("; banded reads "
              "index arg - "
              + str(pp[0]))
    elif kind == "grid2":
        n += ("; [a][b] FLATTENED "
              "a-major, width "
              + str(pp[0]))
    elif kind == "search":
        n += ("; the [17][3] "
              "search triples "
              "flat")
    elif kind == "pref":
        n += ("; the [17][17] "
              "matrix FLATTENED "
              "viewer-major")
    elif kind == "dex":
        n += ("; dex band "
              "16-19 reads "
              "arg - 16")
    if tag.endswith("_offset"):
        n += ("; COMPUTED "
              "prefix sums")
    return n


def lua_def(dkey, rows, tables,
            intmeta):
    out = []
    w = out.append
    tabs = def_tables(dkey, tables)
    n = len(rows[dkey])
    w("-- " + dkey)
    w("-- The R1058 weapons-family "
      "de-wire.")
    w("-- " + LUA_TITLE[dkey] + ".")
    w("-- rows[]: the def's row names -"
      " the R1042 equipment rows idiom"
      " (computed names where the print"
      " has no name list).")
    w("-- tables[]: the printed columns;"
      " the accessors live in the "
      "family headers"
      " and keep their clamps.")
    w("-- DO NOT hand-edit: "
      "tools/r1058_splice.py is the "
      "only writer.")
    w("")
    w("return {")
    w("  key = \"%s\"," % dkey)
    w("  name = \"%s\"," % LUA_TITLE[dkey])
    w("  sources = {")
    w("    { part = 0, round = 1058 },")
    w("  },")
    w("  pins = {")
    w("    { name = \"%sRowCount\","
      % dkey)
    w("      value = %d," % n)
    w("      comment = \"the table "
      "rows\" },")
    w("  },")
    w("  rows = {")
    for i, nm in enumerate(rows[dkey]):
        w("    { name = \"%s\"," % _q(nm))
        w("      set = \"%s\"," % dkey)
        w("      band = { %d, %d },"
          % (i, i))
        w("      xp = 0, xp_hi = 0, "
          "gp = 0, gp_hi = 0,")
        w("      qty = { 0, 0 } },")
    w("  },")
    w("  tables = {")
    for tag, vals in tabs:
        w("    { name = \"%s\"," % tag)
        w("      values = {")
        for r in range(0, len(vals), 10):
            w("        "
              + ", ".join(str(v)
                         for v in
                         vals[r:r + 10])
              + ", ")
        w("      },")
        meta = intmeta.get(
            (dkey, tag))
        if meta:
            cmt = table_comment(
                *meta)
        else:
            cmt = ("the computed "
                   "prefix-sum "
                   "offsets")
        w("      comment = \"%s\" },"
          % _q(cmt))
    w("  },")
    w("}")
    w("")
    return "\n".join(out)


def build_lua(rows, tables,
              intmeta):
    os.makedirs(
        os.path.join(ROOT, LUA_DIR),
        exist_ok=True)
    wrote = []
    for dkey in DEFS:
        txt = lua_def(dkey, rows,
                      tables, intmeta)
        path = os.path.join(
            ROOT, LUA_DIR,
            dkey + ".lua")
        open(path, "w").write(txt)
        wrote.append(dkey)
    return wrote


# ---- the seam header --------------------------

SEAM_HDR = """\
// ===========================================================================
// Adnd1 - rules/seams/weaponsreg.h
// The R1058 weapons-family registry seam.
//
// content/tables/weapondata/ (R1058)
// via items::MiscItemRegistry: the R1042
// rows idiom plus named tables per def
// (the R1051 dzTable idiom) and the rows
// readers (the R1051 dzRows idiom). Header-
// only singleton (the R1040 appendixp.h
// idiom). Every accessor in the weapons
// family headers keeps its signature, clamp
// and branch; only the array read moves
// behind the registry. The R1056 uaregistry
// precedent, seated at rules/seams for the
// first cross-book family.
// DO NOT hand-edit: tools/r1058_splice.py
// is the only writer.
// ===========================================================================

#pragma once

#include "items/MiscItemRegistry.h"

namespace rules {

// ---- the weapons-family registry seam ----

inline items::MiscItemRegistry&
wReg() {
    static items::MiscItemRegistry
        reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory(
            "content/tables/"
            "weapondata");
    }
    return reg;
}

// the name rows of one def
inline const std::vector<
    items::MiscItemRow>& wRows(
        const char* key) {
    static std::map<std::string,
        std::vector<
            items::MiscItemRow>>
        cache;
    auto it = cache.find(key);
    if (it == cache.end()) {
        const items::MiscItemDef*
            d = wReg().find(key);
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
// (null when absent or empty -
// the MiscItemTable values are
// long long, NOT long: the
// R1058 preflight caught the
// derived seam's dropped long)
inline const std::vector<
    long long>* wTable(
        const char* key,
        const char* tag) {
    static std::map<std::string,
        std::vector<
            long long>>
        cache;
    std::string ck =
        std::string(key)
        + "/" + tag;
    auto it = cache.find(ck);
    if (it == cache.end()) {
        const items::
            MiscItemDef*
            d = wReg().find(key);
        const std::vector<
            long long>* v = nullptr;
        if (d) {
            for (const auto&
                     t : d->tables)
                if (t.name == tag) {
                    v = &t.values;
                    break;
                }
        }
        it = cache.emplace(
            ck, v ? *v
                  : std::vector<
                        long long>()
            ).first;
    }
    return it->second.empty()
        ? nullptr
        : &it->second;
}

}   // namespace rules
"""




def write_seam_header():
    path = os.path.join(
        ROOT, "rules/seams/",
        "weaponsreg.h")
    open(path, "w").write(SEAM_HDR)


# ---- the header rewrite -----------------------

# the emitted body of one
# retiring fn (clamps and
# guards verbatim from the
# parse; the read on the
# seam)
def _guard_ret(clamps):
    # the first guard that
    # RETURNS a value (the
    # parsed fallback), or
    # None
    for c in clamps:
        m = re.match(
            r"if \([^)]*\)"
            r"[\s\S]*?"
            r"return (-?\d+);", c)
        if m:
            return int(m.group(1))
    return None


def _idx_expr(clamps):
    # the index expression of
    # the final `return k[...];`
    m = re.search(
        r"return \w+\[([^\]]*)\]"
        r"\s*;", clamps[-1])
    if m:
        return m.group(1).strip()
    return None


def new_body_int(fn, dkey, tag,
                 kind, pp, clamps,
                 vals):
    guards = clamps[:-1]
    idx = _idx_expr(clamps)
    gret = _guard_ret(clamps)
    out = []
    a = out.append
    a("    const auto* g = wTable(")
    a("        \"%s\", \"%s\");"
      % (dkey, tag))
    for g in guards:
        a("    " + g)
    if kind in ("band", "range0",
                "dex"):
        fb = gret if gret \
            is not None else 0
        a("    if (!g) return %d;" % fb)
    elif kind == "search":
        a("    if (!g) return -1;")
    elif kind == "pref":
        a("    if (!g) return PREF_N;")
    else:
        a("    if (!g) return %d;"
          % vals[0])
    if kind == "search":
        a("    for (int i = 0; i < 17;"
          " ++i)")
        a("        if ((*g)[i * 3] =="
          " level")
        a("            && (*g)[i * 3"
          " + 1] == feet)")
        a("            return (*g)"
          "[i * 3 + 2];")
        a("    return -1;")
    elif kind == "pref":
        a("    return (RacePref)"
          "(*g)[(viewer - 1) * 17")
        a("        + (viewed - 1)];")
    elif kind == "grid2":
        wd = pp[0]
        m = re.search(
            r"return \w+\[([^\]]*)\]"
            r"\[([^\]]*)\]", clamps[-1])
        ia, ib = m.group(1).strip(), \
            m.group(2).strip()
        a("    return (int)(*g)"
          "[(%s) * %d" % (ia, wd))
        a("        + (%s)];" % ib)
    else:
        a("    return (int)(*g)"
          "[%s];" % idx)
    return "\n".join(out)


def new_body_reader(fn, dkey,
                    kind, pp, clamps):
    out = []
    a = out.append
    if kind == "reader_tern":
        # the guard rides the
        # return ternary
        # (uapcSertenName): keep
        # it verbatim with the
        # array read swapped
        a("    const auto& rows = "
          "wRows(\"%s\");" % dkey)
        a("    if (rows.empty())")
        a("        return \"\";")
        t = clamps[-1]
        arg = pp[0]
        t = re.sub(
            r"\b\w+\[" + arg + r"\]",
            "rows[" + arg
            + "].name.c_str()", t)
        a("    " + t)
        return "\n".join(out)
    if kind == "gridstr":
        # the padded string grid:
        # both clamps verbatim,
        # the read flattened
        # row-major
        (an, alo, ahi, bn,
         blo, bhi) = pp
        a("    const auto& rows = "
          "wRows(\"%s\");" % dkey)
        a("    if (rows.empty())")
        a("        return \"\";")
        for g in clamps[:-1]:
            if not g.startswith("if "):
                continue
            a("    " + g)
        m = re.search(
            r"return \w+\[([^\]]*)\]"
            r"\[([^\]]*)\]", clamps[-1])
        ia, ib = m.group(1).strip(), \
            m.group(2).strip()
        wdt = bhi - blo + 1
        a("    if ((int)rows.size()"
          " <= (%s) * %d"
          % (ia, wdt))
        a("        + (%s))" % ib)
        a("        return \"\";")
        a("    return rows[(%s) * %d"
          % (ia, wdt))
        a("        + (%s)].name"
          ".c_str();" % ib)
        return "\n".join(out)
    if kind == "reader_name":
        # the wspeed idiom: a
        # name-keyed struct pair
        # list, retuned through
        # the wTable sf column
        arg = pp[0]
        a("    const auto& rows = "
          "wRows(\"%s\");" % dkey)
        a("    const auto* g = wTable("
          "\"%s\", \"sf\");" % dkey)
        a("    if (rows.empty() || !g)")
        a("        return 0;")
        a("    for (int i = 0;"
          " i < (int)rows.size();"
          " ++i) {")
        a("        if (std::strcmp(%s,"
          " rows[i].name.c_str())"
          % arg)
        a("                == 0)")
        a("            return (int)"
          "(*g)[i];")
        a("    }")
        a("    return 0;")
        return "\n".join(out)
    a("    const auto& rows = "
      "wRows(\"%s\");" % dkey)
    a("    if (rows.empty())")
    a("        return \"\";")
    for g in clamps[:-1]:
        # only if-statements
        # re-emit (a bare
        # return mid-body is
        # not a clamp)
        if not g.startswith("if "):
            continue
        a("    " + g)
    if kind == "reader2":
        m = re.search(
            r"return \w+\[([^\]]*)\]"
            r"\[([^\]]*)\]", clamps[-1])
        ia, ib = m.group(1).strip(), \
            m.group(2).strip()
        wdt = pp[5] - pp[4] + 1
        a("    if ((int)rows.size()"
          " <= (%s) * %d" % (ia, wdt))
        a("        + (%s))" % ib)
        a("        return \"\";")
        a("    return rows[(%s) * %d"
          % (ia, wdt))
        a("        + (%s)].name"
          ".c_str();" % ib)
        return "\n".join(out)
    idx = _idx_expr(clamps)
    a("    if ((int)rows.size()"
      " <= (%s))" % idx)
    a("        return \"\";")
    a("    return rows[%s].name"
      ".c_str();" % idx)
    return "\n".join(out)


def rewrite_file(path, fns_in_file,
                 p, tables):
    raw = open(path).read()
    src = _strip(raw)
    changed = False
    for spec in fns_in_file:
        fn = spec[0]
        m = re.search(
            r"^[ \t]*inline [\w\s:\*&]+?"
            r"\b" + fn + r"\(",
            raw, re.M)
        if not m:
            die(fn + " decl missing in "
                + path)
        # the exact signature span
        # in the RAW text: find the
        # opening brace, then the
        # matching close
        i = raw.index("{", m.start())
        depth = 1
        j = i + 1
        while j < len(raw) and depth:
            if raw[j] == "{":
                depth += 1
            elif raw[j] == "}":
                depth -= 1
            j += 1
        if depth:
            die(fn + " braces")
        sig = raw[m.start():i + 1]
        if spec[1] == "int":
            (fn2, stem, dkey, tag,
             arr, kind, pp) = spec[2]
            vals = tables[(dkey, tag)]
            body = new_body_int(
                fn, dkey, tag, kind, pp,
                p["clamps"][fn], vals)
        else:
            (fn2, stem, dkey, arr,
             kind, pp) = spec[2]
            body = new_body_reader(
                fn, dkey, kind, pp,
                p["clamps"][fn])
        newtxt = sig + "\n" + body \
            + "\n}"
        raw = (raw[:m.start()]
               + newtxt
               + raw[j:])
        src = _strip(raw)
        changed = True
    # the seam include + mark
    if APPLIED_MARK not in raw:
        insert = (APPLIED_MARK
                  + "\n#include \"rules/seams/"
                  "weaponsreg.h\"\n")
        if "#pragma once\n" in raw:
            raw = raw.replace(
                "#pragma once\n",
                "#pragma once\n\n"
                + insert, 1)
        else:
            # a header with no
            # pragma (uafollowers.h):
            # seat the mark after
            # the leading banner
            m2 = re.match(
                r"(//[^\n]*\n)+", raw)
            at = m2.end() if m2 \
                else 0
            raw = (raw[:at]
                   + "\n" + insert
                   + raw[at:])
        changed = True
    if changed:
        open(path, "w").write(raw)
    return changed


def rewrite_headers(p, tables):
    by_file = {}
    for spec in INT_FNS:
        by_file.setdefault(
            spec[1] + ".h",
            []).append(("int", spec))
    for spec in READERS:
        by_file.setdefault(
            spec[1] + ".h",
            []).append(("reader",
                        spec))
    applied = 0
    for path, specs in by_file.items():
        full = os.path.join(
            ROOT, path)
        raw = open(full).read()
        if APPLIED_MARK in raw:
            continue
        specs = [x[1] if x[0]
                 == "int" else x[1]
                 for x in specs]
        # tag each with its class
        wrapped = []
        for x in specs:
            cls = "int" \
                if x in INT_FNS \
                else "reader"
            wrapped.append((x[0],
                            cls, x))
        if rewrite_file(full,
                        wrapped, p,
                        tables):
            applied += 1
    return applied


# ---- the seam model (the ------
# edges wants of the REWRITTEN
# accessors; the clamps run
# generically off the parse) ---

def run_clamps(clamps, env, model):
    # returns ("ret", v) on a
    # returning guard, else None
    for c in clamps[:-1]:
        m = re.match(
            r"if \(([\s\S]*?)\)\s*"
            r"return ([\s\S]*?);", c)
        if m:
            if model.eval_expr(
                    m.group(1),
                    dict(env)):
                return ("ret",
                        model.eval_expr(
                            m.group(2),
                            dict(env)))
            continue
        m = re.match(
            r"if \(([\s\S]*?)\)\s*"
            r"(\w+) = ([\s\S]*?);", c)
        if m:
            if model.eval_expr(
                    m.group(1),
                    dict(env)):
                env[m.group(2)] = \
                    model.eval_expr(
                        m.group(3),
                        dict(env))
            continue
        m = re.match(
            r"(\w+) = ([\s\S]*?);", c)
        if m:
            env[m.group(1)] = \
                model.eval_expr(
                    m.group(2),
                    dict(env))
    return None


def seam_eval_int(fn, args, p,
                  tables, model):
    spec = None
    for t in INT_FNS:
        if t[0] == fn:
            spec = t
            break
    (fn2, stem, dkey, tag, arr,
     kind, pp) = spec
    vals = tables[(dkey, tag)]
    names = [x.split()[-1]
             .strip("&").strip("[]")
             for x in
             model.args_of(fn)]
    env = dict(zip(names, args))
    clamps = p["clamps"][fn]
    r = run_clamps(clamps, env,
                   model)
    if r:
        return r[1]
    if kind == "search":
        for i in range(17):
            if (vals[i * 3]
                    == args[0]
                    and vals[i * 3 + 1]
                    == args[1]):
                return vals[
                    i * 3 + 2]
        return -1
    if kind == "pref":
        if (args[0] < 1
                or args[0] > 17
                or args[1] < 1
                or args[1] > 17):
            return 3  # PREF_N
        return vals[(args[0] - 1)
                    * 17
                    + (args[1] - 1)]
    if kind == "grid2":
        m = re.search(
            r"return \w+\[([^\]]*)\]"
            r"\[([^\]]*)\]",
            clamps[-1])
        ia = model.eval_expr(
            m.group(1), dict(env))
        ib = model.eval_expr(
            m.group(2), dict(env))
        w = pp[0]
        return vals[ia * w + ib]
    idx = _idx_expr(clamps)
    i = model.eval_expr(
        idx, dict(env))
    if i < 0 or i >= len(vals):
        die("seam_eval_int "
            + fn
            + " out of range: "
            + str(i))
    return vals[i]


def seam_eval_reader(fn, args, p,
                     rows, model):
    spec = None
    for t in READERS:
        if t[0] == fn:
            spec = t
            break
    (fn2, stem, dkey, arr, kind,
     pp) = spec
    names = [x.split()[-1]
             .strip("&").strip("[]")
             for x in
             model.args_of(fn)]
    env = dict(zip(names, args))
    clamps = p["clamps"][fn]
    if kind == "reader_tern":
        lo, hi = pp[1], pp[2]
        a = args[0]
        if a < lo or a > hi:
            return ""
        return rows[dkey][a]
    if kind == "gridstr":
        (an, alo, ahi, bn,
         blo, bhi) = pp
        r = run_clamps(clamps, env,
                       model)
        if r is not None:
            die("gridstr guard "
                + fn)
        m = re.search(
            r"return \w+\[([^\]]*)\]"
            r"\[([^\]]*)\]", clamps[-1])
        ia = model.eval_expr(
            m.group(1), dict(env))
        ib = model.eval_expr(
            m.group(2), dict(env))
        wdt = bhi - blo + 1
        i = ia * wdt + ib
        if i < 0 \
                or i >= len(rows[dkey]):
            die("gridstr index "
                + fn + ": "
                + str(i))
        return rows[dkey][i]
    if kind == "reader_name":
        # the wspeed idiom: a
        # name-keyed pair list -
        # unknown names read 0
        # (checked BEFORE the
        # clamp walk: the bare
        # "return 0;" tail is
        # the unknown-name
        # fallback, not a
        # guard)
        sf = tables_get(
            p, (dkey, "sf"))
        names = rows[dkey]
        if args[0] in names:
            return sf[
                names.index(
                    args[0])]
        return 0
    r = run_clamps(clamps, env,
                   model)
    if r is not None:
        die("reader with a "
            "returning guard: "
            + fn)
    if kind == "reader2":
        wdt = pp[5] - pp[4] + 1
        t = max(pp[1],
                min(pp[2],
                    args[0]))
        row = max(pp[4],
                  min(pp[5],
                      args[1]))
        return rows[dkey][
            t * wdt + row]
    idx = _idx_expr(clamps)
    i = model.eval_expr(
        idx, dict(env))
    if i < 0 or i >= len(rows[dkey]):
        return ""
    return rows[dkey][i]


def tables_get(p, key):
    # the parse-level table
    # (used by seam_eval_reader
    # before build_tables)
    if key == ("ua_cavmoney",
               "item_offset"):
        c = p["ints"][
            ("ua_cavmoney",
             "item_count")]
        return prefix_sums(c)
    if key == ("ua_socialclass",
               "roster_offset"):
        c = p["ints"][
            ("ua_socialclass",
             "roster_count")]
        return prefix_sums(c)
    return p["ints"][key]


# ---- the fragment emit ------------------------

F_INC = ('    #include "rules/'
         'audits/'
         'r1058_weapons_registry.h"'
         '  // R1058')


class FE:
    # the fragment emitter
    def __init__(self, p, enums,
                 fns, rows, tables):
        self.p = p
        self.enums = enums
        self.fns = fns
        self.rows = rows
        self.tables = tables
        self.model = Model(
            p, enums, fns)
        self.out = []
        self.seam_accessors = \
            {}

    def w(self, line=""):
        self.out.append(line)

    def head(self):
        self.w("    // ==== R1058: "
               "weapons registry "
               "==========")
        self.w("    // The R1058 "
               "de-wire: the 49 "
               "retiring static")
        self.w("    // arrays of the "
               "eleven cross-book "
               "WEAPONS-family")
        self.w("    // headers ride "
               "items::MiscItemRegistry "
               "from")
        self.w("    // content/tables/"
               "weapondata/ - %d defs,"
               % len(DEFS)
               + " %d tables, %d"
               % (len(INT_FNS),
                  len(READERS))
               + " rows readers;")
        self.w("    // the six KEPT "
               "struct/logic seams "
               "and the count fns "
               "stay C++,")
        self.w("    // probed by the "
               "older pin fragments "
               "and the model "
               "here. Eight "
               "sections: load, "
               "counts,")
        self.w("    // defs-A/B/C/D, "
               "seam, edges. Census "
               "%d -> %d."
               % (CENSUS_BEFORE,
                  CENSUS_AFTER)
               + " DO NOT hand-edit:")
        self.w("    // tools/"
               "r1058_splice.py is "
               "the only writer.")
        self.w("    {")
        self.w("        int bad = 0;")

    def guard(self, idx):
        self.w('        printf('
               '"R1058 weapons '
               'registry %s audit: '
               'bad %%d\\n", bad);'
               % LABELS[idx])
        if idx < len(LABELS) - 1:
            self.w(
                "        if (bad)"
                " return 1;")
            self.w("        bad = 0;")

    # 1. load
    def sec_load(self):
        self.w("        // -- 1. "
               "load -------------"
               "-----------------")
        self.w("        {")
        self.w("            items::"
               "MiscItemRegistry reg;")
        self.w("            int n = "
               "reg.loadDirectory(")
        self.w('                "'
               'content/tables/'
               'weapondata");')
        self.w("            if (n != "
               "%d) ++bad;" % len(DEFS))
        self.w("            if (!reg."
               "errors().empty()) "
               "++bad;")
        self.w("            for (const "
               "auto& kv : reg.all())")
        self.w("                if ((int)"
               "kv.second.sources."
               "size() != 1")
        self.w("                    || "
               "kv.second.sources[0]"
               ".second != %d)"
               % ROUND)
        self.w("                    "
               "++bad;")
        for d in DEFS:
            self.w('            if (!reg'
                   '.find("%s")) ++bad;'
                   % d)
        self.w("        }")
        self.guard(0)

    # 2. counts
    def sec_counts(self):
        self.w("        // -- 2. "
               "counts -------------"
               "-------------")
        self.w("        {")
        self.w("            items::"
               "MiscItemRegistry reg;")
        self.w("            reg."
               "loadDirectory(")
        self.w('                "'
               'content/tables/'
               'weapondata");')
        for d in DEFS:
            tabs = def_tables(
                d, self.tables)
            self.def_block(d, tabs)
        self.w("        }")
        self.guard(1)

    def def_block(self, d, tabs):
        self.w("            {")
        self.w("                const "
               "items::MiscItemDef* d "
               "=")
        self.w('                    reg'
               '.find("%s");' % d)
        self.w("                if (!d) "
               "{ ++bad; } else {")
        self.w("                    if "
               "((int)d->rows.size() "
               "!= %d"
               % len(self.rows[d]))
        self.w("                        || "
               "(int)d->pins.size() "
               "!= 1")
        self.w('                        || '
               'd->pins[0].name')
        self.w('                            != '
               '"%sRowCount"' % d)
        self.w("                        || "
               "d->pins[0].value "
               "!= %d)"
               % len(self.rows[d]))
        self.w("                        "
               "++bad;")
        self.w("                    if "
               "((int)d->tables.size() "
               "!= %d) ++bad;"
               % len(tabs))
        for ti, (tag,
                 vals) in enumerate(tabs):
            self.w("                    if "
                   "(d->tables[%d].name"
                   % ti)
            self.w('                        != '
                   '"%s"' % tag)
            self.w("                        || "
                   "(int)d->tables[%d]"
                   % ti)
            self.w("                            "
                   ".values.size() != "
                   "%d)" % len(vals))
            self.w("                        "
                   "++bad;")
        self.w("                }")
        self.w("            }")

    # 3-6. defs groups
    def sec_defs(self, gi, gname):
        self.w("        // -- %d. %s --"
               % (gi + 3, gname)
               + "-" * max(1,
                           28 - len(
                               gname)))
        self.w("        {")
        self.w("            items::"
               "MiscItemRegistry reg;")
        self.w("            reg."
               "loadDirectory(")
        self.w('                "'
               'content/tables/'
               'weapondata");')
        for d in GROUPS[gname]:
            self.def_checks(d)
        self.w("        }")
        self.guard(gi + 2)

    def def_checks(self, d):
        tabs = def_tables(
            d, self.tables)
        self.w("            {")
        self.w("                const "
               "items::MiscItemDef* d "
               "=")
        self.w('                    reg'
               '.find("%s");' % d)
        self.w("                if (!d) "
               "{ ++bad; } else {")
        for ti, (tag,
                 vals) in enumerate(tabs):
            for i, v in enumerate(vals):
                self.w("                    "
                       "if (d->tables[%d]"
                       % ti)
                self.w("                        "
                       ".values[%d] != "
                       "%d) ++bad;"
                       % (i, v))
        for spec in READERS:
            if spec[2] != d:
                continue
            self.reader_probes(
                spec)
        for spec in INT_FNS:
            if spec[2] != d:
                continue
            self.int_probes(spec)
        self.w("                }")
        self.w("            }")

    def reader_probes(self, spec):
        (fn, stem, dkey, arr,
         kind, pp) = spec
        if kind == "gridstr":
            (an, alo, ahi, bn,
             blo, bhi) = pp
            for a in range(alo,
                           ahi + 1):
                for b in range(
                        blo,
                        bhi + 1):
                    want = \
                        seam_eval_reader(
                            fn, [a, b],
                            self.p,
                            self.rows,
                            self.model)
                    self.w(
                        "                    "
                        "if (std::string("
                        "rules::%s(%d, %d))"
                        % (fn, a, b))
                    self.w(
                        '                        '
                        '!= '
                        '"%s") ++bad;'
                        % _q(want))
            return
        if kind == "reader_name":
            # the wspeed idiom:
            # probe every known
            # name plus one
            # unknown -> 0
            names = self.rows[dkey]
            sf = self.tables[
                (dkey, "sf")]
            self.w(
                "                    "
                "// %d pairs + 1 "
                "unknown"
                % len(names))
            for i, nm in \
                    enumerate(names):
                self.w(
                    "                    "
                    'if (rules::%s("%s")'
                    % (fn, _q(nm)))
                self.w(
                    "                        "
                    "!= %d) ++bad;"
                    % sf[i])
            self.w(
                "                    "
                'if (rules::%s('
                '"no such weapon")'
                % fn)
            self.w(
                "                        "
                "!= 0) ++bad;")
            return
        # reader / reader_null /
        # reader_tern: the full
        # in-range walk
        lo, hi = pp[1], pp[2]
        for a in range(lo,
                       hi + 1):
            want = \
                seam_eval_reader(
                    fn, [a],
                    self.p,
                    self.rows,
                    self.model)
            self.w("                    "
                   "if (std::string("
                   "rules::%s(%d))"
                   % (fn, a))
            self.w('                        '
                   '!= '
                   '"%s") ++bad;'
                   % _q(want))

    def int_probes(self, spec):
        (fn, stem, dkey, tag,
         arr, kind, pp) = spec
        if kind == "band":
            lo, hi = pp
            for a in range(lo,
                           hi + 1):
                want = \
                    seam_eval_int(
                        fn, [a],
                        self.p,
                        self.tables,
                        self.model)
                self.w("                    "
                       "if (rules::%s(%d)"
                       " != %d) ++bad;"
                       % (fn, a,
                          want))
            return
        if kind == "grid2":
            (w, aoff, boff, amin,
             amax, bmin, bmax) = pp
            for a in (amin, amax):
                for b in (bmin,
                          bmax):
                    want = \
                        seam_eval_int(
                            fn, [a, b],
                            self.p,
                            self.tables,
                            self.model)
                    self.w("                    "
                           "if (rules::%s("
                           "%d, %d) != %d)"
                           % (fn, a, b,
                              want))
                    self.w("                        "
                           "++bad;")
            return
        # flat
        vals = self.tables[
            (dkey, tag)]
        n = len(vals)
        for a in range(0, n):
            want = \
                seam_eval_int(
                    fn, [a],
                    self.p,
                    self.tables,
                    self.model)
            self.w("                    "
                   "if (rules::%s(%d)"
                   " != %d) ++bad;"
                   % (fn, a,
                      want))

    # 7. seam: per-def block,
    # each accessor cross-read
    # EXACTLY once, its OWN
    # def block only (the R1054
    # class-13 discipline)
    def sec_seam(self):
        self.w("        // -- 7. seam --"
               "---------------------"
               "-----")
        self.w("        {")
        self.w("            items::"
               "MiscItemRegistry reg;")
        self.w("            reg."
               "loadDirectory(")
        self.w('                "'
               'content/tables/'
               'weapondata");')
        for d in DEFS:
            self.seam_block(d)
        self.w("        }")
        self.guard(len(LABELS) - 2)

    def seam_block(self, d):
        tabs = def_tables(
            d, self.tables)
        tabidx = {tag: i
                  for i, (tag, _)
                  in enumerate(tabs)}
        self.w("            {")
        self.w("                const "
               "items::MiscItemDef* d "
               "=")
        self.w('                    reg'
               '.find("%s");' % d)
        self.w("                if (!d) "
               "{ ++bad; } else {")
        emitted = []
        for spec in INT_FNS:
            if spec[2] != d:
                continue
            (fn, stem, dkey, tag,
             arr, kind, pp) = spec
            vals = self.tables[
                (dkey, tag)]
            ti = tabidx[tag]
            n = len(vals)
            if kind == "band":
                lo = pp[0]
                self.w("                    "
                       "for (int i = 0; "
                       "i < %d; ++i)"
                       % n)
                self.w("                        "
                       "if (rules::%s("
                       "%d + i)"
                       % (fn, lo))
                self.w("                            "
                       "!= (int)d->"
                       "tables[%d]."
                       "values[i])"
                       % ti)
                self.w("                            "
                       "++bad;")
            elif kind == "grid2":
                (wd, aoff, boff, amin,
                 amax, bmin, bmax) = pp
                self.w("                    "
                       "for (int i = 0; "
                       "i < %d; ++i)"
                       % (amax - amin + 1))
                self.w("                        "
                       "for (int j = 0; "
                       "j < %d; ++j)"
                       % (bmax - bmin + 1))
                self.w("                            "
                       "if (rules::%s("
                       "%d + i, %d + j)"
                       % (fn, amin, bmin))
                self.w("                                "
                       "!= (int)d->"
                       "tables[%d]."
                       "values[(i + %d) * %d "
                       "+ (j + %d)])"
                       % (ti,
                          amin - aoff,
                          wd,
                          bmin - boff))
                self.w("                                "
                       "++bad;")
            else:
                idx = _idx_expr(
                    self.p["clamps"]
                    [fn])
                off = 0
                m = re.match(
                    r"(\w+) - (\d+)",
                    idx)
                if m:
                    off = int(
                        m.group(2))
                self.w("                    "
                       "for (int i = 0; "
                       "i < %d; ++i)"
                       % n)
                self.w("                        "
                       "if (rules::%s("
                       "%d + i)"
                       % (fn, off))
                self.w("                            "
                       "!= (int)d->"
                       "tables[%d]."
                       "values[i])"
                       % ti)
                self.w("                            "
                       "++bad;")
            emitted.append(fn)
        for spec in READERS:
            if spec[2] != d:
                continue
            (fn, stem, dkey, arr,
             kind, pp) = spec
            if kind == "gridstr":
                (an, alo, ahi, bn,
                 blo, bhi) = pp
                wdt = bhi - blo + 1
                self.w("                    "
                       "for (int a = 0; "
                       "a < %d; ++a)"
                       % (ahi - alo + 1))
                self.w("                        "
                       "for (int b = 0; "
                       "b < %d; ++b)"
                       % wdt)
                self.w("                            "
                       "if (std::string("
                       "rules::%s("
                       "%d + a, %d + b))"
                       % (fn, alo, blo))
                self.w("                                "
                       "!= d->"
                       "rows[a * %d + b]"
                       ".name)"
                       % wdt)
                self.w("                                "
                       "++bad;")
            elif kind == \
                    "reader_name":
                # name-keyed: the
                # rows ARE the sf
                # order; cross-check
                # the wTable column
                ti = tabidx["sf"]
                self.w("                    "
                       "for (int i = 0; "
                       "i < (int)d->"
                       "rows.size(); "
                       "++i)")
                self.w("                        "
                       'if (rules::%s('
                       "d->rows[i]."
                       "name.c_str())"
                       % fn)
                self.w("                            "
                       "!= (int)d->"
                       "tables[%d]."
                       "values[i])"
                       % ti)
                self.w("                            "
                       "++bad;")
            else:
                lo = pp[1]
                self.w("                    "
                       "for (int i = 0; "
                       "i < (int)d->"
                       "rows.size(); "
                       "++i)")
                self.w("                        "
                       "if (std::string("
                       "rules::%s(%d + "
                       "i))" % (fn, lo))
                self.w("                            "
                       "!= d->"
                       "rows[i].name)")
                self.w("                            "
                       "++bad;")
            emitted.append(fn)
        for fn in emitted:
            self.seam_accessors[
                fn] = \
                self.seam_accessors.get(
                    fn, 0) + 1
        self.w("                }")
        self.w("            }")

    # 8. edges
    def sec_edges(self):
        self.w("        // -- 8. "
               "edges -------------"
               "-----------------")
        self.w("        {")
        self.edge_ints()
        self.edge_readers()
        self.edge_scalars()
        self.edge_cstrs()
        self.edge_logic()
        self.edge_kept_counts()
        self.edge_structs()
        self.w("        }")
        self.guard(len(LABELS) - 1)

    def edge_ints(self):
        for spec in INT_FNS:
            (fn, stem, dkey, tag,
             arr, kind, pp) = spec
            if kind == "band":
                lo, hi = pp
                probes = [lo - 1, lo,
                          hi, hi + 1]
            elif kind == "grid2":
                (w, aoff, boff, amin,
                 amax, bmin,
                 bmax) = pp
                probes = [(amin - 1,
                           bmin),
                          (amax + 1,
                           bmax)]
            else:
                vals = self.tables[
                    (dkey, tag)]
                hi = len(vals) - 1
                probes = [-1, 0,
                          hi + 1]
            for a in probes:
                args = a \
                    if isinstance(
                        a, tuple) \
                    else (a,)
                want = \
                    seam_eval_int(
                        fn, list(args),
                        self.p,
                        self.tables,
                        self.model)
                argtxt = ", ".join(
                    str(x) for x
                    in args)
                self.w("            "
                       "if (rules::%s("
                       "%s) != %d)"
                       % (fn, argtxt,
                          want))
                self.w("                "
                       "++bad;")

    def edge_readers(self):
        for spec in READERS:
            (fn, stem, dkey, arr,
             kind, pp) = spec
            if kind == "gridstr":
                (an, alo, ahi, bn,
                 blo, bhi) = pp
                probes = [(alo - 1,
                           blo),
                          (ahi + 1,
                           bhi + 1)]
            elif kind == \
                    "reader_name":
                # name-keyed: one
                # present, one
                # absent (int
                # compares)
                nm = self.rows[
                    dkey][0]
                sf = self.tables[
                    (dkey, "sf")]
                self.w(
                    "            "
                    'if (rules::'
                    '%s("%s")'
                    % (fn, _q(nm)))
                self.w(
                    "                "
                    "!= %d) ++bad;"
                    % sf[0])
                self.w(
                    "            "
                    'if (rules::'
                    '%s("no such '
                    'weapon")' % fn)
                self.w(
                    "                "
                    "!= 0) ++bad;")
                continue
            else:
                lo, hi = pp[1], pp[2]
                probes = [(lo - 1,),
                          (hi + 1,)]
            for a in probes:
                want = \
                    seam_eval_reader(
                        fn, list(a),
                        self.p,
                        self.rows,
                        self.model)
                argtxt = ", ".join(
                    str(x) for x
                    in a)
                self.w("            "
                       "if (std::string("
                       "rules::%s(%s))"
                       % (fn, argtxt))
                self.w('                '
                       '!= '
                       '"%s") '
                       '++bad;'
                       % _q(want))

    def edge_scalars(self):
        # every zero-arg scalar
        # in the 18 headers,
        # wants from the parse
        for fn in sorted(
                self.p["scalars"]):
            v = self.p["scalars"][fn]
            if isinstance(v, bool):
                self.w("            "
                       "if (rules::"
                       "%s() != %s)"
                       % (fn,
                          "true"
                          if v
                          else
                          "false"))
                self.w("                "
                       "++bad;")
            else:
                self.w("            "
                       "if (rules::"
                       "%s() != %d)"
                       % (fn, v))
                self.w("                "
                       "++bad;")

    def edge_cstrs(self):
        # the zero-arg const
        # char* fns with
        # literal returns
        for fn in sorted(
                self.p["cstrs"]):
            v = self.p["cstrs"][fn]
            self.w("            "
                   "if (std::string("
                   "rules::%s())"
                   % fn)
            self.w('                '
                   '!= '
                   '"%s") '
                   '++bad;'
                   % _q(v))

    def edge_logic(self):
        # the kept 1-arg logic
        # fns the generic model
        # can evaluate; probe
        # args derived from each
        # body; the loop-body
        # count fns and the
        # string-arg fns raise
        # in the model and are
        # covered by
        # edge_kept_counts
        # instead
        for fn in sorted(
                self.fns):
            if fn in RETIRED:
                continue
            stem, ret, args = \
                self.fns[fn]
            if args == "":
                continue
            if "," in args:
                continue
            if "const char*" in args:
                continue
            if "&" in ret:
                continue
            src = self.p["srcs"][
                stem + ".h"]
            body = _strip(
                fn_body(src, fn))
            probes = set()
            for m in re.findall(
                    r"case (\w+):",
                    body):
                v = \
                    self.model.\
                    enumval(m)
                probes.add(
                    int(v) if v
                    is not None
                    else int(m))
            for m in re.findall(
                    r"(\w+) ([<>=!]+) "
                    r"(-?\d+)", body):
                lit = int(m[2])
                probes.update(
                    {lit - 1, lit,
                     lit + 1})
            probes.update(
                {0, 1})
            for a in sorted(
                    probes):
                try:
                    want = \
                        self.model.\
                        call(fn, [a])
                except (ValueError,
                        KeyError):
                    continue
                if isinstance(
                        want, str):
                    self.w("            "
                           "if (std::"
                           "string("
                           "rules::%s("
                           "%d))"
                           % (fn, a))
                    self.w('                '
                           '!= '
                           '"%s") '
                           '++bad;'
                           % _q(want))
                else:
                    if isinstance(
                            want,
                            bool):
                        wtxt = \
                            "true" \
                            if want \
                            else \
                            "false"
                    else:
                        wtxt = \
                            str(want)
                    self.w("            "
                           "if (rules::"
                           "%s(%d) != "
                           "%s)"
                           % (fn, a,
                              wtxt))
                    self.w("                "
                           "++bad;")

    def _struct_of(self, afn):
        for (stem, fn, sname,
             cnt, fields) \
                in KEEP_STRUCTS:
            if fn == afn:
                return (stem, sname,
                        cnt, fields)
        die("struct of " + afn)

    def edge_kept_counts(self):
        # the count fns the
        # model cannot evaluate
        for ent in KEPT_COUNTS:
            kind = ent[0]
            fn = ent[1]
            if kind == "structfield":
                (_, _2, afn,
                 field, cnt) = ent
                (stem, sname, n,
                 fields) = \
                    self._struct_of(
                        afn)
                fi = fields.index(
                    field)
                col = []
                for strs, ints in \
                        self.p[
                            "structs"][
                            afn]:
                    col.append(
                        ints[fi - 1]
                        if fi > 0
                        else None)
                counts = {}
                for v in col:
                    counts[v] = \
                        counts.get(
                            v, 0) + 1
                for v in sorted(
                        counts):
                    self.w("            "
                           "if (rules::%s("
                           "%d) != %d)"
                           % (fn, v,
                              counts[v]))
                    self.w("                "
                           "++bad;")
                self.w("            "
                       "if (rules::%s("
                       "999) != 0)"
                       % fn)
                self.w("                "
                       "++bad;")
            elif kind == "reader":
                (_, _2, rfn,
                 cnt) = ent
                vals = None
                for spec in READERS:
                    if spec[0] == rfn:
                        vals = \
                            self.p[
                                "strs"][
                                rfn]
                        break
                if vals is None:
                    for spec in \
                            INT_FNS:
                        if spec[0] \
                                == rfn:
                            vals = \
                                self.\
                                tables[
                                    (spec[
                                         2],
                                     spec[
                                         3])]
                            break
                counts = {}
                for v in vals:
                    counts[v] = \
                        counts.get(
                            v, 0) + 1
                for v in sorted(
                        counts):
                    self.w("            "
                           "if (rules::%s("
                           "%d) != %d)"
                           % (fn, v,
                              counts[v]))
                    self.w("                "
                           "++bad;")
                self.w("            "
                       "if (rules::%s("
                       "999) != 0)"
                       % fn)
                self.w("                "
                       "++bad;")
            elif kind == "nonnull":
                (_, _2, rfn,
                 cnt) = ent
                names = self.p[
                    "strs"][rfn]
                nn = sum(
                    1 for x in names
                    if x != "")
                self.w("            "
                       "if (rules::%s() "
                       "!= %d) ++bad;"
                       % (fn, nn))
            elif kind == "freq":
                (_, _2, afn) = ent
                (stem, sname, n,
                 fields) = \
                    self._struct_of(
                        afn)
                fi = fields.index(
                    "freq")
                col = []
                for strs, ints in \
                        self.p[
                            "structs"][
                            afn]:
                    col.append(
                        strs[fi])
                counts = {}
                for v in col:
                    counts[v] = \
                        counts.get(
                            v, 0) + 1
                for v in sorted(
                        counts):
                    self.w("            "
                           "if (rules::%s("
                           '"%s") != %d)'
                           % (fn,
                              _q(v),
                              counts[v]))
                    self.w("                "
                           "++bad;")
                self.w("            "
                       'if (rules::%s('
                       '"never") != 0)'
                       % fn)
                self.w("                "
                       "++bad;")

    def edge_structs(self):
        # the seven KEPT struct
        # seams: every field of
        # every row probed
        # against the parse
        for (stem, afn, sname,
             cnt, fields) \
                in KEEP_STRUCTS:
            recs = self.p[
                "structs"][afn]
            nstr = sum(
                1 for f in fields
                if not f.endswith(
                    "Count")
                and f in (
                    "name", "sphere",
                    "head", "body",
                    "color", "days",
                    "freq", "form"))
            for i, rec in \
                    enumerate(recs):
                strs, ints = rec
                si = 0
                ii = 0
                for f in fields:
                    if f in (
                            "name",
                            "sphere",
                            "head",
                            "body",
                            "color",
                            "days",
                            "freq",
                            "form"):
                        self.w(
                            "            "
                            "if (std::"
                            "string("
                            "rules::%s("
                            "%d).%s)"
                            % (afn, i,
                               f))
                        self.w(
                            '                '
                            '!= '
                            '"%s") '
                            '++bad;'
                            % _q(
                                strs[
                                    si]))
                        si += 1
                    else:
                        self.w(
                            "            "
                            "if (rules::"
                            "%s(%d).%s "
                            "!= %d)"
                            % (afn, i,
                               f,
                               ints[
                                   ii]))
                        self.w(
                            "                "
                            "++bad;")
                        ii += 1

    def build(self):
        self.head()
        self.sec_load()
        self.sec_counts()
        self.sec_defs(0, "A")
        self.sec_defs(1, "B")
        self.sec_defs(2, "C")
        self.sec_defs(3, "D")
        self.sec_seam()
        self.sec_edges()
        self.w("    }")
        return "\n".join(
            self.out) + "\n"


# ---- the self-scan ----------------------------

def self_scan(p, tables, rows,
              frag):
    bad = []
    for d in DEFS:
        path = os.path.join(
            ROOT, LUA_DIR,
            d + ".lua")
        if not os.path.exists(
                path):
            bad.append("lua "
                       + d
                       + " missing")
            continue
        t = open(path).read()
        if ('key = "%s"'
                % d) not in t:
            bad.append("lua key "
                       + d)
        if ("value = %d,"
                % len(rows[d])) \
                not in t:
            bad.append("lua rows "
                       + d)
        for tag, vals in \
                def_tables(d,
                           tables):
            if ('name = "%s"'
                    % tag) not in t:
                bad.append("lua table "
                           + d
                           + "/" + tag)
    # the headers: zero
    # static const except the
    # seven KEPT struct seams
    kept_static = {
        "weaponless.h": 3,
        "attacksround.h": 3,
    }
    for f in FILES:
        stem = f.split("/")[-1]
        src = _strip(open(os.path.join(
            ROOT, f)).read())
        found = len(re.findall(
            r"static const ", src))
        want = kept_static.get(
            stem, 0)
        if found != want:
            bad.append(
                "statics in "
                + stem + ": "
                + str(found)
                + " != "
                + str(want))
    # the seam header loads
    # BOTH family dirs
    sh = open(os.path.join(
        ROOT, "rules/seams/",
        "weaponsreg.h")).read()
    for tok in ("wReg()",
                "wRows(",
                "wTable(",
                "weapondata"):
        if tok not in sh:
            bad.append("seam "
                       + tok)
    # the fragment
    for lab in LABELS:
        if ("R1058 weapons "
            "registry %s audit: "
            "bad %%d\\n" % lab) \
                not in frag:
            bad.append("frag "
                       + lab)
    for d in DEFS:
        if ('reg.find('
                '"%s")' % d) \
                not in frag:
            bad.append("frag find "
                       + d)
    for spec in INT_FNS:
        fn = spec[0]
        n = seam_accessors_all.get(
            fn, 0)
        if n != 1:
            bad.append("seam "
                       + fn
                       + " read "
                       + str(n)
                       + "x")
    for spec in READERS:
        fn = spec[0]
        n = seam_accessors_all.get(
            fn, 0)
        if n != 1:
            bad.append("seam "
                       + fn
                       + " read "
                       + str(n)
                       + "x")
    # census
    c = census_count()
    if c != CENSUS_AFTER:
        bad.append("census %d"
                   % c)
    return bad


seam_accessors_all = {}


# ---- main -------------------------------------

def main():
    if not os.path.isfile(
            os.path.join(
                ROOT, REGTEST)):
        die("run me from the "
            "repo root")
    h0 = open(os.path.join(
        ROOT, FILES[0])).read()
    if APPLIED_MARK in h0:
        # the R1057 cascade lesson: an
        # already-spliced tree still
        # needs the KEPT fixups (a v1-
        # spliced tree lacks fragment
        # fixups added in a later tool
        # revision) - the early return
        # must not skip them.
        apply_kept_fixups()
        print("applied 0, "
              "already 9")
        print("SPLICE OK")
        return
    c0 = census_count()
    if c0 != CENSUS_BEFORE:
        die("census %d, want %d"
            % (c0, CENSUS_BEFORE))
    p = parse_pristine()
    enums = parse_enums(
        p["srcs"])
    fns = parse_fns(p["srcs"])
    rows = build_defs(p)
    tables = build_tables(p)
    intmeta = {(s[2], s[3]): s
               for s in INT_FNS}
    for spec in READERS:
        # reader_name: the sf
        # pairs column rides the
        # wTable side channel
        if spec[4] == "reader_name":
            sfv = p["ints"][
                (spec[2], "sf")]
            intmeta[
                (spec[2], "sf")] = (
                spec[0], spec[1],
                spec[2], "sf",
                spec[3], "pairs_sf",
                (0, len(sfv) - 1))
    # the regtest seat
    rt = open(os.path.join(
        ROOT, REGTEST)).read()
    if INC_ANCHOR not in rt:
        die("R1057 include "
            "anchor not found")
    lines = rt.splitlines()
    at = lines.index(
        [l for l in lines
         if INC_ANCHOR in l][0])
    if at != 1305:
        die("R1057 include at "
            "line %d, want 1306"
            % (at + 1))
    rt = rt.replace(
        INC_ANCHOR + "\n",
        INC_ANCHOR + "\n"
        + F_INC + "\n", 1)
    # build
    fe = FE(p, enums, fns,
            rows, tables)
    frag = fe.build()
    global seam_accessors_all
    seam_accessors_all = \
        fe.seam_accessors
    # write
    build_lua(rows, tables,
              intmeta)
    write_seam_header()
    applied = rewrite_headers(
        p, tables)
    apply_kept_fixups()
    open(os.path.join(
        ROOT, FRAG),
        "w").write(frag)
    open(os.path.join(
        ROOT, REGTEST),
        "w").write(rt)
    # self-scan
    bad = self_scan(p, tables,
                    rows, frag)
    if bad:
        for b in bad:
            print("SELF-SCAN "
                  "FAIL: " + b)
        die("self-scan")
    c1 = census_count()
    if c1 != CENSUS_AFTER:
        die("post census %d, "
            "want %d"
            % (c1, CENSUS_AFTER))
    print("census %d -> %d "
          "audit printf "
          "patterns" % (c0, c1))
    print("applied %d headers, "
          "%d lua defs, seam "
          "header, fragment"
          % (applied, len(DEFS)))
    print("SPLICE OK")


def apply_kept_fixups():
    for (path, old, new) \
            in KEPT_FIXUPS:
        full = os.path.join(
            ROOT, path)
        raw = open(full).read()
        if old in raw:
            raw = raw.replace(
                old, new, 1)
            open(full,
                 "w").write(raw)


if __name__ == "__main__":
    main()
