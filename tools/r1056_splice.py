#!/usr/bin/env python3
# r1056_splice.py - the R1056 splice
# tool: the UA classes-family
# de-wire of 13 rules/ua headers
# (68 retiring arrays, 6 kept
# pointer/struct seams).
#
# WHAT IT DOES (run from the repo
# root, idempotent):
#   - parses the 68 retiring static
#     arrays across the 13 headers
#     (band ladders, dex/feet bands,
#     [5][3]/[5][4]/[17][17] grids,
#     the [17][3] search grid, 1-D
#     clamped flats, the ragged
#     switch string lists, the 20
#     string name arrays) plus every
#     kept zero-arg scalar and logic
#     fn (a semantic MODEL, the probe
#     source)
#   - writes content/tables/
#     ua_classes/ as 25 defs, 33
#     tables, every def's rows =
#     its parsed name list (or
#     COMPUTED band/level names);
#     item_offset/roster_offset are
#     COMPUTED prefix-sum tables
#   - rewrites every retiring
#     accessor onto the namespace
#     seam uaReg()/uaRows(key)/
#     uaTable(key,tag); every
#     signature, clamp, guard and
#     branch stays; matrix reads
#     flatten; the fallback is the
#     PARSED guard value per fn
#   - writes rules/audits/
#     r1056_uaclasses_registry.h
#     (SEVEN printf sections, SIX
#     guards, census 1096 -> 1103)
#     and seats its include at
#     regtest.cpp:1305
#
# HARD LESSONS APPLIED (the
# R1049-R1055 ledgers): every want
# computes from the SAME parse that
# writes the lua; probe polarities
# derive from the parsed models;
# NEGATIVE cells end to end; every
# per-def emitted loop is scoped to
# its own def block (the R1054
# class-13 kill); the reader in-range
# probes are arg-aware (R1053 class
# 7); adjacent C string literals
# JOIN (the headers carry "..."
# "..." concatenations); the enum-
# typed returns cast explicitly so
# the fragment compiles at the
# Termux preflight.

import os
import re
import sys

ROOT = os.getcwd()
REGTEST = "regtest.cpp"
LUA_DIR = "content/tables/ua_classes"
FRAG = ("rules/audits/"
        "r1056_uaclasses_registry.h")
APPLIED_MARK = "// R1056 applied"
CENSUS_BEFORE = 1096
CENSUS_AFTER = 1103
INC_ANCHOR = ('    #include "rules/audits/'
              'r1055_subgates_registry.h"'
              '  // R1055')
ROUND = 1056

FILES = [
    "rules/ua/acrobat.h",
    "rules/ua/barbarian.h",
    "rules/ua/cavalier.h",
    "rules/ua/cavmoney.h",
    "rules/ua/hierophant.h",
    "rules/ua/paladin.h",
    "rules/ua/classtables.h",
    "rules/ua/uacavtable.h",
    "rules/ua/uafollowers.h",
    "rules/ua/uaranger.h",
    "rules/ua/uasocialclass.h",
    "rules/ua/uabirth.h",
    "rules/ua/subraces.h",
]

# the def rows: (def key, rows
# source) - "reader:<fn>" = the
# parsed name array of that reader
# fn; "computed:<prefix>:<lo>:<n>"
# = computed names
DEF_ROWS = [
    ("ua_acrobat",
     "reader:acrobatFrozenSkillName"),
    ("ua_acrobat_retained",
     "reader:acrobatRetainedSkillName"),
    ("ua_barbarian",
     "reader:barbarianTertiaryName"),
    ("ua_barbarian_weapons",
     "reader:barbarianRequiredWeaponName"),
    ("ua_cavalier",
     "reader:cavalierPreferredWeaponName"),
    ("ua_cavalier_mind",
     "reader:cavalierMindPowerName"),
    ("ua_cavmoney",
     "reader:cavMoneyStationName"),
    ("ua_cavmoney_entry",
     "reader:cavMoneyStationEntry"),
    ("ua_cavmoney_items",
     "ragged:cavMoneyItemName"),
    ("ua_hierophant",
     "computed:band_:16:8"),
    ("ua_hierophant_conjure",
     "grid:hierophantConjureName"),
    ("ua_hierophant_special",
     "reader:hierophantConjureSpecialName"),
    ("ua_paladin",
     "reader:paladinCavalierAbilityName"),
    ("ua_classtables",
     "reader:acrobatExtraWeaponName"),
    ("ua_cavtable",
     "computed:level_:1:12"),
    ("ua_followers",
     "computed:level_:4:7"),
    ("ua_ranger",
     "reader:uaRangerGiantRosterName"),
    ("ua_ranger_identify",
     "reader:uaRangerTrackIdentifyAbility"),
    ("ua_socialclass",
     "reader:uasocBandFullName"),
    ("ua_socialclass_abbr",
     "reader:uasocBandAbbr"),
    ("ua_socialclass_roster",
     "ragged:uasocRosterName"),
    ("ua_birth",
     "reader:uabirthOrderLabel"),
    ("ua_subrace_prefs",
     "computed:viewer_:1:17"),
    ("ua_subrace_letters",
     "reader:racePrefLetter"),
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
#  search: the [17][3] lookup
#  pref: the [17][17] matrix
INT_FNS = [
    ("acrobatXpToAttain", "acrobat",
     "ua_acrobat", "split_xp", "k",
     "band", (6, 12)),
    ("acrobatExtensionFailurePercent",
     "acrobat", "ua_acrobat",
     "ext_fail", "k", "flat", ()),
    ("acrobatExtensionRecoverySegments",
     "acrobat", "ua_acrobat",
     "ext_recover", "k", "flat", ()),
    ("acrobatFootnoteCarryGp",
     "acrobat", "ua_acrobat",
     "carry_gp", "k", "grid2",
     (3, 1, 0, 1, 5, 0, 2)),
    ("acrobatFallingChanceKnown",
     "acrobat", "ua_acrobat",
     "fall_known", "cells", "search",
     ()),
    ("acrobatDexTightropeBonus",
     "acrobat", "ua_acrobat",
     "dex_tightrope", "k", "dex",
     ()),
    ("acrobatDexPoleVaultBonus",
     "acrobat", "ua_acrobat",
     "dex_vault", "k", "dex", ()),
    ("acrobatDexAttackBonus",
     "acrobat", "ua_acrobat",
     "dex_attack", "k", "dex", ()),
    ("acrobatDexEvasionBonus",
     "acrobat", "ua_acrobat",
     "dex_evasion", "k", "dex", ()),
    ("acrobatDexFallingBonus",
     "acrobat", "ua_acrobat",
     "dex_falling", "k", "dex", ()),
    ("barbarianXpToAttain",
     "barbarian", "ua_barbarian",
     "xp_attain", "k", "band",
     (1, 11)),
    ("barbarianStrikeLevel",
     "barbarian", "ua_barbarian",
     "strike_level", "k", "off1",
     ()),
    ("cavalierXpToAttain",
     "cavalier", "ua_cavalier",
     "xp_attain", "k", "band",
     (1, 12)),
    ("cavalierHorsemanshipLevel",
     "cavalier", "ua_cavalier",
     "horsemanship", "k", "flat",
     ()),
    ("cavMoneyGoldLow", "cavmoney",
     "ua_cavmoney", "gold_low", "k",
     "flat", ()),
    ("cavMoneyGoldHigh", "cavmoney",
     "ua_cavmoney", "gold_high", "k",
     "flat", ()),
    ("cavMoneyDiceCount", "cavmoney",
     "ua_cavmoney", "dice_count", "k",
     "flat", ()),
    ("cavMoneyDiceFaces", "cavmoney",
     "ua_cavmoney", "dice_faces", "k",
     "flat", ()),
    ("cavMoneyDiceBonus", "cavmoney",
     "ua_cavmoney", "dice_bonus", "k",
     "flat", ()),
    ("cavMoneyItemCount", "cavmoney",
     "ua_cavmoney", "item_count", "k",
     "flat", ()),
    ("hierophantXpBandLow",
     "hierophant", "ua_hierophant",
     "xp_band_low", "k", "band",
     (16, 23)),
    ("hierophantConjureLow",
     "hierophant", "ua_hierophant",
     "conjure_low", "lo", "grid2",
     (4, 0, 0, 0, 4, 0, 3)),
    ("hierophantConjureHigh",
     "hierophant", "ua_hierophant",
     "conjure_high", "hi", "grid2",
     (4, 0, 0, 0, 4, 0, 3)),
    ("uacavtLevelXpLow",
     "uacavtable", "ua_cavtable",
     "xp_low", "k", "off1", ()),
    ("uacavtLevelXpHigh",
     "uacavtable", "ua_cavtable",
     "xp_high", "k", "off1", ()),
    ("uafolDiceCount",
     "uafollowers", "ua_followers",
     "dice_count", "k", "band",
     (4, 10)),
    ("uafolEquipRowLo",
     "uafollowers", "ua_followers",
     "equip_lo", "k", "range0", ()),
    ("uafolEquipRowHi",
     "uafollowers", "ua_followers",
     "equip_hi", "k", "range0", ()),
    ("uaRangerTrackTerrainModifier",
     "uaranger", "ua_ranger",
     "terrain_mod", "k", "flat", ()),
    ("uasocBandLow", "uasocialclass",
     "ua_socialclass", "band_low", "k",
     "flat", ()),
    ("uasocBandHigh", "uasocialclass",
     "ua_socialclass", "band_high", "k",
     "flat", ()),
    ("uasocRosterCount",
     "uasocialclass", "ua_socialclass",
     "roster_count", "k", "flat", ()),
    ("uabirthRowLow", "uabirth",
     "ua_birth", "row_low", "k",
     "flat", ()),
    ("uabirthRowHigh", "uabirth",
     "ua_birth", "row_high", "k",
     "flat", ()),
    ("subracePrefers", "subraces",
     "ua_subrace_prefs", "pref_matrix",
     "M", "pref", ()),
]

# the retiring string readers:
# (fn, file stem, def, array name,
# kind, params)
# kinds: reader (1-arg clamp),
# reader_guard (range guard),
# reader2 (2-D [t*W+row]),
# reader_off (ragged via the
# count+offset tables)
READERS = [
    ("acrobatFrozenSkillName",
     "acrobat", "ua_acrobat", "k",
     "reader", ("i", 0, 3)),
    ("acrobatRetainedSkillName",
     "acrobat", "ua_acrobat_retained",
     "k", "reader", ("i", 0, 3)),
    ("barbarianRequiredWeaponName",
     "barbarian", "ua_barbarian_weapons",
     "k", "reader", ("i", 0, 2)),
    ("barbarianTertiaryName",
     "barbarian", "ua_barbarian", "k",
     "reader", ("i", 0, 6)),
    ("cavalierPreferredWeaponName",
     "cavalier", "ua_cavalier", "k",
     "reader", ("i", 0, 10)),
    ("cavalierMindPowerName",
     "cavalier", "ua_cavalier_mind",
     "k", "reader", ("i", 0, 9)),
    ("cavMoneyStationName",
     "cavmoney", "ua_cavmoney", "k",
     "reader", ("i", 0, 5)),
    ("cavMoneyStationEntry",
     "cavmoney", "ua_cavmoney_entry",
     "k", "reader", ("i", 0, 5)),
    ("cavMoneyItemName", "cavmoney",
     "ua_cavmoney_items", "s",
     "reader_off",
     ("ua_cavmoney", "item_count",
      "item_offset", "station", 0, 5,
      "j")),
    ("hierophantConjureName",
     "hierophant",
     "ua_hierophant_conjure", "k",
     "reader2", ("t", 0, 4, "row",
                  0, 3)),
    ("hierophantConjureSpecialName",
     "hierophant", "ua_hierophant_special",
     "k", "reader", ("i", 0, 3)),
    ("paladinCavalierAbilityName",
     "paladin", "ua_paladin", "k",
     "reader", ("i", 0, 4)),
    ("acrobatExtraWeaponName",
     "classtables", "ua_classtables",
     "k", "reader", ("i", 0, 1)),
    ("uaRangerTrackIdentifyAbility",
     "uaranger", "ua_ranger_identify",
     "k", "reader", ("level", 1,
                     10)),
    ("uaRangerGiantRosterName",
     "uaranger", "ua_ranger", "k",
     "reader", ("i", 0, 21)),
    ("uasocBandFullName",
     "uasocialclass", "ua_socialclass",
     "k", "reader", ("i", 0, 8)),
    ("uasocBandAbbr",
     "uasocialclass",
     "ua_socialclass_abbr", "k",
     "reader", ("i", 0, 8)),
    ("uasocRosterName",
     "uasocialclass",
     "ua_socialclass_roster", "r",
     "reader_off",
     ("ua_socialclass", "roster_count",
      "roster_offset", "i", 0, 8,
      "j")),
    ("uabirthOrderLabel", "uabirth",
     "ua_birth", "k", "reader",
     ("i", 0, 12)),
    ("racePrefLetter", "subraces",
     "ua_subrace_letters", "L",
     "reader_guard", ("p", 0, 5)),
]

# the kept pointer-out list fns
# (values probed): (fn, file
# stem, array name, count)
LIST_FNS = [
    ("drowInnateBase", "subraces",
     "B", 3),
    ("drowInnateAt4", "subraces",
     "B", 3),
    ("drowInnateFemale4", "subraces",
     "B", 4),
    ("svirfInnate", "subraces",
     "B", 3),
]

LUA_TITLE = {
    "ua_acrobat":
        "UA thief-acrobat Function "
        "Table and skill pins",
    "ua_acrobat_retained":
        "UA thief-acrobat retained "
        "skill names",
    "ua_barbarian":
        "UA barbarian class tables",
    "ua_barbarian_weapons":
        "UA barbarian required "
        "weapons",
    "ua_cavalier":
        "UA cavalier class tables",
    "ua_cavalier_mind":
        "UA cavalier mind-affecting "
        "power names",
    "ua_cavmoney":
        "UA cavalier starting money "
        "by station",
    "ua_cavmoney_entry":
        "UA cavalier money station "
        "entry labels",
    "ua_cavmoney_items":
        "UA cavalier starting "
        "equipment items",
    "ua_hierophant":
        "UA druid hierophant ladder "
        "and conjure bands",
    "ua_hierophant_conjure":
        "UA hierophant conjuring "
        "table names",
    "ua_hierophant_special":
        "UA hierophant para-"
        "elemental special roster",
    "ua_paladin":
        "UA paladin cavalier "
        "abilities",
    "ua_classtables":
        "UA acrobat extra weapons",
    "ua_cavtable":
        "UA Cavaliers Table I XP "
        "bands",
    "ua_followers":
        "UA cavalier follower dice "
        "and equipment rows",
    "ua_ranger":
        "UA ranger giant-class "
        "roster and tracking",
    "ua_ranger_identify":
        "UA ranger tracking "
        "identification abilities",
    "ua_socialclass":
        "UA social class bands",
    "ua_socialclass_abbr":
        "UA social class "
        "abbreviations",
    "ua_socialclass_roster":
        "UA social class occupation "
        "rosters",
    "ua_birth":
        "UA circumstances-of-birth "
        "table",
    "ua_subrace_prefs":
        "UA racial preferences "
        "matrix",
    "ua_subrace_letters":
        "UA racial preference "
        "letters",
}

GROUPS = {
    "A": ["ua_acrobat",
          "ua_acrobat_retained",
          "ua_barbarian",
          "ua_barbarian_weapons",
          "ua_cavalier",
          "ua_cavalier_mind",
          "ua_cavmoney",
          "ua_cavmoney_entry",
          "ua_cavmoney_items"],
    "B": ["ua_hierophant",
          "ua_hierophant_conjure",
          "ua_hierophant_special",
          "ua_paladin",
          "ua_classtables",
          "ua_cavtable",
          "ua_followers"],
    "C": ["ua_ranger",
          "ua_ranger_identify",
          "ua_socialclass",
          "ua_socialclass_abbr",
          "ua_socialclass_roster",
          "ua_birth",
          "ua_subrace_prefs",
          "ua_subrace_letters"],
}

LABELS = [
    "load", "counts", "defs-A",
    "defs-B", "defs-C", "seam",
    "edges",
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
           r"(?:int|uint8_t) " + name
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
    return out


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
         "grids": {}, "scalars": {},
         "clamps": {}, "args": {}}
    for f in FILES:
        s = srcs[f]
        stem = f.split("/")[-1][:-2]
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
            "rules/ua/" + stem
            + ".h"]
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
            "rules/ua/" + stem
            + ".h"]
        b = fn_body(s, fn)
        p["args"][fn] = _fn_args(s, fn)
        if kind == "reader_off":
            # the ragged switch
            # lists; the counts
            # ride the parent
            # def's table
            counts = p["ints"][
                (pp[0], pp[1])]
            p["strs"][fn] = \
                _ragged_vals(
                    b, arr, counts)
        else:
            n = pp[2] - pp[1] + 1 \
                if kind in ("reader",
                            "reader_guard") \
                else (pp[2] * pp[5]
                      if kind
                      == "reader2"
                      else None)
            if kind == "reader2":
                dims = (pp[2] - pp[1] + 1,
                        pp[5] - pp[4] + 1)
                vals = _str_grid(
                    b, arr, dims)
                p["strs"][fn] = vals
            else:
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
            "rules/ua/" + stem
            + ".h"]
        b = fn_body(s, fn)
        p["lists"][fn] = \
            _str_vals(b, arr, n)
    # the earth elemental rows
    s = srcs["rules/ua/"
             "subraces.h"]
    m = re.search(
        r"static const "
        r"EarthElementalRow "
        r"R\[6\] = \{([\s\S]*?)\};",
        s)
    if not m:
        die("earth rows missing")
    body = m.group(1)
    rows = []
    for rm in re.finditer(
            r'\{\s*(-?\d+),\s*'
            r'(-?\d+),\s*"',
            body):
        lo = int(rm.group(1))
        hi = int(rm.group(2))
        rest = body[rm.end():]
        q = re.match(
            r'((?:[^"\\]|\\.)*)"'
            r'(\s*"((?:[^"\\]|\\.)*)")?'
            r'\s*\}', rest)
        if not q:
            die("earth row strings")
        rows.append((lo, hi,
                     q.group(1)
                     + (q.group(3)
                        or "")))
    if len(rows) != 6:
        die("earth rows "
            + str(len(rows)))
    p["earth"] = rows
    # the struct traits: parse
    # the T[SUBRACE_COUNT]
    # initializer into 17
    # field-tuples
    p["traits"] = \
        _parse_traits(s)
    return p


def _arr_dims(src, body, name):
    m = re.search(
        r"static const "
        r"(?:int|uint8_t) " + name
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
    return out


def _parse_traits(src):
    m = re.search(
        r"static const "
        r"SubRaceTraits "
        r"T\[SUBRACE_COUNT\] = "
        r"\{", src)
    if not m:
        die("traits array")
    seg = src[m.end():]
    # each record spans brace
    # depth 2 (inside the
    # initializer's depth-1
    # outer brace)
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
    if len(recs) != 18:
        die("traits records "
            + str(len(recs)))
    out = []
    for r in recs:
        nums = [int(v) for v in
                re.findall(r"-?\d+",
                           _strip(r))]
        if len(nums) != 29:
            die("traits fields "
                + str(len(nums)))
        out.append(nums)
    return out


def _clamp_lines(body, kind, pp):
    # the EXACT original
    # clamp/guard statements,
    # comments stripped - the
    # new body reuses them
    # verbatim (R1053 class 5)
    lines = []
    for m in re.finditer(
            r"^[ \t]*(if \([^;]*?\)"
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
        stem = f.split("/")[-1][:-2]
        for m in re.finditer(
                r"inline ((?:[\w:\*&]+"
                r"(?:\s+|\s*\*\s*)"
                r")+?)\b(\w+)\("
                r"([\s\S]*?)\)\s*\{",
                src):
            ret, name, args = m.groups()
            if name in ("uaReg", "uaRows",
                        "uaTable"):
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
            "rules/ua/" + stem + ".h"]
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


# the def rows + the computed
# offset tables, all derived
# from the parse
def build_defs(p):
    rows = {}
    for dkey, src in DEF_ROWS:
        if src.startswith("reader:"):
            rows[dkey] = p["strs"][
                src[7:]]
        elif src.startswith("ragged:"):
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
        elif src.startswith("grid:"):
            rows[dkey] = p["strs"][
                src[5:]]
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
    # grid2 flatten, pref
    # matrix flat, plus the
    # computed offset tables
    t = {}
    for (fn, stem, dkey, tag,
         arr, kind, pp) in INT_FNS:
        vals = p["ints"][(dkey, tag)] \
            if (dkey, tag) in p["ints"] \
            else p["ints"][tag]
        t[(dkey, tag)] = vals
    t[("ua_cavmoney", "item_offset")] = \
        prefix_sums(
            t[("ua_cavmoney",
               "item_count")])
    t[("ua_socialclass",
       "roster_offset")] = \
        prefix_sums(
            t[("ua_socialclass",
               "roster_count")])
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
    w("-- The R1056 UA classes-family "
      "de-wire (rules/ua).")
    w("-- " + LUA_TITLE[dkey] + ".")
    w("-- rows[]: the def's row names -"
      " the R1042 equipment rows idiom"
      " (computed names where the print"
      " has no name list).")
    w("-- tables[]: the printed columns;"
      " the accessors live in rules/ua"
      " and keep their clamps.")
    w("-- DO NOT hand-edit: "
      "tools/r1056_splice.py is the "
      "only writer.")
    w("")
    w("return {")
    w("  key = \"%s\"," % dkey)
    w("  name = \"%s\"," % LUA_TITLE[dkey])
    w("  sources = {")
    w("    { part = 0, round = 1056 },")
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
// Adnd1 - rules/ua/uaregistry.h
// The R1056 UA classes-family registry seam.
//
// content/tables/ua_classes/ via
// items::MiscItemRegistry: the R1042
// rows idiom plus named tables per def
// (the R1051 dzTable idiom) and the rows
// readers (the R1051 dzRows idiom). Header-
// only singleton (the R1040 appendixp.h
// idiom). Every accessor in the thirteen
// rules/ua headers keeps its signature,
// clamp and branch; only the array read
// moves behind the registry.
// DO NOT hand-edit: tools/r1056_splice.py
// is the only writer.
// ===========================================================================

#pragma once

#include "items/MiscItemRegistry.h"

namespace rules {

// ---- the R1056 registry seam ---------------

inline items::MiscItemRegistry&
uaReg() {
    static items::MiscItemRegistry
        reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory(
            "content/tables/"
            "ua_classes");
    }
    return reg;
}

// the name rows of one def
inline const std::vector<
    items::MiscItemRow>& uaRows(
        const char* key) {
    static std::map<std::string,
        std::vector<
            items::MiscItemRow>>
        cache;
    auto it = cache.find(key);
    if (it == cache.end()) {
        const items::MiscItemDef*
            d = uaReg().find(key);
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
    long>* uaTable(const char* key,
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
            d = uaReg().find(key);
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

}  // namespace rules
"""


def write_seam_header():
    path = os.path.join(
        ROOT, "rules/ua/",
        "uaregistry.h")
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
    a("    const auto* g = uaTable(")
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
    if kind == "reader_guard":
        a("    const auto& rows = "
          "uaRows(\"%s\");" % dkey)
        a("    if (rows.empty())")
        a("        return \"?\";")
        # the parsed ternary with
        # the array read swapped
        t = clamps[-1]
        t = re.sub(r"\b\w+\[p\]",
                   "rows[p].name"
                   ".c_str()", t)
        a("    " + t)
        return "\n".join(out)
    if kind == "reader_off":
        parent, cnttag, offtag, \
            arg1, lo1, hi1, arg2 = pp
        a("    const auto& rows = "
          "uaRows(\"%s\");" % dkey)
        a("    const auto* cnt = "
          "uaTable(\"%s\","
          % parent)
        a("        \"%s\");" % cnttag)
        a("    const auto* off = "
          "uaTable(\"%s\","
          % parent)
        a("        \"%s\");" % offtag)
        a("    if (rows.empty()"
          " || !cnt || !off)")
        a("        return \"\";")
        for g in clamps[:-1]:
            # a per-case clamp
            # (`if (j > N)`) was
            # station-conditional
            # inside the switch:
            # flattened it would
            # over-clamp - the
            # count-based clamp
            # below subsumes it
            if arg2 + " >" in g:
                continue
            if ("switch" in g
                    or "case" in g):
                continue
            if not g.startswith("if "):
                continue
            a("    " + g)
        a("    int c = (int)"
          "(*cnt)[%s];" % arg1)
        a("    if (%s >= c)" % arg2)
        a("        %s = c - 1;" % arg2)
        a("    return rows[(int)"
          "(*off)[%s]" % arg1)
        a("        + %s].name"
          ".c_str();" % arg2)
        return "\n".join(out)
    a("    const auto& rows = "
      "uaRows(\"%s\");" % dkey)
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
                  + "\n#include \"rules/ua/"
                  "uaregistry.h\"\n")
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
            "rules/ua/" + spec[1]
            + ".h",
            []).append(("int", spec))
    for spec in READERS:
        by_file.setdefault(
            "rules/ua/" + spec[1]
            + ".h",
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
    if kind == "reader_guard":
        # the ternary: p in
        # PREF_P..PREF_H
        if args[0] < 0 \
                or args[0] > 5:
            return "?"
        return rows[dkey][args[0]]
    if kind == "reader_off":
        (parent, cnttag, offtag,
         arg1, lo1, hi1, arg2) = pp
        counts = tables_get(
            p, (parent, cnttag))
        offs = tables_get(
            p, (parent, offtag))
        a = max(lo1, min(hi1,
                         args[0]))
        c = counts[a]
        j = max(0, args[1])
        if j >= c:
            j = c - 1
        return rows[dkey][
            offs[a] + j]
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
         'r1056_uaclasses_registry.h"'
         '  // R1056')


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
        self.w("    // ==== R1056: "
               "uaclasses registry "
               "==========")
        self.w("    // The R1056 "
               "de-wire: the 68 "
               "retiring static")
        self.w("    // arrays of the "
               "thirteen rules/ua "
               "CLASSES-family")
        self.w("    // headers ride "
               "items::MiscItemRegistry "
               "from")
        self.w("    // content/tables/"
               "ua_classes/ - 24 defs, "
               "37 tables, 20")
        self.w("    // rows readers; "
               "the six subraces.h "
               "struct/pointer")
        self.w("    // seams stay C++, "
               "probed here. Seven")
        self.w("    // sections: load, "
               "counts, defs-A/B/C, "
               "seam,")
        self.w("    // edges. Census "
               "1096 -> 1103. DO NOT "
               "hand-edit:")
        self.w("    // tools/"
               "r1056_splice.py is "
               "the only writer.")
        self.w("    {")
        self.w("        int bad = 0;")

    def guard(self, idx):
        self.w('        printf('
               '"R1056 uaclasses '
               'registry %s audit: '
               'bad %%d\\n", bad);'
               % LABELS[idx])
        if idx < 6:
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
        self.w('                '
               '"content/tables/'
               'ua_classes");')
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
        self.w('                '
               '"content/tables/'
               'ua_classes");')
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
        # the per-def row name
        # probes, scoped INSIDE
        # this def's own block
        for i, nm in enumerate(
                self.rows[d]):
            self.w('                    if '
                   '(d->rows[%d].name'
                   % i)
            self.w('                        != '
                   '"%s") ++bad;'
                   % _q(nm))
        self.w("                }")
        self.w("            }")

    # 3-5. defs groups
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
        self.w('                '
               '"content/tables/'
               'ua_classes");')
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
        # every cell of every
        # int table vs the parse
        for ti, (tag,
                 vals) in enumerate(tabs):
            if (d, tag) in (
                    ("ua_cavmoney",
                     "item_offset"),
                    ("ua_socialclass",
                     "roster_offset")):
                # the COMPUTED
                # offset tables pin
                # by their walks
                # below; per-cell
                # wants ride the
                # offset reader
                # probes
                continue
            for i, v in enumerate(vals):
                self.w("                    "
                       "if (d->tables[%d]"
                       % ti)
                self.w("                        "
                       ".values[%d] != "
                       "%d) ++bad;"
                       % (i, v))
        # the readers of this
        # def: the in-range
        # arg-aware probes
        for spec in READERS:
            if spec[2] != d:
                continue
            self.reader_probes(
                spec)
        # the int accessors of
        # this def: in-range
        # probes
        for spec in INT_FNS:
            if spec[2] != d:
                continue
            self.int_probes(spec)
        self.w("                }")
        self.w("            }")

    def reader_probes(self, spec):
        (fn, stem, dkey, arr,
         kind, pp) = spec
        names = [x.split()[-1]
                 .strip("&")
                 .strip("[]")
                 for x in
                 self.model.args_of(fn)]
        lst = self.rows[dkey]
        if kind == "reader":
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
                self.w('                        != '
                       '"%s") ++bad;'
                       % _q(want))
        elif kind == "reader2":
            for t in range(pp[1],
                           pp[2] + 1):
                for row in range(
                        pp[4],
                        pp[5] + 1):
                    want = \
                        seam_eval_reader(
                            fn, [t, row],
                            self.p,
                            self.rows,
                            self.model)
                    self.w(" "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           "if (std::"
                           "string(rules::"
                           "%s(%d, %d))"
                           % (fn, t,
                              row))
                    self.w(' '
                           ' '
                           ' '
                           ' '
                           ' '
                           ' '
                           ' '
                           ' '
                           ' '
                           ' != '
                           '"%s") '
                           '++bad;'
                           % _q(want))

    def int_probes(self, spec):
        (fn, stem, dkey, tag,
         arr, kind, pp) = spec
        if kind == "search":
            vals = self.tables[
                (dkey, tag)]
            for i in range(17):
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "if (rules::%s("
                       "%d, %d) != %d)"
                       % (fn,
                          vals[i * 3],
                          vals[i * 3
                          + 1],
                          vals[i * 3
                          + 2]))
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "++bad;")
            return
        if kind == "pref":
            vals = self.tables[
                (dkey, tag)]
            for v in range(1, 18):
                for vd in (2, 10):
                    want = \
                        seam_eval_int(
                            fn, [v, vd],
                            self.p,
                            self.tables,
                            self.model)
                    self.w(" "
                           "if (rules::"
                           "%s(("
                           "rules::"
                           "CharSubRace)"
                           "%d, (rules::"
                           "CharSubRace)"
                           "%d) != %d)"
                           % (fn, v,
                              vd,
                              want))
                    self.w(" "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           "++bad;")
            return
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
                self.w(" "
                       " "
                       " "
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
                    self.w(" "
                           " "
                           "if (rules::%s("
                           "%d, %d) != %d)"
                           % (fn, a, b,
                              want))
                    self.w(" "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           "++bad;")
            return
        # flat / off1 / dex /
        # range0
        idx = _idx_expr(
            self.p["clamps"][fn])
        vals = self.tables[
            (dkey, tag)]
        n = len(vals)
        lo = 0
        m = re.search(
            r"if \((\w+) > "
            r"(-?\d+)\)",
            " ".join(
                self.p["clamps"]
                [fn]))
        hi = int(m.group(2)) \
            if m else n - 1
        for a in range(lo,
                       hi + 1):
            want = \
                seam_eval_int(
                    fn, [a],
                    self.p,
                    self.tables,
                    self.model)
            self.w(" "
                   " "
                   " "
                   " "
                   " "
                   "if (rules::%s(%d)"
                   " != %d) ++bad;"
                   % (fn, a, want))

    # 6. seam: per-def block,
    # each accessor cross-read
    # EXACTLY once, its OWN
    # def block only (the R1054
    # class-13 discipline)
    def sec_seam(self):
        self.w("        // -- 6. seam --"
               "---------------------"
               "-----")
        self.w("        {")
        self.w("            items::"
               "MiscItemRegistry reg;")
        self.w("            reg."
               "loadDirectory(")
        self.w('                '
               '"content/tables/'
               'ua_classes");')
        for d in DEFS:
            self.seam_block(d)
        self.w("        }")
        self.guard(5)

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
            if kind == "search":
                vals = self.tables[
                    (dkey, tag)]
                ti = tabidx[tag]
                self.w(" "
                       " "
                       "for (int i = 0; "
                       "i < 17; ++i) {")
                self.w(" "
                       " "
                       " "
                       " "
                       "int got = rules::"
                       "%s("
                       % fn)
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "(int)d->"
                       "tables[%d]."
                       "values[i * 3],"
                       % ti)
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "(int)d->"
                       "tables[%d]."
                       "values[i * 3 "
                       "+ 1]);"
                       % ti)
                self.w(" "
                       " "
                       " "
                       " "
                       "if (got != "
                       "(int)d->"
                       "tables[%d]."
                       "values[i * 3 "
                       "+ 2])"
                       % ti)
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "++bad;")
                self.w(" "
                       " "
                       " "
                       "}")
                emitted.append(fn)
                continue
            if kind == "pref":
                ti = tabidx[tag]
                self.w(" "
                       " "
                       "for (int v = 1; "
                       "v <= 17; ++v)")
                self.w(" "
                       " "
                       " "
                       "for (int vd = 1; "
                       "vd <= 17; ++vd)")
                self.w(" "
                       " "
                       " "
                       " "
                       "if ((int)"
                       "rules::%s("
                       % fn)
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "(rules::"
                       "CharSubRace)v,")
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "(rules::"
                       "CharSubRace)"
                       "vd)")
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "!= "
                       "(int)d->"
                       "tables[%d]."
                       "values["
                       % ti)
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "(v - 1) * 17 "
                       "+ vd - 1])")
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "++bad;")
                emitted.append(fn)
                continue
            vals = self.tables[
                (dkey, tag)]
            ti = tabidx[tag]
            n = len(vals)
            if kind == "band":
                lo = pp[0]
                self.w(" "
                       " "
                       " "
                       "for (int i = 0; "
                       "i < %d; ++i)"
                       % n)
                self.w(" "
                       " "
                       " "
                       " "
                       "if (rules::%s("
                       "%d + i)"
                       % (fn, lo))
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "!= (int)d->"
                       "tables[%d]."
                       "values[i])"
                       % ti)
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "++bad;")
            elif kind == "grid2":
                (wd, aoff, boff, amin,
                 amax, bmin, bmax) = pp
                self.w(" "
                       "for (int i = 0; "
                       "i < %d; ++i)"
                       % (amax - amin + 1))
                self.w(" "
                       "for (int j = 0; "
                       "j < %d; ++j)"
                       % (bmax - bmin + 1))
                self.w(" "
                       "if (rules::%s("
                       "%d + i, %d + j)"
                       % (fn, amin, bmin))
                self.w(" "
                       "!= (int)d->"
                       "tables[%d]."
                       "values[(i + %d) * %d "
                       "+ (j + %d)])"
                       % (ti,
                          amin - aoff,
                          wd,
                          bmin - boff))
                self.w(" "
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
                self.w(" "
                       " "
                       " "
                       "for (int i = 0; "
                       "i < %d; ++i)"
                       % n)
                self.w(" "
                       " "
                       " "
                       " "
                       "if (rules::%s("
                       "%d + i)"
                       % (fn, off))
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "!= (int)d->"
                       "tables[%d]."
                       "values[i])"
                       % ti)
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "++bad;")
            emitted.append(fn)
        for spec in READERS:
            if spec[2] != d:
                continue
            (fn, stem, dkey, arr,
             kind, pp) = spec
            lst = self.rows[dkey]
            if kind == "reader":
                lo = pp[1]
                self.w(" "
                       " "
                       " "
                       "for (int i = 0; "
                       "i < (int)d->"
                       "rows.size(); "
                       "++i)")
                self.w(" "
                       " "
                       " "
                       " "
                       "if (std::string("
                       "rules::%s(%d + "
                       "i))" % (fn, lo))
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "!= d->"
                       "rows[i].name)")
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "++bad;")
            emitted.append(fn)
        for fn in emitted:
            self.seam_accessors[
                fn] = \
                self.seam_accessors.get(
                    fn, 0) + 1
        self.w("                }")
        self.w("            }")

    # 7. edges
    def sec_edges(self):
        self.w("        // -- 7. "
               "edges -------------"
               "-----------------")
        self.w("        {")
        self.edge_ints()
        self.edge_readers()
        self.edge_scalars()
        self.edge_logic()
        self.edge_lists()
        self.edge_structs()
        self.w("        }")
        self.guard(6)

    def edge_ints(self):
        for spec in INT_FNS:
            (fn, stem, dkey, tag,
             arr, kind, pp) = spec
            if kind == "band":
                lo, hi = pp
                probes = [lo - 1, lo,
                          hi, hi + 1]
            elif kind == "dex":
                probes = [15, 16, 19,
                          20]
            elif kind == "flat":
                probes = [-1, 0]
            elif kind == "off1":
                probes = [0, 1]
            elif kind == "range0":
                probes = [-1, 0]
            elif kind == "grid2":
                (w, aoff, boff, amin,
                 amax, bmin,
                 bmax) = pp
                probes = [(amin - 1,
                           bmin),
                          (amax + 1,
                           bmax)]
            elif kind == "search":
                vals = self.tables[
                    (dkey, tag)]
                # a guaranteed MISS
                # pair: (vals[0]+1,
                # vals[1]) can collide
                # with a real row (the
                # R1056 falling table);
                # walk candidates until
                # one is absent
                pairs = set()
                for i in range(
                        len(vals) // 3):
                    pairs.add(
                        (vals[i * 3],
                         vals[i * 3
                         + 1]))
                a0, b0 = \
                    vals[0], vals[1]
                probe = None
                for cand in (
                        (a0 + 1, b0 + 1),
                        (a0 + 1, b0 - 1),
                        (a0 + 2, b0),
                        (a0 - 1, b0)):
                    if cand \
                            not in pairs:
                        probe = cand
                        break
                if probe is None:
                    die("search edge"
                        " probe: " + fn)
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "if (rules::%s("
                       "%d, %d) != -1)"
                       % (fn,
                          probe[0],
                          probe[1]))
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "++bad;")
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "if (rules::%s("
                       "999, 999) != -1)"
                       % fn)
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "++bad;")
                continue
            elif kind == "pref":
                for (v, vd) in ((0, 1),
                                (1, 0),
                                (18, 1),
                                (1, 18)):
                    self.w(" "
                           " "
                           " "
                           " "
                           "if ((int)"
                           "rules::%s("
                           % fn)
                    self.w(" "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           "(rules::"
                           "CharSubRace)"
                           "%d," % v)
                    self.w(" "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           "(rules::"
                           "CharSubRace)"
                           "%d) != 3)"
                           % vd)
                    self.w(" "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           "++bad;")
                continue
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
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "if (rules::%s("
                       "%s) != %d)"
                       % (fn, argtxt,
                          want))
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "++bad;")

    def edge_readers(self):
        for spec in READERS:
            (fn, stem, dkey, arr,
             kind, pp) = spec
            lst = self.rows[dkey]
            if kind == "reader":
                lo, hi = pp[1], pp[2]
                probes = [(lo - 1,),
                          (hi + 1,)]
            elif kind == "reader2":
                probes = [(pp[1] - 1,
                           pp[4] - 1),
                          (pp[2] + 1,
                           pp[5] + 1)]
            elif kind == \
                    "reader_guard":
                for a in (-1, 6):
                    self.w(" "
                           " "
                           " "
                           " "
                           " "
                           " "
                           "if (std::"
                           "string("
                           "rules::%s("
                           "%s))"
                           % (fn,
                              self.
                              enum_call_args(
                                  fn,
                                  [a])))
                    self.w(' '
                           ' '
                           ' '
                           ' '
                           ' '
                           ' '
                           ' '
                           ' '
                           ' '
                           ' != '
                           '"?") '
                           '++bad;')
                continue
            else:
                probes = [(-1, 0),
                          (pp[5], 99)]
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
                self.w(" "
                       " "
                       " "
                       " "
                       "if (std::string("
                       "rules::%s(%s))"
                       % (fn, argtxt))
                self.w(' '
                       ' '
                       ' '
                       ' '
                       ' '
                       ' '
                       ' '
                       ' != '
                       '"%s") '
                       '++bad;'
                       % _q(want))

    def edge_scalars(self):
        # every zero-arg scalar
        # in the 13 headers,
        # wants from the parse
        for fn in sorted(
                self.p["scalars"]):
            v = self.p["scalars"][fn]
            if isinstance(v, bool):
                self.w(" "
                       " "
                       " "
                       " "
                       "if (rules::"
                       "%s() != %s)"
                       % (fn,
                          "true"
                          if v
                          else
                          "false"))
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "++bad;")
            else:
                self.w(" "
                       " "
                       " "
                       " "
                       "if (rules::"
                       "%s() != %d)"
                       % (fn, v))
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "++bad;")

    def enum_call_args(self, fn,
                       args):
        # render probe args,
        # enum-typed where the
        # arg type is an enum
        out = []
        for (decl, val) in \
                zip(self.model.
                    args_of(fn),
                    args):
            ty = decl.split()[0] \
                .strip("&")
            if ty in self.enums:
                # ALWAYS the
                # numeric cast -
                # the enumerator
                # NAME (e.g.
                # SUB_DWARF_GRAY)
                # is not declared
                # in the regtest
                # TU (Curtiss's
                # second preflight
                # caught the name
                # form: 20
                # undeclared-
                # identifier
                # errors); the
                # int cast is
                # always in scope
                out.append(
                    "(rules::%s)"
                    "%d" % (ty,
                            val))
                continue
            else:
                out.append(
                    str(val))
        return ", ".join(out)

    def edge_logic(self):
        # the kept logic fns:
        # probe args derived
        # from each body (case
        # labels + boundary
        # literals); wants via
        # the generic model
        for fn in sorted(
                self.fns):
            if fn in RETIRED:
                continue
            stem, ret, args = \
                self.fns[fn]
            if args == "":
                continue
            if "const char**&" \
                    in args:
                continue
            if "SubRaceTraits&" \
                    in ret or \
                    ret.endswith(
                        "EarthElemental"
                        "Row*"):
                continue
            # multi-arg logic fns
            # cannot take a
            # single-arg probe
            # (the R1056 woc
            # collision): skip
            if "," in args:
                continue
            src = self.p["srcs"][
                "rules/ua/" + stem
                + ".h"]
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
            retc = ret.split()[-1]
            for a in sorted(
                    probes):
                try:
                    want = \
                        self.model.\
                        call(fn, [a])
                except (ValueError,
                        KeyError):
                    continue
                # classify by the
                # MODEL's VALUE, not
                # ret.split()[-1]
                # (which is "char*"
                # for a const char*
                # fn - the unquoted-
                # want bug Curtiss's
                # preflight caught)
                if isinstance(
                        want, str):
                    self.w(" "
                           " "
                           " "
                           " "
                           "if (std::"
                           "string("
                           "rules::%s("
                           "%s))"
                           % (fn,
                              self.
                              enum_call_args(
                                  fn,
                                  [a])))
                    self.w(' '
                           ' '
                           ' '
                           ' '
                           ' '
                           ' '
                           ' '
                           ' != '
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
                    self.w(" "
                           " "
                           " "
                           " "
                           "if (rules::"
                           "%s(%s) != "
                           "%s)"
                           % (fn,
                              self.
                              enum_call_args(
                                  fn,
                                  [a]),
                              wtxt))
                    self.w(" "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           "++bad;")

    def edge_lists(self):
        for (fn, stem, arr,
             n) in LIST_FNS:
            lst = self.p["lists"][fn]
            # each pointer-out
            # probe group gets
            # its OWN brace
            # block: L/n
            # redeclared at the
            # same scope is a
            # compile error
            # (Curtiss's third
            # preflight: 6
            # redefinition
            # errors)
            self.w("{")
            self.w(" "
                   " "
                   " "
                   " "
                   " "
                   " "
                   " "
                   " "
                   " "
                   " "
                   " "
                   "const char** L "
                   "= nullptr;")
            self.w(" "
                   " "
                   " "
                   " "
                   " "
                   " "
                   " "
                   " "
                   " "
                   " "
                   " "
                   " "
                   "int n = rules::"
                   "%s(L);"
                   % fn)
            self.w(" "
                   " "
                   " "
                   " "
                   " "
                   " "
                   " "
                   " "
                   " "
                   " "
                   " "
                   " "
                   "if (n != %d) "
                   "++bad;" % n)
            for i, want in \
                    enumerate(lst):
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "if (std::"
                       "string(L[%d])"
                       % i)
                self.w(' '
                       ' '
                       ' '
                       ' '
                       ' '
                       ' '
                       ' '
                       ' '
                       ' != '
                       '"%s") '
                       '++bad;'
                       % _q(want))
            self.w("}")

    def edge_structs(self):
        # the traits: probe all
        # nonzero fields per
        # sub-race + full probes
        # on the three deep
        # strains
        self.w(" "
               " "
               " "
               "for (int s = 0; "
               "s < 18; ++s) {")
        self.w(" "
               " "
               " "
               " "
               "const rules::"
               "SubRaceTraits& t "
               "=")
        self.w(" "
               " "
               " "
               " "
               " "
               " "
               " "
               " "
               " "
               " "
               " "
               "rules::"
               "subraceTraits("
               "(rules::"
               "CharSubRace)s);")
        full = {1, 4, 10}
        fields = TRAIT_FIELDS
        for s, rec in enumerate(
                self.p["traits"]):
            adj = rec[:6]
            mx = rec[6:12]
            scal = rec[12:]
            if s in full:
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       "if (s == %d) {"
                       % s)
                for j, v in \
                        enumerate(
                            adj):
                    self.w(" "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           "if (t.adj"
                           "[%d] != %d)"
                           % (j, v))
                    self.w(" "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           "++bad;")
                for j, v in \
                        enumerate(mx):
                    self.w(" "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           "if (t.max"
                           "[%d] != %d)"
                           % (j, v))
                    self.w(" "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           "++bad;")
                for fname, v in \
                        zip(fields,
                            scal):
                    self.w(" "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           "if (t.%s "
                           "!= %d)"
                           % (fname,
                              v))
                    self.w(" "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           " "
                           "++bad;")
                self.w(" "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " "
                       " }")
            else:
                for j, v in \
                        enumerate(
                            adj):
                    if v:
                        self.w(" "
                               " "
                               "if (s "
                               "== %d "
                               "&& t.adj"
                               "[%d] != "
                               "%d)"
                               % (s, j,
                                  v))
                        self.w(" "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               "++bad;")
                for j, v in \
                        enumerate(mx):
                    if v:
                        self.w(" "
                               "if (s "
                               "== %d "
                               "&& t.max"
                               "[%d] != "
                               "%d)"
                               % (s, j,
                                  v))
                        self.w(" "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               "++bad;")
                for fname, v in \
                        zip(fields,
                            scal):
                    if v:
                        self.w(" "
                               "if (s "
                               "== %d "
                               "&& t.%s"
                               " != %d)"
                               % (s,
                                  fname,
                                  v))
                        self.w(" "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               " "
                               "++bad;")
        self.w(" "
               " "
               " "
               "}")
        # the earth rows
        self.w(" "
               " "
               " "
               " "
               " "
               " "
               " "
               " "
               " "
               "int en = 0;")
        self.w(" "
               " "
               " "
               " "
               " "
               " "
               " "
               " "
               " "
               "const rules::"
               "EarthElementalRow* R "
               "=")
        self.w(" "
               " "
               " "
               " "
               " "
               " "
               " "
               " "
               " "
               " "
               " "
               "rules::"
               "svirfEarthElemental"
               "Table(en);")
        self.w(" "
               " "
               " "
               " "
               " "
               " "
               " "
               " "
               "if (en != 6) "
               "++bad;")
        for i, (lo, hi,
                res) in enumerate(
                    self.p["earth"]):
            self.w(" "
                   " "
                   " "
                   " "
                   " "
                   "if (R[%d].lo "
                   "!= %d || R[%d].hi "
                   "!= %d)"
                   % (i, lo, i, hi))
            self.w(" "
                   " "
                   " "
                   " "
                   " "
                   " "
                   " "
                   " "
                   " "
                   " "
                   " "
                   " "
                   " "
                   "++bad;")
            self.w(" "
                   " "
                   " "
                   " "
                   " "
                   "if (std::"
                   "string(R[%d]"
                   ".result)"
                   % i)
            self.w(' '
                   ' '
                   ' '
                   ' '
                   ' '
                   ' '
                   ' '
                   ' != '
                   '"%s") '
                   '++bad;'
                   % _q(res))

    def build(self):
        self.head()
        self.sec_load()
        self.sec_counts()
        self.sec_defs(0, "A")
        self.sec_defs(1, "B")
        self.sec_defs(2, "C")
        self.sec_seam()
        self.sec_edges()
        self.w("    }")
        return "\n".join(
            self.out) + "\n"


TRAIT_FIELDS = [
    "infravisionFeet",
    "saveVsMagicBonus",
    "saveVsPoisonBonus",
    "saveOtherBonus",
    "illusionImmune",
    "paralysisImmune",
    "magicPoisonImmune",
    "surpriseOn",
    "surpriseDie",
    "surprisedOn",
    "surprisedDie",
    "moveFemale",
    "moveMale",
    "twoWeaponFree",
    "losesSwordBowBonus",
    "maleOnlyPC",
    "noPsionics",
]


# ---- the self-scan ----------------------------

def self_scan(p, tables, rows,
              frag):
    bad = []
    # the lua files
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
    # six kept subraces seams
    for f in FILES:
        src = open(os.path.join(
            ROOT, f)).read()
        kept = 0
        for m in re.finditer(
                r"static const "
                r"[\w\* ]+[\w\[]"
                r"[^\n]*=", src):
            if "subraces.h" \
                    in f:
                kept += 1
            else:
                bad.append(
                    "static const in "
                    + f + ": "
                    + m.group(0)[:40])
        if f.endswith(
                "subraces.h") \
                and kept != 6:
            bad.append("subraces "
                       "kept decls "
                       + str(kept))
    # the seam header
    sh = open(os.path.join(
        ROOT, "rules/ua/",
        "uaregistry.h")).read()
    for tok in ("uaReg()",
                "uaRows(",
                "uaTable(",
                "ua_classes"):
        if tok not in sh:
            bad.append("seam "
                       + tok)
    # the fragment
    for lab in LABELS:
        if ("R1056 uaclasses "
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
    # every retiring accessor
    # is read exactly once in
    # the seam section, inside
    # its own def block
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
    os.chdir(ROOT) \
        if False else None
    if not os.path.isfile(
            os.path.join(
                ROOT, REGTEST)):
        die("run me from the "
            "repo root")
    h0 = open(os.path.join(
        ROOT, FILES[0])).read()
    if APPLIED_MARK in h0:
        print("applied 0, "
              "already 13")
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
    # the regtest seat
    rt = open(os.path.join(
        ROOT, REGTEST)).read()
    if INC_ANCHOR not in rt:
        die("R1055 include "
            "anchor not found")
    lines = rt.splitlines()
    at = lines.index(
        [l for l in lines
         if INC_ANCHOR in l][0])
    if at != 1303:
        die("R1055 include at "
            "line %d, want 1304"
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
    for spec in READERS:
        if spec[4] == "reader2" \
                or True:
            pass
    # write
    build_lua(rows, tables,
              intmeta)
    write_seam_header()
    applied = rewrite_headers(
        p, tables)
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
          "24 lua defs, seam "
          "header, fragment"
          % applied)
    print("SPLICE OK")


if __name__ == "__main__":
    main()
