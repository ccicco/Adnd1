#!/usr/bin/env python3
# r1053_splice.py - the R1053 splice tool: the DMG pp.82-83
# intoxication + insanity table de-wire of
# rules/dmg/insanity.h.
#
# WHAT IT DOES (run from the repo root, idempotent):
#   - parses the 14 retiring int arrays (11 single-array
#     state accessors + the two stimulant percent arrays
#     + the 7-cell mania strength grid with its DEAD
#     index 0) plus the 21-string insanity name array,
#     and MODELS the kept logic fns (intoxicationClamp,
#     insanityIsMild, the derived magicSaveRaise ladder,
#     the 41 zero-arg scalar fns)
#   - writes content/tables/dm_insanity/ as 2 defs:
#     dm_intoxication (5 state ROWS computed from the
#     INTOX_* enum members + 13 named dim-5 tables) and
#     dm_insanity (20 form ROWS from the parsed names +
#     the 7-cell mania_strength_state table, dead 0
#     preserved faithfully)
#   - rewrites the 14 array accessors onto a
#     namespace-rules seam: izReg() / izRows(key) /
#     izTable(key, tag); every signature, clamp and
#     branch stays (the stimulant accessor keeps its
#     branch as a TAG-level ternary on the same def key;
#     insanityName becomes a rows reader - the R1051
#     dzRows idiom)
#   - writes rules/audits/r1053_insanity_registry.h at
#     the R1041+ in-function seat (six printf sections,
#     census 1076 -> 1082) and seats its include at
#     regtest.cpp:1302
#
# HARD LESSONS APPLIED (the R1049-R1052 ledgers): every
# want is computed from the SAME parse that writes the
# lua; the probe POLARITIES (IsMild, the clamp bounds)
# are DERIVED from the parsed models, never recalled;
# NEGATIVE cells are handled end to end (parse, lua,
# wants, every parity check); the tag-level ternary
# carries its own self-scan check (the R1052 adjacent-
# literal class - here the key is fixed and each ternary
# arm ends its own string, but the check stays); the
# tool SELF-SCANS its own emitted fragment, seam and
# lua before writing anything.

import os
import re
import sys

ROOT = os.getcwd()
HEAD = "rules/dmg/insanity.h"
LUA_DIR = "content/tables/dm_insanity"
FRAG = "rules/audits/r1053_insanity_registry.h"
REGTEST = "regtest.cpp"
APPLIED_MARK = "// R1053 applied"
INC_LINE = ('    #include "rules/audits/'
            'r1053_insanity_registry.h"  // R1053')
CENSUS_BEFORE = 1076
CENSUS_AFTER = 1082
INC_ANCHOR = ('    #include "rules/audits/'
              'r1052_poison_registry.h"  // R1052')

# the 11 single-array state accessors (tag -> fn)
STATE_TAGS = [
    ("bravery_adjust", "intoxicationBraveryAdjust"),
    ("morale_adjust", "intoxicationMoraleAdjust"),
    ("intelligence_adjust", "intoxicationIntelligenceAdjust"),
    ("wisdom_adjust", "intoxicationWisdomAdjust"),
    ("dexterity_adjust", "intoxicationDexterityAdjust"),
    ("charisma_adjust", "intoxicationCharismaAdjust"),
    ("attack_dice_adjust", "intoxicationAttackDiceAdjust"),
    ("hit_point_adjust", "intoxicationHitPointAdjust"),
    ("magic_save_raise_percent", "intoxicationMagicSaveRaisePercent"),
    ("recovery_min_hours", "intoxicationRecoveryMin"),
    ("recovery_max_hours", "intoxicationRecoveryMax"),
]

# the stimulant percent tables: tag -> (strong, array name)
STIM_TAGS = [
    ("stimulant_mild_percent", False, "kMild"),
    ("stimulant_strong_percent", True, "kStrong"),
]

STIM_FN = "intoxicationStimulantPercent"
MANIA_TAG = "mania_strength_state"
MANIA_FN = "insanityManiaStrengthState"
NAME_FN = "insanityName"

DEFS = [
    {"key": "dm_intoxication",
     "pfx": "Ti",
     "title": ("DMG p.82 intoxication "
               "(the five states)"),
     "tags": [t for t, _ in STATE_TAGS]
             + [t for t, _, _ in STIM_TAGS]},
    {"key": "dm_insanity",
     "pfx": "Ta",
     "title": ("DMG p.83 insanity "
               "(the twenty forms)"),
     "tags": [MANIA_TAG]},
]

LABELS = [
    "R1053 insanity registry load",
    "R1053 insanity registry counts",
    "R1053 intoxication states",
    "R1053 insanity types",
    "R1053 insanity registry seam",
    "R1053 insanity registry edges",
]

LUA_CMT = {
    "bravery_adjust":
        "the bravery modifier",
    "morale_adjust":
        "the NPC morale percent",
    "intelligence_adjust":
        "the intelligence modifier",
    "wisdom_adjust":
        "the wisdom modifier",
    "dexterity_adjust":
        "the dexterity modifier",
    "charisma_adjust":
        "the charisma modifier",
    "attack_dice_adjust":
        "the attack-dice penalty",
    "hit_point_adjust":
        "the hit-point bonus",
    "magic_save_raise_percent":
        "the vs-magic save raise percent",
    "recovery_min_hours":
        "recovery hours low end",
    "recovery_max_hours":
        "recovery hours high end",
    "stimulant_mild_percent":
        "the mild stimulant "
        "multiplier percent",
    "stimulant_strong_percent":
        "the strong stimulant "
        "multiplier percent",
    "mania_strength_state":
        "the d6 mania strength "
        "percent (index 0 dead)",
}


def die(msg):
    sys.stderr.write(
        "r1053_splice: FATAL: %s\n" % msg)
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


def parse_arrays_in(body, fn):
    out = re.findall(
        r"static const int "
        r"(\w+)\[(\d+)\] = "
        r"\{([^}]*)\};", body)
    if not out:
        die("no arrays in " + fn)
    return [(nm, int(dm),
             [int(v) for v in
              re.findall(r"-?\d+", lit)])
            for nm, dm, lit in out]


def parse_pristine(src):
    p = {}
    p["n_static"] = len(
        re.findall(r"static const ", src))
    if p["n_static"] != 15:
        die("pristine has %d static "
            "consts, want 15 (14 int "
            "arrays + the name array)"
            % p["n_static"])
    # the IntoxState enum (stays in
    # the header; the lua row names
    # COMPUTE from its members)
    m = re.search(
        r"enum IntoxState "
        r"\{([\s\S]*?)\n\};", src)
    if not m:
        die("enum IntoxState not found")
    mem = re.findall(
        r"(INTOX_\w+)"
        r"(?:\s*=\s*(\d+))?",
        re.sub(r"//[^\n]*", "",
               m.group(1)))
    p["IntoxState"] = [(nm,
                        int(iv) if iv else i)
                       for i, (nm, iv)
                       in enumerate(mem)]
    if len(p["IntoxState"]) != 5:
        die("IntoxState has %d members"
            % len(p["IntoxState"]))
    if p["IntoxState"][0] != \
            ("INTOX_SOBER", 0) \
            or p["IntoxState"][4][1] != 4:
        die("IntoxState bounds "
            "unexpected")
    p["state_names"] = [
        nm[len("INTOX_"):].lower()
        for nm, _ in p["IntoxState"]]
    # the clamp fn (kept; edges
    # probe its bounds DERIVED)
    cb = flat(fn_body(src,
                      "intoxicationClamp"))
    if ("if (s < INTOX_SOBER) "
            "s = INTOX_SOBER;") not in cb \
            or ("if (s > INTOX_"
                "COMATOSE) s = INTOX_"
                "COMATOSE;") not in cb:
        die("clamp bounds not found")
    # the 11 single-array state
    # accessors
    arrs = {}
    for tag, fn in STATE_TAGS:
        body = fn_body(src, fn)
        got = parse_arrays_in(body, fn)
        if len(got) != 1 \
                or got[0][1] != 5:
            die(fn + ": want one "
                "5-array")
        if "intoxicationClamp(s)" \
                not in body:
            die(fn + ": the clamp "
                "call is missing")
        arrs[tag] = got[0][2]
    # the stimulant accessor: two
    # arrays, the branch is the
    # strong bool - verify the
    # ternary reads the right one
    body = fn_body(src, STIM_FN)
    got = parse_arrays_in(body, STIM_FN)
    amap = dict(
        (nm, (dm, vals))
        for nm, dm, vals in got)
    if set(amap) != set(
            ["kMild", "kStrong"]):
        die(STIM_FN + ": want "
            "kMild + kStrong")
    for nm in ("kMild", "kStrong"):
        if amap[nm][0] != 5:
            die(STIM_FN + ": " + nm
                + " is not dim 5")
    fb = flat(body)
    if ("return strong ? "
            "kStrong[intoxication"
            "Clamp(s)] : "
            "kMild[intoxication"
            "Clamp(s)];") not in fb:
        die(STIM_FN + ": the "
            "strong ternary does "
            "not read kStrong then "
            "kMild")
    arrs["stimulant_mild_percent"] = \
        amap["kMild"][1]
    arrs["stimulant_strong_percent"] = \
        amap["kStrong"][1]
    # the missing-table fallback
    # must be polarity-independent
    if amap["kMild"][1][0] != \
            amap["kStrong"][1][0]:
        die(STIM_FN + ": the sober "
            "cells differ, the "
            "fallback would be "
            "polarity-dependent")
    p["stim_fb"] = amap["kMild"][1][0]
    # the mania strength grid: 7
    # cells with the DEAD index 0
    body = fn_body(src, MANIA_FN)
    got = parse_arrays_in(body, MANIA_FN)
    if len(got) != 1 or got[0][1] != 7:
        die(MANIA_FN + ": want one "
            "7-array")
    p["mania"] = got[0][2]
    fb = flat(body)
    if ("if (d6 < 1) d6 = 1; "
            "if (d6 > 6) d6 = 6; "
            "return k[d6];") not in fb:
        die(MANIA_FN + ": the d6 "
            "clamp or read not found")
    # the name array: 21 strings,
    # index 0 dead
    body = fn_body(src, NAME_FN)
    m = re.search(
        r"k\[21\] = \{([\s\S]*?)\};",
        body)
    if not m:
        die("the name array init "
            "not found")
    names = re.findall(
        r'"([^"]*)"', m.group(1))
    if len(names) != 21 \
            or names[0] != "":
        die("the name array is not "
            "21 strings with a dead "
            "index 0")
    p["names"] = names[1:]
    lo = int(re.search(
        r"if \(type < (\d+)\)",
        body).group(1))
    hi = int(re.search(
        r"if \(type > (\d+)\)",
        body).group(1))
    if (lo, hi) != (1, len(p["names"])):
        die("name clamps %s do not "
            "match the %d names"
            % (str((lo, hi)),
               len(p["names"])))
    p["name_lo"], p["name_hi"] = lo, hi
    # insanityIsMild (kept; the
    # edges polarity derives here)
    body = flat(fn_body(src,
                        "insanityIsMild"))
    m = re.search(
        r"return type >= (\d+) && "
        r"type <= (\d+);", body)
    if not m:
        die("the IsMild bounds not "
            "found")
    p["mild_lo"] = int(m.group(1))
    p["mild_hi"] = int(m.group(2))
    # the derived magicSaveRaise
    # ladder (kept fn, no array)
    body = flat(fn_body(
        src, "intoxicationMagicSaveRaise"))
    if ("return -intoxication"
            "AttackDiceAdjust(s);") \
            not in body:
        die("magicSaveRaise is not "
            "the negated attack "
            "ladder")
    if "static const" in body:
        die("magicSaveRaise reads "
            "an array")
    p["msvr"] = [
        -v for v in
        arrs["attack_dice_adjust"]]
    # the zero-arg scalar fns
    p["scalars"] = re.findall(
        r"inline int (\w+)\(\)"
        r"\s*\{\s*return (-?\d+);"
        r"\s*\}", src)
    if len(p["scalars"]) < 30:
        die("only %d scalar fns "
            "parsed" % len(p["scalars"]))
    p["arrs"] = arrs
    return p


def m_mild(p, t):
    return p["mild_lo"] <= t <= p["mild_hi"]


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

def lua_def(p, d):
    out = []
    w = out.append
    key = d["key"]
    if key == "dm_intoxication":
        names = p["state_names"]
    else:
        names = p["names"]
    n = len(names)
    w("-- " + key)
    w("-- The R1053 insanity de-wire "
      "(DMG pp.82-83).")
    w("-- " + d["title"] + ".")
    w("-- rows[]: " +
      ("the intoxication states "
       "(names COMPUTED from the "
       "INTOX_* enum members)" if
       key == "dm_intoxication" else
       "the printed insanity forms, "
       "1-20 in order (band the "
       "index, row i = type i+1)")
      + " - the R1042 equipment rows "
      "idiom.")
    w("-- tables[]: the printed "
      "columns per row" +
      ("; mania_strength_state "
       "keeps its DEAD index 0 "
       "faithfully (the accessor "
       "clamps d6 1..6 and reads "
       "values[d6])" if
       key == "dm_insanity" else "")
      + ".")
    w("-- The accessors live in "
      "rules/dmg/insanity.h and "
      "keep their clamps and "
      "branches.")
    w("-- DO NOT hand-edit: "
      "tools/r1053_splice.py is the "
      "only writer.")
    w("")
    w("return {")
    w("  key = \"%s\"," % key)
    w("  name = \"%s\"," % d["title"])
    w("  sources = {")
    w("    { part = 0, round = 1053 },")
    w("  },")
    w("  pins = {")
    w("    { name = \"%sRowCount\","
      % key)
    w("      value = %d,"
      % n)
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
    for tag in d["tags"]:
        vals = p["arrs"][tag] \
            if tag != MANIA_TAG \
            else p["mania"]
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
    return {d["key"]: lua_def(p, d)
            for d in DEFS}


# ---- seam emit ------------------------------

SEAM_TXT = """\
// ---- the R1053 registry seam ---------------
// content/tables/dm_insanity/ via
// items::MiscItemRegistry: the
// R1042 rows idiom plus named
// tables per def (the R1051 dzTable
// idiom) and the rows reader (the
// R1051 dzRows idiom - insanityName
// is a rows reader now). Header-only
// singleton (the R1040 appendixp.h
// idiom). Every accessor below
// keeps its signature, clamp and
// branch; only the array read moves
// behind the registry. The stimulant
// accessor keeps its strong branch
// as a TAG-level ternary on the same
// def key (each ternary arm closes
// its own string - the R1052 adjacent
// literal lesson).

inline items::MiscItemRegistry&
izReg() {
    static items::MiscItemRegistry
        reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory(
            "content/tables/"
            "dm_insanity");
    }
    return reg;
}

// the name rows of one def (the
// band is the index; insanityName
// maps type-1 onto them)
inline const std::vector<
    items::MiscItemRow>& izRows(
        const char* key) {
    static std::map<std::string,
        std::vector<
            items::MiscItemRow>>
        cache;
    auto it = cache.find(key);
    if (it == cache.end()) {
        const items::MiscItemDef*
            d = izReg().find(key);
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
    long>* izTable(const char* key,
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
            d = izReg().find(key);
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


def new_state_body(p, tag, fn):
    e = Emit()
    e("inline int %s(IntoxState s) {" % fn)
    e.raw([
        "    const auto* g = izTable(",
        "        \"dm_intoxication\", \"%s\");" % tag])
    e("    if (!g) return %d;"
      % p["arrs"][tag][0])
    e("    return (int)(*g)"
      "[intoxicationClamp(s)];")
    e("}")
    return "\n".join(e.lines)


def new_stim_body(p):
    e = Emit()
    e("inline int %s(" % STIM_FN)
    e("        IntoxState s, "
      "bool strong) {")
    e.raw([
        "    const auto* g = izTable(",
        "        \"dm_intoxication\",",
        "        strong",
        "            ? \"stimulant_strong_percent\"",
        "            : \"stimulant_mild_percent\");"])
    e("    if (!g) return %d;" % p["stim_fb"])
    e("    return (int)(*g)"
      "[intoxicationClamp(s)];")
    e("}")
    return "\n".join(e.lines)


def new_mania_body(p):
    e = Emit()
    e("inline int %s(int d6) {" % MANIA_FN)
    e.raw([
        "    const auto* g = izTable(",
        "        \"dm_insanity\", \"mania_strength_state\");"])
    e("    if (d6 < 1) d6 = 1;")
    e("    if (d6 > 6) d6 = 6;")
    e("    if (!g) return %d;" % p["mania"][0])
    e("    return (int)(*g)[d6];")
    e("}")
    return "\n".join(e.lines)


def new_name_body(p):
    e = Emit()
    e("inline const char* %s(int type) {"
      % NAME_FN)
    e("    const auto& rows = ")
    e.raw(["        izRows(\"dm_insanity\");"])
    e("    if (rows.empty())")
    e("        return \"\";")
    e("    if (type < %d) type = %d;"
      % (p["name_lo"], p["name_lo"]))
    e("    if (type > %d) type = %d;"
      % (p["name_hi"], p["name_hi"]))
    e("    if ((int)rows.size() < type)")
    e("        return \"\";")
    e("    return rows[type - 1]"
      ".name.c_str();")
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
    rewrites = []
    for tag, fn in STATE_TAGS:
        rewrites.append((fn,
                         new_state_body(p, tag, fn)))
    rewrites.append((STIM_FN, new_stim_body(p)))
    rewrites.append((MANIA_FN, new_mania_body(p)))
    rewrites.append((NAME_FN, new_name_body(p)))
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
    for fn in (["intoxicationClamp",
                "intoxicationMagicSaveRaise",
                "insanityIsMild"]
               + [fn for fn, _ in
                  p["scalars"]]):
        if ("inline" not in s
                or fn not in s):
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


def name_probe(E, t, nm):
    # a string-literal probe hand-shaped
    # so the literal never wraps (wrap()
    # refuses quotes; the R1052 lesson);
    # rules:: and the fn stay on one line
    # so the qualification scan holds
    E.raw([
        "            if (std::string(",
        "                rules::insanityName(%d))" % t,
        "                != \"%s\")" % nm,
        "                ++bad;"])


def build_frag(p):
    E = Emit()
    P = E
    P("    // ==== R1053: insanity registry ==========")
    P("    // The R1053 de-wire: the 14 int arrays")
    P("    // and the 21-string name array of")
    P("    // rules/dmg/insanity.h ride items::")
    P("    // MiscItemRegistry from content/tables/")
    P("    // dm_insanity/ (2 defs: state + form")
    P("    // rows, named tables; the mania grid")
    P("    // keeps its dead index 0, the name")
    P("    // array retires onto the rows). Six")
    P("    // sections: load, counts, the two")
    P("    // defs, seam, edges. Census 1076 ->")
    P("    // 1082. DO NOT hand-edit:")
    P("    // tools/r1053_splice.py is the only")
    P("    // writer.")
    P("    {")
    P("        int bad = 0;")
    keys = [d["key"] for d in DEFS]
    # -- 1. load
    P("        // -- 1. load ---------------------------------")
    P("        {")
    P("            items::MiscItemRegistry reg;")
    P("            int n = reg.loadDirectory(")
    P("                \"content/tables/dm_insanity\");")
    P("            if (n != 2) ++bad;")
    P("            if (!reg.errors().empty()) ++bad;")
    P("            for (const auto& kv : reg.all())")
    P("                if ((int)kv.second.sources.size() != 1")
    P("                    || kv.second.sources[0].second != 1053)")
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
    P("                \"content/tables/dm_insanity\");")
    for d in DEFS:
        key = d["key"]
        if key == "dm_intoxication":
            names = p["state_names"]
        else:
            names = p["names"]
        n = len(names)
        P("            {")
        P("                const items::MiscItemDef* d =")
        P("                    reg.find(\"%s\");" % key)
        P("                if (!d) { ++bad; } else {")
        P("                    if ((int)d->rows.size() != %d" % n)
        P("                        || (int)d->pins.size() != 1")
        P("                        || d->pins[0].name != \"%sRowCount\"" % key)
        P("                        || d->pins[0].value != %d" % n)
        P("                        || (int)d->tables.size() != %d)"
          % len(d["tags"]))
        P("                        ++bad;")
        for i, tg in enumerate(d["tags"]):
            width = (len(p["arrs"][tg])
                     if tg != MANIA_TAG
                     else len(p["mania"]))
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
            E.raw([
                "                    if (std::string(",
                "                        d->rows[%d].name)" % i,
                "                        != \"%s\")" % nm,
                "                        ++bad;"])
        P("                }")
        P("            }")
    P("        }")
    P("        printf(\"%s audit: bad %%d\\n\", bad);"
      % LABELS[1])
    P("        if (bad) return 1;")
    P("        bad = 0;")
    # -- 3. the intoxication def
    d = DEFS[0]
    P("        // -- 3. %s ----" % d["key"])
    P("        {")
    for tag, fn in STATE_TAGS:
        vals = p["arrs"][tag]
        wn = "wantTi%s" % camel(tag)
        want_arr(P, wn, vals, ind="            ")
        P("            for (int i = 0; i < 5; ++i)")
        P("                if (rules::%s(" % fn)
        P("                    (rules::IntoxState)i)")
        P("                    != %s[i])" % wn)
        P("                    ++bad;")
    for tag, strong, _ in STIM_TAGS:
        vals = p["arrs"][tag]
        wn = "wantTi%s" % camel(tag)
        want_arr(P, wn, vals, ind="            ")
        P("            for (int i = 0; i < 5; ++i)")
        P("                if (rules::%s(" % STIM_FN)
        P("                    (rules::IntoxState)i, %s)" % ("true" if strong else "false"))
        P("                    != %s[i])" % wn)
        P("                    ++bad;")
    P("        }")
    P("        printf(\"%s audit: bad %%d\\n\", bad);"
      % LABELS[2])
    P("        if (bad) return 1;")
    P("        bad = 0;")
    # -- 4. the insanity def
    d = DEFS[1]
    P("        // -- 4. %s ----" % d["key"])
    P("        {")
    # the 20 form names read through the
    # rows-reader accessor (the names
    # DERIVE from the parse)
    for t, nm in enumerate(p["names"], 1):
        name_probe(E, t, nm)
    # the mania strength grid: the want
    # holds the EXPECTED ACCESSOR OUTPUTS
    # for d6 1..6 (the dead index 0 is
    # unreachable through the clamp)
    want_arr(P, "wantTaManiaStrength",
             p["mania"][1:], ind="            ")
    P("            for (int i = 1; i <= 6; ++i)")
    P("                if (rules::%s(i)" % MANIA_FN)
    P("                    != wantTaManiaStrength"
      "[i - 1])")
    P("                    ++bad;")
    P("        }")
    P("        printf(\"%s audit: bad %%d\\n\", bad);"
      % LABELS[3])
    P("        if (bad) return 1;")
    P("        bad = 0;")
    # -- 5. seam: the raw registry
    # cross-read against the accessors
    # (dual-path diff)
    P("        // -- 5. seam ---------------------------------")
    P("        {")
    P("            items::MiscItemRegistry reg;")
    P("            reg.loadDirectory(")
    P("                \"content/tables/dm_insanity\");")
    for d in DEFS:
        key = d["key"]
        P("            {")
        P("                const items::MiscItemDef* d =")
        P("                    reg.find(\"%s\");" % key)
        P("                if (!d) ++bad;")
        for tag in d["tags"]:
            P("                {")
            P("                    int got = 0;")
            P("                    for (const auto& t : d->tables) {")
            P("                        if (t.name != \"%s\")" % tag)
            P("                            continue;")
            P("                        got = 1;")
            if tag in [t for t, _ in STATE_TAGS]:
                fn = dict(STATE_TAGS)[tag]
                width = 5
                P("                        for (int i = 0; i < %d;" % width)
                P("                             ++i)")
                P("                            if ((int)t.values[i] !=")
                P("                                rules::%s(" % fn)
                P("                                    (rules::IntoxState)i))")
                P("                                ++bad;")
            elif tag in [t for t, _, _ in STIM_TAGS]:
                strong = tag == "stimulant_strong_percent"
                P("                        for (int i = 0; i < 5;")
                P("                             ++i)")
                P("                            if ((int)t.values[i] !=")
                P("                                rules::%s(" % STIM_FN)
                P("                                    (rules::IntoxState)i,")
                P("                                %s))" % ("true" if strong else "false"))
                P("                                ++bad;")
            else:  # the mania grid: the dead
                # index 0 rides the table
                # faithfully; the accessor
                # reads cells 1..6
                P("                        if ((int)t.values.size() != 7)")
                P("                            ++bad;")
                P("                        if ((int)t.values.size() > 0")
                P("                            && (int)t.values[0] != %d)" % p["mania"][0])
                P("                            ++bad;")
                P("                        for (int i = 1; i <= 6; ++i)")
                P("                            if ((int)t.values[i] !=")
                P("                                rules::%s(i))" % MANIA_FN)
                P("                                ++bad;")
            P("                    }")
            P("                    if (!got) ++bad;")
            P("                }")
        if key == "dm_insanity":
            # the form rows cross-read
            # against the rows reader
            P("                for (int i = 0; i < %d;" % len(p["names"]))
            P("                     ++i)")
            P("                    if (d->rows[i].name !=")
            P("                        rules::%s(i + 1))" % NAME_FN)
            P("                        ++bad;")
        P("            }")
    P("        }")
    P("        printf(\"%s audit: bad %%d\\n\", bad);"
      % LABELS[4])
    P("        if (bad) return 1;")
    P("        bad = 0;")
    # -- 6. edges: the kept logic fns,
    # every probe DERIVED from the parse
    # (the last section carries NO guard)
    P("        // -- 6. edges --------------------------------")
    P("        {")
    # the clamp fn bounds (DERIVED from
    # the enum parse)
    sober = p["IntoxState"][0][0]
    comat = p["IntoxState"][4][0]
    for arg, mem in (("-1", sober), ("9", comat)):
        P("            if (rules::intoxicationClamp(")
        P("                (rules::IntoxState)%s)" % arg)
        P("                != rules::%s)" % mem)
        P("                ++bad;")
    # every state-keyed accessor at its
    # clamp bounds: -1 reads the sober
    # cell, 9 the comatose cell (DERIVED)
    for tag, fn in STATE_TAGS:
        v = p["arrs"][tag]
        for arg, val in (("-1", v[0]), ("9", v[4])):
            P("            if (rules::%s(" % fn)
            P("                (rules::IntoxState)%s)" % arg)
            P("                != %d)" % val)
            P("                ++bad;")
    for tag, strong, _ in STIM_TAGS:
        v = p["arrs"][tag]
        flag = "true" if strong else "false"
        for arg, val in (("-1", v[0]), ("9", v[4])):
            P("            if (rules::%s(" % STIM_FN)
            P("                (rules::IntoxState)%s," % arg)
            P("                %s) != %d)" % (flag, val))
            P("                ++bad;")
    # the mania d6 clamp (DERIVED)
    for d6, val in ((0, p["mania"][1]), (1, p["mania"][1]),
                    (6, p["mania"][6]), (7, p["mania"][6])):
        P("            if (rules::%s(%d) != %d) ++bad;"
          % (MANIA_FN, d6, val))
    # the name reader clamps (DERIVED:
    # below 1 reads the first form,
    # above 20 the last)
    name_probe(E, 0, p["names"][0])
    name_probe(E, p["name_hi"] + 1, p["names"][-1])
    # insanityIsMild polarity (DERIVED -
    # the R1051 class-3 lesson: model-TRUE
    # needs the bang so the probe fires
    # when the accessor disagrees)
    for t in (0, 1, 4, 5, 21):
        mild = m_mild(p, t)
        pol = "!" if mild else ""
        P("            if (%srules::insanityIsMild(%d))"
          % (pol, t))
        P("                ++bad;")
    # the derived magicSaveRaise ladder
    for i, v in enumerate(p["msvr"]):
        P("            if (rules::intoxicationMagicSaveRaise(")
        P("                (rules::IntoxState)%d) != %d)" % (i, v))
        P("                ++bad;")
    # the zero-arg scalar fns (ALL of
    # them, DERIVED from the parse)
    for fn, v in p["scalars"]:
        P("            if (rules::%s() != %d)" % (fn, int(v)))
        P("                ++bad;")
    P("        }")
    P("        printf(\"%s audit: bad %%d\\n\", bad);"
      % LABELS[5])
    P("    }")
    return "\n".join(E.lines)


# ---- the self-scan --------------------------
# Nothing is written until the emitted
# fragment, seam and lua pass every
# structural and parity check.

def self_scan(frag, seam, luas, p):
    # fragment shape
    if frag.count("printf(") != 6:
        die("self-scan: printf count")
    if frag.count("audit: bad %d") != 6:
        die("self-scan: census pattern count")
    if frag.count("if (bad) return 1;") != 5:
        die("self-scan: guard count")
    if frag.count("\n        bad = 0;") != 5:
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
    # terminator strip
    for line in frag.splitlines():
        s = line.rstrip()
        if s.endswith("})") and not s.endswith("});"):
            die("self-scan: }) strip")
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
    # fn and enum token
    toks = set([fn for _, fn in STATE_TAGS])
    toks.add(STIM_FN)
    toks.add(MANIA_FN)
    toks.add(NAME_FN)
    toks.add("insanityIsMild")
    toks.add("intoxicationClamp")
    toks.add("intoxicationMagicSaveRaise")
    toks.update(fn for fn, _ in p["scalars"])
    toks.add("IntoxState")
    toks.update(nm for nm, _ in p["IntoxState"])
    fcode = re.sub(r"//[^\n]*", "", frag)
    for tk in toks:
        for m in re.finditer(
                r"(?<![\w:])" + tk + r"(?![\w:])",
                fcode):
            if not fcode[:m.start()].endswith("rules::"):
                die("self-scan: " + tk + " unqualified")
            break
    for tk in ("MiscItemRegistry", "MiscItemDef"):
        for m in re.finditer(
                r"(?<![\w:])" + tk + r"(?![\w:])",
                fcode):
            if not fcode[:m.start()].endswith("items::"):
                die("self-scan: " + tk + " not items::")
    # find targets AS SETS
    if sorted(set(re.findall(
            r'reg\.find\("(\w+)"\)', frag))) \
            != sorted([d["key"] for d in DEFS]):
        die("self-scan: find targets")
    # want arrays: values parity vs the
    # parse (NEGATIVE cells included)
    all_tags = [t for t, _ in STATE_TAGS] + \
        [t for t, _, _ in STIM_TAGS]
    for tag in all_tags:
        wn = "wantTi%s" % camel(tag)
        m = re.search(
            r"const int " + wn +
            r"\[\] = \{([-\d\s,]+)\};", frag)
        if not m:
            die("self-scan: want " + wn + " missing")
        got = [int(v) for v in
               re.findall(r"-?\d+", m.group(1))]
        if got != p["arrs"][tag]:
            die("self-scan: want " + wn + " parity")
    m = re.search(
        r"const int wantTaManiaStrength"
        r"\[\] = \{([-\d\s,]+)\};", frag)
    if not m:
        die("self-scan: want wantTaManiaStrength missing")
    got = [int(v) for v in
           re.findall(r"-?\d+", m.group(1))]
    if got != p["mania"][1:]:
        die("self-scan: want wantTaManiaStrength parity")
    # name probes: every parsed form
    # name appears in exactly one
    # in-range literal probe (the
    # rows-reader output parity); the
    # clamp probes at 0 and 21 are
    # counted separately below
    probes = re.findall(
        r'insanityName\((\d+)\)\)'
        r'\s*!= "([^"]*)"\)', frag)
    for i, nm in enumerate(p["names"], 1):
        c = sum(1 for a, n in probes
                if int(a) == i and n == nm)
        if c != 1:
            die("self-scan: name probe " + nm)
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
    # IsMild polarity (model-TRUE carries
    # the bang; model-FALSE must NOT -
    # the R1051 class-3 lesson)
    for t in (0, 1, 4, 5, 21):
        if m_mild(p, t):
            probe_rx(r"!rules::insanityIsMild\(%d\)\)" % t)
        else:
            probe_rx(r"(?<!\!)rules::insanity"
                     r"IsMild\(%d\)\)" % t)
    # the clamp fn bounds
    sober = p["IntoxState"][0][0]
    comat = p["IntoxState"][4][0]
    for arg, mem in (("-1", sober), ("9", comat)):
        probe_rx(r"rules::intoxicationClamp\(\s*"
                  r"\(rules::IntoxState\)%s\)\s*"
                  r"!=\s*rules::%s\)" % (arg, mem))
    # the state accessor clamp bounds
    for tag, fn in STATE_TAGS:
        v = p["arrs"][tag]
        for arg, val in (("-1", v[0]), ("9", v[4])):
            probe_rx(r"rules::%s\(\s*\(rules::IntoxState\)"
                     r"%s\)\s*!=\s*%d\)"
                     % (fn, arg, val))
    # the stimulant clamp bounds (both
    # polarities)
    for tag, strong, _ in STIM_TAGS:
        v = p["arrs"][tag]
        flag = "true" if strong else "false"
        for arg, val in (("-1", v[0]), ("9", v[4])):
            probe_rx(r"rules::%s\(\s*\(rules::IntoxState\)"
                     r"%s,\s*%s\)\s*!=\s*%d\)"
                     % (STIM_FN, arg, flag, val))
    # the mania clamp probes
    for d6, val in ((0, p["mania"][1]), (1, p["mania"][1]),
                    (6, p["mania"][6]), (7, p["mania"][6])):
        probe_rx(r"rules::%s\(%d\)\s*!=\s*%d\)"
                 % (MANIA_FN, d6, val))
    # the name clamp probes
    probe_rx(r'std::string\(\s*rules::insanityName\(0\)\)'
             r'\s*!=\s*"%s"\)' % p["names"][0])
    probe_rx(r'std::string\(\s*rules::insanityName\(%d\)\)'
             r'\s*!=\s*"%s"\)'
             % (p["name_hi"] + 1, p["names"][-1]))
    # the magicSaveRaise ladder
    for i, v in enumerate(p["msvr"]):
        probe_rx(r"rules::intoxicationMagicSaveRaise\(\s*"
                 r"\(rules::IntoxState\)%d\)\s*!=\s*%d\)"
                 % (i, v))
    # seam checks
    if seam.count(APPLIED_MARK) != 1:
        die("self-scan: mark count")
    if ('#include "items/MiscItemRegistry.h"'
            not in seam):
        die("self-scan: registry include")
    if re.search(r"static const ", seam):
        die("self-scan: a static array survived")
    for tok in ("izReg()", "izTable(", "izRows("):
        if tok not in seam:
            die("self-scan: seam fn missing " + tok)
    # the tag-level ternary (the R1052
    # adjacent-literal class: each arm
    # must close its own string; the
    # strong arm closes with a quote,
    # the mild arm with quote+paren)
    for ln in ('? "stimulant_strong_percent"',
               ': "stimulant_mild_percent");'):
        if ln not in seam:
            die("self-scan: ternary tag " + ln)
    # the single-owner call sites pin
    # their def key and tag
    for tag, _ in STATE_TAGS:
        if ('"dm_intoxication", "%s");' % tag) \
                not in seam:
            die("self-scan: single-owner site " + tag)
    if ('"dm_insanity", "mania_strength_state");') \
            not in seam:
        die("self-scan: mania site")
    if 'izRows("dm_insanity");' not in seam:
        die("self-scan: rows site")
    # the clamps survived the rewrite
    if seam.count("intoxicationClamp(s)];") != 12:
        die("self-scan: clamp call count %d"
            % seam.count("intoxicationClamp(s)];"))
    if "if (d6 < 1) d6 = 1;" not in seam \
            or "if (d6 > 6) d6 = 6;" not in seam:
        die("self-scan: mania clamp lost")
    if ("if (type < 1) type = 1;" not in seam
            or "if (type > %d) type = %d;"
            % (p["name_hi"], p["name_hi"])
            not in seam):
        die("self-scan: name clamp lost")
    # lua checks
    for d in DEFS:
        x = luas[d["key"]]
        key = d["key"]
        if key == "dm_intoxication":
            names = p["state_names"]
        else:
            names = p["names"]
        n = len(names)
        if ('key = "%s"' % key) not in x:
            die("self-scan: lua key " + key)
        if "round = 1053" not in x:
            die("self-scan: lua round " + key)
        if x.count("band = { ") != n:
            die("self-scan: lua row count " + key)
        if ('name = "%sRowCount"' % key) not in x:
            die("self-scan: lua pin " + key)
        for nm in names:
            if ('name = "%s",' % nm) not in x:
                die("self-scan: lua row " + nm)
        for tag in d["tags"]:
            if ('name = "%s",' % tag) not in x:
                die("self-scan: lua table " + tag)
            m = re.search(
                r'name = "' + tag +
                r'",\s*values = \{([-\d\s,]+)\}', x)
            if not m:
                die("self-scan: lua values " + tag)
            got = [int(v) for v in
                   re.findall(r"-?\d+", m.group(1))]
            want = (p["arrs"][tag] if tag != MANIA_TAG
                    else p["mania"])
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
        die("R1052 include anchor not found in regtest.cpp")
    before = rt.splitlines()
    at = before.index(
        [l for l in before if INC_ANCHOR in l][0])
    if at != 1300:
        die("R1052 include at line %d, want 1301"
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
          "wrote 3 new files")
    print("SPLICE OK")


if __name__ == "__main__":
    main()
