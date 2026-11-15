#!/usr/bin/env python3
# r1052_splice.py - the R1052 splice
# tool: the DMG p.20 purchased-poison
# table de-wire of rules/dmg/poison.h.
#
# WHAT IT DOES (run from the repo
# root, idempotent):
#   - parses the 10 hard-coded arrays
#     of the 6 route-branch accessors
#     (cost, onset min/max, detect,
#     damage if save, damage if no
#     save) plus the kept logic fns
#     (gradeExists, killsIfNoSave,
#     victimSaveBonus, onsetUnit,
#     user efficiency, monster flags,
#     blade venom) as semantic MODELS
#   - writes content/tables/dm_poison/
#     as 2 defs (dm_poison_ingestive:
#     5 grade rows + 6 tables;
#     dm_poison_insinuative: 4 grade
#     rows + 4 tables) - the R1042
#     rows idiom (grade letters,
#     band the grade index) plus
#     named tables per def (R1051)
#   - rewrites the 6 array accessors
#     onto a namespace-rules seam:
#     pzReg() / pzTable(key, tag);
#     every signature, guard and
#     route branch stays
#   - writes rules/audits/
#     r1052_poison_registry.h at the
#     R1041+ in-function seat (six
#     printf sections, census
#     1070 -> 1076) and seats its
#     include at regtest.cpp:1301
#
# HARD LESSONS APPLIED (the R1049 +
# R1050 + R1051 ledgers): every want
# is computed from the SAME parse that
# writes the lua; the damage_if_no_save
# tables hold PRE-KILL values while
# the want arrays hold EXPECTED
# ACCESSOR OUTPUTS (kills -> -1), and
# the seam cross-read reconstructs
# the table value from the accessor +
# the parsed kills model; the probe
# POLARITIES (kills, gradeExists,
# unit specials) are derived from the
# parsed models, never recalled
# (R1051 class 3); the tool SELF-SCANS
# its own emitted fragment, seam and
# lua before writing; labels are
# pre-shaped to fit 78 on ONE line.

import os
import re
import sys

ROOT = os.getcwd()
HEAD = "rules/dmg/poison.h"
LUA_DIR = "content/tables/dm_poison"
FRAG = ("rules/audits/"
        "r1052_poison_registry.h")
REGTEST = "regtest.cpp"
APPLIED_MARK = "// R1052 applied"
INC_LINE = ('    #include "rules/audits/'
            'r1052_poison_registry.h"'
            '  // R1052')
CENSUS_BEFORE = 1070
CENSUS_AFTER = 1076
MARKER = "R1052 poison registry"
INC_ANCHOR = ('    #include "rules/audits/'
              'r1051_disease_'
              'registry.h"  // R1051')
ING = 0   # POISON_INGESTIVE
INS = 1   # POISON_INSINUATIVE

# which accessor feeds which table;
# route_rows marks the defs whose
# table the accessor picks BY ROUTE
# (ternary); the insinuative def
# owns only the tables its route can
# read. detect_chance and
# damage_if_save are ingestive-owned
# (the accessors never branch on
# route for them).
DEFS = [
    {"key": "dm_poison_ingestive",
     "pfx": "Pi",
     "route": ING,
     "title": ("DMG p.20 purchased "
               "poison, ingestive "
               "(grades A-E)"),
     "tags": ["cost_per_dose",
              "onset_min",
              "onset_max",
              "detect_chance",
              "damage_if_save",
              "damage_if_no_save"]},
    {"key": "dm_poison_insinuative",
     "pfx": "Ps",
     "route": INS,
     "title": ("DMG p.20 purchased "
               "poison, insinuative "
               "(grades A-D)"),
     "tags": ["cost_per_dose",
              "onset_min",
              "onset_max",
              "damage_if_no_save"]},
]

# accessor fn per tag
FN = {
    "cost_per_dose":
        "poisonCostPerDose",
    "onset_min": "poisonOnsetMin",
    "onset_max": "poisonOnsetMax",
    "detect_chance":
        "poisonDetectChance",
    "damage_if_save":
        "poisonDamageIfSave",
    "damage_if_no_save":
        "poisonDamageIfNoSave",
}

# tags whose accessor picks the def
# by route (ternary); the rest read
# the ingestive def for both routes
ROUTE_TAGS = ["cost_per_dose",
              "onset_min",
              "onset_max",
              "damage_if_no_save"]

LABELS = [
    "R1052 poison registry load",
    "R1052 poison registry counts",
    "R1052 ingestive poisons",
    "R1052 insinuative poisons",
    "R1052 poison registry seam",
    "R1052 poison registry edges",
]


def die(msg):
    sys.stderr.write(
        "r1052_splice: FATAL: %s\n"
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
# retiring array plus a semantic
# MODEL of every kept logic fn (the
# frag probes derive from the models,
# never from recalled constants).

def fn_body(src, fn):
    m = re.search(
        r"inline [\w\* ]+?" + fn +
        r"\([\s\S]*?\n\}", src)
    if not m:
        die("body of " + fn
            + " not found")
    return m.group(0)


def parse_arrays_in(body, fn):
    # every static array of one
    # accessor body, in source order
    out = re.findall(
        r"static const int "
        r"(\w+)\[(\d+)\] = "
        r"\{([^}]*)\};", body)
    if not out:
        die("no arrays in " + fn)
    return [(nm, int(dm),
             [int(v) for v in
              re.findall(r"-?\d+",
                         lit)])
            for nm, dm, lit in out]


def parse_pristine(src):
    p = {}
    p["n_static"] = len(
        re.findall(r"static const ",
                   src))
    if p["n_static"] != 10:
        die("pristine has %d "
            "static consts, want 10"
            % p["n_static"])
    # the enums (stay in the
    # header; the frag probes
    # their members)
    for en, want in (
            [("PoisonRoute", 2),
             ("PoisonUnit", 3)]):
        m = re.search(
            r"enum " + en +
            r" \{([\s\S]*?)\n\};",
            src)
        if not m:
            die("enum " + en
                + " not found")
        mem = re.findall(
            r"(POISON_\w+)"
            r"(?:\s*=\s*(\d+))?",
            re.sub(r"//[^\n]*", "",
                   m.group(1)))
        p[en] = [(nm,
                  int(iv) if iv
                  else i)
                 for i, (nm, iv)
                 in enumerate(mem)]
        if len(p[en]) != want:
            die("enum " + en
                + " has %d members"
                % len(p[en]))
    # the grade bounds: ingestive
    # A-E (0..4), insinuative A-D
    # (0..3) - derived from the
    # gradeExists model below
    ge = fn_body(src,
                 "poisonGrade"
                 "Exists")
    m = re.search(
        r"if \(grade < (\d+) \|\| "
        r"grade > (\d+)\)", ge)
    if not m:
        die("grade bounds not "
            "found")
    p["g_lo"] = int(m.group(1))
    p["g_hi"] = int(m.group(2))
    m = re.search(
        r"route == "
        r"POISON_INSINUATIVE\) "
        r"return grade <= (\d+)",
        ge)
    if not m:
        die("insinuative grade "
            "cap not found")
    p["ins_hi"] = int(m.group(1))
    if (p["g_lo"], p["g_hi"],
            p["ins_hi"]) != (0, 4, 3):
        die("grade bounds %s"
            % str((p["g_lo"],
                   p["g_hi"],
                   p["ins_hi"])))
    # the six array accessors
    arrs = {}
    for tag, fn in FN.items():
        body = fn_body(src, fn)
        got = parse_arrays_in(
            body, fn)
        if tag in ROUTE_TAGS:
            # two arrays: the
            # dim-5 ingestive and
            # the dim-4 insinuative
            a5 = [a for a in got
                  if a[1] == 5]
            a4 = [a for a in got
                  if a[1] == 4]
            if len(a5) != 1 \
                    or len(a4) != 1:
                die(fn + ": want "
                    "one 5-array and "
                    "one 4-array")
            # the insinuative
            # branch must read the
            # dim-4 array
            m = re.search(
                r"route == "
                r"POISON_INSINUATIVE\)"
                r"[\s\S]{0,160}?"
                r"return (\w+)\[",
                body)
            if not m \
                    or m.group(1) \
                    != a4[0][0]:
                die(fn + ": the "
                    "insinuative "
                    "branch does not "
                    "read the 4-array")
            # the fallthrough
            # must read the 5-array
            # (a dead array would
            # retire silently)
            if a5[0][0] not in \
                    re.findall(
                        r"return "
                        r"(\w+)\[",
                        body):
                die(fn + ": the "
                    "5-array is dead")
            arrs[tag] = {
                "ing": a5[0][2],
                "ins": a4[0][2]}
        else:
            # single ingestive-
            # owned array, dim 5
            if len(got) != 1 \
                    or got[0][1] != 5:
                die(fn + ": want "
                    "one 5-array")
            # a route branch may
            # exist but must
            # return a CONSTANT
            # (damage_if_save:
            # insinuative -> 0),
            # never read an
            # array
            if re.search(
                    r"POISON_INSINUATIVE\)"
                    r"[\s\S]{0,20}?"
                    r"return \w+\[",
                    body):
                die(fn + ": the "
                    "insinuative "
                    "branch reads an "
                    "array, want a "
                    "constant")
            arrs[tag] = {
                "ing": got[0][2],
                "ins": None}
    p["arrs"] = arrs
    # the kills model
    kb = fn_body(src,
                 "poisonKillsIf"
                 "NoSave")
    m = re.search(
        r"POISON_INSINUATIVE\) "
        r"return grade == (\d+)",
        kb)
    if not m:
        die("kills insinuative "
            "rule not found")
    p["kills_ins_eq"] = \
        int(m.group(1))
    m = re.search(
        r"return grade >= (\d+)",
        kb)
    if not m:
        die("kills ingestive "
            "rule not found")
    p["kills_ing_ge"] = \
        int(m.group(1))
    # the victim save bonus model
    vb = fn_body(src,
                 "poisonVictim"
                 "SaveBonus")
    m = re.search(
        r"grade <= (\d+)\) "
        r"return (\d+) - grade",
        vb)
    if not m:
        die("vsb ladder not found")
    p["vsb_lo"], p["vsb_base"] = \
        int(m.group(1)), \
        int(m.group(2))
    m = re.search(
        r"grade == (\d+)\) "
        r"return (\d+);",
        vb)
    if not m:
        die("vsb grade-3 rule "
            "not found")
    p["vsb_eq"], p["vsb_eq_v"] = \
        int(m.group(1)), \
        int(m.group(2))
    m = re.search(
        r"(\d+) \}\s*$",
        vb.replace("\n", " "))
    # the final fallthrough
    m = re.findall(
        r"return (\d+);", vb)
    p["vsb_else"] = int(m[-1])
    # the onset unit model
    ub = fn_body(src,
                 "poisonOnsetUnit")
    spec = re.findall(
        r"route == "
        r"POISON_INGESTIVE && "
        r"grade == (\d+)\)\s*"
        r"return POISON_UNIT_"
        r"(\w+);", ub)
    if len(spec) != 2:
        die("onset unit specials "
            "not found")
    ival = dict(
        (nm, v)
        for nm, v in p["PoisonUnit"])
    p["unit_spec"] = [
        (int(g), ival["POISON_UNIT_"
                      + u])
        for g, u in spec]
    m = re.search(
        r"return POISON_UNIT_"
        r"(\w+);\s*\}",
        ub)
    if not m:
        die("onset unit default "
            "not found")
    p["unit_def"] = ival[
        "POISON_UNIT_" + m.group(1)]
    # blade venom potency model
    bb = fn_body(src,
                 "poisonBladeVenom"
                 "PotencyPercent")
    p["blade"] = re.findall(
        r"interval (<=|==) "
        r"(\d+)\) return (\d+);",
        bb)
    m = re.search(
        r"return (\d+);\s*\}",
        bb)
    if not m:
        die("blade default not "
            "found")
    p["blade_else"] = \
        int(m.group(1))
    # the simple return-N fns
    for fn, want in (
            [("poisonMonster"
              "AllOrNothing",
              "true"),
             ("poisonMonster"
              "DualUse",
              "true")]):
        b = fn_body(src, fn)
        if ("return " + want
                + ";") not in b:
            die(fn + " does not "
                "return " + want)
    # user efficiency model
    ub2 = fn_body(src,
                  "poisonUser"
                  "EfficiencyAdj")
    m = re.search(
        r"assassin && studied\) "
        r"return (\d+);",
        ub2)
    if not m:
        die("user eff studied "
            "rule not found")
    p["ue_studied"] = \
        int(m.group(1))
    m = re.search(
        r"if \(assassin\) "
        r"return (\d+);",
        ub2)
    if not m:
        die("user eff assassin "
            "rule not found")
    p["ue_assassin"] = \
        int(m.group(1))
    m = re.findall(
        r"return (\d+);", ub2)
    p["ue_other"] = int(m[-1])
    # decayed blade venom
    db = fn_body(src,
                 "poisonBladeVenom"
                 "DecayedGives"
                 "SaveBonus")
    m = re.search(
        r"return interval "
        r">= (\d+);", db)
    if not m:
        die("decayed rule not "
            "found")
    p["decayed_ge"] = \
        int(m.group(1))
    return p


# the semantic models (shared by
# the frag emit and the self-scan
# polarity re-derivation)

def m_exists(p, route, grade):
    if grade < p["g_lo"] \
            or grade > p["g_hi"]:
        return False
    if route == INS:
        return grade <= p["ins_hi"]
    return True


def m_kills(p, route, grade):
    if not m_exists(p, route,
                    grade):
        return False
    if route == INS:
        return grade \
            == p["kills_ins_eq"]
    return grade \
        >= p["kills_ing_ge"]


def m_vsb(p, grade):
    if grade <= p["vsb_lo"]:
        return p["vsb_base"] \
            - grade
    if grade == p["vsb_eq"]:
        return p["vsb_eq_v"]
    return p["vsb_else"]


def m_unit(p, route, grade):
    for g, u in p["unit_spec"]:
        if route == ING \
                and grade == g:
            return u
    return p["unit_def"]


def m_blade(p, interval):
    for op, n, v in p["blade"]:
        if op == "<=" \
                and interval \
                <= int(n):
            return int(v)
        if op == "==" \
                and interval \
                == int(n):
            return int(v)
    return p["blade_else"]


# ---- the emitter ---------------------------

def wrap(text, ind=""):
    m = re.match(r" *(.*)", text,
                 re.S)
    body = text.lstrip(" ")
    lead = ind + (" " *
                  (len(text)
                   - len(body)))
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

def grade_rows(p, route):
    hi = (p["ins_hi"]
          if route == INS
          else p["g_hi"])
    return [chr(ord("A") + i)
            for i in range(hi + 1)]


def lua_def(p, d):
    out = []
    w = out.append
    key = d["key"]
    names = grade_rows(
        p, d["route"])
    n = len(names)
    w("-- " + key)
    w("-- The R1052 poison "
      "de-wire (DMG p.20).")
    w("-- " + d["title"] + ".")
    w("-- rows[]: the grade "
      "letters (name the")
    w("-- string, band the "
      "grade index, all")
    w("-- price/xp/qty keys 0 "
      "- the R1042")
    w("-- equipment rows "
      "idiom). tables[]: the")
    w("-- per-grade columns of "
      "the p.20 print.")
    w("-- damage_if_no_save "
      "holds the PRE-KILL")
    w("-- printed values (a "
      "kill grade reads -1")
    w("-- through "
      "poisonKillsIfNoSave).")
    w("-- The accessors live "
      "in rules/dmg/poison.h")
    w("-- and keep their "
      "guards and branches.")
    w("-- DO NOT hand-edit: "
      "tools/r1052_splice.py")
    w("-- is the only writer.")
    w("")
    w("return {")
    w("  key = \"%s\"," % key)
    w("  name = \"%s\","
      % d["title"])
    w("  sources = {")
    w("    { part = 0, "
      "round = 1052 },")
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
    for i, nm in enumerate(names):
        w("    { name = \"%s\","
          % nm)
        w("      set = \"%s\","
          % key)
        w("      band = { %d, %d },"
          % (i, i))
        w("      xp = 0, "
          "xp_hi = 0, gp = 0, "
          "gp_hi = 0,")
        w("      qty = { 0, 0 }"
          " },")
    w("  },")
    w("  tables = {")
    for tag in d["tags"]:
        vals = table_vals(
            p, d, tag)
        w("    { name = \"%s\","
          % tag)
        w("      values = {")
        for r in range(0, n, 10):
            w("        "
              + ", ".join(
                  str(v) for v
                  in vals[r:r + 10])
              + ", ")
        w("      },")
        w("      comment = "
          "\"%s\" },"
          % lua_cmt(tag))
    w("  },")
    w("}")
    w("")
    return "\n".join(out)


def lua_cmt(tag):
    return {
        "cost_per_dose":
            "gp per dose",
        "onset_min":
            "the onset range "
            "low end",
        "onset_max":
            "the onset range "
            "high end",
        "detect_chance":
            "the taste/smell/"
            "see percent",
        "damage_if_save":
            "damage on a made "
            "save (ingestive "
            "print)",
        "damage_if_no_save":
            "pre-kill damage "
            "on a failed save",
    }[tag]


def table_vals(p, d, tag):
    # the PRE-KILL table
    # values this def owns
    a = p["arrs"][tag]
    return (a["ing"]
            if d["route"] == ING
            else a["ins"])


def build_lua(p):
    return {d["key"]:
            lua_def(p, d)
            for d in DEFS}


# ---- seam emit ------------------------------

SEAM_TXT = """\
// ---- the R1052 registry seam ---------------
// content/tables/dm_poison/ via
// items::MiscItemRegistry: the
// R1042 grade rows plus named
// tables per def (the R1051
// dzTable idiom). Header-only
// singleton (the R1040 appendixp.h
// idiom). Every accessor below
// keeps its signature, guard and
// route branch; only the array
// read moves behind the registry.

inline items::MiscItemRegistry&
pzReg() {
    static items::MiscItemRegistry
        reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory(
            "content/tables/"
            "dm_poison");
    }
    return reg;
}

// one named int table of one def
// (null when absent or empty)
inline const std::vector<long
    long>* pzTable(const char* key,
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
            d = pzReg().find(key);
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


def pick_lines(tag):
    # the def-selection lines:
    # a route ternary for the
    # route-owned tags, a fixed
    # ingestive key for the
    # single-owner tags
    if tag in ROUTE_TAGS:
        return [
            "    const auto* g = "
            "pzTable(",
            "        route == "
            "POISON_INSINUATIVE",
            "            ? "
            "\"dm_poison_insinuative\"",
            "            : "
            "\"dm_poison_ingestive\",",
            "        \"%s\");" % tag]
    return [
        "    const auto* g = pzTable("
        "\"dm_poison_ingestive\", "
        "\"%s\");" % tag]


def new_accessor_body(tag):
    fn = FN[tag]
    e = Emit()
    e("inline int %s(int route, "
      "int grade) {" % fn)
    # the guard lines, kept
    # exactly as the pristine
    if tag == "cost_per_dose":
        e("    if (!poisonGrade"
          "Exists(route, grade))"
          " return 0;")
        fb = "0"
    elif tag in ("onset_min",
                 "onset_max"):
        e("    if (!poisonGrade"
          "Exists(route, grade))"
          " return 0;")
        fb = "0"
    elif tag == "detect_chance":
        e("    if (!poisonGrade"
          "Exists(route, grade))"
          " return 0;")
        fb = "0"
    elif tag == "damage_if_save":
        e("    if (!poisonGrade"
          "Exists(route, grade))"
          " return -1;")
        e("    if (route == "
          "POISON_INSINUATIVE)"
          " return 0;")
        fb = "-1"
    else:  # damage_if_no_save
        e("    if (poisonKills"
          "IfNoSave(route, "
          "grade)) return -1;")
        e("    if (!poisonGrade"
          "Exists(route, grade))"
          " return -1;")
        fb = "0"
    for ln in pick_lines(tag):
        e(ln)
    e("    if (!g) return %s;"
      % fb)
    e("    return (int)(*g)"
      "[grade];")
    e("}")
    return "\n".join(e.lines)


def build_seam(src):
    s = src
    if APPLIED_MARK in s:
        die("applied mark already "
            "present")
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
    for tag in FN:
        fn = FN[tag]
        body = new_accessor_body(
            tag)
        m = re.search(
            r"inline [\w\* ]*?"
            + fn
            + r"\([^)]*\)"
            r"[\s\S]*?\n\}", s)
        if not m:
            die("body of " + fn
                + " not found for "
                "the rewrite")
        s = s.replace(
            m.group(0), body, 1)
    if re.search(r"static const ",
                 s):
        die("a static array "
            "survived the rewrite")
    # the kept logic fns must
    # still be present
    for fn in ("poisonGrade"
               "Exists",
               "poisonKillsIf"
               "NoSave",
               "poisonVictim"
               "SaveBonus",
               "poisonOnsetUnit",
               "poisonUser"
               "EfficiencyAdj"):
        if ("inline" not in s
                or fn not in s):
            die("kept fn " + fn
                + " lost")
    return s


# ---- fragment emit --------------------------

def want_arr(P, name, vals,
             per=10, ind=""):
    P("%sconst int %s[] = {"
      % (ind, name))
    for r in range(0, len(vals),
                   per):
        P("%s    %s,"
          % (ind,
             ", ".join(
                 str(v) for v in
                 vals[r:r + per])))
    P("%s};" % ind)


def build_frag(p):
    E = Emit()
    P = E
    P("    // ==== R1052: poison "
      "registry "
      "========================")
    P("    // The R1052 de-wire: "
      "the 10 arrays of")
    P("    // rules/dmg/poison.h "
      "ride items::")
    P("    // MiscItemRegistry "
      "from content/tables/")
    P("    // dm_poison/ (2 defs: "
      "grade rows + the")
    P("    // p.20 columns; "
      "damage_if_no_save is")
    P("    // pre-kill, the "
      "accessor folds the")
    P("    // kills model back "
      "in). Six sections: ")
    P("    // load, counts, "
      "ingestive, insinuative,")
    P("    // seam, edges. Census"
      " 1070 -> 1076. DO NOT")
    P("    // hand-edit: "
      "tools/r1052_splice.py is "
      "the")
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
      "dm_poison\");")
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
      ".second != 1052)")
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
      "dm_poison\");")
    for d in DEFS:
        key = d["key"]
        names = grade_rows(
            p, d["route"])
        n = len(names)
        tags = list(d["tags"])
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
          "() != %d)"
          % len(tags))
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
            P("                        "
              "++bad;")
        for i in range(n):
            P("                    if"
              " (d->rows[%d].set !="
              % i)
            P("                        "
              "\"%s\""
              " || d->rows[%d]"
              % (key, i))
            P("                        "
              ".bandLo != %d"
              " || d->rows[%d]"
              % (i, i))
            P("                        "
              ".bandHi != %d"
              " || std::string("
              % i)
            P("                        "
              "d->rows[%d].name)"
              % i)
            P("                        "
              "!= \"%s\")"
              % names[i])
            P("                        "
              "++bad;")
        P("                }")
        P("            }")
    P("        }")
    P("        printf(\"%s "
      "audit: bad %%d\\n\", bad);"
      % LABELS[1])
    P("        if (bad) "
      "return 1;")
    P("        bad = 0;")
    # -- 3 + 4: the routes
    for di, d in enumerate(DEFS):
        lbl = LABELS[2 + di]
        route = d["route"]
        names = grade_rows(
            p, route)
        n = len(names)
        P("        // -- %d. "
          "the %s ----"
          % (3 + di, d["key"]))
        P("        {")
        for tag in d["tags"]:
            fn = FN[tag]
            # the EXPECTED
            # ACCESSOR OUTPUTS:
            # kills grades fold
            # to -1
            vals = list(
                table_vals(p, d,
                           tag))
            if tag \
                    == "damage_if_" \
                       "no_save":
                for i in range(n):
                    if m_kills(
                            p, route,
                            i):
                        vals[i] = -1
            wn = ("want%s%s"
                  % (d["pfx"],
                     camel(tag)))
            want_arr(
                P, wn, vals,
                ind="            ")
            P("            for "
              "(int i = 0; i < "
              "%d; ++i)" % n)
            P("                if "
              "(rules::%s(%d, i)"
              % (fn, route))
            P("                    "
              "!= %s[i])"
              % wn)
            P("                    "
              "++bad;")
        # the ingestive-owned
        # columns read THROUGH
        # the insinuative route
        # (the pristine
        # accessors never
        # branch on route for
        # them)
        if d["route"] == INS:
            dv = p["arrs"][
                "detect_chance"][
                "ing"][:n]
            want_arr(
                P,
                "wantPsDetect"
                "Chance", dv,
                ind="            ")
            P("            for "
              "(int i = 0; i < "
              "%d; ++i)" % n)
            P("                if "
              "(rules::poison"
              "DetectChance(1, i)")
            P("                    "
              "!= wantPs"
              "DetectChance[i])")
            P("                    "
              "++bad;")
            for i in range(n):
                P("            if "
                  "(rules::poison"
                  "DamageIfSave(1, %d)"
                  " != 0)" % i)
                P("                "
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
    # accessors (dual-path diff);
    # damage_if_no_save compares
    # KILLS-AWARE: the lua holds
    # the PRE-KILL print (0 at
    # kill grades), the accessor
    # folds the kills model to
    # -1 - so a kill grade asserts
    # acc == -1 and a non-kill
    # grade asserts table == acc
    # (the pre-kill vs folded
    # ternary compared the two
    # against each other: 0 != -1
    # at every kill grade, a
    # compile-clean runtime kill)
    P("        // -- 5. seam "
      "---------------------------------")
    P("        {")
    P("            items::"
      "MiscItemRegistry reg;")
    P("            reg."
      "loadDirectory(")
    P("                "
      "\"content/tables/"
      "dm_poison\");")
    for d in DEFS:
        key = d["key"]
        route = d["route"]
        n = len(grade_rows(
            p, route))
        P("            {")
        P("                const "
          "items::MiscItemDef*"
          " d =")
        P("                    "
          "reg.find(\"%s\");"
          % key)
        P("                if (!d)"
          " ++bad;")
        for tag in d["tags"]:
            P("                {")
            P("                    "
              "int got = 0;")
            P("                    "
              "for (const auto& t :"
              " d->tables) {")
            P("                        "
              "if (t.name != "
              "\"%s\")" % tag)
            P("                            "
              "continue;")
            P("                        "
              "got = 1;")
            if tag \
                    == "damage_" \
                       "if_no_save":
                P("                        "
                  "for (int i = 0; "
                  "i < %d;" % n)
                P("                             "
                  "++i)")
                P("                            "
                  "if (rules::poison"
                  "KillsIfNoSave(%d, "
                  "i)) {" % route)
                P("                                "
                  "if (rules::poison"
                  "DamageIfNoSave(%d, "
                  "i) != -1)" % route)
                P("                                    "
                  "++bad;")
                P("                            "
                  "} else {")
                P("                                "
                  "if ((int)t.values[i] !=")
                P("                                    "
                  "rules::poison"
                  "DamageIf"
                  "NoSave(%d, i))"
                  % route)
                P("                                    "
                  "++bad;")
                P("                            }")
            else:
                P("                        "
                  "for (int i = 0; "
                  "i < %d;" % n)
                P("                             "
                  "++i)")
                P("                            "
                  "if ((int)t.values[i] !="
                  " rules::%s(%d, i))"
                  % (FN[tag], route))
                P("                                "
                  "++bad;")
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
    # -- 6. edges: the kept
    # logic fns, probed from the
    # parsed models (the last
    # section carries NO guard)
    P("        // -- 6. edges "
      "--------------------------------")
    P("        {")
    # gradeExists polarity,
    # DERIVED from the model
    for route in (ING, INS):
        for g in (p["g_lo"] - 1,
                  p["g_hi"] + 1,
                  p["ins_hi"] + 1
                  if route == INS
                  else p["ins_hi"]):
            ex = m_exists(
                p, route, g)
            # model-TRUE needs
            # the bang (fire when
            # the accessor
            # disagrees)
            pol = "!" if ex \
                else ""
            P("            if "
              "(%srules::poison"
              "GradeExists(%d, %d))"
              % (pol, route, g))
            P("                "
              "++bad;")
    for route in (ING, INS):
        g0 = 0 if m_exists(
            p, route, 0) else None
        P("            if "
          "(!rules::poison"
          "GradeExists(%d, 0))"
          % route)
        P("                ++bad;")
    # onsetUnit specials +
    # default (DERIVED)
    for route in (ING, INS):
        for g in range(
                p["ins_hi"] + 1
                if route == INS
                else p["g_hi"] + 1):
            u = m_unit(
                p, route, g)
            un = [nm for nm, v
                  in p["PoisonUnit"]
                  if v == u][0]
            P("            if "
              "(rules::poison"
              "OnsetUnit(%d, %d)"
              % (route, g))
            P("                != "
              "rules::%s) ++bad;"
              % un)
    # the victim save bonus
    # ladder (DERIVED)
    for route in (ING, INS):
        hi = (p["ins_hi"]
              if route == INS
              else p["g_hi"])
        for g in range(hi + 1):
            P("            if "
              "(rules::poison"
              "VictimSaveBonus("
              "%d, %d) != %d)"
              % (route, g,
                 m_vsb(p, g)))
            P("                "
              "++bad;")
    # the kills polarity
    # (DERIVED - the R1051
    # class-3 lesson: the
    # probes must match the
    # model, never invert)
    for route in (ING, INS):
        hi = (p["ins_hi"]
              if route == INS
              else p["g_hi"])
        for g in range(hi + 1):
            k = m_kills(
                p, route, g)
            # model-TRUE needs
            # the bang (fire when
            # the accessor
            # disagrees - the
            # R1051 class-3
            # lesson, now with
            # the polarity the
            # RIGHT way round)
            pol = "!" if k \
                else ""
            P("            if "
              "(%srules::poison"
              "KillsIfNoSave("
              "%d, %d))" %
              (pol, route, g))
            P("                "
              "++bad;")
    # user efficiency, the
    # monster flags, blade
    # venom (DERIVED)
    P("            if "
      "(rules::poisonUser"
      "EfficiencyAdj(true, "
      "true) != %d)"
      % p["ue_studied"])
    P("                ++bad;")
    P("            if "
      "(rules::poisonUser"
      "EfficiencyAdj(true, "
      "false) != %d)"
      % p["ue_assassin"])
    P("                ++bad;")
    P("            if "
      "(rules::poisonUser"
      "EfficiencyAdj(false, "
      "false) != %d)"
      % p["ue_other"])
    P("                ++bad;")
    P("            if "
      "(!rules::poison"
      "MonsterAllOrNothing())"
      " ++bad;")
    P("            if "
      "(!rules::poison"
      "MonsterDualUse())"
      " ++bad;")
    for iv in (0, 1, 2):
        P("            if "
          "(rules::poison"
          "BladeVenom"
          "PotencyPercent(%d)"
          " != %d)" %
          (iv, m_blade(p, iv)))
        P("                "
          "++bad;")
    P("            if "
      "(rules::poison"
      "BladeVenomDecayed"
      "GivesSaveBonus(0))"
      " ++bad;")
    P("            if "
      "(!rules::poison"
      "BladeVenomDecayed"
      "GivesSaveBonus(1))"
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
        for p in
        tag.split("_"))


# ---- the self-scan --------------------------
# Nothing is written until the
# emitted fragment, seam and lua
# pass every structural and
# parity check.

def self_scan(frag, seam,
              luas, p):
    # fragment shape
    if frag.count("printf("
                  ) != 6:
        die("self-scan: printf "
            "count")
    if frag.count(
            "audit: bad %d") != 6:
        die("self-scan: census "
            "pattern count")
    if frag.count(
            "if (bad) return 1;"
            ) != 5:
        die("self-scan: guard "
            "count")
    if frag.count(
            "\n        bad = 0;"
            ) != 5:
        die("self-scan: bad "
            "resets")
    for lbl in LABELS:
        if frag.count(lbl) != 1:
            die("self-scan: label "
                + lbl)
    if frag.count("(") != \
            frag.count(")"):
        die("self-scan: paren "
            "balance")
    if frag.count("{") != \
            frag.count("}"):
        die("self-scan: brace "
            "balance")
    # seat shape
    for tok in ("#include",
                "#pragma",
                "namespace",
                "inline",
                "std::map",
                "std::set",
                "std::sort"):
        if tok in frag:
            die("self-scan: %s at "
                "the seat" % tok)
    # terminator strip
    for line in frag.splitlines():
        s = line.rstrip()
        if s.endswith("})") \
                and not \
                s.endswith("});"):
            die("self-scan: }) "
                "strip")
    # cols (banner lines exempt)
    for line in frag.splitlines():
        if line.startswith(
                "    // ===="):
            continue
        if len(line.rstrip()) \
                > 78:
            die("self-scan: cols "
                + repr(line[:50]))
    # fused tokens
    if re.search(
            r"[A-Za-z0-9_]"
            r"(?:rules|items)::",
            frag):
        die("self-scan: fused "
            "token")
    if re.search(
            r"\bconst(?=[A-Za-z_])",
            frag):
        die("self-scan: fused "
            "const")
    # rules:: qualification of
    # every fn and enum token
    toks = set(FN.values())
    for en in ("PoisonRoute",
               "PoisonUnit"):
        toks.add(en)
        toks.update(
            nm for nm, _
            in p[en])
    toks.update([
        "poisonGradeExists",
        "poisonKillsIfNoSave",
        "poisonVictimSaveBonus",
        "poisonOnsetUnit",
        "poisonUser"
        "EfficiencyAdj",
        "poisonMonster"
        "AllOrNothing",
        "poisonMonsterDualUse",
        "poisonBladeVenom"
        "PotencyPercent",
        "poisonBladeVenom"
        "DecayedGives"
        "SaveBonus"])
    fcode = re.sub(
        r"//[^\n]*", "", frag)
    for tk in toks:
        for m in re.finditer(
                r"(?<![\w:])" + tk
                + r"(?![\w:])",
                fcode):
            if not fcode[:m.
                    start()] \
                    .endswith(
                        "rules::"):
                die("self-scan: "
                    + tk
                    + " unqualified")
            break
    for tk in ("MiscItemRegistry",
               "MiscItemDef"):
        for m in re.finditer(
                r"(?<![\w:])" + tk
                + r"(?![\w:])",
                fcode):
            if not fcode[:m.
                    start()] \
                    .endswith(
                        "items::"):
                die("self-scan: "
                    + tk
                    + " not items::")
            break
    # find targets AS SETS
    if sorted(set(re.findall(
            r'reg\.find\("(\w+)"'
            r"\)", frag))) \
            != sorted(
                [d["key"]
                 for d in DEFS]):
        die("self-scan: find "
            "targets")
    # want arrays: per-def
    # prefixes, values parity
    # vs the parse (expected
    # accessor outputs)
    for d in DEFS:
        route = d["route"]
        n = len(grade_rows(
            p, route))
        for tag in d["tags"]:
            wn = ("want%s%s"
                  % (d["pfx"],
                     camel(tag)))
            m = re.search(
                r"const int " + wn
                + r"\[\] = \{"
                r"([\d\s,-]+)\};",
                frag)
            if not m:
                die("self-scan: "
                    "want " + wn
                    + " missing")
            got = [int(v) for v in
                   re.findall(
                       r"-?\d+",
                       m.group(1))]
            vals = list(
                table_vals(
                    p, d, tag))
            if tag \
                    == "damage_if_" \
                       "no_save":
                for i in range(n):
                    if m_kills(
                            p, route,
                            i):
                        vals[i] = -1
            if got != vals:
                die("self-scan: "
                    "want " + wn
                    + " parity")
    # the route-1 detect
    # probes (the
    # ingestive-owned
    # column read through
    # the insinuative
    # route)
    m = re.search(
        r"const int "
        r"wantPsDetectChance"
        r"\[\] = \{"
        r"([\d\s,]+)\};", frag)
    if not m:
        die("self-scan: want "
            "wantPsDetectChance "
            "missing")
    got = [int(v) for v in
           re.findall(r"\d+",
                      m.group(1))]
    if got != p["arrs"][
            "detect_chance"][
            "ing"][
        :len(grade_rows(
            p, INS))]:
        die("self-scan: want "
            "wantPsDetectChance "
            "parity")
    # polarity re-derivation:
    # every kills and exists
    # probe must match the
    # model (R1051 class 3 -
    # and the R1052 lesson:
    # the check must derive
    # the polarity from the
    # SEMANTICS, not copy the
    # emitter's formula)
    for route in (ING, INS):
        hi = (p["ins_hi"]
              if route == INS
              else p["g_hi"])
        for g in range(hi + 1):
            pol = ("!" if
                   m_kills(
                       p, route, g)
                   else "")
            want = ("%srules::"
                    "poisonKills"
                    "IfNoSave(%d, "
                    "%d))"
                    % (pol, route,
                       g))
            if want not in fcode:
                die("self-scan: "
                    "kills probe "
                    "polarity %d,%d"
                    % (route, g))
    for route in (ING, INS):
        for g in (p["g_lo"] - 1,
                  p["g_hi"] + 1,
                  p["ins_hi"] + 1
                  if route == INS
                  else p["ins_hi"]):
            ex = m_exists(
                p, route, g)
            pol = ("!" if ex
                   else "")
            want = ("%srules::"
                    "poisonGrade"
                    "Exists(%d, %d))"
                    % (pol, route,
                       g))
            if want not in fcode:
                die("self-scan: "
                    "exists probe "
                    "polarity %d,%d"
                    % (route, g))
    # seam checks
    if seam.count(
            APPLIED_MARK) != 1:
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
    if "pzReg()" not in seam \
            or "pzTable(" \
            not in seam:
        die("self-scan: seam "
            "fn missing")
    # the kills-aware seam
    # compare (the class-14
    # kill): the frag's
    # damage_if_no_save seam
    # compare must assert
    # acc == -1 at kill grades
    # and table == acc at the
    # rest - never the folded
    # ternary against pre-kill
    # data (0 != -1)
    fflat = re.sub(r"\s+", " ",
                   frag)
    if fflat.count("? -1"):
        die("self-scan: the "
            "folded ternary "
            "rides the seam "
            "compare")
    for route in (0, 1):
        want = ("if (rules::"
                "poisonKillsIf"
                "NoSave(%d, i)) "
                "{ if (rules::"
                "poisonDamageIf"
                "NoSave(%d, i) "
                "!= -1) ++bad; } "
                "else { if ((int)"
                "t.values[i] != "
                "rules::poison"
                "DamageIfNoSave"
                "(%d, i)) ++bad; }"
                % (route, route,
                   route))
        if want not in fflat:
            die("self-scan: "
                "kills-aware "
                "seam compare "
                "route %d"
                % route)
    # every accessor call
    # site pins its def key
    # and tag
    for d in DEFS:
        for tag in d["tags"]:
            if tag \
                    in ROUTE_TAGS:
                # the ternary:
                # both keys with
                # this tag
                for ln in (
                        "? \"dm_poison_"
                        "insinuative\"",
                        ": \"dm_poison_"
                        "ingestive\","):
                    if ln not in seam:
                        die("self-"
                            "scan: "
                            "ternary "
                            "key "
                            + ln)
                if ('"%s\");'
                    % tag) \
                        not in seam:
                    die("self-"
                        "scan: tag "
                        + tag)
            else:
                if ('pzTable('
                    '"dm_poison_'
                    'ingestive", '
                    '"%s\");'
                    % tag) \
                        not in seam:
                    die("self-"
                        "scan: "
                        "single-"
                        "owner site "
                        + tag)
    # lua checks
    for d in DEFS:
        x = luas[d["key"]]
        key = d["key"]
        names = grade_rows(
            p, d["route"])
        n = len(names)
        if ('key = "%s"'
                % key) not in x:
            die("self-scan: lua "
                "key " + key)
        if "round = 1052" \
                not in x:
            die("self-scan: lua "
                "round " + key)
        if x.count("band = { ") \
                != n:
            die("self-scan: lua "
                "row count " + key)
        if ('name = "%s'
            'RowCount"'
                % key) not in x:
            die("self-scan: lua "
                "pin " + key)
        for i, nm in \
                enumerate(names):
            if ('name = "%s",'
                    % nm) not in x:
                die("self-scan: "
                    "lua grade "
                    + nm)
        for tag in d["tags"]:
            if ('name = "%s",'
                    % tag) not in x:
                die("self-scan: "
                    "lua table "
                    + tag)
            m = re.search(
                r'name = "' + tag
                + r'",\s*values = \{'
                r'([\d\s,]+)\}', x)
            if not m:
                die("self-scan: "
                    "lua values "
                    + tag)
            got = [int(v)
                   for v in
                   re.findall(
                       r"\d+",
                       m.group(1))]
            if got != table_vals(
                    p, d, tag):
                die("self-scan: "
                    "lua value "
                    "parity "
                    + tag)


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
    p = parse_pristine(src)
    luas = build_lua(p)
    seam = build_seam(src)
    frag = build_frag(p)
    self_scan(frag, seam, luas,
              p)
    # the regtest seat
    rt = open(os.path.join(
        ROOT, REGTEST)).read()
    if INC_ANCHOR not in rt:
        die("R1051 include "
            "anchor not found "
            "in regtest.cpp")
    before = rt.splitlines()
    at = before.index(
        [l for l in before
         if INC_ANCHOR in l][0])
    if at != 1299:
        die("R1051 include at "
            "line %d, want 1300"
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
