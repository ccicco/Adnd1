#!/usr/bin/env python3
# r1051_splice.py - the R1051 splice
# tool: the DMG pp.13-14 disease and
# parasitic infestation table de-wire
# of rules/dmg/disease.h.
#
# WHAT IT DOES (run from the repo
# root, idempotent):
#   - parses the 12 hard-coded arrays
#     of disease.h (2 string name
#     arrays, 9 int band/column arrays,
#     1 DiseaseDurationUnit enum array)
#   - writes content/tables/dm_disease/
#     as 2 defs (dm_disease_areas: 16
#     name ROWS + 6 tables; dm_parasite_
#     areas: 6 name rows + 4 tables) -
#     the R1042 equipment rows idiom
#     (name the string, band the row
#     index) plus named tables per def
#   - rewrites the 12 accessors onto a
#     namespace-rules seam: dzReg() /
#     dzRows(key) / dzTable(key, tag);
#     every signature and clamp stays
#   - writes rules/audits/
#     r1051_disease_registry.h at the
#     R1041+ in-function seat (the R1048
#     block idiom, six printf sections,
#     census 1064 -> 1070) and seats its
#     include at regtest.cpp:1300
#
# HARD LESSONS APPLIED (the R1049 +
# R1050 ledgers): every want is
# computed from the SAME parse that
# writes the lua; every dim, clamp,
# tag and probe comes off the parse
# (never hardcoded); enum members
# parse NAME-FIRST (R1050 class 1);
# the seam index/clamp expressions
# are re-verified against the parsed
# signature names (R1050 class 2);
# the tool SELF-SCANS its own emitted
# fragment and seam before writing;
# the wrapper refuses to split a
# line carrying a string literal
# (R1050 class 4); labels are
# pre-shaped to fit 78 on ONE line
# so the census pattern can never
# split.

import os
import re
import sys

ROOT = os.getcwd()
HEAD = "rules/dmg/disease.h"
LUA_DIR = "content/tables/dm_disease"
FRAG = ("rules/audits/"
        "r1051_disease_registry.h")
REGTEST = "regtest.cpp"
APPLIED_MARK = "// R1051 applied"
INC_LINE = ('    #include "rules/audits/'
            'r1051_disease_registry.h"'
            '  // R1051')
CENSUS_BEFORE = 1064
CENSUS_AFTER = 1070
MARKER = "R1051 disease registry"
INC_ANCHOR = ("    #include \"rules/audits/"
              "r1050_dm_movement_"
              "registry.h\"  // R1050")
DUR_ENUM = "DiseaseDurationUnit"

# The two defs: which functions feed
# which rows/tables. Every table is
# (tag, accessor); the enum accessor
# carries its enum type.
DEFS = [
    {"key": "dm_disease_areas",
     "pfx": "Dz",
     "title": ("DMG p.14 disease "
               "table (16 areas)"),
     "name_fn": "diseaseAreaName",
     "count_fn": "diseaseAreaCount",
     "d100_fn": "diseaseAreaForD100",
     "tables": [
         ("acute_hi",
          "diseaseAcuteHi", None),
         ("sev_mild_hi",
          "diseaseSeverityMildHi",
          None),
         ("sev_severe_hi",
          "diseaseSeveritySevereHi",
          None),
         ("sev_terminal_hi",
          "diseaseSeverityTerminalHi",
          None),
         ("terminal_unit",
          "diseaseTerminalUnit",
          DUR_ENUM)]},
    {"key": "dm_parasite_areas",
     "pfx": "Pa",
     "title": ("DMG p.14 parasitic "
               "infestation table "
               "(6 areas)"),
     "name_fn": "parasiteAreaName",
     "count_fn": "parasiteAreaCount",
     "d100_fn": "parasiteAreaForD100",
     "tables": [
         ("sev_mild_hi",
          "parasiteSeverityMildHi",
          None),
         ("sev_severe_hi",
          "parasiteSeveritySevereHi",
          None),
         ("sev_terminal_hi",
          "parasiteSeverityTerminalHi",
          None)]},
]

LABELS = [
    "R1051 disease registry load",
    "R1051 disease registry counts",
    "R1051 disease areas",
    "R1051 parasite areas",
    "R1051 disease registry seam",
    "R1051 disease registry edges",
]


def die(msg):
    sys.stderr.write(
        "r1051_splice: FATAL: %s\n"
        % msg)
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
# An independent read of every
# retiring array, its function
# context, its dim and its clamp.

def enum_members(src, name):
    m = re.search(
        r"enum " + name
        + r" \{([\s\S]*?)\n\};",
        src)
    if not m:
        die("enum " + name
            + " not found")
    body = re.sub(r"//[^\n]*",
                  "", m.group(1))
    out = []
    for p in body.split(","):
        p = p.strip()
        # R1050 class 1: the NAME
        # captures first, the =d
        # initializer second
        mm = re.match(
            r"([A-Z_][A-Z_0-9]*)"
            r"(?:\s*=\s*(\d+))?$",
            p)
        if mm:
            out.append((mm.group(1),
                        mm.group(2)))
    if len(out) < 2:
        die("enum " + name
            + " members < 2")
    vals = {}
    v = 0
    for nm, iv in out:
        if iv is not None:
            v = int(iv)
        vals[nm] = v
        v += 1
    return vals


def parse_name_fn(src, fn):
    m = re.search(
        r"inline const char\* "
        + fn
        + r"\(int (\w+)\) \{\s*"
        r"static const char\* "
        r"const k\[(\d+)\] = "
        r"\{([\s\S]*?)\};",
        src)
    if not m:
        die("name array of " + fn
            + " not found")
    pnames = re.findall(
        r'"([^"]*)"', m.group(3))
    dim = int(m.group(2))
    if len(pnames) != dim:
        die(fn + ": %d names, "
            "dim %d"
            % (len(pnames), dim))
    clamp = parse_clamp(src, fn,
                        m.group(1),
                        dim)
    return {"names": pnames,
            "dim": dim,
            "param": m.group(1),
            "clamp": clamp}


def parse_clamp(src, fn, param,
                dim):
    # the clamp must pin the last
    # index (dim - 1) and use the
    # signature param name
    m = re.search(
        r"inline [\w\* ]*" + fn
        + r"\([\s\S]*?\n\}",
        src)
    if not m:
        die("body of " + fn
            + " not found")
    body = m.group(0)
    c = re.search(
        r"if \(" + param
        + r" > (\d+)\) " + param
        + r" = \1;", body)
    if not c:
        die("clamp of " + fn
            + " not found")
    if int(c.group(1)) != dim - 1:
        die("clamp of " + fn
            + " is %s, want %d"
            % (c.group(1), dim - 1))
    lo = re.search(
        r"if \(" + param
        + r" < 0\) " + param
        + r" = 0;", body)
    if not lo:
        die("lower clamp of "
            + fn + " not found")
    return int(c.group(1))


def parse_int_fn(src, fn,
                 want_clamp=True):
    m = re.search(
        r"inline int " + fn
        + r"\(int (\w+)\) \{\s*"
        r"static const int "
        r"k(?:Lo)?\[(\d+)\] = "
        r"\{([\s\S]*?)\};",
        src)
    if not m:
        die("int array of " + fn
            + " not found")
    vals = [int(v) for v in
            re.findall(
                r"-?\d+", m.group(3))]
    dim = int(m.group(2))
    if len(vals) != dim:
        die(fn + ": %d values, "
            "dim %d"
            % (len(vals), dim))
    clamp = (parse_clamp(
                src, fn,
                m.group(1), dim)
              if want_clamp
              else -1)
    return {"vals": vals,
            "dim": dim,
            "param": m.group(1),
            "clamp": clamp}


def parse_d100_fn(src, fn):
    r = parse_int_fn(src, fn,
                     False)
    m = re.search(
        r"inline int " + fn
        + r"\([\s\S]*?\n\}",
        src)
    body = m.group(0)
    if "kLo" not in body:
        die(fn + " is not a "
            + "kLo band fn")
    top = re.search(
        r"for \(int i = (\d+); "
        r"i >= 0; --i\)", body)
    if not top:
        die("band loop of " + fn
            + " not found")
    if int(top.group(1)) \
            != r["dim"] - 1:
        die("band loop of " + fn
            + " top %s, want %d"
            % (top.group(1),
               r["dim"] - 1))
    # the band lows must be
    # strictly increasing (the
    # kLo[i]-1 probes in the
    # audit assume gap >= 1)
    for i in range(1, len(
            r["vals"])):
        if r["vals"][i] \
                <= r["vals"][i - 1]:
            die("band of " + fn
                + " not strictly "
                + "increasing at "
                + str(i))
    # the d100 clamp is 1..100
    c = re.search(
        r"if \((\w+) < 1\) \1 "
        r"= 1;\s*if \(\1 > 100\)"
        r" \1 = 100;", body)
    if not c:
        die("d100 clamp of "
            + fn + " not found")
    r["d100"] = True
    return r


def parse_enum_fn(src, fn,
                  etype, evalues):
    m = re.search(
        r"inline " + etype
        + r" " + fn
        + r"\(int (\w+)\) \{"
        r"[\s\S]*?"
        r"static const " + etype
        + r" k\[(\d+)\] = "
        r"\{([\s\S]*?)\};",
        src)
    if not m:
        die("enum array of " + fn
            + " not found")
    toks = re.findall(
        r"([A-Z_][A-Z_0-9]*)"
        r"(?![\w])", m.group(3))
    dim = int(m.group(2))
    if len(toks) != dim:
        die(fn + ": %d members, "
            "dim %d"
            % (len(toks), dim))
    vals = []
    for t in toks:
        if t not in evalues:
            die(fn + ": member "
                + t + " not in "
                + etype)
        vals.append(evalues[t])
    clamp = parse_clamp(src, fn,
                        m.group(1),
                        dim)
    return {"vals": vals,
            "dim": dim,
            "param": m.group(1),
            "clamp": clamp,
            "members": toks}


def parse_count_fn(src, fn, dim):
    m = re.search(
        r"inline int " + fn
        + r"\(\) \{ return "
        r"(\d+); \}", src)
    if not m:
        die("count fn " + fn
            + " not found")
    if int(m.group(1)) != dim:
        die("count fn " + fn
            + " returns %s, "
            "want %d"
            % (m.group(1), dim))


def parse_all(src):
    ev = enum_members(src,
                      DUR_ENUM)
    for d in DEFS:
        d["rows_data"] = \
            parse_name_fn(
                src, d["name_fn"])
        d["d100_data"] = \
            parse_d100_fn(
                src, d["d100_fn"])
        parse_count_fn(
            src, d["count_fn"],
            d["rows_data"]["dim"])
        if d["d100_data"]["dim"] \
                != d["rows_data"][
                    "dim"]:
            die(d["key"]
                + ": name dim "
                + "!= band dim")
        d["table_data"] = []
        for tag, fn, et \
                in d["tables"]:
            if et is None:
                t = parse_int_fn(
                    src, fn)
            else:
                t = parse_enum_fn(
                    src, fn, et, ev)
            if t["dim"] \
                    != d["rows_data"][
                        "dim"]:
                die(d["key"] + "/"
                    + tag
                    + ": dim != "
                    + "rows dim")
            t["tag"] = tag
            t["fn"] = fn
            t["etype"] = et
            d["table_data"].append(
                t)
    n_static = len(re.findall(
        r"static const ", src))
    if n_static != 12:
        die("pristine has %d "
            "static consts, "
            "want 12"
            % n_static)
    return ev


# ---- the emitter ---------------------------

def wrap(text, ind=""):
    m = re.match(r"( *)(.*)", text,
                 re.S)
    lead = ind + m.group(1)
    body = m.group(2)
    if len(lead + body) <= 78:
        return [lead + body]
    if '"' in body:
        die("emit: line with a "
            + "string literal "
            + "does not fit 78: "
            + body[:40])
    words = body.split(" ")
    out = [lead + words[0]]
    for w in words[1:]:
        if len(out[-1]) + 1 \
                + len(w) <= 78:
            out[-1] += " " + w
        else:
            out.append(lead + "    "
                       + w)
    return out


class Emit:
    def __init__(self):
        self.lines = []

    def __call__(self, text,
                 ind=""):
        self.lines.extend(
            wrap(text, ind))


# ---- lua emit -------------------------------
# The R1042 equipment rows idiom +
# named tables per def (the R1047
# grid values shape).

def lua_def(d):
    out = []
    w = out.append
    key = d["key"]
    rows = d["rows_data"]
    n = rows["dim"]
    w("-- " + key)
    w("-- The R1051 disease de-wire"
      " (DMG pp.13-14).")
    w("-- " + d["title"] + ".")
    w("-- rows[]: the printed area"
      " names (name the")
    w("-- string, band the row"
      " index, the price/xp/")
    w("-- qty keys all 0 - the"
      " R1042 equipment")
    w("-- rows idiom). tables[]:"
      " the d100 band lows,")
    w("-- the occurrence and"
      " severity d8 highs,")
    if any(t["etype"]
           for t in
           d["table_data"]):
        w("-- and the terminal"
          " duration units (the")
        w("-- " + DUR_ENUM
          + " members as ints).")
    else:
        w("-- the severity d8"
          " highs.")
    w("-- The accessors live in"
      " rules/dmg/disease.h")
    w("-- and are unchanged.")
    w("-- DO NOT hand-edit: "
      "tools/r1051_splice.py")
    w("-- is the only writer.")
    w("")
    w("return {")
    w("  key = \"%s\"," % key)
    w("  name = \"%s\","
      % d["title"])
    w("  sources = {")
    w("    { part = 0, "
      "round = 1051 },")
    w("  },")
    w("  pins = {")
    w("    { name = "
      "\"%sRowCount\","
      % key)
    w("      value = %d,"
      % n)
    w("      comment = "
      "\"the table rows\" },")
    w("  },")
    w("  rows = {")
    for i, nm in enumerate(
            rows["names"]):
        w("    { name = \"%s\","
          % nm)
        w("      set = \"%s\","
          % key)
        w("      band = { %d, %d },"  # noqa: E501
          % (i, i))
        w("      xp = 0, "
          "xp_hi = 0, gp = 0, "
          "gp_hi = 0,")
        w("      qty = { 0, 0 }"
          " },")
    w("  },")
    w("  tables = {")
    for t in ([{"tag": "d100",
                "vals":
                d["d100_data"]
                ["vals"],
                "etype": None}]
              + d["table_data"]):
        w("    { name = \"%s\","
          % t["tag"])
        w("      values = {")
        vals = t["vals"]
        per = 10
        for r in range(0, n, per):
            w("        "
              + ", ".join(
                  str(v) for v
                  in vals[r:r + per])
              + ", ")
        w("      },")
        cmt = {
            "d100": "the d100 "
                    "band lows",
            "acute_hi": "the "
                        "occurrence "
                        "d8 acute "
                        "highs",
            "sev_mild_hi": "the "
                           "severity "
                           "d8 mild "
                           "highs",
            "sev_severe_hi":
                "the severity "
                "d8 severe highs",
            "sev_terminal_hi":
                "the severity d8 "
                "terminal highs",
            "terminal_unit":
                "the terminal "
                "duration units "
                "(DUR ints)",
        }[t["tag"]]
        w("      comment = "
          "\"%s\" }," % cmt)
    w("  },")
    w("}")
    w("")
    return "\n".join(out)


def build_lua():
    return {d["key"]:
            lua_def(d)
            for d in DEFS}


# ---- seam emit ------------------------------
# The header rewrite: the seam
# rides namespace rules (after its
# opener, the R1050 idiom); every
# accessor body is replaced with a
# registry read; every signature
# and clamp bound stays.

SEAM_TXT = """\
// ---- the R1051 registry seam ---------------
// content/tables/dm_disease/ via
// items::MiscItemRegistry: the R1042
// equipment rows idiom (name rows,
// band the row index) plus named
// tables per def (the R1047 values
// shape). Header-only singleton (the
// R1040 appendixp.h idiom). Every
// accessor below keeps its signature
// and clamp; only the array read
// moves behind the registry.

inline items::MiscItemRegistry&
dzReg() {
    static items::MiscItemRegistry
        reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory(
            "content/tables/"
            "dm_disease");
    }
    return reg;
}

// the name rows of one def (the
// printed areas, band the index)
inline const std::vector<
    items::MiscItemRow>& dzRows(
        const char* key) {
    static std::map<std::string,
        std::vector<
            items::MiscItemRow>>
        cache;
    auto it = cache.find(key);
    if (it == cache.end()) {
        const items::MiscItemDef*
            d = dzReg().find(key);
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
    long>* dzTable(const char* key,
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
            d = dzReg().find(key);
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


def new_name_body(d):
    n = d["rows_data"]["dim"]
    hi = n - 1
    e = Emit()
    e("inline const char* "
      + d["name_fn"]
      + "(int idx) {")
    e("    const auto& rows = "
      "dzRows(\"%s\");"
      % d["key"])
    e("    if (rows.empty()) "
      "return \"\";")
    e("    if (idx < 0) idx = 0;")
    e("    if (idx > %d) "
      "idx = %d;" % (hi, hi))
    e("    return rows[idx]"
      ".name.c_str();")
    e("}")
    return "\n".join(e.lines)


def new_d100_body(d):
    n = d["rows_data"]["dim"]
    hi = n - 1
    e = Emit()
    e("inline int "
      + d["d100_fn"]
      + "(int d100) {")
    e("    const auto* g = "
      "dzTable(\"%s\", "
      "\"d100\");"
      % d["key"])
    e("    if (!g) return 0;")
    e("    if (d100 < 1) "
      "d100 = 1;")
    e("    if (d100 > 100) "
      "d100 = 100;")
    e("    for (int i = "
      "(int)g->size() - 1;")
    e("         i >= 0; --i)")
    e("        if (d100 >= "
      "(int)(*g)[i]) return i;")
    e("    return 0;")
    e("}")
    return "\n".join(e.lines)


def new_table_body(d, t,
                   fallback):
    n = t["dim"]
    hi = n - 1
    e = Emit()
    if t["etype"] is None:
        e("inline int "
          + t["fn"]
          + "(int idx) {")
        ret = "    return (int)"
    else:
        e("inline " + t["etype"]
          + " " + t["fn"]
          + "(int idx) {")
        ret = ("    return ("
               + t["etype"] + ")")
    e("    const auto* g = "
      "dzTable(\"%s\", \"%s\");"
      % (d["key"], t["tag"]))
    if t["etype"] is None:
        e("    if (!g) return 0;")
    else:
        # int 0 does not
        # implicitly convert to
        # the enum - the fallback
        # names the zero member
        e("    if (!g) return "
          + fallback + ";")
    e("    if (idx < 0) idx = 0;")
    e("    if (idx > %d) "
      "idx = %d;" % (hi, hi))
    e(ret + "(*g)[idx];")
    e("}")
    return "\n".join(e.lines)


def build_seam(src, fallback):
    s = src
    if APPLIED_MARK in s:
        die("applied mark "
            "already present")
    anchor = "namespace rules {\n"
    if anchor not in s:
        die("namespace rules "
            "anchor not found")
    inc = (APPLIED_MARK + "\n"
           + "#include \"items/"
           "MiscItemRegistry.h\"\n"
           + "\n")
    s = s.replace(
        anchor, inc + anchor
        + "\n" + SEAM_TXT, 1)
    # the accessor rewrites,
    # each scoped to its own
    # function body
    for d in DEFS:
        for spec in (
            [[d["name_fn"],
              new_name_body(d)]]
            + [[d["d100_fn"],
                new_d100_body(d)]]
            + [[t["fn"],
                new_table_body(
                    d, t,
                    fallback)]
               for t in
               d["table_data"]]):
            fn, body = spec
            m = re.search(
                r"inline [\w\* ]*?"
                + fn
                + r"\([^)]*\)"
                r"[\s\S]*?\n\}",
                s)
            if not m:
                die("body of " + fn
                    + " not found "
                    + "for the "
                    + "rewrite")
            s = s.replace(
                m.group(0), body, 1)
    if re.search(r"static const ",
                 s):
        die("a static array "
            "survived the "
            "rewrite")
    return s


# ---- fragment emit --------------------------
# R1048 block idiom at the
# R1041+ in-function seat: six
# printf sections, bad reset
# between them, 5 guards, every
# want computed from the parse.

def want_arr(E, name, vals,
             per=10):
    E("const int %s[] = {" % name)
    for r in range(0, len(vals),
                   per):
        E("    " + ", ".join(
            str(v) for v in
            vals[r:r + per])
          + ",")
    E("};")


def build_frag(ev):
    E = Emit()
    P = E
    P("    // ==== R1051: "
      "disease registry "
      "========================")
    P("    // The R1051 de-wire:"
      " the 12 tables of")
    P("    // rules/dmg/disease.h"
      " ride items::")
    P("    // MiscItemRegistry from"
      " content/tables/")
    P("    // dm_disease/ (2 defs:"
      " name rows + d100/")
    P("    // occurrence/severity"
      " columns + the terminal")
    P("    // duration units). Six"
      " sections: load,")
    P("    // counts, disease"
      " areas, parasite areas,")
    P("    // seam, edges. Census"
      " 1064 -> 1070. DO NOT")
    P("    // hand-edit: "
      "tools/r1051_splice.py is"
      " the")
    P("    // only writer.")
    P("    {")
    P("        int bad = 0;")
    keys = [d["key"] for d in
            DEFS]
    # -- 1. load
    P("        // -- 1. load "
      "---------------------------------")
    P("        {")
    P("            items::"
      "MiscItemRegistry reg;")
    P("            int n = "
      "reg.loadDirectory(")
    P("                "
      "\"content/tables/"
      "dm_disease\");")
    P("            if (n != 2) "
      "++bad;")
    P("            if (!reg."
      "errors().empty()) ++bad;")
    P("            for (const "
      "auto& kv : reg.all())")
    P("                if ((int)"
      "kv.second.sources"
      ".size() != 1")
    P("                    || kv"
      ".second.sources[0]"
      ".second != 1051)")
    P("                    ++bad;")
    for key in keys:
        P("            if (!reg."
          "find(\"%s\")) ++bad;"
          % key)
    P("        }")
    P("        printf(\"%s "
      "audit: bad %%d\\n\", bad);"
      % LABELS[0])
    P("        if (bad) "
      "return 1;")
    P("        bad = 0;")
    # -- 2. counts
    P("        // -- 2. counts "
      "--------------------------------")
    P("        {")
    P("            items::"
      "MiscItemRegistry reg;")
    P("            reg."
      "loadDirectory(")
    P("                "
      "\"content/tables/"
      "dm_disease\");")
    for d in DEFS:
        key = d["key"]
        n = d["rows_data"]["dim"]
        nt = 1 + len(
            d["table_data"])
        tags = (["d100"]
                + [t["tag"]
                   for t in
                   d["table_data"]])
        P("            {")
        P("                const "
          "items::MiscItemDef*"
          " d =")
        P("                    "
          "reg.find(\"%s\");"
          % key)
        P("                if (!d)"
          " { ++bad; } else {")
        P("                    if "
          "((int)d->rows.size()"
          " != %d" % n)
        P("                        "
          "|| (int)d->pins.size()"
          " != 1")
        P("                        "
          "|| d->pins[0].name !="
          " \"%sRowCount\""
          % key)
        P("                        "
          "|| d->pins[0].value !="
          " %d" % n)
        P("                        "
          "|| (int)d->tables.size"
          "() != %d)" % nt)
        P("                        ++"
          "bad;")
        for i, tg in enumerate(
                tags):
            P("                    if"
              " (d->tables[%d].name"
              % i)
            P("                        "
              "!= \"%s\"" % tg)
            P("                        "
              "|| (int)d->tables[%d]"
              % i)
            P("                            "
              ".values.size() != %d)"
              % n)
            P("                        ++"
              "bad;")
        for i in range(n):
            P("                    if"
              " (d->rows[%d].set !="
              % i)
            P("                        "
              "\"%s\"" % key)
            P("                        "
              "|| d->rows[%d].bandLo"
              " != %d" % (i, i))
            P("                        "
              "|| d->rows[%d].bandHi"
              " != %d)" % (i, i))
            P("                        ++"
              "bad;")
        P("                }")
        P("            }")
    P("        }")
    P("        printf(\"%s "
      "audit: bad %%d\\n\", bad);"
      % LABELS[1])
    P("        if (bad) "
      "return 1;")
    P("        bad = 0;")
    # -- 3 + 4: the areas
    for di, d in enumerate(
            DEFS):
        lbl = LABELS[2 + di]
        P("        // -- %d. "
          "the %s ----"
          % (3 + di, d["key"]))
        P("        {")
        n = d["rows_data"]["dim"]
        P("            if "
          "(rules::%s() != %d)"
          " ++bad;"
          % (d["count_fn"], n))
        for i, nm in enumerate(
                d["rows_data"]
                ["names"]):
            P("            if "
              "(std::string("
              "rules::%s(%d))"
              % (d["name_fn"], i))
            P("                != "
              "\"%s\") ++bad;"
              % nm)
        P("            const int "
          "want%sLo[] = {"
          % d["pfx"])
        lo = d["d100_data"]["vals"]
        for r in range(0, n, 10):
            P("                "
              + ", ".join(
                  str(v) for v in
                  lo[r:r + 10])
              + ",")
        P("            };")
        P("            for (int i ="
          " 0; i < %d; ++i)" % n)
        P("                if "
          "(rules::%s("
          % d["d100_fn"])
        P("                    "
          "want%sLo[i]) != i)"
          % d["pfx"])
        P("                    ++bad;")
        P("            for (int i ="
          " 1; i < %d; ++i)" % n)
        P("                if "
          "(rules::%s("
          % d["d100_fn"])
        P("                    "
          "want%sLo[i] - 1) != "
          "i - 1)" % d["pfx"])
        P("                    ++bad;")
        for t in d["table_data"]:
            if t["etype"] is None:
                P("            const "
                  "int want%s%s[] = {"
                  % (d["pfx"],
                     camel(
                         t["tag"])))
                for r in range(
                        0, n, 10):
                    P("            "
                      "    "
                      + ", ".join(
                          str(v)
                          for v in
                          t["vals"]
                          [r:r + 10])
                      + ",")
                P("            };")
                P("            for "
                  "(int i = 0; i < "
                  "%d; ++i)" % n)
                P("                if"
                  " (rules::%s(i)"
                  % t["fn"])
                P("                    "
                  "!= want%s%s[i])"
                  % (d["pfx"],
                     camel(t["tag"])))
                P("                    "
                  "++bad;")
            else:
                P("            const "
                  "int want%s%s[] = {"
                  % (d["pfx"],
                     camel(
                         t["tag"])))
                for r in range(
                        0, n, 10):
                    P("            "
                      "    "
                      + ", ".join(
                          str(v)
                          for v in
                          t["vals"]
                          [r:r + 10])
                      + ",")
                P("            };")
                P("            for "
                  "(int i = 0; i < "
                  "%d; ++i)" % n)
                P("                if"
                  " ((int)rules::"
                  "%s(i)" % t["fn"])
                P("                    "
                  "!= want%s%s[i])"
                  % (d["pfx"],
                     camel(t["tag"])))
                P("                    "
                  "++bad;")
        P("        }")
        P("        printf(\"%s "
          "audit: bad %%d\\n\", bad);"
          % lbl)
        P("        if (bad) "
          "return 1;")
        P("        bad = 0;")
    # -- 5. seam: the raw registry
    # cross-read against the
    # accessors (dual-path diff)
    P("        // -- 5. seam "
      "---------------------------------")
    P("        {")
    P("            items::"
      "MiscItemRegistry reg;")
    P("            reg."
      "loadDirectory(")
    P("                "
      "\"content/tables/"
      "dm_disease\");")
    for d in DEFS:
        key = d["key"]
        n = d["rows_data"]["dim"]
        P("            {")
        P("                const "
          "items::MiscItemDef*"
          " d =")
        P("                    "
          "reg.find(\"%s\");"
          % key)
        P("                if (!d)"
          " ++bad;")
        for t in d["table_data"]:
            tag = t["tag"]
            P("                {")
            P("                    int "
              "got = 0;")
            P("                    for "
              "(const auto& t :"
              " d->tables) {")
            P("                        if"
              " (t.name != \"%s\")"
              % tag)
            P("                            "
              "continue;")
            P("                        got"
              " = 1;")
            P("                        for"
              " (int i = 0; i < "
              "%d;" % n)
            P("                             "
              "++i)")
            P("                            if"
              " ((int)t.values[i] !="
              " rules::%s(i))"
              % t["fn"])
            P("                                ++"
              "bad;")
            P("                    }")
            P("                    if "
              "(!got) ++bad;")
            P("                }")
        P("            }")
    P("        }")
    P("        printf(\"%s "
      "audit: bad %%d\\n\", bad);"
      % LABELS[4])
    P("        if (bad) "
      "return 1;")
    P("        bad = 0;")
    # -- 6. edges: clamps and the
    # boundary semantics
    P("        // -- 6. edges "
      "--------------------------------")
    P("        {")
    for d in DEFS:
        n = d["rows_data"]["dim"]
        hi = n - 1
        P("            if "
          "(std::string("
          "rules::%s(-1))"
          % d["name_fn"])
        P("                != "
          "\"%s\") ++bad;"
          % d["rows_data"]["names"]
          [0])
        P("            if "
          "(std::string("
          "rules::%s(99))"
          % d["name_fn"])
        P("                != "
          "\"%s\") ++bad;"
          % d["rows_data"]["names"]
          [hi])
        P("            if "
          "(rules::%s(0) != 0)"
          " ++bad;"
          % d["d100_fn"])
        P("            if "
          "(rules::%s(101) != %d)"
          " ++bad;"
          % (d["d100_fn"], hi))
    # the terminal-column and
    # acute/chronic boundary
    # semantics (disease def only);
    # the no-terminal-column areas
    # are COMPUTED from the parsed
    # terminal highs, never
    # hardcoded (R1049 lesson)
    term = [t for t in
            DEFS[0]["table_data"]
            if t["tag"]
            == "sev_terminal_hi"][0]
    zeros = [i for i, v in
             enumerate(
                 term["vals"])
             if v == 0]
    if len(zeros) != 3:
        die("disease terminal "
            "zero columns %s, "
            "want 3"
            % str(zeros))
    # boundary probes: IsAcute is
    # true AT the acute high (d8
    # <= hi) and false one past it
    # - the polarity is derived
    # from the parsed semantics,
    # never recalled
    P("            if "
      "(!rules::diseaseIsAcute("
      "0, rules::"
      "diseaseAcuteHi(0)))"
      " ++bad;")
    P("            if "
      "(rules::diseaseIsAcute("
      "0, rules::"
      "diseaseAcuteHi(0) + 1))"
      " ++bad;")
    P("            if "
      "(!rules::diseaseIsChronic("
      "0, rules::"
      "diseaseAcuteHi(0) + 1))"
      " ++bad;")
    P("            if "
      "(rules::diseaseChronicLo("
      "0) !="
      " rules::diseaseAcuteHi(0)"
      " + 1) ++bad;")
    for i in zeros:
        P("            if "
          "(rules::"
          "diseaseHasTerminalColumn"
          "(%d)) ++bad;" % i)
    nd = DEFS[0]["rows_data"]["dim"]
    for i in (0, nd - 1):
        if i in zeros:
            die("zero terminal "
                "column at a "
                "probe edge")
        P("            if "
          "(!rules::"
          "diseaseHasTerminalColumn"
          "(%d)) ++bad;" % i)
    P("            if "
      "(rules::diseaseMildWeeksMin()"
      " != 1")
    P("                || rules::"
      "diseaseMildWeeksMax() != 3)"
      " ++bad;")
    P("        }")
    P("        printf(\"%s "
      "audit: bad %%d\\n\", bad);"
      % LABELS[5])
    P("    }")
    return "\n".join(E.lines)


def camel(tag):
    return "".join(
        p.capitalize()
        for p in tag.split("_"))


# ---- the self-scan --------------------------
# Nothing is written until the
# emitted fragment, seam and lua
# pass every mirror check.

def self_scan(frag, seam,
              luas):
    # fragment shape
    if frag.count("printf(") != 6:
        die("self-scan: printf "
            "count")
    if frag.count(
            "audit: bad %d") != 6:
        die("self-scan: census "
            "pattern count")
    if frag.count(
            "if (bad) return 1;") \
            != 5:
        die("self-scan: guard "
            "count")
    for lbl in LABELS:
        if frag.count(lbl) != 1:
            die("self-scan: label "
                + lbl)
    # boundary-polarity guards:
    # IsAcute is true AT the
    # acute high and false one
    # past it; the probes must
    # match the parsed semantics
    # or the edges audit self-
    # destructs on correct data
    # (the R1051 polarity kill)
    if ("!rules::diseaseIsAcute("
        "0, rules::"
        "diseaseAcuteHi(0)))"
        " ++bad;"
            not in frag):
        die("self-scan: acute "
            "boundary polarity")
    if ("rules::diseaseIsAcute("
        "0, rules::"
        "diseaseAcuteHi(0) + 1))"
        " ++bad;"
            not in frag):
        die("self-scan: acute "
            "boundary polarity hi")
    if frag.count("(") != \
            frag.count(")"):
        die("self-scan: paren "
            "balance")
    if frag.count("{") != \
            frag.count("}"):
        die("self-scan: brace "
            "balance")
    if frag.count(
            "\n        bad = 0;") \
            != 5:
        die("self-scan: bad "
            "resets")
    for tok in ("#include",
                "#pragma",
                "namespace",
                "std::map",
                "std::set",
                "std::sort"):
        if tok in frag:
            die("self-scan: %s "
                "at the seat"
                % tok)
    for line in frag.splitlines():
        if line.startswith(
                "    // ===="):
            continue
        if len(line.rstrip()) \
                > 78:
            die("self-scan: "
                "frag cols: "
                + line[:50])
        s = line.rstrip()
        if s.endswith("})") \
                and not s.endswith(
                    "});"):
            die("self-scan: "
                "}) strip")
    if re.search(
            r"[A-Za-z0-9_]"
            r"(?:rules|items)::",
            frag):
        die("self-scan: fused "
            "ns token")
    if re.search(
            r"\bconst(?="
            r"[A-Za-z_])", frag):
        die("self-scan: fused "
            "const")
    # every rules:: token of the
    # fragment is qualified
    toks = set()
    for d in DEFS:
        toks.add(d["name_fn"])
        toks.add(d["count_fn"])
        toks.add(d["d100_fn"])
        for t in d["table_data"]:
            toks.add(t["fn"])
    toks.update([
        "diseaseChronicLo",
        "diseaseIsAcute",
        "diseaseIsChronic",
        "diseaseHasTerminalColumn",
        "diseaseMildWeeksMin",
        "diseaseMildWeeksMax"])
    for tk in toks:
        for m in re.finditer(
                r"(?<![\w:])" + tk
                + r"(?![\w:])",
                frag):
            if not frag[:m.
                    start()] \
                    .endswith(
                        "rules::"):
                die("self-scan: "
                    + tk
                    + " unqualified")
    # find targets parity
    keys = sorted(
        d["key"] for d in DEFS)
    if sorted(set(re.findall(
            r'reg\.find\("(\w+)"\)',
            frag))) != keys:
        die("self-scan: find "
            "targets")
    # want arrays: every int
    # table has one, and it
    # carries the parsed values
    for d in DEFS:
        if ("want%sLo[] = {"
                % d["pfx"]) \
                not in frag:
            die("self-scan: "
                "wantLo "
                + d["key"])
    for d in DEFS:
        for t in d["table_data"]:
            nm = ("want" + d["pfx"]
                  + camel(t["tag"]))
            if (nm + "[] = {") \
                    not in frag:
                die("self-scan: "
                    "want array "
                    + nm)
            m = re.search(
                re.escape(nm)
                + r"\[\] = "
                r"\{([\d\s,]+)\};",
                frag)
            got = [int(v) for v in
                   re.findall(
                       r"\d+",
                       m.group(1))]
            if got != t["vals"]:
                die("self-scan: "
                    "want values "
                    + nm)
    # seam checks
    if seam.count(APPLIED_MARK) \
            != 1:
        die("self-scan: mark "
            "count")
    if ('#include "items/'
            'MiscItemRegistry.h"'
            not in seam):
        die("self-scan: "
            "registry include")
    if re.search(
            r"static const ",
            seam):
        die("self-scan: a "
            "static array "
            "survived")
    for tok in ("dzReg()",
                "dzRows(",
                "dzTable("):
        if tok not in seam:
            die("self-scan: "
                "seam fn " + tok)
    # every accessor call
    # site pins its def key
    # and tag (dangling guards)
    for d in DEFS:
        if ('dzRows("%s")'
                % d["key"]) \
                not in seam:
            die("self-scan: "
                "dzRows key "
                + d["key"])
        for t in d["table_data"]:
            if ('dzTable("%s", '
                '"%s")'
                % (d["key"],
                   t["tag"])) \
                    not in seam:
                die("self-scan: "
                    "dzTable tag "
                    + t["tag"])
        if ('dzTable("%s", '
            '"d100")'
            % d["key"]) \
                not in seam:
            die("self-scan: "
                "dzTable d100 "
                + d["key"])
    # lua checks
    for d in DEFS:
        x = luas[d["key"]]
        key = d["key"]
        n = d["rows_data"]["dim"]
        if ('key = "%s"' % key) \
                not in x:
            die("self-scan: lua "
                "key " + key)
        if ("round = 1051"
                not in x):
            die("self-scan: lua "
                "round " + key)
        if x.count("band = { ") \
                != n:
            die("self-scan: lua "
                "row count " + key)
        if ('name = "%sRowCount"'
                % key) not in x:
            die("self-scan: lua "
                "pin " + key)
        for i, nm in enumerate(
                d["rows_data"]
                ["names"]):
            if ('name = "%s"' % nm) \
                    not in x:
                die("self-scan: lua "
                    "name " + nm)
        for t in d["table_data"]:
            if ('name = "%s"'
                    % t["tag"]) \
                    not in x:
                die("self-scan: lua "
                    "table " + t["tag"])
        # values parity: the
        # emitted flat values
        # equal the parse
        for t in ([{"tag": "d100",
                    "vals":
                    d["d100_data"]
                    ["vals"]}]
                  + d["table_data"]):
            m = re.search(
                r'name = "' + t["tag"]
                + r'",\s*values = \{'
                r'([\d\s,]+)\}',
                x)
            if not m:
                die("self-scan: "
                    "lua values "
                    + t["tag"])
            got = [int(v) for v in
                   re.findall(
                       r"\d+",
                       m.group(1))]
            if got != t["vals"]:
                die("self-scan: "
                    "lua value "
                    "parity "
                    + t["tag"])


# ---- main -----------------------------------

def main():
    if not os.path.isfile(
            os.path.join(
                ROOT, REGTEST)) \
            or not os.path.isfile(
                os.path.join(
                    ROOT, HEAD)):
        die("run me from the "
            + "repo root")
    src = open(os.path.join(
        ROOT, HEAD)).read()
    if APPLIED_MARK in src:
        print("applied 0, "
              "already 1")
        print("SPLICE OK")
        return
    c0 = census_count()
    if c0 != CENSUS_BEFORE:
        die("census %d, want %d"
            % (c0, CENSUS_BEFORE))
    ev = parse_all(src)
    luas = build_lua()
    seam = build_seam(
        src, next(iter(ev)))
    frag = build_frag(ev)
    self_scan(frag, seam, luas)
    # the regtest seat
    rt = open(os.path.join(
        ROOT, REGTEST)).read()
    if INC_ANCHOR not in rt:
        die("R1050 include "
            "anchor not found "
            "in regtest.cpp")
    before = rt.splitlines()
    at = before.index(
        [l for l in before
         if INC_ANCHOR in l][0])
    if at != 1298:
        die("R1050 include at "
            "line %d, want 1298"
            % (at + 1))
    rt = rt.replace(
        INC_ANCHOR + "\n",
        INC_ANCHOR + "\n"
        + INC_LINE + "\n", 1)
    # write everything
    os.makedirs(os.path.join(
        ROOT, LUA_DIR),
        exist_ok=True)
    for key, txt in luas.items():
        open(os.path.join(
            ROOT, LUA_DIR,
            key + ".lua"),
            "w").write(txt)
    open(os.path.join(
        ROOT, FRAG),
        "w").write(frag + "\n")
    open(os.path.join(
        ROOT, HEAD),
        "w").write(seam)
    open(os.path.join(
        ROOT, REGTEST),
        "w").write(rt)
    c1 = census_count()
    if c1 != CENSUS_AFTER:
        die("post census %d, "
            "want %d"
            % (c1, CENSUS_AFTER))
    print("census %d -> %d "
          "audit printf patterns"
          % (c0, c1))
    print("applied 1, rewrote "
          "2 tracked files, wrote "
          "3 new files")
    print("SPLICE OK")


if __name__ == "__main__":
    main()
